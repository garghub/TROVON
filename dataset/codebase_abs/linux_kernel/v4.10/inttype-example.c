static int T_1 F_1 ( void )
{
int V_1 [ 6 ] ;
int V_2 , V_3 ;
unsigned int V_4 ;
F_2 ( V_5 L_1 ) ;
for ( V_2 = 0 ; V_2 != 10 ; V_2 ++ )
F_3 ( & V_6 , V_2 ) ;
F_2 ( V_5 L_2 , F_4 ( & V_6 ) ) ;
V_4 = F_5 ( & V_6 , V_1 , 2 ) ;
F_2 ( V_5 L_3 , V_4 ) ;
V_4 = F_6 ( & V_6 , V_1 , V_4 ) ;
F_2 ( V_5 L_3 , V_4 ) ;
F_2 ( V_5 L_4 ) ;
F_7 ( & V_6 ) ;
for ( V_2 = 20 ; F_3 ( & V_6 , V_2 ) ; V_2 ++ )
;
F_2 ( V_5 L_5 , F_4 ( & V_6 ) ) ;
if ( F_8 ( & V_6 , & V_2 ) )
F_2 ( V_5 L_6 , V_2 ) ;
V_3 = 0 ;
while ( F_9 ( & V_6 , & V_2 ) ) {
F_2 ( V_5 L_7 , V_2 ) ;
if ( V_2 != V_7 [ V_3 ++ ] ) {
F_2 ( V_8 L_8 ) ;
return - V_9 ;
}
}
if ( V_3 != F_10 ( V_7 ) ) {
F_2 ( V_8 L_9 ) ;
return - V_9 ;
}
F_2 ( V_5 L_10 ) ;
return 0 ;
}
static T_2 F_11 ( struct V_10 * V_10 , const char T_3 * V_1 ,
T_4 V_11 , T_5 * V_12 )
{
int V_4 ;
unsigned int V_13 ;
if ( F_12 ( & V_14 ) )
return - V_15 ;
V_4 = F_13 ( & V_6 , V_1 , V_11 , & V_13 ) ;
F_14 ( & V_14 ) ;
return V_4 ? V_4 : V_13 ;
}
static T_2 F_15 ( struct V_10 * V_10 , char T_3 * V_1 ,
T_4 V_11 , T_5 * V_12 )
{
int V_4 ;
unsigned int V_13 ;
if ( F_12 ( & V_16 ) )
return - V_15 ;
V_4 = F_16 ( & V_6 , V_1 , V_11 , & V_13 ) ;
F_14 ( & V_16 ) ;
return V_4 ? V_4 : V_13 ;
}
static int T_1 F_17 ( void )
{
#ifdef F_18
int V_4 ;
V_4 = F_19 ( & V_6 , V_17 , V_18 ) ;
if ( V_4 ) {
F_2 ( V_19 L_11 ) ;
return V_4 ;
}
#endif
if ( F_1 () < 0 ) {
#ifdef F_18
F_20 ( & V_6 ) ;
#endif
return - V_9 ;
}
if ( F_21 ( V_20 , 0 , NULL , & V_21 ) == NULL ) {
#ifdef F_18
F_20 ( & V_6 ) ;
#endif
return - V_22 ;
}
return 0 ;
}
static void T_6 F_22 ( void )
{
F_23 ( V_20 , NULL ) ;
#ifdef F_18
F_20 ( & V_6 ) ;
#endif
}
