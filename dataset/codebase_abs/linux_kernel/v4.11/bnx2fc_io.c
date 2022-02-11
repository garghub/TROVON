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
F_15 ( & V_2 -> V_10 ) ) ;
if ( ! ( F_16 ( V_26 ,
& V_2 -> V_17 ) ) ) {
F_17 ( V_2 ) ;
F_18 ( & V_2 -> V_10 , V_27 ) ;
F_11 ( & V_15 -> V_18 ) ;
return;
}
} else {
F_7 ( V_2 , L_6 ) ;
if ( F_16 ( V_28 ,
& V_2 -> V_17 ) ) {
F_7 ( V_2 , L_7
L_8 ) ;
goto V_21;
}
if ( ! F_16 ( V_25 ,
& V_2 -> V_17 ) ) {
V_16 = F_19 ( V_2 ) ;
if ( V_16 == V_29 )
goto V_21;
F_18 ( & V_2 -> V_10 , V_27 ) ;
F_11 ( & V_15 -> V_18 ) ;
return;
} else {
F_7 ( V_2 , L_9
L_10 ) ;
}
}
break;
case V_30 :
if ( F_14 ( V_25 , & V_2 -> V_17 ) ) {
F_7 ( V_2 , L_11 ) ;
if ( ! F_16 ( V_26 ,
& V_2 -> V_17 ) ) {
F_18 ( & V_2 -> V_10 , V_27 ) ;
F_11 ( & V_15 -> V_18 ) ;
return;
}
} else {
F_7 ( V_2 , L_12 ) ;
if ( F_16 ( V_31 ,
& V_2 -> V_17 ) )
goto V_21;
F_20 ( V_32 , & V_2 -> V_17 ) ;
if ( ( V_2 -> V_33 ) && ( V_2 -> V_34 ) ) {
V_2 -> V_33 ( V_2 -> V_34 ) ;
V_2 -> V_34 = NULL ;
}
}
break;
default:
F_21 (KERN_ERR PFX L_13 ,
cmd_type) ;
break;
}
V_21:
F_18 ( & V_2 -> V_10 , V_27 ) ;
F_11 ( & V_15 -> V_18 ) ;
}
static void F_22 ( struct V_1 * V_2 , int V_35 )
{
struct V_36 * V_37 = V_2 -> V_37 ;
if ( V_2 -> V_13 != V_22 )
return;
F_7 ( V_2 , L_14 , V_35 ) ;
if ( F_14 ( V_38 , & V_2 -> V_17 ) ) {
return;
}
F_23 ( V_2 ) ;
V_2 -> V_37 = NULL ;
if ( ! V_37 ) {
F_21 (KERN_ERR PFX L_15
L_16 ,
io_req->xid) ;
return;
}
if ( ! V_37 -> V_39 ) {
F_24 ( V_40 L_17 , V_2 -> V_41 ) ;
return;
}
if ( ! V_37 -> V_39 -> V_42 ) {
F_24 ( V_40 L_18 ,
V_2 -> V_41 ) ;
return;
}
V_37 -> V_43 = V_35 << 16 ;
F_7 ( V_2 , L_19 ,
V_37 , F_25 ( V_37 -> V_43 ) , V_37 -> V_44 ,
V_37 -> V_45 ) ;
F_26 ( V_37 , F_27 ( V_37 ) ) ;
V_37 -> V_46 . V_47 = NULL ;
V_37 -> V_48 ( V_37 ) ;
}
struct V_49 * F_28 ( struct V_50 * V_51 )
{
struct V_49 * V_52 ;
struct V_53 * V_54 ;
struct V_1 * V_2 ;
T_2 V_55 ;
T_3 V_56 ;
T_4 V_41 ;
int V_57 ;
int V_58 , V_59 ;
T_2 V_60 ;
int V_61 = F_29 () + 1 ;
T_4 V_62 = V_63 ;
T_4 V_64 = V_51 -> V_64 ;
if ( V_64 <= V_62 || V_64 == V_65 ) {
F_21 (KERN_ERR PFX L_20 , min_xid, max_xid) ;
return NULL ;
}
F_30 ( L_21 , V_62 , V_64 ) ;
V_58 = V_64 - V_62 + 1 ;
V_55 = ( V_58 * ( sizeof( struct V_1 * ) ) ) ;
V_55 += sizeof( struct V_49 ) ;
V_52 = F_31 ( V_55 , V_66 ) ;
if ( ! V_52 ) {
F_21 (KERN_ERR PFX L_22 ) ;
return NULL ;
}
V_52 -> V_67 = F_31 ( sizeof( * V_52 -> V_67 ) *
V_61 , V_66 ) ;
if ( ! V_52 -> V_67 ) {
F_21 (KERN_ERR PFX L_23 ) ;
goto V_68;
}
V_52 -> V_69 = F_31 ( sizeof( * V_52 -> V_69 ) *
V_61 , V_66 ) ;
if ( ! V_52 -> V_69 ) {
F_21 (KERN_ERR PFX L_24 ) ;
F_32 ( V_52 -> V_67 ) ;
V_52 -> V_67 = NULL ;
goto V_68;
}
V_52 -> V_51 = V_51 ;
V_52 -> V_70 = (struct V_1 * * ) ( V_52 + 1 ) ;
for ( V_57 = 0 ; V_57 < V_61 ; V_57 ++ ) {
F_33 ( & V_52 -> V_67 [ V_57 ] ) ;
F_34 ( & V_52 -> V_69 [ V_57 ] ) ;
}
V_41 = V_63 ;
V_59 = V_58 - V_51 -> V_71 ;
for ( V_57 = 0 ; V_57 < V_58 ; V_57 ++ ) {
V_2 = F_31 ( sizeof( * V_2 ) , V_66 ) ;
if ( ! V_2 ) {
F_21 (KERN_ERR PFX L_25 ) ;
goto V_68;
}
F_33 ( & V_2 -> V_72 ) ;
F_35 ( & V_2 -> V_9 , F_5 ) ;
V_2 -> V_41 = V_41 ++ ;
if ( V_57 < V_59 )
F_36 ( & V_2 -> V_72 ,
& V_52 -> V_67 [ V_2 -> V_41 %
F_29 () ] ) ;
else
F_36 ( & V_2 -> V_72 ,
& V_52 -> V_67 [ F_29 () ] ) ;
V_2 ++ ;
}
V_56 = V_58 * sizeof( struct V_53 * ) ;
V_52 -> V_73 = F_37 ( V_56 , V_66 ) ;
if ( ! V_52 -> V_73 ) {
F_21 (KERN_ERR PFX L_26 ) ;
goto V_68;
}
V_56 = sizeof( struct V_53 ) ;
for ( V_57 = 0 ; V_57 < V_58 ; V_57 ++ ) {
V_52 -> V_73 [ V_57 ] = F_37 ( V_56 , V_66 ) ;
if ( ! V_52 -> V_73 [ V_57 ] ) {
F_21 (KERN_ERR PFX L_27
L_28 , i) ;
goto V_68;
}
}
V_60 = V_74 * sizeof( struct V_75 ) ;
for ( V_57 = 0 ; V_57 < V_58 ; V_57 ++ ) {
V_54 = V_52 -> V_73 [ V_57 ] ;
V_54 -> V_76 = F_38 ( & V_51 -> V_77 -> V_78 ,
V_60 ,
& V_54 -> V_79 ,
V_66 ) ;
if ( ! V_54 -> V_76 ) {
F_21 (KERN_ERR PFX L_27
L_29 , i) ;
goto V_68;
}
}
return V_52 ;
V_68:
F_39 ( V_52 ) ;
return NULL ;
}
void F_39 ( struct V_49 * V_52 )
{
struct V_53 * V_54 ;
struct V_50 * V_51 = V_52 -> V_51 ;
T_2 V_60 ;
T_4 V_62 = V_63 ;
T_4 V_64 = V_51 -> V_64 ;
int V_58 ;
int V_57 ;
V_58 = V_64 - V_62 + 1 ;
if ( ! V_52 -> V_73 )
goto V_80;
V_60 = V_74 * sizeof( struct V_75 ) ;
for ( V_57 = 0 ; V_57 < V_58 ; V_57 ++ ) {
V_54 = V_52 -> V_73 [ V_57 ] ;
if ( V_54 -> V_76 ) {
F_40 ( & V_51 -> V_77 -> V_78 , V_60 ,
V_54 -> V_76 ,
V_54 -> V_79 ) ;
V_54 -> V_76 = NULL ;
}
}
for ( V_57 = 0 ; V_57 < V_58 ; V_57 ++ ) {
F_32 ( V_52 -> V_73 [ V_57 ] ) ;
V_52 -> V_73 [ V_57 ] = NULL ;
}
F_32 ( V_52 -> V_73 ) ;
V_52 -> V_73 = NULL ;
V_80:
F_32 ( V_52 -> V_69 ) ;
if ( ! V_52 -> V_67 )
goto V_81;
for ( V_57 = 0 ; V_57 < F_29 () + 1 ; V_57 ++ ) {
struct V_1 * V_82 , * V_2 ;
F_41 (io_req, tmp,
&cmgr->free_list[i], link) {
F_42 ( & V_2 -> V_72 ) ;
F_32 ( V_2 ) ;
}
}
F_32 ( V_52 -> V_67 ) ;
V_81:
F_32 ( V_52 ) ;
}
struct V_1 * F_43 ( struct V_14 * V_15 , int type )
{
struct V_83 * V_6 = V_15 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_49 * V_84 = V_5 -> V_51 -> V_84 ;
struct V_1 * V_2 ;
struct V_85 * V_86 ;
struct V_53 * V_76 ;
int V_87 = V_88 ;
T_3 V_89 ;
T_3 V_90 ;
T_4 V_41 ;
V_90 = V_15 -> V_90 ;
switch ( type ) {
case V_91 :
V_90 = V_92 ;
break;
case V_30 :
V_90 = V_93 ;
break;
default:
break;
}
F_8 ( & V_84 -> V_69 [ V_87 ] ) ;
V_89 = F_44 ( & V_15 -> V_89 ) ;
if ( ( F_45 ( & ( V_84 -> V_67 [ V_87 ] ) ) ) ||
( V_15 -> V_94 . V_95 >= V_90 ) ||
( V_89 + V_90 <= V_96 ) ) {
F_46 ( V_15 , L_30
L_31 ,
V_15 -> V_94 . V_95 , V_15 -> V_90 ) ;
if ( F_45 ( & ( V_84 -> V_67 [ V_87 ] ) ) )
F_21 (KERN_ERR PFX L_32 ) ;
F_11 ( & V_84 -> V_69 [ V_87 ] ) ;
return NULL ;
}
V_86 = (struct V_85 * )
V_84 -> V_67 [ V_87 ] . V_97 ;
F_47 ( V_86 ) ;
V_2 = (struct V_1 * ) V_86 ;
V_41 = V_2 -> V_41 ;
V_84 -> V_70 [ V_41 ] = V_2 ;
F_48 ( & V_15 -> V_94 ) ;
F_49 ( & V_15 -> V_89 ) ;
F_11 ( & V_84 -> V_69 [ V_87 ] ) ;
F_33 ( & V_2 -> V_72 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_84 = V_84 ;
V_2 -> V_17 = 0 ;
V_2 -> V_13 = type ;
V_76 = V_2 -> V_76 = V_84 -> V_73 [ V_41 ] ;
V_76 -> V_2 = V_2 ;
F_50 ( & V_2 -> V_10 ) ;
return V_2 ;
}
struct V_1 * F_51 ( struct V_14 * V_15 )
{
struct V_83 * V_6 = V_15 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_49 * V_84 = V_5 -> V_51 -> V_84 ;
struct V_1 * V_2 ;
struct V_85 * V_86 ;
struct V_53 * V_76 ;
T_3 V_89 ;
T_3 V_90 ;
T_4 V_41 ;
int V_87 = F_52 () ;
V_90 = V_98 ;
F_8 ( & V_84 -> V_69 [ V_87 ] ) ;
V_89 = F_44 ( & V_15 -> V_89 ) ;
if ( ( F_45 ( & V_84 -> V_67 [ V_87 ] ) ) ||
( V_15 -> V_94 . V_95 >= V_90 ) ||
( V_89 + V_90 <= V_96 ) ) {
F_11 ( & V_84 -> V_69 [ V_87 ] ) ;
F_53 () ;
return NULL ;
}
V_86 = (struct V_85 * )
V_84 -> V_67 [ V_87 ] . V_97 ;
F_47 ( V_86 ) ;
V_2 = (struct V_1 * ) V_86 ;
V_41 = V_2 -> V_41 ;
V_84 -> V_70 [ V_41 ] = V_2 ;
F_48 ( & V_15 -> V_94 ) ;
F_49 ( & V_15 -> V_89 ) ;
F_11 ( & V_84 -> V_69 [ V_87 ] ) ;
F_53 () ;
F_33 ( & V_2 -> V_72 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_84 = V_84 ;
V_2 -> V_17 = 0 ;
V_76 = V_2 -> V_76 = V_84 -> V_73 [ V_41 ] ;
V_76 -> V_2 = V_2 ;
F_50 ( & V_2 -> V_10 ) ;
return V_2 ;
}
void V_27 ( struct V_99 * V_100 )
{
struct V_1 * V_2 = F_6 ( V_100 ,
struct V_1 , V_10 ) ;
struct V_49 * V_84 = V_2 -> V_84 ;
int V_87 ;
if ( V_2 -> V_13 == V_22 )
V_87 = V_2 -> V_41 % F_29 () ;
else
V_87 = V_88 ;
F_8 ( & V_84 -> V_69 [ V_87 ] ) ;
if ( V_2 -> V_13 != V_22 )
F_54 ( V_2 ) ;
V_84 -> V_70 [ V_2 -> V_41 ] = NULL ;
F_47 ( & V_2 -> V_72 ) ;
F_55 ( & V_2 -> V_72 ,
& V_84 -> V_67 [ V_87 ] ) ;
F_49 ( & V_2 -> V_15 -> V_94 ) ;
F_11 ( & V_84 -> V_69 [ V_87 ] ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_101 * V_102 = & ( V_2 -> V_102 ) ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
struct V_50 * V_51 = V_5 -> V_51 ;
T_2 V_103 = sizeof( struct V_75 ) ;
V_102 -> V_104 = 0 ;
if ( V_102 -> V_105 ) {
F_40 ( & V_51 -> V_77 -> V_78 , V_103 ,
V_102 -> V_105 ,
V_102 -> V_106 ) ;
V_102 -> V_105 = NULL ;
}
if ( V_102 -> V_107 ) {
F_40 ( & V_51 -> V_77 -> V_78 , V_103 ,
V_102 -> V_107 ,
V_102 -> V_108 ) ;
V_102 -> V_107 = NULL ;
}
if ( V_102 -> V_109 ) {
F_40 ( & V_51 -> V_77 -> V_78 , V_110 ,
V_102 -> V_109 ,
V_102 -> V_111 ) ;
V_102 -> V_109 = NULL ;
}
if ( V_102 -> V_112 ) {
F_40 ( & V_51 -> V_77 -> V_78 , V_110 ,
V_102 -> V_112 ,
V_102 -> V_113 ) ;
V_102 -> V_112 = NULL ;
}
}
int F_56 ( struct V_1 * V_2 )
{
struct V_101 * V_102 ;
struct V_75 * V_105 ;
struct V_75 * V_107 ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
struct V_50 * V_51 = V_5 -> V_51 ;
T_5 V_114 ;
T_2 V_103 ;
V_102 = (struct V_101 * ) & ( V_2 -> V_102 ) ;
memset ( V_102 , 0 , sizeof( struct V_101 ) ) ;
if ( V_2 -> V_13 != V_30 ) {
V_102 -> V_115 = sizeof( struct V_116 ) ;
V_2 -> V_117 = V_102 -> V_115 ;
} else
V_102 -> V_115 = V_2 -> V_117 ;
V_102 -> V_109 = F_38 ( & V_51 -> V_77 -> V_78 , V_110 ,
& V_102 -> V_111 ,
V_118 ) ;
if ( ! V_102 -> V_109 ) {
F_21 (KERN_ERR PFX L_33 ) ;
F_54 ( V_2 ) ;
return V_119 ;
}
V_102 -> V_112 = F_38 ( & V_51 -> V_77 -> V_78 , V_110 ,
& V_102 -> V_113 ,
V_118 ) ;
if ( ! V_102 -> V_112 ) {
F_21 (KERN_ERR PFX L_34 ) ;
F_54 ( V_2 ) ;
return V_119 ;
}
memset ( V_102 -> V_109 , 0 , V_110 ) ;
memset ( V_102 -> V_112 , 0 , V_110 ) ;
V_103 = sizeof( struct V_75 ) ;
V_102 -> V_105 = F_38 ( & V_51 -> V_77 -> V_78 , V_103 ,
& V_102 -> V_106 ,
V_118 ) ;
if ( ! V_102 -> V_105 ) {
F_21 (KERN_ERR PFX L_35 ) ;
F_54 ( V_2 ) ;
return V_119 ;
}
V_102 -> V_107 = F_38 ( & V_51 -> V_77 -> V_78 , V_103 ,
& V_102 -> V_108 ,
V_118 ) ;
if ( ! V_102 -> V_107 ) {
F_21 (KERN_ERR PFX L_36 ) ;
F_54 ( V_2 ) ;
return V_119 ;
}
V_114 = V_102 -> V_111 ;
V_105 = V_102 -> V_105 ;
V_105 -> V_120 = ( T_3 ) V_114 & 0xffffffff ;
V_105 -> V_121 = ( T_3 ) ( ( V_122 ) V_114 >> 32 ) ;
V_105 -> V_123 = V_110 ;
V_105 -> V_124 = 0 ;
V_107 = V_102 -> V_107 ;
V_114 = V_102 -> V_113 ;
V_107 -> V_120 = ( T_3 ) V_114 & 0xffffffff ;
V_107 -> V_121 = ( T_3 ) ( ( V_122 ) V_114 >> 32 ) ;
V_107 -> V_123 = V_110 ;
V_107 -> V_124 = 0 ;
return V_29 ;
}
static int F_57 ( struct V_36 * V_37 , T_1 V_104 )
{
struct V_125 * V_126 ;
struct V_127 * V_128 ;
struct V_129 * V_130 ;
struct V_83 * V_6 ;
struct V_4 * V_5 ;
struct V_14 * V_15 ;
struct V_1 * V_2 ;
struct V_101 * V_131 ;
struct V_132 * V_133 ;
struct V_132 * V_134 ;
struct V_135 * V_42 = V_37 -> V_39 -> V_42 ;
struct V_136 * V_137 ;
struct V_116 * V_116 ;
int V_138 , V_87 ;
int V_16 = V_29 ;
T_4 V_41 ;
T_3 V_139 , V_140 ;
unsigned long V_141 = V_142 ;
V_126 = F_58 ( V_42 ) ;
V_128 = F_59 ( F_60 ( V_37 -> V_39 ) ) ;
V_6 = F_61 ( V_126 ) ;
V_5 = V_6 -> V_7 ;
if ( V_128 == NULL ) {
F_21 (KERN_ERR PFX L_37 ) ;
V_16 = V_119 ;
goto V_143;
}
V_130 = V_128 -> V_144 ;
V_16 = F_62 ( V_37 ) ;
if ( V_16 )
return V_16 ;
if ( V_126 -> V_145 != V_146 || ! ( V_126 -> V_147 ) ) {
F_21 (KERN_ERR PFX L_38 ) ;
V_16 = V_119 ;
goto V_143;
}
V_15 = (struct V_14 * ) & V_130 [ 1 ] ;
if ( ! ( F_14 ( V_148 , & V_15 -> V_124 ) ) ) {
F_21 (KERN_ERR PFX L_39 ) ;
V_16 = V_119 ;
goto V_143;
}
V_149:
V_2 = F_43 ( V_15 , V_91 ) ;
if ( ! V_2 ) {
if ( F_63 ( V_142 , V_141 + V_150 ) ) {
F_21 (KERN_ERR PFX L_40 ) ;
V_16 = V_119 ;
goto V_143;
}
F_64 ( 20 ) ;
goto V_149;
}
V_2 -> V_37 = V_37 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_15 = V_15 ;
V_131 = (struct V_101 * ) & ( V_2 -> V_102 ) ;
V_16 = F_56 ( V_2 ) ;
if ( V_16 == V_119 ) {
F_21 (KERN_ERR PFX L_41 ) ;
F_8 ( & V_15 -> V_18 ) ;
F_18 ( & V_2 -> V_10 , V_27 ) ;
F_11 ( & V_15 -> V_18 ) ;
goto V_143;
}
V_2 -> V_151 = 0 ;
V_131 -> V_104 = V_104 ;
F_65 ( V_2 , (struct V_116 * ) V_131 -> V_109 ) ;
V_116 = (struct V_116 * ) V_131 -> V_109 ;
memset ( V_116 -> V_152 , 0 , V_37 -> V_153 ) ;
V_116 -> V_154 = 0 ;
V_137 = & ( V_131 -> V_155 ) ;
V_139 = V_15 -> V_139 ;
V_140 = V_128 -> V_156 ;
F_66 ( V_137 , V_157 , V_140 , V_139 ,
V_158 , V_159 | V_160 |
V_161 , 0 ) ;
V_41 = V_2 -> V_41 ;
F_46 ( V_15 , L_42 , V_41 ) ;
V_138 = V_41 / V_162 ;
V_87 = V_41 % V_162 ;
V_134 = (struct V_132 * )
V_5 -> V_51 -> V_163 [ V_138 ] ;
V_133 = & ( V_134 [ V_87 ] ) ;
F_67 ( V_2 , V_133 ) ;
V_37 -> V_46 . V_47 = ( char * ) V_2 ;
F_8 ( & V_15 -> V_18 ) ;
F_68 ( V_15 , V_41 ) ;
V_2 -> V_164 = 1 ;
F_36 ( & V_2 -> V_72 , & V_15 -> V_165 ) ;
F_69 ( & V_2 -> V_24 ) ;
V_2 -> V_166 = 1 ;
F_70 ( V_15 ) ;
F_11 ( & V_15 -> V_18 ) ;
V_16 = F_71 ( & V_2 -> V_24 ,
V_5 -> V_167 * V_150 ) ;
F_8 ( & V_15 -> V_18 ) ;
V_2 -> V_166 = 0 ;
if ( ! ( F_14 ( V_168 , & V_2 -> V_17 ) ) ) {
F_20 ( V_169 , & V_2 -> V_17 ) ;
if ( V_2 -> V_164 ) {
F_47 ( & V_2 -> V_72 ) ;
V_2 -> V_164 = 0 ;
}
V_2 -> V_166 = 1 ;
F_17 ( V_2 ) ;
F_11 ( & V_15 -> V_18 ) ;
V_16 = F_71 ( & V_2 -> V_24 ,
V_170 ) ;
F_8 ( & V_15 -> V_18 ) ;
V_2 -> V_166 = 0 ;
if ( ! V_16 )
F_18 ( & V_2 -> V_10 , V_27 ) ;
}
F_11 ( & V_15 -> V_18 ) ;
if ( ! V_16 ) {
F_46 ( V_15 , L_43 ) ;
V_16 = V_119 ;
} else {
F_46 ( V_15 , L_44 ) ;
V_16 = V_29 ;
}
V_143:
return V_16 ;
}
int F_19 ( struct V_1 * V_2 )
{
struct V_125 * V_126 ;
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_127 * V_128 = V_15 -> V_128 ;
struct V_171 * V_172 = V_15 -> V_172 ;
struct V_4 * V_5 ;
struct V_83 * V_6 ;
struct V_1 * V_173 ;
struct V_132 * V_133 ;
struct V_132 * V_134 ;
struct V_136 * V_137 ;
struct V_101 * V_174 ;
int V_138 , V_87 ;
T_3 V_139 , V_140 ;
T_4 V_41 ;
int V_16 = V_29 ;
T_3 V_175 = V_172 -> V_175 ;
F_7 ( V_2 , L_45 ) ;
V_6 = V_2 -> V_6 ;
V_5 = V_6 -> V_7 ;
V_126 = V_6 -> V_126 ;
if ( ! F_14 ( V_148 , & V_15 -> V_124 ) ) {
F_21 (KERN_ERR PFX L_46 ) ;
V_16 = V_119 ;
goto V_176;
}
if ( V_128 == NULL ) {
F_21 (KERN_ERR PFX L_47 ) ;
V_16 = V_119 ;
goto V_176;
}
if ( V_126 -> V_145 != V_146 || ! ( V_126 -> V_147 ) ) {
F_21 (KERN_ERR PFX L_48 ) ;
V_16 = V_119 ;
goto V_176;
}
V_173 = F_43 ( V_15 , V_177 ) ;
if ( ! V_173 ) {
F_21 (KERN_ERR PFX L_49 ) ;
V_16 = V_119 ;
goto V_176;
}
V_173 -> V_37 = NULL ;
V_173 -> V_6 = V_6 ;
V_173 -> V_15 = V_15 ;
V_173 -> V_117 = 0 ;
V_174 = (struct V_101 * ) & ( V_173 -> V_102 ) ;
memset ( V_174 , 0 , sizeof( struct V_101 ) ) ;
V_137 = & ( V_174 -> V_155 ) ;
V_137 -> V_178 = F_72 ( V_2 -> V_41 ) ;
V_137 -> V_179 = F_72 ( V_2 -> V_133 -> V_180 . V_181 . V_182 ) ;
V_139 = V_15 -> V_139 ;
V_140 = V_128 -> V_156 ;
F_66 ( V_137 , V_183 , V_140 , V_139 ,
V_184 , V_159 | V_160 |
V_161 , 0 ) ;
V_41 = V_173 -> V_41 ;
F_7 ( V_173 , L_50 ) ;
V_138 = V_41 / V_162 ;
V_87 = V_41 % V_162 ;
V_134 = (struct V_132 * )
V_5 -> V_51 -> V_163 [ V_138 ] ;
V_133 = & ( V_134 [ V_87 ] ) ;
F_67 ( V_173 , V_133 ) ;
F_1 ( V_2 , 2 * V_175 ) ;
F_68 ( V_15 , V_41 ) ;
F_70 ( V_15 ) ;
V_176:
return V_16 ;
}
int F_73 ( struct V_1 * V_185 , T_3 V_186 ,
enum V_187 V_188 )
{
struct V_125 * V_126 ;
struct V_14 * V_15 = V_185 -> V_15 ;
struct V_4 * V_5 ;
struct V_83 * V_6 ;
struct V_1 * V_189 ;
struct V_132 * V_133 ;
struct V_132 * V_134 ;
struct V_190 * V_34 = NULL ;
int V_138 , V_87 ;
T_4 V_41 ;
int V_16 = 0 ;
F_7 ( V_185 , L_51 ,
V_185 -> V_41 ) ;
F_4 ( & V_185 -> V_10 ) ;
V_6 = V_185 -> V_6 ;
V_5 = V_6 -> V_7 ;
V_126 = V_6 -> V_126 ;
V_34 = F_31 ( sizeof( struct V_190 ) , V_118 ) ;
if ( ! V_34 ) {
F_21 (KERN_ERR PFX L_52 ) ;
V_16 = - V_191 ;
goto V_192;
}
V_189 = F_43 ( V_15 , V_193 ) ;
if ( ! V_189 ) {
F_21 (KERN_ERR PFX L_53 ) ;
V_16 = - V_191 ;
F_32 ( V_34 ) ;
goto V_192;
}
V_189 -> V_37 = NULL ;
V_189 -> V_6 = V_6 ;
V_189 -> V_15 = V_15 ;
V_189 -> V_117 = 0 ;
V_41 = V_189 -> V_41 ;
V_138 = V_41 / V_162 ;
V_87 = V_41 % V_162 ;
V_134 = (struct V_132 * )
V_5 -> V_51 -> V_163 [ V_138 ] ;
V_133 = & ( V_134 [ V_87 ] ) ;
V_34 -> V_194 = V_185 ;
V_34 -> V_2 = V_189 ;
V_34 -> V_188 = V_188 ;
V_34 -> V_186 = V_186 ;
V_189 -> V_34 = V_34 ;
F_21 (KERN_ERR PFX L_54 ) ;
F_74 ( V_189 , V_133 , V_185 , V_186 ) ;
F_68 ( V_15 , V_41 ) ;
F_70 ( V_15 ) ;
V_192:
return V_16 ;
}
int F_17 ( struct V_1 * V_2 )
{
struct V_125 * V_126 ;
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_4 * V_5 ;
struct V_83 * V_6 ;
struct V_1 * V_195 ;
struct V_132 * V_133 ;
struct V_132 * V_134 ;
int V_138 , V_87 ;
T_4 V_41 , V_196 ;
int V_16 = 0 ;
F_7 ( V_2 , L_55 ) ;
V_6 = V_2 -> V_6 ;
V_5 = V_6 -> V_7 ;
V_126 = V_6 -> V_126 ;
V_195 = F_43 ( V_15 , V_197 ) ;
if ( ! V_195 ) {
F_21 (KERN_ERR PFX L_53 ) ;
V_16 = - 1 ;
goto V_192;
}
V_195 -> V_37 = NULL ;
V_195 -> V_6 = V_6 ;
V_195 -> V_15 = V_15 ;
V_195 -> V_117 = 0 ;
V_41 = V_195 -> V_41 ;
V_138 = V_41 / V_162 ;
V_87 = V_41 % V_162 ;
V_134 = (struct V_132 * )
V_5 -> V_51 -> V_163 [ V_138 ] ;
V_133 = & ( V_134 [ V_87 ] ) ;
V_196 = V_2 -> V_41 ;
F_7 ( V_2 , L_56 , V_41 ) ;
F_75 ( V_195 , V_133 , V_196 ) ;
F_68 ( V_15 , V_41 ) ;
F_70 ( V_15 ) ;
V_192:
return V_16 ;
}
int F_76 ( struct V_36 * V_37 )
{
return F_57 ( V_37 , V_198 ) ;
}
int F_77 ( struct V_36 * V_37 )
{
return F_57 ( V_37 , V_199 ) ;
}
static int F_78 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
int V_16 = V_29 ;
V_2 -> V_166 = 1 ;
F_17 ( V_2 ) ;
F_11 ( & V_15 -> V_18 ) ;
F_79 ( & V_2 -> V_24 ) ;
V_2 -> V_166 = 0 ;
F_18 ( & V_2 -> V_10 , V_27 ) ;
F_8 ( & V_15 -> V_18 ) ;
return V_16 ;
}
int F_80 ( struct V_36 * V_37 )
{
struct V_127 * V_128 = F_59 ( F_60 ( V_37 -> V_39 ) ) ;
struct V_129 * V_130 = V_128 -> V_144 ;
struct V_1 * V_2 ;
struct V_125 * V_126 ;
struct V_14 * V_15 ;
int V_16 ;
V_16 = F_62 ( V_37 ) ;
if ( V_16 )
return V_16 ;
V_126 = F_58 ( V_37 -> V_39 -> V_42 ) ;
if ( ( V_126 -> V_145 != V_146 ) || ! ( V_126 -> V_147 ) ) {
F_21 (KERN_ERR PFX L_57 ) ;
return V_119 ;
}
V_15 = (struct V_14 * ) & V_130 [ 1 ] ;
F_46 ( V_15 , L_58 ) ;
F_8 ( & V_15 -> V_18 ) ;
V_2 = (struct V_1 * ) V_37 -> V_46 . V_47 ;
if ( ! V_2 ) {
F_21 (KERN_ERR PFX L_59 ) ;
F_11 ( & V_15 -> V_18 ) ;
return V_29 ;
}
F_7 ( V_2 , L_60 ,
F_15 ( & V_2 -> V_10 ) ) ;
F_4 ( & V_2 -> V_10 ) ;
F_81 ( V_15 != V_2 -> V_15 ) ;
if ( V_15 -> V_200 ) {
F_21 (KERN_ERR PFX L_61
L_62 , io_req->xid) ;
F_18 ( & V_2 -> V_10 , V_27 ) ;
F_11 ( & V_15 -> V_18 ) ;
return V_29 ;
}
if ( V_2 -> V_201 == 0 ) {
F_21 (KERN_ERR PFX L_61
L_63 , io_req->xid) ;
F_22 ( V_2 , V_202 ) ;
F_18 ( & V_2 -> V_10 , V_27 ) ;
F_11 ( & V_15 -> V_18 ) ;
return V_29 ;
}
F_47 ( & V_2 -> V_72 ) ;
V_2 -> V_201 = 0 ;
F_36 ( & V_2 -> V_72 , & V_15 -> V_203 ) ;
F_69 ( & V_2 -> V_24 ) ;
if ( F_16 ( V_25 , & V_2 -> V_17 ) ) {
F_21 (KERN_ERR PFX L_61
L_64 , io_req->xid) ;
if ( F_82 ( & V_2 -> V_9 ) )
F_18 ( & V_2 -> V_10 ,
V_27 ) ;
V_16 = F_78 ( V_2 ) ;
F_20 ( V_204 , & V_2 -> V_17 ) ;
goto V_205;
}
if ( F_82 ( & V_2 -> V_9 ) )
F_18 ( & V_2 -> V_10 ,
V_27 ) ;
F_20 ( V_23 , & V_2 -> V_17 ) ;
V_2 -> V_166 = 1 ;
V_16 = F_19 ( V_2 ) ;
if ( V_16 == V_119 ) {
F_17 ( V_2 ) ;
F_11 ( & V_15 -> V_18 ) ;
F_79 ( & V_2 -> V_24 ) ;
F_8 ( & V_15 -> V_18 ) ;
V_2 -> V_166 = 0 ;
goto V_21;
}
F_11 ( & V_15 -> V_18 ) ;
F_79 ( & V_2 -> V_24 ) ;
F_8 ( & V_15 -> V_18 ) ;
V_2 -> V_166 = 0 ;
if ( F_14 ( V_28 , & V_2 -> V_17 ) ) {
F_7 ( V_2 , L_65 ) ;
V_16 = V_29 ;
} else if ( ! ( F_16 ( V_26 ,
& V_2 -> V_17 ) ) ) {
F_21 (KERN_ERR PFX L_66 ,
io_req->xid) ;
V_16 = F_78 ( V_2 ) ;
goto V_205;
} else {
F_7 ( V_2 , L_67 ) ;
V_16 = V_29 ;
F_22 ( V_2 , V_202 ) ;
F_18 ( & V_2 -> V_10 , V_27 ) ;
}
V_21:
F_18 ( & V_2 -> V_10 , V_27 ) ;
V_205:
F_11 ( & V_15 -> V_18 ) ;
return V_16 ;
}
void F_83 ( struct V_1 * V_189 ,
struct V_132 * V_133 ,
T_1 V_206 )
{
struct V_190 * V_34 = V_189 -> V_34 ;
struct V_1 * V_185 = V_34 -> V_194 ;
T_3 V_186 = V_34 -> V_186 ;
enum V_187 V_188 = V_34 -> V_188 ;
int V_16 = 0 ;
struct V_14 * V_15 = V_185 -> V_15 ;
F_7 ( V_185 , L_68
L_69 ,
V_189 -> V_41 , V_189 -> V_13 ) ;
if ( V_206 == V_207 ) {
F_21 (KERN_ERR PFX L_70 ,
seq_clnp_req->xid) ;
goto V_208;
}
F_11 ( & V_15 -> V_18 ) ;
V_16 = F_84 ( V_185 , V_186 , V_188 ) ;
F_8 ( & V_15 -> V_18 ) ;
if ( V_16 )
F_21 (KERN_ERR PFX L_71
L_72 ) ;
V_189 -> V_34 = NULL ;
F_18 ( & V_185 -> V_10 , V_27 ) ;
V_208:
F_32 ( V_34 ) ;
return;
}
void F_85 ( struct V_1 * V_2 ,
struct V_132 * V_133 ,
T_1 V_209 )
{
F_7 ( V_2 , L_73
L_74 ,
F_15 ( & V_2 -> V_10 ) , V_2 -> V_13 ) ;
F_22 ( V_2 , V_210 ) ;
F_18 ( & V_2 -> V_10 , V_27 ) ;
if ( V_2 -> V_166 )
F_13 ( & V_2 -> V_24 ) ;
}
void F_86 ( struct V_1 * V_2 ,
struct V_132 * V_133 ,
T_1 V_209 )
{
T_3 V_188 ;
T_3 V_175 = V_211 ;
T_1 V_212 = 0 ;
struct V_14 * V_15 = V_2 -> V_15 ;
F_7 ( V_2 , L_75
L_74 ,
V_2 -> V_41 ,
F_15 ( & V_2 -> V_10 ) , V_2 -> V_13 ) ;
if ( F_16 ( V_26 ,
& V_2 -> V_17 ) ) {
F_7 ( V_2 , L_76
L_77 ) ;
return;
}
if ( F_16 ( V_204 ,
& V_2 -> V_17 ) )
goto V_213;
if ( F_14 ( V_25 , & V_2 -> V_17 ) )
if ( F_82 ( & V_2 -> V_9 ) )
F_18 ( & V_2 -> V_10 ,
V_27 ) ;
V_188 = ( T_1 ) V_133 -> V_214 . V_215 . V_216 . V_217 . V_188 ;
switch ( V_188 ) {
case V_218 :
F_7 ( V_2 , L_78 ) ;
V_212 = 1 ;
break;
case V_219 :
F_7 ( V_2 , L_79 ) ;
break;
default:
F_21 (KERN_ERR PFX L_80 ) ;
break;
}
if ( V_212 ) {
F_7 ( V_2 , L_81 ) ;
F_20 ( V_19 , & V_2 -> V_17 ) ;
}
F_20 ( V_20 , & V_2 -> V_17 ) ;
F_1 ( V_2 , V_175 ) ;
V_213:
if ( V_2 -> V_166 ) {
if ( F_9 ( V_23 ,
& V_2 -> V_17 ) )
F_13 ( & V_2 -> V_24 ) ;
} else {
if ( V_2 -> V_201 ) {
F_47 ( & V_2 -> V_72 ) ;
V_2 -> V_201 = 0 ;
F_36 ( & V_2 -> V_72 , & V_15 -> V_203 ) ;
}
F_22 ( V_2 , V_210 ) ;
F_18 ( & V_2 -> V_10 , V_27 ) ;
}
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = V_2 -> V_37 ;
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_1 * V_220 , * V_82 ;
V_122 V_221 = V_37 -> V_39 -> V_222 ;
V_122 V_222 ;
int V_16 = 0 ;
F_7 ( V_2 , L_82 ) ;
F_41 (cmd, tmp, &tgt->active_cmd_queue, link) {
F_46 ( V_15 , L_83 ) ;
V_222 = V_220 -> V_37 -> V_39 -> V_222 ;
if ( V_222 == V_221 ) {
if ( ! F_16 ( V_25 ,
& V_220 -> V_17 ) ) {
if ( F_82 ( & V_2 -> V_9 ) )
F_18 ( & V_2 -> V_10 ,
V_27 ) ;
V_16 = F_19 ( V_220 ) ;
F_88 ( V_16 != V_29 ) ;
} else
F_21 (KERN_ERR PFX L_84
L_85 ,
cmd->xid) ;
}
}
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_1 * V_220 , * V_82 ;
int V_16 = 0 ;
F_7 ( V_2 , L_86 ) ;
F_41 (cmd, tmp, &tgt->active_cmd_queue, link) {
F_46 ( V_15 , L_87 ) ;
if ( ! F_16 ( V_25 ,
& V_220 -> V_17 ) ) {
if ( F_82 ( & V_2 -> V_9 ) )
F_18 ( & V_2 -> V_10 ,
V_27 ) ;
V_16 = F_19 ( V_220 ) ;
F_88 ( V_16 != V_29 ) ;
} else
F_21 (KERN_ERR PFX L_88
L_89 , cmd->xid) ;
}
}
void F_90 ( struct V_1 * V_2 ,
struct V_132 * V_133 , T_1 V_209 )
{
struct V_101 * V_131 ;
struct V_136 * V_137 ;
struct V_36 * V_37 = V_2 -> V_37 ;
V_122 * V_223 ;
V_122 * V_224 ;
void * V_225 ;
F_7 ( V_2 , L_90 ) ;
if ( ! ( F_14 ( V_169 , & V_2 -> V_17 ) ) )
F_20 ( V_168 , & V_2 -> V_17 ) ;
else {
return;
}
V_131 = & ( V_2 -> V_102 ) ;
V_137 = & ( V_131 -> V_226 ) ;
V_223 = ( V_122 * ) V_137 ;
V_224 = ( V_122 * )
& V_133 -> V_214 . V_215 . V_216 . V_227 . V_137 ;
V_223 [ 0 ] = F_91 ( V_224 [ 0 ] ) ;
V_223 [ 1 ] = F_91 ( V_224 [ 1 ] ) ;
V_223 [ 2 ] = F_91 ( V_224 [ 2 ] ) ;
V_131 -> V_228 =
V_133 -> V_214 . V_215 . V_216 . V_227 . V_229 ;
V_225 = V_131 -> V_112 ;
if ( V_137 -> V_230 == V_231 ) {
F_92 ( V_2 ,
(struct V_232 * )
V_225 , V_209 ) ;
if ( V_2 -> V_233 == 0 ) {
if ( V_131 -> V_104 & V_199 )
F_87 ( V_2 ) ;
else if ( V_131 -> V_104 & V_198 )
F_89 ( V_2 ) ;
}
} else {
F_21 (KERN_ERR PFX L_91 ,
fc_hdr->fh_r_ctl) ;
}
if ( ! V_37 -> V_46 . V_47 ) {
F_21 (KERN_ERR PFX L_92 ) ;
return;
}
switch ( V_2 -> V_234 ) {
case V_235 :
if ( V_2 -> V_236 == 0 ) {
V_37 -> V_43 = V_237 << 16 ;
} else {
V_37 -> V_43 = ( V_237 << 16 ) | V_2 -> V_236 ;
}
if ( V_2 -> V_238 )
F_26 ( V_37 , V_2 -> V_238 ) ;
break;
default:
F_7 ( V_2 , L_93 ,
V_2 -> V_234 ) ;
break;
}
V_37 = V_2 -> V_37 ;
V_2 -> V_37 = NULL ;
if ( V_2 -> V_164 ) {
F_47 ( & V_2 -> V_72 ) ;
V_2 -> V_164 = 0 ;
} else {
F_21 (KERN_ERR PFX L_94 ) ;
return;
}
V_37 -> V_46 . V_47 = NULL ;
V_37 -> V_48 ( V_37 ) ;
F_18 ( & V_2 -> V_10 , V_27 ) ;
if ( V_2 -> V_166 ) {
F_7 ( V_2 , L_95 ) ;
F_13 ( & V_2 -> V_24 ) ;
}
}
static int F_93 ( struct V_1 * V_2 , V_122 V_114 , int V_239 ,
int V_240 )
{
struct V_75 * V_241 = V_2 -> V_76 -> V_76 ;
int V_242 , V_243 ;
V_243 = 0 ;
while ( V_239 ) {
if ( V_239 >= V_244 )
V_242 = V_244 ;
else
V_242 = V_239 ;
V_241 [ V_240 + V_243 ] . V_120 = V_114 & 0xffffffff ;
V_241 [ V_240 + V_243 ] . V_121 = V_114 >> 32 ;
V_241 [ V_240 + V_243 ] . V_123 = ( T_4 ) V_242 ;
V_241 [ V_240 + V_243 ] . V_124 = 0 ;
V_114 += ( V_122 ) V_242 ;
V_243 ++ ;
V_239 -= V_242 ;
}
return V_243 ;
}
static int F_94 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
struct V_50 * V_51 = V_5 -> V_51 ;
struct V_36 * V_245 = V_2 -> V_37 ;
struct V_75 * V_241 = V_2 -> V_76 -> V_76 ;
struct V_246 * V_247 ;
int V_248 = 0 ;
int V_249 = 0 ;
int V_250 = 0 ;
int V_243 ;
unsigned int V_239 ;
V_122 V_114 ;
int V_57 ;
V_249 = F_95 ( & V_51 -> V_77 -> V_78 , F_96 ( V_245 ) ,
F_97 ( V_245 ) , V_245 -> V_251 ) ;
F_98 (sc, sg, sg_count, i) {
V_239 = F_99 ( V_247 ) ;
V_114 = F_100 ( V_247 ) ;
if ( V_239 > V_252 ) {
V_243 = F_93 ( V_2 , V_114 , V_239 ,
V_250 ) ;
} else {
V_243 = 1 ;
V_241 [ V_250 ] . V_120 = V_114 & 0xffffffff ;
V_241 [ V_250 ] . V_121 = V_114 >> 32 ;
V_241 [ V_250 ] . V_123 = ( T_4 ) V_239 ;
V_241 [ V_250 ] . V_124 = 0 ;
}
V_250 += V_243 ;
V_248 += V_239 ;
}
if ( V_248 != F_27 ( V_245 ) )
F_21 (KERN_ERR PFX L_96
L_97 , byte_count, scsi_bufflen(sc),
io_req->xid) ;
return V_250 ;
}
static int F_101 ( struct V_1 * V_2 )
{
struct V_36 * V_245 = V_2 -> V_37 ;
struct V_75 * V_241 = V_2 -> V_76 -> V_76 ;
int V_250 ;
if ( F_97 ( V_245 ) ) {
V_250 = F_94 ( V_2 ) ;
if ( V_250 == 0 )
return - V_191 ;
} else {
V_250 = 0 ;
V_241 [ 0 ] . V_120 = V_241 [ 0 ] . V_121 = 0 ;
V_241 [ 0 ] . V_123 = V_241 [ 0 ] . V_124 = 0 ;
}
V_2 -> V_76 -> V_253 = V_250 ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_36 * V_245 = V_2 -> V_37 ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
struct V_50 * V_51 = V_5 -> V_51 ;
if ( V_2 -> V_76 -> V_253 && V_245 && F_97 ( V_245 ) ) {
F_102 ( & V_51 -> V_77 -> V_78 , F_96 ( V_245 ) ,
F_97 ( V_245 ) , V_245 -> V_251 ) ;
V_2 -> V_76 -> V_253 = 0 ;
}
}
void F_65 ( struct V_1 * V_2 ,
struct V_116 * V_116 )
{
struct V_36 * V_37 = V_2 -> V_37 ;
memset ( V_116 , 0 , sizeof( struct V_116 ) ) ;
F_103 ( V_37 -> V_39 -> V_222 , & V_116 -> V_254 ) ;
V_116 -> V_154 = F_104 ( V_2 -> V_117 ) ;
memcpy ( V_116 -> V_152 , V_37 -> V_255 , V_37 -> V_153 ) ;
V_116 -> V_256 = 0 ;
V_116 -> V_257 = 0 ;
V_116 -> V_258 = V_2 -> V_102 . V_104 ;
V_116 -> V_259 = V_2 -> V_151 ;
V_116 -> V_257 = V_260 ;
}
static void F_92 ( struct V_1 * V_2 ,
struct V_232 * V_261 ,
T_1 V_209 )
{
struct V_36 * V_37 = V_2 -> V_37 ;
struct V_14 * V_15 = V_2 -> V_15 ;
T_1 V_262 = V_261 -> V_263 . V_124 ;
T_3 V_264 = 0 ;
int V_57 ;
unsigned char * V_265 ;
unsigned char * V_266 ;
int V_267 = 0 ;
int V_268 = 0 ;
V_2 -> V_234 = V_235 ;
V_2 -> V_238 = 0 ;
if ( V_262 & ( V_269 |
V_270 ) )
V_2 -> V_238 = V_261 -> V_238 ;
V_2 -> V_271 = V_262 ;
F_105 ( V_37 ) = V_2 -> V_236 =
V_261 -> V_272 ;
if ( V_209 ) {
if ( V_262 &
V_273 ) {
V_268 = V_264
= V_261 -> V_268 ;
}
if ( V_262 &
V_274 ) {
V_267 = V_261 -> V_267 ;
V_264 += V_261 -> V_267 ;
}
V_2 -> V_268 = V_268 ;
V_2 -> V_267 = V_267 ;
if ( V_264 > V_209 * V_275 ) {
F_21 (KERN_ERR PFX L_98 ,
rq_buff_len) ;
V_264 = V_209 * V_275 ;
}
V_265 = F_106 ( V_15 , 1 ) ;
if ( V_209 > 1 ) {
for ( V_57 = 1 ; V_57 < V_209 ; V_57 ++ )
V_266 = F_106 ( V_15 , 1 ) ;
}
if ( ( V_268 == 4 ) || ( V_268 == 8 ) ) {
V_2 -> V_233 = V_265 [ 3 ] ;
F_7 ( V_2 , L_99 ,
V_2 -> V_233 ) ;
}
V_265 += V_268 ;
if ( V_267 > V_276 ) {
F_21 (KERN_ERR PFX L_100 ) ;
V_267 = V_276 ;
}
memset ( V_37 -> V_277 , 0 , V_276 ) ;
if ( V_267 )
memcpy ( V_37 -> V_277 , V_265 , V_267 ) ;
for ( V_57 = 0 ; V_57 < V_209 ; V_57 ++ )
F_107 ( V_15 , 1 ) ;
}
}
int F_108 ( struct V_135 * V_42 ,
struct V_36 * V_37 )
{
struct V_125 * V_126 = F_58 ( V_42 ) ;
struct V_127 * V_128 = F_59 ( F_60 ( V_37 -> V_39 ) ) ;
struct V_129 * V_130 = V_128 -> V_144 ;
struct V_14 * V_15 ;
struct V_1 * V_2 ;
int V_16 = 0 ;
int V_278 ;
V_278 = F_109 ( V_128 ) ;
if ( V_278 ) {
V_37 -> V_43 = V_278 ;
V_37 -> V_48 ( V_37 ) ;
return 0 ;
}
if ( ( V_126 -> V_145 != V_146 ) || ! ( V_126 -> V_147 ) ) {
V_16 = V_279 ;
goto V_280;
}
V_15 = (struct V_14 * ) & V_130 [ 1 ] ;
if ( ! F_14 ( V_148 , & V_15 -> V_124 ) ) {
V_16 = V_281 ;
goto V_280;
}
if ( V_15 -> V_282 ) {
if ( F_63 ( V_142 , V_15 -> V_282 ) ) {
V_15 -> V_282 = 0 ;
} else {
V_16 = V_281 ;
goto V_280;
}
}
F_8 ( & V_15 -> V_18 ) ;
V_2 = F_51 ( V_15 ) ;
if ( ! V_2 ) {
V_16 = V_279 ;
goto V_283;
}
V_2 -> V_37 = V_37 ;
if ( F_110 ( V_15 , V_2 ) ) {
F_21 (KERN_ERR PFX L_101 ) ;
V_16 = V_279 ;
goto V_283;
}
V_283:
F_11 ( & V_15 -> V_18 ) ;
V_280:
return V_16 ;
}
void F_111 ( struct V_1 * V_2 ,
struct V_132 * V_133 ,
T_1 V_209 )
{
struct V_232 * V_261 ;
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_36 * V_37 ;
struct V_135 * V_42 ;
if ( F_16 ( V_28 , & V_2 -> V_17 ) ) {
F_7 ( V_2 , L_102
L_103 ) ;
}
if ( F_82 ( & V_2 -> V_9 ) )
F_18 ( & V_2 -> V_10 ,
V_27 ) ;
V_37 = V_2 -> V_37 ;
if ( V_37 == NULL ) {
F_21 (KERN_ERR PFX L_104 ) ;
return;
}
V_261 = (struct V_232 * )
& ( V_133 -> V_214 . V_215 . V_216 . V_261 . V_284 ) ;
F_92 ( V_2 , V_261 , V_209 ) ;
V_42 = V_37 -> V_39 -> V_42 ;
if ( ! V_37 -> V_46 . V_47 ) {
F_21 (KERN_ERR PFX L_105 ) ;
return;
}
if ( V_2 -> V_201 ) {
F_47 ( & V_2 -> V_72 ) ;
V_2 -> V_201 = 0 ;
F_36 ( & V_2 -> V_72 , & V_15 -> V_203 ) ;
} else {
F_7 ( V_2 , L_106 ) ;
if ( V_2 -> V_166 )
if ( F_9 ( V_23 ,
& V_2 -> V_17 ) )
F_13 ( & V_2 -> V_24 ) ;
}
F_23 ( V_2 ) ;
V_2 -> V_37 = NULL ;
switch ( V_2 -> V_234 ) {
case V_235 :
if ( V_2 -> V_236 == 0 ) {
V_37 -> V_43 = V_237 << 16 ;
} else {
F_7 ( V_2 , L_107
L_108 ,
V_2 -> V_236 , V_2 -> V_238 ) ;
V_37 -> V_43 = ( V_237 << 16 ) | V_2 -> V_236 ;
if ( V_2 -> V_236 == V_285 ||
V_2 -> V_236 == V_286 ) {
V_15 -> V_282 = V_142 +
V_261 -> V_287 * V_150 / 10 ;
}
}
if ( V_2 -> V_238 )
F_26 ( V_37 , V_2 -> V_238 ) ;
break;
default:
F_21 (KERN_ERR PFX L_109 ,
io_req->fcp_status) ;
break;
}
V_37 -> V_46 . V_47 = NULL ;
V_37 -> V_48 ( V_37 ) ;
F_18 ( & V_2 -> V_10 , V_27 ) ;
}
int F_110 ( struct V_14 * V_15 ,
struct V_1 * V_2 )
{
struct V_132 * V_133 ;
struct V_132 * V_134 ;
struct V_36 * V_37 = V_2 -> V_37 ;
struct V_83 * V_6 = V_15 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_50 * V_51 = V_5 -> V_51 ;
struct V_125 * V_126 = V_6 -> V_126 ;
struct V_288 * V_289 ;
int V_138 , V_87 ;
T_4 V_41 ;
V_2 -> V_13 = V_22 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_117 = F_27 ( V_37 ) ;
V_37 -> V_46 . V_47 = ( char * ) V_2 ;
V_289 = F_112 ( V_126 -> V_289 , F_52 () ) ;
if ( V_37 -> V_251 == V_290 ) {
V_2 -> V_151 = V_291 ;
V_289 -> V_292 ++ ;
V_289 -> V_293 += V_2 -> V_117 ;
} else if ( V_37 -> V_251 == V_294 ) {
V_2 -> V_151 = V_295 ;
V_289 -> V_296 ++ ;
V_289 -> V_297 += V_2 -> V_117 ;
} else {
V_2 -> V_151 = 0 ;
V_289 -> V_298 ++ ;
}
F_53 () ;
V_41 = V_2 -> V_41 ;
if ( F_101 ( V_2 ) ) {
F_21 (KERN_ERR PFX L_110 ) ;
F_18 ( & V_2 -> V_10 , V_27 ) ;
return - V_299 ;
}
V_138 = V_41 / V_162 ;
V_87 = V_41 % V_162 ;
V_134 = (struct V_132 * ) V_51 -> V_163 [ V_138 ] ;
V_133 = & ( V_134 [ V_87 ] ) ;
F_113 ( V_2 , V_133 ) ;
if ( V_15 -> V_200 ) {
F_21 (KERN_ERR PFX L_111 ) ;
F_18 ( & V_2 -> V_10 , V_27 ) ;
return - V_299 ;
}
if ( ! F_14 ( V_148 , & V_15 -> V_124 ) ) {
F_21 (KERN_ERR PFX L_112 ) ;
F_18 ( & V_2 -> V_10 , V_27 ) ;
return - V_299 ;
}
if ( V_15 -> V_300 )
F_1 ( V_2 , V_301 ) ;
F_68 ( V_15 , V_41 ) ;
V_2 -> V_201 = 1 ;
F_36 ( & V_2 -> V_72 , & V_15 -> V_302 ) ;
F_70 ( V_15 ) ;
return 0 ;
}
