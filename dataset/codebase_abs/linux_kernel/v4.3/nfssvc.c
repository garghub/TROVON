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
static void F_23 ( struct V_42 * V_43 , struct V_20 * V_20 )
{
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
if ( ! V_23 -> V_38 )
return;
F_21 ( V_20 ) ;
F_24 ( V_43 , V_20 ) ;
F_25 ( V_44 L_3
L_4 ) ;
F_26 ( V_20 ) ;
}
void F_27 ( void )
{
int V_45 = 0 ;
int V_46 ;
for ( V_46 = V_4 ; V_46 < V_5 ; V_46 ++ ) {
if ( V_47 . V_48 [ V_46 ] )
V_45 = 1 ;
}
if ( ! V_45 ) {
for ( V_46 = V_4 ; V_46 < V_5 ; V_46 ++ )
V_47 . V_48 [ V_46 ] = V_8 [ V_46 ] ;
#if F_2 ( V_9 ) || F_2 ( V_10 )
for ( V_46 = V_49 ; V_46 < V_11 ; V_46 ++ )
V_50 . V_48 [ V_46 ] =
V_13 [ V_46 ] ;
#endif
}
}
static void F_28 ( void )
{
#define F_29 10
V_51 = ( F_30 ()
>> F_29 ) * V_52 ;
V_53 = 0 ;
F_31 ( & V_54 ) ;
F_32 ( L_5 , V_55 , V_51 ) ;
}
static int F_33 ( void )
{
struct V_56 V_46 ;
unsigned long long V_57 ;
unsigned long V_33 ;
F_34 ( & V_46 ) ;
V_57 = ( V_46 . V_58 - V_46 . V_59 ) << V_60 ;
V_57 >>= 12 ;
V_33 = V_61 ;
while ( V_33 > V_57 && V_33 >= 8 * 1024 * 2 )
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
if ( V_62 == 0 )
V_62 = F_33 () ;
F_27 () ;
V_23 -> V_26 = F_39 ( & V_47 , V_62 ,
& V_63 ) ;
if ( V_23 -> V_26 == NULL )
return - V_64 ;
V_23 -> V_26 -> V_65 = V_23 -> V_66 ;
error = F_40 ( V_23 -> V_26 , V_20 ) ;
if ( error < 0 ) {
F_41 ( V_23 -> V_26 ) ;
return error ;
}
F_28 () ;
F_42 ( & V_23 -> V_67 ) ;
return 0 ;
}
int F_43 ( struct V_20 * V_20 )
{
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
if ( V_23 -> V_26 == NULL )
return 0 ;
else
return V_23 -> V_26 -> V_68 ;
}
int F_44 ( int V_69 , int * V_70 , struct V_20 * V_20 )
{
int V_46 = 0 ;
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
if ( V_23 -> V_26 != NULL ) {
for ( V_46 = 0 ; V_46 < V_23 -> V_26 -> V_68 && V_46 < V_69 ; V_46 ++ )
V_70 [ V_46 ] = V_23 -> V_26 -> V_71 [ V_46 ] . V_72 ;
}
return 0 ;
}
void F_45 ( struct V_20 * V_20 )
{
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
int V_73 = ( V_23 -> V_26 -> V_27 == 1 ) ;
if ( V_73 )
F_46 ( V_23 -> V_26 , V_20 ) ;
F_41 ( V_23 -> V_26 ) ;
if ( V_73 )
V_23 -> V_26 = NULL ;
}
int F_47 ( int V_69 , int * V_70 , struct V_20 * V_20 )
{
int V_46 = 0 ;
int V_74 = 0 ;
int V_75 = 0 ;
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
F_36 ( ! F_37 ( & V_25 ) ) ;
if ( V_23 -> V_26 == NULL || V_69 <= 0 )
return 0 ;
if ( V_69 > V_23 -> V_26 -> V_68 )
V_69 = V_23 -> V_26 -> V_68 ;
V_74 = 0 ;
for ( V_46 = 0 ; V_46 < V_69 ; V_46 ++ ) {
V_70 [ V_46 ] = F_48 ( V_70 [ V_46 ] , V_76 ) ;
V_74 += V_70 [ V_46 ] ;
}
if ( V_74 > V_76 ) {
for ( V_46 = 0 ; V_46 < V_69 && V_74 > 0 ; V_46 ++ ) {
int V_77 = V_70 [ V_46 ] * V_76 / V_74 ;
V_74 -= ( V_70 [ V_46 ] - V_77 ) ;
V_70 [ V_46 ] = V_77 ;
}
for ( V_46 = 0 ; V_46 < V_69 && V_74 > 0 ; V_46 ++ ) {
V_70 [ V_46 ] -- ;
V_74 -- ;
}
}
if ( V_70 [ 0 ] == 0 )
V_70 [ 0 ] = 1 ;
F_38 ( V_23 -> V_26 ) ;
for ( V_46 = 0 ; V_46 < V_69 ; V_46 ++ ) {
V_75 = V_23 -> V_26 -> V_78 -> V_79 ( V_23 -> V_26 ,
& V_23 -> V_26 -> V_71 [ V_46 ] , V_70 [ V_46 ] ) ;
if ( V_75 )
break;
}
F_45 ( V_20 ) ;
return V_75 ;
}
int
F_49 ( int V_32 , struct V_20 * V_20 )
{
int error ;
bool V_80 ;
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
F_6 ( & V_25 ) ;
F_32 ( L_6 ) ;
V_32 = F_50 ( V_32 , 0 ) ;
V_32 = F_48 ( V_32 , V_76 ) ;
error = 0 ;
if ( V_32 == 0 && V_23 -> V_26 == NULL )
goto V_81;
error = F_35 ( V_20 ) ;
if ( error )
goto V_81;
V_80 = V_23 -> V_38 ;
error = F_18 ( V_32 , V_20 ) ;
if ( error )
goto V_82;
error = V_23 -> V_26 -> V_78 -> V_79 ( V_23 -> V_26 ,
NULL , V_32 ) ;
if ( error )
goto V_83;
error = V_23 -> V_26 -> V_27 - 1 ;
V_83:
if ( error < 0 && ! V_80 )
F_21 ( V_20 ) ;
V_82:
F_45 ( V_20 ) ;
V_81:
F_7 ( & V_25 ) ;
return error ;
}
static int
F_51 ( void * V_84 )
{
struct V_85 * V_86 = (struct V_85 * ) V_84 ;
struct V_87 * V_88 = F_52 ( V_86 -> V_89 -> V_28 . V_90 , F_53 ( struct V_87 ) , V_91 ) ;
struct V_20 * V_20 = V_88 -> V_92 ;
struct V_22 * V_23 = F_5 ( V_20 , V_24 ) ;
int V_75 ;
F_6 ( & V_25 ) ;
if ( F_54 () < 0 ) {
F_25 ( L_7 ) ;
goto V_81;
}
V_93 -> V_94 -> V_95 = 0 ;
F_55 ( V_96 ) ;
F_55 ( V_97 ) ;
F_55 ( V_98 ) ;
F_55 ( V_99 ) ;
V_100 . V_101 ++ ;
F_7 ( & V_25 ) ;
F_56 () ;
for (; ; ) {
V_86 -> V_89 -> V_65 = V_23 -> V_66 ;
while ( ( V_75 = F_57 ( V_86 , 60 * 60 * V_102 ) ) == - V_103 )
;
if ( V_75 == - V_104 )
break;
F_58 () ;
F_59 ( V_86 ) ;
F_58 () ;
}
F_60 ( V_93 ) ;
F_6 ( & V_25 ) ;
V_100 . V_101 -- ;
V_81:
V_86 -> V_89 = NULL ;
F_61 ( V_86 ) ;
F_45 ( V_20 ) ;
F_7 ( & V_25 ) ;
F_62 ( 0 ) ;
return 0 ;
}
static T_2 F_63 ( T_1 V_1 , T_2 V_105 )
{
if ( V_105 == V_106 && V_1 == 2 )
return V_107 ;
if ( V_105 == V_108 && V_1 < 4 )
return V_109 ;
return V_105 ;
}
int
F_64 ( struct V_85 * V_86 , T_2 * V_110 )
{
struct V_111 * V_112 ;
T_3 V_113 ;
T_2 V_105 ;
T_2 * V_114 ;
F_32 ( L_8 ,
V_86 -> V_115 , V_86 -> V_116 ) ;
V_112 = V_86 -> V_117 ;
V_86 -> V_118 = V_112 -> V_119 ;
V_113 = V_112 -> V_120 ;
if ( V_113 && ! V_113 ( V_86 , ( T_2 * ) V_86 -> V_121 . V_122 [ 0 ] . V_123 ,
V_86 -> V_124 ) ) {
F_32 ( L_9 ) ;
* V_110 = V_125 ;
return 1 ;
}
switch ( F_65 ( V_86 ) ) {
case V_126 :
return 0 ;
case V_127 :
return 1 ;
case V_128 : ;
}
V_114 = V_86 -> V_129 . V_122 [ 0 ] . V_123
+ V_86 -> V_129 . V_122 [ 0 ] . V_130 ;
V_86 -> V_129 . V_122 [ 0 ] . V_130 += sizeof( T_2 ) ;
V_105 = V_112 -> V_131 ( V_86 , V_86 -> V_124 , V_86 -> V_132 ) ;
V_105 = F_63 ( V_86 -> V_115 , V_105 ) ;
if ( V_105 == V_107 || F_66 ( V_133 , & V_86 -> V_134 ) ) {
F_32 ( L_10 ) ;
F_67 ( V_86 , V_135 , NULL ) ;
return 0 ;
}
if ( V_86 -> V_116 != 0 )
* V_114 ++ = V_105 ;
if ( ! ( V_105 && V_86 -> V_115 == 2 ) ) {
V_113 = V_112 -> V_136 ;
if ( V_113 && ! V_113 ( V_86 , V_114 ,
V_86 -> V_132 ) ) {
F_32 ( L_11 ) ;
F_67 ( V_86 , V_135 , NULL ) ;
* V_110 = V_137 ;
return 1 ;
}
}
F_67 ( V_86 , V_86 -> V_118 , V_110 + 1 ) ;
return 1 ;
}
int F_68 ( struct V_138 * V_138 , struct V_139 * V_139 )
{
int V_33 ;
struct V_22 * V_23 = F_5 ( V_138 -> V_140 -> V_141 , V_24 ) ;
F_6 ( & V_25 ) ;
if ( V_23 -> V_26 == NULL ) {
F_7 ( & V_25 ) ;
return - V_142 ;
}
F_38 ( V_23 -> V_26 ) ;
V_33 = F_69 ( V_23 -> V_26 , V_139 ) ;
F_7 ( & V_25 ) ;
return V_33 ;
}
int F_70 ( struct V_138 * V_138 , struct V_139 * V_139 )
{
int V_33 = F_71 ( V_138 , V_139 ) ;
struct V_20 * V_20 = V_138 -> V_140 -> V_141 ;
F_6 ( & V_25 ) ;
F_45 ( V_20 ) ;
F_7 ( & V_25 ) ;
return V_33 ;
}
