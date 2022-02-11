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
static void F_18 ( struct V_34 * V_35 )
{
V_22 = NULL ;
F_16 () ;
F_19 ( V_35 ) ;
F_20 ( V_36 L_3
L_4 ) ;
F_21 () ;
}
void F_22 ( void )
{
int V_37 = 0 ;
int V_38 ;
for ( V_38 = V_4 ; V_38 < V_5 ; V_38 ++ ) {
if ( V_39 . V_40 [ V_38 ] )
V_37 = 1 ;
}
if ( ! V_37 ) {
for ( V_38 = V_4 ; V_38 < V_5 ; V_38 ++ )
V_39 . V_40 [ V_38 ] = V_8 [ V_38 ] ;
#if F_2 ( V_9 ) || F_2 ( V_10 )
for ( V_38 = V_41 ; V_38 < V_11 ; V_38 ++ )
V_42 . V_40 [ V_38 ] =
V_13 [ V_38 ] ;
#endif
}
}
static void F_23 ( void )
{
#define F_24 10
V_43 = ( F_25 ()
>> F_24 ) * V_44 ;
V_45 = 0 ;
F_26 ( & V_46 ) ;
F_27 ( L_5 , V_47 , V_43 ) ;
}
int F_28 ( void )
{
int V_48 = 0 ;
F_29 ( ! F_30 ( & V_21 ) ) ;
if ( V_22 ) {
F_31 ( V_22 ) ;
return 0 ;
}
if ( V_49 == 0 ) {
struct V_50 V_38 ;
F_32 ( & V_38 ) ;
V_49 = V_51 ;
V_38 . V_52 <<= V_53 - 12 ;
while ( V_49 > V_38 . V_52 &&
V_49 >= 8 * 1024 * 2 )
V_49 /= 2 ;
}
F_22 () ;
V_22 = F_33 ( & V_39 , V_49 ,
F_18 , V_54 , V_55 ) ;
if ( V_22 == NULL )
return - V_56 ;
F_23 () ;
F_34 ( & V_57 ) ;
return V_48 ;
}
int F_35 ( void )
{
if ( V_22 == NULL )
return 0 ;
else
return V_22 -> V_58 ;
}
int F_36 ( int V_59 , int * V_60 )
{
int V_38 = 0 ;
if ( V_22 != NULL ) {
for ( V_38 = 0 ; V_38 < V_22 -> V_58 && V_38 < V_59 ; V_38 ++ )
V_60 [ V_38 ] = V_22 -> V_61 [ V_38 ] . V_62 ;
}
return 0 ;
}
int F_37 ( int V_59 , int * V_60 )
{
int V_38 = 0 ;
int V_63 = 0 ;
int V_48 = 0 ;
F_29 ( ! F_30 ( & V_21 ) ) ;
if ( V_22 == NULL || V_59 <= 0 )
return 0 ;
if ( V_59 > V_22 -> V_58 )
V_59 = V_22 -> V_58 ;
V_63 = 0 ;
for ( V_38 = 0 ; V_38 < V_59 ; V_38 ++ ) {
if ( V_60 [ V_38 ] > V_64 )
V_60 [ V_38 ] = V_64 ;
V_63 += V_60 [ V_38 ] ;
}
if ( V_63 > V_64 ) {
for ( V_38 = 0 ; V_38 < V_59 && V_63 > 0 ; V_38 ++ ) {
int V_65 = V_60 [ V_38 ] * V_64 / V_63 ;
V_63 -= ( V_60 [ V_38 ] - V_65 ) ;
V_60 [ V_38 ] = V_65 ;
}
for ( V_38 = 0 ; V_38 < V_59 && V_63 > 0 ; V_38 ++ ) {
V_60 [ V_38 ] -- ;
V_63 -- ;
}
}
if ( V_60 [ 0 ] == 0 )
V_60 [ 0 ] = 1 ;
F_31 ( V_22 ) ;
for ( V_38 = 0 ; V_38 < V_59 ; V_38 ++ ) {
V_48 = F_38 ( V_22 , & V_22 -> V_61 [ V_38 ] ,
V_60 [ V_38 ] ) ;
if ( V_48 )
break;
}
F_39 ( V_22 ) ;
return V_48 ;
}
int
F_40 ( unsigned short V_24 , int V_29 )
{
int error ;
bool V_66 ;
F_5 ( & V_21 ) ;
F_27 ( L_6 ) ;
if ( V_29 <= 0 )
V_29 = 0 ;
if ( V_29 > V_64 )
V_29 = V_64 ;
error = 0 ;
if ( V_29 == 0 && V_22 == NULL )
goto V_67;
error = F_28 () ;
if ( error )
goto V_67;
V_66 = V_31 ;
error = F_10 ( V_24 , V_29 ) ;
if ( error )
goto V_68;
error = F_38 ( V_22 , NULL , V_29 ) ;
if ( error )
goto V_69;
error = V_22 -> V_23 - 1 ;
V_69:
if ( error < 0 && ! V_66 )
F_16 () ;
V_68:
F_39 ( V_22 ) ;
V_67:
F_6 ( & V_21 ) ;
return error ;
}
static int
V_54 ( void * V_70 )
{
struct V_71 * V_72 = (struct V_71 * ) V_70 ;
int V_48 , V_73 = 0 ;
F_5 ( & V_21 ) ;
if ( F_41 () < 0 ) {
F_20 ( L_7 ) ;
goto V_67;
}
V_74 -> V_75 -> V_76 = 0 ;
F_42 ( V_77 ) ;
F_42 ( V_78 ) ;
F_42 ( V_79 ) ;
F_42 ( V_80 ) ;
V_81 . V_82 ++ ;
F_6 ( & V_21 ) ;
V_74 -> V_83 |= V_84 ;
F_43 () ;
for (; ; ) {
while ( ( V_48 = F_44 ( V_72 , 60 * 60 * V_85 ) ) == - V_86 )
;
if ( V_48 == - V_87 )
break;
else if ( V_48 < 0 ) {
if ( V_48 != V_73 ) {
F_20 ( V_36 L_8
L_9 , V_47 , - V_48 ) ;
V_73 = V_48 ;
}
F_45 ( V_85 ) ;
continue;
}
F_46 () ;
F_47 ( V_72 ) ;
F_46 () ;
}
F_48 ( V_74 ) ;
F_5 ( & V_21 ) ;
V_81 . V_82 -- ;
V_67:
F_49 ( V_72 ) ;
F_6 ( & V_21 ) ;
F_50 ( 0 ) ;
return 0 ;
}
static T_2 F_51 ( T_1 V_1 , T_2 V_88 )
{
if ( V_88 == V_89 && V_1 == 2 )
return V_90 ;
if ( V_88 == V_91 && V_1 < 4 )
return V_92 ;
return V_88 ;
}
int
F_52 ( struct V_71 * V_72 , T_2 * V_93 )
{
struct V_94 * V_95 ;
T_3 V_96 ;
T_2 V_88 ;
T_2 * V_97 ;
F_27 ( L_10 ,
V_72 -> V_98 , V_72 -> V_99 ) ;
V_95 = V_72 -> V_100 ;
V_72 -> V_101 = V_95 -> V_102 ;
V_96 = V_95 -> V_103 ;
if ( V_96 && ! V_96 ( V_72 , ( T_2 * ) V_72 -> V_104 . V_105 [ 0 ] . V_106 ,
V_72 -> V_107 ) ) {
F_27 ( L_11 ) ;
* V_93 = V_108 ;
return 1 ;
}
switch ( F_53 ( V_72 ) ) {
case V_109 :
case V_110 :
return 0 ;
case V_111 :
return 1 ;
case V_112 : ;
}
V_97 = V_72 -> V_113 . V_105 [ 0 ] . V_106
+ V_72 -> V_113 . V_105 [ 0 ] . V_114 ;
V_72 -> V_113 . V_105 [ 0 ] . V_114 += sizeof( T_2 ) ;
V_88 = V_95 -> V_115 ( V_72 , V_72 -> V_107 , V_72 -> V_116 ) ;
V_88 = F_51 ( V_72 -> V_98 , V_88 ) ;
if ( V_88 == V_90 || V_72 -> V_117 ) {
F_27 ( L_12 ) ;
F_54 ( V_72 , V_118 , NULL ) ;
return 0 ;
}
if ( V_72 -> V_99 != 0 )
* V_97 ++ = V_88 ;
if ( ! ( V_88 && V_72 -> V_98 == 2 ) ) {
V_96 = V_95 -> V_119 ;
if ( V_96 && ! V_96 ( V_72 , V_97 ,
V_72 -> V_116 ) ) {
F_27 ( L_13 ) ;
F_54 ( V_72 , V_118 , NULL ) ;
* V_93 = V_120 ;
return 1 ;
}
}
F_54 ( V_72 , V_95 -> V_102 , V_93 + 1 ) ;
return 1 ;
}
int F_55 ( struct V_121 * V_121 , struct V_122 * V_122 )
{
int V_30 ;
F_5 ( & V_21 ) ;
if ( V_22 == NULL ) {
F_6 ( & V_21 ) ;
return - V_123 ;
}
F_31 ( V_22 ) ;
V_30 = F_56 ( V_22 , V_122 ) ;
F_6 ( & V_21 ) ;
return V_30 ;
}
int F_57 ( struct V_121 * V_121 , struct V_122 * V_122 )
{
int V_30 = F_58 ( V_121 , V_122 ) ;
F_5 ( & V_21 ) ;
F_39 ( V_22 ) ;
F_6 ( & V_21 ) ;
return V_30 ;
}
