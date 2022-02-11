void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
if ( F_2 ( V_5 -> V_8 , & V_2 -> V_9 ,
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
F_23 ( V_2 ) ;
V_2 -> V_49 = NULL ;
if ( ! V_49 ) {
F_21 (KERN_ERR PFX L_19
L_20 ,
io_req->xid) ;
return;
}
V_49 -> V_50 = V_47 << 16 ;
F_7 ( V_2 , L_21 ,
V_49 , F_24 ( V_49 -> V_50 ) , V_49 -> V_51 ,
V_49 -> V_52 ) ;
F_25 ( V_49 , F_26 ( V_49 ) ) ;
V_49 -> V_53 . V_54 = NULL ;
V_49 -> V_55 ( V_49 ) ;
}
struct V_56 * F_27 ( struct V_4 * V_5 ,
T_2 V_57 , T_2 V_58 )
{
struct V_56 * V_59 ;
struct V_60 * V_61 ;
struct V_1 * V_2 ;
T_3 V_62 ;
T_4 V_63 ;
T_2 V_64 ;
int V_65 ;
int V_66 , V_67 ;
T_3 V_68 ;
int V_69 = F_28 () + 1 ;
if ( V_58 <= V_57 || V_58 == V_70 ) {
F_21 (KERN_ERR PFX L_22 , min_xid, max_xid) ;
return NULL ;
}
F_29 ( L_23 , V_57 , V_58 ) ;
V_66 = V_58 - V_57 + 1 ;
V_62 = ( V_66 * ( sizeof( struct V_1 * ) ) ) ;
V_62 += sizeof( struct V_56 ) ;
V_59 = F_30 ( V_62 , V_71 ) ;
if ( ! V_59 ) {
F_21 (KERN_ERR PFX L_24 ) ;
return NULL ;
}
V_59 -> V_72 = F_30 ( sizeof( * V_59 -> V_72 ) *
V_69 , V_71 ) ;
if ( ! V_59 -> V_72 ) {
F_21 (KERN_ERR PFX L_25 ) ;
goto V_73;
}
V_59 -> V_74 = F_30 ( sizeof( * V_59 -> V_74 ) *
V_69 , V_71 ) ;
if ( ! V_59 -> V_74 ) {
F_21 (KERN_ERR PFX L_26 ) ;
goto V_73;
}
V_59 -> V_5 = V_5 ;
V_59 -> V_75 = (struct V_1 * * ) ( V_59 + 1 ) ;
for ( V_65 = 0 ; V_65 < V_69 ; V_65 ++ ) {
F_31 ( & V_59 -> V_72 [ V_65 ] ) ;
F_32 ( & V_59 -> V_74 [ V_65 ] ) ;
}
V_64 = V_76 ;
V_67 = V_66 - V_77 ;
for ( V_65 = 0 ; V_65 < V_66 ; V_65 ++ ) {
V_2 = F_30 ( sizeof( * V_2 ) , V_71 ) ;
if ( ! V_2 ) {
F_21 (KERN_ERR PFX L_27 ) ;
goto V_73;
}
F_31 ( & V_2 -> V_78 ) ;
F_33 ( & V_2 -> V_9 , F_5 ) ;
V_2 -> V_64 = V_64 ++ ;
if ( V_65 < V_67 )
F_34 ( & V_2 -> V_78 ,
& V_59 -> V_72 [ V_2 -> V_64 %
F_28 () ] ) ;
else
F_34 ( & V_2 -> V_78 ,
& V_59 -> V_72 [ F_28 () ] ) ;
V_2 ++ ;
}
V_63 = V_66 * sizeof( struct V_60 * ) ;
V_59 -> V_79 = F_35 ( V_63 , V_71 ) ;
if ( ! V_59 -> V_79 ) {
F_21 (KERN_ERR PFX L_28 ) ;
goto V_73;
}
V_63 = sizeof( struct V_60 ) ;
for ( V_65 = 0 ; V_65 < V_66 ; V_65 ++ ) {
V_59 -> V_79 [ V_65 ] = F_35 ( V_63 , V_71 ) ;
if ( ! V_59 -> V_79 [ V_65 ] ) {
F_21 (KERN_ERR PFX L_29
L_30 , i) ;
goto V_73;
}
}
V_68 = V_80 * sizeof( struct V_81 ) ;
for ( V_65 = 0 ; V_65 < V_66 ; V_65 ++ ) {
V_61 = V_59 -> V_79 [ V_65 ] ;
V_61 -> V_82 = F_36 ( & V_5 -> V_83 -> V_84 ,
V_68 ,
& V_61 -> V_85 ,
V_71 ) ;
if ( ! V_61 -> V_82 ) {
F_21 (KERN_ERR PFX L_29
L_31 , i) ;
goto V_73;
}
}
return V_59 ;
V_73:
F_37 ( V_59 ) ;
return NULL ;
}
void F_37 ( struct V_56 * V_59 )
{
struct V_60 * V_61 ;
struct V_4 * V_5 = V_59 -> V_5 ;
T_3 V_68 ;
T_2 V_57 = V_76 ;
T_2 V_58 = V_86 ;
int V_66 ;
int V_65 ;
V_66 = V_58 - V_57 + 1 ;
if ( ! V_59 -> V_79 )
goto V_87;
V_68 = V_80 * sizeof( struct V_81 ) ;
for ( V_65 = 0 ; V_65 < V_66 ; V_65 ++ ) {
V_61 = V_59 -> V_79 [ V_65 ] ;
if ( V_61 -> V_82 ) {
F_38 ( & V_5 -> V_83 -> V_84 , V_68 ,
V_61 -> V_82 ,
V_61 -> V_85 ) ;
V_61 -> V_82 = NULL ;
}
}
for ( V_65 = 0 ; V_65 < V_66 ; V_65 ++ ) {
F_39 ( V_59 -> V_79 [ V_65 ] ) ;
V_59 -> V_79 [ V_65 ] = NULL ;
}
F_39 ( V_59 -> V_79 ) ;
V_59 -> V_79 = NULL ;
V_87:
F_39 ( V_59 -> V_74 ) ;
if ( ! V_59 -> V_72 )
goto V_88;
for ( V_65 = 0 ; V_65 < F_28 () + 1 ; V_65 ++ ) {
struct V_89 * V_90 ;
struct V_89 * V_91 ;
F_40 (list, tmp, &cmgr->free_list[i]) {
struct V_1 * V_2 = (struct V_1 * ) V_90 ;
F_41 ( & V_2 -> V_78 ) ;
F_39 ( V_2 ) ;
}
}
F_39 ( V_59 -> V_72 ) ;
V_88:
F_39 ( V_59 ) ;
}
struct V_1 * F_42 ( struct V_18 * V_19 , int type )
{
struct V_92 * V_6 = V_19 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_56 * V_93 = V_5 -> V_93 ;
struct V_1 * V_2 ;
struct V_89 * V_94 ;
struct V_60 * V_82 ;
int V_95 = V_96 ;
T_4 V_97 ;
T_2 V_64 ;
V_97 = V_19 -> V_97 ;
switch ( type ) {
case V_98 :
V_97 = V_99 ;
break;
case V_42 :
V_97 = V_100 ;
break;
default:
break;
}
F_8 ( & V_93 -> V_74 [ V_95 ] ) ;
if ( ( F_43 ( & ( V_93 -> V_72 [ V_95 ] ) ) ) ||
( V_19 -> V_101 . V_31 >= V_97 ) ) {
F_44 ( V_19 , L_32
L_33 ,
V_19 -> V_101 . V_31 , V_19 -> V_97 ) ;
if ( F_43 ( & ( V_93 -> V_72 [ V_95 ] ) ) )
F_21 (KERN_ERR PFX L_34 ) ;
F_11 ( & V_93 -> V_74 [ V_95 ] ) ;
return NULL ;
}
V_94 = (struct V_89 * )
V_93 -> V_72 [ V_95 ] . V_102 ;
F_45 ( V_94 ) ;
V_2 = (struct V_1 * ) V_94 ;
V_64 = V_2 -> V_64 ;
V_93 -> V_75 [ V_64 ] = V_2 ;
F_46 ( & V_19 -> V_101 ) ;
F_11 ( & V_93 -> V_74 [ V_95 ] ) ;
F_31 ( & V_2 -> V_78 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_93 = V_93 ;
V_2 -> V_22 = 0 ;
V_2 -> V_17 = type ;
V_82 = V_2 -> V_82 = V_93 -> V_79 [ V_64 ] ;
V_82 -> V_2 = V_2 ;
F_47 ( & V_2 -> V_10 ) ;
return V_2 ;
}
static struct V_1 * F_48 ( struct V_18 * V_19 )
{
struct V_92 * V_6 = V_19 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_56 * V_93 = V_5 -> V_93 ;
struct V_1 * V_2 ;
struct V_89 * V_94 ;
struct V_60 * V_82 ;
T_4 V_97 ;
T_2 V_64 ;
int V_95 = F_49 () ;
V_97 = V_103 ;
F_8 ( & V_93 -> V_74 [ V_95 ] ) ;
if ( ( F_43 ( & V_93 -> V_72 [ V_95 ] ) ) ||
( V_19 -> V_101 . V_31 >= V_97 ) ) {
F_11 ( & V_93 -> V_74 [ V_95 ] ) ;
F_50 () ;
return NULL ;
}
V_94 = (struct V_89 * )
V_93 -> V_72 [ V_95 ] . V_102 ;
F_45 ( V_94 ) ;
V_2 = (struct V_1 * ) V_94 ;
V_64 = V_2 -> V_64 ;
V_93 -> V_75 [ V_64 ] = V_2 ;
F_46 ( & V_19 -> V_101 ) ;
F_11 ( & V_93 -> V_74 [ V_95 ] ) ;
F_50 () ;
F_31 ( & V_2 -> V_78 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_93 = V_93 ;
V_2 -> V_22 = 0 ;
V_82 = V_2 -> V_82 = V_93 -> V_79 [ V_64 ] ;
V_82 -> V_2 = V_2 ;
F_47 ( & V_2 -> V_10 ) ;
return V_2 ;
}
void V_35 ( struct V_104 * V_105 )
{
struct V_1 * V_2 = F_6 ( V_105 ,
struct V_1 , V_10 ) ;
struct V_56 * V_93 = V_2 -> V_93 ;
int V_95 ;
if ( V_2 -> V_17 == V_27 )
V_95 = V_2 -> V_64 % F_28 () ;
else
V_95 = V_96 ;
F_8 ( & V_93 -> V_74 [ V_95 ] ) ;
if ( V_2 -> V_17 != V_27 )
F_51 ( V_2 ) ;
V_93 -> V_75 [ V_2 -> V_64 ] = NULL ;
F_45 ( & V_2 -> V_78 ) ;
F_52 ( & V_2 -> V_78 ,
& V_93 -> V_72 [ V_95 ] ) ;
F_53 ( & V_2 -> V_19 -> V_101 ) ;
F_11 ( & V_93 -> V_74 [ V_95 ] ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_106 * V_107 = & ( V_2 -> V_107 ) ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
T_3 V_108 = sizeof( struct V_81 ) ;
V_107 -> V_109 = 0 ;
if ( V_107 -> V_110 ) {
F_38 ( & V_5 -> V_83 -> V_84 , V_108 ,
V_107 -> V_110 ,
V_107 -> V_111 ) ;
V_107 -> V_110 = NULL ;
}
if ( V_107 -> V_112 ) {
F_38 ( & V_5 -> V_83 -> V_84 , V_108 ,
V_107 -> V_112 ,
V_107 -> V_113 ) ;
V_107 -> V_112 = NULL ;
}
if ( V_107 -> V_114 ) {
F_38 ( & V_5 -> V_83 -> V_84 , V_115 ,
V_107 -> V_114 ,
V_107 -> V_116 ) ;
V_107 -> V_114 = NULL ;
}
if ( V_107 -> V_117 ) {
F_38 ( & V_5 -> V_83 -> V_84 , V_115 ,
V_107 -> V_117 ,
V_107 -> V_118 ) ;
V_107 -> V_117 = NULL ;
}
}
int F_54 ( struct V_1 * V_2 )
{
struct V_106 * V_107 ;
struct V_81 * V_110 ;
struct V_81 * V_112 ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
T_5 V_119 ;
T_3 V_108 ;
V_107 = (struct V_106 * ) & ( V_2 -> V_107 ) ;
memset ( V_107 , 0 , sizeof( struct V_106 ) ) ;
V_107 -> V_120 = sizeof( struct V_121 ) ;
V_2 -> V_122 = V_107 -> V_120 ;
V_107 -> V_114 = F_36 ( & V_5 -> V_83 -> V_84 , V_115 ,
& V_107 -> V_116 ,
V_123 ) ;
if ( ! V_107 -> V_114 ) {
F_21 (KERN_ERR PFX L_35 ) ;
F_51 ( V_2 ) ;
return V_124 ;
}
V_107 -> V_117 = F_36 ( & V_5 -> V_83 -> V_84 , V_115 ,
& V_107 -> V_118 ,
V_123 ) ;
if ( ! V_107 -> V_117 ) {
F_21 (KERN_ERR PFX L_36 ) ;
F_51 ( V_2 ) ;
return V_124 ;
}
memset ( V_107 -> V_114 , 0 , V_115 ) ;
memset ( V_107 -> V_117 , 0 , V_115 ) ;
V_108 = sizeof( struct V_81 ) ;
V_107 -> V_110 = F_36 ( & V_5 -> V_83 -> V_84 , V_108 ,
& V_107 -> V_111 ,
V_123 ) ;
if ( ! V_107 -> V_110 ) {
F_21 (KERN_ERR PFX L_37 ) ;
F_51 ( V_2 ) ;
return V_124 ;
}
V_107 -> V_112 = F_36 ( & V_5 -> V_83 -> V_84 , V_108 ,
& V_107 -> V_113 ,
V_123 ) ;
if ( ! V_107 -> V_110 ) {
F_21 (KERN_ERR PFX L_38 ) ;
F_51 ( V_2 ) ;
return V_124 ;
}
V_119 = V_107 -> V_116 ;
V_110 = V_107 -> V_110 ;
V_110 -> V_125 = ( T_4 ) V_119 & 0xffffffff ;
V_110 -> V_126 = ( T_4 ) ( ( V_127 ) V_119 >> 32 ) ;
V_110 -> V_128 = V_115 ;
V_110 -> V_34 = 0 ;
V_112 = V_107 -> V_112 ;
V_119 = V_107 -> V_118 ;
V_112 -> V_125 = ( T_4 ) V_119 & 0xffffffff ;
V_112 -> V_126 = ( T_4 ) ( ( V_127 ) V_119 >> 32 ) ;
V_112 -> V_128 = V_115 ;
V_112 -> V_34 = 0 ;
return V_41 ;
}
static int F_55 ( struct V_48 * V_49 , T_1 V_109 )
{
struct V_13 * V_14 ;
struct V_129 * V_130 = F_56 ( F_57 ( V_49 -> V_131 ) ) ;
struct V_132 * V_133 = V_130 -> V_134 ;
struct V_92 * V_6 ;
struct V_4 * V_5 ;
struct V_18 * V_19 ;
struct V_1 * V_2 ;
struct V_106 * V_135 ;
struct V_136 * V_137 ;
struct V_136 * V_138 ;
struct V_139 * V_140 = V_49 -> V_131 -> V_140 ;
struct V_141 * V_142 ;
struct V_121 * V_121 ;
int V_143 , V_95 ;
int V_21 = V_41 ;
T_2 V_64 ;
T_4 V_144 , V_145 ;
unsigned long V_146 = V_147 ;
V_14 = F_58 ( V_140 ) ;
V_6 = F_59 ( V_14 ) ;
V_5 = V_6 -> V_7 ;
if ( V_130 == NULL ) {
F_21 (KERN_ALERT PFX L_39 ) ;
V_21 = V_124 ;
goto V_148;
}
V_21 = F_60 ( V_49 ) ;
if ( V_21 )
return V_21 ;
if ( V_14 -> V_149 != V_150 || ! ( V_14 -> V_151 ) ) {
F_21 (KERN_ERR PFX L_40 ) ;
V_21 = V_124 ;
goto V_148;
}
V_19 = (struct V_18 * ) & V_133 [ 1 ] ;
if ( ! ( F_14 ( V_152 , & V_19 -> V_34 ) ) ) {
F_21 (KERN_ERR PFX L_41 ) ;
V_21 = V_124 ;
goto V_148;
}
V_153:
V_2 = F_42 ( V_19 , V_98 ) ;
if ( ! V_2 ) {
if ( F_61 ( V_147 , V_146 + V_154 ) ) {
F_21 (KERN_ERR PFX L_42 ) ;
V_21 = V_124 ;
goto V_148;
}
F_62 ( 20 ) ;
goto V_153;
}
V_2 -> V_49 = V_49 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_19 = V_19 ;
V_135 = (struct V_106 * ) & ( V_2 -> V_107 ) ;
V_21 = F_54 ( V_2 ) ;
if ( V_21 == V_124 ) {
F_21 (KERN_ERR PFX L_43 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
goto V_148;
}
V_2 -> V_155 = 0 ;
V_135 -> V_109 = V_109 ;
F_63 ( V_2 , (struct V_121 * ) V_135 -> V_114 ) ;
V_121 = (struct V_121 * ) V_135 -> V_114 ;
memset ( V_121 -> V_156 , 0 , V_49 -> V_157 ) ;
V_121 -> V_158 = 0 ;
V_142 = & ( V_135 -> V_159 ) ;
V_144 = V_19 -> V_144 ;
V_145 = V_130 -> V_160 ;
F_64 ( V_142 , V_161 , V_145 , V_144 ,
V_162 , V_163 | V_164 |
V_165 , 0 ) ;
V_64 = V_2 -> V_64 ;
F_44 ( V_19 , L_44 , V_64 ) ;
V_143 = V_64 / V_166 ;
V_95 = V_64 % V_166 ;
V_138 = (struct V_136 * ) V_5 -> V_167 [ V_143 ] ;
V_137 = & ( V_138 [ V_95 ] ) ;
F_65 ( V_2 , V_137 ) ;
V_49 -> V_53 . V_54 = ( char * ) V_2 ;
F_8 ( & V_19 -> V_23 ) ;
F_66 ( V_19 , V_64 ) ;
V_2 -> V_168 = 1 ;
F_34 ( & V_2 -> V_78 , & V_19 -> V_169 ) ;
F_67 ( & V_2 -> V_29 ) ;
V_2 -> V_170 = 1 ;
F_68 ( V_19 ) ;
F_11 ( & V_19 -> V_23 ) ;
V_21 = F_69 ( & V_2 -> V_29 ,
V_171 * V_154 ) ;
F_8 ( & V_19 -> V_23 ) ;
V_2 -> V_170 = 0 ;
if ( ! ( F_14 ( V_172 , & V_2 -> V_22 ) ) )
F_20 ( V_173 , & V_2 -> V_22 ) ;
F_11 ( & V_19 -> V_23 ) ;
if ( ! V_21 ) {
F_21 (KERN_ERR PFX L_45 ) ;
V_21 = V_124 ;
} else {
F_21 (KERN_ERR PFX L_46 ) ;
V_21 = V_41 ;
}
V_148:
return V_21 ;
}
int F_19 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_129 * V_130 = V_19 -> V_130 ;
struct V_15 * V_16 = V_19 -> V_16 ;
struct V_4 * V_5 ;
struct V_92 * V_6 ;
struct V_1 * V_174 ;
struct V_136 * V_137 ;
struct V_136 * V_138 ;
struct V_141 * V_142 ;
struct V_106 * V_175 ;
int V_143 , V_95 ;
T_4 V_144 , V_145 ;
T_2 V_64 ;
int V_21 = V_41 ;
T_4 V_176 = V_16 -> V_176 ;
F_7 ( V_2 , L_47 ) ;
V_6 = V_2 -> V_6 ;
V_5 = V_6 -> V_7 ;
V_14 = V_6 -> V_14 ;
if ( ! F_14 ( V_152 , & V_19 -> V_34 ) ) {
F_21 (KERN_ERR PFX L_48 ) ;
V_21 = V_124 ;
goto V_177;
}
if ( V_130 == NULL ) {
F_21 (KERN_ALERT PFX L_49 ) ;
V_21 = V_124 ;
goto V_177;
}
if ( V_14 -> V_149 != V_150 || ! ( V_14 -> V_151 ) ) {
F_21 (KERN_ERR PFX L_50 ) ;
V_21 = V_124 ;
goto V_177;
}
V_174 = F_42 ( V_19 , V_178 ) ;
if ( ! V_174 ) {
F_21 (KERN_ERR PFX L_51 ) ;
V_21 = V_124 ;
goto V_177;
}
V_174 -> V_49 = NULL ;
V_174 -> V_6 = V_6 ;
V_174 -> V_19 = V_19 ;
V_174 -> V_122 = 0 ;
V_175 = (struct V_106 * ) & ( V_174 -> V_107 ) ;
memset ( V_175 , 0 , sizeof( struct V_106 ) ) ;
V_142 = & ( V_175 -> V_159 ) ;
V_142 -> V_179 = F_70 ( V_2 -> V_64 ) ;
V_142 -> V_180 = F_70 ( V_2 -> V_137 -> V_181 . V_182 ) ;
V_144 = V_19 -> V_144 ;
V_145 = V_130 -> V_160 ;
F_64 ( V_142 , V_183 , V_145 , V_144 ,
V_184 , V_163 | V_164 |
V_165 , 0 ) ;
V_64 = V_174 -> V_64 ;
F_7 ( V_174 , L_52 ) ;
V_143 = V_64 / V_166 ;
V_95 = V_64 % V_166 ;
V_138 = (struct V_136 * ) V_5 -> V_167 [ V_143 ] ;
V_137 = & ( V_138 [ V_95 ] ) ;
F_65 ( V_174 , V_137 ) ;
F_1 ( V_2 , 2 * V_176 ) ;
F_66 ( V_19 , V_64 ) ;
F_68 ( V_19 ) ;
V_177:
return V_21 ;
}
int F_71 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_4 * V_5 ;
struct V_92 * V_6 ;
struct V_1 * V_185 ;
struct V_136 * V_137 ;
struct V_136 * V_138 ;
int V_143 , V_95 ;
T_2 V_64 , V_186 ;
int V_21 = 0 ;
F_7 ( V_2 , L_53 ) ;
V_6 = V_2 -> V_6 ;
V_5 = V_6 -> V_7 ;
V_14 = V_6 -> V_14 ;
V_185 = F_42 ( V_19 , V_187 ) ;
if ( ! V_185 ) {
F_21 (KERN_ERR PFX L_54 ) ;
V_21 = - 1 ;
goto V_188;
}
V_185 -> V_49 = NULL ;
V_185 -> V_6 = V_6 ;
V_185 -> V_19 = V_19 ;
V_185 -> V_122 = 0 ;
V_64 = V_185 -> V_64 ;
V_143 = V_64 / V_166 ;
V_95 = V_64 % V_166 ;
V_138 = (struct V_136 * ) V_5 -> V_167 [ V_143 ] ;
V_137 = & ( V_138 [ V_95 ] ) ;
V_186 = V_2 -> V_64 ;
F_7 ( V_2 , L_55 , V_64 ) ;
F_72 ( V_185 , V_137 , V_186 ) ;
F_66 ( V_19 , V_64 ) ;
F_68 ( V_19 ) ;
V_188:
return V_21 ;
}
int F_73 ( struct V_48 * V_49 )
{
return F_55 ( V_49 , V_189 ) ;
}
int F_74 ( struct V_48 * V_49 )
{
return F_55 ( V_49 , V_190 ) ;
}
int F_75 ( struct V_48 * V_49 )
{
struct V_129 * V_130 = F_56 ( F_57 ( V_49 -> V_131 ) ) ;
struct V_132 * V_133 = V_130 -> V_134 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
struct V_18 * V_19 ;
int V_21 = V_124 ;
V_21 = F_60 ( V_49 ) ;
if ( V_21 )
return V_21 ;
V_14 = F_58 ( V_49 -> V_131 -> V_140 ) ;
if ( ( V_14 -> V_149 != V_150 ) || ! ( V_14 -> V_151 ) ) {
F_21 (KERN_ALERT PFX L_56 ) ;
return V_21 ;
}
V_19 = (struct V_18 * ) & V_133 [ 1 ] ;
F_44 ( V_19 , L_57 ) ;
F_8 ( & V_19 -> V_23 ) ;
V_2 = (struct V_1 * ) V_49 -> V_53 . V_54 ;
if ( ! V_2 ) {
F_21 (KERN_ERR PFX L_58 ) ;
F_11 ( & V_19 -> V_23 ) ;
return V_41 ;
}
F_7 ( V_2 , L_59 ,
V_2 -> V_10 . V_10 . V_31 ) ;
F_4 ( & V_2 -> V_10 ) ;
F_76 ( V_19 != V_2 -> V_19 ) ;
if ( V_19 -> V_191 ) {
F_21 (KERN_ALERT PFX L_60
L_61 , io_req->xid) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
F_11 ( & V_19 -> V_23 ) ;
return V_41 ;
}
if ( V_2 -> V_192 == 0 ) {
F_21 (KERN_ALERT PFX L_60
L_62 , io_req->xid) ;
F_22 ( V_2 , V_193 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
F_11 ( & V_19 -> V_23 ) ;
return V_41 ;
}
F_45 ( & V_2 -> V_78 ) ;
V_2 -> V_192 = 0 ;
F_34 ( & V_2 -> V_78 , & V_19 -> V_194 ) ;
F_67 ( & V_2 -> V_29 ) ;
V_2 -> V_170 = 1 ;
if ( ! F_15 ( V_30 , & V_2 -> V_22 ) ) {
if ( F_77 ( & V_2 -> V_9 ) )
F_16 ( & V_2 -> V_10 ,
V_35 ) ;
F_20 ( V_28 , & V_2 -> V_22 ) ;
V_21 = F_19 ( V_2 ) ;
} else {
F_21 (KERN_ALERT PFX L_60
L_63 , io_req->xid) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
F_11 ( & V_19 -> V_23 ) ;
return V_41 ;
}
if ( V_21 == V_124 ) {
F_16 ( & V_2 -> V_10 , V_35 ) ;
F_11 ( & V_19 -> V_23 ) ;
return V_21 ;
}
F_11 ( & V_19 -> V_23 ) ;
F_78 ( & V_2 -> V_29 ) ;
F_8 ( & V_19 -> V_23 ) ;
V_2 -> V_170 = 0 ;
if ( ! ( F_15 ( V_32 ,
& V_2 -> V_22 ) ) ) {
F_21 (KERN_ERR PFX L_64 ,
io_req->xid) ;
V_21 = V_124 ;
} else {
F_7 ( V_2 , L_65 ) ;
V_21 = V_41 ;
F_22 ( V_2 , V_193 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
}
F_16 ( & V_2 -> V_10 , V_35 ) ;
F_11 ( & V_19 -> V_23 ) ;
return V_21 ;
}
void F_79 ( struct V_1 * V_2 ,
struct V_136 * V_137 ,
T_1 V_195 )
{
F_7 ( V_2 , L_66
L_67 ,
V_2 -> V_10 . V_10 . V_31 , V_2 -> V_17 ) ;
F_22 ( V_2 , V_196 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
}
void F_80 ( struct V_1 * V_2 ,
struct V_136 * V_137 ,
T_1 V_195 )
{
T_4 V_197 ;
T_4 V_176 = V_198 ;
T_1 V_199 = 0 ;
struct V_18 * V_19 = V_2 -> V_19 ;
F_7 ( V_2 , L_68
L_67 ,
V_2 -> V_64 ,
V_2 -> V_10 . V_10 . V_31 , V_2 -> V_17 ) ;
if ( F_15 ( V_32 ,
& V_2 -> V_22 ) ) {
F_7 ( V_2 , L_69
L_70 ) ;
return;
}
if ( F_15 ( V_200 ,
& V_2 -> V_22 ) )
goto V_201;
if ( F_14 ( V_30 , & V_2 -> V_22 ) )
if ( F_77 ( & V_2 -> V_9 ) )
F_16 ( & V_2 -> V_10 ,
V_35 ) ;
V_197 = V_137 -> V_202 . V_203 . V_204 . V_205 . V_197 ;
switch ( V_197 ) {
case V_206 :
F_7 ( V_2 , L_71 ) ;
V_199 = 1 ;
break;
case V_207 :
F_7 ( V_2 , L_72 ) ;
break;
default:
F_21 (KERN_ERR PFX L_73 ) ;
break;
}
if ( V_199 ) {
F_7 ( V_2 , L_74 ) ;
F_20 ( V_24 , & V_2 -> V_22 ) ;
}
F_20 ( V_25 , & V_2 -> V_22 ) ;
F_1 ( V_2 , V_176 ) ;
V_201:
if ( V_2 -> V_170 ) {
if ( F_9 ( V_28 ,
& V_2 -> V_22 ) )
F_13 ( & V_2 -> V_29 ) ;
} else {
if ( V_2 -> V_192 ) {
F_45 ( & V_2 -> V_78 ) ;
V_2 -> V_192 = 0 ;
F_34 ( & V_2 -> V_78 , & V_19 -> V_194 ) ;
}
F_22 ( V_2 , V_196 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
}
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_48 * V_49 = V_2 -> V_49 ;
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_89 * V_90 ;
struct V_89 * V_91 ;
struct V_1 * V_208 ;
int V_209 = V_49 -> V_131 -> V_210 ;
int V_21 = 0 ;
int V_210 ;
F_7 ( V_2 , L_75 ) ;
F_40 (list, tmp, &tgt->active_cmd_queue) {
F_44 ( V_19 , L_76 ) ;
V_208 = (struct V_1 * ) V_90 ;
V_210 = V_208 -> V_49 -> V_131 -> V_210 ;
if ( V_210 == V_209 ) {
if ( ! F_15 ( V_30 ,
& V_208 -> V_22 ) ) {
if ( F_77 ( & V_2 -> V_9 ) )
F_16 ( & V_2 -> V_10 ,
V_35 ) ;
V_21 = F_19 ( V_208 ) ;
F_82 ( V_21 != V_41 ) ;
} else
F_21 (KERN_ERR PFX L_77
L_78 ,
cmd->xid) ;
}
}
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_89 * V_90 ;
struct V_89 * V_91 ;
struct V_1 * V_208 ;
int V_21 = 0 ;
F_7 ( V_2 , L_79 ) ;
F_40 (list, tmp, &tgt->active_cmd_queue) {
F_44 ( V_19 , L_80 ) ;
V_208 = (struct V_1 * ) V_90 ;
if ( ! F_15 ( V_30 ,
& V_208 -> V_22 ) ) {
if ( F_77 ( & V_2 -> V_9 ) )
F_16 ( & V_2 -> V_10 ,
V_35 ) ;
V_21 = F_19 ( V_208 ) ;
F_82 ( V_21 != V_41 ) ;
} else
F_21 (KERN_ERR PFX L_81
L_82 , cmd->xid) ;
}
}
void F_84 ( struct V_1 * V_2 ,
struct V_136 * V_137 , T_1 V_195 )
{
struct V_106 * V_135 ;
struct V_141 * V_142 ;
struct V_48 * V_49 = V_2 -> V_49 ;
V_127 * V_211 ;
V_127 * V_212 ;
void * V_213 ;
F_7 ( V_2 , L_83 ) ;
if ( ! ( F_14 ( V_173 , & V_2 -> V_22 ) ) )
F_20 ( V_172 , & V_2 -> V_22 ) ;
else {
return;
}
V_135 = & ( V_2 -> V_107 ) ;
V_142 = & ( V_135 -> V_214 ) ;
V_211 = ( V_127 * ) V_142 ;
V_212 = ( V_127 * )
& V_137 -> V_202 . V_203 . V_215 . V_216 . V_142 ;
V_211 [ 0 ] = F_85 ( V_212 [ 0 ] ) ;
V_211 [ 1 ] = F_85 ( V_212 [ 1 ] ) ;
V_211 [ 2 ] = F_85 ( V_212 [ 2 ] ) ;
V_135 -> V_217 = V_137 -> V_218 . V_219 . V_220 . V_221 ;
V_213 = V_135 -> V_117 ;
if ( V_142 -> V_222 == V_223 ) {
F_86 ( V_2 ,
(struct V_224 * )
V_213 , V_195 ) ;
if ( V_2 -> V_225 == 0 ) {
if ( V_135 -> V_109 & V_190 )
F_81 ( V_2 ) ;
else if ( V_135 -> V_109 & V_189 )
F_83 ( V_2 ) ;
}
} else {
F_21 (KERN_ERR PFX L_84 ,
fc_hdr->fh_r_ctl) ;
}
if ( ! V_49 -> V_53 . V_54 ) {
F_21 (KERN_ALERT PFX L_85 ) ;
return;
}
switch ( V_2 -> V_226 ) {
case V_227 :
if ( V_2 -> V_228 == 0 ) {
V_49 -> V_50 = V_229 << 16 ;
} else {
V_49 -> V_50 = ( V_229 << 16 ) | V_2 -> V_228 ;
}
if ( V_2 -> V_230 )
F_25 ( V_49 , V_2 -> V_230 ) ;
break;
default:
F_7 ( V_2 , L_86 ,
V_2 -> V_226 ) ;
break;
}
V_49 = V_2 -> V_49 ;
V_2 -> V_49 = NULL ;
if ( V_2 -> V_168 ) {
F_45 ( & V_2 -> V_78 ) ;
V_2 -> V_168 = 0 ;
} else {
F_21 (KERN_ALERT PFX L_87 ) ;
return;
}
V_49 -> V_53 . V_54 = NULL ;
V_49 -> V_55 ( V_49 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
if ( V_2 -> V_170 ) {
F_7 ( V_2 , L_88 ) ;
F_13 ( & V_2 -> V_29 ) ;
}
}
static int F_87 ( struct V_1 * V_2 , V_127 V_119 , int V_231 ,
int V_232 )
{
struct V_81 * V_233 = V_2 -> V_82 -> V_82 ;
int V_234 , V_235 ;
V_235 = 0 ;
while ( V_231 ) {
if ( V_231 >= V_236 )
V_234 = V_236 ;
else
V_234 = V_231 ;
V_233 [ V_232 + V_235 ] . V_125 = V_119 & 0xffffffff ;
V_233 [ V_232 + V_235 ] . V_126 = V_119 >> 32 ;
V_233 [ V_232 + V_235 ] . V_128 = ( T_2 ) V_234 ;
V_233 [ V_232 + V_235 ] . V_34 = 0 ;
V_119 += ( V_127 ) V_234 ;
V_235 ++ ;
V_231 -= V_234 ;
}
return V_235 ;
}
static int F_88 ( struct V_1 * V_2 )
{
struct V_48 * V_237 = V_2 -> V_49 ;
struct V_81 * V_233 = V_2 -> V_82 -> V_82 ;
struct V_238 * V_239 ;
int V_240 = 0 ;
int V_241 = 0 ;
int V_242 = 0 ;
int V_235 ;
unsigned int V_231 ;
V_127 V_119 ;
int V_65 ;
V_241 = F_89 ( V_237 ) ;
F_90 (sc, sg, sg_count, i) {
V_231 = F_91 ( V_239 ) ;
V_119 = F_92 ( V_239 ) ;
if ( V_231 > V_243 ) {
V_235 = F_87 ( V_2 , V_119 , V_231 ,
V_242 ) ;
} else {
V_235 = 1 ;
V_233 [ V_242 ] . V_125 = V_119 & 0xffffffff ;
V_233 [ V_242 ] . V_126 = V_119 >> 32 ;
V_233 [ V_242 ] . V_128 = ( T_2 ) V_231 ;
V_233 [ V_242 ] . V_34 = 0 ;
}
V_242 += V_235 ;
V_240 += V_231 ;
}
if ( V_240 != F_26 ( V_237 ) )
F_21 (KERN_ERR PFX L_89
L_90 , byte_count, scsi_bufflen(sc),
io_req->xid) ;
return V_242 ;
}
static void F_93 ( struct V_1 * V_2 )
{
struct V_48 * V_237 = V_2 -> V_49 ;
struct V_81 * V_233 = V_2 -> V_82 -> V_82 ;
int V_242 ;
if ( F_94 ( V_237 ) )
V_242 = F_88 ( V_2 ) ;
else {
V_242 = 0 ;
V_233 [ 0 ] . V_125 = V_233 [ 0 ] . V_126 = 0 ;
V_233 [ 0 ] . V_128 = V_233 [ 0 ] . V_34 = 0 ;
}
V_2 -> V_82 -> V_244 = V_242 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_48 * V_237 = V_2 -> V_49 ;
if ( V_2 -> V_82 -> V_244 && V_237 ) {
F_95 ( V_237 ) ;
V_2 -> V_82 -> V_244 = 0 ;
}
}
void F_63 ( struct V_1 * V_2 ,
struct V_121 * V_121 )
{
struct V_48 * V_49 = V_2 -> V_49 ;
char V_245 [ 2 ] ;
memset ( V_121 , 0 , sizeof( struct V_121 ) ) ;
F_96 ( V_49 -> V_131 -> V_210 ,
(struct V_246 * ) V_121 -> V_247 ) ;
V_121 -> V_158 = F_97 ( V_2 -> V_122 ) ;
memcpy ( V_121 -> V_156 , V_49 -> V_248 , V_49 -> V_157 ) ;
V_121 -> V_249 = 0 ;
V_121 -> V_250 = 0 ;
V_121 -> V_251 = V_2 -> V_107 . V_109 ;
V_121 -> V_252 = V_2 -> V_155 ;
if ( F_98 ( V_49 , V_245 ) ) {
switch ( V_245 [ 0 ] ) {
case V_253 :
V_121 -> V_250 = V_254 ;
break;
case V_255 :
V_121 -> V_250 = V_256 ;
break;
default:
V_121 -> V_250 = V_257 ;
break;
}
} else {
V_121 -> V_250 = 0 ;
}
}
static void F_86 ( struct V_1 * V_2 ,
struct V_224 * V_258 ,
T_1 V_195 )
{
struct V_48 * V_49 = V_2 -> V_49 ;
struct V_18 * V_19 = V_2 -> V_19 ;
T_1 V_259 = V_258 -> V_260 . V_34 ;
T_4 V_261 = 0 ;
int V_65 ;
unsigned char * V_262 ;
unsigned char * V_263 ;
int V_264 = 0 ;
int V_265 = 0 ;
V_2 -> V_226 = V_227 ;
V_2 -> V_230 = V_258 -> V_230 ;
V_2 -> V_266 = V_259 ;
F_99 ( V_49 ) = V_2 -> V_228 =
V_258 -> V_267 ;
if ( V_195 ) {
if ( V_259 &
V_268 ) {
V_265 = V_261
= V_258 -> V_265 ;
}
if ( V_259 &
V_269 ) {
V_264 = V_258 -> V_264 ;
V_261 += V_258 -> V_264 ;
}
V_2 -> V_265 = V_265 ;
V_2 -> V_264 = V_264 ;
if ( V_261 > V_195 * V_270 ) {
F_21 (KERN_ALERT PFX L_91 ,
rq_buff_len) ;
V_261 = V_195 * V_270 ;
}
V_262 = F_100 ( V_19 , 1 ) ;
if ( V_195 > 1 ) {
for ( V_65 = 1 ; V_65 < V_195 ; V_65 ++ )
V_263 = F_100 ( V_19 , 1 ) ;
}
if ( ( V_265 == 4 ) || ( V_265 == 8 ) ) {
V_2 -> V_225 = V_262 [ 3 ] ;
F_21 (KERN_ERR PFX L_92 ,
io_req->fcp_rsp_code) ;
}
V_262 += V_265 ;
if ( V_264 > V_271 ) {
F_21 (KERN_ERR PFX L_93 ) ;
V_264 = V_271 ;
}
memset ( V_49 -> V_272 , 0 , sizeof( V_49 -> V_272 ) ) ;
if ( V_264 )
memcpy ( V_49 -> V_272 , V_262 , V_264 ) ;
for ( V_65 = 0 ; V_65 < V_195 ; V_65 ++ )
F_101 ( V_19 , 1 ) ;
}
}
int F_102 ( struct V_139 * V_140 ,
struct V_48 * V_49 )
{
struct V_13 * V_14 = F_58 ( V_140 ) ;
struct V_129 * V_130 = F_56 ( F_57 ( V_49 -> V_131 ) ) ;
struct V_132 * V_133 = V_130 -> V_134 ;
struct V_18 * V_19 ;
struct V_1 * V_2 ;
int V_21 = 0 ;
int V_273 ;
V_273 = F_103 ( V_130 ) ;
if ( V_273 ) {
V_49 -> V_50 = V_273 ;
V_49 -> V_55 ( V_49 ) ;
return 0 ;
}
if ( ( V_14 -> V_149 != V_150 ) || ! ( V_14 -> V_151 ) ) {
V_21 = V_274 ;
goto V_275;
}
V_19 = (struct V_18 * ) & V_133 [ 1 ] ;
if ( ! F_14 ( V_152 , & V_19 -> V_34 ) ) {
if ( F_14 ( V_276 , & V_19 -> V_34 ) ) {
V_49 -> V_50 = V_277 << 16 ;
V_49 -> V_55 ( V_49 ) ;
return 0 ;
}
V_21 = V_278 ;
goto V_275;
}
V_2 = F_48 ( V_19 ) ;
if ( ! V_2 ) {
V_21 = V_274 ;
goto V_275;
}
V_2 -> V_49 = V_49 ;
if ( F_104 ( V_19 , V_2 ) ) {
F_21 (KERN_ERR PFX L_94 ) ;
V_21 = V_274 ;
goto V_275;
}
V_275:
return V_21 ;
}
void F_105 ( struct V_1 * V_2 ,
struct V_136 * V_137 ,
T_1 V_195 )
{
struct V_224 * V_258 ;
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_48 * V_49 ;
struct V_139 * V_140 ;
if ( F_15 ( V_40 , & V_2 -> V_22 ) ) {
F_7 ( V_2 , L_95
L_96 ) ;
}
if ( F_77 ( & V_2 -> V_9 ) )
F_16 ( & V_2 -> V_10 ,
V_35 ) ;
V_49 = V_2 -> V_49 ;
if ( V_49 == NULL ) {
F_21 (KERN_ERR PFX L_97 ) ;
return;
}
V_258 = (struct V_224 * )
& ( V_137 -> V_202 . V_203 . V_204 . V_258 . V_279 ) ;
F_86 ( V_2 , V_258 , V_195 ) ;
V_140 = V_49 -> V_131 -> V_140 ;
if ( ! V_49 -> V_53 . V_54 ) {
F_21 (KERN_ERR PFX L_98 ) ;
return;
}
V_2 -> V_49 = NULL ;
if ( V_2 -> V_192 ) {
F_45 ( & V_2 -> V_78 ) ;
V_2 -> V_192 = 0 ;
F_34 ( & V_2 -> V_78 , & V_19 -> V_194 ) ;
} else {
F_7 ( V_2 , L_99 ) ;
if ( V_2 -> V_170 )
if ( F_9 ( V_28 ,
& V_2 -> V_22 ) )
F_13 ( & V_2 -> V_29 ) ;
}
F_23 ( V_2 ) ;
switch ( V_2 -> V_226 ) {
case V_227 :
if ( V_2 -> V_228 == 0 ) {
V_49 -> V_50 = V_229 << 16 ;
} else {
F_7 ( V_2 , L_100
L_101 ,
V_2 -> V_228 , V_2 -> V_230 ) ;
V_49 -> V_50 = ( V_229 << 16 ) | V_2 -> V_228 ;
}
if ( V_2 -> V_230 )
F_25 ( V_49 , V_2 -> V_230 ) ;
break;
default:
F_21 (KERN_ALERT PFX L_102 ,
io_req->fcp_status) ;
break;
}
V_49 -> V_53 . V_54 = NULL ;
V_49 -> V_55 ( V_49 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
}
static int F_104 ( struct V_18 * V_19 ,
struct V_1 * V_2 )
{
struct V_136 * V_137 ;
struct V_136 * V_138 ;
struct V_48 * V_49 = V_2 -> V_49 ;
struct V_92 * V_6 = V_19 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_13 * V_14 = V_6 -> V_14 ;
struct V_280 * V_281 ;
int V_143 , V_95 ;
T_2 V_64 ;
V_2 -> V_17 = V_27 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_19 = V_19 ;
V_2 -> V_122 = F_26 ( V_49 ) ;
V_49 -> V_53 . V_54 = ( char * ) V_2 ;
V_281 = F_106 ( V_14 -> V_282 , F_49 () ) ;
if ( V_49 -> V_283 == V_284 ) {
V_2 -> V_155 = V_285 ;
V_281 -> V_286 ++ ;
V_281 -> V_287 += V_2 -> V_122 ;
} else if ( V_49 -> V_283 == V_288 ) {
V_2 -> V_155 = V_289 ;
V_281 -> V_290 ++ ;
V_281 -> V_291 += V_2 -> V_122 ;
} else {
V_2 -> V_155 = 0 ;
V_281 -> V_292 ++ ;
}
F_50 () ;
V_64 = V_2 -> V_64 ;
F_93 ( V_2 ) ;
V_143 = V_64 / V_166 ;
V_95 = V_64 % V_166 ;
V_138 = (struct V_136 * ) V_5 -> V_167 [ V_143 ] ;
V_137 = & ( V_138 [ V_95 ] ) ;
F_107 ( V_2 , V_137 ) ;
F_8 ( & V_19 -> V_23 ) ;
if ( V_19 -> V_191 ) {
F_21 (KERN_ERR PFX L_103 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
F_11 ( & V_19 -> V_23 ) ;
return - V_293 ;
}
if ( ! F_14 ( V_152 , & V_19 -> V_34 ) ) {
F_21 (KERN_ERR PFX L_104 ) ;
F_16 ( & V_2 -> V_10 , V_35 ) ;
F_11 ( & V_19 -> V_23 ) ;
return - V_293 ;
}
F_1 ( V_2 , V_294 ) ;
F_66 ( V_19 , V_64 ) ;
V_2 -> V_192 = 1 ;
F_34 ( & V_2 -> V_78 , & V_19 -> V_295 ) ;
F_68 ( V_19 ) ;
F_11 ( & V_19 -> V_23 ) ;
return 0 ;
}
