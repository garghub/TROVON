static T_1 * F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned char V_5 = 0x00 ;
unsigned int V_6 ;
T_1 * V_7 = F_2 ( V_8 , V_9 ) ;
struct V_10 V_11 [] = {
{
. V_12 = V_2 -> V_12 ,
. V_13 = 0 ,
. V_14 = 1 ,
. V_15 = & V_5 ,
} , {
. V_12 = V_2 -> V_12 ,
. V_13 = V_16 ,
. V_14 = V_8 ,
. V_15 = V_7 ,
}
} ;
if ( ! V_7 )
return NULL ;
if ( F_3 ( V_4 , V_11 , 2 ) != 2 ) {
F_4 ( L_1 ) ;
goto V_17;
}
if ( ! F_5 ( V_7 , 0 , false , NULL ) ) {
F_4 ( L_2 ) ;
goto V_17;
}
V_6 = ( V_7 [ V_18 ] + 1 ) * V_8 ;
if ( V_6 > V_8 ) {
F_6 ( V_7 ) ;
V_7 = F_2 ( V_6 , V_9 ) ;
if ( ! V_7 )
return NULL ;
V_5 = 0x00 ;
V_11 [ 1 ] . V_14 = V_6 ;
V_11 [ 1 ] . V_15 = V_7 ;
if ( F_3 ( V_4 , V_11 , 2 ) != 2 ) {
F_4 ( L_3 ) ;
goto V_17;
}
if ( ! F_5 ( V_7 , 1 , false , NULL ) ) {
F_4 ( L_2 ) ;
goto V_17;
}
}
return V_7 ;
V_17:
F_6 ( V_7 ) ;
return NULL ;
}
static int F_7 ( struct V_19 * V_20 )
{
struct V_1 * V_2 ;
int V_21 = 0 ;
V_2 = V_22 -> V_23 ;
F_6 ( V_22 -> V_24 ) ;
V_22 -> V_24 = (struct V_24 * ) F_1 ( V_2 ) ;
if ( V_22 -> V_24 ) {
F_8 ( V_20 ,
V_22 -> V_24 ) ;
V_21 = F_9 ( V_20 ,
V_22 -> V_24 ) ;
}
return V_21 ;
}
static enum V_25 F_10 (
struct V_19 * V_20 , struct V_26 * V_27 )
{
return V_28 ;
}
static enum V_29 F_11 (
struct V_19 * V_20 , bool V_30 )
{
struct V_1 * V_31 =
V_22 -> V_31 ;
T_2 V_32 ;
V_32 = F_12 ( V_31 ,
V_33 ) ;
if ( V_32 == V_34 )
return V_35 ;
if ( V_32 == 0 )
return V_36 ;
return V_37 ;
}
static T_3 F_13 ( int V_38 , void * V_39 )
{
struct V_1 * V_31
= V_22 -> V_31 ;
F_14 ( V_31 ,
V_40 ,
V_41 ) ;
if ( V_22 -> V_20 . V_42 )
F_15 ( V_22 -> V_20 . V_42 ) ;
return V_43 ;
}
static int F_16 ( struct V_44 * V_45 )
{
struct V_19 * V_20 = & V_22 -> V_20 ;
struct V_1 * V_31
= V_22 -> V_31 ;
int V_46 ;
if ( ! V_45 -> V_47 ) {
F_4 ( L_4 ) ;
return - V_48 ;
}
V_20 -> V_49 = V_50 ;
F_17 ( V_20 ,
& V_51 ) ;
V_46 = F_18 ( V_45 -> V_42 , V_20 ,
& V_52 ,
V_53 ) ;
if ( V_46 ) {
F_4 ( L_5 ) ;
return V_46 ;
}
V_46 = F_19 ( V_20 , V_45 -> V_47 ) ;
if ( V_46 )
return V_46 ;
F_14 ( V_31 ,
V_54 ,
V_55 ) ;
F_14 ( V_31 ,
V_56 ,
V_57 ) ;
return 0 ;
}
static int F_20 ( struct V_58 * V_42 )
{
F_21 ( & V_59 ) ;
if ( V_22 )
goto V_60;
V_22 = F_22 ( V_42 ,
sizeof( * V_22 ) ,
V_9 ) ;
if ( ! V_22 ) {
F_23 ( & V_59 ) ;
return - V_61 ;
}
V_60:
F_23 ( & V_59 ) ;
return 0 ;
}
static void F_24 ( void )
{
F_21 ( & V_59 ) ;
if ( ! V_22 )
goto V_62;
F_25 ( & V_22 -> V_45 ) ;
F_6 ( V_22 -> V_24 ) ;
V_22 = NULL ;
V_62:
F_23 ( & V_59 ) ;
}
static int F_26 ( struct V_1 * V_31 ,
const struct V_63 * V_64 )
{
struct V_58 * V_42 = & V_31 -> V_42 ;
F_20 ( V_42 ) ;
V_22 -> V_31 = V_31 ;
F_27 ( V_31 , V_22 ) ;
V_22 -> V_45 . V_65 = & V_66 ;
V_22 -> V_45 . V_67 = V_42 -> V_67 ;
F_28 ( & V_22 -> V_45 ) ;
F_14 ( V_31 ,
V_40 ,
V_41 ) ;
if ( ! V_31 -> V_38 )
return 0 ;
return F_29 ( & V_31 -> V_42 ,
V_31 -> V_38 , NULL ,
F_13 ,
V_68 | V_69 ,
L_6 , V_22 ) ;
}
static int F_30 ( struct V_1 * V_31 )
{
F_24 () ;
return 0 ;
}
static int F_31 ( struct V_1 * V_23 ,
const struct V_63 * V_64 )
{
struct V_58 * V_42 = & V_23 -> V_42 ;
F_20 ( V_42 ) ;
V_22 -> V_23 = V_23 ;
F_27 ( V_23 , V_22 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_23 )
{
F_24 () ;
return 0 ;
}
static int T_4 F_33 ( void )
{
int V_46 ;
V_46 = F_34 ( & V_70 ) ;
if ( V_46 )
return V_46 ;
return F_34 ( & V_71 ) ;
}
static void T_5 F_35 ( void )
{
F_36 ( & V_71 ) ;
F_36 ( & V_70 ) ;
}
