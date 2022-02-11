void T_1 F_1 ( void )
{
T_2 V_1 ;
int V_2 ;
switch ( V_3 -> V_4 ) {
case V_5 :
V_3 -> V_6 = V_7 ;
break;
#ifdef F_2
case V_8 :
V_3 -> V_6 = F_2 ;
break;
#endif
default:
F_3 () ;
}
F_4 ( 115200 ) ;
F_5 ( V_3 -> V_9 ,
F_6 ( V_10 ) ) ;
F_5 ( V_3 -> V_11 ,
F_6 ( V_10 ) ) ;
F_7 ( F_8 ( V_10 ) ,
V_12 ) ;
* V_3 -> V_13 |= V_14 ;
V_2 = * V_3 -> V_13 ;
V_1 = V_15 ;
switch ( V_3 -> V_16 ) {
case V_17 :
V_1 |= V_18 ;
break;
case V_19 :
V_1 |= V_20 ;
break;
}
V_1 |= V_21 | V_22 ;
* V_3 -> V_23 = V_1 ;
V_2 = * V_3 -> V_23 ;
F_9 (
F_10 ( V_10 + 1 ) ) ;
}
void F_4 ( unsigned V_24 )
{
const unsigned V_25 = 10 ;
unsigned long V_6 = V_3 -> V_6 ;
unsigned V_26 , V_2 ;
T_2 V_27 ;
T_3 V_28 ;
if ( ! V_24 ) {
V_24 = 9600 ;
} else if ( V_24 == 134 ) {
V_24 = 269 ;
V_26 = 2 ;
}
V_29:
V_26 = 1 ;
switch ( V_3 -> V_16 ) {
case V_17 :
V_28 = V_30 ;
V_27 = V_2 = ( V_6 / ( V_24 * V_26 ) + 4 ) / 8 - 1 ;
if ( V_2 > 0 && V_2 <= 65535 )
goto V_31;
V_28 = V_32 ;
V_27 = V_2 = ( V_6 / ( V_24 * 8 * V_26 ) + 4 ) / 8 - 1 ;
if ( V_2 > 0 && V_2 <= 65535 )
goto V_31;
V_28 = V_33 ;
V_27 = V_2 = ( V_6 / ( V_24 * 32 * V_26 ) + 4 ) / 8 - 1 ;
if ( V_2 > 0 && V_2 <= 65535 )
goto V_31;
break;
case V_19 :
V_28 = V_34 ;
V_27 = V_2 = ( V_6 / ( V_24 * V_26 ) + 4 ) / 8 - 1 ;
if ( V_2 > 0 && V_2 <= 255 )
goto V_31;
V_28 = V_35 ;
V_27 = V_2 = ( V_6 / ( V_24 * 8 * V_26 ) + 4 ) / 8 - 1 ;
if ( V_2 > 0 && V_2 <= 255 )
goto V_31;
V_28 = V_36 ;
V_27 = V_2 = ( V_6 / ( V_24 * 32 * V_26 ) + 4 ) / 8 - 1 ;
if ( V_2 > 0 && V_2 <= 255 )
goto V_31;
break;
}
V_24 = 9600 ;
goto V_29;
V_31:
V_3 -> V_37 . V_38 = ( 2 * V_25 * V_39 ) / V_24 ;
V_3 -> V_37 . V_38 += V_39 / 50 ;
switch ( V_3 -> V_16 ) {
case V_17 :
* V_3 -> V_40 = 0 ;
* V_3 -> V_41 = V_27 ;
* V_3 -> V_40 = V_42 ;
* V_3 -> V_40 = V_28 | V_43 ;
break;
case V_19 :
* V_3 -> V_40 = 0 ;
* ( volatile V_44 * ) V_3 -> V_41 = ( V_44 ) V_27 ;
* V_3 -> V_40 = V_45 ;
* V_3 -> V_40 = V_28 | V_46 ;
break;
}
}
int F_11 ( unsigned char * V_47 , int V_48 )
{
unsigned V_49 ;
V_44 V_50 , V_51 ;
#if F_12 ( V_52 )
int V_53 ;
#endif
* V_47 = 0xff ;
if ( V_54 ) {
* V_47 = V_54 ;
V_54 = 0 ;
return 0 ;
}
V_55:
V_49 = V_56 ;
F_13 () ;
if ( V_49 == V_57 ) {
if ( V_48 )
return - V_58 ;
#ifdef V_52
for ( V_53 = 0 ; V_53 < V_59 ; V_53 ++ )
V_60 [ V_53 ] = 0 ;
#endif
goto V_55;
}
V_50 = V_61 [ V_49 ++ ] ;
V_51 = V_61 [ V_49 ++ ] ;
F_13 () ;
V_56 = V_49 & ( V_62 - 1 ) ;
V_51 &= V_63 | V_64 | V_65 | V_66 |
V_67 ;
if ( V_51 & V_65 && V_50 == 0 ) {
switch ( V_3 -> V_68 ) {
case 0 : V_3 -> V_68 = 1 ; goto V_55;
case 1 : V_3 -> V_68 = 2 ; goto V_55;
case 2 :
V_3 -> V_68 = 3 ;
F_14 ( L_1
L_2 ) ;
return - V_69 ;
default:
goto V_55;
}
} else if ( V_51 & V_65 ) {
if ( V_3 -> V_68 )
goto V_55;
F_14 ( L_3 ) ;
return - V_70 ;
} else if ( V_51 & V_67 ) {
if ( V_3 -> V_68 )
goto V_55;
F_14 ( L_4 ) ;
return - V_70 ;
} else if ( V_51 & V_66 ) {
if ( V_3 -> V_68 )
goto V_55;
F_14 ( L_5 ) ;
return - V_70 ;
} else {
if ( V_3 -> V_68 == 3 ) {
switch ( V_50 ) {
case 0xFF :
case 0xFE :
case 0xFC :
case 0xF8 :
case 0xF0 :
case 0xE0 :
case 0xC0 :
case 0x80 :
case 0x00 :
V_3 -> V_68 = 0 ;
goto V_55;
default:
break;
}
}
V_3 -> V_68 = 0 ;
F_15 ( L_6 , V_50 , V_51 ) ;
* V_47 = V_50 & 0x7f ;
return 0 ;
}
}
void F_16 ( unsigned char V_50 )
{
while ( * V_3 -> V_71 & V_72 )
continue;
if ( V_50 == 0x0a ) {
* ( V_44 * ) V_3 -> V_73 = 0x0d ;
while ( * V_3 -> V_71 & V_72 )
continue;
}
* ( V_44 * ) V_3 -> V_73 = V_50 ;
}
void F_17 ( void )
{
while ( * V_3 -> V_71 & ( V_72 | V_74 ) )
continue;
}
