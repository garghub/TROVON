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
if ( ! ( V_41 -> V_46 & V_47 ) )
goto V_48;
if ( V_40 -> V_49 == V_50 &&
V_41 -> V_51 & V_52 )
V_40 -> V_49 = V_53 ;
V_45 = V_40 -> V_54 ;
if ( F_11 ( V_41 , V_40 ) != V_55 )
goto V_56;
V_33 -> V_57 += V_45 ;
V_33 -> V_58 ++ ;
V_44 -> V_59 += V_45 ;
V_44 -> V_60 ++ ;
return V_61 ;
V_48:
F_12 ( V_40 ) ;
V_33 -> V_62 ++ ;
return V_61 ;
V_56:
V_44 -> V_63 ++ ;
return V_61 ;
}
static struct V_64 * F_13 ( struct V_1 * V_2 )
{
struct V_35 * V_36 ;
int V_65 ;
struct V_43 * V_33 , V_66 = { 0 } ;
V_36 = F_8 ( V_2 ) ;
F_14 (cpu) {
V_33 = F_15 ( V_36 -> V_33 , V_65 ) ;
V_66 . V_60 += V_33 -> V_60 ;
V_66 . V_58 += V_33 -> V_58 ;
V_66 . V_59 += V_33 -> V_59 ;
V_66 . V_57 += V_33 -> V_57 ;
V_66 . V_62 += V_33 -> V_62 ;
V_66 . V_63 += V_33 -> V_63 ;
}
V_2 -> V_33 . V_60 = V_66 . V_60 ;
V_2 -> V_33 . V_58 = V_66 . V_58 ;
V_2 -> V_33 . V_59 = V_66 . V_59 ;
V_2 -> V_33 . V_57 = V_66 . V_57 ;
V_2 -> V_33 . V_62 = V_66 . V_62 ;
V_2 -> V_33 . V_63 = V_66 . V_63 ;
return & V_2 -> V_33 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_35 * V_36 ;
V_36 = F_8 ( V_2 ) ;
if ( V_36 -> V_37 == NULL )
return - V_67 ;
if ( V_36 -> V_37 -> V_46 & V_47 ) {
F_17 ( V_2 ) ;
F_17 ( V_36 -> V_37 ) ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = F_8 ( V_2 ) ;
F_19 ( V_2 ) ;
F_19 ( V_36 -> V_37 ) ;
return 0 ;
}
static int F_20 ( int V_68 )
{
return V_68 >= V_69 && V_68 <= V_70 ;
}
static int F_21 ( struct V_1 * V_2 , int V_68 )
{
if ( ! F_20 ( V_68 ) )
return - V_71 ;
V_2 -> V_72 = V_68 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_43 T_5 * V_33 ;
struct V_35 * V_36 ;
V_33 = F_23 ( struct V_43 ) ;
if ( V_33 == NULL )
return - V_73 ;
V_36 = F_8 ( V_2 ) ;
V_36 -> V_33 = V_33 ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_35 * V_36 ;
V_36 = F_8 ( V_2 ) ;
F_25 ( V_36 -> V_33 ) ;
F_26 ( V_2 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_28 ( V_2 ) ;
V_2 -> V_74 = & V_75 ;
V_2 -> V_76 = & V_77 ;
V_2 -> V_51 |= V_78 ;
V_2 -> V_79 = F_24 ;
V_2 -> V_80 = V_81 | V_82 | V_52 ;
}
static int F_29 ( struct V_83 * V_84 [] , struct V_83 * V_34 [] )
{
if ( V_84 [ V_85 ] ) {
if ( F_30 ( V_84 [ V_85 ] ) != V_86 )
return - V_71 ;
if ( ! F_31 ( F_32 ( V_84 [ V_85 ] ) ) )
return - V_87 ;
}
if ( V_84 [ V_88 ] ) {
if ( ! F_20 ( F_33 ( V_84 [ V_88 ] ) ) )
return - V_71 ;
}
return 0 ;
}
static int F_34 ( struct V_89 * V_90 , struct V_1 * V_2 ,
struct V_83 * V_84 [] , struct V_83 * V_34 [] )
{
int V_91 ;
struct V_1 * V_37 ;
struct V_35 * V_36 ;
char V_92 [ V_93 ] ;
struct V_83 * V_94 [ V_95 + 1 ] , * * V_96 ;
struct V_97 * V_98 ;
struct V_89 * V_89 ;
if ( V_34 != NULL && V_34 [ V_99 ] != NULL ) {
struct V_83 * V_100 ;
V_100 = V_34 [ V_99 ] ;
V_98 = F_32 ( V_100 ) ;
V_91 = F_35 ( V_94 , V_95 ,
F_32 ( V_100 ) + sizeof( struct V_97 ) ,
F_30 ( V_100 ) - sizeof( struct V_97 ) ,
V_101 ) ;
if ( V_91 < 0 )
return V_91 ;
V_91 = F_29 ( V_94 , NULL ) ;
if ( V_91 < 0 )
return V_91 ;
V_96 = V_94 ;
} else {
V_98 = NULL ;
V_96 = V_84 ;
}
if ( V_96 [ V_102 ] )
F_36 ( V_92 , V_96 [ V_102 ] , V_93 ) ;
else
snprintf ( V_92 , V_93 , V_22 L_2 ) ;
V_89 = F_37 ( V_90 , V_96 ) ;
if ( F_38 ( V_89 ) )
return F_39 ( V_89 ) ;
V_37 = F_40 ( V_90 , V_89 , V_92 , & V_103 , V_96 ) ;
if ( F_38 ( V_37 ) ) {
F_41 ( V_89 ) ;
return F_39 ( V_37 ) ;
}
if ( V_96 [ V_85 ] == NULL )
F_42 ( V_37 -> V_104 ) ;
V_91 = F_43 ( V_37 ) ;
F_41 ( V_89 ) ;
V_89 = NULL ;
if ( V_91 < 0 )
goto V_105;
F_19 ( V_37 ) ;
V_91 = F_44 ( V_37 , V_98 ) ;
if ( V_91 < 0 )
goto V_106;
if ( V_84 [ V_85 ] == NULL )
F_42 ( V_2 -> V_104 ) ;
if ( V_84 [ V_102 ] )
F_36 ( V_2 -> V_107 , V_84 [ V_102 ] , V_93 ) ;
else
snprintf ( V_2 -> V_107 , V_93 , V_22 L_2 ) ;
if ( strchr ( V_2 -> V_107 , '%' ) ) {
V_91 = F_45 ( V_2 , V_2 -> V_107 ) ;
if ( V_91 < 0 )
goto V_108;
}
V_91 = F_43 ( V_2 ) ;
if ( V_91 < 0 )
goto V_109;
F_19 ( V_2 ) ;
V_36 = F_8 ( V_2 ) ;
V_36 -> V_37 = V_37 ;
V_36 = F_8 ( V_37 ) ;
V_36 -> V_37 = V_2 ;
return 0 ;
V_109:
V_108:
V_106:
F_46 ( V_37 ) ;
return V_91 ;
V_105:
F_26 ( V_37 ) ;
return V_91 ;
}
static void F_47 ( struct V_1 * V_2 , struct V_110 * V_111 )
{
struct V_35 * V_36 ;
struct V_1 * V_37 ;
V_36 = F_8 ( V_2 ) ;
V_37 = V_36 -> V_37 ;
F_48 ( V_2 , V_111 ) ;
F_48 ( V_37 , V_111 ) ;
}
static T_6 int F_49 ( void )
{
return F_50 ( & V_103 ) ;
}
static T_7 void F_51 ( void )
{
F_52 ( & V_103 ) ;
}
