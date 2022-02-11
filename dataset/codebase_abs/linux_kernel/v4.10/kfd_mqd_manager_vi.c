static inline struct V_1 * F_1 ( void * V_2 )
{
return (struct V_1 * ) V_2 ;
}
static int F_2 ( struct V_3 * V_4 , void * * V_2 ,
struct V_5 * * V_6 , T_1 * V_7 ,
struct V_8 * V_9 )
{
int V_10 ;
T_1 V_11 ;
struct V_1 * V_12 ;
V_10 = F_3 ( V_4 -> V_13 , sizeof( struct V_1 ) ,
V_6 ) ;
if ( V_10 != 0 )
return - V_14 ;
V_12 = (struct V_1 * ) ( * V_6 ) -> V_15 ;
V_11 = ( * V_6 ) -> V_16 ;
memset ( V_12 , 0 , sizeof( struct V_1 ) ) ;
V_12 -> V_17 = 0xC0310800 ;
V_12 -> V_18 = 1 ;
V_12 -> V_19 = 0xFFFFFFFF ;
V_12 -> V_20 = 0xFFFFFFFF ;
V_12 -> V_21 = 0xFFFFFFFF ;
V_12 -> V_22 = 0xFFFFFFFF ;
V_12 -> V_23 = V_24 |
0x53 << V_25 ;
V_12 -> V_26 = 1 << V_27 |
V_28 << V_29 ;
V_12 -> V_30 = F_4 ( V_11 ) ;
V_12 -> V_31 = F_5 ( V_11 ) ;
V_12 -> V_32 = 1 << V_33 |
1 << V_34 |
10 << V_35 ;
V_12 -> V_36 = 1 ;
V_12 -> V_37 = 15 ;
V_12 -> V_38 = 1 << V_39 ;
if ( V_9 -> V_40 == V_41 )
V_12 -> V_42 = 1 ;
* V_2 = V_12 ;
if ( V_7 != NULL )
* V_7 = V_11 ;
V_10 = V_4 -> V_43 ( V_4 , V_12 , V_9 ) ;
return V_10 ;
}
static int F_6 ( struct V_3 * V_4 , void * V_2 ,
T_2 V_44 , T_2 V_45 ,
T_2 T_3 * V_46 )
{
return V_4 -> V_13 -> V_47 -> V_48
( V_4 -> V_13 -> V_49 , V_2 , V_44 , V_45 , V_46 ) ;
}
static int F_7 ( struct V_3 * V_4 , void * V_2 ,
struct V_8 * V_9 , unsigned int V_50 ,
unsigned int V_51 )
{
struct V_1 * V_12 ;
F_8 ( ! V_4 || ! V_9 || ! V_2 ) ;
F_9 ( L_1 , V_52 ) ;
V_12 = F_1 ( V_2 ) ;
V_12 -> V_53 = 5 << V_54 |
V_51 << V_55 |
V_50 << V_56 ;
V_12 -> V_53 |=
F_10 ( V_9 -> V_57 / sizeof( unsigned int ) ) - 1 - 1 ;
F_9 ( L_2 , V_12 -> V_53 ) ;
V_12 -> V_58 = F_4 ( ( T_1 ) V_9 -> V_59 >> 8 ) ;
V_12 -> V_60 = F_5 ( ( T_1 ) V_9 -> V_59 >> 8 ) ;
V_12 -> V_61 = F_4 ( ( T_1 ) V_9 -> V_62 ) ;
V_12 -> V_63 = F_5 ( ( T_1 ) V_9 -> V_62 ) ;
V_12 -> V_64 =
1 << V_65 |
V_9 -> V_66 <<
V_67 ;
F_9 ( L_3 ,
V_12 -> V_64 ) ;
V_12 -> V_68 = V_51 << V_69 |
V_50 << V_70 ;
V_12 -> V_71 = V_51 << V_72 |
3 << V_73 |
V_50 << V_74 ;
V_12 -> V_68 |=
F_10 ( V_9 -> V_75 / sizeof( unsigned int ) ) - 1 - 1 ;
V_12 -> V_76 =
F_4 ( V_9 -> V_77 >> 8 ) ;
V_12 -> V_78 =
F_5 ( V_9 -> V_77 >> 8 ) ;
V_12 -> V_79 = V_51 << V_80 |
V_50 << V_81 ;
V_12 -> V_82 = V_9 -> V_83 ;
if ( V_9 -> V_40 == V_41 ) {
V_12 -> V_53 |= V_84 |
2 << V_85 ;
}
V_12 -> V_86 = 0 ;
V_9 -> V_87 = false ;
if ( V_9 -> V_57 > 0 &&
V_9 -> V_59 != 0 &&
V_9 -> V_88 > 0 ) {
V_12 -> V_86 = 1 ;
V_9 -> V_87 = true ;
}
return 0 ;
}
static int V_43 ( struct V_3 * V_4 , void * V_2 ,
struct V_8 * V_9 )
{
return F_7 ( V_4 , V_2 , V_9 , V_89 , 1 ) ;
}
static int F_11 ( struct V_3 * V_4 , void * V_2 ,
enum V_90 type ,
unsigned int V_91 , T_2 V_44 ,
T_2 V_45 )
{
return V_4 -> V_13 -> V_47 -> V_92
( V_4 -> V_13 -> V_49 , type , V_91 ,
V_44 , V_45 ) ;
}
static void F_12 ( struct V_3 * V_4 , void * V_2 ,
struct V_5 * V_6 )
{
F_8 ( ! V_4 || ! V_2 ) ;
F_13 ( V_4 -> V_13 , V_6 ) ;
}
static bool F_14 ( struct V_3 * V_4 , void * V_2 ,
T_1 V_59 , T_2 V_44 ,
T_2 V_45 )
{
return V_4 -> V_13 -> V_47 -> V_93 (
V_4 -> V_13 -> V_49 , V_59 ,
V_44 , V_45 ) ;
}
static int F_15 ( struct V_3 * V_4 , void * * V_2 ,
struct V_5 * * V_6 , T_1 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_12 ;
int V_10 = F_2 ( V_4 , V_2 , V_6 , V_7 , V_9 ) ;
if ( V_10 != 0 )
return V_10 ;
V_12 = F_1 ( * V_2 ) ;
V_12 -> V_53 |= 1 << V_94 |
1 << V_95 ;
return V_10 ;
}
static int F_16 ( struct V_3 * V_4 , void * V_2 ,
struct V_8 * V_9 )
{
struct V_1 * V_12 ;
int V_10 = F_7 ( V_4 , V_2 , V_9 , V_28 , 0 ) ;
if ( V_10 != 0 )
return V_10 ;
V_12 = F_1 ( V_2 ) ;
V_12 -> V_82 = V_9 -> V_83 ;
return V_10 ;
}
struct V_3 * F_17 ( enum V_96 type ,
struct V_97 * V_13 )
{
struct V_3 * V_2 ;
F_8 ( ! V_13 ) ;
F_8 ( type >= V_98 ) ;
F_9 ( L_1 , V_52 ) ;
V_2 = F_18 ( sizeof( struct V_3 ) , V_99 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_13 = V_13 ;
switch ( type ) {
case V_100 :
case V_101 :
V_2 -> F_2 = F_2 ;
V_2 -> F_12 = F_12 ;
V_2 -> F_6 = F_6 ;
V_2 -> V_43 = V_43 ;
V_2 -> F_11 = F_11 ;
V_2 -> F_14 = F_14 ;
break;
case V_102 :
V_2 -> F_2 = F_15 ;
V_2 -> F_12 = F_12 ;
V_2 -> F_6 = F_6 ;
V_2 -> V_43 = F_16 ;
V_2 -> F_11 = F_11 ;
V_2 -> F_14 = F_14 ;
break;
case V_103 :
break;
default:
F_19 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
