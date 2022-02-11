static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_4 = V_2 -> V_4 ;
T_1 V_5 = V_2 -> V_6 -> V_5 ;
T_1 V_7 = V_2 -> V_6 -> V_8 ;
T_1 V_9 = V_2 -> V_6 -> V_10 & 0xf ;
T_1 V_11 = V_2 -> V_6 -> V_12 & 0xf ;
if ( V_2 -> V_6 -> V_12 > V_13 ||
V_2 -> V_6 -> V_10 > V_14 ||
V_2 -> V_6 -> V_8 > V_15 ||
V_2 -> V_6 -> V_5 > V_15 )
return - V_16 ;
V_3 = F_2 ( V_4 , V_17 ,
( V_9 << V_18 ) | V_11 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_4 , V_19 , V_20 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_4 , V_21 , V_20 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_4 , V_22 , V_5 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_4 , V_23 , V_7 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_3 ( V_4 , V_24 , 0x0 , V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_4 , V_26 ,
V_27 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_4 , V_28 ,
V_27 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_4 , V_29 ,
V_27 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_4 , V_30 ,
V_27 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_4 , V_31 ,
V_27 ) ;
return V_3 ;
}
static T_2 F_4 ( int V_32 , void * V_33 )
{
struct V_1 * V_2 = V_33 ;
struct V_4 * V_4 = V_2 -> V_4 ;
T_1 V_34 , V_35 , V_36 , V_37 , V_38 ;
T_1 V_39 ;
for ( V_34 = 0 ; V_34 < V_40 * 2 ; V_34 ++ ) {
V_37 = F_5 ( V_4 , V_41 ) ;
if ( V_37 == V_42 ||
V_37 == V_43 )
continue;
V_36 = V_37 & V_44 ;
V_35 = ( V_37 & V_45 ) >> V_18 ;
V_39 = F_6 ( V_35 , V_36 ,
V_46 ) ;
V_38 = V_37 & V_47 ;
F_7 ( V_2 -> V_48 , V_49 , V_50 , V_39 ) ;
F_8 ( V_2 -> V_48 , V_2 -> V_51 [ V_39 ] , ! V_38 ) ;
F_9 ( V_2 -> V_48 ) ;
}
F_3 ( V_4 , V_52 ,
0x0 , V_53 | V_54 ) ;
F_3 ( V_4 , V_55 ,
0x0 , V_56 | V_57 ) ;
return V_58 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_2 -> V_4 ;
int V_3 ;
V_3 = F_3 ( V_4 , V_59 , V_60 , 0x0 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_3 ( V_4 , V_61 , 0x0 , V_62 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_3 ( V_4 , V_63 , 0x0 , V_64 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_3 ( V_4 , V_65 , 0x0 , 0x1 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_3 ( V_4 , V_55 , 0x0 ,
V_56 | V_57 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_66 = false ;
return V_3 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_2 -> V_4 ;
int V_3 ;
V_3 = F_3 ( V_4 , V_52 ,
0x0 , V_53 | V_54 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_3 ( V_4 , V_55 ,
~ ( V_56 | V_57 ) , 0x0 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_3 ( V_4 , V_63 , 0x1 , 0x0 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_3 ( V_4 , V_59 , V_60 , 0x1 ) ;
V_2 -> V_66 = true ;
return V_3 ;
}
static int F_12 ( struct V_67 * V_48 )
{
int error ;
struct V_1 * V_2 = F_13 ( V_48 ) ;
error = F_10 ( V_2 ) ;
if ( error < 0 ) {
F_14 ( & V_48 -> V_33 , L_1 ) ;
return error ;
}
error = F_1 ( V_2 ) ;
if ( error < 0 ) {
F_14 ( & V_48 -> V_33 , L_2 ) ;
return error ;
}
return 0 ;
}
static void F_15 ( struct V_67 * V_48 )
{
struct V_1 * V_2 = F_13 ( V_48 ) ;
F_11 ( V_2 ) ;
}
static int T_3 F_16 ( struct V_68 * V_69 )
{
struct V_4 * V_4 = F_17 ( V_69 -> V_33 . V_70 ) ;
struct V_1 * V_2 ;
struct V_67 * V_48 ;
const struct V_71 * V_72 ;
int error , V_32 ;
V_72 = V_4 -> V_73 -> V_2 ;
if ( ! V_72 ) {
F_14 ( & V_69 -> V_33 , L_3 ) ;
return - V_16 ;
}
V_32 = F_18 ( V_69 , 0 ) ;
if ( V_32 < 0 )
return V_32 ;
V_2 = F_19 ( sizeof( struct V_1 ) , V_74 ) ;
V_48 = F_20 () ;
if ( ! V_2 || ! V_48 ) {
F_14 ( & V_69 -> V_33 , L_4 ) ;
error = - V_75 ;
goto V_76;
}
V_2 -> V_6 = V_72 ;
V_2 -> V_48 = V_48 ;
V_2 -> V_4 = V_4 ;
V_48 -> V_77 . V_78 = V_79 ;
V_48 -> V_80 = V_69 -> V_80 ;
V_48 -> V_33 . V_70 = & V_69 -> V_33 ;
V_48 -> V_81 = V_2 -> V_51 ;
V_48 -> V_82 = sizeof( V_2 -> V_51 [ 0 ] ) ;
V_48 -> V_83 = F_21 ( V_2 -> V_51 ) ;
V_48 -> V_84 = F_12 ;
V_48 -> V_85 = F_15 ;
F_22 ( V_48 , V_2 ) ;
F_23 ( V_48 , V_49 , V_50 ) ;
F_24 ( V_86 , V_48 -> V_87 ) ;
if ( ! V_72 -> V_88 )
F_24 ( V_89 , V_48 -> V_87 ) ;
F_25 ( V_72 -> V_90 , 0x3 ,
V_48 -> V_81 , V_48 -> V_91 ) ;
error = F_26 ( V_32 , NULL ,
F_4 , V_72 -> V_92 ,
L_5 , V_2 ) ;
if ( error < 0 ) {
F_14 ( & V_69 -> V_33 ,
L_6 ,
V_32 , error ) ;
goto V_76;
}
error = F_27 ( V_48 ) ;
if ( error ) {
F_14 ( & V_69 -> V_33 , L_7 ) ;
goto V_93;
}
F_28 ( & V_69 -> V_33 , V_72 -> V_94 ) ;
F_29 ( & V_69 -> V_33 , V_72 -> V_94 ) ;
F_30 ( V_69 , V_2 ) ;
return 0 ;
V_93:
F_31 ( V_32 , V_2 ) ;
V_76:
F_32 ( V_48 ) ;
F_33 ( V_2 ) ;
return error ;
}
static int T_4 F_34 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = F_35 ( V_69 ) ;
int V_32 = F_18 ( V_69 , 0 ) ;
if ( ! V_2 -> V_66 )
F_11 ( V_2 ) ;
F_31 ( V_32 , V_2 ) ;
F_36 ( V_2 -> V_48 ) ;
F_33 ( V_2 ) ;
return 0 ;
}
static int F_37 ( struct V_95 * V_33 )
{
struct V_68 * V_69 = F_38 ( V_33 ) ;
struct V_1 * V_2 = F_35 ( V_69 ) ;
int V_32 = F_18 ( V_69 , 0 ) ;
if ( V_2 -> V_66 )
return 0 ;
if ( ! F_39 ( & V_69 -> V_33 ) )
F_11 ( V_2 ) ;
else
F_40 ( V_32 ) ;
return 0 ;
}
static int F_41 ( struct V_95 * V_33 )
{
struct V_68 * V_69 = F_38 ( V_33 ) ;
struct V_1 * V_2 = F_35 ( V_69 ) ;
int V_32 = F_18 ( V_69 , 0 ) ;
if ( ! V_2 -> V_66 )
return 0 ;
if ( ! F_39 ( & V_69 -> V_33 ) )
F_10 ( V_2 ) ;
else
F_42 ( V_32 ) ;
return 0 ;
}
static int T_5 F_43 ( void )
{
return F_44 ( & V_96 ) ;
}
static void T_6 F_45 ( void )
{
return F_46 ( & V_96 ) ;
}
