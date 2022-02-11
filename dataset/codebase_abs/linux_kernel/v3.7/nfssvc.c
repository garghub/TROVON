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
V_19 = V_17 ;
break;
case V_14 :
if ( V_17 == 0 )
return - 1 ;
V_19 = V_17 - 1 ;
break;
case V_15 :
return V_17 <= V_19 ;
case V_16 :
return V_17 <= V_18 ;
}
return 0 ;
}
int F_4 ( void )
{
int V_20 = 0 ;
F_5 ( & V_21 ) ;
if ( V_22 )
V_20 = V_22 -> V_23 ;
F_6 ( & V_21 ) ;
return V_20 ;
}
static int F_7 ( void )
{
int error ;
if ( ! F_8 ( & V_22 -> V_24 ) )
return 0 ;
error = F_9 ( V_22 , L_1 , & V_25 , V_26 , V_27 ,
V_28 ) ;
if ( error < 0 )
return error ;
error = F_9 ( V_22 , L_2 , & V_25 , V_26 , V_27 ,
V_28 ) ;
if ( error < 0 )
return error ;
return 0 ;
}
static int F_10 ( int V_29 )
{
int V_30 ;
if ( V_31 )
return 0 ;
V_30 = F_11 ( 2 * V_29 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_7 () ;
if ( V_30 )
goto V_32;
V_30 = F_12 ( & V_25 ) ;
if ( V_30 )
goto V_32;
V_30 = F_13 () ;
if ( V_30 )
goto V_33;
V_31 = true ;
return 0 ;
V_33:
F_14 ( & V_25 ) ;
V_32:
F_15 () ;
return V_30 ;
}
static void F_16 ( void )
{
if ( ! V_31 )
return;
F_17 () ;
F_14 ( & V_25 ) ;
F_15 () ;
V_31 = false ;
}
static void F_18 ( struct V_34 * V_35 , struct V_36 * V_36 )
{
F_16 () ;
F_19 ( V_35 , V_36 ) ;
F_20 ( V_37 L_3
L_4 ) ;
F_21 ( V_36 ) ;
}
void F_22 ( void )
{
int V_38 = 0 ;
int V_39 ;
for ( V_39 = V_4 ; V_39 < V_5 ; V_39 ++ ) {
if ( V_40 . V_41 [ V_39 ] )
V_38 = 1 ;
}
if ( ! V_38 ) {
for ( V_39 = V_4 ; V_39 < V_5 ; V_39 ++ )
V_40 . V_41 [ V_39 ] = V_8 [ V_39 ] ;
#if F_2 ( V_9 ) || F_2 ( V_10 )
for ( V_39 = V_42 ; V_39 < V_11 ; V_39 ++ )
V_43 . V_41 [ V_39 ] =
V_13 [ V_39 ] ;
#endif
}
}
static void F_23 ( void )
{
#define F_24 10
V_44 = ( F_25 ()
>> F_24 ) * V_45 ;
V_46 = 0 ;
F_26 ( & V_47 ) ;
F_27 ( L_5 , V_48 , V_44 ) ;
}
static int F_28 ( void )
{
struct V_49 V_39 ;
unsigned long long V_50 ;
unsigned long V_30 ;
F_29 ( & V_39 ) ;
V_50 = ( V_39 . V_51 - V_39 . V_52 ) << V_53 ;
V_50 >>= 12 ;
V_30 = V_54 ;
while ( V_30 > V_50 && V_30 >= 8 * 1024 * 2 )
V_30 /= 2 ;
return V_30 ;
}
int F_30 ( void )
{
int error ;
struct V_36 * V_36 = V_55 -> V_56 -> V_57 ;
F_31 ( ! F_32 ( & V_21 ) ) ;
if ( V_22 ) {
F_33 ( V_22 ) ;
return 0 ;
}
if ( V_58 == 0 )
V_58 = F_28 () ;
F_22 () ;
V_22 = F_34 ( & V_40 , V_58 ,
F_18 , V_59 , V_60 ) ;
if ( V_22 == NULL )
return - V_61 ;
error = F_35 ( V_22 , V_36 ) ;
if ( error < 0 ) {
F_36 ( V_22 ) ;
return error ;
}
F_23 () ;
F_37 ( & V_62 ) ;
return 0 ;
}
int F_38 ( void )
{
if ( V_22 == NULL )
return 0 ;
else
return V_22 -> V_63 ;
}
int F_39 ( int V_64 , int * V_65 )
{
int V_39 = 0 ;
if ( V_22 != NULL ) {
for ( V_39 = 0 ; V_39 < V_22 -> V_63 && V_39 < V_64 ; V_39 ++ )
V_65 [ V_39 ] = V_22 -> V_66 [ V_39 ] . V_67 ;
}
return 0 ;
}
int F_40 ( int V_64 , int * V_65 )
{
int V_39 = 0 ;
int V_68 = 0 ;
int V_69 = 0 ;
struct V_36 * V_36 = & V_25 ;
F_31 ( ! F_32 ( & V_21 ) ) ;
if ( V_22 == NULL || V_64 <= 0 )
return 0 ;
if ( V_64 > V_22 -> V_63 )
V_64 = V_22 -> V_63 ;
V_68 = 0 ;
for ( V_39 = 0 ; V_39 < V_64 ; V_39 ++ ) {
if ( V_65 [ V_39 ] > V_70 )
V_65 [ V_39 ] = V_70 ;
V_68 += V_65 [ V_39 ] ;
}
if ( V_68 > V_70 ) {
for ( V_39 = 0 ; V_39 < V_64 && V_68 > 0 ; V_39 ++ ) {
int V_71 = V_65 [ V_39 ] * V_70 / V_68 ;
V_68 -= ( V_65 [ V_39 ] - V_71 ) ;
V_65 [ V_39 ] = V_71 ;
}
for ( V_39 = 0 ; V_39 < V_64 && V_68 > 0 ; V_39 ++ ) {
V_65 [ V_39 ] -- ;
V_68 -- ;
}
}
if ( V_65 [ 0 ] == 0 )
V_65 [ 0 ] = 1 ;
F_33 ( V_22 ) ;
for ( V_39 = 0 ; V_39 < V_64 ; V_39 ++ ) {
V_69 = F_41 ( V_22 , & V_22 -> V_66 [ V_39 ] ,
V_65 [ V_39 ] ) ;
if ( V_69 )
break;
}
F_42 ( V_36 ) ;
return V_69 ;
}
int
F_43 ( int V_29 )
{
int error ;
bool V_72 ;
struct V_36 * V_36 = & V_25 ;
F_5 ( & V_21 ) ;
F_27 ( L_6 ) ;
if ( V_29 <= 0 )
V_29 = 0 ;
if ( V_29 > V_70 )
V_29 = V_70 ;
error = 0 ;
if ( V_29 == 0 && V_22 == NULL )
goto V_73;
error = F_30 () ;
if ( error )
goto V_73;
V_72 = V_31 ;
error = F_10 ( V_29 ) ;
if ( error )
goto V_74;
error = F_41 ( V_22 , NULL , V_29 ) ;
if ( error )
goto V_75;
error = V_22 -> V_23 - 1 ;
V_75:
if ( error < 0 && ! V_72 )
F_16 () ;
V_74:
F_42 ( V_36 ) ;
V_73:
F_6 ( & V_21 ) ;
return error ;
}
static int
V_59 ( void * V_76 )
{
struct V_77 * V_78 = (struct V_77 * ) V_76 ;
int V_69 ;
F_5 ( & V_21 ) ;
if ( F_44 () < 0 ) {
F_20 ( L_7 ) ;
goto V_73;
}
V_55 -> V_79 -> V_80 = 0 ;
F_45 ( V_81 ) ;
F_45 ( V_82 ) ;
F_45 ( V_83 ) ;
F_45 ( V_84 ) ;
V_85 . V_86 ++ ;
F_6 ( & V_21 ) ;
V_55 -> V_87 |= V_88 ;
F_46 () ;
for (; ; ) {
while ( ( V_69 = F_47 ( V_78 , 60 * 60 * V_89 ) ) == - V_90 )
;
if ( V_69 == - V_91 )
break;
F_48 () ;
F_49 ( V_78 ) ;
F_48 () ;
}
F_50 ( V_55 ) ;
F_5 ( & V_21 ) ;
V_85 . V_86 -- ;
V_73:
V_78 -> V_92 = NULL ;
F_51 ( V_78 ) ;
F_42 ( & V_25 ) ;
F_6 ( & V_21 ) ;
F_52 ( 0 ) ;
return 0 ;
}
static T_2 F_53 ( T_1 V_1 , T_2 V_93 )
{
if ( V_93 == V_94 && V_1 == 2 )
return V_95 ;
if ( V_93 == V_96 && V_1 < 4 )
return V_97 ;
return V_93 ;
}
int
F_54 ( struct V_77 * V_78 , T_2 * V_98 )
{
struct V_99 * V_100 ;
T_3 V_101 ;
T_2 V_93 ;
T_2 * V_102 ;
F_27 ( L_8 ,
V_78 -> V_103 , V_78 -> V_104 ) ;
V_100 = V_78 -> V_105 ;
V_78 -> V_106 = V_100 -> V_107 ;
V_101 = V_100 -> V_108 ;
if ( V_101 && ! V_101 ( V_78 , ( T_2 * ) V_78 -> V_109 . V_110 [ 0 ] . V_111 ,
V_78 -> V_112 ) ) {
F_27 ( L_9 ) ;
* V_98 = V_113 ;
return 1 ;
}
switch ( F_55 ( V_78 ) ) {
case V_114 :
case V_115 :
return 0 ;
case V_116 :
return 1 ;
case V_117 : ;
}
V_102 = V_78 -> V_118 . V_110 [ 0 ] . V_111
+ V_78 -> V_118 . V_110 [ 0 ] . V_119 ;
V_78 -> V_118 . V_110 [ 0 ] . V_119 += sizeof( T_2 ) ;
V_93 = V_100 -> V_120 ( V_78 , V_78 -> V_112 , V_78 -> V_121 ) ;
V_93 = F_53 ( V_78 -> V_103 , V_93 ) ;
if ( V_93 == V_95 || V_78 -> V_122 ) {
F_27 ( L_10 ) ;
F_56 ( V_78 , V_123 , NULL ) ;
return 0 ;
}
if ( V_78 -> V_104 != 0 )
* V_102 ++ = V_93 ;
if ( ! ( V_93 && V_78 -> V_103 == 2 ) ) {
V_101 = V_100 -> V_124 ;
if ( V_101 && ! V_101 ( V_78 , V_102 ,
V_78 -> V_121 ) ) {
F_27 ( L_11 ) ;
F_56 ( V_78 , V_123 , NULL ) ;
* V_98 = V_125 ;
return 1 ;
}
}
F_56 ( V_78 , V_100 -> V_107 , V_98 + 1 ) ;
return 1 ;
}
int F_57 ( struct V_126 * V_126 , struct V_127 * V_127 )
{
int V_30 ;
F_5 ( & V_21 ) ;
if ( V_22 == NULL ) {
F_6 ( & V_21 ) ;
return - V_128 ;
}
F_33 ( V_22 ) ;
V_30 = F_58 ( V_22 , V_127 ) ;
F_6 ( & V_21 ) ;
return V_30 ;
}
int F_59 ( struct V_126 * V_126 , struct V_127 * V_127 )
{
int V_30 = F_60 ( V_126 , V_127 ) ;
struct V_36 * V_36 = & V_25 ;
F_5 ( & V_21 ) ;
F_42 ( V_36 ) ;
F_6 ( & V_21 ) ;
return V_30 ;
}
