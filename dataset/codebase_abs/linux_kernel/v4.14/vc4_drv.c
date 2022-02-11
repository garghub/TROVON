void T_1 * F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 ;
void T_1 * V_6 ;
V_5 = F_2 ( V_2 , V_7 , V_3 ) ;
V_6 = F_3 ( & V_2 -> V_2 , V_5 ) ;
if ( F_4 ( V_6 ) ) {
F_5 ( L_1 , F_6 ( V_6 ) ) ;
return V_6 ;
}
return V_6 ;
}
static int F_7 ( struct V_8 * V_2 , void * V_9 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = F_8 ( V_2 ) ;
struct V_14 * args = V_9 ;
int V_15 ;
if ( args -> V_16 != 0 )
return - V_17 ;
switch ( args -> V_18 ) {
case V_19 :
V_15 = F_9 ( & V_13 -> V_20 -> V_21 -> V_2 ) ;
if ( V_15 < 0 )
return V_15 ;
args -> V_22 = F_10 ( V_23 ) ;
F_11 ( & V_13 -> V_20 -> V_21 -> V_2 ) ;
F_12 ( & V_13 -> V_20 -> V_21 -> V_2 ) ;
break;
case V_24 :
V_15 = F_9 ( & V_13 -> V_20 -> V_21 -> V_2 ) ;
if ( V_15 < 0 )
return V_15 ;
args -> V_22 = F_10 ( V_25 ) ;
F_11 ( & V_13 -> V_20 -> V_21 -> V_2 ) ;
F_12 ( & V_13 -> V_20 -> V_21 -> V_2 ) ;
break;
case V_26 :
V_15 = F_9 ( & V_13 -> V_20 -> V_21 -> V_2 ) ;
if ( V_15 < 0 )
return V_15 ;
args -> V_22 = F_10 ( V_27 ) ;
F_11 ( & V_13 -> V_20 -> V_21 -> V_2 ) ;
F_12 ( & V_13 -> V_20 -> V_21 -> V_2 ) ;
break;
case V_28 :
case V_29 :
case V_30 :
case V_31 :
args -> V_22 = true ;
break;
default:
F_13 ( L_2 , args -> V_18 ) ;
return - V_17 ;
}
return 0 ;
}
static void F_14 ( struct V_8 * V_2 )
{
struct V_12 * V_13 = F_8 ( V_2 ) ;
F_15 ( V_13 -> V_32 ) ;
}
static int F_16 ( struct V_33 * V_2 , void * V_9 )
{
return V_2 == V_9 ;
}
static void F_17 ( struct V_33 * V_2 ,
struct V_34 * * V_35 ,
struct V_36 * const * V_37 ,
int V_38 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_38 ; V_39 ++ ) {
struct V_40 * V_41 = & V_37 [ V_39 ] -> V_42 ;
struct V_33 * V_43 = NULL , * V_44 ;
while ( ( V_44 = F_18 ( & V_45 , V_43 , V_41 ,
( void * ) V_45 . V_35 ) ) ) {
F_19 ( V_43 ) ;
F_20 ( V_2 , V_35 , F_16 , V_44 ) ;
V_43 = V_44 ;
}
F_19 ( V_43 ) ;
}
}
static void F_21 ( void )
{
struct V_46 * V_47 ;
V_47 = F_22 ( 1 ) ;
if ( ! V_47 )
return;
V_47 -> V_48 [ 0 ] . V_49 = 0 ;
V_47 -> V_48 [ 0 ] . V_50 = ~ 0 ;
F_23 ( V_47 , L_3 , false ) ;
F_24 ( V_47 ) ;
}
static int F_25 ( struct V_33 * V_2 )
{
struct V_1 * V_21 = F_26 ( V_2 ) ;
struct V_8 * V_51 ;
struct V_12 * V_13 ;
int V_15 = 0 ;
V_2 -> V_52 = F_27 ( 32 ) ;
V_13 = F_28 ( V_2 , sizeof( * V_13 ) , V_53 ) ;
if ( ! V_13 )
return - V_54 ;
V_51 = F_29 ( & V_55 , V_2 ) ;
if ( F_4 ( V_51 ) )
return F_6 ( V_51 ) ;
F_30 ( V_21 , V_51 ) ;
V_13 -> V_2 = V_51 ;
V_51 -> V_56 = V_13 ;
V_15 = F_31 ( V_51 ) ;
if ( V_15 )
goto V_57;
F_32 ( V_51 ) ;
F_33 ( V_51 ) ;
V_15 = F_34 ( V_2 , V_51 ) ;
if ( V_15 )
goto V_58;
F_21 () ;
V_15 = F_35 ( V_51 , 0 ) ;
if ( V_15 < 0 )
goto V_59;
F_36 ( V_51 ) ;
return 0 ;
V_59:
F_37 ( V_2 , V_51 ) ;
V_58:
F_38 ( V_51 ) ;
F_39 ( V_51 ) ;
V_57:
F_40 ( V_51 ) ;
return V_15 ;
}
static void F_41 ( struct V_33 * V_2 )
{
struct V_1 * V_21 = F_26 ( V_2 ) ;
struct V_8 * V_51 = F_42 ( V_21 ) ;
struct V_12 * V_13 = F_8 ( V_51 ) ;
F_43 ( V_51 ) ;
if ( V_13 -> V_32 )
F_44 ( V_13 -> V_32 ) ;
F_45 ( V_51 ) ;
F_40 ( V_51 ) ;
}
static int F_46 ( struct V_1 * V_21 )
{
struct V_34 * V_35 = NULL ;
struct V_33 * V_2 = & V_21 -> V_2 ;
F_17 ( V_2 , & V_35 ,
V_60 , F_47 ( V_60 ) ) ;
return F_48 ( V_2 , & V_61 , V_35 ) ;
}
static int F_49 ( struct V_1 * V_21 )
{
F_50 ( & V_21 -> V_2 , & V_61 ) ;
return 0 ;
}
static int T_2 F_51 ( void )
{
int V_15 ;
V_15 = F_52 ( V_60 ,
F_47 ( V_60 ) ) ;
if ( V_15 )
return V_15 ;
return F_53 ( & V_62 ) ;
}
static void T_3 F_54 ( void )
{
F_55 ( V_60 ,
F_47 ( V_60 ) ) ;
F_56 ( & V_62 ) ;
}
