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
if ( ! V_32 )
goto V_39;
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
static T_3 F_20 ( void )
{
return F_21 ( sizeof( struct V_43 )
+ F_22 ( sizeof( V_44 ) )
+ F_22 ( sizeof( struct V_45 ) ) ) ;
}
static void F_23 ( struct V_46 * V_47 )
{
struct V_48 * V_49 =
F_24 ( V_47 , struct V_48 , V_47 ) ;
struct V_1 * V_2 = V_49 -> V_2 ;
const struct V_50 * V_51 ;
struct V_10 * V_11 ;
const enum V_52 V_53 = F_25 ( V_2 ) ;
int V_38 = - 1 ;
F_26 ( V_53 == V_54 ) ;
V_11 = F_27 ( F_20 () , V_55 ) ;
if ( ! V_11 )
goto V_39;
F_28 ( & V_56 ) ;
V_51 = V_57 [ V_2 -> V_58 ] ;
if ( V_51 && V_51 -> V_59 )
V_38 = V_51 -> V_59 ( V_11 , V_2 ) ;
F_29 ( & V_56 ) ;
if ( ! V_38 )
F_30 ( F_4 ( V_2 ) -> V_60 , V_11 , 0 , V_53 ,
V_55 ) ;
else
F_31 ( V_11 ) ;
V_39:
F_32 ( V_2 ) ;
F_33 ( V_49 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_48 * V_49 =
F_35 ( sizeof( struct V_48 ) , V_61 ) ;
if ( ! V_49 )
return F_32 ( V_2 ) ;
V_49 -> V_2 = V_2 ;
F_36 ( & V_49 -> V_47 , F_23 ) ;
F_37 ( V_62 , & V_49 -> V_47 ) ;
}
void F_38 ( int (* F_39)( struct V_10 * V_11 , struct V_63 * V_64 ) )
{
F_28 ( & V_56 ) ;
V_65 = F_39 ;
F_29 ( & V_56 ) ;
}
void F_40 ( int (* F_39)( struct V_10 * V_11 , struct V_63 * V_64 ) )
{
F_28 ( & V_56 ) ;
V_65 = NULL ;
F_29 ( & V_56 ) ;
}
int F_41 ( const struct V_50 * V_51 )
{
int V_38 = 0 ;
if ( V_51 -> V_66 >= V_67 )
return - V_68 ;
F_28 ( & V_56 ) ;
if ( V_57 [ V_51 -> V_66 ] )
V_38 = - V_69 ;
else
V_57 [ V_51 -> V_66 ] = V_51 ;
F_29 ( & V_56 ) ;
return V_38 ;
}
void F_42 ( const struct V_50 * V_70 )
{
int V_66 = V_70 -> V_66 ;
if ( V_66 >= V_67 )
return;
F_28 ( & V_56 ) ;
F_43 ( V_57 [ V_66 ] != V_70 ) ;
V_57 [ V_66 ] = NULL ;
F_29 ( & V_56 ) ;
}
static int F_44 ( struct V_10 * V_11 , struct V_63 * V_64 )
{
int V_38 ;
struct V_71 * V_72 = F_45 ( V_64 ) ;
const struct V_50 * V_51 ;
if ( F_46 ( V_64 ) < sizeof( * V_72 ) )
return - V_68 ;
if ( V_72 -> V_73 >= V_67 )
return - V_68 ;
if ( V_57 [ V_72 -> V_73 ] == NULL )
F_47 ( L_1 , V_74 ,
V_75 , V_72 -> V_73 ) ;
F_28 ( & V_56 ) ;
V_51 = V_57 [ V_72 -> V_73 ] ;
if ( V_51 == NULL )
V_38 = - V_76 ;
else
V_38 = V_51 -> V_77 ( V_11 , V_64 ) ;
F_29 ( & V_56 ) ;
return V_38 ;
}
static int F_48 ( struct V_10 * V_11 , struct V_63 * V_64 )
{
int V_78 ;
switch ( V_64 -> V_79 ) {
case V_80 :
case V_81 :
if ( V_65 == NULL )
F_47 ( L_1 , V_74 ,
V_75 , V_82 ) ;
F_28 ( & V_56 ) ;
if ( V_65 != NULL )
V_78 = V_65 ( V_11 , V_64 ) ;
else
V_78 = - V_83 ;
F_29 ( & V_56 ) ;
return V_78 ;
case V_84 :
return F_44 ( V_11 , V_64 ) ;
default:
return - V_68 ;
}
}
static void F_49 ( struct V_10 * V_11 )
{
F_28 ( & V_85 ) ;
F_50 ( V_11 , & F_48 ) ;
F_29 ( & V_85 ) ;
}
static int F_51 ( struct V_86 * V_86 , int V_53 )
{
switch ( V_53 ) {
case V_87 :
case V_88 :
if ( ! V_57 [ V_82 ] )
F_47 ( L_1 , V_74 ,
V_75 , V_82 ) ;
break;
case V_89 :
case V_90 :
if ( ! V_57 [ V_91 ] )
F_47 ( L_1 , V_74 ,
V_75 , V_82 ) ;
break;
}
return 0 ;
}
static int T_4 F_52 ( struct V_86 * V_86 )
{
struct V_92 V_93 = {
. V_94 = V_95 ,
. V_96 = F_49 ,
. V_97 = F_51 ,
. V_98 = V_99 ,
} ;
V_86 -> V_60 = F_53 ( V_86 , V_75 , & V_93 ) ;
return V_86 -> V_60 == NULL ? - V_100 : 0 ;
}
static void T_5 F_54 ( struct V_86 * V_86 )
{
F_55 ( V_86 -> V_60 ) ;
V_86 -> V_60 = NULL ;
}
static int T_6 F_56 ( void )
{
V_62 = F_57 ( L_2 , 0 , 0 ) ;
F_43 ( ! V_62 ) ;
return F_58 ( & V_101 ) ;
}
static void T_7 F_59 ( void )
{
F_60 ( & V_101 ) ;
F_61 ( V_62 ) ;
}
