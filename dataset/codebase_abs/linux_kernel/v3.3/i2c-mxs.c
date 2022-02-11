static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_3 ( V_4 << 8 , V_2 -> V_3 + V_5 ) ;
F_3 ( V_6 ,
V_2 -> V_3 + V_7 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_8 , int V_9 ,
int V_10 )
{
T_2 V_11 ;
F_3 ( V_12 , V_2 -> V_3 + V_13 ) ;
V_11 = ( V_8 << 1 ) | V_14 ;
F_3 ( V_11 , V_2 -> V_3 + V_15 ) ;
V_11 = V_16 | F_5 ( V_9 ) | V_10 ;
F_3 ( V_11 , V_2 -> V_3 + V_13 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
T_1 V_8 , T_1 * V_17 , int V_9 , int V_10 )
{
T_2 V_11 ;
int V_18 , V_19 ;
V_11 = V_20 | F_5 ( V_9 + 1 ) | V_10 ;
F_3 ( V_11 , V_2 -> V_3 + V_13 ) ;
V_11 = ( ( V_8 << 1 ) | V_21 ) << 24 ;
for ( V_18 = 0 ; V_18 < V_9 ; V_18 ++ ) {
V_11 >>= 8 ;
V_11 |= V_17 [ V_18 ] << 24 ;
if ( ( V_18 & 3 ) == 2 )
F_3 ( V_11 , V_2 -> V_3 + V_15 ) ;
}
V_19 = 24 - ( V_18 & 3 ) * 8 ;
if ( V_19 )
F_3 ( V_11 >> V_19 , V_2 -> V_3 + V_15 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
unsigned long V_22 = V_23 + F_8 ( 1000 ) ;
while ( F_9 ( V_2 -> V_3 + V_24 )
& V_25 ) {
if ( F_10 ( V_23 , V_22 ) )
return - V_26 ;
F_11 () ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , T_1 * V_17 , int V_9 )
{
T_2 V_11 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_9 ; V_18 ++ ) {
if ( ( V_18 & 3 ) == 0 ) {
if ( F_7 ( V_2 ) )
return - V_26 ;
V_11 = F_9 ( V_2 -> V_3 + V_27 ) ;
}
V_17 [ V_18 ] = V_11 & 0xff ;
V_11 >>= 8 ;
}
return 0 ;
}
static int F_13 ( struct V_28 * V_29 , struct V_30 * V_31 ,
int V_32 )
{
struct V_1 * V_2 = F_14 ( V_29 ) ;
int V_33 ;
int V_10 ;
F_15 ( V_2 -> V_34 , L_1 ,
V_31 -> V_8 , V_31 -> V_9 , V_31 -> V_10 , V_32 ) ;
if ( V_31 -> V_9 == 0 )
return - V_35 ;
F_16 ( & V_2 -> V_36 ) ;
V_10 = V_32 ? V_37 : 0 ;
if ( V_31 -> V_10 & V_38 )
F_4 ( V_2 , V_31 -> V_8 , V_31 -> V_9 , V_10 ) ;
else
F_6 ( V_2 , V_31 -> V_8 , V_31 -> V_17 , V_31 -> V_9 ,
V_10 ) ;
F_3 ( V_39 ,
V_2 -> V_3 + V_7 ) ;
V_33 = F_17 ( & V_2 -> V_36 ,
F_8 ( 1000 ) ) ;
if ( V_33 == 0 )
goto V_22;
if ( ( ! V_2 -> V_40 ) && ( V_31 -> V_10 & V_38 ) ) {
V_33 = F_12 ( V_2 , V_31 -> V_17 , V_31 -> V_9 ) ;
if ( V_33 )
goto V_22;
}
if ( V_2 -> V_40 == - V_41 )
F_1 ( V_2 ) ;
F_15 ( V_2 -> V_34 , L_2 , V_2 -> V_40 ) ;
return V_2 -> V_40 ;
V_22:
F_15 ( V_2 -> V_34 , L_3 ) ;
F_1 ( V_2 ) ;
return - V_26 ;
}
static int F_18 ( struct V_28 * V_29 , struct V_30 V_42 [] ,
int V_43 )
{
int V_18 ;
int V_44 ;
for ( V_18 = 0 ; V_18 < V_43 ; V_18 ++ ) {
V_44 = F_13 ( V_29 , & V_42 [ V_18 ] , V_18 == ( V_43 - 1 ) ) ;
if ( V_44 )
return V_44 ;
}
return V_43 ;
}
static T_2 F_19 ( struct V_28 * V_29 )
{
return V_45 | ( V_46 & ~ V_47 ) ;
}
static T_3 F_20 ( int V_48 , void * V_49 )
{
struct V_1 * V_2 = V_49 ;
T_2 V_50 = F_9 ( V_2 -> V_3 + V_51 ) & V_4 ;
bool V_52 ;
if ( ! V_50 )
return V_53 ;
if ( V_50 & V_54 )
V_2 -> V_40 = - V_41 ;
else if ( V_50 & ( V_55 |
V_56 |
V_57 | V_58 ) )
V_2 -> V_40 = - V_59 ;
else
V_2 -> V_40 = 0 ;
V_52 = ( F_9 ( V_2 -> V_3 + V_24 ) &
V_60 ) == 0 ;
if ( V_52 || V_2 -> V_40 )
F_21 ( & V_2 -> V_36 ) ;
F_3 ( V_50 , V_2 -> V_3 + V_61 ) ;
return V_62 ;
}
static int T_4 F_22 ( struct V_63 * V_64 )
{
struct V_65 * V_34 = & V_64 -> V_34 ;
struct V_1 * V_2 ;
struct V_28 * V_29 ;
struct V_66 * V_67 ;
T_5 V_68 ;
int V_44 , V_69 ;
V_2 = F_23 ( V_34 , sizeof( struct V_1 ) , V_70 ) ;
if ( ! V_2 )
return - V_71 ;
V_67 = F_24 ( V_64 , V_72 , 0 ) ;
if ( ! V_67 )
return - V_73 ;
V_68 = F_25 ( V_67 ) ;
if ( ! F_26 ( V_34 , V_67 -> V_74 , V_68 , V_67 -> V_75 ) )
return - V_76 ;
V_2 -> V_3 = F_27 ( V_34 , V_67 -> V_74 , V_68 ) ;
if ( ! V_2 -> V_3 )
return - V_76 ;
V_69 = F_28 ( V_64 , 0 ) ;
if ( V_69 < 0 )
return V_69 ;
V_44 = F_29 ( V_34 , V_69 , F_20 , 0 , F_30 ( V_34 ) , V_2 ) ;
if ( V_44 )
return V_44 ;
V_2 -> V_34 = V_34 ;
F_31 ( V_64 , V_2 ) ;
F_1 ( V_2 ) ;
V_29 = & V_2 -> V_77 ;
F_32 ( V_29 -> V_75 , L_4 , sizeof( V_29 -> V_75 ) ) ;
V_29 -> V_78 = V_79 ;
V_29 -> V_80 = & V_81 ;
V_29 -> V_34 . V_82 = V_34 ;
V_29 -> V_83 = V_64 -> V_84 ;
F_33 ( V_29 , V_2 ) ;
V_44 = F_34 ( V_29 ) ;
if ( V_44 ) {
F_35 ( V_34 , L_5 , V_44 ) ;
F_3 ( V_85 ,
V_2 -> V_3 + V_86 ) ;
return V_44 ;
}
return 0 ;
}
static int T_6 F_36 ( struct V_63 * V_64 )
{
struct V_1 * V_2 = F_37 ( V_64 ) ;
int V_33 ;
V_33 = F_38 ( & V_2 -> V_77 ) ;
if ( V_33 )
return - V_76 ;
F_3 ( V_39 ,
V_2 -> V_3 + V_87 ) ;
F_3 ( V_85 , V_2 -> V_3 + V_86 ) ;
F_31 ( V_64 , NULL ) ;
return 0 ;
}
static int T_7 F_39 ( void )
{
return F_40 ( & V_88 , F_22 ) ;
}
static void T_8 F_41 ( void )
{
F_42 ( & V_88 ) ;
}
