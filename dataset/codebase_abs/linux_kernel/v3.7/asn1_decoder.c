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
if ( V_6 == 0 ) {
if ( V_1 [ V_8 ++ ] != 0 )
goto V_15;
if ( -- V_11 <= 0 ) {
* V_4 = V_8 - * V_3 ;
* V_3 = V_8 ;
return 0 ;
}
goto V_12;
}
if ( F_2 ( ( V_6 & 0x1f ) == 0x1f ) ) {
do {
if ( F_2 ( V_2 - V_8 < 2 ) )
goto V_14;
V_7 = V_1 [ V_8 ++ ] ;
} while ( V_7 & 0x80 );
}
V_9 = V_1 [ V_8 ++ ] ;
if ( V_9 <= 0x7f ) {
V_8 += V_9 ;
goto V_12;
}
if ( F_2 ( V_9 == 0x80 ) ) {
if ( F_2 ( ( V_6 & V_16 ) == V_17 << 5 ) )
goto V_18;
V_11 ++ ;
goto V_12;
}
V_10 = V_9 - 0x80 ;
if ( F_2 ( V_10 > sizeof( T_1 ) - 1 ) )
goto V_19;
if ( F_2 ( V_10 > V_2 - V_8 ) )
goto V_14;
for ( V_9 = 0 ; V_10 > 0 ; V_10 -- ) {
V_9 <<= 8 ;
V_9 |= V_1 [ V_8 ++ ] ;
}
V_8 += V_9 ;
goto V_12;
V_19:
* V_5 = L_1 ;
goto error;
V_18:
* V_5 = L_2 ;
goto error;
V_15:
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
int F_3 ( const struct V_20 * V_21 ,
void * V_22 ,
const unsigned char * V_1 ,
T_1 V_2 )
{
const unsigned char * V_23 = V_21 -> V_23 ;
const T_2 * V_24 = V_21 -> V_24 ;
T_1 V_25 = V_21 -> V_25 ;
enum V_26 V_27 ;
unsigned char V_6 = 0 , V_28 = 0 , V_29 = 0 , V_30 = 0 , V_31 = 0 ;
const char * V_32 ;
T_1 V_33 = 0 , V_8 = 0 , V_34 = 0 , V_9 = 0 ;
int V_35 ;
unsigned char V_36 = 0 ;
#define F_4 0x01
#define F_5 0x02
#define F_6 0x20
#define F_7 10
unsigned short V_37 [ F_7 ] ;
unsigned short V_38 [ F_7 ] ;
unsigned char V_39 [ F_7 ] ;
#define F_8 10
unsigned char V_40 [ F_8 ] ;
if ( V_2 > 65535 )
return - V_41 ;
V_42:
F_9 ( L_6 ,
V_33 , V_25 , V_8 , V_2 , V_28 , V_29 ) ;
if ( F_2 ( V_33 >= V_25 ) )
goto V_43;
V_27 = V_23 [ V_33 ] ;
if ( F_2 ( V_33 + V_44 [ V_27 ] > V_25 ) )
goto V_43;
if ( V_27 <= V_45 ) {
unsigned char V_7 ;
if ( ( V_27 & V_46 &&
V_36 & F_5 ) ||
V_8 == V_2 ) {
V_33 += V_44 [ V_27 ] ;
goto V_42;
}
V_36 = 0 ;
V_31 = 2 ;
if ( F_2 ( V_8 >= V_2 - 1 ) )
goto V_14;
V_6 = V_1 [ V_8 ++ ] ;
if ( F_2 ( ( V_6 & 0x1f ) == 0x1f ) )
goto V_47;
if ( V_27 & V_48 ) {
F_9 ( L_7 , V_6 ) ;
} else {
V_30 = V_23 [ V_33 + 1 ] ;
V_36 |= V_30 & F_6 ;
V_7 = V_30 ^ V_6 ;
V_7 &= ~ ( V_30 & V_16 ) ;
F_9 ( L_8 , V_6 , V_30 , V_7 ) ;
if ( V_7 != 0 ) {
if ( V_27 & V_49 ) {
V_33 += V_44 [ V_27 ] ;
V_8 -- ;
goto V_42;
}
goto V_50;
}
}
V_36 |= F_5 ;
V_9 = V_1 [ V_8 ++ ] ;
if ( V_9 > 0x7f ) {
if ( F_2 ( V_9 == 0x80 ) ) {
if ( F_2 ( ! ( V_6 & V_16 ) ) )
goto V_18;
V_36 |= F_4 ;
if ( F_2 ( 2 > V_2 - V_8 ) )
goto V_14;
} else {
int V_10 = V_9 - 0x80 ;
if ( F_2 ( V_10 > 2 ) )
goto V_19;
if ( F_2 ( V_8 >= V_2 - V_10 ) )
goto V_14;
V_31 += V_10 ;
for ( V_9 = 0 ; V_10 > 0 ; V_10 -- ) {
V_9 <<= 8 ;
V_9 |= V_1 [ V_8 ++ ] ;
}
if ( F_2 ( V_9 > V_2 - V_8 ) )
goto V_14;
}
}
if ( V_36 & F_6 ) {
if ( F_2 ( V_28 >= F_7 ) )
goto V_51;
V_37 [ V_28 ] = V_8 ;
V_39 [ V_28 ] = V_31 ;
if ( ! ( V_36 & F_4 ) ) {
V_38 [ V_28 ] = V_2 ;
V_2 = V_8 + V_9 ;
} else {
V_38 [ V_28 ] = 0 ;
}
V_28 ++ ;
}
F_9 ( L_9 ,
V_6 , V_9 , V_36 & F_6 ? L_10 : L_11 ) ;
V_34 = V_8 ;
}
switch ( V_27 ) {
case V_52 :
case V_53 :
V_35 = V_24 [ V_23 [ V_33 + 1 ] ] ( V_22 , V_31 , V_6 , V_1 + V_8 , V_9 ) ;
if ( V_35 < 0 )
return V_35 ;
goto V_54;
case V_55 :
case V_56 :
case V_57 :
V_35 = V_24 [ V_23 [ V_33 + 2 ] ] ( V_22 , V_31 , V_6 , V_1 + V_8 , V_9 ) ;
if ( V_35 < 0 )
return V_35 ;
goto V_54;
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
V_54:
if ( ! ( V_36 & F_6 ) ) {
if ( V_36 & F_4 ) {
V_35 = F_1 (
V_1 , V_2 , & V_8 , & V_9 , & V_32 ) ;
if ( V_35 < 0 )
goto error;
} else {
V_8 += V_9 ;
}
F_9 ( L_12 , V_9 ) ;
}
V_33 += V_44 [ V_27 ] ;
goto V_42;
case V_63 :
case V_64 :
case V_65 :
F_9 ( L_13 ) ;
if ( F_2 ( V_29 == F_8 ) )
goto V_66;
V_40 [ V_29 ++ ] = V_33 + V_44 [ V_27 ] ;
V_33 = V_23 [ V_33 + 2 ] ;
goto V_42;
case V_67 :
if ( F_2 ( ! ( V_36 & F_5 ) ) )
goto V_50;
V_33 += V_44 [ V_27 ] ;
goto V_42;
case V_68 :
if ( F_2 ( V_29 != 0 || V_28 != 0 ) ) {
F_10 ( L_14 ,
V_29 , V_28 ) ;
return - V_69 ;
}
return 0 ;
case V_70 :
case V_71 :
if ( F_2 ( ! ( V_36 & F_5 ) ) )
goto V_50;
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
if ( F_2 ( V_28 <= 0 ) )
goto V_78;
V_28 -- ;
V_34 = V_37 [ V_28 ] ;
V_31 = V_39 [ V_28 ] ;
V_9 = V_2 ;
V_2 = V_38 [ V_28 ] ;
F_9 ( L_15 ,
V_34 , V_8 , V_9 , V_2 ) ;
if ( V_2 == 0 ) {
V_2 = V_9 ;
if ( F_2 ( V_2 - V_8 < 2 ) )
goto V_14;
if ( V_1 [ V_8 ++ ] != 0 ) {
if ( V_27 & V_79 ) {
V_8 -- ;
V_28 ++ ;
V_33 = V_23 [ V_33 + 1 ] ;
F_9 ( L_16 ) ;
goto V_42;
}
goto V_13;
}
if ( V_1 [ V_8 ++ ] != 0 )
goto V_15;
V_9 = V_8 - V_34 - 2 ;
} else {
if ( V_8 < V_9 && ( V_27 & V_79 ) ) {
V_2 = V_9 ;
V_28 ++ ;
V_33 = V_23 [ V_33 + 1 ] ;
F_9 ( L_16 ) ;
goto V_42;
}
if ( V_8 != V_9 )
goto V_80;
V_9 -= V_34 ;
F_9 ( L_17 , V_9 , V_8 - V_34 ) ;
}
if ( V_27 & V_81 ) {
unsigned char V_82 ;
if ( V_27 & V_79 )
V_82 = V_23 [ V_33 + 2 ] ;
else
V_82 = V_23 [ V_33 + 1 ] ;
V_35 = V_24 [ V_82 ] ( V_22 , V_31 , 0 , V_1 + V_34 , V_9 ) ;
}
V_33 += V_44 [ V_27 ] ;
goto V_42;
case V_83 :
V_35 = V_24 [ V_23 [ V_33 + 1 ] ] ( V_22 , V_31 , V_6 , V_1 + V_34 , V_9 ) ;
V_33 += V_44 [ V_27 ] ;
goto V_42;
case V_84 :
if ( F_2 ( V_29 <= 0 ) )
goto V_85;
V_33 = V_40 [ -- V_29 ] ;
goto V_42;
default:
break;
}
F_10 ( L_18 , V_27 ) ;
return - V_69 ;
V_14:
V_32 = L_4 ;
goto error;
V_43:
V_32 = L_19 ;
goto error;
V_85:
V_32 = L_20 ;
goto error;
V_66:
V_32 = L_21 ;
goto error;
V_78:
V_32 = L_22 ;
goto error;
V_51:
V_32 = L_23 ;
goto error;
V_80:
V_32 = L_24 ;
goto error;
V_13:
V_32 = L_5 ;
goto error;
V_15:
V_32 = L_3 ;
goto error;
V_19:
V_32 = L_1 ;
goto error;
V_18:
V_32 = L_2 ;
goto error;
V_50:
V_32 = L_25 ;
goto error;
V_47:
V_32 = L_26 ;
error:
F_9 ( L_27 ,
V_32 , V_33 , V_8 , V_30 , V_6 , V_9 ) ;
return - V_69 ;
}
