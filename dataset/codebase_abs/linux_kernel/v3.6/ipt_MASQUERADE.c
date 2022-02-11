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
T_1 V_24 , V_25 ;
F_4 ( V_2 -> V_26 == V_27 ) ;
V_15 = F_5 ( V_12 , & V_19 ) ;
V_17 = F_6 ( V_15 ) ;
F_4 ( V_15 && ( V_19 == V_28 || V_19 == V_29 ||
V_19 == V_30 ) ) ;
if ( V_15 -> V_31 [ V_32 ] . V_33 . V_34 . V_35 . V_36 == 0 )
return V_37 ;
V_4 = V_2 -> V_5 ;
V_23 = F_7 ( V_12 ) ;
V_25 = F_8 ( V_23 , F_9 ( V_12 ) -> V_38 ) ;
V_24 = F_10 ( V_2 -> V_39 , V_25 , V_40 ) ;
if ( ! V_24 ) {
F_11 ( L_3 , V_2 -> V_39 -> V_41 ) ;
return V_42 ;
}
V_17 -> V_43 = V_2 -> V_39 -> V_44 ;
V_21 = ( (struct V_20 )
{ V_4 -> V_6 [ 0 ] . V_7 | V_8 ,
V_24 , V_24 ,
V_4 -> V_6 [ 0 ] . V_45 , V_4 -> V_6 [ 0 ] . V_46 } ) ;
return F_12 ( V_15 , & V_21 , V_47 ) ;
}
static int
F_13 ( struct V_14 * V_48 , void * V_44 )
{
const struct V_16 * V_17 = F_6 ( V_48 ) ;
if ( ! V_17 )
return 0 ;
return V_17 -> V_43 == ( int ) ( long ) V_44 ;
}
static int F_14 ( struct V_49 * V_50 ,
unsigned long V_51 ,
void * V_52 )
{
const struct V_53 * V_54 = V_52 ;
struct V_55 * V_55 = F_15 ( V_54 ) ;
if ( V_51 == V_56 ) {
F_4 ( V_54 -> V_44 != 0 ) ;
F_16 ( V_55 , F_13 ,
( void * ) ( long ) V_54 -> V_44 ) ;
}
return V_57 ;
}
static int F_17 ( struct V_49 * V_50 ,
unsigned long V_51 ,
void * V_52 )
{
struct V_53 * V_54 = ( (struct V_58 * ) V_52 ) -> V_59 -> V_54 ;
return F_14 ( V_50 , V_51 , V_54 ) ;
}
static int T_2 F_18 ( void )
{
int V_60 ;
V_60 = F_19 ( & V_61 ) ;
if ( V_60 == 0 ) {
F_20 ( & V_62 ) ;
F_21 ( & V_63 ) ;
}
return V_60 ;
}
static void T_3 F_22 ( void )
{
F_23 ( & V_61 ) ;
F_24 ( & V_62 ) ;
F_25 ( & V_63 ) ;
}
