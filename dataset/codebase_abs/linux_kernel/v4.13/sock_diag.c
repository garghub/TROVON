T_1 F_1 ( struct V_1 * V_2 )
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
F_9 ( V_2 , V_13 ) ;
return F_10 ( V_11 , V_12 , sizeof( V_13 ) , & V_13 ) ;
}
int F_11 ( bool V_15 , struct V_1 * V_2 ,
struct V_10 * V_11 , int V_12 )
{
struct V_16 * V_17 ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
unsigned int V_22 ;
int V_23 = 0 ;
if ( ! V_15 ) {
F_12 ( V_11 , V_12 , 0 ) ;
return 0 ;
}
F_13 () ;
V_19 = F_14 ( V_2 -> V_18 ) ;
if ( ! V_19 )
goto V_24;
V_17 = V_19 -> V_25 -> V_26 ;
if ( ! V_17 )
goto V_24;
V_22 = F_15 ( V_17 ) ;
V_21 = F_12 ( V_11 , V_12 , V_22 ) ;
if ( V_21 == NULL ) {
V_23 = - V_27 ;
goto V_24;
}
memcpy ( F_16 ( V_21 ) , V_17 -> V_19 , V_22 ) ;
V_24:
F_17 () ;
return V_23 ;
}
static T_3 F_18 ( void )
{
return F_19 ( sizeof( struct V_28 )
+ F_20 ( sizeof( V_29 ) )
+ F_21 ( sizeof( struct V_30 ) ) ) ;
}
static void F_22 ( struct V_31 * V_32 )
{
struct V_33 * V_34 =
F_23 ( V_32 , struct V_33 , V_32 ) ;
struct V_1 * V_2 = V_34 -> V_2 ;
const struct V_35 * V_36 ;
struct V_10 * V_11 ;
const enum V_37 V_38 = F_24 ( V_2 ) ;
int V_23 = - 1 ;
F_25 ( V_38 == V_39 ) ;
V_11 = F_26 ( F_18 () , V_40 ) ;
if ( ! V_11 )
goto V_24;
F_27 ( & V_41 ) ;
V_36 = V_42 [ V_2 -> V_43 ] ;
if ( V_36 && V_36 -> V_44 )
V_23 = V_36 -> V_44 ( V_11 , V_2 ) ;
F_28 ( & V_41 ) ;
if ( ! V_23 )
F_29 ( F_4 ( V_2 ) -> V_45 , V_11 , 0 , V_38 ,
V_40 ) ;
else
F_30 ( V_11 ) ;
V_24:
F_31 ( V_2 ) ;
F_32 ( V_34 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
struct V_33 * V_34 =
F_34 ( sizeof( struct V_33 ) , V_46 ) ;
if ( ! V_34 )
return F_31 ( V_2 ) ;
V_34 -> V_2 = V_2 ;
F_35 ( & V_34 -> V_32 , F_22 ) ;
F_36 ( V_47 , & V_34 -> V_32 ) ;
}
void F_37 ( int (* F_38)( struct V_10 * V_11 , struct V_48 * V_49 ) )
{
F_27 ( & V_41 ) ;
V_50 = F_38 ;
F_28 ( & V_41 ) ;
}
void F_39 ( int (* F_38)( struct V_10 * V_11 , struct V_48 * V_49 ) )
{
F_27 ( & V_41 ) ;
V_50 = NULL ;
F_28 ( & V_41 ) ;
}
int F_40 ( const struct V_35 * V_36 )
{
int V_23 = 0 ;
if ( V_36 -> V_51 >= V_52 )
return - V_53 ;
F_27 ( & V_41 ) ;
if ( V_42 [ V_36 -> V_51 ] )
V_23 = - V_54 ;
else
V_42 [ V_36 -> V_51 ] = V_36 ;
F_28 ( & V_41 ) ;
return V_23 ;
}
void F_41 ( const struct V_35 * V_55 )
{
int V_51 = V_55 -> V_51 ;
if ( V_51 >= V_52 )
return;
F_27 ( & V_41 ) ;
F_42 ( V_42 [ V_51 ] != V_55 ) ;
V_42 [ V_51 ] = NULL ;
F_28 ( & V_41 ) ;
}
static int F_43 ( struct V_10 * V_11 , struct V_48 * V_49 )
{
int V_23 ;
struct V_56 * V_57 = F_44 ( V_49 ) ;
const struct V_35 * V_36 ;
if ( F_45 ( V_49 ) < sizeof( * V_57 ) )
return - V_53 ;
if ( V_57 -> V_58 >= V_52 )
return - V_53 ;
if ( V_42 [ V_57 -> V_58 ] == NULL )
F_46 ( L_1 , V_59 ,
V_60 , V_57 -> V_58 ) ;
F_27 ( & V_41 ) ;
V_36 = V_42 [ V_57 -> V_58 ] ;
if ( V_36 == NULL )
V_23 = - V_61 ;
else if ( V_49 -> V_62 == V_63 )
V_23 = V_36 -> V_64 ( V_11 , V_49 ) ;
else if ( V_49 -> V_62 == V_65 && V_36 -> V_66 )
V_23 = V_36 -> V_66 ( V_11 , V_49 ) ;
else
V_23 = - V_67 ;
F_28 ( & V_41 ) ;
return V_23 ;
}
static int F_47 ( struct V_10 * V_11 , struct V_48 * V_49 ,
struct V_68 * V_69 )
{
int V_70 ;
switch ( V_49 -> V_62 ) {
case V_71 :
case V_72 :
if ( V_50 == NULL )
F_46 ( L_1 , V_59 ,
V_60 , V_73 ) ;
F_27 ( & V_41 ) ;
if ( V_50 != NULL )
V_70 = V_50 ( V_11 , V_49 ) ;
else
V_70 = - V_67 ;
F_28 ( & V_41 ) ;
return V_70 ;
case V_63 :
case V_65 :
return F_43 ( V_11 , V_49 ) ;
default:
return - V_53 ;
}
}
static void F_48 ( struct V_10 * V_11 )
{
F_27 ( & V_74 ) ;
F_49 ( V_11 , & F_47 ) ;
F_28 ( & V_74 ) ;
}
static int F_50 ( struct V_75 * V_75 , int V_38 )
{
switch ( V_38 ) {
case V_76 :
case V_77 :
if ( ! V_42 [ V_73 ] )
F_46 ( L_1 , V_59 ,
V_60 , V_73 ) ;
break;
case V_78 :
case V_79 :
if ( ! V_42 [ V_80 ] )
F_46 ( L_1 , V_59 ,
V_60 , V_73 ) ;
break;
}
return 0 ;
}
int F_51 ( struct V_1 * V_2 , int V_23 )
{
if ( ! F_52 ( F_4 ( V_2 ) -> V_81 , V_82 ) )
return - V_83 ;
if ( ! V_2 -> V_84 -> V_85 )
return - V_67 ;
return V_2 -> V_84 -> V_85 ( V_2 , V_23 ) ;
}
static int T_4 F_53 ( struct V_75 * V_75 )
{
struct V_86 V_87 = {
. V_88 = V_89 ,
. V_90 = F_48 ,
. V_91 = F_50 ,
. V_92 = V_93 ,
} ;
V_75 -> V_45 = F_54 ( V_75 , V_60 , & V_87 ) ;
return V_75 -> V_45 == NULL ? - V_94 : 0 ;
}
static void T_5 F_55 ( struct V_75 * V_75 )
{
F_56 ( V_75 -> V_45 ) ;
V_75 -> V_45 = NULL ;
}
static int T_6 F_57 ( void )
{
V_47 = F_58 ( L_2 , 0 , 0 ) ;
F_42 ( ! V_47 ) ;
return F_59 ( & V_95 ) ;
}
