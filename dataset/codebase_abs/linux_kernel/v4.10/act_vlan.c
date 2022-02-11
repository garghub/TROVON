static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct F_1 * V_7 = F_2 ( V_4 ) ;
int V_8 ;
int V_9 ;
T_1 V_10 ;
F_3 ( & V_7 -> V_11 ) ;
F_4 ( & V_7 -> V_12 ) ;
F_5 ( & V_7 -> V_13 , V_2 ) ;
V_8 = V_7 -> V_14 ;
if ( F_6 ( V_2 ) )
F_7 ( V_2 , V_2 -> V_15 ) ;
switch ( V_7 -> V_16 ) {
case V_17 :
V_9 = F_8 ( V_2 ) ;
if ( V_9 )
goto V_18;
break;
case V_19 :
V_9 = F_9 ( V_2 , V_7 -> V_20 , V_7 -> V_21 |
( V_7 -> V_22 << V_23 ) ) ;
if ( V_9 )
goto V_18;
break;
case V_24 :
if ( ! F_10 ( V_2 ) )
goto V_25;
if ( F_11 ( V_2 ) ) {
V_10 = F_12 ( V_2 ) ;
V_2 -> V_26 = 0 ;
} else {
V_9 = F_13 ( V_2 , & V_10 ) ;
if ( V_9 )
goto V_18;
}
V_10 = ( V_10 & ~ V_27 ) | V_7 -> V_21 ;
if ( V_7 -> V_22 ) {
V_10 &= ~ V_28 ;
V_10 |= V_7 -> V_22 << V_23 ;
}
F_14 ( V_2 , V_7 -> V_20 , V_10 ) ;
break;
default:
F_15 () ;
}
goto V_25;
V_18:
V_8 = V_29 ;
V_7 -> V_30 . V_31 ++ ;
V_25:
if ( F_6 ( V_2 ) )
F_16 ( V_2 , V_2 -> V_15 ) ;
F_17 ( & V_7 -> V_11 ) ;
return V_8 ;
}
static int F_18 ( struct V_32 * V_32 , struct V_33 * V_34 ,
struct V_33 * V_35 , struct V_3 * * V_4 ,
int V_36 , int V_37 )
{
struct V_38 * V_39 = F_19 ( V_32 , V_40 ) ;
struct V_33 * V_41 [ V_42 + 1 ] ;
struct V_43 * V_44 ;
struct F_1 * V_7 ;
int V_8 ;
T_2 V_45 = 0 ;
T_2 V_46 = 0 ;
T_3 V_47 = 0 ;
bool V_48 = false ;
int V_49 = 0 , V_9 ;
if ( ! V_34 )
return - V_50 ;
V_9 = F_20 ( V_41 , V_42 , V_34 , V_51 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( ! V_41 [ V_52 ] )
return - V_50 ;
V_44 = F_21 ( V_41 [ V_52 ] ) ;
V_48 = F_22 ( V_39 , V_44 -> V_53 , V_4 , V_37 ) ;
if ( V_48 && V_37 )
return 0 ;
switch ( V_44 -> V_54 ) {
case V_17 :
break;
case V_19 :
case V_24 :
if ( ! V_41 [ V_55 ] ) {
if ( V_48 )
F_23 ( * V_4 , V_37 ) ;
return - V_50 ;
}
V_45 = F_24 ( V_41 [ V_55 ] ) ;
if ( V_45 >= V_27 ) {
if ( V_48 )
F_23 ( * V_4 , V_37 ) ;
return - V_56 ;
}
if ( V_41 [ V_57 ] ) {
V_46 = F_25 ( V_41 [ V_57 ] ) ;
switch ( V_46 ) {
case F_26 ( V_58 ) :
case F_26 ( V_59 ) :
break;
default:
return - V_60 ;
}
} else {
V_46 = F_26 ( V_58 ) ;
}
if ( V_41 [ V_61 ] )
V_47 = F_27 ( V_41 [ V_61 ] ) ;
break;
default:
if ( V_48 )
F_23 ( * V_4 , V_37 ) ;
return - V_50 ;
}
V_8 = V_44 -> V_54 ;
if ( ! V_48 ) {
V_49 = F_28 ( V_39 , V_44 -> V_53 , V_35 , V_4 ,
& V_62 , V_37 , false ) ;
if ( V_49 )
return V_49 ;
V_49 = V_63 ;
} else {
F_23 ( * V_4 , V_37 ) ;
if ( ! V_36 )
return - V_64 ;
}
V_7 = F_2 ( * V_4 ) ;
F_29 ( & V_7 -> V_11 ) ;
V_7 -> V_16 = V_8 ;
V_7 -> V_21 = V_45 ;
V_7 -> V_22 = V_47 ;
V_7 -> V_20 = V_46 ;
V_7 -> V_14 = V_44 -> V_8 ;
F_30 ( & V_7 -> V_11 ) ;
if ( V_49 == V_63 )
F_31 ( V_39 , * V_4 ) ;
return V_49 ;
}
static int F_32 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_37 , int V_65 )
{
unsigned char * V_66 = F_33 ( V_2 ) ;
struct F_1 * V_7 = F_2 ( V_4 ) ;
struct V_43 V_67 = {
. V_53 = V_7 -> V_68 ,
. V_69 = V_7 -> V_70 - V_65 ,
. V_71 = V_7 -> V_72 - V_37 ,
. V_8 = V_7 -> V_14 ,
. V_54 = V_7 -> V_16 ,
} ;
struct V_73 V_74 ;
if ( F_34 ( V_2 , V_52 , sizeof( V_67 ) , & V_67 ) )
goto V_75;
if ( ( V_7 -> V_16 == V_19 ||
V_7 -> V_16 == V_24 ) &&
( F_35 ( V_2 , V_55 , V_7 -> V_21 ) ||
F_36 ( V_2 , V_57 ,
V_7 -> V_20 ) ||
( F_37 ( V_2 , V_61 ,
V_7 -> V_22 ) ) ) )
goto V_75;
F_38 ( & V_74 , & V_7 -> V_12 ) ;
if ( F_39 ( V_2 , V_76 , sizeof( V_74 ) , & V_74 , V_77 ) )
goto V_75;
return V_2 -> V_78 ;
V_75:
F_40 ( V_2 , V_66 ) ;
return - 1 ;
}
static int F_41 ( struct V_32 * V_32 , struct V_1 * V_2 ,
struct V_79 * V_80 , int type ,
const struct V_81 * V_82 )
{
struct V_38 * V_39 = F_19 ( V_32 , V_40 ) ;
return F_42 ( V_39 , V_2 , V_80 , type , V_82 ) ;
}
static int F_43 ( struct V_32 * V_32 , struct V_3 * * V_4 , T_4 V_53 )
{
struct V_38 * V_39 = F_19 ( V_32 , V_40 ) ;
return F_44 ( V_39 , V_4 , V_53 ) ;
}
static T_5 int F_45 ( struct V_32 * V_32 )
{
struct V_38 * V_39 = F_19 ( V_32 , V_40 ) ;
return F_46 ( V_39 , & V_62 , V_83 ) ;
}
static void T_6 F_47 ( struct V_32 * V_32 )
{
struct V_38 * V_39 = F_19 ( V_32 , V_40 ) ;
F_48 ( V_39 ) ;
}
static int T_7 F_49 ( void )
{
return F_50 ( & V_62 , & V_84 ) ;
}
static void T_8 F_51 ( void )
{
F_52 ( & V_62 , & V_84 ) ;
}
