static void
F_1 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
if ( V_3 != 2 ) {
F_2 ( V_4 , V_1 , V_2 , V_3 ,
L_1 , V_3 ) ;
return;
}
if ( F_3 ( V_1 , V_2 ) & 0x80 ) {
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_2 ,
F_3 ( V_1 , V_2 ) & 0x7F ) ;
} else {
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_3 ,
F_3 ( V_1 , V_2 ) & 0x7F ) ;
}
F_4 ( V_4 , V_5 , V_1 , V_2 + 1 , 1 , V_6 ) ;
}
static void
F_5 ( T_1 * V_1 , int V_2 , T_2 * V_4 )
{
unsigned int V_7 = F_3 ( V_1 , V_2 ) ;
if ( V_7 == V_8 ) {
F_6 ( V_4 , V_9 ,
V_1 , V_2 , 1 , V_7 ,
L_4 ) ;
} else if ( V_7 == V_10 ) {
F_6 ( V_4 , V_9 ,
V_1 , V_2 , 1 , V_7 ,
L_5 ) ;
} else if ( V_7 == V_11 ) {
F_6 ( V_4 , V_9 ,
V_1 , V_2 , 1 , V_7 ,
L_6 ) ;
} else if ( ( V_7 >= 16 && V_7 < 63 )
|| ( ( V_7 >= 80 ) && ( V_7 < 254 ) ) ) {
F_6 ( V_4 , V_9 ,
V_1 , V_2 , 1 , V_7 ,
L_7 ,
V_7 ) ;
} else if ( V_7 >= 64 && V_7 <= 79 ) {
F_6 ( V_4 , V_9 ,
V_1 , V_2 , 1 , V_7 ,
L_8 ,
V_7 ) ;
} else {
F_6 ( V_4 , V_9 ,
V_1 , V_2 , 1 , V_7 ,
L_9 ,
V_7 ) ;
}
}
void
F_7 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_12 ;
T_3 V_13 ;
T_3 V_14 ;
T_3 V_15 ;
T_3 V_16 ;
T_3 V_17 ;
T_3 V_18 ;
if ( V_3 == 0 )
return;
V_12 = F_3 ( V_1 , V_2 ) ;
V_13 = V_12 & 0x60 ;
if ( V_13 != V_19 ) {
F_2 ( V_4 , V_1 , V_2 ,
V_3 , L_10 ,
F_8 ( V_1 , V_2 , V_3 ) ) ;
F_9 ( V_4 , V_20 , V_1 , V_2 , 1 , V_12 ) ;
F_10 ( V_4 , V_21 , V_1 , V_2 , 1 , V_12 ) ;
return;
}
F_9 ( V_4 , V_20 , V_1 , V_2 , 1 , V_12 ) ;
F_10 ( V_4 , V_21 , V_1 , V_2 , 1 , V_12 ) ;
F_10 ( V_4 , V_22 , V_1 , V_2 , 1 , V_12 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( ! ( V_12 & V_23 ) ) {
if ( V_3 == 0 )
return;
V_12 = F_3 ( V_1 , V_2 ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_11 ,
( V_12 & 0x40 ) ? L_12 : L_13 ) ;
V_2 += 1 ;
V_3 -= 1 ;
}
if ( V_3 == 0 )
return;
V_12 = F_3 ( V_1 , V_2 ) ;
F_9 ( V_4 , V_20 , V_1 , V_2 , 1 , V_12 ) ;
F_10 ( V_4 , V_24 , V_1 , V_2 , 1 , V_12 ) ;
F_10 ( V_4 , V_25 , V_1 , V_2 , 1 , V_12 ) ;
V_14 = V_12 & 0x1F ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_14 == V_26 ) {
if ( V_3 == 0 )
return;
F_2 ( V_4 , V_1 , V_2 , 1 , L_14 , F_3 ( V_1 , V_2 ) & 0x7f ) ;
V_2 += 1 ;
V_3 -= 1 ;
}
if ( V_3 == 0 )
return;
V_12 = F_3 ( V_1 , V_2 ) ;
if ( ( V_12 & 0x60 ) == 0x20 ) {
F_9 ( V_4 , V_20 , V_1 , V_2 , 1 , V_12 ) ;
F_10 ( V_4 , V_27 , V_1 , V_2 , 1 , V_12 ) ;
F_10 ( V_4 , V_28 , V_1 , V_2 , 1 , V_12 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_12 & V_23 )
goto V_29;
if ( V_3 == 0 )
return;
V_12 = F_3 ( V_1 , V_2 ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_15 ,
( V_12 & 0x40 ) ? L_16 : L_17 ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_18 ,
( V_12 & 0x20 ) ? L_12 : L_13 ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_19 ,
F_11 ( V_12 & 0x1F , & V_30 ,
L_20 ) ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_12 & V_23 )
goto V_29;
if ( V_3 == 0 )
return;
V_12 = F_3 ( V_1 , V_2 ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_21 ,
F_12 ( V_12 & 0x60 , V_31 ,
L_22 ) ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_23 ,
( V_12 & 0x10 ) ? L_24 : L_25 ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_26 ,
( V_12 & 0x08 ) ? L_27 : L_28 ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_29 ,
( V_12 & 0x04 ) ? L_24 : L_25 ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_30 ,
( V_12 & 0x02 ) ? L_27 : L_28 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_12 & V_23 )
goto V_29;
if ( V_3 == 0 )
return;
V_12 = F_3 ( V_1 , V_2 ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_31 ,
( V_12 & 0x40 ) ? L_12 : L_13 ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_32 ,
( V_12 & 0x20 ) ? L_12 : L_13 ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_33 ,
( V_12 & 0x10 ) ? L_34 : L_35 ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
( V_12 & 0x08 ) ?
L_36 : L_37 ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_38 ,
( V_12 & 0x04 ) ? L_39 : L_40 ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_41 ,
( V_12 & 0x02 ) ? L_42 : L_43 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_12 & V_23 )
goto V_29;
if ( V_3 == 0 )
return;
V_12 = F_3 ( V_1 , V_2 ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_44 ,
F_12 ( V_12 & 0x60 , V_32 ,
L_22 ) ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_45 ,
F_12 ( V_12 & 0x18 , V_33 ,
L_22 ) ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_46 ,
F_12 ( V_12 & 0x07 , V_34 ,
L_22 ) ) ;
if ( V_12 & V_23 )
goto V_29;
V_12 = F_3 ( V_1 , V_2 ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_47 ,
( V_12 & 0x40 ) ? L_48 : L_49 ) ;
V_15 = V_12 & 0x3F ;
if ( V_15 <= 0x5 ||
( V_15 >= 0x20 && V_15 <= 0x2F ) ) {
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_50 , V_15 ) ;
} else if ( V_15 >= 0x30 ) {
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_51 , V_15 ) ;
} else {
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_52 ,
F_11 ( V_15 , & V_35 ,
L_20 ) ) ;
}
V_2 += 1 ;
V_3 -= 1 ;
}
V_29:
;
if ( V_3 == 0 )
return;
V_12 = F_3 ( V_1 , V_2 ) ;
if ( ( V_12 & 0x60 ) == 0x40 ) {
F_9 ( V_4 , V_20 , V_1 , V_2 , 1 , V_12 ) ;
F_10 ( V_4 , V_27 , V_1 , V_2 , 1 , V_12 ) ;
V_16 = V_12 & 0x1F ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_53 ,
F_11 ( V_16 , & V_36 ,
L_20 ) ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_12 & V_23 )
goto V_37;
if ( V_3 == 0 )
return;
V_12 = F_3 ( V_1 , V_2 ) ;
if ( V_16 == V_38 ) {
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_54 ,
V_12 & 0x7F ) ;
} else {
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_55 ,
F_12 ( V_12 & 0x60 , V_39 ,
L_20 ) ) ;
}
V_2 += 1 ;
V_3 -= 1 ;
if ( V_12 & V_23 )
goto V_37;
if ( V_3 == 0 )
return;
V_12 = F_3 ( V_1 , V_2 ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_56 , V_12 & 0x7F ) ;
V_2 += 1 ;
V_3 -= 1 ;
}
V_37:
;
if ( V_3 == 0 )
return;
V_12 = F_3 ( V_1 , V_2 ) ;
if ( ( V_12 & 0x60 ) == 0x60 ) {
F_9 ( V_4 , V_20 , V_1 , V_2 , 1 , V_12 ) ;
F_10 ( V_4 , V_27 , V_1 , V_2 , 1 , V_12 ) ;
V_17 = V_12 & 0x1F ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_57 ,
F_12 ( V_17 , V_40 ,
L_20 ) ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_12 & V_23 )
goto V_41;
if ( V_3 == 0 )
return;
V_12 = F_3 ( V_1 , V_2 ) ;
switch ( V_17 ) {
case V_42 :
case V_43 :
case V_44 :
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_55 ,
F_12 ( V_12 & 0x60 , V_39 ,
L_20 ) ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_12 & V_23 )
goto V_41;
if ( V_3 == 0 )
return;
V_12 = F_3 ( V_1 , V_2 ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_58 , V_12 & 0x0F ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_12 & V_23 )
goto V_41;
if ( V_3 == 0 )
return;
V_12 = F_3 ( V_1 , V_2 ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_59 , V_12 & 0x7F ) ;
break;
case V_45 :
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_60 ,
1 << ( V_12 & 0x0F ) ) ;
break;
case V_46 :
V_18 = ( V_12 & 0x0F ) << 4 ;
if ( V_12 & V_23 )
goto V_41;
if ( V_3 < 2 )
return;
V_12 = F_3 ( V_1 , V_2 + 1 ) ;
V_18 |= ( V_12 & 0x0F ) ;
F_2 ( V_4 , V_1 , V_2 , 2 ,
L_61 ,
F_12 ( V_18 , V_47 ,
L_20 ) ) ;
break;
}
}
V_41:
;
}
static const T_4 * F_13 ( T_3 V_48 , T_3 V_49 ) {
if ( V_48 == V_8 )
return F_12 ( V_49 , V_50 , L_20 ) ;
else
return F_11 ( V_49 , & V_51 , L_20 ) ;
}
static void
F_14 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 , int V_52 , T_3 * V_53 , const T_5 * V_54 )
{
T_3 V_12 ;
T_3 V_13 ;
T_3 V_55 ;
if ( V_3 == 0 )
return;
V_12 = F_3 ( V_1 , V_2 ) ;
V_13 = V_12 & 0x60 ;
if ( V_13 != V_19 ) {
F_10 ( V_4 , V_21 , V_1 , V_2 , 1 , V_12 ) ;
F_2 ( V_4 , V_1 , V_2 ,
V_3 , L_10 ,
F_8 ( V_1 , V_2 , V_3 ) ) ;
return;
}
F_10 ( V_4 , V_56 , V_1 , V_2 , 1 , V_12 ) ;
F_10 ( V_4 , V_21 , V_1 , V_2 , 1 , V_12 ) ;
F_9 ( V_4 , V_20 , V_1 , V_2 , 1 , V_12 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( ! ( V_12 & V_23 ) ) {
if ( V_3 == 0 )
return;
V_12 = F_3 ( V_1 , V_2 ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_62 ,
F_12 ( V_12 & 0x7F , V_57 ,
L_20 ) ) ;
F_9 ( V_4 , V_20 , V_1 , V_2 , 1 , V_12 ) ;
V_2 += 1 ;
V_3 -= 1 ;
}
if ( V_3 == 0 )
return;
V_12 = F_3 ( V_1 , V_2 ) ;
* V_53 = V_12 & 0x7F ;
if( V_58 ) {
V_59 -> V_53 = * V_53 ;
}
F_10 ( V_4 , V_52 , V_1 , V_2 , 1 , * V_53 ) ;
F_9 ( V_4 , V_20 , V_1 , V_2 , 1 , V_12 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_3 == 0 )
return;
switch ( * V_53 ) {
case V_60 :
case V_61 :
case V_62 :
V_12 = F_3 ( V_1 , V_2 ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_63 ,
( V_12 & 0x80 ) ? L_64 : L_65 ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_66 ,
( V_12 & 0x40 ) ? L_67 : L_68 ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_69 ,
F_12 ( V_12 & 0x03 , V_63 ,
L_22 ) ) ;
break;
case V_64 :
V_55 = V_12 & 0x7C ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_70 ,
F_12 ( V_12 & 0x7C , V_65 ,
L_22 ) ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_69 ,
F_12 ( V_12 & 0x03 , V_63 ,
L_22 ) ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_3 == 0 )
return;
switch ( V_55 ) {
case V_66 :
F_2 ( V_4 , V_1 , V_2 , V_3 ,
L_71 ,
F_8 ( V_1 , V_2 , V_3 ) ) ;
break;
case V_67 :
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_72 ,
F_12 ( F_3 ( V_1 , V_2 ) , V_54 ,
L_20 ) ) ;
break;
case V_68 :
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_73 ,
F_12 ( F_3 ( V_1 , V_2 ) , V_54 ,
L_20 ) ) ;
break;
default:
F_2 ( V_4 , V_1 , V_2 , V_3 ,
L_74 ,
F_8 ( V_1 , V_2 , V_3 ) ) ;
break;
}
break;
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
do {
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_75 ,
F_12 ( F_3 ( V_1 , V_2 ) , V_54 ,
L_20 ) ) ;
V_2 += 1 ;
V_3 -= 1 ;
} while ( V_3 != 0 );
break;
case V_74 :
case V_75 :
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_76 ,
F_11 ( F_3 ( V_1 , V_2 ) , & V_51 ,
L_20 ) ) ;
break;
case V_76 :
if ( V_3 < 3 )
return;
F_2 ( V_4 , V_1 , V_2 , 3 ,
L_77 , F_15 ( F_16 () , V_1 , V_2 , 3 ) ) ;
break;
default:
F_2 ( V_4 , V_1 , V_2 , V_3 ,
L_78 ,
F_8 ( V_1 , V_2 , V_3 ) ) ;
}
}
void
F_17 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 , int V_52 , T_3 * V_53 , const T_5 * V_54 )
{
T_6 V_77 = V_58 ;
V_58 = FALSE ;
F_14 ( V_1 , V_2 , V_3 , V_4 , V_52 , V_53 , V_54 ) ;
V_58 = V_77 ;
}
static void
F_18 ( T_1 * V_1 , int V_2 , int V_3 V_78 , T_2 * V_4 )
{
if ( V_3 == 0 )
return;
F_4 ( V_4 , V_20 , V_1 , V_2 , 1 , V_6 ) ;
F_4 ( V_4 , V_79 , V_1 , V_2 , 1 , V_6 ) ;
F_4 ( V_4 , V_80 , V_1 , V_2 , 1 , V_6 ) ;
}
static void
F_19 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_12 ;
T_3 V_13 ;
if ( V_3 == 0 )
return;
V_12 = F_3 ( V_1 , V_2 ) ;
V_13 = V_12 & 0x60 ;
F_10 ( V_4 , V_21 , V_1 , V_2 , 1 , V_12 ) ;
if ( V_13 != V_19 ) {
F_2 ( V_4 , V_1 , V_2 ,
V_3 , L_10 ,
F_8 ( V_1 , V_2 , V_3 ) ) ;
return;
}
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_79 ,
F_11 ( V_12 & 0x3F , & V_81 ,
L_20 ) ) ;
}
static void
F_20 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_12 ;
T_3 V_13 ;
if ( V_3 == 0 )
return;
V_12 = F_3 ( V_1 , V_2 ) ;
F_4 ( V_4 , V_20 , V_1 , V_2 , 1 , V_6 ) ;
F_4 ( V_4 , V_82 , V_1 , V_2 , 1 , V_6 ) ;
F_4 ( V_4 , V_83 , V_1 , V_2 , 1 , V_6 ) ;
F_4 ( V_4 , V_84 , V_1 , V_2 , 1 , V_6 ) ;
F_4 ( V_4 , V_85 , V_1 , V_2 , 1 , V_6 ) ;
if ( V_12 & V_86 ) {
F_4 ( V_4 , V_87 , V_1 , V_2 , 1 , V_6 ) ;
} else {
F_4 ( V_4 , V_88 , V_1 , V_2 , 1 , V_6 ) ;
}
V_2 += 1 ;
V_3 -= 1 ;
if ( V_12 & V_89 ) {
T_3 V_90 ;
T_7 V_91 = 0 ;
int V_92 = V_2 ;
int V_93 = 0 ;
do {
if ( V_3 == 0 )
break;
V_90 = F_3 ( V_1 , V_2 ) ;
V_2 += 1 ;
V_3 -= 1 ;
V_93 ++ ;
V_91 <<= 7 ;
V_91 |= V_90 & 0x7F ;
} while ( ! ( V_90 & V_23 ) );
if ( V_93 != 0 ) {
F_2 ( V_4 , V_1 , V_92 ,
V_93 , L_80 , V_91 ) ;
}
}
if ( V_12 & V_86 ) {
if ( V_3 == 0 )
return;
V_12 = F_3 ( V_1 , V_2 ) ;
V_13 = V_12 & 0x60 ;
F_4 ( V_4 , V_20 , V_1 , V_2 , 1 , V_6 ) ;
F_10 ( V_4 , V_21 , V_1 , V_2 , 1 , V_12 ) ;
if ( V_13 != V_19 ) {
F_2 ( V_4 , V_1 , V_2 ,
V_3 , L_10 ,
F_8 ( V_1 , V_2 , V_3 ) ) ;
return;
}
F_4 ( V_4 , V_94 , V_1 , V_2 , 1 , V_6 ) ;
F_4 ( V_4 , V_95 , V_1 , V_2 , 1 , V_6 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_12 & V_96 ) {
T_3 V_90 ;
while ( V_3 ) {
V_90 = F_3 ( V_1 , V_2 ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_81 , V_90 ) ;
V_2 += 1 ;
V_3 -= 1 ;
}
} else {
T_3 V_90 ;
do {
if ( V_3 == 0 )
break;
V_90 = F_3 ( V_1 , V_2 ) ;
F_4 ( V_4 , V_20 , V_1 , V_2 , 1 , V_6 ) ;
F_4 ( V_4 , V_97 , V_1 , V_2 , 1 , V_6 ) ;
V_2 += 1 ;
V_3 -= 1 ;
} while ( ! ( V_90 & V_23 ) );
}
}
}
void
F_21 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_12 ;
T_3 V_13 ;
if ( V_3 == 0 )
return;
V_12 = F_3 ( V_1 , V_2 ) ;
V_13 = V_12 & 0x60 ;
F_10 ( V_4 , V_21 , V_1 , V_2 , 1 , V_12 ) ;
if ( V_13 != V_19 ) {
F_2 ( V_4 , V_1 , V_2 ,
V_3 , L_10 ,
F_8 ( V_1 , V_2 , V_3 ) ) ;
return;
}
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_82 ,
F_11 ( V_12 & 0x0F , & V_98 ,
L_22 ) ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_3 == 0 )
return;
V_12 = F_3 ( V_1 , V_2 ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_83 ,
F_11 ( V_12 & 0x7F , & V_99 ,
L_20 ) ) ;
}
static void
F_22 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_12 ;
int V_100 ;
if ( V_3 == 0 )
return;
V_12 = F_3 ( V_1 , V_2 ) ;
V_100 = V_12 & 0x7F ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_84 ,
V_100 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_100 != 0 ) {
if ( V_3 == 0 )
return;
V_12 = F_3 ( V_1 , V_2 ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_85 ,
F_12 ( V_12 & 0x70 , V_101 ,
L_20 ) ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_86 ,
F_12 ( V_12 & 0x0F , V_102 ,
L_20 ) ) ;
V_2 += 1 ;
V_3 -= 1 ;
V_100 -- ;
if ( V_3 == 0 )
return;
if ( V_100 > V_3 )
V_100 = V_3 ;
if ( V_100 != 0 ) {
F_2 ( V_4 , V_1 , V_2 , V_100 ,
L_87 ,
F_23 ( V_1 , V_2 , V_100 ) ) ;
V_2 += V_100 ;
V_3 -= V_100 ;
}
}
if ( V_3 == 0 )
return;
F_2 ( V_4 , V_1 , V_2 ,
V_3 , L_88 ,
F_8 ( V_1 , V_2 , V_3 ) ) ;
}
static void
F_24 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_12 ;
if ( V_3 == 0 )
return;
V_12 = F_3 ( V_1 , V_2 ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_89 ,
F_12 ( V_12 & 0x7F , V_103 ,
L_20 ) ) ;
}
static void
F_25 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
if ( V_3 == 6 ) {
F_2 ( V_4 , V_1 , V_2 , 6 ,
L_90 ,
F_3 ( V_1 , V_2 + 0 ) , F_3 ( V_1 , V_2 + 1 ) , F_3 ( V_1 , V_2 + 2 ) ,
F_3 ( V_1 , V_2 + 3 ) , F_3 ( V_1 , V_2 + 4 ) , F_3 ( V_1 , V_2 + 5 ) ) ;
} else if ( V_3 == 5 ) {
F_2 ( V_4 , V_1 , V_2 , 5 ,
L_91 ,
F_3 ( V_1 , V_2 + 0 ) , F_3 ( V_1 , V_2 + 1 ) , F_3 ( V_1 , V_2 + 2 ) ,
F_3 ( V_1 , V_2 + 3 ) , F_3 ( V_1 , V_2 + 4 ) ) ;
} else {
F_2 ( V_4 , V_1 , V_2 , V_3 ,
L_92 , V_3 ) ;
}
}
static void
F_26 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
if ( V_3 != 1 ) {
F_2 ( V_4 , V_1 , V_2 , V_3 ,
L_93 , V_3 ) ;
return;
}
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_94 ,
F_11 ( F_3 ( V_1 , V_2 ) , & V_104 ,
L_20 ) ) ;
}
static void
F_27 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
if ( V_3 != 4 ) {
F_2 ( V_4 , V_1 , V_2 , V_3 ,
L_95 , V_3 ) ;
return;
}
F_2 ( V_4 , V_1 , V_2 + 0 , 1 ,
L_96 ,
F_11 ( F_3 ( V_1 , V_2 + 0 ) & 0x1F ,
& V_105 , L_20 ) ) ;
F_2 ( V_4 , V_1 , V_2 + 1 , 1 ,
L_97 ,
F_11 ( F_3 ( V_1 , V_2 + 1 ) & 0x1F ,
& V_105 , L_20 ) ) ;
F_2 ( V_4 , V_1 , V_2 + 2 , 1 ,
L_98 ,
F_11 ( F_3 ( V_1 , V_2 + 2 ) & 0x1F ,
& V_105 , L_20 ) ) ;
F_2 ( V_4 , V_1 , V_2 + 3 , 1 ,
L_99 ,
F_11 ( F_3 ( V_1 , V_2 + 3 ) & 0x1F ,
& V_105 , L_20 ) ) ;
}
static int
F_28 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 , const char * V_106 )
{
T_3 V_12 ;
T_8 V_107 ;
int V_108 ;
V_108 = 0 ;
V_12 = F_3 ( V_1 , V_2 ) ;
if ( V_12 & V_23 ) {
goto V_109;
}
V_107 = ( V_12 & 0x3 ) << 14 ;
V_2 += 1 ;
V_3 -= 1 ;
V_108 ++ ;
if ( V_3 == 0 ) {
goto V_110;
}
V_12 = F_3 ( V_1 , V_2 ) ;
if ( V_12 & V_23 ) {
goto V_109;
}
V_107 |= ( V_12 & 0x7F ) << 7 ;
V_2 += 1 ;
V_3 -= 1 ;
V_108 ++ ;
if ( V_3 == 0 ) {
goto V_110;
}
V_12 = F_3 ( V_1 , V_2 ) ;
if ( ! ( V_12 & V_23 ) ) {
goto V_109;
}
V_107 |= ( V_12 & 0x7F ) ;
V_2 += 1 ;
V_108 ++ ;
F_2 ( V_4 , V_1 , V_2 , V_108 , L_100 , V_106 ,
V_107 ) ;
return V_108 ;
V_110:
F_2 ( V_4 , V_1 , V_2 , V_3 ,
L_101 , V_106 ) ;
return - 1 ;
V_109:
F_2 ( V_4 , V_1 , V_2 , V_3 , L_102 ,
V_106 ) ;
return - 1 ;
}
static void
F_29 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
int V_108 ;
if ( V_3 == 0 )
return;
V_108 = F_28 ( V_1 , V_2 , V_3 , V_4 ,
L_103 ) ;
if ( V_108 < 0 )
return;
V_2 += V_108 ;
V_3 -= V_108 ;
if ( V_3 == 0 )
return;
V_108 = F_28 ( V_1 , V_2 , V_3 , V_4 ,
L_104 ) ;
if ( V_108 < 0 )
return;
V_2 += V_108 ;
V_3 -= V_108 ;
if ( V_3 == 0 )
return;
F_28 ( V_1 , V_2 , V_3 , V_4 ,
L_105 ) ;
}
static void
F_30 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
if ( V_3 == 0 )
return;
F_28 ( V_1 , V_2 , V_3 , V_4 ,
L_106 ) ;
}
static void
F_31 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_12 ;
if ( V_3 == 0 )
return;
V_12 = F_3 ( V_1 , V_2 ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_107 ,
F_12 ( V_12 & 0x18 , V_111 , L_20 ) ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_66 ,
( V_12 & 0x04 ) ? L_108 :
L_109 ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_110 ,
( V_12 & 0x02 ) ? L_111 : L_112 ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_113 ,
( V_12 & 0x01 ) ? 8 : 128 ) ;
}
static void
F_32 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
if ( V_3 == 0 )
return;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_114 , F_3 ( V_1 , V_2 ) & 0x7F ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_3 == 0 )
return;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_115 , F_3 ( V_1 , V_2 ) & 0x7F ) ;
}
static void
F_33 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
if ( V_3 == 0 )
return;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_114 , F_3 ( V_1 , V_2 ) & 0x7F ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_3 == 0 )
return;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_115 , F_3 ( V_1 , V_2 ) & 0x7F ) ;
}
static void
F_34 ( T_1 * V_1 , int V_2 , int V_3 , T_2 * V_4 )
{
if ( V_3 == 0 )
return;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_116 ,
F_12 ( F_3 ( V_1 , V_2 ) & 0x07 ,
V_112 , L_20 ) ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_3 == 0 )
return;
F_2 ( V_4 , V_1 , V_2 , V_3 , L_117 ,
F_23 ( V_1 , V_2 , V_3 ) ) ;
}
static void
F_35 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
if ( V_3 == 0 )
return;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_118 ,
F_12 ( F_3 ( V_1 , V_2 ) & 0x07 ,
V_113 , L_20 ) ) ;
}
static void
F_36 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 , int V_114 , T_9 V_115 )
{
T_3 V_12 ;
T_10 V_116 ;
if ( V_3 == 0 )
return;
V_12 = F_3 ( V_1 , V_2 ) ;
V_116 = V_12 & 0x0f ;
V_115 . V_117 = ( V_12 & 0x70 ) >> 4 ;
F_10 ( V_4 , V_118 , V_1 , V_2 , 1 , V_12 ) ;
F_10 ( V_4 , V_119 , V_1 , V_2 , 1 , V_12 ) ;
F_9 ( V_4 , V_20 , V_1 , V_2 , 1 , V_12 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( ! ( V_12 & V_23 ) ) {
if ( V_3 == 0 )
return;
V_12 = F_3 ( V_1 , V_2 ) ;
F_10 ( V_4 , V_120 , V_1 , V_2 , 1 , V_12 ) ;
F_10 ( V_4 , V_121 , V_1 , V_2 , 1 , V_12 ) ;
F_9 ( V_4 , V_20 , V_1 , V_2 , 1 , V_12 ) ;
V_2 += 1 ;
V_3 -= 1 ;
}
if ( ! ( V_12 & V_23 ) ) {
if ( V_3 == 0 )
return;
V_12 = F_3 ( V_1 , V_2 ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_119 ,
F_12 ( V_12 & 0x0F , V_122 ,
L_22 ) ) ;
V_2 += 1 ;
V_3 -= 1 ;
}
if ( V_3 == 0 )
return;
F_4 ( V_4 , V_114 , V_1 , V_2 , V_3 , V_123 | V_124 ) ;
F_37 ( F_38 ( V_4 ) , L_120 , F_23 ( V_1 , V_2 , V_3 ) ) ;
if ( V_116 == 1 ) {
if ( V_115 . V_125 != V_126 ) {
V_115 . V_127 = F_15 ( F_16 () , V_1 , V_2 , V_3 ) ;
V_115 . V_128 = V_3 ;
F_39 ( V_1 , V_4 , V_2 , V_3 , V_115 ) ;
}
}
if ( V_115 . V_125 == V_129 && V_58 )
V_59 -> V_130 = F_15 ( F_16 () , V_1 , V_2 , V_3 ) ;
if ( V_115 . V_125 == V_131 && V_58 )
V_59 -> V_132 = F_15 ( F_16 () , V_1 , V_2 , V_3 ) ;
}
static void
F_40 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_12 ;
if ( V_3 == 0 )
return;
V_12 = F_3 ( V_1 , V_2 ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_121 ,
F_12 ( V_12 & 0x70 , V_133 ,
L_20 ) ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_122 ,
F_12 ( V_12 & 0x08 , V_134 ,
L_20 ) ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_3 == 0 )
return;
F_2 ( V_4 , V_1 , V_2 , V_3 , L_123 ,
F_8 ( V_1 , V_2 , V_3 ) ) ;
}
static void
F_41 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
if ( V_3 != 1 ) {
F_2 ( V_4 , V_1 , V_2 , V_3 ,
L_124 , V_3 ) ;
return;
}
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_125 ,
F_12 ( F_3 ( V_1 , V_2 ) & 0x07 ,
V_135 , L_20 ) ) ;
}
void
F_42 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_12 ;
T_3 V_13 ;
T_3 V_136 ;
T_3 V_137 ;
if ( V_3 == 0 )
return;
V_12 = F_3 ( V_1 , V_2 ) ;
V_13 = V_12 & 0x60 ;
V_136 = V_12 & 0x03 ;
F_4 ( V_4 , V_20 , V_1 , V_2 , 1 , V_6 ) ;
F_10 ( V_4 , V_21 , V_1 , V_2 , 1 , V_12 ) ;
F_10 ( V_4 , V_138 , V_1 , V_2 , 1 , V_12 ) ;
F_10 ( V_4 , V_139 , V_1 , V_2 , 1 , V_12 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( ( V_13 != V_19 ) || ( V_136 != V_140 ) ) {
F_2 ( V_4 , V_1 , V_2 ,
V_3 , L_10 ,
F_8 ( V_1 , V_2 , V_3 ) ) ;
return;
}
if ( V_3 == 0 )
return;
V_12 = F_3 ( V_1 , V_2 ) ;
V_137 = V_12 & 0x7F ;
F_4 ( V_4 , V_20 , V_1 , V_2 , 1 , V_6 ) ;
F_10 ( V_4 , V_141 , V_1 , V_2 , 1 , V_12 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( ! ( V_12 & V_23 ) ) {
if ( V_3 == 0 )
return;
V_12 = F_3 ( V_1 , V_2 ) ;
if ( ( V_137 == V_142 ) || ( V_137 == 0x61 ) || ( V_137 == 0x62 ) ||
( V_137 == 0x68 ) ) {
F_4 ( V_4 , V_20 , V_1 , V_2 , 1 , V_6 ) ;
F_10 ( V_4 , V_143 , V_1 , V_2 , 1 , V_12 ) ;
}
else if ( ( V_137 == V_144 ) || ( V_137 == V_145 ) ) {
F_4 ( V_4 , V_20 , V_1 , V_2 , 1 , V_6 ) ;
F_10 ( V_4 , V_146 , V_1 , V_2 , 1 , V_12 ) ;
}
}
}
void
F_43 ( T_1 * V_1 , T_11 * V_147 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_12 ;
T_1 * V_148 = NULL ;
if ( V_3 == 0 )
return;
V_12 = F_3 ( V_1 , V_2 ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_126 ,
F_11 ( V_12 , & V_149 ,
L_127 ) ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_3 == 0 )
return;
switch ( V_12 ) {
case V_150 :
V_148 = F_44 ( V_1 , V_2 , V_3 , V_3 ) ;
F_2 ( V_4 , V_1 , V_2 , V_3 , L_128 , V_3 ) ;
if ( ! F_45 ( V_151 , V_148 , V_147 , V_4 , NULL ) ) {
F_46 ( V_152 , V_148 , V_147 , V_4 , NULL ) ;
}
break;
case V_153 :
F_2 ( V_4 , V_1 , V_2 , V_3 , L_129 ,
F_23 ( V_1 , V_2 , V_3 ) ) ;
break;
default:
F_2 ( V_4 , V_1 , V_2 , V_3 , L_129 ,
F_8 ( V_1 , V_2 , V_3 ) ) ;
break;
}
}
static void
F_47 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_12 ;
if ( V_3 == 0 )
return;
V_12 = F_3 ( V_1 , V_2 ) ;
F_2 ( V_4 , V_1 , V_2 , 1 ,
L_130 ,
F_12 ( V_12 & 0x07 , V_154 ,
L_127 ) ) ;
V_3 -= 1 ;
if ( V_3 == 0 )
return;
}
static void
F_48 ( T_1 * V_1 , int V_2 , int V_3 , T_2 * V_4 ,
const char * V_106 )
{
if ( V_3 != 0 ) {
F_2 ( V_4 , V_1 , V_2 , V_3 , L_131 , V_106 ,
F_23 ( V_1 , V_2 , V_3 ) ) ;
F_37 ( F_38 ( V_4 ) , L_132 , F_23 ( V_1 , V_2 , V_3 ) ) ;
}
}
static void
F_49 ( T_1 * V_1 , T_11 * V_147 , T_2 * V_4 ,
T_6 V_155 )
{
int V_2 = 0 ;
T_2 * V_156 = NULL ;
T_2 * V_157 = NULL ;
T_12 * V_158 , * V_159 ;
T_3 V_48 ;
T_3 V_160 ;
T_3 V_161 [ 15 ] ;
T_7 V_162 ;
T_3 V_49 , V_163 ;
T_3 V_164 ;
T_8 V_165 ;
T_6 V_166 , V_167 ;
T_7 V_168 ;
T_13 * V_169 ;
T_1 * V_148 = NULL ;
V_59 = F_50 ( F_16 () , V_170 ) ;
F_51 ( V_59 ) ;
V_58 = TRUE ;
F_52 ( V_147 -> V_171 , V_172 , L_5 ) ;
V_48 = F_3 ( V_1 , V_2 ) ;
if ( V_4 ) {
V_158 = F_4 ( V_4 , V_173 , V_1 , V_2 , - 1 ,
V_124 ) ;
V_156 = F_53 ( V_158 , V_174 ) ;
F_5 ( V_1 , V_2 , V_156 ) ;
}
V_2 += 1 ;
V_160 = F_3 ( V_1 , V_2 ) & 0xF ;
if ( V_156 != NULL )
F_10 ( V_156 , V_175 , V_1 , V_2 , 1 , V_160 ) ;
V_2 += 1 ;
switch ( V_160 ) {
case 0 : V_162 = 0 ; break;
case 1 : V_162 = F_3 ( V_1 , V_2 ) ; break;
case 2 : V_162 = F_54 ( V_1 , V_2 ) ; break;
case 3 : V_162 = F_55 ( V_1 , V_2 ) ; break;
default: V_162 = F_56 ( V_1 , V_2 ) ;
}
if ( V_160 != 0 ) {
F_57 ( V_1 , V_161 , V_2 , V_160 ) ;
if ( V_156 != NULL ) {
F_9 ( V_156 , V_176 ,
V_1 , V_2 , 1 , ( V_161 [ 0 ] & 0x80 ) != 0 ) ;
V_161 [ 0 ] &= 0x7F ;
F_58 ( V_156 , V_177 ,
V_1 , V_2 , V_160 , V_161 ) ;
} else
{
V_161 [ 0 ] &= 0x7F ;
}
memcpy ( & ( V_59 -> V_178 ) , V_161 , V_160 > sizeof( V_59 -> V_178 ) ? sizeof( V_59 -> V_178 ) : V_160 ) ;
V_2 += V_160 ;
}
V_49 = F_3 ( V_1 , V_2 ) ;
if( V_58 ) {
V_59 -> V_49 = V_49 ;
}
F_59 ( V_147 -> V_171 , V_179 , F_13 ( V_48 , V_49 ) ) ;
if ( V_48 == V_8 )
F_4 ( V_156 , V_180 , V_1 , V_2 , 1 , V_6 ) ;
else
F_4 ( V_156 , V_181 , V_1 , V_2 , 1 , V_6 ) ;
V_2 += 1 ;
if ( ( V_49 != V_182 ) || ! V_183 ||
( F_60 ( V_1 , V_2 ) <= 4 ) ) {
F_61 ( V_1 , V_147 , V_4 , V_156 , V_155 , V_2 , 0 ) ;
return;
}
V_164 = F_3 ( V_1 , V_2 ) ;
V_165 = F_3 ( V_1 , V_2 + 1 ) ;
if ( ( V_164 != V_184 ) || ( V_165 < 2 ) ) {
F_61 ( V_1 , V_147 , V_4 , V_156 , V_155 , V_2 , 0 ) ;
return;
}
V_159 = F_2 ( V_156 , V_1 , V_2 , 1 + 1 + V_165 , L_66 ,
F_12 ( V_164 , V_185 [ 0 ] , L_133 ) ) ;
V_157 = F_53 ( V_159 , V_186 ) ;
F_2 ( V_157 , V_1 , V_2 , 1 , L_75 ,
F_12 ( V_164 , V_185 [ 0 ] , L_20 ) ) ;
F_2 ( V_157 , V_1 , V_2 + 1 , 1 , L_134 , V_165 ) ;
F_1 ( V_1 , V_2 + 2 , V_165 , V_157 ) ;
V_166 = ( F_3 ( V_1 , V_2 + 2 ) & 0x80 ) != 0 ;
V_167 = ( F_3 ( V_1 , V_2 + 2 ) & 0x7F ) != 0 ;
V_163 = F_3 ( V_1 , V_2 + 3 ) ;
F_62 ( V_147 -> V_171 , V_179 , L_135 ,
F_11 ( V_163 , & V_51 , L_136 ) ) ;
V_2 += 1 + 1 + V_165 ;
V_168 = F_60 ( V_1 , V_2 ) ;
if ( V_166 && F_63 ( & V_187 , V_147 , V_162 , NULL ) ) {
F_64 ( & V_187 , V_147 , V_162 , NULL ) ;
}
V_169 = F_65 ( & V_187 ,
V_1 , V_2 , V_147 , V_162 , NULL ,
V_168 , V_167 ) ;
if ( V_169 ) {
if ( V_147 -> V_188 -> V_189 == V_169 -> V_190 ) {
if ( V_169 -> V_191 != NULL ) {
V_148 = F_66 ( V_1 , V_169 -> V_192 ) ;
F_67 ( V_147 , V_148 , L_137 ) ;
if ( V_4 ) {
T_12 * V_193 ;
F_68 ( V_169 , & V_194 , V_156 , V_147 , V_148 , & V_193 ) ;
}
} else {
V_148 = F_69 ( V_1 , V_2 ) ;
}
F_70 ( V_147 -> V_171 , V_179 , L_138 ,
F_11 ( V_163 , & V_51 , L_136 ) ) ;
} else {
if ( V_4 ) F_10 ( V_156 , V_195 , V_1 , V_2 , V_168 , V_169 -> V_190 ) ;
}
}
if ( V_148 )
F_61 ( V_148 , V_147 , V_4 , V_156 , V_155 , 0 , 0 ) ;
}
static void
F_61 ( T_1 * V_1 , T_11 * V_147 , T_2 * V_196 ,
T_2 * V_156 , T_6 V_155 , int V_2 , int V_197 )
{
T_12 * V_158 ;
T_2 * V_157 = NULL ;
T_3 V_164 ;
T_3 V_198 ;
T_8 V_165 ;
int V_199 , V_200 ;
T_6 V_201 , V_202 ;
T_1 * V_203 , * V_148 ;
T_9 V_115 ;
V_115 . V_125 = V_126 ;
V_115 . V_117 = V_126 ;
V_115 . V_127 = L_12 ;
V_115 . V_128 = V_126 ;
V_199 = V_200 = V_197 ;
V_202 = FALSE ;
while ( F_60 ( V_1 , V_2 ) > 0 ) {
V_164 = F_3 ( V_1 , V_2 ) ;
if ( ( V_164 & V_204 ) &&
( ( V_164 & V_205 ) == V_206 ) ) {
V_201 = V_164 & V_207 ;
V_199 = V_164 & V_208 ;
if ( ! V_201 )
V_200 = V_199 ;
if ( V_156 != NULL ) {
F_2 ( V_156 , V_1 , V_2 , 1 ,
L_139 ,
( V_201 ? L_140 : L_141 ) ,
V_199 ,
F_12 ( V_199 , V_209 ,
L_20 ) ) ;
}
V_2 += 1 ;
continue;
}
if ( V_164 & V_204 ) {
if ( F_71 ( V_210 , V_199 ) ||
F_71 ( V_211 , ( V_199 << 8 ) | ( V_164 & V_205 ) ) ) {
V_148 = F_44 ( V_1 , V_2 , 1 , 1 ) ;
if ( F_72 ( V_211 , ( V_199 << 8 ) | ( V_164 & V_205 ) , V_148 , V_147 , V_156 ) ||
F_72 ( V_210 , V_199 , V_148 , V_147 , V_156 ) ) {
V_2 += 1 ;
V_199 = V_200 ;
continue;
}
}
switch ( ( V_199 << 8 ) | ( V_164 & V_205 ) ) {
case V_212 | V_213 :
switch ( V_164 ) {
case V_214 :
if ( V_156 != NULL ) {
F_2 ( V_156 , V_1 , V_2 , 1 ,
L_142 ) ;
}
break;
case V_215 :
if ( V_156 != NULL ) {
F_2 ( V_156 , V_1 , V_2 , 1 ,
L_143 ) ;
}
break;
default:
if ( V_156 != NULL ) {
F_2 ( V_156 , V_1 , V_2 , 1 ,
L_133 ,
V_164 ) ;
}
break;
}
break;
case V_212 | V_216 :
if ( V_156 != NULL ) {
F_2 ( V_156 , V_1 , V_2 , 1 ,
L_144 ,
F_12 ( V_164 & V_217 ,
V_218 ,
L_22 ) ) ;
}
break;
case V_212 | V_219 :
if ( V_156 != NULL ) {
F_2 ( V_156 , V_1 , V_2 , 1 ,
L_145 ,
F_12 ( V_164 & V_217 ,
V_220 ,
L_22 ) ) ;
}
break;
default:
if ( V_156 != NULL ) {
F_2 ( V_156 , V_1 , V_2 , 1 ,
L_133 ,
V_164 ) ;
}
break;
}
V_2 += 1 ;
V_199 = V_200 ;
continue;
}
if ( V_155 && F_73 ( V_1 , V_2 , 4 ) &&
V_199 == 0 && F_3 ( V_1 , V_2 ) == V_221 &&
F_3 ( V_1 , V_2 + 3 ) == V_222 ) {
V_165 = F_54 ( V_1 , V_2 + 1 ) ;
if ( V_156 != NULL ) {
V_158 = F_2 ( V_156 , V_1 , V_2 ,
1 + 2 + V_165 , L_66 ,
F_12 ( V_164 ,
V_185 [ V_199 ] ,
L_133 ) ) ;
V_157 = F_53 ( V_158 ,
V_186 ) ;
F_2 ( V_157 , V_1 , V_2 , 1 ,
L_75 ,
F_12 ( V_164 ,
V_185 [ V_199 ] , L_20 ) ) ;
F_2 ( V_157 , V_1 , V_2 + 1 ,
2 , L_134 , V_165 ) ;
F_2 ( V_157 , V_1 , V_2 + 3 ,
1 , L_126 ,
F_11 ( F_3 ( V_1 , V_2 + 3 ) ,
& V_149 ,
L_127 ) ) ;
}
if ( V_165 > 1 ) {
if ( ! V_147 -> V_223 ) {
V_165 = F_74 ( V_165 , F_75 ( V_1 , V_2 + 3 ) ) ;
}
if ( V_224 != NULL ) {
V_203 = F_44 ( V_1 ,
V_2 + 4 , V_165 - 1 ,
V_165 - 1 ) ;
F_76 ( V_224 , V_203 ,
V_147 , V_196 ) ;
} else {
F_2 ( V_157 , V_1 ,
V_2 + 4 , V_165 - 1 ,
L_129 ,
F_8 ( V_1 , V_2 + 4 ,
V_165 - 1 ) ) ;
}
}
V_2 += 1 + 2 + V_165 ;
} else {
V_165 = F_3 ( V_1 , V_2 + 1 ) ;
if ( V_202 && ( F_60 ( V_1 , V_2 + 2 ) < V_165 ) ) {
F_2 ( V_156 , V_1 , V_2 , F_60 ( V_1 , V_2 ) , L_146 ) ;
break;
}
if ( F_71 ( V_210 , V_199 ) ||
F_71 ( V_211 , ( V_199 << 8 ) | V_164 ) ) {
V_148 = F_44 ( V_1 , V_2 , V_165 + 2 , V_165 + 2 ) ;
if ( F_72 ( V_211 , ( V_199 << 8 ) | V_164 , V_148 , V_147 , V_156 ) ||
F_72 ( V_210 , V_199 , V_148 , V_147 , V_156 ) ) {
V_2 += 2 + V_165 ;
V_199 = V_200 ;
continue;
}
}
V_158 = F_2 ( V_156 , V_1 , V_2 , 1 + 1 + V_165 , L_66 ,
F_12 ( V_164 , V_185 [ V_199 ] , L_133 ) ) ;
V_157 = F_53 ( V_158 , V_186 ) ;
F_2 ( V_157 , V_1 , V_2 , 1 , L_75 ,
F_12 ( V_164 , V_185 [ V_199 ] , L_20 ) ) ;
F_2 ( V_157 , V_1 , V_2 + 1 , 1 , L_134 , V_165 ) ;
if ( ( ( V_199 << 8 ) | V_164 ) == ( V_212 | V_184 ) ) {
F_1 ( V_1 , V_2 + 2 , V_165 , V_157 ) ;
F_62 ( V_147 -> V_171 , V_179 , L_135 ,
F_11 ( F_3 ( V_1 , V_2 + 3 ) , & V_51 , L_136 ) ) ;
if ( F_3 ( V_1 , V_2 + 2 ) & 0x80 ) {
V_202 = TRUE ;
} else {
F_2 ( V_156 , V_1 , V_2 + 4 , F_60 ( V_1 , V_2 + 4 ) , L_147 ) ;
V_165 += F_60 ( V_1 , V_2 + 4 ) ;
}
} else {
switch ( ( V_199 << 8 ) | V_164 ) {
case V_212 | V_225 :
case V_212 | V_226 :
if ( V_156 != NULL ) {
F_7 ( V_1 ,
V_2 + 2 , V_165 ,
V_157 ) ;
}
break;
case V_212 | V_227 :
F_14 ( V_1 ,
V_2 + 2 , V_165 ,
V_157 ,
V_228 , & V_198 , V_229 ) ;
break;
case V_212 | V_230 :
if ( V_156 != NULL ) {
F_18 ( V_1 ,
V_2 + 2 , V_165 ,
V_157 ) ;
}
break;
case V_212 | V_231 :
if ( V_156 != NULL ) {
F_19 ( V_1 ,
V_2 + 2 , V_165 ,
V_157 ) ;
}
break;
case V_212 | V_232 :
if ( V_156 != NULL ) {
F_20 (
V_1 , V_2 + 2 , V_165 ,
V_157 ) ;
}
break;
case V_212 | V_233 :
if ( V_156 != NULL ) {
F_21 ( V_1 ,
V_2 + 2 , V_165 ,
V_157 ) ;
}
break;
case V_212 | V_234 :
case V_212 | V_235 :
if ( V_156 != NULL ) {
F_22 ( V_1 ,
V_2 + 2 , V_165 ,
V_157 ) ;
}
break;
case V_212 | V_236 :
if ( V_156 != NULL ) {
F_24 (
V_1 , V_2 + 2 , V_165 ,
V_157 ) ;
}
break;
case V_212 | V_237 :
if ( V_156 != NULL ) {
F_48 ( V_1 , V_2 + 2 ,
V_165 , V_157 ,
L_148 ) ;
}
break;
case V_212 | V_238 :
if ( V_156 != NULL ) {
F_25 ( V_1 ,
V_2 + 2 , V_165 ,
V_157 ) ;
}
break;
case V_212 | V_239 :
if ( V_156 != NULL ) {
F_48 ( V_1 , V_2 + 2 ,
V_165 , V_157 ,
L_149 ) ;
}
break;
case V_212 | V_240 :
if ( V_156 != NULL ) {
F_26 ( V_1 ,
V_2 + 2 , V_165 ,
V_157 ) ;
}
break;
case V_212 | V_241 :
if ( V_156 != NULL ) {
F_27 ( V_1 ,
V_2 + 2 , V_165 ,
V_157 ) ;
}
break;
case V_212 | V_242 :
if ( V_156 != NULL ) {
F_29 ( V_1 ,
V_2 + 2 , V_165 ,
V_157 ) ;
}
break;
case V_212 | V_243 :
if ( V_156 != NULL ) {
F_30 (
V_1 , V_2 + 2 , V_165 ,
V_157 ) ;
}
break;
case V_212 | V_244 :
if ( V_156 != NULL ) {
F_31 (
V_1 , V_2 + 2 , V_165 ,
V_157 ) ;
}
break;
case V_212 | V_245 :
if ( V_156 != NULL ) {
F_32 ( V_1 ,
V_2 + 2 , V_165 ,
V_157 ) ;
}
break;
case V_212 | V_246 :
if ( V_156 != NULL ) {
F_33 ( V_1 ,
V_2 + 2 , V_165 ,
V_157 ) ;
}
break;
case V_212 | V_247 :
if ( V_156 != NULL ) {
F_34 ( V_1 ,
V_2 + 2 , V_165 ,
V_157 ) ;
}
break;
case V_212 | V_248 :
if ( V_156 != NULL ) {
F_35 ( V_1 ,
V_2 + 2 , V_165 ,
V_157 ) ;
}
break;
case V_212 | V_249 :
if ( V_156 != NULL ) {
F_36 ( V_1 ,
V_2 + 2 , V_165 ,
V_157 ,
V_250 , V_115 ) ;
}
break;
case V_212 | V_251 :
V_115 . V_125 = V_129 ;
F_36 ( V_1 ,
V_2 + 2 , V_165 ,
V_157 ,
V_252 , V_115 ) ;
break;
case V_212 | V_253 :
V_115 . V_125 = V_131 ;
F_36 ( V_1 ,
V_2 + 2 , V_165 ,
V_157 ,
V_254 , V_115 ) ;
break;
case V_212 | V_255 :
case V_212 | V_256 :
if ( V_156 != NULL ) {
F_40 ( V_1 ,
V_2 + 2 , V_165 ,
V_157 ) ;
}
break;
case V_212 | V_257 :
if ( V_156 != NULL ) {
F_36 ( V_1 ,
V_2 + 2 , V_165 ,
V_157 ,
V_258 , V_115 ) ;
}
break;
case V_212 | V_259 :
if ( V_156 != NULL ) {
F_41 ( V_1 ,
V_2 + 2 , V_165 ,
V_157 ) ;
}
break;
case V_212 | V_260 :
if ( V_156 != NULL ) {
F_42 ( V_1 ,
V_2 + 2 , V_165 ,
V_157 ) ;
}
break;
case V_212 | V_221 :
if ( V_156 != NULL ) {
F_43 ( V_1 , V_147 ,
V_2 + 2 , V_165 ,
V_157 ) ;
}
break;
case V_261 | V_262 :
if ( V_156 != NULL ) {
F_47 ( V_1 ,
V_2 + 2 , V_165 ,
V_157 ) ;
}
break;
case V_263 | V_237 :
if ( V_156 != NULL ) {
F_48 ( V_1 , V_2 + 2 ,
V_165 , V_157 ,
L_150 ) ;
}
break;
default:
if ( V_156 != NULL ) {
F_2 ( V_157 , V_1 ,
V_2 + 2 , V_165 ,
L_10 ,
F_8 ( V_1 , V_2 + 2 ,
V_165 ) ) ;
}
break;
}
}
V_2 += 1 + 1 + V_165 ;
}
V_199 = V_200 ;
}
if( V_58 ) {
F_77 ( V_264 , V_147 , V_59 ) ;
}
V_58 = FALSE ;
}
static T_6
F_78 ( T_1 * V_1 , T_11 * V_147 , T_2 * V_4 , void * T_14 V_78 )
{
int V_265 ;
V_265 = F_79 ( V_1 , 3 ) ;
if ( V_265 == - 1 ) {
return FALSE ;
}
if ( F_80 ( V_1 ) == 4 ) {
F_81 ( V_1 , V_147 , V_4 , V_266 ,
V_267 ) ;
return TRUE ;
}
if ( ! F_73 ( V_1 , 4 , 3 ) )
return FALSE ;
if ( ( F_3 ( V_1 , 4 ) != V_10 ) && ( F_3 ( V_1 , 4 ) != 0x03 ) ) {
return FALSE ;
}
F_81 ( V_1 , V_147 , V_4 , V_266 ,
V_267 ) ;
return TRUE ;
}
static void
F_82 ( T_1 * V_1 , T_11 * V_147 , T_2 * V_4 )
{
F_78 ( V_1 , V_147 , V_4 , NULL ) ;
}
static void
F_83 ( T_1 * V_1 , T_11 * V_147 , T_2 * V_4 )
{
F_49 ( V_1 , V_147 , V_4 , TRUE ) ;
}
static void
F_84 ( T_1 * V_1 , T_11 * V_147 , T_2 * V_4 )
{
F_49 ( V_1 , V_147 , V_4 , FALSE ) ;
}
static void
F_85 ( T_1 * V_1 , T_11 * V_147 , T_2 * V_4 )
{
F_49 ( V_1 , V_147 , V_4 , TRUE ) ;
}
static void
F_86 ( T_1 * V_1 , T_11 * V_147 , T_2 * V_4 )
{
F_61 ( V_1 , V_147 , NULL , V_4 , FALSE , 0 , 0 ) ;
}
static void
F_87 ( T_1 * V_1 , T_11 * V_147 , T_2 * V_4 )
{
F_61 ( V_1 , V_147 , NULL , V_4 , FALSE , 0 , 7 ) ;
}
static void
F_88 ( void ) {
F_89 ( & V_187 ,
& V_268 ) ;
}
void
F_90 ( void )
{
static T_15 V_269 [] = {
{ & V_9 ,
{ L_151 , L_152 , V_270 , V_271 , NULL , 0x0 ,
NULL , V_272 } } ,
{ & V_175 ,
{ L_153 , L_154 , V_270 , V_273 , NULL , 0x0 ,
NULL , V_272 } } ,
{ & V_176 ,
{ L_155 , L_156 , V_274 , V_275 , F_91 ( & V_276 ) , 0x0 ,
NULL , V_272 } } ,
{ & V_177 ,
{ L_157 , L_158 , V_277 , V_275 , NULL , 0x0 ,
NULL , V_272 } } ,
{ & V_181 ,
{ L_159 , L_160 , V_270 , V_271 | V_278 , & V_51 , 0x0 ,
NULL , V_272 } } ,
{ & V_180 ,
{ L_161 , L_162 , V_270 , V_271 , F_92 ( V_50 ) , 0x0 ,
NULL , V_272 } } ,
{ & V_5 ,
{ L_163 , L_164 , V_270 , V_271 | V_278 , & V_51 , 0x0 ,
NULL , V_272 } } ,
{ & V_21 ,
{ L_165 , L_166 , V_270 , V_271 ,
F_92 ( V_279 ) , 0x60 , NULL , V_272 } } ,
{ & V_138 ,
{ L_167 , L_168 , V_270 , V_271 ,
F_92 ( V_280 ) , 0x1C , NULL , V_272 } } ,
{ & V_139 ,
{ L_169 , L_170 , V_270 , V_271 ,
F_92 ( V_281 ) , 0x03 , NULL , V_272 } } ,
{ & V_141 ,
{ L_171 , L_172 , V_270 , V_271 | V_278 ,
& V_282 , 0x7f , NULL , V_272 } } ,
{ & V_146 ,
{ L_173 , L_174 , V_270 , V_271 | V_278 ,
& V_283 , 0x7f , NULL , V_272 } } ,
{ & V_143 ,
{ L_175 , L_176 , V_270 , V_271 ,
F_92 ( V_284 ) , 0x7f , NULL , V_272 } } ,
{ & V_22 ,
{ L_177 , L_178 , V_270 , V_271 ,
F_92 ( V_285 ) , 0x1f , NULL , V_272 } } ,
{ & V_24 ,
{ L_179 , L_180 , V_270 , V_271 ,
F_92 ( V_286 ) , 0x60 , NULL , V_272 } } ,
{ & V_25 ,
{ L_181 , L_182 , V_270 , V_271 ,
F_92 ( V_287 ) , 0x1f , NULL , V_272 } } ,
{ & V_27 ,
{ L_183 , L_184 , V_270 , V_271 ,
F_92 ( V_288 ) , 0x60 , NULL , V_272 } } ,
{ & V_28 ,
{ L_185 , L_186 , V_270 , V_271 | V_278 ,
& V_289 , 0x1f , NULL , V_272 } } ,
{ & V_56 ,
{ L_187 , L_188 , V_270 , V_273 | V_278 , & V_98 , 0x0f ,
NULL , V_272 } } ,
{ & V_228 ,
{ L_189 , L_190 , V_270 , V_273 | V_278 , & V_290 , 0x7f ,
NULL , V_272 } } ,
{ & V_119 ,
{ L_191 , L_192 , V_270 , V_271 , F_92 ( V_291 ) , 0x70 ,
NULL , V_272 } } ,
{ & V_118 ,
{ L_193 , L_194 , V_270 , V_271 , F_92 ( V_292 ) , 0x0f ,
NULL , V_272 } } ,
{ & V_120 ,
{ L_195 , L_196 , V_270 , V_271 , F_92 ( V_293 ) , 0x03 ,
NULL , V_272 } } ,
{ & V_121 ,
{ L_197 , L_198 , V_270 , V_271 , F_92 ( V_294 ) , 0x60 ,
NULL , V_272 } } ,
{ & V_20 ,
{ L_199 , L_200 ,
V_274 , 8 , F_91 ( & V_295 ) , 0x80 ,
NULL , V_272 } } ,
{ & V_79 ,
{ L_201 , L_202 ,
V_270 , V_273 , F_92 ( V_296 ) , 0x40 ,
NULL , V_272 } } ,
{ & V_80 ,
{ L_203 , L_204 ,
V_270 , V_273 , F_92 ( V_297 ) , 0x07 ,
NULL , V_272 } } ,
{ & V_252 ,
{ L_205 , L_206 , V_298 , V_275 , NULL , 0x0 ,
NULL , V_272 } } ,
{ & V_254 ,
{ L_207 , L_208 , V_298 , V_275 , NULL , 0x0 ,
NULL , V_272 } } ,
{ & V_250 ,
{ L_209 , L_210 , V_298 , V_275 , NULL , 0x0 ,
NULL , V_272 } } ,
{ & V_258 ,
{ L_211 , L_212 , V_298 , V_275 , NULL , 0x0 ,
NULL , V_272 } } ,
{ & V_82 ,
{ L_213 , L_214 , V_274 , 8 , NULL , 0x40 ,
L_215 , V_272 } } ,
{ & V_83 ,
{ L_216 , L_217 , V_274 , 8 , F_91 ( & V_299 ) , 0x20 ,
L_218 , V_272 } } ,
{ & V_84 ,
{ L_219 , L_220 , V_274 , 8 , F_91 ( & V_300 ) , 0x08 ,
L_221 , V_272 } } ,
{ & V_85 ,
{ L_222 , L_223 , V_274 , 8 , NULL , 0x04 ,
L_224 , V_272 } } ,
{ & V_88 ,
{ L_225 , L_226 , V_270 , V_271 , V_301 , 0x03 ,
L_227 , V_272 } } ,
{ & V_87 ,
{ L_225 , L_226 , V_270 , V_271 , V_302 , 0x03 ,
L_227 , V_272 } } ,
{ & V_94 ,
{ L_228 , L_229 , V_274 , 8 , F_91 ( & V_303 ) , 0x10 ,
L_230 , V_272 } } ,
{ & V_95 ,
{ L_231 , L_232 , V_270 , V_271 , V_304 , 0xF ,
L_233 , V_272 } } ,
{ & V_97 ,
{ L_234 , L_235 , V_270 , V_273 , NULL , 0x7F ,
NULL , V_272 } } ,
{ & V_305 ,
{ L_236 , L_237 , V_274 , V_275 , NULL , 0x0 ,
L_238 , V_272 } } ,
{ & V_306 ,
{ L_239 , L_240 , V_274 , V_275 , NULL , 0x0 ,
L_241 , V_272 } } ,
{ & V_307 ,
{ L_242 , L_243 , V_274 , V_275 , NULL , 0x0 ,
L_244 , V_272 } } ,
{ & V_308 ,
{ L_245 , L_246 , V_274 , V_275 , NULL , 0x0 ,
L_247 , V_272 } } ,
{ & V_309 ,
{ L_248 , L_249 , V_310 , V_275 , NULL , 0x0 ,
L_250 , V_272 } } ,
{ & V_311 ,
{ L_251 , L_252 , V_312 , V_273 , NULL , 0x0 ,
NULL , V_272 } } ,
{ & V_313 ,
{ L_253 , L_254 , V_310 , V_275 , NULL , 0x0 ,
NULL , V_272 } } ,
{ & V_314 ,
{ L_255 , L_256 , V_315 , V_275 , NULL , 0x0 ,
NULL , V_272 } } ,
{ & V_195 ,
{ L_257 , L_258 , V_310 , V_275 , NULL , 0x0 ,
L_259 , V_272 } } ,
{ & V_316 ,
{ L_260 , L_261 , V_312 , V_273 , NULL , 0x0 ,
L_262 , V_272 } } ,
} ;
static T_10 * V_317 [] = {
& V_174 ,
& V_186 ,
& V_318 ,
& V_319 ,
} ;
T_16 * V_320 ;
V_173 = F_93 ( L_5 , L_5 , L_263 ) ;
F_94 ( V_173 , V_269 , F_95 ( V_269 ) ) ;
F_96 ( V_317 , F_95 ( V_317 ) ) ;
F_97 ( F_88 ) ;
F_98 ( L_263 , F_84 , V_173 ) ;
F_98 ( L_264 , F_82 , V_173 ) ;
V_321 = F_99 ( L_264 ) ;
V_267 = F_100 ( F_83 ,
V_173 ) ;
F_98 ( L_265 , F_85 , V_173 ) ;
F_98 ( L_266 , F_86 , V_173 ) ;
F_98 ( L_267 , F_87 , V_173 ) ;
V_210 = F_101 ( L_268 , L_269 , V_270 , V_271 ) ;
V_211 = F_101 ( L_266 , L_270 , V_322 , V_271 ) ;
F_102 ( L_271 , & V_151 ) ;
V_320 = F_103 ( V_173 , NULL ) ;
F_104 ( V_320 , L_272 ,
L_273 ,
L_274
L_275 ,
& V_266 ) ;
F_104 ( V_320 , L_276 ,
L_277 ,
L_278 ,
& V_183 ) ;
V_264 = F_105 ( L_263 ) ;
}
void
F_106 ( void )
{
T_17 V_323 ;
T_17 V_324 ;
V_323 = F_99 ( L_263 ) ;
F_107 ( L_279 , V_325 , V_323 ) ;
V_324 = F_99 ( L_265 ) ;
F_107 ( L_280 , V_326 , V_324 ) ;
V_224 = F_99 ( L_281 ) ;
V_152 = F_99 ( L_282 ) ;
F_108 ( L_283 , F_78 , V_173 ) ;
}
static void F_51 ( V_170 * V_327 )
{
if( V_327 == NULL ) {
return;
}
V_327 -> V_130 = NULL ;
V_327 -> V_132 = NULL ;
V_327 -> V_53 = 0xFF ;
V_327 -> V_178 = - 1 ;
}
