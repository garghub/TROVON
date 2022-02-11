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
if ( V_27 != V_19 ) {
V_44 [ V_27 ] . V_20 = V_42 ;
}
V_47 -> V_23 = V_42 ;
V_47 -> V_22 +=
V_44 [ V_42 ] . V_14 ;
}
}
if ( V_45 ) {
V_44 [ V_42 ] . V_15 += V_43 ;
}
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
memcpy ( V_51 -> V_56 , V_49 -> V_57 , V_58 ) ;
V_51 -> V_59 = 1 ;
V_29 -> V_60 = 1 ;
}
F_28 ( V_9 ) ;
}
static int F_33 ( const struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_21 * V_21 )
{
struct V_1 * V_49 , V_61 ;
if ( V_3 -> V_62 != F_34 ( V_63 ) )
goto V_64;
V_49 = F_35 ( V_3 , 0 , sizeof( V_61 ) , & V_61 ) ;
if ( ! V_49 )
goto V_64;
F_36 ( V_9 , V_49 ) ;
if ( V_49 -> V_65 == F_37 ( V_66 ) ) {
F_31 ( V_9 , V_49 ) ;
F_38 ( L_1 ) ;
}
V_64:
return V_67 ;
}
static struct V_21 * F_39 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_21 * V_68 = NULL , * V_69 = NULL , * V_21 ;
struct V_37 * V_38 ;
bool V_70 = false ;
F_40 (bond, slave, iter) {
if ( ! F_24 ( V_21 ) )
continue;
if ( ! V_70 ) {
if ( ! V_68 || V_68 -> V_35 < V_21 -> V_35 )
V_68 = V_21 ;
} else {
if ( ! V_69 || V_69 -> V_35 < V_21 -> V_35 )
V_69 = V_21 ;
}
if ( V_21 == V_29 -> V_69 )
V_70 = true ;
}
if ( ! V_69 || ( V_68 && V_69 -> V_35 < V_68 -> V_35 ) )
V_69 = V_68 ;
if ( V_69 )
V_29 -> V_69 = V_69 ;
return V_69 ;
}
static struct V_21 * F_41 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_21 * V_68 = NULL , * V_69 = NULL , * V_21 ;
struct V_37 * V_38 ;
bool V_70 = false ;
F_23 (bond, slave, iter) {
if ( ! F_24 ( V_21 ) )
continue;
if ( ! V_70 ) {
if ( ! V_68 || V_68 -> V_35 < V_21 -> V_35 )
V_68 = V_21 ;
} else {
if ( ! V_69 || V_69 -> V_35 < V_21 -> V_35 )
V_69 = V_21 ;
}
if ( V_21 == V_29 -> V_69 )
V_70 = true ;
}
if ( ! V_69 || ( V_68 && V_69 -> V_35 < V_68 -> V_35 ) )
V_69 = V_68 ;
if ( V_69 )
V_29 -> V_69 = V_69 ;
return V_69 ;
}
static void F_42 ( struct V_8 * V_9 , T_1 V_71 [] )
{
if ( ! V_9 -> V_72 ) {
return;
}
if ( ! V_9 -> V_73 . V_74 ) {
if ( ! F_43 ( V_9 -> V_72 -> V_75 , 1 ) )
V_9 -> V_73 . V_74 = 1 ;
else
V_9 -> V_73 . V_74 = 0 ;
}
V_9 -> V_73 . V_76 = 0 ;
F_44 ( V_9 -> V_72 , V_71 ) ;
}
static void F_45 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_50 * V_77 ;
T_2 V_25 , V_27 ;
F_27 ( V_9 ) ;
V_77 = V_29 -> V_53 ;
V_25 = V_29 -> V_78 ;
for (; V_25 != V_79 ; V_25 = V_27 ) {
V_27 = V_77 [ V_25 ] . V_80 ;
if ( V_77 [ V_25 ] . V_21 == V_21 ) {
struct V_21 * V_45 = F_39 ( V_9 ) ;
if ( V_45 ) {
V_77 [ V_25 ] . V_21 = V_45 ;
if ( ! F_32 ( V_77 [ V_25 ] . V_56 ,
V_81 ) ) {
V_29 -> V_53 [ V_25 ] . V_59 = 1 ;
V_29 -> V_60 = 1 ;
V_29 -> V_82 =
V_83 ;
}
} else {
V_77 [ V_25 ] . V_21 = NULL ;
}
}
}
F_28 ( V_9 ) ;
F_46 ( & V_9 -> V_84 ) ;
if ( V_21 != V_9 -> V_72 ) {
F_42 ( V_9 , V_21 -> V_75 -> V_85 ) ;
}
F_47 ( & V_9 -> V_84 ) ;
}
static void F_48 ( struct V_50 * V_51 )
{
int V_6 ;
if ( ! V_51 -> V_21 ) {
return;
}
for ( V_6 = 0 ; V_6 < V_86 ; V_6 ++ ) {
struct V_2 * V_3 ;
V_3 = F_49 ( V_66 , V_63 ,
V_51 -> V_55 ,
V_51 -> V_21 -> V_75 ,
V_51 -> V_52 ,
V_51 -> V_56 ,
V_51 -> V_21 -> V_75 -> V_85 ,
V_51 -> V_56 ) ;
if ( ! V_3 ) {
F_50 ( L_2 ,
V_51 -> V_21 -> V_9 -> V_75 -> V_87 ) ;
continue;
}
V_3 -> V_75 = V_51 -> V_21 -> V_75 ;
if ( V_51 -> V_88 ) {
V_3 = F_51 ( V_3 , F_37 ( V_89 ) , V_51 -> V_88 ) ;
if ( ! V_3 ) {
F_50 ( L_3 ,
V_51 -> V_21 -> V_9 -> V_75 -> V_87 ) ;
continue;
}
}
F_52 ( V_3 ) ;
}
}
static void F_53 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_50 * V_51 ;
T_2 V_42 ;
F_27 ( V_9 ) ;
V_42 = V_29 -> V_78 ;
for (; V_42 != V_79 ;
V_42 = V_51 -> V_80 ) {
V_51 = & ( V_29 -> V_53 [ V_42 ] ) ;
if ( V_51 -> V_59 ) {
F_48 ( V_51 ) ;
if ( V_29 -> V_82 == 0 ) {
V_51 -> V_59 = 0 ;
}
}
}
V_29 -> V_90 = V_91 ;
F_28 ( V_9 ) ;
}
static void F_54 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_50 * V_51 ;
int V_59 = 0 ;
T_2 V_42 ;
F_27 ( V_9 ) ;
V_42 = V_29 -> V_78 ;
for (; V_42 != V_79 ;
V_42 = V_51 -> V_80 ) {
V_51 = & ( V_29 -> V_53 [ V_42 ] ) ;
if ( ( V_51 -> V_21 == V_21 ) &&
! F_32 ( V_51 -> V_56 , V_81 ) ) {
V_51 -> V_59 = 1 ;
V_59 = 1 ;
}
}
if ( V_59 ) {
V_29 -> V_60 = 1 ;
V_29 -> V_82 = V_83 ;
}
F_28 ( V_9 ) ;
}
static void F_55 ( struct V_8 * V_9 , T_3 V_92 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_50 * V_51 ;
T_2 V_42 ;
F_29 ( V_9 ) ;
V_42 = V_29 -> V_78 ;
for (; V_42 != V_79 ;
V_42 = V_51 -> V_80 ) {
V_51 = & ( V_29 -> V_53 [ V_42 ] ) ;
if ( ! V_51 -> V_21 ) {
F_50 ( L_4 ,
V_9 -> V_75 -> V_87 ) ;
continue;
}
if ( ( V_51 -> V_52 == V_92 ) &&
! F_32 ( V_51 -> V_21 -> V_75 -> V_85 ,
V_9 -> V_75 -> V_85 ) &&
! F_32 ( V_51 -> V_56 , V_81 ) ) {
V_51 -> V_59 = 1 ;
V_29 -> V_60 = 1 ;
}
}
F_30 ( V_9 ) ;
}
static struct V_21 * F_56 ( struct V_2 * V_3 , struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_1 * V_49 = V_1 ( V_3 ) ;
struct V_21 * V_45 , * V_72 ;
struct V_50 * V_51 ;
T_2 V_42 = 0 ;
F_29 ( V_9 ) ;
V_72 = F_57 ( V_9 -> V_72 ) ;
V_42 = F_2 ( ( T_1 * ) & V_49 -> V_55 , sizeof( V_49 -> V_55 ) ) ;
V_51 = & ( V_29 -> V_53 [ V_42 ] ) ;
if ( V_51 -> V_54 ) {
if ( ( V_51 -> V_52 == V_49 -> V_52 ) &&
( V_51 -> V_55 == V_49 -> V_55 ) ) {
if ( ! F_32 ( V_49 -> V_56 , V_81 ) ) {
memcpy ( V_51 -> V_56 , V_49 -> V_56 , V_58 ) ;
}
memcpy ( V_51 -> V_57 , V_49 -> V_57 , V_58 ) ;
V_45 = V_51 -> V_21 ;
if ( V_45 ) {
F_30 ( V_9 ) ;
return V_45 ;
}
} else {
if ( V_9 -> V_72 &&
V_51 -> V_21 != V_72 ) {
V_51 -> V_21 = V_72 ;
F_48 ( V_51 ) ;
}
}
}
V_45 = F_41 ( V_9 ) ;
if ( V_45 ) {
if ( ! ( V_51 -> V_54 &&
V_51 -> V_52 == V_49 -> V_52 ) ) {
T_2 V_93 = F_2 ( ( T_1 * ) & V_49 -> V_52 ,
sizeof( V_49 -> V_52 ) ) ;
F_58 ( V_9 , V_42 ) ;
F_59 ( V_9 , V_93 , V_42 ) ;
}
V_51 -> V_52 = V_49 -> V_52 ;
V_51 -> V_55 = V_49 -> V_55 ;
memcpy ( V_51 -> V_56 , V_49 -> V_56 , V_58 ) ;
memcpy ( V_51 -> V_57 , V_49 -> V_57 , V_58 ) ;
V_51 -> V_21 = V_45 ;
if ( ! F_32 ( V_51 -> V_56 , V_81 ) ) {
V_51 -> V_59 = 1 ;
V_9 -> V_73 . V_60 = 1 ;
} else {
V_51 -> V_59 = 0 ;
}
if ( ! F_60 ( V_3 , & V_51 -> V_88 ) )
V_51 -> V_88 = 0 ;
if ( ! V_51 -> V_54 ) {
T_2 V_94 = V_29 -> V_78 ;
V_29 -> V_78 = V_42 ;
V_51 -> V_80 = V_94 ;
if ( V_94 != V_79 ) {
V_29 -> V_53 [ V_94 ] . V_95 =
V_42 ;
}
V_51 -> V_54 = 1 ;
}
}
F_30 ( V_9 ) ;
return V_45 ;
}
static struct V_21 * F_61 ( struct V_2 * V_3 , struct V_8 * V_9 )
{
struct V_1 * V_49 = V_1 ( V_3 ) ;
struct V_21 * V_17 = NULL ;
if ( ! F_62 ( V_9 , V_49 -> V_57 ) )
return NULL ;
if ( V_49 -> V_65 == F_37 ( V_66 ) ) {
V_17 = F_56 ( V_3 , V_9 ) ;
if ( V_17 ) {
memcpy ( V_49 -> V_57 , V_17 -> V_75 -> V_85 , V_58 ) ;
}
F_38 ( L_5 ) ;
} else if ( V_49 -> V_65 == F_37 ( V_96 ) ) {
F_56 ( V_3 , V_9 ) ;
V_9 -> V_73 . V_90 = V_91 ;
F_55 ( V_9 , V_49 -> V_52 ) ;
F_38 ( L_6 ) ;
}
return V_17 ;
}
static void F_63 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_21 * V_45 ;
struct V_50 * V_51 ;
int V_59 ;
T_2 V_42 ;
F_27 ( V_9 ) ;
V_59 = 0 ;
V_42 = V_29 -> V_78 ;
for (; V_42 != V_79 ;
V_42 = V_51 -> V_80 ) {
V_51 = & ( V_29 -> V_53 [ V_42 ] ) ;
V_45 = F_39 ( V_9 ) ;
if ( V_45 && ( V_51 -> V_21 != V_45 ) ) {
V_51 -> V_21 = V_45 ;
V_51 -> V_59 = 1 ;
V_59 = 1 ;
}
}
if ( V_59 ) {
V_29 -> V_60 = 1 ;
}
F_28 ( V_9 ) ;
}
static void F_64 ( struct V_50 * V_12 )
{
V_12 -> V_80 = V_79 ;
V_12 -> V_95 = V_79 ;
V_12 -> V_54 = 0 ;
V_12 -> V_21 = NULL ;
V_12 -> V_88 = 0 ;
}
static void F_65 ( struct V_50 * V_12 )
{
V_12 -> V_97 = V_79 ;
V_12 -> V_98 = V_79 ;
V_12 -> V_99 = V_79 ;
}
static void F_66 ( struct V_50 * V_12 )
{
memset ( V_12 , 0 , sizeof( struct V_50 ) ) ;
F_64 ( V_12 ) ;
F_65 ( V_12 ) ;
}
static void F_67 ( struct V_8 * V_9 , T_2 V_25 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
T_2 V_27 = V_29 -> V_53 [ V_25 ] . V_80 ;
T_2 V_100 = V_29 -> V_53 [ V_25 ] . V_95 ;
if ( V_25 == V_29 -> V_78 )
V_29 -> V_78 = V_27 ;
if ( V_100 != V_79 )
V_29 -> V_53 [ V_100 ] . V_80 = V_27 ;
if ( V_27 != V_79 )
V_29 -> V_53 [ V_27 ] . V_95 = V_100 ;
}
static void F_58 ( struct V_8 * V_9 , T_2 V_25 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
T_2 V_27 = V_29 -> V_53 [ V_25 ] . V_99 ;
T_2 V_100 = V_29 -> V_53 [ V_25 ] . V_98 ;
V_29 -> V_53 [ V_25 ] . V_99 = V_79 ;
V_29 -> V_53 [ V_25 ] . V_98 = V_79 ;
if ( V_27 != V_79 )
V_29 -> V_53 [ V_27 ] . V_98 = V_100 ;
if ( V_100 == V_79 )
return;
if ( V_29 -> V_53 [ V_100 ] . V_97 == V_25 )
V_29 -> V_53 [ V_100 ] . V_97 = V_27 ;
else
V_29 -> V_53 [ V_100 ] . V_99 = V_27 ;
}
static void F_68 ( struct V_8 * V_9 , T_2 V_25 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_50 * V_12 = & ( V_29 -> V_53 [ V_25 ] ) ;
F_67 ( V_9 , V_25 ) ;
F_64 ( V_12 ) ;
F_58 ( V_9 , V_25 ) ;
}
static void F_59 ( struct V_8 * V_9 , T_2 V_101 , T_2 V_102 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
T_2 V_18 ;
V_29 -> V_53 [ V_102 ] . V_98 = V_101 ;
V_18 = V_29 -> V_53 [ V_101 ] . V_97 ;
V_29 -> V_53 [ V_102 ] . V_99 = V_18 ;
if ( V_18 != V_79 )
V_29 -> V_53 [ V_18 ] . V_98 = V_102 ;
V_29 -> V_53 [ V_101 ] . V_97 = V_102 ;
}
static void F_36 ( struct V_8 * V_9 , struct V_1 * V_49 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
T_2 V_101 = F_2 ( ( T_1 * ) & ( V_49 -> V_52 ) , sizeof( V_49 -> V_52 ) ) ;
T_2 V_25 ;
F_27 ( V_9 ) ;
V_25 = V_29 -> V_53 [ V_101 ] . V_97 ;
while ( V_25 != V_79 ) {
struct V_50 * V_12 = & ( V_29 -> V_53 [ V_25 ] ) ;
T_2 V_27 = V_12 -> V_99 ;
if ( V_12 -> V_52 == V_49 -> V_52 &&
! F_32 ( V_49 -> V_57 , V_12 -> V_57 ) )
F_68 ( V_9 , V_25 ) ;
V_25 = V_27 ;
}
F_28 ( V_9 ) ;
}
static int F_69 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_50 * V_32 ;
int V_30 = V_103 * sizeof( struct V_50 ) ;
int V_6 ;
V_32 = F_70 ( V_30 , V_33 ) ;
if ( ! V_32 )
return - 1 ;
F_27 ( V_9 ) ;
V_29 -> V_53 = V_32 ;
V_29 -> V_78 = V_79 ;
for ( V_6 = 0 ; V_6 < V_103 ; V_6 ++ ) {
F_66 ( V_29 -> V_53 + V_6 ) ;
}
F_28 ( V_9 ) ;
V_9 -> V_104 = F_33 ;
return 0 ;
}
static void F_71 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
F_27 ( V_9 ) ;
F_20 ( V_29 -> V_53 ) ;
V_29 -> V_53 = NULL ;
V_29 -> V_78 = V_79 ;
F_28 ( V_9 ) ;
}
static void F_72 ( struct V_8 * V_9 , unsigned short V_88 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
T_2 V_105 ;
F_27 ( V_9 ) ;
V_105 = V_29 -> V_78 ;
while ( V_105 != V_79 ) {
struct V_50 * V_106 = & ( V_29 -> V_53 [ V_105 ] ) ;
T_2 V_27 = V_29 -> V_53 [ V_105 ] . V_80 ;
if ( V_106 -> V_88 == V_88 )
F_68 ( V_9 , V_105 ) ;
V_105 = V_27 ;
}
F_28 ( V_9 ) ;
}
static void F_73 ( struct V_21 * V_21 , T_1 V_107 [] ,
T_4 V_108 )
{
struct V_109 V_110 ;
struct V_2 * V_3 ;
int V_30 = sizeof( struct V_109 ) ;
char * V_111 ;
memset ( & V_110 , 0 , V_30 ) ;
memcpy ( V_110 . V_56 , V_107 , V_58 ) ;
memcpy ( V_110 . V_57 , V_107 , V_58 ) ;
V_110 . type = F_34 ( V_112 ) ;
V_3 = F_74 ( V_30 ) ;
if ( ! V_3 )
return;
V_111 = F_75 ( V_3 , V_30 ) ;
memcpy ( V_111 , & V_110 , V_30 ) ;
F_76 ( V_3 ) ;
V_3 -> V_113 = V_3 -> V_114 + V_115 ;
V_3 -> V_62 = V_110 . type ;
V_3 -> V_116 = V_117 ;
V_3 -> V_75 = V_21 -> V_75 ;
if ( V_108 ) {
V_3 = F_51 ( V_3 , F_37 ( V_89 ) , V_108 ) ;
if ( ! V_3 ) {
F_50 ( L_3 ,
V_21 -> V_9 -> V_75 -> V_87 ) ;
return;
}
}
F_77 ( V_3 ) ;
}
static void F_44 ( struct V_21 * V_21 , T_1 V_107 [] )
{
struct V_8 * V_9 = F_78 ( V_21 ) ;
struct V_118 * V_119 ;
struct V_37 * V_38 ;
F_73 ( V_21 , V_107 , 0 ) ;
F_79 () ;
F_80 (bond->dev, upper, iter) {
if ( V_119 -> V_120 & V_121 )
F_73 ( V_21 , V_107 ,
F_81 ( V_119 ) ) ;
}
F_82 () ;
}
static int F_83 ( struct V_21 * V_21 , T_1 V_71 [] )
{
struct V_118 * V_75 = V_21 -> V_75 ;
struct V_122 V_123 ;
if ( V_21 -> V_9 -> V_124 . V_125 == V_126 ) {
memcpy ( V_75 -> V_85 , V_71 , V_75 -> V_127 ) ;
return 0 ;
}
memcpy ( V_123 . V_128 , V_71 , V_75 -> V_127 ) ;
V_123 . V_129 = V_75 -> type ;
if ( F_84 ( V_75 , & V_123 ) ) {
F_50 ( L_7
L_8 ,
V_21 -> V_9 -> V_75 -> V_87 , V_75 -> V_87 ) ;
return - V_130 ;
}
return 0 ;
}
static void F_85 ( struct V_21 * V_131 , struct V_21 * V_132 )
{
T_1 V_133 [ V_58 ] ;
memcpy ( V_133 , V_131 -> V_75 -> V_85 , V_58 ) ;
F_83 ( V_131 , V_132 -> V_75 -> V_85 ) ;
F_83 ( V_132 , V_133 ) ;
}
static void F_86 ( struct V_8 * V_9 , struct V_21 * V_131 ,
struct V_21 * V_132 )
{
int V_134 = ( F_24 ( V_131 ) != F_24 ( V_132 ) ) ;
struct V_21 * V_135 = NULL ;
F_87 () ;
if ( F_24 ( V_131 ) ) {
F_44 ( V_131 , V_131 -> V_75 -> V_85 ) ;
if ( V_9 -> V_73 . V_136 ) {
F_54 ( V_9 , V_131 ) ;
}
} else {
V_135 = V_131 ;
}
if ( F_24 ( V_132 ) ) {
F_44 ( V_132 , V_132 -> V_75 -> V_85 ) ;
if ( V_9 -> V_73 . V_136 ) {
F_54 ( V_9 , V_132 ) ;
}
} else {
V_135 = V_132 ;
}
if ( V_9 -> V_73 . V_136 && V_134 ) {
F_42 ( V_9 ,
V_135 -> V_75 -> V_85 ) ;
}
}
static void F_88 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
int V_137 ;
int V_138 ;
struct V_21 * V_139 ;
V_137 = ! F_32 ( V_21 -> V_140 ,
V_21 -> V_75 -> V_85 ) ;
V_138 = ! F_32 ( V_21 -> V_140 ,
V_9 -> V_75 -> V_85 ) ;
if ( V_137 && V_138 ) {
V_139 = F_89 ( V_9 , V_21 -> V_140 ) ;
if ( V_139 ) {
F_85 ( V_21 , V_139 ) ;
F_86 ( V_9 , V_21 , V_139 ) ;
}
}
}
static int F_90 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
struct V_21 * V_141 = V_9 -> V_72 ;
struct V_21 * V_142 , * V_143 = NULL ;
struct V_37 * V_38 ;
if ( ! F_91 ( V_9 ) ) {
return 0 ;
}
if ( ! F_32 ( V_21 -> V_140 , V_9 -> V_75 -> V_85 ) ) {
if ( ! F_89 ( V_9 , V_21 -> V_75 -> V_85 ) )
return 0 ;
F_83 ( V_21 , V_9 -> V_75 -> V_85 ) ;
}
F_40 (bond, tmp_slave1, iter) {
if ( ! F_89 ( V_9 , V_142 -> V_140 ) ) {
V_143 = V_142 ;
break;
}
if ( ! V_141 ) {
if ( F_32 ( V_142 -> V_75 -> V_85 ,
V_9 -> V_75 -> V_85 ) ) {
V_141 = V_142 ;
}
}
}
if ( V_143 ) {
F_83 ( V_21 , V_143 -> V_140 ) ;
F_92 ( L_9 ,
V_9 -> V_75 -> V_87 , V_21 -> V_75 -> V_87 ,
V_143 -> V_75 -> V_87 ) ;
} else if ( V_141 ) {
F_50 ( L_10 ,
V_9 -> V_75 -> V_87 , V_21 -> V_75 -> V_87 ) ;
return - V_144 ;
}
return 0 ;
}
static int F_93 ( struct V_8 * V_9 , void * V_71 )
{
struct V_21 * V_21 , * V_145 ;
struct V_37 * V_38 ;
struct V_122 V_146 ;
char V_147 [ V_58 ] ;
int V_148 ;
if ( V_9 -> V_73 . V_136 )
return 0 ;
F_40 (bond, slave, iter) {
memcpy ( V_147 , V_21 -> V_75 -> V_85 , V_58 ) ;
V_148 = F_84 ( V_21 -> V_75 , V_71 ) ;
memcpy ( V_21 -> V_75 -> V_85 , V_147 , V_58 ) ;
if ( V_148 )
goto V_149;
}
return 0 ;
V_149:
memcpy ( V_146 . V_128 , V_9 -> V_75 -> V_85 , V_9 -> V_75 -> V_127 ) ;
V_146 . V_129 = V_9 -> V_75 -> type ;
F_40 (bond, rollback_slave, iter) {
if ( V_145 == V_21 )
break;
memcpy ( V_147 , V_145 -> V_75 -> V_85 , V_58 ) ;
F_84 ( V_145 -> V_75 , & V_146 ) ;
memcpy ( V_145 -> V_75 -> V_85 , V_147 , V_58 ) ;
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
V_9 -> V_73 . V_136 = 1 ;
V_148 = F_69 ( V_9 ) ;
if ( V_148 ) {
F_19 ( V_9 ) ;
return V_148 ;
}
} else {
V_9 -> V_73 . V_136 = 0 ;
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
int F_96 ( struct V_2 * V_3 , struct V_118 * V_150 )
{
struct V_8 * V_9 = F_97 ( V_150 ) ;
struct V_151 * V_152 ;
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_21 * V_17 = NULL ;
static const T_3 V_153 = F_98 ( 0xffffffff ) ;
int V_5 = 0 ;
int V_154 = 1 ;
T_2 V_42 = 0 ;
const T_1 * V_4 = NULL ;
int V_148 = 1 ;
struct V_155 * V_156 ;
F_76 ( V_3 ) ;
V_152 = F_99 ( V_3 ) ;
switch ( F_100 ( V_3 -> V_62 ) ) {
case V_157 : {
const struct V_158 * V_159 = F_101 ( V_3 ) ;
if ( F_32 ( V_152 -> V_160 , V_81 ) ||
( V_159 -> V_161 == V_153 ) ||
( V_159 -> V_62 == V_162 ) ) {
V_154 = 0 ;
break;
}
V_4 = ( char * ) & ( V_159 -> V_161 ) ;
V_5 = sizeof( V_159 -> V_161 ) ;
}
break;
case V_163 :
if ( F_32 ( V_152 -> V_160 , V_81 ) ) {
V_154 = 0 ;
break;
}
if ( F_32 ( V_152 -> V_160 , V_164 ) ) {
V_154 = 0 ;
break;
}
V_156 = F_102 ( V_3 ) ;
if ( F_103 ( & V_156 -> V_165 ) ) {
V_154 = 0 ;
break;
}
V_4 = ( char * ) & ( F_102 ( V_3 ) -> V_161 ) ;
V_5 = sizeof( F_102 ( V_3 ) -> V_161 ) ;
break;
case V_166 :
if ( F_104 ( V_3 ) -> V_167 != V_168 ) {
V_154 = 0 ;
break;
}
if ( F_104 ( V_3 ) -> V_169 != V_170 ) {
V_154 = 0 ;
break;
}
V_4 = ( char * ) V_152 -> V_160 ;
V_5 = V_58 ;
break;
case V_63 :
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
V_42 = F_2 ( V_4 , V_5 ) ;
V_17 = F_26 ( V_9 , V_42 , V_3 -> V_171 ) ;
}
if ( ! V_17 ) {
V_17 = F_57 ( V_9 -> V_72 ) ;
V_29 -> V_172 += V_3 -> V_171 ;
}
if ( V_17 && F_24 ( V_17 ) ) {
if ( V_17 != F_57 ( V_9 -> V_72 ) ) {
memcpy ( V_152 -> V_173 ,
V_17 -> V_75 -> V_85 ,
V_58 ) ;
}
V_148 = F_105 ( V_9 , V_3 , V_17 -> V_75 ) ;
} else {
if ( V_17 ) {
F_8 ( V_9 ) ;
F_15 ( V_9 , V_17 , 0 ) ;
F_10 ( V_9 ) ;
}
}
if ( V_148 ) {
F_106 ( V_3 ) ;
}
return V_174 ;
}
void F_107 ( struct V_175 * V_176 )
{
struct V_8 * V_9 = F_108 ( V_176 , struct V_8 ,
V_177 . V_176 ) ;
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_37 * V_38 ;
struct V_21 * V_21 ;
F_109 ( & V_9 -> V_178 ) ;
if ( ! F_91 ( V_9 ) ) {
V_29 -> V_179 = 0 ;
V_29 -> V_180 = 0 ;
goto V_181;
}
V_29 -> V_179 ++ ;
V_29 -> V_180 ++ ;
if ( V_29 -> V_180 >= F_110 ( V_9 ) ) {
F_109 ( & V_9 -> V_84 ) ;
F_40 (bond, slave, iter)
F_44 ( V_21 , V_21 -> V_75 -> V_85 ) ;
F_111 ( & V_9 -> V_84 ) ;
V_29 -> V_180 = 0 ;
}
if ( V_29 -> V_179 >= V_182 ) {
F_109 ( & V_9 -> V_84 ) ;
F_40 (bond, slave, iter) {
F_16 ( V_9 , V_21 , 1 ) ;
if ( V_21 == V_9 -> V_72 ) {
F_14 ( V_21 ) . V_22 =
V_29 -> V_172 /
V_16 ;
V_29 -> V_172 = 0 ;
}
}
F_111 ( & V_9 -> V_84 ) ;
V_29 -> V_179 = 0 ;
}
if ( V_29 -> V_136 ) {
if ( V_29 -> V_74 &&
( ++ V_29 -> V_76 >= V_183 ) ) {
F_111 ( & V_9 -> V_178 ) ;
if ( ! F_112 () ) {
F_109 ( & V_9 -> V_178 ) ;
goto V_181;
}
V_29 -> V_76 = 0 ;
F_43 ( V_9 -> V_72 -> V_75 , - 1 ) ;
V_29 -> V_74 = 0 ;
F_113 () ;
F_109 ( & V_9 -> V_178 ) ;
}
if ( V_29 -> F_63 ) {
V_29 -> F_63 = 0 ;
F_63 ( V_9 ) ;
}
if ( V_29 -> V_60 ) {
if ( V_29 -> V_90 ) {
-- V_29 -> V_90 ;
} else {
F_53 ( V_9 ) ;
if ( V_29 -> V_82 ) {
-- V_29 -> V_82 ;
} else {
V_29 -> V_60 = 0 ;
}
}
}
}
V_181:
F_114 ( V_9 -> V_184 , & V_9 -> V_177 , V_185 ) ;
F_111 ( & V_9 -> V_178 ) ;
}
int F_115 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
int V_148 ;
V_148 = F_83 ( V_21 , V_21 -> V_140 ) ;
if ( V_148 ) {
return V_148 ;
}
V_148 = F_90 ( V_9 , V_21 ) ;
if ( V_148 ) {
return V_148 ;
}
F_13 ( V_21 ) ;
V_9 -> V_73 . V_179 = V_182 ;
if ( V_9 -> V_73 . V_136 ) {
V_9 -> V_73 . F_63 = 1 ;
}
return 0 ;
}
void F_116 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
if ( F_91 ( V_9 ) )
F_88 ( V_9 , V_21 ) ;
F_16 ( V_9 , V_21 , 0 ) ;
if ( V_9 -> V_73 . V_136 ) {
V_9 -> V_73 . V_69 = NULL ;
F_45 ( V_9 , V_21 ) ;
}
}
void F_117 ( struct V_8 * V_9 , struct V_21 * V_21 , char V_186 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
if ( V_186 == V_187 ) {
F_16 ( V_9 , V_21 , 0 ) ;
if ( V_9 -> V_73 . V_136 ) {
F_45 ( V_9 , V_21 ) ;
}
} else if ( V_186 == V_188 ) {
V_29 -> V_179 = V_182 ;
if ( V_9 -> V_73 . V_136 ) {
V_9 -> V_73 . F_63 = 1 ;
}
}
}
void F_118 ( struct V_8 * V_9 , struct V_21 * V_189 )
__releases( &bond->curr_slave_lock
int F_119 ( struct V_118 * V_150 , void * V_71 )
__acquires( &bond->lock
void F_120 ( struct V_8 * V_9 , unsigned short V_88 )
{
if ( V_9 -> V_73 . V_136 ) {
F_72 ( V_9 , V_88 ) ;
}
}
