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
int V_19 ;
F_3 ( L_2 , V_2 -> V_17 ) ;
V_19 = F_5 ( V_2 -> V_20 -> V_21 , V_2 -> V_22 , & V_2 -> V_23 ) ;
if ( V_19 ) {
V_2 -> V_23 = 0 ;
F_6 ( V_2 -> V_24 -> V_24 , L_3 , V_19 ) ;
return V_19 ;
}
F_7 ( V_2 , V_25 ,
F_8 ( F_9 ( V_2 -> V_20 -> V_26 / 8 ) ) |
F_10 ( F_9 ( V_27 / 8 ) ) ) ;
F_7 ( V_2 , V_28 , V_2 -> V_23 ) ;
F_7 ( V_2 , V_29 , F_11 ( V_5 , V_30 ) ) ;
F_7 ( V_2 , V_31 , F_11 ( V_5 , V_32 ) ) ;
F_7 ( V_2 , V_33 , 0x1 ) ;
return 0 ;
}
static T_1 F_12 ( struct V_34 * V_35 )
{
return V_35 -> V_36 - V_35 -> V_37 ;
}
T_1 F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_38 -> V_32 ;
}
void F_14 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_39 * V_24 = V_2 -> V_24 ;
int V_19 ;
V_2 -> V_40 -> V_41 ( V_2 ) ;
V_2 -> V_20 -> V_36 = V_2 -> V_20 -> V_37 ;
V_5 -> V_38 -> V_32 = V_2 -> V_42 ;
V_5 -> V_38 -> V_30 = 0 ;
V_5 -> V_38 -> V_43 = 0 ;
V_2 -> V_40 -> V_44 ( V_2 ) ;
V_19 = V_2 -> V_40 -> V_45 ( V_2 ) ;
if ( V_19 ) {
F_6 ( V_24 -> V_24 , L_4 , V_19 ) ;
}
}
int F_15 ( struct V_1 * V_2 , struct V_46 * V_47 ,
struct V_48 * V_49 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_50 * V_51 = V_2 -> V_24 -> V_52 ;
struct V_34 * V_35 = V_2 -> V_20 ;
unsigned V_53 , V_54 = 0 ;
for ( V_53 = 0 ; V_53 < V_47 -> V_55 ; V_53 ++ ) {
switch ( V_47 -> V_56 [ V_53 ] . type ) {
case V_57 :
break;
case V_58 :
if ( V_51 -> V_59 == V_49 )
break;
case V_60 :
F_16 ( V_35 , V_61 , 2 ) ;
F_17 ( V_35 , V_47 -> V_56 [ V_53 ] . V_62 ) ;
F_17 ( V_35 , V_47 -> V_56 [ V_53 ] . V_26 ) ;
V_54 ++ ;
break;
}
}
if ( V_54 % 2 )
F_18 ( V_35 ) ;
F_19 ( V_35 , V_63 , 1 ) ;
F_17 ( V_35 , V_47 -> V_32 ) ;
if ( F_20 ( V_5 ) ) {
F_16 ( V_35 , V_64 , 1 ) ;
F_17 ( V_35 , V_65 ) ;
F_16 ( V_35 , V_66 , 1 ) ;
F_17 ( V_35 , 0x00000000 ) ;
}
F_16 ( V_35 , V_64 , 3 ) ;
F_17 ( V_35 , V_67 ) ;
F_17 ( V_35 , F_11 ( V_5 , V_32 ) ) ;
F_17 ( V_35 , V_47 -> V_32 ) ;
F_16 ( V_35 , V_68 , 1 ) ;
F_17 ( V_35 , 0x80000000 ) ;
#if 0
if (adreno_is_a3xx(adreno_gpu)) {
OUT_PKT3(ring, CP_SET_CONSTANT, 2);
OUT_RING(ring, CP_REG(REG_A3XX_HLSQ_CL_KERNEL_GROUP_X_REG));
OUT_RING(ring, 0x00000000);
}
#endif
V_2 -> V_40 -> V_69 ( V_2 ) ;
return 0 ;
}
void F_21 ( struct V_1 * V_2 )
{
T_1 V_43 = F_12 ( V_2 -> V_20 ) ;
F_22 () ;
F_7 ( V_2 , V_70 , V_43 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
T_1 V_43 = F_12 ( V_2 -> V_20 ) ;
if ( F_24 ( V_5 -> V_38 -> V_30 == V_43 ) )
F_25 ( L_5 , V_2 -> V_17 ) ;
}
void F_26 ( struct V_1 * V_2 , struct V_71 * V_72 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
F_27 ( V_72 , L_6 ,
V_5 -> V_7 -> V_8 , V_5 -> V_12 . V_16 ,
V_5 -> V_12 . V_15 , V_5 -> V_12 . V_14 ,
V_5 -> V_12 . V_13 ) ;
F_27 ( V_72 , L_7 , V_5 -> V_38 -> V_32 ,
V_2 -> V_42 ) ;
F_27 ( V_72 , L_8 , V_5 -> V_38 -> V_30 ) ;
F_27 ( V_72 , L_9 , V_5 -> V_38 -> V_43 ) ;
F_27 ( V_72 , L_10 , F_12 ( V_2 -> V_20 ) ) ;
}
void F_28 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
F_29 ( L_6 ,
V_5 -> V_7 -> V_8 , V_5 -> V_12 . V_16 ,
V_5 -> V_12 . V_15 , V_5 -> V_12 . V_14 ,
V_5 -> V_12 . V_13 ) ;
F_29 ( L_7 , V_5 -> V_38 -> V_32 ,
V_2 -> V_42 ) ;
F_29 ( L_8 , V_5 -> V_38 -> V_30 ) ;
F_29 ( L_9 , V_5 -> V_38 -> V_43 ) ;
F_29 ( L_10 , F_12 ( V_2 -> V_20 ) ) ;
}
static T_1 F_30 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
T_1 V_26 = V_2 -> V_20 -> V_26 / 4 ;
T_1 V_43 = F_12 ( V_2 -> V_20 ) ;
T_1 V_30 = V_5 -> V_38 -> V_30 ;
return ( V_30 + ( V_26 - 1 ) - V_43 ) % V_26 ;
}
void F_31 ( struct V_1 * V_2 , T_1 V_73 )
{
if ( F_24 ( F_30 ( V_2 ) >= V_73 ) )
F_25 ( L_11 , V_2 -> V_17 ) ;
}
static inline bool F_32 ( T_3 V_74 , T_3 V_22 )
{
return ( V_74 == V_75 ) || ( V_74 == V_22 ) ;
}
int F_33 ( struct V_39 * V_76 , struct V_77 * V_78 ,
struct V_5 * V_2 , const struct V_79 * V_40 ,
struct V_80 V_12 )
{
struct V_81 * V_82 ;
int V_53 , V_19 ;
for ( V_53 = 0 ; V_53 < F_34 ( V_83 ) ; V_53 ++ ) {
const struct V_84 * V_7 = & V_83 [ V_53 ] ;
if ( F_32 ( V_7 -> V_12 . V_16 , V_12 . V_16 ) &&
F_32 ( V_7 -> V_12 . V_15 , V_12 . V_15 ) &&
F_32 ( V_7 -> V_12 . V_14 , V_12 . V_14 ) &&
F_32 ( V_7 -> V_12 . V_13 , V_12 . V_13 ) ) {
V_2 -> V_7 = V_7 ;
V_2 -> V_8 = V_7 -> V_8 ;
break;
}
}
if ( V_53 == F_34 ( V_83 ) ) {
F_6 ( V_76 -> V_24 , L_12 ,
V_12 . V_16 , V_12 . V_15 , V_12 . V_14 , V_12 . V_13 ) ;
return - V_85 ;
}
F_3 ( L_13 , V_2 -> V_7 -> V_17 ,
V_12 . V_16 , V_12 . V_15 , V_12 . V_14 , V_12 . V_13 ) ;
V_2 -> V_40 = V_40 ;
V_2 -> V_10 = V_2 -> V_7 -> V_10 ;
V_2 -> V_12 = V_12 ;
V_19 = F_35 ( & V_2 -> V_86 , V_2 -> V_7 -> V_87 , V_76 -> V_24 ) ;
if ( V_19 ) {
F_6 ( V_76 -> V_24 , L_14 ,
V_2 -> V_7 -> V_87 , V_19 ) ;
return V_19 ;
}
V_19 = F_35 ( & V_2 -> V_88 , V_2 -> V_7 -> V_89 , V_76 -> V_24 ) ;
if ( V_19 ) {
F_6 ( V_76 -> V_24 , L_15 ,
V_2 -> V_7 -> V_89 , V_19 ) ;
return V_19 ;
}
V_19 = F_36 ( V_76 , V_78 , & V_2 -> V_90 , & V_40 -> V_90 ,
V_2 -> V_7 -> V_17 , L_16 , L_17 ,
V_91 ) ;
if ( V_19 )
return V_19 ;
V_82 = V_2 -> V_90 . V_82 ;
if ( V_82 ) {
V_19 = V_82 -> V_40 -> V_92 ( V_82 , V_93 ,
F_34 ( V_93 ) ) ;
if ( V_19 )
return V_19 ;
}
F_37 ( & V_76 -> V_94 ) ;
V_2 -> V_95 = F_38 ( V_76 , sizeof( * V_2 -> V_38 ) ,
V_96 ) ;
F_39 ( & V_76 -> V_94 ) ;
if ( F_40 ( V_2 -> V_95 ) ) {
V_19 = F_41 ( V_2 -> V_95 ) ;
V_2 -> V_95 = NULL ;
F_6 ( V_76 -> V_24 , L_18 , V_19 ) ;
return V_19 ;
}
V_2 -> V_38 = F_42 ( V_2 -> V_95 ) ;
if ( ! V_2 -> V_38 ) {
F_6 ( V_76 -> V_24 , L_19 ) ;
return - V_97 ;
}
V_19 = F_5 ( V_2 -> V_95 , V_2 -> V_90 . V_22 ,
& V_2 -> V_98 ) ;
if ( V_19 ) {
F_6 ( V_76 -> V_24 , L_20 , V_19 ) ;
return V_19 ;
}
return 0 ;
}
void F_43 ( struct V_5 * V_2 )
{
if ( V_2 -> V_95 ) {
if ( V_2 -> V_98 )
F_44 ( V_2 -> V_95 , V_2 -> V_90 . V_22 ) ;
F_45 ( V_2 -> V_95 ) ;
}
if ( V_2 -> V_86 )
F_46 ( V_2 -> V_86 ) ;
if ( V_2 -> V_88 )
F_46 ( V_2 -> V_88 ) ;
F_47 ( & V_2 -> V_90 ) ;
}
