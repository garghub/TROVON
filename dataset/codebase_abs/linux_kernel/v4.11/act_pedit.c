static struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 V_4 )
{
struct V_1 * V_5 ;
struct V_1 * V_6 ;
const struct V_2 * V_7 ;
int V_8 = - V_9 ;
int V_10 ;
if ( ! V_3 || ! V_4 )
return NULL ;
V_5 = F_2 ( V_4 , sizeof( * V_6 ) , V_11 ) ;
if ( ! V_5 )
return F_3 ( - V_12 ) ;
V_6 = V_5 ;
F_4 (ka, nla, rem) {
struct V_2 * V_13 [ V_14 + 1 ] ;
if ( ! V_4 ) {
V_8 = - V_9 ;
goto V_15;
}
V_4 -- ;
if ( F_5 ( V_7 ) != V_16 ) {
V_8 = - V_9 ;
goto V_15;
}
V_8 = F_6 ( V_13 , V_14 , V_7 ,
V_17 ) ;
if ( V_8 )
goto V_15;
if ( ! V_13 [ V_18 ] ||
! V_13 [ V_19 ] ) {
V_8 = - V_9 ;
goto V_15;
}
V_6 -> V_20 = F_7 ( V_13 [ V_18 ] ) ;
V_6 -> V_21 = F_7 ( V_13 [ V_19 ] ) ;
if ( V_6 -> V_20 > V_22 ||
V_6 -> V_21 > V_23 ) {
V_8 = - V_9 ;
goto V_15;
}
V_6 ++ ;
}
if ( V_4 )
goto V_15;
return V_5 ;
V_15:
F_8 ( V_5 ) ;
return F_3 ( V_8 ) ;
}
static int F_9 ( struct V_24 * V_25 ,
struct V_1 * V_5 , int V_4 )
{
struct V_2 * V_26 = F_10 ( V_25 , V_27 ) ;
for (; V_4 > 0 ; V_4 -- ) {
struct V_2 * V_28 ;
V_28 = F_10 ( V_25 , V_16 ) ;
if ( F_11 ( V_25 , V_18 , V_5 -> V_20 ) ||
F_11 ( V_25 , V_19 , V_5 -> V_21 ) ) {
F_12 ( V_25 , V_26 ) ;
return - V_9 ;
}
F_13 ( V_25 , V_28 ) ;
V_5 ++ ;
}
F_13 ( V_25 , V_26 ) ;
return 0 ;
}
static int F_14 ( struct V_29 * V_29 , struct V_2 * V_3 ,
struct V_2 * V_30 , struct V_31 * * V_32 ,
int V_33 , int V_34 )
{
struct V_35 * V_36 = F_15 ( V_29 , V_37 ) ;
struct V_2 * V_13 [ V_38 + 1 ] ;
struct V_2 * V_39 ;
struct V_40 * V_41 ;
int V_42 = 0 , V_8 ;
struct V_43 * V_44 ;
struct V_45 * V_46 = NULL ;
struct V_1 * V_5 ;
int V_47 ;
if ( V_3 == NULL )
return - V_9 ;
V_8 = F_6 ( V_13 , V_38 , V_3 , V_48 ) ;
if ( V_8 < 0 )
return V_8 ;
V_39 = V_13 [ V_49 ] ;
if ( ! V_39 )
V_39 = V_13 [ V_50 ] ;
if ( ! V_39 )
return - V_9 ;
V_41 = F_16 ( V_39 ) ;
V_47 = V_41 -> V_51 * sizeof( struct V_45 ) ;
if ( F_17 ( V_39 ) < sizeof( * V_41 ) + V_47 )
return - V_9 ;
V_5 = F_1 ( V_13 [ V_27 ] , V_41 -> V_51 ) ;
if ( F_18 ( V_5 ) )
return F_19 ( V_5 ) ;
if ( ! F_20 ( V_36 , V_41 -> V_52 , V_32 , V_34 ) ) {
if ( ! V_41 -> V_51 )
return - V_9 ;
V_42 = F_21 ( V_36 , V_41 -> V_52 , V_30 , V_32 ,
& V_53 , V_34 , false ) ;
if ( V_42 )
return V_42 ;
V_44 = F_22 ( * V_32 ) ;
V_46 = F_23 ( V_47 , V_11 ) ;
if ( V_46 == NULL ) {
F_24 ( * V_32 , V_30 ) ;
F_8 ( V_5 ) ;
return - V_12 ;
}
V_42 = V_54 ;
} else {
if ( V_34 )
return 0 ;
F_25 ( * V_32 , V_34 ) ;
if ( ! V_33 )
return - V_55 ;
V_44 = F_22 ( * V_32 ) ;
if ( V_44 -> V_56 && V_44 -> V_56 != V_41 -> V_51 ) {
V_46 = F_23 ( V_47 , V_11 ) ;
if ( ! V_46 ) {
F_8 ( V_5 ) ;
return - V_12 ;
}
}
}
F_26 ( & V_44 -> V_57 ) ;
V_44 -> V_58 = V_41 -> V_59 ;
V_44 -> V_60 = V_41 -> V_61 ;
if ( V_46 ) {
F_8 ( V_44 -> V_62 ) ;
V_44 -> V_62 = V_46 ;
V_44 -> V_56 = V_41 -> V_51 ;
}
memcpy ( V_44 -> V_62 , V_41 -> V_46 , V_47 ) ;
F_8 ( V_44 -> V_63 ) ;
V_44 -> V_63 = V_5 ;
F_27 ( & V_44 -> V_57 ) ;
if ( V_42 == V_54 )
F_28 ( V_36 , * V_32 ) ;
return V_42 ;
}
static void F_29 ( struct V_31 * V_32 , int V_34 )
{
struct V_43 * V_44 = F_22 ( V_32 ) ;
struct V_45 * V_46 = V_44 -> V_62 ;
F_8 ( V_46 ) ;
F_8 ( V_44 -> V_63 ) ;
}
static bool F_30 ( struct V_24 * V_25 , int V_64 )
{
if ( V_64 > 0 && V_64 > V_25 -> V_65 )
return false ;
if ( V_64 < 0 && - V_64 > F_31 ( V_25 ) )
return false ;
return true ;
}
static int F_32 ( struct V_24 * V_25 ,
enum V_66 V_20 , int * V_67 )
{
int V_42 = - V_9 ;
switch ( V_20 ) {
case V_68 :
if ( F_33 ( V_25 ) ) {
* V_67 = F_34 ( V_25 ) ;
V_42 = 0 ;
}
break;
case V_69 :
case V_70 :
case V_71 :
* V_67 = F_35 ( V_25 ) ;
V_42 = 0 ;
break;
case V_72 :
case V_73 :
if ( F_36 ( V_25 ) ) {
* V_67 = F_37 ( V_25 ) ;
V_42 = 0 ;
}
break;
default:
V_42 = - V_9 ;
break;
} ;
return V_42 ;
}
static int V_43 ( struct V_24 * V_25 , const struct V_31 * V_32 ,
struct V_74 * V_75 )
{
struct V_43 * V_44 = F_22 ( V_32 ) ;
int V_76 ;
if ( F_38 ( V_25 , V_77 ) )
return V_44 -> V_60 ;
F_39 ( & V_44 -> V_57 ) ;
F_40 ( & V_44 -> V_78 ) ;
if ( V_44 -> V_56 > 0 ) {
struct V_45 * V_79 = V_44 -> V_62 ;
struct V_1 * V_80 = V_44 -> V_63 ;
enum V_66 V_20 = V_69 ;
enum V_81 V_21 = V_82 ;
for ( V_76 = V_44 -> V_56 ; V_76 > 0 ; V_76 -- , V_79 ++ ) {
T_2 * V_83 , V_84 ;
int V_64 = V_79 -> V_85 ;
int V_67 ;
T_2 V_86 ;
int V_87 ;
if ( V_80 ) {
V_20 = V_80 -> V_20 ;
V_21 = V_80 -> V_21 ;
V_80 ++ ;
}
V_87 = F_32 ( V_25 , V_20 , & V_67 ) ;
if ( V_87 ) {
F_41 ( L_1 ,
V_20 ) ;
goto V_88;
}
if ( V_79 -> V_89 ) {
char * V_90 , V_91 ;
if ( ! F_30 ( V_25 , V_67 + V_79 -> V_92 ) ) {
F_41 ( L_2 ,
V_67 + V_79 -> V_92 ) ;
goto V_88;
}
V_90 = F_42 ( V_25 , V_67 + V_79 -> V_92 , 1 ,
& V_91 ) ;
if ( ! V_90 )
goto V_88;
V_64 += ( * V_90 & V_79 -> V_89 ) >> V_79 -> V_93 ;
}
if ( V_64 % 4 ) {
F_41 ( L_3
L_4 ) ;
goto V_88;
}
if ( ! F_30 ( V_25 , V_67 + V_64 ) ) {
F_41 ( L_5 ,
V_67 + V_64 ) ;
goto V_88;
}
V_83 = F_42 ( V_25 , V_67 + V_64 , 4 , & V_84 ) ;
if ( ! V_83 )
goto V_88;
switch ( V_21 ) {
case V_82 :
V_86 = V_79 -> V_86 ;
break;
case V_94 :
V_86 = ( * V_83 + V_79 -> V_86 ) & ~ V_79 -> V_95 ;
break;
default:
F_41 ( L_6 ,
V_21 ) ;
goto V_88;
}
* V_83 = ( ( * V_83 & V_79 -> V_95 ) ^ V_86 ) ;
if ( V_83 == & V_84 )
F_43 ( V_25 , V_67 + V_64 , V_83 , 4 ) ;
}
goto V_96;
} else
F_44 ( 1 , L_7 , V_44 -> V_97 ) ;
V_88:
V_44 -> V_98 . V_99 ++ ;
V_96:
F_45 ( & V_44 -> V_100 , V_25 ) ;
F_46 ( & V_44 -> V_57 ) ;
return V_44 -> V_60 ;
}
static int F_47 ( struct V_24 * V_25 , struct V_31 * V_32 ,
int V_34 , int V_101 )
{
unsigned char * V_102 = F_48 ( V_25 ) ;
struct V_43 * V_44 = F_22 ( V_32 ) ;
struct V_40 * V_103 ;
struct V_104 V_105 ;
int V_106 ;
V_106 = sizeof( * V_103 ) + V_44 -> V_56 * sizeof( struct V_45 ) ;
V_103 = F_49 ( V_106 , V_77 ) ;
if ( F_50 ( ! V_103 ) )
return - V_107 ;
memcpy ( V_103 -> V_46 , V_44 -> V_62 ,
V_44 -> V_56 * sizeof( struct V_45 ) ) ;
V_103 -> V_52 = V_44 -> V_97 ;
V_103 -> V_51 = V_44 -> V_56 ;
V_103 -> V_59 = V_44 -> V_58 ;
V_103 -> V_61 = V_44 -> V_60 ;
V_103 -> V_108 = V_44 -> V_109 - V_101 ;
V_103 -> V_110 = V_44 -> V_111 - V_34 ;
if ( V_44 -> V_63 ) {
F_9 ( V_25 , V_44 -> V_63 , V_44 -> V_56 ) ;
if ( F_51 ( V_25 , V_50 , V_106 , V_103 ) )
goto V_112;
} else {
if ( F_51 ( V_25 , V_49 , V_106 , V_103 ) )
goto V_112;
}
F_52 ( & V_105 , & V_44 -> V_78 ) ;
if ( F_53 ( V_25 , V_113 , sizeof( V_105 ) , & V_105 , V_114 ) )
goto V_112;
F_8 ( V_103 ) ;
return V_25 -> V_65 ;
V_112:
F_12 ( V_25 , V_102 ) ;
F_8 ( V_103 ) ;
return - 1 ;
}
static int F_54 ( struct V_29 * V_29 , struct V_24 * V_25 ,
struct V_115 * V_116 , int type ,
const struct V_117 * V_118 )
{
struct V_35 * V_36 = F_15 ( V_29 , V_37 ) ;
return F_55 ( V_36 , V_25 , V_116 , type , V_118 ) ;
}
static int F_56 ( struct V_29 * V_29 , struct V_31 * * V_32 , T_2 V_52 )
{
struct V_35 * V_36 = F_15 ( V_29 , V_37 ) ;
return F_57 ( V_36 , V_32 , V_52 ) ;
}
static T_3 int F_58 ( struct V_29 * V_29 )
{
struct V_35 * V_36 = F_15 ( V_29 , V_37 ) ;
return F_59 ( V_36 , & V_53 , V_119 ) ;
}
static void T_4 F_60 ( struct V_29 * V_29 )
{
struct V_35 * V_36 = F_15 ( V_29 , V_37 ) ;
F_61 ( V_36 ) ;
}
static int T_5 F_62 ( void )
{
return F_63 ( & V_53 , & V_120 ) ;
}
static void T_6 F_64 ( void )
{
F_65 ( & V_53 , & V_120 ) ;
}
