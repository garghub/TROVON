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
static inline void F_8 ( struct V_11 * V_12 , int V_13 )
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
static inline void F_9 ( struct V_21 * V_21 )
{
F_10 ( V_21 ) . V_22 = 0 ;
F_10 ( V_21 ) . V_23 = V_19 ;
}
static void F_11 ( struct V_8 * V_9 , struct V_21 * V_21 , int V_13 )
{
struct V_11 * V_24 ;
T_2 V_25 ;
F_3 ( V_9 ) ;
V_24 = F_5 ( V_9 ) . V_26 ;
if ( V_24 ) {
V_25 = F_10 ( V_21 ) . V_23 ;
while ( V_25 != V_19 ) {
T_2 V_27 = V_24 [ V_25 ] . V_18 ;
F_8 ( & V_24 [ V_25 ] , V_13 ) ;
V_25 = V_27 ;
}
}
F_9 ( V_21 ) ;
F_6 ( V_9 ) ;
}
static int F_12 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
int V_30 = V_31 * sizeof( struct V_11 ) ;
struct V_11 * V_32 ;
int V_6 ;
V_32 = F_13 ( V_30 , V_33 ) ;
if ( ! V_32 ) {
F_14 ( L_1 ,
V_9 -> V_34 -> V_35 ) ;
return - 1 ;
}
F_3 ( V_9 ) ;
V_29 -> V_26 = V_32 ;
for ( V_6 = 0 ; V_6 < V_31 ; V_6 ++ ) {
F_8 ( & V_29 -> V_26 [ V_6 ] , 0 ) ;
}
F_6 ( V_9 ) ;
return 0 ;
}
static void F_15 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
F_3 ( V_9 ) ;
F_16 ( V_29 -> V_26 ) ;
V_29 -> V_26 = NULL ;
F_6 ( V_9 ) ;
}
static long long F_17 ( struct V_21 * V_21 )
{
return ( V_36 ) ( V_21 -> V_37 << 20 ) -
( V_36 ) ( F_10 ( V_21 ) . V_22 << 3 ) ;
}
static struct V_21 * F_18 ( struct V_8 * V_9 )
{
struct V_21 * V_21 , * V_38 ;
long long V_39 ;
int V_6 ;
V_38 = NULL ;
V_39 = V_40 ;
F_19 (bond, slave, i) {
if ( F_20 ( V_21 ) ) {
long long V_41 = F_17 ( V_21 ) ;
if ( V_39 < V_41 ) {
V_38 = V_21 ;
V_39 = V_41 ;
}
}
}
return V_38 ;
}
static struct V_21 * F_21 ( struct V_8 * V_9 , T_2 V_42 , T_2 V_43 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_11 * V_44 ;
struct V_21 * V_45 ;
F_3 ( V_9 ) ;
V_44 = V_29 -> V_26 ;
V_45 = V_44 [ V_42 ] . V_17 ;
if ( ! V_45 ) {
V_45 = F_18 ( V_9 ) ;
if ( V_45 ) {
struct V_46 * V_47 =
& ( F_10 ( V_45 ) ) ;
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
F_6 ( V_9 ) ;
return V_45 ;
}
static inline void F_22 ( struct V_8 * V_9 )
{
F_4 ( & ( F_5 ( V_9 ) . V_48 ) ) ;
}
static inline void F_23 ( struct V_8 * V_9 )
{
F_7 ( & ( F_5 ( V_9 ) . V_48 ) ) ;
}
static void F_24 ( struct V_8 * V_9 , struct V_1 * V_49 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_50 * V_51 ;
T_2 V_42 ;
F_22 ( V_9 ) ;
V_42 = F_2 ( ( T_1 * ) & ( V_49 -> V_52 ) , sizeof( V_49 -> V_52 ) ) ;
V_51 = & ( V_29 -> V_53 [ V_42 ] ) ;
if ( ( V_51 -> V_54 ) &&
( V_51 -> V_52 == V_49 -> V_55 ) &&
( V_51 -> V_55 == V_49 -> V_52 ) &&
( F_25 ( V_51 -> V_56 , V_49 -> V_57 ) ) ) {
memcpy ( V_51 -> V_56 , V_49 -> V_57 , V_58 ) ;
V_51 -> V_59 = 1 ;
V_29 -> V_60 = 1 ;
}
F_23 ( V_9 ) ;
}
static void F_26 ( struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_21 * V_21 )
{
struct V_1 * V_49 ;
if ( V_3 -> V_61 != F_27 ( V_62 ) )
return;
V_49 = (struct V_1 * ) V_3 -> V_63 ;
if ( ! V_49 ) {
F_28 ( L_2 ) ;
return;
}
if ( ! F_29 ( V_3 , F_30 ( V_9 -> V_34 ) ) )
return;
if ( V_3 -> V_64 < sizeof( struct V_1 ) ) {
F_28 ( L_3 ) ;
return;
}
if ( V_49 -> V_65 == F_31 ( V_66 ) ) {
F_24 ( V_9 , V_49 ) ;
F_28 ( L_4 ) ;
}
}
static struct V_21 * F_32 ( struct V_8 * V_9 )
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
F_33 (bond, slave, i, start_at) {
if ( F_20 ( V_21 ) ) {
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
static void F_34 ( struct V_8 * V_9 , T_1 V_71 [] )
{
if ( ! V_9 -> V_72 ) {
return;
}
if ( ! V_9 -> V_73 . V_74 ) {
if ( ! F_35 ( V_9 -> V_72 -> V_34 , 1 ) )
V_9 -> V_73 . V_74 = 1 ;
else
V_9 -> V_73 . V_74 = 0 ;
}
V_9 -> V_73 . V_75 = 0 ;
F_36 ( V_9 -> V_72 , V_71 ) ;
}
static void F_37 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_50 * V_76 ;
T_2 V_25 , V_27 ;
F_22 ( V_9 ) ;
V_76 = V_29 -> V_53 ;
V_25 = V_29 -> V_77 ;
for (; V_25 != V_78 ; V_25 = V_27 ) {
V_27 = V_76 [ V_25 ] . V_18 ;
if ( V_76 [ V_25 ] . V_21 == V_21 ) {
struct V_21 * V_45 = F_32 ( V_9 ) ;
if ( V_45 ) {
V_76 [ V_25 ] . V_21 = V_45 ;
if ( F_25 ( V_76 [ V_25 ] . V_56 ,
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
F_23 ( V_9 ) ;
F_38 ( & V_9 -> V_82 ) ;
if ( V_21 != V_9 -> V_72 ) {
F_34 ( V_9 , V_21 -> V_34 -> V_83 ) ;
}
F_39 ( & V_9 -> V_82 ) ;
}
static void F_40 ( struct V_50 * V_51 )
{
int V_6 ;
if ( ! V_51 -> V_21 ) {
return;
}
for ( V_6 = 0 ; V_6 < V_84 ; V_6 ++ ) {
struct V_2 * V_3 ;
V_3 = F_41 ( V_66 , V_62 ,
V_51 -> V_55 ,
V_51 -> V_21 -> V_34 ,
V_51 -> V_52 ,
V_51 -> V_56 ,
V_51 -> V_21 -> V_34 -> V_83 ,
V_51 -> V_56 ) ;
if ( ! V_3 ) {
F_14 ( L_5 ,
V_51 -> V_21 -> V_34 -> V_85 -> V_35 ) ;
continue;
}
V_3 -> V_34 = V_51 -> V_21 -> V_34 ;
if ( V_51 -> V_86 ) {
V_3 = F_42 ( V_3 , V_51 -> V_87 ) ;
if ( ! V_3 ) {
F_14 ( L_6 ,
V_51 -> V_21 -> V_34 -> V_85 -> V_35 ) ;
continue;
}
}
F_43 ( V_3 ) ;
}
}
static void F_44 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_50 * V_51 ;
T_2 V_42 ;
F_22 ( V_9 ) ;
V_42 = V_29 -> V_77 ;
for (; V_42 != V_78 ; V_42 = V_51 -> V_18 ) {
V_51 = & ( V_29 -> V_53 [ V_42 ] ) ;
if ( V_51 -> V_59 ) {
F_40 ( V_51 ) ;
if ( V_29 -> V_80 == 0 ) {
V_51 -> V_59 = 0 ;
}
}
}
V_29 -> V_88 = V_89 ;
F_23 ( V_9 ) ;
}
static void F_45 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_50 * V_51 ;
int V_59 = 0 ;
T_2 V_42 ;
F_22 ( V_9 ) ;
V_42 = V_29 -> V_77 ;
for (; V_42 != V_78 ; V_42 = V_51 -> V_18 ) {
V_51 = & ( V_29 -> V_53 [ V_42 ] ) ;
if ( ( V_51 -> V_21 == V_21 ) &&
F_25 ( V_51 -> V_56 , V_79 ) ) {
V_51 -> V_59 = 1 ;
V_59 = 1 ;
}
}
if ( V_59 ) {
V_29 -> V_60 = 1 ;
V_29 -> V_80 = V_81 ;
}
F_23 ( V_9 ) ;
}
static void F_46 ( struct V_8 * V_9 , T_3 V_90 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_50 * V_51 ;
T_2 V_42 ;
F_22 ( V_9 ) ;
V_42 = V_29 -> V_77 ;
for (; V_42 != V_78 ; V_42 = V_51 -> V_18 ) {
V_51 = & ( V_29 -> V_53 [ V_42 ] ) ;
if ( ! V_51 -> V_21 ) {
F_14 ( L_7 ,
V_9 -> V_34 -> V_35 ) ;
continue;
}
if ( ( V_51 -> V_52 == V_90 ) &&
F_25 ( V_51 -> V_21 -> V_34 -> V_83 ,
V_9 -> V_34 -> V_83 ) &&
F_25 ( V_51 -> V_56 , V_79 ) ) {
V_51 -> V_59 = 1 ;
V_29 -> V_60 = 1 ;
}
}
F_23 ( V_9 ) ;
}
static struct V_21 * F_47 ( struct V_2 * V_3 , struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_1 * V_49 = V_1 ( V_3 ) ;
struct V_21 * V_45 ;
struct V_50 * V_51 ;
T_2 V_42 = 0 ;
F_22 ( V_9 ) ;
V_42 = F_2 ( ( T_1 * ) & V_49 -> V_55 , sizeof( V_49 -> V_55 ) ) ;
V_51 = & ( V_29 -> V_53 [ V_42 ] ) ;
if ( V_51 -> V_54 ) {
if ( ( V_51 -> V_52 == V_49 -> V_52 ) &&
( V_51 -> V_55 == V_49 -> V_55 ) ) {
if ( F_25 ( V_49 -> V_56 , V_79 ) ) {
memcpy ( V_51 -> V_56 , V_49 -> V_56 , V_58 ) ;
}
V_45 = V_51 -> V_21 ;
if ( V_45 ) {
F_23 ( V_9 ) ;
return V_45 ;
}
} else {
if ( V_9 -> V_72 &&
V_51 -> V_21 != V_9 -> V_72 ) {
V_51 -> V_21 = V_9 -> V_72 ;
F_40 ( V_51 ) ;
}
}
}
V_45 = F_32 ( V_9 ) ;
if ( V_45 ) {
V_51 -> V_52 = V_49 -> V_52 ;
V_51 -> V_55 = V_49 -> V_55 ;
memcpy ( V_51 -> V_56 , V_49 -> V_56 , V_58 ) ;
V_51 -> V_21 = V_45 ;
if ( F_25 ( V_51 -> V_56 , V_79 ) ) {
V_51 -> V_59 = 1 ;
V_9 -> V_73 . V_60 = 1 ;
} else {
V_51 -> V_59 = 0 ;
}
if ( V_9 -> V_91 ) {
if ( ! F_48 ( V_3 , & V_51 -> V_87 ) )
V_51 -> V_86 = 1 ;
}
if ( ! V_51 -> V_54 ) {
T_2 V_92 = V_29 -> V_77 ;
V_29 -> V_77 = V_42 ;
V_51 -> V_18 = V_92 ;
if ( V_92 != V_78 ) {
V_29 -> V_53 [ V_92 ] . V_20 =
V_42 ;
}
V_51 -> V_54 = 1 ;
}
}
F_23 ( V_9 ) ;
return V_45 ;
}
static struct V_21 * F_49 ( struct V_2 * V_3 , struct V_8 * V_9 )
{
struct V_1 * V_49 = V_1 ( V_3 ) ;
struct V_21 * V_17 = NULL ;
if ( V_49 -> V_65 == F_31 ( V_66 ) ) {
V_17 = F_47 ( V_3 , V_9 ) ;
if ( V_17 ) {
memcpy ( V_49 -> V_57 , V_17 -> V_34 -> V_83 , V_58 ) ;
}
F_28 ( L_8 ) ;
} else if ( V_49 -> V_65 == F_31 ( V_93 ) ) {
F_47 ( V_3 , V_9 ) ;
V_9 -> V_73 . V_88 = V_89 ;
F_46 ( V_9 , V_49 -> V_52 ) ;
F_28 ( L_9 ) ;
}
return V_17 ;
}
static void F_50 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_21 * V_45 ;
struct V_50 * V_51 ;
int V_59 ;
T_2 V_42 ;
F_22 ( V_9 ) ;
V_59 = 0 ;
V_42 = V_29 -> V_77 ;
for (; V_42 != V_78 ; V_42 = V_51 -> V_18 ) {
V_51 = & ( V_29 -> V_53 [ V_42 ] ) ;
V_45 = F_32 ( V_9 ) ;
if ( V_45 && ( V_51 -> V_21 != V_45 ) ) {
V_51 -> V_21 = V_45 ;
V_51 -> V_59 = 1 ;
V_59 = 1 ;
}
}
if ( V_59 ) {
V_29 -> V_60 = 1 ;
}
F_23 ( V_9 ) ;
}
static void F_51 ( struct V_50 * V_12 )
{
memset ( V_12 , 0 , sizeof( struct V_50 ) ) ;
V_12 -> V_18 = V_78 ;
V_12 -> V_20 = V_78 ;
}
static int F_52 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_50 * V_32 ;
int V_30 = V_94 * sizeof( struct V_50 ) ;
int V_6 ;
V_32 = F_53 ( V_30 , V_33 ) ;
if ( ! V_32 ) {
F_14 ( L_10 ,
V_9 -> V_34 -> V_35 ) ;
return - 1 ;
}
F_22 ( V_9 ) ;
V_29 -> V_53 = V_32 ;
V_29 -> V_77 = V_78 ;
for ( V_6 = 0 ; V_6 < V_94 ; V_6 ++ ) {
F_51 ( V_29 -> V_53 + V_6 ) ;
}
F_23 ( V_9 ) ;
V_9 -> V_95 = F_26 ;
return 0 ;
}
static void F_54 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
F_22 ( V_9 ) ;
F_16 ( V_29 -> V_53 ) ;
V_29 -> V_53 = NULL ;
V_29 -> V_77 = V_78 ;
F_23 ( V_9 ) ;
}
static void F_55 ( struct V_8 * V_9 , unsigned short V_87 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
T_2 V_96 ;
F_22 ( V_9 ) ;
V_96 = V_29 -> V_77 ;
while ( V_96 != V_78 ) {
struct V_50 * V_97 = & ( V_29 -> V_53 [ V_96 ] ) ;
T_2 V_27 = V_29 -> V_53 [ V_96 ] . V_18 ;
T_2 V_98 = V_29 -> V_53 [ V_96 ] . V_20 ;
if ( V_97 -> V_86 && ( V_97 -> V_87 == V_87 ) ) {
if ( V_96 == V_29 -> V_77 ) {
V_29 -> V_77 = V_27 ;
}
if ( V_98 != V_78 ) {
V_29 -> V_53 [ V_98 ] . V_18 = V_27 ;
}
if ( V_27 != V_78 ) {
V_29 -> V_53 [ V_27 ] . V_20 = V_98 ;
}
F_51 ( V_97 ) ;
}
V_96 = V_27 ;
}
F_23 ( V_9 ) ;
}
static void F_36 ( struct V_21 * V_21 , T_1 V_99 [] )
{
struct V_8 * V_9 = F_56 ( V_21 ) ;
struct V_100 V_101 ;
int V_30 = sizeof( struct V_100 ) ;
int V_6 ;
memset ( & V_101 , 0 , V_30 ) ;
memcpy ( V_101 . V_56 , V_99 , V_58 ) ;
memcpy ( V_101 . V_57 , V_99 , V_58 ) ;
V_101 . type = F_27 ( V_102 ) ;
for ( V_6 = 0 ; V_6 < V_103 ; V_6 ++ ) {
struct V_2 * V_3 ;
char * V_63 ;
V_3 = F_57 ( V_30 ) ;
if ( ! V_3 ) {
return;
}
V_63 = F_58 ( V_3 , V_30 ) ;
memcpy ( V_63 , & V_101 , V_30 ) ;
F_59 ( V_3 ) ;
V_3 -> V_104 = V_3 -> V_105 + V_106 ;
V_3 -> V_61 = V_101 . type ;
V_3 -> V_107 = V_108 ;
V_3 -> V_34 = V_21 -> V_34 ;
if ( V_9 -> V_91 ) {
struct V_109 * V_110 ;
V_110 = F_60 ( V_9 ,
V_9 -> V_73 . V_111 ) ;
V_9 -> V_73 . V_111 = V_110 ;
if ( ! V_110 ) {
F_61 ( V_3 ) ;
continue;
}
V_3 = F_42 ( V_3 , V_110 -> V_87 ) ;
if ( ! V_3 ) {
F_14 ( L_6 ,
V_9 -> V_34 -> V_35 ) ;
continue;
}
}
F_62 ( V_3 ) ;
}
}
static int F_63 ( struct V_21 * V_21 , T_1 V_71 [] , int V_112 )
{
struct V_113 * V_34 = V_21 -> V_34 ;
struct V_114 V_115 ;
if ( ! V_112 ) {
memcpy ( V_34 -> V_83 , V_71 , V_34 -> V_116 ) ;
return 0 ;
}
memcpy ( V_115 . V_117 , V_71 , V_34 -> V_116 ) ;
V_115 . V_118 = V_34 -> type ;
if ( F_64 ( V_34 , & V_115 ) ) {
F_14 ( L_11
L_12 ,
V_34 -> V_85 -> V_35 , V_34 -> V_35 ) ;
return - V_119 ;
}
return 0 ;
}
static void F_65 ( struct V_8 * V_9 , struct V_21 * V_120 , struct V_21 * V_121 )
{
T_1 V_122 [ V_58 ] ;
memcpy ( V_122 , V_120 -> V_34 -> V_83 , V_58 ) ;
F_63 ( V_120 , V_121 -> V_34 -> V_83 , V_9 -> V_73 . V_123 ) ;
F_63 ( V_121 , V_122 , V_9 -> V_73 . V_123 ) ;
}
static void F_66 ( struct V_8 * V_9 , struct V_21 * V_120 ,
struct V_21 * V_121 )
{
int V_124 = ( F_20 ( V_120 ) != F_20 ( V_121 ) ) ;
struct V_21 * V_125 = NULL ;
F_67 () ;
if ( F_20 ( V_120 ) ) {
F_36 ( V_120 , V_120 -> V_34 -> V_83 ) ;
if ( V_9 -> V_73 . V_123 ) {
F_45 ( V_9 , V_120 ) ;
}
} else {
V_125 = V_120 ;
}
if ( F_20 ( V_121 ) ) {
F_36 ( V_121 , V_121 -> V_34 -> V_83 ) ;
if ( V_9 -> V_73 . V_123 ) {
F_45 ( V_9 , V_121 ) ;
}
} else {
V_125 = V_121 ;
}
if ( V_9 -> V_73 . V_123 && V_124 ) {
F_34 ( V_9 ,
V_125 -> V_34 -> V_83 ) ;
}
}
static void F_68 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
int V_126 ;
int V_127 ;
V_126 = F_25 ( V_21 -> V_128 ,
V_21 -> V_34 -> V_83 ) ;
V_127 = F_25 ( V_21 -> V_128 ,
V_9 -> V_34 -> V_83 ) ;
if ( V_126 && V_127 ) {
struct V_21 * V_129 ;
int V_6 , V_130 = 0 ;
F_19 (bond, tmp_slave, i) {
if ( ! F_25 ( V_21 -> V_128 ,
V_129 -> V_34 -> V_83 ) ) {
V_130 = 1 ;
break;
}
}
if ( V_130 ) {
F_65 ( V_9 , V_21 , V_129 ) ;
F_66 ( V_9 , V_21 , V_129 ) ;
}
}
}
static int F_69 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
struct V_21 * V_131 , * V_132 , * V_133 ;
struct V_21 * V_134 = V_9 -> V_72 ;
int V_6 , V_135 , V_130 = 0 ;
if ( V_9 -> V_136 == 0 ) {
return 0 ;
}
if ( F_25 ( V_21 -> V_128 , V_9 -> V_34 -> V_83 ) ) {
F_19 (bond, tmp_slave1, i) {
if ( ! F_25 ( V_131 -> V_34 -> V_83 ,
V_21 -> V_34 -> V_83 ) ) {
V_130 = 1 ;
break;
}
}
if ( ! V_130 )
return 0 ;
F_63 ( V_21 , V_9 -> V_34 -> V_83 ,
V_9 -> V_73 . V_123 ) ;
}
V_133 = NULL ;
F_19 (bond, tmp_slave1, i) {
V_130 = 0 ;
F_19 (bond, tmp_slave2, j) {
if ( ! F_25 ( V_131 -> V_128 ,
V_132 -> V_34 -> V_83 ) ) {
V_130 = 1 ;
break;
}
}
if ( ! V_130 ) {
V_133 = V_131 ;
break;
}
if ( ! V_134 ) {
if ( ! F_25 ( V_131 -> V_34 -> V_83 ,
V_9 -> V_34 -> V_83 ) ) {
V_134 = V_131 ;
}
}
}
if ( V_133 ) {
F_63 ( V_21 , V_133 -> V_128 ,
V_9 -> V_73 . V_123 ) ;
F_70 ( L_13 ,
V_9 -> V_34 -> V_35 , V_21 -> V_34 -> V_35 ,
V_133 -> V_34 -> V_35 ) ;
} else if ( V_134 ) {
F_14 ( L_14 ,
V_9 -> V_34 -> V_35 , V_21 -> V_34 -> V_35 ) ;
return - V_137 ;
}
return 0 ;
}
static int F_71 ( struct V_8 * V_9 , void * V_71 )
{
struct V_114 V_138 ;
struct V_21 * V_21 , * V_139 ;
char V_140 [ V_58 ] ;
int V_141 ;
int V_6 ;
if ( V_9 -> V_73 . V_123 ) {
return 0 ;
}
F_19 (bond, slave, i) {
memcpy ( V_140 , V_21 -> V_34 -> V_83 , V_58 ) ;
V_141 = F_64 ( V_21 -> V_34 , V_71 ) ;
memcpy ( V_21 -> V_34 -> V_83 , V_140 , V_58 ) ;
if ( V_141 )
goto V_142;
}
return 0 ;
V_142:
memcpy ( V_138 . V_117 , V_9 -> V_34 -> V_83 , V_9 -> V_34 -> V_116 ) ;
V_138 . V_118 = V_9 -> V_34 -> type ;
V_139 = V_21 ;
F_72 (bond, slave, i, bond->first_slave, stop_at) {
memcpy ( V_140 , V_21 -> V_34 -> V_83 , V_58 ) ;
F_64 ( V_21 -> V_34 , & V_138 ) ;
memcpy ( V_21 -> V_34 -> V_83 , V_140 , V_58 ) ;
}
return V_141 ;
}
int F_73 ( struct V_8 * V_9 , int V_123 )
{
int V_141 ;
V_141 = F_12 ( V_9 ) ;
if ( V_141 ) {
return V_141 ;
}
if ( V_123 ) {
V_9 -> V_73 . V_123 = 1 ;
V_141 = F_52 ( V_9 ) ;
if ( V_141 ) {
F_15 ( V_9 ) ;
return V_141 ;
}
} else {
V_9 -> V_73 . V_123 = 0 ;
}
return 0 ;
}
void F_74 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
F_15 ( V_9 ) ;
if ( V_29 -> V_123 ) {
F_54 ( V_9 ) ;
}
}
int F_75 ( struct V_2 * V_3 , struct V_113 * V_143 )
{
struct V_8 * V_9 = F_76 ( V_143 ) ;
struct V_144 * V_145 ;
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_21 * V_17 = NULL ;
static const T_3 V_146 = F_77 ( 0xffffffff ) ;
int V_5 = 0 ;
int V_147 = 1 ;
T_2 V_42 = 0 ;
const T_1 * V_4 = NULL ;
int V_141 = 1 ;
struct V_148 * V_149 ;
F_59 ( V_3 ) ;
V_145 = F_78 ( V_3 ) ;
F_79 ( & V_9 -> V_82 ) ;
switch ( F_80 ( V_3 -> V_61 ) ) {
case V_150 : {
const struct V_151 * V_152 = F_81 ( V_3 ) ;
if ( ! F_25 ( V_145 -> V_153 , V_79 ) ||
( V_152 -> V_154 == V_146 ) ||
( V_152 -> V_61 == V_155 ) ) {
V_147 = 0 ;
break;
}
V_4 = ( char * ) & ( V_152 -> V_154 ) ;
V_5 = sizeof( V_152 -> V_154 ) ;
}
break;
case V_156 :
if ( ! F_25 ( V_145 -> V_153 , V_79 ) ) {
V_147 = 0 ;
break;
}
if ( ! F_25 ( V_145 -> V_153 , V_157 ) ) {
V_147 = 0 ;
break;
}
V_149 = F_82 ( V_3 ) ;
if ( F_83 ( & V_149 -> V_158 ) ) {
V_147 = 0 ;
break;
}
V_4 = ( char * ) & ( F_82 ( V_3 ) -> V_154 ) ;
V_5 = sizeof( F_82 ( V_3 ) -> V_154 ) ;
break;
case V_159 :
if ( F_84 ( V_3 ) -> V_160 != V_161 ) {
V_147 = 0 ;
break;
}
if ( F_84 ( V_3 ) -> V_162 != V_163 ) {
V_147 = 0 ;
break;
}
V_4 = ( char * ) V_145 -> V_153 ;
V_5 = V_58 ;
break;
case V_62 :
V_147 = 0 ;
if ( V_29 -> V_123 ) {
V_17 = F_49 ( V_3 , V_9 ) ;
}
break;
default:
V_147 = 0 ;
break;
}
if ( V_147 ) {
V_42 = F_2 ( V_4 , V_5 ) ;
V_17 = F_21 ( V_9 , V_42 , V_3 -> V_64 ) ;
}
if ( ! V_17 ) {
V_17 = V_9 -> V_72 ;
V_29 -> V_164 += V_3 -> V_64 ;
}
if ( V_17 && F_20 ( V_17 ) ) {
if ( V_17 != V_9 -> V_72 ) {
memcpy ( V_145 -> V_165 ,
V_17 -> V_34 -> V_83 ,
V_58 ) ;
}
V_141 = F_85 ( V_9 , V_3 , V_17 -> V_34 ) ;
} else {
if ( V_17 ) {
F_11 ( V_9 , V_17 , 0 ) ;
}
}
if ( V_141 ) {
F_86 ( V_3 ) ;
}
F_87 ( & V_9 -> V_82 ) ;
return V_166 ;
}
void F_88 ( struct V_167 * V_168 )
{
struct V_8 * V_9 = F_89 ( V_168 , struct V_8 ,
V_169 . V_168 ) ;
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_21 * V_21 ;
int V_6 ;
F_79 ( & V_9 -> V_170 ) ;
if ( V_9 -> V_171 ) {
goto V_172;
}
if ( V_9 -> V_136 == 0 ) {
V_29 -> V_173 = 0 ;
V_29 -> V_174 = 0 ;
goto V_175;
}
V_29 -> V_173 ++ ;
V_29 -> V_174 ++ ;
if ( V_29 -> V_174 >= V_176 ) {
F_79 ( & V_9 -> V_82 ) ;
F_19 (bond, slave, i) {
F_36 ( V_21 , V_21 -> V_34 -> V_83 ) ;
}
F_87 ( & V_9 -> V_82 ) ;
V_29 -> V_174 = 0 ;
}
if ( V_29 -> V_173 >= V_177 ) {
F_79 ( & V_9 -> V_82 ) ;
F_19 (bond, slave, i) {
F_11 ( V_9 , V_21 , 1 ) ;
if ( V_21 == V_9 -> V_72 ) {
F_10 ( V_21 ) . V_22 =
V_29 -> V_164 /
V_16 ;
V_29 -> V_164 = 0 ;
}
}
F_87 ( & V_9 -> V_82 ) ;
V_29 -> V_173 = 0 ;
}
if ( V_29 -> V_123 ) {
if ( V_29 -> V_74 &&
( ++ V_29 -> V_75 >= V_178 ) ) {
F_87 ( & V_9 -> V_170 ) ;
F_90 () ;
V_29 -> V_75 = 0 ;
F_35 ( V_9 -> V_72 -> V_34 , - 1 ) ;
V_29 -> V_74 = 0 ;
F_91 () ;
F_79 ( & V_9 -> V_170 ) ;
}
if ( V_29 -> F_50 ) {
V_29 -> F_50 = 0 ;
F_50 ( V_9 ) ;
}
if ( V_29 -> V_60 ) {
if ( V_29 -> V_88 ) {
-- V_29 -> V_88 ;
} else {
F_44 ( V_9 ) ;
if ( V_29 -> V_80 ) {
-- V_29 -> V_80 ;
} else {
V_29 -> V_60 = 0 ;
}
}
}
}
V_175:
F_92 ( V_9 -> V_179 , & V_9 -> V_169 , V_180 ) ;
V_172:
F_87 ( & V_9 -> V_170 ) ;
}
int F_93 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
int V_141 ;
V_141 = F_63 ( V_21 , V_21 -> V_128 ,
V_9 -> V_73 . V_123 ) ;
if ( V_141 ) {
return V_141 ;
}
F_79 ( & V_9 -> V_170 ) ;
V_141 = F_69 ( V_9 , V_21 ) ;
F_87 ( & V_9 -> V_170 ) ;
if ( V_141 ) {
return V_141 ;
}
F_9 ( V_21 ) ;
V_9 -> V_73 . V_173 = V_177 ;
if ( V_9 -> V_73 . V_123 ) {
V_9 -> V_73 . F_50 = 1 ;
}
return 0 ;
}
void F_94 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
if ( V_9 -> V_136 > 1 ) {
F_68 ( V_9 , V_21 ) ;
}
F_11 ( V_9 , V_21 , 0 ) ;
if ( V_9 -> V_73 . V_123 ) {
V_9 -> V_73 . V_69 = NULL ;
F_37 ( V_9 , V_21 ) ;
}
}
void F_95 ( struct V_8 * V_9 , struct V_21 * V_21 , char V_181 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
if ( V_181 == V_182 ) {
F_11 ( V_9 , V_21 , 0 ) ;
if ( V_9 -> V_73 . V_123 ) {
F_37 ( V_9 , V_21 ) ;
}
} else if ( V_181 == V_183 ) {
V_29 -> V_173 = V_177 ;
if ( V_9 -> V_73 . V_123 ) {
V_9 -> V_73 . F_50 = 1 ;
}
}
}
void F_96 ( struct V_8 * V_9 , struct V_21 * V_184 )
__releases( &bond->curr_slave_lock
int F_97 ( struct V_113 * V_143 , void * V_71 )
__acquires( &bond->lock
void F_98 ( struct V_8 * V_9 , unsigned short V_87 )
{
if ( V_9 -> V_73 . V_111 &&
( V_9 -> V_73 . V_111 -> V_87 == V_87 ) ) {
V_9 -> V_73 . V_111 = NULL ;
}
if ( V_9 -> V_73 . V_123 ) {
F_55 ( V_9 , V_87 ) ;
}
}
