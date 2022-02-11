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
}
} while ( ! ( F_1 ( V_50 ) & V_51 ) );
F_26 ( & V_12 . V_61 ,
V_62 + F_27 ( V_12 . V_40 -> V_63 ) ) ;
F_28 ( V_12 . V_40 ) ;
return V_64 ;
}
static int F_29 ( void )
{
T_1 V_65 , V_66 , V_67 ;
V_65 = F_1 ( V_68 ) ;
F_3 ( V_68 , 0 ) ;
#ifdef F_30
F_4 ( 0xff , 0x080 ) ;
#endif
V_66 = F_1 ( V_68 ) & 0x0f ;
F_3 ( V_68 , 0x0f ) ;
#ifdef F_30
F_4 ( 0x00 , 0x080 ) ;
#endif
V_67 = F_1 ( V_68 ) & 0x0f ;
F_3 ( V_68 , V_65 ) ;
if ( V_66 != 0 || V_67 != 0x0f ) {
F_31 ( L_4 ) ;
return - V_69 ;
}
F_3 ( V_70 , F_1 ( V_70 ) & ( ~ V_71 ) ) ;
F_3 ( V_68 , F_1 ( V_68 ) &
( ~ ( V_72 | V_73 | V_74 | V_75 ) ) ) ;
F_1 ( V_26 ) ;
F_1 ( V_76 ) ;
F_1 ( V_50 ) ;
F_1 ( V_53 ) ;
V_9 () ;
F_1 ( V_26 ) ;
F_1 ( V_76 ) ;
F_1 ( V_50 ) ;
F_1 ( V_53 ) ;
switch ( type ) {
case V_77 :
case V_78 :
F_3 ( V_70 , F_1 ( V_70 ) | V_71 ) ;
F_3 ( V_79 , 0 ) ;
F_3 ( V_80 , 1 ) ;
F_3 ( V_70 , V_81 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_32 ( unsigned long V_82 )
{
F_21 ( V_38 ) ;
V_38 . V_63 = true ;
V_38 . V_39 = V_12 . V_40 -> V_63 ;
F_22 ( V_12 . V_40 , & V_38 ) ;
F_28 ( V_12 . V_40 ) ;
}
static int F_33 ( struct V_83 * V_56 )
{
struct V_84 * V_40 ;
int V_21 , V_85 , V_86 , V_87 ;
V_40 = F_34 ( & V_56 -> V_56 , V_88 ) ;
if ( ! V_40 )
return - V_89 ;
if ( V_8 [ type ] . V_90 && V_8 [ type ] . V_91 )
V_40 -> V_92 = V_93 ;
if ( V_8 [ type ] . V_94 )
V_40 -> V_95 = V_96 ;
if ( V_8 [ type ] . V_97 )
V_40 -> V_98 = V_99 ;
switch ( type ) {
case V_100 :
V_40 -> V_101 = L_5 ;
break;
case V_77 :
V_40 -> V_101 = L_6 ;
break;
case V_78 :
V_40 -> V_101 = L_7 ;
break;
case V_102 :
V_40 -> V_101 = L_8 ;
break;
case V_103 :
V_40 -> V_101 = L_9 ;
break;
}
V_40 -> V_104 = V_105 L_10 ;
V_40 -> V_106 . V_107 = V_108 ;
V_40 -> V_106 . V_109 = 0x0001 ;
V_40 -> V_106 . V_110 = 0x0001 ;
V_40 -> V_106 . V_111 = 0x0100 ;
V_40 -> V_112 = V_113 ;
V_40 -> V_114 = V_115 ;
V_40 -> V_56 . V_116 = & V_12 . V_55 -> V_56 ;
V_40 -> V_117 = V_118 ;
V_40 -> V_119 = V_105 ;
V_40 -> V_120 = V_121 ;
V_40 -> V_122 = 1 ;
V_40 -> V_63 = V_123 ;
V_40 -> V_124 = 10 * V_123 ;
V_40 -> V_125 = 250000 ;
V_12 . V_40 = V_40 ;
F_35 ( & V_12 . V_61 , F_32 ,
( unsigned long ) & V_12 ) ;
V_87 = F_36 ( & V_56 -> V_56 , V_126 , F_23 ,
V_127 ? V_128 : 0 ,
V_105 , & V_8 ) ;
if ( V_87 < 0 ) {
if ( V_87 == - V_129 )
F_24 ( & V_56 -> V_56 , L_11 , V_126 ) ;
else if ( V_87 == - V_130 )
F_24 ( & V_56 -> V_56 , L_12 ) ;
return V_87 ;
}
if ( ( V_2 &&
( F_37 ( & V_56 -> V_56 , V_2 , 8 << V_3 ,
V_105 ) == NULL ) ) ||
( ! V_2 && ( F_38 ( & V_56 -> V_56 , V_4 , 8 ,
V_105 ) == NULL ) ) ) {
F_24 ( & V_56 -> V_56 , L_13 , V_4 ) ;
F_39 ( & V_56 -> V_56 , L_14 ) ;
F_39 ( & V_56 -> V_56 ,
L_15 ) ;
F_39 ( & V_56 -> V_56 , L_16 ) ;
return - V_129 ;
}
V_87 = F_29 () ;
if ( V_87 < 0 )
return V_87 ;
F_6 ( 50 , 38000 ) ;
if ( V_58 == - 1 ) {
F_40 ( 500 ) ;
V_85 = 0 ;
V_86 = 0 ;
for ( V_21 = 0 ; V_21 < 9 ; V_21 ++ ) {
if ( F_1 ( V_53 ) & V_8 [ type ] . V_59 )
V_85 ++ ;
else
V_86 ++ ;
F_40 ( 40 ) ;
}
V_58 = V_85 >= V_86 ? 1 : 0 ;
F_41 ( & V_56 -> V_56 , L_17 ,
V_58 ? L_18 : L_19 ) ;
} else
F_41 ( & V_56 -> V_56 , L_20 ,
V_58 ? L_18 : L_19 ) ;
F_42 ( & V_56 -> V_56 , L_21 , V_126 , V_4 ) ;
return F_43 ( & V_56 -> V_56 , V_40 ) ;
}
static int V_113 ( struct V_84 * V_40 )
{
unsigned long V_131 ;
V_12 . V_60 = F_12 () ;
F_44 ( & V_8 [ type ] . V_132 , V_131 ) ;
F_3 ( V_70 , F_1 ( V_70 ) & ( ~ V_71 ) ) ;
F_3 ( V_68 , F_1 ( V_68 ) | V_72 ) ;
F_45 ( & V_8 [ type ] . V_132 , V_131 ) ;
return 0 ;
}
static void V_115 ( struct V_84 * V_40 )
{
unsigned long V_131 ;
F_44 ( & V_8 [ type ] . V_132 , V_131 ) ;
F_3 ( V_70 , F_1 ( V_70 ) & ( ~ V_71 ) ) ;
F_3 ( V_68 , F_1 ( V_68 ) &
( ~ ( V_72 | V_73 | V_74 | V_75 ) ) ) ;
F_45 ( & V_8 [ type ] . V_132 , V_131 ) ;
}
static int V_93 ( struct V_84 * V_56 , unsigned int * V_133 ,
unsigned int V_134 )
{
unsigned long V_131 ;
T_2 V_29 ;
T_5 V_31 ;
int V_21 ;
F_44 ( & V_8 [ type ] . V_132 , V_131 ) ;
if ( type == V_77 ) {
F_5 () ;
}
V_29 = F_12 () ;
for ( V_21 = 0 ; V_21 < V_134 ; V_21 ++ ) {
if ( V_21 % 2 )
V_8 [ type ] . V_91 () ;
else
V_8 [ type ] . V_90 ( V_133 [ V_21 ] , V_29 ) ;
V_29 = F_11 ( V_29 , V_133 [ V_21 ] ) ;
V_31 = F_46 ( V_29 , F_12 () ) ;
if ( V_31 > 25 ) {
F_45 ( & V_8 [ type ] . V_132 , V_131 ) ;
F_47 ( V_31 - 25 , V_31 + 25 ) ;
F_44 ( & V_8 [ type ] . V_132 , V_131 ) ;
} else if ( V_31 > 0 ) {
F_48 ( V_31 ) ;
}
}
V_9 () ;
F_45 ( & V_8 [ type ] . V_132 , V_131 ) ;
return V_134 ;
}
static int V_99 ( struct V_84 * V_56 , T_6 V_135 )
{
F_6 ( V_135 , V_12 . V_14 ) ;
return 0 ;
}
static int V_96 ( struct V_84 * V_56 , T_6 V_136 )
{
if ( V_136 > 500000 || V_136 < 20000 )
return - V_130 ;
F_6 ( V_12 . V_13 , V_136 ) ;
return 0 ;
}
static int F_49 ( struct V_83 * V_56 ,
T_7 V_137 )
{
F_3 ( V_70 , F_1 ( V_70 ) & ( ~ V_71 ) ) ;
F_3 ( V_68 , F_1 ( V_68 ) &
( ~ ( V_72 | V_73 | V_74 | V_75 ) ) ) ;
F_1 ( V_26 ) ;
F_1 ( V_76 ) ;
F_1 ( V_50 ) ;
F_1 ( V_53 ) ;
return 0 ;
}
static int F_50 ( struct V_83 * V_56 )
{
unsigned long V_131 ;
int V_87 ;
V_87 = F_29 () ;
if ( V_87 < 0 )
return V_87 ;
F_44 ( & V_8 [ type ] . V_132 , V_131 ) ;
V_12 . V_60 = F_12 () ;
F_3 ( V_68 , F_1 ( V_68 ) | V_72 ) ;
V_9 () ;
F_45 ( & V_8 [ type ] . V_132 , V_131 ) ;
return 0 ;
}
static int T_8 F_51 ( void )
{
int V_87 ;
V_87 = F_52 ( & V_138 ) ;
if ( V_87 )
return V_87 ;
V_12 . V_55 = F_53 ( L_22 , 0 ) ;
if ( ! V_12 . V_55 ) {
V_87 = - V_89 ;
goto V_139;
}
V_87 = F_54 ( V_12 . V_55 ) ;
if ( V_87 )
goto V_140;
return 0 ;
V_140:
F_55 ( V_12 . V_55 ) ;
V_139:
F_56 ( & V_138 ) ;
return V_87 ;
}
static void F_57 ( void )
{
F_58 ( V_12 . V_55 ) ;
F_56 ( & V_138 ) ;
}
static int T_8 F_59 ( void )
{
int V_87 ;
switch ( type ) {
case V_100 :
case V_77 :
case V_78 :
case V_102 :
case V_103 :
V_4 = V_4 ? V_4 : 0x3f8 ;
V_126 = V_126 ? V_126 : 4 ;
break;
default:
return - V_130 ;
}
if ( ! V_32 ) {
switch ( type ) {
case V_100 :
case V_103 :
V_8 [ type ] . V_94 = false ;
V_8 [ type ] . V_97 = false ;
break;
}
}
if ( V_58 != - 1 )
V_58 = ! ! V_58 ;
V_87 = F_51 () ;
if ( ! V_87 )
return 0 ;
F_57 () ;
return V_87 ;
}
static void T_9 F_60 ( void )
{
F_61 ( & V_12 . V_61 ) ;
F_57 () ;
}
