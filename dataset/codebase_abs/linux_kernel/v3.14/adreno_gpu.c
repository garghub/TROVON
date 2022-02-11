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
default:
F_3 ( L_1 , V_2 -> V_11 , V_3 ) ;
return - V_12 ;
}
}
int F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
F_3 ( L_2 , V_2 -> V_11 ) ;
F_5 ( V_2 , V_13 ,
F_6 ( F_7 ( V_2 -> V_14 -> V_15 / 8 ) ) |
F_8 ( F_7 ( V_16 / 8 ) ) ) ;
F_5 ( V_2 , V_17 , V_2 -> V_18 ) ;
F_5 ( V_2 , V_19 , F_9 ( V_5 , V_20 ) ) ;
F_5 ( V_2 , V_21 , F_9 ( V_5 , V_22 ) ) ;
F_5 ( V_2 , V_23 , 0x1 ) ;
return 0 ;
}
static T_1 F_10 ( struct V_24 * V_25 )
{
return V_25 -> V_26 - V_25 -> V_27 ;
}
T_1 F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_28 -> V_22 ;
}
void F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_29 * V_30 = V_2 -> V_30 ;
int V_31 ;
V_2 -> V_32 -> V_33 ( V_2 ) ;
V_2 -> V_14 -> V_26 = V_2 -> V_14 -> V_27 ;
V_5 -> V_28 -> V_22 = V_2 -> V_34 ;
V_5 -> V_28 -> V_20 = 0 ;
V_5 -> V_28 -> V_35 = 0 ;
V_2 -> V_32 -> V_36 ( V_2 ) ;
V_31 = V_2 -> V_32 -> V_37 ( V_2 ) ;
if ( V_31 ) {
F_13 ( V_30 -> V_30 , L_3 , V_31 ) ;
}
}
int F_14 ( struct V_1 * V_2 , struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_42 * V_43 = V_2 -> V_30 -> V_44 ;
struct V_24 * V_25 = V_2 -> V_14 ;
unsigned V_45 , V_46 = 0 ;
for ( V_45 = 0 ; V_45 < V_39 -> V_47 ; V_45 ++ ) {
switch ( V_39 -> V_48 [ V_45 ] . type ) {
case V_49 :
break;
case V_50 :
if ( V_43 -> V_51 == V_41 )
break;
case V_52 :
F_15 ( V_25 , V_53 , 2 ) ;
F_16 ( V_25 , V_39 -> V_48 [ V_45 ] . V_54 ) ;
F_16 ( V_25 , V_39 -> V_48 [ V_45 ] . V_15 ) ;
V_46 ++ ;
break;
}
}
if ( V_46 % 2 )
F_17 ( V_25 ) ;
F_18 ( V_25 , V_55 , 1 ) ;
F_16 ( V_25 , V_39 -> V_22 ) ;
if ( F_19 ( V_5 ) ) {
F_15 ( V_25 , V_56 , 1 ) ;
F_16 ( V_25 , V_57 ) ;
F_15 ( V_25 , V_58 , 1 ) ;
F_16 ( V_25 , 0x00000000 ) ;
}
F_15 ( V_25 , V_56 , 3 ) ;
F_16 ( V_25 , V_59 ) ;
F_16 ( V_25 , F_9 ( V_5 , V_22 ) ) ;
F_16 ( V_25 , V_39 -> V_22 ) ;
F_15 ( V_25 , V_60 , 1 ) ;
F_16 ( V_25 , 0x80000000 ) ;
#if 0
if (adreno_is_a3xx(adreno_gpu)) {
OUT_PKT3(ring, CP_SET_CONSTANT, 2);
OUT_RING(ring, CP_REG(REG_A3XX_HLSQ_CL_KERNEL_GROUP_X_REG));
OUT_RING(ring, 0x00000000);
}
#endif
V_2 -> V_32 -> V_61 ( V_2 ) ;
return 0 ;
}
void F_20 ( struct V_1 * V_2 )
{
T_1 V_35 = F_10 ( V_2 -> V_14 ) ;
F_21 () ;
F_5 ( V_2 , V_62 , V_35 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
T_1 V_20 , V_35 = F_10 ( V_2 -> V_14 ) ;
unsigned long V_63 ;
V_63 = V_64 + V_65 ;
do {
V_20 = V_5 -> V_28 -> V_20 ;
if ( V_20 == V_35 )
return;
} while( F_23 ( V_64 , V_63 ) );
F_24 ( L_4 , V_2 -> V_11 ) ;
}
void F_25 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
F_26 ( V_67 , L_5 ,
V_5 -> V_7 -> V_8 , V_5 -> V_68 . V_69 ,
V_5 -> V_68 . V_70 , V_5 -> V_68 . V_71 ,
V_5 -> V_68 . V_72 ) ;
F_26 ( V_67 , L_6 , V_5 -> V_28 -> V_22 ,
V_2 -> V_34 ) ;
F_26 ( V_67 , L_7 , V_5 -> V_28 -> V_20 ) ;
F_26 ( V_67 , L_8 , V_5 -> V_28 -> V_35 ) ;
F_26 ( V_67 , L_9 , F_10 ( V_2 -> V_14 ) ) ;
}
void F_27 ( struct V_1 * V_2 , T_1 V_73 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
T_1 V_74 ;
unsigned long V_63 = V_64 + V_65 ;
do {
T_1 V_15 = V_2 -> V_14 -> V_15 / 4 ;
T_1 V_35 = F_10 ( V_2 -> V_14 ) ;
T_1 V_20 = V_5 -> V_28 -> V_20 ;
V_74 = ( V_20 + ( V_15 - 1 ) - V_35 ) % V_15 ;
if ( F_28 ( V_64 , V_63 ) ) {
F_24 ( L_10 , V_2 -> V_11 ) ;
break;
}
} while( V_74 < V_73 );
}
static inline bool F_29 ( T_3 V_75 , T_3 V_76 )
{
return ( V_75 == V_77 ) || ( V_75 == V_76 ) ;
}
int F_30 ( struct V_29 * V_78 , struct V_79 * V_80 ,
struct V_5 * V_2 , const struct V_81 * V_32 ,
struct V_82 V_68 )
{
struct V_83 * V_84 ;
int V_45 , V_31 ;
for ( V_45 = 0 ; V_45 < F_31 ( V_85 ) ; V_45 ++ ) {
const struct V_86 * V_7 = & V_85 [ V_45 ] ;
if ( F_29 ( V_7 -> V_68 . V_69 , V_68 . V_69 ) &&
F_29 ( V_7 -> V_68 . V_70 , V_68 . V_70 ) &&
F_29 ( V_7 -> V_68 . V_71 , V_68 . V_71 ) &&
F_29 ( V_7 -> V_68 . V_72 , V_68 . V_72 ) ) {
V_2 -> V_7 = V_7 ;
V_2 -> V_8 = V_7 -> V_8 ;
break;
}
}
if ( V_45 == F_31 ( V_85 ) ) {
F_13 ( V_78 -> V_30 , L_11 ,
V_68 . V_69 , V_68 . V_70 , V_68 . V_71 , V_68 . V_72 ) ;
return - V_87 ;
}
F_3 ( L_12 , V_2 -> V_7 -> V_11 ,
V_68 . V_69 , V_68 . V_70 , V_68 . V_71 , V_68 . V_72 ) ;
V_2 -> V_32 = V_32 ;
V_2 -> V_10 = V_2 -> V_7 -> V_10 ;
V_2 -> V_68 = V_68 ;
V_31 = F_32 ( & V_2 -> V_88 , V_2 -> V_7 -> V_89 , V_78 -> V_30 ) ;
if ( V_31 ) {
F_13 ( V_78 -> V_30 , L_13 ,
V_2 -> V_7 -> V_89 , V_31 ) ;
return V_31 ;
}
V_31 = F_32 ( & V_2 -> V_90 , V_2 -> V_7 -> V_91 , V_78 -> V_30 ) ;
if ( V_31 ) {
F_13 ( V_78 -> V_30 , L_14 ,
V_2 -> V_7 -> V_91 , V_31 ) ;
return V_31 ;
}
V_31 = F_33 ( V_78 , V_80 , & V_2 -> V_92 , & V_32 -> V_92 ,
V_2 -> V_7 -> V_11 , L_15 , L_16 ,
V_93 ) ;
if ( V_31 )
return V_31 ;
V_84 = V_2 -> V_92 . V_84 ;
if ( V_84 ) {
V_31 = V_84 -> V_32 -> V_94 ( V_84 , V_95 ,
F_31 ( V_95 ) ) ;
if ( V_31 )
return V_31 ;
}
V_2 -> V_96 = F_34 ( V_78 , sizeof( * V_2 -> V_28 ) ,
V_97 ) ;
if ( F_35 ( V_2 -> V_96 ) ) {
V_31 = F_36 ( V_2 -> V_96 ) ;
V_2 -> V_96 = NULL ;
F_13 ( V_78 -> V_30 , L_17 , V_31 ) ;
return V_31 ;
}
V_2 -> V_28 = F_37 ( V_2 -> V_96 ) ;
if ( ! V_2 -> V_28 ) {
F_13 ( V_78 -> V_30 , L_18 ) ;
return - V_98 ;
}
V_31 = F_38 ( V_2 -> V_96 , V_2 -> V_92 . V_76 ,
& V_2 -> V_99 ) ;
if ( V_31 ) {
F_13 ( V_78 -> V_30 , L_19 , V_31 ) ;
return V_31 ;
}
return 0 ;
}
void F_39 ( struct V_5 * V_2 )
{
if ( V_2 -> V_96 ) {
if ( V_2 -> V_99 )
F_40 ( V_2 -> V_96 , V_2 -> V_92 . V_76 ) ;
F_41 ( V_2 -> V_96 ) ;
}
if ( V_2 -> V_88 )
F_42 ( V_2 -> V_88 ) ;
if ( V_2 -> V_90 )
F_42 ( V_2 -> V_90 ) ;
F_43 ( & V_2 -> V_92 ) ;
}
