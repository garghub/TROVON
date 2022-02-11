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
V_13 [ V_30 ] = F_11 ( & V_2 -> V_31 ) ;
return F_12 ( V_11 , V_12 , sizeof( V_13 ) , & V_13 ) ;
}
int F_13 ( bool V_32 , struct V_1 * V_2 ,
struct V_10 * V_11 , int V_12 )
{
struct V_33 * V_34 ;
struct V_35 * V_36 ;
struct V_37 * V_38 ;
unsigned int V_39 ;
int V_40 = 0 ;
if ( ! V_32 ) {
F_14 ( V_11 , V_12 , 0 ) ;
return 0 ;
}
F_15 () ;
V_36 = F_16 ( V_2 -> V_35 ) ;
if ( ! V_36 )
goto V_41;
V_34 = V_36 -> V_42 -> V_43 ;
if ( ! V_34 )
goto V_41;
V_39 = F_17 ( V_34 ) ;
V_38 = F_14 ( V_11 , V_12 , V_39 ) ;
if ( V_38 == NULL ) {
V_40 = - V_44 ;
goto V_41;
}
memcpy ( F_18 ( V_38 ) , V_34 -> V_36 , V_39 ) ;
V_41:
F_19 () ;
return V_40 ;
}
static T_3 F_20 ( void )
{
return F_21 ( sizeof( struct V_45 )
+ F_22 ( sizeof( V_46 ) )
+ F_23 ( sizeof( struct V_47 ) ) ) ;
}
static void F_24 ( struct V_48 * V_49 )
{
struct V_50 * V_51 =
F_25 ( V_49 , struct V_50 , V_49 ) ;
struct V_1 * V_2 = V_51 -> V_2 ;
const struct V_52 * V_53 ;
struct V_10 * V_11 ;
const enum V_54 V_55 = F_26 ( V_2 ) ;
int V_40 = - 1 ;
F_27 ( V_55 == V_56 ) ;
V_11 = F_28 ( F_20 () , V_57 ) ;
if ( ! V_11 )
goto V_41;
F_29 ( & V_58 ) ;
V_53 = V_59 [ V_2 -> V_60 ] ;
if ( V_53 && V_53 -> V_61 )
V_40 = V_53 -> V_61 ( V_11 , V_2 ) ;
F_30 ( & V_58 ) ;
if ( ! V_40 )
F_31 ( F_4 ( V_2 ) -> V_62 , V_11 , 0 , V_55 ,
V_57 ) ;
else
F_32 ( V_11 ) ;
V_41:
F_33 ( V_2 ) ;
F_34 ( V_51 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
struct V_50 * V_51 =
F_36 ( sizeof( struct V_50 ) , V_63 ) ;
if ( ! V_51 )
return F_33 ( V_2 ) ;
V_51 -> V_2 = V_2 ;
F_37 ( & V_51 -> V_49 , F_24 ) ;
F_38 ( V_64 , & V_51 -> V_49 ) ;
}
void F_39 ( int (* F_40)( struct V_10 * V_11 , struct V_65 * V_66 ) )
{
F_29 ( & V_58 ) ;
V_67 = F_40 ;
F_30 ( & V_58 ) ;
}
void F_41 ( int (* F_40)( struct V_10 * V_11 , struct V_65 * V_66 ) )
{
F_29 ( & V_58 ) ;
V_67 = NULL ;
F_30 ( & V_58 ) ;
}
int F_42 ( const struct V_52 * V_53 )
{
int V_40 = 0 ;
if ( V_53 -> V_68 >= V_69 )
return - V_70 ;
F_29 ( & V_58 ) ;
if ( V_59 [ V_53 -> V_68 ] )
V_40 = - V_71 ;
else
V_59 [ V_53 -> V_68 ] = V_53 ;
F_30 ( & V_58 ) ;
return V_40 ;
}
void F_43 ( const struct V_52 * V_72 )
{
int V_68 = V_72 -> V_68 ;
if ( V_68 >= V_69 )
return;
F_29 ( & V_58 ) ;
F_44 ( V_59 [ V_68 ] != V_72 ) ;
V_59 [ V_68 ] = NULL ;
F_30 ( & V_58 ) ;
}
static int F_45 ( struct V_10 * V_11 , struct V_65 * V_66 )
{
int V_40 ;
struct V_73 * V_74 = F_46 ( V_66 ) ;
const struct V_52 * V_53 ;
if ( F_47 ( V_66 ) < sizeof( * V_74 ) )
return - V_70 ;
if ( V_74 -> V_75 >= V_69 )
return - V_70 ;
if ( V_59 [ V_74 -> V_75 ] == NULL )
F_48 ( L_1 , V_76 ,
V_77 , V_74 -> V_75 ) ;
F_29 ( & V_58 ) ;
V_53 = V_59 [ V_74 -> V_75 ] ;
if ( V_53 == NULL )
V_40 = - V_78 ;
else if ( V_66 -> V_79 == V_80 )
V_40 = V_53 -> V_81 ( V_11 , V_66 ) ;
else if ( V_66 -> V_79 == V_82 && V_53 -> V_83 )
V_40 = V_53 -> V_83 ( V_11 , V_66 ) ;
else
V_40 = - V_84 ;
F_30 ( & V_58 ) ;
return V_40 ;
}
static int F_49 ( struct V_10 * V_11 , struct V_65 * V_66 )
{
int V_85 ;
switch ( V_66 -> V_79 ) {
case V_86 :
case V_87 :
if ( V_67 == NULL )
F_48 ( L_1 , V_76 ,
V_77 , V_88 ) ;
F_29 ( & V_58 ) ;
if ( V_67 != NULL )
V_85 = V_67 ( V_11 , V_66 ) ;
else
V_85 = - V_84 ;
F_30 ( & V_58 ) ;
return V_85 ;
case V_80 :
case V_82 :
return F_45 ( V_11 , V_66 ) ;
default:
return - V_70 ;
}
}
static void F_50 ( struct V_10 * V_11 )
{
F_29 ( & V_89 ) ;
F_51 ( V_11 , & F_49 ) ;
F_30 ( & V_89 ) ;
}
static int F_52 ( struct V_90 * V_90 , int V_55 )
{
switch ( V_55 ) {
case V_91 :
case V_92 :
if ( ! V_59 [ V_88 ] )
F_48 ( L_1 , V_76 ,
V_77 , V_88 ) ;
break;
case V_93 :
case V_94 :
if ( ! V_59 [ V_95 ] )
F_48 ( L_1 , V_76 ,
V_77 , V_88 ) ;
break;
}
return 0 ;
}
int F_53 ( struct V_1 * V_2 , int V_40 )
{
if ( ! F_54 ( F_4 ( V_2 ) -> V_96 , V_97 ) )
return - V_98 ;
if ( ! V_2 -> V_99 -> V_100 )
return - V_84 ;
return V_2 -> V_99 -> V_100 ( V_2 , V_40 ) ;
}
static int T_4 F_55 ( struct V_90 * V_90 )
{
struct V_101 V_102 = {
. V_103 = V_104 ,
. V_105 = F_50 ,
. V_106 = F_52 ,
. V_107 = V_108 ,
} ;
V_90 -> V_62 = F_56 ( V_90 , V_77 , & V_102 ) ;
return V_90 -> V_62 == NULL ? - V_109 : 0 ;
}
static void T_5 F_57 ( struct V_90 * V_90 )
{
F_58 ( V_90 -> V_62 ) ;
V_90 -> V_62 = NULL ;
}
static int T_6 F_59 ( void )
{
V_64 = F_60 ( L_2 , 0 , 0 ) ;
F_44 ( ! V_64 ) ;
return F_61 ( & V_110 ) ;
}
