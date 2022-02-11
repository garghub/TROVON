int F_1 ( void )
{
return V_1 ;
}
int F_2 ( void )
{
return V_2 ;
}
int F_3 ( void )
{
return V_3 ;
}
int F_4 ( void )
{
return V_4 ;
}
static int F_5 ( const char * V_5 , struct V_6 * V_7 )
{
long V_8 ;
int V_9 ;
if ( ! V_5 )
return - V_10 ;
V_9 = F_6 ( V_5 , 0 , & V_8 ) ;
if ( V_9 == - V_10 || ( ( int ) V_8 != V_8 ) )
return - V_10 ;
* ( ( int * ) V_7 -> V_11 ) = V_8 ;
F_7 ( V_8 ) ;
return 0 ;
}
static T_1 F_8 ( struct V_12 * V_13 , char * V_14 ,
int V_15 )
{
return sprintf ( V_14 , L_1 , V_13 -> V_16 ) ;
}
static T_1 F_9 ( struct V_12 * V_13 , char * V_14 ,
int V_15 )
{
return sprintf ( V_14 , L_1 , V_13 -> V_17 ) ;
}
static T_1 F_10 ( struct V_12 * V_13 , char * V_14 ,
int V_15 )
{
int V_18 ;
T_2 V_19 = 0 ;
for ( V_18 = 0 ; V_18 < V_13 -> V_20 ; V_18 ++ )
V_19 += V_13 -> V_21 [ V_18 ] . V_22 -> V_19 ;
return sprintf ( V_14 , L_1 , F_11 ( V_19 ) ) ;
}
static T_1 F_12 ( struct V_12 * V_13 , char * V_14 ,
int V_15 )
{
return sprintf ( V_14 , L_2 , V_23 [ V_13 -> V_21 [ 0 ] . V_22 -> V_24 ] ) ;
}
static T_1 F_13 ( struct V_12 * V_13 , char * V_14 ,
int V_15 )
{
return sprintf ( V_14 , L_2 , V_25 [ V_13 -> V_21 [ 0 ] . V_22 -> V_26 ] ) ;
}
static T_1 F_14 ( struct V_12 * V_13 , char * V_14 ,
int V_15 )
{
return sprintf ( V_14 , L_2 , V_27 [ V_13 -> V_21 [ 0 ] . V_22 -> V_28 ] ) ;
}
static T_1 F_15 ( struct V_12 * V_13 ,
char * V_14 , int V_29 )
{
if ( ! V_13 -> V_21 [ V_29 ] . V_22 -> V_30 [ 0 ] )
return 0 ;
return snprintf ( V_14 , V_31 , L_2 ,
V_13 -> V_21 [ V_29 ] . V_22 -> V_30 ) ;
}
static T_1 F_16 ( struct V_12 * V_13 ,
const char * V_14 ,
T_3 V_32 , int V_29 )
{
T_1 V_33 = 0 ;
V_33 = F_17 ( ( T_1 ) V_32 , ( T_1 ) V_31 - 1 ) ;
strncpy ( V_13 -> V_21 [ V_29 ] . V_22 -> V_30 , V_14 , V_33 ) ;
V_13 -> V_21 [ V_29 ] . V_22 -> V_30 [ V_33 ] = '\0' ;
return V_33 ;
}
static T_1 F_18 ( struct V_12 * V_13 ,
char * V_14 , int V_29 )
{
return sprintf ( V_14 , L_1 , V_13 -> V_21 [ V_29 ] . V_17 ) ;
}
static T_1 F_19 ( struct V_34 * V_35 ,
struct V_36 * V_37 , char * V_38 )
{
struct V_12 * V_13 = F_20 ( V_35 ) ;
struct V_39 * V_40 = F_21 ( V_37 ) ;
if ( V_40 -> V_41 )
return V_40 -> V_41 ( V_13 ,
V_38 , V_40 -> V_15 ) ;
return - V_42 ;
}
static T_1 F_22 ( struct V_34 * V_35 , struct V_36 * V_37 ,
const char * V_38 , T_3 V_32 )
{
struct V_12 * V_13 = F_20 ( V_35 ) ;
struct V_39 * V_40 = F_21 ( V_37 ) ;
if ( V_40 -> V_43 )
return V_40 -> V_43 ( V_13 ,
V_38 ,
V_32 , V_40 -> V_15 ) ;
return - V_42 ;
}
static int F_23 ( struct V_34 * V_35 , int V_44 )
{
int V_45 = - V_46 ;
if ( V_44 >= V_47 )
return V_45 ;
V_45 = F_24 ( V_35 ,
(struct V_36 * )
V_48 [ V_44 ] ) ;
if ( ! V_45 ) {
V_45 = F_24 ( V_35 ,
(struct V_36 * )
V_49 [ V_44 ] ) ;
} else {
F_25 ( L_3 ,
V_50 ) ;
}
return V_45 ;
}
static void F_26 ( struct V_34 * V_35 )
{
struct V_51 * V_52 ;
struct V_12 * V_53 ;
F_25 ( L_4 , V_50 ) ;
V_53 = F_27 ( V_35 , struct V_12 , V_35 ) ;
V_52 = V_53 -> V_52 ;
F_28 ( & V_52 -> V_54 ) ;
}
static int F_29 ( struct V_51 * V_52 ,
struct V_12 * V_13 , int V_55 )
{
struct V_34 * V_56 = & V_52 -> V_54 ;
struct V_34 * V_35 ;
int V_44 ;
int V_45 ;
memset ( & V_13 -> V_35 , 0 , sizeof( V_13 -> V_35 ) ) ;
V_13 -> V_52 = V_52 ;
V_35 = F_30 ( & V_52 -> V_54 ) ;
if ( ! V_35 ) {
V_45 = - V_46 ;
goto V_57;
}
V_45 = F_31 ( & V_13 -> V_35 , & V_58 , V_56 ,
L_5 , V_55 ) ;
if ( V_45 )
goto V_59;
for ( V_44 = 0 ; V_44 < V_13 -> V_20 ; V_44 ++ ) {
V_45 = F_23 ( & V_13 -> V_35 , V_44 ) ;
if ( V_45 ) {
F_28 ( & V_13 -> V_35 ) ;
goto V_57;
}
}
F_32 ( & V_13 -> V_35 , V_60 ) ;
return 0 ;
V_59:
F_28 ( & V_52 -> V_54 ) ;
V_57:
return V_45 ;
}
static T_1 F_33 ( struct V_51 * V_52 ,
const char * V_14 , T_3 V_32 )
{
int V_61 , V_44 ;
V_52 -> V_62 = 0 ;
V_52 -> V_63 = 0 ;
V_52 -> V_64 = 0 ;
V_52 -> V_65 = 0 ;
for ( V_61 = 0 ; V_61 < V_52 -> V_66 ; V_61 ++ ) {
struct V_12 * V_67 = & V_52 -> V_68 [ V_61 ] ;
V_67 -> V_16 = 0 ;
V_67 -> V_17 = 0 ;
for ( V_44 = 0 ; V_44 < V_67 -> V_20 ; V_44 ++ )
V_67 -> V_21 [ V_44 ] . V_17 = 0 ;
}
V_52 -> V_69 = V_70 ;
return V_32 ;
}
static T_1 F_34 ( struct V_51 * V_52 ,
const char * V_14 , T_3 V_32 )
{
unsigned long V_71 = 0 ;
int V_72 = 0 ;
if ( ! V_52 -> V_73 )
return - V_46 ;
if ( F_35 ( V_14 , 10 , & V_71 ) < 0 )
return - V_10 ;
V_72 = V_52 -> V_73 ( V_52 , V_71 ) ;
if ( V_72 < 0 ) {
F_36 ( V_74 , V_75 ,
L_6 , V_71 ) ;
return - V_10 ;
}
return V_32 ;
}
static T_1 F_37 ( struct V_51 * V_52 , char * V_14 )
{
int V_71 = 0 ;
if ( ! V_52 -> V_76 )
return - V_46 ;
V_71 = V_52 -> V_76 ( V_52 ) ;
if ( V_71 < 0 ) {
F_36 ( V_77 , V_75 , L_7 ) ;
return V_71 ;
}
return sprintf ( V_14 , L_8 , V_71 ) ;
}
static T_1 F_38 ( struct V_51 * V_52 , char * V_14 )
{
return sprintf ( V_14 , L_8 , V_52 -> V_64 ) ;
}
static T_1 F_39 ( struct V_51 * V_52 , char * V_14 )
{
return sprintf ( V_14 , L_8 , V_52 -> V_65 ) ;
}
static T_1 F_40 ( struct V_51 * V_52 , char * V_14 )
{
return sprintf ( V_14 , L_8 , V_52 -> V_63 ) ;
}
static T_1 F_41 ( struct V_51 * V_52 , char * V_14 )
{
return sprintf ( V_14 , L_8 , V_52 -> V_62 ) ;
}
static T_1 F_42 ( struct V_51 * V_52 , char * V_14 )
{
return sprintf ( V_14 , L_9 , ( V_70 - V_52 -> V_69 ) / V_78 ) ;
}
static T_1 F_43 ( struct V_51 * V_52 , char * V_14 )
{
return sprintf ( V_14 , L_2 , V_52 -> V_79 ) ;
}
static T_1 F_44 ( struct V_51 * V_52 , char * V_14 )
{
int V_80 = 0 , V_81 , V_82 ;
for ( V_81 = 0 ; V_81 < V_52 -> V_66 ; V_81 ++ ) {
struct V_12 * V_13 = & V_52 -> V_68 [ V_81 ] ;
for ( V_82 = 0 ; V_82 < V_13 -> V_20 ; V_82 ++ ) {
struct V_83 * V_22 = V_13 -> V_21 [ V_82 ] . V_22 ;
V_80 += V_22 -> V_19 ;
}
}
return sprintf ( V_14 , L_1 , F_11 ( V_80 ) ) ;
}
static T_1 F_45 ( struct V_34 * V_35 , struct V_36 * V_37 ,
char * V_38 )
{
struct V_51 * V_51 = F_46 ( V_35 ) ;
struct V_84 * V_85 = F_47 ( V_37 ) ;
F_25 ( L_10 , V_50 , V_51 ) ;
if ( V_85 -> V_41 )
return V_85 -> V_41 ( V_51 , V_38 ) ;
return - V_42 ;
}
static T_1 F_48 ( struct V_34 * V_35 , struct V_36 * V_37 ,
const char * V_38 , T_3 V_32 )
{
struct V_51 * V_51 = F_46 ( V_35 ) ;
struct V_84 * V_85 = F_47 ( V_37 ) ;
F_25 ( L_10 , V_50 , V_51 ) ;
if ( V_85 -> V_43 )
return V_85 -> V_43 ( V_51 , V_38 , V_32 ) ;
return - V_42 ;
}
static void F_49 ( struct V_34 * V_35 )
{
struct V_51 * V_52 ;
V_52 = F_46 ( V_35 ) ;
F_50 ( L_11 , V_50 , V_52 -> V_86 ) ;
F_51 ( V_52 -> V_87 ) ;
}
int F_52 ( struct V_51 * V_52 )
{
struct V_34 * V_56 ;
int V_45 ;
F_25 ( L_4 , V_50 ) ;
V_56 = & V_52 -> V_54 ;
memset ( V_56 , 0 , sizeof( * V_56 ) ) ;
V_52 -> V_87 = V_88 ;
if ( ! F_53 ( V_52 -> V_87 ) ) {
V_45 = - V_46 ;
goto V_89;
}
V_56 -> V_90 = V_91 ;
V_45 = F_31 ( V_56 , & V_92 , NULL ,
L_12 , V_52 -> V_86 ) ;
if ( V_45 ) {
F_25 ( L_13 ,
V_50 , V_52 -> V_86 ) ;
goto V_93;
}
F_32 ( V_56 , V_60 ) ;
F_25 ( L_14 ,
V_50 , V_52 -> V_86 ) ;
return 0 ;
V_93:
F_51 ( V_52 -> V_87 ) ;
V_89:
return V_45 ;
}
void F_54 ( struct V_51 * V_52 )
{
F_25 ( L_4 , V_50 ) ;
F_28 ( & V_52 -> V_54 ) ;
}
static T_1 F_55 ( struct V_34 * V_35 , struct V_36 * V_37 ,
char * V_38 )
{
struct V_51 * V_51 = F_56 ( V_35 ) ;
struct V_84 * V_85 = F_47 ( V_37 ) ;
F_25 ( L_10 , V_50 , V_51 ) ;
if ( V_85 -> V_41 )
return V_85 -> V_41 ( V_51 , V_38 ) ;
return - V_42 ;
}
static T_1 F_57 ( struct V_34 * V_35 , struct V_36 * V_37 ,
const char * V_38 , T_3 V_32 )
{
struct V_51 * V_51 = F_56 ( V_35 ) ;
struct V_84 * V_85 = F_47 ( V_37 ) ;
F_25 ( L_10 , V_50 , V_51 ) ;
if ( V_85 -> V_43 )
return V_85 -> V_43 ( V_51 , V_38 , V_32 ) ;
return - V_42 ;
}
static void F_58 ( struct V_34 * V_35 )
{
struct V_94 * V_95 ;
struct V_51 * V_52 ;
F_25 ( L_4 , V_50 ) ;
V_95 = F_27 ( V_35 , struct V_94 , V_35 ) ;
V_52 = V_95 -> V_52 ;
}
static int F_59 ( struct V_51 * V_52 ,
const struct V_84 * V_96 ,
struct V_34 * V_35 )
{
int V_45 ;
F_60 ( L_4 , V_50 ) ;
while ( V_96 ) {
F_60 ( L_15 , V_50 , V_96 ) ;
if ( V_96 -> V_95 ) {
struct V_94 * V_97 ;
V_97 = F_61 ( sizeof( * V_97 ) , V_98 ) ;
if ( ! V_97 )
return - V_99 ;
V_97 -> V_95 = V_96 -> V_95 ;
V_97 -> V_52 = V_52 ;
F_62 ( & V_97 -> V_100 , & V_52 -> V_101 ) ;
F_50 ( L_16 , V_50 ,
V_96 -> V_95 -> V_102 , V_52 ) ;
V_45 = F_31 ( & V_97 -> V_35 ,
& V_103 ,
& V_52 -> V_54 ,
V_96 -> V_95 -> V_102 ) ;
if ( V_45 < 0 ) {
F_63 ( V_104 L_17 , V_45 ) ;
return V_45 ;
}
V_45 = F_59 ( V_52 ,
V_97 -> V_95 -> V_85 ,
& V_97 -> V_35 ) ;
if ( V_45 < 0 )
return V_45 ;
} else if ( V_96 -> V_37 . V_102 ) {
F_60 ( L_18 , V_50 ,
V_96 -> V_37 . V_102 ) ;
V_45 = F_24 ( V_35 , & V_96 -> V_37 ) ;
if ( V_45 < 0 ) {
F_63 ( V_104 L_19 , V_45 ) ;
return V_45 ;
}
} else
break;
V_96 ++ ;
}
return 0 ;
}
static void F_64 ( struct V_51 * V_52 ,
const struct V_84 * V_96 ,
struct V_34 * V_35 , int V_32 )
{
struct V_94 * V_97 , * V_105 ;
F_25 ( L_4 , V_50 ) ;
while ( V_96 ) {
F_60 ( L_15 , V_50 , V_96 ) ;
if ( V_96 -> V_95 ) {
F_60 ( L_20 ,
V_50 , V_96 -> V_95 -> V_102 ) ;
F_65 (grp_kobj,
&mci->grp_kobj_list, list) {
F_60 ( L_21 , V_50 , V_97 -> V_95 ) ;
if ( V_97 -> V_95 == V_96 -> V_95 ) {
F_64 ( V_52 ,
V_97 -> V_95 -> V_85 ,
& V_97 -> V_35 , V_32 + 1 ) ;
F_60 ( L_22 , V_50 ,
V_96 -> V_95 -> V_102 ) ;
F_28 ( & V_97 -> V_35 ) ;
}
}
F_60 ( L_23 ,
V_50 , V_96 -> V_95 -> V_102 ) ;
} else if ( V_96 -> V_37 . V_102 ) {
F_60 ( L_18 , V_50 ,
V_96 -> V_37 . V_102 ) ;
F_66 ( V_35 , & V_96 -> V_37 ) ;
} else
break;
V_96 ++ ;
}
if ( V_32 )
return;
F_67 (grp_kobj, tmp,
&mci->grp_kobj_list, list) {
F_68 ( & V_97 -> V_100 ) ;
F_69 ( V_97 ) ;
}
}
int F_70 ( struct V_51 * V_52 )
{
int V_18 , V_82 ;
int V_45 ;
struct V_12 * V_13 ;
struct V_34 * V_56 = & V_52 -> V_54 ;
F_50 ( L_24 , V_50 , V_52 -> V_86 ) ;
F_71 ( & V_52 -> V_101 ) ;
V_45 = F_72 ( V_56 , & V_52 -> V_106 -> V_35 ,
V_107 ) ;
if ( V_45 ) {
F_25 ( L_25 , V_50 ) ;
goto V_108;
}
if ( V_52 -> V_109 ) {
V_45 = F_59 ( V_52 ,
V_52 -> V_109 ,
& V_52 -> V_54 ) ;
if ( V_45 ) {
F_25 ( L_26 ,
V_50 ) ;
goto V_108;
}
}
for ( V_18 = 0 ; V_18 < V_52 -> V_66 ; V_18 ++ ) {
int V_19 = 0 ;
V_13 = & V_52 -> V_68 [ V_18 ] ;
for ( V_82 = 0 ; V_82 < V_13 -> V_20 ; V_82 ++ )
V_19 += V_13 -> V_21 [ V_82 ] . V_22 -> V_19 ;
if ( V_19 > 0 ) {
V_45 = F_29 ( V_52 , V_13 , V_18 ) ;
if ( V_45 ) {
F_25 ( L_27 ,
V_50 , V_18 ) ;
goto V_110;
}
}
}
return 0 ;
V_110:
for ( V_18 -- ; V_18 >= 0 ; V_18 -- ) {
int V_19 = 0 ;
V_13 = & V_52 -> V_68 [ V_18 ] ;
for ( V_82 = 0 ; V_82 < V_13 -> V_20 ; V_82 ++ )
V_19 += V_13 -> V_21 [ V_82 ] . V_22 -> V_19 ;
if ( V_19 > 0 )
F_28 ( & V_52 -> V_68 [ V_18 ] . V_35 ) ;
}
F_64 ( V_52 ,
V_52 -> V_109 , & V_52 -> V_54 , 0 ) ;
F_73 ( V_56 , V_107 ) ;
V_108:
return V_45 ;
}
void F_74 ( struct V_51 * V_52 )
{
struct V_12 * V_13 ;
int V_18 , V_82 ;
F_50 ( L_4 , V_50 ) ;
F_60 ( L_28 , V_50 ) ;
for ( V_18 = 0 ; V_18 < V_52 -> V_66 ; V_18 ++ ) {
int V_19 = 0 ;
V_13 = & V_52 -> V_68 [ V_18 ] ;
for ( V_82 = 0 ; V_82 < V_13 -> V_20 ; V_82 ++ )
V_19 += V_13 -> V_21 [ V_82 ] . V_22 -> V_19 ;
if ( V_19 > 0 ) {
F_50 ( L_29 , V_50 , V_18 ) ;
F_28 ( & V_52 -> V_68 [ V_18 ] . V_35 ) ;
}
}
if ( V_52 -> V_109 ) {
F_60 ( L_30 , V_50 ) ;
F_64 ( V_52 ,
V_52 -> V_109 ,
& V_52 -> V_54 , 0 ) ;
}
F_60 ( L_31 , V_50 ) ;
F_73 ( & V_52 -> V_54 , V_107 ) ;
F_60 ( L_32 , V_50 ) ;
F_28 ( & V_52 -> V_54 ) ;
}
int F_75 ( void )
{
int V_45 = - V_10 ;
struct V_111 * V_112 ;
F_25 ( L_4 , V_50 ) ;
V_112 = F_76 () ;
if ( V_112 == NULL ) {
F_25 ( L_33 , V_50 , V_45 ) ;
goto V_89;
}
V_91 = F_77 ( L_34 , NULL , & V_112 -> V_113 -> V_35 ) ;
if ( ! V_91 ) {
V_45 = - V_99 ;
F_25 ( L_35 , V_50 ) ;
goto V_114;
}
F_25 ( L_36 , V_50 ) ;
return 0 ;
V_114:
F_78 () ;
V_89:
return V_45 ;
}
void F_79 ( void )
{
F_80 ( V_91 ) ;
F_78 () ;
}
