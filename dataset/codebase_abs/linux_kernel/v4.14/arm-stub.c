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
V_9 = F_9 ( V_30 ) ;
if ( V_9 != V_14 )
goto V_50;
V_9 = V_30 -> V_12 -> V_13 ( V_10 ,
& V_41 , ( void * ) & V_5 ) ;
if ( V_9 != V_14 ) {
F_10 ( V_30 , L_3 ) ;
goto V_50;
}
V_33 = F_11 ( V_30 ) ;
if ( V_33 == V_51 ) {
F_10 ( V_30 , L_4 ) ;
goto V_50;
}
V_38 = F_12 ( V_30 , V_5 , & V_39 ) ;
if ( ! V_38 ) {
F_10 ( V_30 , L_5 ) ;
goto V_50;
}
if ( F_13 ( V_52 ) ||
F_13 ( V_53 ) ||
V_39 == 0 )
F_14 ( V_54 ) ;
if ( ! F_13 ( V_53 ) && V_39 > 0 )
F_14 ( V_38 ) ;
F_15 ( V_30 , L_6 ) ;
V_26 = F_4 ( V_30 ) ;
V_9 = F_16 ( V_30 , V_31 , & V_32 ,
& V_43 ,
& V_44 ,
V_33 , V_5 ) ;
if ( V_9 != V_14 ) {
F_10 ( V_30 , L_7 ) ;
goto V_55;
}
F_17 ( V_30 ) ;
V_46 = F_18 ( V_30 ) ;
if ( V_46 != V_56 &&
strstr ( V_38 , L_8 ) ) {
F_15 ( V_30 , L_9 ) ;
} else {
V_9 = F_19 ( V_30 , V_5 , V_38 ,
L_8 ,
~ 0UL , & V_36 , & V_37 ) ;
if ( V_9 != V_14 ) {
F_10 ( V_30 , L_10 ) ;
goto V_57;
}
}
if ( V_36 ) {
F_15 ( V_30 , L_11 ) ;
} else {
V_36 = ( V_58 ) F_20 ( V_30 , & V_37 ) ;
if ( V_36 )
F_15 ( V_30 , L_12 ) ;
}
if ( ! V_36 )
F_15 ( V_30 , L_13 ) ;
V_9 = F_19 ( V_30 , V_5 , V_38 , L_14 ,
F_21 ( V_33 ,
* V_31 ) ,
( unsigned long * ) & V_34 ,
( unsigned long * ) & V_35 ) ;
if ( V_9 != V_14 )
F_10 ( V_30 , L_15 ) ;
F_22 ( V_30 ) ;
if ( ! F_13 ( V_59 ) && ! F_23 () ) {
static const T_8 V_60 = V_61 -
V_62 -
V_63 ;
T_9 V_64 ;
V_9 = F_24 ( V_30 , sizeof( V_64 ) ,
( V_65 * ) & V_64 ) ;
if ( V_9 == V_14 ) {
V_66 = V_62 +
( ( ( V_60 >> 21 ) * V_64 ) >> ( 32 - 21 ) ) ;
}
}
V_40 = V_36 ;
V_9 = F_25 ( V_30 , V_10 ,
& V_40 , F_26 ( V_33 ) ,
V_34 , V_35 , V_38 ,
V_36 , V_37 ) ;
if ( V_9 == V_14 )
return V_40 ;
F_10 ( V_30 , L_16 ) ;
F_27 ( V_30 , V_35 , V_34 ) ;
F_27 ( V_30 , V_37 , V_36 ) ;
V_57:
F_27 ( V_30 , V_32 , * V_31 ) ;
F_27 ( V_30 , V_44 , V_43 ) ;
V_55:
F_28 ( V_30 , V_26 ) ;
F_27 ( V_30 , V_39 , ( unsigned long ) V_38 ) ;
V_50:
return V_51 ;
}
static int F_29 ( const void * V_67 , const void * V_68 )
{
const T_10 * V_69 = V_67 , * V_70 = V_68 ;
return ( V_69 -> V_71 > V_70 -> V_71 ) ? 1 : - 1 ;
}
static bool F_30 ( T_10 * V_69 ,
T_10 * V_70 )
{
T_8 V_72 ;
if ( V_69 == NULL || V_70 == NULL )
return false ;
V_72 = V_69 -> V_71 + V_69 -> V_73 * V_74 ;
return V_72 == V_70 -> V_71 ;
}
static bool F_31 ( T_10 * V_69 ,
T_10 * V_70 )
{
static const T_8 V_75 = V_76 | V_77 |
V_78 | V_79 |
V_80 ;
return ( ( V_69 -> V_81 ^ V_70 -> V_81 ) & V_75 ) == 0 ;
}
void F_32 ( T_10 * V_82 , unsigned long V_83 ,
unsigned long V_84 , T_10 * V_85 ,
int * V_86 )
{
T_8 V_87 = V_66 ;
T_10 * V_88 , * V_89 = NULL , * V_18 = V_85 ;
int V_67 ;
if ( F_13 ( V_90 ) )
F_33 ( V_82 , V_83 / V_84 , V_84 , F_29 ,
NULL ) ;
for ( V_67 = 0 ; V_67 < V_83 ; V_67 += V_84 , V_89 = V_88 ) {
T_8 V_91 , V_24 ;
V_88 = ( void * ) V_82 + V_67 ;
if ( ! ( V_88 -> V_81 & V_80 ) )
continue;
V_91 = V_88 -> V_71 ;
V_24 = V_88 -> V_73 * V_74 ;
if ( ( F_13 ( V_90 ) &&
! F_30 ( V_89 , V_88 ) ) ||
! F_31 ( V_89 , V_88 ) ) {
V_91 = F_34 ( V_88 -> V_71 , V_92 ) ;
V_24 += V_88 -> V_71 - V_91 ;
if ( F_35 ( V_88 -> V_71 , V_93 ) && V_24 >= V_93 )
V_87 = F_36 ( V_87 , V_93 ) ;
else
V_87 = F_36 ( V_87 , V_92 ) ;
}
V_88 -> V_94 = V_87 + V_88 -> V_71 - V_91 ;
V_87 += V_24 ;
memcpy ( V_18 , V_88 , V_84 ) ;
V_18 = ( void * ) V_18 + V_84 ;
++ * V_86 ;
}
}
