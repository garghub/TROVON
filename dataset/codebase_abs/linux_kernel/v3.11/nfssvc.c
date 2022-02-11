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
static int F_17 ( int V_32 , struct V_20 * V_20 )
{
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
int V_33 ;
if ( V_23 -> V_36 )
return 0 ;
V_33 = F_11 ( V_32 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_8 ( V_20 ) ;
if ( V_33 )
goto V_37;
V_33 = F_18 ( V_20 ) ;
if ( V_33 )
goto V_37;
V_33 = F_19 ( V_20 ) ;
if ( V_33 )
goto V_38;
V_23 -> V_36 = true ;
return 0 ;
V_38:
F_20 ( V_20 ) ;
V_37:
F_15 () ;
return V_33 ;
}
static void F_21 ( struct V_20 * V_20 )
{
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
F_22 ( V_20 ) ;
F_20 ( V_20 ) ;
V_23 -> V_36 = false ;
F_15 () ;
}
static void F_23 ( struct V_39 * V_40 , struct V_20 * V_20 )
{
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
if ( ! V_23 -> V_36 )
return;
F_21 ( V_20 ) ;
F_24 ( V_40 , V_20 ) ;
F_25 ( V_41 L_3
L_4 ) ;
F_26 ( V_20 ) ;
}
void F_27 ( void )
{
int V_42 = 0 ;
int V_43 ;
for ( V_43 = V_4 ; V_43 < V_5 ; V_43 ++ ) {
if ( V_44 . V_45 [ V_43 ] )
V_42 = 1 ;
}
if ( ! V_42 ) {
for ( V_43 = V_4 ; V_43 < V_5 ; V_43 ++ )
V_44 . V_45 [ V_43 ] = V_8 [ V_43 ] ;
#if F_2 ( V_9 ) || F_2 ( V_10 )
for ( V_43 = V_46 ; V_43 < V_11 ; V_43 ++ )
V_47 . V_45 [ V_43 ] =
V_13 [ V_43 ] ;
#endif
}
}
static void F_28 ( void )
{
#define F_29 10
V_48 = ( F_30 ()
>> F_29 ) * V_49 ;
V_50 = 0 ;
F_31 ( & V_51 ) ;
F_32 ( L_5 , V_52 , V_48 ) ;
}
static int F_33 ( void )
{
struct V_53 V_43 ;
unsigned long long V_54 ;
unsigned long V_33 ;
F_34 ( & V_43 ) ;
V_54 = ( V_43 . V_55 - V_43 . V_56 ) << V_57 ;
V_54 >>= 12 ;
V_33 = V_58 ;
while ( V_33 > V_54 && V_33 >= 8 * 1024 * 2 )
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
if ( V_59 == 0 )
V_59 = F_33 () ;
F_27 () ;
V_23 -> V_26 = F_39 ( & V_44 , V_59 ,
F_23 , V_60 , V_61 ) ;
if ( V_23 -> V_26 == NULL )
return - V_62 ;
error = F_40 ( V_23 -> V_26 , V_20 ) ;
if ( error < 0 ) {
F_41 ( V_23 -> V_26 ) ;
return error ;
}
F_28 () ;
F_42 ( & V_23 -> V_63 ) ;
return 0 ;
}
int F_43 ( struct V_20 * V_20 )
{
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
if ( V_23 -> V_26 == NULL )
return 0 ;
else
return V_23 -> V_26 -> V_64 ;
}
int F_44 ( int V_65 , int * V_66 , struct V_20 * V_20 )
{
int V_43 = 0 ;
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
if ( V_23 -> V_26 != NULL ) {
for ( V_43 = 0 ; V_43 < V_23 -> V_26 -> V_64 && V_43 < V_65 ; V_43 ++ )
V_66 [ V_43 ] = V_23 -> V_26 -> V_67 [ V_43 ] . V_68 ;
}
return 0 ;
}
void F_45 ( struct V_20 * V_20 )
{
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
int V_69 = ( V_23 -> V_26 -> V_27 == 1 ) ;
if ( V_69 )
F_46 ( V_23 -> V_26 , V_20 ) ;
F_41 ( V_23 -> V_26 ) ;
if ( V_69 )
V_23 -> V_26 = NULL ;
}
int F_47 ( int V_65 , int * V_66 , struct V_20 * V_20 )
{
int V_43 = 0 ;
int V_70 = 0 ;
int V_71 = 0 ;
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
F_36 ( ! F_37 ( & V_25 ) ) ;
if ( V_23 -> V_26 == NULL || V_65 <= 0 )
return 0 ;
if ( V_65 > V_23 -> V_26 -> V_64 )
V_65 = V_23 -> V_26 -> V_64 ;
V_70 = 0 ;
for ( V_43 = 0 ; V_43 < V_65 ; V_43 ++ ) {
if ( V_66 [ V_43 ] > V_72 )
V_66 [ V_43 ] = V_72 ;
V_70 += V_66 [ V_43 ] ;
}
if ( V_70 > V_72 ) {
for ( V_43 = 0 ; V_43 < V_65 && V_70 > 0 ; V_43 ++ ) {
int V_73 = V_66 [ V_43 ] * V_72 / V_70 ;
V_70 -= ( V_66 [ V_43 ] - V_73 ) ;
V_66 [ V_43 ] = V_73 ;
}
for ( V_43 = 0 ; V_43 < V_65 && V_70 > 0 ; V_43 ++ ) {
V_66 [ V_43 ] -- ;
V_70 -- ;
}
}
if ( V_66 [ 0 ] == 0 )
V_66 [ 0 ] = 1 ;
F_38 ( V_23 -> V_26 ) ;
for ( V_43 = 0 ; V_43 < V_65 ; V_43 ++ ) {
V_71 = F_48 ( V_23 -> V_26 , & V_23 -> V_26 -> V_67 [ V_43 ] ,
V_66 [ V_43 ] ) ;
if ( V_71 )
break;
}
F_45 ( V_20 ) ;
return V_71 ;
}
int
F_49 ( int V_32 , struct V_20 * V_20 )
{
int error ;
bool V_74 ;
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
F_6 ( & V_25 ) ;
F_32 ( L_6 ) ;
if ( V_32 <= 0 )
V_32 = 0 ;
if ( V_32 > V_72 )
V_32 = V_72 ;
error = 0 ;
if ( V_32 == 0 && V_23 -> V_26 == NULL )
goto V_75;
error = F_35 ( V_20 ) ;
if ( error )
goto V_75;
V_74 = V_23 -> V_36 ;
error = F_17 ( V_32 , V_20 ) ;
if ( error )
goto V_76;
error = F_48 ( V_23 -> V_26 , NULL , V_32 ) ;
if ( error )
goto V_77;
error = V_23 -> V_26 -> V_27 - 1 ;
V_77:
if ( error < 0 && ! V_74 )
F_21 ( V_20 ) ;
V_76:
F_45 ( V_20 ) ;
V_75:
F_7 ( & V_25 ) ;
return error ;
}
static int
V_60 ( void * V_78 )
{
struct V_79 * V_80 = (struct V_79 * ) V_78 ;
struct V_81 * V_82 = F_50 ( V_80 -> V_83 -> V_28 . V_84 , F_51 ( struct V_81 ) , V_85 ) ;
struct V_20 * V_20 = V_82 -> V_86 ;
int V_71 ;
F_6 ( & V_25 ) ;
if ( F_52 () < 0 ) {
F_25 ( L_7 ) ;
goto V_75;
}
V_87 -> V_88 -> V_89 = 0 ;
F_53 ( V_90 ) ;
F_53 ( V_91 ) ;
F_53 ( V_92 ) ;
F_53 ( V_93 ) ;
V_94 . V_95 ++ ;
F_7 ( & V_25 ) ;
V_87 -> V_96 |= V_97 ;
F_54 () ;
for (; ; ) {
while ( ( V_71 = F_55 ( V_80 , 60 * 60 * V_98 ) ) == - V_99 )
;
if ( V_71 == - V_100 )
break;
F_56 () ;
F_57 ( V_80 ) ;
F_56 () ;
}
F_58 ( V_87 ) ;
F_6 ( & V_25 ) ;
V_94 . V_95 -- ;
V_75:
V_80 -> V_83 = NULL ;
F_59 ( V_80 ) ;
F_45 ( V_20 ) ;
F_7 ( & V_25 ) ;
F_60 ( 0 ) ;
return 0 ;
}
static T_2 F_61 ( T_1 V_1 , T_2 V_101 )
{
if ( V_101 == V_102 && V_1 == 2 )
return V_103 ;
if ( V_101 == V_104 && V_1 < 4 )
return V_105 ;
return V_101 ;
}
int
F_62 ( struct V_79 * V_80 , T_2 * V_106 )
{
struct V_107 * V_108 ;
T_3 V_109 ;
T_2 V_101 ;
T_2 * V_110 ;
F_32 ( L_8 ,
V_80 -> V_111 , V_80 -> V_112 ) ;
V_108 = V_80 -> V_113 ;
V_80 -> V_114 = V_108 -> V_115 ;
V_109 = V_108 -> V_116 ;
if ( V_109 && ! V_109 ( V_80 , ( T_2 * ) V_80 -> V_117 . V_118 [ 0 ] . V_119 ,
V_80 -> V_120 ) ) {
F_32 ( L_9 ) ;
* V_106 = V_121 ;
return 1 ;
}
switch ( F_63 ( V_80 ) ) {
case V_122 :
return 0 ;
case V_123 :
return 1 ;
case V_124 : ;
}
V_110 = V_80 -> V_125 . V_118 [ 0 ] . V_119
+ V_80 -> V_125 . V_118 [ 0 ] . V_126 ;
V_80 -> V_125 . V_118 [ 0 ] . V_126 += sizeof( T_2 ) ;
V_101 = V_108 -> V_127 ( V_80 , V_80 -> V_120 , V_80 -> V_128 ) ;
V_101 = F_61 ( V_80 -> V_111 , V_101 ) ;
if ( V_101 == V_103 || V_80 -> V_129 ) {
F_32 ( L_10 ) ;
F_64 ( V_80 , V_130 , NULL ) ;
return 0 ;
}
if ( V_80 -> V_112 != 0 )
* V_110 ++ = V_101 ;
if ( ! ( V_101 && V_80 -> V_111 == 2 ) ) {
V_109 = V_108 -> V_131 ;
if ( V_109 && ! V_109 ( V_80 , V_110 ,
V_80 -> V_128 ) ) {
F_32 ( L_11 ) ;
F_64 ( V_80 , V_130 , NULL ) ;
* V_106 = V_132 ;
return 1 ;
}
}
F_64 ( V_80 , V_80 -> V_114 , V_106 + 1 ) ;
return 1 ;
}
int F_65 ( struct V_133 * V_133 , struct V_134 * V_134 )
{
int V_33 ;
struct V_22 * V_23 = F_5 ( V_133 -> V_135 -> V_136 , V_24 ) ;
F_6 ( & V_25 ) ;
if ( V_23 -> V_26 == NULL ) {
F_7 ( & V_25 ) ;
return - V_137 ;
}
F_38 ( V_23 -> V_26 ) ;
V_33 = F_66 ( V_23 -> V_26 , V_134 ) ;
F_7 ( & V_25 ) ;
return V_33 ;
}
int F_67 ( struct V_133 * V_133 , struct V_134 * V_134 )
{
int V_33 = F_68 ( V_133 , V_134 ) ;
struct V_20 * V_20 = V_133 -> V_135 -> V_136 ;
F_6 ( & V_25 ) ;
F_45 ( V_20 ) ;
F_7 ( & V_25 ) ;
return V_33 ;
}
