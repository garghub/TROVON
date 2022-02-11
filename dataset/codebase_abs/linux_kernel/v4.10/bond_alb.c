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
return - V_34 ;
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
return ( V_35 ) ( V_18 -> V_36 << 20 ) -
( V_35 ) ( F_5 ( V_18 ) . V_19 << 3 ) ;
}
static struct V_18 * F_16 ( struct V_21 * V_22 )
{
struct V_18 * V_18 , * V_37 ;
struct V_38 * V_39 ;
long long V_40 ;
V_37 = NULL ;
V_40 = V_41 ;
F_17 (bond, slave, iter) {
if ( F_18 ( V_18 ) ) {
long long V_42 = F_15 ( V_18 ) ;
if ( V_40 < V_42 ) {
V_37 = V_18 ;
V_40 = V_42 ;
}
}
}
return V_37 ;
}
static struct V_18 * F_19 ( struct V_21 * V_22 , T_2 V_43 ,
T_2 V_44 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
struct V_8 * V_45 ;
struct V_18 * V_46 ;
V_45 = V_29 -> V_25 ;
V_46 = V_45 [ V_43 ] . V_14 ;
if ( ! V_46 ) {
V_46 = F_16 ( V_22 ) ;
if ( V_46 ) {
struct V_47 * V_48 =
& ( F_5 ( V_46 ) ) ;
T_2 V_26 = V_48 -> V_20 ;
V_45 [ V_43 ] . V_14 = V_46 ;
V_45 [ V_43 ] . V_15 = V_26 ;
V_45 [ V_43 ] . V_17 = V_16 ;
if ( V_26 != V_16 )
V_45 [ V_26 ] . V_17 = V_43 ;
V_48 -> V_20 = V_43 ;
V_48 -> V_19 +=
V_45 [ V_43 ] . V_11 ;
}
}
if ( V_46 )
V_45 [ V_43 ] . V_12 += V_44 ;
return V_46 ;
}
static struct V_18 * F_20 ( struct V_21 * V_22 , T_2 V_43 ,
T_2 V_44 )
{
struct V_18 * V_14 ;
F_21 ( & V_22 -> V_27 ) ;
V_14 = F_19 ( V_22 , V_43 , V_44 ) ;
F_22 ( & V_22 -> V_27 ) ;
return V_14 ;
}
static void F_23 ( struct V_21 * V_22 , struct V_1 * V_49 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
struct V_50 * V_51 ;
T_2 V_43 ;
F_9 ( & V_22 -> V_27 ) ;
V_43 = F_2 ( ( T_1 * ) & ( V_49 -> V_52 ) , sizeof( V_49 -> V_52 ) ) ;
V_51 = & ( V_29 -> V_53 [ V_43 ] ) ;
if ( ( V_51 -> V_54 ) &&
( V_51 -> V_52 == V_49 -> V_55 ) &&
( V_51 -> V_55 == V_49 -> V_52 ) &&
( ! F_24 ( V_51 -> V_56 , V_49 -> V_57 ) ) ) {
F_25 ( V_51 -> V_56 , V_49 -> V_57 ) ;
V_51 -> V_58 = 1 ;
V_29 -> V_59 = 1 ;
}
F_10 ( & V_22 -> V_27 ) ;
}
static int F_26 ( const struct V_2 * V_3 , struct V_21 * V_22 ,
struct V_18 * V_18 )
{
struct V_1 * V_49 , V_60 ;
if ( V_3 -> V_61 != F_27 ( V_62 ) )
goto V_63;
V_49 = F_28 ( V_3 , 0 , sizeof( V_60 ) , & V_60 ) ;
if ( ! V_49 )
goto V_63;
F_29 ( V_22 , V_49 ) ;
if ( V_49 -> V_64 == F_30 ( V_65 ) ) {
F_23 ( V_22 , V_49 ) ;
F_31 ( V_22 -> V_66 , L_1 ) ;
}
V_63:
return V_67 ;
}
static struct V_18 * F_32 ( struct V_21 * V_22 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
struct V_18 * V_68 = NULL , * V_69 = NULL , * V_18 ;
struct V_38 * V_39 ;
bool V_70 = false ;
F_17 (bond, slave, iter) {
if ( ! F_18 ( V_18 ) )
continue;
if ( ! V_70 ) {
if ( ! V_68 || V_68 -> V_36 < V_18 -> V_36 )
V_68 = V_18 ;
} else {
if ( ! V_69 || V_69 -> V_36 < V_18 -> V_36 )
V_69 = V_18 ;
}
if ( V_18 == V_29 -> V_69 )
V_70 = true ;
}
if ( ! V_69 || ( V_68 && V_69 -> V_36 < V_68 -> V_36 ) )
V_69 = V_68 ;
if ( V_69 )
V_29 -> V_69 = V_69 ;
return V_69 ;
}
static struct V_18 * F_33 ( struct V_21 * V_22 )
{
struct V_18 * V_69 ;
F_34 () ;
F_35 () ;
V_69 = F_32 ( V_22 ) ;
F_36 () ;
return V_69 ;
}
static void F_37 ( struct V_21 * V_22 , T_1 V_71 [] )
{
struct V_18 * V_72 = F_38 ( V_22 -> V_73 ) ;
if ( ! V_72 )
return;
if ( ! V_22 -> V_74 . V_75 ) {
if ( ! F_39 ( V_72 -> V_66 , 1 ) )
V_22 -> V_74 . V_75 = 1 ;
else
V_22 -> V_74 . V_75 = 0 ;
}
V_22 -> V_74 . V_76 = 0 ;
F_40 ( V_72 , V_71 , true ) ;
}
static void F_41 ( struct V_21 * V_22 , struct V_18 * V_18 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
struct V_50 * V_77 ;
T_2 V_24 , V_26 ;
F_9 ( & V_22 -> V_27 ) ;
V_77 = V_29 -> V_53 ;
V_24 = V_29 -> V_78 ;
for (; V_24 != V_79 ; V_24 = V_26 ) {
V_26 = V_77 [ V_24 ] . V_80 ;
if ( V_77 [ V_24 ] . V_18 == V_18 ) {
struct V_18 * V_46 = F_33 ( V_22 ) ;
if ( V_46 ) {
V_77 [ V_24 ] . V_18 = V_46 ;
if ( ! F_24 ( V_77 [ V_24 ] . V_56 ,
V_81 ) ) {
V_29 -> V_53 [ V_24 ] . V_58 = 1 ;
V_29 -> V_59 = 1 ;
V_29 -> V_82 =
V_83 ;
}
} else {
V_77 [ V_24 ] . V_18 = NULL ;
}
}
}
F_10 ( & V_22 -> V_27 ) ;
if ( V_18 != F_38 ( V_22 -> V_73 ) )
F_37 ( V_22 , V_18 -> V_66 -> V_84 ) ;
}
static void F_42 ( struct V_50 * V_51 )
{
int V_6 ;
if ( ! V_51 -> V_18 )
return;
for ( V_6 = 0 ; V_6 < V_85 ; V_6 ++ ) {
struct V_2 * V_3 ;
V_3 = F_43 ( V_65 , V_62 ,
V_51 -> V_55 ,
V_51 -> V_18 -> V_66 ,
V_51 -> V_52 ,
V_51 -> V_56 ,
V_51 -> V_18 -> V_66 -> V_84 ,
V_51 -> V_56 ) ;
if ( ! V_3 ) {
F_44 ( V_51 -> V_18 -> V_22 -> V_66 ,
L_2 ) ;
continue;
}
V_3 -> V_66 = V_51 -> V_18 -> V_66 ;
if ( V_51 -> V_86 ) {
F_45 ( V_3 , F_30 ( V_87 ) ,
V_51 -> V_86 ) ;
}
F_46 ( V_3 ) ;
}
}
static void F_47 ( struct V_21 * V_22 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
struct V_50 * V_51 ;
T_2 V_43 ;
F_9 ( & V_22 -> V_27 ) ;
V_43 = V_29 -> V_78 ;
for (; V_43 != V_79 ;
V_43 = V_51 -> V_80 ) {
V_51 = & ( V_29 -> V_53 [ V_43 ] ) ;
if ( V_51 -> V_58 ) {
F_42 ( V_51 ) ;
if ( V_29 -> V_82 == 0 )
V_51 -> V_58 = 0 ;
}
}
V_29 -> V_88 = V_89 ;
F_10 ( & V_22 -> V_27 ) ;
}
static void F_48 ( struct V_21 * V_22 , struct V_18 * V_18 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
struct V_50 * V_51 ;
int V_58 = 0 ;
T_2 V_43 ;
F_9 ( & V_22 -> V_27 ) ;
V_43 = V_29 -> V_78 ;
for (; V_43 != V_79 ;
V_43 = V_51 -> V_80 ) {
V_51 = & ( V_29 -> V_53 [ V_43 ] ) ;
if ( ( V_51 -> V_18 == V_18 ) &&
! F_24 ( V_51 -> V_56 , V_81 ) ) {
V_51 -> V_58 = 1 ;
V_58 = 1 ;
}
}
if ( V_58 ) {
V_29 -> V_59 = 1 ;
V_29 -> V_82 = V_83 ;
}
F_10 ( & V_22 -> V_27 ) ;
}
static void F_49 ( struct V_21 * V_22 , T_3 V_90 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
struct V_50 * V_51 ;
T_2 V_43 ;
F_21 ( & V_22 -> V_27 ) ;
V_43 = V_29 -> V_78 ;
for (; V_43 != V_79 ;
V_43 = V_51 -> V_80 ) {
V_51 = & ( V_29 -> V_53 [ V_43 ] ) ;
if ( ! V_51 -> V_18 ) {
F_44 ( V_22 -> V_66 , L_3 ) ;
continue;
}
if ( ( V_51 -> V_52 == V_90 ) &&
! F_24 ( V_51 -> V_18 -> V_66 -> V_84 ,
V_22 -> V_66 -> V_84 ) &&
! F_24 ( V_51 -> V_56 , V_81 ) ) {
V_51 -> V_58 = 1 ;
V_29 -> V_59 = 1 ;
}
}
F_22 ( & V_22 -> V_27 ) ;
}
static struct V_18 * F_50 ( struct V_2 * V_3 , struct V_21 * V_22 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
struct V_1 * V_49 = V_1 ( V_3 ) ;
struct V_18 * V_46 , * V_73 ;
struct V_50 * V_51 ;
T_2 V_43 = 0 ;
F_21 ( & V_22 -> V_27 ) ;
V_73 = F_51 ( V_22 -> V_73 ) ;
V_43 = F_2 ( ( T_1 * ) & V_49 -> V_55 , sizeof( V_49 -> V_55 ) ) ;
V_51 = & ( V_29 -> V_53 [ V_43 ] ) ;
if ( V_51 -> V_54 ) {
if ( ( V_51 -> V_52 == V_49 -> V_52 ) &&
( V_51 -> V_55 == V_49 -> V_55 ) ) {
if ( ! F_24 ( V_49 -> V_56 , V_81 ) ) {
F_25 ( V_51 -> V_56 , V_49 -> V_56 ) ;
}
F_25 ( V_51 -> V_57 , V_49 -> V_57 ) ;
V_46 = V_51 -> V_18 ;
if ( V_46 ) {
F_22 ( & V_22 -> V_27 ) ;
return V_46 ;
}
} else {
if ( V_73 &&
V_51 -> V_18 != V_73 ) {
V_51 -> V_18 = V_73 ;
F_42 ( V_51 ) ;
}
}
}
V_46 = F_32 ( V_22 ) ;
if ( V_46 ) {
if ( ! ( V_51 -> V_54 &&
V_51 -> V_52 == V_49 -> V_52 ) ) {
T_2 V_91 = F_2 ( ( T_1 * ) & V_49 -> V_52 ,
sizeof( V_49 -> V_52 ) ) ;
F_52 ( V_22 , V_43 ) ;
F_53 ( V_22 , V_91 , V_43 ) ;
}
V_51 -> V_52 = V_49 -> V_52 ;
V_51 -> V_55 = V_49 -> V_55 ;
F_25 ( V_51 -> V_56 , V_49 -> V_56 ) ;
F_25 ( V_51 -> V_57 , V_49 -> V_57 ) ;
V_51 -> V_18 = V_46 ;
if ( ! F_24 ( V_51 -> V_56 , V_81 ) ) {
V_51 -> V_58 = 1 ;
V_22 -> V_74 . V_59 = 1 ;
} else {
V_51 -> V_58 = 0 ;
}
if ( F_54 ( V_3 , & V_51 -> V_86 ) )
V_51 -> V_86 = 0 ;
if ( ! V_51 -> V_54 ) {
T_2 V_92 = V_29 -> V_78 ;
V_29 -> V_78 = V_43 ;
V_51 -> V_80 = V_92 ;
if ( V_92 != V_79 ) {
V_29 -> V_53 [ V_92 ] . V_93 =
V_43 ;
}
V_51 -> V_54 = 1 ;
}
}
F_22 ( & V_22 -> V_27 ) ;
return V_46 ;
}
static struct V_18 * F_55 ( struct V_2 * V_3 , struct V_21 * V_22 )
{
struct V_1 * V_49 = V_1 ( V_3 ) ;
struct V_18 * V_14 = NULL ;
if ( ! F_56 ( V_22 , V_49 -> V_57 ) )
return NULL ;
if ( V_49 -> V_64 == F_30 ( V_65 ) ) {
V_14 = F_50 ( V_3 , V_22 ) ;
if ( V_14 )
F_25 ( V_49 -> V_57 , V_14 -> V_66 -> V_84 ) ;
F_31 ( V_22 -> V_66 , L_4 ) ;
} else if ( V_49 -> V_64 == F_30 ( V_94 ) ) {
F_50 ( V_3 , V_22 ) ;
V_22 -> V_74 . V_88 = V_89 ;
F_49 ( V_22 , V_49 -> V_52 ) ;
F_31 ( V_22 -> V_66 , L_5 ) ;
}
return V_14 ;
}
static void F_57 ( struct V_21 * V_22 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
struct V_18 * V_46 ;
struct V_50 * V_51 ;
int V_58 ;
T_2 V_43 ;
F_9 ( & V_22 -> V_27 ) ;
V_58 = 0 ;
V_43 = V_29 -> V_78 ;
for (; V_43 != V_79 ;
V_43 = V_51 -> V_80 ) {
V_51 = & ( V_29 -> V_53 [ V_43 ] ) ;
V_46 = F_32 ( V_22 ) ;
if ( V_46 && ( V_51 -> V_18 != V_46 ) ) {
V_51 -> V_18 = V_46 ;
V_51 -> V_58 = 1 ;
V_58 = 1 ;
}
}
if ( V_58 )
V_29 -> V_59 = 1 ;
F_10 ( & V_22 -> V_27 ) ;
}
static void F_58 ( struct V_50 * V_9 )
{
V_9 -> V_80 = V_79 ;
V_9 -> V_93 = V_79 ;
V_9 -> V_54 = 0 ;
V_9 -> V_18 = NULL ;
V_9 -> V_86 = 0 ;
}
static void F_59 ( struct V_50 * V_9 )
{
V_9 -> V_95 = V_79 ;
V_9 -> V_96 = V_79 ;
V_9 -> V_97 = V_79 ;
}
static void F_60 ( struct V_50 * V_9 )
{
memset ( V_9 , 0 , sizeof( struct V_50 ) ) ;
F_58 ( V_9 ) ;
F_59 ( V_9 ) ;
}
static void F_61 ( struct V_21 * V_22 , T_2 V_24 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
T_2 V_26 = V_29 -> V_53 [ V_24 ] . V_80 ;
T_2 V_98 = V_29 -> V_53 [ V_24 ] . V_93 ;
if ( V_24 == V_29 -> V_78 )
V_29 -> V_78 = V_26 ;
if ( V_98 != V_79 )
V_29 -> V_53 [ V_98 ] . V_80 = V_26 ;
if ( V_26 != V_79 )
V_29 -> V_53 [ V_26 ] . V_93 = V_98 ;
}
static void F_52 ( struct V_21 * V_22 , T_2 V_24 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
T_2 V_26 = V_29 -> V_53 [ V_24 ] . V_97 ;
T_2 V_98 = V_29 -> V_53 [ V_24 ] . V_96 ;
V_29 -> V_53 [ V_24 ] . V_97 = V_79 ;
V_29 -> V_53 [ V_24 ] . V_96 = V_79 ;
if ( V_26 != V_79 )
V_29 -> V_53 [ V_26 ] . V_96 = V_98 ;
if ( V_98 == V_79 )
return;
if ( V_29 -> V_53 [ V_98 ] . V_95 == V_24 )
V_29 -> V_53 [ V_98 ] . V_95 = V_26 ;
else
V_29 -> V_53 [ V_98 ] . V_97 = V_26 ;
}
static void F_62 ( struct V_21 * V_22 , T_2 V_24 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
struct V_50 * V_9 = & ( V_29 -> V_53 [ V_24 ] ) ;
F_61 ( V_22 , V_24 ) ;
F_58 ( V_9 ) ;
F_52 ( V_22 , V_24 ) ;
}
static void F_53 ( struct V_21 * V_22 , T_2 V_99 , T_2 V_100 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
T_2 V_15 ;
V_29 -> V_53 [ V_100 ] . V_96 = V_99 ;
V_15 = V_29 -> V_53 [ V_99 ] . V_95 ;
V_29 -> V_53 [ V_100 ] . V_97 = V_15 ;
if ( V_15 != V_79 )
V_29 -> V_53 [ V_15 ] . V_96 = V_100 ;
V_29 -> V_53 [ V_99 ] . V_95 = V_100 ;
}
static void F_29 ( struct V_21 * V_22 , struct V_1 * V_49 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
T_2 V_99 = F_2 ( ( T_1 * ) & ( V_49 -> V_52 ) , sizeof( V_49 -> V_52 ) ) ;
T_2 V_24 ;
F_9 ( & V_22 -> V_27 ) ;
V_24 = V_29 -> V_53 [ V_99 ] . V_95 ;
while ( V_24 != V_79 ) {
struct V_50 * V_9 = & ( V_29 -> V_53 [ V_24 ] ) ;
T_2 V_26 = V_9 -> V_97 ;
if ( V_9 -> V_52 == V_49 -> V_52 &&
! F_24 ( V_49 -> V_57 , V_9 -> V_57 ) )
F_62 ( V_22 , V_24 ) ;
V_24 = V_26 ;
}
F_10 ( & V_22 -> V_27 ) ;
}
static int F_63 ( struct V_21 * V_22 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
struct V_50 * V_32 ;
int V_30 = V_101 * sizeof( struct V_50 ) ;
int V_6 ;
V_32 = F_64 ( V_30 , V_33 ) ;
if ( ! V_32 )
return - 1 ;
F_9 ( & V_22 -> V_27 ) ;
V_29 -> V_53 = V_32 ;
V_29 -> V_78 = V_79 ;
for ( V_6 = 0 ; V_6 < V_101 ; V_6 ++ )
F_60 ( V_29 -> V_53 + V_6 ) ;
F_10 ( & V_22 -> V_27 ) ;
V_22 -> V_102 = F_26 ;
return 0 ;
}
static void F_65 ( struct V_21 * V_22 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
F_9 ( & V_22 -> V_27 ) ;
F_14 ( V_29 -> V_53 ) ;
V_29 -> V_53 = NULL ;
V_29 -> V_78 = V_79 ;
F_10 ( & V_22 -> V_27 ) ;
}
static void F_66 ( struct V_21 * V_22 , unsigned short V_86 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
T_2 V_103 ;
F_9 ( & V_22 -> V_27 ) ;
V_103 = V_29 -> V_78 ;
while ( V_103 != V_79 ) {
struct V_50 * V_104 = & ( V_29 -> V_53 [ V_103 ] ) ;
T_2 V_26 = V_29 -> V_53 [ V_103 ] . V_80 ;
if ( V_104 -> V_86 == V_86 )
F_62 ( V_22 , V_103 ) ;
V_103 = V_26 ;
}
F_10 ( & V_22 -> V_27 ) ;
}
static void F_67 ( struct V_18 * V_18 , T_1 V_105 [] ,
T_4 V_106 , T_5 V_107 )
{
struct V_108 V_109 ;
struct V_2 * V_3 ;
int V_30 = sizeof( struct V_108 ) ;
char * V_110 ;
memset ( & V_109 , 0 , V_30 ) ;
F_25 ( V_109 . V_56 , V_105 ) ;
F_25 ( V_109 . V_57 , V_105 ) ;
V_109 . type = F_27 ( V_111 ) ;
V_3 = F_68 ( V_30 ) ;
if ( ! V_3 )
return;
V_110 = F_69 ( V_3 , V_30 ) ;
memcpy ( V_110 , & V_109 , V_30 ) ;
F_70 ( V_3 ) ;
V_3 -> V_112 = V_3 -> V_113 + V_114 ;
V_3 -> V_61 = V_109 . type ;
V_3 -> V_115 = V_116 ;
V_3 -> V_66 = V_18 -> V_66 ;
if ( V_107 )
F_45 ( V_3 , V_106 , V_107 ) ;
F_71 ( V_3 ) ;
}
static int F_72 ( struct V_117 * V_118 , void * V_119 )
{
struct V_120 * V_110 = V_119 ;
bool V_121 = V_110 -> V_121 ;
struct V_21 * V_22 = V_110 -> V_22 ;
struct V_18 * V_18 = V_110 -> V_18 ;
T_1 * V_105 = V_110 -> V_105 ;
struct V_122 * V_123 ;
if ( F_73 ( V_118 ) && F_74 ( V_118 ) == 0 ) {
if ( V_121 &&
F_24 ( V_105 ,
V_118 -> V_84 ) ) {
F_67 ( V_18 , V_105 ,
F_75 ( V_118 ) ,
F_76 ( V_118 ) ) ;
} else if ( ! V_121 ) {
F_67 ( V_18 , V_118 -> V_84 ,
F_75 ( V_118 ) ,
F_76 ( V_118 ) ) ;
}
}
if ( F_77 ( V_118 ) && ! V_121 ) {
V_123 = F_78 ( V_22 -> V_66 , V_118 , 0 ) ;
if ( F_79 ( V_123 ) )
F_80 () ;
F_67 ( V_18 , V_118 -> V_84 ,
V_123 [ 0 ] . V_106 , V_123 [ 0 ] . V_86 ) ;
F_14 ( V_123 ) ;
}
return 0 ;
}
static void F_40 ( struct V_18 * V_18 , T_1 V_105 [] ,
bool V_121 )
{
struct V_21 * V_22 = F_81 ( V_18 ) ;
struct V_120 V_110 = {
. V_121 = V_121 ,
. V_105 = V_105 ,
. V_18 = V_18 ,
. V_22 = V_22 ,
} ;
F_67 ( V_18 , V_105 , 0 , 0 ) ;
F_35 () ;
F_82 ( V_22 -> V_66 , F_72 , & V_110 ) ;
F_36 () ;
}
static int F_83 ( struct V_18 * V_18 , T_1 V_71 [] )
{
struct V_117 * V_66 = V_18 -> V_66 ;
struct V_124 V_125 ;
if ( F_84 ( V_18 -> V_22 ) == V_126 ) {
memcpy ( V_66 -> V_84 , V_71 , V_66 -> V_127 ) ;
return 0 ;
}
memcpy ( V_125 . V_128 , V_71 , V_66 -> V_127 ) ;
V_125 . V_129 = V_66 -> type ;
if ( F_85 ( V_66 , & V_125 ) ) {
F_44 ( V_18 -> V_22 -> V_66 , L_6 ,
V_66 -> V_130 ) ;
return - V_131 ;
}
return 0 ;
}
static void F_86 ( struct V_18 * V_132 , struct V_18 * V_133 )
{
T_1 V_134 [ V_135 ] ;
F_25 ( V_134 , V_132 -> V_66 -> V_84 ) ;
F_83 ( V_132 , V_133 -> V_66 -> V_84 ) ;
F_83 ( V_133 , V_134 ) ;
}
static void F_87 ( struct V_21 * V_22 , struct V_18 * V_132 ,
struct V_18 * V_133 )
{
int V_136 = ( F_18 ( V_132 ) != F_18 ( V_133 ) ) ;
struct V_18 * V_137 = NULL ;
F_34 () ;
if ( F_18 ( V_132 ) ) {
F_40 ( V_132 , V_132 -> V_66 -> V_84 , false ) ;
if ( V_22 -> V_74 . V_138 ) {
F_48 ( V_22 , V_132 ) ;
}
} else {
V_137 = V_132 ;
}
if ( F_18 ( V_133 ) ) {
F_40 ( V_133 , V_133 -> V_66 -> V_84 , false ) ;
if ( V_22 -> V_74 . V_138 ) {
F_48 ( V_22 , V_133 ) ;
}
} else {
V_137 = V_133 ;
}
if ( V_22 -> V_74 . V_138 && V_136 ) {
F_37 ( V_22 ,
V_137 -> V_66 -> V_84 ) ;
}
}
static void F_88 ( struct V_21 * V_22 , struct V_18 * V_18 )
{
int V_139 ;
int V_140 ;
struct V_18 * V_141 ;
V_139 = ! F_24 ( V_18 -> V_142 ,
V_18 -> V_66 -> V_84 ) ;
V_140 = ! F_24 ( V_18 -> V_142 ,
V_22 -> V_66 -> V_84 ) ;
if ( V_139 && V_140 ) {
V_141 = F_89 ( V_22 , V_18 -> V_142 ) ;
if ( V_141 ) {
F_86 ( V_18 , V_141 ) ;
F_87 ( V_22 , V_18 , V_141 ) ;
}
}
}
static int F_90 ( struct V_21 * V_22 , struct V_18 * V_18 )
{
struct V_18 * V_143 = F_91 ( V_22 -> V_73 ) ;
struct V_18 * V_144 , * V_145 = NULL ;
struct V_38 * V_39 ;
if ( ! F_92 ( V_22 ) ) {
return 0 ;
}
if ( ! F_24 ( V_18 -> V_142 , V_22 -> V_66 -> V_84 ) ) {
if ( ! F_89 ( V_22 , V_18 -> V_66 -> V_84 ) )
return 0 ;
F_83 ( V_18 , V_22 -> V_66 -> V_84 ) ;
}
F_93 (bond, tmp_slave1, iter) {
if ( ! F_89 ( V_22 , V_144 -> V_142 ) ) {
V_145 = V_144 ;
break;
}
if ( ! V_143 ) {
if ( F_24 ( V_144 -> V_66 -> V_84 ,
V_22 -> V_66 -> V_84 ) ) {
V_143 = V_144 ;
}
}
}
if ( V_145 ) {
F_83 ( V_18 , V_145 -> V_142 ) ;
F_94 ( V_22 -> V_66 , L_7 ,
V_18 -> V_66 -> V_130 , V_145 -> V_66 -> V_130 ) ;
} else if ( V_143 ) {
F_44 ( V_22 -> V_66 , L_8 ,
V_18 -> V_66 -> V_130 ) ;
return - V_146 ;
}
return 0 ;
}
static int F_95 ( struct V_21 * V_22 , void * V_71 )
{
struct V_18 * V_18 , * V_147 ;
struct V_38 * V_39 ;
struct V_124 V_148 ;
char V_149 [ V_135 ] ;
int V_150 ;
if ( V_22 -> V_74 . V_138 )
return 0 ;
F_93 (bond, slave, iter) {
F_25 ( V_149 , V_18 -> V_66 -> V_84 ) ;
V_150 = F_85 ( V_18 -> V_66 , V_71 ) ;
F_25 ( V_18 -> V_66 -> V_84 , V_149 ) ;
if ( V_150 )
goto V_151;
}
return 0 ;
V_151:
memcpy ( V_148 . V_128 , V_22 -> V_66 -> V_84 , V_22 -> V_66 -> V_127 ) ;
V_148 . V_129 = V_22 -> V_66 -> type ;
F_93 (bond, rollback_slave, iter) {
if ( V_147 == V_18 )
break;
F_25 ( V_149 , V_147 -> V_66 -> V_84 ) ;
F_85 ( V_147 -> V_66 , & V_148 ) ;
F_25 ( V_147 -> V_66 -> V_84 , V_149 ) ;
}
return V_150 ;
}
int F_96 ( struct V_21 * V_22 , int V_138 )
{
int V_150 ;
V_150 = F_11 ( V_22 ) ;
if ( V_150 )
return V_150 ;
if ( V_138 ) {
V_22 -> V_74 . V_138 = 1 ;
V_150 = F_63 ( V_22 ) ;
if ( V_150 ) {
F_13 ( V_22 ) ;
return V_150 ;
}
} else {
V_22 -> V_74 . V_138 = 0 ;
}
return 0 ;
}
void F_97 ( struct V_21 * V_22 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
F_13 ( V_22 ) ;
if ( V_29 -> V_138 )
F_65 ( V_22 ) ;
}
static int F_98 ( struct V_2 * V_3 , struct V_21 * V_22 ,
struct V_18 * V_14 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
struct V_152 * V_153 = F_99 ( V_3 ) ;
if ( ! V_14 ) {
V_14 = F_51 ( V_22 -> V_73 ) ;
if ( V_22 -> V_154 . V_155 )
V_29 -> V_156 += V_3 -> V_157 ;
}
if ( V_14 && F_18 ( V_14 ) ) {
if ( V_14 != F_91 ( V_22 -> V_73 ) ) {
F_25 ( V_153 -> V_158 ,
V_14 -> V_66 -> V_84 ) ;
}
F_100 ( V_22 , V_3 , V_14 -> V_66 ) ;
goto V_63;
}
if ( V_14 && V_22 -> V_154 . V_155 ) {
F_21 ( & V_22 -> V_27 ) ;
F_6 ( V_22 , V_14 , 0 ) ;
F_22 ( & V_22 -> V_27 ) ;
}
F_101 ( V_22 -> V_66 , V_3 ) ;
V_63:
return V_159 ;
}
int F_102 ( struct V_2 * V_3 , struct V_117 * V_160 )
{
struct V_21 * V_22 = F_103 ( V_160 ) ;
struct V_152 * V_153 ;
struct V_18 * V_14 = NULL ;
T_2 V_43 ;
F_70 ( V_3 ) ;
V_153 = F_99 ( V_3 ) ;
if ( ! F_104 ( V_153 -> V_161 ) ) {
switch ( V_3 -> V_61 ) {
case F_30 ( V_162 ) :
case F_30 ( V_163 ) :
case F_30 ( V_164 ) :
V_43 = F_105 ( V_22 , V_3 ) ;
if ( V_22 -> V_154 . V_155 ) {
V_14 = F_20 ( V_22 ,
V_43 & 0xFF ,
V_3 -> V_157 ) ;
} else {
struct V_165 * V_166 ;
unsigned int V_167 ;
V_166 = F_51 ( V_22 -> V_168 ) ;
V_167 = V_166 ? F_106 ( V_166 -> V_167 ) : 0 ;
if ( F_107 ( V_167 ) )
V_14 = V_166 -> V_169 [ V_43 %
V_167 ] ;
}
break;
}
}
return F_98 ( V_3 , V_22 , V_14 ) ;
}
int F_108 ( struct V_2 * V_3 , struct V_117 * V_160 )
{
struct V_21 * V_22 = F_103 ( V_160 ) ;
struct V_152 * V_153 ;
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
struct V_18 * V_14 = NULL ;
static const T_3 V_170 = F_109 ( 0xffffffff ) ;
int V_5 = 0 ;
bool V_171 = true ;
T_2 V_43 = 0 ;
const T_1 * V_4 = NULL ;
struct V_172 * V_173 ;
F_70 ( V_3 ) ;
V_153 = F_99 ( V_3 ) ;
switch ( F_110 ( V_3 -> V_61 ) ) {
case V_162 : {
const struct V_174 * V_175 = F_111 ( V_3 ) ;
if ( F_24 ( V_153 -> V_161 , V_81 ) ||
( V_175 -> V_176 == V_170 ) ||
( V_175 -> V_61 == V_177 ) ) {
V_171 = false ;
break;
}
V_4 = ( char * ) & ( V_175 -> V_176 ) ;
V_5 = sizeof( V_175 -> V_176 ) ;
}
break;
case V_164 :
if ( F_24 ( V_153 -> V_161 , V_81 ) ) {
V_171 = false ;
break;
}
if ( F_24 ( V_153 -> V_161 , V_178 ) ) {
V_171 = false ;
break;
}
V_173 = F_112 ( V_3 ) ;
if ( F_113 ( & V_173 -> V_179 ) ) {
V_171 = false ;
break;
}
V_4 = ( char * ) & ( F_112 ( V_3 ) -> V_176 ) ;
V_5 = sizeof( F_112 ( V_3 ) -> V_176 ) ;
break;
case V_163 :
if ( F_114 ( V_3 ) -> V_180 != V_181 ) {
V_171 = false ;
break;
}
if ( F_114 ( V_3 ) -> V_182 != V_183 ) {
V_171 = false ;
break;
}
V_4 = ( char * ) V_153 -> V_161 ;
V_5 = V_135 ;
break;
case V_62 :
V_171 = false ;
if ( V_29 -> V_138 )
V_14 = F_55 ( V_3 , V_22 ) ;
break;
default:
V_171 = false ;
break;
}
if ( V_171 ) {
V_43 = F_2 ( V_4 , V_5 ) ;
V_14 = F_20 ( V_22 , V_43 , V_3 -> V_157 ) ;
}
return F_98 ( V_3 , V_22 , V_14 ) ;
}
void F_115 ( struct V_184 * V_185 )
{
struct V_21 * V_22 = F_116 ( V_185 , struct V_21 ,
V_186 . V_185 ) ;
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
struct V_38 * V_39 ;
struct V_18 * V_18 ;
if ( ! F_92 ( V_22 ) ) {
V_29 -> V_187 = 0 ;
V_29 -> V_188 = 0 ;
goto V_189;
}
F_35 () ;
V_29 -> V_187 ++ ;
V_29 -> V_188 ++ ;
if ( V_29 -> V_188 >= F_117 ( V_22 ) ) {
bool V_121 ;
F_17 (bond, slave, iter) {
V_121 = ( V_18 != F_91 ( V_22 -> V_73 ) ||
V_29 -> V_138 ) ;
F_40 ( V_18 , V_18 -> V_66 -> V_84 ,
V_121 ) ;
}
V_29 -> V_188 = 0 ;
}
if ( V_29 -> V_187 >= V_190 ) {
F_17 (bond, slave, iter) {
F_8 ( V_22 , V_18 , 1 ) ;
if ( V_18 == F_91 ( V_22 -> V_73 ) ) {
F_5 ( V_18 ) . V_19 =
V_29 -> V_156 /
V_13 ;
V_29 -> V_156 = 0 ;
}
}
V_29 -> V_187 = 0 ;
}
if ( V_29 -> V_138 ) {
if ( V_29 -> V_75 &&
( ++ V_29 -> V_76 >= V_191 ) ) {
F_36 () ;
if ( ! F_118 () )
goto V_189;
V_29 -> V_76 = 0 ;
F_39 ( F_38 ( V_22 -> V_73 ) -> V_66 ,
- 1 ) ;
V_29 -> V_75 = 0 ;
F_119 () ;
F_35 () ;
}
if ( V_29 -> F_57 ) {
V_29 -> F_57 = 0 ;
F_57 ( V_22 ) ;
}
if ( V_29 -> V_59 ) {
if ( V_29 -> V_88 ) {
-- V_29 -> V_88 ;
} else {
F_47 ( V_22 ) ;
if ( V_29 -> V_82 )
-- V_29 -> V_82 ;
else
V_29 -> V_59 = 0 ;
}
}
}
F_36 () ;
V_189:
F_120 ( V_22 -> V_192 , & V_22 -> V_186 , V_193 ) ;
}
int F_121 ( struct V_21 * V_22 , struct V_18 * V_18 )
{
int V_150 ;
V_150 = F_83 ( V_18 , V_18 -> V_142 ) ;
if ( V_150 )
return V_150 ;
V_150 = F_90 ( V_22 , V_18 ) ;
if ( V_150 )
return V_150 ;
F_4 ( V_18 ) ;
V_22 -> V_74 . V_187 = V_190 ;
if ( V_22 -> V_74 . V_138 )
V_22 -> V_74 . F_57 = 1 ;
return 0 ;
}
void F_122 ( struct V_21 * V_22 , struct V_18 * V_18 )
{
if ( F_92 ( V_22 ) )
F_88 ( V_22 , V_18 ) ;
F_8 ( V_22 , V_18 , 0 ) ;
if ( V_22 -> V_74 . V_138 ) {
V_22 -> V_74 . V_69 = NULL ;
F_41 ( V_22 , V_18 ) ;
}
}
void F_123 ( struct V_21 * V_22 , struct V_18 * V_18 , char V_194 )
{
struct V_28 * V_29 = & ( F_7 ( V_22 ) ) ;
if ( V_194 == V_195 ) {
F_8 ( V_22 , V_18 , 0 ) ;
if ( V_22 -> V_74 . V_138 )
F_41 ( V_22 , V_18 ) ;
} else if ( V_194 == V_196 ) {
V_29 -> V_187 = V_190 ;
if ( V_22 -> V_74 . V_138 ) {
V_22 -> V_74 . F_57 = 1 ;
}
}
if ( F_124 ( V_22 ) ) {
if ( F_125 ( V_22 , NULL ) )
F_126 ( L_9 ) ;
}
}
void F_127 ( struct V_21 * V_22 , struct V_18 * V_197 )
{
struct V_18 * V_198 ;
struct V_18 * V_72 ;
V_72 = F_38 ( V_22 -> V_73 ) ;
if ( V_72 == V_197 )
return;
if ( V_72 && V_22 -> V_74 . V_75 ) {
F_39 ( V_72 -> V_66 , - 1 ) ;
V_22 -> V_74 . V_75 = 0 ;
V_22 -> V_74 . V_76 = 0 ;
}
V_198 = V_72 ;
F_128 ( V_22 -> V_73 , V_197 ) ;
if ( ! V_197 || ! F_92 ( V_22 ) )
return;
if ( ! V_198 )
V_198 = F_89 ( V_22 , V_22 -> V_66 -> V_84 ) ;
if ( V_198 )
F_8 ( V_22 , V_198 , 1 ) ;
F_8 ( V_22 , V_197 , 1 ) ;
if ( F_84 ( V_22 ) == V_126 ) {
struct V_124 V_148 ;
T_1 V_149 [ V_135 ] ;
F_25 ( V_149 , V_197 -> V_66 -> V_84 ) ;
memcpy ( V_148 . V_128 , V_22 -> V_66 -> V_84 , V_22 -> V_66 -> V_127 ) ;
V_148 . V_129 = V_22 -> V_66 -> type ;
F_85 ( V_197 -> V_66 , & V_148 ) ;
F_25 ( V_197 -> V_66 -> V_84 , V_149 ) ;
}
if ( V_198 ) {
F_86 ( V_198 , V_197 ) ;
F_87 ( V_22 , V_198 , V_197 ) ;
} else {
F_83 ( V_197 , V_22 -> V_66 -> V_84 ) ;
F_40 ( V_197 , V_22 -> V_66 -> V_84 ,
false ) ;
}
}
int F_129 ( struct V_117 * V_160 , void * V_71 )
{
struct V_21 * V_22 = F_103 ( V_160 ) ;
struct V_124 * V_148 = V_71 ;
struct V_18 * V_72 ;
struct V_18 * V_198 ;
int V_150 ;
if ( ! F_130 ( V_148 -> V_128 ) )
return - V_199 ;
V_150 = F_95 ( V_22 , V_71 ) ;
if ( V_150 )
return V_150 ;
memcpy ( V_160 -> V_84 , V_148 -> V_128 , V_160 -> V_127 ) ;
V_72 = F_38 ( V_22 -> V_73 ) ;
if ( ! V_72 )
return 0 ;
V_198 = F_89 ( V_22 , V_160 -> V_84 ) ;
if ( V_198 ) {
F_86 ( V_198 , V_72 ) ;
F_87 ( V_22 , V_198 , V_72 ) ;
} else {
F_83 ( V_72 , V_160 -> V_84 ) ;
F_40 ( V_72 ,
V_160 -> V_84 , false ) ;
if ( V_22 -> V_74 . V_138 ) {
F_48 ( V_22 , V_72 ) ;
}
}
return 0 ;
}
void F_131 ( struct V_21 * V_22 , unsigned short V_86 )
{
if ( V_22 -> V_74 . V_138 )
F_66 ( V_22 , V_86 ) ;
}
