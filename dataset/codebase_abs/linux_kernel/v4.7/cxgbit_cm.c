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
static int F_11 ( unsigned int V_19 )
{
return V_19 == V_20 ||
V_19 == V_21 ||
V_19 == V_22 ;
}
static int F_12 ( const struct V_23 * V_24 )
{
return ( ( unsigned long ) V_24 >> 10 ) & ( V_25 - 1 ) ;
}
static struct V_26 *
F_13 ( struct V_8 * V_9 , struct V_23 * V_24 ,
unsigned int V_27 )
{
struct V_26 * V_28 = F_14 ( sizeof( * V_28 ) , V_29 ) ;
if ( V_28 ) {
int V_30 = F_12 ( V_24 ) ;
V_28 -> V_24 = V_24 ;
V_28 -> V_27 = V_27 ;
F_15 ( & V_9 -> V_31 ) ;
V_28 -> V_32 = V_9 -> V_33 [ V_30 ] ;
V_9 -> V_33 [ V_30 ] = V_28 ;
F_16 ( & V_9 -> V_31 ) ;
}
return V_28 ;
}
static int
F_17 ( struct V_8 * V_9 , struct V_23 * V_24 )
{
int V_27 = - 1 , V_30 = F_12 ( V_24 ) ;
struct V_26 * V_28 ;
F_15 ( & V_9 -> V_31 ) ;
for ( V_28 = V_9 -> V_33 [ V_30 ] ; V_28 ; V_28 = V_28 -> V_32 ) {
if ( V_28 -> V_24 == V_24 ) {
V_27 = V_28 -> V_27 ;
break;
}
}
F_16 ( & V_9 -> V_31 ) ;
return V_27 ;
}
static int F_18 ( struct V_8 * V_9 , struct V_23 * V_24 )
{
int V_27 = - 1 , V_30 = F_12 ( V_24 ) ;
struct V_26 * V_28 , * * V_34 = & V_9 -> V_33 [ V_30 ] ;
F_15 ( & V_9 -> V_31 ) ;
for ( V_28 = * V_34 ; V_28 ; V_34 = & V_28 -> V_32 , V_28 = V_28 -> V_32 ) {
if ( V_28 -> V_24 == V_24 ) {
V_27 = V_28 -> V_27 ;
* V_34 = V_28 -> V_32 ;
F_19 ( V_28 ) ;
break;
}
}
F_16 ( & V_9 -> V_31 ) ;
return V_27 ;
}
void F_20 ( struct V_35 * V_35 )
{
struct V_23 * V_24 ;
V_24 = F_21 ( V_35 , struct V_23 , V_35 ) ;
F_19 ( V_24 ) ;
}
static int
F_22 ( struct V_8 * V_9 , unsigned int V_27 ,
struct V_23 * V_24 )
{
struct V_36 * V_37 = (struct V_36 * )
& V_24 -> V_38 . V_39 ;
int V_40 ;
int V_3 ;
F_23 ( L_4 ,
V_41 , V_9 -> V_16 . V_42 [ 0 ] -> V_43 , V_27 , V_37 -> V_44 ) ;
V_40 = F_24 ( ( const struct V_45 * )
& V_37 -> V_46 ) ;
if ( V_40 != V_47 ) {
V_3 = F_25 ( V_9 -> V_16 . V_42 [ 0 ] ,
( const T_2 * ) & V_37 -> V_46 . V_48 , 1 ) ;
if ( V_3 ) {
F_4 ( L_5 ,
V_37 -> V_46 . V_48 , V_3 ) ;
return - V_49 ;
}
}
F_26 ( V_24 ) ;
F_1 ( & V_24 -> V_38 . V_50 ) ;
V_3 = F_27 ( V_9 -> V_16 . V_42 [ 0 ] ,
V_27 , & V_37 -> V_46 ,
V_37 -> V_44 ,
V_9 -> V_16 . V_51 [ 0 ] ) ;
if ( ! V_3 )
V_3 = F_6 ( V_9 , & V_24 -> V_38 . V_50 ,
0 , 10 , V_41 ) ;
else if ( V_3 > 0 )
V_3 = F_28 ( V_3 ) ;
else
F_29 ( V_24 ) ;
if ( V_3 ) {
if ( V_3 != - V_18 )
F_30 ( V_9 -> V_16 . V_42 [ 0 ] ,
( const T_2 * ) & V_37 -> V_46 . V_48 , 1 ) ;
F_4 ( L_6 ,
V_3 , V_27 , V_37 -> V_46 . V_48 ,
F_31 ( V_37 -> V_44 ) ) ;
}
return V_3 ;
}
static int
F_32 ( struct V_8 * V_9 , unsigned int V_27 ,
struct V_23 * V_24 )
{
struct V_52 * sin = (struct V_52 * )
& V_24 -> V_38 . V_39 ;
int V_3 ;
F_23 ( L_7 ,
V_41 , V_9 -> V_16 . V_42 [ 0 ] -> V_43 , V_27 , sin -> V_53 ) ;
F_26 ( V_24 ) ;
F_1 ( & V_24 -> V_38 . V_50 ) ;
V_3 = F_33 ( V_9 -> V_16 . V_42 [ 0 ] ,
V_27 , sin -> V_54 . V_55 ,
sin -> V_53 , 0 ,
V_9 -> V_16 . V_51 [ 0 ] ) ;
if ( ! V_3 )
V_3 = F_6 ( V_9 ,
& V_24 -> V_38 . V_50 ,
0 , 10 , V_41 ) ;
else if ( V_3 > 0 )
V_3 = F_28 ( V_3 ) ;
else
F_29 ( V_24 ) ;
if ( V_3 )
F_4 ( L_8 ,
V_3 , V_27 , & sin -> V_54 , F_31 ( sin -> V_53 ) ) ;
return V_3 ;
}
struct V_8 * F_34 ( struct V_56 * V_57 , T_1 * V_58 )
{
struct V_8 * V_9 ;
T_1 V_59 ;
F_35 (cdev, &cdev_list_head, list) {
struct V_60 * V_16 = & V_9 -> V_16 ;
for ( V_59 = 0 ; V_59 < V_16 -> V_61 ; V_59 ++ ) {
if ( V_16 -> V_42 [ V_59 ] == V_57 ) {
if ( V_58 )
* V_58 = V_59 ;
return V_9 ;
}
}
}
return NULL ;
}
static struct V_56 * F_36 ( struct V_56 * V_57 )
{
if ( V_57 -> V_62 & V_63 ) {
F_4 ( L_9 ,
V_57 -> V_43 ) ;
return NULL ;
}
if ( F_37 ( V_57 ) )
return F_38 ( V_57 ) ;
return V_57 ;
}
static struct V_56 * F_39 ( T_3 V_64 )
{
struct V_56 * V_57 ;
V_57 = F_40 ( & V_65 , V_64 , false ) ;
if ( ! V_57 )
return NULL ;
return F_36 ( V_57 ) ;
}
static struct V_56 * F_41 ( struct V_45 * V_66 )
{
struct V_56 * V_57 = NULL ;
bool V_67 = false ;
if ( F_42 ( V_68 ) ) {
F_43 (&init_net, ndev)
if ( F_44 ( & V_65 , V_66 , V_57 , 1 ) ) {
V_67 = true ;
break;
}
}
if ( ! V_67 )
return NULL ;
return F_36 ( V_57 ) ;
}
static struct V_8 * F_45 ( struct V_23 * V_24 )
{
struct V_69 * V_70 = & V_24 -> V_38 . V_39 ;
int V_71 = V_70 -> V_71 ;
struct V_56 * V_57 = NULL ;
struct V_8 * V_9 = NULL ;
F_46 () ;
if ( V_71 == V_72 ) {
struct V_52 * sin ;
sin = (struct V_52 * ) V_70 ;
V_57 = F_39 ( sin -> V_54 . V_55 ) ;
} else if ( V_71 == V_73 ) {
struct V_36 * V_37 ;
V_37 = (struct V_36 * ) V_70 ;
V_57 = F_41 ( & V_37 -> V_46 ) ;
}
if ( ! V_57 )
goto V_14;
V_9 = F_34 ( V_57 , NULL ) ;
V_14:
F_47 () ;
return V_9 ;
}
static bool F_48 ( struct V_23 * V_24 )
{
struct V_69 * V_70 = & V_24 -> V_38 . V_39 ;
int V_71 = V_70 -> V_71 ;
int V_40 ;
if ( V_71 == V_72 ) {
struct V_52 * sin ;
sin = (struct V_52 * ) V_70 ;
if ( sin -> V_54 . V_55 == F_49 ( V_74 ) )
return true ;
} else if ( V_71 == V_73 ) {
struct V_36 * V_37 ;
V_37 = (struct V_36 * ) V_70 ;
V_40 = F_24 ( ( const struct V_45 * )
& V_37 -> V_46 ) ;
if ( V_40 == V_47 )
return true ;
}
return false ;
}
static int
F_50 ( struct V_8 * V_9 , struct V_23 * V_24 )
{
int V_27 , V_3 ;
int V_71 = V_24 -> V_38 . V_39 . V_71 ;
if ( ! F_7 ( V_12 , & V_9 -> V_13 ) )
return - V_75 ;
V_27 = F_51 ( V_9 -> V_16 . V_76 , V_71 , V_24 ) ;
if ( V_27 < 0 )
return - V_75 ;
if ( ! F_13 ( V_9 , V_24 , V_27 ) ) {
F_52 ( V_9 -> V_16 . V_76 , V_27 , V_71 ) ;
return - V_75 ;
}
if ( V_71 == V_72 )
V_3 = F_32 ( V_9 , V_27 , V_24 ) ;
else
V_3 = F_22 ( V_9 , V_27 , V_24 ) ;
if ( V_3 ) {
if ( V_3 != - V_18 )
F_52 ( V_9 -> V_16 . V_76 , V_27 ,
V_71 ) ;
F_18 ( V_9 , V_24 ) ;
return V_3 ;
}
return V_3 ;
}
static int F_53 ( struct V_23 * V_24 )
{
struct V_8 * V_9 ;
int V_3 = - 1 ;
F_54 ( & V_77 ) ;
V_9 = F_45 ( V_24 ) ;
if ( ! V_9 )
goto V_14;
if ( F_17 ( V_9 , V_24 ) >= 0 )
goto V_14;
if ( F_50 ( V_9 , V_24 ) )
goto V_14;
V_24 -> V_38 . V_9 = V_9 ;
V_3 = 0 ;
V_14:
F_55 ( & V_77 ) ;
return V_3 ;
}
static int F_56 ( struct V_23 * V_24 )
{
struct V_8 * V_9 ;
int V_3 ;
T_2 V_78 = 0 ;
F_54 ( & V_77 ) ;
F_35 (cdev, &cdev_list_head, list) {
if ( F_17 ( V_9 , V_24 ) >= 0 ) {
F_55 ( & V_77 ) ;
return - 1 ;
}
}
F_35 (cdev, &cdev_list_head, list) {
V_3 = F_50 ( V_9 , V_24 ) ;
if ( V_3 == - V_18 )
break;
if ( V_3 != 0 )
continue;
V_78 ++ ;
}
F_55 ( & V_77 ) ;
return V_78 ? 0 : - 1 ;
}
int F_57 ( struct V_79 * V_80 , struct V_69 * V_81 )
{
struct V_23 * V_24 ;
int V_3 ;
if ( ( V_81 -> V_71 != V_72 ) &&
( V_81 -> V_71 != V_73 ) )
return - V_75 ;
V_24 = F_14 ( sizeof( * V_24 ) , V_29 ) ;
if ( ! V_24 )
return - V_49 ;
F_58 ( & V_24 -> V_82 ) ;
F_59 ( & V_24 -> V_38 . V_50 . V_4 ) ;
F_59 ( & V_24 -> V_83 ) ;
F_60 ( & V_24 -> V_84 ) ;
F_61 ( & V_24 -> V_85 ) ;
F_62 ( & V_24 -> V_35 ) ;
memcpy ( & V_80 -> V_86 , V_81 ,
sizeof( struct V_69 ) ) ;
memcpy ( & V_24 -> V_38 . V_39 , & V_80 -> V_86 ,
sizeof( V_24 -> V_38 . V_39 ) ) ;
V_24 -> V_80 = V_80 ;
V_24 -> V_38 . V_9 = NULL ;
if ( F_48 ( V_24 ) )
V_3 = F_56 ( V_24 ) ;
else
V_3 = F_53 ( V_24 ) ;
if ( V_3 ) {
F_29 ( V_24 ) ;
return - V_75 ;
}
V_80 -> V_87 = V_24 ;
V_24 -> V_38 . V_88 = V_89 ;
return 0 ;
}
static void
F_63 ( struct V_79 * V_80 , struct V_90 * V_91 ,
struct V_92 * V_93 )
{
V_91 -> V_94 = V_80 -> V_86 . V_71 ;
V_91 -> V_95 = V_93 -> V_38 . V_96 ;
V_91 -> V_97 = V_93 -> V_38 . V_39 ;
}
int F_64 ( struct V_79 * V_80 , struct V_90 * V_91 )
{
struct V_23 * V_24 = V_80 -> V_87 ;
struct V_92 * V_93 ;
int V_3 = 0 ;
V_82:
V_3 = F_65 ( & V_24 -> V_83 ) ;
if ( V_3 )
return - V_98 ;
F_66 ( & V_80 -> V_99 ) ;
if ( V_80 -> V_100 >= V_101 ) {
F_67 ( & V_80 -> V_99 ) ;
return - V_98 ;
}
F_67 ( & V_80 -> V_99 ) ;
F_66 ( & V_24 -> V_85 ) ;
if ( F_68 ( & V_24 -> V_84 ) ) {
F_67 ( & V_24 -> V_85 ) ;
goto V_82;
}
V_93 = F_69 ( & V_24 -> V_84 ,
struct V_92 ,
V_102 ) ;
F_70 ( & V_93 -> V_102 ) ;
F_67 ( & V_24 -> V_85 ) ;
V_91 -> V_103 = V_93 ;
V_93 -> V_91 = V_91 ;
F_63 ( V_80 , V_91 , V_93 ) ;
return 0 ;
}
static int
F_71 ( struct V_8 * V_9 , struct V_23 * V_24 )
{
int V_27 , V_3 ;
bool V_104 = false ;
V_27 = F_18 ( V_9 , V_24 ) ;
if ( V_27 < 0 )
return - V_75 ;
if ( ! F_7 ( V_12 , & V_9 -> V_13 ) )
return - V_75 ;
if ( V_24 -> V_80 -> V_86 . V_71 == V_73 )
V_104 = true ;
F_26 ( V_24 ) ;
F_1 ( & V_24 -> V_38 . V_50 ) ;
V_3 = F_72 ( V_9 -> V_16 . V_42 [ 0 ] , V_27 ,
V_9 -> V_16 . V_51 [ 0 ] , V_104 ) ;
if ( V_3 > 0 )
V_3 = F_28 ( V_3 ) ;
if ( V_3 ) {
F_29 ( V_24 ) ;
return V_3 ;
}
V_3 = F_6 ( V_9 , & V_24 -> V_38 . V_50 ,
0 , 10 , V_41 ) ;
if ( V_3 == - V_18 )
return V_3 ;
if ( V_104 && V_24 -> V_38 . V_9 ) {
struct V_36 * V_37 ;
V_37 = (struct V_36 * ) & V_24 -> V_38 . V_39 ;
F_30 ( V_9 -> V_16 . V_42 [ 0 ] ,
( const T_2 * ) & V_37 -> V_46 . V_48 ,
1 ) ;
}
F_52 ( V_9 -> V_16 . V_76 , V_27 ,
V_24 -> V_38 . V_39 . V_71 ) ;
return 0 ;
}
static void F_73 ( struct V_23 * V_24 )
{
struct V_8 * V_9 ;
int V_3 ;
F_54 ( & V_77 ) ;
F_35 (cdev, &cdev_list_head, list) {
V_3 = F_71 ( V_9 , V_24 ) ;
if ( V_3 == - V_18 )
break;
}
F_55 ( & V_77 ) ;
}
static void F_74 ( struct V_23 * V_24 )
{
struct V_8 * V_9 ;
bool V_67 = false ;
F_54 ( & V_77 ) ;
F_35 (cdev, &cdev_list_head, list) {
if ( V_9 == V_24 -> V_38 . V_9 ) {
V_67 = true ;
break;
}
}
if ( ! V_67 )
goto V_14;
F_71 ( V_9 , V_24 ) ;
V_14:
F_55 ( & V_77 ) ;
}
void F_75 ( struct V_79 * V_80 )
{
struct V_23 * V_24 = V_80 -> V_87 ;
V_24 -> V_38 . V_88 = V_105 ;
if ( V_24 -> V_38 . V_9 )
F_74 ( V_24 ) ;
else
F_73 ( V_24 ) ;
V_80 -> V_87 = NULL ;
F_29 ( V_24 ) ;
}
static void F_76 ( struct V_92 * V_93 )
{
struct V_106 * V_107 ;
struct V_108 * V_109 ;
unsigned int V_110 = F_77 ( sizeof( struct V_108 ) , 16 ) ;
V_107 = F_78 ( V_110 , V_111 ) ;
if ( ! V_107 )
return;
V_109 = (struct V_108 * ) F_79 ( V_107 , V_110 ) ;
memset ( V_109 , 0 , V_110 ) ;
F_80 ( V_107 , V_112 , V_93 -> V_113 ) ;
F_81 ( V_109 , V_93 -> V_10 ) ;
F_82 ( V_109 ) = F_83 ( F_84 ( V_114 ,
V_93 -> V_10 ) ) ;
V_109 -> V_115 = 0 ;
F_85 ( V_107 ) |= V_116 ;
F_86 ( & V_93 -> V_117 , V_107 ) ;
F_87 ( V_93 ) ;
}
static void F_88 ( void * V_118 , struct V_106 * V_107 )
{
F_23 ( L_10 , V_41 , V_118 ) ;
F_89 ( V_107 ) ;
}
static void F_90 ( void * V_118 , struct V_106 * V_107 )
{
struct V_8 * V_9 = V_118 ;
struct V_119 * V_109 = F_91 ( V_107 ) ;
F_23 ( L_11 , V_41 , V_9 ) ;
V_109 -> V_120 = V_121 ;
F_92 ( V_9 , V_107 ) ;
}
static int F_93 ( struct V_92 * V_93 )
{
struct V_119 * V_109 ;
unsigned int V_110 = F_77 ( sizeof( * V_109 ) , 16 ) ;
struct V_106 * V_107 ;
F_23 ( L_12 ,
V_41 , V_93 , V_93 -> V_10 , V_93 -> V_38 . V_88 ) ;
F_94 ( & V_93 -> V_117 ) ;
if ( ! F_95 ( V_122 , & V_93 -> V_38 . V_13 ) )
F_96 ( V_93 ) ;
V_107 = F_97 ( & V_93 -> V_123 ) ;
V_109 = (struct V_119 * ) F_79 ( V_107 , V_110 ) ;
memset ( V_109 , 0 , V_110 ) ;
F_80 ( V_107 , V_112 , V_93 -> V_113 ) ;
F_98 ( V_107 , V_93 -> V_38 . V_9 , F_90 ) ;
F_81 ( V_109 , V_93 -> V_10 ) ;
F_82 ( V_109 ) = F_83 ( F_84 ( V_124 ,
V_93 -> V_10 ) ) ;
V_109 -> V_120 = V_125 ;
return F_99 ( V_93 -> V_38 . V_9 , V_107 , V_93 -> V_126 ) ;
}
void F_100 ( struct V_90 * V_91 )
{
struct V_92 * V_93 = V_91 -> V_103 ;
bool V_127 = false ;
F_23 ( L_13 ,
V_41 , V_93 -> V_38 . V_88 ) ;
F_66 ( & V_93 -> V_128 ) ;
switch ( V_93 -> V_38 . V_88 ) {
case V_129 :
if ( V_91 -> V_130 == V_131 ) {
V_93 -> V_38 . V_88 = V_132 ;
F_76 ( V_93 ) ;
} else {
V_93 -> V_38 . V_88 = V_133 ;
F_93 ( V_93 ) ;
}
break;
case V_132 :
V_93 -> V_38 . V_88 = V_134 ;
F_76 ( V_93 ) ;
break;
case V_105 :
V_127 = true ;
break;
default:
F_4 ( L_14 ,
V_41 , V_93 , V_93 -> V_38 . V_88 ) ;
}
F_67 ( & V_93 -> V_128 ) ;
if ( V_127 )
F_101 ( V_93 ) ;
}
static void F_102 ( struct V_92 * V_93 , T_4 V_135 )
{
V_93 -> V_136 = V_93 -> V_38 . V_9 -> V_16 . V_137 [ F_103 ( V_135 ) ] -
( ( V_93 -> V_38 . V_96 . V_71 == V_72 ) ?
sizeof( struct V_138 ) : sizeof( struct V_139 ) ) -
sizeof( struct V_140 ) ;
V_93 -> V_141 = V_93 -> V_136 ;
if ( F_104 ( V_135 ) )
V_93 -> V_136 -= F_105 ( V_142 , 4 ) ;
if ( V_93 -> V_136 < 128 )
V_93 -> V_136 = 128 ;
if ( V_93 -> V_136 & 7 )
F_9 ( L_15 ,
F_103 ( V_135 ) , V_93 -> V_141 , V_93 -> V_136 ) ;
F_23 ( L_16 , V_41 , F_103 ( V_135 ) ,
V_93 -> V_141 , V_93 -> V_136 ) ;
}
static void F_106 ( struct V_92 * V_93 )
{
struct V_106 * V_107 ;
F_94 ( & V_93 -> V_117 ) ;
F_94 ( & V_93 -> V_143 ) ;
F_94 ( & V_93 -> V_144 ) ;
F_94 ( & V_93 -> V_145 ) ;
F_94 ( & V_93 -> V_123 ) ;
while ( ( V_107 = F_107 ( V_93 ) ) )
F_89 ( V_107 ) ;
F_108 ( V_93 -> V_146 ) ;
}
void F_109 ( struct V_35 * V_35 )
{
struct V_92 * V_93 ;
struct V_8 * V_9 ;
V_93 = F_21 ( V_35 , struct V_92 , V_35 ) ;
F_23 ( L_17 , V_41 , V_93 , V_93 -> V_38 . V_88 ) ;
if ( V_93 -> V_38 . V_39 . V_71 == V_73 ) {
struct V_36 * V_37 = (struct V_36 * )
& V_93 -> V_38 . V_39 ;
F_30 ( V_93 -> V_38 . V_9 -> V_16 . V_42 [ 0 ] ,
( const T_2 * )
& V_37 -> V_46 . V_48 , 1 ) ;
}
F_110 ( V_93 -> V_38 . V_9 -> V_16 . V_76 , 0 , V_93 -> V_10 ) ;
F_111 ( V_93 -> V_147 ) ;
F_112 ( V_93 -> V_126 ) ;
V_9 = V_93 -> V_38 . V_9 ;
F_66 ( & V_9 -> V_148 . V_128 ) ;
F_113 ( & V_93 -> V_149 ) ;
F_67 ( & V_9 -> V_148 . V_128 ) ;
F_106 ( V_93 ) ;
F_114 ( V_9 ) ;
F_19 ( V_93 ) ;
}
static void
F_115 ( struct V_150 * V_109 , int * V_151 ,
T_5 * V_152 , T_5 * V_153 , T_6 * V_154 ,
T_6 * V_155 )
{
T_2 V_156 = F_116 ( F_117 ( V_109 -> V_157 ) ) ;
T_2 V_158 = F_118 ( F_117 ( V_109 -> V_157 ) ) ;
struct V_138 * V_159 = (struct V_138 * ) ( ( T_1 * ) ( V_109 + 1 ) + V_156 ) ;
struct V_139 * V_160 = (struct V_139 * ) ( ( T_1 * ) ( V_109 + 1 ) + V_156 ) ;
struct V_140 * V_161 = (struct V_140 * )
( ( T_1 * ) ( V_109 + 1 ) + V_156 + V_158 ) ;
if ( V_159 -> V_162 == 4 ) {
F_23 ( L_18 ,
V_41 ,
F_119 ( V_159 -> V_64 ) , F_119 ( V_159 -> V_163 ) ,
F_31 ( V_161 -> V_164 ) ,
F_31 ( V_161 -> V_165 ) ) ;
* V_151 = 4 ;
memcpy ( V_153 , & V_159 -> V_64 , 4 ) ;
memcpy ( V_152 , & V_159 -> V_163 , 4 ) ;
} else {
F_23 ( L_19 ,
V_41 ,
V_160 -> V_64 . V_48 , V_160 -> V_163 . V_48 ,
F_31 ( V_161 -> V_164 ) ,
F_31 ( V_161 -> V_165 ) ) ;
* V_151 = 6 ;
memcpy ( V_153 , V_160 -> V_64 . V_48 , 16 ) ;
memcpy ( V_152 , V_160 -> V_163 . V_48 , 16 ) ;
}
* V_155 = V_161 -> V_164 ;
* V_154 = V_161 -> V_165 ;
}
static int
F_120 ( struct V_8 * V_9 , struct V_56 * V_166 )
{
T_1 V_59 ;
V_166 = F_36 ( V_166 ) ;
for ( V_59 = 0 ; V_59 < V_9 -> V_16 . V_61 ; V_59 ++ )
if ( V_9 -> V_16 . V_42 [ V_59 ] == V_166 )
return 1 ;
return 0 ;
}
static struct V_167 *
F_121 ( struct V_8 * V_9 , T_5 * V_152 , T_5 * V_153 ,
T_6 V_154 , T_6 V_155 , T_1 V_168 ,
T_7 V_169 )
{
struct V_167 * V_147 = NULL ;
if ( F_42 ( V_68 ) ) {
struct V_170 V_171 ;
memset ( & V_171 , 0 , sizeof( V_171 ) ) ;
memcpy ( & V_171 . V_163 , V_153 , 16 ) ;
memcpy ( & V_171 . V_64 , V_152 , 16 ) ;
if ( F_24 ( & V_171 . V_163 ) & V_172 )
V_171 . V_173 = V_169 ;
V_147 = F_122 ( & V_65 , NULL , & V_171 ) ;
if ( ! V_147 )
goto V_14;
if ( ! F_120 ( V_9 , F_123 ( V_147 ) -> V_174 ) &&
! ( F_123 ( V_147 ) -> V_174 -> V_13 & V_175 ) ) {
F_111 ( V_147 ) ;
V_147 = NULL ;
}
}
V_14:
return V_147 ;
}
static struct V_167 *
F_124 ( struct V_8 * V_9 , T_3 V_152 , T_3 V_153 ,
T_6 V_154 , T_6 V_155 , T_1 V_168 )
{
struct V_176 * V_177 ;
struct V_178 V_179 ;
struct V_180 * V_181 ;
V_177 = F_125 ( & V_65 , & V_179 , NULL , V_153 ,
V_152 ,
V_155 , V_154 , V_182 ,
V_168 , 0 ) ;
if ( F_126 ( V_177 ) )
return NULL ;
V_181 = F_127 ( & V_177 -> V_147 , & V_153 ) ;
if ( ! V_181 )
return NULL ;
if ( ! F_120 ( V_9 , V_181 -> V_174 ) &&
! ( V_181 -> V_174 -> V_13 & V_175 ) ) {
F_128 ( V_181 ) ;
F_111 ( & V_177 -> V_147 ) ;
return NULL ;
}
F_128 ( V_181 ) ;
return & V_177 -> V_147 ;
}
static void F_129 ( struct V_92 * V_93 , struct V_183 * V_184 )
{
unsigned int V_185 ;
T_1 V_186 ;
V_185 = V_184 -> V_187 . V_188 ;
V_186 = V_185 / V_189 ;
#define F_130 (256 * 1024)
V_93 -> V_190 = F_130 ;
if ( V_186 )
V_93 -> V_190 *= V_186 ;
#define F_131 (256 * 1024)
V_93 -> V_191 = F_131 ;
if ( V_186 )
V_93 -> V_191 *= V_186 ;
F_23 ( L_20 ,
V_41 , V_93 -> V_191 , V_93 -> V_190 ) ;
}
static T_1 F_132 ( struct V_56 * V_57 )
{
return V_57 -> V_192 -> V_193 ( V_57 ) ;
}
static int F_133 ( int V_194 )
{
if ( ! V_194 )
return 0 ;
return ( F_134 ( V_194 ) - 1 ) ;
}
static T_1 F_135 ( struct V_56 * V_57 , T_4 V_154 )
{
int V_3 ;
T_1 V_195 ;
struct V_196 V_197 = {
. V_198 = V_154
} ;
V_3 = ( int ) V_57 -> V_192 -> V_199 ( V_57 , V_200 , & V_195 ) ;
if ( V_3 )
return 0 ;
if ( V_195 & V_201 ) {
V_197 . V_202 = V_203 ;
V_3 = F_136 ( V_57 , & V_197 ) ;
} else if ( V_195 & V_204 ) {
V_197 . V_202 = V_205 ;
V_3 = F_137 ( V_57 , & V_197 ) ;
}
F_9 ( L_21 , F_133 ( V_3 ) ) ;
return F_133 ( V_3 ) ;
}
static int
F_138 ( struct V_92 * V_93 , int V_151 , T_5 * V_153 ,
T_4 V_154 , struct V_167 * V_147 ,
struct V_8 * V_9 )
{
struct V_180 * V_181 ;
int V_3 , V_206 ;
struct V_56 * V_57 ;
T_4 V_207 , V_58 ;
#ifdef F_139
T_1 V_208 = 0 ;
#endif
V_181 = F_127 ( V_147 , V_153 ) ;
if ( ! V_181 )
return - V_98 ;
F_46 () ;
V_3 = - V_49 ;
if ( V_181 -> V_174 -> V_13 & V_175 ) {
if ( V_151 == 4 )
V_57 = F_39 ( * ( T_3 * ) V_153 ) ;
else if ( F_42 ( V_68 ) )
V_57 = F_41 ( (struct V_45 * ) V_153 ) ;
else
V_57 = NULL ;
if ( ! V_57 ) {
V_3 = - V_98 ;
goto V_14;
}
V_93 -> V_126 = F_140 ( V_9 -> V_16 . V_126 ,
V_181 , V_57 , 0 ) ;
if ( ! V_93 -> V_126 )
goto V_14;
V_93 -> V_209 = V_57 -> V_209 ;
V_93 -> V_210 = F_141 ( V_57 ) ;
V_93 -> V_211 = ( F_142 ( V_57 ) & 0x7F ) << 1 ;
V_206 = V_9 -> V_16 . V_212 /
V_9 -> V_16 . V_213 ;
V_93 -> V_113 = F_143 ( V_57 ) * V_206 ;
V_206 = V_9 -> V_16 . V_214 /
V_9 -> V_16 . V_213 ;
V_93 -> V_215 = F_143 ( V_57 ) ;
V_93 -> V_216 = V_9 -> V_16 . V_51 [
F_143 ( V_57 ) * V_206 ] ;
V_93 -> V_58 = F_143 ( V_57 ) ;
F_129 ( V_93 ,
(struct V_183 * ) F_144 ( V_57 ) ) ;
} else {
V_57 = F_36 ( V_181 -> V_174 ) ;
if ( ! V_57 ) {
V_3 = - V_98 ;
goto V_14;
}
#ifdef F_139
if ( F_132 ( V_57 ) )
V_208 = F_135 ( V_57 ,
V_154 ) ;
V_93 -> V_217 = V_208 ;
V_93 -> V_126 = F_140 ( V_9 -> V_16 . V_126 , V_181 , V_57 , V_208 ) ;
#else
V_93 -> V_126 = F_140 ( V_9 -> V_16 . V_126 , V_181 , V_57 , 0 ) ;
#endif
if ( ! V_93 -> V_126 )
goto V_14;
V_58 = F_143 ( V_57 ) ;
V_93 -> V_209 = F_145 ( V_147 ) ;
V_93 -> V_210 = F_141 ( V_57 ) ;
V_93 -> V_211 = ( F_142 ( V_57 ) & 0x7F ) << 1 ;
V_206 = V_9 -> V_16 . V_212 /
V_9 -> V_16 . V_61 ;
V_93 -> V_113 = ( V_58 * V_206 ) +
( V_9 -> V_218 [ V_58 ] [ 0 ] ++ % V_206 ) ;
V_93 -> V_215 = F_143 ( V_57 ) ;
V_206 = V_9 -> V_16 . V_214 /
V_9 -> V_16 . V_61 ;
V_207 = ( V_58 * V_206 ) +
( V_9 -> V_218 [ V_58 ] [ 1 ] ++ % V_206 ) ;
V_93 -> V_216 = V_9 -> V_16 . V_51 [ V_207 ] ;
V_93 -> V_58 = V_58 ;
F_129 ( V_93 ,
(struct V_183 * ) F_144 ( V_57 ) ) ;
}
V_3 = 0 ;
V_14:
F_47 () ;
F_128 ( V_181 ) ;
return V_3 ;
}
int F_92 ( struct V_8 * V_9 , struct V_106 * V_107 )
{
int V_3 = 0 ;
if ( ! F_7 ( V_12 , & V_9 -> V_13 ) ) {
F_89 ( V_107 ) ;
F_4 ( L_22 , V_41 ) ;
return - V_7 ;
}
V_3 = F_146 ( V_9 -> V_16 . V_42 [ 0 ] , V_107 ) ;
if ( V_3 < 0 )
F_89 ( V_107 ) ;
return V_3 < 0 ? V_3 : 0 ;
}
static void F_147 ( struct V_8 * V_9 , T_2 V_10 )
{
struct V_219 * V_109 ;
unsigned int V_110 = F_77 ( sizeof( * V_109 ) , 16 ) ;
struct V_106 * V_107 ;
V_107 = F_78 ( V_110 , V_111 ) ;
if ( ! V_107 )
return;
V_109 = (struct V_219 * ) F_79 ( V_107 , V_110 ) ;
memset ( V_109 , 0 , V_110 ) ;
F_81 ( V_109 , V_10 ) ;
F_82 ( V_109 ) = F_83 ( F_84 (
V_220 , V_10 ) ) ;
F_80 ( V_107 , V_221 , 0 ) ;
F_92 ( V_9 , V_107 ) ;
}
int
F_99 ( struct V_8 * V_9 , struct V_106 * V_107 ,
struct V_222 * V_223 )
{
int V_3 = 0 ;
if ( ! F_7 ( V_12 , & V_9 -> V_13 ) ) {
F_89 ( V_107 ) ;
F_4 ( L_22 , V_41 ) ;
return - V_7 ;
}
V_3 = F_148 ( V_9 -> V_16 . V_42 [ 0 ] , V_107 , V_223 ) ;
if ( V_3 < 0 )
F_89 ( V_107 ) ;
return V_3 < 0 ? V_3 : 0 ;
}
static void
F_149 ( const unsigned short * V_137 , unsigned short V_209 ,
unsigned int * V_224 , int V_225 , int V_104 )
{
unsigned short V_226 = ( V_104 ? sizeof( struct V_139 ) :
sizeof( struct V_138 ) ) +
sizeof( struct V_140 ) +
( V_225 ? F_105 ( V_142 ,
4 ) : 0 ) ;
unsigned short V_227 = V_209 - V_226 ;
F_150 ( V_137 , V_226 , V_227 , 8 , V_224 ) ;
}
static void F_151 ( struct V_92 * V_93 , struct V_106 * V_107 )
{
if ( V_93 -> V_38 . V_88 != V_129 ) {
F_108 ( V_107 ) ;
return;
}
F_92 ( V_93 -> V_38 . V_9 , V_107 ) ;
}
int F_152 ( struct V_92 * V_93 )
{
struct V_106 * V_107 ;
struct V_228 * V_109 ;
unsigned int V_110 = F_77 ( sizeof( * V_109 ) , 16 ) ;
V_107 = F_78 ( V_110 , V_29 ) ;
if ( ! V_107 )
return - 1 ;
V_109 = (struct V_228 * ) F_79 ( V_107 , V_110 ) ;
memset ( V_109 , 0 , V_110 ) ;
F_80 ( V_107 , V_229 , V_93 -> V_215 ) ;
F_81 ( V_109 , V_93 -> V_10 ) ;
F_82 ( V_109 ) = F_83 ( F_84 ( V_230 ,
V_93 -> V_10 ) ) ;
V_109 -> V_231 = F_83 ( V_232 | F_153 ( 1 ) |
F_154 ( V_93 -> V_233 ) ) ;
V_93 -> V_233 = 0 ;
F_66 ( & V_93 -> V_128 ) ;
if ( V_93 -> V_234 ) {
F_155 ( V_107 ) = F_151 ;
F_86 ( & V_93 -> V_144 , V_107 ) ;
F_67 ( & V_93 -> V_128 ) ;
return 0 ;
}
F_151 ( V_93 , V_107 ) ;
F_67 ( & V_93 -> V_128 ) ;
return 0 ;
}
static int F_156 ( struct V_92 * V_93 )
{
struct V_106 * V_107 ;
T_2 V_110 , V_235 ;
T_1 V_59 ;
V_235 = F_157 ( struct V_236 ,
V_237 [ V_238 ] ) ;
V_110 = F_158 ( T_2 , sizeof( struct V_119 ) ,
sizeof( struct V_239 ) ) ;
V_110 = F_159 ( V_110 , V_235 ) ;
V_110 = F_77 ( V_110 , 16 ) ;
for ( V_59 = 0 ; V_59 < 3 ; V_59 ++ ) {
V_107 = F_78 ( V_110 , V_111 ) ;
if ( ! V_107 )
goto V_14;
F_86 ( & V_93 -> V_123 , V_107 ) ;
}
V_107 = F_78 ( V_240 , V_111 ) ;
if ( ! V_107 )
goto V_14;
memset ( V_107 -> V_241 , 0 , V_240 ) ;
V_93 -> V_146 = V_107 ;
return 0 ;
V_14:
F_94 ( & V_93 -> V_123 ) ;
return - V_49 ;
}
static T_2 F_160 ( T_2 V_242 )
{
T_2 V_243 = 0 ;
while ( V_243 < 14 && ( 65535 << V_243 ) < V_242 )
V_243 ++ ;
return V_243 ;
}
static void
F_161 ( struct V_92 * V_93 , struct V_150 * V_109 )
{
struct V_106 * V_107 ;
const struct V_140 * V_244 ;
struct V_245 * V_246 ;
unsigned int V_110 = F_77 ( sizeof( * V_246 ) , 16 ) ;
unsigned int V_247 ;
T_8 V_248 ;
T_2 V_249 , V_250 ;
T_2 V_243 ;
T_2 V_242 ;
F_23 ( L_23 , V_41 , V_93 , V_93 -> V_10 ) ;
V_107 = F_78 ( V_110 , V_111 ) ;
if ( ! V_107 ) {
F_101 ( V_93 ) ;
return;
}
V_246 = (struct V_245 * ) F_79 ( V_107 , V_110 ) ;
memset ( V_246 , 0 , V_110 ) ;
F_81 ( V_246 , V_93 -> V_10 ) ;
F_82 ( V_246 ) = F_83 ( F_84 ( V_251 ,
V_93 -> V_10 ) ) ;
F_149 ( V_93 -> V_38 . V_9 -> V_16 . V_137 , V_93 -> V_209 , & V_247 ,
V_109 -> V_252 . V_253 ,
( V_93 -> V_38 . V_96 . V_71 == V_72 ) ? 0 : 1 ) ;
V_243 = F_160 ( V_93 -> V_190 ) ;
V_242 = V_93 -> V_190 >> 10 ;
if ( V_242 > V_254 )
V_242 = V_254 ;
V_248 = V_255 |
F_162 ( V_243 ) |
F_163 ( V_247 ) |
F_164 ( V_93 -> V_126 -> V_224 ) |
F_165 ( V_93 -> V_210 ) |
F_166 ( V_93 -> V_211 ) |
F_167 ( V_93 -> V_168 >> 2 ) |
F_168 ( V_256 ) |
F_169 ( V_242 ) ;
V_249 = F_170 ( 0 ) |
V_257 | F_171 ( V_93 -> V_216 ) ;
if ( V_109 -> V_252 . V_253 )
V_249 |= V_258 ;
if ( V_109 -> V_252 . V_259 )
V_249 |= V_260 ;
if ( V_243 )
V_249 |= V_261 ;
V_250 = F_119 ( V_109 -> V_157 ) ;
V_244 = ( const void * ) ( V_109 + 1 ) + F_116 ( V_250 ) +
F_118 ( V_250 ) ;
if ( V_244 -> V_262 && V_244 -> V_263 )
V_249 |= F_172 ( 1 ) ;
V_249 |= F_173 ( 3 ) ;
V_249 |= F_174 ( V_264 ) ;
V_249 |= V_265 ;
V_246 -> V_266 = F_83 ( ( F_175 () & ~ 7UL ) - 1 ) ;
V_249 |= V_267 ;
V_246 -> V_248 = F_176 ( V_248 ) ;
V_246 -> V_249 = F_83 ( V_249 ) ;
F_80 ( V_107 , V_221 , V_93 -> V_215 ) ;
F_98 ( V_107 , NULL , F_88 ) ;
F_99 ( V_93 -> V_38 . V_9 , V_107 , V_93 -> V_126 ) ;
}
static void
F_177 ( struct V_8 * V_9 , struct V_106 * V_107 )
{
struct V_92 * V_93 = NULL ;
struct V_23 * V_24 ;
struct V_150 * V_109 = F_91 ( V_107 ) ;
unsigned int V_27 = F_178 ( F_119 ( V_109 -> V_268 ) ) ;
struct V_269 * V_270 = V_9 -> V_16 . V_76 ;
unsigned int V_10 = F_179 ( V_109 ) ;
T_4 V_271 = F_31 ( V_109 -> V_252 . V_141 ) ;
unsigned short V_272 ;
struct V_167 * V_147 ;
T_5 V_152 [ 16 ] , V_153 [ 16 ] ;
T_6 V_154 , V_155 ;
int V_3 ;
int V_151 ;
F_23 ( L_24 ,
V_41 , V_9 , V_27 , V_10 ) ;
V_24 = F_180 ( V_270 , V_27 ) ;
if ( ! V_24 ) {
F_4 ( L_25 ,
V_41 , V_27 ) ;
goto V_273;
}
if ( V_24 -> V_38 . V_88 != V_89 ) {
F_4 ( L_26 ,
V_41 ) ;
goto V_274;
}
V_93 = F_181 ( V_270 , V_10 ) ;
if ( V_93 ) {
F_4 ( L_27 ,
V_41 , V_10 ) ;
goto V_273;
}
F_115 ( V_109 , & V_151 , V_152 , V_153 ,
& V_154 , & V_155 ) ;
if ( V_151 == 4 ) {
F_23 ( L_28
L_29
, V_41 , V_24 , V_10 ,
V_152 , V_153 , F_31 ( V_154 ) ,
F_31 ( V_155 ) , V_271 ) ;
V_147 = F_124 ( V_9 , * ( T_3 * ) V_152 ,
* ( T_3 * ) V_153 ,
V_154 , V_155 ,
F_182 ( F_119 ( V_109 -> V_268 ) ) ) ;
} else {
F_23 ( L_30
L_29
, V_41 , V_24 , V_10 ,
V_152 , V_153 , F_31 ( V_154 ) ,
F_31 ( V_155 ) , V_271 ) ;
V_147 = F_121 ( V_9 , V_152 , V_153 ,
V_154 , V_155 ,
F_182 ( F_119 ( V_109 -> V_268 ) ) ,
( (struct V_36 * )
& V_24 -> V_38 . V_39 ) -> V_169 ) ;
}
if ( ! V_147 ) {
F_4 ( L_31 ,
V_41 ) ;
goto V_274;
}
V_93 = F_14 ( sizeof( * V_93 ) , V_111 ) ;
if ( ! V_93 ) {
F_111 ( V_147 ) ;
goto V_273;
}
V_3 = F_138 ( V_93 , V_151 , V_153 , F_31 ( V_154 ) ,
V_147 , V_9 ) ;
if ( V_3 ) {
F_4 ( L_32 ,
V_41 ) ;
F_111 ( V_147 ) ;
F_19 ( V_93 ) ;
goto V_274;
}
F_62 ( & V_93 -> V_35 ) ;
F_59 ( & V_93 -> V_38 . V_50 . V_4 ) ;
F_60 ( & V_93 -> V_102 ) ;
V_272 = ( V_151 == 4 ? sizeof( struct V_138 ) : sizeof( struct V_139 ) ) +
sizeof( struct V_140 ) + ( V_109 -> V_252 . V_253 ? 12 : 0 ) ;
if ( V_271 && V_93 -> V_209 > ( V_271 + V_272 ) )
V_93 -> V_209 = V_271 + V_272 ;
V_93 -> V_38 . V_88 = V_275 ;
V_93 -> V_38 . V_9 = V_9 ;
V_93 -> V_24 = V_24 ;
V_93 -> V_168 = F_182 ( F_119 ( V_109 -> V_268 ) ) ;
V_93 -> V_147 = V_147 ;
V_93 -> V_10 = V_10 ;
V_93 -> V_276 = V_9 -> V_16 . V_276 -
F_183 ( sizeof( struct V_119 ) , 16 ) ;
V_93 -> V_277 = V_93 -> V_276 ;
V_93 -> V_278 = 0 ;
if ( V_151 == 4 ) {
struct V_52 * sin = (struct V_52 * )
& V_93 -> V_38 . V_39 ;
sin -> V_279 = V_72 ;
sin -> V_53 = V_154 ;
sin -> V_54 . V_55 = * ( T_3 * ) V_152 ;
sin = (struct V_52 * ) & V_93 -> V_38 . V_96 ;
sin -> V_279 = V_72 ;
sin -> V_53 = V_155 ;
sin -> V_54 . V_55 = * ( T_3 * ) V_153 ;
} else {
struct V_36 * V_37 = (struct V_36 * )
& V_93 -> V_38 . V_39 ;
V_37 -> V_280 = V_281 ;
V_37 -> V_44 = V_154 ;
memcpy ( V_37 -> V_46 . V_48 , V_152 , 16 ) ;
F_25 ( V_9 -> V_16 . V_42 [ 0 ] ,
( const T_2 * ) & V_37 -> V_46 . V_48 ,
1 ) ;
V_37 = (struct V_36 * ) & V_93 -> V_38 . V_96 ;
V_37 -> V_280 = V_281 ;
V_37 -> V_44 = V_155 ;
memcpy ( V_37 -> V_46 . V_48 , V_153 , 16 ) ;
}
F_184 ( & V_93 -> V_143 ) ;
F_184 ( & V_93 -> V_117 ) ;
F_184 ( & V_93 -> V_145 ) ;
F_184 ( & V_93 -> V_144 ) ;
F_184 ( & V_93 -> V_123 ) ;
F_185 ( V_93 ) ;
F_61 ( & V_93 -> V_128 ) ;
F_58 ( & V_93 -> V_282 ) ;
F_58 ( & V_93 -> V_283 ) ;
V_93 -> V_234 = false ;
if ( F_156 ( V_93 ) ) {
F_111 ( V_147 ) ;
F_19 ( V_93 ) ;
goto V_273;
}
F_186 ( V_9 ) ;
F_15 ( & V_9 -> V_148 . V_128 ) ;
F_187 ( & V_93 -> V_149 , & V_9 -> V_148 . V_149 ) ;
F_16 ( & V_9 -> V_148 . V_128 ) ;
F_188 ( V_270 , V_93 , V_10 ) ;
F_161 ( V_93 , V_109 ) ;
goto V_273;
V_274:
F_147 ( V_9 , V_10 ) ;
V_273:
F_108 ( V_107 ) ;
}
static T_2
F_189 ( struct V_92 * V_93 , T_2 * V_284 ,
T_2 * V_285 )
{
T_2 V_286 , V_287 , V_235 ;
V_286 = V_288 ;
if ( V_93 -> V_289 )
V_286 ++ ;
#ifdef F_139
V_286 ++ ;
#endif
V_235 = F_157 ( struct V_236 , V_237 [ V_286 ] ) ;
V_287 = F_183 ( V_235 , 16 ) ;
V_235 = V_287 * 16 ;
if ( V_284 )
* V_284 = V_286 ;
if ( V_285 )
* V_285 = V_235 ;
return V_287 ;
}
T_2 F_96 ( struct V_92 * V_93 )
{
struct V_8 * V_9 = V_93 -> V_38 . V_9 ;
struct V_236 * V_290 ;
T_2 V_286 , V_287 , V_235 ;
struct V_106 * V_107 ;
T_1 V_291 ;
#ifdef F_139
T_4 V_292 = ( (struct V_222 * ) V_93 -> V_126 ) -> V_292 ;
#endif
V_287 = F_189 ( V_93 , & V_286 , & V_235 ) ;
V_107 = F_97 ( & V_93 -> V_123 ) ;
V_290 = (struct V_236 * ) F_79 ( V_107 , V_235 ) ;
memset ( V_290 , 0 , V_235 ) ;
V_290 -> V_293 = F_83 ( F_190 ( V_294 ) |
F_191 ( V_286 ) ) ;
V_290 -> V_295 = F_83 ( F_192 ( V_287 ) |
F_193 ( V_93 -> V_10 ) ) ;
V_290 -> V_237 [ 0 ] . V_296 = V_297 ;
V_290 -> V_237 [ 0 ] . V_298 = F_83 ( F_194
( V_93 -> V_38 . V_9 -> V_16 . V_299 ) ) ;
V_290 -> V_237 [ 1 ] . V_296 = V_300 ;
V_290 -> V_237 [ 1 ] . V_298 = F_83 ( V_93 -> V_210 ) ;
V_290 -> V_237 [ 2 ] . V_296 = V_301 ;
V_290 -> V_237 [ 2 ] . V_298 = F_83 ( V_93 -> V_210 ) ;
V_290 -> V_237 [ 3 ] . V_296 = V_302 ;
V_290 -> V_237 [ 3 ] . V_298 = F_83 ( V_93 -> V_216 ) ;
V_290 -> V_237 [ 4 ] . V_296 = V_303 ;
V_290 -> V_237 [ 4 ] . V_298 = F_83 ( V_93 -> V_304 ) ;
V_290 -> V_237 [ 5 ] . V_296 = V_305 ;
V_290 -> V_237 [ 5 ] . V_298 = F_83 ( V_93 -> V_306 ) ;
V_290 -> V_237 [ 6 ] . V_296 = V_307 ;
V_290 -> V_237 [ 6 ] . V_298 = F_83 ( V_93 -> V_191 ) ;
V_290 -> V_237 [ 7 ] . V_296 = V_308 ;
V_290 -> V_237 [ 7 ] . V_298 = F_83 ( V_93 -> V_136 ) ;
V_290 -> V_237 [ 8 ] . V_296 = V_309 ;
if ( F_7 ( V_310 , & V_9 -> V_13 ) )
V_290 -> V_237 [ 8 ] . V_298 = F_83 ( V_311 ) ;
else
V_290 -> V_237 [ 8 ] . V_298 = F_83 ( 16384 ) ;
V_291 = 9 ;
if ( V_93 -> V_289 ) {
V_290 -> V_237 [ V_291 ] . V_296 = V_312 ;
V_290 -> V_237 [ V_291 ] . V_298 = F_83 ( V_93 -> V_289 ) ;
V_291 ++ ;
}
#ifdef F_139
V_290 -> V_237 [ V_291 ] . V_296 = V_313 ;
if ( V_292 == V_314 ) {
F_195 ( L_33 , V_93 -> V_10 ) ;
V_290 -> V_237 [ V_291 ] . V_298 = F_83 ( 0 ) ;
} else
V_290 -> V_237 [ V_291 ] . V_298 = F_83 (
( V_292 & V_315 ) >> V_316 ) ;
#endif
F_23 ( L_34
L_35 ,
V_41 , V_93 , V_93 -> V_210 , V_93 -> V_216 , V_93 -> V_304 ,
V_93 -> V_306 , V_93 -> V_191 , V_93 -> V_136 ) ;
F_80 ( V_107 , V_112 , V_93 -> V_113 ) ;
F_92 ( V_93 -> V_38 . V_9 , V_107 ) ;
return V_287 ;
}
int F_196 ( struct V_92 * V_93 )
{
struct V_106 * V_107 ;
struct V_317 * V_109 ;
T_1 V_318 = V_93 -> V_319 & V_320 ;
T_1 V_321 = V_93 -> V_319 & V_322 ;
unsigned int V_110 = F_77 ( sizeof( * V_109 ) , 16 ) ;
int V_3 ;
V_107 = F_78 ( V_110 , V_29 ) ;
if ( ! V_107 )
return - V_49 ;
V_109 = (struct V_317 * ) F_79 ( V_107 , V_110 ) ;
memset ( V_109 , 0 , V_110 ) ;
F_81 ( V_109 , V_93 -> V_10 ) ;
F_82 ( V_109 ) = F_49 ( F_84 ( V_323 , V_93 -> V_10 ) ) ;
V_109 -> V_324 = F_197 ( F_198 ( 0 ) | F_199 ( V_93 -> V_216 ) ) ;
V_109 -> V_325 = F_197 ( 0 ) ;
V_109 -> V_326 = F_176 ( 0x3 << 4 ) ;
V_109 -> V_298 = F_176 ( ( ( V_318 ? V_327 : 0 ) |
( V_321 ? V_328 : 0 ) ) << 4 ) ;
F_80 ( V_107 , V_329 , V_93 -> V_215 ) ;
F_200 ( V_93 ) ;
F_1 ( & V_93 -> V_38 . V_50 ) ;
F_92 ( V_93 -> V_38 . V_9 , V_107 ) ;
V_3 = F_6 ( V_93 -> V_38 . V_9 ,
& V_93 -> V_38 . V_50 ,
V_93 -> V_10 , 5 , V_41 ) ;
if ( V_3 )
return - 1 ;
return 0 ;
}
int F_201 ( struct V_92 * V_93 , T_2 V_330 )
{
struct V_106 * V_107 ;
struct V_317 * V_109 ;
unsigned int V_110 = F_77 ( sizeof( * V_109 ) , 16 ) ;
int V_3 ;
V_107 = F_78 ( V_110 , V_29 ) ;
if ( ! V_107 )
return - V_49 ;
V_109 = (struct V_317 * ) F_79 ( V_107 , V_110 ) ;
memset ( V_109 , 0 , V_110 ) ;
F_81 ( V_109 , V_93 -> V_10 ) ;
F_82 ( V_109 ) = F_49 ( F_84 ( V_323 , V_93 -> V_10 ) ) ;
V_109 -> V_324 = F_197 ( F_198 ( 0 ) | F_199 ( V_93 -> V_216 ) ) ;
V_109 -> V_325 = F_197 ( 0 ) ;
V_109 -> V_326 = F_176 ( 0x3 << 8 ) ;
V_109 -> V_298 = F_176 ( V_330 << 8 ) ;
F_80 ( V_107 , V_329 , V_93 -> V_215 ) ;
F_200 ( V_93 ) ;
F_1 ( & V_93 -> V_38 . V_50 ) ;
F_92 ( V_93 -> V_38 . V_9 , V_107 ) ;
V_3 = F_6 ( V_93 -> V_38 . V_9 ,
& V_93 -> V_38 . V_50 ,
V_93 -> V_10 , 5 , V_41 ) ;
if ( V_3 )
return - 1 ;
return 0 ;
}
static void
F_202 ( struct V_8 * V_9 , struct V_106 * V_107 )
{
struct V_331 * V_332 = F_91 ( V_107 ) ;
struct V_269 * V_270 = V_9 -> V_16 . V_76 ;
unsigned int V_27 = F_179 ( V_332 ) ;
struct V_23 * V_24 = F_180 ( V_270 , V_27 ) ;
F_23 ( L_36 ,
V_41 , V_24 , V_27 , V_332 -> V_19 ) ;
if ( ! V_24 ) {
F_9 ( L_37 , V_41 , V_27 ) ;
return;
}
F_3 ( & V_24 -> V_38 . V_50 , V_41 , V_332 -> V_19 ) ;
F_29 ( V_24 ) ;
}
static void
F_203 ( struct V_8 * V_9 , struct V_106 * V_107 )
{
struct V_333 * V_332 = F_91 ( V_107 ) ;
struct V_269 * V_270 = V_9 -> V_16 . V_76 ;
unsigned int V_27 = F_179 ( V_332 ) ;
struct V_23 * V_24 = F_180 ( V_270 , V_27 ) ;
F_23 ( L_36 ,
V_41 , V_24 , V_27 , V_332 -> V_19 ) ;
if ( ! V_24 ) {
F_9 ( L_37 , V_41 , V_27 ) ;
return;
}
F_3 ( & V_24 -> V_38 . V_50 , V_41 , V_332 -> V_19 ) ;
F_29 ( V_24 ) ;
}
static void
F_204 ( struct V_8 * V_9 , struct V_106 * V_107 )
{
struct V_334 * V_109 = F_91 ( V_107 ) ;
struct V_269 * V_270 = V_9 -> V_16 . V_76 ;
unsigned int V_10 = F_179 ( V_109 ) ;
struct V_92 * V_93 ;
struct V_23 * V_24 ;
T_4 V_335 = F_205 ( V_109 -> V_335 ) ;
T_2 V_336 = F_117 ( V_109 -> V_336 ) ;
T_2 V_337 = F_117 ( V_109 -> V_337 ) ;
V_93 = F_181 ( V_270 , V_10 ) ;
if ( F_206 ( ! V_93 ) ) {
F_4 ( L_38 , V_10 ) ;
goto V_273;
}
V_24 = V_93 -> V_24 ;
F_23 ( L_39 ,
V_41 , V_93 , V_10 , V_24 ) ;
V_93 -> V_338 = V_336 ;
V_93 -> V_339 = V_336 ;
V_93 -> V_304 = V_336 ;
V_93 -> V_306 = V_337 ;
if ( V_93 -> V_190 > ( V_254 << 10 ) )
V_93 -> V_233 = ( V_93 -> V_190 - ( V_254 << 10 ) ) ;
V_93 -> V_289 = F_207 ( V_335 ) ;
F_102 ( V_93 , V_335 ) ;
F_208 ( V_93 -> V_147 ) ;
V_93 -> V_38 . V_88 = V_129 ;
F_66 ( & V_24 -> V_85 ) ;
F_187 ( & V_93 -> V_102 , & V_24 -> V_84 ) ;
F_67 ( & V_24 -> V_85 ) ;
F_5 ( & V_24 -> V_83 ) ;
V_273:
F_108 ( V_107 ) ;
}
static void F_209 ( struct V_92 * V_93 , struct V_106 * V_107 )
{
F_85 ( V_107 ) = 0 ;
F_66 ( & V_93 -> V_143 . V_128 ) ;
F_86 ( & V_93 -> V_143 , V_107 ) ;
F_67 ( & V_93 -> V_143 . V_128 ) ;
F_210 ( & V_93 -> V_282 ) ;
}
static void F_211 ( struct V_92 * V_93 , struct V_106 * V_107 )
{
F_23 ( L_40 ,
V_41 , V_93 , V_93 -> V_10 , V_93 -> V_38 . V_88 ) ;
switch ( V_93 -> V_38 . V_88 ) {
case V_129 :
V_93 -> V_38 . V_88 = V_132 ;
F_209 ( V_93 , V_107 ) ;
return;
case V_132 :
V_93 -> V_38 . V_88 = V_134 ;
break;
case V_134 :
V_93 -> V_38 . V_88 = V_105 ;
F_101 ( V_93 ) ;
break;
case V_133 :
break;
default:
F_9 ( L_41 ,
V_41 , V_93 -> V_38 . V_88 ) ;
}
F_108 ( V_107 ) ;
}
static void F_212 ( struct V_92 * V_93 , struct V_106 * V_107 )
{
F_23 ( L_40 ,
V_41 , V_93 , V_93 -> V_10 , V_93 -> V_38 . V_88 ) ;
switch ( V_93 -> V_38 . V_88 ) {
case V_132 :
V_93 -> V_38 . V_88 = V_134 ;
break;
case V_134 :
V_93 -> V_38 . V_88 = V_105 ;
F_101 ( V_93 ) ;
break;
case V_133 :
case V_105 :
break;
default:
F_9 ( L_42 ,
V_41 , V_93 -> V_38 . V_88 ) ;
}
F_108 ( V_107 ) ;
}
static void F_213 ( struct V_92 * V_93 , struct V_106 * V_107 )
{
struct V_340 * V_341 = F_91 ( V_107 ) ;
unsigned int V_10 = F_179 ( V_341 ) ;
struct V_239 * V_332 ;
struct V_106 * V_342 ;
bool V_127 = false ;
bool V_343 = false ;
unsigned int V_110 = F_77 ( sizeof( * V_332 ) , 16 ) ;
F_23 ( L_40 ,
V_41 , V_93 , V_10 , V_93 -> V_38 . V_88 ) ;
if ( F_11 ( V_341 -> V_19 ) ) {
F_4 ( L_43 ,
V_41 , V_341 -> V_19 , V_10 ) ;
goto V_273;
}
switch ( V_93 -> V_38 . V_88 ) {
case V_275 :
case V_134 :
V_93 -> V_38 . V_88 = V_105 ;
V_127 = true ;
break;
case V_129 :
V_93 -> V_38 . V_88 = V_105 ;
V_343 = true ;
break;
case V_132 :
V_93 -> V_38 . V_88 = V_105 ;
if ( ! V_93 -> V_91 )
V_127 = true ;
break;
case V_133 :
break;
default:
F_9 ( L_44 ,
V_41 , V_93 -> V_38 . V_88 ) ;
V_93 -> V_38 . V_88 = V_105 ;
}
F_94 ( & V_93 -> V_117 ) ;
if ( ! F_95 ( V_122 , & V_93 -> V_38 . V_13 ) )
F_96 ( V_93 ) ;
V_342 = F_97 ( & V_93 -> V_123 ) ;
F_80 ( V_107 , V_112 , V_93 -> V_113 ) ;
V_332 = (struct V_239 * ) F_79 ( V_342 , V_110 ) ;
memset ( V_332 , 0 , V_110 ) ;
F_81 ( V_332 , V_93 -> V_10 ) ;
F_82 ( V_332 ) = F_83 ( F_84 ( V_344 , V_10 ) ) ;
V_332 -> V_120 = V_121 ;
F_92 ( V_93 -> V_38 . V_9 , V_342 ) ;
if ( V_343 ) {
F_209 ( V_93 , V_107 ) ;
return;
}
if ( V_127 )
F_101 ( V_93 ) ;
V_273:
F_108 ( V_107 ) ;
}
static void F_214 ( struct V_92 * V_93 , struct V_106 * V_107 )
{
F_23 ( L_40 ,
V_41 , V_93 , V_93 -> V_10 , V_93 -> V_38 . V_88 ) ;
switch ( V_93 -> V_38 . V_88 ) {
case V_133 :
V_93 -> V_38 . V_88 = V_105 ;
F_101 ( V_93 ) ;
break;
default:
F_9 ( L_45 ,
V_41 , V_93 -> V_38 . V_88 ) ;
}
F_108 ( V_107 ) ;
}
static bool F_215 ( const struct V_92 * V_93 )
{
const struct V_106 * V_107 = V_93 -> V_345 ;
T_2 V_346 = 0 ;
if ( F_206 ( V_93 -> V_276 > V_93 -> V_277 ) ) {
F_4 ( L_46 ,
V_93 , V_93 -> V_10 , V_93 -> V_276 , V_93 -> V_277 ) ;
return true ;
}
while ( V_107 ) {
V_346 += V_107 -> V_347 ;
V_107 = F_216 ( V_107 ) ;
}
if ( F_206 ( ( V_93 -> V_276 + V_346 ) != V_93 -> V_277 ) ) {
F_4 ( L_47 ,
V_93 , V_93 -> V_10 , V_93 -> V_276 ,
V_346 , V_93 -> V_277 ) ;
return true ;
}
return false ;
}
static void F_217 ( struct V_92 * V_93 , struct V_106 * V_107 )
{
struct V_348 * V_332 = (struct V_348 * ) F_91 ( V_107 ) ;
T_2 V_349 = V_332 -> V_349 ;
T_2 V_339 = F_119 ( V_332 -> V_339 ) ;
V_93 -> V_276 += V_349 ;
if ( V_93 -> V_278 > ( V_93 -> V_277 - V_93 -> V_276 ) )
V_93 -> V_278 = V_93 -> V_277 - V_93 -> V_276 ;
while ( V_349 ) {
struct V_106 * V_28 = F_218 ( V_93 ) ;
if ( F_206 ( ! V_28 ) ) {
F_4 ( L_48 ,
V_93 , V_93 -> V_10 , V_349 ,
V_93 -> V_276 , V_93 -> V_278 ) ;
break;
}
if ( F_206 ( V_349 < V_28 -> V_347 ) ) {
F_195 ( L_49 ,
V_93 , V_93 -> V_10 ,
V_349 , V_93 -> V_276 , V_93 -> V_278 ,
V_28 -> V_347 ) ;
V_28 -> V_347 -= V_349 ;
break;
}
F_107 ( V_93 ) ;
V_349 -= V_28 -> V_347 ;
F_89 ( V_28 ) ;
}
if ( F_206 ( F_215 ( V_93 ) ) ) {
F_209 ( V_93 , V_107 ) ;
return;
}
if ( V_332 -> V_350 & V_351 ) {
if ( F_206 ( F_219 ( V_339 , V_93 -> V_339 ) ) ) {
F_195 ( L_50 ,
V_93 , V_93 -> V_10 , V_339 ,
V_93 -> V_339 ) ;
goto V_273;
}
if ( V_93 -> V_339 != V_339 ) {
V_93 -> V_339 = V_339 ;
F_208 ( V_93 -> V_147 ) ;
F_210 ( & V_93 -> V_283 ) ;
}
}
if ( F_220 ( & V_93 -> V_117 ) )
F_87 ( V_93 ) ;
V_273:
F_108 ( V_107 ) ;
}
static void F_221 ( struct V_8 * V_9 , struct V_106 * V_107 )
{
struct V_92 * V_93 ;
struct V_352 * V_332 = (struct V_352 * ) V_107 -> V_241 ;
unsigned int V_10 = F_179 ( V_332 ) ;
struct V_60 * V_16 = & V_9 -> V_16 ;
struct V_269 * V_270 = V_16 -> V_76 ;
V_93 = F_181 ( V_270 , V_10 ) ;
if ( F_206 ( ! V_93 ) )
F_4 ( L_38 , V_10 ) ;
else
F_3 ( & V_93 -> V_38 . V_50 , V_41 , V_332 -> V_19 ) ;
F_101 ( V_93 ) ;
}
static void F_222 ( struct V_8 * V_9 , struct V_106 * V_107 )
{
struct V_92 * V_93 ;
struct V_353 * V_354 = F_91 ( V_107 ) ;
unsigned int V_10 = F_179 ( V_354 ) ;
struct V_60 * V_16 = & V_9 -> V_16 ;
struct V_269 * V_270 = V_16 -> V_76 ;
V_93 = F_181 ( V_270 , V_10 ) ;
if ( F_206 ( ! V_93 ) ) {
F_4 ( L_51 , V_10 ) ;
goto V_273;
}
F_209 ( V_93 , V_107 ) ;
return;
V_273:
F_108 ( V_107 ) ;
}
static void
F_223 ( struct V_92 * V_93 , struct V_106 * V_107 )
{
F_15 ( & V_93 -> V_128 ) ;
if ( V_93 -> V_234 ) {
F_86 ( & V_93 -> V_144 , V_107 ) ;
F_16 ( & V_93 -> V_128 ) ;
return;
}
F_155 (V_107)( V_93 , V_107 );
F_16 ( & V_93 -> V_128 ) ;
}
static void F_224 ( struct V_92 * V_93 , struct V_106 * V_107 )
{
F_200 ( V_93 ) ;
F_223 ( V_93 , V_107 ) ;
F_101 ( V_93 ) ;
}
static void F_225 ( struct V_8 * V_9 , struct V_106 * V_107 )
{
struct V_92 * V_93 ;
struct V_355 * V_354 = F_91 ( V_107 ) ;
struct V_60 * V_16 = & V_9 -> V_16 ;
struct V_269 * V_270 = V_16 -> V_76 ;
unsigned int V_10 = F_179 ( V_354 ) ;
T_1 V_356 = F_226 ( V_107 ) ;
bool V_357 = true ;
switch ( V_356 ) {
case V_358 :
F_155 ( V_107 ) = F_217 ;
V_357 = false ;
break;
case V_359 :
F_155 ( V_107 ) = F_211 ;
break;
case V_360 :
F_155 ( V_107 ) = F_212 ;
break;
case V_361 :
F_155 ( V_107 ) = F_213 ;
break;
case V_362 :
F_155 ( V_107 ) = F_214 ;
break;
default:
goto V_273;
}
V_93 = F_181 ( V_270 , V_10 ) ;
if ( F_206 ( ! V_93 ) ) {
F_4 ( L_51 , V_10 ) ;
goto V_273;
}
if ( V_357 )
F_224 ( V_93 , V_107 ) ;
else
F_223 ( V_93 , V_107 ) ;
return;
V_273:
F_108 ( V_107 ) ;
}
