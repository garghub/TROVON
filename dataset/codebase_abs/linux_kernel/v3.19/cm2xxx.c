static void F_1 ( T_1 V_1 , T_2 V_2 , T_3 V_3 )
{
T_3 V_4 ;
V_4 = F_2 ( V_2 , V_5 ) ;
V_4 &= ~ V_3 ;
V_4 |= V_1 << F_3 ( V_3 ) ;
F_4 ( V_4 , V_2 , V_5 ) ;
}
static bool F_5 ( T_2 V_2 , T_3 V_3 )
{
T_3 V_4 ;
V_4 = F_2 ( V_2 , V_5 ) ;
V_4 &= V_3 ;
V_4 >>= F_3 ( V_3 ) ;
return ( V_4 == V_6 ) ? 1 : 0 ;
}
static void F_6 ( T_2 V_2 , T_3 V_3 )
{
F_1 ( V_6 , V_2 , V_3 ) ;
}
static void F_7 ( T_2 V_2 , T_3 V_3 )
{
F_1 ( V_7 , V_2 , V_3 ) ;
}
static void F_8 ( T_1 V_8 )
{
T_3 V_4 ;
V_4 = F_2 ( V_9 , V_10 ) ;
V_4 &= ~ V_11 ;
V_4 |= V_8 << V_12 ;
F_4 ( V_4 , V_9 , V_10 ) ;
}
void F_9 ( void )
{
F_8 ( V_13 ) ;
}
void F_10 ( void )
{
F_8 ( V_14 ) ;
}
static void F_11 ( T_1 V_8 , T_3 V_3 )
{
T_3 V_4 ;
V_4 = F_2 ( V_9 , V_10 ) ;
V_4 &= ~ V_3 ;
V_4 |= V_8 << F_3 ( V_3 ) ;
F_4 ( V_4 , V_9 , V_10 ) ;
}
void F_12 ( void )
{
F_11 ( V_15 ,
V_16 ) ;
}
void F_13 ( void )
{
F_11 ( V_17 ,
V_16 ) ;
}
void F_14 ( void )
{
F_11 ( V_15 ,
V_18 ) ;
}
void F_15 ( void )
{
F_11 ( V_17 ,
V_18 ) ;
}
static int F_16 ( T_1 V_19 , T_1 V_20 )
{
T_3 V_4 , V_8 ;
V_8 = V_21 << V_19 ;
V_4 = F_2 ( V_9 , V_22 ) ;
if ( V_4 & V_8 )
return 0 ;
V_4 |= V_8 ;
F_4 ( V_4 , V_9 , V_22 ) ;
F_17 ( 0 , V_9 , 1 , V_20 ) ;
return 0 ;
}
static void F_18 ( T_1 V_19 )
{
T_3 V_4 ;
V_4 = F_2 ( V_9 , V_22 ) ;
V_4 &= ~ ( V_21 << V_19 ) ;
F_4 ( V_4 , V_9 , V_22 ) ;
}
int F_19 ( void )
{
return F_16 ( V_23 ,
V_24 ) ;
}
int F_20 ( void )
{
return F_16 ( V_25 ,
V_26 ) ;
}
void F_21 ( void )
{
F_18 ( V_23 ) ;
}
void F_22 ( void )
{
F_18 ( V_25 ) ;
}
static int F_23 ( void T_4 * V_27 ,
T_2 * V_28 ,
T_1 * V_29 )
{
unsigned long V_30 ;
T_1 V_31 ;
int V_32 ;
if ( V_27 < V_33 || V_27 > ( V_33 + 0x0fff ) )
return - V_34 ;
V_31 = ( unsigned long ) V_27 & 0xff ;
for ( V_32 = 0 ; V_32 < F_24 ( V_35 ) ; V_32 ++ ) {
if ( V_31 == V_35 [ V_32 ] ) {
* V_29 = V_32 + 1 ;
break;
}
}
if ( V_32 == F_24 ( V_35 ) )
return - V_34 ;
V_30 = V_27 - V_33 ;
V_30 &= 0xff00 ;
* V_28 = V_30 ;
return 0 ;
}
int F_17 ( T_1 V_36 , T_2 V_37 , T_5 V_38 ,
T_1 V_39 )
{
int V_40 = 0 , V_32 = 0 ;
T_1 V_41 ;
T_3 V_3 ;
if ( ! V_38 || ( V_38 > F_24 ( V_35 ) ) )
return - V_34 ;
V_41 = V_35 [ V_38 - 1 ] ;
V_3 = 1 << V_39 ;
V_40 = V_3 ;
F_25 ( ( ( F_2 ( V_37 , V_41 ) &
V_3 ) == V_40 ) , V_42 , V_32 ) ;
return ( V_32 < V_42 ) ? 0 : - V_43 ;
}
static void F_26 ( struct V_44 * V_45 )
{
F_6 ( V_45 -> V_46 . V_47 -> V_48 ,
V_45 -> V_49 ) ;
}
static void F_27 ( struct V_44 * V_45 )
{
F_7 ( V_45 -> V_46 . V_47 -> V_48 ,
V_45 -> V_49 ) ;
}
static int F_28 ( struct V_44 * V_45 )
{
bool V_50 = false ;
if ( ! V_45 -> V_49 )
return 0 ;
V_50 = F_5 ( V_45 -> V_46 . V_47 -> V_48 ,
V_45 -> V_49 ) ;
if ( ! V_50 && V_45 -> V_51 & V_52 )
F_29 ( V_45 ) ;
return 0 ;
}
static int F_30 ( struct V_44 * V_45 )
{
bool V_50 = false ;
if ( ! V_45 -> V_49 )
return 0 ;
V_50 = F_5 ( V_45 -> V_46 . V_47 -> V_48 ,
V_45 -> V_49 ) ;
if ( ! V_50 && V_45 -> V_51 & V_53 )
F_31 ( V_45 ) ;
return 0 ;
}
int F_32 ( void )
{
T_3 V_54 , V_55 ;
V_54 = F_2 ( V_56 , V_57 ) ;
V_55 = F_2 ( V_56 , V_58 ) ;
return ( V_54 | V_55 ) ? 1 : 0 ;
}
int F_33 ( void )
{
T_3 V_59 ;
V_59 = F_2 ( V_56 , V_57 ) ;
if ( V_59 & ( V_60 | V_61 |
V_62 | V_63 |
V_64 | V_65 ) )
return 0 ;
V_59 = F_2 ( V_56 , V_58 ) ;
if ( V_59 & V_66 )
return 0 ;
return 1 ;
}
T_3 F_34 ( void )
{
T_3 V_4 ;
V_4 = F_2 ( V_9 , V_67 ) ;
V_4 &= V_68 ;
return V_4 ;
}
T_3 F_35 ( void )
{
return F_2 ( V_9 , V_67 ) ;
}
T_3 F_36 ( void )
{
return F_2 ( V_9 , V_69 ) ;
}
T_3 F_37 ( void )
{
return F_2 ( V_9 , V_22 ) ;
}
void F_38 ( T_3 V_70 , T_3 V_71 , T_3 V_72 , T_3 V_73 , T_3 V_74 )
{
T_3 V_75 ;
F_4 ( V_70 , V_76 , V_77 ) ;
F_4 ( V_71 , V_78 , V_77 ) ;
F_4 ( V_72 , V_79 , V_77 ) ;
V_75 = F_2 ( V_56 , V_69 ) &
V_80 ;
F_4 ( V_73 | V_75 , V_56 , V_69 ) ;
if ( V_74 )
F_4 ( V_74 , V_81 , V_77 ) ;
}
int T_6 F_39 ( void )
{
return F_40 ( & V_82 ) ;
}
static void T_7 F_41 ( void )
{
F_42 ( & V_82 ) ;
}
