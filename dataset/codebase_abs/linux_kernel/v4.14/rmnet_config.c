static int F_1 ( const struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 ) == V_4 ;
}
static struct V_5 *
F_3 ( const struct V_1 * V_2 )
{
return F_4 ( V_2 -> V_6 ) ;
}
static struct V_7 *
F_5 ( struct V_1 * V_8 , int V_9 )
{
struct V_7 * V_10 ;
struct V_5 * V_11 ;
if ( ! F_1 ( V_8 ) ) {
V_10 = F_6 ( V_8 ) ;
} else {
V_11 = F_3 ( V_8 ) ;
V_10 = & V_11 -> V_12 [ V_9 ] ;
}
return V_10 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_5 * V_11 )
{
if ( V_11 -> V_13 )
return - V_14 ;
F_8 ( V_11 ) ;
F_9 ( V_2 ) ;
F_10 ( V_2 ) ;
F_11 ( V_2 , L_1 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_11 ;
int V_15 ;
F_13 () ;
if ( F_1 ( V_2 ) )
return 0 ;
V_11 = F_14 ( sizeof( * V_11 ) , V_16 ) ;
if ( ! V_11 )
return - V_17 ;
V_11 -> V_8 = V_2 ;
V_15 = F_15 ( V_2 , V_4 , V_11 ) ;
if ( V_15 ) {
F_8 ( V_11 ) ;
return - V_18 ;
}
F_16 ( V_2 ) ;
F_11 ( V_2 , L_2 ) ;
return 0 ;
}
static void F_17 ( struct V_1 * V_8 ,
T_1 V_19 , T_1 V_20 ,
struct V_1 * V_21 )
{
struct V_7 * V_10 ;
F_11 ( V_8 , L_3 ,
V_19 , V_20 , V_21 -> V_22 ) ;
V_10 = F_5 ( V_8 , V_19 ) ;
memset ( V_10 , 0 , sizeof( struct V_7 ) ) ;
V_10 -> V_20 = V_20 ;
V_10 -> V_21 = V_21 ;
V_10 -> V_19 = V_19 ;
}
static int F_18 ( struct V_23 * V_24 , struct V_1 * V_8 ,
struct V_25 * V_26 [] , struct V_25 * V_27 [] ,
struct V_28 * V_29 )
{
int V_30 = V_31 |
V_32 |
V_33 ;
int V_34 = V_35 |
V_36 ;
struct V_1 * V_2 ;
int V_37 = V_38 ;
struct V_5 * V_11 ;
int V_39 = 0 ;
T_2 V_19 ;
V_2 = F_19 ( V_24 , F_20 ( V_26 [ V_40 ] ) ) ;
if ( ! V_2 || ! V_8 )
return - V_41 ;
if ( ! V_27 [ V_42 ] )
return - V_14 ;
V_19 = F_21 ( V_27 [ V_42 ] ) ;
V_39 = F_12 ( V_2 ) ;
if ( V_39 )
goto V_43;
V_11 = F_3 ( V_2 ) ;
V_39 = F_22 ( V_19 , V_8 , V_11 , V_2 ) ;
if ( V_39 )
goto V_44;
V_39 = F_23 ( V_8 , V_2 , NULL , NULL ) ;
if ( V_39 )
goto V_45;
F_11 ( V_8 , L_4 ,
V_30 , V_34 ) ;
V_11 -> V_46 = V_34 ;
V_11 -> V_47 = V_30 ;
F_17 ( V_2 , V_19 , V_37 , V_8 ) ;
F_17 ( V_8 , V_19 , V_37 , V_2 ) ;
return 0 ;
V_45:
F_24 ( V_19 , V_11 ) ;
V_44:
F_7 ( V_2 , V_11 ) ;
V_43:
return V_39 ;
}
static void F_25 ( struct V_1 * V_8 , struct V_48 * V_49 )
{
struct V_1 * V_2 ;
struct V_5 * V_11 ;
T_1 V_19 ;
F_26 () ;
V_2 = F_27 ( V_8 ) ;
F_28 () ;
if ( ! V_2 || ! F_1 ( V_2 ) )
return;
V_11 = F_3 ( V_2 ) ;
V_19 = F_29 ( V_8 ) ;
F_24 ( V_19 , V_11 ) ;
F_30 ( V_8 , V_2 ) ;
F_7 ( V_2 , V_11 ) ;
F_31 ( V_8 , V_49 ) ;
}
static int F_32 ( struct V_1 * V_50 , void * V_27 )
{
struct V_51 * V_52 = V_27 ;
T_1 V_19 ;
V_19 = F_29 ( V_50 ) ;
F_24 ( V_19 , V_52 -> V_11 ) ;
F_30 ( V_50 , V_52 -> V_2 ) ;
F_31 ( V_50 , V_52 -> V_49 ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_8 )
{
struct V_1 * V_2 = V_8 ;
struct V_51 V_52 ;
struct V_5 * V_11 ;
F_34 ( V_53 ) ;
if ( ! F_1 ( V_2 ) )
return;
F_13 () ;
V_52 . V_2 = V_2 ;
V_52 . V_49 = & V_53 ;
V_11 = F_3 ( V_8 ) ;
V_52 . V_11 = V_11 ;
F_26 () ;
F_35 ( V_2 , F_32 , & V_52 ) ;
F_28 () ;
F_36 ( & V_53 ) ;
F_7 ( V_2 , V_11 ) ;
}
static int F_37 ( struct V_54 * V_55 ,
unsigned long V_56 , void * V_27 )
{
struct V_1 * V_8 = F_38 ( V_27 ) ;
if ( ! V_8 )
return V_57 ;
switch ( V_56 ) {
case V_58 :
F_11 ( V_8 , L_5 ) ;
F_33 ( V_8 ) ;
break;
default:
break;
}
return V_57 ;
}
static int F_39 ( struct V_25 * V_26 [] , struct V_25 * V_27 [] ,
struct V_28 * V_29 )
{
T_2 V_19 ;
if ( ! V_27 || ! V_27 [ V_42 ] )
return - V_14 ;
V_19 = F_21 ( V_27 [ V_42 ] ) ;
if ( V_19 > ( V_59 - 1 ) )
return - V_60 ;
return 0 ;
}
static T_3 F_40 ( const struct V_1 * V_8 )
{
return F_41 ( 2 ) ;
}
struct V_5 * F_42 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) )
return F_43 ( V_2 -> V_6 ) ;
else
return NULL ;
}
static int T_4 F_44 ( void )
{
int V_15 ;
V_15 = F_45 ( & V_61 ) ;
if ( V_15 != 0 )
return V_15 ;
V_15 = F_46 ( & V_62 ) ;
if ( V_15 != 0 ) {
F_47 ( & V_61 ) ;
return V_15 ;
}
return V_15 ;
}
static void T_5 F_48 ( void )
{
F_47 ( & V_61 ) ;
F_49 ( & V_62 ) ;
}
