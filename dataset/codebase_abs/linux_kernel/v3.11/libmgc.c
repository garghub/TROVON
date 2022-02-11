static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
V_6 ;
F_2 () ;
V_5 = F_3 ( V_2 , V_4 ) ;
if ( V_5 )
GOTO ( V_7 , V_5 ) ;
V_2 -> V_8 . V_9 . V_10 . V_11 = V_12 ;
V_5 = F_4 ( V_2 , & V_2 -> V_13 , V_2 , NULL ) ;
if ( V_5 ) {
F_5 ( L_1 ) ;
GOTO ( V_14 , V_5 ) ;
}
RETURN ( V_5 ) ;
V_14:
F_6 ( V_2 ) ;
V_7:
F_7 () ;
RETURN ( V_5 ) ;
}
static int F_8 ( struct V_1 * V_2 , enum V_15 V_16 )
{
int V_5 = 0 ;
V_6 ;
switch ( V_16 ) {
case V_17 :
case V_18 :
F_9 ( V_2 ) ;
V_5 = F_10 ( V_2 , 0 ) ;
if ( V_5 != 0 )
F_5 ( L_2 ) ;
break;
}
RETURN ( V_5 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_19 * V_9 = & V_2 -> V_8 . V_9 ;
int V_5 ;
V_6 ;
F_12 ( V_9 -> V_20 == NULL ) ;
F_7 () ;
V_5 = F_6 ( V_2 ) ;
RETURN ( V_5 ) ;
}
static int F_13 ( struct V_1 * V_2 , struct V_21 * V_22 ,
struct V_1 * V_23 , int * V_24 )
{
struct V_25 * V_26 ;
int V_5 ;
V_6 ;
F_12 ( V_22 == & V_2 -> V_13 ) ;
V_5 = F_14 ( NULL , V_2 , V_22 , V_27 , V_23 ,
& V_28 ) ;
if ( V_5 < 0 )
RETURN ( V_5 ) ;
V_26 = F_15 ( V_22 , V_27 ) ;
F_16 ( V_26 ) ;
F_17 ( V_26 ) ;
RETURN ( V_5 ) ;
}
static int F_18 ( struct V_1 * V_2 , int V_29 )
{
struct V_25 * V_26 ;
V_6 ;
V_26 = F_19 ( V_2 , V_27 ) ;
if ( V_26 )
F_20 ( NULL , V_26 ) ;
RETURN ( 0 ) ;
}
int T_1 F_21 ( void )
{
return F_22 ( & V_30 , NULL ,
NULL , V_31 , NULL ) ;
}
