static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 , struct V_7 , V_9 ) ;
struct V_10 * V_11 = V_8 -> V_12 -> V_13 . V_14 ;
struct V_15 * V_16 = & V_6 -> V_6 ;
T_1 V_17 = ( V_8 -> V_18 -> V_19 & 3 ) << 8 ;
if ( V_6 -> V_20 )
return - V_21 ;
if ( V_16 -> V_22 > 8188 )
V_16 -> V_22 = 8188 ;
else if ( V_16 -> V_22 & 1 )
V_16 -> V_22 &= ~ 1 ;
switch ( V_11 -> type ) {
case V_23 :
switch ( V_16 -> V_24 ) {
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
break;
default:
V_16 -> V_24 = V_30 ;
}
break;
case V_31 :
switch ( V_16 -> V_24 ) {
case V_27 :
case V_28 :
case V_29 :
case V_32 :
case V_33 :
break;
default:
V_16 -> V_24 = V_28 ;
}
break;
}
if ( V_6 -> V_34 == V_35 ) {
V_4 -> V_36 = * V_16 ;
return 0 ;
}
if ( V_16 -> V_22 > 8188 || V_16 -> V_22 & 1 )
return - V_21 ;
switch ( V_16 -> V_24 ) {
case V_25 :
V_17 |= 0x1e ;
break;
case V_26 :
V_17 |= 0x18 ;
break;
case V_37 :
V_17 |= 0x21 ;
break;
case V_38 :
V_17 |= 0x22 ;
break;
case V_27 :
case V_28 :
case V_29 :
V_17 |= 0x2a ;
break;
default:
return - V_21 ;
}
F_3 ( V_17 , V_8 -> V_39 + V_40 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_41 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 , struct V_7 , V_9 ) ;
if ( ! V_8 -> V_42 ) {
struct V_43 * V_44 = F_5 ( V_2 ) ;
struct V_1 * V_45 = F_6 ( V_44 ) ;
struct V_10 * V_11 = V_8 -> V_12 -> V_13 . V_14 ;
unsigned long V_46 , V_47 ;
struct V_41 V_48 = { . type = V_49 ,} ;
int V_50 ;
V_47 = V_51 |
V_52 ;
switch ( V_11 -> type ) {
case V_23 :
if ( V_8 -> V_18 -> V_53 != 1 )
V_47 |= V_54 ;
break;
case V_31 :
switch ( V_8 -> V_18 -> V_53 ) {
default:
V_47 |= V_55 ;
case 3 :
V_47 |= V_56 ;
case 2 :
V_47 |= V_54 ;
}
}
V_50 = F_7 ( V_45 , V_57 , V_58 , & V_48 ) ;
if ( V_50 == - V_59 )
V_46 = V_47 ;
else if ( ! V_50 )
V_46 = F_8 ( & V_48 ,
V_47 ) ;
else
V_46 = 0 ;
if ( ! V_46 )
return - V_21 ;
V_8 -> V_42 = V_46 ;
}
if ( V_4 ) {
V_4 -> V_60 = V_61 |
V_62 | V_63 |
V_64 | V_65 ;
V_4 -> type = V_66 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
const struct V_41 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 , struct V_7 , V_9 ) ;
struct V_43 * V_44 = F_5 ( V_2 ) ;
struct V_1 * V_45 = F_6 ( V_44 ) ;
struct V_41 V_48 = { . type = V_49 ,} ;
int V_50 = F_4 ( V_2 , NULL ) ;
if ( V_50 < 0 )
return V_50 ;
F_10 ( & V_8 -> V_12 -> V_13 ) ;
F_11 ( V_8 ) ;
V_48 . V_60 = V_8 -> V_42 ;
return F_7 ( V_45 , V_57 , V_67 , & V_48 ) ;
}
static void F_11 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_12 -> V_13 . V_14 ;
T_2 V_17 = 0x10 ;
F_3 ( 0x00000001 , V_8 -> V_39 + V_68 ) ;
F_3 ( 0x00000001 , V_8 -> V_39 + V_69 ) ;
F_12 ( 5 ) ;
F_3 ( 0x00000000 , V_8 -> V_39 + V_69 ) ;
switch ( V_11 -> type ) {
case V_23 :
if ( V_8 -> V_18 -> V_53 == 1 )
V_17 |= 1 ;
else
V_17 |= 3 ;
break;
case V_31 :
if ( ! V_8 -> V_18 -> V_53 || V_8 -> V_18 -> V_53 > 4 )
V_17 |= 0xf ;
else
V_17 |= ( 1 << V_8 -> V_18 -> V_53 ) - 1 ;
}
if ( V_8 -> V_18 -> V_70 == V_71 )
V_17 |= 0x8000 ;
F_3 ( V_17 , V_8 -> V_39 + V_72 ) ;
V_17 = 0 ;
if ( V_11 -> V_60 & V_73 )
V_17 |= 2 ;
if ( V_11 -> V_60 & V_74 )
V_17 |= 1 ;
F_3 ( V_17 , V_8 -> V_39 + V_75 ) ;
}
static int F_13 ( struct V_7 * V_8 )
{
struct V_76 * V_13 = F_14 ( & V_8 -> V_9 ) ;
struct V_10 * V_11 = V_13 -> V_14 ;
struct V_43 * V_44 = F_5 ( & V_8 -> V_9 ) ;
int V_77 ;
if ( V_8 -> V_18 )
return - V_78 ;
for ( V_77 = 0 ; V_77 < V_11 -> V_79 ; V_77 ++ )
if ( ( V_11 -> V_80 [ V_77 ] . V_12 &&
& V_11 -> V_80 [ V_77 ] . V_12 -> V_13 == V_44 -> V_12 ) ||
( V_44 -> V_81 &&
strcmp ( V_11 -> V_80 [ V_77 ] . V_82 , F_15 ( V_44 -> V_81 ) ) ) )
break;
F_16 ( V_13 , L_1 , V_83 , V_13 , V_77 ) ;
if ( V_77 == V_11 -> V_79 )
return - V_84 ;
V_8 -> V_18 = V_11 -> V_80 + V_77 ;
return 0 ;
}
static void F_17 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_18 )
return;
V_8 -> V_18 = NULL ;
F_18 ( F_14 ( & V_8 -> V_9 ) ) ;
}
static int F_19 ( struct V_1 * V_2 , int V_85 )
{
struct V_7 * V_8 = F_2 ( V_2 , struct V_7 , V_9 ) ;
if ( V_85 )
return F_13 ( V_8 ) ;
F_17 ( V_8 ) ;
return 0 ;
}
static int F_20 ( struct V_86 * V_12 )
{
struct V_87 * V_88 ;
unsigned int V_89 ;
int V_50 ;
struct V_7 * V_8 ;
struct V_10 * V_11 = V_12 -> V_13 . V_14 ;
if ( ! V_11 )
return - V_21 ;
V_8 = F_21 ( & V_12 -> V_13 , sizeof( struct V_7 ) , V_90 ) ;
if ( ! V_8 )
return - V_91 ;
V_88 = F_22 ( V_12 , V_92 , 0 ) ;
V_89 = F_23 ( V_12 , 0 ) ;
if ( ! V_88 || ( int ) V_89 <= 0 ) {
F_24 ( & V_12 -> V_13 , L_2 ) ;
return - V_84 ;
}
if ( V_11 -> type != V_23 ) {
F_24 ( & V_12 -> V_13 , L_3 ) ;
return - V_21 ;
}
V_8 -> V_89 = V_89 ;
V_8 -> V_39 = F_25 ( & V_12 -> V_13 , V_88 ) ;
if ( F_26 ( V_8 -> V_39 ) )
return F_27 ( V_8 -> V_39 ) ;
V_8 -> V_12 = V_12 ;
V_8 -> V_9 . V_93 = V_94 ;
V_8 -> V_9 . V_13 = & V_12 -> V_13 ;
F_28 ( V_12 , & V_8 -> V_9 ) ;
F_29 ( & V_8 -> V_9 , & V_95 ) ;
F_30 ( & V_8 -> V_9 , & V_12 -> V_13 ) ;
snprintf ( V_8 -> V_9 . V_82 , V_96 , L_4 ,
F_15 ( & V_12 -> V_13 ) ) ;
V_50 = F_31 ( & V_8 -> V_9 ) ;
if ( V_50 < 0 )
return V_50 ;
F_32 ( & V_12 -> V_13 ) ;
F_16 ( & V_12 -> V_13 , L_5 ) ;
return 0 ;
}
static int F_33 ( struct V_86 * V_12 )
{
struct V_1 * V_9 = F_34 ( V_12 ) ;
struct V_7 * V_8 = F_2 ( V_9 , struct V_7 , V_9 ) ;
F_35 ( & V_8 -> V_9 ) ;
F_36 ( & V_12 -> V_13 ) ;
return 0 ;
}
