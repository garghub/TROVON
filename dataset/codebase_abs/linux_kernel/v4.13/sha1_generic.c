static void F_1 ( struct V_1 * V_2 , T_1 const * V_3 ,
int V_4 )
{
T_2 V_5 [ V_6 ] ;
while ( V_4 -- ) {
F_2 ( V_2 -> V_7 , V_3 , V_5 ) ;
V_3 += V_8 ;
}
F_3 ( V_5 , sizeof( V_5 ) ) ;
}
int F_4 ( struct V_9 * V_10 , const T_1 * V_11 ,
unsigned int V_12 )
{
return F_5 ( V_10 , V_11 , V_12 , F_1 ) ;
}
static int F_6 ( struct V_9 * V_10 , T_1 * V_13 )
{
F_7 ( V_10 , F_1 ) ;
return F_8 ( V_10 , V_13 ) ;
}
int F_9 ( struct V_9 * V_10 , const T_1 * V_11 ,
unsigned int V_12 , T_1 * V_13 )
{
F_5 ( V_10 , V_11 , V_12 , F_1 ) ;
return F_6 ( V_10 , V_13 ) ;
}
static int T_3 F_10 ( void )
{
return F_11 ( & V_14 ) ;
}
static void T_4 F_12 ( void )
{
F_13 ( & V_14 ) ;
}
