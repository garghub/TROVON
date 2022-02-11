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
int F_8 ( struct V_27 * V_28 , struct V_6 * V_1 ,
struct V_7 * V_8 , int V_9 )
{
struct V_29 * V_30 ;
struct V_31 * V_32 ;
unsigned int V_26 ;
int V_33 = 0 ;
if ( ! F_9 ( V_28 , V_34 ) ) {
F_10 ( V_8 , V_9 , 0 ) ;
return 0 ;
}
F_11 () ;
V_32 = F_12 ( V_1 -> V_31 ) ;
V_26 = V_32 ? V_32 -> V_26 * sizeof( struct V_35 ) : 0 ;
V_30 = F_10 ( V_8 , V_9 , V_26 ) ;
if ( V_30 == NULL ) {
V_33 = - V_36 ;
goto V_37;
}
if ( V_32 ) {
struct V_35 * V_38 = (struct V_35 * ) F_13 ( V_30 ) ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_32 -> V_26 ; V_39 ++ , V_38 ++ )
F_14 ( & V_32 -> V_40 [ V_39 ] , V_38 ) ;
}
V_37:
F_15 () ;
return V_33 ;
}
void F_16 ( int (* F_17)( struct V_7 * V_8 , struct V_41 * V_42 ) )
{
F_18 ( & V_43 ) ;
V_44 = F_17 ;
F_19 ( & V_43 ) ;
}
void F_20 ( int (* F_17)( struct V_7 * V_8 , struct V_41 * V_42 ) )
{
F_18 ( & V_43 ) ;
V_44 = NULL ;
F_19 ( & V_43 ) ;
}
int F_21 ( const struct V_45 * V_46 )
{
int V_33 = 0 ;
if ( V_46 -> V_47 >= V_48 )
return - V_49 ;
F_18 ( & V_43 ) ;
if ( V_50 [ V_46 -> V_47 ] )
V_33 = - V_51 ;
else
V_50 [ V_46 -> V_47 ] = V_46 ;
F_19 ( & V_43 ) ;
return V_33 ;
}
void F_22 ( const struct V_45 * V_52 )
{
int V_47 = V_52 -> V_47 ;
if ( V_47 >= V_48 )
return;
F_18 ( & V_43 ) ;
F_23 ( V_50 [ V_47 ] != V_52 ) ;
V_50 [ V_47 ] = NULL ;
F_19 ( & V_43 ) ;
}
static int F_24 ( struct V_7 * V_8 , struct V_41 * V_42 )
{
int V_33 ;
struct V_53 * V_54 = F_25 ( V_42 ) ;
const struct V_45 * V_46 ;
if ( F_26 ( V_42 ) < sizeof( * V_54 ) )
return - V_49 ;
if ( V_54 -> V_55 >= V_48 )
return - V_49 ;
if ( V_50 [ V_54 -> V_55 ] == NULL )
F_27 ( L_1 , V_56 ,
V_57 , V_54 -> V_55 ) ;
F_18 ( & V_43 ) ;
V_46 = V_50 [ V_54 -> V_55 ] ;
if ( V_46 == NULL )
V_33 = - V_58 ;
else
V_33 = V_46 -> V_59 ( V_8 , V_42 ) ;
F_19 ( & V_43 ) ;
return V_33 ;
}
static int F_28 ( struct V_7 * V_8 , struct V_41 * V_42 )
{
int V_60 ;
switch ( V_42 -> V_61 ) {
case V_62 :
case V_63 :
if ( V_44 == NULL )
F_27 ( L_1 , V_56 ,
V_57 , V_64 ) ;
F_18 ( & V_43 ) ;
if ( V_44 != NULL )
V_60 = V_44 ( V_8 , V_42 ) ;
else
V_60 = - V_65 ;
F_19 ( & V_43 ) ;
return V_60 ;
case V_66 :
return F_24 ( V_8 , V_42 ) ;
default:
return - V_49 ;
}
}
static void F_29 ( struct V_7 * V_8 )
{
F_18 ( & V_67 ) ;
F_30 ( V_8 , & F_28 ) ;
F_19 ( & V_67 ) ;
}
static int T_2 F_31 ( struct V_68 * V_68 )
{
struct V_69 V_70 = {
. V_71 = F_29 ,
} ;
V_68 -> V_72 = F_32 ( V_68 , V_57 , & V_70 ) ;
return V_68 -> V_72 == NULL ? - V_73 : 0 ;
}
static void T_3 F_33 ( struct V_68 * V_68 )
{
F_34 ( V_68 -> V_72 ) ;
V_68 -> V_72 = NULL ;
}
static int T_4 F_35 ( void )
{
return F_36 ( & V_74 ) ;
}
static void T_5 F_37 ( void )
{
F_38 ( & V_74 ) ;
}
