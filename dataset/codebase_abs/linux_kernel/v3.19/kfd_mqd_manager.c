inline void F_1 ( unsigned long V_1 )
{
while ( F_2 ( V_2 , V_1 ) )
F_3 () ;
}
static inline struct V_3 * F_4 ( void * V_4 )
{
return (struct V_3 * ) V_4 ;
}
static int F_5 ( struct V_5 * V_6 , void * * V_4 ,
struct V_7 * * V_8 , T_1 * V_9 ,
struct V_10 * V_11 )
{
T_1 V_12 ;
struct V_3 * V_13 ;
int V_14 ;
F_6 ( ! V_6 || ! V_11 || ! V_4 ) ;
F_7 ( L_1 , V_15 ) ;
V_14 = V_16 -> V_17 ( V_6 -> V_18 -> V_19 ,
sizeof( struct V_3 ) ,
256 ,
V_20 ,
(struct V_21 * * ) V_8 ) ;
if ( V_14 != 0 )
return - V_22 ;
V_13 = (struct V_3 * ) ( * V_8 ) -> V_23 ;
V_12 = ( * V_8 ) -> V_24 ;
memset ( V_13 , 0 , F_8 ( sizeof( struct V_3 ) , 256 ) ) ;
V_13 -> V_25 = 0xC0310800 ;
V_13 -> V_26 = 1 ;
V_13 -> V_27 = 0xFFFFFFFF ;
V_13 -> V_28 = 0xFFFFFFFF ;
V_13 -> V_29 = 0xFFFFFFFF ;
V_13 -> V_30 = 0xFFFFFFFF ;
V_13 -> V_31 =
V_32 | V_33 ;
V_13 -> V_34 = V_35 ;
V_13 -> V_36 = F_9 ( V_12 ) ;
V_13 -> V_37 = F_10 ( V_12 ) ;
V_13 -> V_38 = V_39 | V_40 ;
V_13 -> V_38 = V_40 | V_39 ;
V_13 -> V_41 = V_42 | V_43 |
F_11 ( 10 ) ;
V_13 -> V_44 = 1 ;
V_13 -> V_45 = 15 ;
* V_4 = V_13 ;
if ( V_9 != NULL )
* V_9 = V_12 ;
V_14 = V_6 -> V_46 ( V_6 , V_13 , V_11 ) ;
return V_14 ;
}
static void F_12 ( struct V_5 * V_6 , void * V_4 ,
struct V_7 * V_8 )
{
F_6 ( ! V_6 || ! V_4 ) ;
V_16 -> V_47 ( V_6 -> V_18 -> V_19 , (struct V_21 * ) V_8 ) ;
}
static int F_13 ( struct V_5 * V_6 , void * V_4 , T_2 V_48 ,
T_2 V_49 , T_2 T_3 * V_50 )
{
return V_16 -> V_51 ( V_6 -> V_18 -> V_19 , V_4 , V_48 , V_49 , V_50 ) ;
}
static int V_46 ( struct V_5 * V_6 , void * V_4 ,
struct V_10 * V_11 )
{
struct V_3 * V_13 ;
F_6 ( ! V_6 || ! V_11 || ! V_4 ) ;
F_7 ( L_1 , V_15 ) ;
V_13 = F_4 ( V_4 ) ;
V_13 -> V_52 = V_53 |
V_54 | V_55 ;
V_13 -> V_52 |= F_14 ( V_11 -> V_56 / sizeof( unsigned int ) )
- 1 - 1 ;
V_13 -> V_57 = F_9 ( ( T_1 ) V_11 -> V_58 >> 8 ) ;
V_13 -> V_59 = F_10 ( ( T_1 ) V_11 -> V_58 >> 8 ) ;
V_13 -> V_60 = F_9 ( ( T_1 ) V_11 -> V_61 ) ;
V_13 -> V_62 = F_10 ( ( T_1 ) V_11 -> V_61 ) ;
V_13 -> V_63 = V_64 |
F_15 ( V_11 -> V_65 ) ;
V_13 -> V_66 = V_11 -> V_67 ;
if ( V_11 -> V_68 == V_69 ) {
V_13 -> V_70 = V_71 ;
V_13 -> V_52 |= V_72 ;
}
V_13 -> V_73 = 0 ;
V_11 -> V_74 = false ;
if ( V_11 -> V_56 > 0 &&
V_11 -> V_58 != 0 &&
V_11 -> V_75 > 0 ) {
V_13 -> V_73 = 1 ;
V_11 -> V_74 = true ;
}
return 0 ;
}
static int F_16 ( struct V_5 * V_6 , void * V_4 ,
enum V_76 type ,
unsigned int V_77 , T_2 V_48 ,
T_2 V_49 )
{
return V_16 -> V_78 ( V_6 -> V_18 -> V_19 , type , V_77 ,
V_48 , V_49 ) ;
}
static bool F_17 ( struct V_5 * V_6 , void * V_4 ,
T_1 V_58 , T_2 V_48 ,
T_2 V_49 )
{
return V_16 -> V_79 ( V_6 -> V_18 -> V_19 , V_58 ,
V_48 , V_49 ) ;
}
static int F_18 ( struct V_5 * V_6 , void * * V_4 ,
struct V_7 * * V_8 , T_1 * V_9 ,
struct V_10 * V_11 )
{
T_1 V_12 ;
struct V_3 * V_13 ;
int V_14 ;
F_6 ( ! V_6 || ! V_11 || ! V_4 || ! V_8 ) ;
F_7 ( L_1 , V_15 ) ;
V_14 = V_16 -> V_17 ( V_6 -> V_18 -> V_19 ,
sizeof( struct V_3 ) ,
256 ,
V_20 ,
(struct V_21 * * ) V_8 ) ;
if ( V_14 != 0 )
return - V_22 ;
V_13 = (struct V_3 * ) ( * V_8 ) -> V_23 ;
V_12 = ( * V_8 ) -> V_24 ;
memset ( V_13 , 0 , F_8 ( sizeof( struct V_3 ) , 256 ) ) ;
V_13 -> V_25 = 0xC0310800 ;
V_13 -> V_26 = 1 ;
V_13 -> V_27 = 0xFFFFFFFF ;
V_13 -> V_28 = 0xFFFFFFFF ;
V_13 -> V_29 = 0xFFFFFFFF ;
V_13 -> V_30 = 0xFFFFFFFF ;
V_13 -> V_31 = V_32 |
V_33 ;
V_13 -> V_41 = V_42 | V_43 |
F_11 ( 10 ) ;
V_13 -> V_34 = V_35 ;
V_13 -> V_36 = F_9 ( V_12 ) ;
V_13 -> V_37 = F_10 ( V_12 ) ;
V_13 -> V_38 = V_39 ;
V_13 -> V_44 = 1 ;
V_13 -> V_45 = 15 ;
* V_4 = V_13 ;
if ( V_9 )
* V_9 = V_12 ;
V_14 = V_6 -> V_46 ( V_6 , V_13 , V_11 ) ;
return V_14 ;
}
static int F_19 ( struct V_5 * V_6 , void * V_4 ,
struct V_10 * V_11 )
{
struct V_3 * V_13 ;
F_6 ( ! V_6 || ! V_11 || ! V_4 ) ;
F_7 ( L_1 , V_15 ) ;
V_13 = F_4 ( V_4 ) ;
V_13 -> V_52 = V_53 |
V_54 |
V_80 |
V_81 ;
V_13 -> V_52 |= F_14 ( V_11 -> V_56 / sizeof( unsigned int ) )
- 1 - 1 ;
V_13 -> V_57 = F_9 ( ( T_1 ) V_11 -> V_58 >> 8 ) ;
V_13 -> V_59 = F_10 ( ( T_1 ) V_11 -> V_58 >> 8 ) ;
V_13 -> V_60 = F_9 ( ( T_1 ) V_11 -> V_61 ) ;
V_13 -> V_62 = F_10 ( ( T_1 ) V_11 -> V_61 ) ;
V_13 -> V_63 = V_64 |
F_15 ( V_11 -> V_65 ) ;
V_13 -> V_66 = V_11 -> V_67 ;
V_13 -> V_73 = 0 ;
V_11 -> V_74 = false ;
if ( V_11 -> V_56 > 0 &&
V_11 -> V_58 != 0 &&
V_11 -> V_75 > 0 ) {
V_13 -> V_73 = 1 ;
V_11 -> V_74 = true ;
}
return 0 ;
}
struct V_5 * F_20 ( enum V_82 type ,
struct V_83 * V_18 )
{
struct V_5 * V_4 ;
F_6 ( ! V_18 ) ;
F_6 ( type >= V_84 ) ;
F_7 ( L_1 , V_15 ) ;
V_4 = F_21 ( sizeof( struct V_5 ) , V_85 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_18 = V_18 ;
switch ( type ) {
case V_86 :
case V_87 :
V_4 -> F_5 = F_5 ;
V_4 -> F_12 = F_12 ;
V_4 -> F_13 = F_13 ;
V_4 -> V_46 = V_46 ;
V_4 -> F_16 = F_16 ;
V_4 -> F_17 = F_17 ;
break;
case V_88 :
V_4 -> F_5 = F_18 ;
V_4 -> F_12 = F_12 ;
V_4 -> F_13 = F_13 ;
V_4 -> V_46 = F_19 ;
V_4 -> F_16 = F_16 ;
V_4 -> F_17 = F_17 ;
break;
default:
F_22 ( V_4 ) ;
return NULL ;
}
return V_4 ;
}
