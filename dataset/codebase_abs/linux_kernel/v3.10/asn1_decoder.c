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
if ( F_2 ( ( V_6 & 0x1f ) == V_16 ) ) {
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
if ( F_2 ( V_9 == V_17 ) ) {
if ( F_2 ( ( V_6 & V_18 ) == V_19 << 5 ) )
goto V_20;
V_11 ++ ;
goto V_12;
}
V_10 = V_9 - 0x80 ;
if ( F_2 ( V_10 > sizeof( T_1 ) - 1 ) )
goto V_21;
if ( F_2 ( V_10 > V_2 - V_8 ) )
goto V_14;
for ( V_9 = 0 ; V_10 > 0 ; V_10 -- ) {
V_9 <<= 8 ;
V_9 |= V_1 [ V_8 ++ ] ;
}
V_8 += V_9 ;
goto V_12;
V_21:
* V_5 = L_1 ;
goto error;
V_20:
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
int F_3 ( const struct V_22 * V_23 ,
void * V_24 ,
const unsigned char * V_1 ,
T_1 V_2 )
{
const unsigned char * V_25 = V_23 -> V_25 ;
const T_2 * V_26 = V_23 -> V_26 ;
T_1 V_27 = V_23 -> V_27 ;
enum V_28 V_29 ;
unsigned char V_6 = 0 , V_30 = 0 , V_31 = 0 , V_32 = 0 , V_33 = 0 ;
const char * V_34 ;
T_1 V_35 = 0 , V_8 = 0 , V_36 = 0 , V_9 = 0 ;
int V_37 ;
unsigned char V_38 = 0 ;
#define F_4 0x01
#define F_5 0x02
#define F_6 0x20
#define F_7 10
unsigned short V_39 [ F_7 ] ;
unsigned short V_40 [ F_7 ] ;
unsigned char V_41 [ F_7 ] ;
#define F_8 10
unsigned char V_42 [ F_8 ] ;
if ( V_2 > 65535 )
return - V_43 ;
V_44:
F_9 ( L_6 ,
V_35 , V_27 , V_8 , V_2 , V_30 , V_31 ) ;
if ( F_2 ( V_35 >= V_27 ) )
goto V_45;
V_29 = V_25 [ V_35 ] ;
if ( F_2 ( V_35 + V_46 [ V_29 ] > V_27 ) )
goto V_45;
if ( V_29 <= V_47 ) {
unsigned char V_7 ;
if ( ( V_29 & V_48 &&
V_38 & F_5 ) ||
V_8 == V_2 ) {
V_35 += V_46 [ V_29 ] ;
goto V_44;
}
V_38 = 0 ;
V_33 = 2 ;
if ( F_2 ( V_8 >= V_2 - 1 ) )
goto V_14;
V_6 = V_1 [ V_8 ++ ] ;
if ( F_2 ( ( V_6 & 0x1f ) == V_16 ) )
goto V_49;
if ( V_29 & V_50 ) {
F_9 ( L_7 , V_6 ) ;
} else {
V_32 = V_25 [ V_35 + 1 ] ;
V_38 |= V_32 & F_6 ;
V_7 = V_32 ^ V_6 ;
V_7 &= ~ ( V_32 & V_18 ) ;
F_9 ( L_8 , V_6 , V_32 , V_7 ) ;
if ( V_7 != 0 ) {
if ( V_29 & V_51 ) {
V_35 += V_46 [ V_29 ] ;
V_8 -- ;
goto V_44;
}
goto V_52;
}
}
V_38 |= F_5 ;
V_9 = V_1 [ V_8 ++ ] ;
if ( V_9 > 0x7f ) {
if ( F_2 ( V_9 == V_17 ) ) {
if ( F_2 ( ! ( V_6 & V_18 ) ) )
goto V_20;
V_38 |= F_4 ;
if ( F_2 ( 2 > V_2 - V_8 ) )
goto V_14;
} else {
int V_10 = V_9 - 0x80 ;
if ( F_2 ( V_10 > 2 ) )
goto V_21;
if ( F_2 ( V_8 >= V_2 - V_10 ) )
goto V_14;
V_33 += V_10 ;
for ( V_9 = 0 ; V_10 > 0 ; V_10 -- ) {
V_9 <<= 8 ;
V_9 |= V_1 [ V_8 ++ ] ;
}
if ( F_2 ( V_9 > V_2 - V_8 ) )
goto V_14;
}
}
if ( V_38 & F_6 ) {
if ( F_2 ( V_30 >= F_7 ) )
goto V_53;
V_39 [ V_30 ] = V_8 ;
V_41 [ V_30 ] = V_33 ;
if ( ! ( V_38 & F_4 ) ) {
V_40 [ V_30 ] = V_2 ;
V_2 = V_8 + V_9 ;
} else {
V_40 [ V_30 ] = 0 ;
}
V_30 ++ ;
}
F_9 ( L_9 ,
V_6 , V_9 , V_38 & F_6 ? L_10 : L_11 ) ;
V_36 = V_8 ;
}
switch ( V_29 ) {
case V_54 :
case V_55 :
V_37 = V_26 [ V_25 [ V_35 + 1 ] ] ( V_24 , V_33 , V_6 , V_1 + V_8 , V_9 ) ;
if ( V_37 < 0 )
return V_37 ;
goto V_56;
case V_57 :
case V_58 :
case V_59 :
V_37 = V_26 [ V_25 [ V_35 + 2 ] ] ( V_24 , V_33 , V_6 , V_1 + V_8 , V_9 ) ;
if ( V_37 < 0 )
return V_37 ;
goto V_56;
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
V_56:
if ( ! ( V_38 & F_6 ) ) {
if ( V_38 & F_4 ) {
V_37 = F_1 (
V_1 , V_2 , & V_8 , & V_9 , & V_34 ) ;
if ( V_37 < 0 )
goto error;
} else {
V_8 += V_9 ;
}
F_9 ( L_12 , V_9 ) ;
}
V_35 += V_46 [ V_29 ] ;
goto V_44;
case V_65 :
case V_66 :
case V_67 :
F_9 ( L_13 ) ;
if ( F_2 ( V_31 == F_8 ) )
goto V_68;
V_42 [ V_31 ++ ] = V_35 + V_46 [ V_29 ] ;
V_35 = V_25 [ V_35 + 2 ] ;
goto V_44;
case V_69 :
if ( F_2 ( ! ( V_38 & F_5 ) ) )
goto V_52;
V_35 += V_46 [ V_29 ] ;
goto V_44;
case V_70 :
if ( F_2 ( V_31 != 0 || V_30 != 0 ) ) {
F_10 ( L_14 ,
V_31 , V_30 ) ;
return - V_71 ;
}
return 0 ;
case V_72 :
case V_73 :
if ( F_2 ( ! ( V_38 & F_5 ) ) )
goto V_52;
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
if ( F_2 ( V_30 <= 0 ) )
goto V_80;
V_30 -- ;
V_36 = V_39 [ V_30 ] ;
V_33 = V_41 [ V_30 ] ;
V_9 = V_2 ;
V_2 = V_40 [ V_30 ] ;
F_9 ( L_15 ,
V_36 , V_8 , V_9 , V_2 ) ;
if ( V_2 == 0 ) {
V_2 = V_9 ;
if ( F_2 ( V_2 - V_8 < 2 ) )
goto V_14;
if ( V_1 [ V_8 ++ ] != 0 ) {
if ( V_29 & V_81 ) {
V_8 -- ;
V_30 ++ ;
V_35 = V_25 [ V_35 + 1 ] ;
F_9 ( L_16 ) ;
goto V_44;
}
goto V_13;
}
if ( V_1 [ V_8 ++ ] != 0 )
goto V_15;
V_9 = V_8 - V_36 - 2 ;
} else {
if ( V_8 < V_9 && ( V_29 & V_81 ) ) {
V_2 = V_9 ;
V_30 ++ ;
V_35 = V_25 [ V_35 + 1 ] ;
F_9 ( L_16 ) ;
goto V_44;
}
if ( V_8 != V_9 )
goto V_82;
V_9 -= V_36 ;
F_9 ( L_17 , V_9 , V_8 - V_36 ) ;
}
if ( V_29 & V_83 ) {
unsigned char V_84 ;
if ( V_29 & V_81 )
V_84 = V_25 [ V_35 + 2 ] ;
else
V_84 = V_25 [ V_35 + 1 ] ;
V_37 = V_26 [ V_84 ] ( V_24 , V_33 , 0 , V_1 + V_36 , V_9 ) ;
}
V_35 += V_46 [ V_29 ] ;
goto V_44;
case V_85 :
V_37 = V_26 [ V_25 [ V_35 + 1 ] ] ( V_24 , V_33 , V_6 , V_1 + V_36 , V_9 ) ;
V_35 += V_46 [ V_29 ] ;
goto V_44;
case V_86 :
if ( F_2 ( V_31 <= 0 ) )
goto V_87;
V_35 = V_42 [ -- V_31 ] ;
goto V_44;
default:
break;
}
F_10 ( L_18 , V_29 ) ;
return - V_71 ;
V_14:
V_34 = L_4 ;
goto error;
V_45:
V_34 = L_19 ;
goto error;
V_87:
V_34 = L_20 ;
goto error;
V_68:
V_34 = L_21 ;
goto error;
V_80:
V_34 = L_22 ;
goto error;
V_53:
V_34 = L_23 ;
goto error;
V_82:
V_34 = L_24 ;
goto error;
V_13:
V_34 = L_5 ;
goto error;
V_15:
V_34 = L_3 ;
goto error;
V_21:
V_34 = L_1 ;
goto error;
V_20:
V_34 = L_2 ;
goto error;
V_52:
V_34 = L_25 ;
goto error;
V_49:
V_34 = L_26 ;
error:
F_9 ( L_27 ,
V_34 , V_35 , V_8 , V_32 , V_6 , V_9 ) ;
return - V_71 ;
}
