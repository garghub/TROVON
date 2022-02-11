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
static void F_6 ( unsigned int V_10 , T_2 V_11 )
{
long V_12 ;
int V_13 ;
unsigned char V_14 ;
unsigned char V_15 , V_16 ;
V_12 = V_10 * 1152 / 10000 ;
if ( V_17 . V_18 > 50 )
V_15 = 3 ;
else
V_15 = 1 ;
for ( V_13 = 0 , V_14 = 0x7f ; V_12 > 0 ; V_12 -= 3 ) {
V_16 = V_15 << ( V_13 * 3 ) ;
V_16 >>= 1 ;
V_14 &= ( ~ V_16 ) ;
V_13 ++ ;
if ( V_13 == 3 ) {
F_3 ( V_19 , V_14 ) ;
while ( ! ( F_1 ( V_20 ) & V_21 ) )
;
V_14 = 0x7f ;
V_13 = 0 ;
}
}
if ( V_13 != 0 ) {
F_3 ( V_19 , V_14 ) ;
while ( ! ( F_1 ( V_20 ) & V_22 ) )
;
}
}
static void F_7 ( void )
{
}
static void F_8 ( unsigned int V_10 , T_2 V_23 )
{
T_2 V_24 , V_11 = F_9 ( V_23 , V_10 ) ;
T_3 V_25 ;
unsigned int V_26 , V_27 ;
V_26 = F_10 ( V_17 . V_18 * ( V_28 / 100 ) ,
V_17 . V_29 ) ;
V_27 = F_10 ( ( 100 - V_17 . V_18 ) *
( V_28 / 100 ) , V_17 . V_29 ) ;
for (; ; ) {
V_24 = F_11 () ;
if ( F_12 ( V_24 , V_11 ) >= 0 )
break;
F_5 () ;
V_23 = F_13 ( V_23 , V_26 ) ;
V_25 = F_14 ( F_15 ( V_23 , V_24 ) ) ;
if ( V_25 > 0 )
F_16 ( V_25 ) ;
V_24 = F_11 () ;
V_9 () ;
if ( F_12 ( V_24 , V_11 ) >= 0 )
break;
V_23 = F_13 ( V_23 , V_27 ) ;
V_25 = F_14 ( F_15 ( V_23 , V_24 ) ) ;
if ( V_25 > 0 )
F_16 ( V_25 ) ;
}
}
static void F_17 ( unsigned int V_10 , T_2 V_23 )
{
if ( V_30 )
F_8 ( V_10 , V_23 ) ;
else
F_5 () ;
}
static void F_18 ( void )
{
V_9 () ;
}
static void F_19 ( unsigned int V_31 , bool V_32 )
{
static unsigned int V_33 , V_26 , V_27 ;
F_20 ( V_34 ) ;
if ( V_33 > 0 && V_32 ) {
V_26 += V_31 ;
if ( V_26 > 250000 ) {
V_34 . V_35 = V_27 ;
V_34 . V_26 = false ;
F_21 ( V_17 . V_36 , & V_34 ) ;
V_34 . V_35 = V_26 ;
V_34 . V_26 = true ;
F_21 ( V_17 . V_36 , & V_34 ) ;
V_33 = 0 ;
V_26 = 0 ;
}
return;
}
if ( ! V_32 ) {
if ( V_33 == 0 ) {
if ( V_31 > 20000000 ) {
V_27 = V_31 ;
V_33 ++ ;
return;
}
} else {
if ( V_31 > 20000000 ) {
V_27 += V_26 ;
if ( V_27 > V_37 )
V_27 = V_37 ;
V_27 += V_31 ;
if ( V_27 > V_37 )
V_27 = V_37 ;
V_26 = 0 ;
return;
}
V_34 . V_35 = V_27 ;
V_34 . V_26 = false ;
F_21 ( V_17 . V_36 , & V_34 ) ;
V_34 . V_35 = V_26 ;
V_34 . V_26 = true ;
F_21 ( V_17 . V_36 , & V_34 ) ;
V_33 = 0 ;
V_26 = 0 ;
}
}
V_34 . V_35 = V_31 ;
V_34 . V_26 = V_32 ;
F_21 ( V_17 . V_36 , & V_34 ) ;
}
static T_4 F_22 ( int V_13 , void * V_38 )
{
T_2 V_39 ;
int V_40 , V_41 ;
T_1 V_42 ;
T_2 V_43 ;
unsigned int V_44 ;
static int V_45 = - 1 ;
if ( ( F_1 ( V_46 ) & V_47 ) ) {
return V_48 ;
}
V_40 = 0 ;
do {
V_40 ++ ;
V_42 = F_1 ( V_49 ) ;
if ( V_40 > V_50 ) {
F_23 ( & V_17 . V_51 -> V_52 , L_1 ) ;
break;
}
if ( ( V_42 & V_8 [ type ] . V_53 ) &&
V_54 != - 1 ) {
V_39 = F_11 () ;
V_41 = ( V_42 & V_8 [ type ] . V_55 ) ? 1 : 0 ;
if ( V_41 == V_45 ) {
F_23 ( & V_17 . V_51 -> V_52 ,
L_2 ,
V_41 , V_54 , F_14 ( V_39 ) ,
F_14 ( V_17 . V_56 ) ) ;
continue;
}
V_43 = F_15 ( V_39 , V_17 . V_56 ) ;
if ( F_12 ( V_43 , F_24 ( 15 , 0 ) ) > 0 ) {
V_44 = V_37 ;
if ( ! ( V_41 ^ V_54 ) ) {
F_23 ( & V_17 . V_51 -> V_52 ,
L_3 ,
V_41 , V_54 , F_14 ( V_39 ) ,
F_14 ( V_17 . V_56 ) ) ;
V_54 = V_54 ? 0 : 1 ;
}
} else {
V_44 = F_14 ( V_43 ) ;
}
F_19 ( V_44 , ! ( V_41 ^ V_54 ) ) ;
V_17 . V_56 = V_39 ;
V_45 = V_41 ;
}
} while ( ! ( F_1 ( V_46 ) & V_47 ) );
F_25 ( & V_17 . V_57 ,
V_58 + F_26 ( V_17 . V_36 -> V_59 ) ) ;
F_27 ( V_17 . V_36 ) ;
return V_60 ;
}
static int F_28 ( void )
{
T_1 V_61 , V_62 , V_63 ;
V_61 = F_1 ( V_64 ) ;
F_3 ( V_64 , 0 ) ;
#ifdef F_29
F_4 ( 0xff , 0x080 ) ;
#endif
V_62 = F_1 ( V_64 ) & 0x0f ;
F_3 ( V_64 , 0x0f ) ;
#ifdef F_29
F_4 ( 0x00 , 0x080 ) ;
#endif
V_63 = F_1 ( V_64 ) & 0x0f ;
F_3 ( V_64 , V_61 ) ;
if ( V_62 != 0 || V_63 != 0x0f ) {
F_30 ( L_4 ) ;
return - V_65 ;
}
F_3 ( V_66 , F_1 ( V_66 ) & ( ~ V_67 ) ) ;
F_3 ( V_64 , F_1 ( V_64 ) &
( ~ ( V_68 | V_69 | V_70 | V_71 ) ) ) ;
F_1 ( V_20 ) ;
F_1 ( V_72 ) ;
F_1 ( V_46 ) ;
F_1 ( V_49 ) ;
V_9 () ;
F_1 ( V_20 ) ;
F_1 ( V_72 ) ;
F_1 ( V_46 ) ;
F_1 ( V_49 ) ;
switch ( type ) {
case V_73 :
case V_74 :
F_3 ( V_66 , F_1 ( V_66 ) | V_67 ) ;
F_3 ( V_75 , 0 ) ;
F_3 ( V_76 , 1 ) ;
F_3 ( V_66 , V_77 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_31 ( unsigned long V_78 )
{
F_20 ( V_34 ) ;
V_34 . V_59 = true ;
V_34 . V_35 = V_17 . V_36 -> V_59 ;
F_21 ( V_17 . V_36 , & V_34 ) ;
F_27 ( V_17 . V_36 ) ;
}
static int F_32 ( struct V_79 * V_52 )
{
struct V_80 * V_36 ;
int V_13 , V_81 , V_82 , V_83 ;
V_36 = F_33 ( & V_52 -> V_52 , V_84 ) ;
if ( ! V_36 )
return - V_85 ;
if ( V_8 [ type ] . V_86 && V_8 [ type ] . V_87 )
V_36 -> V_88 = V_89 ;
if ( V_8 [ type ] . V_90 )
V_36 -> V_91 = V_92 ;
if ( V_8 [ type ] . V_93 )
V_36 -> V_94 = V_95 ;
switch ( type ) {
case V_96 :
V_36 -> V_97 = L_5 ;
break;
case V_73 :
V_36 -> V_97 = L_6 ;
break;
case V_74 :
V_36 -> V_97 = L_7 ;
break;
case V_98 :
V_36 -> V_97 = L_8 ;
break;
case V_99 :
V_36 -> V_97 = L_9 ;
break;
}
V_36 -> V_100 = V_101 L_10 ;
V_36 -> V_102 . V_103 = V_104 ;
V_36 -> V_102 . V_105 = 0x0001 ;
V_36 -> V_102 . V_106 = 0x0001 ;
V_36 -> V_102 . V_107 = 0x0100 ;
V_36 -> V_108 = V_109 ;
V_36 -> V_110 = V_111 ;
V_36 -> V_52 . V_112 = & V_17 . V_51 -> V_52 ;
V_36 -> V_113 = V_114 ;
V_36 -> V_115 = V_101 ;
V_36 -> V_116 = V_117 ;
V_36 -> V_118 = 1 ;
V_36 -> V_59 = V_119 ;
V_36 -> V_120 = 10 * V_119 ;
V_36 -> V_121 = 250000 ;
V_17 . V_36 = V_36 ;
F_34 ( & V_17 . V_57 , F_31 ,
( unsigned long ) & V_17 ) ;
V_83 = F_35 ( & V_52 -> V_52 , V_122 , F_22 ,
V_123 ? V_124 : 0 ,
V_101 , & V_8 ) ;
if ( V_83 < 0 ) {
if ( V_83 == - V_125 )
F_23 ( & V_52 -> V_52 , L_11 , V_122 ) ;
else if ( V_83 == - V_126 )
F_23 ( & V_52 -> V_52 , L_12 ) ;
return V_83 ;
}
if ( ( V_2 &&
( F_36 ( & V_52 -> V_52 , V_2 , 8 << V_3 ,
V_101 ) == NULL ) ) ||
( ! V_2 && ( F_37 ( & V_52 -> V_52 , V_4 , 8 ,
V_101 ) == NULL ) ) ) {
F_23 ( & V_52 -> V_52 , L_13 , V_4 ) ;
F_38 ( & V_52 -> V_52 , L_14 ) ;
F_38 ( & V_52 -> V_52 ,
L_15 ) ;
F_38 ( & V_52 -> V_52 , L_16 ) ;
return - V_125 ;
}
V_83 = F_28 () ;
if ( V_83 < 0 )
return V_83 ;
V_17 . V_18 = 50 ;
V_17 . V_29 = 38000 ;
if ( V_54 == - 1 ) {
F_39 ( 500 ) ;
V_81 = 0 ;
V_82 = 0 ;
for ( V_13 = 0 ; V_13 < 9 ; V_13 ++ ) {
if ( F_1 ( V_49 ) & V_8 [ type ] . V_55 )
V_81 ++ ;
else
V_82 ++ ;
F_39 ( 40 ) ;
}
V_54 = V_81 >= V_82 ? 1 : 0 ;
F_40 ( & V_52 -> V_52 , L_17 ,
V_54 ? L_18 : L_19 ) ;
} else
F_40 ( & V_52 -> V_52 , L_20 ,
V_54 ? L_18 : L_19 ) ;
F_41 ( & V_52 -> V_52 , L_21 , V_122 , V_4 ) ;
return F_42 ( & V_52 -> V_52 , V_36 ) ;
}
static int V_109 ( struct V_80 * V_36 )
{
unsigned long V_127 ;
V_17 . V_56 = F_11 () ;
F_43 ( & V_8 [ type ] . V_128 , V_127 ) ;
F_3 ( V_66 , F_1 ( V_66 ) & ( ~ V_67 ) ) ;
F_3 ( V_64 , F_1 ( V_64 ) | V_68 ) ;
F_44 ( & V_8 [ type ] . V_128 , V_127 ) ;
return 0 ;
}
static void V_111 ( struct V_80 * V_36 )
{
unsigned long V_127 ;
F_43 ( & V_8 [ type ] . V_128 , V_127 ) ;
F_3 ( V_66 , F_1 ( V_66 ) & ( ~ V_67 ) ) ;
F_3 ( V_64 , F_1 ( V_64 ) &
( ~ ( V_68 | V_69 | V_70 | V_71 ) ) ) ;
F_44 ( & V_8 [ type ] . V_128 , V_127 ) ;
}
static int V_89 ( struct V_80 * V_52 , unsigned int * V_129 ,
unsigned int V_130 )
{
unsigned long V_127 ;
T_2 V_23 ;
T_5 V_25 ;
int V_13 ;
F_43 ( & V_8 [ type ] . V_128 , V_127 ) ;
if ( type == V_73 ) {
F_5 () ;
}
V_23 = F_11 () ;
for ( V_13 = 0 ; V_13 < V_130 ; V_13 ++ ) {
if ( V_13 % 2 )
V_8 [ type ] . V_87 () ;
else
V_8 [ type ] . V_86 ( V_129 [ V_13 ] , V_23 ) ;
V_23 = F_9 ( V_23 , V_129 [ V_13 ] ) ;
V_25 = F_45 ( V_23 , F_11 () ) ;
if ( V_25 > 25 ) {
F_44 ( & V_8 [ type ] . V_128 , V_127 ) ;
F_46 ( V_25 - 25 , V_25 + 25 ) ;
F_43 ( & V_8 [ type ] . V_128 , V_127 ) ;
} else if ( V_25 > 0 ) {
F_47 ( V_25 ) ;
}
}
V_9 () ;
F_44 ( & V_8 [ type ] . V_128 , V_127 ) ;
return V_130 ;
}
static int V_95 ( struct V_80 * V_52 , T_6 V_131 )
{
V_17 . V_18 = V_131 ;
return 0 ;
}
static int V_92 ( struct V_80 * V_52 , T_6 V_29 )
{
if ( V_29 > 500000 || V_29 < 20000 )
return - V_126 ;
V_17 . V_29 = V_29 ;
return 0 ;
}
static int F_48 ( struct V_79 * V_52 ,
T_7 V_132 )
{
F_3 ( V_66 , F_1 ( V_66 ) & ( ~ V_67 ) ) ;
F_3 ( V_64 , F_1 ( V_64 ) &
( ~ ( V_68 | V_69 | V_70 | V_71 ) ) ) ;
F_1 ( V_20 ) ;
F_1 ( V_72 ) ;
F_1 ( V_46 ) ;
F_1 ( V_49 ) ;
return 0 ;
}
static int F_49 ( struct V_79 * V_52 )
{
unsigned long V_127 ;
int V_83 ;
V_83 = F_28 () ;
if ( V_83 < 0 )
return V_83 ;
F_43 ( & V_8 [ type ] . V_128 , V_127 ) ;
V_17 . V_56 = F_11 () ;
F_3 ( V_64 , F_1 ( V_64 ) | V_68 ) ;
V_9 () ;
F_44 ( & V_8 [ type ] . V_128 , V_127 ) ;
return 0 ;
}
static int T_8 F_50 ( void )
{
int V_83 ;
V_83 = F_51 ( & V_133 ) ;
if ( V_83 )
return V_83 ;
V_17 . V_51 = F_52 ( L_22 , 0 ) ;
if ( ! V_17 . V_51 ) {
V_83 = - V_85 ;
goto V_134;
}
V_83 = F_53 ( V_17 . V_51 ) ;
if ( V_83 )
goto V_135;
return 0 ;
V_135:
F_54 ( V_17 . V_51 ) ;
V_134:
F_55 ( & V_133 ) ;
return V_83 ;
}
static void F_56 ( void )
{
F_57 ( V_17 . V_51 ) ;
F_55 ( & V_133 ) ;
}
static int T_8 F_58 ( void )
{
int V_83 ;
switch ( type ) {
case V_96 :
case V_73 :
case V_74 :
case V_98 :
case V_99 :
V_4 = V_4 ? V_4 : 0x3f8 ;
V_122 = V_122 ? V_122 : 4 ;
break;
default:
return - V_126 ;
}
if ( ! V_30 ) {
switch ( type ) {
case V_96 :
case V_99 :
V_8 [ type ] . V_90 = false ;
V_8 [ type ] . V_93 = false ;
break;
}
}
if ( V_54 != - 1 )
V_54 = ! ! V_54 ;
V_83 = F_50 () ;
if ( ! V_83 )
return 0 ;
F_56 () ;
return V_83 ;
}
static void T_9 F_59 ( void )
{
F_60 ( & V_17 . V_57 ) ;
F_56 () ;
}
