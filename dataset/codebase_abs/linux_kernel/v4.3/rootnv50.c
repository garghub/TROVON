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
int V_14 ;
F_3 ( V_15 , L_1 , V_16 ) ;
if ( F_4 ( args -> V_12 , 0 , 0 , false ) ) {
F_3 ( V_15 , L_2 ,
args -> V_12 . V_17 ) ;
args -> V_12 . V_18 = ( V_7 & 0xffff0000 ) >> 16 ;
args -> V_12 . V_19 = ( V_7 & 0x0000ffff ) ;
args -> V_12 . V_20 = ( V_9 & 0xffff0000 ) >> 16 ;
args -> V_12 . V_21 = ( V_9 & 0x0000ffff ) ;
args -> V_12 . V_22 = ( V_10 & 0xffff0000 ) >> 16 ;
args -> V_12 . V_23 = ( V_10 & 0x0000ffff ) ;
args -> V_12 . time [ 0 ] = F_5 ( F_6 () ) ;
args -> V_12 . V_24 =
F_2 ( V_2 , 0x616340 + ( V_8 * 0x800 ) ) & 0xffff ;
args -> V_12 . time [ 1 ] = F_5 ( F_6 () ) ;
args -> V_12 . V_25 =
F_2 ( V_2 , 0x616344 + ( V_8 * 0x800 ) ) & 0xffff ;
} else
return V_14 ;
return 0 ;
}
int
F_7 ( struct V_26 * V_15 , T_2 V_27 , void * V_13 , T_2 V_16 )
{
union {
struct V_28 V_12 ;
struct V_29 V_30 ;
} * args = V_13 ;
struct V_31 * V_32 = V_31 ( V_15 ) ;
struct V_33 * V_3 = V_32 -> V_3 ;
const struct V_34 * V_35 = V_3 -> V_35 ;
struct V_36 * V_37 = NULL ;
struct V_36 * V_38 ;
T_3 type , V_39 = 0 ;
int V_8 , V_14 ;
if ( V_27 != V_40 )
return - V_41 ;
F_3 ( V_15 , L_3 , V_16 ) ;
if ( F_4 ( args -> V_12 , 0 , 0 , true ) ) {
F_3 ( V_15 , L_4 ,
args -> V_12 . V_17 , args -> V_12 . V_42 , args -> V_12 . V_8 ) ;
V_27 = args -> V_12 . V_42 ;
V_8 = args -> V_12 . V_8 ;
} else
if ( F_4 ( args -> V_30 , 1 , 1 , true ) ) {
F_3 ( V_15 , L_5
L_6 ,
args -> V_30 . V_17 , args -> V_30 . V_42 ,
args -> V_30 . V_43 , args -> V_30 . V_44 ) ;
V_27 = args -> V_30 . V_42 ;
type = args -> V_30 . V_43 ;
V_39 = args -> V_30 . V_44 ;
V_8 = F_8 ( ( V_39 >> 8 ) & 0x0f ) - 1 ;
} else
return V_14 ;
if ( V_8 < 0 || V_8 >= V_3 -> V_4 . V_8 . V_45 )
return - V_46 ;
if ( V_39 ) {
F_9 (temp, &disp->base.outp, head) {
if ( ( V_38 -> V_47 . V_43 == type ) &&
( V_38 -> V_47 . V_44 & V_39 ) == V_39 ) {
V_37 = V_38 ;
break;
}
}
if ( V_37 == NULL )
return - V_46 ;
}
switch ( V_27 ) {
case V_48 :
return V_35 -> V_8 . V_49 ( V_15 , V_3 , V_13 , V_16 , V_8 ) ;
default:
break;
}
switch ( V_27 * ! ! V_37 ) {
case V_50 :
return V_35 -> V_51 . V_52 ( V_15 , V_3 , V_13 , V_16 , V_8 , V_37 ) ;
case V_53 :
return V_35 -> V_51 . V_54 ( V_15 , V_3 , V_13 , V_16 , V_8 , V_37 ) ;
case V_55 :
return V_35 -> V_56 . V_52 ( V_15 , V_3 , V_13 , V_16 , V_8 , V_37 ) ;
case V_57 :
if ( ! V_35 -> V_56 . V_58 )
return - V_59 ;
return V_35 -> V_56 . V_58 ( V_15 , V_3 , V_13 , V_16 , V_8 , V_37 ) ;
case V_60 :
if ( ! V_35 -> V_56 . V_61 )
return - V_59 ;
return V_35 -> V_56 . V_61 ( V_15 , V_3 , V_13 , V_16 , V_8 , V_37 ) ;
case V_62 : {
union {
struct V_63 V_12 ;
} * args = V_13 ;
F_3 ( V_15 , L_7 , V_16 ) ;
if ( F_4 ( args -> V_12 , 0 , 0 , false ) ) {
F_3 ( V_15 , L_8
L_9 ,
args -> V_12 . V_17 , args -> V_12 . V_64 ) ;
V_3 -> V_56 . V_65 = args -> V_12 . V_64 ;
return 0 ;
} else
return V_14 ;
}
break;
case V_66 : {
struct V_67 * V_68 = V_67 ( V_37 ) ;
union {
struct V_69 V_12 ;
} * args = V_13 ;
F_3 ( V_15 , L_10 , V_16 ) ;
if ( F_4 ( args -> V_12 , 0 , 0 , false ) ) {
F_3 ( V_15 , L_11 ,
args -> V_12 . V_17 , args -> V_12 . V_70 ) ;
if ( args -> V_12 . V_70 == 0 ) {
F_10 ( & V_68 -> V_71 ) ;
V_68 -> V_35 -> V_72 ( V_68 , 0 ) ;
F_11 ( & V_68 -> V_73 . V_74 , 0 ) ;
return 0 ;
} else
if ( args -> V_12 . V_70 != 0 ) {
F_12 ( & V_68 -> V_4 , 0 , true ) ;
return 0 ;
}
} else
return V_14 ;
}
break;
case V_75 :
if ( ! V_35 -> V_76 . V_52 )
return - V_59 ;
return V_35 -> V_76 . V_52 ( V_15 , V_3 , V_13 , V_16 , V_8 , V_37 ) ;
default:
break;
}
return - V_41 ;
}
static int
F_13 ( const struct V_77 * V_78 ,
void * V_13 , T_2 V_16 , struct V_26 * * V_79 )
{
const struct V_80 * V_81 = V_78 -> V_82 ;
struct V_31 * V_32 = V_31 ( V_78 -> V_83 ) ;
return V_81 -> V_84 ( V_81 -> V_35 , V_81 -> V_27 , V_32 , V_81 -> V_85 ,
V_78 , V_13 , V_16 , V_79 ) ;
}
static int
F_14 ( const struct V_77 * V_78 ,
void * V_13 , T_2 V_16 , struct V_26 * * V_79 )
{
const struct V_86 * V_81 = V_78 -> V_82 ;
struct V_31 * V_32 = V_31 ( V_78 -> V_83 ) ;
return V_81 -> V_84 ( V_81 -> V_35 , V_81 -> V_27 , V_32 , V_81 -> V_85 ,
V_78 , V_13 , V_16 , V_79 ) ;
}
static int
F_15 ( struct V_26 * V_15 , int V_87 ,
struct V_77 * V_81 )
{
struct V_31 * V_32 = V_31 ( V_15 ) ;
if ( V_87 < F_16 ( V_32 -> V_35 -> V_88 ) ) {
V_81 -> V_4 = V_32 -> V_35 -> V_88 [ V_87 ] -> V_4 ;
V_81 -> V_82 = V_32 -> V_35 -> V_88 [ V_87 ] ;
V_81 -> V_84 = F_13 ;
return 0 ;
}
V_87 -= F_16 ( V_32 -> V_35 -> V_88 ) ;
if ( V_87 < F_16 ( V_32 -> V_35 -> V_89 ) ) {
V_81 -> V_4 = V_32 -> V_35 -> V_89 [ V_87 ] -> V_4 ;
V_81 -> V_82 = V_32 -> V_35 -> V_89 [ V_87 ] ;
V_81 -> V_84 = F_14 ;
return 0 ;
}
return - V_41 ;
}
static int
F_17 ( struct V_26 * V_15 , bool V_90 )
{
struct V_31 * V_32 = V_31 ( V_15 ) ;
V_32 -> V_35 -> V_91 ( V_32 ) ;
return 0 ;
}
static int
F_18 ( struct V_26 * V_15 )
{
struct V_31 * V_32 = V_31 ( V_15 ) ;
return V_32 -> V_35 -> V_92 ( V_32 ) ;
}
static void *
F_19 ( struct V_26 * V_15 )
{
struct V_31 * V_32 = V_31 ( V_15 ) ;
F_20 ( & V_32 -> V_93 ) ;
F_21 ( & V_32 -> V_94 ) ;
return V_32 ;
}
int
F_22 ( const struct V_95 * V_35 ,
struct V_96 * V_4 , const struct V_77 * V_78 ,
void * V_13 , T_2 V_16 , struct V_26 * * V_79 )
{
struct V_33 * V_3 = V_33 ( V_4 ) ;
struct V_31 * V_32 ;
struct V_1 * V_2 = V_3 -> V_4 . V_5 . V_6 . V_2 ;
int V_14 ;
if ( ! ( V_32 = F_23 ( sizeof( * V_32 ) , V_97 ) ) )
return - V_98 ;
* V_79 = & V_32 -> V_15 ;
F_24 ( & V_99 , V_78 , & V_32 -> V_15 ) ;
V_32 -> V_35 = V_35 ;
V_32 -> V_3 = V_3 ;
V_14 = F_25 ( V_3 -> V_4 . V_5 . V_6 . V_2 , 0x10000 , 0x10000 ,
false , NULL , & V_32 -> V_94 ) ;
if ( V_14 )
return V_14 ;
return F_26 ( V_2 , 0x1000 , 0 , V_32 -> V_94 , & V_32 -> V_93 ) ;
}
void
F_27 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_3 -> V_4 . V_5 . V_6 . V_2 ;
F_28 ( V_2 , 0x610024 , 0x00000000 ) ;
F_28 ( V_2 , 0x610020 , 0x00000000 ) ;
}
int
F_29 ( struct V_31 * V_32 )
{
struct V_33 * V_3 = V_32 -> V_3 ;
struct V_1 * V_2 = V_3 -> V_4 . V_5 . V_6 . V_2 ;
T_2 V_100 ;
int V_101 ;
V_100 = F_2 ( V_2 , 0x614004 ) ;
F_28 ( V_2 , 0x610184 , V_100 ) ;
for ( V_101 = 0 ; V_101 < V_3 -> V_4 . V_8 . V_45 ; V_101 ++ ) {
V_100 = F_2 ( V_2 , 0x616100 + ( V_101 * 0x800 ) ) ;
F_28 ( V_2 , 0x610190 + ( V_101 * 0x10 ) , V_100 ) ;
V_100 = F_2 ( V_2 , 0x616104 + ( V_101 * 0x800 ) ) ;
F_28 ( V_2 , 0x610194 + ( V_101 * 0x10 ) , V_100 ) ;
V_100 = F_2 ( V_2 , 0x616108 + ( V_101 * 0x800 ) ) ;
F_28 ( V_2 , 0x610198 + ( V_101 * 0x10 ) , V_100 ) ;
V_100 = F_2 ( V_2 , 0x61610c + ( V_101 * 0x800 ) ) ;
F_28 ( V_2 , 0x61019c + ( V_101 * 0x10 ) , V_100 ) ;
}
for ( V_101 = 0 ; V_101 < V_3 -> V_35 -> V_51 . V_45 ; V_101 ++ ) {
V_100 = F_2 ( V_2 , 0x61a000 + ( V_101 * 0x800 ) ) ;
F_28 ( V_2 , 0x6101d0 + ( V_101 * 0x04 ) , V_100 ) ;
}
for ( V_101 = 0 ; V_101 < V_3 -> V_35 -> V_56 . V_45 ; V_101 ++ ) {
V_100 = F_2 ( V_2 , 0x61c000 + ( V_101 * 0x800 ) ) ;
F_28 ( V_2 , 0x6101e0 + ( V_101 * 0x04 ) , V_100 ) ;
}
for ( V_101 = 0 ; V_101 < V_3 -> V_35 -> V_76 . V_45 ; V_101 ++ ) {
V_100 = F_2 ( V_2 , 0x61e000 + ( V_101 * 0x800 ) ) ;
F_28 ( V_2 , 0x6101f0 + ( V_101 * 0x04 ) , V_100 ) ;
}
if ( F_2 ( V_2 , 0x610024 ) & 0x00000100 ) {
F_28 ( V_2 , 0x610024 , 0x00000100 ) ;
F_30 ( V_2 , 0x6194e8 , 0x00000001 , 0x00000000 ) ;
if ( F_31 (device, 2000 ,
if (!(nvkm_rd32(device, 0x6194e8) & 0x00000002))
break;
) < 0 )
return - V_102 ;
}
F_28 ( V_2 , 0x610010 , ( V_32 -> V_94 -> V_103 >> 8 ) | 9 ) ;
F_28 ( V_2 , 0x61002c , 0x00000370 ) ;
F_28 ( V_2 , 0x610028 , 0x00000000 ) ;
return 0 ;
}
static int
F_32 ( struct V_96 * V_3 , const struct V_77 * V_78 ,
void * V_13 , T_2 V_16 , struct V_26 * * V_79 )
{
return F_22 ( & V_31 , V_3 , V_78 ,
V_13 , V_16 , V_79 ) ;
}
