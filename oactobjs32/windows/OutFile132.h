// Declarations for the <see cref="OutFile132"/> class to manage print
// output to a file with 132-column lines.

// $Id: OutFile132.h 1.8 11/6/2024 12:29:22 Olson,DavidJ. $

#pragma once

#include <fstream>
#include "outfile.h"

/// <summary>Manages the print output functions, when printing to a
/// file formatted for 132 columns.</summary>
///
/// <remarks>Manages the print output functions, when printing to a
/// file formatted for 132 columns.</remarks>
class OutFile132 : public Out132
{
private:
  /// <summary>Number of columns to space over on left side.</summary>
  int cols;
  /// <summary>String of spaces for left side margin.</summary>
  char *colstring;
public:
  OutFile132( const std::string& newCorename = std::string("") );
  OutFile132( const std::string& newCorename,
    const std::string& newExtension );
  ~OutFile132();
  /// <summary>Advances one line.</summary>
  void advanceLine() { outstrm << "\n"; }
  /// <summary>Advances to next page.</summary>
  void formfeed() { outstrm << "\14" << "\n"; }
  /// <summary>Returns number of columns to space over on left side.</summary>
  ///
  /// <returns>Number of columns to space over on left side.</returns>
  int getCols() const { return cols; }
  /// <summary>Returns left-hand margin string.</summary>
  ///
  /// <returns>Left-hand margin string.</returns>
  const char *getColString() const { return((const char *)colstring); }
  /// <summary>Prints one line with a carriage return.</summary>
  ///
  /// <param name="str">String to print.</param>
  void printLine( const std::string& str )
  { outstrm << colstring << str << "\n"; }
  /// <summary>Prints one line with a carriage return.</summary>
  ///
  /// <param name="str">String to print.</param>
  void printLine( const char* str )
  { outstrm << colstring << str << "\n"; }
  /// <summary>Print a line of output with no carriage return.</summary>
  ///
  /// <param name="str">String to print.</param>
  void printLinena( const std::string& str )
  { outstrm << colstring << str << '\r'; }
  /// <summary>Print a line of output with no carriage return.</summary>
  ///
  /// <param name="str">String to print.</param>
  void printLinena( const char* str )
  { outstrm << colstring << str << '\r'; }
  void setCols( int newCols );
};
