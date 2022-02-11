T_1 F_1 ( T_2 V_1 )
{
struct V_2 * V_3 = V_4 -> V_5 -> V_6 ;
T_1 V_7 = V_1 & 0xffff8000 ;
if ( F_2 ( V_3 , L_1 ) )
return V_7 ;
return V_7 | ( ( V_1 & 0x300000000ull ) >> 19 ) ;
}
int F_3 ( T_2 V_1 )
{
int V_8 ;
struct V_9 T_3 * V_10 ;
if ( ! V_4 || ! V_4 -> V_11 )
return - V_12 ;
V_10 = V_4 -> V_11 ;
for ( V_8 = 0 ; V_8 < F_4 ( V_10 -> V_13 ) ; V_8 ++ ) {
T_1 V_14 = F_5 ( & V_10 -> V_13 [ V_8 ] . V_14 ) ;
T_1 V_15 = F_5 ( & V_10 -> V_13 [ V_8 ] . V_15 ) ;
if ( V_14 & V_16 && ( V_14 & V_15 & V_17 ) == F_1 ( V_1 ) )
return V_8 ;
}
return - V_18 ;
}
int F_6 ( T_2 V_1 , struct V_19 * V_20 )
{
int V_13 ;
T_1 V_14 ;
struct V_9 T_3 * V_10 ;
V_13 = F_3 ( V_1 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( ! V_4 || ! V_4 -> V_11 )
return - V_12 ;
V_10 = V_4 -> V_11 ;
V_14 = F_5 ( & V_10 -> V_13 [ V_13 ] . V_14 ) ;
switch ( V_14 & V_21 ) {
case V_22 :
V_20 -> V_23 = & V_10 -> V_24 ;
break;
case V_25 :
V_20 -> V_23 = & V_10 -> V_26 ;
break;
case V_27 :
V_20 -> V_23 = & V_10 -> V_28 ;
break;
default:
return - V_29 ;
}
switch ( V_14 & V_30 ) {
case V_31 :
V_20 -> V_32 = 8 ;
break;
case V_33 :
V_20 -> V_32 = 16 ;
break;
case V_34 :
V_20 -> V_32 = 32 ;
break;
default:
return - V_29 ;
}
return 0 ;
}
int F_7 ( struct V_19 * V_20 , void T_3 * V_35 , T_1 V_36 )
{
int V_37 = 0 ;
unsigned long V_38 ;
if ( ! V_4 || ! V_4 -> V_11 )
return - V_12 ;
F_8 ( & V_39 , V_38 ) ;
F_9 ( & V_4 -> V_11 -> V_36 , V_36 ) ;
switch ( V_20 -> V_32 ) {
case 8 :
F_10 ( V_35 , 0x0 ) ;
break;
case 16 :
F_11 ( V_35 , 0x0 ) ;
break;
case 32 :
F_9 ( V_35 , 0x0 ) ;
break;
default:
V_37 = - V_29 ;
break;
}
F_12 ( & V_39 , V_38 ) ;
return V_37 ;
}
static int F_13 ( struct V_40 * V_41 ,
struct V_2 * V_42 )
{
struct V_9 T_3 * V_10 = V_41 -> V_11 ;
F_14 ( & V_10 -> V_43 , V_44 ) ;
F_9 ( & V_10 -> V_45 , 0 ) ;
F_9 ( & V_10 -> V_46 , 0 ) ;
F_9 ( & V_10 -> V_47 , V_48 ) ;
F_9 ( & V_10 -> V_49 , V_50 ) ;
if ( F_2 ( V_42 , L_1 ) )
F_15 ( & V_10 -> V_51 , V_52 , V_53 ) ;
return 0 ;
}
static T_4 F_16 ( int V_54 , void * V_55 )
{
struct V_40 * V_41 = V_55 ;
struct V_9 T_3 * V_10 = V_41 -> V_11 ;
T_1 V_56 ;
unsigned long V_38 ;
F_8 ( & V_39 , V_38 ) ;
V_56 = F_5 ( & V_10 -> V_43 ) ;
if ( ! V_56 ) {
F_12 ( & V_39 , V_38 ) ;
return V_57 ;
}
F_9 ( & V_10 -> V_43 , V_44 ) ;
F_9 ( & V_10 -> V_45 , 0 ) ;
F_9 ( & V_10 -> V_46 , 0 ) ;
V_41 -> V_58 = V_56 ;
if ( V_56 & V_59 )
F_17 ( V_41 -> V_5 , L_2
L_3 , V_56 ) ;
if ( V_56 & V_60 )
F_17 ( V_41 -> V_5 , L_4
L_3 , V_56 ) ;
if ( V_56 & V_61 )
F_17 ( V_41 -> V_5 , L_5
L_3 , V_56 ) ;
if ( V_56 & V_62 )
F_17 ( V_41 -> V_5 , L_6
L_3 , V_56 ) ;
if ( V_56 & V_63 )
F_17 ( V_41 -> V_5 , L_7
L_3 , V_56 ) ;
if ( V_56 & V_64 ) {
F_17 ( V_41 -> V_5 , L_8
L_3 , V_56 ) ;
F_18 () ;
F_19 ( & V_41 -> V_65 ) ;
}
if ( V_56 & V_66 ) {
F_17 ( V_41 -> V_5 , L_9
L_3 , V_56 ) ;
F_18 () ;
F_19 ( & V_41 -> V_65 ) ;
}
if ( V_56 & V_67 ) {
F_18 () ;
F_19 ( & V_41 -> V_65 ) ;
}
if ( V_56 & ~ V_68 )
F_17 ( V_41 -> V_5 , L_10
L_3 , V_56 ) ;
F_12 ( & V_39 , V_38 ) ;
return V_69 ;
}
static int F_20 ( struct V_70 * V_5 )
{
int V_37 ;
if ( ! V_5 -> V_5 . V_6 ) {
F_17 ( & V_5 -> V_5 , L_11 ) ;
return - V_71 ;
}
V_4 = F_21 ( sizeof( * V_4 ) , V_72 ) ;
if ( ! V_4 )
return - V_73 ;
F_22 ( & V_5 -> V_5 , V_4 ) ;
F_23 ( & V_4 -> V_74 ) ;
F_24 ( & V_4 -> V_65 ) ;
V_4 -> V_11 = F_25 ( V_5 -> V_5 . V_6 , 0 ) ;
if ( ! V_4 -> V_11 ) {
F_17 ( & V_5 -> V_5 , L_12 ) ;
V_37 = - V_12 ;
goto V_75;
}
V_4 -> V_76 [ 0 ] = F_26 ( V_5 -> V_5 . V_6 , 0 ) ;
if ( ! V_4 -> V_76 [ 0 ] ) {
F_17 ( & V_5 -> V_5 , L_13 ) ;
V_37 = - V_12 ;
goto V_75;
}
V_4 -> V_5 = & V_5 -> V_5 ;
V_37 = F_13 ( V_4 , V_5 -> V_5 . V_6 ) ;
if ( V_37 < 0 )
goto V_75;
V_37 = F_27 ( V_4 -> V_76 [ 0 ] , F_16 , 0 ,
L_14 , V_4 ) ;
if ( V_37 != 0 ) {
F_17 ( & V_5 -> V_5 , L_15 ,
V_4 -> V_76 [ 0 ] ) ;
V_37 = V_4 -> V_76 [ 0 ] ;
goto V_75;
}
V_4 -> V_76 [ 1 ] = F_26 ( V_5 -> V_5 . V_6 , 1 ) ;
if ( V_4 -> V_76 [ 1 ] ) {
V_37 = F_27 ( V_4 -> V_76 [ 1 ] , F_16 ,
V_77 , L_16 , V_4 ) ;
if ( V_37 ) {
F_17 ( & V_5 -> V_5 , L_15 ,
V_4 -> V_76 [ 1 ] ) ;
V_37 = V_4 -> V_76 [ 1 ] ;
goto V_78;
}
}
F_9 ( & V_4 -> V_11 -> V_79 , V_80 ) ;
return 0 ;
V_78:
F_28 ( V_4 -> V_76 [ 0 ] , V_4 ) ;
V_75:
F_29 ( V_4 -> V_11 ) ;
F_30 ( V_4 ) ;
V_4 = NULL ;
return V_37 ;
}
static int F_31 ( struct V_70 * V_81 , T_5 V_82 )
{
struct V_40 * V_41 = F_32 ( & V_81 -> V_5 ) ;
struct V_9 T_3 * V_10 = V_41 -> V_11 ;
V_41 -> V_83 = F_33 ( sizeof( struct V_9 ) , V_72 ) ;
if ( ! V_41 -> V_83 )
return - V_73 ;
F_34 ( V_41 -> V_83 , V_10 , sizeof( struct V_9 ) ) ;
return 0 ;
}
static int F_35 ( struct V_70 * V_81 )
{
struct V_40 * V_41 = F_32 ( & V_81 -> V_5 ) ;
struct V_9 T_3 * V_10 = V_41 -> V_11 ;
if ( V_41 -> V_83 ) {
F_36 ( V_10 , V_41 -> V_83 ,
sizeof( struct V_9 ) ) ;
F_30 ( V_41 -> V_83 ) ;
V_41 -> V_83 = NULL ;
}
return 0 ;
}
static int T_6 F_37 ( void )
{
return F_38 ( & V_84 ) ;
}
