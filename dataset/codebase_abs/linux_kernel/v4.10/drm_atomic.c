static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 =
F_2 ( V_1 , struct V_2 , V_4 ) ;
F_3 ( V_3 ) ;
}
void F_4 ( struct V_2 * V_3 )
{
F_5 ( & V_3 -> V_4 , F_1 ) ;
}
void F_6 ( struct V_5 * V_6 )
{
F_3 ( V_6 -> V_7 ) ;
F_3 ( V_6 -> V_8 ) ;
F_3 ( V_6 -> V_9 ) ;
}
int
F_7 ( struct V_10 * V_11 , struct V_5 * V_6 )
{
F_8 ( & V_6 -> V_4 ) ;
V_6 -> V_12 = true ;
V_6 -> V_8 = F_9 ( V_11 -> V_13 . V_14 ,
sizeof( * V_6 -> V_8 ) , V_15 ) ;
if ( ! V_6 -> V_8 )
goto V_16;
V_6 -> V_9 = F_9 ( V_11 -> V_13 . V_17 ,
sizeof( * V_6 -> V_9 ) , V_15 ) ;
if ( ! V_6 -> V_9 )
goto V_16;
V_6 -> V_11 = V_11 ;
F_10 ( L_1 , V_6 ) ;
return 0 ;
V_16:
F_6 ( V_6 ) ;
return - V_18 ;
}
struct V_5 *
F_11 ( struct V_10 * V_11 )
{
struct V_19 * V_20 = & V_11 -> V_13 ;
struct V_5 * V_6 ;
if ( ! V_20 -> V_21 -> V_22 ) {
V_6 = F_12 ( sizeof( * V_6 ) , V_15 ) ;
if ( ! V_6 )
return NULL ;
if ( F_7 ( V_11 , V_6 ) < 0 ) {
F_3 ( V_6 ) ;
return NULL ;
}
return V_6 ;
}
return V_20 -> V_21 -> V_22 ( V_11 ) ;
}
void F_13 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_19 * V_20 = & V_11 -> V_13 ;
int V_23 ;
F_10 ( L_2 , V_6 ) ;
for ( V_23 = 0 ; V_23 < V_6 -> V_24 ; V_23 ++ ) {
struct V_25 * V_26 = V_6 -> V_7 [ V_23 ] . V_27 ;
if ( ! V_26 )
continue;
V_26 -> V_21 -> V_28 ( V_26 ,
V_6 -> V_7 [ V_23 ] . V_6 ) ;
V_6 -> V_7 [ V_23 ] . V_27 = NULL ;
V_6 -> V_7 [ V_23 ] . V_6 = NULL ;
F_14 ( V_26 ) ;
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
F_4 ( V_6 -> V_8 [ V_23 ] . V_3 ) ;
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
void F_15 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_19 * V_20 = & V_11 -> V_13 ;
if ( V_20 -> V_21 -> V_34 )
V_20 -> V_21 -> V_34 ( V_6 ) ;
else
F_13 ( V_6 ) ;
}
void F_16 ( struct V_1 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 , F_17 ( * V_6 ) , V_4 ) ;
struct V_19 * V_20 = & V_6 -> V_11 -> V_13 ;
F_15 ( V_6 ) ;
F_10 ( L_3 , V_6 ) ;
if ( V_20 -> V_21 -> V_35 ) {
V_20 -> V_21 -> V_35 ( V_6 ) ;
} else {
F_6 ( V_6 ) ;
F_3 ( V_6 ) ;
}
}
struct V_36 *
F_18 ( struct V_5 * V_6 ,
struct V_29 * V_30 )
{
int V_37 , V_38 = F_19 ( V_30 ) ;
struct V_36 * V_39 ;
F_20 ( ! V_6 -> V_40 ) ;
V_39 = F_21 ( V_6 , V_30 ) ;
if ( V_39 )
return V_39 ;
V_37 = F_22 ( & V_30 -> V_41 , V_6 -> V_40 ) ;
if ( V_37 )
return F_23 ( V_37 ) ;
V_39 = V_30 -> V_21 -> V_42 ( V_30 ) ;
if ( ! V_39 )
return F_23 ( - V_18 ) ;
V_6 -> V_8 [ V_38 ] . V_6 = V_39 ;
V_6 -> V_8 [ V_38 ] . V_27 = V_30 ;
V_39 -> V_6 = V_6 ;
F_10 ( L_4 ,
V_30 -> V_43 . V_44 , V_30 -> V_45 , V_39 , V_6 ) ;
return V_39 ;
}
static void F_24 ( struct V_5 * V_6 ,
struct V_29 * V_30 , T_1 T_2 * V_46 )
{
V_6 -> V_8 [ F_19 ( V_30 ) ] . V_47 = V_46 ;
}
static T_1 T_2 * F_25 ( struct V_5 * V_6 ,
struct V_29 * V_30 )
{
T_1 T_2 * V_46 ;
V_46 = V_6 -> V_8 [ F_19 ( V_30 ) ] . V_47 ;
V_6 -> V_8 [ F_19 ( V_30 ) ] . V_47 = NULL ;
return V_46 ;
}
int F_26 ( struct V_36 * V_6 ,
struct V_48 * V_49 )
{
struct V_50 V_51 ;
if ( V_49 && memcmp ( & V_6 -> V_49 , V_49 , sizeof( * V_49 ) ) == 0 )
return 0 ;
F_27 ( V_6 -> V_52 ) ;
V_6 -> V_52 = NULL ;
if ( V_49 ) {
F_28 ( & V_51 , V_49 ) ;
V_6 -> V_52 =
F_29 ( V_6 -> V_30 -> V_11 ,
sizeof( V_51 ) ,
& V_51 ) ;
if ( F_30 ( V_6 -> V_52 ) )
return F_31 ( V_6 -> V_52 ) ;
F_32 ( & V_6 -> V_49 , V_49 ) ;
V_6 -> V_53 = true ;
F_10 ( L_5 ,
V_49 -> V_45 , V_6 ) ;
} else {
memset ( & V_6 -> V_49 , 0 , sizeof( V_6 -> V_49 ) ) ;
V_6 -> V_53 = false ;
F_10 ( L_6 ,
V_6 ) ;
}
return 0 ;
}
int F_33 ( struct V_36 * V_6 ,
struct V_54 * V_55 )
{
if ( V_55 == V_6 -> V_52 )
return 0 ;
F_27 ( V_6 -> V_52 ) ;
V_6 -> V_52 = NULL ;
memset ( & V_6 -> V_49 , 0 , sizeof( V_6 -> V_49 ) ) ;
if ( V_55 ) {
if ( V_55 -> V_56 != sizeof( struct V_50 ) ||
F_34 ( & V_6 -> V_49 ,
( const struct V_50 * )
V_55 -> V_57 ) )
return - V_58 ;
V_6 -> V_52 = F_35 ( V_55 ) ;
V_6 -> V_53 = true ;
F_10 ( L_5 ,
V_6 -> V_49 . V_45 , V_6 ) ;
} else {
V_6 -> V_53 = false ;
F_10 ( L_6 ,
V_6 ) ;
}
return 0 ;
}
static void
F_36 ( struct V_54 * * V_55 ,
struct V_54 * V_59 ,
bool * V_60 )
{
struct V_54 * V_61 = * V_55 ;
if ( V_61 == V_59 )
return;
F_27 ( V_61 ) ;
if ( V_59 )
F_35 ( V_59 ) ;
* V_55 = V_59 ;
* V_60 = true ;
return;
}
static int
F_37 ( struct V_29 * V_30 ,
struct V_54 * * V_55 ,
T_3 V_62 ,
T_4 V_63 ,
bool * V_60 )
{
struct V_54 * V_59 = NULL ;
if ( V_62 != 0 ) {
V_59 = F_38 ( V_30 -> V_11 , V_62 ) ;
if ( V_59 == NULL )
return - V_58 ;
if ( V_63 > 0 && V_63 != V_59 -> V_56 ) {
F_27 ( V_59 ) ;
return - V_58 ;
}
}
F_36 ( V_55 , V_59 , V_60 ) ;
F_27 ( V_59 ) ;
return 0 ;
}
int F_39 ( struct V_29 * V_30 ,
struct V_36 * V_6 , struct V_64 * V_65 ,
T_3 V_66 )
{
struct V_10 * V_11 = V_30 -> V_11 ;
struct V_19 * V_20 = & V_11 -> V_13 ;
bool V_60 = false ;
int V_37 ;
if ( V_65 == V_20 -> V_67 )
V_6 -> V_68 = V_66 ;
else if ( V_65 == V_20 -> V_69 ) {
struct V_54 * V_49 =
F_38 ( V_11 , V_66 ) ;
V_37 = F_33 ( V_6 , V_49 ) ;
F_27 ( V_49 ) ;
return V_37 ;
} else if ( V_65 == V_20 -> V_70 ) {
V_37 = F_37 ( V_30 ,
& V_6 -> V_71 ,
V_66 ,
- 1 ,
& V_60 ) ;
V_6 -> V_72 |= V_60 ;
return V_37 ;
} else if ( V_65 == V_20 -> V_73 ) {
V_37 = F_37 ( V_30 ,
& V_6 -> V_74 ,
V_66 ,
sizeof( struct V_75 ) ,
& V_60 ) ;
V_6 -> V_72 |= V_60 ;
return V_37 ;
} else if ( V_65 == V_20 -> V_76 ) {
V_37 = F_37 ( V_30 ,
& V_6 -> V_77 ,
V_66 ,
- 1 ,
& V_60 ) ;
V_6 -> V_72 |= V_60 ;
return V_37 ;
} else if ( V_65 == V_20 -> V_78 ) {
T_1 T_2 * V_46 = F_40 ( V_66 ) ;
if ( ! V_46 )
return 0 ;
if ( F_41 ( - 1 , V_46 ) )
return - V_79 ;
F_24 ( V_6 -> V_6 , V_30 , V_46 ) ;
} else if ( V_30 -> V_21 -> V_80 )
return V_30 -> V_21 -> V_80 ( V_30 , V_6 , V_65 , V_66 ) ;
else
return - V_58 ;
return 0 ;
}
static int
F_42 ( struct V_29 * V_30 ,
const struct V_36 * V_6 ,
struct V_64 * V_65 , T_3 * V_66 )
{
struct V_10 * V_11 = V_30 -> V_11 ;
struct V_19 * V_20 = & V_11 -> V_13 ;
if ( V_65 == V_20 -> V_67 )
* V_66 = V_6 -> V_68 ;
else if ( V_65 == V_20 -> V_69 )
* V_66 = ( V_6 -> V_52 ) ? V_6 -> V_52 -> V_43 . V_44 : 0 ;
else if ( V_65 == V_20 -> V_70 )
* V_66 = ( V_6 -> V_71 ) ? V_6 -> V_71 -> V_43 . V_44 : 0 ;
else if ( V_65 == V_20 -> V_73 )
* V_66 = ( V_6 -> V_74 ) ? V_6 -> V_74 -> V_43 . V_44 : 0 ;
else if ( V_65 == V_20 -> V_76 )
* V_66 = ( V_6 -> V_77 ) ? V_6 -> V_77 -> V_43 . V_44 : 0 ;
else if ( V_65 == V_20 -> V_78 )
* V_66 = 0 ;
else if ( V_30 -> V_21 -> V_81 )
return V_30 -> V_21 -> V_81 ( V_30 , V_6 , V_65 , V_66 ) ;
else
return - V_58 ;
return 0 ;
}
static int F_43 ( struct V_29 * V_30 ,
struct V_36 * V_6 )
{
if ( V_6 -> V_68 && ! V_6 -> V_53 ) {
F_10 ( L_7 ,
V_30 -> V_43 . V_44 , V_30 -> V_45 ) ;
return - V_58 ;
}
if ( F_44 ( V_30 -> V_11 , V_82 ) &&
F_20 ( V_6 -> V_53 && ! V_6 -> V_52 ) ) {
F_10 ( L_8 ,
V_30 -> V_43 . V_44 , V_30 -> V_45 ) ;
return - V_58 ;
}
if ( F_44 ( V_30 -> V_11 , V_82 ) &&
F_20 ( ! V_6 -> V_53 && V_6 -> V_52 ) ) {
F_10 ( L_9 ,
V_30 -> V_43 . V_44 , V_30 -> V_45 ) ;
return - V_58 ;
}
if ( V_6 -> V_31 && ! V_6 -> V_68 && ! V_30 -> V_6 -> V_68 ) {
F_10 ( L_10 ,
V_30 -> V_43 . V_44 ) ;
return - V_58 ;
}
return 0 ;
}
static void F_45 ( struct V_83 * V_84 ,
const struct V_36 * V_6 )
{
struct V_29 * V_30 = V_6 -> V_30 ;
F_46 ( V_84 , L_11 , V_30 -> V_43 . V_44 , V_30 -> V_45 ) ;
F_46 ( V_84 , L_12 , V_6 -> V_53 ) ;
F_46 ( V_84 , L_13 , V_6 -> V_68 ) ;
F_46 ( V_84 , L_14 , V_6 -> V_85 ) ;
F_46 ( V_84 , L_15 , V_6 -> V_86 ) ;
F_46 ( V_84 , L_16 , V_6 -> V_87 ) ;
F_46 ( V_84 , L_17 , V_6 -> V_88 ) ;
F_46 ( V_84 , L_18 , V_6 -> V_72 ) ;
F_46 ( V_84 , L_19 , V_6 -> V_89 ) ;
F_46 ( V_84 , L_20 , V_6 -> V_90 ) ;
F_46 ( V_84 , L_21 , V_6 -> V_91 ) ;
F_46 ( V_84 , L_22 V_92 L_23 , F_47 ( & V_6 -> V_49 ) ) ;
if ( V_30 -> V_21 -> V_93 )
V_30 -> V_21 -> V_93 ( V_84 , V_6 ) ;
}
struct V_94 *
F_48 ( struct V_5 * V_6 ,
struct V_32 * V_33 )
{
int V_37 , V_38 = F_49 ( V_33 ) ;
struct V_94 * V_95 ;
F_20 ( ! V_6 -> V_40 ) ;
V_95 = F_50 ( V_6 , V_33 ) ;
if ( V_95 )
return V_95 ;
V_37 = F_22 ( & V_33 -> V_41 , V_6 -> V_40 ) ;
if ( V_37 )
return F_23 ( V_37 ) ;
V_95 = V_33 -> V_21 -> V_42 ( V_33 ) ;
if ( ! V_95 )
return F_23 ( - V_18 ) ;
V_6 -> V_9 [ V_38 ] . V_6 = V_95 ;
V_6 -> V_9 [ V_38 ] . V_27 = V_33 ;
V_95 -> V_6 = V_6 ;
F_10 ( L_24 ,
V_33 -> V_43 . V_44 , V_33 -> V_45 , V_95 , V_6 ) ;
if ( V_95 -> V_30 ) {
struct V_36 * V_39 ;
V_39 = F_18 ( V_6 ,
V_95 -> V_30 ) ;
if ( F_30 ( V_39 ) )
return F_51 ( V_39 ) ;
}
return V_95 ;
}
int F_52 ( struct V_32 * V_33 ,
struct V_94 * V_6 , struct V_64 * V_65 ,
T_3 V_66 )
{
struct V_10 * V_11 = V_33 -> V_11 ;
struct V_19 * V_20 = & V_11 -> V_13 ;
if ( V_65 == V_20 -> V_96 ) {
struct V_97 * V_98 = F_53 ( V_11 , V_66 ) ;
F_54 ( V_6 , V_98 ) ;
if ( V_98 )
F_55 ( V_98 ) ;
} else if ( V_65 == V_20 -> V_99 ) {
if ( V_6 -> V_100 )
return - V_58 ;
if ( F_56 ( V_66 ) == - 1 )
return 0 ;
V_6 -> V_100 = F_57 ( V_66 ) ;
if ( ! V_6 -> V_100 )
return - V_58 ;
} else if ( V_65 == V_20 -> V_101 ) {
struct V_29 * V_30 = F_58 ( V_11 , V_66 ) ;
return F_59 ( V_6 , V_30 ) ;
} else if ( V_65 == V_20 -> V_102 ) {
V_6 -> V_103 = F_56 ( V_66 ) ;
} else if ( V_65 == V_20 -> V_104 ) {
V_6 -> V_105 = F_56 ( V_66 ) ;
} else if ( V_65 == V_20 -> V_106 ) {
V_6 -> V_107 = V_66 ;
} else if ( V_65 == V_20 -> V_108 ) {
V_6 -> V_109 = V_66 ;
} else if ( V_65 == V_20 -> V_110 ) {
V_6 -> V_111 = V_66 ;
} else if ( V_65 == V_20 -> V_112 ) {
V_6 -> V_113 = V_66 ;
} else if ( V_65 == V_20 -> V_114 ) {
V_6 -> V_115 = V_66 ;
} else if ( V_65 == V_20 -> V_116 ) {
V_6 -> V_117 = V_66 ;
} else if ( V_65 == V_33 -> V_118 ) {
if ( ! F_60 ( V_66 & V_119 ) )
return - V_58 ;
V_6 -> V_120 = V_66 ;
} else if ( V_65 == V_33 -> V_121 ) {
V_6 -> V_122 = V_66 ;
} else if ( V_33 -> V_21 -> V_80 ) {
return V_33 -> V_21 -> V_80 ( V_33 , V_6 ,
V_65 , V_66 ) ;
} else {
return - V_58 ;
}
return 0 ;
}
static int
F_61 ( struct V_32 * V_33 ,
const struct V_94 * V_6 ,
struct V_64 * V_65 , T_3 * V_66 )
{
struct V_10 * V_11 = V_33 -> V_11 ;
struct V_19 * V_20 = & V_11 -> V_13 ;
if ( V_65 == V_20 -> V_96 ) {
* V_66 = ( V_6 -> V_98 ) ? V_6 -> V_98 -> V_43 . V_44 : 0 ;
} else if ( V_65 == V_20 -> V_99 ) {
* V_66 = - 1 ;
} else if ( V_65 == V_20 -> V_101 ) {
* V_66 = ( V_6 -> V_30 ) ? V_6 -> V_30 -> V_43 . V_44 : 0 ;
} else if ( V_65 == V_20 -> V_102 ) {
* V_66 = F_62 ( V_6 -> V_103 ) ;
} else if ( V_65 == V_20 -> V_104 ) {
* V_66 = F_62 ( V_6 -> V_105 ) ;
} else if ( V_65 == V_20 -> V_106 ) {
* V_66 = V_6 -> V_107 ;
} else if ( V_65 == V_20 -> V_108 ) {
* V_66 = V_6 -> V_109 ;
} else if ( V_65 == V_20 -> V_110 ) {
* V_66 = V_6 -> V_111 ;
} else if ( V_65 == V_20 -> V_112 ) {
* V_66 = V_6 -> V_113 ;
} else if ( V_65 == V_20 -> V_114 ) {
* V_66 = V_6 -> V_115 ;
} else if ( V_65 == V_20 -> V_116 ) {
* V_66 = V_6 -> V_117 ;
} else if ( V_65 == V_33 -> V_118 ) {
* V_66 = V_6 -> V_120 ;
} else if ( V_65 == V_33 -> V_121 ) {
* V_66 = V_6 -> V_122 ;
} else if ( V_33 -> V_21 -> V_81 ) {
return V_33 -> V_21 -> V_81 ( V_33 , V_6 , V_65 , V_66 ) ;
} else {
return - V_58 ;
}
return 0 ;
}
static bool
F_63 ( struct V_5 * V_6 ,
struct V_32 * V_33 ,
struct V_94 * V_95 )
{
if ( ! V_33 -> V_6 -> V_30 || ! V_95 -> V_30 )
return false ;
if ( V_33 -> V_6 -> V_30 == V_95 -> V_30 )
return false ;
return true ;
}
static int F_64 ( struct V_32 * V_33 ,
struct V_94 * V_6 )
{
unsigned int V_123 , V_124 ;
int V_37 ;
if ( F_20 ( V_6 -> V_30 && ! V_6 -> V_98 ) ) {
F_10 ( L_25 ) ;
return - V_58 ;
} else if ( F_20 ( V_6 -> V_98 && ! V_6 -> V_30 ) ) {
F_10 ( L_26 ) ;
return - V_58 ;
}
if ( ! V_6 -> V_30 )
return 0 ;
if ( ! ( V_33 -> V_125 & F_65 ( V_6 -> V_30 ) ) ) {
F_10 ( L_27 ) ;
return - V_58 ;
}
V_37 = F_66 ( V_33 , V_6 -> V_98 -> V_126 ) ;
if ( V_37 ) {
struct V_127 V_128 ;
F_10 ( L_28 ,
F_67 ( V_6 -> V_98 -> V_126 ,
& V_128 ) ) ;
return V_37 ;
}
if ( V_6 -> V_107 > V_129 ||
V_6 -> V_103 > V_129 - ( V_130 ) V_6 -> V_107 ||
V_6 -> V_109 > V_129 ||
V_6 -> V_105 > V_129 - ( V_130 ) V_6 -> V_109 ) {
F_10 ( L_29 ,
V_6 -> V_107 , V_6 -> V_109 ,
V_6 -> V_103 , V_6 -> V_105 ) ;
return - V_131 ;
}
V_123 = V_6 -> V_98 -> V_132 << 16 ;
V_124 = V_6 -> V_98 -> V_133 << 16 ;
if ( V_6 -> V_115 > V_123 ||
V_6 -> V_111 > V_123 - V_6 -> V_115 ||
V_6 -> V_117 > V_124 ||
V_6 -> V_113 > V_124 - V_6 -> V_117 ) {
F_10 ( L_30
L_31 ,
V_6 -> V_115 >> 16 , ( ( V_6 -> V_115 & 0xffff ) * 15625 ) >> 10 ,
V_6 -> V_117 >> 16 , ( ( V_6 -> V_117 & 0xffff ) * 15625 ) >> 10 ,
V_6 -> V_111 >> 16 , ( ( V_6 -> V_111 & 0xffff ) * 15625 ) >> 10 ,
V_6 -> V_113 >> 16 , ( ( V_6 -> V_113 & 0xffff ) * 15625 ) >> 10 ) ;
return - V_134 ;
}
if ( F_63 ( V_6 -> V_6 , V_33 , V_6 ) ) {
F_10 ( L_32 ,
V_33 -> V_43 . V_44 , V_33 -> V_45 ) ;
return - V_58 ;
}
return 0 ;
}
static void F_68 ( struct V_83 * V_84 ,
const struct V_94 * V_6 )
{
struct V_32 * V_33 = V_6 -> V_33 ;
struct V_135 V_136 = F_69 ( V_6 ) ;
struct V_135 V_137 = F_70 ( V_6 ) ;
F_46 ( V_84 , L_33 , V_33 -> V_43 . V_44 , V_33 -> V_45 ) ;
F_46 ( V_84 , L_34 , V_6 -> V_30 ? V_6 -> V_30 -> V_45 : L_35 ) ;
F_46 ( V_84 , L_36 , V_6 -> V_98 ? V_6 -> V_98 -> V_43 . V_44 : 0 ) ;
if ( V_6 -> V_98 ) {
struct V_97 * V_98 = V_6 -> V_98 ;
int V_23 , V_138 = F_71 ( V_98 -> V_126 ) ;
struct V_127 V_128 ;
F_46 ( V_84 , L_37 ,
F_67 ( V_98 -> V_126 , & V_128 ) ) ;
F_46 ( V_84 , L_38 , V_98 -> V_139 ) ;
F_46 ( V_84 , L_39 , V_98 -> V_132 , V_98 -> V_133 ) ;
F_46 ( V_84 , L_40 ) ;
for ( V_23 = 0 ; V_23 < V_138 ; V_23 ++ ) {
F_46 ( V_84 , L_41 , V_23 , V_98 -> V_140 [ V_23 ] ) ;
F_46 ( V_84 , L_42 , V_23 , V_98 -> V_141 [ V_23 ] ) ;
}
}
F_46 ( V_84 , L_43 V_142 L_23 , F_72 ( & V_137 ) ) ;
F_46 ( V_84 , L_44 V_143 L_23 , F_73 ( & V_136 ) ) ;
F_46 ( V_84 , L_45 , V_6 -> V_120 ) ;
if ( V_33 -> V_21 -> V_93 )
V_33 -> V_21 -> V_93 ( V_84 , V_6 ) ;
}
struct V_144 *
F_74 ( struct V_5 * V_6 ,
struct V_25 * V_26 )
{
int V_37 , V_38 ;
struct V_19 * V_20 = & V_26 -> V_11 -> V_13 ;
struct V_144 * V_145 ;
F_20 ( ! V_6 -> V_40 ) ;
V_37 = F_22 ( & V_20 -> V_146 , V_6 -> V_40 ) ;
if ( V_37 )
return F_23 ( V_37 ) ;
V_38 = F_75 ( V_26 ) ;
if ( V_38 >= V_6 -> V_24 ) {
struct V_147 * V_148 ;
int V_149 = F_76 ( V_38 + 1 , V_20 -> V_24 ) ;
V_148 = F_77 ( V_6 -> V_7 , V_149 * sizeof( * V_6 -> V_7 ) , V_15 ) ;
if ( ! V_148 )
return F_23 ( - V_18 ) ;
V_6 -> V_7 = V_148 ;
memset ( & V_6 -> V_7 [ V_6 -> V_24 ] , 0 ,
sizeof( * V_6 -> V_7 ) * ( V_149 - V_6 -> V_24 ) ) ;
V_6 -> V_24 = V_149 ;
}
if ( V_6 -> V_7 [ V_38 ] . V_6 )
return V_6 -> V_7 [ V_38 ] . V_6 ;
V_145 = V_26 -> V_21 -> V_42 ( V_26 ) ;
if ( ! V_145 )
return F_23 ( - V_18 ) ;
F_78 ( V_26 ) ;
V_6 -> V_7 [ V_38 ] . V_6 = V_145 ;
V_6 -> V_7 [ V_38 ] . V_27 = V_26 ;
V_145 -> V_6 = V_6 ;
F_10 ( L_46 ,
V_26 -> V_43 . V_44 , V_145 , V_6 ) ;
if ( V_145 -> V_30 ) {
struct V_36 * V_39 ;
V_39 = F_18 ( V_6 ,
V_145 -> V_30 ) ;
if ( F_30 ( V_39 ) )
return F_51 ( V_39 ) ;
}
return V_145 ;
}
int F_79 ( struct V_25 * V_26 ,
struct V_144 * V_6 , struct V_64 * V_65 ,
T_3 V_66 )
{
struct V_10 * V_11 = V_26 -> V_11 ;
struct V_19 * V_20 = & V_11 -> V_13 ;
if ( V_65 == V_20 -> V_101 ) {
struct V_29 * V_30 = F_58 ( V_11 , V_66 ) ;
return F_80 ( V_6 , V_30 ) ;
} else if ( V_65 == V_20 -> V_150 ) {
return - V_58 ;
} else if ( V_65 == V_20 -> V_151 ) {
V_6 -> V_152 . V_153 = V_66 ;
} else if ( V_65 == V_20 -> V_154 ) {
V_6 -> V_152 . V_155 . V_156 = V_66 ;
} else if ( V_65 == V_20 -> V_157 ) {
V_6 -> V_152 . V_155 . V_158 = V_66 ;
} else if ( V_65 == V_20 -> V_159 ) {
V_6 -> V_152 . V_155 . V_160 = V_66 ;
} else if ( V_65 == V_20 -> V_161 ) {
V_6 -> V_152 . V_155 . V_162 = V_66 ;
} else if ( V_65 == V_20 -> V_163 ) {
V_6 -> V_152 . V_49 = V_66 ;
} else if ( V_65 == V_20 -> V_164 ) {
V_6 -> V_152 . V_165 = V_66 ;
} else if ( V_65 == V_20 -> V_166 ) {
V_6 -> V_152 . V_167 = V_66 ;
} else if ( V_65 == V_20 -> V_168 ) {
V_6 -> V_152 . V_169 = V_66 ;
} else if ( V_65 == V_20 -> V_170 ) {
V_6 -> V_152 . V_171 = V_66 ;
} else if ( V_65 == V_20 -> V_172 ) {
V_6 -> V_152 . V_173 = V_66 ;
} else if ( V_65 == V_20 -> V_174 ) {
V_6 -> V_152 . V_175 = V_66 ;
} else if ( V_26 -> V_21 -> V_80 ) {
return V_26 -> V_21 -> V_80 ( V_26 ,
V_6 , V_65 , V_66 ) ;
} else {
return - V_58 ;
}
return 0 ;
}
static void F_81 ( struct V_83 * V_84 ,
const struct V_144 * V_6 )
{
struct V_25 * V_26 = V_6 -> V_26 ;
F_46 ( V_84 , L_47 , V_26 -> V_43 . V_44 , V_26 -> V_45 ) ;
F_46 ( V_84 , L_34 , V_6 -> V_30 ? V_6 -> V_30 -> V_45 : L_35 ) ;
if ( V_26 -> V_21 -> V_93 )
V_26 -> V_21 -> V_93 ( V_84 , V_6 ) ;
}
static int
F_82 ( struct V_25 * V_26 ,
const struct V_144 * V_6 ,
struct V_64 * V_65 , T_3 * V_66 )
{
struct V_10 * V_11 = V_26 -> V_11 ;
struct V_19 * V_20 = & V_11 -> V_13 ;
if ( V_65 == V_20 -> V_101 ) {
* V_66 = ( V_6 -> V_30 ) ? V_6 -> V_30 -> V_43 . V_44 : 0 ;
} else if ( V_65 == V_20 -> V_150 ) {
* V_66 = V_26 -> V_176 ;
} else if ( V_65 == V_20 -> V_151 ) {
* V_66 = V_6 -> V_152 . V_153 ;
} else if ( V_65 == V_20 -> V_154 ) {
* V_66 = V_6 -> V_152 . V_155 . V_156 ;
} else if ( V_65 == V_20 -> V_157 ) {
* V_66 = V_6 -> V_152 . V_155 . V_158 ;
} else if ( V_65 == V_20 -> V_159 ) {
* V_66 = V_6 -> V_152 . V_155 . V_160 ;
} else if ( V_65 == V_20 -> V_161 ) {
* V_66 = V_6 -> V_152 . V_155 . V_162 ;
} else if ( V_65 == V_20 -> V_163 ) {
* V_66 = V_6 -> V_152 . V_49 ;
} else if ( V_65 == V_20 -> V_164 ) {
* V_66 = V_6 -> V_152 . V_165 ;
} else if ( V_65 == V_20 -> V_166 ) {
* V_66 = V_6 -> V_152 . V_167 ;
} else if ( V_65 == V_20 -> V_168 ) {
* V_66 = V_6 -> V_152 . V_169 ;
} else if ( V_65 == V_20 -> V_170 ) {
* V_66 = V_6 -> V_152 . V_171 ;
} else if ( V_65 == V_20 -> V_172 ) {
* V_66 = V_6 -> V_152 . V_173 ;
} else if ( V_65 == V_20 -> V_174 ) {
* V_66 = V_6 -> V_152 . V_175 ;
} else if ( V_26 -> V_21 -> V_81 ) {
return V_26 -> V_21 -> V_81 ( V_26 ,
V_6 , V_65 , V_66 ) ;
} else {
return - V_58 ;
}
return 0 ;
}
int F_83 ( struct V_177 * V_178 ,
struct V_64 * V_65 , T_3 * V_66 )
{
struct V_10 * V_11 = V_65 -> V_11 ;
int V_37 ;
switch ( V_178 -> type ) {
case V_179 : {
struct V_25 * V_26 = F_84 ( V_178 ) ;
F_20 ( ! F_85 ( & V_11 -> V_13 . V_146 ) ) ;
V_37 = F_82 ( V_26 ,
V_26 -> V_6 , V_65 , V_66 ) ;
break;
}
case V_180 : {
struct V_29 * V_30 = F_86 ( V_178 ) ;
F_20 ( ! F_85 ( & V_30 -> V_41 ) ) ;
V_37 = F_42 ( V_30 ,
V_30 -> V_6 , V_65 , V_66 ) ;
break;
}
case V_181 : {
struct V_32 * V_33 = F_87 ( V_178 ) ;
F_20 ( ! F_85 ( & V_33 -> V_41 ) ) ;
V_37 = F_61 ( V_33 ,
V_33 -> V_6 , V_65 , V_66 ) ;
break;
}
default:
V_37 = - V_58 ;
break;
}
return V_37 ;
}
int
F_59 ( struct V_94 * V_95 ,
struct V_29 * V_30 )
{
struct V_32 * V_33 = V_95 -> V_33 ;
struct V_36 * V_39 ;
if ( V_95 -> V_30 ) {
V_39 = F_18 ( V_95 -> V_6 ,
V_95 -> V_30 ) ;
if ( F_20 ( F_30 ( V_39 ) ) )
return F_31 ( V_39 ) ;
V_39 -> V_89 &= ~ ( 1 << F_49 ( V_33 ) ) ;
}
V_95 -> V_30 = V_30 ;
if ( V_30 ) {
V_39 = F_18 ( V_95 -> V_6 ,
V_30 ) ;
if ( F_30 ( V_39 ) )
return F_31 ( V_39 ) ;
V_39 -> V_89 |= ( 1 << F_49 ( V_33 ) ) ;
}
if ( V_30 )
F_10 ( L_48 ,
V_95 , V_30 -> V_43 . V_44 , V_30 -> V_45 ) ;
else
F_10 ( L_49 ,
V_95 ) ;
return 0 ;
}
void
F_54 ( struct V_94 * V_95 ,
struct V_97 * V_98 )
{
if ( V_98 )
F_10 ( L_50 ,
V_98 -> V_43 . V_44 , V_95 ) ;
else
F_10 ( L_51 ,
V_95 ) ;
F_88 ( & V_95 -> V_98 , V_98 ) ;
}
void
F_89 ( struct V_94 * V_95 ,
struct V_182 * V_100 )
{
if ( V_95 -> V_100 ) {
F_90 ( V_100 ) ;
return;
}
V_95 -> V_100 = V_100 ;
}
int
F_80 ( struct V_144 * V_183 ,
struct V_29 * V_30 )
{
struct V_36 * V_39 ;
if ( V_183 -> V_30 == V_30 )
return 0 ;
if ( V_183 -> V_30 ) {
V_39 = F_21 ( V_183 -> V_6 ,
V_183 -> V_30 ) ;
V_39 -> V_90 &=
~ ( 1 << F_75 ( V_183 -> V_26 ) ) ;
F_14 ( V_183 -> V_26 ) ;
V_183 -> V_30 = NULL ;
}
if ( V_30 ) {
V_39 = F_18 ( V_183 -> V_6 , V_30 ) ;
if ( F_30 ( V_39 ) )
return F_31 ( V_39 ) ;
V_39 -> V_90 |=
1 << F_75 ( V_183 -> V_26 ) ;
F_78 ( V_183 -> V_26 ) ;
V_183 -> V_30 = V_30 ;
F_10 ( L_52 ,
V_183 , V_30 -> V_43 . V_44 , V_30 -> V_45 ) ;
} else {
F_10 ( L_53 ,
V_183 ) ;
}
return 0 ;
}
int
F_91 ( struct V_5 * V_6 ,
struct V_29 * V_30 )
{
struct V_19 * V_20 = & V_6 -> V_11 -> V_13 ;
struct V_25 * V_26 ;
struct V_144 * V_183 ;
int V_37 ;
V_37 = F_22 ( & V_20 -> V_146 , V_6 -> V_40 ) ;
if ( V_37 )
return V_37 ;
F_10 ( L_54 ,
V_30 -> V_43 . V_44 , V_30 -> V_45 , V_6 ) ;
F_92 (connector, state->dev) {
if ( V_26 -> V_6 -> V_30 != V_30 )
continue;
V_183 = F_74 ( V_6 , V_26 ) ;
if ( F_30 ( V_183 ) )
return F_31 ( V_183 ) ;
}
return 0 ;
}
int
F_93 ( struct V_5 * V_6 ,
struct V_29 * V_30 )
{
struct V_32 * V_33 ;
F_20 ( ! F_21 ( V_6 , V_30 ) ) ;
F_94 (plane, state->dev, crtc->state->plane_mask) {
struct V_94 * V_95 =
F_48 ( V_6 , V_33 ) ;
if ( F_30 ( V_95 ) )
return F_31 ( V_95 ) ;
}
return 0 ;
}
void F_95 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
unsigned V_184 = 0 ;
struct V_29 * V_30 ;
int V_37 ;
bool V_185 = false ;
F_96 (crtc, dev) {
if ( V_30 -> V_40 != V_6 -> V_40 )
continue;
V_184 |= F_65 ( V_30 ) ;
V_30 -> V_40 = NULL ;
}
if ( F_20 ( V_11 -> V_13 . V_40 == V_6 -> V_40 ) ) {
V_185 = true ;
V_11 -> V_13 . V_40 = NULL ;
}
V_186:
F_97 ( V_6 -> V_40 ) ;
V_37 = F_98 ( V_11 , V_6 -> V_40 ) ;
if ( V_37 )
goto V_186;
F_96 (crtc, dev)
if ( F_65 ( V_30 ) & V_184 )
V_30 -> V_40 = V_6 -> V_40 ;
if ( V_185 )
V_11 -> V_13 . V_40 = V_6 -> V_40 ;
}
int F_99 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_19 * V_20 = & V_11 -> V_13 ;
struct V_32 * V_33 ;
struct V_94 * V_95 ;
struct V_29 * V_30 ;
struct V_36 * V_39 ;
int V_23 , V_37 = 0 ;
F_10 ( L_55 , V_6 ) ;
F_100 (state, plane, plane_state, i) {
V_37 = F_64 ( V_33 , V_95 ) ;
if ( V_37 ) {
F_10 ( L_56 ,
V_33 -> V_43 . V_44 , V_33 -> V_45 ) ;
return V_37 ;
}
}
F_101 (state, crtc, crtc_state, i) {
V_37 = F_43 ( V_30 , V_39 ) ;
if ( V_37 ) {
F_10 ( L_57 ,
V_30 -> V_43 . V_44 , V_30 -> V_45 ) ;
return V_37 ;
}
}
if ( V_20 -> V_21 -> V_187 )
V_37 = V_20 -> V_21 -> V_187 ( V_6 -> V_11 , V_6 ) ;
if ( ! V_6 -> V_12 ) {
F_101 (state, crtc, crtc_state, i) {
if ( F_102 ( V_39 ) ) {
F_10 ( L_58 ,
V_30 -> V_43 . V_44 , V_30 -> V_45 ) ;
return - V_58 ;
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
F_10 ( L_59 , V_6 ) ;
return V_20 -> V_21 -> V_188 ( V_6 -> V_11 , V_6 , false ) ;
}
int F_104 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = & V_6 -> V_11 -> V_13 ;
int V_37 ;
V_37 = F_99 ( V_6 ) ;
if ( V_37 )
return V_37 ;
F_10 ( L_60 , V_6 ) ;
return V_20 -> V_21 -> V_188 ( V_6 -> V_11 , V_6 , true ) ;
}
static void F_105 ( const struct V_5 * V_6 )
{
struct V_83 V_84 = F_106 ( V_6 -> V_11 -> V_11 ) ;
struct V_32 * V_33 ;
struct V_94 * V_95 ;
struct V_29 * V_30 ;
struct V_36 * V_39 ;
struct V_25 * V_26 ;
struct V_144 * V_145 ;
int V_23 ;
F_10 ( L_55 , V_6 ) ;
F_100 (state, plane, plane_state, i)
F_68 ( & V_84 , V_95 ) ;
F_101 (state, crtc, crtc_state, i)
F_45 ( & V_84 , V_39 ) ;
F_107 (state, connector, connector_state, i)
F_81 ( & V_84 , V_145 ) ;
}
void F_108 ( struct V_10 * V_11 , struct V_83 * V_84 )
{
struct V_19 * V_20 = & V_11 -> V_13 ;
struct V_32 * V_33 ;
struct V_29 * V_30 ;
struct V_25 * V_26 ;
if ( ! F_44 ( V_11 , V_82 ) )
return;
F_109 (plane, &config->plane_list, head)
F_68 ( V_84 , V_33 -> V_6 ) ;
F_109 (crtc, &config->crtc_list, head)
F_45 ( V_84 , V_30 -> V_6 ) ;
F_109 (connector, &config->connector_list, head)
F_81 ( V_84 , V_26 -> V_6 ) ;
}
static int F_110 ( struct V_189 * V_190 , void * V_57 )
{
struct V_191 * V_192 = (struct V_191 * ) V_190 -> V_193 ;
struct V_10 * V_11 = V_192 -> V_194 -> V_11 ;
struct V_83 V_84 = F_111 ( V_190 ) ;
F_112 ( V_11 ) ;
F_108 ( V_11 , & V_84 ) ;
F_113 ( V_11 ) ;
return 0 ;
}
int F_114 ( struct V_195 * V_194 )
{
return F_115 ( V_196 ,
F_116 ( V_196 ) ,
V_194 -> V_197 , V_194 ) ;
}
int F_117 ( struct V_195 * V_194 )
{
return F_118 ( V_196 ,
F_116 ( V_196 ) ,
V_194 ) ;
}
static struct V_198 * F_119 (
struct V_10 * V_11 , T_3 V_199 )
{
struct V_198 * V_200 = NULL ;
V_200 = F_12 ( sizeof *V_200 , V_15 ) ;
if ( ! V_200 )
return NULL ;
V_200 -> V_31 . V_43 . type = V_201 ;
V_200 -> V_31 . V_43 . V_56 = sizeof( V_200 -> V_31 ) ;
V_200 -> V_31 . V_199 = V_199 ;
return V_200 ;
}
static int F_120 ( struct V_5 * V_6 ,
struct V_177 * V_178 , struct V_64 * V_202 ,
T_3 V_203 )
{
struct V_177 * V_4 ;
int V_37 ;
if ( ! F_121 ( V_202 , V_203 , & V_4 ) )
return - V_58 ;
switch ( V_178 -> type ) {
case V_179 : {
struct V_25 * V_26 = F_84 ( V_178 ) ;
struct V_144 * V_145 ;
V_145 = F_74 ( V_6 , V_26 ) ;
if ( F_30 ( V_145 ) ) {
V_37 = F_31 ( V_145 ) ;
break;
}
V_37 = F_79 ( V_26 ,
V_145 , V_202 , V_203 ) ;
break;
}
case V_180 : {
struct V_29 * V_30 = F_86 ( V_178 ) ;
struct V_36 * V_39 ;
V_39 = F_18 ( V_6 , V_30 ) ;
if ( F_30 ( V_39 ) ) {
V_37 = F_31 ( V_39 ) ;
break;
}
V_37 = F_39 ( V_30 ,
V_39 , V_202 , V_203 ) ;
break;
}
case V_181 : {
struct V_32 * V_33 = F_87 ( V_178 ) ;
struct V_94 * V_95 ;
V_95 = F_48 ( V_6 , V_33 ) ;
if ( F_30 ( V_95 ) ) {
V_37 = F_31 ( V_95 ) ;
break;
}
V_37 = F_52 ( V_33 ,
V_95 , V_202 , V_203 ) ;
break;
}
default:
V_37 = - V_58 ;
break;
}
F_122 ( V_202 , V_4 ) ;
return V_37 ;
}
void F_123 ( struct V_10 * V_11 ,
unsigned V_89 ,
int V_37 )
{
struct V_32 * V_33 ;
F_94 (plane, dev, plane_mask) {
if ( V_37 == 0 ) {
struct V_97 * V_204 = V_33 -> V_6 -> V_98 ;
if ( V_204 )
F_124 ( V_204 ) ;
V_33 -> V_98 = V_204 ;
V_33 -> V_30 = V_33 -> V_6 -> V_30 ;
if ( V_33 -> V_205 )
F_55 ( V_33 -> V_205 ) ;
}
V_33 -> V_205 = NULL ;
}
}
static int F_125 ( struct V_206 * V_207 ,
struct V_182 * V_100 )
{
V_207 -> V_208 = F_126 ( V_209 ) ;
if ( V_207 -> V_208 < 0 )
return V_207 -> V_208 ;
if ( F_41 ( V_207 -> V_208 , V_207 -> V_47 ) )
return - V_79 ;
V_207 -> V_210 = F_127 ( V_100 ) ;
if ( ! V_207 -> V_210 )
return - V_18 ;
return 0 ;
}
static int F_128 ( struct V_10 * V_11 ,
struct V_5 * V_6 ,
struct V_211 * V_212 ,
struct V_213 * V_214 ,
struct V_206 * * V_207 ,
unsigned int * V_215 )
{
struct V_29 * V_30 ;
struct V_36 * V_39 ;
int V_23 , V_37 ;
if ( V_212 -> V_216 & V_217 )
return 0 ;
F_101 (state, crtc, crtc_state, i) {
T_1 T_2 * V_46 ;
V_46 = F_25 ( V_39 -> V_6 , V_30 ) ;
if ( V_212 -> V_216 & V_218 || V_46 ) {
struct V_198 * V_200 ;
V_200 = F_119 ( V_11 , V_212 -> V_199 ) ;
if ( ! V_200 )
return - V_18 ;
V_39 -> V_31 = V_200 ;
}
if ( V_212 -> V_216 & V_218 ) {
struct V_198 * V_200 = V_39 -> V_31 ;
if ( ! V_214 )
continue;
V_37 = F_129 ( V_11 , V_214 , & V_200 -> V_43 ,
& V_200 -> V_31 . V_43 ) ;
if ( V_37 ) {
F_3 ( V_200 ) ;
V_39 -> V_31 = NULL ;
return V_37 ;
}
}
if ( V_46 ) {
struct V_182 * V_100 ;
struct V_206 * V_219 ;
V_219 = F_77 ( * V_207 , sizeof( * * V_207 ) *
( * V_215 + 1 ) , V_15 ) ;
if ( ! V_219 )
return - V_18 ;
memset ( & V_219 [ * V_215 ] , 0 , sizeof( * V_219 ) ) ;
V_219 [ * V_215 ] . V_47 = V_46 ;
* V_207 = V_219 ;
V_100 = F_130 ( V_30 ) ;
if ( ! V_100 )
return - V_18 ;
V_37 = F_125 ( & V_219 [ ( * V_215 ) ++ ] , V_100 ) ;
if ( V_37 ) {
F_90 ( V_100 ) ;
return V_37 ;
}
V_39 -> V_31 -> V_43 . V_100 = V_100 ;
}
}
return 0 ;
}
static void F_131 ( struct V_10 * V_11 ,
struct V_5 * V_6 ,
struct V_206 * V_207 ,
unsigned int V_215 ,
bool V_220 )
{
struct V_29 * V_30 ;
struct V_36 * V_39 ;
int V_23 ;
if ( V_220 ) {
for ( V_23 = 0 ; V_23 < V_215 ; V_23 ++ )
F_132 ( V_207 [ V_23 ] . V_208 ,
V_207 [ V_23 ] . V_210 -> V_221 ) ;
F_3 ( V_207 ) ;
return;
}
F_101 (state, crtc, crtc_state, i) {
struct V_198 * V_31 = V_39 -> V_31 ;
if ( V_31 && ( V_31 -> V_43 . V_100 || V_31 -> V_43 . V_214 ) ) {
F_133 ( V_11 , & V_31 -> V_43 ) ;
V_39 -> V_31 = NULL ;
}
}
if ( ! V_207 )
return;
for ( V_23 = 0 ; V_23 < V_215 ; V_23 ++ ) {
if ( V_207 [ V_23 ] . V_210 )
F_134 ( V_207 [ V_23 ] . V_210 -> V_221 ) ;
if ( V_207 [ V_23 ] . V_208 >= 0 )
F_135 ( V_207 [ V_23 ] . V_208 ) ;
if ( V_207 [ V_23 ] . V_47 &&
F_41 ( - 1 , V_207 [ V_23 ] . V_47 ) )
F_10 ( L_61 ) ;
}
F_3 ( V_207 ) ;
}
int F_136 ( struct V_10 * V_11 ,
void * V_57 , struct V_213 * V_214 )
{
struct V_211 * V_212 = V_57 ;
T_5 T_2 * V_222 = ( T_5 T_2 * ) ( unsigned long ) ( V_212 -> V_222 ) ;
T_5 T_2 * V_223 = ( T_5 T_2 * ) ( unsigned long ) ( V_212 -> V_223 ) ;
T_5 T_2 * V_224 = ( T_5 T_2 * ) ( unsigned long ) ( V_212 -> V_224 ) ;
T_3 T_2 * V_225 = ( T_3 T_2 * ) ( unsigned long ) ( V_212 -> V_225 ) ;
unsigned int V_226 , V_227 ;
struct V_5 * V_6 ;
struct V_228 V_229 ;
struct V_32 * V_33 ;
struct V_206 * V_207 = NULL ;
unsigned V_89 ;
int V_37 = 0 ;
unsigned int V_23 , V_230 , V_215 = 0 ;
if ( ! F_44 ( V_11 , V_82 ) )
return - V_58 ;
if ( ! V_214 -> V_231 )
return - V_58 ;
if ( V_212 -> V_216 & ~ V_232 )
return - V_58 ;
if ( V_212 -> V_233 )
return - V_58 ;
if ( ( V_212 -> V_216 & V_234 ) &&
! V_11 -> V_13 . V_235 )
return - V_58 ;
if ( ( V_212 -> V_216 & V_217 ) &&
( V_212 -> V_216 & V_218 ) )
return - V_58 ;
F_137 ( & V_229 , 0 ) ;
V_6 = F_11 ( V_11 ) ;
if ( ! V_6 )
return - V_18 ;
V_6 -> V_40 = & V_229 ;
V_6 -> V_12 = ! ! ( V_212 -> V_216 & V_236 ) ;
V_186:
V_89 = 0 ;
V_226 = 0 ;
V_227 = 0 ;
for ( V_23 = 0 ; V_23 < V_212 -> V_237 ; V_23 ++ ) {
T_5 V_238 , V_239 ;
struct V_177 * V_178 ;
if ( F_138 ( V_238 , V_222 + V_226 ) ) {
V_37 = - V_79 ;
goto V_240;
}
V_178 = F_139 ( V_11 , V_238 , V_241 ) ;
if ( ! V_178 ) {
V_37 = - V_242 ;
goto V_240;
}
if ( ! V_178 -> V_243 ) {
F_140 ( V_178 ) ;
V_37 = - V_242 ;
goto V_240;
}
if ( F_138 ( V_239 , V_223 + V_226 ) ) {
F_140 ( V_178 ) ;
V_37 = - V_79 ;
goto V_240;
}
V_226 ++ ;
for ( V_230 = 0 ; V_230 < V_239 ; V_230 ++ ) {
T_5 V_244 ;
T_3 V_203 ;
struct V_64 * V_202 ;
if ( F_138 ( V_244 , V_224 + V_227 ) ) {
F_140 ( V_178 ) ;
V_37 = - V_79 ;
goto V_240;
}
V_202 = F_141 ( V_178 , V_244 ) ;
if ( ! V_202 ) {
F_140 ( V_178 ) ;
V_37 = - V_242 ;
goto V_240;
}
if ( F_142 ( & V_203 ,
V_225 + V_227 ,
sizeof( V_203 ) ) ) {
F_140 ( V_178 ) ;
V_37 = - V_79 ;
goto V_240;
}
V_37 = F_120 ( V_6 , V_178 , V_202 , V_203 ) ;
if ( V_37 ) {
F_140 ( V_178 ) ;
goto V_240;
}
V_227 ++ ;
}
if ( V_178 -> type == V_181 && V_239 &&
! ( V_212 -> V_216 & V_217 ) ) {
V_33 = F_87 ( V_178 ) ;
V_89 |= ( 1 << F_49 ( V_33 ) ) ;
V_33 -> V_205 = V_33 -> V_98 ;
}
F_140 ( V_178 ) ;
}
V_37 = F_128 ( V_11 , V_6 , V_212 , V_214 , & V_207 ,
& V_215 ) ;
if ( V_37 )
goto V_240;
if ( V_212 -> V_216 & V_217 ) {
V_37 = F_99 ( V_6 ) ;
} else if ( V_212 -> V_216 & V_245 ) {
V_37 = F_104 ( V_6 ) ;
} else {
if ( F_143 ( V_246 & V_247 ) )
F_105 ( V_6 ) ;
V_37 = F_103 ( V_6 ) ;
}
V_240:
F_123 ( V_11 , V_89 , V_37 ) ;
F_131 ( V_11 , V_6 , V_207 , V_215 , ! V_37 ) ;
if ( V_37 == - V_248 ) {
F_15 ( V_6 ) ;
F_97 ( & V_229 ) ;
goto V_186;
}
F_144 ( V_6 ) ;
F_145 ( & V_229 ) ;
F_146 ( & V_229 ) ;
return V_37 ;
}
