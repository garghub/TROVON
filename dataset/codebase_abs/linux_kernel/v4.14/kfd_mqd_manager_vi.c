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
if ( V_7 )
* V_7 = V_11 ;
V_10 = V_4 -> V_43 ( V_4 , V_12 , V_9 ) ;
return V_10 ;
}
static int F_6 ( struct V_3 * V_4 , void * V_2 ,
T_2 V_44 , T_2 V_45 ,
struct V_8 * V_46 , struct V_47 * V_48 )
{
T_2 V_49 = ( V_46 -> V_40 == V_41 ? 4 : 0 ) ;
T_2 V_50 = ( T_2 ) ( ( V_46 -> V_51 / sizeof( T_2 ) ) - 1 ) ;
return V_4 -> V_13 -> V_52 -> V_53 ( V_4 -> V_13 -> V_54 , V_2 , V_44 , V_45 ,
( T_2 V_55 * ) V_46 -> V_56 ,
V_49 , V_50 , V_48 ) ;
}
static int F_7 ( struct V_3 * V_4 , void * V_2 ,
struct V_8 * V_9 , unsigned int V_57 ,
unsigned int V_58 )
{
struct V_1 * V_12 ;
V_12 = F_1 ( V_2 ) ;
V_12 -> V_59 = 5 << V_60 |
V_58 << V_61 |
V_57 << V_62 ;
V_12 -> V_59 |=
F_8 ( V_9 -> V_51 / sizeof( unsigned int ) ) - 1 - 1 ;
F_9 ( L_1 , V_12 -> V_59 ) ;
V_12 -> V_63 = F_4 ( ( T_1 ) V_9 -> V_64 >> 8 ) ;
V_12 -> V_65 = F_5 ( ( T_1 ) V_9 -> V_64 >> 8 ) ;
V_12 -> V_66 = F_4 ( ( T_1 ) V_9 -> V_67 ) ;
V_12 -> V_68 = F_5 ( ( T_1 ) V_9 -> V_67 ) ;
V_12 -> V_69 =
V_9 -> V_70 <<
V_71 ;
F_9 ( L_2 ,
V_12 -> V_69 ) ;
V_12 -> V_72 = V_58 << V_73 |
V_57 << V_74 ;
V_12 -> V_75 = V_58 << V_76 |
3 << V_77 |
V_57 << V_78 ;
V_12 -> V_72 |= F_10 ( 0xA ,
F_8 ( V_9 -> V_79 / sizeof( unsigned int ) ) - 1 - 1 ) ;
V_12 -> V_80 =
F_4 ( V_9 -> V_81 >> 8 ) ;
V_12 -> V_82 =
F_5 ( V_9 -> V_81 >> 8 ) ;
V_12 -> V_83 = V_58 << V_84 |
V_57 << V_85 ;
V_12 -> V_86 = V_9 -> V_87 ;
if ( V_9 -> V_40 == V_41 ) {
V_12 -> V_59 |= V_88 |
2 << V_89 ;
}
V_9 -> V_90 = false ;
if ( V_9 -> V_51 > 0 &&
V_9 -> V_64 != 0 &&
V_9 -> V_91 > 0 ) {
V_9 -> V_90 = true ;
}
return 0 ;
}
static int V_43 ( struct V_3 * V_4 , void * V_2 ,
struct V_8 * V_9 )
{
return F_7 ( V_4 , V_2 , V_9 , V_92 , 1 ) ;
}
static int F_11 ( struct V_3 * V_4 , void * V_2 ,
enum V_93 type ,
unsigned int V_94 , T_2 V_44 ,
T_2 V_45 )
{
return V_4 -> V_13 -> V_52 -> V_95
( V_4 -> V_13 -> V_54 , V_2 , type , V_94 ,
V_44 , V_45 ) ;
}
static void F_12 ( struct V_3 * V_4 , void * V_2 ,
struct V_5 * V_6 )
{
F_13 ( V_4 -> V_13 , V_6 ) ;
}
static bool F_14 ( struct V_3 * V_4 , void * V_2 ,
T_1 V_64 , T_2 V_44 ,
T_2 V_45 )
{
return V_4 -> V_13 -> V_52 -> V_96 (
V_4 -> V_13 -> V_54 , V_64 ,
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
V_12 -> V_59 |= 1 << V_97 |
1 << V_98 ;
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
V_12 -> V_86 = V_9 -> V_87 ;
return V_10 ;
}
struct V_3 * F_17 ( enum V_99 type ,
struct V_100 * V_13 )
{
struct V_3 * V_2 ;
if ( F_18 ( type >= V_101 ) )
return NULL ;
V_2 = F_19 ( sizeof( * V_2 ) , V_102 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_13 = V_13 ;
switch ( type ) {
case V_103 :
case V_104 :
V_2 -> F_2 = F_2 ;
V_2 -> F_12 = F_12 ;
V_2 -> F_6 = F_6 ;
V_2 -> V_43 = V_43 ;
V_2 -> F_11 = F_11 ;
V_2 -> F_14 = F_14 ;
break;
case V_105 :
V_2 -> F_2 = F_15 ;
V_2 -> F_12 = F_12 ;
V_2 -> F_6 = F_6 ;
V_2 -> V_43 = F_16 ;
V_2 -> F_11 = F_11 ;
V_2 -> F_14 = F_14 ;
break;
case V_106 :
break;
default:
F_20 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
