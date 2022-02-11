static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
F_2 () ;
V_5 = F_3 ( V_2 , V_4 ) ;
if ( V_5 )
GOTO ( V_6 , V_5 ) ;
V_2 -> V_7 . V_8 . V_9 . V_10 = V_11 ;
V_5 = F_4 ( V_2 , & V_2 -> V_12 , V_2 , NULL ) ;
if ( V_5 ) {
F_5 ( L_1 ) ;
GOTO ( V_13 , V_5 ) ;
}
return V_5 ;
V_13:
F_6 ( V_2 ) ;
V_6:
F_7 () ;
return V_5 ;
}
static int F_8 ( struct V_1 * V_2 , enum V_14 V_15 )
{
int V_5 = 0 ;
switch ( V_15 ) {
case V_16 :
case V_17 :
F_9 ( V_2 ) ;
V_5 = F_10 ( V_2 , 0 ) ;
if ( V_5 != 0 )
F_5 ( L_2 ) ;
break;
}
return V_5 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_18 * V_8 = & V_2 -> V_7 . V_8 ;
int V_5 ;
F_12 ( V_8 -> V_19 == NULL ) ;
F_7 () ;
V_5 = F_6 ( V_2 ) ;
return V_5 ;
}
static int F_13 ( struct V_1 * V_2 , struct V_20 * V_21 ,
struct V_1 * V_22 , int * V_23 )
{
struct V_24 * V_25 ;
int V_5 ;
F_12 ( V_21 == & V_2 -> V_12 ) ;
V_5 = F_14 ( NULL , V_2 , V_21 , V_26 , V_22 ,
& V_27 ) ;
if ( V_5 < 0 )
return V_5 ;
V_25 = F_15 ( V_21 , V_26 ) ;
F_16 ( V_25 ) ;
F_17 ( V_25 ) ;
return V_5 ;
}
static int F_18 ( struct V_1 * V_2 , int V_28 )
{
struct V_24 * V_25 ;
V_25 = F_19 ( V_2 , V_26 ) ;
if ( V_25 )
F_20 ( NULL , V_25 ) ;
return 0 ;
}
int T_1 F_21 ( void )
{
return F_22 ( & V_29 , NULL ,
NULL , V_30 , NULL ) ;
}
