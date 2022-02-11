static inline
void F_1 ( struct V_1 * V_2 , enum V_3 V_4 )
{
V_2 -> V_5 |= ( ( ( V_6 ) V_4 ) & 0xFF ) << 24 ;
}
static inline
enum V_3 F_2 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 >> 24 ) & 0xFF ;
}
static int F_3 ( struct V_7 * V_8 )
{
F_4 () ;
return 0 ;
}
static
int F_5 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
V_10 -> V_11 -> V_5 = V_12 ;
if ( ! V_10 -> V_13 -> V_14 ) {
struct V_15 * V_16 = V_10 -> V_13 -> V_17 ;
F_1 ( V_10 -> V_11 ,
V_16 -> V_18 . V_19 . V_20 ) ;
}
V_10 -> V_21 = V_10 -> V_22 ;
return 0 ;
}
static
int F_6 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
V_6 V_23 , V_24 ;
F_7 ( V_10 -> V_25 ) ;
V_10 -> V_26 = V_10 -> V_25 ;
V_10 -> V_27 = V_10 -> V_28 ;
if ( V_10 -> V_29 ) {
V_23 = F_8 ( V_10 -> V_25 ) ;
V_24 = F_9 ( V_10 -> V_26 ) ;
if ( V_24 != V_23 ) {
F_10 ( V_30 ,
L_1 ,
V_24 , V_23 ) ;
return - V_31 ;
}
}
return 0 ;
}
static
struct V_32 * F_11 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
struct V_37 * V_38 )
{
F_7 ( F_12 ( V_38 -> V_39 ) == V_40 ) ;
F_13 ( & V_41 ) ;
return & V_42 ;
}
static
void F_14 ( struct V_32 * V_43 )
{
F_7 ( V_43 == & V_42 ) ;
}
static
struct V_7 * F_15 ( struct V_32 * V_43 ,
struct V_44 * V_45 ,
int V_46 , int V_47 )
{
F_16 ( & V_48 . V_49 ) ;
return & V_48 ;
}
static
int F_17 ( struct V_32 * V_43 ,
T_1 V_50 ,
int V_51 , int V_52 )
{
return 0 ;
}
static
int F_18 ( struct V_32 * V_43 ,
struct V_9 * V_10 ,
int V_53 )
{
if ( ! V_10 -> V_11 ) {
int V_54 = F_19 ( V_53 ) ;
F_7 ( ! V_10 -> V_55 ) ;
F_20 ( V_10 -> V_11 , V_54 ) ;
if ( ! V_10 -> V_11 )
return - V_56 ;
V_10 -> V_57 = V_54 ;
} else {
F_7 ( V_10 -> V_55 ) ;
F_7 ( V_10 -> V_57 >= V_53 ) ;
memset ( V_10 -> V_11 , 0 , V_53 ) ;
}
V_10 -> V_58 = V_10 -> V_11 ;
return 0 ;
}
static
void F_21 ( struct V_32 * V_43 ,
struct V_9 * V_10 )
{
if ( ! V_10 -> V_55 ) {
F_22 ( V_10 -> V_58 == V_10 -> V_11 ,
L_2 ,
V_10 , V_10 -> V_58 , V_10 -> V_11 ) ;
F_22 ( V_10 -> V_57 >= V_10 -> V_22 ,
L_3 ,
V_10 , V_10 -> V_22 , V_10 -> V_57 ) ;
F_23 ( V_10 -> V_11 , V_10 -> V_57 ) ;
V_10 -> V_11 = NULL ;
V_10 -> V_57 = 0 ;
}
}
static
int F_24 ( struct V_32 * V_43 ,
struct V_9 * V_10 ,
int V_53 )
{
V_53 += F_25 () ;
V_53 = F_19 ( V_53 ) ;
F_20 ( V_10 -> V_59 , V_53 ) ;
if ( ! V_10 -> V_59 )
return - V_56 ;
V_10 -> V_60 = V_53 ;
return 0 ;
}
static
void F_26 ( struct V_32 * V_43 ,
struct V_9 * V_10 )
{
F_7 ( V_10 -> V_59 ) ;
F_23 ( V_10 -> V_59 , V_10 -> V_60 ) ;
V_10 -> V_59 = NULL ;
V_10 -> V_60 = 0 ;
}
static
int F_27 ( struct V_32 * V_43 ,
struct V_9 * V_10 ,
int V_61 , int V_62 )
{
struct V_1 * V_63 ;
struct V_1 * V_64 = V_10 -> V_58 ;
int V_65 , V_66 , V_54 ;
F_7 ( V_10 -> V_11 ) ;
F_7 ( V_10 -> V_11 == V_10 -> V_58 ) ;
F_7 ( V_10 -> V_57 >= V_10 -> V_22 ) ;
F_7 ( V_10 -> V_22 == F_28 ( V_64 ) ) ;
V_65 = V_10 -> V_11 -> V_67 [ V_61 ] ;
V_10 -> V_11 -> V_67 [ V_61 ] = V_62 ;
V_66 = F_28 ( V_64 ) ;
V_10 -> V_11 -> V_67 [ V_61 ] = V_65 ;
F_7 ( ! V_10 -> V_55 || V_10 -> V_57 >= V_66 ) ;
if ( V_10 -> V_57 < V_66 ) {
V_54 = F_19 ( V_66 ) ;
F_20 ( V_63 , V_54 ) ;
if ( V_63 == NULL )
return - V_56 ;
if ( V_10 -> V_13 )
F_29 ( & V_10 -> V_13 -> V_68 ) ;
memcpy ( V_63 , V_10 -> V_11 , V_10 -> V_22 ) ;
F_23 ( V_10 -> V_11 , V_10 -> V_57 ) ;
V_10 -> V_11 = V_10 -> V_58 = V_63 ;
V_10 -> V_57 = V_54 ;
if ( V_10 -> V_13 )
F_30 ( & V_10 -> V_13 -> V_68 ) ;
}
F_31 ( V_10 -> V_58 , V_61 , V_62 ) ;
V_10 -> V_22 = V_66 ;
return 0 ;
}
static
int F_32 ( struct V_9 * V_10 )
{
F_7 ( F_12 ( V_10 -> V_69 . V_39 ) ==
V_40 ) ;
if ( V_10 -> V_69 . V_39 != V_12 ) {
F_33 ( L_4 , V_10 -> V_69 . V_39 ) ;
return V_70 ;
}
V_10 -> V_71 = F_2 ( V_10 -> V_11 ) ;
V_10 -> V_58 = V_10 -> V_11 ;
V_10 -> V_22 = V_10 -> V_21 ;
V_10 -> V_72 = & V_73 ;
F_16 ( & V_10 -> V_72 -> V_74 ) ;
return V_75 ;
}
static
int F_34 ( struct V_9 * V_10 , int V_53 )
{
struct V_76 * V_77 ;
int V_78 = sizeof( * V_77 ) + V_53 ;
F_7 ( V_53 % 8 == 0 ) ;
V_77 = V_10 -> V_79 ;
if ( V_77 ) {
F_7 ( V_77 -> V_78 >= V_78 ) ;
} else {
F_20 ( V_77 , V_78 ) ;
if ( V_77 == NULL )
return - V_56 ;
V_77 -> V_78 = V_78 ;
}
V_77 -> V_80 = V_10 -> V_72 ;
F_16 ( & V_10 -> V_72 -> V_74 ) ;
V_77 -> V_81 = (struct V_1 * ) ( V_77 + 1 ) ;
V_77 -> V_82 = V_78 - sizeof( * V_77 ) ;
V_77 -> V_83 = V_77 -> V_81 ;
V_10 -> V_79 = V_77 ;
return 0 ;
}
static
void F_35 ( struct V_76 * V_77 )
{
F_36 ( & V_77 -> V_80 -> V_74 , 1 ) ;
F_37 ( & V_77 -> V_80 -> V_74 ) ;
if ( ! V_77 -> V_84 )
F_23 ( V_77 , V_77 -> V_78 ) ;
}
static
int F_38 ( struct V_9 * V_10 )
{
struct V_76 * V_77 = V_10 -> V_79 ;
F_7 ( V_77 ) ;
V_77 -> V_81 -> V_5 = V_12 ;
V_77 -> V_85 = V_10 -> V_27 ;
if ( F_39 ( V_10 -> V_86 ) ) {
if ( F_40 ( V_10 -> V_58 ) & V_87 )
V_10 -> V_88 = F_25 () ;
else
V_10 -> V_88 = 0 ;
} else {
V_6 V_89 ;
V_89 = F_9 ( V_77 -> V_81 ) ;
F_41 ( V_77 -> V_81 , V_89 ) ;
V_10 -> V_88 = 0 ;
}
return 0 ;
}
static void F_42 ( void )
{
static F_43 ( V_90 ) ;
V_42 . V_91 = & V_41 ;
F_44 ( & V_42 . V_92 , 1 ) ;
V_42 . V_93 = - 1 ;
V_42 . V_94 = NULL ;
V_42 . V_95 . V_39 = V_12 ;
V_42 . V_95 . V_96 = 0 ;
V_42 . V_97 = V_98 ;
V_42 . V_99 = 0 ;
F_45 ( & V_42 . V_100 ) ;
F_44 ( & V_42 . V_101 , 1 ) ;
F_46 ( & V_42 . V_102 ) ;
V_42 . V_103 = 0 ;
V_42 . V_104 = 0 ;
F_47 ( & V_48 . V_105 , & V_90 ) ;
F_44 ( & V_48 . V_49 , 1 ) ;
V_48 . V_106 = & V_42 ;
V_48 . V_107 = & V_108 ;
V_48 . V_109 = 0 ;
V_48 . V_110 = V_111 | V_112 |
V_113 ;
V_48 . V_114 . V_115 = 0 ;
F_45 ( & V_48 . V_116 ) ;
F_46 ( & V_48 . V_117 ) ;
F_46 ( & V_48 . V_118 ) ;
}
int F_48 ( void )
{
int V_119 ;
F_42 () ;
V_119 = F_49 ( & V_41 ) ;
if ( V_119 )
F_33 ( L_5 , V_41 . V_120 , V_119 ) ;
return V_119 ;
}
void F_50 ( void )
{
int V_119 ;
V_119 = F_51 ( & V_41 ) ;
if ( V_119 )
F_33 ( L_6 ,
V_41 . V_120 , V_119 ) ;
}
