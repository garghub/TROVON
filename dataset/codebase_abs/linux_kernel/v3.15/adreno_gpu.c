int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
switch ( V_3 ) {
case V_6 :
* V_4 = V_5 -> V_7 -> V_8 ;
return 0 ;
case V_9 :
* V_4 = V_5 -> V_10 ;
return 0 ;
case V_11 :
* V_4 = V_5 -> V_12 . V_13 |
( V_5 -> V_12 . V_14 << 8 ) |
( V_5 -> V_12 . V_15 << 16 ) |
( V_5 -> V_12 . V_16 << 24 ) ;
return 0 ;
default:
F_3 ( L_1 , V_2 -> V_17 , V_3 ) ;
return - V_18 ;
}
}
int F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
F_3 ( L_2 , V_2 -> V_17 ) ;
F_5 ( V_2 , V_19 ,
F_6 ( F_7 ( V_2 -> V_20 -> V_21 / 8 ) ) |
F_8 ( F_7 ( V_22 / 8 ) ) ) ;
F_5 ( V_2 , V_23 , V_2 -> V_24 ) ;
F_5 ( V_2 , V_25 , F_9 ( V_5 , V_26 ) ) ;
F_5 ( V_2 , V_27 , F_9 ( V_5 , V_28 ) ) ;
F_5 ( V_2 , V_29 , 0x1 ) ;
return 0 ;
}
static T_1 F_10 ( struct V_30 * V_31 )
{
return V_31 -> V_32 - V_31 -> V_33 ;
}
T_1 F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_34 -> V_28 ;
}
void F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_35 * V_36 = V_2 -> V_36 ;
int V_37 ;
V_2 -> V_38 -> V_39 ( V_2 ) ;
V_2 -> V_20 -> V_32 = V_2 -> V_20 -> V_33 ;
V_5 -> V_34 -> V_28 = V_2 -> V_40 ;
V_5 -> V_34 -> V_26 = 0 ;
V_5 -> V_34 -> V_41 = 0 ;
V_2 -> V_38 -> V_42 ( V_2 ) ;
V_37 = V_2 -> V_38 -> V_43 ( V_2 ) ;
if ( V_37 ) {
F_13 ( V_36 -> V_36 , L_3 , V_37 ) ;
}
}
int F_14 ( struct V_1 * V_2 , struct V_44 * V_45 ,
struct V_46 * V_47 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_48 * V_49 = V_2 -> V_36 -> V_50 ;
struct V_30 * V_31 = V_2 -> V_20 ;
unsigned V_51 , V_52 = 0 ;
for ( V_51 = 0 ; V_51 < V_45 -> V_53 ; V_51 ++ ) {
switch ( V_45 -> V_54 [ V_51 ] . type ) {
case V_55 :
break;
case V_56 :
if ( V_49 -> V_57 == V_47 )
break;
case V_58 :
F_15 ( V_31 , V_59 , 2 ) ;
F_16 ( V_31 , V_45 -> V_54 [ V_51 ] . V_60 ) ;
F_16 ( V_31 , V_45 -> V_54 [ V_51 ] . V_21 ) ;
V_52 ++ ;
break;
}
}
if ( V_52 % 2 )
F_17 ( V_31 ) ;
F_18 ( V_31 , V_61 , 1 ) ;
F_16 ( V_31 , V_45 -> V_28 ) ;
if ( F_19 ( V_5 ) ) {
F_15 ( V_31 , V_62 , 1 ) ;
F_16 ( V_31 , V_63 ) ;
F_15 ( V_31 , V_64 , 1 ) ;
F_16 ( V_31 , 0x00000000 ) ;
}
F_15 ( V_31 , V_62 , 3 ) ;
F_16 ( V_31 , V_65 ) ;
F_16 ( V_31 , F_9 ( V_5 , V_28 ) ) ;
F_16 ( V_31 , V_45 -> V_28 ) ;
F_15 ( V_31 , V_66 , 1 ) ;
F_16 ( V_31 , 0x80000000 ) ;
#if 0
if (adreno_is_a3xx(adreno_gpu)) {
OUT_PKT3(ring, CP_SET_CONSTANT, 2);
OUT_RING(ring, CP_REG(REG_A3XX_HLSQ_CL_KERNEL_GROUP_X_REG));
OUT_RING(ring, 0x00000000);
}
#endif
V_2 -> V_38 -> V_67 ( V_2 ) ;
return 0 ;
}
void F_20 ( struct V_1 * V_2 )
{
T_1 V_41 = F_10 ( V_2 -> V_20 ) ;
F_21 () ;
F_5 ( V_2 , V_68 , V_41 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
T_1 V_41 = F_10 ( V_2 -> V_20 ) ;
if ( F_23 ( V_5 -> V_34 -> V_26 == V_41 ) )
F_24 ( L_4 , V_2 -> V_17 ) ;
}
void F_25 ( struct V_1 * V_2 , struct V_69 * V_70 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
F_26 ( V_70 , L_5 ,
V_5 -> V_7 -> V_8 , V_5 -> V_12 . V_16 ,
V_5 -> V_12 . V_15 , V_5 -> V_12 . V_14 ,
V_5 -> V_12 . V_13 ) ;
F_26 ( V_70 , L_6 , V_5 -> V_34 -> V_28 ,
V_2 -> V_40 ) ;
F_26 ( V_70 , L_7 , V_5 -> V_34 -> V_26 ) ;
F_26 ( V_70 , L_8 , V_5 -> V_34 -> V_41 ) ;
F_26 ( V_70 , L_9 , F_10 ( V_2 -> V_20 ) ) ;
}
void F_27 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
F_28 ( L_5 ,
V_5 -> V_7 -> V_8 , V_5 -> V_12 . V_16 ,
V_5 -> V_12 . V_15 , V_5 -> V_12 . V_14 ,
V_5 -> V_12 . V_13 ) ;
F_28 ( L_6 , V_5 -> V_34 -> V_28 ,
V_2 -> V_40 ) ;
F_28 ( L_7 , V_5 -> V_34 -> V_26 ) ;
F_28 ( L_8 , V_5 -> V_34 -> V_41 ) ;
F_28 ( L_9 , F_10 ( V_2 -> V_20 ) ) ;
}
static T_1 F_29 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
T_1 V_21 = V_2 -> V_20 -> V_21 / 4 ;
T_1 V_41 = F_10 ( V_2 -> V_20 ) ;
T_1 V_26 = V_5 -> V_34 -> V_26 ;
return ( V_26 + ( V_21 - 1 ) - V_41 ) % V_21 ;
}
void F_30 ( struct V_1 * V_2 , T_1 V_71 )
{
if ( F_23 ( F_29 ( V_2 ) >= V_71 ) )
F_24 ( L_10 , V_2 -> V_17 ) ;
}
static inline bool F_31 ( T_3 V_72 , T_3 V_73 )
{
return ( V_72 == V_74 ) || ( V_72 == V_73 ) ;
}
int F_32 ( struct V_35 * V_75 , struct V_76 * V_77 ,
struct V_5 * V_2 , const struct V_78 * V_38 ,
struct V_79 V_12 )
{
struct V_80 * V_81 ;
int V_51 , V_37 ;
for ( V_51 = 0 ; V_51 < F_33 ( V_82 ) ; V_51 ++ ) {
const struct V_83 * V_7 = & V_82 [ V_51 ] ;
if ( F_31 ( V_7 -> V_12 . V_16 , V_12 . V_16 ) &&
F_31 ( V_7 -> V_12 . V_15 , V_12 . V_15 ) &&
F_31 ( V_7 -> V_12 . V_14 , V_12 . V_14 ) &&
F_31 ( V_7 -> V_12 . V_13 , V_12 . V_13 ) ) {
V_2 -> V_7 = V_7 ;
V_2 -> V_8 = V_7 -> V_8 ;
break;
}
}
if ( V_51 == F_33 ( V_82 ) ) {
F_13 ( V_75 -> V_36 , L_11 ,
V_12 . V_16 , V_12 . V_15 , V_12 . V_14 , V_12 . V_13 ) ;
return - V_84 ;
}
F_3 ( L_12 , V_2 -> V_7 -> V_17 ,
V_12 . V_16 , V_12 . V_15 , V_12 . V_14 , V_12 . V_13 ) ;
V_2 -> V_38 = V_38 ;
V_2 -> V_10 = V_2 -> V_7 -> V_10 ;
V_2 -> V_12 = V_12 ;
V_37 = F_34 ( & V_2 -> V_85 , V_2 -> V_7 -> V_86 , V_75 -> V_36 ) ;
if ( V_37 ) {
F_13 ( V_75 -> V_36 , L_13 ,
V_2 -> V_7 -> V_86 , V_37 ) ;
return V_37 ;
}
V_37 = F_34 ( & V_2 -> V_87 , V_2 -> V_7 -> V_88 , V_75 -> V_36 ) ;
if ( V_37 ) {
F_13 ( V_75 -> V_36 , L_14 ,
V_2 -> V_7 -> V_88 , V_37 ) ;
return V_37 ;
}
V_37 = F_35 ( V_75 , V_77 , & V_2 -> V_89 , & V_38 -> V_89 ,
V_2 -> V_7 -> V_17 , L_15 , L_16 ,
V_90 ) ;
if ( V_37 )
return V_37 ;
V_81 = V_2 -> V_89 . V_81 ;
if ( V_81 ) {
V_37 = V_81 -> V_38 -> V_91 ( V_81 , V_92 ,
F_33 ( V_92 ) ) ;
if ( V_37 )
return V_37 ;
}
V_2 -> V_93 = F_36 ( V_75 , sizeof( * V_2 -> V_34 ) ,
V_94 ) ;
if ( F_37 ( V_2 -> V_93 ) ) {
V_37 = F_38 ( V_2 -> V_93 ) ;
V_2 -> V_93 = NULL ;
F_13 ( V_75 -> V_36 , L_17 , V_37 ) ;
return V_37 ;
}
V_2 -> V_34 = F_39 ( V_2 -> V_93 ) ;
if ( ! V_2 -> V_34 ) {
F_13 ( V_75 -> V_36 , L_18 ) ;
return - V_95 ;
}
V_37 = F_40 ( V_2 -> V_93 , V_2 -> V_89 . V_73 ,
& V_2 -> V_96 ) ;
if ( V_37 ) {
F_13 ( V_75 -> V_36 , L_19 , V_37 ) ;
return V_37 ;
}
return 0 ;
}
void F_41 ( struct V_5 * V_2 )
{
if ( V_2 -> V_93 ) {
if ( V_2 -> V_96 )
F_42 ( V_2 -> V_93 , V_2 -> V_89 . V_73 ) ;
F_43 ( V_2 -> V_93 ) ;
}
if ( V_2 -> V_85 )
F_44 ( V_2 -> V_85 ) ;
if ( V_2 -> V_87 )
F_44 ( V_2 -> V_87 ) ;
F_45 ( & V_2 -> V_89 ) ;
}
