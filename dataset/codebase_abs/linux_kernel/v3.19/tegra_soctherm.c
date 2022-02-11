static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 , V_4 , V_5 ;
int V_6 ;
V_6 = F_2 ( V_7 , & V_3 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_8 = V_3 & V_9 ;
V_2 -> V_10 = ( V_3 & V_11 )
>> V_12 ;
V_3 = ( ( V_3 & V_13 )
>> V_14 ) ;
V_5 = F_3 ( V_3 , 4 ) ;
V_6 = F_2 ( V_15 , & V_3 ) ;
if ( V_6 )
return V_6 ;
V_4 = F_3 ( V_3 , 5 ) ;
V_2 -> V_16 = 2 * V_17 + V_4 ;
V_2 -> V_18 = 2 * V_19 + V_5 ;
return 0 ;
}
static T_2 F_4 ( T_2 V_20 , T_2 V_21 )
{
T_2 V_2 , V_22 ;
V_22 = V_20 << 16 ;
V_2 = F_5 ( V_22 * 2 + 1 , 2 * V_21 ) ;
return V_2 >> 16 ;
}
static int
F_6 ( const struct V_23 * V_24 ,
const struct V_1 * V_25 ,
T_1 * V_26 )
{
T_1 V_3 ;
T_3 V_27 , V_28 , V_29 , V_30 ,
V_31 , div ;
T_4 V_32 , V_33 ;
T_2 V_34 ;
int V_6 ;
V_6 = F_2 ( V_24 -> V_35 , & V_3 ) ;
if ( V_6 )
return V_6 ;
V_28 = ( V_25 -> V_8 * 64 ) + F_3 ( V_3 , 12 ) ;
V_3 = ( V_3 & V_36 )
>> V_37 ;
V_27 = ( V_25 -> V_10 * 32 ) + F_3 ( V_3 , 12 ) ;
V_29 = V_27 - V_28 ;
V_30 = V_25 -> V_18 - V_25 -> V_16 ;
V_31 = V_24 -> V_38 -> V_39 * V_24 -> V_38 -> V_40 ;
div = V_24 -> V_38 -> V_41 * V_24 -> V_38 -> V_42 ;
V_32 = F_4 ( ( T_2 ) V_30 * ( 1LL << 13 ) * V_31 ,
( T_2 ) V_29 * div ) ;
V_34 = ( T_2 ) V_27 * V_25 -> V_16 -
( T_2 ) V_28 * V_25 -> V_18 ;
V_33 = F_4 ( V_34 , ( T_2 ) V_29 ) ;
V_32 = F_4 ( ( T_2 ) V_32 * V_24 -> V_43 ,
( T_2 ) 1000000LL ) ;
V_33 = F_4 ( ( T_2 ) V_33 * V_24 -> V_43 +
V_24 -> V_44 , ( T_2 ) 1000000LL ) ;
* V_26 = ( ( V_45 ) V_32 << V_46 ) |
( ( V_45 ) V_33 << V_47 ) ;
return 0 ;
}
static int F_7 ( struct V_48 * V_49 ,
const struct V_23 * V_24 ,
const struct V_1 * V_25 )
{
void T_5 * V_50 = V_49 -> V_51 + V_24 -> V_50 ;
unsigned int V_3 ;
T_1 V_26 ;
int V_6 ;
V_6 = F_6 ( V_24 , V_25 , & V_26 ) ;
if ( V_6 )
return V_6 ;
V_3 = V_24 -> V_38 -> V_52 << V_53 ;
F_8 ( V_3 , V_50 + V_54 ) ;
V_3 = ( V_24 -> V_38 -> V_41 - 1 ) << V_55 ;
V_3 |= V_24 -> V_38 -> V_56 << V_57 ;
V_3 |= V_24 -> V_38 -> V_58 << V_59 ;
V_3 |= V_60 ;
F_8 ( V_3 , V_50 + V_61 ) ;
F_8 ( V_26 , V_50 + V_62 ) ;
return 0 ;
}
static long F_9 ( V_45 V_3 )
{
long V_63 ;
V_63 = ( ( V_3 & V_64 ) >> V_65 ) * 1000 ;
if ( V_3 & V_66 )
V_63 += 500 ;
if ( V_3 & V_67 )
V_63 *= - 1 ;
return V_63 ;
}
static int F_10 ( void * V_68 , long * V_69 )
{
struct V_70 * V_71 = V_68 ;
T_1 V_3 ;
V_3 = ( F_11 ( V_71 -> V_72 ) >> V_71 -> V_73 ) & V_74 ;
* V_69 = F_9 ( V_3 ) ;
return 0 ;
}
static int F_12 ( struct V_75 * V_76 )
{
struct V_48 * V_49 ;
struct V_77 * V_78 ;
struct V_1 V_79 ;
struct V_80 * V_81 ;
unsigned int V_82 ;
int V_6 ;
const struct V_23 * V_83 = V_84 ;
V_49 = F_13 ( & V_76 -> V_85 , sizeof( * V_49 ) , V_86 ) ;
if ( ! V_49 )
return - V_87 ;
V_81 = F_14 ( V_76 , V_88 , 0 ) ;
V_49 -> V_51 = F_15 ( & V_76 -> V_85 , V_81 ) ;
if ( F_16 ( V_49 -> V_51 ) )
return F_17 ( V_49 -> V_51 ) ;
V_49 -> V_89 = F_18 ( & V_76 -> V_85 , L_1 ) ;
if ( F_16 ( V_49 -> V_89 ) ) {
F_19 ( & V_76 -> V_85 , L_2 ) ;
return F_17 ( V_49 -> V_89 ) ;
}
V_49 -> V_90 = F_20 ( & V_76 -> V_85 , L_3 ) ;
if ( F_16 ( V_49 -> V_90 ) ) {
F_19 ( & V_76 -> V_85 , L_4 ) ;
return F_17 ( V_49 -> V_90 ) ;
}
V_49 -> V_91 = F_20 ( & V_76 -> V_85 , L_1 ) ;
if ( F_16 ( V_49 -> V_91 ) ) {
F_19 ( & V_76 -> V_85 , L_5 ) ;
return F_17 ( V_49 -> V_91 ) ;
}
F_21 ( V_49 -> V_89 ) ;
V_6 = F_22 ( V_49 -> V_91 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_22 ( V_49 -> V_90 ) ;
if ( V_6 ) {
F_23 ( V_49 -> V_91 ) ;
return V_6 ;
}
F_24 ( V_49 -> V_89 ) ;
V_6 = F_1 ( & V_79 ) ;
if ( V_6 )
goto V_92;
for ( V_82 = 0 ; V_82 < F_25 ( V_84 ) ; ++ V_82 ) {
V_6 = F_7 ( V_49 , V_83 + V_82 , & V_79 ) ;
if ( V_6 )
goto V_92;
}
F_8 ( V_93 , V_49 -> V_51 + V_94 ) ;
F_8 ( V_95 , V_49 -> V_51 + V_96 ) ;
for ( V_82 = 0 ; V_82 < F_25 ( V_49 -> V_97 ) ; ++ V_82 ) {
struct V_70 * V_71 =
F_13 ( & V_76 -> V_85 , sizeof( * V_71 ) , V_86 ) ;
if ( ! V_71 ) {
V_6 = - V_87 ;
goto V_98;
}
V_71 -> V_72 = V_49 -> V_51 + V_99 [ V_82 ] . V_100 ;
V_71 -> V_73 = V_99 [ V_82 ] . V_73 ;
V_78 = F_26 ( & V_76 -> V_85 , V_82 , V_71 ,
& V_101 ) ;
if ( F_16 ( V_78 ) ) {
V_6 = F_17 ( V_78 ) ;
F_19 ( & V_76 -> V_85 , L_6 ,
V_6 ) ;
goto V_98;
}
V_49 -> V_97 [ V_82 ] = V_78 ;
}
return 0 ;
V_98:
while ( V_82 -- )
F_27 ( & V_76 -> V_85 ,
V_49 -> V_97 [ V_82 ] ) ;
V_92:
F_23 ( V_49 -> V_90 ) ;
F_23 ( V_49 -> V_91 ) ;
return V_6 ;
}
static int F_28 ( struct V_75 * V_76 )
{
struct V_48 * V_49 = F_29 ( V_76 ) ;
unsigned int V_82 ;
for ( V_82 = 0 ; V_82 < F_25 ( V_49 -> V_97 ) ; ++ V_82 ) {
F_27 ( & V_76 -> V_85 ,
V_49 -> V_97 [ V_82 ] ) ;
}
F_23 ( V_49 -> V_90 ) ;
F_23 ( V_49 -> V_91 ) ;
return 0 ;
}
