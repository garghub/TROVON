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
int F_3 ( T_1 V_17 , enum V_2 V_3 )
{
if ( V_17 > V_18 )
return - 1 ;
switch( V_3 ) {
case V_6 :
V_19 [ V_17 ] = true ;
break;
case V_14 :
V_19 [ V_17 ] = false ;
break;
case V_15 :
return V_19 [ V_17 ] ;
case V_16 :
return V_17 <= V_18 ;
}
return 0 ;
}
int F_4 ( struct V_20 * V_20 )
{
int V_21 = 0 ;
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
F_6 ( & V_25 ) ;
if ( V_23 -> V_26 )
V_21 = V_23 -> V_26 -> V_27 ;
F_7 ( & V_25 ) ;
return V_21 ;
}
static int F_8 ( struct V_20 * V_20 )
{
int error ;
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
if ( ! F_9 ( & V_23 -> V_26 -> V_28 ) )
return 0 ;
error = F_10 ( V_23 -> V_26 , L_1 , V_20 , V_29 , V_30 ,
V_31 ) ;
if ( error < 0 )
return error ;
error = F_10 ( V_23 -> V_26 , L_2 , V_20 , V_29 , V_30 ,
V_31 ) ;
if ( error < 0 )
return error ;
return 0 ;
}
static int F_11 ( int V_32 )
{
int V_33 ;
if ( V_34 ++ )
return 0 ;
V_33 = F_12 ( 2 * V_32 ) ;
if ( V_33 )
goto V_35;
V_33 = F_13 () ;
if ( V_33 )
goto V_36;
return 0 ;
V_36:
F_14 () ;
V_35:
V_34 -- ;
return V_33 ;
}
static void F_15 ( void )
{
if ( -- V_34 )
return;
F_16 () ;
F_14 () ;
}
static bool F_17 ( void )
{
#if F_2 ( V_37 )
return ( V_7 [ 2 ] != NULL ) || ( V_7 [ 3 ] != NULL ) ;
#else
return ( V_7 [ 2 ] != NULL ) ;
#endif
}
static int F_18 ( int V_32 , struct V_20 * V_20 )
{
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
int V_33 ;
if ( V_23 -> V_38 )
return 0 ;
V_33 = F_11 ( V_32 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_8 ( V_20 ) ;
if ( V_33 )
goto V_39;
if ( F_17 () && ! V_23 -> V_40 ) {
V_33 = V_40 ( V_20 ) ;
if ( V_33 )
goto V_39;
V_23 -> V_40 = 1 ;
}
V_33 = F_19 ( V_20 ) ;
if ( V_33 )
goto V_41;
V_23 -> V_38 = true ;
return 0 ;
V_41:
if ( V_23 -> V_40 ) {
F_20 ( V_20 ) ;
V_23 -> V_40 = 0 ;
}
V_39:
F_15 () ;
return V_33 ;
}
static void F_21 ( struct V_20 * V_20 )
{
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
F_22 ( V_20 ) ;
if ( V_23 -> V_40 ) {
F_20 ( V_20 ) ;
V_23 -> V_40 = 0 ;
}
V_23 -> V_38 = false ;
F_15 () ;
}
static int F_23 ( struct V_42 * V_43 , unsigned long V_44 ,
void * V_45 )
{
struct V_46 * V_47 = (struct V_46 * ) V_45 ;
struct V_48 * V_49 = V_47 -> V_50 -> V_49 ;
struct V_20 * V_20 = F_24 ( V_49 ) ;
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
struct V_51 sin ;
if ( V_44 != V_52 )
goto V_53;
if ( V_23 -> V_26 ) {
F_25 ( L_3 , & V_47 -> V_54 ) ;
sin . V_55 = V_56 ;
sin . V_57 . V_58 = V_47 -> V_54 ;
F_26 ( V_23 -> V_26 , (struct V_59 * ) & sin ) ;
}
V_53:
return V_60 ;
}
static int F_27 ( struct V_42 * V_43 ,
unsigned long V_44 , void * V_45 )
{
struct V_61 * V_47 = (struct V_61 * ) V_45 ;
struct V_48 * V_49 = V_47 -> V_62 -> V_49 ;
struct V_20 * V_20 = F_24 ( V_49 ) ;
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
struct V_63 V_64 ;
if ( V_44 != V_52 )
goto V_53;
if ( V_23 -> V_26 ) {
F_25 ( L_4 , & V_47 -> V_65 ) ;
V_64 . V_66 = V_67 ;
V_64 . V_68 = V_47 -> V_65 ;
F_26 ( V_23 -> V_26 , (struct V_59 * ) & V_64 ) ;
}
V_53:
return V_60 ;
}
static void F_28 ( struct V_69 * V_70 , struct V_20 * V_20 )
{
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
if ( F_29 ( & V_71 ) == 0 ) {
F_30 ( & V_72 ) ;
#if F_31 ( V_73 )
F_32 ( & V_74 ) ;
#endif
}
F_33 ( V_70 , V_20 ) ;
if ( ! V_23 -> V_38 )
return;
F_21 ( V_20 ) ;
F_34 ( V_75 L_5
L_6 ) ;
F_35 ( V_20 ) ;
}
void F_36 ( void )
{
int V_76 = 0 ;
int V_77 ;
for ( V_77 = V_4 ; V_77 < V_5 ; V_77 ++ ) {
if ( V_78 . V_79 [ V_77 ] )
V_76 = 1 ;
}
if ( ! V_76 ) {
for ( V_77 = V_4 ; V_77 < V_5 ; V_77 ++ )
V_78 . V_79 [ V_77 ] = V_8 [ V_77 ] ;
#if F_2 ( V_9 ) || F_2 ( V_10 )
for ( V_77 = V_80 ; V_77 < V_11 ; V_77 ++ )
V_81 . V_79 [ V_77 ] =
V_13 [ V_77 ] ;
#endif
}
}
static void F_37 ( void )
{
#define F_38 10
V_82 = ( F_39 ()
>> F_38 ) * V_83 ;
V_84 = 0 ;
F_40 ( & V_85 ) ;
F_25 ( L_7 , V_86 , V_82 ) ;
}
static int F_41 ( void )
{
struct V_87 V_77 ;
unsigned long long V_88 ;
unsigned long V_33 ;
F_42 ( & V_77 ) ;
V_88 = ( V_77 . V_89 - V_77 . V_90 ) << V_91 ;
V_88 >>= 12 ;
V_33 = V_92 ;
while ( V_33 > V_88 && V_33 >= 8 * 1024 * 2 )
V_33 /= 2 ;
return V_33 ;
}
int F_43 ( struct V_20 * V_20 )
{
int error ;
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
F_44 ( ! F_45 ( & V_25 ) ) ;
if ( V_23 -> V_26 ) {
F_46 ( V_23 -> V_26 ) ;
return 0 ;
}
if ( V_93 == 0 )
V_93 = F_41 () ;
F_36 () ;
V_23 -> V_26 = F_47 ( & V_78 , V_93 ,
& V_94 ) ;
if ( V_23 -> V_26 == NULL )
return - V_95 ;
V_23 -> V_26 -> V_96 = V_23 -> V_97 ;
error = F_48 ( V_23 -> V_26 , V_20 ) ;
if ( error < 0 ) {
F_49 ( V_23 -> V_26 ) ;
return error ;
}
F_37 () ;
if ( F_50 ( & V_71 ) == 1 ) {
F_51 ( & V_72 ) ;
#if F_31 ( V_73 )
F_52 ( & V_74 ) ;
#endif
}
F_53 ( & V_23 -> V_98 ) ;
return 0 ;
}
int F_54 ( struct V_20 * V_20 )
{
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
if ( V_23 -> V_26 == NULL )
return 0 ;
else
return V_23 -> V_26 -> V_99 ;
}
int F_55 ( int V_100 , int * V_101 , struct V_20 * V_20 )
{
int V_77 = 0 ;
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
if ( V_23 -> V_26 != NULL ) {
for ( V_77 = 0 ; V_77 < V_23 -> V_26 -> V_99 && V_77 < V_100 ; V_77 ++ )
V_101 [ V_77 ] = V_23 -> V_26 -> V_102 [ V_77 ] . V_103 ;
}
return 0 ;
}
void F_56 ( struct V_20 * V_20 )
{
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
int V_104 = ( V_23 -> V_26 -> V_27 == 1 ) ;
if ( V_104 )
F_57 ( V_23 -> V_26 , V_20 ) ;
F_49 ( V_23 -> V_26 ) ;
if ( V_104 )
V_23 -> V_26 = NULL ;
}
int F_58 ( int V_100 , int * V_101 , struct V_20 * V_20 )
{
int V_77 = 0 ;
int V_105 = 0 ;
int V_106 = 0 ;
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
F_44 ( ! F_45 ( & V_25 ) ) ;
if ( V_23 -> V_26 == NULL || V_100 <= 0 )
return 0 ;
if ( V_100 > V_23 -> V_26 -> V_99 )
V_100 = V_23 -> V_26 -> V_99 ;
V_105 = 0 ;
for ( V_77 = 0 ; V_77 < V_100 ; V_77 ++ ) {
V_101 [ V_77 ] = F_59 ( V_101 [ V_77 ] , V_107 ) ;
V_105 += V_101 [ V_77 ] ;
}
if ( V_105 > V_107 ) {
for ( V_77 = 0 ; V_77 < V_100 && V_105 > 0 ; V_77 ++ ) {
int V_108 = V_101 [ V_77 ] * V_107 / V_105 ;
V_105 -= ( V_101 [ V_77 ] - V_108 ) ;
V_101 [ V_77 ] = V_108 ;
}
for ( V_77 = 0 ; V_77 < V_100 && V_105 > 0 ; V_77 ++ ) {
V_101 [ V_77 ] -- ;
V_105 -- ;
}
}
if ( V_101 [ 0 ] == 0 )
V_101 [ 0 ] = 1 ;
F_46 ( V_23 -> V_26 ) ;
for ( V_77 = 0 ; V_77 < V_100 ; V_77 ++ ) {
V_106 = V_23 -> V_26 -> V_109 -> V_110 ( V_23 -> V_26 ,
& V_23 -> V_26 -> V_102 [ V_77 ] , V_101 [ V_77 ] ) ;
if ( V_106 )
break;
}
F_56 ( V_20 ) ;
return V_106 ;
}
int
F_60 ( int V_32 , struct V_20 * V_20 )
{
int error ;
bool V_111 ;
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
F_6 ( & V_25 ) ;
F_25 ( L_8 ) ;
V_32 = F_61 ( V_32 , 0 ) ;
V_32 = F_59 ( V_32 , V_107 ) ;
error = 0 ;
if ( V_32 == 0 && V_23 -> V_26 == NULL )
goto V_53;
error = F_43 ( V_20 ) ;
if ( error )
goto V_53;
V_111 = V_23 -> V_38 ;
error = F_18 ( V_32 , V_20 ) ;
if ( error )
goto V_112;
error = V_23 -> V_26 -> V_109 -> V_110 ( V_23 -> V_26 ,
NULL , V_32 ) ;
if ( error )
goto V_113;
error = V_23 -> V_26 -> V_27 - 1 ;
V_113:
if ( error < 0 && ! V_111 )
F_21 ( V_20 ) ;
V_112:
F_56 ( V_20 ) ;
V_53:
F_7 ( & V_25 ) ;
return error ;
}
static int
F_62 ( void * V_114 )
{
struct V_115 * V_116 = (struct V_115 * ) V_114 ;
struct V_117 * V_118 = F_63 ( V_116 -> V_119 -> V_28 . V_120 , F_64 ( struct V_117 ) , V_121 ) ;
struct V_20 * V_20 = V_118 -> V_122 ;
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
int V_106 ;
F_6 ( & V_25 ) ;
if ( F_65 () < 0 ) {
F_34 ( L_9 ) ;
goto V_53;
}
V_123 -> V_124 -> V_125 = 0 ;
F_66 ( V_126 ) ;
F_66 ( V_127 ) ;
F_66 ( V_128 ) ;
F_66 ( V_129 ) ;
V_130 . V_131 ++ ;
F_7 ( & V_25 ) ;
F_67 () ;
for (; ; ) {
V_116 -> V_119 -> V_96 = V_23 -> V_97 ;
while ( ( V_106 = F_68 ( V_116 , 60 * 60 * V_132 ) ) == - V_133 )
;
if ( V_106 == - V_134 )
break;
F_69 () ;
F_70 ( V_116 ) ;
F_69 () ;
}
F_71 ( V_123 ) ;
F_6 ( & V_25 ) ;
V_130 . V_131 -- ;
V_53:
V_116 -> V_119 = NULL ;
F_72 ( V_116 ) ;
F_56 ( V_20 ) ;
F_7 ( & V_25 ) ;
F_73 ( 0 ) ;
return 0 ;
}
static T_2 F_74 ( T_1 V_1 , T_2 V_135 )
{
if ( V_135 == V_136 && V_1 == 2 )
return V_137 ;
if ( V_135 == V_138 && V_1 < 4 )
return V_139 ;
return V_135 ;
}
int
F_75 ( struct V_115 * V_116 , T_2 * V_140 )
{
struct V_141 * V_142 ;
T_3 V_143 ;
T_2 V_135 ;
T_2 * V_144 ;
F_25 ( L_10 ,
V_116 -> V_145 , V_116 -> V_146 ) ;
V_142 = V_116 -> V_147 ;
V_116 -> V_148 = V_142 -> V_149 ;
V_143 = V_142 -> V_150 ;
if ( V_143 && ! V_143 ( V_116 , ( T_2 * ) V_116 -> V_151 . V_152 [ 0 ] . V_153 ,
V_116 -> V_154 ) ) {
F_25 ( L_11 ) ;
* V_140 = V_155 ;
return 1 ;
}
switch ( F_76 ( V_116 ) ) {
case V_156 :
return 0 ;
case V_157 :
return 1 ;
case V_158 : ;
}
V_144 = V_116 -> V_159 . V_152 [ 0 ] . V_153
+ V_116 -> V_159 . V_152 [ 0 ] . V_160 ;
V_116 -> V_159 . V_152 [ 0 ] . V_160 += sizeof( T_2 ) ;
V_135 = V_142 -> V_161 ( V_116 , V_116 -> V_154 , V_116 -> V_162 ) ;
V_135 = F_74 ( V_116 -> V_145 , V_135 ) ;
if ( V_135 == V_137 || F_77 ( V_163 , & V_116 -> V_164 ) ) {
F_25 ( L_12 ) ;
F_78 ( V_116 , V_165 , NULL ) ;
return 0 ;
}
if ( V_116 -> V_146 != 0 )
* V_144 ++ = V_135 ;
if ( ! ( V_135 && V_116 -> V_145 == 2 ) ) {
V_143 = V_142 -> V_166 ;
if ( V_143 && ! V_143 ( V_116 , V_144 ,
V_116 -> V_162 ) ) {
F_25 ( L_13 ) ;
F_78 ( V_116 , V_165 , NULL ) ;
* V_140 = V_167 ;
return 1 ;
}
}
F_78 ( V_116 , V_116 -> V_148 , V_140 + 1 ) ;
return 1 ;
}
int F_79 ( struct V_168 * V_168 , struct V_169 * V_169 )
{
int V_33 ;
struct V_22 * V_23 = F_5 ( V_168 -> V_170 -> V_171 , V_24 ) ;
F_6 ( & V_25 ) ;
if ( V_23 -> V_26 == NULL ) {
F_7 ( & V_25 ) ;
return - V_172 ;
}
F_46 ( V_23 -> V_26 ) ;
V_33 = F_80 ( V_23 -> V_26 , V_169 ) ;
F_7 ( & V_25 ) ;
return V_33 ;
}
int F_81 ( struct V_168 * V_168 , struct V_169 * V_169 )
{
int V_33 = F_82 ( V_168 , V_169 ) ;
struct V_20 * V_20 = V_168 -> V_170 -> V_171 ;
F_6 ( & V_25 ) ;
F_56 ( V_20 ) ;
F_7 ( & V_25 ) ;
return V_33 ;
}
