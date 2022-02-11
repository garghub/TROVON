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
static int F_5 ( struct V_2 * V_3 , char * V_32 ,
int V_33 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_34 V_35 ;
int V_36 = V_33 ;
int V_13 ;
if ( NULL == V_32 )
return - V_16 ;
for ( V_13 = 0 ; V_13 < V_5 -> V_11 [ V_36 ] . V_37 ; V_13 ++ ) {
V_35 = V_5 -> V_11 [ V_36 ] . V_38 [ V_13 ] ;
if ( ! strcmp ( V_32 , V_35 . V_39 ) ) {
V_3 -> V_23 = V_35 ;
return 0 ;
}
}
return - V_16 ;
}
static int F_6 ( struct V_2 * V_3 ,
struct V_34 * V_40 )
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
struct V_34 V_35 ;
int V_36 = V_3 -> V_42 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_3 -> V_5 -> V_11 [ V_36 ] . V_37 ; V_13 ++ ) {
V_35 = V_5 -> V_11 [ V_36 ] . V_38 [ V_13 ] ;
if ( ( V_35 . V_43 & V_44 ) &&
( V_35 . V_45 . V_41 == V_41 ) ) {
V_3 -> V_23 = V_35 ;
return 0 ;
}
}
return - V_16 ;
}
static int F_8 ( struct V_2 * V_3 ,
T_1 V_46 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_34 V_35 ;
int V_36 = V_3 -> V_42 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_3 -> V_5 -> V_11 [ V_36 ] . V_37 ; V_13 ++ ) {
V_35 = V_5 -> V_11 [ V_36 ] . V_38 [ V_13 ] ;
if ( ( V_35 . V_43 & V_47 ) &&
( V_35 . V_45 . V_46 & V_46 ) ) {
V_3 -> V_23 = V_35 ;
return 0 ;
}
}
return - V_16 ;
}
static int F_9 ( struct V_2 * V_3 ,
char * V_48 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_34 V_35 ;
int V_36 = V_3 -> V_42 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_3 -> V_5 -> V_11 [ V_36 ] . V_37 ; V_13 ++ ) {
V_35 = V_5 -> V_11 [ V_36 ] . V_38 [ V_13 ] ;
if ( ! strcmp ( V_35 . V_39 , V_48 ) ) {
V_3 -> V_23 = V_35 ;
return 0 ;
}
}
return - V_16 ;
}
static int F_10 ( struct V_2 * V_3 , int V_6 )
{
struct V_1 * V_49 =
F_1 ( V_3 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_50 * V_51 = V_3 -> V_51 ;
enum V_52 V_53 ;
int V_54 ;
int V_55 ;
int V_56 = 0 ;
if ( V_6 >= V_5 -> V_31 )
return - V_16 ;
F_11 ( & V_3 -> V_57 ) ;
V_55 = V_3 -> V_7 ;
V_54 = V_5 -> V_11 [ V_6 ] . V_29 . V_6 ;
if ( strcmp ( V_49 -> V_14 ,
V_5 -> V_11 [ V_6 ] . V_12 ) ) {
V_55 = F_2 ( V_5 , V_6 ) ;
if ( V_55 < 0 ) {
V_56 = - V_16 ;
goto V_58;
}
V_53 = V_5 -> V_11 [ V_6 ] . V_53 ;
V_51 -> V_59 ( V_53 ) ;
if ( V_56 )
goto V_58;
}
V_56 = F_12 ( V_3 -> V_60 [ V_55 ] , V_61 ,
V_62 , 0 , V_54 , 0 ) ;
if ( V_56 )
goto V_58;
V_56 = F_5 ( V_3 ,
V_5 -> V_11 [ V_6 ] . V_63 , V_6 ) ;
if ( ! V_56 ) {
struct V_64 * V_65 = V_3 -> V_65 ;
V_65 -> V_66 . V_67 ( V_65 ,
V_3 -> V_23 . V_68 ) ;
V_65 -> V_66 . V_69 ( V_65 ,
V_3 -> V_23 . V_70 ) ;
V_3 -> V_7 = V_55 ;
V_3 -> V_42 = V_6 ;
}
V_58:
F_13 ( & V_3 -> V_57 ) ;
return V_56 ;
}
static int F_14 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
int V_56 = 0 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_5 -> V_31 ; V_13 ++ ) {
if ( ! strcmp ( V_71 ,
V_5 -> V_11 [ V_13 ] . V_29 . V_39 ) ) {
V_56 = F_10 ( V_3 , V_13 ) ;
if ( ! V_56 )
V_3 -> V_42 = V_13 ;
return V_56 ;
}
}
return V_56 ;
}
static unsigned int F_15 ( struct V_2 * V_3 )
{
return V_3 -> V_42 ;
}
static int F_16 ( struct V_2 * V_3 ,
struct V_72 * V_41 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
int V_73 = V_3 -> V_42 ;
int V_55 = V_3 -> V_7 ;
int V_56 ;
if ( ! ( V_5 -> V_11 [ V_73 ] . V_29 . V_74 &
V_75 ) )
return - V_16 ;
V_56 = F_7 ( V_3 , V_41 -> V_76 ) ;
if ( V_56 )
return V_56 ;
F_11 ( & V_3 -> V_57 ) ;
V_56 = F_12 ( V_3 -> V_60 [ V_55 ] , V_61 ,
V_77 , V_41 ) ;
if ( ! V_56 && ( V_3 -> V_78 != NULL ) ) {
V_56 = F_12 ( V_3 -> V_78 , V_61 ,
V_77 , V_41 ) ;
}
if ( ! V_56 ) {
struct V_64 * V_65 = V_3 -> V_65 ;
V_65 -> V_66 . V_67 ( V_65 ,
V_3 -> V_23 . V_68 ) ;
V_65 -> V_66 . V_69 ( V_65 ,
V_3 -> V_23 . V_70 ) ;
}
F_13 ( & V_3 -> V_57 ) ;
return V_56 ;
}
static int F_17 ( struct V_2 * V_3 ,
struct V_72 * V_41 )
{
if ( V_3 -> V_23 . V_43 &
V_44 ) {
V_41 -> V_76 = V_3 -> V_23 . V_45 . V_41 ;
return 0 ;
}
return - V_16 ;
}
static int F_18 ( struct V_2 * V_3 ,
struct V_79 * V_80 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
int V_73 = V_3 -> V_42 ;
struct V_81 * V_29 = & V_5 -> V_11 [ V_73 ] ;
int V_82 = 0 ;
int V_13 ;
if ( ! ( V_29 -> V_29 . V_74 & V_75 ) )
return - V_16 ;
for ( V_13 = 0 ; V_13 < V_29 -> V_37 ; V_13 ++ ) {
if ( V_29 -> V_38 [ V_13 ] . V_43 == V_44 ) {
if ( V_82 == V_80 -> V_6 )
break;
V_82 ++ ;
}
}
if ( V_13 == V_29 -> V_37 )
return - V_16 ;
return F_19 ( V_29 -> V_38 [ V_13 ] . V_45 . V_41 ,
V_80 ) ;
}
static int F_20 ( struct V_2 * V_3 , T_1 * V_46 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
int V_73 = V_3 -> V_42 ;
int V_55 = V_3 -> V_7 ;
int V_56 ;
if ( ! ( V_5 -> V_11 [ V_73 ] . V_29 . V_74 &
V_83 ) )
return - V_16 ;
V_56 = F_8 ( V_3 , * V_46 ) ;
if ( V_56 )
return V_56 ;
F_11 ( & V_3 -> V_57 ) ;
V_56 = F_12 ( V_3 -> V_60 [ V_55 ] , V_61 ,
V_84 , * V_46 ) ;
if ( ! V_56 ) {
struct V_64 * V_65 = V_3 -> V_65 ;
V_65 -> V_66 . V_67 ( V_65 ,
V_3 -> V_23 . V_68 ) ;
V_65 -> V_66 . V_69 ( V_65 ,
V_3 -> V_23 . V_70 ) ;
}
F_13 ( & V_3 -> V_57 ) ;
return V_56 ;
}
static int F_21 ( struct V_2 * V_3 , T_1 * V_46 )
{
struct V_34 V_85 = V_3 -> V_23 ;
if ( V_85 . V_43 & V_47 ) {
* V_46 = V_85 . V_45 . V_46 ;
return 0 ;
}
return - V_16 ;
}
static int F_22 ( struct V_2 * V_3 ,
struct V_34 * V_40 )
{
struct V_34 * V_86 = NULL ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_72 V_41 ;
struct V_64 * V_65 ;
int V_73 = V_3 -> V_42 ;
int V_56 = 0 ;
int V_13 ;
if ( ( NULL == V_40 ) || ( NULL == V_40 -> V_39 ) )
return - V_16 ;
for ( V_13 = 0 ; V_13 < V_5 -> V_11 [ V_73 ] . V_37 ; V_13 ++ ) {
if ( ! strcmp ( V_40 -> V_39 ,
V_5 -> V_11 [ V_73 ] . V_38 [ V_13 ] . V_39 ) ) {
V_86 = & V_5 -> V_11 [ V_73 ] . V_38 [ V_13 ] ;
if ( V_86 -> V_43 & V_47 )
return F_20 ( V_3 ,
& V_86 -> V_45 . V_46 ) ;
if ( V_86 -> V_43 & V_44 ) {
V_41 . V_76 =
V_86 -> V_45 . V_41 ;
return F_16 ( V_3 , & V_41 ) ;
}
}
}
if ( V_86 == NULL )
return - V_16 ;
F_11 ( & V_3 -> V_57 ) ;
V_65 = V_3 -> V_65 ;
V_3 -> V_23 = * V_86 ;
V_65 -> V_66 . V_67 ( V_65 ,
V_3 -> V_23 . V_68 ) ;
V_65 -> V_66 . V_69 ( V_65 ,
V_3 -> V_23 . V_70 ) ;
F_13 ( & V_3 -> V_57 ) ;
return V_56 ;
}
static int F_23 ( struct V_2 * V_3 )
{
int V_56 ;
V_56 = F_9 ( V_3 , V_87 ) ;
if ( V_56 )
return V_56 ;
return F_22 ( V_3 , & V_3 -> V_23 ) ;
}
static int F_24 ( struct V_88 * V_89 , void * V_90 )
{
struct V_91 * V_92 = F_25 ( V_89 ) ;
struct V_2 * V_3 = V_90 ;
if ( strcmp ( L_1 , V_92 -> V_39 ) == 0 )
V_3 -> V_65 = F_26 ( V_92 ) ;
if ( strcmp ( L_2 , V_92 -> V_39 ) == 0 )
V_3 -> V_51 = F_27 ( & V_92 -> V_89 ) ;
return 0 ;
}
static int F_28 ( struct V_88 * V_89 , struct V_2 * V_3 )
{
struct V_1 * V_93 ;
struct V_94 * V_95 ;
struct V_96 * * V_97 ;
struct V_64 * V_65 ;
struct V_98 * V_99 ;
int V_33 ;
int V_100 ;
int V_56 = 0 ;
int V_101 ;
int V_13 ;
if ( NULL == V_3 || NULL == V_89 ) {
F_29 ( V_102 L_3 ) ;
return - V_103 ;
}
if ( V_3 -> V_104 )
return 0 ;
F_11 ( & V_3 -> V_57 ) ;
if ( strcmp ( V_3 -> V_5 -> V_14 , L_4 ) != 0 ) {
V_3 -> V_105 = F_30 ( V_3 -> V_92 , L_5 ) ;
if ( F_31 ( V_3 -> V_105 ) ) {
V_56 = F_32 ( V_3 -> V_105 ) ;
goto V_106;
}
if ( F_33 ( V_3 -> V_105 ) ) {
V_56 = - V_103 ;
goto V_106;
}
}
F_34 ( V_107 , 1 ) ;
V_56 = F_35 ( V_89 , & V_3 -> V_108 ) ;
if ( V_56 ) {
F_36 ( V_89 -> V_109 ,
L_6 ) ;
goto V_110;
}
F_37 ( & V_3 -> V_108 , L_7 ) ;
V_101 = F_38 ( & V_111 , NULL , V_3 ,
F_24 ) ;
if ( V_101 < 0 )
return V_101 ;
V_3 -> V_8 = F_39 ( & V_3 -> V_108 ,
V_3 -> V_5 -> V_8 . V_14 ) ;
if ( V_3 -> V_8 == NULL ) {
F_36 ( & V_3 -> V_108 ,
L_8 ) ;
V_56 = - V_103 ;
goto V_112;
}
V_65 = V_3 -> V_65 ;
if ( NULL != V_65 -> V_66 . V_113 ) {
V_101 = V_65 -> V_66 . V_113 ( V_65 ) ;
if ( V_101 ) {
F_36 ( & V_3 -> V_108 ,
L_9 ) ;
V_101 = - V_114 ;
goto V_112;
}
}
V_100 = V_3 -> V_5 -> V_15 + 1 ;
V_3 -> V_60 = F_40 (
sizeof( struct V_96 * ) * V_100 ,
V_115 ) ;
if ( NULL == V_3 -> V_60 ) {
F_36 ( & V_3 -> V_108 ,
L_10 ) ;
V_56 = - V_114 ;
goto V_112;
}
V_99 = F_41 ( V_3 -> V_5 -> V_116 ) ;
for ( V_13 = 0 ; V_13 < ( V_3 -> V_5 -> V_15 + 1 ) ; V_13 ++ ) {
if ( V_13 == 0 ) {
V_97 = & V_3 -> V_60 [ V_13 ] ;
* V_97 = V_3 -> V_8 ;
continue;
}
V_93 = & V_3 -> V_5 -> V_9 [ V_13 ] ;
if ( V_93 -> V_117 ) {
V_97 = & V_3 -> V_60 [ V_13 ] ;
* V_97 = F_42 (
& V_3 -> V_108 , V_99 ,
& V_93 -> V_118 , NULL ) ;
if ( * V_97 )
F_37 ( & V_3 -> V_108 ,
L_11 ,
V_93 -> V_14 ) ;
else {
F_36 ( & V_3 -> V_108 , L_12
L_13 ,
V_93 -> V_14 ) ;
V_56 = - V_103 ;
goto V_119;
}
} else
F_43 ( & V_3 -> V_108 , L_14
L_15 ) ;
}
if ( ( strcmp ( V_3 -> V_5 -> V_14 , L_16 ) == 0 ) &&
V_3 -> V_5 -> V_78 != NULL ) {
V_95 = V_3 -> V_5 -> V_78 ;
if ( V_95 -> V_117 ) {
V_3 -> V_78 = F_42 (
& V_3 -> V_108 , V_99 ,
& V_95 -> V_118 , NULL ) ;
if ( ! V_3 -> V_78 ) {
F_36 ( & V_3 -> V_108 ,
L_17 ,
V_95 -> V_14 ) ;
V_56 = - V_103 ;
goto V_120;
}
F_37 ( & V_3 -> V_108 ,
L_11 ,
V_95 -> V_14 ) ;
} else {
V_3 -> V_78 = NULL ;
F_43 ( & V_3 -> V_108 , L_18
L_15 ) ;
}
} else {
V_3 -> V_78 = NULL ;
}
V_3 -> V_7 = 0 ;
V_3 -> V_42 = 0 ;
V_33 = 0 ;
F_13 ( & V_3 -> V_57 ) ;
F_29 ( V_121 L_19 , V_71 ) ;
V_56 = F_14 ( V_3 ) ;
if ( V_56 ) {
F_36 ( & V_3 -> V_108 , L_20 ,
V_71 ) ;
return V_56 ;
}
F_29 ( V_121 L_21 , V_87 ) ;
V_56 = F_23 ( V_3 ) ;
if ( V_56 ) {
F_36 ( & V_3 -> V_108 , L_22 ,
V_87 ) ;
return V_56 ;
}
V_3 -> V_104 = 1 ;
return 0 ;
V_120:
F_44 ( V_3 -> V_78 ) ;
V_119:
F_44 ( V_3 -> V_60 ) ;
V_112:
F_45 ( & V_3 -> V_108 ) ;
V_110:
if ( strcmp ( V_3 -> V_5 -> V_14 , L_4 ) != 0 )
F_46 ( V_3 -> V_105 ) ;
V_106:
F_13 ( & V_3 -> V_57 ) ;
return V_56 ;
}
static void F_47 ( struct V_88 * V_89 , struct V_2 * V_3 )
{
F_45 ( & V_3 -> V_108 ) ;
if ( strcmp ( V_3 -> V_5 -> V_14 , L_4 ) != 0 )
F_46 ( V_3 -> V_105 ) ;
F_44 ( V_3 -> V_78 ) ;
F_44 ( V_3 -> V_60 ) ;
V_3 -> V_104 = 0 ;
F_34 ( V_107 , 0 ) ;
}
static T_2 int F_48 ( struct V_91 * V_92 )
{
struct V_2 * V_3 ;
struct V_4 * V_5 ;
int V_56 = - V_16 ;
if ( V_92 -> V_89 . V_122 == NULL ) {
F_36 ( V_92 -> V_89 . V_109 , L_23 ) ;
return - V_103 ;
}
V_5 = V_92 -> V_89 . V_122 ;
if ( ! V_5 -> V_14 [ 0 ] ||
! V_5 -> V_123 . V_14 [ 0 ] ||
! V_5 -> V_8 . V_14 [ 0 ] ) {
F_36 ( V_92 -> V_89 . V_109 , L_24
L_25 ) ;
return V_56 ;
}
V_3 = F_49 ( sizeof( * V_3 ) , V_115 ) ;
if ( V_3 == NULL ) {
F_36 ( V_92 -> V_89 . V_109 , L_26
L_27 ) ;
return - V_114 ;
}
V_3 -> V_5 = V_5 ;
V_3 -> V_66 = V_124 ;
V_3 -> V_92 = & V_92 -> V_89 ;
if ( V_5 -> V_11 -> V_37 > 0 )
V_3 -> V_23 = V_3 -> V_5 -> V_11 [ 0 ] . V_38 [ 0 ] ;
else {
F_44 ( V_3 ) ;
return - V_103 ;
}
F_50 ( V_92 , V_3 ) ;
F_51 ( & V_3 -> V_57 ) ;
return 0 ;
}
static int F_52 ( struct V_91 * V_88 )
{
struct V_2 * V_3 = F_26 ( V_88 ) ;
F_44 ( V_3 ) ;
return 0 ;
}
