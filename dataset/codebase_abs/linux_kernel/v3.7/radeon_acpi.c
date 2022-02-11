static union V_1 * F_1 ( T_1 V_2 , int V_3 ,
struct V_4 * V_5 )
{
T_2 V_6 ;
union V_1 V_7 [ 2 ] ;
struct V_8 V_9 ;
struct V_4 V_10 = { V_11 , NULL } ;
V_9 . V_12 = 2 ;
V_9 . V_13 = & V_7 [ 0 ] ;
V_7 [ 0 ] . type = V_14 ;
V_7 [ 0 ] . integer . V_15 = V_3 ;
if ( V_5 ) {
V_7 [ 1 ] . type = V_16 ;
V_7 [ 1 ] . V_10 . V_17 = V_5 -> V_17 ;
V_7 [ 1 ] . V_10 . V_13 = V_5 -> V_13 ;
} else {
V_7 [ 1 ] . type = V_14 ;
V_7 [ 1 ] . integer . V_15 = 0 ;
}
V_6 = F_2 ( V_2 , L_1 , & V_9 , & V_10 ) ;
if ( F_3 ( V_6 ) && V_6 != V_18 ) {
F_4 ( L_2 ,
F_5 ( V_6 ) ) ;
F_6 ( V_10 . V_13 ) ;
return NULL ;
}
return V_10 . V_13 ;
}
static void F_7 ( struct V_19 * V_20 , T_3 V_21 )
{
V_20 -> V_22 = V_21 & V_23 ;
V_20 -> V_24 = V_21 & V_25 ;
V_20 -> V_26 = V_21 & V_27 ;
V_20 -> V_28 = V_21 & V_29 ;
V_20 -> V_30 = V_21 & V_31 ;
V_20 -> V_32 = V_21 & V_33 ;
V_20 -> V_34 = V_21 & V_35 ;
V_20 -> V_36 = V_21 & V_37 ;
V_20 -> V_38 = V_21 & V_39 ;
}
static void F_8 ( struct V_40 * V_41 , T_3 V_21 )
{
V_41 -> V_42 = V_21 & V_43 ;
V_41 -> V_44 = V_21 & V_45 ;
V_41 -> V_46 = V_21 & V_47 ;
V_41 -> V_48 = V_21 & V_49 ;
V_41 -> V_50 = V_21 & V_51 ;
V_41 -> V_52 = V_21 & V_53 ;
V_41 -> V_54 = V_21 & V_55 ;
V_41 -> V_56 = V_21 & V_57 ;
V_41 -> V_58 = V_21 & V_59 ;
V_41 -> V_60 = V_21 & V_61 ;
}
static int F_9 ( T_1 V_2 ,
struct V_62 * V_63 )
{
union V_1 * V_64 ;
struct V_65 V_66 ;
T_4 V_67 ;
int V_68 = 0 ;
V_64 = F_1 ( V_2 , V_69 , NULL ) ;
if ( ! V_64 )
return - V_70 ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_67 = * ( V_71 * ) V_64 -> V_10 . V_13 ;
if ( V_67 < 12 ) {
F_10 ( L_3 , V_67 ) ;
V_68 = - V_72 ;
goto V_73;
}
V_67 = F_11 ( sizeof( V_66 ) , V_67 ) ;
memcpy ( & V_66 , V_64 -> V_10 . V_13 , V_67 ) ;
F_4 ( L_4 , V_66 . V_74 ) ;
F_7 ( & V_63 -> V_75 , V_66 . V_76 ) ;
F_8 ( & V_63 -> V_77 , V_66 . V_78 ) ;
V_73:
F_6 ( V_64 ) ;
return V_68 ;
}
static int F_12 ( T_1 V_2 ,
struct V_79 * V_20 )
{
union V_1 * V_64 ;
struct V_80 V_5 ;
T_4 V_67 ;
int V_68 = 0 ;
V_64 = F_1 ( V_2 , V_81 , NULL ) ;
if ( ! V_64 ) {
V_68 = - V_70 ;
goto V_73;
}
V_67 = * ( V_71 * ) V_64 -> V_10 . V_13 ;
if ( V_67 < 10 ) {
V_68 = - V_72 ;
goto V_73;
}
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
V_67 = F_11 ( sizeof( V_5 ) , V_67 ) ;
memcpy ( & V_5 , V_64 -> V_10 . V_13 , V_67 ) ;
F_4 ( L_5 ,
V_5 . V_82 , V_5 . V_83 ) ;
V_5 . V_82 = V_5 . V_82 & V_5 . V_83 ;
if ( ( V_5 . V_82 & V_84 ) == V_85 ) {
V_20 -> V_86 = false ;
V_20 -> V_87 = 0 ;
} else if ( ( V_5 . V_82 & V_84 ) == V_88 ) {
V_20 -> V_86 = true ;
V_20 -> V_87 = 0x81 ;
} else {
if ( V_67 < 11 ) {
V_68 = - V_72 ;
goto V_73;
}
V_20 -> V_86 = true ;
V_20 -> V_87 = V_5 . V_87 ;
}
V_73:
F_4 ( L_6 ,
( V_20 -> V_86 ? L_7 : L_8 ) ,
V_20 -> V_87 ) ;
F_6 ( V_64 ) ;
return V_68 ;
}
static int F_13 ( T_1 V_2 ,
struct V_89 * V_90 )
{
union V_1 * V_64 ;
T_4 V_67 ;
int V_12 = 0 ;
V_64 = F_1 ( V_2 , V_91 , NULL ) ;
if ( ! V_64 )
return - V_70 ;
V_67 = * ( V_71 * ) V_64 -> V_10 . V_13 ;
if ( V_67 < 0xd ) {
V_12 = - V_72 ;
goto V_73;
}
memset ( V_90 , 0 , sizeof( * V_90 ) ) ;
V_67 = F_11 ( sizeof( * V_90 ) , V_67 ) ;
memcpy ( V_90 , V_64 -> V_10 . V_13 , V_67 ) ;
F_4 ( L_9 , V_90 -> V_92 ) ;
V_12 = F_14 ( V_90 -> V_92 ) ;
V_73:
F_6 ( V_64 ) ;
return V_12 ;
}
int F_15 ( struct V_93 * V_94 ,
struct V_95 * V_96 )
{
struct V_62 * V_63 = & V_94 -> V_63 ;
struct V_89 V_90 ;
T_1 V_2 ;
int V_12 ;
F_4 ( L_10 ,
V_96 -> V_97 , V_96 -> type ) ;
if ( strcmp ( V_96 -> V_97 , V_98 ) != 0 )
return V_99 ;
if ( ! V_63 -> V_100 . V_86 ||
V_96 -> type != V_63 -> V_100 . V_87 )
return V_99 ;
V_2 = F_16 ( & V_94 -> V_101 -> V_102 ) ;
V_12 = F_13 ( V_2 , & V_90 ) ;
if ( V_12 <= 0 )
return V_99 ;
F_4 ( L_11 , V_12 ) ;
if ( V_90 . V_92 & V_103 ) {
struct V_104 * V_105 = V_63 -> V_106 ;
if ( V_105 ) {
F_4 ( L_12 ,
V_90 . V_107 ) ;
F_17 ( V_94 , V_105 , V_90 . V_107 ) ;
#if F_18 ( V_108 ) || F_18 ( V_109 )
if ( V_94 -> V_110 ) {
struct V_111 * V_112 = V_105 -> V_113 ;
F_19 ( V_112 -> V_114 ,
V_115 ) ;
} else {
struct V_116 * V_112 = V_105 -> V_113 ;
F_19 ( V_112 -> V_114 ,
V_115 ) ;
}
#endif
}
}
return V_117 ;
}
static union V_1 * F_20 ( T_1 V_2 , int V_3 ,
struct V_4 * V_5 )
{
T_2 V_6 ;
union V_1 V_118 [ 2 ] ;
struct V_8 V_119 ;
struct V_4 V_10 = { V_11 , NULL } ;
V_119 . V_12 = 2 ;
V_119 . V_13 = & V_118 [ 0 ] ;
V_118 [ 0 ] . type = V_14 ;
V_118 [ 0 ] . integer . V_15 = V_3 ;
if ( V_5 ) {
V_118 [ 1 ] . type = V_16 ;
V_118 [ 1 ] . V_10 . V_17 = V_5 -> V_17 ;
V_118 [ 1 ] . V_10 . V_13 = V_5 -> V_13 ;
} else {
V_118 [ 1 ] . type = V_14 ;
V_118 [ 1 ] . integer . V_15 = 0 ;
}
V_6 = F_2 ( V_2 , L_13 , & V_119 , & V_10 ) ;
if ( F_3 ( V_6 ) && V_6 != V_18 ) {
F_4 ( L_14 ,
F_5 ( V_6 ) ) ;
F_6 ( V_10 . V_13 ) ;
return NULL ;
}
return V_10 . V_13 ;
}
static void F_21 ( struct V_120 * V_41 , T_3 V_21 )
{
V_41 -> V_121 = V_21 & V_122 ;
V_41 -> V_123 = V_21 & V_124 ;
V_41 -> V_125 = V_21 & V_126 ;
V_41 -> V_127 = V_21 & V_128 ;
}
static int F_22 ( T_1 V_2 ,
struct V_129 * V_130 )
{
union V_1 * V_64 ;
struct V_131 V_66 ;
T_4 V_67 ;
int V_68 = 0 ;
V_64 = F_20 ( V_2 , V_132 , NULL ) ;
if ( ! V_64 )
return - V_70 ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_67 = * ( V_71 * ) V_64 -> V_10 . V_13 ;
if ( V_67 < 8 ) {
F_10 ( L_15 , V_67 ) ;
V_68 = - V_72 ;
goto V_73;
}
V_67 = F_11 ( sizeof( V_66 ) , V_67 ) ;
memcpy ( & V_66 , V_64 -> V_10 . V_13 , V_67 ) ;
F_4 ( L_16 , V_66 . V_74 ) ;
F_21 ( & V_130 -> V_77 , V_66 . V_78 ) ;
V_73:
F_6 ( V_64 ) ;
return V_68 ;
}
static int F_23 ( struct V_133 * V_134 ,
unsigned long V_135 ,
void * V_136 )
{
struct V_93 * V_94 = F_24 ( V_134 , struct V_93 , V_137 ) ;
struct V_95 * V_138 = (struct V_95 * ) V_136 ;
if ( strcmp ( V_138 -> V_97 , V_139 ) == 0 ) {
if ( F_25 () > 0 )
F_4 ( L_17 ) ;
else
F_4 ( L_18 ) ;
F_26 ( V_94 ) ;
}
return F_15 ( V_94 , V_138 ) ;
}
int F_27 ( struct V_93 * V_94 )
{
T_1 V_2 ;
struct V_62 * V_63 = & V_94 -> V_63 ;
struct V_129 * V_130 = & V_94 -> V_130 ;
int V_140 ;
V_2 = F_16 ( & V_94 -> V_101 -> V_102 ) ;
if ( ! F_28 ( V_94 ) || ! V_94 -> V_141 || ! V_2 )
return 0 ;
V_140 = F_22 ( V_2 , V_130 ) ;
if ( V_140 ) {
F_4 ( L_19 , V_140 ) ;
}
V_140 = F_9 ( V_2 , V_63 ) ;
if ( V_140 ) {
F_4 ( L_20 , V_140 ) ;
goto V_73;
}
if ( V_63 -> V_75 . V_36 ) {
struct V_142 * V_143 ;
struct V_104 * V_144 = NULL ;
F_29 (tmp, &rdev->ddev->mode_config.encoder_list,
head) {
struct V_104 * V_105 = F_30 ( V_143 ) ;
if ( ( V_105 -> V_145 & ( V_146 ) ) &&
V_105 -> V_113 ) {
if ( V_94 -> V_110 ) {
struct V_111 * V_112 = V_105 -> V_113 ;
if ( V_112 -> V_114 ) {
V_144 = V_105 ;
break;
}
} else {
struct V_116 * V_112 = V_105 -> V_113 ;
if ( V_112 -> V_114 ) {
V_144 = V_105 ;
break;
}
}
}
}
V_63 -> V_106 = V_144 ;
if ( ! V_144 ) {
F_31 ( L_21 ) ;
}
}
if ( V_63 -> V_77 . V_44 && ! V_63 -> V_77 . V_42 ) {
V_63 -> V_77 . V_42 = true ;
}
if ( V_63 -> V_77 . V_42 ) {
V_140 = F_12 ( V_2 ,
& V_63 -> V_100 ) ;
if ( V_140 ) {
F_4 ( L_22 ,
V_140 ) ;
V_63 -> V_100 . V_86 = false ;
}
}
V_73:
V_94 -> V_137 . V_147 = F_23 ;
F_32 ( & V_94 -> V_137 ) ;
return V_140 ;
}
void F_33 ( struct V_93 * V_94 )
{
F_34 ( & V_94 -> V_137 ) ;
}
