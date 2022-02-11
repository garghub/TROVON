static void F_1 ( struct V_1 * V_1 , T_1 V_2 ,
unsigned int V_3 ,
const struct V_4 * V_5 ,
const struct V_6 * V_7 ,
const struct V_6 * V_8 ,
const struct V_9 * V_10 ,
const char * V_11 )
{
F_2 ( V_1 , V_2 , V_5 -> V_12 , V_3 , V_5 , V_7 , V_8 ,
V_10 , V_11 ) ;
}
static int T_2 F_3 ( struct V_1 * V_1 )
{
return F_4 ( V_1 , V_13 , & V_14 ) ;
}
static void T_3 F_5 ( struct V_1 * V_1 )
{
F_6 ( V_1 , & V_14 ) ;
}
static int T_4 F_7 ( void )
{
int V_15 ;
F_8 ( V_16 , V_17 ) ;
F_8 ( V_18 , V_17 ) ;
F_8 ( V_19 , V_17 ) ;
V_15 = F_9 ( & V_20 ) ;
if ( V_15 < 0 )
return V_15 ;
F_10 ( V_13 , & V_14 ) ;
return 0 ;
}
static void T_5 F_11 ( void )
{
F_12 ( & V_20 ) ;
F_13 ( & V_14 ) ;
}
