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
memset ( & V_21 . V_45 , 0 , sizeof( V_21 . V_45 ) ) ;
memset ( & V_21 . V_46 , 0 , sizeof( V_21 . V_46 ) ) ;
V_21 . V_7 = V_4 -> V_6 [ 0 ] . V_7 | V_8 ;
V_21 . V_45 . V_36 = V_24 ;
V_21 . V_46 . V_36 = V_24 ;
V_21 . V_47 = V_4 -> V_6 [ 0 ] . V_48 ;
V_21 . V_49 = V_4 -> V_6 [ 0 ] . V_50 ;
return F_12 ( V_15 , & V_21 , V_51 ) ;
}
static int
F_13 ( struct V_14 * V_52 , void * V_44 )
{
const struct V_16 * V_17 = F_6 ( V_52 ) ;
if ( ! V_17 )
return 0 ;
if ( F_14 ( V_52 ) != V_53 )
return 0 ;
return V_17 -> V_43 == ( int ) ( long ) V_44 ;
}
static int F_15 ( struct V_54 * V_55 ,
unsigned long V_56 ,
void * V_57 )
{
const struct V_58 * V_59 = V_57 ;
struct V_60 * V_60 = F_16 ( V_59 ) ;
if ( V_56 == V_61 ) {
F_4 ( V_59 -> V_44 != 0 ) ;
F_17 ( V_60 , F_13 ,
( void * ) ( long ) V_59 -> V_44 ) ;
}
return V_62 ;
}
static int F_18 ( struct V_54 * V_55 ,
unsigned long V_56 ,
void * V_57 )
{
struct V_58 * V_59 = ( (struct V_63 * ) V_57 ) -> V_64 -> V_59 ;
return F_15 ( V_55 , V_56 , V_59 ) ;
}
static int T_2 F_19 ( void )
{
int V_65 ;
V_65 = F_20 ( & V_66 ) ;
if ( V_65 == 0 ) {
F_21 ( & V_67 ) ;
F_22 ( & V_68 ) ;
}
return V_65 ;
}
static void T_3 F_23 ( void )
{
F_24 ( & V_66 ) ;
F_25 ( & V_67 ) ;
F_26 ( & V_68 ) ;
}
