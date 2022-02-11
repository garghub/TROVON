static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_7 ;
F_3 ( & V_6 -> V_8 ) ;
V_7 = F_4 ( V_4 , V_9 ) ;
if ( V_7 <= 0 ) {
F_5 ( & V_6 -> V_8 ) ;
return V_10 ;
}
if ( V_7 & V_11 )
F_6 ( & V_4 -> V_12 , L_1 ) ;
if ( V_7 & V_13 ) {
V_7 &= ~ V_13 ;
F_7 ( V_6 -> V_14 , 1 , V_15 | V_16 ) ;
}
if ( V_7 & V_17 ) {
V_7 &= ~ V_17 ;
F_7 ( V_6 -> V_14 , 1 , V_18 | V_16 ) ;
}
if ( V_7 & V_19 ) {
V_7 &= ~ V_19 ;
F_7 ( V_6 -> V_14 , 1 , V_20 | V_16 ) ;
}
F_8 ( V_4 , V_9 , V_7 ) ;
F_5 ( & V_6 -> V_8 ) ;
return V_21 ;
}
static int F_9 ( struct V_22 * V_12 , struct V_23 * V_24 )
{
struct V_5 * V_6 = F_10 ( V_12 ) ;
T_2 V_25 [ 7 ] ;
int V_7 ;
int V_26 ;
V_7 = F_4 ( V_6 -> V_4 , V_9 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_7 & V_11 ) {
F_6 ( V_12 , L_1 ) ;
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
static int F_15 ( struct V_22 * V_12 , struct V_23 * V_24 )
{
struct V_5 * V_6 = F_10 ( V_12 ) ;
T_2 V_25 [ 7 ] ;
int V_43 , V_7 ;
int V_44 ;
unsigned long V_45 ;
if ( ( V_24 -> V_39 < 100 ) || ( V_24 -> V_39 > 199 ) )
return - V_27 ;
V_43 = F_4 ( V_6 -> V_4 , V_46 ) ;
if ( V_43 < 0 )
return V_43 ;
V_6 -> V_47 = V_43 | V_48 ;
V_44 = F_8 ( V_6 -> V_4 , V_46 ,
V_6 -> V_47 ) ;
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
V_43 = F_4 ( V_6 -> V_4 , V_46 ) ;
if ( V_43 < 0 )
return V_43 ;
V_6 -> V_47 = V_43 & ~ V_48 ;
V_44 = F_8 ( V_6 -> V_4 , V_46 ,
V_6 -> V_47 ) ;
if ( V_44 < 0 )
return V_44 ;
F_18 ( & V_6 -> V_8 , V_45 ) ;
V_7 = F_4 ( V_6 -> V_4 , V_9 ) ;
if ( V_7 < 0 ) {
F_19 ( & V_6 -> V_8 , V_45 ) ;
return V_7 ;
}
if ( V_7 & V_11 )
V_44 = F_8 ( V_6 -> V_4 , V_9 ,
V_7 & ~ V_11 ) ;
F_19 ( & V_6 -> V_8 , V_45 ) ;
return 0 ;
}
static int F_20 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_2 V_43 [ 2 ] ;
int V_49 = 0 , V_26 = 0 ;
V_26 = F_8 ( V_4 , V_50 , 0xD8 ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_8 ( V_4 , V_51 , 0x00 ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_8 ( V_4 , V_52 , 0x08 ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_8 ( V_4 , V_53 , 0x00 ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_11 ( V_6 -> V_4 , V_9 ,
2 , V_43 ) ;
if ( V_26 != 2 )
return V_26 < 0 ? V_26 : - V_29 ;
if ( V_43 [ 0 ] & V_11 )
F_6 ( & V_4 -> V_12 , L_2 ) ;
if ( V_43 [ 0 ] & V_17 ) {
F_6 ( & V_4 -> V_12 , L_3 ) ;
V_49 = 1 ;
}
if ( V_43 [ 0 ] & V_13 )
V_49 = 1 ;
if ( V_43 [ 0 ] & V_19 )
V_49 = 1 ;
if ( V_49 ) {
V_43 [ 0 ] &= ~ ( V_17 | V_13 | V_19 ) ;
V_26 = F_8 ( V_4 , V_9 , V_43 [ 0 ] ) ;
if ( V_26 < 0 )
return V_26 ;
}
V_6 -> V_47 = ( V_43 [ 1 ] & ~ V_54 ) ;
return V_26 ;
}
static int F_21 ( struct V_22 * V_12 , struct V_55 * V_56 )
{
struct V_5 * V_6 = F_10 ( V_12 ) ;
struct V_3 * V_4 = V_6 -> V_4 ;
T_2 V_57 [ 3 ] ;
int V_7 ;
int V_26 ;
V_26 = F_11 ( V_4 , V_58 , 3 , V_57 ) ;
if ( V_26 != 3 )
return V_26 < 0 ? V_26 : - V_29 ;
V_7 = F_4 ( V_4 , V_9 ) ;
if ( V_7 < 0 )
return V_7 ;
V_56 -> time . V_30 = 0 ;
V_56 -> time . V_31 = F_12 ( V_57 [ 0 ] & 0x7f ) ;
V_56 -> time . V_33 = F_12 ( V_57 [ 1 ] & 0x3f ) ;
if ( ! ( V_57 [ 2 ] & V_59 ) )
V_56 -> time . V_35 = F_12 ( V_57 [ 2 ] & 0x7f ) ;
V_56 -> V_60 = ! ! ( V_6 -> V_47 & V_61 ) ;
V_56 -> V_62 = ( V_7 & V_17 ) && V_56 -> V_60 ;
return V_26 ;
}
static int F_22 ( struct V_22 * V_12 , struct V_55 * V_56 )
{
struct V_3 * V_4 = F_23 ( V_12 ) ;
struct V_5 * V_6 = F_10 ( V_12 ) ;
T_2 V_57 [ 3 ] ;
int V_63 , V_7 ;
int V_26 ;
unsigned long V_45 ;
F_18 ( & V_6 -> V_8 , V_45 ) ;
V_7 = F_4 ( V_4 , V_9 ) ;
if ( V_7 < 0 ) {
F_19 ( & V_6 -> V_8 , V_45 ) ;
return V_7 ;
}
if ( V_6 -> V_47 & ( V_61 | V_64 ) ) {
V_6 -> V_47 &= ~ ( V_61 | V_64 ) ;
V_26 = F_8 ( V_6 -> V_4 , V_46 ,
V_6 -> V_47 ) ;
if ( V_26 < 0 ) {
F_19 ( & V_6 -> V_8 , V_45 ) ;
return V_26 ;
}
}
V_7 &= ~ V_17 ;
V_26 = F_8 ( V_6 -> V_4 , V_9 , V_7 ) ;
F_19 ( & V_6 -> V_8 , V_45 ) ;
if ( V_26 < 0 )
return V_26 ;
V_57 [ 0 ] = F_16 ( V_56 -> time . V_31 ) ;
V_57 [ 1 ] = F_16 ( V_56 -> time . V_33 ) ;
V_57 [ 2 ] = F_16 ( V_56 -> time . V_35 ) ;
V_26 = F_17 ( V_6 -> V_4 , V_58 ,
2 , V_57 ) ;
if ( V_26 < 0 )
return V_26 ;
V_63 = F_4 ( V_4 , V_65 ) ;
if ( V_63 < 0 )
return V_63 ;
V_63 |= V_66 ;
V_26 = F_8 ( V_6 -> V_4 , V_65 , V_63 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_57 [ 2 ] == 0 )
V_57 [ 2 ] |= V_59 ;
V_26 = F_8 ( V_6 -> V_4 , V_67 ,
V_57 [ 2 ] ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_56 -> V_60 ) {
if ( V_6 -> V_14 -> V_68 . V_60 )
V_6 -> V_47 |= V_64 ;
if ( V_6 -> V_14 -> V_69 . V_60 )
V_6 -> V_47 |=
( V_61 | V_64 ) ;
V_26 = F_8 ( V_6 -> V_4 , V_46 ,
V_6 -> V_47 ) ;
if ( V_26 < 0 )
return V_26 ;
}
return 0 ;
}
static int F_24 ( struct V_22 * V_12 ,
unsigned int V_60 )
{
struct V_3 * V_4 = F_23 ( V_12 ) ;
struct V_5 * V_6 = F_10 ( V_12 ) ;
int V_7 ;
T_2 V_43 ;
int V_26 ;
V_43 = V_6 -> V_47 ;
if ( V_60 ) {
if ( V_6 -> V_14 -> V_68 . V_60 )
V_43 |= V_64 ;
if ( V_6 -> V_14 -> V_69 . V_60 )
V_43 |= ( V_61 | V_64 ) ;
} else {
if ( ! V_6 -> V_14 -> V_68 . V_60 )
V_43 &= ~ V_64 ;
if ( ! V_6 -> V_14 -> V_69 . V_60 )
V_43 &= ~ V_61 ;
}
V_7 = F_4 ( V_4 , V_9 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 &= ~ V_17 ;
V_26 = F_8 ( V_6 -> V_4 , V_9 , V_7 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_43 != V_6 -> V_47 ) {
V_6 -> V_47 = V_43 ;
V_26 = F_8 ( V_6 -> V_4 , V_46 ,
V_6 -> V_47 ) ;
if ( V_26 < 0 )
return V_26 ;
}
return 0 ;
}
static int F_25 ( struct V_22 * V_12 , unsigned int V_70 , unsigned long V_71 )
{
struct V_3 * V_4 = F_23 ( V_12 ) ;
struct V_5 * V_6 = F_10 ( V_12 ) ;
int V_44 , V_72 ;
int V_7 ;
unsigned long V_45 ;
switch ( V_70 ) {
case V_73 :
V_7 = F_4 ( V_6 -> V_4 , V_9 ) ;
if ( V_7 < 0 )
return V_7 ;
V_72 = ! ! ( V_7 & V_11 ) ;
if ( F_26 ( ( void V_74 * ) V_71 , & V_72 , sizeof( int ) ) )
return - V_75 ;
return 0 ;
case V_76 :
F_18 ( & V_6 -> V_8 , V_45 ) ;
V_7 = F_4 ( V_6 -> V_4 , V_9 ) ;
if ( V_7 < 0 ) {
F_19 ( & V_6 -> V_8 , V_45 ) ;
return V_7 ;
}
V_7 &= ~ V_11 ;
V_44 = F_8 ( V_4 , V_9 , V_7 ) ;
F_19 ( & V_6 -> V_8 , V_45 ) ;
if ( V_44 < 0 )
return V_44 ;
return 0 ;
default:
return - V_77 ;
}
}
static int F_27 ( struct V_3 * V_4 ,
const struct V_78 * V_79 )
{
struct V_80 * V_81 = F_28 ( V_4 -> V_12 . V_82 ) ;
struct V_5 * V_6 ;
int V_26 = 0 ;
if ( ! F_29 ( V_81 , V_83
| V_84 ) ) {
F_30 ( & V_81 -> V_12 , L_4 ) ;
return - V_29 ;
}
V_6 = F_31 ( & V_4 -> V_12 , sizeof( struct V_5 ) ,
V_85 ) ;
if ( ! V_6 )
return - V_86 ;
V_6 -> V_4 = V_4 ;
F_32 ( V_4 , V_6 ) ;
F_33 ( & V_6 -> V_8 ) ;
V_26 = F_20 ( V_4 ) ;
if ( V_26 )
return V_26 ;
if ( V_4 -> V_1 > 0 ) {
F_34 ( & V_4 -> V_12 , L_5 , V_4 -> V_1 ) ;
V_26 = F_35 ( & V_4 -> V_12 , V_4 -> V_1 , NULL ,
F_1 ,
V_87 | V_88 ,
L_6 , V_4 ) ;
if ( V_26 ) {
F_30 ( & V_4 -> V_12 , L_7 ) ;
V_4 -> V_1 = 0 ;
} else {
V_89 . V_90 = F_21 ;
V_89 . V_91 = F_22 ;
V_89 . V_92 = F_24 ;
}
}
V_6 -> V_14 = F_36 ( & V_4 -> V_12 , V_4 -> V_93 ,
& V_89 , V_94 ) ;
if ( F_37 ( V_6 -> V_14 ) ) {
F_30 ( & V_4 -> V_12 , L_8 ) ;
return F_38 ( V_6 -> V_14 ) ;
}
V_6 -> V_14 -> V_95 = 1 ;
return V_26 ;
}
