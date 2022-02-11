static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
F_3 ( & V_8 -> V_9 ) ;
F_4 ( & V_8 -> V_10 ) ;
F_5 ( & V_8 -> V_11 , V_2 ) ;
F_6 ( L_1 ,
( char * ) V_8 -> V_12 , V_8 -> V_11 . V_13 ) ;
F_7 ( & V_8 -> V_9 ) ;
return V_8 -> V_14 ;
}
static void F_8 ( struct V_3 * V_4 , int V_15 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
F_9 ( V_8 -> V_12 ) ;
}
static int F_10 ( struct V_7 * V_8 , char * V_16 )
{
V_8 -> V_12 = F_11 ( V_17 , V_18 ) ;
if ( F_12 ( ! V_8 -> V_12 ) )
return - V_19 ;
F_13 ( V_8 -> V_12 , V_16 , V_17 ) ;
return 0 ;
}
static void F_14 ( struct V_7 * V_8 , char * V_16 ,
struct V_20 * V_21 )
{
F_15 ( & V_8 -> V_9 ) ;
V_8 -> V_14 = V_21 -> V_22 ;
memset ( V_8 -> V_12 , 0 , V_17 ) ;
F_13 ( V_8 -> V_12 , V_16 , V_17 ) ;
F_16 ( & V_8 -> V_9 ) ;
}
static int F_17 ( struct V_23 * V_23 , struct V_24 * V_25 ,
struct V_24 * V_26 , struct V_3 * * V_4 ,
int V_27 , int V_15 )
{
struct V_28 * V_29 = F_18 ( V_23 , V_30 ) ;
struct V_24 * V_31 [ V_32 + 1 ] ;
struct V_20 * V_33 ;
struct V_7 * V_8 ;
bool V_34 = false ;
int V_35 = 0 , V_36 ;
char * V_16 ;
if ( V_25 == NULL )
return - V_37 ;
V_36 = F_19 ( V_31 , V_32 , V_25 , V_38 , NULL ) ;
if ( V_36 < 0 )
return V_36 ;
if ( V_31 [ V_39 ] == NULL )
return - V_37 ;
V_33 = F_20 ( V_31 [ V_39 ] ) ;
V_34 = F_21 ( V_29 , V_33 -> V_40 , V_4 , V_15 ) ;
if ( V_34 && V_15 )
return 0 ;
if ( V_31 [ V_41 ] == NULL ) {
if ( V_34 )
F_22 ( * V_4 , V_15 ) ;
return - V_37 ;
}
V_16 = F_20 ( V_31 [ V_41 ] ) ;
if ( ! V_34 ) {
V_35 = F_23 ( V_29 , V_33 -> V_40 , V_26 , V_4 ,
& V_42 , V_15 , false ) ;
if ( V_35 )
return V_35 ;
V_8 = F_2 ( * V_4 ) ;
V_35 = F_10 ( V_8 , V_16 ) ;
if ( V_35 < 0 ) {
F_24 ( * V_4 , V_26 ) ;
return V_35 ;
}
V_8 -> V_14 = V_33 -> V_22 ;
V_35 = V_43 ;
} else {
V_8 = F_2 ( * V_4 ) ;
F_22 ( * V_4 , V_15 ) ;
if ( ! V_27 )
return - V_44 ;
F_14 ( V_8 , V_16 , V_33 ) ;
}
if ( V_35 == V_43 )
F_25 ( V_29 , * V_4 ) ;
return V_35 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_15 , int V_45 )
{
unsigned char * V_46 = F_27 ( V_2 ) ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_20 V_47 = {
. V_40 = V_8 -> V_48 ,
. V_49 = V_8 -> V_50 - V_45 ,
. V_51 = V_8 -> V_52 - V_15 ,
. V_22 = V_8 -> V_14 ,
} ;
struct V_53 V_54 ;
if ( F_28 ( V_2 , V_39 , sizeof( V_47 ) , & V_47 ) ||
F_29 ( V_2 , V_41 , V_8 -> V_12 ) )
goto V_55;
F_30 ( & V_54 , & V_8 -> V_10 ) ;
if ( F_31 ( V_2 , V_56 , sizeof( V_54 ) , & V_54 , V_57 ) )
goto V_55;
return V_2 -> V_58 ;
V_55:
F_32 ( V_2 , V_46 ) ;
return - 1 ;
}
static int F_33 ( struct V_23 * V_23 , struct V_1 * V_2 ,
struct V_59 * V_60 , int type ,
const struct V_61 * V_62 )
{
struct V_28 * V_29 = F_18 ( V_23 , V_30 ) ;
return F_34 ( V_29 , V_2 , V_60 , type , V_62 ) ;
}
static int F_35 ( struct V_23 * V_23 , struct V_3 * * V_4 , T_1 V_40 )
{
struct V_28 * V_29 = F_18 ( V_23 , V_30 ) ;
return F_36 ( V_29 , V_4 , V_40 ) ;
}
static T_2 int F_37 ( struct V_23 * V_23 )
{
struct V_28 * V_29 = F_18 ( V_23 , V_30 ) ;
return F_38 ( V_29 , & V_42 , V_63 ) ;
}
static void T_3 F_39 ( struct V_23 * V_23 )
{
struct V_28 * V_29 = F_18 ( V_23 , V_30 ) ;
F_40 ( V_29 ) ;
}
static int T_4 F_41 ( void )
{
int V_35 = F_42 ( & V_42 , & V_64 ) ;
if ( ! V_35 )
F_6 ( L_2 ) ;
return V_35 ;
}
static void T_5 F_43 ( void )
{
F_44 ( & V_42 , & V_64 ) ;
}
