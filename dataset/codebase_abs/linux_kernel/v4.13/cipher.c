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
memcpy ( V_43 -> V_49 , V_45 -> V_50 . V_51 -> V_28 -> V_52 . V_53 . V_54 ,
V_47 ) ;
} else {
F_39 ( V_43 -> V_49 ,
V_24 -> V_29 + V_55 ,
V_47 ) ;
}
}
static int F_40 ( struct V_56 * V_57 )
{
struct V_58 * V_52 = F_41 ( V_57 ) ;
V_52 -> V_5 . V_59 = & V_60 ;
V_57 -> V_61 . V_62 = sizeof( struct V_12 ) ;
return 0 ;
}
static int F_42 ( struct V_63 * V_64 , const T_3 * V_65 ,
unsigned int V_25 )
{
struct V_56 * V_57 = F_43 ( V_64 ) ;
struct V_58 * V_52 = F_41 ( V_57 ) ;
int V_66 ;
int V_26 ;
int V_67 ;
int V_68 ;
V_67 = F_44 ( & V_52 -> V_69 , V_65 , V_25 ) ;
if ( V_67 ) {
F_45 ( V_64 , V_70 ) ;
return V_67 ;
}
V_66 = ( V_52 -> V_69 . V_71 - 16 ) / 4 ;
V_26 = V_52 -> V_69 . V_71 + 24 - V_66 ;
for ( V_68 = 0 ; V_68 < V_66 ; V_68 ++ )
V_52 -> V_69 . V_72 [ 4 + V_68 ] =
F_46 ( V_52 -> V_69 . V_73 [ V_26 + V_68 ] ) ;
return 0 ;
}
static int F_47 ( struct V_63 * V_64 , const T_3 * V_65 ,
unsigned int V_25 )
{
struct V_56 * V_57 = F_43 ( V_64 ) ;
struct V_74 * V_52 = F_41 ( V_57 ) ;
T_2 V_75 [ V_76 ] ;
int V_67 ;
if ( V_25 != V_77 ) {
F_45 ( V_64 , V_70 ) ;
return - V_78 ;
}
V_67 = F_48 ( V_75 , V_65 ) ;
if ( ! V_67 && ( V_57 -> V_79 & V_80 ) ) {
V_57 -> V_79 |= V_81 ;
return - V_78 ;
}
memcpy ( V_52 -> V_65 , V_65 , V_77 ) ;
return 0 ;
}
static int F_49 ( struct V_63 * V_64 ,
const T_3 * V_65 , unsigned int V_25 )
{
struct V_56 * V_57 = F_43 ( V_64 ) ;
struct V_74 * V_52 = F_41 ( V_57 ) ;
if ( V_25 != V_82 ) {
F_45 ( V_64 , V_70 ) ;
return - V_78 ;
}
memcpy ( V_52 -> V_65 , V_65 , V_82 ) ;
return 0 ;
}
static int F_50 ( struct V_3 * V_4 ,
const struct V_83 * V_84 )
{
struct V_12 * V_13 = F_7 ( V_4 ) ;
T_4 V_85 = ( V_4 -> V_5 . V_85 & V_86 ) ?
V_87 : V_88 ;
struct V_44 * V_45 = & V_13 -> V_5 ;
struct V_1 V_2 ;
bool V_32 = false ;
int V_67 ;
unsigned int V_47 ;
V_45 -> V_50 . V_89 = NULL ;
V_45 -> V_50 . V_51 = NULL ;
if ( V_4 -> V_7 != V_4 -> V_9 ) {
V_67 = F_51 ( V_14 -> V_15 , V_4 -> V_7 , V_13 -> V_17 ,
V_8 ) ;
if ( ! V_67 )
return - V_90 ;
V_67 = F_51 ( V_14 -> V_15 , V_4 -> V_9 , V_13 -> V_16 ,
V_10 ) ;
if ( ! V_67 ) {
V_67 = - V_90 ;
goto V_91;
}
} else {
V_67 = F_51 ( V_14 -> V_15 , V_4 -> V_7 , V_13 -> V_17 ,
V_18 ) ;
if ( ! V_67 )
return - V_90 ;
}
F_52 ( & V_45 -> V_50 ) ;
F_1 ( & V_2 , V_4 ) ;
do {
struct V_83 * V_28 ;
V_28 = F_53 ( & V_45 -> V_50 , V_84 , V_32 , V_85 ) ;
if ( F_54 ( V_28 ) ) {
V_67 = F_55 ( V_28 ) ;
goto V_92;
}
V_32 = true ;
F_17 ( V_28 , V_2 . V_5 . V_93 ) ;
V_67 = F_56 ( & V_45 -> V_50 , & V_2 . V_5 ,
& V_2 . V_7 , V_85 ) ;
if ( V_67 )
goto V_92;
V_67 = F_57 ( & V_45 -> V_50 , V_85 ) ;
if ( V_67 )
goto V_92;
V_67 = F_56 ( & V_45 -> V_50 , & V_2 . V_5 ,
& V_2 . V_9 , V_85 ) ;
if ( V_67 )
goto V_92;
} while ( F_4 ( & V_2 ) );
V_47 = F_37 ( F_38 ( V_4 ) ) ;
V_67 = F_58 ( & V_45 -> V_50 , V_94 ,
V_30 ,
V_95 , V_85 ) ;
if ( V_67 )
goto V_92;
V_45 -> V_50 . V_51 -> V_85 |= V_96 ;
return 0 ;
V_92:
F_9 ( V_45 ) ;
if ( V_4 -> V_9 != V_4 -> V_7 )
F_8 ( V_14 -> V_15 , V_4 -> V_9 , V_13 -> V_16 ,
V_10 ) ;
V_91:
F_8 ( V_14 -> V_15 , V_4 -> V_7 , V_13 -> V_17 ,
V_4 -> V_9 != V_4 -> V_7 ? V_8 : V_18 ) ;
return V_67 ;
}
static inline int
F_59 ( struct V_3 * V_4 ,
const struct V_83 * V_84 )
{
struct V_12 * V_13 = F_7 ( V_4 ) ;
struct V_20 * V_21 = & V_13 -> V_22 ;
struct V_44 * V_45 = & V_13 -> V_5 ;
V_21 -> V_28 = * V_84 ;
V_21 -> V_32 = false ;
V_45 -> V_50 . V_89 = NULL ;
V_45 -> V_50 . V_51 = NULL ;
return 0 ;
}
static int F_60 ( struct V_3 * V_4 ,
struct V_83 * V_97 )
{
struct V_12 * V_13 = F_7 ( V_4 ) ;
struct V_63 * V_57 = F_38 ( V_4 ) ;
unsigned int V_98 = F_61 ( V_57 ) ;
int V_67 ;
if ( ! F_62 ( V_4 -> V_6 , V_98 ) )
return - V_78 ;
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
F_65 ( V_97 , V_99 ,
V_100 ) ;
if ( V_14 -> V_101 -> V_102 )
V_67 = F_50 ( V_4 , V_97 ) ;
else
V_67 = F_59 ( V_4 , V_97 ) ;
return V_67 ;
}
static int F_66 ( struct V_3 * V_4 ,
struct V_83 * V_97 )
{
int V_67 ;
struct V_12 * V_13 = F_7 ( V_4 ) ;
struct V_23 * V_24 ;
V_67 = F_60 ( V_4 , V_97 ) ;
if ( V_67 )
return V_67 ;
V_24 = F_67 ( V_4 -> V_6 ) ;
F_33 ( & V_4 -> V_5 , V_24 ) ;
V_67 = F_68 ( & V_4 -> V_5 , & V_13 -> V_5 ) ;
if ( F_69 ( & V_4 -> V_5 , V_67 ) )
F_10 ( V_4 ) ;
return V_67 ;
}
static int F_70 ( struct V_3 * V_4 ,
struct V_83 * V_97 )
{
struct V_74 * V_52 = F_41 ( V_4 -> V_5 . V_57 ) ;
F_65 ( V_97 , V_103 ,
V_104 ) ;
memcpy ( V_97 -> V_52 . V_53 . V_65 , V_52 -> V_65 , V_77 ) ;
return F_66 ( V_4 , V_97 ) ;
}
static int F_71 ( struct V_3 * V_4 )
{
struct V_83 V_97 ;
F_72 ( & V_97 ,
V_105 |
V_106 ) ;
return F_70 ( V_4 , & V_97 ) ;
}
static int F_73 ( struct V_3 * V_4 )
{
struct V_83 V_97 ;
F_72 ( & V_97 ,
V_105 |
V_107 ) ;
return F_70 ( V_4 , & V_97 ) ;
}
static int F_74 ( struct V_3 * V_4 ,
struct V_83 * V_97 )
{
F_65 ( V_97 , V_108 ,
V_109 ) ;
memcpy ( V_97 -> V_52 . V_53 . V_54 , V_4 -> V_49 , V_110 ) ;
return F_70 ( V_4 , V_97 ) ;
}
static int F_75 ( struct V_3 * V_4 )
{
struct V_83 V_97 ;
F_72 ( & V_97 , V_106 ) ;
return F_74 ( V_4 , & V_97 ) ;
}
static int F_76 ( struct V_3 * V_4 )
{
struct V_83 V_97 ;
F_72 ( & V_97 , V_107 ) ;
return F_74 ( V_4 , & V_97 ) ;
}
static int F_77 ( struct V_3 * V_4 ,
struct V_83 * V_97 )
{
struct V_111 * V_52 = F_41 ( V_4 -> V_5 . V_57 ) ;
F_65 ( V_97 , V_112 ,
V_104 ) ;
memcpy ( V_97 -> V_52 . V_53 . V_65 , V_52 -> V_65 , V_82 ) ;
return F_66 ( V_4 , V_97 ) ;
}
static int F_78 ( struct V_3 * V_4 )
{
struct V_83 V_97 ;
F_72 ( & V_97 ,
V_105 |
V_113 |
V_106 ) ;
return F_77 ( V_4 , & V_97 ) ;
}
static int F_79 ( struct V_3 * V_4 )
{
struct V_83 V_97 ;
F_72 ( & V_97 ,
V_105 |
V_113 |
V_107 ) ;
return F_77 ( V_4 , & V_97 ) ;
}
static int F_80 ( struct V_3 * V_4 ,
struct V_83 * V_97 )
{
memcpy ( V_97 -> V_52 . V_53 . V_54 , V_4 -> V_49 , V_114 ) ;
return F_77 ( V_4 , V_97 ) ;
}
static int F_81 ( struct V_3 * V_4 )
{
struct V_83 V_97 ;
F_72 ( & V_97 ,
V_108 |
V_113 |
V_106 ) ;
return F_80 ( V_4 , & V_97 ) ;
}
static int F_82 ( struct V_3 * V_4 )
{
struct V_83 V_97 ;
F_72 ( & V_97 ,
V_108 |
V_113 |
V_107 ) ;
return F_80 ( V_4 , & V_97 ) ;
}
static int F_83 ( struct V_3 * V_4 ,
struct V_83 * V_97 )
{
struct V_58 * V_52 = F_41 ( V_4 -> V_5 . V_57 ) ;
int V_68 ;
T_2 * V_65 ;
T_2 V_115 ;
V_115 = V_116 ;
if ( F_84 ( V_97 ) & V_107 )
V_65 = V_52 -> V_69 . V_72 ;
else
V_65 = V_52 -> V_69 . V_73 ;
for ( V_68 = 0 ; V_68 < V_52 -> V_69 . V_71 / sizeof( T_2 ) ; V_68 ++ )
V_97 -> V_52 . V_53 . V_65 [ V_68 ] = F_46 ( V_65 [ V_68 ] ) ;
if ( V_52 -> V_69 . V_71 == 24 )
V_115 |= V_117 ;
else if ( V_52 -> V_69 . V_71 == 32 )
V_115 |= V_118 ;
F_65 ( V_97 , V_115 ,
V_104 |
V_119 ) ;
return F_66 ( V_4 , V_97 ) ;
}
static int F_85 ( struct V_3 * V_4 )
{
struct V_83 V_97 ;
F_72 ( & V_97 ,
V_105 |
V_106 ) ;
return F_83 ( V_4 , & V_97 ) ;
}
static int F_86 ( struct V_3 * V_4 )
{
struct V_83 V_97 ;
F_72 ( & V_97 ,
V_105 |
V_107 ) ;
return F_83 ( V_4 , & V_97 ) ;
}
static int F_87 ( struct V_3 * V_4 ,
struct V_83 * V_97 )
{
F_65 ( V_97 , V_108 ,
V_109 ) ;
memcpy ( V_97 -> V_52 . V_53 . V_54 , V_4 -> V_49 , V_120 ) ;
return F_83 ( V_4 , V_97 ) ;
}
static int F_88 ( struct V_3 * V_4 )
{
struct V_83 V_97 ;
F_72 ( & V_97 , V_106 ) ;
return F_87 ( V_4 , & V_97 ) ;
}
static int F_89 ( struct V_3 * V_4 )
{
struct V_83 V_97 ;
F_72 ( & V_97 , V_107 ) ;
return F_87 ( V_4 , & V_97 ) ;
}
