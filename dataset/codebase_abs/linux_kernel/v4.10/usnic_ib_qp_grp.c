const char * F_1 ( enum V_1 V_2 )
{
switch ( V_2 ) {
case V_3 :
return L_1 ;
case V_4 :
return L_2 ;
case V_5 :
return L_3 ;
case V_6 :
return L_4 ;
case V_7 :
return L_5 ;
case V_8 :
return L_6 ;
case V_9 :
return L_7 ;
default:
return L_8 ;
}
}
int F_2 ( char * V_10 , int V_11 )
{
return F_3 ( V_10 , V_11 , L_9 ) ;
}
int F_4 ( void * V_12 , char * V_10 , int V_11 )
{
struct V_13 * V_14 = V_12 ;
struct V_15 * V_16 ;
if ( V_12 ) {
V_16 = F_5 ( & V_14 -> V_17 ,
struct V_15 , V_18 ) ;
return F_3 ( V_10 , V_11 , L_10 ,
V_14 -> V_19 . V_20 ,
F_1 (
V_14 -> V_2 ) ,
V_14 -> V_21 ,
F_6 ( V_14 -> V_22 -> V_23 ) ,
V_16 -> V_24 -> V_25 ) ;
} else {
return F_3 ( V_10 , V_11 , L_11 ) ;
}
}
static struct V_26 *
F_7 ( struct V_13 * V_14 )
{
F_8 ( & V_14 -> V_27 ) ;
return F_9 ( V_14 , V_28 ) ;
}
static int F_10 ( struct V_13 * V_14 )
{
int V_29 ;
int V_30 , V_31 ;
struct V_26 * V_32 ;
struct V_33 * V_34 ;
F_8 ( & V_14 -> V_27 ) ;
V_31 = F_6 ( V_14 -> V_22 -> V_23 ) ;
V_32 = F_7 ( V_14 ) ;
if ( F_11 ( V_32 ) ) {
F_12 ( L_12 ,
F_13 ( V_32 ) ) ;
return F_13 ( V_32 ) ;
}
for ( V_30 = 0 ; V_30 < V_32 -> V_35 ; V_30 ++ ) {
V_34 = V_32 -> V_34 [ V_30 ] ;
V_29 = F_14 ( V_14 -> V_36 , V_31 ,
V_34 -> V_31 ) ;
if ( V_29 ) {
F_12 ( L_13 ,
V_34 -> V_31 , V_14 -> V_36 -> V_37 ,
V_31 , V_29 ) ;
goto V_38;
}
}
return 0 ;
V_38:
for ( V_30 -- ; V_30 >= 0 ; V_30 -- ) {
V_34 = V_32 -> V_34 [ V_30 ] ;
F_15 ( V_14 -> V_36 , V_31 ,
V_34 -> V_31 ) ;
}
return V_29 ;
}
static int F_16 ( struct V_13 * V_14 )
{
int V_30 , V_31 ;
struct V_26 * V_32 ;
struct V_33 * V_34 ;
int V_29 = 0 ;
F_8 ( & V_14 -> V_27 ) ;
V_31 = F_6 ( V_14 -> V_22 -> V_23 ) ;
V_32 = F_7 ( V_14 ) ;
if ( F_11 ( V_32 ) ) {
F_12 ( L_12 ,
F_13 ( V_32 ) ) ;
return F_13 ( V_32 ) ;
}
for ( V_30 = 0 ; V_30 < V_32 -> V_35 ; V_30 ++ ) {
V_34 = V_32 -> V_34 [ V_30 ] ;
V_29 = F_15 ( V_14 -> V_36 , V_31 ,
V_34 -> V_31 ) ;
if ( V_29 ) {
F_12 ( L_14 ,
V_34 -> V_31 ,
V_14 -> V_36 -> V_37 ,
V_31 , V_29 ) ;
}
}
return V_29 ;
}
static int F_17 ( struct V_13 * V_14 ,
struct V_39 * V_40 )
{
struct V_26 * V_32 ;
V_32 = F_9 ( V_14 , V_28 ) ;
if ( F_11 ( V_32 ) ) {
F_12 ( L_15 ,
F_18 ( V_28 ) ,
F_13 ( V_32 ) ) ;
return F_13 ( V_32 ) ;
}
V_40 -> V_31 = F_6 ( V_14 -> V_22 -> V_23 ) ;
V_40 -> V_41 . type = V_42 ;
V_40 -> V_41 . V_43 . V_44 = V_32 -> V_34 [ V_45 ] -> V_31 ;
return 0 ;
}
static struct V_15 *
F_19 ( struct V_13 * V_14 ,
struct V_46 * V_47 )
{
T_1 V_48 ;
int V_49 ;
struct V_50 V_50 ;
struct V_39 V_40 ;
struct V_15 * V_51 ;
struct V_52 * V_24 ;
enum V_53 V_54 ;
V_54 = V_47 -> V_54 ;
V_48 = V_47 -> V_55 . V_48 ;
V_48 = F_20 ( V_54 , V_48 ) ;
if ( V_48 == 0 )
return F_21 ( - V_56 ) ;
F_22 ( & V_50 , V_48 ) ;
V_49 = F_17 ( V_14 , & V_40 ) ;
if ( V_49 )
goto V_57;
V_24 = F_23 ( V_14 -> V_36 , & V_50 , & V_40 ) ;
if ( F_24 ( V_24 ) ) {
V_49 = V_24 ? F_13 ( V_24 ) : - V_58 ;
goto V_57;
}
V_51 = F_25 ( sizeof( * V_51 ) , V_59 ) ;
if ( ! V_51 ) {
V_49 = - V_60 ;
goto V_61;
}
V_51 -> V_24 = V_24 ;
V_51 -> V_54 = V_54 ;
V_51 -> V_55 . V_48 = V_48 ;
V_51 -> V_14 = V_14 ;
return V_51 ;
V_61:
F_26 ( V_24 ) ;
V_57:
F_27 ( V_54 , V_48 ) ;
return F_21 ( V_49 ) ;
}
static void F_28 ( struct V_15 * V_51 )
{
F_26 ( V_51 -> V_24 ) ;
F_27 ( V_51 -> V_54 ,
V_51 -> V_55 . V_48 ) ;
F_29 ( V_51 ) ;
}
static struct V_15 *
F_30 ( struct V_13 * V_14 ,
struct V_46 * V_47 )
{
struct V_62 * V_63 ;
int V_64 ;
int V_49 ;
struct V_50 V_50 ;
struct V_39 V_40 ;
struct V_15 * V_51 ;
struct V_52 * V_24 ;
enum V_53 V_54 ;
T_2 V_65 ;
T_1 V_48 ;
int V_66 ;
V_54 = V_47 -> V_54 ;
V_64 = V_47 -> V_67 . V_64 ;
V_63 = F_31 ( V_64 ) ;
if ( F_24 ( V_63 ) )
return F_32 ( V_63 ) ;
V_49 = F_33 ( V_63 , & V_66 , & V_65 , & V_48 ) ;
if ( V_49 )
goto V_68;
if ( V_66 != V_69 ) {
F_12 ( L_16 , V_64 ) ;
V_49 = - V_70 ;
goto V_68;
}
F_34 ( & V_50 , V_65 , V_48 ) ;
V_49 = F_17 ( V_14 , & V_40 ) ;
if ( V_49 )
goto V_68;
V_24 = F_23 ( V_14 -> V_36 , & V_50 , & V_40 ) ;
if ( F_24 ( V_24 ) ) {
V_49 = V_24 ? F_13 ( V_24 ) : - V_58 ;
goto V_68;
}
V_51 = F_25 ( sizeof( * V_51 ) , V_59 ) ;
if ( ! V_51 ) {
V_49 = - V_60 ;
goto V_61;
}
V_51 -> V_24 = V_24 ;
V_51 -> V_54 = V_54 ;
V_51 -> V_67 . V_63 = V_63 ;
V_51 -> V_14 = V_14 ;
return V_51 ;
V_61:
F_26 ( V_24 ) ;
V_68:
F_35 ( V_63 ) ;
return F_21 ( V_49 ) ;
}
static void F_36 ( struct V_15 * V_51 )
{
F_26 ( V_51 -> V_24 ) ;
F_35 ( V_51 -> V_67 . V_63 ) ;
F_29 ( V_51 ) ;
}
static struct V_15 *
F_37 ( struct V_13 * V_14 ,
struct V_46 * V_47 )
{
struct V_15 * V_51 ;
enum V_53 V_54 ;
V_54 = V_47 -> V_54 ;
switch ( V_54 ) {
case V_71 :
V_51 = F_19 ( V_14 , V_47 ) ;
break;
case V_72 :
V_51 = F_30 ( V_14 , V_47 ) ;
break;
default:
F_12 ( L_17 ,
V_47 -> V_54 ) ;
return F_21 ( - V_56 ) ;
}
if ( ! F_24 ( V_51 ) ) {
F_38 ( & V_51 -> V_18 , & V_14 -> V_17 ) ;
F_39 ( V_51 ) ;
}
return V_51 ;
}
static void F_40 ( struct V_15 * V_51 )
{
F_41 ( V_51 ) ;
F_42 ( & V_51 -> V_18 ) ;
switch ( V_51 -> V_54 ) {
case V_71 :
F_28 ( V_51 ) ;
break;
case V_72 :
F_36 ( V_51 ) ;
break;
default:
F_43 ( 1 , L_17 ,
V_51 -> V_54 ) ;
break;
}
}
static void F_44 ( struct V_13 * V_14 )
{
struct V_15 * V_51 , * V_73 ;
F_45 (qp_flow, tmp, &qp_grp->flows_lst, link)
F_40 ( V_51 ) ;
}
int F_46 ( struct V_13 * V_14 ,
enum V_1 V_74 ,
void * V_75 )
{
int V_29 = 0 ;
int V_31 ;
struct V_76 V_76 ;
enum V_1 V_77 ;
struct V_46 * V_47 ;
struct V_15 * V_51 ;
V_77 = V_14 -> V_2 ;
V_31 = F_6 ( V_14 -> V_22 -> V_23 ) ;
V_47 = (struct V_46 * ) V_75 ;
F_47 ( & V_14 -> V_27 ) ;
switch ( V_74 ) {
case V_3 :
switch ( V_77 ) {
case V_3 :
break;
case V_4 :
F_44 ( V_14 ) ;
V_29 = 0 ;
break;
case V_5 :
case V_6 :
case V_9 :
V_29 = F_16 ( V_14 ) ;
F_44 ( V_14 ) ;
break;
default:
V_29 = - V_56 ;
}
break;
case V_4 :
switch ( V_77 ) {
case V_3 :
if ( V_47 ) {
V_51 = F_37 ( V_14 ,
V_47 ) ;
if ( F_24 ( V_51 ) ) {
V_29 = V_51 ? F_13 ( V_51 ) : - V_58 ;
break;
}
} else {
V_29 = 0 ;
}
break;
case V_4 :
if ( V_47 ) {
V_51 = F_37 ( V_14 ,
V_47 ) ;
if ( F_24 ( V_51 ) ) {
V_29 = V_51 ? F_13 ( V_51 ) : - V_58 ;
break;
}
} else {
V_29 = - V_56 ;
}
break;
case V_5 :
V_29 = F_16 ( V_14 ) ;
break;
case V_6 :
V_29 = F_16 ( V_14 ) ;
break;
default:
V_29 = - V_56 ;
}
break;
case V_5 :
switch ( V_77 ) {
case V_4 :
V_29 = F_10 ( V_14 ) ;
break;
default:
V_29 = - V_56 ;
}
break;
case V_6 :
switch ( V_77 ) {
case V_5 :
break;
default:
V_29 = - V_56 ;
}
break;
case V_9 :
V_76 . V_78 = & V_14 -> V_22 -> V_79 -> V_80 ;
V_76 . V_81 . V_82 = & V_14 -> V_19 ;
V_76 . V_83 = V_84 ;
switch ( V_77 ) {
case V_3 :
V_14 -> V_19 . V_85 ( & V_76 ,
V_14 -> V_19 . V_86 ) ;
break;
case V_4 :
F_44 ( V_14 ) ;
V_14 -> V_19 . V_85 ( & V_76 ,
V_14 -> V_19 . V_86 ) ;
break;
case V_5 :
case V_6 :
V_29 = F_16 ( V_14 ) ;
F_44 ( V_14 ) ;
V_14 -> V_19 . V_85 ( & V_76 ,
V_14 -> V_19 . V_86 ) ;
break;
default:
V_29 = - V_56 ;
}
break;
default:
V_29 = - V_56 ;
}
F_48 ( & V_14 -> V_27 ) ;
if ( ! V_29 ) {
V_14 -> V_2 = V_74 ;
F_49 ( L_18 ,
V_14 -> V_87 ,
F_1 ( V_77 ) ,
F_1 ( V_74 ) ) ;
} else {
F_12 ( L_19 ,
V_14 -> V_87 ,
F_1 ( V_77 ) ,
F_1 ( V_74 ) ) ;
}
return V_29 ;
}
static struct V_26 * *
F_50 ( struct V_88 * V_23 ,
struct V_89 * V_90 , void * V_91 )
{
enum V_92 V_93 ;
struct V_26 * * V_94 ;
int V_49 , V_30 , V_95 , V_96 ;
for ( V_96 = 0 ;
V_90 -> V_97 [ V_96 ] . type != V_98 ;
V_96 ++ ) {
}
V_94 = F_25 ( sizeof( * V_94 ) * ( V_96 + 1 ) ,
V_59 ) ;
if ( ! V_94 )
return F_21 ( - V_60 ) ;
for ( V_30 = 0 ; V_90 -> V_97 [ V_30 ] . type != V_98 ;
V_30 ++ ) {
V_93 = V_90 -> V_97 [ V_30 ] . type ;
V_95 = V_90 -> V_97 [ V_30 ] . V_35 ;
V_94 [ V_30 ] = F_51 ( V_23 , V_93 ,
V_95 , V_91 ) ;
if ( F_24 ( V_94 [ V_30 ] ) ) {
V_49 = V_94 [ V_30 ] ?
F_13 ( V_94 [ V_30 ] ) : - V_60 ;
F_12 ( L_20 ,
F_18 ( V_93 ) ,
F_52 ( V_23 ) ,
V_49 ) ;
goto V_99;
}
}
return V_94 ;
V_99:
for ( V_30 -- ; V_30 >= 0 ; V_30 -- )
F_53 ( V_94 [ V_30 ] ) ;
F_29 ( V_94 ) ;
return F_21 ( V_49 ) ;
}
static void F_54 ( struct V_26 * * V_94 )
{
int V_30 ;
for ( V_30 = 0 ; V_94 [ V_30 ] ; V_30 ++ )
F_53 ( V_94 [ V_30 ] ) ;
F_29 ( V_94 ) ;
}
static int F_55 ( struct V_100 * V_22 ,
struct V_101 * V_102 ,
struct V_13 * V_14 )
{
int V_49 ;
struct V_103 * V_104 ;
F_8 ( & V_22 -> V_27 ) ;
V_104 = F_56 ( V_22 -> V_23 ) ;
if ( V_22 -> V_105 == 0 ) {
V_49 = F_57 ( V_102 -> V_106 , & V_104 -> V_107 ) ;
if ( V_49 ) {
F_12 ( L_21 ,
F_58 ( V_104 ) ) ;
return V_49 ;
}
V_22 -> V_102 = V_102 ;
}
V_22 -> V_105 ++ ;
F_59 ( V_22 -> V_102 != V_102 ) ;
V_14 -> V_22 = V_22 ;
return 0 ;
}
static void F_60 ( struct V_13 * V_14 )
{
struct V_103 * V_104 ;
struct V_101 * V_102 ;
F_8 ( & V_14 -> V_22 -> V_27 ) ;
V_102 = V_14 -> V_22 -> V_102 ;
V_104 = F_56 ( V_14 -> V_22 -> V_23 ) ;
if ( -- V_14 -> V_22 -> V_105 == 0 ) {
V_14 -> V_22 -> V_102 = NULL ;
F_61 ( V_102 -> V_106 , & V_104 -> V_107 ) ;
}
V_14 -> V_22 = NULL ;
}
static void F_62 ( struct V_89 * V_90 )
{
char V_10 [ 512 ] ;
F_63 ( V_10 , sizeof( V_10 ) , V_90 ) ;
F_64 ( L_22 , V_10 ) ;
}
static int F_65 ( struct V_15 * V_51 ,
T_2 * V_108 )
{
enum V_53 V_54 = V_51 -> V_54 ;
int V_49 ;
T_1 V_48 = 0 ;
switch ( V_54 ) {
case V_71 :
* V_108 = V_51 -> V_55 . V_48 ;
break;
case V_72 :
V_49 = F_33 ( V_51 -> V_67 . V_63 ,
NULL , NULL ,
& V_48 ) ;
if ( V_49 )
return V_49 ;
* V_108 = V_48 ;
break;
default:
F_12 ( L_17 , V_54 ) ;
return - V_56 ;
}
return 0 ;
}
struct V_13 *
F_66 ( struct V_109 * V_36 , struct V_100 * V_22 ,
struct V_101 * V_102 ,
struct V_89 * V_90 ,
struct V_46 * V_110 )
{
struct V_13 * V_14 ;
int V_49 ;
enum V_53 V_111 = V_110 -> V_54 ;
struct V_15 * V_51 ;
F_8 ( & V_22 -> V_27 ) ;
V_49 = F_67 ( & V_112 [ V_111 ] ,
V_90 ) ;
if ( V_49 ) {
F_12 ( L_23 ,
V_111 ) ;
F_62 ( V_90 ) ;
return F_21 ( V_49 ) ;
}
V_14 = F_25 ( sizeof( * V_14 ) , V_59 ) ;
if ( ! V_14 )
return NULL ;
V_14 -> V_94 = F_50 ( V_22 -> V_23 , V_90 ,
V_14 ) ;
if ( F_24 ( V_14 -> V_94 ) ) {
V_49 = V_14 -> V_94 ?
F_13 ( V_14 -> V_94 ) : - V_60 ;
goto V_113;
}
V_49 = F_55 ( V_22 , V_102 , V_14 ) ;
if ( V_49 )
goto V_99;
F_68 ( & V_14 -> V_17 ) ;
F_69 ( & V_14 -> V_27 ) ;
V_14 -> V_36 = V_36 ;
V_14 -> V_2 = V_3 ;
V_14 -> V_21 = V_114 -> V_115 ;
V_51 = F_37 ( V_14 , V_110 ) ;
if ( F_24 ( V_51 ) ) {
F_12 ( L_24 ,
F_13 ( V_51 ) ) ;
V_49 = V_51 ? F_13 ( V_51 ) : - V_58 ;
goto V_116;
}
V_49 = F_65 ( V_51 , & V_14 -> V_87 ) ;
if ( V_49 )
goto V_117;
V_14 -> V_19 . V_20 = V_14 -> V_87 ;
F_70 ( V_14 ) ;
return V_14 ;
V_117:
F_40 ( V_51 ) ;
V_116:
F_60 ( V_14 ) ;
V_99:
F_54 ( V_14 -> V_94 ) ;
V_113:
F_29 ( V_14 ) ;
return F_21 ( V_49 ) ;
}
void F_71 ( struct V_13 * V_14 )
{
F_59 ( V_14 -> V_2 != V_3 ) ;
F_8 ( & V_14 -> V_22 -> V_27 ) ;
F_44 ( V_14 ) ;
F_72 ( V_14 ) ;
F_60 ( V_14 ) ;
F_54 ( V_14 -> V_94 ) ;
F_29 ( V_14 ) ;
}
struct V_26 *
F_9 ( struct V_13 * V_14 ,
enum V_92 V_93 )
{
int V_30 ;
for ( V_30 = 0 ; V_14 -> V_94 [ V_30 ] ; V_30 ++ ) {
if ( V_14 -> V_94 [ V_30 ] -> type == V_93 )
return V_14 -> V_94 [ V_30 ] ;
}
return F_21 ( - V_56 ) ;
}
