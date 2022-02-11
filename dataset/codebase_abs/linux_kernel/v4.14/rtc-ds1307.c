static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
struct V_4 * V_5 = & V_3 -> V_6 -> V_7 ;
int V_8 , V_9 ;
F_2 ( V_5 ) ;
V_9 = F_3 ( V_3 -> V_10 , V_11 , & V_8 ) ;
if ( V_9 )
goto V_12;
if ( V_8 & V_13 ) {
V_8 &= ~ V_13 ;
F_4 ( V_3 -> V_10 , V_11 , V_8 ) ;
V_9 = F_5 ( V_3 -> V_10 , V_14 ,
V_15 , 0 ) ;
if ( V_9 )
goto V_12;
F_6 ( V_3 -> V_6 , 1 , V_16 | V_17 ) ;
}
V_12:
F_7 ( V_5 ) ;
return V_18 ;
}
static int F_8 ( struct V_19 * V_20 , struct V_21 * V_22 )
{
struct V_3 * V_3 = F_9 ( V_20 ) ;
int V_23 , V_9 ;
const struct V_24 * V_25 = & V_26 [ V_3 -> type ] ;
T_2 V_27 [ 7 ] ;
V_9 = F_10 ( V_3 -> V_10 , V_25 -> V_28 , V_27 ,
sizeof( V_27 ) ) ;
if ( V_9 ) {
F_11 ( V_20 , L_1 , L_2 , V_9 ) ;
return V_9 ;
}
F_12 ( V_20 , L_3 , L_2 , V_27 ) ;
if ( V_3 -> type == V_29 &&
V_27 [ V_30 ] & V_31 ) {
F_13 ( V_20 , L_4 ) ;
return - V_32 ;
}
V_22 -> V_33 = F_14 ( V_27 [ V_34 ] & 0x7f ) ;
V_22 -> V_35 = F_14 ( V_27 [ V_30 ] & 0x7f ) ;
V_23 = V_27 [ V_36 ] & 0x3f ;
V_22 -> V_37 = F_14 ( V_23 ) ;
V_22 -> V_38 = F_14 ( V_27 [ V_39 ] & 0x07 ) - 1 ;
V_22 -> V_40 = F_14 ( V_27 [ V_41 ] & 0x3f ) ;
V_23 = V_27 [ V_42 ] & 0x1f ;
V_22 -> V_43 = F_14 ( V_23 ) - 1 ;
V_22 -> V_44 = F_14 ( V_27 [ V_45 ] ) + 100 ;
if ( V_27 [ V_25 -> V_46 ] & V_25 -> V_47 &&
F_15 ( V_48 ) )
V_22 -> V_44 += 100 ;
F_12 ( V_20 , L_5
L_6 ,
L_2 , V_22 -> V_33 , V_22 -> V_35 ,
V_22 -> V_37 , V_22 -> V_40 ,
V_22 -> V_43 , V_22 -> V_44 , V_22 -> V_38 ) ;
return F_16 ( V_22 ) ;
}
static int F_17 ( struct V_19 * V_20 , struct V_21 * V_22 )
{
struct V_3 * V_3 = F_9 ( V_20 ) ;
const struct V_24 * V_25 = & V_26 [ V_3 -> type ] ;
int V_49 ;
int V_23 ;
T_2 V_27 [ 7 ] ;
F_12 ( V_20 , L_5
L_6 ,
L_7 , V_22 -> V_33 , V_22 -> V_35 ,
V_22 -> V_37 , V_22 -> V_40 ,
V_22 -> V_43 , V_22 -> V_44 , V_22 -> V_38 ) ;
if ( V_22 -> V_44 < 100 )
return - V_32 ;
#ifdef V_48
if ( V_22 -> V_44 > ( V_25 -> V_47 ? 299 : 199 ) )
return - V_32 ;
#else
if ( V_22 -> V_44 > 199 )
return - V_32 ;
#endif
V_27 [ V_34 ] = F_18 ( V_22 -> V_33 ) ;
V_27 [ V_30 ] = F_18 ( V_22 -> V_35 ) ;
V_27 [ V_36 ] = F_18 ( V_22 -> V_37 ) ;
V_27 [ V_39 ] = F_18 ( V_22 -> V_38 + 1 ) ;
V_27 [ V_41 ] = F_18 ( V_22 -> V_40 ) ;
V_27 [ V_42 ] = F_18 ( V_22 -> V_43 + 1 ) ;
V_23 = V_22 -> V_44 - 100 ;
V_27 [ V_45 ] = F_18 ( V_23 ) ;
if ( V_25 -> V_50 )
V_27 [ V_25 -> V_46 ] |= V_25 -> V_50 ;
if ( V_22 -> V_44 > 199 && V_25 -> V_47 )
V_27 [ V_25 -> V_46 ] |= V_25 -> V_47 ;
if ( V_3 -> type == V_51 ) {
V_27 [ V_34 ] |= V_52 ;
V_27 [ V_39 ] |= V_53 ;
}
F_12 ( V_20 , L_3 , L_7 , V_27 ) ;
V_49 = F_19 ( V_3 -> V_10 , V_25 -> V_28 , V_27 ,
sizeof( V_27 ) ) ;
if ( V_49 ) {
F_11 ( V_20 , L_1 , L_7 , V_49 ) ;
return V_49 ;
}
return 0 ;
}
static int F_20 ( struct V_19 * V_20 , struct V_54 * V_22 )
{
struct V_3 * V_3 = F_9 ( V_20 ) ;
int V_9 ;
T_2 V_27 [ 9 ] ;
if ( ! F_21 ( V_55 , & V_3 -> V_56 ) )
return - V_32 ;
V_9 = F_10 ( V_3 -> V_10 , V_57 ,
V_27 , sizeof( V_27 ) ) ;
if ( V_9 ) {
F_11 ( V_20 , L_1 , L_8 , V_9 ) ;
return V_9 ;
}
F_12 ( V_20 , L_9 , L_8 ,
& V_27 [ 0 ] , & V_27 [ 4 ] , & V_27 [ 7 ] ) ;
V_22 -> time . V_33 = F_14 ( V_27 [ 0 ] & 0x7f ) ;
V_22 -> time . V_35 = F_14 ( V_27 [ 1 ] & 0x7f ) ;
V_22 -> time . V_37 = F_14 ( V_27 [ 2 ] & 0x3f ) ;
V_22 -> time . V_40 = F_14 ( V_27 [ 3 ] & 0x3f ) ;
V_22 -> V_58 = ! ! ( V_27 [ 7 ] & V_15 ) ;
V_22 -> V_59 = ! ! ( V_27 [ 8 ] & V_13 ) ;
F_12 ( V_20 , L_5
L_10 ,
L_8 , V_22 -> time . V_33 , V_22 -> time . V_35 ,
V_22 -> time . V_37 , V_22 -> time . V_40 ,
V_22 -> V_58 , V_22 -> V_59 ) ;
return 0 ;
}
static int F_22 ( struct V_19 * V_20 , struct V_54 * V_22 )
{
struct V_3 * V_3 = F_9 ( V_20 ) ;
unsigned char V_27 [ 9 ] ;
T_2 V_60 , V_61 ;
int V_9 ;
if ( ! F_21 ( V_55 , & V_3 -> V_56 ) )
return - V_32 ;
F_12 ( V_20 , L_5
L_10 ,
L_11 , V_22 -> time . V_33 , V_22 -> time . V_35 ,
V_22 -> time . V_37 , V_22 -> time . V_40 ,
V_22 -> V_58 , V_22 -> V_59 ) ;
V_9 = F_10 ( V_3 -> V_10 , V_57 , V_27 ,
sizeof( V_27 ) ) ;
if ( V_9 ) {
F_11 ( V_20 , L_1 , L_12 , V_9 ) ;
return V_9 ;
}
V_60 = V_27 [ 7 ] ;
V_61 = V_27 [ 8 ] ;
F_12 ( V_20 , L_13 , L_14 ,
& V_27 [ 0 ] , & V_27 [ 4 ] , V_60 , V_61 ) ;
V_27 [ 0 ] = F_18 ( V_22 -> time . V_33 ) ;
V_27 [ 1 ] = F_18 ( V_22 -> time . V_35 ) ;
V_27 [ 2 ] = F_18 ( V_22 -> time . V_37 ) ;
V_27 [ 3 ] = F_18 ( V_22 -> time . V_40 ) ;
V_27 [ 4 ] = 0 ;
V_27 [ 5 ] = 0 ;
V_27 [ 6 ] = 0 ;
V_27 [ 7 ] = V_60 & ~ ( V_15 | V_62 ) ;
V_27 [ 8 ] = V_61 & ~ ( V_13 | V_63 ) ;
V_9 = F_19 ( V_3 -> V_10 , V_57 , V_27 ,
sizeof( V_27 ) ) ;
if ( V_9 ) {
F_11 ( V_20 , L_15 ) ;
return V_9 ;
}
if ( V_22 -> V_58 ) {
F_12 ( V_20 , L_16 ) ;
V_27 [ 7 ] |= V_15 ;
F_4 ( V_3 -> V_10 , V_14 , V_27 [ 7 ] ) ;
}
return 0 ;
}
static int F_23 ( struct V_19 * V_20 , unsigned int V_58 )
{
struct V_3 * V_3 = F_9 ( V_20 ) ;
if ( ! F_21 ( V_55 , & V_3 -> V_56 ) )
return - V_64 ;
return F_5 ( V_3 -> V_10 , V_14 ,
V_15 ,
V_58 ? V_15 : 0 ) ;
}
static T_1 F_24 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
struct V_4 * V_5 = & V_3 -> V_6 -> V_7 ;
T_2 V_65 [ 3 ] ;
int V_9 ;
F_2 ( V_5 ) ;
V_9 = F_10 ( V_3 -> V_10 , V_66 , V_65 ,
sizeof( V_65 ) ) ;
if ( V_9 < 0 )
goto V_12;
if ( ! ( V_65 [ 1 ] & V_67 ) )
goto V_12;
V_65 [ 1 ] &= ~ V_67 ;
V_65 [ 2 ] &= ~ V_68 ;
V_9 = F_19 ( V_3 -> V_10 , V_66 , V_65 ,
sizeof( V_65 ) ) ;
if ( V_9 < 0 )
goto V_12;
F_6 ( V_3 -> V_6 , 1 , V_16 | V_17 ) ;
V_12:
F_7 ( V_5 ) ;
return V_18 ;
}
static int F_25 ( struct V_19 * V_20 , struct V_54 * V_22 )
{
struct V_3 * V_3 = F_9 ( V_20 ) ;
T_2 V_69 [ 3 ] , V_65 [ 3 ] ;
int V_9 ;
if ( ! F_21 ( V_55 , & V_3 -> V_56 ) )
return - V_32 ;
V_9 = F_10 ( V_3 -> V_10 , V_70 , V_69 ,
sizeof( V_69 ) ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_10 ( V_3 -> V_10 , V_66 , V_65 ,
sizeof( V_65 ) ) ;
if ( V_9 < 0 )
return V_9 ;
V_22 -> V_58 = ! ! ( V_65 [ 2 ] & V_68 ) ;
V_22 -> V_59 = ! ! ( V_65 [ 1 ] & V_67 ) ;
V_22 -> time . V_33 = - 1 ;
V_22 -> time . V_35 = F_14 ( V_69 [ 0 ] & 0x7f ) ;
V_22 -> time . V_37 = F_14 ( V_69 [ 1 ] & 0x7f ) ;
V_22 -> time . V_38 = - 1 ;
V_22 -> time . V_40 = F_14 ( V_69 [ 2 ] & 0x7f ) ;
V_22 -> time . V_43 = - 1 ;
V_22 -> time . V_44 = - 1 ;
V_22 -> time . V_71 = - 1 ;
V_22 -> time . V_72 = - 1 ;
F_12 ( V_20 , L_17 ,
V_73 , V_22 -> time . V_33 , V_22 -> time . V_35 , V_22 -> time . V_37 ,
V_22 -> time . V_38 , V_22 -> time . V_40 , V_22 -> time . V_43 , V_22 -> V_58 ) ;
return 0 ;
}
static int F_26 ( struct V_19 * V_20 , struct V_54 * V_22 )
{
struct V_3 * V_3 = F_9 ( V_20 ) ;
T_2 V_69 [ 3 ] , V_65 [ 3 ] ;
int V_9 ;
if ( ! F_21 ( V_55 , & V_3 -> V_56 ) )
return - V_32 ;
F_12 ( V_20 , L_18
L_19 , V_73 ,
V_22 -> time . V_33 , V_22 -> time . V_35 , V_22 -> time . V_37 ,
V_22 -> time . V_38 , V_22 -> time . V_40 , V_22 -> time . V_43 ,
V_22 -> V_58 , V_22 -> V_59 ) ;
V_9 = F_10 ( V_3 -> V_10 , V_66 , V_65 ,
sizeof( V_65 ) ) ;
if ( V_9 < 0 )
return V_9 ;
V_65 [ 0 ] &= ~ V_74 ;
V_65 [ 1 ] |= V_67 ;
V_65 [ 2 ] &= ~ V_68 ;
V_9 = F_19 ( V_3 -> V_10 , V_66 , V_65 ,
sizeof( V_65 ) ) ;
if ( V_9 < 0 )
return V_9 ;
V_69 [ 0 ] = F_18 ( V_22 -> time . V_35 ) ;
V_69 [ 1 ] = F_18 ( V_22 -> time . V_37 ) ;
V_69 [ 2 ] = F_18 ( V_22 -> time . V_40 ) ;
V_9 = F_19 ( V_3 -> V_10 , V_70 , V_69 ,
sizeof( V_69 ) ) ;
if ( V_9 < 0 )
return V_9 ;
if ( ! V_22 -> V_58 )
return 0 ;
V_65 [ 2 ] |= V_68 ;
return F_19 ( V_3 -> V_10 , V_66 , V_65 ,
sizeof( V_65 ) ) ;
}
static int F_27 ( struct V_19 * V_20 , unsigned int V_58 )
{
struct V_3 * V_3 = F_9 ( V_20 ) ;
int V_9 , V_75 ;
if ( ! F_21 ( V_55 , & V_3 -> V_56 ) )
return - V_32 ;
V_9 = F_3 ( V_3 -> V_10 , V_76 , & V_75 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_58 )
V_75 |= V_68 ;
else
V_75 &= ~ V_68 ;
return F_4 ( V_3 -> V_10 , V_76 , V_75 ) ;
}
static T_1 F_28 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
struct V_4 * V_5 = & V_3 -> V_6 -> V_7 ;
int V_75 , V_9 ;
F_2 ( V_5 ) ;
V_9 = F_3 ( V_3 -> V_10 , V_77 , & V_75 ) ;
if ( V_9 )
goto V_12;
if ( ! ( V_75 & V_78 ) )
goto V_12;
V_75 &= ~ V_78 ;
V_9 = F_4 ( V_3 -> V_10 , V_77 , V_75 ) ;
if ( V_9 )
goto V_12;
V_9 = F_5 ( V_3 -> V_10 , V_79 ,
V_80 , 0 ) ;
if ( V_9 )
goto V_12;
F_6 ( V_3 -> V_6 , 1 , V_16 | V_17 ) ;
V_12:
F_7 ( V_5 ) ;
return V_18 ;
}
static int F_29 ( struct V_19 * V_20 , struct V_54 * V_22 )
{
struct V_3 * V_3 = F_9 ( V_20 ) ;
T_2 V_27 [ 10 ] ;
int V_9 ;
if ( ! F_21 ( V_55 , & V_3 -> V_56 ) )
return - V_32 ;
V_9 = F_10 ( V_3 -> V_10 , V_79 , V_27 ,
sizeof( V_27 ) ) ;
if ( V_9 )
return V_9 ;
V_22 -> V_58 = ! ! ( V_27 [ 0 ] & V_80 ) ;
V_22 -> time . V_33 = F_14 ( V_27 [ 3 ] & 0x7f ) ;
V_22 -> time . V_35 = F_14 ( V_27 [ 4 ] & 0x7f ) ;
V_22 -> time . V_37 = F_14 ( V_27 [ 5 ] & 0x3f ) ;
V_22 -> time . V_38 = F_14 ( V_27 [ 6 ] & 0x7 ) - 1 ;
V_22 -> time . V_40 = F_14 ( V_27 [ 7 ] & 0x3f ) ;
V_22 -> time . V_43 = F_14 ( V_27 [ 8 ] & 0x1f ) - 1 ;
V_22 -> time . V_44 = - 1 ;
V_22 -> time . V_71 = - 1 ;
V_22 -> time . V_72 = - 1 ;
F_12 ( V_20 , L_18
L_20 , V_73 ,
V_22 -> time . V_33 , V_22 -> time . V_35 , V_22 -> time . V_37 ,
V_22 -> time . V_38 , V_22 -> time . V_40 , V_22 -> time . V_43 , V_22 -> V_58 ,
! ! ( V_27 [ 6 ] & V_81 ) ,
! ! ( V_27 [ 6 ] & V_78 ) ,
( V_27 [ 6 ] & V_82 ) >> 4 ) ;
return 0 ;
}
static int F_30 ( struct V_19 * V_20 , struct V_54 * V_22 )
{
struct V_3 * V_3 = F_9 ( V_20 ) ;
unsigned char V_27 [ 10 ] ;
int V_9 ;
if ( ! F_21 ( V_55 , & V_3 -> V_56 ) )
return - V_32 ;
F_12 ( V_20 , L_18
L_19 , V_73 ,
V_22 -> time . V_33 , V_22 -> time . V_35 , V_22 -> time . V_37 ,
V_22 -> time . V_38 , V_22 -> time . V_40 , V_22 -> time . V_43 ,
V_22 -> V_58 , V_22 -> V_59 ) ;
V_9 = F_10 ( V_3 -> V_10 , V_79 , V_27 ,
sizeof( V_27 ) ) ;
if ( V_9 )
return V_9 ;
V_27 [ 3 ] = F_18 ( V_22 -> time . V_33 ) ;
V_27 [ 4 ] = F_18 ( V_22 -> time . V_35 ) ;
V_27 [ 5 ] = F_18 ( V_22 -> time . V_37 ) ;
V_27 [ 6 ] = F_18 ( V_22 -> time . V_38 + 1 ) ;
V_27 [ 7 ] = F_18 ( V_22 -> time . V_40 ) ;
V_27 [ 8 ] = F_18 ( V_22 -> time . V_43 + 1 ) ;
V_27 [ 6 ] &= ~ V_78 ;
V_27 [ 6 ] |= V_82 ;
V_27 [ 0 ] &= ~ V_80 ;
V_9 = F_19 ( V_3 -> V_10 , V_79 , V_27 ,
sizeof( V_27 ) ) ;
if ( V_9 )
return V_9 ;
if ( ! V_22 -> V_58 )
return 0 ;
V_27 [ 0 ] |= V_80 ;
return F_4 ( V_3 -> V_10 , V_79 , V_27 [ 0 ] ) ;
}
static int F_31 ( struct V_19 * V_20 , unsigned int V_58 )
{
struct V_3 * V_3 = F_9 ( V_20 ) ;
if ( ! F_21 ( V_55 , & V_3 -> V_56 ) )
return - V_32 ;
return F_5 ( V_3 -> V_10 , V_79 ,
V_80 ,
V_58 ? V_80 : 0 ) ;
}
static int F_32 ( void * V_83 , unsigned int V_28 , void * V_84 ,
T_3 V_85 )
{
struct V_3 * V_3 = V_83 ;
const struct V_24 * V_25 = & V_26 [ V_3 -> type ] ;
return F_10 ( V_3 -> V_10 , V_25 -> V_86 + V_28 ,
V_84 , V_85 ) ;
}
static int F_33 ( void * V_83 , unsigned int V_28 , void * V_84 ,
T_3 V_85 )
{
struct V_3 * V_3 = V_83 ;
const struct V_24 * V_25 = & V_26 [ V_3 -> type ] ;
return F_19 ( V_3 -> V_10 , V_25 -> V_86 + V_28 ,
V_84 , V_85 ) ;
}
static T_2 F_34 ( struct V_3 * V_3 ,
T_4 V_87 , bool V_88 )
{
T_2 V_89 = ( V_88 ) ? V_90 :
V_91 ;
switch ( V_87 ) {
case 250 :
V_89 |= V_92 ;
break;
case 2000 :
V_89 |= V_93 ;
break;
case 4000 :
V_89 |= V_94 ;
break;
default:
F_35 ( V_3 -> V_20 ,
L_21 , V_87 ) ;
return 0 ;
}
return V_89 ;
}
static T_2 F_36 ( struct V_3 * V_3 ,
const struct V_24 * V_25 )
{
T_4 V_87 ;
bool V_88 = true ;
if ( ! V_25 -> V_95 )
return 0 ;
if ( F_37 ( V_3 -> V_20 , L_22 ,
& V_87 ) )
return 0 ;
if ( F_38 ( V_3 -> V_20 , L_23 ) )
V_88 = false ;
return V_25 -> V_95 ( V_3 , V_87 , V_88 ) ;
}
static int F_39 ( struct V_19 * V_20 , T_5 * V_96 )
{
struct V_3 * V_3 = F_9 ( V_20 ) ;
T_2 V_97 [ 2 ] ;
T_6 V_98 ;
int V_9 ;
V_9 = F_10 ( V_3 -> V_10 , V_99 ,
V_97 , sizeof( V_97 ) ) ;
if ( V_9 )
return V_9 ;
V_98 = ( V_97 [ 0 ] << 8 ) | V_97 [ 1 ] ;
V_98 >>= 6 ;
* V_96 = V_98 * 250 ;
return 0 ;
}
static T_7 F_40 ( struct V_19 * V_20 ,
struct V_100 * V_101 , char * V_102 )
{
int V_9 ;
T_5 V_98 ;
V_9 = F_39 ( V_20 , & V_98 ) ;
if ( V_9 )
return V_9 ;
return sprintf ( V_102 , L_24 , V_98 ) ;
}
static void F_41 ( struct V_3 * V_3 )
{
struct V_19 * V_20 ;
if ( V_3 -> type != V_103 )
return;
V_20 = F_42 ( V_3 -> V_20 , V_3 -> V_104 ,
V_3 ,
V_105 ) ;
if ( F_43 ( V_20 ) ) {
F_35 ( V_3 -> V_20 , L_25 ,
F_44 ( V_20 ) ) ;
}
}
static void F_41 ( struct V_3 * V_3 )
{
}
static int F_45 ( struct V_3 * V_3 , T_2 V_106 , T_2 V_107 )
{
struct V_4 * V_5 = & V_3 -> V_6 -> V_7 ;
int V_9 ;
F_2 ( V_5 ) ;
V_9 = F_5 ( V_3 -> V_10 , V_14 ,
V_106 , V_107 ) ;
F_7 ( V_5 ) ;
return V_9 ;
}
static unsigned long F_46 ( struct V_108 * V_109 ,
unsigned long V_110 )
{
struct V_3 * V_3 = F_47 ( V_109 ) ;
int V_60 , V_9 ;
int V_111 = 0 ;
V_9 = F_3 ( V_3 -> V_10 , V_14 , & V_60 ) ;
if ( V_9 )
return V_9 ;
if ( V_60 & V_112 )
V_111 += 1 ;
if ( V_60 & V_113 )
V_111 += 2 ;
return V_114 [ V_111 ] ;
}
static long F_48 ( struct V_108 * V_109 , unsigned long V_115 ,
unsigned long * V_116 )
{
int V_117 ;
for ( V_117 = F_49 ( V_114 ) - 1 ; V_117 >= 0 ; V_117 -- ) {
if ( V_114 [ V_117 ] <= V_115 )
return V_114 [ V_117 ] ;
}
return 0 ;
}
static int F_50 ( struct V_108 * V_109 , unsigned long V_115 ,
unsigned long V_110 )
{
struct V_3 * V_3 = F_47 ( V_109 ) ;
int V_60 = 0 ;
int V_111 ;
for ( V_111 = 0 ; V_111 < F_49 ( V_114 ) ;
V_111 ++ ) {
if ( V_114 [ V_111 ] == V_115 )
break;
}
if ( V_111 == F_49 ( V_114 ) )
return - V_32 ;
if ( V_111 & 1 )
V_60 |= V_112 ;
if ( V_111 & 2 )
V_60 |= V_113 ;
return F_45 ( V_3 , V_112 | V_113 ,
V_60 ) ;
}
static int F_51 ( struct V_108 * V_109 )
{
struct V_3 * V_3 = F_47 ( V_109 ) ;
return F_45 ( V_3 , V_118 , 0 ) ;
}
static void F_52 ( struct V_108 * V_109 )
{
struct V_3 * V_3 = F_47 ( V_109 ) ;
F_45 ( V_3 , V_118 , V_118 ) ;
}
static int F_53 ( struct V_108 * V_109 )
{
struct V_3 * V_3 = F_47 ( V_109 ) ;
int V_60 , V_9 ;
V_9 = F_3 ( V_3 -> V_10 , V_14 , & V_60 ) ;
if ( V_9 )
return V_9 ;
return ! ( V_60 & V_118 ) ;
}
static unsigned long F_54 ( struct V_108 * V_109 ,
unsigned long V_110 )
{
return 32768 ;
}
static int F_55 ( struct V_3 * V_3 , bool V_119 )
{
struct V_4 * V_5 = & V_3 -> V_6 -> V_7 ;
int V_9 ;
F_2 ( V_5 ) ;
V_9 = F_5 ( V_3 -> V_10 , V_11 ,
V_120 ,
V_119 ? V_120 : 0 ) ;
F_7 ( V_5 ) ;
return V_9 ;
}
static int F_56 ( struct V_108 * V_109 )
{
struct V_3 * V_3 = F_57 ( V_109 ) ;
return F_55 ( V_3 , true ) ;
}
static void F_58 ( struct V_108 * V_109 )
{
struct V_3 * V_3 = F_57 ( V_109 ) ;
F_55 ( V_3 , false ) ;
}
static int F_59 ( struct V_108 * V_109 )
{
struct V_3 * V_3 = F_57 ( V_109 ) ;
int V_61 , V_9 ;
V_9 = F_3 ( V_3 -> V_10 , V_11 , & V_61 ) ;
if ( V_9 )
return V_9 ;
return ! ! ( V_61 & V_120 ) ;
}
static int F_60 ( struct V_3 * V_3 )
{
struct V_121 * V_122 = V_3 -> V_20 -> V_123 ;
struct V_124 * V_125 ;
int V_117 ;
V_125 = F_61 ( V_3 -> V_20 , sizeof( * V_125 ) , V_126 ) ;
if ( ! V_125 )
return - V_127 ;
V_125 -> V_128 = F_49 ( V_129 ) ;
V_125 -> V_130 = F_62 ( V_3 -> V_20 , V_125 -> V_128 ,
sizeof( V_125 -> V_130 [ 0 ] ) , V_126 ) ;
if ( ! V_125 -> V_130 )
return - V_127 ;
for ( V_117 = 0 ; V_117 < F_49 ( V_129 ) ; V_117 ++ ) {
struct V_131 V_132 = V_129 [ V_117 ] ;
if ( V_117 == V_133 && F_21 ( V_55 , & V_3 -> V_56 ) )
continue;
F_63 ( V_122 , L_26 , V_117 ,
& V_132 . V_104 ) ;
V_3 -> V_130 [ V_117 ] . V_132 = & V_132 ;
V_125 -> V_130 [ V_117 ] = F_64 ( V_3 -> V_20 ,
& V_3 -> V_130 [ V_117 ] ) ;
if ( F_43 ( V_125 -> V_130 [ V_117 ] ) )
return F_44 ( V_125 -> V_130 [ V_117 ] ) ;
}
if ( ! V_122 )
return 0 ;
F_65 ( V_122 , V_134 , V_125 ) ;
return 0 ;
}
static void F_66 ( struct V_3 * V_3 )
{
int V_9 ;
if ( V_3 -> type != V_103 )
return;
V_9 = F_60 ( V_3 ) ;
if ( V_9 ) {
F_35 ( V_3 -> V_20 , L_27 ,
V_9 ) ;
}
}
static void F_66 ( struct V_3 * V_3 )
{
}
static int F_67 ( struct V_135 * V_136 ,
const struct V_137 * V_138 )
{
struct V_3 * V_3 ;
int V_139 = - V_140 ;
int V_23 , V_141 ;
const struct V_24 * V_25 ;
bool V_142 ;
bool V_143 = false ;
unsigned char V_27 [ 8 ] ;
struct V_144 * V_145 = F_68 ( & V_136 -> V_20 ) ;
struct V_21 V_146 ;
unsigned long V_147 ;
T_2 V_148 = 0 ;
V_3 = F_61 ( & V_136 -> V_20 , sizeof( struct V_3 ) , V_126 ) ;
if ( ! V_3 )
return - V_127 ;
F_69 ( & V_136 -> V_20 , V_3 ) ;
V_3 -> V_20 = & V_136 -> V_20 ;
V_3 -> V_104 = V_136 -> V_104 ;
V_3 -> V_10 = F_70 ( V_136 , & V_149 ) ;
if ( F_43 ( V_3 -> V_10 ) ) {
F_11 ( V_3 -> V_20 , L_28 ) ;
return F_44 ( V_3 -> V_10 ) ;
}
F_71 ( V_136 , V_3 ) ;
if ( V_136 -> V_20 . V_123 ) {
V_3 -> type = (enum V_150 )
F_72 ( & V_136 -> V_20 ) ;
V_25 = & V_26 [ V_3 -> type ] ;
} else if ( V_138 ) {
V_25 = & V_26 [ V_138 -> V_151 ] ;
V_3 -> type = V_138 -> V_151 ;
} else {
const struct V_152 * V_153 ;
V_153 = F_73 ( F_74 ( V_154 ) ,
V_3 -> V_20 ) ;
if ( ! V_153 )
return - V_140 ;
V_25 = & V_26 [ V_153 -> V_151 ] ;
V_3 -> type = V_153 -> V_151 ;
}
V_142 = V_136 -> V_1 > 0 && V_25 -> V_155 ;
if ( ! V_145 )
V_148 = F_36 ( V_3 , V_25 ) ;
else if ( V_145 -> V_148 )
V_148 = V_145 -> V_148 ;
if ( V_148 && V_25 -> V_156 ) {
V_148 |= V_157 ;
F_12 ( V_3 -> V_20 ,
L_29 ,
V_148 , V_25 -> V_156 ) ;
F_4 ( V_3 -> V_10 , V_25 -> V_156 ,
V_148 ) ;
}
#ifdef F_75
if ( V_25 -> V_155 && F_76 ( V_136 -> V_20 . V_123 ,
L_30 ) )
V_143 = true ;
#endif
switch ( V_3 -> type ) {
case V_158 :
case V_159 :
case V_160 :
case V_103 :
V_139 = F_10 ( V_3 -> V_10 , V_14 ,
V_27 , 2 ) ;
if ( V_139 ) {
F_12 ( V_3 -> V_20 , L_31 , V_139 ) ;
goto exit;
}
if ( V_27 [ 0 ] & V_161 )
V_27 [ 0 ] &= ~ V_161 ;
if ( V_142 || V_143 ) {
V_27 [ 0 ] |= V_118 | V_25 -> V_162 ;
V_27 [ 0 ] &= ~ ( V_62 | V_15 ) ;
}
F_4 ( V_3 -> V_10 , V_14 ,
V_27 [ 0 ] ) ;
if ( V_27 [ 1 ] & V_163 ) {
F_4 ( V_3 -> V_10 , V_11 ,
V_27 [ 1 ] & ~ V_163 ) ;
F_35 ( V_3 -> V_20 , L_32 ) ;
}
break;
case V_164 :
V_139 = F_10 ( V_3 -> V_10 ,
V_165 << 4 | 0x08 , V_27 , 2 ) ;
if ( V_139 ) {
F_12 ( V_3 -> V_20 , L_31 , V_139 ) ;
goto exit;
}
if ( ! ( V_27 [ 1 ] & V_166 ) ) {
V_27 [ 1 ] |= V_166 ;
F_4 ( V_3 -> V_10 ,
V_167 << 4 | 0x08 ,
V_27 [ 1 ] ) ;
F_35 ( V_3 -> V_20 ,
L_33 ) ;
}
if ( V_27 [ 1 ] & V_168 ) {
V_27 [ 1 ] &= ~ V_168 ;
F_4 ( V_3 -> V_10 ,
V_167 << 4 | 0x08 ,
V_27 [ 1 ] ) ;
F_35 ( V_3 -> V_20 , L_34 ) ;
}
if ( V_27 [ 1 ] & V_169 ) {
V_27 [ 1 ] &= ~ V_169 ;
F_4 ( V_3 -> V_10 ,
V_167 << 4 | 0x08 ,
V_27 [ 1 ] ) ;
F_35 ( V_3 -> V_20 , L_35 ) ;
}
if ( ! ( V_27 [ 0 ] & V_170 ) ) {
T_2 V_171 ;
F_4 ( V_3 -> V_10 ,
V_165 << 4 | 0x08 ,
V_27 [ 0 ] | V_170 ) ;
V_139 = F_10 ( V_3 -> V_10 ,
V_165 << 4 | 0x08 ,
V_27 , 2 ) ;
if ( V_139 ) {
F_12 ( V_3 -> V_20 , L_31 , V_139 ) ;
goto exit;
}
V_171 = F_14 ( V_27 [ V_36 ] ) ;
if ( V_171 == 12 )
V_171 = 0 ;
if ( V_27 [ V_36 ] & V_172 )
V_171 += 12 ;
F_4 ( V_3 -> V_10 ,
V_36 << 4 | 0x08 , V_171 ) ;
}
break;
default:
break;
}
V_173:
V_139 = F_10 ( V_3 -> V_10 , V_25 -> V_28 , V_27 ,
sizeof( V_27 ) ) ;
if ( V_139 ) {
F_12 ( V_3 -> V_20 , L_31 , V_139 ) ;
goto exit;
}
V_23 = V_27 [ V_34 ] ;
switch ( V_3 -> type ) {
case V_174 :
case V_29 :
case V_175 :
if ( V_23 & V_176 ) {
F_4 ( V_3 -> V_10 , V_34 , 0 ) ;
F_35 ( V_3 -> V_20 , L_32 ) ;
goto V_173;
}
break;
case V_177 :
case V_178 :
if ( V_23 & V_176 )
F_4 ( V_3 -> V_10 , V_34 , 0 ) ;
if ( V_27 [ V_179 ] & V_180 ) {
F_4 ( V_3 -> V_10 , V_179 ,
V_27 [ V_179 ] &
~ V_180 ) ;
F_35 ( V_3 -> V_20 , L_32 ) ;
goto V_173;
}
break;
case V_181 :
if ( V_23 & V_182 )
F_4 ( V_3 -> V_10 , V_34 , 0 ) ;
V_139 = F_3 ( V_3 -> V_10 , V_183 , & V_23 ) ;
if ( V_139 ) {
F_12 ( V_3 -> V_20 , L_31 , V_139 ) ;
goto exit;
}
if ( V_23 & V_184 ) {
F_4 ( V_3 -> V_10 , V_183 , 0 ) ;
F_35 ( V_3 -> V_20 , L_32 ) ;
}
break;
case V_51 :
if ( ! ( V_27 [ V_39 ] & V_53 ) ) {
F_4 ( V_3 -> V_10 , V_39 ,
V_27 [ V_39 ] |
V_53 ) ;
}
if ( ! ( V_23 & V_52 ) ) {
F_4 ( V_3 -> V_10 , V_34 ,
V_52 ) ;
F_35 ( V_3 -> V_20 , L_32 ) ;
goto V_173;
}
break;
default:
break;
}
V_23 = V_27 [ V_36 ] ;
switch ( V_3 -> type ) {
case V_181 :
case V_29 :
case V_175 :
break;
case V_164 :
break;
default:
if ( ! ( V_23 & V_185 ) )
break;
V_23 = F_14 ( V_23 & 0x1f ) ;
if ( V_23 == 12 )
V_23 = 0 ;
if ( V_27 [ V_36 ] & V_172 )
V_23 += 12 ;
F_4 ( V_3 -> V_10 , V_25 -> V_28 + V_36 ,
F_18 ( V_23 ) ) ;
}
F_8 ( V_3 -> V_20 , & V_146 ) ;
V_141 = V_146 . V_38 ;
V_147 = F_77 ( & V_146 ) ;
F_78 ( V_147 , & V_146 ) ;
if ( V_141 != V_146 . V_38 )
F_5 ( V_3 -> V_10 , V_186 ,
V_187 ,
V_146 . V_38 + 1 ) ;
if ( V_142 || V_143 ) {
F_79 ( V_3 -> V_20 , true ) ;
F_80 ( V_55 , & V_3 -> V_56 ) ;
}
V_3 -> V_6 = F_81 ( V_3 -> V_20 ) ;
if ( F_43 ( V_3 -> V_6 ) )
return F_44 ( V_3 -> V_6 ) ;
if ( V_143 && ! V_142 ) {
F_82 ( V_3 -> V_20 ,
L_36 ) ;
V_3 -> V_6 -> V_188 = 1 ;
}
if ( V_142 ) {
V_139 = F_83 ( V_3 -> V_20 , V_136 -> V_1 , NULL ,
V_25 -> V_189 ? : F_1 ,
V_190 | V_191 ,
V_3 -> V_104 , V_3 ) ;
if ( V_139 ) {
V_136 -> V_1 = 0 ;
F_79 ( V_3 -> V_20 , false ) ;
F_84 ( V_55 , & V_3 -> V_56 ) ;
F_11 ( V_3 -> V_20 , L_37 ) ;
} else {
F_12 ( V_3 -> V_20 , L_38 , V_136 -> V_1 ) ;
}
}
if ( V_25 -> V_192 ) {
V_3 -> V_193 . V_104 = L_39 ;
V_3 -> V_193 . V_194 = 1 ;
V_3 -> V_193 . V_195 = 1 ;
V_3 -> V_193 . V_196 = V_25 -> V_192 ;
V_3 -> V_193 . V_197 = F_32 ;
V_3 -> V_193 . V_198 = F_33 ;
V_3 -> V_193 . V_83 = V_3 ;
V_3 -> V_6 -> V_199 = & V_3 -> V_193 ;
V_3 -> V_6 -> V_200 = true ;
}
V_3 -> V_6 -> V_201 = V_25 -> V_202 ? : & V_203 ;
V_139 = F_85 ( V_3 -> V_6 ) ;
if ( V_139 )
return V_139 ;
F_41 ( V_3 ) ;
F_66 ( V_3 ) ;
return 0 ;
exit:
return V_139 ;
}
