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
break;
case V_24 :
V_15 = F_9 ( & V_13 -> V_20 -> V_21 -> V_2 ) ;
if ( V_15 < 0 )
return V_15 ;
args -> V_22 = F_10 ( V_25 ) ;
F_11 ( & V_13 -> V_20 -> V_21 -> V_2 ) ;
break;
case V_26 :
V_15 = F_9 ( & V_13 -> V_20 -> V_21 -> V_2 ) ;
if ( V_15 < 0 )
return V_15 ;
args -> V_22 = F_10 ( V_27 ) ;
F_11 ( & V_13 -> V_20 -> V_21 -> V_2 ) ;
break;
case V_28 :
args -> V_22 = true ;
break;
default:
F_12 ( L_2 , args -> V_18 ) ;
return - V_17 ;
}
return 0 ;
}
static void F_13 ( struct V_8 * V_2 )
{
struct V_12 * V_13 = F_8 ( V_2 ) ;
F_14 ( V_13 -> V_29 ) ;
}
static int F_15 ( struct V_30 * V_2 , void * V_9 )
{
return V_2 == V_9 ;
}
static void F_16 ( struct V_30 * V_2 ,
struct V_31 * * V_32 ,
struct V_33 * const * V_34 ,
int V_35 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < V_35 ; V_36 ++ ) {
struct V_37 * V_38 = & V_34 [ V_36 ] -> V_39 ;
struct V_30 * V_40 = NULL , * V_41 ;
while ( ( V_41 = F_17 ( & V_42 , V_40 , V_38 ,
( void * ) V_42 . V_32 ) ) ) {
F_18 ( V_40 ) ;
F_19 ( V_2 , V_32 , F_15 , V_41 ) ;
V_40 = V_41 ;
}
F_18 ( V_40 ) ;
}
}
static void F_20 ( void )
{
struct V_43 * V_44 ;
V_44 = F_21 ( 1 ) ;
if ( ! V_44 )
return;
V_44 -> V_45 [ 0 ] . V_46 = 0 ;
V_44 -> V_45 [ 0 ] . V_47 = ~ 0 ;
F_22 ( V_44 , L_3 , false ) ;
F_23 ( V_44 ) ;
}
static int F_24 ( struct V_30 * V_2 )
{
struct V_1 * V_21 = F_25 ( V_2 ) ;
struct V_8 * V_48 ;
struct V_12 * V_13 ;
int V_15 = 0 ;
V_2 -> V_49 = F_26 ( 32 ) ;
V_13 = F_27 ( V_2 , sizeof( * V_13 ) , V_50 ) ;
if ( ! V_13 )
return - V_51 ;
V_48 = F_28 ( & V_52 , V_2 ) ;
if ( ! V_48 )
return - V_51 ;
F_29 ( V_21 , V_48 ) ;
V_13 -> V_2 = V_48 ;
V_48 -> V_53 = V_13 ;
F_30 ( V_48 ) ;
F_31 ( V_48 ) ;
F_32 ( V_48 ) ;
V_15 = F_33 ( V_2 , V_48 ) ;
if ( V_15 )
goto V_54;
F_20 () ;
V_15 = F_34 ( V_48 , 0 ) ;
if ( V_15 < 0 )
goto V_55;
F_35 ( V_48 ) ;
return 0 ;
V_55:
F_36 ( V_2 , V_48 ) ;
V_54:
F_37 ( V_48 ) ;
F_38 ( V_48 ) ;
F_39 ( V_48 ) ;
return V_15 ;
}
static void F_40 ( struct V_30 * V_2 )
{
struct V_1 * V_21 = F_25 ( V_2 ) ;
struct V_8 * V_48 = F_41 ( V_21 ) ;
struct V_12 * V_13 = F_8 ( V_48 ) ;
if ( V_13 -> V_29 )
F_42 ( V_13 -> V_29 ) ;
F_43 ( V_48 ) ;
F_44 ( V_48 ) ;
}
static int F_45 ( struct V_1 * V_21 )
{
struct V_31 * V_32 = NULL ;
struct V_30 * V_2 = & V_21 -> V_2 ;
F_16 ( V_2 , & V_32 ,
V_56 , F_46 ( V_56 ) ) ;
return F_47 ( V_2 , & V_57 , V_32 ) ;
}
static int F_48 ( struct V_1 * V_21 )
{
F_49 ( & V_21 -> V_2 , & V_57 ) ;
return 0 ;
}
static int T_2 F_50 ( void )
{
int V_36 , V_15 ;
for ( V_36 = 0 ; V_36 < F_46 ( V_56 ) ; V_36 ++ ) {
V_15 = F_51 ( V_56 [ V_36 ] ) ;
if ( V_15 ) {
while ( -- V_36 >= 0 )
F_52 ( V_56 [ V_36 ] ) ;
return V_15 ;
}
}
return F_51 ( & V_58 ) ;
}
static void T_3 F_53 ( void )
{
int V_36 ;
for ( V_36 = F_46 ( V_56 ) - 1 ; V_36 >= 0 ; V_36 -- )
F_52 ( V_56 [ V_36 ] ) ;
F_52 ( & V_58 ) ;
}
