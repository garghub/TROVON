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
T_1 V_13 = V_2 -> V_13 ;
struct V_14 * V_15 = V_2 -> V_15 ;
int V_16 ;
F_7 ( V_2 , L_1
L_2 , V_13 , V_2 -> V_17 ) ;
F_8 ( & V_15 -> V_18 ) ;
if ( F_9 ( V_19 , & V_2 -> V_17 ) ) {
F_10 ( V_20 , & V_2 -> V_17 ) ;
F_11 ( & V_15 -> V_18 ) ;
F_12 ( V_2 ) ;
return;
}
if ( F_9 ( V_20 , & V_2 -> V_17 ) ) {
F_7 ( V_2 , L_3 ) ;
goto V_21;
}
switch ( V_13 ) {
case V_22 :
if ( F_9 ( V_23 ,
& V_2 -> V_17 ) ) {
F_7 ( V_2 , L_4 ) ;
F_13 ( & V_2 -> V_24 ) ;
} else if ( F_14 ( V_25 ,
& V_2 -> V_17 ) ) {
F_7 ( V_2 , L_5 ,
V_2 -> V_10 . V_10 . V_26 ) ;
if ( ! ( F_15 ( V_27 ,
& V_2 -> V_17 ) ) ) {
F_16 ( V_2 ) ;
F_17 ( & V_2 -> V_10 , V_28 ) ;
F_11 ( & V_15 -> V_18 ) ;
return;
}
} else {
F_7 ( V_2 , L_6 ) ;
if ( F_15 ( V_29 ,
& V_2 -> V_17 ) ) {
F_7 ( V_2 , L_7
L_8 ) ;
goto V_21;
}
if ( ! F_15 ( V_25 ,
& V_2 -> V_17 ) ) {
V_16 = F_18 ( V_2 ) ;
if ( V_16 == V_30 )
goto V_21;
F_17 ( & V_2 -> V_10 , V_28 ) ;
F_11 ( & V_15 -> V_18 ) ;
return;
} else {
F_7 ( V_2 , L_9
L_10 ) ;
}
}
break;
case V_31 :
if ( F_14 ( V_25 , & V_2 -> V_17 ) ) {
F_7 ( V_2 , L_11 ) ;
if ( ! F_15 ( V_27 ,
& V_2 -> V_17 ) ) {
F_17 ( & V_2 -> V_10 , V_28 ) ;
F_11 ( & V_15 -> V_18 ) ;
return;
}
} else {
F_7 ( V_2 , L_12 ) ;
if ( F_15 ( V_32 ,
& V_2 -> V_17 ) )
goto V_21;
F_19 ( V_33 , & V_2 -> V_17 ) ;
if ( ( V_2 -> V_34 ) && ( V_2 -> V_35 ) ) {
V_2 -> V_34 ( V_2 -> V_35 ) ;
V_2 -> V_35 = NULL ;
}
}
break;
default:
F_20 (KERN_ERR PFX L_13 ,
cmd_type) ;
break;
}
V_21:
F_17 ( & V_2 -> V_10 , V_28 ) ;
F_11 ( & V_15 -> V_18 ) ;
}
static void F_21 ( struct V_1 * V_2 , int V_36 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
if ( V_2 -> V_13 != V_22 )
return;
F_7 ( V_2 , L_14 , V_36 ) ;
if ( F_14 ( V_39 , & V_2 -> V_17 ) ) {
return;
}
F_22 ( V_2 ) ;
V_2 -> V_38 = NULL ;
if ( ! V_38 ) {
F_20 (KERN_ERR PFX L_15
L_16 ,
io_req->xid) ;
return;
}
V_38 -> V_40 = V_36 << 16 ;
F_7 ( V_2 , L_17 ,
V_38 , F_23 ( V_38 -> V_40 ) , V_38 -> V_41 ,
V_38 -> V_42 ) ;
F_24 ( V_38 , F_25 ( V_38 ) ) ;
V_38 -> V_43 . V_44 = NULL ;
V_38 -> V_45 ( V_38 ) ;
}
struct V_46 * F_26 ( struct V_47 * V_48 )
{
struct V_46 * V_49 ;
struct V_50 * V_51 ;
struct V_1 * V_2 ;
T_2 V_52 ;
T_3 V_53 ;
T_4 V_54 ;
int V_55 ;
int V_56 , V_57 ;
T_2 V_58 ;
int V_59 = F_27 () + 1 ;
T_4 V_60 = V_61 ;
T_4 V_62 = V_48 -> V_62 ;
if ( V_62 <= V_60 || V_62 == V_63 ) {
F_20 (KERN_ERR PFX L_18 , min_xid, max_xid) ;
return NULL ;
}
F_28 ( L_19 , V_60 , V_62 ) ;
V_56 = V_62 - V_60 + 1 ;
V_52 = ( V_56 * ( sizeof( struct V_1 * ) ) ) ;
V_52 += sizeof( struct V_46 ) ;
V_49 = F_29 ( V_52 , V_64 ) ;
if ( ! V_49 ) {
F_20 (KERN_ERR PFX L_20 ) ;
return NULL ;
}
V_49 -> V_65 = F_29 ( sizeof( * V_49 -> V_65 ) *
V_59 , V_64 ) ;
if ( ! V_49 -> V_65 ) {
F_20 (KERN_ERR PFX L_21 ) ;
goto V_66;
}
V_49 -> V_67 = F_29 ( sizeof( * V_49 -> V_67 ) *
V_59 , V_64 ) ;
if ( ! V_49 -> V_67 ) {
F_20 (KERN_ERR PFX L_22 ) ;
F_30 ( V_49 -> V_65 ) ;
V_49 -> V_65 = NULL ;
goto V_66;
}
V_49 -> V_48 = V_48 ;
V_49 -> V_68 = (struct V_1 * * ) ( V_49 + 1 ) ;
for ( V_55 = 0 ; V_55 < V_59 ; V_55 ++ ) {
F_31 ( & V_49 -> V_65 [ V_55 ] ) ;
F_32 ( & V_49 -> V_67 [ V_55 ] ) ;
}
V_54 = V_61 ;
V_57 = V_56 - V_48 -> V_69 ;
for ( V_55 = 0 ; V_55 < V_56 ; V_55 ++ ) {
V_2 = F_29 ( sizeof( * V_2 ) , V_64 ) ;
if ( ! V_2 ) {
F_20 (KERN_ERR PFX L_23 ) ;
goto V_66;
}
F_31 ( & V_2 -> V_70 ) ;
F_33 ( & V_2 -> V_9 , F_5 ) ;
V_2 -> V_54 = V_54 ++ ;
if ( V_55 < V_57 )
F_34 ( & V_2 -> V_70 ,
& V_49 -> V_65 [ V_2 -> V_54 %
F_27 () ] ) ;
else
F_34 ( & V_2 -> V_70 ,
& V_49 -> V_65 [ F_27 () ] ) ;
V_2 ++ ;
}
V_53 = V_56 * sizeof( struct V_50 * ) ;
V_49 -> V_71 = F_35 ( V_53 , V_64 ) ;
if ( ! V_49 -> V_71 ) {
F_20 (KERN_ERR PFX L_24 ) ;
goto V_66;
}
V_53 = sizeof( struct V_50 ) ;
for ( V_55 = 0 ; V_55 < V_56 ; V_55 ++ ) {
V_49 -> V_71 [ V_55 ] = F_35 ( V_53 , V_64 ) ;
if ( ! V_49 -> V_71 [ V_55 ] ) {
F_20 (KERN_ERR PFX L_25
L_26 , i) ;
goto V_66;
}
}
V_58 = V_72 * sizeof( struct V_73 ) ;
for ( V_55 = 0 ; V_55 < V_56 ; V_55 ++ ) {
V_51 = V_49 -> V_71 [ V_55 ] ;
V_51 -> V_74 = F_36 ( & V_48 -> V_75 -> V_76 ,
V_58 ,
& V_51 -> V_77 ,
V_64 ) ;
if ( ! V_51 -> V_74 ) {
F_20 (KERN_ERR PFX L_25
L_27 , i) ;
goto V_66;
}
}
return V_49 ;
V_66:
F_37 ( V_49 ) ;
return NULL ;
}
void F_37 ( struct V_46 * V_49 )
{
struct V_50 * V_51 ;
struct V_47 * V_48 = V_49 -> V_48 ;
T_2 V_58 ;
T_4 V_60 = V_61 ;
T_4 V_62 = V_48 -> V_62 ;
int V_56 ;
int V_55 ;
V_56 = V_62 - V_60 + 1 ;
if ( ! V_49 -> V_71 )
goto V_78;
V_58 = V_72 * sizeof( struct V_73 ) ;
for ( V_55 = 0 ; V_55 < V_56 ; V_55 ++ ) {
V_51 = V_49 -> V_71 [ V_55 ] ;
if ( V_51 -> V_74 ) {
F_38 ( & V_48 -> V_75 -> V_76 , V_58 ,
V_51 -> V_74 ,
V_51 -> V_77 ) ;
V_51 -> V_74 = NULL ;
}
}
for ( V_55 = 0 ; V_55 < V_56 ; V_55 ++ ) {
F_30 ( V_49 -> V_71 [ V_55 ] ) ;
V_49 -> V_71 [ V_55 ] = NULL ;
}
F_30 ( V_49 -> V_71 ) ;
V_49 -> V_71 = NULL ;
V_78:
F_30 ( V_49 -> V_67 ) ;
if ( ! V_49 -> V_65 )
goto V_79;
for ( V_55 = 0 ; V_55 < F_27 () + 1 ; V_55 ++ ) {
struct V_1 * V_80 , * V_2 ;
F_39 (io_req, tmp,
&cmgr->free_list[i], link) {
F_40 ( & V_2 -> V_70 ) ;
F_30 ( V_2 ) ;
}
}
F_30 ( V_49 -> V_65 ) ;
V_79:
F_30 ( V_49 ) ;
}
struct V_1 * F_41 ( struct V_14 * V_15 , int type )
{
struct V_81 * V_6 = V_15 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_46 * V_82 = V_5 -> V_48 -> V_82 ;
struct V_1 * V_2 ;
struct V_83 * V_84 ;
struct V_50 * V_74 ;
int V_85 = V_86 ;
T_3 V_87 ;
T_3 V_88 ;
T_4 V_54 ;
V_88 = V_15 -> V_88 ;
switch ( type ) {
case V_89 :
V_88 = V_90 ;
break;
case V_31 :
V_88 = V_91 ;
break;
default:
break;
}
F_8 ( & V_82 -> V_67 [ V_85 ] ) ;
V_87 = F_42 ( & V_15 -> V_87 ) ;
if ( ( F_43 ( & ( V_82 -> V_65 [ V_85 ] ) ) ) ||
( V_15 -> V_92 . V_26 >= V_88 ) ||
( V_87 + V_88 <= V_93 ) ) {
F_44 ( V_15 , L_28
L_29 ,
V_15 -> V_92 . V_26 , V_15 -> V_88 ) ;
if ( F_43 ( & ( V_82 -> V_65 [ V_85 ] ) ) )
F_20 (KERN_ERR PFX L_30 ) ;
F_11 ( & V_82 -> V_67 [ V_85 ] ) ;
return NULL ;
}
V_84 = (struct V_83 * )
V_82 -> V_65 [ V_85 ] . V_94 ;
F_45 ( V_84 ) ;
V_2 = (struct V_1 * ) V_84 ;
V_54 = V_2 -> V_54 ;
V_82 -> V_68 [ V_54 ] = V_2 ;
F_46 ( & V_15 -> V_92 ) ;
F_47 ( & V_15 -> V_87 ) ;
F_11 ( & V_82 -> V_67 [ V_85 ] ) ;
F_31 ( & V_2 -> V_70 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_82 = V_82 ;
V_2 -> V_17 = 0 ;
V_2 -> V_13 = type ;
V_74 = V_2 -> V_74 = V_82 -> V_71 [ V_54 ] ;
V_74 -> V_2 = V_2 ;
F_48 ( & V_2 -> V_10 ) ;
return V_2 ;
}
struct V_1 * F_49 ( struct V_14 * V_15 )
{
struct V_81 * V_6 = V_15 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_46 * V_82 = V_5 -> V_48 -> V_82 ;
struct V_1 * V_2 ;
struct V_83 * V_84 ;
struct V_50 * V_74 ;
T_3 V_87 ;
T_3 V_88 ;
T_4 V_54 ;
int V_85 = F_50 () ;
V_88 = V_95 ;
F_8 ( & V_82 -> V_67 [ V_85 ] ) ;
V_87 = F_42 ( & V_15 -> V_87 ) ;
if ( ( F_43 ( & V_82 -> V_65 [ V_85 ] ) ) ||
( V_15 -> V_92 . V_26 >= V_88 ) ||
( V_87 + V_88 <= V_93 ) ) {
F_11 ( & V_82 -> V_67 [ V_85 ] ) ;
F_51 () ;
return NULL ;
}
V_84 = (struct V_83 * )
V_82 -> V_65 [ V_85 ] . V_94 ;
F_45 ( V_84 ) ;
V_2 = (struct V_1 * ) V_84 ;
V_54 = V_2 -> V_54 ;
V_82 -> V_68 [ V_54 ] = V_2 ;
F_46 ( & V_15 -> V_92 ) ;
F_47 ( & V_15 -> V_87 ) ;
F_11 ( & V_82 -> V_67 [ V_85 ] ) ;
F_51 () ;
F_31 ( & V_2 -> V_70 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_82 = V_82 ;
V_2 -> V_17 = 0 ;
V_74 = V_2 -> V_74 = V_82 -> V_71 [ V_54 ] ;
V_74 -> V_2 = V_2 ;
F_48 ( & V_2 -> V_10 ) ;
return V_2 ;
}
void V_28 ( struct V_96 * V_97 )
{
struct V_1 * V_2 = F_6 ( V_97 ,
struct V_1 , V_10 ) ;
struct V_46 * V_82 = V_2 -> V_82 ;
int V_85 ;
if ( V_2 -> V_13 == V_22 )
V_85 = V_2 -> V_54 % F_27 () ;
else
V_85 = V_86 ;
F_8 ( & V_82 -> V_67 [ V_85 ] ) ;
if ( V_2 -> V_13 != V_22 )
F_52 ( V_2 ) ;
V_82 -> V_68 [ V_2 -> V_54 ] = NULL ;
F_45 ( & V_2 -> V_70 ) ;
F_53 ( & V_2 -> V_70 ,
& V_82 -> V_65 [ V_85 ] ) ;
F_47 ( & V_2 -> V_15 -> V_92 ) ;
F_11 ( & V_82 -> V_67 [ V_85 ] ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_98 * V_99 = & ( V_2 -> V_99 ) ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
struct V_47 * V_48 = V_5 -> V_48 ;
T_2 V_100 = sizeof( struct V_73 ) ;
V_99 -> V_101 = 0 ;
if ( V_99 -> V_102 ) {
F_38 ( & V_48 -> V_75 -> V_76 , V_100 ,
V_99 -> V_102 ,
V_99 -> V_103 ) ;
V_99 -> V_102 = NULL ;
}
if ( V_99 -> V_104 ) {
F_38 ( & V_48 -> V_75 -> V_76 , V_100 ,
V_99 -> V_104 ,
V_99 -> V_105 ) ;
V_99 -> V_104 = NULL ;
}
if ( V_99 -> V_106 ) {
F_38 ( & V_48 -> V_75 -> V_76 , V_107 ,
V_99 -> V_106 ,
V_99 -> V_108 ) ;
V_99 -> V_106 = NULL ;
}
if ( V_99 -> V_109 ) {
F_38 ( & V_48 -> V_75 -> V_76 , V_107 ,
V_99 -> V_109 ,
V_99 -> V_110 ) ;
V_99 -> V_109 = NULL ;
}
}
int F_54 ( struct V_1 * V_2 )
{
struct V_98 * V_99 ;
struct V_73 * V_102 ;
struct V_73 * V_104 ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
struct V_47 * V_48 = V_5 -> V_48 ;
T_5 V_111 ;
T_2 V_100 ;
V_99 = (struct V_98 * ) & ( V_2 -> V_99 ) ;
memset ( V_99 , 0 , sizeof( struct V_98 ) ) ;
if ( V_2 -> V_13 != V_31 ) {
V_99 -> V_112 = sizeof( struct V_113 ) ;
V_2 -> V_114 = V_99 -> V_112 ;
} else
V_99 -> V_112 = V_2 -> V_114 ;
V_99 -> V_106 = F_36 ( & V_48 -> V_75 -> V_76 , V_107 ,
& V_99 -> V_108 ,
V_115 ) ;
if ( ! V_99 -> V_106 ) {
F_20 (KERN_ERR PFX L_31 ) ;
F_52 ( V_2 ) ;
return V_116 ;
}
V_99 -> V_109 = F_36 ( & V_48 -> V_75 -> V_76 , V_107 ,
& V_99 -> V_110 ,
V_115 ) ;
if ( ! V_99 -> V_109 ) {
F_20 (KERN_ERR PFX L_32 ) ;
F_52 ( V_2 ) ;
return V_116 ;
}
memset ( V_99 -> V_106 , 0 , V_107 ) ;
memset ( V_99 -> V_109 , 0 , V_107 ) ;
V_100 = sizeof( struct V_73 ) ;
V_99 -> V_102 = F_36 ( & V_48 -> V_75 -> V_76 , V_100 ,
& V_99 -> V_103 ,
V_115 ) ;
if ( ! V_99 -> V_102 ) {
F_20 (KERN_ERR PFX L_33 ) ;
F_52 ( V_2 ) ;
return V_116 ;
}
V_99 -> V_104 = F_36 ( & V_48 -> V_75 -> V_76 , V_100 ,
& V_99 -> V_105 ,
V_115 ) ;
if ( ! V_99 -> V_104 ) {
F_20 (KERN_ERR PFX L_34 ) ;
F_52 ( V_2 ) ;
return V_116 ;
}
V_111 = V_99 -> V_108 ;
V_102 = V_99 -> V_102 ;
V_102 -> V_117 = ( T_3 ) V_111 & 0xffffffff ;
V_102 -> V_118 = ( T_3 ) ( ( V_119 ) V_111 >> 32 ) ;
V_102 -> V_120 = V_107 ;
V_102 -> V_121 = 0 ;
V_104 = V_99 -> V_104 ;
V_111 = V_99 -> V_110 ;
V_104 -> V_117 = ( T_3 ) V_111 & 0xffffffff ;
V_104 -> V_118 = ( T_3 ) ( ( V_119 ) V_111 >> 32 ) ;
V_104 -> V_120 = V_107 ;
V_104 -> V_121 = 0 ;
return V_30 ;
}
static int F_55 ( struct V_37 * V_38 , T_1 V_101 )
{
struct V_122 * V_123 ;
struct V_124 * V_125 ;
struct V_126 * V_127 ;
struct V_81 * V_6 ;
struct V_4 * V_5 ;
struct V_14 * V_15 ;
struct V_1 * V_2 ;
struct V_98 * V_128 ;
struct V_129 * V_130 ;
struct V_129 * V_131 ;
struct V_132 * V_133 = V_38 -> V_134 -> V_133 ;
struct V_135 * V_136 ;
struct V_113 * V_113 ;
int V_137 , V_85 ;
int V_16 = V_30 ;
T_4 V_54 ;
T_3 V_138 , V_139 ;
unsigned long V_140 = V_141 ;
V_123 = F_56 ( V_133 ) ;
V_125 = F_57 ( F_58 ( V_38 -> V_134 ) ) ;
V_6 = F_59 ( V_123 ) ;
V_5 = V_6 -> V_7 ;
if ( V_125 == NULL ) {
F_20 (KERN_ERR PFX L_35 ) ;
V_16 = V_116 ;
goto V_142;
}
V_127 = V_125 -> V_143 ;
V_16 = F_60 ( V_38 ) ;
if ( V_16 )
return V_16 ;
if ( V_123 -> V_144 != V_145 || ! ( V_123 -> V_146 ) ) {
F_20 (KERN_ERR PFX L_36 ) ;
V_16 = V_116 ;
goto V_142;
}
V_15 = (struct V_14 * ) & V_127 [ 1 ] ;
if ( ! ( F_14 ( V_147 , & V_15 -> V_121 ) ) ) {
F_20 (KERN_ERR PFX L_37 ) ;
V_16 = V_116 ;
goto V_142;
}
V_148:
V_2 = F_41 ( V_15 , V_89 ) ;
if ( ! V_2 ) {
if ( F_61 ( V_141 , V_140 + V_149 ) ) {
F_20 (KERN_ERR PFX L_38 ) ;
V_16 = V_116 ;
goto V_142;
}
F_62 ( 20 ) ;
goto V_148;
}
V_2 -> V_38 = V_38 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_15 = V_15 ;
V_128 = (struct V_98 * ) & ( V_2 -> V_99 ) ;
V_16 = F_54 ( V_2 ) ;
if ( V_16 == V_116 ) {
F_20 (KERN_ERR PFX L_39 ) ;
F_8 ( & V_15 -> V_18 ) ;
F_17 ( & V_2 -> V_10 , V_28 ) ;
F_11 ( & V_15 -> V_18 ) ;
goto V_142;
}
V_2 -> V_150 = 0 ;
V_128 -> V_101 = V_101 ;
F_63 ( V_2 , (struct V_113 * ) V_128 -> V_106 ) ;
V_113 = (struct V_113 * ) V_128 -> V_106 ;
memset ( V_113 -> V_151 , 0 , V_38 -> V_152 ) ;
V_113 -> V_153 = 0 ;
V_136 = & ( V_128 -> V_154 ) ;
V_138 = V_15 -> V_138 ;
V_139 = V_125 -> V_155 ;
F_64 ( V_136 , V_156 , V_139 , V_138 ,
V_157 , V_158 | V_159 |
V_160 , 0 ) ;
V_54 = V_2 -> V_54 ;
F_44 ( V_15 , L_40 , V_54 ) ;
V_137 = V_54 / V_161 ;
V_85 = V_54 % V_161 ;
V_131 = (struct V_129 * )
V_5 -> V_48 -> V_162 [ V_137 ] ;
V_130 = & ( V_131 [ V_85 ] ) ;
F_65 ( V_2 , V_130 ) ;
V_38 -> V_43 . V_44 = ( char * ) V_2 ;
F_8 ( & V_15 -> V_18 ) ;
F_66 ( V_15 , V_54 ) ;
V_2 -> V_163 = 1 ;
F_34 ( & V_2 -> V_70 , & V_15 -> V_164 ) ;
F_67 ( & V_2 -> V_24 ) ;
V_2 -> V_165 = 1 ;
F_68 ( V_15 ) ;
F_11 ( & V_15 -> V_18 ) ;
V_16 = F_69 ( & V_2 -> V_24 ,
V_166 * V_149 ) ;
F_8 ( & V_15 -> V_18 ) ;
V_2 -> V_165 = 0 ;
if ( ! ( F_14 ( V_167 , & V_2 -> V_17 ) ) ) {
F_19 ( V_168 , & V_2 -> V_17 ) ;
if ( V_2 -> V_163 ) {
F_45 ( & V_2 -> V_70 ) ;
V_2 -> V_163 = 0 ;
}
V_2 -> V_165 = 1 ;
F_16 ( V_2 ) ;
F_11 ( & V_15 -> V_18 ) ;
V_16 = F_69 ( & V_2 -> V_24 ,
V_169 ) ;
F_8 ( & V_15 -> V_18 ) ;
V_2 -> V_165 = 0 ;
if ( ! V_16 )
F_17 ( & V_2 -> V_10 , V_28 ) ;
}
F_11 ( & V_15 -> V_18 ) ;
if ( ! V_16 ) {
F_44 ( V_15 , L_41 ) ;
V_16 = V_116 ;
} else {
F_44 ( V_15 , L_42 ) ;
V_16 = V_30 ;
}
V_142:
return V_16 ;
}
int F_18 ( struct V_1 * V_2 )
{
struct V_122 * V_123 ;
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_124 * V_125 = V_15 -> V_125 ;
struct V_170 * V_171 = V_15 -> V_171 ;
struct V_4 * V_5 ;
struct V_81 * V_6 ;
struct V_1 * V_172 ;
struct V_129 * V_130 ;
struct V_129 * V_131 ;
struct V_135 * V_136 ;
struct V_98 * V_173 ;
int V_137 , V_85 ;
T_3 V_138 , V_139 ;
T_4 V_54 ;
int V_16 = V_30 ;
T_3 V_174 = V_171 -> V_174 ;
F_7 ( V_2 , L_43 ) ;
V_6 = V_2 -> V_6 ;
V_5 = V_6 -> V_7 ;
V_123 = V_6 -> V_123 ;
if ( ! F_14 ( V_147 , & V_15 -> V_121 ) ) {
F_20 (KERN_ERR PFX L_44 ) ;
V_16 = V_116 ;
goto V_175;
}
if ( V_125 == NULL ) {
F_20 (KERN_ERR PFX L_45 ) ;
V_16 = V_116 ;
goto V_175;
}
if ( V_123 -> V_144 != V_145 || ! ( V_123 -> V_146 ) ) {
F_20 (KERN_ERR PFX L_46 ) ;
V_16 = V_116 ;
goto V_175;
}
V_172 = F_41 ( V_15 , V_176 ) ;
if ( ! V_172 ) {
F_20 (KERN_ERR PFX L_47 ) ;
V_16 = V_116 ;
goto V_175;
}
V_172 -> V_38 = NULL ;
V_172 -> V_6 = V_6 ;
V_172 -> V_15 = V_15 ;
V_172 -> V_114 = 0 ;
V_173 = (struct V_98 * ) & ( V_172 -> V_99 ) ;
memset ( V_173 , 0 , sizeof( struct V_98 ) ) ;
V_136 = & ( V_173 -> V_154 ) ;
V_136 -> V_177 = F_70 ( V_2 -> V_54 ) ;
V_136 -> V_178 = F_70 ( V_2 -> V_130 -> V_179 . V_180 . V_181 ) ;
V_138 = V_15 -> V_138 ;
V_139 = V_125 -> V_155 ;
F_64 ( V_136 , V_182 , V_139 , V_138 ,
V_183 , V_158 | V_159 |
V_160 , 0 ) ;
V_54 = V_172 -> V_54 ;
F_7 ( V_172 , L_48 ) ;
V_137 = V_54 / V_161 ;
V_85 = V_54 % V_161 ;
V_131 = (struct V_129 * )
V_5 -> V_48 -> V_162 [ V_137 ] ;
V_130 = & ( V_131 [ V_85 ] ) ;
F_65 ( V_172 , V_130 ) ;
F_1 ( V_2 , 2 * V_174 ) ;
F_66 ( V_15 , V_54 ) ;
F_68 ( V_15 ) ;
V_175:
return V_16 ;
}
int F_71 ( struct V_1 * V_184 , T_3 V_185 ,
enum V_186 V_187 )
{
struct V_122 * V_123 ;
struct V_14 * V_15 = V_184 -> V_15 ;
struct V_4 * V_5 ;
struct V_81 * V_6 ;
struct V_1 * V_188 ;
struct V_129 * V_130 ;
struct V_129 * V_131 ;
struct V_189 * V_35 = NULL ;
int V_137 , V_85 ;
T_4 V_54 ;
int V_16 = 0 ;
F_7 ( V_184 , L_49 ,
V_184 -> V_54 ) ;
F_4 ( & V_184 -> V_10 ) ;
V_6 = V_184 -> V_6 ;
V_5 = V_6 -> V_7 ;
V_123 = V_6 -> V_123 ;
V_35 = F_29 ( sizeof( struct V_189 ) , V_115 ) ;
if ( ! V_35 ) {
F_20 (KERN_ERR PFX L_50 ) ;
V_16 = - V_190 ;
goto V_191;
}
V_188 = F_41 ( V_15 , V_192 ) ;
if ( ! V_188 ) {
F_20 (KERN_ERR PFX L_51 ) ;
V_16 = - V_190 ;
F_30 ( V_35 ) ;
goto V_191;
}
V_188 -> V_38 = NULL ;
V_188 -> V_6 = V_6 ;
V_188 -> V_15 = V_15 ;
V_188 -> V_114 = 0 ;
V_54 = V_188 -> V_54 ;
V_137 = V_54 / V_161 ;
V_85 = V_54 % V_161 ;
V_131 = (struct V_129 * )
V_5 -> V_48 -> V_162 [ V_137 ] ;
V_130 = & ( V_131 [ V_85 ] ) ;
V_35 -> V_193 = V_184 ;
V_35 -> V_2 = V_188 ;
V_35 -> V_187 = V_187 ;
V_35 -> V_185 = V_185 ;
V_188 -> V_35 = V_35 ;
F_20 (KERN_ERR PFX L_52 ) ;
F_72 ( V_188 , V_130 , V_184 , V_185 ) ;
F_66 ( V_15 , V_54 ) ;
F_68 ( V_15 ) ;
V_191:
return V_16 ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_122 * V_123 ;
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_4 * V_5 ;
struct V_81 * V_6 ;
struct V_1 * V_194 ;
struct V_129 * V_130 ;
struct V_129 * V_131 ;
int V_137 , V_85 ;
T_4 V_54 , V_195 ;
int V_16 = 0 ;
F_7 ( V_2 , L_53 ) ;
V_6 = V_2 -> V_6 ;
V_5 = V_6 -> V_7 ;
V_123 = V_6 -> V_123 ;
V_194 = F_41 ( V_15 , V_196 ) ;
if ( ! V_194 ) {
F_20 (KERN_ERR PFX L_51 ) ;
V_16 = - 1 ;
goto V_191;
}
V_194 -> V_38 = NULL ;
V_194 -> V_6 = V_6 ;
V_194 -> V_15 = V_15 ;
V_194 -> V_114 = 0 ;
V_54 = V_194 -> V_54 ;
V_137 = V_54 / V_161 ;
V_85 = V_54 % V_161 ;
V_131 = (struct V_129 * )
V_5 -> V_48 -> V_162 [ V_137 ] ;
V_130 = & ( V_131 [ V_85 ] ) ;
V_195 = V_2 -> V_54 ;
F_7 ( V_2 , L_54 , V_54 ) ;
F_73 ( V_194 , V_130 , V_195 ) ;
F_66 ( V_15 , V_54 ) ;
F_68 ( V_15 ) ;
V_191:
return V_16 ;
}
int F_74 ( struct V_37 * V_38 )
{
return F_55 ( V_38 , V_197 ) ;
}
int F_75 ( struct V_37 * V_38 )
{
return F_55 ( V_38 , V_198 ) ;
}
int F_76 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
int V_16 = V_30 ;
V_2 -> V_165 = 1 ;
F_16 ( V_2 ) ;
F_11 ( & V_15 -> V_18 ) ;
F_77 ( & V_2 -> V_24 ) ;
V_2 -> V_165 = 0 ;
F_17 ( & V_2 -> V_10 , V_28 ) ;
F_8 ( & V_15 -> V_18 ) ;
return V_16 ;
}
int F_78 ( struct V_37 * V_38 )
{
struct V_124 * V_125 = F_57 ( F_58 ( V_38 -> V_134 ) ) ;
struct V_126 * V_127 = V_125 -> V_143 ;
struct V_1 * V_2 ;
struct V_122 * V_123 ;
struct V_14 * V_15 ;
int V_16 ;
V_16 = F_60 ( V_38 ) ;
if ( V_16 )
return V_16 ;
V_123 = F_56 ( V_38 -> V_134 -> V_133 ) ;
if ( ( V_123 -> V_144 != V_145 ) || ! ( V_123 -> V_146 ) ) {
F_20 (KERN_ERR PFX L_55 ) ;
return V_116 ;
}
V_15 = (struct V_14 * ) & V_127 [ 1 ] ;
F_44 ( V_15 , L_56 ) ;
F_8 ( & V_15 -> V_18 ) ;
V_2 = (struct V_1 * ) V_38 -> V_43 . V_44 ;
if ( ! V_2 ) {
F_20 (KERN_ERR PFX L_57 ) ;
F_11 ( & V_15 -> V_18 ) ;
return V_30 ;
}
F_7 ( V_2 , L_58 ,
V_2 -> V_10 . V_10 . V_26 ) ;
F_4 ( & V_2 -> V_10 ) ;
F_79 ( V_15 != V_2 -> V_15 ) ;
if ( V_15 -> V_199 ) {
F_20 (KERN_ERR PFX L_59
L_60 , io_req->xid) ;
F_17 ( & V_2 -> V_10 , V_28 ) ;
F_11 ( & V_15 -> V_18 ) ;
return V_30 ;
}
if ( V_2 -> V_200 == 0 ) {
F_20 (KERN_ERR PFX L_59
L_61 , io_req->xid) ;
F_21 ( V_2 , V_201 ) ;
F_17 ( & V_2 -> V_10 , V_28 ) ;
F_11 ( & V_15 -> V_18 ) ;
return V_30 ;
}
F_45 ( & V_2 -> V_70 ) ;
V_2 -> V_200 = 0 ;
F_34 ( & V_2 -> V_70 , & V_15 -> V_202 ) ;
F_67 ( & V_2 -> V_24 ) ;
if ( F_15 ( V_25 , & V_2 -> V_17 ) ) {
F_20 (KERN_ERR PFX L_59
L_62 , io_req->xid) ;
if ( F_80 ( & V_2 -> V_9 ) )
F_17 ( & V_2 -> V_10 ,
V_28 ) ;
V_16 = F_76 ( V_2 ) ;
F_19 ( V_203 , & V_2 -> V_17 ) ;
goto V_204;
}
if ( F_80 ( & V_2 -> V_9 ) )
F_17 ( & V_2 -> V_10 ,
V_28 ) ;
F_19 ( V_23 , & V_2 -> V_17 ) ;
V_2 -> V_165 = 1 ;
V_16 = F_18 ( V_2 ) ;
if ( V_16 == V_116 ) {
F_16 ( V_2 ) ;
F_11 ( & V_15 -> V_18 ) ;
F_77 ( & V_2 -> V_24 ) ;
F_8 ( & V_15 -> V_18 ) ;
V_2 -> V_165 = 0 ;
goto V_21;
}
F_11 ( & V_15 -> V_18 ) ;
F_77 ( & V_2 -> V_24 ) ;
F_8 ( & V_15 -> V_18 ) ;
V_2 -> V_165 = 0 ;
if ( F_14 ( V_29 , & V_2 -> V_17 ) ) {
F_7 ( V_2 , L_63 ) ;
V_16 = V_30 ;
} else if ( ! ( F_15 ( V_27 ,
& V_2 -> V_17 ) ) ) {
F_20 (KERN_ERR PFX L_64 ,
io_req->xid) ;
V_16 = F_76 ( V_2 ) ;
goto V_204;
} else {
F_7 ( V_2 , L_65 ) ;
V_16 = V_30 ;
F_21 ( V_2 , V_201 ) ;
F_17 ( & V_2 -> V_10 , V_28 ) ;
}
V_21:
F_17 ( & V_2 -> V_10 , V_28 ) ;
V_204:
F_11 ( & V_15 -> V_18 ) ;
return V_16 ;
}
void F_81 ( struct V_1 * V_188 ,
struct V_129 * V_130 ,
T_1 V_205 )
{
struct V_189 * V_35 = V_188 -> V_35 ;
struct V_1 * V_184 = V_35 -> V_193 ;
T_3 V_185 = V_35 -> V_185 ;
enum V_186 V_187 = V_35 -> V_187 ;
int V_16 = 0 ;
struct V_14 * V_15 = V_184 -> V_15 ;
F_7 ( V_184 , L_66
L_67 ,
V_188 -> V_54 , V_188 -> V_13 ) ;
if ( V_205 == V_206 ) {
F_20 (KERN_ERR PFX L_68 ,
seq_clnp_req->xid) ;
goto V_207;
}
F_11 ( & V_15 -> V_18 ) ;
V_16 = F_82 ( V_184 , V_185 , V_187 ) ;
F_8 ( & V_15 -> V_18 ) ;
if ( V_16 )
F_20 (KERN_ERR PFX L_69
L_70 ) ;
V_188 -> V_35 = NULL ;
F_17 ( & V_184 -> V_10 , V_28 ) ;
V_207:
F_30 ( V_35 ) ;
return;
}
void F_83 ( struct V_1 * V_2 ,
struct V_129 * V_130 ,
T_1 V_208 )
{
F_7 ( V_2 , L_71
L_72 ,
V_2 -> V_10 . V_10 . V_26 , V_2 -> V_13 ) ;
F_21 ( V_2 , V_209 ) ;
F_17 ( & V_2 -> V_10 , V_28 ) ;
if ( V_2 -> V_165 )
F_13 ( & V_2 -> V_24 ) ;
}
void F_84 ( struct V_1 * V_2 ,
struct V_129 * V_130 ,
T_1 V_208 )
{
T_3 V_187 ;
T_3 V_174 = V_210 ;
T_1 V_211 = 0 ;
struct V_14 * V_15 = V_2 -> V_15 ;
F_7 ( V_2 , L_73
L_72 ,
V_2 -> V_54 ,
V_2 -> V_10 . V_10 . V_26 , V_2 -> V_13 ) ;
if ( F_15 ( V_27 ,
& V_2 -> V_17 ) ) {
F_7 ( V_2 , L_74
L_75 ) ;
return;
}
if ( F_15 ( V_203 ,
& V_2 -> V_17 ) )
goto V_212;
if ( F_14 ( V_25 , & V_2 -> V_17 ) )
if ( F_80 ( & V_2 -> V_9 ) )
F_17 ( & V_2 -> V_10 ,
V_28 ) ;
V_187 = ( T_1 ) V_130 -> V_213 . V_214 . V_215 . V_216 . V_187 ;
switch ( V_187 ) {
case V_217 :
F_7 ( V_2 , L_76 ) ;
V_211 = 1 ;
break;
case V_218 :
F_7 ( V_2 , L_77 ) ;
break;
default:
F_20 (KERN_ERR PFX L_78 ) ;
break;
}
if ( V_211 ) {
F_7 ( V_2 , L_79 ) ;
F_19 ( V_19 , & V_2 -> V_17 ) ;
}
F_19 ( V_20 , & V_2 -> V_17 ) ;
F_1 ( V_2 , V_174 ) ;
V_212:
if ( V_2 -> V_165 ) {
if ( F_9 ( V_23 ,
& V_2 -> V_17 ) )
F_13 ( & V_2 -> V_24 ) ;
} else {
if ( V_2 -> V_200 ) {
F_45 ( & V_2 -> V_70 ) ;
V_2 -> V_200 = 0 ;
F_34 ( & V_2 -> V_70 , & V_15 -> V_202 ) ;
}
F_21 ( V_2 , V_209 ) ;
F_17 ( & V_2 -> V_10 , V_28 ) ;
}
}
static void F_85 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_1 * V_219 , * V_80 ;
V_119 V_220 = V_38 -> V_134 -> V_221 ;
V_119 V_221 ;
int V_16 = 0 ;
F_7 ( V_2 , L_80 ) ;
F_39 (cmd, tmp, &tgt->active_cmd_queue, link) {
F_44 ( V_15 , L_81 ) ;
V_221 = V_219 -> V_38 -> V_134 -> V_221 ;
if ( V_221 == V_220 ) {
if ( ! F_15 ( V_25 ,
& V_219 -> V_17 ) ) {
if ( F_80 ( & V_2 -> V_9 ) )
F_17 ( & V_2 -> V_10 ,
V_28 ) ;
V_16 = F_18 ( V_219 ) ;
F_86 ( V_16 != V_30 ) ;
} else
F_20 (KERN_ERR PFX L_82
L_83 ,
cmd->xid) ;
}
}
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_1 * V_219 , * V_80 ;
int V_16 = 0 ;
F_7 ( V_2 , L_84 ) ;
F_39 (cmd, tmp, &tgt->active_cmd_queue, link) {
F_44 ( V_15 , L_85 ) ;
if ( ! F_15 ( V_25 ,
& V_219 -> V_17 ) ) {
if ( F_80 ( & V_2 -> V_9 ) )
F_17 ( & V_2 -> V_10 ,
V_28 ) ;
V_16 = F_18 ( V_219 ) ;
F_86 ( V_16 != V_30 ) ;
} else
F_20 (KERN_ERR PFX L_86
L_87 , cmd->xid) ;
}
}
void F_88 ( struct V_1 * V_2 ,
struct V_129 * V_130 , T_1 V_208 )
{
struct V_98 * V_128 ;
struct V_135 * V_136 ;
struct V_37 * V_38 = V_2 -> V_38 ;
V_119 * V_222 ;
V_119 * V_223 ;
void * V_224 ;
F_7 ( V_2 , L_88 ) ;
if ( ! ( F_14 ( V_168 , & V_2 -> V_17 ) ) )
F_19 ( V_167 , & V_2 -> V_17 ) ;
else {
return;
}
V_128 = & ( V_2 -> V_99 ) ;
V_136 = & ( V_128 -> V_225 ) ;
V_222 = ( V_119 * ) V_136 ;
V_223 = ( V_119 * )
& V_130 -> V_213 . V_214 . V_215 . V_226 . V_136 ;
V_222 [ 0 ] = F_89 ( V_223 [ 0 ] ) ;
V_222 [ 1 ] = F_89 ( V_223 [ 1 ] ) ;
V_222 [ 2 ] = F_89 ( V_223 [ 2 ] ) ;
V_128 -> V_227 =
V_130 -> V_213 . V_214 . V_215 . V_226 . V_228 ;
V_224 = V_128 -> V_109 ;
if ( V_136 -> V_229 == V_230 ) {
F_90 ( V_2 ,
(struct V_231 * )
V_224 , V_208 ) ;
if ( V_2 -> V_232 == 0 ) {
if ( V_128 -> V_101 & V_198 )
F_85 ( V_2 ) ;
else if ( V_128 -> V_101 & V_197 )
F_87 ( V_2 ) ;
}
} else {
F_20 (KERN_ERR PFX L_89 ,
fc_hdr->fh_r_ctl) ;
}
if ( ! V_38 -> V_43 . V_44 ) {
F_20 (KERN_ERR PFX L_90 ) ;
return;
}
switch ( V_2 -> V_233 ) {
case V_234 :
if ( V_2 -> V_235 == 0 ) {
V_38 -> V_40 = V_236 << 16 ;
} else {
V_38 -> V_40 = ( V_236 << 16 ) | V_2 -> V_235 ;
}
if ( V_2 -> V_237 )
F_24 ( V_38 , V_2 -> V_237 ) ;
break;
default:
F_7 ( V_2 , L_91 ,
V_2 -> V_233 ) ;
break;
}
V_38 = V_2 -> V_38 ;
V_2 -> V_38 = NULL ;
if ( V_2 -> V_163 ) {
F_45 ( & V_2 -> V_70 ) ;
V_2 -> V_163 = 0 ;
} else {
F_20 (KERN_ERR PFX L_92 ) ;
return;
}
V_38 -> V_43 . V_44 = NULL ;
V_38 -> V_45 ( V_38 ) ;
F_17 ( & V_2 -> V_10 , V_28 ) ;
if ( V_2 -> V_165 ) {
F_7 ( V_2 , L_93 ) ;
F_13 ( & V_2 -> V_24 ) ;
}
}
static int F_91 ( struct V_1 * V_2 , V_119 V_111 , int V_238 ,
int V_239 )
{
struct V_73 * V_240 = V_2 -> V_74 -> V_74 ;
int V_241 , V_242 ;
V_242 = 0 ;
while ( V_238 ) {
if ( V_238 >= V_243 )
V_241 = V_243 ;
else
V_241 = V_238 ;
V_240 [ V_239 + V_242 ] . V_117 = V_111 & 0xffffffff ;
V_240 [ V_239 + V_242 ] . V_118 = V_111 >> 32 ;
V_240 [ V_239 + V_242 ] . V_120 = ( T_4 ) V_241 ;
V_240 [ V_239 + V_242 ] . V_121 = 0 ;
V_111 += ( V_119 ) V_241 ;
V_242 ++ ;
V_238 -= V_241 ;
}
return V_242 ;
}
static int F_92 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
struct V_47 * V_48 = V_5 -> V_48 ;
struct V_37 * V_244 = V_2 -> V_38 ;
struct V_73 * V_240 = V_2 -> V_74 -> V_74 ;
struct V_245 * V_246 ;
int V_247 = 0 ;
int V_248 = 0 ;
int V_249 = 0 ;
int V_242 ;
unsigned int V_238 ;
V_119 V_111 ;
int V_55 ;
V_248 = F_93 ( & V_48 -> V_75 -> V_76 , F_94 ( V_244 ) ,
F_95 ( V_244 ) , V_244 -> V_250 ) ;
F_96 (sc, sg, sg_count, i) {
V_238 = F_97 ( V_246 ) ;
V_111 = F_98 ( V_246 ) ;
if ( V_238 > V_251 ) {
V_242 = F_91 ( V_2 , V_111 , V_238 ,
V_249 ) ;
} else {
V_242 = 1 ;
V_240 [ V_249 ] . V_117 = V_111 & 0xffffffff ;
V_240 [ V_249 ] . V_118 = V_111 >> 32 ;
V_240 [ V_249 ] . V_120 = ( T_4 ) V_238 ;
V_240 [ V_249 ] . V_121 = 0 ;
}
V_249 += V_242 ;
V_247 += V_238 ;
}
if ( V_247 != F_25 ( V_244 ) )
F_20 (KERN_ERR PFX L_94
L_95 , byte_count, scsi_bufflen(sc),
io_req->xid) ;
return V_249 ;
}
static int F_99 ( struct V_1 * V_2 )
{
struct V_37 * V_244 = V_2 -> V_38 ;
struct V_73 * V_240 = V_2 -> V_74 -> V_74 ;
int V_249 ;
if ( F_95 ( V_244 ) ) {
V_249 = F_92 ( V_2 ) ;
if ( V_249 == 0 )
return - V_190 ;
} else {
V_249 = 0 ;
V_240 [ 0 ] . V_117 = V_240 [ 0 ] . V_118 = 0 ;
V_240 [ 0 ] . V_120 = V_240 [ 0 ] . V_121 = 0 ;
}
V_2 -> V_74 -> V_252 = V_249 ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_37 * V_244 = V_2 -> V_38 ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
struct V_47 * V_48 = V_5 -> V_48 ;
if ( V_2 -> V_74 -> V_252 && V_244 && F_95 ( V_244 ) ) {
F_100 ( & V_48 -> V_75 -> V_76 , F_94 ( V_244 ) ,
F_95 ( V_244 ) , V_244 -> V_250 ) ;
V_2 -> V_74 -> V_252 = 0 ;
}
}
void F_63 ( struct V_1 * V_2 ,
struct V_113 * V_113 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
memset ( V_113 , 0 , sizeof( struct V_113 ) ) ;
F_101 ( V_38 -> V_134 -> V_221 , & V_113 -> V_253 ) ;
V_113 -> V_153 = F_102 ( V_2 -> V_114 ) ;
memcpy ( V_113 -> V_151 , V_38 -> V_254 , V_38 -> V_152 ) ;
V_113 -> V_255 = 0 ;
V_113 -> V_256 = 0 ;
V_113 -> V_257 = V_2 -> V_99 . V_101 ;
V_113 -> V_258 = V_2 -> V_150 ;
V_113 -> V_256 = V_259 ;
}
static void F_90 ( struct V_1 * V_2 ,
struct V_231 * V_260 ,
T_1 V_208 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
struct V_14 * V_15 = V_2 -> V_15 ;
T_1 V_261 = V_260 -> V_262 . V_121 ;
T_3 V_263 = 0 ;
int V_55 ;
unsigned char * V_264 ;
unsigned char * V_265 ;
int V_266 = 0 ;
int V_267 = 0 ;
V_2 -> V_233 = V_234 ;
V_2 -> V_237 = 0 ;
if ( V_261 & ( V_268 |
V_269 ) )
V_2 -> V_237 = V_260 -> V_237 ;
V_2 -> V_270 = V_261 ;
F_103 ( V_38 ) = V_2 -> V_235 =
V_260 -> V_271 ;
if ( V_208 ) {
if ( V_261 &
V_272 ) {
V_267 = V_263
= V_260 -> V_267 ;
}
if ( V_261 &
V_273 ) {
V_266 = V_260 -> V_266 ;
V_263 += V_260 -> V_266 ;
}
V_2 -> V_267 = V_267 ;
V_2 -> V_266 = V_266 ;
if ( V_263 > V_208 * V_274 ) {
F_20 (KERN_ERR PFX L_96 ,
rq_buff_len) ;
V_263 = V_208 * V_274 ;
}
V_264 = F_104 ( V_15 , 1 ) ;
if ( V_208 > 1 ) {
for ( V_55 = 1 ; V_55 < V_208 ; V_55 ++ )
V_265 = F_104 ( V_15 , 1 ) ;
}
if ( ( V_267 == 4 ) || ( V_267 == 8 ) ) {
V_2 -> V_232 = V_264 [ 3 ] ;
F_20 (KERN_ERR PFX L_97 ,
io_req->fcp_rsp_code) ;
}
V_264 += V_267 ;
if ( V_266 > V_275 ) {
F_20 (KERN_ERR PFX L_98 ) ;
V_266 = V_275 ;
}
memset ( V_38 -> V_276 , 0 , V_275 ) ;
if ( V_266 )
memcpy ( V_38 -> V_276 , V_264 , V_266 ) ;
for ( V_55 = 0 ; V_55 < V_208 ; V_55 ++ )
F_105 ( V_15 , 1 ) ;
}
}
int F_106 ( struct V_132 * V_133 ,
struct V_37 * V_38 )
{
struct V_122 * V_123 = F_56 ( V_133 ) ;
struct V_124 * V_125 = F_57 ( F_58 ( V_38 -> V_134 ) ) ;
struct V_126 * V_127 = V_125 -> V_143 ;
struct V_14 * V_15 ;
struct V_1 * V_2 ;
int V_16 = 0 ;
int V_277 ;
V_277 = F_107 ( V_125 ) ;
if ( V_277 ) {
V_38 -> V_40 = V_277 ;
V_38 -> V_45 ( V_38 ) ;
return 0 ;
}
if ( ( V_123 -> V_144 != V_145 ) || ! ( V_123 -> V_146 ) ) {
V_16 = V_278 ;
goto V_279;
}
V_15 = (struct V_14 * ) & V_127 [ 1 ] ;
if ( ! F_14 ( V_147 , & V_15 -> V_121 ) ) {
V_16 = V_280 ;
goto V_279;
}
if ( V_15 -> V_281 ) {
if ( F_61 ( V_141 , V_15 -> V_281 ) ) {
V_15 -> V_281 = 0 ;
} else {
V_16 = V_280 ;
goto V_279;
}
}
F_8 ( & V_15 -> V_18 ) ;
V_2 = F_49 ( V_15 ) ;
if ( ! V_2 ) {
V_16 = V_278 ;
goto V_282;
}
V_2 -> V_38 = V_38 ;
if ( F_108 ( V_15 , V_2 ) ) {
F_20 (KERN_ERR PFX L_99 ) ;
V_16 = V_278 ;
goto V_282;
}
V_282:
F_11 ( & V_15 -> V_18 ) ;
V_279:
return V_16 ;
}
void F_109 ( struct V_1 * V_2 ,
struct V_129 * V_130 ,
T_1 V_208 )
{
struct V_231 * V_260 ;
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_37 * V_38 ;
struct V_132 * V_133 ;
if ( F_15 ( V_29 , & V_2 -> V_17 ) ) {
F_7 ( V_2 , L_100
L_101 ) ;
}
if ( F_80 ( & V_2 -> V_9 ) )
F_17 ( & V_2 -> V_10 ,
V_28 ) ;
V_38 = V_2 -> V_38 ;
if ( V_38 == NULL ) {
F_20 (KERN_ERR PFX L_102 ) ;
return;
}
V_260 = (struct V_231 * )
& ( V_130 -> V_213 . V_214 . V_215 . V_260 . V_283 ) ;
F_90 ( V_2 , V_260 , V_208 ) ;
V_133 = V_38 -> V_134 -> V_133 ;
if ( ! V_38 -> V_43 . V_44 ) {
F_20 (KERN_ERR PFX L_103 ) ;
return;
}
if ( V_2 -> V_200 ) {
F_45 ( & V_2 -> V_70 ) ;
V_2 -> V_200 = 0 ;
F_34 ( & V_2 -> V_70 , & V_15 -> V_202 ) ;
} else {
F_7 ( V_2 , L_104 ) ;
if ( V_2 -> V_165 )
if ( F_9 ( V_23 ,
& V_2 -> V_17 ) )
F_13 ( & V_2 -> V_24 ) ;
}
F_22 ( V_2 ) ;
V_2 -> V_38 = NULL ;
switch ( V_2 -> V_233 ) {
case V_234 :
if ( V_2 -> V_235 == 0 ) {
V_38 -> V_40 = V_236 << 16 ;
} else {
F_7 ( V_2 , L_105
L_106 ,
V_2 -> V_235 , V_2 -> V_237 ) ;
V_38 -> V_40 = ( V_236 << 16 ) | V_2 -> V_235 ;
if ( V_2 -> V_235 == V_284 ||
V_2 -> V_235 == V_285 ) {
V_15 -> V_281 = V_141 +
V_260 -> V_286 * V_149 / 10 ;
}
}
if ( V_2 -> V_237 )
F_24 ( V_38 , V_2 -> V_237 ) ;
break;
default:
F_20 (KERN_ERR PFX L_107 ,
io_req->fcp_status) ;
break;
}
V_38 -> V_43 . V_44 = NULL ;
V_38 -> V_45 ( V_38 ) ;
F_17 ( & V_2 -> V_10 , V_28 ) ;
}
int F_108 ( struct V_14 * V_15 ,
struct V_1 * V_2 )
{
struct V_129 * V_130 ;
struct V_129 * V_131 ;
struct V_37 * V_38 = V_2 -> V_38 ;
struct V_81 * V_6 = V_15 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_47 * V_48 = V_5 -> V_48 ;
struct V_122 * V_123 = V_6 -> V_123 ;
struct V_287 * V_288 ;
int V_137 , V_85 ;
T_4 V_54 ;
V_2 -> V_13 = V_22 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_114 = F_25 ( V_38 ) ;
V_38 -> V_43 . V_44 = ( char * ) V_2 ;
V_288 = F_110 ( V_123 -> V_288 , F_50 () ) ;
if ( V_38 -> V_250 == V_289 ) {
V_2 -> V_150 = V_290 ;
V_288 -> V_291 ++ ;
V_288 -> V_292 += V_2 -> V_114 ;
} else if ( V_38 -> V_250 == V_293 ) {
V_2 -> V_150 = V_294 ;
V_288 -> V_295 ++ ;
V_288 -> V_296 += V_2 -> V_114 ;
} else {
V_2 -> V_150 = 0 ;
V_288 -> V_297 ++ ;
}
F_51 () ;
V_54 = V_2 -> V_54 ;
if ( F_99 ( V_2 ) ) {
F_20 (KERN_ERR PFX L_108 ) ;
F_17 ( & V_2 -> V_10 , V_28 ) ;
return - V_298 ;
}
V_137 = V_54 / V_161 ;
V_85 = V_54 % V_161 ;
V_131 = (struct V_129 * ) V_48 -> V_162 [ V_137 ] ;
V_130 = & ( V_131 [ V_85 ] ) ;
F_111 ( V_2 , V_130 ) ;
if ( V_15 -> V_199 ) {
F_20 (KERN_ERR PFX L_109 ) ;
F_17 ( & V_2 -> V_10 , V_28 ) ;
return - V_298 ;
}
if ( ! F_14 ( V_147 , & V_15 -> V_121 ) ) {
F_20 (KERN_ERR PFX L_110 ) ;
F_17 ( & V_2 -> V_10 , V_28 ) ;
return - V_298 ;
}
if ( V_15 -> V_299 )
F_1 ( V_2 , V_300 ) ;
F_66 ( V_15 , V_54 ) ;
V_2 -> V_200 = 1 ;
F_34 ( & V_2 -> V_70 , & V_15 -> V_301 ) ;
F_68 ( V_15 ) ;
return 0 ;
}
