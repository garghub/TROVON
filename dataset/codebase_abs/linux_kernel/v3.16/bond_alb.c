static inline struct V_1 * V_1 ( const struct V_2 * V_3 )
{
return (struct V_1 * ) F_1 ( V_3 ) ;
}
static inline T_1 F_2 ( const T_1 * V_4 , int V_5 )
{
int V_6 ;
T_1 V_7 = 0 ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ )
V_7 ^= V_4 [ V_6 ] ;
return V_7 ;
}
static inline void F_3 ( struct V_8 * V_9 )
{
F_4 ( & ( F_5 ( V_9 ) . V_10 ) ) ;
}
static inline void F_6 ( struct V_8 * V_9 )
{
F_7 ( & ( F_5 ( V_9 ) . V_10 ) ) ;
}
static inline void F_8 ( struct V_8 * V_9 )
{
F_9 ( & ( F_5 ( V_9 ) . V_10 ) ) ;
}
static inline void F_10 ( struct V_8 * V_9 )
{
F_11 ( & ( F_5 ( V_9 ) . V_10 ) ) ;
}
static inline void F_12 ( struct V_11 * V_12 , int V_13 )
{
if ( V_13 ) {
V_12 -> V_14 = 1 + V_12 -> V_15 /
V_16 ;
V_12 -> V_15 = 0 ;
}
V_12 -> V_17 = NULL ;
V_12 -> V_18 = V_19 ;
V_12 -> V_20 = V_19 ;
}
static inline void F_13 ( struct V_21 * V_21 )
{
F_14 ( V_21 ) . V_22 = 0 ;
F_14 ( V_21 ) . V_23 = V_19 ;
}
static void F_15 ( struct V_8 * V_9 , struct V_21 * V_21 ,
int V_13 )
{
struct V_11 * V_24 ;
T_2 V_25 ;
V_24 = F_5 ( V_9 ) . V_26 ;
if ( V_24 ) {
V_25 = F_14 ( V_21 ) . V_23 ;
while ( V_25 != V_19 ) {
T_2 V_27 = V_24 [ V_25 ] . V_18 ;
F_12 ( & V_24 [ V_25 ] , V_13 ) ;
V_25 = V_27 ;
}
}
F_13 ( V_21 ) ;
}
static void F_16 ( struct V_8 * V_9 , struct V_21 * V_21 ,
int V_13 )
{
F_3 ( V_9 ) ;
F_15 ( V_9 , V_21 , V_13 ) ;
F_6 ( V_9 ) ;
}
static int F_17 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
int V_30 = V_31 * sizeof( struct V_11 ) ;
struct V_11 * V_32 ;
int V_6 ;
V_32 = F_18 ( V_30 , V_33 ) ;
if ( ! V_32 )
return - 1 ;
F_3 ( V_9 ) ;
V_29 -> V_26 = V_32 ;
for ( V_6 = 0 ; V_6 < V_31 ; V_6 ++ )
F_12 ( & V_29 -> V_26 [ V_6 ] , 0 ) ;
F_6 ( V_9 ) ;
return 0 ;
}
static void F_19 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
F_3 ( V_9 ) ;
F_20 ( V_29 -> V_26 ) ;
V_29 -> V_26 = NULL ;
F_6 ( V_9 ) ;
}
static long long F_21 ( struct V_21 * V_21 )
{
return ( V_34 ) ( V_21 -> V_35 << 20 ) -
( V_34 ) ( F_14 ( V_21 ) . V_22 << 3 ) ;
}
static struct V_21 * F_22 ( struct V_8 * V_9 )
{
struct V_21 * V_21 , * V_36 ;
struct V_37 * V_38 ;
long long V_39 ;
V_36 = NULL ;
V_39 = V_40 ;
F_23 (bond, slave, iter) {
if ( F_24 ( V_21 ) ) {
long long V_41 = F_21 ( V_21 ) ;
if ( V_39 < V_41 ) {
V_36 = V_21 ;
V_39 = V_41 ;
}
}
}
return V_36 ;
}
static struct V_21 * F_25 ( struct V_8 * V_9 , T_2 V_42 ,
T_2 V_43 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_11 * V_44 ;
struct V_21 * V_45 ;
V_44 = V_29 -> V_26 ;
V_45 = V_44 [ V_42 ] . V_17 ;
if ( ! V_45 ) {
V_45 = F_22 ( V_9 ) ;
if ( V_45 ) {
struct V_46 * V_47 =
& ( F_14 ( V_45 ) ) ;
T_2 V_27 = V_47 -> V_23 ;
V_44 [ V_42 ] . V_17 = V_45 ;
V_44 [ V_42 ] . V_18 = V_27 ;
V_44 [ V_42 ] . V_20 = V_19 ;
if ( V_27 != V_19 )
V_44 [ V_27 ] . V_20 = V_42 ;
V_47 -> V_23 = V_42 ;
V_47 -> V_22 +=
V_44 [ V_42 ] . V_14 ;
}
}
if ( V_45 )
V_44 [ V_42 ] . V_15 += V_43 ;
return V_45 ;
}
static struct V_21 * F_26 ( struct V_8 * V_9 , T_2 V_42 ,
T_2 V_43 )
{
struct V_21 * V_17 ;
F_8 ( V_9 ) ;
V_17 = F_25 ( V_9 , V_42 , V_43 ) ;
F_10 ( V_9 ) ;
return V_17 ;
}
static inline void F_27 ( struct V_8 * V_9 )
{
F_4 ( & ( F_5 ( V_9 ) . V_48 ) ) ;
}
static inline void F_28 ( struct V_8 * V_9 )
{
F_7 ( & ( F_5 ( V_9 ) . V_48 ) ) ;
}
static inline void F_29 ( struct V_8 * V_9 )
{
F_9 ( & ( F_5 ( V_9 ) . V_48 ) ) ;
}
static inline void F_30 ( struct V_8 * V_9 )
{
F_11 ( & ( F_5 ( V_9 ) . V_48 ) ) ;
}
static void F_31 ( struct V_8 * V_9 , struct V_1 * V_49 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_50 * V_51 ;
T_2 V_42 ;
F_27 ( V_9 ) ;
V_42 = F_2 ( ( T_1 * ) & ( V_49 -> V_52 ) , sizeof( V_49 -> V_52 ) ) ;
V_51 = & ( V_29 -> V_53 [ V_42 ] ) ;
if ( ( V_51 -> V_54 ) &&
( V_51 -> V_52 == V_49 -> V_55 ) &&
( V_51 -> V_55 == V_49 -> V_52 ) &&
( ! F_32 ( V_51 -> V_56 , V_49 -> V_57 ) ) ) {
F_33 ( V_51 -> V_56 , V_49 -> V_57 ) ;
V_51 -> V_58 = 1 ;
V_29 -> V_59 = 1 ;
}
F_28 ( V_9 ) ;
}
static int F_34 ( const struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_21 * V_21 )
{
struct V_1 * V_49 , V_60 ;
if ( V_3 -> V_61 != F_35 ( V_62 ) )
goto V_63;
V_49 = F_36 ( V_3 , 0 , sizeof( V_60 ) , & V_60 ) ;
if ( ! V_49 )
goto V_63;
F_37 ( V_9 , V_49 ) ;
if ( V_49 -> V_64 == F_38 ( V_65 ) ) {
F_31 ( V_9 , V_49 ) ;
F_39 ( L_1 ) ;
}
V_63:
return V_66 ;
}
static struct V_21 * F_40 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_21 * V_67 = NULL , * V_68 = NULL , * V_21 ;
struct V_37 * V_38 ;
bool V_69 = false ;
F_41 (bond, slave, iter) {
if ( ! F_24 ( V_21 ) )
continue;
if ( ! V_69 ) {
if ( ! V_67 || V_67 -> V_35 < V_21 -> V_35 )
V_67 = V_21 ;
} else {
if ( ! V_68 || V_68 -> V_35 < V_21 -> V_35 )
V_68 = V_21 ;
}
if ( V_21 == V_29 -> V_68 )
V_69 = true ;
}
if ( ! V_68 || ( V_67 && V_68 -> V_35 < V_67 -> V_35 ) )
V_68 = V_67 ;
if ( V_68 )
V_29 -> V_68 = V_68 ;
return V_68 ;
}
static struct V_21 * F_42 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_21 * V_67 = NULL , * V_68 = NULL , * V_21 ;
struct V_37 * V_38 ;
bool V_69 = false ;
F_23 (bond, slave, iter) {
if ( ! F_24 ( V_21 ) )
continue;
if ( ! V_69 ) {
if ( ! V_67 || V_67 -> V_35 < V_21 -> V_35 )
V_67 = V_21 ;
} else {
if ( ! V_68 || V_68 -> V_35 < V_21 -> V_35 )
V_68 = V_21 ;
}
if ( V_21 == V_29 -> V_68 )
V_69 = true ;
}
if ( ! V_68 || ( V_67 && V_68 -> V_35 < V_67 -> V_35 ) )
V_68 = V_67 ;
if ( V_68 )
V_29 -> V_68 = V_68 ;
return V_68 ;
}
static void F_43 ( struct V_8 * V_9 , T_1 V_70 [] )
{
if ( ! V_9 -> V_71 )
return;
if ( ! V_9 -> V_72 . V_73 ) {
if ( ! F_44 ( V_9 -> V_71 -> V_74 , 1 ) )
V_9 -> V_72 . V_73 = 1 ;
else
V_9 -> V_72 . V_73 = 0 ;
}
V_9 -> V_72 . V_75 = 0 ;
F_45 ( V_9 -> V_71 , V_70 , true ) ;
}
static void F_46 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_50 * V_76 ;
T_2 V_25 , V_27 ;
F_27 ( V_9 ) ;
V_76 = V_29 -> V_53 ;
V_25 = V_29 -> V_77 ;
for (; V_25 != V_78 ; V_25 = V_27 ) {
V_27 = V_76 [ V_25 ] . V_79 ;
if ( V_76 [ V_25 ] . V_21 == V_21 ) {
struct V_21 * V_45 = F_40 ( V_9 ) ;
if ( V_45 ) {
V_76 [ V_25 ] . V_21 = V_45 ;
if ( ! F_32 ( V_76 [ V_25 ] . V_56 ,
V_80 ) ) {
V_29 -> V_53 [ V_25 ] . V_58 = 1 ;
V_29 -> V_59 = 1 ;
V_29 -> V_81 =
V_82 ;
}
} else {
V_76 [ V_25 ] . V_21 = NULL ;
}
}
}
F_28 ( V_9 ) ;
F_47 ( & V_9 -> V_83 ) ;
if ( V_21 != V_9 -> V_71 )
F_43 ( V_9 , V_21 -> V_74 -> V_84 ) ;
F_48 ( & V_9 -> V_83 ) ;
}
static void F_49 ( struct V_50 * V_51 )
{
int V_6 ;
if ( ! V_51 -> V_21 )
return;
for ( V_6 = 0 ; V_6 < V_85 ; V_6 ++ ) {
struct V_2 * V_3 ;
V_3 = F_50 ( V_65 , V_62 ,
V_51 -> V_55 ,
V_51 -> V_21 -> V_74 ,
V_51 -> V_52 ,
V_51 -> V_56 ,
V_51 -> V_21 -> V_74 -> V_84 ,
V_51 -> V_56 ) ;
if ( ! V_3 ) {
F_51 ( L_2 ,
V_51 -> V_21 -> V_9 -> V_74 -> V_86 ) ;
continue;
}
V_3 -> V_74 = V_51 -> V_21 -> V_74 ;
if ( V_51 -> V_87 ) {
V_3 = F_52 ( V_3 , F_38 ( V_88 ) , V_51 -> V_87 ) ;
if ( ! V_3 ) {
F_51 ( L_3 ,
V_51 -> V_21 -> V_9 -> V_74 -> V_86 ) ;
continue;
}
}
F_53 ( V_3 ) ;
}
}
static void F_54 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_50 * V_51 ;
T_2 V_42 ;
F_27 ( V_9 ) ;
V_42 = V_29 -> V_77 ;
for (; V_42 != V_78 ;
V_42 = V_51 -> V_79 ) {
V_51 = & ( V_29 -> V_53 [ V_42 ] ) ;
if ( V_51 -> V_58 ) {
F_49 ( V_51 ) ;
if ( V_29 -> V_81 == 0 )
V_51 -> V_58 = 0 ;
}
}
V_29 -> V_89 = V_90 ;
F_28 ( V_9 ) ;
}
static void F_55 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_50 * V_51 ;
int V_58 = 0 ;
T_2 V_42 ;
F_27 ( V_9 ) ;
V_42 = V_29 -> V_77 ;
for (; V_42 != V_78 ;
V_42 = V_51 -> V_79 ) {
V_51 = & ( V_29 -> V_53 [ V_42 ] ) ;
if ( ( V_51 -> V_21 == V_21 ) &&
! F_32 ( V_51 -> V_56 , V_80 ) ) {
V_51 -> V_58 = 1 ;
V_58 = 1 ;
}
}
if ( V_58 ) {
V_29 -> V_59 = 1 ;
V_29 -> V_81 = V_82 ;
}
F_28 ( V_9 ) ;
}
static void F_56 ( struct V_8 * V_9 , T_3 V_91 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_50 * V_51 ;
T_2 V_42 ;
F_29 ( V_9 ) ;
V_42 = V_29 -> V_77 ;
for (; V_42 != V_78 ;
V_42 = V_51 -> V_79 ) {
V_51 = & ( V_29 -> V_53 [ V_42 ] ) ;
if ( ! V_51 -> V_21 ) {
F_51 ( L_4 ,
V_9 -> V_74 -> V_86 ) ;
continue;
}
if ( ( V_51 -> V_52 == V_91 ) &&
! F_32 ( V_51 -> V_21 -> V_74 -> V_84 ,
V_9 -> V_74 -> V_84 ) &&
! F_32 ( V_51 -> V_56 , V_80 ) ) {
V_51 -> V_58 = 1 ;
V_29 -> V_59 = 1 ;
}
}
F_30 ( V_9 ) ;
}
static struct V_21 * F_57 ( struct V_2 * V_3 , struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_1 * V_49 = V_1 ( V_3 ) ;
struct V_21 * V_45 , * V_71 ;
struct V_50 * V_51 ;
T_2 V_42 = 0 ;
F_29 ( V_9 ) ;
V_71 = F_58 ( V_9 -> V_71 ) ;
V_42 = F_2 ( ( T_1 * ) & V_49 -> V_55 , sizeof( V_49 -> V_55 ) ) ;
V_51 = & ( V_29 -> V_53 [ V_42 ] ) ;
if ( V_51 -> V_54 ) {
if ( ( V_51 -> V_52 == V_49 -> V_52 ) &&
( V_51 -> V_55 == V_49 -> V_55 ) ) {
if ( ! F_32 ( V_49 -> V_56 , V_80 ) ) {
F_33 ( V_51 -> V_56 , V_49 -> V_56 ) ;
}
F_33 ( V_51 -> V_57 , V_49 -> V_57 ) ;
V_45 = V_51 -> V_21 ;
if ( V_45 ) {
F_30 ( V_9 ) ;
return V_45 ;
}
} else {
if ( V_9 -> V_71 &&
V_51 -> V_21 != V_71 ) {
V_51 -> V_21 = V_71 ;
F_49 ( V_51 ) ;
}
}
}
V_45 = F_42 ( V_9 ) ;
if ( V_45 ) {
if ( ! ( V_51 -> V_54 &&
V_51 -> V_52 == V_49 -> V_52 ) ) {
T_2 V_92 = F_2 ( ( T_1 * ) & V_49 -> V_52 ,
sizeof( V_49 -> V_52 ) ) ;
F_59 ( V_9 , V_42 ) ;
F_60 ( V_9 , V_92 , V_42 ) ;
}
V_51 -> V_52 = V_49 -> V_52 ;
V_51 -> V_55 = V_49 -> V_55 ;
F_33 ( V_51 -> V_56 , V_49 -> V_56 ) ;
F_33 ( V_51 -> V_57 , V_49 -> V_57 ) ;
V_51 -> V_21 = V_45 ;
if ( ! F_32 ( V_51 -> V_56 , V_80 ) ) {
V_51 -> V_58 = 1 ;
V_9 -> V_72 . V_59 = 1 ;
} else {
V_51 -> V_58 = 0 ;
}
if ( F_61 ( V_3 , & V_51 -> V_87 ) )
V_51 -> V_87 = 0 ;
if ( ! V_51 -> V_54 ) {
T_2 V_93 = V_29 -> V_77 ;
V_29 -> V_77 = V_42 ;
V_51 -> V_79 = V_93 ;
if ( V_93 != V_78 ) {
V_29 -> V_53 [ V_93 ] . V_94 =
V_42 ;
}
V_51 -> V_54 = 1 ;
}
}
F_30 ( V_9 ) ;
return V_45 ;
}
static struct V_21 * F_62 ( struct V_2 * V_3 , struct V_8 * V_9 )
{
struct V_1 * V_49 = V_1 ( V_3 ) ;
struct V_21 * V_17 = NULL ;
if ( ! F_63 ( V_9 , V_49 -> V_57 ) )
return NULL ;
if ( V_49 -> V_64 == F_38 ( V_65 ) ) {
V_17 = F_57 ( V_3 , V_9 ) ;
if ( V_17 )
F_33 ( V_49 -> V_57 , V_17 -> V_74 -> V_84 ) ;
F_39 ( L_5 ) ;
} else if ( V_49 -> V_64 == F_38 ( V_95 ) ) {
F_57 ( V_3 , V_9 ) ;
V_9 -> V_72 . V_89 = V_90 ;
F_56 ( V_9 , V_49 -> V_52 ) ;
F_39 ( L_6 ) ;
}
return V_17 ;
}
static void F_64 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_21 * V_45 ;
struct V_50 * V_51 ;
int V_58 ;
T_2 V_42 ;
F_27 ( V_9 ) ;
V_58 = 0 ;
V_42 = V_29 -> V_77 ;
for (; V_42 != V_78 ;
V_42 = V_51 -> V_79 ) {
V_51 = & ( V_29 -> V_53 [ V_42 ] ) ;
V_45 = F_42 ( V_9 ) ;
if ( V_45 && ( V_51 -> V_21 != V_45 ) ) {
V_51 -> V_21 = V_45 ;
V_51 -> V_58 = 1 ;
V_58 = 1 ;
}
}
if ( V_58 )
V_29 -> V_59 = 1 ;
F_28 ( V_9 ) ;
}
static void F_65 ( struct V_50 * V_12 )
{
V_12 -> V_79 = V_78 ;
V_12 -> V_94 = V_78 ;
V_12 -> V_54 = 0 ;
V_12 -> V_21 = NULL ;
V_12 -> V_87 = 0 ;
}
static void F_66 ( struct V_50 * V_12 )
{
V_12 -> V_96 = V_78 ;
V_12 -> V_97 = V_78 ;
V_12 -> V_98 = V_78 ;
}
static void F_67 ( struct V_50 * V_12 )
{
memset ( V_12 , 0 , sizeof( struct V_50 ) ) ;
F_65 ( V_12 ) ;
F_66 ( V_12 ) ;
}
static void F_68 ( struct V_8 * V_9 , T_2 V_25 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
T_2 V_27 = V_29 -> V_53 [ V_25 ] . V_79 ;
T_2 V_99 = V_29 -> V_53 [ V_25 ] . V_94 ;
if ( V_25 == V_29 -> V_77 )
V_29 -> V_77 = V_27 ;
if ( V_99 != V_78 )
V_29 -> V_53 [ V_99 ] . V_79 = V_27 ;
if ( V_27 != V_78 )
V_29 -> V_53 [ V_27 ] . V_94 = V_99 ;
}
static void F_59 ( struct V_8 * V_9 , T_2 V_25 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
T_2 V_27 = V_29 -> V_53 [ V_25 ] . V_98 ;
T_2 V_99 = V_29 -> V_53 [ V_25 ] . V_97 ;
V_29 -> V_53 [ V_25 ] . V_98 = V_78 ;
V_29 -> V_53 [ V_25 ] . V_97 = V_78 ;
if ( V_27 != V_78 )
V_29 -> V_53 [ V_27 ] . V_97 = V_99 ;
if ( V_99 == V_78 )
return;
if ( V_29 -> V_53 [ V_99 ] . V_96 == V_25 )
V_29 -> V_53 [ V_99 ] . V_96 = V_27 ;
else
V_29 -> V_53 [ V_99 ] . V_98 = V_27 ;
}
static void F_69 ( struct V_8 * V_9 , T_2 V_25 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_50 * V_12 = & ( V_29 -> V_53 [ V_25 ] ) ;
F_68 ( V_9 , V_25 ) ;
F_65 ( V_12 ) ;
F_59 ( V_9 , V_25 ) ;
}
static void F_60 ( struct V_8 * V_9 , T_2 V_100 , T_2 V_101 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
T_2 V_18 ;
V_29 -> V_53 [ V_101 ] . V_97 = V_100 ;
V_18 = V_29 -> V_53 [ V_100 ] . V_96 ;
V_29 -> V_53 [ V_101 ] . V_98 = V_18 ;
if ( V_18 != V_78 )
V_29 -> V_53 [ V_18 ] . V_97 = V_101 ;
V_29 -> V_53 [ V_100 ] . V_96 = V_101 ;
}
static void F_37 ( struct V_8 * V_9 , struct V_1 * V_49 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
T_2 V_100 = F_2 ( ( T_1 * ) & ( V_49 -> V_52 ) , sizeof( V_49 -> V_52 ) ) ;
T_2 V_25 ;
F_27 ( V_9 ) ;
V_25 = V_29 -> V_53 [ V_100 ] . V_96 ;
while ( V_25 != V_78 ) {
struct V_50 * V_12 = & ( V_29 -> V_53 [ V_25 ] ) ;
T_2 V_27 = V_12 -> V_98 ;
if ( V_12 -> V_52 == V_49 -> V_52 &&
! F_32 ( V_49 -> V_57 , V_12 -> V_57 ) )
F_69 ( V_9 , V_25 ) ;
V_25 = V_27 ;
}
F_28 ( V_9 ) ;
}
static int F_70 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_50 * V_32 ;
int V_30 = V_102 * sizeof( struct V_50 ) ;
int V_6 ;
V_32 = F_71 ( V_30 , V_33 ) ;
if ( ! V_32 )
return - 1 ;
F_27 ( V_9 ) ;
V_29 -> V_53 = V_32 ;
V_29 -> V_77 = V_78 ;
for ( V_6 = 0 ; V_6 < V_102 ; V_6 ++ )
F_67 ( V_29 -> V_53 + V_6 ) ;
F_28 ( V_9 ) ;
V_9 -> V_103 = F_34 ;
return 0 ;
}
static void F_72 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
F_27 ( V_9 ) ;
F_20 ( V_29 -> V_53 ) ;
V_29 -> V_53 = NULL ;
V_29 -> V_77 = V_78 ;
F_28 ( V_9 ) ;
}
static void F_73 ( struct V_8 * V_9 , unsigned short V_87 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
T_2 V_104 ;
F_27 ( V_9 ) ;
V_104 = V_29 -> V_77 ;
while ( V_104 != V_78 ) {
struct V_50 * V_105 = & ( V_29 -> V_53 [ V_104 ] ) ;
T_2 V_27 = V_29 -> V_53 [ V_104 ] . V_79 ;
if ( V_105 -> V_87 == V_87 )
F_69 ( V_9 , V_104 ) ;
V_104 = V_27 ;
}
F_28 ( V_9 ) ;
}
static void F_74 ( struct V_21 * V_21 , T_1 V_106 [] ,
T_4 V_107 , T_5 V_108 )
{
struct V_109 V_110 ;
struct V_2 * V_3 ;
int V_30 = sizeof( struct V_109 ) ;
char * V_111 ;
memset ( & V_110 , 0 , V_30 ) ;
F_33 ( V_110 . V_56 , V_106 ) ;
F_33 ( V_110 . V_57 , V_106 ) ;
V_110 . type = F_35 ( V_112 ) ;
V_3 = F_75 ( V_30 ) ;
if ( ! V_3 )
return;
V_111 = F_76 ( V_3 , V_30 ) ;
memcpy ( V_111 , & V_110 , V_30 ) ;
F_77 ( V_3 ) ;
V_3 -> V_113 = V_3 -> V_114 + V_115 ;
V_3 -> V_61 = V_110 . type ;
V_3 -> V_116 = V_117 ;
V_3 -> V_74 = V_21 -> V_74 ;
if ( V_108 ) {
V_3 = F_52 ( V_3 , V_107 , V_108 ) ;
if ( ! V_3 ) {
F_51 ( L_3 ,
V_21 -> V_9 -> V_74 -> V_86 ) ;
return;
}
}
F_78 ( V_3 ) ;
}
static void F_45 ( struct V_21 * V_21 , T_1 V_106 [] ,
bool V_118 )
{
struct V_8 * V_9 = F_79 ( V_21 ) ;
struct V_119 * V_120 ;
struct V_37 * V_38 ;
struct V_121 V_122 [ V_123 ] ;
F_74 ( V_21 , V_106 , 0 , 0 ) ;
F_80 () ;
F_81 (bond->dev, upper, iter) {
if ( F_82 ( V_120 ) && F_83 ( V_120 ) == 0 ) {
if ( V_118 &&
F_32 ( V_106 ,
V_120 -> V_84 ) ) {
F_74 ( V_21 , V_106 ,
F_84 ( V_120 ) ,
F_85 ( V_120 ) ) ;
} else if ( ! V_118 ) {
F_74 ( V_21 , V_120 -> V_84 ,
F_84 ( V_120 ) ,
F_85 ( V_120 ) ) ;
}
}
if ( F_86 ( V_120 ) && ! V_118 ) {
memset ( V_122 , 0 , sizeof( V_122 ) ) ;
F_87 ( V_9 -> V_74 , V_120 , V_122 ) ;
F_74 ( V_21 , V_120 -> V_84 ,
V_122 [ 0 ] . V_107 , V_122 [ 0 ] . V_87 ) ;
}
}
F_88 () ;
}
static int F_89 ( struct V_21 * V_21 , T_1 V_70 [] )
{
struct V_119 * V_74 = V_21 -> V_74 ;
struct V_124 V_125 ;
if ( F_90 ( V_21 -> V_9 ) == V_126 ) {
memcpy ( V_74 -> V_84 , V_70 , V_74 -> V_127 ) ;
return 0 ;
}
memcpy ( V_125 . V_128 , V_70 , V_74 -> V_127 ) ;
V_125 . V_129 = V_74 -> type ;
if ( F_91 ( V_74 , & V_125 ) ) {
F_51 ( L_7
L_8 ,
V_21 -> V_9 -> V_74 -> V_86 , V_74 -> V_86 ) ;
return - V_130 ;
}
return 0 ;
}
static void F_92 ( struct V_21 * V_131 , struct V_21 * V_132 )
{
T_1 V_133 [ V_134 ] ;
F_33 ( V_133 , V_131 -> V_74 -> V_84 ) ;
F_89 ( V_131 , V_132 -> V_74 -> V_84 ) ;
F_89 ( V_132 , V_133 ) ;
}
static void F_93 ( struct V_8 * V_9 , struct V_21 * V_131 ,
struct V_21 * V_132 )
{
int V_135 = ( F_24 ( V_131 ) != F_24 ( V_132 ) ) ;
struct V_21 * V_136 = NULL ;
F_94 () ;
if ( F_24 ( V_131 ) ) {
F_45 ( V_131 , V_131 -> V_74 -> V_84 , false ) ;
if ( V_9 -> V_72 . V_137 ) {
F_55 ( V_9 , V_131 ) ;
}
} else {
V_136 = V_131 ;
}
if ( F_24 ( V_132 ) ) {
F_45 ( V_132 , V_132 -> V_74 -> V_84 , false ) ;
if ( V_9 -> V_72 . V_137 ) {
F_55 ( V_9 , V_132 ) ;
}
} else {
V_136 = V_132 ;
}
if ( V_9 -> V_72 . V_137 && V_135 ) {
F_43 ( V_9 ,
V_136 -> V_74 -> V_84 ) ;
}
}
static void F_95 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
int V_138 ;
int V_139 ;
struct V_21 * V_140 ;
V_138 = ! F_32 ( V_21 -> V_141 ,
V_21 -> V_74 -> V_84 ) ;
V_139 = ! F_32 ( V_21 -> V_141 ,
V_9 -> V_74 -> V_84 ) ;
if ( V_138 && V_139 ) {
V_140 = F_96 ( V_9 , V_21 -> V_141 ) ;
if ( V_140 ) {
F_92 ( V_21 , V_140 ) ;
F_93 ( V_9 , V_21 , V_140 ) ;
}
}
}
static int F_97 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
struct V_21 * V_142 = V_9 -> V_71 ;
struct V_21 * V_143 , * V_144 = NULL ;
struct V_37 * V_38 ;
if ( ! F_98 ( V_9 ) ) {
return 0 ;
}
if ( ! F_32 ( V_21 -> V_141 , V_9 -> V_74 -> V_84 ) ) {
if ( ! F_96 ( V_9 , V_21 -> V_74 -> V_84 ) )
return 0 ;
F_89 ( V_21 , V_9 -> V_74 -> V_84 ) ;
}
F_41 (bond, tmp_slave1, iter) {
if ( ! F_96 ( V_9 , V_143 -> V_141 ) ) {
V_144 = V_143 ;
break;
}
if ( ! V_142 ) {
if ( F_32 ( V_143 -> V_74 -> V_84 ,
V_9 -> V_74 -> V_84 ) ) {
V_142 = V_143 ;
}
}
}
if ( V_144 ) {
F_89 ( V_21 , V_144 -> V_141 ) ;
F_99 ( L_9 ,
V_9 -> V_74 -> V_86 , V_21 -> V_74 -> V_86 ,
V_144 -> V_74 -> V_86 ) ;
} else if ( V_142 ) {
F_51 ( L_10 ,
V_9 -> V_74 -> V_86 , V_21 -> V_74 -> V_86 ) ;
return - V_145 ;
}
return 0 ;
}
static int F_100 ( struct V_8 * V_9 , void * V_70 )
{
struct V_21 * V_21 , * V_146 ;
struct V_37 * V_38 ;
struct V_124 V_147 ;
char V_148 [ V_134 ] ;
int V_149 ;
if ( V_9 -> V_72 . V_137 )
return 0 ;
F_41 (bond, slave, iter) {
F_33 ( V_148 , V_21 -> V_74 -> V_84 ) ;
V_149 = F_91 ( V_21 -> V_74 , V_70 ) ;
F_33 ( V_21 -> V_74 -> V_84 , V_148 ) ;
if ( V_149 )
goto V_150;
}
return 0 ;
V_150:
memcpy ( V_147 . V_128 , V_9 -> V_74 -> V_84 , V_9 -> V_74 -> V_127 ) ;
V_147 . V_129 = V_9 -> V_74 -> type ;
F_41 (bond, rollback_slave, iter) {
if ( V_146 == V_21 )
break;
F_33 ( V_148 , V_146 -> V_74 -> V_84 ) ;
F_91 ( V_146 -> V_74 , & V_147 ) ;
F_33 ( V_146 -> V_74 -> V_84 , V_148 ) ;
}
return V_149 ;
}
int F_101 ( struct V_8 * V_9 , int V_137 )
{
int V_149 ;
V_149 = F_17 ( V_9 ) ;
if ( V_149 )
return V_149 ;
if ( V_137 ) {
V_9 -> V_72 . V_137 = 1 ;
V_149 = F_70 ( V_9 ) ;
if ( V_149 ) {
F_19 ( V_9 ) ;
return V_149 ;
}
} else {
V_9 -> V_72 . V_137 = 0 ;
}
return 0 ;
}
void F_102 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
F_19 ( V_9 ) ;
if ( V_29 -> V_137 )
F_72 ( V_9 ) ;
}
static int F_103 ( struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_21 * V_17 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_151 * V_152 = F_104 ( V_3 ) ;
if ( ! V_17 ) {
V_17 = F_58 ( V_9 -> V_71 ) ;
if ( V_9 -> V_153 . V_154 )
V_29 -> V_155 += V_3 -> V_156 ;
}
if ( V_17 && F_24 ( V_17 ) ) {
if ( V_17 != F_58 ( V_9 -> V_71 ) ) {
F_33 ( V_152 -> V_157 ,
V_17 -> V_74 -> V_84 ) ;
}
F_105 ( V_9 , V_3 , V_17 -> V_74 ) ;
goto V_63;
}
if ( V_17 && V_9 -> V_153 . V_154 ) {
F_8 ( V_9 ) ;
F_15 ( V_9 , V_17 , 0 ) ;
F_10 ( V_9 ) ;
}
F_106 ( V_3 ) ;
V_63:
return V_158 ;
}
int F_107 ( struct V_2 * V_3 , struct V_119 * V_159 )
{
struct V_8 * V_9 = F_108 ( V_159 ) ;
struct V_151 * V_152 ;
struct V_21 * V_17 = NULL ;
T_2 V_42 ;
F_77 ( V_3 ) ;
V_152 = F_104 ( V_3 ) ;
if ( ! F_109 ( V_152 -> V_160 ) ) {
switch ( V_3 -> V_61 ) {
case F_38 ( V_161 ) :
case F_38 ( V_162 ) :
case F_38 ( V_163 ) :
V_42 = F_110 ( V_9 , V_3 ) ;
if ( V_9 -> V_153 . V_154 ) {
V_17 = F_26 ( V_9 ,
V_42 & 0xFF ,
V_3 -> V_156 ) ;
} else {
struct V_37 * V_38 ;
int V_164 = V_42 % V_9 -> V_165 ;
F_23 (bond, tx_slave, iter)
if ( -- V_164 < 0 )
break;
}
break;
}
}
return F_103 ( V_3 , V_9 , V_17 ) ;
}
int F_111 ( struct V_2 * V_3 , struct V_119 * V_159 )
{
struct V_8 * V_9 = F_108 ( V_159 ) ;
struct V_151 * V_152 ;
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_21 * V_17 = NULL ;
static const T_3 V_166 = F_112 ( 0xffffffff ) ;
int V_5 = 0 ;
bool V_167 = true ;
T_2 V_42 = 0 ;
const T_1 * V_4 = NULL ;
struct V_168 * V_169 ;
F_77 ( V_3 ) ;
V_152 = F_104 ( V_3 ) ;
switch ( F_113 ( V_3 -> V_61 ) ) {
case V_161 : {
const struct V_170 * V_171 = F_114 ( V_3 ) ;
if ( F_32 ( V_152 -> V_160 , V_80 ) ||
( V_171 -> V_172 == V_166 ) ||
( V_171 -> V_61 == V_173 ) ) {
V_167 = false ;
break;
}
V_4 = ( char * ) & ( V_171 -> V_172 ) ;
V_5 = sizeof( V_171 -> V_172 ) ;
}
break;
case V_163 :
if ( F_32 ( V_152 -> V_160 , V_80 ) ) {
V_167 = false ;
break;
}
if ( F_32 ( V_152 -> V_160 , V_174 ) ) {
V_167 = false ;
break;
}
V_169 = F_115 ( V_3 ) ;
if ( F_116 ( & V_169 -> V_175 ) ) {
V_167 = false ;
break;
}
V_4 = ( char * ) & ( F_115 ( V_3 ) -> V_172 ) ;
V_5 = sizeof( F_115 ( V_3 ) -> V_172 ) ;
break;
case V_162 :
if ( F_117 ( V_3 ) -> V_176 != V_177 ) {
V_167 = false ;
break;
}
if ( F_117 ( V_3 ) -> V_178 != V_179 ) {
V_167 = false ;
break;
}
V_4 = ( char * ) V_152 -> V_160 ;
V_5 = V_134 ;
break;
case V_62 :
V_167 = false ;
if ( V_29 -> V_137 )
V_17 = F_62 ( V_3 , V_9 ) ;
break;
default:
V_167 = false ;
break;
}
if ( V_167 ) {
V_42 = F_2 ( V_4 , V_5 ) ;
V_17 = F_26 ( V_9 , V_42 , V_3 -> V_156 ) ;
}
return F_103 ( V_3 , V_9 , V_17 ) ;
}
void F_118 ( struct V_180 * V_181 )
{
struct V_8 * V_9 = F_119 ( V_181 , struct V_8 ,
V_182 . V_181 ) ;
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_37 * V_38 ;
struct V_21 * V_21 ;
if ( ! F_98 ( V_9 ) ) {
V_29 -> V_183 = 0 ;
V_29 -> V_184 = 0 ;
goto V_185;
}
F_80 () ;
V_29 -> V_183 ++ ;
V_29 -> V_184 ++ ;
if ( V_29 -> V_184 >= F_120 ( V_9 ) ) {
bool V_118 ;
F_121 ( & V_9 -> V_83 ) ;
F_23 (bond, slave, iter) {
V_118 = ( V_21 != V_9 -> V_71 ||
V_29 -> V_137 ) ;
F_45 ( V_21 , V_21 -> V_74 -> V_84 ,
V_118 ) ;
}
F_122 ( & V_9 -> V_83 ) ;
V_29 -> V_184 = 0 ;
}
if ( V_29 -> V_183 >= V_186 ) {
F_121 ( & V_9 -> V_83 ) ;
F_23 (bond, slave, iter) {
F_16 ( V_9 , V_21 , 1 ) ;
if ( V_21 == V_9 -> V_71 ) {
F_14 ( V_21 ) . V_22 =
V_29 -> V_155 /
V_16 ;
V_29 -> V_155 = 0 ;
}
}
F_122 ( & V_9 -> V_83 ) ;
V_29 -> V_183 = 0 ;
}
if ( V_29 -> V_137 ) {
if ( V_29 -> V_73 &&
( ++ V_29 -> V_75 >= V_187 ) ) {
F_88 () ;
if ( ! F_123 () )
goto V_185;
V_29 -> V_75 = 0 ;
F_44 ( V_9 -> V_71 -> V_74 , - 1 ) ;
V_29 -> V_73 = 0 ;
F_124 () ;
F_80 () ;
}
if ( V_29 -> F_64 ) {
V_29 -> F_64 = 0 ;
F_64 ( V_9 ) ;
}
if ( V_29 -> V_59 ) {
if ( V_29 -> V_89 ) {
-- V_29 -> V_89 ;
} else {
F_54 ( V_9 ) ;
if ( V_29 -> V_81 )
-- V_29 -> V_81 ;
else
V_29 -> V_59 = 0 ;
}
}
}
F_88 () ;
V_185:
F_125 ( V_9 -> V_188 , & V_9 -> V_182 , V_189 ) ;
}
int F_126 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
int V_149 ;
V_149 = F_89 ( V_21 , V_21 -> V_141 ) ;
if ( V_149 )
return V_149 ;
V_149 = F_97 ( V_9 , V_21 ) ;
if ( V_149 )
return V_149 ;
F_13 ( V_21 ) ;
V_9 -> V_72 . V_183 = V_186 ;
if ( V_9 -> V_72 . V_137 )
V_9 -> V_72 . F_64 = 1 ;
return 0 ;
}
void F_127 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
if ( F_98 ( V_9 ) )
F_95 ( V_9 , V_21 ) ;
F_16 ( V_9 , V_21 , 0 ) ;
if ( V_9 -> V_72 . V_137 ) {
V_9 -> V_72 . V_68 = NULL ;
F_46 ( V_9 , V_21 ) ;
}
}
void F_128 ( struct V_8 * V_9 , struct V_21 * V_21 , char V_190 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
if ( V_190 == V_191 ) {
F_16 ( V_9 , V_21 , 0 ) ;
if ( V_9 -> V_72 . V_137 )
F_46 ( V_9 , V_21 ) ;
} else if ( V_190 == V_192 ) {
V_29 -> V_183 = V_186 ;
if ( V_9 -> V_72 . V_137 ) {
V_9 -> V_72 . F_64 = 1 ;
}
}
}
void F_129 ( struct V_8 * V_9 , struct V_21 * V_193 )
__releases( &bond->curr_slave_lock
int F_130 ( struct V_119 * V_159 , void * V_70 )
__acquires( &bond->lock
void F_131 ( struct V_8 * V_9 , unsigned short V_87 )
{
if ( V_9 -> V_72 . V_137 )
F_73 ( V_9 , V_87 ) ;
}
