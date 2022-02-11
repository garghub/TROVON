static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_3 ( V_2 -> V_4 -> V_5 , V_2 -> V_3 + V_6 ) ;
F_3 ( V_2 -> V_4 -> V_7 , V_2 -> V_3 + V_8 ) ;
F_3 ( V_2 -> V_4 -> V_9 , V_2 -> V_3 + V_10 ) ;
F_3 ( V_11 << 8 , V_2 -> V_3 + V_12 ) ;
F_3 ( V_13 ,
V_2 -> V_3 + V_14 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_15 , int V_16 ,
int V_17 )
{
T_2 V_18 ;
F_3 ( V_19 , V_2 -> V_3 + V_20 ) ;
V_18 = ( V_15 << 1 ) | V_21 ;
F_3 ( V_18 , V_2 -> V_3 + V_22 ) ;
V_18 = V_23 | F_5 ( V_16 ) | V_17 ;
F_3 ( V_18 , V_2 -> V_3 + V_20 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
T_1 V_15 , T_1 * V_24 , int V_16 , int V_17 )
{
T_2 V_18 ;
int V_25 , V_26 ;
V_18 = V_27 | F_5 ( V_16 + 1 ) | V_17 ;
F_3 ( V_18 , V_2 -> V_3 + V_20 ) ;
V_18 = ( ( V_15 << 1 ) | V_28 ) << 24 ;
for ( V_25 = 0 ; V_25 < V_16 ; V_25 ++ ) {
V_18 >>= 8 ;
V_18 |= V_24 [ V_25 ] << 24 ;
if ( ( V_25 & 3 ) == 2 )
F_3 ( V_18 , V_2 -> V_3 + V_22 ) ;
}
V_26 = 24 - ( V_25 & 3 ) * 8 ;
if ( V_26 )
F_3 ( V_18 >> V_26 , V_2 -> V_3 + V_22 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
unsigned long V_29 = V_30 + F_8 ( 1000 ) ;
while ( F_9 ( V_2 -> V_3 + V_31 )
& V_32 ) {
if ( F_10 ( V_30 , V_29 ) )
return - V_33 ;
F_11 () ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , T_1 * V_24 , int V_16 )
{
T_2 V_34 ( V_18 ) ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_16 ; V_25 ++ ) {
if ( ( V_25 & 3 ) == 0 ) {
if ( F_7 ( V_2 ) )
return - V_33 ;
V_18 = F_9 ( V_2 -> V_3 + V_35 ) ;
}
V_24 [ V_25 ] = V_18 & 0xff ;
V_18 >>= 8 ;
}
return 0 ;
}
static int F_13 ( struct V_36 * V_37 , struct V_38 * V_39 ,
int V_40 )
{
struct V_1 * V_2 = F_14 ( V_37 ) ;
int V_41 ;
int V_17 ;
F_15 ( V_2 -> V_42 , L_1 ,
V_39 -> V_15 , V_39 -> V_16 , V_39 -> V_17 , V_40 ) ;
if ( V_39 -> V_16 == 0 )
return - V_43 ;
F_16 ( & V_2 -> V_44 ) ;
V_2 -> V_45 = 0 ;
V_17 = V_40 ? V_46 : 0 ;
if ( V_39 -> V_17 & V_47 )
F_4 ( V_2 , V_39 -> V_15 , V_39 -> V_16 , V_17 ) ;
else
F_6 ( V_2 , V_39 -> V_15 , V_39 -> V_24 , V_39 -> V_16 ,
V_17 ) ;
F_3 ( V_48 ,
V_2 -> V_3 + V_14 ) ;
V_41 = F_17 ( & V_2 -> V_44 ,
F_8 ( 1000 ) ) ;
if ( V_41 == 0 )
goto V_29;
if ( ( ! V_2 -> V_45 ) && ( V_39 -> V_17 & V_47 ) ) {
V_41 = F_12 ( V_2 , V_39 -> V_24 , V_39 -> V_16 ) ;
if ( V_41 )
goto V_29;
}
if ( V_2 -> V_45 == - V_49 )
F_1 ( V_2 ) ;
else
F_3 ( V_48 ,
V_2 -> V_3 + V_50 ) ;
F_15 ( V_2 -> V_42 , L_2 , V_2 -> V_45 ) ;
return V_2 -> V_45 ;
V_29:
F_15 ( V_2 -> V_42 , L_3 ) ;
F_1 ( V_2 ) ;
return - V_33 ;
}
static int F_18 ( struct V_36 * V_37 , struct V_38 V_51 [] ,
int V_52 )
{
int V_25 ;
int V_53 ;
for ( V_25 = 0 ; V_25 < V_52 ; V_25 ++ ) {
V_53 = F_13 ( V_37 , & V_51 [ V_25 ] , V_25 == ( V_52 - 1 ) ) ;
if ( V_53 )
return V_53 ;
}
return V_52 ;
}
static T_2 F_19 ( struct V_36 * V_37 )
{
return V_54 | ( V_55 & ~ V_56 ) ;
}
static T_3 F_20 ( int V_57 , void * V_58 )
{
struct V_1 * V_2 = V_58 ;
T_2 V_59 = F_9 ( V_2 -> V_3 + V_60 ) & V_11 ;
bool V_61 ;
if ( ! V_59 )
return V_62 ;
if ( V_59 & V_63 )
V_2 -> V_45 = - V_49 ;
else if ( V_59 & ( V_64 |
V_65 |
V_66 | V_67 ) )
V_2 -> V_45 = - V_68 ;
V_61 = ( F_9 ( V_2 -> V_3 + V_31 ) &
V_69 ) == 0 ;
if ( V_61 || V_2 -> V_45 )
F_21 ( & V_2 -> V_44 ) ;
F_3 ( V_59 , V_2 -> V_3 + V_70 ) ;
return V_71 ;
}
static int F_22 ( struct V_1 * V_2 )
{
T_4 V_4 ;
struct V_72 * V_42 = V_2 -> V_42 ;
struct V_73 * V_74 = V_42 -> V_75 ;
int V_41 ;
V_41 = F_23 ( V_74 , L_4 , & V_4 ) ;
if ( V_41 )
F_24 ( V_42 , L_5 ) ;
else if ( V_4 == 400000 )
V_2 -> V_4 = & V_76 ;
else if ( V_4 != 100000 )
F_24 ( V_42 , L_6 ) ;
return 0 ;
}
static int T_5 F_25 ( struct V_77 * V_78 )
{
struct V_72 * V_42 = & V_78 -> V_42 ;
struct V_1 * V_2 ;
struct V_36 * V_37 ;
struct V_79 * V_79 ;
struct V_80 * V_81 ;
T_6 V_82 ;
int V_53 , V_83 ;
V_79 = F_26 ( V_42 ) ;
if ( F_27 ( V_79 ) )
return F_28 ( V_79 ) ;
V_2 = F_29 ( V_42 , sizeof( struct V_1 ) , V_84 ) ;
if ( ! V_2 )
return - V_85 ;
V_81 = F_30 ( V_78 , V_86 , 0 ) ;
if ( ! V_81 )
return - V_87 ;
V_82 = F_31 ( V_81 ) ;
if ( ! F_32 ( V_42 , V_81 -> V_88 , V_82 , V_81 -> V_89 ) )
return - V_90 ;
V_2 -> V_3 = F_33 ( V_42 , V_81 -> V_88 , V_82 ) ;
if ( ! V_2 -> V_3 )
return - V_90 ;
V_83 = F_34 ( V_78 , 0 ) ;
if ( V_83 < 0 )
return V_83 ;
V_53 = F_35 ( V_42 , V_83 , F_20 , 0 , F_36 ( V_42 ) , V_2 ) ;
if ( V_53 )
return V_53 ;
V_2 -> V_42 = V_42 ;
V_2 -> V_4 = & V_91 ;
if ( V_42 -> V_75 ) {
V_53 = F_22 ( V_2 ) ;
if ( V_53 )
return V_53 ;
}
F_37 ( V_78 , V_2 ) ;
F_1 ( V_2 ) ;
V_37 = & V_2 -> V_92 ;
F_38 ( V_37 -> V_89 , L_7 , sizeof( V_37 -> V_89 ) ) ;
V_37 -> V_93 = V_94 ;
V_37 -> V_95 = & V_96 ;
V_37 -> V_42 . V_97 = V_42 ;
V_37 -> V_98 = V_78 -> V_99 ;
V_37 -> V_42 . V_75 = V_78 -> V_42 . V_75 ;
F_39 ( V_37 , V_2 ) ;
V_53 = F_40 ( V_37 ) ;
if ( V_53 ) {
F_41 ( V_42 , L_8 , V_53 ) ;
F_3 ( V_100 ,
V_2 -> V_3 + V_101 ) ;
return V_53 ;
}
F_42 ( V_37 ) ;
return 0 ;
}
static int T_7 F_43 ( struct V_77 * V_78 )
{
struct V_1 * V_2 = F_44 ( V_78 ) ;
int V_41 ;
V_41 = F_45 ( & V_2 -> V_92 ) ;
if ( V_41 )
return - V_90 ;
F_3 ( V_100 , V_2 -> V_3 + V_101 ) ;
F_37 ( V_78 , NULL ) ;
return 0 ;
}
static int T_8 F_46 ( void )
{
return F_47 ( & V_102 , F_25 ) ;
}
static void T_9 F_48 ( void )
{
F_49 ( & V_102 ) ;
}
