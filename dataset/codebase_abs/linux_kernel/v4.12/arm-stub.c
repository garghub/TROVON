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
V_46 = F_17 ( V_30 ) ;
if ( V_46 != V_56 &&
strstr ( V_38 , L_8 ) ) {
F_15 ( V_30 , L_9 ) ;
} else {
V_9 = F_18 ( V_30 , V_5 , V_38 ,
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
V_36 = ( V_58 ) F_19 ( V_30 , & V_37 ) ;
if ( V_36 )
F_15 ( V_30 , L_12 ) ;
}
if ( ! V_36 )
F_15 ( V_30 , L_13 ) ;
V_9 = F_18 ( V_30 , V_5 , V_38 , L_14 ,
F_20 ( V_33 ,
* V_31 ) ,
( unsigned long * ) & V_34 ,
( unsigned long * ) & V_35 ) ;
if ( V_9 != V_14 )
F_10 ( V_30 , L_15 ) ;
F_21 ( V_30 ) ;
if ( ! F_22 () ) {
static const T_8 V_59 = V_60 -
V_61 -
V_62 ;
T_9 V_63 ;
V_9 = F_23 ( V_30 , sizeof( V_63 ) ,
( V_64 * ) & V_63 ) ;
if ( V_9 == V_14 ) {
V_65 = V_61 +
( ( ( V_59 >> 21 ) * V_63 ) >> ( 32 - 21 ) ) ;
}
}
V_40 = V_36 ;
V_9 = F_24 ( V_30 , V_10 ,
& V_40 , F_25 ( V_33 ) ,
V_34 , V_35 , V_38 ,
V_36 , V_37 ) ;
if ( V_9 == V_14 )
return V_40 ;
F_10 ( V_30 , L_16 ) ;
F_26 ( V_30 , V_35 , V_34 ) ;
F_26 ( V_30 , V_37 , V_36 ) ;
V_57:
F_26 ( V_30 , V_32 , * V_31 ) ;
F_26 ( V_30 , V_44 , V_43 ) ;
V_55:
F_27 ( V_30 , V_26 ) ;
F_26 ( V_30 , V_39 , ( unsigned long ) V_38 ) ;
V_50:
return V_51 ;
}
static int F_28 ( const void * V_66 , const void * V_67 )
{
const T_10 * V_68 = V_66 , * V_69 = V_67 ;
return ( V_68 -> V_70 > V_69 -> V_70 ) ? 1 : - 1 ;
}
static bool F_29 ( T_10 * V_68 ,
T_10 * V_69 )
{
T_8 V_71 ;
if ( V_68 == NULL || V_69 == NULL )
return false ;
V_71 = V_68 -> V_70 + V_68 -> V_72 * V_73 ;
return V_71 == V_69 -> V_70 ;
}
static bool F_30 ( T_10 * V_68 ,
T_10 * V_69 )
{
static const T_8 V_74 = V_75 | V_76 |
V_77 | V_78 |
V_79 ;
return ( ( V_68 -> V_80 ^ V_69 -> V_80 ) & V_74 ) == 0 ;
}
void F_31 ( T_10 * V_81 , unsigned long V_82 ,
unsigned long V_83 , T_10 * V_84 ,
int * V_85 )
{
T_8 V_86 = V_65 ;
T_10 * V_87 , * V_88 = NULL , * V_18 = V_84 ;
int V_66 ;
F_32 ( V_81 , V_82 / V_83 , V_83 , F_28 , NULL ) ;
for ( V_66 = 0 ; V_66 < V_82 ; V_66 += V_83 , V_88 = V_87 ) {
T_8 V_89 , V_24 ;
V_87 = ( void * ) V_81 + V_66 ;
if ( ! ( V_87 -> V_80 & V_79 ) )
continue;
V_89 = V_87 -> V_70 ;
V_24 = V_87 -> V_72 * V_73 ;
if ( ! F_29 ( V_88 , V_87 ) ||
! F_30 ( V_88 , V_87 ) ) {
V_89 = F_33 ( V_87 -> V_70 , V_90 ) ;
V_24 += V_87 -> V_70 - V_89 ;
if ( F_34 ( V_87 -> V_70 , V_91 ) && V_24 >= V_91 )
V_86 = F_35 ( V_86 , V_91 ) ;
else
V_86 = F_35 ( V_86 , V_90 ) ;
}
V_87 -> V_92 = V_86 + V_87 -> V_70 - V_89 ;
V_86 += V_24 ;
memcpy ( V_18 , V_87 , V_83 ) ;
V_18 = ( void * ) V_18 + V_83 ;
++ * V_85 ;
}
}
