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
static const struct V_5 *
F_16 ( struct V_65 * V_30 )
{
struct V_66 * V_67 = V_30 -> V_68 ;
struct V_5 * V_69 ;
T_3 V_70 , V_71 ;
T_3 V_72 ;
int V_73 ;
if ( ! V_67 )
return F_17 ( - V_74 ) ;
V_69 = F_18 ( V_30 , sizeof( * V_69 ) , V_75 ) ;
if ( ! V_69 )
return F_17 ( - V_76 ) ;
F_19 ( V_67 , L_3 , & V_70 ) ;
F_19 ( V_67 , L_4 , & V_71 ) ;
V_69 -> V_7 = ( T_2 ) V_70 ;
V_69 -> V_9 = ( T_2 ) V_71 ;
if ( ! V_69 -> V_9 || ! V_69 -> V_7 ||
V_69 -> V_9 > V_77 || V_69 -> V_7 > V_78 ) {
F_14 ( V_30 ,
L_5 ,
V_69 -> V_7 , V_69 -> V_9 ) ;
return F_17 ( - V_11 ) ;
}
if ( ! F_20 ( V_67 , L_6 , & V_73 ) ) {
F_14 ( V_30 , L_7 ) ;
return F_17 ( - V_79 ) ;
}
V_69 -> V_80 = F_21 ( V_67 , L_8 ) ;
V_69 -> V_81 = F_21 ( V_67 , L_9 ) ||
F_21 ( V_67 , L_10 ) ;
F_19 ( V_67 , L_11 , & V_72 ) ;
if ( V_72 )
V_69 -> V_20 = V_72 * 16 ;
else
V_69 -> V_20 = V_82 ;
V_69 -> V_18 = V_83 ;
V_69 -> V_84 = V_85 ;
return V_69 ;
}
static int F_22 ( struct V_86 * V_87 )
{
struct V_4 * V_4 = F_23 ( V_87 -> V_30 . V_88 ) ;
struct V_1 * V_2 ;
struct V_64 * V_45 ;
const struct V_5 * V_69 ;
int error , V_29 ;
V_69 = F_16 ( & V_87 -> V_30 ) ;
if ( F_24 ( V_69 ) ) {
F_14 ( & V_87 -> V_30 , L_12 ) ;
return F_25 ( V_69 ) ;
}
V_29 = F_26 ( V_87 , 0 ) ;
if ( V_29 < 0 )
return V_29 ;
V_2 = F_18 ( & V_87 -> V_30 , sizeof( struct V_1 ) ,
V_75 ) ;
if ( ! V_2 )
return - V_76 ;
V_45 = F_27 ( & V_87 -> V_30 ) ;
if ( ! V_45 ) {
F_14 ( & V_87 -> V_30 , L_13 ) ;
return - V_76 ;
}
V_2 -> V_6 = V_69 ;
V_2 -> V_45 = V_45 ;
V_2 -> V_4 = V_4 ;
V_45 -> V_89 . V_90 = V_91 ;
V_45 -> V_92 = V_87 -> V_92 ;
V_45 -> V_30 . V_88 = & V_87 -> V_30 ;
V_45 -> V_93 = F_12 ;
V_45 -> V_94 = F_15 ;
error = F_28 ( V_69 -> V_95 , NULL ,
V_10 , V_8 ,
NULL , V_45 ) ;
if ( error ) {
F_14 ( & V_87 -> V_30 , L_14 ) ;
return error ;
}
V_2 -> V_48 = V_45 -> V_96 ;
F_29 ( V_45 , V_46 , V_47 ) ;
if ( ! V_69 -> V_80 )
F_30 ( V_97 , V_45 -> V_98 ) ;
F_31 ( V_45 , V_2 ) ;
F_11 ( V_2 ) ;
error = F_32 ( & V_87 -> V_30 , V_29 ,
NULL , F_4 ,
V_69 -> V_84 | V_99 ,
L_15 , V_2 ) ;
if ( error ) {
F_14 ( & V_87 -> V_30 ,
L_16 ,
V_29 , error ) ;
return error ;
}
error = F_33 ( V_45 ) ;
if ( error ) {
F_14 ( & V_87 -> V_30 , L_17 ) ;
return error ;
}
F_34 ( & V_87 -> V_30 , V_69 -> V_81 ) ;
F_35 ( & V_87 -> V_30 , V_69 -> V_81 ) ;
F_36 ( V_87 , V_2 ) ;
return 0 ;
}
static int F_37 ( struct V_65 * V_30 )
{
struct V_86 * V_87 = F_38 ( V_30 ) ;
struct V_1 * V_2 = F_39 ( V_87 ) ;
int V_29 = F_26 ( V_87 , 0 ) ;
if ( V_2 -> V_63 )
return 0 ;
if ( ! F_40 ( & V_87 -> V_30 ) )
F_11 ( V_2 ) ;
else
F_41 ( V_29 ) ;
return 0 ;
}
static int F_42 ( struct V_65 * V_30 )
{
struct V_86 * V_87 = F_38 ( V_30 ) ;
struct V_1 * V_2 = F_39 ( V_87 ) ;
int V_29 = F_26 ( V_87 , 0 ) ;
if ( ! V_2 -> V_63 )
return 0 ;
if ( ! F_40 ( & V_87 -> V_30 ) )
F_10 ( V_2 ) ;
else
F_43 ( V_29 ) ;
return 0 ;
}
