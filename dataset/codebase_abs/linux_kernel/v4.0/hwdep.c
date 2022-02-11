static struct V_1 * F_1 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_5 ;
F_2 (hwdep, &snd_hwdep_devices, list)
if ( V_5 -> V_3 == V_3 && V_5 -> V_4 == V_4 )
return V_5 ;
return NULL ;
}
static T_1 F_3 ( struct V_6 * V_6 , T_1 V_7 , int V_8 )
{
struct V_1 * V_9 = V_6 -> V_10 ;
if ( V_9 -> V_11 . V_12 )
return V_9 -> V_11 . V_12 ( V_9 , V_6 , V_7 , V_8 ) ;
return - V_13 ;
}
static T_2 F_4 ( struct V_6 * V_6 , char T_3 * V_14 ,
T_4 V_15 , T_1 * V_7 )
{
struct V_1 * V_9 = V_6 -> V_10 ;
if ( V_9 -> V_11 . V_16 )
return V_9 -> V_11 . V_16 ( V_9 , V_14 , V_15 , V_7 ) ;
return - V_13 ;
}
static T_2 F_5 ( struct V_6 * V_6 , const char T_3 * V_14 ,
T_4 V_15 , T_1 * V_7 )
{
struct V_1 * V_9 = V_6 -> V_10 ;
if ( V_9 -> V_11 . V_17 )
return V_9 -> V_11 . V_17 ( V_9 , V_14 , V_15 , V_7 ) ;
return - V_13 ;
}
static int F_6 ( struct V_18 * V_18 , struct V_6 * V_6 )
{
int V_19 = F_7 ( V_18 ) ;
struct V_1 * V_9 ;
int V_20 ;
T_5 V_21 ;
if ( V_19 == V_22 ) {
V_9 = F_8 ( F_9 ( V_18 ) ,
V_23 ) ;
#ifdef F_10
} else if ( V_19 == V_24 ) {
V_9 = F_11 ( F_9 ( V_18 ) ,
V_25 ) ;
#endif
} else
return - V_13 ;
if ( V_9 == NULL )
return - V_26 ;
if ( ! F_12 ( V_9 -> V_3 -> V_27 ) ) {
F_13 ( V_9 -> V_3 ) ;
return - V_28 ;
}
F_14 ( & V_21 , V_29 ) ;
F_15 ( & V_9 -> V_30 , & V_21 ) ;
F_16 ( & V_9 -> V_31 ) ;
while ( 1 ) {
if ( V_9 -> V_32 && V_9 -> V_33 > 0 ) {
V_20 = - V_34 ;
break;
}
if ( ! V_9 -> V_11 . V_35 ) {
V_20 = 0 ;
break;
}
V_20 = V_9 -> V_11 . V_35 ( V_9 , V_6 ) ;
if ( V_20 >= 0 )
break;
if ( V_20 == - V_36 ) {
if ( V_6 -> V_37 & V_38 ) {
V_20 = - V_34 ;
break;
}
} else
break;
F_17 ( V_39 ) ;
F_18 ( & V_9 -> V_31 ) ;
F_19 () ;
F_16 ( & V_9 -> V_31 ) ;
if ( V_9 -> V_3 -> V_40 ) {
V_20 = - V_26 ;
break;
}
if ( F_20 ( V_29 ) ) {
V_20 = - V_41 ;
break;
}
}
F_21 ( & V_9 -> V_30 , & V_21 ) ;
if ( V_20 >= 0 ) {
V_20 = F_22 ( V_9 -> V_3 , V_6 ) ;
if ( V_20 >= 0 ) {
V_6 -> V_10 = V_9 ;
V_9 -> V_33 ++ ;
} else {
if ( V_9 -> V_11 . V_42 )
V_9 -> V_11 . V_42 ( V_9 , V_6 ) ;
}
}
F_18 ( & V_9 -> V_31 ) ;
if ( V_20 < 0 )
F_23 ( V_9 -> V_3 -> V_27 ) ;
F_13 ( V_9 -> V_3 ) ;
return V_20 ;
}
static int F_24 ( struct V_18 * V_18 , struct V_6 * V_6 )
{
int V_20 = 0 ;
struct V_1 * V_9 = V_6 -> V_10 ;
struct V_27 * V_43 = V_9 -> V_3 -> V_27 ;
F_16 ( & V_9 -> V_31 ) ;
if ( V_9 -> V_11 . V_42 )
V_20 = V_9 -> V_11 . V_42 ( V_9 , V_6 ) ;
if ( V_9 -> V_33 > 0 )
V_9 -> V_33 -- ;
F_18 ( & V_9 -> V_31 ) ;
F_25 ( & V_9 -> V_30 ) ;
F_26 ( V_9 -> V_3 , V_6 ) ;
F_23 ( V_43 ) ;
return V_20 ;
}
static unsigned int F_27 ( struct V_6 * V_6 , T_6 * V_21 )
{
struct V_1 * V_9 = V_6 -> V_10 ;
if ( V_9 -> V_11 . V_44 )
return V_9 -> V_11 . V_44 ( V_9 , V_6 , V_21 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_9 ,
struct F_28 T_3 * V_45 )
{
struct F_28 V_46 ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
V_46 . V_3 = V_9 -> V_3 -> V_47 ;
F_29 ( V_46 . V_48 , V_9 -> V_48 , sizeof( V_46 . V_48 ) ) ;
F_29 ( V_46 . V_49 , V_9 -> V_49 , sizeof( V_46 . V_49 ) ) ;
V_46 . V_50 = V_9 -> V_50 ;
if ( F_30 ( V_45 , & V_46 , sizeof( V_46 ) ) )
return - V_28 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_9 ,
struct F_31 T_3 * V_45 )
{
struct F_31 V_46 ;
int V_20 ;
if ( ! V_9 -> V_11 . V_51 )
return - V_13 ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
V_46 . V_52 = V_9 -> V_52 ;
if ( ( V_20 = V_9 -> V_11 . V_51 ( V_9 , & V_46 ) ) < 0 )
return V_20 ;
if ( F_30 ( V_45 , & V_46 , sizeof( V_46 ) ) )
return - V_28 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_9 ,
struct V_53 T_3 * V_45 )
{
struct V_53 V_46 ;
int V_20 ;
if ( ! V_9 -> V_11 . V_54 )
return - V_13 ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
if ( F_33 ( & V_46 , V_45 , sizeof( V_46 ) ) )
return - V_28 ;
if ( V_9 -> V_52 & ( 1 << V_46 . V_55 ) )
return - V_34 ;
if ( ! F_34 ( V_56 , V_46 . V_57 , V_46 . V_58 ) )
return - V_28 ;
V_20 = V_9 -> V_11 . V_54 ( V_9 , & V_46 ) ;
if ( V_20 < 0 )
return V_20 ;
V_9 -> V_52 |= ( 1 << V_46 . V_55 ) ;
return 0 ;
}
static long F_35 ( struct V_6 * V_6 , unsigned int V_59 ,
unsigned long V_60 )
{
struct V_1 * V_9 = V_6 -> V_10 ;
void T_3 * V_61 = ( void T_3 * ) V_60 ;
switch ( V_59 ) {
case V_62 :
return F_36 ( V_63 , ( int T_3 * ) V_61 ) ;
case V_64 :
return F_28 ( V_9 , V_61 ) ;
case V_65 :
return F_31 ( V_9 , V_61 ) ;
case V_66 :
return F_32 ( V_9 , V_61 ) ;
}
if ( V_9 -> V_11 . V_67 )
return V_9 -> V_11 . V_67 ( V_9 , V_6 , V_59 , V_60 ) ;
return - V_68 ;
}
static int F_37 ( struct V_6 * V_6 , struct V_69 * V_70 )
{
struct V_1 * V_9 = V_6 -> V_10 ;
if ( V_9 -> V_11 . V_71 )
return V_9 -> V_11 . V_71 ( V_9 , V_6 , V_70 ) ;
return - V_13 ;
}
static int F_38 ( struct V_2 * V_3 ,
struct V_72 * V_73 ,
unsigned int V_59 , unsigned long V_60 )
{
switch ( V_59 ) {
case V_74 :
{
int V_4 ;
if ( F_39 ( V_4 , ( int T_3 * ) V_60 ) )
return - V_28 ;
F_16 ( & V_75 ) ;
if ( V_4 < 0 )
V_4 = 0 ;
else if ( V_4 < V_76 )
V_4 ++ ;
else
V_4 = V_76 ;
while ( V_4 < V_76 ) {
if ( F_1 ( V_3 , V_4 ) )
break;
V_4 ++ ;
}
if ( V_4 >= V_76 )
V_4 = - 1 ;
F_18 ( & V_75 ) ;
if ( F_36 ( V_4 , ( int T_3 * ) V_60 ) )
return - V_28 ;
return 0 ;
}
case V_77 :
{
struct F_28 T_3 * V_46 = (struct F_28 T_3 * ) V_60 ;
int V_4 , V_20 ;
struct V_1 * V_5 ;
if ( F_39 ( V_4 , & V_46 -> V_4 ) )
return - V_28 ;
F_16 ( & V_75 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 )
V_20 = F_28 ( V_5 , V_46 ) ;
else
V_20 = - V_13 ;
F_18 ( & V_75 ) ;
return V_20 ;
}
}
return - V_78 ;
}
static void F_40 ( struct V_4 * V_79 )
{
F_41 ( F_42 ( V_79 , struct V_1 , V_79 ) ) ;
}
int F_43 ( struct V_2 * V_3 , char * V_48 , int V_4 ,
struct V_1 * * V_80 )
{
struct V_1 * V_5 ;
int V_20 ;
static struct V_81 V_11 = {
. V_82 = V_83 ,
. V_84 = V_85 ,
. V_86 = V_87 ,
} ;
if ( F_44 ( ! V_3 ) )
return - V_13 ;
if ( V_80 )
* V_80 = NULL ;
V_5 = F_45 ( sizeof( * V_5 ) , V_88 ) ;
if ( V_5 == NULL ) {
F_46 ( V_3 -> V_79 , L_1 ) ;
return - V_89 ;
}
F_47 ( & V_5 -> V_30 ) ;
F_48 ( & V_5 -> V_31 ) ;
V_5 -> V_3 = V_3 ;
V_5 -> V_4 = V_4 ;
if ( V_48 )
F_29 ( V_5 -> V_48 , V_48 , sizeof( V_5 -> V_48 ) ) ;
F_49 ( & V_5 -> V_79 , V_3 ) ;
V_5 -> V_79 . V_42 = F_40 ;
F_50 ( & V_5 -> V_79 , L_2 , V_3 -> V_47 , V_4 ) ;
#ifdef F_10
V_5 -> V_90 = - 1 ;
#endif
V_20 = F_51 ( V_3 , V_91 , V_5 , & V_11 ) ;
if ( V_20 < 0 ) {
F_52 ( & V_5 -> V_79 ) ;
return V_20 ;
}
if ( V_80 )
* V_80 = V_5 ;
return 0 ;
}
static int V_83 ( struct V_92 * V_4 )
{
struct V_1 * V_5 = V_4 -> V_93 ;
if ( ! V_5 )
return 0 ;
if ( V_5 -> V_94 )
V_5 -> V_94 ( V_5 ) ;
F_52 ( & V_5 -> V_79 ) ;
return 0 ;
}
static int V_85 ( struct V_92 * V_4 )
{
struct V_1 * V_5 = V_4 -> V_93 ;
struct V_2 * V_3 = V_5 -> V_3 ;
int V_20 ;
F_16 ( & V_75 ) ;
if ( F_1 ( V_3 , V_5 -> V_4 ) ) {
F_18 ( & V_75 ) ;
return - V_34 ;
}
F_53 ( & V_5 -> V_95 , & V_96 ) ;
V_20 = F_54 ( V_23 ,
V_5 -> V_3 , V_5 -> V_4 ,
& V_97 , V_5 , & V_5 -> V_79 ) ;
if ( V_20 < 0 ) {
F_46 ( & V_5 -> V_79 , L_3 ) ;
F_55 ( & V_5 -> V_95 ) ;
F_18 ( & V_75 ) ;
return V_20 ;
}
#ifdef F_10
V_5 -> V_98 = 0 ;
if ( V_5 -> V_90 >= 0 ) {
if ( V_5 -> V_90 == V_25 &&
V_5 -> V_4 )
F_56 ( & V_5 -> V_79 ,
L_4 ) ;
else if ( F_57 ( V_5 -> V_90 ,
V_3 , V_5 -> V_4 ,
& V_97 , V_5 ) < 0 )
F_56 ( & V_5 -> V_79 ,
L_5 ) ;
else
V_5 -> V_98 = 1 ;
}
#endif
F_18 ( & V_75 ) ;
return 0 ;
}
static int V_87 ( struct V_92 * V_4 )
{
struct V_1 * V_5 = V_4 -> V_93 ;
if ( F_44 ( ! V_5 ) )
return - V_13 ;
F_16 ( & V_75 ) ;
if ( F_1 ( V_5 -> V_3 , V_5 -> V_4 ) != V_5 ) {
F_18 ( & V_75 ) ;
return - V_99 ;
}
F_16 ( & V_5 -> V_31 ) ;
F_25 ( & V_5 -> V_30 ) ;
#ifdef F_10
if ( V_5 -> V_98 )
F_58 ( V_5 -> V_90 , V_5 -> V_3 , V_5 -> V_4 ) ;
#endif
F_59 ( & V_5 -> V_79 ) ;
F_60 ( & V_5 -> V_95 ) ;
F_18 ( & V_5 -> V_31 ) ;
F_18 ( & V_75 ) ;
return 0 ;
}
static void F_61 ( struct V_100 * V_101 ,
struct V_102 * V_103 )
{
struct V_1 * V_5 ;
F_16 ( & V_75 ) ;
F_2 (hwdep, &snd_hwdep_devices, list)
F_62 ( V_103 , L_6 ,
V_5 -> V_3 -> V_47 , V_5 -> V_4 , V_5 -> V_49 ) ;
F_18 ( & V_75 ) ;
}
static void T_7 F_63 ( void )
{
struct V_100 * V_101 ;
if ( ( V_101 = F_64 ( V_104 , L_7 , NULL ) ) != NULL ) {
V_101 -> V_105 . V_106 . V_16 = F_61 ;
if ( F_65 ( V_101 ) < 0 ) {
F_66 ( V_101 ) ;
V_101 = NULL ;
}
}
V_107 = V_101 ;
}
static void T_8 F_67 ( void )
{
F_66 ( V_107 ) ;
}
static int T_7 F_68 ( void )
{
F_63 () ;
F_69 ( F_38 ) ;
F_70 ( F_38 ) ;
return 0 ;
}
static void T_8 F_71 ( void )
{
F_72 ( F_38 ) ;
F_73 ( F_38 ) ;
F_67 () ;
}
