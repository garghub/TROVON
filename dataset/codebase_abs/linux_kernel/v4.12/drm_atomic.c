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
}
int
F_5 ( struct V_10 * V_11 , struct V_5 * V_6 )
{
F_6 ( & V_6 -> V_4 ) ;
V_6 -> V_12 = true ;
V_6 -> V_8 = F_7 ( V_11 -> V_13 . V_14 ,
sizeof( * V_6 -> V_8 ) , V_15 ) ;
if ( ! V_6 -> V_8 )
goto V_16;
V_6 -> V_9 = F_7 ( V_11 -> V_13 . V_17 ,
sizeof( * V_6 -> V_9 ) , V_15 ) ;
if ( ! V_6 -> V_9 )
goto V_16;
V_6 -> V_11 = V_11 ;
F_8 ( L_1 , V_6 ) ;
return 0 ;
V_16:
F_4 ( V_6 ) ;
return - V_18 ;
}
struct V_5 *
F_9 ( struct V_10 * V_11 )
{
struct V_19 * V_20 = & V_11 -> V_13 ;
struct V_5 * V_6 ;
if ( ! V_20 -> V_21 -> V_22 ) {
V_6 = F_10 ( sizeof( * V_6 ) , V_15 ) ;
if ( ! V_6 )
return NULL ;
if ( F_5 ( V_11 , V_6 ) < 0 ) {
F_3 ( V_6 ) ;
return NULL ;
}
return V_6 ;
}
return V_20 -> V_21 -> V_22 ( V_11 ) ;
}
void F_11 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_19 * V_20 = & V_11 -> V_13 ;
int V_23 ;
F_8 ( L_2 , V_6 ) ;
for ( V_23 = 0 ; V_23 < V_6 -> V_24 ; V_23 ++ ) {
struct V_25 * V_26 = V_6 -> V_7 [ V_23 ] . V_27 ;
if ( ! V_26 )
continue;
V_26 -> V_21 -> V_28 ( V_26 ,
V_6 -> V_7 [ V_23 ] . V_6 ) ;
V_6 -> V_7 [ V_23 ] . V_27 = NULL ;
V_6 -> V_7 [ V_23 ] . V_6 = NULL ;
F_12 ( V_26 ) ;
}
for ( V_23 = 0 ; V_23 < V_20 -> V_14 ; V_23 ++ ) {
struct V_29 * V_30 = V_6 -> V_8 [ V_23 ] . V_27 ;
if ( ! V_30 )
continue;
V_30 -> V_21 -> V_28 ( V_30 ,
V_6 -> V_8 [ V_23 ] . V_6 ) ;
if ( V_6 -> V_8 [ V_23 ] . V_3 ) {
F_3 ( V_6 -> V_8 [ V_23 ] . V_3 -> V_31 ) ;
V_6 -> V_8 [ V_23 ] . V_3 -> V_31 = NULL ;
F_13 ( V_6 -> V_8 [ V_23 ] . V_3 ) ;
}
V_6 -> V_8 [ V_23 ] . V_3 = NULL ;
V_6 -> V_8 [ V_23 ] . V_27 = NULL ;
V_6 -> V_8 [ V_23 ] . V_6 = NULL ;
}
for ( V_23 = 0 ; V_23 < V_20 -> V_17 ; V_23 ++ ) {
struct V_32 * V_33 = V_6 -> V_9 [ V_23 ] . V_27 ;
if ( ! V_33 )
continue;
V_33 -> V_21 -> V_28 ( V_33 ,
V_6 -> V_9 [ V_23 ] . V_6 ) ;
V_6 -> V_9 [ V_23 ] . V_27 = NULL ;
V_6 -> V_9 [ V_23 ] . V_6 = NULL ;
}
}
void F_14 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_19 * V_20 = & V_11 -> V_13 ;
if ( V_20 -> V_21 -> V_34 )
V_20 -> V_21 -> V_34 ( V_6 ) ;
else
F_11 ( V_6 ) ;
}
void F_15 ( struct V_1 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 , F_16 ( * V_6 ) , V_4 ) ;
struct V_19 * V_20 = & V_6 -> V_11 -> V_13 ;
F_14 ( V_6 ) ;
F_8 ( L_3 , V_6 ) ;
if ( V_20 -> V_21 -> V_35 ) {
V_20 -> V_21 -> V_35 ( V_6 ) ;
} else {
F_4 ( V_6 ) ;
F_3 ( V_6 ) ;
}
}
struct V_36 *
F_17 ( struct V_5 * V_6 ,
struct V_29 * V_30 )
{
int V_37 , V_38 = F_18 ( V_30 ) ;
struct V_36 * V_39 ;
F_19 ( ! V_6 -> V_40 ) ;
V_39 = F_20 ( V_6 , V_30 ) ;
if ( V_39 )
return V_39 ;
V_37 = F_21 ( & V_30 -> V_41 , V_6 -> V_40 ) ;
if ( V_37 )
return F_22 ( V_37 ) ;
V_39 = V_30 -> V_21 -> V_42 ( V_30 ) ;
if ( ! V_39 )
return F_22 ( - V_18 ) ;
V_6 -> V_8 [ V_38 ] . V_6 = V_39 ;
V_6 -> V_8 [ V_38 ] . V_43 = V_30 -> V_6 ;
V_6 -> V_8 [ V_38 ] . V_44 = V_39 ;
V_6 -> V_8 [ V_38 ] . V_27 = V_30 ;
V_39 -> V_6 = V_6 ;
F_8 ( L_4 ,
V_30 -> V_45 . V_46 , V_30 -> V_47 , V_39 , V_6 ) ;
return V_39 ;
}
static void F_23 ( struct V_5 * V_6 ,
struct V_29 * V_30 , T_1 T_2 * V_48 )
{
V_6 -> V_8 [ F_18 ( V_30 ) ] . V_49 = V_48 ;
}
static T_1 T_2 * F_24 ( struct V_5 * V_6 ,
struct V_29 * V_30 )
{
T_1 T_2 * V_48 ;
V_48 = V_6 -> V_8 [ F_18 ( V_30 ) ] . V_49 ;
V_6 -> V_8 [ F_18 ( V_30 ) ] . V_49 = NULL ;
return V_48 ;
}
int F_25 ( struct V_36 * V_6 ,
struct V_50 * V_51 )
{
struct V_52 V_53 ;
if ( V_51 && memcmp ( & V_6 -> V_51 , V_51 , sizeof( * V_51 ) ) == 0 )
return 0 ;
F_26 ( V_6 -> V_54 ) ;
V_6 -> V_54 = NULL ;
if ( V_51 ) {
F_27 ( & V_53 , V_51 ) ;
V_6 -> V_54 =
F_28 ( V_6 -> V_30 -> V_11 ,
sizeof( V_53 ) ,
& V_53 ) ;
if ( F_29 ( V_6 -> V_54 ) )
return F_30 ( V_6 -> V_54 ) ;
F_31 ( & V_6 -> V_51 , V_51 ) ;
V_6 -> V_55 = true ;
F_8 ( L_5 ,
V_51 -> V_47 , V_6 ) ;
} else {
memset ( & V_6 -> V_51 , 0 , sizeof( V_6 -> V_51 ) ) ;
V_6 -> V_55 = false ;
F_8 ( L_6 ,
V_6 ) ;
}
return 0 ;
}
int F_32 ( struct V_36 * V_6 ,
struct V_56 * V_57 )
{
if ( V_57 == V_6 -> V_54 )
return 0 ;
F_26 ( V_6 -> V_54 ) ;
V_6 -> V_54 = NULL ;
memset ( & V_6 -> V_51 , 0 , sizeof( V_6 -> V_51 ) ) ;
if ( V_57 ) {
if ( V_57 -> V_58 != sizeof( struct V_52 ) ||
F_33 ( & V_6 -> V_51 ,
( const struct V_52 * )
V_57 -> V_59 ) )
return - V_60 ;
V_6 -> V_54 = F_34 ( V_57 ) ;
V_6 -> V_55 = true ;
F_8 ( L_5 ,
V_6 -> V_51 . V_47 , V_6 ) ;
} else {
V_6 -> V_55 = false ;
F_8 ( L_6 ,
V_6 ) ;
}
return 0 ;
}
static void
F_35 ( struct V_56 * * V_57 ,
struct V_56 * V_61 ,
bool * V_62 )
{
struct V_56 * V_63 = * V_57 ;
if ( V_63 == V_61 )
return;
F_26 ( V_63 ) ;
if ( V_61 )
F_34 ( V_61 ) ;
* V_57 = V_61 ;
* V_62 = true ;
return;
}
static int
F_36 ( struct V_29 * V_30 ,
struct V_56 * * V_57 ,
T_3 V_64 ,
T_4 V_65 ,
bool * V_62 )
{
struct V_56 * V_61 = NULL ;
if ( V_64 != 0 ) {
V_61 = F_37 ( V_30 -> V_11 , V_64 ) ;
if ( V_61 == NULL )
return - V_60 ;
if ( V_65 > 0 && V_65 != V_61 -> V_58 ) {
F_26 ( V_61 ) ;
return - V_60 ;
}
}
F_35 ( V_57 , V_61 , V_62 ) ;
F_26 ( V_61 ) ;
return 0 ;
}
int F_38 ( struct V_29 * V_30 ,
struct V_36 * V_6 , struct V_66 * V_67 ,
T_3 V_68 )
{
struct V_10 * V_11 = V_30 -> V_11 ;
struct V_19 * V_20 = & V_11 -> V_13 ;
bool V_62 = false ;
int V_37 ;
if ( V_67 == V_20 -> V_69 )
V_6 -> V_70 = V_68 ;
else if ( V_67 == V_20 -> V_71 ) {
struct V_56 * V_51 =
F_37 ( V_11 , V_68 ) ;
V_37 = F_32 ( V_6 , V_51 ) ;
F_26 ( V_51 ) ;
return V_37 ;
} else if ( V_67 == V_20 -> V_72 ) {
V_37 = F_36 ( V_30 ,
& V_6 -> V_73 ,
V_68 ,
- 1 ,
& V_62 ) ;
V_6 -> V_74 |= V_62 ;
return V_37 ;
} else if ( V_67 == V_20 -> V_75 ) {
V_37 = F_36 ( V_30 ,
& V_6 -> V_76 ,
V_68 ,
sizeof( struct V_77 ) ,
& V_62 ) ;
V_6 -> V_74 |= V_62 ;
return V_37 ;
} else if ( V_67 == V_20 -> V_78 ) {
V_37 = F_36 ( V_30 ,
& V_6 -> V_79 ,
V_68 ,
- 1 ,
& V_62 ) ;
V_6 -> V_74 |= V_62 ;
return V_37 ;
} else if ( V_67 == V_20 -> V_80 ) {
T_1 T_2 * V_48 = F_39 ( V_68 ) ;
if ( ! V_48 )
return 0 ;
if ( F_40 ( - 1 , V_48 ) )
return - V_81 ;
F_23 ( V_6 -> V_6 , V_30 , V_48 ) ;
} else if ( V_30 -> V_21 -> V_82 )
return V_30 -> V_21 -> V_82 ( V_30 , V_6 , V_67 , V_68 ) ;
else
return - V_60 ;
return 0 ;
}
static int
F_41 ( struct V_29 * V_30 ,
const struct V_36 * V_6 ,
struct V_66 * V_67 , T_3 * V_68 )
{
struct V_10 * V_11 = V_30 -> V_11 ;
struct V_19 * V_20 = & V_11 -> V_13 ;
if ( V_67 == V_20 -> V_69 )
* V_68 = V_6 -> V_70 ;
else if ( V_67 == V_20 -> V_71 )
* V_68 = ( V_6 -> V_54 ) ? V_6 -> V_54 -> V_45 . V_46 : 0 ;
else if ( V_67 == V_20 -> V_72 )
* V_68 = ( V_6 -> V_73 ) ? V_6 -> V_73 -> V_45 . V_46 : 0 ;
else if ( V_67 == V_20 -> V_75 )
* V_68 = ( V_6 -> V_76 ) ? V_6 -> V_76 -> V_45 . V_46 : 0 ;
else if ( V_67 == V_20 -> V_78 )
* V_68 = ( V_6 -> V_79 ) ? V_6 -> V_79 -> V_45 . V_46 : 0 ;
else if ( V_67 == V_20 -> V_80 )
* V_68 = 0 ;
else if ( V_30 -> V_21 -> V_83 )
return V_30 -> V_21 -> V_83 ( V_30 , V_6 , V_67 , V_68 ) ;
else
return - V_60 ;
return 0 ;
}
static int F_42 ( struct V_29 * V_30 ,
struct V_36 * V_6 )
{
if ( V_6 -> V_70 && ! V_6 -> V_55 ) {
F_8 ( L_7 ,
V_30 -> V_45 . V_46 , V_30 -> V_47 ) ;
return - V_60 ;
}
if ( F_43 ( V_30 -> V_11 , V_84 ) &&
F_19 ( V_6 -> V_55 && ! V_6 -> V_54 ) ) {
F_8 ( L_8 ,
V_30 -> V_45 . V_46 , V_30 -> V_47 ) ;
return - V_60 ;
}
if ( F_43 ( V_30 -> V_11 , V_84 ) &&
F_19 ( ! V_6 -> V_55 && V_6 -> V_54 ) ) {
F_8 ( L_9 ,
V_30 -> V_45 . V_46 , V_30 -> V_47 ) ;
return - V_60 ;
}
if ( V_6 -> V_31 && ! V_6 -> V_70 && ! V_30 -> V_6 -> V_70 ) {
F_8 ( L_10 ,
V_30 -> V_45 . V_46 , V_30 -> V_47 ) ;
return - V_60 ;
}
return 0 ;
}
static void F_44 ( struct V_85 * V_86 ,
const struct V_36 * V_6 )
{
struct V_29 * V_30 = V_6 -> V_30 ;
F_45 ( V_86 , L_11 , V_30 -> V_45 . V_46 , V_30 -> V_47 ) ;
F_45 ( V_86 , L_12 , V_6 -> V_55 ) ;
F_45 ( V_86 , L_13 , V_6 -> V_70 ) ;
F_45 ( V_86 , L_14 , V_6 -> V_87 ) ;
F_45 ( V_86 , L_15 , V_6 -> V_88 ) ;
F_45 ( V_86 , L_16 , V_6 -> V_89 ) ;
F_45 ( V_86 , L_17 , V_6 -> V_90 ) ;
F_45 ( V_86 , L_18 , V_6 -> V_74 ) ;
F_45 ( V_86 , L_19 , V_6 -> V_91 ) ;
F_45 ( V_86 , L_20 , V_6 -> V_92 ) ;
F_45 ( V_86 , L_21 , V_6 -> V_93 ) ;
F_45 ( V_86 , L_22 V_94 L_23 , F_46 ( & V_6 -> V_51 ) ) ;
if ( V_30 -> V_21 -> V_95 )
V_30 -> V_21 -> V_95 ( V_86 , V_6 ) ;
}
struct V_96 *
F_47 ( struct V_5 * V_6 ,
struct V_32 * V_33 )
{
int V_37 , V_38 = F_48 ( V_33 ) ;
struct V_96 * V_97 ;
F_19 ( ! V_6 -> V_40 ) ;
V_97 = F_49 ( V_6 , V_33 ) ;
if ( V_97 )
return V_97 ;
V_37 = F_21 ( & V_33 -> V_41 , V_6 -> V_40 ) ;
if ( V_37 )
return F_22 ( V_37 ) ;
V_97 = V_33 -> V_21 -> V_42 ( V_33 ) ;
if ( ! V_97 )
return F_22 ( - V_18 ) ;
V_6 -> V_9 [ V_38 ] . V_6 = V_97 ;
V_6 -> V_9 [ V_38 ] . V_27 = V_33 ;
V_6 -> V_9 [ V_38 ] . V_43 = V_33 -> V_6 ;
V_6 -> V_9 [ V_38 ] . V_44 = V_97 ;
V_97 -> V_6 = V_6 ;
F_8 ( L_24 ,
V_33 -> V_45 . V_46 , V_33 -> V_47 , V_97 , V_6 ) ;
if ( V_97 -> V_30 ) {
struct V_36 * V_39 ;
V_39 = F_17 ( V_6 ,
V_97 -> V_30 ) ;
if ( F_29 ( V_39 ) )
return F_50 ( V_39 ) ;
}
return V_97 ;
}
int F_51 ( struct V_32 * V_33 ,
struct V_96 * V_6 , struct V_66 * V_67 ,
T_3 V_68 )
{
struct V_10 * V_11 = V_33 -> V_11 ;
struct V_19 * V_20 = & V_11 -> V_13 ;
if ( V_67 == V_20 -> V_98 ) {
struct V_99 * V_100 = F_52 ( V_11 , V_68 ) ;
F_53 ( V_6 , V_100 ) ;
if ( V_100 )
F_54 ( V_100 ) ;
} else if ( V_67 == V_20 -> V_101 ) {
if ( V_6 -> V_102 )
return - V_60 ;
if ( F_55 ( V_68 ) == - 1 )
return 0 ;
V_6 -> V_102 = F_56 ( V_68 ) ;
if ( ! V_6 -> V_102 )
return - V_60 ;
} else if ( V_67 == V_20 -> V_103 ) {
struct V_29 * V_30 = F_57 ( V_11 , V_68 ) ;
return F_58 ( V_6 , V_30 ) ;
} else if ( V_67 == V_20 -> V_104 ) {
V_6 -> V_105 = F_55 ( V_68 ) ;
} else if ( V_67 == V_20 -> V_106 ) {
V_6 -> V_107 = F_55 ( V_68 ) ;
} else if ( V_67 == V_20 -> V_108 ) {
V_6 -> V_109 = V_68 ;
} else if ( V_67 == V_20 -> V_110 ) {
V_6 -> V_111 = V_68 ;
} else if ( V_67 == V_20 -> V_112 ) {
V_6 -> V_113 = V_68 ;
} else if ( V_67 == V_20 -> V_114 ) {
V_6 -> V_115 = V_68 ;
} else if ( V_67 == V_20 -> V_116 ) {
V_6 -> V_117 = V_68 ;
} else if ( V_67 == V_20 -> V_118 ) {
V_6 -> V_119 = V_68 ;
} else if ( V_67 == V_33 -> V_120 ) {
if ( ! F_59 ( V_68 & V_121 ) )
return - V_60 ;
V_6 -> V_122 = V_68 ;
} else if ( V_67 == V_33 -> V_123 ) {
V_6 -> V_124 = V_68 ;
} else if ( V_33 -> V_21 -> V_82 ) {
return V_33 -> V_21 -> V_82 ( V_33 , V_6 ,
V_67 , V_68 ) ;
} else {
return - V_60 ;
}
return 0 ;
}
static int
F_60 ( struct V_32 * V_33 ,
const struct V_96 * V_6 ,
struct V_66 * V_67 , T_3 * V_68 )
{
struct V_10 * V_11 = V_33 -> V_11 ;
struct V_19 * V_20 = & V_11 -> V_13 ;
if ( V_67 == V_20 -> V_98 ) {
* V_68 = ( V_6 -> V_100 ) ? V_6 -> V_100 -> V_45 . V_46 : 0 ;
} else if ( V_67 == V_20 -> V_101 ) {
* V_68 = - 1 ;
} else if ( V_67 == V_20 -> V_103 ) {
* V_68 = ( V_6 -> V_30 ) ? V_6 -> V_30 -> V_45 . V_46 : 0 ;
} else if ( V_67 == V_20 -> V_104 ) {
* V_68 = F_61 ( V_6 -> V_105 ) ;
} else if ( V_67 == V_20 -> V_106 ) {
* V_68 = F_61 ( V_6 -> V_107 ) ;
} else if ( V_67 == V_20 -> V_108 ) {
* V_68 = V_6 -> V_109 ;
} else if ( V_67 == V_20 -> V_110 ) {
* V_68 = V_6 -> V_111 ;
} else if ( V_67 == V_20 -> V_112 ) {
* V_68 = V_6 -> V_113 ;
} else if ( V_67 == V_20 -> V_114 ) {
* V_68 = V_6 -> V_115 ;
} else if ( V_67 == V_20 -> V_116 ) {
* V_68 = V_6 -> V_117 ;
} else if ( V_67 == V_20 -> V_118 ) {
* V_68 = V_6 -> V_119 ;
} else if ( V_67 == V_33 -> V_120 ) {
* V_68 = V_6 -> V_122 ;
} else if ( V_67 == V_33 -> V_123 ) {
* V_68 = V_6 -> V_124 ;
} else if ( V_33 -> V_21 -> V_83 ) {
return V_33 -> V_21 -> V_83 ( V_33 , V_6 , V_67 , V_68 ) ;
} else {
return - V_60 ;
}
return 0 ;
}
static bool
F_62 ( struct V_5 * V_6 ,
struct V_32 * V_33 ,
struct V_96 * V_97 )
{
if ( ! V_33 -> V_6 -> V_30 || ! V_97 -> V_30 )
return false ;
if ( V_33 -> V_6 -> V_30 == V_97 -> V_30 )
return false ;
return true ;
}
static int F_63 ( struct V_32 * V_33 ,
struct V_96 * V_6 )
{
unsigned int V_125 , V_126 ;
int V_37 ;
if ( F_19 ( V_6 -> V_30 && ! V_6 -> V_100 ) ) {
F_8 ( L_25 ) ;
return - V_60 ;
} else if ( F_19 ( V_6 -> V_100 && ! V_6 -> V_30 ) ) {
F_8 ( L_26 ) ;
return - V_60 ;
}
if ( ! V_6 -> V_30 )
return 0 ;
if ( ! ( V_33 -> V_127 & F_64 ( V_6 -> V_30 ) ) ) {
F_8 ( L_27 ) ;
return - V_60 ;
}
V_37 = F_65 ( V_33 , V_6 -> V_100 -> V_128 -> V_128 ) ;
if ( V_37 ) {
struct V_129 V_130 ;
F_8 ( L_28 ,
F_66 ( V_6 -> V_100 -> V_128 -> V_128 ,
& V_130 ) ) ;
return V_37 ;
}
if ( V_6 -> V_109 > V_131 ||
V_6 -> V_105 > V_131 - ( V_132 ) V_6 -> V_109 ||
V_6 -> V_111 > V_131 ||
V_6 -> V_107 > V_131 - ( V_132 ) V_6 -> V_111 ) {
F_8 ( L_29 ,
V_6 -> V_109 , V_6 -> V_111 ,
V_6 -> V_105 , V_6 -> V_107 ) ;
return - V_133 ;
}
V_125 = V_6 -> V_100 -> V_134 << 16 ;
V_126 = V_6 -> V_100 -> V_135 << 16 ;
if ( V_6 -> V_117 > V_125 ||
V_6 -> V_113 > V_125 - V_6 -> V_117 ||
V_6 -> V_119 > V_126 ||
V_6 -> V_115 > V_126 - V_6 -> V_119 ) {
F_8 ( L_30
L_31 ,
V_6 -> V_117 >> 16 , ( ( V_6 -> V_117 & 0xffff ) * 15625 ) >> 10 ,
V_6 -> V_119 >> 16 , ( ( V_6 -> V_119 & 0xffff ) * 15625 ) >> 10 ,
V_6 -> V_113 >> 16 , ( ( V_6 -> V_113 & 0xffff ) * 15625 ) >> 10 ,
V_6 -> V_115 >> 16 , ( ( V_6 -> V_115 & 0xffff ) * 15625 ) >> 10 ) ;
return - V_136 ;
}
if ( F_62 ( V_6 -> V_6 , V_33 , V_6 ) ) {
F_8 ( L_32 ,
V_33 -> V_45 . V_46 , V_33 -> V_47 ) ;
return - V_60 ;
}
return 0 ;
}
static void F_67 ( struct V_85 * V_86 ,
const struct V_96 * V_6 )
{
struct V_32 * V_33 = V_6 -> V_33 ;
struct V_137 V_138 = F_68 ( V_6 ) ;
struct V_137 V_139 = F_69 ( V_6 ) ;
F_45 ( V_86 , L_33 , V_33 -> V_45 . V_46 , V_33 -> V_47 ) ;
F_45 ( V_86 , L_34 , V_6 -> V_30 ? V_6 -> V_30 -> V_47 : L_35 ) ;
F_45 ( V_86 , L_36 , V_6 -> V_100 ? V_6 -> V_100 -> V_45 . V_46 : 0 ) ;
if ( V_6 -> V_100 ) {
struct V_99 * V_100 = V_6 -> V_100 ;
int V_23 , V_140 = V_100 -> V_128 -> V_141 ;
struct V_129 V_130 ;
F_45 ( V_86 , L_37 ,
F_66 ( V_100 -> V_128 -> V_128 , & V_130 ) ) ;
F_45 ( V_86 , L_38 , V_100 -> V_142 ) ;
F_45 ( V_86 , L_39 , V_100 -> V_134 , V_100 -> V_135 ) ;
F_45 ( V_86 , L_40 ) ;
for ( V_23 = 0 ; V_23 < V_140 ; V_23 ++ ) {
F_45 ( V_86 , L_41 , V_23 , V_100 -> V_143 [ V_23 ] ) ;
F_45 ( V_86 , L_42 , V_23 , V_100 -> V_144 [ V_23 ] ) ;
}
}
F_45 ( V_86 , L_43 V_145 L_23 , F_70 ( & V_139 ) ) ;
F_45 ( V_86 , L_44 V_146 L_23 , F_71 ( & V_138 ) ) ;
F_45 ( V_86 , L_45 , V_6 -> V_122 ) ;
if ( V_33 -> V_21 -> V_95 )
V_33 -> V_21 -> V_95 ( V_86 , V_6 ) ;
}
struct V_147 *
F_72 ( struct V_5 * V_6 ,
struct V_25 * V_26 )
{
int V_37 , V_38 ;
struct V_19 * V_20 = & V_26 -> V_11 -> V_13 ;
struct V_147 * V_148 ;
F_19 ( ! V_6 -> V_40 ) ;
V_37 = F_21 ( & V_20 -> V_149 , V_6 -> V_40 ) ;
if ( V_37 )
return F_22 ( V_37 ) ;
V_38 = F_73 ( V_26 ) ;
if ( V_38 >= V_6 -> V_24 ) {
struct V_150 * V_151 ;
int V_152 = F_74 ( V_38 + 1 , V_20 -> V_24 ) ;
V_151 = F_75 ( V_6 -> V_7 , V_152 * sizeof( * V_6 -> V_7 ) , V_15 ) ;
if ( ! V_151 )
return F_22 ( - V_18 ) ;
V_6 -> V_7 = V_151 ;
memset ( & V_6 -> V_7 [ V_6 -> V_24 ] , 0 ,
sizeof( * V_6 -> V_7 ) * ( V_152 - V_6 -> V_24 ) ) ;
V_6 -> V_24 = V_152 ;
}
if ( V_6 -> V_7 [ V_38 ] . V_6 )
return V_6 -> V_7 [ V_38 ] . V_6 ;
V_148 = V_26 -> V_21 -> V_42 ( V_26 ) ;
if ( ! V_148 )
return F_22 ( - V_18 ) ;
F_76 ( V_26 ) ;
V_6 -> V_7 [ V_38 ] . V_6 = V_148 ;
V_6 -> V_7 [ V_38 ] . V_43 = V_26 -> V_6 ;
V_6 -> V_7 [ V_38 ] . V_44 = V_148 ;
V_6 -> V_7 [ V_38 ] . V_27 = V_26 ;
V_148 -> V_6 = V_6 ;
F_8 ( L_46 ,
V_26 -> V_45 . V_46 , V_26 -> V_47 ,
V_148 , V_6 ) ;
if ( V_148 -> V_30 ) {
struct V_36 * V_39 ;
V_39 = F_17 ( V_6 ,
V_148 -> V_30 ) ;
if ( F_29 ( V_39 ) )
return F_50 ( V_39 ) ;
}
return V_148 ;
}
int F_77 ( struct V_25 * V_26 ,
struct V_147 * V_6 , struct V_66 * V_67 ,
T_3 V_68 )
{
struct V_10 * V_11 = V_26 -> V_11 ;
struct V_19 * V_20 = & V_11 -> V_13 ;
if ( V_67 == V_20 -> V_103 ) {
struct V_29 * V_30 = F_57 ( V_11 , V_68 ) ;
return F_78 ( V_6 , V_30 ) ;
} else if ( V_67 == V_20 -> V_153 ) {
return - V_60 ;
} else if ( V_67 == V_20 -> V_154 ) {
V_6 -> V_155 . V_156 = V_68 ;
} else if ( V_67 == V_20 -> V_157 ) {
V_6 -> V_155 . V_158 . V_159 = V_68 ;
} else if ( V_67 == V_20 -> V_160 ) {
V_6 -> V_155 . V_158 . V_161 = V_68 ;
} else if ( V_67 == V_20 -> V_162 ) {
V_6 -> V_155 . V_158 . V_163 = V_68 ;
} else if ( V_67 == V_20 -> V_164 ) {
V_6 -> V_155 . V_158 . V_165 = V_68 ;
} else if ( V_67 == V_20 -> V_166 ) {
V_6 -> V_155 . V_51 = V_68 ;
} else if ( V_67 == V_20 -> V_167 ) {
V_6 -> V_155 . V_168 = V_68 ;
} else if ( V_67 == V_20 -> V_169 ) {
V_6 -> V_155 . V_170 = V_68 ;
} else if ( V_67 == V_20 -> V_171 ) {
V_6 -> V_155 . V_172 = V_68 ;
} else if ( V_67 == V_20 -> V_173 ) {
V_6 -> V_155 . V_174 = V_68 ;
} else if ( V_67 == V_20 -> V_175 ) {
V_6 -> V_155 . V_176 = V_68 ;
} else if ( V_67 == V_20 -> V_177 ) {
V_6 -> V_155 . V_178 = V_68 ;
} else if ( V_67 == V_20 -> V_179 ) {
if ( V_6 -> V_180 != V_181 )
V_6 -> V_180 = V_68 ;
} else if ( V_26 -> V_21 -> V_82 ) {
return V_26 -> V_21 -> V_82 ( V_26 ,
V_6 , V_67 , V_68 ) ;
} else {
return - V_60 ;
}
return 0 ;
}
static void F_79 ( struct V_85 * V_86 ,
const struct V_147 * V_6 )
{
struct V_25 * V_26 = V_6 -> V_26 ;
F_45 ( V_86 , L_47 , V_26 -> V_45 . V_46 , V_26 -> V_47 ) ;
F_45 ( V_86 , L_34 , V_6 -> V_30 ? V_6 -> V_30 -> V_47 : L_35 ) ;
if ( V_26 -> V_21 -> V_95 )
V_26 -> V_21 -> V_95 ( V_86 , V_6 ) ;
}
static int
F_80 ( struct V_25 * V_26 ,
const struct V_147 * V_6 ,
struct V_66 * V_67 , T_3 * V_68 )
{
struct V_10 * V_11 = V_26 -> V_11 ;
struct V_19 * V_20 = & V_11 -> V_13 ;
if ( V_67 == V_20 -> V_103 ) {
* V_68 = ( V_6 -> V_30 ) ? V_6 -> V_30 -> V_45 . V_46 : 0 ;
} else if ( V_67 == V_20 -> V_153 ) {
* V_68 = V_26 -> V_182 ;
} else if ( V_67 == V_20 -> V_154 ) {
* V_68 = V_6 -> V_155 . V_156 ;
} else if ( V_67 == V_20 -> V_157 ) {
* V_68 = V_6 -> V_155 . V_158 . V_159 ;
} else if ( V_67 == V_20 -> V_160 ) {
* V_68 = V_6 -> V_155 . V_158 . V_161 ;
} else if ( V_67 == V_20 -> V_162 ) {
* V_68 = V_6 -> V_155 . V_158 . V_163 ;
} else if ( V_67 == V_20 -> V_164 ) {
* V_68 = V_6 -> V_155 . V_158 . V_165 ;
} else if ( V_67 == V_20 -> V_166 ) {
* V_68 = V_6 -> V_155 . V_51 ;
} else if ( V_67 == V_20 -> V_167 ) {
* V_68 = V_6 -> V_155 . V_168 ;
} else if ( V_67 == V_20 -> V_169 ) {
* V_68 = V_6 -> V_155 . V_170 ;
} else if ( V_67 == V_20 -> V_171 ) {
* V_68 = V_6 -> V_155 . V_172 ;
} else if ( V_67 == V_20 -> V_173 ) {
* V_68 = V_6 -> V_155 . V_174 ;
} else if ( V_67 == V_20 -> V_175 ) {
* V_68 = V_6 -> V_155 . V_176 ;
} else if ( V_67 == V_20 -> V_177 ) {
* V_68 = V_6 -> V_155 . V_178 ;
} else if ( V_67 == V_20 -> V_179 ) {
* V_68 = V_6 -> V_180 ;
} else if ( V_26 -> V_21 -> V_83 ) {
return V_26 -> V_21 -> V_83 ( V_26 ,
V_6 , V_67 , V_68 ) ;
} else {
return - V_60 ;
}
return 0 ;
}
int F_81 ( struct V_183 * V_184 ,
struct V_66 * V_67 , T_3 * V_68 )
{
struct V_10 * V_11 = V_67 -> V_11 ;
int V_37 ;
switch ( V_184 -> type ) {
case V_185 : {
struct V_25 * V_26 = F_82 ( V_184 ) ;
F_19 ( ! F_83 ( & V_11 -> V_13 . V_149 ) ) ;
V_37 = F_80 ( V_26 ,
V_26 -> V_6 , V_67 , V_68 ) ;
break;
}
case V_186 : {
struct V_29 * V_30 = F_84 ( V_184 ) ;
F_19 ( ! F_83 ( & V_30 -> V_41 ) ) ;
V_37 = F_41 ( V_30 ,
V_30 -> V_6 , V_67 , V_68 ) ;
break;
}
case V_187 : {
struct V_32 * V_33 = F_85 ( V_184 ) ;
F_19 ( ! F_83 ( & V_33 -> V_41 ) ) ;
V_37 = F_60 ( V_33 ,
V_33 -> V_6 , V_67 , V_68 ) ;
break;
}
default:
V_37 = - V_60 ;
break;
}
return V_37 ;
}
int
F_58 ( struct V_96 * V_97 ,
struct V_29 * V_30 )
{
struct V_32 * V_33 = V_97 -> V_33 ;
struct V_36 * V_39 ;
if ( V_97 -> V_30 ) {
V_39 = F_17 ( V_97 -> V_6 ,
V_97 -> V_30 ) ;
if ( F_19 ( F_29 ( V_39 ) ) )
return F_30 ( V_39 ) ;
V_39 -> V_91 &= ~ ( 1 << F_48 ( V_33 ) ) ;
}
V_97 -> V_30 = V_30 ;
if ( V_30 ) {
V_39 = F_17 ( V_97 -> V_6 ,
V_30 ) ;
if ( F_29 ( V_39 ) )
return F_30 ( V_39 ) ;
V_39 -> V_91 |= ( 1 << F_48 ( V_33 ) ) ;
}
if ( V_30 )
F_8 ( L_48 ,
V_97 , V_30 -> V_45 . V_46 , V_30 -> V_47 ) ;
else
F_8 ( L_49 ,
V_97 ) ;
return 0 ;
}
void
F_53 ( struct V_96 * V_97 ,
struct V_99 * V_100 )
{
if ( V_100 )
F_8 ( L_50 ,
V_100 -> V_45 . V_46 , V_97 ) ;
else
F_8 ( L_51 ,
V_97 ) ;
F_86 ( & V_97 -> V_100 , V_100 ) ;
}
void
F_87 ( struct V_96 * V_97 ,
struct V_188 * V_102 )
{
if ( V_97 -> V_102 ) {
F_88 ( V_102 ) ;
return;
}
V_97 -> V_102 = V_102 ;
}
int
F_78 ( struct V_147 * V_189 ,
struct V_29 * V_30 )
{
struct V_36 * V_39 ;
if ( V_189 -> V_30 == V_30 )
return 0 ;
if ( V_189 -> V_30 ) {
V_39 = F_89 ( V_189 -> V_6 ,
V_189 -> V_30 ) ;
V_39 -> V_92 &=
~ ( 1 << F_73 ( V_189 -> V_26 ) ) ;
F_12 ( V_189 -> V_26 ) ;
V_189 -> V_30 = NULL ;
}
if ( V_30 ) {
V_39 = F_17 ( V_189 -> V_6 , V_30 ) ;
if ( F_29 ( V_39 ) )
return F_30 ( V_39 ) ;
V_39 -> V_92 |=
1 << F_73 ( V_189 -> V_26 ) ;
F_76 ( V_189 -> V_26 ) ;
V_189 -> V_30 = V_30 ;
F_8 ( L_52 ,
V_189 , V_30 -> V_45 . V_46 , V_30 -> V_47 ) ;
} else {
F_8 ( L_53 ,
V_189 ) ;
}
return 0 ;
}
int
F_90 ( struct V_5 * V_6 ,
struct V_29 * V_30 )
{
struct V_19 * V_20 = & V_6 -> V_11 -> V_13 ;
struct V_25 * V_26 ;
struct V_147 * V_189 ;
struct V_190 V_191 ;
struct V_36 * V_39 ;
int V_37 ;
V_39 = F_17 ( V_6 , V_30 ) ;
if ( F_29 ( V_39 ) )
return F_30 ( V_39 ) ;
V_37 = F_21 ( & V_20 -> V_149 , V_6 -> V_40 ) ;
if ( V_37 )
return V_37 ;
F_8 ( L_54 ,
V_30 -> V_45 . V_46 , V_30 -> V_47 , V_6 ) ;
F_91 ( V_6 -> V_11 , & V_191 ) ;
F_92 (connector, &conn_iter) {
if ( ! ( V_39 -> V_92 & ( 1 << F_73 ( V_26 ) ) ) )
continue;
V_189 = F_72 ( V_6 , V_26 ) ;
if ( F_29 ( V_189 ) ) {
F_93 ( & V_191 ) ;
return F_30 ( V_189 ) ;
}
}
F_93 ( & V_191 ) ;
return 0 ;
}
int
F_94 ( struct V_5 * V_6 ,
struct V_29 * V_30 )
{
struct V_32 * V_33 ;
F_19 ( ! F_89 ( V_6 , V_30 ) ) ;
F_95 (plane, state->dev, crtc->state->plane_mask) {
struct V_96 * V_97 =
F_47 ( V_6 , V_33 ) ;
if ( F_29 ( V_97 ) )
return F_30 ( V_97 ) ;
}
return 0 ;
}
void F_96 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
int V_37 ;
bool V_192 = false ;
if ( F_19 ( V_11 -> V_13 . V_40 == V_6 -> V_40 ) ) {
V_192 = true ;
V_11 -> V_13 . V_40 = NULL ;
}
V_193:
F_97 ( V_6 -> V_40 ) ;
V_37 = F_98 ( V_11 , V_6 -> V_40 ) ;
if ( V_37 )
goto V_193;
if ( V_192 )
V_11 -> V_13 . V_40 = V_6 -> V_40 ;
}
int F_99 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_19 * V_20 = & V_11 -> V_13 ;
struct V_32 * V_33 ;
struct V_96 * V_97 ;
struct V_29 * V_30 ;
struct V_36 * V_39 ;
int V_23 , V_37 = 0 ;
F_8 ( L_55 , V_6 ) ;
F_100 (state, plane, plane_state, i) {
V_37 = F_63 ( V_33 , V_97 ) ;
if ( V_37 ) {
F_8 ( L_56 ,
V_33 -> V_45 . V_46 , V_33 -> V_47 ) ;
return V_37 ;
}
}
F_101 (state, crtc, crtc_state, i) {
V_37 = F_42 ( V_30 , V_39 ) ;
if ( V_37 ) {
F_8 ( L_57 ,
V_30 -> V_45 . V_46 , V_30 -> V_47 ) ;
return V_37 ;
}
}
if ( V_20 -> V_21 -> V_194 )
V_37 = V_20 -> V_21 -> V_194 ( V_6 -> V_11 , V_6 ) ;
if ( ! V_6 -> V_12 ) {
F_101 (state, crtc, crtc_state, i) {
if ( F_102 ( V_39 ) ) {
F_8 ( L_58 ,
V_30 -> V_45 . V_46 , V_30 -> V_47 ) ;
return - V_60 ;
}
}
}
return V_37 ;
}
int F_103 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = & V_6 -> V_11 -> V_13 ;
int V_37 ;
V_37 = F_99 ( V_6 ) ;
if ( V_37 )
return V_37 ;
F_8 ( L_59 , V_6 ) ;
return V_20 -> V_21 -> V_195 ( V_6 -> V_11 , V_6 , false ) ;
}
int F_104 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = & V_6 -> V_11 -> V_13 ;
int V_37 ;
V_37 = F_99 ( V_6 ) ;
if ( V_37 )
return V_37 ;
F_8 ( L_60 , V_6 ) ;
return V_20 -> V_21 -> V_195 ( V_6 -> V_11 , V_6 , true ) ;
}
static void F_105 ( const struct V_5 * V_6 )
{
struct V_85 V_86 = F_106 ( V_6 -> V_11 -> V_11 ) ;
struct V_32 * V_33 ;
struct V_96 * V_97 ;
struct V_29 * V_30 ;
struct V_36 * V_39 ;
struct V_25 * V_26 ;
struct V_147 * V_148 ;
int V_23 ;
F_8 ( L_55 , V_6 ) ;
F_100 (state, plane, plane_state, i)
F_67 ( & V_86 , V_97 ) ;
F_101 (state, crtc, crtc_state, i)
F_44 ( & V_86 , V_39 ) ;
F_107 (state, connector, connector_state, i)
F_79 ( & V_86 , V_148 ) ;
}
static void F_108 ( struct V_10 * V_11 , struct V_85 * V_86 ,
bool V_196 )
{
struct V_19 * V_20 = & V_11 -> V_13 ;
struct V_32 * V_33 ;
struct V_29 * V_30 ;
struct V_25 * V_26 ;
struct V_190 V_191 ;
if ( ! F_43 ( V_11 , V_84 ) )
return;
F_109 (plane, &config->plane_list, head) {
if ( V_196 )
F_21 ( & V_33 -> V_41 , NULL ) ;
F_67 ( V_86 , V_33 -> V_6 ) ;
if ( V_196 )
F_110 ( & V_33 -> V_41 ) ;
}
F_109 (crtc, &config->crtc_list, head) {
if ( V_196 )
F_21 ( & V_30 -> V_41 , NULL ) ;
F_44 ( V_86 , V_30 -> V_6 ) ;
if ( V_196 )
F_110 ( & V_30 -> V_41 ) ;
}
F_91 ( V_11 , & V_191 ) ;
if ( V_196 )
F_21 ( & V_11 -> V_13 . V_149 , NULL ) ;
F_92 (connector, &conn_iter)
F_79 ( V_86 , V_26 -> V_6 ) ;
if ( V_196 )
F_110 ( & V_11 -> V_13 . V_149 ) ;
F_93 ( & V_191 ) ;
}
void F_111 ( struct V_10 * V_11 , struct V_85 * V_86 )
{
F_108 ( V_11 , V_86 , false ) ;
}
static int F_112 ( struct V_197 * V_198 , void * V_59 )
{
struct V_199 * V_200 = (struct V_199 * ) V_198 -> V_201 ;
struct V_10 * V_11 = V_200 -> V_202 -> V_11 ;
struct V_85 V_86 = F_113 ( V_198 ) ;
F_108 ( V_11 , & V_86 , true ) ;
return 0 ;
}
int F_114 ( struct V_203 * V_202 )
{
return F_115 ( V_204 ,
F_116 ( V_204 ) ,
V_202 -> V_205 , V_202 ) ;
}
static struct V_206 * F_117 (
struct V_10 * V_11 , T_3 V_207 )
{
struct V_206 * V_208 = NULL ;
V_208 = F_10 ( sizeof *V_208 , V_15 ) ;
if ( ! V_208 )
return NULL ;
V_208 -> V_31 . V_45 . type = V_209 ;
V_208 -> V_31 . V_45 . V_58 = sizeof( V_208 -> V_31 ) ;
V_208 -> V_31 . V_207 = V_207 ;
return V_208 ;
}
static int F_118 ( struct V_5 * V_6 ,
struct V_183 * V_184 , struct V_66 * V_210 ,
T_3 V_211 )
{
struct V_183 * V_4 ;
int V_37 ;
if ( ! F_119 ( V_210 , V_211 , & V_4 ) )
return - V_60 ;
switch ( V_184 -> type ) {
case V_185 : {
struct V_25 * V_26 = F_82 ( V_184 ) ;
struct V_147 * V_148 ;
V_148 = F_72 ( V_6 , V_26 ) ;
if ( F_29 ( V_148 ) ) {
V_37 = F_30 ( V_148 ) ;
break;
}
V_37 = F_77 ( V_26 ,
V_148 , V_210 , V_211 ) ;
break;
}
case V_186 : {
struct V_29 * V_30 = F_84 ( V_184 ) ;
struct V_36 * V_39 ;
V_39 = F_17 ( V_6 , V_30 ) ;
if ( F_29 ( V_39 ) ) {
V_37 = F_30 ( V_39 ) ;
break;
}
V_37 = F_38 ( V_30 ,
V_39 , V_210 , V_211 ) ;
break;
}
case V_187 : {
struct V_32 * V_33 = F_85 ( V_184 ) ;
struct V_96 * V_97 ;
V_97 = F_47 ( V_6 , V_33 ) ;
if ( F_29 ( V_97 ) ) {
V_37 = F_30 ( V_97 ) ;
break;
}
V_37 = F_51 ( V_33 ,
V_97 , V_210 , V_211 ) ;
break;
}
default:
V_37 = - V_60 ;
break;
}
F_120 ( V_210 , V_4 ) ;
return V_37 ;
}
void F_121 ( struct V_10 * V_11 ,
unsigned V_91 ,
int V_37 )
{
struct V_32 * V_33 ;
F_95 (plane, dev, plane_mask) {
if ( V_37 == 0 ) {
struct V_99 * V_212 = V_33 -> V_6 -> V_100 ;
if ( V_212 )
F_122 ( V_212 ) ;
V_33 -> V_100 = V_212 ;
V_33 -> V_30 = V_33 -> V_6 -> V_30 ;
if ( V_33 -> V_213 )
F_54 ( V_33 -> V_213 ) ;
}
V_33 -> V_213 = NULL ;
}
}
static int F_123 ( struct V_214 * V_215 ,
struct V_188 * V_102 )
{
V_215 -> V_216 = F_124 ( V_217 ) ;
if ( V_215 -> V_216 < 0 )
return V_215 -> V_216 ;
if ( F_40 ( V_215 -> V_216 , V_215 -> V_49 ) )
return - V_81 ;
V_215 -> V_218 = F_125 ( V_102 ) ;
if ( ! V_215 -> V_218 )
return - V_18 ;
return 0 ;
}
static int F_126 ( struct V_10 * V_11 ,
struct V_5 * V_6 ,
struct V_219 * V_220 ,
struct V_221 * V_222 ,
struct V_214 * * V_215 ,
unsigned int * V_223 )
{
struct V_29 * V_30 ;
struct V_36 * V_39 ;
int V_23 , V_37 ;
if ( V_220 -> V_224 & V_225 )
return 0 ;
F_101 (state, crtc, crtc_state, i) {
T_1 T_2 * V_48 ;
V_48 = F_24 ( V_39 -> V_6 , V_30 ) ;
if ( V_220 -> V_224 & V_226 || V_48 ) {
struct V_206 * V_208 ;
V_208 = F_117 ( V_11 , V_220 -> V_207 ) ;
if ( ! V_208 )
return - V_18 ;
V_39 -> V_31 = V_208 ;
}
if ( V_220 -> V_224 & V_226 ) {
struct V_206 * V_208 = V_39 -> V_31 ;
if ( ! V_222 )
continue;
V_37 = F_127 ( V_11 , V_222 , & V_208 -> V_45 ,
& V_208 -> V_31 . V_45 ) ;
if ( V_37 ) {
F_3 ( V_208 ) ;
V_39 -> V_31 = NULL ;
return V_37 ;
}
}
if ( V_48 ) {
struct V_188 * V_102 ;
struct V_214 * V_227 ;
V_227 = F_75 ( * V_215 , sizeof( * * V_215 ) *
( * V_223 + 1 ) , V_15 ) ;
if ( ! V_227 )
return - V_18 ;
memset ( & V_227 [ * V_223 ] , 0 , sizeof( * V_227 ) ) ;
V_227 [ * V_223 ] . V_49 = V_48 ;
* V_215 = V_227 ;
V_102 = F_128 ( V_30 ) ;
if ( ! V_102 )
return - V_18 ;
V_37 = F_123 ( & V_227 [ ( * V_223 ) ++ ] , V_102 ) ;
if ( V_37 ) {
F_88 ( V_102 ) ;
return V_37 ;
}
V_39 -> V_31 -> V_45 . V_102 = V_102 ;
}
}
return 0 ;
}
static void F_129 ( struct V_10 * V_11 ,
struct V_5 * V_6 ,
struct V_214 * V_215 ,
unsigned int V_223 ,
bool V_228 )
{
struct V_29 * V_30 ;
struct V_36 * V_39 ;
int V_23 ;
if ( V_228 ) {
for ( V_23 = 0 ; V_23 < V_223 ; V_23 ++ )
F_130 ( V_215 [ V_23 ] . V_216 ,
V_215 [ V_23 ] . V_218 -> V_229 ) ;
F_3 ( V_215 ) ;
return;
}
F_101 (state, crtc, crtc_state, i) {
struct V_206 * V_31 = V_39 -> V_31 ;
if ( V_31 && ( V_31 -> V_45 . V_102 || V_31 -> V_45 . V_222 ) ) {
F_131 ( V_11 , & V_31 -> V_45 ) ;
V_39 -> V_31 = NULL ;
}
}
if ( ! V_215 )
return;
for ( V_23 = 0 ; V_23 < V_223 ; V_23 ++ ) {
if ( V_215 [ V_23 ] . V_218 )
F_132 ( V_215 [ V_23 ] . V_218 -> V_229 ) ;
if ( V_215 [ V_23 ] . V_216 >= 0 )
F_133 ( V_215 [ V_23 ] . V_216 ) ;
if ( V_215 [ V_23 ] . V_49 &&
F_40 ( - 1 , V_215 [ V_23 ] . V_49 ) )
F_8 ( L_61 ) ;
}
F_3 ( V_215 ) ;
}
int F_134 ( struct V_10 * V_11 ,
void * V_59 , struct V_221 * V_222 )
{
struct V_219 * V_220 = V_59 ;
T_5 T_2 * V_230 = ( T_5 T_2 * ) ( unsigned long ) ( V_220 -> V_230 ) ;
T_5 T_2 * V_231 = ( T_5 T_2 * ) ( unsigned long ) ( V_220 -> V_231 ) ;
T_5 T_2 * V_232 = ( T_5 T_2 * ) ( unsigned long ) ( V_220 -> V_232 ) ;
T_3 T_2 * V_233 = ( T_3 T_2 * ) ( unsigned long ) ( V_220 -> V_233 ) ;
unsigned int V_234 , V_235 ;
struct V_5 * V_6 ;
struct V_236 V_237 ;
struct V_32 * V_33 ;
struct V_214 * V_215 = NULL ;
unsigned V_91 ;
int V_37 = 0 ;
unsigned int V_23 , V_238 , V_223 = 0 ;
if ( ! F_43 ( V_11 , V_84 ) )
return - V_60 ;
if ( ! V_222 -> V_239 )
return - V_60 ;
if ( V_220 -> V_224 & ~ V_240 )
return - V_60 ;
if ( V_220 -> V_241 )
return - V_60 ;
if ( ( V_220 -> V_224 & V_242 ) &&
! V_11 -> V_13 . V_243 )
return - V_60 ;
if ( ( V_220 -> V_224 & V_225 ) &&
( V_220 -> V_224 & V_226 ) )
return - V_60 ;
F_135 ( & V_237 , 0 ) ;
V_6 = F_9 ( V_11 ) ;
if ( ! V_6 )
return - V_18 ;
V_6 -> V_40 = & V_237 ;
V_6 -> V_12 = ! ! ( V_220 -> V_224 & V_244 ) ;
V_193:
V_91 = 0 ;
V_234 = 0 ;
V_235 = 0 ;
for ( V_23 = 0 ; V_23 < V_220 -> V_245 ; V_23 ++ ) {
T_5 V_246 , V_247 ;
struct V_183 * V_184 ;
if ( F_136 ( V_246 , V_230 + V_234 ) ) {
V_37 = - V_81 ;
goto V_248;
}
V_184 = F_137 ( V_11 , V_246 , V_249 ) ;
if ( ! V_184 ) {
V_37 = - V_250 ;
goto V_248;
}
if ( ! V_184 -> V_251 ) {
F_138 ( V_184 ) ;
V_37 = - V_250 ;
goto V_248;
}
if ( F_136 ( V_247 , V_231 + V_234 ) ) {
F_138 ( V_184 ) ;
V_37 = - V_81 ;
goto V_248;
}
V_234 ++ ;
for ( V_238 = 0 ; V_238 < V_247 ; V_238 ++ ) {
T_5 V_252 ;
T_3 V_211 ;
struct V_66 * V_210 ;
if ( F_136 ( V_252 , V_232 + V_235 ) ) {
F_138 ( V_184 ) ;
V_37 = - V_81 ;
goto V_248;
}
V_210 = F_139 ( V_184 , V_252 ) ;
if ( ! V_210 ) {
F_138 ( V_184 ) ;
V_37 = - V_250 ;
goto V_248;
}
if ( F_140 ( & V_211 ,
V_233 + V_235 ,
sizeof( V_211 ) ) ) {
F_138 ( V_184 ) ;
V_37 = - V_81 ;
goto V_248;
}
V_37 = F_118 ( V_6 , V_184 , V_210 , V_211 ) ;
if ( V_37 ) {
F_138 ( V_184 ) ;
goto V_248;
}
V_235 ++ ;
}
if ( V_184 -> type == V_187 && V_247 &&
! ( V_220 -> V_224 & V_225 ) ) {
V_33 = F_85 ( V_184 ) ;
V_91 |= ( 1 << F_48 ( V_33 ) ) ;
V_33 -> V_213 = V_33 -> V_100 ;
}
F_138 ( V_184 ) ;
}
V_37 = F_126 ( V_11 , V_6 , V_220 , V_222 , & V_215 ,
& V_223 ) ;
if ( V_37 )
goto V_248;
if ( V_220 -> V_224 & V_225 ) {
V_37 = F_99 ( V_6 ) ;
} else if ( V_220 -> V_224 & V_253 ) {
V_37 = F_104 ( V_6 ) ;
} else {
if ( F_141 ( V_254 & V_255 ) )
F_105 ( V_6 ) ;
V_37 = F_103 ( V_6 ) ;
}
V_248:
F_121 ( V_11 , V_91 , V_37 ) ;
F_129 ( V_11 , V_6 , V_215 , V_223 , ! V_37 ) ;
if ( V_37 == - V_256 ) {
F_14 ( V_6 ) ;
F_97 ( & V_237 ) ;
goto V_193;
}
F_142 ( V_6 ) ;
F_143 ( & V_237 ) ;
F_144 ( & V_237 ) ;
return V_37 ;
}
