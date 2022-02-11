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
if ( V_25 > 0 && V_25 < V_6 -> V_4 . V_30 . V_28 )
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
if ( V_22 ) {
V_40 = F_18 ( & V_22 -> V_46 , V_32 , V_33 , 0 ) ;
if ( V_40 )
V_40 = F_19 ( V_40 , V_32 , V_33 ) ;
if ( ! V_40 ) {
F_20 ( NULL , & V_38 ) ;
return - V_11 ;
}
V_38 -> V_47 = V_22 -> V_40 -> V_47 ;
if ( V_38 -> V_47 != ~ 0 )
V_38 -> V_47 += V_40 -> V_48 ;
V_38 -> V_49 = V_40 -> V_48 ;
V_38 -> V_50 = V_40 -> V_48 + V_22 -> V_40 -> V_50 ;
V_38 -> V_51 = V_40 ;
} else {
V_27 = V_37 -> V_52 ( V_38 , V_32 , V_33 ) ;
if ( V_27 ) {
F_20 ( NULL , & V_38 ) ;
return V_27 ;
}
V_27 = - V_53 ;
if ( ! ( V_26 & V_54 ) )
V_27 = V_37 -> V_55 ( V_38 ) ;
if ( V_27 )
V_38 -> V_47 = ~ 0 ;
V_38 -> V_49 = V_56 ;
}
if ( V_38 -> V_26 & V_57 ) {
for ( V_41 = 0 ; V_41 < V_38 -> V_32 ; V_41 += 4 )
F_21 ( V_38 , V_41 , 0 ) ;
V_37 -> V_58 ( V_2 ) ;
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
V_6 -> V_59 = ~ 0 ;
return 0 ;
}
void
F_24 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_18 * V_19 , * V_60 ;
struct V_8 * V_9 , * V_61 ;
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
F_30 ( struct V_62 * V_63 )
{
struct V_34 * V_38 =
F_31 ( V_63 , struct V_34 , V_42 ) ;
struct V_1 * V_2 = V_38 -> V_2 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_36 * V_37 = & V_6 -> V_4 . V_37 ;
int V_41 ;
F_13 ( V_2 , L_2 , V_38 ) ;
if ( V_38 -> V_51 && ( V_38 -> V_26 & V_64 ) ) {
for ( V_41 = 0 ; V_41 < V_38 -> V_32 ; V_41 += 4 )
F_21 ( V_38 , V_41 , 0 ) ;
V_37 -> V_58 ( V_2 ) ;
}
if ( V_38 -> V_65 )
V_38 -> V_65 ( V_2 , V_38 ) ;
if ( V_38 -> V_49 == V_56 ) {
if ( V_38 -> V_51 ) {
V_37 -> V_66 ( V_38 ) ;
V_37 -> V_67 ( V_38 ) ;
}
} else {
if ( V_38 -> V_51 ) {
F_15 ( & V_6 -> V_43 ) ;
F_32 ( V_38 -> V_51 ) ;
F_17 ( & V_6 -> V_43 ) ;
}
}
F_15 ( & V_6 -> V_43 ) ;
F_26 ( & V_38 -> V_44 ) ;
F_17 ( & V_6 -> V_43 ) ;
F_27 ( V_38 ) ;
}
void
F_20 ( struct V_34 * V_63 , struct V_34 * * V_31 )
{
if ( V_63 )
F_33 ( & V_63 -> V_42 ) ;
if ( * V_31 )
F_34 ( & ( * V_31 ) -> V_42 , F_30 ) ;
* V_31 = V_63 ;
}
int
F_35 ( struct V_1 * V_2 , T_1 V_47 , T_3 V_50 ,
T_1 V_32 , T_1 V_26 , struct V_34 * * V_68 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_34 * V_38 = NULL ;
int V_41 ;
F_13 ( V_2 ,
L_4 ,
V_47 , V_50 , V_32 , V_26 ) ;
V_38 = F_2 ( sizeof( * V_38 ) , V_10 ) ;
if ( ! V_38 )
return - V_11 ;
F_13 ( V_2 , L_2 , V_38 ) ;
V_38 -> V_2 = V_2 ;
V_38 -> V_26 = V_26 ;
F_14 ( & V_38 -> V_42 ) ;
V_38 -> V_32 = V_32 ;
V_38 -> V_47 = V_47 ;
V_38 -> V_49 = V_56 ;
V_38 -> V_50 = V_50 ;
if ( V_38 -> V_26 & V_57 ) {
for ( V_41 = 0 ; V_41 < V_38 -> V_32 ; V_41 += 4 )
F_21 ( V_38 , V_41 , 0 ) ;
V_6 -> V_4 . V_37 . V_58 ( V_2 ) ;
}
F_15 ( & V_6 -> V_43 ) ;
F_16 ( & V_38 -> V_44 , & V_6 -> V_45 ) ;
F_17 ( & V_6 -> V_43 ) ;
* V_68 = V_38 ;
return 0 ;
}
void
F_36 ( struct V_34 * V_69 , T_1 V_70 , int V_3 ,
T_3 V_71 , T_3 V_32 , int V_72 , int V_73 ,
T_1 type , T_1 V_74 )
{
struct V_5 * V_6 = V_69 -> V_2 -> V_7 ;
struct V_36 * V_75 = & V_6 -> V_4 . V_37 ;
T_1 V_76 ;
V_76 = ( V_74 << 29 ) | ( type << 22 ) | V_3 ;
V_76 |= 0x00100000 ;
switch ( V_73 ) {
case V_77 : V_76 |= 0x00040000 ; break;
case V_78 :
case V_79 : V_76 |= 0x00080000 ; break;
default:
break;
}
switch ( V_72 ) {
case V_80 :
V_76 |= 0x00010000 ;
break;
case V_81 :
V_76 |= 0x00020000 ;
break;
case V_82 :
V_76 |= 0x00030000 ;
break;
case V_83 :
V_71 += V_6 -> V_84 . V_85 ;
default:
V_76 &= ~ 0x00100000 ;
break;
}
V_32 = ( V_71 + V_32 ) - 1 ;
F_21 ( V_69 , V_70 + 0x00 , V_76 ) ;
F_21 ( V_69 , V_70 + 0x04 , F_37 ( V_32 ) ) ;
F_21 ( V_69 , V_70 + 0x08 , F_37 ( V_71 ) ) ;
F_21 ( V_69 , V_70 + 0x0c , F_38 ( V_32 ) << 24 |
F_38 ( V_71 ) ) ;
F_21 ( V_69 , V_70 + 0x10 , 0x00000000 ) ;
F_21 ( V_69 , V_70 + 0x14 , 0x00000000 ) ;
V_75 -> V_58 ( V_69 -> V_2 ) ;
}
int
F_39 ( struct V_17 * V_22 , int V_3 , T_3 V_71 , T_3 V_32 ,
int V_72 , int V_73 , T_1 type , T_1 V_74 ,
struct V_34 * * V_86 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_27 ;
V_27 = F_12 ( V_2 , V_22 , 24 , 16 , V_64 , V_86 ) ;
if ( V_27 )
return V_27 ;
F_36 ( * V_86 , 0 , V_3 , V_71 , V_32 , V_72 ,
V_73 , type , V_74 ) ;
return 0 ;
}
int
F_40 ( struct V_17 * V_22 , int V_3 , T_3 V_71 ,
T_3 V_32 , int V_73 , int V_72 ,
struct V_34 * * V_86 )
{
struct V_5 * V_6 = V_22 -> V_2 -> V_7 ;
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_34 * V_69 ;
T_1 V_76 , V_87 ;
int V_27 ;
if ( V_6 -> V_88 >= V_89 ) {
T_1 V_74 = ( V_72 == V_90 ) ? V_91 : 0 ;
T_1 type = ( V_72 == V_90 ) ? V_92 : 0 ;
return F_39 ( V_22 , V_3 , V_71 , V_32 ,
V_72 , V_73 , type , V_74 , V_86 ) ;
}
if ( V_72 == V_83 ) {
struct V_34 * V_93 = V_6 -> V_84 . V_94 ;
if ( V_6 -> V_84 . type == V_95 ) {
if ( V_71 == 0 ) {
F_20 ( V_93 , V_86 ) ;
return 0 ;
}
V_71 = F_41 ( V_2 , V_71 ) ;
V_72 = V_81 ;
} else {
V_71 += V_6 -> V_84 . V_85 ;
if ( V_6 -> V_84 . type == V_96 )
V_72 = V_82 ;
else
V_72 = V_81 ;
}
}
V_76 = V_3 ;
V_76 |= 0x00003000 ;
V_87 = 0 ;
switch ( V_72 ) {
case V_81 :
V_76 |= 0x00020000 ;
break;
case V_82 :
V_76 |= 0x00030000 ;
break;
default:
break;
}
switch ( V_73 ) {
case V_77 :
V_76 |= 0x00004000 ;
break;
case V_79 :
V_76 |= 0x00008000 ;
default:
V_87 |= 0x00000002 ;
break;
}
V_76 |= ( V_71 & 0x00000fff ) << 20 ;
V_87 |= ( V_71 & 0xfffff000 ) ;
V_27 = F_12 ( V_2 , V_22 , 16 , 16 , V_64 , & V_69 ) ;
if ( V_27 )
return V_27 ;
F_21 ( V_69 , 0x00 , V_76 ) ;
F_21 ( V_69 , 0x04 , V_32 - 1 ) ;
F_21 ( V_69 , 0x08 , V_87 ) ;
F_21 ( V_69 , 0x0c , V_87 ) ;
V_69 -> V_4 = V_97 ;
V_69 -> V_3 = V_3 ;
* V_86 = V_69 ;
return 0 ;
}
static int
F_42 ( struct V_17 * V_22 , T_1 V_98 , T_4 V_3 )
{
struct V_5 * V_6 = V_22 -> V_2 -> V_7 ;
struct V_34 * V_38 ;
int V_27 ;
V_38 = F_2 ( sizeof( * V_38 ) , V_10 ) ;
if ( ! V_38 )
return - V_11 ;
V_38 -> V_2 = V_22 -> V_2 ;
V_38 -> V_4 = V_97 ;
V_38 -> V_3 = V_3 ;
F_14 ( & V_38 -> V_42 ) ;
V_38 -> V_49 = 0x40 ;
F_15 ( & V_6 -> V_43 ) ;
F_16 ( & V_38 -> V_44 , & V_6 -> V_45 ) ;
F_17 ( & V_6 -> V_43 ) ;
V_27 = F_43 ( V_22 , V_98 , V_38 ) ;
F_20 ( NULL , & V_38 ) ;
return V_27 ;
}
int
F_44 ( struct V_17 * V_22 , T_1 V_98 , int V_3 )
{
struct V_5 * V_6 = V_22 -> V_2 -> V_7 ;
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_8 * V_9 ;
int V_27 ;
F_13 ( V_2 , L_5 , V_22 -> V_13 , V_3 ) ;
F_7 (oc, &dev_priv->classes, head) {
struct V_99 * V_100 = V_6 -> V_100 [ V_9 -> V_4 ] ;
if ( V_9 -> V_13 != V_3 )
continue;
if ( V_9 -> V_4 == V_97 )
return F_42 ( V_22 , V_98 , V_3 ) ;
if ( ! V_22 -> V_101 [ V_9 -> V_4 ] ) {
V_27 = V_100 -> V_102 ( V_22 , V_9 -> V_4 ) ;
if ( V_27 )
return V_27 ;
}
return V_100 -> V_103 ( V_22 , V_9 -> V_4 , V_98 , V_3 ) ;
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
T_2 V_71 ;
int V_27 ;
F_13 ( V_2 , L_7 , V_22 -> V_13 ) ;
V_32 = 0x2000 ;
V_71 = 0 ;
if ( V_6 -> V_88 == V_89 ) {
V_32 += 0x1400 ;
V_32 += 0x4000 ;
V_71 = 0x6000 ;
V_32 += 0x8000 ;
V_32 += 0x1000 ;
}
V_27 = F_12 ( V_2 , NULL , V_32 , 0x1000 , 0 , & V_22 -> V_40 ) ;
if ( V_27 ) {
F_45 ( V_2 , L_8 , V_27 ) ;
return V_27 ;
}
V_27 = F_47 ( & V_22 -> V_46 , V_71 , V_32 ) ;
if ( V_27 ) {
F_45 ( V_2 , L_9 , V_27 ) ;
F_20 ( NULL , & V_22 -> V_40 ) ;
return V_27 ;
}
return 0 ;
}
int
F_48 ( struct V_17 * V_22 ,
T_2 V_104 , T_2 V_105 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_34 * V_106 = NULL , * V_107 = NULL ;
int V_27 , V_41 ;
F_13 ( V_2 , L_10 , V_22 -> V_13 , V_104 , V_105 ) ;
if ( V_6 -> V_88 == V_108 ) {
struct V_109 * V_110 = V_6 -> V_111 ;
struct V_112 * V_113 ;
V_27 = F_12 ( V_2 , NULL , 4096 , 0x1000 , 0 ,
& V_22 -> V_40 ) ;
if ( V_27 )
return V_27 ;
F_49 ( V_110 , & V_22 -> V_110 , NULL ) ;
V_113 = F_50 ( & V_110 -> V_114 , struct V_112 , V_14 ) ;
F_21 ( V_22 -> V_40 , 0x0200 , F_37 ( V_113 -> V_69 -> V_50 ) ) ;
F_21 ( V_22 -> V_40 , 0x0204 , F_38 ( V_113 -> V_69 -> V_50 ) ) ;
F_21 ( V_22 -> V_40 , 0x0208 , 0xffffffff ) ;
F_21 ( V_22 -> V_40 , 0x020c , 0x000000ff ) ;
return 0 ;
}
V_27 = F_46 ( V_22 ) ;
if ( V_27 ) {
F_45 ( V_2 , L_11 ) ;
return V_27 ;
}
if ( V_6 -> V_111 ) {
T_1 V_115 = ( V_6 -> V_116 == 0x50 ) ? 0x1400 : 0x0200 ;
T_3 V_117 = V_22 -> V_40 -> V_50 + V_115 ;
T_1 V_118 = V_22 -> V_40 -> V_47 ;
if ( V_118 != ~ 0 )
V_118 += V_115 ;
V_27 = F_35 ( V_2 , V_118 , V_117 , 0x4000 ,
0 , & V_22 -> V_119 ) ;
if ( V_27 )
return V_27 ;
F_49 ( V_6 -> V_111 , & V_22 -> V_110 , V_22 -> V_119 ) ;
}
if ( V_6 -> V_88 < V_89 ) {
F_51 ( V_6 -> V_120 , & V_22 -> V_120 , NULL ) ;
} else {
struct V_34 * V_120 = NULL ;
V_27 = F_12 ( V_2 , V_22 , 0x8000 , 16 ,
V_57 , & V_120 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_52 ( V_2 , V_120 , & V_22 -> V_120 ) ;
F_20 ( NULL , & V_120 ) ;
if ( V_27 )
return V_27 ;
for ( V_41 = 0 ; V_41 < 2 ; V_41 ++ ) {
struct V_34 * V_121 = NULL ;
struct V_122 * V_123 =
& F_53 ( V_2 ) -> V_124 [ V_41 ] ;
T_3 V_70 = V_123 -> V_121 . V_125 -> V_125 . V_126 . V_48 << V_127 ;
V_27 = F_40 ( V_22 , 0x3d , V_70 , 0xfff ,
V_78 ,
V_80 , & V_121 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_43 ( V_22 , V_128 + V_41 , V_121 ) ;
F_20 ( NULL , & V_121 ) ;
if ( V_27 )
return V_27 ;
}
}
if ( V_6 -> V_88 >= V_89 ) {
V_27 = F_40 ( V_22 , V_129 ,
0 , ( 1ULL << 40 ) , V_78 ,
V_90 , & V_106 ) ;
if ( V_27 ) {
F_45 ( V_2 , L_12 , V_27 ) ;
return V_27 ;
}
} else {
V_27 = F_40 ( V_22 , V_129 ,
0 , V_6 -> V_130 ,
V_78 ,
V_80 , & V_106 ) ;
if ( V_27 ) {
F_45 ( V_2 , L_12 , V_27 ) ;
return V_27 ;
}
}
V_27 = F_43 ( V_22 , V_104 , V_106 ) ;
F_20 ( NULL , & V_106 ) ;
if ( V_27 ) {
F_45 ( V_2 , L_13 , V_27 ) ;
return V_27 ;
}
if ( V_6 -> V_88 >= V_89 ) {
V_27 = F_40 ( V_22 , V_129 ,
0 , ( 1ULL << 40 ) , V_78 ,
V_90 , & V_107 ) ;
} else {
V_27 = F_40 ( V_22 , V_129 ,
0 , V_6 -> V_84 . V_131 ,
V_78 ,
V_83 , & V_107 ) ;
}
if ( V_27 ) {
F_45 ( V_2 , L_14 , V_27 ) ;
return V_27 ;
}
V_27 = F_43 ( V_22 , V_105 , V_107 ) ;
F_20 ( NULL , & V_107 ) ;
if ( V_27 ) {
F_45 ( V_2 , L_15 , V_27 ) ;
return V_27 ;
}
return 0 ;
}
void
F_54 ( struct V_17 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
F_13 ( V_2 , L_7 , V_22 -> V_13 ) ;
F_51 ( NULL , & V_22 -> V_120 , V_22 ) ;
F_49 ( NULL , & V_22 -> V_110 , V_22 -> V_119 ) ;
F_20 ( NULL , & V_22 -> V_119 ) ;
if ( F_55 ( & V_22 -> V_46 ) )
F_56 ( & V_22 -> V_46 ) ;
F_20 ( NULL , & V_22 -> V_40 ) ;
}
int
F_57 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_34 * V_38 ;
int V_41 ;
F_7 (gpuobj, &dev_priv->gpuobj_list, list) {
if ( V_38 -> V_49 != V_56 )
continue;
V_38 -> V_132 = F_58 ( V_38 -> V_32 ) ;
if ( ! V_38 -> V_132 ) {
F_59 ( V_2 ) ;
return - V_11 ;
}
for ( V_41 = 0 ; V_41 < V_38 -> V_32 ; V_41 += 4 )
V_38 -> V_132 [ V_41 / 4 ] = F_60 ( V_38 , V_41 ) ;
}
return 0 ;
}
void
F_59 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_34 * V_38 ;
int V_41 ;
F_7 (gpuobj, &dev_priv->gpuobj_list, list) {
if ( ! V_38 -> V_132 )
continue;
for ( V_41 = 0 ; V_41 < V_38 -> V_32 ; V_41 += 4 )
F_21 ( V_38 , V_41 , V_38 -> V_132 [ V_41 / 4 ] ) ;
F_61 ( V_38 -> V_132 ) ;
V_38 -> V_132 = NULL ;
}
V_6 -> V_4 . V_37 . V_58 ( V_2 ) ;
}
int F_62 ( struct V_1 * V_2 , void * V_23 ,
struct V_133 * V_134 )
{
struct V_135 * V_136 = V_23 ;
struct V_17 * V_22 ;
int V_27 ;
if ( V_136 -> V_98 == ~ 0 )
return - V_21 ;
V_22 = F_63 ( V_2 , V_134 , V_136 -> V_137 ) ;
if ( F_64 ( V_22 ) )
return F_65 ( V_22 ) ;
if ( F_66 ( V_22 , V_136 -> V_98 ) ) {
V_27 = - V_138 ;
goto V_139;
}
V_27 = F_44 ( V_22 , V_136 -> V_98 , V_136 -> V_3 ) ;
if ( V_27 ) {
F_45 ( V_2 , L_16 ,
V_27 , V_136 -> V_137 , V_136 -> V_98 ) ;
}
V_139:
F_67 ( & V_22 ) ;
return V_27 ;
}
int F_68 ( struct V_1 * V_2 , void * V_23 ,
struct V_133 * V_134 )
{
struct V_140 * V_141 = V_23 ;
struct V_17 * V_22 ;
int V_27 ;
V_22 = F_63 ( V_2 , V_134 , V_141 -> V_137 ) ;
if ( F_64 ( V_22 ) )
return F_65 ( V_22 ) ;
F_69 ( V_22 ) ;
V_27 = F_70 ( V_22 , V_141 -> V_98 ) ;
F_67 ( & V_22 ) ;
return V_27 ;
}
T_1
F_60 ( struct V_34 * V_38 , T_1 V_70 )
{
struct V_5 * V_6 = V_38 -> V_2 -> V_7 ;
struct V_1 * V_2 = V_38 -> V_2 ;
unsigned long V_26 ;
if ( V_38 -> V_47 == ~ 0 || ! V_6 -> V_142 ) {
T_3 V_31 = V_38 -> V_50 + V_70 ;
T_1 V_71 = V_31 >> 16 ;
T_1 V_143 ;
F_10 ( & V_6 -> V_144 , V_26 ) ;
if ( V_6 -> V_59 != V_71 ) {
V_6 -> V_59 = V_71 ;
F_71 ( V_2 , 0x001700 , V_6 -> V_59 ) ;
}
V_143 = F_72 ( V_2 , 0x700000 + ( V_31 & 0xffff ) ) ;
F_11 ( & V_6 -> V_144 , V_26 ) ;
return V_143 ;
}
return F_73 ( V_2 , V_38 -> V_47 + V_70 ) ;
}
void
F_21 ( struct V_34 * V_38 , T_1 V_70 , T_1 V_143 )
{
struct V_5 * V_6 = V_38 -> V_2 -> V_7 ;
struct V_1 * V_2 = V_38 -> V_2 ;
unsigned long V_26 ;
if ( V_38 -> V_47 == ~ 0 || ! V_6 -> V_142 ) {
T_3 V_31 = V_38 -> V_50 + V_70 ;
T_1 V_71 = V_31 >> 16 ;
F_10 ( & V_6 -> V_144 , V_26 ) ;
if ( V_6 -> V_59 != V_71 ) {
V_6 -> V_59 = V_71 ;
F_71 ( V_2 , 0x001700 , V_6 -> V_59 ) ;
}
F_71 ( V_2 , 0x700000 + ( V_31 & 0xffff ) , V_143 ) ;
F_11 ( & V_6 -> V_144 , V_26 ) ;
return;
}
F_74 ( V_2 , V_38 -> V_47 + V_70 , V_143 ) ;
}
