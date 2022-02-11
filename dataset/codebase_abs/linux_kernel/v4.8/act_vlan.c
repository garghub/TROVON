static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct F_1 * V_7 = F_2 ( V_4 ) ;
int V_8 ;
int V_9 ;
F_3 ( & V_7 -> V_10 ) ;
F_4 ( & V_7 -> V_11 ) ;
F_5 ( & V_7 -> V_12 , V_2 ) ;
V_8 = V_7 -> V_13 ;
switch ( V_7 -> V_14 ) {
case V_15 :
V_9 = F_6 ( V_2 ) ;
if ( V_9 )
goto V_16;
break;
case V_17 :
V_9 = F_7 ( V_2 , V_7 -> V_18 , V_7 -> V_19 ) ;
if ( V_9 )
goto V_16;
break;
default:
F_8 () ;
}
goto V_20;
V_16:
V_8 = V_21 ;
V_7 -> V_22 . V_23 ++ ;
V_20:
F_9 ( & V_7 -> V_10 ) ;
return V_8 ;
}
static int F_10 ( struct V_24 * V_24 , struct V_25 * V_26 ,
struct V_25 * V_27 , struct V_3 * * V_4 ,
int V_28 , int V_29 )
{
struct V_30 * V_31 = F_11 ( V_24 , V_32 ) ;
struct V_25 * V_33 [ V_34 + 1 ] ;
struct V_35 * V_36 ;
struct F_1 * V_7 ;
int V_8 ;
T_1 V_37 = 0 ;
T_1 V_38 = 0 ;
bool V_39 = false ;
int V_40 = 0 , V_9 ;
if ( ! V_26 )
return - V_41 ;
V_9 = F_12 ( V_33 , V_34 , V_26 , V_42 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( ! V_33 [ V_43 ] )
return - V_41 ;
V_36 = F_13 ( V_33 [ V_43 ] ) ;
V_39 = F_14 ( V_31 , V_36 -> V_44 , V_4 , V_29 ) ;
if ( V_39 && V_29 )
return 0 ;
switch ( V_36 -> V_45 ) {
case V_15 :
break;
case V_17 :
if ( ! V_33 [ V_46 ] ) {
if ( V_39 )
F_15 ( * V_4 , V_29 ) ;
return - V_41 ;
}
V_37 = F_16 ( V_33 [ V_46 ] ) ;
if ( V_37 >= V_47 ) {
if ( V_39 )
F_15 ( * V_4 , V_29 ) ;
return - V_48 ;
}
if ( V_33 [ V_49 ] ) {
V_38 = F_17 ( V_33 [ V_49 ] ) ;
switch ( V_38 ) {
case F_18 ( V_50 ) :
case F_18 ( V_51 ) :
break;
default:
return - V_52 ;
}
} else {
V_38 = F_18 ( V_50 ) ;
}
break;
default:
if ( V_39 )
F_15 ( * V_4 , V_29 ) ;
return - V_41 ;
}
V_8 = V_36 -> V_45 ;
if ( ! V_39 ) {
V_40 = F_19 ( V_31 , V_36 -> V_44 , V_27 , V_4 ,
& V_53 , V_29 , false ) ;
if ( V_40 )
return V_40 ;
V_40 = V_54 ;
} else {
F_15 ( * V_4 , V_29 ) ;
if ( ! V_28 )
return - V_55 ;
}
V_7 = F_2 ( * V_4 ) ;
F_20 ( & V_7 -> V_10 ) ;
V_7 -> V_14 = V_8 ;
V_7 -> V_19 = V_37 ;
V_7 -> V_18 = V_38 ;
V_7 -> V_13 = V_36 -> V_8 ;
F_21 ( & V_7 -> V_10 ) ;
if ( V_40 == V_54 )
F_22 ( V_31 , * V_4 ) ;
return V_40 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_29 , int V_56 )
{
unsigned char * V_57 = F_24 ( V_2 ) ;
struct F_1 * V_7 = F_2 ( V_4 ) ;
struct V_35 V_58 = {
. V_44 = V_7 -> V_59 ,
. V_60 = V_7 -> V_61 - V_56 ,
. V_62 = V_7 -> V_63 - V_29 ,
. V_8 = V_7 -> V_13 ,
. V_45 = V_7 -> V_14 ,
} ;
struct V_64 V_65 ;
if ( F_25 ( V_2 , V_43 , sizeof( V_58 ) , & V_58 ) )
goto V_66;
if ( V_7 -> V_14 == V_17 &&
( F_26 ( V_2 , V_46 , V_7 -> V_19 ) ||
F_27 ( V_2 , V_49 ,
V_7 -> V_18 ) ) )
goto V_66;
F_28 ( & V_65 , & V_7 -> V_11 ) ;
if ( F_29 ( V_2 , V_67 , sizeof( V_65 ) , & V_65 , V_68 ) )
goto V_66;
return V_2 -> V_69 ;
V_66:
F_30 ( V_2 , V_57 ) ;
return - 1 ;
}
static int F_31 ( struct V_24 * V_24 , struct V_1 * V_2 ,
struct V_70 * V_71 , int type ,
const struct V_72 * V_73 )
{
struct V_30 * V_31 = F_11 ( V_24 , V_32 ) ;
return F_32 ( V_31 , V_2 , V_71 , type , V_73 ) ;
}
static int F_33 ( struct V_24 * V_24 , struct V_3 * * V_4 , T_2 V_44 )
{
struct V_30 * V_31 = F_11 ( V_24 , V_32 ) ;
return F_34 ( V_31 , V_4 , V_44 ) ;
}
static T_3 int F_35 ( struct V_24 * V_24 )
{
struct V_30 * V_31 = F_11 ( V_24 , V_32 ) ;
return F_36 ( V_31 , & V_53 , V_74 ) ;
}
static void T_4 F_37 ( struct V_24 * V_24 )
{
struct V_30 * V_31 = F_11 ( V_24 , V_32 ) ;
F_38 ( V_31 ) ;
}
static int T_5 F_39 ( void )
{
return F_40 ( & V_53 , & V_75 ) ;
}
static void T_6 F_41 ( void )
{
F_42 ( & V_53 , & V_75 ) ;
}
