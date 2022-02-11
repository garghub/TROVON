static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_7 ) ;
struct V_8 * V_9 = V_6 -> V_10 -> V_11 . V_12 ;
if ( V_4 -> V_13 > 8188 )
V_4 -> V_13 = 8188 ;
else if ( V_4 -> V_13 & 1 )
V_4 -> V_13 &= ~ 1 ;
switch ( V_9 -> type ) {
case V_14 :
switch ( V_4 -> V_15 ) {
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
break;
default:
V_4 -> V_15 = V_21 ;
}
break;
case V_22 :
switch ( V_4 -> V_15 ) {
case V_18 :
case V_19 :
case V_20 :
case V_23 :
case V_24 :
break;
default:
V_4 -> V_15 = V_19 ;
}
break;
}
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_7 ) ;
T_1 V_25 = ( V_6 -> V_26 -> V_27 & 3 ) << 8 ;
F_4 ( V_2 -> V_28 -> V_11 , L_1 , V_29 , V_4 -> V_15 ) ;
if ( V_4 -> V_13 > 8188 || V_4 -> V_13 & 1 )
return - V_30 ;
switch ( V_4 -> V_15 ) {
case V_16 :
V_25 |= 0x1e ;
break;
case V_17 :
V_25 |= 0x18 ;
break;
case V_31 :
V_25 |= 0x21 ;
break;
case V_32 :
V_25 |= 0x22 ;
break;
case V_18 :
case V_19 :
case V_20 :
V_25 |= 0x2a ;
break;
default:
return - V_30 ;
}
F_5 ( V_25 , V_6 -> V_33 + V_34 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_7 ) ;
if ( ! V_6 -> V_37 ) {
struct V_38 * V_39 = F_7 ( V_2 ) ;
struct V_1 * V_40 = F_8 ( V_39 ) ;
struct V_8 * V_9 = V_6 -> V_10 -> V_11 . V_12 ;
unsigned long V_41 , V_42 ;
struct V_35 V_43 = { . type = V_44 ,} ;
int V_45 ;
V_42 = V_46 |
V_47 ;
switch ( V_9 -> type ) {
case V_14 :
if ( V_6 -> V_26 -> V_48 != 1 )
V_42 |= V_49 ;
break;
case V_22 :
switch ( V_6 -> V_26 -> V_48 ) {
default:
V_42 |= V_50 ;
case 3 :
V_42 |= V_51 ;
case 2 :
V_42 |= V_49 ;
}
}
V_45 = F_9 ( V_40 , V_52 , V_53 , & V_43 ) ;
if ( V_45 == - V_54 )
V_41 = V_42 ;
else if ( ! V_45 )
V_41 = F_10 ( & V_43 ,
V_42 ) ;
else
V_41 = 0 ;
if ( ! V_41 )
return - V_30 ;
V_6 -> V_37 = V_41 ;
}
if ( V_36 ) {
V_36 -> V_55 = V_56 |
V_57 | V_58 |
V_59 | V_60 ;
V_36 -> type = V_61 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
const struct V_35 * V_36 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_7 ) ;
struct V_38 * V_39 = F_7 ( V_2 ) ;
struct V_1 * V_40 = F_8 ( V_39 ) ;
struct V_35 V_43 = { . type = V_44 ,} ;
int V_45 = F_6 ( V_2 , NULL ) ;
if ( V_45 < 0 )
return V_45 ;
F_12 ( & V_6 -> V_10 -> V_11 ) ;
F_13 ( V_6 ) ;
V_43 . V_55 = V_6 -> V_37 ;
return F_9 ( V_40 , V_52 , V_62 , & V_43 ) ;
}
static void F_13 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 -> V_11 . V_12 ;
T_2 V_25 = 0x10 ;
F_5 ( 0x00000001 , V_6 -> V_33 + V_63 ) ;
F_5 ( 0x00000001 , V_6 -> V_33 + V_64 ) ;
F_14 ( 5 ) ;
F_5 ( 0x00000000 , V_6 -> V_33 + V_64 ) ;
switch ( V_9 -> type ) {
case V_14 :
if ( V_6 -> V_26 -> V_48 == 1 )
V_25 |= 1 ;
else
V_25 |= 3 ;
break;
case V_22 :
if ( ! V_6 -> V_26 -> V_48 || V_6 -> V_26 -> V_48 > 4 )
V_25 |= 0xf ;
else
V_25 |= ( 1 << V_6 -> V_26 -> V_48 ) - 1 ;
}
if ( V_6 -> V_26 -> V_65 == V_66 )
V_25 |= 0x8000 ;
F_5 ( V_25 , V_6 -> V_33 + V_67 ) ;
V_25 = 0 ;
if ( V_9 -> V_55 & V_68 )
V_25 |= 2 ;
if ( V_9 -> V_55 & V_69 )
V_25 |= 1 ;
F_5 ( V_25 , V_6 -> V_33 + V_70 ) ;
}
static int F_15 ( struct V_5 * V_6 )
{
struct V_71 * V_11 = F_16 ( & V_6 -> V_7 ) ;
struct V_8 * V_9 = V_11 -> V_12 ;
struct V_38 * V_39 = F_7 ( & V_6 -> V_7 ) ;
int V_72 ;
if ( V_6 -> V_26 )
return - V_73 ;
for ( V_72 = 0 ; V_72 < V_9 -> V_74 ; V_72 ++ )
if ( ( V_9 -> V_75 [ V_72 ] . V_10 &&
& V_9 -> V_75 [ V_72 ] . V_10 -> V_11 == V_39 -> V_10 ) ||
( V_39 -> V_76 &&
strcmp ( V_9 -> V_75 [ V_72 ] . V_77 , F_17 ( V_39 -> V_76 ) ) ) )
break;
F_4 ( V_11 , L_2 , V_29 , V_11 , V_72 ) ;
if ( V_72 == V_9 -> V_74 )
return - V_78 ;
V_6 -> V_26 = V_9 -> V_75 + V_72 ;
return 0 ;
}
static void F_18 ( struct V_5 * V_6 )
{
if ( ! V_6 -> V_26 )
return;
V_6 -> V_26 = NULL ;
F_19 ( F_16 ( & V_6 -> V_7 ) ) ;
}
static int F_20 ( struct V_1 * V_2 , int V_79 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_7 ) ;
if ( V_79 )
return F_15 ( V_6 ) ;
F_18 ( V_6 ) ;
return 0 ;
}
static int F_21 ( struct V_80 * V_10 )
{
struct V_81 * V_82 ;
unsigned int V_83 ;
int V_45 ;
struct V_5 * V_6 ;
struct V_8 * V_9 = V_10 -> V_11 . V_12 ;
if ( ! V_9 )
return - V_30 ;
V_6 = F_22 ( & V_10 -> V_11 , sizeof( struct V_5 ) , V_84 ) ;
if ( ! V_6 )
return - V_85 ;
V_82 = F_23 ( V_10 , V_86 , 0 ) ;
V_83 = F_24 ( V_10 , 0 ) ;
if ( ! V_82 || ( int ) V_83 <= 0 ) {
F_25 ( & V_10 -> V_11 , L_3 ) ;
return - V_78 ;
}
if ( V_9 -> type != V_14 ) {
F_25 ( & V_10 -> V_11 , L_4 ) ;
return - V_30 ;
}
V_6 -> V_83 = V_83 ;
V_6 -> V_33 = F_26 ( & V_10 -> V_11 , V_82 ) ;
if ( F_27 ( V_6 -> V_33 ) )
return F_28 ( V_6 -> V_33 ) ;
V_6 -> V_10 = V_10 ;
V_6 -> V_7 . V_87 = V_88 ;
V_6 -> V_7 . V_11 = & V_10 -> V_11 ;
F_29 ( V_10 , & V_6 -> V_7 ) ;
F_30 ( & V_6 -> V_7 , & V_89 ) ;
F_31 ( & V_6 -> V_7 , & V_10 -> V_11 ) ;
snprintf ( V_6 -> V_7 . V_77 , V_90 , L_5 ,
F_17 ( & V_10 -> V_11 ) ) ;
V_45 = F_32 ( & V_6 -> V_7 ) ;
if ( V_45 < 0 )
return V_45 ;
F_33 ( & V_10 -> V_11 ) ;
F_4 ( & V_10 -> V_11 , L_6 ) ;
return 0 ;
}
static int F_34 ( struct V_80 * V_10 )
{
struct V_1 * V_7 = F_35 ( V_10 ) ;
struct V_5 * V_6 = F_2 ( V_7 , struct V_5 , V_7 ) ;
F_36 ( & V_6 -> V_7 ) ;
F_37 ( V_7 ) ;
F_38 ( & V_10 -> V_11 ) ;
return 0 ;
}
