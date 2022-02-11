int
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 ;
V_9 = F_2 ( sizeof( * V_9 ) , V_10 ) ;
if ( ! V_9 )
return - V_11 ;
F_3 ( & V_9 -> V_12 ) ;
V_9 -> V_13 = V_3 ;
V_9 -> V_4 = V_4 ;
F_4 ( & V_9 -> V_14 , & V_6 -> V_15 ) ;
return 0 ;
}
int
F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_16 ,
int (* F_6)( struct V_17 * , T_1 , T_1 , T_1 ) )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_18 * V_19 ;
struct V_8 * V_9 ;
F_7 (oc, &dev_priv->classes, head) {
if ( V_9 -> V_13 == V_3 )
goto V_20;
}
return - V_21 ;
V_20:
V_19 = F_2 ( sizeof( * V_19 ) , V_10 ) ;
if ( ! V_19 )
return - V_11 ;
V_19 -> V_16 = V_16 ;
V_19 -> F_6 = F_6 ;
F_4 ( & V_19 -> V_14 , & V_9 -> V_12 ) ;
return 0 ;
}
int
F_8 ( struct V_17 * V_22 ,
T_1 V_3 , T_1 V_16 , T_1 V_23 )
{
struct V_5 * V_6 = V_22 -> V_2 -> V_7 ;
struct V_18 * V_19 ;
struct V_8 * V_9 ;
F_7 (oc, &dev_priv->classes, head) {
if ( V_9 -> V_13 != V_3 )
continue;
F_7 (om, &oc->methods, head) {
if ( V_19 -> V_16 == V_16 )
return V_19 -> F_6 ( V_22 , V_3 , V_16 , V_23 ) ;
}
}
return - V_24 ;
}
int
F_9 ( struct V_1 * V_2 , int V_25 ,
T_1 V_3 , T_1 V_16 , T_1 V_23 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_17 * V_22 = NULL ;
unsigned long V_26 ;
int V_27 = - V_21 ;
F_10 ( & V_6 -> V_28 . V_29 , V_26 ) ;
if ( V_25 >= 0 && V_25 < V_6 -> V_4 . V_30 . V_28 )
V_22 = V_6 -> V_28 . V_31 [ V_25 ] ;
if ( V_22 )
V_27 = F_8 ( V_22 , V_3 , V_16 , V_23 ) ;
F_11 ( & V_6 -> V_28 . V_29 , V_26 ) ;
return V_27 ;
}
int
F_12 ( struct V_1 * V_2 , struct V_17 * V_22 ,
T_2 V_32 , int V_33 , T_2 V_26 ,
struct V_34 * * V_35 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_36 * V_37 = & V_6 -> V_4 . V_37 ;
struct V_34 * V_38 ;
struct V_39 * V_40 = NULL ;
int V_27 , V_41 ;
F_13 ( V_2 , L_1 ,
V_22 ? V_22 -> V_13 : - 1 , V_32 , V_33 , V_26 ) ;
V_38 = F_2 ( sizeof( * V_38 ) , V_10 ) ;
if ( ! V_38 )
return - V_11 ;
F_13 ( V_2 , L_2 , V_38 ) ;
V_38 -> V_2 = V_2 ;
V_38 -> V_26 = V_26 ;
F_14 ( & V_38 -> V_42 ) ;
V_38 -> V_32 = V_32 ;
F_15 ( & V_6 -> V_43 ) ;
F_16 ( & V_38 -> V_44 , & V_6 -> V_45 ) ;
F_17 ( & V_6 -> V_43 ) ;
if ( ! ( V_26 & V_46 ) && V_22 ) {
V_40 = F_18 ( & V_22 -> V_47 , V_32 , V_33 , 0 ) ;
if ( V_40 )
V_40 = F_19 ( V_40 , V_32 , V_33 ) ;
if ( ! V_40 ) {
F_20 ( NULL , & V_38 ) ;
return - V_11 ;
}
V_38 -> V_48 = V_22 -> V_40 -> V_48 ;
if ( V_38 -> V_48 != ~ 0 )
V_38 -> V_48 += V_40 -> V_49 ;
V_38 -> V_50 = V_40 -> V_49 ;
V_38 -> V_51 = V_40 -> V_49 + V_22 -> V_40 -> V_51 ;
V_38 -> V_52 = V_40 ;
} else {
V_27 = V_37 -> V_53 ( V_38 , V_22 , V_32 , V_33 ) ;
if ( V_27 ) {
F_20 ( NULL , & V_38 ) ;
return V_27 ;
}
V_27 = - V_54 ;
if ( ! ( V_26 & V_55 ) )
V_27 = V_37 -> V_56 ( V_38 ) ;
if ( V_27 )
V_38 -> V_48 = ~ 0 ;
V_38 -> V_50 = V_57 ;
}
if ( V_38 -> V_26 & V_58 ) {
for ( V_41 = 0 ; V_41 < V_38 -> V_32 ; V_41 += 4 )
F_21 ( V_38 , V_41 , 0 ) ;
V_37 -> V_59 ( V_2 ) ;
}
* V_35 = V_38 ;
return 0 ;
}
int
F_22 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_13 ( V_2 , L_3 ) ;
F_3 ( & V_6 -> V_45 ) ;
F_3 ( & V_6 -> V_15 ) ;
F_23 ( & V_6 -> V_43 ) ;
V_6 -> V_60 = ~ 0 ;
return 0 ;
}
void
F_24 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_18 * V_19 , * V_61 ;
struct V_8 * V_9 , * V_62 ;
F_13 ( V_2 , L_3 ) ;
F_25 (oc, tc, &dev_priv->classes, head) {
F_25 (om, tm, &oc->methods, head) {
F_26 ( & V_19 -> V_14 ) ;
F_27 ( V_19 ) ;
}
F_26 ( & V_9 -> V_14 ) ;
F_27 ( V_9 ) ;
}
F_28 ( ! F_29 ( & V_6 -> V_45 ) ) ;
}
static void
F_30 ( struct V_63 * V_64 )
{
struct V_34 * V_38 =
F_31 ( V_64 , struct V_34 , V_42 ) ;
struct V_1 * V_2 = V_38 -> V_2 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_36 * V_37 = & V_6 -> V_4 . V_37 ;
int V_41 ;
F_13 ( V_2 , L_2 , V_38 ) ;
if ( V_38 -> V_52 && ( V_38 -> V_26 & V_65 ) ) {
for ( V_41 = 0 ; V_41 < V_38 -> V_32 ; V_41 += 4 )
F_21 ( V_38 , V_41 , 0 ) ;
V_37 -> V_59 ( V_2 ) ;
}
if ( V_38 -> V_66 )
V_38 -> V_66 ( V_2 , V_38 ) ;
if ( V_38 -> V_50 == V_57 ) {
if ( V_38 -> V_52 ) {
V_37 -> V_67 ( V_38 ) ;
V_37 -> V_68 ( V_38 ) ;
}
} else {
if ( V_38 -> V_52 ) {
F_15 ( & V_6 -> V_43 ) ;
F_32 ( V_38 -> V_52 ) ;
F_17 ( & V_6 -> V_43 ) ;
}
}
F_15 ( & V_6 -> V_43 ) ;
F_26 ( & V_38 -> V_44 ) ;
F_17 ( & V_6 -> V_43 ) ;
F_27 ( V_38 ) ;
}
void
F_20 ( struct V_34 * V_64 , struct V_34 * * V_31 )
{
if ( V_64 )
F_33 ( & V_64 -> V_42 ) ;
if ( * V_31 )
F_34 ( & ( * V_31 ) -> V_42 , F_30 ) ;
* V_31 = V_64 ;
}
int
F_35 ( struct V_1 * V_2 , T_1 V_48 , T_3 V_51 ,
T_1 V_32 , T_1 V_26 , struct V_34 * * V_69 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_34 * V_38 = NULL ;
int V_41 ;
F_13 ( V_2 ,
L_4 ,
V_48 , V_51 , V_32 , V_26 ) ;
V_38 = F_2 ( sizeof( * V_38 ) , V_10 ) ;
if ( ! V_38 )
return - V_11 ;
F_13 ( V_2 , L_2 , V_38 ) ;
V_38 -> V_2 = V_2 ;
V_38 -> V_26 = V_26 ;
F_14 ( & V_38 -> V_42 ) ;
V_38 -> V_32 = V_32 ;
V_38 -> V_48 = V_48 ;
V_38 -> V_50 = V_57 ;
V_38 -> V_51 = V_51 ;
if ( V_38 -> V_26 & V_58 ) {
for ( V_41 = 0 ; V_41 < V_38 -> V_32 ; V_41 += 4 )
F_21 ( V_38 , V_41 , 0 ) ;
V_6 -> V_4 . V_37 . V_59 ( V_2 ) ;
}
F_15 ( & V_6 -> V_43 ) ;
F_16 ( & V_38 -> V_44 , & V_6 -> V_45 ) ;
F_17 ( & V_6 -> V_43 ) ;
* V_69 = V_38 ;
return 0 ;
}
void
F_36 ( struct V_34 * V_70 , T_1 V_71 , int V_3 ,
T_3 V_72 , T_3 V_32 , int V_73 , int V_74 ,
T_1 type , T_1 V_75 )
{
struct V_5 * V_6 = V_70 -> V_2 -> V_7 ;
struct V_36 * V_76 = & V_6 -> V_4 . V_37 ;
T_1 V_77 ;
V_77 = ( V_75 << 29 ) | ( type << 22 ) | V_3 ;
V_77 |= 0x00100000 ;
switch ( V_74 ) {
case V_78 : V_77 |= 0x00040000 ; break;
case V_79 :
case V_80 : V_77 |= 0x00080000 ; break;
default:
break;
}
switch ( V_73 ) {
case V_81 :
V_77 |= 0x00010000 ;
break;
case V_82 :
V_77 |= 0x00020000 ;
break;
case V_83 :
V_77 |= 0x00030000 ;
break;
case V_84 :
V_72 += V_6 -> V_85 . V_86 ;
default:
V_77 &= ~ 0x00100000 ;
break;
}
V_32 = ( V_72 + V_32 ) - 1 ;
F_21 ( V_70 , V_71 + 0x00 , V_77 ) ;
F_21 ( V_70 , V_71 + 0x04 , F_37 ( V_32 ) ) ;
F_21 ( V_70 , V_71 + 0x08 , F_37 ( V_72 ) ) ;
F_21 ( V_70 , V_71 + 0x0c , F_38 ( V_32 ) << 24 |
F_38 ( V_72 ) ) ;
F_21 ( V_70 , V_71 + 0x10 , 0x00000000 ) ;
F_21 ( V_70 , V_71 + 0x14 , 0x00000000 ) ;
V_76 -> V_59 ( V_70 -> V_2 ) ;
}
int
F_39 ( struct V_17 * V_22 , int V_3 , T_3 V_72 , T_3 V_32 ,
int V_73 , int V_74 , T_1 type , T_1 V_75 ,
struct V_34 * * V_87 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_27 ;
V_27 = F_12 ( V_2 , V_22 , 24 , 16 , V_65 , V_87 ) ;
if ( V_27 )
return V_27 ;
F_36 ( * V_87 , 0 , V_3 , V_72 , V_32 , V_73 ,
V_74 , type , V_75 ) ;
return 0 ;
}
int
F_40 ( struct V_17 * V_22 , int V_3 , T_3 V_72 ,
T_3 V_32 , int V_74 , int V_73 ,
struct V_34 * * V_87 )
{
struct V_5 * V_6 = V_22 -> V_2 -> V_7 ;
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_34 * V_70 ;
T_1 V_77 , V_88 ;
int V_27 ;
if ( V_6 -> V_89 >= V_90 ) {
T_1 V_75 = ( V_73 == V_91 ) ? V_92 : 0 ;
T_1 type = ( V_73 == V_91 ) ? V_93 : 0 ;
return F_39 ( V_22 , V_3 , V_72 , V_32 ,
V_73 , V_74 , type , V_75 , V_87 ) ;
}
if ( V_73 == V_84 ) {
struct V_34 * V_94 = V_6 -> V_85 . V_95 ;
if ( V_6 -> V_85 . type == V_96 ) {
if ( V_72 == 0 ) {
F_20 ( V_94 , V_87 ) ;
return 0 ;
}
V_72 = F_41 ( V_2 , V_72 ) ;
V_73 = V_82 ;
} else {
V_72 += V_6 -> V_85 . V_86 ;
if ( V_6 -> V_85 . type == V_97 )
V_73 = V_83 ;
else
V_73 = V_82 ;
}
}
V_77 = V_3 ;
V_77 |= 0x00003000 ;
V_88 = 0 ;
switch ( V_73 ) {
case V_82 :
V_77 |= 0x00020000 ;
break;
case V_83 :
V_77 |= 0x00030000 ;
break;
default:
break;
}
switch ( V_74 ) {
case V_78 :
V_77 |= 0x00004000 ;
break;
case V_80 :
V_77 |= 0x00008000 ;
default:
V_88 |= 0x00000002 ;
break;
}
V_77 |= ( V_72 & 0x00000fff ) << 20 ;
V_88 |= ( V_72 & 0xfffff000 ) ;
V_27 = F_12 ( V_2 , V_22 , 16 , 16 , V_65 , & V_70 ) ;
if ( V_27 )
return V_27 ;
F_21 ( V_70 , 0x00 , V_77 ) ;
F_21 ( V_70 , 0x04 , V_32 - 1 ) ;
F_21 ( V_70 , 0x08 , V_88 ) ;
F_21 ( V_70 , 0x0c , V_88 ) ;
V_70 -> V_4 = V_98 ;
V_70 -> V_3 = V_3 ;
* V_87 = V_70 ;
return 0 ;
}
static int
F_42 ( struct V_17 * V_22 , T_1 V_99 , T_4 V_3 )
{
struct V_5 * V_6 = V_22 -> V_2 -> V_7 ;
struct V_34 * V_38 ;
int V_27 ;
V_38 = F_2 ( sizeof( * V_38 ) , V_10 ) ;
if ( ! V_38 )
return - V_11 ;
V_38 -> V_2 = V_22 -> V_2 ;
V_38 -> V_4 = V_98 ;
V_38 -> V_3 = V_3 ;
F_14 ( & V_38 -> V_42 ) ;
V_38 -> V_50 = 0x40 ;
F_15 ( & V_6 -> V_43 ) ;
F_16 ( & V_38 -> V_44 , & V_6 -> V_45 ) ;
F_17 ( & V_6 -> V_43 ) ;
V_27 = F_43 ( V_22 , V_99 , V_38 ) ;
F_20 ( NULL , & V_38 ) ;
return V_27 ;
}
int
F_44 ( struct V_17 * V_22 , T_1 V_99 , int V_3 )
{
struct V_5 * V_6 = V_22 -> V_2 -> V_7 ;
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_8 * V_9 ;
int V_27 ;
F_13 ( V_2 , L_5 , V_22 -> V_13 , V_3 ) ;
F_7 (oc, &dev_priv->classes, head) {
struct V_100 * V_101 = V_6 -> V_101 [ V_9 -> V_4 ] ;
if ( V_9 -> V_13 != V_3 )
continue;
if ( V_9 -> V_4 == V_98 )
return F_42 ( V_22 , V_99 , V_3 ) ;
if ( ! V_22 -> V_102 [ V_9 -> V_4 ] ) {
V_27 = V_101 -> V_103 ( V_22 , V_9 -> V_4 ) ;
if ( V_27 )
return V_27 ;
}
return V_101 -> V_104 ( V_22 , V_9 -> V_4 , V_99 , V_3 ) ;
}
F_45 ( V_2 , L_6 , V_3 ) ;
return - V_21 ;
}
static int
F_46 ( struct V_17 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_5 * V_6 = V_2 -> V_7 ;
T_2 V_32 ;
T_2 V_72 ;
int V_27 ;
F_13 ( V_2 , L_7 , V_22 -> V_13 ) ;
V_32 = 0x2000 ;
V_72 = 0 ;
if ( V_6 -> V_89 == V_90 ) {
V_32 += 0x1400 ;
V_32 += 0x4000 ;
V_72 = 0x6000 ;
V_32 += 0x8000 ;
V_32 += 0x1000 ;
}
V_27 = F_12 ( V_2 , NULL , V_32 , 0x1000 , 0 , & V_22 -> V_40 ) ;
if ( V_27 ) {
F_45 ( V_2 , L_8 , V_27 ) ;
return V_27 ;
}
V_27 = F_47 ( & V_22 -> V_47 , V_72 , V_32 - V_72 ) ;
if ( V_27 ) {
F_45 ( V_2 , L_9 , V_27 ) ;
F_20 ( NULL , & V_22 -> V_40 ) ;
return V_27 ;
}
return 0 ;
}
static int
F_48 ( struct V_17 * V_22 , struct V_105 * V_106 )
{
struct V_5 * V_6 = V_22 -> V_2 -> V_7 ;
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_34 * V_107 = NULL ;
struct V_108 * V_109 ;
int V_27 , V_41 ;
V_27 = F_12 ( V_2 , NULL , 4096 , 0x1000 , 0 , & V_22 -> V_40 ) ;
if ( V_27 )
return V_27 ;
if ( F_29 ( & V_106 -> V_110 ) ) {
V_27 = F_12 ( V_2 , NULL , 65536 , 0x1000 , 0 , & V_107 ) ;
if ( V_27 )
return V_27 ;
}
F_49 ( V_106 , & V_22 -> V_106 , V_107 ) ;
F_20 ( NULL , & V_107 ) ;
V_109 = F_50 ( & V_106 -> V_110 , struct V_108 , V_14 ) ;
F_21 ( V_22 -> V_40 , 0x0200 , F_37 ( V_109 -> V_70 -> V_51 ) ) ;
F_21 ( V_22 -> V_40 , 0x0204 , F_38 ( V_109 -> V_70 -> V_51 ) ) ;
F_21 ( V_22 -> V_40 , 0x0208 , 0xffffffff ) ;
F_21 ( V_22 -> V_40 , 0x020c , 0x000000ff ) ;
for ( V_41 = 0 ; V_41 < V_2 -> V_111 . V_112 ; V_41 ++ ) {
struct V_113 * V_114 ;
if ( V_6 -> V_89 >= V_115 )
V_114 = F_51 ( V_2 , V_41 ) ;
else
V_114 = F_52 ( V_2 ) -> V_116 [ V_41 ] . V_117 . V_114 ;
V_27 = F_53 ( V_114 , V_22 -> V_106 , & V_22 -> V_118 [ V_41 ] ) ;
if ( V_27 )
return V_27 ;
}
return 0 ;
}
int
F_54 ( struct V_17 * V_22 ,
T_2 V_119 , T_2 V_120 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_121 * V_122 = V_121 ( V_22 -> V_123 ) ;
struct V_105 * V_106 = V_122 ? V_122 -> V_106 : V_6 -> V_124 ;
struct V_34 * V_125 = NULL , * V_126 = NULL ;
int V_27 , V_41 ;
F_13 ( V_2 , L_10 , V_22 -> V_13 , V_119 , V_120 ) ;
if ( V_6 -> V_89 >= V_127 )
return F_48 ( V_22 , V_106 ) ;
V_27 = F_46 ( V_22 ) ;
if ( V_27 ) {
F_45 ( V_2 , L_11 ) ;
return V_27 ;
}
if ( V_106 ) {
T_1 V_128 = ( V_6 -> V_129 == 0x50 ) ? 0x1400 : 0x0200 ;
T_3 V_130 = V_22 -> V_40 -> V_51 + V_128 ;
T_1 V_131 = V_22 -> V_40 -> V_48 ;
if ( V_131 != ~ 0 )
V_131 += V_128 ;
V_27 = F_35 ( V_2 , V_131 , V_130 , 0x4000 ,
0 , & V_22 -> V_132 ) ;
if ( V_27 )
return V_27 ;
F_49 ( V_106 , & V_22 -> V_106 , V_22 -> V_132 ) ;
}
if ( V_6 -> V_89 < V_90 ) {
F_55 ( V_6 -> V_133 , & V_22 -> V_133 , NULL ) ;
} else {
struct V_34 * V_133 = NULL ;
V_27 = F_12 ( V_2 , V_22 , 0x8000 , 16 ,
V_58 , & V_133 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_56 ( V_2 , V_133 , & V_22 -> V_133 ) ;
F_20 ( NULL , & V_133 ) ;
if ( V_27 )
return V_27 ;
for ( V_41 = 0 ; V_41 < V_2 -> V_111 . V_112 ; V_41 ++ ) {
struct V_34 * V_117 = NULL ;
struct V_134 * V_135 =
& F_52 ( V_2 ) -> V_116 [ V_41 ] ;
T_3 V_71 = V_135 -> V_117 . V_114 -> V_114 . V_71 ;
V_27 = F_40 ( V_22 , 0x3d , V_71 , 0xfff ,
V_79 ,
V_81 , & V_117 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_43 ( V_22 , V_136 + V_41 , V_117 ) ;
F_20 ( NULL , & V_117 ) ;
if ( V_27 )
return V_27 ;
}
}
if ( V_6 -> V_89 >= V_90 ) {
V_27 = F_40 ( V_22 , V_137 ,
0 , ( 1ULL << 40 ) , V_79 ,
V_91 , & V_125 ) ;
if ( V_27 ) {
F_45 ( V_2 , L_12 , V_27 ) ;
return V_27 ;
}
} else {
V_27 = F_40 ( V_22 , V_137 ,
0 , V_6 -> V_138 ,
V_79 ,
V_81 , & V_125 ) ;
if ( V_27 ) {
F_45 ( V_2 , L_12 , V_27 ) ;
return V_27 ;
}
}
V_27 = F_43 ( V_22 , V_119 , V_125 ) ;
F_20 ( NULL , & V_125 ) ;
if ( V_27 ) {
F_45 ( V_2 , L_13 , V_27 ) ;
return V_27 ;
}
if ( V_6 -> V_89 >= V_90 ) {
V_27 = F_40 ( V_22 , V_137 ,
0 , ( 1ULL << 40 ) , V_79 ,
V_91 , & V_126 ) ;
} else {
V_27 = F_40 ( V_22 , V_137 ,
0 , V_6 -> V_85 . V_139 ,
V_79 ,
V_84 , & V_126 ) ;
}
if ( V_27 ) {
F_45 ( V_2 , L_14 , V_27 ) ;
return V_27 ;
}
V_27 = F_43 ( V_22 , V_120 , V_126 ) ;
F_20 ( NULL , & V_126 ) ;
if ( V_27 ) {
F_45 ( V_2 , L_15 , V_27 ) ;
return V_27 ;
}
return 0 ;
}
void
F_57 ( struct V_17 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_41 ;
F_13 ( V_2 , L_7 , V_22 -> V_13 ) ;
if ( V_6 -> V_89 >= V_115 ) {
for ( V_41 = 0 ; V_41 < V_2 -> V_111 . V_112 ; V_41 ++ ) {
struct V_113 * V_114 = F_51 ( V_2 , V_41 ) ;
F_58 ( V_114 , & V_22 -> V_118 [ V_41 ] ) ;
}
} else
if ( V_6 -> V_89 >= V_90 ) {
struct F_52 * V_140 = F_52 ( V_2 ) ;
for ( V_41 = 0 ; V_41 < V_2 -> V_111 . V_112 ; V_41 ++ ) {
struct V_134 * V_135 = & V_140 -> V_116 [ V_41 ] ;
F_58 ( V_135 -> V_117 . V_114 , & V_22 -> V_118 [ V_41 ] ) ;
}
}
F_49 ( NULL , & V_22 -> V_106 , V_22 -> V_132 ) ;
F_20 ( NULL , & V_22 -> V_132 ) ;
if ( F_59 ( & V_22 -> V_47 ) )
F_60 ( & V_22 -> V_47 ) ;
F_20 ( NULL , & V_22 -> V_40 ) ;
}
int
F_61 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_34 * V_38 ;
int V_41 ;
F_7 (gpuobj, &dev_priv->gpuobj_list, list) {
if ( V_38 -> V_50 != V_57 )
continue;
V_38 -> V_141 = F_62 ( V_38 -> V_32 ) ;
if ( ! V_38 -> V_141 ) {
F_63 ( V_2 ) ;
return - V_11 ;
}
for ( V_41 = 0 ; V_41 < V_38 -> V_32 ; V_41 += 4 )
V_38 -> V_141 [ V_41 / 4 ] = F_64 ( V_38 , V_41 ) ;
}
return 0 ;
}
void
F_63 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_34 * V_38 ;
int V_41 ;
F_7 (gpuobj, &dev_priv->gpuobj_list, list) {
if ( ! V_38 -> V_141 )
continue;
for ( V_41 = 0 ; V_41 < V_38 -> V_32 ; V_41 += 4 )
F_21 ( V_38 , V_41 , V_38 -> V_141 [ V_41 / 4 ] ) ;
F_65 ( V_38 -> V_141 ) ;
V_38 -> V_141 = NULL ;
}
V_6 -> V_4 . V_37 . V_59 ( V_2 ) ;
}
int F_66 ( struct V_1 * V_2 , void * V_23 ,
struct V_142 * V_123 )
{
struct V_143 * V_144 = V_23 ;
struct V_17 * V_22 ;
int V_27 ;
if ( V_144 -> V_99 == ~ 0 )
return - V_21 ;
V_22 = F_67 ( V_123 , V_144 -> V_145 ) ;
if ( F_68 ( V_22 ) )
return F_69 ( V_22 ) ;
if ( F_70 ( V_22 , V_144 -> V_99 ) ) {
V_27 = - V_146 ;
goto V_147;
}
V_27 = F_44 ( V_22 , V_144 -> V_99 , V_144 -> V_3 ) ;
if ( V_27 ) {
F_45 ( V_2 , L_16 ,
V_27 , V_144 -> V_145 , V_144 -> V_99 ) ;
}
V_147:
F_71 ( & V_22 ) ;
return V_27 ;
}
int F_72 ( struct V_1 * V_2 , void * V_23 ,
struct V_142 * V_123 )
{
struct V_148 * V_149 = V_23 ;
struct V_17 * V_22 ;
int V_27 ;
V_22 = F_67 ( V_123 , V_149 -> V_145 ) ;
if ( F_68 ( V_22 ) )
return F_69 ( V_22 ) ;
F_73 ( V_22 ) ;
V_27 = F_74 ( V_22 , V_149 -> V_99 ) ;
F_71 ( & V_22 ) ;
return V_27 ;
}
T_1
F_64 ( struct V_34 * V_38 , T_1 V_71 )
{
struct V_5 * V_6 = V_38 -> V_2 -> V_7 ;
struct V_1 * V_2 = V_38 -> V_2 ;
unsigned long V_26 ;
if ( V_38 -> V_48 == ~ 0 || ! V_6 -> V_150 ) {
T_3 V_31 = V_38 -> V_51 + V_71 ;
T_1 V_72 = V_31 >> 16 ;
T_1 V_151 ;
F_10 ( & V_6 -> V_152 , V_26 ) ;
if ( V_6 -> V_60 != V_72 ) {
V_6 -> V_60 = V_72 ;
F_75 ( V_2 , 0x001700 , V_6 -> V_60 ) ;
}
V_151 = F_76 ( V_2 , 0x700000 + ( V_31 & 0xffff ) ) ;
F_11 ( & V_6 -> V_152 , V_26 ) ;
return V_151 ;
}
return F_77 ( V_2 , V_38 -> V_48 + V_71 ) ;
}
void
F_21 ( struct V_34 * V_38 , T_1 V_71 , T_1 V_151 )
{
struct V_5 * V_6 = V_38 -> V_2 -> V_7 ;
struct V_1 * V_2 = V_38 -> V_2 ;
unsigned long V_26 ;
if ( V_38 -> V_48 == ~ 0 || ! V_6 -> V_150 ) {
T_3 V_31 = V_38 -> V_51 + V_71 ;
T_1 V_72 = V_31 >> 16 ;
F_10 ( & V_6 -> V_152 , V_26 ) ;
if ( V_6 -> V_60 != V_72 ) {
V_6 -> V_60 = V_72 ;
F_75 ( V_2 , 0x001700 , V_6 -> V_60 ) ;
}
F_75 ( V_2 , 0x700000 + ( V_31 & 0xffff ) , V_151 ) ;
F_11 ( & V_6 -> V_152 , V_26 ) ;
return;
}
F_78 ( V_2 , V_38 -> V_48 + V_71 , V_151 ) ;
}
