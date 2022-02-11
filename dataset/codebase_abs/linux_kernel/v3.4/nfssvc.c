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
static int F_7 ( int V_24 )
{
int error ;
if ( ! F_8 ( & V_22 -> V_25 ) )
return 0 ;
error = F_9 ( V_22 , L_1 , & V_26 , V_27 , V_24 ,
V_28 ) ;
if ( error < 0 )
return error ;
error = F_9 ( V_22 , L_2 , & V_26 , V_27 , V_24 ,
V_28 ) ;
if ( error < 0 )
return error ;
return 0 ;
}
static int F_10 ( unsigned short V_24 , int V_29 )
{
int V_30 ;
if ( V_31 )
return 0 ;
V_30 = F_11 ( 2 * V_29 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_7 ( V_24 ) ;
if ( V_30 )
goto V_32;
V_30 = F_12 () ;
if ( V_30 )
goto V_32;
V_30 = F_13 () ;
if ( V_30 )
goto V_33;
V_31 = true ;
return 0 ;
V_33:
F_14 () ;
V_32:
F_15 () ;
return V_30 ;
}
static void F_16 ( void )
{
if ( ! V_31 )
return;
F_17 () ;
F_14 () ;
F_15 () ;
V_31 = false ;
}
static void F_18 ( struct V_34 * V_35 , struct V_36 * V_36 )
{
V_22 = NULL ;
F_16 () ;
F_19 ( V_35 , V_36 ) ;
F_20 ( V_37 L_3
L_4 ) ;
F_21 () ;
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
F_31 ( ! F_32 ( & V_21 ) ) ;
if ( V_22 ) {
F_33 ( V_22 ) ;
return 0 ;
}
if ( V_55 == 0 )
V_55 = F_28 () ;
F_22 () ;
V_22 = F_34 ( & V_40 , V_55 ,
F_18 , V_56 , V_57 ) ;
if ( V_22 == NULL )
return - V_58 ;
F_23 () ;
F_35 ( & V_59 ) ;
return 0 ;
}
int F_36 ( void )
{
if ( V_22 == NULL )
return 0 ;
else
return V_22 -> V_60 ;
}
int F_37 ( int V_61 , int * V_62 )
{
int V_39 = 0 ;
if ( V_22 != NULL ) {
for ( V_39 = 0 ; V_39 < V_22 -> V_60 && V_39 < V_61 ; V_39 ++ )
V_62 [ V_39 ] = V_22 -> V_63 [ V_39 ] . V_64 ;
}
return 0 ;
}
int F_38 ( int V_61 , int * V_62 )
{
int V_39 = 0 ;
int V_65 = 0 ;
int V_66 = 0 ;
F_31 ( ! F_32 ( & V_21 ) ) ;
if ( V_22 == NULL || V_61 <= 0 )
return 0 ;
if ( V_61 > V_22 -> V_60 )
V_61 = V_22 -> V_60 ;
V_65 = 0 ;
for ( V_39 = 0 ; V_39 < V_61 ; V_39 ++ ) {
if ( V_62 [ V_39 ] > V_67 )
V_62 [ V_39 ] = V_67 ;
V_65 += V_62 [ V_39 ] ;
}
if ( V_65 > V_67 ) {
for ( V_39 = 0 ; V_39 < V_61 && V_65 > 0 ; V_39 ++ ) {
int V_68 = V_62 [ V_39 ] * V_67 / V_65 ;
V_65 -= ( V_62 [ V_39 ] - V_68 ) ;
V_62 [ V_39 ] = V_68 ;
}
for ( V_39 = 0 ; V_39 < V_61 && V_65 > 0 ; V_39 ++ ) {
V_62 [ V_39 ] -- ;
V_65 -- ;
}
}
if ( V_62 [ 0 ] == 0 )
V_62 [ 0 ] = 1 ;
F_33 ( V_22 ) ;
for ( V_39 = 0 ; V_39 < V_61 ; V_39 ++ ) {
V_66 = F_39 ( V_22 , & V_22 -> V_63 [ V_39 ] ,
V_62 [ V_39 ] ) ;
if ( V_66 )
break;
}
F_40 ( V_22 ) ;
return V_66 ;
}
int
F_41 ( unsigned short V_24 , int V_29 )
{
int error ;
bool V_69 ;
F_5 ( & V_21 ) ;
F_27 ( L_6 ) ;
if ( V_29 <= 0 )
V_29 = 0 ;
if ( V_29 > V_67 )
V_29 = V_67 ;
error = 0 ;
if ( V_29 == 0 && V_22 == NULL )
goto V_70;
error = F_30 () ;
if ( error )
goto V_70;
V_69 = V_31 ;
error = F_10 ( V_24 , V_29 ) ;
if ( error )
goto V_71;
error = F_39 ( V_22 , NULL , V_29 ) ;
if ( error )
goto V_72;
error = V_22 -> V_23 - 1 ;
V_72:
if ( error < 0 && ! V_69 )
F_16 () ;
V_71:
F_40 ( V_22 ) ;
V_70:
F_6 ( & V_21 ) ;
return error ;
}
static int
V_56 ( void * V_73 )
{
struct V_74 * V_75 = (struct V_74 * ) V_73 ;
int V_66 , V_76 = 0 ;
F_5 ( & V_21 ) ;
if ( F_42 () < 0 ) {
F_20 ( L_7 ) ;
goto V_70;
}
V_77 -> V_78 -> V_79 = 0 ;
F_43 ( V_80 ) ;
F_43 ( V_81 ) ;
F_43 ( V_82 ) ;
F_43 ( V_83 ) ;
V_84 . V_85 ++ ;
F_6 ( & V_21 ) ;
V_77 -> V_86 |= V_87 ;
F_44 () ;
for (; ; ) {
while ( ( V_66 = F_45 ( V_75 , 60 * 60 * V_88 ) ) == - V_89 )
;
if ( V_66 == - V_90 )
break;
else if ( V_66 < 0 ) {
if ( V_66 != V_76 ) {
F_20 ( V_37 L_8
L_9 , V_48 , - V_66 ) ;
V_76 = V_66 ;
}
F_46 ( V_88 ) ;
continue;
}
F_47 () ;
F_48 ( V_75 ) ;
F_47 () ;
}
F_49 ( V_77 ) ;
F_5 ( & V_21 ) ;
V_84 . V_85 -- ;
V_70:
F_50 ( V_75 ) ;
F_6 ( & V_21 ) ;
F_51 ( 0 ) ;
return 0 ;
}
static T_2 F_52 ( T_1 V_1 , T_2 V_91 )
{
if ( V_91 == V_92 && V_1 == 2 )
return V_93 ;
if ( V_91 == V_94 && V_1 < 4 )
return V_95 ;
return V_91 ;
}
int
F_53 ( struct V_74 * V_75 , T_2 * V_96 )
{
struct V_97 * V_98 ;
T_3 V_99 ;
T_2 V_91 ;
T_2 * V_100 ;
F_27 ( L_10 ,
V_75 -> V_101 , V_75 -> V_102 ) ;
V_98 = V_75 -> V_103 ;
V_75 -> V_104 = V_98 -> V_105 ;
V_99 = V_98 -> V_106 ;
if ( V_99 && ! V_99 ( V_75 , ( T_2 * ) V_75 -> V_107 . V_108 [ 0 ] . V_109 ,
V_75 -> V_110 ) ) {
F_27 ( L_11 ) ;
* V_96 = V_111 ;
return 1 ;
}
switch ( F_54 ( V_75 ) ) {
case V_112 :
case V_113 :
return 0 ;
case V_114 :
return 1 ;
case V_115 : ;
}
V_100 = V_75 -> V_116 . V_108 [ 0 ] . V_109
+ V_75 -> V_116 . V_108 [ 0 ] . V_117 ;
V_75 -> V_116 . V_108 [ 0 ] . V_117 += sizeof( T_2 ) ;
V_91 = V_98 -> V_118 ( V_75 , V_75 -> V_110 , V_75 -> V_119 ) ;
V_91 = F_52 ( V_75 -> V_101 , V_91 ) ;
if ( V_91 == V_93 || V_75 -> V_120 ) {
F_27 ( L_12 ) ;
F_55 ( V_75 , V_121 , NULL ) ;
return 0 ;
}
if ( V_75 -> V_102 != 0 )
* V_100 ++ = V_91 ;
if ( ! ( V_91 && V_75 -> V_101 == 2 ) ) {
V_99 = V_98 -> V_122 ;
if ( V_99 && ! V_99 ( V_75 , V_100 ,
V_75 -> V_119 ) ) {
F_27 ( L_13 ) ;
F_55 ( V_75 , V_121 , NULL ) ;
* V_96 = V_123 ;
return 1 ;
}
}
F_55 ( V_75 , V_98 -> V_105 , V_96 + 1 ) ;
return 1 ;
}
int F_56 ( struct V_124 * V_124 , struct V_125 * V_125 )
{
int V_30 ;
F_5 ( & V_21 ) ;
if ( V_22 == NULL ) {
F_6 ( & V_21 ) ;
return - V_126 ;
}
F_33 ( V_22 ) ;
V_30 = F_57 ( V_22 , V_125 ) ;
F_6 ( & V_21 ) ;
return V_30 ;
}
int F_58 ( struct V_124 * V_124 , struct V_125 * V_125 )
{
int V_30 = F_59 ( V_124 , V_125 ) ;
F_5 ( & V_21 ) ;
F_40 ( V_22 ) ;
F_6 ( & V_21 ) ;
return V_30 ;
}
