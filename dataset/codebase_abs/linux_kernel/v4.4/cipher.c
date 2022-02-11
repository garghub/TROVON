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
F_9 ( & V_13 -> V_4 . V_19 ) ;
}
static inline void F_10 ( struct V_3 * V_4 )
{
struct V_12 * V_13 = F_7 ( V_4 ) ;
if ( V_13 -> V_4 . V_5 . type == V_20 )
F_6 ( V_4 ) ;
}
static void F_11 ( struct V_3 * V_4 )
{
struct V_12 * V_13 = F_7 ( V_4 ) ;
struct V_21 * V_22 = & V_13 -> V_4 . V_23 ;
struct V_24 * V_25 = V_22 -> V_5 . V_25 ;
T_1 V_26 = F_12 ( T_1 , V_4 -> V_6 - V_22 -> V_27 ,
V_28 ) ;
V_26 = F_13 ( V_4 -> V_7 , V_13 -> V_17 ,
V_25 -> V_29 + V_30 ,
V_26 , V_22 -> V_27 ) ;
V_22 -> V_31 = V_26 ;
F_14 ( & V_22 -> V_32 , V_26 ) ;
if ( ! V_22 -> V_33 ) {
F_15 ( V_25 -> V_29 , & V_22 -> V_32 , sizeof( V_22 -> V_32 ) ) ;
V_22 -> V_33 = true ;
} else {
F_15 ( V_25 -> V_29 , & V_22 -> V_32 , sizeof( V_22 -> V_32 . V_34 ) ) ;
}
F_16 ( V_25 , V_35 ) ;
F_17 ( V_36 , V_25 -> V_37 + V_38 ) ;
F_18 ( V_39 , V_25 -> V_37 + V_40 ) ;
}
static int F_19 ( struct V_3 * V_4 ,
T_2 V_41 )
{
struct V_12 * V_13 = F_7 ( V_4 ) ;
struct V_21 * V_22 = & V_13 -> V_4 . V_23 ;
struct V_24 * V_25 = V_22 -> V_5 . V_25 ;
T_1 V_26 ;
V_26 = F_20 ( V_4 -> V_9 , V_13 -> V_16 ,
V_25 -> V_29 + V_30 ,
V_22 -> V_31 , V_22 -> V_27 ) ;
V_22 -> V_27 += V_26 ;
if ( V_22 -> V_27 < V_4 -> V_6 )
return - V_42 ;
return 0 ;
}
static int F_21 ( struct V_43 * V_4 ,
T_2 V_41 )
{
struct V_3 * V_44 = F_22 ( V_4 ) ;
struct V_12 * V_13 = F_7 ( V_44 ) ;
struct V_21 * V_22 = & V_13 -> V_4 . V_23 ;
struct V_24 * V_25 = V_22 -> V_5 . V_25 ;
int V_45 ;
if ( V_13 -> V_4 . V_5 . type == V_20 )
V_45 = F_23 ( & V_13 -> V_4 . V_19 , V_41 ) ;
else
V_45 = F_19 ( V_44 , V_41 ) ;
if ( V_45 )
return V_45 ;
F_24 ( V_44 -> V_46 ,
V_25 -> V_29 + V_47 ,
F_25 ( F_26 ( V_44 ) ) ) ;
return 0 ;
}
static void F_27 ( struct V_43 * V_4 )
{
struct V_3 * V_44 = F_22 ( V_4 ) ;
struct V_12 * V_13 = F_7 ( V_44 ) ;
if ( V_13 -> V_4 . V_5 . type == V_20 )
F_28 ( & V_13 -> V_4 . V_19 ) ;
else
F_11 ( V_44 ) ;
}
static inline void
F_29 ( struct V_3 * V_4 )
{
struct V_12 * V_13 = F_7 ( V_4 ) ;
struct V_48 * V_49 = & V_13 -> V_4 . V_19 ;
F_30 ( V_49 , V_49 -> V_5 . V_25 ) ;
}
static inline void
F_31 ( struct V_3 * V_4 )
{
struct V_12 * V_13 = F_7 ( V_4 ) ;
struct V_21 * V_22 = & V_13 -> V_4 . V_23 ;
struct V_24 * V_25 = V_22 -> V_5 . V_25 ;
V_22 -> V_31 = 0 ;
V_22 -> V_27 = 0 ;
F_32 ( V_25 , & V_22 -> V_32 ) ;
F_15 ( V_25 -> V_29 , & V_22 -> V_32 , sizeof( V_22 -> V_32 ) ) ;
}
static inline void F_33 ( struct V_43 * V_4 ,
struct V_24 * V_25 )
{
struct V_3 * V_44 = F_22 ( V_4 ) ;
struct V_12 * V_13 = F_7 ( V_44 ) ;
V_13 -> V_4 . V_5 . V_25 = V_25 ;
if ( V_13 -> V_4 . V_5 . type == V_20 )
F_29 ( V_44 ) ;
else
F_31 ( V_44 ) ;
}
static inline void
F_34 ( struct V_43 * V_4 )
{
struct V_3 * V_44 = F_22 ( V_4 ) ;
F_10 ( V_44 ) ;
}
static int F_35 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = F_36 ( V_51 ) ;
V_53 -> V_5 . V_54 = & V_55 ;
V_51 -> V_56 . V_57 = sizeof( struct V_12 ) ;
return 0 ;
}
static int F_37 ( struct V_58 * V_59 , const T_3 * V_60 ,
unsigned int V_26 )
{
struct V_50 * V_51 = F_38 ( V_59 ) ;
struct V_52 * V_53 = F_36 ( V_51 ) ;
int V_61 ;
int V_27 ;
int V_45 ;
int V_62 ;
V_45 = F_39 ( & V_53 -> V_63 , V_60 , V_26 ) ;
if ( V_45 ) {
F_40 ( V_59 , V_64 ) ;
return V_45 ;
}
V_61 = ( V_53 -> V_63 . V_65 - 16 ) / 4 ;
V_27 = V_53 -> V_63 . V_65 + 24 - V_61 ;
for ( V_62 = 0 ; V_62 < V_61 ; V_62 ++ )
V_53 -> V_63 . V_66 [ 4 + V_62 ] =
F_41 ( V_53 -> V_63 . V_67 [ V_27 + V_62 ] ) ;
return 0 ;
}
static int F_42 ( struct V_58 * V_59 , const T_3 * V_60 ,
unsigned int V_26 )
{
struct V_50 * V_51 = F_38 ( V_59 ) ;
struct V_68 * V_53 = F_36 ( V_51 ) ;
T_2 V_69 [ V_70 ] ;
int V_45 ;
if ( V_26 != V_71 ) {
F_40 ( V_59 , V_64 ) ;
return - V_72 ;
}
V_45 = F_43 ( V_69 , V_60 ) ;
if ( ! V_45 && ( V_51 -> V_73 & V_74 ) ) {
V_51 -> V_73 |= V_75 ;
return - V_72 ;
}
memcpy ( V_53 -> V_60 , V_60 , V_71 ) ;
return 0 ;
}
static int F_44 ( struct V_58 * V_59 ,
const T_3 * V_60 , unsigned int V_26 )
{
struct V_50 * V_51 = F_38 ( V_59 ) ;
struct V_68 * V_53 = F_36 ( V_51 ) ;
if ( V_26 != V_76 ) {
F_40 ( V_59 , V_64 ) ;
return - V_72 ;
}
memcpy ( V_53 -> V_60 , V_60 , V_76 ) ;
return 0 ;
}
static int F_45 ( struct V_3 * V_4 ,
const struct V_77 * V_78 )
{
struct V_12 * V_13 = F_7 ( V_4 ) ;
T_4 V_79 = ( V_4 -> V_5 . V_79 & V_80 ) ?
V_81 : V_82 ;
struct V_48 * V_49 = & V_13 -> V_4 . V_19 ;
struct V_1 V_2 ;
struct V_83 V_84 ;
bool V_33 = false ;
int V_45 ;
V_49 -> V_5 . type = V_20 ;
V_49 -> V_84 . V_85 = NULL ;
V_49 -> V_84 . V_86 = NULL ;
if ( V_4 -> V_7 != V_4 -> V_9 ) {
V_45 = F_46 ( V_14 -> V_15 , V_4 -> V_7 , V_13 -> V_17 ,
V_8 ) ;
if ( ! V_45 )
return - V_87 ;
V_45 = F_46 ( V_14 -> V_15 , V_4 -> V_9 , V_13 -> V_16 ,
V_10 ) ;
if ( ! V_45 ) {
V_45 = - V_87 ;
goto V_88;
}
} else {
V_45 = F_46 ( V_14 -> V_15 , V_4 -> V_7 , V_13 -> V_17 ,
V_18 ) ;
if ( ! V_45 )
return - V_87 ;
}
F_47 ( & V_84 ) ;
F_1 ( & V_2 , V_4 ) ;
do {
struct V_77 * V_32 ;
V_32 = F_48 ( & V_84 , V_78 , V_33 , V_79 ) ;
if ( F_49 ( V_32 ) ) {
V_45 = F_50 ( V_32 ) ;
goto V_89;
}
V_33 = true ;
F_14 ( V_32 , V_2 . V_5 . V_90 ) ;
V_45 = F_51 ( & V_84 , & V_2 . V_5 ,
& V_2 . V_7 , V_79 ) ;
if ( V_45 )
goto V_89;
V_45 = F_52 ( & V_84 , V_79 ) ;
if ( V_45 )
goto V_89;
V_45 = F_51 ( & V_84 , & V_2 . V_5 ,
& V_2 . V_9 , V_79 ) ;
if ( V_45 )
goto V_89;
} while ( F_4 ( & V_2 ) );
V_49 -> V_84 = V_84 ;
return 0 ;
V_89:
F_9 ( V_49 ) ;
if ( V_4 -> V_9 != V_4 -> V_7 )
F_8 ( V_14 -> V_15 , V_4 -> V_9 , V_13 -> V_16 ,
V_10 ) ;
V_88:
F_8 ( V_14 -> V_15 , V_4 -> V_7 , V_13 -> V_17 ,
V_4 -> V_9 != V_4 -> V_7 ? V_8 : V_18 ) ;
return V_45 ;
}
static inline int
F_53 ( struct V_3 * V_4 ,
const struct V_77 * V_78 )
{
struct V_12 * V_13 = F_7 ( V_4 ) ;
struct V_21 * V_22 = & V_13 -> V_4 . V_23 ;
V_22 -> V_5 . type = V_91 ;
V_22 -> V_32 = * V_78 ;
V_22 -> V_33 = false ;
return 0 ;
}
static int F_54 ( struct V_3 * V_4 ,
struct V_77 * V_92 )
{
struct V_12 * V_13 = F_7 ( V_4 ) ;
struct V_58 * V_51 = F_26 ( V_4 ) ;
unsigned int V_93 = F_55 ( V_51 ) ;
int V_45 ;
if ( ! F_56 ( V_4 -> V_6 , V_93 ) )
return - V_72 ;
V_13 -> V_17 = F_57 ( V_4 -> V_7 , V_4 -> V_6 ) ;
V_13 -> V_16 = F_57 ( V_4 -> V_9 , V_4 -> V_6 ) ;
F_58 ( V_92 , V_94 ,
V_95 ) ;
if ( V_14 -> V_96 -> V_97 )
V_45 = F_45 ( V_4 , V_92 ) ;
else
V_45 = F_53 ( V_4 , V_92 ) ;
return V_45 ;
}
static int F_59 ( struct V_3 * V_4 ,
struct V_77 * V_92 )
{
struct V_68 * V_53 = F_36 ( V_4 -> V_5 . V_51 ) ;
int V_45 ;
F_58 ( V_92 , V_98 ,
V_99 ) ;
memcpy ( V_92 -> V_53 . V_100 . V_60 , V_53 -> V_60 , V_71 ) ;
V_45 = F_54 ( V_4 , V_92 ) ;
if ( V_45 )
return V_45 ;
V_45 = F_60 ( & V_4 -> V_5 ) ;
if ( F_61 ( & V_4 -> V_5 , V_45 ) )
F_10 ( V_4 ) ;
return V_45 ;
}
static int F_62 ( struct V_3 * V_4 )
{
struct V_77 V_92 ;
F_63 ( & V_92 ,
V_101 |
V_102 ) ;
return F_59 ( V_4 , & V_92 ) ;
}
static int F_64 ( struct V_3 * V_4 )
{
struct V_77 V_92 ;
F_63 ( & V_92 ,
V_101 |
V_103 ) ;
return F_59 ( V_4 , & V_92 ) ;
}
static int F_65 ( struct V_3 * V_4 ,
struct V_77 * V_92 )
{
F_58 ( V_92 , V_104 ,
V_105 ) ;
memcpy ( V_92 -> V_53 . V_100 . V_106 , V_4 -> V_46 , V_107 ) ;
return F_59 ( V_4 , V_92 ) ;
}
static int F_66 ( struct V_3 * V_4 )
{
struct V_77 V_92 ;
F_63 ( & V_92 , V_102 ) ;
return F_65 ( V_4 , & V_92 ) ;
}
static int F_67 ( struct V_3 * V_4 )
{
struct V_77 V_92 ;
F_63 ( & V_92 , V_103 ) ;
return F_65 ( V_4 , & V_92 ) ;
}
static int F_68 ( struct V_3 * V_4 ,
struct V_77 * V_92 )
{
struct V_108 * V_53 = F_36 ( V_4 -> V_5 . V_51 ) ;
int V_45 ;
F_58 ( V_92 , V_109 ,
V_99 ) ;
memcpy ( V_92 -> V_53 . V_100 . V_60 , V_53 -> V_60 , V_76 ) ;
V_45 = F_54 ( V_4 , V_92 ) ;
if ( V_45 )
return V_45 ;
V_45 = F_60 ( & V_4 -> V_5 ) ;
if ( F_61 ( & V_4 -> V_5 , V_45 ) )
F_10 ( V_4 ) ;
return V_45 ;
}
static int F_69 ( struct V_3 * V_4 )
{
struct V_77 V_92 ;
F_63 ( & V_92 ,
V_101 |
V_110 |
V_102 ) ;
return F_68 ( V_4 , & V_92 ) ;
}
static int F_70 ( struct V_3 * V_4 )
{
struct V_77 V_92 ;
F_63 ( & V_92 ,
V_101 |
V_110 |
V_103 ) ;
return F_68 ( V_4 , & V_92 ) ;
}
static int F_71 ( struct V_3 * V_4 ,
struct V_77 * V_92 )
{
memcpy ( V_92 -> V_53 . V_100 . V_106 , V_4 -> V_46 , V_111 ) ;
return F_68 ( V_4 , V_92 ) ;
}
static int F_72 ( struct V_3 * V_4 )
{
struct V_77 V_92 ;
F_63 ( & V_92 ,
V_104 |
V_110 |
V_102 ) ;
return F_71 ( V_4 , & V_92 ) ;
}
static int F_73 ( struct V_3 * V_4 )
{
struct V_77 V_92 ;
F_63 ( & V_92 ,
V_104 |
V_110 |
V_103 ) ;
return F_71 ( V_4 , & V_92 ) ;
}
static int F_74 ( struct V_3 * V_4 ,
struct V_77 * V_92 )
{
struct V_52 * V_53 = F_36 ( V_4 -> V_5 . V_51 ) ;
int V_45 , V_62 ;
T_2 * V_60 ;
T_2 V_112 ;
V_112 = V_113 ;
if ( F_75 ( V_92 ) & V_103 )
V_60 = V_53 -> V_63 . V_66 ;
else
V_60 = V_53 -> V_63 . V_67 ;
for ( V_62 = 0 ; V_62 < V_53 -> V_63 . V_65 / sizeof( T_2 ) ; V_62 ++ )
V_92 -> V_53 . V_100 . V_60 [ V_62 ] = F_41 ( V_60 [ V_62 ] ) ;
if ( V_53 -> V_63 . V_65 == 24 )
V_112 |= V_114 ;
else if ( V_53 -> V_63 . V_65 == 32 )
V_112 |= V_115 ;
F_58 ( V_92 , V_112 ,
V_99 |
V_116 ) ;
V_45 = F_54 ( V_4 , V_92 ) ;
if ( V_45 )
return V_45 ;
V_45 = F_60 ( & V_4 -> V_5 ) ;
if ( F_61 ( & V_4 -> V_5 , V_45 ) )
F_10 ( V_4 ) ;
return V_45 ;
}
static int F_76 ( struct V_3 * V_4 )
{
struct V_77 V_92 ;
F_63 ( & V_92 ,
V_101 |
V_102 ) ;
return F_74 ( V_4 , & V_92 ) ;
}
static int F_77 ( struct V_3 * V_4 )
{
struct V_77 V_92 ;
F_63 ( & V_92 ,
V_101 |
V_103 ) ;
return F_74 ( V_4 , & V_92 ) ;
}
static int F_78 ( struct V_3 * V_4 ,
struct V_77 * V_92 )
{
F_58 ( V_92 , V_104 ,
V_105 ) ;
memcpy ( V_92 -> V_53 . V_100 . V_106 , V_4 -> V_46 , V_117 ) ;
return F_74 ( V_4 , V_92 ) ;
}
static int F_79 ( struct V_3 * V_4 )
{
struct V_77 V_92 ;
F_63 ( & V_92 , V_102 ) ;
return F_78 ( V_4 , & V_92 ) ;
}
static int F_80 ( struct V_3 * V_4 )
{
struct V_77 V_92 ;
F_63 ( & V_92 , V_103 ) ;
return F_78 ( V_4 , & V_92 ) ;
}
