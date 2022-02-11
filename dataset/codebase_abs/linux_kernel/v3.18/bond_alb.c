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
static inline void F_3 ( struct V_8 * V_9 , int V_10 )
{
if ( V_10 ) {
V_9 -> V_11 = 1 + V_9 -> V_12 /
V_13 ;
V_9 -> V_12 = 0 ;
}
V_9 -> V_14 = NULL ;
V_9 -> V_15 = V_16 ;
V_9 -> V_17 = V_16 ;
}
static inline void F_4 ( struct V_18 * V_18 )
{
F_5 ( V_18 ) . V_19 = 0 ;
F_5 ( V_18 ) . V_20 = V_16 ;
}
static void F_6 ( struct V_21 * V_22 , struct V_18 * V_18 ,
int V_10 )
{
struct V_8 * V_23 ;
T_2 V_24 ;
V_23 = F_7 ( V_22 ) . V_25 ;
if ( V_23 ) {
V_24 = F_5 ( V_18 ) . V_20 ;
while ( V_24 != V_16 ) {
T_2 V_26 = V_23 [ V_24 ] . V_15 ;
F_3 ( & V_23 [ V_24 ] , V_10 ) ;
V_24 = V_26 ;
}
}
F_4 ( V_18 ) ;
}
static void F_8 ( struct V_21 * V_22 , struct V_18 * V_18 ,
int V_10 )
{
F_9 ( & V_22 -> V_27 ) ;
F_6 ( V_22 , V_18 , V_10 ) ;
F_10 ( & V_22 -> V_27 ) ;
}
static int F_11 ( struct V_21 * V_22 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
int V_30 = V_31 * sizeof( struct V_8 ) ;
struct V_8 * V_32 ;
int V_6 ;
V_32 = F_12 ( V_30 , V_33 ) ;
if ( ! V_32 )
return - 1 ;
F_9 ( & V_22 -> V_27 ) ;
V_29 -> V_25 = V_32 ;
for ( V_6 = 0 ; V_6 < V_31 ; V_6 ++ )
F_3 ( & V_29 -> V_25 [ V_6 ] , 0 ) ;
F_10 ( & V_22 -> V_27 ) ;
return 0 ;
}
static void F_13 ( struct V_21 * V_22 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
F_9 ( & V_22 -> V_27 ) ;
F_14 ( V_29 -> V_25 ) ;
V_29 -> V_25 = NULL ;
F_10 ( & V_22 -> V_27 ) ;
}
static long long F_15 ( struct V_18 * V_18 )
{
return ( V_34 ) ( V_18 -> V_35 << 20 ) -
( V_34 ) ( F_5 ( V_18 ) . V_19 << 3 ) ;
}
static struct V_18 * F_16 ( struct V_21 * V_22 )
{
struct V_18 * V_18 , * V_36 ;
struct V_37 * V_38 ;
long long V_39 ;
V_36 = NULL ;
V_39 = V_40 ;
F_17 (bond, slave, iter) {
if ( F_18 ( V_18 ) ) {
long long V_41 = F_15 ( V_18 ) ;
if ( V_39 < V_41 ) {
V_36 = V_18 ;
V_39 = V_41 ;
}
}
}
return V_36 ;
}
static struct V_18 * F_19 ( struct V_21 * V_22 , T_2 V_42 ,
T_2 V_43 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
struct V_8 * V_44 ;
struct V_18 * V_45 ;
V_44 = V_29 -> V_25 ;
V_45 = V_44 [ V_42 ] . V_14 ;
if ( ! V_45 ) {
V_45 = F_16 ( V_22 ) ;
if ( V_45 ) {
struct V_46 * V_47 =
& ( F_5 ( V_45 ) ) ;
T_2 V_26 = V_47 -> V_20 ;
V_44 [ V_42 ] . V_14 = V_45 ;
V_44 [ V_42 ] . V_15 = V_26 ;
V_44 [ V_42 ] . V_17 = V_16 ;
if ( V_26 != V_16 )
V_44 [ V_26 ] . V_17 = V_42 ;
V_47 -> V_20 = V_42 ;
V_47 -> V_19 +=
V_44 [ V_42 ] . V_11 ;
}
}
if ( V_45 )
V_44 [ V_42 ] . V_12 += V_43 ;
return V_45 ;
}
static struct V_18 * F_20 ( struct V_21 * V_22 , T_2 V_42 ,
T_2 V_43 )
{
struct V_18 * V_14 ;
F_21 ( & V_22 -> V_27 ) ;
V_14 = F_19 ( V_22 , V_42 , V_43 ) ;
F_22 ( & V_22 -> V_27 ) ;
return V_14 ;
}
static void F_23 ( struct V_21 * V_22 , struct V_1 * V_48 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
struct V_49 * V_50 ;
T_2 V_42 ;
F_9 ( & V_22 -> V_27 ) ;
V_42 = F_2 ( ( T_1 * ) & ( V_48 -> V_51 ) , sizeof( V_48 -> V_51 ) ) ;
V_50 = & ( V_29 -> V_52 [ V_42 ] ) ;
if ( ( V_50 -> V_53 ) &&
( V_50 -> V_51 == V_48 -> V_54 ) &&
( V_50 -> V_54 == V_48 -> V_51 ) &&
( ! F_24 ( V_50 -> V_55 , V_48 -> V_56 ) ) ) {
F_25 ( V_50 -> V_55 , V_48 -> V_56 ) ;
V_50 -> V_57 = 1 ;
V_29 -> V_58 = 1 ;
}
F_10 ( & V_22 -> V_27 ) ;
}
static int F_26 ( const struct V_2 * V_3 , struct V_21 * V_22 ,
struct V_18 * V_18 )
{
struct V_1 * V_48 , V_59 ;
if ( V_3 -> V_60 != F_27 ( V_61 ) )
goto V_62;
V_48 = F_28 ( V_3 , 0 , sizeof( V_59 ) , & V_59 ) ;
if ( ! V_48 )
goto V_62;
F_29 ( V_22 , V_48 ) ;
if ( V_48 -> V_63 == F_30 ( V_64 ) ) {
F_23 ( V_22 , V_48 ) ;
F_31 ( V_22 -> V_65 , L_1 ) ;
}
V_62:
return V_66 ;
}
static struct V_18 * F_32 ( struct V_21 * V_22 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
struct V_18 * V_67 = NULL , * V_68 = NULL , * V_18 ;
struct V_37 * V_38 ;
bool V_69 = false ;
F_17 (bond, slave, iter) {
if ( ! F_18 ( V_18 ) )
continue;
if ( ! V_69 ) {
if ( ! V_67 || V_67 -> V_35 < V_18 -> V_35 )
V_67 = V_18 ;
} else {
if ( ! V_68 || V_68 -> V_35 < V_18 -> V_35 )
V_68 = V_18 ;
}
if ( V_18 == V_29 -> V_68 )
V_69 = true ;
}
if ( ! V_68 || ( V_67 && V_68 -> V_35 < V_67 -> V_35 ) )
V_68 = V_67 ;
if ( V_68 )
V_29 -> V_68 = V_68 ;
return V_68 ;
}
static struct V_18 * F_33 ( struct V_21 * V_22 )
{
struct V_18 * V_68 ;
F_34 () ;
F_35 () ;
V_68 = F_32 ( V_22 ) ;
F_36 () ;
return V_68 ;
}
static void F_37 ( struct V_21 * V_22 , T_1 V_70 [] )
{
struct V_18 * V_71 = F_38 ( V_22 -> V_72 ) ;
if ( ! V_71 )
return;
if ( ! V_22 -> V_73 . V_74 ) {
if ( ! F_39 ( V_71 -> V_65 , 1 ) )
V_22 -> V_73 . V_74 = 1 ;
else
V_22 -> V_73 . V_74 = 0 ;
}
V_22 -> V_73 . V_75 = 0 ;
F_40 ( V_71 , V_70 , true ) ;
}
static void F_41 ( struct V_21 * V_22 , struct V_18 * V_18 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
struct V_49 * V_76 ;
T_2 V_24 , V_26 ;
F_9 ( & V_22 -> V_27 ) ;
V_76 = V_29 -> V_52 ;
V_24 = V_29 -> V_77 ;
for (; V_24 != V_78 ; V_24 = V_26 ) {
V_26 = V_76 [ V_24 ] . V_79 ;
if ( V_76 [ V_24 ] . V_18 == V_18 ) {
struct V_18 * V_45 = F_33 ( V_22 ) ;
if ( V_45 ) {
V_76 [ V_24 ] . V_18 = V_45 ;
if ( ! F_24 ( V_76 [ V_24 ] . V_55 ,
V_80 ) ) {
V_29 -> V_52 [ V_24 ] . V_57 = 1 ;
V_29 -> V_58 = 1 ;
V_29 -> V_81 =
V_82 ;
}
} else {
V_76 [ V_24 ] . V_18 = NULL ;
}
}
}
F_10 ( & V_22 -> V_27 ) ;
if ( V_18 != F_38 ( V_22 -> V_72 ) )
F_37 ( V_22 , V_18 -> V_65 -> V_83 ) ;
}
static void F_42 ( struct V_49 * V_50 )
{
int V_6 ;
if ( ! V_50 -> V_18 )
return;
for ( V_6 = 0 ; V_6 < V_84 ; V_6 ++ ) {
struct V_2 * V_3 ;
V_3 = F_43 ( V_64 , V_61 ,
V_50 -> V_54 ,
V_50 -> V_18 -> V_65 ,
V_50 -> V_51 ,
V_50 -> V_55 ,
V_50 -> V_18 -> V_65 -> V_83 ,
V_50 -> V_55 ) ;
if ( ! V_3 ) {
F_44 ( V_50 -> V_18 -> V_22 -> V_65 ,
L_2 ) ;
continue;
}
V_3 -> V_65 = V_50 -> V_18 -> V_65 ;
if ( V_50 -> V_85 ) {
V_3 = F_45 ( V_3 , F_30 ( V_86 ) , V_50 -> V_85 ) ;
if ( ! V_3 ) {
F_44 ( V_50 -> V_18 -> V_22 -> V_65 ,
L_3 ) ;
continue;
}
}
F_46 ( V_3 ) ;
}
}
static void F_47 ( struct V_21 * V_22 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
struct V_49 * V_50 ;
T_2 V_42 ;
F_9 ( & V_22 -> V_27 ) ;
V_42 = V_29 -> V_77 ;
for (; V_42 != V_78 ;
V_42 = V_50 -> V_79 ) {
V_50 = & ( V_29 -> V_52 [ V_42 ] ) ;
if ( V_50 -> V_57 ) {
F_42 ( V_50 ) ;
if ( V_29 -> V_81 == 0 )
V_50 -> V_57 = 0 ;
}
}
V_29 -> V_87 = V_88 ;
F_10 ( & V_22 -> V_27 ) ;
}
static void F_48 ( struct V_21 * V_22 , struct V_18 * V_18 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
struct V_49 * V_50 ;
int V_57 = 0 ;
T_2 V_42 ;
F_9 ( & V_22 -> V_27 ) ;
V_42 = V_29 -> V_77 ;
for (; V_42 != V_78 ;
V_42 = V_50 -> V_79 ) {
V_50 = & ( V_29 -> V_52 [ V_42 ] ) ;
if ( ( V_50 -> V_18 == V_18 ) &&
! F_24 ( V_50 -> V_55 , V_80 ) ) {
V_50 -> V_57 = 1 ;
V_57 = 1 ;
}
}
if ( V_57 ) {
V_29 -> V_58 = 1 ;
V_29 -> V_81 = V_82 ;
}
F_10 ( & V_22 -> V_27 ) ;
}
static void F_49 ( struct V_21 * V_22 , T_3 V_89 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
struct V_49 * V_50 ;
T_2 V_42 ;
F_21 ( & V_22 -> V_27 ) ;
V_42 = V_29 -> V_77 ;
for (; V_42 != V_78 ;
V_42 = V_50 -> V_79 ) {
V_50 = & ( V_29 -> V_52 [ V_42 ] ) ;
if ( ! V_50 -> V_18 ) {
F_44 ( V_22 -> V_65 , L_4 ) ;
continue;
}
if ( ( V_50 -> V_51 == V_89 ) &&
! F_24 ( V_50 -> V_18 -> V_65 -> V_83 ,
V_22 -> V_65 -> V_83 ) &&
! F_24 ( V_50 -> V_55 , V_80 ) ) {
V_50 -> V_57 = 1 ;
V_29 -> V_58 = 1 ;
}
}
F_22 ( & V_22 -> V_27 ) ;
}
static struct V_18 * F_50 ( struct V_2 * V_3 , struct V_21 * V_22 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
struct V_1 * V_48 = V_1 ( V_3 ) ;
struct V_18 * V_45 , * V_72 ;
struct V_49 * V_50 ;
T_2 V_42 = 0 ;
F_21 ( & V_22 -> V_27 ) ;
V_72 = F_51 ( V_22 -> V_72 ) ;
V_42 = F_2 ( ( T_1 * ) & V_48 -> V_54 , sizeof( V_48 -> V_54 ) ) ;
V_50 = & ( V_29 -> V_52 [ V_42 ] ) ;
if ( V_50 -> V_53 ) {
if ( ( V_50 -> V_51 == V_48 -> V_51 ) &&
( V_50 -> V_54 == V_48 -> V_54 ) ) {
if ( ! F_24 ( V_48 -> V_55 , V_80 ) ) {
F_25 ( V_50 -> V_55 , V_48 -> V_55 ) ;
}
F_25 ( V_50 -> V_56 , V_48 -> V_56 ) ;
V_45 = V_50 -> V_18 ;
if ( V_45 ) {
F_22 ( & V_22 -> V_27 ) ;
return V_45 ;
}
} else {
if ( V_72 &&
V_50 -> V_18 != V_72 ) {
V_50 -> V_18 = V_72 ;
F_42 ( V_50 ) ;
}
}
}
V_45 = F_32 ( V_22 ) ;
if ( V_45 ) {
if ( ! ( V_50 -> V_53 &&
V_50 -> V_51 == V_48 -> V_51 ) ) {
T_2 V_90 = F_2 ( ( T_1 * ) & V_48 -> V_51 ,
sizeof( V_48 -> V_51 ) ) ;
F_52 ( V_22 , V_42 ) ;
F_53 ( V_22 , V_90 , V_42 ) ;
}
V_50 -> V_51 = V_48 -> V_51 ;
V_50 -> V_54 = V_48 -> V_54 ;
F_25 ( V_50 -> V_55 , V_48 -> V_55 ) ;
F_25 ( V_50 -> V_56 , V_48 -> V_56 ) ;
V_50 -> V_18 = V_45 ;
if ( ! F_24 ( V_50 -> V_55 , V_80 ) ) {
V_50 -> V_57 = 1 ;
V_22 -> V_73 . V_58 = 1 ;
} else {
V_50 -> V_57 = 0 ;
}
if ( F_54 ( V_3 , & V_50 -> V_85 ) )
V_50 -> V_85 = 0 ;
if ( ! V_50 -> V_53 ) {
T_2 V_91 = V_29 -> V_77 ;
V_29 -> V_77 = V_42 ;
V_50 -> V_79 = V_91 ;
if ( V_91 != V_78 ) {
V_29 -> V_52 [ V_91 ] . V_92 =
V_42 ;
}
V_50 -> V_53 = 1 ;
}
}
F_22 ( & V_22 -> V_27 ) ;
return V_45 ;
}
static struct V_18 * F_55 ( struct V_2 * V_3 , struct V_21 * V_22 )
{
struct V_1 * V_48 = V_1 ( V_3 ) ;
struct V_18 * V_14 = NULL ;
if ( ! F_56 ( V_22 , V_48 -> V_56 ) )
return NULL ;
if ( V_48 -> V_63 == F_30 ( V_64 ) ) {
V_14 = F_50 ( V_3 , V_22 ) ;
if ( V_14 )
F_25 ( V_48 -> V_56 , V_14 -> V_65 -> V_83 ) ;
F_31 ( V_22 -> V_65 , L_5 ) ;
} else if ( V_48 -> V_63 == F_30 ( V_93 ) ) {
F_50 ( V_3 , V_22 ) ;
V_22 -> V_73 . V_87 = V_88 ;
F_49 ( V_22 , V_48 -> V_51 ) ;
F_31 ( V_22 -> V_65 , L_6 ) ;
}
return V_14 ;
}
static void F_57 ( struct V_21 * V_22 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
struct V_18 * V_45 ;
struct V_49 * V_50 ;
int V_57 ;
T_2 V_42 ;
F_9 ( & V_22 -> V_27 ) ;
V_57 = 0 ;
V_42 = V_29 -> V_77 ;
for (; V_42 != V_78 ;
V_42 = V_50 -> V_79 ) {
V_50 = & ( V_29 -> V_52 [ V_42 ] ) ;
V_45 = F_32 ( V_22 ) ;
if ( V_45 && ( V_50 -> V_18 != V_45 ) ) {
V_50 -> V_18 = V_45 ;
V_50 -> V_57 = 1 ;
V_57 = 1 ;
}
}
if ( V_57 )
V_29 -> V_58 = 1 ;
F_10 ( & V_22 -> V_27 ) ;
}
static void F_58 ( struct V_49 * V_9 )
{
V_9 -> V_79 = V_78 ;
V_9 -> V_92 = V_78 ;
V_9 -> V_53 = 0 ;
V_9 -> V_18 = NULL ;
V_9 -> V_85 = 0 ;
}
static void F_59 ( struct V_49 * V_9 )
{
V_9 -> V_94 = V_78 ;
V_9 -> V_95 = V_78 ;
V_9 -> V_96 = V_78 ;
}
static void F_60 ( struct V_49 * V_9 )
{
memset ( V_9 , 0 , sizeof( struct V_49 ) ) ;
F_58 ( V_9 ) ;
F_59 ( V_9 ) ;
}
static void F_61 ( struct V_21 * V_22 , T_2 V_24 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
T_2 V_26 = V_29 -> V_52 [ V_24 ] . V_79 ;
T_2 V_97 = V_29 -> V_52 [ V_24 ] . V_92 ;
if ( V_24 == V_29 -> V_77 )
V_29 -> V_77 = V_26 ;
if ( V_97 != V_78 )
V_29 -> V_52 [ V_97 ] . V_79 = V_26 ;
if ( V_26 != V_78 )
V_29 -> V_52 [ V_26 ] . V_92 = V_97 ;
}
static void F_52 ( struct V_21 * V_22 , T_2 V_24 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
T_2 V_26 = V_29 -> V_52 [ V_24 ] . V_96 ;
T_2 V_97 = V_29 -> V_52 [ V_24 ] . V_95 ;
V_29 -> V_52 [ V_24 ] . V_96 = V_78 ;
V_29 -> V_52 [ V_24 ] . V_95 = V_78 ;
if ( V_26 != V_78 )
V_29 -> V_52 [ V_26 ] . V_95 = V_97 ;
if ( V_97 == V_78 )
return;
if ( V_29 -> V_52 [ V_97 ] . V_94 == V_24 )
V_29 -> V_52 [ V_97 ] . V_94 = V_26 ;
else
V_29 -> V_52 [ V_97 ] . V_96 = V_26 ;
}
static void F_62 ( struct V_21 * V_22 , T_2 V_24 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
struct V_49 * V_9 = & ( V_29 -> V_52 [ V_24 ] ) ;
F_61 ( V_22 , V_24 ) ;
F_58 ( V_9 ) ;
F_52 ( V_22 , V_24 ) ;
}
static void F_53 ( struct V_21 * V_22 , T_2 V_98 , T_2 V_99 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
T_2 V_15 ;
V_29 -> V_52 [ V_99 ] . V_95 = V_98 ;
V_15 = V_29 -> V_52 [ V_98 ] . V_94 ;
V_29 -> V_52 [ V_99 ] . V_96 = V_15 ;
if ( V_15 != V_78 )
V_29 -> V_52 [ V_15 ] . V_95 = V_99 ;
V_29 -> V_52 [ V_98 ] . V_94 = V_99 ;
}
static void F_29 ( struct V_21 * V_22 , struct V_1 * V_48 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
T_2 V_98 = F_2 ( ( T_1 * ) & ( V_48 -> V_51 ) , sizeof( V_48 -> V_51 ) ) ;
T_2 V_24 ;
F_9 ( & V_22 -> V_27 ) ;
V_24 = V_29 -> V_52 [ V_98 ] . V_94 ;
while ( V_24 != V_78 ) {
struct V_49 * V_9 = & ( V_29 -> V_52 [ V_24 ] ) ;
T_2 V_26 = V_9 -> V_96 ;
if ( V_9 -> V_51 == V_48 -> V_51 &&
! F_24 ( V_48 -> V_56 , V_9 -> V_56 ) )
F_62 ( V_22 , V_24 ) ;
V_24 = V_26 ;
}
F_10 ( & V_22 -> V_27 ) ;
}
static int F_63 ( struct V_21 * V_22 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
struct V_49 * V_32 ;
int V_30 = V_100 * sizeof( struct V_49 ) ;
int V_6 ;
V_32 = F_64 ( V_30 , V_33 ) ;
if ( ! V_32 )
return - 1 ;
F_9 ( & V_22 -> V_27 ) ;
V_29 -> V_52 = V_32 ;
V_29 -> V_77 = V_78 ;
for ( V_6 = 0 ; V_6 < V_100 ; V_6 ++ )
F_60 ( V_29 -> V_52 + V_6 ) ;
F_10 ( & V_22 -> V_27 ) ;
V_22 -> V_101 = F_26 ;
return 0 ;
}
static void F_65 ( struct V_21 * V_22 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
F_9 ( & V_22 -> V_27 ) ;
F_14 ( V_29 -> V_52 ) ;
V_29 -> V_52 = NULL ;
V_29 -> V_77 = V_78 ;
F_10 ( & V_22 -> V_27 ) ;
}
static void F_66 ( struct V_21 * V_22 , unsigned short V_85 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
T_2 V_102 ;
F_9 ( & V_22 -> V_27 ) ;
V_102 = V_29 -> V_77 ;
while ( V_102 != V_78 ) {
struct V_49 * V_103 = & ( V_29 -> V_52 [ V_102 ] ) ;
T_2 V_26 = V_29 -> V_52 [ V_102 ] . V_79 ;
if ( V_103 -> V_85 == V_85 )
F_62 ( V_22 , V_102 ) ;
V_102 = V_26 ;
}
F_10 ( & V_22 -> V_27 ) ;
}
static void F_67 ( struct V_18 * V_18 , T_1 V_104 [] ,
T_4 V_105 , T_5 V_106 )
{
struct V_107 V_108 ;
struct V_2 * V_3 ;
int V_30 = sizeof( struct V_107 ) ;
char * V_109 ;
memset ( & V_108 , 0 , V_30 ) ;
F_25 ( V_108 . V_55 , V_104 ) ;
F_25 ( V_108 . V_56 , V_104 ) ;
V_108 . type = F_27 ( V_110 ) ;
V_3 = F_68 ( V_30 ) ;
if ( ! V_3 )
return;
V_109 = F_69 ( V_3 , V_30 ) ;
memcpy ( V_109 , & V_108 , V_30 ) ;
F_70 ( V_3 ) ;
V_3 -> V_111 = V_3 -> V_112 + V_113 ;
V_3 -> V_60 = V_108 . type ;
V_3 -> V_114 = V_115 ;
V_3 -> V_65 = V_18 -> V_65 ;
if ( V_106 ) {
V_3 = F_45 ( V_3 , V_105 , V_106 ) ;
if ( ! V_3 ) {
F_44 ( V_18 -> V_22 -> V_65 , L_3 ) ;
return;
}
}
F_71 ( V_3 ) ;
}
static void F_40 ( struct V_18 * V_18 , T_1 V_104 [] ,
bool V_116 )
{
struct V_21 * V_22 = F_72 ( V_18 ) ;
struct V_117 * V_118 ;
struct V_37 * V_38 ;
struct V_119 * V_120 ;
F_67 ( V_18 , V_104 , 0 , 0 ) ;
F_35 () ;
F_73 (bond->dev, upper, iter) {
if ( F_74 ( V_118 ) && F_75 ( V_118 ) == 0 ) {
if ( V_116 &&
F_24 ( V_104 ,
V_118 -> V_83 ) ) {
F_67 ( V_18 , V_104 ,
F_76 ( V_118 ) ,
F_77 ( V_118 ) ) ;
} else if ( ! V_116 ) {
F_67 ( V_18 , V_118 -> V_83 ,
F_76 ( V_118 ) ,
F_77 ( V_118 ) ) ;
}
}
if ( F_78 ( V_118 ) && ! V_116 ) {
V_120 = F_79 ( V_22 -> V_65 , V_118 , 0 ) ;
if ( F_80 ( V_120 ) )
F_81 () ;
F_67 ( V_18 , V_118 -> V_83 ,
V_120 [ 0 ] . V_105 , V_120 [ 0 ] . V_85 ) ;
F_14 ( V_120 ) ;
}
}
F_36 () ;
}
static int F_82 ( struct V_18 * V_18 , T_1 V_70 [] )
{
struct V_117 * V_65 = V_18 -> V_65 ;
struct V_121 V_122 ;
if ( F_83 ( V_18 -> V_22 ) == V_123 ) {
memcpy ( V_65 -> V_83 , V_70 , V_65 -> V_124 ) ;
return 0 ;
}
memcpy ( V_122 . V_125 , V_70 , V_65 -> V_124 ) ;
V_122 . V_126 = V_65 -> type ;
if ( F_84 ( V_65 , & V_122 ) ) {
F_44 ( V_18 -> V_22 -> V_65 , L_7 ,
V_65 -> V_127 ) ;
return - V_128 ;
}
return 0 ;
}
static void F_85 ( struct V_18 * V_129 , struct V_18 * V_130 )
{
T_1 V_131 [ V_132 ] ;
F_25 ( V_131 , V_129 -> V_65 -> V_83 ) ;
F_82 ( V_129 , V_130 -> V_65 -> V_83 ) ;
F_82 ( V_130 , V_131 ) ;
}
static void F_86 ( struct V_21 * V_22 , struct V_18 * V_129 ,
struct V_18 * V_130 )
{
int V_133 = ( F_18 ( V_129 ) != F_18 ( V_130 ) ) ;
struct V_18 * V_134 = NULL ;
F_34 () ;
if ( F_18 ( V_129 ) ) {
F_40 ( V_129 , V_129 -> V_65 -> V_83 , false ) ;
if ( V_22 -> V_73 . V_135 ) {
F_48 ( V_22 , V_129 ) ;
}
} else {
V_134 = V_129 ;
}
if ( F_18 ( V_130 ) ) {
F_40 ( V_130 , V_130 -> V_65 -> V_83 , false ) ;
if ( V_22 -> V_73 . V_135 ) {
F_48 ( V_22 , V_130 ) ;
}
} else {
V_134 = V_130 ;
}
if ( V_22 -> V_73 . V_135 && V_133 ) {
F_37 ( V_22 ,
V_134 -> V_65 -> V_83 ) ;
}
}
static void F_87 ( struct V_21 * V_22 , struct V_18 * V_18 )
{
int V_136 ;
int V_137 ;
struct V_18 * V_138 ;
V_136 = ! F_24 ( V_18 -> V_139 ,
V_18 -> V_65 -> V_83 ) ;
V_137 = ! F_24 ( V_18 -> V_139 ,
V_22 -> V_65 -> V_83 ) ;
if ( V_136 && V_137 ) {
V_138 = F_88 ( V_22 , V_18 -> V_139 ) ;
if ( V_138 ) {
F_85 ( V_18 , V_138 ) ;
F_86 ( V_22 , V_18 , V_138 ) ;
}
}
}
static int F_89 ( struct V_21 * V_22 , struct V_18 * V_18 )
{
struct V_18 * V_140 = F_90 ( V_22 -> V_72 ) ;
struct V_18 * V_141 , * V_142 = NULL ;
struct V_37 * V_38 ;
if ( ! F_91 ( V_22 ) ) {
return 0 ;
}
if ( ! F_24 ( V_18 -> V_139 , V_22 -> V_65 -> V_83 ) ) {
if ( ! F_88 ( V_22 , V_18 -> V_65 -> V_83 ) )
return 0 ;
F_82 ( V_18 , V_22 -> V_65 -> V_83 ) ;
}
F_92 (bond, tmp_slave1, iter) {
if ( ! F_88 ( V_22 , V_141 -> V_139 ) ) {
V_142 = V_141 ;
break;
}
if ( ! V_140 ) {
if ( F_24 ( V_141 -> V_65 -> V_83 ,
V_22 -> V_65 -> V_83 ) ) {
V_140 = V_141 ;
}
}
}
if ( V_142 ) {
F_82 ( V_18 , V_142 -> V_139 ) ;
F_93 ( V_22 -> V_65 , L_8 ,
V_18 -> V_65 -> V_127 , V_142 -> V_65 -> V_127 ) ;
} else if ( V_140 ) {
F_44 ( V_22 -> V_65 , L_9 ,
V_18 -> V_65 -> V_127 ) ;
return - V_143 ;
}
return 0 ;
}
static int F_94 ( struct V_21 * V_22 , void * V_70 )
{
struct V_18 * V_18 , * V_144 ;
struct V_37 * V_38 ;
struct V_121 V_145 ;
char V_146 [ V_132 ] ;
int V_147 ;
if ( V_22 -> V_73 . V_135 )
return 0 ;
F_92 (bond, slave, iter) {
F_25 ( V_146 , V_18 -> V_65 -> V_83 ) ;
V_147 = F_84 ( V_18 -> V_65 , V_70 ) ;
F_25 ( V_18 -> V_65 -> V_83 , V_146 ) ;
if ( V_147 )
goto V_148;
}
return 0 ;
V_148:
memcpy ( V_145 . V_125 , V_22 -> V_65 -> V_83 , V_22 -> V_65 -> V_124 ) ;
V_145 . V_126 = V_22 -> V_65 -> type ;
F_92 (bond, rollback_slave, iter) {
if ( V_144 == V_18 )
break;
F_25 ( V_146 , V_144 -> V_65 -> V_83 ) ;
F_84 ( V_144 -> V_65 , & V_145 ) ;
F_25 ( V_144 -> V_65 -> V_83 , V_146 ) ;
}
return V_147 ;
}
int F_95 ( struct V_21 * V_22 , int V_135 )
{
int V_147 ;
V_147 = F_11 ( V_22 ) ;
if ( V_147 )
return V_147 ;
if ( V_135 ) {
V_22 -> V_73 . V_135 = 1 ;
V_147 = F_63 ( V_22 ) ;
if ( V_147 ) {
F_13 ( V_22 ) ;
return V_147 ;
}
} else {
V_22 -> V_73 . V_135 = 0 ;
}
return 0 ;
}
void F_96 ( struct V_21 * V_22 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
F_13 ( V_22 ) ;
if ( V_29 -> V_135 )
F_65 ( V_22 ) ;
}
static int F_97 ( struct V_2 * V_3 , struct V_21 * V_22 ,
struct V_18 * V_14 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
struct V_149 * V_150 = F_98 ( V_3 ) ;
if ( ! V_14 ) {
V_14 = F_51 ( V_22 -> V_72 ) ;
if ( V_22 -> V_151 . V_152 )
V_29 -> V_153 += V_3 -> V_154 ;
}
if ( V_14 && F_18 ( V_14 ) ) {
if ( V_14 != F_90 ( V_22 -> V_72 ) ) {
F_25 ( V_150 -> V_155 ,
V_14 -> V_65 -> V_83 ) ;
}
F_99 ( V_22 , V_3 , V_14 -> V_65 ) ;
goto V_62;
}
if ( V_14 && V_22 -> V_151 . V_152 ) {
F_21 ( & V_22 -> V_27 ) ;
F_6 ( V_22 , V_14 , 0 ) ;
F_22 ( & V_22 -> V_27 ) ;
}
F_100 ( V_3 ) ;
V_62:
return V_156 ;
}
int F_101 ( struct V_2 * V_3 , struct V_117 * V_157 )
{
struct V_21 * V_22 = F_102 ( V_157 ) ;
struct V_149 * V_150 ;
struct V_18 * V_14 = NULL ;
T_2 V_42 ;
F_70 ( V_3 ) ;
V_150 = F_98 ( V_3 ) ;
if ( ! F_103 ( V_150 -> V_158 ) ) {
switch ( V_3 -> V_60 ) {
case F_30 ( V_159 ) :
case F_30 ( V_160 ) :
case F_30 ( V_161 ) :
V_42 = F_104 ( V_22 , V_3 ) ;
if ( V_22 -> V_151 . V_152 ) {
V_14 = F_20 ( V_22 ,
V_42 & 0xFF ,
V_3 -> V_154 ) ;
} else {
struct V_162 * V_163 ;
unsigned int V_164 ;
V_163 = F_51 ( V_22 -> V_165 ) ;
V_164 = V_163 ? F_105 ( V_163 -> V_164 ) : 0 ;
if ( F_106 ( V_164 ) )
V_14 = V_163 -> V_166 [ V_42 %
V_164 ] ;
}
break;
}
}
return F_97 ( V_3 , V_22 , V_14 ) ;
}
int F_107 ( struct V_2 * V_3 , struct V_117 * V_157 )
{
struct V_21 * V_22 = F_102 ( V_157 ) ;
struct V_149 * V_150 ;
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
struct V_18 * V_14 = NULL ;
static const T_3 V_167 = F_108 ( 0xffffffff ) ;
int V_5 = 0 ;
bool V_168 = true ;
T_2 V_42 = 0 ;
const T_1 * V_4 = NULL ;
struct V_169 * V_170 ;
F_70 ( V_3 ) ;
V_150 = F_98 ( V_3 ) ;
switch ( F_109 ( V_3 -> V_60 ) ) {
case V_159 : {
const struct V_171 * V_172 = F_110 ( V_3 ) ;
if ( F_24 ( V_150 -> V_158 , V_80 ) ||
( V_172 -> V_173 == V_167 ) ||
( V_172 -> V_60 == V_174 ) ) {
V_168 = false ;
break;
}
V_4 = ( char * ) & ( V_172 -> V_173 ) ;
V_5 = sizeof( V_172 -> V_173 ) ;
}
break;
case V_161 :
if ( F_24 ( V_150 -> V_158 , V_80 ) ) {
V_168 = false ;
break;
}
if ( F_24 ( V_150 -> V_158 , V_175 ) ) {
V_168 = false ;
break;
}
V_170 = F_111 ( V_3 ) ;
if ( F_112 ( & V_170 -> V_176 ) ) {
V_168 = false ;
break;
}
V_4 = ( char * ) & ( F_111 ( V_3 ) -> V_173 ) ;
V_5 = sizeof( F_111 ( V_3 ) -> V_173 ) ;
break;
case V_160 :
if ( F_113 ( V_3 ) -> V_177 != V_178 ) {
V_168 = false ;
break;
}
if ( F_113 ( V_3 ) -> V_179 != V_180 ) {
V_168 = false ;
break;
}
V_4 = ( char * ) V_150 -> V_158 ;
V_5 = V_132 ;
break;
case V_61 :
V_168 = false ;
if ( V_29 -> V_135 )
V_14 = F_55 ( V_3 , V_22 ) ;
break;
default:
V_168 = false ;
break;
}
if ( V_168 ) {
V_42 = F_2 ( V_4 , V_5 ) ;
V_14 = F_20 ( V_22 , V_42 , V_3 -> V_154 ) ;
}
return F_97 ( V_3 , V_22 , V_14 ) ;
}
void F_114 ( struct V_181 * V_182 )
{
struct V_21 * V_22 = F_115 ( V_182 , struct V_21 ,
V_183 . V_182 ) ;
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
struct V_37 * V_38 ;
struct V_18 * V_18 ;
if ( ! F_91 ( V_22 ) ) {
V_29 -> V_184 = 0 ;
V_29 -> V_185 = 0 ;
goto V_186;
}
F_35 () ;
V_29 -> V_184 ++ ;
V_29 -> V_185 ++ ;
if ( V_29 -> V_185 >= F_116 ( V_22 ) ) {
bool V_116 ;
F_17 (bond, slave, iter) {
V_116 = ( V_18 != F_90 ( V_22 -> V_72 ) ||
V_29 -> V_135 ) ;
F_40 ( V_18 , V_18 -> V_65 -> V_83 ,
V_116 ) ;
}
V_29 -> V_185 = 0 ;
}
if ( V_29 -> V_184 >= V_187 ) {
F_17 (bond, slave, iter) {
F_8 ( V_22 , V_18 , 1 ) ;
if ( V_18 == F_90 ( V_22 -> V_72 ) ) {
F_5 ( V_18 ) . V_19 =
V_29 -> V_153 /
V_13 ;
V_29 -> V_153 = 0 ;
}
}
V_29 -> V_184 = 0 ;
}
if ( V_29 -> V_135 ) {
if ( V_29 -> V_74 &&
( ++ V_29 -> V_75 >= V_188 ) ) {
F_36 () ;
if ( ! F_117 () )
goto V_186;
V_29 -> V_75 = 0 ;
F_39 ( F_38 ( V_22 -> V_72 ) -> V_65 ,
- 1 ) ;
V_29 -> V_74 = 0 ;
F_118 () ;
F_35 () ;
}
if ( V_29 -> F_57 ) {
V_29 -> F_57 = 0 ;
F_57 ( V_22 ) ;
}
if ( V_29 -> V_58 ) {
if ( V_29 -> V_87 ) {
-- V_29 -> V_87 ;
} else {
F_47 ( V_22 ) ;
if ( V_29 -> V_81 )
-- V_29 -> V_81 ;
else
V_29 -> V_58 = 0 ;
}
}
}
F_36 () ;
V_186:
F_119 ( V_22 -> V_189 , & V_22 -> V_183 , V_190 ) ;
}
int F_120 ( struct V_21 * V_22 , struct V_18 * V_18 )
{
int V_147 ;
V_147 = F_82 ( V_18 , V_18 -> V_139 ) ;
if ( V_147 )
return V_147 ;
V_147 = F_89 ( V_22 , V_18 ) ;
if ( V_147 )
return V_147 ;
F_4 ( V_18 ) ;
V_22 -> V_73 . V_184 = V_187 ;
if ( V_22 -> V_73 . V_135 )
V_22 -> V_73 . F_57 = 1 ;
return 0 ;
}
void F_121 ( struct V_21 * V_22 , struct V_18 * V_18 )
{
if ( F_91 ( V_22 ) )
F_87 ( V_22 , V_18 ) ;
F_8 ( V_22 , V_18 , 0 ) ;
if ( V_22 -> V_73 . V_135 ) {
V_22 -> V_73 . V_68 = NULL ;
F_41 ( V_22 , V_18 ) ;
}
}
void F_122 ( struct V_21 * V_22 , struct V_18 * V_18 , char V_191 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
if ( V_191 == V_192 ) {
F_8 ( V_22 , V_18 , 0 ) ;
if ( V_22 -> V_73 . V_135 )
F_41 ( V_22 , V_18 ) ;
} else if ( V_191 == V_193 ) {
V_29 -> V_184 = V_187 ;
if ( V_22 -> V_73 . V_135 ) {
V_22 -> V_73 . F_57 = 1 ;
}
}
if ( F_123 ( V_22 ) ) {
if ( F_124 ( V_22 , NULL ) )
F_125 ( L_10 ) ;
}
}
void F_126 ( struct V_21 * V_22 , struct V_18 * V_194 )
{
struct V_18 * V_195 ;
struct V_18 * V_71 ;
V_71 = F_38 ( V_22 -> V_72 ) ;
if ( V_71 == V_194 )
return;
if ( V_71 && V_22 -> V_73 . V_74 ) {
F_39 ( V_71 -> V_65 , - 1 ) ;
V_22 -> V_73 . V_74 = 0 ;
V_22 -> V_73 . V_75 = 0 ;
}
V_195 = V_71 ;
F_127 ( V_22 -> V_72 , V_194 ) ;
if ( ! V_194 || ! F_91 ( V_22 ) )
return;
if ( ! V_195 )
V_195 = F_88 ( V_22 , V_22 -> V_65 -> V_83 ) ;
if ( V_195 )
F_8 ( V_22 , V_195 , 1 ) ;
F_8 ( V_22 , V_194 , 1 ) ;
if ( F_83 ( V_22 ) == V_123 ) {
struct V_121 V_145 ;
T_1 V_146 [ V_132 ] ;
F_25 ( V_146 , V_194 -> V_65 -> V_83 ) ;
memcpy ( V_145 . V_125 , V_22 -> V_65 -> V_83 , V_22 -> V_65 -> V_124 ) ;
V_145 . V_126 = V_22 -> V_65 -> type ;
F_84 ( V_194 -> V_65 , & V_145 ) ;
F_25 ( V_194 -> V_65 -> V_83 , V_146 ) ;
}
if ( V_195 ) {
F_85 ( V_195 , V_194 ) ;
F_86 ( V_22 , V_195 , V_194 ) ;
} else {
F_82 ( V_194 , V_22 -> V_65 -> V_83 ) ;
F_40 ( V_194 , V_22 -> V_65 -> V_83 ,
false ) ;
}
}
int F_128 ( struct V_117 * V_157 , void * V_70 )
{
struct V_21 * V_22 = F_102 ( V_157 ) ;
struct V_121 * V_145 = V_70 ;
struct V_18 * V_71 ;
struct V_18 * V_195 ;
int V_147 ;
if ( ! F_129 ( V_145 -> V_125 ) )
return - V_196 ;
V_147 = F_94 ( V_22 , V_70 ) ;
if ( V_147 )
return V_147 ;
memcpy ( V_157 -> V_83 , V_145 -> V_125 , V_157 -> V_124 ) ;
V_71 = F_38 ( V_22 -> V_72 ) ;
if ( ! V_71 )
return 0 ;
V_195 = F_88 ( V_22 , V_157 -> V_83 ) ;
if ( V_195 ) {
F_85 ( V_195 , V_71 ) ;
F_86 ( V_22 , V_195 , V_71 ) ;
} else {
F_82 ( V_71 , V_157 -> V_83 ) ;
F_40 ( V_71 ,
V_157 -> V_83 , false ) ;
if ( V_22 -> V_73 . V_135 ) {
F_48 ( V_22 , V_71 ) ;
}
}
return 0 ;
}
void F_130 ( struct V_21 * V_22 , unsigned short V_85 )
{
if ( V_22 -> V_73 . V_135 )
F_66 ( V_22 , V_85 ) ;
}
