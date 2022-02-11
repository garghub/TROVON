static int F_1 ( const struct V_1 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 [ 0 ] . V_7 & V_8 ) {
F_2 ( L_1 ) ;
return - V_9 ;
}
if ( V_4 -> V_10 != 1 ) {
F_2 ( L_2 , V_4 -> V_10 ) ;
return - V_9 ;
}
return 0 ;
}
static unsigned int
F_3 ( struct V_11 * V_12 , const struct V_13 * V_2 )
{
struct V_14 * V_15 ;
struct V_16 * V_17 ;
enum V_18 V_19 ;
struct V_20 V_21 ;
const struct V_3 * V_4 ;
const struct V_22 * V_23 ;
T_1 V_24 ;
F_4 ( V_2 -> V_25 == V_26 ) ;
V_15 = F_5 ( V_12 , & V_19 ) ;
V_17 = F_6 ( V_15 ) ;
F_4 ( V_15 && ( V_19 == V_27 || V_19 == V_28 ||
V_19 == V_29 ) ) ;
if ( V_15 -> V_30 [ V_31 ] . V_32 . V_33 . V_34 . V_35 == 0 )
return V_36 ;
V_4 = V_2 -> V_5 ;
V_23 = F_7 ( V_12 ) ;
V_24 = F_8 ( V_2 -> V_37 , V_23 -> V_38 , V_39 ) ;
if ( ! V_24 ) {
F_9 ( L_3 , V_2 -> V_37 -> V_40 ) ;
return V_41 ;
}
V_17 -> V_42 = V_2 -> V_37 -> V_43 ;
V_21 = ( (struct V_20 )
{ V_4 -> V_6 [ 0 ] . V_7 | V_8 ,
V_24 , V_24 ,
V_4 -> V_6 [ 0 ] . V_44 , V_4 -> V_6 [ 0 ] . V_45 } ) ;
return F_10 ( V_15 , & V_21 , V_46 ) ;
}
static int
F_11 ( struct V_14 * V_47 , void * V_43 )
{
const struct V_16 * V_17 = F_6 ( V_47 ) ;
if ( ! V_17 )
return 0 ;
return V_17 -> V_42 == ( int ) ( long ) V_43 ;
}
static int F_12 ( struct V_48 * V_49 ,
unsigned long V_50 ,
void * V_51 )
{
const struct V_52 * V_53 = V_51 ;
struct V_54 * V_54 = F_13 ( V_53 ) ;
if ( V_50 == V_55 ) {
F_4 ( V_53 -> V_43 != 0 ) ;
F_14 ( V_54 , F_11 ,
( void * ) ( long ) V_53 -> V_43 ) ;
}
return V_56 ;
}
static int F_15 ( struct V_48 * V_49 ,
unsigned long V_50 ,
void * V_51 )
{
struct V_52 * V_53 = ( (struct V_57 * ) V_51 ) -> V_58 -> V_53 ;
return F_12 ( V_49 , V_50 , V_53 ) ;
}
static int T_2 F_16 ( void )
{
int V_59 ;
V_59 = F_17 ( & V_60 ) ;
if ( V_59 == 0 ) {
F_18 ( & V_61 ) ;
F_19 ( & V_62 ) ;
}
return V_59 ;
}
static void T_3 F_20 ( void )
{
F_21 ( & V_60 ) ;
F_22 ( & V_61 ) ;
F_23 ( & V_62 ) ;
}
