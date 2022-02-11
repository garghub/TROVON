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
strcpy ( V_20 -> V_21 , V_22 ) ;
strcpy ( V_20 -> V_23 , V_24 ) ;
strcpy ( V_20 -> V_25 , L_1 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_26 , T_2 * V_27 )
{
switch( V_26 ) {
case V_28 :
memcpy ( V_27 , & V_29 , sizeof( V_29 ) ) ;
break;
}
}
static int F_5 ( struct V_1 * V_2 , int V_30 )
{
switch ( V_30 ) {
case V_28 :
return F_6 ( V_29 ) ;
default:
return - V_31 ;
}
}
static void F_7 ( struct V_1 * V_2 ,
struct V_32 * V_33 , T_3 * V_34 )
{
struct V_35 * V_36 ;
V_36 = F_8 ( V_2 ) ;
V_34 [ 0 ] = V_36 -> V_37 -> V_38 ;
}
static T_4 F_9 ( struct V_39 * V_40 , struct V_1 * V_2 )
{
struct V_1 * V_41 = NULL ;
struct V_35 * V_36 , * V_42 ;
struct V_43 * V_33 , * V_44 ;
int V_45 ;
V_36 = F_8 ( V_2 ) ;
V_41 = V_36 -> V_37 ;
V_42 = F_8 ( V_41 ) ;
V_33 = F_10 ( V_36 -> V_33 ) ;
V_44 = F_10 ( V_42 -> V_33 ) ;
if ( V_40 -> V_46 == V_47 &&
V_41 -> V_48 & V_49 )
V_40 -> V_46 = V_50 ;
V_45 = V_40 -> V_51 ;
if ( F_11 ( V_41 , V_40 ) != V_52 )
goto V_53;
F_12 ( & V_33 -> V_54 ) ;
V_33 -> V_55 += V_45 ;
V_33 -> V_56 ++ ;
F_13 ( & V_33 -> V_54 ) ;
F_12 ( & V_44 -> V_54 ) ;
V_44 -> V_57 += V_45 ;
V_44 -> V_58 ++ ;
F_13 ( & V_44 -> V_54 ) ;
return V_59 ;
V_53:
F_12 ( & V_44 -> V_54 ) ;
V_44 -> V_60 ++ ;
F_13 ( & V_44 -> V_54 ) ;
return V_59 ;
}
static struct V_61 * F_14 ( struct V_1 * V_2 ,
struct V_61 * V_62 )
{
struct V_35 * V_36 = F_8 ( V_2 ) ;
int V_63 ;
F_15 (cpu) {
struct V_43 * V_33 = F_16 ( V_36 -> V_33 , V_63 ) ;
T_3 V_58 , V_57 , V_60 ;
T_3 V_56 , V_55 ;
unsigned int V_64 ;
do {
V_64 = F_17 ( & V_33 -> V_54 ) ;
V_58 = V_33 -> V_58 ;
V_56 = V_33 -> V_56 ;
V_57 = V_33 -> V_57 ;
V_55 = V_33 -> V_55 ;
V_60 = V_33 -> V_60 ;
} while ( F_18 ( & V_33 -> V_54 , V_64 ) );
V_62 -> V_58 += V_58 ;
V_62 -> V_56 += V_56 ;
V_62 -> V_57 += V_57 ;
V_62 -> V_55 += V_55 ;
V_62 -> V_60 += V_60 ;
}
return V_62 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_35 * V_36 ;
V_36 = F_8 ( V_2 ) ;
if ( V_36 -> V_37 == NULL )
return - V_65 ;
if ( V_36 -> V_37 -> V_66 & V_67 ) {
F_20 ( V_2 ) ;
F_20 ( V_36 -> V_37 ) ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = F_8 ( V_2 ) ;
F_22 ( V_2 ) ;
F_22 ( V_36 -> V_37 ) ;
return 0 ;
}
static int F_23 ( int V_68 )
{
return V_68 >= V_69 && V_68 <= V_70 ;
}
static int F_24 ( struct V_1 * V_2 , int V_68 )
{
if ( ! F_23 ( V_68 ) )
return - V_71 ;
V_2 -> V_72 = V_68 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_43 T_5 * V_33 ;
struct V_35 * V_36 ;
V_33 = F_26 ( struct V_43 ) ;
if ( V_33 == NULL )
return - V_73 ;
V_36 = F_8 ( V_2 ) ;
V_36 -> V_33 = V_33 ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_35 * V_36 ;
V_36 = F_8 ( V_2 ) ;
F_28 ( V_36 -> V_33 ) ;
F_29 ( V_2 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_31 ( V_2 ) ;
V_2 -> V_74 &= ~ V_75 ;
V_2 -> V_76 = & V_77 ;
V_2 -> V_78 = & V_79 ;
V_2 -> V_48 |= V_80 ;
V_2 -> V_81 = F_27 ;
V_2 -> V_82 = V_83 | V_84 | V_49 ;
}
static int F_32 ( struct V_85 * V_86 [] , struct V_85 * V_34 [] )
{
if ( V_86 [ V_87 ] ) {
if ( F_33 ( V_86 [ V_87 ] ) != V_88 )
return - V_71 ;
if ( ! F_34 ( F_35 ( V_86 [ V_87 ] ) ) )
return - V_89 ;
}
if ( V_86 [ V_90 ] ) {
if ( ! F_23 ( F_36 ( V_86 [ V_90 ] ) ) )
return - V_71 ;
}
return 0 ;
}
static int F_37 ( struct V_91 * V_92 , struct V_1 * V_2 ,
struct V_85 * V_86 [] , struct V_85 * V_34 [] )
{
int V_93 ;
struct V_1 * V_37 ;
struct V_35 * V_36 ;
char V_94 [ V_95 ] ;
struct V_85 * V_96 [ V_97 + 1 ] , * * V_98 ;
struct V_99 * V_100 ;
struct V_91 * V_91 ;
if ( V_34 != NULL && V_34 [ V_101 ] != NULL ) {
struct V_85 * V_102 ;
V_102 = V_34 [ V_101 ] ;
V_100 = F_35 ( V_102 ) ;
V_93 = F_38 ( V_96 , V_97 ,
F_35 ( V_102 ) + sizeof( struct V_99 ) ,
F_33 ( V_102 ) - sizeof( struct V_99 ) ,
V_103 ) ;
if ( V_93 < 0 )
return V_93 ;
V_93 = F_32 ( V_96 , NULL ) ;
if ( V_93 < 0 )
return V_93 ;
V_98 = V_96 ;
} else {
V_100 = NULL ;
V_98 = V_86 ;
}
if ( V_98 [ V_104 ] )
F_39 ( V_94 , V_98 [ V_104 ] , V_95 ) ;
else
snprintf ( V_94 , V_95 , V_22 L_2 ) ;
V_91 = F_40 ( V_92 , V_98 ) ;
if ( F_41 ( V_91 ) )
return F_42 ( V_91 ) ;
V_37 = F_43 ( V_92 , V_91 , V_94 , & V_105 , V_98 ) ;
if ( F_41 ( V_37 ) ) {
F_44 ( V_91 ) ;
return F_42 ( V_37 ) ;
}
if ( V_98 [ V_87 ] == NULL )
F_45 ( V_37 -> V_106 ) ;
V_93 = F_46 ( V_37 ) ;
F_44 ( V_91 ) ;
V_91 = NULL ;
if ( V_93 < 0 )
goto V_107;
F_22 ( V_37 ) ;
V_93 = F_47 ( V_37 , V_100 ) ;
if ( V_93 < 0 )
goto V_108;
if ( V_86 [ V_87 ] == NULL )
F_45 ( V_2 -> V_106 ) ;
if ( V_86 [ V_104 ] )
F_39 ( V_2 -> V_109 , V_86 [ V_104 ] , V_95 ) ;
else
snprintf ( V_2 -> V_109 , V_95 , V_22 L_2 ) ;
if ( strchr ( V_2 -> V_109 , '%' ) ) {
V_93 = F_48 ( V_2 , V_2 -> V_109 ) ;
if ( V_93 < 0 )
goto V_110;
}
V_93 = F_46 ( V_2 ) ;
if ( V_93 < 0 )
goto V_111;
F_22 ( V_2 ) ;
V_36 = F_8 ( V_2 ) ;
V_36 -> V_37 = V_37 ;
V_36 = F_8 ( V_37 ) ;
V_36 -> V_37 = V_2 ;
return 0 ;
V_111:
V_110:
V_108:
F_49 ( V_37 ) ;
return V_93 ;
V_107:
F_29 ( V_37 ) ;
return V_93 ;
}
static void F_50 ( struct V_1 * V_2 , struct V_112 * V_113 )
{
struct V_35 * V_36 ;
struct V_1 * V_37 ;
V_36 = F_8 ( V_2 ) ;
V_37 = V_36 -> V_37 ;
F_51 ( V_2 , V_113 ) ;
F_51 ( V_37 , V_113 ) ;
}
static T_6 int F_52 ( void )
{
return F_53 ( & V_105 ) ;
}
static T_7 void F_54 ( void )
{
F_55 ( & V_105 ) ;
}
