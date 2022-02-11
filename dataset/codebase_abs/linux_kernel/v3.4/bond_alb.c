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
( F_32 ( V_49 -> V_54 , V_47 -> V_55 ) ) ) {
memcpy ( V_49 -> V_54 , V_47 -> V_55 , V_56 ) ;
V_49 -> V_57 = 1 ;
V_29 -> V_58 = 1 ;
}
F_28 ( V_9 ) ;
}
static int F_33 ( struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_21 * V_21 )
{
struct V_1 * V_47 ;
if ( V_3 -> V_59 != F_34 ( V_60 ) )
goto V_61;
V_47 = (struct V_1 * ) V_3 -> V_62 ;
if ( ! V_47 ) {
F_35 ( L_1 ) ;
goto V_61;
}
if ( ! F_36 ( V_3 , F_37 ( V_9 -> V_63 ) ) )
goto V_61;
if ( V_3 -> V_64 < sizeof( struct V_1 ) ) {
F_35 ( L_2 ) ;
goto V_61;
}
if ( V_47 -> V_65 == F_38 ( V_66 ) ) {
F_31 ( V_9 , V_47 ) ;
F_35 ( L_3 ) ;
}
V_61:
return V_67 ;
}
static struct V_21 * F_39 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_21 * V_68 , * V_21 , * V_69 ;
int V_6 = 0 ;
if ( V_29 -> V_70 ) {
V_69 = V_29 -> V_70 ;
} else {
V_69 = V_9 -> V_71 ;
}
V_68 = NULL ;
F_40 (bond, slave, i, start_at) {
if ( F_24 ( V_21 ) ) {
if ( ! V_68 ) {
V_68 = V_21 ;
} else if ( V_21 -> V_35 > V_68 -> V_35 ) {
V_68 = V_21 ;
}
}
}
if ( V_68 ) {
V_29 -> V_70 = V_68 -> V_18 ;
}
return V_68 ;
}
static void F_41 ( struct V_8 * V_9 , T_1 V_72 [] )
{
if ( ! V_9 -> V_73 ) {
return;
}
if ( ! V_9 -> V_74 . V_75 ) {
if ( ! F_42 ( V_9 -> V_73 -> V_63 , 1 ) )
V_9 -> V_74 . V_75 = 1 ;
else
V_9 -> V_74 . V_75 = 0 ;
}
V_9 -> V_74 . V_76 = 0 ;
F_43 ( V_9 -> V_73 , V_72 ) ;
}
static void F_44 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_48 * V_77 ;
T_2 V_25 , V_27 ;
F_27 ( V_9 ) ;
V_77 = V_29 -> V_51 ;
V_25 = V_29 -> V_78 ;
for (; V_25 != V_79 ; V_25 = V_27 ) {
V_27 = V_77 [ V_25 ] . V_18 ;
if ( V_77 [ V_25 ] . V_21 == V_21 ) {
struct V_21 * V_43 = F_39 ( V_9 ) ;
if ( V_43 ) {
V_77 [ V_25 ] . V_21 = V_43 ;
if ( F_32 ( V_77 [ V_25 ] . V_54 ,
V_80 ) ) {
V_29 -> V_51 [ V_25 ] . V_57 = 1 ;
V_29 -> V_58 = 1 ;
V_29 -> V_81 =
V_82 ;
}
} else {
V_77 [ V_25 ] . V_21 = NULL ;
}
}
}
F_28 ( V_9 ) ;
F_45 ( & V_9 -> V_83 ) ;
if ( V_21 != V_9 -> V_73 ) {
F_41 ( V_9 , V_21 -> V_63 -> V_84 ) ;
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
V_3 = F_48 ( V_66 , V_60 ,
V_49 -> V_53 ,
V_49 -> V_21 -> V_63 ,
V_49 -> V_50 ,
V_49 -> V_54 ,
V_49 -> V_21 -> V_63 -> V_84 ,
V_49 -> V_54 ) ;
if ( ! V_3 ) {
F_49 ( L_4 ,
V_49 -> V_21 -> V_63 -> V_86 -> V_87 ) ;
continue;
}
V_3 -> V_63 = V_49 -> V_21 -> V_63 ;
if ( V_49 -> V_88 ) {
V_3 = F_50 ( V_3 , V_49 -> V_89 ) ;
if ( ! V_3 ) {
F_49 ( L_5 ,
V_49 -> V_21 -> V_63 -> V_86 -> V_87 ) ;
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
V_40 = V_29 -> V_78 ;
for (; V_40 != V_79 ; V_40 = V_49 -> V_18 ) {
V_49 = & ( V_29 -> V_51 [ V_40 ] ) ;
if ( V_49 -> V_57 ) {
F_47 ( V_49 ) ;
if ( V_29 -> V_81 == 0 ) {
V_49 -> V_57 = 0 ;
}
}
}
V_29 -> V_90 = V_91 ;
F_28 ( V_9 ) ;
}
static void F_53 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_48 * V_49 ;
int V_57 = 0 ;
T_2 V_40 ;
F_27 ( V_9 ) ;
V_40 = V_29 -> V_78 ;
for (; V_40 != V_79 ; V_40 = V_49 -> V_18 ) {
V_49 = & ( V_29 -> V_51 [ V_40 ] ) ;
if ( ( V_49 -> V_21 == V_21 ) &&
F_32 ( V_49 -> V_54 , V_80 ) ) {
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
static void F_54 ( struct V_8 * V_9 , T_3 V_92 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_48 * V_49 ;
T_2 V_40 ;
F_29 ( V_9 ) ;
V_40 = V_29 -> V_78 ;
for (; V_40 != V_79 ; V_40 = V_49 -> V_18 ) {
V_49 = & ( V_29 -> V_51 [ V_40 ] ) ;
if ( ! V_49 -> V_21 ) {
F_49 ( L_6 ,
V_9 -> V_63 -> V_87 ) ;
continue;
}
if ( ( V_49 -> V_50 == V_92 ) &&
F_32 ( V_49 -> V_21 -> V_63 -> V_84 ,
V_9 -> V_63 -> V_84 ) &&
F_32 ( V_49 -> V_54 , V_80 ) ) {
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
if ( F_32 ( V_47 -> V_54 , V_80 ) ) {
memcpy ( V_49 -> V_54 , V_47 -> V_54 , V_56 ) ;
}
V_43 = V_49 -> V_21 ;
if ( V_43 ) {
F_30 ( V_9 ) ;
return V_43 ;
}
} else {
if ( V_9 -> V_73 &&
V_49 -> V_21 != V_9 -> V_73 ) {
V_49 -> V_21 = V_9 -> V_73 ;
F_47 ( V_49 ) ;
}
}
}
V_43 = F_39 ( V_9 ) ;
if ( V_43 ) {
V_49 -> V_50 = V_47 -> V_50 ;
V_49 -> V_53 = V_47 -> V_53 ;
memcpy ( V_49 -> V_54 , V_47 -> V_54 , V_56 ) ;
V_49 -> V_21 = V_43 ;
if ( F_32 ( V_49 -> V_54 , V_80 ) ) {
V_49 -> V_57 = 1 ;
V_9 -> V_74 . V_58 = 1 ;
} else {
V_49 -> V_57 = 0 ;
}
if ( F_56 ( V_9 ) ) {
if ( ! F_57 ( V_3 , & V_49 -> V_89 ) )
V_49 -> V_88 = 1 ;
}
if ( ! V_49 -> V_52 ) {
T_2 V_93 = V_29 -> V_78 ;
V_29 -> V_78 = V_40 ;
V_49 -> V_18 = V_93 ;
if ( V_93 != V_79 ) {
V_29 -> V_51 [ V_93 ] . V_20 =
V_40 ;
}
V_49 -> V_52 = 1 ;
}
}
F_30 ( V_9 ) ;
return V_43 ;
}
static struct V_21 * F_58 ( struct V_2 * V_3 , struct V_8 * V_9 )
{
struct V_1 * V_47 = V_1 ( V_3 ) ;
struct V_21 * V_17 = NULL ;
if ( V_47 -> V_65 == F_38 ( V_66 ) ) {
V_17 = F_55 ( V_3 , V_9 ) ;
if ( V_17 ) {
memcpy ( V_47 -> V_55 , V_17 -> V_63 -> V_84 , V_56 ) ;
}
F_35 ( L_7 ) ;
} else if ( V_47 -> V_65 == F_38 ( V_94 ) ) {
F_55 ( V_3 , V_9 ) ;
V_9 -> V_74 . V_90 = V_91 ;
F_54 ( V_9 , V_47 -> V_50 ) ;
F_35 ( L_8 ) ;
}
return V_17 ;
}
static void F_59 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_21 * V_43 ;
struct V_48 * V_49 ;
int V_57 ;
T_2 V_40 ;
F_27 ( V_9 ) ;
V_57 = 0 ;
V_40 = V_29 -> V_78 ;
for (; V_40 != V_79 ; V_40 = V_49 -> V_18 ) {
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
static void F_60 ( struct V_48 * V_12 )
{
memset ( V_12 , 0 , sizeof( struct V_48 ) ) ;
V_12 -> V_18 = V_79 ;
V_12 -> V_20 = V_79 ;
}
static int F_61 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_48 * V_32 ;
int V_30 = V_95 * sizeof( struct V_48 ) ;
int V_6 ;
V_32 = F_62 ( V_30 , V_33 ) ;
if ( ! V_32 )
return - 1 ;
F_27 ( V_9 ) ;
V_29 -> V_51 = V_32 ;
V_29 -> V_78 = V_79 ;
for ( V_6 = 0 ; V_6 < V_95 ; V_6 ++ ) {
F_60 ( V_29 -> V_51 + V_6 ) ;
}
F_28 ( V_9 ) ;
V_9 -> V_96 = F_33 ;
return 0 ;
}
static void F_63 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
F_27 ( V_9 ) ;
F_20 ( V_29 -> V_51 ) ;
V_29 -> V_51 = NULL ;
V_29 -> V_78 = V_79 ;
F_28 ( V_9 ) ;
}
static void F_64 ( struct V_8 * V_9 , unsigned short V_89 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
T_2 V_97 ;
F_27 ( V_9 ) ;
V_97 = V_29 -> V_78 ;
while ( V_97 != V_79 ) {
struct V_48 * V_98 = & ( V_29 -> V_51 [ V_97 ] ) ;
T_2 V_27 = V_29 -> V_51 [ V_97 ] . V_18 ;
T_2 V_99 = V_29 -> V_51 [ V_97 ] . V_20 ;
if ( V_98 -> V_88 && ( V_98 -> V_89 == V_89 ) ) {
if ( V_97 == V_29 -> V_78 ) {
V_29 -> V_78 = V_27 ;
}
if ( V_99 != V_79 ) {
V_29 -> V_51 [ V_99 ] . V_18 = V_27 ;
}
if ( V_27 != V_79 ) {
V_29 -> V_51 [ V_27 ] . V_20 = V_99 ;
}
F_60 ( V_98 ) ;
}
V_97 = V_27 ;
}
F_28 ( V_9 ) ;
}
static void F_43 ( struct V_21 * V_21 , T_1 V_100 [] )
{
struct V_8 * V_9 = F_65 ( V_21 ) ;
struct V_101 V_102 ;
int V_30 = sizeof( struct V_101 ) ;
int V_6 ;
memset ( & V_102 , 0 , V_30 ) ;
memcpy ( V_102 . V_54 , V_100 , V_56 ) ;
memcpy ( V_102 . V_55 , V_100 , V_56 ) ;
V_102 . type = F_34 ( V_103 ) ;
for ( V_6 = 0 ; V_6 < V_104 ; V_6 ++ ) {
struct V_2 * V_3 ;
char * V_62 ;
V_3 = F_66 ( V_30 ) ;
if ( ! V_3 ) {
return;
}
V_62 = F_67 ( V_3 , V_30 ) ;
memcpy ( V_62 , & V_102 , V_30 ) ;
F_68 ( V_3 ) ;
V_3 -> V_105 = V_3 -> V_106 + V_107 ;
V_3 -> V_59 = V_102 . type ;
V_3 -> V_108 = V_109 ;
V_3 -> V_63 = V_21 -> V_63 ;
if ( F_56 ( V_9 ) ) {
struct V_110 * V_111 ;
V_111 = F_69 ( V_9 ,
V_9 -> V_74 . V_112 ) ;
V_9 -> V_74 . V_112 = V_111 ;
if ( ! V_111 ) {
F_70 ( V_3 ) ;
continue;
}
V_3 = F_50 ( V_3 , V_111 -> V_89 ) ;
if ( ! V_3 ) {
F_49 ( L_5 ,
V_9 -> V_63 -> V_87 ) ;
continue;
}
}
F_71 ( V_3 ) ;
}
}
static int F_72 ( struct V_21 * V_21 , T_1 V_72 [] )
{
struct V_113 * V_63 = V_21 -> V_63 ;
struct V_114 V_115 ;
if ( V_21 -> V_9 -> V_116 . V_117 == V_118 ) {
memcpy ( V_63 -> V_84 , V_72 , V_63 -> V_119 ) ;
return 0 ;
}
memcpy ( V_115 . V_120 , V_72 , V_63 -> V_119 ) ;
V_115 . V_121 = V_63 -> type ;
if ( F_73 ( V_63 , & V_115 ) ) {
F_49 ( L_9
L_10 ,
V_63 -> V_86 -> V_87 , V_63 -> V_87 ) ;
return - V_122 ;
}
return 0 ;
}
static void F_74 ( struct V_8 * V_9 , struct V_21 * V_123 , struct V_21 * V_124 )
{
T_1 V_125 [ V_56 ] ;
memcpy ( V_125 , V_123 -> V_63 -> V_84 , V_56 ) ;
F_72 ( V_123 , V_124 -> V_63 -> V_84 ) ;
F_72 ( V_124 , V_125 ) ;
}
static void F_75 ( struct V_8 * V_9 , struct V_21 * V_123 ,
struct V_21 * V_124 )
{
int V_126 = ( F_24 ( V_123 ) != F_24 ( V_124 ) ) ;
struct V_21 * V_127 = NULL ;
F_76 () ;
if ( F_24 ( V_123 ) ) {
F_43 ( V_123 , V_123 -> V_63 -> V_84 ) ;
if ( V_9 -> V_74 . V_128 ) {
F_53 ( V_9 , V_123 ) ;
}
} else {
V_127 = V_123 ;
}
if ( F_24 ( V_124 ) ) {
F_43 ( V_124 , V_124 -> V_63 -> V_84 ) ;
if ( V_9 -> V_74 . V_128 ) {
F_53 ( V_9 , V_124 ) ;
}
} else {
V_127 = V_124 ;
}
if ( V_9 -> V_74 . V_128 && V_126 ) {
F_41 ( V_9 ,
V_127 -> V_63 -> V_84 ) ;
}
}
static void F_77 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
int V_129 ;
int V_130 ;
V_129 = F_32 ( V_21 -> V_131 ,
V_21 -> V_63 -> V_84 ) ;
V_130 = F_32 ( V_21 -> V_131 ,
V_9 -> V_63 -> V_84 ) ;
if ( V_129 && V_130 ) {
struct V_21 * V_132 ;
int V_6 , V_133 = 0 ;
F_23 (bond, tmp_slave, i) {
if ( ! F_32 ( V_21 -> V_131 ,
V_132 -> V_63 -> V_84 ) ) {
V_133 = 1 ;
break;
}
}
if ( V_133 ) {
F_74 ( V_9 , V_21 , V_132 ) ;
F_75 ( V_9 , V_21 , V_132 ) ;
}
}
}
static int F_78 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
struct V_21 * V_134 , * V_135 , * V_136 ;
struct V_21 * V_137 = V_9 -> V_73 ;
int V_6 , V_138 , V_133 = 0 ;
if ( V_9 -> V_139 == 0 ) {
return 0 ;
}
if ( F_32 ( V_21 -> V_131 , V_9 -> V_63 -> V_84 ) ) {
F_23 (bond, tmp_slave1, i) {
if ( ! F_32 ( V_134 -> V_63 -> V_84 ,
V_21 -> V_63 -> V_84 ) ) {
V_133 = 1 ;
break;
}
}
if ( ! V_133 )
return 0 ;
F_72 ( V_21 , V_9 -> V_63 -> V_84 ) ;
}
V_136 = NULL ;
F_23 (bond, tmp_slave1, i) {
V_133 = 0 ;
F_23 (bond, tmp_slave2, j) {
if ( ! F_32 ( V_134 -> V_131 ,
V_135 -> V_63 -> V_84 ) ) {
V_133 = 1 ;
break;
}
}
if ( ! V_133 ) {
V_136 = V_134 ;
break;
}
if ( ! V_137 ) {
if ( ! F_32 ( V_134 -> V_63 -> V_84 ,
V_9 -> V_63 -> V_84 ) ) {
V_137 = V_134 ;
}
}
}
if ( V_136 ) {
F_72 ( V_21 , V_136 -> V_131 ) ;
F_79 ( L_11 ,
V_9 -> V_63 -> V_87 , V_21 -> V_63 -> V_87 ,
V_136 -> V_63 -> V_87 ) ;
} else if ( V_137 ) {
F_49 ( L_12 ,
V_9 -> V_63 -> V_87 , V_21 -> V_63 -> V_87 ) ;
return - V_140 ;
}
return 0 ;
}
static int F_80 ( struct V_8 * V_9 , void * V_72 )
{
struct V_114 V_141 ;
struct V_21 * V_21 , * V_142 ;
char V_143 [ V_56 ] ;
int V_144 ;
int V_6 ;
if ( V_9 -> V_74 . V_128 ) {
return 0 ;
}
F_23 (bond, slave, i) {
memcpy ( V_143 , V_21 -> V_63 -> V_84 , V_56 ) ;
V_144 = F_73 ( V_21 -> V_63 , V_72 ) ;
memcpy ( V_21 -> V_63 -> V_84 , V_143 , V_56 ) ;
if ( V_144 )
goto V_145;
}
return 0 ;
V_145:
memcpy ( V_141 . V_120 , V_9 -> V_63 -> V_84 , V_9 -> V_63 -> V_119 ) ;
V_141 . V_121 = V_9 -> V_63 -> type ;
V_142 = V_21 ;
F_81 (bond, slave, i, bond->first_slave, stop_at) {
memcpy ( V_143 , V_21 -> V_63 -> V_84 , V_56 ) ;
F_73 ( V_21 -> V_63 , & V_141 ) ;
memcpy ( V_21 -> V_63 -> V_84 , V_143 , V_56 ) ;
}
return V_144 ;
}
int F_82 ( struct V_8 * V_9 , int V_128 )
{
int V_144 ;
V_144 = F_17 ( V_9 ) ;
if ( V_144 ) {
return V_144 ;
}
if ( V_128 ) {
V_9 -> V_74 . V_128 = 1 ;
V_144 = F_61 ( V_9 ) ;
if ( V_144 ) {
F_19 ( V_9 ) ;
return V_144 ;
}
} else {
V_9 -> V_74 . V_128 = 0 ;
}
return 0 ;
}
void F_83 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
F_19 ( V_9 ) ;
if ( V_29 -> V_128 ) {
F_63 ( V_9 ) ;
}
}
int F_84 ( struct V_2 * V_3 , struct V_113 * V_146 )
{
struct V_8 * V_9 = F_85 ( V_146 ) ;
struct V_147 * V_148 ;
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_21 * V_17 = NULL ;
static const T_3 V_149 = F_86 ( 0xffffffff ) ;
int V_5 = 0 ;
int V_150 = 1 ;
T_2 V_40 = 0 ;
const T_1 * V_4 = NULL ;
int V_144 = 1 ;
struct V_151 * V_152 ;
F_68 ( V_3 ) ;
V_148 = F_87 ( V_3 ) ;
F_88 ( & V_9 -> V_83 ) ;
switch ( F_89 ( V_3 -> V_59 ) ) {
case V_153 : {
const struct V_154 * V_155 = F_90 ( V_3 ) ;
if ( ! F_32 ( V_148 -> V_156 , V_80 ) ||
( V_155 -> V_157 == V_149 ) ||
( V_155 -> V_59 == V_158 ) ) {
V_150 = 0 ;
break;
}
V_4 = ( char * ) & ( V_155 -> V_157 ) ;
V_5 = sizeof( V_155 -> V_157 ) ;
}
break;
case V_159 :
if ( ! F_32 ( V_148 -> V_156 , V_80 ) ) {
V_150 = 0 ;
break;
}
if ( ! F_32 ( V_148 -> V_156 , V_160 ) ) {
V_150 = 0 ;
break;
}
V_152 = F_91 ( V_3 ) ;
if ( F_92 ( & V_152 -> V_161 ) ) {
V_150 = 0 ;
break;
}
V_4 = ( char * ) & ( F_91 ( V_3 ) -> V_157 ) ;
V_5 = sizeof( F_91 ( V_3 ) -> V_157 ) ;
break;
case V_162 :
if ( F_93 ( V_3 ) -> V_163 != V_164 ) {
V_150 = 0 ;
break;
}
if ( F_93 ( V_3 ) -> V_165 != V_166 ) {
V_150 = 0 ;
break;
}
V_4 = ( char * ) V_148 -> V_156 ;
V_5 = V_56 ;
break;
case V_60 :
V_150 = 0 ;
if ( V_29 -> V_128 ) {
V_17 = F_58 ( V_3 , V_9 ) ;
}
break;
default:
V_150 = 0 ;
break;
}
if ( V_150 ) {
V_40 = F_2 ( V_4 , V_5 ) ;
V_17 = F_26 ( V_9 , V_40 , V_3 -> V_64 ) ;
}
if ( ! V_17 ) {
V_17 = V_9 -> V_73 ;
V_29 -> V_167 += V_3 -> V_64 ;
}
if ( V_17 && F_24 ( V_17 ) ) {
if ( V_17 != V_9 -> V_73 ) {
memcpy ( V_148 -> V_168 ,
V_17 -> V_63 -> V_84 ,
V_56 ) ;
}
V_144 = F_94 ( V_9 , V_3 , V_17 -> V_63 ) ;
} else {
if ( V_17 ) {
F_8 ( V_9 ) ;
F_15 ( V_9 , V_17 , 0 ) ;
F_10 ( V_9 ) ;
}
}
if ( V_144 ) {
F_95 ( V_3 ) ;
}
F_96 ( & V_9 -> V_83 ) ;
return V_169 ;
}
void F_97 ( struct V_170 * V_171 )
{
struct V_8 * V_9 = F_98 ( V_171 , struct V_8 ,
V_172 . V_171 ) ;
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
struct V_21 * V_21 ;
int V_6 ;
F_88 ( & V_9 -> V_173 ) ;
if ( V_9 -> V_139 == 0 ) {
V_29 -> V_174 = 0 ;
V_29 -> V_175 = 0 ;
goto V_176;
}
V_29 -> V_174 ++ ;
V_29 -> V_175 ++ ;
if ( V_29 -> V_175 >= V_177 ) {
F_88 ( & V_9 -> V_83 ) ;
F_23 (bond, slave, i) {
F_43 ( V_21 , V_21 -> V_63 -> V_84 ) ;
}
F_96 ( & V_9 -> V_83 ) ;
V_29 -> V_175 = 0 ;
}
if ( V_29 -> V_174 >= V_178 ) {
F_88 ( & V_9 -> V_83 ) ;
F_23 (bond, slave, i) {
F_16 ( V_9 , V_21 , 1 ) ;
if ( V_21 == V_9 -> V_73 ) {
F_14 ( V_21 ) . V_22 =
V_29 -> V_167 /
V_16 ;
V_29 -> V_167 = 0 ;
}
}
F_96 ( & V_9 -> V_83 ) ;
V_29 -> V_174 = 0 ;
}
if ( V_29 -> V_128 ) {
if ( V_29 -> V_75 &&
( ++ V_29 -> V_76 >= V_179 ) ) {
F_96 ( & V_9 -> V_173 ) ;
if ( ! F_99 () ) {
F_88 ( & V_9 -> V_173 ) ;
goto V_176;
}
V_29 -> V_76 = 0 ;
F_42 ( V_9 -> V_73 -> V_63 , - 1 ) ;
V_29 -> V_75 = 0 ;
F_100 () ;
F_88 ( & V_9 -> V_173 ) ;
}
if ( V_29 -> F_59 ) {
V_29 -> F_59 = 0 ;
F_59 ( V_9 ) ;
}
if ( V_29 -> V_58 ) {
if ( V_29 -> V_90 ) {
-- V_29 -> V_90 ;
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
V_176:
F_101 ( V_9 -> V_180 , & V_9 -> V_172 , V_181 ) ;
F_96 ( & V_9 -> V_173 ) ;
}
int F_102 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
int V_144 ;
V_144 = F_72 ( V_21 , V_21 -> V_131 ) ;
if ( V_144 ) {
return V_144 ;
}
F_88 ( & V_9 -> V_173 ) ;
V_144 = F_78 ( V_9 , V_21 ) ;
F_96 ( & V_9 -> V_173 ) ;
if ( V_144 ) {
return V_144 ;
}
F_13 ( V_21 ) ;
V_9 -> V_74 . V_174 = V_178 ;
if ( V_9 -> V_74 . V_128 ) {
V_9 -> V_74 . F_59 = 1 ;
}
return 0 ;
}
void F_103 ( struct V_8 * V_9 , struct V_21 * V_21 )
{
if ( V_9 -> V_139 > 1 ) {
F_77 ( V_9 , V_21 ) ;
}
F_16 ( V_9 , V_21 , 0 ) ;
if ( V_9 -> V_74 . V_128 ) {
V_9 -> V_74 . V_70 = NULL ;
F_44 ( V_9 , V_21 ) ;
}
}
void F_104 ( struct V_8 * V_9 , struct V_21 * V_21 , char V_182 )
{
struct V_28 * V_29 = & ( F_5 ( V_9 ) ) ;
if ( V_182 == V_183 ) {
F_16 ( V_9 , V_21 , 0 ) ;
if ( V_9 -> V_74 . V_128 ) {
F_44 ( V_9 , V_21 ) ;
}
} else if ( V_182 == V_184 ) {
V_29 -> V_174 = V_178 ;
if ( V_9 -> V_74 . V_128 ) {
V_9 -> V_74 . F_59 = 1 ;
}
}
}
void F_105 ( struct V_8 * V_9 , struct V_21 * V_185 )
__releases( &bond->curr_slave_lock
int F_106 ( struct V_113 * V_146 , void * V_72 )
__acquires( &bond->lock
void F_107 ( struct V_8 * V_9 , unsigned short V_89 )
{
if ( V_9 -> V_74 . V_112 &&
( V_9 -> V_74 . V_112 -> V_89 == V_89 ) ) {
V_9 -> V_74 . V_112 = NULL ;
}
if ( V_9 -> V_74 . V_128 ) {
F_64 ( V_9 , V_89 ) ;
}
}
