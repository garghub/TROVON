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
return V_33 ;
V_33 = F_13 () ;
if ( V_33 )
goto V_35;
return 0 ;
V_35:
F_14 () ;
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
#if F_2 ( V_36 )
return ( V_7 [ 2 ] != NULL ) || ( V_7 [ 3 ] != NULL ) ;
#else
return ( V_7 [ 2 ] != NULL ) ;
#endif
}
static int F_18 ( int V_32 , struct V_20 * V_20 )
{
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
int V_33 ;
if ( V_23 -> V_37 )
return 0 ;
V_33 = F_11 ( V_32 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_8 ( V_20 ) ;
if ( V_33 )
goto V_38;
if ( F_17 () && ! V_23 -> V_39 ) {
V_33 = V_39 ( V_20 ) ;
if ( V_33 )
goto V_38;
V_23 -> V_39 = 1 ;
}
V_33 = F_19 ( V_20 ) ;
if ( V_33 )
goto V_40;
V_23 -> V_37 = true ;
return 0 ;
V_40:
if ( V_23 -> V_39 ) {
F_20 ( V_20 ) ;
V_23 -> V_39 = 0 ;
}
V_38:
F_15 () ;
return V_33 ;
}
static void F_21 ( struct V_20 * V_20 )
{
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
F_22 ( V_20 ) ;
if ( V_23 -> V_39 ) {
F_20 ( V_20 ) ;
V_23 -> V_39 = 0 ;
}
V_23 -> V_37 = false ;
F_15 () ;
}
static void F_23 ( struct V_41 * V_42 , struct V_20 * V_20 )
{
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
if ( ! V_23 -> V_37 )
return;
F_21 ( V_20 ) ;
F_24 ( V_42 , V_20 ) ;
F_25 ( V_43 L_3
L_4 ) ;
F_26 ( V_20 ) ;
}
void F_27 ( void )
{
int V_44 = 0 ;
int V_45 ;
for ( V_45 = V_4 ; V_45 < V_5 ; V_45 ++ ) {
if ( V_46 . V_47 [ V_45 ] )
V_44 = 1 ;
}
if ( ! V_44 ) {
for ( V_45 = V_4 ; V_45 < V_5 ; V_45 ++ )
V_46 . V_47 [ V_45 ] = V_8 [ V_45 ] ;
#if F_2 ( V_9 ) || F_2 ( V_10 )
for ( V_45 = V_48 ; V_45 < V_11 ; V_45 ++ )
V_49 . V_47 [ V_45 ] =
V_13 [ V_45 ] ;
#endif
}
}
static void F_28 ( void )
{
#define F_29 10
V_50 = ( F_30 ()
>> F_29 ) * V_51 ;
V_52 = 0 ;
F_31 ( & V_53 ) ;
F_32 ( L_5 , V_54 , V_50 ) ;
}
static int F_33 ( void )
{
struct V_55 V_45 ;
unsigned long long V_56 ;
unsigned long V_33 ;
F_34 ( & V_45 ) ;
V_56 = ( V_45 . V_57 - V_45 . V_58 ) << V_59 ;
V_56 >>= 12 ;
V_33 = V_60 ;
while ( V_33 > V_56 && V_33 >= 8 * 1024 * 2 )
V_33 /= 2 ;
return V_33 ;
}
int F_35 ( struct V_20 * V_20 )
{
int error ;
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
F_36 ( ! F_37 ( & V_25 ) ) ;
if ( V_23 -> V_26 ) {
F_38 ( V_23 -> V_26 ) ;
return 0 ;
}
if ( V_61 == 0 )
V_61 = F_33 () ;
F_27 () ;
V_23 -> V_26 = F_39 ( & V_46 , V_61 ,
F_23 , V_62 , V_63 ) ;
if ( V_23 -> V_26 == NULL )
return - V_64 ;
error = F_40 ( V_23 -> V_26 , V_20 ) ;
if ( error < 0 ) {
F_41 ( V_23 -> V_26 ) ;
return error ;
}
F_28 () ;
F_42 ( & V_23 -> V_65 ) ;
return 0 ;
}
int F_43 ( struct V_20 * V_20 )
{
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
if ( V_23 -> V_26 == NULL )
return 0 ;
else
return V_23 -> V_26 -> V_66 ;
}
int F_44 ( int V_67 , int * V_68 , struct V_20 * V_20 )
{
int V_45 = 0 ;
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
if ( V_23 -> V_26 != NULL ) {
for ( V_45 = 0 ; V_45 < V_23 -> V_26 -> V_66 && V_45 < V_67 ; V_45 ++ )
V_68 [ V_45 ] = V_23 -> V_26 -> V_69 [ V_45 ] . V_70 ;
}
return 0 ;
}
void F_45 ( struct V_20 * V_20 )
{
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
int V_71 = ( V_23 -> V_26 -> V_27 == 1 ) ;
if ( V_71 )
F_46 ( V_23 -> V_26 , V_20 ) ;
F_41 ( V_23 -> V_26 ) ;
if ( V_71 )
V_23 -> V_26 = NULL ;
}
int F_47 ( int V_67 , int * V_68 , struct V_20 * V_20 )
{
int V_45 = 0 ;
int V_72 = 0 ;
int V_73 = 0 ;
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
F_36 ( ! F_37 ( & V_25 ) ) ;
if ( V_23 -> V_26 == NULL || V_67 <= 0 )
return 0 ;
if ( V_67 > V_23 -> V_26 -> V_66 )
V_67 = V_23 -> V_26 -> V_66 ;
V_72 = 0 ;
for ( V_45 = 0 ; V_45 < V_67 ; V_45 ++ ) {
if ( V_68 [ V_45 ] > V_74 )
V_68 [ V_45 ] = V_74 ;
V_72 += V_68 [ V_45 ] ;
}
if ( V_72 > V_74 ) {
for ( V_45 = 0 ; V_45 < V_67 && V_72 > 0 ; V_45 ++ ) {
int V_75 = V_68 [ V_45 ] * V_74 / V_72 ;
V_72 -= ( V_68 [ V_45 ] - V_75 ) ;
V_68 [ V_45 ] = V_75 ;
}
for ( V_45 = 0 ; V_45 < V_67 && V_72 > 0 ; V_45 ++ ) {
V_68 [ V_45 ] -- ;
V_72 -- ;
}
}
if ( V_68 [ 0 ] == 0 )
V_68 [ 0 ] = 1 ;
F_38 ( V_23 -> V_26 ) ;
for ( V_45 = 0 ; V_45 < V_67 ; V_45 ++ ) {
V_73 = F_48 ( V_23 -> V_26 , & V_23 -> V_26 -> V_69 [ V_45 ] ,
V_68 [ V_45 ] ) ;
if ( V_73 )
break;
}
F_45 ( V_20 ) ;
return V_73 ;
}
int
F_49 ( int V_32 , struct V_20 * V_20 )
{
int error ;
bool V_76 ;
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
F_6 ( & V_25 ) ;
F_32 ( L_6 ) ;
if ( V_32 <= 0 )
V_32 = 0 ;
if ( V_32 > V_74 )
V_32 = V_74 ;
error = 0 ;
if ( V_32 == 0 && V_23 -> V_26 == NULL )
goto V_77;
error = F_35 ( V_20 ) ;
if ( error )
goto V_77;
V_76 = V_23 -> V_37 ;
error = F_18 ( V_32 , V_20 ) ;
if ( error )
goto V_78;
error = F_48 ( V_23 -> V_26 , NULL , V_32 ) ;
if ( error )
goto V_79;
error = V_23 -> V_26 -> V_27 - 1 ;
V_79:
if ( error < 0 && ! V_76 )
F_21 ( V_20 ) ;
V_78:
F_45 ( V_20 ) ;
V_77:
F_7 ( & V_25 ) ;
return error ;
}
static int
V_62 ( void * V_80 )
{
struct V_81 * V_82 = (struct V_81 * ) V_80 ;
struct V_83 * V_84 = F_50 ( V_82 -> V_85 -> V_28 . V_86 , F_51 ( struct V_83 ) , V_87 ) ;
struct V_20 * V_20 = V_84 -> V_88 ;
int V_73 ;
F_6 ( & V_25 ) ;
if ( F_52 () < 0 ) {
F_25 ( L_7 ) ;
goto V_77;
}
V_89 -> V_90 -> V_91 = 0 ;
F_53 ( V_92 ) ;
F_53 ( V_93 ) ;
F_53 ( V_94 ) ;
F_53 ( V_95 ) ;
V_96 . V_97 ++ ;
F_7 ( & V_25 ) ;
V_89 -> V_98 |= V_99 ;
F_54 () ;
for (; ; ) {
while ( ( V_73 = F_55 ( V_82 , 60 * 60 * V_100 ) ) == - V_101 )
;
if ( V_73 == - V_102 )
break;
F_56 () ;
F_57 ( V_82 ) ;
F_56 () ;
}
F_58 ( V_89 ) ;
F_6 ( & V_25 ) ;
V_96 . V_97 -- ;
V_77:
V_82 -> V_85 = NULL ;
F_59 ( V_82 ) ;
F_45 ( V_20 ) ;
F_7 ( & V_25 ) ;
F_60 ( 0 ) ;
return 0 ;
}
static T_2 F_61 ( T_1 V_1 , T_2 V_103 )
{
if ( V_103 == V_104 && V_1 == 2 )
return V_105 ;
if ( V_103 == V_106 && V_1 < 4 )
return V_107 ;
return V_103 ;
}
int
F_62 ( struct V_81 * V_82 , T_2 * V_108 )
{
struct V_109 * V_110 ;
T_3 V_111 ;
T_2 V_103 ;
T_2 * V_112 ;
F_32 ( L_8 ,
V_82 -> V_113 , V_82 -> V_114 ) ;
V_110 = V_82 -> V_115 ;
V_82 -> V_116 = V_110 -> V_117 ;
V_111 = V_110 -> V_118 ;
if ( V_111 && ! V_111 ( V_82 , ( T_2 * ) V_82 -> V_119 . V_120 [ 0 ] . V_121 ,
V_82 -> V_122 ) ) {
F_32 ( L_9 ) ;
* V_108 = V_123 ;
return 1 ;
}
switch ( F_63 ( V_82 ) ) {
case V_124 :
return 0 ;
case V_125 :
return 1 ;
case V_126 : ;
}
V_112 = V_82 -> V_127 . V_120 [ 0 ] . V_121
+ V_82 -> V_127 . V_120 [ 0 ] . V_128 ;
V_82 -> V_127 . V_120 [ 0 ] . V_128 += sizeof( T_2 ) ;
V_103 = V_110 -> V_129 ( V_82 , V_82 -> V_122 , V_82 -> V_130 ) ;
V_103 = F_61 ( V_82 -> V_113 , V_103 ) ;
if ( V_103 == V_105 || V_82 -> V_131 ) {
F_32 ( L_10 ) ;
F_64 ( V_82 , V_132 , NULL ) ;
return 0 ;
}
if ( V_82 -> V_114 != 0 )
* V_112 ++ = V_103 ;
if ( ! ( V_103 && V_82 -> V_113 == 2 ) ) {
V_111 = V_110 -> V_133 ;
if ( V_111 && ! V_111 ( V_82 , V_112 ,
V_82 -> V_130 ) ) {
F_32 ( L_11 ) ;
F_64 ( V_82 , V_132 , NULL ) ;
* V_108 = V_134 ;
return 1 ;
}
}
F_64 ( V_82 , V_82 -> V_116 , V_108 + 1 ) ;
return 1 ;
}
int F_65 ( struct V_135 * V_135 , struct V_136 * V_136 )
{
int V_33 ;
struct V_22 * V_23 = F_5 ( V_135 -> V_137 -> V_138 , V_24 ) ;
F_6 ( & V_25 ) ;
if ( V_23 -> V_26 == NULL ) {
F_7 ( & V_25 ) ;
return - V_139 ;
}
F_38 ( V_23 -> V_26 ) ;
V_33 = F_66 ( V_23 -> V_26 , V_136 ) ;
F_7 ( & V_25 ) ;
return V_33 ;
}
int F_67 ( struct V_135 * V_135 , struct V_136 * V_136 )
{
int V_33 = F_68 ( V_135 , V_136 ) ;
struct V_20 * V_20 = V_135 -> V_137 -> V_138 ;
F_6 ( & V_25 ) ;
F_45 ( V_20 ) ;
F_7 ( & V_25 ) ;
return V_33 ;
}
