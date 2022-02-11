int F_1 ( void * V_1 , T_1 * V_2 )
{
if ( ( V_2 [ 0 ] != V_3 ||
V_2 [ 1 ] != V_3 ) &&
( ( V_4 ) ( unsigned long ) V_1 != V_2 [ 0 ] ||
( V_4 ) ( ( ( ( unsigned long ) V_1 ) >> 31 ) >> 1 ) != V_2 [ 1 ] ) )
return - V_5 ;
else
return 0 ;
}
void F_2 ( void * V_1 , T_1 * V_2 )
{
V_2 [ 0 ] = ( V_4 ) ( unsigned long ) V_1 ;
V_2 [ 1 ] = ( V_4 ) ( ( ( unsigned long ) V_1 >> 31 ) >> 1 ) ;
}
int F_3 ( struct V_6 * V_1 , struct V_7 * V_8 , int V_9 )
{
V_4 V_10 [ V_11 ] ;
V_10 [ V_12 ] = F_4 ( V_1 ) ;
V_10 [ V_13 ] = V_1 -> V_14 ;
V_10 [ V_15 ] = F_5 ( V_1 ) ;
V_10 [ V_16 ] = V_1 -> V_17 ;
V_10 [ V_18 ] = V_1 -> V_19 ;
V_10 [ V_20 ] = V_1 -> V_21 ;
V_10 [ V_22 ] = F_6 ( & V_1 -> V_23 ) ;
V_10 [ V_24 ] = V_1 -> V_25 . V_26 ;
return F_7 ( V_8 , V_9 , sizeof( V_10 ) , & V_10 ) ;
}
void F_8 ( int (* F_9)( struct V_7 * V_8 , struct V_27 * V_28 ) )
{
F_10 ( & V_29 ) ;
V_30 = F_9 ;
F_11 ( & V_29 ) ;
}
void F_12 ( int (* F_9)( struct V_7 * V_8 , struct V_27 * V_28 ) )
{
F_10 ( & V_29 ) ;
V_30 = NULL ;
F_11 ( & V_29 ) ;
}
int F_13 ( const struct V_31 * V_32 )
{
int V_33 = 0 ;
if ( V_32 -> V_34 >= V_35 )
return - V_36 ;
F_10 ( & V_29 ) ;
if ( V_37 [ V_32 -> V_34 ] )
V_33 = - V_38 ;
else
V_37 [ V_32 -> V_34 ] = V_32 ;
F_11 ( & V_29 ) ;
return V_33 ;
}
void F_14 ( const struct V_31 * V_39 )
{
int V_34 = V_39 -> V_34 ;
if ( V_34 >= V_35 )
return;
F_10 ( & V_29 ) ;
F_15 ( V_37 [ V_34 ] != V_39 ) ;
V_37 [ V_34 ] = NULL ;
F_11 ( & V_29 ) ;
}
static int F_16 ( struct V_7 * V_8 , struct V_27 * V_28 )
{
int V_33 ;
struct V_40 * V_41 = F_17 ( V_28 ) ;
const struct V_31 * V_32 ;
if ( F_18 ( V_28 ) < sizeof( * V_41 ) )
return - V_36 ;
if ( V_41 -> V_42 >= V_35 )
return - V_36 ;
if ( V_37 [ V_41 -> V_42 ] == NULL )
F_19 ( L_1 , V_43 ,
V_44 , V_41 -> V_42 ) ;
F_10 ( & V_29 ) ;
V_32 = V_37 [ V_41 -> V_42 ] ;
if ( V_32 == NULL )
V_33 = - V_45 ;
else
V_33 = V_32 -> V_46 ( V_8 , V_28 ) ;
F_11 ( & V_29 ) ;
return V_33 ;
}
static int F_20 ( struct V_7 * V_8 , struct V_27 * V_28 )
{
int V_47 ;
switch ( V_28 -> V_48 ) {
case V_49 :
case V_50 :
if ( V_30 == NULL )
F_19 ( L_1 , V_43 ,
V_44 , V_51 ) ;
F_10 ( & V_29 ) ;
if ( V_30 != NULL )
V_47 = V_30 ( V_8 , V_28 ) ;
else
V_47 = - V_52 ;
F_11 ( & V_29 ) ;
return V_47 ;
case V_53 :
return F_16 ( V_8 , V_28 ) ;
default:
return - V_36 ;
}
}
static void F_21 ( struct V_7 * V_8 )
{
F_10 ( & V_54 ) ;
F_22 ( V_8 , & F_20 ) ;
F_11 ( & V_54 ) ;
}
static int T_2 F_23 ( struct V_55 * V_55 )
{
struct V_56 V_57 = {
. V_58 = F_21 ,
} ;
V_55 -> V_59 = F_24 ( V_55 , V_44 , & V_57 ) ;
return V_55 -> V_59 == NULL ? - V_60 : 0 ;
}
static void T_3 F_25 ( struct V_55 * V_55 )
{
F_26 ( V_55 -> V_59 ) ;
V_55 -> V_59 = NULL ;
}
static int T_4 F_27 ( void )
{
return F_28 ( & V_61 ) ;
}
static void T_5 F_29 ( void )
{
F_30 ( & V_61 ) ;
}
