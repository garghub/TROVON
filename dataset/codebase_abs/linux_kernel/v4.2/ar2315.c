static inline T_1 F_1 ( T_1 V_1 )
{
return F_2 ( V_2 + V_1 ) ;
}
static inline void F_3 ( T_1 V_1 , T_1 V_3 )
{
F_4 ( V_3 , V_2 + V_1 ) ;
}
static inline void F_5 ( T_1 V_1 , T_1 V_4 , T_1 V_3 )
{
T_1 V_5 = F_1 ( V_1 ) ;
V_5 &= ~ V_4 ;
V_5 |= V_3 ;
F_3 ( V_1 , V_5 ) ;
}
static T_2 F_6 ( int V_6 , void * V_7 )
{
F_3 ( V_8 , V_9 ) ;
F_1 ( V_10 ) ;
F_7 ( L_1 ) ;
F_8 ( L_2 ) ;
return V_11 ;
}
static void F_9 ( unsigned V_12 , struct V_13 * V_14 )
{
T_1 V_15 = F_1 ( V_16 ) &
F_1 ( V_17 ) ;
unsigned V_18 , V_19 = 0 ;
if ( V_15 ) {
struct V_20 * V_21 = F_10 ( V_14 ) ;
V_18 = F_11 ( V_15 ) ;
V_19 = F_12 ( V_21 , V_18 ) ;
}
if ( V_19 ) {
if ( V_18 == V_22 )
F_3 ( V_16 , V_23 ) ;
else if ( V_18 == V_24 )
F_3 ( V_16 , V_25 ) ;
F_13 ( V_19 ) ;
} else {
F_14 () ;
}
}
static void F_15 ( struct V_26 * V_27 )
{
F_5 ( V_17 , 0 , F_16 ( V_27 -> V_28 ) ) ;
}
static void F_17 ( struct V_26 * V_27 )
{
F_5 ( V_17 , F_16 ( V_27 -> V_28 ) , 0 ) ;
}
static int F_18 ( struct V_20 * V_27 , unsigned V_12 ,
T_3 V_29 )
{
F_19 ( V_12 , & V_30 , V_31 ) ;
return 0 ;
}
static void F_20 ( void )
{
T_1 V_15 = F_21 () & F_22 () ;
if ( V_15 & V_32 )
F_23 ( V_33 ) ;
#ifdef F_24
else if ( V_15 & V_34 )
F_23 ( V_35 ) ;
#endif
else if ( V_15 & V_36 )
F_23 ( V_37 ) ;
else if ( V_15 & V_38 )
F_23 ( V_39 ) ;
else
F_14 () ;
}
void T_4 F_25 ( void )
{
struct V_20 * V_21 ;
unsigned V_12 ;
V_40 = F_20 ;
V_21 = F_26 ( NULL , V_41 ,
& V_42 , NULL ) ;
if ( ! V_21 )
F_27 ( L_3 ) ;
V_12 = F_28 ( V_21 , V_43 ) ;
F_29 ( V_12 , & V_44 ) ;
F_30 ( V_37 ,
F_9 , V_21 ) ;
V_45 = V_21 ;
}
void T_4 F_31 ( void )
{
F_32 ( V_46 , V_47 ) ;
F_33 ( 0 , V_48 , V_33 ) ;
}
static void F_34 ( char * V_49 )
{
void (* F_35)( void ) = ( void * ) 0xbfc00000 ;
F_36 () ;
F_3 ( V_50 , V_51 ) ;
F_35 () ;
}
static unsigned T_4 F_37 ( T_1 V_52 )
{
unsigned int V_53 , V_54 ;
unsigned int V_55 , V_56 , V_57 , V_58 ;
unsigned int V_59 ;
V_53 = F_1 ( V_60 ) ;
V_56 = F_38 ( V_53 , V_61 ) ;
V_56 = V_62 [ V_56 ] ;
V_57 = F_38 ( V_53 , V_63 ) ;
V_58 = F_38 ( V_53 , V_64 ) + 1 ;
V_55 = ( 40000000 / V_56 ) * ( 2 * V_58 ) * V_57 ;
switch ( V_52 & V_65 ) {
case 0 :
case 1 :
V_59 = F_38 ( V_53 , V_66 ) ;
V_59 = V_67 [ V_59 ] ;
break;
case 2 :
V_59 = F_38 ( V_53 , V_68 ) ;
V_59 = V_67 [ V_59 ] ;
break;
default:
V_55 = 40000000 ;
V_59 = 1 ;
break;
}
V_54 = F_38 ( V_52 , V_69 ) ;
V_54 = V_54 * 2 ? : 1 ;
return V_55 / ( V_59 * V_54 ) ;
}
static inline unsigned F_39 ( void )
{
return F_37 ( F_1 ( V_70 ) ) ;
}
static inline unsigned F_40 ( void )
{
return F_37 ( F_1 ( V_71 ) ) ;
}
void T_4 F_41 ( void )
{
V_72 = F_39 () / 2 ;
}
void T_4 F_42 ( void )
{
void T_5 * V_73 ;
T_1 V_74 , V_75 ;
T_1 V_76 ;
T_1 V_77 ;
V_73 = F_43 ( V_78 ,
V_79 ) ;
V_75 = F_2 ( V_73 + V_80 ) ;
V_74 = 1 + F_38 ( V_75 , V_81 ) ;
V_74 <<= 1 + F_38 ( V_75 , V_82 ) ;
V_74 <<= 1 + F_38 ( V_75 , V_83 ) ;
V_74 <<= 3 ;
F_44 ( 0 , V_74 , V_84 ) ;
F_45 ( V_73 ) ;
V_2 = F_43 ( V_85 , V_86 ) ;
V_76 = F_1 ( V_87 ) & V_88 ;
switch ( V_76 ) {
case 0x91 :
V_89 = V_90 ;
break;
case 0x90 :
V_89 = V_91 ;
break;
case 0x87 :
V_89 = V_92 ;
break;
case 0x86 :
default:
V_89 = V_93 ;
break;
}
V_94 . V_76 = V_76 ;
V_77 = F_46 () ;
F_47 ( V_77 & ~ 0x3 ) ;
F_3 ( V_8 , V_9 ) ;
F_1 ( V_10 ) ;
F_3 ( V_95 , V_96 ) ;
V_97 = F_34 ;
}
void T_4 F_48 ( void )
{
unsigned V_12 = F_28 ( V_45 ,
V_98 ) ;
F_49 ( V_99 , V_12 , F_40 () ) ;
#ifdef F_24
if ( V_89 == V_93 ) {
F_5 ( V_100 , 0 , V_101 ) ;
F_50 ( 20 ) ;
F_5 ( V_100 , V_101 , 0 ) ;
F_50 ( 20 ) ;
F_5 ( V_102 , 0 , V_103 |
V_104 ) ;
F_3 ( V_105 , V_106 |
( V_107 <<
V_108 ) ) ;
F_5 ( V_109 , 0 , V_110 ) ;
F_5 ( V_111 , V_112 |
V_113 , V_114 |
V_115 | V_116 |
( V_117 <<
V_118 ) ) ;
F_51 ( L_4 , - 1 ,
V_119 ,
F_52 ( V_119 ) ) ;
}
#endif
}
