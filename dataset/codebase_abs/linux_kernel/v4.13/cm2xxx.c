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
static int F_23 ( struct V_27 * V_28 ,
T_2 * V_29 ,
T_1 * V_30 )
{
unsigned long V_31 ;
T_1 V_32 ;
int V_33 ;
V_32 = V_28 -> V_34 & 0xff ;
for ( V_33 = 0 ; V_33 < F_24 ( V_35 ) ; V_33 ++ ) {
if ( V_32 == V_35 [ V_33 ] ) {
* V_30 = V_33 + 1 ;
break;
}
}
if ( V_33 == F_24 ( V_35 ) )
return - V_36 ;
V_31 = V_28 -> V_34 ;
V_31 &= 0xff00 ;
* V_29 = V_31 ;
return 0 ;
}
int F_17 ( T_1 V_37 , T_2 V_38 , T_4 V_39 ,
T_1 V_40 )
{
int V_41 = 0 , V_33 = 0 ;
T_1 V_42 ;
T_3 V_3 ;
if ( ! V_39 || ( V_39 > F_24 ( V_35 ) ) )
return - V_36 ;
V_42 = V_35 [ V_39 - 1 ] ;
V_3 = 1 << V_40 ;
V_41 = V_3 ;
F_25 ( ( ( F_2 ( V_38 , V_42 ) &
V_3 ) == V_41 ) , V_43 , V_33 ) ;
return ( V_33 < V_43 ) ? 0 : - V_44 ;
}
static void F_26 ( struct V_45 * V_46 )
{
F_6 ( V_46 -> V_47 . V_48 -> V_49 ,
V_46 -> V_50 ) ;
}
static void F_27 ( struct V_45 * V_46 )
{
F_7 ( V_46 -> V_47 . V_48 -> V_49 ,
V_46 -> V_50 ) ;
}
static int F_28 ( struct V_45 * V_46 )
{
bool V_51 = false ;
if ( ! V_46 -> V_50 )
return 0 ;
V_51 = F_5 ( V_46 -> V_47 . V_48 -> V_49 ,
V_46 -> V_50 ) ;
if ( ! V_51 && V_46 -> V_52 & V_53 )
F_29 ( V_46 ) ;
return 0 ;
}
static int F_30 ( struct V_45 * V_46 )
{
bool V_51 = false ;
if ( ! V_46 -> V_50 )
return 0 ;
V_51 = F_5 ( V_46 -> V_47 . V_48 -> V_49 ,
V_46 -> V_50 ) ;
if ( ! V_51 && V_46 -> V_52 & V_54 )
F_31 ( V_46 ) ;
return 0 ;
}
int F_32 ( void )
{
T_3 V_55 , V_56 ;
V_55 = F_2 ( V_57 , V_58 ) ;
V_56 = F_2 ( V_57 , V_59 ) ;
return ( V_55 | V_56 ) ? 1 : 0 ;
}
int F_33 ( void )
{
T_3 V_60 ;
V_60 = F_2 ( V_57 , V_58 ) ;
if ( V_60 & ( V_61 | V_62 |
V_63 | V_64 |
V_65 | V_66 ) )
return 0 ;
V_60 = F_2 ( V_57 , V_59 ) ;
if ( V_60 & V_67 )
return 0 ;
return 1 ;
}
T_3 F_34 ( void )
{
T_3 V_4 ;
V_4 = F_2 ( V_9 , V_68 ) ;
V_4 &= V_69 ;
return V_4 ;
}
T_3 F_35 ( void )
{
return F_2 ( V_9 , V_68 ) ;
}
void F_36 ( T_3 V_70 , T_3 V_71 , T_3 V_72 , T_3 V_73 , T_3 V_74 )
{
T_3 V_75 ;
F_4 ( V_70 , V_76 , V_77 ) ;
F_4 ( V_71 , V_78 , V_77 ) ;
F_4 ( V_72 , V_79 , V_77 ) ;
V_75 = F_2 ( V_57 , V_80 ) &
V_81 ;
F_4 ( V_73 | V_75 , V_57 , V_80 ) ;
if ( V_74 )
F_4 ( V_74 , V_82 , V_77 ) ;
}
int T_5 F_37 ( const struct V_83 * V_84 )
{
return F_38 ( & V_85 ) ;
}
static void T_6 F_39 ( void )
{
F_40 ( & V_85 ) ;
}
