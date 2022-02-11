static const char * * T_1 F_1 ( struct V_1 * V_2 ,
int * V_3 )
{
const char * * V_4 ;
unsigned int V_5 ;
V_5 = F_2 ( V_2 ) ;
if ( F_3 ( ! V_5 ) )
return F_4 ( - V_6 ) ;
V_4 = F_5 ( V_5 , sizeof( const char * ) , V_7 ) ;
if ( ! V_4 )
return F_4 ( - V_8 ) ;
* V_3 = F_6 ( V_2 , V_4 , V_5 ) ;
return V_4 ;
}
static void T_1 F_7 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_11 * V_11 ;
void T_2 * V_12 ;
const char * * V_4 ;
int V_3 = 0 ;
V_12 = F_8 ( V_2 , 0 ) ;
if ( ! V_12 ) {
F_9 ( L_1 , V_13 ) ;
return;
}
V_4 = F_1 ( V_2 , & V_3 ) ;
if ( F_10 ( V_4 ) ) {
F_9 ( L_2 ,
V_13 , F_11 ( V_4 ) ) ;
goto V_14;
}
V_11 = F_12 ( NULL , V_2 -> V_15 , V_4 , V_3 ,
V_10 -> V_16 | V_17 ,
V_12 + V_10 -> V_18 ,
V_10 -> V_19 , V_10 -> V_20 , V_10 -> V_21 ,
V_10 -> V_22 ) ;
if ( F_10 ( V_11 ) )
goto V_23;
F_13 ( L_3 ,
F_14 ( V_11 ) ,
F_14 ( F_15 ( V_11 ) ) ,
( unsigned int ) F_16 ( V_11 ) ) ;
F_17 ( V_4 ) ;
F_18 ( V_2 , V_24 , V_11 ) ;
return;
V_23:
F_17 ( V_4 ) ;
V_14:
F_19 ( V_12 ) ;
}
static void T_1 F_20 ( struct V_1 * V_2 )
{
F_7 ( V_2 , & V_25 ) ;
}
