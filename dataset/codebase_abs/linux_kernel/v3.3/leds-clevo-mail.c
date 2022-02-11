static int T_1 F_1 ( const struct V_1 * V_2 )
{
F_2 (KERN_INFO KBUILD_MODNAME L_1 , id->ident) ;
return 1 ;
}
static void F_3 ( struct V_3 * V_4 ,
enum V_5 V_6 )
{
F_4 () ;
if ( V_6 == V_7 )
F_5 ( NULL , V_8 ) ;
else if ( V_6 <= V_9 )
F_5 ( NULL , V_10 ) ;
else
F_5 ( NULL , V_11 ) ;
F_6 () ;
}
static int F_7 ( struct V_3 * V_4 ,
unsigned long * V_12 ,
unsigned long * V_13 )
{
int V_14 = - V_15 ;
F_4 () ;
if ( * V_12 == 0 && * V_13 == 0 ) {
* V_12 = 1000 ;
* V_13 = 1000 ;
F_5 ( NULL , V_10 ) ;
V_14 = 0 ;
} else if ( * V_12 == 500 && * V_13 == 500 ) {
F_5 ( NULL , V_11 ) ;
V_14 = 0 ;
} else if ( * V_12 == 1000 && * V_13 == 1000 ) {
F_5 ( NULL , V_10 ) ;
V_14 = 0 ;
} else {
F_2 (KERN_DEBUG KBUILD_MODNAME
L_2
L_3 ,
*delay_on, *delay_off) ;
}
F_6 () ;
return V_14 ;
}
static int T_2 F_8 ( struct V_16 * V_17 )
{
return F_9 ( & V_17 -> V_18 , & V_19 ) ;
}
static int F_10 ( struct V_16 * V_17 )
{
F_11 ( & V_19 ) ;
return 0 ;
}
static int T_1 F_12 ( void )
{
int error = 0 ;
int V_20 = 0 ;
if ( ! V_21 ) {
V_20 = F_13 ( V_22 ) ;
} else {
V_20 = 1 ;
F_2 (KERN_ERR KBUILD_MODNAME L_4
L_5
L_6
L_7 ) ;
}
if ( ! V_20 )
return - V_23 ;
V_17 = F_14 ( V_24 , - 1 , NULL , 0 ) ;
if ( ! F_15 ( V_17 ) ) {
error = F_16 ( & V_25 ,
F_8 ) ;
if ( error ) {
F_2 (KERN_ERR KBUILD_MODNAME
L_8 ) ;
F_17 ( V_17 ) ;
}
} else
error = F_18 ( V_17 ) ;
return error ;
}
static void T_3 F_19 ( void )
{
F_17 ( V_17 ) ;
F_20 ( & V_25 ) ;
F_3 ( NULL , V_7 ) ;
}
