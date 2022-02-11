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
static const inline struct V_31 * F_16 ( int V_34 )
{
if ( V_37 [ V_34 ] == NULL )
F_17 ( L_1 , V_40 ,
V_41 , V_34 ) ;
F_10 ( & V_29 ) ;
return V_37 [ V_34 ] ;
}
static inline void F_18 ( const struct V_31 * V_42 )
{
F_11 ( & V_29 ) ;
}
static int F_19 ( struct V_7 * V_8 , struct V_27 * V_28 )
{
int V_33 ;
struct V_43 * V_44 = F_20 ( V_28 ) ;
const struct V_31 * V_32 ;
if ( F_21 ( V_28 ) < sizeof( * V_44 ) )
return - V_36 ;
V_32 = F_16 ( V_44 -> V_45 ) ;
if ( V_32 == NULL )
V_33 = - V_46 ;
else
V_33 = V_32 -> V_47 ( V_8 , V_28 ) ;
F_18 ( V_32 ) ;
return V_33 ;
}
static int F_22 ( struct V_7 * V_8 , struct V_27 * V_28 )
{
int V_48 ;
switch ( V_28 -> V_49 ) {
case V_50 :
case V_51 :
if ( V_30 == NULL )
F_17 ( L_1 , V_40 ,
V_41 , V_52 ) ;
F_10 ( & V_29 ) ;
if ( V_30 != NULL )
V_48 = V_30 ( V_8 , V_28 ) ;
else
V_48 = - V_53 ;
F_11 ( & V_29 ) ;
return V_48 ;
case V_54 :
return F_19 ( V_8 , V_28 ) ;
default:
return - V_36 ;
}
}
static void F_23 ( struct V_7 * V_8 )
{
F_10 ( & V_55 ) ;
F_24 ( V_8 , & F_22 ) ;
F_11 ( & V_55 ) ;
}
static int T_2 F_25 ( struct V_56 * V_56 )
{
struct V_57 V_58 = {
. V_59 = F_23 ,
} ;
V_56 -> V_60 = F_26 ( V_56 , V_41 ,
V_61 , & V_58 ) ;
return V_56 -> V_60 == NULL ? - V_62 : 0 ;
}
static void T_3 F_27 ( struct V_56 * V_56 )
{
F_28 ( V_56 -> V_60 ) ;
V_56 -> V_60 = NULL ;
}
static int T_4 F_29 ( void )
{
return F_30 ( & V_63 ) ;
}
static void T_5 F_31 ( void )
{
F_32 ( & V_63 ) ;
}
