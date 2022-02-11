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
if ( ! ( F_14 ( V_177 , & V_2 -> V_22 ) ) ) {
F_20 ( V_178 , & V_2 -> V_22 ) ;
if ( V_2 -> V_173 ) {
F_46 ( & V_2 -> V_81 ) ;
V_2 -> V_173 = 0 ;
}
V_2 -> V_175 = 1 ;
F_71 ( V_2 ) ;
F_11 ( & V_19 -> V_23 ) ;
V_21 = F_70 ( & V_2 -> V_29 ,
V_179 ) ;
F_8 ( & V_19 -> V_23 ) ;
V_2 -> V_175 = 0 ;
if ( ! V_21 )
F_16 ( & V_2 -> V_10 , V_35 ) ;
}
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
struct V_1 * V_180 ;
struct V_141 * V_142 ;
struct V_141 * V_143 ;
struct V_146 * V_147 ;
struct V_111 * V_181 ;
int V_148 , V_98 ;
T_4 V_149 , V_150 ;
T_2 V_67 ;
int V_21 = V_41 ;
T_4 V_182 = V_16 -> V_182 ;
F_7 ( V_2 , L_47 ) ;
V_6 = V_2 -> V_6 ;
V_5 = V_6 -> V_7 ;
V_14 = V_6 -> V_14 ;
if ( ! F_14 ( V_157 , & V_19 -> V_34 ) ) {
F_21 (KERN_ERR PFX L_48 ) ;
V_21 = V_129 ;
goto V_183;
}
if ( V_135 == NULL ) {
F_21 (KERN_ERR PFX L_49 ) ;
V_21 = V_129 ;
goto V_183;
}
if ( V_14 -> V_154 != V_155 || ! ( V_14 -> V_156 ) ) {
F_21 (KERN_ERR PFX L_50 ) ;
V_21 = V_129 ;
goto V_183;
}
V_180 = F_42 ( V_19 , V_184 ) ;
if ( ! V_180 ) {
F_21 (KERN_ERR PFX L_51 ) ;
V_21 = V_129 ;
goto V_183;
}
V_180 -> V_49 = NULL ;
V_180 -> V_6 = V_6 ;
V_180 -> V_19 = V_19 ;
V_180 -> V_127 = 0 ;
V_181 = (struct V_111 * ) & ( V_180 -> V_112 ) ;
memset ( V_181 , 0 , sizeof( struct V_111 ) ) ;
V_147 = & ( V_181 -> V_164 ) ;
V_147 -> V_185 = F_72 ( V_2 -> V_67 ) ;
V_147 -> V_186 = F_72 ( V_2 -> V_142 -> V_187 . V_188 . V_189 ) ;
V_149 = V_19 -> V_149 ;
V_150 = V_135 -> V_165 ;
F_65 ( V_147 , V_190 , V_150 , V_149 ,
V_191 , V_168 | V_169 |
V_170 , 0 ) ;
V_67 = V_180 -> V_67 ;
F_7 ( V_180 , L_52 ) ;
V_148 = V_67 / V_171 ;
V_98 = V_67 % V_171 ;
V_143 = (struct V_141 * )
V_5 -> V_59 -> V_172 [ V_148 ] ;
V_142 = & ( V_143 [ V_98 ] ) ;
F_66 ( V_180 , V_142 ) ;
F_1 ( V_2 , 2 * V_182 ) ;
F_67 ( V_19 , V_67 ) ;
F_69 ( V_19 ) ;
V_183:
return V_21 ;
}
int F_73 ( struct V_1 * V_192 , T_4 V_193 ,
enum V_194 V_195 )
{
struct V_13 * V_14 ;
struct V_18 * V_19 = V_192 -> V_19 ;
struct V_4 * V_5 ;
struct V_95 * V_6 ;
struct V_1 * V_196 ;
struct V_141 * V_142 ;
struct V_141 * V_143 ;
struct V_197 * V_46 = NULL ;
int V_148 , V_98 ;
T_2 V_67 ;
int V_21 = 0 ;
F_7 ( V_192 , L_53 ,
V_192 -> V_67 ) ;
F_4 ( & V_192 -> V_10 ) ;
V_6 = V_192 -> V_6 ;
V_5 = V_6 -> V_7 ;
V_14 = V_6 -> V_14 ;
V_46 = F_30 ( sizeof( struct V_197 ) , V_128 ) ;
if ( ! V_46 ) {
F_21 (KERN_ERR PFX L_54 ) ;
V_21 = - V_198 ;
goto V_199;
}
V_196 = F_42 ( V_19 , V_200 ) ;
if ( ! V_196 ) {
F_21 (KERN_ERR PFX L_55 ) ;
V_21 = - V_198 ;
F_39 ( V_46 ) ;
goto V_199;
}
V_196 -> V_49 = NULL ;
V_196 -> V_6 = V_6 ;
V_196 -> V_19 = V_19 ;
V_196 -> V_127 = 0 ;
V_67 = V_196 -> V_67 ;
V_148 = V_67 / V_171 ;
V_98 = V_67 % V_171 ;
V_143 = (struct V_141 * )
V_5 -> V_59 -> V_172 [ V_148 ] ;
V_142 = & ( V_143 [ V_98 ] ) ;
V_46 -> V_201 = V_192 ;
V_46 -> V_2 = V_196 ;
V_46 -> V_195 = V_195 ;
V_46 -> V_193 = V_193 ;
V_196 -> V_46 = V_46 ;
F_21 (KERN_ERR PFX L_56 ) ;
F_74 ( V_196 , V_142 , V_192 , V_193 ) ;
F_67 ( V_19 , V_67 ) ;
F_69 ( V_19 ) ;
V_199:
return V_21 ;
}
int F_71 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_4 * V_5 ;
struct V_95 * V_6 ;
struct V_1 * V_202 ;
struct V_141 * V_142 ;
struct V_141 * V_143 ;
int V_148 , V_98 ;
T_2 V_67 , V_203 ;
int V_21 = 0 ;
F_7 ( V_2 , L_57 ) ;
V_6 = V_2 -> V_6 ;
V_5 = V_6 -> V_7 ;
V_14 = V_6 -> V_14 ;
V_202 = F_42 ( V_19 , V_204 ) ;
if ( ! V_202 ) {
F_21 (KERN_ERR PFX L_55 ) ;
V_21 = - 1 ;
goto V_199;
}
V_202 -> V_49 = NULL ;
V_202 -> V_6 = V_6 ;
V_202 -> V_19 = V_19 ;
V_202 -> V_127 = 0 ;
V_67 = V_202 -> V_67 ;
V_148 = V_67 / V_171 ;
V_98 = V_67 % V_171 ;
V_143 = (struct V_141 * )
V_5 -> V_59 -> V_172 [ V_148 ] ;
V_142 = & ( V_143 [ V_98 ] ) ;
V_203 = V_2 -> V_67 ;
F_7 ( V_2 , L_58 , V_67 ) ;
F_75 ( V_202 , V_142 , V_203 ) ;
F_67 ( V_19 , V_67 ) ;
F_69 ( V_19 ) ;
V_199:
return V_21 ;
}
int F_76 ( struct V_48 * V_49 )
{
return F_56 ( V_49 , V_205 ) ;
}
int F_77 ( struct V_48 * V_49 )
{
return F_56 ( V_49 , V_206 ) ;
}
int F_78 ( struct V_13 * V_14 , struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_15 * V_16 = V_19 -> V_16 ;
int V_20 ;
int V_21 = V_41 ;
int V_207 = 0 ;
F_7 ( V_2 , L_59 ,
V_19 -> V_34 ) ;
V_20 = F_15 ( V_33 ,
& V_19 -> V_34 ) ;
V_2 -> V_175 = 1 ;
F_71 ( V_2 ) ;
F_11 ( & V_19 -> V_23 ) ;
F_79 ( & V_2 -> V_29 ) ;
V_2 -> V_175 = 0 ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
if ( ! V_20 ) {
F_10 ( V_157 , & V_19 -> V_34 ) ;
F_17 ( & V_14 -> V_36 . V_37 ) ;
V_14 -> V_38 . V_39 ( V_16 ) ;
F_18 ( & V_14 -> V_36 . V_37 ) ;
do {
F_63 ( V_208 ) ;
if ( V_207 ++ > V_209 ) {
V_21 = V_129 ;
break;
}
} while ( ! F_14 ( V_157 , & V_19 -> V_34 ) );
}
F_8 ( & V_19 -> V_23 ) ;
return V_21 ;
}
int F_80 ( struct V_48 * V_49 )
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
F_21 (KERN_ERR PFX L_60 ) ;
return V_21 ;
}
V_19 = (struct V_18 * ) & V_138 [ 1 ] ;
F_45 ( V_19 , L_61 ) ;
F_8 ( & V_19 -> V_23 ) ;
V_2 = (struct V_1 * ) V_49 -> V_54 . V_55 ;
if ( ! V_2 ) {
F_21 (KERN_ERR PFX L_62 ) ;
F_11 ( & V_19 -> V_23 ) ;
return V_41 ;
}
F_7 ( V_2 , L_63 ,
V_2 -> V_10 . V_10 . V_31 ) ;
F_4 ( & V_2 -> V_10 ) ;
F_81 ( V_19 != V_2 -> V_19 ) ;
if ( V_19 -> V_210 ) {
F_21 (KERN_ERR PFX L_64
L_65 , io_req->xid) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
F_11 ( & V_19 -> V_23 ) ;
return V_41 ;
}
if ( V_2 -> V_211 == 0 ) {
F_21 (KERN_ERR PFX L_64
L_66 , io_req->xid) ;
F_22 ( V_2 , V_212 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
F_11 ( & V_19 -> V_23 ) ;
return V_41 ;
}
F_46 ( & V_2 -> V_81 ) ;
V_2 -> V_211 = 0 ;
F_34 ( & V_2 -> V_81 , & V_19 -> V_213 ) ;
F_68 ( & V_2 -> V_29 ) ;
if ( F_15 ( V_30 , & V_2 -> V_22 ) ) {
F_21 (KERN_ERR PFX L_64
L_67 , io_req->xid) ;
if ( F_82 ( & V_2 -> V_9 ) )
F_16 ( & V_2 -> V_10 ,
V_35 ) ;
V_21 = F_78 ( V_14 , V_2 ) ;
goto V_214;
}
if ( F_82 ( & V_2 -> V_9 ) )
F_16 ( & V_2 -> V_10 ,
V_35 ) ;
F_20 ( V_28 , & V_2 -> V_22 ) ;
V_2 -> V_175 = 1 ;
V_21 = F_19 ( V_2 ) ;
if ( V_21 == V_129 ) {
F_71 ( V_2 ) ;
F_11 ( & V_19 -> V_23 ) ;
F_79 ( & V_2 -> V_29 ) ;
F_8 ( & V_19 -> V_23 ) ;
V_2 -> V_175 = 0 ;
goto V_26;
}
F_11 ( & V_19 -> V_23 ) ;
F_79 ( & V_2 -> V_29 ) ;
F_8 ( & V_19 -> V_23 ) ;
V_2 -> V_175 = 0 ;
if ( ! ( F_15 ( V_32 ,
& V_2 -> V_22 ) ) ) {
F_21 (KERN_ERR PFX L_68 ,
io_req->xid) ;
V_21 = F_78 ( V_14 , V_2 ) ;
goto V_214;
} else {
F_7 ( V_2 , L_69 ) ;
V_21 = V_41 ;
F_22 ( V_2 , V_212 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
}
V_26:
F_16 ( & V_2 -> V_10 , V_35 ) ;
V_214:
F_11 ( & V_19 -> V_23 ) ;
return V_21 ;
}
void F_83 ( struct V_1 * V_196 ,
struct V_141 * V_142 ,
T_1 V_215 )
{
struct V_197 * V_46 = V_196 -> V_46 ;
struct V_1 * V_192 = V_46 -> V_201 ;
T_4 V_193 = V_46 -> V_193 ;
enum V_194 V_195 = V_46 -> V_195 ;
int V_21 = 0 ;
struct V_18 * V_19 = V_192 -> V_19 ;
F_7 ( V_192 , L_70
L_71 ,
V_196 -> V_67 , V_196 -> V_17 ) ;
if ( V_215 == V_216 ) {
F_21 (KERN_ERR PFX L_72 ,
seq_clnp_req->xid) ;
goto V_217;
}
F_11 ( & V_19 -> V_23 ) ;
V_21 = F_84 ( V_192 , V_193 , V_195 ) ;
F_8 ( & V_19 -> V_23 ) ;
if ( V_21 )
F_21 (KERN_ERR PFX L_73
L_74 ) ;
V_196 -> V_46 = NULL ;
F_16 ( & V_192 -> V_10 , V_35 ) ;
V_217:
F_39 ( V_46 ) ;
return;
}
void F_85 ( struct V_1 * V_2 ,
struct V_141 * V_142 ,
T_1 V_218 )
{
F_7 ( V_2 , L_75
L_76 ,
V_2 -> V_10 . V_10 . V_31 , V_2 -> V_17 ) ;
F_22 ( V_2 , V_219 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
if ( V_2 -> V_175 )
F_13 ( & V_2 -> V_29 ) ;
}
void F_86 ( struct V_1 * V_2 ,
struct V_141 * V_142 ,
T_1 V_218 )
{
T_4 V_195 ;
T_4 V_182 = V_220 ;
T_1 V_221 = 0 ;
struct V_18 * V_19 = V_2 -> V_19 ;
F_7 ( V_2 , L_77
L_76 ,
V_2 -> V_67 ,
V_2 -> V_10 . V_10 . V_31 , V_2 -> V_17 ) ;
if ( F_15 ( V_32 ,
& V_2 -> V_22 ) ) {
F_7 ( V_2 , L_78
L_79 ) ;
return;
}
if ( F_15 ( V_222 ,
& V_2 -> V_22 ) )
goto V_223;
if ( F_14 ( V_30 , & V_2 -> V_22 ) )
if ( F_82 ( & V_2 -> V_9 ) )
F_16 ( & V_2 -> V_10 ,
V_35 ) ;
V_195 = ( T_1 ) V_142 -> V_224 . V_225 . V_226 . V_227 . V_195 ;
switch ( V_195 ) {
case V_228 :
F_7 ( V_2 , L_80 ) ;
V_221 = 1 ;
break;
case V_229 :
F_7 ( V_2 , L_81 ) ;
break;
default:
F_21 (KERN_ERR PFX L_82 ) ;
break;
}
if ( V_221 ) {
F_7 ( V_2 , L_83 ) ;
F_20 ( V_24 , & V_2 -> V_22 ) ;
}
F_20 ( V_25 , & V_2 -> V_22 ) ;
F_1 ( V_2 , V_182 ) ;
V_223:
if ( V_2 -> V_175 ) {
if ( F_9 ( V_28 ,
& V_2 -> V_22 ) )
F_13 ( & V_2 -> V_29 ) ;
} else {
if ( V_2 -> V_211 ) {
F_46 ( & V_2 -> V_81 ) ;
V_2 -> V_211 = 0 ;
F_34 ( & V_2 -> V_81 , & V_19 -> V_213 ) ;
}
F_22 ( V_2 , V_219 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
}
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_48 * V_49 = V_2 -> V_49 ;
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_92 * V_93 ;
struct V_92 * V_94 ;
struct V_1 * V_230 ;
int V_231 = V_49 -> V_136 -> V_232 ;
int V_21 = 0 ;
int V_232 ;
F_7 ( V_2 , L_84 ) ;
F_40 (list, tmp, &tgt->active_cmd_queue) {
F_45 ( V_19 , L_85 ) ;
V_230 = (struct V_1 * ) V_93 ;
V_232 = V_230 -> V_49 -> V_136 -> V_232 ;
if ( V_232 == V_231 ) {
if ( ! F_15 ( V_30 ,
& V_230 -> V_22 ) ) {
if ( F_82 ( & V_2 -> V_9 ) )
F_16 ( & V_2 -> V_10 ,
V_35 ) ;
V_21 = F_19 ( V_230 ) ;
F_88 ( V_21 != V_41 ) ;
} else
F_21 (KERN_ERR PFX L_86
L_87 ,
cmd->xid) ;
}
}
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_92 * V_93 ;
struct V_92 * V_94 ;
struct V_1 * V_230 ;
int V_21 = 0 ;
F_7 ( V_2 , L_88 ) ;
F_40 (list, tmp, &tgt->active_cmd_queue) {
F_45 ( V_19 , L_89 ) ;
V_230 = (struct V_1 * ) V_93 ;
if ( ! F_15 ( V_30 ,
& V_230 -> V_22 ) ) {
if ( F_82 ( & V_2 -> V_9 ) )
F_16 ( & V_2 -> V_10 ,
V_35 ) ;
V_21 = F_19 ( V_230 ) ;
F_88 ( V_21 != V_41 ) ;
} else
F_21 (KERN_ERR PFX L_90
L_91 , cmd->xid) ;
}
}
void F_90 ( struct V_1 * V_2 ,
struct V_141 * V_142 , T_1 V_218 )
{
struct V_111 * V_140 ;
struct V_146 * V_147 ;
struct V_48 * V_49 = V_2 -> V_49 ;
V_132 * V_233 ;
V_132 * V_234 ;
void * V_235 ;
F_7 ( V_2 , L_92 ) ;
if ( ! ( F_14 ( V_178 , & V_2 -> V_22 ) ) )
F_20 ( V_177 , & V_2 -> V_22 ) ;
else {
return;
}
V_140 = & ( V_2 -> V_112 ) ;
V_147 = & ( V_140 -> V_236 ) ;
V_233 = ( V_132 * ) V_147 ;
V_234 = ( V_132 * )
& V_142 -> V_224 . V_225 . V_226 . V_237 . V_147 ;
V_233 [ 0 ] = F_91 ( V_234 [ 0 ] ) ;
V_233 [ 1 ] = F_91 ( V_234 [ 1 ] ) ;
V_233 [ 2 ] = F_91 ( V_234 [ 2 ] ) ;
V_140 -> V_238 =
V_142 -> V_224 . V_225 . V_226 . V_237 . V_239 ;
V_235 = V_140 -> V_122 ;
if ( V_147 -> V_240 == V_241 ) {
F_92 ( V_2 ,
(struct V_242 * )
V_235 , V_218 ) ;
if ( V_2 -> V_243 == 0 ) {
if ( V_140 -> V_114 & V_206 )
F_87 ( V_2 ) ;
else if ( V_140 -> V_114 & V_205 )
F_89 ( V_2 ) ;
}
} else {
F_21 (KERN_ERR PFX L_93 ,
fc_hdr->fh_r_ctl) ;
}
if ( ! V_49 -> V_54 . V_55 ) {
F_21 (KERN_ERR PFX L_94 ) ;
return;
}
switch ( V_2 -> V_244 ) {
case V_245 :
if ( V_2 -> V_246 == 0 ) {
V_49 -> V_51 = V_247 << 16 ;
} else {
V_49 -> V_51 = ( V_247 << 16 ) | V_2 -> V_246 ;
}
if ( V_2 -> V_248 )
F_25 ( V_49 , V_2 -> V_248 ) ;
break;
default:
F_7 ( V_2 , L_95 ,
V_2 -> V_244 ) ;
break;
}
V_49 = V_2 -> V_49 ;
V_2 -> V_49 = NULL ;
if ( V_2 -> V_173 ) {
F_46 ( & V_2 -> V_81 ) ;
V_2 -> V_173 = 0 ;
} else {
F_21 (KERN_ERR PFX L_96 ) ;
return;
}
V_49 -> V_54 . V_55 = NULL ;
V_49 -> V_56 ( V_49 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
if ( V_2 -> V_175 ) {
F_7 ( V_2 , L_97 ) ;
F_13 ( & V_2 -> V_29 ) ;
}
}
static int F_93 ( struct V_1 * V_2 , V_132 V_124 , int V_249 ,
int V_250 )
{
struct V_84 * V_251 = V_2 -> V_85 -> V_85 ;
int V_252 , V_253 ;
V_253 = 0 ;
while ( V_249 ) {
if ( V_249 >= V_254 )
V_252 = V_254 ;
else
V_252 = V_249 ;
V_251 [ V_250 + V_253 ] . V_130 = V_124 & 0xffffffff ;
V_251 [ V_250 + V_253 ] . V_131 = V_124 >> 32 ;
V_251 [ V_250 + V_253 ] . V_133 = ( T_2 ) V_252 ;
V_251 [ V_250 + V_253 ] . V_34 = 0 ;
V_124 += ( V_132 ) V_252 ;
V_253 ++ ;
V_249 -= V_252 ;
}
return V_253 ;
}
static int F_94 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
struct V_58 * V_59 = V_5 -> V_59 ;
struct V_48 * V_255 = V_2 -> V_49 ;
struct V_84 * V_251 = V_2 -> V_85 -> V_85 ;
struct V_256 * V_257 ;
int V_258 = 0 ;
int V_259 = 0 ;
int V_260 = 0 ;
int V_253 ;
unsigned int V_249 ;
V_132 V_124 ;
int V_68 ;
V_259 = F_95 ( & V_59 -> V_86 -> V_87 , F_96 ( V_255 ) ,
F_97 ( V_255 ) , V_255 -> V_261 ) ;
F_98 (sc, sg, sg_count, i) {
V_249 = F_99 ( V_257 ) ;
V_124 = F_100 ( V_257 ) ;
if ( V_249 > V_262 ) {
V_253 = F_93 ( V_2 , V_124 , V_249 ,
V_260 ) ;
} else {
V_253 = 1 ;
V_251 [ V_260 ] . V_130 = V_124 & 0xffffffff ;
V_251 [ V_260 ] . V_131 = V_124 >> 32 ;
V_251 [ V_260 ] . V_133 = ( T_2 ) V_249 ;
V_251 [ V_260 ] . V_34 = 0 ;
}
V_260 += V_253 ;
V_258 += V_249 ;
}
if ( V_258 != F_26 ( V_255 ) )
F_21 (KERN_ERR PFX L_98
L_99 , byte_count, scsi_bufflen(sc),
io_req->xid) ;
return V_260 ;
}
static int F_101 ( struct V_1 * V_2 )
{
struct V_48 * V_255 = V_2 -> V_49 ;
struct V_84 * V_251 = V_2 -> V_85 -> V_85 ;
int V_260 ;
if ( F_97 ( V_255 ) ) {
V_260 = F_94 ( V_2 ) ;
if ( V_260 == 0 )
return - V_198 ;
} else {
V_260 = 0 ;
V_251 [ 0 ] . V_130 = V_251 [ 0 ] . V_131 = 0 ;
V_251 [ 0 ] . V_133 = V_251 [ 0 ] . V_34 = 0 ;
}
V_2 -> V_85 -> V_263 = V_260 ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_48 * V_255 = V_2 -> V_49 ;
if ( V_2 -> V_85 -> V_263 && V_255 ) {
F_102 ( V_255 ) ;
V_2 -> V_85 -> V_263 = 0 ;
}
}
void F_64 ( struct V_1 * V_2 ,
struct V_126 * V_126 )
{
struct V_48 * V_49 = V_2 -> V_49 ;
char V_264 [ 2 ] ;
memset ( V_126 , 0 , sizeof( struct V_126 ) ) ;
F_103 ( V_49 -> V_136 -> V_232 , & V_126 -> V_265 ) ;
V_126 -> V_163 = F_104 ( V_2 -> V_127 ) ;
memcpy ( V_126 -> V_161 , V_49 -> V_266 , V_49 -> V_162 ) ;
V_126 -> V_267 = 0 ;
V_126 -> V_268 = 0 ;
V_126 -> V_269 = V_2 -> V_112 . V_114 ;
V_126 -> V_270 = V_2 -> V_160 ;
if ( F_105 ( V_49 , V_264 ) ) {
switch ( V_264 [ 0 ] ) {
case V_271 :
V_126 -> V_268 = V_272 ;
break;
case V_273 :
V_126 -> V_268 = V_274 ;
break;
default:
V_126 -> V_268 = V_275 ;
break;
}
} else {
V_126 -> V_268 = 0 ;
}
}
static void F_92 ( struct V_1 * V_2 ,
struct V_242 * V_276 ,
T_1 V_218 )
{
struct V_48 * V_49 = V_2 -> V_49 ;
struct V_18 * V_19 = V_2 -> V_19 ;
T_1 V_277 = V_276 -> V_278 . V_34 ;
T_4 V_279 = 0 ;
int V_68 ;
unsigned char * V_280 ;
unsigned char * V_281 ;
int V_282 = 0 ;
int V_283 = 0 ;
V_2 -> V_244 = V_245 ;
V_2 -> V_248 = V_276 -> V_248 ;
V_2 -> V_284 = V_277 ;
F_106 ( V_49 ) = V_2 -> V_246 =
V_276 -> V_285 ;
if ( V_218 ) {
if ( V_277 &
V_286 ) {
V_283 = V_279
= V_276 -> V_283 ;
}
if ( V_277 &
V_287 ) {
V_282 = V_276 -> V_282 ;
V_279 += V_276 -> V_282 ;
}
V_2 -> V_283 = V_283 ;
V_2 -> V_282 = V_282 ;
if ( V_279 > V_218 * V_288 ) {
F_21 (KERN_ERR PFX L_100 ,
rq_buff_len) ;
V_279 = V_218 * V_288 ;
}
V_280 = F_107 ( V_19 , 1 ) ;
if ( V_218 > 1 ) {
for ( V_68 = 1 ; V_68 < V_218 ; V_68 ++ )
V_281 = F_107 ( V_19 , 1 ) ;
}
if ( ( V_283 == 4 ) || ( V_283 == 8 ) ) {
V_2 -> V_243 = V_280 [ 3 ] ;
F_21 (KERN_ERR PFX L_101 ,
io_req->fcp_rsp_code) ;
}
V_280 += V_283 ;
if ( V_282 > V_289 ) {
F_21 (KERN_ERR PFX L_102 ) ;
V_282 = V_289 ;
}
memset ( V_49 -> V_290 , 0 , sizeof( V_49 -> V_290 ) ) ;
if ( V_282 )
memcpy ( V_49 -> V_290 , V_280 , V_282 ) ;
for ( V_68 = 0 ; V_68 < V_218 ; V_68 ++ )
F_108 ( V_19 , 1 ) ;
}
}
int F_109 ( struct V_144 * V_145 ,
struct V_48 * V_49 )
{
struct V_13 * V_14 = F_59 ( V_145 ) ;
struct V_134 * V_135 = F_57 ( F_58 ( V_49 -> V_136 ) ) ;
struct V_137 * V_138 = V_135 -> V_139 ;
struct V_18 * V_19 ;
struct V_1 * V_2 ;
int V_21 = 0 ;
int V_291 ;
V_291 = F_110 ( V_135 ) ;
if ( V_291 ) {
V_49 -> V_51 = V_291 ;
V_49 -> V_56 ( V_49 ) ;
return 0 ;
}
if ( ( V_14 -> V_154 != V_155 ) || ! ( V_14 -> V_156 ) ) {
V_21 = V_292 ;
goto V_293;
}
V_19 = (struct V_18 * ) & V_138 [ 1 ] ;
if ( ! F_14 ( V_157 , & V_19 -> V_34 ) ) {
V_21 = V_294 ;
goto V_293;
}
V_2 = F_50 ( V_19 ) ;
if ( ! V_2 ) {
V_21 = V_292 ;
goto V_293;
}
V_2 -> V_49 = V_49 ;
if ( F_111 ( V_19 , V_2 ) ) {
F_21 (KERN_ERR PFX L_103 ) ;
V_21 = V_292 ;
goto V_293;
}
V_293:
return V_21 ;
}
void F_112 ( struct V_1 * V_2 ,
struct V_141 * V_142 ,
T_1 V_218 )
{
struct V_242 * V_276 ;
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_48 * V_49 ;
struct V_144 * V_145 ;
if ( F_15 ( V_40 , & V_2 -> V_22 ) ) {
F_7 ( V_2 , L_104
L_105 ) ;
}
if ( F_82 ( & V_2 -> V_9 ) )
F_16 ( & V_2 -> V_10 ,
V_35 ) ;
V_49 = V_2 -> V_49 ;
if ( V_49 == NULL ) {
F_21 (KERN_ERR PFX L_106 ) ;
return;
}
V_276 = (struct V_242 * )
& ( V_142 -> V_224 . V_225 . V_226 . V_276 . V_295 ) ;
F_92 ( V_2 , V_276 , V_218 ) ;
V_145 = V_49 -> V_136 -> V_145 ;
if ( ! V_49 -> V_54 . V_55 ) {
F_21 (KERN_ERR PFX L_107 ) ;
return;
}
if ( V_2 -> V_211 ) {
F_46 ( & V_2 -> V_81 ) ;
V_2 -> V_211 = 0 ;
F_34 ( & V_2 -> V_81 , & V_19 -> V_213 ) ;
} else {
F_7 ( V_2 , L_108 ) ;
if ( V_2 -> V_175 )
if ( F_9 ( V_28 ,
& V_2 -> V_22 ) )
F_13 ( & V_2 -> V_29 ) ;
}
F_23 ( V_2 ) ;
V_2 -> V_49 = NULL ;
switch ( V_2 -> V_244 ) {
case V_245 :
if ( V_2 -> V_246 == 0 ) {
V_49 -> V_51 = V_247 << 16 ;
} else {
F_7 ( V_2 , L_109
L_110 ,
V_2 -> V_246 , V_2 -> V_248 ) ;
V_49 -> V_51 = ( V_247 << 16 ) | V_2 -> V_246 ;
}
if ( V_2 -> V_248 )
F_25 ( V_49 , V_2 -> V_248 ) ;
break;
default:
F_21 (KERN_ERR PFX L_111 ,
io_req->fcp_status) ;
break;
}
V_49 -> V_54 . V_55 = NULL ;
V_49 -> V_56 ( V_49 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
}
int F_111 ( struct V_18 * V_19 ,
struct V_1 * V_2 )
{
struct V_141 * V_142 ;
struct V_141 * V_143 ;
struct V_48 * V_49 = V_2 -> V_49 ;
struct V_95 * V_6 = V_19 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_58 * V_59 = V_5 -> V_59 ;
struct V_13 * V_14 = V_6 -> V_14 ;
struct V_296 * V_297 ;
int V_148 , V_98 ;
T_2 V_67 ;
V_2 -> V_17 = V_27 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_19 = V_19 ;
V_2 -> V_127 = F_26 ( V_49 ) ;
V_49 -> V_54 . V_55 = ( char * ) V_2 ;
V_297 = F_113 ( V_14 -> V_298 , F_51 () ) ;
if ( V_49 -> V_261 == V_299 ) {
V_2 -> V_160 = V_300 ;
V_297 -> V_301 ++ ;
V_297 -> V_302 += V_2 -> V_127 ;
} else if ( V_49 -> V_261 == V_303 ) {
V_2 -> V_160 = V_304 ;
V_297 -> V_305 ++ ;
V_297 -> V_306 += V_2 -> V_127 ;
} else {
V_2 -> V_160 = 0 ;
V_297 -> V_307 ++ ;
}
F_52 () ;
V_67 = V_2 -> V_67 ;
if ( F_101 ( V_2 ) ) {
F_21 (KERN_ERR PFX L_112 ) ;
F_8 ( & V_19 -> V_23 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
F_11 ( & V_19 -> V_23 ) ;
return - V_308 ;
}
V_148 = V_67 / V_171 ;
V_98 = V_67 % V_171 ;
V_143 = (struct V_141 * ) V_59 -> V_172 [ V_148 ] ;
V_142 = & ( V_143 [ V_98 ] ) ;
F_114 ( V_2 , V_142 ) ;
F_8 ( & V_19 -> V_23 ) ;
if ( V_19 -> V_210 ) {
F_21 (KERN_ERR PFX L_113 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
F_11 ( & V_19 -> V_23 ) ;
return - V_308 ;
}
if ( ! F_14 ( V_157 , & V_19 -> V_34 ) ) {
F_21 (KERN_ERR PFX L_114 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
F_11 ( & V_19 -> V_23 ) ;
return - V_308 ;
}
if ( V_19 -> V_309 )
F_1 ( V_2 , V_310 ) ;
F_67 ( V_19 , V_67 ) ;
V_2 -> V_211 = 1 ;
F_34 ( & V_2 -> V_81 , & V_19 -> V_311 ) ;
F_69 ( V_19 ) ;
F_11 ( & V_19 -> V_23 ) ;
return 0 ;
}
