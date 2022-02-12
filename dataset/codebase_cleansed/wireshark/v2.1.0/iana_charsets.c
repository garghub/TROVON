guint
mibenum_charset_to_encoding (guint charset)
{
switch (charset) {
case 3:
return ENC_NA|ENC_ASCII;
case 4:
return ENC_NA|ENC_ISO_8859_1;
case 5:
return ENC_NA|ENC_ISO_8859_2;
case 6:
return ENC_NA|ENC_ISO_8859_3;
case 7:
return ENC_NA|ENC_ISO_8859_4;
case 8:
return ENC_NA|ENC_ISO_8859_5;
case 9:
return ENC_NA|ENC_ISO_8859_6;
case 10:
return ENC_NA|ENC_ISO_8859_7;
case 11:
return ENC_NA|ENC_ISO_8859_8;
case 12:
return ENC_NA|ENC_ISO_8859_9;
case 13:
return ENC_NA|ENC_ISO_8859_10;
case 106:
return ENC_NA|ENC_UTF_8;
case 109:
return ENC_NA|ENC_ISO_8859_13;
case 110:
return ENC_NA|ENC_ISO_8859_14;
case 111:
return ENC_NA|ENC_ISO_8859_15;
case 112:
return ENC_NA|ENC_ISO_8859_16;
case 1000:
return ENC_BIG_ENDIAN|ENC_UCS_2;
case 1001:
return ENC_BIG_ENDIAN|ENC_UCS_4;
case 1013:
return ENC_BIG_ENDIAN|ENC_UTF_16;
case 1014:
return ENC_LITTLE_ENDIAN|ENC_UTF_16;
case 1015:
return ENC_LITTLE_ENDIAN|ENC_UTF_16;
case 2011:
return ENC_NA|ENC_CP437;
case 2259:
return ENC_NA|ENC_ISO_8859_11;
default:
return ENC_NA|ENC_ASCII;
}
}
