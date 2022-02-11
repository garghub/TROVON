static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_2 * V_4 , struct V_5 * * V_6 , int V_7 ,
int V_8 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
struct V_2 * V_12 [ V_13 + 1 ] ;
struct V_14 * V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
bool V_19 = false ;
int V_20 ;
if ( ! V_3 )
return - V_21 ;
V_20 = F_3 ( V_12 , V_13 , V_3 , V_22 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( ! V_12 [ V_23 ] || ! V_12 [ V_24 ] ||
! V_12 [ V_25 ] )
return - V_21 ;
V_16 = F_4 ( V_12 [ V_23 ] ) ;
V_19 = F_5 ( V_10 , V_16 -> V_26 , V_6 , V_8 ) ;
if ( V_19 && V_8 )
return 0 ;
if ( ! V_19 ) {
V_20 = F_6 ( V_10 , V_16 -> V_26 , V_4 , V_6 ,
& V_27 , V_8 , false ) ;
if ( V_20 )
return V_20 ;
V_20 = V_28 ;
} else {
F_7 ( * V_6 , V_8 ) ;
if ( ! V_7 )
return - V_29 ;
}
V_18 = F_8 ( * V_6 ) ;
V_18 -> V_30 = V_16 -> V_31 ;
V_18 -> V_32 = F_9 ( V_12 [ V_24 ] ) ;
V_18 -> V_33 = F_9 ( V_12 [ V_25 ] ) ;
V_14 = F_10 ( V_1 , V_18 -> V_33 ) ;
if ( ! V_14 ) {
if ( V_20 == V_28 )
F_7 ( * V_6 , V_8 ) ;
return - V_34 ;
}
F_11 ( V_18 -> V_14 , V_14 ) ;
if ( V_12 [ V_35 ] ) {
V_18 -> V_36 = true ;
V_18 -> V_37 = F_9 ( V_12 [ V_35 ] ) ;
}
if ( V_20 == V_28 )
F_12 ( V_10 , * V_6 ) ;
return V_20 ;
}
static void F_13 ( struct V_38 * V_39 )
{
struct V_17 * V_18 = F_14 ( V_39 , struct V_17 , V_39 ) ;
struct V_14 * V_14 ;
V_14 = F_15 ( V_18 -> V_14 , 1 ) ;
F_11 ( V_18 -> V_14 , NULL ) ;
F_16 ( V_14 ) ;
}
static void F_17 ( struct V_5 * V_6 , int V_8 )
{
struct V_17 * V_18 = F_8 ( V_6 ) ;
F_18 ( & V_18 -> V_39 , F_13 ) ;
}
static bool F_19 ( struct V_40 * V_41 )
{
switch ( V_41 -> type ) {
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
return false ;
default:
return true ;
}
}
static int F_20 ( struct V_48 * V_49 , const struct V_5 * V_6 ,
struct V_50 * V_51 )
{
struct V_17 * V_18 = F_8 ( V_6 ) ;
struct V_14 * V_14 ;
int V_52 ;
int V_53 ;
int V_54 ;
int V_55 ;
F_21 ( & V_18 -> V_56 ) ;
F_22 ( F_23 ( V_18 -> V_57 . V_58 ) , V_49 ) ;
V_52 = F_24 ( V_18 -> V_30 ) ;
F_25 () ;
V_14 = F_26 ( V_18 -> V_14 ) ;
if ( V_14 && ( F_27 () % V_18 -> V_32 == 0 ) ) {
if ( ! F_28 ( V_49 ) ) {
V_54 = V_49 -> V_59 ;
V_55 = V_49 -> V_41 -> V_60 ;
} else {
V_54 = V_49 -> V_41 -> V_60 ;
V_55 = 0 ;
}
if ( F_28 ( V_49 ) && F_19 ( V_49 -> V_41 ) )
F_29 ( V_49 , V_49 -> V_61 ) ;
V_53 = V_18 -> V_36 ? V_18 -> V_37 : V_49 -> V_62 ;
F_30 ( V_14 , V_49 , V_53 , V_54 , V_55 ,
V_18 -> V_32 ) ;
if ( F_28 ( V_49 ) && F_19 ( V_49 -> V_41 ) )
F_31 ( V_49 , V_49 -> V_61 ) ;
}
F_32 () ;
return V_52 ;
}
static int F_33 ( struct V_48 * V_49 , struct V_5 * V_6 ,
int V_8 , int V_63 )
{
unsigned char * V_64 = F_34 ( V_49 ) ;
struct V_17 * V_18 = F_8 ( V_6 ) ;
struct V_15 V_65 = {
. V_26 = V_18 -> V_66 ,
. V_31 = V_18 -> V_30 ,
. V_67 = V_18 -> V_68 - V_63 ,
. V_69 = V_18 -> V_70 - V_8 ,
} ;
struct V_71 V_72 ;
if ( F_35 ( V_49 , V_23 , sizeof( V_65 ) , & V_65 ) )
goto V_73;
F_36 ( & V_72 , & V_18 -> V_56 ) ;
if ( F_37 ( V_49 , V_74 , sizeof( V_72 ) , & V_72 , V_75 ) )
goto V_73;
if ( F_38 ( V_49 , V_24 , V_18 -> V_32 ) )
goto V_73;
if ( V_18 -> V_36 )
if ( F_38 ( V_49 , V_35 , V_18 -> V_37 ) )
goto V_73;
if ( F_38 ( V_49 , V_25 , V_18 -> V_33 ) )
goto V_73;
return V_49 -> V_62 ;
V_73:
F_39 ( V_49 , V_64 ) ;
return - 1 ;
}
static int F_40 ( struct V_1 * V_1 , struct V_48 * V_49 ,
struct V_76 * V_77 , int type ,
const struct V_78 * V_79 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
return F_41 ( V_10 , V_49 , V_77 , type , V_79 ) ;
}
static int F_42 ( struct V_1 * V_1 , struct V_5 * * V_6 , T_1 V_26 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
return F_43 ( V_10 , V_6 , V_26 ) ;
}
static T_2 int F_44 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
return F_45 ( V_10 , & V_27 , V_80 ) ;
}
static void T_3 F_46 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
F_47 ( V_10 ) ;
}
static int T_4 F_48 ( void )
{
return F_49 ( & V_27 , & V_81 ) ;
}
static void T_5 F_50 ( void )
{
F_51 ( & V_27 , & V_81 ) ;
}
