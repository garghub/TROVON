void F_1 ( void )
{
V_1 = 1 ;
}
bool F_2 ( void )
{
return ! V_1 && F_3 () ;
}
static int F_4 ( struct V_2 * V_3 , void * V_4 )
{
bool V_5 = * ( ( bool * ) V_4 ) ;
if ( ( V_3 -> V_6 == V_7 ) ||
( V_3 -> V_6 == V_8 ) ||
( V_3 -> V_6 == V_9 ) ) {
if ( V_5 )
F_5 ( V_3 ) ;
else
F_6 ( V_3 ) ;
}
if ( V_5 )
F_7 ( V_3 ) ;
return 0 ;
}
static void F_8 ( struct V_2 * V_3 ,
bool V_5 )
{
F_4 ( V_3 , & V_5 ) ;
if ( ! V_3 -> V_10 )
return;
F_9 ( V_3 -> V_10 , F_4 , & V_5 ) ;
}
static void F_10 ( struct V_11 * V_12 )
{
struct V_2 * V_13 = V_12 -> V_14 -> V_15 ;
int V_16 , V_17 ;
T_1 V_18 ;
T_2 V_19 ;
V_16 = F_11 ( V_13 ) ;
F_12 ( V_13 , V_16 + V_20 , & V_18 ) ;
F_13 ( V_13 , V_16 + V_20 , V_18 ) ;
F_12 ( V_13 , V_16 + V_21 , & V_18 ) ;
V_18 &= ~ ( V_22 ) ;
F_13 ( V_13 , V_16 + V_21 , V_18 ) ;
V_17 = F_14 ( V_13 , V_23 ) ;
F_15 ( V_13 , V_17 + V_24 , & V_19 ) ;
F_16 ( V_13 , V_17 + V_24 , V_19 ) ;
F_15 ( V_13 , V_17 + V_25 , & V_19 ) ;
F_16 ( V_13 , V_17 + V_25 , V_19 ) ;
F_15 ( V_13 , V_17 + V_26 , & V_19 ) ;
F_16 ( V_13 , V_17 + V_26 , V_19 ) ;
F_8 ( V_13 , true ) ;
F_15 ( V_13 , V_17 + V_27 , & V_19 ) ;
V_19 |= V_28 ;
F_16 ( V_13 , V_17 + V_27 , V_19 ) ;
}
static void F_17 ( struct V_11 * V_12 )
{
struct V_2 * V_13 = V_12 -> V_14 -> V_15 ;
T_2 V_19 ;
int V_16 ;
F_8 ( V_13 , false ) ;
V_16 = F_14 ( V_13 , V_23 ) ;
F_15 ( V_13 , V_16 + V_27 , & V_19 ) ;
V_19 &= ~ V_28 ;
F_16 ( V_13 , V_16 + V_27 , V_19 ) ;
F_15 ( V_13 , V_16 + V_24 , & V_19 ) ;
F_16 ( V_13 , V_16 + V_24 , V_19 ) ;
}
T_3 F_18 ( int V_29 , void * V_30 )
{
unsigned int V_31 , V_32 ;
struct V_33 * V_13 = (struct V_33 * ) V_30 ;
struct V_11 * V_12 = F_19 ( V_13 ) ;
int V_34 ;
unsigned long V_35 ;
int V_16 ;
V_16 = F_14 ( V_13 -> V_15 , V_23 ) ;
F_20 ( & V_12 -> V_36 , V_35 ) ;
F_15 ( V_13 -> V_15 , V_16 + V_24 , & V_31 ) ;
if ( ! ( V_31 & ( V_37 | V_38 ) ) ) {
F_21 ( & V_12 -> V_36 , V_35 ) ;
return V_39 ;
}
F_15 ( V_13 -> V_15 , V_16 + V_40 , & V_32 ) ;
F_16 ( V_13 -> V_15 , V_16 + V_24 , V_31 ) ;
V_34 = V_12 -> V_41 + 1 ;
if ( V_34 == V_42 )
V_34 = 0 ;
if ( V_34 == V_12 -> V_43 ) {
F_21 ( & V_12 -> V_36 , V_35 ) ;
return V_44 ;
}
V_12 -> V_45 [ V_12 -> V_41 ] . V_31 = V_31 ;
V_12 -> V_45 [ V_12 -> V_41 ] . V_32 = V_32 ;
V_12 -> V_41 = V_34 ;
F_21 ( & V_12 -> V_36 , V_35 ) ;
F_22 ( & V_12 -> V_46 ) ;
return V_44 ;
}
static struct V_11 * F_23 ( struct V_33 * V_3 )
{
struct V_11 * V_12 ;
V_12 = F_24 ( sizeof( struct V_11 ) , V_47 ) ;
if ( ! V_12 )
return NULL ;
F_25 ( & V_12 -> V_36 ) ;
V_12 -> V_14 = V_3 ;
F_26 ( & V_12 -> V_46 , V_48 ) ;
F_27 ( & V_12 -> V_49 ) ;
F_28 ( & V_12 -> V_50 ) ;
F_29 ( V_3 , V_12 ) ;
return V_12 ;
}
static void F_30 ( struct V_33 * V_3 )
{
struct V_11 * V_12 = F_19 ( V_3 ) ;
if ( V_12 ) {
if ( V_12 -> V_51 )
F_31 ( V_3 -> V_29 , V_3 ) ;
F_32 ( V_12 -> V_50 , V_12 -> V_41 == V_12 -> V_43 ) ;
F_17 ( V_12 ) ;
F_33 ( V_12 ) ;
F_29 ( V_3 , NULL ) ;
}
}
static int T_4 F_34 ( struct V_33 * V_3 )
{
int V_31 ;
struct V_11 * V_12 ;
struct V_52 * V_52 = & V_3 -> V_52 ;
V_31 = F_35 ( V_3 ) ;
if ( V_31 )
return V_31 ;
V_12 = F_23 ( V_3 ) ;
if ( ! V_12 ) {
F_36 ( V_53 , V_52 , L_1 ) ;
F_30 ( V_3 ) ;
return - V_54 ;
}
V_31 = F_37 ( V_3 -> V_29 , F_18 , V_55 , L_2 , V_3 ) ;
if ( V_31 ) {
F_36 ( V_53 , V_52 , L_3 ) ;
F_30 ( V_3 ) ;
return V_31 ;
}
V_12 -> V_51 = 1 ;
F_10 ( V_12 ) ;
return V_31 ;
}
static T_5 F_38 ( struct V_2 * V_3 )
{
T_2 V_19 ;
int V_16 ;
V_16 = F_14 ( V_3 , V_23 ) ;
F_15 ( V_3 , V_16 + V_27 , & V_19 ) ;
V_19 &= ~ V_28 ;
F_16 ( V_3 , V_16 + V_27 , V_19 ) ;
F_39 ( V_3 ) ;
F_36 ( V_53 , & V_3 -> V_3 , L_4 ) ;
F_15 ( V_3 , V_16 + V_24 , & V_19 ) ;
F_16 ( V_3 , V_16 + V_24 , V_19 ) ;
F_15 ( V_3 , V_16 + V_27 , & V_19 ) ;
V_19 |= V_28 ;
F_16 ( V_3 , V_16 + V_27 , V_19 ) ;
return V_56 ;
}
static T_5 F_40 ( struct V_2 * V_3 ,
enum V_57 error )
{
return V_58 ;
}
static void F_41 ( struct V_2 * V_3 )
{
int V_16 ;
T_2 V_31 , V_59 ;
T_1 V_18 ;
V_16 = F_11 ( V_3 ) ;
F_12 ( V_3 , V_16 + V_20 , & V_18 ) ;
F_13 ( V_3 , V_16 + V_20 , V_18 ) ;
V_16 = F_14 ( V_3 , V_23 ) ;
F_15 ( V_3 , V_16 + V_26 , & V_31 ) ;
F_15 ( V_3 , V_16 + V_60 , & V_59 ) ;
if ( V_3 -> V_61 == V_62 )
V_31 &= ~ V_59 ;
else
V_31 &= V_59 ;
F_16 ( V_3 , V_16 + V_26 , V_31 ) ;
}
static int T_6 F_42 ( void )
{
if ( ! F_2 () || F_43 () )
return - V_63 ;
return F_44 ( & V_64 ) ;
}
static void T_7 F_45 ( void )
{
F_46 ( & V_64 ) ;
}
