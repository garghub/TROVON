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
V_17 . V_35 = F_13 ( V_8 -> V_36 -> V_37 . V_38 ) ;
V_39:
V_6 = F_14 ( V_19 , V_32 , & V_17 , sizeof( V_17 ) ,
F_1 , V_2 ,
V_25 ) ;
if ( V_6 == - V_29 ) {
if ( F_15 ( V_27 , V_26 + ( 10 * V_40 ) ) ) {
F_3 ( L_5 ) ;
V_6 = V_41 ;
goto V_30;
}
F_16 ( 20 ) ;
goto V_39;
}
V_30:
if ( V_6 ) {
F_3 ( L_6 ,
V_8 -> V_9 ) ;
F_8 ( V_2 ) ;
F_17 ( & V_19 -> V_42 ) ;
F_4 ( & V_8 -> V_10 , V_11 ) ;
F_18 ( & V_19 -> V_42 ) ;
}
return V_6 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_43 ;
struct V_18 * V_19 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
unsigned char * V_48 ;
void * V_49 ;
T_1 V_50 , V_51 ;
T_2 V_52 ;
int V_53 ;
int V_6 = 0 ;
V_52 = V_2 -> V_52 ;
F_3 ( L_7 , V_52 ) ;
V_43 = V_2 -> V_7 ;
if ( F_5 ( V_12 , & V_43 -> V_13 ) ) {
if ( V_43 -> V_14 ) {
F_6 ( & V_43 -> V_15 ) ;
V_43 -> V_14 = 0 ;
V_6 = F_7 ( V_43 ) ;
F_2 ( V_6 ) ;
}
goto V_54;
}
V_19 = V_43 -> V_19 ;
V_45 = & ( V_43 -> V_45 ) ;
V_47 = & ( V_45 -> V_55 ) ;
V_50 = V_45 -> V_50 ;
V_49 = V_45 -> V_49 ;
V_48 = F_10 ( V_56 , V_57 ) ;
if ( ! V_48 ) {
F_11 (KERN_ERR PFX L_8 ) ;
goto V_54;
}
V_51 = sizeof( * V_47 ) ;
if ( V_51 + V_50 > V_56 ) {
F_11 (KERN_ERR PFX L_9
L_10 ) ;
goto V_58;
}
memcpy ( V_48 , V_47 , V_51 ) ;
memcpy ( V_48 + V_51 , V_49 , V_50 ) ;
V_53 = V_51 + V_50 ;
F_20 ( V_19 , V_48 , V_53 , V_52 ) ;
V_58:
F_8 ( V_48 ) ;
V_54:
F_8 ( V_2 ) ;
}
int F_21 ( struct V_18 * V_19 , struct V_59 * V_60 )
{
struct V_61 * V_62 ;
struct V_46 * V_63 ;
struct V_1 * V_2 ;
struct V_20 * V_21 = V_19 -> V_22 -> V_23 ;
T_1 V_25 = V_21 -> V_25 ;
int V_6 ;
V_63 = F_22 ( V_60 ) ;
V_2 = F_10 ( sizeof( struct V_1 ) , V_57 ) ;
if ( ! V_2 ) {
F_11 (KERN_ERR PFX L_11 ) ;
return - V_29 ;
}
V_2 -> V_52 = F_23 ( V_63 -> V_64 ) ;
F_3 ( L_12 , V_2 -> V_52 ) ;
V_62 = F_24 ( V_60 , sizeof( * V_62 ) ) ;
V_6 = F_14 ( V_19 , V_65 , V_62 , sizeof( * V_62 ) ,
F_19 , V_2 , 2 * V_25 ) ;
if ( V_6 )
F_8 ( V_2 ) ;
return V_6 ;
}
int F_25 ( struct V_18 * V_19 , struct V_59 * V_60 )
{
struct V_66 * V_67 ;
struct V_46 * V_63 ;
struct V_1 * V_2 ;
struct V_20 * V_21 = V_19 -> V_22 -> V_23 ;
T_1 V_25 = V_21 -> V_25 ;
int V_6 ;
V_63 = F_22 ( V_60 ) ;
V_2 = F_10 ( sizeof( struct V_1 ) , V_57 ) ;
if ( ! V_2 ) {
F_11 (KERN_ERR PFX L_13 ) ;
return - V_29 ;
}
V_2 -> V_52 = F_23 ( V_63 -> V_64 ) ;
F_3 ( L_14 , V_2 -> V_52 ) ;
V_67 = F_24 ( V_60 , sizeof( * V_67 ) ) ;
V_6 = F_14 ( V_19 , V_68 , V_67 , sizeof( * V_67 ) ,
F_19 , V_2 , 2 * V_25 ) ;
if ( V_6 )
F_8 ( V_2 ) ;
return V_6 ;
}
int F_26 ( struct V_18 * V_19 , struct V_59 * V_60 )
{
struct V_69 * V_70 ;
struct V_46 * V_63 ;
struct V_1 * V_2 ;
struct V_20 * V_21 = V_19 -> V_22 -> V_23 ;
T_1 V_25 = V_21 -> V_25 ;
int V_6 ;
V_63 = F_22 ( V_60 ) ;
V_2 = F_10 ( sizeof( struct V_1 ) , V_57 ) ;
if ( ! V_2 ) {
F_11 (KERN_ERR PFX L_13 ) ;
return - V_29 ;
}
V_2 -> V_52 = F_23 ( V_63 -> V_64 ) ;
V_70 = F_24 ( V_60 , sizeof( * V_70 ) ) ;
V_6 = F_14 ( V_19 , V_71 , V_70 , sizeof( * V_70 ) ,
F_19 , V_2 , 2 * V_25 ) ;
if ( V_6 )
F_8 ( V_2 ) ;
return V_6 ;
}
static int F_14 ( struct V_18 * V_19 , unsigned int V_72 ,
void * V_73 , T_1 V_74 ,
void (* F_27)( struct V_1 * V_2 ) ,
struct V_1 * V_2 , T_1 V_75 )
{
struct V_76 * V_77 = V_19 -> V_77 ;
struct V_78 * V_79 = V_77 -> V_80 ;
struct V_81 * V_82 = V_19 -> V_82 ;
struct V_20 * V_21 = V_77 -> V_21 ;
struct V_3 * V_43 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
struct V_83 * V_36 ;
struct V_83 * V_84 ;
int V_6 = 0 ;
int V_85 , V_86 ;
T_1 V_87 , V_24 ;
T_2 V_9 ;
V_6 = F_28 ( V_82 ) ;
if ( V_6 ) {
F_11 (KERN_ALERT PFX L_15 , op) ;
V_6 = - V_88 ;
goto V_89;
}
if ( V_21 -> V_90 != V_91 || ! ( V_21 -> V_92 ) ) {
F_11 (KERN_ALERT PFX L_16 , op) ;
V_6 = - V_88 ;
goto V_89;
}
if ( ! ( F_29 ( V_93 , & V_19 -> V_94 ) ) ||
( F_29 ( V_95 , & V_19 -> V_94 ) ) ) {
F_11 (KERN_ERR PFX L_17 , op) ;
V_6 = - V_88 ;
goto V_89;
}
V_43 = F_30 ( V_19 , V_96 ) ;
if ( ! V_43 ) {
V_6 = - V_29 ;
goto V_89;
}
V_43 -> V_97 = NULL ;
V_43 -> V_77 = V_77 ;
V_43 -> V_19 = V_19 ;
V_43 -> F_27 = F_27 ;
V_2 -> V_7 = V_43 ;
V_43 -> V_2 = V_2 ;
V_45 = (struct V_44 * ) & ( V_43 -> V_45 ) ;
V_6 = F_31 ( V_43 ) ;
if ( V_6 == V_41 ) {
F_11 (KERN_ALERT PFX L_18 ) ;
F_17 ( & V_19 -> V_42 ) ;
F_4 ( & V_43 -> V_10 , V_11 ) ;
F_18 ( & V_19 -> V_42 ) ;
V_6 = - V_29 ;
goto V_89;
} else {
V_6 = 0 ;
}
V_45 -> V_98 = V_74 ;
V_43 -> V_99 = V_45 -> V_98 ;
if ( ( V_72 >= V_100 ) && ( V_72 <= V_101 ) ) {
memcpy ( V_45 -> V_102 , V_73 , V_74 ) ;
} else {
F_11 (KERN_ALERT PFX L_19 , op) ;
V_43 -> F_27 = NULL ;
V_43 -> V_2 = NULL ;
F_17 ( & V_19 -> V_42 ) ;
F_4 ( & V_43 -> V_10 , V_11 ) ;
F_18 ( & V_19 -> V_42 ) ;
V_6 = - V_88 ;
}
if ( V_6 )
goto V_89;
V_47 = & ( V_45 -> V_103 ) ;
V_87 = V_19 -> V_82 -> V_104 ;
V_24 = V_19 -> V_24 ;
F_32 ( V_47 , V_105 , V_87 , V_24 ,
V_106 , V_107 | V_108 |
V_109 , 0 ) ;
V_9 = V_43 -> V_9 ;
V_85 = V_9 / V_110 ;
V_86 = V_9 % V_110 ;
V_84 = (struct V_83 * ) V_79 -> V_111 [ V_85 ] ;
V_36 = & ( V_84 [ V_86 ] ) ;
F_33 ( V_43 , V_36 ) ;
F_17 ( & V_19 -> V_42 ) ;
if ( ! F_29 ( V_93 , & V_19 -> V_94 ) ) {
F_11 (KERN_ERR PFX L_20 ) ;
V_43 -> F_27 = NULL ;
V_43 -> V_2 = NULL ;
F_4 ( & V_43 -> V_10 , V_11 ) ;
F_18 ( & V_19 -> V_42 ) ;
return - V_88 ;
}
if ( V_75 )
F_34 ( V_43 , V_75 ) ;
F_35 ( V_19 , V_9 ) ;
V_43 -> V_14 = 1 ;
F_36 ( & V_43 -> V_15 , & V_19 -> V_112 ) ;
F_37 ( V_19 ) ;
F_18 ( & V_19 -> V_42 ) ;
V_89:
return V_6 ;
}
void F_38 ( struct V_3 * V_43 ,
struct V_83 * V_36 , T_3 V_113 )
{
struct V_44 * V_45 ;
struct V_46 * V_47 ;
T_4 * V_114 ;
T_4 * V_115 ;
F_3 ( L_21
L_22 , V_43 -> V_9 , V_43 -> V_116 ) ;
if ( F_39 ( V_117 ,
& V_43 -> V_13 ) ) {
F_3 ( L_23
L_24 , V_43 -> V_9 ) ;
F_4 ( & V_43 -> V_10 , V_11 ) ;
return;
}
if ( F_40 ( & V_43 -> V_118 ) )
F_4 ( & V_43 -> V_10 ,
V_11 ) ;
if ( V_43 -> V_14 ) {
F_6 ( & V_43 -> V_15 ) ;
V_43 -> V_14 = 0 ;
}
V_45 = & ( V_43 -> V_45 ) ;
V_47 = & ( V_45 -> V_55 ) ;
V_114 = ( T_4 * ) V_47 ;
V_115 = ( T_4 * )
& V_36 -> V_119 . V_120 . V_121 . V_122 . V_47 ;
V_114 [ 0 ] = F_41 ( V_115 [ 0 ] ) ;
V_114 [ 1 ] = F_41 ( V_115 [ 1 ] ) ;
V_114 [ 2 ] = F_41 ( V_115 [ 2 ] ) ;
V_45 -> V_50 = V_36 -> V_123 . V_124 . V_125 . V_126 ;
if ( ( V_43 -> F_27 ) && ( V_43 -> V_2 ) ) {
V_43 -> F_27 ( V_43 -> V_2 ) ;
V_43 -> V_2 = NULL ;
}
F_4 ( & V_43 -> V_10 , V_11 ) ;
}
static void F_42 ( struct V_127 * V_128 , struct V_59 * V_60 ,
void * V_129 )
{
struct V_130 * V_131 = V_129 ;
struct V_132 * V_133 = F_43 ( V_128 ) ;
struct V_20 * V_21 = V_133 -> V_134 ;
T_3 * V_135 ;
struct V_46 * V_63 ;
T_3 V_72 ;
if ( F_44 ( V_60 ) )
goto V_136;
V_135 = F_45 ( V_60 ) -> V_137 ;
if ( F_46 ( V_135 ) ) {
V_63 = F_22 ( V_60 ) ;
if ( V_63 -> V_138 != V_106 ) {
F_11 (KERN_ERR PFX L_25
L_26 ) ;
F_47 ( V_60 ) ;
return;
}
V_72 = F_48 ( V_60 ) ;
if ( V_21 -> V_139 ) {
if ( V_72 == V_100 ) {
F_11 (KERN_ERR PFX L_27 ) ;
F_49 ( V_21 -> V_139 ) ;
F_47 ( V_60 ) ;
return;
}
}
if ( F_50 ( V_131 , V_21 , V_60 ) ) {
F_47 ( V_60 ) ;
return;
}
}
V_131 -> V_140 ( V_21 , V_135 ) ;
V_136:
F_51 ( V_128 , V_60 , V_21 ) ;
}
static void F_52 ( struct V_127 * V_128 , struct V_59 * V_60 ,
void * V_129 )
{
struct V_130 * V_131 = V_129 ;
struct V_132 * V_133 = F_43 ( V_128 ) ;
struct V_20 * V_21 = V_133 -> V_134 ;
static T_3 V_141 [ V_142 ] = { 0 } ;
if ( ! F_44 ( V_60 ) )
V_131 -> V_140 ( V_21 , V_141 ) ;
F_53 ( V_128 , V_60 , V_21 ) ;
}
struct V_127 * F_54 ( struct V_20 * V_21 , T_1 V_87 ,
struct V_59 * V_60 , unsigned int V_72 ,
void (* F_55)( struct V_127 * ,
struct V_59 * ,
void * ) ,
void * V_129 , T_1 V_143 )
{
struct V_76 * V_77 = F_56 ( V_21 ) ;
struct V_78 * V_79 = V_77 -> V_80 ;
struct V_130 * V_131 = & V_79 -> V_144 ;
struct V_46 * V_63 = F_22 ( V_60 ) ;
switch ( V_72 ) {
case V_145 :
case V_146 :
return F_57 ( V_21 , V_87 , V_60 , V_72 , F_42 ,
V_131 , V_143 ) ;
case V_68 :
if ( F_58 ( V_63 -> V_147 ) != V_148 )
break;
return F_57 ( V_21 , V_87 , V_60 , V_72 , F_52 ,
V_131 , V_143 ) ;
}
return F_57 ( V_21 , V_87 , V_60 , V_72 , F_55 , V_129 , V_143 ) ;
}
