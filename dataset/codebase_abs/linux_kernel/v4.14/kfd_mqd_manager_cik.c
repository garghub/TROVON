static inline struct V_1 * F_1 ( void * V_2 )
{
return (struct V_1 * ) V_2 ;
}
static int F_2 ( struct V_3 * V_4 , void * * V_2 ,
struct V_5 * * V_6 , T_1 * V_7 ,
struct V_8 * V_9 )
{
T_1 V_10 ;
struct V_1 * V_11 ;
int V_12 ;
V_12 = F_3 ( V_4 -> V_13 , sizeof( struct V_1 ) ,
V_6 ) ;
if ( V_12 != 0 )
return - V_14 ;
V_11 = (struct V_1 * ) ( * V_6 ) -> V_15 ;
V_10 = ( * V_6 ) -> V_16 ;
memset ( V_11 , 0 , F_4 ( sizeof( struct V_1 ) , 256 ) ) ;
V_11 -> V_17 = 0xC0310800 ;
V_11 -> V_18 = 1 ;
V_11 -> V_19 = 0xFFFFFFFF ;
V_11 -> V_20 = 0xFFFFFFFF ;
V_11 -> V_21 = 0xFFFFFFFF ;
V_11 -> V_22 = 0xFFFFFFFF ;
V_11 -> V_23 =
V_24 | V_25 ;
V_11 -> V_26 = V_27 ;
V_11 -> V_28 = F_5 ( V_10 ) ;
V_11 -> V_29 = F_6 ( V_10 ) ;
V_11 -> V_30 = V_31 | V_32 ;
V_11 -> V_30 = V_32 | V_31 ;
V_11 -> V_33 = V_34 | V_35 |
F_7 ( 10 ) ;
V_11 -> V_36 = 1 ;
V_11 -> V_37 = 15 ;
if ( V_9 -> V_38 == V_39 )
V_11 -> V_40 = V_41 ;
* V_2 = V_11 ;
if ( V_7 )
* V_7 = V_10 ;
V_12 = V_4 -> V_42 ( V_4 , V_11 , V_9 ) ;
return V_12 ;
}
static int F_8 ( struct V_3 * V_4 , void * * V_2 ,
struct V_5 * * V_6 , T_1 * V_7 ,
struct V_8 * V_9 )
{
int V_12 ;
struct V_43 * V_11 ;
V_12 = F_3 ( V_4 -> V_13 ,
sizeof( struct V_43 ) ,
V_6 ) ;
if ( V_12 != 0 )
return - V_14 ;
V_11 = (struct V_43 * ) ( * V_6 ) -> V_15 ;
memset ( V_11 , 0 , sizeof( struct V_43 ) ) ;
* V_2 = V_11 ;
if ( V_7 )
* V_7 = ( * V_6 ) -> V_16 ;
V_12 = V_4 -> V_42 ( V_4 , V_11 , V_9 ) ;
return V_12 ;
}
static void F_9 ( struct V_3 * V_4 , void * V_2 ,
struct V_5 * V_6 )
{
F_10 ( V_4 -> V_13 , V_6 ) ;
}
static void F_11 ( struct V_3 * V_4 , void * V_2 ,
struct V_5 * V_6 )
{
F_10 ( V_4 -> V_13 , V_6 ) ;
}
static int F_12 ( struct V_3 * V_4 , void * V_2 , T_2 V_44 ,
T_2 V_45 , struct V_8 * V_46 ,
struct V_47 * V_48 )
{
T_2 V_49 = ( V_46 -> V_38 == V_39 ? 4 : 0 ) ;
T_2 V_50 = ( T_2 ) ( ( V_46 -> V_51 / sizeof( T_2 ) ) - 1 ) ;
return V_4 -> V_13 -> V_52 -> V_53 ( V_4 -> V_13 -> V_54 , V_2 , V_44 , V_45 ,
( T_2 V_55 * ) V_46 -> V_56 ,
V_49 , V_50 , V_48 ) ;
}
static int F_13 ( struct V_3 * V_4 , void * V_2 ,
T_2 V_44 , T_2 V_45 ,
struct V_8 * V_46 , struct V_47 * V_48 )
{
return V_4 -> V_13 -> V_52 -> V_57 ( V_4 -> V_13 -> V_54 , V_2 ) ;
}
static int V_42 ( struct V_3 * V_4 , void * V_2 ,
struct V_8 * V_9 )
{
struct V_1 * V_11 ;
V_11 = F_1 ( V_2 ) ;
V_11 -> V_58 = V_59 |
V_60 | V_61 ;
V_11 -> V_58 |= F_14 ( V_9 -> V_51 / sizeof( unsigned int ) )
- 1 - 1 ;
V_11 -> V_62 = F_5 ( ( T_1 ) V_9 -> V_63 >> 8 ) ;
V_11 -> V_64 = F_6 ( ( T_1 ) V_9 -> V_63 >> 8 ) ;
V_11 -> V_65 = F_5 ( ( T_1 ) V_9 -> V_66 ) ;
V_11 -> V_67 = F_6 ( ( T_1 ) V_9 -> V_66 ) ;
V_11 -> V_68 = F_15 ( V_9 -> V_69 ) ;
V_11 -> V_70 = V_9 -> V_71 ;
if ( V_9 -> V_38 == V_39 )
V_11 -> V_58 |= V_72 ;
V_9 -> V_73 = false ;
if ( V_9 -> V_51 > 0 &&
V_9 -> V_63 != 0 &&
V_9 -> V_74 > 0 ) {
V_9 -> V_73 = true ;
}
return 0 ;
}
static int F_16 ( struct V_3 * V_4 , void * V_2 ,
struct V_8 * V_9 )
{
struct V_43 * V_11 ;
V_11 = F_17 ( V_2 ) ;
V_11 -> V_75 = F_14 ( V_9 -> V_51 / sizeof( unsigned int ) ) <<
V_76 |
V_9 -> V_71 << V_77 |
1 << V_78 |
6 << V_79 ;
V_11 -> V_80 = F_5 ( V_9 -> V_63 >> 8 ) ;
V_11 -> V_81 = F_6 ( V_9 -> V_63 >> 8 ) ;
V_11 -> V_82 = F_5 ( ( T_1 ) V_9 -> V_66 ) ;
V_11 -> V_83 = F_6 ( ( T_1 ) V_9 -> V_66 ) ;
V_11 -> V_84 = V_9 -> V_69 <<
V_85 |
1 << V_86 ;
V_11 -> V_87 = V_9 -> V_88 ;
V_11 -> V_89 = V_9 -> V_89 ;
V_11 -> V_90 = V_9 -> V_90 ;
V_9 -> V_73 = false ;
if ( V_9 -> V_51 > 0 &&
V_9 -> V_63 != 0 &&
V_9 -> V_74 > 0 ) {
V_11 -> V_75 |=
1 << V_91 ;
V_9 -> V_73 = true ;
}
return 0 ;
}
static int F_18 ( struct V_3 * V_4 , void * V_2 ,
enum V_92 type ,
unsigned int V_93 , T_2 V_44 ,
T_2 V_45 )
{
return V_4 -> V_13 -> V_52 -> V_94 ( V_4 -> V_13 -> V_54 , V_2 , type , V_93 ,
V_44 , V_45 ) ;
}
static int F_19 ( struct V_3 * V_4 , void * V_2 ,
enum V_92 type ,
unsigned int V_93 , T_2 V_44 ,
T_2 V_45 )
{
return V_4 -> V_13 -> V_52 -> V_95 ( V_4 -> V_13 -> V_54 , V_2 , V_93 ) ;
}
static bool F_20 ( struct V_3 * V_4 , void * V_2 ,
T_1 V_63 , T_2 V_44 ,
T_2 V_45 )
{
return V_4 -> V_13 -> V_52 -> V_96 ( V_4 -> V_13 -> V_54 , V_63 ,
V_44 , V_45 ) ;
}
static bool F_21 ( struct V_3 * V_4 , void * V_2 ,
T_1 V_63 , T_2 V_44 ,
T_2 V_45 )
{
return V_4 -> V_13 -> V_52 -> V_97 ( V_4 -> V_13 -> V_54 , V_2 ) ;
}
static int F_22 ( struct V_3 * V_4 , void * * V_2 ,
struct V_5 * * V_6 , T_1 * V_7 ,
struct V_8 * V_9 )
{
T_1 V_10 ;
struct V_1 * V_11 ;
int V_12 ;
V_12 = F_3 ( V_4 -> V_13 , sizeof( struct V_1 ) ,
V_6 ) ;
if ( V_12 != 0 )
return - V_14 ;
V_11 = (struct V_1 * ) ( * V_6 ) -> V_15 ;
V_10 = ( * V_6 ) -> V_16 ;
memset ( V_11 , 0 , F_4 ( sizeof( struct V_1 ) , 256 ) ) ;
V_11 -> V_17 = 0xC0310800 ;
V_11 -> V_18 = 1 ;
V_11 -> V_19 = 0xFFFFFFFF ;
V_11 -> V_20 = 0xFFFFFFFF ;
V_11 -> V_21 = 0xFFFFFFFF ;
V_11 -> V_22 = 0xFFFFFFFF ;
V_11 -> V_23 = V_24 |
V_25 ;
V_11 -> V_33 = V_34 | V_35 |
F_7 ( 10 ) ;
V_11 -> V_26 = V_27 ;
V_11 -> V_28 = F_5 ( V_10 ) ;
V_11 -> V_29 = F_6 ( V_10 ) ;
V_11 -> V_30 = V_31 ;
V_11 -> V_36 = 1 ;
V_11 -> V_37 = 15 ;
* V_2 = V_11 ;
if ( V_7 )
* V_7 = V_10 ;
V_12 = V_4 -> V_42 ( V_4 , V_11 , V_9 ) ;
return V_12 ;
}
static int F_23 ( struct V_3 * V_4 , void * V_2 ,
struct V_8 * V_9 )
{
struct V_1 * V_11 ;
V_11 = F_1 ( V_2 ) ;
V_11 -> V_58 = V_59 |
V_60 |
V_98 |
V_99 ;
V_11 -> V_58 |= F_14 ( V_9 -> V_51 / sizeof( unsigned int ) )
- 1 - 1 ;
V_11 -> V_62 = F_5 ( ( T_1 ) V_9 -> V_63 >> 8 ) ;
V_11 -> V_64 = F_6 ( ( T_1 ) V_9 -> V_63 >> 8 ) ;
V_11 -> V_65 = F_5 ( ( T_1 ) V_9 -> V_66 ) ;
V_11 -> V_67 = F_6 ( ( T_1 ) V_9 -> V_66 ) ;
V_11 -> V_68 = V_100 |
F_15 ( V_9 -> V_69 ) ;
V_11 -> V_70 = V_9 -> V_71 ;
V_11 -> V_101 = 0 ;
V_9 -> V_73 = false ;
if ( V_9 -> V_51 > 0 &&
V_9 -> V_63 != 0 &&
V_9 -> V_74 > 0 ) {
V_11 -> V_101 = 1 ;
V_9 -> V_73 = true ;
}
return 0 ;
}
struct V_43 * F_17 ( void * V_2 )
{
struct V_43 * V_11 ;
V_11 = (struct V_43 * ) V_2 ;
return V_11 ;
}
struct V_3 * F_24 ( enum V_102 type ,
struct V_103 * V_13 )
{
struct V_3 * V_2 ;
if ( F_25 ( type >= V_104 ) )
return NULL ;
V_2 = F_26 ( sizeof( * V_2 ) , V_105 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_13 = V_13 ;
switch ( type ) {
case V_106 :
case V_107 :
V_2 -> F_2 = F_2 ;
V_2 -> F_9 = F_9 ;
V_2 -> F_12 = F_12 ;
V_2 -> V_42 = V_42 ;
V_2 -> F_18 = F_18 ;
V_2 -> F_20 = F_20 ;
break;
case V_108 :
V_2 -> F_2 = F_22 ;
V_2 -> F_9 = F_9 ;
V_2 -> F_12 = F_12 ;
V_2 -> V_42 = F_23 ;
V_2 -> F_18 = F_18 ;
V_2 -> F_20 = F_20 ;
break;
case V_109 :
V_2 -> F_2 = F_8 ;
V_2 -> F_9 = F_11 ;
V_2 -> F_12 = F_13 ;
V_2 -> V_42 = F_16 ;
V_2 -> F_18 = F_19 ;
V_2 -> F_20 = F_21 ;
break;
default:
F_27 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
