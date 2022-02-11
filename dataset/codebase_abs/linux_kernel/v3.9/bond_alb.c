static inline struct V_1 * V_1 ( const struct V_2 * V_3 )
{
return (struct V_1 * ) F_1 ( V_3 ) ;
}
static inline T_1 F_2 ( const T_1 * V_4 , int V_5 )
{
int V_6 ;
T_1 V_7 = 0 ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ ) {
V_7 ^= V_4 [ V_6 ] ;
}
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
for ( V_6 = 0 ; V_6 < V_31 ; V_6 ++ ) {
F_12 ( & V_29 -> V_26 [ V_6 ] , 0 ) ;
}
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
long long V_37 ;
int V_6 ;
V_36 = NULL ;
V_37 = V_38 ;
F_23 (bond, slave, i) {
if ( F_24 ( V_21 ) ) {
long long V_39 = F_21 ( V_21 ) ;
if ( V_37 < V_39 ) {
V_36 = V_21 ;
V_37 = V_39 ;
}
}
}
return V_36 ;
}
static struct V_21 * F_25 ( struct V_8 * V_9 , T_2 V_40 ,
T_2 V_41 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_11 * V_42 ;
struct V_21 * V_43 ;
V_42 = V_29 -> V_26 ;
V_43 = V_42 [ V_40 ] . V_17 ;
if ( ! V_43 ) {
V_43 = F_22 ( V_9 ) ;
if ( V_43 ) {
struct V_44 * V_45 =
& ( F_14 ( V_43 ) ) ;
T_2 V_27 = V_45 -> V_23 ;
V_42 [ V_40 ] . V_17 = V_43 ;
V_42 [ V_40 ] . V_18 = V_27 ;
V_42 [ V_40 ] . V_20 = V_19 ;
if ( V_27 != V_19 ) {
V_42 [ V_27 ] . V_20 = V_40 ;
}
V_45 -> V_23 = V_40 ;
V_45 -> V_22 +=
V_42 [ V_40 ] . V_14 ;
}
}
if ( V_43 ) {
V_42 [ V_40 ] . V_15 += V_41 ;
}
return V_43 ;
}
static struct V_21 * F_26 ( struct V_8 * V_9 , T_2 V_40 ,
T_2 V_41 )
{
struct V_21 * V_17 ;
F_8 ( V_9 ) ;
V_17 = F_25 ( V_9 , V_40 , V_41 ) ;
F_10 ( V_9 ) ;
return V_17 ;
}
static inline void F_27 ( struct V_8 * V_9 )
{
F_4 ( & ( F_5 ( V_9 ) . V_46 ) ) ;
}
static inline void F_28 ( struct V_8 * V_9 )
{
F_7 ( & ( F_5 ( V_9 ) . V_46 ) ) ;
}
static inline void F_29 ( struct V_8 * V_9 )
{
F_9 ( & ( F_5 ( V_9 ) . V_46 ) ) ;
}
static inline void F_30 ( struct V_8 * V_9 )
{
F_11 ( & ( F_5 ( V_9 ) . V_46 ) ) ;
}
static void F_31 ( struct V_8 * V_9 , struct V_1 * V_47 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_48 * V_49 ;
T_2 V_40 ;
F_27 ( V_9 ) ;
V_40 = F_2 ( ( T_1 * ) & ( V_47 -> V_50 ) , sizeof( V_47 -> V_50 ) ) ;
V_49 = & ( V_29 -> V_51 [ V_40 ] ) ;
if ( ( V_49 -> V_52 ) &&
( V_49 -> V_50 == V_47 -> V_53 ) &&
( V_49 -> V_53 == V_47 -> V_50 ) &&
( ! F_32 ( V_49 -> V_54 , V_47 -> V_55 ) ) ) {
memcpy ( V_49 -> V_54 , V_47 -> V_55 , V_56 ) ;
V_49 -> V_57 = 1 ;
V_29 -> V_58 = 1 ;
}
F_28 ( V_9 ) ;
}
static int F_33 ( const struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_21 * V_21 )
{
struct V_1 * V_47 , V_59 ;
if ( V_3 -> V_60 != F_34 ( V_61 ) )
goto V_62;
V_47 = F_35 ( V_3 , 0 , sizeof( V_59 ) , & V_59 ) ;
if ( ! V_47 )
goto V_62;
F_36 ( V_9 , V_47 ) ;
if ( V_47 -> V_63 == F_37 ( V_64 ) ) {
F_31 ( V_9 , V_47 ) ;
F_38 ( L_1 ) ;
}
V_62:
return V_65 ;
}
static struct V_21 * F_39 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_21 * V_66 , * V_21 , * V_67 ;
int V_6 = 0 ;
if ( V_29 -> V_68 ) {
V_67 = V_29 -> V_68 ;
} else {
V_67 = V_9 -> V_69 ;
}
V_66 = NULL ;
F_40 (bond, slave, i, start_at) {
if ( F_24 ( V_21 ) ) {
if ( ! V_66 ) {
V_66 = V_21 ;
} else if ( V_21 -> V_35 > V_66 -> V_35 ) {
V_66 = V_21 ;
}
}
}
if ( V_66 ) {
V_29 -> V_68 = V_66 -> V_18 ;
}
return V_66 ;
}
static void F_41 ( struct V_8 * V_9 , T_1 V_70 [] )
{
if ( ! V_9 -> V_71 ) {
return;
}
if ( ! V_9 -> V_72 . V_73 ) {
if ( ! F_42 ( V_9 -> V_71 -> V_74 , 1 ) )
V_9 -> V_72 . V_73 = 1 ;
else
V_9 -> V_72 . V_73 = 0 ;
}
V_9 -> V_72 . V_75 = 0 ;
F_43 ( V_9 -> V_71 , V_70 ) ;
}
static void F_44 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_48 * V_76 ;
T_2 V_25 , V_27 ;
F_27 ( V_9 ) ;
V_76 = V_29 -> V_51 ;
V_25 = V_29 -> V_77 ;
for (; V_25 != V_78 ; V_25 = V_27 ) {
V_27 = V_76 [ V_25 ] . V_79 ;
if ( V_76 [ V_25 ] . V_21 == V_21 ) {
struct V_21 * V_43 = F_39 ( V_9 ) ;
if ( V_43 ) {
V_76 [ V_25 ] . V_21 = V_43 ;
if ( ! F_32 ( V_76 [ V_25 ] . V_54 ,
V_80 ) ) {
V_29 -> V_51 [ V_25 ] . V_57 = 1 ;
V_29 -> V_58 = 1 ;
V_29 -> V_81 =
V_82 ;
}
} else {
V_76 [ V_25 ] . V_21 = NULL ;
}
}
}
F_28 ( V_9 ) ;
F_45 ( & V_9 -> V_83 ) ;
if ( V_21 != V_9 -> V_71 ) {
F_41 ( V_9 , V_21 -> V_74 -> V_84 ) ;
}
F_46 ( & V_9 -> V_83 ) ;
}
static void F_47 ( struct V_48 * V_49 )
{
int V_6 ;
if ( ! V_49 -> V_21 ) {
return;
}
for ( V_6 = 0 ; V_6 < V_85 ; V_6 ++ ) {
struct V_2 * V_3 ;
V_3 = F_48 ( V_64 , V_61 ,
V_49 -> V_53 ,
V_49 -> V_21 -> V_74 ,
V_49 -> V_50 ,
V_49 -> V_54 ,
V_49 -> V_21 -> V_74 -> V_84 ,
V_49 -> V_54 ) ;
if ( ! V_3 ) {
F_49 ( L_2 ,
V_49 -> V_21 -> V_9 -> V_74 -> V_86 ) ;
continue;
}
V_3 -> V_74 = V_49 -> V_21 -> V_74 ;
if ( V_49 -> V_87 ) {
V_3 = F_50 ( V_3 , V_49 -> V_88 ) ;
if ( ! V_3 ) {
F_49 ( L_3 ,
V_49 -> V_21 -> V_9 -> V_74 -> V_86 ) ;
continue;
}
}
F_51 ( V_3 ) ;
}
}
static void F_52 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_48 * V_49 ;
T_2 V_40 ;
F_27 ( V_9 ) ;
V_40 = V_29 -> V_77 ;
for (; V_40 != V_78 ;
V_40 = V_49 -> V_79 ) {
V_49 = & ( V_29 -> V_51 [ V_40 ] ) ;
if ( V_49 -> V_57 ) {
F_47 ( V_49 ) ;
if ( V_29 -> V_81 == 0 ) {
V_49 -> V_57 = 0 ;
}
}
}
V_29 -> V_89 = V_90 ;
F_28 ( V_9 ) ;
}
static void F_53 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_48 * V_49 ;
int V_57 = 0 ;
T_2 V_40 ;
F_27 ( V_9 ) ;
V_40 = V_29 -> V_77 ;
for (; V_40 != V_78 ;
V_40 = V_49 -> V_79 ) {
V_49 = & ( V_29 -> V_51 [ V_40 ] ) ;
if ( ( V_49 -> V_21 == V_21 ) &&
! F_32 ( V_49 -> V_54 , V_80 ) ) {
V_49 -> V_57 = 1 ;
V_57 = 1 ;
}
}
if ( V_57 ) {
V_29 -> V_58 = 1 ;
V_29 -> V_81 = V_82 ;
}
F_28 ( V_9 ) ;
}
static void F_54 ( struct V_8 * V_9 , T_3 V_91 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_48 * V_49 ;
T_2 V_40 ;
F_29 ( V_9 ) ;
V_40 = V_29 -> V_77 ;
for (; V_40 != V_78 ;
V_40 = V_49 -> V_79 ) {
V_49 = & ( V_29 -> V_51 [ V_40 ] ) ;
if ( ! V_49 -> V_21 ) {
F_49 ( L_4 ,
V_9 -> V_74 -> V_86 ) ;
continue;
}
if ( ( V_49 -> V_50 == V_91 ) &&
! F_32 ( V_49 -> V_21 -> V_74 -> V_84 ,
V_9 -> V_74 -> V_84 ) &&
! F_32 ( V_49 -> V_54 , V_80 ) ) {
V_49 -> V_57 = 1 ;
V_29 -> V_58 = 1 ;
}
}
F_30 ( V_9 ) ;
}
static struct V_21 * F_55 ( struct V_2 * V_3 , struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_1 * V_47 = V_1 ( V_3 ) ;
struct V_21 * V_43 ;
struct V_48 * V_49 ;
T_2 V_40 = 0 ;
F_29 ( V_9 ) ;
V_40 = F_2 ( ( T_1 * ) & V_47 -> V_53 , sizeof( V_47 -> V_53 ) ) ;
V_49 = & ( V_29 -> V_51 [ V_40 ] ) ;
if ( V_49 -> V_52 ) {
if ( ( V_49 -> V_50 == V_47 -> V_50 ) &&
( V_49 -> V_53 == V_47 -> V_53 ) ) {
if ( ! F_32 ( V_47 -> V_54 , V_80 ) ) {
memcpy ( V_49 -> V_54 , V_47 -> V_54 , V_56 ) ;
}
memcpy ( V_49 -> V_55 , V_47 -> V_55 , V_56 ) ;
V_43 = V_49 -> V_21 ;
if ( V_43 ) {
F_30 ( V_9 ) ;
return V_43 ;
}
} else {
if ( V_9 -> V_71 &&
V_49 -> V_21 != V_9 -> V_71 ) {
V_49 -> V_21 = V_9 -> V_71 ;
F_47 ( V_49 ) ;
}
}
}
V_43 = F_39 ( V_9 ) ;
if ( V_43 ) {
if ( ! ( V_49 -> V_52 &&
V_49 -> V_50 == V_47 -> V_50 ) ) {
T_2 V_92 = F_2 ( ( T_1 * ) & V_47 -> V_50 ,
sizeof( V_47 -> V_50 ) ) ;
F_56 ( V_9 , V_40 ) ;
F_57 ( V_9 , V_92 , V_40 ) ;
}
V_49 -> V_50 = V_47 -> V_50 ;
V_49 -> V_53 = V_47 -> V_53 ;
memcpy ( V_49 -> V_54 , V_47 -> V_54 , V_56 ) ;
memcpy ( V_49 -> V_55 , V_47 -> V_55 , V_56 ) ;
V_49 -> V_21 = V_43 ;
if ( ! F_32 ( V_49 -> V_54 , V_80 ) ) {
V_49 -> V_57 = 1 ;
V_9 -> V_72 . V_58 = 1 ;
} else {
V_49 -> V_57 = 0 ;
}
if ( F_58 ( V_9 ) ) {
if ( ! F_59 ( V_3 , & V_49 -> V_88 ) )
V_49 -> V_87 = 1 ;
}
if ( ! V_49 -> V_52 ) {
T_2 V_93 = V_29 -> V_77 ;
V_29 -> V_77 = V_40 ;
V_49 -> V_79 = V_93 ;
if ( V_93 != V_78 ) {
V_29 -> V_51 [ V_93 ] . V_94 =
V_40 ;
}
V_49 -> V_52 = 1 ;
}
}
F_30 ( V_9 ) ;
return V_43 ;
}
static struct V_21 * F_60 ( struct V_2 * V_3 , struct V_8 * V_9 )
{
struct V_1 * V_47 = V_1 ( V_3 ) ;
struct V_21 * V_17 = NULL ;
if ( ! F_61 ( V_9 , V_47 -> V_55 ) )
return NULL ;
if ( V_47 -> V_63 == F_37 ( V_64 ) ) {
V_17 = F_55 ( V_3 , V_9 ) ;
if ( V_17 ) {
memcpy ( V_47 -> V_55 , V_17 -> V_74 -> V_84 , V_56 ) ;
}
F_38 ( L_5 ) ;
} else if ( V_47 -> V_63 == F_37 ( V_95 ) ) {
F_55 ( V_3 , V_9 ) ;
V_9 -> V_72 . V_89 = V_90 ;
F_54 ( V_9 , V_47 -> V_50 ) ;
F_38 ( L_6 ) ;
}
return V_17 ;
}
static void F_62 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_21 * V_43 ;
struct V_48 * V_49 ;
int V_57 ;
T_2 V_40 ;
F_27 ( V_9 ) ;
V_57 = 0 ;
V_40 = V_29 -> V_77 ;
for (; V_40 != V_78 ;
V_40 = V_49 -> V_79 ) {
V_49 = & ( V_29 -> V_51 [ V_40 ] ) ;
V_43 = F_39 ( V_9 ) ;
if ( V_43 && ( V_49 -> V_21 != V_43 ) ) {
V_49 -> V_21 = V_43 ;
V_49 -> V_57 = 1 ;
V_57 = 1 ;
}
}
if ( V_57 ) {
V_29 -> V_58 = 1 ;
}
F_28 ( V_9 ) ;
}
static void F_63 ( struct V_48 * V_12 )
{
V_12 -> V_79 = V_78 ;
V_12 -> V_94 = V_78 ;
V_12 -> V_52 = 0 ;
V_12 -> V_21 = NULL ;
V_12 -> V_87 = 0 ;
}
static void F_64 ( struct V_48 * V_12 )
{
V_12 -> V_96 = V_78 ;
V_12 -> V_97 = V_78 ;
V_12 -> V_98 = V_78 ;
}
static void F_65 ( struct V_48 * V_12 )
{
memset ( V_12 , 0 , sizeof( struct V_48 ) ) ;
F_63 ( V_12 ) ;
F_64 ( V_12 ) ;
}
static void F_66 ( struct V_8 * V_9 , T_2 V_25 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
T_2 V_27 = V_29 -> V_51 [ V_25 ] . V_79 ;
T_2 V_99 = V_29 -> V_51 [ V_25 ] . V_94 ;
if ( V_25 == V_29 -> V_77 )
V_29 -> V_77 = V_27 ;
if ( V_99 != V_78 )
V_29 -> V_51 [ V_99 ] . V_79 = V_27 ;
if ( V_27 != V_78 )
V_29 -> V_51 [ V_27 ] . V_94 = V_99 ;
}
static void F_56 ( struct V_8 * V_9 , T_2 V_25 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
T_2 V_27 = V_29 -> V_51 [ V_25 ] . V_98 ;
T_2 V_99 = V_29 -> V_51 [ V_25 ] . V_97 ;
V_29 -> V_51 [ V_25 ] . V_98 = V_78 ;
V_29 -> V_51 [ V_25 ] . V_97 = V_78 ;
if ( V_27 != V_78 )
V_29 -> V_51 [ V_27 ] . V_97 = V_99 ;
if ( V_99 == V_78 )
return;
if ( V_29 -> V_51 [ V_99 ] . V_96 == V_25 )
V_29 -> V_51 [ V_99 ] . V_96 = V_27 ;
else
V_29 -> V_51 [ V_99 ] . V_98 = V_27 ;
}
static void F_67 ( struct V_8 * V_9 , T_2 V_25 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_48 * V_12 = & ( V_29 -> V_51 [ V_25 ] ) ;
F_66 ( V_9 , V_25 ) ;
F_63 ( V_12 ) ;
F_56 ( V_9 , V_25 ) ;
}
static void F_57 ( struct V_8 * V_9 , T_2 V_100 , T_2 V_101 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
T_2 V_18 ;
V_29 -> V_51 [ V_101 ] . V_97 = V_100 ;
V_18 = V_29 -> V_51 [ V_100 ] . V_96 ;
V_29 -> V_51 [ V_101 ] . V_98 = V_18 ;
if ( V_18 != V_78 )
V_29 -> V_51 [ V_18 ] . V_97 = V_101 ;
V_29 -> V_51 [ V_100 ] . V_96 = V_101 ;
}
static void F_36 ( struct V_8 * V_9 , struct V_1 * V_47 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
T_2 V_100 = F_2 ( ( T_1 * ) & ( V_47 -> V_50 ) , sizeof( V_47 -> V_50 ) ) ;
T_2 V_25 ;
F_27 ( V_9 ) ;
V_25 = V_29 -> V_51 [ V_100 ] . V_96 ;
while ( V_25 != V_78 ) {
struct V_48 * V_12 = & ( V_29 -> V_51 [ V_25 ] ) ;
T_2 V_27 = V_12 -> V_98 ;
if ( V_12 -> V_50 == V_47 -> V_50 &&
! F_32 ( V_47 -> V_55 , V_12 -> V_55 ) )
F_67 ( V_9 , V_25 ) ;
V_25 = V_27 ;
}
F_28 ( V_9 ) ;
}
static int F_68 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_48 * V_32 ;
int V_30 = V_102 * sizeof( struct V_48 ) ;
int V_6 ;
V_32 = F_69 ( V_30 , V_33 ) ;
if ( ! V_32 )
return - 1 ;
F_27 ( V_9 ) ;
V_29 -> V_51 = V_32 ;
V_29 -> V_77 = V_78 ;
for ( V_6 = 0 ; V_6 < V_102 ; V_6 ++ ) {
F_65 ( V_29 -> V_51 + V_6 ) ;
}
F_28 ( V_9 ) ;
V_9 -> V_103 = F_33 ;
return 0 ;
}
static void F_70 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
F_27 ( V_9 ) ;
F_20 ( V_29 -> V_51 ) ;
V_29 -> V_51 = NULL ;
V_29 -> V_77 = V_78 ;
F_28 ( V_9 ) ;
}
static void F_71 ( struct V_8 * V_9 , unsigned short V_88 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
T_2 V_104 ;
F_27 ( V_9 ) ;
V_104 = V_29 -> V_77 ;
while ( V_104 != V_78 ) {
struct V_48 * V_105 = & ( V_29 -> V_51 [ V_104 ] ) ;
T_2 V_27 = V_29 -> V_51 [ V_104 ] . V_79 ;
if ( V_105 -> V_87 && ( V_105 -> V_88 == V_88 ) )
F_67 ( V_9 , V_104 ) ;
V_104 = V_27 ;
}
F_28 ( V_9 ) ;
}
static void F_43 ( struct V_21 * V_21 , T_1 V_106 [] )
{
struct V_8 * V_9 = F_72 ( V_21 ) ;
struct V_107 V_108 ;
int V_30 = sizeof( struct V_107 ) ;
int V_6 ;
memset ( & V_108 , 0 , V_30 ) ;
memcpy ( V_108 . V_54 , V_106 , V_56 ) ;
memcpy ( V_108 . V_55 , V_106 , V_56 ) ;
V_108 . type = F_34 ( V_109 ) ;
for ( V_6 = 0 ; V_6 < V_110 ; V_6 ++ ) {
struct V_2 * V_3 ;
char * V_111 ;
V_3 = F_73 ( V_30 ) ;
if ( ! V_3 ) {
return;
}
V_111 = F_74 ( V_3 , V_30 ) ;
memcpy ( V_111 , & V_108 , V_30 ) ;
F_75 ( V_3 ) ;
V_3 -> V_112 = V_3 -> V_113 + V_114 ;
V_3 -> V_60 = V_108 . type ;
V_3 -> V_115 = V_116 ;
V_3 -> V_74 = V_21 -> V_74 ;
if ( F_58 ( V_9 ) ) {
struct V_117 * V_118 ;
V_118 = F_76 ( V_9 ,
V_9 -> V_72 . V_119 ) ;
V_9 -> V_72 . V_119 = V_118 ;
if ( ! V_118 ) {
F_77 ( V_3 ) ;
continue;
}
V_3 = F_50 ( V_3 , V_118 -> V_88 ) ;
if ( ! V_3 ) {
F_49 ( L_3 ,
V_9 -> V_74 -> V_86 ) ;
continue;
}
}
F_78 ( V_3 ) ;
}
}
static int F_79 ( struct V_21 * V_21 , T_1 V_70 [] )
{
struct V_120 * V_74 = V_21 -> V_74 ;
struct V_121 V_122 ;
if ( V_21 -> V_9 -> V_123 . V_124 == V_125 ) {
memcpy ( V_74 -> V_84 , V_70 , V_74 -> V_126 ) ;
return 0 ;
}
memcpy ( V_122 . V_127 , V_70 , V_74 -> V_126 ) ;
V_122 . V_128 = V_74 -> type ;
if ( F_80 ( V_74 , & V_122 ) ) {
F_49 ( L_7
L_8 ,
V_21 -> V_9 -> V_74 -> V_86 , V_74 -> V_86 ) ;
return - V_129 ;
}
return 0 ;
}
static void F_81 ( struct V_8 * V_9 , struct V_21 * V_130 , struct V_21 * V_131 )
{
T_1 V_132 [ V_56 ] ;
memcpy ( V_132 , V_130 -> V_74 -> V_84 , V_56 ) ;
F_79 ( V_130 , V_131 -> V_74 -> V_84 ) ;
F_79 ( V_131 , V_132 ) ;
}
static void F_82 ( struct V_8 * V_9 , struct V_21 * V_130 ,
struct V_21 * V_131 )
{
int V_133 = ( F_24 ( V_130 ) != F_24 ( V_131 ) ) ;
struct V_21 * V_134 = NULL ;
F_83 () ;
if ( F_24 ( V_130 ) ) {
F_43 ( V_130 , V_130 -> V_74 -> V_84 ) ;
if ( V_9 -> V_72 . V_135 ) {
F_53 ( V_9 , V_130 ) ;
}
} else {
V_134 = V_130 ;
}
if ( F_24 ( V_131 ) ) {
F_43 ( V_131 , V_131 -> V_74 -> V_84 ) ;
if ( V_9 -> V_72 . V_135 ) {
F_53 ( V_9 , V_131 ) ;
}
} else {
V_134 = V_131 ;
}
if ( V_9 -> V_72 . V_135 && V_133 ) {
F_41 ( V_9 ,
V_134 -> V_74 -> V_84 ) ;
}
}
static void F_84 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
int V_136 ;
int V_137 ;
V_136 = ! F_32 ( V_21 -> V_138 ,
V_21 -> V_74 -> V_84 ) ;
V_137 = ! F_32 ( V_21 -> V_138 ,
V_9 -> V_74 -> V_84 ) ;
if ( V_136 && V_137 ) {
struct V_21 * V_139 ;
int V_6 , V_140 = 0 ;
F_23 (bond, tmp_slave, i) {
if ( F_32 ( V_21 -> V_138 ,
V_139 -> V_74 -> V_84 ) ) {
V_140 = 1 ;
break;
}
}
if ( V_140 ) {
F_81 ( V_9 , V_21 , V_139 ) ;
F_82 ( V_9 , V_21 , V_139 ) ;
}
}
}
static int F_85 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
struct V_21 * V_141 , * V_142 , * V_143 ;
struct V_21 * V_144 = V_9 -> V_71 ;
int V_6 , V_145 , V_140 = 0 ;
if ( V_9 -> V_146 == 0 ) {
return 0 ;
}
if ( ! F_32 ( V_21 -> V_138 , V_9 -> V_74 -> V_84 ) ) {
F_23 (bond, tmp_slave1, i) {
if ( F_32 ( V_141 -> V_74 -> V_84 ,
V_21 -> V_74 -> V_84 ) ) {
V_140 = 1 ;
break;
}
}
if ( ! V_140 )
return 0 ;
F_79 ( V_21 , V_9 -> V_74 -> V_84 ) ;
}
V_143 = NULL ;
F_23 (bond, tmp_slave1, i) {
V_140 = 0 ;
F_23 (bond, tmp_slave2, j) {
if ( F_32 ( V_141 -> V_138 ,
V_142 -> V_74 -> V_84 ) ) {
V_140 = 1 ;
break;
}
}
if ( ! V_140 ) {
V_143 = V_141 ;
break;
}
if ( ! V_144 ) {
if ( F_32 ( V_141 -> V_74 -> V_84 ,
V_9 -> V_74 -> V_84 ) ) {
V_144 = V_141 ;
}
}
}
if ( V_143 ) {
F_79 ( V_21 , V_143 -> V_138 ) ;
F_86 ( L_9 ,
V_9 -> V_74 -> V_86 , V_21 -> V_74 -> V_86 ,
V_143 -> V_74 -> V_86 ) ;
} else if ( V_144 ) {
F_49 ( L_10 ,
V_9 -> V_74 -> V_86 , V_21 -> V_74 -> V_86 ) ;
return - V_147 ;
}
return 0 ;
}
static int F_87 ( struct V_8 * V_9 , void * V_70 )
{
struct V_121 V_148 ;
struct V_21 * V_21 , * V_149 ;
char V_150 [ V_56 ] ;
int V_151 ;
int V_6 ;
if ( V_9 -> V_72 . V_135 ) {
return 0 ;
}
F_23 (bond, slave, i) {
memcpy ( V_150 , V_21 -> V_74 -> V_84 , V_56 ) ;
V_151 = F_80 ( V_21 -> V_74 , V_70 ) ;
memcpy ( V_21 -> V_74 -> V_84 , V_150 , V_56 ) ;
if ( V_151 )
goto V_152;
}
return 0 ;
V_152:
memcpy ( V_148 . V_127 , V_9 -> V_74 -> V_84 , V_9 -> V_74 -> V_126 ) ;
V_148 . V_128 = V_9 -> V_74 -> type ;
V_149 = V_21 ;
F_88 (bond, slave, i, bond->first_slave, stop_at) {
memcpy ( V_150 , V_21 -> V_74 -> V_84 , V_56 ) ;
F_80 ( V_21 -> V_74 , & V_148 ) ;
memcpy ( V_21 -> V_74 -> V_84 , V_150 , V_56 ) ;
}
return V_151 ;
}
int F_89 ( struct V_8 * V_9 , int V_135 )
{
int V_151 ;
V_151 = F_17 ( V_9 ) ;
if ( V_151 ) {
return V_151 ;
}
if ( V_135 ) {
V_9 -> V_72 . V_135 = 1 ;
V_151 = F_68 ( V_9 ) ;
if ( V_151 ) {
F_19 ( V_9 ) ;
return V_151 ;
}
} else {
V_9 -> V_72 . V_135 = 0 ;
}
return 0 ;
}
void F_90 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
F_19 ( V_9 ) ;
if ( V_29 -> V_135 ) {
F_70 ( V_9 ) ;
}
}
int F_91 ( struct V_2 * V_3 , struct V_120 * V_153 )
{
struct V_8 * V_9 = F_92 ( V_153 ) ;
struct V_154 * V_155 ;
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_21 * V_17 = NULL ;
static const T_3 V_156 = F_93 ( 0xffffffff ) ;
int V_5 = 0 ;
int V_157 = 1 ;
T_2 V_40 = 0 ;
const T_1 * V_4 = NULL ;
int V_151 = 1 ;
struct V_158 * V_159 ;
F_75 ( V_3 ) ;
V_155 = F_94 ( V_3 ) ;
F_95 ( & V_9 -> V_83 ) ;
switch ( F_96 ( V_3 -> V_60 ) ) {
case V_160 : {
const struct V_161 * V_162 = F_97 ( V_3 ) ;
if ( F_32 ( V_155 -> V_163 , V_80 ) ||
( V_162 -> V_164 == V_156 ) ||
( V_162 -> V_60 == V_165 ) ) {
V_157 = 0 ;
break;
}
V_4 = ( char * ) & ( V_162 -> V_164 ) ;
V_5 = sizeof( V_162 -> V_164 ) ;
}
break;
case V_166 :
if ( F_32 ( V_155 -> V_163 , V_80 ) ) {
V_157 = 0 ;
break;
}
if ( F_32 ( V_155 -> V_163 , V_167 ) ) {
V_157 = 0 ;
break;
}
V_159 = F_98 ( V_3 ) ;
if ( F_99 ( & V_159 -> V_168 ) ) {
V_157 = 0 ;
break;
}
V_4 = ( char * ) & ( F_98 ( V_3 ) -> V_164 ) ;
V_5 = sizeof( F_98 ( V_3 ) -> V_164 ) ;
break;
case V_169 :
if ( F_100 ( V_3 ) -> V_170 != V_171 ) {
V_157 = 0 ;
break;
}
if ( F_100 ( V_3 ) -> V_172 != V_173 ) {
V_157 = 0 ;
break;
}
V_4 = ( char * ) V_155 -> V_163 ;
V_5 = V_56 ;
break;
case V_61 :
V_157 = 0 ;
if ( V_29 -> V_135 ) {
V_17 = F_60 ( V_3 , V_9 ) ;
}
break;
default:
V_157 = 0 ;
break;
}
if ( V_157 ) {
V_40 = F_2 ( V_4 , V_5 ) ;
V_17 = F_26 ( V_9 , V_40 , V_3 -> V_174 ) ;
}
if ( ! V_17 ) {
V_17 = V_9 -> V_71 ;
V_29 -> V_175 += V_3 -> V_174 ;
}
if ( V_17 && F_24 ( V_17 ) ) {
if ( V_17 != V_9 -> V_71 ) {
memcpy ( V_155 -> V_176 ,
V_17 -> V_74 -> V_84 ,
V_56 ) ;
}
V_151 = F_101 ( V_9 , V_3 , V_17 -> V_74 ) ;
} else {
if ( V_17 ) {
F_8 ( V_9 ) ;
F_15 ( V_9 , V_17 , 0 ) ;
F_10 ( V_9 ) ;
}
}
F_102 ( & V_9 -> V_83 ) ;
if ( V_151 ) {
F_77 ( V_3 ) ;
}
return V_177 ;
}
void F_103 ( struct V_178 * V_179 )
{
struct V_8 * V_9 = F_104 ( V_179 , struct V_8 ,
V_180 . V_179 ) ;
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_21 * V_21 ;
int V_6 ;
F_95 ( & V_9 -> V_181 ) ;
if ( V_9 -> V_146 == 0 ) {
V_29 -> V_182 = 0 ;
V_29 -> V_183 = 0 ;
goto V_184;
}
V_29 -> V_182 ++ ;
V_29 -> V_183 ++ ;
if ( V_29 -> V_183 >= V_185 ) {
F_95 ( & V_9 -> V_83 ) ;
F_23 (bond, slave, i) {
F_43 ( V_21 , V_21 -> V_74 -> V_84 ) ;
}
F_102 ( & V_9 -> V_83 ) ;
V_29 -> V_183 = 0 ;
}
if ( V_29 -> V_182 >= V_186 ) {
F_95 ( & V_9 -> V_83 ) ;
F_23 (bond, slave, i) {
F_16 ( V_9 , V_21 , 1 ) ;
if ( V_21 == V_9 -> V_71 ) {
F_14 ( V_21 ) . V_22 =
V_29 -> V_175 /
V_16 ;
V_29 -> V_175 = 0 ;
}
}
F_102 ( & V_9 -> V_83 ) ;
V_29 -> V_182 = 0 ;
}
if ( V_29 -> V_135 ) {
if ( V_29 -> V_73 &&
( ++ V_29 -> V_75 >= V_187 ) ) {
F_102 ( & V_9 -> V_181 ) ;
if ( ! F_105 () ) {
F_95 ( & V_9 -> V_181 ) ;
goto V_184;
}
V_29 -> V_75 = 0 ;
F_42 ( V_9 -> V_71 -> V_74 , - 1 ) ;
V_29 -> V_73 = 0 ;
F_106 () ;
F_95 ( & V_9 -> V_181 ) ;
}
if ( V_29 -> F_62 ) {
V_29 -> F_62 = 0 ;
F_62 ( V_9 ) ;
}
if ( V_29 -> V_58 ) {
if ( V_29 -> V_89 ) {
-- V_29 -> V_89 ;
} else {
F_52 ( V_9 ) ;
if ( V_29 -> V_81 ) {
-- V_29 -> V_81 ;
} else {
V_29 -> V_58 = 0 ;
}
}
}
}
V_184:
F_107 ( V_9 -> V_188 , & V_9 -> V_180 , V_189 ) ;
F_102 ( & V_9 -> V_181 ) ;
}
int F_108 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
int V_151 ;
V_151 = F_79 ( V_21 , V_21 -> V_138 ) ;
if ( V_151 ) {
return V_151 ;
}
F_95 ( & V_9 -> V_181 ) ;
V_151 = F_85 ( V_9 , V_21 ) ;
F_102 ( & V_9 -> V_181 ) ;
if ( V_151 ) {
return V_151 ;
}
F_13 ( V_21 ) ;
V_9 -> V_72 . V_182 = V_186 ;
if ( V_9 -> V_72 . V_135 ) {
V_9 -> V_72 . F_62 = 1 ;
}
return 0 ;
}
void F_109 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
if ( V_9 -> V_146 > 1 ) {
F_84 ( V_9 , V_21 ) ;
}
F_16 ( V_9 , V_21 , 0 ) ;
if ( V_9 -> V_72 . V_135 ) {
V_9 -> V_72 . V_68 = NULL ;
F_44 ( V_9 , V_21 ) ;
}
}
void F_110 ( struct V_8 * V_9 , struct V_21 * V_21 , char V_190 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
if ( V_190 == V_191 ) {
F_16 ( V_9 , V_21 , 0 ) ;
if ( V_9 -> V_72 . V_135 ) {
F_44 ( V_9 , V_21 ) ;
}
} else if ( V_190 == V_192 ) {
V_29 -> V_182 = V_186 ;
if ( V_9 -> V_72 . V_135 ) {
V_9 -> V_72 . F_62 = 1 ;
}
}
}
void F_111 ( struct V_8 * V_9 , struct V_21 * V_193 )
__releases( &bond->curr_slave_lock
int F_112 ( struct V_120 * V_153 , void * V_70 )
__acquires( &bond->lock
void F_113 ( struct V_8 * V_9 , unsigned short V_88 )
{
if ( V_9 -> V_72 . V_119 &&
( V_9 -> V_72 . V_119 -> V_88 == V_88 ) ) {
V_9 -> V_72 . V_119 = NULL ;
}
if ( V_9 -> V_72 . V_135 ) {
F_71 ( V_9 , V_88 ) ;
}
}
