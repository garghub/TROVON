static inline T_1 F_1 ( const T_1 * V_1 , const T_1 * V_2 )
{
return ( V_1 [ 0 ] & V_2 [ 0 ] ) ^
( V_1 [ 1 ] & V_2 [ 1 ] ) ^
( V_1 [ 2 ] & V_2 [ 2 ] ) ^
( V_1 [ 3 ] & V_2 [ 3 ] ) ;
}
static inline T_1
F_2 ( int V_3 , const T_1 * V_1 , const T_1 * V_2 )
{
switch ( V_3 ) {
case V_4 :
return * V_1 & * V_2 ;
case V_5 :
return F_1 ( V_1 , V_2 ) ;
}
return 0 ;
}
static inline void F_3 ( union V_6 * V_7 ,
const struct V_8 * V_9 )
{
union V_6 V_10 ;
T_2 V_11 , V_12 ;
V_10 . V_13 = ( V_7 -> V_13 & V_9 -> V_14 . V_13 ) | V_9 -> V_15 . V_13 ;
V_11 = F_4 ( V_10 . V_16 . V_11 ) ;
V_12 = F_4 ( V_10 . V_16 . V_12 ) ;
if ( V_12 > V_11 )
V_7 -> V_17 = ( V_12 << 16 ) | V_11 ;
else
V_7 -> V_17 = ( V_11 << 16 ) | V_12 ;
}
static int
F_5 ( const struct V_18 * V_19 , struct V_20 * V_21 ,
const struct V_8 * V_9 )
{
#if F_6 ( V_22 )
enum V_23 V_24 ;
struct V_25 * V_26 = F_7 ( V_19 , & V_24 ) ;
struct V_27 * V_28 ;
struct V_27 * V_29 ;
if ( V_26 == NULL || F_8 ( V_26 ) )
return - 1 ;
V_28 = & V_26 -> V_30 [ V_31 ] . V_32 ;
V_29 = & V_26 -> V_30 [ V_33 ] . V_32 ;
V_21 -> V_11 = F_2 ( V_28 -> V_11 . V_3 , V_28 -> V_11 . V_34 . V_35 ,
V_9 -> V_36 . V_35 ) ;
V_21 -> V_12 = F_2 ( V_28 -> V_11 . V_3 , V_29 -> V_11 . V_34 . V_35 ,
V_9 -> V_37 . V_35 ) ;
if ( V_9 -> V_38 & F_9 ( V_39 ) )
return 0 ;
V_21 -> V_40 = F_10 ( V_26 ) ;
if ( V_21 -> V_40 != V_41 ) {
V_21 -> V_7 . V_16 . V_11 = V_28 -> V_11 . V_42 . V_43 ;
V_21 -> V_7 . V_16 . V_12 = V_29 -> V_11 . V_42 . V_43 ;
F_3 ( & V_21 -> V_7 , V_9 ) ;
}
return 0 ;
#else
return - 1 ;
#endif
}
static inline T_3
F_11 ( struct V_20 * V_21 , const struct V_8 * V_9 )
{
T_3 V_44 ;
T_3 V_11 = F_12 ( V_21 -> V_11 ) ;
T_3 V_12 = F_12 ( V_21 -> V_12 ) ;
if ( V_12 < V_11 )
F_13 ( V_11 , V_12 ) ;
V_44 = F_14 ( V_11 , V_12 , V_21 -> V_7 . V_17 , V_9 -> V_45 ) ;
V_44 = V_44 ^ ( V_21 -> V_40 & V_9 -> V_46 ) ;
return ( ( ( V_47 ) V_44 * V_9 -> V_48 ) >> 32 ) + V_9 -> V_49 ;
}
static void
F_15 ( const struct V_18 * V_19 , unsigned int V_50 ,
struct V_20 * V_21 , const struct V_8 * V_9 )
{
int V_51 ;
V_51 = F_16 ( V_21 -> V_40 ) ;
if ( V_51 < 0 )
return;
V_50 += V_51 ;
if ( F_17 ( V_19 , V_50 , & V_21 -> V_7 , sizeof( V_21 -> V_7 ) ) < 0 )
return;
F_3 ( & V_21 -> V_7 , V_9 ) ;
}
static int F_18 ( const struct V_18 * V_19 , int * V_52 )
{
struct V_53 * V_54 , V_55 ;
V_54 = F_19 ( V_19 , * V_52 , sizeof( V_55 ) , & V_55 ) ;
if ( V_54 == NULL )
return 0 ;
if ( V_54 -> V_56 && V_54 -> V_56 < 128 ) {
* V_52 += sizeof( struct V_53 ) ;
return 1 ;
}
return 0 ;
}
static int
F_20 ( const struct V_18 * V_19 , struct V_20 * V_21 ,
const struct V_8 * V_9 )
{
struct V_57 * V_35 , V_58 ;
int V_59 = V_60 ;
unsigned int V_50 = 0 ;
T_2 V_61 = 0 ;
int V_62 ;
V_35 = (struct V_57 * ) ( V_19 -> V_63 + F_21 ( V_19 ) ) ;
V_62 = F_22 ( V_19 , & V_50 , - 1 , & V_61 , & V_59 ) ;
if ( V_62 < 0 )
return 0 ;
if ( ( V_59 & V_64 ) || ( V_62 != V_65 ) )
goto V_66;
if ( F_18 ( V_19 , & V_50 ) ) {
V_35 = F_19 ( V_19 , V_50 , sizeof( V_58 ) , & V_58 ) ;
if ( V_35 == NULL )
return - 1 ;
V_59 = V_60 ;
V_62 = F_22 ( V_19 , & V_50 , - 1 , & V_61 , & V_59 ) ;
if ( V_62 < 0 )
return - 1 ;
}
V_66:
V_21 -> V_11 = F_1 ( V_35 -> V_67 . V_68 , V_9 -> V_36 . V_35 ) ;
V_21 -> V_12 = F_1 ( V_35 -> V_69 . V_68 , V_9 -> V_37 . V_35 ) ;
if ( V_9 -> V_38 & F_9 ( V_39 ) )
return 0 ;
V_21 -> V_40 = V_62 ;
if ( V_21 -> V_40 == V_65 )
return 0 ;
if ( V_59 & V_64 )
return 0 ;
F_15 ( V_19 , V_50 , V_21 , V_9 ) ;
return 0 ;
}
static unsigned int
F_23 ( struct V_18 * V_19 , const struct V_70 * V_71 )
{
const struct V_8 * V_9 = V_71 -> V_72 ;
struct V_20 V_21 ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
if ( V_9 -> V_38 & F_9 ( V_73 ) ) {
if ( F_5 ( V_19 , & V_21 , V_9 ) < 0 )
return V_74 ;
} else {
if ( F_20 ( V_19 , & V_21 , V_9 ) < 0 )
return V_74 ;
}
V_19 -> V_75 = F_11 ( & V_21 , V_9 ) ;
return V_74 ;
}
static int F_24 ( const struct V_18 * V_19 , int V_76 , int * V_50 )
{
const struct V_77 * V_78 ;
struct V_77 V_79 ;
V_78 = F_19 ( V_19 , * V_50 + V_76 , sizeof( V_79 ) , & V_79 ) ;
if ( V_78 == NULL || V_78 -> type > V_80 )
return 0 ;
if ( V_78 -> type != V_81 &&
V_78 -> type != V_82 &&
V_78 -> type != V_83 &&
V_78 -> type != V_84 &&
V_78 -> type != V_85 )
return 0 ;
* V_50 += V_76 + sizeof( V_79 ) ;
return 1 ;
}
static int
F_25 ( const struct V_18 * V_19 , struct V_20 * V_21 ,
const struct V_8 * V_9 )
{
struct V_86 * V_87 , V_88 ;
int V_50 = F_21 ( V_19 ) ;
V_87 = (struct V_86 * ) ( V_19 -> V_63 + V_50 ) ;
if ( V_87 -> V_89 == V_41 ) {
if ( F_24 ( V_19 , V_87 -> V_90 * 4 , & V_50 ) ) {
V_87 = F_19 ( V_19 , V_50 , sizeof( V_88 ) , & V_88 ) ;
if ( V_87 == NULL )
return - 1 ;
}
}
V_21 -> V_11 = V_87 -> V_67 & V_9 -> V_36 . V_87 ;
V_21 -> V_12 = V_87 -> V_69 & V_9 -> V_37 . V_87 ;
if ( V_9 -> V_38 & F_9 ( V_39 ) )
return 0 ;
V_21 -> V_40 = V_87 -> V_89 ;
if ( V_21 -> V_40 == V_41 )
return 0 ;
if ( V_87 -> V_91 & F_26 ( V_92 | V_93 ) )
return 0 ;
F_15 ( V_19 , ( V_87 -> V_90 * 4 ) + V_50 , V_21 , V_9 ) ;
return 0 ;
}
static unsigned int
F_27 ( struct V_18 * V_19 , const struct V_70 * V_71 )
{
const struct V_8 * V_9 = V_71 -> V_72 ;
struct V_20 V_21 ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
if ( V_9 -> V_38 & F_9 ( V_73 ) ) {
if ( F_5 ( V_19 , & V_21 , V_9 ) < 0 )
return V_74 ;
} else {
if ( F_25 ( V_19 , & V_21 , V_9 ) < 0 )
return V_74 ;
}
V_19 -> V_75 = F_11 ( & V_21 , V_9 ) ;
return V_74 ;
}
static int F_28 ( const struct V_94 * V_71 )
{
const struct V_8 * V_9 = V_71 -> V_72 ;
if ( ! V_9 -> V_48 ) {
F_29 ( L_1 ) ;
return - V_95 ;
}
if ( V_9 -> V_46 &&
( V_9 -> V_38 & F_9 ( V_39 ) ) ) {
F_29 ( L_2 ) ;
return - V_95 ;
}
if ( V_9 -> V_38 & F_9 ( V_96 ) &&
( V_9 -> V_38 & ( F_9 ( V_97 ) |
F_9 ( V_98 ) ) ) ) {
F_29 ( L_3 ) ;
return - V_95 ;
}
if ( V_9 -> V_38 & F_9 ( V_99 ) &&
( V_9 -> V_38 & ( F_9 ( V_100 ) |
F_9 ( V_101 ) ) ) ) {
F_29 ( L_4 ) ;
return - V_95 ;
}
return 0 ;
}
static int T_4 F_30 ( void )
{
return F_31 ( V_102 , F_32 ( V_102 ) ) ;
}
static void T_5 F_33 ( void )
{
F_34 ( V_102 , F_32 ( V_102 ) ) ;
}
