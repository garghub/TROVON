static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 , void * V_5 , T_2 V_6 )
{
return F_2 ( V_2 -> V_7 , F_3 ( V_2 -> V_7 , 0 ) ,
V_3 ,
V_8 | V_9 | V_10 ,
0x00 , V_4 , V_5 , V_6 , 1000 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_11 ;
T_1 V_5 [ 24 ] ;
V_11 = F_1 ( V_2 , V_12 , 0x00 , V_5 , 12 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_1 ( V_2 , V_12 , 0x01 , V_5 , 12 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_1 ( V_2 , V_12 , 0x02 , V_5 , 12 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_1 ( V_2 , V_13 , 0x00 , V_5 , 24 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_1 ( V_2 , V_14 , 0x00 , V_5 , 5 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_1 ( V_2 , V_12 , 0x03 , V_5 , 12 ) ;
return V_11 ;
}
static void F_5 ( struct V_15 * V_16 )
{
struct V_1 * V_17 = V_16 -> V_18 ;
F_6 ( V_17 -> V_2 , L_1 ) ;
F_4 ( V_17 ) ;
}
static void F_7 ( struct V_15 * V_16 )
{
struct V_1 * V_17 = V_16 -> V_18 ;
F_6 ( V_17 -> V_2 , L_2 ) ;
}
static void F_8 ( struct V_19 * V_20 , struct V_21 * V_22 )
{
int V_23 , V_24 , V_25 ;
int V_26 = F_9 ( V_20 -> V_26 ) ;
int V_27 = F_9 ( V_20 -> V_27 ) ;
int V_28 = F_9 ( V_20 -> V_28 ) ;
int V_29 = F_9 ( V_20 -> V_29 ) ;
int V_30 = F_9 ( V_20 -> V_30 ) ;
int V_31 = F_9 ( V_20 -> V_31 ) ;
int V_32 = F_10 ( V_22 , V_20 -> V_33 ) ;
if ( V_32 < 0 || V_32 >= V_34 )
return;
F_11 ( V_22 , V_32 ) ;
F_12 ( V_22 , V_35 , 1 ) ;
V_23 = ( V_26 > V_27 ) ;
V_24 = F_13 ( V_26 , V_27 ) ;
V_25 = F_14 ( V_26 , V_27 ) ;
F_15 ( V_22 , V_36 , V_28 ) ;
F_15 ( V_22 , V_37 , V_29 ) ;
F_15 ( V_22 , V_38 , V_30 ) ;
F_15 ( V_22 , V_39 , V_31 ) ;
F_15 ( V_22 , V_40 , V_23 ) ;
F_15 ( V_22 , V_41 , V_24 ) ;
F_15 ( V_22 , V_42 , V_25 ) ;
}
static void F_16 ( struct V_15 * V_16 )
{
struct V_1 * V_17 = V_16 -> V_18 ;
struct V_21 * V_22 = V_16 -> V_22 ;
int V_11 , V_43 , V_44 , V_45 , V_46 ;
T_3 V_47 ( V_48 ) ;
struct V_49 * V_50 = & V_17 -> V_51 -> V_50 ;
struct V_19 * V_52 = & V_17 -> V_51 -> V_53 [ 0 ] ;
F_6 ( V_17 -> V_2 , L_3 ) ;
V_44 = - 1 ;
do {
V_11 = F_17 ( V_17 -> V_7 ,
F_18 ( V_17 -> V_7 , V_17 -> V_54 ) ,
V_17 -> V_51 , V_17 -> V_55 ,
& V_43 , 1000 ) ;
F_6 ( V_17 -> V_2 , L_4 , V_43 ) ;
if ( V_11 < 0 ) {
F_19 ( V_17 -> V_2 , L_5 ) ;
return;
}
V_11 = V_43 - sizeof( struct V_49 ) ;
if ( V_11 % sizeof( struct V_19 ) != 0 ) {
F_19 ( V_17 -> V_2 , L_6 ) ;
return;
}
if ( V_44 == - 1 ) {
V_44 = F_9 ( V_50 -> V_56 ) ;
F_6 ( V_17 -> V_2 , L_7 , V_44 ) ;
V_48 = F_20 ( V_50 -> V_48 ) ;
}
if ( V_48 != V_50 -> V_48 )
F_21 ( V_17 -> V_2 , L_8 ) ;
V_45 = V_11 / sizeof( struct V_19 ) ;
F_6 ( V_17 -> V_2 , L_9 , V_45 ) ;
if ( V_45 > V_44 )
V_45 = V_44 ;
for ( V_46 = 0 ; V_46 < V_45 ; V_46 ++ ) {
V_44 -- ;
F_6 ( V_17 -> V_2 , L_10 ) ;
F_8 ( & ( V_52 [ V_46 ] ) , V_22 ) ;
}
} while ( V_44 > 0 );
F_22 ( V_22 ) ;
F_23 ( V_22 ) ;
}
static void F_24 ( struct V_21 * V_21 )
{
F_25 ( V_57 , V_21 -> V_58 ) ;
F_25 ( V_59 , V_21 -> V_58 ) ;
F_26 ( V_21 , V_36 ,
0 , V_60 , 0 , 0 ) ;
F_26 ( V_21 , V_37 ,
0 , V_61 , 0 , 0 ) ;
F_26 ( V_21 , V_38 ,
0 , V_60 , 0 , 0 ) ;
F_26 ( V_21 , V_39 ,
0 , V_61 , 0 , 0 ) ;
F_26 ( V_21 , V_41 ,
0 , V_60 , 0 , 0 ) ;
F_26 ( V_21 , V_42 ,
0 , V_61 , 0 , 0 ) ;
F_26 ( V_21 , V_40 , 0 , 1 , 0 , 0 ) ;
F_27 ( V_21 , V_34 ,
V_62 | V_63 ) ;
}
static int F_28 ( struct V_64 * V_65 ,
const struct V_66 * V_67 )
{
struct V_68 * V_7 = F_29 ( V_65 ) ;
struct V_1 * V_17 ;
struct V_69 * V_70 ;
struct V_71 * V_72 ;
struct V_15 * V_73 ;
int error ;
V_70 = & V_65 -> V_74 [ 0 ] ;
if ( V_70 -> V_75 . V_76 != 0xFF )
return - V_77 ;
V_72 = & V_70 -> V_72 [ 4 ] . V_75 ;
if ( V_72 -> V_78 != V_79 )
return - V_77 ;
V_17 = F_30 ( sizeof( struct V_1 ) , V_80 ) ;
if ( ! V_17 )
return - V_81 ;
V_73 = F_31 () ;
if ( ! V_73 ) {
error = - V_81 ;
goto V_82;
}
V_73 -> V_18 = V_17 ;
V_73 -> V_83 = V_84 ;
V_73 -> V_85 = F_5 ;
V_73 -> V_86 = F_16 ;
V_73 -> V_87 = F_7 ;
F_24 ( V_73 -> V_22 ) ;
V_73 -> V_22 -> V_88 = L_11 ;
F_32 ( V_7 , & V_73 -> V_22 -> V_67 ) ;
F_33 ( V_7 , V_17 -> V_89 , sizeof( V_17 -> V_89 ) ) ;
F_34 ( V_17 -> V_89 , L_12 , sizeof( V_17 -> V_89 ) ) ;
V_73 -> V_22 -> V_89 = V_17 -> V_89 ;
V_73 -> V_22 -> V_2 . V_90 = & V_65 -> V_2 ;
V_17 -> V_7 = V_7 ;
V_17 -> V_2 = & V_65 -> V_2 ;
V_17 -> V_22 = V_73 ;
V_17 -> V_55 = F_35 ( V_72 ) ;
V_17 -> V_54 = V_72 -> V_78 ;
V_17 -> V_51 = F_36 ( V_17 -> V_55 , V_80 ) ;
if ( ! V_17 -> V_51 ) {
F_19 ( & V_65 -> V_2 , L_13 ) ;
error = - V_81 ;
goto V_91;
}
error = F_37 ( V_73 ) ;
if ( error ) {
F_19 ( & V_65 -> V_2 ,
L_14 ) ;
goto V_92;
}
F_38 ( V_65 , V_17 ) ;
F_6 ( & V_65 -> V_2 , L_15 , V_93 ) ;
return 0 ;
V_92:
F_39 ( V_17 -> V_51 ) ;
V_91:
F_40 ( V_17 -> V_22 ) ;
V_82:
F_39 ( V_17 ) ;
return error ;
}
static void F_41 ( struct V_64 * V_65 )
{
struct V_1 * V_17 = F_42 ( V_65 ) ;
F_43 ( V_17 -> V_22 ) ;
F_40 ( V_17 -> V_22 ) ;
F_39 ( V_17 -> V_51 ) ;
F_39 ( V_17 ) ;
F_38 ( V_65 , NULL ) ;
F_6 ( & V_65 -> V_2 , L_16 , V_93 ) ;
}
