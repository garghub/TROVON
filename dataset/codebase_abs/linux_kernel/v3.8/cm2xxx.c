static void F_1 ( T_1 V_1 , T_2 V_2 , T_3 V_3 )
{
T_3 V_4 ;
V_4 = F_2 ( V_2 , V_5 ) ;
V_4 &= ~ V_3 ;
V_4 |= V_1 << F_3 ( V_3 ) ;
F_4 ( V_4 , V_2 , V_5 ) ;
}
bool F_5 ( T_2 V_2 , T_3 V_3 )
{
T_3 V_4 ;
V_4 = F_2 ( V_2 , V_5 ) ;
V_4 &= V_3 ;
V_4 >>= F_3 ( V_3 ) ;
return ( V_4 == V_6 ) ? 1 : 0 ;
}
void F_6 ( T_2 V_2 , T_3 V_3 )
{
F_1 ( V_6 , V_2 , V_3 ) ;
}
void F_7 ( T_2 V_2 , T_3 V_3 )
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
F_17 ( V_9 , 1 , V_20 ) ;
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
int F_23 ( void T_4 * V_27 , T_2 * V_28 ,
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
int F_17 ( T_2 V_36 , T_1 V_37 , T_1 V_38 )
{
int V_39 = 0 , V_32 = 0 ;
T_1 V_40 ;
T_3 V_3 ;
if ( ! V_37 || ( V_37 > F_24 ( V_35 ) ) )
return - V_34 ;
V_40 = V_35 [ V_37 - 1 ] ;
V_3 = 1 << V_38 ;
V_39 = V_3 ;
F_25 ( ( ( F_2 ( V_36 , V_40 ) &
V_3 ) == V_39 ) , V_41 , V_32 ) ;
return ( V_32 < V_41 ) ? 0 : - V_42 ;
}
static void F_26 ( struct V_43 * V_44 )
{
if ( F_27 ( & V_44 -> V_45 ) > 0 )
F_28 ( V_44 ) ;
F_6 ( V_44 -> V_46 . V_47 -> V_48 ,
V_44 -> V_49 ) ;
}
static void F_29 ( struct V_43 * V_44 )
{
F_7 ( V_44 -> V_46 . V_47 -> V_48 ,
V_44 -> V_49 ) ;
if ( F_27 ( & V_44 -> V_45 ) > 0 )
F_30 ( V_44 ) ;
}
static int F_31 ( struct V_43 * V_44 )
{
bool V_50 = false ;
if ( ! V_44 -> V_49 )
return 0 ;
V_50 = F_5 ( V_44 -> V_46 . V_47 -> V_48 ,
V_44 -> V_49 ) ;
if ( V_50 ) {
F_7 ( V_44 -> V_46 . V_47 -> V_48 ,
V_44 -> V_49 ) ;
F_28 ( V_44 ) ;
F_6 ( V_44 -> V_46 . V_47 -> V_48 ,
V_44 -> V_49 ) ;
} else {
if ( V_44 -> V_51 & V_52 )
F_32 ( V_44 ) ;
}
return 0 ;
}
static int F_33 ( struct V_43 * V_44 )
{
bool V_50 = false ;
if ( ! V_44 -> V_49 )
return 0 ;
V_50 = F_5 ( V_44 -> V_46 . V_47 -> V_48 ,
V_44 -> V_49 ) ;
if ( V_50 ) {
F_7 ( V_44 -> V_46 . V_47 -> V_48 ,
V_44 -> V_49 ) ;
F_30 ( V_44 ) ;
F_6 ( V_44 -> V_46 . V_47 -> V_48 ,
V_44 -> V_49 ) ;
} else {
if ( V_44 -> V_51 & V_53 )
F_34 ( V_44 ) ;
}
return 0 ;
}
int T_5 F_35 ( void )
{
if ( ! F_36 () )
return 0 ;
return F_37 ( & V_54 ) ;
}
static void T_6 F_38 ( void )
{
if ( ! F_36 () )
return;
F_39 ( F_40 ( & V_54 ) ,
L_1 , V_55 ) ;
}
