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
case V_17 :
* V_4 = V_5 -> V_18 . V_19 ;
return 0 ;
case V_20 :
if ( V_5 -> V_21 -> V_22 )
return V_5 -> V_21 -> V_22 ( V_2 , V_4 ) ;
return - V_23 ;
default:
F_3 ( L_1 , V_2 -> V_24 , V_3 ) ;
return - V_23 ;
}
}
int F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
int V_25 ;
F_3 ( L_2 , V_2 -> V_24 ) ;
V_25 = F_5 ( V_2 -> V_26 -> V_27 , V_2 -> V_28 , & V_2 -> V_29 ) ;
if ( V_25 ) {
V_2 -> V_29 = 0 ;
F_6 ( V_2 -> V_30 -> V_30 , L_3 , V_25 ) ;
return V_25 ;
}
F_7 ( V_5 , V_31 ,
F_8 ( F_9 ( V_2 -> V_26 -> V_32 / 8 ) ) |
F_10 ( F_9 ( V_33 / 8 ) ) |
( F_11 ( V_5 ) ? V_34 : 0 ) ) ;
F_7 ( V_5 , V_35 , V_2 -> V_29 ) ;
if ( ! F_11 ( V_5 ) )
F_7 ( V_5 , V_36 ,
F_12 ( V_5 , V_37 ) ) ;
return 0 ;
}
static T_1 F_13 ( struct V_38 * V_39 )
{
return V_39 -> V_40 - V_39 -> V_41 ;
}
static T_1 F_14 ( struct V_5 * V_5 )
{
if ( F_11 ( V_5 ) )
return V_5 -> V_42 -> V_37 = F_15 (
V_5 , V_43 ) ;
else
return V_5 -> V_42 -> V_37 ;
}
T_1 F_16 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_42 -> V_44 ;
}
void F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_45 * V_30 = V_2 -> V_30 ;
int V_25 ;
V_2 -> V_21 -> V_46 ( V_2 ) ;
V_2 -> V_26 -> V_40 = V_2 -> V_26 -> V_41 ;
V_5 -> V_42 -> V_44 = V_2 -> V_47 ;
V_5 -> V_42 -> V_37 = 0 ;
V_5 -> V_42 -> V_48 = 0 ;
V_2 -> V_21 -> V_49 ( V_2 ) ;
V_25 = V_2 -> V_21 -> V_50 ( V_2 ) ;
if ( V_25 ) {
F_6 ( V_30 -> V_30 , L_4 , V_25 ) ;
}
}
int F_18 ( struct V_1 * V_2 , struct V_51 * V_52 ,
struct V_53 * V_54 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_55 * V_56 = V_2 -> V_30 -> V_57 ;
struct V_38 * V_39 = V_2 -> V_26 ;
unsigned V_58 , V_59 = 0 ;
for ( V_58 = 0 ; V_58 < V_52 -> V_60 ; V_58 ++ ) {
switch ( V_52 -> V_61 [ V_58 ] . type ) {
case V_62 :
break;
case V_63 :
if ( V_56 -> V_64 == V_54 )
break;
case V_65 :
F_19 ( V_39 , F_11 ( V_5 ) ?
V_66 : V_67 , 2 ) ;
F_20 ( V_39 , V_52 -> V_61 [ V_58 ] . V_68 ) ;
F_20 ( V_39 , V_52 -> V_61 [ V_58 ] . V_32 ) ;
V_59 ++ ;
break;
}
}
if ( V_59 % 2 )
F_21 ( V_39 ) ;
F_22 ( V_39 , V_69 , 1 ) ;
F_20 ( V_39 , V_52 -> V_44 ) ;
if ( F_23 ( V_5 ) || F_24 ( V_5 ) ) {
F_19 ( V_39 , V_70 , 1 ) ;
F_20 ( V_39 , V_71 ) ;
F_19 ( V_39 , V_72 , 1 ) ;
F_20 ( V_39 , 0x00000000 ) ;
}
F_19 ( V_39 , V_70 , 3 ) ;
F_20 ( V_39 , V_73 ) ;
F_20 ( V_39 , F_12 ( V_5 , V_44 ) ) ;
F_20 ( V_39 , V_52 -> V_44 ) ;
F_19 ( V_39 , V_74 , 1 ) ;
F_20 ( V_39 , 0x80000000 ) ;
if ( F_25 ( V_5 ) ) {
F_19 ( V_39 , V_72 , 1 ) ;
F_20 ( V_39 , 0x00000000 ) ;
F_19 ( V_39 , V_74 , 1 ) ;
F_20 ( V_39 , 0x80000000 ) ;
}
#if 0
if (adreno_is_a3xx(adreno_gpu)) {
OUT_PKT3(ring, CP_SET_CONSTANT, 2);
OUT_RING(ring, CP_REG(REG_A3XX_HLSQ_CL_KERNEL_GROUP_X_REG));
OUT_RING(ring, 0x00000000);
}
#endif
V_2 -> V_21 -> V_75 ( V_2 ) ;
return 0 ;
}
void F_26 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
T_1 V_48 = F_13 ( V_2 -> V_26 ) ;
F_27 () ;
F_7 ( V_5 , V_76 , V_48 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
T_1 V_48 = F_13 ( V_2 -> V_26 ) ;
int V_25 ;
V_25 = F_29 ( F_14 ( V_5 ) == V_48 ) ;
if ( V_25 )
F_30 ( L_5 , V_2 -> V_24 ) ;
}
void F_31 ( struct V_1 * V_2 , struct V_77 * V_78 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
int V_58 ;
F_32 ( V_78 , L_6 ,
V_5 -> V_7 -> V_8 , V_5 -> V_12 . V_16 ,
V_5 -> V_12 . V_15 , V_5 -> V_12 . V_14 ,
V_5 -> V_12 . V_13 ) ;
F_32 ( V_78 , L_7 , V_5 -> V_42 -> V_44 ,
V_2 -> V_47 ) ;
F_32 ( V_78 , L_8 , F_14 ( V_5 ) ) ;
F_32 ( V_78 , L_9 , V_5 -> V_42 -> V_48 ) ;
F_32 ( V_78 , L_10 , F_13 ( V_2 -> V_26 ) ) ;
V_2 -> V_21 -> V_49 ( V_2 ) ;
F_32 ( V_78 , L_11 , V_2 -> V_24 ) ;
for ( V_58 = 0 ; V_5 -> V_79 [ V_58 ] != ~ 0 ; V_58 += 2 ) {
T_1 V_41 = V_5 -> V_79 [ V_58 ] ;
T_1 V_80 = V_5 -> V_79 [ V_58 + 1 ] ;
T_1 V_81 ;
for ( V_81 = V_41 ; V_81 <= V_80 ; V_81 ++ ) {
T_1 V_82 = F_33 ( V_2 , V_81 ) ;
F_32 ( V_78 , L_12 , V_81 << 2 , V_82 ) ;
}
}
V_2 -> V_21 -> V_46 ( V_2 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
int V_58 ;
F_35 ( L_6 ,
V_5 -> V_7 -> V_8 , V_5 -> V_12 . V_16 ,
V_5 -> V_12 . V_15 , V_5 -> V_12 . V_14 ,
V_5 -> V_12 . V_13 ) ;
F_35 ( L_7 , V_5 -> V_42 -> V_44 ,
V_2 -> V_47 ) ;
F_35 ( L_8 , F_14 ( V_5 ) ) ;
F_35 ( L_9 , V_5 -> V_42 -> V_48 ) ;
F_35 ( L_10 , F_13 ( V_2 -> V_26 ) ) ;
for ( V_58 = 0 ; V_58 < 8 ; V_58 ++ ) {
F_35 ( L_13 , V_58 ,
F_33 ( V_2 , V_83 + V_58 ) ) ;
}
}
void F_36 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
int V_58 ;
F_35 ( L_11 , V_2 -> V_24 ) ;
for ( V_58 = 0 ; V_5 -> V_79 [ V_58 ] != ~ 0 ; V_58 += 2 ) {
T_1 V_41 = V_5 -> V_79 [ V_58 ] ;
T_1 V_80 = V_5 -> V_79 [ V_58 + 1 ] ;
T_1 V_81 ;
for ( V_81 = V_41 ; V_81 <= V_80 ; V_81 ++ ) {
T_1 V_82 = F_33 ( V_2 , V_81 ) ;
F_35 ( L_12 , V_81 << 2 , V_82 ) ;
}
}
}
static T_1 F_37 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
T_1 V_32 = V_2 -> V_26 -> V_32 / 4 ;
T_1 V_48 = F_13 ( V_2 -> V_26 ) ;
T_1 V_37 = F_14 ( V_5 ) ;
return ( V_37 + ( V_32 - 1 ) - V_48 ) % V_32 ;
}
void F_38 ( struct V_1 * V_2 , T_1 V_84 )
{
if ( F_29 ( F_37 ( V_2 ) >= V_84 ) )
F_30 ( L_14 , V_2 -> V_24 ) ;
}
int F_39 ( struct V_45 * V_85 , struct V_86 * V_87 ,
struct V_5 * V_5 , const struct V_88 * V_21 )
{
struct V_89 * V_90 = V_87 -> V_30 . V_91 ;
struct V_1 * V_2 = & V_5 -> V_18 ;
struct V_92 * V_93 ;
int V_25 ;
V_5 -> V_21 = V_21 ;
V_5 -> V_7 = F_40 ( V_90 -> V_12 ) ;
V_5 -> V_10 = V_5 -> V_7 -> V_10 ;
V_5 -> V_8 = V_5 -> V_7 -> V_8 ;
V_5 -> V_12 = V_90 -> V_12 ;
V_2 -> V_19 = V_90 -> V_19 ;
V_2 -> V_94 = V_90 -> V_94 ;
V_2 -> V_95 = V_90 -> V_95 ;
#ifdef F_41
V_2 -> V_96 = V_90 -> V_96 ;
#endif
F_3 ( L_15 ,
V_2 -> V_19 , V_2 -> V_94 , V_2 -> V_95 ) ;
V_25 = F_42 ( V_85 , V_87 , & V_5 -> V_18 , & V_21 -> V_18 ,
V_5 -> V_7 -> V_24 , L_16 , L_17 ,
V_97 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_43 ( & V_5 -> V_98 , V_5 -> V_7 -> V_99 , V_85 -> V_30 ) ;
if ( V_25 ) {
F_6 ( V_85 -> V_30 , L_18 ,
V_5 -> V_7 -> V_99 , V_25 ) ;
return V_25 ;
}
V_25 = F_43 ( & V_5 -> V_100 , V_5 -> V_7 -> V_101 , V_85 -> V_30 ) ;
if ( V_25 ) {
F_6 ( V_85 -> V_30 , L_19 ,
V_5 -> V_7 -> V_101 , V_25 ) ;
return V_25 ;
}
V_93 = V_2 -> V_93 ;
if ( V_93 ) {
V_25 = V_93 -> V_21 -> V_102 ( V_93 , V_103 ,
F_44 ( V_103 ) ) ;
if ( V_25 )
return V_25 ;
}
F_45 ( & V_85 -> V_104 ) ;
V_5 -> V_105 = F_46 ( V_85 , sizeof( * V_5 -> V_42 ) ,
V_106 ) ;
F_47 ( & V_85 -> V_104 ) ;
if ( F_48 ( V_5 -> V_105 ) ) {
V_25 = F_49 ( V_5 -> V_105 ) ;
V_5 -> V_105 = NULL ;
F_6 ( V_85 -> V_30 , L_20 , V_25 ) ;
return V_25 ;
}
V_5 -> V_42 = F_50 ( V_5 -> V_105 ) ;
if ( ! V_5 -> V_42 ) {
F_6 ( V_85 -> V_30 , L_21 ) ;
return - V_107 ;
}
V_25 = F_5 ( V_5 -> V_105 , V_2 -> V_28 ,
& V_5 -> V_108 ) ;
if ( V_25 ) {
F_6 ( V_85 -> V_30 , L_22 , V_25 ) ;
return V_25 ;
}
return 0 ;
}
void F_51 ( struct V_5 * V_2 )
{
if ( V_2 -> V_105 ) {
if ( V_2 -> V_108 )
F_52 ( V_2 -> V_105 , V_2 -> V_18 . V_28 ) ;
F_53 ( V_2 -> V_105 ) ;
}
F_54 ( V_2 -> V_98 ) ;
F_54 ( V_2 -> V_100 ) ;
F_55 ( & V_2 -> V_18 ) ;
}
