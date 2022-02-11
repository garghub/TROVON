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
void * V_36 = V_6 -> V_10 [ V_24 ] . V_36 ;
V_6 -> V_10 [ V_24 ] . V_22 -> V_37 ( V_36 ) ;
V_6 -> V_10 [ V_24 ] . V_38 = NULL ;
V_6 -> V_10 [ V_24 ] . V_36 = NULL ;
V_6 -> V_10 [ V_24 ] . V_22 = NULL ;
}
V_6 -> V_35 = 0 ;
}
void F_14 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = V_6 -> V_12 ;
struct V_20 * V_21 = & V_12 -> V_14 ;
if ( V_21 -> V_22 -> V_39 )
V_21 -> V_22 -> V_39 ( V_6 ) ;
else
F_11 ( V_6 ) ;
}
void F_15 ( struct V_1 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 , F_16 ( * V_6 ) , V_4 ) ;
struct V_20 * V_21 = & V_6 -> V_12 -> V_14 ;
F_14 ( V_6 ) ;
F_8 ( L_3 , V_6 ) ;
if ( V_21 -> V_22 -> V_40 ) {
V_21 -> V_22 -> V_40 ( V_6 ) ;
} else {
F_4 ( V_6 ) ;
F_3 ( V_6 ) ;
}
}
struct V_41 *
F_17 ( struct V_5 * V_6 ,
struct V_30 * V_31 )
{
int V_42 , V_43 = F_18 ( V_31 ) ;
struct V_41 * V_44 ;
F_19 ( ! V_6 -> V_45 ) ;
V_44 = F_20 ( V_6 , V_31 ) ;
if ( V_44 )
return V_44 ;
V_42 = F_21 ( & V_31 -> V_46 , V_6 -> V_45 ) ;
if ( V_42 )
return F_22 ( V_42 ) ;
V_44 = V_31 -> V_22 -> V_47 ( V_31 ) ;
if ( ! V_44 )
return F_22 ( - V_19 ) ;
V_6 -> V_8 [ V_43 ] . V_6 = V_44 ;
V_6 -> V_8 [ V_43 ] . V_48 = V_31 -> V_6 ;
V_6 -> V_8 [ V_43 ] . V_49 = V_44 ;
V_6 -> V_8 [ V_43 ] . V_28 = V_31 ;
V_44 -> V_6 = V_6 ;
F_8 ( L_4 ,
V_31 -> V_50 . V_51 , V_31 -> V_52 , V_44 , V_6 ) ;
return V_44 ;
}
static void F_23 ( struct V_5 * V_6 ,
struct V_30 * V_31 , T_1 T_2 * V_53 )
{
V_6 -> V_8 [ F_18 ( V_31 ) ] . V_54 = V_53 ;
}
static T_1 T_2 * F_24 ( struct V_5 * V_6 ,
struct V_30 * V_31 )
{
T_1 T_2 * V_53 ;
V_53 = V_6 -> V_8 [ F_18 ( V_31 ) ] . V_54 ;
V_6 -> V_8 [ F_18 ( V_31 ) ] . V_54 = NULL ;
return V_53 ;
}
int F_25 ( struct V_41 * V_6 ,
const struct V_55 * V_56 )
{
struct V_57 V_58 ;
if ( V_56 && memcmp ( & V_6 -> V_56 , V_56 , sizeof( * V_56 ) ) == 0 )
return 0 ;
F_26 ( V_6 -> V_59 ) ;
V_6 -> V_59 = NULL ;
if ( V_56 ) {
F_27 ( & V_58 , V_56 ) ;
V_6 -> V_59 =
F_28 ( V_6 -> V_31 -> V_12 ,
sizeof( V_58 ) ,
& V_58 ) ;
if ( F_29 ( V_6 -> V_59 ) )
return F_30 ( V_6 -> V_59 ) ;
F_31 ( & V_6 -> V_56 , V_56 ) ;
V_6 -> V_60 = true ;
F_8 ( L_5 ,
V_56 -> V_52 , V_6 ) ;
} else {
memset ( & V_6 -> V_56 , 0 , sizeof( V_6 -> V_56 ) ) ;
V_6 -> V_60 = false ;
F_8 ( L_6 ,
V_6 ) ;
}
return 0 ;
}
int F_32 ( struct V_41 * V_6 ,
struct V_61 * V_62 )
{
if ( V_62 == V_6 -> V_59 )
return 0 ;
F_26 ( V_6 -> V_59 ) ;
V_6 -> V_59 = NULL ;
memset ( & V_6 -> V_56 , 0 , sizeof( V_6 -> V_56 ) ) ;
if ( V_62 ) {
if ( V_62 -> V_63 != sizeof( struct V_57 ) ||
F_33 ( & V_6 -> V_56 ,
( const struct V_57 * )
V_62 -> V_64 ) )
return - V_65 ;
V_6 -> V_59 = F_34 ( V_62 ) ;
V_6 -> V_60 = true ;
F_8 ( L_5 ,
V_6 -> V_56 . V_52 , V_6 ) ;
} else {
V_6 -> V_60 = false ;
F_8 ( L_6 ,
V_6 ) ;
}
return 0 ;
}
static void
F_35 ( struct V_61 * * V_62 ,
struct V_61 * V_66 ,
bool * V_67 )
{
struct V_61 * V_68 = * V_62 ;
if ( V_68 == V_66 )
return;
F_26 ( V_68 ) ;
if ( V_66 )
F_34 ( V_66 ) ;
* V_62 = V_66 ;
* V_67 = true ;
return;
}
static int
F_36 ( struct V_11 * V_12 ,
struct V_61 * * V_62 ,
T_3 V_69 ,
T_4 V_70 ,
bool * V_67 )
{
struct V_61 * V_66 = NULL ;
if ( V_69 != 0 ) {
V_66 = F_37 ( V_12 , V_69 ) ;
if ( V_66 == NULL )
return - V_65 ;
if ( V_70 > 0 && V_70 != V_66 -> V_63 ) {
F_26 ( V_66 ) ;
return - V_65 ;
}
}
F_35 ( V_62 , V_66 , V_67 ) ;
F_26 ( V_66 ) ;
return 0 ;
}
int F_38 ( struct V_30 * V_31 ,
struct V_41 * V_6 , struct V_71 * V_72 ,
T_3 V_73 )
{
struct V_11 * V_12 = V_31 -> V_12 ;
struct V_20 * V_21 = & V_12 -> V_14 ;
bool V_67 = false ;
int V_42 ;
if ( V_72 == V_21 -> V_74 )
V_6 -> V_75 = V_73 ;
else if ( V_72 == V_21 -> V_76 ) {
struct V_61 * V_56 =
F_37 ( V_12 , V_73 ) ;
V_42 = F_32 ( V_6 , V_56 ) ;
F_26 ( V_56 ) ;
return V_42 ;
} else if ( V_72 == V_21 -> V_77 ) {
V_42 = F_36 ( V_12 ,
& V_6 -> V_78 ,
V_73 ,
- 1 ,
& V_67 ) ;
V_6 -> V_79 |= V_67 ;
return V_42 ;
} else if ( V_72 == V_21 -> V_80 ) {
V_42 = F_36 ( V_12 ,
& V_6 -> V_81 ,
V_73 ,
sizeof( struct V_82 ) ,
& V_67 ) ;
V_6 -> V_79 |= V_67 ;
return V_42 ;
} else if ( V_72 == V_21 -> V_83 ) {
V_42 = F_36 ( V_12 ,
& V_6 -> V_84 ,
V_73 ,
- 1 ,
& V_67 ) ;
V_6 -> V_79 |= V_67 ;
return V_42 ;
} else if ( V_72 == V_21 -> V_85 ) {
T_1 T_2 * V_53 = F_39 ( V_73 ) ;
if ( ! V_53 )
return 0 ;
if ( F_40 ( - 1 , V_53 ) )
return - V_86 ;
F_23 ( V_6 -> V_6 , V_31 , V_53 ) ;
} else if ( V_31 -> V_22 -> V_87 )
return V_31 -> V_22 -> V_87 ( V_31 , V_6 , V_72 , V_73 ) ;
else
return - V_65 ;
return 0 ;
}
static int
F_41 ( struct V_30 * V_31 ,
const struct V_41 * V_6 ,
struct V_71 * V_72 , T_3 * V_73 )
{
struct V_11 * V_12 = V_31 -> V_12 ;
struct V_20 * V_21 = & V_12 -> V_14 ;
if ( V_72 == V_21 -> V_74 )
* V_73 = V_6 -> V_75 ;
else if ( V_72 == V_21 -> V_76 )
* V_73 = ( V_6 -> V_59 ) ? V_6 -> V_59 -> V_50 . V_51 : 0 ;
else if ( V_72 == V_21 -> V_77 )
* V_73 = ( V_6 -> V_78 ) ? V_6 -> V_78 -> V_50 . V_51 : 0 ;
else if ( V_72 == V_21 -> V_80 )
* V_73 = ( V_6 -> V_81 ) ? V_6 -> V_81 -> V_50 . V_51 : 0 ;
else if ( V_72 == V_21 -> V_83 )
* V_73 = ( V_6 -> V_84 ) ? V_6 -> V_84 -> V_50 . V_51 : 0 ;
else if ( V_72 == V_21 -> V_85 )
* V_73 = 0 ;
else if ( V_31 -> V_22 -> V_88 )
return V_31 -> V_22 -> V_88 ( V_31 , V_6 , V_72 , V_73 ) ;
else
return - V_65 ;
return 0 ;
}
static int F_42 ( struct V_30 * V_31 ,
struct V_41 * V_6 )
{
if ( V_6 -> V_75 && ! V_6 -> V_60 ) {
F_8 ( L_7 ,
V_31 -> V_50 . V_51 , V_31 -> V_52 ) ;
return - V_65 ;
}
if ( F_43 ( V_31 -> V_12 , V_89 ) &&
F_19 ( V_6 -> V_60 && ! V_6 -> V_59 ) ) {
F_8 ( L_8 ,
V_31 -> V_50 . V_51 , V_31 -> V_52 ) ;
return - V_65 ;
}
if ( F_43 ( V_31 -> V_12 , V_89 ) &&
F_19 ( ! V_6 -> V_60 && V_6 -> V_59 ) ) {
F_8 ( L_9 ,
V_31 -> V_50 . V_51 , V_31 -> V_52 ) ;
return - V_65 ;
}
if ( V_6 -> V_32 && ! V_6 -> V_75 && ! V_31 -> V_6 -> V_75 ) {
F_8 ( L_10 ,
V_31 -> V_50 . V_51 , V_31 -> V_52 ) ;
return - V_65 ;
}
return 0 ;
}
static void F_44 ( struct V_90 * V_91 ,
const struct V_41 * V_6 )
{
struct V_30 * V_31 = V_6 -> V_31 ;
F_45 ( V_91 , L_11 , V_31 -> V_50 . V_51 , V_31 -> V_52 ) ;
F_45 ( V_91 , L_12 , V_6 -> V_60 ) ;
F_45 ( V_91 , L_13 , V_6 -> V_75 ) ;
F_45 ( V_91 , L_14 , V_6 -> V_92 ) ;
F_45 ( V_91 , L_15 , V_6 -> V_93 ) ;
F_45 ( V_91 , L_16 , V_6 -> V_94 ) ;
F_45 ( V_91 , L_17 , V_6 -> V_95 ) ;
F_45 ( V_91 , L_18 , V_6 -> V_79 ) ;
F_45 ( V_91 , L_19 , V_6 -> V_96 ) ;
F_45 ( V_91 , L_20 , V_6 -> V_97 ) ;
F_45 ( V_91 , L_21 , V_6 -> V_98 ) ;
F_45 ( V_91 , L_22 V_99 L_23 , F_46 ( & V_6 -> V_56 ) ) ;
if ( V_31 -> V_22 -> V_100 )
V_31 -> V_22 -> V_100 ( V_91 , V_6 ) ;
}
struct V_101 *
F_47 ( struct V_5 * V_6 ,
struct V_33 * V_34 )
{
int V_42 , V_43 = F_48 ( V_34 ) ;
struct V_101 * V_102 ;
F_19 ( ! V_6 -> V_45 ) ;
V_102 = F_49 ( V_6 , V_34 ) ;
if ( V_102 )
return V_102 ;
V_42 = F_21 ( & V_34 -> V_46 , V_6 -> V_45 ) ;
if ( V_42 )
return F_22 ( V_42 ) ;
V_102 = V_34 -> V_22 -> V_47 ( V_34 ) ;
if ( ! V_102 )
return F_22 ( - V_19 ) ;
V_6 -> V_9 [ V_43 ] . V_6 = V_102 ;
V_6 -> V_9 [ V_43 ] . V_28 = V_34 ;
V_6 -> V_9 [ V_43 ] . V_48 = V_34 -> V_6 ;
V_6 -> V_9 [ V_43 ] . V_49 = V_102 ;
V_102 -> V_6 = V_6 ;
F_8 ( L_24 ,
V_34 -> V_50 . V_51 , V_34 -> V_52 , V_102 , V_6 ) ;
if ( V_102 -> V_31 ) {
struct V_41 * V_44 ;
V_44 = F_17 ( V_6 ,
V_102 -> V_31 ) ;
if ( F_29 ( V_44 ) )
return F_50 ( V_44 ) ;
}
return V_102 ;
}
int F_51 ( struct V_33 * V_34 ,
struct V_101 * V_6 , struct V_71 * V_72 ,
T_3 V_73 )
{
struct V_11 * V_12 = V_34 -> V_12 ;
struct V_20 * V_21 = & V_12 -> V_14 ;
if ( V_72 == V_21 -> V_103 ) {
struct V_104 * V_105 = F_52 ( V_12 , V_73 ) ;
F_53 ( V_6 , V_105 ) ;
if ( V_105 )
F_54 ( V_105 ) ;
} else if ( V_72 == V_21 -> V_106 ) {
if ( V_6 -> V_107 )
return - V_65 ;
if ( F_55 ( V_73 ) == - 1 )
return 0 ;
V_6 -> V_107 = F_56 ( V_73 ) ;
if ( ! V_6 -> V_107 )
return - V_65 ;
} else if ( V_72 == V_21 -> V_108 ) {
struct V_30 * V_31 = F_57 ( V_12 , V_73 ) ;
return F_58 ( V_6 , V_31 ) ;
} else if ( V_72 == V_21 -> V_109 ) {
V_6 -> V_110 = F_55 ( V_73 ) ;
} else if ( V_72 == V_21 -> V_111 ) {
V_6 -> V_112 = F_55 ( V_73 ) ;
} else if ( V_72 == V_21 -> V_113 ) {
V_6 -> V_114 = V_73 ;
} else if ( V_72 == V_21 -> V_115 ) {
V_6 -> V_116 = V_73 ;
} else if ( V_72 == V_21 -> V_117 ) {
V_6 -> V_118 = V_73 ;
} else if ( V_72 == V_21 -> V_119 ) {
V_6 -> V_120 = V_73 ;
} else if ( V_72 == V_21 -> V_121 ) {
V_6 -> V_122 = V_73 ;
} else if ( V_72 == V_21 -> V_123 ) {
V_6 -> V_124 = V_73 ;
} else if ( V_72 == V_34 -> V_125 ) {
if ( ! F_59 ( V_73 & V_126 ) )
return - V_65 ;
V_6 -> V_127 = V_73 ;
} else if ( V_72 == V_34 -> V_128 ) {
V_6 -> V_129 = V_73 ;
} else if ( V_34 -> V_22 -> V_87 ) {
return V_34 -> V_22 -> V_87 ( V_34 , V_6 ,
V_72 , V_73 ) ;
} else {
return - V_65 ;
}
return 0 ;
}
static int
F_60 ( struct V_33 * V_34 ,
const struct V_101 * V_6 ,
struct V_71 * V_72 , T_3 * V_73 )
{
struct V_11 * V_12 = V_34 -> V_12 ;
struct V_20 * V_21 = & V_12 -> V_14 ;
if ( V_72 == V_21 -> V_103 ) {
* V_73 = ( V_6 -> V_105 ) ? V_6 -> V_105 -> V_50 . V_51 : 0 ;
} else if ( V_72 == V_21 -> V_106 ) {
* V_73 = - 1 ;
} else if ( V_72 == V_21 -> V_108 ) {
* V_73 = ( V_6 -> V_31 ) ? V_6 -> V_31 -> V_50 . V_51 : 0 ;
} else if ( V_72 == V_21 -> V_109 ) {
* V_73 = F_61 ( V_6 -> V_110 ) ;
} else if ( V_72 == V_21 -> V_111 ) {
* V_73 = F_61 ( V_6 -> V_112 ) ;
} else if ( V_72 == V_21 -> V_113 ) {
* V_73 = V_6 -> V_114 ;
} else if ( V_72 == V_21 -> V_115 ) {
* V_73 = V_6 -> V_116 ;
} else if ( V_72 == V_21 -> V_117 ) {
* V_73 = V_6 -> V_118 ;
} else if ( V_72 == V_21 -> V_119 ) {
* V_73 = V_6 -> V_120 ;
} else if ( V_72 == V_21 -> V_121 ) {
* V_73 = V_6 -> V_122 ;
} else if ( V_72 == V_21 -> V_123 ) {
* V_73 = V_6 -> V_124 ;
} else if ( V_72 == V_34 -> V_125 ) {
* V_73 = V_6 -> V_127 ;
} else if ( V_72 == V_34 -> V_128 ) {
* V_73 = V_6 -> V_129 ;
} else if ( V_34 -> V_22 -> V_88 ) {
return V_34 -> V_22 -> V_88 ( V_34 , V_6 , V_72 , V_73 ) ;
} else {
return - V_65 ;
}
return 0 ;
}
static bool
F_62 ( struct V_5 * V_6 ,
struct V_33 * V_34 ,
struct V_101 * V_102 )
{
if ( ! V_34 -> V_6 -> V_31 || ! V_102 -> V_31 )
return false ;
if ( V_34 -> V_6 -> V_31 == V_102 -> V_31 )
return false ;
return true ;
}
static int F_63 ( struct V_33 * V_34 ,
struct V_101 * V_6 )
{
unsigned int V_130 , V_131 ;
int V_42 ;
if ( F_19 ( V_6 -> V_31 && ! V_6 -> V_105 ) ) {
F_8 ( L_25 ) ;
return - V_65 ;
} else if ( F_19 ( V_6 -> V_105 && ! V_6 -> V_31 ) ) {
F_8 ( L_26 ) ;
return - V_65 ;
}
if ( ! V_6 -> V_31 )
return 0 ;
if ( ! ( V_34 -> V_132 & F_64 ( V_6 -> V_31 ) ) ) {
F_8 ( L_27 ) ;
return - V_65 ;
}
V_42 = F_65 ( V_34 , V_6 -> V_105 -> V_133 -> V_133 ) ;
if ( V_42 ) {
struct V_134 V_135 ;
F_8 ( L_28 ,
F_66 ( V_6 -> V_105 -> V_133 -> V_133 ,
& V_135 ) ) ;
return V_42 ;
}
if ( V_6 -> V_114 > V_136 ||
V_6 -> V_110 > V_136 - ( V_137 ) V_6 -> V_114 ||
V_6 -> V_116 > V_136 ||
V_6 -> V_112 > V_136 - ( V_137 ) V_6 -> V_116 ) {
F_8 ( L_29 ,
V_6 -> V_114 , V_6 -> V_116 ,
V_6 -> V_110 , V_6 -> V_112 ) ;
return - V_138 ;
}
V_130 = V_6 -> V_105 -> V_139 << 16 ;
V_131 = V_6 -> V_105 -> V_140 << 16 ;
if ( V_6 -> V_122 > V_130 ||
V_6 -> V_118 > V_130 - V_6 -> V_122 ||
V_6 -> V_124 > V_131 ||
V_6 -> V_120 > V_131 - V_6 -> V_124 ) {
F_8 ( L_30
L_31 ,
V_6 -> V_122 >> 16 , ( ( V_6 -> V_122 & 0xffff ) * 15625 ) >> 10 ,
V_6 -> V_124 >> 16 , ( ( V_6 -> V_124 & 0xffff ) * 15625 ) >> 10 ,
V_6 -> V_118 >> 16 , ( ( V_6 -> V_118 & 0xffff ) * 15625 ) >> 10 ,
V_6 -> V_120 >> 16 , ( ( V_6 -> V_120 & 0xffff ) * 15625 ) >> 10 ) ;
return - V_141 ;
}
if ( F_62 ( V_6 -> V_6 , V_34 , V_6 ) ) {
F_8 ( L_32 ,
V_34 -> V_50 . V_51 , V_34 -> V_52 ) ;
return - V_65 ;
}
return 0 ;
}
static void F_67 ( struct V_90 * V_91 ,
const struct V_101 * V_6 )
{
struct V_33 * V_34 = V_6 -> V_34 ;
struct V_142 V_143 = F_68 ( V_6 ) ;
struct V_142 V_144 = F_69 ( V_6 ) ;
F_45 ( V_91 , L_33 , V_34 -> V_50 . V_51 , V_34 -> V_52 ) ;
F_45 ( V_91 , L_34 , V_6 -> V_31 ? V_6 -> V_31 -> V_52 : L_35 ) ;
F_45 ( V_91 , L_36 , V_6 -> V_105 ? V_6 -> V_105 -> V_50 . V_51 : 0 ) ;
if ( V_6 -> V_105 ) {
struct V_104 * V_105 = V_6 -> V_105 ;
int V_24 , V_145 = V_105 -> V_133 -> V_146 ;
struct V_134 V_135 ;
F_45 ( V_91 , L_37 ,
F_66 ( V_105 -> V_133 -> V_133 , & V_135 ) ) ;
F_45 ( V_91 , L_38 , V_105 -> V_147 ) ;
F_45 ( V_91 , L_39 , V_105 -> V_139 , V_105 -> V_140 ) ;
F_45 ( V_91 , L_40 ) ;
for ( V_24 = 0 ; V_24 < V_145 ; V_24 ++ ) {
F_45 ( V_91 , L_41 , V_24 , V_105 -> V_148 [ V_24 ] ) ;
F_45 ( V_91 , L_42 , V_24 , V_105 -> V_149 [ V_24 ] ) ;
}
}
F_45 ( V_91 , L_43 V_150 L_23 , F_70 ( & V_144 ) ) ;
F_45 ( V_91 , L_44 V_151 L_23 , F_71 ( & V_143 ) ) ;
F_45 ( V_91 , L_45 , V_6 -> V_127 ) ;
if ( V_34 -> V_22 -> V_100 )
V_34 -> V_22 -> V_100 ( V_91 , V_6 ) ;
}
void *
F_72 ( struct V_5 * V_6 , void * V_38 ,
const struct V_152 * V_22 )
{
int V_43 , V_153 , V_24 ;
T_5 V_154 ;
struct V_155 * V_156 ;
for ( V_24 = 0 ; V_24 < V_6 -> V_35 ; V_24 ++ )
if ( V_38 == V_6 -> V_10 [ V_24 ] . V_38 &&
V_6 -> V_10 [ V_24 ] . V_36 )
return V_6 -> V_10 [ V_24 ] . V_36 ;
V_153 = V_6 -> V_35 + 1 ;
V_154 = sizeof( * V_6 -> V_10 ) * V_153 ;
V_156 = F_73 ( V_6 -> V_10 , V_154 , V_16 ) ;
if ( ! V_156 )
return F_22 ( - V_19 ) ;
V_6 -> V_10 = V_156 ;
V_43 = V_6 -> V_35 ;
memset ( & V_6 -> V_10 [ V_43 ] , 0 , sizeof( * V_6 -> V_10 ) ) ;
V_6 -> V_10 [ V_43 ] . V_36 = V_22 -> V_157 ( V_6 , V_38 ) ;
if ( ! V_6 -> V_10 [ V_43 ] . V_36 )
return F_22 ( - V_19 ) ;
V_6 -> V_10 [ V_43 ] . V_38 = V_38 ;
V_6 -> V_10 [ V_43 ] . V_22 = V_22 ;
V_6 -> V_35 = V_153 ;
F_8 ( L_46 ,
V_6 -> V_10 [ V_43 ] . V_36 , V_6 ) ;
return V_6 -> V_10 [ V_43 ] . V_36 ;
}
struct V_158 *
F_74 ( struct V_5 * V_6 ,
struct V_26 * V_27 )
{
int V_42 , V_43 ;
struct V_20 * V_21 = & V_27 -> V_12 -> V_14 ;
struct V_158 * V_159 ;
F_19 ( ! V_6 -> V_45 ) ;
V_42 = F_21 ( & V_21 -> V_160 , V_6 -> V_45 ) ;
if ( V_42 )
return F_22 ( V_42 ) ;
V_43 = F_75 ( V_27 ) ;
if ( V_43 >= V_6 -> V_25 ) {
struct V_161 * V_162 ;
int V_163 = F_76 ( V_43 + 1 , V_21 -> V_25 ) ;
V_162 = F_73 ( V_6 -> V_7 , V_163 * sizeof( * V_6 -> V_7 ) , V_16 ) ;
if ( ! V_162 )
return F_22 ( - V_19 ) ;
V_6 -> V_7 = V_162 ;
memset ( & V_6 -> V_7 [ V_6 -> V_25 ] , 0 ,
sizeof( * V_6 -> V_7 ) * ( V_163 - V_6 -> V_25 ) ) ;
V_6 -> V_25 = V_163 ;
}
if ( V_6 -> V_7 [ V_43 ] . V_6 )
return V_6 -> V_7 [ V_43 ] . V_6 ;
V_159 = V_27 -> V_22 -> V_47 ( V_27 ) ;
if ( ! V_159 )
return F_22 ( - V_19 ) ;
F_77 ( V_27 ) ;
V_6 -> V_7 [ V_43 ] . V_6 = V_159 ;
V_6 -> V_7 [ V_43 ] . V_48 = V_27 -> V_6 ;
V_6 -> V_7 [ V_43 ] . V_49 = V_159 ;
V_6 -> V_7 [ V_43 ] . V_28 = V_27 ;
V_159 -> V_6 = V_6 ;
F_8 ( L_47 ,
V_27 -> V_50 . V_51 , V_27 -> V_52 ,
V_159 , V_6 ) ;
if ( V_159 -> V_31 ) {
struct V_41 * V_44 ;
V_44 = F_17 ( V_6 ,
V_159 -> V_31 ) ;
if ( F_29 ( V_44 ) )
return F_50 ( V_44 ) ;
}
return V_159 ;
}
int F_78 ( struct V_26 * V_27 ,
struct V_158 * V_6 , struct V_71 * V_72 ,
T_3 V_73 )
{
struct V_11 * V_12 = V_27 -> V_12 ;
struct V_20 * V_21 = & V_12 -> V_14 ;
if ( V_72 == V_21 -> V_108 ) {
struct V_30 * V_31 = F_57 ( V_12 , V_73 ) ;
return F_79 ( V_6 , V_31 ) ;
} else if ( V_72 == V_21 -> V_164 ) {
return - V_65 ;
} else if ( V_72 == V_21 -> V_165 ) {
V_6 -> V_166 . V_167 = V_73 ;
} else if ( V_72 == V_21 -> V_168 ) {
V_6 -> V_166 . V_169 . V_170 = V_73 ;
} else if ( V_72 == V_21 -> V_171 ) {
V_6 -> V_166 . V_169 . V_172 = V_73 ;
} else if ( V_72 == V_21 -> V_173 ) {
V_6 -> V_166 . V_169 . V_174 = V_73 ;
} else if ( V_72 == V_21 -> V_175 ) {
V_6 -> V_166 . V_169 . V_176 = V_73 ;
} else if ( V_72 == V_21 -> V_177 ) {
V_6 -> V_166 . V_56 = V_73 ;
} else if ( V_72 == V_21 -> V_178 ) {
V_6 -> V_166 . V_179 = V_73 ;
} else if ( V_72 == V_21 -> V_180 ) {
V_6 -> V_166 . V_181 = V_73 ;
} else if ( V_72 == V_21 -> V_182 ) {
V_6 -> V_166 . V_183 = V_73 ;
} else if ( V_72 == V_21 -> V_184 ) {
V_6 -> V_166 . V_185 = V_73 ;
} else if ( V_72 == V_21 -> V_186 ) {
V_6 -> V_166 . V_187 = V_73 ;
} else if ( V_72 == V_21 -> V_188 ) {
V_6 -> V_166 . V_189 = V_73 ;
} else if ( V_72 == V_21 -> V_190 ) {
if ( V_6 -> V_191 != V_192 )
V_6 -> V_191 = V_73 ;
} else if ( V_72 == V_21 -> V_193 ) {
V_6 -> V_194 = V_73 ;
} else if ( V_72 == V_27 -> V_195 ) {
V_6 -> V_196 = V_73 ;
} else if ( V_27 -> V_22 -> V_87 ) {
return V_27 -> V_22 -> V_87 ( V_27 ,
V_6 , V_72 , V_73 ) ;
} else {
return - V_65 ;
}
return 0 ;
}
static void F_80 ( struct V_90 * V_91 ,
const struct V_158 * V_6 )
{
struct V_26 * V_27 = V_6 -> V_27 ;
F_45 ( V_91 , L_48 , V_27 -> V_50 . V_51 , V_27 -> V_52 ) ;
F_45 ( V_91 , L_34 , V_6 -> V_31 ? V_6 -> V_31 -> V_52 : L_35 ) ;
if ( V_27 -> V_22 -> V_100 )
V_27 -> V_22 -> V_100 ( V_91 , V_6 ) ;
}
static int
F_81 ( struct V_26 * V_27 ,
const struct V_158 * V_6 ,
struct V_71 * V_72 , T_3 * V_73 )
{
struct V_11 * V_12 = V_27 -> V_12 ;
struct V_20 * V_21 = & V_12 -> V_14 ;
if ( V_72 == V_21 -> V_108 ) {
* V_73 = ( V_6 -> V_31 ) ? V_6 -> V_31 -> V_50 . V_51 : 0 ;
} else if ( V_72 == V_21 -> V_164 ) {
* V_73 = V_27 -> V_197 ;
} else if ( V_72 == V_21 -> V_165 ) {
* V_73 = V_6 -> V_166 . V_167 ;
} else if ( V_72 == V_21 -> V_168 ) {
* V_73 = V_6 -> V_166 . V_169 . V_170 ;
} else if ( V_72 == V_21 -> V_171 ) {
* V_73 = V_6 -> V_166 . V_169 . V_172 ;
} else if ( V_72 == V_21 -> V_173 ) {
* V_73 = V_6 -> V_166 . V_169 . V_174 ;
} else if ( V_72 == V_21 -> V_175 ) {
* V_73 = V_6 -> V_166 . V_169 . V_176 ;
} else if ( V_72 == V_21 -> V_177 ) {
* V_73 = V_6 -> V_166 . V_56 ;
} else if ( V_72 == V_21 -> V_178 ) {
* V_73 = V_6 -> V_166 . V_179 ;
} else if ( V_72 == V_21 -> V_180 ) {
* V_73 = V_6 -> V_166 . V_181 ;
} else if ( V_72 == V_21 -> V_182 ) {
* V_73 = V_6 -> V_166 . V_183 ;
} else if ( V_72 == V_21 -> V_184 ) {
* V_73 = V_6 -> V_166 . V_185 ;
} else if ( V_72 == V_21 -> V_186 ) {
* V_73 = V_6 -> V_166 . V_187 ;
} else if ( V_72 == V_21 -> V_188 ) {
* V_73 = V_6 -> V_166 . V_189 ;
} else if ( V_72 == V_21 -> V_190 ) {
* V_73 = V_6 -> V_191 ;
} else if ( V_72 == V_21 -> V_193 ) {
* V_73 = V_6 -> V_194 ;
} else if ( V_72 == V_27 -> V_195 ) {
* V_73 = V_6 -> V_196 ;
} else if ( V_27 -> V_22 -> V_88 ) {
return V_27 -> V_22 -> V_88 ( V_27 ,
V_6 , V_72 , V_73 ) ;
} else {
return - V_65 ;
}
return 0 ;
}
int F_82 ( struct V_198 * V_38 ,
struct V_71 * V_72 , T_3 * V_73 )
{
struct V_11 * V_12 = V_72 -> V_12 ;
int V_42 ;
switch ( V_38 -> type ) {
case V_199 : {
struct V_26 * V_27 = F_83 ( V_38 ) ;
F_19 ( ! F_84 ( & V_12 -> V_14 . V_160 ) ) ;
V_42 = F_81 ( V_27 ,
V_27 -> V_6 , V_72 , V_73 ) ;
break;
}
case V_200 : {
struct V_30 * V_31 = F_85 ( V_38 ) ;
F_19 ( ! F_84 ( & V_31 -> V_46 ) ) ;
V_42 = F_41 ( V_31 ,
V_31 -> V_6 , V_72 , V_73 ) ;
break;
}
case V_201 : {
struct V_33 * V_34 = F_86 ( V_38 ) ;
F_19 ( ! F_84 ( & V_34 -> V_46 ) ) ;
V_42 = F_60 ( V_34 ,
V_34 -> V_6 , V_72 , V_73 ) ;
break;
}
default:
V_42 = - V_65 ;
break;
}
return V_42 ;
}
int
F_58 ( struct V_101 * V_102 ,
struct V_30 * V_31 )
{
struct V_33 * V_34 = V_102 -> V_34 ;
struct V_41 * V_44 ;
if ( V_102 -> V_31 ) {
V_44 = F_17 ( V_102 -> V_6 ,
V_102 -> V_31 ) ;
if ( F_19 ( F_29 ( V_44 ) ) )
return F_30 ( V_44 ) ;
V_44 -> V_96 &= ~ ( 1 << F_48 ( V_34 ) ) ;
}
V_102 -> V_31 = V_31 ;
if ( V_31 ) {
V_44 = F_17 ( V_102 -> V_6 ,
V_31 ) ;
if ( F_29 ( V_44 ) )
return F_30 ( V_44 ) ;
V_44 -> V_96 |= ( 1 << F_48 ( V_34 ) ) ;
}
if ( V_31 )
F_8 ( L_49 ,
V_102 , V_31 -> V_50 . V_51 , V_31 -> V_52 ) ;
else
F_8 ( L_50 ,
V_102 ) ;
return 0 ;
}
void
F_53 ( struct V_101 * V_102 ,
struct V_104 * V_105 )
{
if ( V_105 )
F_8 ( L_51 ,
V_105 -> V_50 . V_51 , V_102 ) ;
else
F_8 ( L_52 ,
V_102 ) ;
F_87 ( & V_102 -> V_105 , V_105 ) ;
}
void
F_88 ( struct V_101 * V_102 ,
struct V_202 * V_107 )
{
if ( V_102 -> V_107 ) {
F_89 ( V_107 ) ;
return;
}
V_102 -> V_107 = V_107 ;
}
int
F_79 ( struct V_158 * V_203 ,
struct V_30 * V_31 )
{
struct V_41 * V_44 ;
if ( V_203 -> V_31 == V_31 )
return 0 ;
if ( V_203 -> V_31 ) {
V_44 = F_90 ( V_203 -> V_6 ,
V_203 -> V_31 ) ;
V_44 -> V_97 &=
~ ( 1 << F_75 ( V_203 -> V_27 ) ) ;
F_12 ( V_203 -> V_27 ) ;
V_203 -> V_31 = NULL ;
}
if ( V_31 ) {
V_44 = F_17 ( V_203 -> V_6 , V_31 ) ;
if ( F_29 ( V_44 ) )
return F_30 ( V_44 ) ;
V_44 -> V_97 |=
1 << F_75 ( V_203 -> V_27 ) ;
F_77 ( V_203 -> V_27 ) ;
V_203 -> V_31 = V_31 ;
F_8 ( L_53 ,
V_203 , V_31 -> V_50 . V_51 , V_31 -> V_52 ) ;
} else {
F_8 ( L_54 ,
V_203 ) ;
}
return 0 ;
}
int
F_91 ( struct V_5 * V_6 ,
struct V_30 * V_31 )
{
struct V_20 * V_21 = & V_6 -> V_12 -> V_14 ;
struct V_26 * V_27 ;
struct V_158 * V_203 ;
struct V_204 V_205 ;
struct V_41 * V_44 ;
int V_42 ;
V_44 = F_17 ( V_6 , V_31 ) ;
if ( F_29 ( V_44 ) )
return F_30 ( V_44 ) ;
V_42 = F_21 ( & V_21 -> V_160 , V_6 -> V_45 ) ;
if ( V_42 )
return V_42 ;
F_8 ( L_55 ,
V_31 -> V_50 . V_51 , V_31 -> V_52 , V_6 ) ;
F_92 ( V_6 -> V_12 , & V_205 ) ;
F_93 (connector, &conn_iter) {
if ( ! ( V_44 -> V_97 & ( 1 << F_75 ( V_27 ) ) ) )
continue;
V_203 = F_74 ( V_6 , V_27 ) ;
if ( F_29 ( V_203 ) ) {
F_94 ( & V_205 ) ;
return F_30 ( V_203 ) ;
}
}
F_94 ( & V_205 ) ;
return 0 ;
}
int
F_95 ( struct V_5 * V_6 ,
struct V_30 * V_31 )
{
struct V_33 * V_34 ;
F_19 ( ! F_90 ( V_6 , V_31 ) ) ;
F_96 (plane, state->dev, crtc->state->plane_mask) {
struct V_101 * V_102 =
F_47 ( V_6 , V_34 ) ;
if ( F_29 ( V_102 ) )
return F_30 ( V_102 ) ;
}
return 0 ;
}
void F_97 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = V_6 -> V_12 ;
int V_42 ;
bool V_206 = false ;
if ( F_19 ( V_12 -> V_14 . V_45 == V_6 -> V_45 ) ) {
V_206 = true ;
V_12 -> V_14 . V_45 = NULL ;
}
V_207:
F_98 ( V_6 -> V_45 ) ;
V_42 = F_99 ( V_12 , V_6 -> V_45 ) ;
if ( V_42 )
goto V_207;
if ( V_206 )
V_12 -> V_14 . V_45 = V_6 -> V_45 ;
}
int F_100 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = V_6 -> V_12 ;
struct V_20 * V_21 = & V_12 -> V_14 ;
struct V_33 * V_34 ;
struct V_101 * V_102 ;
struct V_30 * V_31 ;
struct V_41 * V_44 ;
int V_24 , V_42 = 0 ;
F_8 ( L_56 , V_6 ) ;
F_101 (state, plane, plane_state, i) {
V_42 = F_63 ( V_34 , V_102 ) ;
if ( V_42 ) {
F_8 ( L_57 ,
V_34 -> V_50 . V_51 , V_34 -> V_52 ) ;
return V_42 ;
}
}
F_102 (state, crtc, crtc_state, i) {
V_42 = F_42 ( V_31 , V_44 ) ;
if ( V_42 ) {
F_8 ( L_58 ,
V_31 -> V_50 . V_51 , V_31 -> V_52 ) ;
return V_42 ;
}
}
if ( V_21 -> V_22 -> V_208 )
V_42 = V_21 -> V_22 -> V_208 ( V_6 -> V_12 , V_6 ) ;
if ( V_42 )
return V_42 ;
if ( ! V_6 -> V_13 ) {
F_102 (state, crtc, crtc_state, i) {
if ( F_103 ( V_44 ) ) {
F_8 ( L_59 ,
V_31 -> V_50 . V_51 , V_31 -> V_52 ) ;
return - V_65 ;
}
}
}
return 0 ;
}
int F_104 ( struct V_5 * V_6 )
{
struct V_20 * V_21 = & V_6 -> V_12 -> V_14 ;
int V_42 ;
V_42 = F_100 ( V_6 ) ;
if ( V_42 )
return V_42 ;
F_8 ( L_60 , V_6 ) ;
return V_21 -> V_22 -> V_209 ( V_6 -> V_12 , V_6 , false ) ;
}
int F_105 ( struct V_5 * V_6 )
{
struct V_20 * V_21 = & V_6 -> V_12 -> V_14 ;
int V_42 ;
V_42 = F_100 ( V_6 ) ;
if ( V_42 )
return V_42 ;
F_8 ( L_61 , V_6 ) ;
return V_21 -> V_22 -> V_209 ( V_6 -> V_12 , V_6 , true ) ;
}
static void F_106 ( const struct V_5 * V_6 )
{
struct V_90 V_91 = F_107 ( V_6 -> V_12 -> V_12 ) ;
struct V_33 * V_34 ;
struct V_101 * V_102 ;
struct V_30 * V_31 ;
struct V_41 * V_44 ;
struct V_26 * V_27 ;
struct V_158 * V_159 ;
int V_24 ;
F_8 ( L_56 , V_6 ) ;
F_101 (state, plane, plane_state, i)
F_67 ( & V_91 , V_102 ) ;
F_102 (state, crtc, crtc_state, i)
F_44 ( & V_91 , V_44 ) ;
F_108 (state, connector, connector_state, i)
F_80 ( & V_91 , V_159 ) ;
}
static void F_109 ( struct V_11 * V_12 , struct V_90 * V_91 ,
bool V_210 )
{
struct V_20 * V_21 = & V_12 -> V_14 ;
struct V_33 * V_34 ;
struct V_30 * V_31 ;
struct V_26 * V_27 ;
struct V_204 V_205 ;
if ( ! F_43 ( V_12 , V_89 ) )
return;
F_110 (plane, &config->plane_list, head) {
if ( V_210 )
F_21 ( & V_34 -> V_46 , NULL ) ;
F_67 ( V_91 , V_34 -> V_6 ) ;
if ( V_210 )
F_111 ( & V_34 -> V_46 ) ;
}
F_110 (crtc, &config->crtc_list, head) {
if ( V_210 )
F_21 ( & V_31 -> V_46 , NULL ) ;
F_44 ( V_91 , V_31 -> V_6 ) ;
if ( V_210 )
F_111 ( & V_31 -> V_46 ) ;
}
F_92 ( V_12 , & V_205 ) ;
if ( V_210 )
F_21 ( & V_12 -> V_14 . V_160 , NULL ) ;
F_93 (connector, &conn_iter)
F_80 ( V_91 , V_27 -> V_6 ) ;
if ( V_210 )
F_111 ( & V_12 -> V_14 . V_160 ) ;
F_94 ( & V_205 ) ;
}
void F_112 ( struct V_11 * V_12 , struct V_90 * V_91 )
{
F_109 ( V_12 , V_91 , false ) ;
}
static int F_113 ( struct V_211 * V_212 , void * V_64 )
{
struct V_213 * V_214 = (struct V_213 * ) V_212 -> V_215 ;
struct V_11 * V_12 = V_214 -> V_216 -> V_12 ;
struct V_90 V_91 = F_114 ( V_212 ) ;
F_109 ( V_12 , & V_91 , true ) ;
return 0 ;
}
int F_115 ( struct V_217 * V_216 )
{
return F_116 ( V_218 ,
F_117 ( V_218 ) ,
V_216 -> V_219 , V_216 ) ;
}
static struct V_220 * F_118 (
struct V_11 * V_12 , T_3 V_221 )
{
struct V_220 * V_222 = NULL ;
V_222 = F_10 ( sizeof *V_222 , V_16 ) ;
if ( ! V_222 )
return NULL ;
V_222 -> V_32 . V_50 . type = V_223 ;
V_222 -> V_32 . V_50 . V_63 = sizeof( V_222 -> V_32 ) ;
V_222 -> V_32 . V_221 = V_221 ;
return V_222 ;
}
static int F_119 ( struct V_5 * V_6 ,
struct V_198 * V_38 , struct V_71 * V_224 ,
T_3 V_225 )
{
struct V_198 * V_4 ;
int V_42 ;
if ( ! F_120 ( V_224 , V_225 , & V_4 ) )
return - V_65 ;
switch ( V_38 -> type ) {
case V_199 : {
struct V_26 * V_27 = F_83 ( V_38 ) ;
struct V_158 * V_159 ;
V_159 = F_74 ( V_6 , V_27 ) ;
if ( F_29 ( V_159 ) ) {
V_42 = F_30 ( V_159 ) ;
break;
}
V_42 = F_78 ( V_27 ,
V_159 , V_224 , V_225 ) ;
break;
}
case V_200 : {
struct V_30 * V_31 = F_85 ( V_38 ) ;
struct V_41 * V_44 ;
V_44 = F_17 ( V_6 , V_31 ) ;
if ( F_29 ( V_44 ) ) {
V_42 = F_30 ( V_44 ) ;
break;
}
V_42 = F_38 ( V_31 ,
V_44 , V_224 , V_225 ) ;
break;
}
case V_201 : {
struct V_33 * V_34 = F_86 ( V_38 ) ;
struct V_101 * V_102 ;
V_102 = F_47 ( V_6 , V_34 ) ;
if ( F_29 ( V_102 ) ) {
V_42 = F_30 ( V_102 ) ;
break;
}
V_42 = F_51 ( V_34 ,
V_102 , V_224 , V_225 ) ;
break;
}
default:
V_42 = - V_65 ;
break;
}
F_121 ( V_224 , V_4 ) ;
return V_42 ;
}
void F_122 ( struct V_11 * V_12 ,
unsigned V_96 ,
int V_42 )
{
struct V_33 * V_34 ;
F_96 (plane, dev, plane_mask) {
if ( V_42 == 0 ) {
struct V_104 * V_226 = V_34 -> V_6 -> V_105 ;
if ( V_226 )
F_123 ( V_226 ) ;
V_34 -> V_105 = V_226 ;
V_34 -> V_31 = V_34 -> V_6 -> V_31 ;
if ( V_34 -> V_227 )
F_54 ( V_34 -> V_227 ) ;
}
V_34 -> V_227 = NULL ;
}
}
static int F_124 ( struct V_228 * V_229 ,
struct V_202 * V_107 )
{
V_229 -> V_230 = F_125 ( V_231 ) ;
if ( V_229 -> V_230 < 0 )
return V_229 -> V_230 ;
if ( F_40 ( V_229 -> V_230 , V_229 -> V_54 ) )
return - V_86 ;
V_229 -> V_232 = F_126 ( V_107 ) ;
if ( ! V_229 -> V_232 )
return - V_19 ;
return 0 ;
}
static int F_127 ( struct V_11 * V_12 ,
struct V_5 * V_6 ,
struct V_233 * V_234 ,
struct V_235 * V_236 ,
struct V_228 * * V_229 ,
unsigned int * V_237 )
{
struct V_30 * V_31 ;
struct V_41 * V_44 ;
int V_24 , V_42 ;
if ( V_234 -> V_238 & V_239 )
return 0 ;
F_102 (state, crtc, crtc_state, i) {
T_1 T_2 * V_53 ;
V_53 = F_24 ( V_44 -> V_6 , V_31 ) ;
if ( V_234 -> V_238 & V_240 || V_53 ) {
struct V_220 * V_222 ;
V_222 = F_118 ( V_12 , V_234 -> V_221 ) ;
if ( ! V_222 )
return - V_19 ;
V_44 -> V_32 = V_222 ;
}
if ( V_234 -> V_238 & V_240 ) {
struct V_220 * V_222 = V_44 -> V_32 ;
if ( ! V_236 )
continue;
V_42 = F_128 ( V_12 , V_236 , & V_222 -> V_50 ,
& V_222 -> V_32 . V_50 ) ;
if ( V_42 ) {
F_3 ( V_222 ) ;
V_44 -> V_32 = NULL ;
return V_42 ;
}
}
if ( V_53 ) {
struct V_202 * V_107 ;
struct V_228 * V_241 ;
V_241 = F_73 ( * V_229 , sizeof( * * V_229 ) *
( * V_237 + 1 ) , V_16 ) ;
if ( ! V_241 )
return - V_19 ;
memset ( & V_241 [ * V_237 ] , 0 , sizeof( * V_241 ) ) ;
V_241 [ * V_237 ] . V_54 = V_53 ;
* V_229 = V_241 ;
V_107 = F_129 ( V_31 ) ;
if ( ! V_107 )
return - V_19 ;
V_42 = F_124 ( & V_241 [ ( * V_237 ) ++ ] , V_107 ) ;
if ( V_42 ) {
F_89 ( V_107 ) ;
return V_42 ;
}
V_44 -> V_32 -> V_50 . V_107 = V_107 ;
}
}
return 0 ;
}
static void F_130 ( struct V_11 * V_12 ,
struct V_5 * V_6 ,
struct V_228 * V_229 ,
unsigned int V_237 ,
bool V_242 )
{
struct V_30 * V_31 ;
struct V_41 * V_44 ;
int V_24 ;
if ( V_242 ) {
for ( V_24 = 0 ; V_24 < V_237 ; V_24 ++ )
F_131 ( V_229 [ V_24 ] . V_230 ,
V_229 [ V_24 ] . V_232 -> V_243 ) ;
F_3 ( V_229 ) ;
return;
}
F_102 (state, crtc, crtc_state, i) {
struct V_220 * V_32 = V_44 -> V_32 ;
if ( V_32 && ( V_32 -> V_50 . V_107 || V_32 -> V_50 . V_236 ) ) {
F_132 ( V_12 , & V_32 -> V_50 ) ;
V_44 -> V_32 = NULL ;
}
}
if ( ! V_229 )
return;
for ( V_24 = 0 ; V_24 < V_237 ; V_24 ++ ) {
if ( V_229 [ V_24 ] . V_232 )
F_133 ( V_229 [ V_24 ] . V_232 -> V_243 ) ;
if ( V_229 [ V_24 ] . V_230 >= 0 )
F_134 ( V_229 [ V_24 ] . V_230 ) ;
if ( V_229 [ V_24 ] . V_54 &&
F_40 ( - 1 , V_229 [ V_24 ] . V_54 ) )
F_8 ( L_62 ) ;
}
F_3 ( V_229 ) ;
}
int F_135 ( struct V_11 * V_12 ,
void * V_64 , struct V_235 * V_236 )
{
struct V_233 * V_234 = V_64 ;
T_6 T_2 * V_244 = ( T_6 T_2 * ) ( unsigned long ) ( V_234 -> V_244 ) ;
T_6 T_2 * V_245 = ( T_6 T_2 * ) ( unsigned long ) ( V_234 -> V_245 ) ;
T_6 T_2 * V_246 = ( T_6 T_2 * ) ( unsigned long ) ( V_234 -> V_246 ) ;
T_3 T_2 * V_247 = ( T_3 T_2 * ) ( unsigned long ) ( V_234 -> V_247 ) ;
unsigned int V_248 , V_249 ;
struct V_5 * V_6 ;
struct V_250 V_251 ;
struct V_33 * V_34 ;
struct V_228 * V_229 ;
unsigned V_96 ;
int V_42 = 0 ;
unsigned int V_24 , V_252 , V_237 ;
if ( ! F_43 ( V_12 , V_89 ) )
return - V_65 ;
if ( ! V_236 -> V_253 )
return - V_65 ;
if ( V_234 -> V_238 & ~ V_254 )
return - V_65 ;
if ( V_234 -> V_255 )
return - V_65 ;
if ( ( V_234 -> V_238 & V_256 ) &&
! V_12 -> V_14 . V_257 )
return - V_65 ;
if ( ( V_234 -> V_238 & V_239 ) &&
( V_234 -> V_238 & V_240 ) )
return - V_65 ;
F_136 ( & V_251 , 0 ) ;
V_6 = F_9 ( V_12 ) ;
if ( ! V_6 )
return - V_19 ;
V_6 -> V_45 = & V_251 ;
V_6 -> V_13 = ! ! ( V_234 -> V_238 & V_258 ) ;
V_207:
V_96 = 0 ;
V_248 = 0 ;
V_249 = 0 ;
V_229 = NULL ;
V_237 = 0 ;
for ( V_24 = 0 ; V_24 < V_234 -> V_259 ; V_24 ++ ) {
T_6 V_260 , V_261 ;
struct V_198 * V_38 ;
if ( F_137 ( V_260 , V_244 + V_248 ) ) {
V_42 = - V_86 ;
goto V_262;
}
V_38 = F_138 ( V_12 , V_260 , V_263 ) ;
if ( ! V_38 ) {
V_42 = - V_264 ;
goto V_262;
}
if ( ! V_38 -> V_265 ) {
F_139 ( V_38 ) ;
V_42 = - V_264 ;
goto V_262;
}
if ( F_137 ( V_261 , V_245 + V_248 ) ) {
F_139 ( V_38 ) ;
V_42 = - V_86 ;
goto V_262;
}
V_248 ++ ;
for ( V_252 = 0 ; V_252 < V_261 ; V_252 ++ ) {
T_6 V_266 ;
T_3 V_225 ;
struct V_71 * V_224 ;
if ( F_137 ( V_266 , V_246 + V_249 ) ) {
F_139 ( V_38 ) ;
V_42 = - V_86 ;
goto V_262;
}
V_224 = F_140 ( V_38 , V_266 ) ;
if ( ! V_224 ) {
F_139 ( V_38 ) ;
V_42 = - V_264 ;
goto V_262;
}
if ( F_141 ( & V_225 ,
V_247 + V_249 ,
sizeof( V_225 ) ) ) {
F_139 ( V_38 ) ;
V_42 = - V_86 ;
goto V_262;
}
V_42 = F_119 ( V_6 , V_38 , V_224 , V_225 ) ;
if ( V_42 ) {
F_139 ( V_38 ) ;
goto V_262;
}
V_249 ++ ;
}
if ( V_38 -> type == V_201 && V_261 &&
! ( V_234 -> V_238 & V_239 ) ) {
V_34 = F_86 ( V_38 ) ;
V_96 |= ( 1 << F_48 ( V_34 ) ) ;
V_34 -> V_227 = V_34 -> V_105 ;
}
F_139 ( V_38 ) ;
}
V_42 = F_127 ( V_12 , V_6 , V_234 , V_236 , & V_229 ,
& V_237 ) ;
if ( V_42 )
goto V_262;
if ( V_234 -> V_238 & V_239 ) {
V_42 = F_100 ( V_6 ) ;
} else if ( V_234 -> V_238 & V_267 ) {
V_42 = F_105 ( V_6 ) ;
} else {
if ( F_142 ( V_268 & V_269 ) )
F_106 ( V_6 ) ;
V_42 = F_104 ( V_6 ) ;
}
V_262:
F_122 ( V_12 , V_96 , V_42 ) ;
F_130 ( V_12 , V_6 , V_229 , V_237 , ! V_42 ) ;
if ( V_42 == - V_270 ) {
F_14 ( V_6 ) ;
F_98 ( & V_251 ) ;
goto V_207;
}
F_143 ( V_6 ) ;
F_144 ( & V_251 ) ;
F_145 ( & V_251 ) ;
return V_42 ;
}
