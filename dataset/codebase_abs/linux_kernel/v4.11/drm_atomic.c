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
V_6 -> V_8 [ V_38 ] . V_27 = V_30 ;
V_39 -> V_6 = V_6 ;
F_8 ( L_4 ,
V_30 -> V_43 . V_44 , V_30 -> V_45 , V_39 , V_6 ) ;
return V_39 ;
}
static void F_23 ( struct V_5 * V_6 ,
struct V_29 * V_30 , T_1 T_2 * V_46 )
{
V_6 -> V_8 [ F_18 ( V_30 ) ] . V_47 = V_46 ;
}
static T_1 T_2 * F_24 ( struct V_5 * V_6 ,
struct V_29 * V_30 )
{
T_1 T_2 * V_46 ;
V_46 = V_6 -> V_8 [ F_18 ( V_30 ) ] . V_47 ;
V_6 -> V_8 [ F_18 ( V_30 ) ] . V_47 = NULL ;
return V_46 ;
}
int F_25 ( struct V_36 * V_6 ,
struct V_48 * V_49 )
{
struct V_50 V_51 ;
if ( V_49 && memcmp ( & V_6 -> V_49 , V_49 , sizeof( * V_49 ) ) == 0 )
return 0 ;
F_26 ( V_6 -> V_52 ) ;
V_6 -> V_52 = NULL ;
if ( V_49 ) {
F_27 ( & V_51 , V_49 ) ;
V_6 -> V_52 =
F_28 ( V_6 -> V_30 -> V_11 ,
sizeof( V_51 ) ,
& V_51 ) ;
if ( F_29 ( V_6 -> V_52 ) )
return F_30 ( V_6 -> V_52 ) ;
F_31 ( & V_6 -> V_49 , V_49 ) ;
V_6 -> V_53 = true ;
F_8 ( L_5 ,
V_49 -> V_45 , V_6 ) ;
} else {
memset ( & V_6 -> V_49 , 0 , sizeof( V_6 -> V_49 ) ) ;
V_6 -> V_53 = false ;
F_8 ( L_6 ,
V_6 ) ;
}
return 0 ;
}
int F_32 ( struct V_36 * V_6 ,
struct V_54 * V_55 )
{
if ( V_55 == V_6 -> V_52 )
return 0 ;
F_26 ( V_6 -> V_52 ) ;
V_6 -> V_52 = NULL ;
memset ( & V_6 -> V_49 , 0 , sizeof( V_6 -> V_49 ) ) ;
if ( V_55 ) {
if ( V_55 -> V_56 != sizeof( struct V_50 ) ||
F_33 ( & V_6 -> V_49 ,
( const struct V_50 * )
V_55 -> V_57 ) )
return - V_58 ;
V_6 -> V_52 = F_34 ( V_55 ) ;
V_6 -> V_53 = true ;
F_8 ( L_5 ,
V_6 -> V_49 . V_45 , V_6 ) ;
} else {
V_6 -> V_53 = false ;
F_8 ( L_6 ,
V_6 ) ;
}
return 0 ;
}
static void
F_35 ( struct V_54 * * V_55 ,
struct V_54 * V_59 ,
bool * V_60 )
{
struct V_54 * V_61 = * V_55 ;
if ( V_61 == V_59 )
return;
F_26 ( V_61 ) ;
if ( V_59 )
F_34 ( V_59 ) ;
* V_55 = V_59 ;
* V_60 = true ;
return;
}
static int
F_36 ( struct V_29 * V_30 ,
struct V_54 * * V_55 ,
T_3 V_62 ,
T_4 V_63 ,
bool * V_60 )
{
struct V_54 * V_59 = NULL ;
if ( V_62 != 0 ) {
V_59 = F_37 ( V_30 -> V_11 , V_62 ) ;
if ( V_59 == NULL )
return - V_58 ;
if ( V_63 > 0 && V_63 != V_59 -> V_56 ) {
F_26 ( V_59 ) ;
return - V_58 ;
}
}
F_35 ( V_55 , V_59 , V_60 ) ;
F_26 ( V_59 ) ;
return 0 ;
}
int F_38 ( struct V_29 * V_30 ,
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
F_37 ( V_11 , V_66 ) ;
V_37 = F_32 ( V_6 , V_49 ) ;
F_26 ( V_49 ) ;
return V_37 ;
} else if ( V_65 == V_20 -> V_70 ) {
V_37 = F_36 ( V_30 ,
& V_6 -> V_71 ,
V_66 ,
- 1 ,
& V_60 ) ;
V_6 -> V_72 |= V_60 ;
return V_37 ;
} else if ( V_65 == V_20 -> V_73 ) {
V_37 = F_36 ( V_30 ,
& V_6 -> V_74 ,
V_66 ,
sizeof( struct V_75 ) ,
& V_60 ) ;
V_6 -> V_72 |= V_60 ;
return V_37 ;
} else if ( V_65 == V_20 -> V_76 ) {
V_37 = F_36 ( V_30 ,
& V_6 -> V_77 ,
V_66 ,
- 1 ,
& V_60 ) ;
V_6 -> V_72 |= V_60 ;
return V_37 ;
} else if ( V_65 == V_20 -> V_78 ) {
T_1 T_2 * V_46 = F_39 ( V_66 ) ;
if ( ! V_46 )
return 0 ;
if ( F_40 ( - 1 , V_46 ) )
return - V_79 ;
F_23 ( V_6 -> V_6 , V_30 , V_46 ) ;
} else if ( V_30 -> V_21 -> V_80 )
return V_30 -> V_21 -> V_80 ( V_30 , V_6 , V_65 , V_66 ) ;
else
return - V_58 ;
return 0 ;
}
static int
F_41 ( struct V_29 * V_30 ,
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
static int F_42 ( struct V_29 * V_30 ,
struct V_36 * V_6 )
{
if ( V_6 -> V_68 && ! V_6 -> V_53 ) {
F_8 ( L_7 ,
V_30 -> V_43 . V_44 , V_30 -> V_45 ) ;
return - V_58 ;
}
if ( F_43 ( V_30 -> V_11 , V_82 ) &&
F_19 ( V_6 -> V_53 && ! V_6 -> V_52 ) ) {
F_8 ( L_8 ,
V_30 -> V_43 . V_44 , V_30 -> V_45 ) ;
return - V_58 ;
}
if ( F_43 ( V_30 -> V_11 , V_82 ) &&
F_19 ( ! V_6 -> V_53 && V_6 -> V_52 ) ) {
F_8 ( L_9 ,
V_30 -> V_43 . V_44 , V_30 -> V_45 ) ;
return - V_58 ;
}
if ( V_6 -> V_31 && ! V_6 -> V_68 && ! V_30 -> V_6 -> V_68 ) {
F_8 ( L_10 ,
V_30 -> V_43 . V_44 ) ;
return - V_58 ;
}
return 0 ;
}
static void F_44 ( struct V_83 * V_84 ,
const struct V_36 * V_6 )
{
struct V_29 * V_30 = V_6 -> V_30 ;
F_45 ( V_84 , L_11 , V_30 -> V_43 . V_44 , V_30 -> V_45 ) ;
F_45 ( V_84 , L_12 , V_6 -> V_53 ) ;
F_45 ( V_84 , L_13 , V_6 -> V_68 ) ;
F_45 ( V_84 , L_14 , V_6 -> V_85 ) ;
F_45 ( V_84 , L_15 , V_6 -> V_86 ) ;
F_45 ( V_84 , L_16 , V_6 -> V_87 ) ;
F_45 ( V_84 , L_17 , V_6 -> V_88 ) ;
F_45 ( V_84 , L_18 , V_6 -> V_72 ) ;
F_45 ( V_84 , L_19 , V_6 -> V_89 ) ;
F_45 ( V_84 , L_20 , V_6 -> V_90 ) ;
F_45 ( V_84 , L_21 , V_6 -> V_91 ) ;
F_45 ( V_84 , L_22 V_92 L_23 , F_46 ( & V_6 -> V_49 ) ) ;
if ( V_30 -> V_21 -> V_93 )
V_30 -> V_21 -> V_93 ( V_84 , V_6 ) ;
}
struct V_94 *
F_47 ( struct V_5 * V_6 ,
struct V_32 * V_33 )
{
int V_37 , V_38 = F_48 ( V_33 ) ;
struct V_94 * V_95 ;
F_19 ( ! V_6 -> V_40 ) ;
V_95 = F_49 ( V_6 , V_33 ) ;
if ( V_95 )
return V_95 ;
V_37 = F_21 ( & V_33 -> V_41 , V_6 -> V_40 ) ;
if ( V_37 )
return F_22 ( V_37 ) ;
V_95 = V_33 -> V_21 -> V_42 ( V_33 ) ;
if ( ! V_95 )
return F_22 ( - V_18 ) ;
V_6 -> V_9 [ V_38 ] . V_6 = V_95 ;
V_6 -> V_9 [ V_38 ] . V_27 = V_33 ;
V_95 -> V_6 = V_6 ;
F_8 ( L_24 ,
V_33 -> V_43 . V_44 , V_33 -> V_45 , V_95 , V_6 ) ;
if ( V_95 -> V_30 ) {
struct V_36 * V_39 ;
V_39 = F_17 ( V_6 ,
V_95 -> V_30 ) ;
if ( F_29 ( V_39 ) )
return F_50 ( V_39 ) ;
}
return V_95 ;
}
int F_51 ( struct V_32 * V_33 ,
struct V_94 * V_6 , struct V_64 * V_65 ,
T_3 V_66 )
{
struct V_10 * V_11 = V_33 -> V_11 ;
struct V_19 * V_20 = & V_11 -> V_13 ;
if ( V_65 == V_20 -> V_96 ) {
struct V_97 * V_98 = F_52 ( V_11 , V_66 ) ;
F_53 ( V_6 , V_98 ) ;
if ( V_98 )
F_54 ( V_98 ) ;
} else if ( V_65 == V_20 -> V_99 ) {
if ( V_6 -> V_100 )
return - V_58 ;
if ( F_55 ( V_66 ) == - 1 )
return 0 ;
V_6 -> V_100 = F_56 ( V_66 ) ;
if ( ! V_6 -> V_100 )
return - V_58 ;
} else if ( V_65 == V_20 -> V_101 ) {
struct V_29 * V_30 = F_57 ( V_11 , V_66 ) ;
return F_58 ( V_6 , V_30 ) ;
} else if ( V_65 == V_20 -> V_102 ) {
V_6 -> V_103 = F_55 ( V_66 ) ;
} else if ( V_65 == V_20 -> V_104 ) {
V_6 -> V_105 = F_55 ( V_66 ) ;
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
if ( ! F_59 ( V_66 & V_119 ) )
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
F_60 ( struct V_32 * V_33 ,
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
* V_66 = F_61 ( V_6 -> V_103 ) ;
} else if ( V_65 == V_20 -> V_104 ) {
* V_66 = F_61 ( V_6 -> V_105 ) ;
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
F_62 ( struct V_5 * V_6 ,
struct V_32 * V_33 ,
struct V_94 * V_95 )
{
if ( ! V_33 -> V_6 -> V_30 || ! V_95 -> V_30 )
return false ;
if ( V_33 -> V_6 -> V_30 == V_95 -> V_30 )
return false ;
return true ;
}
static int F_63 ( struct V_32 * V_33 ,
struct V_94 * V_6 )
{
unsigned int V_123 , V_124 ;
int V_37 ;
if ( F_19 ( V_6 -> V_30 && ! V_6 -> V_98 ) ) {
F_8 ( L_25 ) ;
return - V_58 ;
} else if ( F_19 ( V_6 -> V_98 && ! V_6 -> V_30 ) ) {
F_8 ( L_26 ) ;
return - V_58 ;
}
if ( ! V_6 -> V_30 )
return 0 ;
if ( ! ( V_33 -> V_125 & F_64 ( V_6 -> V_30 ) ) ) {
F_8 ( L_27 ) ;
return - V_58 ;
}
V_37 = F_65 ( V_33 , V_6 -> V_98 -> V_126 -> V_126 ) ;
if ( V_37 ) {
struct V_127 V_128 ;
F_8 ( L_28 ,
F_66 ( V_6 -> V_98 -> V_126 -> V_126 ,
& V_128 ) ) ;
return V_37 ;
}
if ( V_6 -> V_107 > V_129 ||
V_6 -> V_103 > V_129 - ( V_130 ) V_6 -> V_107 ||
V_6 -> V_109 > V_129 ||
V_6 -> V_105 > V_129 - ( V_130 ) V_6 -> V_109 ) {
F_8 ( L_29 ,
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
F_8 ( L_30
L_31 ,
V_6 -> V_115 >> 16 , ( ( V_6 -> V_115 & 0xffff ) * 15625 ) >> 10 ,
V_6 -> V_117 >> 16 , ( ( V_6 -> V_117 & 0xffff ) * 15625 ) >> 10 ,
V_6 -> V_111 >> 16 , ( ( V_6 -> V_111 & 0xffff ) * 15625 ) >> 10 ,
V_6 -> V_113 >> 16 , ( ( V_6 -> V_113 & 0xffff ) * 15625 ) >> 10 ) ;
return - V_134 ;
}
if ( F_62 ( V_6 -> V_6 , V_33 , V_6 ) ) {
F_8 ( L_32 ,
V_33 -> V_43 . V_44 , V_33 -> V_45 ) ;
return - V_58 ;
}
return 0 ;
}
static void F_67 ( struct V_83 * V_84 ,
const struct V_94 * V_6 )
{
struct V_32 * V_33 = V_6 -> V_33 ;
struct V_135 V_136 = F_68 ( V_6 ) ;
struct V_135 V_137 = F_69 ( V_6 ) ;
F_45 ( V_84 , L_33 , V_33 -> V_43 . V_44 , V_33 -> V_45 ) ;
F_45 ( V_84 , L_34 , V_6 -> V_30 ? V_6 -> V_30 -> V_45 : L_35 ) ;
F_45 ( V_84 , L_36 , V_6 -> V_98 ? V_6 -> V_98 -> V_43 . V_44 : 0 ) ;
if ( V_6 -> V_98 ) {
struct V_97 * V_98 = V_6 -> V_98 ;
int V_23 , V_138 = V_98 -> V_126 -> V_139 ;
struct V_127 V_128 ;
F_45 ( V_84 , L_37 ,
F_66 ( V_98 -> V_126 -> V_126 , & V_128 ) ) ;
F_45 ( V_84 , L_38 , V_98 -> V_140 ) ;
F_45 ( V_84 , L_39 , V_98 -> V_132 , V_98 -> V_133 ) ;
F_45 ( V_84 , L_40 ) ;
for ( V_23 = 0 ; V_23 < V_138 ; V_23 ++ ) {
F_45 ( V_84 , L_41 , V_23 , V_98 -> V_141 [ V_23 ] ) ;
F_45 ( V_84 , L_42 , V_23 , V_98 -> V_142 [ V_23 ] ) ;
}
}
F_45 ( V_84 , L_43 V_143 L_23 , F_70 ( & V_137 ) ) ;
F_45 ( V_84 , L_44 V_144 L_23 , F_71 ( & V_136 ) ) ;
F_45 ( V_84 , L_45 , V_6 -> V_120 ) ;
if ( V_33 -> V_21 -> V_93 )
V_33 -> V_21 -> V_93 ( V_84 , V_6 ) ;
}
struct V_145 *
F_72 ( struct V_5 * V_6 ,
struct V_25 * V_26 )
{
int V_37 , V_38 ;
struct V_19 * V_20 = & V_26 -> V_11 -> V_13 ;
struct V_145 * V_146 ;
F_19 ( ! V_6 -> V_40 ) ;
V_37 = F_21 ( & V_20 -> V_147 , V_6 -> V_40 ) ;
if ( V_37 )
return F_22 ( V_37 ) ;
V_38 = F_73 ( V_26 ) ;
if ( V_38 >= V_6 -> V_24 ) {
struct V_148 * V_149 ;
int V_150 = F_74 ( V_38 + 1 , V_20 -> V_24 ) ;
V_149 = F_75 ( V_6 -> V_7 , V_150 * sizeof( * V_6 -> V_7 ) , V_15 ) ;
if ( ! V_149 )
return F_22 ( - V_18 ) ;
V_6 -> V_7 = V_149 ;
memset ( & V_6 -> V_7 [ V_6 -> V_24 ] , 0 ,
sizeof( * V_6 -> V_7 ) * ( V_150 - V_6 -> V_24 ) ) ;
V_6 -> V_24 = V_150 ;
}
if ( V_6 -> V_7 [ V_38 ] . V_6 )
return V_6 -> V_7 [ V_38 ] . V_6 ;
V_146 = V_26 -> V_21 -> V_42 ( V_26 ) ;
if ( ! V_146 )
return F_22 ( - V_18 ) ;
F_76 ( V_26 ) ;
V_6 -> V_7 [ V_38 ] . V_6 = V_146 ;
V_6 -> V_7 [ V_38 ] . V_27 = V_26 ;
V_146 -> V_6 = V_6 ;
F_8 ( L_46 ,
V_26 -> V_43 . V_44 , V_146 , V_6 ) ;
if ( V_146 -> V_30 ) {
struct V_36 * V_39 ;
V_39 = F_17 ( V_6 ,
V_146 -> V_30 ) ;
if ( F_29 ( V_39 ) )
return F_50 ( V_39 ) ;
}
return V_146 ;
}
int F_77 ( struct V_25 * V_26 ,
struct V_145 * V_6 , struct V_64 * V_65 ,
T_3 V_66 )
{
struct V_10 * V_11 = V_26 -> V_11 ;
struct V_19 * V_20 = & V_11 -> V_13 ;
if ( V_65 == V_20 -> V_101 ) {
struct V_29 * V_30 = F_57 ( V_11 , V_66 ) ;
return F_78 ( V_6 , V_30 ) ;
} else if ( V_65 == V_20 -> V_151 ) {
return - V_58 ;
} else if ( V_65 == V_20 -> V_152 ) {
V_6 -> V_153 . V_154 = V_66 ;
} else if ( V_65 == V_20 -> V_155 ) {
V_6 -> V_153 . V_156 . V_157 = V_66 ;
} else if ( V_65 == V_20 -> V_158 ) {
V_6 -> V_153 . V_156 . V_159 = V_66 ;
} else if ( V_65 == V_20 -> V_160 ) {
V_6 -> V_153 . V_156 . V_161 = V_66 ;
} else if ( V_65 == V_20 -> V_162 ) {
V_6 -> V_153 . V_156 . V_163 = V_66 ;
} else if ( V_65 == V_20 -> V_164 ) {
V_6 -> V_153 . V_49 = V_66 ;
} else if ( V_65 == V_20 -> V_165 ) {
V_6 -> V_153 . V_166 = V_66 ;
} else if ( V_65 == V_20 -> V_167 ) {
V_6 -> V_153 . V_168 = V_66 ;
} else if ( V_65 == V_20 -> V_169 ) {
V_6 -> V_153 . V_170 = V_66 ;
} else if ( V_65 == V_20 -> V_171 ) {
V_6 -> V_153 . V_172 = V_66 ;
} else if ( V_65 == V_20 -> V_173 ) {
V_6 -> V_153 . V_174 = V_66 ;
} else if ( V_65 == V_20 -> V_175 ) {
V_6 -> V_153 . V_176 = V_66 ;
} else if ( V_26 -> V_21 -> V_80 ) {
return V_26 -> V_21 -> V_80 ( V_26 ,
V_6 , V_65 , V_66 ) ;
} else {
return - V_58 ;
}
return 0 ;
}
static void F_79 ( struct V_83 * V_84 ,
const struct V_145 * V_6 )
{
struct V_25 * V_26 = V_6 -> V_26 ;
F_45 ( V_84 , L_47 , V_26 -> V_43 . V_44 , V_26 -> V_45 ) ;
F_45 ( V_84 , L_34 , V_6 -> V_30 ? V_6 -> V_30 -> V_45 : L_35 ) ;
if ( V_26 -> V_21 -> V_93 )
V_26 -> V_21 -> V_93 ( V_84 , V_6 ) ;
}
static int
F_80 ( struct V_25 * V_26 ,
const struct V_145 * V_6 ,
struct V_64 * V_65 , T_3 * V_66 )
{
struct V_10 * V_11 = V_26 -> V_11 ;
struct V_19 * V_20 = & V_11 -> V_13 ;
if ( V_65 == V_20 -> V_101 ) {
* V_66 = ( V_6 -> V_30 ) ? V_6 -> V_30 -> V_43 . V_44 : 0 ;
} else if ( V_65 == V_20 -> V_151 ) {
* V_66 = V_26 -> V_177 ;
} else if ( V_65 == V_20 -> V_152 ) {
* V_66 = V_6 -> V_153 . V_154 ;
} else if ( V_65 == V_20 -> V_155 ) {
* V_66 = V_6 -> V_153 . V_156 . V_157 ;
} else if ( V_65 == V_20 -> V_158 ) {
* V_66 = V_6 -> V_153 . V_156 . V_159 ;
} else if ( V_65 == V_20 -> V_160 ) {
* V_66 = V_6 -> V_153 . V_156 . V_161 ;
} else if ( V_65 == V_20 -> V_162 ) {
* V_66 = V_6 -> V_153 . V_156 . V_163 ;
} else if ( V_65 == V_20 -> V_164 ) {
* V_66 = V_6 -> V_153 . V_49 ;
} else if ( V_65 == V_20 -> V_165 ) {
* V_66 = V_6 -> V_153 . V_166 ;
} else if ( V_65 == V_20 -> V_167 ) {
* V_66 = V_6 -> V_153 . V_168 ;
} else if ( V_65 == V_20 -> V_169 ) {
* V_66 = V_6 -> V_153 . V_170 ;
} else if ( V_65 == V_20 -> V_171 ) {
* V_66 = V_6 -> V_153 . V_172 ;
} else if ( V_65 == V_20 -> V_173 ) {
* V_66 = V_6 -> V_153 . V_174 ;
} else if ( V_65 == V_20 -> V_175 ) {
* V_66 = V_6 -> V_153 . V_176 ;
} else if ( V_26 -> V_21 -> V_81 ) {
return V_26 -> V_21 -> V_81 ( V_26 ,
V_6 , V_65 , V_66 ) ;
} else {
return - V_58 ;
}
return 0 ;
}
int F_81 ( struct V_178 * V_179 ,
struct V_64 * V_65 , T_3 * V_66 )
{
struct V_10 * V_11 = V_65 -> V_11 ;
int V_37 ;
switch ( V_179 -> type ) {
case V_180 : {
struct V_25 * V_26 = F_82 ( V_179 ) ;
F_19 ( ! F_83 ( & V_11 -> V_13 . V_147 ) ) ;
V_37 = F_80 ( V_26 ,
V_26 -> V_6 , V_65 , V_66 ) ;
break;
}
case V_181 : {
struct V_29 * V_30 = F_84 ( V_179 ) ;
F_19 ( ! F_83 ( & V_30 -> V_41 ) ) ;
V_37 = F_41 ( V_30 ,
V_30 -> V_6 , V_65 , V_66 ) ;
break;
}
case V_182 : {
struct V_32 * V_33 = F_85 ( V_179 ) ;
F_19 ( ! F_83 ( & V_33 -> V_41 ) ) ;
V_37 = F_60 ( V_33 ,
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
F_58 ( struct V_94 * V_95 ,
struct V_29 * V_30 )
{
struct V_32 * V_33 = V_95 -> V_33 ;
struct V_36 * V_39 ;
if ( V_95 -> V_30 ) {
V_39 = F_17 ( V_95 -> V_6 ,
V_95 -> V_30 ) ;
if ( F_19 ( F_29 ( V_39 ) ) )
return F_30 ( V_39 ) ;
V_39 -> V_89 &= ~ ( 1 << F_48 ( V_33 ) ) ;
}
V_95 -> V_30 = V_30 ;
if ( V_30 ) {
V_39 = F_17 ( V_95 -> V_6 ,
V_30 ) ;
if ( F_29 ( V_39 ) )
return F_30 ( V_39 ) ;
V_39 -> V_89 |= ( 1 << F_48 ( V_33 ) ) ;
}
if ( V_30 )
F_8 ( L_48 ,
V_95 , V_30 -> V_43 . V_44 , V_30 -> V_45 ) ;
else
F_8 ( L_49 ,
V_95 ) ;
return 0 ;
}
void
F_53 ( struct V_94 * V_95 ,
struct V_97 * V_98 )
{
if ( V_98 )
F_8 ( L_50 ,
V_98 -> V_43 . V_44 , V_95 ) ;
else
F_8 ( L_51 ,
V_95 ) ;
F_86 ( & V_95 -> V_98 , V_98 ) ;
}
void
F_87 ( struct V_94 * V_95 ,
struct V_183 * V_100 )
{
if ( V_95 -> V_100 ) {
F_88 ( V_100 ) ;
return;
}
V_95 -> V_100 = V_100 ;
}
int
F_78 ( struct V_145 * V_184 ,
struct V_29 * V_30 )
{
struct V_36 * V_39 ;
if ( V_184 -> V_30 == V_30 )
return 0 ;
if ( V_184 -> V_30 ) {
V_39 = F_20 ( V_184 -> V_6 ,
V_184 -> V_30 ) ;
V_39 -> V_90 &=
~ ( 1 << F_73 ( V_184 -> V_26 ) ) ;
F_12 ( V_184 -> V_26 ) ;
V_184 -> V_30 = NULL ;
}
if ( V_30 ) {
V_39 = F_17 ( V_184 -> V_6 , V_30 ) ;
if ( F_29 ( V_39 ) )
return F_30 ( V_39 ) ;
V_39 -> V_90 |=
1 << F_73 ( V_184 -> V_26 ) ;
F_76 ( V_184 -> V_26 ) ;
V_184 -> V_30 = V_30 ;
F_8 ( L_52 ,
V_184 , V_30 -> V_43 . V_44 , V_30 -> V_45 ) ;
} else {
F_8 ( L_53 ,
V_184 ) ;
}
return 0 ;
}
int
F_89 ( struct V_5 * V_6 ,
struct V_29 * V_30 )
{
struct V_19 * V_20 = & V_6 -> V_11 -> V_13 ;
struct V_25 * V_26 ;
struct V_145 * V_184 ;
struct V_185 V_186 ;
int V_37 ;
V_37 = F_21 ( & V_20 -> V_147 , V_6 -> V_40 ) ;
if ( V_37 )
return V_37 ;
F_8 ( L_54 ,
V_30 -> V_43 . V_44 , V_30 -> V_45 , V_6 ) ;
F_90 ( V_6 -> V_11 , & V_186 ) ;
F_91 (connector, &conn_iter) {
if ( V_26 -> V_6 -> V_30 != V_30 )
continue;
V_184 = F_72 ( V_6 , V_26 ) ;
if ( F_29 ( V_184 ) ) {
F_92 ( & V_186 ) ;
return F_30 ( V_184 ) ;
}
}
F_92 ( & V_186 ) ;
return 0 ;
}
int
F_93 ( struct V_5 * V_6 ,
struct V_29 * V_30 )
{
struct V_32 * V_33 ;
F_19 ( ! F_20 ( V_6 , V_30 ) ) ;
F_94 (plane, state->dev, crtc->state->plane_mask) {
struct V_94 * V_95 =
F_47 ( V_6 , V_33 ) ;
if ( F_29 ( V_95 ) )
return F_30 ( V_95 ) ;
}
return 0 ;
}
void F_95 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
unsigned V_187 = 0 ;
struct V_29 * V_30 ;
int V_37 ;
bool V_188 = false ;
F_96 (crtc, dev) {
if ( V_30 -> V_40 != V_6 -> V_40 )
continue;
V_187 |= F_64 ( V_30 ) ;
V_30 -> V_40 = NULL ;
}
if ( F_19 ( V_11 -> V_13 . V_40 == V_6 -> V_40 ) ) {
V_188 = true ;
V_11 -> V_13 . V_40 = NULL ;
}
V_189:
F_97 ( V_6 -> V_40 ) ;
V_37 = F_98 ( V_11 , V_6 -> V_40 ) ;
if ( V_37 )
goto V_189;
F_96 (crtc, dev)
if ( F_64 ( V_30 ) & V_187 )
V_30 -> V_40 = V_6 -> V_40 ;
if ( V_188 )
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
F_8 ( L_55 , V_6 ) ;
F_100 (state, plane, plane_state, i) {
V_37 = F_63 ( V_33 , V_95 ) ;
if ( V_37 ) {
F_8 ( L_56 ,
V_33 -> V_43 . V_44 , V_33 -> V_45 ) ;
return V_37 ;
}
}
F_101 (state, crtc, crtc_state, i) {
V_37 = F_42 ( V_30 , V_39 ) ;
if ( V_37 ) {
F_8 ( L_57 ,
V_30 -> V_43 . V_44 , V_30 -> V_45 ) ;
return V_37 ;
}
}
if ( V_20 -> V_21 -> V_190 )
V_37 = V_20 -> V_21 -> V_190 ( V_6 -> V_11 , V_6 ) ;
if ( ! V_6 -> V_12 ) {
F_101 (state, crtc, crtc_state, i) {
if ( F_102 ( V_39 ) ) {
F_8 ( L_58 ,
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
F_8 ( L_59 , V_6 ) ;
return V_20 -> V_21 -> V_191 ( V_6 -> V_11 , V_6 , false ) ;
}
int F_104 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = & V_6 -> V_11 -> V_13 ;
int V_37 ;
V_37 = F_99 ( V_6 ) ;
if ( V_37 )
return V_37 ;
F_8 ( L_60 , V_6 ) ;
return V_20 -> V_21 -> V_191 ( V_6 -> V_11 , V_6 , true ) ;
}
static void F_105 ( const struct V_5 * V_6 )
{
struct V_83 V_84 = F_106 ( V_6 -> V_11 -> V_11 ) ;
struct V_32 * V_33 ;
struct V_94 * V_95 ;
struct V_29 * V_30 ;
struct V_36 * V_39 ;
struct V_25 * V_26 ;
struct V_145 * V_146 ;
int V_23 ;
F_8 ( L_55 , V_6 ) ;
F_100 (state, plane, plane_state, i)
F_67 ( & V_84 , V_95 ) ;
F_101 (state, crtc, crtc_state, i)
F_44 ( & V_84 , V_39 ) ;
F_107 (state, connector, connector_state, i)
F_79 ( & V_84 , V_146 ) ;
}
void F_108 ( struct V_10 * V_11 , struct V_83 * V_84 )
{
struct V_19 * V_20 = & V_11 -> V_13 ;
struct V_32 * V_33 ;
struct V_29 * V_30 ;
struct V_25 * V_26 ;
struct V_185 V_186 ;
if ( ! F_43 ( V_11 , V_82 ) )
return;
F_109 (plane, &config->plane_list, head)
F_67 ( V_84 , V_33 -> V_6 ) ;
F_109 (crtc, &config->crtc_list, head)
F_44 ( V_84 , V_30 -> V_6 ) ;
F_90 ( V_11 , & V_186 ) ;
F_91 (connector, &conn_iter)
F_79 ( V_84 , V_26 -> V_6 ) ;
F_92 ( & V_186 ) ;
}
static int F_110 ( struct V_192 * V_193 , void * V_57 )
{
struct V_194 * V_195 = (struct V_194 * ) V_193 -> V_196 ;
struct V_10 * V_11 = V_195 -> V_197 -> V_11 ;
struct V_83 V_84 = F_111 ( V_193 ) ;
F_112 ( V_11 ) ;
F_108 ( V_11 , & V_84 ) ;
F_113 ( V_11 ) ;
return 0 ;
}
int F_114 ( struct V_198 * V_197 )
{
return F_115 ( V_199 ,
F_116 ( V_199 ) ,
V_197 -> V_200 , V_197 ) ;
}
static struct V_201 * F_117 (
struct V_10 * V_11 , T_3 V_202 )
{
struct V_201 * V_203 = NULL ;
V_203 = F_10 ( sizeof *V_203 , V_15 ) ;
if ( ! V_203 )
return NULL ;
V_203 -> V_31 . V_43 . type = V_204 ;
V_203 -> V_31 . V_43 . V_56 = sizeof( V_203 -> V_31 ) ;
V_203 -> V_31 . V_202 = V_202 ;
return V_203 ;
}
static int F_118 ( struct V_5 * V_6 ,
struct V_178 * V_179 , struct V_64 * V_205 ,
T_3 V_206 )
{
struct V_178 * V_4 ;
int V_37 ;
if ( ! F_119 ( V_205 , V_206 , & V_4 ) )
return - V_58 ;
switch ( V_179 -> type ) {
case V_180 : {
struct V_25 * V_26 = F_82 ( V_179 ) ;
struct V_145 * V_146 ;
V_146 = F_72 ( V_6 , V_26 ) ;
if ( F_29 ( V_146 ) ) {
V_37 = F_30 ( V_146 ) ;
break;
}
V_37 = F_77 ( V_26 ,
V_146 , V_205 , V_206 ) ;
break;
}
case V_181 : {
struct V_29 * V_30 = F_84 ( V_179 ) ;
struct V_36 * V_39 ;
V_39 = F_17 ( V_6 , V_30 ) ;
if ( F_29 ( V_39 ) ) {
V_37 = F_30 ( V_39 ) ;
break;
}
V_37 = F_38 ( V_30 ,
V_39 , V_205 , V_206 ) ;
break;
}
case V_182 : {
struct V_32 * V_33 = F_85 ( V_179 ) ;
struct V_94 * V_95 ;
V_95 = F_47 ( V_6 , V_33 ) ;
if ( F_29 ( V_95 ) ) {
V_37 = F_30 ( V_95 ) ;
break;
}
V_37 = F_51 ( V_33 ,
V_95 , V_205 , V_206 ) ;
break;
}
default:
V_37 = - V_58 ;
break;
}
F_120 ( V_205 , V_4 ) ;
return V_37 ;
}
void F_121 ( struct V_10 * V_11 ,
unsigned V_89 ,
int V_37 )
{
struct V_32 * V_33 ;
F_94 (plane, dev, plane_mask) {
if ( V_37 == 0 ) {
struct V_97 * V_207 = V_33 -> V_6 -> V_98 ;
if ( V_207 )
F_122 ( V_207 ) ;
V_33 -> V_98 = V_207 ;
V_33 -> V_30 = V_33 -> V_6 -> V_30 ;
if ( V_33 -> V_208 )
F_54 ( V_33 -> V_208 ) ;
}
V_33 -> V_208 = NULL ;
}
}
static int F_123 ( struct V_209 * V_210 ,
struct V_183 * V_100 )
{
V_210 -> V_211 = F_124 ( V_212 ) ;
if ( V_210 -> V_211 < 0 )
return V_210 -> V_211 ;
if ( F_40 ( V_210 -> V_211 , V_210 -> V_47 ) )
return - V_79 ;
V_210 -> V_213 = F_125 ( V_100 ) ;
if ( ! V_210 -> V_213 )
return - V_18 ;
return 0 ;
}
static int F_126 ( struct V_10 * V_11 ,
struct V_5 * V_6 ,
struct V_214 * V_215 ,
struct V_216 * V_217 ,
struct V_209 * * V_210 ,
unsigned int * V_218 )
{
struct V_29 * V_30 ;
struct V_36 * V_39 ;
int V_23 , V_37 ;
if ( V_215 -> V_219 & V_220 )
return 0 ;
F_101 (state, crtc, crtc_state, i) {
T_1 T_2 * V_46 ;
V_46 = F_24 ( V_39 -> V_6 , V_30 ) ;
if ( V_215 -> V_219 & V_221 || V_46 ) {
struct V_201 * V_203 ;
V_203 = F_117 ( V_11 , V_215 -> V_202 ) ;
if ( ! V_203 )
return - V_18 ;
V_39 -> V_31 = V_203 ;
}
if ( V_215 -> V_219 & V_221 ) {
struct V_201 * V_203 = V_39 -> V_31 ;
if ( ! V_217 )
continue;
V_37 = F_127 ( V_11 , V_217 , & V_203 -> V_43 ,
& V_203 -> V_31 . V_43 ) ;
if ( V_37 ) {
F_3 ( V_203 ) ;
V_39 -> V_31 = NULL ;
return V_37 ;
}
}
if ( V_46 ) {
struct V_183 * V_100 ;
struct V_209 * V_222 ;
V_222 = F_75 ( * V_210 , sizeof( * * V_210 ) *
( * V_218 + 1 ) , V_15 ) ;
if ( ! V_222 )
return - V_18 ;
memset ( & V_222 [ * V_218 ] , 0 , sizeof( * V_222 ) ) ;
V_222 [ * V_218 ] . V_47 = V_46 ;
* V_210 = V_222 ;
V_100 = F_128 ( V_30 ) ;
if ( ! V_100 )
return - V_18 ;
V_37 = F_123 ( & V_222 [ ( * V_218 ) ++ ] , V_100 ) ;
if ( V_37 ) {
F_88 ( V_100 ) ;
return V_37 ;
}
V_39 -> V_31 -> V_43 . V_100 = V_100 ;
}
}
return 0 ;
}
static void F_129 ( struct V_10 * V_11 ,
struct V_5 * V_6 ,
struct V_209 * V_210 ,
unsigned int V_218 ,
bool V_223 )
{
struct V_29 * V_30 ;
struct V_36 * V_39 ;
int V_23 ;
if ( V_223 ) {
for ( V_23 = 0 ; V_23 < V_218 ; V_23 ++ )
F_130 ( V_210 [ V_23 ] . V_211 ,
V_210 [ V_23 ] . V_213 -> V_224 ) ;
F_3 ( V_210 ) ;
return;
}
F_101 (state, crtc, crtc_state, i) {
struct V_201 * V_31 = V_39 -> V_31 ;
if ( V_31 && ( V_31 -> V_43 . V_100 || V_31 -> V_43 . V_217 ) ) {
F_131 ( V_11 , & V_31 -> V_43 ) ;
V_39 -> V_31 = NULL ;
}
}
if ( ! V_210 )
return;
for ( V_23 = 0 ; V_23 < V_218 ; V_23 ++ ) {
if ( V_210 [ V_23 ] . V_213 )
F_132 ( V_210 [ V_23 ] . V_213 -> V_224 ) ;
if ( V_210 [ V_23 ] . V_211 >= 0 )
F_133 ( V_210 [ V_23 ] . V_211 ) ;
if ( V_210 [ V_23 ] . V_47 &&
F_40 ( - 1 , V_210 [ V_23 ] . V_47 ) )
F_8 ( L_61 ) ;
}
F_3 ( V_210 ) ;
}
int F_134 ( struct V_10 * V_11 ,
void * V_57 , struct V_216 * V_217 )
{
struct V_214 * V_215 = V_57 ;
T_5 T_2 * V_225 = ( T_5 T_2 * ) ( unsigned long ) ( V_215 -> V_225 ) ;
T_5 T_2 * V_226 = ( T_5 T_2 * ) ( unsigned long ) ( V_215 -> V_226 ) ;
T_5 T_2 * V_227 = ( T_5 T_2 * ) ( unsigned long ) ( V_215 -> V_227 ) ;
T_3 T_2 * V_228 = ( T_3 T_2 * ) ( unsigned long ) ( V_215 -> V_228 ) ;
unsigned int V_229 , V_230 ;
struct V_5 * V_6 ;
struct V_231 V_232 ;
struct V_32 * V_33 ;
struct V_209 * V_210 = NULL ;
unsigned V_89 ;
int V_37 = 0 ;
unsigned int V_23 , V_233 , V_218 = 0 ;
if ( ! F_43 ( V_11 , V_82 ) )
return - V_58 ;
if ( ! V_217 -> V_234 )
return - V_58 ;
if ( V_215 -> V_219 & ~ V_235 )
return - V_58 ;
if ( V_215 -> V_236 )
return - V_58 ;
if ( ( V_215 -> V_219 & V_237 ) &&
! V_11 -> V_13 . V_238 )
return - V_58 ;
if ( ( V_215 -> V_219 & V_220 ) &&
( V_215 -> V_219 & V_221 ) )
return - V_58 ;
F_135 ( & V_232 , 0 ) ;
V_6 = F_9 ( V_11 ) ;
if ( ! V_6 )
return - V_18 ;
V_6 -> V_40 = & V_232 ;
V_6 -> V_12 = ! ! ( V_215 -> V_219 & V_239 ) ;
V_189:
V_89 = 0 ;
V_229 = 0 ;
V_230 = 0 ;
for ( V_23 = 0 ; V_23 < V_215 -> V_240 ; V_23 ++ ) {
T_5 V_241 , V_242 ;
struct V_178 * V_179 ;
if ( F_136 ( V_241 , V_225 + V_229 ) ) {
V_37 = - V_79 ;
goto V_243;
}
V_179 = F_137 ( V_11 , V_241 , V_244 ) ;
if ( ! V_179 ) {
V_37 = - V_245 ;
goto V_243;
}
if ( ! V_179 -> V_246 ) {
F_138 ( V_179 ) ;
V_37 = - V_245 ;
goto V_243;
}
if ( F_136 ( V_242 , V_226 + V_229 ) ) {
F_138 ( V_179 ) ;
V_37 = - V_79 ;
goto V_243;
}
V_229 ++ ;
for ( V_233 = 0 ; V_233 < V_242 ; V_233 ++ ) {
T_5 V_247 ;
T_3 V_206 ;
struct V_64 * V_205 ;
if ( F_136 ( V_247 , V_227 + V_230 ) ) {
F_138 ( V_179 ) ;
V_37 = - V_79 ;
goto V_243;
}
V_205 = F_139 ( V_179 , V_247 ) ;
if ( ! V_205 ) {
F_138 ( V_179 ) ;
V_37 = - V_245 ;
goto V_243;
}
if ( F_140 ( & V_206 ,
V_228 + V_230 ,
sizeof( V_206 ) ) ) {
F_138 ( V_179 ) ;
V_37 = - V_79 ;
goto V_243;
}
V_37 = F_118 ( V_6 , V_179 , V_205 , V_206 ) ;
if ( V_37 ) {
F_138 ( V_179 ) ;
goto V_243;
}
V_230 ++ ;
}
if ( V_179 -> type == V_182 && V_242 &&
! ( V_215 -> V_219 & V_220 ) ) {
V_33 = F_85 ( V_179 ) ;
V_89 |= ( 1 << F_48 ( V_33 ) ) ;
V_33 -> V_208 = V_33 -> V_98 ;
}
F_138 ( V_179 ) ;
}
V_37 = F_126 ( V_11 , V_6 , V_215 , V_217 , & V_210 ,
& V_218 ) ;
if ( V_37 )
goto V_243;
if ( V_215 -> V_219 & V_220 ) {
V_37 = F_99 ( V_6 ) ;
} else if ( V_215 -> V_219 & V_248 ) {
V_37 = F_104 ( V_6 ) ;
} else {
if ( F_141 ( V_249 & V_250 ) )
F_105 ( V_6 ) ;
V_37 = F_103 ( V_6 ) ;
}
V_243:
F_121 ( V_11 , V_89 , V_37 ) ;
F_129 ( V_11 , V_6 , V_210 , V_218 , ! V_37 ) ;
if ( V_37 == - V_251 ) {
F_14 ( V_6 ) ;
F_97 ( & V_232 ) ;
goto V_189;
}
F_142 ( V_6 ) ;
F_143 ( & V_232 ) ;
F_144 ( & V_232 ) ;
return V_37 ;
}
