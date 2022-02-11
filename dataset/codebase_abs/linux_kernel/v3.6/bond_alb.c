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
if ( V_47 -> V_63 == F_36 ( V_64 ) ) {
F_31 ( V_9 , V_47 ) ;
F_37 ( L_1 ) ;
}
V_62:
return V_65 ;
}
static struct V_21 * F_38 ( struct V_8 * V_9 )
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
F_39 (bond, slave, i, start_at) {
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
static void F_40 ( struct V_8 * V_9 , T_1 V_70 [] )
{
if ( ! V_9 -> V_71 ) {
return;
}
if ( ! V_9 -> V_72 . V_73 ) {
if ( ! F_41 ( V_9 -> V_71 -> V_74 , 1 ) )
V_9 -> V_72 . V_73 = 1 ;
else
V_9 -> V_72 . V_73 = 0 ;
}
V_9 -> V_72 . V_75 = 0 ;
F_42 ( V_9 -> V_71 , V_70 ) ;
}
static void F_43 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_48 * V_76 ;
T_2 V_25 , V_27 ;
F_27 ( V_9 ) ;
V_76 = V_29 -> V_51 ;
V_25 = V_29 -> V_77 ;
for (; V_25 != V_78 ; V_25 = V_27 ) {
V_27 = V_76 [ V_25 ] . V_18 ;
if ( V_76 [ V_25 ] . V_21 == V_21 ) {
struct V_21 * V_43 = F_38 ( V_9 ) ;
if ( V_43 ) {
V_76 [ V_25 ] . V_21 = V_43 ;
if ( ! F_32 ( V_76 [ V_25 ] . V_54 ,
V_79 ) ) {
V_29 -> V_51 [ V_25 ] . V_57 = 1 ;
V_29 -> V_58 = 1 ;
V_29 -> V_80 =
V_81 ;
}
} else {
V_76 [ V_25 ] . V_21 = NULL ;
}
}
}
F_28 ( V_9 ) ;
F_44 ( & V_9 -> V_82 ) ;
if ( V_21 != V_9 -> V_71 ) {
F_40 ( V_9 , V_21 -> V_74 -> V_83 ) ;
}
F_45 ( & V_9 -> V_82 ) ;
}
static void F_46 ( struct V_48 * V_49 )
{
int V_6 ;
if ( ! V_49 -> V_21 ) {
return;
}
for ( V_6 = 0 ; V_6 < V_84 ; V_6 ++ ) {
struct V_2 * V_3 ;
V_3 = F_47 ( V_64 , V_61 ,
V_49 -> V_53 ,
V_49 -> V_21 -> V_74 ,
V_49 -> V_50 ,
V_49 -> V_54 ,
V_49 -> V_21 -> V_74 -> V_83 ,
V_49 -> V_54 ) ;
if ( ! V_3 ) {
F_48 ( L_2 ,
V_49 -> V_21 -> V_74 -> V_85 -> V_86 ) ;
continue;
}
V_3 -> V_74 = V_49 -> V_21 -> V_74 ;
if ( V_49 -> V_87 ) {
V_3 = F_49 ( V_3 , V_49 -> V_88 ) ;
if ( ! V_3 ) {
F_48 ( L_3 ,
V_49 -> V_21 -> V_74 -> V_85 -> V_86 ) ;
continue;
}
}
F_50 ( V_3 ) ;
}
}
static void F_51 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_48 * V_49 ;
T_2 V_40 ;
F_27 ( V_9 ) ;
V_40 = V_29 -> V_77 ;
for (; V_40 != V_78 ; V_40 = V_49 -> V_18 ) {
V_49 = & ( V_29 -> V_51 [ V_40 ] ) ;
if ( V_49 -> V_57 ) {
F_46 ( V_49 ) ;
if ( V_29 -> V_80 == 0 ) {
V_49 -> V_57 = 0 ;
}
}
}
V_29 -> V_89 = V_90 ;
F_28 ( V_9 ) ;
}
static void F_52 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_48 * V_49 ;
int V_57 = 0 ;
T_2 V_40 ;
F_27 ( V_9 ) ;
V_40 = V_29 -> V_77 ;
for (; V_40 != V_78 ; V_40 = V_49 -> V_18 ) {
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
static void F_53 ( struct V_8 * V_9 , T_3 V_91 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_48 * V_49 ;
T_2 V_40 ;
F_29 ( V_9 ) ;
V_40 = V_29 -> V_77 ;
for (; V_40 != V_78 ; V_40 = V_49 -> V_18 ) {
V_49 = & ( V_29 -> V_51 [ V_40 ] ) ;
if ( ! V_49 -> V_21 ) {
F_48 ( L_4 ,
V_9 -> V_74 -> V_86 ) ;
continue;
}
if ( ( V_49 -> V_50 == V_91 ) &&
! F_32 ( V_49 -> V_21 -> V_74 -> V_83 ,
V_9 -> V_74 -> V_83 ) &&
! F_32 ( V_49 -> V_54 , V_79 ) ) {
V_49 -> V_57 = 1 ;
V_29 -> V_58 = 1 ;
}
}
F_30 ( V_9 ) ;
}
static struct V_21 * F_54 ( struct V_2 * V_3 , struct V_8 * V_9 )
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
V_43 = V_49 -> V_21 ;
if ( V_43 ) {
F_30 ( V_9 ) ;
return V_43 ;
}
} else {
if ( V_9 -> V_71 &&
V_49 -> V_21 != V_9 -> V_71 ) {
V_49 -> V_21 = V_9 -> V_71 ;
F_46 ( V_49 ) ;
}
}
}
V_43 = F_38 ( V_9 ) ;
if ( V_43 ) {
V_49 -> V_50 = V_47 -> V_50 ;
V_49 -> V_53 = V_47 -> V_53 ;
memcpy ( V_49 -> V_54 , V_47 -> V_54 , V_56 ) ;
V_49 -> V_21 = V_43 ;
if ( ! F_32 ( V_49 -> V_54 , V_79 ) ) {
V_49 -> V_57 = 1 ;
V_9 -> V_72 . V_58 = 1 ;
} else {
V_49 -> V_57 = 0 ;
}
if ( F_55 ( V_9 ) ) {
if ( ! F_56 ( V_3 , & V_49 -> V_88 ) )
V_49 -> V_87 = 1 ;
}
if ( ! V_49 -> V_52 ) {
T_2 V_92 = V_29 -> V_77 ;
V_29 -> V_77 = V_40 ;
V_49 -> V_18 = V_92 ;
if ( V_92 != V_78 ) {
V_29 -> V_51 [ V_92 ] . V_20 =
V_40 ;
}
V_49 -> V_52 = 1 ;
}
}
F_30 ( V_9 ) ;
return V_43 ;
}
static struct V_21 * F_57 ( struct V_2 * V_3 , struct V_8 * V_9 )
{
struct V_1 * V_47 = V_1 ( V_3 ) ;
struct V_21 * V_17 = NULL ;
if ( V_47 -> V_63 == F_36 ( V_64 ) ) {
V_17 = F_54 ( V_3 , V_9 ) ;
if ( V_17 ) {
memcpy ( V_47 -> V_55 , V_17 -> V_74 -> V_83 , V_56 ) ;
}
F_37 ( L_5 ) ;
} else if ( V_47 -> V_63 == F_36 ( V_93 ) ) {
F_54 ( V_3 , V_9 ) ;
V_9 -> V_72 . V_89 = V_90 ;
F_53 ( V_9 , V_47 -> V_50 ) ;
F_37 ( L_6 ) ;
}
return V_17 ;
}
static void F_58 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_21 * V_43 ;
struct V_48 * V_49 ;
int V_57 ;
T_2 V_40 ;
F_27 ( V_9 ) ;
V_57 = 0 ;
V_40 = V_29 -> V_77 ;
for (; V_40 != V_78 ; V_40 = V_49 -> V_18 ) {
V_49 = & ( V_29 -> V_51 [ V_40 ] ) ;
V_43 = F_38 ( V_9 ) ;
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
static void F_59 ( struct V_48 * V_12 )
{
memset ( V_12 , 0 , sizeof( struct V_48 ) ) ;
V_12 -> V_18 = V_78 ;
V_12 -> V_20 = V_78 ;
}
static int F_60 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_48 * V_32 ;
int V_30 = V_94 * sizeof( struct V_48 ) ;
int V_6 ;
V_32 = F_61 ( V_30 , V_33 ) ;
if ( ! V_32 )
return - 1 ;
F_27 ( V_9 ) ;
V_29 -> V_51 = V_32 ;
V_29 -> V_77 = V_78 ;
for ( V_6 = 0 ; V_6 < V_94 ; V_6 ++ ) {
F_59 ( V_29 -> V_51 + V_6 ) ;
}
F_28 ( V_9 ) ;
V_9 -> V_95 = F_33 ;
return 0 ;
}
static void F_62 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
F_27 ( V_9 ) ;
F_20 ( V_29 -> V_51 ) ;
V_29 -> V_51 = NULL ;
V_29 -> V_77 = V_78 ;
F_28 ( V_9 ) ;
}
static void F_63 ( struct V_8 * V_9 , unsigned short V_88 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
T_2 V_96 ;
F_27 ( V_9 ) ;
V_96 = V_29 -> V_77 ;
while ( V_96 != V_78 ) {
struct V_48 * V_97 = & ( V_29 -> V_51 [ V_96 ] ) ;
T_2 V_27 = V_29 -> V_51 [ V_96 ] . V_18 ;
T_2 V_98 = V_29 -> V_51 [ V_96 ] . V_20 ;
if ( V_97 -> V_87 && ( V_97 -> V_88 == V_88 ) ) {
if ( V_96 == V_29 -> V_77 ) {
V_29 -> V_77 = V_27 ;
}
if ( V_98 != V_78 ) {
V_29 -> V_51 [ V_98 ] . V_18 = V_27 ;
}
if ( V_27 != V_78 ) {
V_29 -> V_51 [ V_27 ] . V_20 = V_98 ;
}
F_59 ( V_97 ) ;
}
V_96 = V_27 ;
}
F_28 ( V_9 ) ;
}
static void F_42 ( struct V_21 * V_21 , T_1 V_99 [] )
{
struct V_8 * V_9 = F_64 ( V_21 ) ;
struct V_100 V_101 ;
int V_30 = sizeof( struct V_100 ) ;
int V_6 ;
memset ( & V_101 , 0 , V_30 ) ;
memcpy ( V_101 . V_54 , V_99 , V_56 ) ;
memcpy ( V_101 . V_55 , V_99 , V_56 ) ;
V_101 . type = F_34 ( V_102 ) ;
for ( V_6 = 0 ; V_6 < V_103 ; V_6 ++ ) {
struct V_2 * V_3 ;
char * V_104 ;
V_3 = F_65 ( V_30 ) ;
if ( ! V_3 ) {
return;
}
V_104 = F_66 ( V_3 , V_30 ) ;
memcpy ( V_104 , & V_101 , V_30 ) ;
F_67 ( V_3 ) ;
V_3 -> V_105 = V_3 -> V_106 + V_107 ;
V_3 -> V_60 = V_101 . type ;
V_3 -> V_108 = V_109 ;
V_3 -> V_74 = V_21 -> V_74 ;
if ( F_55 ( V_9 ) ) {
struct V_110 * V_111 ;
V_111 = F_68 ( V_9 ,
V_9 -> V_72 . V_112 ) ;
V_9 -> V_72 . V_112 = V_111 ;
if ( ! V_111 ) {
F_69 ( V_3 ) ;
continue;
}
V_3 = F_49 ( V_3 , V_111 -> V_88 ) ;
if ( ! V_3 ) {
F_48 ( L_3 ,
V_9 -> V_74 -> V_86 ) ;
continue;
}
}
F_70 ( V_3 ) ;
}
}
static int F_71 ( struct V_21 * V_21 , T_1 V_70 [] )
{
struct V_113 * V_74 = V_21 -> V_74 ;
struct V_114 V_115 ;
if ( V_21 -> V_9 -> V_116 . V_117 == V_118 ) {
memcpy ( V_74 -> V_83 , V_70 , V_74 -> V_119 ) ;
return 0 ;
}
memcpy ( V_115 . V_120 , V_70 , V_74 -> V_119 ) ;
V_115 . V_121 = V_74 -> type ;
if ( F_72 ( V_74 , & V_115 ) ) {
F_48 ( L_7
L_8 ,
V_74 -> V_85 -> V_86 , V_74 -> V_86 ) ;
return - V_122 ;
}
return 0 ;
}
static void F_73 ( struct V_8 * V_9 , struct V_21 * V_123 , struct V_21 * V_124 )
{
T_1 V_125 [ V_56 ] ;
memcpy ( V_125 , V_123 -> V_74 -> V_83 , V_56 ) ;
F_71 ( V_123 , V_124 -> V_74 -> V_83 ) ;
F_71 ( V_124 , V_125 ) ;
}
static void F_74 ( struct V_8 * V_9 , struct V_21 * V_123 ,
struct V_21 * V_124 )
{
int V_126 = ( F_24 ( V_123 ) != F_24 ( V_124 ) ) ;
struct V_21 * V_127 = NULL ;
F_75 () ;
if ( F_24 ( V_123 ) ) {
F_42 ( V_123 , V_123 -> V_74 -> V_83 ) ;
if ( V_9 -> V_72 . V_128 ) {
F_52 ( V_9 , V_123 ) ;
}
} else {
V_127 = V_123 ;
}
if ( F_24 ( V_124 ) ) {
F_42 ( V_124 , V_124 -> V_74 -> V_83 ) ;
if ( V_9 -> V_72 . V_128 ) {
F_52 ( V_9 , V_124 ) ;
}
} else {
V_127 = V_124 ;
}
if ( V_9 -> V_72 . V_128 && V_126 ) {
F_40 ( V_9 ,
V_127 -> V_74 -> V_83 ) ;
}
}
static void F_76 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
int V_129 ;
int V_130 ;
V_129 = ! F_32 ( V_21 -> V_131 ,
V_21 -> V_74 -> V_83 ) ;
V_130 = ! F_32 ( V_21 -> V_131 ,
V_9 -> V_74 -> V_83 ) ;
if ( V_129 && V_130 ) {
struct V_21 * V_132 ;
int V_6 , V_133 = 0 ;
F_23 (bond, tmp_slave, i) {
if ( F_32 ( V_21 -> V_131 ,
V_132 -> V_74 -> V_83 ) ) {
V_133 = 1 ;
break;
}
}
if ( V_133 ) {
F_73 ( V_9 , V_21 , V_132 ) ;
F_74 ( V_9 , V_21 , V_132 ) ;
}
}
}
static int F_77 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
struct V_21 * V_134 , * V_135 , * V_136 ;
struct V_21 * V_137 = V_9 -> V_71 ;
int V_6 , V_138 , V_133 = 0 ;
if ( V_9 -> V_139 == 0 ) {
return 0 ;
}
if ( ! F_32 ( V_21 -> V_131 , V_9 -> V_74 -> V_83 ) ) {
F_23 (bond, tmp_slave1, i) {
if ( F_32 ( V_134 -> V_74 -> V_83 ,
V_21 -> V_74 -> V_83 ) ) {
V_133 = 1 ;
break;
}
}
if ( ! V_133 )
return 0 ;
F_71 ( V_21 , V_9 -> V_74 -> V_83 ) ;
}
V_136 = NULL ;
F_23 (bond, tmp_slave1, i) {
V_133 = 0 ;
F_23 (bond, tmp_slave2, j) {
if ( F_32 ( V_134 -> V_131 ,
V_135 -> V_74 -> V_83 ) ) {
V_133 = 1 ;
break;
}
}
if ( ! V_133 ) {
V_136 = V_134 ;
break;
}
if ( ! V_137 ) {
if ( F_32 ( V_134 -> V_74 -> V_83 ,
V_9 -> V_74 -> V_83 ) ) {
V_137 = V_134 ;
}
}
}
if ( V_136 ) {
F_71 ( V_21 , V_136 -> V_131 ) ;
F_78 ( L_9 ,
V_9 -> V_74 -> V_86 , V_21 -> V_74 -> V_86 ,
V_136 -> V_74 -> V_86 ) ;
} else if ( V_137 ) {
F_48 ( L_10 ,
V_9 -> V_74 -> V_86 , V_21 -> V_74 -> V_86 ) ;
return - V_140 ;
}
return 0 ;
}
static int F_79 ( struct V_8 * V_9 , void * V_70 )
{
struct V_114 V_141 ;
struct V_21 * V_21 , * V_142 ;
char V_143 [ V_56 ] ;
int V_144 ;
int V_6 ;
if ( V_9 -> V_72 . V_128 ) {
return 0 ;
}
F_23 (bond, slave, i) {
memcpy ( V_143 , V_21 -> V_74 -> V_83 , V_56 ) ;
V_144 = F_72 ( V_21 -> V_74 , V_70 ) ;
memcpy ( V_21 -> V_74 -> V_83 , V_143 , V_56 ) ;
if ( V_144 )
goto V_145;
}
return 0 ;
V_145:
memcpy ( V_141 . V_120 , V_9 -> V_74 -> V_83 , V_9 -> V_74 -> V_119 ) ;
V_141 . V_121 = V_9 -> V_74 -> type ;
V_142 = V_21 ;
F_80 (bond, slave, i, bond->first_slave, stop_at) {
memcpy ( V_143 , V_21 -> V_74 -> V_83 , V_56 ) ;
F_72 ( V_21 -> V_74 , & V_141 ) ;
memcpy ( V_21 -> V_74 -> V_83 , V_143 , V_56 ) ;
}
return V_144 ;
}
int F_81 ( struct V_8 * V_9 , int V_128 )
{
int V_144 ;
V_144 = F_17 ( V_9 ) ;
if ( V_144 ) {
return V_144 ;
}
if ( V_128 ) {
V_9 -> V_72 . V_128 = 1 ;
V_144 = F_60 ( V_9 ) ;
if ( V_144 ) {
F_19 ( V_9 ) ;
return V_144 ;
}
} else {
V_9 -> V_72 . V_128 = 0 ;
}
return 0 ;
}
void F_82 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
F_19 ( V_9 ) ;
if ( V_29 -> V_128 ) {
F_62 ( V_9 ) ;
}
}
int F_83 ( struct V_2 * V_3 , struct V_113 * V_146 )
{
struct V_8 * V_9 = F_84 ( V_146 ) ;
struct V_147 * V_148 ;
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_21 * V_17 = NULL ;
static const T_3 V_149 = F_85 ( 0xffffffff ) ;
int V_5 = 0 ;
int V_150 = 1 ;
T_2 V_40 = 0 ;
const T_1 * V_4 = NULL ;
int V_144 = 1 ;
struct V_151 * V_152 ;
F_67 ( V_3 ) ;
V_148 = F_86 ( V_3 ) ;
F_87 ( & V_9 -> V_82 ) ;
switch ( F_88 ( V_3 -> V_60 ) ) {
case V_153 : {
const struct V_154 * V_155 = F_89 ( V_3 ) ;
if ( F_32 ( V_148 -> V_156 , V_79 ) ||
( V_155 -> V_157 == V_149 ) ||
( V_155 -> V_60 == V_158 ) ) {
V_150 = 0 ;
break;
}
V_4 = ( char * ) & ( V_155 -> V_157 ) ;
V_5 = sizeof( V_155 -> V_157 ) ;
}
break;
case V_159 :
if ( F_32 ( V_148 -> V_156 , V_79 ) ) {
V_150 = 0 ;
break;
}
if ( F_32 ( V_148 -> V_156 , V_160 ) ) {
V_150 = 0 ;
break;
}
V_152 = F_90 ( V_3 ) ;
if ( F_91 ( & V_152 -> V_161 ) ) {
V_150 = 0 ;
break;
}
V_4 = ( char * ) & ( F_90 ( V_3 ) -> V_157 ) ;
V_5 = sizeof( F_90 ( V_3 ) -> V_157 ) ;
break;
case V_162 :
if ( F_92 ( V_3 ) -> V_163 != V_164 ) {
V_150 = 0 ;
break;
}
if ( F_92 ( V_3 ) -> V_165 != V_166 ) {
V_150 = 0 ;
break;
}
V_4 = ( char * ) V_148 -> V_156 ;
V_5 = V_56 ;
break;
case V_61 :
V_150 = 0 ;
if ( V_29 -> V_128 ) {
V_17 = F_57 ( V_3 , V_9 ) ;
}
break;
default:
V_150 = 0 ;
break;
}
if ( V_150 ) {
V_40 = F_2 ( V_4 , V_5 ) ;
V_17 = F_26 ( V_9 , V_40 , V_3 -> V_167 ) ;
}
if ( ! V_17 ) {
V_17 = V_9 -> V_71 ;
V_29 -> V_168 += V_3 -> V_167 ;
}
if ( V_17 && F_24 ( V_17 ) ) {
if ( V_17 != V_9 -> V_71 ) {
memcpy ( V_148 -> V_169 ,
V_17 -> V_74 -> V_83 ,
V_56 ) ;
}
V_144 = F_93 ( V_9 , V_3 , V_17 -> V_74 ) ;
} else {
if ( V_17 ) {
F_8 ( V_9 ) ;
F_15 ( V_9 , V_17 , 0 ) ;
F_10 ( V_9 ) ;
}
}
F_94 ( & V_9 -> V_82 ) ;
if ( V_144 ) {
F_69 ( V_3 ) ;
}
return V_170 ;
}
void F_95 ( struct V_171 * V_172 )
{
struct V_8 * V_9 = F_96 ( V_172 , struct V_8 ,
V_173 . V_172 ) ;
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_21 * V_21 ;
int V_6 ;
F_87 ( & V_9 -> V_174 ) ;
if ( V_9 -> V_139 == 0 ) {
V_29 -> V_175 = 0 ;
V_29 -> V_176 = 0 ;
goto V_177;
}
V_29 -> V_175 ++ ;
V_29 -> V_176 ++ ;
if ( V_29 -> V_176 >= V_178 ) {
F_87 ( & V_9 -> V_82 ) ;
F_23 (bond, slave, i) {
F_42 ( V_21 , V_21 -> V_74 -> V_83 ) ;
}
F_94 ( & V_9 -> V_82 ) ;
V_29 -> V_176 = 0 ;
}
if ( V_29 -> V_175 >= V_179 ) {
F_87 ( & V_9 -> V_82 ) ;
F_23 (bond, slave, i) {
F_16 ( V_9 , V_21 , 1 ) ;
if ( V_21 == V_9 -> V_71 ) {
F_14 ( V_21 ) . V_22 =
V_29 -> V_168 /
V_16 ;
V_29 -> V_168 = 0 ;
}
}
F_94 ( & V_9 -> V_82 ) ;
V_29 -> V_175 = 0 ;
}
if ( V_29 -> V_128 ) {
if ( V_29 -> V_73 &&
( ++ V_29 -> V_75 >= V_180 ) ) {
F_94 ( & V_9 -> V_174 ) ;
if ( ! F_97 () ) {
F_87 ( & V_9 -> V_174 ) ;
goto V_177;
}
V_29 -> V_75 = 0 ;
F_41 ( V_9 -> V_71 -> V_74 , - 1 ) ;
V_29 -> V_73 = 0 ;
F_98 () ;
F_87 ( & V_9 -> V_174 ) ;
}
if ( V_29 -> F_58 ) {
V_29 -> F_58 = 0 ;
F_58 ( V_9 ) ;
}
if ( V_29 -> V_58 ) {
if ( V_29 -> V_89 ) {
-- V_29 -> V_89 ;
} else {
F_51 ( V_9 ) ;
if ( V_29 -> V_80 ) {
-- V_29 -> V_80 ;
} else {
V_29 -> V_58 = 0 ;
}
}
}
}
V_177:
F_99 ( V_9 -> V_181 , & V_9 -> V_173 , V_182 ) ;
F_94 ( & V_9 -> V_174 ) ;
}
int F_100 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
int V_144 ;
V_144 = F_71 ( V_21 , V_21 -> V_131 ) ;
if ( V_144 ) {
return V_144 ;
}
F_87 ( & V_9 -> V_174 ) ;
V_144 = F_77 ( V_9 , V_21 ) ;
F_94 ( & V_9 -> V_174 ) ;
if ( V_144 ) {
return V_144 ;
}
F_13 ( V_21 ) ;
V_9 -> V_72 . V_175 = V_179 ;
if ( V_9 -> V_72 . V_128 ) {
V_9 -> V_72 . F_58 = 1 ;
}
return 0 ;
}
void F_101 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
if ( V_9 -> V_139 > 1 ) {
F_76 ( V_9 , V_21 ) ;
}
F_16 ( V_9 , V_21 , 0 ) ;
if ( V_9 -> V_72 . V_128 ) {
V_9 -> V_72 . V_68 = NULL ;
F_43 ( V_9 , V_21 ) ;
}
}
void F_102 ( struct V_8 * V_9 , struct V_21 * V_21 , char V_183 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
if ( V_183 == V_184 ) {
F_16 ( V_9 , V_21 , 0 ) ;
if ( V_9 -> V_72 . V_128 ) {
F_43 ( V_9 , V_21 ) ;
}
} else if ( V_183 == V_185 ) {
V_29 -> V_175 = V_179 ;
if ( V_9 -> V_72 . V_128 ) {
V_9 -> V_72 . F_58 = 1 ;
}
}
}
void F_103 ( struct V_8 * V_9 , struct V_21 * V_186 )
__releases( &bond->curr_slave_lock
int F_104 ( struct V_113 * V_146 , void * V_70 )
__acquires( &bond->lock
void F_105 ( struct V_8 * V_9 , unsigned short V_88 )
{
if ( V_9 -> V_72 . V_112 &&
( V_9 -> V_72 . V_112 -> V_88 == V_88 ) ) {
V_9 -> V_72 . V_112 = NULL ;
}
if ( V_9 -> V_72 . V_128 ) {
F_63 ( V_9 , V_88 ) ;
}
}
