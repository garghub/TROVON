static void F_1 ( struct V_1 * V_1 , T_1 V_2 ,
unsigned int V_3 ,
const struct V_4 * V_5 ,
const struct V_6 * V_7 ,
const struct V_6 * V_8 ,
const struct V_9 * V_10 ,
const char * V_11 )
{
switch ( F_2 ( V_5 ) -> V_12 ) {
case F_3 ( V_13 ) :
F_4 ( V_1 , V_14 , V_3 , V_5 , V_7 , V_8 ,
V_10 , L_1 , V_11 ) ;
break;
case F_3 ( V_15 ) :
F_4 ( V_1 , V_16 , V_3 , V_5 , V_7 , V_8 ,
V_10 , L_1 , V_11 ) ;
break;
case F_3 ( V_17 ) :
case F_3 ( V_18 ) :
F_4 ( V_1 , V_19 , V_3 , V_5 , V_7 , V_8 ,
V_10 , L_1 , V_11 ) ;
break;
}
}
static int T_2 F_5 ( struct V_1 * V_1 )
{
return F_6 ( V_1 , V_20 , & V_21 ) ;
}
static void T_3 F_7 ( struct V_1 * V_1 )
{
F_8 ( V_1 , & V_21 ) ;
}
static int T_4 F_9 ( void )
{
int V_22 ;
F_10 ( V_14 , V_23 ) ;
F_10 ( V_16 , V_23 ) ;
F_10 ( V_19 , V_23 ) ;
V_22 = F_11 ( & V_24 ) ;
if ( V_22 < 0 )
return V_22 ;
F_12 ( V_20 , & V_21 ) ;
return 0 ;
}
static void T_5 F_13 ( void )
{
F_14 ( & V_24 ) ;
F_15 ( & V_21 ) ;
}
