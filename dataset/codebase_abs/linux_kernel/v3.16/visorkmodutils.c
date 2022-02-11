void * F_1 ( T_1 V_1 )
{
return F_2 ( V_1 , V_2 | V_3 ) ;
}
struct V_4 * F_3 ( void * V_5 , T_1 V_6 )
{
struct V_4 * V_7 = NULL ;
struct V_4 * V_8 = F_1 ( sizeof( struct V_4 ) ) ;
if ( V_8 == NULL ) {
V_7 = NULL ;
goto V_9;
}
memset ( V_8 , 0 , sizeof( struct V_4 ) ) ;
V_8 -> V_5 = V_5 ;
V_8 -> V_10 = V_6 ;
V_7 = V_8 ;
V_9:
if ( V_7 == NULL ) {
F_4 ( V_8 ) ;
V_8 = NULL ;
}
return V_7 ;
}
void F_4 ( struct V_4 * V_8 )
{
if ( ! V_8 )
return;
F_5 ( V_8 ) ;
}
static T_2 T_3
F_6 ( void )
{
unsigned int V_11 , V_12 , V_13 , V_14 ;
if ( V_15 ) {
F_7 ( V_16 , & V_11 , & V_12 , & V_13 , & V_14 ) ;
return ( V_12 == V_17 ) &&
( V_13 == V_18 ) &&
( V_14 == V_19 ) ;
} else
return 0 ;
}
static T_2 int
F_8 ( void )
{
if ( F_6 () ) {
V_20 = TRUE ;
return 0 ;
} else
return - V_21 ;
}
static T_4 void
F_9 ( void )
{
}
