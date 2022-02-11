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
int F_8 ( bool V_27 , struct V_6 * V_1 ,
struct V_7 * V_8 , int V_9 )
{
struct V_28 * V_29 ;
struct V_30 * V_31 ;
struct V_32 * V_33 ;
unsigned int V_34 ;
int V_35 = 0 ;
if ( ! V_27 ) {
F_9 ( V_8 , V_9 , 0 ) ;
return 0 ;
}
F_10 () ;
V_31 = F_11 ( V_1 -> V_30 ) ;
if ( ! V_31 )
goto V_36;
V_29 = V_31 -> V_37 -> V_38 ;
V_34 = F_12 ( V_29 ) ;
V_33 = F_9 ( V_8 , V_9 , V_34 ) ;
if ( V_33 == NULL ) {
V_35 = - V_39 ;
goto V_36;
}
memcpy ( F_13 ( V_33 ) , V_29 -> V_31 , V_34 ) ;
V_36:
F_14 () ;
return V_35 ;
}
void F_15 ( int (* F_16)( struct V_7 * V_8 , struct V_40 * V_41 ) )
{
F_17 ( & V_42 ) ;
V_43 = F_16 ;
F_18 ( & V_42 ) ;
}
void F_19 ( int (* F_16)( struct V_7 * V_8 , struct V_40 * V_41 ) )
{
F_17 ( & V_42 ) ;
V_43 = NULL ;
F_18 ( & V_42 ) ;
}
int F_20 ( const struct V_44 * V_45 )
{
int V_35 = 0 ;
if ( V_45 -> V_46 >= V_47 )
return - V_48 ;
F_17 ( & V_42 ) ;
if ( V_49 [ V_45 -> V_46 ] )
V_35 = - V_50 ;
else
V_49 [ V_45 -> V_46 ] = V_45 ;
F_18 ( & V_42 ) ;
return V_35 ;
}
void F_21 ( const struct V_44 * V_51 )
{
int V_46 = V_51 -> V_46 ;
if ( V_46 >= V_47 )
return;
F_17 ( & V_42 ) ;
F_22 ( V_49 [ V_46 ] != V_51 ) ;
V_49 [ V_46 ] = NULL ;
F_18 ( & V_42 ) ;
}
static int F_23 ( struct V_7 * V_8 , struct V_40 * V_41 )
{
int V_35 ;
struct V_52 * V_53 = F_24 ( V_41 ) ;
const struct V_44 * V_45 ;
if ( F_25 ( V_41 ) < sizeof( * V_53 ) )
return - V_48 ;
if ( V_53 -> V_54 >= V_47 )
return - V_48 ;
if ( V_49 [ V_53 -> V_54 ] == NULL )
F_26 ( L_1 , V_55 ,
V_56 , V_53 -> V_54 ) ;
F_17 ( & V_42 ) ;
V_45 = V_49 [ V_53 -> V_54 ] ;
if ( V_45 == NULL )
V_35 = - V_57 ;
else
V_35 = V_45 -> V_58 ( V_8 , V_41 ) ;
F_18 ( & V_42 ) ;
return V_35 ;
}
static int F_27 ( struct V_7 * V_8 , struct V_40 * V_41 )
{
int V_59 ;
switch ( V_41 -> V_60 ) {
case V_61 :
case V_62 :
if ( V_43 == NULL )
F_26 ( L_1 , V_55 ,
V_56 , V_63 ) ;
F_17 ( & V_42 ) ;
if ( V_43 != NULL )
V_59 = V_43 ( V_8 , V_41 ) ;
else
V_59 = - V_64 ;
F_18 ( & V_42 ) ;
return V_59 ;
case V_65 :
return F_23 ( V_8 , V_41 ) ;
default:
return - V_48 ;
}
}
static void F_28 ( struct V_7 * V_8 )
{
F_17 ( & V_66 ) ;
F_29 ( V_8 , & F_27 ) ;
F_18 ( & V_66 ) ;
}
static int T_2 F_30 ( struct V_67 * V_67 )
{
struct V_68 V_69 = {
. V_70 = F_28 ,
} ;
V_67 -> V_71 = F_31 ( V_67 , V_56 , & V_69 ) ;
return V_67 -> V_71 == NULL ? - V_72 : 0 ;
}
static void T_3 F_32 ( struct V_67 * V_67 )
{
F_33 ( V_67 -> V_71 ) ;
V_67 -> V_71 = NULL ;
}
static int T_4 F_34 ( void )
{
return F_35 ( & V_73 ) ;
}
static void T_5 F_36 ( void )
{
F_37 ( & V_73 ) ;
}
