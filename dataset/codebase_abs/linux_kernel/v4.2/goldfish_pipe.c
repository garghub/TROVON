static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
struct V_6 * V_7 = V_2 -> V_7 ;
F_2 ( & V_7 -> V_8 , V_4 ) ;
F_3 ( V_2 , V_7 -> V_9 + V_10 ,
V_7 -> V_9 + V_11 ) ;
F_4 ( V_3 , V_7 -> V_9 + V_12 ) ;
V_5 = F_5 ( V_7 -> V_9 + V_13 ) ;
F_6 ( & V_7 -> V_8 , V_4 ) ;
return V_5 ;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
struct V_6 * V_7 = V_2 -> V_7 ;
F_2 ( & V_7 -> V_8 , V_4 ) ;
F_3 ( V_2 , V_7 -> V_9 + V_10 ,
V_7 -> V_9 + V_11 ) ;
F_4 ( V_3 , V_7 -> V_9 + V_12 ) ;
F_6 ( & V_7 -> V_8 , V_4 ) ;
}
static int F_8 ( int V_5 )
{
switch ( V_5 ) {
case V_14 :
return - V_15 ;
case V_16 :
return - V_17 ;
case V_18 :
return - V_19 ;
default:
return - V_20 ;
}
}
static int F_9 ( struct V_6 * V_7 ,
struct V_21 * V_22 )
{
T_1 V_23 , V_24 ;
T_2 V_25 ;
V_23 = F_5 ( V_7 -> V_9 + V_26 ) ;
V_24 = F_5 ( V_7 -> V_9 + V_27 ) ;
V_25 = ( ( T_2 ) V_23 << 32 ) | V_24 ;
if ( V_25 != ( F_10 ( V_22 ) ) )
return 0 ;
return 1 ;
}
static int F_11 ( struct V_28 * V_29 ,
struct V_6 * V_7 )
{
T_2 V_25 ;
struct V_21 * V_22 ;
V_22 = F_12 ( & V_29 -> V_7 , sizeof( struct V_21 ) , V_30 ) ;
if ( ! V_22 )
return - 1 ;
V_25 = F_10 ( V_22 ) ;
F_4 ( ( T_1 ) ( V_25 >> 32 ) , V_7 -> V_9 + V_26 ) ;
F_4 ( ( T_1 ) V_25 , V_7 -> V_9 + V_27 ) ;
if ( F_9 ( V_7 , V_22 ) ) {
V_7 -> V_22 = V_22 ;
return 0 ;
} else
return - 1 ;
}
static int F_13 ( struct V_6 * V_7 , const int V_3 ,
unsigned long V_31 , unsigned long V_32 ,
struct V_1 * V_2 , int * V_5 )
{
struct V_21 * V_22 = V_7 -> V_22 ;
if ( V_22 == NULL )
return - 1 ;
V_22 -> V_33 = V_34 ;
V_22 -> V_35 = ( unsigned long ) V_2 ;
V_22 -> V_36 = V_32 ;
V_22 -> V_31 = V_31 ;
V_22 -> V_3 = V_3 ;
F_4 ( V_3 , V_7 -> V_9 + V_37 ) ;
if ( V_22 -> V_33 == V_34 )
return - 1 ;
* V_5 = V_22 -> V_33 ;
return 0 ;
}
static T_3 F_14 ( struct V_38 * V_39 , char T_4 * V_40 ,
T_5 V_41 , int V_42 )
{
unsigned long V_43 ;
struct V_1 * V_2 = V_39 -> V_44 ;
struct V_6 * V_7 = V_2 -> V_7 ;
const int V_45 = V_42 ? 0
: ( V_46 - V_47 ) ;
unsigned long V_31 , V_48 ;
int V_49 = 0 ;
if ( F_15 ( V_50 , & V_2 -> V_4 ) )
return - V_19 ;
if ( F_16 ( V_41 == 0 ) )
return 0 ;
if ( ! F_17 ( V_42 ? V_51 : V_52 ,
V_40 , V_41 ) )
return - V_53 ;
if ( F_18 ( & V_2 -> V_8 ) )
return - V_54 ;
V_31 = ( unsigned long ) ( void * ) V_40 ;
V_48 = V_31 + V_41 ;
while ( V_31 < V_48 ) {
unsigned long V_55 = ( V_31 & V_56 ) + V_57 ;
unsigned long V_58 = V_55 < V_48 ? V_55
: V_48 ;
unsigned long V_32 = V_58 - V_31 ;
int V_5 , V_59 ;
if ( V_42 ) {
char V_60 ;
if ( F_19 ( V_60 , ( char T_4 * ) V_31 ) ) {
if ( ! V_49 )
V_49 = - V_53 ;
break;
}
} else {
if ( F_20 ( 0 , ( char T_4 * ) V_31 ) ) {
if ( ! V_49 )
V_49 = - V_53 ;
break;
}
}
F_2 ( & V_7 -> V_8 , V_43 ) ;
if ( F_13 ( V_7 , V_47 + V_45 ,
V_31 , V_32 , V_2 , & V_5 ) ) {
F_3 ( V_2 , V_7 -> V_9 + V_10 ,
V_7 -> V_9 + V_11 ) ;
F_4 ( V_32 , V_7 -> V_9 + V_61 ) ;
F_3 ( ( void * ) V_31 ,
V_7 -> V_9 + V_62 ,
V_7 -> V_9 + V_63 ) ;
F_4 ( V_47 + V_45 ,
V_7 -> V_9 + V_12 ) ;
V_5 = F_5 ( V_7 -> V_9 + V_13 ) ;
}
F_6 ( & V_7 -> V_8 , V_43 ) ;
if ( V_5 > 0 ) {
V_49 += V_5 ;
V_31 += V_5 ;
continue;
}
if ( V_5 == 0 )
break;
if ( V_49 > 0 )
break;
if ( V_5 != V_14 ||
( V_39 -> V_64 & V_65 ) != 0 ) {
V_49 = F_8 ( V_5 ) ;
break;
}
V_59 = V_42 ? V_66 : V_67 ;
F_21 ( V_59 , & V_2 -> V_4 ) ;
F_7 ( V_2 , V_68 + V_45 ) ;
F_22 ( & V_2 -> V_8 ) ;
while ( F_15 ( V_59 , & V_2 -> V_4 ) ) {
if ( F_23 (
V_2 -> V_69 ,
! F_15 ( V_59 , & V_2 -> V_4 ) ) )
return - V_54 ;
if ( F_15 ( V_50 , & V_2 -> V_4 ) )
return - V_19 ;
}
if ( F_18 ( & V_2 -> V_8 ) )
return - V_54 ;
continue;
}
F_22 ( & V_2 -> V_8 ) ;
return V_49 ;
}
static T_3 F_24 ( struct V_38 * V_39 , char T_4 * V_40 ,
T_5 V_41 , T_6 * V_70 )
{
return F_14 ( V_39 , V_40 , V_41 , 0 ) ;
}
static T_3 F_25 ( struct V_38 * V_39 ,
const char T_4 * V_40 , T_5 V_41 ,
T_6 * V_70 )
{
return F_14 ( V_39 , ( char T_4 * ) V_40 ,
V_41 , 1 ) ;
}
static unsigned int F_26 ( struct V_38 * V_39 , T_7 * V_71 )
{
struct V_1 * V_2 = V_39 -> V_44 ;
unsigned int V_72 = 0 ;
int V_5 ;
F_27 ( & V_2 -> V_8 ) ;
F_28 ( V_39 , & V_2 -> V_69 , V_71 ) ;
V_5 = F_1 ( V_2 , V_73 ) ;
F_22 ( & V_2 -> V_8 ) ;
if ( V_5 & V_74 )
V_72 |= V_75 | V_76 ;
if ( V_5 & V_77 )
V_72 |= V_78 | V_79 ;
if ( V_5 & V_80 )
V_72 |= V_81 ;
if ( F_15 ( V_50 , & V_2 -> V_4 ) )
V_72 |= V_82 ;
return V_72 ;
}
static T_8 F_29 ( int V_83 , void * V_84 )
{
struct V_6 * V_7 = V_84 ;
unsigned long V_43 ;
int V_85 = 0 ;
F_2 ( & V_7 -> V_8 , V_43 ) ;
for (; ; ) {
struct V_1 * V_2 ;
unsigned long V_86 ;
unsigned long V_35 = 0 ;
#ifdef F_30
V_35 = ( T_2 ) F_5 ( V_7 -> V_9 + V_11 ) << 32 ;
if ( V_35 == 0 )
break;
#endif
V_35 |= F_5 ( V_7 -> V_9 + V_10 ) ;
if ( V_35 == 0 )
break;
V_86 = F_5 ( V_7 -> V_9 + V_87 ) ;
V_2 = (struct V_1 * ) ( V_88 ) V_35 ;
if ( V_86 & V_89 ) {
F_21 ( V_50 , & V_2 -> V_4 ) ;
V_86 |= V_90 | V_91 ;
}
if ( V_86 & V_90 )
F_31 ( V_67 , & V_2 -> V_4 ) ;
if ( V_86 & V_91 )
F_31 ( V_66 , & V_2 -> V_4 ) ;
F_32 ( & V_2 -> V_69 ) ;
V_85 ++ ;
}
F_6 ( & V_7 -> V_8 , V_43 ) ;
return ( V_85 == 0 ) ? V_92 : V_93 ;
}
static int F_33 ( struct V_94 * V_94 , struct V_38 * V_38 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 = V_95 ;
T_9 V_5 ;
V_2 = F_34 ( sizeof( * V_2 ) , V_30 ) ;
if ( V_2 == NULL )
return - V_17 ;
V_2 -> V_7 = V_7 ;
F_35 ( & V_2 -> V_8 ) ;
F_36 ( & V_2 -> V_69 ) ;
V_5 = F_1 ( V_2 , V_96 ) ;
if ( V_5 < 0 ) {
F_37 ( V_2 ) ;
return V_5 ;
}
V_38 -> V_44 = V_2 ;
return 0 ;
}
static int F_38 ( struct V_94 * V_94 , struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_44 ;
F_7 ( V_2 , V_97 ) ;
F_37 ( V_2 ) ;
V_39 -> V_44 = NULL ;
return 0 ;
}
static int F_39 ( struct V_28 * V_29 )
{
int V_98 ;
struct V_99 * V_100 ;
struct V_6 * V_7 = V_95 ;
F_40 ( V_7 -> V_9 != NULL ) ;
F_41 ( & V_7 -> V_8 ) ;
V_100 = F_42 ( V_29 , V_101 , 0 ) ;
if ( V_100 == NULL || F_43 ( V_100 ) < V_57 ) {
F_44 ( & V_29 -> V_7 , L_1 ) ;
return - V_20 ;
}
V_7 -> V_9 = F_45 ( & V_29 -> V_7 , V_100 -> V_102 , V_57 ) ;
if ( V_7 -> V_9 == NULL ) {
F_44 ( & V_29 -> V_7 , L_2 ) ;
return - V_20 ;
}
V_100 = F_42 ( V_29 , V_103 , 0 ) ;
if ( V_100 == NULL ) {
V_98 = - V_20 ;
goto error;
}
V_7 -> V_83 = V_100 -> V_102 ;
V_98 = F_46 ( & V_29 -> V_7 , V_7 -> V_83 , F_29 ,
V_104 , L_3 , V_7 ) ;
if ( V_98 ) {
F_44 ( & V_29 -> V_7 , L_4 ) ;
goto error;
}
V_98 = F_47 ( & V_105 ) ;
if ( V_98 ) {
F_44 ( & V_29 -> V_7 , L_5 ) ;
goto error;
}
F_11 ( V_29 , V_7 ) ;
return 0 ;
error:
V_7 -> V_9 = NULL ;
return V_98 ;
}
static int F_48 ( struct V_28 * V_29 )
{
struct V_6 * V_7 = V_95 ;
F_49 ( & V_105 ) ;
V_7 -> V_9 = NULL ;
return 0 ;
}
