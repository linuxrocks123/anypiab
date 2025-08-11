// Functions to mimic AfxFormatString using Standard C++ Library strings.

// $Id: FormatString.cpp 1.5.1.1 2012/03/08 06:55:13EST 277133 Development 277133(2012/03/08 06:55:49EST) $

//Nice job keeping your platform-independent code platform-independent, asshats.

#include "FormatString.h"
#include "Resource.h"
#include "StringFunctions.h"

#include <string>
#include <unordered_map>

using namespace std;

static unordered_map<int,string> res;
static void init_res()
{
     res[PIA_IDS_MONTHTEXT]="Month in %1 that this case is being or was processed";
     res[PIA_IDS_PEBESMONTH]="Must choose month of PEBES processing";
     res[PIA_IDS_AGEPLAN]="Planned age of retirement must be from 0 to 99";
     res[PIA_IDS_BEGIN1]="First year of earnings must not be less than year of birth";
     res[PIA_IDS_BEGIN2]="Inconsistent period of backward projection";
     res[PIA_IDS_BIRTH3]="Worker's month of birth must be from 1 to 12";
     res[PIA_IDS_BIRTH4]="Worker's day of birth must be from 1 to 31";
     res[PIA_IDS_JOASDI]="Must choose type of benefit";
     res[PIA_IDS_BIRTH2]="Year of birth must be at least 1800 (use 4 digits)";
     res[PIA_IDS_BIRTH1]="Year of birth in PEBES case must be before current year";
     res[PIA_IDS_BIRTH5]="Year of birth is too large";
     res[PIA_IDS_SEX]="Must choose sex of worker";
     res[PIA_IDS_BIPROJTTL]="Benefit Increases Set %1";
     res[PIA_IDS_READERR]="Stored case is in error";
     res[PIA_IDS_CPIINC3]="Benefit increase assumption file is in error";
     res[PIA_IDS_2YEARS]="Year%1Year%2";
     res[PIA_IDS_CPIINC2]="Cannot store the benefit increase file";
     res[PIA_IDS_YEAR]="Year%1";
     res[PIA_IDS_CPIINC1]="Benefit increase must be less than 100% and nonnegative";
     res[PIA_IDS_IALTBI2]="Must choose PEBES benefit increase assumption";
     res[PIA_IDS_IALTAW2]="Must choose PEBES average wage increase assumption";
     res[PIA_IDS_CACHUP1]="Catch-up increase must be less than 100% and nonnegative";
     res[PIA_IDS_ANDLATER]="%1 and later";
     res[PIA_IDS_HISTAMTTL]="Historical Amounts for %1";
     res[PIA_IDS_AVGWGTTL]="Average Wage Increases Set %1";
     res[PIA_IDS_EARNTYPE]="Must choose type of earnings";
     res[PIA_IDS_EARNPEBS]="Annual earnings must be between $0 and $999,999.99";
     res[PIA_IDS_ANSCCH]="Must choose catch-up benefit increase response";
     res[PIA_IDS_ENT1]="Month of entitlement must be from 1 to 12";
     res[PIA_IDS_ENT2]="Year of entitlement is too early";
     res[PIA_IDS_BEGIN3]="First year of earnings is too early";
     res[PIA_IDS_END1]="First year of earnings must not be after last year";
     res[PIA_IDS_VALDI1]="Number of periods of disability must be 0, 1, or 2";
     res[PIA_IDS_VALDI2]="Number of periods of disability must be 1 or 2";
     res[PIA_IDS_PROJBACK1]="Backward earnings projection indicator must be 0, 1, or 2";
     res[PIA_IDS_END4]="Last year of earnings is too late";
     res[PIA_IDS_PROJFWRD1]="Forward earnings projection indicator must be 0, 1, or 2";
     res[PIA_IDS_END3]="Inconsistent period of forward projection";
     res[PIA_IDS_ENT3]="Year of entitlement is too late";
     res[PIA_IDS_PROJBACK2]="Must choose type of backward earnings projection";
     res[PIA_IDS_PERCBACK]="Backward projection percentage must be between 0.0 and 9.9";
     res[PIA_IDS_PROJFWRD2]="Must choose type of forward earnings projection";
     res[PIA_IDS_PERCFWRD]="Forward projection percentage must be between 0.0 and 9.9";
     res[PIA_IDS_BENDATE1]="Benefit date must be at or after entitlement";
     res[PIA_IDS_BENDATE2]="Month of benefit must be from 1 to 12";
     res[PIA_IDS_BENDATE3]="Year of benefit is too early";
     res[PIA_IDS_BENDATE4]="Year of benefit is too late";
     res[PIA_IDS_BEGIN4]="First year of earnings must be before current year";
     res[PIA_IDS_BEGIN5]="First year of earnings is too late";
     res[PIA_IDS_END2]="Last year of earnings is too late";
     res[PIA_IDS_ONSET1]="Month of disability onset must be from 1 to 12";
     res[PIA_IDS_ONSET2]="Day of disability onset must be from 1 to 31";
     res[PIA_IDS_ONSET4]="Disability onset is too late";
     res[PIA_IDS_ONSET3]="Disability onset must be at least 1937";
     res[PIA_IDS_START1]="First year of projection must be at least 1979";
     res[PIA_IDS_START2]="First year of projection is too late";
     res[PIA_IDS_DICESS1]="Month of disability cessation must be from 1 to 12";
     res[PIA_IDS_DICESS2]="Disability cessation must be at least 1937";
     res[PIA_IDS_DICESS3]="Disability cessation is too late";
     res[PIA_IDS_DEATH1]="Month of death must be from 1 to 12";
     res[PIA_IDS_CUPROJTTL]="Catch-up Increases Set %1";
     res[PIA_IDS_PRRENT1]="Month of prior entitlement to disability must be from 1 to 12";
     res[PIA_IDS_PRRENT2]="Year of prior entitlement to disability must be at least 1940";
     res[PIA_IDS_PRRENT3]="Year of prior entitlement to disability is too late";
     res[PIA_IDS_DEATH4]="Death must precede entitlement";
     res[PIA_IDS_DEATH5]="Birth must precede death";
     res[PIA_IDS_DEATH3]="Year of death must be at least 1937";
     res[PIA_IDS_ONSET6]="Disability onset must precede entitlement";
     res[PIA_IDS_ONSET5]="Disability onset must be after birth";
     res[PIA_IDS_ONSET7]="Disability onset must precede death";
     res[PIA_IDS_DICESS4]="Disability onset must precede cessation";
     res[PIA_IDS_DICESS6]="Disability cessation must precede current entitlement";
     res[PIA_IDS_DICESS7]="Disability cessation must precede death";
     res[PIA_IDS_ONSET8]="Disability onsets out of order";
     res[PIA_IDS_DICESS5]="Prior cessation must precede current onset";
     res[PIA_IDS_JSURV]="Must set type of survivor";
     res[PIA_IDS_JBIRTH1]="Widow(er)'s month of birth must be from 1 to 12";
     res[PIA_IDS_JBIRTH2]="Widow(er)'s day of birth must be from 1 to 31";
     res[PIA_IDS_JONSET1]="Disabled widow(er)'s month of disability must be from 1 to 12";
     res[PIA_IDS_JONSET2]="Disabled widow(er)'s day of disability onset must be from 1 to 31";
     res[PIA_IDS_JONSET3]="Disabled widow(er)'s year of disability onset must be at least 1940";
     res[PIA_IDS_JONSET4]="Disabled widow(er)'s year of disability onset is too late";
     res[PIA_IDS_WAITPD1]="Month of disability waiting period must be from 1 to 12";
     res[PIA_IDS_WAITPD2]="Year of disability waiting period must be at least 1940";
     res[PIA_IDS_WAITPD3]="Year of disability waiting period is too late";
     res[PIA_IDS_JONSET6]="Widow(er)'s disability onset must precede entitlement";
     res[PIA_IDS_JBIRTH3]="Widow(er)'s year of birth must be at least 1800";
     res[PIA_IDS_JBIRTH4]="Widow(er)'s year of birth is too late";
     res[PIA_IDS_JONSET5]="Widow(er)'s birth must precede disability onset";
     res[PIA_IDS_WAITPD4]="Waiting period must be after disability onset";
     res[PIA_IDS_WAITPD5]="Waiting period must precede entitlement";
     res[PIA_IDS_PRRENT5]="Prior disability entitlement must be after disability onset";
     res[PIA_IDS_PRRENT4]="Prior disability entitlement must be before second entitlement";
     res[PIA_IDS_WAITPD6]="Waiting period must precede cessation";
     res[PIA_IDS_PEBSASM]="Must be flat or 1% assumption for PEBES";
     res[PIA_IDS_PUBPEN]="Noncovered pension must be between $0 and $999,999.99";
     res[PIA_IDS_QCTD]="QCs from 1937 to 1977 must be from 0 to 164";
     res[PIA_IDS_QC51TD]="QCs from 1951 to 1977 must be from 0 to 108";
     res[PIA_IDS_QCANN]="Annual quarters of coverage must be from 0 to 4";
     res[PIA_IDS_QC]="QCs from 1951 to 1977 cannot be more than QCs from 1937 to 1977";
     res[PIA_IDS_ARDRI1]="Inconsistent data (impossible age)";
     res[PIA_IDS_ARDRI2]="Retirement before earliest possible retirement age";
     res[PIA_IDS_ARDRI3]="No disabled widow(er) benefit until February 1968";
     res[PIA_IDS_ARDRI4]="Earliest possible age is 50 for disabled widow(er)";
     res[PIA_IDS_ARDRI5]="Cannot handle disabled widow(er) over age 60";
     res[PIA_IDS_ARDRI6]="Aged widow(er) before earliest possible age";
     res[PIA_IDS_ARDRI7]="No disability benefits until 1957";
     res[PIA_IDS_ARDRI8]="Disability beneficiary before earliest possible age";
     res[PIA_IDS_ARDRI9]="Disability beneficiary after latest possible age";
     res[PIA_IDS_FQINC4]="Cannot open the average wage increase assumption file";
     res[PIA_IDS_AWBI1]="Cannot open the historical amounts file";
     res[PIA_IDS_AWBI3]="Historical amounts file is in error";
     res[PIA_IDS_FQINC3]="Average wage increase assumption file is in error";
     res[PIA_IDS_AWBI2]="Cannot save the historical amounts file";
     res[PIA_IDS_FQINC2]="Cannot store the average wage increase file";
     res[PIA_IDS_BASEYR4]="Cannot open the base year file";
     res[PIA_IDS_BASEYR3]="Base year file is in error";
     res[PIA_IDS_BASEYR2]="Cannot save the base year file";
     res[PIA_IDS_FQINC1]="Average wage increase must be between -10% and 100%";
     res[PIA_IDS_BASEYR1]="Must be from 1979 to 2020, and historical data must exist";
     res[PIA_IDS_IALTBI1]="Must choose benefit increase assumption";
     res[PIA_IDS_IALTAW1]="Must choose average wage increase assumption";
     res[PIA_IDS_BASECH]="Must choose wage base assumption";
     res[PIA_IDS_CPIINC4]="Cannot open the benefit increase assumption file";
     res[PIA_IDS_EARNHI]="Annual Medicare earnings must be between $0 and $999,999.99";
     res[PIA_IDS_BASE2]="Maximum wage base must be between $0 and $999,999.99";
     res[PIA_IDS_TAXTYPE]="Must choose type of taxes";
     res[PIA_IDS_CACHUP2]="Cannot open the catch-up benefit increase file";
     res[PIA_IDS_CACHUP3]="Cannot store the catch-up benefit increase file";
     res[PIA_IDS_LAWCHG1]="Year of change in law must be current year or later";
     res[PIA_IDS_LAWCHG2]="Law change proportion must be between 0.00 and 1.00";
     res[PIA_IDS_LAWCHG3]="Alternative percentage must be between 0.00% and 99.99%";
     res[PIA_IDS_LAWCHG4]="Alternative bend point must be between $0 and $99,999";
     res[PIA_IDS_LAWCHG5]="Percentage decline must be between 0.00% and 9.99%";
     res[PIA_IDS_ONSET9]="Invalid disability onset date";
     res[PIA_IDS_ONSET10]="Invalid prior disability onset date";
     res[PIA_IDS_JBIRTH5]="Invalid widow(er) date of birth";
     res[PIA_IDS_JONSET7]="Invalid widow(er)'s disability onset date";
     res[PIA_IDS_BIRTH6]="Invalid date of birth";
     res[PIA_IDS_PRRENT6]="Invalid prior disability entitlement date";
     res[PIA_IDS_DICESS8]="Invalid disability cessation date";
     res[PIA_IDS_DEATH6]="Invalid date of death";
     res[PIA_IDS_WAITPD7]="Invalid first month of waiting period";
     res[PIA_IDS_TITLEPRO1]="Cannot open the assumption titles file";
     res[PIA_IDS_TITLEPRO2]="Cannot read a title from assumption titles file";
     res[PIA_IDS_TITLEPRO3]="Cannot store the assumption titles file";
     res[PIA_IDS_ENT4]="Invalid date of initial entitlement";
     res[PIA_IDS_FOINFO1]="Cannot open the field office file";
     res[PIA_IDS_FOINFO2]="Field office file is in error";
     res[PIA_IDS_FOINFO3]="Cannot save the field office file";
     res[PIA_IDS_LAWCHG7]="Cannot open the law change file";
     res[PIA_IDS_LAWCHG6]="Law change file is in error";
     res[PIA_IDS_LAWCHG8]="Cannot save the law change file";
     res[PIA_IDS_BENDATE5]="Invalid date of benefit";
     res[PIA_IDS_ONSET11]="Disability onset must precede full retirement age";
     res[PIA_IDS_PRRENT7]="Prior disability entitlement must precede full retirement age";
     res[PIA_IDS_PIBTABLE1]="Cannot open old-start table file";
     res[PIA_IDS_PIBTABLE2]="Old-start table file is in error";
     res[PIA_IDS_MAXIMUMTEXT]="Maximum: $%1";
     res[PIA_IDS_AVERAGETEXT]="Average: $%1";
     res[PIA_IDS_LOWTEXT]="Low: $%1";
     res[PIA_IDS_OUTFILE]="Unable to store file %1";
     res[PIA_IDS_READEOF]="Unexpected end of file reading stored case";
     res[PIA_IDS_READMORE]="More data available for this case";
     res[PIA_IDS_SEXOUT]="Sex: %1";
     res[PIA_IDS_DOBOUT]="Date of birth: %1";
     res[PIA_IDS_OABENTOUT]="Retired in %1 at age %2";
     res[PIA_IDS_OABBENOUT]="Benefit as of %1 at age %2";
     res[PIA_IDS_NRAOUT]="Full retirement age: %1";
     res[PIA_IDS_NRA1OUT]="Early retirement age: %1";
     res[PIA_IDS_DEATHOUT]="Died on %1";
     res[PIA_IDS_SURVENTOUT]="Benefits started in %1";
     res[PIA_IDS_SURVBENOUT]="Benefit as of %1";
     res[PIA_IDS_JSURVOUT]="Type of beneficiary: %1";
     res[PIA_IDS_NRAWIDOUT]="Widow(er)'s full retirement age: %1";
     res[PIA_IDS_ONSETOUT]="Disabled on %1";
     res[PIA_IDS_PRIOROUT]="Prior disability onset on %1";
     res[PIA_IDS_PRCESSOUT]="Prior disability cessation in %1";
     res[PIA_IDS_DIBENTOUT]="Benefits started in %1 at age %2";
     res[PIA_IDS_PIAOUT]="   PIA = %1";
     res[PIA_IDS_MFBOUT]="   MFB = %1";
     res[PIA_IDS_BIOUT]="Benefit increase assumptions:";
     res[PIA_IDS_AWOUT]="Average wage increase assumptions:";
     res[PIA_IDS_NAMEOUT]="Name: %1";
     res[PIA_IDS_SSNOUT]="Social Security number: %1";
     res[PIA_IDS_NONPENOUT]="Noncovered monthly pension: %1";
     res[PIA_IDS_RELERNOUT]="Relative earnings position: %1";
     res[PIA_IDS_PROBASOUT]="Projected wage bases: %1";
     res[PIA_IDS_REQQCOUT]="   Required quarters of coverage: %1";
     res[PIA_IDS_ACTQCOUT]="   Actual quarters of coverage: %1";
     res[PIA_IDS_INSTATOUT]="   Insured status: %1";
     res[PIA_IDS_DINS1OUT]="   Period after disability: %1 to %2";
     res[PIA_IDS_DINS2OUT]="   Period before disability: %1 to %2";
     res[PIA_IDS_DINS3OUT]="   Period before prior disability: %1 to %2";
     res[PIA_IDS_ELAPSOUT]="   Elapsed quarters of coverage: %1";
     res[PIA_IDS_PRENTOUT]="Previous disability entitlement in %1";
     res[PIA_IDS_ONSET2OUT]="Second prior disability onset on %1";
     res[PIA_IDS_CESS2OUT]="Second prior disability cessation in %1";
     res[PIA_IDS_SPYRS2OUT]="   Years of coverage: %1";
     res[PIA_IDS_PONSETOUT]="Previous disability onset on %1";
     res[PIA_IDS_DOBWIDOUT]="Widow(er) born on %1";
     res[PIA_IDS_WIDDIBOUT]="Widow(er) disabled on %1";
     res[PIA_IDS_AMEOUT]="Average Monthly Earnings   = %1";
     res[PIA_IDS_AIMEOUT]="Indexed Monthly Earnings   = %1";
     res[PIA_IDS_SPYRSOUT]="Spec Min years of coverage = %1";
     res[PIA_IDS_PIALOUT]="Primary Insurance Amount   = %1";
     res[PIA_IDS_DRCMOUT]="Number of months increment = %1";
     res[PIA_IDS_DRCFOUT]="Delayed increment factor   = %1";
     res[PIA_IDS_ARFMOUT]="Number of months reduction = %1";
     res[PIA_IDS_BENFOUT]="Benefit factor             = %1";
     res[PIA_IDS_ARFFOUT]="Actuarial reduction factor = %1";
     res[PIA_IDS_BEN1OUT]="Benefit before rounding    = %1";
     res[PIA_IDS_MFBLOUT]="Maximum Family Benefit     = %1";
     res[PIA_IDS_SUPPIAOUT]="Support PIA                = %1";
     res[PIA_IDS_BEN2OUT]="Benefit after rounding     = %1";
     res[PIA_IDS_NTOTALOUT]="Not insured for totalization benefits";
     res[PIA_IDS_INSUREOUT]="Insured for regular benefits";
     res[PIA_IDS_NINSUROUT]="Not fully insured based on input data";
     res[PIA_IDS_UNEARNOUT]="Earnings after last possible year not used";
     res[PIA_IDS_ERNLIMOUT]="Earnings limited to $999,999.99";
     res[PIA_IDS_NINSTOUT]="Not fully or totalization insured";
     res[PIA_IDS_SPPIA1OUT]="   (based on Special Minimum PIA)";
     res[PIA_IDS_SPPIA2OUT]="   (based on support PIA)";
     res[PIA_IDS_NDISINOUT]="Warning! Worker is not disability-insured.";
     res[PIA_IDS_OPENERR]="Cannot open %1 for input";
     res[PIA_IDS_HIGHTEXT]="High: $%1";
     res[PIA_IDS_BIASSUM]="Must choose benefit increase assumption";
     res[PIA_IDS_AWASSUM]="Must choose average wage increase assumption";
     res[PIA_IDS_HISTAMTUPDATE]="Amounts for %1 computations:";
     res[PIA_IDS_UPDATEBI]="Benefit increase for December %1 (percent)";
     res[PIA_IDS_UPDATEAW]="Average wage for %1";
     res[PIA_IDS_UPDATEWB]="Wage base for %1";
     res[PIA_IDS_UPDATEWBOLD]="Old-law wage base for %1";
     res[PIA_IDS_QCTOT0]="Must have some quarters of coverage";
     res[PIA_IDS_REVIEWBI]="Benefit increase for June %1 (percent)";
     res[PIA_IDS_WAGEBASE]="Wage bases for %1";
     res[PIA_IDS_PIACALRANGE]="Out of range error in PiaCal::calculate";
     res[PIA_IDS_PIACALPLRGE]="Out of range error in PiaCalPL::piacal";
     res[PIA_IDS_OSRANGE1]="Out of range error in OldStart::calculate";
     res[PIA_IDS_OSRANGE2]="Out of range error in OldStart::c_os50";
     res[PIA_IDS_RTGENRL]="Denominator out of range in Rtgeneral::project1";
     res[PIA_IDS_QTRYRQTR]="Quarter out of range in QtrYear";
     res[PIA_IDS_QTRYRYR]="Year out of range in QtrYear";
     res[PIA_IDS_GENFILE1]="Error opening file in Genfile::openout";
     res[PIA_IDS_GENFILE2]="Error opening file in Genfile::openapp";
     res[PIA_IDS_GENFILE3]="Error opening file in Genfile::openin";
     res[PIA_IDS_QCARRAY1]="Year out of bounds in QcArray::QcArray";
     res[PIA_IDS_QCARRAY2]="Year out of bounds in QcArray::SetAt";
     res[PIA_IDS_QCARRAY3]="Year out of bounds in QcArray::sum using years";
     res[PIA_IDS_QCARRAY4]="Year out of bounds in QcArray::sum using QtrYears";
     res[PIA_IDS_FLOATANN1]="Year out of bounds in FloatAnnual";
     res[PIA_IDS_FLOATANN2]="Error in FloatAnnual::read";
     res[PIA_IDS_DBLEANN1]="Year out of bounds in DoubleAnnual";
     res[PIA_IDS_DBLEANN2]="Error in DoubleAnnual::read";
     res[PIA_IDS_INTANN1]="Year out of bounds in IntAnnual";
     res[PIA_IDS_INTANN2]="Error in IntAnnual::read";
     res[PIA_IDS_FLOATMTH1]="Year out of bounds in FloatMonth";
     res[PIA_IDS_FLOATMTH2]="Error in FloatMonth::read";
     res[PIA_IDS_FLOATQTR1]="Year out of bounds in FloatQuarter";
     res[PIA_IDS_FLOATQTR2]="Error in FloatQuarter::read";
     res[PIA_IDS_PIB50MFB]="Index out of bounds in Pib50Mfb";
     res[PIA_IDS_PIB50PIB]="Index out of bounds in Pib50Pib";
     res[PIA_IDS_PIB52MFB]="Index out of bounds in Pib52Mfb";
     res[PIA_IDS_PIB54MFB]="Index out of bounds in Pib54Mfb";
     res[PIA_IDS_PIB54PIA]="Index out of bounds in Pib54Pia";
     res[PIA_IDS_PIB58AME]="Index out of bounds in Pib58Ame";
     res[PIA_IDS_PIB58PIB]="Index out of bounds in Pib58Pib";
     res[PIA_IDS_BASE1]="Index out of bounds in Wage Base";
     res[PIA_IDS_BICCHP]="Error in bicchp";
     res[PIA_IDS_ROUND]="Error in round";
     res[PIA_IDS_SETNOCH]="Error in setnoch";
     res[PIA_IDS_UPDATEFQ]="Error in updatefq";
     res[PIA_IDS_UNBICCHP]="Error in unbicchp";
     res[PIA_IDS_EARNTYPEYR]="Year out of bounds in earntype";
     res[PIA_IDS_TAXTYPEYR]="Year out of bounds in taxtype";
     res[PIA_IDS_NEEDAW]="Error in need_aw";
     res[PIA_IDS_EARNMAL]="Error in earnmal";
     res[PIA_IDS_NEEDBASES]="Error in needbases";
     res[PIA_IDS_NEEDBI]="Error in need_bi";
     res[PIA_IDS_ATOFLOAT]="Error in atofloat";
     res[PIA_IDS_ATOINT]="Error in atoint";
     res[PIA_IDS_ATOLONG]="Error in atolong";
     res[PIA_IDS_ATODOUBLE]="Error in atodouble";
     res[PIA_IDS_FLOATQTR3]="Error in floatqtr - 3";
     res[PIA_IDS_FLOATQTR4]="Error in floatqtr - 4";
     res[PIA_IDS_TITLEPRO4]="Error in titlepro - 4";
     res[PIA_IDS_RELERNPOS]="Error in relernpos";
     res[PIA_IDS_LAWCHG9]="Error in lawchange - 9";
     res[PIA_IDS_CACHUP4]="Error in cachup - 4";
     res[PIA_IDS_MODTC]="Error in modtc";
     res[PIA_IDS_AVGWG]="Error in avgwg";
     res[PIA_IDS_DATEMONTH]="Error in Date - month";
     res[PIA_IDS_DATEYEAR]="Error in Date - year";
     res[PIA_IDS_DATEDAY]="Error in Date - day";
     res[PIA_IDS_DATEREAD]="Error in Date::read";
     res[PIA_IDS_DATEDIFF]="Error in Date::diff";
     res[PIA_IDS_BENARRAY1]="Error in BenefitAmountArray - 1";
     res[PIA_IDS_BENARRAY2]="Error in BenefitAmountArray - 2";
     res[PIA_IDS_ONEPAGE]="Error in OnePage::prepareStrings";
     res[PIA_IDS_TWOPAGE1]="Error in InsuredPage::prepareStrings";
     res[PIA_IDS_TWOPAGE2]="Error in EarningsPage::prepareStrings";
     res[PIA_IDS_TWOPAGE3]="Error in Summary1Page::prepareStrings";
     res[PIA_IDS_TWOPAGE4]="Error in Summary2Page::prepareStrings";
     res[PIA_IDS_TWOPAGE5]="Error in Summary3Page::prepareStrings";
     res[PIA_IDS_OSSTRING]="Error in OldStart1Page::prepareStrings";
     res[PIA_IDS_PTSTRING]="Error in PiaTable1Page::prepareStrings";
     res[PIA_IDS_WISTRING]="Error in WageInd1Page::prepareStrings";
     res[PIA_IDS_TGSTRING]="Error in TransGuar1Page::prepareStrings";
     res[PIA_IDS_SMSTRING]="Error in SpecMin1Page::prepareStrings";
     res[PIA_IDS_RWSTRING]="Error in ReindWid1Page::prepareStrings";
     res[PIA_IDS_FMSTRING]="Error in FrozMinPage::prepareStrings";
     res[PIA_IDS_TXSTRING]="Error in TaxesPage::prepareStrings";
     res[PIA_IDS_DEATH2]="Year of death is too late";
     res[PIA_IDS_CONFIG1]="Unable to open configuration file for input";
     res[PIA_IDS_CONFIG5]="Unable to open configuration file for output";
     res[PIA_IDS_CONFIG6]="Error reading configuration file";
     res[PIA_IDS_MILSERV1]="Starting and ending dates are out of order";
     res[PIA_IDS_MILSERV2]="Number of military service periods must be between 0 and 15";
     res[PIA_IDS_MILSERV3]="Number of military service periods must be between 1 and 15";
     res[PIA_IDS_MILSERV4]="Invalid starting date (use mo/year format)";
     res[PIA_IDS_MILSERV5]="Invalid ending date (use mo/year format)";
     res[PIA_IDS_FULLBEN]="Full benefit               = %1";
     res[PIA_IDS_FAMSIZE]="Number of family members must be between 0 and 15";
     res[PIA_IDS_MFBBEN]="Benefit after MFB          = %1";
     res[PIA_IDS_ARDRI10]="Aged spouse before earliest possible age";
     res[PIA_IDS_NRAWIFEOUT]="Spouse's full retirement age: %1";
     res[PIA_IDS_AWBIDAT1]="Incorrect last year of data in AwbiDataNonFile";
     res[PIA_IDS_SECONDARY]="Incorrect data for secondary benefit";
     res[PIA_IDS_SSN1]="Full SSN must have 9 digits";
     res[PIA_IDS_QCDISCAL]="Incorrect date in qcDisCal";
     res[PIA_IDS_CURINSOUT]="Currently insured only";
     res[PIA_IDS_BENDATE6]="Benefit date must be at or after family member's date of entitlement";
     res[PIA_IDS_AGEMONTH]="Months out of range in Age class";
     res[PIA_IDS_FLOATMTH3]="Quarter out of range in FloatMonth::qaverage";
     res[PIA_IDS_METHOD]="number out of range in PiaMethod::order";
     res[PIA_IDS_OLDSTART1]="Entitlement date not set in OldStart::calculate";
     res[PIA_IDS_OLDSTART2]="Benefit date not set in OldStart::calculate";
     res[PIA_IDS_PIATABLE1]="Entitlement date not set in PiaTable::calculate";
     res[PIA_IDS_PIATABLE2]="Benefit date not set in PiaTable::calculate";
     res[PIA_IDS_MILSERV6]="Military service qcs 1937-50 out of range in MilServDates::getQc3750";
     res[PIA_IDS_MILSERV7]="Number of months out of range in MilServDates::getEarn3750";
     res[PIA_IDS_DISREQCAL1]="QcDisDate1.year out of range in PiaData::qcDisReqCal";
     res[PIA_IDS_DISREQCAL2]="QcDisDate6.year out of range in PiaData::qcDisReqCal";
     res[PIA_IDS_QCCAL]="Qcamt not set in PiaData::qcCal";
     res[PIA_IDS_EARNPROJ]="last year of earnings out of range in PiaData::earnProject";
     res[PIA_IDS_EARNTYPE1]="First year of earnings out of range in PiaWrite::writeEarntype";
     res[PIA_IDS_WRITEEARN]="First year of earnings out of range in PiaWrite::writeEarn";
     res[PIA_IDS_QCAMT]="Average wages not set in Qcamt::project";
     res[PIA_IDS_BITANN1]="Year out of range in BitAnnual";
     res[PIA_IDS_QCLUMPYEAR]="qclumpyear is out of range";
     res[PIA_IDS_QCPACKED1]="Index out of range in QcPacked::get";
     res[PIA_IDS_QCPACKED2]="Index out of range in QcPacked::set";
     res[PIA_IDS_BEGIN6]="Must have regular OASDI earnings, railroad, or military service";
     res[PIA_IDS_NONPENDATE1]="Noncovered pension entitlement date must not be before date of birth";
     res[PIA_IDS_NONPENDATE2]="Noncovered pension entitlement date must not be after date of death";
     res[PIA_IDS_NONPENDATE3]="Noncovered pension entitlement date is invalid (use Month/Year format)";
     res[PIA_IDS_NONPENDATEOUT]="Noncovered pension entitlement date: %1";
}

