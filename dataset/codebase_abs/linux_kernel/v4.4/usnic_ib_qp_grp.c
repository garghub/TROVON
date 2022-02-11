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
return V_32 ? F_13 ( V_32 ) : - V_35 ;
}
for ( V_30 = 0 ; V_30 < V_32 -> V_36 ; V_30 ++ ) {
V_34 = V_32 -> V_34 [ V_30 ] ;
V_29 = F_14 ( V_14 -> V_37 , V_31 ,
V_34 -> V_31 ) ;
if ( V_29 ) {
F_12 ( L_13 ,
V_34 -> V_31 , V_14 -> V_37 -> V_38 ,
V_31 , V_29 ) ;
goto V_39;
}
}
return 0 ;
V_39:
for ( V_30 -- ; V_30 >= 0 ; V_30 -- ) {
V_34 = V_32 -> V_34 [ V_30 ] ;
F_15 ( V_14 -> V_37 , V_31 ,
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
return V_32 ? F_13 ( V_32 ) : - V_35 ;
}
for ( V_30 = 0 ; V_30 < V_32 -> V_36 ; V_30 ++ ) {
V_34 = V_32 -> V_34 [ V_30 ] ;
V_29 = F_15 ( V_14 -> V_37 , V_31 ,
V_34 -> V_31 ) ;
if ( V_29 ) {
F_12 ( L_14 ,
V_34 -> V_31 ,
V_14 -> V_37 -> V_38 ,
V_31 , V_29 ) ;
}
}
return V_29 ;
}
static int F_17 ( struct V_13 * V_14 ,
struct V_40 * V_41 )
{
struct V_26 * V_32 ;
V_32 = F_9 ( V_14 , V_28 ) ;
if ( F_11 ( V_32 ) ) {
F_12 ( L_15 ,
F_18 ( V_28 ) ,
F_13 ( V_32 ) ) ;
return V_32 ? F_13 ( V_32 ) : - V_35 ;
}
V_41 -> V_31 = F_6 ( V_14 -> V_22 -> V_23 ) ;
V_41 -> V_42 . type = V_43 ;
V_41 -> V_42 . V_44 . V_45 = V_32 -> V_34 [ V_46 ] -> V_31 ;
return 0 ;
}
static struct V_15 *
F_19 ( struct V_13 * V_14 ,
struct V_47 * V_48 )
{
T_1 V_49 ;
int V_50 ;
struct V_51 V_51 ;
struct V_40 V_41 ;
struct V_15 * V_52 ;
struct V_53 * V_24 ;
enum V_54 V_55 ;
V_55 = V_48 -> V_55 ;
V_49 = V_48 -> V_56 . V_49 ;
V_49 = F_20 ( V_55 , V_49 ) ;
if ( V_49 == 0 )
return F_21 ( - V_57 ) ;
F_22 ( & V_51 , V_49 ) ;
V_50 = F_17 ( V_14 , & V_41 ) ;
if ( V_50 )
goto V_58;
V_24 = F_23 ( V_14 -> V_37 , & V_51 , & V_41 ) ;
if ( F_11 ( V_24 ) ) {
F_12 ( L_16 ,
F_13 ( V_24 ) ) ;
V_50 = V_24 ? F_13 ( V_24 ) : - V_59 ;
goto V_58;
}
V_52 = F_24 ( sizeof( * V_52 ) , V_60 ) ;
if ( ! V_52 ) {
V_50 = - V_35 ;
goto V_61;
}
V_52 -> V_24 = V_24 ;
V_52 -> V_55 = V_55 ;
V_52 -> V_56 . V_49 = V_49 ;
V_52 -> V_14 = V_14 ;
return V_52 ;
V_61:
F_25 ( V_24 ) ;
V_58:
F_26 ( V_55 , V_49 ) ;
return F_21 ( V_50 ) ;
}
static void F_27 ( struct V_15 * V_52 )
{
F_25 ( V_52 -> V_24 ) ;
F_26 ( V_52 -> V_55 ,
V_52 -> V_56 . V_49 ) ;
F_28 ( V_52 ) ;
}
static struct V_15 *
F_29 ( struct V_13 * V_14 ,
struct V_47 * V_48 )
{
struct V_62 * V_63 ;
int V_64 ;
int V_50 ;
struct V_51 V_51 ;
struct V_40 V_41 ;
struct V_15 * V_52 ;
struct V_53 * V_24 ;
enum V_54 V_55 ;
T_2 V_65 ;
T_1 V_49 ;
int V_66 ;
V_55 = V_48 -> V_55 ;
V_64 = V_48 -> V_67 . V_64 ;
V_63 = F_30 ( V_64 ) ;
if ( F_11 ( V_63 ) )
return F_31 ( V_63 ) ;
V_50 = F_32 ( V_63 , & V_66 , & V_65 , & V_49 ) ;
if ( V_50 )
goto V_68;
if ( V_66 != V_69 ) {
F_12 ( L_17 , V_64 ) ;
V_50 = - V_70 ;
goto V_68;
}
F_33 ( & V_51 , V_65 , V_49 ) ;
V_50 = F_17 ( V_14 , & V_41 ) ;
if ( V_50 )
goto V_68;
V_24 = F_23 ( V_14 -> V_37 , & V_51 , & V_41 ) ;
if ( F_11 ( V_24 ) ) {
F_12 ( L_16 ,
F_13 ( V_24 ) ) ;
V_50 = V_24 ? F_13 ( V_24 ) : - V_59 ;
goto V_68;
}
V_52 = F_24 ( sizeof( * V_52 ) , V_60 ) ;
if ( ! V_52 ) {
V_50 = - V_35 ;
goto V_61;
}
V_52 -> V_24 = V_24 ;
V_52 -> V_55 = V_55 ;
V_52 -> V_67 . V_63 = V_63 ;
V_52 -> V_14 = V_14 ;
return V_52 ;
V_61:
F_25 ( V_24 ) ;
V_68:
F_34 ( V_63 ) ;
return F_21 ( V_50 ) ;
}
static void F_35 ( struct V_15 * V_52 )
{
F_25 ( V_52 -> V_24 ) ;
F_34 ( V_52 -> V_67 . V_63 ) ;
F_28 ( V_52 ) ;
}
static struct V_15 *
F_36 ( struct V_13 * V_14 ,
struct V_47 * V_48 )
{
struct V_15 * V_52 ;
enum V_54 V_55 ;
V_55 = V_48 -> V_55 ;
switch ( V_55 ) {
case V_71 :
V_52 = F_19 ( V_14 , V_48 ) ;
break;
case V_72 :
V_52 = F_29 ( V_14 , V_48 ) ;
break;
default:
F_12 ( L_18 ,
V_48 -> V_55 ) ;
return F_21 ( - V_57 ) ;
}
if ( ! F_11 ( V_52 ) ) {
F_37 ( & V_52 -> V_18 , & V_14 -> V_17 ) ;
F_38 ( V_52 ) ;
}
return V_52 ;
}
static void F_39 ( struct V_15 * V_52 )
{
F_40 ( V_52 ) ;
F_41 ( & V_52 -> V_18 ) ;
switch ( V_52 -> V_55 ) {
case V_71 :
F_27 ( V_52 ) ;
break;
case V_72 :
F_35 ( V_52 ) ;
break;
default:
F_42 ( 1 , L_18 ,
V_52 -> V_55 ) ;
break;
}
}
static void F_43 ( struct V_13 * V_14 )
{
struct V_15 * V_52 , * V_73 ;
F_44 (qp_flow, tmp, &qp_grp->flows_lst, link)
F_39 ( V_52 ) ;
}
int F_45 ( struct V_13 * V_14 ,
enum V_1 V_74 ,
void * V_75 )
{
int V_29 = 0 ;
int V_31 ;
struct V_76 V_76 ;
enum V_1 V_77 ;
struct V_47 * V_48 ;
struct V_15 * V_52 ;
V_77 = V_14 -> V_2 ;
V_31 = F_6 ( V_14 -> V_22 -> V_23 ) ;
V_48 = (struct V_47 * ) V_75 ;
F_46 ( & V_14 -> V_27 ) ;
switch ( V_74 ) {
case V_3 :
switch ( V_77 ) {
case V_3 :
break;
case V_4 :
F_43 ( V_14 ) ;
V_29 = 0 ;
break;
case V_5 :
case V_6 :
case V_9 :
V_29 = F_16 ( V_14 ) ;
F_43 ( V_14 ) ;
break;
default:
V_29 = - V_57 ;
}
break;
case V_4 :
switch ( V_77 ) {
case V_3 :
if ( V_48 ) {
V_52 = F_36 ( V_14 ,
V_48 ) ;
if ( F_11 ( V_52 ) ) {
V_29 = V_52 ? F_13 ( V_52 ) : - V_59 ;
break;
}
} else {
V_29 = 0 ;
}
break;
case V_4 :
if ( V_48 ) {
V_52 = F_36 ( V_14 ,
V_48 ) ;
if ( F_11 ( V_52 ) ) {
V_29 = V_52 ? F_13 ( V_52 ) : - V_59 ;
break;
}
} else {
V_29 = - V_57 ;
}
break;
case V_5 :
V_29 = F_16 ( V_14 ) ;
break;
case V_6 :
V_29 = F_16 ( V_14 ) ;
break;
default:
V_29 = - V_57 ;
}
break;
case V_5 :
switch ( V_77 ) {
case V_4 :
V_29 = F_10 ( V_14 ) ;
break;
default:
V_29 = - V_57 ;
}
break;
case V_6 :
switch ( V_77 ) {
case V_5 :
break;
default:
V_29 = - V_57 ;
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
F_43 ( V_14 ) ;
V_14 -> V_19 . V_85 ( & V_76 ,
V_14 -> V_19 . V_86 ) ;
break;
case V_5 :
case V_6 :
V_29 = F_16 ( V_14 ) ;
F_43 ( V_14 ) ;
V_14 -> V_19 . V_85 ( & V_76 ,
V_14 -> V_19 . V_86 ) ;
break;
default:
V_29 = - V_57 ;
}
break;
default:
V_29 = - V_57 ;
}
F_47 ( & V_14 -> V_27 ) ;
if ( ! V_29 ) {
V_14 -> V_2 = V_74 ;
F_48 ( L_19 ,
V_14 -> V_87 ,
F_1 ( V_77 ) ,
F_1 ( V_74 ) ) ;
} else {
F_12 ( L_20 ,
V_14 -> V_87 ,
F_1 ( V_77 ) ,
F_1 ( V_74 ) ) ;
}
return V_29 ;
}
static struct V_26 * *
F_49 ( struct V_88 * V_23 ,
struct V_89 * V_90 , void * V_91 )
{
enum V_92 V_93 ;
struct V_26 * * V_94 ;
int V_50 , V_30 , V_95 , V_96 ;
for ( V_96 = 0 ;
V_90 -> V_97 [ V_96 ] . type != V_98 ;
V_96 ++ ) {
}
V_94 = F_24 ( sizeof( * V_94 ) * ( V_96 + 1 ) ,
V_60 ) ;
if ( ! V_94 )
return F_21 ( - V_35 ) ;
for ( V_30 = 0 ; V_90 -> V_97 [ V_30 ] . type != V_98 ;
V_30 ++ ) {
V_93 = V_90 -> V_97 [ V_30 ] . type ;
V_95 = V_90 -> V_97 [ V_30 ] . V_36 ;
V_94 [ V_30 ] = F_50 ( V_23 , V_93 ,
V_95 , V_91 ) ;
if ( F_11 ( V_94 [ V_30 ] ) ) {
V_50 = V_94 [ V_30 ] ?
F_13 ( V_94 [ V_30 ] ) : - V_35 ;
F_12 ( L_21 ,
F_18 ( V_93 ) ,
F_51 ( V_23 ) ,
V_50 ) ;
goto V_99;
}
}
return V_94 ;
V_99:
for ( V_30 -- ; V_30 > 0 ; V_30 -- )
F_52 ( V_94 [ V_30 ] ) ;
F_28 ( V_94 ) ;
return F_21 ( V_50 ) ;
}
static void F_53 ( struct V_26 * * V_94 )
{
int V_30 ;
for ( V_30 = 0 ; V_94 [ V_30 ] ; V_30 ++ )
F_52 ( V_94 [ V_30 ] ) ;
F_28 ( V_94 ) ;
}
static int F_54 ( struct V_100 * V_22 ,
struct V_101 * V_102 ,
struct V_13 * V_14 )
{
int V_50 ;
struct V_103 * V_104 ;
F_8 ( & V_22 -> V_27 ) ;
V_104 = F_55 ( V_22 -> V_23 ) ;
if ( V_22 -> V_105 == 0 ) {
V_50 = F_56 ( V_102 -> V_106 , & V_104 -> V_107 ) ;
if ( V_50 ) {
F_12 ( L_22 ,
F_57 ( V_104 ) ) ;
return V_50 ;
}
V_22 -> V_102 = V_102 ;
}
V_22 -> V_105 ++ ;
F_58 ( V_22 -> V_102 != V_102 ) ;
V_14 -> V_22 = V_22 ;
return 0 ;
}
static void F_59 ( struct V_13 * V_14 )
{
struct V_103 * V_104 ;
struct V_101 * V_102 ;
F_8 ( & V_14 -> V_22 -> V_27 ) ;
V_102 = V_14 -> V_22 -> V_102 ;
V_104 = F_55 ( V_14 -> V_22 -> V_23 ) ;
if ( -- V_14 -> V_22 -> V_105 == 0 ) {
V_14 -> V_22 -> V_102 = NULL ;
F_60 ( V_102 -> V_106 , & V_104 -> V_107 ) ;
}
V_14 -> V_22 = NULL ;
}
static void F_61 ( struct V_89 * V_90 )
{
char V_10 [ 512 ] ;
F_62 ( V_10 , sizeof( V_10 ) , V_90 ) ;
F_63 ( L_23 , V_10 ) ;
}
static int F_64 ( struct V_15 * V_52 ,
T_2 * V_108 )
{
enum V_54 V_55 = V_52 -> V_55 ;
int V_50 ;
T_1 V_49 = 0 ;
switch ( V_55 ) {
case V_71 :
* V_108 = V_52 -> V_56 . V_49 ;
break;
case V_72 :
V_50 = F_32 ( V_52 -> V_67 . V_63 ,
NULL , NULL ,
& V_49 ) ;
if ( V_50 )
return V_50 ;
* V_108 = V_49 ;
break;
default:
F_12 ( L_18 , V_55 ) ;
return - V_57 ;
}
return 0 ;
}
struct V_13 *
F_65 ( struct V_109 * V_37 , struct V_100 * V_22 ,
struct V_101 * V_102 ,
struct V_89 * V_90 ,
struct V_47 * V_110 )
{
struct V_13 * V_14 ;
int V_50 ;
enum V_54 V_111 = V_110 -> V_55 ;
struct V_15 * V_52 ;
F_8 ( & V_22 -> V_27 ) ;
V_50 = F_66 ( & V_112 [ V_111 ] ,
V_90 ) ;
if ( V_50 ) {
F_12 ( L_24 ,
V_111 ) ;
F_61 ( V_90 ) ;
return F_21 ( V_50 ) ;
}
V_14 = F_24 ( sizeof( * V_14 ) , V_60 ) ;
if ( ! V_14 ) {
F_12 ( L_25 ) ;
return NULL ;
}
V_14 -> V_94 = F_49 ( V_22 -> V_23 , V_90 ,
V_14 ) ;
if ( F_11 ( V_14 -> V_94 ) ) {
V_50 = V_14 -> V_94 ?
F_13 ( V_14 -> V_94 ) : - V_35 ;
F_12 ( L_26 ,
V_14 -> V_87 , V_50 ) ;
goto V_113;
}
V_50 = F_54 ( V_22 , V_102 , V_14 ) ;
if ( V_50 )
goto V_99;
F_67 ( & V_14 -> V_17 ) ;
F_68 ( & V_14 -> V_27 ) ;
V_14 -> V_37 = V_37 ;
V_14 -> V_2 = V_3 ;
V_14 -> V_21 = V_114 -> V_115 ;
V_52 = F_36 ( V_14 , V_110 ) ;
if ( F_11 ( V_52 ) ) {
F_12 ( L_27 ,
F_13 ( V_52 ) ) ;
V_50 = V_52 ? F_13 ( V_52 ) : - V_59 ;
goto V_116;
}
V_50 = F_64 ( V_52 , & V_14 -> V_87 ) ;
if ( V_50 )
goto V_117;
V_14 -> V_19 . V_20 = V_14 -> V_87 ;
F_69 ( V_14 ) ;
return V_14 ;
V_117:
F_39 ( V_52 ) ;
V_116:
F_59 ( V_14 ) ;
V_99:
F_53 ( V_14 -> V_94 ) ;
V_113:
F_28 ( V_14 ) ;
return F_21 ( V_50 ) ;
}
void F_70 ( struct V_13 * V_14 )
{
F_58 ( V_14 -> V_2 != V_3 ) ;
F_8 ( & V_14 -> V_22 -> V_27 ) ;
F_43 ( V_14 ) ;
F_71 ( V_14 ) ;
F_59 ( V_14 ) ;
F_53 ( V_14 -> V_94 ) ;
F_28 ( V_14 ) ;
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
return F_21 ( - V_57 ) ;
}
