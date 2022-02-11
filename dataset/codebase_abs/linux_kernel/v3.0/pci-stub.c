static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
F_2 ( V_5 , & V_2 -> V_2 , L_1 ) ;
return 0 ;
}
static int T_1 F_3 ( void )
{
char * V_6 , * V_4 ;
int V_7 ;
V_7 = F_4 ( & V_8 ) ;
if ( V_7 )
return V_7 ;
if ( V_9 [ 0 ] == '\0' )
return 0 ;
V_6 = V_9 ;
while ( ( V_4 = F_5 ( & V_6 , L_2 ) ) ) {
unsigned int V_10 , V_11 , V_12 = V_13 ,
V_14 = V_13 , V_15 = 0 , V_16 = 0 ;
int V_17 ;
if ( ! strlen ( V_4 ) )
continue;
V_17 = sscanf ( V_4 , L_3 ,
& V_10 , & V_11 , & V_12 , & V_14 ,
& V_15 , & V_16 ) ;
if ( V_17 < 2 ) {
F_6 ( V_18
L_4 , V_4 ) ;
continue;
}
F_6 ( V_5
L_5 ,
V_10 , V_11 , V_12 , V_14 , V_15 , V_16 ) ;
V_7 = F_7 ( & V_8 , V_10 , V_11 ,
V_12 , V_14 , V_15 , V_16 , 0 ) ;
if ( V_7 )
F_6 ( V_18
L_6 , V_7 ) ;
}
return 0 ;
}
static void T_2 F_8 ( void )
{
F_9 ( & V_8 ) ;
}
