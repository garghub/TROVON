static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 . V_5 ) ;
}
int F_3 ( int V_6 , int V_7 , int V_8 )
{
if ( V_6 < 0 && V_7 < 0 && V_8 < 0 )
return - V_9 ;
if ( V_6 == 0 )
return - V_9 ;
if ( V_7 > V_10 )
return - V_9 ;
if ( V_7 < 0 &&
V_8 > V_10 )
return - V_9 ;
if ( V_8 >= V_11 / V_12 )
return - V_9 ;
if ( V_7 >= 0 && V_8 >= 0 &&
V_7 >= V_8 )
return - V_9 ;
return 0 ;
}
static int F_4 ( struct V_13 * V_14 , struct V_15 * V_4 ,
struct V_15 * V_16 )
{
struct V_1 * V_17 = F_2 ( V_4 ) ;
struct V_18 * V_19 = F_5 ( V_17 ) ;
F_6 ( & V_19 -> V_20 , 0 ) ;
return 0 ;
}
static T_1
F_7 ( struct V_15 * V_4 , struct V_21 * V_22 ,
char * V_23 )
{
struct V_2 * V_24 = F_8 ( V_4 ) ;
return sprintf ( V_23 , V_25 L_1 , F_9 ( V_24 ) ) ;
}
static T_1
F_10 ( struct V_15 * V_4 , struct V_21 * V_22 ,
char * V_23 )
{
struct V_2 * V_24 = F_8 ( V_4 ) ;
int V_26 ;
char * V_27 = NULL ;
for ( V_26 = 0 ; V_26 < F_11 ( V_28 ) ; V_26 ++ )
if ( V_28 [ V_26 ] . V_29 == V_24 -> V_30 ) {
V_27 = V_28 [ V_26 ] . V_27 ;
break;
}
return sprintf ( V_23 , L_2 , V_27 ? : L_3 ) ;
}
static T_1 F_12 ( struct V_15 * V_4 ,
struct V_21 * V_22 ,
const char * V_23 , T_2 V_31 )
{
struct V_2 * V_24 = F_8 ( V_4 ) ;
struct V_1 * V_17 = F_2 ( V_4 ) ;
struct V_32 * V_26 = F_13 ( V_17 -> V_33 ) ;
if ( V_26 -> V_34 -> V_35 ) {
V_26 -> V_34 -> V_35 ( V_24 ) ;
return V_31 ;
} else {
return - V_36 ;
}
}
static T_1 F_14 ( struct V_15 * V_4 ,
struct V_21 * V_22 ,
char * V_23 )
{
static const char * const V_37 [] = {
[ V_38 ] = L_4 ,
[ V_39 ] = L_5 ,
[ V_40 ] = L_6 ,
[ V_41 ] = L_7 ,
} ;
struct V_2 * V_24 = F_8 ( V_4 ) ;
enum V_42 V_43 = V_24 -> V_43 ;
return sprintf ( V_23 , L_2 ,
( unsigned ) V_43 < F_11 ( V_37 ) ?
V_37 [ V_43 ] : L_8 ) ;
}
static T_1 F_15 ( char * V_23 , int V_44 )
{
return V_44 >= 0 ? sprintf ( V_23 , L_9 , V_44 ) : sprintf ( V_23 , L_10 ) ;
}
static int F_16 ( int * V_44 , const char * V_23 )
{
int V_45 = 0 ;
if ( strncmp ( V_23 , L_11 , 3 ) != 0 )
V_45 = F_17 ( V_23 , 0 , V_44 ) ;
else
* V_44 = - 1 ;
return V_45 ;
}
static T_1 F_18 ( struct V_15 * V_4 ,
struct V_21 * V_22 , char * V_23 )
{
struct V_2 * V_24 = F_8 ( V_4 ) ;
return F_15 ( V_23 , V_24 -> V_6 ) ;
}
static T_1 F_19 ( struct V_15 * V_4 ,
struct V_21 * V_22 ,
const char * V_23 , const T_2 V_31 )
{
struct V_2 * V_24 = F_8 ( V_4 ) ;
int V_45 , V_46 ;
V_45 = F_16 ( & V_46 , V_23 ) ;
if ( V_45 )
goto V_47;
V_45 = F_3 ( V_46 , V_24 -> V_7 ,
V_24 -> V_8 ) ;
if ( V_45 )
goto V_47;
if ( V_24 -> V_6 <= 0 && V_46 > 0 &&
V_24 -> V_43 != V_38 ) {
F_20 ( V_48 , & V_24 -> V_49 ,
V_46 * V_12 ) ;
} else if ( V_46 <= 0 ) {
F_21 ( & V_24 -> V_49 ) ;
}
V_24 -> V_6 = V_46 ;
V_45 = V_31 ;
V_47:
return V_45 ;
}
static T_1 F_22 ( struct V_15 * V_4 ,
struct V_21 * V_22 , char * V_23 )
{
struct V_2 * V_24 = F_8 ( V_4 ) ;
return sprintf ( V_23 , L_9 , V_24 -> V_50 ) ;
}
static T_1 F_23 ( struct V_15 * V_4 ,
struct V_21 * V_22 ,
char * V_23 )
{
struct V_2 * V_24 = F_8 ( V_4 ) ;
return F_15 ( V_23 , V_24 -> V_7 ) ;
}
static T_1 F_24 ( struct V_15 * V_4 ,
struct V_21 * V_22 ,
const char * V_23 , T_2 V_31 )
{
struct V_2 * V_24 = F_8 ( V_4 ) ;
int V_45 ;
int V_7 ;
V_45 = F_16 ( & V_7 , V_23 ) ;
if ( V_45 )
goto V_47;
V_45 = F_3 ( V_24 -> V_6 , V_7 ,
V_24 -> V_8 ) ;
if ( V_45 )
goto V_47;
V_24 -> V_7 = V_7 ;
V_45 = V_31 ;
V_47:
return V_45 ;
}
static T_1 F_25 ( struct V_15 * V_4 ,
struct V_21 * V_22 ,
char * V_23 )
{
struct V_2 * V_24 = F_8 ( V_4 ) ;
return F_15 ( V_23 , V_24 -> V_8 ) ;
}
static T_1 F_26 ( struct V_15 * V_4 ,
struct V_21 * V_22 ,
const char * V_23 , T_2 V_31 )
{
struct V_2 * V_24 = F_8 ( V_4 ) ;
int V_45 ;
int V_8 ;
V_45 = F_16 ( & V_8 , V_23 ) ;
if ( V_45 )
goto V_47;
V_45 = F_3 ( V_24 -> V_6 , V_24 -> V_7 ,
V_8 ) ;
if ( V_45 )
goto V_47;
V_24 -> V_8 = V_8 ;
V_45 = V_31 ;
V_47:
return V_45 ;
}
static int F_27 ( struct V_2 * V_24 ,
enum V_42 V_51 )
{
enum V_42 V_52 = V_24 -> V_43 ;
F_28 ( & V_24 -> V_53 ) ;
switch ( V_51 ) {
case V_38 :
switch ( V_52 ) {
case V_41 :
goto V_54;
default:
break;
}
break;
case V_39 :
switch ( V_52 ) {
case V_38 :
break;
default:
goto V_54;
}
break;
case V_40 :
switch ( V_52 ) {
case V_41 :
goto V_54;
default:
break;
}
break;
case V_41 :
break;
}
V_24 -> V_43 = V_51 ;
return 0 ;
V_54:
return - V_9 ;
}
static void F_29 ( struct V_55 * V_56 )
{
struct V_2 * V_24 = F_30 ( F_31 ( V_56 ) ,
struct V_2 , V_49 ) ;
struct V_1 * V_17 = F_1 ( V_24 ) ;
int V_46 , V_45 ;
V_45 = F_32 ( V_24 ) ;
if ( V_45 != 0 ) {
F_33 ( V_57 , V_17 ,
L_12 ,
++ V_24 -> V_50 , V_45 ) ;
V_46 = V_24 -> V_6 *
F_34 ( 100 , F_35 ( 1 , V_24 -> V_50 - 10 ) ) ;
if ( V_46 > 0 )
F_20 ( V_48 ,
& V_24 -> V_49 , V_46 * V_12 ) ;
}
}
static void F_36 ( struct V_2 * V_24 )
{
struct V_1 * V_17 = F_1 ( V_24 ) ;
struct V_32 * V_26 ;
F_28 ( & V_24 -> V_53 ) ;
if ( F_27 ( V_24 , V_40 ) )
return;
F_37 ( V_24 -> V_4 . V_5 , V_58 ) ;
V_26 = F_13 ( V_17 -> V_33 ) ;
if ( V_26 -> V_34 -> V_59 )
V_26 -> V_34 -> V_59 ( V_24 ) ;
}
static void F_38 ( struct V_55 * V_56 )
{
struct V_2 * V_24 = F_30 ( F_31 ( V_56 ) ,
struct V_2 , V_60 ) ;
struct V_1 * V_17 = F_1 ( V_24 ) ;
F_39 ( L_13 ,
F_40 ( & V_24 -> V_4 ) , F_40 ( & V_17 -> V_61 ) ) ;
F_41 ( & V_24 -> V_53 ) ;
if ( V_24 -> V_43 == V_39 )
F_36 ( V_24 ) ;
F_42 ( & V_24 -> V_53 ) ;
}
static void F_43 ( struct V_55 * V_56 )
{
struct V_2 * V_24 = F_30 ( F_31 ( V_56 ) ,
struct V_2 , V_62 ) ;
struct V_1 * V_17 = F_1 ( V_24 ) ;
struct V_32 * V_26 = F_13 ( V_17 -> V_33 ) ;
F_39 ( L_14 ,
F_40 ( & V_24 -> V_4 ) , F_40 ( & V_17 -> V_61 ) ) ;
F_41 ( & V_24 -> V_53 ) ;
F_44 ( F_27 ( V_24 , V_41 ) != 0 ) ;
F_37 ( V_24 -> V_4 . V_5 , V_58 ) ;
F_42 ( & V_24 -> V_53 ) ;
V_26 -> V_34 -> V_35 ( V_24 ) ;
}
static void F_45 ( struct V_2 * V_24 )
{
struct V_1 * V_17 = F_1 ( V_24 ) ;
int V_46 , V_7 , V_8 ;
F_28 ( & V_24 -> V_53 ) ;
V_46 = V_24 -> V_6 ;
V_7 = V_24 -> V_7 ;
V_8 = V_24 -> V_8 ;
F_46 ( L_15 , F_40 ( & V_17 -> V_61 ) ,
V_24 -> V_43 ) ;
if ( V_24 -> V_43 == V_41 )
return;
if ( V_46 > 0 )
F_20 ( V_48 , & V_24 -> V_49 ,
1UL * V_46 * V_12 ) ;
if ( ( V_7 >= 0 || V_8 >= 0 ) &&
F_27 ( V_24 , V_39 ) == 0 ) {
F_46 ( L_16 , F_40 ( & V_17 -> V_61 ) ,
V_24 -> V_43 ) ;
F_47 ( & V_17 -> V_61 ) ;
if ( V_7 >= 0 )
F_20 ( V_48 ,
& V_24 -> V_60 ,
1UL * V_7 * V_12 ) ;
if ( V_8 >= 0 )
F_20 ( V_48 ,
& V_24 -> V_62 ,
1UL * V_8 * V_12 ) ;
}
}
void F_48 ( struct V_2 * V_24 )
{
F_41 ( & V_24 -> V_53 ) ;
F_45 ( V_24 ) ;
F_42 ( & V_24 -> V_53 ) ;
}
static int F_49 ( struct V_1 * V_17 )
{
struct V_63 * V_64 ;
struct V_65 * V_66 ;
int V_67 = 0 ;
F_50 (sdev, shost) {
V_66 = V_64 -> V_65 ;
F_51 ( V_66 -> V_68 ) ;
V_67 += V_66 -> V_67 ;
F_52 ( V_66 -> V_68 ) ;
}
return V_67 ;
}
int F_32 ( struct V_2 * V_24 )
{
struct V_1 * V_17 = F_1 ( V_24 ) ;
struct V_32 * V_26 = F_13 ( V_17 -> V_33 ) ;
struct V_63 * V_64 ;
int V_45 ;
F_46 ( L_17 , F_40 ( & V_17 -> V_61 ) ) ;
V_45 = F_53 ( & V_24 -> V_53 ) ;
if ( V_45 )
goto V_47;
F_47 ( & V_17 -> V_61 ) ;
while ( F_49 ( V_17 ) )
F_54 ( 20 ) ;
V_45 = V_24 -> V_43 != V_41 ? V_26 -> V_34 -> V_69 ( V_24 ) : - V_70 ;
F_46 ( L_18 ,
F_40 ( & V_17 -> V_61 ) , V_24 -> V_43 , V_45 ) ;
if ( V_45 == 0 ) {
F_21 ( & V_24 -> V_60 ) ;
F_21 ( & V_24 -> V_62 ) ;
V_24 -> V_50 = 0 ;
F_27 ( V_24 , V_38 ) ;
F_37 ( & V_17 -> V_61 , V_71 ) ;
F_51 ( V_17 -> V_72 ) ;
F_55 (sdev, shost)
if ( V_64 -> V_73 == V_74 )
V_64 -> V_73 = V_71 ;
F_52 ( V_17 -> V_72 ) ;
} else if ( V_24 -> V_43 == V_38 ) {
F_36 ( V_24 ) ;
F_37 ( & V_17 -> V_61 ,
V_58 ) ;
F_45 ( V_24 ) ;
} else if ( V_24 -> V_43 != V_39 ) {
F_37 ( & V_17 -> V_61 ,
V_58 ) ;
}
F_42 ( & V_24 -> V_53 ) ;
V_47:
return V_45 ;
}
static enum V_75 F_56 ( struct V_76 * V_77 )
{
struct V_63 * V_64 = V_77 -> V_15 ;
struct V_1 * V_17 = V_64 -> V_78 ;
struct V_32 * V_26 = F_13 ( V_17 -> V_33 ) ;
F_46 ( L_19 , F_40 ( & V_64 -> V_79 ) ) ;
return V_26 -> V_34 -> V_80 && F_57 ( V_64 ) ?
V_81 : V_82 ;
}
static void F_58 ( struct V_15 * V_4 )
{
struct V_2 * V_24 = F_59 ( V_4 ) ;
F_60 ( V_4 -> V_5 ) ;
F_61 ( V_24 ) ;
}
static int F_62 ( const struct V_15 * V_4 )
{
return V_4 -> V_83 == F_58 ;
}
static int F_63 ( struct V_84 * V_85 ,
struct V_15 * V_4 )
{
struct V_1 * V_17 ;
struct V_32 * V_26 ;
if ( ! F_62 ( V_4 ) )
return 0 ;
V_17 = F_2 ( V_4 -> V_5 ) ;
if ( ! V_17 -> V_33 )
return 0 ;
if ( V_17 -> V_33 -> V_86 . V_87 . V_88 != & V_89 . V_88 )
return 0 ;
V_26 = F_13 ( V_17 -> V_33 ) ;
return & V_26 -> V_90 . V_87 == V_85 ;
}
static int F_64 ( struct V_84 * V_85 , struct V_15 * V_4 )
{
struct V_1 * V_17 ;
struct V_32 * V_26 ;
if ( ! F_65 ( V_4 ) )
return 0 ;
V_17 = F_2 ( V_4 ) ;
if ( ! V_17 -> V_33 )
return 0 ;
if ( V_17 -> V_33 -> V_86 . V_87 . V_88 != & V_89 . V_88 )
return 0 ;
V_26 = F_13 ( V_17 -> V_33 ) ;
return & V_26 -> V_91 . V_86 . V_87 == V_85 ;
}
void F_66 ( struct V_2 * V_24 )
{
F_67 ( & V_24 -> V_4 ) ;
}
void F_68 ( struct V_2 * V_24 )
{
F_60 ( & V_24 -> V_4 ) ;
}
struct V_2 * F_69 ( struct V_1 * V_17 ,
struct V_92 * V_93 )
{
struct V_2 * V_24 ;
struct V_15 * V_5 = & V_17 -> V_61 ;
struct V_32 * V_26 = F_13 ( V_17 -> V_33 ) ;
int V_94 , V_95 ;
V_24 = F_70 ( sizeof( * V_24 ) , V_96 ) ;
if ( ! V_24 )
return F_71 ( - V_97 ) ;
F_72 ( & V_24 -> V_53 ) ;
F_73 ( & V_24 -> V_4 ) ;
V_24 -> V_4 . V_5 = F_67 ( V_5 ) ;
V_24 -> V_4 . V_83 = F_58 ;
memcpy ( V_24 -> V_98 , V_93 -> V_98 , sizeof( V_24 -> V_98 ) ) ;
V_24 -> V_30 = V_93 -> V_30 ;
if ( V_26 -> V_34 -> V_69 )
V_24 -> V_6 = V_26 -> V_34 -> V_6 ?
* V_26 -> V_34 -> V_6 : 10 ;
F_74 ( & V_24 -> V_49 , F_29 ) ;
V_24 -> V_7 = V_26 -> V_34 -> V_7 ?
* V_26 -> V_34 -> V_7 : 15 ;
V_24 -> V_8 = V_26 -> V_34 -> V_8 ? * V_26 -> V_34 -> V_8 : 60 ;
F_74 ( & V_24 -> V_60 ,
F_38 ) ;
F_74 ( & V_24 -> V_62 , F_43 ) ;
V_94 = F_75 ( & F_5 ( V_17 ) -> V_20 ) ;
F_76 ( & V_24 -> V_4 , L_20 , V_17 -> V_99 , V_94 ) ;
F_77 ( & V_24 -> V_4 ) ;
V_95 = F_78 ( & V_24 -> V_4 ) ;
if ( V_95 ) {
F_79 ( & V_24 -> V_4 ) ;
F_60 ( & V_24 -> V_4 ) ;
return F_71 ( V_95 ) ;
}
F_80 ( & V_24 -> V_4 ) ;
F_81 ( & V_24 -> V_4 ) ;
return V_24 ;
}
void F_82 ( struct V_2 * V_24 )
{
struct V_15 * V_4 = & V_24 -> V_4 ;
F_83 ( V_4 ) ;
F_84 ( V_4 ) ;
F_79 ( V_4 ) ;
F_60 ( V_4 ) ;
}
static int F_85 ( struct V_15 * V_4 , void * V_100 )
{
if ( F_62 ( V_4 ) )
F_82 ( F_59 ( V_4 ) ) ;
return 0 ;
}
void F_86 ( struct V_1 * V_17 )
{
F_87 ( & V_17 -> V_61 , NULL , F_85 ) ;
}
void F_88 ( struct V_2 * V_24 )
{
F_41 ( & V_24 -> V_53 ) ;
if ( V_24 -> V_43 == V_39 )
F_36 ( V_24 ) ;
F_27 ( V_24 , V_41 ) ;
F_42 ( & V_24 -> V_53 ) ;
F_89 ( & V_24 -> V_49 ) ;
F_89 ( & V_24 -> V_60 ) ;
F_89 ( & V_24 -> V_62 ) ;
}
static int F_90 ( struct V_1 * V_17 , T_3 V_101 , T_3 V_102 ,
int V_103 )
{
struct V_32 * V_26 = F_13 ( V_17 -> V_33 ) ;
return V_26 -> V_34 -> V_104 ( V_17 , V_101 , V_102 , V_103 ) ;
}
static int F_91 ( struct V_1 * V_17 , T_3 V_101 , int V_103 )
{
struct V_32 * V_26 = F_13 ( V_17 -> V_33 ) ;
return V_26 -> V_34 -> V_105 ( V_17 , V_101 , V_103 ) ;
}
struct V_106 *
F_92 ( struct V_107 * V_108 )
{
int V_31 ;
struct V_32 * V_26 ;
V_26 = F_70 ( sizeof( * V_26 ) , V_96 ) ;
if ( ! V_26 )
return NULL ;
V_26 -> V_91 . V_109 = F_56 ;
V_26 -> V_91 . V_104 = F_90 ;
V_26 -> V_91 . V_105 = F_91 ;
V_26 -> V_91 . V_110 = sizeof( struct V_18 ) ;
V_26 -> V_91 . V_86 . V_87 . V_111 = & V_26 -> V_86 [ 0 ] ;
V_26 -> V_91 . V_86 . V_87 . V_88 = & V_89 . V_88 ;
V_26 -> V_91 . V_86 . V_87 . V_112 = F_64 ;
V_26 -> V_86 [ 0 ] = NULL ;
F_93 ( & V_26 -> V_91 . V_86 ) ;
V_26 -> V_90 . V_87 . V_111 = & V_26 -> V_113 [ 0 ] ;
V_26 -> V_90 . V_87 . V_88 = & V_114 . V_88 ;
V_26 -> V_90 . V_87 . V_112 = F_63 ;
V_31 = 0 ;
V_26 -> V_113 [ V_31 ++ ] = & V_115 ;
V_26 -> V_113 [ V_31 ++ ] = & V_116 ;
if ( V_108 -> V_117 ) {
V_26 -> V_113 [ V_31 ++ ] = & V_118 ;
V_26 -> V_113 [ V_31 ++ ] = & V_119 ;
V_26 -> V_113 [ V_31 ++ ] = & V_120 ;
}
if ( V_108 -> V_69 ) {
V_26 -> V_113 [ V_31 ++ ] = & V_121 ;
V_26 -> V_113 [ V_31 ++ ] = & V_122 ;
}
if ( V_108 -> V_35 )
V_26 -> V_113 [ V_31 ++ ] = & V_123 ;
V_26 -> V_113 [ V_31 ++ ] = NULL ;
F_94 ( V_31 > F_11 ( V_26 -> V_113 ) ) ;
F_93 ( & V_26 -> V_90 ) ;
V_26 -> V_34 = V_108 ;
return & V_26 -> V_91 ;
}
void F_95 ( struct V_106 * V_91 )
{
struct V_32 * V_26 = F_13 ( V_91 ) ;
F_96 ( & V_26 -> V_91 . V_86 ) ;
F_96 ( & V_26 -> V_90 ) ;
F_61 ( V_26 ) ;
}
static T_4 int F_97 ( void )
{
int V_95 ;
V_95 = F_98 ( & V_89 ) ;
if ( V_95 )
return V_95 ;
V_95 = F_98 ( & V_114 ) ;
if ( V_95 )
goto V_124;
return 0 ;
V_124:
F_99 ( & V_89 ) ;
return V_95 ;
}
static void T_5 F_100 ( void )
{
F_99 ( & V_89 ) ;
F_99 ( & V_114 ) ;
}
