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
if ( ! F_12 ( V_9 -> V_3 -> V_27 ) )
return - V_28 ;
F_13 ( & V_21 , V_29 ) ;
F_14 ( & V_9 -> V_30 , & V_21 ) ;
F_15 ( & V_9 -> V_31 ) ;
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
F_16 ( V_39 ) ;
F_17 ( & V_9 -> V_31 ) ;
F_18 () ;
F_15 ( & V_9 -> V_31 ) ;
if ( F_19 ( V_29 ) ) {
V_20 = - V_40 ;
break;
}
}
F_20 ( & V_9 -> V_30 , & V_21 ) ;
if ( V_20 >= 0 ) {
V_20 = F_21 ( V_9 -> V_3 , V_6 ) ;
if ( V_20 >= 0 ) {
V_6 -> V_10 = V_9 ;
V_9 -> V_33 ++ ;
} else {
if ( V_9 -> V_11 . V_41 )
V_9 -> V_11 . V_41 ( V_9 , V_6 ) ;
}
}
F_17 ( & V_9 -> V_31 ) ;
if ( V_20 < 0 )
F_22 ( V_9 -> V_3 -> V_27 ) ;
return V_20 ;
}
static int F_23 ( struct V_18 * V_18 , struct V_6 * V_6 )
{
int V_20 = 0 ;
struct V_1 * V_9 = V_6 -> V_10 ;
struct V_27 * V_42 = V_9 -> V_3 -> V_27 ;
F_15 ( & V_9 -> V_31 ) ;
if ( V_9 -> V_11 . V_41 )
V_20 = V_9 -> V_11 . V_41 ( V_9 , V_6 ) ;
if ( V_9 -> V_33 > 0 )
V_9 -> V_33 -- ;
F_17 ( & V_9 -> V_31 ) ;
F_24 ( & V_9 -> V_30 ) ;
F_25 ( V_9 -> V_3 , V_6 ) ;
F_22 ( V_42 ) ;
return V_20 ;
}
static unsigned int F_26 ( struct V_6 * V_6 , T_6 * V_21 )
{
struct V_1 * V_9 = V_6 -> V_10 ;
if ( V_9 -> V_11 . V_43 )
return V_9 -> V_11 . V_43 ( V_9 , V_6 , V_21 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_9 ,
struct F_27 T_3 * V_44 )
{
struct F_27 V_45 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_3 = V_9 -> V_3 -> V_46 ;
F_28 ( V_45 . V_47 , V_9 -> V_47 , sizeof( V_45 . V_47 ) ) ;
F_28 ( V_45 . V_48 , V_9 -> V_48 , sizeof( V_45 . V_48 ) ) ;
V_45 . V_49 = V_9 -> V_49 ;
if ( F_29 ( V_44 , & V_45 , sizeof( V_45 ) ) )
return - V_28 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_9 ,
struct F_30 T_3 * V_44 )
{
struct F_30 V_45 ;
int V_20 ;
if ( ! V_9 -> V_11 . V_50 )
return - V_13 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_51 = V_9 -> V_51 ;
if ( ( V_20 = V_9 -> V_11 . V_50 ( V_9 , & V_45 ) ) < 0 )
return V_20 ;
if ( F_29 ( V_44 , & V_45 , sizeof( V_45 ) ) )
return - V_28 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_9 ,
struct V_52 T_3 * V_44 )
{
struct V_52 V_45 ;
int V_20 ;
if ( ! V_9 -> V_11 . V_53 )
return - V_13 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
if ( F_32 ( & V_45 , V_44 , sizeof( V_45 ) ) )
return - V_28 ;
if ( V_9 -> V_51 & ( 1 << V_45 . V_54 ) )
return - V_34 ;
if ( ! F_33 ( V_55 , V_45 . V_56 , V_45 . V_57 ) )
return - V_28 ;
V_20 = V_9 -> V_11 . V_53 ( V_9 , & V_45 ) ;
if ( V_20 < 0 )
return V_20 ;
V_9 -> V_51 |= ( 1 << V_45 . V_54 ) ;
return 0 ;
}
static long F_34 ( struct V_6 * V_6 , unsigned int V_58 ,
unsigned long V_59 )
{
struct V_1 * V_9 = V_6 -> V_10 ;
void T_3 * V_60 = ( void T_3 * ) V_59 ;
switch ( V_58 ) {
case V_61 :
return F_35 ( V_62 , ( int T_3 * ) V_60 ) ;
case V_63 :
return F_27 ( V_9 , V_60 ) ;
case V_64 :
return F_30 ( V_9 , V_60 ) ;
case V_65 :
return F_31 ( V_9 , V_60 ) ;
}
if ( V_9 -> V_11 . V_66 )
return V_9 -> V_11 . V_66 ( V_9 , V_6 , V_58 , V_59 ) ;
return - V_67 ;
}
static int F_36 ( struct V_6 * V_6 , struct V_68 * V_69 )
{
struct V_1 * V_9 = V_6 -> V_10 ;
if ( V_9 -> V_11 . V_70 )
return V_9 -> V_11 . V_70 ( V_9 , V_6 , V_69 ) ;
return - V_13 ;
}
static int F_37 ( struct V_2 * V_3 ,
struct V_71 * V_72 ,
unsigned int V_58 , unsigned long V_59 )
{
switch ( V_58 ) {
case V_73 :
{
int V_4 ;
if ( F_38 ( V_4 , ( int T_3 * ) V_59 ) )
return - V_28 ;
F_15 ( & V_74 ) ;
V_4 = V_4 < 0 ? 0 : V_4 + 1 ;
while ( V_4 < V_75 ) {
if ( F_1 ( V_3 , V_4 ) )
break;
V_4 ++ ;
}
if ( V_4 >= V_75 )
V_4 = - 1 ;
F_17 ( & V_74 ) ;
if ( F_35 ( V_4 , ( int T_3 * ) V_59 ) )
return - V_28 ;
return 0 ;
}
case V_76 :
{
struct F_27 T_3 * V_45 = (struct F_27 T_3 * ) V_59 ;
int V_4 , V_20 ;
struct V_1 * V_5 ;
if ( F_38 ( V_4 , & V_45 -> V_4 ) )
return - V_28 ;
F_15 ( & V_74 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 )
V_20 = F_27 ( V_5 , V_45 ) ;
else
V_20 = - V_13 ;
F_17 ( & V_74 ) ;
return V_20 ;
}
}
return - V_77 ;
}
int F_39 ( struct V_2 * V_3 , char * V_47 , int V_4 ,
struct V_1 * * V_78 )
{
struct V_1 * V_5 ;
int V_20 ;
static struct V_79 V_11 = {
. V_80 = V_81 ,
. V_82 = V_83 ,
. V_84 = V_85 ,
} ;
if ( F_40 ( ! V_3 ) )
return - V_13 ;
if ( V_78 )
* V_78 = NULL ;
V_5 = F_41 ( sizeof( * V_5 ) , V_86 ) ;
if ( V_5 == NULL ) {
F_42 ( V_87 L_1 ) ;
return - V_88 ;
}
V_5 -> V_3 = V_3 ;
V_5 -> V_4 = V_4 ;
if ( V_47 )
F_28 ( V_5 -> V_47 , V_47 , sizeof( V_5 -> V_47 ) ) ;
#ifdef F_10
V_5 -> V_89 = - 1 ;
#endif
if ( ( V_20 = F_43 ( V_3 , V_90 , V_5 , & V_11 ) ) < 0 ) {
F_44 ( V_5 ) ;
return V_20 ;
}
F_45 ( & V_5 -> V_30 ) ;
F_46 ( & V_5 -> V_31 ) ;
if ( V_78 )
* V_78 = V_5 ;
return 0 ;
}
static int F_44 ( struct V_1 * V_5 )
{
if ( ! V_5 )
return 0 ;
if ( V_5 -> V_91 )
V_5 -> V_91 ( V_5 ) ;
F_47 ( V_5 ) ;
return 0 ;
}
static int V_81 ( struct V_92 * V_4 )
{
struct V_1 * V_5 = V_4 -> V_93 ;
return F_44 ( V_5 ) ;
}
static int V_83 ( struct V_92 * V_4 )
{
struct V_1 * V_5 = V_4 -> V_93 ;
int V_20 ;
char V_48 [ 32 ] ;
F_15 ( & V_74 ) ;
if ( F_1 ( V_5 -> V_3 , V_5 -> V_4 ) ) {
F_17 ( & V_74 ) ;
return - V_34 ;
}
F_48 ( & V_5 -> V_94 , & V_95 ) ;
sprintf ( V_48 , L_2 , V_5 -> V_3 -> V_46 , V_5 -> V_4 ) ;
if ( ( V_20 = F_49 ( V_23 ,
V_5 -> V_3 , V_5 -> V_4 ,
& V_96 , V_5 , V_48 ) ) < 0 ) {
F_42 ( V_87 L_3 ,
V_5 -> V_3 -> V_46 , V_5 -> V_4 ) ;
F_50 ( & V_5 -> V_94 ) ;
F_17 ( & V_74 ) ;
return V_20 ;
}
#ifdef F_10
V_5 -> V_97 = 0 ;
if ( V_5 -> V_89 >= 0 ) {
if ( ( V_5 -> V_89 == V_25 ) && ( V_5 -> V_4 != 0 ) ) {
F_42 ( V_98 L_4 ) ;
} else {
if ( F_51 ( V_5 -> V_89 ,
V_5 -> V_3 , V_5 -> V_4 ,
& V_96 , V_5 ,
V_5 -> V_99 ) < 0 ) {
F_42 ( V_87 L_5 ,
V_5 -> V_3 -> V_46 , V_5 -> V_4 ) ;
} else
V_5 -> V_97 = 1 ;
}
}
#endif
F_17 ( & V_74 ) ;
return 0 ;
}
static int V_85 ( struct V_92 * V_4 )
{
struct V_1 * V_5 = V_4 -> V_93 ;
if ( F_40 ( ! V_5 ) )
return - V_13 ;
F_15 ( & V_74 ) ;
if ( F_1 ( V_5 -> V_3 , V_5 -> V_4 ) != V_5 ) {
F_17 ( & V_74 ) ;
return - V_100 ;
}
#ifdef F_10
if ( V_5 -> V_97 )
F_52 ( V_5 -> V_89 , V_5 -> V_3 , V_5 -> V_4 ) ;
#endif
F_53 ( V_23 , V_5 -> V_3 , V_5 -> V_4 ) ;
F_54 ( & V_5 -> V_94 ) ;
F_17 ( & V_74 ) ;
return 0 ;
}
static void F_55 ( struct V_101 * V_102 ,
struct V_103 * V_104 )
{
struct V_1 * V_5 ;
F_15 ( & V_74 ) ;
F_2 (hwdep, &snd_hwdep_devices, list)
F_56 ( V_104 , L_6 ,
V_5 -> V_3 -> V_46 , V_5 -> V_4 , V_5 -> V_48 ) ;
F_17 ( & V_74 ) ;
}
static void T_7 F_57 ( void )
{
struct V_101 * V_102 ;
if ( ( V_102 = F_58 ( V_105 , L_7 , NULL ) ) != NULL ) {
V_102 -> V_106 . V_107 . V_16 = F_55 ;
if ( F_59 ( V_102 ) < 0 ) {
F_60 ( V_102 ) ;
V_102 = NULL ;
}
}
V_108 = V_102 ;
}
static void T_8 F_61 ( void )
{
F_60 ( V_108 ) ;
}
static int T_7 F_62 ( void )
{
F_57 () ;
F_63 ( F_37 ) ;
F_64 ( F_37 ) ;
return 0 ;
}
static void T_8 F_65 ( void )
{
F_66 ( F_37 ) ;
F_67 ( F_37 ) ;
F_61 () ;
}
