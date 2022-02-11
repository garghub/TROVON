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
static int F_12 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 -> V_11 . V_12 ;
struct V_1 * V_2 , * V_55 = & V_6 -> V_7 ;
struct V_45 * V_46 = NULL ;
struct V_56 * V_11 = F_13 ( & V_6 -> V_7 ) ;
int V_57 ;
F_14 (sd, csi2_sd->v4l2_dev)
if ( V_2 -> V_58 ) {
V_46 = (struct V_45 * ) V_2 -> V_58 ;
break;
}
if ( ! V_46 )
return - V_30 ;
for ( V_57 = 0 ; V_57 < V_9 -> V_59 ; V_57 ++ )
if ( & V_9 -> V_60 [ V_57 ] . V_10 -> V_11 == V_46 -> V_10 )
break;
F_4 ( V_11 , L_2 , V_29 , V_11 , V_57 ) ;
if ( V_57 == V_9 -> V_59 )
return - V_61 ;
V_6 -> V_26 = V_9 -> V_60 + V_57 ;
V_6 -> V_62 = V_46 -> V_63 -> V_62 ;
V_6 -> V_64 = V_46 -> V_63 -> V_64 ;
V_46 -> V_63 -> V_62 = F_8 ;
V_46 -> V_63 -> V_64 = F_9 ;
V_55 -> V_58 = ( long ) V_46 ;
F_15 ( V_11 ) ;
F_6 ( V_6 ) ;
return 0 ;
}
static void F_16 ( struct V_5 * V_6 )
{
struct V_45 * V_46 = (struct V_45 * ) V_6 -> V_7 . V_58 ;
V_6 -> V_26 = NULL ;
V_6 -> V_7 . V_58 = 0 ;
V_46 -> V_63 -> V_62 = V_6 -> V_62 ;
V_46 -> V_63 -> V_64 = V_6 -> V_64 ;
V_6 -> V_62 = NULL ;
V_6 -> V_64 = NULL ;
F_17 ( F_13 ( & V_6 -> V_7 ) ) ;
}
static int F_18 ( struct V_1 * V_2 , int V_65 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_7 ) ;
if ( V_65 )
return F_12 ( V_6 ) ;
F_16 ( V_6 ) ;
return 0 ;
}
static T_3 int F_19 ( struct V_66 * V_10 )
{
struct V_67 * V_68 ;
unsigned int V_69 ;
int V_70 ;
struct V_5 * V_6 ;
struct V_8 * V_9 = V_10 -> V_11 . V_12 ;
V_68 = F_20 ( V_10 , V_71 , 0 ) ;
V_69 = F_21 ( V_10 , 0 ) ;
if ( ! V_68 || ( int ) V_69 <= 0 || ! V_9 ) {
F_22 ( & V_10 -> V_11 , L_3 ) ;
return - V_61 ;
}
if ( V_9 -> type != V_14 ) {
F_22 ( & V_10 -> V_11 , L_4 ) ;
return - V_30 ;
}
V_6 = F_23 ( sizeof( struct V_5 ) , V_72 ) ;
if ( ! V_6 )
return - V_73 ;
V_6 -> V_69 = V_69 ;
if ( ! F_24 ( V_68 -> V_74 , F_25 ( V_68 ) , V_10 -> V_75 ) ) {
F_22 ( & V_10 -> V_11 , L_5 ) ;
V_70 = - V_76 ;
goto V_77;
}
V_6 -> V_33 = F_26 ( V_68 -> V_74 , F_25 ( V_68 ) ) ;
if ( ! V_6 -> V_33 ) {
V_70 = - V_78 ;
F_22 ( & V_10 -> V_11 , L_6 ) ;
goto V_79;
}
V_6 -> V_10 = V_10 ;
F_27 ( V_10 , V_6 ) ;
F_28 ( & V_6 -> V_7 , & V_80 ) ;
F_29 ( & V_6 -> V_7 , & V_10 -> V_11 ) ;
snprintf ( V_6 -> V_7 . V_75 , V_81 , L_7 ,
F_30 ( V_9 -> V_28 -> V_11 ) ) ;
V_70 = F_31 ( V_9 -> V_28 , & V_6 -> V_7 ) ;
F_4 ( & V_10 -> V_11 , L_8 , V_29 , V_6 , V_70 ) ;
if ( V_70 < 0 )
goto V_82;
F_32 ( & V_10 -> V_11 ) ;
F_4 ( & V_10 -> V_11 , L_9 ) ;
return 0 ;
V_82:
F_33 ( V_6 -> V_33 ) ;
V_79:
F_34 ( V_68 -> V_74 , F_25 ( V_68 ) ) ;
V_77:
F_35 ( V_6 ) ;
return V_70 ;
}
static T_4 int F_36 ( struct V_66 * V_10 )
{
struct V_5 * V_6 = F_37 ( V_10 ) ;
struct V_67 * V_68 = F_20 ( V_10 , V_71 , 0 ) ;
F_38 ( & V_6 -> V_7 ) ;
F_39 ( & V_10 -> V_11 ) ;
F_33 ( V_6 -> V_33 ) ;
F_34 ( V_68 -> V_74 , F_25 ( V_68 ) ) ;
F_27 ( V_10 , NULL ) ;
F_35 ( V_6 ) ;
return 0 ;
}
static int T_5 F_40 ( void )
{
return F_41 ( & V_83 ) ;
}
static void T_6 F_42 ( void )
{
F_43 ( & V_83 ) ;
}
