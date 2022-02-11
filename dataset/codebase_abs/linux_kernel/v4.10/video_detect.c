static void F_1 ( void )
{
if ( ! strcmp ( L_1 , V_1 ) )
V_2 = V_3 ;
if ( ! strcmp ( L_2 , V_1 ) )
V_2 = V_4 ;
if ( ! strcmp ( L_3 , V_1 ) )
V_2 = V_5 ;
if ( ! strcmp ( L_4 , V_1 ) )
V_2 = V_6 ;
}
static T_1
F_2 ( T_2 V_7 , T_3 V_8 , void * V_9 , void * * V_10 )
{
long * V_11 = V_9 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
static const struct V_16 V_17 [] = {
{ V_18 , 0 } ,
{ L_5 , 0 } ,
} ;
if ( F_3 ( V_7 , & V_15 ) )
return V_19 ;
if ( ! F_4 ( V_15 , V_17 ) ) {
V_13 = F_5 ( V_7 ) ;
if ( ! V_13 )
return V_19 ;
F_6 ( V_13 ) ;
* V_11 |= F_7 ( V_7 ) ;
}
return V_19 ;
}
static int F_8 ( const struct V_20 * V_21 )
{
V_22 = V_3 ;
return 0 ;
}
static int F_9 ( const struct V_20 * V_21 )
{
V_22 = V_4 ;
return 0 ;
}
static int F_10 ( const struct V_20 * V_21 )
{
V_22 = V_5 ;
return 0 ;
}
static void F_11 ( struct V_23 * V_24 )
{
if ( F_12 () != V_4 )
F_13 () ;
}
static int F_14 ( struct V_25 * V_26 ,
unsigned long V_27 , void * V_28 )
{
struct V_29 * V_30 = V_28 ;
if ( V_30 -> V_31 . type == V_32 &&
V_27 == V_33 )
F_15 ( & V_34 ) ;
return V_35 ;
}
enum V_36 F_12 ( void )
{
static F_16 ( V_37 ) ;
static bool V_38 ;
static long V_39 ;
F_17 ( & V_37 ) ;
if ( ! V_38 ) {
F_1 () ;
F_18 ( V_40 ) ;
F_19 ( V_41 , V_42 ,
V_43 , F_2 , NULL ,
& V_39 , NULL ) ;
F_20 ( & V_34 ,
F_11 ) ;
V_44 . V_45 = F_14 ;
V_44 . V_46 = 0 ;
if ( F_21 ( & V_44 ) == 0 )
V_47 = true ;
V_38 = true ;
}
F_22 ( & V_37 ) ;
if ( V_2 != V_48 )
return V_2 ;
if ( V_22 != V_48 )
return V_22 ;
if ( ! ( V_39 & V_49 ) )
return V_3 ;
if ( F_23 () && F_24 ( V_32 ) )
return V_5 ;
return V_4 ;
}
void F_25 ( enum V_36 type )
{
V_22 = type ;
if ( F_12 () != V_4 )
F_13 () ;
}
void T_4 F_26 ( void )
{
if ( V_47 )
F_27 ( & V_44 ) ;
}
