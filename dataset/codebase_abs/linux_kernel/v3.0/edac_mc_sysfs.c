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
return sprintf ( V_14 , L_1 , F_11 ( V_13 -> V_18 ) ) ;
}
static T_1 F_12 ( struct V_12 * V_13 , char * V_14 ,
int V_15 )
{
return sprintf ( V_14 , L_2 , V_19 [ V_13 -> V_20 ] ) ;
}
static T_1 F_13 ( struct V_12 * V_13 , char * V_14 ,
int V_15 )
{
return sprintf ( V_14 , L_2 , V_21 [ V_13 -> V_22 ] ) ;
}
static T_1 F_14 ( struct V_12 * V_13 , char * V_14 ,
int V_15 )
{
return sprintf ( V_14 , L_2 , V_23 [ V_13 -> V_24 ] ) ;
}
static T_1 F_15 ( struct V_12 * V_13 ,
char * V_14 , int V_25 )
{
if ( ! V_13 -> V_26 [ V_25 ] . V_27 [ 0 ] )
return 0 ;
return snprintf ( V_14 , V_28 , L_2 ,
V_13 -> V_26 [ V_25 ] . V_27 ) ;
}
static T_1 F_16 ( struct V_12 * V_13 ,
const char * V_14 ,
T_2 V_29 , int V_25 )
{
T_1 V_30 = 0 ;
V_30 = F_17 ( ( T_1 ) V_29 , ( T_1 ) V_28 - 1 ) ;
strncpy ( V_13 -> V_26 [ V_25 ] . V_27 , V_14 , V_30 ) ;
V_13 -> V_26 [ V_25 ] . V_27 [ V_30 ] = '\0' ;
return V_30 ;
}
static T_1 F_18 ( struct V_12 * V_13 ,
char * V_14 , int V_25 )
{
return sprintf ( V_14 , L_1 , V_13 -> V_26 [ V_25 ] . V_17 ) ;
}
static T_1 F_19 ( struct V_31 * V_32 ,
struct V_33 * V_34 , char * V_35 )
{
struct V_12 * V_13 = F_20 ( V_32 ) ;
struct V_36 * V_37 = F_21 ( V_34 ) ;
if ( V_37 -> V_38 )
return V_37 -> V_38 ( V_13 ,
V_35 , V_37 -> V_15 ) ;
return - V_39 ;
}
static T_1 F_22 ( struct V_31 * V_32 , struct V_33 * V_34 ,
const char * V_35 , T_2 V_29 )
{
struct V_12 * V_13 = F_20 ( V_32 ) ;
struct V_36 * V_37 = F_21 ( V_34 ) ;
if ( V_37 -> V_40 )
return V_37 -> V_40 ( V_13 ,
V_35 ,
V_29 , V_37 -> V_15 ) ;
return - V_39 ;
}
static int F_23 ( struct V_31 * V_32 , int V_41 )
{
int V_42 = - V_43 ;
if ( V_41 >= V_44 )
return V_42 ;
V_42 = F_24 ( V_32 ,
(struct V_33 * )
V_45 [ V_41 ] ) ;
if ( ! V_42 ) {
V_42 = F_24 ( V_32 ,
(struct V_33 * )
V_46 [ V_41 ] ) ;
} else {
F_25 ( L_3 ,
V_47 ) ;
}
return V_42 ;
}
static void F_26 ( struct V_31 * V_32 )
{
struct V_48 * V_49 ;
struct V_12 * V_50 ;
F_25 ( L_4 , V_47 ) ;
V_50 = F_27 ( V_32 , struct V_12 , V_32 ) ;
V_49 = V_50 -> V_49 ;
F_28 ( & V_49 -> V_51 ) ;
}
static int F_29 ( struct V_48 * V_49 ,
struct V_12 * V_13 , int V_52 )
{
struct V_31 * V_53 = & V_49 -> V_51 ;
struct V_31 * V_32 ;
int V_41 ;
int V_42 ;
memset ( & V_13 -> V_32 , 0 , sizeof( V_13 -> V_32 ) ) ;
V_13 -> V_49 = V_49 ;
V_32 = F_30 ( & V_49 -> V_51 ) ;
if ( ! V_32 ) {
V_42 = - V_43 ;
goto V_54;
}
V_42 = F_31 ( & V_13 -> V_32 , & V_55 , V_53 ,
L_5 , V_52 ) ;
if ( V_42 )
goto V_56;
for ( V_41 = 0 ; V_41 < V_13 -> V_57 ; V_41 ++ ) {
V_42 = F_23 ( & V_13 -> V_32 , V_41 ) ;
if ( V_42 ) {
F_28 ( & V_13 -> V_32 ) ;
goto V_54;
}
}
F_32 ( & V_13 -> V_32 , V_58 ) ;
return 0 ;
V_56:
F_28 ( & V_49 -> V_51 ) ;
V_54:
return V_42 ;
}
static T_1 F_33 ( struct V_48 * V_49 ,
const char * V_14 , T_2 V_29 )
{
int V_59 , V_41 ;
V_49 -> V_60 = 0 ;
V_49 -> V_61 = 0 ;
V_49 -> V_16 = 0 ;
V_49 -> V_17 = 0 ;
for ( V_59 = 0 ; V_59 < V_49 -> V_62 ; V_59 ++ ) {
struct V_12 * V_63 = & V_49 -> V_64 [ V_59 ] ;
V_63 -> V_16 = 0 ;
V_63 -> V_17 = 0 ;
for ( V_41 = 0 ; V_41 < V_63 -> V_57 ; V_41 ++ )
V_63 -> V_26 [ V_41 ] . V_17 = 0 ;
}
V_49 -> V_65 = V_66 ;
return V_29 ;
}
static T_1 F_34 ( struct V_48 * V_49 ,
const char * V_14 , T_2 V_29 )
{
unsigned long V_67 = 0 ;
int V_68 = 0 ;
if ( ! V_49 -> V_69 )
return - V_10 ;
if ( F_35 ( V_14 , 10 , & V_67 ) < 0 )
return - V_10 ;
V_68 = V_49 -> V_69 ( V_49 , V_67 ) ;
if ( V_68 < 0 ) {
F_36 ( V_70 , V_71 ,
L_6 , V_67 ) ;
return - V_10 ;
}
return V_29 ;
}
static T_1 F_37 ( struct V_48 * V_49 , char * V_14 )
{
int V_67 = 0 ;
if ( ! V_49 -> V_72 )
return - V_10 ;
V_67 = V_49 -> V_72 ( V_49 ) ;
if ( V_67 < 0 ) {
F_36 ( V_73 , V_71 , L_7 ) ;
return V_67 ;
}
return sprintf ( V_14 , L_8 , V_67 ) ;
}
static T_1 F_38 ( struct V_48 * V_49 , char * V_14 )
{
return sprintf ( V_14 , L_8 , V_49 -> V_16 ) ;
}
static T_1 F_39 ( struct V_48 * V_49 , char * V_14 )
{
return sprintf ( V_14 , L_8 , V_49 -> V_17 ) ;
}
static T_1 F_40 ( struct V_48 * V_49 , char * V_14 )
{
return sprintf ( V_14 , L_8 , V_49 -> V_61 ) ;
}
static T_1 F_41 ( struct V_48 * V_49 , char * V_14 )
{
return sprintf ( V_14 , L_8 , V_49 -> V_60 ) ;
}
static T_1 F_42 ( struct V_48 * V_49 , char * V_14 )
{
return sprintf ( V_14 , L_9 , ( V_66 - V_49 -> V_65 ) / V_74 ) ;
}
static T_1 F_43 ( struct V_48 * V_49 , char * V_14 )
{
return sprintf ( V_14 , L_2 , V_49 -> V_75 ) ;
}
static T_1 F_44 ( struct V_48 * V_49 , char * V_14 )
{
int V_76 , V_77 ;
for ( V_76 = V_77 = 0 ; V_77 < V_49 -> V_62 ;
V_77 ++ ) {
struct V_12 * V_13 = & V_49 -> V_64 [ V_77 ] ;
if ( ! V_13 -> V_18 )
continue;
V_76 += V_13 -> V_18 ;
}
return sprintf ( V_14 , L_1 , F_11 ( V_76 ) ) ;
}
static T_1 F_45 ( struct V_31 * V_32 , struct V_33 * V_34 ,
char * V_35 )
{
struct V_48 * V_48 = F_46 ( V_32 ) ;
struct V_78 * V_79 = F_47 ( V_34 ) ;
F_25 ( L_10 , V_47 , V_48 ) ;
if ( V_79 -> V_38 )
return V_79 -> V_38 ( V_48 , V_35 ) ;
return - V_39 ;
}
static T_1 F_48 ( struct V_31 * V_32 , struct V_33 * V_34 ,
const char * V_35 , T_2 V_29 )
{
struct V_48 * V_48 = F_46 ( V_32 ) ;
struct V_78 * V_79 = F_47 ( V_34 ) ;
F_25 ( L_10 , V_47 , V_48 ) ;
if ( V_79 -> V_40 )
return V_79 -> V_40 ( V_48 , V_35 , V_29 ) ;
return - V_39 ;
}
static void F_49 ( struct V_31 * V_32 )
{
struct V_48 * V_49 ;
V_49 = F_46 ( V_32 ) ;
F_50 ( L_11 , V_47 , V_49 -> V_80 ) ;
F_51 ( V_49 -> V_81 ) ;
}
int F_52 ( struct V_48 * V_49 )
{
struct V_31 * V_53 ;
int V_42 ;
F_25 ( L_4 , V_47 ) ;
V_53 = & V_49 -> V_51 ;
memset ( V_53 , 0 , sizeof( * V_53 ) ) ;
V_49 -> V_81 = V_82 ;
if ( ! F_53 ( V_49 -> V_81 ) ) {
V_42 = - V_43 ;
goto V_83;
}
V_53 -> V_84 = V_85 ;
V_42 = F_31 ( V_53 , & V_86 , NULL ,
L_12 , V_49 -> V_80 ) ;
if ( V_42 ) {
F_25 ( L_13 ,
V_47 , V_49 -> V_80 ) ;
goto V_87;
}
F_32 ( V_53 , V_58 ) ;
F_25 ( L_14 ,
V_47 , V_49 -> V_80 ) ;
return 0 ;
V_87:
F_51 ( V_49 -> V_81 ) ;
V_83:
return V_42 ;
}
void F_54 ( struct V_48 * V_49 )
{
F_25 ( L_4 , V_47 ) ;
F_28 ( & V_49 -> V_51 ) ;
}
static T_1 F_55 ( struct V_31 * V_32 , struct V_33 * V_34 ,
char * V_35 )
{
struct V_48 * V_48 = F_56 ( V_32 ) ;
struct V_78 * V_79 = F_47 ( V_34 ) ;
F_25 ( L_10 , V_47 , V_48 ) ;
if ( V_79 -> V_38 )
return V_79 -> V_38 ( V_48 , V_35 ) ;
return - V_39 ;
}
static T_1 F_57 ( struct V_31 * V_32 , struct V_33 * V_34 ,
const char * V_35 , T_2 V_29 )
{
struct V_48 * V_48 = F_56 ( V_32 ) ;
struct V_78 * V_79 = F_47 ( V_34 ) ;
F_25 ( L_10 , V_47 , V_48 ) ;
if ( V_79 -> V_40 )
return V_79 -> V_40 ( V_48 , V_35 , V_29 ) ;
return - V_39 ;
}
static void F_58 ( struct V_31 * V_32 )
{
struct V_88 * V_89 ;
struct V_48 * V_49 ;
F_25 ( L_4 , V_47 ) ;
V_89 = F_27 ( V_32 , struct V_88 , V_32 ) ;
V_49 = V_89 -> V_49 ;
}
static int F_59 ( struct V_48 * V_49 ,
const struct V_78 * V_90 ,
struct V_31 * V_32 )
{
int V_42 ;
F_60 ( L_4 , V_47 ) ;
while ( V_90 ) {
F_60 ( L_15 , V_47 , V_90 ) ;
if ( V_90 -> V_89 ) {
struct V_88 * V_91 ;
V_91 = F_61 ( sizeof( * V_91 ) , V_92 ) ;
if ( ! V_91 )
return - V_93 ;
V_91 -> V_89 = V_90 -> V_89 ;
V_91 -> V_49 = V_49 ;
F_62 ( & V_91 -> V_94 , & V_49 -> V_95 ) ;
F_50 ( L_16 , V_47 ,
V_90 -> V_89 -> V_96 , V_49 ) ;
V_42 = F_31 ( & V_91 -> V_32 ,
& V_97 ,
& V_49 -> V_51 ,
V_90 -> V_89 -> V_96 ) ;
if ( V_42 < 0 ) {
F_63 ( V_98 L_17 , V_42 ) ;
return V_42 ;
}
V_42 = F_59 ( V_49 ,
V_91 -> V_89 -> V_79 ,
& V_91 -> V_32 ) ;
if ( V_42 < 0 )
return V_42 ;
} else if ( V_90 -> V_34 . V_96 ) {
F_60 ( L_18 , V_47 ,
V_90 -> V_34 . V_96 ) ;
V_42 = F_24 ( V_32 , & V_90 -> V_34 ) ;
if ( V_42 < 0 ) {
F_63 ( V_98 L_19 , V_42 ) ;
return V_42 ;
}
} else
break;
V_90 ++ ;
}
return 0 ;
}
static void F_64 ( struct V_48 * V_49 ,
const struct V_78 * V_90 ,
struct V_31 * V_32 , int V_29 )
{
struct V_88 * V_91 , * V_99 ;
F_25 ( L_4 , V_47 ) ;
while ( V_90 ) {
F_60 ( L_15 , V_47 , V_90 ) ;
if ( V_90 -> V_89 ) {
F_60 ( L_20 ,
V_47 , V_90 -> V_89 -> V_96 ) ;
F_65 (grp_kobj,
&mci->grp_kobj_list, list) {
F_60 ( L_21 , V_47 , V_91 -> V_89 ) ;
if ( V_91 -> V_89 == V_90 -> V_89 ) {
F_64 ( V_49 ,
V_91 -> V_89 -> V_79 ,
& V_91 -> V_32 , V_29 + 1 ) ;
F_60 ( L_22 , V_47 ,
V_90 -> V_89 -> V_96 ) ;
F_28 ( & V_91 -> V_32 ) ;
}
}
F_60 ( L_23 ,
V_47 , V_90 -> V_89 -> V_96 ) ;
} else if ( V_90 -> V_34 . V_96 ) {
F_60 ( L_18 , V_47 ,
V_90 -> V_34 . V_96 ) ;
F_66 ( V_32 , & V_90 -> V_34 ) ;
} else
break;
V_90 ++ ;
}
if ( V_29 )
return;
F_67 (grp_kobj, tmp,
&mci->grp_kobj_list, list) {
F_68 ( & V_91 -> V_94 ) ;
F_69 ( V_91 ) ;
}
}
int F_70 ( struct V_48 * V_49 )
{
int V_100 ;
int V_42 ;
struct V_12 * V_13 ;
struct V_31 * V_53 = & V_49 -> V_51 ;
F_50 ( L_24 , V_47 , V_49 -> V_80 ) ;
F_71 ( & V_49 -> V_95 ) ;
V_42 = F_72 ( V_53 , & V_49 -> V_101 -> V_32 ,
V_102 ) ;
if ( V_42 ) {
F_25 ( L_25 , V_47 ) ;
goto V_103;
}
if ( V_49 -> V_104 ) {
V_42 = F_59 ( V_49 ,
V_49 -> V_104 ,
& V_49 -> V_51 ) ;
if ( V_42 ) {
F_25 ( L_26 ,
V_47 ) ;
goto V_103;
}
}
for ( V_100 = 0 ; V_100 < V_49 -> V_62 ; V_100 ++ ) {
V_13 = & V_49 -> V_64 [ V_100 ] ;
if ( V_13 -> V_18 > 0 ) {
V_42 = F_29 ( V_49 , V_13 , V_100 ) ;
if ( V_42 ) {
F_25 ( L_27 ,
V_47 , V_100 ) ;
goto V_105;
}
}
}
return 0 ;
V_105:
for ( V_100 -- ; V_100 >= 0 ; V_100 -- ) {
if ( V_13 -> V_18 > 0 ) {
F_28 ( & V_49 -> V_64 [ V_100 ] . V_32 ) ;
}
}
F_64 ( V_49 ,
V_49 -> V_104 , & V_49 -> V_51 , 0 ) ;
F_73 ( V_53 , V_102 ) ;
V_103:
return V_42 ;
}
void F_74 ( struct V_48 * V_49 )
{
int V_100 ;
F_50 ( L_4 , V_47 ) ;
F_60 ( L_28 , V_47 ) ;
for ( V_100 = 0 ; V_100 < V_49 -> V_62 ; V_100 ++ ) {
if ( V_49 -> V_64 [ V_100 ] . V_18 > 0 ) {
F_50 ( L_29 , V_47 , V_100 ) ;
F_28 ( & V_49 -> V_64 [ V_100 ] . V_32 ) ;
}
}
if ( V_49 -> V_104 ) {
F_60 ( L_30 , V_47 ) ;
F_64 ( V_49 ,
V_49 -> V_104 ,
& V_49 -> V_51 , 0 ) ;
}
F_60 ( L_31 , V_47 ) ;
F_73 ( & V_49 -> V_51 , V_102 ) ;
F_60 ( L_32 , V_47 ) ;
F_28 ( & V_49 -> V_51 ) ;
}
int F_75 ( void )
{
int V_42 = - V_10 ;
struct V_106 * V_107 ;
F_25 ( L_4 , V_47 ) ;
V_107 = F_76 () ;
if ( V_107 == NULL ) {
F_25 ( L_33 , V_47 , V_42 ) ;
goto V_83;
}
V_85 = F_77 ( L_34 , NULL , & V_107 -> V_84 . V_32 ) ;
if ( ! V_85 ) {
V_42 = - V_93 ;
F_25 ( L_35 , V_47 ) ;
goto V_108;
}
F_25 ( L_36 , V_47 ) ;
return 0 ;
V_108:
F_78 () ;
V_83:
return V_42 ;
}
void F_79 ( void )
{
F_80 ( V_85 ) ;
F_78 () ;
}
