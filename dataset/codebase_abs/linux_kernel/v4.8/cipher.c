static inline void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( & V_2 -> V_5 , V_4 -> V_6 ) ;
F_3 ( & V_2 -> V_7 , V_4 -> V_7 , V_8 ) ;
F_3 ( & V_2 -> V_9 , V_4 -> V_9 , V_10 ) ;
}
static inline bool
F_4 ( struct V_1 * V_2 )
{
V_2 -> V_7 . V_11 = 0 ;
V_2 -> V_9 . V_11 = 0 ;
return F_5 ( & V_2 -> V_5 ) ;
}
static inline void
F_6 ( struct V_3 * V_4 )
{
struct V_12 * V_13 = F_7 ( V_4 ) ;
if ( V_4 -> V_9 != V_4 -> V_7 ) {
F_8 ( V_14 -> V_15 , V_4 -> V_9 , V_13 -> V_16 ,
V_10 ) ;
F_8 ( V_14 -> V_15 , V_4 -> V_7 , V_13 -> V_17 ,
V_8 ) ;
} else {
F_8 ( V_14 -> V_15 , V_4 -> V_7 , V_13 -> V_17 ,
V_18 ) ;
}
F_9 ( & V_13 -> V_5 ) ;
}
static inline void F_10 ( struct V_3 * V_4 )
{
struct V_12 * V_13 = F_7 ( V_4 ) ;
if ( F_11 ( & V_13 -> V_5 ) == V_19 )
F_6 ( V_4 ) ;
}
static void F_12 ( struct V_3 * V_4 )
{
struct V_12 * V_13 = F_7 ( V_4 ) ;
struct V_20 * V_21 = & V_13 -> V_22 ;
struct V_23 * V_24 = V_13 -> V_5 . V_24 ;
T_1 V_25 = F_13 ( T_1 , V_4 -> V_6 - V_21 -> V_26 ,
V_27 ) ;
F_14 ( V_24 , & V_21 -> V_28 ) ;
F_15 ( V_24 -> V_29 , & V_21 -> V_28 , sizeof( V_21 -> V_28 ) ) ;
V_25 = F_16 ( V_4 -> V_7 , V_13 -> V_17 ,
V_24 -> V_29 + V_30 ,
V_25 , V_21 -> V_26 ) ;
V_21 -> V_31 = V_25 ;
F_17 ( & V_21 -> V_28 , V_25 ) ;
if ( ! V_21 -> V_32 ) {
F_15 ( V_24 -> V_29 , & V_21 -> V_28 , sizeof( V_21 -> V_28 ) ) ;
V_21 -> V_32 = true ;
} else {
F_15 ( V_24 -> V_29 , & V_21 -> V_28 , sizeof( V_21 -> V_28 . V_33 ) ) ;
}
F_18 ( V_24 , V_34 ) ;
F_19 ( V_35 , V_24 -> V_36 + V_37 ) ;
F_20 ( F_21 ( V_24 -> V_36 + V_38 ) &
V_39 ) ;
F_22 ( V_39 , V_24 -> V_36 + V_38 ) ;
}
static int F_23 ( struct V_3 * V_4 ,
T_2 V_40 )
{
struct V_12 * V_13 = F_7 ( V_4 ) ;
struct V_20 * V_21 = & V_13 -> V_22 ;
struct V_23 * V_24 = V_13 -> V_5 . V_24 ;
T_1 V_25 ;
V_25 = F_24 ( V_4 -> V_9 , V_13 -> V_16 ,
V_24 -> V_29 + V_30 ,
V_21 -> V_31 , V_21 -> V_26 ) ;
V_21 -> V_26 += V_25 ;
if ( V_21 -> V_26 < V_4 -> V_6 )
return - V_41 ;
return 0 ;
}
static int F_25 ( struct V_42 * V_4 ,
T_2 V_40 )
{
struct V_3 * V_43 = F_26 ( V_4 ) ;
struct V_12 * V_13 = F_7 ( V_43 ) ;
struct V_44 * V_45 = & V_13 -> V_5 ;
if ( F_11 ( V_45 ) == V_46 )
return F_23 ( V_43 , V_40 ) ;
return F_27 ( V_45 , V_40 ) ;
}
static void F_28 ( struct V_42 * V_4 )
{
struct V_3 * V_43 = F_26 ( V_4 ) ;
struct V_12 * V_13 = F_7 ( V_43 ) ;
if ( F_11 ( & V_13 -> V_5 ) == V_19 )
F_29 ( & V_13 -> V_5 ) ;
else
F_12 ( V_43 ) ;
}
static inline void
F_30 ( struct V_3 * V_4 )
{
struct V_12 * V_13 = F_7 ( V_4 ) ;
struct V_44 * V_45 = & V_13 -> V_5 ;
F_31 ( V_45 , V_45 -> V_24 ) ;
}
static inline void
F_32 ( struct V_3 * V_4 )
{
struct V_12 * V_13 = F_7 ( V_4 ) ;
struct V_20 * V_21 = & V_13 -> V_22 ;
V_21 -> V_31 = 0 ;
V_21 -> V_26 = 0 ;
}
static inline void F_33 ( struct V_42 * V_4 ,
struct V_23 * V_24 )
{
struct V_3 * V_43 = F_26 ( V_4 ) ;
struct V_12 * V_13 = F_7 ( V_43 ) ;
V_13 -> V_5 . V_24 = V_24 ;
if ( F_11 ( & V_13 -> V_5 ) == V_19 )
F_30 ( V_43 ) ;
else
F_32 ( V_43 ) ;
}
static inline void
F_34 ( struct V_42 * V_4 )
{
struct V_3 * V_43 = F_26 ( V_4 ) ;
F_10 ( V_43 ) ;
}
static void
F_35 ( struct V_42 * V_4 )
{
struct V_3 * V_43 = F_26 ( V_4 ) ;
struct V_12 * V_13 = F_7 ( V_43 ) ;
struct V_23 * V_24 = V_13 -> V_5 . V_24 ;
unsigned int V_47 ;
F_36 ( V_43 -> V_6 , & V_24 -> V_48 ) ;
V_47 = F_37 ( F_38 ( V_43 ) ) ;
if ( F_11 ( & V_13 -> V_5 ) == V_19 ) {
struct V_44 * V_45 ;
V_45 = & V_13 -> V_5 ;
memcpy ( V_43 -> V_49 , V_45 -> V_50 . V_51 -> V_52 , V_47 ) ;
} else {
F_39 ( V_43 -> V_49 ,
V_24 -> V_29 + V_53 ,
V_47 ) ;
}
}
static int F_40 ( struct V_54 * V_55 )
{
struct V_56 * V_57 = F_41 ( V_55 ) ;
V_57 -> V_5 . V_58 = & V_59 ;
V_55 -> V_60 . V_61 = sizeof( struct V_12 ) ;
return 0 ;
}
static int F_42 ( struct V_62 * V_63 , const T_3 * V_64 ,
unsigned int V_25 )
{
struct V_54 * V_55 = F_43 ( V_63 ) ;
struct V_56 * V_57 = F_41 ( V_55 ) ;
int V_65 ;
int V_26 ;
int V_66 ;
int V_67 ;
V_66 = F_44 ( & V_57 -> V_68 , V_64 , V_25 ) ;
if ( V_66 ) {
F_45 ( V_63 , V_69 ) ;
return V_66 ;
}
V_65 = ( V_57 -> V_68 . V_70 - 16 ) / 4 ;
V_26 = V_57 -> V_68 . V_70 + 24 - V_65 ;
for ( V_67 = 0 ; V_67 < V_65 ; V_67 ++ )
V_57 -> V_68 . V_71 [ 4 + V_67 ] =
F_46 ( V_57 -> V_68 . V_72 [ V_26 + V_67 ] ) ;
return 0 ;
}
static int F_47 ( struct V_62 * V_63 , const T_3 * V_64 ,
unsigned int V_25 )
{
struct V_54 * V_55 = F_43 ( V_63 ) ;
struct V_73 * V_57 = F_41 ( V_55 ) ;
T_2 V_74 [ V_75 ] ;
int V_66 ;
if ( V_25 != V_76 ) {
F_45 ( V_63 , V_69 ) ;
return - V_77 ;
}
V_66 = F_48 ( V_74 , V_64 ) ;
if ( ! V_66 && ( V_55 -> V_78 & V_79 ) ) {
V_55 -> V_78 |= V_80 ;
return - V_77 ;
}
memcpy ( V_57 -> V_64 , V_64 , V_76 ) ;
return 0 ;
}
static int F_49 ( struct V_62 * V_63 ,
const T_3 * V_64 , unsigned int V_25 )
{
struct V_54 * V_55 = F_43 ( V_63 ) ;
struct V_73 * V_57 = F_41 ( V_55 ) ;
if ( V_25 != V_81 ) {
F_45 ( V_63 , V_69 ) ;
return - V_77 ;
}
memcpy ( V_57 -> V_64 , V_64 , V_81 ) ;
return 0 ;
}
static int F_50 ( struct V_3 * V_4 ,
const struct V_82 * V_83 )
{
struct V_12 * V_13 = F_7 ( V_4 ) ;
T_4 V_84 = ( V_4 -> V_5 . V_84 & V_85 ) ?
V_86 : V_87 ;
struct V_44 * V_45 = & V_13 -> V_5 ;
struct V_1 V_2 ;
bool V_32 = false ;
int V_66 ;
unsigned int V_47 ;
V_45 -> V_50 . V_88 = NULL ;
V_45 -> V_50 . V_51 = NULL ;
if ( V_4 -> V_7 != V_4 -> V_9 ) {
V_66 = F_51 ( V_14 -> V_15 , V_4 -> V_7 , V_13 -> V_17 ,
V_8 ) ;
if ( ! V_66 )
return - V_89 ;
V_66 = F_51 ( V_14 -> V_15 , V_4 -> V_9 , V_13 -> V_16 ,
V_10 ) ;
if ( ! V_66 ) {
V_66 = - V_89 ;
goto V_90;
}
} else {
V_66 = F_51 ( V_14 -> V_15 , V_4 -> V_7 , V_13 -> V_17 ,
V_18 ) ;
if ( ! V_66 )
return - V_89 ;
}
F_52 ( & V_45 -> V_50 ) ;
F_1 ( & V_2 , V_4 ) ;
do {
struct V_82 * V_28 ;
V_28 = F_53 ( & V_45 -> V_50 , V_83 , V_32 , V_84 ) ;
if ( F_54 ( V_28 ) ) {
V_66 = F_55 ( V_28 ) ;
goto V_91;
}
V_32 = true ;
F_17 ( V_28 , V_2 . V_5 . V_92 ) ;
V_66 = F_56 ( & V_45 -> V_50 , & V_2 . V_5 ,
& V_2 . V_7 , V_84 ) ;
if ( V_66 )
goto V_91;
V_66 = F_57 ( & V_45 -> V_50 , V_84 ) ;
if ( V_66 )
goto V_91;
V_66 = F_56 ( & V_45 -> V_50 , & V_2 . V_5 ,
& V_2 . V_9 , V_84 ) ;
if ( V_66 )
goto V_91;
} while ( F_4 ( & V_2 ) );
V_47 = F_37 ( F_38 ( V_4 ) ) ;
V_66 = F_58 ( & V_45 -> V_50 , V_53 ,
V_47 , V_93 , V_84 ) ;
if ( V_66 )
goto V_91;
V_45 -> V_50 . V_51 -> V_84 |= V_94 ;
return 0 ;
V_91:
F_9 ( V_45 ) ;
if ( V_4 -> V_9 != V_4 -> V_7 )
F_8 ( V_14 -> V_15 , V_4 -> V_9 , V_13 -> V_16 ,
V_10 ) ;
V_90:
F_8 ( V_14 -> V_15 , V_4 -> V_7 , V_13 -> V_17 ,
V_4 -> V_9 != V_4 -> V_7 ? V_8 : V_18 ) ;
return V_66 ;
}
static inline int
F_59 ( struct V_3 * V_4 ,
const struct V_82 * V_83 )
{
struct V_12 * V_13 = F_7 ( V_4 ) ;
struct V_20 * V_21 = & V_13 -> V_22 ;
struct V_44 * V_45 = & V_13 -> V_5 ;
V_21 -> V_28 = * V_83 ;
V_21 -> V_32 = false ;
V_45 -> V_50 . V_88 = NULL ;
V_45 -> V_50 . V_51 = NULL ;
return 0 ;
}
static int F_60 ( struct V_3 * V_4 ,
struct V_82 * V_95 )
{
struct V_12 * V_13 = F_7 ( V_4 ) ;
struct V_62 * V_55 = F_38 ( V_4 ) ;
unsigned int V_96 = F_61 ( V_55 ) ;
int V_66 ;
if ( ! F_62 ( V_4 -> V_6 , V_96 ) )
return - V_77 ;
V_13 -> V_17 = F_63 ( V_4 -> V_7 , V_4 -> V_6 ) ;
if ( V_13 -> V_17 < 0 ) {
F_64 ( V_14 -> V_15 , L_1 ) ;
return V_13 -> V_17 ;
}
V_13 -> V_16 = F_63 ( V_4 -> V_9 , V_4 -> V_6 ) ;
if ( V_13 -> V_16 < 0 ) {
F_64 ( V_14 -> V_15 , L_2 ) ;
return V_13 -> V_16 ;
}
F_65 ( V_95 , V_97 ,
V_98 ) ;
if ( V_14 -> V_99 -> V_100 )
V_66 = F_50 ( V_4 , V_95 ) ;
else
V_66 = F_59 ( V_4 , V_95 ) ;
return V_66 ;
}
static int F_66 ( struct V_3 * V_4 ,
struct V_82 * V_95 )
{
int V_66 ;
struct V_12 * V_13 = F_7 ( V_4 ) ;
struct V_23 * V_24 ;
V_66 = F_60 ( V_4 , V_95 ) ;
if ( V_66 )
return V_66 ;
V_24 = F_67 ( V_4 -> V_6 ) ;
F_33 ( & V_4 -> V_5 , V_24 ) ;
V_66 = F_68 ( & V_4 -> V_5 , & V_13 -> V_5 ) ;
if ( F_69 ( & V_4 -> V_5 , V_66 ) )
F_10 ( V_4 ) ;
return V_66 ;
}
static int F_70 ( struct V_3 * V_4 ,
struct V_82 * V_95 )
{
struct V_73 * V_57 = F_41 ( V_4 -> V_5 . V_55 ) ;
F_65 ( V_95 , V_101 ,
V_102 ) ;
memcpy ( V_95 -> V_57 . V_103 . V_64 , V_57 -> V_64 , V_76 ) ;
return F_66 ( V_4 , V_95 ) ;
}
static int F_71 ( struct V_3 * V_4 )
{
struct V_82 V_95 ;
F_72 ( & V_95 ,
V_104 |
V_105 ) ;
return F_70 ( V_4 , & V_95 ) ;
}
static int F_73 ( struct V_3 * V_4 )
{
struct V_82 V_95 ;
F_72 ( & V_95 ,
V_104 |
V_106 ) ;
return F_70 ( V_4 , & V_95 ) ;
}
static int F_74 ( struct V_3 * V_4 ,
struct V_82 * V_95 )
{
F_65 ( V_95 , V_107 ,
V_108 ) ;
memcpy ( V_95 -> V_57 . V_103 . V_109 , V_4 -> V_49 , V_110 ) ;
return F_70 ( V_4 , V_95 ) ;
}
static int F_75 ( struct V_3 * V_4 )
{
struct V_82 V_95 ;
F_72 ( & V_95 , V_105 ) ;
return F_74 ( V_4 , & V_95 ) ;
}
static int F_76 ( struct V_3 * V_4 )
{
struct V_82 V_95 ;
F_72 ( & V_95 , V_106 ) ;
return F_74 ( V_4 , & V_95 ) ;
}
static int F_77 ( struct V_3 * V_4 ,
struct V_82 * V_95 )
{
struct V_111 * V_57 = F_41 ( V_4 -> V_5 . V_55 ) ;
F_65 ( V_95 , V_112 ,
V_102 ) ;
memcpy ( V_95 -> V_57 . V_103 . V_64 , V_57 -> V_64 , V_81 ) ;
return F_66 ( V_4 , V_95 ) ;
}
static int F_78 ( struct V_3 * V_4 )
{
struct V_82 V_95 ;
F_72 ( & V_95 ,
V_104 |
V_113 |
V_105 ) ;
return F_77 ( V_4 , & V_95 ) ;
}
static int F_79 ( struct V_3 * V_4 )
{
struct V_82 V_95 ;
F_72 ( & V_95 ,
V_104 |
V_113 |
V_106 ) ;
return F_77 ( V_4 , & V_95 ) ;
}
static int F_80 ( struct V_3 * V_4 ,
struct V_82 * V_95 )
{
memcpy ( V_95 -> V_57 . V_103 . V_109 , V_4 -> V_49 , V_114 ) ;
return F_77 ( V_4 , V_95 ) ;
}
static int F_81 ( struct V_3 * V_4 )
{
struct V_82 V_95 ;
F_72 ( & V_95 ,
V_107 |
V_113 |
V_105 ) ;
return F_80 ( V_4 , & V_95 ) ;
}
static int F_82 ( struct V_3 * V_4 )
{
struct V_82 V_95 ;
F_72 ( & V_95 ,
V_107 |
V_113 |
V_106 ) ;
return F_80 ( V_4 , & V_95 ) ;
}
static int F_83 ( struct V_3 * V_4 ,
struct V_82 * V_95 )
{
struct V_56 * V_57 = F_41 ( V_4 -> V_5 . V_55 ) ;
int V_67 ;
T_2 * V_64 ;
T_2 V_115 ;
V_115 = V_116 ;
if ( F_84 ( V_95 ) & V_106 )
V_64 = V_57 -> V_68 . V_71 ;
else
V_64 = V_57 -> V_68 . V_72 ;
for ( V_67 = 0 ; V_67 < V_57 -> V_68 . V_70 / sizeof( T_2 ) ; V_67 ++ )
V_95 -> V_57 . V_103 . V_64 [ V_67 ] = F_46 ( V_64 [ V_67 ] ) ;
if ( V_57 -> V_68 . V_70 == 24 )
V_115 |= V_117 ;
else if ( V_57 -> V_68 . V_70 == 32 )
V_115 |= V_118 ;
F_65 ( V_95 , V_115 ,
V_102 |
V_119 ) ;
return F_66 ( V_4 , V_95 ) ;
}
static int F_85 ( struct V_3 * V_4 )
{
struct V_82 V_95 ;
F_72 ( & V_95 ,
V_104 |
V_105 ) ;
return F_83 ( V_4 , & V_95 ) ;
}
static int F_86 ( struct V_3 * V_4 )
{
struct V_82 V_95 ;
F_72 ( & V_95 ,
V_104 |
V_106 ) ;
return F_83 ( V_4 , & V_95 ) ;
}
static int F_87 ( struct V_3 * V_4 ,
struct V_82 * V_95 )
{
F_65 ( V_95 , V_107 ,
V_108 ) ;
memcpy ( V_95 -> V_57 . V_103 . V_109 , V_4 -> V_49 , V_120 ) ;
return F_83 ( V_4 , V_95 ) ;
}
static int F_88 ( struct V_3 * V_4 )
{
struct V_82 V_95 ;
F_72 ( & V_95 , V_105 ) ;
return F_87 ( V_4 , & V_95 ) ;
}
static int F_89 ( struct V_3 * V_4 )
{
struct V_82 V_95 ;
F_72 ( & V_95 , V_106 ) ;
return F_87 ( V_4 , & V_95 ) ;
}
