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
struct V_57 * F_27 ( struct V_58 * V_59 )
{
struct V_57 * V_60 ;
struct V_61 * V_62 ;
struct V_1 * V_2 ;
T_2 V_63 ;
T_3 V_64 ;
T_4 V_65 ;
int V_66 ;
int V_67 , V_68 ;
T_2 V_69 ;
int V_70 = F_28 () + 1 ;
T_4 V_71 = V_72 ;
T_4 V_73 = V_59 -> V_73 ;
if ( V_73 <= V_71 || V_73 == V_74 ) {
F_21 (KERN_ERR PFX L_22 , min_xid, max_xid) ;
return NULL ;
}
F_29 ( L_23 , V_71 , V_73 ) ;
V_67 = V_73 - V_71 + 1 ;
V_63 = ( V_67 * ( sizeof( struct V_1 * ) ) ) ;
V_63 += sizeof( struct V_57 ) ;
V_60 = F_30 ( V_63 , V_75 ) ;
if ( ! V_60 ) {
F_21 (KERN_ERR PFX L_24 ) ;
return NULL ;
}
V_60 -> V_76 = F_30 ( sizeof( * V_60 -> V_76 ) *
V_70 , V_75 ) ;
if ( ! V_60 -> V_76 ) {
F_21 (KERN_ERR PFX L_25 ) ;
goto V_77;
}
V_60 -> V_78 = F_30 ( sizeof( * V_60 -> V_78 ) *
V_70 , V_75 ) ;
if ( ! V_60 -> V_78 ) {
F_21 (KERN_ERR PFX L_26 ) ;
F_31 ( V_60 -> V_76 ) ;
V_60 -> V_76 = NULL ;
goto V_77;
}
V_60 -> V_59 = V_59 ;
V_60 -> V_79 = (struct V_1 * * ) ( V_60 + 1 ) ;
for ( V_66 = 0 ; V_66 < V_70 ; V_66 ++ ) {
F_32 ( & V_60 -> V_76 [ V_66 ] ) ;
F_33 ( & V_60 -> V_78 [ V_66 ] ) ;
}
V_65 = V_72 ;
V_68 = V_67 - V_59 -> V_80 ;
for ( V_66 = 0 ; V_66 < V_67 ; V_66 ++ ) {
V_2 = F_30 ( sizeof( * V_2 ) , V_75 ) ;
if ( ! V_2 ) {
F_21 (KERN_ERR PFX L_27 ) ;
goto V_77;
}
F_32 ( & V_2 -> V_81 ) ;
F_34 ( & V_2 -> V_9 , F_5 ) ;
V_2 -> V_65 = V_65 ++ ;
if ( V_66 < V_68 )
F_35 ( & V_2 -> V_81 ,
& V_60 -> V_76 [ V_2 -> V_65 %
F_28 () ] ) ;
else
F_35 ( & V_2 -> V_81 ,
& V_60 -> V_76 [ F_28 () ] ) ;
V_2 ++ ;
}
V_64 = V_67 * sizeof( struct V_61 * ) ;
V_60 -> V_82 = F_36 ( V_64 , V_75 ) ;
if ( ! V_60 -> V_82 ) {
F_21 (KERN_ERR PFX L_28 ) ;
goto V_77;
}
V_64 = sizeof( struct V_61 ) ;
for ( V_66 = 0 ; V_66 < V_67 ; V_66 ++ ) {
V_60 -> V_82 [ V_66 ] = F_36 ( V_64 , V_75 ) ;
if ( ! V_60 -> V_82 [ V_66 ] ) {
F_21 (KERN_ERR PFX L_29
L_30 , i) ;
goto V_77;
}
}
V_69 = V_83 * sizeof( struct V_84 ) ;
for ( V_66 = 0 ; V_66 < V_67 ; V_66 ++ ) {
V_62 = V_60 -> V_82 [ V_66 ] ;
V_62 -> V_85 = F_37 ( & V_59 -> V_86 -> V_87 ,
V_69 ,
& V_62 -> V_88 ,
V_75 ) ;
if ( ! V_62 -> V_85 ) {
F_21 (KERN_ERR PFX L_29
L_31 , i) ;
goto V_77;
}
}
return V_60 ;
V_77:
F_38 ( V_60 ) ;
return NULL ;
}
void F_38 ( struct V_57 * V_60 )
{
struct V_61 * V_62 ;
struct V_58 * V_59 = V_60 -> V_59 ;
T_2 V_69 ;
T_4 V_71 = V_72 ;
T_4 V_73 = V_59 -> V_73 ;
int V_67 ;
int V_66 ;
V_67 = V_73 - V_71 + 1 ;
if ( ! V_60 -> V_82 )
goto V_89;
V_69 = V_83 * sizeof( struct V_84 ) ;
for ( V_66 = 0 ; V_66 < V_67 ; V_66 ++ ) {
V_62 = V_60 -> V_82 [ V_66 ] ;
if ( V_62 -> V_85 ) {
F_39 ( & V_59 -> V_86 -> V_87 , V_69 ,
V_62 -> V_85 ,
V_62 -> V_88 ) ;
V_62 -> V_85 = NULL ;
}
}
for ( V_66 = 0 ; V_66 < V_67 ; V_66 ++ ) {
F_31 ( V_60 -> V_82 [ V_66 ] ) ;
V_60 -> V_82 [ V_66 ] = NULL ;
}
F_31 ( V_60 -> V_82 ) ;
V_60 -> V_82 = NULL ;
V_89:
F_31 ( V_60 -> V_78 ) ;
if ( ! V_60 -> V_76 )
goto V_90;
for ( V_66 = 0 ; V_66 < F_28 () + 1 ; V_66 ++ ) {
struct V_1 * V_91 , * V_2 ;
F_40 (io_req, tmp,
&cmgr->free_list[i], link) {
F_41 ( & V_2 -> V_81 ) ;
F_31 ( V_2 ) ;
}
}
F_31 ( V_60 -> V_76 ) ;
V_90:
F_31 ( V_60 ) ;
}
struct V_1 * F_42 ( struct V_18 * V_19 , int type )
{
struct V_92 * V_6 = V_19 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_57 * V_93 = V_5 -> V_59 -> V_93 ;
struct V_1 * V_2 ;
struct V_94 * V_95 ;
struct V_61 * V_85 ;
int V_96 = V_97 ;
T_3 V_98 ;
T_3 V_99 ;
T_4 V_65 ;
V_99 = V_19 -> V_99 ;
switch ( type ) {
case V_100 :
V_99 = V_101 ;
break;
case V_42 :
V_99 = V_102 ;
break;
default:
break;
}
F_8 ( & V_93 -> V_78 [ V_96 ] ) ;
V_98 = F_43 ( & V_19 -> V_98 ) ;
if ( ( F_44 ( & ( V_93 -> V_76 [ V_96 ] ) ) ) ||
( V_19 -> V_103 . V_31 >= V_99 ) ||
( V_98 + V_99 <= V_104 ) ) {
F_45 ( V_19 , L_32
L_33 ,
V_19 -> V_103 . V_31 , V_19 -> V_99 ) ;
if ( F_44 ( & ( V_93 -> V_76 [ V_96 ] ) ) )
F_21 (KERN_ERR PFX L_34 ) ;
F_11 ( & V_93 -> V_78 [ V_96 ] ) ;
return NULL ;
}
V_95 = (struct V_94 * )
V_93 -> V_76 [ V_96 ] . V_105 ;
F_46 ( V_95 ) ;
V_2 = (struct V_1 * ) V_95 ;
V_65 = V_2 -> V_65 ;
V_93 -> V_79 [ V_65 ] = V_2 ;
F_47 ( & V_19 -> V_103 ) ;
F_48 ( & V_19 -> V_98 ) ;
F_11 ( & V_93 -> V_78 [ V_96 ] ) ;
F_32 ( & V_2 -> V_81 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_93 = V_93 ;
V_2 -> V_22 = 0 ;
V_2 -> V_17 = type ;
V_85 = V_2 -> V_85 = V_93 -> V_82 [ V_65 ] ;
V_85 -> V_2 = V_2 ;
F_49 ( & V_2 -> V_10 ) ;
return V_2 ;
}
struct V_1 * F_50 ( struct V_18 * V_19 )
{
struct V_92 * V_6 = V_19 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_57 * V_93 = V_5 -> V_59 -> V_93 ;
struct V_1 * V_2 ;
struct V_94 * V_95 ;
struct V_61 * V_85 ;
T_3 V_98 ;
T_3 V_99 ;
T_4 V_65 ;
int V_96 = F_51 () ;
V_99 = V_106 ;
F_8 ( & V_93 -> V_78 [ V_96 ] ) ;
V_98 = F_43 ( & V_19 -> V_98 ) ;
if ( ( F_44 ( & V_93 -> V_76 [ V_96 ] ) ) ||
( V_19 -> V_103 . V_31 >= V_99 ) ||
( V_98 + V_99 <= V_104 ) ) {
F_11 ( & V_93 -> V_78 [ V_96 ] ) ;
F_52 () ;
return NULL ;
}
V_95 = (struct V_94 * )
V_93 -> V_76 [ V_96 ] . V_105 ;
F_46 ( V_95 ) ;
V_2 = (struct V_1 * ) V_95 ;
V_65 = V_2 -> V_65 ;
V_93 -> V_79 [ V_65 ] = V_2 ;
F_47 ( & V_19 -> V_103 ) ;
F_48 ( & V_19 -> V_98 ) ;
F_11 ( & V_93 -> V_78 [ V_96 ] ) ;
F_52 () ;
F_32 ( & V_2 -> V_81 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_93 = V_93 ;
V_2 -> V_22 = 0 ;
V_85 = V_2 -> V_85 = V_93 -> V_82 [ V_65 ] ;
V_85 -> V_2 = V_2 ;
F_49 ( & V_2 -> V_10 ) ;
return V_2 ;
}
void V_35 ( struct V_107 * V_108 )
{
struct V_1 * V_2 = F_6 ( V_108 ,
struct V_1 , V_10 ) ;
struct V_57 * V_93 = V_2 -> V_93 ;
int V_96 ;
if ( V_2 -> V_17 == V_27 )
V_96 = V_2 -> V_65 % F_28 () ;
else
V_96 = V_97 ;
F_8 ( & V_93 -> V_78 [ V_96 ] ) ;
if ( V_2 -> V_17 != V_27 )
F_53 ( V_2 ) ;
V_93 -> V_79 [ V_2 -> V_65 ] = NULL ;
F_46 ( & V_2 -> V_81 ) ;
F_54 ( & V_2 -> V_81 ,
& V_93 -> V_76 [ V_96 ] ) ;
F_48 ( & V_2 -> V_19 -> V_103 ) ;
F_11 ( & V_93 -> V_78 [ V_96 ] ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_109 * V_110 = & ( V_2 -> V_110 ) ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
struct V_58 * V_59 = V_5 -> V_59 ;
T_2 V_111 = sizeof( struct V_84 ) ;
V_110 -> V_112 = 0 ;
if ( V_110 -> V_113 ) {
F_39 ( & V_59 -> V_86 -> V_87 , V_111 ,
V_110 -> V_113 ,
V_110 -> V_114 ) ;
V_110 -> V_113 = NULL ;
}
if ( V_110 -> V_115 ) {
F_39 ( & V_59 -> V_86 -> V_87 , V_111 ,
V_110 -> V_115 ,
V_110 -> V_116 ) ;
V_110 -> V_115 = NULL ;
}
if ( V_110 -> V_117 ) {
F_39 ( & V_59 -> V_86 -> V_87 , V_118 ,
V_110 -> V_117 ,
V_110 -> V_119 ) ;
V_110 -> V_117 = NULL ;
}
if ( V_110 -> V_120 ) {
F_39 ( & V_59 -> V_86 -> V_87 , V_118 ,
V_110 -> V_120 ,
V_110 -> V_121 ) ;
V_110 -> V_120 = NULL ;
}
}
int F_55 ( struct V_1 * V_2 )
{
struct V_109 * V_110 ;
struct V_84 * V_113 ;
struct V_84 * V_115 ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
struct V_58 * V_59 = V_5 -> V_59 ;
T_5 V_122 ;
T_2 V_111 ;
V_110 = (struct V_109 * ) & ( V_2 -> V_110 ) ;
memset ( V_110 , 0 , sizeof( struct V_109 ) ) ;
V_110 -> V_123 = sizeof( struct V_124 ) ;
V_2 -> V_125 = V_110 -> V_123 ;
V_110 -> V_117 = F_37 ( & V_59 -> V_86 -> V_87 , V_118 ,
& V_110 -> V_119 ,
V_126 ) ;
if ( ! V_110 -> V_117 ) {
F_21 (KERN_ERR PFX L_35 ) ;
F_53 ( V_2 ) ;
return V_127 ;
}
V_110 -> V_120 = F_37 ( & V_59 -> V_86 -> V_87 , V_118 ,
& V_110 -> V_121 ,
V_126 ) ;
if ( ! V_110 -> V_120 ) {
F_21 (KERN_ERR PFX L_36 ) ;
F_53 ( V_2 ) ;
return V_127 ;
}
memset ( V_110 -> V_117 , 0 , V_118 ) ;
memset ( V_110 -> V_120 , 0 , V_118 ) ;
V_111 = sizeof( struct V_84 ) ;
V_110 -> V_113 = F_37 ( & V_59 -> V_86 -> V_87 , V_111 ,
& V_110 -> V_114 ,
V_126 ) ;
if ( ! V_110 -> V_113 ) {
F_21 (KERN_ERR PFX L_37 ) ;
F_53 ( V_2 ) ;
return V_127 ;
}
V_110 -> V_115 = F_37 ( & V_59 -> V_86 -> V_87 , V_111 ,
& V_110 -> V_116 ,
V_126 ) ;
if ( ! V_110 -> V_115 ) {
F_21 (KERN_ERR PFX L_38 ) ;
F_53 ( V_2 ) ;
return V_127 ;
}
V_122 = V_110 -> V_119 ;
V_113 = V_110 -> V_113 ;
V_113 -> V_128 = ( T_3 ) V_122 & 0xffffffff ;
V_113 -> V_129 = ( T_3 ) ( ( V_130 ) V_122 >> 32 ) ;
V_113 -> V_131 = V_118 ;
V_113 -> V_34 = 0 ;
V_115 = V_110 -> V_115 ;
V_122 = V_110 -> V_121 ;
V_115 -> V_128 = ( T_3 ) V_122 & 0xffffffff ;
V_115 -> V_129 = ( T_3 ) ( ( V_130 ) V_122 >> 32 ) ;
V_115 -> V_131 = V_118 ;
V_115 -> V_34 = 0 ;
return V_41 ;
}
static int F_56 ( struct V_48 * V_49 , T_1 V_112 )
{
struct V_13 * V_14 ;
struct V_132 * V_133 ;
struct V_134 * V_135 ;
struct V_92 * V_6 ;
struct V_4 * V_5 ;
struct V_18 * V_19 ;
struct V_1 * V_2 ;
struct V_109 * V_136 ;
struct V_137 * V_138 ;
struct V_137 * V_139 ;
struct V_140 * V_141 = V_49 -> V_142 -> V_141 ;
struct V_143 * V_144 ;
struct V_124 * V_124 ;
int V_145 , V_96 ;
int V_21 = V_41 ;
T_4 V_65 ;
T_3 V_146 , V_147 ;
unsigned long V_148 = V_149 ;
V_14 = F_57 ( V_141 ) ;
V_133 = F_58 ( F_59 ( V_49 -> V_142 ) ) ;
V_6 = F_60 ( V_14 ) ;
V_5 = V_6 -> V_7 ;
if ( V_133 == NULL ) {
F_21 (KERN_ERR PFX L_39 ) ;
V_21 = V_127 ;
goto V_150;
}
V_135 = V_133 -> V_151 ;
V_21 = F_61 ( V_49 ) ;
if ( V_21 )
return V_21 ;
if ( V_14 -> V_152 != V_153 || ! ( V_14 -> V_154 ) ) {
F_21 (KERN_ERR PFX L_40 ) ;
V_21 = V_127 ;
goto V_150;
}
V_19 = (struct V_18 * ) & V_135 [ 1 ] ;
if ( ! ( F_14 ( V_155 , & V_19 -> V_34 ) ) ) {
F_21 (KERN_ERR PFX L_41 ) ;
V_21 = V_127 ;
goto V_150;
}
V_156:
V_2 = F_42 ( V_19 , V_100 ) ;
if ( ! V_2 ) {
if ( F_62 ( V_149 , V_148 + V_157 ) ) {
F_21 (KERN_ERR PFX L_42 ) ;
V_21 = V_127 ;
goto V_150;
}
F_63 ( 20 ) ;
goto V_156;
}
V_2 -> V_49 = V_49 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_19 = V_19 ;
V_136 = (struct V_109 * ) & ( V_2 -> V_110 ) ;
V_21 = F_55 ( V_2 ) ;
if ( V_21 == V_127 ) {
F_21 (KERN_ERR PFX L_43 ) ;
F_8 ( & V_19 -> V_23 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
F_11 ( & V_19 -> V_23 ) ;
goto V_150;
}
V_2 -> V_158 = 0 ;
V_136 -> V_112 = V_112 ;
F_64 ( V_2 , (struct V_124 * ) V_136 -> V_117 ) ;
V_124 = (struct V_124 * ) V_136 -> V_117 ;
memset ( V_124 -> V_159 , 0 , V_49 -> V_160 ) ;
V_124 -> V_161 = 0 ;
V_144 = & ( V_136 -> V_162 ) ;
V_146 = V_19 -> V_146 ;
V_147 = V_133 -> V_163 ;
F_65 ( V_144 , V_164 , V_147 , V_146 ,
V_165 , V_166 | V_167 |
V_168 , 0 ) ;
V_65 = V_2 -> V_65 ;
F_45 ( V_19 , L_44 , V_65 ) ;
V_145 = V_65 / V_169 ;
V_96 = V_65 % V_169 ;
V_139 = (struct V_137 * )
V_5 -> V_59 -> V_170 [ V_145 ] ;
V_138 = & ( V_139 [ V_96 ] ) ;
F_66 ( V_2 , V_138 ) ;
V_49 -> V_54 . V_55 = ( char * ) V_2 ;
F_8 ( & V_19 -> V_23 ) ;
F_67 ( V_19 , V_65 ) ;
V_2 -> V_171 = 1 ;
F_35 ( & V_2 -> V_81 , & V_19 -> V_172 ) ;
F_68 ( & V_2 -> V_29 ) ;
V_2 -> V_173 = 1 ;
F_69 ( V_19 ) ;
F_11 ( & V_19 -> V_23 ) ;
V_21 = F_70 ( & V_2 -> V_29 ,
V_174 * V_157 ) ;
F_8 ( & V_19 -> V_23 ) ;
V_2 -> V_173 = 0 ;
if ( ! ( F_14 ( V_175 , & V_2 -> V_22 ) ) ) {
F_20 ( V_176 , & V_2 -> V_22 ) ;
if ( V_2 -> V_171 ) {
F_46 ( & V_2 -> V_81 ) ;
V_2 -> V_171 = 0 ;
}
V_2 -> V_173 = 1 ;
F_71 ( V_2 ) ;
F_11 ( & V_19 -> V_23 ) ;
V_21 = F_70 ( & V_2 -> V_29 ,
V_177 ) ;
F_8 ( & V_19 -> V_23 ) ;
V_2 -> V_173 = 0 ;
if ( ! V_21 )
F_16 ( & V_2 -> V_10 , V_35 ) ;
}
F_11 ( & V_19 -> V_23 ) ;
if ( ! V_21 ) {
F_45 ( V_19 , L_45 ) ;
V_21 = V_127 ;
} else {
F_45 ( V_19 , L_46 ) ;
V_21 = V_41 ;
}
V_150:
return V_21 ;
}
int F_19 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_132 * V_133 = V_19 -> V_133 ;
struct V_15 * V_16 = V_19 -> V_16 ;
struct V_4 * V_5 ;
struct V_92 * V_6 ;
struct V_1 * V_178 ;
struct V_137 * V_138 ;
struct V_137 * V_139 ;
struct V_143 * V_144 ;
struct V_109 * V_179 ;
int V_145 , V_96 ;
T_3 V_146 , V_147 ;
T_4 V_65 ;
int V_21 = V_41 ;
T_3 V_180 = V_16 -> V_180 ;
F_7 ( V_2 , L_47 ) ;
V_6 = V_2 -> V_6 ;
V_5 = V_6 -> V_7 ;
V_14 = V_6 -> V_14 ;
if ( ! F_14 ( V_155 , & V_19 -> V_34 ) ) {
F_21 (KERN_ERR PFX L_48 ) ;
V_21 = V_127 ;
goto V_181;
}
if ( V_133 == NULL ) {
F_21 (KERN_ERR PFX L_49 ) ;
V_21 = V_127 ;
goto V_181;
}
if ( V_14 -> V_152 != V_153 || ! ( V_14 -> V_154 ) ) {
F_21 (KERN_ERR PFX L_50 ) ;
V_21 = V_127 ;
goto V_181;
}
V_178 = F_42 ( V_19 , V_182 ) ;
if ( ! V_178 ) {
F_21 (KERN_ERR PFX L_51 ) ;
V_21 = V_127 ;
goto V_181;
}
V_178 -> V_49 = NULL ;
V_178 -> V_6 = V_6 ;
V_178 -> V_19 = V_19 ;
V_178 -> V_125 = 0 ;
V_179 = (struct V_109 * ) & ( V_178 -> V_110 ) ;
memset ( V_179 , 0 , sizeof( struct V_109 ) ) ;
V_144 = & ( V_179 -> V_162 ) ;
V_144 -> V_183 = F_72 ( V_2 -> V_65 ) ;
V_144 -> V_184 = F_72 ( V_2 -> V_138 -> V_185 . V_186 . V_187 ) ;
V_146 = V_19 -> V_146 ;
V_147 = V_133 -> V_163 ;
F_65 ( V_144 , V_188 , V_147 , V_146 ,
V_189 , V_166 | V_167 |
V_168 , 0 ) ;
V_65 = V_178 -> V_65 ;
F_7 ( V_178 , L_52 ) ;
V_145 = V_65 / V_169 ;
V_96 = V_65 % V_169 ;
V_139 = (struct V_137 * )
V_5 -> V_59 -> V_170 [ V_145 ] ;
V_138 = & ( V_139 [ V_96 ] ) ;
F_66 ( V_178 , V_138 ) ;
F_1 ( V_2 , 2 * V_180 ) ;
F_67 ( V_19 , V_65 ) ;
F_69 ( V_19 ) ;
V_181:
return V_21 ;
}
int F_73 ( struct V_1 * V_190 , T_3 V_191 ,
enum V_192 V_193 )
{
struct V_13 * V_14 ;
struct V_18 * V_19 = V_190 -> V_19 ;
struct V_4 * V_5 ;
struct V_92 * V_6 ;
struct V_1 * V_194 ;
struct V_137 * V_138 ;
struct V_137 * V_139 ;
struct V_195 * V_46 = NULL ;
int V_145 , V_96 ;
T_4 V_65 ;
int V_21 = 0 ;
F_7 ( V_190 , L_53 ,
V_190 -> V_65 ) ;
F_4 ( & V_190 -> V_10 ) ;
V_6 = V_190 -> V_6 ;
V_5 = V_6 -> V_7 ;
V_14 = V_6 -> V_14 ;
V_46 = F_30 ( sizeof( struct V_195 ) , V_126 ) ;
if ( ! V_46 ) {
F_21 (KERN_ERR PFX L_54 ) ;
V_21 = - V_196 ;
goto V_197;
}
V_194 = F_42 ( V_19 , V_198 ) ;
if ( ! V_194 ) {
F_21 (KERN_ERR PFX L_55 ) ;
V_21 = - V_196 ;
F_31 ( V_46 ) ;
goto V_197;
}
V_194 -> V_49 = NULL ;
V_194 -> V_6 = V_6 ;
V_194 -> V_19 = V_19 ;
V_194 -> V_125 = 0 ;
V_65 = V_194 -> V_65 ;
V_145 = V_65 / V_169 ;
V_96 = V_65 % V_169 ;
V_139 = (struct V_137 * )
V_5 -> V_59 -> V_170 [ V_145 ] ;
V_138 = & ( V_139 [ V_96 ] ) ;
V_46 -> V_199 = V_190 ;
V_46 -> V_2 = V_194 ;
V_46 -> V_193 = V_193 ;
V_46 -> V_191 = V_191 ;
V_194 -> V_46 = V_46 ;
F_21 (KERN_ERR PFX L_56 ) ;
F_74 ( V_194 , V_138 , V_190 , V_191 ) ;
F_67 ( V_19 , V_65 ) ;
F_69 ( V_19 ) ;
V_197:
return V_21 ;
}
int F_71 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_4 * V_5 ;
struct V_92 * V_6 ;
struct V_1 * V_200 ;
struct V_137 * V_138 ;
struct V_137 * V_139 ;
int V_145 , V_96 ;
T_4 V_65 , V_201 ;
int V_21 = 0 ;
F_7 ( V_2 , L_57 ) ;
V_6 = V_2 -> V_6 ;
V_5 = V_6 -> V_7 ;
V_14 = V_6 -> V_14 ;
V_200 = F_42 ( V_19 , V_202 ) ;
if ( ! V_200 ) {
F_21 (KERN_ERR PFX L_55 ) ;
V_21 = - 1 ;
goto V_197;
}
V_200 -> V_49 = NULL ;
V_200 -> V_6 = V_6 ;
V_200 -> V_19 = V_19 ;
V_200 -> V_125 = 0 ;
V_65 = V_200 -> V_65 ;
V_145 = V_65 / V_169 ;
V_96 = V_65 % V_169 ;
V_139 = (struct V_137 * )
V_5 -> V_59 -> V_170 [ V_145 ] ;
V_138 = & ( V_139 [ V_96 ] ) ;
V_201 = V_2 -> V_65 ;
F_7 ( V_2 , L_58 , V_65 ) ;
F_75 ( V_200 , V_138 , V_201 ) ;
F_67 ( V_19 , V_65 ) ;
F_69 ( V_19 ) ;
V_197:
return V_21 ;
}
int F_76 ( struct V_48 * V_49 )
{
return F_56 ( V_49 , V_203 ) ;
}
int F_77 ( struct V_48 * V_49 )
{
return F_56 ( V_49 , V_204 ) ;
}
int F_78 ( struct V_13 * V_14 , struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_15 * V_16 = V_19 -> V_16 ;
int V_20 ;
int V_21 = V_41 ;
int V_205 = 0 ;
F_7 ( V_2 , L_59 ,
V_19 -> V_34 ) ;
V_20 = F_15 ( V_33 ,
& V_19 -> V_34 ) ;
V_2 -> V_173 = 1 ;
F_71 ( V_2 ) ;
F_11 ( & V_19 -> V_23 ) ;
F_79 ( & V_2 -> V_29 ) ;
V_2 -> V_173 = 0 ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
if ( ! V_20 ) {
F_10 ( V_155 , & V_19 -> V_34 ) ;
F_17 ( & V_14 -> V_36 . V_37 ) ;
V_14 -> V_38 . V_39 ( V_16 ) ;
F_18 ( & V_14 -> V_36 . V_37 ) ;
do {
F_63 ( V_206 ) ;
if ( V_205 ++ > V_207 ) {
V_21 = V_127 ;
break;
}
} while ( ! F_14 ( V_155 , & V_19 -> V_34 ) );
}
F_8 ( & V_19 -> V_23 ) ;
return V_21 ;
}
int F_80 ( struct V_48 * V_49 )
{
struct V_132 * V_133 = F_58 ( F_59 ( V_49 -> V_142 ) ) ;
struct V_134 * V_135 = V_133 -> V_151 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
struct V_18 * V_19 ;
int V_21 = V_127 ;
V_21 = F_61 ( V_49 ) ;
if ( V_21 )
return V_21 ;
V_14 = F_57 ( V_49 -> V_142 -> V_141 ) ;
if ( ( V_14 -> V_152 != V_153 ) || ! ( V_14 -> V_154 ) ) {
F_21 (KERN_ERR PFX L_60 ) ;
return V_21 ;
}
V_19 = (struct V_18 * ) & V_135 [ 1 ] ;
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
if ( V_19 -> V_208 ) {
F_21 (KERN_ERR PFX L_64
L_65 , io_req->xid) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
F_11 ( & V_19 -> V_23 ) ;
return V_41 ;
}
if ( V_2 -> V_209 == 0 ) {
F_21 (KERN_ERR PFX L_64
L_66 , io_req->xid) ;
F_22 ( V_2 , V_210 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
F_11 ( & V_19 -> V_23 ) ;
return V_41 ;
}
F_46 ( & V_2 -> V_81 ) ;
V_2 -> V_209 = 0 ;
F_35 ( & V_2 -> V_81 , & V_19 -> V_211 ) ;
F_68 ( & V_2 -> V_29 ) ;
if ( F_15 ( V_30 , & V_2 -> V_22 ) ) {
F_21 (KERN_ERR PFX L_64
L_67 , io_req->xid) ;
if ( F_82 ( & V_2 -> V_9 ) )
F_16 ( & V_2 -> V_10 ,
V_35 ) ;
V_21 = F_78 ( V_14 , V_2 ) ;
F_20 ( V_212 , & V_2 -> V_22 ) ;
goto V_213;
}
if ( F_82 ( & V_2 -> V_9 ) )
F_16 ( & V_2 -> V_10 ,
V_35 ) ;
F_20 ( V_28 , & V_2 -> V_22 ) ;
V_2 -> V_173 = 1 ;
V_21 = F_19 ( V_2 ) ;
if ( V_21 == V_127 ) {
F_71 ( V_2 ) ;
F_11 ( & V_19 -> V_23 ) ;
F_79 ( & V_2 -> V_29 ) ;
F_8 ( & V_19 -> V_23 ) ;
V_2 -> V_173 = 0 ;
goto V_26;
}
F_11 ( & V_19 -> V_23 ) ;
F_79 ( & V_2 -> V_29 ) ;
F_8 ( & V_19 -> V_23 ) ;
V_2 -> V_173 = 0 ;
if ( F_14 ( V_40 , & V_2 -> V_22 ) ) {
F_7 ( V_2 , L_68 ) ;
V_21 = V_41 ;
} else if ( ! ( F_15 ( V_32 ,
& V_2 -> V_22 ) ) ) {
F_21 (KERN_ERR PFX L_69 ,
io_req->xid) ;
V_21 = F_78 ( V_14 , V_2 ) ;
goto V_213;
} else {
F_7 ( V_2 , L_70 ) ;
V_21 = V_41 ;
F_22 ( V_2 , V_210 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
}
V_26:
F_16 ( & V_2 -> V_10 , V_35 ) ;
V_213:
F_11 ( & V_19 -> V_23 ) ;
return V_21 ;
}
void F_83 ( struct V_1 * V_194 ,
struct V_137 * V_138 ,
T_1 V_214 )
{
struct V_195 * V_46 = V_194 -> V_46 ;
struct V_1 * V_190 = V_46 -> V_199 ;
T_3 V_191 = V_46 -> V_191 ;
enum V_192 V_193 = V_46 -> V_193 ;
int V_21 = 0 ;
struct V_18 * V_19 = V_190 -> V_19 ;
F_7 ( V_190 , L_71
L_72 ,
V_194 -> V_65 , V_194 -> V_17 ) ;
if ( V_214 == V_215 ) {
F_21 (KERN_ERR PFX L_73 ,
seq_clnp_req->xid) ;
goto V_216;
}
F_11 ( & V_19 -> V_23 ) ;
V_21 = F_84 ( V_190 , V_191 , V_193 ) ;
F_8 ( & V_19 -> V_23 ) ;
if ( V_21 )
F_21 (KERN_ERR PFX L_74
L_75 ) ;
V_194 -> V_46 = NULL ;
F_16 ( & V_190 -> V_10 , V_35 ) ;
V_216:
F_31 ( V_46 ) ;
return;
}
void F_85 ( struct V_1 * V_2 ,
struct V_137 * V_138 ,
T_1 V_217 )
{
F_7 ( V_2 , L_76
L_77 ,
V_2 -> V_10 . V_10 . V_31 , V_2 -> V_17 ) ;
F_22 ( V_2 , V_218 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
if ( V_2 -> V_173 )
F_13 ( & V_2 -> V_29 ) ;
}
void F_86 ( struct V_1 * V_2 ,
struct V_137 * V_138 ,
T_1 V_217 )
{
T_3 V_193 ;
T_3 V_180 = V_219 ;
T_1 V_220 = 0 ;
struct V_18 * V_19 = V_2 -> V_19 ;
F_7 ( V_2 , L_78
L_77 ,
V_2 -> V_65 ,
V_2 -> V_10 . V_10 . V_31 , V_2 -> V_17 ) ;
if ( F_15 ( V_32 ,
& V_2 -> V_22 ) ) {
F_7 ( V_2 , L_79
L_80 ) ;
return;
}
if ( F_15 ( V_212 ,
& V_2 -> V_22 ) )
goto V_221;
if ( F_14 ( V_30 , & V_2 -> V_22 ) )
if ( F_82 ( & V_2 -> V_9 ) )
F_16 ( & V_2 -> V_10 ,
V_35 ) ;
V_193 = ( T_1 ) V_138 -> V_222 . V_223 . V_224 . V_225 . V_193 ;
switch ( V_193 ) {
case V_226 :
F_7 ( V_2 , L_81 ) ;
V_220 = 1 ;
break;
case V_227 :
F_7 ( V_2 , L_82 ) ;
break;
default:
F_21 (KERN_ERR PFX L_83 ) ;
break;
}
if ( V_220 ) {
F_7 ( V_2 , L_84 ) ;
F_20 ( V_24 , & V_2 -> V_22 ) ;
}
F_20 ( V_25 , & V_2 -> V_22 ) ;
F_1 ( V_2 , V_180 ) ;
V_221:
if ( V_2 -> V_173 ) {
if ( F_9 ( V_28 ,
& V_2 -> V_22 ) )
F_13 ( & V_2 -> V_29 ) ;
} else {
if ( V_2 -> V_209 ) {
F_46 ( & V_2 -> V_81 ) ;
V_2 -> V_209 = 0 ;
F_35 ( & V_2 -> V_81 , & V_19 -> V_211 ) ;
}
F_22 ( V_2 , V_218 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
}
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_48 * V_49 = V_2 -> V_49 ;
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_1 * V_228 , * V_91 ;
V_130 V_229 = V_49 -> V_142 -> V_230 ;
V_130 V_230 ;
int V_21 = 0 ;
F_7 ( V_2 , L_85 ) ;
F_40 (cmd, tmp, &tgt->active_cmd_queue, link) {
F_45 ( V_19 , L_86 ) ;
V_230 = V_228 -> V_49 -> V_142 -> V_230 ;
if ( V_230 == V_229 ) {
if ( ! F_15 ( V_30 ,
& V_228 -> V_22 ) ) {
if ( F_82 ( & V_2 -> V_9 ) )
F_16 ( & V_2 -> V_10 ,
V_35 ) ;
V_21 = F_19 ( V_228 ) ;
F_88 ( V_21 != V_41 ) ;
} else
F_21 (KERN_ERR PFX L_87
L_88 ,
cmd->xid) ;
}
}
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_1 * V_228 , * V_91 ;
int V_21 = 0 ;
F_7 ( V_2 , L_89 ) ;
F_40 (cmd, tmp, &tgt->active_cmd_queue, link) {
F_45 ( V_19 , L_90 ) ;
if ( ! F_15 ( V_30 ,
& V_228 -> V_22 ) ) {
if ( F_82 ( & V_2 -> V_9 ) )
F_16 ( & V_2 -> V_10 ,
V_35 ) ;
V_21 = F_19 ( V_228 ) ;
F_88 ( V_21 != V_41 ) ;
} else
F_21 (KERN_ERR PFX L_91
L_92 , cmd->xid) ;
}
}
void F_90 ( struct V_1 * V_2 ,
struct V_137 * V_138 , T_1 V_217 )
{
struct V_109 * V_136 ;
struct V_143 * V_144 ;
struct V_48 * V_49 = V_2 -> V_49 ;
V_130 * V_231 ;
V_130 * V_232 ;
void * V_233 ;
F_7 ( V_2 , L_93 ) ;
if ( ! ( F_14 ( V_176 , & V_2 -> V_22 ) ) )
F_20 ( V_175 , & V_2 -> V_22 ) ;
else {
return;
}
V_136 = & ( V_2 -> V_110 ) ;
V_144 = & ( V_136 -> V_234 ) ;
V_231 = ( V_130 * ) V_144 ;
V_232 = ( V_130 * )
& V_138 -> V_222 . V_223 . V_224 . V_235 . V_144 ;
V_231 [ 0 ] = F_91 ( V_232 [ 0 ] ) ;
V_231 [ 1 ] = F_91 ( V_232 [ 1 ] ) ;
V_231 [ 2 ] = F_91 ( V_232 [ 2 ] ) ;
V_136 -> V_236 =
V_138 -> V_222 . V_223 . V_224 . V_235 . V_237 ;
V_233 = V_136 -> V_120 ;
if ( V_144 -> V_238 == V_239 ) {
F_92 ( V_2 ,
(struct V_240 * )
V_233 , V_217 ) ;
if ( V_2 -> V_241 == 0 ) {
if ( V_136 -> V_112 & V_204 )
F_87 ( V_2 ) ;
else if ( V_136 -> V_112 & V_203 )
F_89 ( V_2 ) ;
}
} else {
F_21 (KERN_ERR PFX L_94 ,
fc_hdr->fh_r_ctl) ;
}
if ( ! V_49 -> V_54 . V_55 ) {
F_21 (KERN_ERR PFX L_95 ) ;
return;
}
switch ( V_2 -> V_242 ) {
case V_243 :
if ( V_2 -> V_244 == 0 ) {
V_49 -> V_51 = V_245 << 16 ;
} else {
V_49 -> V_51 = ( V_245 << 16 ) | V_2 -> V_244 ;
}
if ( V_2 -> V_246 )
F_25 ( V_49 , V_2 -> V_246 ) ;
break;
default:
F_7 ( V_2 , L_96 ,
V_2 -> V_242 ) ;
break;
}
V_49 = V_2 -> V_49 ;
V_2 -> V_49 = NULL ;
if ( V_2 -> V_171 ) {
F_46 ( & V_2 -> V_81 ) ;
V_2 -> V_171 = 0 ;
} else {
F_21 (KERN_ERR PFX L_97 ) ;
return;
}
V_49 -> V_54 . V_55 = NULL ;
V_49 -> V_56 ( V_49 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
if ( V_2 -> V_173 ) {
F_7 ( V_2 , L_98 ) ;
F_13 ( & V_2 -> V_29 ) ;
}
}
static int F_93 ( struct V_1 * V_2 , V_130 V_122 , int V_247 ,
int V_248 )
{
struct V_84 * V_249 = V_2 -> V_85 -> V_85 ;
int V_250 , V_251 ;
V_251 = 0 ;
while ( V_247 ) {
if ( V_247 >= V_252 )
V_250 = V_252 ;
else
V_250 = V_247 ;
V_249 [ V_248 + V_251 ] . V_128 = V_122 & 0xffffffff ;
V_249 [ V_248 + V_251 ] . V_129 = V_122 >> 32 ;
V_249 [ V_248 + V_251 ] . V_131 = ( T_4 ) V_250 ;
V_249 [ V_248 + V_251 ] . V_34 = 0 ;
V_122 += ( V_130 ) V_250 ;
V_251 ++ ;
V_247 -= V_250 ;
}
return V_251 ;
}
static int F_94 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
struct V_58 * V_59 = V_5 -> V_59 ;
struct V_48 * V_253 = V_2 -> V_49 ;
struct V_84 * V_249 = V_2 -> V_85 -> V_85 ;
struct V_254 * V_255 ;
int V_256 = 0 ;
int V_257 = 0 ;
int V_258 = 0 ;
int V_251 ;
unsigned int V_247 ;
V_130 V_122 ;
int V_66 ;
V_257 = F_95 ( & V_59 -> V_86 -> V_87 , F_96 ( V_253 ) ,
F_97 ( V_253 ) , V_253 -> V_259 ) ;
F_98 (sc, sg, sg_count, i) {
V_247 = F_99 ( V_255 ) ;
V_122 = F_100 ( V_255 ) ;
if ( V_247 > V_260 ) {
V_251 = F_93 ( V_2 , V_122 , V_247 ,
V_258 ) ;
} else {
V_251 = 1 ;
V_249 [ V_258 ] . V_128 = V_122 & 0xffffffff ;
V_249 [ V_258 ] . V_129 = V_122 >> 32 ;
V_249 [ V_258 ] . V_131 = ( T_4 ) V_247 ;
V_249 [ V_258 ] . V_34 = 0 ;
}
V_258 += V_251 ;
V_256 += V_247 ;
}
if ( V_256 != F_26 ( V_253 ) )
F_21 (KERN_ERR PFX L_99
L_100 , byte_count, scsi_bufflen(sc),
io_req->xid) ;
return V_258 ;
}
static int F_101 ( struct V_1 * V_2 )
{
struct V_48 * V_253 = V_2 -> V_49 ;
struct V_84 * V_249 = V_2 -> V_85 -> V_85 ;
int V_258 ;
if ( F_97 ( V_253 ) ) {
V_258 = F_94 ( V_2 ) ;
if ( V_258 == 0 )
return - V_196 ;
} else {
V_258 = 0 ;
V_249 [ 0 ] . V_128 = V_249 [ 0 ] . V_129 = 0 ;
V_249 [ 0 ] . V_131 = V_249 [ 0 ] . V_34 = 0 ;
}
V_2 -> V_85 -> V_261 = V_258 ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_48 * V_253 = V_2 -> V_49 ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
struct V_58 * V_59 = V_5 -> V_59 ;
if ( V_2 -> V_85 -> V_261 && V_253 && F_97 ( V_253 ) ) {
F_102 ( & V_59 -> V_86 -> V_87 , F_96 ( V_253 ) ,
F_97 ( V_253 ) , V_253 -> V_259 ) ;
V_2 -> V_85 -> V_261 = 0 ;
}
}
void F_64 ( struct V_1 * V_2 ,
struct V_124 * V_124 )
{
struct V_48 * V_49 = V_2 -> V_49 ;
char V_262 [ 2 ] ;
memset ( V_124 , 0 , sizeof( struct V_124 ) ) ;
F_103 ( V_49 -> V_142 -> V_230 , & V_124 -> V_263 ) ;
V_124 -> V_161 = F_104 ( V_2 -> V_125 ) ;
memcpy ( V_124 -> V_159 , V_49 -> V_264 , V_49 -> V_160 ) ;
V_124 -> V_265 = 0 ;
V_124 -> V_266 = 0 ;
V_124 -> V_267 = V_2 -> V_110 . V_112 ;
V_124 -> V_268 = V_2 -> V_158 ;
if ( F_105 ( V_49 , V_262 ) ) {
switch ( V_262 [ 0 ] ) {
case V_269 :
V_124 -> V_266 = V_270 ;
break;
case V_271 :
V_124 -> V_266 = V_272 ;
break;
default:
V_124 -> V_266 = V_273 ;
break;
}
} else {
V_124 -> V_266 = 0 ;
}
}
static void F_92 ( struct V_1 * V_2 ,
struct V_240 * V_274 ,
T_1 V_217 )
{
struct V_48 * V_49 = V_2 -> V_49 ;
struct V_18 * V_19 = V_2 -> V_19 ;
T_1 V_275 = V_274 -> V_276 . V_34 ;
T_3 V_277 = 0 ;
int V_66 ;
unsigned char * V_278 ;
unsigned char * V_279 ;
int V_280 = 0 ;
int V_281 = 0 ;
V_2 -> V_242 = V_243 ;
V_2 -> V_246 = V_274 -> V_246 ;
V_2 -> V_282 = V_275 ;
F_106 ( V_49 ) = V_2 -> V_244 =
V_274 -> V_283 ;
if ( V_217 ) {
if ( V_275 &
V_284 ) {
V_281 = V_277
= V_274 -> V_281 ;
}
if ( V_275 &
V_285 ) {
V_280 = V_274 -> V_280 ;
V_277 += V_274 -> V_280 ;
}
V_2 -> V_281 = V_281 ;
V_2 -> V_280 = V_280 ;
if ( V_277 > V_217 * V_286 ) {
F_21 (KERN_ERR PFX L_101 ,
rq_buff_len) ;
V_277 = V_217 * V_286 ;
}
V_278 = F_107 ( V_19 , 1 ) ;
if ( V_217 > 1 ) {
for ( V_66 = 1 ; V_66 < V_217 ; V_66 ++ )
V_279 = F_107 ( V_19 , 1 ) ;
}
if ( ( V_281 == 4 ) || ( V_281 == 8 ) ) {
V_2 -> V_241 = V_278 [ 3 ] ;
F_21 (KERN_ERR PFX L_102 ,
io_req->fcp_rsp_code) ;
}
V_278 += V_281 ;
if ( V_280 > V_287 ) {
F_21 (KERN_ERR PFX L_103 ) ;
V_280 = V_287 ;
}
memset ( V_49 -> V_288 , 0 , V_287 ) ;
if ( V_280 )
memcpy ( V_49 -> V_288 , V_278 , V_280 ) ;
for ( V_66 = 0 ; V_66 < V_217 ; V_66 ++ )
F_108 ( V_19 , 1 ) ;
}
}
int F_109 ( struct V_140 * V_141 ,
struct V_48 * V_49 )
{
struct V_13 * V_14 = F_57 ( V_141 ) ;
struct V_132 * V_133 = F_58 ( F_59 ( V_49 -> V_142 ) ) ;
struct V_134 * V_135 = V_133 -> V_151 ;
struct V_18 * V_19 ;
struct V_1 * V_2 ;
int V_21 = 0 ;
int V_289 ;
V_289 = F_110 ( V_133 ) ;
if ( V_289 ) {
V_49 -> V_51 = V_289 ;
V_49 -> V_56 ( V_49 ) ;
return 0 ;
}
if ( ( V_14 -> V_152 != V_153 ) || ! ( V_14 -> V_154 ) ) {
V_21 = V_290 ;
goto V_291;
}
V_19 = (struct V_18 * ) & V_135 [ 1 ] ;
if ( ! F_14 ( V_155 , & V_19 -> V_34 ) ) {
V_21 = V_292 ;
goto V_291;
}
if ( V_19 -> V_293 ) {
if ( F_62 ( V_149 , V_19 -> V_293 ) ) {
V_19 -> V_293 = 0 ;
} else {
V_21 = V_292 ;
goto V_291;
}
}
F_8 ( & V_19 -> V_23 ) ;
V_2 = F_50 ( V_19 ) ;
if ( ! V_2 ) {
V_21 = V_290 ;
goto V_294;
}
V_2 -> V_49 = V_49 ;
if ( F_111 ( V_19 , V_2 ) ) {
F_21 (KERN_ERR PFX L_104 ) ;
V_21 = V_290 ;
goto V_294;
}
V_294:
F_11 ( & V_19 -> V_23 ) ;
V_291:
return V_21 ;
}
void F_112 ( struct V_1 * V_2 ,
struct V_137 * V_138 ,
T_1 V_217 )
{
struct V_240 * V_274 ;
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_48 * V_49 ;
struct V_140 * V_141 ;
if ( F_15 ( V_40 , & V_2 -> V_22 ) ) {
F_7 ( V_2 , L_105
L_106 ) ;
}
if ( F_82 ( & V_2 -> V_9 ) )
F_16 ( & V_2 -> V_10 ,
V_35 ) ;
V_49 = V_2 -> V_49 ;
if ( V_49 == NULL ) {
F_21 (KERN_ERR PFX L_107 ) ;
return;
}
V_274 = (struct V_240 * )
& ( V_138 -> V_222 . V_223 . V_224 . V_274 . V_295 ) ;
F_92 ( V_2 , V_274 , V_217 ) ;
V_141 = V_49 -> V_142 -> V_141 ;
if ( ! V_49 -> V_54 . V_55 ) {
F_21 (KERN_ERR PFX L_108 ) ;
return;
}
if ( V_2 -> V_209 ) {
F_46 ( & V_2 -> V_81 ) ;
V_2 -> V_209 = 0 ;
F_35 ( & V_2 -> V_81 , & V_19 -> V_211 ) ;
} else {
F_7 ( V_2 , L_109 ) ;
if ( V_2 -> V_173 )
if ( F_9 ( V_28 ,
& V_2 -> V_22 ) )
F_13 ( & V_2 -> V_29 ) ;
}
F_23 ( V_2 ) ;
V_2 -> V_49 = NULL ;
switch ( V_2 -> V_242 ) {
case V_243 :
if ( V_2 -> V_244 == 0 ) {
V_49 -> V_51 = V_245 << 16 ;
} else {
F_7 ( V_2 , L_110
L_111 ,
V_2 -> V_244 , V_2 -> V_246 ) ;
V_49 -> V_51 = ( V_245 << 16 ) | V_2 -> V_244 ;
if ( V_2 -> V_244 == V_296 ||
V_2 -> V_244 == V_297 ) {
V_19 -> V_293 = V_149 +
V_274 -> V_298 * V_157 / 10 ;
}
}
if ( V_2 -> V_246 )
F_25 ( V_49 , V_2 -> V_246 ) ;
break;
default:
F_21 (KERN_ERR PFX L_112 ,
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
struct V_137 * V_138 ;
struct V_137 * V_139 ;
struct V_48 * V_49 = V_2 -> V_49 ;
struct V_92 * V_6 = V_19 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_58 * V_59 = V_5 -> V_59 ;
struct V_13 * V_14 = V_6 -> V_14 ;
struct V_299 * V_300 ;
int V_145 , V_96 ;
T_4 V_65 ;
V_2 -> V_17 = V_27 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_19 = V_19 ;
V_2 -> V_125 = F_26 ( V_49 ) ;
V_49 -> V_54 . V_55 = ( char * ) V_2 ;
V_300 = F_113 ( V_14 -> V_300 , F_51 () ) ;
if ( V_49 -> V_259 == V_301 ) {
V_2 -> V_158 = V_302 ;
V_300 -> V_303 ++ ;
V_300 -> V_304 += V_2 -> V_125 ;
} else if ( V_49 -> V_259 == V_305 ) {
V_2 -> V_158 = V_306 ;
V_300 -> V_307 ++ ;
V_300 -> V_308 += V_2 -> V_125 ;
} else {
V_2 -> V_158 = 0 ;
V_300 -> V_309 ++ ;
}
F_52 () ;
V_65 = V_2 -> V_65 ;
if ( F_101 ( V_2 ) ) {
F_21 (KERN_ERR PFX L_113 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
return - V_310 ;
}
V_145 = V_65 / V_169 ;
V_96 = V_65 % V_169 ;
V_139 = (struct V_137 * ) V_59 -> V_170 [ V_145 ] ;
V_138 = & ( V_139 [ V_96 ] ) ;
F_114 ( V_2 , V_138 ) ;
if ( V_19 -> V_208 ) {
F_21 (KERN_ERR PFX L_114 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
return - V_310 ;
}
if ( ! F_14 ( V_155 , & V_19 -> V_34 ) ) {
F_21 (KERN_ERR PFX L_115 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
return - V_310 ;
}
if ( V_19 -> V_311 )
F_1 ( V_2 , V_312 ) ;
F_67 ( V_19 , V_65 ) ;
V_2 -> V_209 = 1 ;
F_35 ( & V_2 -> V_81 , & V_19 -> V_313 ) ;
F_69 ( V_19 ) ;
return 0 ;
}
