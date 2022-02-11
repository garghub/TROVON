static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 . V_5 ) ;
}
static inline struct V_2 * F_3 ( struct V_1 * V_6 )
{
return F_4 ( & V_6 -> V_7 ) ;
}
int F_5 ( int V_8 , int V_9 , int V_10 )
{
if ( V_8 < 0 && V_9 < 0 && V_10 < 0 )
return - V_11 ;
if ( V_8 == 0 )
return - V_11 ;
if ( V_9 > V_12 )
return - V_11 ;
if ( V_9 < 0 &&
V_10 > V_12 )
return - V_11 ;
if ( V_10 >= V_13 / V_14 )
return - V_11 ;
if ( V_9 >= 0 && V_10 >= 0 &&
V_9 >= V_10 )
return - V_11 ;
return 0 ;
}
static int F_6 ( struct V_15 * V_16 , struct V_17 * V_4 ,
struct V_17 * V_18 )
{
struct V_1 * V_6 = F_2 ( V_4 ) ;
struct V_19 * V_20 = F_7 ( V_6 ) ;
F_8 ( & V_20 -> V_21 , 0 ) ;
return 0 ;
}
static T_1
F_9 ( struct V_17 * V_4 , struct V_22 * V_23 ,
char * V_24 )
{
struct V_2 * V_25 = F_4 ( V_4 ) ;
return sprintf ( V_24 , L_1 , V_25 -> V_26 ) ;
}
static T_1
F_10 ( struct V_17 * V_4 , struct V_22 * V_23 ,
char * V_24 )
{
struct V_2 * V_25 = F_4 ( V_4 ) ;
int V_27 ;
char * V_28 = NULL ;
for ( V_27 = 0 ; V_27 < F_11 ( V_29 ) ; V_27 ++ )
if ( V_29 [ V_27 ] . V_30 == V_25 -> V_31 ) {
V_28 = V_29 [ V_27 ] . V_28 ;
break;
}
return sprintf ( V_24 , L_2 , V_28 ? : L_3 ) ;
}
static T_1 F_12 ( struct V_17 * V_4 ,
struct V_22 * V_23 ,
const char * V_24 , T_2 V_32 )
{
struct V_2 * V_25 = F_4 ( V_4 ) ;
struct V_1 * V_6 = F_2 ( V_4 ) ;
struct V_33 * V_27 = F_13 ( V_6 -> V_34 ) ;
if ( V_27 -> V_35 -> V_36 ) {
V_27 -> V_35 -> V_36 ( V_25 ) ;
return V_32 ;
} else {
return - V_37 ;
}
}
static T_1 F_14 ( struct V_17 * V_4 ,
struct V_22 * V_23 ,
char * V_24 )
{
static const char * const V_38 [] = {
[ V_39 ] = L_4 ,
[ V_40 ] = L_5 ,
[ V_41 ] = L_6 ,
[ V_42 ] = L_7 ,
} ;
struct V_2 * V_25 = F_4 ( V_4 ) ;
enum V_43 V_44 = V_25 -> V_44 ;
return sprintf ( V_24 , L_2 ,
( unsigned ) V_44 < F_11 ( V_38 ) ?
V_38 [ V_44 ] : L_8 ) ;
}
static T_1 F_15 ( char * V_24 , int V_45 )
{
return V_45 >= 0 ? sprintf ( V_24 , L_9 , V_45 ) : sprintf ( V_24 , L_10 ) ;
}
int F_16 ( int * V_45 , const char * V_24 )
{
int V_46 = 0 ;
if ( strncmp ( V_24 , L_11 , 3 ) != 0 )
V_46 = F_17 ( V_24 , 0 , V_45 ) ;
else
* V_45 = - 1 ;
return V_46 ;
}
static T_1 F_18 ( struct V_17 * V_4 ,
struct V_22 * V_23 , char * V_24 )
{
struct V_2 * V_25 = F_4 ( V_4 ) ;
return F_15 ( V_24 , V_25 -> V_8 ) ;
}
static T_1 F_19 ( struct V_17 * V_4 ,
struct V_22 * V_23 ,
const char * V_24 , const T_2 V_32 )
{
struct V_2 * V_25 = F_4 ( V_4 ) ;
int V_46 , V_47 ;
V_46 = F_16 ( & V_47 , V_24 ) ;
if ( V_46 )
goto V_48;
V_46 = F_5 ( V_47 , V_25 -> V_9 ,
V_25 -> V_10 ) ;
if ( V_46 )
goto V_48;
if ( V_25 -> V_8 <= 0 && V_47 > 0 &&
V_25 -> V_44 != V_39 ) {
F_20 ( V_49 , & V_25 -> V_50 ,
V_47 * V_14 ) ;
} else if ( V_47 <= 0 ) {
F_21 ( & V_25 -> V_50 ) ;
}
V_25 -> V_8 = V_47 ;
V_46 = V_32 ;
V_48:
return V_46 ;
}
static T_1 F_22 ( struct V_17 * V_4 ,
struct V_22 * V_23 , char * V_24 )
{
struct V_2 * V_25 = F_4 ( V_4 ) ;
return sprintf ( V_24 , L_9 , V_25 -> V_51 ) ;
}
static T_1 F_23 ( struct V_17 * V_4 ,
struct V_22 * V_23 ,
char * V_24 )
{
struct V_2 * V_25 = F_4 ( V_4 ) ;
return F_15 ( V_24 , V_25 -> V_9 ) ;
}
static T_1 F_24 ( struct V_17 * V_4 ,
struct V_22 * V_23 ,
const char * V_24 , T_2 V_32 )
{
struct V_2 * V_25 = F_4 ( V_4 ) ;
int V_46 ;
int V_9 ;
V_46 = F_16 ( & V_9 , V_24 ) ;
if ( V_46 )
goto V_48;
V_46 = F_5 ( V_25 -> V_8 , V_9 ,
V_25 -> V_10 ) ;
if ( V_46 )
goto V_48;
V_25 -> V_9 = V_9 ;
V_46 = V_32 ;
V_48:
return V_46 ;
}
static T_1 F_25 ( struct V_17 * V_4 ,
struct V_22 * V_23 ,
char * V_24 )
{
struct V_2 * V_25 = F_4 ( V_4 ) ;
return F_15 ( V_24 , V_25 -> V_10 ) ;
}
static T_1 F_26 ( struct V_17 * V_4 ,
struct V_22 * V_23 ,
const char * V_24 , T_2 V_32 )
{
struct V_2 * V_25 = F_4 ( V_4 ) ;
int V_46 ;
int V_10 ;
V_46 = F_16 ( & V_10 , V_24 ) ;
if ( V_46 )
goto V_48;
V_46 = F_5 ( V_25 -> V_8 , V_25 -> V_9 ,
V_10 ) ;
if ( V_46 )
goto V_48;
V_25 -> V_10 = V_10 ;
V_46 = V_32 ;
V_48:
return V_46 ;
}
static int F_27 ( struct V_2 * V_25 ,
enum V_43 V_52 )
{
enum V_43 V_53 = V_25 -> V_44 ;
F_28 ( & V_25 -> V_54 ) ;
switch ( V_52 ) {
case V_39 :
switch ( V_53 ) {
case V_42 :
goto V_55;
default:
break;
}
break;
case V_40 :
switch ( V_53 ) {
case V_39 :
break;
default:
goto V_55;
}
break;
case V_41 :
switch ( V_53 ) {
case V_42 :
goto V_55;
default:
break;
}
break;
case V_42 :
break;
}
V_25 -> V_44 = V_52 ;
return 0 ;
V_55:
return - V_11 ;
}
static void F_29 ( struct V_56 * V_57 )
{
struct V_2 * V_25 = F_30 ( F_31 ( V_57 ) ,
struct V_2 , V_50 ) ;
struct V_1 * V_6 = F_1 ( V_25 ) ;
int V_47 , V_46 ;
V_46 = F_32 ( V_25 ) ;
if ( V_46 != 0 ) {
F_33 ( V_58 , V_6 ,
L_12 ,
++ V_25 -> V_51 , V_46 ) ;
V_47 = V_25 -> V_8 *
F_34 ( 100 , F_35 ( 1 , V_25 -> V_51 - 10 ) ) ;
if ( V_47 > 0 )
F_20 ( V_49 ,
& V_25 -> V_50 , V_47 * V_14 ) ;
}
}
static void F_36 ( struct V_2 * V_25 )
{
struct V_1 * V_6 = F_1 ( V_25 ) ;
struct V_33 * V_27 ;
F_28 ( & V_25 -> V_54 ) ;
if ( F_27 ( V_25 , V_41 ) )
return;
F_37 ( V_25 -> V_4 . V_5 ) ;
F_38 ( V_25 -> V_4 . V_5 , V_59 ) ;
V_27 = F_13 ( V_6 -> V_34 ) ;
if ( V_27 -> V_35 -> V_60 )
V_27 -> V_35 -> V_60 ( V_25 ) ;
}
static void F_39 ( struct V_56 * V_57 )
{
struct V_2 * V_25 = F_30 ( F_31 ( V_57 ) ,
struct V_2 , V_61 ) ;
struct V_1 * V_6 = F_1 ( V_25 ) ;
F_40 ( L_13 ,
F_41 ( & V_25 -> V_4 ) , F_41 ( & V_6 -> V_7 ) ) ;
F_42 ( & V_25 -> V_54 ) ;
if ( V_25 -> V_44 == V_40 )
F_36 ( V_25 ) ;
F_43 ( & V_25 -> V_54 ) ;
}
static void F_44 ( struct V_56 * V_57 )
{
struct V_2 * V_25 = F_30 ( F_31 ( V_57 ) ,
struct V_2 , V_62 ) ;
struct V_1 * V_6 = F_1 ( V_25 ) ;
struct V_33 * V_27 = F_13 ( V_6 -> V_34 ) ;
F_40 ( L_14 ,
F_41 ( & V_25 -> V_4 ) , F_41 ( & V_6 -> V_7 ) ) ;
F_42 ( & V_25 -> V_54 ) ;
F_45 ( F_27 ( V_25 , V_42 ) != 0 ) ;
F_38 ( V_25 -> V_4 . V_5 , V_59 ) ;
F_43 ( & V_25 -> V_54 ) ;
V_27 -> V_35 -> V_36 ( V_25 ) ;
}
static void F_46 ( struct V_2 * V_25 )
{
struct V_1 * V_6 = F_1 ( V_25 ) ;
int V_47 , V_9 , V_10 ;
F_28 ( & V_25 -> V_54 ) ;
V_47 = V_25 -> V_8 ;
V_9 = V_25 -> V_9 ;
V_10 = V_25 -> V_10 ;
F_47 ( L_15 , F_41 ( & V_6 -> V_7 ) ,
V_25 -> V_44 ) ;
if ( V_25 -> V_44 == V_42 )
return;
if ( V_47 > 0 )
F_20 ( V_49 , & V_25 -> V_50 ,
1UL * V_47 * V_14 ) ;
if ( ( V_9 >= 0 || V_10 >= 0 ) &&
F_27 ( V_25 , V_40 ) == 0 ) {
F_47 ( L_16 , F_41 ( & V_6 -> V_7 ) ,
V_25 -> V_44 ) ;
F_37 ( & V_6 -> V_7 ) ;
if ( V_9 >= 0 )
F_20 ( V_49 ,
& V_25 -> V_61 ,
1UL * V_9 * V_14 ) ;
if ( V_10 >= 0 )
F_20 ( V_49 ,
& V_25 -> V_62 ,
1UL * V_10 * V_14 ) ;
}
}
void F_48 ( struct V_2 * V_25 )
{
F_42 ( & V_25 -> V_54 ) ;
F_46 ( V_25 ) ;
F_43 ( & V_25 -> V_54 ) ;
}
int F_32 ( struct V_2 * V_25 )
{
struct V_1 * V_6 = F_1 ( V_25 ) ;
struct V_33 * V_27 = F_13 ( V_6 -> V_34 ) ;
struct V_63 * V_64 ;
int V_46 ;
F_47 ( L_17 , F_41 ( & V_6 -> V_7 ) ) ;
V_46 = F_49 ( & V_25 -> V_54 ) ;
if ( V_46 )
goto V_48;
F_37 ( & V_6 -> V_7 ) ;
V_46 = V_25 -> V_44 != V_42 ? V_27 -> V_35 -> V_65 ( V_25 ) : - V_66 ;
F_47 ( L_18 ,
F_41 ( & V_6 -> V_7 ) , V_25 -> V_44 , V_46 ) ;
if ( V_46 == 0 ) {
F_21 ( & V_25 -> V_61 ) ;
F_21 ( & V_25 -> V_62 ) ;
V_25 -> V_51 = 0 ;
F_27 ( V_25 , V_39 ) ;
F_38 ( & V_6 -> V_7 , V_67 ) ;
F_50 ( V_6 -> V_68 ) ;
F_51 (sdev, shost)
if ( V_64 -> V_69 == V_70 )
V_64 -> V_69 = V_67 ;
F_52 ( V_6 -> V_68 ) ;
} else if ( V_25 -> V_44 == V_39 ) {
F_36 ( V_25 ) ;
F_38 ( & V_6 -> V_7 ,
V_59 ) ;
F_46 ( V_25 ) ;
} else if ( V_25 -> V_44 != V_40 ) {
F_38 ( & V_6 -> V_7 ,
V_59 ) ;
}
F_43 ( & V_25 -> V_54 ) ;
V_48:
return V_46 ;
}
enum V_71 F_53 ( struct V_72 * V_73 )
{
struct V_63 * V_64 = V_73 -> V_17 ;
struct V_1 * V_6 = V_64 -> V_74 ;
struct V_33 * V_27 = F_13 ( V_6 -> V_34 ) ;
struct V_2 * V_25 = F_3 ( V_6 ) ;
F_47 ( L_19 , F_41 ( & V_64 -> V_75 ) ) ;
return V_25 -> V_9 < 0 && V_25 -> V_10 < 0 &&
V_27 -> V_35 -> V_76 && F_54 ( V_64 ) ?
V_77 : V_78 ;
}
static void F_55 ( struct V_17 * V_4 )
{
struct V_2 * V_25 = F_56 ( V_4 ) ;
F_57 ( V_4 -> V_5 ) ;
F_58 ( V_25 ) ;
}
static int F_59 ( const struct V_17 * V_4 )
{
return V_4 -> V_79 == F_55 ;
}
static int F_60 ( struct V_80 * V_81 ,
struct V_17 * V_4 )
{
struct V_1 * V_6 ;
struct V_33 * V_27 ;
if ( ! F_59 ( V_4 ) )
return 0 ;
V_6 = F_2 ( V_4 -> V_5 ) ;
if ( ! V_6 -> V_34 )
return 0 ;
if ( V_6 -> V_34 -> V_82 . V_83 . V_84 != & V_85 . V_84 )
return 0 ;
V_27 = F_13 ( V_6 -> V_34 ) ;
return & V_27 -> V_86 . V_83 == V_81 ;
}
static int F_61 ( struct V_80 * V_81 , struct V_17 * V_4 )
{
struct V_1 * V_6 ;
struct V_33 * V_27 ;
if ( ! F_62 ( V_4 ) )
return 0 ;
V_6 = F_2 ( V_4 ) ;
if ( ! V_6 -> V_34 )
return 0 ;
if ( V_6 -> V_34 -> V_82 . V_83 . V_84 != & V_85 . V_84 )
return 0 ;
V_27 = F_13 ( V_6 -> V_34 ) ;
return & V_27 -> V_87 . V_82 . V_83 == V_81 ;
}
void F_63 ( struct V_2 * V_25 )
{
F_64 ( & V_25 -> V_4 ) ;
}
void F_65 ( struct V_2 * V_25 )
{
F_57 ( & V_25 -> V_4 ) ;
}
struct V_2 * F_66 ( struct V_1 * V_6 ,
struct V_88 * V_89 )
{
struct V_2 * V_25 ;
struct V_17 * V_5 = & V_6 -> V_7 ;
struct V_33 * V_27 = F_13 ( V_6 -> V_34 ) ;
int V_90 , V_91 ;
V_25 = F_67 ( sizeof( * V_25 ) , V_92 ) ;
if ( ! V_25 )
return F_68 ( - V_93 ) ;
F_69 ( & V_25 -> V_54 ) ;
F_70 ( & V_25 -> V_4 ) ;
V_25 -> V_4 . V_5 = F_64 ( V_5 ) ;
V_25 -> V_4 . V_79 = F_55 ;
memcpy ( V_25 -> V_26 , V_89 -> V_26 , sizeof( V_25 -> V_26 ) ) ;
V_25 -> V_31 = V_89 -> V_31 ;
if ( V_27 -> V_35 -> V_65 )
V_25 -> V_8 = V_27 -> V_35 -> V_8 ?
* V_27 -> V_35 -> V_8 : 10 ;
F_71 ( & V_25 -> V_50 , F_29 ) ;
V_25 -> V_9 = V_27 -> V_35 -> V_9 ?
* V_27 -> V_35 -> V_9 : 15 ;
V_25 -> V_10 = V_27 -> V_35 -> V_10 ? * V_27 -> V_35 -> V_10 : 60 ;
F_71 ( & V_25 -> V_61 ,
F_39 ) ;
F_71 ( & V_25 -> V_62 , F_44 ) ;
V_90 = F_72 ( & F_7 ( V_6 ) -> V_21 ) ;
F_73 ( & V_25 -> V_4 , L_20 , V_6 -> V_94 , V_90 ) ;
F_74 ( & V_25 -> V_4 ) ;
V_91 = F_75 ( & V_25 -> V_4 ) ;
if ( V_91 ) {
F_76 ( & V_25 -> V_4 ) ;
F_57 ( & V_25 -> V_4 ) ;
return F_68 ( V_91 ) ;
}
F_77 ( & V_25 -> V_4 ) ;
F_78 ( & V_25 -> V_4 ) ;
return V_25 ;
}
void F_79 ( struct V_2 * V_25 )
{
struct V_17 * V_4 = & V_25 -> V_4 ;
F_80 ( V_4 ) ;
F_81 ( V_4 ) ;
F_76 ( V_4 ) ;
F_57 ( V_4 ) ;
}
static int F_82 ( struct V_17 * V_4 , void * V_95 )
{
if ( F_59 ( V_4 ) )
F_79 ( F_56 ( V_4 ) ) ;
return 0 ;
}
void F_83 ( struct V_1 * V_6 )
{
F_84 ( & V_6 -> V_7 , NULL , F_82 ) ;
}
void F_85 ( struct V_2 * V_25 )
{
F_42 ( & V_25 -> V_54 ) ;
if ( V_25 -> V_44 == V_40 )
F_36 ( V_25 ) ;
F_27 ( V_25 , V_42 ) ;
F_43 ( & V_25 -> V_54 ) ;
F_86 ( & V_25 -> V_50 ) ;
F_86 ( & V_25 -> V_61 ) ;
F_86 ( & V_25 -> V_62 ) ;
}
struct V_96 *
F_87 ( struct V_97 * V_98 )
{
int V_32 ;
struct V_33 * V_27 ;
V_27 = F_67 ( sizeof( * V_27 ) , V_92 ) ;
if ( ! V_27 )
return NULL ;
V_27 -> V_87 . V_99 = sizeof( struct V_19 ) ;
V_27 -> V_87 . V_82 . V_83 . V_100 = & V_27 -> V_82 [ 0 ] ;
V_27 -> V_87 . V_82 . V_83 . V_84 = & V_85 . V_84 ;
V_27 -> V_87 . V_82 . V_83 . V_101 = F_61 ;
V_27 -> V_82 [ 0 ] = NULL ;
F_88 ( & V_27 -> V_87 . V_82 ) ;
V_27 -> V_86 . V_83 . V_100 = & V_27 -> V_102 [ 0 ] ;
V_27 -> V_86 . V_83 . V_84 = & V_103 . V_84 ;
V_27 -> V_86 . V_83 . V_101 = F_60 ;
V_32 = 0 ;
V_27 -> V_102 [ V_32 ++ ] = & V_104 ;
V_27 -> V_102 [ V_32 ++ ] = & V_105 ;
if ( V_98 -> V_106 ) {
V_27 -> V_102 [ V_32 ++ ] = & V_107 ;
V_27 -> V_102 [ V_32 ++ ] = & V_108 ;
V_27 -> V_102 [ V_32 ++ ] = & V_109 ;
}
if ( V_98 -> V_65 ) {
V_27 -> V_102 [ V_32 ++ ] = & V_110 ;
V_27 -> V_102 [ V_32 ++ ] = & V_111 ;
}
if ( V_98 -> V_36 )
V_27 -> V_102 [ V_32 ++ ] = & V_112 ;
V_27 -> V_102 [ V_32 ++ ] = NULL ;
F_89 ( V_32 > F_11 ( V_27 -> V_102 ) ) ;
F_88 ( & V_27 -> V_86 ) ;
V_27 -> V_35 = V_98 ;
return & V_27 -> V_87 ;
}
void F_90 ( struct V_96 * V_87 )
{
struct V_33 * V_27 = F_13 ( V_87 ) ;
F_91 ( & V_27 -> V_87 . V_82 ) ;
F_91 ( & V_27 -> V_86 ) ;
F_58 ( V_27 ) ;
}
static T_3 int F_92 ( void )
{
int V_91 ;
V_91 = F_93 ( & V_85 ) ;
if ( V_91 )
return V_91 ;
V_91 = F_93 ( & V_103 ) ;
if ( V_91 )
goto V_113;
return 0 ;
V_113:
F_94 ( & V_85 ) ;
return V_91 ;
}
static void T_4 F_95 ( void )
{
F_94 ( & V_85 ) ;
F_94 ( & V_103 ) ;
}
