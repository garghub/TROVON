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
* V_4 = 0x100000 ;
return 0 ;
case V_12 :
* V_4 = V_5 -> V_13 . V_14 |
( V_5 -> V_13 . V_15 << 8 ) |
( V_5 -> V_13 . V_16 << 16 ) |
( V_5 -> V_13 . V_17 << 24 ) ;
return 0 ;
case V_18 :
* V_4 = V_5 -> V_19 . V_20 ;
return 0 ;
case V_21 :
if ( V_5 -> V_22 -> V_23 ) {
int V_24 ;
F_3 ( & V_2 -> V_25 -> V_26 ) ;
V_24 = V_5 -> V_22 -> V_23 ( V_2 , V_4 ) ;
F_4 ( & V_2 -> V_25 -> V_26 ) ;
return V_24 ;
}
return - V_27 ;
default:
F_5 ( L_1 , V_2 -> V_28 , V_3 ) ;
return - V_27 ;
}
}
int F_6 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
int V_24 ;
F_5 ( L_2 , V_2 -> V_28 ) ;
V_24 = F_7 ( V_2 -> V_29 -> V_30 , V_2 -> V_31 , & V_2 -> V_32 ) ;
if ( V_24 ) {
V_2 -> V_32 = 0 ;
F_8 ( V_2 -> V_26 -> V_26 , L_3 , V_24 ) ;
return V_24 ;
}
V_2 -> V_29 -> V_33 = V_2 -> V_29 -> V_34 ;
V_5 -> V_35 -> V_36 = V_2 -> V_37 -> V_38 ;
V_5 -> V_35 -> V_39 = 0 ;
F_9 ( V_5 , V_40 ,
F_10 ( F_11 ( V_2 -> V_29 -> V_41 / 8 ) ) |
F_12 ( F_11 ( V_42 / 8 ) ) |
( F_13 ( V_5 ) ? V_43 : 0 ) ) ;
F_14 ( V_5 , V_44 ,
V_45 , V_2 -> V_32 ) ;
if ( ! F_13 ( V_5 ) ) {
F_14 ( V_5 , V_46 ,
V_47 ,
F_15 ( V_5 , V_39 ) ) ;
}
return 0 ;
}
static T_1 F_16 ( struct V_48 * V_49 )
{
return V_49 -> V_33 - V_49 -> V_34 ;
}
static T_1 F_17 ( struct V_5 * V_5 )
{
if ( F_13 ( V_5 ) )
return V_5 -> V_35 -> V_39 = F_18 (
V_5 , V_50 ) ;
else
return V_5 -> V_35 -> V_39 ;
}
T_1 F_19 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_35 -> V_36 ;
}
void F_20 ( struct V_1 * V_2 )
{
struct V_51 * V_26 = V_2 -> V_26 ;
int V_24 ;
V_2 -> V_22 -> V_52 ( V_2 ) ;
V_2 -> V_22 -> V_53 ( V_2 ) ;
V_24 = F_21 ( V_2 ) ;
if ( V_24 ) {
F_8 ( V_26 -> V_26 , L_4 , V_24 ) ;
}
}
void F_22 ( struct V_1 * V_2 , struct V_54 * V_55 ,
struct V_56 * V_57 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_58 * V_59 = V_2 -> V_26 -> V_60 ;
struct V_48 * V_49 = V_2 -> V_29 ;
unsigned V_61 ;
for ( V_61 = 0 ; V_61 < V_55 -> V_62 ; V_61 ++ ) {
switch ( V_55 -> V_63 [ V_61 ] . type ) {
case V_64 :
break;
case V_65 :
if ( V_59 -> V_66 == V_57 )
break;
case V_67 :
F_23 ( V_49 , F_13 ( V_5 ) ?
V_68 : V_69 , 2 ) ;
F_24 ( V_49 , V_55 -> V_63 [ V_61 ] . V_70 ) ;
F_24 ( V_49 , V_55 -> V_63 [ V_61 ] . V_41 ) ;
F_25 ( V_49 ) ;
break;
}
}
F_26 ( V_49 , V_71 , 1 ) ;
F_24 ( V_49 , V_55 -> V_36 -> V_72 ) ;
if ( F_27 ( V_5 ) || F_28 ( V_5 ) ) {
F_23 ( V_49 , V_73 , 1 ) ;
F_24 ( V_49 , V_74 ) ;
F_23 ( V_49 , V_75 , 1 ) ;
F_24 ( V_49 , 0x00000000 ) ;
}
F_23 ( V_49 , V_73 , 3 ) ;
F_24 ( V_49 , V_76 ) ;
F_24 ( V_49 , F_15 ( V_5 , V_36 ) ) ;
F_24 ( V_49 , V_55 -> V_36 -> V_72 ) ;
F_23 ( V_49 , V_77 , 1 ) ;
F_24 ( V_49 , 0x80000000 ) ;
if ( F_29 ( V_5 ) ) {
F_23 ( V_49 , V_75 , 1 ) ;
F_24 ( V_49 , 0x00000000 ) ;
F_23 ( V_49 , V_77 , 1 ) ;
F_24 ( V_49 , 0x80000000 ) ;
}
#if 0
if (adreno_is_a3xx(adreno_gpu)) {
OUT_PKT3(ring, CP_SET_CONSTANT, 2);
OUT_RING(ring, CP_REG(REG_A3XX_HLSQ_CL_KERNEL_GROUP_X_REG));
OUT_RING(ring, 0x00000000);
}
#endif
V_2 -> V_22 -> V_78 ( V_2 ) ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
T_1 V_79 ;
V_79 = F_16 ( V_2 -> V_29 ) & ( ( V_2 -> V_29 -> V_41 / 4 ) - 1 ) ;
F_31 () ;
F_9 ( V_5 , V_80 , V_79 ) ;
}
bool F_32 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
T_1 V_79 = F_16 ( V_2 -> V_29 ) ;
if ( ! F_33 ( F_17 ( V_5 ) == V_79 ) )
return true ;
F_34 ( L_5 , V_2 -> V_28 ) ;
return false ;
}
void F_35 ( struct V_1 * V_2 , struct V_81 * V_82 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
int V_61 ;
F_36 ( V_82 , L_6 ,
V_5 -> V_7 -> V_8 , V_5 -> V_13 . V_17 ,
V_5 -> V_13 . V_16 , V_5 -> V_13 . V_15 ,
V_5 -> V_13 . V_14 ) ;
F_36 ( V_82 , L_7 , V_5 -> V_35 -> V_36 ,
V_2 -> V_37 -> V_83 ) ;
F_36 ( V_82 , L_8 , F_17 ( V_5 ) ) ;
F_36 ( V_82 , L_9 , F_16 ( V_2 -> V_29 ) ) ;
F_36 ( V_82 , L_10 , V_2 -> V_28 ) ;
for ( V_61 = 0 ; V_5 -> V_84 [ V_61 ] != ~ 0 ; V_61 += 2 ) {
T_1 V_34 = V_5 -> V_84 [ V_61 ] ;
T_1 V_85 = V_5 -> V_84 [ V_61 + 1 ] ;
T_1 V_86 ;
for ( V_86 = V_34 ; V_86 <= V_85 ; V_86 ++ ) {
T_1 V_87 = F_37 ( V_2 , V_86 ) ;
F_36 ( V_82 , L_11 , V_86 << 2 , V_87 ) ;
}
}
}
void F_38 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
F_39 ( L_6 ,
V_5 -> V_7 -> V_8 , V_5 -> V_13 . V_17 ,
V_5 -> V_13 . V_16 , V_5 -> V_13 . V_15 ,
V_5 -> V_13 . V_14 ) ;
F_39 ( L_7 , V_5 -> V_35 -> V_36 ,
V_2 -> V_37 -> V_83 ) ;
F_39 ( L_8 , F_17 ( V_5 ) ) ;
F_39 ( L_9 , F_16 ( V_2 -> V_29 ) ) ;
}
void F_40 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
int V_61 ;
F_39 ( L_10 , V_2 -> V_28 ) ;
for ( V_61 = 0 ; V_5 -> V_84 [ V_61 ] != ~ 0 ; V_61 += 2 ) {
T_1 V_34 = V_5 -> V_84 [ V_61 ] ;
T_1 V_85 = V_5 -> V_84 [ V_61 + 1 ] ;
T_1 V_86 ;
for ( V_86 = V_34 ; V_86 <= V_85 ; V_86 ++ ) {
T_1 V_87 = F_37 ( V_2 , V_86 ) ;
F_39 ( L_11 , V_86 << 2 , V_87 ) ;
}
}
}
static T_1 F_41 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
T_1 V_41 = V_2 -> V_29 -> V_41 / 4 ;
T_1 V_79 = F_16 ( V_2 -> V_29 ) ;
T_1 V_39 = F_17 ( V_5 ) ;
return ( V_39 + ( V_41 - 1 ) - V_79 ) % V_41 ;
}
void F_42 ( struct V_1 * V_2 , T_1 V_88 )
{
if ( F_33 ( F_41 ( V_2 ) >= V_88 ) )
F_34 ( L_12 , V_2 -> V_28 ) ;
}
int F_43 ( struct V_51 * V_89 , struct V_90 * V_25 ,
struct V_5 * V_5 , const struct V_91 * V_22 )
{
struct V_92 * V_93 = V_25 -> V_26 . V_94 ;
struct V_95 V_96 = { 0 } ;
struct V_1 * V_2 = & V_5 -> V_19 ;
int V_24 ;
V_5 -> V_22 = V_22 ;
V_5 -> V_7 = F_44 ( V_93 -> V_13 ) ;
V_5 -> V_10 = V_5 -> V_7 -> V_10 ;
V_5 -> V_8 = V_5 -> V_7 -> V_8 ;
V_5 -> V_13 = V_93 -> V_13 ;
V_2 -> V_20 = V_93 -> V_20 ;
V_2 -> V_97 = V_93 -> V_97 ;
#ifdef F_45
V_2 -> V_98 = V_93 -> V_98 ;
#endif
F_5 ( L_13 ,
V_2 -> V_20 , V_2 -> V_97 ) ;
V_96 . V_99 = L_14 ;
V_96 . V_100 = L_15 ;
V_96 . va_start = V_101 ;
V_96 . va_end = 0xffffffff ;
V_96 . V_102 = V_103 ;
F_46 ( & V_25 -> V_26 , V_104 ) ;
F_47 ( & V_25 -> V_26 ) ;
F_48 ( & V_25 -> V_26 ) ;
V_24 = F_49 ( V_89 , V_25 , & V_5 -> V_19 , & V_22 -> V_19 ,
V_5 -> V_7 -> V_28 , & V_96 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_50 ( & V_5 -> V_105 , V_5 -> V_7 -> V_106 , V_89 -> V_26 ) ;
if ( V_24 ) {
F_8 ( V_89 -> V_26 , L_16 ,
V_5 -> V_7 -> V_106 , V_24 ) ;
return V_24 ;
}
V_24 = F_50 ( & V_5 -> V_107 , V_5 -> V_7 -> V_108 , V_89 -> V_26 ) ;
if ( V_24 ) {
F_8 ( V_89 -> V_26 , L_17 ,
V_5 -> V_7 -> V_108 , V_24 ) ;
return V_24 ;
}
V_5 -> V_35 = F_51 ( V_89 ,
sizeof( * V_5 -> V_35 ) , V_109 , V_2 -> V_31 ,
& V_5 -> V_110 , & V_5 -> V_111 ) ;
if ( F_52 ( V_5 -> V_35 ) ) {
V_24 = F_53 ( V_5 -> V_35 ) ;
V_5 -> V_35 = NULL ;
F_8 ( V_89 -> V_26 , L_18 , V_24 ) ;
}
return V_24 ;
}
void F_54 ( struct V_5 * V_5 )
{
struct V_1 * V_2 = & V_5 -> V_19 ;
if ( V_5 -> V_110 ) {
if ( V_5 -> V_35 )
F_55 ( V_5 -> V_110 ) ;
if ( V_5 -> V_111 )
F_56 ( V_5 -> V_110 , V_2 -> V_31 ) ;
F_57 ( V_5 -> V_110 ) ;
}
F_58 ( V_5 -> V_105 ) ;
F_58 ( V_5 -> V_107 ) ;
F_59 ( V_2 ) ;
}
