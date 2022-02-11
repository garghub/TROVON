int F_1 ( int V_1 , enum V_2 V_3 )
{
if ( V_1 < V_4 || V_1 >= V_5 )
return 0 ;
switch( V_3 ) {
case V_6 :
V_7 [ V_1 ] = V_8 [ V_1 ] ;
#if F_2 ( V_9 ) || F_2 ( V_10 )
if ( V_1 < V_11 )
V_12 [ V_1 ] = V_13 [ V_1 ] ;
#endif
break;
case V_14 :
V_7 [ V_1 ] = NULL ;
#if F_2 ( V_9 ) || F_2 ( V_10 )
if ( V_1 < V_11 )
V_12 [ V_1 ] = NULL ;
#endif
break;
case V_15 :
return V_7 [ V_1 ] != NULL ;
case V_16 :
return V_8 [ V_1 ] != NULL ;
}
return 0 ;
}
static void
F_3 ( void )
{
unsigned V_17 ;
for ( V_17 = 0 ; V_17 <= V_18 ; V_17 ++ ) {
if ( V_19 [ V_17 ] )
return;
}
F_1 ( 4 , V_14 ) ;
}
int F_4 ( T_1 V_20 , enum V_2 V_3 )
{
if ( V_20 > V_18 &&
V_3 != V_16 )
return - 1 ;
switch( V_3 ) {
case V_6 :
V_19 [ V_20 ] = true ;
F_1 ( 4 , V_6 ) ;
break;
case V_14 :
V_19 [ V_20 ] = false ;
F_3 () ;
break;
case V_15 :
return V_19 [ V_20 ] ;
case V_16 :
return V_20 <= V_18 ;
}
return 0 ;
}
int F_5 ( struct V_21 * V_21 )
{
int V_22 = 0 ;
struct V_23 * V_24 = F_6 ( V_21 , V_25 ) ;
F_7 ( & V_26 ) ;
if ( V_24 -> V_27 )
V_22 = V_24 -> V_27 -> V_28 ;
F_8 ( & V_26 ) ;
return V_22 ;
}
static int F_9 ( struct V_21 * V_21 )
{
int error ;
struct V_23 * V_24 = F_6 ( V_21 , V_25 ) ;
if ( ! F_10 ( & V_24 -> V_27 -> V_29 ) )
return 0 ;
error = F_11 ( V_24 -> V_27 , L_1 , V_21 , V_30 , V_31 ,
V_32 ) ;
if ( error < 0 )
return error ;
error = F_11 ( V_24 -> V_27 , L_2 , V_21 , V_30 , V_31 ,
V_32 ) ;
if ( error < 0 )
return error ;
return 0 ;
}
static int F_12 ( int V_33 )
{
int V_34 ;
if ( V_35 ++ )
return 0 ;
V_34 = F_13 ( 2 * V_33 ) ;
if ( V_34 )
goto V_36;
V_34 = F_14 () ;
if ( V_34 )
goto V_37;
return 0 ;
V_37:
F_15 () ;
V_36:
V_35 -- ;
return V_34 ;
}
static void F_16 ( void )
{
if ( -- V_35 )
return;
F_17 () ;
F_15 () ;
}
static bool F_18 ( void )
{
#if F_2 ( V_38 )
return ( V_7 [ 2 ] != NULL ) || ( V_7 [ 3 ] != NULL ) ;
#else
return ( V_7 [ 2 ] != NULL ) ;
#endif
}
static int F_19 ( int V_33 , struct V_21 * V_21 )
{
struct V_23 * V_24 = F_6 ( V_21 , V_25 ) ;
int V_34 ;
if ( V_24 -> V_39 )
return 0 ;
V_34 = F_12 ( V_33 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_9 ( V_21 ) ;
if ( V_34 )
goto V_40;
if ( F_18 () && ! V_24 -> V_41 ) {
V_34 = V_41 ( V_21 ) ;
if ( V_34 )
goto V_40;
V_24 -> V_41 = 1 ;
}
V_34 = F_20 ( V_21 ) ;
if ( V_34 )
goto V_42;
V_24 -> V_39 = true ;
return 0 ;
V_42:
if ( V_24 -> V_41 ) {
F_21 ( V_21 ) ;
V_24 -> V_41 = 0 ;
}
V_40:
F_16 () ;
return V_34 ;
}
static void F_22 ( struct V_21 * V_21 )
{
struct V_23 * V_24 = F_6 ( V_21 , V_25 ) ;
F_23 ( V_21 ) ;
if ( V_24 -> V_41 ) {
F_21 ( V_21 ) ;
V_24 -> V_41 = 0 ;
}
V_24 -> V_39 = false ;
F_16 () ;
}
static int F_24 ( struct V_43 * V_44 , unsigned long V_45 ,
void * V_46 )
{
struct V_47 * V_48 = (struct V_47 * ) V_46 ;
struct V_49 * V_50 = V_48 -> V_51 -> V_50 ;
struct V_21 * V_21 = F_25 ( V_50 ) ;
struct V_23 * V_24 = F_6 ( V_21 , V_25 ) ;
struct V_52 sin ;
if ( V_45 != V_53 )
goto V_54;
if ( V_24 -> V_27 ) {
F_26 ( L_3 , & V_48 -> V_55 ) ;
sin . V_56 = V_57 ;
sin . V_58 . V_59 = V_48 -> V_55 ;
F_27 ( V_24 -> V_27 , (struct V_60 * ) & sin ) ;
}
V_54:
return V_61 ;
}
static int F_28 ( struct V_43 * V_44 ,
unsigned long V_45 , void * V_46 )
{
struct V_62 * V_48 = (struct V_62 * ) V_46 ;
struct V_49 * V_50 = V_48 -> V_63 -> V_50 ;
struct V_21 * V_21 = F_25 ( V_50 ) ;
struct V_23 * V_24 = F_6 ( V_21 , V_25 ) ;
struct V_64 V_65 ;
if ( V_45 != V_53 )
goto V_54;
if ( V_24 -> V_27 ) {
F_26 ( L_4 , & V_48 -> V_66 ) ;
V_65 . V_67 = V_68 ;
V_65 . V_69 = V_48 -> V_66 ;
if ( F_29 ( & V_65 . V_69 ) & V_70 )
V_65 . V_71 = V_48 -> V_63 -> V_50 -> V_72 ;
F_27 ( V_24 -> V_27 , (struct V_60 * ) & V_65 ) ;
}
V_54:
return V_61 ;
}
static void F_30 ( struct V_73 * V_74 , struct V_21 * V_21 )
{
struct V_23 * V_24 = F_6 ( V_21 , V_25 ) ;
if ( F_31 ( & V_75 ) == 0 ) {
F_32 ( & V_76 ) ;
#if F_33 ( V_77 )
F_34 ( & V_78 ) ;
#endif
}
F_35 ( V_74 , V_21 ) ;
if ( ! V_24 -> V_39 )
return;
F_22 ( V_21 ) ;
F_36 ( V_79 L_5
L_6 ) ;
F_37 ( V_21 ) ;
}
void F_38 ( void )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_5 ; V_17 ++ )
if ( F_1 ( V_17 , V_15 ) )
return;
for ( V_17 = 0 ; V_17 < V_5 ; V_17 ++ )
if ( V_17 != 4 )
F_1 ( V_17 , V_6 ) ;
else {
int V_80 = 0 ;
while ( F_4 ( V_80 , V_6 ) >= 0 )
V_80 ++ ;
}
}
static void F_39 ( void )
{
#define F_40 10
V_81 = ( F_41 ()
>> F_40 ) * V_82 ;
V_83 = 0 ;
F_42 ( & V_84 ) ;
F_26 ( L_7 , V_85 , V_81 ) ;
}
static int F_43 ( void )
{
struct V_86 V_17 ;
unsigned long long V_87 ;
unsigned long V_34 ;
F_44 ( & V_17 ) ;
V_87 = ( V_17 . V_88 - V_17 . V_89 ) << V_90 ;
V_87 >>= 12 ;
V_34 = V_91 ;
while ( V_34 > V_87 && V_34 >= 8 * 1024 * 2 )
V_34 /= 2 ;
return V_34 ;
}
int F_45 ( struct V_21 * V_21 )
{
int error ;
struct V_23 * V_24 = F_6 ( V_21 , V_25 ) ;
F_46 ( ! F_47 ( & V_26 ) ) ;
if ( V_24 -> V_27 ) {
F_48 ( V_24 -> V_27 ) ;
return 0 ;
}
if ( V_92 == 0 )
V_92 = F_43 () ;
F_38 () ;
V_24 -> V_27 = F_49 ( & V_93 , V_92 ,
& V_94 ) ;
if ( V_24 -> V_27 == NULL )
return - V_95 ;
V_24 -> V_27 -> V_96 = V_24 -> V_97 ;
error = F_50 ( V_24 -> V_27 , V_21 ) ;
if ( error < 0 ) {
F_51 ( V_24 -> V_27 ) ;
return error ;
}
F_39 () ;
if ( F_52 ( & V_75 ) == 1 ) {
F_53 ( & V_76 ) ;
#if F_33 ( V_77 )
F_54 ( & V_78 ) ;
#endif
}
F_55 ( & V_24 -> V_98 ) ;
return 0 ;
}
int F_56 ( struct V_21 * V_21 )
{
struct V_23 * V_24 = F_6 ( V_21 , V_25 ) ;
if ( V_24 -> V_27 == NULL )
return 0 ;
else
return V_24 -> V_27 -> V_99 ;
}
int F_57 ( int V_100 , int * V_101 , struct V_21 * V_21 )
{
int V_17 = 0 ;
struct V_23 * V_24 = F_6 ( V_21 , V_25 ) ;
if ( V_24 -> V_27 != NULL ) {
for ( V_17 = 0 ; V_17 < V_24 -> V_27 -> V_99 && V_17 < V_100 ; V_17 ++ )
V_101 [ V_17 ] = V_24 -> V_27 -> V_102 [ V_17 ] . V_103 ;
}
return 0 ;
}
void F_58 ( struct V_21 * V_21 )
{
struct V_23 * V_24 = F_6 ( V_21 , V_25 ) ;
int V_104 = ( V_24 -> V_27 -> V_28 == 1 ) ;
if ( V_104 )
F_59 ( V_24 -> V_27 , V_21 ) ;
F_51 ( V_24 -> V_27 ) ;
if ( V_104 )
V_24 -> V_27 = NULL ;
}
int F_60 ( int V_100 , int * V_101 , struct V_21 * V_21 )
{
int V_17 = 0 ;
int V_105 = 0 ;
int V_106 = 0 ;
struct V_23 * V_24 = F_6 ( V_21 , V_25 ) ;
F_46 ( ! F_47 ( & V_26 ) ) ;
if ( V_24 -> V_27 == NULL || V_100 <= 0 )
return 0 ;
if ( V_100 > V_24 -> V_27 -> V_99 )
V_100 = V_24 -> V_27 -> V_99 ;
V_105 = 0 ;
for ( V_17 = 0 ; V_17 < V_100 ; V_17 ++ ) {
V_101 [ V_17 ] = F_61 ( V_101 [ V_17 ] , V_107 ) ;
V_105 += V_101 [ V_17 ] ;
}
if ( V_105 > V_107 ) {
for ( V_17 = 0 ; V_17 < V_100 && V_105 > 0 ; V_17 ++ ) {
int V_108 = V_101 [ V_17 ] * V_107 / V_105 ;
V_105 -= ( V_101 [ V_17 ] - V_108 ) ;
V_101 [ V_17 ] = V_108 ;
}
for ( V_17 = 0 ; V_17 < V_100 && V_105 > 0 ; V_17 ++ ) {
V_101 [ V_17 ] -- ;
V_105 -- ;
}
}
if ( V_101 [ 0 ] == 0 )
V_101 [ 0 ] = 1 ;
F_48 ( V_24 -> V_27 ) ;
for ( V_17 = 0 ; V_17 < V_100 ; V_17 ++ ) {
V_106 = V_24 -> V_27 -> V_109 -> V_110 ( V_24 -> V_27 ,
& V_24 -> V_27 -> V_102 [ V_17 ] , V_101 [ V_17 ] ) ;
if ( V_106 )
break;
}
F_58 ( V_21 ) ;
return V_106 ;
}
int
F_62 ( int V_33 , struct V_21 * V_21 )
{
int error ;
bool V_111 ;
struct V_23 * V_24 = F_6 ( V_21 , V_25 ) ;
F_7 ( & V_26 ) ;
F_26 ( L_8 ) ;
V_33 = F_63 ( V_33 , 0 ) ;
V_33 = F_61 ( V_33 , V_107 ) ;
error = 0 ;
if ( V_33 == 0 && V_24 -> V_27 == NULL )
goto V_54;
error = F_45 ( V_21 ) ;
if ( error )
goto V_54;
V_111 = V_24 -> V_39 ;
error = F_19 ( V_33 , V_21 ) ;
if ( error )
goto V_112;
error = V_24 -> V_27 -> V_109 -> V_110 ( V_24 -> V_27 ,
NULL , V_33 ) ;
if ( error )
goto V_113;
error = V_24 -> V_27 -> V_28 - 1 ;
V_113:
if ( error < 0 && ! V_111 )
F_22 ( V_21 ) ;
V_112:
F_58 ( V_21 ) ;
V_54:
F_8 ( & V_26 ) ;
return error ;
}
static int
F_64 ( void * V_114 )
{
struct V_115 * V_116 = (struct V_115 * ) V_114 ;
struct V_117 * V_118 = F_65 ( V_116 -> V_119 -> V_29 . V_120 , F_66 ( struct V_117 ) , V_121 ) ;
struct V_21 * V_21 = V_118 -> V_122 ;
struct V_23 * V_24 = F_6 ( V_21 , V_25 ) ;
int V_106 ;
F_7 ( & V_26 ) ;
if ( F_67 () < 0 ) {
F_36 ( L_9 ) ;
goto V_54;
}
V_123 -> V_124 -> V_125 = 0 ;
F_68 ( V_126 ) ;
F_68 ( V_127 ) ;
F_68 ( V_128 ) ;
F_68 ( V_129 ) ;
V_130 . V_131 ++ ;
F_8 ( & V_26 ) ;
F_69 () ;
for (; ; ) {
V_116 -> V_119 -> V_96 = V_24 -> V_97 ;
while ( ( V_106 = F_70 ( V_116 , 60 * 60 * V_132 ) ) == - V_133 )
;
if ( V_106 == - V_134 )
break;
F_71 () ;
F_72 ( V_116 ) ;
F_71 () ;
}
F_73 ( V_123 ) ;
F_7 ( & V_26 ) ;
V_130 . V_131 -- ;
V_54:
V_116 -> V_119 = NULL ;
F_74 ( V_116 ) ;
F_58 ( V_21 ) ;
F_8 ( & V_26 ) ;
F_75 ( 0 ) ;
return 0 ;
}
static T_2 F_76 ( T_1 V_1 , T_2 V_135 )
{
if ( V_135 == V_136 && V_1 == 2 )
return V_137 ;
if ( V_135 == V_138 && V_1 < 4 )
return V_139 ;
return V_135 ;
}
static bool F_77 ( struct V_115 * V_116 ,
const struct V_140 * V_141 )
{
if ( V_116 -> V_142 != V_143 )
return false ;
if ( V_116 -> V_144 >= 4 )
return false ;
if ( V_141 -> V_145 > 0 &&
V_141 -> V_145 < F_78 ( V_82 ) )
return false ;
return V_116 -> V_146 . V_147 > V_82 ;
}
int
F_79 ( struct V_115 * V_116 , T_2 * V_148 )
{
const struct V_140 * V_141 ;
T_2 V_135 ;
T_2 * V_149 ;
F_26 ( L_10 ,
V_116 -> V_144 , V_116 -> V_150 ) ;
V_141 = V_116 -> V_151 ;
if ( F_77 ( V_116 , V_141 ) ) {
F_26 ( L_11 , V_116 -> V_144 ) ;
* V_148 = V_152 ;
return 1 ;
}
V_116 -> V_153 = V_141 -> V_154 ;
if ( V_141 -> V_155 &&
! V_141 -> V_155 ( V_116 , ( T_2 * ) V_116 -> V_146 . V_156 [ 0 ] . V_157 ) ) {
F_26 ( L_12 ) ;
* V_148 = V_152 ;
return 1 ;
}
switch ( F_80 ( V_116 ) ) {
case V_158 :
return 0 ;
case V_159 :
return 1 ;
case V_160 : ;
}
V_149 = V_116 -> V_161 . V_156 [ 0 ] . V_157
+ V_116 -> V_161 . V_156 [ 0 ] . V_162 ;
V_116 -> V_161 . V_156 [ 0 ] . V_162 += sizeof( T_2 ) ;
V_135 = V_141 -> V_163 ( V_116 ) ;
V_135 = F_76 ( V_116 -> V_144 , V_135 ) ;
if ( V_135 == V_137 || F_81 ( V_164 , & V_116 -> V_165 ) ) {
F_26 ( L_13 ) ;
F_82 ( V_116 , V_166 , NULL ) ;
return 0 ;
}
if ( V_116 -> V_150 != 0 )
* V_149 ++ = V_135 ;
if ( ! ( V_135 && V_116 -> V_144 == 2 ) ) {
if ( V_141 -> V_167 && ! V_141 -> V_167 ( V_116 , V_149 ) ) {
F_26 ( L_14 ) ;
F_82 ( V_116 , V_166 , NULL ) ;
* V_148 = V_168 ;
return 1 ;
}
}
F_82 ( V_116 , V_116 -> V_153 , V_148 + 1 ) ;
return 1 ;
}
int F_83 ( struct V_169 * V_169 , struct V_170 * V_170 )
{
int V_34 ;
struct V_23 * V_24 = F_6 ( V_169 -> V_171 -> V_172 , V_25 ) ;
F_7 ( & V_26 ) ;
if ( V_24 -> V_27 == NULL ) {
F_8 ( & V_26 ) ;
return - V_173 ;
}
F_48 ( V_24 -> V_27 ) ;
V_34 = F_84 ( V_24 -> V_27 , V_170 ) ;
F_8 ( & V_26 ) ;
return V_34 ;
}
int F_85 ( struct V_169 * V_169 , struct V_170 * V_170 )
{
int V_34 = F_86 ( V_169 , V_170 ) ;
struct V_21 * V_21 = V_169 -> V_171 -> V_172 ;
F_7 ( & V_26 ) ;
F_58 ( V_21 ) ;
F_8 ( & V_26 ) ;
return V_34 ;
}
