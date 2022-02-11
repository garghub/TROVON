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
if ( V_26 == NULL )
return - 1 ;
V_28 = & V_26 -> V_30 [ V_31 ] . V_32 ;
V_29 = & V_26 -> V_30 [ V_33 ] . V_32 ;
V_21 -> V_11 = F_2 ( V_28 -> V_11 . V_3 , V_28 -> V_11 . V_34 . V_35 ,
V_9 -> V_36 . V_35 ) ;
V_21 -> V_12 = F_2 ( V_28 -> V_11 . V_3 , V_29 -> V_11 . V_34 . V_35 ,
V_9 -> V_37 . V_35 ) ;
if ( V_9 -> V_38 & F_8 ( V_39 ) )
return 0 ;
V_21 -> V_40 = F_9 ( V_26 ) ;
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
F_10 ( struct V_20 * V_21 , const struct V_8 * V_9 )
{
T_3 V_44 ;
T_3 V_11 = F_11 ( V_21 -> V_11 ) ;
T_3 V_12 = F_11 ( V_21 -> V_12 ) ;
if ( V_12 < V_11 )
F_12 ( V_11 , V_12 ) ;
V_44 = F_13 ( V_11 , V_12 , V_21 -> V_7 . V_17 , V_9 -> V_45 ) ;
V_44 = V_44 ^ ( V_21 -> V_40 & V_9 -> V_46 ) ;
return F_14 ( V_44 , V_9 -> V_47 ) + V_9 -> V_48 ;
}
static void
F_15 ( const struct V_18 * V_19 , unsigned int V_49 ,
struct V_20 * V_21 , const struct V_8 * V_9 )
{
int V_50 ;
V_50 = F_16 ( V_21 -> V_40 ) ;
if ( V_50 < 0 )
return;
V_49 += V_50 ;
if ( F_17 ( V_19 , V_49 , & V_21 -> V_7 , sizeof( V_21 -> V_7 ) ) < 0 )
return;
F_3 ( & V_21 -> V_7 , V_9 ) ;
}
static int F_18 ( const struct V_18 * V_19 , int * V_51 )
{
struct V_52 * V_53 , V_54 ;
V_53 = F_19 ( V_19 , * V_51 , sizeof( V_54 ) , & V_54 ) ;
if ( V_53 == NULL )
return 0 ;
if ( V_53 -> V_55 && V_53 -> V_55 < 128 ) {
* V_51 += sizeof( struct V_52 ) ;
return 1 ;
}
return 0 ;
}
static int
F_20 ( const struct V_18 * V_19 , struct V_20 * V_21 ,
const struct V_8 * V_9 )
{
struct V_56 * V_35 , V_57 ;
int V_58 = V_59 ;
unsigned int V_49 = 0 ;
T_2 V_60 = 0 ;
int V_61 ;
V_35 = (struct V_56 * ) ( V_19 -> V_62 + F_21 ( V_19 ) ) ;
V_61 = F_22 ( V_19 , & V_49 , - 1 , & V_60 , & V_58 ) ;
if ( V_61 < 0 )
return 0 ;
if ( ( V_58 & V_63 ) || ( V_61 != V_64 ) )
goto V_65;
if ( F_18 ( V_19 , & V_49 ) ) {
V_35 = F_19 ( V_19 , V_49 , sizeof( V_57 ) , & V_57 ) ;
if ( V_35 == NULL )
return - 1 ;
V_58 = V_59 ;
V_61 = F_22 ( V_19 , & V_49 , - 1 , & V_60 , & V_58 ) ;
if ( V_61 < 0 )
return - 1 ;
}
V_65:
V_21 -> V_11 = F_1 ( V_35 -> V_66 . V_67 , V_9 -> V_36 . V_35 ) ;
V_21 -> V_12 = F_1 ( V_35 -> V_68 . V_67 , V_9 -> V_37 . V_35 ) ;
if ( V_9 -> V_38 & F_8 ( V_39 ) )
return 0 ;
V_21 -> V_40 = V_61 ;
if ( V_21 -> V_40 == V_64 )
return 0 ;
if ( V_58 & V_63 )
return 0 ;
F_15 ( V_19 , V_49 , V_21 , V_9 ) ;
return 0 ;
}
static unsigned int
F_23 ( struct V_18 * V_19 , const struct V_69 * V_70 )
{
const struct V_8 * V_9 = V_70 -> V_71 ;
struct V_20 V_21 ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
if ( V_9 -> V_38 & F_8 ( V_72 ) ) {
if ( F_5 ( V_19 , & V_21 , V_9 ) < 0 )
return V_73 ;
} else {
if ( F_20 ( V_19 , & V_21 , V_9 ) < 0 )
return V_73 ;
}
V_19 -> V_74 = F_10 ( & V_21 , V_9 ) ;
return V_73 ;
}
static int F_24 ( const struct V_18 * V_19 , int V_75 , int * V_49 )
{
const struct V_76 * V_77 ;
struct V_76 V_78 ;
V_77 = F_19 ( V_19 , * V_49 + V_75 , sizeof( V_78 ) , & V_78 ) ;
if ( V_77 == NULL || V_77 -> type > V_79 )
return 0 ;
if ( V_77 -> type != V_80 &&
V_77 -> type != V_81 &&
V_77 -> type != V_82 &&
V_77 -> type != V_83 &&
V_77 -> type != V_84 )
return 0 ;
* V_49 += V_75 + sizeof( V_78 ) ;
return 1 ;
}
static int
F_25 ( const struct V_18 * V_19 , struct V_20 * V_21 ,
const struct V_8 * V_9 )
{
struct V_85 * V_86 , V_87 ;
int V_49 = F_21 ( V_19 ) ;
V_86 = (struct V_85 * ) ( V_19 -> V_62 + V_49 ) ;
if ( V_86 -> V_88 == V_41 ) {
if ( F_24 ( V_19 , V_86 -> V_89 * 4 , & V_49 ) ) {
V_86 = F_19 ( V_19 , V_49 , sizeof( V_87 ) , & V_87 ) ;
if ( V_86 == NULL )
return - 1 ;
}
}
V_21 -> V_11 = V_86 -> V_66 & V_9 -> V_36 . V_86 ;
V_21 -> V_12 = V_86 -> V_68 & V_9 -> V_37 . V_86 ;
if ( V_9 -> V_38 & F_8 ( V_39 ) )
return 0 ;
V_21 -> V_40 = V_86 -> V_88 ;
if ( V_21 -> V_40 == V_41 )
return 0 ;
if ( V_86 -> V_90 & F_26 ( V_91 | V_92 ) )
return 0 ;
F_15 ( V_19 , ( V_86 -> V_89 * 4 ) + V_49 , V_21 , V_9 ) ;
return 0 ;
}
static unsigned int
F_27 ( struct V_18 * V_19 , const struct V_69 * V_70 )
{
const struct V_8 * V_9 = V_70 -> V_71 ;
struct V_20 V_21 ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
if ( V_9 -> V_38 & F_8 ( V_72 ) ) {
if ( F_5 ( V_19 , & V_21 , V_9 ) < 0 )
return V_73 ;
} else {
if ( F_25 ( V_19 , & V_21 , V_9 ) < 0 )
return V_73 ;
}
V_19 -> V_74 = F_10 ( & V_21 , V_9 ) ;
return V_73 ;
}
static int F_28 ( const struct V_93 * V_70 )
{
const struct V_8 * V_9 = V_70 -> V_71 ;
if ( ! V_9 -> V_47 ) {
F_29 ( L_1 ) ;
return - V_94 ;
}
if ( V_9 -> V_46 &&
( V_9 -> V_38 & F_8 ( V_39 ) ) ) {
F_29 ( L_2 ) ;
return - V_94 ;
}
if ( V_9 -> V_38 & F_8 ( V_95 ) &&
( V_9 -> V_38 & ( F_8 ( V_96 ) |
F_8 ( V_97 ) ) ) ) {
F_29 ( L_3 ) ;
return - V_94 ;
}
if ( V_9 -> V_38 & F_8 ( V_98 ) &&
( V_9 -> V_38 & ( F_8 ( V_99 ) |
F_8 ( V_100 ) ) ) ) {
F_29 ( L_4 ) ;
return - V_94 ;
}
return 0 ;
}
static int T_4 F_30 ( void )
{
return F_31 ( V_101 , F_32 ( V_101 ) ) ;
}
static void T_5 F_33 ( void )
{
F_34 ( V_101 , F_32 ( V_101 ) ) ;
}
