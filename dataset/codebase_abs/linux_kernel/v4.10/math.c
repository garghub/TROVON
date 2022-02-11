int F_1 ( void )
{
V_1 = V_2 ;
V_3 = V_4 ;
V_2 = V_5 ;
V_4 = V_6 ;
return 0 ;
}
void F_2 ( void )
{
V_2 = V_1 ;
V_4 = V_3 ;
}
long
V_4 ( unsigned long V_7 )
{
V_8 ;
F_3 ( V_9 ) ; F_3 ( V_10 ) ; F_3 ( V_11 ) ;
F_4 ( V_12 ) ; F_4 ( V_13 ) ; F_4 ( V_14 ) ;
unsigned long V_15 , V_16 , V_17 , V_18 , V_19 , V_20 ;
unsigned long V_21 , V_22 , V_23 , V_24 , V_25 , V_26 ;
T_1 V_27 ;
long V_28 ;
F_5 ( V_27 , ( T_1 V_29 * ) V_7 ) ;
V_17 = ( V_27 >> 0 ) & 0x1f ;
V_16 = ( V_27 >> 16 ) & 0x1f ;
V_15 = ( V_27 >> 21 ) & 0x1f ;
V_18 = ( V_27 >> 5 ) & 0xf ;
V_20 = ( V_27 >> 9 ) & 0x3 ;
V_19 = ( V_27 >> 11 ) & 0x3 ;
V_26 = F_6 () ;
V_25 = F_7 ( F_8 () -> V_30 , V_26 ) ;
if ( V_19 == 3 ) {
V_19 = ( V_26 >> V_31 ) & 3 ;
}
switch ( V_20 ) {
case V_32 :
V_22 = F_9 ( V_15 ) ;
V_23 = F_9 ( V_16 ) ;
F_10 ( V_9 , & V_22 ) ;
F_10 ( V_10 , & V_23 ) ;
switch ( V_18 ) {
case V_33 :
F_11 ( V_11 , V_9 , V_10 ) ;
goto V_34;
case V_35 :
F_12 ( V_11 , V_9 , V_10 ) ;
goto V_34;
case V_36 :
F_13 ( V_11 , V_9 , V_10 ) ;
goto V_34;
case V_37 :
F_14 ( V_11 , V_9 , V_10 ) ;
goto V_34;
case V_38 :
F_15 ( V_11 , V_10 ) ;
goto V_34;
}
goto V_39;
case V_40 :
V_22 = F_16 ( V_15 ) ;
V_23 = F_16 ( V_16 ) ;
if ( ( V_18 & ~ 3 ) == V_41 ) {
F_17 ( V_12 , & V_22 ) ;
F_17 ( V_13 , & V_23 ) ;
if ( ! V_42 && ! F_18 ( V_12 ) ) {
F_19 ( V_43 ) ;
if ( V_44 )
F_20 ( V_12 , V_45 ) ;
}
if ( ! V_46 && ! F_18 ( V_13 ) ) {
F_19 ( V_43 ) ;
if ( V_44 )
F_20 ( V_13 , V_45 ) ;
}
F_21 ( V_21 , V_12 , V_13 , 3 ) ;
V_24 = 0x4000000000000000UL ;
if ( V_21 == 3
&& ( ( V_18 & 3 ) >= 2
|| F_22 ( V_12 )
|| F_22 ( V_13 ) ) ) {
F_19 ( V_47 ) ;
}
switch ( V_18 ) {
case V_41 : if ( V_21 != 3 ) V_24 = 0 ; break;
case V_48 : if ( V_21 ) V_24 = 0 ; break;
case V_49 : if ( V_21 != - 1 ) V_24 = 0 ; break;
case V_50 : if ( ( long ) V_21 > 0 ) V_24 = 0 ; break;
}
goto V_51;
}
F_23 ( V_12 , & V_22 ) ;
F_23 ( V_13 , & V_23 ) ;
switch ( V_18 ) {
case V_33 :
F_24 ( V_14 , V_12 , V_13 ) ;
goto V_52;
case V_35 :
F_25 ( V_14 , V_12 , V_13 ) ;
goto V_52;
case V_36 :
F_26 ( V_14 , V_12 , V_13 ) ;
goto V_52;
case V_37 :
F_27 ( V_14 , V_12 , V_13 ) ;
goto V_52;
case V_38 :
F_28 ( V_14 , V_13 ) ;
goto V_52;
case V_53 :
if ( V_27 & 0x2000 ) {
F_29 ( V_54 , V_55 , 1 , 1 , V_11 , V_13 ) ;
goto V_34;
} else {
V_23 = F_9 ( V_16 ) ;
F_10 ( V_10 , & V_23 ) ;
V_56 = V_57 ;
V_58 = V_59 ;
V_60 = V_46 + ( 1024 - 128 ) ;
V_61 = V_62 << ( 52 - 23 ) ;
goto V_52;
}
case V_63 :
if ( V_57 == V_64
&& ( F_30 ( V_13 ) & V_65 ) ) {
V_24 = 0 ;
} else
F_31 ( V_24 , V_13 , 64 , 2 ) ;
goto V_51;
}
goto V_39;
case V_66 :
V_23 = F_16 ( V_16 ) ;
switch ( V_18 ) {
case V_67 :
V_24 = ( ( V_23 & 0xc0000000 ) << 32 |
( V_23 & 0x3fffffff ) << 29 ) ;
F_19 ( V_47 ) ;
goto V_51;
case V_53 :
F_32 ( V_11 , ( ( long ) V_23 ) , 64 , long ) ;
goto V_34;
case V_68 :
F_33 ( V_14 , ( ( long ) V_23 ) , 64 , long ) ;
goto V_52;
}
goto V_39;
}
goto V_39;
V_34:
F_34 ( & V_24 , V_11 ) ;
if ( ( V_69 & V_70 ) && ( V_25 & V_71 ) )
V_24 = 0 ;
F_35 ( V_17 , V_24 ) ;
goto V_72;
V_52:
F_36 ( & V_24 , V_14 ) ;
if ( ( V_69 & V_70 ) && ( V_25 & V_71 ) )
V_24 = 0 ;
V_51:
F_37 ( V_17 , V_24 ) ;
goto V_72;
V_72:
if ( V_69 ) {
V_25 |= ( V_69 << V_73 ) ;
F_8 () -> V_30
|= ( V_69 << V_73 ) ;
V_26 &= ( ~ V_74 | V_75 ) ;
V_26 |= F_38 ( V_25 ) ;
F_39 ( V_26 ) ;
V_69 = V_69 & V_25 & V_76 ;
V_28 = 0 ;
if ( V_69 ) {
if ( V_69 & V_77 ) V_28 = V_78 ;
if ( V_69 & V_79 ) V_28 = V_80 ;
if ( V_69 & V_81 ) V_28 = V_78 ;
if ( V_69 & V_82 ) V_28 = V_83 ;
if ( V_69 & V_84 ) V_28 = V_85 ;
if ( V_69 & V_86 ) V_28 = V_87 ;
}
return V_28 ;
}
return 0 ;
V_39:
F_40 ( V_88 L_1 ,
V_27 , V_7 ) ;
return - 1 ;
}
long
V_2 ( struct V_89 * V_90 , unsigned long V_91 )
{
unsigned long V_92 = V_90 -> V_7 - 4 ;
unsigned long V_27 , V_93 , V_94 , V_28 = 0 ;
while ( V_91 ) {
F_5 ( V_27 , ( T_1 V_29 * ) ( V_92 ) ) ;
V_93 = V_27 >> 26 ;
V_94 = V_27 & 0x1f ;
switch ( V_93 ) {
case V_95 :
case V_96 :
case 0x30 ... 0x3f :
goto V_97;
case V_98 :
switch ( V_27 & 0xffff ) {
case V_99 :
case V_100 :
goto V_97;
default:
break;
}
break;
case V_101 :
case V_102 :
case V_103 :
case V_104 :
V_91 &= ~ ( 1UL << V_94 ) ;
break;
case V_105 :
case V_106 :
case V_107 :
case V_108 :
V_91 &= ~ ( 1UL << ( V_94 + 32 ) ) ;
break;
}
if ( ! V_91 ) {
V_90 -> V_7 = V_92 + 4 ;
V_28 = V_4 ( V_92 ) ;
goto V_97;
}
V_92 -= 4 ;
}
V_97:
return V_28 ;
}
