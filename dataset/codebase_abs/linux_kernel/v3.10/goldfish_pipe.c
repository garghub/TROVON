static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
struct V_6 * V_7 = V_2 -> V_7 ;
F_2 ( & V_7 -> V_8 , V_4 ) ;
F_3 ( ( T_1 ) V_2 , V_7 -> V_9 + V_10 ) ;
F_3 ( V_3 , V_7 -> V_9 + V_11 ) ;
V_5 = F_4 ( V_7 -> V_9 + V_12 ) ;
F_5 ( & V_7 -> V_8 , V_4 ) ;
return V_5 ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
struct V_6 * V_7 = V_2 -> V_7 ;
F_2 ( & V_7 -> V_8 , V_4 ) ;
F_3 ( ( T_1 ) V_2 , V_7 -> V_9 + V_10 ) ;
F_3 ( V_3 , V_7 -> V_9 + V_11 ) ;
F_5 ( & V_7 -> V_8 , V_4 ) ;
}
static int F_7 ( int V_5 )
{
switch ( V_5 ) {
case V_13 :
return - V_14 ;
case V_15 :
return - V_16 ;
case V_17 :
return - V_18 ;
default:
return - V_19 ;
}
}
static int F_8 ( struct V_6 * V_7 ,
struct V_20 * V_21 )
{
T_1 V_22 , V_23 ;
T_2 V_24 ;
V_22 = F_4 ( V_7 -> V_9 + V_25 ) ;
V_23 = F_4 ( V_7 -> V_9 + V_26 ) ;
V_24 = ( ( T_2 ) V_22 << 32 ) | V_23 ;
if ( V_24 != ( F_9 ( V_21 ) ) )
return 0 ;
return 1 ;
}
static int F_10 ( struct V_27 * V_28 ,
struct V_6 * V_7 )
{
T_2 V_24 ;
struct V_20 * V_21 ;
V_21 = F_11 ( & V_28 -> V_7 , sizeof( struct V_20 ) , V_29 ) ;
if ( ! V_21 )
return - 1 ;
V_24 = F_9 ( V_21 ) ;
F_3 ( ( T_1 ) ( V_24 >> 32 ) , V_7 -> V_9 + V_25 ) ;
F_3 ( ( T_1 ) V_24 , V_7 -> V_9 + V_26 ) ;
if ( F_8 ( V_7 , V_21 ) ) {
V_7 -> V_21 = V_21 ;
return 0 ;
} else
return - 1 ;
}
static int F_12 ( struct V_6 * V_7 , const int V_3 ,
unsigned long V_30 , unsigned long V_31 ,
struct V_1 * V_2 , int * V_5 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
if ( V_21 == NULL )
return - 1 ;
V_21 -> V_32 = V_33 ;
V_21 -> V_34 = ( unsigned long ) V_2 ;
V_21 -> V_35 = V_31 ;
V_21 -> V_30 = V_30 ;
V_21 -> V_3 = V_3 ;
F_3 ( V_3 , V_7 -> V_9 + V_36 ) ;
if ( V_21 -> V_32 == V_33 )
return - 1 ;
* V_5 = V_21 -> V_32 ;
return 0 ;
}
static T_3 F_13 ( struct V_37 * V_38 , char T_4 * V_39 ,
T_5 V_40 , int V_41 )
{
unsigned long V_42 ;
struct V_1 * V_2 = V_38 -> V_43 ;
struct V_6 * V_7 = V_2 -> V_7 ;
const int V_44 = V_41 ? 0
: ( V_45 - V_46 ) ;
unsigned long V_30 , V_47 ;
int V_48 = 0 ;
if ( F_14 ( V_49 , & V_2 -> V_4 ) )
return - V_18 ;
if ( F_15 ( V_40 ) == 0 )
return 0 ;
if ( ! F_16 ( V_41 ? V_50 : V_51 ,
V_39 , V_40 ) )
return - V_52 ;
if ( F_17 ( & V_2 -> V_8 ) )
return - V_53 ;
V_30 = ( unsigned long ) ( void * ) V_39 ;
V_47 = V_30 + V_40 ;
while ( V_30 < V_47 ) {
unsigned long V_54 = ( V_30 & V_55 ) + V_56 ;
unsigned long V_57 = V_54 < V_47 ? V_54
: V_47 ;
unsigned long V_31 = V_57 - V_30 ;
int V_5 , V_58 ;
if ( V_41 ) {
char V_59 ;
if ( F_18 ( V_59 , ( char T_4 * ) V_30 ) ) {
if ( ! V_48 )
V_48 = - V_52 ;
break;
}
} else {
if ( F_19 ( 0 , ( char T_4 * ) V_30 ) ) {
if ( ! V_48 )
V_48 = - V_52 ;
break;
}
}
F_2 ( & V_7 -> V_8 , V_42 ) ;
if ( F_12 ( V_7 , V_46 + V_44 ,
V_30 , V_31 , V_2 , & V_5 ) ) {
F_3 ( ( T_1 ) V_2 , V_7 -> V_9 + V_10 ) ;
F_3 ( V_31 , V_7 -> V_9 + V_60 ) ;
F_3 ( V_30 , V_7 -> V_9 + V_61 ) ;
F_3 ( V_46 + V_44 ,
V_7 -> V_9 + V_11 ) ;
V_5 = F_4 ( V_7 -> V_9 + V_12 ) ;
}
F_5 ( & V_7 -> V_8 , V_42 ) ;
if ( V_5 > 0 ) {
V_48 += V_5 ;
V_30 += V_5 ;
continue;
}
if ( V_5 == 0 )
break;
if ( V_48 > 0 )
break;
if ( V_5 != V_13 ||
( V_38 -> V_62 & V_63 ) != 0 ) {
V_48 = F_7 ( V_5 ) ;
break;
}
V_58 = V_41 ? V_64 : V_65 ;
F_20 ( V_58 , & V_2 -> V_4 ) ;
F_6 ( V_2 , V_66 + V_44 ) ;
F_21 ( & V_2 -> V_8 ) ;
while ( F_14 ( V_58 , & V_2 -> V_4 ) ) {
if ( F_22 (
V_2 -> V_67 ,
! F_14 ( V_58 , & V_2 -> V_4 ) ) )
return - V_53 ;
if ( F_14 ( V_49 , & V_2 -> V_4 ) )
return - V_18 ;
}
if ( F_17 ( & V_2 -> V_8 ) )
return - V_53 ;
continue;
}
F_21 ( & V_2 -> V_8 ) ;
return V_48 ;
}
static T_3 F_23 ( struct V_37 * V_38 , char T_4 * V_39 ,
T_5 V_40 , T_6 * V_68 )
{
return F_13 ( V_38 , V_39 , V_40 , 0 ) ;
}
static T_3 F_24 ( struct V_37 * V_38 ,
const char T_4 * V_39 , T_5 V_40 ,
T_6 * V_68 )
{
return F_13 ( V_38 , ( char T_4 * ) V_39 ,
V_40 , 1 ) ;
}
static unsigned int F_25 ( struct V_37 * V_38 , T_7 * V_69 )
{
struct V_1 * V_2 = V_38 -> V_43 ;
unsigned int V_70 = 0 ;
int V_5 ;
F_26 ( & V_2 -> V_8 ) ;
F_27 ( V_38 , & V_2 -> V_67 , V_69 ) ;
V_5 = F_1 ( V_2 , V_71 ) ;
F_21 ( & V_2 -> V_8 ) ;
if ( V_5 & V_72 )
V_70 |= V_73 | V_74 ;
if ( V_5 & V_75 )
V_70 |= V_76 | V_77 ;
if ( V_5 & V_78 )
V_70 |= V_79 ;
if ( F_14 ( V_49 , & V_2 -> V_4 ) )
V_70 |= V_80 ;
return V_70 ;
}
static T_8 F_28 ( int V_81 , void * V_82 )
{
struct V_6 * V_7 = V_82 ;
unsigned long V_42 ;
int V_83 = 0 ;
F_2 ( & V_7 -> V_8 , V_42 ) ;
for (; ; ) {
struct V_1 * V_2 ;
unsigned long V_84 ;
unsigned long V_34 = F_4 ( V_7 -> V_9 + V_10 ) ;
if ( V_34 == 0 )
break;
V_84 = F_4 ( V_7 -> V_9 + V_85 ) ;
V_2 = (struct V_1 * ) ( V_86 ) V_34 ;
if ( V_84 & V_87 ) {
F_20 ( V_49 , & V_2 -> V_4 ) ;
V_84 |= V_88 | V_89 ;
}
if ( V_84 & V_88 )
F_29 ( V_65 , & V_2 -> V_4 ) ;
if ( V_84 & V_89 )
F_29 ( V_64 , & V_2 -> V_4 ) ;
F_30 ( & V_2 -> V_67 ) ;
V_83 ++ ;
}
F_5 ( & V_7 -> V_8 , V_42 ) ;
return ( V_83 == 0 ) ? V_90 : V_91 ;
}
static int F_31 ( struct V_92 * V_92 , struct V_37 * V_37 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 = V_93 ;
T_9 V_5 ;
V_2 = F_32 ( sizeof( * V_2 ) , V_29 ) ;
if ( V_2 == NULL )
return - V_16 ;
V_2 -> V_7 = V_7 ;
F_33 ( & V_2 -> V_8 ) ;
F_34 ( & V_2 -> V_67 ) ;
V_5 = F_1 ( V_2 , V_94 ) ;
if ( V_5 < 0 ) {
F_35 ( V_2 ) ;
return V_5 ;
}
V_37 -> V_43 = V_2 ;
return 0 ;
}
static int F_36 ( struct V_92 * V_92 , struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_43 ;
F_6 ( V_2 , V_95 ) ;
F_35 ( V_2 ) ;
V_38 -> V_43 = NULL ;
return 0 ;
}
static int F_37 ( struct V_27 * V_28 )
{
int V_96 ;
struct V_97 * V_98 ;
struct V_6 * V_7 = V_93 ;
F_38 ( V_7 -> V_9 != NULL ) ;
F_39 ( & V_7 -> V_8 ) ;
V_98 = F_40 ( V_28 , V_99 , 0 ) ;
if ( V_98 == NULL || F_41 ( V_98 ) < V_56 ) {
F_42 ( & V_28 -> V_7 , L_1 ) ;
return - V_19 ;
}
V_7 -> V_9 = F_43 ( & V_28 -> V_7 , V_98 -> V_100 , V_56 ) ;
if ( V_7 -> V_9 == NULL ) {
F_42 ( & V_28 -> V_7 , L_2 ) ;
return - V_19 ;
}
V_98 = F_40 ( V_28 , V_101 , 0 ) ;
if ( V_98 == NULL ) {
V_96 = - V_19 ;
goto error;
}
V_7 -> V_81 = V_98 -> V_100 ;
V_96 = F_44 ( & V_28 -> V_7 , V_7 -> V_81 , F_28 ,
V_102 , L_3 , V_7 ) ;
if ( V_96 ) {
F_42 ( & V_28 -> V_7 , L_4 ) ;
goto error;
}
V_96 = F_45 ( & V_103 ) ;
if ( V_96 ) {
F_42 ( & V_28 -> V_7 , L_5 ) ;
goto error;
}
F_10 ( V_28 , V_7 ) ;
return 0 ;
error:
V_7 -> V_9 = NULL ;
return V_96 ;
}
static int F_46 ( struct V_27 * V_28 )
{
struct V_6 * V_7 = V_93 ;
F_47 ( & V_103 ) ;
V_7 -> V_9 = NULL ;
return 0 ;
}
