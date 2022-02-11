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
struct V_34 * V_35 ;
F_3 ( V_9 ) ;
F_20 ( V_29 -> V_26 ) ;
V_29 -> V_26 = NULL ;
F_6 ( V_9 ) ;
V_35 = F_21 ( V_29 -> V_36 ) ;
if ( V_35 )
F_22 ( V_35 , V_37 ) ;
}
static long long F_23 ( struct V_21 * V_21 )
{
return ( V_38 ) ( V_21 -> V_39 << 20 ) -
( V_38 ) ( F_14 ( V_21 ) . V_22 << 3 ) ;
}
static struct V_21 * F_24 ( struct V_8 * V_9 )
{
struct V_21 * V_21 , * V_40 ;
struct V_41 * V_42 ;
long long V_43 ;
V_40 = NULL ;
V_43 = V_44 ;
F_25 (bond, slave, iter) {
if ( F_26 ( V_21 ) ) {
long long V_45 = F_23 ( V_21 ) ;
if ( V_43 < V_45 ) {
V_40 = V_21 ;
V_43 = V_45 ;
}
}
}
return V_40 ;
}
static struct V_21 * F_27 ( struct V_8 * V_9 , T_2 V_46 ,
T_2 V_47 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_11 * V_48 ;
struct V_21 * V_49 ;
V_48 = V_29 -> V_26 ;
V_49 = V_48 [ V_46 ] . V_17 ;
if ( ! V_49 ) {
V_49 = F_24 ( V_9 ) ;
if ( V_49 ) {
struct V_50 * V_51 =
& ( F_14 ( V_49 ) ) ;
T_2 V_27 = V_51 -> V_23 ;
V_48 [ V_46 ] . V_17 = V_49 ;
V_48 [ V_46 ] . V_18 = V_27 ;
V_48 [ V_46 ] . V_20 = V_19 ;
if ( V_27 != V_19 )
V_48 [ V_27 ] . V_20 = V_46 ;
V_51 -> V_23 = V_46 ;
V_51 -> V_22 +=
V_48 [ V_46 ] . V_14 ;
}
}
if ( V_49 )
V_48 [ V_46 ] . V_15 += V_47 ;
return V_49 ;
}
static struct V_21 * F_28 ( struct V_8 * V_9 , T_2 V_46 ,
T_2 V_47 )
{
struct V_21 * V_17 ;
F_8 ( V_9 ) ;
V_17 = F_27 ( V_9 , V_46 , V_47 ) ;
F_10 ( V_9 ) ;
return V_17 ;
}
static inline void F_29 ( struct V_8 * V_9 )
{
F_4 ( & ( F_5 ( V_9 ) . V_52 ) ) ;
}
static inline void F_30 ( struct V_8 * V_9 )
{
F_7 ( & ( F_5 ( V_9 ) . V_52 ) ) ;
}
static inline void F_31 ( struct V_8 * V_9 )
{
F_9 ( & ( F_5 ( V_9 ) . V_52 ) ) ;
}
static inline void F_32 ( struct V_8 * V_9 )
{
F_11 ( & ( F_5 ( V_9 ) . V_52 ) ) ;
}
static void F_33 ( struct V_8 * V_9 , struct V_1 * V_53 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_54 * V_55 ;
T_2 V_46 ;
F_29 ( V_9 ) ;
V_46 = F_2 ( ( T_1 * ) & ( V_53 -> V_56 ) , sizeof( V_53 -> V_56 ) ) ;
V_55 = & ( V_29 -> V_57 [ V_46 ] ) ;
if ( ( V_55 -> V_58 ) &&
( V_55 -> V_56 == V_53 -> V_59 ) &&
( V_55 -> V_59 == V_53 -> V_56 ) &&
( ! F_34 ( V_55 -> V_60 , V_53 -> V_61 ) ) ) {
F_35 ( V_55 -> V_60 , V_53 -> V_61 ) ;
V_55 -> V_62 = 1 ;
V_29 -> V_63 = 1 ;
}
F_30 ( V_9 ) ;
}
static int F_36 ( const struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_21 * V_21 )
{
struct V_1 * V_53 , V_64 ;
if ( V_3 -> V_65 != F_37 ( V_66 ) )
goto V_67;
V_53 = F_38 ( V_3 , 0 , sizeof( V_64 ) , & V_64 ) ;
if ( ! V_53 )
goto V_67;
F_39 ( V_9 , V_53 ) ;
if ( V_53 -> V_68 == F_40 ( V_69 ) ) {
F_33 ( V_9 , V_53 ) ;
F_41 ( V_9 -> V_70 , L_1 ) ;
}
V_67:
return V_71 ;
}
static struct V_21 * F_42 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_21 * V_72 = NULL , * V_73 = NULL , * V_21 ;
struct V_41 * V_42 ;
bool V_74 = false ;
F_43 (bond, slave, iter) {
if ( ! F_26 ( V_21 ) )
continue;
if ( ! V_74 ) {
if ( ! V_72 || V_72 -> V_39 < V_21 -> V_39 )
V_72 = V_21 ;
} else {
if ( ! V_73 || V_73 -> V_39 < V_21 -> V_39 )
V_73 = V_21 ;
}
if ( V_21 == V_29 -> V_73 )
V_74 = true ;
}
if ( ! V_73 || ( V_72 && V_73 -> V_39 < V_72 -> V_39 ) )
V_73 = V_72 ;
if ( V_73 )
V_29 -> V_73 = V_73 ;
return V_73 ;
}
static struct V_21 * F_44 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_21 * V_72 = NULL , * V_73 = NULL , * V_21 ;
struct V_41 * V_42 ;
bool V_74 = false ;
F_25 (bond, slave, iter) {
if ( ! F_26 ( V_21 ) )
continue;
if ( ! V_74 ) {
if ( ! V_72 || V_72 -> V_39 < V_21 -> V_39 )
V_72 = V_21 ;
} else {
if ( ! V_73 || V_73 -> V_39 < V_21 -> V_39 )
V_73 = V_21 ;
}
if ( V_21 == V_29 -> V_73 )
V_74 = true ;
}
if ( ! V_73 || ( V_72 && V_73 -> V_39 < V_72 -> V_39 ) )
V_73 = V_72 ;
if ( V_73 )
V_29 -> V_73 = V_73 ;
return V_73 ;
}
static void F_45 ( struct V_8 * V_9 , T_1 V_75 [] )
{
struct V_21 * V_76 = F_46 ( V_9 ) ;
if ( ! V_76 )
return;
if ( ! V_9 -> V_77 . V_78 ) {
if ( ! F_47 ( V_76 -> V_70 , 1 ) )
V_9 -> V_77 . V_78 = 1 ;
else
V_9 -> V_77 . V_78 = 0 ;
}
V_9 -> V_77 . V_79 = 0 ;
F_48 ( V_76 , V_75 , true ) ;
}
static void F_49 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_54 * V_80 ;
T_2 V_25 , V_27 ;
F_29 ( V_9 ) ;
V_80 = V_29 -> V_57 ;
V_25 = V_29 -> V_81 ;
for (; V_25 != V_82 ; V_25 = V_27 ) {
V_27 = V_80 [ V_25 ] . V_83 ;
if ( V_80 [ V_25 ] . V_21 == V_21 ) {
struct V_21 * V_49 = F_42 ( V_9 ) ;
if ( V_49 ) {
V_80 [ V_25 ] . V_21 = V_49 ;
if ( ! F_34 ( V_80 [ V_25 ] . V_60 ,
V_84 ) ) {
V_29 -> V_57 [ V_25 ] . V_62 = 1 ;
V_29 -> V_63 = 1 ;
V_29 -> V_85 =
V_86 ;
}
} else {
V_80 [ V_25 ] . V_21 = NULL ;
}
}
}
F_30 ( V_9 ) ;
F_50 ( & V_9 -> V_87 ) ;
if ( V_21 != F_46 ( V_9 ) )
F_45 ( V_9 , V_21 -> V_70 -> V_88 ) ;
F_51 ( & V_9 -> V_87 ) ;
}
static void F_52 ( struct V_54 * V_55 )
{
int V_6 ;
if ( ! V_55 -> V_21 )
return;
for ( V_6 = 0 ; V_6 < V_89 ; V_6 ++ ) {
struct V_2 * V_3 ;
V_3 = F_53 ( V_69 , V_66 ,
V_55 -> V_59 ,
V_55 -> V_21 -> V_70 ,
V_55 -> V_56 ,
V_55 -> V_60 ,
V_55 -> V_21 -> V_70 -> V_88 ,
V_55 -> V_60 ) ;
if ( ! V_3 ) {
F_54 ( V_55 -> V_21 -> V_9 -> V_70 ,
L_2 ) ;
continue;
}
V_3 -> V_70 = V_55 -> V_21 -> V_70 ;
if ( V_55 -> V_90 ) {
V_3 = F_55 ( V_3 , F_40 ( V_91 ) , V_55 -> V_90 ) ;
if ( ! V_3 ) {
F_54 ( V_55 -> V_21 -> V_9 -> V_70 ,
L_3 ) ;
continue;
}
}
F_56 ( V_3 ) ;
}
}
static void F_57 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_54 * V_55 ;
T_2 V_46 ;
F_29 ( V_9 ) ;
V_46 = V_29 -> V_81 ;
for (; V_46 != V_82 ;
V_46 = V_55 -> V_83 ) {
V_55 = & ( V_29 -> V_57 [ V_46 ] ) ;
if ( V_55 -> V_62 ) {
F_52 ( V_55 ) ;
if ( V_29 -> V_85 == 0 )
V_55 -> V_62 = 0 ;
}
}
V_29 -> V_92 = V_93 ;
F_30 ( V_9 ) ;
}
static void F_58 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_54 * V_55 ;
int V_62 = 0 ;
T_2 V_46 ;
F_29 ( V_9 ) ;
V_46 = V_29 -> V_81 ;
for (; V_46 != V_82 ;
V_46 = V_55 -> V_83 ) {
V_55 = & ( V_29 -> V_57 [ V_46 ] ) ;
if ( ( V_55 -> V_21 == V_21 ) &&
! F_34 ( V_55 -> V_60 , V_84 ) ) {
V_55 -> V_62 = 1 ;
V_62 = 1 ;
}
}
if ( V_62 ) {
V_29 -> V_63 = 1 ;
V_29 -> V_85 = V_86 ;
}
F_30 ( V_9 ) ;
}
static void F_59 ( struct V_8 * V_9 , T_3 V_94 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_54 * V_55 ;
T_2 V_46 ;
F_31 ( V_9 ) ;
V_46 = V_29 -> V_81 ;
for (; V_46 != V_82 ;
V_46 = V_55 -> V_83 ) {
V_55 = & ( V_29 -> V_57 [ V_46 ] ) ;
if ( ! V_55 -> V_21 ) {
F_54 ( V_9 -> V_70 , L_4 ) ;
continue;
}
if ( ( V_55 -> V_56 == V_94 ) &&
! F_34 ( V_55 -> V_21 -> V_70 -> V_88 ,
V_9 -> V_70 -> V_88 ) &&
! F_34 ( V_55 -> V_60 , V_84 ) ) {
V_55 -> V_62 = 1 ;
V_29 -> V_63 = 1 ;
}
}
F_32 ( V_9 ) ;
}
static struct V_21 * F_60 ( struct V_2 * V_3 , struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_1 * V_53 = V_1 ( V_3 ) ;
struct V_21 * V_49 , * V_95 ;
struct V_54 * V_55 ;
T_2 V_46 = 0 ;
F_31 ( V_9 ) ;
V_95 = F_61 ( V_9 -> V_95 ) ;
V_46 = F_2 ( ( T_1 * ) & V_53 -> V_59 , sizeof( V_53 -> V_59 ) ) ;
V_55 = & ( V_29 -> V_57 [ V_46 ] ) ;
if ( V_55 -> V_58 ) {
if ( ( V_55 -> V_56 == V_53 -> V_56 ) &&
( V_55 -> V_59 == V_53 -> V_59 ) ) {
if ( ! F_34 ( V_53 -> V_60 , V_84 ) ) {
F_35 ( V_55 -> V_60 , V_53 -> V_60 ) ;
}
F_35 ( V_55 -> V_61 , V_53 -> V_61 ) ;
V_49 = V_55 -> V_21 ;
if ( V_49 ) {
F_32 ( V_9 ) ;
return V_49 ;
}
} else {
if ( V_95 &&
V_55 -> V_21 != V_95 ) {
V_55 -> V_21 = V_95 ;
F_52 ( V_55 ) ;
}
}
}
V_49 = F_44 ( V_9 ) ;
if ( V_49 ) {
if ( ! ( V_55 -> V_58 &&
V_55 -> V_56 == V_53 -> V_56 ) ) {
T_2 V_96 = F_2 ( ( T_1 * ) & V_53 -> V_56 ,
sizeof( V_53 -> V_56 ) ) ;
F_62 ( V_9 , V_46 ) ;
F_63 ( V_9 , V_96 , V_46 ) ;
}
V_55 -> V_56 = V_53 -> V_56 ;
V_55 -> V_59 = V_53 -> V_59 ;
F_35 ( V_55 -> V_60 , V_53 -> V_60 ) ;
F_35 ( V_55 -> V_61 , V_53 -> V_61 ) ;
V_55 -> V_21 = V_49 ;
if ( ! F_34 ( V_55 -> V_60 , V_84 ) ) {
V_55 -> V_62 = 1 ;
V_9 -> V_77 . V_63 = 1 ;
} else {
V_55 -> V_62 = 0 ;
}
if ( F_64 ( V_3 , & V_55 -> V_90 ) )
V_55 -> V_90 = 0 ;
if ( ! V_55 -> V_58 ) {
T_2 V_97 = V_29 -> V_81 ;
V_29 -> V_81 = V_46 ;
V_55 -> V_83 = V_97 ;
if ( V_97 != V_82 ) {
V_29 -> V_57 [ V_97 ] . V_98 =
V_46 ;
}
V_55 -> V_58 = 1 ;
}
}
F_32 ( V_9 ) ;
return V_49 ;
}
static struct V_21 * F_65 ( struct V_2 * V_3 , struct V_8 * V_9 )
{
struct V_1 * V_53 = V_1 ( V_3 ) ;
struct V_21 * V_17 = NULL ;
if ( ! F_66 ( V_9 , V_53 -> V_61 ) )
return NULL ;
if ( V_53 -> V_68 == F_40 ( V_69 ) ) {
V_17 = F_60 ( V_3 , V_9 ) ;
if ( V_17 )
F_35 ( V_53 -> V_61 , V_17 -> V_70 -> V_88 ) ;
F_41 ( V_9 -> V_70 , L_5 ) ;
} else if ( V_53 -> V_68 == F_40 ( V_99 ) ) {
F_60 ( V_3 , V_9 ) ;
V_9 -> V_77 . V_92 = V_93 ;
F_59 ( V_9 , V_53 -> V_56 ) ;
F_41 ( V_9 -> V_70 , L_6 ) ;
}
return V_17 ;
}
static void F_67 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_21 * V_49 ;
struct V_54 * V_55 ;
int V_62 ;
T_2 V_46 ;
F_29 ( V_9 ) ;
V_62 = 0 ;
V_46 = V_29 -> V_81 ;
for (; V_46 != V_82 ;
V_46 = V_55 -> V_83 ) {
V_55 = & ( V_29 -> V_57 [ V_46 ] ) ;
V_49 = F_44 ( V_9 ) ;
if ( V_49 && ( V_55 -> V_21 != V_49 ) ) {
V_55 -> V_21 = V_49 ;
V_55 -> V_62 = 1 ;
V_62 = 1 ;
}
}
if ( V_62 )
V_29 -> V_63 = 1 ;
F_30 ( V_9 ) ;
}
static void F_68 ( struct V_54 * V_12 )
{
V_12 -> V_83 = V_82 ;
V_12 -> V_98 = V_82 ;
V_12 -> V_58 = 0 ;
V_12 -> V_21 = NULL ;
V_12 -> V_90 = 0 ;
}
static void F_69 ( struct V_54 * V_12 )
{
V_12 -> V_100 = V_82 ;
V_12 -> V_101 = V_82 ;
V_12 -> V_102 = V_82 ;
}
static void F_70 ( struct V_54 * V_12 )
{
memset ( V_12 , 0 , sizeof( struct V_54 ) ) ;
F_68 ( V_12 ) ;
F_69 ( V_12 ) ;
}
static void F_71 ( struct V_8 * V_9 , T_2 V_25 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
T_2 V_27 = V_29 -> V_57 [ V_25 ] . V_83 ;
T_2 V_103 = V_29 -> V_57 [ V_25 ] . V_98 ;
if ( V_25 == V_29 -> V_81 )
V_29 -> V_81 = V_27 ;
if ( V_103 != V_82 )
V_29 -> V_57 [ V_103 ] . V_83 = V_27 ;
if ( V_27 != V_82 )
V_29 -> V_57 [ V_27 ] . V_98 = V_103 ;
}
static void F_62 ( struct V_8 * V_9 , T_2 V_25 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
T_2 V_27 = V_29 -> V_57 [ V_25 ] . V_102 ;
T_2 V_103 = V_29 -> V_57 [ V_25 ] . V_101 ;
V_29 -> V_57 [ V_25 ] . V_102 = V_82 ;
V_29 -> V_57 [ V_25 ] . V_101 = V_82 ;
if ( V_27 != V_82 )
V_29 -> V_57 [ V_27 ] . V_101 = V_103 ;
if ( V_103 == V_82 )
return;
if ( V_29 -> V_57 [ V_103 ] . V_100 == V_25 )
V_29 -> V_57 [ V_103 ] . V_100 = V_27 ;
else
V_29 -> V_57 [ V_103 ] . V_102 = V_27 ;
}
static void F_72 ( struct V_8 * V_9 , T_2 V_25 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_54 * V_12 = & ( V_29 -> V_57 [ V_25 ] ) ;
F_71 ( V_9 , V_25 ) ;
F_68 ( V_12 ) ;
F_62 ( V_9 , V_25 ) ;
}
static void F_63 ( struct V_8 * V_9 , T_2 V_104 , T_2 V_105 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
T_2 V_18 ;
V_29 -> V_57 [ V_105 ] . V_101 = V_104 ;
V_18 = V_29 -> V_57 [ V_104 ] . V_100 ;
V_29 -> V_57 [ V_105 ] . V_102 = V_18 ;
if ( V_18 != V_82 )
V_29 -> V_57 [ V_18 ] . V_101 = V_105 ;
V_29 -> V_57 [ V_104 ] . V_100 = V_105 ;
}
static void F_39 ( struct V_8 * V_9 , struct V_1 * V_53 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
T_2 V_104 = F_2 ( ( T_1 * ) & ( V_53 -> V_56 ) , sizeof( V_53 -> V_56 ) ) ;
T_2 V_25 ;
F_29 ( V_9 ) ;
V_25 = V_29 -> V_57 [ V_104 ] . V_100 ;
while ( V_25 != V_82 ) {
struct V_54 * V_12 = & ( V_29 -> V_57 [ V_25 ] ) ;
T_2 V_27 = V_12 -> V_102 ;
if ( V_12 -> V_56 == V_53 -> V_56 &&
! F_34 ( V_53 -> V_61 , V_12 -> V_61 ) )
F_72 ( V_9 , V_25 ) ;
V_25 = V_27 ;
}
F_30 ( V_9 ) ;
}
static int F_73 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_54 * V_32 ;
int V_30 = V_106 * sizeof( struct V_54 ) ;
int V_6 ;
V_32 = F_74 ( V_30 , V_33 ) ;
if ( ! V_32 )
return - 1 ;
F_29 ( V_9 ) ;
V_29 -> V_57 = V_32 ;
V_29 -> V_81 = V_82 ;
for ( V_6 = 0 ; V_6 < V_106 ; V_6 ++ )
F_70 ( V_29 -> V_57 + V_6 ) ;
F_30 ( V_9 ) ;
V_9 -> V_107 = F_36 ;
return 0 ;
}
static void F_75 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
F_29 ( V_9 ) ;
F_20 ( V_29 -> V_57 ) ;
V_29 -> V_57 = NULL ;
V_29 -> V_81 = V_82 ;
F_30 ( V_9 ) ;
}
static void F_76 ( struct V_8 * V_9 , unsigned short V_90 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
T_2 V_108 ;
F_29 ( V_9 ) ;
V_108 = V_29 -> V_81 ;
while ( V_108 != V_82 ) {
struct V_54 * V_109 = & ( V_29 -> V_57 [ V_108 ] ) ;
T_2 V_27 = V_29 -> V_57 [ V_108 ] . V_83 ;
if ( V_109 -> V_90 == V_90 )
F_72 ( V_9 , V_108 ) ;
V_108 = V_27 ;
}
F_30 ( V_9 ) ;
}
static void F_77 ( struct V_21 * V_21 , T_1 V_110 [] ,
T_4 V_111 , T_5 V_112 )
{
struct V_113 V_114 ;
struct V_2 * V_3 ;
int V_30 = sizeof( struct V_113 ) ;
char * V_115 ;
memset ( & V_114 , 0 , V_30 ) ;
F_35 ( V_114 . V_60 , V_110 ) ;
F_35 ( V_114 . V_61 , V_110 ) ;
V_114 . type = F_37 ( V_116 ) ;
V_3 = F_78 ( V_30 ) ;
if ( ! V_3 )
return;
V_115 = F_79 ( V_3 , V_30 ) ;
memcpy ( V_115 , & V_114 , V_30 ) ;
F_80 ( V_3 ) ;
V_3 -> V_117 = V_3 -> V_118 + V_119 ;
V_3 -> V_65 = V_114 . type ;
V_3 -> V_120 = V_121 ;
V_3 -> V_70 = V_21 -> V_70 ;
if ( V_112 ) {
V_3 = F_55 ( V_3 , V_111 , V_112 ) ;
if ( ! V_3 ) {
F_54 ( V_21 -> V_9 -> V_70 , L_3 ) ;
return;
}
}
F_81 ( V_3 ) ;
}
static void F_48 ( struct V_21 * V_21 , T_1 V_110 [] ,
bool V_122 )
{
struct V_8 * V_9 = F_82 ( V_21 ) ;
struct V_123 * V_124 ;
struct V_41 * V_42 ;
struct V_125 * V_126 ;
F_77 ( V_21 , V_110 , 0 , 0 ) ;
F_83 () ;
F_84 (bond->dev, upper, iter) {
if ( F_85 ( V_124 ) && F_86 ( V_124 ) == 0 ) {
if ( V_122 &&
F_34 ( V_110 ,
V_124 -> V_88 ) ) {
F_77 ( V_21 , V_110 ,
F_87 ( V_124 ) ,
F_88 ( V_124 ) ) ;
} else if ( ! V_122 ) {
F_77 ( V_21 , V_124 -> V_88 ,
F_87 ( V_124 ) ,
F_88 ( V_124 ) ) ;
}
}
if ( F_89 ( V_124 ) && ! V_122 ) {
V_126 = F_90 ( V_9 -> V_70 , V_124 , 0 ) ;
if ( F_91 ( V_126 ) )
F_92 () ;
F_77 ( V_21 , V_124 -> V_88 ,
V_126 [ 0 ] . V_111 , V_126 [ 0 ] . V_90 ) ;
F_20 ( V_126 ) ;
}
}
F_93 () ;
}
static int F_94 ( struct V_21 * V_21 , T_1 V_75 [] )
{
struct V_123 * V_70 = V_21 -> V_70 ;
struct V_127 V_128 ;
if ( F_95 ( V_21 -> V_9 ) == V_129 ) {
memcpy ( V_70 -> V_88 , V_75 , V_70 -> V_130 ) ;
return 0 ;
}
memcpy ( V_128 . V_131 , V_75 , V_70 -> V_130 ) ;
V_128 . V_132 = V_70 -> type ;
if ( F_96 ( V_70 , & V_128 ) ) {
F_54 ( V_21 -> V_9 -> V_70 , L_7 ,
V_70 -> V_133 ) ;
return - V_134 ;
}
return 0 ;
}
static void F_97 ( struct V_21 * V_135 , struct V_21 * V_136 )
{
T_1 V_137 [ V_138 ] ;
F_35 ( V_137 , V_135 -> V_70 -> V_88 ) ;
F_94 ( V_135 , V_136 -> V_70 -> V_88 ) ;
F_94 ( V_136 , V_137 ) ;
}
static void F_98 ( struct V_8 * V_9 , struct V_21 * V_135 ,
struct V_21 * V_136 )
{
int V_139 = ( F_26 ( V_135 ) != F_26 ( V_136 ) ) ;
struct V_21 * V_140 = NULL ;
F_99 () ;
if ( F_26 ( V_135 ) ) {
F_48 ( V_135 , V_135 -> V_70 -> V_88 , false ) ;
if ( V_9 -> V_77 . V_141 ) {
F_58 ( V_9 , V_135 ) ;
}
} else {
V_140 = V_135 ;
}
if ( F_26 ( V_136 ) ) {
F_48 ( V_136 , V_136 -> V_70 -> V_88 , false ) ;
if ( V_9 -> V_77 . V_141 ) {
F_58 ( V_9 , V_136 ) ;
}
} else {
V_140 = V_136 ;
}
if ( V_9 -> V_77 . V_141 && V_139 ) {
F_45 ( V_9 ,
V_140 -> V_70 -> V_88 ) ;
}
}
static void F_100 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
int V_142 ;
int V_143 ;
struct V_21 * V_144 ;
V_142 = ! F_34 ( V_21 -> V_145 ,
V_21 -> V_70 -> V_88 ) ;
V_143 = ! F_34 ( V_21 -> V_145 ,
V_9 -> V_70 -> V_88 ) ;
if ( V_142 && V_143 ) {
V_144 = F_101 ( V_9 , V_21 -> V_145 ) ;
if ( V_144 ) {
F_97 ( V_21 , V_144 ) ;
F_98 ( V_9 , V_21 , V_144 ) ;
}
}
}
static int F_102 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
struct V_21 * V_146 = F_103 ( V_9 -> V_95 ) ;
struct V_21 * V_147 , * V_148 = NULL ;
struct V_41 * V_42 ;
if ( ! F_104 ( V_9 ) ) {
return 0 ;
}
if ( ! F_34 ( V_21 -> V_145 , V_9 -> V_70 -> V_88 ) ) {
if ( ! F_101 ( V_9 , V_21 -> V_70 -> V_88 ) )
return 0 ;
F_94 ( V_21 , V_9 -> V_70 -> V_88 ) ;
}
F_43 (bond, tmp_slave1, iter) {
if ( ! F_101 ( V_9 , V_147 -> V_145 ) ) {
V_148 = V_147 ;
break;
}
if ( ! V_146 ) {
if ( F_34 ( V_147 -> V_70 -> V_88 ,
V_9 -> V_70 -> V_88 ) ) {
V_146 = V_147 ;
}
}
}
if ( V_148 ) {
F_94 ( V_21 , V_148 -> V_145 ) ;
F_105 ( V_9 -> V_70 , L_8 ,
V_21 -> V_70 -> V_133 , V_148 -> V_70 -> V_133 ) ;
} else if ( V_146 ) {
F_54 ( V_9 -> V_70 , L_9 ,
V_21 -> V_70 -> V_133 ) ;
return - V_149 ;
}
return 0 ;
}
static int F_106 ( struct V_8 * V_9 , void * V_75 )
{
struct V_21 * V_21 , * V_150 ;
struct V_41 * V_42 ;
struct V_127 V_151 ;
char V_152 [ V_138 ] ;
int V_153 ;
if ( V_9 -> V_77 . V_141 )
return 0 ;
F_43 (bond, slave, iter) {
F_35 ( V_152 , V_21 -> V_70 -> V_88 ) ;
V_153 = F_96 ( V_21 -> V_70 , V_75 ) ;
F_35 ( V_21 -> V_70 -> V_88 , V_152 ) ;
if ( V_153 )
goto V_154;
}
return 0 ;
V_154:
memcpy ( V_151 . V_131 , V_9 -> V_70 -> V_88 , V_9 -> V_70 -> V_130 ) ;
V_151 . V_132 = V_9 -> V_70 -> type ;
F_43 (bond, rollback_slave, iter) {
if ( V_150 == V_21 )
break;
F_35 ( V_152 , V_150 -> V_70 -> V_88 ) ;
F_96 ( V_150 -> V_70 , & V_151 ) ;
F_35 ( V_150 -> V_70 -> V_88 , V_152 ) ;
}
return V_153 ;
}
int F_107 ( struct V_8 * V_9 , int V_141 )
{
int V_153 ;
V_153 = F_17 ( V_9 ) ;
if ( V_153 )
return V_153 ;
if ( V_141 ) {
V_9 -> V_77 . V_141 = 1 ;
V_153 = F_73 ( V_9 ) ;
if ( V_153 ) {
F_19 ( V_9 ) ;
return V_153 ;
}
} else {
V_9 -> V_77 . V_141 = 0 ;
}
return 0 ;
}
void F_108 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
F_19 ( V_9 ) ;
if ( V_29 -> V_141 )
F_75 ( V_9 ) ;
}
static int F_109 ( struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_21 * V_17 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_155 * V_156 = F_110 ( V_3 ) ;
if ( ! V_17 ) {
V_17 = F_61 ( V_9 -> V_95 ) ;
if ( V_9 -> V_157 . V_158 )
V_29 -> V_159 += V_3 -> V_160 ;
}
if ( V_17 && F_26 ( V_17 ) ) {
if ( V_17 != F_61 ( V_9 -> V_95 ) ) {
F_35 ( V_156 -> V_161 ,
V_17 -> V_70 -> V_88 ) ;
}
F_111 ( V_9 , V_3 , V_17 -> V_70 ) ;
goto V_67;
}
if ( V_17 && V_9 -> V_157 . V_158 ) {
F_8 ( V_9 ) ;
F_15 ( V_9 , V_17 , 0 ) ;
F_10 ( V_9 ) ;
}
F_112 ( V_3 ) ;
V_67:
return V_162 ;
}
static int F_113 ( struct V_8 * V_9 ,
struct V_21 * V_163 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_21 * V_17 ;
struct V_41 * V_42 ;
struct V_34 * V_164 , * V_165 ;
V_164 = F_18 ( F_114 ( struct V_34 , V_35 [ V_9 -> V_166 ] ) ,
V_167 ) ;
if ( ! V_164 )
return - V_168 ;
F_43 (bond, tx_slave, iter) {
if ( ! F_26 ( V_17 ) )
continue;
if ( V_163 == V_17 )
continue;
V_164 -> V_35 [ V_164 -> V_169 ++ ] = V_17 ;
}
V_165 = F_21 ( V_29 -> V_36 ) ;
F_115 ( V_29 -> V_36 , V_164 ) ;
if ( V_165 )
F_22 ( V_165 , V_37 ) ;
return 0 ;
}
int F_116 ( struct V_2 * V_3 , struct V_123 * V_170 )
{
struct V_8 * V_9 = F_117 ( V_170 ) ;
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_155 * V_156 ;
struct V_21 * V_17 = NULL ;
T_2 V_46 ;
F_80 ( V_3 ) ;
V_156 = F_110 ( V_3 ) ;
if ( ! F_118 ( V_156 -> V_171 ) ) {
switch ( V_3 -> V_65 ) {
case F_40 ( V_172 ) :
case F_40 ( V_173 ) :
case F_40 ( V_174 ) :
V_46 = F_119 ( V_9 , V_3 ) ;
if ( V_9 -> V_157 . V_158 ) {
V_17 = F_28 ( V_9 ,
V_46 & 0xFF ,
V_3 -> V_160 ) ;
} else {
struct V_34 * V_175 ;
V_175 = F_61 ( V_29 -> V_36 ) ;
if ( V_175 && V_175 -> V_169 )
V_17 = V_175 -> V_35 [ V_46 %
V_175 -> V_169 ] ;
}
break;
}
}
return F_109 ( V_3 , V_9 , V_17 ) ;
}
int F_120 ( struct V_2 * V_3 , struct V_123 * V_170 )
{
struct V_8 * V_9 = F_117 ( V_170 ) ;
struct V_155 * V_156 ;
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_21 * V_17 = NULL ;
static const T_3 V_176 = F_121 ( 0xffffffff ) ;
int V_5 = 0 ;
bool V_177 = true ;
T_2 V_46 = 0 ;
const T_1 * V_4 = NULL ;
struct V_178 * V_179 ;
F_80 ( V_3 ) ;
V_156 = F_110 ( V_3 ) ;
switch ( F_122 ( V_3 -> V_65 ) ) {
case V_172 : {
const struct V_180 * V_181 = F_123 ( V_3 ) ;
if ( F_34 ( V_156 -> V_171 , V_84 ) ||
( V_181 -> V_182 == V_176 ) ||
( V_181 -> V_65 == V_183 ) ) {
V_177 = false ;
break;
}
V_4 = ( char * ) & ( V_181 -> V_182 ) ;
V_5 = sizeof( V_181 -> V_182 ) ;
}
break;
case V_174 :
if ( F_34 ( V_156 -> V_171 , V_84 ) ) {
V_177 = false ;
break;
}
if ( F_34 ( V_156 -> V_171 , V_184 ) ) {
V_177 = false ;
break;
}
V_179 = F_124 ( V_3 ) ;
if ( F_125 ( & V_179 -> V_185 ) ) {
V_177 = false ;
break;
}
V_4 = ( char * ) & ( F_124 ( V_3 ) -> V_182 ) ;
V_5 = sizeof( F_124 ( V_3 ) -> V_182 ) ;
break;
case V_173 :
if ( F_126 ( V_3 ) -> V_186 != V_187 ) {
V_177 = false ;
break;
}
if ( F_126 ( V_3 ) -> V_188 != V_189 ) {
V_177 = false ;
break;
}
V_4 = ( char * ) V_156 -> V_171 ;
V_5 = V_138 ;
break;
case V_66 :
V_177 = false ;
if ( V_29 -> V_141 )
V_17 = F_65 ( V_3 , V_9 ) ;
break;
default:
V_177 = false ;
break;
}
if ( V_177 ) {
V_46 = F_2 ( V_4 , V_5 ) ;
V_17 = F_28 ( V_9 , V_46 , V_3 -> V_160 ) ;
}
return F_109 ( V_3 , V_9 , V_17 ) ;
}
void F_127 ( struct V_190 * V_191 )
{
struct V_8 * V_9 = F_128 ( V_191 , struct V_8 ,
V_192 . V_191 ) ;
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_41 * V_42 ;
struct V_21 * V_21 ;
if ( ! F_104 ( V_9 ) ) {
V_29 -> V_193 = 0 ;
V_29 -> V_194 = 0 ;
goto V_195;
}
F_83 () ;
V_29 -> V_193 ++ ;
V_29 -> V_194 ++ ;
if ( V_29 -> V_194 >= F_129 ( V_9 ) ) {
bool V_122 ;
F_130 ( & V_9 -> V_87 ) ;
F_25 (bond, slave, iter) {
V_122 = ( V_21 != F_103 ( V_9 -> V_95 ) ||
V_29 -> V_141 ) ;
F_48 ( V_21 , V_21 -> V_70 -> V_88 ,
V_122 ) ;
}
F_131 ( & V_9 -> V_87 ) ;
V_29 -> V_194 = 0 ;
}
if ( V_29 -> V_193 >= V_196 ) {
F_130 ( & V_9 -> V_87 ) ;
F_25 (bond, slave, iter) {
F_16 ( V_9 , V_21 , 1 ) ;
if ( V_21 == F_103 ( V_9 -> V_95 ) ) {
F_14 ( V_21 ) . V_22 =
V_29 -> V_159 /
V_16 ;
V_29 -> V_159 = 0 ;
}
}
F_131 ( & V_9 -> V_87 ) ;
V_29 -> V_193 = 0 ;
}
if ( V_29 -> V_141 ) {
if ( V_29 -> V_78 &&
( ++ V_29 -> V_79 >= V_197 ) ) {
F_93 () ;
if ( ! F_132 () )
goto V_195;
V_29 -> V_79 = 0 ;
F_47 ( F_21 ( V_9 -> V_95 ) -> V_70 ,
- 1 ) ;
V_29 -> V_78 = 0 ;
F_133 () ;
F_83 () ;
}
if ( V_29 -> F_67 ) {
V_29 -> F_67 = 0 ;
F_67 ( V_9 ) ;
}
if ( V_29 -> V_63 ) {
if ( V_29 -> V_92 ) {
-- V_29 -> V_92 ;
} else {
F_57 ( V_9 ) ;
if ( V_29 -> V_85 )
-- V_29 -> V_85 ;
else
V_29 -> V_63 = 0 ;
}
}
}
F_93 () ;
V_195:
F_134 ( V_9 -> V_198 , & V_9 -> V_192 , V_199 ) ;
}
int F_135 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
int V_153 ;
V_153 = F_94 ( V_21 , V_21 -> V_145 ) ;
if ( V_153 )
return V_153 ;
V_153 = F_102 ( V_9 , V_21 ) ;
if ( V_153 )
return V_153 ;
F_13 ( V_21 ) ;
V_9 -> V_77 . V_193 = V_196 ;
if ( V_9 -> V_77 . V_141 )
V_9 -> V_77 . F_67 = 1 ;
return 0 ;
}
void F_136 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
if ( F_104 ( V_9 ) )
F_100 ( V_9 , V_21 ) ;
F_16 ( V_9 , V_21 , 0 ) ;
if ( V_9 -> V_77 . V_141 ) {
V_9 -> V_77 . V_73 = NULL ;
F_49 ( V_9 , V_21 ) ;
}
if ( F_137 ( V_9 ) )
if ( F_113 ( V_9 , V_21 ) )
F_138 ( L_10 ) ;
}
void F_139 ( struct V_8 * V_9 , struct V_21 * V_21 , char V_200 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
if ( V_200 == V_201 ) {
F_16 ( V_9 , V_21 , 0 ) ;
if ( V_9 -> V_77 . V_141 )
F_49 ( V_9 , V_21 ) ;
} else if ( V_200 == V_202 ) {
V_29 -> V_193 = V_196 ;
if ( V_9 -> V_77 . V_141 ) {
V_9 -> V_77 . F_67 = 1 ;
}
}
if ( F_137 ( V_9 ) ) {
if ( F_113 ( V_9 , NULL ) )
F_138 ( L_10 ) ;
}
}
void F_140 ( struct V_8 * V_9 , struct V_21 * V_203 )
__releases( &bond->curr_slave_lock
int F_141 ( struct V_123 * V_170 , void * V_75 )
__acquires( &bond->lock
void F_142 ( struct V_8 * V_9 , unsigned short V_90 )
{
if ( V_9 -> V_77 . V_141 )
F_76 ( V_9 , V_90 ) ;
}
