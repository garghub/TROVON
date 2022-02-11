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
static struct V_11 * F_8 ( const char * V_12 , bool V_15 )
{
struct V_11 * V_7 ;
F_9 ( & V_16 ) ;
V_7 = F_4 ( V_12 ) ;
if ( ! V_7 && V_15 ) {
F_10 ( & V_16 ) ;
F_11 ( L_1 , V_12 ) ;
F_9 ( & V_16 ) ;
V_7 = F_4 ( V_12 ) ;
}
if ( V_7 && ! F_12 ( V_7 -> V_14 ) )
V_7 = NULL ;
F_10 ( & V_16 ) ;
return V_7 ;
}
static int T_1 F_13 ( char * V_17 )
{
strncpy ( V_18 , V_17 , sizeof( V_18 ) - 1 ) ;
return 1 ;
}
void T_1 F_14 ( void )
{
struct V_11 * V_7 ;
if ( ! V_18 [ 0 ] )
return;
F_9 ( & V_16 ) ;
V_7 = F_4 ( V_18 ) ;
F_10 ( & V_16 ) ;
if ( ! V_7 )
F_11 ( L_1 , V_18 ) ;
}
struct V_6 * F_15 ( struct V_4 * V_5 ,
struct V_11 * V_7 )
{
struct V_6 * V_19 ;
V_19 = F_16 ( sizeof( * V_19 ) , V_20 , V_5 -> V_21 ) ;
if ( F_17 ( ! V_19 ) )
return NULL ;
V_19 -> type = V_7 ;
F_18 ( & V_19 -> V_22 , & V_23 ) ;
F_19 ( & V_19 -> V_24 ) ;
F_20 ( V_19 -> V_25 ) ;
return V_19 ;
}
static void F_21 ( struct V_26 * V_22 )
{
struct V_6 * V_7 ;
V_7 = F_22 ( V_22 , struct V_6 , V_22 ) ;
F_6 ( V_7 -> type ) ;
F_23 ( V_7 ) ;
}
int F_24 ( struct V_4 * V_5 , char * V_12 )
{
struct V_11 * V_7 = NULL ;
int V_27 ;
F_25 ( & V_5 -> V_24 ) ;
if ( F_17 ( V_5 -> V_8 ) )
return 0 ;
F_26 ( & V_5 -> V_28 ) ;
V_5 -> V_29 = NULL ;
V_5 -> V_30 = 0 ;
V_5 -> V_31 = NULL ;
if ( V_12 ) {
V_7 = F_8 ( V_12 , true ) ;
if ( ! V_7 )
return - V_32 ;
}
if ( ! V_7 && * V_18 ) {
V_7 = F_8 ( V_18 , false ) ;
if ( ! V_7 )
F_27 ( V_33 L_2 ,
V_18 ) ;
}
if ( ! V_7 ) {
V_7 = F_8 ( V_34 , false ) ;
if ( ! V_7 ) {
F_27 ( V_33
L_3 \
L_4 ) ;
V_7 = F_8 ( L_5 , false ) ;
}
}
V_27 = V_7 -> V_9 . V_35 ( V_5 , V_7 ) ;
if ( V_27 )
F_6 ( V_7 ) ;
return V_27 ;
}
void F_28 ( struct V_6 * V_7 )
{
F_29 ( & V_7 -> V_24 ) ;
if ( V_7 -> type -> V_9 . V_36 )
V_7 -> type -> V_9 . V_36 ( V_7 ) ;
F_30 ( & V_7 -> V_24 ) ;
F_31 ( & V_7 -> V_22 ) ;
}
static inline void F_32 ( struct V_1 * V_2 )
{
F_33 ( & V_2 -> V_25 ) ;
V_2 -> V_37 &= ~ V_38 ;
}
static void F_34 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
if ( F_35 ( V_2 ) )
F_32 ( V_2 ) ;
}
static void F_36 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
F_37 ( F_35 ( V_2 ) ) ;
F_38 ( V_7 -> V_25 , & V_2 -> V_25 , F_39 ( V_2 ) ) ;
V_2 -> V_37 |= V_38 ;
}
static void F_40 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
F_32 ( V_2 ) ;
F_36 ( V_5 , V_2 ) ;
}
static struct V_1 * F_41 ( struct V_4 * V_5 , T_2 V_39 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_40 * V_41 ;
struct V_1 * V_2 ;
F_42 (e->hash, rq, next, hash, offset) {
F_37 ( ! F_35 ( V_2 ) ) ;
if ( F_17 ( ! F_43 ( V_2 ) ) ) {
F_32 ( V_2 ) ;
continue;
}
if ( F_39 ( V_2 ) == V_39 )
return V_2 ;
}
return NULL ;
}
void F_44 ( struct V_42 * V_43 , struct V_1 * V_2 )
{
struct V_44 * * V_45 = & V_43 -> V_44 ;
struct V_44 * V_46 = NULL ;
struct V_1 * V_47 ;
while ( * V_45 ) {
V_46 = * V_45 ;
V_47 = F_45 ( V_46 , struct V_1 , V_44 ) ;
if ( F_46 ( V_2 ) < F_46 ( V_47 ) )
V_45 = & ( * V_45 ) -> V_48 ;
else if ( F_46 ( V_2 ) >= F_46 ( V_47 ) )
V_45 = & ( * V_45 ) -> V_49 ;
}
F_47 ( & V_2 -> V_44 , V_46 , V_45 ) ;
F_48 ( & V_2 -> V_44 , V_43 ) ;
}
void F_49 ( struct V_42 * V_43 , struct V_1 * V_2 )
{
F_37 ( F_50 ( & V_2 -> V_44 ) ) ;
F_51 ( & V_2 -> V_44 , V_43 ) ;
F_52 ( & V_2 -> V_44 ) ;
}
struct V_1 * F_53 ( struct V_42 * V_43 , T_2 V_50 )
{
struct V_44 * V_51 = V_43 -> V_44 ;
struct V_1 * V_2 ;
while ( V_51 ) {
V_2 = F_45 ( V_51 , struct V_1 , V_44 ) ;
if ( V_50 < F_46 ( V_2 ) )
V_51 = V_51 -> V_48 ;
else if ( V_50 > F_46 ( V_2 ) )
V_51 = V_51 -> V_49 ;
else
return V_2 ;
}
return NULL ;
}
void F_54 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
T_2 V_52 ;
struct V_53 * V_54 ;
int V_55 ;
if ( V_5 -> V_29 == V_2 )
V_5 -> V_29 = NULL ;
F_34 ( V_5 , V_2 ) ;
V_5 -> V_56 -- ;
V_52 = V_5 -> V_30 ;
V_55 = V_57 | V_58 ;
F_55 (entry, &q->queue_head) {
struct V_1 * V_59 = F_56 ( V_54 ) ;
if ( ( V_2 -> V_37 & V_60 ) !=
( V_59 -> V_37 & V_60 ) )
break;
if ( F_57 ( V_2 ) != F_57 ( V_59 ) )
break;
if ( V_59 -> V_37 & V_55 )
break;
if ( F_46 ( V_2 ) >= V_52 ) {
if ( F_46 ( V_59 ) < V_52 )
continue;
} else {
if ( F_46 ( V_59 ) >= V_52 )
break;
}
if ( F_46 ( V_2 ) >= F_46 ( V_59 ) )
break;
}
F_58 ( & V_2 -> V_61 , V_54 ) ;
}
void F_59 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
if ( V_5 -> V_29 == V_2 )
V_5 -> V_29 = NULL ;
F_34 ( V_5 , V_2 ) ;
V_5 -> V_56 -- ;
V_5 -> V_30 = F_60 ( V_2 ) ;
V_5 -> V_31 = V_2 ;
F_61 ( & V_2 -> V_61 , & V_5 -> V_28 ) ;
}
int F_62 ( struct V_4 * V_5 , struct V_1 * * V_62 , struct V_3 * V_3 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_1 * V_47 ;
int V_63 ;
if ( F_63 ( V_5 ) || ! F_64 ( V_3 ) )
return V_64 ;
if ( V_5 -> V_29 && F_2 ( V_5 -> V_29 , V_3 ) ) {
V_63 = F_65 ( V_5 -> V_29 , V_3 ) ;
if ( V_63 != V_64 ) {
* V_62 = V_5 -> V_29 ;
return V_63 ;
}
}
if ( F_66 ( V_5 ) )
return V_64 ;
V_47 = F_41 ( V_5 , V_3 -> V_65 . V_66 ) ;
if ( V_47 && F_2 ( V_47 , V_3 ) ) {
* V_62 = V_47 ;
return V_67 ;
}
if ( V_7 -> type -> V_9 . V_68 )
return V_7 -> type -> V_9 . V_68 ( V_5 , V_62 , V_3 ) ;
return V_64 ;
}
static bool F_67 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
struct V_1 * V_47 ;
bool V_63 ;
if ( F_63 ( V_5 ) )
return false ;
if ( V_5 -> V_29 && F_68 ( V_5 , V_5 -> V_29 , V_2 ) )
return true ;
if ( F_66 ( V_5 ) )
return false ;
V_63 = false ;
while ( 1 ) {
V_47 = F_41 ( V_5 , F_46 ( V_2 ) ) ;
if ( ! V_47 || ! F_68 ( V_5 , V_47 , V_2 ) )
break;
V_63 = true ;
V_2 = V_47 ;
}
return V_63 ;
}
void F_69 ( struct V_4 * V_5 , struct V_1 * V_2 , int type )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> type -> V_9 . V_69 )
V_7 -> type -> V_9 . V_69 ( V_5 , V_2 , type ) ;
if ( type == V_67 )
F_40 ( V_5 , V_2 ) ;
V_5 -> V_29 = V_2 ;
}
void F_70 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_1 * V_41 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
const int V_70 = V_41 -> V_37 & V_71 ;
if ( V_70 && V_7 -> type -> V_9 . V_72 )
V_7 -> type -> V_9 . V_72 ( V_5 , V_2 , V_41 ) ;
F_40 ( V_5 , V_2 ) ;
if ( V_70 ) {
F_34 ( V_5 , V_41 ) ;
V_5 -> V_56 -- ;
}
V_5 -> V_29 = V_2 ;
}
void F_71 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_3 * V_3 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> type -> V_9 . V_73 )
V_7 -> type -> V_9 . V_73 ( V_5 , V_2 , V_3 ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 -> V_74 && ! ( V_2 -> V_37 & V_75 ) )
V_2 -> V_5 -> V_76 -- ;
}
static void F_73 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
if ( V_5 -> V_74 && ! ( V_2 -> V_37 & V_75 ) && V_5 -> V_76 ++ == 0 &&
( V_5 -> V_77 == V_78 || V_5 -> V_77 == V_79 ) )
F_74 ( V_5 -> V_74 ) ;
}
static inline void F_72 ( struct V_1 * V_2 ) {}
static inline void F_73 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
}
void F_75 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
if ( F_76 ( V_2 ) ) {
V_5 -> V_80 [ F_77 ( V_2 ) ] -- ;
if ( V_2 -> V_37 & V_71 )
F_78 ( V_5 , V_2 ) ;
}
V_2 -> V_37 &= ~ V_58 ;
F_72 ( V_2 ) ;
F_79 ( V_5 , V_2 , V_81 ) ;
}
void F_80 ( struct V_4 * V_5 )
{
static int V_82 ;
F_25 ( V_5 -> V_83 ) ;
while ( V_5 -> V_8 -> type -> V_9 . V_84 ( V_5 , 1 ) )
;
if ( V_5 -> V_56 && V_82 ++ < 10 ) {
F_27 ( V_33 L_6
L_7 ,
V_5 -> V_8 -> type -> V_13 , V_5 -> V_56 ) ;
}
}
void F_79 ( struct V_4 * V_5 , struct V_1 * V_2 , int V_85 )
{
F_81 ( V_5 , V_2 ) ;
F_73 ( V_5 , V_2 ) ;
V_2 -> V_5 = V_5 ;
if ( V_2 -> V_37 & V_57 ) {
if ( V_2 -> V_86 == V_87 ) {
V_5 -> V_30 = F_60 ( V_2 ) ;
V_5 -> V_31 = V_2 ;
}
} else if ( ! ( V_2 -> V_37 & V_88 ) &&
( V_85 == V_89 ||
V_85 == V_90 ) )
V_85 = V_91 ;
switch ( V_85 ) {
case V_81 :
case V_92 :
V_2 -> V_37 |= V_57 ;
F_58 ( & V_2 -> V_61 , & V_5 -> V_28 ) ;
break;
case V_91 :
V_2 -> V_37 |= V_57 ;
F_80 ( V_5 ) ;
F_61 ( & V_2 -> V_61 , & V_5 -> V_28 ) ;
F_82 ( V_5 ) ;
break;
case V_90 :
if ( F_67 ( V_5 , V_2 ) )
break;
case V_89 :
F_37 ( V_2 -> V_86 != V_87 ) ;
V_2 -> V_37 |= V_71 ;
V_5 -> V_56 ++ ;
if ( F_43 ( V_2 ) ) {
F_36 ( V_5 , V_2 ) ;
if ( ! V_5 -> V_29 )
V_5 -> V_29 = V_2 ;
}
V_5 -> V_8 -> type -> V_9 . V_93 ( V_5 , V_2 ) ;
break;
case V_94 :
V_2 -> V_37 |= V_57 ;
F_83 ( V_2 ) ;
break;
default:
F_27 ( V_33 L_8 ,
V_95 , V_85 ) ;
F_84 () ;
}
}
void F_85 ( struct V_4 * V_5 , struct V_1 * V_2 , int V_85 )
{
unsigned long V_96 ;
F_86 ( V_5 -> V_83 , V_96 ) ;
F_79 ( V_5 , V_2 , V_85 ) ;
F_87 ( V_5 -> V_83 , V_96 ) ;
}
struct V_1 * F_88 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> type -> V_9 . V_97 )
return V_7 -> type -> V_9 . V_97 ( V_5 , V_2 ) ;
return NULL ;
}
struct V_1 * F_89 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> type -> V_9 . V_98 )
return V_7 -> type -> V_9 . V_98 ( V_5 , V_2 ) ;
return NULL ;
}
int F_90 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_3 * V_3 , T_3 V_99 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> type -> V_9 . V_100 )
return V_7 -> type -> V_9 . V_100 ( V_5 , V_2 , V_3 , V_99 ) ;
return 0 ;
}
void F_91 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> type -> V_9 . V_101 )
V_7 -> type -> V_9 . V_101 ( V_2 ) ;
}
int F_92 ( struct V_4 * V_5 , int V_102 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> type -> V_9 . V_103 )
return V_7 -> type -> V_9 . V_103 ( V_5 , V_102 ) ;
return V_104 ;
}
void F_93 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( F_76 ( V_2 ) ) {
V_5 -> V_80 [ F_77 ( V_2 ) ] -- ;
if ( ( V_2 -> V_37 & V_71 ) &&
V_7 -> type -> V_9 . V_105 )
V_7 -> type -> V_9 . V_105 ( V_5 , V_2 ) ;
}
}
static T_4
F_94 ( struct V_26 * V_22 , struct V_106 * V_107 , char * V_108 )
{
struct V_109 * V_54 = F_95 ( V_107 ) ;
struct V_6 * V_7 ;
T_4 error ;
if ( ! V_54 -> V_110 )
return - V_111 ;
V_7 = F_22 ( V_22 , struct V_6 , V_22 ) ;
F_29 ( & V_7 -> V_24 ) ;
error = V_7 -> type ? V_54 -> V_110 ( V_7 , V_108 ) : - V_112 ;
F_30 ( & V_7 -> V_24 ) ;
return error ;
}
static T_4
F_96 ( struct V_26 * V_22 , struct V_106 * V_107 ,
const char * V_108 , T_5 V_113 )
{
struct V_109 * V_54 = F_95 ( V_107 ) ;
struct V_6 * V_7 ;
T_4 error ;
if ( ! V_54 -> V_114 )
return - V_111 ;
V_7 = F_22 ( V_22 , struct V_6 , V_22 ) ;
F_29 ( & V_7 -> V_24 ) ;
error = V_7 -> type ? V_54 -> V_114 ( V_7 , V_108 , V_113 ) : - V_112 ;
F_30 ( & V_7 -> V_24 ) ;
return error ;
}
int F_97 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
int error ;
error = F_98 ( & V_7 -> V_22 , & V_5 -> V_22 , L_9 , L_10 ) ;
if ( ! error ) {
struct V_109 * V_107 = V_7 -> type -> V_115 ;
if ( V_107 ) {
while ( V_107 -> V_107 . V_12 ) {
if ( F_99 ( & V_7 -> V_22 , & V_107 -> V_107 ) )
break;
V_107 ++ ;
}
}
F_100 ( & V_7 -> V_22 , V_116 ) ;
V_7 -> V_117 = 1 ;
if ( V_7 -> type -> V_9 . V_118 )
V_7 -> type -> V_9 . V_118 ( V_5 ) ;
}
return error ;
}
void F_101 ( struct V_4 * V_5 )
{
if ( V_5 ) {
struct V_6 * V_7 = V_5 -> V_8 ;
F_100 ( & V_7 -> V_22 , V_119 ) ;
F_102 ( & V_7 -> V_22 ) ;
V_7 -> V_117 = 0 ;
}
}
int F_103 ( struct V_11 * V_7 )
{
char * V_120 = L_11 ;
if ( V_7 -> V_121 ) {
if ( F_104 ( V_7 -> V_121 < sizeof( struct V_122 ) ) ||
F_104 ( V_7 -> V_123 < F_105 ( struct V_122 ) ) )
return - V_32 ;
snprintf ( V_7 -> V_124 , sizeof( V_7 -> V_124 ) ,
L_12 , V_7 -> V_13 ) ;
V_7 -> V_125 = F_106 ( V_7 -> V_124 , V_7 -> V_121 ,
V_7 -> V_123 , 0 , NULL ) ;
if ( ! V_7 -> V_125 )
return - V_126 ;
}
F_9 ( & V_16 ) ;
if ( F_4 ( V_7 -> V_13 ) ) {
F_10 ( & V_16 ) ;
if ( V_7 -> V_125 )
F_107 ( V_7 -> V_125 ) ;
return - V_127 ;
}
F_61 ( & V_7 -> V_128 , & V_129 ) ;
F_10 ( & V_16 ) ;
if ( ! strcmp ( V_7 -> V_13 , V_18 ) ||
( ! * V_18 &&
! strcmp ( V_7 -> V_13 , V_34 ) ) )
V_120 = L_13 ;
F_27 ( V_130 L_14 , V_7 -> V_13 ,
V_120 ) ;
return 0 ;
}
void F_108 ( struct V_11 * V_7 )
{
F_9 ( & V_16 ) ;
F_109 ( & V_7 -> V_128 ) ;
F_10 ( & V_16 ) ;
if ( V_7 -> V_125 ) {
F_110 () ;
F_107 ( V_7 -> V_125 ) ;
V_7 -> V_125 = NULL ;
}
}
static int F_111 ( struct V_4 * V_5 , struct V_11 * V_131 )
{
struct V_6 * V_132 = V_5 -> V_8 ;
bool V_117 = V_132 -> V_117 ;
int V_27 ;
F_112 ( V_5 ) ;
if ( V_117 )
F_101 ( V_5 ) ;
F_113 ( V_5 -> V_83 ) ;
F_114 ( V_5 ) ;
F_115 ( V_5 -> V_83 ) ;
V_27 = V_131 -> V_9 . V_35 ( V_5 , V_131 ) ;
if ( V_27 )
goto V_133;
if ( V_117 ) {
V_27 = F_97 ( V_5 ) ;
if ( V_27 )
goto V_134;
}
F_28 ( V_132 ) ;
F_116 ( V_5 ) ;
F_117 ( V_5 , L_15 , V_131 -> V_13 ) ;
return 0 ;
V_134:
F_28 ( V_5 -> V_8 ) ;
V_133:
V_5 -> V_8 = V_132 ;
F_97 ( V_5 ) ;
F_116 ( V_5 ) ;
return V_27 ;
}
static int F_118 ( struct V_4 * V_5 , const char * V_12 )
{
char V_13 [ V_135 ] ;
struct V_11 * V_7 ;
if ( ! V_5 -> V_8 )
return - V_136 ;
F_119 ( V_13 , V_12 , sizeof( V_13 ) ) ;
V_7 = F_8 ( F_120 ( V_13 ) , true ) ;
if ( ! V_7 ) {
F_27 ( V_33 L_16 , V_13 ) ;
return - V_32 ;
}
if ( ! strcmp ( V_13 , V_5 -> V_8 -> type -> V_13 ) ) {
F_6 ( V_7 ) ;
return 0 ;
}
return F_111 ( V_5 , V_7 ) ;
}
int F_121 ( struct V_4 * V_5 , const char * V_12 )
{
int V_63 ;
F_29 ( & V_5 -> V_24 ) ;
V_63 = F_118 ( V_5 , V_12 ) ;
F_30 ( & V_5 -> V_24 ) ;
return V_63 ;
}
T_4 F_122 ( struct V_4 * V_5 , const char * V_12 ,
T_5 V_137 )
{
int V_63 ;
if ( ! V_5 -> V_8 )
return V_137 ;
V_63 = F_118 ( V_5 , V_12 ) ;
if ( ! V_63 )
return V_137 ;
F_27 ( V_33 L_17 , V_12 ) ;
return V_63 ;
}
T_4 F_123 ( struct V_4 * V_5 , char * V_12 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_11 * V_138 ;
struct V_11 * V_139 ;
int V_140 = 0 ;
if ( ! V_5 -> V_8 || ! F_124 ( V_5 ) )
return sprintf ( V_12 , L_18 ) ;
V_138 = V_7 -> type ;
F_9 ( & V_16 ) ;
F_5 (__e, &elv_list, list) {
if ( ! strcmp ( V_138 -> V_13 , V_139 -> V_13 ) )
V_140 += sprintf ( V_12 + V_140 , L_19 , V_138 -> V_13 ) ;
else
V_140 += sprintf ( V_12 + V_140 , L_20 , V_139 -> V_13 ) ;
}
F_10 ( & V_16 ) ;
V_140 += sprintf ( V_140 + V_12 , L_21 ) ;
return V_140 ;
}
struct V_1 * F_125 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
struct V_44 * V_141 = F_126 ( & V_2 -> V_44 ) ;
if ( V_141 )
return F_127 ( V_141 ) ;
return NULL ;
}
struct V_1 * F_128 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
struct V_44 * V_142 = F_129 ( & V_2 -> V_44 ) ;
if ( V_142 )
return F_127 ( V_142 ) ;
return NULL ;
}
