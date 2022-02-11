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
V_9 = F_10 ( V_3 -> V_10 , V_3 -> V_27 , V_3 -> V_28 , 7 ) ;
if ( V_9 ) {
F_11 ( V_20 , L_1 , L_2 , V_9 ) ;
return V_9 ;
}
F_12 ( V_20 , L_3 , L_2 , V_3 -> V_28 ) ;
if ( V_3 -> type == V_29 &&
V_3 -> V_28 [ V_30 ] & V_31 ) {
F_13 ( V_20 , L_4 ) ;
return - V_32 ;
}
V_22 -> V_33 = F_14 ( V_3 -> V_28 [ V_34 ] & 0x7f ) ;
V_22 -> V_35 = F_14 ( V_3 -> V_28 [ V_30 ] & 0x7f ) ;
V_23 = V_3 -> V_28 [ V_36 ] & 0x3f ;
V_22 -> V_37 = F_14 ( V_23 ) ;
V_22 -> V_38 = F_14 ( V_3 -> V_28 [ V_39 ] & 0x07 ) - 1 ;
V_22 -> V_40 = F_14 ( V_3 -> V_28 [ V_41 ] & 0x3f ) ;
V_23 = V_3 -> V_28 [ V_42 ] & 0x1f ;
V_22 -> V_43 = F_14 ( V_23 ) - 1 ;
V_22 -> V_44 = F_14 ( V_3 -> V_28 [ V_45 ] ) + 100 ;
if ( V_3 -> V_28 [ V_25 -> V_46 ] & V_25 -> V_47 &&
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
T_2 * V_50 = V_3 -> V_28 ;
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
V_50 [ V_34 ] = F_18 ( V_22 -> V_33 ) ;
V_50 [ V_30 ] = F_18 ( V_22 -> V_35 ) ;
V_50 [ V_36 ] = F_18 ( V_22 -> V_37 ) ;
V_50 [ V_39 ] = F_18 ( V_22 -> V_38 + 1 ) ;
V_50 [ V_41 ] = F_18 ( V_22 -> V_40 ) ;
V_50 [ V_42 ] = F_18 ( V_22 -> V_43 + 1 ) ;
V_23 = V_22 -> V_44 - 100 ;
V_50 [ V_45 ] = F_18 ( V_23 ) ;
if ( V_25 -> V_51 )
V_50 [ V_25 -> V_46 ] |= V_25 -> V_51 ;
if ( V_22 -> V_44 > 199 && V_25 -> V_47 )
V_50 [ V_25 -> V_46 ] |= V_25 -> V_47 ;
if ( V_3 -> type == V_52 ) {
V_50 [ V_34 ] |= V_53 ;
V_50 [ V_39 ] |= V_54 ;
}
F_12 ( V_20 , L_3 , L_7 , V_50 ) ;
V_49 = F_19 ( V_3 -> V_10 , V_3 -> V_27 , V_50 , 7 ) ;
if ( V_49 ) {
F_11 ( V_20 , L_1 , L_7 , V_49 ) ;
return V_49 ;
}
return 0 ;
}
static int F_20 ( struct V_19 * V_20 , struct V_55 * V_22 )
{
struct V_3 * V_3 = F_9 ( V_20 ) ;
int V_9 ;
if ( ! F_21 ( V_56 , & V_3 -> V_57 ) )
return - V_32 ;
V_9 = F_10 ( V_3 -> V_10 , V_58 ,
V_3 -> V_28 , 9 ) ;
if ( V_9 ) {
F_11 ( V_20 , L_1 , L_8 , V_9 ) ;
return V_9 ;
}
F_12 ( V_20 , L_9 , L_8 ,
& V_3 -> V_28 [ 0 ] , & V_3 -> V_28 [ 4 ] , & V_3 -> V_28 [ 7 ] ) ;
V_22 -> time . V_33 = F_14 ( V_3 -> V_28 [ 0 ] & 0x7f ) ;
V_22 -> time . V_35 = F_14 ( V_3 -> V_28 [ 1 ] & 0x7f ) ;
V_22 -> time . V_37 = F_14 ( V_3 -> V_28 [ 2 ] & 0x3f ) ;
V_22 -> time . V_40 = F_14 ( V_3 -> V_28 [ 3 ] & 0x3f ) ;
V_22 -> V_59 = ! ! ( V_3 -> V_28 [ 7 ] & V_15 ) ;
V_22 -> V_60 = ! ! ( V_3 -> V_28 [ 8 ] & V_13 ) ;
F_12 ( V_20 , L_5
L_10 ,
L_8 , V_22 -> time . V_33 , V_22 -> time . V_35 ,
V_22 -> time . V_37 , V_22 -> time . V_40 ,
V_22 -> V_59 , V_22 -> V_60 ) ;
return 0 ;
}
static int F_22 ( struct V_19 * V_20 , struct V_55 * V_22 )
{
struct V_3 * V_3 = F_9 ( V_20 ) ;
unsigned char * V_50 = V_3 -> V_28 ;
T_2 V_61 , V_62 ;
int V_9 ;
if ( ! F_21 ( V_56 , & V_3 -> V_57 ) )
return - V_32 ;
F_12 ( V_20 , L_5
L_10 ,
L_11 , V_22 -> time . V_33 , V_22 -> time . V_35 ,
V_22 -> time . V_37 , V_22 -> time . V_40 ,
V_22 -> V_59 , V_22 -> V_60 ) ;
V_9 = F_10 ( V_3 -> V_10 , V_58 , V_50 , 9 ) ;
if ( V_9 ) {
F_11 ( V_20 , L_1 , L_12 , V_9 ) ;
return V_9 ;
}
V_61 = V_3 -> V_28 [ 7 ] ;
V_62 = V_3 -> V_28 [ 8 ] ;
F_12 ( V_20 , L_13 , L_14 ,
& V_3 -> V_28 [ 0 ] , & V_3 -> V_28 [ 4 ] , V_61 , V_62 ) ;
V_50 [ 0 ] = F_18 ( V_22 -> time . V_33 ) ;
V_50 [ 1 ] = F_18 ( V_22 -> time . V_35 ) ;
V_50 [ 2 ] = F_18 ( V_22 -> time . V_37 ) ;
V_50 [ 3 ] = F_18 ( V_22 -> time . V_40 ) ;
V_50 [ 4 ] = 0 ;
V_50 [ 5 ] = 0 ;
V_50 [ 6 ] = 0 ;
V_50 [ 7 ] = V_61 & ~ ( V_15 | V_63 ) ;
V_50 [ 8 ] = V_62 & ~ ( V_13 | V_64 ) ;
V_9 = F_19 ( V_3 -> V_10 , V_58 , V_50 , 9 ) ;
if ( V_9 ) {
F_11 ( V_20 , L_15 ) ;
return V_9 ;
}
if ( V_22 -> V_59 ) {
F_12 ( V_20 , L_16 ) ;
V_50 [ 7 ] |= V_15 ;
F_4 ( V_3 -> V_10 , V_14 , V_50 [ 7 ] ) ;
}
return 0 ;
}
static int F_23 ( struct V_19 * V_20 , unsigned int V_59 )
{
struct V_3 * V_3 = F_9 ( V_20 ) ;
if ( ! F_21 ( V_56 , & V_3 -> V_57 ) )
return - V_65 ;
return F_5 ( V_3 -> V_10 , V_14 ,
V_15 ,
V_59 ? V_15 : 0 ) ;
}
static T_1 F_24 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
struct V_4 * V_5 = & V_3 -> V_6 -> V_7 ;
T_2 V_66 [ 3 ] ;
int V_9 ;
F_2 ( V_5 ) ;
V_9 = F_10 ( V_3 -> V_10 , V_67 , V_66 , 3 ) ;
if ( V_9 < 0 )
goto V_12;
if ( ! ( V_66 [ 1 ] & V_68 ) )
goto V_12;
V_66 [ 1 ] &= ~ V_68 ;
V_66 [ 2 ] &= ~ V_69 ;
V_9 = F_19 ( V_3 -> V_10 , V_67 , V_66 , 3 ) ;
if ( V_9 < 0 )
goto V_12;
F_6 ( V_3 -> V_6 , 1 , V_16 | V_17 ) ;
V_12:
F_7 ( V_5 ) ;
return V_18 ;
}
static int F_25 ( struct V_19 * V_20 , struct V_55 * V_22 )
{
struct V_3 * V_3 = F_9 ( V_20 ) ;
T_2 V_70 [ 3 ] , V_66 [ 3 ] ;
int V_9 ;
if ( ! F_21 ( V_56 , & V_3 -> V_57 ) )
return - V_32 ;
V_9 = F_10 ( V_3 -> V_10 , V_71 , V_70 , 3 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_10 ( V_3 -> V_10 , V_67 , V_66 , 3 ) ;
if ( V_9 < 0 )
return V_9 ;
V_22 -> V_59 = ! ! ( V_66 [ 2 ] & V_69 ) ;
V_22 -> V_60 = ! ! ( V_66 [ 1 ] & V_68 ) ;
V_22 -> time . V_33 = - 1 ;
V_22 -> time . V_35 = F_14 ( V_70 [ 0 ] & 0x7f ) ;
V_22 -> time . V_37 = F_14 ( V_70 [ 1 ] & 0x7f ) ;
V_22 -> time . V_38 = - 1 ;
V_22 -> time . V_40 = F_14 ( V_70 [ 2 ] & 0x7f ) ;
V_22 -> time . V_43 = - 1 ;
V_22 -> time . V_44 = - 1 ;
V_22 -> time . V_72 = - 1 ;
V_22 -> time . V_73 = - 1 ;
F_12 ( V_20 , L_17 ,
V_74 , V_22 -> time . V_33 , V_22 -> time . V_35 , V_22 -> time . V_37 ,
V_22 -> time . V_38 , V_22 -> time . V_40 , V_22 -> time . V_43 , V_22 -> V_59 ) ;
return 0 ;
}
static int F_26 ( struct V_19 * V_20 , struct V_55 * V_22 )
{
struct V_3 * V_3 = F_9 ( V_20 ) ;
T_2 V_70 [ 3 ] , V_66 [ 3 ] ;
int V_9 ;
if ( ! F_21 ( V_56 , & V_3 -> V_57 ) )
return - V_32 ;
F_12 ( V_20 , L_18
L_19 , V_74 ,
V_22 -> time . V_33 , V_22 -> time . V_35 , V_22 -> time . V_37 ,
V_22 -> time . V_38 , V_22 -> time . V_40 , V_22 -> time . V_43 ,
V_22 -> V_59 , V_22 -> V_60 ) ;
V_9 = F_10 ( V_3 -> V_10 , V_67 , V_66 , 3 ) ;
if ( V_9 < 0 )
return V_9 ;
V_66 [ 0 ] &= ~ V_75 ;
V_66 [ 1 ] |= V_68 ;
V_66 [ 2 ] &= ~ V_69 ;
V_9 = F_19 ( V_3 -> V_10 , V_67 , V_66 , 3 ) ;
if ( V_9 < 0 )
return V_9 ;
V_70 [ 0 ] = F_18 ( V_22 -> time . V_35 ) ;
V_70 [ 1 ] = F_18 ( V_22 -> time . V_37 ) ;
V_70 [ 2 ] = F_18 ( V_22 -> time . V_40 ) ;
V_9 = F_19 ( V_3 -> V_10 , V_71 , V_70 , 3 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( ! V_22 -> V_59 )
return 0 ;
V_66 [ 2 ] |= V_69 ;
return F_19 ( V_3 -> V_10 , V_67 , V_66 , 3 ) ;
}
static int F_27 ( struct V_19 * V_20 , unsigned int V_59 )
{
struct V_3 * V_3 = F_9 ( V_20 ) ;
int V_9 , V_76 ;
if ( ! F_21 ( V_56 , & V_3 -> V_57 ) )
return - V_32 ;
V_9 = F_3 ( V_3 -> V_10 , V_77 , & V_76 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_59 )
V_76 |= V_69 ;
else
V_76 &= ~ V_69 ;
return F_4 ( V_3 -> V_10 , V_77 , V_76 ) ;
}
static T_1 F_28 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
struct V_4 * V_5 = & V_3 -> V_6 -> V_7 ;
int V_76 , V_9 ;
F_2 ( V_5 ) ;
V_9 = F_3 ( V_3 -> V_10 , V_78 , & V_76 ) ;
if ( V_9 )
goto V_12;
if ( ! ( V_76 & V_79 ) )
goto V_12;
V_76 &= ~ V_79 ;
V_9 = F_4 ( V_3 -> V_10 , V_78 , V_76 ) ;
if ( V_9 )
goto V_12;
V_9 = F_5 ( V_3 -> V_10 , V_80 ,
V_81 , 0 ) ;
if ( V_9 )
goto V_12;
F_6 ( V_3 -> V_6 , 1 , V_16 | V_17 ) ;
V_12:
F_7 ( V_5 ) ;
return V_18 ;
}
static int F_29 ( struct V_19 * V_20 , struct V_55 * V_22 )
{
struct V_3 * V_3 = F_9 ( V_20 ) ;
T_2 * V_28 = V_3 -> V_28 ;
int V_9 ;
if ( ! F_21 ( V_56 , & V_3 -> V_57 ) )
return - V_32 ;
V_9 = F_10 ( V_3 -> V_10 , V_80 , V_28 , 10 ) ;
if ( V_9 )
return V_9 ;
V_22 -> V_59 = ! ! ( V_28 [ 0 ] & V_81 ) ;
V_22 -> time . V_33 = F_14 ( V_3 -> V_28 [ 3 ] & 0x7f ) ;
V_22 -> time . V_35 = F_14 ( V_3 -> V_28 [ 4 ] & 0x7f ) ;
V_22 -> time . V_37 = F_14 ( V_3 -> V_28 [ 5 ] & 0x3f ) ;
V_22 -> time . V_38 = F_14 ( V_3 -> V_28 [ 6 ] & 0x7 ) - 1 ;
V_22 -> time . V_40 = F_14 ( V_3 -> V_28 [ 7 ] & 0x3f ) ;
V_22 -> time . V_43 = F_14 ( V_3 -> V_28 [ 8 ] & 0x1f ) - 1 ;
V_22 -> time . V_44 = - 1 ;
V_22 -> time . V_72 = - 1 ;
V_22 -> time . V_73 = - 1 ;
F_12 ( V_20 , L_18
L_20 , V_74 ,
V_22 -> time . V_33 , V_22 -> time . V_35 , V_22 -> time . V_37 ,
V_22 -> time . V_38 , V_22 -> time . V_40 , V_22 -> time . V_43 , V_22 -> V_59 ,
! ! ( V_3 -> V_28 [ 6 ] & V_82 ) ,
! ! ( V_3 -> V_28 [ 6 ] & V_79 ) ,
( V_3 -> V_28 [ 6 ] & V_83 ) >> 4 ) ;
return 0 ;
}
static int F_30 ( struct V_19 * V_20 , struct V_55 * V_22 )
{
struct V_3 * V_3 = F_9 ( V_20 ) ;
unsigned char * V_28 = V_3 -> V_28 ;
int V_9 ;
if ( ! F_21 ( V_56 , & V_3 -> V_57 ) )
return - V_32 ;
F_12 ( V_20 , L_18
L_19 , V_74 ,
V_22 -> time . V_33 , V_22 -> time . V_35 , V_22 -> time . V_37 ,
V_22 -> time . V_38 , V_22 -> time . V_40 , V_22 -> time . V_43 ,
V_22 -> V_59 , V_22 -> V_60 ) ;
V_9 = F_10 ( V_3 -> V_10 , V_80 , V_28 , 10 ) ;
if ( V_9 )
return V_9 ;
V_28 [ 3 ] = F_18 ( V_22 -> time . V_33 ) ;
V_28 [ 4 ] = F_18 ( V_22 -> time . V_35 ) ;
V_28 [ 5 ] = F_18 ( V_22 -> time . V_37 ) ;
V_28 [ 6 ] = F_18 ( V_22 -> time . V_38 + 1 ) ;
V_28 [ 7 ] = F_18 ( V_22 -> time . V_40 ) ;
V_28 [ 8 ] = F_18 ( V_22 -> time . V_43 + 1 ) ;
V_28 [ 6 ] &= ~ V_79 ;
V_28 [ 6 ] |= V_83 ;
V_28 [ 0 ] &= ~ V_81 ;
V_9 = F_19 ( V_3 -> V_10 , V_80 , V_28 , 10 ) ;
if ( V_9 )
return V_9 ;
if ( ! V_22 -> V_59 )
return 0 ;
V_28 [ 0 ] |= V_81 ;
return F_4 ( V_3 -> V_10 , V_80 , V_28 [ 0 ] ) ;
}
static int F_31 ( struct V_19 * V_20 , unsigned int V_59 )
{
struct V_3 * V_3 = F_9 ( V_20 ) ;
if ( ! F_21 ( V_56 , & V_3 -> V_57 ) )
return - V_32 ;
return F_5 ( V_3 -> V_10 , V_80 ,
V_81 ,
V_59 ? V_81 : 0 ) ;
}
static int F_32 ( void * V_84 , unsigned int V_27 , void * V_85 ,
T_3 V_86 )
{
struct V_3 * V_3 = V_84 ;
return F_10 ( V_3 -> V_10 , V_3 -> V_87 + V_27 ,
V_85 , V_86 ) ;
}
static int F_33 ( void * V_84 , unsigned int V_27 , void * V_85 ,
T_3 V_86 )
{
struct V_3 * V_3 = V_84 ;
return F_19 ( V_3 -> V_10 , V_3 -> V_87 + V_27 ,
V_85 , V_86 ) ;
}
static T_2 F_34 ( struct V_3 * V_3 ,
T_4 V_88 , bool V_89 )
{
T_2 V_90 = ( V_89 ) ? V_91 :
V_92 ;
switch ( V_88 ) {
case 250 :
V_90 |= V_93 ;
break;
case 2000 :
V_90 |= V_94 ;
break;
case 4000 :
V_90 |= V_95 ;
break;
default:
F_35 ( V_3 -> V_20 ,
L_21 , V_88 ) ;
return 0 ;
}
return V_90 ;
}
static void F_36 ( struct V_3 * V_3 ,
struct V_24 * V_25 )
{
T_4 V_88 = 0 ;
bool V_89 = true ;
if ( ! V_25 -> V_96 )
goto V_12;
if ( F_37 ( V_3 -> V_20 , L_22 ,
& V_88 ) )
goto V_12;
if ( F_38 ( V_3 -> V_20 , L_23 ) )
V_89 = false ;
V_25 -> V_97 = V_25 -> V_96 ( V_3 ,
V_88 , V_89 ) ;
V_12:
return;
}
static int F_39 ( struct V_19 * V_20 , T_5 * V_98 )
{
struct V_3 * V_3 = F_9 ( V_20 ) ;
T_2 V_99 [ 2 ] ;
T_6 V_100 ;
int V_9 ;
V_9 = F_10 ( V_3 -> V_10 , V_101 ,
V_99 , sizeof( V_99 ) ) ;
if ( V_9 )
return V_9 ;
V_100 = ( V_99 [ 0 ] << 8 ) | V_99 [ 1 ] ;
V_100 >>= 6 ;
* V_98 = V_100 * 250 ;
return 0 ;
}
static T_7 F_40 ( struct V_19 * V_20 ,
struct V_102 * V_103 , char * V_50 )
{
int V_9 ;
T_5 V_100 ;
V_9 = F_39 ( V_20 , & V_100 ) ;
if ( V_9 )
return V_9 ;
return sprintf ( V_50 , L_24 , V_100 ) ;
}
static void F_41 ( struct V_3 * V_3 )
{
struct V_19 * V_20 ;
if ( V_3 -> type != V_104 )
return;
V_20 = F_42 ( V_3 -> V_20 , V_3 -> V_105 ,
V_3 , V_106 ) ;
if ( F_43 ( V_20 ) ) {
F_35 ( V_3 -> V_20 , L_25 ,
F_44 ( V_20 ) ) ;
}
}
static void F_41 ( struct V_3 * V_3 )
{
}
static int F_45 ( struct V_3 * V_3 , T_2 V_107 , T_2 V_108 )
{
struct V_4 * V_5 = & V_3 -> V_6 -> V_7 ;
int V_9 ;
F_2 ( V_5 ) ;
V_9 = F_5 ( V_3 -> V_10 , V_14 ,
V_107 , V_108 ) ;
F_7 ( V_5 ) ;
return V_9 ;
}
static unsigned long F_46 ( struct V_109 * V_110 ,
unsigned long V_111 )
{
struct V_3 * V_3 = F_47 ( V_110 ) ;
int V_61 , V_9 ;
int V_112 = 0 ;
V_9 = F_3 ( V_3 -> V_10 , V_14 , & V_61 ) ;
if ( V_9 )
return V_9 ;
if ( V_61 & V_113 )
V_112 += 1 ;
if ( V_61 & V_114 )
V_112 += 2 ;
return V_115 [ V_112 ] ;
}
static long F_48 ( struct V_109 * V_110 , unsigned long V_116 ,
unsigned long * V_117 )
{
int V_118 ;
for ( V_118 = F_49 ( V_115 ) - 1 ; V_118 >= 0 ; V_118 -- ) {
if ( V_115 [ V_118 ] <= V_116 )
return V_115 [ V_118 ] ;
}
return 0 ;
}
static int F_50 ( struct V_109 * V_110 , unsigned long V_116 ,
unsigned long V_111 )
{
struct V_3 * V_3 = F_47 ( V_110 ) ;
int V_61 = 0 ;
int V_112 ;
for ( V_112 = 0 ; V_112 < F_49 ( V_115 ) ;
V_112 ++ ) {
if ( V_115 [ V_112 ] == V_116 )
break;
}
if ( V_112 == F_49 ( V_115 ) )
return - V_32 ;
if ( V_112 & 1 )
V_61 |= V_113 ;
if ( V_112 & 2 )
V_61 |= V_114 ;
return F_45 ( V_3 , V_113 | V_114 ,
V_61 ) ;
}
static int F_51 ( struct V_109 * V_110 )
{
struct V_3 * V_3 = F_47 ( V_110 ) ;
return F_45 ( V_3 , V_119 , 0 ) ;
}
static void F_52 ( struct V_109 * V_110 )
{
struct V_3 * V_3 = F_47 ( V_110 ) ;
F_45 ( V_3 , V_119 , V_119 ) ;
}
static int F_53 ( struct V_109 * V_110 )
{
struct V_3 * V_3 = F_47 ( V_110 ) ;
int V_61 , V_9 ;
V_9 = F_3 ( V_3 -> V_10 , V_14 , & V_61 ) ;
if ( V_9 )
return V_9 ;
return ! ( V_61 & V_119 ) ;
}
static unsigned long F_54 ( struct V_109 * V_110 ,
unsigned long V_111 )
{
return 32768 ;
}
static int F_55 ( struct V_3 * V_3 , bool V_120 )
{
struct V_4 * V_5 = & V_3 -> V_6 -> V_7 ;
int V_9 ;
F_2 ( V_5 ) ;
V_9 = F_5 ( V_3 -> V_10 , V_11 ,
V_121 ,
V_120 ? V_121 : 0 ) ;
F_7 ( V_5 ) ;
return V_9 ;
}
static int F_56 ( struct V_109 * V_110 )
{
struct V_3 * V_3 = F_57 ( V_110 ) ;
return F_55 ( V_3 , true ) ;
}
static void F_58 ( struct V_109 * V_110 )
{
struct V_3 * V_3 = F_57 ( V_110 ) ;
F_55 ( V_3 , false ) ;
}
static int F_59 ( struct V_109 * V_110 )
{
struct V_3 * V_3 = F_57 ( V_110 ) ;
int V_62 , V_9 ;
V_9 = F_3 ( V_3 -> V_10 , V_11 , & V_62 ) ;
if ( V_9 )
return V_9 ;
return ! ! ( V_62 & V_121 ) ;
}
static int F_60 ( struct V_3 * V_3 )
{
struct V_122 * V_123 = V_3 -> V_20 -> V_124 ;
struct V_125 * V_126 ;
int V_118 ;
V_126 = F_61 ( V_3 -> V_20 , sizeof( * V_126 ) , V_127 ) ;
if ( ! V_126 )
return - V_128 ;
V_126 -> V_129 = F_49 ( V_130 ) ;
V_126 -> V_131 = F_62 ( V_3 -> V_20 , V_126 -> V_129 ,
sizeof( V_126 -> V_131 [ 0 ] ) , V_127 ) ;
if ( ! V_126 -> V_131 )
return - V_128 ;
for ( V_118 = 0 ; V_118 < F_49 ( V_130 ) ; V_118 ++ ) {
struct V_132 V_133 = V_130 [ V_118 ] ;
if ( V_118 == V_134 && F_21 ( V_56 , & V_3 -> V_57 ) )
continue;
F_63 ( V_123 , L_26 , V_118 ,
& V_133 . V_105 ) ;
V_3 -> V_131 [ V_118 ] . V_133 = & V_133 ;
V_126 -> V_131 [ V_118 ] = F_64 ( V_3 -> V_20 ,
& V_3 -> V_131 [ V_118 ] ) ;
if ( F_43 ( V_126 -> V_131 [ V_118 ] ) )
return F_44 ( V_126 -> V_131 [ V_118 ] ) ;
}
if ( ! V_123 )
return 0 ;
F_65 ( V_123 , V_135 , V_126 ) ;
return 0 ;
}
static void F_66 ( struct V_3 * V_3 )
{
int V_9 ;
if ( V_3 -> type != V_104 )
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
static int F_67 ( struct V_136 * V_137 ,
const struct V_138 * V_139 )
{
struct V_3 * V_3 ;
int V_140 = - V_141 ;
int V_23 , V_142 ;
struct V_24 * V_25 ;
bool V_143 = false ;
bool V_144 = false ;
unsigned char * V_50 ;
struct V_145 * V_146 = F_68 ( & V_137 -> V_20 ) ;
struct V_21 V_147 ;
unsigned long V_148 ;
T_8 V_149 = F_1 ;
static const int V_150 [] = {
[ V_151 ] = 0 ,
[ V_152 ] = V_153 ,
[ V_104 ] = V_154 ,
} ;
const struct V_155 * V_156 = & V_157 ;
V_3 = F_61 ( & V_137 -> V_20 , sizeof( struct V_3 ) , V_127 ) ;
if ( ! V_3 )
return - V_128 ;
F_69 ( & V_137 -> V_20 , V_3 ) ;
V_3 -> V_20 = & V_137 -> V_20 ;
V_3 -> V_105 = V_137 -> V_105 ;
V_3 -> V_1 = V_137 -> V_1 ;
V_3 -> V_10 = F_70 ( V_137 , & V_158 ) ;
if ( F_43 ( V_3 -> V_10 ) ) {
F_11 ( V_3 -> V_20 , L_28 ) ;
return F_44 ( V_3 -> V_10 ) ;
}
F_71 ( V_137 , V_3 ) ;
if ( V_137 -> V_20 . V_124 ) {
V_3 -> type = (enum V_159 )
F_72 ( & V_137 -> V_20 ) ;
V_25 = & V_26 [ V_3 -> type ] ;
} else if ( V_139 ) {
V_25 = & V_26 [ V_139 -> V_160 ] ;
V_3 -> type = V_139 -> V_160 ;
} else {
const struct V_161 * V_162 ;
V_162 = F_73 ( F_74 ( V_163 ) ,
V_3 -> V_20 ) ;
if ( ! V_162 )
return - V_141 ;
V_25 = & V_26 [ V_162 -> V_160 ] ;
V_3 -> type = V_162 -> V_160 ;
}
if ( ! V_146 )
F_36 ( V_3 , V_25 ) ;
else if ( V_146 -> V_97 )
V_25 -> V_97 = V_146 -> V_97 ;
if ( V_25 -> V_97 && V_25 -> V_164 ) {
F_12 ( V_3 -> V_20 ,
L_29 ,
V_165 | V_25 -> V_97 ,
V_25 -> V_164 ) ;
F_4 ( V_3 -> V_10 , V_25 -> V_164 ,
V_165 |
V_25 -> V_97 ) ;
}
V_50 = V_3 -> V_28 ;
#ifdef F_75
if ( F_76 ( V_137 -> V_20 . V_124 , L_30 ) ) {
V_144 = true ;
}
if ( F_76 ( V_137 -> V_20 . V_124 ,
L_31 ) ) {
V_144 = true ;
}
#endif
switch ( V_3 -> type ) {
case V_151 :
case V_152 :
case V_104 :
V_140 = F_10 ( V_3 -> V_10 , V_14 ,
V_50 , 2 ) ;
if ( V_140 ) {
F_12 ( V_3 -> V_20 , L_32 , V_140 ) ;
goto exit;
}
if ( V_3 -> V_28 [ 0 ] & V_166 )
V_3 -> V_28 [ 0 ] &= ~ V_166 ;
if ( V_25 -> V_167 && ( V_3 -> V_1 > 0 ||
V_144 ) ) {
V_3 -> V_28 [ 0 ] |= V_119
| V_150 [ V_3 -> type ] ;
V_3 -> V_28 [ 0 ] &= ~ ( V_63 | V_15 ) ;
V_143 = true ;
}
F_4 ( V_3 -> V_10 , V_14 ,
V_3 -> V_28 [ 0 ] ) ;
if ( V_3 -> V_28 [ 1 ] & V_168 ) {
F_4 ( V_3 -> V_10 , V_11 ,
V_3 -> V_28 [ 1 ] & ~ V_168 ) ;
F_35 ( V_3 -> V_20 , L_33 ) ;
}
break;
case V_169 :
V_140 = F_10 ( V_3 -> V_10 ,
V_170 << 4 | 0x08 , V_50 , 2 ) ;
if ( V_140 ) {
F_12 ( V_3 -> V_20 , L_32 , V_140 ) ;
goto exit;
}
if ( ! ( V_3 -> V_28 [ 1 ] & V_171 ) ) {
V_3 -> V_28 [ 1 ] |= V_171 ;
F_4 ( V_3 -> V_10 ,
V_172 << 4 | 0x08 ,
V_3 -> V_28 [ 1 ] ) ;
F_35 ( V_3 -> V_20 ,
L_34 ) ;
}
if ( V_3 -> V_28 [ 1 ] & V_173 ) {
V_3 -> V_28 [ 1 ] &= ~ V_173 ;
F_4 ( V_3 -> V_10 ,
V_172 << 4 | 0x08 ,
V_3 -> V_28 [ 1 ] ) ;
F_35 ( V_3 -> V_20 , L_35 ) ;
}
if ( V_3 -> V_28 [ 1 ] & V_174 ) {
V_3 -> V_28 [ 1 ] &= ~ V_174 ;
F_4 ( V_3 -> V_10 ,
V_172 << 4 | 0x08 ,
V_3 -> V_28 [ 1 ] ) ;
F_35 ( V_3 -> V_20 , L_36 ) ;
}
if ( ! ( V_3 -> V_28 [ 0 ] & V_175 ) ) {
T_2 V_176 ;
F_4 ( V_3 -> V_10 ,
V_170 << 4 | 0x08 ,
V_3 -> V_28 [ 0 ] | V_175 ) ;
V_140 = F_10 ( V_3 -> V_10 ,
V_170 << 4 | 0x08 ,
V_50 , 2 ) ;
if ( V_140 ) {
F_12 ( V_3 -> V_20 , L_32 , V_140 ) ;
goto exit;
}
V_176 = F_14 ( V_3 -> V_28 [ V_36 ] ) ;
if ( V_176 == 12 )
V_176 = 0 ;
if ( V_3 -> V_28 [ V_36 ] & V_177 )
V_176 += 12 ;
F_4 ( V_3 -> V_10 ,
V_36 << 4 | 0x08 , V_176 ) ;
}
break;
case V_178 :
V_3 -> V_27 = 0x10 ;
V_156 = & V_179 ;
if ( V_25 -> V_167 && V_3 -> V_1 > 0 ) {
V_149 = F_24 ;
V_143 = true ;
}
break;
case V_180 :
V_3 -> V_27 = 1 ;
break;
case V_52 :
V_156 = & V_181 ;
if ( V_25 -> V_167 && ( V_3 -> V_1 > 0 ||
V_144 ) ) {
V_149 = F_28 ;
V_143 = true ;
}
break;
default:
break;
}
V_182:
V_140 = F_10 ( V_3 -> V_10 , V_3 -> V_27 , V_50 , 8 ) ;
if ( V_140 ) {
F_12 ( V_3 -> V_20 , L_32 , V_140 ) ;
goto exit;
}
V_23 = V_3 -> V_28 [ V_34 ] ;
switch ( V_3 -> type ) {
case V_183 :
case V_29 :
case V_184 :
if ( V_23 & V_185 ) {
F_4 ( V_3 -> V_10 , V_34 , 0 ) ;
F_35 ( V_3 -> V_20 , L_33 ) ;
goto V_182;
}
break;
case V_186 :
case V_187 :
if ( V_23 & V_185 )
F_4 ( V_3 -> V_10 , V_34 , 0 ) ;
if ( V_3 -> V_28 [ V_188 ] & V_189 ) {
F_4 ( V_3 -> V_10 , V_188 ,
V_3 -> V_28 [ V_188 ] &
~ V_189 ) ;
F_35 ( V_3 -> V_20 , L_33 ) ;
goto V_182;
}
break;
case V_190 :
if ( V_23 & V_191 )
F_4 ( V_3 -> V_10 , V_34 , 0 ) ;
V_140 = F_3 ( V_3 -> V_10 , V_192 , & V_23 ) ;
if ( V_140 ) {
F_12 ( V_3 -> V_20 , L_32 , V_140 ) ;
goto exit;
}
if ( V_23 & V_193 ) {
F_4 ( V_3 -> V_10 , V_192 , 0 ) ;
F_35 ( V_3 -> V_20 , L_33 ) ;
}
break;
case V_52 :
if ( ! ( V_3 -> V_28 [ V_39 ] & V_54 ) ) {
F_4 ( V_3 -> V_10 , V_39 ,
V_3 -> V_28 [ V_39 ] |
V_54 ) ;
}
if ( ! ( V_23 & V_53 ) ) {
F_4 ( V_3 -> V_10 , V_34 ,
V_53 ) ;
F_35 ( V_3 -> V_20 , L_33 ) ;
goto V_182;
}
break;
default:
break;
}
V_23 = V_3 -> V_28 [ V_36 ] ;
switch ( V_3 -> type ) {
case V_190 :
case V_29 :
case V_184 :
break;
case V_169 :
break;
default:
if ( ! ( V_23 & V_194 ) )
break;
V_23 = F_14 ( V_23 & 0x1f ) ;
if ( V_23 == 12 )
V_23 = 0 ;
if ( V_3 -> V_28 [ V_36 ] & V_177 )
V_23 += 12 ;
F_4 ( V_3 -> V_10 , V_3 -> V_27 + V_36 ,
F_18 ( V_23 ) ) ;
}
F_8 ( V_3 -> V_20 , & V_147 ) ;
V_142 = V_147 . V_38 ;
V_148 = F_77 ( & V_147 ) ;
F_78 ( V_148 , & V_147 ) ;
if ( V_142 != V_147 . V_38 )
F_5 ( V_3 -> V_10 , V_195 ,
V_196 ,
V_147 . V_38 + 1 ) ;
if ( V_143 ) {
F_79 ( V_3 -> V_20 , true ) ;
F_80 ( V_56 , & V_3 -> V_57 ) ;
}
V_3 -> V_6 = F_81 ( V_3 -> V_20 ) ;
if ( F_43 ( V_3 -> V_6 ) ) {
return F_44 ( V_3 -> V_6 ) ;
}
if ( V_144 && V_3 -> V_1 <= 0 ) {
V_143 = false ;
F_82 ( V_3 -> V_20 ,
L_37 ) ;
V_3 -> V_6 -> V_197 = 1 ;
}
if ( V_143 ) {
V_140 = F_83 ( V_3 -> V_20 ,
V_3 -> V_1 , NULL , V_149 ,
V_198 | V_199 ,
V_3 -> V_105 , V_3 ) ;
if ( V_140 ) {
V_137 -> V_1 = 0 ;
F_79 ( V_3 -> V_20 , false ) ;
F_84 ( V_56 , & V_3 -> V_57 ) ;
F_11 ( V_3 -> V_20 , L_38 ) ;
} else
F_12 ( V_3 -> V_20 , L_39 , V_137 -> V_1 ) ;
}
if ( V_25 -> V_200 ) {
V_3 -> V_201 . V_105 = L_40 ;
V_3 -> V_201 . V_202 = 1 ;
V_3 -> V_201 . V_203 = 1 ;
V_3 -> V_201 . V_204 = V_25 -> V_200 ;
V_3 -> V_201 . V_205 = F_32 ;
V_3 -> V_201 . V_206 = F_33 ;
V_3 -> V_201 . V_84 = V_3 ;
V_3 -> V_87 = V_25 -> V_87 ;
V_3 -> V_6 -> V_207 = & V_3 -> V_201 ;
V_3 -> V_6 -> V_208 = true ;
}
V_3 -> V_6 -> V_209 = V_156 ;
V_140 = F_85 ( V_3 -> V_6 ) ;
if ( V_140 )
return V_140 ;
F_41 ( V_3 ) ;
F_66 ( V_3 ) ;
return 0 ;
exit:
return V_140 ;
}
