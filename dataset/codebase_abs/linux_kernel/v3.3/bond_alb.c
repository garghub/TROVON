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
if ( ! V_32 ) {
F_19 ( L_1 ,
V_9 -> V_34 -> V_35 ) ;
return - 1 ;
}
F_3 ( V_9 ) ;
V_29 -> V_26 = V_32 ;
for ( V_6 = 0 ; V_6 < V_31 ; V_6 ++ ) {
F_12 ( & V_29 -> V_26 [ V_6 ] , 0 ) ;
}
F_6 ( V_9 ) ;
return 0 ;
}
static void F_20 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
F_3 ( V_9 ) ;
F_21 ( V_29 -> V_26 ) ;
V_29 -> V_26 = NULL ;
F_6 ( V_9 ) ;
}
static long long F_22 ( struct V_21 * V_21 )
{
return ( V_36 ) ( V_21 -> V_37 << 20 ) -
( V_36 ) ( F_14 ( V_21 ) . V_22 << 3 ) ;
}
static struct V_21 * F_23 ( struct V_8 * V_9 )
{
struct V_21 * V_21 , * V_38 ;
long long V_39 ;
int V_6 ;
V_38 = NULL ;
V_39 = V_40 ;
F_24 (bond, slave, i) {
if ( F_25 ( V_21 ) ) {
long long V_41 = F_22 ( V_21 ) ;
if ( V_39 < V_41 ) {
V_38 = V_21 ;
V_39 = V_41 ;
}
}
}
return V_38 ;
}
static struct V_21 * F_26 ( struct V_8 * V_9 , T_2 V_42 ,
T_2 V_43 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_11 * V_44 ;
struct V_21 * V_45 ;
V_44 = V_29 -> V_26 ;
V_45 = V_44 [ V_42 ] . V_17 ;
if ( ! V_45 ) {
V_45 = F_23 ( V_9 ) ;
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
static struct V_21 * F_27 ( struct V_8 * V_9 , T_2 V_42 ,
T_2 V_43 )
{
struct V_21 * V_17 ;
F_8 ( V_9 ) ;
V_17 = F_26 ( V_9 , V_42 , V_43 ) ;
F_10 ( V_9 ) ;
return V_17 ;
}
static inline void F_28 ( struct V_8 * V_9 )
{
F_4 ( & ( F_5 ( V_9 ) . V_48 ) ) ;
}
static inline void F_29 ( struct V_8 * V_9 )
{
F_7 ( & ( F_5 ( V_9 ) . V_48 ) ) ;
}
static inline void F_30 ( struct V_8 * V_9 )
{
F_9 ( & ( F_5 ( V_9 ) . V_48 ) ) ;
}
static inline void F_31 ( struct V_8 * V_9 )
{
F_11 ( & ( F_5 ( V_9 ) . V_48 ) ) ;
}
static void F_32 ( struct V_8 * V_9 , struct V_1 * V_49 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_50 * V_51 ;
T_2 V_42 ;
F_28 ( V_9 ) ;
V_42 = F_2 ( ( T_1 * ) & ( V_49 -> V_52 ) , sizeof( V_49 -> V_52 ) ) ;
V_51 = & ( V_29 -> V_53 [ V_42 ] ) ;
if ( ( V_51 -> V_54 ) &&
( V_51 -> V_52 == V_49 -> V_55 ) &&
( V_51 -> V_55 == V_49 -> V_52 ) &&
( F_33 ( V_51 -> V_56 , V_49 -> V_57 ) ) ) {
memcpy ( V_51 -> V_56 , V_49 -> V_57 , V_58 ) ;
V_51 -> V_59 = 1 ;
V_29 -> V_60 = 1 ;
}
F_29 ( V_9 ) ;
}
static void F_34 ( struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_21 * V_21 )
{
struct V_1 * V_49 ;
if ( V_3 -> V_61 != F_35 ( V_62 ) )
return;
V_49 = (struct V_1 * ) V_3 -> V_63 ;
if ( ! V_49 ) {
F_36 ( L_2 ) ;
return;
}
if ( ! F_37 ( V_3 , F_38 ( V_9 -> V_34 ) ) )
return;
if ( V_3 -> V_64 < sizeof( struct V_1 ) ) {
F_36 ( L_3 ) ;
return;
}
if ( V_49 -> V_65 == F_39 ( V_66 ) ) {
F_32 ( V_9 , V_49 ) ;
F_36 ( L_4 ) ;
}
}
static struct V_21 * F_40 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_21 * V_67 , * V_21 , * V_68 ;
int V_6 = 0 ;
if ( V_29 -> V_69 ) {
V_68 = V_29 -> V_69 ;
} else {
V_68 = V_9 -> V_70 ;
}
V_67 = NULL ;
F_41 (bond, slave, i, start_at) {
if ( F_25 ( V_21 ) ) {
if ( ! V_67 ) {
V_67 = V_21 ;
} else if ( V_21 -> V_37 > V_67 -> V_37 ) {
V_67 = V_21 ;
}
}
}
if ( V_67 ) {
V_29 -> V_69 = V_67 -> V_18 ;
}
return V_67 ;
}
static void F_42 ( struct V_8 * V_9 , T_1 V_71 [] )
{
if ( ! V_9 -> V_72 ) {
return;
}
if ( ! V_9 -> V_73 . V_74 ) {
if ( ! F_43 ( V_9 -> V_72 -> V_34 , 1 ) )
V_9 -> V_73 . V_74 = 1 ;
else
V_9 -> V_73 . V_74 = 0 ;
}
V_9 -> V_73 . V_75 = 0 ;
F_44 ( V_9 -> V_72 , V_71 ) ;
}
static void F_45 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_50 * V_76 ;
T_2 V_25 , V_27 ;
F_28 ( V_9 ) ;
V_76 = V_29 -> V_53 ;
V_25 = V_29 -> V_77 ;
for (; V_25 != V_78 ; V_25 = V_27 ) {
V_27 = V_76 [ V_25 ] . V_18 ;
if ( V_76 [ V_25 ] . V_21 == V_21 ) {
struct V_21 * V_45 = F_40 ( V_9 ) ;
if ( V_45 ) {
V_76 [ V_25 ] . V_21 = V_45 ;
if ( F_33 ( V_76 [ V_25 ] . V_56 ,
V_79 ) ) {
V_29 -> V_53 [ V_25 ] . V_59 = 1 ;
V_29 -> V_60 = 1 ;
V_29 -> V_80 =
V_81 ;
}
} else {
V_76 [ V_25 ] . V_21 = NULL ;
}
}
}
F_29 ( V_9 ) ;
F_46 ( & V_9 -> V_82 ) ;
if ( V_21 != V_9 -> V_72 ) {
F_42 ( V_9 , V_21 -> V_34 -> V_83 ) ;
}
F_47 ( & V_9 -> V_82 ) ;
}
static void F_48 ( struct V_50 * V_51 )
{
int V_6 ;
if ( ! V_51 -> V_21 ) {
return;
}
for ( V_6 = 0 ; V_6 < V_84 ; V_6 ++ ) {
struct V_2 * V_3 ;
V_3 = F_49 ( V_66 , V_62 ,
V_51 -> V_55 ,
V_51 -> V_21 -> V_34 ,
V_51 -> V_52 ,
V_51 -> V_56 ,
V_51 -> V_21 -> V_34 -> V_83 ,
V_51 -> V_56 ) ;
if ( ! V_3 ) {
F_19 ( L_5 ,
V_51 -> V_21 -> V_34 -> V_85 -> V_35 ) ;
continue;
}
V_3 -> V_34 = V_51 -> V_21 -> V_34 ;
if ( V_51 -> V_86 ) {
V_3 = F_50 ( V_3 , V_51 -> V_87 ) ;
if ( ! V_3 ) {
F_19 ( L_6 ,
V_51 -> V_21 -> V_34 -> V_85 -> V_35 ) ;
continue;
}
}
F_51 ( V_3 ) ;
}
}
static void F_52 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_50 * V_51 ;
T_2 V_42 ;
F_28 ( V_9 ) ;
V_42 = V_29 -> V_77 ;
for (; V_42 != V_78 ; V_42 = V_51 -> V_18 ) {
V_51 = & ( V_29 -> V_53 [ V_42 ] ) ;
if ( V_51 -> V_59 ) {
F_48 ( V_51 ) ;
if ( V_29 -> V_80 == 0 ) {
V_51 -> V_59 = 0 ;
}
}
}
V_29 -> V_88 = V_89 ;
F_29 ( V_9 ) ;
}
static void F_53 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_50 * V_51 ;
int V_59 = 0 ;
T_2 V_42 ;
F_28 ( V_9 ) ;
V_42 = V_29 -> V_77 ;
for (; V_42 != V_78 ; V_42 = V_51 -> V_18 ) {
V_51 = & ( V_29 -> V_53 [ V_42 ] ) ;
if ( ( V_51 -> V_21 == V_21 ) &&
F_33 ( V_51 -> V_56 , V_79 ) ) {
V_51 -> V_59 = 1 ;
V_59 = 1 ;
}
}
if ( V_59 ) {
V_29 -> V_60 = 1 ;
V_29 -> V_80 = V_81 ;
}
F_29 ( V_9 ) ;
}
static void F_54 ( struct V_8 * V_9 , T_3 V_90 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_50 * V_51 ;
T_2 V_42 ;
F_30 ( V_9 ) ;
V_42 = V_29 -> V_77 ;
for (; V_42 != V_78 ; V_42 = V_51 -> V_18 ) {
V_51 = & ( V_29 -> V_53 [ V_42 ] ) ;
if ( ! V_51 -> V_21 ) {
F_19 ( L_7 ,
V_9 -> V_34 -> V_35 ) ;
continue;
}
if ( ( V_51 -> V_52 == V_90 ) &&
F_33 ( V_51 -> V_21 -> V_34 -> V_83 ,
V_9 -> V_34 -> V_83 ) &&
F_33 ( V_51 -> V_56 , V_79 ) ) {
V_51 -> V_59 = 1 ;
V_29 -> V_60 = 1 ;
}
}
F_31 ( V_9 ) ;
}
static struct V_21 * F_55 ( struct V_2 * V_3 , struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_1 * V_49 = V_1 ( V_3 ) ;
struct V_21 * V_45 ;
struct V_50 * V_51 ;
T_2 V_42 = 0 ;
F_30 ( V_9 ) ;
V_42 = F_2 ( ( T_1 * ) & V_49 -> V_55 , sizeof( V_49 -> V_55 ) ) ;
V_51 = & ( V_29 -> V_53 [ V_42 ] ) ;
if ( V_51 -> V_54 ) {
if ( ( V_51 -> V_52 == V_49 -> V_52 ) &&
( V_51 -> V_55 == V_49 -> V_55 ) ) {
if ( F_33 ( V_49 -> V_56 , V_79 ) ) {
memcpy ( V_51 -> V_56 , V_49 -> V_56 , V_58 ) ;
}
V_45 = V_51 -> V_21 ;
if ( V_45 ) {
F_31 ( V_9 ) ;
return V_45 ;
}
} else {
if ( V_9 -> V_72 &&
V_51 -> V_21 != V_9 -> V_72 ) {
V_51 -> V_21 = V_9 -> V_72 ;
F_48 ( V_51 ) ;
}
}
}
V_45 = F_40 ( V_9 ) ;
if ( V_45 ) {
V_51 -> V_52 = V_49 -> V_52 ;
V_51 -> V_55 = V_49 -> V_55 ;
memcpy ( V_51 -> V_56 , V_49 -> V_56 , V_58 ) ;
V_51 -> V_21 = V_45 ;
if ( F_33 ( V_51 -> V_56 , V_79 ) ) {
V_51 -> V_59 = 1 ;
V_9 -> V_73 . V_60 = 1 ;
} else {
V_51 -> V_59 = 0 ;
}
if ( F_56 ( V_9 ) ) {
if ( ! F_57 ( V_3 , & V_51 -> V_87 ) )
V_51 -> V_86 = 1 ;
}
if ( ! V_51 -> V_54 ) {
T_2 V_91 = V_29 -> V_77 ;
V_29 -> V_77 = V_42 ;
V_51 -> V_18 = V_91 ;
if ( V_91 != V_78 ) {
V_29 -> V_53 [ V_91 ] . V_20 =
V_42 ;
}
V_51 -> V_54 = 1 ;
}
}
F_31 ( V_9 ) ;
return V_45 ;
}
static struct V_21 * F_58 ( struct V_2 * V_3 , struct V_8 * V_9 )
{
struct V_1 * V_49 = V_1 ( V_3 ) ;
struct V_21 * V_17 = NULL ;
if ( V_49 -> V_65 == F_39 ( V_66 ) ) {
V_17 = F_55 ( V_3 , V_9 ) ;
if ( V_17 ) {
memcpy ( V_49 -> V_57 , V_17 -> V_34 -> V_83 , V_58 ) ;
}
F_36 ( L_8 ) ;
} else if ( V_49 -> V_65 == F_39 ( V_92 ) ) {
F_55 ( V_3 , V_9 ) ;
V_9 -> V_73 . V_88 = V_89 ;
F_54 ( V_9 , V_49 -> V_52 ) ;
F_36 ( L_9 ) ;
}
return V_17 ;
}
static void F_59 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_21 * V_45 ;
struct V_50 * V_51 ;
int V_59 ;
T_2 V_42 ;
F_28 ( V_9 ) ;
V_59 = 0 ;
V_42 = V_29 -> V_77 ;
for (; V_42 != V_78 ; V_42 = V_51 -> V_18 ) {
V_51 = & ( V_29 -> V_53 [ V_42 ] ) ;
V_45 = F_40 ( V_9 ) ;
if ( V_45 && ( V_51 -> V_21 != V_45 ) ) {
V_51 -> V_21 = V_45 ;
V_51 -> V_59 = 1 ;
V_59 = 1 ;
}
}
if ( V_59 ) {
V_29 -> V_60 = 1 ;
}
F_29 ( V_9 ) ;
}
static void F_60 ( struct V_50 * V_12 )
{
memset ( V_12 , 0 , sizeof( struct V_50 ) ) ;
V_12 -> V_18 = V_78 ;
V_12 -> V_20 = V_78 ;
}
static int F_61 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_50 * V_32 ;
int V_30 = V_93 * sizeof( struct V_50 ) ;
int V_6 ;
V_32 = F_62 ( V_30 , V_33 ) ;
if ( ! V_32 ) {
F_19 ( L_10 ,
V_9 -> V_34 -> V_35 ) ;
return - 1 ;
}
F_28 ( V_9 ) ;
V_29 -> V_53 = V_32 ;
V_29 -> V_77 = V_78 ;
for ( V_6 = 0 ; V_6 < V_93 ; V_6 ++ ) {
F_60 ( V_29 -> V_53 + V_6 ) ;
}
F_29 ( V_9 ) ;
V_9 -> V_94 = F_34 ;
return 0 ;
}
static void F_63 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
F_28 ( V_9 ) ;
F_21 ( V_29 -> V_53 ) ;
V_29 -> V_53 = NULL ;
V_29 -> V_77 = V_78 ;
F_29 ( V_9 ) ;
}
static void F_64 ( struct V_8 * V_9 , unsigned short V_87 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
T_2 V_95 ;
F_28 ( V_9 ) ;
V_95 = V_29 -> V_77 ;
while ( V_95 != V_78 ) {
struct V_50 * V_96 = & ( V_29 -> V_53 [ V_95 ] ) ;
T_2 V_27 = V_29 -> V_53 [ V_95 ] . V_18 ;
T_2 V_97 = V_29 -> V_53 [ V_95 ] . V_20 ;
if ( V_96 -> V_86 && ( V_96 -> V_87 == V_87 ) ) {
if ( V_95 == V_29 -> V_77 ) {
V_29 -> V_77 = V_27 ;
}
if ( V_97 != V_78 ) {
V_29 -> V_53 [ V_97 ] . V_18 = V_27 ;
}
if ( V_27 != V_78 ) {
V_29 -> V_53 [ V_27 ] . V_20 = V_97 ;
}
F_60 ( V_96 ) ;
}
V_95 = V_27 ;
}
F_29 ( V_9 ) ;
}
static void F_44 ( struct V_21 * V_21 , T_1 V_98 [] )
{
struct V_8 * V_9 = F_65 ( V_21 ) ;
struct V_99 V_100 ;
int V_30 = sizeof( struct V_99 ) ;
int V_6 ;
memset ( & V_100 , 0 , V_30 ) ;
memcpy ( V_100 . V_56 , V_98 , V_58 ) ;
memcpy ( V_100 . V_57 , V_98 , V_58 ) ;
V_100 . type = F_35 ( V_101 ) ;
for ( V_6 = 0 ; V_6 < V_102 ; V_6 ++ ) {
struct V_2 * V_3 ;
char * V_63 ;
V_3 = F_66 ( V_30 ) ;
if ( ! V_3 ) {
return;
}
V_63 = F_67 ( V_3 , V_30 ) ;
memcpy ( V_63 , & V_100 , V_30 ) ;
F_68 ( V_3 ) ;
V_3 -> V_103 = V_3 -> V_104 + V_105 ;
V_3 -> V_61 = V_100 . type ;
V_3 -> V_106 = V_107 ;
V_3 -> V_34 = V_21 -> V_34 ;
if ( F_56 ( V_9 ) ) {
struct V_108 * V_109 ;
V_109 = F_69 ( V_9 ,
V_9 -> V_73 . V_110 ) ;
V_9 -> V_73 . V_110 = V_109 ;
if ( ! V_109 ) {
F_70 ( V_3 ) ;
continue;
}
V_3 = F_50 ( V_3 , V_109 -> V_87 ) ;
if ( ! V_3 ) {
F_19 ( L_6 ,
V_9 -> V_34 -> V_35 ) ;
continue;
}
}
F_71 ( V_3 ) ;
}
}
static int F_72 ( struct V_21 * V_21 , T_1 V_71 [] )
{
struct V_111 * V_34 = V_21 -> V_34 ;
struct V_112 V_113 ;
if ( V_21 -> V_9 -> V_114 . V_115 == V_116 ) {
memcpy ( V_34 -> V_83 , V_71 , V_34 -> V_117 ) ;
return 0 ;
}
memcpy ( V_113 . V_118 , V_71 , V_34 -> V_117 ) ;
V_113 . V_119 = V_34 -> type ;
if ( F_73 ( V_34 , & V_113 ) ) {
F_19 ( L_11
L_12 ,
V_34 -> V_85 -> V_35 , V_34 -> V_35 ) ;
return - V_120 ;
}
return 0 ;
}
static void F_74 ( struct V_8 * V_9 , struct V_21 * V_121 , struct V_21 * V_122 )
{
T_1 V_123 [ V_58 ] ;
memcpy ( V_123 , V_121 -> V_34 -> V_83 , V_58 ) ;
F_72 ( V_121 , V_122 -> V_34 -> V_83 ) ;
F_72 ( V_122 , V_123 ) ;
}
static void F_75 ( struct V_8 * V_9 , struct V_21 * V_121 ,
struct V_21 * V_122 )
{
int V_124 = ( F_25 ( V_121 ) != F_25 ( V_122 ) ) ;
struct V_21 * V_125 = NULL ;
F_76 () ;
if ( F_25 ( V_121 ) ) {
F_44 ( V_121 , V_121 -> V_34 -> V_83 ) ;
if ( V_9 -> V_73 . V_126 ) {
F_53 ( V_9 , V_121 ) ;
}
} else {
V_125 = V_121 ;
}
if ( F_25 ( V_122 ) ) {
F_44 ( V_122 , V_122 -> V_34 -> V_83 ) ;
if ( V_9 -> V_73 . V_126 ) {
F_53 ( V_9 , V_122 ) ;
}
} else {
V_125 = V_122 ;
}
if ( V_9 -> V_73 . V_126 && V_124 ) {
F_42 ( V_9 ,
V_125 -> V_34 -> V_83 ) ;
}
}
static void F_77 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
int V_127 ;
int V_128 ;
V_127 = F_33 ( V_21 -> V_129 ,
V_21 -> V_34 -> V_83 ) ;
V_128 = F_33 ( V_21 -> V_129 ,
V_9 -> V_34 -> V_83 ) ;
if ( V_127 && V_128 ) {
struct V_21 * V_130 ;
int V_6 , V_131 = 0 ;
F_24 (bond, tmp_slave, i) {
if ( ! F_33 ( V_21 -> V_129 ,
V_130 -> V_34 -> V_83 ) ) {
V_131 = 1 ;
break;
}
}
if ( V_131 ) {
F_74 ( V_9 , V_21 , V_130 ) ;
F_75 ( V_9 , V_21 , V_130 ) ;
}
}
}
static int F_78 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
struct V_21 * V_132 , * V_133 , * V_134 ;
struct V_21 * V_135 = V_9 -> V_72 ;
int V_6 , V_136 , V_131 = 0 ;
if ( V_9 -> V_137 == 0 ) {
return 0 ;
}
if ( F_33 ( V_21 -> V_129 , V_9 -> V_34 -> V_83 ) ) {
F_24 (bond, tmp_slave1, i) {
if ( ! F_33 ( V_132 -> V_34 -> V_83 ,
V_21 -> V_34 -> V_83 ) ) {
V_131 = 1 ;
break;
}
}
if ( ! V_131 )
return 0 ;
F_72 ( V_21 , V_9 -> V_34 -> V_83 ) ;
}
V_134 = NULL ;
F_24 (bond, tmp_slave1, i) {
V_131 = 0 ;
F_24 (bond, tmp_slave2, j) {
if ( ! F_33 ( V_132 -> V_129 ,
V_133 -> V_34 -> V_83 ) ) {
V_131 = 1 ;
break;
}
}
if ( ! V_131 ) {
V_134 = V_132 ;
break;
}
if ( ! V_135 ) {
if ( ! F_33 ( V_132 -> V_34 -> V_83 ,
V_9 -> V_34 -> V_83 ) ) {
V_135 = V_132 ;
}
}
}
if ( V_134 ) {
F_72 ( V_21 , V_134 -> V_129 ) ;
F_79 ( L_13 ,
V_9 -> V_34 -> V_35 , V_21 -> V_34 -> V_35 ,
V_134 -> V_34 -> V_35 ) ;
} else if ( V_135 ) {
F_19 ( L_14 ,
V_9 -> V_34 -> V_35 , V_21 -> V_34 -> V_35 ) ;
return - V_138 ;
}
return 0 ;
}
static int F_80 ( struct V_8 * V_9 , void * V_71 )
{
struct V_112 V_139 ;
struct V_21 * V_21 , * V_140 ;
char V_141 [ V_58 ] ;
int V_142 ;
int V_6 ;
if ( V_9 -> V_73 . V_126 ) {
return 0 ;
}
F_24 (bond, slave, i) {
memcpy ( V_141 , V_21 -> V_34 -> V_83 , V_58 ) ;
V_142 = F_73 ( V_21 -> V_34 , V_71 ) ;
memcpy ( V_21 -> V_34 -> V_83 , V_141 , V_58 ) ;
if ( V_142 )
goto V_143;
}
return 0 ;
V_143:
memcpy ( V_139 . V_118 , V_9 -> V_34 -> V_83 , V_9 -> V_34 -> V_117 ) ;
V_139 . V_119 = V_9 -> V_34 -> type ;
V_140 = V_21 ;
F_81 (bond, slave, i, bond->first_slave, stop_at) {
memcpy ( V_141 , V_21 -> V_34 -> V_83 , V_58 ) ;
F_73 ( V_21 -> V_34 , & V_139 ) ;
memcpy ( V_21 -> V_34 -> V_83 , V_141 , V_58 ) ;
}
return V_142 ;
}
int F_82 ( struct V_8 * V_9 , int V_126 )
{
int V_142 ;
V_142 = F_17 ( V_9 ) ;
if ( V_142 ) {
return V_142 ;
}
if ( V_126 ) {
V_9 -> V_73 . V_126 = 1 ;
V_142 = F_61 ( V_9 ) ;
if ( V_142 ) {
F_20 ( V_9 ) ;
return V_142 ;
}
} else {
V_9 -> V_73 . V_126 = 0 ;
}
return 0 ;
}
void F_83 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
F_20 ( V_9 ) ;
if ( V_29 -> V_126 ) {
F_63 ( V_9 ) ;
}
}
int F_84 ( struct V_2 * V_3 , struct V_111 * V_144 )
{
struct V_8 * V_9 = F_85 ( V_144 ) ;
struct V_145 * V_146 ;
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_21 * V_17 = NULL ;
static const T_3 V_147 = F_86 ( 0xffffffff ) ;
int V_5 = 0 ;
int V_148 = 1 ;
T_2 V_42 = 0 ;
const T_1 * V_4 = NULL ;
int V_142 = 1 ;
struct V_149 * V_150 ;
F_68 ( V_3 ) ;
V_146 = F_87 ( V_3 ) ;
F_88 ( & V_9 -> V_82 ) ;
switch ( F_89 ( V_3 -> V_61 ) ) {
case V_151 : {
const struct V_152 * V_153 = F_90 ( V_3 ) ;
if ( ! F_33 ( V_146 -> V_154 , V_79 ) ||
( V_153 -> V_155 == V_147 ) ||
( V_153 -> V_61 == V_156 ) ) {
V_148 = 0 ;
break;
}
V_4 = ( char * ) & ( V_153 -> V_155 ) ;
V_5 = sizeof( V_153 -> V_155 ) ;
}
break;
case V_157 :
if ( ! F_33 ( V_146 -> V_154 , V_79 ) ) {
V_148 = 0 ;
break;
}
if ( ! F_33 ( V_146 -> V_154 , V_158 ) ) {
V_148 = 0 ;
break;
}
V_150 = F_91 ( V_3 ) ;
if ( F_92 ( & V_150 -> V_159 ) ) {
V_148 = 0 ;
break;
}
V_4 = ( char * ) & ( F_91 ( V_3 ) -> V_155 ) ;
V_5 = sizeof( F_91 ( V_3 ) -> V_155 ) ;
break;
case V_160 :
if ( F_93 ( V_3 ) -> V_161 != V_162 ) {
V_148 = 0 ;
break;
}
if ( F_93 ( V_3 ) -> V_163 != V_164 ) {
V_148 = 0 ;
break;
}
V_4 = ( char * ) V_146 -> V_154 ;
V_5 = V_58 ;
break;
case V_62 :
V_148 = 0 ;
if ( V_29 -> V_126 ) {
V_17 = F_58 ( V_3 , V_9 ) ;
}
break;
default:
V_148 = 0 ;
break;
}
if ( V_148 ) {
V_42 = F_2 ( V_4 , V_5 ) ;
V_17 = F_27 ( V_9 , V_42 , V_3 -> V_64 ) ;
}
if ( ! V_17 ) {
V_17 = V_9 -> V_72 ;
V_29 -> V_165 += V_3 -> V_64 ;
}
if ( V_17 && F_25 ( V_17 ) ) {
if ( V_17 != V_9 -> V_72 ) {
memcpy ( V_146 -> V_166 ,
V_17 -> V_34 -> V_83 ,
V_58 ) ;
}
V_142 = F_94 ( V_9 , V_3 , V_17 -> V_34 ) ;
} else {
if ( V_17 ) {
F_8 ( V_9 ) ;
F_15 ( V_9 , V_17 , 0 ) ;
F_10 ( V_9 ) ;
}
}
if ( V_142 ) {
F_95 ( V_3 ) ;
}
F_96 ( & V_9 -> V_82 ) ;
return V_167 ;
}
void F_97 ( struct V_168 * V_169 )
{
struct V_8 * V_9 = F_98 ( V_169 , struct V_8 ,
V_170 . V_169 ) ;
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_21 * V_21 ;
int V_6 ;
F_88 ( & V_9 -> V_171 ) ;
if ( V_9 -> V_137 == 0 ) {
V_29 -> V_172 = 0 ;
V_29 -> V_173 = 0 ;
goto V_174;
}
V_29 -> V_172 ++ ;
V_29 -> V_173 ++ ;
if ( V_29 -> V_173 >= V_175 ) {
F_88 ( & V_9 -> V_82 ) ;
F_24 (bond, slave, i) {
F_44 ( V_21 , V_21 -> V_34 -> V_83 ) ;
}
F_96 ( & V_9 -> V_82 ) ;
V_29 -> V_173 = 0 ;
}
if ( V_29 -> V_172 >= V_176 ) {
F_88 ( & V_9 -> V_82 ) ;
F_24 (bond, slave, i) {
F_16 ( V_9 , V_21 , 1 ) ;
if ( V_21 == V_9 -> V_72 ) {
F_14 ( V_21 ) . V_22 =
V_29 -> V_165 /
V_16 ;
V_29 -> V_165 = 0 ;
}
}
F_96 ( & V_9 -> V_82 ) ;
V_29 -> V_172 = 0 ;
}
if ( V_29 -> V_126 ) {
if ( V_29 -> V_74 &&
( ++ V_29 -> V_75 >= V_177 ) ) {
F_96 ( & V_9 -> V_171 ) ;
if ( ! F_99 () ) {
F_88 ( & V_9 -> V_171 ) ;
goto V_174;
}
V_29 -> V_75 = 0 ;
F_43 ( V_9 -> V_72 -> V_34 , - 1 ) ;
V_29 -> V_74 = 0 ;
F_100 () ;
F_88 ( & V_9 -> V_171 ) ;
}
if ( V_29 -> F_59 ) {
V_29 -> F_59 = 0 ;
F_59 ( V_9 ) ;
}
if ( V_29 -> V_60 ) {
if ( V_29 -> V_88 ) {
-- V_29 -> V_88 ;
} else {
F_52 ( V_9 ) ;
if ( V_29 -> V_80 ) {
-- V_29 -> V_80 ;
} else {
V_29 -> V_60 = 0 ;
}
}
}
}
V_174:
F_101 ( V_9 -> V_178 , & V_9 -> V_170 , V_179 ) ;
F_96 ( & V_9 -> V_171 ) ;
}
int F_102 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
int V_142 ;
V_142 = F_72 ( V_21 , V_21 -> V_129 ) ;
if ( V_142 ) {
return V_142 ;
}
F_88 ( & V_9 -> V_171 ) ;
V_142 = F_78 ( V_9 , V_21 ) ;
F_96 ( & V_9 -> V_171 ) ;
if ( V_142 ) {
return V_142 ;
}
F_13 ( V_21 ) ;
V_9 -> V_73 . V_172 = V_176 ;
if ( V_9 -> V_73 . V_126 ) {
V_9 -> V_73 . F_59 = 1 ;
}
return 0 ;
}
void F_103 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
if ( V_9 -> V_137 > 1 ) {
F_77 ( V_9 , V_21 ) ;
}
F_16 ( V_9 , V_21 , 0 ) ;
if ( V_9 -> V_73 . V_126 ) {
V_9 -> V_73 . V_69 = NULL ;
F_45 ( V_9 , V_21 ) ;
}
}
void F_104 ( struct V_8 * V_9 , struct V_21 * V_21 , char V_180 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
if ( V_180 == V_181 ) {
F_16 ( V_9 , V_21 , 0 ) ;
if ( V_9 -> V_73 . V_126 ) {
F_45 ( V_9 , V_21 ) ;
}
} else if ( V_180 == V_182 ) {
V_29 -> V_172 = V_176 ;
if ( V_9 -> V_73 . V_126 ) {
V_9 -> V_73 . F_59 = 1 ;
}
}
}
void F_105 ( struct V_8 * V_9 , struct V_21 * V_183 )
__releases( &bond->curr_slave_lock
int F_106 ( struct V_111 * V_144 , void * V_71 )
__acquires( &bond->lock
void F_107 ( struct V_8 * V_9 , unsigned short V_87 )
{
if ( V_9 -> V_73 . V_110 &&
( V_9 -> V_73 . V_110 -> V_87 == V_87 ) ) {
V_9 -> V_73 . V_110 = NULL ;
}
if ( V_9 -> V_73 . V_126 ) {
F_64 ( V_9 , V_87 ) ;
}
}
