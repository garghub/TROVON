static int F_1 ( T_1 V_1 )
{
int V_2 , V_3 = - V_4 ;
struct V_5 * V_6 = V_7 -> V_8 ;
struct V_9 * V_10 =
(struct V_9 * ) V_11 ;
T_2 V_12 = V_6 -> V_13 ;
F_2 ( V_14 ) ;
F_3 ( V_1 , & V_10 -> V_15 ) ;
F_3 ( 0 , & V_10 -> V_16 ) ;
V_3 = F_4 ( V_7 , & V_1 ) ;
if ( V_3 < 0 ) {
F_5 ( L_1 ,
V_1 , V_3 ) ;
return V_3 ;
}
F_2 ( V_12 ) ;
for ( V_2 = V_17 ; V_2 > 0 ; V_2 -- ) {
if ( F_6 ( & V_10 -> V_16 ) & V_18 ) {
V_3 = 0 ;
break;
}
}
F_7 ( V_7 , V_3 ) ;
return V_3 ;
}
static void F_8 ( struct V_19 * V_20 , void * V_21 , int V_22 )
{
if ( V_22 )
F_9 ( L_2 ,
* ( T_1 * ) V_21 , V_22 ) ;
else
F_9 ( L_3 ,
* ( T_1 * ) V_21 , V_22 ) ;
}
static int F_10 ( struct V_23 * V_24 , T_3 V_25 )
{
int V_3 = - V_26 ;
T_4 V_16 = V_27 ;
struct V_28 V_29 = { V_30 , NULL } ;
struct V_28 V_31 = { sizeof( L_4 ) , L_4 } ;
struct V_28 V_32 = { 0 , NULL } ;
union V_33 * V_34 = NULL ;
struct V_35 * V_36 ;
V_16 = F_11 ( V_25 , L_5 , NULL , & V_29 ,
V_37 ) ;
if ( F_12 ( V_16 ) )
return - V_38 ;
V_34 = V_29 . V_39 ;
if ( ! V_34 || V_34 -> V_40 . V_41 != 1 ) {
F_9 ( L_6 ) ;
goto V_42;
}
V_36 = & ( V_24 -> V_43 ) ;
V_32 . V_44 = sizeof( struct V_35 ) ;
V_32 . V_39 = V_36 ;
V_16 = F_13 ( & ( V_34 -> V_40 . V_45 [ 0 ] ) ,
& V_31 , & V_32 ) ;
if ( F_12 ( V_16 ) ) {
F_9 ( L_7 , V_24 -> V_46 ) ;
goto V_42;
}
if ( V_36 -> V_47 != V_48 ) {
F_9 ( L_8 , V_24 -> V_46 ) ;
goto V_42;
}
if ( V_36 -> V_49 != V_50 ) {
F_9 ( L_9 , V_24 -> V_46 ) ;
goto V_42;
}
if ( V_36 -> V_51 != V_52 &&
V_36 -> V_51 != V_53 &&
V_36 -> V_51 != V_54 ) {
F_9 ( L_10 , V_24 -> V_46 ) ;
goto V_42;
}
V_3 = 0 ;
V_42:
F_14 ( V_29 . V_39 ) ;
return V_3 ;
}
int F_15 ( struct V_55 * * V_56 )
{
int V_57 ;
int V_58 = 0 ;
unsigned int V_59 , V_60 ;
T_5 V_61 ;
struct V_55 * V_62 , * V_63 ;
struct V_35 * V_36 ;
struct V_35 * V_64 ;
struct V_23 * V_24 , * V_65 ;
if ( ! F_16 ( & V_61 , V_66 ) )
return - V_67 ;
F_17 (i) {
V_62 = V_56 [ V_59 ] ;
if ( ! V_62 )
continue;
if ( F_18 ( V_59 , V_61 ) )
continue;
V_24 = F_19 ( V_68 , V_59 ) ;
if ( ! V_24 )
continue;
V_36 = & ( V_24 -> V_43 ) ;
F_20 ( V_59 , V_62 -> V_69 ) ;
F_20 ( V_59 , V_61 ) ;
if ( V_36 -> V_70 <= 1 )
continue;
V_57 = V_36 -> V_70 ;
if ( V_36 -> V_51 == V_52 )
V_62 -> V_71 = V_72 ;
else if ( V_36 -> V_51 == V_54 )
V_62 -> V_71 = V_73 ;
else if ( V_36 -> V_51 == V_53 )
V_62 -> V_71 = V_74 ;
F_17 (j) {
if ( V_59 == V_60 )
continue;
V_65 = F_19 ( V_68 , V_60 ) ;
if ( ! V_65 )
continue;
V_64 = & ( V_65 -> V_43 ) ;
if ( V_64 -> V_75 != V_36 -> V_75 )
continue;
if ( V_64 -> V_70 != V_57 ) {
V_58 = - V_26 ;
goto V_76;
}
if ( V_36 -> V_51 != V_64 -> V_51 ) {
V_58 = - V_26 ;
goto V_76;
}
F_20 ( V_60 , V_61 ) ;
F_20 ( V_60 , V_62 -> V_69 ) ;
}
F_17 (j) {
if ( V_59 == V_60 )
continue;
V_63 = V_56 [ V_60 ] ;
if ( ! V_63 )
continue;
V_65 = F_19 ( V_68 , V_60 ) ;
if ( ! V_65 )
continue;
V_64 = & ( V_65 -> V_43 ) ;
if ( V_64 -> V_75 != V_36 -> V_75 )
continue;
V_63 -> V_71 = V_62 -> V_71 ;
F_21 ( V_63 -> V_69 ,
V_62 -> V_69 ) ;
}
}
V_76:
F_17 (i) {
V_62 = V_56 [ V_59 ] ;
if ( ! V_62 )
continue;
if ( V_58 ) {
F_22 ( V_62 -> V_69 ) ;
F_20 ( V_59 , V_62 -> V_69 ) ;
V_62 -> V_71 = V_72 ;
}
}
F_23 ( V_61 ) ;
return V_58 ;
}
static int F_24 ( int V_77 )
{
struct V_5 * V_78 ;
unsigned int V_79 ;
if ( V_77 >= 0 ) {
V_7 = F_25 ( & V_80 ,
V_77 ) ;
if ( F_26 ( V_7 ) ) {
F_5 ( L_11 ) ;
return - V_38 ;
}
V_78 = V_7 -> V_8 ;
if ( ! V_78 ) {
F_5 ( L_12 ) ;
return - V_38 ;
}
V_81 = V_78 -> V_82 ;
V_79 = V_78 -> V_44 ;
V_14 = V_78 -> V_83 ;
V_11 = F_27 ( V_81 , V_79 ) ;
if ( ! V_11 ) {
F_5 ( L_13 ) ;
return - V_67 ;
}
V_84 = true ;
}
return 0 ;
}
int F_28 ( struct V_85 * V_62 )
{
struct V_28 V_86 = { V_30 , NULL } ;
union V_33 * V_87 , * V_88 ;
struct V_23 * V_24 ;
struct V_89 * V_90 ;
T_3 V_25 = V_62 -> V_25 ;
unsigned int V_91 , V_59 , V_92 ;
T_4 V_16 ;
int V_22 = - V_26 ;
V_16 = F_11 ( V_25 , L_14 , NULL , & V_86 ,
V_37 ) ;
if ( F_12 ( V_16 ) ) {
V_22 = - V_38 ;
goto V_93;
}
V_87 = (union V_33 * ) V_86 . V_39 ;
V_24 = F_29 ( sizeof( struct V_23 ) , V_66 ) ;
if ( ! V_24 ) {
V_22 = - V_67 ;
goto V_93;
}
V_88 = & V_87 -> V_40 . V_45 [ 0 ] ;
if ( V_88 -> type == V_94 ) {
V_91 = V_88 -> integer . V_95 ;
} else {
F_9 ( L_15 ,
V_88 -> type ) ;
goto V_96;
}
if ( V_91 != V_97 ) {
F_9 ( L_16 ,
V_91 , V_97 ) ;
goto V_96;
}
V_88 = & V_87 -> V_40 . V_45 [ 1 ] ;
if ( V_88 -> type == V_94 ) {
V_92 = V_88 -> integer . V_95 ;
} else {
F_9 ( L_17 ,
V_88 -> type ) ;
goto V_96;
}
if ( V_92 != V_98 ) {
F_9 ( L_18 ,
V_92 , V_98 ) ;
goto V_96;
}
for ( V_59 = 2 ; V_59 < V_91 ; V_59 ++ ) {
V_88 = & V_87 -> V_40 . V_45 [ V_59 ] ;
if ( V_88 -> type == V_94 ) {
V_24 -> V_99 [ V_59 - 2 ] . type = V_94 ;
V_24 -> V_99 [ V_59 - 2 ] . V_100 . V_101 = V_88 -> integer . V_95 ;
} else if ( V_88 -> type == V_102 ) {
V_90 = (struct V_89 * )
V_88 -> V_29 . V_39 ;
if ( V_90 -> V_103 == V_104 ) {
if ( V_77 < 0 )
V_77 = V_90 -> V_105 ;
else if ( V_77 != V_90 -> V_105 ) {
F_9 ( L_19 ) ;
goto V_96;
}
} else if ( V_90 -> V_103 != V_106 ) {
F_9 ( L_20 , V_90 -> V_103 ) ;
goto V_96;
}
V_24 -> V_99 [ V_59 - 2 ] . type = V_102 ;
memcpy ( & V_24 -> V_99 [ V_59 - 2 ] . V_100 . V_107 , V_90 , sizeof( * V_90 ) ) ;
} else {
F_9 ( L_21 , V_59 , V_62 -> V_108 ) ;
goto V_96;
}
}
V_24 -> V_46 = V_62 -> V_108 ;
F_19 ( V_68 , V_62 -> V_108 ) = V_24 ;
V_22 = F_10 ( V_24 , V_25 ) ;
if ( V_22 )
goto V_96;
if ( ! V_84 ) {
V_22 = F_24 ( V_77 ) ;
if ( V_22 )
goto V_96;
}
F_9 ( L_22 , V_62 -> V_108 ) ;
F_14 ( V_86 . V_39 ) ;
return 0 ;
V_96:
F_14 ( V_24 ) ;
V_93:
F_14 ( V_86 . V_39 ) ;
return V_22 ;
}
void F_30 ( struct V_85 * V_62 )
{
struct V_23 * V_24 ;
V_24 = F_19 ( V_68 , V_62 -> V_108 ) ;
F_14 ( V_24 ) ;
}
static T_6 F_31 ( struct V_89 * V_107 )
{
if ( V_107 -> V_103 == V_104 )
return ( T_6 ) V_81 + 0x8 + V_107 -> V_109 ;
else
return V_107 -> V_109 ;
}
static void F_32 ( struct V_89 * V_107 , T_6 * V_110 )
{
T_6 V_111 = F_31 ( V_107 ) ;
F_33 ( ( V_112 ) V_111 ,
V_110 , V_107 -> V_113 ) ;
}
static void F_34 ( struct V_89 * V_107 , T_6 V_110 )
{
T_6 V_111 = F_31 ( V_107 ) ;
F_35 ( ( V_112 ) V_111 ,
V_110 , V_107 -> V_113 ) ;
}
int F_36 ( int V_114 , struct V_115 * V_116 )
{
struct V_23 * V_23 = F_19 ( V_68 , V_114 ) ;
struct V_117 * V_118 , * V_119 , * V_120 ,
* V_121 ;
T_6 V_122 , V_123 , V_124 , V_125 ;
int V_22 = 0 ;
if ( ! V_23 ) {
F_9 ( L_23 , V_114 ) ;
return - V_38 ;
}
V_118 = & V_23 -> V_99 [ V_126 ] ;
V_119 = & V_23 -> V_99 [ V_127 ] ;
V_120 = & V_23 -> V_99 [ V_128 ] ;
V_121 = & V_23 -> V_99 [ V_129 ] ;
F_37 ( & V_130 ) ;
if ( ( V_118 -> V_100 . V_107 . V_103 == V_104 ) ||
( V_119 -> V_100 . V_107 . V_103 == V_104 ) ||
( V_120 -> V_100 . V_107 . V_103 == V_104 ) ||
( V_121 -> V_100 . V_107 . V_103 == V_104 ) ) {
if ( F_1 ( V_131 ) ) {
V_22 = - V_4 ;
goto V_132;
}
}
F_32 ( & V_118 -> V_100 . V_107 , & V_122 ) ;
V_116 -> V_133 = V_122 ;
F_32 ( & V_119 -> V_100 . V_107 , & V_123 ) ;
V_116 -> V_134 = V_123 ;
F_32 ( & V_120 -> V_100 . V_107 , & V_124 ) ;
V_116 -> V_135 = V_124 ;
F_32 ( & V_121 -> V_100 . V_107 , & V_125 ) ;
V_116 -> V_136 = V_125 ;
if ( ! V_124 )
V_116 -> V_135 = V_116 -> V_136 ;
if ( ! V_122 || ! V_123 || ! V_125 )
V_22 = - V_26 ;
V_132:
F_38 ( & V_130 ) ;
return V_22 ;
}
int F_39 ( int V_114 , struct V_137 * V_138 )
{
struct V_23 * V_23 = F_19 ( V_68 , V_114 ) ;
struct V_117 * V_139 , * V_140 ;
T_6 V_141 , V_142 ;
int V_22 = 0 ;
if ( ! V_23 ) {
F_9 ( L_23 , V_114 ) ;
return - V_38 ;
}
V_139 = & V_23 -> V_99 [ V_143 ] ;
V_140 = & V_23 -> V_99 [ V_144 ] ;
F_37 ( & V_130 ) ;
if ( ( V_139 -> V_100 . V_107 . V_103 == V_104 ) ||
( V_140 -> V_100 . V_107 . V_103 == V_104 ) ) {
if ( F_1 ( V_131 ) ) {
V_22 = - V_4 ;
goto V_132;
}
}
F_32 ( & V_139 -> V_100 . V_107 , & V_141 ) ;
F_32 ( & V_140 -> V_100 . V_107 , & V_142 ) ;
if ( ! V_141 || ! V_142 ) {
V_22 = - V_26 ;
goto V_132;
}
V_138 -> V_141 = V_141 ;
V_138 -> V_142 = V_142 ;
V_138 -> V_141 -= V_138 -> V_145 ;
V_138 -> V_142 -= V_138 -> V_146 ;
V_138 -> V_145 = V_141 ;
V_138 -> V_146 = V_142 ;
V_132:
F_38 ( & V_130 ) ;
return V_22 ;
}
int F_40 ( int V_147 , struct V_148 * V_149 )
{
struct V_23 * V_23 = F_19 ( V_68 , V_147 ) ;
struct V_117 * V_150 ;
int V_22 = 0 ;
if ( ! V_23 ) {
F_9 ( L_23 , V_147 ) ;
return - V_38 ;
}
V_150 = & V_23 -> V_99 [ V_151 ] ;
F_37 ( & V_130 ) ;
F_34 ( & V_150 -> V_100 . V_107 , V_149 -> V_152 ) ;
if ( V_150 -> V_100 . V_107 . V_103 == V_104 ) {
if ( F_1 ( V_153 ) )
V_22 = - V_4 ;
}
F_38 ( & V_130 ) ;
return V_22 ;
}
