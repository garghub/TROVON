static T_1 F_1 ( struct V_1 * V_2 )
{
while ( 1 ) {
T_1 V_3 = F_2 ( & V_2 -> V_4 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_3 ( & F_4 ( V_2 ) -> V_5 ) ;
F_5 ( & V_2 -> V_4 , 0 , V_3 ) ;
}
}
int F_6 ( struct V_1 * V_2 , const T_2 * V_6 )
{
T_1 V_3 ;
if ( V_6 [ 0 ] == V_7 && V_6 [ 1 ] == V_7 )
return 0 ;
V_3 = F_1 ( V_2 ) ;
if ( ( V_8 ) V_3 != V_6 [ 0 ] || ( V_8 ) ( V_3 >> 32 ) != V_6 [ 1 ] )
return - V_9 ;
return 0 ;
}
void F_7 ( struct V_1 * V_2 , T_2 * V_6 )
{
T_1 V_3 = F_1 ( V_2 ) ;
V_6 [ 0 ] = ( V_8 ) V_3 ;
V_6 [ 1 ] = ( V_8 ) ( V_3 >> 32 ) ;
}
int F_8 ( struct V_1 * V_2 , struct V_10 * V_11 , int V_12 )
{
V_8 V_13 [ V_14 ] ;
V_13 [ V_15 ] = F_9 ( V_2 ) ;
V_13 [ V_16 ] = V_2 -> V_17 ;
V_13 [ V_18 ] = F_10 ( V_2 ) ;
V_13 [ V_19 ] = V_2 -> V_20 ;
V_13 [ V_21 ] = V_2 -> V_22 ;
V_13 [ V_23 ] = V_2 -> V_24 ;
V_13 [ V_25 ] = F_11 ( & V_2 -> V_26 ) ;
V_13 [ V_27 ] = V_2 -> V_28 . V_29 ;
return F_12 ( V_11 , V_12 , sizeof( V_13 ) , & V_13 ) ;
}
int F_13 ( bool V_30 , struct V_1 * V_2 ,
struct V_10 * V_11 , int V_12 )
{
struct V_31 * V_32 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
unsigned int V_37 ;
int V_38 = 0 ;
if ( ! V_30 ) {
F_14 ( V_11 , V_12 , 0 ) ;
return 0 ;
}
F_15 () ;
V_34 = F_16 ( V_2 -> V_33 ) ;
if ( ! V_34 )
goto V_39;
V_32 = V_34 -> V_40 -> V_41 ;
V_37 = F_17 ( V_32 ) ;
V_36 = F_14 ( V_11 , V_12 , V_37 ) ;
if ( V_36 == NULL ) {
V_38 = - V_42 ;
goto V_39;
}
memcpy ( F_18 ( V_36 ) , V_32 -> V_34 , V_37 ) ;
V_39:
F_19 () ;
return V_38 ;
}
void F_20 ( int (* F_21)( struct V_10 * V_11 , struct V_43 * V_44 ) )
{
F_22 ( & V_45 ) ;
V_46 = F_21 ;
F_23 ( & V_45 ) ;
}
void F_24 ( int (* F_21)( struct V_10 * V_11 , struct V_43 * V_44 ) )
{
F_22 ( & V_45 ) ;
V_46 = NULL ;
F_23 ( & V_45 ) ;
}
int F_25 ( const struct V_47 * V_48 )
{
int V_38 = 0 ;
if ( V_48 -> V_49 >= V_50 )
return - V_51 ;
F_22 ( & V_45 ) ;
if ( V_52 [ V_48 -> V_49 ] )
V_38 = - V_53 ;
else
V_52 [ V_48 -> V_49 ] = V_48 ;
F_23 ( & V_45 ) ;
return V_38 ;
}
void F_26 ( const struct V_47 * V_54 )
{
int V_49 = V_54 -> V_49 ;
if ( V_49 >= V_50 )
return;
F_22 ( & V_45 ) ;
F_27 ( V_52 [ V_49 ] != V_54 ) ;
V_52 [ V_49 ] = NULL ;
F_23 ( & V_45 ) ;
}
static int F_28 ( struct V_10 * V_11 , struct V_43 * V_44 )
{
int V_38 ;
struct V_55 * V_56 = F_29 ( V_44 ) ;
const struct V_47 * V_48 ;
if ( F_30 ( V_44 ) < sizeof( * V_56 ) )
return - V_51 ;
if ( V_56 -> V_57 >= V_50 )
return - V_51 ;
if ( V_52 [ V_56 -> V_57 ] == NULL )
F_31 ( L_1 , V_58 ,
V_59 , V_56 -> V_57 ) ;
F_22 ( & V_45 ) ;
V_48 = V_52 [ V_56 -> V_57 ] ;
if ( V_48 == NULL )
V_38 = - V_60 ;
else
V_38 = V_48 -> V_61 ( V_11 , V_44 ) ;
F_23 ( & V_45 ) ;
return V_38 ;
}
static int F_32 ( struct V_10 * V_11 , struct V_43 * V_44 )
{
int V_62 ;
switch ( V_44 -> V_63 ) {
case V_64 :
case V_65 :
if ( V_46 == NULL )
F_31 ( L_1 , V_58 ,
V_59 , V_66 ) ;
F_22 ( & V_45 ) ;
if ( V_46 != NULL )
V_62 = V_46 ( V_11 , V_44 ) ;
else
V_62 = - V_67 ;
F_23 ( & V_45 ) ;
return V_62 ;
case V_68 :
return F_28 ( V_11 , V_44 ) ;
default:
return - V_51 ;
}
}
static void F_33 ( struct V_10 * V_11 )
{
F_22 ( & V_69 ) ;
F_34 ( V_11 , & F_32 ) ;
F_23 ( & V_69 ) ;
}
static int T_3 F_35 ( struct V_70 * V_70 )
{
struct V_71 V_72 = {
. V_73 = F_33 ,
} ;
V_70 -> V_74 = F_36 ( V_70 , V_59 , & V_72 ) ;
return V_70 -> V_74 == NULL ? - V_75 : 0 ;
}
static void T_4 F_37 ( struct V_70 * V_70 )
{
F_38 ( V_70 -> V_74 ) ;
V_70 -> V_74 = NULL ;
}
static int T_5 F_39 ( void )
{
return F_40 ( & V_76 ) ;
}
static void T_6 F_41 ( void )
{
F_42 ( & V_76 ) ;
}
