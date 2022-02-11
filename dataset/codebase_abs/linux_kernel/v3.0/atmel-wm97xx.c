static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
struct V_4 * V_5 = V_3 -> V_5 ;
int V_6 = F_2 ( V_3 , V_7 ) ;
T_1 V_8 = V_9 ;
if ( V_6 & V_10 ) {
F_3 ( & V_5 -> V_11 -> V_12 , L_1 ) ;
F_2 ( V_3 , V_13 ) ;
V_8 = V_14 ;
} else if ( V_6 & V_15 ) {
T_2 V_16 ;
T_2 V_17 ;
T_2 V_18 ;
T_2 V_19 ;
V_16 = F_2 ( V_3 , V_13 ) ;
V_17 = V_16 & 0x0fff ;
V_18 = V_16 & V_20 ;
V_19 = ( V_16 & V_21 ) >> 8 ;
if ( V_18 == V_22 )
V_3 -> V_23 = V_17 ;
if ( V_18 == V_24 )
V_3 -> V_25 = V_17 ;
if ( ! V_26 && V_18 == V_24 ) {
F_4 ( V_5 -> V_27 , V_28 , V_3 -> V_23 ) ;
F_4 ( V_5 -> V_27 , V_29 , V_3 -> V_25 ) ;
F_5 ( V_5 -> V_27 , V_30 , V_19 ) ;
F_6 ( V_5 -> V_27 ) ;
} else if ( V_26 && V_18 == V_31 ) {
F_4 ( V_5 -> V_27 , V_28 , V_3 -> V_23 ) ;
F_4 ( V_5 -> V_27 , V_29 , V_3 -> V_25 ) ;
F_4 ( V_5 -> V_27 , V_32 , V_17 ) ;
F_5 ( V_5 -> V_27 , V_30 , V_17 ) ;
F_6 ( V_5 -> V_27 ) ;
}
V_8 = V_14 ;
}
return V_8 ;
}
static void F_7 ( struct V_4 * V_5 )
{
struct V_3 * V_3 = F_8 ( V_5 -> V_11 ) ;
struct V_27 * V_27 = V_5 -> V_27 ;
int V_19 = F_9 ( V_3 -> V_33 ) ;
if ( V_19 != 0 ) {
F_10 ( & V_3 -> V_34 ,
V_35 + F_11 ( 1 ) ) ;
} else {
if ( V_26 )
F_4 ( V_27 , V_32 , 0 ) ;
F_5 ( V_27 , V_30 , 0 ) ;
F_6 ( V_27 ) ;
}
}
static void F_12 ( unsigned long V_16 )
{
F_7 ( (struct V_4 * ) V_16 ) ;
}
static int F_13 ( struct V_4 * V_5 )
{
struct V_3 * V_3 = F_8 ( V_5 -> V_11 ) ;
int V_36 = 0 ;
if ( V_5 -> V_37 == NULL )
return - V_38 ;
for ( V_36 = 0 ; V_36 < F_14 ( V_39 ) ; V_36 ++ ) {
if ( V_5 -> V_40 != V_39 [ V_36 ] . V_40 )
continue;
V_41 = V_36 ;
if ( V_42 <= V_39 [ V_36 ] . V_43 )
break;
}
V_5 -> V_44 = V_39 [ V_41 ] . V_45 ;
V_5 -> V_46 = V_47 ;
F_15 ( & V_5 -> V_11 -> V_12 , L_2
L_3 , V_39 [ V_41 ] . V_43 ) ;
if ( V_48 ) {
unsigned long V_49 ;
V_5 -> V_50 = V_3 -> V_51 ;
switch ( V_5 -> V_40 ) {
case V_52 :
case V_53 :
F_16 ( V_5 , V_54 , V_55 ,
V_56 ,
V_57 ,
V_58 ) ;
F_16 ( V_5 , V_59 , V_60 ,
V_56 ,
V_61 ,
V_62 ) ;
case V_63 :
V_49 = F_2 ( V_3 , V_64 ) ;
V_49 &= ~ F_17 ( V_5 -> V_46 ) ;
V_49 |= F_18 ( V_5 -> V_46 , V_65 ) ;
F_19 ( V_3 , V_64 , V_49 ) ;
F_19 ( V_3 , V_66 , V_67
| V_68
| V_69
| V_10
| V_15 ) ;
F_2 ( V_3 , V_13 ) ;
F_19 ( V_3 , V_70 , V_71 ) ;
break;
default:
F_20 ( & V_5 -> V_11 -> V_12 , L_4
L_5 ) ;
V_48 = 0 ;
break;
}
}
return 0 ;
}
static void F_21 ( struct V_4 * V_5 )
{
if ( V_48 ) {
struct V_3 * V_3 =
F_8 ( V_5 -> V_11 ) ;
unsigned long V_72 ;
switch ( V_5 -> V_40 & 0xffff ) {
case V_63 :
case V_52 :
case V_53 :
V_72 = F_2 ( V_3 , V_64 ) ;
V_72 &= ~ F_17 ( V_5 -> V_46 ) ;
F_19 ( V_3 , V_64 , V_72 ) ;
F_19 ( V_3 , V_73 , V_71 ) ;
F_19 ( V_3 , V_66 , 0 ) ;
V_5 -> V_50 = 0 ;
break;
default:
F_20 ( & V_5 -> V_11 -> V_12 , L_6 ) ;
break;
}
}
}
static void F_22 ( struct V_4 * V_5 , int V_74 )
{
}
static int T_3 F_23 ( struct V_75 * V_76 )
{
struct V_4 * V_5 = F_8 ( V_76 ) ;
struct V_3 * V_3 ;
int V_77 ;
V_3 = F_24 ( sizeof( struct V_3 ) , V_78 ) ;
if ( ! V_3 ) {
F_3 ( & V_76 -> V_12 , L_7 ) ;
return - V_79 ;
}
V_3 -> V_5 = V_5 ;
V_3 -> V_80 = ( void * ) V_81 ;
V_3 -> V_82 = V_83 ;
V_3 -> V_33 = V_84 ;
V_3 -> V_51 = F_25 ( V_3 -> V_33 ) ;
F_26 ( & V_3 -> V_34 , F_12 ,
( unsigned long ) V_5 ) ;
V_77 = F_27 ( V_3 -> V_82 ,
F_1 ,
V_85 , L_8 , V_3 ) ;
if ( V_77 ) {
F_3 ( & V_76 -> V_12 , L_9 ) ;
goto V_86;
}
F_28 ( V_76 , V_3 ) ;
V_77 = F_29 ( V_5 , & V_87 ) ;
if ( V_77 )
goto V_88;
return V_77 ;
V_88:
F_30 ( V_3 -> V_82 , V_3 ) ;
V_86:
F_28 ( V_76 , NULL ) ;
F_31 ( V_3 ) ;
return V_77 ;
}
static int T_4 F_32 ( struct V_75 * V_76 )
{
struct V_3 * V_3 = F_8 ( V_76 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_19 ( V_3 , V_73 , V_71 ) ;
F_30 ( V_3 -> V_82 , V_3 ) ;
F_33 ( & V_3 -> V_34 ) ;
F_34 ( V_5 ) ;
F_28 ( V_76 , NULL ) ;
F_31 ( V_3 ) ;
return 0 ;
}
static int F_35 ( struct V_75 * V_76 , T_5 V_89 )
{
struct V_3 * V_3 = F_8 ( V_76 ) ;
F_19 ( V_3 , V_73 , V_71 ) ;
F_36 ( V_3 -> V_51 ) ;
F_33 ( & V_3 -> V_34 ) ;
return 0 ;
}
static int F_37 ( struct V_75 * V_76 )
{
struct V_3 * V_3 = F_8 ( V_76 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
if ( V_5 -> V_27 -> V_90 ) {
F_38 ( V_3 -> V_51 ) ;
F_19 ( V_3 , V_70 , V_71 ) ;
}
return 0 ;
}
static int T_3 F_39 ( void )
{
return F_40 ( & V_91 , F_23 ) ;
}
static void T_4 F_41 ( void )
{
F_42 ( & V_91 ) ;
}
