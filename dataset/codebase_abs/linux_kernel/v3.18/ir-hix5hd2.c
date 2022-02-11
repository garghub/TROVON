static void F_1 ( struct V_1 * V_2 , bool V_3 )
{
T_1 V_4 ;
F_2 ( V_2 -> V_5 , V_6 , & V_4 ) ;
if ( V_3 ) {
V_4 &= ~ V_7 ;
V_4 |= V_8 ;
} else {
V_4 &= ~ V_8 ;
V_4 |= V_7 ;
}
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
}
static int F_4 ( struct V_1 * V_9 )
{
int V_10 = 10000 ;
T_1 V_4 , V_11 ;
F_5 ( 0x01 , V_9 -> V_12 + V_13 ) ;
while ( F_6 ( V_9 -> V_12 + V_14 ) ) {
if ( V_10 -- ) {
F_7 ( 1 ) ;
} else {
F_8 ( V_9 -> V_2 , L_1 ) ;
return - V_15 ;
}
}
V_11 = F_9 ( V_9 -> V_11 , 1000000 ) ;
V_4 = V_16 & V_17 << V_18 ;
V_4 |= V_19 & V_20 << V_21 ;
V_4 |= ( V_22 - 1 ) & V_23
<< V_24 ;
V_4 |= V_25 ;
V_4 |= ( V_11 - 1 ) & V_26 << V_27 ;
F_5 ( V_4 , V_9 -> V_12 + V_28 ) ;
F_5 ( 0x00 , V_9 -> V_12 + V_29 ) ;
F_5 ( 0x01 , V_9 -> V_12 + V_30 ) ;
return 0 ;
}
static int F_10 ( struct V_31 * V_32 )
{
struct V_1 * V_9 = V_32 -> V_9 ;
F_1 ( V_9 , true ) ;
return F_4 ( V_9 ) ;
}
static void F_11 ( struct V_31 * V_32 )
{
struct V_1 * V_9 = V_32 -> V_9 ;
F_1 ( V_9 , false ) ;
}
static T_2 F_12 ( int V_33 , void * V_34 )
{
T_1 V_35 , V_36 , V_37 ;
T_1 V_38 , V_39 ;
T_1 V_40 , V_41 ;
struct V_1 * V_9 = V_34 ;
V_40 = F_6 ( V_9 -> V_12 + V_42 ) ;
if ( V_40 & V_43 ) {
F_13 ( V_9 -> V_32 ) ;
V_35 = F_6 ( V_9 -> V_12 + V_44 ) ;
for ( V_41 = 0 ; V_41 < V_35 ; V_41 ++ )
F_6 ( V_9 -> V_12 + V_45 ) ;
F_5 ( V_46 , V_9 -> V_12 + V_47 ) ;
F_14 ( V_9 -> V_2 , L_2 ,
V_22 ) ;
}
if ( ( V_40 & V_48 ) || ( V_40 & V_49 ) ) {
F_15 ( V_50 ) ;
V_35 = F_6 ( V_9 -> V_12 + V_44 ) ;
for ( V_41 = 0 ; V_41 < V_35 ; V_41 ++ ) {
V_36 = F_6 ( V_9 -> V_12 + V_45 ) ;
V_38 = ( ( V_36 & 0xffff ) * 10 ) ;
V_39 = ( ( V_36 >> 16 ) & 0xffff ) * 10 ;
V_37 = ( V_38 + V_39 ) / 10 ;
V_50 . V_51 = F_16 ( V_38 ) ;
V_50 . V_52 = true ;
F_17 ( V_9 -> V_32 , & V_50 ) ;
if ( V_37 < V_16 ) {
V_50 . V_51 = F_16 ( V_39 ) ;
V_50 . V_52 = false ;
F_17 ( V_9 -> V_32 , & V_50 ) ;
} else {
F_18 ( V_9 -> V_32 , true ) ;
}
}
if ( V_40 & V_48 )
F_5 ( V_53 , V_9 -> V_12 + V_47 ) ;
if ( V_40 & V_49 )
F_5 ( V_54 , V_9 -> V_12 + V_47 ) ;
}
F_19 ( V_9 -> V_32 ) ;
return V_55 ;
}
static int F_20 ( struct V_56 * V_57 )
{
struct V_31 * V_32 ;
struct V_58 * V_2 = & V_57 -> V_2 ;
struct V_59 * V_60 ;
struct V_1 * V_9 ;
struct V_61 * V_62 = V_57 -> V_2 . V_63 ;
const char * V_64 ;
int V_65 ;
V_9 = F_21 ( V_2 , sizeof( * V_9 ) , V_66 ) ;
if ( ! V_9 )
return - V_67 ;
V_9 -> V_5 = F_22 ( V_62 ,
L_3 ) ;
if ( F_23 ( V_9 -> V_5 ) ) {
F_8 ( V_2 , L_4 ) ;
return - V_68 ;
}
V_60 = F_24 ( V_57 , V_69 , 0 ) ;
V_9 -> V_12 = F_25 ( V_2 , V_60 ) ;
if ( F_23 ( ( V_70 void * ) V_9 -> V_12 ) )
return F_26 ( ( V_70 void * ) V_9 -> V_12 ) ;
V_9 -> V_33 = F_27 ( V_57 , 0 ) ;
if ( V_9 -> V_33 < 0 ) {
F_8 ( V_2 , L_5 ) ;
return V_9 -> V_33 ;
}
V_32 = F_28 () ;
if ( ! V_32 )
return - V_67 ;
V_9 -> clock = F_29 ( V_2 , NULL ) ;
if ( F_23 ( V_9 -> clock ) ) {
F_8 ( V_2 , L_6 ) ;
V_65 = F_26 ( V_9 -> clock ) ;
goto V_71;
}
F_30 ( V_9 -> clock ) ;
V_9 -> V_11 = F_31 ( V_9 -> clock ) ;
V_32 -> V_72 = V_73 ;
V_32 -> V_74 = V_75 ;
V_32 -> V_9 = V_9 ;
V_32 -> V_76 = F_10 ;
V_32 -> V_77 = F_11 ;
V_32 -> V_78 = V_79 ;
V_64 = F_32 ( V_62 , L_7 , NULL ) ;
V_32 -> V_64 = V_64 ? : V_80 ;
V_32 -> V_81 = V_79 ;
V_32 -> V_82 = V_79 L_8 ;
V_32 -> V_83 . V_84 = V_85 ;
V_32 -> V_83 . V_86 = 0x0001 ;
V_32 -> V_83 . V_87 = 0x0001 ;
V_32 -> V_83 . V_88 = 0x0100 ;
V_32 -> V_89 = F_16 ( 10 ) ;
V_32 -> V_10 = F_16 ( V_16 * 10 ) ;
V_65 = F_33 ( V_32 ) ;
if ( V_65 < 0 )
goto V_90;
if ( F_34 ( V_2 , V_9 -> V_33 , F_12 ,
V_91 , V_57 -> V_92 , V_9 ) < 0 ) {
F_8 ( V_2 , L_9 , V_9 -> V_33 ) ;
V_65 = - V_68 ;
goto V_93;
}
V_9 -> V_32 = V_32 ;
V_9 -> V_2 = V_2 ;
F_35 ( V_57 , V_9 ) ;
return V_65 ;
V_93:
F_36 ( V_32 ) ;
V_32 = NULL ;
V_90:
F_37 ( V_9 -> clock ) ;
V_71:
F_38 ( V_32 ) ;
F_8 ( V_2 , L_10 , V_65 ) ;
return V_65 ;
}
static int F_39 ( struct V_56 * V_57 )
{
struct V_1 * V_9 = F_40 ( V_57 ) ;
F_37 ( V_9 -> clock ) ;
F_36 ( V_9 -> V_32 ) ;
return 0 ;
}
static int F_41 ( struct V_58 * V_2 )
{
struct V_1 * V_9 = F_42 ( V_2 ) ;
F_37 ( V_9 -> clock ) ;
F_1 ( V_9 , false ) ;
return 0 ;
}
static int F_43 ( struct V_58 * V_2 )
{
struct V_1 * V_9 = F_42 ( V_2 ) ;
F_1 ( V_9 , true ) ;
F_30 ( V_9 -> clock ) ;
F_5 ( 0x01 , V_9 -> V_12 + V_13 ) ;
F_5 ( 0x00 , V_9 -> V_12 + V_29 ) ;
F_5 ( 0xff , V_9 -> V_12 + V_47 ) ;
F_5 ( 0x01 , V_9 -> V_12 + V_30 ) ;
return 0 ;
}
