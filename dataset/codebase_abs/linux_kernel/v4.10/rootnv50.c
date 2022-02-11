int
F_1 ( T_1 )
{
struct V_1 * V_2 = V_3 -> V_4 . V_5 . V_6 . V_2 ;
const T_2 V_7 = F_2 ( V_2 , 0x610aec + ( V_8 * 0x540 ) ) ;
const T_2 V_9 = F_2 ( V_2 , 0x610af4 + ( V_8 * 0x540 ) ) ;
const T_2 V_10 = F_2 ( V_2 , 0x610afc + ( V_8 * 0x540 ) ) ;
union {
struct V_11 V_12 ;
} * args = V_13 ;
int V_14 = - V_15 ;
F_3 ( V_16 , L_1 , V_17 ) ;
if ( ! ( V_14 = F_4 ( V_14 , & V_13 , & V_17 , args -> V_12 , 0 , 0 , false ) ) ) {
F_3 ( V_16 , L_2 ,
args -> V_12 . V_18 ) ;
args -> V_12 . V_19 = ( V_7 & 0xffff0000 ) >> 16 ;
args -> V_12 . V_20 = ( V_7 & 0x0000ffff ) ;
args -> V_12 . V_21 = ( V_9 & 0xffff0000 ) >> 16 ;
args -> V_12 . V_22 = ( V_9 & 0x0000ffff ) ;
args -> V_12 . V_23 = ( V_10 & 0xffff0000 ) >> 16 ;
args -> V_12 . V_24 = ( V_10 & 0x0000ffff ) ;
args -> V_12 . time [ 0 ] = F_5 ( F_6 () ) ;
args -> V_12 . V_25 =
F_2 ( V_2 , 0x616340 + ( V_8 * 0x800 ) ) & 0xffff ;
args -> V_12 . time [ 1 ] = F_5 ( F_6 () ) ;
args -> V_12 . V_26 =
F_2 ( V_2 , 0x616344 + ( V_8 * 0x800 ) ) & 0xffff ;
} else
return V_14 ;
return 0 ;
}
static int
F_7 ( struct V_27 * V_16 , T_2 V_28 , void * V_13 , T_2 V_17 )
{
union {
struct V_29 V_12 ;
struct V_30 V_31 ;
} * args = V_13 ;
struct V_32 * V_33 = V_32 ( V_16 ) ;
struct V_34 * V_3 = V_33 -> V_3 ;
const struct V_35 * V_36 = V_3 -> V_36 ;
struct V_37 * V_38 = NULL ;
struct V_37 * V_39 ;
T_3 type , V_40 = 0 ;
int V_8 , V_14 = - V_15 ;
if ( V_28 != V_41 )
return - V_42 ;
F_3 ( V_16 , L_3 , V_17 ) ;
if ( ! ( V_14 = F_4 ( V_14 , & V_13 , & V_17 , args -> V_12 , 0 , 0 , true ) ) ) {
F_3 ( V_16 , L_4 ,
args -> V_12 . V_18 , args -> V_12 . V_43 , args -> V_12 . V_8 ) ;
V_28 = args -> V_12 . V_43 ;
V_8 = args -> V_12 . V_8 ;
} else
if ( ! ( V_14 = F_4 ( V_14 , & V_13 , & V_17 , args -> V_31 , 1 , 1 , true ) ) ) {
F_3 ( V_16 , L_5
L_6 ,
args -> V_31 . V_18 , args -> V_31 . V_43 ,
args -> V_31 . V_44 , args -> V_31 . V_45 ) ;
V_28 = args -> V_31 . V_43 ;
type = args -> V_31 . V_44 ;
V_40 = args -> V_31 . V_45 ;
V_8 = F_8 ( ( V_40 >> 8 ) & 0x0f ) - 1 ;
} else
return V_14 ;
if ( V_8 < 0 || V_8 >= V_3 -> V_4 . V_8 . V_46 )
return - V_47 ;
if ( V_40 ) {
F_9 (temp, &disp->base.outp, head) {
if ( ( V_39 -> V_48 . V_44 == type ) &&
( V_39 -> V_48 . V_45 & V_40 ) == V_40 ) {
V_38 = V_39 ;
break;
}
}
if ( V_38 == NULL )
return - V_47 ;
}
switch ( V_28 ) {
case V_49 :
return V_36 -> V_8 . V_50 ( V_16 , V_3 , V_13 , V_17 , V_8 ) ;
default:
break;
}
switch ( V_28 * ! ! V_38 ) {
case V_51 :
return V_36 -> V_52 . V_53 ( V_16 , V_3 , V_13 , V_17 , V_8 , V_38 ) ;
case V_54 :
return V_36 -> V_52 . V_55 ( V_16 , V_3 , V_13 , V_17 , V_8 , V_38 ) ;
case V_56 :
return V_36 -> V_57 . V_53 ( V_16 , V_3 , V_13 , V_17 , V_8 , V_38 ) ;
case V_58 :
if ( ! V_36 -> V_57 . V_59 )
return - V_60 ;
return V_36 -> V_57 . V_59 ( V_16 , V_3 , V_13 , V_17 , V_8 , V_38 ) ;
case V_61 :
if ( ! V_36 -> V_57 . V_62 )
return - V_60 ;
return V_36 -> V_57 . V_62 ( V_16 , V_3 , V_13 , V_17 , V_8 , V_38 ) ;
case V_63 : {
union {
struct V_64 V_12 ;
} * args = V_13 ;
int V_14 = - V_15 ;
F_3 ( V_16 , L_7 , V_17 ) ;
if ( ! ( V_14 = F_4 ( V_14 , & V_13 , & V_17 , args -> V_12 , 0 , 0 , false ) ) ) {
F_3 ( V_16 , L_8
L_9 ,
args -> V_12 . V_18 , args -> V_12 . V_65 ) ;
V_3 -> V_57 . V_66 = args -> V_12 . V_65 ;
return 0 ;
} else
return V_14 ;
}
break;
case V_67 : {
struct V_68 * V_69 = V_68 ( V_38 ) ;
union {
struct V_70 V_12 ;
} * args = V_13 ;
int V_14 = - V_15 ;
F_3 ( V_16 , L_10 , V_17 ) ;
if ( ! ( V_14 = F_4 ( V_14 , & V_13 , & V_17 , args -> V_12 , 0 , 0 , false ) ) ) {
F_3 ( V_16 , L_11 ,
args -> V_12 . V_18 , args -> V_12 . V_71 ) ;
if ( args -> V_12 . V_71 == 0 ) {
F_10 ( & V_69 -> V_72 ) ;
V_69 -> V_36 -> V_73 ( V_69 , 0 ) ;
F_11 ( & V_69 -> V_74 . V_75 , 0 ) ;
return 0 ;
} else
if ( args -> V_12 . V_71 != 0 ) {
F_12 ( & V_69 -> V_4 , 0 ) ;
return 0 ;
}
} else
return V_14 ;
}
break;
case V_76 : {
struct V_68 * V_69 = V_68 ( V_38 ) ;
union {
struct V_77 V_12 ;
} * args = V_13 ;
int V_14 = - V_15 ;
F_3 ( V_16 , L_12 , V_17 ) ;
if ( ! ( V_14 = F_4 ( V_14 , & V_13 , & V_17 , args -> V_12 , 0 , 0 , false ) ) ) {
F_3 ( V_16 , L_13 ,
args -> V_12 . V_18 , args -> V_12 . V_71 ) ;
if ( V_69 -> V_74 . V_78 != ! ! args -> V_12 . V_71 ) {
V_69 -> V_74 . V_78 = ! ! args -> V_12 . V_71 ;
F_11 ( & V_69 -> V_74 . V_75 , 0 ) ;
F_12 ( & V_69 -> V_4 , 0 ) ;
}
return 0 ;
} else
return V_14 ;
}
break;
case V_79 : {
struct V_68 * V_69 = V_68 ( V_38 ) ;
union {
struct V_80 V_12 ;
} * args = V_13 ;
int V_14 = - V_15 ;
F_3 ( V_16 , L_14 , V_17 ) ;
if ( ! ( V_14 = F_4 ( V_14 , & V_13 , & V_17 , args -> V_12 , 0 , 0 , false ) ) ) {
F_3 ( V_16 , L_15
L_16 ,
args -> V_12 . V_18 , args -> V_12 . V_81 ,
args -> V_12 . V_82 , args -> V_12 . V_83 ,
args -> V_12 . V_84 ) ;
if ( ! V_69 -> V_36 -> V_85 )
return - V_60 ;
V_69 -> V_36 -> V_85 ( V_69 , V_8 , args -> V_12 . V_81 ,
args -> V_12 . V_82 , args -> V_12 . V_83 ,
args -> V_12 . V_84 ) ;
return 0 ;
} else
return V_14 ;
}
break;
case V_86 :
if ( ! V_36 -> V_87 . V_53 )
return - V_60 ;
return V_36 -> V_87 . V_53 ( V_16 , V_3 , V_13 , V_17 , V_8 , V_38 ) ;
default:
break;
}
return - V_42 ;
}
static int
F_13 ( const struct V_88 * V_89 ,
void * V_13 , T_2 V_17 , struct V_27 * * V_90 )
{
const struct V_91 * V_92 = V_89 -> V_93 ;
struct V_32 * V_33 = V_32 ( V_89 -> V_94 ) ;
return V_92 -> V_95 ( V_92 -> V_36 , V_92 -> V_28 , V_33 , V_92 -> V_96 ,
V_89 , V_13 , V_17 , V_90 ) ;
}
static int
F_14 ( const struct V_88 * V_89 ,
void * V_13 , T_2 V_17 , struct V_27 * * V_90 )
{
const struct V_97 * V_92 = V_89 -> V_93 ;
struct V_32 * V_33 = V_32 ( V_89 -> V_94 ) ;
return V_92 -> V_95 ( V_92 -> V_36 , V_92 -> V_28 , V_33 , V_92 -> V_96 . V_98 ,
V_92 -> V_96 . V_99 , V_89 , V_13 , V_17 , V_90 ) ;
}
static int
F_15 ( struct V_27 * V_16 , int V_100 ,
struct V_88 * V_92 )
{
struct V_32 * V_33 = V_32 ( V_16 ) ;
if ( V_100 < F_16 ( V_33 -> V_36 -> V_101 ) ) {
V_92 -> V_4 = V_33 -> V_36 -> V_101 [ V_100 ] -> V_4 ;
V_92 -> V_93 = V_33 -> V_36 -> V_101 [ V_100 ] ;
V_92 -> V_95 = F_13 ;
return 0 ;
}
V_100 -= F_16 ( V_33 -> V_36 -> V_101 ) ;
if ( V_100 < F_16 ( V_33 -> V_36 -> V_102 ) ) {
V_92 -> V_4 = V_33 -> V_36 -> V_102 [ V_100 ] -> V_4 ;
V_92 -> V_93 = V_33 -> V_36 -> V_102 [ V_100 ] ;
V_92 -> V_95 = F_14 ;
return 0 ;
}
return - V_42 ;
}
static int
F_17 ( struct V_27 * V_16 , bool V_103 )
{
struct V_32 * V_33 = V_32 ( V_16 ) ;
V_33 -> V_36 -> V_104 ( V_33 ) ;
return 0 ;
}
static int
F_18 ( struct V_27 * V_16 )
{
struct V_32 * V_33 = V_32 ( V_16 ) ;
return V_33 -> V_36 -> V_105 ( V_33 ) ;
}
static void *
F_19 ( struct V_27 * V_16 )
{
struct V_32 * V_33 = V_32 ( V_16 ) ;
F_20 ( & V_33 -> V_106 ) ;
F_21 ( & V_33 -> V_107 ) ;
return V_33 ;
}
int
F_22 ( const struct V_108 * V_36 ,
struct V_109 * V_4 , const struct V_88 * V_89 ,
void * V_13 , T_2 V_17 , struct V_27 * * V_90 )
{
struct V_34 * V_3 = V_34 ( V_4 ) ;
struct V_32 * V_33 ;
struct V_1 * V_2 = V_3 -> V_4 . V_5 . V_6 . V_2 ;
int V_14 ;
if ( ! ( V_33 = F_23 ( sizeof( * V_33 ) , V_110 ) ) )
return - V_111 ;
* V_90 = & V_33 -> V_16 ;
F_24 ( & V_112 , V_89 , & V_33 -> V_16 ) ;
V_33 -> V_36 = V_36 ;
V_33 -> V_3 = V_3 ;
V_14 = F_25 ( V_3 -> V_4 . V_5 . V_6 . V_2 , 0x10000 , 0x10000 ,
false , NULL , & V_33 -> V_107 ) ;
if ( V_14 )
return V_14 ;
return F_26 ( V_2 , 0x1000 , 0 , V_33 -> V_107 , & V_33 -> V_106 ) ;
}
void
F_27 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_3 -> V_4 . V_5 . V_6 . V_2 ;
F_28 ( V_2 , 0x610024 , 0x00000000 ) ;
F_28 ( V_2 , 0x610020 , 0x00000000 ) ;
}
int
F_29 ( struct V_32 * V_33 )
{
struct V_34 * V_3 = V_33 -> V_3 ;
struct V_1 * V_2 = V_3 -> V_4 . V_5 . V_6 . V_2 ;
T_2 V_113 ;
int V_114 ;
V_113 = F_2 ( V_2 , 0x614004 ) ;
F_28 ( V_2 , 0x610184 , V_113 ) ;
for ( V_114 = 0 ; V_114 < V_3 -> V_4 . V_8 . V_46 ; V_114 ++ ) {
V_113 = F_2 ( V_2 , 0x616100 + ( V_114 * 0x800 ) ) ;
F_28 ( V_2 , 0x610190 + ( V_114 * 0x10 ) , V_113 ) ;
V_113 = F_2 ( V_2 , 0x616104 + ( V_114 * 0x800 ) ) ;
F_28 ( V_2 , 0x610194 + ( V_114 * 0x10 ) , V_113 ) ;
V_113 = F_2 ( V_2 , 0x616108 + ( V_114 * 0x800 ) ) ;
F_28 ( V_2 , 0x610198 + ( V_114 * 0x10 ) , V_113 ) ;
V_113 = F_2 ( V_2 , 0x61610c + ( V_114 * 0x800 ) ) ;
F_28 ( V_2 , 0x61019c + ( V_114 * 0x10 ) , V_113 ) ;
}
for ( V_114 = 0 ; V_114 < V_3 -> V_36 -> V_52 . V_46 ; V_114 ++ ) {
V_113 = F_2 ( V_2 , 0x61a000 + ( V_114 * 0x800 ) ) ;
F_28 ( V_2 , 0x6101d0 + ( V_114 * 0x04 ) , V_113 ) ;
}
for ( V_114 = 0 ; V_114 < V_3 -> V_36 -> V_57 . V_46 ; V_114 ++ ) {
V_113 = F_2 ( V_2 , 0x61c000 + ( V_114 * 0x800 ) ) ;
F_28 ( V_2 , 0x6101e0 + ( V_114 * 0x04 ) , V_113 ) ;
}
for ( V_114 = 0 ; V_114 < V_3 -> V_36 -> V_87 . V_46 ; V_114 ++ ) {
V_113 = F_2 ( V_2 , 0x61e000 + ( V_114 * 0x800 ) ) ;
F_28 ( V_2 , 0x6101f0 + ( V_114 * 0x04 ) , V_113 ) ;
}
if ( F_2 ( V_2 , 0x610024 ) & 0x00000100 ) {
F_28 ( V_2 , 0x610024 , 0x00000100 ) ;
F_30 ( V_2 , 0x6194e8 , 0x00000001 , 0x00000000 ) ;
if ( F_31 (device, 2000 ,
if (!(nvkm_rd32(device, 0x6194e8) & 0x00000002))
break;
) < 0 )
return - V_115 ;
}
F_28 ( V_2 , 0x610010 , ( V_33 -> V_107 -> V_116 >> 8 ) | 9 ) ;
F_28 ( V_2 , 0x61002c , 0x00000370 ) ;
F_28 ( V_2 , 0x610028 , 0x00000000 ) ;
return 0 ;
}
static int
F_32 ( struct V_109 * V_3 , const struct V_88 * V_89 ,
void * V_13 , T_2 V_17 , struct V_27 * * V_90 )
{
return F_22 ( & V_32 , V_3 , V_89 ,
V_13 , V_17 , V_90 ) ;
}
