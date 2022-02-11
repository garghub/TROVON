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
memcpy ( V_65 , V_10 -> V_11 , V_10 -> V_22 ) ;
F_25 ( V_10 -> V_11 , V_10 -> V_60 ) ;
V_10 -> V_11 = V_10 -> V_31 = V_65 ;
V_10 -> V_60 = V_57 ;
}
F_31 ( V_10 -> V_31 , V_63 , V_64 ) ;
V_10 -> V_22 = V_68 ;
return 0 ;
}
static
int F_32 ( struct V_9 * V_10 )
{
F_7 ( F_14 ( V_10 -> V_70 . V_42 ) ==
V_43 ) ;
if ( V_10 -> V_70 . V_42 != V_12 ) {
F_33 ( L_4 , V_10 -> V_70 . V_42 ) ;
return V_71 ;
}
V_10 -> V_72 = F_2 ( V_10 -> V_11 ) ;
V_10 -> V_31 = V_10 -> V_11 ;
V_10 -> V_22 = V_10 -> V_21 ;
V_10 -> V_73 = & V_74 ;
F_18 ( & V_10 -> V_73 -> V_75 ) ;
return V_76 ;
}
static
int F_34 ( struct V_9 * V_10 , int V_56 )
{
struct V_77 * V_78 ;
int V_79 = sizeof( * V_78 ) + V_56 ;
F_7 ( V_56 % 8 == 0 ) ;
V_78 = V_10 -> V_80 ;
if ( V_78 ) {
F_7 ( V_78 -> V_79 >= V_79 ) ;
} else {
F_22 ( V_78 , V_79 ) ;
if ( V_78 == NULL )
return - V_59 ;
V_78 -> V_79 = V_79 ;
}
V_78 -> V_81 = V_10 -> V_73 ;
F_18 ( & V_10 -> V_73 -> V_75 ) ;
V_78 -> V_82 = (struct V_1 * ) ( V_78 + 1 ) ;
V_78 -> V_83 = V_79 - sizeof( * V_78 ) ;
V_78 -> V_84 = V_78 -> V_82 ;
V_10 -> V_80 = V_78 ;
return 0 ;
}
static
void F_35 ( struct V_77 * V_78 )
{
F_36 ( & V_78 -> V_81 -> V_75 , 1 ) ;
F_37 ( & V_78 -> V_81 -> V_75 ) ;
if ( ! V_78 -> V_85 )
F_25 ( V_78 , V_78 -> V_79 ) ;
}
static
int F_38 ( struct V_9 * V_10 )
{
struct V_77 * V_78 = V_10 -> V_80 ;
F_7 ( V_78 ) ;
V_78 -> V_82 -> V_5 = V_12 ;
V_78 -> V_86 = V_10 -> V_27 ;
if ( F_39 ( V_10 -> V_87 ) ) {
if ( F_10 ( V_10 -> V_31 ) & V_88 )
V_10 -> V_89 = F_27 () ;
else
V_10 -> V_89 = 0 ;
} else {
V_6 V_90 ;
#if V_30 < F_9 ( 2 , 7 , 50 , 0 )
if ( F_10 ( V_10 -> V_31 ) &
V_32 )
V_90 = F_11 ( V_78 -> V_82 , 0 ) ;
else
V_90 = F_11 ( V_78 -> V_82 , 1 ) ;
#else
# warning "remove checksum compatibility support for b1_8"
V_90 = F_11 ( V_78 -> V_82 ) ;
#endif
F_40 ( V_78 -> V_82 , V_90 ) ;
V_10 -> V_89 = 0 ;
}
return 0 ;
}
static void F_41 ( void )
{
static F_42 ( V_91 ) ;
V_45 . V_92 = & V_44 ;
F_43 ( & V_45 . V_93 , 1 ) ;
V_45 . V_94 = - 1 ;
V_45 . V_95 = NULL ;
V_45 . V_96 . V_42 = V_12 ;
V_45 . V_96 . V_97 = 0 ;
V_45 . V_98 = V_99 ;
V_45 . V_100 = 0 ;
F_44 ( & V_45 . V_101 ) ;
F_43 ( & V_45 . V_102 , 1 ) ;
F_45 ( & V_45 . V_103 ) ;
V_45 . V_104 = 0 ;
V_45 . V_105 = 0 ;
F_46 ( & V_51 . V_106 , & V_91 ) ;
F_43 ( & V_51 . V_52 , 1 ) ;
V_51 . V_107 = & V_45 ;
V_51 . V_108 = & V_109 ;
V_51 . V_110 = 0 ;
V_51 . V_111 = V_112 | V_113 |
V_114 ;
V_51 . V_115 . V_116 = 0 ;
F_44 ( & V_51 . V_117 ) ;
F_45 ( & V_51 . V_118 ) ;
F_45 ( & V_51 . V_119 ) ;
}
int F_47 ( void )
{
int V_120 ;
F_41 () ;
V_120 = F_48 ( & V_44 ) ;
if ( V_120 )
F_33 ( L_5 , V_44 . V_121 , V_120 ) ;
return V_120 ;
}
void F_49 ( void )
{
int V_120 ;
V_120 = F_50 ( & V_44 ) ;
if ( V_120 )
F_33 ( L_6 , V_44 . V_121 , V_120 ) ;
}
