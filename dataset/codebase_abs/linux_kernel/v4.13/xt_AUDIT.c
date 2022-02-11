static bool F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 V_6 ;
const struct V_5 * V_7 ;
V_7 = F_2 ( V_4 , F_3 ( V_4 ) , sizeof( V_6 ) , & V_6 ) ;
if ( ! V_7 )
return false ;
F_4 ( V_2 , L_1 ,
& V_7 -> V_8 , & V_7 -> V_9 , V_7 -> V_10 ) ;
return true ;
}
static bool F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_11 V_12 ;
const struct V_11 * V_7 ;
T_1 V_13 ;
T_2 V_14 ;
V_7 = F_2 ( V_4 , F_3 ( V_4 ) , sizeof( V_12 ) , & V_12 ) ;
if ( ! V_7 )
return false ;
V_13 = V_7 -> V_13 ;
F_6 ( V_4 , F_3 ( V_4 ) + sizeof( V_12 ) , & V_13 , & V_14 ) ;
F_4 ( V_2 , L_2 ,
& V_7 -> V_8 , & V_7 -> V_9 , V_13 ) ;
return true ;
}
static unsigned int
F_7 ( struct V_3 * V_4 , const struct V_15 * V_16 )
{
struct V_1 * V_2 ;
int V_17 = - 1 ;
if ( V_18 == 0 )
goto V_19;
V_2 = F_8 ( NULL , V_20 , V_21 ) ;
if ( V_2 == NULL )
goto V_19;
F_4 ( V_2 , L_3 , V_4 -> V_22 ) ;
switch ( F_9 ( V_16 ) ) {
case V_23 :
switch ( F_10 ( V_4 ) -> V_24 ) {
case F_11 ( V_25 ) :
V_17 = F_1 ( V_2 , V_4 ) ? V_26 : - 1 ;
break;
case F_11 ( V_27 ) :
V_17 = F_5 ( V_2 , V_4 ) ? V_28 : - 1 ;
break;
}
break;
case V_26 :
V_17 = F_1 ( V_2 , V_4 ) ? V_26 : - 1 ;
break;
case V_28 :
V_17 = F_5 ( V_2 , V_4 ) ? V_28 : - 1 ;
break;
}
if ( V_17 == - 1 )
F_4 ( V_2 , L_4 ) ;
F_12 ( V_2 ) ;
V_19:
return V_29 ;
}
static unsigned int
F_13 ( struct V_3 * V_4 , const struct V_15 * V_16 )
{
F_7 ( V_4 , V_16 ) ;
return V_30 ;
}
static int F_14 ( const struct V_31 * V_16 )
{
const struct V_32 * V_33 = V_16 -> V_34 ;
if ( V_33 -> type > V_35 ) {
F_15 ( L_5 ,
V_35 ) ;
return - V_36 ;
}
return 0 ;
}
static int T_3 F_16 ( void )
{
return F_17 ( V_37 , F_18 ( V_37 ) ) ;
}
static void T_4 F_19 ( void )
{
F_20 ( V_37 , F_18 ( V_37 ) ) ;
}
