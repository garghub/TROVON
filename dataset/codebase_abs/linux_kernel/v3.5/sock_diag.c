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
T_1 * V_10 ;
V_10 = F_4 ( F_5 ( V_8 , V_9 , V_11 * sizeof( T_1 ) ) ) ;
V_10 [ V_12 ] = F_6 ( V_1 ) ;
V_10 [ V_13 ] = V_1 -> V_14 ;
V_10 [ V_15 ] = F_7 ( V_1 ) ;
V_10 [ V_16 ] = V_1 -> V_17 ;
V_10 [ V_18 ] = V_1 -> V_19 ;
V_10 [ V_20 ] = V_1 -> V_21 ;
V_10 [ V_22 ] = F_8 ( & V_1 -> V_23 ) ;
return 0 ;
V_24:
return - V_25 ;
}
void F_9 ( int (* F_10)( struct V_7 * V_8 , struct V_26 * V_27 ) )
{
F_11 ( & V_28 ) ;
V_29 = F_10 ;
F_12 ( & V_28 ) ;
}
void F_13 ( int (* F_10)( struct V_7 * V_8 , struct V_26 * V_27 ) )
{
F_11 ( & V_28 ) ;
V_29 = NULL ;
F_12 ( & V_28 ) ;
}
int F_14 ( const struct V_30 * V_31 )
{
int V_32 = 0 ;
if ( V_31 -> V_33 >= V_34 )
return - V_35 ;
F_11 ( & V_28 ) ;
if ( V_36 [ V_31 -> V_33 ] )
V_32 = - V_37 ;
else
V_36 [ V_31 -> V_33 ] = V_31 ;
F_12 ( & V_28 ) ;
return V_32 ;
}
void F_15 ( const struct V_30 * V_38 )
{
int V_33 = V_38 -> V_33 ;
if ( V_33 >= V_34 )
return;
F_11 ( & V_28 ) ;
F_16 ( V_36 [ V_33 ] != V_38 ) ;
V_36 [ V_33 ] = NULL ;
F_12 ( & V_28 ) ;
}
static const inline struct V_30 * F_17 ( int V_33 )
{
if ( V_36 [ V_33 ] == NULL )
F_18 ( L_1 , V_39 ,
V_40 , V_33 ) ;
F_11 ( & V_28 ) ;
return V_36 [ V_33 ] ;
}
static inline void F_19 ( const struct V_30 * V_41 )
{
F_12 ( & V_28 ) ;
}
static int F_20 ( struct V_7 * V_8 , struct V_26 * V_27 )
{
int V_32 ;
struct V_42 * V_43 = F_21 ( V_27 ) ;
const struct V_30 * V_31 ;
if ( F_22 ( V_27 ) < sizeof( * V_43 ) )
return - V_35 ;
V_31 = F_17 ( V_43 -> V_44 ) ;
if ( V_31 == NULL )
V_32 = - V_45 ;
else
V_32 = V_31 -> V_46 ( V_8 , V_27 ) ;
F_19 ( V_31 ) ;
return V_32 ;
}
static int F_23 ( struct V_7 * V_8 , struct V_26 * V_27 )
{
int V_47 ;
switch ( V_27 -> V_48 ) {
case V_49 :
case V_50 :
if ( V_29 == NULL )
F_18 ( L_1 , V_39 ,
V_40 , V_51 ) ;
F_11 ( & V_28 ) ;
if ( V_29 != NULL )
V_47 = V_29 ( V_8 , V_27 ) ;
else
V_47 = - V_52 ;
F_12 ( & V_28 ) ;
return V_47 ;
case V_53 :
return F_20 ( V_8 , V_27 ) ;
default:
return - V_35 ;
}
}
static void F_24 ( struct V_7 * V_8 )
{
F_11 ( & V_54 ) ;
F_25 ( V_8 , & F_23 ) ;
F_12 ( & V_54 ) ;
}
static int T_2 F_26 ( void )
{
V_55 = F_27 ( & V_56 , V_40 , 0 ,
F_24 , NULL , V_57 ) ;
return V_55 == NULL ? - V_58 : 0 ;
}
static void T_3 F_28 ( void )
{
F_29 ( V_55 ) ;
}
