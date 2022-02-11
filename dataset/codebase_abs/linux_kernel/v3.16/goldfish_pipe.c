static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
struct V_6 * V_7 = V_2 -> V_7 ;
F_2 ( & V_7 -> V_8 , V_4 ) ;
F_3 ( ( V_9 ) ( unsigned long ) V_2 , V_7 -> V_10 + V_11 ,
V_7 -> V_10 + V_12 ) ;
F_4 ( V_3 , V_7 -> V_10 + V_13 ) ;
V_5 = F_5 ( V_7 -> V_10 + V_14 ) ;
F_6 ( & V_7 -> V_8 , V_4 ) ;
return V_5 ;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
struct V_6 * V_7 = V_2 -> V_7 ;
F_2 ( & V_7 -> V_8 , V_4 ) ;
F_3 ( ( V_9 ) ( unsigned long ) V_2 , V_7 -> V_10 + V_11 ,
V_7 -> V_10 + V_12 ) ;
F_4 ( V_3 , V_7 -> V_10 + V_13 ) ;
F_6 ( & V_7 -> V_8 , V_4 ) ;
}
static int F_8 ( int V_5 )
{
switch ( V_5 ) {
case V_15 :
return - V_16 ;
case V_17 :
return - V_18 ;
case V_19 :
return - V_20 ;
default:
return - V_21 ;
}
}
static int F_9 ( struct V_6 * V_7 ,
struct V_22 * V_23 )
{
T_1 V_24 , V_25 ;
V_9 V_26 ;
V_24 = F_5 ( V_7 -> V_10 + V_27 ) ;
V_25 = F_5 ( V_7 -> V_10 + V_28 ) ;
V_26 = ( ( V_9 ) V_24 << 32 ) | V_25 ;
if ( V_26 != ( F_10 ( V_23 ) ) )
return 0 ;
return 1 ;
}
static int F_11 ( struct V_29 * V_30 ,
struct V_6 * V_7 )
{
V_9 V_26 ;
struct V_22 * V_23 ;
V_23 = F_12 ( & V_30 -> V_7 , sizeof( struct V_22 ) , V_31 ) ;
if ( ! V_23 )
return - 1 ;
V_26 = F_10 ( V_23 ) ;
F_4 ( ( T_1 ) ( V_26 >> 32 ) , V_7 -> V_10 + V_27 ) ;
F_4 ( ( T_1 ) V_26 , V_7 -> V_10 + V_28 ) ;
if ( F_9 ( V_7 , V_23 ) ) {
V_7 -> V_23 = V_23 ;
return 0 ;
} else
return - 1 ;
}
static int F_13 ( struct V_6 * V_7 , const int V_3 ,
unsigned long V_32 , unsigned long V_33 ,
struct V_1 * V_2 , int * V_5 )
{
struct V_22 * V_23 = V_7 -> V_23 ;
if ( V_23 == NULL )
return - 1 ;
V_23 -> V_34 = V_35 ;
V_23 -> V_36 = ( unsigned long ) V_2 ;
V_23 -> V_37 = V_33 ;
V_23 -> V_32 = V_32 ;
V_23 -> V_3 = V_3 ;
F_4 ( V_3 , V_7 -> V_10 + V_38 ) ;
if ( V_23 -> V_34 == V_35 )
return - 1 ;
* V_5 = V_23 -> V_34 ;
return 0 ;
}
static T_2 F_14 ( struct V_39 * V_40 , char T_3 * V_41 ,
T_4 V_42 , int V_43 )
{
unsigned long V_44 ;
struct V_1 * V_2 = V_40 -> V_45 ;
struct V_6 * V_7 = V_2 -> V_7 ;
const int V_46 = V_43 ? 0
: ( V_47 - V_48 ) ;
unsigned long V_32 , V_49 ;
int V_50 = 0 ;
if ( F_15 ( V_51 , & V_2 -> V_4 ) )
return - V_20 ;
if ( F_16 ( V_42 ) == 0 )
return 0 ;
if ( ! F_17 ( V_43 ? V_52 : V_53 ,
V_41 , V_42 ) )
return - V_54 ;
if ( F_18 ( & V_2 -> V_8 ) )
return - V_55 ;
V_32 = ( unsigned long ) ( void * ) V_41 ;
V_49 = V_32 + V_42 ;
while ( V_32 < V_49 ) {
unsigned long V_56 = ( V_32 & V_57 ) + V_58 ;
unsigned long V_59 = V_56 < V_49 ? V_56
: V_49 ;
unsigned long V_33 = V_59 - V_32 ;
int V_5 , V_60 ;
if ( V_43 ) {
char V_61 ;
if ( F_19 ( V_61 , ( char T_3 * ) V_32 ) ) {
if ( ! V_50 )
V_50 = - V_54 ;
break;
}
} else {
if ( F_20 ( 0 , ( char T_3 * ) V_32 ) ) {
if ( ! V_50 )
V_50 = - V_54 ;
break;
}
}
F_2 ( & V_7 -> V_8 , V_44 ) ;
if ( F_13 ( V_7 , V_48 + V_46 ,
V_32 , V_33 , V_2 , & V_5 ) ) {
F_3 ( ( V_9 ) ( unsigned long ) V_2 ,
V_7 -> V_10 + V_11 ,
V_7 -> V_10 + V_12 ) ;
F_4 ( V_33 , V_7 -> V_10 + V_62 ) ;
F_3 ( V_32 , V_7 -> V_10 + V_63 ,
V_7 -> V_10 + V_64 ) ;
F_4 ( V_48 + V_46 ,
V_7 -> V_10 + V_13 ) ;
V_5 = F_5 ( V_7 -> V_10 + V_14 ) ;
}
F_6 ( & V_7 -> V_8 , V_44 ) ;
if ( V_5 > 0 ) {
V_50 += V_5 ;
V_32 += V_5 ;
continue;
}
if ( V_5 == 0 )
break;
if ( V_50 > 0 )
break;
if ( V_5 != V_15 ||
( V_40 -> V_65 & V_66 ) != 0 ) {
V_50 = F_8 ( V_5 ) ;
break;
}
V_60 = V_43 ? V_67 : V_68 ;
F_21 ( V_60 , & V_2 -> V_4 ) ;
F_7 ( V_2 , V_69 + V_46 ) ;
F_22 ( & V_2 -> V_8 ) ;
while ( F_15 ( V_60 , & V_2 -> V_4 ) ) {
if ( F_23 (
V_2 -> V_70 ,
! F_15 ( V_60 , & V_2 -> V_4 ) ) )
return - V_55 ;
if ( F_15 ( V_51 , & V_2 -> V_4 ) )
return - V_20 ;
}
if ( F_18 ( & V_2 -> V_8 ) )
return - V_55 ;
continue;
}
F_22 ( & V_2 -> V_8 ) ;
return V_50 ;
}
static T_2 F_24 ( struct V_39 * V_40 , char T_3 * V_41 ,
T_4 V_42 , T_5 * V_71 )
{
return F_14 ( V_40 , V_41 , V_42 , 0 ) ;
}
static T_2 F_25 ( struct V_39 * V_40 ,
const char T_3 * V_41 , T_4 V_42 ,
T_5 * V_71 )
{
return F_14 ( V_40 , ( char T_3 * ) V_41 ,
V_42 , 1 ) ;
}
static unsigned int F_26 ( struct V_39 * V_40 , T_6 * V_72 )
{
struct V_1 * V_2 = V_40 -> V_45 ;
unsigned int V_73 = 0 ;
int V_5 ;
F_27 ( & V_2 -> V_8 ) ;
F_28 ( V_40 , & V_2 -> V_70 , V_72 ) ;
V_5 = F_1 ( V_2 , V_74 ) ;
F_22 ( & V_2 -> V_8 ) ;
if ( V_5 & V_75 )
V_73 |= V_76 | V_77 ;
if ( V_5 & V_78 )
V_73 |= V_79 | V_80 ;
if ( V_5 & V_81 )
V_73 |= V_82 ;
if ( F_15 ( V_51 , & V_2 -> V_4 ) )
V_73 |= V_83 ;
return V_73 ;
}
static T_7 F_29 ( int V_84 , void * V_85 )
{
struct V_6 * V_7 = V_85 ;
unsigned long V_44 ;
int V_86 = 0 ;
F_2 ( & V_7 -> V_8 , V_44 ) ;
for (; ; ) {
struct V_1 * V_2 ;
unsigned long V_87 ;
unsigned long V_36 = 0 ;
#ifdef F_30
V_36 = ( V_9 ) F_5 ( V_7 -> V_10 + V_12 ) << 32 ;
if ( V_36 == 0 )
break;
#endif
V_36 |= F_5 ( V_7 -> V_10 + V_11 ) ;
if ( V_36 == 0 )
break;
V_87 = F_5 ( V_7 -> V_10 + V_88 ) ;
V_2 = (struct V_1 * ) ( V_89 ) V_36 ;
if ( V_87 & V_90 ) {
F_21 ( V_51 , & V_2 -> V_4 ) ;
V_87 |= V_91 | V_92 ;
}
if ( V_87 & V_91 )
F_31 ( V_68 , & V_2 -> V_4 ) ;
if ( V_87 & V_92 )
F_31 ( V_67 , & V_2 -> V_4 ) ;
F_32 ( & V_2 -> V_70 ) ;
V_86 ++ ;
}
F_6 ( & V_7 -> V_8 , V_44 ) ;
return ( V_86 == 0 ) ? V_93 : V_94 ;
}
static int F_33 ( struct V_95 * V_95 , struct V_39 * V_39 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 = V_96 ;
T_8 V_5 ;
V_2 = F_34 ( sizeof( * V_2 ) , V_31 ) ;
if ( V_2 == NULL )
return - V_18 ;
V_2 -> V_7 = V_7 ;
F_35 ( & V_2 -> V_8 ) ;
F_36 ( & V_2 -> V_70 ) ;
V_5 = F_1 ( V_2 , V_97 ) ;
if ( V_5 < 0 ) {
F_37 ( V_2 ) ;
return V_5 ;
}
V_39 -> V_45 = V_2 ;
return 0 ;
}
static int F_38 ( struct V_95 * V_95 , struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_45 ;
F_7 ( V_2 , V_98 ) ;
F_37 ( V_2 ) ;
V_40 -> V_45 = NULL ;
return 0 ;
}
static int F_39 ( struct V_29 * V_30 )
{
int V_99 ;
struct V_100 * V_101 ;
struct V_6 * V_7 = V_96 ;
F_40 ( V_7 -> V_10 != NULL ) ;
F_41 ( & V_7 -> V_8 ) ;
V_101 = F_42 ( V_30 , V_102 , 0 ) ;
if ( V_101 == NULL || F_43 ( V_101 ) < V_58 ) {
F_44 ( & V_30 -> V_7 , L_1 ) ;
return - V_21 ;
}
V_7 -> V_10 = F_45 ( & V_30 -> V_7 , V_101 -> V_103 , V_58 ) ;
if ( V_7 -> V_10 == NULL ) {
F_44 ( & V_30 -> V_7 , L_2 ) ;
return - V_21 ;
}
V_101 = F_42 ( V_30 , V_104 , 0 ) ;
if ( V_101 == NULL ) {
V_99 = - V_21 ;
goto error;
}
V_7 -> V_84 = V_101 -> V_103 ;
V_99 = F_46 ( & V_30 -> V_7 , V_7 -> V_84 , F_29 ,
V_105 , L_3 , V_7 ) ;
if ( V_99 ) {
F_44 ( & V_30 -> V_7 , L_4 ) ;
goto error;
}
V_99 = F_47 ( & V_106 ) ;
if ( V_99 ) {
F_44 ( & V_30 -> V_7 , L_5 ) ;
goto error;
}
F_11 ( V_30 , V_7 ) ;
return 0 ;
error:
V_7 -> V_10 = NULL ;
return V_99 ;
}
static int F_48 ( struct V_29 * V_30 )
{
struct V_6 * V_7 = V_96 ;
F_49 ( & V_106 ) ;
V_7 -> V_10 = NULL ;
return 0 ;
}
