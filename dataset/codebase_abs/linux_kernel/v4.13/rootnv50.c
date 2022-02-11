static int
F_1 ( struct V_1 * V_2 , T_1 V_3 , void * V_4 , T_1 V_5 )
{
union {
struct V_6 V_7 ;
struct V_8 V_9 ;
} * args = V_4 ;
struct V_10 * V_11 = V_10 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_13 ;
struct V_14 * V_15 , * V_16 = NULL ;
struct V_17 * V_18 ;
T_2 type , V_19 = 0 ;
int V_20 , V_21 = - V_22 ;
if ( V_3 != V_23 )
return - V_24 ;
F_2 ( V_2 , L_1 , V_5 ) ;
if ( ! ( V_21 = F_3 ( V_21 , & V_4 , & V_5 , args -> V_7 , 0 , 0 , true ) ) ) {
F_2 ( V_2 , L_2 ,
args -> V_7 . V_25 , args -> V_7 . V_26 , args -> V_7 . V_18 ) ;
V_3 = args -> V_7 . V_26 ;
V_20 = args -> V_7 . V_18 ;
} else
if ( ! ( V_21 = F_3 ( V_21 , & V_4 , & V_5 , args -> V_9 , 1 , 1 , true ) ) ) {
F_2 ( V_2 , L_3
L_4 ,
args -> V_9 . V_25 , args -> V_9 . V_26 ,
args -> V_9 . V_27 , args -> V_9 . V_28 ) ;
V_3 = args -> V_9 . V_26 ;
type = args -> V_9 . V_27 ;
V_19 = args -> V_9 . V_28 ;
V_20 = F_4 ( ( V_19 >> 8 ) & 0x0f ) - 1 ;
} else
return V_21 ;
if ( ! ( V_18 = F_5 ( & V_13 -> V_29 , V_20 ) ) )
return - V_30 ;
if ( V_19 ) {
F_6 (temp, &disp->base.outp, head) {
if ( ( V_15 -> V_31 . V_27 == type ) &&
( V_15 -> V_31 . V_28 & V_19 ) == V_19 ) {
V_16 = V_15 ;
break;
}
}
if ( V_16 == NULL )
return - V_30 ;
}
switch ( V_3 ) {
case V_32 : {
return F_7 ( V_2 , V_18 , V_4 , V_5 ) ;
}
default:
break;
}
switch ( V_3 * ! ! V_16 ) {
case V_33 : {
union {
struct V_34 V_7 ;
} * args = V_4 ;
int V_21 = - V_22 ;
if ( ! ( V_21 = F_3 ( V_21 , & V_4 , & V_5 , args -> V_7 , 0 , 0 , false ) ) ) {
V_21 = F_8 ( V_16 , V_35 ) ;
if ( V_21 == 0 ) {
args -> V_7 . V_36 = V_16 -> V_37 -> V_38 ;
args -> V_7 . V_39 = V_16 -> V_37 -> V_40 . V_39 ;
}
}
return V_21 ;
}
break;
case V_41 :
F_9 ( V_16 , V_35 ) ;
return 0 ;
case V_42 : {
union {
struct V_43 V_7 ;
} * args = V_4 ;
int V_21 = - V_22 ;
if ( ! ( V_21 = F_3 ( V_21 , & V_4 , & V_5 , args -> V_7 , 0 , 0 , false ) ) ) {
if ( args -> V_7 . V_4 & 0xfff00000 )
return - V_24 ;
V_21 = F_8 ( V_16 , V_44 ) ;
if ( V_21 )
return V_21 ;
V_21 = V_16 -> V_37 -> V_45 -> V_46 ( V_16 -> V_37 , args -> V_7 . V_4 ) ;
F_9 ( V_16 , V_44 ) ;
if ( V_21 < 0 )
return V_21 ;
args -> V_7 . V_47 = V_21 ;
return 0 ;
} else
return V_21 ;
}
break;
case V_48 : {
union {
struct V_49 V_7 ;
} * args = V_4 ;
struct V_50 * V_37 = V_16 -> V_37 ;
int V_21 = - V_22 ;
F_2 ( V_2 , L_5 , V_5 ) ;
if ( ! ( V_21 = F_3 ( V_21 , & V_4 , & V_5 , args -> V_7 , 0 , 0 , true ) ) ) {
F_2 ( V_2 , L_6 ,
args -> V_7 . V_25 ) ;
if ( V_5 > 0x60 )
return - V_51 ;
} else
return V_21 ;
if ( ! V_37 -> V_45 -> V_52 . V_53 )
return - V_54 ;
if ( V_5 && args -> V_7 . V_4 [ 0 ] ) {
if ( V_16 -> V_31 . type == V_55 )
V_37 -> V_45 -> V_56 . V_57 ( V_37 , V_20 , true ) ;
V_37 -> V_45 -> V_52 . V_53 ( V_37 , V_20 , true ) ;
V_37 -> V_45 -> V_52 . V_58 ( V_37 , V_4 , V_5 ) ;
} else {
if ( V_16 -> V_31 . type == V_55 )
V_37 -> V_45 -> V_56 . V_57 ( V_37 , V_20 , false ) ;
V_37 -> V_45 -> V_52 . V_53 ( V_37 , V_20 , false ) ;
}
return 0 ;
}
break;
case V_59 : {
union {
struct V_60 V_7 ;
} * args = V_4 ;
T_3 * V_61 , V_62 ;
T_3 * V_63 , V_64 ;
int V_21 = - V_22 ;
F_2 ( V_2 , L_7 , V_5 ) ;
if ( ! ( V_21 = F_3 ( V_21 , & V_4 , & V_5 , args -> V_7 , 0 , 0 , true ) ) ) {
F_2 ( V_2 , L_8
L_9 ,
args -> V_7 . V_25 , args -> V_7 . V_65 ,
args -> V_7 . V_66 , args -> V_7 . V_67 ) ;
if ( args -> V_7 . V_66 > 0x1f || args -> V_7 . V_67 > 0x7f )
return - V_24 ;
if ( ( args -> V_7 . V_68
+ args -> V_7 . V_69 ) > V_5 )
return - V_24 ;
else
if ( ( args -> V_7 . V_68
+ args -> V_7 . V_69 ) < V_5 )
return - V_51 ;
V_63 = V_4 ;
V_64 = args -> V_7 . V_68 ;
V_61 = V_63 + V_64 ;
V_62 = args -> V_7 . V_69 ;
} else
return V_21 ;
if ( ! V_16 -> V_37 -> V_45 -> V_70 . V_71 )
return - V_54 ;
V_16 -> V_37 -> V_45 -> V_70 . V_71 ( V_16 -> V_37 , V_20 , args -> V_7 . V_65 ,
args -> V_7 . V_66 ,
args -> V_7 . V_67 , V_63 , V_64 ,
V_61 , V_62 ) ;
return 0 ;
}
break;
case V_72 : {
union {
struct V_73 V_7 ;
} * args = V_4 ;
int V_21 = - V_22 ;
F_2 ( V_2 , L_10 , V_5 ) ;
if ( ! ( V_21 = F_3 ( V_21 , & V_4 , & V_5 , args -> V_7 , 0 , 0 , false ) ) ) {
F_2 ( V_2 , L_11
L_12 ,
args -> V_7 . V_25 , args -> V_7 . V_74 ) ;
V_13 -> V_75 . V_76 = args -> V_7 . V_74 ;
return 0 ;
} else
return V_21 ;
}
break;
case V_77 : {
struct V_78 * V_56 = V_78 ( V_16 ) ;
union {
struct V_79 V_7 ;
} * args = V_4 ;
int V_21 = - V_22 ;
F_2 ( V_2 , L_13 , V_5 ) ;
if ( ! ( V_21 = F_3 ( V_21 , & V_4 , & V_5 , args -> V_7 , 0 , 0 , false ) ) ) {
F_2 ( V_2 , L_14 ,
args -> V_7 . V_25 , args -> V_7 . V_65 ) ;
V_56 -> V_80 . V_81 = ! ! args -> V_7 . V_65 ;
return 0 ;
} else
return V_21 ;
}
break;
case V_82 : {
union {
struct V_83 V_7 ;
} * args = V_4 ;
int V_21 = - V_22 ;
F_2 ( V_2 , L_15 , V_5 ) ;
if ( ! ( V_21 = F_3 ( V_21 , & V_4 , & V_5 , args -> V_7 , 0 , 0 , false ) ) ) {
F_2 ( V_2 , L_16
L_17 ,
args -> V_7 . V_25 , args -> V_7 . V_84 ,
args -> V_7 . V_85 , args -> V_7 . V_86 ,
args -> V_7 . V_87 ) ;
if ( ! V_16 -> V_37 -> V_45 -> V_56 . V_88 )
return - V_54 ;
V_16 -> V_37 -> V_45 -> V_56 . V_88 ( V_16 -> V_37 , V_20 ,
args -> V_7 . V_84 ,
args -> V_7 . V_85 ,
args -> V_7 . V_86 ,
args -> V_7 . V_87 ) ;
return 0 ;
} else
return V_21 ;
}
break;
default:
break;
}
return - V_24 ;
}
static int
F_10 ( const struct V_89 * V_90 ,
void * V_4 , T_1 V_5 , struct V_1 * * V_91 )
{
const struct V_92 * V_93 = V_90 -> V_94 ;
struct V_10 * V_11 = V_10 ( V_90 -> V_95 ) ;
return V_93 -> V_96 ( V_93 -> V_45 , V_93 -> V_3 , V_11 , V_93 -> V_97 ,
V_90 , V_4 , V_5 , V_91 ) ;
}
static int
F_11 ( const struct V_89 * V_90 ,
void * V_4 , T_1 V_5 , struct V_1 * * V_91 )
{
const struct V_98 * V_93 = V_90 -> V_94 ;
struct V_10 * V_11 = V_10 ( V_90 -> V_95 ) ;
return V_93 -> V_96 ( V_93 -> V_45 , V_93 -> V_3 , V_11 , V_93 -> V_97 . V_71 ,
V_93 -> V_97 . V_99 , V_90 , V_4 , V_5 , V_91 ) ;
}
static int
F_12 ( struct V_1 * V_2 , int V_100 ,
struct V_89 * V_93 )
{
struct V_10 * V_11 = V_10 ( V_2 ) ;
if ( V_100 < F_13 ( V_11 -> V_45 -> V_101 ) ) {
V_93 -> V_29 = V_11 -> V_45 -> V_101 [ V_100 ] -> V_29 ;
V_93 -> V_94 = V_11 -> V_45 -> V_101 [ V_100 ] ;
V_93 -> V_96 = F_10 ;
return 0 ;
}
V_100 -= F_13 ( V_11 -> V_45 -> V_101 ) ;
if ( V_100 < F_13 ( V_11 -> V_45 -> V_102 ) ) {
V_93 -> V_29 = V_11 -> V_45 -> V_102 [ V_100 ] -> V_29 ;
V_93 -> V_94 = V_11 -> V_45 -> V_102 [ V_100 ] ;
V_93 -> V_96 = F_11 ;
return 0 ;
}
return - V_24 ;
}
static int
F_14 ( struct V_1 * V_2 , bool V_103 )
{
struct V_10 * V_11 = V_10 ( V_2 ) ;
V_11 -> V_45 -> V_104 ( V_11 ) ;
return 0 ;
}
static int
F_15 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_10 ( V_2 ) ;
struct V_50 * V_37 ;
int V_21 ;
V_21 = V_11 -> V_45 -> V_105 ( V_11 ) ;
if ( V_21 )
return V_21 ;
F_6 (ior, &root->disp->base.ior, head) {
V_37 -> V_45 -> V_106 ( V_37 , true , true , true , true , true ) ;
}
return 0 ;
}
static void *
F_16 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_10 ( V_2 ) ;
F_17 ( & V_11 -> V_107 ) ;
F_18 ( & V_11 -> V_108 ) ;
return V_11 ;
}
int
F_19 ( const struct V_109 * V_45 ,
struct V_110 * V_29 , const struct V_89 * V_90 ,
void * V_4 , T_1 V_5 , struct V_1 * * V_91 )
{
struct V_12 * V_13 = V_12 ( V_29 ) ;
struct V_10 * V_11 ;
struct V_111 * V_112 = V_13 -> V_29 . V_113 . V_114 . V_112 ;
int V_21 ;
if ( ! ( V_11 = F_20 ( sizeof( * V_11 ) , V_115 ) ) )
return - V_116 ;
* V_91 = & V_11 -> V_2 ;
F_21 ( & V_117 , V_90 , & V_11 -> V_2 ) ;
V_11 -> V_45 = V_45 ;
V_11 -> V_13 = V_13 ;
V_21 = F_22 ( V_13 -> V_29 . V_113 . V_114 . V_112 , 0x10000 , 0x10000 ,
false , NULL , & V_11 -> V_108 ) ;
if ( V_21 )
return V_21 ;
return F_23 ( V_112 , 0x1000 , 0 , V_11 -> V_108 , & V_11 -> V_107 ) ;
}
void
F_24 ( struct V_10 * V_11 )
{
struct V_111 * V_112 = V_11 -> V_13 -> V_29 . V_113 . V_114 . V_112 ;
F_25 ( V_112 , 0x610024 , 0x00000000 ) ;
F_25 ( V_112 , 0x610020 , 0x00000000 ) ;
}
int
F_26 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_13 ;
struct V_17 * V_18 ;
struct V_111 * V_112 = V_13 -> V_29 . V_113 . V_114 . V_112 ;
T_1 V_118 ;
int V_119 ;
V_118 = F_27 ( V_112 , 0x614004 ) ;
F_25 ( V_112 , 0x610184 , V_118 ) ;
F_6 (head, &disp->base.head, head) {
V_118 = F_27 ( V_112 , 0x616100 + ( V_18 -> V_38 * 0x800 ) ) ;
F_25 ( V_112 , 0x610190 + ( V_18 -> V_38 * 0x10 ) , V_118 ) ;
V_118 = F_27 ( V_112 , 0x616104 + ( V_18 -> V_38 * 0x800 ) ) ;
F_25 ( V_112 , 0x610194 + ( V_18 -> V_38 * 0x10 ) , V_118 ) ;
V_118 = F_27 ( V_112 , 0x616108 + ( V_18 -> V_38 * 0x800 ) ) ;
F_25 ( V_112 , 0x610198 + ( V_18 -> V_38 * 0x10 ) , V_118 ) ;
V_118 = F_27 ( V_112 , 0x61610c + ( V_18 -> V_38 * 0x800 ) ) ;
F_25 ( V_112 , 0x61019c + ( V_18 -> V_38 * 0x10 ) , V_118 ) ;
}
for ( V_119 = 0 ; V_119 < V_13 -> V_45 -> V_120 . V_121 ; V_119 ++ ) {
V_118 = F_27 ( V_112 , 0x61a000 + ( V_119 * 0x800 ) ) ;
F_25 ( V_112 , 0x6101d0 + ( V_119 * 0x04 ) , V_118 ) ;
}
for ( V_119 = 0 ; V_119 < V_13 -> V_45 -> V_75 . V_121 ; V_119 ++ ) {
V_118 = F_27 ( V_112 , 0x61c000 + ( V_119 * 0x800 ) ) ;
F_25 ( V_112 , 0x6101e0 + ( V_119 * 0x04 ) , V_118 ) ;
}
for ( V_119 = 0 ; V_119 < V_13 -> V_45 -> V_122 . V_121 ; V_119 ++ ) {
V_118 = F_27 ( V_112 , 0x61e000 + ( V_119 * 0x800 ) ) ;
F_25 ( V_112 , 0x6101f0 + ( V_119 * 0x04 ) , V_118 ) ;
}
if ( F_27 ( V_112 , 0x610024 ) & 0x00000100 ) {
F_25 ( V_112 , 0x610024 , 0x00000100 ) ;
F_28 ( V_112 , 0x6194e8 , 0x00000001 , 0x00000000 ) ;
if ( F_29 (device, 2000 ,
if (!(nvkm_rd32(device, 0x6194e8) & 0x00000002))
break;
) < 0 )
return - V_123 ;
}
F_25 ( V_112 , 0x610010 , ( V_11 -> V_108 -> V_124 >> 8 ) | 9 ) ;
F_25 ( V_112 , 0x61002c , 0x00000370 ) ;
F_25 ( V_112 , 0x610028 , 0x00000000 ) ;
return 0 ;
}
static int
F_30 ( struct V_110 * V_13 , const struct V_89 * V_90 ,
void * V_4 , T_1 V_5 , struct V_1 * * V_91 )
{
return F_19 ( & V_10 , V_13 , V_90 ,
V_4 , V_5 , V_91 ) ;
}
