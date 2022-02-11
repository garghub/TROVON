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
struct V_26 * V_27 = F_10 ( V_2 , V_28 ) ;
struct V_17 * V_22 = NULL ;
unsigned long V_29 ;
int V_30 = - V_21 ;
F_11 ( & V_6 -> V_31 . V_32 , V_29 ) ;
if ( V_25 >= 0 && V_25 < V_27 -> V_31 )
V_22 = V_6 -> V_31 . V_33 [ V_25 ] ;
if ( V_22 )
V_30 = F_8 ( V_22 , V_3 , V_16 , V_23 ) ;
F_12 ( & V_6 -> V_31 . V_32 , V_29 ) ;
return V_30 ;
}
int
F_13 ( struct V_1 * V_2 , struct V_17 * V_22 ,
T_2 V_34 , int V_35 , T_2 V_29 ,
struct V_36 * * V_37 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_38 * V_39 = & V_6 -> V_4 . V_39 ;
struct V_36 * V_40 ;
struct V_41 * V_42 = NULL ;
int V_30 , V_43 ;
F_14 ( V_2 , L_1 ,
V_22 ? V_22 -> V_13 : - 1 , V_34 , V_35 , V_29 ) ;
V_40 = F_2 ( sizeof( * V_40 ) , V_10 ) ;
if ( ! V_40 )
return - V_11 ;
F_14 ( V_2 , L_2 , V_40 ) ;
V_40 -> V_2 = V_2 ;
V_40 -> V_29 = V_29 ;
F_15 ( & V_40 -> V_44 ) ;
V_40 -> V_34 = V_34 ;
F_16 ( & V_6 -> V_45 ) ;
F_17 ( & V_40 -> V_46 , & V_6 -> V_47 ) ;
F_18 ( & V_6 -> V_45 ) ;
if ( ! ( V_29 & V_48 ) && V_22 ) {
V_42 = F_19 ( & V_22 -> V_49 , V_34 , V_35 , 0 ) ;
if ( V_42 )
V_42 = F_20 ( V_42 , V_34 , V_35 ) ;
if ( ! V_42 ) {
F_21 ( NULL , & V_40 ) ;
return - V_11 ;
}
V_40 -> V_50 = V_22 -> V_42 -> V_50 ;
if ( V_40 -> V_50 != ~ 0 )
V_40 -> V_50 += V_42 -> V_51 ;
V_40 -> V_52 = V_42 -> V_51 ;
V_40 -> V_53 = V_42 -> V_51 + V_22 -> V_42 -> V_53 ;
V_40 -> V_54 = V_42 ;
} else {
V_30 = V_39 -> V_55 ( V_40 , V_22 , V_34 , V_35 ) ;
if ( V_30 ) {
F_21 ( NULL , & V_40 ) ;
return V_30 ;
}
V_30 = - V_56 ;
if ( ! ( V_29 & V_57 ) )
V_30 = V_39 -> V_58 ( V_40 ) ;
if ( V_30 )
V_40 -> V_50 = ~ 0 ;
V_40 -> V_52 = V_59 ;
}
if ( V_40 -> V_29 & V_60 ) {
for ( V_43 = 0 ; V_43 < V_40 -> V_34 ; V_43 += 4 )
F_22 ( V_40 , V_43 , 0 ) ;
V_39 -> V_61 ( V_2 ) ;
}
* V_37 = V_40 ;
return 0 ;
}
int
F_23 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_14 ( V_2 , L_3 ) ;
F_3 ( & V_6 -> V_47 ) ;
F_3 ( & V_6 -> V_15 ) ;
F_24 ( & V_6 -> V_45 ) ;
V_6 -> V_62 = ~ 0 ;
return 0 ;
}
void
F_25 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_18 * V_19 , * V_63 ;
struct V_8 * V_9 , * V_64 ;
F_14 ( V_2 , L_3 ) ;
F_26 (oc, tc, &dev_priv->classes, head) {
F_26 (om, tm, &oc->methods, head) {
F_27 ( & V_19 -> V_14 ) ;
F_28 ( V_19 ) ;
}
F_27 ( & V_9 -> V_14 ) ;
F_28 ( V_9 ) ;
}
F_29 ( ! F_30 ( & V_6 -> V_47 ) ) ;
}
static void
F_31 ( struct V_65 * V_66 )
{
struct V_36 * V_40 =
F_32 ( V_66 , struct V_36 , V_44 ) ;
struct V_1 * V_2 = V_40 -> V_2 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_38 * V_39 = & V_6 -> V_4 . V_39 ;
int V_43 ;
F_14 ( V_2 , L_2 , V_40 ) ;
if ( V_40 -> V_54 && ( V_40 -> V_29 & V_67 ) ) {
for ( V_43 = 0 ; V_43 < V_40 -> V_34 ; V_43 += 4 )
F_22 ( V_40 , V_43 , 0 ) ;
V_39 -> V_61 ( V_2 ) ;
}
if ( V_40 -> V_68 )
V_40 -> V_68 ( V_2 , V_40 ) ;
if ( V_40 -> V_52 == V_59 ) {
if ( V_40 -> V_54 ) {
V_39 -> V_69 ( V_40 ) ;
V_39 -> V_70 ( V_40 ) ;
}
} else {
if ( V_40 -> V_54 ) {
F_16 ( & V_6 -> V_45 ) ;
F_33 ( V_40 -> V_54 ) ;
F_18 ( & V_6 -> V_45 ) ;
}
}
F_16 ( & V_6 -> V_45 ) ;
F_27 ( & V_40 -> V_46 ) ;
F_18 ( & V_6 -> V_45 ) ;
F_28 ( V_40 ) ;
}
void
F_21 ( struct V_36 * V_66 , struct V_36 * * V_33 )
{
if ( V_66 )
F_34 ( & V_66 -> V_44 ) ;
if ( * V_33 )
F_35 ( & ( * V_33 ) -> V_44 , F_31 ) ;
* V_33 = V_66 ;
}
int
F_36 ( struct V_1 * V_2 , T_1 V_50 , T_3 V_53 ,
T_1 V_34 , T_1 V_29 , struct V_36 * * V_71 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_36 * V_40 = NULL ;
int V_43 ;
F_14 ( V_2 ,
L_4 ,
V_50 , V_53 , V_34 , V_29 ) ;
V_40 = F_2 ( sizeof( * V_40 ) , V_10 ) ;
if ( ! V_40 )
return - V_11 ;
F_14 ( V_2 , L_2 , V_40 ) ;
V_40 -> V_2 = V_2 ;
V_40 -> V_29 = V_29 ;
F_15 ( & V_40 -> V_44 ) ;
V_40 -> V_34 = V_34 ;
V_40 -> V_50 = V_50 ;
V_40 -> V_52 = V_59 ;
V_40 -> V_53 = V_53 ;
if ( V_40 -> V_29 & V_60 ) {
for ( V_43 = 0 ; V_43 < V_40 -> V_34 ; V_43 += 4 )
F_22 ( V_40 , V_43 , 0 ) ;
V_6 -> V_4 . V_39 . V_61 ( V_2 ) ;
}
F_16 ( & V_6 -> V_45 ) ;
F_17 ( & V_40 -> V_46 , & V_6 -> V_47 ) ;
F_18 ( & V_6 -> V_45 ) ;
* V_71 = V_40 ;
return 0 ;
}
void
F_37 ( struct V_36 * V_72 , T_1 V_73 , int V_3 ,
T_3 V_74 , T_3 V_34 , int V_75 , int V_76 ,
T_1 type , T_1 V_77 )
{
struct V_5 * V_6 = V_72 -> V_2 -> V_7 ;
struct V_38 * V_78 = & V_6 -> V_4 . V_39 ;
T_1 V_79 ;
V_79 = ( V_77 << 29 ) | ( type << 22 ) | V_3 ;
V_79 |= 0x00100000 ;
switch ( V_76 ) {
case V_80 : V_79 |= 0x00040000 ; break;
case V_81 :
case V_82 : V_79 |= 0x00080000 ; break;
default:
break;
}
switch ( V_75 ) {
case V_83 :
V_79 |= 0x00010000 ;
break;
case V_84 :
V_79 |= 0x00020000 ;
break;
case V_85 :
V_79 |= 0x00030000 ;
break;
case V_86 :
V_74 += V_6 -> V_87 . V_88 ;
default:
V_79 &= ~ 0x00100000 ;
break;
}
V_34 = ( V_74 + V_34 ) - 1 ;
F_22 ( V_72 , V_73 + 0x00 , V_79 ) ;
F_22 ( V_72 , V_73 + 0x04 , F_38 ( V_34 ) ) ;
F_22 ( V_72 , V_73 + 0x08 , F_38 ( V_74 ) ) ;
F_22 ( V_72 , V_73 + 0x0c , F_39 ( V_34 ) << 24 |
F_39 ( V_74 ) ) ;
F_22 ( V_72 , V_73 + 0x10 , 0x00000000 ) ;
F_22 ( V_72 , V_73 + 0x14 , 0x00000000 ) ;
V_78 -> V_61 ( V_72 -> V_2 ) ;
}
int
F_40 ( struct V_17 * V_22 , int V_3 , T_3 V_74 , T_3 V_34 ,
int V_75 , int V_76 , T_1 type , T_1 V_77 ,
struct V_36 * * V_89 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_30 ;
V_30 = F_13 ( V_2 , V_22 , 24 , 16 , V_67 , V_89 ) ;
if ( V_30 )
return V_30 ;
F_37 ( * V_89 , 0 , V_3 , V_74 , V_34 , V_75 ,
V_76 , type , V_77 ) ;
return 0 ;
}
int
F_41 ( struct V_17 * V_22 , int V_3 , T_3 V_74 ,
T_3 V_34 , int V_76 , int V_75 ,
struct V_36 * * V_89 )
{
struct V_5 * V_6 = V_22 -> V_2 -> V_7 ;
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_36 * V_72 ;
T_1 V_79 , V_90 ;
int V_30 ;
if ( V_6 -> V_91 >= V_92 ) {
T_1 V_77 = ( V_75 == V_93 ) ? V_94 : 0 ;
T_1 type = ( V_75 == V_93 ) ? V_95 : 0 ;
return F_40 ( V_22 , V_3 , V_74 , V_34 ,
V_75 , V_76 , type , V_77 , V_89 ) ;
}
if ( V_75 == V_86 ) {
struct V_36 * V_96 = V_6 -> V_87 . V_97 ;
if ( V_6 -> V_87 . type == V_98 ) {
if ( V_74 == 0 ) {
F_21 ( V_96 , V_89 ) ;
return 0 ;
}
V_74 = F_42 ( V_2 , V_74 ) ;
V_75 = V_84 ;
} else {
V_74 += V_6 -> V_87 . V_88 ;
if ( V_6 -> V_87 . type == V_99 )
V_75 = V_85 ;
else
V_75 = V_84 ;
}
}
V_79 = V_3 ;
V_79 |= 0x00003000 ;
V_90 = 0 ;
switch ( V_75 ) {
case V_84 :
V_79 |= 0x00020000 ;
break;
case V_85 :
V_79 |= 0x00030000 ;
break;
default:
break;
}
switch ( V_76 ) {
case V_80 :
V_79 |= 0x00004000 ;
break;
case V_82 :
V_79 |= 0x00008000 ;
default:
V_90 |= 0x00000002 ;
break;
}
V_79 |= ( V_74 & 0x00000fff ) << 20 ;
V_90 |= ( V_74 & 0xfffff000 ) ;
V_30 = F_13 ( V_2 , V_22 , 16 , 16 , V_67 , & V_72 ) ;
if ( V_30 )
return V_30 ;
F_22 ( V_72 , 0x00 , V_79 ) ;
F_22 ( V_72 , 0x04 , V_34 - 1 ) ;
F_22 ( V_72 , 0x08 , V_90 ) ;
F_22 ( V_72 , 0x0c , V_90 ) ;
V_72 -> V_4 = V_100 ;
V_72 -> V_3 = V_3 ;
* V_89 = V_72 ;
return 0 ;
}
int
F_43 ( struct V_17 * V_22 , T_1 V_101 , int V_3 )
{
struct V_5 * V_6 = V_22 -> V_2 -> V_7 ;
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_8 * V_9 ;
int V_30 ;
F_14 ( V_2 , L_5 , V_22 -> V_13 , V_3 ) ;
F_7 (oc, &dev_priv->classes, head) {
struct V_102 * V_103 = V_6 -> V_103 [ V_9 -> V_4 ] ;
if ( V_9 -> V_13 != V_3 )
continue;
if ( ! V_22 -> V_104 [ V_9 -> V_4 ] ) {
V_30 = V_103 -> V_105 ( V_22 , V_9 -> V_4 ) ;
if ( V_30 )
return V_30 ;
}
return V_103 -> V_106 ( V_22 , V_9 -> V_4 , V_101 , V_3 ) ;
}
return - V_21 ;
}
static int
F_44 ( struct V_17 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_5 * V_6 = V_2 -> V_7 ;
T_2 V_34 ;
T_2 V_74 ;
int V_30 ;
F_14 ( V_2 , L_6 , V_22 -> V_13 ) ;
V_34 = 0x2000 ;
V_74 = 0 ;
if ( V_6 -> V_91 == V_92 ) {
V_34 += 0x1400 ;
V_34 += 0x4000 ;
V_74 = 0x6000 ;
V_34 += 0x8000 ;
V_34 += 0x1000 ;
}
V_30 = F_13 ( V_2 , NULL , V_34 , 0x1000 , 0 , & V_22 -> V_42 ) ;
if ( V_30 ) {
F_45 ( V_2 , L_7 , V_30 ) ;
return V_30 ;
}
V_30 = F_46 ( & V_22 -> V_49 , V_74 , V_34 - V_74 ) ;
if ( V_30 ) {
F_45 ( V_2 , L_8 , V_30 ) ;
F_21 ( NULL , & V_22 -> V_42 ) ;
return V_30 ;
}
return 0 ;
}
static int
F_47 ( struct V_17 * V_22 , struct V_107 * V_108 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_36 * V_109 = NULL ;
struct V_110 * V_111 ;
int V_30 ;
V_30 = F_13 ( V_2 , NULL , 4096 , 0x1000 , 0 , & V_22 -> V_42 ) ;
if ( V_30 )
return V_30 ;
if ( F_30 ( & V_108 -> V_112 ) ) {
V_30 = F_13 ( V_2 , NULL , 65536 , 0x1000 , 0 , & V_109 ) ;
if ( V_30 )
return V_30 ;
}
F_48 ( V_108 , & V_22 -> V_108 , V_109 ) ;
F_21 ( NULL , & V_109 ) ;
V_111 = F_49 ( & V_108 -> V_112 , struct V_110 , V_14 ) ;
F_22 ( V_22 -> V_42 , 0x0200 , F_38 ( V_111 -> V_72 -> V_53 ) ) ;
F_22 ( V_22 -> V_42 , 0x0204 , F_39 ( V_111 -> V_72 -> V_53 ) ) ;
F_22 ( V_22 -> V_42 , 0x0208 , 0xffffffff ) ;
F_22 ( V_22 -> V_42 , 0x020c , 0x000000ff ) ;
return 0 ;
}
int
F_50 ( struct V_17 * V_22 ,
T_2 V_113 , T_2 V_114 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_115 * V_116 = V_115 ( V_22 -> V_117 ) ;
struct V_107 * V_108 = V_116 ? V_116 -> V_108 : V_6 -> V_118 ;
struct V_36 * V_119 = NULL , * V_120 = NULL ;
int V_30 ;
F_14 ( V_2 , L_9 , V_22 -> V_13 , V_113 , V_114 ) ;
if ( V_6 -> V_91 >= V_121 )
return F_47 ( V_22 , V_108 ) ;
V_30 = F_44 ( V_22 ) ;
if ( V_30 ) {
F_45 ( V_2 , L_10 ) ;
return V_30 ;
}
if ( V_108 ) {
T_1 V_122 = ( V_6 -> V_123 == 0x50 ) ? 0x1400 : 0x0200 ;
T_3 V_124 = V_22 -> V_42 -> V_53 + V_122 ;
T_1 V_125 = V_22 -> V_42 -> V_50 ;
if ( V_125 != ~ 0 )
V_125 += V_122 ;
V_30 = F_36 ( V_2 , V_125 , V_124 , 0x4000 ,
0 , & V_22 -> V_126 ) ;
if ( V_30 )
return V_30 ;
F_48 ( V_108 , & V_22 -> V_108 , V_22 -> V_126 ) ;
}
if ( V_6 -> V_91 < V_92 ) {
F_51 ( V_6 -> V_127 , & V_22 -> V_127 , NULL ) ;
} else {
struct V_36 * V_127 = NULL ;
V_30 = F_13 ( V_2 , V_22 , 0x8000 , 16 ,
V_60 , & V_127 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_52 ( V_2 , V_127 , & V_22 -> V_127 ) ;
F_21 ( NULL , & V_127 ) ;
if ( V_30 )
return V_30 ;
}
if ( V_6 -> V_91 >= V_92 ) {
V_30 = F_41 ( V_22 , V_128 ,
0 , ( 1ULL << 40 ) , V_81 ,
V_93 , & V_119 ) ;
if ( V_30 ) {
F_45 ( V_2 , L_11 , V_30 ) ;
return V_30 ;
}
} else {
V_30 = F_41 ( V_22 , V_128 ,
0 , V_6 -> V_129 ,
V_81 ,
V_83 , & V_119 ) ;
if ( V_30 ) {
F_45 ( V_2 , L_11 , V_30 ) ;
return V_30 ;
}
}
V_30 = F_53 ( V_22 , V_113 , V_119 ) ;
F_21 ( NULL , & V_119 ) ;
if ( V_30 ) {
F_45 ( V_2 , L_12 , V_30 ) ;
return V_30 ;
}
if ( V_6 -> V_91 >= V_92 ) {
V_30 = F_41 ( V_22 , V_128 ,
0 , ( 1ULL << 40 ) , V_81 ,
V_93 , & V_120 ) ;
} else {
V_30 = F_41 ( V_22 , V_128 ,
0 , V_6 -> V_87 . V_130 ,
V_81 ,
V_86 , & V_120 ) ;
}
if ( V_30 ) {
F_45 ( V_2 , L_13 , V_30 ) ;
return V_30 ;
}
V_30 = F_53 ( V_22 , V_114 , V_120 ) ;
F_21 ( NULL , & V_120 ) ;
if ( V_30 ) {
F_45 ( V_2 , L_14 , V_30 ) ;
return V_30 ;
}
return 0 ;
}
void
F_54 ( struct V_17 * V_22 )
{
F_14 ( V_22 -> V_2 , L_6 , V_22 -> V_13 ) ;
F_48 ( NULL , & V_22 -> V_108 , V_22 -> V_126 ) ;
F_21 ( NULL , & V_22 -> V_126 ) ;
if ( F_55 ( & V_22 -> V_49 ) )
F_56 ( & V_22 -> V_49 ) ;
F_21 ( NULL , & V_22 -> V_42 ) ;
}
int
F_57 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_36 * V_40 ;
int V_43 ;
F_7 (gpuobj, &dev_priv->gpuobj_list, list) {
if ( V_40 -> V_52 != V_59 )
continue;
V_40 -> V_131 = F_58 ( V_40 -> V_34 ) ;
if ( ! V_40 -> V_131 ) {
F_59 ( V_2 ) ;
return - V_11 ;
}
for ( V_43 = 0 ; V_43 < V_40 -> V_34 ; V_43 += 4 )
V_40 -> V_131 [ V_43 / 4 ] = F_60 ( V_40 , V_43 ) ;
}
return 0 ;
}
void
F_59 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_36 * V_40 ;
int V_43 ;
F_7 (gpuobj, &dev_priv->gpuobj_list, list) {
if ( ! V_40 -> V_131 )
continue;
for ( V_43 = 0 ; V_43 < V_40 -> V_34 ; V_43 += 4 )
F_22 ( V_40 , V_43 , V_40 -> V_131 [ V_43 / 4 ] ) ;
F_61 ( V_40 -> V_131 ) ;
V_40 -> V_131 = NULL ;
}
V_6 -> V_4 . V_39 . V_61 ( V_2 ) ;
}
int F_62 ( struct V_1 * V_2 , void * V_23 ,
struct V_132 * V_117 )
{
struct V_133 * V_134 = V_23 ;
struct V_17 * V_22 ;
int V_30 ;
if ( V_134 -> V_101 == ~ 0 )
return - V_21 ;
if ( V_134 -> V_3 == 0x506e ) {
V_134 -> V_3 = F_63 ( V_2 ) ;
if ( V_134 -> V_3 == 0x906e )
return 0 ;
} else
if ( V_134 -> V_3 == 0x906e ) {
F_45 ( V_2 , L_15 ) ;
return - V_21 ;
}
V_22 = F_64 ( V_117 , V_134 -> V_135 ) ;
if ( F_65 ( V_22 ) )
return F_66 ( V_22 ) ;
if ( F_67 ( V_22 , V_134 -> V_101 ) ) {
V_30 = - V_136 ;
goto V_137;
}
V_30 = F_43 ( V_22 , V_134 -> V_101 , V_134 -> V_3 ) ;
if ( V_30 ) {
F_45 ( V_2 , L_16 ,
V_30 , V_134 -> V_135 , V_134 -> V_101 ) ;
}
V_137:
F_68 ( & V_22 ) ;
return V_30 ;
}
int F_69 ( struct V_1 * V_2 , void * V_23 ,
struct V_132 * V_117 )
{
struct V_138 * V_139 = V_23 ;
struct V_17 * V_22 ;
int V_30 ;
V_22 = F_64 ( V_117 , V_139 -> V_135 ) ;
if ( F_65 ( V_22 ) )
return F_66 ( V_22 ) ;
F_70 ( V_22 ) ;
V_30 = F_71 ( V_22 , V_139 -> V_101 ) ;
F_68 ( & V_22 ) ;
return V_30 ;
}
T_1
F_60 ( struct V_36 * V_40 , T_1 V_73 )
{
struct V_5 * V_6 = V_40 -> V_2 -> V_7 ;
struct V_1 * V_2 = V_40 -> V_2 ;
unsigned long V_29 ;
if ( V_40 -> V_50 == ~ 0 || ! V_6 -> V_140 ) {
T_3 V_33 = V_40 -> V_53 + V_73 ;
T_1 V_74 = V_33 >> 16 ;
T_1 V_141 ;
F_11 ( & V_6 -> V_142 , V_29 ) ;
if ( V_6 -> V_62 != V_74 ) {
V_6 -> V_62 = V_74 ;
F_72 ( V_2 , 0x001700 , V_6 -> V_62 ) ;
}
V_141 = F_73 ( V_2 , 0x700000 + ( V_33 & 0xffff ) ) ;
F_12 ( & V_6 -> V_142 , V_29 ) ;
return V_141 ;
}
return F_74 ( V_2 , V_40 -> V_50 + V_73 ) ;
}
void
F_22 ( struct V_36 * V_40 , T_1 V_73 , T_1 V_141 )
{
struct V_5 * V_6 = V_40 -> V_2 -> V_7 ;
struct V_1 * V_2 = V_40 -> V_2 ;
unsigned long V_29 ;
if ( V_40 -> V_50 == ~ 0 || ! V_6 -> V_140 ) {
T_3 V_33 = V_40 -> V_53 + V_73 ;
T_1 V_74 = V_33 >> 16 ;
F_11 ( & V_6 -> V_142 , V_29 ) ;
if ( V_6 -> V_62 != V_74 ) {
V_6 -> V_62 = V_74 ;
F_72 ( V_2 , 0x001700 , V_6 -> V_62 ) ;
}
F_72 ( V_2 , 0x700000 + ( V_33 & 0xffff ) , V_141 ) ;
F_12 ( & V_6 -> V_142 , V_29 ) ;
return;
}
F_75 ( V_2 , V_40 -> V_50 + V_73 , V_141 ) ;
}
