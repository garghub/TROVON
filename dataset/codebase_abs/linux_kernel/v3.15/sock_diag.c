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
V_29 = V_31 -> V_37 ;
V_34 = F_12 ( V_29 ) ;
V_33 = F_9 ( V_8 , V_9 , V_34 ) ;
if ( V_33 == NULL ) {
V_35 = - V_38 ;
goto V_36;
}
memcpy ( F_13 ( V_33 ) , V_29 -> V_31 , V_34 ) ;
V_36:
F_14 () ;
return V_35 ;
}
void F_15 ( int (* F_16)( struct V_7 * V_8 , struct V_39 * V_40 ) )
{
F_17 ( & V_41 ) ;
V_42 = F_16 ;
F_18 ( & V_41 ) ;
}
void F_19 ( int (* F_16)( struct V_7 * V_8 , struct V_39 * V_40 ) )
{
F_17 ( & V_41 ) ;
V_42 = NULL ;
F_18 ( & V_41 ) ;
}
int F_20 ( const struct V_43 * V_44 )
{
int V_35 = 0 ;
if ( V_44 -> V_45 >= V_46 )
return - V_47 ;
F_17 ( & V_41 ) ;
if ( V_48 [ V_44 -> V_45 ] )
V_35 = - V_49 ;
else
V_48 [ V_44 -> V_45 ] = V_44 ;
F_18 ( & V_41 ) ;
return V_35 ;
}
void F_21 ( const struct V_43 * V_50 )
{
int V_45 = V_50 -> V_45 ;
if ( V_45 >= V_46 )
return;
F_17 ( & V_41 ) ;
F_22 ( V_48 [ V_45 ] != V_50 ) ;
V_48 [ V_45 ] = NULL ;
F_18 ( & V_41 ) ;
}
static int F_23 ( struct V_7 * V_8 , struct V_39 * V_40 )
{
int V_35 ;
struct V_51 * V_52 = F_24 ( V_40 ) ;
const struct V_43 * V_44 ;
if ( F_25 ( V_40 ) < sizeof( * V_52 ) )
return - V_47 ;
if ( V_52 -> V_53 >= V_46 )
return - V_47 ;
if ( V_48 [ V_52 -> V_53 ] == NULL )
F_26 ( L_1 , V_54 ,
V_55 , V_52 -> V_53 ) ;
F_17 ( & V_41 ) ;
V_44 = V_48 [ V_52 -> V_53 ] ;
if ( V_44 == NULL )
V_35 = - V_56 ;
else
V_35 = V_44 -> V_57 ( V_8 , V_40 ) ;
F_18 ( & V_41 ) ;
return V_35 ;
}
static int F_27 ( struct V_7 * V_8 , struct V_39 * V_40 )
{
int V_58 ;
switch ( V_40 -> V_59 ) {
case V_60 :
case V_61 :
if ( V_42 == NULL )
F_26 ( L_1 , V_54 ,
V_55 , V_62 ) ;
F_17 ( & V_41 ) ;
if ( V_42 != NULL )
V_58 = V_42 ( V_8 , V_40 ) ;
else
V_58 = - V_63 ;
F_18 ( & V_41 ) ;
return V_58 ;
case V_64 :
return F_23 ( V_8 , V_40 ) ;
default:
return - V_47 ;
}
}
static void F_28 ( struct V_7 * V_8 )
{
F_17 ( & V_65 ) ;
F_29 ( V_8 , & F_27 ) ;
F_18 ( & V_65 ) ;
}
static int T_2 F_30 ( struct V_66 * V_66 )
{
struct V_67 V_68 = {
. V_69 = F_28 ,
} ;
V_66 -> V_70 = F_31 ( V_66 , V_55 , & V_68 ) ;
return V_66 -> V_70 == NULL ? - V_71 : 0 ;
}
static void T_3 F_32 ( struct V_66 * V_66 )
{
F_33 ( V_66 -> V_70 ) ;
V_66 -> V_70 = NULL ;
}
static int T_4 F_34 ( void )
{
return F_35 ( & V_72 ) ;
}
static void T_5 F_36 ( void )
{
F_37 ( & V_72 ) ;
}
