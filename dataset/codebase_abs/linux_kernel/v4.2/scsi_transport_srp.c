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
return sprintf ( V_24 , V_26 L_1 , F_10 ( V_25 ) ) ;
}
static T_1
F_11 ( struct V_17 * V_4 , struct V_22 * V_23 ,
char * V_24 )
{
struct V_2 * V_25 = F_4 ( V_4 ) ;
int V_27 ;
char * V_28 = NULL ;
for ( V_27 = 0 ; V_27 < F_12 ( V_29 ) ; V_27 ++ )
if ( V_29 [ V_27 ] . V_30 == V_25 -> V_31 ) {
V_28 = V_29 [ V_27 ] . V_28 ;
break;
}
return sprintf ( V_24 , L_2 , V_28 ? : L_3 ) ;
}
static T_1 F_13 ( struct V_17 * V_4 ,
struct V_22 * V_23 ,
const char * V_24 , T_2 V_32 )
{
struct V_2 * V_25 = F_4 ( V_4 ) ;
struct V_1 * V_6 = F_2 ( V_4 ) ;
struct V_33 * V_27 = F_14 ( V_6 -> V_34 ) ;
if ( V_27 -> V_35 -> V_36 ) {
V_27 -> V_35 -> V_36 ( V_25 ) ;
return V_32 ;
} else {
return - V_37 ;
}
}
static T_1 F_15 ( struct V_17 * V_4 ,
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
( unsigned ) V_44 < F_12 ( V_38 ) ?
V_38 [ V_44 ] : L_8 ) ;
}
static T_1 F_16 ( char * V_24 , int V_45 )
{
return V_45 >= 0 ? sprintf ( V_24 , L_9 , V_45 ) : sprintf ( V_24 , L_10 ) ;
}
int F_17 ( int * V_45 , const char * V_24 )
{
int V_46 = 0 ;
if ( strncmp ( V_24 , L_11 , 3 ) != 0 )
V_46 = F_18 ( V_24 , 0 , V_45 ) ;
else
* V_45 = - 1 ;
return V_46 ;
}
static T_1 F_19 ( struct V_17 * V_4 ,
struct V_22 * V_23 , char * V_24 )
{
struct V_2 * V_25 = F_4 ( V_4 ) ;
return F_16 ( V_24 , V_25 -> V_8 ) ;
}
static T_1 F_20 ( struct V_17 * V_4 ,
struct V_22 * V_23 ,
const char * V_24 , const T_2 V_32 )
{
struct V_2 * V_25 = F_4 ( V_4 ) ;
int V_46 , V_47 ;
V_46 = F_17 ( & V_47 , V_24 ) ;
if ( V_46 )
goto V_48;
V_46 = F_5 ( V_47 , V_25 -> V_9 ,
V_25 -> V_10 ) ;
if ( V_46 )
goto V_48;
if ( V_25 -> V_8 <= 0 && V_47 > 0 &&
V_25 -> V_44 != V_39 ) {
F_21 ( V_49 , & V_25 -> V_50 ,
V_47 * V_14 ) ;
} else if ( V_47 <= 0 ) {
F_22 ( & V_25 -> V_50 ) ;
}
V_25 -> V_8 = V_47 ;
V_46 = V_32 ;
V_48:
return V_46 ;
}
static T_1 F_23 ( struct V_17 * V_4 ,
struct V_22 * V_23 , char * V_24 )
{
struct V_2 * V_25 = F_4 ( V_4 ) ;
return sprintf ( V_24 , L_9 , V_25 -> V_51 ) ;
}
static T_1 F_24 ( struct V_17 * V_4 ,
struct V_22 * V_23 ,
char * V_24 )
{
struct V_2 * V_25 = F_4 ( V_4 ) ;
return F_16 ( V_24 , V_25 -> V_9 ) ;
}
static T_1 F_25 ( struct V_17 * V_4 ,
struct V_22 * V_23 ,
const char * V_24 , T_2 V_32 )
{
struct V_2 * V_25 = F_4 ( V_4 ) ;
int V_46 ;
int V_9 ;
V_46 = F_17 ( & V_9 , V_24 ) ;
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
static T_1 F_26 ( struct V_17 * V_4 ,
struct V_22 * V_23 ,
char * V_24 )
{
struct V_2 * V_25 = F_4 ( V_4 ) ;
return F_16 ( V_24 , V_25 -> V_10 ) ;
}
static T_1 F_27 ( struct V_17 * V_4 ,
struct V_22 * V_23 ,
const char * V_24 , T_2 V_32 )
{
struct V_2 * V_25 = F_4 ( V_4 ) ;
int V_46 ;
int V_10 ;
V_46 = F_17 ( & V_10 , V_24 ) ;
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
static int F_28 ( struct V_2 * V_25 ,
enum V_43 V_52 )
{
enum V_43 V_53 = V_25 -> V_44 ;
F_29 ( & V_25 -> V_54 ) ;
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
static void F_30 ( struct V_56 * V_57 )
{
struct V_2 * V_25 = F_31 ( F_32 ( V_57 ) ,
struct V_2 , V_50 ) ;
struct V_1 * V_6 = F_1 ( V_25 ) ;
int V_47 , V_46 ;
V_46 = F_33 ( V_25 ) ;
if ( V_46 != 0 ) {
F_34 ( V_58 , V_6 ,
L_12 ,
++ V_25 -> V_51 , V_46 ) ;
V_47 = V_25 -> V_8 *
F_35 ( 100 , F_36 ( 1 , V_25 -> V_51 - 10 ) ) ;
if ( V_47 > 0 )
F_21 ( V_49 ,
& V_25 -> V_50 , V_47 * V_14 ) ;
}
}
static int F_37 ( struct V_1 * V_6 )
{
struct V_59 * V_60 ;
struct V_61 * V_62 ;
int V_63 = 0 ;
F_38 (sdev, shost) {
V_62 = V_60 -> V_61 ;
F_39 ( V_62 -> V_64 ) ;
V_63 += V_62 -> V_63 ;
F_40 ( V_62 -> V_64 ) ;
}
return V_63 ;
}
static void F_41 ( struct V_1 * V_6 )
{
while ( F_37 ( V_6 ) )
F_42 ( 20 ) ;
}
static void F_43 ( struct V_2 * V_25 )
{
struct V_1 * V_6 = F_1 ( V_25 ) ;
struct V_33 * V_27 ;
F_29 ( & V_25 -> V_54 ) ;
if ( F_28 ( V_25 , V_41 ) )
return;
F_44 ( V_25 -> V_4 . V_5 , V_65 ) ;
V_27 = F_14 ( V_6 -> V_34 ) ;
if ( V_27 -> V_35 -> V_66 ) {
F_41 ( V_6 ) ;
V_27 -> V_35 -> V_66 ( V_25 ) ;
}
}
static void F_45 ( struct V_56 * V_57 )
{
struct V_2 * V_25 = F_31 ( F_32 ( V_57 ) ,
struct V_2 , V_67 ) ;
struct V_1 * V_6 = F_1 ( V_25 ) ;
F_46 ( L_13 ,
F_47 ( & V_25 -> V_4 ) , F_47 ( & V_6 -> V_7 ) ) ;
F_48 ( & V_25 -> V_54 ) ;
if ( V_25 -> V_44 == V_40 )
F_43 ( V_25 ) ;
F_49 ( & V_25 -> V_54 ) ;
}
static void F_50 ( struct V_56 * V_57 )
{
struct V_2 * V_25 = F_31 ( F_32 ( V_57 ) ,
struct V_2 , V_68 ) ;
struct V_1 * V_6 = F_1 ( V_25 ) ;
struct V_33 * V_27 = F_14 ( V_6 -> V_34 ) ;
F_46 ( L_14 ,
F_47 ( & V_25 -> V_4 ) , F_47 ( & V_6 -> V_7 ) ) ;
F_48 ( & V_25 -> V_54 ) ;
F_51 ( F_28 ( V_25 , V_42 ) != 0 ) ;
F_44 ( V_25 -> V_4 . V_5 , V_65 ) ;
F_49 ( & V_25 -> V_54 ) ;
V_27 -> V_35 -> V_36 ( V_25 ) ;
}
static void F_52 ( struct V_2 * V_25 )
{
struct V_1 * V_6 = F_1 ( V_25 ) ;
int V_47 , V_9 , V_10 ;
F_29 ( & V_25 -> V_54 ) ;
V_47 = V_25 -> V_8 ;
V_9 = V_25 -> V_9 ;
V_10 = V_25 -> V_10 ;
F_53 ( L_15 , F_47 ( & V_6 -> V_7 ) ,
V_25 -> V_44 ) ;
if ( V_25 -> V_44 == V_42 )
return;
if ( V_47 > 0 )
F_21 ( V_49 , & V_25 -> V_50 ,
1UL * V_47 * V_14 ) ;
if ( ( V_9 >= 0 || V_10 >= 0 ) &&
F_28 ( V_25 , V_40 ) == 0 ) {
F_53 ( L_16 , F_47 ( & V_6 -> V_7 ) ,
V_25 -> V_44 ) ;
F_54 ( & V_6 -> V_7 ) ;
if ( V_9 >= 0 )
F_21 ( V_49 ,
& V_25 -> V_67 ,
1UL * V_9 * V_14 ) ;
if ( V_10 >= 0 )
F_21 ( V_49 ,
& V_25 -> V_68 ,
1UL * V_10 * V_14 ) ;
}
}
void F_55 ( struct V_2 * V_25 )
{
F_48 ( & V_25 -> V_54 ) ;
F_52 ( V_25 ) ;
F_49 ( & V_25 -> V_54 ) ;
}
int F_33 ( struct V_2 * V_25 )
{
struct V_1 * V_6 = F_1 ( V_25 ) ;
struct V_33 * V_27 = F_14 ( V_6 -> V_34 ) ;
struct V_59 * V_60 ;
int V_46 ;
F_53 ( L_17 , F_47 ( & V_6 -> V_7 ) ) ;
V_46 = F_56 ( & V_25 -> V_54 ) ;
if ( V_46 )
goto V_48;
F_54 ( & V_6 -> V_7 ) ;
F_41 ( V_6 ) ;
V_46 = V_25 -> V_44 != V_42 ? V_27 -> V_35 -> V_69 ( V_25 ) : - V_70 ;
F_53 ( L_18 ,
F_47 ( & V_6 -> V_7 ) , V_25 -> V_44 , V_46 ) ;
if ( V_46 == 0 ) {
F_22 ( & V_25 -> V_67 ) ;
F_22 ( & V_25 -> V_68 ) ;
V_25 -> V_51 = 0 ;
F_28 ( V_25 , V_39 ) ;
F_44 ( & V_6 -> V_7 , V_71 ) ;
F_39 ( V_6 -> V_72 ) ;
F_57 (sdev, shost)
if ( V_60 -> V_73 == V_74 )
V_60 -> V_73 = V_71 ;
F_40 ( V_6 -> V_72 ) ;
} else if ( V_25 -> V_44 == V_39 ) {
F_43 ( V_25 ) ;
F_44 ( & V_6 -> V_7 ,
V_65 ) ;
F_52 ( V_25 ) ;
} else if ( V_25 -> V_44 != V_40 ) {
F_44 ( & V_6 -> V_7 ,
V_65 ) ;
}
F_49 ( & V_25 -> V_54 ) ;
V_48:
return V_46 ;
}
static enum V_75 F_58 ( struct V_76 * V_77 )
{
struct V_59 * V_60 = V_77 -> V_17 ;
struct V_1 * V_6 = V_60 -> V_78 ;
struct V_33 * V_27 = F_14 ( V_6 -> V_34 ) ;
struct V_2 * V_25 = F_3 ( V_6 ) ;
F_53 ( L_19 , F_47 ( & V_60 -> V_79 ) ) ;
return V_25 -> V_9 < 0 && V_25 -> V_10 < 0 &&
V_27 -> V_35 -> V_80 && F_59 ( V_60 ) ?
V_81 : V_82 ;
}
static void F_60 ( struct V_17 * V_4 )
{
struct V_2 * V_25 = F_61 ( V_4 ) ;
F_62 ( V_4 -> V_5 ) ;
F_63 ( V_25 ) ;
}
static int F_64 ( const struct V_17 * V_4 )
{
return V_4 -> V_83 == F_60 ;
}
static int F_65 ( struct V_84 * V_85 ,
struct V_17 * V_4 )
{
struct V_1 * V_6 ;
struct V_33 * V_27 ;
if ( ! F_64 ( V_4 ) )
return 0 ;
V_6 = F_2 ( V_4 -> V_5 ) ;
if ( ! V_6 -> V_34 )
return 0 ;
if ( V_6 -> V_34 -> V_86 . V_87 . V_88 != & V_89 . V_88 )
return 0 ;
V_27 = F_14 ( V_6 -> V_34 ) ;
return & V_27 -> V_90 . V_87 == V_85 ;
}
static int F_66 ( struct V_84 * V_85 , struct V_17 * V_4 )
{
struct V_1 * V_6 ;
struct V_33 * V_27 ;
if ( ! F_67 ( V_4 ) )
return 0 ;
V_6 = F_2 ( V_4 ) ;
if ( ! V_6 -> V_34 )
return 0 ;
if ( V_6 -> V_34 -> V_86 . V_87 . V_88 != & V_89 . V_88 )
return 0 ;
V_27 = F_14 ( V_6 -> V_34 ) ;
return & V_27 -> V_91 . V_86 . V_87 == V_85 ;
}
void F_68 ( struct V_2 * V_25 )
{
F_69 ( & V_25 -> V_4 ) ;
}
void F_70 ( struct V_2 * V_25 )
{
F_62 ( & V_25 -> V_4 ) ;
}
struct V_2 * F_71 ( struct V_1 * V_6 ,
struct V_92 * V_93 )
{
struct V_2 * V_25 ;
struct V_17 * V_5 = & V_6 -> V_7 ;
struct V_33 * V_27 = F_14 ( V_6 -> V_34 ) ;
int V_94 , V_95 ;
V_25 = F_72 ( sizeof( * V_25 ) , V_96 ) ;
if ( ! V_25 )
return F_73 ( - V_97 ) ;
F_74 ( & V_25 -> V_54 ) ;
F_75 ( & V_25 -> V_4 ) ;
V_25 -> V_4 . V_5 = F_69 ( V_5 ) ;
V_25 -> V_4 . V_83 = F_60 ;
memcpy ( V_25 -> V_98 , V_93 -> V_98 , sizeof( V_25 -> V_98 ) ) ;
V_25 -> V_31 = V_93 -> V_31 ;
if ( V_27 -> V_35 -> V_69 )
V_25 -> V_8 = V_27 -> V_35 -> V_8 ?
* V_27 -> V_35 -> V_8 : 10 ;
F_76 ( & V_25 -> V_50 , F_30 ) ;
V_25 -> V_9 = V_27 -> V_35 -> V_9 ?
* V_27 -> V_35 -> V_9 : 15 ;
V_25 -> V_10 = V_27 -> V_35 -> V_10 ? * V_27 -> V_35 -> V_10 : 60 ;
F_76 ( & V_25 -> V_67 ,
F_45 ) ;
F_76 ( & V_25 -> V_68 , F_50 ) ;
V_94 = F_77 ( & F_7 ( V_6 ) -> V_21 ) ;
F_78 ( & V_25 -> V_4 , L_20 , V_6 -> V_99 , V_94 ) ;
F_79 ( & V_25 -> V_4 ) ;
V_95 = F_80 ( & V_25 -> V_4 ) ;
if ( V_95 ) {
F_81 ( & V_25 -> V_4 ) ;
F_62 ( & V_25 -> V_4 ) ;
return F_73 ( V_95 ) ;
}
F_82 ( & V_25 -> V_4 ) ;
F_83 ( & V_25 -> V_4 ) ;
return V_25 ;
}
void F_84 ( struct V_2 * V_25 )
{
struct V_17 * V_4 = & V_25 -> V_4 ;
F_85 ( V_4 ) ;
F_86 ( V_4 ) ;
F_81 ( V_4 ) ;
F_62 ( V_4 ) ;
}
static int F_87 ( struct V_17 * V_4 , void * V_100 )
{
if ( F_64 ( V_4 ) )
F_84 ( F_61 ( V_4 ) ) ;
return 0 ;
}
void F_88 ( struct V_1 * V_6 )
{
F_89 ( & V_6 -> V_7 , NULL , F_87 ) ;
}
void F_90 ( struct V_2 * V_25 )
{
F_48 ( & V_25 -> V_54 ) ;
if ( V_25 -> V_44 == V_40 )
F_43 ( V_25 ) ;
F_28 ( V_25 , V_42 ) ;
F_49 ( & V_25 -> V_54 ) ;
F_91 ( & V_25 -> V_50 ) ;
F_91 ( & V_25 -> V_67 ) ;
F_91 ( & V_25 -> V_68 ) ;
}
static int F_92 ( struct V_1 * V_6 , T_3 V_101 , T_3 V_102 ,
int V_103 )
{
struct V_33 * V_27 = F_14 ( V_6 -> V_34 ) ;
return V_27 -> V_35 -> V_104 ( V_6 , V_101 , V_102 , V_103 ) ;
}
static int F_93 ( struct V_1 * V_6 , T_3 V_101 , int V_103 )
{
struct V_33 * V_27 = F_14 ( V_6 -> V_34 ) ;
return V_27 -> V_35 -> V_105 ( V_6 , V_101 , V_103 ) ;
}
struct V_106 *
F_94 ( struct V_107 * V_108 )
{
int V_32 ;
struct V_33 * V_27 ;
V_27 = F_72 ( sizeof( * V_27 ) , V_96 ) ;
if ( ! V_27 )
return NULL ;
V_27 -> V_91 . V_109 = F_58 ;
V_27 -> V_91 . V_104 = F_92 ;
V_27 -> V_91 . V_105 = F_93 ;
V_27 -> V_91 . V_110 = sizeof( struct V_19 ) ;
V_27 -> V_91 . V_86 . V_87 . V_111 = & V_27 -> V_86 [ 0 ] ;
V_27 -> V_91 . V_86 . V_87 . V_88 = & V_89 . V_88 ;
V_27 -> V_91 . V_86 . V_87 . V_112 = F_66 ;
V_27 -> V_86 [ 0 ] = NULL ;
F_95 ( & V_27 -> V_91 . V_86 ) ;
V_27 -> V_90 . V_87 . V_111 = & V_27 -> V_113 [ 0 ] ;
V_27 -> V_90 . V_87 . V_88 = & V_114 . V_88 ;
V_27 -> V_90 . V_87 . V_112 = F_65 ;
V_32 = 0 ;
V_27 -> V_113 [ V_32 ++ ] = & V_115 ;
V_27 -> V_113 [ V_32 ++ ] = & V_116 ;
if ( V_108 -> V_117 ) {
V_27 -> V_113 [ V_32 ++ ] = & V_118 ;
V_27 -> V_113 [ V_32 ++ ] = & V_119 ;
V_27 -> V_113 [ V_32 ++ ] = & V_120 ;
}
if ( V_108 -> V_69 ) {
V_27 -> V_113 [ V_32 ++ ] = & V_121 ;
V_27 -> V_113 [ V_32 ++ ] = & V_122 ;
}
if ( V_108 -> V_36 )
V_27 -> V_113 [ V_32 ++ ] = & V_123 ;
V_27 -> V_113 [ V_32 ++ ] = NULL ;
F_96 ( V_32 > F_12 ( V_27 -> V_113 ) ) ;
F_95 ( & V_27 -> V_90 ) ;
V_27 -> V_35 = V_108 ;
return & V_27 -> V_91 ;
}
void F_97 ( struct V_106 * V_91 )
{
struct V_33 * V_27 = F_14 ( V_91 ) ;
F_98 ( & V_27 -> V_91 . V_86 ) ;
F_98 ( & V_27 -> V_90 ) ;
F_63 ( V_27 ) ;
}
static T_4 int F_99 ( void )
{
int V_95 ;
V_95 = F_100 ( & V_89 ) ;
if ( V_95 )
return V_95 ;
V_95 = F_100 ( & V_114 ) ;
if ( V_95 )
goto V_124;
return 0 ;
V_124:
F_101 ( & V_89 ) ;
return V_95 ;
}
static void T_5 F_102 ( void )
{
F_101 ( & V_89 ) ;
F_101 ( & V_114 ) ;
}
