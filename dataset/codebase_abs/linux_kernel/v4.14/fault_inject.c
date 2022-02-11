static T_1 F_1 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
static T_5 V_5 ;
char V_6 [ 25 ] ;
T_3 V_7 ;
T_4 V_8 = * V_4 ;
struct V_9 * V_10 = F_2 ( V_1 ) -> V_11 ;
if ( ! V_8 )
V_5 = V_10 -> V_12 () ;
V_7 = F_3 ( V_6 , sizeof( V_6 ) , L_1 , V_5 ) ;
return F_4 ( V_2 , V_3 , V_4 , V_6 , V_7 ) ;
}
static T_1 F_5 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
char V_13 [ V_14 ] ;
T_3 V_7 = F_6 ( sizeof( V_13 ) - 1 , V_3 ) ;
struct V_15 * V_15 = V_16 -> V_17 -> V_18 ;
struct V_19 V_20 ;
struct V_9 * V_10 = F_2 ( V_1 ) -> V_11 ;
T_5 V_5 ;
char * V_21 ;
if ( F_7 ( V_13 , V_2 , V_7 ) )
return - V_22 ;
V_13 [ V_7 ] = '\0' ;
V_21 = strchr ( V_13 , '\n' ) ;
if ( V_21 ) {
V_7 = V_21 - V_13 ;
* V_21 = '\0' ;
}
V_7 = F_8 ( V_15 , V_13 , V_7 , (struct V_23 * ) & V_20 , sizeof( V_20 ) ) ;
if ( V_7 > 0 ) {
V_5 = V_10 -> V_24 ( & V_20 , V_7 ) ;
if ( V_5 )
F_9 ( L_2 ,
V_10 -> V_1 , V_13 , V_5 ) ;
} else {
V_5 = F_10 ( V_13 , NULL , 0 ) ;
if ( V_5 == 0 )
F_9 ( L_3 , V_10 -> V_1 ) ;
else
F_9 ( L_4 ,
V_10 -> V_1 , V_5 ) ;
V_5 = V_10 -> V_25 ( V_5 ) ;
F_9 ( L_5 , V_10 -> V_1 , V_5 ) ;
}
return V_3 ;
}
void F_11 ( void )
{
F_12 ( V_26 ) ;
}
int F_13 ( void )
{
unsigned int V_27 ;
struct V_9 * V_10 ;
T_6 V_28 = V_29 | V_30 | V_31 ;
V_26 = F_14 ( L_6 , NULL ) ;
if ( ! V_26 )
goto V_32;
for ( V_27 = 0 ; V_27 < V_33 ; V_27 ++ ) {
V_10 = & V_34 [ V_27 ] ;
if ( ! F_15 ( V_10 -> V_1 , V_28 , V_26 , V_10 , & V_35 ) )
goto V_32;
}
return 0 ;
V_32:
F_11 () ;
return - V_36 ;
}
