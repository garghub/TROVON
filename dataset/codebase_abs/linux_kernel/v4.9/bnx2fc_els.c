static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_3 * V_5 ;
int V_6 = 0 ;
F_2 ( ! V_2 ) ;
V_5 = V_2 -> V_7 ;
V_4 = V_2 -> V_8 ;
F_2 ( ! V_4 ) ;
F_3 ( L_1 ,
V_4 -> V_9 , V_5 -> V_9 ) ;
F_4 ( & V_4 -> V_10 , V_11 ) ;
if ( F_5 ( V_12 , & V_5 -> V_13 ) ) {
F_3 ( L_2 ,
V_5 -> V_9 ) ;
if ( V_5 -> V_14 ) {
F_6 ( & V_5 -> V_15 ) ;
V_5 -> V_14 = 0 ;
V_6 = F_7 ( V_5 ) ;
F_2 ( V_6 ) ;
}
}
F_8 ( V_2 ) ;
}
int F_9 ( struct V_3 * V_8 )
{
struct V_16 V_17 ;
struct V_18 * V_19 = V_8 -> V_19 ;
struct V_20 * V_21 = V_19 -> V_22 -> V_23 ;
struct V_1 * V_2 = NULL ;
T_1 V_24 = V_19 -> V_24 ;
T_1 V_25 = V_21 -> V_25 ;
unsigned long V_26 = V_27 ;
int V_6 ;
F_3 ( L_3 ,
V_8 -> V_9 ) ;
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
V_2 = F_10 ( sizeof( struct V_1 ) , V_28 ) ;
if ( ! V_2 ) {
F_11 (KERN_ERR PFX L_4 ) ;
V_6 = - V_29 ;
goto V_30;
}
V_2 -> V_8 = V_8 ;
V_17 . V_31 = V_32 ;
F_12 ( V_17 . V_33 , V_24 ) ;
V_17 . V_34 = F_13 ( V_8 -> V_9 ) ;
V_17 . V_35 = F_13 ( V_8 -> V_36 -> V_37 . V_38 . V_39 ) ;
V_40:
V_6 = F_14 ( V_19 , V_32 , & V_17 , sizeof( V_17 ) ,
F_1 , V_2 ,
V_25 ) ;
if ( V_6 == - V_29 ) {
if ( F_15 ( V_27 , V_26 + ( 10 * V_41 ) ) ) {
F_3 ( L_5 ) ;
V_6 = V_42 ;
goto V_30;
}
F_16 ( 20 ) ;
goto V_40;
}
V_30:
if ( V_6 ) {
F_3 ( L_6 ,
V_8 -> V_9 ) ;
F_8 ( V_2 ) ;
F_17 ( & V_19 -> V_43 ) ;
F_4 ( & V_8 -> V_10 , V_11 ) ;
F_18 ( & V_19 -> V_43 ) ;
}
return V_6 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_44 ;
struct V_18 * V_19 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
unsigned char * V_49 ;
void * V_50 ;
T_1 V_51 , V_52 ;
T_2 V_53 ;
int V_54 ;
int V_6 = 0 ;
V_53 = V_2 -> V_53 ;
F_3 ( L_7 , V_53 ) ;
V_44 = V_2 -> V_7 ;
if ( F_5 ( V_12 , & V_44 -> V_13 ) ) {
if ( V_44 -> V_14 ) {
F_6 ( & V_44 -> V_15 ) ;
V_44 -> V_14 = 0 ;
V_6 = F_7 ( V_44 ) ;
F_2 ( V_6 ) ;
}
goto V_55;
}
V_19 = V_44 -> V_19 ;
V_46 = & ( V_44 -> V_46 ) ;
V_48 = & ( V_46 -> V_56 ) ;
V_51 = V_46 -> V_51 ;
V_50 = V_46 -> V_50 ;
V_49 = F_10 ( V_57 , V_58 ) ;
if ( ! V_49 ) {
F_11 (KERN_ERR PFX L_8 ) ;
goto V_55;
}
V_52 = sizeof( * V_48 ) ;
if ( V_52 + V_51 > V_57 ) {
F_11 (KERN_ERR PFX L_9
L_10 ) ;
goto V_59;
}
memcpy ( V_49 , V_48 , V_52 ) ;
memcpy ( V_49 + V_52 , V_50 , V_51 ) ;
V_54 = V_52 + V_51 ;
F_20 ( V_19 , V_49 , V_54 , V_53 ) ;
V_59:
F_8 ( V_49 ) ;
V_55:
F_8 ( V_2 ) ;
}
int F_21 ( struct V_18 * V_19 , struct V_60 * V_61 )
{
struct V_62 * V_63 ;
struct V_47 * V_64 ;
struct V_1 * V_2 ;
struct V_20 * V_21 = V_19 -> V_22 -> V_23 ;
T_1 V_25 = V_21 -> V_25 ;
int V_6 ;
V_64 = F_22 ( V_61 ) ;
V_2 = F_10 ( sizeof( struct V_1 ) , V_58 ) ;
if ( ! V_2 ) {
F_11 (KERN_ERR PFX L_11 ) ;
return - V_29 ;
}
V_2 -> V_53 = F_23 ( V_64 -> V_65 ) ;
F_3 ( L_12 , V_2 -> V_53 ) ;
V_63 = F_24 ( V_61 , sizeof( * V_63 ) ) ;
V_6 = F_14 ( V_19 , V_66 , V_63 , sizeof( * V_63 ) ,
F_19 , V_2 , 2 * V_25 ) ;
if ( V_6 )
F_8 ( V_2 ) ;
return V_6 ;
}
int F_25 ( struct V_18 * V_19 , struct V_60 * V_61 )
{
struct V_67 * V_68 ;
struct V_47 * V_64 ;
struct V_1 * V_2 ;
struct V_20 * V_21 = V_19 -> V_22 -> V_23 ;
T_1 V_25 = V_21 -> V_25 ;
int V_6 ;
V_64 = F_22 ( V_61 ) ;
V_2 = F_10 ( sizeof( struct V_1 ) , V_58 ) ;
if ( ! V_2 ) {
F_11 (KERN_ERR PFX L_13 ) ;
return - V_29 ;
}
V_2 -> V_53 = F_23 ( V_64 -> V_65 ) ;
F_3 ( L_14 , V_2 -> V_53 ) ;
V_68 = F_24 ( V_61 , sizeof( * V_68 ) ) ;
V_6 = F_14 ( V_19 , V_69 , V_68 , sizeof( * V_68 ) ,
F_19 , V_2 , 2 * V_25 ) ;
if ( V_6 )
F_8 ( V_2 ) ;
return V_6 ;
}
int F_26 ( struct V_18 * V_19 , struct V_60 * V_61 )
{
struct V_70 * V_71 ;
struct V_47 * V_64 ;
struct V_1 * V_2 ;
struct V_20 * V_21 = V_19 -> V_22 -> V_23 ;
T_1 V_25 = V_21 -> V_25 ;
int V_6 ;
V_64 = F_22 ( V_61 ) ;
V_2 = F_10 ( sizeof( struct V_1 ) , V_58 ) ;
if ( ! V_2 ) {
F_11 (KERN_ERR PFX L_13 ) ;
return - V_29 ;
}
V_2 -> V_53 = F_23 ( V_64 -> V_65 ) ;
V_71 = F_24 ( V_61 , sizeof( * V_71 ) ) ;
V_6 = F_14 ( V_19 , V_72 , V_71 , sizeof( * V_71 ) ,
F_19 , V_2 , 2 * V_25 ) ;
if ( V_6 )
F_8 ( V_2 ) ;
return V_6 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_45 * V_46 ;
struct V_47 * V_48 , * V_64 ;
struct V_3 * V_73 ;
struct V_3 * V_4 ;
struct V_60 * V_61 ;
unsigned char * V_49 ;
void * V_50 ;
T_1 V_51 , V_52 ;
T_3 V_74 ;
int V_6 = 0 ;
V_4 = V_2 -> V_8 ;
V_73 = V_2 -> V_7 ;
if ( F_5 ( V_12 , & V_73 -> V_13 ) ) {
F_28 ( V_73 , L_15
L_16 ,
V_4 -> V_9 ) ;
V_6 = F_29 ( V_73 ) ;
if ( V_6 != V_75 ) {
F_28 ( V_73 , L_17
L_18 ) ;
F_7 ( V_73 ) ;
}
if ( F_30 ( V_76 , & V_4 -> V_13 ) ||
F_30 ( V_77 , & V_4 -> V_13 ) ) {
F_28 ( V_73 , L_19 ,
V_4 -> V_9 , V_4 -> V_13 ) ;
goto V_78;
}
V_4 -> V_79 ++ ;
if ( V_4 -> V_79 <= V_80 ) {
struct V_18 * V_19 = V_4 -> V_19 ;
F_18 ( & V_19 -> V_43 ) ;
V_6 = F_31 ( V_4 ,
V_4 -> V_81 ,
V_4 -> V_82 ) ;
F_17 ( & V_19 -> V_43 ) ;
if ( ! V_6 )
goto V_78;
}
V_6 = F_29 ( V_4 ) ;
if ( V_6 != V_75 ) {
F_28 ( V_73 , L_17
L_20 ,
V_4 -> V_9 ) ;
F_7 ( V_4 ) ;
}
goto V_78;
}
if ( F_30 ( V_76 , & V_4 -> V_13 ) ||
F_30 ( V_77 , & V_4 -> V_13 ) ) {
F_28 ( V_73 , L_21 ,
V_4 -> V_9 , V_4 -> V_13 ) ;
goto V_78;
}
V_46 = & ( V_73 -> V_46 ) ;
V_48 = & ( V_46 -> V_56 ) ;
V_51 = V_46 -> V_51 ;
V_50 = V_46 -> V_50 ;
V_52 = sizeof( * V_48 ) ;
V_49 = F_10 ( V_57 , V_58 ) ;
if ( ! V_49 ) {
F_11 (KERN_ERR PFX L_22 ) ;
goto V_78;
}
memcpy ( V_49 , V_48 , V_52 ) ;
memcpy ( V_49 + V_52 , V_50 , V_51 ) ;
V_61 = F_32 ( NULL , V_51 ) ;
if ( ! V_61 ) {
F_11 (KERN_ERR PFX L_23 ) ;
goto V_59;
}
V_64 = (struct V_47 * ) F_22 ( V_61 ) ;
memcpy ( V_64 , V_49 , V_52 + V_51 ) ;
V_74 = F_33 ( V_61 ) ;
switch ( V_74 ) {
case V_83 :
F_28 ( V_73 , L_24 ) ;
break;
case V_84 :
F_28 ( V_73 , L_25 ) ;
V_6 = F_29 ( V_4 ) ;
if ( V_6 != V_75 ) {
F_28 ( V_73 , L_17
L_20 ,
V_4 -> V_9 ) ;
F_7 ( V_4 ) ;
}
break;
default:
F_28 ( V_73 , L_26 ,
V_74 ) ;
break;
}
F_34 ( V_61 ) ;
V_59:
F_8 ( V_49 ) ;
V_78:
F_4 ( & V_4 -> V_10 , V_11 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_85 ;
struct V_3 * V_86 ;
struct V_45 * V_46 ;
struct V_47 * V_48 , * V_64 ;
struct V_87 * V_88 ;
struct V_89 * V_90 ;
struct V_18 * V_19 ;
struct V_91 * V_92 ;
struct V_93 * V_94 ;
enum V_95 V_96 ;
unsigned char * V_49 ;
void * V_50 ;
struct V_60 * V_61 ;
T_3 V_74 ;
T_1 V_97 ;
T_1 V_98 ;
T_1 V_51 , V_52 ;
int V_6 = 0 ;
bool V_99 = false ;
bool V_100 = false ;
F_36 ( L_27 ) ;
V_86 = V_2 -> V_7 ;
V_4 = V_2 -> V_8 ;
F_28 ( V_86 , L_28 , V_4 -> V_9 ) ;
V_19 = V_4 -> V_19 ;
if ( F_5 ( V_12 , & V_86 -> V_13 ) ) {
F_28 ( V_86 , L_29
L_16 ,
V_4 -> V_9 ) ;
V_6 = F_29 ( V_86 ) ;
if ( V_6 != V_75 ) {
F_28 ( V_86 , L_30
L_18 ) ;
F_7 ( V_86 ) ;
}
V_4 -> V_101 ++ ;
if ( V_4 -> V_101 <= V_102 ) {
F_18 ( & V_19 -> V_43 ) ;
V_6 = F_37 ( V_4 ) ;
F_17 ( & V_19 -> V_43 ) ;
if ( ! V_6 )
goto V_103;
}
V_6 = F_29 ( V_4 ) ;
if ( V_6 != V_75 ) {
F_28 ( V_86 , L_30
L_20 ,
V_4 -> V_9 ) ;
F_7 ( V_4 ) ;
}
goto V_103;
}
if ( F_30 ( V_76 , & V_4 -> V_13 ) ) {
F_28 ( V_86 , L_31
L_16 ,
V_4 -> V_9 ) ;
goto V_103;
}
if ( F_30 ( V_77 , & V_4 -> V_13 ) ) {
F_28 ( V_86 , L_32
L_16 ,
V_4 -> V_9 ) ;
goto V_103;
}
V_46 = & ( V_86 -> V_46 ) ;
V_48 = & ( V_46 -> V_56 ) ;
V_51 = V_46 -> V_51 ;
V_90 = V_50 = V_46 -> V_50 ;
V_52 = sizeof( * V_48 ) ;
V_49 = F_10 ( V_57 , V_58 ) ;
if ( ! V_49 ) {
F_11 (KERN_ERR PFX L_33 ) ;
goto V_103;
}
memcpy ( V_49 , V_48 , V_52 ) ;
memcpy ( V_49 + V_52 , V_50 , V_51 ) ;
V_61 = F_32 ( NULL , V_51 ) ;
if ( ! V_61 ) {
F_11 (KERN_ERR PFX L_23 ) ;
goto V_59;
}
V_64 = (struct V_47 * ) F_22 ( V_61 ) ;
memcpy ( V_64 , V_49 , V_52 + V_51 ) ;
V_74 = F_33 ( V_61 ) ;
if ( V_74 == V_84 ) {
F_28 ( V_86 , L_34 ) ;
V_88 = F_24 ( V_61 , sizeof( * V_88 ) ) ;
if ( ( V_88 -> V_104 == V_105 ||
V_88 -> V_104 == V_106 ) &&
V_88 -> V_107 == V_108 ) {
F_28 ( V_86 , L_35 ) ;
V_85 = F_38 ( V_19 ) ;
if ( ! V_85 )
goto V_100;
V_85 -> V_94 = V_4 -> V_94 ;
F_39 ( V_109 ,
& V_4 -> V_13 ) ;
F_7 ( V_4 ) ;
F_28 ( V_86 , L_36 ) ;
V_6 = F_40 ( V_19 , V_85 ) ;
if ( ! V_6 )
goto V_110;
F_28 ( V_86 , L_37 ) ;
}
V_100:
V_6 = F_29 ( V_4 ) ;
if ( V_6 != V_75 ) {
F_28 ( V_86 , L_30
L_18 ) ;
F_7 ( V_4 ) ;
}
} else if ( V_74 == V_83 ) {
V_97 = F_41 ( V_90 -> V_111 ) ;
V_98 = F_41 ( V_90 -> V_112 ) ;
if ( V_98 & V_113 ) {
F_28 ( V_86 , L_38 ) ;
goto V_110;
}
F_28 ( V_86 , L_39 ,
V_98 , V_97 ) ;
V_92 = (struct V_91 * )
& V_4 -> V_92 ;
V_94 = V_4 -> V_94 ;
if ( V_94 -> V_114 == V_115 ) {
if ( V_97 == V_4 -> V_116 ) {
F_28 ( V_86 , L_40 ) ;
V_96 = V_117 ;
V_97 = 0 ;
} else {
F_28 ( V_86 , L_41 ) ;
V_99 = true ;
V_96 = V_118 ;
if ( F_42 ( V_4 ,
V_97 , V_96 ) )
V_100 = true ;
}
} else {
if ( V_92 -> V_119 . V_120 ==
V_4 -> V_116 ) {
F_28 ( V_86 , L_42 ) ;
V_96 = V_117 ;
V_97 = 0 ;
} else {
V_99 = true ;
V_97 = V_92 -> V_119 . V_120 ;
F_28 ( V_86 , L_43 ) ;
V_96 = V_121 ;
if ( F_42 ( V_4 ,
V_97 , V_96 ) )
V_100 = true ;
}
}
if ( V_100 ) {
V_6 = F_29 ( V_4 ) ;
if ( V_6 != V_75 ) {
F_28 ( V_86 , L_44
L_45 ) ;
F_7 ( V_4 ) ;
}
} else if ( ! V_99 ) {
F_28 ( V_86 , L_46 ) ;
F_18 ( & V_19 -> V_43 ) ;
V_6 = F_31 ( V_4 , V_97 , V_96 ) ;
F_17 ( & V_19 -> V_43 ) ;
if ( V_6 ) {
F_28 ( V_86 , L_47
L_48 ) ;
}
}
}
V_110:
F_34 ( V_61 ) ;
V_59:
F_8 ( V_49 ) ;
V_103:
F_4 ( & V_4 -> V_10 , V_11 ) ;
F_8 ( V_2 ) ;
}
int F_37 ( struct V_3 * V_4 )
{
struct V_122 V_123 ;
struct V_18 * V_19 = V_4 -> V_19 ;
struct V_20 * V_21 = V_19 -> V_22 -> V_23 ;
struct V_1 * V_2 = NULL ;
T_1 V_24 = V_19 -> V_24 ;
T_1 V_25 = V_21 -> V_25 ;
int V_6 ;
F_28 ( V_4 , L_49 ) ;
memset ( & V_123 , 0 , sizeof( V_123 ) ) ;
V_2 = F_10 ( sizeof( struct V_1 ) , V_58 ) ;
if ( ! V_2 ) {
F_11 (KERN_ERR PFX L_50 ) ;
V_6 = - V_29 ;
goto V_124;
}
F_43 ( & V_4 -> V_10 ) ;
V_2 -> V_8 = V_4 ;
V_123 . V_125 = V_126 ;
F_12 ( V_123 . V_127 , V_24 ) ;
V_123 . V_128 = F_13 ( V_4 -> V_9 ) ;
V_123 . V_129 = F_13 ( V_4 -> V_36 -> V_37 . V_38 . V_39 ) ;
V_6 = F_14 ( V_19 , V_126 , & V_123 , sizeof( V_123 ) ,
F_35 , V_2 ,
V_25 ) ;
V_124:
if ( V_6 ) {
F_28 ( V_4 , L_51 ) ;
F_17 ( & V_19 -> V_43 ) ;
F_4 ( & V_4 -> V_10 , V_11 ) ;
F_18 ( & V_19 -> V_43 ) ;
F_8 ( V_2 ) ;
}
return V_6 ;
}
int F_31 ( struct V_3 * V_4 , T_1 V_97 , T_3 V_96 )
{
struct V_130 V_131 ;
struct V_18 * V_19 = V_4 -> V_19 ;
struct V_20 * V_21 = V_19 -> V_22 -> V_23 ;
struct V_1 * V_2 = NULL ;
T_1 V_25 = V_21 -> V_25 ;
int V_6 ;
F_28 ( V_4 , L_52 ) ;
memset ( & V_131 , 0 , sizeof( V_131 ) ) ;
V_2 = F_10 ( sizeof( struct V_1 ) , V_58 ) ;
if ( ! V_2 ) {
F_11 (KERN_ERR PFX L_53 ) ;
V_6 = - V_29 ;
goto V_132;
}
F_43 ( & V_4 -> V_10 ) ;
V_2 -> V_8 = V_4 ;
V_131 . V_133 = V_134 ;
V_131 . V_135 = F_13 ( V_4 -> V_9 ) ;
V_131 . V_136 = F_13 ( V_4 -> V_36 -> V_37 . V_38 . V_39 ) ;
V_131 . V_137 = F_44 ( V_97 ) ;
V_131 . V_138 = V_96 ;
V_4 -> V_81 = V_97 ;
V_4 -> V_82 = V_96 ;
V_6 = F_14 ( V_19 , V_134 , & V_131 , sizeof( V_131 ) ,
F_27 , V_2 ,
V_25 ) ;
V_132:
if ( V_6 ) {
F_28 ( V_4 , L_54 ) ;
F_17 ( & V_19 -> V_43 ) ;
F_4 ( & V_4 -> V_10 , V_11 ) ;
F_18 ( & V_19 -> V_43 ) ;
F_8 ( V_2 ) ;
} else
F_39 ( V_139 , & V_4 -> V_13 ) ;
return V_6 ;
}
static int F_14 ( struct V_18 * V_19 , unsigned int V_140 ,
void * V_119 , T_1 V_141 ,
void (* F_45)( struct V_1 * V_2 ) ,
struct V_1 * V_2 , T_1 V_142 )
{
struct V_143 * V_144 = V_19 -> V_144 ;
struct V_145 * V_146 = V_144 -> V_147 ;
struct V_148 * V_149 = V_19 -> V_149 ;
struct V_20 * V_21 = V_144 -> V_21 ;
struct V_3 * V_44 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
struct V_150 * V_36 ;
struct V_150 * V_151 ;
int V_6 = 0 ;
int V_152 , V_153 ;
T_1 V_154 , V_24 ;
T_2 V_9 ;
V_6 = F_46 ( V_149 ) ;
if ( V_6 ) {
F_11 (KERN_ERR PFX L_55 , op) ;
V_6 = - V_155 ;
goto V_156;
}
if ( V_21 -> V_157 != V_158 || ! ( V_21 -> V_159 ) ) {
F_11 (KERN_ERR PFX L_56 , op) ;
V_6 = - V_155 ;
goto V_156;
}
if ( ! ( F_30 ( V_160 , & V_19 -> V_161 ) ) ) {
F_11 (KERN_ERR PFX L_57 , op) ;
V_6 = - V_155 ;
goto V_156;
}
V_44 = F_47 ( V_19 , V_162 ) ;
if ( ! V_44 ) {
V_6 = - V_29 ;
goto V_156;
}
V_44 -> V_94 = NULL ;
V_44 -> V_144 = V_144 ;
V_44 -> V_19 = V_19 ;
V_44 -> F_45 = F_45 ;
V_2 -> V_7 = V_44 ;
V_44 -> V_2 = V_2 ;
V_44 -> V_116 = V_141 ;
V_46 = (struct V_45 * ) & ( V_44 -> V_46 ) ;
V_6 = F_48 ( V_44 ) ;
if ( V_6 == V_42 ) {
F_11 (KERN_ERR PFX L_58 ) ;
F_17 ( & V_19 -> V_43 ) ;
F_4 ( & V_44 -> V_10 , V_11 ) ;
F_18 ( & V_19 -> V_43 ) ;
V_6 = - V_29 ;
goto V_156;
} else {
V_6 = 0 ;
}
V_46 -> V_163 = V_141 ;
V_44 -> V_116 = V_46 -> V_163 ;
if ( ( V_140 >= V_84 ) && ( V_140 <= V_164 ) ) {
memcpy ( V_46 -> V_165 , V_119 , V_141 ) ;
} else {
F_11 (KERN_ERR PFX L_59 , op) ;
V_44 -> F_45 = NULL ;
V_44 -> V_2 = NULL ;
F_17 ( & V_19 -> V_43 ) ;
F_4 ( & V_44 -> V_10 , V_11 ) ;
F_18 ( & V_19 -> V_43 ) ;
V_6 = - V_155 ;
}
if ( V_6 )
goto V_156;
V_48 = & ( V_46 -> V_166 ) ;
V_154 = V_19 -> V_149 -> V_167 ;
V_24 = V_19 -> V_24 ;
if ( V_140 == V_134 )
F_49 ( V_48 , V_168 , V_154 , V_24 ,
V_169 , V_170 |
V_171 | V_172 , 0 ) ;
else
F_49 ( V_48 , V_173 , V_154 , V_24 ,
V_174 , V_170 |
V_171 | V_172 , 0 ) ;
V_9 = V_44 -> V_9 ;
V_152 = V_9 / V_175 ;
V_153 = V_9 % V_175 ;
V_151 = (struct V_150 * )
V_146 -> V_176 -> V_177 [ V_152 ] ;
V_36 = & ( V_151 [ V_153 ] ) ;
F_50 ( V_44 , V_36 ) ;
F_17 ( & V_19 -> V_43 ) ;
if ( ! F_30 ( V_160 , & V_19 -> V_161 ) ) {
F_11 (KERN_ERR PFX L_60 ) ;
V_44 -> F_45 = NULL ;
V_44 -> V_2 = NULL ;
F_4 ( & V_44 -> V_10 , V_11 ) ;
F_18 ( & V_19 -> V_43 ) ;
return - V_155 ;
}
if ( V_142 )
F_51 ( V_44 , V_142 ) ;
F_52 ( V_19 , V_9 ) ;
V_44 -> V_14 = 1 ;
F_53 ( & V_44 -> V_15 , & V_19 -> V_178 ) ;
F_54 ( V_19 ) ;
F_18 ( & V_19 -> V_43 ) ;
V_156:
return V_6 ;
}
void F_55 ( struct V_3 * V_44 ,
struct V_150 * V_36 , T_3 V_179 )
{
struct V_45 * V_46 ;
struct V_47 * V_48 ;
T_4 * V_180 ;
T_4 * V_181 ;
F_3 ( L_61
L_62 , V_44 -> V_9 , V_44 -> V_182 ) ;
if ( F_56 ( V_183 ,
& V_44 -> V_13 ) ) {
F_3 ( L_63
L_64 , V_44 -> V_9 ) ;
F_4 ( & V_44 -> V_10 , V_11 ) ;
return;
}
if ( F_57 ( & V_44 -> V_184 ) )
F_4 ( & V_44 -> V_10 ,
V_11 ) ;
if ( V_44 -> V_14 ) {
F_6 ( & V_44 -> V_15 ) ;
V_44 -> V_14 = 0 ;
}
V_46 = & ( V_44 -> V_46 ) ;
V_48 = & ( V_46 -> V_56 ) ;
V_180 = ( T_4 * ) V_48 ;
V_181 = ( T_4 * )
& V_36 -> V_185 . V_186 . V_187 . V_188 . V_48 ;
V_180 [ 0 ] = F_58 ( V_181 [ 0 ] ) ;
V_180 [ 1 ] = F_58 ( V_181 [ 1 ] ) ;
V_180 [ 2 ] = F_58 ( V_181 [ 2 ] ) ;
V_46 -> V_51 =
V_36 -> V_185 . V_186 . V_187 . V_188 . V_189 ;
if ( ( V_44 -> F_45 ) && ( V_44 -> V_2 ) ) {
V_44 -> F_45 ( V_44 -> V_2 ) ;
V_44 -> V_2 = NULL ;
}
F_4 ( & V_44 -> V_10 , V_11 ) ;
}
static void F_59 ( struct V_190 * V_191 , struct V_60 * V_61 ,
void * V_192 )
{
struct V_193 * V_194 = V_192 ;
struct V_195 * V_196 = F_60 ( V_191 ) ;
struct V_20 * V_21 = V_196 -> V_197 ;
T_3 * V_198 ;
T_3 V_140 ;
if ( F_61 ( V_61 ) )
goto V_199;
V_198 = F_62 ( V_61 ) -> V_200 ;
if ( F_63 ( V_198 ) ) {
V_140 = F_33 ( V_61 ) ;
if ( V_21 -> V_201 ) {
if ( V_140 == V_84 ) {
F_11 (KERN_ERR PFX L_65 ) ;
F_64 ( V_21 -> V_201 ) ;
F_34 ( V_61 ) ;
return;
}
}
F_65 ( V_194 , V_21 , V_61 ) ;
}
if ( ! F_63 ( V_198 ) )
V_194 -> V_202 ( V_21 , V_198 ) ;
V_199:
F_66 ( V_191 , V_61 , V_21 ) ;
}
static void F_67 ( struct V_190 * V_191 , struct V_60 * V_61 ,
void * V_192 )
{
struct V_193 * V_194 = V_192 ;
struct V_195 * V_196 = F_60 ( V_191 ) ;
struct V_20 * V_21 = V_196 -> V_197 ;
static T_3 V_203 [ V_204 ] = { 0 } ;
if ( ! F_61 ( V_61 ) )
V_194 -> V_202 ( V_21 , V_203 ) ;
F_68 ( V_191 , V_61 , V_21 ) ;
}
struct V_190 * F_69 ( struct V_20 * V_21 , T_1 V_154 ,
struct V_60 * V_61 , unsigned int V_140 ,
void (* F_70)( struct V_190 * ,
struct V_60 * ,
void * ) ,
void * V_192 , T_1 V_205 )
{
struct V_143 * V_144 = F_71 ( V_21 ) ;
struct V_145 * V_146 = V_144 -> V_147 ;
struct V_193 * V_194 = F_72 ( V_146 ) ;
struct V_47 * V_64 = F_22 ( V_61 ) ;
switch ( V_140 ) {
case V_206 :
case V_207 :
return F_73 ( V_21 , V_154 , V_61 , V_140 , F_59 ,
V_194 , V_205 ) ;
case V_69 :
if ( F_74 ( V_64 -> V_208 ) != V_209 )
break;
return F_73 ( V_21 , V_154 , V_61 , V_140 , F_67 ,
V_194 , V_205 ) ;
}
return F_73 ( V_21 , V_154 , V_61 , V_140 , F_70 , V_192 , V_205 ) ;
}
