void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 =
F_2 ( V_1 , struct V_2 , V_4 ) ;
F_3 ( V_3 ) ;
}
void F_4 ( struct V_5 * V_6 )
{
F_3 ( V_6 -> V_7 ) ;
F_3 ( V_6 -> V_8 ) ;
F_3 ( V_6 -> V_9 ) ;
F_3 ( V_6 -> V_10 ) ;
}
int
F_5 ( struct V_11 * V_12 , struct V_5 * V_6 )
{
F_6 ( & V_6 -> V_4 ) ;
V_6 -> V_13 = true ;
V_6 -> V_8 = F_7 ( V_12 -> V_14 . V_15 ,
sizeof( * V_6 -> V_8 ) , V_16 ) ;
if ( ! V_6 -> V_8 )
goto V_17;
V_6 -> V_9 = F_7 ( V_12 -> V_14 . V_18 ,
sizeof( * V_6 -> V_9 ) , V_16 ) ;
if ( ! V_6 -> V_9 )
goto V_17;
V_6 -> V_12 = V_12 ;
F_8 ( L_1 , V_6 ) ;
return 0 ;
V_17:
F_4 ( V_6 ) ;
return - V_19 ;
}
struct V_5 *
F_9 ( struct V_11 * V_12 )
{
struct V_20 * V_21 = & V_12 -> V_14 ;
if ( ! V_21 -> V_22 -> V_23 ) {
struct V_5 * V_6 ;
V_6 = F_10 ( sizeof( * V_6 ) , V_16 ) ;
if ( ! V_6 )
return NULL ;
if ( F_5 ( V_12 , V_6 ) < 0 ) {
F_3 ( V_6 ) ;
return NULL ;
}
return V_6 ;
}
return V_21 -> V_22 -> V_23 ( V_12 ) ;
}
void F_11 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = V_6 -> V_12 ;
struct V_20 * V_21 = & V_12 -> V_14 ;
int V_24 ;
F_8 ( L_2 , V_6 ) ;
for ( V_24 = 0 ; V_24 < V_6 -> V_25 ; V_24 ++ ) {
struct V_26 * V_27 = V_6 -> V_7 [ V_24 ] . V_28 ;
if ( ! V_27 )
continue;
V_27 -> V_22 -> V_29 ( V_27 ,
V_6 -> V_7 [ V_24 ] . V_6 ) ;
V_6 -> V_7 [ V_24 ] . V_28 = NULL ;
V_6 -> V_7 [ V_24 ] . V_6 = NULL ;
F_12 ( V_27 ) ;
}
for ( V_24 = 0 ; V_24 < V_21 -> V_15 ; V_24 ++ ) {
struct V_30 * V_31 = V_6 -> V_8 [ V_24 ] . V_28 ;
if ( ! V_31 )
continue;
V_31 -> V_22 -> V_29 ( V_31 ,
V_6 -> V_8 [ V_24 ] . V_6 ) ;
if ( V_6 -> V_8 [ V_24 ] . V_3 ) {
F_3 ( V_6 -> V_8 [ V_24 ] . V_3 -> V_32 ) ;
V_6 -> V_8 [ V_24 ] . V_3 -> V_32 = NULL ;
F_13 ( V_6 -> V_8 [ V_24 ] . V_3 ) ;
}
V_6 -> V_8 [ V_24 ] . V_3 = NULL ;
V_6 -> V_8 [ V_24 ] . V_28 = NULL ;
V_6 -> V_8 [ V_24 ] . V_6 = NULL ;
}
for ( V_24 = 0 ; V_24 < V_21 -> V_18 ; V_24 ++ ) {
struct V_33 * V_34 = V_6 -> V_9 [ V_24 ] . V_28 ;
if ( ! V_34 )
continue;
V_34 -> V_22 -> V_29 ( V_34 ,
V_6 -> V_9 [ V_24 ] . V_6 ) ;
V_6 -> V_9 [ V_24 ] . V_28 = NULL ;
V_6 -> V_9 [ V_24 ] . V_6 = NULL ;
}
for ( V_24 = 0 ; V_24 < V_6 -> V_35 ; V_24 ++ ) {
struct V_36 * V_37 = V_6 -> V_10 [ V_24 ] . V_28 ;
if ( ! V_37 )
continue;
V_37 -> V_22 -> V_29 ( V_37 ,
V_6 -> V_10 [ V_24 ] . V_6 ) ;
V_6 -> V_10 [ V_24 ] . V_28 = NULL ;
V_6 -> V_10 [ V_24 ] . V_6 = NULL ;
}
V_6 -> V_35 = 0 ;
}
void F_14 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = V_6 -> V_12 ;
struct V_20 * V_21 = & V_12 -> V_14 ;
if ( V_21 -> V_22 -> V_38 )
V_21 -> V_22 -> V_38 ( V_6 ) ;
else
F_11 ( V_6 ) ;
}
void F_15 ( struct V_1 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 , F_16 ( * V_6 ) , V_4 ) ;
struct V_20 * V_21 = & V_6 -> V_12 -> V_14 ;
F_14 ( V_6 ) ;
F_8 ( L_3 , V_6 ) ;
if ( V_21 -> V_22 -> V_39 ) {
V_21 -> V_22 -> V_39 ( V_6 ) ;
} else {
F_4 ( V_6 ) ;
F_3 ( V_6 ) ;
}
}
struct V_40 *
F_17 ( struct V_5 * V_6 ,
struct V_30 * V_31 )
{
int V_41 , V_42 = F_18 ( V_31 ) ;
struct V_40 * V_43 ;
F_19 ( ! V_6 -> V_44 ) ;
V_43 = F_20 ( V_6 , V_31 ) ;
if ( V_43 )
return V_43 ;
V_41 = F_21 ( & V_31 -> V_45 , V_6 -> V_44 ) ;
if ( V_41 )
return F_22 ( V_41 ) ;
V_43 = V_31 -> V_22 -> V_46 ( V_31 ) ;
if ( ! V_43 )
return F_22 ( - V_19 ) ;
V_6 -> V_8 [ V_42 ] . V_6 = V_43 ;
V_6 -> V_8 [ V_42 ] . V_47 = V_31 -> V_6 ;
V_6 -> V_8 [ V_42 ] . V_48 = V_43 ;
V_6 -> V_8 [ V_42 ] . V_28 = V_31 ;
V_43 -> V_6 = V_6 ;
F_8 ( L_4 ,
V_31 -> V_49 . V_50 , V_31 -> V_51 , V_43 , V_6 ) ;
return V_43 ;
}
static void F_23 ( struct V_5 * V_6 ,
struct V_30 * V_31 , T_1 T_2 * V_52 )
{
V_6 -> V_8 [ F_18 ( V_31 ) ] . V_53 = V_52 ;
}
static T_1 T_2 * F_24 ( struct V_5 * V_6 ,
struct V_30 * V_31 )
{
T_1 T_2 * V_52 ;
V_52 = V_6 -> V_8 [ F_18 ( V_31 ) ] . V_53 ;
V_6 -> V_8 [ F_18 ( V_31 ) ] . V_53 = NULL ;
return V_52 ;
}
int F_25 ( struct V_40 * V_6 ,
const struct V_54 * V_55 )
{
struct V_56 V_57 ;
if ( V_55 && memcmp ( & V_6 -> V_55 , V_55 , sizeof( * V_55 ) ) == 0 )
return 0 ;
F_26 ( V_6 -> V_58 ) ;
V_6 -> V_58 = NULL ;
if ( V_55 ) {
F_27 ( & V_57 , V_55 ) ;
V_6 -> V_58 =
F_28 ( V_6 -> V_31 -> V_12 ,
sizeof( V_57 ) ,
& V_57 ) ;
if ( F_29 ( V_6 -> V_58 ) )
return F_30 ( V_6 -> V_58 ) ;
F_31 ( & V_6 -> V_55 , V_55 ) ;
V_6 -> V_59 = true ;
F_8 ( L_5 ,
V_55 -> V_51 , V_6 ) ;
} else {
memset ( & V_6 -> V_55 , 0 , sizeof( V_6 -> V_55 ) ) ;
V_6 -> V_59 = false ;
F_8 ( L_6 ,
V_6 ) ;
}
return 0 ;
}
int F_32 ( struct V_40 * V_6 ,
struct V_60 * V_61 )
{
if ( V_61 == V_6 -> V_58 )
return 0 ;
F_26 ( V_6 -> V_58 ) ;
V_6 -> V_58 = NULL ;
memset ( & V_6 -> V_55 , 0 , sizeof( V_6 -> V_55 ) ) ;
if ( V_61 ) {
if ( V_61 -> V_62 != sizeof( struct V_56 ) ||
F_33 ( & V_6 -> V_55 ,
( const struct V_56 * )
V_61 -> V_63 ) )
return - V_64 ;
V_6 -> V_58 = F_34 ( V_61 ) ;
V_6 -> V_59 = true ;
F_8 ( L_5 ,
V_6 -> V_55 . V_51 , V_6 ) ;
} else {
V_6 -> V_59 = false ;
F_8 ( L_6 ,
V_6 ) ;
}
return 0 ;
}
static int
F_35 ( struct V_11 * V_12 ,
struct V_60 * * V_61 ,
T_3 V_65 ,
T_4 V_66 ,
bool * V_67 )
{
struct V_60 * V_68 = NULL ;
if ( V_65 != 0 ) {
V_68 = F_36 ( V_12 , V_65 ) ;
if ( V_68 == NULL )
return - V_64 ;
if ( V_66 > 0 && V_66 != V_68 -> V_62 ) {
F_26 ( V_68 ) ;
return - V_64 ;
}
}
* V_67 |= F_37 ( V_61 , V_68 ) ;
F_26 ( V_68 ) ;
return 0 ;
}
int F_38 ( struct V_30 * V_31 ,
struct V_40 * V_6 , struct V_69 * V_70 ,
T_3 V_71 )
{
struct V_11 * V_12 = V_31 -> V_12 ;
struct V_20 * V_21 = & V_12 -> V_14 ;
bool V_67 = false ;
int V_41 ;
if ( V_70 == V_21 -> V_72 )
V_6 -> V_73 = V_71 ;
else if ( V_70 == V_21 -> V_74 ) {
struct V_60 * V_55 =
F_36 ( V_12 , V_71 ) ;
V_41 = F_32 ( V_6 , V_55 ) ;
F_26 ( V_55 ) ;
return V_41 ;
} else if ( V_70 == V_21 -> V_75 ) {
V_41 = F_35 ( V_12 ,
& V_6 -> V_76 ,
V_71 ,
- 1 ,
& V_67 ) ;
V_6 -> V_77 |= V_67 ;
return V_41 ;
} else if ( V_70 == V_21 -> V_78 ) {
V_41 = F_35 ( V_12 ,
& V_6 -> V_79 ,
V_71 ,
sizeof( struct V_80 ) ,
& V_67 ) ;
V_6 -> V_77 |= V_67 ;
return V_41 ;
} else if ( V_70 == V_21 -> V_81 ) {
V_41 = F_35 ( V_12 ,
& V_6 -> V_82 ,
V_71 ,
- 1 ,
& V_67 ) ;
V_6 -> V_77 |= V_67 ;
return V_41 ;
} else if ( V_70 == V_21 -> V_83 ) {
T_1 T_2 * V_52 = F_39 ( V_71 ) ;
if ( ! V_52 )
return 0 ;
if ( F_40 ( - 1 , V_52 ) )
return - V_84 ;
F_23 ( V_6 -> V_6 , V_31 , V_52 ) ;
} else if ( V_31 -> V_22 -> V_85 )
return V_31 -> V_22 -> V_85 ( V_31 , V_6 , V_70 , V_71 ) ;
else
return - V_64 ;
return 0 ;
}
static int
F_41 ( struct V_30 * V_31 ,
const struct V_40 * V_6 ,
struct V_69 * V_70 , T_3 * V_71 )
{
struct V_11 * V_12 = V_31 -> V_12 ;
struct V_20 * V_21 = & V_12 -> V_14 ;
if ( V_70 == V_21 -> V_72 )
* V_71 = V_6 -> V_73 ;
else if ( V_70 == V_21 -> V_74 )
* V_71 = ( V_6 -> V_58 ) ? V_6 -> V_58 -> V_49 . V_50 : 0 ;
else if ( V_70 == V_21 -> V_75 )
* V_71 = ( V_6 -> V_76 ) ? V_6 -> V_76 -> V_49 . V_50 : 0 ;
else if ( V_70 == V_21 -> V_78 )
* V_71 = ( V_6 -> V_79 ) ? V_6 -> V_79 -> V_49 . V_50 : 0 ;
else if ( V_70 == V_21 -> V_81 )
* V_71 = ( V_6 -> V_82 ) ? V_6 -> V_82 -> V_49 . V_50 : 0 ;
else if ( V_70 == V_21 -> V_83 )
* V_71 = 0 ;
else if ( V_31 -> V_22 -> V_86 )
return V_31 -> V_22 -> V_86 ( V_31 , V_6 , V_70 , V_71 ) ;
else
return - V_64 ;
return 0 ;
}
static int F_42 ( struct V_30 * V_31 ,
struct V_40 * V_6 )
{
if ( V_6 -> V_73 && ! V_6 -> V_59 ) {
F_8 ( L_7 ,
V_31 -> V_49 . V_50 , V_31 -> V_51 ) ;
return - V_64 ;
}
if ( F_43 ( V_31 -> V_12 , V_87 ) &&
F_19 ( V_6 -> V_59 && ! V_6 -> V_58 ) ) {
F_8 ( L_8 ,
V_31 -> V_49 . V_50 , V_31 -> V_51 ) ;
return - V_64 ;
}
if ( F_43 ( V_31 -> V_12 , V_87 ) &&
F_19 ( ! V_6 -> V_59 && V_6 -> V_58 ) ) {
F_8 ( L_9 ,
V_31 -> V_49 . V_50 , V_31 -> V_51 ) ;
return - V_64 ;
}
if ( V_6 -> V_32 && ! V_6 -> V_73 && ! V_31 -> V_6 -> V_73 ) {
F_8 ( L_10 ,
V_31 -> V_49 . V_50 , V_31 -> V_51 ) ;
return - V_64 ;
}
return 0 ;
}
static void F_44 ( struct V_88 * V_89 ,
const struct V_40 * V_6 )
{
struct V_30 * V_31 = V_6 -> V_31 ;
F_45 ( V_89 , L_11 , V_31 -> V_49 . V_50 , V_31 -> V_51 ) ;
F_45 ( V_89 , L_12 , V_6 -> V_59 ) ;
F_45 ( V_89 , L_13 , V_6 -> V_73 ) ;
F_45 ( V_89 , L_14 , V_6 -> V_90 ) ;
F_45 ( V_89 , L_15 , V_6 -> V_91 ) ;
F_45 ( V_89 , L_16 , V_6 -> V_92 ) ;
F_45 ( V_89 , L_17 , V_6 -> V_93 ) ;
F_45 ( V_89 , L_18 , V_6 -> V_77 ) ;
F_45 ( V_89 , L_19 , V_6 -> V_94 ) ;
F_45 ( V_89 , L_20 , V_6 -> V_95 ) ;
F_45 ( V_89 , L_21 , V_6 -> V_96 ) ;
F_45 ( V_89 , L_22 V_97 L_23 , F_46 ( & V_6 -> V_55 ) ) ;
if ( V_31 -> V_22 -> V_98 )
V_31 -> V_22 -> V_98 ( V_89 , V_6 ) ;
}
struct V_99 *
F_47 ( struct V_5 * V_6 ,
struct V_33 * V_34 )
{
int V_41 , V_42 = F_48 ( V_34 ) ;
struct V_99 * V_100 ;
F_19 ( ! V_6 -> V_44 ) ;
V_100 = F_49 ( V_6 , V_34 ) ;
if ( V_100 )
return V_100 ;
V_41 = F_21 ( & V_34 -> V_45 , V_6 -> V_44 ) ;
if ( V_41 )
return F_22 ( V_41 ) ;
V_100 = V_34 -> V_22 -> V_46 ( V_34 ) ;
if ( ! V_100 )
return F_22 ( - V_19 ) ;
V_6 -> V_9 [ V_42 ] . V_6 = V_100 ;
V_6 -> V_9 [ V_42 ] . V_28 = V_34 ;
V_6 -> V_9 [ V_42 ] . V_47 = V_34 -> V_6 ;
V_6 -> V_9 [ V_42 ] . V_48 = V_100 ;
V_100 -> V_6 = V_6 ;
F_8 ( L_24 ,
V_34 -> V_49 . V_50 , V_34 -> V_51 , V_100 , V_6 ) ;
if ( V_100 -> V_31 ) {
struct V_40 * V_43 ;
V_43 = F_17 ( V_6 ,
V_100 -> V_31 ) ;
if ( F_29 ( V_43 ) )
return F_50 ( V_43 ) ;
}
return V_100 ;
}
static int F_51 ( struct V_33 * V_34 ,
struct V_99 * V_6 , struct V_69 * V_70 ,
T_3 V_71 )
{
struct V_11 * V_12 = V_34 -> V_12 ;
struct V_20 * V_21 = & V_12 -> V_14 ;
if ( V_70 == V_21 -> V_101 ) {
struct V_102 * V_103 = F_52 ( V_12 , V_71 ) ;
F_53 ( V_6 , V_103 ) ;
if ( V_103 )
F_54 ( V_103 ) ;
} else if ( V_70 == V_21 -> V_104 ) {
if ( V_6 -> V_105 )
return - V_64 ;
if ( F_55 ( V_71 ) == - 1 )
return 0 ;
V_6 -> V_105 = F_56 ( V_71 ) ;
if ( ! V_6 -> V_105 )
return - V_64 ;
} else if ( V_70 == V_21 -> V_106 ) {
struct V_30 * V_31 = F_57 ( V_12 , V_71 ) ;
return F_58 ( V_6 , V_31 ) ;
} else if ( V_70 == V_21 -> V_107 ) {
V_6 -> V_108 = F_55 ( V_71 ) ;
} else if ( V_70 == V_21 -> V_109 ) {
V_6 -> V_110 = F_55 ( V_71 ) ;
} else if ( V_70 == V_21 -> V_111 ) {
V_6 -> V_112 = V_71 ;
} else if ( V_70 == V_21 -> V_113 ) {
V_6 -> V_114 = V_71 ;
} else if ( V_70 == V_21 -> V_115 ) {
V_6 -> V_116 = V_71 ;
} else if ( V_70 == V_21 -> V_117 ) {
V_6 -> V_118 = V_71 ;
} else if ( V_70 == V_21 -> V_119 ) {
V_6 -> V_120 = V_71 ;
} else if ( V_70 == V_21 -> V_121 ) {
V_6 -> V_122 = V_71 ;
} else if ( V_70 == V_34 -> V_123 ) {
if ( ! F_59 ( V_71 & V_124 ) )
return - V_64 ;
V_6 -> V_125 = V_71 ;
} else if ( V_70 == V_34 -> V_126 ) {
V_6 -> V_127 = V_71 ;
} else if ( V_34 -> V_22 -> V_85 ) {
return V_34 -> V_22 -> V_85 ( V_34 , V_6 ,
V_70 , V_71 ) ;
} else {
return - V_64 ;
}
return 0 ;
}
static int
F_60 ( struct V_33 * V_34 ,
const struct V_99 * V_6 ,
struct V_69 * V_70 , T_3 * V_71 )
{
struct V_11 * V_12 = V_34 -> V_12 ;
struct V_20 * V_21 = & V_12 -> V_14 ;
if ( V_70 == V_21 -> V_101 ) {
* V_71 = ( V_6 -> V_103 ) ? V_6 -> V_103 -> V_49 . V_50 : 0 ;
} else if ( V_70 == V_21 -> V_104 ) {
* V_71 = - 1 ;
} else if ( V_70 == V_21 -> V_106 ) {
* V_71 = ( V_6 -> V_31 ) ? V_6 -> V_31 -> V_49 . V_50 : 0 ;
} else if ( V_70 == V_21 -> V_107 ) {
* V_71 = F_61 ( V_6 -> V_108 ) ;
} else if ( V_70 == V_21 -> V_109 ) {
* V_71 = F_61 ( V_6 -> V_110 ) ;
} else if ( V_70 == V_21 -> V_111 ) {
* V_71 = V_6 -> V_112 ;
} else if ( V_70 == V_21 -> V_113 ) {
* V_71 = V_6 -> V_114 ;
} else if ( V_70 == V_21 -> V_115 ) {
* V_71 = V_6 -> V_116 ;
} else if ( V_70 == V_21 -> V_117 ) {
* V_71 = V_6 -> V_118 ;
} else if ( V_70 == V_21 -> V_119 ) {
* V_71 = V_6 -> V_120 ;
} else if ( V_70 == V_21 -> V_121 ) {
* V_71 = V_6 -> V_122 ;
} else if ( V_70 == V_34 -> V_123 ) {
* V_71 = V_6 -> V_125 ;
} else if ( V_70 == V_34 -> V_126 ) {
* V_71 = V_6 -> V_127 ;
} else if ( V_34 -> V_22 -> V_86 ) {
return V_34 -> V_22 -> V_86 ( V_34 , V_6 , V_70 , V_71 ) ;
} else {
return - V_64 ;
}
return 0 ;
}
static bool
F_62 ( struct V_5 * V_6 ,
struct V_33 * V_34 ,
struct V_99 * V_100 )
{
if ( ! V_34 -> V_6 -> V_31 || ! V_100 -> V_31 )
return false ;
if ( V_34 -> V_6 -> V_31 == V_100 -> V_31 )
return false ;
return true ;
}
static int F_63 ( struct V_33 * V_34 ,
struct V_99 * V_6 )
{
unsigned int V_128 , V_129 ;
int V_41 ;
if ( F_19 ( V_6 -> V_31 && ! V_6 -> V_103 ) ) {
F_8 ( L_25 ) ;
return - V_64 ;
} else if ( F_19 ( V_6 -> V_103 && ! V_6 -> V_31 ) ) {
F_8 ( L_26 ) ;
return - V_64 ;
}
if ( ! V_6 -> V_31 )
return 0 ;
if ( ! ( V_34 -> V_130 & F_64 ( V_6 -> V_31 ) ) ) {
F_8 ( L_27 ) ;
return - V_64 ;
}
V_41 = F_65 ( V_34 , V_6 -> V_103 -> V_131 -> V_131 ) ;
if ( V_41 ) {
struct V_132 V_133 ;
F_8 ( L_28 ,
F_66 ( V_6 -> V_103 -> V_131 -> V_131 ,
& V_133 ) ) ;
return V_41 ;
}
if ( V_6 -> V_112 > V_134 ||
V_6 -> V_108 > V_134 - ( V_135 ) V_6 -> V_112 ||
V_6 -> V_114 > V_134 ||
V_6 -> V_110 > V_134 - ( V_135 ) V_6 -> V_114 ) {
F_8 ( L_29 ,
V_6 -> V_112 , V_6 -> V_114 ,
V_6 -> V_108 , V_6 -> V_110 ) ;
return - V_136 ;
}
V_128 = V_6 -> V_103 -> V_137 << 16 ;
V_129 = V_6 -> V_103 -> V_138 << 16 ;
if ( V_6 -> V_120 > V_128 ||
V_6 -> V_116 > V_128 - V_6 -> V_120 ||
V_6 -> V_122 > V_129 ||
V_6 -> V_118 > V_129 - V_6 -> V_122 ) {
F_8 ( L_30
L_31 ,
V_6 -> V_120 >> 16 , ( ( V_6 -> V_120 & 0xffff ) * 15625 ) >> 10 ,
V_6 -> V_122 >> 16 , ( ( V_6 -> V_122 & 0xffff ) * 15625 ) >> 10 ,
V_6 -> V_116 >> 16 , ( ( V_6 -> V_116 & 0xffff ) * 15625 ) >> 10 ,
V_6 -> V_118 >> 16 , ( ( V_6 -> V_118 & 0xffff ) * 15625 ) >> 10 ) ;
return - V_139 ;
}
if ( F_62 ( V_6 -> V_6 , V_34 , V_6 ) ) {
F_8 ( L_32 ,
V_34 -> V_49 . V_50 , V_34 -> V_51 ) ;
return - V_64 ;
}
return 0 ;
}
static void F_67 ( struct V_88 * V_89 ,
const struct V_99 * V_6 )
{
struct V_33 * V_34 = V_6 -> V_34 ;
struct V_140 V_141 = F_68 ( V_6 ) ;
struct V_140 V_142 = F_69 ( V_6 ) ;
F_45 ( V_89 , L_33 , V_34 -> V_49 . V_50 , V_34 -> V_51 ) ;
F_45 ( V_89 , L_34 , V_6 -> V_31 ? V_6 -> V_31 -> V_51 : L_35 ) ;
F_45 ( V_89 , L_36 , V_6 -> V_103 ? V_6 -> V_103 -> V_49 . V_50 : 0 ) ;
if ( V_6 -> V_103 ) {
struct V_102 * V_103 = V_6 -> V_103 ;
int V_24 , V_143 = V_103 -> V_131 -> V_144 ;
struct V_132 V_133 ;
F_45 ( V_89 , L_37 ,
F_66 ( V_103 -> V_131 -> V_131 , & V_133 ) ) ;
F_45 ( V_89 , L_38 , V_103 -> V_145 ) ;
F_45 ( V_89 , L_39 , V_103 -> V_137 , V_103 -> V_138 ) ;
F_45 ( V_89 , L_40 ) ;
for ( V_24 = 0 ; V_24 < V_143 ; V_24 ++ ) {
F_45 ( V_89 , L_41 , V_24 , V_103 -> V_146 [ V_24 ] ) ;
F_45 ( V_89 , L_42 , V_24 , V_103 -> V_147 [ V_24 ] ) ;
}
}
F_45 ( V_89 , L_43 V_148 L_23 , F_70 ( & V_142 ) ) ;
F_45 ( V_89 , L_44 V_149 L_23 , F_71 ( & V_141 ) ) ;
F_45 ( V_89 , L_45 , V_6 -> V_125 ) ;
if ( V_34 -> V_22 -> V_98 )
V_34 -> V_22 -> V_98 ( V_89 , V_6 ) ;
}
void
F_72 ( struct V_36 * V_37 ,
struct V_150 * V_6 ,
const struct V_151 * V_22 )
{
memset ( V_37 , 0 , sizeof( * V_37 ) ) ;
V_37 -> V_6 = V_6 ;
V_37 -> V_22 = V_22 ;
}
void
F_73 ( struct V_36 * V_37 )
{
V_37 -> V_22 -> V_29 ( V_37 , V_37 -> V_6 ) ;
}
struct V_150 *
F_74 ( struct V_5 * V_6 ,
struct V_36 * V_37 )
{
int V_42 , V_152 , V_24 ;
T_5 V_153 ;
struct V_154 * V_155 ;
struct V_150 * V_156 ;
for ( V_24 = 0 ; V_24 < V_6 -> V_35 ; V_24 ++ )
if ( V_37 == V_6 -> V_10 [ V_24 ] . V_28 )
return V_6 -> V_10 [ V_24 ] . V_6 ;
V_152 = V_6 -> V_35 + 1 ;
V_153 = sizeof( * V_6 -> V_10 ) * V_152 ;
V_155 = F_75 ( V_6 -> V_10 , V_153 , V_16 ) ;
if ( ! V_155 )
return F_22 ( - V_19 ) ;
V_6 -> V_10 = V_155 ;
V_42 = V_6 -> V_35 ;
memset ( & V_6 -> V_10 [ V_42 ] , 0 , sizeof( * V_6 -> V_10 ) ) ;
V_156 = V_37 -> V_22 -> V_46 ( V_37 ) ;
if ( ! V_156 )
return F_22 ( - V_19 ) ;
V_6 -> V_10 [ V_42 ] . V_6 = V_156 ;
V_6 -> V_10 [ V_42 ] . V_47 = V_37 -> V_6 ;
V_6 -> V_10 [ V_42 ] . V_48 = V_156 ;
V_6 -> V_10 [ V_42 ] . V_28 = V_37 ;
V_6 -> V_35 = V_152 ;
F_8 ( L_46 ,
V_37 , V_156 , V_6 ) ;
return V_156 ;
}
struct V_157 *
F_76 ( struct V_5 * V_6 ,
struct V_26 * V_27 )
{
int V_41 , V_42 ;
struct V_20 * V_21 = & V_27 -> V_12 -> V_14 ;
struct V_157 * V_158 ;
F_19 ( ! V_6 -> V_44 ) ;
V_41 = F_21 ( & V_21 -> V_159 , V_6 -> V_44 ) ;
if ( V_41 )
return F_22 ( V_41 ) ;
V_42 = F_77 ( V_27 ) ;
if ( V_42 >= V_6 -> V_25 ) {
struct V_160 * V_161 ;
int V_162 = F_78 ( V_42 + 1 , V_21 -> V_25 ) ;
V_161 = F_75 ( V_6 -> V_7 , V_162 * sizeof( * V_6 -> V_7 ) , V_16 ) ;
if ( ! V_161 )
return F_22 ( - V_19 ) ;
V_6 -> V_7 = V_161 ;
memset ( & V_6 -> V_7 [ V_6 -> V_25 ] , 0 ,
sizeof( * V_6 -> V_7 ) * ( V_162 - V_6 -> V_25 ) ) ;
V_6 -> V_25 = V_162 ;
}
if ( V_6 -> V_7 [ V_42 ] . V_6 )
return V_6 -> V_7 [ V_42 ] . V_6 ;
V_158 = V_27 -> V_22 -> V_46 ( V_27 ) ;
if ( ! V_158 )
return F_22 ( - V_19 ) ;
F_79 ( V_27 ) ;
V_6 -> V_7 [ V_42 ] . V_6 = V_158 ;
V_6 -> V_7 [ V_42 ] . V_47 = V_27 -> V_6 ;
V_6 -> V_7 [ V_42 ] . V_48 = V_158 ;
V_6 -> V_7 [ V_42 ] . V_28 = V_27 ;
V_158 -> V_6 = V_6 ;
F_8 ( L_47 ,
V_27 -> V_49 . V_50 , V_27 -> V_51 ,
V_158 , V_6 ) ;
if ( V_158 -> V_31 ) {
struct V_40 * V_43 ;
V_43 = F_17 ( V_6 ,
V_158 -> V_31 ) ;
if ( F_29 ( V_43 ) )
return F_50 ( V_43 ) ;
}
return V_158 ;
}
static int F_80 ( struct V_26 * V_27 ,
struct V_157 * V_6 , struct V_69 * V_70 ,
T_3 V_71 )
{
struct V_11 * V_12 = V_27 -> V_12 ;
struct V_20 * V_21 = & V_12 -> V_14 ;
if ( V_70 == V_21 -> V_106 ) {
struct V_30 * V_31 = F_57 ( V_12 , V_71 ) ;
return F_81 ( V_6 , V_31 ) ;
} else if ( V_70 == V_21 -> V_163 ) {
return - V_64 ;
} else if ( V_70 == V_21 -> V_164 ) {
V_6 -> V_165 . V_166 = V_71 ;
} else if ( V_70 == V_21 -> V_167 ) {
V_6 -> V_165 . V_168 . V_169 = V_71 ;
} else if ( V_70 == V_21 -> V_170 ) {
V_6 -> V_165 . V_168 . V_171 = V_71 ;
} else if ( V_70 == V_21 -> V_172 ) {
V_6 -> V_165 . V_168 . V_173 = V_71 ;
} else if ( V_70 == V_21 -> V_174 ) {
V_6 -> V_165 . V_168 . V_175 = V_71 ;
} else if ( V_70 == V_21 -> V_176 ) {
V_6 -> V_165 . V_55 = V_71 ;
} else if ( V_70 == V_21 -> V_177 ) {
V_6 -> V_165 . V_178 = V_71 ;
} else if ( V_70 == V_21 -> V_179 ) {
V_6 -> V_165 . V_180 = V_71 ;
} else if ( V_70 == V_21 -> V_181 ) {
V_6 -> V_165 . V_182 = V_71 ;
} else if ( V_70 == V_21 -> V_183 ) {
V_6 -> V_165 . V_184 = V_71 ;
} else if ( V_70 == V_21 -> V_185 ) {
V_6 -> V_165 . V_186 = V_71 ;
} else if ( V_70 == V_21 -> V_187 ) {
V_6 -> V_165 . V_188 = V_71 ;
} else if ( V_70 == V_21 -> V_189 ) {
if ( V_6 -> V_190 != V_191 )
V_6 -> V_190 = V_71 ;
} else if ( V_70 == V_21 -> V_192 ) {
V_6 -> V_193 = V_71 ;
} else if ( V_70 == V_27 -> V_194 ) {
V_6 -> V_195 = V_71 ;
} else if ( V_27 -> V_22 -> V_85 ) {
return V_27 -> V_22 -> V_85 ( V_27 ,
V_6 , V_70 , V_71 ) ;
} else {
return - V_64 ;
}
return 0 ;
}
static void F_82 ( struct V_88 * V_89 ,
const struct V_157 * V_6 )
{
struct V_26 * V_27 = V_6 -> V_27 ;
F_45 ( V_89 , L_48 , V_27 -> V_49 . V_50 , V_27 -> V_51 ) ;
F_45 ( V_89 , L_34 , V_6 -> V_31 ? V_6 -> V_31 -> V_51 : L_35 ) ;
if ( V_27 -> V_22 -> V_98 )
V_27 -> V_22 -> V_98 ( V_89 , V_6 ) ;
}
static int
F_83 ( struct V_26 * V_27 ,
const struct V_157 * V_6 ,
struct V_69 * V_70 , T_3 * V_71 )
{
struct V_11 * V_12 = V_27 -> V_12 ;
struct V_20 * V_21 = & V_12 -> V_14 ;
if ( V_70 == V_21 -> V_106 ) {
* V_71 = ( V_6 -> V_31 ) ? V_6 -> V_31 -> V_49 . V_50 : 0 ;
} else if ( V_70 == V_21 -> V_163 ) {
* V_71 = V_27 -> V_196 ;
} else if ( V_70 == V_21 -> V_164 ) {
* V_71 = V_6 -> V_165 . V_166 ;
} else if ( V_70 == V_21 -> V_167 ) {
* V_71 = V_6 -> V_165 . V_168 . V_169 ;
} else if ( V_70 == V_21 -> V_170 ) {
* V_71 = V_6 -> V_165 . V_168 . V_171 ;
} else if ( V_70 == V_21 -> V_172 ) {
* V_71 = V_6 -> V_165 . V_168 . V_173 ;
} else if ( V_70 == V_21 -> V_174 ) {
* V_71 = V_6 -> V_165 . V_168 . V_175 ;
} else if ( V_70 == V_21 -> V_176 ) {
* V_71 = V_6 -> V_165 . V_55 ;
} else if ( V_70 == V_21 -> V_177 ) {
* V_71 = V_6 -> V_165 . V_178 ;
} else if ( V_70 == V_21 -> V_179 ) {
* V_71 = V_6 -> V_165 . V_180 ;
} else if ( V_70 == V_21 -> V_181 ) {
* V_71 = V_6 -> V_165 . V_182 ;
} else if ( V_70 == V_21 -> V_183 ) {
* V_71 = V_6 -> V_165 . V_184 ;
} else if ( V_70 == V_21 -> V_185 ) {
* V_71 = V_6 -> V_165 . V_186 ;
} else if ( V_70 == V_21 -> V_187 ) {
* V_71 = V_6 -> V_165 . V_188 ;
} else if ( V_70 == V_21 -> V_189 ) {
* V_71 = V_6 -> V_190 ;
} else if ( V_70 == V_21 -> V_192 ) {
* V_71 = V_6 -> V_193 ;
} else if ( V_70 == V_27 -> V_194 ) {
* V_71 = V_6 -> V_195 ;
} else if ( V_27 -> V_22 -> V_86 ) {
return V_27 -> V_22 -> V_86 ( V_27 ,
V_6 , V_70 , V_71 ) ;
} else {
return - V_64 ;
}
return 0 ;
}
int F_84 ( struct V_197 * V_37 ,
struct V_69 * V_70 , T_3 * V_71 )
{
struct V_11 * V_12 = V_70 -> V_12 ;
int V_41 ;
switch ( V_37 -> type ) {
case V_198 : {
struct V_26 * V_27 = F_85 ( V_37 ) ;
F_19 ( ! F_86 ( & V_12 -> V_14 . V_159 ) ) ;
V_41 = F_83 ( V_27 ,
V_27 -> V_6 , V_70 , V_71 ) ;
break;
}
case V_199 : {
struct V_30 * V_31 = F_87 ( V_37 ) ;
F_19 ( ! F_86 ( & V_31 -> V_45 ) ) ;
V_41 = F_41 ( V_31 ,
V_31 -> V_6 , V_70 , V_71 ) ;
break;
}
case V_200 : {
struct V_33 * V_34 = F_88 ( V_37 ) ;
F_19 ( ! F_86 ( & V_34 -> V_45 ) ) ;
V_41 = F_60 ( V_34 ,
V_34 -> V_6 , V_70 , V_71 ) ;
break;
}
default:
V_41 = - V_64 ;
break;
}
return V_41 ;
}
int
F_58 ( struct V_99 * V_100 ,
struct V_30 * V_31 )
{
struct V_33 * V_34 = V_100 -> V_34 ;
struct V_40 * V_43 ;
if ( V_100 -> V_31 ) {
V_43 = F_17 ( V_100 -> V_6 ,
V_100 -> V_31 ) ;
if ( F_19 ( F_29 ( V_43 ) ) )
return F_30 ( V_43 ) ;
V_43 -> V_94 &= ~ ( 1 << F_48 ( V_34 ) ) ;
}
V_100 -> V_31 = V_31 ;
if ( V_31 ) {
V_43 = F_17 ( V_100 -> V_6 ,
V_31 ) ;
if ( F_29 ( V_43 ) )
return F_30 ( V_43 ) ;
V_43 -> V_94 |= ( 1 << F_48 ( V_34 ) ) ;
}
if ( V_31 )
F_8 ( L_49 ,
V_100 , V_31 -> V_49 . V_50 , V_31 -> V_51 ) ;
else
F_8 ( L_50 ,
V_100 ) ;
return 0 ;
}
void
F_53 ( struct V_99 * V_100 ,
struct V_102 * V_103 )
{
if ( V_103 )
F_8 ( L_51 ,
V_103 -> V_49 . V_50 , V_100 ) ;
else
F_8 ( L_52 ,
V_100 ) ;
F_89 ( & V_100 -> V_103 , V_103 ) ;
}
void
F_90 ( struct V_99 * V_100 ,
struct V_201 * V_105 )
{
if ( V_100 -> V_105 ) {
F_91 ( V_105 ) ;
return;
}
V_100 -> V_105 = V_105 ;
}
int
F_81 ( struct V_157 * V_202 ,
struct V_30 * V_31 )
{
struct V_40 * V_43 ;
if ( V_202 -> V_31 == V_31 )
return 0 ;
if ( V_202 -> V_31 ) {
V_43 = F_92 ( V_202 -> V_6 ,
V_202 -> V_31 ) ;
V_43 -> V_95 &=
~ ( 1 << F_77 ( V_202 -> V_27 ) ) ;
F_12 ( V_202 -> V_27 ) ;
V_202 -> V_31 = NULL ;
}
if ( V_31 ) {
V_43 = F_17 ( V_202 -> V_6 , V_31 ) ;
if ( F_29 ( V_43 ) )
return F_30 ( V_43 ) ;
V_43 -> V_95 |=
1 << F_77 ( V_202 -> V_27 ) ;
F_79 ( V_202 -> V_27 ) ;
V_202 -> V_31 = V_31 ;
F_8 ( L_53 ,
V_202 , V_31 -> V_49 . V_50 , V_31 -> V_51 ) ;
} else {
F_8 ( L_54 ,
V_202 ) ;
}
return 0 ;
}
int
F_93 ( struct V_5 * V_6 ,
struct V_30 * V_31 )
{
struct V_20 * V_21 = & V_6 -> V_12 -> V_14 ;
struct V_26 * V_27 ;
struct V_157 * V_202 ;
struct V_203 V_204 ;
struct V_40 * V_43 ;
int V_41 ;
V_43 = F_17 ( V_6 , V_31 ) ;
if ( F_29 ( V_43 ) )
return F_30 ( V_43 ) ;
V_41 = F_21 ( & V_21 -> V_159 , V_6 -> V_44 ) ;
if ( V_41 )
return V_41 ;
F_8 ( L_55 ,
V_31 -> V_49 . V_50 , V_31 -> V_51 , V_6 ) ;
F_94 ( V_6 -> V_12 , & V_204 ) ;
F_95 (connector, &conn_iter) {
if ( ! ( V_43 -> V_95 & ( 1 << F_77 ( V_27 ) ) ) )
continue;
V_202 = F_76 ( V_6 , V_27 ) ;
if ( F_29 ( V_202 ) ) {
F_96 ( & V_204 ) ;
return F_30 ( V_202 ) ;
}
}
F_96 ( & V_204 ) ;
return 0 ;
}
int
F_97 ( struct V_5 * V_6 ,
struct V_30 * V_31 )
{
struct V_33 * V_34 ;
F_19 ( ! F_92 ( V_6 , V_31 ) ) ;
F_98 (plane, state->dev, crtc->state->plane_mask) {
struct V_99 * V_100 =
F_47 ( V_6 , V_34 ) ;
if ( F_29 ( V_100 ) )
return F_30 ( V_100 ) ;
}
return 0 ;
}
int F_99 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = V_6 -> V_12 ;
struct V_20 * V_21 = & V_12 -> V_14 ;
struct V_33 * V_34 ;
struct V_99 * V_100 ;
struct V_30 * V_31 ;
struct V_40 * V_43 ;
int V_24 , V_41 = 0 ;
F_8 ( L_56 , V_6 ) ;
F_100 (state, plane, plane_state, i) {
V_41 = F_63 ( V_34 , V_100 ) ;
if ( V_41 ) {
F_8 ( L_57 ,
V_34 -> V_49 . V_50 , V_34 -> V_51 ) ;
return V_41 ;
}
}
F_101 (state, crtc, crtc_state, i) {
V_41 = F_42 ( V_31 , V_43 ) ;
if ( V_41 ) {
F_8 ( L_58 ,
V_31 -> V_49 . V_50 , V_31 -> V_51 ) ;
return V_41 ;
}
}
if ( V_21 -> V_22 -> V_205 )
V_41 = V_21 -> V_22 -> V_205 ( V_6 -> V_12 , V_6 ) ;
if ( V_41 )
return V_41 ;
if ( ! V_6 -> V_13 ) {
F_101 (state, crtc, crtc_state, i) {
if ( F_102 ( V_43 ) ) {
F_8 ( L_59 ,
V_31 -> V_49 . V_50 , V_31 -> V_51 ) ;
return - V_64 ;
}
}
}
return 0 ;
}
int F_103 ( struct V_5 * V_6 )
{
struct V_20 * V_21 = & V_6 -> V_12 -> V_14 ;
int V_41 ;
V_41 = F_99 ( V_6 ) ;
if ( V_41 )
return V_41 ;
F_8 ( L_60 , V_6 ) ;
return V_21 -> V_22 -> V_206 ( V_6 -> V_12 , V_6 , false ) ;
}
int F_104 ( struct V_5 * V_6 )
{
struct V_20 * V_21 = & V_6 -> V_12 -> V_14 ;
int V_41 ;
V_41 = F_99 ( V_6 ) ;
if ( V_41 )
return V_41 ;
F_8 ( L_61 , V_6 ) ;
return V_21 -> V_22 -> V_206 ( V_6 -> V_12 , V_6 , true ) ;
}
static void F_105 ( const struct V_5 * V_6 )
{
struct V_88 V_89 = F_106 ( V_6 -> V_12 -> V_12 ) ;
struct V_33 * V_34 ;
struct V_99 * V_100 ;
struct V_30 * V_31 ;
struct V_40 * V_43 ;
struct V_26 * V_27 ;
struct V_157 * V_158 ;
int V_24 ;
F_8 ( L_56 , V_6 ) ;
F_100 (state, plane, plane_state, i)
F_67 ( & V_89 , V_100 ) ;
F_101 (state, crtc, crtc_state, i)
F_44 ( & V_89 , V_43 ) ;
F_107 (state, connector, connector_state, i)
F_82 ( & V_89 , V_158 ) ;
}
static void F_108 ( struct V_11 * V_12 , struct V_88 * V_89 ,
bool V_207 )
{
struct V_20 * V_21 = & V_12 -> V_14 ;
struct V_33 * V_34 ;
struct V_30 * V_31 ;
struct V_26 * V_27 ;
struct V_203 V_204 ;
if ( ! F_43 ( V_12 , V_87 ) )
return;
F_109 (plane, &config->plane_list, head) {
if ( V_207 )
F_21 ( & V_34 -> V_45 , NULL ) ;
F_67 ( V_89 , V_34 -> V_6 ) ;
if ( V_207 )
F_110 ( & V_34 -> V_45 ) ;
}
F_109 (crtc, &config->crtc_list, head) {
if ( V_207 )
F_21 ( & V_31 -> V_45 , NULL ) ;
F_44 ( V_89 , V_31 -> V_6 ) ;
if ( V_207 )
F_110 ( & V_31 -> V_45 ) ;
}
F_94 ( V_12 , & V_204 ) ;
if ( V_207 )
F_21 ( & V_12 -> V_14 . V_159 , NULL ) ;
F_95 (connector, &conn_iter)
F_82 ( V_89 , V_27 -> V_6 ) ;
if ( V_207 )
F_110 ( & V_12 -> V_14 . V_159 ) ;
F_96 ( & V_204 ) ;
}
void F_111 ( struct V_11 * V_12 , struct V_88 * V_89 )
{
F_108 ( V_12 , V_89 , false ) ;
}
static int F_112 ( struct V_208 * V_209 , void * V_63 )
{
struct V_210 * V_211 = (struct V_210 * ) V_209 -> V_212 ;
struct V_11 * V_12 = V_211 -> V_213 -> V_12 ;
struct V_88 V_89 = F_113 ( V_209 ) ;
F_108 ( V_12 , & V_89 , true ) ;
return 0 ;
}
int F_114 ( struct V_214 * V_213 )
{
return F_115 ( V_215 ,
F_116 ( V_215 ) ,
V_213 -> V_216 , V_213 ) ;
}
static struct V_217 * F_117 (
struct V_11 * V_12 , T_3 V_218 )
{
struct V_217 * V_219 = NULL ;
V_219 = F_10 ( sizeof *V_219 , V_16 ) ;
if ( ! V_219 )
return NULL ;
V_219 -> V_32 . V_49 . type = V_220 ;
V_219 -> V_32 . V_49 . V_62 = sizeof( V_219 -> V_32 ) ;
V_219 -> V_32 . V_218 = V_218 ;
return V_219 ;
}
int F_118 ( struct V_5 * V_6 ,
struct V_26 * V_27 ,
int V_55 )
{
struct V_26 * V_221 ;
struct V_157 * V_222 ;
struct V_30 * V_31 ;
struct V_40 * V_43 ;
int V_24 , V_41 , V_223 = V_27 -> V_196 ;
bool V_73 = false ;
V_41 = F_21 ( & V_6 -> V_12 -> V_14 . V_159 ,
V_6 -> V_44 ) ;
if ( V_41 )
return V_41 ;
if ( V_55 != V_224 )
V_55 = V_225 ;
V_27 -> V_196 = V_55 ;
V_31 = V_27 -> V_6 -> V_31 ;
if ( ! V_31 )
goto V_226;
V_41 = F_93 ( V_6 , V_31 ) ;
if ( V_41 )
goto V_226;
V_43 = F_17 ( V_6 , V_31 ) ;
if ( F_29 ( V_43 ) ) {
V_41 = F_30 ( V_43 ) ;
goto V_226;
}
F_107 (state, tmp_connector, new_conn_state, i) {
if ( V_222 -> V_31 != V_31 )
continue;
if ( V_221 -> V_196 == V_224 ) {
V_73 = true ;
break;
}
}
V_43 -> V_73 = V_73 ;
V_41 = F_103 ( V_6 ) ;
V_226:
if ( V_41 != 0 )
V_27 -> V_196 = V_223 ;
return V_41 ;
}
int F_119 ( struct V_5 * V_6 ,
struct V_197 * V_37 ,
struct V_69 * V_227 ,
T_3 V_228 )
{
struct V_197 * V_4 ;
int V_41 ;
if ( ! F_120 ( V_227 , V_228 , & V_4 ) )
return - V_64 ;
switch ( V_37 -> type ) {
case V_198 : {
struct V_26 * V_27 = F_85 ( V_37 ) ;
struct V_157 * V_158 ;
V_158 = F_76 ( V_6 , V_27 ) ;
if ( F_29 ( V_158 ) ) {
V_41 = F_30 ( V_158 ) ;
break;
}
V_41 = F_80 ( V_27 ,
V_158 , V_227 , V_228 ) ;
break;
}
case V_199 : {
struct V_30 * V_31 = F_87 ( V_37 ) ;
struct V_40 * V_43 ;
V_43 = F_17 ( V_6 , V_31 ) ;
if ( F_29 ( V_43 ) ) {
V_41 = F_30 ( V_43 ) ;
break;
}
V_41 = F_38 ( V_31 ,
V_43 , V_227 , V_228 ) ;
break;
}
case V_200 : {
struct V_33 * V_34 = F_88 ( V_37 ) ;
struct V_99 * V_100 ;
V_100 = F_47 ( V_6 , V_34 ) ;
if ( F_29 ( V_100 ) ) {
V_41 = F_30 ( V_100 ) ;
break;
}
V_41 = F_51 ( V_34 ,
V_100 , V_227 , V_228 ) ;
break;
}
default:
V_41 = - V_64 ;
break;
}
F_121 ( V_227 , V_4 ) ;
return V_41 ;
}
void F_122 ( struct V_11 * V_12 ,
unsigned V_94 ,
int V_41 )
{
struct V_33 * V_34 ;
F_98 (plane, dev, plane_mask) {
if ( V_41 == 0 ) {
struct V_102 * V_229 = V_34 -> V_6 -> V_103 ;
if ( V_229 )
F_123 ( V_229 ) ;
V_34 -> V_103 = V_229 ;
V_34 -> V_31 = V_34 -> V_6 -> V_31 ;
if ( V_34 -> V_230 )
F_54 ( V_34 -> V_230 ) ;
}
V_34 -> V_230 = NULL ;
}
}
static int F_124 ( struct V_231 * V_232 ,
struct V_201 * V_105 )
{
V_232 -> V_233 = F_125 ( V_234 ) ;
if ( V_232 -> V_233 < 0 )
return V_232 -> V_233 ;
if ( F_40 ( V_232 -> V_233 , V_232 -> V_53 ) )
return - V_84 ;
V_232 -> V_235 = F_126 ( V_105 ) ;
if ( ! V_232 -> V_235 )
return - V_19 ;
return 0 ;
}
static int F_127 ( struct V_11 * V_12 ,
struct V_5 * V_6 ,
struct V_236 * V_237 ,
struct V_238 * V_239 ,
struct V_231 * * V_232 ,
unsigned int * V_240 )
{
struct V_30 * V_31 ;
struct V_40 * V_43 ;
int V_24 , V_161 = 0 , V_41 ;
if ( V_237 -> V_241 & V_242 )
return 0 ;
F_101 (state, crtc, crtc_state, i) {
T_1 T_2 * V_52 ;
V_52 = F_24 ( V_43 -> V_6 , V_31 ) ;
if ( V_237 -> V_241 & V_243 || V_52 ) {
struct V_217 * V_219 ;
V_219 = F_117 ( V_12 , V_237 -> V_218 ) ;
if ( ! V_219 )
return - V_19 ;
V_43 -> V_32 = V_219 ;
}
if ( V_237 -> V_241 & V_243 ) {
struct V_217 * V_219 = V_43 -> V_32 ;
if ( ! V_239 )
continue;
V_41 = F_128 ( V_12 , V_239 , & V_219 -> V_49 ,
& V_219 -> V_32 . V_49 ) ;
if ( V_41 ) {
F_3 ( V_219 ) ;
V_43 -> V_32 = NULL ;
return V_41 ;
}
}
if ( V_52 ) {
struct V_201 * V_105 ;
struct V_231 * V_244 ;
V_244 = F_75 ( * V_232 , sizeof( * * V_232 ) *
( * V_240 + 1 ) , V_16 ) ;
if ( ! V_244 )
return - V_19 ;
memset ( & V_244 [ * V_240 ] , 0 , sizeof( * V_244 ) ) ;
V_244 [ * V_240 ] . V_53 = V_52 ;
* V_232 = V_244 ;
V_105 = F_129 ( V_31 ) ;
if ( ! V_105 )
return - V_19 ;
V_41 = F_124 ( & V_244 [ ( * V_240 ) ++ ] , V_105 ) ;
if ( V_41 ) {
F_91 ( V_105 ) ;
return V_41 ;
}
V_43 -> V_32 -> V_49 . V_105 = V_105 ;
}
V_161 ++ ;
}
if ( V_161 == 0 && ( V_237 -> V_241 & V_243 ) )
return - V_64 ;
return 0 ;
}
static void F_130 ( struct V_11 * V_12 ,
struct V_5 * V_6 ,
struct V_231 * V_232 ,
unsigned int V_240 ,
bool V_245 )
{
struct V_30 * V_31 ;
struct V_40 * V_43 ;
int V_24 ;
if ( V_245 ) {
for ( V_24 = 0 ; V_24 < V_240 ; V_24 ++ )
F_131 ( V_232 [ V_24 ] . V_233 ,
V_232 [ V_24 ] . V_235 -> V_246 ) ;
F_3 ( V_232 ) ;
return;
}
F_101 (state, crtc, crtc_state, i) {
struct V_217 * V_32 = V_43 -> V_32 ;
if ( V_32 && ( V_32 -> V_49 . V_105 || V_32 -> V_49 . V_239 ) ) {
F_132 ( V_12 , & V_32 -> V_49 ) ;
V_43 -> V_32 = NULL ;
}
}
if ( ! V_232 )
return;
for ( V_24 = 0 ; V_24 < V_240 ; V_24 ++ ) {
if ( V_232 [ V_24 ] . V_235 )
F_133 ( V_232 [ V_24 ] . V_235 -> V_246 ) ;
if ( V_232 [ V_24 ] . V_233 >= 0 )
F_134 ( V_232 [ V_24 ] . V_233 ) ;
if ( V_232 [ V_24 ] . V_53 &&
F_40 ( - 1 , V_232 [ V_24 ] . V_53 ) )
F_8 ( L_62 ) ;
}
F_3 ( V_232 ) ;
}
int F_135 ( struct V_11 * V_12 ,
void * V_63 , struct V_238 * V_239 )
{
struct V_236 * V_237 = V_63 ;
T_6 T_2 * V_247 = ( T_6 T_2 * ) ( unsigned long ) ( V_237 -> V_247 ) ;
T_6 T_2 * V_248 = ( T_6 T_2 * ) ( unsigned long ) ( V_237 -> V_248 ) ;
T_6 T_2 * V_249 = ( T_6 T_2 * ) ( unsigned long ) ( V_237 -> V_249 ) ;
T_3 T_2 * V_250 = ( T_3 T_2 * ) ( unsigned long ) ( V_237 -> V_250 ) ;
unsigned int V_251 , V_252 ;
struct V_5 * V_6 ;
struct V_253 V_254 ;
struct V_33 * V_34 ;
struct V_231 * V_232 ;
unsigned V_94 ;
int V_41 = 0 ;
unsigned int V_24 , V_255 , V_240 ;
if ( ! F_43 ( V_12 , V_87 ) )
return - V_64 ;
if ( ! V_239 -> V_256 )
return - V_64 ;
if ( V_237 -> V_241 & ~ V_257 )
return - V_64 ;
if ( V_237 -> V_258 )
return - V_64 ;
if ( ( V_237 -> V_241 & V_259 ) &&
! V_12 -> V_14 . V_260 )
return - V_64 ;
if ( ( V_237 -> V_241 & V_242 ) &&
( V_237 -> V_241 & V_243 ) )
return - V_64 ;
F_136 ( & V_254 , 0 ) ;
V_6 = F_9 ( V_12 ) ;
if ( ! V_6 )
return - V_19 ;
V_6 -> V_44 = & V_254 ;
V_6 -> V_13 = ! ! ( V_237 -> V_241 & V_261 ) ;
V_262:
V_94 = 0 ;
V_251 = 0 ;
V_252 = 0 ;
V_232 = NULL ;
V_240 = 0 ;
for ( V_24 = 0 ; V_24 < V_237 -> V_263 ; V_24 ++ ) {
T_6 V_264 , V_265 ;
struct V_197 * V_37 ;
if ( F_137 ( V_264 , V_247 + V_251 ) ) {
V_41 = - V_84 ;
goto V_226;
}
V_37 = F_138 ( V_12 , V_264 , V_266 ) ;
if ( ! V_37 ) {
V_41 = - V_267 ;
goto V_226;
}
if ( ! V_37 -> V_268 ) {
F_139 ( V_37 ) ;
V_41 = - V_267 ;
goto V_226;
}
if ( F_137 ( V_265 , V_248 + V_251 ) ) {
F_139 ( V_37 ) ;
V_41 = - V_84 ;
goto V_226;
}
V_251 ++ ;
for ( V_255 = 0 ; V_255 < V_265 ; V_255 ++ ) {
T_6 V_269 ;
T_3 V_228 ;
struct V_69 * V_227 ;
if ( F_137 ( V_269 , V_249 + V_252 ) ) {
F_139 ( V_37 ) ;
V_41 = - V_84 ;
goto V_226;
}
V_227 = F_140 ( V_37 , V_269 ) ;
if ( ! V_227 ) {
F_139 ( V_37 ) ;
V_41 = - V_267 ;
goto V_226;
}
if ( F_141 ( & V_228 ,
V_250 + V_252 ,
sizeof( V_228 ) ) ) {
F_139 ( V_37 ) ;
V_41 = - V_84 ;
goto V_226;
}
V_41 = F_119 ( V_6 , V_37 , V_227 ,
V_228 ) ;
if ( V_41 ) {
F_139 ( V_37 ) ;
goto V_226;
}
V_252 ++ ;
}
if ( V_37 -> type == V_200 && V_265 &&
! ( V_237 -> V_241 & V_242 ) ) {
V_34 = F_88 ( V_37 ) ;
V_94 |= ( 1 << F_48 ( V_34 ) ) ;
V_34 -> V_230 = V_34 -> V_103 ;
}
F_139 ( V_37 ) ;
}
V_41 = F_127 ( V_12 , V_6 , V_237 , V_239 , & V_232 ,
& V_240 ) ;
if ( V_41 )
goto V_226;
if ( V_237 -> V_241 & V_242 ) {
V_41 = F_99 ( V_6 ) ;
} else if ( V_237 -> V_241 & V_270 ) {
V_41 = F_104 ( V_6 ) ;
} else {
if ( F_142 ( V_271 & V_272 ) )
F_105 ( V_6 ) ;
V_41 = F_103 ( V_6 ) ;
}
V_226:
F_122 ( V_12 , V_94 , V_41 ) ;
F_130 ( V_12 , V_6 , V_232 , V_240 , ! V_41 ) ;
if ( V_41 == - V_273 ) {
F_14 ( V_6 ) ;
F_143 ( & V_254 ) ;
goto V_262;
}
F_144 ( V_6 ) ;
F_145 ( & V_254 ) ;
F_146 ( & V_254 ) ;
return V_41 ;
}
