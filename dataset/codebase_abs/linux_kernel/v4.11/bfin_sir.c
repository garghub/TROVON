static void F_1 ( int V_1 )
{
long V_2 ;
V_1 = V_1 < 10000 ? 10000 : V_1 ;
V_2 = 1 + V_1 / ( V_3 / V_4 ) ;
F_2 ( V_2 ) ;
}
static void F_3 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
int V_9 ;
struct V_10 * V_11 ;
for ( V_9 = 0 ; V_9 < V_8 -> V_12 ; V_9 ++ ) {
V_11 = & V_8 -> V_10 [ V_9 ] ;
switch ( V_11 -> V_13 ) {
case V_14 :
V_6 -> V_15 = ( void V_16 * ) V_11 -> V_17 ;
break;
case V_18 :
V_6 -> V_19 = V_11 -> V_17 ;
break;
case V_20 :
V_6 -> V_21 = V_11 -> V_17 ;
V_6 -> V_22 = V_11 -> V_23 ;
break;
default:
break;
}
}
V_6 -> V_24 = F_4 () ;
#ifdef F_5
V_6 -> V_25 = 1 ;
F_6 ( & ( V_6 -> V_26 ) ) ;
#endif
}
static void F_7 ( struct V_5 * V_27 )
{
#ifdef F_5
F_8 ( V_27 -> V_22 ) ;
#endif
while ( ! ( F_9 ( V_27 ) & V_28 ) ) {
F_10 () ;
continue;
}
F_11 ( V_27 , V_29 ) ;
}
static void F_12 ( struct V_5 * V_27 )
{
F_13 ( V_27 , V_29 ) ;
}
static void F_14 ( struct V_5 * V_27 )
{
F_11 ( V_27 , V_30 ) ;
}
static void F_15 ( struct V_5 * V_27 )
{
F_13 ( V_27 , V_30 ) ;
}
static int F_16 ( struct V_5 * V_27 , int V_31 )
{
int V_32 = - V_33 ;
unsigned int V_34 ;
unsigned short V_35 , V_36 , V_37 ;
static int V_38 ;
int V_39 = 10 ;
V_37 = F_17 ( 8 ) ;
switch ( V_31 ) {
case 9600 :
case 19200 :
case 38400 :
case 57600 :
case 115200 :
V_34 = ( V_27 -> V_24 + ( 8 * V_31 ) ) / ( 16 * V_31 ) ;
do {
F_18 ( V_38 ) ;
V_36 = F_9 ( V_27 ) ;
} while ( ! ( V_36 & V_40 ) && V_39 -- );
V_38 = 1000000 / V_31 + 1 ;
V_35 = F_19 ( V_27 ) ;
V_35 &= ~ V_41 ;
F_20 ( V_27 , V_35 ) ;
F_21 ( V_27 ) ;
F_22 () ;
F_23 ( V_27 , V_34 & 0xFF ) ;
F_24 ( V_27 , ( V_34 >> 8 ) & 0xFF ) ;
F_22 () ;
F_25 ( V_27 ) ;
F_22 () ;
F_26 ( V_27 , V_37 ) ;
V_35 = F_19 ( V_27 ) ;
V_35 |= V_41 ;
F_20 ( V_27 , V_35 ) ;
V_32 = 0 ;
break;
default:
F_27 ( V_42 L_1 , V_31 ) ;
break;
}
V_35 = F_19 ( V_27 ) ;
V_35 |= V_43 | V_44 ;
F_20 ( V_27 , V_35 ) ;
return V_32 ;
}
static int F_28 ( struct V_45 * V_46 )
{
struct V_47 * V_48 = F_29 ( V_46 ) ;
struct V_5 * V_27 = V_48 -> V_49 ;
if ( ! ( F_30 ( V_27 ) & V_30 ) )
return 0 ;
return V_48 -> V_50 . V_51 != V_52 ;
}
static void F_31 ( struct V_45 * V_46 )
{
unsigned int V_53 ;
struct V_47 * V_48 = F_29 ( V_46 ) ;
struct V_5 * V_27 = V_48 -> V_49 ;
if ( V_48 -> V_54 . V_55 != 0 ) {
V_53 = * ( V_48 -> V_54 . V_56 ) ;
F_32 ( V_27 , V_53 ) ;
V_48 -> V_54 . V_56 ++ ;
V_48 -> V_54 . V_55 -- ;
} else {
V_48 -> V_57 . V_58 ++ ;
V_48 -> V_57 . V_59 += V_48 -> V_54 . V_56 - V_48 -> V_54 . V_60 ;
if ( V_48 -> V_61 ) {
F_16 ( V_27 , V_48 -> V_61 ) ;
V_48 -> V_31 = V_48 -> V_61 ;
V_48 -> V_61 = 0 ;
}
F_7 ( V_27 ) ;
F_15 ( V_27 ) ;
F_33 ( V_46 ) ;
}
}
static void F_34 ( struct V_45 * V_46 )
{
struct V_47 * V_48 = F_29 ( V_46 ) ;
struct V_5 * V_27 = V_48 -> V_49 ;
unsigned char V_62 ;
F_35 ( V_27 ) ;
V_62 = F_36 ( V_27 ) ;
F_37 ( V_46 , & V_48 -> V_57 , & V_48 -> V_50 , V_62 ) ;
}
static T_1 F_38 ( int V_19 , void * V_63 )
{
struct V_45 * V_46 = V_63 ;
struct V_47 * V_48 = F_29 ( V_46 ) ;
struct V_5 * V_27 = V_48 -> V_49 ;
F_39 ( & V_48 -> V_64 ) ;
while ( ( F_9 ( V_27 ) & V_65 ) )
F_34 ( V_46 ) ;
F_40 ( & V_48 -> V_64 ) ;
return V_66 ;
}
static T_1 F_41 ( int V_19 , void * V_63 )
{
struct V_45 * V_46 = V_63 ;
struct V_47 * V_48 = F_29 ( V_46 ) ;
struct V_5 * V_27 = V_48 -> V_49 ;
F_39 ( & V_48 -> V_64 ) ;
if ( F_9 ( V_27 ) & V_28 )
F_31 ( V_46 ) ;
F_40 ( & V_48 -> V_64 ) ;
return V_66 ;
}
static void F_42 ( struct V_45 * V_46 )
{
struct V_47 * V_48 = F_29 ( V_46 ) ;
struct V_5 * V_27 = V_48 -> V_49 ;
if ( ! V_27 -> V_25 )
return;
V_27 -> V_25 = 0 ;
if ( V_48 -> V_54 . V_55 == 0 ) {
V_48 -> V_57 . V_58 ++ ;
if ( V_48 -> V_61 ) {
F_16 ( V_27 , V_48 -> V_61 ) ;
V_48 -> V_31 = V_48 -> V_61 ;
V_48 -> V_61 = 0 ;
}
F_15 ( V_27 ) ;
V_27 -> V_25 = 1 ;
F_33 ( V_46 ) ;
return;
}
F_43 ( ( unsigned long ) ( V_48 -> V_54 . V_56 ) ,
( unsigned long ) ( V_48 -> V_54 . V_56 + V_48 -> V_54 . V_55 ) ) ;
F_44 ( V_27 -> V_22 ,
F_45 ( V_67 , V_68 ,
V_69 , V_70 , V_71 ,
V_72 ) ) ;
F_46 ( V_27 -> V_22 ,
( unsigned long ) ( V_48 -> V_54 . V_56 ) ) ;
F_47 ( V_27 -> V_22 , V_48 -> V_54 . V_55 ) ;
F_48 ( V_27 -> V_22 , 1 ) ;
F_49 ( V_27 -> V_22 ) ;
}
static T_1 F_50 ( int V_19 , void * V_63 )
{
struct V_45 * V_46 = V_63 ;
struct V_47 * V_48 = F_29 ( V_46 ) ;
struct V_5 * V_27 = V_48 -> V_49 ;
F_39 ( & V_48 -> V_64 ) ;
if ( ! ( F_51 ( V_27 -> V_22 ) & V_73 ) ) {
F_52 ( V_27 -> V_22 ) ;
F_7 ( V_27 ) ;
V_48 -> V_57 . V_58 ++ ;
V_48 -> V_57 . V_59 += V_48 -> V_54 . V_55 ;
V_48 -> V_54 . V_55 = 0 ;
if ( V_48 -> V_61 ) {
F_16 ( V_27 , V_48 -> V_61 ) ;
V_48 -> V_31 = V_48 -> V_61 ;
V_48 -> V_61 = 0 ;
}
F_15 ( V_27 ) ;
F_33 ( V_46 ) ;
V_27 -> V_25 = 1 ;
}
F_40 ( & V_48 -> V_64 ) ;
return V_66 ;
}
static void F_53 ( struct V_45 * V_46 )
{
struct V_47 * V_48 = F_29 ( V_46 ) ;
struct V_5 * V_27 = V_48 -> V_49 ;
int V_9 ;
F_35 ( V_27 ) ;
for ( V_9 = V_27 -> V_74 . V_60 ; V_9 < V_27 -> V_74 . V_75 ; V_9 ++ )
F_37 ( V_46 , & V_48 -> V_57 , & V_48 -> V_50 , V_27 -> V_74 . V_76 [ V_9 ] ) ;
}
void F_54 ( struct V_45 * V_46 )
{
struct V_47 * V_48 = F_29 ( V_46 ) ;
struct V_5 * V_27 = V_48 -> V_49 ;
int V_77 , V_78 ;
unsigned long V_13 ;
F_55 ( & V_48 -> V_64 , V_13 ) ;
V_77 = V_79 - F_56 ( V_27 -> V_21 ) ;
if ( V_77 == V_79 )
V_77 = 0 ;
V_78 = V_27 -> V_80 * V_79 + V_77 ;
if ( V_78 > V_27 -> V_74 . V_75 ) {
V_27 -> V_74 . V_75 = V_78 ;
F_53 ( V_46 ) ;
V_27 -> V_74 . V_60 = V_27 -> V_74 . V_75 ;
}
F_57 ( & V_48 -> V_64 , V_13 ) ;
}
static T_1 F_58 ( int V_19 , void * V_63 )
{
struct V_45 * V_46 = V_63 ;
struct V_47 * V_48 = F_29 ( V_46 ) ;
struct V_5 * V_27 = V_48 -> V_49 ;
unsigned short V_81 ;
F_39 ( & V_48 -> V_64 ) ;
V_27 -> V_80 ++ ;
V_27 -> V_74 . V_75 = V_79 * V_27 -> V_80 ;
F_53 ( V_46 ) ;
if ( V_27 -> V_80 >= V_82 ) {
V_27 -> V_80 = 0 ;
V_27 -> V_74 . V_75 = 0 ;
}
V_27 -> V_74 . V_60 = V_27 -> V_74 . V_75 ;
V_81 = F_51 ( V_27 -> V_21 ) ;
F_52 ( V_27 -> V_21 ) ;
F_40 ( & V_48 -> V_64 ) ;
F_59 ( & V_27 -> V_26 , V_83 + V_84 ) ;
return V_66 ;
}
static int F_60 ( struct V_5 * V_27 , struct V_45 * V_46 )
{
#ifdef F_5
T_2 V_85 ;
#endif
if ( F_61 ( V_27 -> V_21 , L_2 ) < 0 ) {
F_62 ( & V_46 -> V_46 , L_3 ) ;
return - V_86 ;
}
if ( F_61 ( V_27 -> V_22 , L_4 ) < 0 ) {
F_62 ( & V_46 -> V_46 , L_5 ) ;
F_63 ( V_27 -> V_21 ) ;
return - V_86 ;
}
#ifdef F_5
F_64 ( V_27 -> V_21 , F_58 , V_46 ) ;
F_64 ( V_27 -> V_22 , F_50 , V_46 ) ;
V_27 -> V_74 . V_76 = F_65 ( NULL , V_87 ,
& V_85 , V_88 ) ;
V_27 -> V_74 . V_60 = 0 ;
V_27 -> V_74 . V_75 = 0 ;
V_27 -> V_80 = 0 ;
F_44 ( V_27 -> V_21 ,
F_45 ( V_89 , V_90 ,
V_91 , V_92 ,
V_71 , V_72 ) ) ;
F_47 ( V_27 -> V_21 , V_79 ) ;
F_48 ( V_27 -> V_21 , 1 ) ;
F_66 ( V_27 -> V_21 , V_82 ) ;
F_67 ( V_27 -> V_21 , 1 ) ;
F_46 ( V_27 -> V_21 , ( unsigned long ) V_27 -> V_74 . V_76 ) ;
F_49 ( V_27 -> V_21 ) ;
V_27 -> V_26 . V_56 = ( unsigned long ) ( V_46 ) ;
V_27 -> V_26 . V_93 = ( void * ) F_54 ;
#else
if ( F_68 ( V_27 -> V_19 , F_38 , 0 , L_6 , V_46 ) ) {
F_62 ( & V_46 -> V_46 , L_7 ) ;
return - V_86 ;
}
if ( F_68 ( V_27 -> V_19 + 1 , F_41 , 0 , L_8 , V_46 ) ) {
F_62 ( & V_46 -> V_46 , L_9 ) ;
F_69 ( V_27 -> V_19 , V_46 ) ;
return - V_86 ;
}
#endif
return 0 ;
}
static void F_70 ( struct V_5 * V_27 , struct V_45 * V_46 )
{
unsigned short V_35 ;
F_14 ( V_27 ) ;
V_35 = F_19 ( V_27 ) ;
V_35 &= ~ ( V_41 | V_94 | V_44 ) ;
F_20 ( V_27 , V_35 ) ;
#ifdef F_5
F_8 ( V_27 -> V_22 ) ;
F_8 ( V_27 -> V_21 ) ;
F_71 ( & ( V_27 -> V_26 ) ) ;
F_72 ( NULL , V_87 , V_27 -> V_74 . V_76 , 0 ) ;
#else
F_69 ( V_27 -> V_19 + 1 , V_46 ) ;
F_69 ( V_27 -> V_19 , V_46 ) ;
#endif
F_63 ( V_27 -> V_22 ) ;
F_63 ( V_27 -> V_21 ) ;
}
static int F_73 ( struct V_7 * V_8 , T_3 V_51 )
{
struct V_5 * V_49 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
V_49 = F_74 ( V_8 ) ;
if ( ! V_49 )
return 0 ;
V_46 = V_49 -> V_46 ;
V_48 = F_29 ( V_46 ) ;
if ( V_48 -> V_95 ) {
F_75 ( & V_48 -> V_96 ) ;
F_70 ( V_48 -> V_49 , V_46 ) ;
F_76 ( V_46 ) ;
}
return 0 ;
}
static int F_77 ( struct V_7 * V_8 )
{
struct V_5 * V_49 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
struct V_5 * V_27 ;
V_49 = F_74 ( V_8 ) ;
if ( ! V_49 )
return 0 ;
V_46 = V_49 -> V_46 ;
V_48 = F_29 ( V_46 ) ;
V_27 = V_48 -> V_49 ;
if ( V_48 -> V_95 ) {
if ( V_48 -> V_61 ) {
V_48 -> V_31 = V_48 -> V_61 ;
V_48 -> V_61 = 0 ;
}
F_60 ( V_27 , V_46 ) ;
F_16 ( V_27 , 9600 ) ;
F_15 ( V_27 ) ;
F_78 ( V_46 ) ;
}
return 0 ;
}
static void F_79 ( struct V_97 * V_96 )
{
struct V_47 * V_48 = F_80 ( V_96 , struct V_47 , V_96 ) ;
struct V_45 * V_46 = V_48 -> V_49 -> V_46 ;
struct V_5 * V_27 = V_48 -> V_49 ;
unsigned short V_35 ;
int V_98 = 10 ;
while ( F_28 ( V_46 ) && -- V_98 )
F_1 ( V_48 -> V_1 ) ;
F_14 ( V_27 ) ;
V_35 = F_19 ( V_27 ) ;
V_35 &= ~ ( V_94 | V_44 ) ;
F_20 ( V_27 , V_35 ) ;
F_22 () ;
V_35 |= V_43 | V_44 ;
F_20 ( V_27 , V_35 ) ;
F_22 () ;
#ifdef F_5
F_42 ( V_46 ) ;
#endif
F_12 ( V_27 ) ;
F_81 ( V_46 ) ;
}
static int F_82 ( struct V_99 * V_100 , struct V_45 * V_46 )
{
struct V_47 * V_48 = F_29 ( V_46 ) ;
int V_31 = F_83 ( V_100 ) ;
F_84 ( V_46 ) ;
V_48 -> V_1 = F_85 ( V_100 ) ;
if ( V_31 != V_48 -> V_31 && V_31 != - 1 )
V_48 -> V_61 = V_31 ;
V_48 -> V_54 . V_56 = V_48 -> V_54 . V_60 ;
if ( V_100 -> V_55 == 0 )
V_48 -> V_54 . V_55 = 0 ;
else
V_48 -> V_54 . V_55 = F_86 ( V_100 , V_48 -> V_54 . V_56 , V_48 -> V_54 . V_101 ) ;
F_87 ( & V_48 -> V_96 ) ;
F_88 ( V_100 ) ;
return 0 ;
}
static int F_89 ( struct V_45 * V_46 , struct V_102 * V_102 , int V_103 )
{
struct V_104 * V_105 = (struct V_104 * ) V_102 ;
struct V_47 * V_48 = F_29 ( V_46 ) ;
struct V_5 * V_27 = V_48 -> V_49 ;
int V_32 = 0 ;
switch ( V_103 ) {
case V_106 :
if ( F_90 ( V_107 ) ) {
if ( V_48 -> V_95 ) {
V_32 = F_16 ( V_27 , V_105 -> V_108 ) ;
F_15 ( V_27 ) ;
} else {
F_62 ( & V_46 -> V_46 , L_10 ) ;
V_32 = 0 ;
}
}
break;
case V_109 :
V_32 = - V_110 ;
if ( F_90 ( V_107 ) ) {
F_91 ( V_46 , TRUE ) ;
V_32 = 0 ;
}
break;
case V_111 :
V_105 -> V_112 = F_28 ( V_46 ) ;
break;
default:
V_32 = - V_113 ;
break;
}
return V_32 ;
}
static struct V_114 * F_92 ( struct V_45 * V_46 )
{
struct V_47 * V_48 = F_29 ( V_46 ) ;
return & V_48 -> V_57 ;
}
static int F_93 ( struct V_45 * V_46 )
{
struct V_47 * V_48 = F_29 ( V_46 ) ;
struct V_5 * V_27 = V_48 -> V_49 ;
int V_115 ;
V_48 -> V_61 = 0 ;
V_48 -> V_31 = 9600 ;
F_94 ( & V_48 -> V_64 ) ;
V_115 = F_60 ( V_27 , V_46 ) ;
if ( V_115 )
goto V_116;
F_16 ( V_27 , 9600 ) ;
V_48 -> V_117 = F_95 ( V_46 , & V_48 -> V_118 , V_119 ) ;
if ( ! V_48 -> V_117 ) {
V_115 = - V_120 ;
goto V_121;
}
F_96 ( & V_48 -> V_96 , F_79 ) ;
V_48 -> V_95 = 1 ;
F_15 ( V_27 ) ;
F_97 ( V_46 ) ;
return 0 ;
V_121:
V_48 -> V_95 = 0 ;
F_70 ( V_27 , V_46 ) ;
V_116:
return V_115 ;
}
static int F_98 ( struct V_45 * V_46 )
{
struct V_47 * V_48 = F_29 ( V_46 ) ;
F_75 ( & V_48 -> V_96 ) ;
F_70 ( V_48 -> V_49 , V_46 ) ;
if ( V_48 -> V_122 ) {
F_88 ( V_48 -> V_122 ) ;
V_48 -> V_122 = NULL ;
}
if ( V_48 -> V_117 ) {
F_99 ( V_48 -> V_117 ) ;
V_48 -> V_117 = NULL ;
}
F_84 ( V_46 ) ;
V_48 -> V_95 = 0 ;
return 0 ;
}
static int F_100 ( T_4 * V_123 , int V_124 )
{
V_123 -> V_60 = F_101 ( V_124 , V_125 ) ;
if ( ! V_123 -> V_60 )
return - V_120 ;
V_123 -> V_101 = V_124 ;
V_123 -> V_126 = FALSE ;
V_123 -> V_51 = V_52 ;
V_123 -> V_56 = V_123 -> V_60 ;
return 0 ;
}
static int F_102 ( struct V_7 * V_8 )
{
struct V_45 * V_46 ;
struct V_47 * V_48 ;
unsigned int V_127 ;
struct V_5 * V_49 ;
int V_115 ;
if ( V_8 -> V_128 >= 0 && V_8 -> V_128 < F_103 ( V_129 ) && \
V_129 [ V_8 -> V_128 ] [ 3 ] == V_8 -> V_128 ) {
V_115 = F_104 ( V_129 [ V_8 -> V_128 ] , V_119 ) ;
if ( V_115 )
return V_115 ;
} else {
F_105 ( & V_8 -> V_46 , L_11 ) ;
return - V_130 ;
}
V_115 = - V_120 ;
V_49 = F_101 ( sizeof( * V_49 ) , V_125 ) ;
if ( ! V_49 )
goto V_131;
F_3 ( V_49 , V_8 ) ;
V_46 = F_106 ( sizeof( * V_48 ) ) ;
if ( ! V_46 )
goto V_132;
V_48 = F_29 ( V_46 ) ;
V_48 -> V_46 = & V_8 -> V_46 ;
V_48 -> V_49 = V_49 ;
V_49 -> V_46 = V_46 ;
V_115 = F_100 ( & V_48 -> V_50 , V_133 ) ;
if ( V_115 )
goto V_134;
V_115 = F_100 ( & V_48 -> V_54 , V_135 ) ;
if ( V_115 )
goto V_136;
V_46 -> V_137 = & V_138 ;
V_46 -> V_19 = V_49 -> V_19 ;
F_107 ( & V_48 -> V_118 ) ;
V_127 = V_139 ;
switch ( V_140 ) {
case 115200 :
V_127 |= V_141 ;
case 57600 :
V_127 |= V_142 ;
case 38400 :
V_127 |= V_143 ;
case 19200 :
V_127 |= V_144 ;
case 9600 :
break;
default:
F_62 ( & V_8 -> V_46 , L_12 ) ;
}
V_48 -> V_118 . V_145 . V_146 &= V_127 ;
V_48 -> V_118 . V_147 . V_146 = 1 ;
F_108 ( & V_48 -> V_118 ) ;
V_115 = F_109 ( V_46 ) ;
if ( V_115 ) {
F_110 ( V_48 -> V_54 . V_60 ) ;
V_136:
F_110 ( V_48 -> V_50 . V_60 ) ;
V_134:
F_111 ( V_46 ) ;
V_132:
F_110 ( V_49 ) ;
V_131:
F_112 ( V_129 [ V_8 -> V_128 ] ) ;
} else
F_113 ( V_8 , V_49 ) ;
return V_115 ;
}
static int F_114 ( struct V_7 * V_8 )
{
struct V_5 * V_49 ;
struct V_45 * V_46 = NULL ;
struct V_47 * V_48 ;
V_49 = F_74 ( V_8 ) ;
if ( ! V_49 )
return 0 ;
V_46 = V_49 -> V_46 ;
V_48 = F_29 ( V_46 ) ;
F_115 ( V_46 ) ;
F_110 ( V_48 -> V_54 . V_60 ) ;
F_110 ( V_48 -> V_50 . V_60 ) ;
F_111 ( V_46 ) ;
F_110 ( V_49 ) ;
return 0 ;
}
