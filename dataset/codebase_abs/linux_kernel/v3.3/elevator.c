static int F_1 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> type -> V_9 . V_10 )
return V_7 -> type -> V_9 . V_10 ( V_5 , V_2 , V_3 ) ;
return 1 ;
}
bool F_2 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
if ( ! F_3 ( V_2 , V_3 ) )
return 0 ;
if ( ! F_1 ( V_2 , V_3 ) )
return 0 ;
return 1 ;
}
static struct V_11 * F_4 ( const char * V_12 )
{
struct V_11 * V_7 ;
F_5 (e, &elv_list, list) {
if ( ! strcmp ( V_7 -> V_13 , V_12 ) )
return V_7 ;
}
return NULL ;
}
static void F_6 ( struct V_11 * V_7 )
{
F_7 ( V_7 -> V_14 ) ;
}
static struct V_11 * F_8 ( const char * V_12 )
{
struct V_11 * V_7 ;
F_9 ( & V_15 ) ;
V_7 = F_4 ( V_12 ) ;
if ( ! V_7 ) {
F_10 ( & V_15 ) ;
F_11 ( L_1 , V_12 ) ;
F_9 ( & V_15 ) ;
V_7 = F_4 ( V_12 ) ;
}
if ( V_7 && ! F_12 ( V_7 -> V_14 ) )
V_7 = NULL ;
F_10 ( & V_15 ) ;
return V_7 ;
}
static int F_13 ( struct V_4 * V_5 ,
struct V_6 * V_16 )
{
V_16 -> V_17 = V_16 -> type -> V_9 . V_18 ( V_5 ) ;
if ( V_16 -> V_17 )
return 0 ;
return - V_19 ;
}
static int T_1 F_14 ( char * V_20 )
{
strncpy ( V_21 , V_20 , sizeof( V_21 ) - 1 ) ;
return 1 ;
}
static struct V_6 * F_15 ( struct V_4 * V_5 ,
struct V_11 * V_7 )
{
struct V_6 * V_16 ;
int V_22 ;
V_16 = F_16 ( sizeof( * V_16 ) , V_23 | V_24 , V_5 -> V_25 ) ;
if ( F_17 ( ! V_16 ) )
goto V_26;
V_16 -> type = V_7 ;
F_18 ( & V_16 -> V_27 , & V_28 ) ;
F_19 ( & V_16 -> V_29 ) ;
V_16 -> V_30 = F_16 ( sizeof( struct V_31 ) * V_32 ,
V_23 , V_5 -> V_25 ) ;
if ( ! V_16 -> V_30 )
goto V_26;
for ( V_22 = 0 ; V_22 < V_32 ; V_22 ++ )
F_20 ( & V_16 -> V_30 [ V_22 ] ) ;
return V_16 ;
V_26:
F_21 ( V_16 ) ;
F_6 ( V_7 ) ;
return NULL ;
}
static void F_22 ( struct V_33 * V_27 )
{
struct V_6 * V_7 ;
V_7 = F_23 ( V_27 , struct V_6 , V_27 ) ;
F_6 ( V_7 -> type ) ;
F_21 ( V_7 -> V_30 ) ;
F_21 ( V_7 ) ;
}
int F_24 ( struct V_4 * V_5 , char * V_12 )
{
struct V_11 * V_7 = NULL ;
struct V_6 * V_16 ;
int V_26 ;
if ( F_17 ( V_5 -> V_8 ) )
return 0 ;
F_25 ( & V_5 -> V_34 ) ;
V_5 -> V_35 = NULL ;
V_5 -> V_36 = 0 ;
V_5 -> V_37 = NULL ;
if ( V_12 ) {
V_7 = F_8 ( V_12 ) ;
if ( ! V_7 )
return - V_38 ;
}
if ( ! V_7 && * V_21 ) {
V_7 = F_8 ( V_21 ) ;
if ( ! V_7 )
F_26 ( V_39 L_2 ,
V_21 ) ;
}
if ( ! V_7 ) {
V_7 = F_8 ( V_40 ) ;
if ( ! V_7 ) {
F_26 ( V_39
L_3 \
L_4 ) ;
V_7 = F_8 ( L_5 ) ;
}
}
V_16 = F_15 ( V_5 , V_7 ) ;
if ( ! V_16 )
return - V_19 ;
V_26 = F_13 ( V_5 , V_16 ) ;
if ( V_26 ) {
F_27 ( & V_16 -> V_27 ) ;
return V_26 ;
}
V_5 -> V_8 = V_16 ;
return 0 ;
}
void F_28 ( struct V_6 * V_7 )
{
F_29 ( & V_7 -> V_29 ) ;
if ( V_7 -> type -> V_9 . V_41 )
V_7 -> type -> V_9 . V_41 ( V_7 ) ;
F_30 ( & V_7 -> V_29 ) ;
F_27 ( & V_7 -> V_27 ) ;
}
static inline void F_31 ( struct V_1 * V_2 )
{
F_32 ( & V_2 -> V_30 ) ;
}
static void F_33 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
if ( F_34 ( V_2 ) )
F_31 ( V_2 ) ;
}
static void F_35 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
F_36 ( F_34 ( V_2 ) ) ;
F_37 ( & V_2 -> V_30 , & V_7 -> V_30 [ F_38 ( F_39 ( V_2 ) ) ] ) ;
}
static void F_40 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
F_31 ( V_2 ) ;
F_35 ( V_5 , V_2 ) ;
}
static struct V_1 * F_41 ( struct V_4 * V_5 , T_2 V_42 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_31 * V_43 = & V_7 -> V_30 [ F_38 ( V_42 ) ] ;
struct V_44 * V_45 , * V_46 ;
struct V_1 * V_2 ;
F_42 (rq, entry, next, hash_list, hash) {
F_36 ( ! F_34 ( V_2 ) ) ;
if ( F_17 ( ! F_43 ( V_2 ) ) ) {
F_31 ( V_2 ) ;
continue;
}
if ( F_39 ( V_2 ) == V_42 )
return V_2 ;
}
return NULL ;
}
void F_44 ( struct V_47 * V_48 , struct V_1 * V_2 )
{
struct V_49 * * V_50 = & V_48 -> V_49 ;
struct V_49 * V_51 = NULL ;
struct V_1 * V_52 ;
while ( * V_50 ) {
V_51 = * V_50 ;
V_52 = F_45 ( V_51 , struct V_1 , V_49 ) ;
if ( F_46 ( V_2 ) < F_46 ( V_52 ) )
V_50 = & ( * V_50 ) -> V_53 ;
else if ( F_46 ( V_2 ) >= F_46 ( V_52 ) )
V_50 = & ( * V_50 ) -> V_54 ;
}
F_47 ( & V_2 -> V_49 , V_51 , V_50 ) ;
F_48 ( & V_2 -> V_49 , V_48 ) ;
}
void F_49 ( struct V_47 * V_48 , struct V_1 * V_2 )
{
F_36 ( F_50 ( & V_2 -> V_49 ) ) ;
F_51 ( & V_2 -> V_49 , V_48 ) ;
F_52 ( & V_2 -> V_49 ) ;
}
struct V_1 * F_53 ( struct V_47 * V_48 , T_2 V_55 )
{
struct V_49 * V_56 = V_48 -> V_49 ;
struct V_1 * V_2 ;
while ( V_56 ) {
V_2 = F_45 ( V_56 , struct V_1 , V_49 ) ;
if ( V_55 < F_46 ( V_2 ) )
V_56 = V_56 -> V_53 ;
else if ( V_55 > F_46 ( V_2 ) )
V_56 = V_56 -> V_54 ;
else
return V_2 ;
}
return NULL ;
}
void F_54 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
T_2 V_57 ;
struct V_58 * V_45 ;
int V_59 ;
if ( V_5 -> V_35 == V_2 )
V_5 -> V_35 = NULL ;
F_33 ( V_5 , V_2 ) ;
V_5 -> V_60 -- ;
V_57 = V_5 -> V_36 ;
V_59 = V_61 | V_62 ;
F_55 (entry, &q->queue_head) {
struct V_1 * V_63 = F_56 ( V_45 ) ;
if ( ( V_2 -> V_64 & V_65 ) !=
( V_63 -> V_64 & V_65 ) )
break;
if ( F_57 ( V_2 ) != F_57 ( V_63 ) )
break;
if ( V_63 -> V_64 & V_59 )
break;
if ( F_46 ( V_2 ) >= V_57 ) {
if ( F_46 ( V_63 ) < V_57 )
continue;
} else {
if ( F_46 ( V_63 ) >= V_57 )
break;
}
if ( F_46 ( V_2 ) >= F_46 ( V_63 ) )
break;
}
F_58 ( & V_2 -> V_66 , V_45 ) ;
}
void F_59 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
if ( V_5 -> V_35 == V_2 )
V_5 -> V_35 = NULL ;
F_33 ( V_5 , V_2 ) ;
V_5 -> V_60 -- ;
V_5 -> V_36 = F_60 ( V_2 ) ;
V_5 -> V_37 = V_2 ;
F_61 ( & V_2 -> V_66 , & V_5 -> V_34 ) ;
}
int F_62 ( struct V_4 * V_5 , struct V_1 * * V_67 , struct V_3 * V_3 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_1 * V_52 ;
int V_68 ;
if ( F_63 ( V_5 ) )
return V_69 ;
if ( V_5 -> V_35 && F_2 ( V_5 -> V_35 , V_3 ) ) {
V_68 = F_64 ( V_5 -> V_35 , V_3 ) ;
if ( V_68 != V_69 ) {
* V_67 = V_5 -> V_35 ;
return V_68 ;
}
}
if ( F_65 ( V_5 ) )
return V_69 ;
V_52 = F_41 ( V_5 , V_3 -> V_70 ) ;
if ( V_52 && F_2 ( V_52 , V_3 ) ) {
* V_67 = V_52 ;
return V_71 ;
}
if ( V_7 -> type -> V_9 . V_72 )
return V_7 -> type -> V_9 . V_72 ( V_5 , V_67 , V_3 ) ;
return V_69 ;
}
static bool F_66 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
struct V_1 * V_52 ;
if ( F_63 ( V_5 ) )
return false ;
if ( V_5 -> V_35 && F_67 ( V_5 , V_5 -> V_35 , V_2 ) )
return true ;
if ( F_65 ( V_5 ) )
return false ;
V_52 = F_41 ( V_5 , F_46 ( V_2 ) ) ;
if ( V_52 && F_67 ( V_5 , V_52 , V_2 ) )
return true ;
return false ;
}
void F_68 ( struct V_4 * V_5 , struct V_1 * V_2 , int type )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> type -> V_9 . V_73 )
V_7 -> type -> V_9 . V_73 ( V_5 , V_2 , type ) ;
if ( type == V_71 )
F_40 ( V_5 , V_2 ) ;
V_5 -> V_35 = V_2 ;
}
void F_69 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_1 * V_46 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
const int V_74 = V_46 -> V_64 & V_75 ;
if ( V_74 && V_7 -> type -> V_9 . V_76 )
V_7 -> type -> V_9 . V_76 ( V_5 , V_2 , V_46 ) ;
F_40 ( V_5 , V_2 ) ;
if ( V_74 ) {
F_33 ( V_5 , V_46 ) ;
V_5 -> V_60 -- ;
}
V_5 -> V_35 = V_2 ;
}
void F_70 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_3 * V_3 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> type -> V_9 . V_77 )
V_7 -> type -> V_9 . V_77 ( V_5 , V_2 , V_3 ) ;
}
void F_71 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
if ( F_72 ( V_2 ) ) {
V_5 -> V_78 [ F_73 ( V_2 ) ] -- ;
if ( V_2 -> V_64 & V_75 )
F_74 ( V_5 , V_2 ) ;
}
V_2 -> V_64 &= ~ V_62 ;
F_75 ( V_5 , V_2 , V_79 ) ;
}
void F_76 ( struct V_4 * V_5 )
{
static int V_80 ;
F_77 ( V_5 -> V_81 ) ;
while ( V_5 -> V_8 -> type -> V_9 . V_82 ( V_5 , 1 ) )
;
if ( V_5 -> V_60 && V_80 ++ < 10 ) {
F_26 ( V_39 L_6
L_7 ,
V_5 -> V_8 -> type -> V_13 , V_5 -> V_60 ) ;
}
}
void F_78 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_8 )
return;
F_79 ( V_5 -> V_81 ) ;
F_80 ( V_83 , V_5 ) ;
F_81 ( V_5 -> V_81 ) ;
F_82 ( V_5 , false ) ;
}
void F_83 ( struct V_4 * V_5 )
{
F_79 ( V_5 -> V_81 ) ;
F_84 ( V_83 , V_5 ) ;
F_81 ( V_5 -> V_81 ) ;
}
void F_75 ( struct V_4 * V_5 , struct V_1 * V_2 , int V_84 )
{
F_85 ( V_5 , V_2 ) ;
V_2 -> V_5 = V_5 ;
if ( V_2 -> V_64 & V_61 ) {
if ( V_2 -> V_85 == V_86 ||
( V_2 -> V_64 & V_65 ) ) {
V_5 -> V_36 = F_60 ( V_2 ) ;
V_5 -> V_37 = V_2 ;
}
} else if ( ! ( V_2 -> V_64 & V_87 ) &&
( V_84 == V_88 ||
V_84 == V_89 ) )
V_84 = V_90 ;
switch ( V_84 ) {
case V_79 :
case V_91 :
V_2 -> V_64 |= V_61 ;
F_58 ( & V_2 -> V_66 , & V_5 -> V_34 ) ;
break;
case V_90 :
V_2 -> V_64 |= V_61 ;
F_76 ( V_5 ) ;
F_61 ( & V_2 -> V_66 , & V_5 -> V_34 ) ;
F_86 ( V_5 ) ;
break;
case V_89 :
if ( F_66 ( V_5 , V_2 ) )
break;
case V_88 :
F_36 ( V_2 -> V_85 != V_86 &&
! ( V_2 -> V_64 & V_65 ) ) ;
V_2 -> V_64 |= V_75 ;
V_5 -> V_60 ++ ;
if ( F_43 ( V_2 ) ) {
F_35 ( V_5 , V_2 ) ;
if ( ! V_5 -> V_35 )
V_5 -> V_35 = V_2 ;
}
V_5 -> V_8 -> type -> V_9 . V_92 ( V_5 , V_2 ) ;
break;
case V_93 :
V_2 -> V_64 |= V_61 ;
F_87 ( V_2 ) ;
break;
default:
F_26 ( V_39 L_8 ,
V_94 , V_84 ) ;
F_88 () ;
}
}
void F_89 ( struct V_4 * V_5 , struct V_1 * V_2 , int V_84 )
{
unsigned long V_95 ;
F_90 ( V_5 -> V_81 , V_95 ) ;
F_75 ( V_5 , V_2 , V_84 ) ;
F_91 ( V_5 -> V_81 , V_95 ) ;
}
struct V_1 * F_92 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> type -> V_9 . V_96 )
return V_7 -> type -> V_9 . V_96 ( V_5 , V_2 ) ;
return NULL ;
}
struct V_1 * F_93 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> type -> V_9 . V_97 )
return V_7 -> type -> V_9 . V_97 ( V_5 , V_2 ) ;
return NULL ;
}
int F_94 ( struct V_4 * V_5 , struct V_1 * V_2 , T_3 V_98 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> type -> V_9 . V_99 )
return V_7 -> type -> V_9 . V_99 ( V_5 , V_2 , V_98 ) ;
return 0 ;
}
void F_95 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> type -> V_9 . V_100 )
V_7 -> type -> V_9 . V_100 ( V_2 ) ;
}
int F_96 ( struct V_4 * V_5 , int V_101 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> type -> V_9 . V_102 )
return V_7 -> type -> V_9 . V_102 ( V_5 , V_101 ) ;
return V_103 ;
}
void F_97 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
F_98 ( V_5 ) ;
while ( ! F_99 ( & V_5 -> V_34 ) ) {
V_2 = F_56 ( V_5 -> V_34 . V_46 ) ;
V_2 -> V_64 |= V_104 ;
F_100 ( V_5 , V_2 ) ;
F_101 ( V_2 ) ;
F_102 ( V_2 , - V_105 ) ;
}
}
void F_103 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( F_72 ( V_2 ) ) {
V_5 -> V_78 [ F_73 ( V_2 ) ] -- ;
if ( ( V_2 -> V_64 & V_75 ) &&
V_7 -> type -> V_9 . V_106 )
V_7 -> type -> V_9 . V_106 ( V_5 , V_2 ) ;
}
}
static T_4
F_104 ( struct V_33 * V_27 , struct V_107 * V_108 , char * V_109 )
{
struct V_110 * V_45 = F_105 ( V_108 ) ;
struct V_6 * V_7 ;
T_4 error ;
if ( ! V_45 -> V_111 )
return - V_105 ;
V_7 = F_23 ( V_27 , struct V_6 , V_27 ) ;
F_29 ( & V_7 -> V_29 ) ;
error = V_7 -> type ? V_45 -> V_111 ( V_7 , V_109 ) : - V_112 ;
F_30 ( & V_7 -> V_29 ) ;
return error ;
}
static T_4
F_106 ( struct V_33 * V_27 , struct V_107 * V_108 ,
const char * V_109 , T_5 V_113 )
{
struct V_110 * V_45 = F_105 ( V_108 ) ;
struct V_6 * V_7 ;
T_4 error ;
if ( ! V_45 -> V_114 )
return - V_105 ;
V_7 = F_23 ( V_27 , struct V_6 , V_27 ) ;
F_29 ( & V_7 -> V_29 ) ;
error = V_7 -> type ? V_45 -> V_114 ( V_7 , V_109 , V_113 ) : - V_112 ;
F_30 ( & V_7 -> V_29 ) ;
return error ;
}
int F_107 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
int error ;
error = F_108 ( & V_7 -> V_27 , & V_5 -> V_27 , L_9 , L_10 ) ;
if ( ! error ) {
struct V_110 * V_108 = V_7 -> type -> V_115 ;
if ( V_108 ) {
while ( V_108 -> V_108 . V_12 ) {
if ( F_109 ( & V_7 -> V_27 , & V_108 -> V_108 ) )
break;
V_108 ++ ;
}
}
F_110 ( & V_7 -> V_27 , V_116 ) ;
V_7 -> V_117 = 1 ;
}
return error ;
}
int F_111 ( struct V_4 * V_5 )
{
return F_107 ( V_5 , V_5 -> V_8 ) ;
}
void F_112 ( struct V_4 * V_5 )
{
if ( V_5 ) {
struct V_6 * V_7 = V_5 -> V_8 ;
F_110 ( & V_7 -> V_27 , V_118 ) ;
F_113 ( & V_7 -> V_27 ) ;
V_7 -> V_117 = 0 ;
}
}
int F_114 ( struct V_11 * V_7 )
{
char * V_119 = L_11 ;
if ( V_7 -> V_120 ) {
if ( F_115 ( V_7 -> V_120 < sizeof( struct V_121 ) ) ||
F_115 ( V_7 -> V_122 < F_116 ( struct V_121 ) ) )
return - V_38 ;
snprintf ( V_7 -> V_123 , sizeof( V_7 -> V_123 ) ,
L_12 , V_7 -> V_13 ) ;
V_7 -> V_124 = F_117 ( V_7 -> V_123 , V_7 -> V_120 ,
V_7 -> V_122 , 0 , NULL ) ;
if ( ! V_7 -> V_124 )
return - V_19 ;
}
F_9 ( & V_15 ) ;
if ( F_4 ( V_7 -> V_13 ) ) {
F_10 ( & V_15 ) ;
if ( V_7 -> V_124 )
F_118 ( V_7 -> V_124 ) ;
return - V_125 ;
}
F_61 ( & V_7 -> V_126 , & V_127 ) ;
F_10 ( & V_15 ) ;
if ( ! strcmp ( V_7 -> V_13 , V_21 ) ||
( ! * V_21 &&
! strcmp ( V_7 -> V_13 , V_40 ) ) )
V_119 = L_13 ;
F_26 ( V_128 L_14 , V_7 -> V_13 ,
V_119 ) ;
return 0 ;
}
void F_119 ( struct V_11 * V_7 )
{
F_9 ( & V_15 ) ;
F_120 ( & V_7 -> V_126 ) ;
F_10 ( & V_15 ) ;
if ( V_7 -> V_124 ) {
F_121 () ;
F_118 ( V_7 -> V_124 ) ;
V_7 -> V_124 = NULL ;
}
}
static int F_122 ( struct V_4 * V_5 , struct V_11 * V_129 )
{
struct V_6 * V_130 , * V_7 ;
int V_26 ;
V_7 = F_15 ( V_5 , V_129 ) ;
if ( ! V_7 )
return - V_19 ;
V_26 = F_13 ( V_5 , V_7 ) ;
if ( V_26 ) {
F_27 ( & V_7 -> V_27 ) ;
return V_26 ;
}
F_78 ( V_5 ) ;
if ( V_5 -> V_8 -> V_117 ) {
F_112 ( V_5 ) ;
V_26 = F_107 ( V_5 , V_7 ) ;
if ( V_26 )
goto V_131;
}
F_79 ( V_5 -> V_81 ) ;
F_123 ( V_5 ) ;
V_130 = V_5 -> V_8 ;
V_5 -> V_8 = V_7 ;
F_81 ( V_5 -> V_81 ) ;
F_28 ( V_130 ) ;
F_83 ( V_5 ) ;
F_124 ( V_5 , L_15 , V_7 -> type -> V_13 ) ;
return 0 ;
V_131:
F_28 ( V_7 ) ;
F_111 ( V_5 ) ;
F_83 ( V_5 ) ;
return V_26 ;
}
int F_125 ( struct V_4 * V_5 , const char * V_12 )
{
char V_13 [ V_132 ] ;
struct V_11 * V_7 ;
if ( ! V_5 -> V_8 )
return - V_133 ;
F_126 ( V_13 , V_12 , sizeof( V_13 ) ) ;
V_7 = F_8 ( F_127 ( V_13 ) ) ;
if ( ! V_7 ) {
F_26 ( V_39 L_16 , V_13 ) ;
return - V_38 ;
}
if ( ! strcmp ( V_13 , V_5 -> V_8 -> type -> V_13 ) ) {
F_6 ( V_7 ) ;
return 0 ;
}
return F_122 ( V_5 , V_7 ) ;
}
T_4 F_128 ( struct V_4 * V_5 , const char * V_12 ,
T_5 V_134 )
{
int V_68 ;
if ( ! V_5 -> V_8 )
return V_134 ;
V_68 = F_125 ( V_5 , V_12 ) ;
if ( ! V_68 )
return V_134 ;
F_26 ( V_39 L_17 , V_12 ) ;
return V_68 ;
}
T_4 F_129 ( struct V_4 * V_5 , char * V_12 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_11 * V_135 ;
struct V_11 * V_136 ;
int V_137 = 0 ;
if ( ! V_5 -> V_8 || ! F_130 ( V_5 ) )
return sprintf ( V_12 , L_18 ) ;
V_135 = V_7 -> type ;
F_9 ( & V_15 ) ;
F_5 (__e, &elv_list, list) {
if ( ! strcmp ( V_135 -> V_13 , V_136 -> V_13 ) )
V_137 += sprintf ( V_12 + V_137 , L_19 , V_135 -> V_13 ) ;
else
V_137 += sprintf ( V_12 + V_137 , L_20 , V_136 -> V_13 ) ;
}
F_10 ( & V_15 ) ;
V_137 += sprintf ( V_137 + V_12 , L_21 ) ;
return V_137 ;
}
struct V_1 * F_131 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
struct V_49 * V_138 = F_132 ( & V_2 -> V_49 ) ;
if ( V_138 )
return F_133 ( V_138 ) ;
return NULL ;
}
struct V_1 * F_134 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
struct V_49 * V_139 = F_135 ( & V_2 -> V_49 ) ;
if ( V_139 )
return F_133 ( V_139 ) ;
return NULL ;
}
