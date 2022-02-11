static T_1 F_1 ( int V_1 )
{
if ( V_2 )
V_1 <<= V_3 ;
return F_2 ( V_4 + V_1 ) ;
}
static void F_3 ( int V_1 , T_1 V_5 )
{
if ( V_2 )
V_1 <<= V_3 ;
F_4 ( V_5 , V_4 + V_1 ) ;
}
static void F_5 ( void )
{
if ( V_6 )
F_3 ( V_7 , V_8 [ type ] . V_9 ) ;
else
F_3 ( V_7 , V_8 [ type ] . F_5 ) ;
}
static void V_9 ( void )
{
if ( V_6 )
F_3 ( V_7 , V_8 [ type ] . F_5 ) ;
else
F_3 ( V_7 , V_8 [ type ] . V_9 ) ;
}
static void F_6 ( unsigned int V_10 ,
unsigned int V_11 )
{
V_12 . V_13 = V_10 ;
V_12 . V_14 = V_11 ;
V_12 . V_15 = F_7 (
V_10 * V_16 , V_11 * 100l ) ;
V_12 . V_17 = F_7 (
( 100l - V_10 ) * V_16 , V_11 * 100l ) ;
}
static void F_8 ( unsigned int V_18 , T_2 V_19 )
{
long V_20 ;
int V_21 ;
unsigned char V_22 ;
unsigned char V_23 , V_24 ;
V_20 = V_18 * 1152 / 10000 ;
if ( V_12 . V_13 > 50 )
V_23 = 3 ;
else
V_23 = 1 ;
for ( V_21 = 0 , V_22 = 0x7f ; V_20 > 0 ; V_20 -= 3 ) {
V_24 = V_23 << ( V_21 * 3 ) ;
V_24 >>= 1 ;
V_22 &= ( ~ V_24 ) ;
V_21 ++ ;
if ( V_21 == 3 ) {
F_3 ( V_25 , V_22 ) ;
while ( ! ( F_1 ( V_26 ) & V_27 ) )
;
V_22 = 0x7f ;
V_21 = 0 ;
}
}
if ( V_21 != 0 ) {
F_3 ( V_25 , V_22 ) ;
while ( ! ( F_1 ( V_26 ) & V_28 ) )
;
}
}
static void F_9 ( void )
{
}
static void F_10 ( unsigned int V_18 , T_2 V_29 )
{
T_2 V_30 , V_19 = F_11 ( V_29 , V_18 ) ;
T_3 V_31 ;
for (; ; ) {
V_30 = F_12 () ;
if ( F_13 ( V_30 , V_19 ) >= 0 )
break;
F_5 () ;
V_29 = F_14 ( V_29 , V_12 . V_15 ) ;
V_31 = F_15 ( F_16 ( V_29 , V_30 ) ) ;
if ( V_31 > 0 )
F_17 ( V_31 ) ;
V_30 = F_12 () ;
V_9 () ;
if ( F_13 ( V_30 , V_19 ) >= 0 )
break;
V_29 = F_14 ( V_29 , V_12 . V_17 ) ;
V_31 = F_15 ( F_16 ( V_29 , V_30 ) ) ;
if ( V_31 > 0 )
F_17 ( V_31 ) ;
}
}
static void F_18 ( unsigned int V_18 , T_2 V_29 )
{
if ( V_32 )
F_10 ( V_18 , V_29 ) ;
else
F_5 () ;
}
static void F_19 ( void )
{
V_9 () ;
}
static void F_20 ( unsigned int V_33 , bool V_34 )
{
static unsigned int V_35 , V_36 , V_37 ;
F_21 ( V_38 ) ;
if ( V_35 > 0 && V_34 ) {
V_36 += V_33 ;
if ( V_36 > 250000 ) {
V_38 . V_39 = V_37 ;
V_38 . V_36 = false ;
F_22 ( V_12 . V_40 , & V_38 ) ;
V_38 . V_39 = V_36 ;
V_38 . V_36 = true ;
F_22 ( V_12 . V_40 , & V_38 ) ;
V_35 = 0 ;
V_36 = 0 ;
}
return;
}
if ( ! V_34 ) {
if ( V_35 == 0 ) {
if ( V_33 > 20000000 ) {
V_37 = V_33 ;
V_35 ++ ;
return;
}
} else {
if ( V_33 > 20000000 ) {
V_37 += V_36 ;
if ( V_37 > V_41 )
V_37 = V_41 ;
V_37 += V_33 ;
if ( V_37 > V_41 )
V_37 = V_41 ;
V_36 = 0 ;
return;
}
V_38 . V_39 = V_37 ;
V_38 . V_36 = false ;
F_22 ( V_12 . V_40 , & V_38 ) ;
V_38 . V_39 = V_36 ;
V_38 . V_36 = true ;
F_22 ( V_12 . V_40 , & V_38 ) ;
V_35 = 0 ;
V_36 = 0 ;
}
}
V_38 . V_39 = V_33 ;
V_38 . V_36 = V_34 ;
F_22 ( V_12 . V_40 , & V_38 ) ;
}
static T_4 F_23 ( int V_21 , void * V_42 )
{
T_2 V_43 ;
int V_44 , V_45 ;
T_1 V_46 ;
T_2 V_47 ;
unsigned int V_48 ;
static int V_49 = - 1 ;
if ( ( F_1 ( V_50 ) & V_51 ) ) {
return V_52 ;
}
V_44 = 0 ;
do {
V_44 ++ ;
V_46 = F_1 ( V_53 ) ;
if ( V_44 > V_54 ) {
F_24 ( & V_12 . V_55 -> V_56 , L_1 ) ;
break;
}
if ( ( V_46 & V_8 [ type ] . V_57 ) &&
V_58 != - 1 ) {
V_43 = F_12 () ;
V_45 = ( V_46 & V_8 [ type ] . V_59 ) ? 1 : 0 ;
if ( V_45 == V_49 ) {
F_24 ( & V_12 . V_55 -> V_56 ,
L_2 ,
V_45 , V_58 , F_15 ( V_43 ) ,
F_15 ( V_12 . V_60 ) ) ;
continue;
}
V_47 = F_16 ( V_43 , V_12 . V_60 ) ;
if ( F_13 ( V_47 , F_25 ( 15 , 0 ) ) > 0 ) {
V_48 = V_41 ;
if ( ! ( V_45 ^ V_58 ) ) {
F_24 ( & V_12 . V_55 -> V_56 ,
L_3 ,
V_45 , V_58 , F_15 ( V_43 ) ,
F_15 ( V_12 . V_60 ) ) ;
V_58 = V_58 ? 0 : 1 ;
}
} else {
V_48 = F_15 ( V_47 ) ;
}
F_20 ( V_48 , ! ( V_45 ^ V_58 ) ) ;
V_12 . V_60 = V_43 ;
V_49 = V_45 ;
F_26 ( V_12 . V_40 ) ;
}
} while ( ! ( F_1 ( V_50 ) & V_51 ) );
return V_61 ;
}
static int F_27 ( void )
{
T_1 V_62 , V_63 , V_64 ;
V_62 = F_1 ( V_65 ) ;
F_3 ( V_65 , 0 ) ;
#ifdef F_28
F_4 ( 0xff , 0x080 ) ;
#endif
V_63 = F_1 ( V_65 ) & 0x0f ;
F_3 ( V_65 , 0x0f ) ;
#ifdef F_28
F_4 ( 0x00 , 0x080 ) ;
#endif
V_64 = F_1 ( V_65 ) & 0x0f ;
F_3 ( V_65 , V_62 ) ;
if ( V_63 != 0 || V_64 != 0x0f ) {
F_29 ( L_4 ) ;
return - V_66 ;
}
F_3 ( V_67 , F_1 ( V_67 ) & ( ~ V_68 ) ) ;
F_3 ( V_65 , F_1 ( V_65 ) &
( ~ ( V_69 | V_70 | V_71 | V_72 ) ) ) ;
F_1 ( V_26 ) ;
F_1 ( V_73 ) ;
F_1 ( V_50 ) ;
F_1 ( V_53 ) ;
V_9 () ;
F_1 ( V_26 ) ;
F_1 ( V_73 ) ;
F_1 ( V_50 ) ;
F_1 ( V_53 ) ;
switch ( type ) {
case V_74 :
case V_75 :
F_3 ( V_67 , F_1 ( V_67 ) | V_68 ) ;
F_3 ( V_76 , 0 ) ;
F_3 ( V_77 , 1 ) ;
F_3 ( V_67 , V_78 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_30 ( struct V_79 * V_56 )
{
int V_21 , V_80 , V_81 , V_82 ;
V_82 = F_31 ( & V_56 -> V_56 , V_83 , F_23 ,
V_84 ? V_85 : 0 ,
V_86 , & V_8 ) ;
if ( V_82 < 0 ) {
if ( V_82 == - V_87 )
F_24 ( & V_56 -> V_56 , L_5 , V_83 ) ;
else if ( V_82 == - V_88 )
F_24 ( & V_56 -> V_56 , L_6 ) ;
return V_82 ;
}
if ( ( V_2 &&
( F_32 ( & V_56 -> V_56 , V_2 , 8 << V_3 ,
V_86 ) == NULL ) ) ||
( ! V_2 && ( F_33 ( & V_56 -> V_56 , V_4 , 8 ,
V_86 ) == NULL ) ) ) {
F_24 ( & V_56 -> V_56 , L_7 , V_4 ) ;
F_34 ( & V_56 -> V_56 , L_8 ) ;
F_34 ( & V_56 -> V_56 ,
L_9 ) ;
F_34 ( & V_56 -> V_56 , L_10 ) ;
return - V_87 ;
}
V_82 = F_27 () ;
if ( V_82 < 0 )
return V_82 ;
F_6 ( 50 , 38000 ) ;
if ( V_58 == - 1 ) {
F_35 ( 500 ) ;
V_80 = 0 ;
V_81 = 0 ;
for ( V_21 = 0 ; V_21 < 9 ; V_21 ++ ) {
if ( F_1 ( V_53 ) & V_8 [ type ] . V_59 )
V_80 ++ ;
else
V_81 ++ ;
F_35 ( 40 ) ;
}
V_58 = V_80 >= V_81 ? 1 : 0 ;
F_36 ( & V_56 -> V_56 , L_11 ,
V_58 ? L_12 : L_13 ) ;
} else
F_36 ( & V_56 -> V_56 , L_14 ,
V_58 ? L_12 : L_13 ) ;
F_37 ( & V_56 -> V_56 , L_15 , V_83 , V_4 ) ;
return 0 ;
}
static int F_38 ( struct V_89 * V_40 )
{
unsigned long V_90 ;
V_12 . V_60 = F_12 () ;
F_39 ( & V_8 [ type ] . V_91 , V_90 ) ;
F_3 ( V_67 , F_1 ( V_67 ) & ( ~ V_68 ) ) ;
F_3 ( V_65 , F_1 ( V_65 ) | V_69 ) ;
F_40 ( & V_8 [ type ] . V_91 , V_90 ) ;
return 0 ;
}
static void F_41 ( struct V_89 * V_40 )
{
unsigned long V_90 ;
F_39 ( & V_8 [ type ] . V_91 , V_90 ) ;
F_3 ( V_67 , F_1 ( V_67 ) & ( ~ V_68 ) ) ;
F_3 ( V_65 , F_1 ( V_65 ) &
( ~ ( V_69 | V_70 | V_71 | V_72 ) ) ) ;
F_40 ( & V_8 [ type ] . V_91 , V_90 ) ;
}
static int F_42 ( struct V_89 * V_56 , unsigned int * V_92 ,
unsigned int V_93 )
{
unsigned long V_90 ;
T_2 V_29 ;
T_5 V_31 ;
int V_21 ;
F_39 ( & V_8 [ type ] . V_91 , V_90 ) ;
if ( type == V_74 ) {
F_5 () ;
}
V_29 = F_12 () ;
for ( V_21 = 0 ; V_21 < V_93 ; V_21 ++ ) {
if ( V_21 % 2 )
V_8 [ type ] . F_43 () ;
else
V_8 [ type ] . F_44 ( V_92 [ V_21 ] , V_29 ) ;
V_29 = F_11 ( V_29 , V_92 [ V_21 ] ) ;
V_31 = F_45 ( V_29 , F_12 () ) ;
if ( V_31 > 25 ) {
F_40 ( & V_8 [ type ] . V_91 , V_90 ) ;
F_46 ( V_31 - 25 , V_31 + 25 ) ;
F_39 ( & V_8 [ type ] . V_91 , V_90 ) ;
} else if ( V_31 > 0 ) {
F_47 ( V_31 ) ;
}
}
V_9 () ;
F_40 ( & V_8 [ type ] . V_91 , V_90 ) ;
return V_93 ;
}
static int F_48 ( struct V_89 * V_56 , T_6 V_94 )
{
F_6 ( V_94 , V_12 . V_14 ) ;
return 0 ;
}
static int F_49 ( struct V_89 * V_56 , T_6 V_95 )
{
if ( V_95 > 500000 || V_95 < 20000 )
return - V_88 ;
F_6 ( V_12 . V_13 , V_95 ) ;
return 0 ;
}
static int F_50 ( struct V_79 * V_56 ,
T_7 V_96 )
{
F_3 ( V_67 , F_1 ( V_67 ) & ( ~ V_68 ) ) ;
F_3 ( V_65 , F_1 ( V_65 ) &
( ~ ( V_69 | V_70 | V_71 | V_72 ) ) ) ;
F_1 ( V_26 ) ;
F_1 ( V_73 ) ;
F_1 ( V_50 ) ;
F_1 ( V_53 ) ;
return 0 ;
}
static int F_51 ( struct V_79 * V_56 )
{
unsigned long V_90 ;
int V_82 ;
V_82 = F_27 () ;
if ( V_82 < 0 )
return V_82 ;
F_39 ( & V_8 [ type ] . V_91 , V_90 ) ;
V_12 . V_60 = F_12 () ;
F_3 ( V_65 , F_1 ( V_65 ) | V_69 ) ;
V_9 () ;
F_40 ( & V_8 [ type ] . V_91 , V_90 ) ;
return 0 ;
}
static int T_8 F_52 ( void )
{
int V_82 ;
V_82 = F_53 ( & V_97 ) ;
if ( V_82 )
return V_82 ;
V_12 . V_55 = F_54 ( L_16 , 0 ) ;
if ( ! V_12 . V_55 ) {
V_82 = - V_98 ;
goto V_99;
}
V_82 = F_55 ( V_12 . V_55 ) ;
if ( V_82 )
goto V_100;
return 0 ;
V_100:
F_56 ( V_12 . V_55 ) ;
V_99:
F_57 ( & V_97 ) ;
return V_82 ;
}
static void F_58 ( void )
{
F_59 ( V_12 . V_55 ) ;
F_57 ( & V_97 ) ;
}
static int T_8 F_60 ( void )
{
struct V_89 * V_40 ;
int V_82 ;
switch ( type ) {
case V_101 :
case V_74 :
case V_75 :
case V_102 :
case V_103 :
V_4 = V_4 ? V_4 : 0x3f8 ;
V_83 = V_83 ? V_83 : 4 ;
break;
default:
return - V_88 ;
}
if ( ! V_32 ) {
switch ( type ) {
case V_101 :
case V_103 :
V_8 [ type ] . V_104 = false ;
V_8 [ type ] . V_105 = false ;
break;
}
}
if ( V_58 != - 1 )
V_58 = ! ! V_58 ;
V_82 = F_52 () ;
if ( V_82 )
return V_82 ;
V_40 = F_61 ( & V_12 . V_55 -> V_56 ) ;
if ( ! V_40 ) {
V_82 = - V_98 ;
goto V_106;
}
if ( V_8 [ type ] . F_44 && V_8 [ type ] . F_43 )
V_40 -> V_107 = F_42 ;
if ( V_8 [ type ] . V_104 )
V_40 -> V_108 = F_49 ;
if ( V_8 [ type ] . V_105 )
V_40 -> V_109 = F_48 ;
switch ( type ) {
case V_101 :
V_40 -> V_110 = L_17 ;
break;
case V_74 :
V_40 -> V_110 = L_18 ;
break;
case V_75 :
V_40 -> V_110 = L_19 ;
break;
case V_102 :
V_40 -> V_110 = L_20 ;
break;
case V_103 :
V_40 -> V_110 = L_21 ;
break;
}
V_40 -> V_111 = V_86 L_22 ;
V_40 -> V_112 . V_113 = V_114 ;
V_40 -> V_112 . V_115 = 0x0001 ;
V_40 -> V_112 . V_116 = 0x0001 ;
V_40 -> V_112 . V_117 = 0x0100 ;
V_40 -> V_118 = F_38 ;
V_40 -> V_119 = F_41 ;
V_40 -> V_56 . V_120 = & V_12 . V_55 -> V_56 ;
V_40 -> V_121 = V_122 ;
V_40 -> V_123 = V_124 ;
V_40 -> V_125 = V_86 ;
V_40 -> V_126 = V_127 ;
V_40 -> V_128 = V_129 ;
V_40 -> V_130 = 250000 ;
V_12 . V_40 = V_40 ;
V_82 = F_62 ( V_40 ) ;
if ( ! V_82 )
return 0 ;
V_106:
F_58 () ;
return V_82 ;
}
static void T_9 F_63 ( void )
{
F_64 ( V_12 . V_40 ) ;
F_58 () ;
}
