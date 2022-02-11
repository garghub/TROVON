static int F_1 ( const unsigned char * V_1 , T_1 V_2 ,
T_1 * V_3 , T_1 * V_4 ,
const char * * V_5 )
{
unsigned char V_6 , V_7 ;
T_1 V_8 = * V_3 , V_9 , V_10 ;
int V_11 = 1 ;
V_12:
if ( F_2 ( V_2 - V_8 < 2 ) ) {
if ( V_2 == V_8 )
goto V_13;
goto V_14;
}
V_6 = V_1 [ V_8 ++ ] ;
if ( V_6 == V_15 ) {
if ( V_1 [ V_8 ++ ] != 0 )
goto V_16;
if ( -- V_11 <= 0 ) {
* V_4 = V_8 - * V_3 ;
* V_3 = V_8 ;
return 0 ;
}
goto V_12;
}
if ( F_2 ( ( V_6 & 0x1f ) == V_17 ) ) {
do {
if ( F_2 ( V_2 - V_8 < 2 ) )
goto V_14;
V_7 = V_1 [ V_8 ++ ] ;
} while ( V_7 & 0x80 );
}
V_9 = V_1 [ V_8 ++ ] ;
if ( V_9 <= 0x7f )
goto V_18;
if ( F_2 ( V_9 == V_19 ) ) {
if ( F_2 ( ( V_6 & V_20 ) == V_21 << 5 ) )
goto V_22;
V_11 ++ ;
goto V_12;
}
V_10 = V_9 - 0x80 ;
if ( F_2 ( V_10 > sizeof( V_9 ) - 1 ) )
goto V_23;
if ( F_2 ( V_10 > V_2 - V_8 ) )
goto V_14;
V_9 = 0 ;
for (; V_10 > 0 ; V_10 -- ) {
V_9 <<= 8 ;
V_9 |= V_1 [ V_8 ++ ] ;
}
V_18:
if ( V_9 > V_2 - V_8 )
goto V_14;
V_8 += V_9 ;
goto V_12;
V_23:
* V_5 = L_1 ;
goto error;
V_22:
* V_5 = L_2 ;
goto error;
V_16:
* V_5 = L_3 ;
goto error;
V_14:
* V_5 = L_4 ;
goto error;
V_13:
* V_5 = L_5 ;
error:
* V_3 = V_8 ;
return - 1 ;
}
int F_3 ( const struct V_24 * V_25 ,
void * V_26 ,
const unsigned char * V_1 ,
T_1 V_2 )
{
const unsigned char * V_27 = V_25 -> V_27 ;
const T_2 * V_28 = V_25 -> V_28 ;
T_1 V_29 = V_25 -> V_29 ;
enum V_30 V_31 ;
unsigned char V_6 = 0 , V_32 = 0 , V_33 = 0 , V_34 = 0 , V_35 = 0 ;
const char * V_36 ;
T_1 V_37 = 0 , V_8 = 0 , V_38 = 0 , V_9 = 0 ;
int V_39 ;
unsigned char V_40 = 0 ;
#define F_4 0x01
#define F_5 0x02
#define F_6 0x04
#define F_7 0x20
#define F_8 10
unsigned short V_41 [ F_8 ] ;
unsigned short V_42 [ F_8 ] ;
unsigned char V_43 [ F_8 ] ;
#define F_9 10
unsigned char V_44 [ F_9 ] ;
if ( V_2 > 65535 )
return - V_45 ;
V_46:
F_10 ( L_6 ,
V_37 , V_29 , V_8 , V_2 , V_32 , V_33 ) ;
if ( F_2 ( V_37 >= V_29 ) )
goto V_47;
V_31 = V_27 [ V_37 ] ;
if ( F_2 ( V_37 + V_48 [ V_31 ] > V_29 ) )
goto V_47;
if ( V_31 <= V_49 ) {
unsigned char V_7 ;
if ( ( V_31 & V_50 && V_40 & F_5 ) ||
( V_31 & V_51 && V_8 == V_2 ) ) {
V_40 &= ~ F_6 ;
V_37 += V_48 [ V_31 ] ;
goto V_46;
}
V_40 = 0 ;
V_35 = 2 ;
if ( F_2 ( V_8 >= V_2 - 1 ) )
goto V_14;
V_6 = V_1 [ V_8 ++ ] ;
if ( F_2 ( ( V_6 & 0x1f ) == V_17 ) )
goto V_52;
if ( V_31 & V_53 ) {
F_10 ( L_7 , V_6 ) ;
} else {
V_34 = V_27 [ V_37 + 1 ] ;
V_40 |= V_34 & F_7 ;
V_7 = V_34 ^ V_6 ;
V_7 &= ~ ( V_34 & V_20 ) ;
F_10 ( L_8 , V_6 , V_34 , V_7 ) ;
if ( V_7 != 0 ) {
if ( V_31 & V_51 ) {
V_37 += V_48 [ V_31 ] ;
V_8 -- ;
goto V_46;
}
goto V_54;
}
}
V_40 |= F_5 ;
V_9 = V_1 [ V_8 ++ ] ;
if ( V_9 > 0x7f ) {
if ( F_2 ( V_9 == V_19 ) ) {
if ( F_2 ( ! ( V_6 & V_20 ) ) )
goto V_22;
V_40 |= F_4 ;
if ( F_2 ( 2 > V_2 - V_8 ) )
goto V_14;
} else {
int V_10 = V_9 - 0x80 ;
if ( F_2 ( V_10 > 2 ) )
goto V_23;
if ( F_2 ( V_8 >= V_2 - V_10 ) )
goto V_14;
V_35 += V_10 ;
for ( V_9 = 0 ; V_10 > 0 ; V_10 -- ) {
V_9 <<= 8 ;
V_9 |= V_1 [ V_8 ++ ] ;
}
if ( F_2 ( V_9 > V_2 - V_8 ) )
goto V_14;
}
}
if ( V_40 & F_7 ) {
if ( F_2 ( V_32 >= F_8 ) )
goto V_55;
V_41 [ V_32 ] = V_8 ;
V_43 [ V_32 ] = V_35 ;
if ( ! ( V_40 & F_4 ) ) {
V_42 [ V_32 ] = V_2 ;
V_2 = V_8 + V_9 ;
} else {
V_42 [ V_32 ] = 0 ;
}
V_32 ++ ;
}
F_10 ( L_9 ,
V_6 , V_9 , V_40 & F_7 ? L_10 : L_11 ) ;
V_38 = V_8 ;
}
switch ( V_31 ) {
case V_56 :
case V_57 :
case V_58 :
case V_59 :
V_39 = V_28 [ V_27 [ V_37 + 1 ] ] ( V_26 , V_35 , V_6 , V_1 + V_8 , V_9 ) ;
if ( V_39 < 0 )
return V_39 ;
goto V_60;
case V_61 :
case V_62 :
case V_63 :
V_39 = V_28 [ V_27 [ V_37 + 2 ] ] ( V_26 , V_35 , V_6 , V_1 + V_8 , V_9 ) ;
if ( V_39 < 0 )
return V_39 ;
goto V_60;
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
V_60:
if ( ! ( V_40 & F_7 ) ) {
if ( V_40 & F_4 ) {
V_39 = F_1 (
V_1 , V_2 , & V_8 , & V_9 , & V_36 ) ;
if ( V_39 < 0 )
goto error;
} else {
V_8 += V_9 ;
}
F_10 ( L_12 , V_9 ) ;
}
V_37 += V_48 [ V_31 ] ;
goto V_46;
case V_71 :
case V_72 :
case V_73 :
F_10 ( L_13 ) ;
if ( F_2 ( V_33 == F_9 ) )
goto V_74;
V_44 [ V_33 ++ ] = V_37 + V_48 [ V_31 ] ;
V_37 = V_27 [ V_37 + 2 ] ;
goto V_46;
case V_75 :
if ( F_2 ( ! ( V_40 & F_5 ) ) )
goto V_54;
V_37 += V_48 [ V_31 ] ;
goto V_46;
case V_76 :
if ( F_2 ( V_33 != 0 || V_32 != 0 ) ) {
F_11 ( L_14 ,
V_33 , V_32 ) ;
return - V_77 ;
}
return 0 ;
case V_78 :
case V_79 :
if ( F_2 ( ! ( V_40 & F_5 ) ) )
goto V_54;
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
if ( F_2 ( V_32 <= 0 ) )
goto V_86;
V_32 -- ;
V_38 = V_41 [ V_32 ] ;
V_35 = V_43 [ V_32 ] ;
V_9 = V_2 ;
V_2 = V_42 [ V_32 ] ;
F_10 ( L_15 ,
V_38 , V_8 , V_9 , V_2 ) ;
if ( V_2 == 0 ) {
V_2 = V_9 ;
if ( F_2 ( V_2 - V_8 < 2 ) )
goto V_14;
if ( V_1 [ V_8 ++ ] != 0 ) {
if ( V_31 & V_87 ) {
V_8 -- ;
V_32 ++ ;
V_37 = V_27 [ V_37 + 1 ] ;
F_10 ( L_16 ) ;
goto V_46;
}
goto V_13;
}
if ( V_1 [ V_8 ++ ] != 0 )
goto V_16;
V_9 = V_8 - V_38 - 2 ;
} else {
if ( V_8 < V_9 && ( V_31 & V_87 ) ) {
V_2 = V_9 ;
V_32 ++ ;
V_37 = V_27 [ V_37 + 1 ] ;
F_10 ( L_16 ) ;
goto V_46;
}
if ( V_8 != V_9 )
goto V_88;
V_9 -= V_38 ;
F_10 ( L_17 , V_9 , V_8 - V_38 ) ;
}
if ( V_31 & V_89 ) {
unsigned char V_90 ;
if ( V_31 & V_87 )
V_90 = V_27 [ V_37 + 2 ] ;
else
V_90 = V_27 [ V_37 + 1 ] ;
V_39 = V_28 [ V_90 ] ( V_26 , V_35 , 0 , V_1 + V_38 , V_9 ) ;
}
V_37 += V_48 [ V_31 ] ;
goto V_46;
case V_91 :
if ( ! ( V_40 & F_6 ) ) {
V_37 += V_48 [ V_31 ] ;
goto V_46;
}
case V_92 :
V_39 = V_28 [ V_27 [ V_37 + 1 ] ] ( V_26 , V_35 , V_6 , V_1 + V_38 , V_9 ) ;
if ( V_39 < 0 )
return V_39 ;
V_37 += V_48 [ V_31 ] ;
goto V_46;
case V_93 :
if ( F_2 ( V_33 <= 0 ) )
goto V_94;
V_37 = V_44 [ -- V_33 ] ;
V_40 |= F_5 | F_6 ;
goto V_46;
default:
break;
}
F_11 ( L_18 ,
V_31 , V_37 ) ;
return - V_77 ;
V_14:
V_36 = L_4 ;
goto error;
V_47:
V_36 = L_19 ;
goto error;
V_94:
V_36 = L_20 ;
goto error;
V_74:
V_36 = L_21 ;
goto error;
V_86:
V_36 = L_22 ;
goto error;
V_55:
V_36 = L_23 ;
goto error;
V_88:
V_36 = L_24 ;
goto error;
V_13:
V_36 = L_5 ;
goto error;
V_16:
V_36 = L_3 ;
goto error;
V_23:
V_36 = L_1 ;
goto error;
V_22:
V_36 = L_2 ;
goto error;
V_54:
V_36 = L_25 ;
goto error;
V_52:
V_36 = L_26 ;
error:
F_10 ( L_27 ,
V_36 , V_37 , V_8 , V_34 , V_6 , V_9 ) ;
return - V_77 ;
}
