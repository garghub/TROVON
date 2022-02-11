static int F_1 ( int V_1 , int V_2 , int V_3 )
{
T_1 V_4 = 0 ;
switch ( V_2 ) {
case 0 :
break;
case 33 :
V_4 |= V_5 ;
break;
case 50 :
V_4 |= V_6 ;
break;
default:
return 1 ;
}
switch ( V_3 ) {
case 0 :
break;
case 33 :
case 50 :
if ( V_2 == V_3 )
V_4 |= V_7 ;
else
return 1 ;
break;
case 120 :
V_4 |= V_8 ;
default:
return 1 ;
}
if ( ! ( ( V_2 == 50 ) || ( V_2 == 0 ) ) )
return 1 ;
F_2 ( ( ( T_1 * ) V_9 ) ,
F_3 ( ( ( T_1 * ) V_9 ) ) & ~ ( V_5 |
V_6 |
V_7 |
V_8 ) ) ;
F_2 ( ( ( T_1 * ) V_9 ) , F_3 ( ( ( T_1 * ) V_9 ) ) | V_4 ) ;
return 0 ;
}
static int F_1 ( int V_1 , int V_2 , int V_3 )
{
T_1 V_4 = 0 ;
switch ( V_2 ) {
case 0 :
break;
case 33 :
V_4 |= V_10 ;
break;
case 50 :
V_4 |= V_11 ;
break;
default:
return 1 ;
}
switch ( V_3 ) {
case 0 :
break;
case 33 :
case 50 :
if ( V_2 == V_3 )
V_4 |= V_12 ;
else
return 1 ;
break;
case 120 :
if ( ( V_2 == 33 ) || ( V_2 == 50 ) )
V_4 |= V_13 ;
else
return 1 ;
default:
return 1 ;
}
F_2 ( ( T_1 * ) V_14 ,
F_3 ( ( T_1 * ) V_14 ) & ~ ( V_15 |
V_16 ) ) ;
F_2 ( ( T_1 * ) V_14 , F_3 ( ( T_1 * ) V_14 ) | V_4 ) ;
return 0 ;
}
static void F_4 ( int V_1 )
{
F_2 ( ( T_1 * ) V_14 , F_3 ( ( T_1 * ) V_14 ) & ~ V_17 ) ;
}
static void F_5 ( int V_1 )
{
F_2 ( ( T_1 * ) V_14 , F_3 ( ( T_1 * ) V_14 ) | V_17 ) ;
}
static inline void F_4 ( int V_1 )
{
V_18 . V_19 ( V_1 , 1 ) ;
}
static inline void F_5 ( int V_1 )
{
V_18 . V_19 ( V_1 , 0 ) ;
}
static inline int F_1 ( int V_1 , int V_2 , int V_3 )
{
return V_18 . F_1 ( V_1 , V_2 , V_3 ) ;
}
static int F_1 ( int V_1 , int V_2 , int V_3 )
{
T_2 V_4 = 0 ;
switch ( V_2 ) {
case 0 :
break;
case 33 :
V_4 |= V_20 ;
break;
case 50 :
V_4 |= V_21 ;
break;
default:
return 1 ;
}
switch ( V_3 ) {
case 0 :
break;
case 33 :
case 50 :
if ( V_2 == V_3 )
V_4 |= V_22 ;
else
return 1 ;
break;
case 120 :
if ( ( V_2 == 33 ) || ( V_2 == 50 ) )
V_4 |= V_23 ;
else
return 1 ;
default:
return 1 ;
}
F_6 ( ( T_2 * ) V_24 ,
F_7 ( ( T_2 * ) V_24 ) & ~ ( V_25 | V_26 ) ) ;
F_6 ( ( T_2 * ) V_24 , F_7 ( ( T_2 * ) V_24 ) | V_4 ) ;
return 0 ;
}
static int F_1 ( int V_1 , int V_2 , int V_3 )
{
T_2 V_4 = 0 ;
T_2 V_27 ;
T_3 * V_28 = F_8 () ;
switch ( V_2 ) {
case 0 :
break;
case 33 :
V_4 |= V_29 ;
break;
case 50 :
V_4 |= V_30 ;
break;
default:
return 1 ;
}
switch ( V_3 ) {
case 0 :
break;
case 33 :
case 50 :
if ( V_2 == V_3 )
V_4 |= V_31 ;
else
return 1 ;
break;
case 120 :
if ( ( V_2 == 33 ) || ( V_2 == 50 ) )
V_4 |= V_32 ;
else
return 1 ;
default:
return 1 ;
}
V_4 = V_4 >> ( V_1 << 2 ) ;
V_27 = F_7 ( & V_28 -> V_33 ) ;
if ( V_4 !=
( V_27 & ( ( V_34 | V_35 ) >> ( V_1 << 2 ) ) ) ) {
V_27 =
V_27 & ~ ( ( V_34 | V_35 ) >>
( V_1 << 2 ) ) ;
F_6 ( & V_28 -> V_33 , V_4 | V_27 ) ;
F_9 ( 100 ) ;
}
return 0 ;
}
static T_4 F_10 ( int V_36 , void * V_37 )
{
struct V_38 * V_39 ;
struct V_40 * V_41 ;
unsigned int V_42 , V_43 , V_44 , V_45 , V_46 ;
T_5 * V_47 = V_48 [ 0 ] . V_47 ;
F_11 ( L_1 ) ;
V_44 = F_3 ( & V_47 -> V_49 ) ;
V_45 = F_3 ( & V_47 -> V_50 ) ;
V_46 = F_3 ( & V_47 -> V_51 ) ;
for ( V_42 = 0 ; V_42 < V_52 ; V_42 ++ ) {
V_39 = & V_48 [ V_42 ] ;
V_41 = & V_39 -> V_43 [ 0 ] ;
V_43 = 0 ;
while ( V_41 -> V_53 ) {
if ( V_44 & V_41 -> V_53 )
V_43 |= V_41 -> V_54 ;
V_41 ++ ;
}
if ( V_43 & V_55 )
if ( ( ( V_45 & F_12 ( V_42 ) ) >> 1 ) ^
( V_45 & F_13 ( V_42 ) ) ) {
V_43 &= ~ V_55 ;
}
#ifdef F_14
if ( ( V_43 & V_55 ) &&
( ( V_45 &
( F_12 ( V_42 ) | F_13 ( V_42 ) ) ) == 0 ) &&
( V_39 -> V_56 . V_57 | V_39 -> V_56 . V_58 ) ) {
V_43 &= ~ V_55 ;
}
#endif
F_11 ( L_2
L_3 , V_42 , V_43 , V_44 , V_45 ) ;
if ( V_43 ) {
F_15 ( & V_59 ) ;
V_60 [ V_42 ] |= V_43 ;
F_16 ( & V_59 ) ;
V_46 &= ~ F_17 ( 0 ) ;
V_46 &= ~ F_17 ( 1 ) ;
F_2 ( & V_47 -> V_51 , V_46 ) ;
if ( V_43 )
F_18 ( & V_48 [ V_42 ] . V_48 , V_43 ) ;
}
}
F_2 ( & V_47 -> V_49 , V_44 ) ;
F_11 ( L_4 ) ;
return V_61 ;
}
static T_1 F_19 ( T_1 V_62 )
{
T_1 V_63 ;
for ( V_63 = 0 ; V_63 < V_64 ; V_63 ++ )
if ( V_65 [ V_63 ] == V_62 )
break;
if ( ( V_63 == V_64 ) || ( V_65 [ V_63 ] == - 1 ) )
V_63 = - 1 ;
return V_63 ;
}
static T_1 F_20 ( T_1 V_66 , T_1 V_67 , T_1 V_68 )
{
T_1 V_4 , V_69 , V_70 , V_71 , V_72 ;
if ( ! V_66 ) {
if ( V_67 )
V_66 = 255 ;
else
V_66 = 100 ;
}
#define F_21 180
V_69 = ( ( V_68 / 1000 ) * V_66 ) / 1000 ;
V_69 = ( V_69 * F_21 ) / ( 100 * 1000 ) ;
if ( V_69 >= V_73 ) {
F_22 ( L_5 ) ;
V_69 = V_73 - 1 ;
}
V_70 = V_69 / 7 ;
V_72 = V_69 / 7 ;
V_71 = ( V_69 * 5 ) / 7 ;
V_70 += V_69 - ( V_70 + V_72 + V_71 ) ;
V_4 = V_70 << 12 ;
V_4 |= V_71 << 7 ;
V_4 |= V_72 << 16 ;
return V_4 ;
}
static int F_23 ( struct V_74 * V_75 , unsigned int * V_76 )
{
int V_77 = F_24 ( V_75 , struct V_38 , V_48 ) -> V_1 ;
struct V_38 * V_39 = & V_48 [ V_77 ] ;
unsigned int V_45 , V_4 ;
T_5 * V_47 = V_39 -> V_47 ;
V_45 = F_3 ( & V_47 -> V_50 ) ;
* V_76 = ( ( V_45 & ( F_13 ( V_77 )
| F_12 ( V_77 ) ) ) == 0 ) ? V_55 : 0 ;
* V_76 |= ( V_45 & F_25 ( V_77 ) ) ? V_78 : 0 ;
if ( V_39 -> V_56 . V_79 & V_80 )
* V_76 |= ( V_45 & F_26 ( V_77 ) ) ? V_81 : 0 ;
else {
* V_76 |= ( V_45 & F_27 ( V_77 ) ) ? V_82 : 0 ;
* V_76 |= ( V_45 & F_26 ( V_77 ) ) ? V_83 : 0 ;
* V_76 |= ( V_45 & F_28 ( V_77 ) ) ? V_84 : 0 ;
}
if ( V_39 -> V_56 . V_57 | V_39 -> V_56 . V_58 )
* V_76 |= V_85 ;
V_4 = ( V_45 & F_29 ( V_77 ) )
>> F_30 ( V_77 ) ;
if ( F_31 ( V_77 ) == V_86 ) {
switch ( V_4 ) {
case 1 :
* V_76 |= V_87 ;
break;
case 2 :
* V_76 |= V_88 ;
break;
} ;
}
F_11 ( L_6 , V_77 , * V_76 ) ;
return 0 ;
}
static int F_32 ( struct V_74 * V_75 , T_6 * V_56 )
{
int V_77 = F_24 ( V_75 , struct V_38 , V_48 ) -> V_1 ;
struct V_38 * V_39 = & V_48 [ V_77 ] ;
struct V_40 * V_41 ;
unsigned int V_4 ;
unsigned long V_79 ;
T_5 * V_47 = V_48 [ 0 ] . V_47 ;
F_11 ( L_7
L_8 , V_77 , V_56 -> V_79 ,
V_56 -> V_57 , V_56 -> V_58 , V_56 -> V_89 , V_56 -> V_90 ) ;
if ( F_1 ( V_77 , V_56 -> V_57 , V_56 -> V_58 ) )
return - V_91 ;
if ( V_56 -> V_79 & V_92 )
F_2 ( F_33 ( V_77 ) , F_3 ( F_33 ( V_77 ) ) | V_93 ) ;
else
F_2 ( F_33 ( V_77 ) ,
F_3 ( F_33 ( V_77 ) ) & ~ V_93 ) ;
if ( V_56 -> V_57 || V_56 -> V_58 )
F_2 ( F_33 ( V_77 ) , F_3 ( F_33 ( V_77 ) ) & ~ V_94 ) ;
else
F_2 ( F_33 ( V_77 ) ,
F_3 ( F_33 ( V_77 ) ) | V_94 ) ;
F_34 ( & V_95 , V_79 ) ;
V_41 = & V_39 -> V_43 [ 0 ] ;
V_4 = 0 ;
if ( V_56 -> V_90 & V_55 ) {
V_41 -> V_54 = V_55 ;
V_4 |= V_41 -> V_53 = ( F_12 ( V_77 )
| F_13 ( V_77 ) ) ;
V_41 ++ ;
}
if ( V_56 -> V_79 & V_80 ) {
if ( V_56 -> V_90 & V_81 ) {
V_41 -> V_54 = V_81 ;
V_4 |= V_41 -> V_53 = F_26 ( V_77 ) ;
V_41 ++ ;
}
if ( V_56 -> V_89 ) {
F_2 ( F_33 ( V_77 ) ,
F_3 ( F_33 ( V_77 ) ) |
F_35 ( V_39 -> V_96 ) << 24 ) ;
V_4 |= F_17 ( V_77 ) ;
} else
F_2 ( F_33 ( V_77 ) ,
F_3 ( F_33 ( V_77 ) ) & 0x00ffffff ) ;
} else {
if ( V_56 -> V_90 & V_83 ) {
V_41 -> V_54 = V_83 ;
V_4 |= V_41 -> V_53 = F_26 ( V_77 ) ;
V_41 ++ ;
}
if ( V_56 -> V_90 & V_84 ) {
V_41 -> V_54 = V_84 ;
V_4 |= V_41 -> V_53 = F_28 ( V_77 ) ;
V_41 ++ ;
}
if ( V_56 -> V_90 & V_82 ) {
V_41 -> V_54 = V_82 ;
V_4 |= V_41 -> V_53 = 0 ;
V_41 ++ ;
}
}
V_41 -> V_53 = 0 ;
F_2 ( & V_47 -> V_49 , V_4 ) ;
V_4 |=
F_3 ( & V_47 ->
V_51 ) & ( F_36 ( 0 ) | F_36 ( 1 ) ) ;
F_2 ( & V_47 -> V_51 , V_4 ) ;
F_37 ( & V_95 , V_79 ) ;
V_39 -> V_56 = * V_56 ;
return 0 ;
}
static int F_38 ( struct V_74 * V_75 , struct V_97 * V_98 )
{
int V_77 = F_24 ( V_75 , struct V_38 , V_48 ) -> V_1 ;
struct V_38 * V_39 = & V_48 [ V_77 ] ;
struct V_99 * V_100 ;
unsigned int V_4 , V_101 ;
T_5 * V_47 = V_39 -> V_47 ;
#define F_39 (io->stop - io->start + 1)
#define F_40 (PCMCIA_IO_WIN_BASE + io->start)
F_11 ( L_9
L_10 , V_77 , V_98 -> V_102 , V_98 -> V_79 ,
V_98 -> V_103 , ( unsigned long long ) V_98 -> V_104 ,
( unsigned long long ) V_98 -> V_105 ) ;
if ( ( V_98 -> V_102 >= V_106 ) || ( V_98 -> V_104 > 0xffff )
|| ( V_98 -> V_105 > 0xffff ) || ( V_98 -> V_105 < V_98 -> V_104 ) )
return - V_91 ;
if ( ( V_4 = F_19 ( F_39 ) ) == - 1 )
return - V_91 ;
if ( V_98 -> V_79 & V_107 ) {
F_11 ( L_11 ) ;
V_101 = ( V_108 * V_52 )
+ ( V_77 * V_106 ) + V_98 -> V_102 ;
V_100 = ( void * ) & V_47 -> V_109 ;
V_100 += V_101 ;
F_2 ( & V_100 -> V_110 , 0 ) ;
F_2 ( & V_100 -> V_111 , F_40 ) ;
V_4 <<= 27 ;
V_4 |= V_112 | ( V_77 << 2 ) ;
V_4 |= F_20 ( V_98 -> V_103 , 1 , V_39 -> V_68 ) ;
if ( V_98 -> V_79 & V_113 )
V_4 |= V_114 ;
if ( V_98 -> V_79 & V_115 )
V_4 |= V_116 ;
if ( V_98 -> V_79 & V_107 )
V_4 |= V_117 ;
F_2 ( & V_100 -> V_110 , V_4 ) ;
F_11 ( L_12
L_13 , V_77 , V_98 -> V_102 , V_100 -> V_111 , V_100 -> V_110 ) ;
} else {
V_101 = ( V_108 * V_52 )
+ ( V_77 * V_106 ) + V_98 -> V_102 ;
V_100 = ( void * ) & V_47 -> V_109 ;
V_100 += V_101 ;
F_2 ( & V_100 -> V_110 , 0 ) ;
F_2 ( & V_100 -> V_111 , 0 ) ;
F_11 ( L_14
L_13 , V_77 , V_98 -> V_102 , V_100 -> V_111 , V_100 -> V_110 ) ;
}
V_39 -> V_118 [ V_98 -> V_102 ] = * V_98 ;
V_39 -> V_118 [ V_98 -> V_102 ] . V_79 &= ( V_113 | V_115 | V_107 ) ;
F_11 ( L_15 ) ;
return 0 ;
}
static int F_41 ( struct V_74 * V_75 ,
struct V_119 * V_120 )
{
int V_77 = F_24 ( V_75 , struct V_38 , V_48 ) -> V_1 ;
struct V_38 * V_39 = & V_48 [ V_77 ] ;
struct V_99 * V_100 ;
struct V_119 * V_121 ;
unsigned int V_4 , V_101 ;
T_5 * V_47 = V_39 -> V_47 ;
F_11 ( L_16
L_17 , V_77 , V_120 -> V_102 , V_120 -> V_79 ,
V_120 -> V_103 , ( unsigned long long ) V_120 -> V_122 ,
V_120 -> V_123 ) ;
if ( ( V_120 -> V_102 >= V_108 )
|| ( V_120 -> V_123 >= 0x04000000 )
|| ( V_120 -> V_122 & 0xfff )
|| ( V_120 -> V_123 & 0xfff ) )
return - V_91 ;
if ( ( V_4 = F_19 ( V_124 ) ) == - 1 ) {
F_22 ( L_18 , V_124 ) ;
return - V_91 ;
}
V_4 <<= 27 ;
V_101 = ( V_77 * V_108 ) + V_120 -> V_102 ;
V_100 = ( void * ) & V_47 -> V_109 ;
V_100 += V_101 ;
V_4 |= V_77 << 2 ;
V_4 |= F_20 ( V_120 -> V_103 , 0 , V_39 -> V_68 ) ;
if ( V_120 -> V_79 & V_125 )
V_4 |= V_126 ;
if ( V_120 -> V_79 & V_113 )
V_4 |= V_114 ;
if ( V_120 -> V_79 & V_115 )
V_4 |= V_116 ;
if ( V_120 -> V_79 & V_107 )
V_4 |= V_117 ;
F_2 ( & V_100 -> V_110 , V_4 ) ;
F_11 ( L_19
L_20 , V_77 , V_120 -> V_102 , V_100 -> V_111 , V_100 -> V_110 ) ;
if ( V_120 -> V_79 & V_107 ) {
V_120 -> V_122 = V_127 +
( V_124 * V_101 )
+ V_120 -> V_123 ;
}
F_11 ( L_16
L_17 , V_77 , V_120 -> V_102 , V_120 -> V_79 ,
V_120 -> V_103 , ( unsigned long long ) V_120 -> V_122 ,
V_120 -> V_123 ) ;
V_121 = & V_39 -> V_128 [ V_120 -> V_102 ] ;
* V_121 = * V_120 ;
V_121 -> V_79 &= ( V_125 | V_113 | V_115 | V_107 ) ;
return 0 ;
}
static int F_42 ( struct V_74 * V_75 )
{
int V_42 ;
V_97 V_98 = { 0 , 0 , 0 , 0 , 1 } ;
V_119 V_120 = { 0 , 0 , 0 , 0 , 0 , 0 } ;
F_11 ( L_21 , V_39 ) ;
F_32 ( V_75 , & V_129 ) ;
for ( V_42 = 0 ; V_42 < V_106 ; V_42 ++ ) {
V_98 . V_102 = V_42 ;
F_38 ( V_75 , & V_98 ) ;
}
for ( V_42 = 0 ; V_42 < V_108 ; V_42 ++ ) {
V_120 . V_102 = V_42 ;
F_41 ( V_75 , & V_120 ) ;
}
return 0 ;
}
static int F_43 ( struct V_74 * V_75 )
{
return F_32 ( V_75 , & V_129 ) ;
}
static int T_7 F_44 ( struct V_130 * V_131 )
{
struct V_99 * V_100 ;
unsigned int V_42 , V_132 , V_96 ;
T_5 * V_47 ;
int V_133 ;
struct V_134 * V_135 = V_131 -> V_37 . V_136 ;
F_45 ( L_22 , V_137 ) ;
V_47 = F_46 ( V_135 , 0 ) ;
if ( V_47 == NULL )
return - V_91 ;
V_138 = F_47 ( V_135 , 0 ) ;
V_96 = V_139 [ V_138 ] . V_96 ;
if ( V_138 < 0 ) {
F_48 ( V_47 ) ;
return - V_91 ;
}
V_140 [ 0 ] = & V_47 -> V_141 ;
V_140 [ 1 ] = & V_47 -> V_142 ;
F_45 ( V_143 L_23 V_144
L_24 , V_138 , V_96 ) ;
if ( F_49 ( V_138 , F_10 , V_145 ,
V_146 , V_48 ) ) {
F_50 ( L_25 ,
V_138 ) ;
F_48 ( V_47 ) ;
return - 1 ;
}
V_100 = ( void * ) & V_47 -> V_109 ;
F_2 ( & V_47 -> V_49 , F_36 ( 0 ) | F_36 ( 1 ) ) ;
F_51 ( & V_47 -> V_51 , F_36 ( 0 ) | F_36 ( 1 ) ) ;
F_2 ( F_33 ( 0 ) ,
V_94 | ( F_35 ( V_96 ) << 16 ) ) ;
F_2 ( F_33 ( 1 ) ,
V_94 | ( F_35 ( V_96 ) << 16 ) ) ;
for ( V_42 = 0 ; V_42 < V_52 ; V_42 ++ ) {
for ( V_132 = 0 ; V_132 < V_108 ; V_132 ++ ) {
F_2 ( & V_100 -> V_111 , V_127 +
( V_124
* ( V_132 + V_42 * V_108 ) ) ) ;
F_2 ( & V_100 -> V_110 , 0 ) ;
V_100 ++ ;
}
}
F_1 ( 0 , 0 , 0 ) ;
F_1 ( 1 , 0 , 0 ) ;
F_4 ( 0 ) ;
F_4 ( 1 ) ;
for ( V_42 = 0 ; V_42 < V_52 ; V_42 ++ ) {
V_48 [ V_42 ] . V_1 = V_42 ;
V_48 [ V_42 ] . V_48 . V_147 = V_148 ;
V_48 [ V_42 ] . V_48 . V_149 =
V_150 | V_151 | V_152 ;
V_48 [ V_42 ] . V_48 . V_153 = 0x000 ;
V_48 [ V_42 ] . V_48 . V_154 = 0x1000 ;
V_48 [ V_42 ] . V_48 . V_155 = 0 ;
V_48 [ V_42 ] . V_48 . V_156 = V_138 ;
V_48 [ V_42 ] . V_48 . V_157 = & V_158 ;
V_48 [ V_42 ] . V_48 . V_159 = & V_160 ;
V_48 [ V_42 ] . V_48 . V_161 = NULL ;
V_48 [ V_42 ] . V_48 . V_37 . V_162 = & V_131 -> V_37 ;
V_48 [ V_42 ] . V_47 = V_47 ;
V_48 [ V_42 ] . V_68 = V_163 ;
V_48 [ V_42 ] . V_96 = V_96 ;
}
for ( V_42 = 0 ; V_42 < V_52 ; V_42 ++ ) {
V_133 = F_52 ( & V_48 [ V_42 ] . V_48 ) ;
if ( V_133 < 0 )
F_50 ( L_26 ) ;
}
return 0 ;
}
static int F_53 ( struct V_130 * V_131 )
{
T_1 V_132 , V_42 ;
struct V_99 * V_100 ;
T_5 * V_47 = V_48 [ 0 ] . V_47 ;
for ( V_42 = 0 ; V_42 < V_52 ; V_42 ++ ) {
V_100 = ( void * ) & V_47 -> V_109 ;
F_2 ( & V_47 -> V_49 , F_36 ( V_42 ) ) ;
F_2 ( & V_47 -> V_51 ,
F_3 ( & V_47 -> V_51 ) & ~ F_36 ( V_42 ) ) ;
F_2 ( F_33 ( V_42 ) , V_94 ) ;
for ( V_132 = 0 ; V_132 < V_108 ; V_132 ++ ) {
F_2 ( & V_100 -> V_110 , 0 ) ;
V_100 ++ ;
}
F_1 ( V_42 , 0 , 0 ) ;
F_5 ( V_42 ) ;
}
for ( V_42 = 0 ; V_42 < V_52 ; V_42 ++ )
F_54 ( & V_48 [ V_42 ] . V_48 ) ;
F_48 ( V_47 ) ;
F_55 ( V_138 , NULL ) ;
return 0 ;
}
static int T_7 F_56 ( void )
{
return F_57 ( & V_164 ) ;
}
static void T_8 F_58 ( void )
{
F_59 ( & V_164 ) ;
}
