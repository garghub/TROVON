void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
if ( F_2 ( V_5 -> V_8 ,
& V_2 -> V_9 ,
F_3 ( V_3 ) ) )
F_4 ( & V_2 -> V_10 ) ;
}
static void F_5 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 , struct V_1 ,
V_9 . V_12 ) ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
T_1 V_17 = V_2 -> V_17 ;
struct V_18 * V_19 = V_2 -> V_19 ;
int V_20 ;
int V_21 ;
F_7 ( V_2 , L_1
L_2 , V_17 , V_2 -> V_22 ) ;
F_8 ( & V_19 -> V_23 ) ;
if ( F_9 ( V_24 , & V_2 -> V_22 ) ) {
F_10 ( V_25 , & V_2 -> V_22 ) ;
F_11 ( & V_19 -> V_23 ) ;
F_12 ( V_2 ) ;
return;
}
if ( F_9 ( V_25 , & V_2 -> V_22 ) ) {
F_7 ( V_2 , L_3 ) ;
goto V_26;
}
switch ( V_17 ) {
case V_27 :
if ( F_9 ( V_28 ,
& V_2 -> V_22 ) ) {
F_7 ( V_2 , L_4 ) ;
F_13 ( & V_2 -> V_29 ) ;
} else if ( F_14 ( V_30 ,
& V_2 -> V_22 ) ) {
F_7 ( V_2 , L_5 ,
V_2 -> V_10 . V_10 . V_31 ) ;
if ( ! ( F_15 ( V_32 ,
& V_2 -> V_22 ) ) ) {
V_14 = V_2 -> V_6 -> V_14 ;
V_16 = V_2 -> V_19 -> V_16 ;
V_20 = F_15 (
V_33 ,
& V_19 -> V_34 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
F_11 ( & V_19 -> V_23 ) ;
if ( ! V_20 ) {
F_7 ( V_2 , L_6
L_7 ,
V_19 -> V_34 ) ;
F_17 ( & V_14 -> V_36 . V_37 ) ;
V_14 -> V_38 . V_39 ( V_16 ) ;
F_18 ( & V_14 -> V_36 . V_37 ) ;
}
return;
}
} else {
F_7 ( V_2 , L_8 ) ;
if ( F_15 ( V_40 ,
& V_2 -> V_22 ) ) {
F_7 ( V_2 , L_9
L_10 ) ;
goto V_26;
}
if ( ! F_15 ( V_30 ,
& V_2 -> V_22 ) ) {
V_21 = F_19 ( V_2 ) ;
if ( V_21 == V_41 )
goto V_26;
V_14 = V_2 -> V_6 -> V_14 ;
V_16 = V_2 -> V_19 -> V_16 ;
V_20 = F_15 (
V_33 ,
& V_19 -> V_34 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
F_11 ( & V_19 -> V_23 ) ;
if ( ! V_20 ) {
F_7 ( V_2 , L_6
L_7 ,
V_19 -> V_34 ) ;
F_17 ( & V_14 -> V_36 . V_37 ) ;
V_14 -> V_38 . V_39 ( V_16 ) ;
F_18 ( & V_14 -> V_36 . V_37 ) ;
}
return;
} else {
F_7 ( V_2 , L_11
L_12 ) ;
}
}
break;
case V_42 :
if ( F_14 ( V_30 , & V_2 -> V_22 ) ) {
F_7 ( V_2 , L_13 ) ;
if ( ! F_15 ( V_32 ,
& V_2 -> V_22 ) ) {
V_14 = V_2 -> V_6 -> V_14 ;
V_16 = V_2 -> V_19 -> V_16 ;
V_20 = F_15 (
V_33 ,
& V_19 -> V_34 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
F_11 ( & V_19 -> V_23 ) ;
if ( ! V_20 ) {
F_7 ( V_2 , L_14
L_15 ) ;
F_17 ( & V_14 -> V_36 . V_37 ) ;
V_14 -> V_38 . V_39 ( V_16 ) ;
F_18 ( & V_14 -> V_36 . V_37 ) ;
}
return;
}
} else {
F_7 ( V_2 , L_16 ) ;
if ( F_15 ( V_43 ,
& V_2 -> V_22 ) )
goto V_26;
F_20 ( V_44 , & V_2 -> V_22 ) ;
if ( ( V_2 -> V_45 ) && ( V_2 -> V_46 ) ) {
V_2 -> V_45 ( V_2 -> V_46 ) ;
V_2 -> V_46 = NULL ;
}
}
break;
default:
F_21 (KERN_ERR PFX L_17 ,
cmd_type) ;
break;
}
V_26:
F_16 ( & V_2 -> V_10 , V_35 ) ;
F_11 ( & V_19 -> V_23 ) ;
}
static void F_22 ( struct V_1 * V_2 , int V_47 )
{
struct V_48 * V_49 = V_2 -> V_49 ;
if ( V_2 -> V_17 != V_27 )
return;
F_7 ( V_2 , L_18 , V_47 ) ;
if ( F_14 ( V_50 , & V_2 -> V_22 ) ) {
return;
}
F_23 ( V_2 ) ;
V_2 -> V_49 = NULL ;
if ( ! V_49 ) {
F_21 (KERN_ERR PFX L_19
L_20 ,
io_req->xid) ;
return;
}
V_49 -> V_51 = V_47 << 16 ;
F_7 ( V_2 , L_21 ,
V_49 , F_24 ( V_49 -> V_51 ) , V_49 -> V_52 ,
V_49 -> V_53 ) ;
F_25 ( V_49 , F_26 ( V_49 ) ) ;
V_49 -> V_54 . V_55 = NULL ;
V_49 -> V_56 ( V_49 ) ;
}
struct V_57 * F_27 ( struct V_58 * V_59 ,
T_2 V_60 , T_2 V_61 )
{
struct V_57 * V_62 ;
struct V_63 * V_64 ;
struct V_1 * V_2 ;
T_3 V_65 ;
T_4 V_66 ;
T_2 V_67 ;
int V_68 ;
int V_69 , V_70 ;
T_3 V_71 ;
int V_72 = F_28 () + 1 ;
if ( V_61 <= V_60 || V_61 == V_73 ) {
F_21 (KERN_ERR PFX L_22 , min_xid, max_xid) ;
return NULL ;
}
F_29 ( L_23 , V_60 , V_61 ) ;
V_69 = V_61 - V_60 + 1 ;
V_65 = ( V_69 * ( sizeof( struct V_1 * ) ) ) ;
V_65 += sizeof( struct V_57 ) ;
V_62 = F_30 ( V_65 , V_74 ) ;
if ( ! V_62 ) {
F_21 (KERN_ERR PFX L_24 ) ;
return NULL ;
}
V_62 -> V_75 = F_30 ( sizeof( * V_62 -> V_75 ) *
V_72 , V_74 ) ;
if ( ! V_62 -> V_75 ) {
F_21 (KERN_ERR PFX L_25 ) ;
goto V_76;
}
V_62 -> V_77 = F_30 ( sizeof( * V_62 -> V_77 ) *
V_72 , V_74 ) ;
if ( ! V_62 -> V_77 ) {
F_21 (KERN_ERR PFX L_26 ) ;
goto V_76;
}
V_62 -> V_59 = V_59 ;
V_62 -> V_78 = (struct V_1 * * ) ( V_62 + 1 ) ;
for ( V_68 = 0 ; V_68 < V_72 ; V_68 ++ ) {
F_31 ( & V_62 -> V_75 [ V_68 ] ) ;
F_32 ( & V_62 -> V_77 [ V_68 ] ) ;
}
V_67 = V_79 ;
V_70 = V_69 - V_80 ;
for ( V_68 = 0 ; V_68 < V_69 ; V_68 ++ ) {
V_2 = F_30 ( sizeof( * V_2 ) , V_74 ) ;
if ( ! V_2 ) {
F_21 (KERN_ERR PFX L_27 ) ;
goto V_76;
}
F_31 ( & V_2 -> V_81 ) ;
F_33 ( & V_2 -> V_9 , F_5 ) ;
V_2 -> V_67 = V_67 ++ ;
if ( V_68 < V_70 )
F_34 ( & V_2 -> V_81 ,
& V_62 -> V_75 [ V_2 -> V_67 %
F_28 () ] ) ;
else
F_34 ( & V_2 -> V_81 ,
& V_62 -> V_75 [ F_28 () ] ) ;
V_2 ++ ;
}
V_66 = V_69 * sizeof( struct V_63 * ) ;
V_62 -> V_82 = F_35 ( V_66 , V_74 ) ;
if ( ! V_62 -> V_82 ) {
F_21 (KERN_ERR PFX L_28 ) ;
goto V_76;
}
V_66 = sizeof( struct V_63 ) ;
for ( V_68 = 0 ; V_68 < V_69 ; V_68 ++ ) {
V_62 -> V_82 [ V_68 ] = F_35 ( V_66 , V_74 ) ;
if ( ! V_62 -> V_82 [ V_68 ] ) {
F_21 (KERN_ERR PFX L_29
L_30 , i) ;
goto V_76;
}
}
V_71 = V_83 * sizeof( struct V_84 ) ;
for ( V_68 = 0 ; V_68 < V_69 ; V_68 ++ ) {
V_64 = V_62 -> V_82 [ V_68 ] ;
V_64 -> V_85 = F_36 ( & V_59 -> V_86 -> V_87 ,
V_71 ,
& V_64 -> V_88 ,
V_74 ) ;
if ( ! V_64 -> V_85 ) {
F_21 (KERN_ERR PFX L_29
L_31 , i) ;
goto V_76;
}
}
return V_62 ;
V_76:
F_37 ( V_62 ) ;
return NULL ;
}
void F_37 ( struct V_57 * V_62 )
{
struct V_63 * V_64 ;
struct V_58 * V_59 = V_62 -> V_59 ;
T_3 V_71 ;
T_2 V_60 = V_79 ;
T_2 V_61 = V_89 ;
int V_69 ;
int V_68 ;
V_69 = V_61 - V_60 + 1 ;
if ( ! V_62 -> V_82 )
goto V_90;
V_71 = V_83 * sizeof( struct V_84 ) ;
for ( V_68 = 0 ; V_68 < V_69 ; V_68 ++ ) {
V_64 = V_62 -> V_82 [ V_68 ] ;
if ( V_64 -> V_85 ) {
F_38 ( & V_59 -> V_86 -> V_87 , V_71 ,
V_64 -> V_85 ,
V_64 -> V_88 ) ;
V_64 -> V_85 = NULL ;
}
}
for ( V_68 = 0 ; V_68 < V_69 ; V_68 ++ ) {
F_39 ( V_62 -> V_82 [ V_68 ] ) ;
V_62 -> V_82 [ V_68 ] = NULL ;
}
F_39 ( V_62 -> V_82 ) ;
V_62 -> V_82 = NULL ;
V_90:
F_39 ( V_62 -> V_77 ) ;
if ( ! V_62 -> V_75 )
goto V_91;
for ( V_68 = 0 ; V_68 < F_28 () + 1 ; V_68 ++ ) {
struct V_92 * V_93 ;
struct V_92 * V_94 ;
F_40 (list, tmp, &cmgr->free_list[i]) {
struct V_1 * V_2 = (struct V_1 * ) V_93 ;
F_41 ( & V_2 -> V_81 ) ;
F_39 ( V_2 ) ;
}
}
F_39 ( V_62 -> V_75 ) ;
V_91:
F_39 ( V_62 ) ;
}
struct V_1 * F_42 ( struct V_18 * V_19 , int type )
{
struct V_95 * V_6 = V_19 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_57 * V_96 = V_5 -> V_59 -> V_96 ;
struct V_1 * V_2 ;
struct V_92 * V_97 ;
struct V_63 * V_85 ;
int V_98 = V_99 ;
T_4 V_100 ;
T_4 V_101 ;
T_2 V_67 ;
V_101 = V_19 -> V_101 ;
switch ( type ) {
case V_102 :
V_101 = V_103 ;
break;
case V_42 :
V_101 = V_104 ;
break;
default:
break;
}
F_8 ( & V_96 -> V_77 [ V_98 ] ) ;
V_100 = F_43 ( & V_19 -> V_100 ) ;
if ( ( F_44 ( & ( V_96 -> V_75 [ V_98 ] ) ) ) ||
( V_19 -> V_105 . V_31 >= V_101 ) ||
( V_100 + V_101 <= V_106 ) ) {
F_45 ( V_19 , L_32
L_33 ,
V_19 -> V_105 . V_31 , V_19 -> V_101 ) ;
if ( F_44 ( & ( V_96 -> V_75 [ V_98 ] ) ) )
F_21 (KERN_ERR PFX L_34 ) ;
F_11 ( & V_96 -> V_77 [ V_98 ] ) ;
return NULL ;
}
V_97 = (struct V_92 * )
V_96 -> V_75 [ V_98 ] . V_107 ;
F_46 ( V_97 ) ;
V_2 = (struct V_1 * ) V_97 ;
V_67 = V_2 -> V_67 ;
V_96 -> V_78 [ V_67 ] = V_2 ;
F_47 ( & V_19 -> V_105 ) ;
F_48 ( & V_19 -> V_100 ) ;
F_11 ( & V_96 -> V_77 [ V_98 ] ) ;
F_31 ( & V_2 -> V_81 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_96 = V_96 ;
V_2 -> V_22 = 0 ;
V_2 -> V_17 = type ;
V_85 = V_2 -> V_85 = V_96 -> V_82 [ V_67 ] ;
V_85 -> V_2 = V_2 ;
F_49 ( & V_2 -> V_10 ) ;
return V_2 ;
}
struct V_1 * F_50 ( struct V_18 * V_19 )
{
struct V_95 * V_6 = V_19 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_57 * V_96 = V_5 -> V_59 -> V_96 ;
struct V_1 * V_2 ;
struct V_92 * V_97 ;
struct V_63 * V_85 ;
T_4 V_100 ;
T_4 V_101 ;
T_2 V_67 ;
int V_98 = F_51 () ;
V_101 = V_108 ;
F_8 ( & V_96 -> V_77 [ V_98 ] ) ;
V_100 = F_43 ( & V_19 -> V_100 ) ;
if ( ( F_44 ( & V_96 -> V_75 [ V_98 ] ) ) ||
( V_19 -> V_105 . V_31 >= V_101 ) ||
( V_100 + V_101 <= V_106 ) ) {
F_11 ( & V_96 -> V_77 [ V_98 ] ) ;
F_52 () ;
return NULL ;
}
V_97 = (struct V_92 * )
V_96 -> V_75 [ V_98 ] . V_107 ;
F_46 ( V_97 ) ;
V_2 = (struct V_1 * ) V_97 ;
V_67 = V_2 -> V_67 ;
V_96 -> V_78 [ V_67 ] = V_2 ;
F_47 ( & V_19 -> V_105 ) ;
F_48 ( & V_19 -> V_100 ) ;
F_11 ( & V_96 -> V_77 [ V_98 ] ) ;
F_52 () ;
F_31 ( & V_2 -> V_81 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_96 = V_96 ;
V_2 -> V_22 = 0 ;
V_85 = V_2 -> V_85 = V_96 -> V_82 [ V_67 ] ;
V_85 -> V_2 = V_2 ;
F_49 ( & V_2 -> V_10 ) ;
return V_2 ;
}
void V_35 ( struct V_109 * V_110 )
{
struct V_1 * V_2 = F_6 ( V_110 ,
struct V_1 , V_10 ) ;
struct V_57 * V_96 = V_2 -> V_96 ;
int V_98 ;
if ( V_2 -> V_17 == V_27 )
V_98 = V_2 -> V_67 % F_28 () ;
else
V_98 = V_99 ;
F_8 ( & V_96 -> V_77 [ V_98 ] ) ;
if ( V_2 -> V_17 != V_27 )
F_53 ( V_2 ) ;
V_96 -> V_78 [ V_2 -> V_67 ] = NULL ;
F_46 ( & V_2 -> V_81 ) ;
F_54 ( & V_2 -> V_81 ,
& V_96 -> V_75 [ V_98 ] ) ;
F_48 ( & V_2 -> V_19 -> V_105 ) ;
F_11 ( & V_96 -> V_77 [ V_98 ] ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_111 * V_112 = & ( V_2 -> V_112 ) ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
struct V_58 * V_59 = V_5 -> V_59 ;
T_3 V_113 = sizeof( struct V_84 ) ;
V_112 -> V_114 = 0 ;
if ( V_112 -> V_115 ) {
F_38 ( & V_59 -> V_86 -> V_87 , V_113 ,
V_112 -> V_115 ,
V_112 -> V_116 ) ;
V_112 -> V_115 = NULL ;
}
if ( V_112 -> V_117 ) {
F_38 ( & V_59 -> V_86 -> V_87 , V_113 ,
V_112 -> V_117 ,
V_112 -> V_118 ) ;
V_112 -> V_117 = NULL ;
}
if ( V_112 -> V_119 ) {
F_38 ( & V_59 -> V_86 -> V_87 , V_120 ,
V_112 -> V_119 ,
V_112 -> V_121 ) ;
V_112 -> V_119 = NULL ;
}
if ( V_112 -> V_122 ) {
F_38 ( & V_59 -> V_86 -> V_87 , V_120 ,
V_112 -> V_122 ,
V_112 -> V_123 ) ;
V_112 -> V_122 = NULL ;
}
}
int F_55 ( struct V_1 * V_2 )
{
struct V_111 * V_112 ;
struct V_84 * V_115 ;
struct V_84 * V_117 ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
struct V_58 * V_59 = V_5 -> V_59 ;
T_5 V_124 ;
T_3 V_113 ;
V_112 = (struct V_111 * ) & ( V_2 -> V_112 ) ;
memset ( V_112 , 0 , sizeof( struct V_111 ) ) ;
V_112 -> V_125 = sizeof( struct V_126 ) ;
V_2 -> V_127 = V_112 -> V_125 ;
V_112 -> V_119 = F_36 ( & V_59 -> V_86 -> V_87 , V_120 ,
& V_112 -> V_121 ,
V_128 ) ;
if ( ! V_112 -> V_119 ) {
F_21 (KERN_ERR PFX L_35 ) ;
F_53 ( V_2 ) ;
return V_129 ;
}
V_112 -> V_122 = F_36 ( & V_59 -> V_86 -> V_87 , V_120 ,
& V_112 -> V_123 ,
V_128 ) ;
if ( ! V_112 -> V_122 ) {
F_21 (KERN_ERR PFX L_36 ) ;
F_53 ( V_2 ) ;
return V_129 ;
}
memset ( V_112 -> V_119 , 0 , V_120 ) ;
memset ( V_112 -> V_122 , 0 , V_120 ) ;
V_113 = sizeof( struct V_84 ) ;
V_112 -> V_115 = F_36 ( & V_59 -> V_86 -> V_87 , V_113 ,
& V_112 -> V_116 ,
V_128 ) ;
if ( ! V_112 -> V_115 ) {
F_21 (KERN_ERR PFX L_37 ) ;
F_53 ( V_2 ) ;
return V_129 ;
}
V_112 -> V_117 = F_36 ( & V_59 -> V_86 -> V_87 , V_113 ,
& V_112 -> V_118 ,
V_128 ) ;
if ( ! V_112 -> V_115 ) {
F_21 (KERN_ERR PFX L_38 ) ;
F_53 ( V_2 ) ;
return V_129 ;
}
V_124 = V_112 -> V_121 ;
V_115 = V_112 -> V_115 ;
V_115 -> V_130 = ( T_4 ) V_124 & 0xffffffff ;
V_115 -> V_131 = ( T_4 ) ( ( V_132 ) V_124 >> 32 ) ;
V_115 -> V_133 = V_120 ;
V_115 -> V_34 = 0 ;
V_117 = V_112 -> V_117 ;
V_124 = V_112 -> V_123 ;
V_117 -> V_130 = ( T_4 ) V_124 & 0xffffffff ;
V_117 -> V_131 = ( T_4 ) ( ( V_132 ) V_124 >> 32 ) ;
V_117 -> V_133 = V_120 ;
V_117 -> V_34 = 0 ;
return V_41 ;
}
static int F_56 ( struct V_48 * V_49 , T_1 V_114 )
{
struct V_13 * V_14 ;
struct V_134 * V_135 = F_57 ( F_58 ( V_49 -> V_136 ) ) ;
struct V_137 * V_138 = V_135 -> V_139 ;
struct V_95 * V_6 ;
struct V_4 * V_5 ;
struct V_18 * V_19 ;
struct V_1 * V_2 ;
struct V_111 * V_140 ;
struct V_141 * V_142 ;
struct V_141 * V_143 ;
struct V_144 * V_145 = V_49 -> V_136 -> V_145 ;
struct V_146 * V_147 ;
struct V_126 * V_126 ;
int V_148 , V_98 ;
int V_21 = V_41 ;
T_2 V_67 ;
T_4 V_149 , V_150 ;
unsigned long V_151 = V_152 ;
V_14 = F_59 ( V_145 ) ;
V_6 = F_60 ( V_14 ) ;
V_5 = V_6 -> V_7 ;
if ( V_135 == NULL ) {
F_21 (KERN_ERR PFX L_39 ) ;
V_21 = V_129 ;
goto V_153;
}
V_21 = F_61 ( V_49 ) ;
if ( V_21 )
return V_21 ;
if ( V_14 -> V_154 != V_155 || ! ( V_14 -> V_156 ) ) {
F_21 (KERN_ERR PFX L_40 ) ;
V_21 = V_129 ;
goto V_153;
}
V_19 = (struct V_18 * ) & V_138 [ 1 ] ;
if ( ! ( F_14 ( V_157 , & V_19 -> V_34 ) ) ) {
F_21 (KERN_ERR PFX L_41 ) ;
V_21 = V_129 ;
goto V_153;
}
V_158:
V_2 = F_42 ( V_19 , V_102 ) ;
if ( ! V_2 ) {
if ( F_62 ( V_152 , V_151 + V_159 ) ) {
F_21 (KERN_ERR PFX L_42 ) ;
V_21 = V_129 ;
goto V_153;
}
F_63 ( 20 ) ;
goto V_158;
}
V_2 -> V_49 = V_49 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_19 = V_19 ;
V_140 = (struct V_111 * ) & ( V_2 -> V_112 ) ;
V_21 = F_55 ( V_2 ) ;
if ( V_21 == V_129 ) {
F_21 (KERN_ERR PFX L_43 ) ;
F_8 ( & V_19 -> V_23 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
F_11 ( & V_19 -> V_23 ) ;
goto V_153;
}
V_2 -> V_160 = 0 ;
V_140 -> V_114 = V_114 ;
F_64 ( V_2 , (struct V_126 * ) V_140 -> V_119 ) ;
V_126 = (struct V_126 * ) V_140 -> V_119 ;
memset ( V_126 -> V_161 , 0 , V_49 -> V_162 ) ;
V_126 -> V_163 = 0 ;
V_147 = & ( V_140 -> V_164 ) ;
V_149 = V_19 -> V_149 ;
V_150 = V_135 -> V_165 ;
F_65 ( V_147 , V_166 , V_150 , V_149 ,
V_167 , V_168 | V_169 |
V_170 , 0 ) ;
V_67 = V_2 -> V_67 ;
F_45 ( V_19 , L_44 , V_67 ) ;
V_148 = V_67 / V_171 ;
V_98 = V_67 % V_171 ;
V_143 = (struct V_141 * )
V_5 -> V_59 -> V_172 [ V_148 ] ;
V_142 = & ( V_143 [ V_98 ] ) ;
F_66 ( V_2 , V_142 ) ;
V_49 -> V_54 . V_55 = ( char * ) V_2 ;
F_8 ( & V_19 -> V_23 ) ;
F_67 ( V_19 , V_67 ) ;
V_2 -> V_173 = 1 ;
F_34 ( & V_2 -> V_81 , & V_19 -> V_174 ) ;
F_68 ( & V_2 -> V_29 ) ;
V_2 -> V_175 = 1 ;
F_69 ( V_19 ) ;
F_11 ( & V_19 -> V_23 ) ;
V_21 = F_70 ( & V_2 -> V_29 ,
V_176 * V_159 ) ;
F_8 ( & V_19 -> V_23 ) ;
V_2 -> V_175 = 0 ;
if ( ! ( F_14 ( V_177 , & V_2 -> V_22 ) ) )
F_20 ( V_178 , & V_2 -> V_22 ) ;
F_11 ( & V_19 -> V_23 ) ;
if ( ! V_21 ) {
F_45 ( V_19 , L_45 ) ;
V_21 = V_129 ;
} else {
F_45 ( V_19 , L_46 ) ;
V_21 = V_41 ;
}
V_153:
return V_21 ;
}
int F_19 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_134 * V_135 = V_19 -> V_135 ;
struct V_15 * V_16 = V_19 -> V_16 ;
struct V_4 * V_5 ;
struct V_95 * V_6 ;
struct V_1 * V_179 ;
struct V_141 * V_142 ;
struct V_141 * V_143 ;
struct V_146 * V_147 ;
struct V_111 * V_180 ;
int V_148 , V_98 ;
T_4 V_149 , V_150 ;
T_2 V_67 ;
int V_21 = V_41 ;
T_4 V_181 = V_16 -> V_181 ;
F_7 ( V_2 , L_47 ) ;
V_6 = V_2 -> V_6 ;
V_5 = V_6 -> V_7 ;
V_14 = V_6 -> V_14 ;
if ( ! F_14 ( V_157 , & V_19 -> V_34 ) ) {
F_21 (KERN_ERR PFX L_48 ) ;
V_21 = V_129 ;
goto V_182;
}
if ( V_135 == NULL ) {
F_21 (KERN_ERR PFX L_49 ) ;
V_21 = V_129 ;
goto V_182;
}
if ( V_14 -> V_154 != V_155 || ! ( V_14 -> V_156 ) ) {
F_21 (KERN_ERR PFX L_50 ) ;
V_21 = V_129 ;
goto V_182;
}
V_179 = F_42 ( V_19 , V_183 ) ;
if ( ! V_179 ) {
F_21 (KERN_ERR PFX L_51 ) ;
V_21 = V_129 ;
goto V_182;
}
V_179 -> V_49 = NULL ;
V_179 -> V_6 = V_6 ;
V_179 -> V_19 = V_19 ;
V_179 -> V_127 = 0 ;
V_180 = (struct V_111 * ) & ( V_179 -> V_112 ) ;
memset ( V_180 , 0 , sizeof( struct V_111 ) ) ;
V_147 = & ( V_180 -> V_164 ) ;
V_147 -> V_184 = F_71 ( V_2 -> V_67 ) ;
V_147 -> V_185 = F_71 ( V_2 -> V_142 -> V_186 . V_187 . V_188 ) ;
V_149 = V_19 -> V_149 ;
V_150 = V_135 -> V_165 ;
F_65 ( V_147 , V_189 , V_150 , V_149 ,
V_190 , V_168 | V_169 |
V_170 , 0 ) ;
V_67 = V_179 -> V_67 ;
F_7 ( V_179 , L_52 ) ;
V_148 = V_67 / V_171 ;
V_98 = V_67 % V_171 ;
V_143 = (struct V_141 * )
V_5 -> V_59 -> V_172 [ V_148 ] ;
V_142 = & ( V_143 [ V_98 ] ) ;
F_66 ( V_179 , V_142 ) ;
F_1 ( V_2 , 2 * V_181 ) ;
F_67 ( V_19 , V_67 ) ;
F_69 ( V_19 ) ;
V_182:
return V_21 ;
}
int F_72 ( struct V_1 * V_191 , T_4 V_192 ,
enum V_193 V_194 )
{
struct V_13 * V_14 ;
struct V_18 * V_19 = V_191 -> V_19 ;
struct V_4 * V_5 ;
struct V_95 * V_6 ;
struct V_1 * V_195 ;
struct V_141 * V_142 ;
struct V_141 * V_143 ;
struct V_196 * V_46 = NULL ;
int V_148 , V_98 ;
T_2 V_67 ;
int V_21 = 0 ;
F_7 ( V_191 , L_53 ,
V_191 -> V_67 ) ;
F_4 ( & V_191 -> V_10 ) ;
V_6 = V_191 -> V_6 ;
V_5 = V_6 -> V_7 ;
V_14 = V_6 -> V_14 ;
V_46 = F_30 ( sizeof( struct V_196 ) , V_128 ) ;
if ( ! V_46 ) {
F_21 (KERN_ERR PFX L_54 ) ;
V_21 = - V_197 ;
goto V_198;
}
V_195 = F_42 ( V_19 , V_199 ) ;
if ( ! V_195 ) {
F_21 (KERN_ERR PFX L_55 ) ;
V_21 = - V_197 ;
F_39 ( V_46 ) ;
goto V_198;
}
V_195 -> V_49 = NULL ;
V_195 -> V_6 = V_6 ;
V_195 -> V_19 = V_19 ;
V_195 -> V_127 = 0 ;
V_67 = V_195 -> V_67 ;
V_148 = V_67 / V_171 ;
V_98 = V_67 % V_171 ;
V_143 = (struct V_141 * )
V_5 -> V_59 -> V_172 [ V_148 ] ;
V_142 = & ( V_143 [ V_98 ] ) ;
V_46 -> V_200 = V_191 ;
V_46 -> V_2 = V_195 ;
V_46 -> V_194 = V_194 ;
V_46 -> V_192 = V_192 ;
V_195 -> V_46 = V_46 ;
F_21 (KERN_ERR PFX L_56 ) ;
F_73 ( V_195 , V_142 , V_191 , V_192 ) ;
F_67 ( V_19 , V_67 ) ;
F_69 ( V_19 ) ;
V_198:
return V_21 ;
}
int F_74 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_4 * V_5 ;
struct V_95 * V_6 ;
struct V_1 * V_201 ;
struct V_141 * V_142 ;
struct V_141 * V_143 ;
int V_148 , V_98 ;
T_2 V_67 , V_202 ;
int V_21 = 0 ;
F_7 ( V_2 , L_57 ) ;
V_6 = V_2 -> V_6 ;
V_5 = V_6 -> V_7 ;
V_14 = V_6 -> V_14 ;
V_201 = F_42 ( V_19 , V_203 ) ;
if ( ! V_201 ) {
F_21 (KERN_ERR PFX L_55 ) ;
V_21 = - 1 ;
goto V_198;
}
V_201 -> V_49 = NULL ;
V_201 -> V_6 = V_6 ;
V_201 -> V_19 = V_19 ;
V_201 -> V_127 = 0 ;
V_67 = V_201 -> V_67 ;
V_148 = V_67 / V_171 ;
V_98 = V_67 % V_171 ;
V_143 = (struct V_141 * )
V_5 -> V_59 -> V_172 [ V_148 ] ;
V_142 = & ( V_143 [ V_98 ] ) ;
V_202 = V_2 -> V_67 ;
F_7 ( V_2 , L_58 , V_67 ) ;
F_75 ( V_201 , V_142 , V_202 ) ;
F_67 ( V_19 , V_67 ) ;
F_69 ( V_19 ) ;
V_198:
return V_21 ;
}
int F_76 ( struct V_48 * V_49 )
{
return F_56 ( V_49 , V_204 ) ;
}
int F_77 ( struct V_48 * V_49 )
{
return F_56 ( V_49 , V_205 ) ;
}
int F_78 ( struct V_48 * V_49 )
{
struct V_134 * V_135 = F_57 ( F_58 ( V_49 -> V_136 ) ) ;
struct V_137 * V_138 = V_135 -> V_139 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
struct V_18 * V_19 ;
int V_21 = V_129 ;
V_21 = F_61 ( V_49 ) ;
if ( V_21 )
return V_21 ;
V_14 = F_59 ( V_49 -> V_136 -> V_145 ) ;
if ( ( V_14 -> V_154 != V_155 ) || ! ( V_14 -> V_156 ) ) {
F_21 (KERN_ERR PFX L_59 ) ;
return V_21 ;
}
V_19 = (struct V_18 * ) & V_138 [ 1 ] ;
F_45 ( V_19 , L_60 ) ;
F_8 ( & V_19 -> V_23 ) ;
V_2 = (struct V_1 * ) V_49 -> V_54 . V_55 ;
if ( ! V_2 ) {
F_21 (KERN_ERR PFX L_61 ) ;
F_11 ( & V_19 -> V_23 ) ;
return V_41 ;
}
F_7 ( V_2 , L_62 ,
V_2 -> V_10 . V_10 . V_31 ) ;
F_4 ( & V_2 -> V_10 ) ;
F_79 ( V_19 != V_2 -> V_19 ) ;
if ( V_19 -> V_206 ) {
F_21 (KERN_ERR PFX L_63
L_64 , io_req->xid) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
F_11 ( & V_19 -> V_23 ) ;
return V_41 ;
}
if ( V_2 -> V_207 == 0 ) {
F_21 (KERN_ERR PFX L_63
L_65 , io_req->xid) ;
F_22 ( V_2 , V_208 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
F_11 ( & V_19 -> V_23 ) ;
return V_41 ;
}
F_46 ( & V_2 -> V_81 ) ;
V_2 -> V_207 = 0 ;
F_34 ( & V_2 -> V_81 , & V_19 -> V_209 ) ;
F_68 ( & V_2 -> V_29 ) ;
V_2 -> V_175 = 1 ;
if ( ! F_15 ( V_30 , & V_2 -> V_22 ) ) {
if ( F_80 ( & V_2 -> V_9 ) )
F_16 ( & V_2 -> V_10 ,
V_35 ) ;
F_20 ( V_28 , & V_2 -> V_22 ) ;
V_21 = F_19 ( V_2 ) ;
} else {
F_21 (KERN_ERR PFX L_63
L_66 , io_req->xid) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
F_11 ( & V_19 -> V_23 ) ;
return V_41 ;
}
if ( V_21 == V_129 ) {
F_16 ( & V_2 -> V_10 , V_35 ) ;
F_11 ( & V_19 -> V_23 ) ;
return V_21 ;
}
F_11 ( & V_19 -> V_23 ) ;
F_81 ( & V_2 -> V_29 ) ;
F_8 ( & V_19 -> V_23 ) ;
V_2 -> V_175 = 0 ;
if ( ! ( F_15 ( V_32 ,
& V_2 -> V_22 ) ) ) {
F_21 (KERN_ERR PFX L_67 ,
io_req->xid) ;
V_21 = V_129 ;
} else {
F_7 ( V_2 , L_68 ) ;
V_21 = V_41 ;
F_22 ( V_2 , V_208 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
}
F_16 ( & V_2 -> V_10 , V_35 ) ;
F_11 ( & V_19 -> V_23 ) ;
return V_21 ;
}
void F_82 ( struct V_1 * V_195 ,
struct V_141 * V_142 ,
T_1 V_210 )
{
struct V_196 * V_46 = V_195 -> V_46 ;
struct V_1 * V_191 = V_46 -> V_200 ;
T_4 V_192 = V_46 -> V_192 ;
enum V_193 V_194 = V_46 -> V_194 ;
int V_21 = 0 ;
struct V_18 * V_19 = V_191 -> V_19 ;
F_7 ( V_191 , L_69
L_70 ,
V_195 -> V_67 , V_195 -> V_17 ) ;
if ( V_210 == V_211 ) {
F_21 (KERN_ERR PFX L_71 ,
seq_clnp_req->xid) ;
goto V_212;
}
F_4 ( & V_191 -> V_10 ) ;
F_11 ( & V_19 -> V_23 ) ;
V_21 = F_83 ( V_191 , V_192 , V_194 ) ;
F_8 ( & V_19 -> V_23 ) ;
if ( V_21 )
F_21 (KERN_ERR PFX L_72
L_73 ) ;
V_195 -> V_46 = NULL ;
F_16 ( & V_191 -> V_10 , V_35 ) ;
V_212:
F_39 ( V_46 ) ;
return;
}
void F_84 ( struct V_1 * V_2 ,
struct V_141 * V_142 ,
T_1 V_213 )
{
F_7 ( V_2 , L_74
L_75 ,
V_2 -> V_10 . V_10 . V_31 , V_2 -> V_17 ) ;
F_22 ( V_2 , V_214 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
}
void F_85 ( struct V_1 * V_2 ,
struct V_141 * V_142 ,
T_1 V_213 )
{
T_4 V_194 ;
T_4 V_181 = V_215 ;
T_1 V_216 = 0 ;
struct V_18 * V_19 = V_2 -> V_19 ;
F_7 ( V_2 , L_76
L_75 ,
V_2 -> V_67 ,
V_2 -> V_10 . V_10 . V_31 , V_2 -> V_17 ) ;
if ( F_15 ( V_32 ,
& V_2 -> V_22 ) ) {
F_7 ( V_2 , L_77
L_78 ) ;
return;
}
if ( F_15 ( V_217 ,
& V_2 -> V_22 ) )
goto V_218;
if ( F_14 ( V_30 , & V_2 -> V_22 ) )
if ( F_80 ( & V_2 -> V_9 ) )
F_16 ( & V_2 -> V_10 ,
V_35 ) ;
V_194 = ( T_1 ) V_142 -> V_219 . V_220 . V_221 . V_222 . V_194 ;
switch ( V_194 ) {
case V_223 :
F_7 ( V_2 , L_79 ) ;
V_216 = 1 ;
break;
case V_224 :
F_7 ( V_2 , L_80 ) ;
break;
default:
F_21 (KERN_ERR PFX L_81 ) ;
break;
}
if ( V_216 ) {
F_7 ( V_2 , L_82 ) ;
F_20 ( V_24 , & V_2 -> V_22 ) ;
}
F_20 ( V_25 , & V_2 -> V_22 ) ;
F_1 ( V_2 , V_181 ) ;
V_218:
if ( V_2 -> V_175 ) {
if ( F_9 ( V_28 ,
& V_2 -> V_22 ) )
F_13 ( & V_2 -> V_29 ) ;
} else {
if ( V_2 -> V_207 ) {
F_46 ( & V_2 -> V_81 ) ;
V_2 -> V_207 = 0 ;
F_34 ( & V_2 -> V_81 , & V_19 -> V_209 ) ;
}
F_22 ( V_2 , V_214 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
}
}
static void F_86 ( struct V_1 * V_2 )
{
struct V_48 * V_49 = V_2 -> V_49 ;
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_92 * V_93 ;
struct V_92 * V_94 ;
struct V_1 * V_225 ;
int V_226 = V_49 -> V_136 -> V_227 ;
int V_21 = 0 ;
int V_227 ;
F_7 ( V_2 , L_83 ) ;
F_40 (list, tmp, &tgt->active_cmd_queue) {
F_45 ( V_19 , L_84 ) ;
V_225 = (struct V_1 * ) V_93 ;
V_227 = V_225 -> V_49 -> V_136 -> V_227 ;
if ( V_227 == V_226 ) {
if ( ! F_15 ( V_30 ,
& V_225 -> V_22 ) ) {
if ( F_80 ( & V_2 -> V_9 ) )
F_16 ( & V_2 -> V_10 ,
V_35 ) ;
V_21 = F_19 ( V_225 ) ;
F_87 ( V_21 != V_41 ) ;
} else
F_21 (KERN_ERR PFX L_85
L_86 ,
cmd->xid) ;
}
}
}
static void F_88 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_92 * V_93 ;
struct V_92 * V_94 ;
struct V_1 * V_225 ;
int V_21 = 0 ;
F_7 ( V_2 , L_87 ) ;
F_40 (list, tmp, &tgt->active_cmd_queue) {
F_45 ( V_19 , L_88 ) ;
V_225 = (struct V_1 * ) V_93 ;
if ( ! F_15 ( V_30 ,
& V_225 -> V_22 ) ) {
if ( F_80 ( & V_2 -> V_9 ) )
F_16 ( & V_2 -> V_10 ,
V_35 ) ;
V_21 = F_19 ( V_225 ) ;
F_87 ( V_21 != V_41 ) ;
} else
F_21 (KERN_ERR PFX L_89
L_90 , cmd->xid) ;
}
}
void F_89 ( struct V_1 * V_2 ,
struct V_141 * V_142 , T_1 V_213 )
{
struct V_111 * V_140 ;
struct V_146 * V_147 ;
struct V_48 * V_49 = V_2 -> V_49 ;
V_132 * V_228 ;
V_132 * V_229 ;
void * V_230 ;
F_7 ( V_2 , L_91 ) ;
if ( ! ( F_14 ( V_178 , & V_2 -> V_22 ) ) )
F_20 ( V_177 , & V_2 -> V_22 ) ;
else {
return;
}
V_140 = & ( V_2 -> V_112 ) ;
V_147 = & ( V_140 -> V_231 ) ;
V_228 = ( V_132 * ) V_147 ;
V_229 = ( V_132 * )
& V_142 -> V_219 . V_220 . V_221 . V_232 . V_147 ;
V_228 [ 0 ] = F_90 ( V_229 [ 0 ] ) ;
V_228 [ 1 ] = F_90 ( V_229 [ 1 ] ) ;
V_228 [ 2 ] = F_90 ( V_229 [ 2 ] ) ;
V_140 -> V_233 =
V_142 -> V_219 . V_220 . V_221 . V_232 . V_234 ;
V_230 = V_140 -> V_122 ;
if ( V_147 -> V_235 == V_236 ) {
F_91 ( V_2 ,
(struct V_237 * )
V_230 , V_213 ) ;
if ( V_2 -> V_238 == 0 ) {
if ( V_140 -> V_114 & V_205 )
F_86 ( V_2 ) ;
else if ( V_140 -> V_114 & V_204 )
F_88 ( V_2 ) ;
}
} else {
F_21 (KERN_ERR PFX L_92 ,
fc_hdr->fh_r_ctl) ;
}
if ( ! V_49 -> V_54 . V_55 ) {
F_21 (KERN_ERR PFX L_93 ) ;
return;
}
switch ( V_2 -> V_239 ) {
case V_240 :
if ( V_2 -> V_241 == 0 ) {
V_49 -> V_51 = V_242 << 16 ;
} else {
V_49 -> V_51 = ( V_242 << 16 ) | V_2 -> V_241 ;
}
if ( V_2 -> V_243 )
F_25 ( V_49 , V_2 -> V_243 ) ;
break;
default:
F_7 ( V_2 , L_94 ,
V_2 -> V_239 ) ;
break;
}
V_49 = V_2 -> V_49 ;
V_2 -> V_49 = NULL ;
if ( V_2 -> V_173 ) {
F_46 ( & V_2 -> V_81 ) ;
V_2 -> V_173 = 0 ;
} else {
F_21 (KERN_ERR PFX L_95 ) ;
return;
}
V_49 -> V_54 . V_55 = NULL ;
V_49 -> V_56 ( V_49 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
if ( V_2 -> V_175 ) {
F_7 ( V_2 , L_96 ) ;
F_13 ( & V_2 -> V_29 ) ;
}
}
static int F_92 ( struct V_1 * V_2 , V_132 V_124 , int V_244 ,
int V_245 )
{
struct V_84 * V_246 = V_2 -> V_85 -> V_85 ;
int V_247 , V_248 ;
V_248 = 0 ;
while ( V_244 ) {
if ( V_244 >= V_249 )
V_247 = V_249 ;
else
V_247 = V_244 ;
V_246 [ V_245 + V_248 ] . V_130 = V_124 & 0xffffffff ;
V_246 [ V_245 + V_248 ] . V_131 = V_124 >> 32 ;
V_246 [ V_245 + V_248 ] . V_133 = ( T_2 ) V_247 ;
V_246 [ V_245 + V_248 ] . V_34 = 0 ;
V_124 += ( V_132 ) V_247 ;
V_248 ++ ;
V_244 -= V_247 ;
}
return V_248 ;
}
static int F_93 ( struct V_1 * V_2 )
{
struct V_48 * V_250 = V_2 -> V_49 ;
struct V_84 * V_246 = V_2 -> V_85 -> V_85 ;
struct V_251 * V_252 ;
int V_253 = 0 ;
int V_254 = 0 ;
int V_255 = 0 ;
int V_248 ;
unsigned int V_244 ;
V_132 V_124 ;
int V_68 ;
V_254 = F_94 ( V_250 ) ;
F_95 (sc, sg, sg_count, i) {
V_244 = F_96 ( V_252 ) ;
V_124 = F_97 ( V_252 ) ;
if ( V_244 > V_256 ) {
V_248 = F_92 ( V_2 , V_124 , V_244 ,
V_255 ) ;
} else {
V_248 = 1 ;
V_246 [ V_255 ] . V_130 = V_124 & 0xffffffff ;
V_246 [ V_255 ] . V_131 = V_124 >> 32 ;
V_246 [ V_255 ] . V_133 = ( T_2 ) V_244 ;
V_246 [ V_255 ] . V_34 = 0 ;
}
V_255 += V_248 ;
V_253 += V_244 ;
}
if ( V_253 != F_26 ( V_250 ) )
F_21 (KERN_ERR PFX L_97
L_98 , byte_count, scsi_bufflen(sc),
io_req->xid) ;
return V_255 ;
}
static void F_98 ( struct V_1 * V_2 )
{
struct V_48 * V_250 = V_2 -> V_49 ;
struct V_84 * V_246 = V_2 -> V_85 -> V_85 ;
int V_255 ;
if ( F_99 ( V_250 ) )
V_255 = F_93 ( V_2 ) ;
else {
V_255 = 0 ;
V_246 [ 0 ] . V_130 = V_246 [ 0 ] . V_131 = 0 ;
V_246 [ 0 ] . V_133 = V_246 [ 0 ] . V_34 = 0 ;
}
V_2 -> V_85 -> V_257 = V_255 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_48 * V_250 = V_2 -> V_49 ;
if ( V_2 -> V_85 -> V_257 && V_250 ) {
F_100 ( V_250 ) ;
V_2 -> V_85 -> V_257 = 0 ;
}
}
void F_64 ( struct V_1 * V_2 ,
struct V_126 * V_126 )
{
struct V_48 * V_49 = V_2 -> V_49 ;
char V_258 [ 2 ] ;
memset ( V_126 , 0 , sizeof( struct V_126 ) ) ;
F_101 ( V_49 -> V_136 -> V_227 ,
(struct V_259 * ) V_126 -> V_260 ) ;
V_126 -> V_163 = F_102 ( V_2 -> V_127 ) ;
memcpy ( V_126 -> V_161 , V_49 -> V_261 , V_49 -> V_162 ) ;
V_126 -> V_262 = 0 ;
V_126 -> V_263 = 0 ;
V_126 -> V_264 = V_2 -> V_112 . V_114 ;
V_126 -> V_265 = V_2 -> V_160 ;
if ( F_103 ( V_49 , V_258 ) ) {
switch ( V_258 [ 0 ] ) {
case V_266 :
V_126 -> V_263 = V_267 ;
break;
case V_268 :
V_126 -> V_263 = V_269 ;
break;
default:
V_126 -> V_263 = V_270 ;
break;
}
} else {
V_126 -> V_263 = 0 ;
}
}
static void F_91 ( struct V_1 * V_2 ,
struct V_237 * V_271 ,
T_1 V_213 )
{
struct V_48 * V_49 = V_2 -> V_49 ;
struct V_18 * V_19 = V_2 -> V_19 ;
T_1 V_272 = V_271 -> V_273 . V_34 ;
T_4 V_274 = 0 ;
int V_68 ;
unsigned char * V_275 ;
unsigned char * V_276 ;
int V_277 = 0 ;
int V_278 = 0 ;
V_2 -> V_239 = V_240 ;
V_2 -> V_243 = V_271 -> V_243 ;
V_2 -> V_279 = V_272 ;
F_104 ( V_49 ) = V_2 -> V_241 =
V_271 -> V_280 ;
if ( V_213 ) {
if ( V_272 &
V_281 ) {
V_278 = V_274
= V_271 -> V_278 ;
}
if ( V_272 &
V_282 ) {
V_277 = V_271 -> V_277 ;
V_274 += V_271 -> V_277 ;
}
V_2 -> V_278 = V_278 ;
V_2 -> V_277 = V_277 ;
if ( V_274 > V_213 * V_283 ) {
F_21 (KERN_ERR PFX L_99 ,
rq_buff_len) ;
V_274 = V_213 * V_283 ;
}
V_275 = F_105 ( V_19 , 1 ) ;
if ( V_213 > 1 ) {
for ( V_68 = 1 ; V_68 < V_213 ; V_68 ++ )
V_276 = F_105 ( V_19 , 1 ) ;
}
if ( ( V_278 == 4 ) || ( V_278 == 8 ) ) {
V_2 -> V_238 = V_275 [ 3 ] ;
F_21 (KERN_ERR PFX L_100 ,
io_req->fcp_rsp_code) ;
}
V_275 += V_278 ;
if ( V_277 > V_284 ) {
F_21 (KERN_ERR PFX L_101 ) ;
V_277 = V_284 ;
}
memset ( V_49 -> V_285 , 0 , sizeof( V_49 -> V_285 ) ) ;
if ( V_277 )
memcpy ( V_49 -> V_285 , V_275 , V_277 ) ;
for ( V_68 = 0 ; V_68 < V_213 ; V_68 ++ )
F_106 ( V_19 , 1 ) ;
}
}
int F_107 ( struct V_144 * V_145 ,
struct V_48 * V_49 )
{
struct V_13 * V_14 = F_59 ( V_145 ) ;
struct V_134 * V_135 = F_57 ( F_58 ( V_49 -> V_136 ) ) ;
struct V_137 * V_138 = V_135 -> V_139 ;
struct V_18 * V_19 ;
struct V_1 * V_2 ;
int V_21 = 0 ;
int V_286 ;
V_286 = F_108 ( V_135 ) ;
if ( V_286 ) {
V_49 -> V_51 = V_286 ;
V_49 -> V_56 ( V_49 ) ;
return 0 ;
}
if ( ( V_14 -> V_154 != V_155 ) || ! ( V_14 -> V_156 ) ) {
V_21 = V_287 ;
goto V_288;
}
V_19 = (struct V_18 * ) & V_138 [ 1 ] ;
if ( ! F_14 ( V_157 , & V_19 -> V_34 ) ) {
if ( F_14 ( V_289 , & V_19 -> V_34 ) ) {
V_49 -> V_51 = V_290 << 16 ;
V_49 -> V_56 ( V_49 ) ;
return 0 ;
}
V_21 = V_291 ;
goto V_288;
}
V_2 = F_50 ( V_19 ) ;
if ( ! V_2 ) {
V_21 = V_287 ;
goto V_288;
}
V_2 -> V_49 = V_49 ;
if ( F_109 ( V_19 , V_2 ) ) {
F_21 (KERN_ERR PFX L_102 ) ;
V_21 = V_287 ;
goto V_288;
}
V_288:
return V_21 ;
}
void F_110 ( struct V_1 * V_2 ,
struct V_141 * V_142 ,
T_1 V_213 )
{
struct V_237 * V_271 ;
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_48 * V_49 ;
struct V_144 * V_145 ;
if ( F_15 ( V_40 , & V_2 -> V_22 ) ) {
F_7 ( V_2 , L_103
L_104 ) ;
}
if ( F_80 ( & V_2 -> V_9 ) )
F_16 ( & V_2 -> V_10 ,
V_35 ) ;
V_49 = V_2 -> V_49 ;
if ( V_49 == NULL ) {
F_21 (KERN_ERR PFX L_105 ) ;
return;
}
V_271 = (struct V_237 * )
& ( V_142 -> V_219 . V_220 . V_221 . V_271 . V_292 ) ;
F_91 ( V_2 , V_271 , V_213 ) ;
V_145 = V_49 -> V_136 -> V_145 ;
if ( ! V_49 -> V_54 . V_55 ) {
F_21 (KERN_ERR PFX L_106 ) ;
return;
}
if ( V_2 -> V_207 ) {
F_46 ( & V_2 -> V_81 ) ;
V_2 -> V_207 = 0 ;
F_34 ( & V_2 -> V_81 , & V_19 -> V_209 ) ;
} else {
F_7 ( V_2 , L_107 ) ;
if ( V_2 -> V_175 )
if ( F_9 ( V_28 ,
& V_2 -> V_22 ) )
F_13 ( & V_2 -> V_29 ) ;
}
F_23 ( V_2 ) ;
V_2 -> V_49 = NULL ;
switch ( V_2 -> V_239 ) {
case V_240 :
if ( V_2 -> V_241 == 0 ) {
V_49 -> V_51 = V_242 << 16 ;
} else {
F_7 ( V_2 , L_108
L_109 ,
V_2 -> V_241 , V_2 -> V_243 ) ;
V_49 -> V_51 = ( V_242 << 16 ) | V_2 -> V_241 ;
}
if ( V_2 -> V_243 )
F_25 ( V_49 , V_2 -> V_243 ) ;
break;
default:
F_21 (KERN_ERR PFX L_110 ,
io_req->fcp_status) ;
break;
}
V_49 -> V_54 . V_55 = NULL ;
V_49 -> V_56 ( V_49 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
}
int F_109 ( struct V_18 * V_19 ,
struct V_1 * V_2 )
{
struct V_141 * V_142 ;
struct V_141 * V_143 ;
struct V_48 * V_49 = V_2 -> V_49 ;
struct V_95 * V_6 = V_19 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_58 * V_59 = V_5 -> V_59 ;
struct V_13 * V_14 = V_6 -> V_14 ;
struct V_293 * V_294 ;
int V_148 , V_98 ;
T_2 V_67 ;
V_2 -> V_17 = V_27 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_19 = V_19 ;
V_2 -> V_127 = F_26 ( V_49 ) ;
V_49 -> V_54 . V_55 = ( char * ) V_2 ;
V_294 = F_111 ( V_14 -> V_295 , F_51 () ) ;
if ( V_49 -> V_296 == V_297 ) {
V_2 -> V_160 = V_298 ;
V_294 -> V_299 ++ ;
V_294 -> V_300 += V_2 -> V_127 ;
} else if ( V_49 -> V_296 == V_301 ) {
V_2 -> V_160 = V_302 ;
V_294 -> V_303 ++ ;
V_294 -> V_304 += V_2 -> V_127 ;
} else {
V_2 -> V_160 = 0 ;
V_294 -> V_305 ++ ;
}
F_52 () ;
V_67 = V_2 -> V_67 ;
F_98 ( V_2 ) ;
V_148 = V_67 / V_171 ;
V_98 = V_67 % V_171 ;
V_143 = (struct V_141 * ) V_59 -> V_172 [ V_148 ] ;
V_142 = & ( V_143 [ V_98 ] ) ;
F_112 ( V_2 , V_142 ) ;
F_8 ( & V_19 -> V_23 ) ;
if ( V_19 -> V_206 ) {
F_21 (KERN_ERR PFX L_111 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
F_11 ( & V_19 -> V_23 ) ;
return - V_306 ;
}
if ( ! F_14 ( V_157 , & V_19 -> V_34 ) ) {
F_21 (KERN_ERR PFX L_112 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
F_11 ( & V_19 -> V_23 ) ;
return - V_306 ;
}
if ( V_19 -> V_307 )
F_1 ( V_2 , V_308 ) ;
F_67 ( V_19 , V_67 ) ;
V_2 -> V_207 = 1 ;
F_34 ( & V_2 -> V_81 , & V_19 -> V_309 ) ;
F_69 ( V_19 ) ;
F_11 ( & V_19 -> V_23 ) ;
return 0 ;
}
