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
int type = F_5 ( V_3 ) ;
if ( ( type == V_6 ) ||
( type == V_7 ) ||
( type == V_8 ) ) {
if ( V_5 )
F_6 ( V_3 ) ;
else
F_7 ( V_3 ) ;
}
if ( V_5 )
F_8 ( V_3 ) ;
return 0 ;
}
static void F_9 ( struct V_2 * V_3 ,
bool V_5 )
{
F_4 ( V_3 , & V_5 ) ;
if ( ! V_3 -> V_9 )
return;
F_10 ( V_3 -> V_9 , F_4 , & V_5 ) ;
}
static void F_11 ( struct V_10 * V_11 )
{
struct V_2 * V_12 = V_11 -> V_13 -> V_14 ;
int V_15 ;
T_1 V_16 ;
T_2 V_17 ;
F_12 ( V_12 , V_18 , & V_16 ) ;
F_13 ( V_12 , V_18 , V_16 ) ;
F_14 ( V_12 , V_19 ,
V_20 ) ;
V_15 = V_12 -> V_21 ;
F_15 ( V_12 , V_15 + V_22 , & V_17 ) ;
F_16 ( V_12 , V_15 + V_22 , V_17 ) ;
F_15 ( V_12 , V_15 + V_23 , & V_17 ) ;
F_16 ( V_12 , V_15 + V_23 , V_17 ) ;
F_15 ( V_12 , V_15 + V_24 , & V_17 ) ;
F_16 ( V_12 , V_15 + V_24 , V_17 ) ;
F_9 ( V_12 , true ) ;
F_15 ( V_12 , V_15 + V_25 , & V_17 ) ;
V_17 |= V_26 ;
F_16 ( V_12 , V_15 + V_25 , V_17 ) ;
}
static void F_17 ( struct V_10 * V_11 )
{
struct V_2 * V_12 = V_11 -> V_13 -> V_14 ;
T_2 V_17 ;
int V_27 ;
F_9 ( V_12 , false ) ;
V_27 = V_12 -> V_21 ;
F_15 ( V_12 , V_27 + V_25 , & V_17 ) ;
V_17 &= ~ V_26 ;
F_16 ( V_12 , V_27 + V_25 , V_17 ) ;
F_15 ( V_12 , V_27 + V_22 , & V_17 ) ;
F_16 ( V_12 , V_27 + V_22 , V_17 ) ;
}
T_3 F_18 ( int V_28 , void * V_29 )
{
unsigned int V_30 , V_31 ;
struct V_32 * V_12 = (struct V_32 * ) V_29 ;
struct V_10 * V_11 = F_19 ( V_12 ) ;
int V_33 ;
unsigned long V_34 ;
int V_27 ;
V_27 = V_12 -> V_14 -> V_21 ;
F_20 ( & V_11 -> V_35 , V_34 ) ;
F_15 ( V_12 -> V_14 , V_27 + V_22 , & V_30 ) ;
if ( ! ( V_30 & ( V_36 | V_37 ) ) ) {
F_21 ( & V_11 -> V_35 , V_34 ) ;
return V_38 ;
}
F_15 ( V_12 -> V_14 , V_27 + V_39 , & V_31 ) ;
F_16 ( V_12 -> V_14 , V_27 + V_22 , V_30 ) ;
V_33 = V_11 -> V_40 + 1 ;
if ( V_33 == V_41 )
V_33 = 0 ;
if ( V_33 == V_11 -> V_42 ) {
F_21 ( & V_11 -> V_35 , V_34 ) ;
return V_43 ;
}
V_11 -> V_44 [ V_11 -> V_40 ] . V_30 = V_30 ;
V_11 -> V_44 [ V_11 -> V_40 ] . V_31 = V_31 ;
V_11 -> V_40 = V_33 ;
F_21 ( & V_11 -> V_35 , V_34 ) ;
F_22 ( & V_11 -> V_45 ) ;
return V_43 ;
}
static struct V_10 * F_23 ( struct V_32 * V_3 )
{
struct V_10 * V_11 ;
V_11 = F_24 ( sizeof( struct V_10 ) , V_46 ) ;
if ( ! V_11 )
return NULL ;
F_25 ( & V_11 -> V_35 ) ;
V_11 -> V_13 = V_3 ;
F_26 ( & V_11 -> V_45 , V_47 ) ;
F_27 ( & V_11 -> V_48 ) ;
F_28 ( V_3 , V_11 ) ;
return V_11 ;
}
static void F_29 ( struct V_32 * V_3 )
{
struct V_10 * V_11 = F_19 ( V_3 ) ;
if ( V_11 ) {
if ( V_11 -> V_49 )
F_30 ( V_3 -> V_28 , V_3 ) ;
F_31 ( & V_11 -> V_45 ) ;
F_17 ( V_11 ) ;
F_32 ( V_11 ) ;
F_28 ( V_3 , NULL ) ;
}
}
static int F_33 ( struct V_32 * V_3 )
{
int V_30 ;
struct V_10 * V_11 ;
struct V_50 * V_50 = & V_3 -> V_50 ;
V_11 = F_23 ( V_3 ) ;
if ( ! V_11 ) {
F_34 ( V_51 , V_50 , L_1 ) ;
F_29 ( V_3 ) ;
return - V_52 ;
}
V_30 = F_35 ( V_3 -> V_28 , F_18 , V_53 , L_2 , V_3 ) ;
if ( V_30 ) {
F_34 ( V_51 , V_50 , L_3 ) ;
F_29 ( V_3 ) ;
return V_30 ;
}
V_11 -> V_49 = 1 ;
F_11 ( V_11 ) ;
return V_30 ;
}
static T_4 F_36 ( struct V_2 * V_3 )
{
T_2 V_17 ;
int V_27 ;
V_27 = V_3 -> V_21 ;
F_15 ( V_3 , V_27 + V_25 , & V_17 ) ;
V_17 &= ~ V_26 ;
F_16 ( V_3 , V_27 + V_25 , V_17 ) ;
F_37 ( V_3 ) ;
F_34 ( V_51 , & V_3 -> V_3 , L_4 ) ;
F_15 ( V_3 , V_27 + V_22 , & V_17 ) ;
F_16 ( V_3 , V_27 + V_22 , V_17 ) ;
F_15 ( V_3 , V_27 + V_25 , & V_17 ) ;
V_17 |= V_26 ;
F_16 ( V_3 , V_27 + V_25 , V_17 ) ;
return V_54 ;
}
static T_4 F_38 ( struct V_2 * V_3 ,
enum V_55 error )
{
return V_56 ;
}
static void F_39 ( struct V_2 * V_3 )
{
int V_27 ;
T_2 V_30 , V_57 ;
T_1 V_16 ;
F_12 ( V_3 , V_18 , & V_16 ) ;
F_13 ( V_3 , V_18 , V_16 ) ;
V_27 = V_3 -> V_21 ;
F_15 ( V_3 , V_27 + V_24 , & V_30 ) ;
F_15 ( V_3 , V_27 + V_58 , & V_57 ) ;
if ( V_3 -> V_59 == V_60 )
V_30 &= ~ V_57 ;
else
V_30 &= V_57 ;
F_16 ( V_3 , V_27 + V_24 , V_30 ) ;
}
static int T_5 F_40 ( void )
{
if ( ! F_2 () || F_41 () )
return - V_61 ;
return F_42 ( & V_62 ) ;
}
