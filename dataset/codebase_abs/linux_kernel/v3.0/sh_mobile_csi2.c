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
static void F_6 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 -> V_11 . V_12 ;
T_2 V_25 = 0x10 ;
F_5 ( 0x00000001 , V_6 -> V_33 + V_35 ) ;
F_5 ( 0x00000001 , V_6 -> V_33 + V_36 ) ;
F_7 ( 5 ) ;
F_5 ( 0x00000000 , V_6 -> V_33 + V_36 ) ;
if ( V_6 -> V_26 -> V_37 & 3 )
V_25 |= V_6 -> V_26 -> V_37 & 3 ;
else
V_25 |= 3 ;
if ( V_6 -> V_26 -> V_38 == V_39 )
V_25 |= 0x8000 ;
F_5 ( V_25 , V_6 -> V_33 + V_40 ) ;
V_25 = 0 ;
if ( V_9 -> V_41 & V_42 )
V_25 |= 2 ;
if ( V_9 -> V_41 & V_43 )
V_25 |= 1 ;
F_5 ( V_25 , V_6 -> V_33 + V_44 ) ;
}
static int F_8 ( struct V_45 * V_46 ,
unsigned long V_41 )
{
return 0 ;
}
static unsigned long F_9 ( struct V_45 * V_46 )
{
struct V_47 * V_48 = F_10 ( V_46 ) ;
const unsigned long V_41 = V_49 |
V_50 | V_51 |
V_52 | V_53 | V_54 ;
return F_11 ( V_48 , V_41 ) ;
}
static int F_12 ( struct V_55 * V_56 ,
unsigned long V_57 , void * V_58 )
{
struct V_59 * V_11 = V_58 ;
struct V_45 * V_46 = F_13 ( V_11 ) ;
struct V_60 * V_28 = F_14 ( V_11 -> V_61 ) ;
struct V_5 * V_6 =
F_2 ( V_56 , struct V_5 , V_62 ) ;
struct V_8 * V_9 = V_6 -> V_10 -> V_11 . V_12 ;
int V_63 , V_64 ;
for ( V_64 = 0 ; V_64 < V_9 -> V_65 ; V_64 ++ )
if ( & V_9 -> V_66 [ V_64 ] . V_10 -> V_11 == V_46 -> V_10 )
break;
F_4 ( V_11 , L_2 , V_29 , V_11 , V_57 , V_64 ) ;
if ( V_64 == V_9 -> V_65 )
return V_67 ;
switch ( V_57 ) {
case V_68 :
snprintf ( V_6 -> V_7 . V_69 , V_70 , L_3 ,
F_15 ( V_28 -> V_11 ) , L_4 ) ;
V_6 -> V_7 . V_71 = ( long ) V_46 ;
V_63 = F_16 ( V_28 , & V_6 -> V_7 ) ;
F_4 ( V_11 , L_5 , V_29 , V_6 , V_63 ) ;
if ( V_63 < 0 )
return V_67 ;
V_6 -> V_26 = V_9 -> V_66 + V_64 ;
V_6 -> V_72 = V_46 -> V_73 -> V_72 ;
V_6 -> V_74 = V_46 -> V_73 -> V_74 ;
V_46 -> V_73 -> V_72 = F_8 ;
V_46 -> V_73 -> V_74 = F_9 ;
F_17 ( F_18 ( & V_6 -> V_7 ) ) ;
F_6 ( V_6 ) ;
break;
case V_75 :
V_6 -> V_26 = NULL ;
V_46 -> V_73 -> V_72 = V_6 -> V_72 ;
V_46 -> V_73 -> V_74 = V_6 -> V_74 ;
V_6 -> V_72 = NULL ;
V_6 -> V_74 = NULL ;
F_19 ( & V_6 -> V_7 ) ;
F_20 ( F_18 ( & V_6 -> V_7 ) ) ;
break;
}
return V_76 ;
}
static T_3 int F_21 ( struct V_77 * V_10 )
{
struct V_78 * V_79 ;
unsigned int V_80 ;
int V_63 ;
struct V_5 * V_6 ;
struct V_8 * V_9 = V_10 -> V_11 . V_12 ;
V_79 = F_22 ( V_10 , V_81 , 0 ) ;
V_80 = F_23 ( V_10 , 0 ) ;
if ( ! V_79 || ( int ) V_80 <= 0 || ! V_9 ) {
F_24 ( & V_10 -> V_11 , L_6 ) ;
return - V_82 ;
}
if ( V_9 -> type != V_14 ) {
F_24 ( & V_10 -> V_11 , L_7 ) ;
return - V_30 ;
}
V_6 = F_25 ( sizeof( struct V_5 ) , V_83 ) ;
if ( ! V_6 )
return - V_84 ;
V_6 -> V_80 = V_80 ;
V_6 -> V_62 . V_85 = F_12 ;
V_63 = F_26 ( & V_86 , & V_6 -> V_62 ) ;
if ( V_63 < 0 ) {
F_24 ( & V_10 -> V_11 , L_8 ) ;
goto V_87;
}
if ( ! F_27 ( V_79 -> V_88 , F_28 ( V_79 ) , V_10 -> V_69 ) ) {
F_24 ( & V_10 -> V_11 , L_9 ) ;
V_63 = - V_89 ;
goto V_90;
}
V_6 -> V_33 = F_29 ( V_79 -> V_88 , F_28 ( V_79 ) ) ;
if ( ! V_6 -> V_33 ) {
V_63 = - V_91 ;
F_24 ( & V_10 -> V_11 , L_10 ) ;
goto V_92;
}
V_6 -> V_10 = V_10 ;
F_30 ( & V_6 -> V_7 , & V_93 ) ;
F_31 ( & V_6 -> V_7 , & V_10 -> V_11 ) ;
F_32 ( V_10 , V_6 ) ;
F_33 ( & V_10 -> V_11 ) ;
F_4 ( & V_10 -> V_11 , L_11 ) ;
return 0 ;
V_92:
F_34 ( V_79 -> V_88 , F_28 ( V_79 ) ) ;
V_90:
F_35 ( & V_86 , & V_6 -> V_62 ) ;
V_87:
F_36 ( V_6 ) ;
return V_63 ;
}
static T_4 int F_37 ( struct V_77 * V_10 )
{
struct V_5 * V_6 = F_38 ( V_10 ) ;
struct V_78 * V_79 = F_22 ( V_10 , V_81 , 0 ) ;
F_35 ( & V_86 , & V_6 -> V_62 ) ;
F_39 ( & V_10 -> V_11 ) ;
F_40 ( V_6 -> V_33 ) ;
F_34 ( V_79 -> V_88 , F_28 ( V_79 ) ) ;
F_32 ( V_10 , NULL ) ;
F_36 ( V_6 ) ;
return 0 ;
}
static int T_5 F_41 ( void )
{
return F_42 ( & V_94 , F_21 ) ;
}
static void T_6 F_43 ( void )
{
F_44 ( & V_94 ) ;
}
