static int F_1 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> V_9 -> V_10 )
return V_7 -> V_9 -> V_10 ( V_5 , V_2 , V_3 ) ;
return 1 ;
}
int F_2 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
if ( ! F_3 ( V_2 ) )
return 0 ;
if ( ( V_3 -> V_11 & V_12 ) != ( V_2 -> V_3 -> V_11 & V_12 ) )
return 0 ;
if ( ( V_3 -> V_11 & V_13 ) != ( V_2 -> V_3 -> V_11 & V_13 ) )
return 0 ;
if ( F_4 ( V_3 ) != F_5 ( V_2 ) )
return 0 ;
if ( V_2 -> V_14 != V_3 -> V_15 -> V_16 || V_2 -> V_17 )
return 0 ;
if ( F_6 ( V_3 ) != F_7 ( V_2 ) )
return 0 ;
if ( ! F_1 ( V_2 , V_3 ) )
return 0 ;
return 1 ;
}
int F_8 ( struct V_1 * V_18 , struct V_3 * V_3 )
{
int V_19 = V_20 ;
if ( F_2 ( V_18 , V_3 ) ) {
if ( F_9 ( V_18 ) + F_10 ( V_18 ) == V_3 -> V_21 )
V_19 = V_22 ;
else if ( F_9 ( V_18 ) - F_11 ( V_3 ) == V_3 -> V_21 )
V_19 = V_23 ;
}
return V_19 ;
}
static struct V_24 * F_12 ( const char * V_25 )
{
struct V_24 * V_7 ;
F_13 (e, &elv_list, list) {
if ( ! strcmp ( V_7 -> V_26 , V_25 ) )
return V_7 ;
}
return NULL ;
}
static void F_14 ( struct V_24 * V_7 )
{
F_15 ( V_7 -> V_27 ) ;
}
static struct V_24 * F_16 ( const char * V_25 )
{
struct V_24 * V_7 ;
F_17 ( & V_28 ) ;
V_7 = F_12 ( V_25 ) ;
if ( ! V_7 ) {
F_18 ( & V_28 ) ;
F_19 ( L_1 , V_25 ) ;
F_17 ( & V_28 ) ;
V_7 = F_12 ( V_25 ) ;
}
if ( V_7 && ! F_20 ( V_7 -> V_27 ) )
V_7 = NULL ;
F_18 ( & V_28 ) ;
return V_7 ;
}
static void * F_21 ( struct V_4 * V_5 ,
struct V_6 * V_29 )
{
return V_29 -> V_9 -> V_30 ( V_5 ) ;
}
static void F_22 ( struct V_4 * V_5 , struct V_6 * V_29 ,
void * V_31 )
{
V_5 -> V_8 = V_29 ;
V_29 -> V_32 = V_31 ;
}
static int T_1 F_23 ( char * V_33 )
{
strncpy ( V_34 , V_33 , sizeof( V_34 ) - 1 ) ;
return 1 ;
}
static struct V_6 * F_24 ( struct V_4 * V_5 ,
struct V_24 * V_7 )
{
struct V_6 * V_29 ;
int V_35 ;
V_29 = F_25 ( sizeof( * V_29 ) , V_36 | V_37 , V_5 -> V_38 ) ;
if ( F_26 ( ! V_29 ) )
goto V_39;
V_29 -> V_9 = & V_7 -> V_9 ;
V_29 -> V_24 = V_7 ;
F_27 ( & V_29 -> V_40 , & V_41 ) ;
F_28 ( & V_29 -> V_42 ) ;
V_29 -> V_43 = F_25 ( sizeof( struct V_44 ) * V_45 ,
V_36 , V_5 -> V_38 ) ;
if ( ! V_29 -> V_43 )
goto V_39;
for ( V_35 = 0 ; V_35 < V_45 ; V_35 ++ )
F_29 ( & V_29 -> V_43 [ V_35 ] ) ;
return V_29 ;
V_39:
F_30 ( V_29 ) ;
F_14 ( V_7 ) ;
return NULL ;
}
static void F_31 ( struct V_46 * V_40 )
{
struct V_6 * V_7 ;
V_7 = F_32 ( V_40 , struct V_6 , V_40 ) ;
F_14 ( V_7 -> V_24 ) ;
F_30 ( V_7 -> V_43 ) ;
F_30 ( V_7 ) ;
}
int F_33 ( struct V_4 * V_5 , char * V_25 )
{
struct V_24 * V_7 = NULL ;
struct V_6 * V_29 ;
void * V_31 ;
if ( F_26 ( V_5 -> V_8 ) )
return 0 ;
F_34 ( & V_5 -> V_47 ) ;
V_5 -> V_48 = NULL ;
V_5 -> V_49 = 0 ;
V_5 -> V_50 = NULL ;
if ( V_25 ) {
V_7 = F_16 ( V_25 ) ;
if ( ! V_7 )
return - V_51 ;
}
if ( ! V_7 && * V_34 ) {
V_7 = F_16 ( V_34 ) ;
if ( ! V_7 )
F_35 ( V_52 L_2 ,
V_34 ) ;
}
if ( ! V_7 ) {
V_7 = F_16 ( V_53 ) ;
if ( ! V_7 ) {
F_35 ( V_52
L_3 \
L_4 ) ;
V_7 = F_16 ( L_5 ) ;
}
}
V_29 = F_24 ( V_5 , V_7 ) ;
if ( ! V_29 )
return - V_54 ;
V_31 = F_21 ( V_5 , V_29 ) ;
if ( ! V_31 ) {
F_36 ( & V_29 -> V_40 ) ;
return - V_54 ;
}
F_22 ( V_5 , V_29 , V_31 ) ;
return 0 ;
}
void F_37 ( struct V_6 * V_7 )
{
F_38 ( & V_7 -> V_42 ) ;
if ( V_7 -> V_9 -> V_55 )
V_7 -> V_9 -> V_55 ( V_7 ) ;
V_7 -> V_9 = NULL ;
F_39 ( & V_7 -> V_42 ) ;
F_36 ( & V_7 -> V_40 ) ;
}
static inline void F_40 ( struct V_1 * V_2 )
{
F_41 ( & V_2 -> V_43 ) ;
}
static void F_42 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
if ( F_43 ( V_2 ) )
F_40 ( V_2 ) ;
}
static void F_44 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
F_45 ( F_43 ( V_2 ) ) ;
F_46 ( & V_2 -> V_43 , & V_7 -> V_43 [ F_47 ( F_48 ( V_2 ) ) ] ) ;
}
static void F_49 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
F_40 ( V_2 ) ;
F_44 ( V_5 , V_2 ) ;
}
static struct V_1 * F_50 ( struct V_4 * V_5 , T_2 V_56 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_44 * V_57 = & V_7 -> V_43 [ F_47 ( V_56 ) ] ;
struct V_58 * V_59 , * V_60 ;
struct V_1 * V_2 ;
F_51 (rq, entry, next, hash_list, hash) {
F_45 ( ! F_43 ( V_2 ) ) ;
if ( F_26 ( ! F_3 ( V_2 ) ) ) {
F_40 ( V_2 ) ;
continue;
}
if ( F_48 ( V_2 ) == V_56 )
return V_2 ;
}
return NULL ;
}
void F_52 ( struct V_61 * V_62 , struct V_1 * V_2 )
{
struct V_63 * * V_64 = & V_62 -> V_63 ;
struct V_63 * V_65 = NULL ;
struct V_1 * V_18 ;
while ( * V_64 ) {
V_65 = * V_64 ;
V_18 = F_53 ( V_65 , struct V_1 , V_63 ) ;
if ( F_9 ( V_2 ) < F_9 ( V_18 ) )
V_64 = & ( * V_64 ) -> V_66 ;
else if ( F_9 ( V_2 ) >= F_9 ( V_18 ) )
V_64 = & ( * V_64 ) -> V_67 ;
}
F_54 ( & V_2 -> V_63 , V_65 , V_64 ) ;
F_55 ( & V_2 -> V_63 , V_62 ) ;
}
void F_56 ( struct V_61 * V_62 , struct V_1 * V_2 )
{
F_45 ( F_57 ( & V_2 -> V_63 ) ) ;
F_58 ( & V_2 -> V_63 , V_62 ) ;
F_59 ( & V_2 -> V_63 ) ;
}
struct V_1 * F_60 ( struct V_61 * V_62 , T_2 V_68 )
{
struct V_63 * V_69 = V_62 -> V_63 ;
struct V_1 * V_2 ;
while ( V_69 ) {
V_2 = F_53 ( V_69 , struct V_1 , V_63 ) ;
if ( V_68 < F_9 ( V_2 ) )
V_69 = V_69 -> V_66 ;
else if ( V_68 > F_9 ( V_2 ) )
V_69 = V_69 -> V_67 ;
else
return V_2 ;
}
return NULL ;
}
void F_61 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
T_2 V_70 ;
struct V_71 * V_59 ;
int V_72 ;
if ( V_5 -> V_48 == V_2 )
V_5 -> V_48 = NULL ;
F_42 ( V_5 , V_2 ) ;
V_5 -> V_73 -- ;
V_70 = V_5 -> V_49 ;
V_72 = V_74 | V_75 ;
F_62 (entry, &q->queue_head) {
struct V_1 * V_76 = F_63 ( V_59 ) ;
if ( ( V_2 -> V_77 & V_12 ) !=
( V_76 -> V_77 & V_12 ) )
break;
if ( F_5 ( V_2 ) != F_5 ( V_76 ) )
break;
if ( V_76 -> V_77 & V_72 )
break;
if ( F_9 ( V_2 ) >= V_70 ) {
if ( F_9 ( V_76 ) < V_70 )
continue;
} else {
if ( F_9 ( V_76 ) >= V_70 )
break;
}
if ( F_9 ( V_2 ) >= F_9 ( V_76 ) )
break;
}
F_64 ( & V_2 -> V_78 , V_59 ) ;
}
void F_65 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
if ( V_5 -> V_48 == V_2 )
V_5 -> V_48 = NULL ;
F_42 ( V_5 , V_2 ) ;
V_5 -> V_73 -- ;
V_5 -> V_49 = F_66 ( V_2 ) ;
V_5 -> V_50 = V_2 ;
F_67 ( & V_2 -> V_78 , & V_5 -> V_47 ) ;
}
int F_68 ( struct V_4 * V_5 , struct V_1 * * V_79 , struct V_3 * V_3 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_1 * V_18 ;
int V_19 ;
if ( F_69 ( V_5 ) )
return V_20 ;
if ( V_5 -> V_48 ) {
V_19 = F_8 ( V_5 -> V_48 , V_3 ) ;
if ( V_19 != V_20 ) {
* V_79 = V_5 -> V_48 ;
return V_19 ;
}
}
if ( F_70 ( V_5 ) )
return V_20 ;
V_18 = F_50 ( V_5 , V_3 -> V_21 ) ;
if ( V_18 && F_2 ( V_18 , V_3 ) ) {
* V_79 = V_18 ;
return V_22 ;
}
if ( V_7 -> V_9 -> V_80 )
return V_7 -> V_9 -> V_80 ( V_5 , V_79 , V_3 ) ;
return V_20 ;
}
static bool F_71 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
struct V_1 * V_18 ;
if ( F_69 ( V_5 ) )
return false ;
if ( V_5 -> V_48 && F_72 ( V_5 , V_5 -> V_48 , V_2 ) )
return true ;
if ( F_70 ( V_5 ) )
return false ;
V_18 = F_50 ( V_5 , F_9 ( V_2 ) ) ;
if ( V_18 && F_72 ( V_5 , V_18 , V_2 ) )
return true ;
return false ;
}
void F_73 ( struct V_4 * V_5 , struct V_1 * V_2 , int type )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> V_9 -> V_81 )
V_7 -> V_9 -> V_81 ( V_5 , V_2 , type ) ;
if ( type == V_22 )
F_49 ( V_5 , V_2 ) ;
V_5 -> V_48 = V_2 ;
}
void F_74 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_1 * V_60 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
const int V_82 = V_60 -> V_77 & V_83 ;
if ( V_82 && V_7 -> V_9 -> V_84 )
V_7 -> V_9 -> V_84 ( V_5 , V_2 , V_60 ) ;
F_49 ( V_5 , V_2 ) ;
if ( V_82 ) {
F_42 ( V_5 , V_60 ) ;
V_5 -> V_73 -- ;
}
V_5 -> V_48 = V_2 ;
}
void F_75 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_3 * V_3 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> V_9 -> V_85 )
V_7 -> V_9 -> V_85 ( V_5 , V_2 , V_3 ) ;
}
void F_76 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
if ( F_77 ( V_2 ) ) {
V_5 -> V_86 [ F_78 ( V_2 ) ] -- ;
if ( V_2 -> V_77 & V_83 )
F_79 ( V_5 , V_2 ) ;
}
V_2 -> V_77 &= ~ V_75 ;
F_80 ( V_5 , V_2 , V_87 ) ;
}
void F_81 ( struct V_4 * V_5 )
{
static int V_88 ;
while ( V_5 -> V_8 -> V_9 -> V_89 ( V_5 , 1 ) )
;
if ( V_5 -> V_73 == 0 )
return;
if ( V_88 ++ < 10 ) {
F_35 ( V_52 L_6
L_7 ,
V_5 -> V_8 -> V_24 -> V_26 , V_5 -> V_73 ) ;
}
}
void F_82 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_8 )
return;
F_83 ( V_90 , V_5 ) ;
F_81 ( V_5 ) ;
while ( V_5 -> V_2 . V_91 ) {
F_84 ( V_5 ) ;
F_85 ( V_5 -> V_92 ) ;
F_86 ( 10 ) ;
F_87 ( V_5 -> V_92 ) ;
F_81 ( V_5 ) ;
}
}
void F_88 ( struct V_4 * V_5 )
{
F_89 ( V_90 , V_5 ) ;
}
void F_80 ( struct V_4 * V_5 , struct V_1 * V_2 , int V_93 )
{
F_90 ( V_5 , V_2 ) ;
V_2 -> V_5 = V_5 ;
if ( V_2 -> V_77 & V_74 ) {
if ( V_2 -> V_94 == V_95 ||
( V_2 -> V_77 & V_12 ) ) {
V_5 -> V_49 = F_66 ( V_2 ) ;
V_5 -> V_50 = V_2 ;
}
} else if ( ! ( V_2 -> V_77 & V_96 ) &&
( V_93 == V_97 ||
V_93 == V_98 ) )
V_93 = V_99 ;
switch ( V_93 ) {
case V_87 :
case V_100 :
V_2 -> V_77 |= V_74 ;
F_64 ( & V_2 -> V_78 , & V_5 -> V_47 ) ;
break;
case V_99 :
V_2 -> V_77 |= V_74 ;
F_81 ( V_5 ) ;
F_67 ( & V_2 -> V_78 , & V_5 -> V_47 ) ;
F_84 ( V_5 ) ;
break;
case V_98 :
if ( F_71 ( V_5 , V_2 ) )
break;
case V_97 :
F_45 ( V_2 -> V_94 != V_95 &&
! ( V_2 -> V_77 & V_12 ) ) ;
V_2 -> V_77 |= V_83 ;
V_5 -> V_73 ++ ;
if ( F_3 ( V_2 ) ) {
F_44 ( V_5 , V_2 ) ;
if ( ! V_5 -> V_48 )
V_5 -> V_48 = V_2 ;
}
V_5 -> V_8 -> V_9 -> V_101 ( V_5 , V_2 ) ;
break;
case V_102 :
V_2 -> V_77 |= V_74 ;
F_91 ( V_2 ) ;
break;
default:
F_35 ( V_52 L_8 ,
V_103 , V_93 ) ;
F_92 () ;
}
}
void F_93 ( struct V_4 * V_5 , struct V_1 * V_2 , int V_93 )
{
unsigned long V_104 ;
F_94 ( V_5 -> V_92 , V_104 ) ;
F_80 ( V_5 , V_2 , V_93 ) ;
F_95 ( V_5 -> V_92 , V_104 ) ;
}
struct V_1 * F_96 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> V_9 -> V_105 )
return V_7 -> V_9 -> V_105 ( V_5 , V_2 ) ;
return NULL ;
}
struct V_1 * F_97 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> V_9 -> V_106 )
return V_7 -> V_9 -> V_106 ( V_5 , V_2 ) ;
return NULL ;
}
int F_98 ( struct V_4 * V_5 , struct V_1 * V_2 , T_3 V_107 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> V_9 -> V_108 )
return V_7 -> V_9 -> V_108 ( V_5 , V_2 , V_107 ) ;
V_2 -> V_109 [ 0 ] = NULL ;
return 0 ;
}
void F_99 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> V_9 -> V_110 )
V_7 -> V_9 -> V_110 ( V_2 ) ;
}
int F_100 ( struct V_4 * V_5 , int V_111 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> V_9 -> V_112 )
return V_7 -> V_9 -> V_112 ( V_5 , V_111 ) ;
return V_113 ;
}
void F_101 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
F_102 ( V_5 ) ;
while ( ! F_103 ( & V_5 -> V_47 ) ) {
V_2 = F_63 ( V_5 -> V_47 . V_60 ) ;
V_2 -> V_77 |= V_114 ;
F_104 ( V_5 , V_2 ) ;
F_105 ( V_2 ) ;
F_106 ( V_2 , - V_115 ) ;
}
}
void F_107 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( F_77 ( V_2 ) ) {
V_5 -> V_86 [ F_78 ( V_2 ) ] -- ;
if ( ( V_2 -> V_77 & V_83 ) &&
V_7 -> V_9 -> V_116 )
V_7 -> V_9 -> V_116 ( V_5 , V_2 ) ;
}
}
static T_4
F_108 ( struct V_46 * V_40 , struct V_117 * V_118 , char * V_119 )
{
struct V_120 * V_59 = F_109 ( V_118 ) ;
struct V_6 * V_7 ;
T_4 error ;
if ( ! V_59 -> V_121 )
return - V_115 ;
V_7 = F_32 ( V_40 , struct V_6 , V_40 ) ;
F_38 ( & V_7 -> V_42 ) ;
error = V_7 -> V_9 ? V_59 -> V_121 ( V_7 , V_119 ) : - V_122 ;
F_39 ( & V_7 -> V_42 ) ;
return error ;
}
static T_4
F_110 ( struct V_46 * V_40 , struct V_117 * V_118 ,
const char * V_119 , T_5 V_123 )
{
struct V_120 * V_59 = F_109 ( V_118 ) ;
struct V_6 * V_7 ;
T_4 error ;
if ( ! V_59 -> V_124 )
return - V_115 ;
V_7 = F_32 ( V_40 , struct V_6 , V_40 ) ;
F_38 ( & V_7 -> V_42 ) ;
error = V_7 -> V_9 ? V_59 -> V_124 ( V_7 , V_119 , V_123 ) : - V_122 ;
F_39 ( & V_7 -> V_42 ) ;
return error ;
}
int F_111 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
int error ;
error = F_112 ( & V_7 -> V_40 , & V_5 -> V_40 , L_9 , L_10 ) ;
if ( ! error ) {
struct V_120 * V_118 = V_7 -> V_24 -> V_125 ;
if ( V_118 ) {
while ( V_118 -> V_118 . V_25 ) {
if ( F_113 ( & V_7 -> V_40 , & V_118 -> V_118 ) )
break;
V_118 ++ ;
}
}
F_114 ( & V_7 -> V_40 , V_126 ) ;
V_7 -> V_127 = 1 ;
}
return error ;
}
static void F_115 ( struct V_6 * V_7 )
{
F_114 ( & V_7 -> V_40 , V_128 ) ;
F_116 ( & V_7 -> V_40 ) ;
V_7 -> V_127 = 0 ;
}
void F_117 ( struct V_4 * V_5 )
{
if ( V_5 )
F_115 ( V_5 -> V_8 ) ;
}
void F_118 ( struct V_24 * V_7 )
{
char * V_129 = L_11 ;
F_17 ( & V_28 ) ;
F_45 ( F_12 ( V_7 -> V_26 ) ) ;
F_67 ( & V_7 -> V_130 , & V_131 ) ;
F_18 ( & V_28 ) ;
if ( ! strcmp ( V_7 -> V_26 , V_34 ) ||
( ! * V_34 &&
! strcmp ( V_7 -> V_26 , V_53 ) ) )
V_129 = L_12 ;
F_35 ( V_132 L_13 , V_7 -> V_26 ,
V_129 ) ;
}
void F_119 ( struct V_24 * V_7 )
{
struct V_133 * V_134 , * V_64 ;
if ( V_7 -> V_9 . V_135 ) {
F_120 ( & V_136 ) ;
F_121 (g, p) {
F_122 ( V_64 ) ;
if ( V_64 -> V_137 )
V_7 -> V_9 . V_135 ( V_64 -> V_137 ) ;
F_123 ( V_64 ) ;
} F_124 ( V_134 , V_64 ) ;
F_125 ( & V_136 ) ;
}
F_17 ( & V_28 ) ;
F_126 ( & V_7 -> V_130 ) ;
F_18 ( & V_28 ) ;
}
static int F_127 ( struct V_4 * V_5 , struct V_24 * V_138 )
{
struct V_6 * V_139 , * V_7 ;
void * V_31 ;
int V_39 ;
V_7 = F_24 ( V_5 , V_138 ) ;
if ( ! V_7 )
return - V_54 ;
V_31 = F_21 ( V_5 , V_7 ) ;
if ( ! V_31 ) {
F_36 ( & V_7 -> V_40 ) ;
return - V_54 ;
}
F_87 ( V_5 -> V_92 ) ;
F_82 ( V_5 ) ;
V_139 = V_5 -> V_8 ;
F_22 ( V_5 , V_7 , V_31 ) ;
F_85 ( V_5 -> V_92 ) ;
if ( V_139 -> V_127 ) {
F_115 ( V_139 ) ;
V_39 = F_111 ( V_5 ) ;
if ( V_39 )
goto V_140;
}
F_37 ( V_139 ) ;
F_87 ( V_5 -> V_92 ) ;
F_88 ( V_5 ) ;
F_85 ( V_5 -> V_92 ) ;
F_128 ( V_5 , L_14 , V_7 -> V_24 -> V_26 ) ;
return 0 ;
V_140:
F_37 ( V_7 ) ;
V_5 -> V_8 = V_139 ;
F_111 ( V_5 ) ;
F_87 ( V_5 -> V_92 ) ;
F_89 ( V_90 , V_5 ) ;
F_85 ( V_5 -> V_92 ) ;
return V_39 ;
}
int F_129 ( struct V_4 * V_5 , const char * V_25 )
{
char V_26 [ V_141 ] ;
struct V_24 * V_7 ;
if ( ! V_5 -> V_8 )
return - V_142 ;
F_130 ( V_26 , V_25 , sizeof( V_26 ) ) ;
V_7 = F_16 ( F_131 ( V_26 ) ) ;
if ( ! V_7 ) {
F_35 ( V_52 L_15 , V_26 ) ;
return - V_51 ;
}
if ( ! strcmp ( V_26 , V_5 -> V_8 -> V_24 -> V_26 ) ) {
F_14 ( V_7 ) ;
return 0 ;
}
return F_127 ( V_5 , V_7 ) ;
}
T_4 F_132 ( struct V_4 * V_5 , const char * V_25 ,
T_5 V_143 )
{
int V_19 ;
if ( ! V_5 -> V_8 )
return V_143 ;
V_19 = F_129 ( V_5 , V_25 ) ;
if ( ! V_19 )
return V_143 ;
F_35 ( V_52 L_16 , V_25 ) ;
return V_19 ;
}
T_4 F_133 ( struct V_4 * V_5 , char * V_25 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_24 * V_144 ;
struct V_24 * V_145 ;
int V_146 = 0 ;
if ( ! V_5 -> V_8 || ! F_134 ( V_5 ) )
return sprintf ( V_25 , L_17 ) ;
V_144 = V_7 -> V_24 ;
F_17 ( & V_28 ) ;
F_13 (__e, &elv_list, list) {
if ( ! strcmp ( V_144 -> V_26 , V_145 -> V_26 ) )
V_146 += sprintf ( V_25 + V_146 , L_18 , V_144 -> V_26 ) ;
else
V_146 += sprintf ( V_25 + V_146 , L_19 , V_145 -> V_26 ) ;
}
F_18 ( & V_28 ) ;
V_146 += sprintf ( V_146 + V_25 , L_20 ) ;
return V_146 ;
}
struct V_1 * F_135 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
struct V_63 * V_147 = F_136 ( & V_2 -> V_63 ) ;
if ( V_147 )
return F_137 ( V_147 ) ;
return NULL ;
}
struct V_1 * F_138 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
struct V_63 * V_148 = F_139 ( & V_2 -> V_63 ) ;
if ( V_148 )
return F_137 ( V_148 ) ;
return NULL ;
}
