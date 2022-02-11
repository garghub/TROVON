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
F_3 ( ! V_4 || ! V_9 || ! V_2 ) ;
F_4 ( L_1 , V_13 ) ;
V_12 = F_5 ( V_4 -> V_14 , sizeof( struct V_1 ) ,
V_6 ) ;
if ( V_12 != 0 )
return - V_15 ;
V_11 = (struct V_1 * ) ( * V_6 ) -> V_16 ;
V_10 = ( * V_6 ) -> V_17 ;
memset ( V_11 , 0 , F_6 ( sizeof( struct V_1 ) , 256 ) ) ;
V_11 -> V_18 = 0xC0310800 ;
V_11 -> V_19 = 1 ;
V_11 -> V_20 = 0xFFFFFFFF ;
V_11 -> V_21 = 0xFFFFFFFF ;
V_11 -> V_22 = 0xFFFFFFFF ;
V_11 -> V_23 = 0xFFFFFFFF ;
V_11 -> V_24 =
V_25 | V_26 ;
V_11 -> V_27 = V_28 ;
V_11 -> V_29 = F_7 ( V_10 ) ;
V_11 -> V_30 = F_8 ( V_10 ) ;
V_11 -> V_31 = V_32 | V_33 ;
V_11 -> V_31 = V_33 | V_32 ;
V_11 -> V_34 = V_35 | V_36 |
F_9 ( 10 ) ;
V_11 -> V_37 = 1 ;
V_11 -> V_38 = 15 ;
if ( V_9 -> V_39 == V_40 )
V_11 -> V_41 = V_42 ;
* V_2 = V_11 ;
if ( V_7 != NULL )
* V_7 = V_10 ;
V_12 = V_4 -> V_43 ( V_4 , V_11 , V_9 ) ;
return V_12 ;
}
static int F_10 ( struct V_3 * V_4 , void * * V_2 ,
struct V_5 * * V_6 , T_1 * V_7 ,
struct V_8 * V_9 )
{
int V_12 ;
struct V_44 * V_11 ;
F_3 ( ! V_4 || ! V_2 || ! V_6 ) ;
V_12 = F_5 ( V_4 -> V_14 ,
sizeof( struct V_44 ) ,
V_6 ) ;
if ( V_12 != 0 )
return - V_15 ;
V_11 = (struct V_44 * ) ( * V_6 ) -> V_16 ;
memset ( V_11 , 0 , sizeof( struct V_44 ) ) ;
* V_2 = V_11 ;
if ( V_7 != NULL )
* V_7 = ( * V_6 ) -> V_17 ;
V_12 = V_4 -> V_43 ( V_4 , V_11 , V_9 ) ;
return V_12 ;
}
static void F_11 ( struct V_3 * V_4 , void * V_2 ,
struct V_5 * V_6 )
{
F_3 ( ! V_4 || ! V_2 ) ;
F_12 ( V_4 -> V_14 , V_6 ) ;
}
static void F_13 ( struct V_3 * V_4 , void * V_2 ,
struct V_5 * V_6 )
{
F_3 ( ! V_4 || ! V_2 ) ;
F_12 ( V_4 -> V_14 , V_6 ) ;
}
static int F_14 ( struct V_3 * V_4 , void * V_2 , T_2 V_45 ,
T_2 V_46 , T_2 T_3 * V_47 )
{
return V_4 -> V_14 -> V_48 -> V_49
( V_4 -> V_14 -> V_50 , V_2 , V_45 , V_46 , V_47 ) ;
}
static int F_15 ( struct V_3 * V_4 , void * V_2 ,
T_2 V_45 , T_2 V_46 ,
T_2 T_3 * V_47 )
{
return V_4 -> V_14 -> V_48 -> V_51 ( V_4 -> V_14 -> V_50 , V_2 ) ;
}
static int V_43 ( struct V_3 * V_4 , void * V_2 ,
struct V_8 * V_9 )
{
struct V_1 * V_11 ;
F_3 ( ! V_4 || ! V_9 || ! V_2 ) ;
F_4 ( L_1 , V_13 ) ;
V_11 = F_1 ( V_2 ) ;
V_11 -> V_52 = V_53 |
V_54 | V_55 ;
V_11 -> V_52 |= F_16 ( V_9 -> V_56 / sizeof( unsigned int ) )
- 1 - 1 ;
V_11 -> V_57 = F_7 ( ( T_1 ) V_9 -> V_58 >> 8 ) ;
V_11 -> V_59 = F_8 ( ( T_1 ) V_9 -> V_58 >> 8 ) ;
V_11 -> V_60 = F_7 ( ( T_1 ) V_9 -> V_61 ) ;
V_11 -> V_62 = F_8 ( ( T_1 ) V_9 -> V_61 ) ;
V_11 -> V_63 = V_64 |
F_17 ( V_9 -> V_65 ) ;
V_11 -> V_66 = V_9 -> V_67 ;
if ( V_9 -> V_39 == V_40 ) {
V_11 -> V_52 |= V_68 ;
}
V_11 -> V_69 = 0 ;
V_9 -> V_70 = false ;
if ( V_9 -> V_56 > 0 &&
V_9 -> V_58 != 0 &&
V_9 -> V_71 > 0 ) {
V_11 -> V_69 = 1 ;
V_9 -> V_70 = true ;
}
return 0 ;
}
static int F_18 ( struct V_3 * V_4 , void * V_2 ,
struct V_8 * V_9 )
{
struct V_44 * V_11 ;
F_3 ( ! V_4 || ! V_2 || ! V_9 ) ;
V_11 = F_19 ( V_2 ) ;
V_11 -> V_72 =
F_20 ( ( F_16 ( V_9 -> V_56 / sizeof( unsigned int ) ) ) ) |
F_21 ( V_9 -> V_67 ) |
V_73 |
F_22 ( 6 ) ;
V_11 -> V_74 = F_7 ( V_9 -> V_58 >> 8 ) ;
V_11 -> V_75 = F_8 ( V_9 -> V_58 >> 8 ) ;
V_11 -> V_76 = F_7 ( ( T_1 ) V_9 -> V_61 ) ;
V_11 -> V_77 = F_8 ( ( T_1 ) V_9 -> V_61 ) ;
V_11 -> V_78 = F_23 ( V_9 -> V_65 ) | V_79 ;
V_11 -> V_80 = V_9 -> V_81 ;
V_11 -> V_82 = V_9 -> V_82 ;
V_11 -> V_83 = V_9 -> V_83 ;
V_9 -> V_70 = false ;
if ( V_9 -> V_56 > 0 &&
V_9 -> V_58 != 0 &&
V_9 -> V_71 > 0 ) {
V_11 -> V_72 |= V_84 ;
V_9 -> V_70 = true ;
}
return 0 ;
}
static int F_24 ( struct V_3 * V_4 , void * V_2 ,
enum V_85 type ,
unsigned int V_86 , T_2 V_45 ,
T_2 V_46 )
{
return V_4 -> V_14 -> V_48 -> V_87 ( V_4 -> V_14 -> V_50 , type , V_86 ,
V_45 , V_46 ) ;
}
static int F_25 ( struct V_3 * V_4 , void * V_2 ,
enum V_85 type ,
unsigned int V_86 , T_2 V_45 ,
T_2 V_46 )
{
return V_4 -> V_14 -> V_48 -> V_88 ( V_4 -> V_14 -> V_50 , V_2 , V_86 ) ;
}
static bool F_26 ( struct V_3 * V_4 , void * V_2 ,
T_1 V_58 , T_2 V_45 ,
T_2 V_46 )
{
return V_4 -> V_14 -> V_48 -> V_89 ( V_4 -> V_14 -> V_50 , V_58 ,
V_45 , V_46 ) ;
}
static bool F_27 ( struct V_3 * V_4 , void * V_2 ,
T_1 V_58 , T_2 V_45 ,
T_2 V_46 )
{
return V_4 -> V_14 -> V_48 -> V_90 ( V_4 -> V_14 -> V_50 , V_2 ) ;
}
static int F_28 ( struct V_3 * V_4 , void * * V_2 ,
struct V_5 * * V_6 , T_1 * V_7 ,
struct V_8 * V_9 )
{
T_1 V_10 ;
struct V_1 * V_11 ;
int V_12 ;
F_3 ( ! V_4 || ! V_9 || ! V_2 || ! V_6 ) ;
F_4 ( L_1 , V_13 ) ;
V_12 = F_5 ( V_4 -> V_14 , sizeof( struct V_1 ) ,
V_6 ) ;
if ( V_12 != 0 )
return - V_15 ;
V_11 = (struct V_1 * ) ( * V_6 ) -> V_16 ;
V_10 = ( * V_6 ) -> V_17 ;
memset ( V_11 , 0 , F_6 ( sizeof( struct V_1 ) , 256 ) ) ;
V_11 -> V_18 = 0xC0310800 ;
V_11 -> V_19 = 1 ;
V_11 -> V_20 = 0xFFFFFFFF ;
V_11 -> V_21 = 0xFFFFFFFF ;
V_11 -> V_22 = 0xFFFFFFFF ;
V_11 -> V_23 = 0xFFFFFFFF ;
V_11 -> V_24 = V_25 |
V_26 ;
V_11 -> V_34 = V_35 | V_36 |
F_9 ( 10 ) ;
V_11 -> V_27 = V_28 ;
V_11 -> V_29 = F_7 ( V_10 ) ;
V_11 -> V_30 = F_8 ( V_10 ) ;
V_11 -> V_31 = V_32 ;
V_11 -> V_37 = 1 ;
V_11 -> V_38 = 15 ;
* V_2 = V_11 ;
if ( V_7 )
* V_7 = V_10 ;
V_12 = V_4 -> V_43 ( V_4 , V_11 , V_9 ) ;
return V_12 ;
}
static int F_29 ( struct V_3 * V_4 , void * V_2 ,
struct V_8 * V_9 )
{
struct V_1 * V_11 ;
F_3 ( ! V_4 || ! V_9 || ! V_2 ) ;
F_4 ( L_1 , V_13 ) ;
V_11 = F_1 ( V_2 ) ;
V_11 -> V_52 = V_53 |
V_54 |
V_91 |
V_92 ;
V_11 -> V_52 |= F_16 ( V_9 -> V_56 / sizeof( unsigned int ) )
- 1 - 1 ;
V_11 -> V_57 = F_7 ( ( T_1 ) V_9 -> V_58 >> 8 ) ;
V_11 -> V_59 = F_8 ( ( T_1 ) V_9 -> V_58 >> 8 ) ;
V_11 -> V_60 = F_7 ( ( T_1 ) V_9 -> V_61 ) ;
V_11 -> V_62 = F_8 ( ( T_1 ) V_9 -> V_61 ) ;
V_11 -> V_63 = V_64 |
F_17 ( V_9 -> V_65 ) ;
V_11 -> V_66 = V_9 -> V_67 ;
V_11 -> V_69 = 0 ;
V_9 -> V_70 = false ;
if ( V_9 -> V_56 > 0 &&
V_9 -> V_58 != 0 &&
V_9 -> V_71 > 0 ) {
V_11 -> V_69 = 1 ;
V_9 -> V_70 = true ;
}
return 0 ;
}
struct V_44 * F_19 ( void * V_2 )
{
struct V_44 * V_11 ;
F_3 ( ! V_2 ) ;
V_11 = (struct V_44 * ) V_2 ;
return V_11 ;
}
struct V_3 * F_30 ( enum V_93 type ,
struct V_94 * V_14 )
{
struct V_3 * V_2 ;
F_3 ( ! V_14 ) ;
F_3 ( type >= V_95 ) ;
F_4 ( L_1 , V_13 ) ;
V_2 = F_31 ( sizeof( struct V_3 ) , V_96 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_14 = V_14 ;
switch ( type ) {
case V_97 :
case V_98 :
V_2 -> F_2 = F_2 ;
V_2 -> F_11 = F_11 ;
V_2 -> F_14 = F_14 ;
V_2 -> V_43 = V_43 ;
V_2 -> F_24 = F_24 ;
V_2 -> F_26 = F_26 ;
break;
case V_99 :
V_2 -> F_2 = F_28 ;
V_2 -> F_11 = F_11 ;
V_2 -> F_14 = F_14 ;
V_2 -> V_43 = F_29 ;
V_2 -> F_24 = F_24 ;
V_2 -> F_26 = F_26 ;
break;
case V_100 :
V_2 -> F_2 = F_10 ;
V_2 -> F_11 = F_13 ;
V_2 -> F_14 = F_15 ;
V_2 -> V_43 = F_18 ;
V_2 -> F_24 = F_25 ;
V_2 -> F_26 = F_27 ;
break;
default:
F_32 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
