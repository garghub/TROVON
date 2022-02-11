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
V_36 = NULL ;
V_37 = V_38 ;
F_23 (bond, slave) {
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
if ( V_29 -> V_68 )
V_67 = V_29 -> V_68 ;
else
V_67 = F_40 ( V_9 ) ;
V_66 = NULL ;
F_41 (bond, slave, i, start_at) {
if ( F_24 ( V_21 ) ) {
if ( ! V_66 ) {
V_66 = V_21 ;
} else if ( V_21 -> V_35 > V_66 -> V_35 ) {
V_66 = V_21 ;
}
}
}
if ( V_66 ) {
V_21 = F_42 ( V_9 , V_66 ) ;
V_29 -> V_68 = V_21 ;
}
return V_66 ;
}
static void F_43 ( struct V_8 * V_9 , T_1 V_69 [] )
{
if ( ! V_9 -> V_70 ) {
return;
}
if ( ! V_9 -> V_71 . V_72 ) {
if ( ! F_44 ( V_9 -> V_70 -> V_73 , 1 ) )
V_9 -> V_71 . V_72 = 1 ;
else
V_9 -> V_71 . V_72 = 0 ;
}
V_9 -> V_71 . V_74 = 0 ;
F_45 ( V_9 -> V_70 , V_69 ) ;
}
static void F_46 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_48 * V_75 ;
T_2 V_25 , V_27 ;
F_27 ( V_9 ) ;
V_75 = V_29 -> V_51 ;
V_25 = V_29 -> V_76 ;
for (; V_25 != V_77 ; V_25 = V_27 ) {
V_27 = V_75 [ V_25 ] . V_78 ;
if ( V_75 [ V_25 ] . V_21 == V_21 ) {
struct V_21 * V_43 = F_39 ( V_9 ) ;
if ( V_43 ) {
V_75 [ V_25 ] . V_21 = V_43 ;
if ( ! F_32 ( V_75 [ V_25 ] . V_54 ,
V_79 ) ) {
V_29 -> V_51 [ V_25 ] . V_57 = 1 ;
V_29 -> V_58 = 1 ;
V_29 -> V_80 =
V_81 ;
}
} else {
V_75 [ V_25 ] . V_21 = NULL ;
}
}
}
F_28 ( V_9 ) ;
F_47 ( & V_9 -> V_82 ) ;
if ( V_21 != V_9 -> V_70 ) {
F_43 ( V_9 , V_21 -> V_73 -> V_83 ) ;
}
F_48 ( & V_9 -> V_82 ) ;
}
static void F_49 ( struct V_48 * V_49 )
{
int V_6 ;
if ( ! V_49 -> V_21 ) {
return;
}
for ( V_6 = 0 ; V_6 < V_84 ; V_6 ++ ) {
struct V_2 * V_3 ;
V_3 = F_50 ( V_64 , V_61 ,
V_49 -> V_53 ,
V_49 -> V_21 -> V_73 ,
V_49 -> V_50 ,
V_49 -> V_54 ,
V_49 -> V_21 -> V_73 -> V_83 ,
V_49 -> V_54 ) ;
if ( ! V_3 ) {
F_51 ( L_2 ,
V_49 -> V_21 -> V_9 -> V_73 -> V_85 ) ;
continue;
}
V_3 -> V_73 = V_49 -> V_21 -> V_73 ;
if ( V_49 -> V_86 ) {
V_3 = F_52 ( V_3 , F_37 ( V_87 ) , V_49 -> V_86 ) ;
if ( ! V_3 ) {
F_51 ( L_3 ,
V_49 -> V_21 -> V_9 -> V_73 -> V_85 ) ;
continue;
}
}
F_53 ( V_3 ) ;
}
}
static void F_54 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_48 * V_49 ;
T_2 V_40 ;
F_27 ( V_9 ) ;
V_40 = V_29 -> V_76 ;
for (; V_40 != V_77 ;
V_40 = V_49 -> V_78 ) {
V_49 = & ( V_29 -> V_51 [ V_40 ] ) ;
if ( V_49 -> V_57 ) {
F_49 ( V_49 ) ;
if ( V_29 -> V_80 == 0 ) {
V_49 -> V_57 = 0 ;
}
}
}
V_29 -> V_88 = V_89 ;
F_28 ( V_9 ) ;
}
static void F_55 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_48 * V_49 ;
int V_57 = 0 ;
T_2 V_40 ;
F_27 ( V_9 ) ;
V_40 = V_29 -> V_76 ;
for (; V_40 != V_77 ;
V_40 = V_49 -> V_78 ) {
V_49 = & ( V_29 -> V_51 [ V_40 ] ) ;
if ( ( V_49 -> V_21 == V_21 ) &&
! F_32 ( V_49 -> V_54 , V_79 ) ) {
V_49 -> V_57 = 1 ;
V_57 = 1 ;
}
}
if ( V_57 ) {
V_29 -> V_58 = 1 ;
V_29 -> V_80 = V_81 ;
}
F_28 ( V_9 ) ;
}
static void F_56 ( struct V_8 * V_9 , T_3 V_90 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_48 * V_49 ;
T_2 V_40 ;
F_29 ( V_9 ) ;
V_40 = V_29 -> V_76 ;
for (; V_40 != V_77 ;
V_40 = V_49 -> V_78 ) {
V_49 = & ( V_29 -> V_51 [ V_40 ] ) ;
if ( ! V_49 -> V_21 ) {
F_51 ( L_4 ,
V_9 -> V_73 -> V_85 ) ;
continue;
}
if ( ( V_49 -> V_50 == V_90 ) &&
! F_32 ( V_49 -> V_21 -> V_73 -> V_83 ,
V_9 -> V_73 -> V_83 ) &&
! F_32 ( V_49 -> V_54 , V_79 ) ) {
V_49 -> V_57 = 1 ;
V_29 -> V_58 = 1 ;
}
}
F_30 ( V_9 ) ;
}
static struct V_21 * F_57 ( struct V_2 * V_3 , struct V_8 * V_9 )
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
if ( ! F_32 ( V_47 -> V_54 , V_79 ) ) {
memcpy ( V_49 -> V_54 , V_47 -> V_54 , V_56 ) ;
}
memcpy ( V_49 -> V_55 , V_47 -> V_55 , V_56 ) ;
V_43 = V_49 -> V_21 ;
if ( V_43 ) {
F_30 ( V_9 ) ;
return V_43 ;
}
} else {
if ( V_9 -> V_70 &&
V_49 -> V_21 != V_9 -> V_70 ) {
V_49 -> V_21 = V_9 -> V_70 ;
F_49 ( V_49 ) ;
}
}
}
V_43 = F_39 ( V_9 ) ;
if ( V_43 ) {
if ( ! ( V_49 -> V_52 &&
V_49 -> V_50 == V_47 -> V_50 ) ) {
T_2 V_91 = F_2 ( ( T_1 * ) & V_47 -> V_50 ,
sizeof( V_47 -> V_50 ) ) ;
F_58 ( V_9 , V_40 ) ;
F_59 ( V_9 , V_91 , V_40 ) ;
}
V_49 -> V_50 = V_47 -> V_50 ;
V_49 -> V_53 = V_47 -> V_53 ;
memcpy ( V_49 -> V_54 , V_47 -> V_54 , V_56 ) ;
memcpy ( V_49 -> V_55 , V_47 -> V_55 , V_56 ) ;
V_49 -> V_21 = V_43 ;
if ( ! F_32 ( V_49 -> V_54 , V_79 ) ) {
V_49 -> V_57 = 1 ;
V_9 -> V_71 . V_58 = 1 ;
} else {
V_49 -> V_57 = 0 ;
}
if ( ! F_60 ( V_3 , & V_49 -> V_86 ) )
V_49 -> V_86 = 0 ;
if ( ! V_49 -> V_52 ) {
T_2 V_92 = V_29 -> V_76 ;
V_29 -> V_76 = V_40 ;
V_49 -> V_78 = V_92 ;
if ( V_92 != V_77 ) {
V_29 -> V_51 [ V_92 ] . V_93 =
V_40 ;
}
V_49 -> V_52 = 1 ;
}
}
F_30 ( V_9 ) ;
return V_43 ;
}
static struct V_21 * F_61 ( struct V_2 * V_3 , struct V_8 * V_9 )
{
struct V_1 * V_47 = V_1 ( V_3 ) ;
struct V_21 * V_17 = NULL ;
if ( ! F_62 ( V_9 , V_47 -> V_55 ) )
return NULL ;
if ( V_47 -> V_63 == F_37 ( V_64 ) ) {
V_17 = F_57 ( V_3 , V_9 ) ;
if ( V_17 ) {
memcpy ( V_47 -> V_55 , V_17 -> V_73 -> V_83 , V_56 ) ;
}
F_38 ( L_5 ) ;
} else if ( V_47 -> V_63 == F_37 ( V_94 ) ) {
F_57 ( V_3 , V_9 ) ;
V_9 -> V_71 . V_88 = V_89 ;
F_56 ( V_9 , V_47 -> V_50 ) ;
F_38 ( L_6 ) ;
}
return V_17 ;
}
static void F_63 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_21 * V_43 ;
struct V_48 * V_49 ;
int V_57 ;
T_2 V_40 ;
F_27 ( V_9 ) ;
V_57 = 0 ;
V_40 = V_29 -> V_76 ;
for (; V_40 != V_77 ;
V_40 = V_49 -> V_78 ) {
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
static void F_64 ( struct V_48 * V_12 )
{
V_12 -> V_78 = V_77 ;
V_12 -> V_93 = V_77 ;
V_12 -> V_52 = 0 ;
V_12 -> V_21 = NULL ;
V_12 -> V_86 = 0 ;
}
static void F_65 ( struct V_48 * V_12 )
{
V_12 -> V_95 = V_77 ;
V_12 -> V_96 = V_77 ;
V_12 -> V_97 = V_77 ;
}
static void F_66 ( struct V_48 * V_12 )
{
memset ( V_12 , 0 , sizeof( struct V_48 ) ) ;
F_64 ( V_12 ) ;
F_65 ( V_12 ) ;
}
static void F_67 ( struct V_8 * V_9 , T_2 V_25 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
T_2 V_27 = V_29 -> V_51 [ V_25 ] . V_78 ;
T_2 V_98 = V_29 -> V_51 [ V_25 ] . V_93 ;
if ( V_25 == V_29 -> V_76 )
V_29 -> V_76 = V_27 ;
if ( V_98 != V_77 )
V_29 -> V_51 [ V_98 ] . V_78 = V_27 ;
if ( V_27 != V_77 )
V_29 -> V_51 [ V_27 ] . V_93 = V_98 ;
}
static void F_58 ( struct V_8 * V_9 , T_2 V_25 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
T_2 V_27 = V_29 -> V_51 [ V_25 ] . V_97 ;
T_2 V_98 = V_29 -> V_51 [ V_25 ] . V_96 ;
V_29 -> V_51 [ V_25 ] . V_97 = V_77 ;
V_29 -> V_51 [ V_25 ] . V_96 = V_77 ;
if ( V_27 != V_77 )
V_29 -> V_51 [ V_27 ] . V_96 = V_98 ;
if ( V_98 == V_77 )
return;
if ( V_29 -> V_51 [ V_98 ] . V_95 == V_25 )
V_29 -> V_51 [ V_98 ] . V_95 = V_27 ;
else
V_29 -> V_51 [ V_98 ] . V_97 = V_27 ;
}
static void F_68 ( struct V_8 * V_9 , T_2 V_25 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_48 * V_12 = & ( V_29 -> V_51 [ V_25 ] ) ;
F_67 ( V_9 , V_25 ) ;
F_64 ( V_12 ) ;
F_58 ( V_9 , V_25 ) ;
}
static void F_59 ( struct V_8 * V_9 , T_2 V_99 , T_2 V_100 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
T_2 V_18 ;
V_29 -> V_51 [ V_100 ] . V_96 = V_99 ;
V_18 = V_29 -> V_51 [ V_99 ] . V_95 ;
V_29 -> V_51 [ V_100 ] . V_97 = V_18 ;
if ( V_18 != V_77 )
V_29 -> V_51 [ V_18 ] . V_96 = V_100 ;
V_29 -> V_51 [ V_99 ] . V_95 = V_100 ;
}
static void F_36 ( struct V_8 * V_9 , struct V_1 * V_47 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
T_2 V_99 = F_2 ( ( T_1 * ) & ( V_47 -> V_50 ) , sizeof( V_47 -> V_50 ) ) ;
T_2 V_25 ;
F_27 ( V_9 ) ;
V_25 = V_29 -> V_51 [ V_99 ] . V_95 ;
while ( V_25 != V_77 ) {
struct V_48 * V_12 = & ( V_29 -> V_51 [ V_25 ] ) ;
T_2 V_27 = V_12 -> V_97 ;
if ( V_12 -> V_50 == V_47 -> V_50 &&
! F_32 ( V_47 -> V_55 , V_12 -> V_55 ) )
F_68 ( V_9 , V_25 ) ;
V_25 = V_27 ;
}
F_28 ( V_9 ) ;
}
static int F_69 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_48 * V_32 ;
int V_30 = V_101 * sizeof( struct V_48 ) ;
int V_6 ;
V_32 = F_70 ( V_30 , V_33 ) ;
if ( ! V_32 )
return - 1 ;
F_27 ( V_9 ) ;
V_29 -> V_51 = V_32 ;
V_29 -> V_76 = V_77 ;
for ( V_6 = 0 ; V_6 < V_101 ; V_6 ++ ) {
F_66 ( V_29 -> V_51 + V_6 ) ;
}
F_28 ( V_9 ) ;
V_9 -> V_102 = F_33 ;
return 0 ;
}
static void F_71 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
F_27 ( V_9 ) ;
F_20 ( V_29 -> V_51 ) ;
V_29 -> V_51 = NULL ;
V_29 -> V_76 = V_77 ;
F_28 ( V_9 ) ;
}
static void F_72 ( struct V_8 * V_9 , unsigned short V_86 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
T_2 V_103 ;
F_27 ( V_9 ) ;
V_103 = V_29 -> V_76 ;
while ( V_103 != V_77 ) {
struct V_48 * V_104 = & ( V_29 -> V_51 [ V_103 ] ) ;
T_2 V_27 = V_29 -> V_51 [ V_103 ] . V_78 ;
if ( V_104 -> V_86 == V_86 )
F_68 ( V_9 , V_103 ) ;
V_103 = V_27 ;
}
F_28 ( V_9 ) ;
}
static void F_73 ( struct V_21 * V_21 , T_1 V_105 [] ,
T_4 V_106 )
{
struct V_107 V_108 ;
struct V_2 * V_3 ;
int V_30 = sizeof( struct V_107 ) ;
char * V_109 ;
memset ( & V_108 , 0 , V_30 ) ;
memcpy ( V_108 . V_54 , V_105 , V_56 ) ;
memcpy ( V_108 . V_55 , V_105 , V_56 ) ;
V_108 . type = F_34 ( V_110 ) ;
V_3 = F_74 ( V_30 ) ;
if ( ! V_3 )
return;
V_109 = F_75 ( V_3 , V_30 ) ;
memcpy ( V_109 , & V_108 , V_30 ) ;
F_76 ( V_3 ) ;
V_3 -> V_111 = V_3 -> V_112 + V_113 ;
V_3 -> V_60 = V_108 . type ;
V_3 -> V_114 = V_115 ;
V_3 -> V_73 = V_21 -> V_73 ;
if ( V_106 ) {
V_3 = F_52 ( V_3 , F_37 ( V_87 ) , V_106 ) ;
if ( ! V_3 ) {
F_51 ( L_3 ,
V_21 -> V_9 -> V_73 -> V_85 ) ;
return;
}
}
F_77 ( V_3 ) ;
}
static void F_45 ( struct V_21 * V_21 , T_1 V_105 [] )
{
struct V_8 * V_9 = F_78 ( V_21 ) ;
struct V_116 * V_117 ;
struct V_118 * V_119 ;
F_73 ( V_21 , V_105 , 0 ) ;
F_79 () ;
F_80 (bond->dev, upper, iter) {
if ( V_117 -> V_120 & V_121 )
F_73 ( V_21 , V_105 ,
F_81 ( V_117 ) ) ;
}
F_82 () ;
}
static int F_83 ( struct V_21 * V_21 , T_1 V_69 [] )
{
struct V_116 * V_73 = V_21 -> V_73 ;
struct V_122 V_123 ;
if ( V_21 -> V_9 -> V_124 . V_125 == V_126 ) {
memcpy ( V_73 -> V_83 , V_69 , V_73 -> V_127 ) ;
return 0 ;
}
memcpy ( V_123 . V_128 , V_69 , V_73 -> V_127 ) ;
V_123 . V_129 = V_73 -> type ;
if ( F_84 ( V_73 , & V_123 ) ) {
F_51 ( L_7
L_8 ,
V_21 -> V_9 -> V_73 -> V_85 , V_73 -> V_85 ) ;
return - V_130 ;
}
return 0 ;
}
static void F_85 ( struct V_21 * V_131 , struct V_21 * V_132 )
{
T_1 V_133 [ V_56 ] ;
memcpy ( V_133 , V_131 -> V_73 -> V_83 , V_56 ) ;
F_83 ( V_131 , V_132 -> V_73 -> V_83 ) ;
F_83 ( V_132 , V_133 ) ;
}
static void F_86 ( struct V_8 * V_9 , struct V_21 * V_131 ,
struct V_21 * V_132 )
{
int V_134 = ( F_24 ( V_131 ) != F_24 ( V_132 ) ) ;
struct V_21 * V_135 = NULL ;
F_87 () ;
if ( F_24 ( V_131 ) ) {
F_45 ( V_131 , V_131 -> V_73 -> V_83 ) ;
if ( V_9 -> V_71 . V_136 ) {
F_55 ( V_9 , V_131 ) ;
}
} else {
V_135 = V_131 ;
}
if ( F_24 ( V_132 ) ) {
F_45 ( V_132 , V_132 -> V_73 -> V_83 ) ;
if ( V_9 -> V_71 . V_136 ) {
F_55 ( V_9 , V_132 ) ;
}
} else {
V_135 = V_132 ;
}
if ( V_9 -> V_71 . V_136 && V_134 ) {
F_43 ( V_9 ,
V_135 -> V_73 -> V_83 ) ;
}
}
static void F_88 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
int V_137 ;
int V_138 ;
struct V_21 * V_139 ;
V_137 = ! F_32 ( V_21 -> V_140 ,
V_21 -> V_73 -> V_83 ) ;
V_138 = ! F_32 ( V_21 -> V_140 ,
V_9 -> V_73 -> V_83 ) ;
if ( V_137 && V_138 ) {
V_139 = F_62 ( V_9 , V_21 -> V_140 ) ;
if ( V_139 ) {
F_85 ( V_21 , V_139 ) ;
F_86 ( V_9 , V_21 , V_139 ) ;
}
}
}
static int F_89 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
struct V_21 * V_141 , * V_142 = NULL ;
struct V_21 * V_143 = V_9 -> V_70 ;
if ( F_90 ( & V_9 -> V_144 ) ) {
return 0 ;
}
if ( ! F_32 ( V_21 -> V_140 , V_9 -> V_73 -> V_83 ) ) {
if ( ! F_62 ( V_9 , V_21 -> V_73 -> V_83 ) )
return 0 ;
F_83 ( V_21 , V_9 -> V_73 -> V_83 ) ;
}
F_23 (bond, tmp_slave1) {
if ( ! F_62 ( V_9 , V_141 -> V_140 ) ) {
V_142 = V_141 ;
break;
}
if ( ! V_143 ) {
if ( F_32 ( V_141 -> V_73 -> V_83 ,
V_9 -> V_73 -> V_83 ) ) {
V_143 = V_141 ;
}
}
}
if ( V_142 ) {
F_83 ( V_21 , V_142 -> V_140 ) ;
F_91 ( L_9 ,
V_9 -> V_73 -> V_85 , V_21 -> V_73 -> V_85 ,
V_142 -> V_73 -> V_85 ) ;
} else if ( V_143 ) {
F_51 ( L_10 ,
V_9 -> V_73 -> V_85 , V_21 -> V_73 -> V_85 ) ;
return - V_145 ;
}
return 0 ;
}
static int F_92 ( struct V_8 * V_9 , void * V_69 )
{
char V_146 [ V_56 ] ;
struct V_21 * V_21 ;
struct V_122 V_147 ;
int V_148 ;
if ( V_9 -> V_71 . V_136 )
return 0 ;
F_23 (bond, slave) {
memcpy ( V_146 , V_21 -> V_73 -> V_83 , V_56 ) ;
V_148 = F_84 ( V_21 -> V_73 , V_69 ) ;
memcpy ( V_21 -> V_73 -> V_83 , V_146 , V_56 ) ;
if ( V_148 )
goto V_149;
}
return 0 ;
V_149:
memcpy ( V_147 . V_128 , V_9 -> V_73 -> V_83 , V_9 -> V_73 -> V_127 ) ;
V_147 . V_129 = V_9 -> V_73 -> type ;
F_93 (bond, slave) {
memcpy ( V_146 , V_21 -> V_73 -> V_83 , V_56 ) ;
F_84 ( V_21 -> V_73 , & V_147 ) ;
memcpy ( V_21 -> V_73 -> V_83 , V_146 , V_56 ) ;
}
return V_148 ;
}
int F_94 ( struct V_8 * V_9 , int V_136 )
{
int V_148 ;
V_148 = F_17 ( V_9 ) ;
if ( V_148 ) {
return V_148 ;
}
if ( V_136 ) {
V_9 -> V_71 . V_136 = 1 ;
V_148 = F_69 ( V_9 ) ;
if ( V_148 ) {
F_19 ( V_9 ) ;
return V_148 ;
}
} else {
V_9 -> V_71 . V_136 = 0 ;
}
return 0 ;
}
void F_95 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
F_19 ( V_9 ) ;
if ( V_29 -> V_136 ) {
F_71 ( V_9 ) ;
}
}
int F_96 ( struct V_2 * V_3 , struct V_116 * V_150 )
{
struct V_8 * V_9 = F_97 ( V_150 ) ;
struct V_151 * V_152 ;
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_21 * V_17 = NULL ;
static const T_3 V_153 = F_98 ( 0xffffffff ) ;
int V_5 = 0 ;
int V_154 = 1 ;
T_2 V_40 = 0 ;
const T_1 * V_4 = NULL ;
int V_148 = 1 ;
struct V_155 * V_156 ;
F_76 ( V_3 ) ;
V_152 = F_99 ( V_3 ) ;
F_100 ( & V_9 -> V_157 ) ;
F_100 ( & V_9 -> V_82 ) ;
switch ( F_101 ( V_3 -> V_60 ) ) {
case V_158 : {
const struct V_159 * V_160 = F_102 ( V_3 ) ;
if ( F_32 ( V_152 -> V_161 , V_79 ) ||
( V_160 -> V_162 == V_153 ) ||
( V_160 -> V_60 == V_163 ) ) {
V_154 = 0 ;
break;
}
V_4 = ( char * ) & ( V_160 -> V_162 ) ;
V_5 = sizeof( V_160 -> V_162 ) ;
}
break;
case V_164 :
if ( F_32 ( V_152 -> V_161 , V_79 ) ) {
V_154 = 0 ;
break;
}
if ( F_32 ( V_152 -> V_161 , V_165 ) ) {
V_154 = 0 ;
break;
}
V_156 = F_103 ( V_3 ) ;
if ( F_104 ( & V_156 -> V_166 ) ) {
V_154 = 0 ;
break;
}
V_4 = ( char * ) & ( F_103 ( V_3 ) -> V_162 ) ;
V_5 = sizeof( F_103 ( V_3 ) -> V_162 ) ;
break;
case V_167 :
if ( F_105 ( V_3 ) -> V_168 != V_169 ) {
V_154 = 0 ;
break;
}
if ( F_105 ( V_3 ) -> V_170 != V_171 ) {
V_154 = 0 ;
break;
}
V_4 = ( char * ) V_152 -> V_161 ;
V_5 = V_56 ;
break;
case V_61 :
V_154 = 0 ;
if ( V_29 -> V_136 ) {
V_17 = F_61 ( V_3 , V_9 ) ;
}
break;
default:
V_154 = 0 ;
break;
}
if ( V_154 ) {
V_40 = F_2 ( V_4 , V_5 ) ;
V_17 = F_26 ( V_9 , V_40 , V_3 -> V_172 ) ;
}
if ( ! V_17 ) {
V_17 = V_9 -> V_70 ;
V_29 -> V_173 += V_3 -> V_172 ;
}
if ( V_17 && F_24 ( V_17 ) ) {
if ( V_17 != V_9 -> V_70 ) {
memcpy ( V_152 -> V_174 ,
V_17 -> V_73 -> V_83 ,
V_56 ) ;
}
V_148 = F_106 ( V_9 , V_3 , V_17 -> V_73 ) ;
} else {
if ( V_17 ) {
F_8 ( V_9 ) ;
F_15 ( V_9 , V_17 , 0 ) ;
F_10 ( V_9 ) ;
}
}
F_107 ( & V_9 -> V_82 ) ;
F_107 ( & V_9 -> V_157 ) ;
if ( V_148 ) {
F_108 ( V_3 ) ;
}
return V_175 ;
}
void F_109 ( struct V_176 * V_177 )
{
struct V_8 * V_9 = F_110 ( V_177 , struct V_8 ,
V_178 . V_177 ) ;
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_21 * V_21 ;
F_100 ( & V_9 -> V_157 ) ;
if ( F_90 ( & V_9 -> V_144 ) ) {
V_29 -> V_179 = 0 ;
V_29 -> V_180 = 0 ;
goto V_181;
}
V_29 -> V_179 ++ ;
V_29 -> V_180 ++ ;
if ( V_29 -> V_180 >= F_111 ( V_9 ) ) {
F_100 ( & V_9 -> V_82 ) ;
F_23 (bond, slave)
F_45 ( V_21 , V_21 -> V_73 -> V_83 ) ;
F_107 ( & V_9 -> V_82 ) ;
V_29 -> V_180 = 0 ;
}
if ( V_29 -> V_179 >= V_182 ) {
F_100 ( & V_9 -> V_82 ) ;
F_23 (bond, slave) {
F_16 ( V_9 , V_21 , 1 ) ;
if ( V_21 == V_9 -> V_70 ) {
F_14 ( V_21 ) . V_22 =
V_29 -> V_173 /
V_16 ;
V_29 -> V_173 = 0 ;
}
}
F_107 ( & V_9 -> V_82 ) ;
V_29 -> V_179 = 0 ;
}
if ( V_29 -> V_136 ) {
if ( V_29 -> V_72 &&
( ++ V_29 -> V_74 >= V_183 ) ) {
F_107 ( & V_9 -> V_157 ) ;
if ( ! F_112 () ) {
F_100 ( & V_9 -> V_157 ) ;
goto V_181;
}
V_29 -> V_74 = 0 ;
F_44 ( V_9 -> V_70 -> V_73 , - 1 ) ;
V_29 -> V_72 = 0 ;
F_113 () ;
F_100 ( & V_9 -> V_157 ) ;
}
if ( V_29 -> F_63 ) {
V_29 -> F_63 = 0 ;
F_63 ( V_9 ) ;
}
if ( V_29 -> V_58 ) {
if ( V_29 -> V_88 ) {
-- V_29 -> V_88 ;
} else {
F_54 ( V_9 ) ;
if ( V_29 -> V_80 ) {
-- V_29 -> V_80 ;
} else {
V_29 -> V_58 = 0 ;
}
}
}
}
V_181:
F_114 ( V_9 -> V_184 , & V_9 -> V_178 , V_185 ) ;
F_107 ( & V_9 -> V_157 ) ;
}
int F_115 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
int V_148 ;
V_148 = F_83 ( V_21 , V_21 -> V_140 ) ;
if ( V_148 ) {
return V_148 ;
}
V_148 = F_89 ( V_9 , V_21 ) ;
if ( V_148 ) {
return V_148 ;
}
F_13 ( V_21 ) ;
V_9 -> V_71 . V_179 = V_182 ;
if ( V_9 -> V_71 . V_136 ) {
V_9 -> V_71 . F_63 = 1 ;
}
return 0 ;
}
void F_116 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
if ( ! F_90 ( & V_9 -> V_144 ) )
F_88 ( V_9 , V_21 ) ;
F_16 ( V_9 , V_21 , 0 ) ;
if ( V_9 -> V_71 . V_136 ) {
V_9 -> V_71 . V_68 = NULL ;
F_46 ( V_9 , V_21 ) ;
}
}
void F_117 ( struct V_8 * V_9 , struct V_21 * V_21 , char V_186 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
if ( V_186 == V_187 ) {
F_16 ( V_9 , V_21 , 0 ) ;
if ( V_9 -> V_71 . V_136 ) {
F_46 ( V_9 , V_21 ) ;
}
} else if ( V_186 == V_188 ) {
V_29 -> V_179 = V_182 ;
if ( V_9 -> V_71 . V_136 ) {
V_9 -> V_71 . F_63 = 1 ;
}
}
}
void F_118 ( struct V_8 * V_9 , struct V_21 * V_189 )
__releases( &bond->curr_slave_lock
int F_119 ( struct V_116 * V_150 , void * V_69 )
__acquires( &bond->lock
void F_120 ( struct V_8 * V_9 , unsigned short V_86 )
{
if ( V_9 -> V_71 . V_136 ) {
F_72 ( V_9 , V_86 ) ;
}
}
