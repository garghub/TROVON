int F_1 ( unsigned int V_1 , int V_2 )
{
if ( ! V_3 ) {
F_2 ( L_1 , V_1 ) ;
F_2 ( L_2 ) ;
return 1 ;
}
return F_3 ( V_3 , V_1 ) ;
}
static inline void F_4 ( void )
{
F_5 ( 0x1 , V_4 + V_5 ) ;
while ( F_6 ( V_4 + V_5 ) & 0x1 ) ;
}
static T_1 F_7 ( struct V_6 * V_7 , struct V_8 * V_8 ,
unsigned long V_9 , T_2 V_10 ,
enum V_11 V_12 ,
struct V_13 * V_14 )
{
if ( V_12 != V_15 )
F_4 () ;
return F_8 ( V_7 , F_9 ( V_8 ) ) + V_9 ;
}
static void F_10 ( struct V_6 * V_7 , T_1 V_16 ,
T_2 V_10 , enum V_11 V_12 ,
struct V_13 * V_14 )
{
if ( V_12 != V_15 )
F_4 () ;
}
static void F_11 ( struct V_6 * V_7 , T_1 V_16 ,
T_2 V_10 , enum V_11 V_12 )
{
if ( V_12 != V_15 )
F_4 () ;
}
static int F_12 ( struct V_17 * V_18 ,
unsigned long V_19 , void * V_20 )
{
struct V_6 * V_7 = V_20 ;
if ( V_19 != V_21 )
return V_22 ;
F_13 ( V_7 , & V_23 ) ;
return V_24 ;
}
int T_3 F_14 ( void )
{
struct V_25 * V_26 ;
V_26 = F_15 ( NULL , V_27 ) ;
if ( V_26 ) {
struct V_28 V_29 ;
F_16 ( L_3 ) ;
F_17 ( V_26 , 0 , & V_29 ) ;
V_30 = V_29 . V_31 ;
F_18 ( & V_30 ) ;
V_3 = F_19 ( V_26 , 0 ) ;
V_4 = F_19 ( V_26 , 1 ) ;
F_1 ( F_20 ( F_21 () ) , 0 ) ;
}
return 0 ;
}
static int T_3 F_22 ( void )
{
if ( F_15 ( NULL , V_27 ) )
F_23 ( & V_32 ,
& V_33 ) ;
return 0 ;
}
