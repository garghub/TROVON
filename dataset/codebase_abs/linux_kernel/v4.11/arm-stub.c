T_1 F_1 ( T_2 * V_1 ,
void * V_2 , void * * V_3 )
{
T_3 * V_4 ;
T_4 * V_5 = V_2 ;
T_5 * V_6 ;
T_6 V_7 = V_8 ;
T_1 V_9 ;
void * V_10 = ( void * ) ( unsigned long ) V_5 -> V_11 ;
V_9 = V_1 -> V_12 -> V_13 ( V_10 ,
& V_7 , ( void * * ) & V_4 ) ;
if ( V_9 != V_14 ) {
F_2 ( V_1 , L_1 ) ;
return V_9 ;
}
V_9 = V_4 -> V_15 ( V_4 , & V_6 ) ;
if ( V_9 != V_14 )
F_2 ( V_1 , L_2 ) ;
* V_3 = V_6 ;
return V_9 ;
}
void F_3 ( T_2 * V_1 ,
T_7 * V_16 )
{
struct V_17 * V_18 ;
V_18 = (struct V_17 * ) V_1 -> V_19 ;
V_18 -> V_20 ( V_18 , V_16 ) ;
}
static struct V_21 * F_4 ( T_2 * V_1 )
{
T_6 V_22 = V_23 ;
T_1 V_9 ;
unsigned long V_24 ;
void * * V_25 = NULL ;
struct V_21 * V_26 = NULL ;
V_24 = 0 ;
V_9 = F_5 ( V_27 , V_28 ,
& V_22 , NULL , & V_24 , V_25 ) ;
if ( V_9 == V_29 ) {
V_26 = F_6 ( V_1 ) ;
if ( ! V_26 )
return NULL ;
F_7 ( V_1 , V_26 , & V_22 , V_24 ) ;
}
return V_26 ;
}
unsigned long F_8 ( void * V_10 , T_2 * V_30 ,
unsigned long * V_31 )
{
T_4 * V_5 ;
T_1 V_9 ;
unsigned long V_32 = 0 ;
unsigned long V_33 ;
unsigned long V_34 ;
T_8 V_35 = 0 ;
unsigned long V_36 = 0 ;
unsigned long V_37 = 0 ;
char * V_38 = NULL ;
int V_39 = 0 ;
unsigned long V_40 ;
T_6 V_41 = V_42 ;
unsigned long V_43 = 0 ;
unsigned long V_44 = 0 ;
enum V_45 V_46 ;
struct V_21 * V_26 ;
if ( V_30 -> V_47 . V_48 != V_49 )
goto V_50;
F_9 ( V_30 , L_3 ) ;
V_9 = F_10 ( V_30 ) ;
if ( V_9 != V_14 )
goto V_50;
V_9 = V_30 -> V_12 -> V_13 ( V_10 ,
& V_41 , ( void * ) & V_5 ) ;
if ( V_9 != V_14 ) {
F_11 ( V_30 , L_4 ) ;
goto V_50;
}
V_33 = F_12 ( V_30 ) ;
if ( V_33 == V_51 ) {
F_11 ( V_30 , L_5 ) ;
goto V_50;
}
V_38 = F_13 ( V_30 , V_5 , & V_39 ) ;
if ( ! V_38 ) {
F_11 ( V_30 , L_6 ) ;
goto V_50;
}
if ( F_14 ( V_52 ) ) {
static const T_9 V_53 [] = V_54 ;
const T_9 * V_16 , * V_55 = V_38 ;
if ( F_14 ( V_56 ) )
V_55 = V_53 ;
V_16 = strstr ( V_55 , L_7 ) ;
if ( V_16 == V_55 || ( V_16 > V_55 && * ( V_16 - 1 ) == ' ' ) )
V_57 = true ;
}
V_26 = F_4 ( V_30 ) ;
V_9 = F_15 ( V_30 , V_31 , & V_32 ,
& V_43 ,
& V_44 ,
V_33 , V_5 ) ;
if ( V_9 != V_14 ) {
F_11 ( V_30 , L_8 ) ;
goto V_58;
}
V_9 = F_16 ( V_38 ) ;
if ( V_9 != V_14 )
F_11 ( V_30 , L_9 ) ;
V_46 = F_17 ( V_30 ) ;
if ( V_46 != V_59 &&
strstr ( V_38 , L_10 ) ) {
F_9 ( V_30 , L_11 ) ;
} else {
V_9 = F_18 ( V_30 , V_5 , V_38 ,
L_10 ,
~ 0UL , & V_36 , & V_37 ) ;
if ( V_9 != V_14 ) {
F_11 ( V_30 , L_12 ) ;
goto V_60;
}
}
if ( V_36 ) {
F_9 ( V_30 , L_13 ) ;
} else {
V_36 = ( V_61 ) F_19 ( V_30 , & V_37 ) ;
if ( V_36 )
F_9 ( V_30 , L_14 ) ;
}
if ( ! V_36 )
F_9 ( V_30 , L_15 ) ;
V_9 = F_18 ( V_30 , V_5 , V_38 ,
L_16 , V_33 + V_62 ,
( unsigned long * ) & V_34 ,
( unsigned long * ) & V_35 ) ;
if ( V_9 != V_14 )
F_11 ( V_30 , L_17 ) ;
F_20 ( V_30 ) ;
V_40 = V_36 ;
V_9 = F_21 ( V_30 , V_10 ,
& V_40 , V_33 + V_63 ,
V_34 , V_35 , V_38 ,
V_36 , V_37 ) ;
if ( V_9 == V_14 )
return V_40 ;
F_11 ( V_30 , L_18 ) ;
F_22 ( V_30 , V_35 , V_34 ) ;
F_22 ( V_30 , V_37 , V_36 ) ;
V_60:
F_22 ( V_30 , V_32 , * V_31 ) ;
F_22 ( V_30 , V_44 , V_43 ) ;
V_58:
F_23 ( V_30 , V_26 ) ;
F_22 ( V_30 , V_39 , ( unsigned long ) V_38 ) ;
V_50:
return V_51 ;
}
static int F_24 ( const void * V_64 , const void * V_65 )
{
const T_10 * V_66 = V_64 , * V_67 = V_65 ;
return ( V_66 -> V_68 > V_67 -> V_68 ) ? 1 : - 1 ;
}
static bool F_25 ( T_10 * V_66 ,
T_10 * V_67 )
{
T_8 V_69 ;
if ( V_66 == NULL || V_67 == NULL )
return false ;
V_69 = V_66 -> V_68 + V_66 -> V_70 * V_71 ;
return V_69 == V_67 -> V_68 ;
}
static bool F_26 ( T_10 * V_66 ,
T_10 * V_67 )
{
static const T_8 V_72 = V_73 | V_74 |
V_75 | V_76 |
V_77 ;
return ( ( V_66 -> V_78 ^ V_67 -> V_78 ) & V_72 ) == 0 ;
}
void F_27 ( T_10 * V_79 , unsigned long V_80 ,
unsigned long V_81 , T_10 * V_82 ,
int * V_83 )
{
T_8 V_84 = V_85 ;
T_10 * V_86 , * V_87 = NULL , * V_18 = V_82 ;
int V_64 ;
F_28 ( V_79 , V_80 / V_81 , V_81 , F_24 , NULL ) ;
for ( V_64 = 0 ; V_64 < V_80 ; V_64 += V_81 , V_87 = V_86 ) {
T_8 V_88 , V_24 ;
V_86 = ( void * ) V_79 + V_64 ;
if ( ! ( V_86 -> V_78 & V_77 ) )
continue;
V_88 = V_86 -> V_68 ;
V_24 = V_86 -> V_70 * V_71 ;
if ( ! F_25 ( V_87 , V_86 ) ||
! F_26 ( V_87 , V_86 ) ) {
V_88 = F_29 ( V_86 -> V_68 , V_89 ) ;
V_24 += V_86 -> V_68 - V_88 ;
if ( F_30 ( V_86 -> V_68 , V_90 ) && V_24 >= V_90 )
V_84 = F_31 ( V_84 , V_90 ) ;
else
V_84 = F_31 ( V_84 , V_89 ) ;
}
V_86 -> V_91 = V_84 + V_86 -> V_68 - V_88 ;
V_84 += V_24 ;
memcpy ( V_18 , V_86 , V_81 ) ;
V_18 = ( void * ) V_18 + V_81 ;
++ * V_83 ;
}
}
