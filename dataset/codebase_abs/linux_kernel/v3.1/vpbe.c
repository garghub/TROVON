static struct V_1 *
F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
int V_6 = V_3 -> V_7 ;
return ( ( V_6 == 0 ) ? & V_5 -> V_8 :
& V_5 -> V_9 [ V_6 - 1 ] ) ;
}
static int F_2 ( struct V_4 * V_5 ,
int V_6 )
{
char * V_10 = V_5 -> V_11 [ V_6 ] . V_12 ;
int V_13 ;
if ( ! strcmp ( V_10 , V_5 -> V_8 . V_14 ) )
return 0 ;
for ( V_13 = 0 ; V_13 < V_5 -> V_15 ; V_13 ++ ) {
if ( ! strcmp ( V_10 ,
V_5 -> V_9 [ V_13 ] . V_14 ) )
return V_13 + 1 ;
}
return - V_16 ;
}
static int F_3 ( struct V_2 * V_3 ,
struct V_17 * V_18 )
{
if ( NULL == V_18 )
return - V_16 ;
V_18 -> V_19 . V_20 = 0 ;
V_18 -> V_19 . V_21 = 0 ;
V_18 -> V_19 . V_22 = V_3 -> V_23 . V_24 ;
V_18 -> V_19 . V_25 = V_3 -> V_23 . V_26 ;
V_18 -> V_27 = V_18 -> V_19 ;
return 0 ;
}
static int F_4 ( struct V_2 * V_3 ,
struct V_28 * V_29 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
int V_30 = V_29 -> V_6 ;
if ( V_30 >= V_5 -> V_31 )
return - V_16 ;
* V_29 = V_5 -> V_11 [ V_30 ] . V_29 ;
V_29 -> V_6 = V_30 ;
return 0 ;
}
static int F_5 ( struct V_2 * V_3 , char * V_32 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_33 V_34 ;
int V_35 = V_3 -> V_36 ;
int V_13 ;
if ( NULL == V_32 )
return - V_16 ;
for ( V_13 = 0 ; V_13 < V_5 -> V_11 [ V_35 ] . V_37 ; V_13 ++ ) {
V_34 = V_5 -> V_11 [ V_35 ] . V_38 [ V_13 ] ;
if ( ! strcmp ( V_32 , V_34 . V_39 ) ) {
V_3 -> V_23 = V_34 ;
return 0 ;
}
}
return - V_16 ;
}
static int F_6 ( struct V_2 * V_3 ,
struct V_33 * V_40 )
{
if ( NULL == V_40 )
return - V_16 ;
* V_40 = V_3 -> V_23 ;
return 0 ;
}
static int F_7 ( struct V_2 * V_3 ,
unsigned int V_41 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_33 V_34 ;
int V_35 = V_3 -> V_36 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_3 -> V_5 -> V_11 [ V_35 ] . V_37 ; V_13 ++ ) {
V_34 = V_5 -> V_11 [ V_35 ] . V_38 [ V_13 ] ;
if ( ( V_34 . V_42 & V_43 ) &&
( V_34 . V_44 . V_41 == V_41 ) ) {
V_3 -> V_23 = V_34 ;
return 0 ;
}
}
return - V_16 ;
}
static int F_8 ( struct V_2 * V_3 ,
T_1 V_45 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_33 V_34 ;
int V_35 = V_3 -> V_36 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_3 -> V_5 -> V_11 [ V_35 ] . V_37 ; V_13 ++ ) {
V_34 = V_5 -> V_11 [ V_35 ] . V_38 [ V_13 ] ;
if ( ( V_34 . V_42 & V_46 ) &&
( V_34 . V_44 . V_45 & V_45 ) ) {
V_3 -> V_23 = V_34 ;
return 0 ;
}
}
return - V_16 ;
}
static int F_9 ( struct V_2 * V_3 ,
char * V_47 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_33 V_34 ;
int V_35 = V_3 -> V_36 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_3 -> V_5 -> V_11 [ V_35 ] . V_37 ; V_13 ++ ) {
V_34 = V_5 -> V_11 [ V_35 ] . V_38 [ V_13 ] ;
if ( ! strcmp ( V_34 . V_39 , V_47 ) ) {
V_3 -> V_23 = V_34 ;
return 0 ;
}
}
return - V_16 ;
}
static int F_10 ( struct V_2 * V_3 , int V_6 )
{
struct V_1 * V_48 =
F_1 ( V_3 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
int V_49 ;
int V_50 ;
int V_51 = 0 ;
if ( V_6 >= V_5 -> V_31 )
return - V_16 ;
F_11 ( & V_3 -> V_52 ) ;
V_50 = V_3 -> V_7 ;
V_49 = V_5 -> V_11 [ V_6 ] . V_29 . V_6 ;
if ( strcmp ( V_48 -> V_14 ,
V_5 -> V_11 [ V_6 ] . V_12 ) ) {
V_50 = F_2 ( V_5 , V_6 ) ;
if ( V_50 < 0 ) {
V_51 = - V_16 ;
goto V_53;
}
if ( V_51 )
goto V_53;
}
V_51 = F_12 ( V_3 -> V_54 [ V_50 ] , V_55 ,
V_56 , 0 , V_49 , 0 ) ;
if ( V_51 )
goto V_53;
V_51 = F_5 ( V_3 ,
V_5 -> V_11 [ V_6 ] . V_57 ) ;
if ( ! V_51 ) {
struct V_58 * V_59 = V_3 -> V_59 ;
V_59 -> V_60 . V_61 ( V_59 ,
V_3 -> V_23 . V_62 ) ;
V_59 -> V_60 . V_63 ( V_59 ,
V_3 -> V_23 . V_64 ) ;
V_3 -> V_7 = V_50 ;
V_3 -> V_36 = V_6 ;
}
V_53:
F_13 ( & V_3 -> V_52 ) ;
return V_51 ;
}
static int F_14 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
int V_51 = 0 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_5 -> V_31 ; V_13 ++ ) {
if ( ! strcmp ( V_65 ,
V_5 -> V_11 [ V_13 ] . V_29 . V_39 ) ) {
V_51 = F_10 ( V_3 , V_13 ) ;
if ( ! V_51 )
V_3 -> V_36 = V_13 ;
return V_51 ;
}
}
return V_51 ;
}
static unsigned int F_15 ( struct V_2 * V_3 )
{
return V_3 -> V_36 ;
}
static int F_16 ( struct V_2 * V_3 ,
struct V_66 * V_41 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
int V_67 = V_3 -> V_36 ;
int V_50 = V_3 -> V_7 ;
int V_51 ;
if ( ! ( V_5 -> V_11 [ V_67 ] . V_29 . V_68 &
V_69 ) )
return - V_16 ;
V_51 = F_7 ( V_3 , V_41 -> V_70 ) ;
if ( V_51 )
return V_51 ;
F_11 ( & V_3 -> V_52 ) ;
V_51 = F_12 ( V_3 -> V_54 [ V_50 ] , V_55 ,
V_71 , V_41 ) ;
if ( ! V_51 ) {
struct V_58 * V_59 = V_3 -> V_59 ;
V_59 -> V_60 . V_61 ( V_59 ,
V_3 -> V_23 . V_62 ) ;
V_59 -> V_60 . V_63 ( V_59 ,
V_3 -> V_23 . V_64 ) ;
}
F_13 ( & V_3 -> V_52 ) ;
return V_51 ;
}
static int F_17 ( struct V_2 * V_3 ,
struct V_66 * V_41 )
{
if ( V_3 -> V_23 . V_42 &
V_43 ) {
V_41 -> V_70 = V_3 -> V_23 . V_44 . V_41 ;
return 0 ;
}
return - V_16 ;
}
static int F_18 ( struct V_2 * V_3 ,
struct V_72 * V_73 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
int V_67 = V_3 -> V_36 ;
struct V_74 * V_29 = & V_5 -> V_11 [ V_67 ] ;
int V_75 = 0 ;
int V_13 ;
if ( ! ( V_29 -> V_29 . V_68 & V_69 ) )
return - V_16 ;
for ( V_13 = 0 ; V_13 < V_29 -> V_37 ; V_13 ++ ) {
if ( V_29 -> V_38 [ V_13 ] . V_42 == V_43 ) {
if ( V_75 == V_73 -> V_6 )
break;
V_75 ++ ;
}
}
if ( V_13 == V_29 -> V_37 )
return - V_16 ;
return F_19 ( V_29 -> V_38 [ V_13 ] . V_44 . V_41 ,
V_73 ) ;
}
static int F_20 ( struct V_2 * V_3 , T_1 * V_45 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
int V_67 = V_3 -> V_36 ;
int V_50 = V_3 -> V_7 ;
int V_51 ;
if ( ! ( V_5 -> V_11 [ V_67 ] . V_29 . V_68 &
V_76 ) )
return - V_16 ;
V_51 = F_8 ( V_3 , * V_45 ) ;
if ( V_51 )
return V_51 ;
F_11 ( & V_3 -> V_52 ) ;
V_51 = F_12 ( V_3 -> V_54 [ V_50 ] , V_55 ,
V_77 , * V_45 ) ;
if ( ! V_51 ) {
struct V_58 * V_59 = V_3 -> V_59 ;
V_59 -> V_60 . V_61 ( V_59 ,
V_3 -> V_23 . V_62 ) ;
V_59 -> V_60 . V_63 ( V_59 ,
V_3 -> V_23 . V_64 ) ;
}
F_13 ( & V_3 -> V_52 ) ;
return V_51 ;
}
static int F_21 ( struct V_2 * V_3 , T_1 * V_45 )
{
struct V_33 V_78 = V_3 -> V_23 ;
if ( V_78 . V_42 & V_46 ) {
* V_45 = V_78 . V_44 . V_45 ;
return 0 ;
}
return - V_16 ;
}
static int F_22 ( struct V_2 * V_3 ,
struct V_33 * V_40 )
{
struct V_33 * V_79 = NULL ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_66 V_41 ;
struct V_58 * V_59 ;
int V_67 = V_3 -> V_36 ;
int V_51 = 0 ;
int V_13 ;
if ( ( NULL == V_40 ) || ( NULL == V_40 -> V_39 ) )
return - V_16 ;
for ( V_13 = 0 ; V_13 < V_5 -> V_11 [ V_67 ] . V_37 ; V_13 ++ ) {
if ( ! strcmp ( V_40 -> V_39 ,
V_5 -> V_11 [ V_67 ] . V_38 [ V_13 ] . V_39 ) ) {
V_79 = & V_5 -> V_11 [ V_67 ] . V_38 [ V_13 ] ;
if ( V_79 -> V_42 & V_46 )
return F_20 ( V_3 ,
& V_79 -> V_44 . V_45 ) ;
if ( V_79 -> V_42 & V_43 ) {
V_41 . V_70 =
V_79 -> V_44 . V_41 ;
return F_16 ( V_3 , & V_41 ) ;
}
}
}
if ( V_79 == NULL )
return - V_16 ;
F_11 ( & V_3 -> V_52 ) ;
V_59 = V_3 -> V_59 ;
V_3 -> V_23 = * V_79 ;
V_59 -> V_60 . V_61 ( V_59 ,
V_3 -> V_23 . V_62 ) ;
V_59 -> V_60 . V_63 ( V_59 ,
V_3 -> V_23 . V_64 ) ;
F_13 ( & V_3 -> V_52 ) ;
return V_51 ;
}
static int F_23 ( struct V_2 * V_3 )
{
int V_51 ;
V_51 = F_9 ( V_3 , V_80 ) ;
if ( V_51 )
return V_51 ;
return F_22 ( V_3 , & V_3 -> V_23 ) ;
}
static int F_24 ( struct V_81 * V_82 , void * V_83 )
{
struct V_84 * V_85 = F_25 ( V_82 ) ;
struct V_2 * V_3 = V_83 ;
if ( strcmp ( L_1 , V_85 -> V_39 ) == 0 )
V_3 -> V_59 = F_26 ( V_85 ) ;
return 0 ;
}
static int F_27 ( struct V_81 * V_82 , struct V_2 * V_3 )
{
struct V_1 * V_86 ;
struct V_87 * * V_88 ;
struct V_58 * V_59 ;
struct V_89 * V_90 ;
int V_91 ;
int V_92 ;
int V_51 = 0 ;
int V_93 ;
int V_13 ;
if ( NULL == V_3 || NULL == V_82 ) {
F_28 ( V_94 L_2 ) ;
return - V_95 ;
}
if ( V_3 -> V_96 )
return 0 ;
F_11 ( & V_3 -> V_52 ) ;
if ( strcmp ( V_3 -> V_5 -> V_14 , L_3 ) != 0 ) {
V_3 -> V_97 = F_29 ( V_3 -> V_85 , L_4 ) ;
if ( F_30 ( V_3 -> V_97 ) ) {
V_51 = F_31 ( V_3 -> V_97 ) ;
goto V_98;
}
if ( F_32 ( V_3 -> V_97 ) ) {
V_51 = - V_95 ;
goto V_98;
}
}
F_33 ( V_99 , 1 ) ;
V_51 = F_34 ( V_82 , & V_3 -> V_100 ) ;
if ( V_51 ) {
F_35 ( V_82 -> V_101 ,
L_5 ) ;
goto V_102;
}
F_36 ( & V_3 -> V_100 , L_6 ) ;
V_93 = F_37 ( & V_103 , NULL , V_3 ,
F_24 ) ;
if ( V_93 < 0 )
return V_93 ;
V_3 -> V_8 = F_38 ( & V_3 -> V_100 ,
V_3 -> V_5 -> V_8 . V_14 ) ;
if ( V_3 -> V_8 == NULL ) {
F_35 ( & V_3 -> V_100 ,
L_7 ) ;
V_51 = - V_95 ;
goto V_104;
}
V_59 = V_3 -> V_59 ;
if ( NULL != V_59 -> V_60 . V_105 ) {
V_93 = V_59 -> V_60 . V_105 ( V_59 ) ;
if ( V_93 ) {
F_35 ( & V_3 -> V_100 ,
L_8 ) ;
V_93 = - V_106 ;
goto V_104;
}
}
V_92 = V_3 -> V_5 -> V_15 + 1 ;
V_3 -> V_54 = F_39 (
sizeof( struct V_87 * ) * V_92 ,
V_107 ) ;
if ( NULL == V_3 -> V_54 ) {
F_35 ( & V_3 -> V_100 ,
L_9 ) ;
V_51 = - V_106 ;
goto V_104;
}
V_90 = F_40 ( V_3 -> V_5 -> V_108 ) ;
for ( V_13 = 0 ; V_13 < ( V_3 -> V_5 -> V_15 + 1 ) ; V_13 ++ ) {
if ( V_13 == 0 ) {
V_88 = & V_3 -> V_54 [ V_13 ] ;
* V_88 = V_3 -> V_8 ;
continue;
}
V_86 = & V_3 -> V_5 -> V_9 [ V_13 ] ;
if ( V_86 -> V_109 ) {
V_88 = & V_3 -> V_54 [ V_13 ] ;
* V_88 = F_41 (
& V_3 -> V_100 , V_90 ,
& V_86 -> V_110 , NULL ) ;
if ( * V_88 )
F_36 ( & V_3 -> V_100 ,
L_10 ,
V_86 -> V_14 ) ;
else {
F_35 ( & V_3 -> V_100 , L_11
L_12 ,
V_86 -> V_14 ) ;
V_51 = - V_95 ;
goto V_111;
}
} else
F_42 ( & V_3 -> V_100 , L_13
L_14 ) ;
}
V_3 -> V_7 = 0 ;
V_3 -> V_36 = 0 ;
V_91 = 0 ;
F_13 ( & V_3 -> V_52 ) ;
F_28 ( V_112 L_15 , V_65 ) ;
V_51 = F_14 ( V_3 ) ;
if ( V_51 ) {
F_35 ( & V_3 -> V_100 , L_16 ,
V_65 ) ;
return V_51 ;
}
F_28 ( V_112 L_17 , V_80 ) ;
V_51 = F_23 ( V_3 ) ;
if ( V_51 ) {
F_35 ( & V_3 -> V_100 , L_18 ,
V_80 ) ;
return V_51 ;
}
V_3 -> V_96 = 1 ;
return 0 ;
V_111:
F_43 ( V_3 -> V_54 ) ;
V_104:
F_44 ( & V_3 -> V_100 ) ;
V_102:
if ( strcmp ( V_3 -> V_5 -> V_14 , L_3 ) != 0 )
F_45 ( V_3 -> V_97 ) ;
V_98:
F_13 ( & V_3 -> V_52 ) ;
return V_51 ;
}
static void F_46 ( struct V_81 * V_82 , struct V_2 * V_3 )
{
F_44 ( & V_3 -> V_100 ) ;
if ( strcmp ( V_3 -> V_5 -> V_14 , L_3 ) != 0 )
F_45 ( V_3 -> V_97 ) ;
F_43 ( V_3 -> V_54 ) ;
V_3 -> V_96 = 0 ;
F_33 ( V_99 , 0 ) ;
}
static T_2 int F_47 ( struct V_84 * V_85 )
{
struct V_2 * V_3 ;
struct V_4 * V_5 ;
int V_51 = - V_16 ;
if ( V_85 -> V_82 . V_113 == NULL ) {
F_35 ( V_85 -> V_82 . V_101 , L_19 ) ;
return - V_95 ;
}
V_5 = V_85 -> V_82 . V_113 ;
if ( ! V_5 -> V_14 [ 0 ] ||
! V_5 -> V_114 . V_14 [ 0 ] ||
! V_5 -> V_8 . V_14 [ 0 ] ) {
F_35 ( V_85 -> V_82 . V_101 , L_20
L_21 ) ;
return V_51 ;
}
V_3 = F_48 ( sizeof( * V_3 ) , V_107 ) ;
if ( V_3 == NULL ) {
F_35 ( V_85 -> V_82 . V_101 , L_22
L_23 ) ;
return - V_106 ;
}
V_3 -> V_5 = V_5 ;
V_3 -> V_60 = V_115 ;
V_3 -> V_85 = & V_85 -> V_82 ;
if ( V_5 -> V_11 -> V_37 > 0 )
V_3 -> V_23 = V_3 -> V_5 -> V_11 [ 0 ] . V_38 [ 0 ] ;
else
return - V_95 ;
F_49 ( V_85 , V_3 ) ;
F_50 ( & V_3 -> V_52 ) ;
return 0 ;
}
static int F_51 ( struct V_84 * V_81 )
{
struct V_2 * V_3 = F_26 ( V_81 ) ;
F_43 ( V_3 ) ;
return 0 ;
}
static T_3 int F_52 ( void )
{
return F_53 ( & V_116 ) ;
}
static void F_54 ( void )
{
F_55 ( & V_116 ) ;
}
