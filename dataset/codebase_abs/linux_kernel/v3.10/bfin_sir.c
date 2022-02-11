static void F_1 ( unsigned long V_1 , int V_2 )
{
long V_3 ;
V_2 = V_2 < 10000 ? 10000 : V_2 ;
V_3 = 1 + V_2 / ( V_4 / V_5 ) ;
F_2 ( V_3 ) ;
}
static void F_3 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
int V_10 ;
struct V_11 * V_12 ;
for ( V_10 = 0 ; V_10 < V_9 -> V_13 ; V_10 ++ ) {
V_12 = & V_9 -> V_11 [ V_10 ] ;
switch ( V_12 -> V_14 ) {
case V_15 :
V_7 -> V_16 = ( void V_17 * ) V_12 -> V_18 ;
break;
case V_19 :
V_7 -> V_20 = V_12 -> V_18 ;
break;
case V_21 :
V_7 -> V_22 = V_12 -> V_18 ;
V_7 -> V_23 = V_12 -> V_24 ;
break;
default:
break;
}
}
V_7 -> V_25 = F_4 () ;
#ifdef F_5
V_7 -> V_26 = 1 ;
F_6 ( & ( V_7 -> V_27 ) ) ;
#endif
}
static void F_7 ( struct V_6 * V_28 )
{
#ifdef F_5
F_8 ( V_28 -> V_23 ) ;
#endif
while ( ! ( F_9 ( V_28 ) & V_29 ) ) {
F_10 () ;
continue;
}
F_11 ( V_28 , V_30 ) ;
}
static void F_12 ( struct V_6 * V_28 )
{
F_13 ( V_28 , V_30 ) ;
}
static void F_14 ( struct V_6 * V_28 )
{
F_11 ( V_28 , V_31 ) ;
}
static void F_15 ( struct V_6 * V_28 )
{
F_13 ( V_28 , V_31 ) ;
}
static int F_16 ( struct V_6 * V_28 , int V_32 )
{
int V_33 = - V_34 ;
unsigned int V_35 ;
unsigned short V_36 , V_37 , V_38 ;
static int V_39 ;
int V_40 = 10 ;
V_38 = F_17 ( 8 ) ;
switch ( V_32 ) {
case 9600 :
case 19200 :
case 38400 :
case 57600 :
case 115200 :
V_35 = ( V_28 -> V_25 + ( 8 * V_32 ) ) / ( 16 * V_32 ) ;
do {
F_18 ( V_39 ) ;
V_37 = F_9 ( V_28 ) ;
} while ( ! ( V_37 & V_41 ) && V_40 -- );
V_39 = 1000000 / V_32 + 1 ;
V_36 = F_19 ( V_28 ) ;
V_36 &= ~ V_42 ;
F_20 ( V_28 , V_36 ) ;
F_21 ( V_28 ) ;
F_22 () ;
F_23 ( V_28 , V_35 & 0xFF ) ;
F_24 ( V_28 , ( V_35 >> 8 ) & 0xFF ) ;
F_22 () ;
F_25 ( V_28 ) ;
F_22 () ;
F_26 ( V_28 , V_38 ) ;
V_36 = F_19 ( V_28 ) ;
V_36 |= V_42 ;
F_20 ( V_28 , V_36 ) ;
V_33 = 0 ;
break;
default:
F_27 ( V_43 L_1 , V_32 ) ;
break;
}
V_36 = F_19 ( V_28 ) ;
V_36 |= V_44 | V_45 ;
F_20 ( V_28 , V_36 ) ;
return V_33 ;
}
static int F_28 ( struct V_46 * V_47 )
{
struct V_48 * V_49 = F_29 ( V_47 ) ;
struct V_6 * V_28 = V_49 -> V_50 ;
if ( ! ( F_30 ( V_28 ) & V_31 ) )
return 0 ;
return V_49 -> V_51 . V_52 != V_53 ;
}
static void F_31 ( struct V_46 * V_47 )
{
unsigned int V_54 ;
struct V_48 * V_49 = F_29 ( V_47 ) ;
struct V_6 * V_28 = V_49 -> V_50 ;
if ( V_49 -> V_55 . V_56 != 0 ) {
V_54 = * ( V_49 -> V_55 . V_57 ) ;
F_32 ( V_28 , V_54 ) ;
V_49 -> V_55 . V_57 ++ ;
V_49 -> V_55 . V_56 -- ;
} else {
V_49 -> V_58 . V_59 ++ ;
V_49 -> V_58 . V_60 += V_49 -> V_55 . V_57 - V_49 -> V_55 . V_61 ;
if ( V_49 -> V_62 ) {
F_16 ( V_28 , V_49 -> V_62 ) ;
V_49 -> V_32 = V_49 -> V_62 ;
V_49 -> V_62 = 0 ;
}
F_7 ( V_28 ) ;
F_15 ( V_28 ) ;
F_33 ( V_47 ) ;
}
}
static void F_34 ( struct V_46 * V_47 )
{
struct V_48 * V_49 = F_29 ( V_47 ) ;
struct V_6 * V_28 = V_49 -> V_50 ;
unsigned char V_63 ;
F_35 ( V_28 ) ;
V_63 = F_36 ( V_28 ) ;
F_37 ( V_47 , & V_49 -> V_58 , & V_49 -> V_51 , V_63 ) ;
V_47 -> V_64 = V_65 ;
}
static T_1 F_38 ( int V_20 , void * V_66 )
{
struct V_46 * V_47 = V_66 ;
struct V_48 * V_49 = F_29 ( V_47 ) ;
struct V_6 * V_28 = V_49 -> V_50 ;
F_39 ( & V_49 -> V_67 ) ;
while ( ( F_9 ( V_28 ) & V_68 ) )
F_34 ( V_47 ) ;
F_40 ( & V_49 -> V_67 ) ;
return V_69 ;
}
static T_1 F_41 ( int V_20 , void * V_66 )
{
struct V_46 * V_47 = V_66 ;
struct V_48 * V_49 = F_29 ( V_47 ) ;
struct V_6 * V_28 = V_49 -> V_50 ;
F_39 ( & V_49 -> V_67 ) ;
if ( F_9 ( V_28 ) & V_29 )
F_31 ( V_47 ) ;
F_40 ( & V_49 -> V_67 ) ;
return V_69 ;
}
static void F_42 ( struct V_46 * V_47 )
{
struct V_48 * V_49 = F_29 ( V_47 ) ;
struct V_6 * V_28 = V_49 -> V_50 ;
if ( ! V_28 -> V_26 )
return;
V_28 -> V_26 = 0 ;
if ( V_49 -> V_55 . V_56 == 0 ) {
V_49 -> V_58 . V_59 ++ ;
if ( V_49 -> V_62 ) {
F_16 ( V_28 , V_49 -> V_62 ) ;
V_49 -> V_32 = V_49 -> V_62 ;
V_49 -> V_62 = 0 ;
}
F_15 ( V_28 ) ;
V_28 -> V_26 = 1 ;
F_33 ( V_47 ) ;
return;
}
F_43 ( ( unsigned long ) ( V_49 -> V_55 . V_57 ) ,
( unsigned long ) ( V_49 -> V_55 . V_57 + V_49 -> V_55 . V_56 ) ) ;
F_44 ( V_28 -> V_23 ,
F_45 ( V_70 , V_71 ,
V_72 , V_73 , V_74 ,
V_75 ) ) ;
F_46 ( V_28 -> V_23 ,
( unsigned long ) ( V_49 -> V_55 . V_57 ) ) ;
F_47 ( V_28 -> V_23 , V_49 -> V_55 . V_56 ) ;
F_48 ( V_28 -> V_23 , 1 ) ;
F_49 ( V_28 -> V_23 ) ;
}
static T_1 F_50 ( int V_20 , void * V_66 )
{
struct V_46 * V_47 = V_66 ;
struct V_48 * V_49 = F_29 ( V_47 ) ;
struct V_6 * V_28 = V_49 -> V_50 ;
F_39 ( & V_49 -> V_67 ) ;
if ( ! ( F_51 ( V_28 -> V_23 ) & V_76 ) ) {
F_52 ( V_28 -> V_23 ) ;
F_7 ( V_28 ) ;
V_49 -> V_58 . V_59 ++ ;
V_49 -> V_58 . V_60 += V_49 -> V_55 . V_56 ;
V_49 -> V_55 . V_56 = 0 ;
if ( V_49 -> V_62 ) {
F_16 ( V_28 , V_49 -> V_62 ) ;
V_49 -> V_32 = V_49 -> V_62 ;
V_49 -> V_62 = 0 ;
}
F_15 ( V_28 ) ;
F_33 ( V_47 ) ;
V_28 -> V_26 = 1 ;
}
F_40 ( & V_49 -> V_67 ) ;
return V_69 ;
}
static void F_53 ( struct V_46 * V_47 )
{
struct V_48 * V_49 = F_29 ( V_47 ) ;
struct V_6 * V_28 = V_49 -> V_50 ;
int V_10 ;
F_35 ( V_28 ) ;
for ( V_10 = V_28 -> V_77 . V_61 ; V_10 < V_28 -> V_77 . V_78 ; V_10 ++ )
F_37 ( V_47 , & V_49 -> V_58 , & V_49 -> V_51 , V_28 -> V_77 . V_79 [ V_10 ] ) ;
}
void F_54 ( struct V_46 * V_47 )
{
struct V_48 * V_49 = F_29 ( V_47 ) ;
struct V_6 * V_28 = V_49 -> V_50 ;
int V_80 , V_81 ;
unsigned long V_14 ;
F_55 ( & V_49 -> V_67 , V_14 ) ;
V_80 = V_82 - F_56 ( V_28 -> V_22 ) ;
if ( V_80 == V_82 )
V_80 = 0 ;
V_81 = V_28 -> V_83 * V_82 + V_80 ;
if ( V_81 > V_28 -> V_77 . V_78 ) {
V_28 -> V_77 . V_78 = V_81 ;
F_53 ( V_47 ) ;
V_28 -> V_77 . V_61 = V_28 -> V_77 . V_78 ;
}
F_57 ( & V_49 -> V_67 , V_14 ) ;
}
static T_1 F_58 ( int V_20 , void * V_66 )
{
struct V_46 * V_47 = V_66 ;
struct V_48 * V_49 = F_29 ( V_47 ) ;
struct V_6 * V_28 = V_49 -> V_50 ;
unsigned short V_84 ;
F_39 ( & V_49 -> V_67 ) ;
V_28 -> V_83 ++ ;
V_28 -> V_77 . V_78 = V_82 * V_28 -> V_83 ;
F_53 ( V_47 ) ;
if ( V_28 -> V_83 >= V_85 ) {
V_28 -> V_83 = 0 ;
V_28 -> V_77 . V_78 = 0 ;
}
V_28 -> V_77 . V_61 = V_28 -> V_77 . V_78 ;
V_84 = F_51 ( V_28 -> V_22 ) ;
F_52 ( V_28 -> V_22 ) ;
F_40 ( & V_49 -> V_67 ) ;
F_59 ( & V_28 -> V_27 , V_65 + V_86 ) ;
return V_69 ;
}
static int F_60 ( struct V_6 * V_28 , struct V_46 * V_47 )
{
#ifdef F_5
T_2 V_87 ;
#endif
if ( F_61 ( V_28 -> V_22 , L_2 ) < 0 ) {
F_62 ( & V_47 -> V_47 , L_3 ) ;
return - V_88 ;
}
if ( F_61 ( V_28 -> V_23 , L_4 ) < 0 ) {
F_62 ( & V_47 -> V_47 , L_5 ) ;
F_63 ( V_28 -> V_22 ) ;
return - V_88 ;
}
#ifdef F_5
F_64 ( V_28 -> V_22 , F_58 , V_47 ) ;
F_64 ( V_28 -> V_23 , F_50 , V_47 ) ;
V_28 -> V_77 . V_79 = F_65 ( NULL , V_89 ,
& V_87 , V_90 ) ;
V_28 -> V_77 . V_61 = 0 ;
V_28 -> V_77 . V_78 = 0 ;
V_28 -> V_83 = 0 ;
F_44 ( V_28 -> V_22 ,
F_45 ( V_91 , V_92 ,
V_93 , V_94 ,
V_74 , V_75 ) ) ;
F_47 ( V_28 -> V_22 , V_82 ) ;
F_48 ( V_28 -> V_22 , 1 ) ;
F_66 ( V_28 -> V_22 , V_85 ) ;
F_67 ( V_28 -> V_22 , 1 ) ;
F_46 ( V_28 -> V_22 , ( unsigned long ) V_28 -> V_77 . V_79 ) ;
F_49 ( V_28 -> V_22 ) ;
V_28 -> V_27 . V_57 = ( unsigned long ) ( V_47 ) ;
V_28 -> V_27 . V_95 = ( void * ) F_54 ;
#else
if ( F_68 ( V_28 -> V_20 , F_38 , V_96 , L_6 , V_47 ) ) {
F_62 ( & V_47 -> V_47 , L_7 ) ;
return - V_88 ;
}
if ( F_68 ( V_28 -> V_20 + 1 , F_41 , V_96 , L_8 , V_47 ) ) {
F_62 ( & V_47 -> V_47 , L_9 ) ;
F_69 ( V_28 -> V_20 , V_47 ) ;
return - V_88 ;
}
#endif
return 0 ;
}
static void F_70 ( struct V_6 * V_28 , struct V_46 * V_47 )
{
unsigned short V_36 ;
F_14 ( V_28 ) ;
V_36 = F_19 ( V_28 ) ;
V_36 &= ~ ( V_42 | V_97 | V_45 ) ;
F_20 ( V_28 , V_36 ) ;
#ifdef F_5
F_8 ( V_28 -> V_23 ) ;
F_8 ( V_28 -> V_22 ) ;
F_71 ( & ( V_28 -> V_27 ) ) ;
F_72 ( NULL , V_89 , V_28 -> V_77 . V_79 , 0 ) ;
#else
F_69 ( V_28 -> V_20 + 1 , V_47 ) ;
F_69 ( V_28 -> V_20 , V_47 ) ;
#endif
F_63 ( V_28 -> V_23 ) ;
F_63 ( V_28 -> V_22 ) ;
}
static int F_73 ( struct V_8 * V_9 , T_3 V_52 )
{
struct V_6 * V_50 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
V_50 = F_74 ( V_9 ) ;
if ( ! V_50 )
return 0 ;
V_47 = V_50 -> V_47 ;
V_49 = F_29 ( V_47 ) ;
if ( V_49 -> V_98 ) {
F_75 ( & V_49 -> V_99 ) ;
F_70 ( V_49 -> V_50 , V_47 ) ;
F_76 ( V_47 ) ;
}
return 0 ;
}
static int F_77 ( struct V_8 * V_9 )
{
struct V_6 * V_50 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_6 * V_28 ;
V_50 = F_74 ( V_9 ) ;
if ( ! V_50 )
return 0 ;
V_47 = V_50 -> V_47 ;
V_49 = F_29 ( V_47 ) ;
V_28 = V_49 -> V_50 ;
if ( V_49 -> V_98 ) {
if ( V_49 -> V_62 ) {
V_49 -> V_32 = V_49 -> V_62 ;
V_49 -> V_62 = 0 ;
}
F_60 ( V_28 , V_47 ) ;
F_16 ( V_28 , 9600 ) ;
F_15 ( V_28 ) ;
F_78 ( V_47 ) ;
}
return 0 ;
}
static void F_79 ( struct V_100 * V_99 )
{
struct V_48 * V_49 = F_80 ( V_99 , struct V_48 , V_99 ) ;
struct V_46 * V_47 = V_49 -> V_50 -> V_47 ;
struct V_6 * V_28 = V_49 -> V_50 ;
unsigned short V_36 ;
int V_101 = 10 ;
while ( F_28 ( V_47 ) && -- V_101 )
F_1 ( V_47 -> V_64 , V_49 -> V_2 ) ;
F_14 ( V_28 ) ;
V_36 = F_19 ( V_28 ) ;
V_36 &= ~ ( V_97 | V_45 ) ;
F_20 ( V_28 , V_36 ) ;
F_22 () ;
V_36 |= V_44 | V_45 ;
F_20 ( V_28 , V_36 ) ;
F_22 () ;
#ifdef F_5
F_42 ( V_47 ) ;
#endif
F_12 ( V_28 ) ;
V_47 -> V_102 = V_65 ;
}
static int F_81 ( struct V_103 * V_104 , struct V_46 * V_47 )
{
struct V_48 * V_49 = F_29 ( V_47 ) ;
int V_32 = F_82 ( V_104 ) ;
F_83 ( V_47 ) ;
V_49 -> V_2 = F_84 ( V_104 ) ;
if ( V_32 != V_49 -> V_32 && V_32 != - 1 )
V_49 -> V_62 = V_32 ;
V_49 -> V_55 . V_57 = V_49 -> V_55 . V_61 ;
if ( V_104 -> V_56 == 0 )
V_49 -> V_55 . V_56 = 0 ;
else
V_49 -> V_55 . V_56 = F_85 ( V_104 , V_49 -> V_55 . V_57 , V_49 -> V_55 . V_105 ) ;
F_86 ( & V_49 -> V_99 ) ;
F_87 ( V_104 ) ;
return 0 ;
}
static int F_88 ( struct V_46 * V_47 , struct V_106 * V_106 , int V_107 )
{
struct V_108 * V_109 = (struct V_108 * ) V_106 ;
struct V_48 * V_49 = F_29 ( V_47 ) ;
struct V_6 * V_28 = V_49 -> V_50 ;
int V_33 = 0 ;
switch ( V_107 ) {
case V_110 :
if ( F_89 ( V_111 ) ) {
if ( V_49 -> V_98 ) {
V_33 = F_16 ( V_28 , V_109 -> V_112 ) ;
F_15 ( V_28 ) ;
} else {
F_62 ( & V_47 -> V_47 , L_10 ) ;
V_33 = 0 ;
}
}
break;
case V_113 :
V_33 = - V_114 ;
if ( F_89 ( V_111 ) ) {
F_90 ( V_47 , TRUE ) ;
V_33 = 0 ;
}
break;
case V_115 :
V_109 -> V_116 = F_28 ( V_47 ) ;
break;
default:
V_33 = - V_117 ;
break;
}
return V_33 ;
}
static struct V_118 * F_91 ( struct V_46 * V_47 )
{
struct V_48 * V_49 = F_29 ( V_47 ) ;
return & V_49 -> V_58 ;
}
static int F_92 ( struct V_46 * V_47 )
{
struct V_48 * V_49 = F_29 ( V_47 ) ;
struct V_6 * V_28 = V_49 -> V_50 ;
int V_119 ;
V_49 -> V_62 = 0 ;
V_49 -> V_32 = 9600 ;
F_93 ( & V_49 -> V_67 ) ;
V_119 = F_60 ( V_28 , V_47 ) ;
if ( V_119 )
goto V_120;
F_16 ( V_28 , 9600 ) ;
V_49 -> V_121 = F_94 ( V_47 , & V_49 -> V_122 , V_123 ) ;
if ( ! V_49 -> V_121 ) {
V_119 = - V_124 ;
goto V_125;
}
F_95 ( & V_49 -> V_99 , F_79 ) ;
V_49 -> V_98 = 1 ;
F_15 ( V_28 ) ;
F_96 ( V_47 ) ;
return 0 ;
V_125:
V_49 -> V_98 = 0 ;
F_70 ( V_28 , V_47 ) ;
V_120:
return V_119 ;
}
static int F_97 ( struct V_46 * V_47 )
{
struct V_48 * V_49 = F_29 ( V_47 ) ;
F_75 ( & V_49 -> V_99 ) ;
F_70 ( V_49 -> V_50 , V_47 ) ;
if ( V_49 -> V_126 ) {
F_87 ( V_49 -> V_126 ) ;
V_49 -> V_126 = NULL ;
}
if ( V_49 -> V_121 ) {
F_98 ( V_49 -> V_121 ) ;
V_49 -> V_121 = NULL ;
}
F_83 ( V_47 ) ;
V_49 -> V_98 = 0 ;
return 0 ;
}
static int F_99 ( T_4 * V_127 , int V_128 )
{
V_127 -> V_61 = F_100 ( V_128 , V_129 ) ;
if ( ! V_127 -> V_61 )
return - V_124 ;
V_127 -> V_105 = V_128 ;
V_127 -> V_130 = FALSE ;
V_127 -> V_52 = V_53 ;
V_127 -> V_57 = V_127 -> V_61 ;
return 0 ;
}
static int F_101 ( struct V_8 * V_9 )
{
struct V_46 * V_47 ;
struct V_48 * V_49 ;
unsigned int V_131 ;
struct V_6 * V_50 ;
int V_119 ;
if ( V_9 -> V_132 >= 0 && V_9 -> V_132 < F_102 ( V_133 ) && \
V_133 [ V_9 -> V_132 ] [ 3 ] == V_9 -> V_132 ) {
V_119 = F_103 ( V_133 [ V_9 -> V_132 ] , V_123 ) ;
if ( V_119 )
return V_119 ;
} else {
F_104 ( & V_9 -> V_47 , L_11 ) ;
return - V_134 ;
}
V_119 = - V_124 ;
V_50 = F_100 ( sizeof( * V_50 ) , V_129 ) ;
if ( ! V_50 )
goto V_135;
F_3 ( V_50 , V_9 ) ;
V_47 = F_105 ( sizeof( * V_49 ) ) ;
if ( ! V_47 )
goto V_136;
V_49 = F_29 ( V_47 ) ;
V_49 -> V_47 = & V_9 -> V_47 ;
V_49 -> V_50 = V_50 ;
V_50 -> V_47 = V_47 ;
V_119 = F_99 ( & V_49 -> V_51 , V_137 ) ;
if ( V_119 )
goto V_138;
V_119 = F_99 ( & V_49 -> V_55 , V_139 ) ;
if ( V_119 )
goto V_140;
V_47 -> V_141 = & V_142 ;
V_47 -> V_20 = V_50 -> V_20 ;
F_106 ( & V_49 -> V_122 ) ;
V_131 = V_143 ;
switch ( V_144 ) {
case 115200 :
V_131 |= V_145 ;
case 57600 :
V_131 |= V_146 ;
case 38400 :
V_131 |= V_147 ;
case 19200 :
V_131 |= V_148 ;
case 9600 :
break;
default:
F_62 ( & V_9 -> V_47 , L_12 ) ;
}
V_49 -> V_122 . V_149 . V_150 &= V_131 ;
V_49 -> V_122 . V_151 . V_150 = 1 ;
F_107 ( & V_49 -> V_122 ) ;
V_119 = F_108 ( V_47 ) ;
if ( V_119 ) {
F_109 ( V_49 -> V_55 . V_61 ) ;
V_140:
F_109 ( V_49 -> V_51 . V_61 ) ;
V_138:
F_110 ( V_47 ) ;
V_136:
F_109 ( V_50 ) ;
V_135:
F_111 ( V_133 [ V_9 -> V_132 ] ) ;
} else
F_112 ( V_9 , V_50 ) ;
return V_119 ;
}
static int F_113 ( struct V_8 * V_9 )
{
struct V_6 * V_50 ;
struct V_46 * V_47 = NULL ;
struct V_48 * V_49 ;
V_50 = F_74 ( V_9 ) ;
if ( ! V_50 )
return 0 ;
V_47 = V_50 -> V_47 ;
V_49 = F_29 ( V_47 ) ;
F_114 ( V_47 ) ;
F_109 ( V_49 -> V_55 . V_61 ) ;
F_109 ( V_49 -> V_51 . V_61 ) ;
F_110 ( V_47 ) ;
F_109 ( V_50 ) ;
F_112 ( V_9 , NULL ) ;
return 0 ;
}
