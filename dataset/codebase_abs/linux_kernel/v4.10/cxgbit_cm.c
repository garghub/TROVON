static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = 0 ;
F_2 ( & V_2 -> V_4 ) ;
}
static void
F_3 ( struct V_1 * V_2 , const char * V_5 , T_1 V_3 )
{
if ( V_3 == V_6 )
V_2 -> V_3 = 0 ;
else
V_2 -> V_3 = - V_7 ;
if ( V_2 -> V_3 )
F_4 ( L_1 , V_5 , V_3 ) ;
F_5 ( & V_2 -> V_4 ) ;
}
static int
F_6 ( struct V_8 * V_9 ,
struct V_1 * V_2 , T_2 V_10 , T_2 V_11 ,
const char * V_5 )
{
int V_3 ;
if ( ! F_7 ( V_12 , & V_9 -> V_13 ) ) {
V_2 -> V_3 = - V_7 ;
goto V_14;
}
V_3 = F_8 ( & V_2 -> V_4 , V_11 * V_15 ) ;
if ( ! V_3 ) {
F_9 ( L_2 ,
V_5 , F_10 ( V_9 -> V_16 . V_17 ) , V_10 ) ;
V_2 -> V_3 = - V_18 ;
}
V_14:
if ( V_2 -> V_3 )
F_9 ( L_3 ,
F_10 ( V_9 -> V_16 . V_17 ) , V_2 -> V_3 , V_10 ) ;
return V_2 -> V_3 ;
}
static int F_11 ( const struct V_19 * V_20 )
{
return ( ( unsigned long ) V_20 >> 10 ) & ( V_21 - 1 ) ;
}
static struct V_22 *
F_12 ( struct V_8 * V_9 , struct V_19 * V_20 ,
unsigned int V_23 )
{
struct V_22 * V_24 = F_13 ( sizeof( * V_24 ) , V_25 ) ;
if ( V_24 ) {
int V_26 = F_11 ( V_20 ) ;
V_24 -> V_20 = V_20 ;
V_24 -> V_23 = V_23 ;
F_14 ( & V_9 -> V_27 ) ;
V_24 -> V_28 = V_9 -> V_29 [ V_26 ] ;
V_9 -> V_29 [ V_26 ] = V_24 ;
F_15 ( & V_9 -> V_27 ) ;
}
return V_24 ;
}
static int
F_16 ( struct V_8 * V_9 , struct V_19 * V_20 )
{
int V_23 = - 1 , V_26 = F_11 ( V_20 ) ;
struct V_22 * V_24 ;
F_14 ( & V_9 -> V_27 ) ;
for ( V_24 = V_9 -> V_29 [ V_26 ] ; V_24 ; V_24 = V_24 -> V_28 ) {
if ( V_24 -> V_20 == V_20 ) {
V_23 = V_24 -> V_23 ;
break;
}
}
F_15 ( & V_9 -> V_27 ) ;
return V_23 ;
}
static int F_17 ( struct V_8 * V_9 , struct V_19 * V_20 )
{
int V_23 = - 1 , V_26 = F_11 ( V_20 ) ;
struct V_22 * V_24 , * * V_30 = & V_9 -> V_29 [ V_26 ] ;
F_14 ( & V_9 -> V_27 ) ;
for ( V_24 = * V_30 ; V_24 ; V_30 = & V_24 -> V_28 , V_24 = V_24 -> V_28 ) {
if ( V_24 -> V_20 == V_20 ) {
V_23 = V_24 -> V_23 ;
* V_30 = V_24 -> V_28 ;
F_18 ( V_24 ) ;
break;
}
}
F_15 ( & V_9 -> V_27 ) ;
return V_23 ;
}
void F_19 ( struct V_31 * V_31 )
{
struct V_19 * V_20 ;
V_20 = F_20 ( V_31 , struct V_19 , V_31 ) ;
F_18 ( V_20 ) ;
}
static int
F_21 ( struct V_8 * V_9 , unsigned int V_23 ,
struct V_19 * V_20 )
{
struct V_32 * V_33 = (struct V_32 * )
& V_20 -> V_34 . V_35 ;
int V_36 ;
int V_3 ;
F_22 ( L_4 ,
V_37 , V_9 -> V_16 . V_38 [ 0 ] -> V_39 , V_23 , V_33 -> V_40 ) ;
V_36 = F_23 ( ( const struct V_41 * )
& V_33 -> V_42 ) ;
if ( V_36 != V_43 ) {
V_3 = F_24 ( V_9 -> V_16 . V_38 [ 0 ] ,
( const T_2 * ) & V_33 -> V_42 . V_44 , 1 ) ;
if ( V_3 ) {
F_4 ( L_5 ,
V_33 -> V_42 . V_44 , V_3 ) ;
return - V_45 ;
}
}
F_25 ( V_20 ) ;
F_1 ( & V_20 -> V_34 . V_46 ) ;
V_3 = F_26 ( V_9 -> V_16 . V_38 [ 0 ] ,
V_23 , & V_33 -> V_42 ,
V_33 -> V_40 ,
V_9 -> V_16 . V_47 [ 0 ] ) ;
if ( ! V_3 )
V_3 = F_6 ( V_9 , & V_20 -> V_34 . V_46 ,
0 , 10 , V_37 ) ;
else if ( V_3 > 0 )
V_3 = F_27 ( V_3 ) ;
else
F_28 ( V_20 ) ;
if ( V_3 ) {
if ( V_3 != - V_18 )
F_29 ( V_9 -> V_16 . V_38 [ 0 ] ,
( const T_2 * ) & V_33 -> V_42 . V_44 , 1 ) ;
F_4 ( L_6 ,
V_3 , V_23 , V_33 -> V_42 . V_44 ,
F_30 ( V_33 -> V_40 ) ) ;
}
return V_3 ;
}
static int
F_31 ( struct V_8 * V_9 , unsigned int V_23 ,
struct V_19 * V_20 )
{
struct V_48 * sin = (struct V_48 * )
& V_20 -> V_34 . V_35 ;
int V_3 ;
F_22 ( L_7 ,
V_37 , V_9 -> V_16 . V_38 [ 0 ] -> V_39 , V_23 , sin -> V_49 ) ;
F_25 ( V_20 ) ;
F_1 ( & V_20 -> V_34 . V_46 ) ;
V_3 = F_32 ( V_9 -> V_16 . V_38 [ 0 ] ,
V_23 , sin -> V_50 . V_51 ,
sin -> V_49 , 0 ,
V_9 -> V_16 . V_47 [ 0 ] ) ;
if ( ! V_3 )
V_3 = F_6 ( V_9 ,
& V_20 -> V_34 . V_46 ,
0 , 10 , V_37 ) ;
else if ( V_3 > 0 )
V_3 = F_27 ( V_3 ) ;
else
F_28 ( V_20 ) ;
if ( V_3 )
F_4 ( L_8 ,
V_3 , V_23 , & sin -> V_50 , F_30 ( sin -> V_49 ) ) ;
return V_3 ;
}
struct V_8 * F_33 ( struct V_52 * V_53 , T_1 * V_54 )
{
struct V_8 * V_9 ;
T_1 V_55 ;
F_34 (cdev, &cdev_list_head, list) {
struct V_56 * V_16 = & V_9 -> V_16 ;
for ( V_55 = 0 ; V_55 < V_16 -> V_57 ; V_55 ++ ) {
if ( V_16 -> V_38 [ V_55 ] == V_53 ) {
if ( V_54 )
* V_54 = V_55 ;
return V_9 ;
}
}
}
return NULL ;
}
static struct V_52 * F_35 ( struct V_52 * V_53 )
{
if ( V_53 -> V_58 & V_59 ) {
F_4 ( L_9 ,
V_53 -> V_39 ) ;
return NULL ;
}
if ( F_36 ( V_53 ) )
return F_37 ( V_53 ) ;
return V_53 ;
}
static struct V_52 * F_38 ( T_3 V_60 )
{
struct V_52 * V_53 ;
V_53 = F_39 ( & V_61 , V_60 , false ) ;
if ( ! V_53 )
return NULL ;
return F_35 ( V_53 ) ;
}
static struct V_52 * F_40 ( struct V_41 * V_62 )
{
struct V_52 * V_53 = NULL ;
bool V_63 = false ;
if ( F_41 ( V_64 ) ) {
F_42 (&init_net, ndev)
if ( F_43 ( & V_61 , V_62 , V_53 , 1 ) ) {
V_63 = true ;
break;
}
}
if ( ! V_63 )
return NULL ;
return F_35 ( V_53 ) ;
}
static struct V_8 * F_44 ( struct V_19 * V_20 )
{
struct V_65 * V_66 = & V_20 -> V_34 . V_35 ;
int V_67 = V_66 -> V_67 ;
struct V_52 * V_53 = NULL ;
struct V_8 * V_9 = NULL ;
F_45 () ;
if ( V_67 == V_68 ) {
struct V_48 * sin ;
sin = (struct V_48 * ) V_66 ;
V_53 = F_38 ( sin -> V_50 . V_51 ) ;
} else if ( V_67 == V_69 ) {
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_66 ;
V_53 = F_40 ( & V_33 -> V_42 ) ;
}
if ( ! V_53 )
goto V_14;
V_9 = F_33 ( V_53 , NULL ) ;
V_14:
F_46 () ;
return V_9 ;
}
static bool F_47 ( struct V_19 * V_20 )
{
struct V_65 * V_66 = & V_20 -> V_34 . V_35 ;
int V_67 = V_66 -> V_67 ;
int V_36 ;
if ( V_67 == V_68 ) {
struct V_48 * sin ;
sin = (struct V_48 * ) V_66 ;
if ( sin -> V_50 . V_51 == F_48 ( V_70 ) )
return true ;
} else if ( V_67 == V_69 ) {
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_66 ;
V_36 = F_23 ( ( const struct V_41 * )
& V_33 -> V_42 ) ;
if ( V_36 == V_43 )
return true ;
}
return false ;
}
static int
F_49 ( struct V_8 * V_9 , struct V_19 * V_20 )
{
int V_23 , V_3 ;
int V_67 = V_20 -> V_34 . V_35 . V_67 ;
if ( ! F_7 ( V_12 , & V_9 -> V_13 ) )
return - V_71 ;
V_23 = F_50 ( V_9 -> V_16 . V_72 , V_67 , V_20 ) ;
if ( V_23 < 0 )
return - V_71 ;
if ( ! F_12 ( V_9 , V_20 , V_23 ) ) {
F_51 ( V_9 -> V_16 . V_72 , V_23 , V_67 ) ;
return - V_71 ;
}
if ( V_67 == V_68 )
V_3 = F_31 ( V_9 , V_23 , V_20 ) ;
else
V_3 = F_21 ( V_9 , V_23 , V_20 ) ;
if ( V_3 ) {
if ( V_3 != - V_18 )
F_51 ( V_9 -> V_16 . V_72 , V_23 ,
V_67 ) ;
F_17 ( V_9 , V_20 ) ;
return V_3 ;
}
return V_3 ;
}
static int F_52 ( struct V_19 * V_20 )
{
struct V_8 * V_9 ;
int V_3 = - 1 ;
F_53 ( & V_73 ) ;
V_9 = F_44 ( V_20 ) ;
if ( ! V_9 )
goto V_14;
if ( F_16 ( V_9 , V_20 ) >= 0 )
goto V_14;
if ( F_49 ( V_9 , V_20 ) )
goto V_14;
V_20 -> V_34 . V_9 = V_9 ;
V_3 = 0 ;
V_14:
F_54 ( & V_73 ) ;
return V_3 ;
}
static int F_55 ( struct V_19 * V_20 )
{
struct V_8 * V_9 ;
int V_3 ;
T_2 V_74 = 0 ;
F_53 ( & V_73 ) ;
F_34 (cdev, &cdev_list_head, list) {
if ( F_16 ( V_9 , V_20 ) >= 0 ) {
F_54 ( & V_73 ) ;
return - 1 ;
}
}
F_34 (cdev, &cdev_list_head, list) {
V_3 = F_49 ( V_9 , V_20 ) ;
if ( V_3 == - V_18 )
break;
if ( V_3 != 0 )
continue;
V_74 ++ ;
}
F_54 ( & V_73 ) ;
return V_74 ? 0 : - 1 ;
}
int F_56 ( struct V_75 * V_76 , struct V_65 * V_77 )
{
struct V_19 * V_20 ;
int V_3 ;
if ( ( V_77 -> V_67 != V_68 ) &&
( V_77 -> V_67 != V_69 ) )
return - V_71 ;
V_20 = F_13 ( sizeof( * V_20 ) , V_25 ) ;
if ( ! V_20 )
return - V_45 ;
F_57 ( & V_20 -> V_78 ) ;
F_58 ( & V_20 -> V_34 . V_46 . V_4 ) ;
F_58 ( & V_20 -> V_79 ) ;
F_59 ( & V_20 -> V_80 ) ;
F_60 ( & V_20 -> V_81 ) ;
F_61 ( & V_20 -> V_31 ) ;
memcpy ( & V_76 -> V_82 , V_77 ,
sizeof( struct V_65 ) ) ;
memcpy ( & V_20 -> V_34 . V_35 , & V_76 -> V_82 ,
sizeof( V_20 -> V_34 . V_35 ) ) ;
V_20 -> V_76 = V_76 ;
V_20 -> V_34 . V_9 = NULL ;
if ( F_47 ( V_20 ) )
V_3 = F_55 ( V_20 ) ;
else
V_3 = F_52 ( V_20 ) ;
if ( V_3 ) {
F_28 ( V_20 ) ;
return - V_71 ;
}
V_76 -> V_83 = V_20 ;
V_20 -> V_34 . V_84 = V_85 ;
return 0 ;
}
static void
F_62 ( struct V_75 * V_76 , struct V_86 * V_87 ,
struct V_88 * V_89 )
{
V_87 -> V_90 = V_76 -> V_82 . V_67 ;
V_87 -> V_91 = V_89 -> V_34 . V_92 ;
V_87 -> V_93 = V_89 -> V_34 . V_35 ;
}
int F_63 ( struct V_75 * V_76 , struct V_86 * V_87 )
{
struct V_19 * V_20 = V_76 -> V_83 ;
struct V_88 * V_89 ;
int V_3 = 0 ;
V_78:
V_3 = F_64 ( & V_20 -> V_79 ) ;
if ( V_3 )
return - V_94 ;
F_65 ( & V_76 -> V_95 ) ;
if ( V_76 -> V_96 >= V_97 ) {
F_66 ( & V_76 -> V_95 ) ;
return - V_94 ;
}
F_66 ( & V_76 -> V_95 ) ;
F_65 ( & V_20 -> V_81 ) ;
if ( F_67 ( & V_20 -> V_80 ) ) {
F_66 ( & V_20 -> V_81 ) ;
goto V_78;
}
V_89 = F_68 ( & V_20 -> V_80 ,
struct V_88 ,
V_98 ) ;
F_69 ( & V_89 -> V_98 ) ;
F_66 ( & V_20 -> V_81 ) ;
V_87 -> V_99 = V_89 ;
V_89 -> V_87 = V_87 ;
F_62 ( V_76 , V_87 , V_89 ) ;
return 0 ;
}
static int
F_70 ( struct V_8 * V_9 , struct V_19 * V_20 )
{
int V_23 , V_3 ;
bool V_100 = false ;
V_23 = F_17 ( V_9 , V_20 ) ;
if ( V_23 < 0 )
return - V_71 ;
if ( ! F_7 ( V_12 , & V_9 -> V_13 ) )
return - V_71 ;
if ( V_20 -> V_76 -> V_82 . V_67 == V_69 )
V_100 = true ;
F_25 ( V_20 ) ;
F_1 ( & V_20 -> V_34 . V_46 ) ;
V_3 = F_71 ( V_9 -> V_16 . V_38 [ 0 ] , V_23 ,
V_9 -> V_16 . V_47 [ 0 ] , V_100 ) ;
if ( V_3 > 0 )
V_3 = F_27 ( V_3 ) ;
if ( V_3 ) {
F_28 ( V_20 ) ;
return V_3 ;
}
V_3 = F_6 ( V_9 , & V_20 -> V_34 . V_46 ,
0 , 10 , V_37 ) ;
if ( V_3 == - V_18 )
return V_3 ;
if ( V_100 && V_20 -> V_34 . V_9 ) {
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) & V_20 -> V_34 . V_35 ;
F_29 ( V_9 -> V_16 . V_38 [ 0 ] ,
( const T_2 * ) & V_33 -> V_42 . V_44 ,
1 ) ;
}
F_51 ( V_9 -> V_16 . V_72 , V_23 ,
V_20 -> V_34 . V_35 . V_67 ) ;
return 0 ;
}
static void F_72 ( struct V_19 * V_20 )
{
struct V_8 * V_9 ;
int V_3 ;
F_53 ( & V_73 ) ;
F_34 (cdev, &cdev_list_head, list) {
V_3 = F_70 ( V_9 , V_20 ) ;
if ( V_3 == - V_18 )
break;
}
F_54 ( & V_73 ) ;
}
static void F_73 ( struct V_19 * V_20 )
{
struct V_8 * V_9 ;
bool V_63 = false ;
F_53 ( & V_73 ) ;
F_34 (cdev, &cdev_list_head, list) {
if ( V_9 == V_20 -> V_34 . V_9 ) {
V_63 = true ;
break;
}
}
if ( ! V_63 )
goto V_14;
F_70 ( V_9 , V_20 ) ;
V_14:
F_54 ( & V_73 ) ;
}
void F_74 ( struct V_75 * V_76 )
{
struct V_19 * V_20 = V_76 -> V_83 ;
V_20 -> V_34 . V_84 = V_101 ;
if ( V_20 -> V_34 . V_9 )
F_73 ( V_20 ) ;
else
F_72 ( V_20 ) ;
V_76 -> V_83 = NULL ;
F_28 ( V_20 ) ;
}
static void F_75 ( struct V_88 * V_89 )
{
struct V_102 * V_103 ;
T_2 V_104 = F_76 ( sizeof( struct V_105 ) , 16 ) ;
V_103 = F_77 ( V_104 , V_106 ) ;
if ( ! V_103 )
return;
F_78 ( V_103 , V_104 , V_89 -> V_10 , V_89 -> V_107 ,
NULL , NULL ) ;
F_79 ( V_103 ) |= V_108 ;
F_80 ( & V_89 -> V_109 , V_103 ) ;
F_81 ( V_89 ) ;
}
static void F_82 ( void * V_110 , struct V_102 * V_103 )
{
F_22 ( L_10 , V_37 , V_110 ) ;
F_83 ( V_103 ) ;
}
static void F_84 ( void * V_110 , struct V_102 * V_103 )
{
struct V_8 * V_9 = V_110 ;
struct V_111 * V_112 = F_85 ( V_103 ) ;
F_22 ( L_11 , V_37 , V_9 ) ;
V_112 -> V_113 = V_114 ;
F_86 ( V_9 , V_103 ) ;
}
static int F_87 ( struct V_88 * V_89 )
{
struct V_102 * V_103 ;
T_2 V_104 = F_76 ( sizeof( struct V_111 ) , 16 ) ;
F_22 ( L_12 ,
V_37 , V_89 , V_89 -> V_10 , V_89 -> V_34 . V_84 ) ;
F_88 ( & V_89 -> V_109 ) ;
if ( ! F_89 ( V_115 , & V_89 -> V_34 . V_13 ) )
F_90 ( V_89 ) ;
V_103 = F_91 ( & V_89 -> V_116 ) ;
F_92 ( V_103 , V_104 , V_89 -> V_10 , V_89 -> V_107 ,
V_89 -> V_34 . V_9 , F_84 ) ;
return F_93 ( V_89 -> V_34 . V_9 , V_103 , V_89 -> V_117 ) ;
}
void F_94 ( struct V_86 * V_87 )
{
struct V_88 * V_89 = V_87 -> V_99 ;
bool V_118 = false ;
F_22 ( L_13 ,
V_37 , V_89 -> V_34 . V_84 ) ;
F_65 ( & V_89 -> V_119 ) ;
switch ( V_89 -> V_34 . V_84 ) {
case V_120 :
if ( V_87 -> V_121 == V_122 ) {
V_89 -> V_34 . V_84 = V_123 ;
F_75 ( V_89 ) ;
} else {
V_89 -> V_34 . V_84 = V_124 ;
F_87 ( V_89 ) ;
}
break;
case V_123 :
V_89 -> V_34 . V_84 = V_125 ;
F_75 ( V_89 ) ;
break;
case V_101 :
V_118 = true ;
break;
default:
F_4 ( L_14 ,
V_37 , V_89 , V_89 -> V_34 . V_84 ) ;
}
F_66 ( & V_89 -> V_119 ) ;
if ( V_118 )
F_95 ( V_89 ) ;
}
static void F_96 ( struct V_88 * V_89 , T_4 V_126 )
{
V_89 -> V_127 = V_89 -> V_34 . V_9 -> V_16 . V_128 [ F_97 ( V_126 ) ] -
( ( V_89 -> V_34 . V_92 . V_67 == V_68 ) ?
sizeof( struct V_129 ) : sizeof( struct V_130 ) ) -
sizeof( struct V_131 ) ;
V_89 -> V_132 = V_89 -> V_127 ;
if ( F_98 ( V_126 ) )
V_89 -> V_127 -= F_99 ( V_133 , 4 ) ;
if ( V_89 -> V_127 < 128 )
V_89 -> V_127 = 128 ;
if ( V_89 -> V_127 & 7 )
F_9 ( L_15 ,
F_97 ( V_126 ) , V_89 -> V_132 , V_89 -> V_127 ) ;
F_22 ( L_16 , V_37 , F_97 ( V_126 ) ,
V_89 -> V_132 , V_89 -> V_127 ) ;
}
static void F_100 ( struct V_88 * V_89 )
{
struct V_102 * V_103 ;
F_88 ( & V_89 -> V_109 ) ;
F_88 ( & V_89 -> V_134 ) ;
F_88 ( & V_89 -> V_135 ) ;
F_88 ( & V_89 -> V_136 ) ;
F_88 ( & V_89 -> V_116 ) ;
while ( ( V_103 = F_101 ( V_89 ) ) )
F_83 ( V_103 ) ;
F_102 ( V_89 -> V_137 ) ;
}
void F_103 ( struct V_31 * V_31 )
{
struct V_88 * V_89 ;
struct V_8 * V_9 ;
V_89 = F_20 ( V_31 , struct V_88 , V_31 ) ;
F_22 ( L_17 , V_37 , V_89 , V_89 -> V_34 . V_84 ) ;
if ( V_89 -> V_34 . V_35 . V_67 == V_69 ) {
struct V_32 * V_33 = (struct V_32 * )
& V_89 -> V_34 . V_35 ;
F_29 ( V_89 -> V_34 . V_9 -> V_16 . V_38 [ 0 ] ,
( const T_2 * )
& V_33 -> V_42 . V_44 , 1 ) ;
}
F_104 ( V_89 -> V_34 . V_9 -> V_16 . V_72 , 0 , V_89 -> V_10 ) ;
F_105 ( V_89 -> V_138 ) ;
F_106 ( V_89 -> V_117 ) ;
V_9 = V_89 -> V_34 . V_9 ;
F_65 ( & V_9 -> V_139 . V_119 ) ;
F_107 ( & V_89 -> V_140 ) ;
F_66 ( & V_9 -> V_139 . V_119 ) ;
F_100 ( V_89 ) ;
F_108 ( V_9 ) ;
F_18 ( V_89 ) ;
}
static void F_109 ( struct V_88 * V_89 , struct V_141 * V_142 )
{
unsigned int V_143 ;
T_1 V_144 ;
V_143 = V_142 -> V_145 . V_146 ;
V_144 = V_143 / V_147 ;
#define F_110 (256 * 1024)
V_89 -> V_148 = F_110 ;
if ( V_144 )
V_89 -> V_148 *= V_144 ;
#define F_111 (256 * 1024)
V_89 -> V_149 = F_111 ;
if ( V_144 )
V_89 -> V_149 *= V_144 ;
F_22 ( L_18 ,
V_37 , V_89 -> V_149 , V_89 -> V_148 ) ;
}
static T_1 F_112 ( struct V_52 * V_53 )
{
return V_53 -> V_150 -> V_151 ( V_53 ) ;
}
static int F_113 ( int V_152 )
{
if ( ! V_152 )
return 0 ;
return ( F_114 ( V_152 ) - 1 ) ;
}
static T_1 F_115 ( struct V_52 * V_53 , T_4 V_153 )
{
int V_3 ;
T_1 V_154 ;
struct V_155 V_156 = {
. V_157 = V_153
} ;
V_3 = ( int ) V_53 -> V_150 -> V_158 ( V_53 , V_159 , & V_154 ) ;
if ( V_3 )
return 0 ;
if ( V_154 & V_160 ) {
V_156 . V_161 = V_162 ;
V_3 = F_116 ( V_53 , & V_156 ) ;
} else if ( V_154 & V_163 ) {
V_156 . V_161 = V_164 ;
V_3 = F_117 ( V_53 , & V_156 ) ;
}
F_9 ( L_19 , F_113 ( V_3 ) ) ;
return F_113 ( V_3 ) ;
}
static int
F_118 ( struct V_88 * V_89 , int V_165 , T_5 * V_166 ,
T_4 V_153 , struct V_167 * V_138 ,
struct V_8 * V_9 )
{
struct V_168 * V_169 ;
int V_3 , V_170 ;
struct V_52 * V_53 ;
T_4 V_171 , V_54 ;
#ifdef F_119
T_1 V_172 = 0 ;
#endif
V_169 = F_120 ( V_138 , V_166 ) ;
if ( ! V_169 )
return - V_94 ;
F_45 () ;
V_3 = - V_45 ;
if ( V_169 -> V_173 -> V_13 & V_174 ) {
if ( V_165 == 4 )
V_53 = F_38 ( * ( T_3 * ) V_166 ) ;
else if ( F_41 ( V_64 ) )
V_53 = F_40 ( (struct V_41 * ) V_166 ) ;
else
V_53 = NULL ;
if ( ! V_53 ) {
V_3 = - V_94 ;
goto V_14;
}
V_89 -> V_117 = F_121 ( V_9 -> V_16 . V_117 ,
V_169 , V_53 , 0 ) ;
if ( ! V_89 -> V_117 )
goto V_14;
V_89 -> V_175 = V_53 -> V_175 ;
V_89 -> V_176 = F_122 ( V_53 ) ;
V_89 -> V_177 = ( F_123 ( V_53 ) & 0x7F ) << 1 ;
V_170 = V_9 -> V_16 . V_178 /
V_9 -> V_16 . V_179 ;
V_89 -> V_107 = F_124 ( V_53 ) * V_170 ;
V_170 = V_9 -> V_16 . V_180 /
V_9 -> V_16 . V_179 ;
V_89 -> V_181 = F_124 ( V_53 ) ;
V_89 -> V_182 = V_9 -> V_16 . V_47 [
F_124 ( V_53 ) * V_170 ] ;
V_89 -> V_54 = F_124 ( V_53 ) ;
F_109 ( V_89 ,
(struct V_141 * ) F_125 ( V_53 ) ) ;
} else {
V_53 = F_35 ( V_169 -> V_173 ) ;
if ( ! V_53 ) {
V_3 = - V_94 ;
goto V_14;
}
#ifdef F_119
if ( F_112 ( V_53 ) )
V_172 = F_115 ( V_53 ,
V_153 ) ;
V_89 -> V_183 = V_172 ;
V_89 -> V_117 = F_121 ( V_9 -> V_16 . V_117 , V_169 , V_53 , V_172 ) ;
#else
V_89 -> V_117 = F_121 ( V_9 -> V_16 . V_117 , V_169 , V_53 , 0 ) ;
#endif
if ( ! V_89 -> V_117 )
goto V_14;
V_54 = F_124 ( V_53 ) ;
V_89 -> V_175 = F_126 ( V_138 ) ;
V_89 -> V_176 = F_122 ( V_53 ) ;
V_89 -> V_177 = ( F_123 ( V_53 ) & 0x7F ) << 1 ;
V_170 = V_9 -> V_16 . V_178 /
V_9 -> V_16 . V_57 ;
V_89 -> V_107 = ( V_54 * V_170 ) +
( V_9 -> V_184 [ V_54 ] [ 0 ] ++ % V_170 ) ;
V_89 -> V_181 = F_124 ( V_53 ) ;
V_170 = V_9 -> V_16 . V_180 /
V_9 -> V_16 . V_57 ;
V_171 = ( V_54 * V_170 ) +
( V_9 -> V_184 [ V_54 ] [ 1 ] ++ % V_170 ) ;
V_89 -> V_182 = V_9 -> V_16 . V_47 [ V_171 ] ;
V_89 -> V_54 = V_54 ;
F_109 ( V_89 ,
(struct V_141 * ) F_125 ( V_53 ) ) ;
}
V_3 = 0 ;
V_14:
F_46 () ;
F_127 ( V_169 ) ;
return V_3 ;
}
int F_86 ( struct V_8 * V_9 , struct V_102 * V_103 )
{
int V_3 = 0 ;
if ( ! F_7 ( V_12 , & V_9 -> V_13 ) ) {
F_83 ( V_103 ) ;
F_4 ( L_20 , V_37 ) ;
return - V_7 ;
}
V_3 = F_128 ( V_9 -> V_16 . V_38 [ 0 ] , V_103 ) ;
if ( V_3 < 0 )
F_83 ( V_103 ) ;
return V_3 < 0 ? V_3 : 0 ;
}
static void F_129 ( struct V_8 * V_9 , T_2 V_10 )
{
T_2 V_104 = F_76 ( sizeof( struct V_185 ) , 16 ) ;
struct V_102 * V_103 ;
V_103 = F_77 ( V_104 , V_106 ) ;
if ( ! V_103 )
return;
F_130 ( V_103 , V_104 , V_10 , 0 ) ;
F_86 ( V_9 , V_103 ) ;
}
int
F_93 ( struct V_8 * V_9 , struct V_102 * V_103 ,
struct V_186 * V_187 )
{
int V_3 = 0 ;
if ( ! F_7 ( V_12 , & V_9 -> V_13 ) ) {
F_83 ( V_103 ) ;
F_4 ( L_20 , V_37 ) ;
return - V_7 ;
}
V_3 = F_131 ( V_9 -> V_16 . V_38 [ 0 ] , V_103 , V_187 ) ;
if ( V_3 < 0 )
F_83 ( V_103 ) ;
return V_3 < 0 ? V_3 : 0 ;
}
static void F_132 ( struct V_88 * V_89 , struct V_102 * V_103 )
{
if ( V_89 -> V_34 . V_84 != V_120 ) {
F_102 ( V_103 ) ;
return;
}
F_86 ( V_89 -> V_34 . V_9 , V_103 ) ;
}
int F_133 ( struct V_88 * V_89 )
{
struct V_102 * V_103 ;
T_2 V_104 = F_76 ( sizeof( struct V_188 ) , 16 ) ;
T_2 V_189 ;
V_103 = F_77 ( V_104 , V_25 ) ;
if ( ! V_103 )
return - 1 ;
V_189 = V_190 | F_134 ( 1 ) |
F_135 ( V_89 -> V_191 ) ;
F_136 ( V_103 , V_104 , V_89 -> V_10 , V_89 -> V_181 ,
V_189 ) ;
V_89 -> V_191 = 0 ;
F_65 ( & V_89 -> V_119 ) ;
if ( V_89 -> V_192 ) {
F_137 ( V_103 ) = F_132 ;
F_80 ( & V_89 -> V_135 , V_103 ) ;
F_66 ( & V_89 -> V_119 ) ;
return 0 ;
}
F_132 ( V_89 , V_103 ) ;
F_66 ( & V_89 -> V_119 ) ;
return 0 ;
}
static int F_138 ( struct V_88 * V_89 )
{
struct V_102 * V_103 ;
T_2 V_104 , V_193 ;
T_1 V_55 ;
V_193 = F_139 ( struct V_194 ,
V_195 [ V_196 ] ) ;
V_104 = F_140 ( T_2 , sizeof( struct V_111 ) ,
sizeof( struct V_197 ) ) ;
V_104 = F_141 ( V_104 , V_193 ) ;
V_104 = F_76 ( V_104 , 16 ) ;
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ ) {
V_103 = F_77 ( V_104 , V_106 ) ;
if ( ! V_103 )
goto V_14;
F_80 ( & V_89 -> V_116 , V_103 ) ;
}
V_103 = F_77 ( V_198 , V_106 ) ;
if ( ! V_103 )
goto V_14;
memset ( V_103 -> V_199 , 0 , V_198 ) ;
V_89 -> V_137 = V_103 ;
return 0 ;
V_14:
F_88 ( & V_89 -> V_116 ) ;
return - V_45 ;
}
static void
F_142 ( struct V_88 * V_89 , struct V_200 * V_112 )
{
struct V_102 * V_103 ;
const struct V_131 * V_201 ;
struct V_202 * V_203 ;
unsigned int V_104 = F_76 ( sizeof( * V_203 ) , 16 ) ;
unsigned int V_204 ;
T_6 V_205 ;
T_2 V_206 , V_207 ;
T_2 V_208 ;
T_2 V_209 ;
F_22 ( L_21 , V_37 , V_89 , V_89 -> V_10 ) ;
V_103 = F_77 ( V_104 , V_106 ) ;
if ( ! V_103 ) {
F_95 ( V_89 ) ;
return;
}
V_203 = (struct V_202 * ) F_143 ( V_103 , V_104 ) ;
memset ( V_203 , 0 , V_104 ) ;
F_144 ( V_203 , V_89 -> V_10 ) ;
F_145 ( V_203 ) = F_146 ( F_147 ( V_210 ,
V_89 -> V_10 ) ) ;
F_148 ( V_89 -> V_34 . V_9 -> V_16 . V_128 , V_89 -> V_175 , & V_204 ,
V_112 -> V_211 . V_212 ,
( V_89 -> V_34 . V_92 . V_67 == V_68 ) ? 0 : 1 ) ;
V_208 = F_149 ( V_89 -> V_148 ) ;
V_209 = V_89 -> V_148 >> 10 ;
if ( V_209 > V_213 )
V_209 = V_213 ;
V_205 = V_214 |
F_150 ( V_208 ) |
F_151 ( V_204 ) |
F_152 ( V_89 -> V_117 -> V_215 ) |
F_153 ( V_89 -> V_176 ) |
F_154 ( V_89 -> V_177 ) |
F_155 ( V_89 -> V_216 >> 2 ) |
F_156 ( V_217 ) |
F_157 ( V_209 ) ;
V_206 = F_158 ( 0 ) |
V_218 | F_159 ( V_89 -> V_182 ) ;
if ( V_112 -> V_211 . V_212 )
V_206 |= V_219 ;
if ( V_112 -> V_211 . V_220 )
V_206 |= V_221 ;
if ( V_208 )
V_206 |= V_222 ;
V_207 = F_160 ( V_112 -> V_223 ) ;
V_201 = ( const void * ) ( V_112 + 1 ) + F_161 ( V_207 ) +
F_162 ( V_207 ) ;
if ( V_201 -> V_224 && V_201 -> V_225 )
V_206 |= F_163 ( 1 ) ;
V_206 |= F_164 ( 3 ) ;
V_206 |= F_165 ( V_226 ) ;
V_206 |= V_227 ;
V_203 -> V_228 = F_146 ( ( F_166 () & ~ 7UL ) - 1 ) ;
V_206 |= V_229 ;
V_203 -> V_205 = F_167 ( V_205 ) ;
V_203 -> V_206 = F_146 ( V_206 ) ;
F_168 ( V_103 , V_230 , V_89 -> V_181 ) ;
F_169 ( V_103 , NULL , F_82 ) ;
F_93 ( V_89 -> V_34 . V_9 , V_103 , V_89 -> V_117 ) ;
}
static void
F_170 ( struct V_8 * V_9 , struct V_102 * V_103 )
{
struct V_88 * V_89 = NULL ;
struct V_19 * V_20 ;
struct V_200 * V_112 = F_85 ( V_103 ) ;
unsigned int V_23 = F_171 ( F_160 ( V_112 -> V_231 ) ) ;
struct V_232 * V_233 = V_9 -> V_16 . V_72 ;
unsigned int V_10 = F_172 ( V_112 ) ;
T_4 V_234 = F_30 ( V_112 -> V_211 . V_132 ) ;
unsigned short V_235 ;
struct V_167 * V_138 ;
T_5 V_236 [ 16 ] , V_166 [ 16 ] ;
T_7 V_153 , V_237 ;
int V_3 ;
int V_165 ;
F_22 ( L_22 ,
V_37 , V_9 , V_23 , V_10 ) ;
V_20 = F_173 ( V_233 , V_23 ) ;
if ( ! V_20 ) {
F_4 ( L_23 ,
V_37 , V_23 ) ;
goto V_238;
}
if ( V_20 -> V_34 . V_84 != V_85 ) {
F_4 ( L_24 ,
V_37 ) ;
goto V_239;
}
V_89 = F_174 ( V_233 , V_10 ) ;
if ( V_89 ) {
F_4 ( L_25 ,
V_37 , V_10 ) ;
goto V_238;
}
F_175 ( V_112 , V_9 -> V_16 . V_240 , & V_165 , V_236 ,
V_166 , & V_153 , & V_237 ) ;
if ( V_165 == 4 ) {
F_22 ( L_26
L_27
, V_37 , V_20 , V_10 ,
V_236 , V_166 , F_30 ( V_153 ) ,
F_30 ( V_237 ) , V_234 ) ;
V_138 = F_176 ( & V_9 -> V_16 , F_35 ,
* ( T_3 * ) V_236 ,
* ( T_3 * ) V_166 ,
V_153 , V_237 ,
F_177 ( F_160 ( V_112 -> V_231 ) ) ) ;
} else {
F_22 ( L_28
L_27
, V_37 , V_20 , V_10 ,
V_236 , V_166 , F_30 ( V_153 ) ,
F_30 ( V_237 ) , V_234 ) ;
V_138 = F_178 ( & V_9 -> V_16 , F_35 ,
V_236 , V_166 ,
V_153 , V_237 ,
F_177 ( F_160 ( V_112 -> V_231 ) ) ,
( (struct V_32 * )
& V_20 -> V_34 . V_35 ) -> V_241 ) ;
}
if ( ! V_138 ) {
F_4 ( L_29 ,
V_37 ) ;
goto V_239;
}
V_89 = F_13 ( sizeof( * V_89 ) , V_106 ) ;
if ( ! V_89 ) {
F_105 ( V_138 ) ;
goto V_238;
}
V_3 = F_118 ( V_89 , V_165 , V_166 , F_30 ( V_153 ) ,
V_138 , V_9 ) ;
if ( V_3 ) {
F_4 ( L_30 ,
V_37 ) ;
F_105 ( V_138 ) ;
F_18 ( V_89 ) ;
goto V_239;
}
F_61 ( & V_89 -> V_31 ) ;
F_58 ( & V_89 -> V_34 . V_46 . V_4 ) ;
F_59 ( & V_89 -> V_98 ) ;
V_235 = ( V_165 == 4 ? sizeof( struct V_129 ) : sizeof( struct V_130 ) ) +
sizeof( struct V_131 ) + ( V_112 -> V_211 . V_212 ? 12 : 0 ) ;
if ( V_234 && V_89 -> V_175 > ( V_234 + V_235 ) )
V_89 -> V_175 = V_234 + V_235 ;
V_89 -> V_34 . V_84 = V_242 ;
V_89 -> V_34 . V_9 = V_9 ;
V_89 -> V_20 = V_20 ;
V_89 -> V_216 = F_177 ( F_160 ( V_112 -> V_231 ) ) ;
V_89 -> V_138 = V_138 ;
V_89 -> V_10 = V_10 ;
V_89 -> V_243 = V_9 -> V_16 . V_243 -
F_179 ( sizeof( struct V_111 ) , 16 ) ;
V_89 -> V_244 = V_89 -> V_243 ;
V_89 -> V_245 = 0 ;
if ( V_165 == 4 ) {
struct V_48 * sin = (struct V_48 * )
& V_89 -> V_34 . V_35 ;
sin -> V_246 = V_68 ;
sin -> V_49 = V_153 ;
sin -> V_50 . V_51 = * ( T_3 * ) V_236 ;
sin = (struct V_48 * ) & V_89 -> V_34 . V_92 ;
sin -> V_246 = V_68 ;
sin -> V_49 = V_237 ;
sin -> V_50 . V_51 = * ( T_3 * ) V_166 ;
} else {
struct V_32 * V_33 = (struct V_32 * )
& V_89 -> V_34 . V_35 ;
V_33 -> V_247 = V_248 ;
V_33 -> V_40 = V_153 ;
memcpy ( V_33 -> V_42 . V_44 , V_236 , 16 ) ;
F_24 ( V_9 -> V_16 . V_38 [ 0 ] ,
( const T_2 * ) & V_33 -> V_42 . V_44 ,
1 ) ;
V_33 = (struct V_32 * ) & V_89 -> V_34 . V_92 ;
V_33 -> V_247 = V_248 ;
V_33 -> V_40 = V_237 ;
memcpy ( V_33 -> V_42 . V_44 , V_166 , 16 ) ;
}
F_180 ( & V_89 -> V_134 ) ;
F_180 ( & V_89 -> V_109 ) ;
F_180 ( & V_89 -> V_136 ) ;
F_180 ( & V_89 -> V_135 ) ;
F_180 ( & V_89 -> V_116 ) ;
F_181 ( V_89 ) ;
F_60 ( & V_89 -> V_119 ) ;
F_57 ( & V_89 -> V_249 ) ;
F_57 ( & V_89 -> V_250 ) ;
V_89 -> V_192 = false ;
if ( F_138 ( V_89 ) ) {
F_105 ( V_138 ) ;
F_18 ( V_89 ) ;
goto V_238;
}
F_182 ( V_9 ) ;
F_14 ( & V_9 -> V_139 . V_119 ) ;
F_183 ( & V_89 -> V_140 , & V_9 -> V_139 . V_140 ) ;
F_15 ( & V_9 -> V_139 . V_119 ) ;
F_184 ( V_233 , V_89 , V_10 ) ;
F_142 ( V_89 , V_112 ) ;
goto V_238;
V_239:
F_129 ( V_9 , V_10 ) ;
V_238:
F_102 ( V_103 ) ;
}
static T_2
F_185 ( struct V_88 * V_89 , T_2 * V_251 ,
T_2 * V_252 )
{
T_2 V_253 , V_254 , V_193 ;
V_253 = V_255 ;
if ( V_89 -> V_256 )
V_253 ++ ;
#ifdef F_119
V_253 ++ ;
#endif
V_193 = F_139 ( struct V_194 , V_195 [ V_253 ] ) ;
V_254 = F_179 ( V_193 , 16 ) ;
V_193 = V_254 * 16 ;
if ( V_251 )
* V_251 = V_253 ;
if ( V_252 )
* V_252 = V_193 ;
return V_254 ;
}
T_2 F_90 ( struct V_88 * V_89 )
{
struct V_8 * V_9 = V_89 -> V_34 . V_9 ;
struct V_194 * V_257 ;
T_2 V_253 , V_254 , V_193 ;
struct V_102 * V_103 ;
T_1 V_258 ;
#ifdef F_119
T_4 V_259 = ( (struct V_186 * ) V_89 -> V_117 ) -> V_259 ;
#endif
V_254 = F_185 ( V_89 , & V_253 , & V_193 ) ;
V_103 = F_91 ( & V_89 -> V_116 ) ;
V_257 = (struct V_194 * ) F_143 ( V_103 , V_193 ) ;
memset ( V_257 , 0 , V_193 ) ;
V_257 -> V_260 = F_146 ( F_186 ( V_261 ) |
F_187 ( V_253 ) ) ;
V_257 -> V_262 = F_146 ( F_188 ( V_254 ) |
F_189 ( V_89 -> V_10 ) ) ;
V_257 -> V_195 [ 0 ] . V_263 = V_264 ;
V_257 -> V_195 [ 0 ] . V_265 = F_146 ( F_190
( V_89 -> V_34 . V_9 -> V_16 . V_266 ) ) ;
V_257 -> V_195 [ 1 ] . V_263 = V_267 ;
V_257 -> V_195 [ 1 ] . V_265 = F_146 ( V_89 -> V_176 ) ;
V_257 -> V_195 [ 2 ] . V_263 = V_268 ;
V_257 -> V_195 [ 2 ] . V_265 = F_146 ( V_89 -> V_176 ) ;
V_257 -> V_195 [ 3 ] . V_263 = V_269 ;
V_257 -> V_195 [ 3 ] . V_265 = F_146 ( V_89 -> V_182 ) ;
V_257 -> V_195 [ 4 ] . V_263 = V_270 ;
V_257 -> V_195 [ 4 ] . V_265 = F_146 ( V_89 -> V_271 ) ;
V_257 -> V_195 [ 5 ] . V_263 = V_272 ;
V_257 -> V_195 [ 5 ] . V_265 = F_146 ( V_89 -> V_273 ) ;
V_257 -> V_195 [ 6 ] . V_263 = V_274 ;
V_257 -> V_195 [ 6 ] . V_265 = F_146 ( V_89 -> V_149 ) ;
V_257 -> V_195 [ 7 ] . V_263 = V_275 ;
V_257 -> V_195 [ 7 ] . V_265 = F_146 ( V_89 -> V_127 ) ;
V_257 -> V_195 [ 8 ] . V_263 = V_276 ;
if ( F_7 ( V_277 , & V_9 -> V_13 ) )
V_257 -> V_195 [ 8 ] . V_265 = F_146 ( V_278 ) ;
else
V_257 -> V_195 [ 8 ] . V_265 = F_146 ( 16384 ) ;
V_258 = 9 ;
if ( V_89 -> V_256 ) {
V_257 -> V_195 [ V_258 ] . V_263 = V_279 ;
V_257 -> V_195 [ V_258 ] . V_265 = F_146 ( V_89 -> V_256 ) ;
V_258 ++ ;
}
#ifdef F_119
V_257 -> V_195 [ V_258 ] . V_263 = V_280 ;
if ( V_259 == V_281 ) {
F_191 ( L_31 , V_89 -> V_10 ) ;
V_257 -> V_195 [ V_258 ] . V_265 = F_146 ( 0 ) ;
} else
V_257 -> V_195 [ V_258 ] . V_265 = F_146 (
( V_259 & V_282 ) >> V_283 ) ;
#endif
F_22 ( L_32
L_33 ,
V_37 , V_89 , V_89 -> V_176 , V_89 -> V_182 , V_89 -> V_271 ,
V_89 -> V_273 , V_89 -> V_149 , V_89 -> V_127 ) ;
F_168 ( V_103 , V_284 , V_89 -> V_107 ) ;
F_86 ( V_89 -> V_34 . V_9 , V_103 ) ;
return V_254 ;
}
int F_192 ( struct V_88 * V_89 )
{
struct V_102 * V_103 ;
struct V_285 * V_112 ;
T_1 V_286 = V_89 -> V_287 & V_288 ;
T_1 V_289 = V_89 -> V_287 & V_290 ;
unsigned int V_104 = F_76 ( sizeof( * V_112 ) , 16 ) ;
int V_3 ;
V_103 = F_77 ( V_104 , V_25 ) ;
if ( ! V_103 )
return - V_45 ;
V_112 = (struct V_285 * ) F_143 ( V_103 , V_104 ) ;
memset ( V_112 , 0 , V_104 ) ;
F_144 ( V_112 , V_89 -> V_10 ) ;
F_145 ( V_112 ) = F_48 ( F_147 ( V_291 , V_89 -> V_10 ) ) ;
V_112 -> V_292 = F_193 ( F_194 ( 0 ) | F_195 ( V_89 -> V_182 ) ) ;
V_112 -> V_293 = F_193 ( 0 ) ;
V_112 -> V_294 = F_167 ( 0x3 << 4 ) ;
V_112 -> V_265 = F_167 ( ( ( V_286 ? V_295 : 0 ) |
( V_289 ? V_296 : 0 ) ) << 4 ) ;
F_168 ( V_103 , V_297 , V_89 -> V_181 ) ;
F_196 ( V_89 ) ;
F_1 ( & V_89 -> V_34 . V_46 ) ;
F_86 ( V_89 -> V_34 . V_9 , V_103 ) ;
V_3 = F_6 ( V_89 -> V_34 . V_9 ,
& V_89 -> V_34 . V_46 ,
V_89 -> V_10 , 5 , V_37 ) ;
if ( V_3 )
return - 1 ;
return 0 ;
}
int F_197 ( struct V_88 * V_89 , T_2 V_298 )
{
struct V_102 * V_103 ;
struct V_285 * V_112 ;
unsigned int V_104 = F_76 ( sizeof( * V_112 ) , 16 ) ;
int V_3 ;
V_103 = F_77 ( V_104 , V_25 ) ;
if ( ! V_103 )
return - V_45 ;
V_112 = (struct V_285 * ) F_143 ( V_103 , V_104 ) ;
memset ( V_112 , 0 , V_104 ) ;
F_144 ( V_112 , V_89 -> V_10 ) ;
F_145 ( V_112 ) = F_48 ( F_147 ( V_291 , V_89 -> V_10 ) ) ;
V_112 -> V_292 = F_193 ( F_194 ( 0 ) | F_195 ( V_89 -> V_182 ) ) ;
V_112 -> V_293 = F_193 ( 0 ) ;
V_112 -> V_294 = F_167 ( 0x3 << 8 ) ;
V_112 -> V_265 = F_167 ( V_298 << 8 ) ;
F_168 ( V_103 , V_297 , V_89 -> V_181 ) ;
F_196 ( V_89 ) ;
F_1 ( & V_89 -> V_34 . V_46 ) ;
F_86 ( V_89 -> V_34 . V_9 , V_103 ) ;
V_3 = F_6 ( V_89 -> V_34 . V_9 ,
& V_89 -> V_34 . V_46 ,
V_89 -> V_10 , 5 , V_37 ) ;
if ( V_3 )
return - 1 ;
return 0 ;
}
static void
F_198 ( struct V_8 * V_9 , struct V_102 * V_103 )
{
struct V_299 * V_300 = F_85 ( V_103 ) ;
struct V_232 * V_233 = V_9 -> V_16 . V_72 ;
unsigned int V_23 = F_172 ( V_300 ) ;
struct V_19 * V_20 = F_173 ( V_233 , V_23 ) ;
F_22 ( L_34 ,
V_37 , V_20 , V_23 , V_300 -> V_301 ) ;
if ( ! V_20 ) {
F_9 ( L_35 , V_37 , V_23 ) ;
return;
}
F_3 ( & V_20 -> V_34 . V_46 , V_37 , V_300 -> V_301 ) ;
F_28 ( V_20 ) ;
}
static void
F_199 ( struct V_8 * V_9 , struct V_102 * V_103 )
{
struct V_302 * V_300 = F_85 ( V_103 ) ;
struct V_232 * V_233 = V_9 -> V_16 . V_72 ;
unsigned int V_23 = F_172 ( V_300 ) ;
struct V_19 * V_20 = F_173 ( V_233 , V_23 ) ;
F_22 ( L_34 ,
V_37 , V_20 , V_23 , V_300 -> V_301 ) ;
if ( ! V_20 ) {
F_9 ( L_35 , V_37 , V_23 ) ;
return;
}
F_3 ( & V_20 -> V_34 . V_46 , V_37 , V_300 -> V_301 ) ;
F_28 ( V_20 ) ;
}
static void
F_200 ( struct V_8 * V_9 , struct V_102 * V_103 )
{
struct V_303 * V_112 = F_85 ( V_103 ) ;
struct V_232 * V_233 = V_9 -> V_16 . V_72 ;
unsigned int V_10 = F_172 ( V_112 ) ;
struct V_88 * V_89 ;
struct V_19 * V_20 ;
T_4 V_304 = F_201 ( V_112 -> V_304 ) ;
T_2 V_305 = F_202 ( V_112 -> V_305 ) ;
T_2 V_306 = F_202 ( V_112 -> V_306 ) ;
V_89 = F_174 ( V_233 , V_10 ) ;
if ( F_203 ( ! V_89 ) ) {
F_4 ( L_36 , V_10 ) ;
goto V_238;
}
V_20 = V_89 -> V_20 ;
F_22 ( L_37 ,
V_37 , V_89 , V_10 , V_20 ) ;
V_89 -> V_307 = V_305 ;
V_89 -> V_308 = V_305 ;
V_89 -> V_271 = V_305 ;
V_89 -> V_273 = V_306 ;
if ( V_89 -> V_148 > ( V_213 << 10 ) )
V_89 -> V_191 = ( V_89 -> V_148 - ( V_213 << 10 ) ) ;
V_89 -> V_256 = F_204 ( V_304 ) ;
F_96 ( V_89 , V_304 ) ;
F_205 ( V_89 -> V_138 ) ;
V_89 -> V_34 . V_84 = V_120 ;
F_65 ( & V_20 -> V_81 ) ;
F_183 ( & V_89 -> V_98 , & V_20 -> V_80 ) ;
F_66 ( & V_20 -> V_81 ) ;
F_5 ( & V_20 -> V_79 ) ;
V_238:
F_102 ( V_103 ) ;
}
static void F_206 ( struct V_88 * V_89 , struct V_102 * V_103 )
{
F_79 ( V_103 ) = 0 ;
F_65 ( & V_89 -> V_134 . V_119 ) ;
F_80 ( & V_89 -> V_134 , V_103 ) ;
F_66 ( & V_89 -> V_134 . V_119 ) ;
F_207 ( & V_89 -> V_249 ) ;
}
static void F_208 ( struct V_88 * V_89 , struct V_102 * V_103 )
{
F_22 ( L_38 ,
V_37 , V_89 , V_89 -> V_10 , V_89 -> V_34 . V_84 ) ;
switch ( V_89 -> V_34 . V_84 ) {
case V_120 :
V_89 -> V_34 . V_84 = V_123 ;
F_206 ( V_89 , V_103 ) ;
return;
case V_123 :
V_89 -> V_34 . V_84 = V_125 ;
break;
case V_125 :
V_89 -> V_34 . V_84 = V_101 ;
F_95 ( V_89 ) ;
break;
case V_124 :
break;
default:
F_9 ( L_39 ,
V_37 , V_89 -> V_34 . V_84 ) ;
}
F_102 ( V_103 ) ;
}
static void F_209 ( struct V_88 * V_89 , struct V_102 * V_103 )
{
F_22 ( L_38 ,
V_37 , V_89 , V_89 -> V_10 , V_89 -> V_34 . V_84 ) ;
switch ( V_89 -> V_34 . V_84 ) {
case V_123 :
V_89 -> V_34 . V_84 = V_125 ;
break;
case V_125 :
V_89 -> V_34 . V_84 = V_101 ;
F_95 ( V_89 ) ;
break;
case V_124 :
case V_101 :
break;
default:
F_9 ( L_40 ,
V_37 , V_89 -> V_34 . V_84 ) ;
}
F_102 ( V_103 ) ;
}
static void F_210 ( struct V_88 * V_89 , struct V_102 * V_103 )
{
struct V_309 * V_310 = F_85 ( V_103 ) ;
unsigned int V_10 = F_172 ( V_310 ) ;
struct V_102 * V_311 ;
bool V_118 = false ;
bool V_312 = false ;
T_2 V_104 = F_76 ( sizeof( struct V_197 ) , 16 ) ;
F_22 ( L_38 ,
V_37 , V_89 , V_10 , V_89 -> V_34 . V_84 ) ;
if ( F_211 ( V_310 -> V_301 ) ) {
F_4 ( L_41 ,
V_37 , V_310 -> V_301 , V_10 ) ;
goto V_238;
}
switch ( V_89 -> V_34 . V_84 ) {
case V_242 :
case V_125 :
V_89 -> V_34 . V_84 = V_101 ;
V_118 = true ;
break;
case V_120 :
V_89 -> V_34 . V_84 = V_101 ;
V_312 = true ;
break;
case V_123 :
V_89 -> V_34 . V_84 = V_101 ;
if ( ! V_89 -> V_87 )
V_118 = true ;
break;
case V_124 :
break;
default:
F_9 ( L_42 ,
V_37 , V_89 -> V_34 . V_84 ) ;
V_89 -> V_34 . V_84 = V_101 ;
}
F_88 ( & V_89 -> V_109 ) ;
if ( ! F_89 ( V_115 , & V_89 -> V_34 . V_13 ) )
F_90 ( V_89 ) ;
V_311 = F_91 ( & V_89 -> V_116 ) ;
F_212 ( V_311 , V_104 , V_89 -> V_10 , V_89 -> V_107 ) ;
F_86 ( V_89 -> V_34 . V_9 , V_311 ) ;
if ( V_312 ) {
F_206 ( V_89 , V_103 ) ;
return;
}
if ( V_118 )
F_95 ( V_89 ) ;
V_238:
F_102 ( V_103 ) ;
}
static void F_213 ( struct V_88 * V_89 , struct V_102 * V_103 )
{
F_22 ( L_38 ,
V_37 , V_89 , V_89 -> V_10 , V_89 -> V_34 . V_84 ) ;
switch ( V_89 -> V_34 . V_84 ) {
case V_124 :
V_89 -> V_34 . V_84 = V_101 ;
F_95 ( V_89 ) ;
break;
default:
F_9 ( L_43 ,
V_37 , V_89 -> V_34 . V_84 ) ;
}
F_102 ( V_103 ) ;
}
static bool F_214 ( const struct V_88 * V_89 )
{
const struct V_102 * V_103 = V_89 -> V_313 ;
T_2 V_314 = 0 ;
if ( F_203 ( V_89 -> V_243 > V_89 -> V_244 ) ) {
F_4 ( L_44 ,
V_89 , V_89 -> V_10 , V_89 -> V_243 , V_89 -> V_244 ) ;
return true ;
}
while ( V_103 ) {
V_314 += V_103 -> V_315 ;
V_103 = F_215 ( V_103 ) ;
}
if ( F_203 ( ( V_89 -> V_243 + V_314 ) != V_89 -> V_244 ) ) {
F_4 ( L_45 ,
V_89 , V_89 -> V_10 , V_89 -> V_243 ,
V_314 , V_89 -> V_244 ) ;
return true ;
}
return false ;
}
static void F_216 ( struct V_88 * V_89 , struct V_102 * V_103 )
{
struct V_316 * V_300 = (struct V_316 * ) F_85 ( V_103 ) ;
T_2 V_317 = V_300 -> V_317 ;
T_2 V_308 = F_160 ( V_300 -> V_308 ) ;
V_89 -> V_243 += V_317 ;
if ( V_89 -> V_245 > ( V_89 -> V_244 - V_89 -> V_243 ) )
V_89 -> V_245 = V_89 -> V_244 - V_89 -> V_243 ;
while ( V_317 ) {
struct V_102 * V_24 = F_217 ( V_89 ) ;
if ( F_203 ( ! V_24 ) ) {
F_4 ( L_46 ,
V_89 , V_89 -> V_10 , V_317 ,
V_89 -> V_243 , V_89 -> V_245 ) ;
break;
}
if ( F_203 ( V_317 < V_24 -> V_315 ) ) {
F_191 ( L_47 ,
V_89 , V_89 -> V_10 ,
V_317 , V_89 -> V_243 , V_89 -> V_245 ,
V_24 -> V_315 ) ;
V_24 -> V_315 -= V_317 ;
break;
}
F_101 ( V_89 ) ;
V_317 -= V_24 -> V_315 ;
F_83 ( V_24 ) ;
}
if ( F_203 ( F_214 ( V_89 ) ) ) {
F_206 ( V_89 , V_103 ) ;
return;
}
if ( V_300 -> V_318 & V_319 ) {
if ( F_203 ( F_218 ( V_308 , V_89 -> V_308 ) ) ) {
F_191 ( L_48 ,
V_89 , V_89 -> V_10 , V_308 ,
V_89 -> V_308 ) ;
goto V_238;
}
if ( V_89 -> V_308 != V_308 ) {
V_89 -> V_308 = V_308 ;
F_205 ( V_89 -> V_138 ) ;
F_207 ( & V_89 -> V_250 ) ;
}
}
if ( F_219 ( & V_89 -> V_109 ) )
F_81 ( V_89 ) ;
V_238:
F_102 ( V_103 ) ;
}
static void F_220 ( struct V_8 * V_9 , struct V_102 * V_103 )
{
struct V_88 * V_89 ;
struct V_320 * V_300 = (struct V_320 * ) V_103 -> V_199 ;
unsigned int V_10 = F_172 ( V_300 ) ;
struct V_56 * V_16 = & V_9 -> V_16 ;
struct V_232 * V_233 = V_16 -> V_72 ;
V_89 = F_174 ( V_233 , V_10 ) ;
if ( F_203 ( ! V_89 ) )
F_4 ( L_36 , V_10 ) ;
else
F_3 ( & V_89 -> V_34 . V_46 , V_37 , V_300 -> V_301 ) ;
F_95 ( V_89 ) ;
}
static void F_221 ( struct V_8 * V_9 , struct V_102 * V_103 )
{
struct V_88 * V_89 ;
struct V_321 * V_322 = F_85 ( V_103 ) ;
unsigned int V_10 = F_172 ( V_322 ) ;
struct V_56 * V_16 = & V_9 -> V_16 ;
struct V_232 * V_233 = V_16 -> V_72 ;
V_89 = F_174 ( V_233 , V_10 ) ;
if ( F_203 ( ! V_89 ) ) {
F_4 ( L_49 , V_10 ) ;
goto V_238;
}
F_206 ( V_89 , V_103 ) ;
return;
V_238:
F_102 ( V_103 ) ;
}
static void
F_222 ( struct V_88 * V_89 , struct V_102 * V_103 )
{
F_14 ( & V_89 -> V_119 ) ;
if ( V_89 -> V_192 ) {
F_80 ( & V_89 -> V_135 , V_103 ) ;
F_15 ( & V_89 -> V_119 ) ;
return;
}
F_137 (V_103)( V_89 , V_103 );
F_15 ( & V_89 -> V_119 ) ;
}
static void F_223 ( struct V_88 * V_89 , struct V_102 * V_103 )
{
F_196 ( V_89 ) ;
F_222 ( V_89 , V_103 ) ;
F_95 ( V_89 ) ;
}
static void F_224 ( struct V_8 * V_9 , struct V_102 * V_103 )
{
struct V_88 * V_89 ;
struct V_323 * V_322 = F_85 ( V_103 ) ;
struct V_56 * V_16 = & V_9 -> V_16 ;
struct V_232 * V_233 = V_16 -> V_72 ;
unsigned int V_10 = F_172 ( V_322 ) ;
T_1 V_324 = F_225 ( V_103 ) ;
bool V_325 = true ;
switch ( V_324 ) {
case V_326 :
F_137 ( V_103 ) = F_216 ;
V_325 = false ;
break;
case V_327 :
F_137 ( V_103 ) = F_208 ;
break;
case V_328 :
F_137 ( V_103 ) = F_209 ;
break;
case V_329 :
F_137 ( V_103 ) = F_210 ;
break;
case V_330 :
F_137 ( V_103 ) = F_213 ;
break;
default:
goto V_238;
}
V_89 = F_174 ( V_233 , V_10 ) ;
if ( F_203 ( ! V_89 ) ) {
F_4 ( L_49 , V_10 ) ;
goto V_238;
}
if ( V_325 )
F_223 ( V_89 , V_103 ) ;
else
F_222 ( V_89 , V_103 ) ;
return;
V_238:
F_102 ( V_103 ) ;
}
