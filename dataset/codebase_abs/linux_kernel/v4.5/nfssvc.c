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
F_29 ( & V_71 ) ;
#if F_30 ( V_72 )
F_31 ( & V_73 ) ;
#endif
F_32 ( V_70 , V_20 ) ;
if ( ! V_23 -> V_38 )
return;
F_21 ( V_20 ) ;
F_33 ( V_74 L_5
L_6 ) ;
F_34 ( V_20 ) ;
}
void F_35 ( void )
{
int V_75 = 0 ;
int V_76 ;
for ( V_76 = V_4 ; V_76 < V_5 ; V_76 ++ ) {
if ( V_77 . V_78 [ V_76 ] )
V_75 = 1 ;
}
if ( ! V_75 ) {
for ( V_76 = V_4 ; V_76 < V_5 ; V_76 ++ )
V_77 . V_78 [ V_76 ] = V_8 [ V_76 ] ;
#if F_2 ( V_9 ) || F_2 ( V_10 )
for ( V_76 = V_79 ; V_76 < V_11 ; V_76 ++ )
V_80 . V_78 [ V_76 ] =
V_13 [ V_76 ] ;
#endif
}
}
static void F_36 ( void )
{
#define F_37 10
V_81 = ( F_38 ()
>> F_37 ) * V_82 ;
V_83 = 0 ;
F_39 ( & V_84 ) ;
F_25 ( L_7 , V_85 , V_81 ) ;
}
static int F_40 ( void )
{
struct V_86 V_76 ;
unsigned long long V_87 ;
unsigned long V_33 ;
F_41 ( & V_76 ) ;
V_87 = ( V_76 . V_88 - V_76 . V_89 ) << V_90 ;
V_87 >>= 12 ;
V_33 = V_91 ;
while ( V_33 > V_87 && V_33 >= 8 * 1024 * 2 )
V_33 /= 2 ;
return V_33 ;
}
int F_42 ( struct V_20 * V_20 )
{
int error ;
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
F_43 ( ! F_44 ( & V_25 ) ) ;
if ( V_23 -> V_26 ) {
F_45 ( V_23 -> V_26 ) ;
return 0 ;
}
if ( V_92 == 0 )
V_92 = F_40 () ;
F_35 () ;
V_23 -> V_26 = F_46 ( & V_77 , V_92 ,
& V_93 ) ;
if ( V_23 -> V_26 == NULL )
return - V_94 ;
V_23 -> V_26 -> V_95 = V_23 -> V_96 ;
error = F_47 ( V_23 -> V_26 , V_20 ) ;
if ( error < 0 ) {
F_48 ( V_23 -> V_26 ) ;
return error ;
}
F_36 () ;
F_49 ( & V_71 ) ;
#if F_30 ( V_72 )
F_50 ( & V_73 ) ;
#endif
F_51 ( & V_23 -> V_97 ) ;
return 0 ;
}
int F_52 ( struct V_20 * V_20 )
{
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
if ( V_23 -> V_26 == NULL )
return 0 ;
else
return V_23 -> V_26 -> V_98 ;
}
int F_53 ( int V_99 , int * V_100 , struct V_20 * V_20 )
{
int V_76 = 0 ;
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
if ( V_23 -> V_26 != NULL ) {
for ( V_76 = 0 ; V_76 < V_23 -> V_26 -> V_98 && V_76 < V_99 ; V_76 ++ )
V_100 [ V_76 ] = V_23 -> V_26 -> V_101 [ V_76 ] . V_102 ;
}
return 0 ;
}
void F_54 ( struct V_20 * V_20 )
{
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
int V_103 = ( V_23 -> V_26 -> V_27 == 1 ) ;
if ( V_103 )
F_55 ( V_23 -> V_26 , V_20 ) ;
F_48 ( V_23 -> V_26 ) ;
if ( V_103 )
V_23 -> V_26 = NULL ;
}
int F_56 ( int V_99 , int * V_100 , struct V_20 * V_20 )
{
int V_76 = 0 ;
int V_104 = 0 ;
int V_105 = 0 ;
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
F_43 ( ! F_44 ( & V_25 ) ) ;
if ( V_23 -> V_26 == NULL || V_99 <= 0 )
return 0 ;
if ( V_99 > V_23 -> V_26 -> V_98 )
V_99 = V_23 -> V_26 -> V_98 ;
V_104 = 0 ;
for ( V_76 = 0 ; V_76 < V_99 ; V_76 ++ ) {
V_100 [ V_76 ] = F_57 ( V_100 [ V_76 ] , V_106 ) ;
V_104 += V_100 [ V_76 ] ;
}
if ( V_104 > V_106 ) {
for ( V_76 = 0 ; V_76 < V_99 && V_104 > 0 ; V_76 ++ ) {
int V_107 = V_100 [ V_76 ] * V_106 / V_104 ;
V_104 -= ( V_100 [ V_76 ] - V_107 ) ;
V_100 [ V_76 ] = V_107 ;
}
for ( V_76 = 0 ; V_76 < V_99 && V_104 > 0 ; V_76 ++ ) {
V_100 [ V_76 ] -- ;
V_104 -- ;
}
}
if ( V_100 [ 0 ] == 0 )
V_100 [ 0 ] = 1 ;
F_45 ( V_23 -> V_26 ) ;
for ( V_76 = 0 ; V_76 < V_99 ; V_76 ++ ) {
V_105 = V_23 -> V_26 -> V_108 -> V_109 ( V_23 -> V_26 ,
& V_23 -> V_26 -> V_101 [ V_76 ] , V_100 [ V_76 ] ) ;
if ( V_105 )
break;
}
F_54 ( V_20 ) ;
return V_105 ;
}
int
F_58 ( int V_32 , struct V_20 * V_20 )
{
int error ;
bool V_110 ;
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
F_6 ( & V_25 ) ;
F_25 ( L_8 ) ;
V_32 = F_59 ( V_32 , 0 ) ;
V_32 = F_57 ( V_32 , V_106 ) ;
error = 0 ;
if ( V_32 == 0 && V_23 -> V_26 == NULL )
goto V_53;
error = F_42 ( V_20 ) ;
if ( error )
goto V_53;
V_110 = V_23 -> V_38 ;
error = F_18 ( V_32 , V_20 ) ;
if ( error )
goto V_111;
error = V_23 -> V_26 -> V_108 -> V_109 ( V_23 -> V_26 ,
NULL , V_32 ) ;
if ( error )
goto V_112;
error = V_23 -> V_26 -> V_27 - 1 ;
V_112:
if ( error < 0 && ! V_110 )
F_21 ( V_20 ) ;
V_111:
F_54 ( V_20 ) ;
V_53:
F_7 ( & V_25 ) ;
return error ;
}
static int
F_60 ( void * V_113 )
{
struct V_114 * V_115 = (struct V_114 * ) V_113 ;
struct V_116 * V_117 = F_61 ( V_115 -> V_118 -> V_28 . V_119 , F_62 ( struct V_116 ) , V_120 ) ;
struct V_20 * V_20 = V_117 -> V_121 ;
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
int V_105 ;
F_6 ( & V_25 ) ;
if ( F_63 () < 0 ) {
F_33 ( L_9 ) ;
goto V_53;
}
V_122 -> V_123 -> V_124 = 0 ;
F_64 ( V_125 ) ;
F_64 ( V_126 ) ;
F_64 ( V_127 ) ;
F_64 ( V_128 ) ;
V_129 . V_130 ++ ;
F_7 ( & V_25 ) ;
F_65 () ;
for (; ; ) {
V_115 -> V_118 -> V_95 = V_23 -> V_96 ;
while ( ( V_105 = F_66 ( V_115 , 60 * 60 * V_131 ) ) == - V_132 )
;
if ( V_105 == - V_133 )
break;
F_67 () ;
F_68 ( V_115 ) ;
F_67 () ;
}
F_69 ( V_122 ) ;
F_6 ( & V_25 ) ;
V_129 . V_130 -- ;
V_53:
V_115 -> V_118 = NULL ;
F_70 ( V_115 ) ;
F_54 ( V_20 ) ;
F_7 ( & V_25 ) ;
F_71 ( 0 ) ;
return 0 ;
}
static T_2 F_72 ( T_1 V_1 , T_2 V_134 )
{
if ( V_134 == V_135 && V_1 == 2 )
return V_136 ;
if ( V_134 == V_137 && V_1 < 4 )
return V_138 ;
return V_134 ;
}
int
F_73 ( struct V_114 * V_115 , T_2 * V_139 )
{
struct V_140 * V_141 ;
T_3 V_142 ;
T_2 V_134 ;
T_2 * V_143 ;
F_25 ( L_10 ,
V_115 -> V_144 , V_115 -> V_145 ) ;
V_141 = V_115 -> V_146 ;
V_115 -> V_147 = V_141 -> V_148 ;
V_142 = V_141 -> V_149 ;
if ( V_142 && ! V_142 ( V_115 , ( T_2 * ) V_115 -> V_150 . V_151 [ 0 ] . V_152 ,
V_115 -> V_153 ) ) {
F_25 ( L_11 ) ;
* V_139 = V_154 ;
return 1 ;
}
switch ( F_74 ( V_115 ) ) {
case V_155 :
return 0 ;
case V_156 :
return 1 ;
case V_157 : ;
}
V_143 = V_115 -> V_158 . V_151 [ 0 ] . V_152
+ V_115 -> V_158 . V_151 [ 0 ] . V_159 ;
V_115 -> V_158 . V_151 [ 0 ] . V_159 += sizeof( T_2 ) ;
V_134 = V_141 -> V_160 ( V_115 , V_115 -> V_153 , V_115 -> V_161 ) ;
V_134 = F_72 ( V_115 -> V_144 , V_134 ) ;
if ( V_134 == V_136 || F_75 ( V_162 , & V_115 -> V_163 ) ) {
F_25 ( L_12 ) ;
F_76 ( V_115 , V_164 , NULL ) ;
return 0 ;
}
if ( V_115 -> V_145 != 0 )
* V_143 ++ = V_134 ;
if ( ! ( V_134 && V_115 -> V_144 == 2 ) ) {
V_142 = V_141 -> V_165 ;
if ( V_142 && ! V_142 ( V_115 , V_143 ,
V_115 -> V_161 ) ) {
F_25 ( L_13 ) ;
F_76 ( V_115 , V_164 , NULL ) ;
* V_139 = V_166 ;
return 1 ;
}
}
F_76 ( V_115 , V_115 -> V_147 , V_139 + 1 ) ;
return 1 ;
}
int F_77 ( struct V_167 * V_167 , struct V_168 * V_168 )
{
int V_33 ;
struct V_22 * V_23 = F_5 ( V_167 -> V_169 -> V_170 , V_24 ) ;
F_6 ( & V_25 ) ;
if ( V_23 -> V_26 == NULL ) {
F_7 ( & V_25 ) ;
return - V_171 ;
}
F_45 ( V_23 -> V_26 ) ;
V_33 = F_78 ( V_23 -> V_26 , V_168 ) ;
F_7 ( & V_25 ) ;
return V_33 ;
}
int F_79 ( struct V_167 * V_167 , struct V_168 * V_168 )
{
int V_33 = F_80 ( V_167 , V_168 ) ;
struct V_20 * V_20 = V_167 -> V_169 -> V_170 ;
F_6 ( & V_25 ) ;
F_54 ( V_20 ) ;
F_7 ( & V_25 ) ;
return V_33 ;
}
