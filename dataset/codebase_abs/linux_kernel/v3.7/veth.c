static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> V_5 = 0 ;
V_4 -> V_6 = 0 ;
F_2 ( V_4 , V_7 ) ;
V_4 -> V_8 = V_9 ;
V_4 -> V_10 = V_11 ;
V_4 -> V_12 = 0 ;
V_4 -> V_13 = V_14 ;
V_4 -> V_15 = V_16 ;
V_4 -> V_17 = 0 ;
V_4 -> V_18 = 0 ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
F_4 ( V_20 -> V_21 , V_22 , sizeof( V_20 -> V_21 ) ) ;
F_4 ( V_20 -> V_23 , V_24 , sizeof( V_20 -> V_23 ) ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_25 , T_2 * V_26 )
{
switch( V_25 ) {
case V_27 :
memcpy ( V_26 , & V_28 , sizeof( V_28 ) ) ;
break;
}
}
static int F_6 ( struct V_1 * V_2 , int V_29 )
{
switch ( V_29 ) {
case V_27 :
return F_7 ( V_28 ) ;
default:
return - V_30 ;
}
}
static void F_8 ( struct V_1 * V_2 ,
struct V_31 * V_32 , T_3 * V_33 )
{
struct V_34 * V_35 ;
V_35 = F_9 ( V_2 ) ;
V_33 [ 0 ] = V_35 -> V_36 -> V_37 ;
}
static T_4 F_10 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
struct V_1 * V_40 = NULL ;
struct V_34 * V_35 , * V_41 ;
struct V_42 * V_32 , * V_43 ;
int V_44 ;
V_35 = F_9 ( V_2 ) ;
V_40 = V_35 -> V_36 ;
V_41 = F_9 ( V_40 ) ;
V_32 = F_11 ( V_35 -> V_32 ) ;
V_43 = F_11 ( V_41 -> V_32 ) ;
if ( V_39 -> V_45 == V_46 &&
V_40 -> V_47 & V_48 )
V_39 -> V_45 = V_49 ;
V_44 = V_39 -> V_50 ;
if ( F_12 ( V_40 , V_39 ) != V_51 )
goto V_52;
F_13 ( & V_32 -> V_53 ) ;
V_32 -> V_54 += V_44 ;
V_32 -> V_55 ++ ;
F_14 ( & V_32 -> V_53 ) ;
F_13 ( & V_43 -> V_53 ) ;
V_43 -> V_56 += V_44 ;
V_43 -> V_57 ++ ;
F_14 ( & V_43 -> V_53 ) ;
return V_58 ;
V_52:
F_13 ( & V_43 -> V_53 ) ;
V_43 -> V_59 ++ ;
F_14 ( & V_43 -> V_53 ) ;
return V_58 ;
}
static struct V_60 * F_15 ( struct V_1 * V_2 ,
struct V_60 * V_61 )
{
struct V_34 * V_35 = F_9 ( V_2 ) ;
int V_62 ;
F_16 (cpu) {
struct V_42 * V_32 = F_17 ( V_35 -> V_32 , V_62 ) ;
T_3 V_57 , V_56 , V_59 ;
T_3 V_55 , V_54 ;
unsigned int V_63 ;
do {
V_63 = F_18 ( & V_32 -> V_53 ) ;
V_57 = V_32 -> V_57 ;
V_55 = V_32 -> V_55 ;
V_56 = V_32 -> V_56 ;
V_54 = V_32 -> V_54 ;
V_59 = V_32 -> V_59 ;
} while ( F_19 ( & V_32 -> V_53 , V_63 ) );
V_61 -> V_57 += V_57 ;
V_61 -> V_55 += V_55 ;
V_61 -> V_56 += V_56 ;
V_61 -> V_54 += V_54 ;
V_61 -> V_59 += V_59 ;
}
return V_61 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
V_35 = F_9 ( V_2 ) ;
if ( V_35 -> V_36 == NULL )
return - V_64 ;
if ( V_35 -> V_36 -> V_65 & V_66 ) {
F_21 ( V_2 ) ;
F_21 ( V_35 -> V_36 ) ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = F_9 ( V_2 ) ;
F_23 ( V_2 ) ;
F_23 ( V_35 -> V_36 ) ;
return 0 ;
}
static int F_24 ( int V_67 )
{
return V_67 >= V_68 && V_67 <= V_69 ;
}
static int F_25 ( struct V_1 * V_2 , int V_67 )
{
if ( ! F_24 ( V_67 ) )
return - V_70 ;
V_2 -> V_71 = V_67 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_42 T_5 * V_32 ;
struct V_34 * V_35 ;
V_32 = F_27 ( struct V_42 ) ;
if ( V_32 == NULL )
return - V_72 ;
V_35 = F_9 ( V_2 ) ;
V_35 -> V_32 = V_32 ;
return 0 ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
V_35 = F_9 ( V_2 ) ;
F_29 ( V_35 -> V_32 ) ;
F_30 ( V_2 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_32 ( V_2 ) ;
V_2 -> V_73 &= ~ V_74 ;
V_2 -> V_75 = & V_76 ;
V_2 -> V_77 = & V_78 ;
V_2 -> V_47 |= V_79 ;
V_2 -> V_80 = F_28 ;
V_2 -> V_81 = V_82 | V_83 | V_48 ;
}
static int F_33 ( struct V_84 * V_85 [] , struct V_84 * V_33 [] )
{
if ( V_85 [ V_86 ] ) {
if ( F_34 ( V_85 [ V_86 ] ) != V_87 )
return - V_70 ;
if ( ! F_35 ( F_36 ( V_85 [ V_86 ] ) ) )
return - V_88 ;
}
if ( V_85 [ V_89 ] ) {
if ( ! F_24 ( F_37 ( V_85 [ V_89 ] ) ) )
return - V_70 ;
}
return 0 ;
}
static int F_38 ( struct V_90 * V_91 , struct V_1 * V_2 ,
struct V_84 * V_85 [] , struct V_84 * V_33 [] )
{
int V_92 ;
struct V_1 * V_36 ;
struct V_34 * V_35 ;
char V_93 [ V_94 ] ;
struct V_84 * V_95 [ V_96 + 1 ] , * * V_97 ;
struct V_98 * V_99 ;
struct V_90 * V_90 ;
if ( V_33 != NULL && V_33 [ V_100 ] != NULL ) {
struct V_84 * V_101 ;
V_101 = V_33 [ V_100 ] ;
V_99 = F_36 ( V_101 ) ;
V_92 = F_39 ( V_95 , V_96 ,
F_36 ( V_101 ) + sizeof( struct V_98 ) ,
F_34 ( V_101 ) - sizeof( struct V_98 ) ,
V_102 ) ;
if ( V_92 < 0 )
return V_92 ;
V_92 = F_33 ( V_95 , NULL ) ;
if ( V_92 < 0 )
return V_92 ;
V_97 = V_95 ;
} else {
V_99 = NULL ;
V_97 = V_85 ;
}
if ( V_97 [ V_103 ] )
F_40 ( V_93 , V_97 [ V_103 ] , V_94 ) ;
else
snprintf ( V_93 , V_94 , V_22 L_1 ) ;
V_90 = F_41 ( V_91 , V_97 ) ;
if ( F_42 ( V_90 ) )
return F_43 ( V_90 ) ;
V_36 = F_44 ( V_91 , V_90 , V_93 , & V_104 , V_97 ) ;
if ( F_42 ( V_36 ) ) {
F_45 ( V_90 ) ;
return F_43 ( V_36 ) ;
}
if ( V_97 [ V_86 ] == NULL )
F_46 ( V_36 ) ;
if ( V_99 && ( V_2 -> V_37 != 0 ) )
V_36 -> V_37 = V_99 -> V_105 ;
V_92 = F_47 ( V_36 ) ;
F_45 ( V_90 ) ;
V_90 = NULL ;
if ( V_92 < 0 )
goto V_106;
F_23 ( V_36 ) ;
V_92 = F_48 ( V_36 , V_99 ) ;
if ( V_92 < 0 )
goto V_107;
if ( V_85 [ V_86 ] == NULL )
F_46 ( V_2 ) ;
if ( V_85 [ V_103 ] )
F_40 ( V_2 -> V_108 , V_85 [ V_103 ] , V_94 ) ;
else
snprintf ( V_2 -> V_108 , V_94 , V_22 L_1 ) ;
if ( strchr ( V_2 -> V_108 , '%' ) ) {
V_92 = F_49 ( V_2 , V_2 -> V_108 ) ;
if ( V_92 < 0 )
goto V_109;
}
V_92 = F_47 ( V_2 ) ;
if ( V_92 < 0 )
goto V_110;
F_23 ( V_2 ) ;
V_35 = F_9 ( V_2 ) ;
V_35 -> V_36 = V_36 ;
V_35 = F_9 ( V_36 ) ;
V_35 -> V_36 = V_2 ;
return 0 ;
V_110:
V_109:
V_107:
F_50 ( V_36 ) ;
return V_92 ;
V_106:
F_30 ( V_36 ) ;
return V_92 ;
}
static void F_51 ( struct V_1 * V_2 , struct V_111 * V_112 )
{
struct V_34 * V_35 ;
struct V_1 * V_36 ;
V_35 = F_9 ( V_2 ) ;
V_36 = V_35 -> V_36 ;
F_52 ( V_2 , V_112 ) ;
F_52 ( V_36 , V_112 ) ;
}
static T_6 int F_53 ( void )
{
return F_54 ( & V_104 ) ;
}
static T_7 void F_55 ( void )
{
F_56 ( & V_104 ) ;
}
