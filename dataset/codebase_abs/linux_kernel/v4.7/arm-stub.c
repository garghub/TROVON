static int F_1 ( T_1 * V_1 )
{
static T_2 const V_2 [] = {
'S' , 'e' , 'c' , 'u' , 'r' , 'e' , 'B' , 'o' , 'o' , 't' , 0 } ;
static T_2 const V_3 [] = {
'S' , 'e' , 't' , 'u' , 'p' , 'M' , 'o' , 'd' , 'e' , 0 } ;
T_3 V_4 = V_5 ;
T_4 * V_6 = V_1 -> V_7 -> V_8 ;
T_5 V_9 ;
unsigned long V_10 = sizeof( V_9 ) ;
T_6 V_11 ;
V_11 = V_6 ( ( T_2 * ) V_2 , ( T_3 * ) & V_4 ,
NULL , & V_10 , & V_9 ) ;
if ( V_11 != V_12 )
goto V_13;
if ( V_9 == 0 )
return 0 ;
V_11 = V_6 ( ( T_2 * ) V_3 , ( T_3 * ) & V_4 ,
NULL , & V_10 , & V_9 ) ;
if ( V_11 != V_12 )
goto V_13;
if ( V_9 == 1 )
return 0 ;
return 1 ;
V_13:
switch ( V_11 ) {
case V_14 :
return 0 ;
case V_15 :
return - V_16 ;
case V_17 :
return - V_18 ;
default:
return - V_19 ;
}
}
T_6 F_2 ( T_1 * V_1 ,
void * V_20 , void * * V_21 )
{
T_7 * V_22 ;
T_8 * V_23 = V_20 ;
T_9 * V_24 ;
T_3 V_25 = V_26 ;
T_6 V_11 ;
void * V_27 = ( void * ) ( unsigned long ) V_23 -> V_28 ;
V_11 = V_1 -> V_29 -> V_30 ( V_27 ,
& V_25 , ( void * * ) & V_22 ) ;
if ( V_11 != V_12 ) {
F_3 ( V_1 , L_1 ) ;
return V_11 ;
}
V_11 = V_22 -> V_31 ( V_22 , & V_24 ) ;
if ( V_11 != V_12 )
F_3 ( V_1 , L_2 ) ;
* V_21 = V_24 ;
return V_11 ;
}
T_6 F_4 ( void * V_27 )
{
T_9 * V_24 = V_27 ;
return V_24 -> V_32 ( V_27 ) ;
}
T_6
F_5 ( void * V_27 , unsigned long * V_10 , void * V_33 )
{
T_9 * V_24 = V_27 ;
return V_24 -> V_34 ( V_27 , V_10 , V_33 ) ;
}
T_6
F_6 ( T_1 * V_1 , void * V_21 ,
T_2 * V_35 , void * * V_27 , T_10 * V_36 )
{
T_9 * V_37 , * V_24 = V_21 ;
T_11 * V_38 ;
T_6 V_11 ;
T_3 V_39 = V_40 ;
unsigned long V_41 ;
V_11 = V_24 -> V_42 ( V_24 , & V_37 , V_35 , V_43 , ( T_10 ) 0 ) ;
if ( V_11 != V_12 ) {
F_3 ( V_1 , L_3 ) ;
F_7 ( V_1 , V_35 ) ;
F_3 ( V_1 , L_4 ) ;
return V_11 ;
}
* V_27 = V_37 ;
V_41 = 0 ;
V_11 = V_37 -> V_44 ( V_37 , & V_39 , & V_41 , NULL ) ;
if ( V_11 != V_45 ) {
F_3 ( V_1 , L_5 ) ;
return V_11 ;
}
V_46:
V_11 = V_1 -> V_29 -> V_47 ( V_48 ,
V_41 , ( void * * ) & V_38 ) ;
if ( V_11 != V_12 ) {
F_3 ( V_1 , L_6 ) ;
return V_11 ;
}
V_11 = V_37 -> V_44 ( V_37 , & V_39 , & V_41 ,
V_38 ) ;
if ( V_11 == V_45 ) {
V_1 -> V_29 -> V_49 ( V_38 ) ;
goto V_46;
}
* V_36 = V_38 -> V_50 ;
V_1 -> V_29 -> V_49 ( V_38 ) ;
if ( V_11 != V_12 )
F_3 ( V_1 , L_7 ) ;
return V_11 ;
}
void F_7 ( T_1 * V_1 ,
T_2 * V_51 )
{
struct V_52 * V_53 ;
V_53 = (struct V_52 * ) V_1 -> V_54 ;
V_53 -> V_55 ( V_53 , V_51 ) ;
}
static struct V_56 * F_8 ( T_1 * V_1 )
{
T_3 V_57 = V_58 ;
T_6 V_11 ;
unsigned long V_10 ;
void * * V_59 = NULL ;
struct V_56 * V_60 = NULL ;
V_10 = 0 ;
V_11 = F_9 ( V_61 , V_62 ,
& V_57 , NULL , & V_10 , V_59 ) ;
if ( V_11 == V_45 ) {
V_60 = F_10 ( V_1 ) ;
if ( ! V_60 )
return NULL ;
F_11 ( V_1 , V_60 , & V_57 , V_10 ) ;
}
return V_60 ;
}
unsigned long F_12 ( void * V_27 , T_1 * V_63 ,
unsigned long * V_64 )
{
T_8 * V_23 ;
T_6 V_11 ;
unsigned long V_65 = 0 ;
unsigned long V_66 ;
unsigned long V_67 ;
T_10 V_68 = 0 ;
unsigned long V_69 = 0 ;
unsigned long V_70 = 0 ;
char * V_71 = NULL ;
int V_72 = 0 ;
unsigned long V_73 ;
T_3 V_74 = V_75 ;
unsigned long V_76 = 0 ;
unsigned long V_77 = 0 ;
int V_78 = 0 ;
struct V_56 * V_60 ;
if ( V_63 -> V_79 . V_80 != V_81 )
goto V_82;
F_13 ( V_63 , L_8 ) ;
V_11 = F_14 ( V_63 ) ;
if ( V_11 != V_12 )
goto V_82;
V_11 = V_63 -> V_29 -> V_30 ( V_27 ,
& V_74 , ( void * ) & V_23 ) ;
if ( V_11 != V_12 ) {
F_15 ( V_63 , L_9 ) ;
goto V_82;
}
V_66 = F_16 ( V_63 ) ;
if ( V_66 == V_83 ) {
F_15 ( V_63 , L_10 ) ;
goto V_82;
}
V_71 = F_17 ( V_63 , V_23 , & V_72 ) ;
if ( ! V_71 ) {
F_15 ( V_63 , L_11 ) ;
goto V_82;
}
if ( F_18 ( V_84 ) ) {
static const T_5 V_85 [] = V_86 ;
const T_5 * V_51 , * V_87 = V_71 ;
if ( F_18 ( V_88 ) )
V_87 = V_85 ;
V_51 = strstr ( V_87 , L_12 ) ;
if ( V_51 == V_87 || ( V_51 > V_87 && * ( V_51 - 1 ) == ' ' ) )
V_89 = true ;
}
V_60 = F_8 ( V_63 ) ;
V_11 = F_19 ( V_63 , V_64 , & V_65 ,
& V_76 ,
& V_77 ,
V_66 , V_23 ) ;
if ( V_11 != V_12 ) {
F_15 ( V_63 , L_13 ) ;
goto V_90;
}
V_11 = F_20 ( V_71 ) ;
if ( V_11 != V_12 )
F_15 ( V_63 , L_14 ) ;
V_78 = F_1 ( V_63 ) ;
if ( V_78 > 0 )
F_13 ( V_63 , L_15 ) ;
if ( V_78 < 0 ) {
F_15 ( V_63 ,
L_16 ) ;
}
if ( V_78 != 0 && strstr ( V_71 , L_17 ) ) {
F_13 ( V_63 , L_18 ) ;
} else {
V_11 = F_21 ( V_63 , V_23 , V_71 ,
L_17 ,
~ 0UL , & V_69 , & V_70 ) ;
if ( V_11 != V_12 ) {
F_15 ( V_63 , L_19 ) ;
goto V_91;
}
}
if ( V_69 ) {
F_13 ( V_63 , L_20 ) ;
} else {
V_69 = ( V_92 ) F_22 ( V_63 , & V_70 ) ;
if ( V_69 )
F_13 ( V_63 , L_21 ) ;
}
if ( ! V_69 )
F_13 ( V_63 , L_22 ) ;
V_11 = F_21 ( V_63 , V_23 , V_71 ,
L_23 , V_66 + V_93 ,
( unsigned long * ) & V_67 ,
( unsigned long * ) & V_68 ) ;
if ( V_11 != V_12 )
F_15 ( V_63 , L_24 ) ;
V_73 = V_69 ;
V_11 = F_23 ( V_63 , V_27 ,
& V_73 , V_66 + V_94 ,
V_67 , V_68 , V_71 ,
V_69 , V_70 ) ;
if ( V_11 == V_12 )
return V_73 ;
F_15 ( V_63 , L_25 ) ;
F_24 ( V_63 , V_68 , V_67 ) ;
F_24 ( V_63 , V_70 , V_69 ) ;
V_91:
F_24 ( V_63 , V_65 , * V_64 ) ;
F_24 ( V_63 , V_77 , V_76 ) ;
V_90:
F_25 ( V_63 , V_60 ) ;
F_24 ( V_63 , V_72 , ( unsigned long ) V_71 ) ;
V_82:
return V_83 ;
}
static int F_26 ( const void * V_95 , const void * V_96 )
{
const T_12 * V_97 = V_95 , * V_98 = V_96 ;
return ( V_97 -> V_99 > V_98 -> V_99 ) ? 1 : - 1 ;
}
static bool F_27 ( T_12 * V_97 ,
T_12 * V_98 )
{
T_10 V_100 ;
if ( V_97 == NULL || V_98 == NULL )
return false ;
V_100 = V_97 -> V_99 + V_97 -> V_101 * V_102 ;
return V_100 == V_98 -> V_99 ;
}
static bool F_28 ( T_12 * V_97 ,
T_12 * V_98 )
{
static const T_10 V_103 = V_104 | V_105 |
V_106 | V_107 |
V_108 ;
return ( ( V_97 -> V_109 ^ V_98 -> V_109 ) & V_103 ) == 0 ;
}
void F_29 ( T_12 * V_110 , unsigned long V_111 ,
unsigned long V_112 , T_12 * V_113 ,
int * V_114 )
{
T_10 V_115 = V_116 ;
T_12 * V_117 , * V_118 = NULL , * V_53 = V_113 ;
int V_95 ;
F_30 ( V_110 , V_111 / V_112 , V_112 , F_26 , NULL ) ;
for ( V_95 = 0 ; V_95 < V_111 ; V_95 += V_112 , V_118 = V_117 ) {
T_10 V_119 , V_10 ;
V_117 = ( void * ) V_110 + V_95 ;
if ( ! ( V_117 -> V_109 & V_108 ) )
continue;
V_119 = V_117 -> V_99 ;
V_10 = V_117 -> V_101 * V_102 ;
if ( ! F_27 ( V_118 , V_117 ) ||
! F_28 ( V_118 , V_117 ) ) {
V_119 = F_31 ( V_117 -> V_99 , V_120 ) ;
V_10 += V_117 -> V_99 - V_119 ;
if ( F_32 ( V_117 -> V_99 , V_121 ) && V_10 >= V_121 )
V_115 = F_33 ( V_115 , V_121 ) ;
else
V_115 = F_33 ( V_115 , V_120 ) ;
}
V_117 -> V_122 = V_115 + V_117 -> V_99 - V_119 ;
V_115 += V_10 ;
memcpy ( V_53 , V_117 , V_112 ) ;
V_53 = ( void * ) V_53 + V_112 ;
++ * V_114 ;
}
}
