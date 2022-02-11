static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_4 = V_2 -> V_4 ;
const struct V_5 * V_6 = V_2 -> V_6 ;
if ( V_6 -> V_7 > V_8 || V_6 -> V_9 > V_10 )
return - V_11 ;
V_3 = F_2 ( V_4 , V_12 ,
( V_6 -> V_9 << V_13 ) | V_6 -> V_7 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_4 , V_14 , V_15 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_4 , V_16 , V_15 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_4 , V_17 ,
V_6 -> V_18 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_4 , V_19 ,
V_6 -> V_20 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_3 ( V_4 , V_21 , 0x0 , V_22 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_4 , V_23 ,
V_24 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_4 , V_25 ,
V_24 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_4 , V_26 ,
V_24 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_4 , V_27 ,
V_24 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_4 , V_28 ,
V_24 ) ;
return V_3 ;
}
static T_1 F_4 ( int V_29 , void * V_30 )
{
struct V_1 * V_2 = V_30 ;
struct V_4 * V_4 = V_2 -> V_4 ;
T_2 V_31 , V_32 , V_33 , V_34 , V_35 ;
T_2 V_36 ;
for ( V_31 = 0 ; V_31 < V_37 * 2 ; V_31 ++ ) {
V_34 = F_5 ( V_4 , V_38 ) ;
if ( V_34 == V_39 ||
V_34 == V_40 )
continue;
V_33 = V_34 & V_41 ;
V_32 = ( V_34 & V_42 ) >> V_13 ;
V_36 = F_6 ( V_32 , V_33 ,
V_43 ) ;
V_35 = V_34 & V_44 ;
F_7 ( V_2 -> V_45 , V_46 , V_47 , V_36 ) ;
F_8 ( V_2 -> V_45 , V_2 -> V_48 [ V_36 ] , ! V_35 ) ;
F_9 ( V_2 -> V_45 ) ;
}
F_3 ( V_4 , V_49 ,
0x0 , V_50 | V_51 ) ;
F_3 ( V_4 , V_52 ,
0x0 , V_53 | V_54 ) ;
return V_55 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_2 -> V_4 ;
int V_3 ;
V_3 = F_3 ( V_4 , V_56 , V_57 , 0x0 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_3 ( V_4 , V_58 , 0x0 , V_59 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_3 ( V_4 , V_60 , 0x0 , V_61 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_3 ( V_4 , V_62 , 0x0 , 0x1 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_3 ( V_4 , V_52 , 0x0 ,
V_53 | V_54 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_63 = false ;
return V_3 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_2 -> V_4 ;
int V_3 ;
V_3 = F_3 ( V_4 , V_49 ,
0x0 , V_50 | V_51 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_3 ( V_4 , V_52 ,
~ ( V_53 | V_54 ) , 0x0 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_3 ( V_4 , V_60 , 0x1 , 0x0 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_3 ( V_4 , V_56 , V_57 , 0x1 ) ;
V_2 -> V_63 = true ;
return V_3 ;
}
static int F_12 ( struct V_64 * V_45 )
{
int error ;
struct V_1 * V_2 = F_13 ( V_45 ) ;
error = F_10 ( V_2 ) ;
if ( error < 0 ) {
F_14 ( & V_45 -> V_30 , L_1 ) ;
return error ;
}
error = F_1 ( V_2 ) ;
if ( error < 0 ) {
F_14 ( & V_45 -> V_30 , L_2 ) ;
return error ;
}
return 0 ;
}
static void F_15 ( struct V_64 * V_45 )
{
struct V_1 * V_2 = F_13 ( V_45 ) ;
F_11 ( V_2 ) ;
}
static int F_16 ( struct V_65 * V_66 )
{
struct V_4 * V_4 = F_17 ( V_66 -> V_30 . V_67 ) ;
struct V_1 * V_2 ;
struct V_64 * V_45 ;
const struct V_5 * V_68 ;
int error , V_29 ;
V_68 = V_4 -> V_69 -> V_2 ;
if ( ! V_68 ) {
F_14 ( & V_66 -> V_30 , L_3 ) ;
return - V_11 ;
}
V_29 = F_18 ( V_66 , 0 ) ;
if ( V_29 < 0 )
return V_29 ;
V_2 = F_19 ( sizeof( struct V_1 ) , V_70 ) ;
V_45 = F_20 () ;
if ( ! V_2 || ! V_45 ) {
F_14 ( & V_66 -> V_30 , L_4 ) ;
error = - V_71 ;
goto V_72;
}
V_2 -> V_6 = V_68 ;
V_2 -> V_45 = V_45 ;
V_2 -> V_4 = V_4 ;
V_45 -> V_73 . V_74 = V_75 ;
V_45 -> V_76 = V_66 -> V_76 ;
V_45 -> V_30 . V_67 = & V_66 -> V_30 ;
V_45 -> V_77 = F_12 ;
V_45 -> V_78 = F_15 ;
error = F_21 ( V_68 -> V_79 , NULL ,
V_10 , V_8 ,
V_2 -> V_48 , V_45 ) ;
if ( error ) {
F_14 ( & V_66 -> V_30 , L_5 ) ;
goto V_72;
}
F_22 ( V_45 , V_46 , V_47 ) ;
if ( ! V_68 -> V_80 )
F_23 ( V_81 , V_45 -> V_82 ) ;
F_24 ( V_45 , V_2 ) ;
error = F_25 ( V_29 , NULL ,
F_4 , V_68 -> V_83 ,
L_6 , V_2 ) ;
if ( error < 0 ) {
F_14 ( & V_66 -> V_30 ,
L_7 ,
V_29 , error ) ;
goto V_72;
}
error = F_26 ( V_45 ) ;
if ( error ) {
F_14 ( & V_66 -> V_30 , L_8 ) ;
goto V_84;
}
F_27 ( & V_66 -> V_30 , V_68 -> V_85 ) ;
F_28 ( & V_66 -> V_30 , V_68 -> V_85 ) ;
F_29 ( V_66 , V_2 ) ;
return 0 ;
V_84:
F_30 ( V_29 , V_2 ) ;
V_72:
F_31 ( V_45 ) ;
F_32 ( V_2 ) ;
return error ;
}
static int F_33 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = F_34 ( V_66 ) ;
int V_29 = F_18 ( V_66 , 0 ) ;
if ( ! V_2 -> V_63 )
F_11 ( V_2 ) ;
F_30 ( V_29 , V_2 ) ;
F_35 ( V_2 -> V_45 ) ;
F_32 ( V_2 ) ;
return 0 ;
}
static int F_36 ( struct V_86 * V_30 )
{
struct V_65 * V_66 = F_37 ( V_30 ) ;
struct V_1 * V_2 = F_34 ( V_66 ) ;
int V_29 = F_18 ( V_66 , 0 ) ;
if ( V_2 -> V_63 )
return 0 ;
if ( ! F_38 ( & V_66 -> V_30 ) )
F_11 ( V_2 ) ;
else
F_39 ( V_29 ) ;
return 0 ;
}
static int F_40 ( struct V_86 * V_30 )
{
struct V_65 * V_66 = F_37 ( V_30 ) ;
struct V_1 * V_2 = F_34 ( V_66 ) ;
int V_29 = F_18 ( V_66 , 0 ) ;
if ( ! V_2 -> V_63 )
return 0 ;
if ( ! F_38 ( & V_66 -> V_30 ) )
F_10 ( V_2 ) ;
else
F_41 ( V_29 ) ;
return 0 ;
}
