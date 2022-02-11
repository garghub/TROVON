static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
struct V_5 * args = V_4 ;
if ( F_2 ( V_3 != V_6 ) )
return V_7 ;
if ( V_8 & V_9 )
F_3 () ;
if ( V_8 & V_10 )
F_4 ( args -> V_11 ) ;
if ( V_8 & V_12 )
F_5 ( 10 ) ;
if ( V_8 & V_13 )
return V_14 ;
return V_15 ;
}
static int T_1 F_6 ( char * V_16 )
{
char * V_17 , * V_18 ;
F_7 ( & V_19 ) ;
if ( F_8 () ) {
F_9 ( V_20 L_1 ) ;
return 0 ;
}
if ( * V_16 != '=' )
return 0 ;
for ( V_17 = V_16 + 1 ; * V_17 ; V_17 = V_18 + 1 ) {
V_18 = strchr ( V_17 , ',' ) ;
if ( V_18 )
* V_18 = 0 ;
if ( strcmp ( V_17 , L_2 ) == 0 )
V_8 |= V_9 ;
else if ( strcmp ( V_17 , L_3 ) == 0 )
V_8 |= V_10 ;
else if ( strcmp ( V_17 , L_4 ) == 0 )
V_8 |= V_12 ;
else if ( strcmp ( V_17 , L_5 ) == 0 )
V_8 |= V_13 ;
else
F_9 ( V_20 L_6 ,
V_17 ) ;
if ( ! V_18 )
break;
}
return 0 ;
}
