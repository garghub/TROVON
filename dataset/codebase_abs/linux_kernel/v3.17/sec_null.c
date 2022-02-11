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
#if V_30 < F_9 ( 2 , 7 , 50 , 0 )
if ( F_10 ( V_10 -> V_31 ) &
V_32 )
V_24 = F_11 ( V_10 -> V_26 , 0 ) ;
else
V_24 = F_11 ( V_10 -> V_26 , 1 ) ;
#else
# warning "remove checksum compatibility support for b1_8"
V_24 = F_11 ( V_10 -> V_26 ) ;
#endif
if ( V_24 != V_23 ) {
F_12 ( V_33 ,
L_1 ,
V_24 , V_23 ) ;
return - V_34 ;
}
}
return 0 ;
}
static
struct V_35 * F_13 ( struct V_36 * V_37 ,
struct V_38 * V_39 ,
struct V_40 * V_41 )
{
F_7 ( F_14 ( V_41 -> V_42 ) == V_43 ) ;
F_15 ( & V_44 ) ;
return & V_45 ;
}
static
void F_16 ( struct V_35 * V_46 )
{
F_7 ( V_46 == & V_45 ) ;
}
static
struct V_7 * F_17 ( struct V_35 * V_46 ,
struct V_47 * V_48 ,
int V_49 , int V_50 )
{
F_18 ( & V_51 . V_52 ) ;
return & V_51 ;
}
static
int F_19 ( struct V_35 * V_46 ,
T_1 V_53 ,
int V_54 , int V_55 )
{
return 0 ;
}
static
int F_20 ( struct V_35 * V_46 ,
struct V_9 * V_10 ,
int V_56 )
{
if ( ! V_10 -> V_11 ) {
int V_57 = F_21 ( V_56 ) ;
F_7 ( ! V_10 -> V_58 ) ;
F_22 ( V_10 -> V_11 , V_57 ) ;
if ( ! V_10 -> V_11 )
return - V_59 ;
V_10 -> V_60 = V_57 ;
} else {
F_7 ( V_10 -> V_58 ) ;
F_7 ( V_10 -> V_60 >= V_56 ) ;
memset ( V_10 -> V_11 , 0 , V_56 ) ;
}
V_10 -> V_31 = V_10 -> V_11 ;
return 0 ;
}
static
void F_23 ( struct V_35 * V_46 ,
struct V_9 * V_10 )
{
if ( ! V_10 -> V_58 ) {
F_24 ( V_10 -> V_31 == V_10 -> V_11 ,
L_2 ,
V_10 , V_10 -> V_31 , V_10 -> V_11 ) ;
F_24 ( V_10 -> V_60 >= V_10 -> V_22 ,
L_3 ,
V_10 , V_10 -> V_22 , V_10 -> V_60 ) ;
F_25 ( V_10 -> V_11 , V_10 -> V_60 ) ;
V_10 -> V_11 = NULL ;
V_10 -> V_60 = 0 ;
}
}
static
int F_26 ( struct V_35 * V_46 ,
struct V_9 * V_10 ,
int V_56 )
{
V_56 += F_27 () ;
V_56 = F_21 ( V_56 ) ;
F_22 ( V_10 -> V_61 , V_56 ) ;
if ( ! V_10 -> V_61 )
return - V_59 ;
V_10 -> V_62 = V_56 ;
return 0 ;
}
static
void F_28 ( struct V_35 * V_46 ,
struct V_9 * V_10 )
{
F_7 ( V_10 -> V_61 ) ;
F_25 ( V_10 -> V_61 , V_10 -> V_62 ) ;
V_10 -> V_61 = NULL ;
V_10 -> V_62 = 0 ;
}
static
int F_29 ( struct V_35 * V_46 ,
struct V_9 * V_10 ,
int V_63 , int V_64 )
{
struct V_1 * V_65 ;
struct V_1 * V_66 = V_10 -> V_31 ;
int V_67 , V_68 , V_57 ;
F_7 ( V_10 -> V_11 ) ;
F_7 ( V_10 -> V_11 == V_10 -> V_31 ) ;
F_7 ( V_10 -> V_60 >= V_10 -> V_22 ) ;
F_7 ( V_10 -> V_22 == F_30 ( V_66 ) ) ;
V_67 = V_10 -> V_11 -> V_69 [ V_63 ] ;
V_10 -> V_11 -> V_69 [ V_63 ] = V_64 ;
V_68 = F_30 ( V_66 ) ;
V_10 -> V_11 -> V_69 [ V_63 ] = V_67 ;
F_7 ( ! V_10 -> V_58 || V_10 -> V_60 >= V_68 ) ;
if ( V_10 -> V_60 < V_68 ) {
V_57 = F_21 ( V_68 ) ;
F_22 ( V_65 , V_57 ) ;
if ( V_65 == NULL )
return - V_59 ;
if ( V_10 -> V_13 )
F_31 ( & V_10 -> V_13 -> V_70 ) ;
memcpy ( V_65 , V_10 -> V_11 , V_10 -> V_22 ) ;
F_25 ( V_10 -> V_11 , V_10 -> V_60 ) ;
V_10 -> V_11 = V_10 -> V_31 = V_65 ;
V_10 -> V_60 = V_57 ;
if ( V_10 -> V_13 )
F_32 ( & V_10 -> V_13 -> V_70 ) ;
}
F_33 ( V_10 -> V_31 , V_63 , V_64 ) ;
V_10 -> V_22 = V_68 ;
return 0 ;
}
static
int F_34 ( struct V_9 * V_10 )
{
F_7 ( F_14 ( V_10 -> V_71 . V_42 ) ==
V_43 ) ;
if ( V_10 -> V_71 . V_42 != V_12 ) {
F_35 ( L_4 , V_10 -> V_71 . V_42 ) ;
return V_72 ;
}
V_10 -> V_73 = F_2 ( V_10 -> V_11 ) ;
V_10 -> V_31 = V_10 -> V_11 ;
V_10 -> V_22 = V_10 -> V_21 ;
V_10 -> V_74 = & V_75 ;
F_18 ( & V_10 -> V_74 -> V_76 ) ;
return V_77 ;
}
static
int F_36 ( struct V_9 * V_10 , int V_56 )
{
struct V_78 * V_79 ;
int V_80 = sizeof( * V_79 ) + V_56 ;
F_7 ( V_56 % 8 == 0 ) ;
V_79 = V_10 -> V_81 ;
if ( V_79 ) {
F_7 ( V_79 -> V_80 >= V_80 ) ;
} else {
F_22 ( V_79 , V_80 ) ;
if ( V_79 == NULL )
return - V_59 ;
V_79 -> V_80 = V_80 ;
}
V_79 -> V_82 = V_10 -> V_74 ;
F_18 ( & V_10 -> V_74 -> V_76 ) ;
V_79 -> V_83 = (struct V_1 * ) ( V_79 + 1 ) ;
V_79 -> V_84 = V_80 - sizeof( * V_79 ) ;
V_79 -> V_85 = V_79 -> V_83 ;
V_10 -> V_81 = V_79 ;
return 0 ;
}
static
void F_37 ( struct V_78 * V_79 )
{
F_38 ( & V_79 -> V_82 -> V_76 , 1 ) ;
F_39 ( & V_79 -> V_82 -> V_76 ) ;
if ( ! V_79 -> V_86 )
F_25 ( V_79 , V_79 -> V_80 ) ;
}
static
int F_40 ( struct V_9 * V_10 )
{
struct V_78 * V_79 = V_10 -> V_81 ;
F_7 ( V_79 ) ;
V_79 -> V_83 -> V_5 = V_12 ;
V_79 -> V_87 = V_10 -> V_27 ;
if ( F_41 ( V_10 -> V_88 ) ) {
if ( F_10 ( V_10 -> V_31 ) & V_89 )
V_10 -> V_90 = F_27 () ;
else
V_10 -> V_90 = 0 ;
} else {
V_6 V_91 ;
#if V_30 < F_9 ( 2 , 7 , 50 , 0 )
if ( F_10 ( V_10 -> V_31 ) &
V_32 )
V_91 = F_11 ( V_79 -> V_83 , 0 ) ;
else
V_91 = F_11 ( V_79 -> V_83 , 1 ) ;
#else
# warning "remove checksum compatibility support for b1_8"
V_91 = F_11 ( V_79 -> V_83 ) ;
#endif
F_42 ( V_79 -> V_83 , V_91 ) ;
V_10 -> V_90 = 0 ;
}
return 0 ;
}
static void F_43 ( void )
{
static F_44 ( V_92 ) ;
V_45 . V_93 = & V_44 ;
F_45 ( & V_45 . V_94 , 1 ) ;
V_45 . V_95 = - 1 ;
V_45 . V_96 = NULL ;
V_45 . V_97 . V_42 = V_12 ;
V_45 . V_97 . V_98 = 0 ;
V_45 . V_99 = V_100 ;
V_45 . V_101 = 0 ;
F_46 ( & V_45 . V_102 ) ;
F_45 ( & V_45 . V_103 , 1 ) ;
F_47 ( & V_45 . V_104 ) ;
V_45 . V_105 = 0 ;
V_45 . V_106 = 0 ;
F_48 ( & V_51 . V_107 , & V_92 ) ;
F_45 ( & V_51 . V_52 , 1 ) ;
V_51 . V_108 = & V_45 ;
V_51 . V_109 = & V_110 ;
V_51 . V_111 = 0 ;
V_51 . V_112 = V_113 | V_114 |
V_115 ;
V_51 . V_116 . V_117 = 0 ;
F_46 ( & V_51 . V_118 ) ;
F_47 ( & V_51 . V_119 ) ;
F_47 ( & V_51 . V_120 ) ;
}
int F_49 ( void )
{
int V_121 ;
F_43 () ;
V_121 = F_50 ( & V_44 ) ;
if ( V_121 )
F_35 ( L_5 , V_44 . V_122 , V_121 ) ;
return V_121 ;
}
void F_51 ( void )
{
int V_121 ;
V_121 = F_52 ( & V_44 ) ;
if ( V_121 )
F_35 ( L_6 , V_44 . V_122 , V_121 ) ;
}
