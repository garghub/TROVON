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
V_10 = V_50 -> V_23 -> V_24 ( V_21 ,
& V_61 , ( void * ) & V_17 ) ;
if ( V_10 != V_12 ) {
F_10 ( V_50 , L_9 ) ;
goto V_68;
}
V_53 = F_11 ( V_50 ) ;
if ( V_53 == V_69 ) {
F_10 ( V_50 , L_10 ) ;
goto V_68;
}
V_10 = F_12 ( V_50 , V_51 , & V_52 ,
& V_63 ,
& V_64 ,
V_53 , V_17 ) ;
if ( V_10 != V_12 ) {
F_10 ( V_50 , L_11 ) ;
goto V_68;
}
V_58 = F_13 ( V_50 , V_17 , & V_59 ) ;
if ( ! V_58 ) {
F_10 ( V_50 , L_12 ) ;
goto V_70;
}
V_10 = F_14 ( V_58 ) ;
if ( V_10 != V_12 )
F_10 ( V_50 , L_13 ) ;
if ( F_1 ( V_50 ) ) {
F_9 ( V_50 , L_14 ) ;
} else {
V_10 = F_15 ( V_50 , V_17 , V_58 ,
L_15 ,
~ 0UL , & V_56 , & V_57 ) ;
if ( V_10 != V_12 ) {
F_10 ( V_50 , L_16 ) ;
goto V_71;
}
}
if ( V_56 ) {
F_9 ( V_50 , L_17 ) ;
} else {
V_56 = ( V_72 ) F_16 ( V_50 , & V_57 ) ;
if ( V_56 )
F_9 ( V_50 , L_18 ) ;
}
if ( ! V_56 )
F_9 ( V_50 , L_19 ) ;
V_10 = F_15 ( V_50 , V_17 , V_58 ,
L_20 , V_53 + V_73 ,
( unsigned long * ) & V_54 ,
( unsigned long * ) & V_55 ) ;
if ( V_10 != V_12 )
F_10 ( V_50 , L_21 ) ;
V_60 = V_56 ;
V_10 = F_17 ( V_50 , V_21 ,
& V_60 , V_53 + V_74 ,
V_54 , V_55 , V_58 ,
V_56 , V_57 ) ;
if ( V_10 == V_12 )
return V_60 ;
F_10 ( V_50 , L_22 ) ;
F_18 ( V_50 , V_55 , V_54 ) ;
F_18 ( V_50 , V_57 , V_56 ) ;
V_71:
F_18 ( V_50 , V_59 , ( unsigned long ) V_58 ) ;
V_70:
F_18 ( V_50 , V_52 , * V_51 ) ;
F_18 ( V_50 , V_64 , V_63 ) ;
V_68:
return V_69 ;
}
static int F_19 ( const void * V_75 , const void * V_76 )
{
const T_11 * V_77 = V_75 , * V_78 = V_76 ;
return ( V_77 -> V_79 > V_78 -> V_79 ) ? 1 : - 1 ;
}
static bool F_20 ( T_11 * V_77 ,
T_11 * V_78 )
{
T_9 V_80 ;
if ( V_77 == NULL || V_78 == NULL )
return false ;
V_80 = V_77 -> V_79 + V_77 -> V_81 * V_82 ;
return V_80 == V_78 -> V_79 ;
}
static bool F_21 ( T_11 * V_77 ,
T_11 * V_78 )
{
static const T_9 V_83 = V_84 | V_85 |
V_86 | V_87 |
V_88 ;
return ( ( V_77 -> V_89 ^ V_78 -> V_89 ) & V_83 ) == 0 ;
}
void F_22 ( T_11 * V_90 , unsigned long V_91 ,
unsigned long V_92 , T_11 * V_93 ,
int * V_94 )
{
T_9 V_95 = V_96 ;
T_11 * V_97 , * V_98 = NULL , * V_47 = V_93 ;
int V_75 ;
F_23 ( V_90 , V_91 / V_92 , V_92 , F_19 , NULL ) ;
for ( V_75 = 0 ; V_75 < V_91 ; V_75 += V_92 , V_98 = V_97 ) {
T_9 V_99 , V_8 ;
V_97 = ( void * ) V_90 + V_75 ;
if ( ! ( V_97 -> V_89 & V_88 ) )
continue;
V_99 = V_97 -> V_79 ;
V_8 = V_97 -> V_81 * V_82 ;
if ( ! F_20 ( V_98 , V_97 ) ||
! F_21 ( V_98 , V_97 ) ) {
V_99 = F_24 ( V_97 -> V_79 , V_100 ) ;
V_8 += V_97 -> V_79 - V_99 ;
if ( F_25 ( V_97 -> V_79 , V_101 ) && V_8 >= V_101 )
V_95 = F_26 ( V_95 , V_101 ) ;
else
V_95 = F_26 ( V_95 , V_100 ) ;
}
V_97 -> V_102 = V_95 + V_97 -> V_79 - V_99 ;
V_95 += V_8 ;
memcpy ( V_47 , V_97 , V_92 ) ;
V_47 = ( void * ) V_47 + V_92 ;
++ * V_94 ;
}
}
