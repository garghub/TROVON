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
if ( V_45 >= V_49 ) {
F_16 ( V_32 , L_4 , V_50 ) ;
return - V_51 ;
}
V_2 -> V_45 = V_45 ;
F_17 ( V_45 , V_44 ) ;
F_6 ( V_32 , L_5 , V_2 -> V_45 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
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
F_19 ( V_2 -> V_45 , V_44 ) ;
F_6 ( V_32 , L_6 , V_2 -> V_45 ) ;
}
void F_20 ( unsigned long V_52 )
{
struct V_53 * V_54 = (struct V_53 * ) V_52 ;
struct V_43 * V_33 = F_8 ( V_54 , struct V_43 , V_54 ) ;
struct V_31 * V_32 = & V_33 -> V_34 . V_32 ;
V_54 -> V_55 = true ;
if ( V_54 -> V_56 <= 4 ) {
V_54 -> V_56 ++ ;
} else {
V_54 -> V_56 = 0 ;
V_54 -> V_57 = V_58 >> 1 ;
}
F_6 ( V_32 , L_7 , V_54 -> V_56 , V_54 -> V_59 ) ;
F_21 ( V_33 ) ;
}
void F_22 ( struct V_43 * V_33 )
{
struct V_53 * V_54 = & V_33 -> V_54 ;
struct V_31 * V_32 = & V_33 -> V_34 . V_32 ;
unsigned V_60 ;
F_6 ( V_32 , L_8 , V_54 -> V_57 ) ;
V_54 -> V_55 = false ;
if( ( V_54 -> V_57 << 1 ) == V_61 )
return;
V_54 -> V_57 <<= 1 ;
V_54 -> V_59 = F_23 () & ( V_54 -> V_57 - 1 ) ;
F_6 ( V_32 , L_9 , V_54 -> V_57 , V_54 -> V_59 ) ;
V_60 = V_54 -> V_59 * V_62 ;
V_54 -> V_56 = 0 ;
F_24 ( & V_54 -> V_63 , V_64 + F_25 ( V_60 ) ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
int V_65 = V_66 ;
if ( V_2 -> V_21 == V_23 ) {
V_65 = 0 ;
} else if ( V_2 -> V_67 ) {
if ( V_2 -> V_21 == V_4
|| V_2 -> V_21 == V_11
|| V_2 -> V_21 == V_9
|| V_2 -> V_21 == V_10 )
V_65 = 1 ;
if ( V_2 -> V_21 == V_7 )
V_65 = 0 ;
}
if ( V_65 > 0 ) {
unsigned V_60 = ( V_65 + 2 ) * V_62 ;
F_24 ( & V_2 -> V_63 , V_64 + F_25 ( V_60 ) ) ;
} else
F_27 ( & V_2 -> V_63 ) ;
}
static void F_28 ( struct V_1 * V_2 ,
enum V_22 V_68 )
{
V_2 -> V_21 = V_68 ;
V_2 -> V_69 = false ;
F_4 ( L_10 , V_2 ) ;
F_26 ( V_2 ) ;
F_29 ( V_2 -> V_33 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
if ( V_2 -> V_70 )
V_2 -> V_70 ( V_2 ) ;
}
void F_31 ( struct V_1 * V_2 , enum V_22 V_68 )
{
struct V_71 * V_72 = & V_2 -> V_72 ;
if ( V_2 -> V_21 == V_68 ) {
switch ( V_2 -> V_21 ) {
case V_7 :
case V_11 :
case V_9 :
case V_10 :
case V_12 :
case V_17 :
case V_16 :
case V_23 :
F_26 ( V_2 ) ;
break;
default:
break;
}
return;
}
F_4 ( L_11 , V_2 ) ;
switch ( V_68 ) {
case V_23 :
F_28 ( V_2 , V_23 ) ;
F_32 ( V_2 ) ;
F_30 ( V_2 ) ;
break;
case V_4 :
F_28 ( V_2 , V_4 ) ;
break;
case V_5 :
F_28 ( V_2 , V_5 ) ;
break;
case V_6 :
F_33 ( V_2 -> V_73 . V_74 , V_2 -> V_73 . V_74 , V_72 -> V_75 . V_74 , V_76 ) ;
F_28 ( V_2 , V_6 ) ;
break;
case V_7 :
if ( V_2 -> V_21 == V_6
|| V_2 -> V_21 == V_10 ) {
F_34 ( V_2 -> V_33 , & V_72 -> V_75 ) ;
V_2 -> V_77 = false ;
}
F_35 ( V_2 -> V_33 , & V_2 -> V_73 ) ;
F_28 ( V_2 , V_7 ) ;
F_30 ( V_2 ) ;
break;
case V_11 :
V_2 -> V_77 = true ;
F_28 ( V_2 , V_11 ) ;
break;
case V_9 :
V_2 -> V_77 = false ;
F_35 ( V_2 -> V_33 , & V_72 -> V_75 ) ;
F_36 ( V_2 -> V_73 . V_74 , V_2 -> V_73 . V_74 , V_72 -> V_75 . V_74 , V_76 ) ;
V_2 -> V_73 . V_78 += V_72 -> V_75 . V_78 ;
V_2 -> V_73 . V_79 += V_72 -> V_75 . V_79 ;
F_28 ( V_2 , V_9 ) ;
break;
case V_10 :
F_33 ( V_72 -> V_75 . V_74 , V_2 -> V_73 . V_74 , V_72 -> V_80 . V_74 , V_76 ) ;
V_2 -> V_77 = true ;
V_2 -> V_73 . V_78 = V_72 -> V_80 . V_78 ;
V_2 -> V_73 . V_79 = V_72 -> V_80 . V_79 ;
F_37 ( V_2 -> V_73 . V_74 , V_72 -> V_80 . V_74 , V_76 ) ;
F_37 ( V_2 -> V_73 . V_81 , V_72 -> V_80 . V_81 , V_76 ) ;
F_28 ( V_2 , V_10 ) ;
break;
case V_12 :
case V_16 :
V_2 -> V_77 = false ;
F_35 ( V_2 -> V_33 , & V_2 -> V_73 ) ;
F_28 ( V_2 , V_12 ) ;
F_30 ( V_2 ) ;
break;
case V_15 :
F_28 ( V_2 , V_15 ) ;
break;
case V_13 :
F_28 ( V_2 , V_13 ) ;
break;
case V_14 :
F_28 ( V_2 , V_14 ) ;
break;
case V_17 :
V_2 -> V_77 = true ;
F_35 ( V_2 -> V_33 , & V_72 -> V_75 ) ;
F_28 ( V_2 , V_17 ) ;
break;
default:
F_16 ( & V_2 -> V_33 -> V_34 . V_32 , L_12 ,
F_2 ( V_68 ) , V_68 ) ;
}
}
static void F_38 ( struct V_82 * V_83 )
{
struct V_1 * V_2 = F_8 ( V_83 , struct V_1 ,
V_84 ) ;
struct V_43 * V_33 = V_2 -> V_33 ;
F_39 ( & V_33 -> V_85 ) ;
F_4 ( L_13 , V_2 ) ;
switch ( V_2 -> V_21 ) {
case V_4 :
if ( V_2 -> V_67 ) {
F_31 ( V_2 , V_7 ) ;
goto V_86;
}
break;
case V_11 :
if ( V_2 -> V_67 ) {
F_31 ( V_2 , V_9 ) ;
goto V_86;
}
break;
case V_9 :
if ( V_2 -> V_67 ) {
F_31 ( V_2 , V_10 ) ;
goto V_86;
}
break;
case V_10 :
if ( V_2 -> V_67 ) {
F_31 ( V_2 , V_7 ) ;
goto V_86;
}
break;
case V_7 :
if ( V_2 -> V_67 )
goto V_86;
break;
case V_17 :
F_31 ( V_2 , V_12 ) ;
F_34 ( V_2 -> V_33 , & V_2 -> V_72 . V_75 ) ;
goto V_86;
case V_23 :
goto V_86;
default:
break;
}
F_32 ( V_2 ) ;
V_86:
F_40 ( & V_33 -> V_85 ) ;
}
static struct V_1 * F_41 ( struct V_43 * V_33 )
{
struct V_1 * V_2 ;
V_2 = F_42 ( sizeof( struct V_1 ) , V_87 ) ;
if ( ! V_2 )
return NULL ;
F_43 ( & V_2 -> V_88 ) ;
F_43 ( & V_2 -> V_89 ) ;
F_44 ( & V_2 -> V_42 ) ;
F_45 ( & V_2 -> V_63 , V_90 , ( unsigned long ) V_2 ) ;
V_2 -> V_33 = V_33 ;
F_46 ( & V_2 -> V_84 , F_38 ) ;
return V_2 ;
}
struct V_1 * F_47 ( struct V_43 * V_33 , T_1 V_91 , void * V_92 )
{
struct V_1 * V_2 ;
V_2 = F_41 ( V_33 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_70 = V_91 ;
V_2 -> V_92 = V_92 ;
return V_2 ;
}
void F_32 ( struct V_1 * V_2 )
{
F_4 ( L_14 , V_2 ) ;
if ( V_2 -> V_21 != V_23 )
F_31 ( V_2 , V_23 ) ;
if ( V_2 -> V_77 )
F_34 ( V_2 -> V_33 , & V_2 -> V_72 . V_75 ) ;
F_34 ( V_2 -> V_33 , & V_2 -> V_73 ) ;
if ( F_48 ( V_2 ) )
F_18 ( V_2 ) ;
F_49 ( V_2 -> V_37 ) ;
if ( V_2 -> V_39 . type == V_41 )
F_49 ( V_2 -> V_39 . V_32 ) ;
F_50 ( & V_2 -> V_88 ) ;
F_12 ( V_2 ) ;
}
void F_51 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) ;
}
int F_52 ( struct V_1 * V_2 )
{
struct V_43 * V_33 = V_2 -> V_33 ;
struct V_93 V_94 ;
struct V_31 * V_32 = & V_33 -> V_34 . V_32 ;
int V_95 ;
F_39 ( & V_33 -> V_85 ) ;
V_95 = F_14 ( V_2 ) ;
if ( V_95 ) {
F_16 ( V_32 , L_15 ,
V_50 , V_95 ) ;
goto V_96;
}
V_2 -> V_97 = F_23 () & 1 ;
F_53 ( V_33 , & V_94 ) ;
V_95 = F_54 ( V_2 , & V_94 , & V_2 -> V_73 ) ;
if ( V_95 == V_98 ) {
V_95 = - V_51 ;
F_18 ( V_2 ) ;
F_16 ( V_32 , L_16 ,
V_50 , V_95 ) ;
goto V_96;
}
V_95 = F_55 ( V_33 , & V_2 -> V_73 ) ;
if ( V_95 != 0 ) {
F_18 ( V_2 ) ;
F_16 ( V_32 , L_17 ,
V_50 , V_95 ) ;
goto V_96;
}
F_10 ( V_2 ) ;
F_56 ( & V_2 -> V_88 , & V_33 -> V_99 ) ;
V_2 -> V_37 = & V_33 -> V_34 ;
F_57 ( V_2 -> V_37 ) ;
F_31 ( V_2 , V_4 ) ;
V_96:
F_40 ( & V_33 -> V_85 ) ;
return V_95 ;
}
int F_58 ( struct V_1 * V_2 , int V_100 , int V_101 , int V_102 )
{
return - V_103 ;
}
int F_59 ( struct V_1 * V_2 , struct V_93 * V_94 )
{
struct V_43 * V_33 = V_2 -> V_33 ;
struct V_53 * V_54 = & V_33 -> V_54 ;
struct V_31 * V_32 = & V_33 -> V_34 . V_32 ;
struct V_71 * V_72 ;
int V_95 = 0 ;
if ( V_54 -> V_55 == false )
return - V_51 ;
V_72 = & V_2 -> V_72 ;
if ( F_54 ( V_2 , V_94 , & V_72 -> V_80 ) == V_104 ) {
if ( ! F_60 ( V_2 -> V_73 . V_74 , V_72 -> V_80 . V_74 , V_76 ) ) {
F_33 ( V_72 -> V_75 . V_74 , V_72 -> V_80 . V_74 , V_2 -> V_73 . V_74 , V_76 ) ;
F_55 ( V_33 , & V_72 -> V_75 ) ;
F_31 ( V_2 , V_11 ) ;
}
} else {
F_6 ( V_32 , L_18 ) ;
}
return V_95 ;
}
void F_21 ( struct V_43 * V_33 )
{
struct V_53 * V_54 = & V_33 -> V_54 ;
struct V_1 * V_2 ;
struct V_93 V_73 ;
if ( V_54 -> V_55 == false )
return;
F_61 (rsv, &rc->reservations, rc_node) {
if ( V_2 -> V_21 == V_7 ||
V_2 -> V_21 == V_8 ) {
F_53 ( V_33 , & V_73 ) ;
F_36 ( V_73 . V_74 , V_73 . V_74 , V_2 -> V_73 . V_74 , V_76 ) ;
F_59 ( V_2 , & V_73 ) ;
}
}
}
void F_62 ( struct V_1 * V_2 )
{
struct V_43 * V_33 = V_2 -> V_33 ;
F_39 ( & V_33 -> V_85 ) ;
if ( V_2 -> V_21 != V_23 )
F_31 ( V_2 , V_23 ) ;
F_40 ( & V_33 -> V_85 ) ;
}
void F_63 ( struct V_1 * V_2 , T_1 V_91 , void * V_92 )
{
F_10 ( V_2 ) ;
V_2 -> V_70 = V_91 ;
V_2 -> V_92 = V_92 ;
V_2 -> V_21 = V_12 ;
}
static bool F_64 ( struct V_1 * V_2 , struct V_34 * V_105 ,
struct V_106 * V_107 )
{
struct V_35 * V_108 ;
int V_45 ;
V_45 = F_65 ( V_107 ) ;
if ( V_2 -> V_45 != V_45 )
return false ;
switch ( V_2 -> V_39 . type ) {
case V_47 :
return V_2 -> V_45 == V_45 ;
case V_41 :
if ( F_66 ( V_107 ) )
V_108 = & V_2 -> V_37 -> V_40 ;
else
V_108 = & V_2 -> V_39 . V_32 -> V_40 ;
return F_67 ( & V_105 -> V_40 , V_108 ) == 0 ;
}
return false ;
}
static struct V_1 * F_68 ( struct V_43 * V_33 ,
struct V_34 * V_105 ,
struct V_106 * V_107 )
{
struct V_1 * V_2 ;
struct V_109 * V_110 ;
enum V_22 V_21 ;
V_2 = F_41 ( V_33 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_33 = V_33 ;
V_2 -> V_37 = V_105 ;
F_57 ( V_2 -> V_37 ) ;
V_2 -> V_39 . type = V_41 ;
V_2 -> V_39 . V_32 = & V_33 -> V_34 ;
F_57 ( & V_33 -> V_34 ) ;
V_2 -> type = F_69 ( V_107 ) ;
V_2 -> V_45 = F_65 ( V_107 ) ;
F_70 ( & V_2 -> V_73 , V_107 ) ;
V_2 -> V_21 = V_15 ;
F_39 ( & V_33 -> V_34 . V_111 ) ;
F_61 (pal, &rc->pals, node) {
if ( V_110 -> V_112 )
V_110 -> V_112 ( V_110 , V_2 ) ;
if ( V_2 -> V_21 == V_12 )
break;
}
F_40 ( & V_33 -> V_34 . V_111 ) ;
F_56 ( & V_2 -> V_88 , & V_33 -> V_99 ) ;
V_21 = V_2 -> V_21 ;
V_2 -> V_21 = V_23 ;
if ( V_21 == V_12
&& F_55 ( V_33 , & V_2 -> V_73 ) == - V_51 ) {
} else {
F_31 ( V_2 , V_21 ) ;
}
return V_2 ;
}
void F_71 ( struct V_1 * V_2 , struct V_93 * V_73 )
{
F_72 ( V_73 -> V_74 , V_76 ) ;
F_33 ( V_73 -> V_74 , V_2 -> V_73 . V_74 , V_2 -> V_33 -> V_113 . V_74 , V_76 ) ;
}
struct V_1 * F_73 ( struct V_43 * V_33 , struct V_34 * V_105 ,
struct V_106 * V_107 )
{
struct V_1 * V_2 ;
F_61 (rsv, &rc->reservations, rc_node) {
if ( F_64 ( V_2 , V_105 , V_107 ) )
return V_2 ;
}
if ( F_66 ( V_107 ) )
return F_68 ( V_33 , V_105 , V_107 ) ;
return NULL ;
}
static bool F_74 ( struct V_43 * V_33 )
{
struct V_1 * V_2 , * V_114 ;
bool V_115 = false ;
F_75 (rsv, t, &rc->reservations, rc_node) {
if ( ! V_2 -> V_69 ) {
F_76 ( V_2 ) ;
V_115 = true ;
}
}
return V_115 ;
}
void F_77 ( struct V_43 * V_33 )
{
unsigned long V_116 = V_117 * V_118 ;
F_78 ( V_33 -> V_119 , & V_33 -> V_120 , F_25 ( V_116 ) ) ;
}
void F_29 ( struct V_43 * V_33 )
{
F_79 ( & V_33 -> V_121 ) ;
if ( ! F_80 ( & V_33 -> V_120 ) ) {
if ( V_33 -> V_122 > 0 ) {
V_33 -> V_122 ++ ;
goto V_86;
}
F_77 ( V_33 ) ;
}
V_86:
F_81 ( & V_33 -> V_121 ) ;
}
static void F_82 ( struct V_82 * V_83 )
{
struct V_43 * V_33 = F_8 ( V_83 , struct V_43 ,
V_120 . V_83 ) ;
bool V_115 ;
F_39 ( & V_33 -> V_85 ) ;
V_115 = F_74 ( V_33 ) ;
if ( ! V_33 -> V_123 . V_69 ) {
F_83 ( V_33 ) ;
V_115 = true ;
}
if ( V_115 && ( V_33 -> V_122 == 0 ) )
F_84 ( V_33 ) ;
F_40 ( & V_33 -> V_85 ) ;
}
static void F_85 ( struct V_82 * V_83 )
{
struct V_43 * V_33 = F_8 ( V_83 , struct V_43 ,
V_124 . V_83 ) ;
struct V_1 * V_2 ;
F_39 ( & V_33 -> V_85 ) ;
F_61 (rsv, &rc->reservations, rc_node) {
if ( V_2 -> type != V_27 ) {
F_30 ( V_2 ) ;
}
}
F_40 ( & V_33 -> V_85 ) ;
}
static void V_90 ( unsigned long V_52 )
{
struct V_1 * V_2 = (struct V_1 * ) V_52 ;
F_86 ( V_2 -> V_33 -> V_119 , & V_2 -> V_84 ) ;
}
void F_87 ( struct V_43 * V_33 )
{
struct V_1 * V_2 , * V_114 ;
F_39 ( & V_33 -> V_85 ) ;
F_75 (rsv, t, &rc->reservations, rc_node) {
if ( V_2 -> V_21 != V_23 )
F_31 ( V_2 , V_23 ) ;
F_88 ( & V_2 -> V_63 ) ;
}
V_33 -> V_122 = 0 ;
F_40 ( & V_33 -> V_85 ) ;
F_89 ( & V_33 -> V_120 ) ;
F_90 ( V_33 -> V_119 ) ;
F_39 ( & V_33 -> V_85 ) ;
F_75 (rsv, t, &rc->reservations, rc_node) {
F_32 ( V_2 ) ;
}
F_40 ( & V_33 -> V_85 ) ;
}
void F_91 ( struct V_43 * V_33 )
{
F_43 ( & V_33 -> V_99 ) ;
F_43 ( & V_33 -> V_125 ) ;
F_92 ( & V_33 -> V_85 ) ;
F_93 ( & V_33 -> V_121 ) ;
F_94 ( & V_33 -> V_120 , F_82 ) ;
F_94 ( & V_33 -> V_124 , F_85 ) ;
V_33 -> V_54 . V_55 = true ;
V_33 -> V_54 . V_56 = 0 ;
V_33 -> V_54 . V_57 = V_58 >> 1 ;
F_45 ( & V_33 -> V_54 . V_63 , F_20 ,
( unsigned long ) & V_33 -> V_54 ) ;
F_95 ( V_33 -> V_34 . V_46 , V_33 -> V_34 . V_46 , V_49 ) ;
}
int F_96 ( struct V_43 * V_33 )
{
char V_126 [ 16 ] ;
snprintf ( V_126 , sizeof( V_126 ) , L_19 , F_97 ( & V_33 -> V_34 . V_32 ) ) ;
V_33 -> V_119 = F_98 ( V_126 ) ;
if ( V_33 -> V_119 == NULL )
return - V_127 ;
return 0 ;
}
void F_99 ( struct V_43 * V_33 )
{
F_87 ( V_33 ) ;
F_100 ( V_33 -> V_119 ) ;
}
