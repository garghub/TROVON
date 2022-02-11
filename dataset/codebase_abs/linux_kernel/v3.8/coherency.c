int F_1 ( void )
{
int V_1 , V_2 ;
V_1 = F_2 ( V_3 + V_4 ) ;
V_2 = ( V_1 & 0xF ) + 1 ;
return V_2 ;
}
int F_3 ( unsigned int V_5 , int V_6 )
{
if ( ! V_3 ) {
F_4 ( L_1 , V_5 ) ;
F_4 ( L_2 ) ;
return 1 ;
}
return F_5 ( V_3 , V_5 ) ;
}
static inline void F_6 ( void )
{
F_7 ( 0x1 , V_7 + V_8 ) ;
while ( F_2 ( V_7 + V_8 ) & 0x1 ) ;
}
static T_1 F_8 ( struct V_9 * V_10 , struct V_11 * V_11 ,
unsigned long V_12 , T_2 V_13 ,
enum V_14 V_15 ,
struct V_16 * V_17 )
{
if ( V_15 != V_18 )
F_6 () ;
return F_9 ( V_10 , F_10 ( V_11 ) ) + V_12 ;
}
static void F_11 ( struct V_9 * V_10 , T_1 V_19 ,
T_2 V_13 , enum V_14 V_15 ,
struct V_16 * V_17 )
{
if ( V_15 != V_18 )
F_6 () ;
}
static void F_12 ( struct V_9 * V_10 , T_1 V_19 ,
T_2 V_13 , enum V_14 V_15 )
{
if ( V_15 != V_18 )
F_6 () ;
}
static int F_13 ( struct V_20 * V_21 ,
unsigned long V_22 , void * V_23 )
{
struct V_9 * V_10 = V_23 ;
if ( V_22 != V_24 )
return V_25 ;
F_14 ( V_10 , & V_26 ) ;
return V_27 ;
}
int T_3 F_15 ( void )
{
struct V_28 * V_29 ;
V_29 = F_16 ( NULL , V_30 ) ;
if ( V_29 ) {
F_17 ( L_3 ) ;
V_3 = F_18 ( V_29 , 0 ) ;
V_7 = F_18 ( V_29 , 1 ) ;
F_3 ( F_19 ( F_20 () ) , 0 ) ;
F_21 ( & V_31 ,
& V_32 ) ;
}
return 0 ;
}