/// <summary>Loads the specified string resource and substitutes for the
/// characters "%1" the string referenced by filler.</summary>
///
/// <param name="result">A reference to a string that will contain the
/// resultant string after the substitution is performed.</param>
/// <param name="rsc">The resource ID of the template string on which the
/// substitution will be performed</param>
/// <param name="filler">A string that will replace the format characters "%1"
/// in the template string</param>
void AfxFormatString1(std::string& result, unsigned int rsc,
  const std::string& filler)
{
     if(!res.size())
          init_res();

     string source = res[rsc];
     result = StringFunctions::replace(source,"%1",filler);
}

/// <summary>Loads the specified string resource and substitutes for the
/// characters "%1"and "%2" the strings referenced by filler1 and filler2.
/// </summary>
///
/// <param name="result">A reference to a string that will contain the
/// resultant string after the substitution is performed.</param>
/// <param name="rsc">The resource ID of the template string on which the
/// substitution will be performed</param>
/// <param name="filler1">A string that will replace the format characters "%1"
/// in the template string</param>
/// <param name="filler2">A string that will replace the format characters "%1"
/// in the template string</param>
void AfxFormatString2(std::string& result, unsigned int rsc,
  const std::string& filler1, const std::string& filler2)
{
     if(!res.size())
          init_res();

     string source = res[rsc];
     string intermediate = StringFunctions::replace(source,"%1",filler1);
     result = StringFunctions::replace(intermediate,"%2",filler2);
}
