static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_7 ;
F_3 ( & V_6 -> V_8 -> V_9 ) ;
V_7 = F_4 ( V_4 , V_10 ) ;
if ( V_7 <= 0 ) {
F_5 ( & V_6 -> V_8 -> V_9 ) ;
return V_11 ;
}
if ( V_7 & V_12 )
F_6 ( & V_4 -> V_13 , L_1 ) ;
if ( V_7 & V_14 ) {
V_7 &= ~ V_14 ;
F_7 ( V_6 -> V_8 , 1 , V_15 | V_16 ) ;
}
if ( V_7 & V_17 ) {
V_7 &= ~ V_17 ;
F_7 ( V_6 -> V_8 , 1 , V_18 | V_16 ) ;
}
if ( V_7 & V_19 ) {
V_7 &= ~ V_19 ;
F_7 ( V_6 -> V_8 , 1 , V_20 | V_16 ) ;
}
F_8 ( V_4 , V_10 , V_7 ) ;
F_5 ( & V_6 -> V_8 -> V_9 ) ;
return V_21 ;
}
static int F_9 ( struct V_22 * V_13 , struct V_23 * V_24 )
{
struct V_5 * V_6 = F_10 ( V_13 ) ;
T_2 V_25 [ 7 ] ;
int V_7 ;
int V_26 ;
V_7 = F_4 ( V_6 -> V_4 , V_10 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_7 & V_12 ) {
F_6 ( V_13 , L_1 ) ;
return - V_27 ;
}
V_26 = F_11 ( V_6 -> V_4 , V_28 ,
7 , V_25 ) ;
if ( V_26 != 7 )
return V_26 < 0 ? V_26 : - V_29 ;
V_24 -> V_30 = F_12 ( V_25 [ V_28 - V_28 ] & 0x7f ) ;
V_24 -> V_31 = F_12 ( V_25 [ V_32 - V_28 ] & 0x7f ) ;
V_24 -> V_33 = F_12 ( V_25 [ V_34 - V_28 ] & 0x3f ) ;
V_24 -> V_35 = F_12 ( V_25 [ V_36 - V_28 ] & 0x3f ) ;
V_24 -> V_37 = F_12 ( V_25 [ V_38 - V_28 ] & 0x1f ) - 1 ;
V_24 -> V_39 = F_12 ( V_25 [ V_40 - V_28 ] ) + 100 ;
V_24 -> V_41 = F_13 ( V_25 [ V_42 - V_28 ] & 0x7f ) ;
return F_14 ( V_24 ) ;
}
static int F_15 ( struct V_22 * V_13 , struct V_23 * V_24 )
{
struct V_5 * V_6 = F_10 ( V_13 ) ;
T_2 V_25 [ 7 ] ;
int V_43 , V_7 ;
int V_44 ;
if ( ( V_24 -> V_39 < 100 ) || ( V_24 -> V_39 > 199 ) )
return - V_27 ;
V_43 = F_4 ( V_6 -> V_4 , V_45 ) ;
if ( V_43 < 0 )
return V_43 ;
V_6 -> V_46 = V_43 | V_47 ;
V_44 = F_8 ( V_6 -> V_4 , V_45 ,
V_6 -> V_46 ) ;
if ( V_44 < 0 )
return V_44 ;
V_25 [ V_28 - V_28 ] = F_16 ( V_24 -> V_30 ) ;
V_25 [ V_32 - V_28 ] = F_16 ( V_24 -> V_31 ) ;
V_25 [ V_34 - V_28 ] = F_16 ( V_24 -> V_33 ) ;
V_25 [ V_36 - V_28 ] = F_16 ( V_24 -> V_35 ) ;
V_25 [ V_38 - V_28 ] = F_16 ( V_24 -> V_37 + 1 ) ;
V_25 [ V_40 - V_28 ] = F_16 ( V_24 -> V_39 - 100 ) ;
V_25 [ V_42 - V_28 ] = F_16 ( 1 << V_24 -> V_41 ) ;
V_44 = F_17 ( V_6 -> V_4 ,
V_28 , 7 , V_25 ) ;
if ( V_44 < 0 )
return V_44 ;
V_43 = F_4 ( V_6 -> V_4 , V_45 ) ;
if ( V_43 < 0 )
return V_43 ;
V_6 -> V_46 = V_43 & ~ V_47 ;
V_44 = F_8 ( V_6 -> V_4 , V_45 ,
V_6 -> V_46 ) ;
if ( V_44 < 0 )
return V_44 ;
V_7 = F_4 ( V_6 -> V_4 , V_10 ) ;
if ( V_7 < 0 ) {
return V_7 ;
}
if ( V_7 & V_12 )
V_44 = F_8 ( V_6 -> V_4 , V_10 ,
V_7 & ~ V_12 ) ;
return 0 ;
}
static int F_18 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_2 V_43 [ 2 ] ;
int V_48 = 0 , V_26 = 0 ;
V_26 = F_8 ( V_4 , V_49 , 0xD8 ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_8 ( V_4 , V_50 , 0x00 ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_8 ( V_4 , V_51 , 0x08 ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_8 ( V_4 , V_52 , 0x00 ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_11 ( V_6 -> V_4 , V_10 ,
2 , V_43 ) ;
if ( V_26 != 2 )
return V_26 < 0 ? V_26 : - V_29 ;
if ( V_43 [ 0 ] & V_12 )
F_6 ( & V_4 -> V_13 , L_2 ) ;
if ( V_43 [ 0 ] & V_17 ) {
F_6 ( & V_4 -> V_13 , L_3 ) ;
V_48 = 1 ;
}
if ( V_43 [ 0 ] & V_14 )
V_48 = 1 ;
if ( V_43 [ 0 ] & V_19 )
V_48 = 1 ;
if ( V_48 ) {
V_43 [ 0 ] &= ~ ( V_17 | V_14 | V_19 ) ;
V_26 = F_8 ( V_4 , V_10 , V_43 [ 0 ] ) ;
if ( V_26 < 0 )
return V_26 ;
}
V_6 -> V_46 = ( V_43 [ 1 ] & ~ V_53 ) ;
return V_26 ;
}
static int F_19 ( struct V_22 * V_13 , struct V_54 * V_55 )
{
struct V_5 * V_6 = F_10 ( V_13 ) ;
struct V_3 * V_4 = V_6 -> V_4 ;
T_2 V_56 [ 3 ] ;
int V_7 ;
int V_26 ;
V_26 = F_11 ( V_4 , V_57 , 3 , V_56 ) ;
if ( V_26 != 3 )
return V_26 < 0 ? V_26 : - V_29 ;
V_7 = F_4 ( V_4 , V_10 ) ;
if ( V_7 < 0 )
return V_7 ;
V_55 -> time . V_30 = 0 ;
V_55 -> time . V_31 = F_12 ( V_56 [ 0 ] & 0x7f ) ;
V_55 -> time . V_33 = F_12 ( V_56 [ 1 ] & 0x3f ) ;
if ( ! ( V_56 [ 2 ] & V_58 ) )
V_55 -> time . V_35 = F_12 ( V_56 [ 2 ] & 0x7f ) ;
V_55 -> V_59 = ! ! ( V_6 -> V_46 & V_60 ) ;
V_55 -> V_61 = ( V_7 & V_17 ) && V_55 -> V_59 ;
return V_26 ;
}
static int F_20 ( struct V_22 * V_13 , struct V_54 * V_55 )
{
struct V_3 * V_4 = F_21 ( V_13 ) ;
struct V_5 * V_6 = F_10 ( V_13 ) ;
T_2 V_56 [ 3 ] ;
int V_62 , V_7 ;
int V_26 ;
V_7 = F_4 ( V_4 , V_10 ) ;
if ( V_7 < 0 ) {
return V_7 ;
}
if ( V_6 -> V_46 & ( V_60 | V_63 ) ) {
V_6 -> V_46 &= ~ ( V_60 | V_63 ) ;
V_26 = F_8 ( V_6 -> V_4 , V_45 ,
V_6 -> V_46 ) ;
if ( V_26 < 0 ) {
return V_26 ;
}
}
V_7 &= ~ V_17 ;
V_26 = F_8 ( V_6 -> V_4 , V_10 , V_7 ) ;
if ( V_26 < 0 )
return V_26 ;
V_56 [ 0 ] = F_16 ( V_55 -> time . V_31 ) ;
V_56 [ 1 ] = F_16 ( V_55 -> time . V_33 ) ;
V_56 [ 2 ] = F_16 ( V_55 -> time . V_35 ) ;
V_26 = F_17 ( V_6 -> V_4 , V_57 ,
2 , V_56 ) ;
if ( V_26 < 0 )
return V_26 ;
V_62 = F_4 ( V_4 , V_64 ) ;
if ( V_62 < 0 )
return V_62 ;
V_62 |= V_65 ;
V_26 = F_8 ( V_6 -> V_4 , V_64 , V_62 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_56 [ 2 ] == 0 )
V_56 [ 2 ] |= V_58 ;
V_26 = F_8 ( V_6 -> V_4 , V_66 ,
V_56 [ 2 ] ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_55 -> V_59 ) {
if ( V_6 -> V_8 -> V_67 . V_59 )
V_6 -> V_46 |= V_63 ;
if ( V_6 -> V_8 -> V_68 . V_59 )
V_6 -> V_46 |=
( V_60 | V_63 ) ;
V_26 = F_8 ( V_6 -> V_4 , V_45 ,
V_6 -> V_46 ) ;
if ( V_26 < 0 )
return V_26 ;
}
return 0 ;
}
static int F_22 ( struct V_22 * V_13 ,
unsigned int V_59 )
{
struct V_3 * V_4 = F_21 ( V_13 ) ;
struct V_5 * V_6 = F_10 ( V_13 ) ;
int V_7 ;
T_2 V_43 ;
int V_26 ;
V_43 = V_6 -> V_46 ;
if ( V_59 ) {
if ( V_6 -> V_8 -> V_67 . V_59 )
V_43 |= V_63 ;
if ( V_6 -> V_8 -> V_68 . V_59 )
V_43 |= ( V_60 | V_63 ) ;
} else {
if ( ! V_6 -> V_8 -> V_67 . V_59 )
V_43 &= ~ V_63 ;
if ( ! V_6 -> V_8 -> V_68 . V_59 )
V_43 &= ~ V_60 ;
}
V_7 = F_4 ( V_4 , V_10 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 &= ~ V_17 ;
V_26 = F_8 ( V_6 -> V_4 , V_10 , V_7 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_43 != V_6 -> V_46 ) {
V_6 -> V_46 = V_43 ;
V_26 = F_8 ( V_6 -> V_4 , V_45 ,
V_6 -> V_46 ) ;
if ( V_26 < 0 )
return V_26 ;
}
return 0 ;
}
static int F_23 ( struct V_22 * V_13 , unsigned int V_69 , unsigned long V_70 )
{
struct V_3 * V_4 = F_21 ( V_13 ) ;
struct V_5 * V_6 = F_10 ( V_13 ) ;
int V_44 , V_71 ;
int V_7 ;
switch ( V_69 ) {
case V_72 :
V_7 = F_4 ( V_6 -> V_4 , V_10 ) ;
if ( V_7 < 0 )
return V_7 ;
V_71 = ! ! ( V_7 & V_12 ) ;
if ( F_24 ( ( void V_73 * ) V_70 , & V_71 , sizeof( int ) ) )
return - V_74 ;
return 0 ;
case V_75 :
V_7 = F_4 ( V_6 -> V_4 , V_10 ) ;
if ( V_7 < 0 ) {
return V_7 ;
}
V_7 &= ~ V_12 ;
V_44 = F_8 ( V_4 , V_10 , V_7 ) ;
if ( V_44 < 0 )
return V_44 ;
return 0 ;
default:
return - V_76 ;
}
}
static int F_25 ( struct V_3 * V_4 ,
const struct V_77 * V_78 )
{
struct V_79 * V_80 = F_26 ( V_4 -> V_13 . V_81 ) ;
struct V_5 * V_6 ;
int V_26 = 0 ;
if ( ! F_27 ( V_80 , V_82
| V_83 ) ) {
F_28 ( & V_80 -> V_13 , L_4 ) ;
return - V_29 ;
}
V_6 = F_29 ( & V_4 -> V_13 , sizeof( struct V_5 ) ,
V_84 ) ;
if ( ! V_6 )
return - V_85 ;
V_6 -> V_4 = V_4 ;
F_30 ( V_4 , V_6 ) ;
V_26 = F_18 ( V_4 ) ;
if ( V_26 )
return V_26 ;
if ( V_4 -> V_1 > 0 ) {
F_31 ( & V_4 -> V_13 , L_5 , V_4 -> V_1 ) ;
V_26 = F_32 ( & V_4 -> V_13 , V_4 -> V_1 , NULL ,
F_1 ,
V_86 | V_87 ,
L_6 , V_4 ) ;
if ( V_26 ) {
F_28 ( & V_4 -> V_13 , L_7 ) ;
V_4 -> V_1 = 0 ;
} else {
V_88 . V_89 = F_19 ;
V_88 . V_90 = F_20 ;
V_88 . V_91 = F_22 ;
}
}
V_6 -> V_8 = F_33 ( & V_4 -> V_13 , V_4 -> V_92 ,
& V_88 , V_93 ) ;
if ( F_34 ( V_6 -> V_8 ) ) {
F_28 ( & V_4 -> V_13 , L_8 ) ;
return F_35 ( V_6 -> V_8 ) ;
}
V_6 -> V_8 -> V_94 = 1 ;
return V_26 ;
}
