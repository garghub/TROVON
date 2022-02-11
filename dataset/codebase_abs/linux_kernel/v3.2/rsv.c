bool F_1 ( struct V_1 * V_2 )
{
static const bool V_3 [] = {
[ V_4 ] = false ,
[ V_5 ] = false ,
[ V_6 ] = false ,
[ V_7 ] = false ,
[ V_8 ] = false ,
[ V_9 ] = false ,
[ V_10 ] = false ,
[ V_11 ] = true ,
[ V_12 ] = false ,
[ V_13 ] = false ,
[ V_14 ] = false ,
[ V_15 ] = false ,
[ V_16 ] = false ,
[ V_17 ] = true ,
[ V_18 ] = true ,
[ V_19 ] = true ,
[ V_20 ] = true ,
} ;
return V_3 [ V_2 -> V_21 ] ;
}
const char * F_2 ( enum V_22 V_21 )
{
if ( V_21 < V_23 || V_21 >= V_24 )
return L_1 ;
return V_25 [ V_21 ] ;
}
const char * F_3 ( enum V_26 type )
{
if ( type < V_27 || type > V_28 )
return L_2 ;
return V_29 [ type ] ;
}
void F_4 ( char * V_30 , struct V_1 * V_2 )
{
struct V_31 * V_32 = & V_2 -> V_33 -> V_34 . V_32 ;
struct V_35 V_36 ;
char V_37 [ V_38 ] , V_39 [ V_38 ] ;
F_5 ( V_37 , sizeof( V_37 ) , & V_2 -> V_37 -> V_40 ) ;
if ( V_2 -> V_39 . type == V_41 )
V_36 = V_2 -> V_39 . V_32 -> V_40 ;
else
V_36 = V_2 -> V_39 . V_36 ;
F_5 ( V_39 , sizeof( V_39 ) , & V_36 ) ;
F_6 ( V_32 , L_3 ,
V_30 , V_37 , V_39 , F_2 ( V_2 -> V_21 ) ) ;
}
static void F_7 ( struct V_42 * V_42 )
{
struct V_1 * V_2 = F_8 ( V_42 , struct V_1 , V_42 ) ;
F_9 ( V_2 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_42 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
F_13 ( & V_2 -> V_42 , F_7 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_43 * V_33 = V_2 -> V_33 ;
struct V_31 * V_32 = & V_33 -> V_34 . V_32 ;
unsigned long * V_44 ;
int V_45 ;
switch ( V_2 -> V_39 . type ) {
case V_41 :
V_44 = V_2 -> V_39 . V_32 -> V_46 ;
break;
case V_47 :
V_44 = V_33 -> V_34 . V_46 ;
break;
default:
return - V_48 ;
}
V_45 = F_15 ( V_44 , V_49 ) ;
if ( V_45 >= V_49 )
return - V_50 ;
V_2 -> V_45 = V_45 ;
F_16 ( V_45 , V_44 ) ;
F_6 ( V_32 , L_4 , V_2 -> V_45 ) ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_43 * V_33 = V_2 -> V_33 ;
struct V_31 * V_32 = & V_33 -> V_34 . V_32 ;
unsigned long * V_44 ;
switch ( V_2 -> V_39 . type ) {
case V_41 :
V_44 = V_2 -> V_39 . V_32 -> V_46 ;
break;
case V_47 :
V_44 = V_33 -> V_34 . V_46 ;
break;
default:
return;
}
F_18 ( V_2 -> V_45 , V_44 ) ;
F_6 ( V_32 , L_5 , V_2 -> V_45 ) ;
}
void F_19 ( unsigned long V_51 )
{
struct V_52 * V_53 = (struct V_52 * ) V_51 ;
struct V_43 * V_33 = F_8 ( V_53 , struct V_43 , V_53 ) ;
struct V_31 * V_32 = & V_33 -> V_34 . V_32 ;
V_53 -> V_54 = true ;
if ( V_53 -> V_55 <= 4 ) {
V_53 -> V_55 ++ ;
} else {
V_53 -> V_55 = 0 ;
V_53 -> V_56 = V_57 >> 1 ;
}
F_6 ( V_32 , L_6 , V_53 -> V_55 , V_53 -> V_58 ) ;
F_20 ( V_33 ) ;
}
void F_21 ( struct V_43 * V_33 )
{
struct V_52 * V_53 = & V_33 -> V_53 ;
struct V_31 * V_32 = & V_33 -> V_34 . V_32 ;
unsigned V_59 ;
F_6 ( V_32 , L_7 , V_53 -> V_56 ) ;
V_53 -> V_54 = false ;
if( ( V_53 -> V_56 << 1 ) == V_60 )
return;
V_53 -> V_56 <<= 1 ;
V_53 -> V_58 = F_22 () & ( V_53 -> V_56 - 1 ) ;
F_6 ( V_32 , L_8 , V_53 -> V_56 , V_53 -> V_58 ) ;
V_59 = V_53 -> V_58 * V_61 ;
V_53 -> V_55 = 0 ;
F_23 ( & V_53 -> V_62 , V_63 + F_24 ( V_59 ) ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
int V_64 = V_65 ;
if ( V_2 -> V_66 ) {
if ( V_2 -> V_21 == V_4
|| V_2 -> V_21 == V_11
|| V_2 -> V_21 == V_9
|| V_2 -> V_21 == V_10 )
V_64 = 1 ;
if ( V_2 -> V_21 == V_7 )
V_64 = 0 ;
}
if ( V_64 > 0 ) {
unsigned V_59 = ( V_64 + 2 ) * V_61 ;
F_23 ( & V_2 -> V_62 , V_63 + F_24 ( V_59 ) ) ;
} else
F_26 ( & V_2 -> V_62 ) ;
}
static void F_27 ( struct V_1 * V_2 ,
enum V_22 V_67 )
{
V_2 -> V_21 = V_67 ;
V_2 -> V_68 = false ;
F_4 ( L_9 , V_2 ) ;
F_25 ( V_2 ) ;
F_28 ( V_2 -> V_33 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
if ( V_2 -> V_69 )
V_2 -> V_69 ( V_2 ) ;
}
void F_30 ( struct V_1 * V_2 , enum V_22 V_67 )
{
struct V_70 * V_71 = & V_2 -> V_71 ;
if ( V_2 -> V_21 == V_67 ) {
switch ( V_2 -> V_21 ) {
case V_7 :
case V_11 :
case V_9 :
case V_10 :
case V_12 :
case V_17 :
case V_16 :
case V_23 :
F_25 ( V_2 ) ;
break;
default:
break;
}
return;
}
F_4 ( L_10 , V_2 ) ;
switch ( V_67 ) {
case V_23 :
F_27 ( V_2 , V_23 ) ;
F_29 ( V_2 ) ;
break;
case V_4 :
F_27 ( V_2 , V_4 ) ;
break;
case V_5 :
F_27 ( V_2 , V_5 ) ;
break;
case V_6 :
F_31 ( V_2 -> V_72 . V_73 , V_2 -> V_72 . V_73 , V_71 -> V_74 . V_73 , V_75 ) ;
F_27 ( V_2 , V_6 ) ;
break;
case V_7 :
if ( V_2 -> V_21 == V_6
|| V_2 -> V_21 == V_10 ) {
F_32 ( V_2 -> V_33 , & V_71 -> V_74 ) ;
V_2 -> V_76 = false ;
}
F_33 ( V_2 -> V_33 , & V_2 -> V_72 ) ;
F_27 ( V_2 , V_7 ) ;
F_29 ( V_2 ) ;
break;
case V_11 :
V_2 -> V_76 = true ;
F_27 ( V_2 , V_11 ) ;
break;
case V_9 :
V_2 -> V_76 = false ;
F_33 ( V_2 -> V_33 , & V_71 -> V_74 ) ;
F_34 ( V_2 -> V_72 . V_73 , V_2 -> V_72 . V_73 , V_71 -> V_74 . V_73 , V_75 ) ;
V_2 -> V_72 . V_77 += V_71 -> V_74 . V_77 ;
V_2 -> V_72 . V_78 += V_71 -> V_74 . V_78 ;
F_27 ( V_2 , V_9 ) ;
break;
case V_10 :
F_31 ( V_71 -> V_74 . V_73 , V_2 -> V_72 . V_73 , V_71 -> V_79 . V_73 , V_75 ) ;
V_2 -> V_76 = true ;
V_2 -> V_72 . V_77 = V_71 -> V_79 . V_77 ;
V_2 -> V_72 . V_78 = V_71 -> V_79 . V_78 ;
F_35 ( V_2 -> V_72 . V_73 , V_71 -> V_79 . V_73 , V_75 ) ;
F_35 ( V_2 -> V_72 . V_80 , V_71 -> V_79 . V_80 , V_75 ) ;
F_27 ( V_2 , V_10 ) ;
break;
case V_12 :
case V_16 :
V_2 -> V_76 = false ;
F_33 ( V_2 -> V_33 , & V_2 -> V_72 ) ;
F_27 ( V_2 , V_12 ) ;
F_29 ( V_2 ) ;
break;
case V_15 :
F_27 ( V_2 , V_15 ) ;
break;
case V_13 :
F_27 ( V_2 , V_13 ) ;
break;
case V_14 :
F_27 ( V_2 , V_14 ) ;
break;
case V_17 :
V_2 -> V_76 = true ;
F_33 ( V_2 -> V_33 , & V_71 -> V_74 ) ;
F_27 ( V_2 , V_17 ) ;
break;
default:
F_36 ( & V_2 -> V_33 -> V_34 . V_32 , L_11 ,
F_2 ( V_67 ) , V_67 ) ;
}
}
static void F_37 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = F_8 ( V_82 , struct V_1 ,
V_83 ) ;
struct V_43 * V_33 = V_2 -> V_33 ;
F_38 ( & V_33 -> V_84 ) ;
F_4 ( L_12 , V_2 ) ;
switch ( V_2 -> V_21 ) {
case V_4 :
if ( V_2 -> V_66 ) {
F_30 ( V_2 , V_7 ) ;
goto V_85;
}
break;
case V_11 :
if ( V_2 -> V_66 ) {
F_30 ( V_2 , V_9 ) ;
goto V_85;
}
break;
case V_9 :
if ( V_2 -> V_66 ) {
F_30 ( V_2 , V_10 ) ;
goto V_85;
}
break;
case V_10 :
if ( V_2 -> V_66 ) {
F_30 ( V_2 , V_7 ) ;
goto V_85;
}
break;
case V_7 :
if ( V_2 -> V_66 )
goto V_85;
break;
case V_17 :
F_30 ( V_2 , V_12 ) ;
F_32 ( V_2 -> V_33 , & V_2 -> V_71 . V_74 ) ;
goto V_85;
default:
break;
}
F_39 ( V_2 ) ;
V_85:
F_40 ( & V_33 -> V_84 ) ;
}
static struct V_1 * F_41 ( struct V_43 * V_33 )
{
struct V_1 * V_2 ;
V_2 = F_42 ( sizeof( struct V_1 ) , V_86 ) ;
if ( ! V_2 )
return NULL ;
F_43 ( & V_2 -> V_87 ) ;
F_43 ( & V_2 -> V_88 ) ;
F_44 ( & V_2 -> V_42 ) ;
F_45 ( & V_2 -> V_62 ) ;
V_2 -> V_62 . V_89 = V_90 ;
V_2 -> V_62 . V_91 = ( unsigned long ) V_2 ;
V_2 -> V_33 = V_33 ;
F_46 ( & V_2 -> V_83 , F_37 ) ;
return V_2 ;
}
struct V_1 * F_47 ( struct V_43 * V_33 , T_1 V_92 , void * V_93 )
{
struct V_1 * V_2 ;
V_2 = F_41 ( V_33 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_69 = V_92 ;
V_2 -> V_93 = V_93 ;
return V_2 ;
}
void F_39 ( struct V_1 * V_2 )
{
F_4 ( L_13 , V_2 ) ;
if ( V_2 -> V_21 != V_23 )
F_30 ( V_2 , V_23 ) ;
if ( V_2 -> V_76 )
F_32 ( V_2 -> V_33 , & V_2 -> V_71 . V_74 ) ;
F_32 ( V_2 -> V_33 , & V_2 -> V_72 ) ;
if ( F_48 ( V_2 ) )
F_17 ( V_2 ) ;
F_49 ( V_2 -> V_37 ) ;
if ( V_2 -> V_39 . type == V_41 )
F_49 ( V_2 -> V_39 . V_32 ) ;
F_50 ( & V_2 -> V_87 ) ;
F_12 ( V_2 ) ;
}
void F_51 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) ;
}
int F_52 ( struct V_1 * V_2 )
{
struct V_43 * V_33 = V_2 -> V_33 ;
struct V_94 V_95 ;
int V_96 ;
F_38 ( & V_33 -> V_84 ) ;
V_96 = F_14 ( V_2 ) ;
if ( V_96 )
goto V_97;
V_2 -> V_98 = F_22 () & 1 ;
F_53 ( V_33 , & V_95 ) ;
V_96 = F_54 ( V_2 , & V_95 , & V_2 -> V_72 ) ;
if ( V_96 == V_99 ) {
V_96 = - V_50 ;
F_17 ( V_2 ) ;
goto V_97;
}
V_96 = F_55 ( V_33 , & V_2 -> V_72 ) ;
if ( V_96 != 0 ) {
F_17 ( V_2 ) ;
goto V_97;
}
F_10 ( V_2 ) ;
F_56 ( & V_2 -> V_87 , & V_33 -> V_100 ) ;
V_2 -> V_37 = & V_33 -> V_34 ;
F_57 ( V_2 -> V_37 ) ;
F_30 ( V_2 , V_4 ) ;
V_97:
F_40 ( & V_33 -> V_84 ) ;
return V_96 ;
}
int F_58 ( struct V_1 * V_2 , int V_101 , int V_102 , int V_103 )
{
return - V_104 ;
}
int F_59 ( struct V_1 * V_2 , struct V_94 * V_95 )
{
struct V_43 * V_33 = V_2 -> V_33 ;
struct V_52 * V_53 = & V_33 -> V_53 ;
struct V_31 * V_32 = & V_33 -> V_34 . V_32 ;
struct V_70 * V_71 ;
int V_96 = 0 ;
if ( V_53 -> V_54 == false )
return - V_50 ;
V_71 = & V_2 -> V_71 ;
if ( F_54 ( V_2 , V_95 , & V_71 -> V_79 ) == V_105 ) {
if ( ! F_60 ( V_2 -> V_72 . V_73 , V_71 -> V_79 . V_73 , V_75 ) ) {
F_31 ( V_71 -> V_74 . V_73 , V_71 -> V_79 . V_73 , V_2 -> V_72 . V_73 , V_75 ) ;
F_55 ( V_33 , & V_71 -> V_74 ) ;
F_30 ( V_2 , V_11 ) ;
}
} else {
F_6 ( V_32 , L_14 ) ;
}
return V_96 ;
}
void F_20 ( struct V_43 * V_33 )
{
struct V_52 * V_53 = & V_33 -> V_53 ;
struct V_1 * V_2 ;
struct V_94 V_72 ;
if ( V_53 -> V_54 == false )
return;
F_61 (rsv, &rc->reservations, rc_node) {
if ( V_2 -> V_21 == V_7 ||
V_2 -> V_21 == V_8 ) {
F_53 ( V_33 , & V_72 ) ;
F_34 ( V_72 . V_73 , V_72 . V_73 , V_2 -> V_72 . V_73 , V_75 ) ;
F_59 ( V_2 , & V_72 ) ;
}
}
}
void F_62 ( struct V_1 * V_2 )
{
struct V_43 * V_33 = V_2 -> V_33 ;
F_38 ( & V_33 -> V_84 ) ;
if ( V_2 -> V_21 != V_23 )
F_30 ( V_2 , V_23 ) ;
F_40 ( & V_33 -> V_84 ) ;
}
void F_63 ( struct V_1 * V_2 , T_1 V_92 , void * V_93 )
{
F_10 ( V_2 ) ;
V_2 -> V_69 = V_92 ;
V_2 -> V_93 = V_93 ;
V_2 -> V_21 = V_12 ;
}
static bool F_64 ( struct V_1 * V_2 , struct V_34 * V_106 ,
struct V_107 * V_108 )
{
struct V_35 * V_109 ;
int V_45 ;
V_45 = F_65 ( V_108 ) ;
if ( V_2 -> V_45 != V_45 )
return false ;
switch ( V_2 -> V_39 . type ) {
case V_47 :
return V_2 -> V_45 == V_45 ;
case V_41 :
if ( F_66 ( V_108 ) )
V_109 = & V_2 -> V_37 -> V_40 ;
else
V_109 = & V_2 -> V_39 . V_32 -> V_40 ;
return F_67 ( & V_106 -> V_40 , V_109 ) == 0 ;
}
return false ;
}
static struct V_1 * F_68 ( struct V_43 * V_33 ,
struct V_34 * V_106 ,
struct V_107 * V_108 )
{
struct V_1 * V_2 ;
struct V_110 * V_111 ;
enum V_22 V_21 ;
V_2 = F_41 ( V_33 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_33 = V_33 ;
V_2 -> V_37 = V_106 ;
F_57 ( V_2 -> V_37 ) ;
V_2 -> V_39 . type = V_41 ;
V_2 -> V_39 . V_32 = & V_33 -> V_34 ;
F_57 ( & V_33 -> V_34 ) ;
V_2 -> type = F_69 ( V_108 ) ;
V_2 -> V_45 = F_65 ( V_108 ) ;
F_70 ( & V_2 -> V_72 , V_108 ) ;
V_2 -> V_21 = V_15 ;
F_38 ( & V_33 -> V_34 . V_112 ) ;
F_61 (pal, &rc->pals, node) {
if ( V_111 -> V_113 )
V_111 -> V_113 ( V_111 , V_2 ) ;
if ( V_2 -> V_21 == V_12 )
break;
}
F_40 ( & V_33 -> V_34 . V_112 ) ;
F_56 ( & V_2 -> V_87 , & V_33 -> V_100 ) ;
V_21 = V_2 -> V_21 ;
V_2 -> V_21 = V_23 ;
if ( V_21 == V_12
&& F_55 ( V_33 , & V_2 -> V_72 ) == - V_50 ) {
} else {
F_30 ( V_2 , V_21 ) ;
}
return V_2 ;
}
void F_71 ( struct V_1 * V_2 , struct V_94 * V_72 )
{
F_72 ( V_72 -> V_73 , V_75 ) ;
F_31 ( V_72 -> V_73 , V_2 -> V_72 . V_73 , V_2 -> V_33 -> V_114 . V_73 , V_75 ) ;
}
struct V_1 * F_73 ( struct V_43 * V_33 , struct V_34 * V_106 ,
struct V_107 * V_108 )
{
struct V_1 * V_2 ;
F_61 (rsv, &rc->reservations, rc_node) {
if ( F_64 ( V_2 , V_106 , V_108 ) )
return V_2 ;
}
if ( F_66 ( V_108 ) )
return F_68 ( V_33 , V_106 , V_108 ) ;
return NULL ;
}
static bool F_74 ( struct V_43 * V_33 )
{
struct V_1 * V_2 , * V_115 ;
bool V_116 = false ;
F_75 (rsv, t, &rc->reservations, rc_node) {
if ( ! V_2 -> V_68 ) {
F_76 ( V_2 ) ;
V_116 = true ;
}
}
return V_116 ;
}
void F_77 ( struct V_43 * V_33 )
{
unsigned long V_117 = V_118 * V_119 ;
F_78 ( V_33 -> V_120 , & V_33 -> V_121 , F_24 ( V_117 ) ) ;
}
void F_28 ( struct V_43 * V_33 )
{
F_79 ( & V_33 -> V_122 ) ;
if ( ! F_80 ( & V_33 -> V_121 ) ) {
if ( V_33 -> V_123 > 0 ) {
V_33 -> V_123 ++ ;
goto V_85;
}
F_77 ( V_33 ) ;
}
V_85:
F_81 ( & V_33 -> V_122 ) ;
}
static void F_82 ( struct V_81 * V_82 )
{
struct V_43 * V_33 = F_8 ( V_82 , struct V_43 ,
V_121 . V_82 ) ;
bool V_116 ;
F_38 ( & V_33 -> V_84 ) ;
V_116 = F_74 ( V_33 ) ;
if ( ! V_33 -> V_124 . V_68 ) {
F_83 ( V_33 ) ;
V_116 = true ;
}
if ( V_116 && ( V_33 -> V_123 == 0 ) )
F_84 ( V_33 ) ;
F_40 ( & V_33 -> V_84 ) ;
}
static void F_85 ( struct V_81 * V_82 )
{
struct V_43 * V_33 = F_8 ( V_82 , struct V_43 ,
V_125 . V_82 ) ;
struct V_1 * V_2 ;
F_38 ( & V_33 -> V_84 ) ;
F_61 (rsv, &rc->reservations, rc_node) {
if ( V_2 -> type != V_27 ) {
V_2 -> V_69 ( V_2 ) ;
}
}
F_40 ( & V_33 -> V_84 ) ;
}
static void V_90 ( unsigned long V_51 )
{
struct V_1 * V_2 = (struct V_1 * ) V_51 ;
F_86 ( V_2 -> V_33 -> V_120 , & V_2 -> V_83 ) ;
}
void F_87 ( struct V_43 * V_33 )
{
struct V_1 * V_2 , * V_115 ;
F_38 ( & V_33 -> V_84 ) ;
F_75 (rsv, t, &rc->reservations, rc_node) {
if ( V_2 -> V_21 != V_23 )
F_30 ( V_2 , V_23 ) ;
F_88 ( & V_2 -> V_62 ) ;
}
V_33 -> V_123 = 0 ;
F_40 ( & V_33 -> V_84 ) ;
F_89 ( & V_33 -> V_121 ) ;
F_90 ( V_33 -> V_120 ) ;
F_38 ( & V_33 -> V_84 ) ;
F_75 (rsv, t, &rc->reservations, rc_node) {
F_39 ( V_2 ) ;
}
F_40 ( & V_33 -> V_84 ) ;
}
void F_91 ( struct V_43 * V_33 )
{
F_43 ( & V_33 -> V_100 ) ;
F_43 ( & V_33 -> V_126 ) ;
F_92 ( & V_33 -> V_84 ) ;
F_93 ( & V_33 -> V_122 ) ;
F_94 ( & V_33 -> V_121 , F_82 ) ;
F_94 ( & V_33 -> V_125 , F_85 ) ;
V_33 -> V_53 . V_54 = true ;
V_33 -> V_53 . V_55 = 0 ;
V_33 -> V_53 . V_56 = V_57 >> 1 ;
F_45 ( & V_33 -> V_53 . V_62 ) ;
V_33 -> V_53 . V_62 . V_89 = F_19 ;
V_33 -> V_53 . V_62 . V_91 = ( unsigned long ) & V_33 -> V_53 ;
F_95 ( V_33 -> V_34 . V_46 , V_33 -> V_34 . V_46 , V_49 ) ;
}
int F_96 ( struct V_43 * V_33 )
{
char V_127 [ 16 ] ;
snprintf ( V_127 , sizeof( V_127 ) , L_15 , F_97 ( & V_33 -> V_34 . V_32 ) ) ;
V_33 -> V_120 = F_98 ( V_127 ) ;
if ( V_33 -> V_120 == NULL )
return - V_128 ;
return 0 ;
}
void F_99 ( struct V_43 * V_33 )
{
F_87 ( V_33 ) ;
F_100 ( V_33 -> V_120 ) ;
}
