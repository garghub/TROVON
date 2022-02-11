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
V_36 -> V_37 = V_38 |
V_39 | V_40 |
V_41 | V_42 ;
V_36 -> type = V_43 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
const struct V_35 * V_36 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_7 ) ;
struct V_44 * V_45 = F_8 ( V_2 ) ;
struct V_1 * V_46 = F_9 ( V_45 ) ;
struct V_35 V_47 = { . type = V_48 ,
. V_37 = V_6 -> V_49 } ;
return F_10 ( V_46 , V_50 , V_51 , & V_47 ) ;
}
static void F_11 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 -> V_11 . V_12 ;
T_2 V_25 = 0x10 ;
F_5 ( 0x00000001 , V_6 -> V_33 + V_52 ) ;
F_5 ( 0x00000001 , V_6 -> V_33 + V_53 ) ;
F_12 ( 5 ) ;
F_5 ( 0x00000000 , V_6 -> V_33 + V_53 ) ;
switch ( V_9 -> type ) {
case V_14 :
if ( V_6 -> V_26 -> V_54 == 1 )
V_25 |= 1 ;
else
V_25 |= 3 ;
break;
case V_22 :
if ( ! V_6 -> V_26 -> V_54 || V_6 -> V_26 -> V_54 > 4 )
V_25 |= 0xf ;
else
V_25 |= ( 1 << V_6 -> V_26 -> V_54 ) - 1 ;
}
if ( V_6 -> V_26 -> V_55 == V_56 )
V_25 |= 0x8000 ;
F_5 ( V_25 , V_6 -> V_33 + V_57 ) ;
V_25 = 0 ;
if ( V_9 -> V_37 & V_58 )
V_25 |= 2 ;
if ( V_9 -> V_37 & V_59 )
V_25 |= 1 ;
F_5 ( V_25 , V_6 -> V_33 + V_60 ) ;
}
static int F_13 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 -> V_11 . V_12 ;
struct V_44 * V_45 = F_8 ( & V_6 -> V_7 ) ;
struct V_1 * V_46 = F_9 ( V_45 ) ;
struct V_61 * V_11 = F_14 ( & V_6 -> V_7 ) ;
struct V_35 V_36 ;
unsigned long V_62 , V_63 ;
int V_64 , V_65 ;
if ( V_6 -> V_26 )
return - V_66 ;
for ( V_64 = 0 ; V_64 < V_9 -> V_67 ; V_64 ++ )
if ( & V_9 -> V_68 [ V_64 ] . V_10 -> V_11 == V_45 -> V_10 )
break;
F_4 ( V_11 , L_2 , V_29 , V_11 , V_64 ) ;
if ( V_64 == V_9 -> V_67 )
return - V_69 ;
V_63 = V_70 | V_71 ;
switch ( V_9 -> type ) {
case V_14 :
if ( V_9 -> V_68 [ V_64 ] . V_54 != 1 )
V_63 |= V_72 ;
break;
case V_22 :
switch ( V_9 -> V_68 [ V_64 ] . V_54 ) {
default:
V_63 |= V_73 ;
case 3 :
V_63 |= V_74 ;
case 2 :
V_63 |= V_72 ;
}
}
V_36 . type = V_48 ;
V_65 = F_10 ( V_46 , V_50 , V_75 , & V_36 ) ;
if ( V_65 == - V_76 )
V_62 = V_63 ;
else if ( ! V_65 )
V_62 = F_15 ( & V_36 ,
V_63 ) ;
else
V_62 = 0 ;
if ( ! V_62 )
return - V_30 ;
V_6 -> V_49 = V_62 ;
V_6 -> V_26 = V_9 -> V_68 + V_64 ;
F_16 ( V_11 ) ;
F_11 ( V_6 ) ;
return 0 ;
}
static void F_17 ( struct V_5 * V_6 )
{
if ( ! V_6 -> V_26 )
return;
V_6 -> V_26 = NULL ;
F_18 ( F_14 ( & V_6 -> V_7 ) ) ;
}
static int F_19 ( struct V_1 * V_2 , int V_77 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_7 ) ;
if ( V_77 )
return F_13 ( V_6 ) ;
F_17 ( V_6 ) ;
return 0 ;
}
static T_3 int F_20 ( struct V_78 * V_10 )
{
struct V_79 * V_80 ;
unsigned int V_81 ;
int V_65 ;
struct V_5 * V_6 ;
struct V_8 * V_9 = V_10 -> V_11 . V_12 ;
V_80 = F_21 ( V_10 , V_82 , 0 ) ;
V_81 = F_22 ( V_10 , 0 ) ;
if ( ! V_80 || ( int ) V_81 <= 0 || ! V_9 ) {
F_23 ( & V_10 -> V_11 , L_3 ) ;
return - V_69 ;
}
if ( V_9 -> type != V_14 ) {
F_23 ( & V_10 -> V_11 , L_4 ) ;
return - V_30 ;
}
V_6 = F_24 ( sizeof( struct V_5 ) , V_83 ) ;
if ( ! V_6 )
return - V_84 ;
V_6 -> V_81 = V_81 ;
if ( ! F_25 ( V_80 -> V_85 , F_26 ( V_80 ) , V_10 -> V_86 ) ) {
F_23 ( & V_10 -> V_11 , L_5 ) ;
V_65 = - V_66 ;
goto V_87;
}
V_6 -> V_33 = F_27 ( V_80 -> V_85 , F_26 ( V_80 ) ) ;
if ( ! V_6 -> V_33 ) {
V_65 = - V_88 ;
F_23 ( & V_10 -> V_11 , L_6 ) ;
goto V_89;
}
V_6 -> V_10 = V_10 ;
F_28 ( V_10 , V_6 ) ;
F_29 ( & V_6 -> V_7 , & V_90 ) ;
F_30 ( & V_6 -> V_7 , & V_10 -> V_11 ) ;
snprintf ( V_6 -> V_7 . V_86 , V_91 , L_7 ,
F_31 ( V_9 -> V_28 -> V_11 ) ) ;
V_65 = F_32 ( V_9 -> V_28 , & V_6 -> V_7 ) ;
F_4 ( & V_10 -> V_11 , L_8 , V_29 , V_6 , V_65 ) ;
if ( V_65 < 0 )
goto V_92;
F_33 ( & V_10 -> V_11 ) ;
F_4 ( & V_10 -> V_11 , L_9 ) ;
return 0 ;
V_92:
F_34 ( V_6 -> V_33 ) ;
V_89:
F_35 ( V_80 -> V_85 , F_26 ( V_80 ) ) ;
V_87:
F_36 ( V_6 ) ;
return V_65 ;
}
static T_4 int F_37 ( struct V_78 * V_10 )
{
struct V_5 * V_6 = F_38 ( V_10 ) ;
struct V_79 * V_80 = F_21 ( V_10 , V_82 , 0 ) ;
F_39 ( & V_6 -> V_7 ) ;
F_40 ( & V_10 -> V_11 ) ;
F_34 ( V_6 -> V_33 ) ;
F_35 ( V_80 -> V_85 , F_26 ( V_80 ) ) ;
F_28 ( V_10 , NULL ) ;
F_36 ( V_6 ) ;
return 0 ;
}
static int T_5 F_41 ( void )
{
return F_42 ( & V_93 ) ;
}
static void T_6 F_43 ( void )
{
F_44 ( & V_93 ) ;
}
