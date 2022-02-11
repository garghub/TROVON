static void F_1 ( T_1 V_1 , T_2 V_2 )
{
int V_3 = ~ 0 ;
int V_4 [ 4 ] = { ( V_2 >> 12 ) & 0xf , ( V_2 >> 8 ) & 0xf , ( V_2 >> 4 ) & 0xf , V_2 & 0xf } ;
int V_5 ;
struct V_6 * V_7 = V_8 ;
for (; V_7 -> V_9 ; V_7 ++ ) {
int V_10 ;
int V_11 = 0 ;
int V_12 = 0 ;
int V_13 = 0 ;
int V_14 = 0 ;
int V_15 ;
int V_16 = 0 ;
for ( V_10 = 0 ; V_10 < 4 ; V_10 ++ ) {
int V_17 = V_7 -> V_18 [ V_10 ] ;
if ( V_17 < 16 ) {
if ( V_4 [ V_10 ] == V_17 )
continue;
goto V_19;
}
switch ( V_17 ) {
case V_20 :
V_11 = ( V_4 [ 2 ] << 4 ) | ( V_4 [ 3 ] ) ;
if ( V_11 & 0x80 )
V_11 |= ~ 0xff ;
V_11 = ( ( char ) V_11 ) * 2 + 4 ;
goto V_21;
case V_22 :
V_11 = ( ( V_4 [ 1 ] ) << 8 ) | ( V_4 [ 2 ] << 4 ) | ( V_4 [ 3 ] ) ;
if ( V_11 & 0x800 )
V_11 |= ~ 0xfff ;
V_11 = V_11 * 2 + 4 ;
goto V_21;
case V_23 :
V_11 = V_4 [ 3 ] ;
goto V_21;
case V_24 :
V_11 = V_4 [ 3 ] << 1 ;
goto V_21;
case V_25 :
V_11 = V_4 [ 3 ] << 2 ;
goto V_21;
case V_26 :
V_11 = ( V_4 [ 2 ] << 4 ) | V_4 [ 3 ] ;
goto V_21;
case V_27 :
V_11 = ( ( V_4 [ 2 ] << 4 ) | V_4 [ 3 ] ) << 1 ;
V_3 = ~ 1 ;
goto V_21;
case V_28 :
V_11 = ( ( V_4 [ 2 ] << 4 ) | V_4 [ 3 ] ) << 2 ;
V_3 = ~ 3 ;
goto V_21;
case V_29 :
V_11 = ( ( V_4 [ 2 ] << 4 ) | V_4 [ 3 ] ) << 1 ;
goto V_21;
case V_30 :
V_11 = ( ( V_4 [ 2 ] << 4 ) | V_4 [ 3 ] ) << 2 ;
goto V_21;
case V_31 :
V_11 = ( V_4 [ 2 ] << 4 ) | ( V_4 [ 3 ] ) ;
goto V_21;
case V_32 :
V_11 = V_4 [ 3 ] ;
goto V_21;
case V_33 :
V_12 = V_4 [ V_10 ] ;
break;
case V_34 :
V_13 = V_4 [ V_10 ] ;
break;
case V_35 :
V_12 = ( V_4 [ V_10 ] & 0xc ) >> 2 ;
V_13 = ( V_4 [ V_10 ] & 0x3 ) ;
break;
case V_36 :
V_14 = V_4 [ V_10 ] & 0x07 ;
break;
default:
return;
}
}
V_21:
F_2 ( L_1 , V_7 -> V_9 ) ;
V_5 = ( V_7 -> V_37 [ 0 ] == V_38 ) ;
V_15 = 0 ;
for ( V_10 = 0 ; V_10 < 6 && V_7 -> V_37 [ V_10 ] != V_38 ; V_10 ++ ) {
if ( V_10 && V_7 -> V_37 [ 1 ] != V_38 )
F_2 ( L_2 ) ;
switch ( V_7 -> V_37 [ V_10 ] ) {
case V_39 :
F_2 ( L_3 , ( char ) ( V_11 ) ) ;
break;
case V_40 :
F_2 ( L_4 ) ;
break;
case V_41 :
F_2 ( L_5 , V_12 ) ;
break;
case V_42 :
F_2 ( L_6 , V_12 ) ;
break;
case V_43 :
F_2 ( L_7 , V_12 ) ;
break;
case V_44 :
F_2 ( L_8 , V_12 ) ;
break;
case V_45 :
F_2 ( L_9 , V_11 , V_12 ) ;
break;
case V_46 :
F_2 ( L_5 , V_13 ) ;
break;
case V_47 :
F_2 ( L_6 , V_13 ) ;
break;
case V_48 :
F_2 ( L_7 , V_13 ) ;
break;
case V_49 :
F_2 ( L_8 , V_13 ) ;
break;
case V_50 :
F_2 ( L_9 , V_11 , V_13 ) ;
break;
case V_51 :
F_2 ( L_10 , V_14 ) ;
break;
case V_52 :
V_15 = 1 ;
V_16 = V_11 + 4 + ( V_1 & V_3 ) ;
F_2 ( L_11 , V_16 ,
( void * ) V_16 ) ;
break;
case V_53 :
F_2 ( L_12 , V_12 ) ;
break;
case V_54 :
F_2 ( L_12 , V_13 ) ;
break;
case V_55 :
F_2 ( L_13 , V_11 ) ;
break;
case V_56 :
F_2 ( L_14 ) ;
break;
case V_57 :
case V_58 :
F_2 ( L_15 , V_11 + V_1 ) ;
break;
case V_59 :
F_2 ( L_16 ) ;
break;
case V_60 :
F_2 ( L_17 ) ;
break;
case V_61 :
F_2 ( L_18 ) ;
break;
case V_62 :
F_2 ( L_19 ) ;
break;
case V_63 :
F_2 ( L_20 ) ;
break;
case V_64 :
F_2 ( L_21 ) ;
break;
case V_65 :
F_2 ( L_22 ) ;
break;
case V_66 :
F_2 ( L_23 ) ;
break;
case V_67 :
F_2 ( L_24 ) ;
break;
case V_68 :
F_2 ( L_25 ) ;
break;
case V_69 :
if ( 0 )
goto V_70;
case V_71 :
F_2 ( L_26 , V_12 ) ;
break;
case V_72 :
F_2 ( L_26 , V_13 ) ;
break;
case V_73 :
if ( V_12 & 1 ) {
F_2 ( L_27 , V_12 & ~ 1 ) ;
break;
}
V_70:
case V_74 :
F_2 ( L_28 , V_12 ) ;
break;
case V_75 :
if ( V_13 & 1 ) {
F_2 ( L_27 , V_13 & ~ 1 ) ;
break;
}
case V_76 :
F_2 ( L_28 , V_13 ) ;
break;
case V_77 :
case V_78 :
F_2 ( L_29 ) ;
break;
case V_79 :
case V_80 :
F_2 ( L_30 ) ;
break;
case V_81 :
F_2 ( L_31 ) ;
break;
case V_82 :
F_2 ( L_32 , V_12 * 4 ) ;
break;
case V_83 :
F_2 ( L_32 , V_13 * 4 ) ;
break;
case V_84 :
F_2 ( L_33 ) ;
break;
default:
return;
}
}
if ( V_15 && strcmp ( V_7 -> V_9 , L_34 ) != 0 ) {
T_1 V_85 ;
if ( V_3 == ~ 1 )
F_3 ( V_85 , ( T_2 * ) V_16 ) ;
else
F_3 ( V_85 , ( T_1 * ) V_16 ) ;
F_2 ( L_35 , V_85 , ( void * ) V_85 ) ;
}
return;
V_19:
;
}
F_2 ( L_36 , V_4 [ 0 ] , V_4 [ 1 ] , V_4 [ 2 ] , V_4 [ 3 ] ) ;
}
void F_4 ( struct V_86 * V_87 )
{
unsigned short * V_88 = ( unsigned short * ) V_87 -> V_88 ;
long V_17 ;
if ( V_87 -> V_88 & 0x1 )
return;
F_2 ( L_37 ) ;
for ( V_17 = - 3 ; V_17 < 6 ; V_17 ++ ) {
unsigned short V_2 ;
if ( F_3 ( V_2 , V_88 + V_17 ) ) {
F_2 ( L_38 ) ;
break;
}
F_2 ( L_39 , ( V_17 ? L_40 : L_41 ) , ( unsigned long ) ( V_88 + V_17 ) ) ;
F_1 ( ( unsigned long ) ( V_88 + V_17 ) , V_2 ) ;
F_2 ( L_42 ) ;
}
F_2 ( L_42 ) ;
}
