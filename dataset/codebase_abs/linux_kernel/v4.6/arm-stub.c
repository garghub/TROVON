static int F_1 ( T_1 * V_1 )
{
static T_2 const V_2 = V_3 ;
static T_3 const V_4 [] = {
'S' , 'e' , 'c' , 'u' , 'r' , 'e' , 'B' , 'o' , 'o' , 't' , 0 } ;
T_4 * V_5 = V_1 -> V_6 -> V_7 ;
unsigned long V_8 = sizeof( V_9 ) ;
T_5 V_10 ;
V_9 V_11 ;
V_10 = V_5 ( ( T_3 * ) V_4 , ( T_2 * ) & V_2 ,
NULL , & V_8 , & V_11 ) ;
switch ( V_10 ) {
case V_12 :
return V_11 ;
case V_13 :
return 0 ;
default:
return 1 ;
}
}
T_5 F_2 ( T_1 * V_1 ,
void * V_14 , void * * V_15 )
{
T_6 * V_16 ;
T_7 * V_17 = V_14 ;
T_8 * V_18 ;
T_2 V_19 = V_20 ;
T_5 V_10 ;
void * V_21 = ( void * ) ( unsigned long ) V_17 -> V_22 ;
V_10 = V_1 -> V_23 -> V_24 ( V_21 ,
& V_19 , ( void * * ) & V_16 ) ;
if ( V_10 != V_12 ) {
F_3 ( V_1 , L_1 ) ;
return V_10 ;
}
V_10 = V_16 -> V_25 ( V_16 , & V_18 ) ;
if ( V_10 != V_12 )
F_3 ( V_1 , L_2 ) ;
* V_15 = V_18 ;
return V_10 ;
}
T_5 F_4 ( void * V_21 )
{
T_8 * V_18 = V_21 ;
return V_18 -> V_26 ( V_21 ) ;
}
T_5
F_5 ( void * V_21 , unsigned long * V_8 , void * V_27 )
{
T_8 * V_18 = V_21 ;
return V_18 -> V_28 ( V_21 , V_8 , V_27 ) ;
}
T_5
F_6 ( T_1 * V_1 , void * V_15 ,
T_3 * V_29 , void * * V_21 , T_9 * V_30 )
{
T_8 * V_31 , * V_18 = V_15 ;
T_10 * V_32 ;
T_5 V_10 ;
T_2 V_33 = V_34 ;
unsigned long V_35 ;
V_10 = V_18 -> V_36 ( V_18 , & V_31 , V_29 , V_37 , ( T_9 ) 0 ) ;
if ( V_10 != V_12 ) {
F_3 ( V_1 , L_3 ) ;
F_7 ( V_1 , V_29 ) ;
F_3 ( V_1 , L_4 ) ;
return V_10 ;
}
* V_21 = V_31 ;
V_35 = 0 ;
V_10 = V_31 -> V_38 ( V_31 , & V_33 , & V_35 , NULL ) ;
if ( V_10 != V_39 ) {
F_3 ( V_1 , L_5 ) ;
return V_10 ;
}
V_40:
V_10 = V_1 -> V_23 -> V_41 ( V_42 ,
V_35 , ( void * * ) & V_32 ) ;
if ( V_10 != V_12 ) {
F_3 ( V_1 , L_6 ) ;
return V_10 ;
}
V_10 = V_31 -> V_38 ( V_31 , & V_33 , & V_35 ,
V_32 ) ;
if ( V_10 == V_39 ) {
V_1 -> V_23 -> V_43 ( V_32 ) ;
goto V_40;
}
* V_30 = V_32 -> V_44 ;
V_1 -> V_23 -> V_43 ( V_32 ) ;
if ( V_10 != V_12 )
F_3 ( V_1 , L_7 ) ;
return V_10 ;
}
void F_7 ( T_1 * V_1 ,
T_3 * V_45 )
{
struct V_46 * V_47 ;
V_47 = (struct V_46 * ) V_1 -> V_48 ;
V_47 -> V_49 ( V_47 , V_45 ) ;
}
unsigned long F_8 ( void * V_21 , T_1 * V_50 ,
unsigned long * V_51 )
{
T_7 * V_17 ;
T_5 V_10 ;
unsigned long V_52 = 0 ;
unsigned long V_53 ;
unsigned long V_54 ;
T_9 V_55 = 0 ;
unsigned long V_56 = 0 ;
unsigned long V_57 = 0 ;
char * V_58 = NULL ;
int V_59 = 0 ;
unsigned long V_60 ;
T_2 V_61 = V_62 ;
unsigned long V_63 = 0 ;
unsigned long V_64 = 0 ;
if ( V_50 -> V_65 . V_66 != V_67 )
goto V_68;
F_9 ( V_50 , L_8 ) ;
V_10 = F_10 ( V_50 ) ;
if ( V_10 != V_12 )
goto V_68;
V_10 = V_50 -> V_23 -> V_24 ( V_21 ,
& V_61 , ( void * ) & V_17 ) ;
if ( V_10 != V_12 ) {
F_11 ( V_50 , L_9 ) ;
goto V_68;
}
V_53 = F_12 ( V_50 ) ;
if ( V_53 == V_69 ) {
F_11 ( V_50 , L_10 ) ;
goto V_68;
}
V_58 = F_13 ( V_50 , V_17 , & V_59 ) ;
if ( ! V_58 ) {
F_11 ( V_50 , L_11 ) ;
goto V_68;
}
if ( F_14 ( V_70 ) ) {
static const V_9 V_71 [] = V_72 ;
const V_9 * V_45 , * V_73 = V_58 ;
if ( F_14 ( V_74 ) )
V_73 = V_71 ;
V_45 = strstr ( V_73 , L_12 ) ;
if ( V_45 == V_73 || ( V_45 > V_73 && * ( V_45 - 1 ) == ' ' ) )
V_75 = true ;
}
V_10 = F_15 ( V_50 , V_51 , & V_52 ,
& V_63 ,
& V_64 ,
V_53 , V_17 ) ;
if ( V_10 != V_12 ) {
F_11 ( V_50 , L_13 ) ;
goto V_76;
}
V_10 = F_16 ( V_58 ) ;
if ( V_10 != V_12 )
F_11 ( V_50 , L_14 ) ;
if ( F_1 ( V_50 ) ) {
F_9 ( V_50 , L_15 ) ;
} else {
V_10 = F_17 ( V_50 , V_17 , V_58 ,
L_16 ,
~ 0UL , & V_56 , & V_57 ) ;
if ( V_10 != V_12 ) {
F_11 ( V_50 , L_17 ) ;
goto V_77;
}
}
if ( V_56 ) {
F_9 ( V_50 , L_18 ) ;
} else {
V_56 = ( V_78 ) F_18 ( V_50 , & V_57 ) ;
if ( V_56 )
F_9 ( V_50 , L_19 ) ;
}
if ( ! V_56 )
F_9 ( V_50 , L_20 ) ;
V_10 = F_17 ( V_50 , V_17 , V_58 ,
L_21 , V_53 + V_79 ,
( unsigned long * ) & V_54 ,
( unsigned long * ) & V_55 ) ;
if ( V_10 != V_12 )
F_11 ( V_50 , L_22 ) ;
V_60 = V_56 ;
V_10 = F_19 ( V_50 , V_21 ,
& V_60 , V_53 + V_80 ,
V_54 , V_55 , V_58 ,
V_56 , V_57 ) ;
if ( V_10 == V_12 )
return V_60 ;
F_11 ( V_50 , L_23 ) ;
F_20 ( V_50 , V_55 , V_54 ) ;
F_20 ( V_50 , V_57 , V_56 ) ;
V_77:
F_20 ( V_50 , V_52 , * V_51 ) ;
F_20 ( V_50 , V_64 , V_63 ) ;
V_76:
F_20 ( V_50 , V_59 , ( unsigned long ) V_58 ) ;
V_68:
return V_69 ;
}
static int F_21 ( const void * V_81 , const void * V_82 )
{
const T_11 * V_83 = V_81 , * V_84 = V_82 ;
return ( V_83 -> V_85 > V_84 -> V_85 ) ? 1 : - 1 ;
}
static bool F_22 ( T_11 * V_83 ,
T_11 * V_84 )
{
T_9 V_86 ;
if ( V_83 == NULL || V_84 == NULL )
return false ;
V_86 = V_83 -> V_85 + V_83 -> V_87 * V_88 ;
return V_86 == V_84 -> V_85 ;
}
static bool F_23 ( T_11 * V_83 ,
T_11 * V_84 )
{
static const T_9 V_89 = V_90 | V_91 |
V_92 | V_93 |
V_94 ;
return ( ( V_83 -> V_95 ^ V_84 -> V_95 ) & V_89 ) == 0 ;
}
void F_24 ( T_11 * V_96 , unsigned long V_97 ,
unsigned long V_98 , T_11 * V_99 ,
int * V_100 )
{
T_9 V_101 = V_102 ;
T_11 * V_103 , * V_104 = NULL , * V_47 = V_99 ;
int V_81 ;
F_25 ( V_96 , V_97 / V_98 , V_98 , F_21 , NULL ) ;
for ( V_81 = 0 ; V_81 < V_97 ; V_81 += V_98 , V_104 = V_103 ) {
T_9 V_105 , V_8 ;
V_103 = ( void * ) V_96 + V_81 ;
if ( ! ( V_103 -> V_95 & V_94 ) )
continue;
V_105 = V_103 -> V_85 ;
V_8 = V_103 -> V_87 * V_88 ;
if ( ! F_22 ( V_104 , V_103 ) ||
! F_23 ( V_104 , V_103 ) ) {
V_105 = F_26 ( V_103 -> V_85 , V_106 ) ;
V_8 += V_103 -> V_85 - V_105 ;
if ( F_27 ( V_103 -> V_85 , V_107 ) && V_8 >= V_107 )
V_101 = F_28 ( V_101 , V_107 ) ;
else
V_101 = F_28 ( V_101 , V_106 ) ;
}
V_103 -> V_108 = V_101 + V_103 -> V_85 - V_105 ;
V_101 += V_8 ;
memcpy ( V_47 , V_103 , V_98 ) ;
V_47 = ( void * ) V_47 + V_98 ;
++ * V_100 ;
}
}
