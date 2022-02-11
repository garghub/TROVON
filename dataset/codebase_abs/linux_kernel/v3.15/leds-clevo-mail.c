static int T_1 F_1 ( const struct V_1 * V_2 )
{
F_2 ( L_1 , V_2 -> V_3 ) ;
return 1 ;
}
static void F_3 ( struct V_4 * V_5 ,
enum V_6 V_7 )
{
F_4 () ;
if ( V_7 == V_8 )
F_5 ( NULL , V_9 ) ;
else if ( V_7 <= V_10 )
F_5 ( NULL , V_11 ) ;
else
F_5 ( NULL , V_12 ) ;
F_6 () ;
}
static int F_7 ( struct V_4 * V_5 ,
unsigned long * V_13 ,
unsigned long * V_14 )
{
int V_15 = - V_16 ;
F_4 () ;
if ( * V_13 == 0 && * V_14 == 0 ) {
* V_13 = 1000 ;
* V_14 = 1000 ;
F_5 ( NULL , V_11 ) ;
V_15 = 0 ;
} else if ( * V_13 == 500 && * V_14 == 500 ) {
F_5 ( NULL , V_12 ) ;
V_15 = 0 ;
} else if ( * V_13 == 1000 && * V_14 == 1000 ) {
F_5 ( NULL , V_11 ) ;
V_15 = 0 ;
} else {
F_8 ( L_2
L_3 ,
* V_13 , * V_14 ) ;
}
F_6 () ;
return V_15 ;
}
static int T_1 F_9 ( struct V_17 * V_18 )
{
return F_10 ( & V_18 -> V_19 , & V_20 ) ;
}
static int F_11 ( struct V_17 * V_18 )
{
F_12 ( & V_20 ) ;
return 0 ;
}
static int T_1 F_13 ( void )
{
int error = 0 ;
int V_21 = 0 ;
if ( ! V_22 ) {
V_21 = F_14 ( V_23 ) ;
} else {
V_21 = 1 ;
F_15 ( L_4
L_5
L_6
L_7 ) ;
}
if ( ! V_21 )
return - V_24 ;
V_18 = F_16 ( V_25 , - 1 , NULL , 0 ) ;
if ( ! F_17 ( V_18 ) ) {
error = F_18 ( & V_26 ,
F_9 ) ;
if ( error ) {
F_15 ( L_8 ) ;
F_19 ( V_18 ) ;
}
} else
error = F_20 ( V_18 ) ;
return error ;
}
static void T_2 F_21 ( void )
{
F_19 ( V_18 ) ;
F_22 ( & V_26 ) ;
F_3 ( NULL , V_8 ) ;
}
