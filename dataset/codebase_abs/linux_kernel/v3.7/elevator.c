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
static int T_1 F_13 ( char * V_16 )
{
strncpy ( V_17 , V_16 , sizeof( V_17 ) - 1 ) ;
return 1 ;
}
static struct V_6 * F_14 ( struct V_4 * V_5 ,
struct V_11 * V_7 )
{
struct V_6 * V_18 ;
int V_19 ;
V_18 = F_15 ( sizeof( * V_18 ) , V_20 | V_21 , V_5 -> V_22 ) ;
if ( F_16 ( ! V_18 ) )
goto V_23;
V_18 -> type = V_7 ;
F_17 ( & V_18 -> V_24 , & V_25 ) ;
F_18 ( & V_18 -> V_26 ) ;
V_18 -> V_27 = F_15 ( sizeof( struct V_28 ) * V_29 ,
V_20 , V_5 -> V_22 ) ;
if ( ! V_18 -> V_27 )
goto V_23;
for ( V_19 = 0 ; V_19 < V_29 ; V_19 ++ )
F_19 ( & V_18 -> V_27 [ V_19 ] ) ;
return V_18 ;
V_23:
F_20 ( V_18 ) ;
F_6 ( V_7 ) ;
return NULL ;
}
static void F_21 ( struct V_30 * V_24 )
{
struct V_6 * V_7 ;
V_7 = F_22 ( V_24 , struct V_6 , V_24 ) ;
F_6 ( V_7 -> type ) ;
F_20 ( V_7 -> V_27 ) ;
F_20 ( V_7 ) ;
}
int F_23 ( struct V_4 * V_5 , char * V_12 )
{
struct V_11 * V_7 = NULL ;
int V_23 ;
if ( F_16 ( V_5 -> V_8 ) )
return 0 ;
F_24 ( & V_5 -> V_31 ) ;
V_5 -> V_32 = NULL ;
V_5 -> V_33 = 0 ;
V_5 -> V_34 = NULL ;
if ( V_12 ) {
V_7 = F_8 ( V_12 ) ;
if ( ! V_7 )
return - V_35 ;
}
if ( ! V_7 && * V_17 ) {
V_7 = F_8 ( V_17 ) ;
if ( ! V_7 )
F_25 ( V_36 L_2 ,
V_17 ) ;
}
if ( ! V_7 ) {
V_7 = F_8 ( V_37 ) ;
if ( ! V_7 ) {
F_25 ( V_36
L_3 \
L_4 ) ;
V_7 = F_8 ( L_5 ) ;
}
}
V_5 -> V_8 = F_14 ( V_5 , V_7 ) ;
if ( ! V_5 -> V_8 )
return - V_38 ;
V_23 = V_7 -> V_9 . V_39 ( V_5 ) ;
if ( V_23 ) {
F_26 ( & V_5 -> V_8 -> V_24 ) ;
return V_23 ;
}
return 0 ;
}
void F_27 ( struct V_6 * V_7 )
{
F_28 ( & V_7 -> V_26 ) ;
if ( V_7 -> type -> V_9 . V_40 )
V_7 -> type -> V_9 . V_40 ( V_7 ) ;
F_29 ( & V_7 -> V_26 ) ;
F_26 ( & V_7 -> V_24 ) ;
}
static inline void F_30 ( struct V_1 * V_2 )
{
F_31 ( & V_2 -> V_27 ) ;
}
static void F_32 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
if ( F_33 ( V_2 ) )
F_30 ( V_2 ) ;
}
static void F_34 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
F_35 ( F_33 ( V_2 ) ) ;
F_36 ( & V_2 -> V_27 , & V_7 -> V_27 [ F_37 ( F_38 ( V_2 ) ) ] ) ;
}
static void F_39 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
F_30 ( V_2 ) ;
F_34 ( V_5 , V_2 ) ;
}
static struct V_1 * F_40 ( struct V_4 * V_5 , T_2 V_41 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_28 * V_42 = & V_7 -> V_27 [ F_37 ( V_41 ) ] ;
struct V_43 * V_44 , * V_45 ;
struct V_1 * V_2 ;
F_41 (rq, entry, next, hash_list, hash) {
F_35 ( ! F_33 ( V_2 ) ) ;
if ( F_16 ( ! F_42 ( V_2 ) ) ) {
F_30 ( V_2 ) ;
continue;
}
if ( F_38 ( V_2 ) == V_41 )
return V_2 ;
}
return NULL ;
}
void F_43 ( struct V_46 * V_47 , struct V_1 * V_2 )
{
struct V_48 * * V_49 = & V_47 -> V_48 ;
struct V_48 * V_50 = NULL ;
struct V_1 * V_51 ;
while ( * V_49 ) {
V_50 = * V_49 ;
V_51 = F_44 ( V_50 , struct V_1 , V_48 ) ;
if ( F_45 ( V_2 ) < F_45 ( V_51 ) )
V_49 = & ( * V_49 ) -> V_52 ;
else if ( F_45 ( V_2 ) >= F_45 ( V_51 ) )
V_49 = & ( * V_49 ) -> V_53 ;
}
F_46 ( & V_2 -> V_48 , V_50 , V_49 ) ;
F_47 ( & V_2 -> V_48 , V_47 ) ;
}
void F_48 ( struct V_46 * V_47 , struct V_1 * V_2 )
{
F_35 ( F_49 ( & V_2 -> V_48 ) ) ;
F_50 ( & V_2 -> V_48 , V_47 ) ;
F_51 ( & V_2 -> V_48 ) ;
}
struct V_1 * F_52 ( struct V_46 * V_47 , T_2 V_54 )
{
struct V_48 * V_55 = V_47 -> V_48 ;
struct V_1 * V_2 ;
while ( V_55 ) {
V_2 = F_44 ( V_55 , struct V_1 , V_48 ) ;
if ( V_54 < F_45 ( V_2 ) )
V_55 = V_55 -> V_52 ;
else if ( V_54 > F_45 ( V_2 ) )
V_55 = V_55 -> V_53 ;
else
return V_2 ;
}
return NULL ;
}
void F_53 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
T_2 V_56 ;
struct V_57 * V_44 ;
int V_58 ;
if ( V_5 -> V_32 == V_2 )
V_5 -> V_32 = NULL ;
F_32 ( V_5 , V_2 ) ;
V_5 -> V_59 -- ;
V_56 = V_5 -> V_33 ;
V_58 = V_60 | V_61 ;
F_54 (entry, &q->queue_head) {
struct V_1 * V_62 = F_55 ( V_44 ) ;
if ( ( V_2 -> V_63 & V_64 ) !=
( V_62 -> V_63 & V_64 ) )
break;
if ( F_56 ( V_2 ) != F_56 ( V_62 ) )
break;
if ( V_62 -> V_63 & V_58 )
break;
if ( F_45 ( V_2 ) >= V_56 ) {
if ( F_45 ( V_62 ) < V_56 )
continue;
} else {
if ( F_45 ( V_62 ) >= V_56 )
break;
}
if ( F_45 ( V_2 ) >= F_45 ( V_62 ) )
break;
}
F_57 ( & V_2 -> V_65 , V_44 ) ;
}
void F_58 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
if ( V_5 -> V_32 == V_2 )
V_5 -> V_32 = NULL ;
F_32 ( V_5 , V_2 ) ;
V_5 -> V_59 -- ;
V_5 -> V_33 = F_59 ( V_2 ) ;
V_5 -> V_34 = V_2 ;
F_60 ( & V_2 -> V_65 , & V_5 -> V_31 ) ;
}
int F_61 ( struct V_4 * V_5 , struct V_1 * * V_66 , struct V_3 * V_3 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_1 * V_51 ;
int V_67 ;
if ( F_62 ( V_5 ) )
return V_68 ;
if ( V_5 -> V_32 && F_2 ( V_5 -> V_32 , V_3 ) ) {
V_67 = F_63 ( V_5 -> V_32 , V_3 ) ;
if ( V_67 != V_68 ) {
* V_66 = V_5 -> V_32 ;
return V_67 ;
}
}
if ( F_64 ( V_5 ) )
return V_68 ;
V_51 = F_40 ( V_5 , V_3 -> V_69 ) ;
if ( V_51 && F_2 ( V_51 , V_3 ) ) {
* V_66 = V_51 ;
return V_70 ;
}
if ( V_7 -> type -> V_9 . V_71 )
return V_7 -> type -> V_9 . V_71 ( V_5 , V_66 , V_3 ) ;
return V_68 ;
}
static bool F_65 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
struct V_1 * V_51 ;
if ( F_62 ( V_5 ) )
return false ;
if ( V_5 -> V_32 && F_66 ( V_5 , V_5 -> V_32 , V_2 ) )
return true ;
if ( F_64 ( V_5 ) )
return false ;
V_51 = F_40 ( V_5 , F_45 ( V_2 ) ) ;
if ( V_51 && F_66 ( V_5 , V_51 , V_2 ) )
return true ;
return false ;
}
void F_67 ( struct V_4 * V_5 , struct V_1 * V_2 , int type )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> type -> V_9 . V_72 )
V_7 -> type -> V_9 . V_72 ( V_5 , V_2 , type ) ;
if ( type == V_70 )
F_39 ( V_5 , V_2 ) ;
V_5 -> V_32 = V_2 ;
}
void F_68 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_1 * V_45 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
const int V_73 = V_45 -> V_63 & V_74 ;
if ( V_73 && V_7 -> type -> V_9 . V_75 )
V_7 -> type -> V_9 . V_75 ( V_5 , V_2 , V_45 ) ;
F_39 ( V_5 , V_2 ) ;
if ( V_73 ) {
F_32 ( V_5 , V_45 ) ;
V_5 -> V_59 -- ;
}
V_5 -> V_32 = V_2 ;
}
void F_69 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_3 * V_3 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> type -> V_9 . V_76 )
V_7 -> type -> V_9 . V_76 ( V_5 , V_2 , V_3 ) ;
}
void F_70 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
if ( F_71 ( V_2 ) ) {
V_5 -> V_77 [ F_72 ( V_2 ) ] -- ;
if ( V_2 -> V_63 & V_74 )
F_73 ( V_5 , V_2 ) ;
}
V_2 -> V_63 &= ~ V_61 ;
F_74 ( V_5 , V_2 , V_78 ) ;
}
void F_75 ( struct V_4 * V_5 )
{
static int V_79 ;
F_76 ( V_5 -> V_80 ) ;
while ( V_5 -> V_8 -> type -> V_9 . V_81 ( V_5 , 1 ) )
;
if ( V_5 -> V_59 && V_79 ++ < 10 ) {
F_25 ( V_36 L_6
L_7 ,
V_5 -> V_8 -> type -> V_13 , V_5 -> V_59 ) ;
}
}
void F_74 ( struct V_4 * V_5 , struct V_1 * V_2 , int V_82 )
{
F_77 ( V_5 , V_2 ) ;
V_2 -> V_5 = V_5 ;
if ( V_2 -> V_63 & V_60 ) {
if ( V_2 -> V_83 == V_84 ) {
V_5 -> V_33 = F_59 ( V_2 ) ;
V_5 -> V_34 = V_2 ;
}
} else if ( ! ( V_2 -> V_63 & V_85 ) &&
( V_82 == V_86 ||
V_82 == V_87 ) )
V_82 = V_88 ;
switch ( V_82 ) {
case V_78 :
case V_89 :
V_2 -> V_63 |= V_60 ;
F_57 ( & V_2 -> V_65 , & V_5 -> V_31 ) ;
break;
case V_88 :
V_2 -> V_63 |= V_60 ;
F_75 ( V_5 ) ;
F_60 ( & V_2 -> V_65 , & V_5 -> V_31 ) ;
F_78 ( V_5 ) ;
break;
case V_87 :
if ( F_65 ( V_5 , V_2 ) )
break;
case V_86 :
F_35 ( V_2 -> V_83 != V_84 ) ;
V_2 -> V_63 |= V_74 ;
V_5 -> V_59 ++ ;
if ( F_42 ( V_2 ) ) {
F_34 ( V_5 , V_2 ) ;
if ( ! V_5 -> V_32 )
V_5 -> V_32 = V_2 ;
}
V_5 -> V_8 -> type -> V_9 . V_90 ( V_5 , V_2 ) ;
break;
case V_91 :
V_2 -> V_63 |= V_60 ;
F_79 ( V_2 ) ;
break;
default:
F_25 ( V_36 L_8 ,
V_92 , V_82 ) ;
F_80 () ;
}
}
void F_81 ( struct V_4 * V_5 , struct V_1 * V_2 , int V_82 )
{
unsigned long V_93 ;
F_82 ( V_5 -> V_80 , V_93 ) ;
F_74 ( V_5 , V_2 , V_82 ) ;
F_83 ( V_5 -> V_80 , V_93 ) ;
}
struct V_1 * F_84 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> type -> V_9 . V_94 )
return V_7 -> type -> V_9 . V_94 ( V_5 , V_2 ) ;
return NULL ;
}
struct V_1 * F_85 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> type -> V_9 . V_95 )
return V_7 -> type -> V_9 . V_95 ( V_5 , V_2 ) ;
return NULL ;
}
int F_86 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_3 * V_3 , T_3 V_96 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> type -> V_9 . V_97 )
return V_7 -> type -> V_9 . V_97 ( V_5 , V_2 , V_3 , V_96 ) ;
return 0 ;
}
void F_87 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> type -> V_9 . V_98 )
V_7 -> type -> V_9 . V_98 ( V_2 ) ;
}
int F_88 ( struct V_4 * V_5 , int V_99 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> type -> V_9 . V_100 )
return V_7 -> type -> V_9 . V_100 ( V_5 , V_99 ) ;
return V_101 ;
}
void F_89 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
F_90 ( V_5 ) ;
while ( ! F_91 ( & V_5 -> V_31 ) ) {
V_2 = F_55 ( V_5 -> V_31 . V_45 ) ;
V_2 -> V_63 |= V_102 ;
F_92 ( V_5 , V_2 ) ;
F_93 ( V_2 ) ;
F_94 ( V_2 , - V_103 ) ;
}
}
void F_95 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( F_71 ( V_2 ) ) {
V_5 -> V_77 [ F_72 ( V_2 ) ] -- ;
if ( ( V_2 -> V_63 & V_74 ) &&
V_7 -> type -> V_9 . V_104 )
V_7 -> type -> V_9 . V_104 ( V_5 , V_2 ) ;
}
}
static T_4
F_96 ( struct V_30 * V_24 , struct V_105 * V_106 , char * V_107 )
{
struct V_108 * V_44 = F_97 ( V_106 ) ;
struct V_6 * V_7 ;
T_4 error ;
if ( ! V_44 -> V_109 )
return - V_103 ;
V_7 = F_22 ( V_24 , struct V_6 , V_24 ) ;
F_28 ( & V_7 -> V_26 ) ;
error = V_7 -> type ? V_44 -> V_109 ( V_7 , V_107 ) : - V_110 ;
F_29 ( & V_7 -> V_26 ) ;
return error ;
}
static T_4
F_98 ( struct V_30 * V_24 , struct V_105 * V_106 ,
const char * V_107 , T_5 V_111 )
{
struct V_108 * V_44 = F_97 ( V_106 ) ;
struct V_6 * V_7 ;
T_4 error ;
if ( ! V_44 -> V_112 )
return - V_103 ;
V_7 = F_22 ( V_24 , struct V_6 , V_24 ) ;
F_28 ( & V_7 -> V_26 ) ;
error = V_7 -> type ? V_44 -> V_112 ( V_7 , V_107 , V_111 ) : - V_110 ;
F_29 ( & V_7 -> V_26 ) ;
return error ;
}
int F_99 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
int error ;
error = F_100 ( & V_7 -> V_24 , & V_5 -> V_24 , L_9 , L_10 ) ;
if ( ! error ) {
struct V_108 * V_106 = V_7 -> type -> V_113 ;
if ( V_106 ) {
while ( V_106 -> V_106 . V_12 ) {
if ( F_101 ( & V_7 -> V_24 , & V_106 -> V_106 ) )
break;
V_106 ++ ;
}
}
F_102 ( & V_7 -> V_24 , V_114 ) ;
V_7 -> V_115 = 1 ;
}
return error ;
}
void F_103 ( struct V_4 * V_5 )
{
if ( V_5 ) {
struct V_6 * V_7 = V_5 -> V_8 ;
F_102 ( & V_7 -> V_24 , V_116 ) ;
F_104 ( & V_7 -> V_24 ) ;
V_7 -> V_115 = 0 ;
}
}
int F_105 ( struct V_11 * V_7 )
{
char * V_117 = L_11 ;
if ( V_7 -> V_118 ) {
if ( F_106 ( V_7 -> V_118 < sizeof( struct V_119 ) ) ||
F_106 ( V_7 -> V_120 < F_107 ( struct V_119 ) ) )
return - V_35 ;
snprintf ( V_7 -> V_121 , sizeof( V_7 -> V_121 ) ,
L_12 , V_7 -> V_13 ) ;
V_7 -> V_122 = F_108 ( V_7 -> V_121 , V_7 -> V_118 ,
V_7 -> V_120 , 0 , NULL ) ;
if ( ! V_7 -> V_122 )
return - V_38 ;
}
F_9 ( & V_15 ) ;
if ( F_4 ( V_7 -> V_13 ) ) {
F_10 ( & V_15 ) ;
if ( V_7 -> V_122 )
F_109 ( V_7 -> V_122 ) ;
return - V_123 ;
}
F_60 ( & V_7 -> V_124 , & V_125 ) ;
F_10 ( & V_15 ) ;
if ( ! strcmp ( V_7 -> V_13 , V_17 ) ||
( ! * V_17 &&
! strcmp ( V_7 -> V_13 , V_37 ) ) )
V_117 = L_13 ;
F_25 ( V_126 L_14 , V_7 -> V_13 ,
V_117 ) ;
return 0 ;
}
void F_110 ( struct V_11 * V_7 )
{
F_9 ( & V_15 ) ;
F_111 ( & V_7 -> V_124 ) ;
F_10 ( & V_15 ) ;
if ( V_7 -> V_122 ) {
F_112 () ;
F_109 ( V_7 -> V_122 ) ;
V_7 -> V_122 = NULL ;
}
}
static int F_113 ( struct V_4 * V_5 , struct V_11 * V_127 )
{
struct V_6 * V_128 = V_5 -> V_8 ;
bool V_115 = V_128 -> V_115 ;
int V_23 ;
F_114 ( V_5 ) ;
if ( V_115 )
F_103 ( V_5 ) ;
F_115 ( V_5 -> V_80 ) ;
F_116 ( V_5 ) ;
F_117 ( V_5 -> V_80 ) ;
V_23 = - V_38 ;
V_5 -> V_8 = F_14 ( V_5 , V_127 ) ;
if ( ! V_5 -> V_8 )
goto V_129;
V_23 = V_127 -> V_9 . V_39 ( V_5 ) ;
if ( V_23 ) {
F_26 ( & V_5 -> V_8 -> V_24 ) ;
goto V_129;
}
if ( V_115 ) {
V_23 = F_99 ( V_5 ) ;
if ( V_23 )
goto V_130;
}
F_27 ( V_128 ) ;
F_118 ( V_5 ) ;
F_119 ( V_5 , L_15 , V_127 -> V_13 ) ;
return 0 ;
V_130:
F_27 ( V_5 -> V_8 ) ;
V_129:
V_5 -> V_8 = V_128 ;
F_99 ( V_5 ) ;
F_118 ( V_5 ) ;
return V_23 ;
}
int F_120 ( struct V_4 * V_5 , const char * V_12 )
{
char V_13 [ V_131 ] ;
struct V_11 * V_7 ;
if ( ! V_5 -> V_8 )
return - V_132 ;
F_121 ( V_13 , V_12 , sizeof( V_13 ) ) ;
V_7 = F_8 ( F_122 ( V_13 ) ) ;
if ( ! V_7 ) {
F_25 ( V_36 L_16 , V_13 ) ;
return - V_35 ;
}
if ( ! strcmp ( V_13 , V_5 -> V_8 -> type -> V_13 ) ) {
F_6 ( V_7 ) ;
return 0 ;
}
return F_113 ( V_5 , V_7 ) ;
}
T_4 F_123 ( struct V_4 * V_5 , const char * V_12 ,
T_5 V_133 )
{
int V_67 ;
if ( ! V_5 -> V_8 )
return V_133 ;
V_67 = F_120 ( V_5 , V_12 ) ;
if ( ! V_67 )
return V_133 ;
F_25 ( V_36 L_17 , V_12 ) ;
return V_67 ;
}
T_4 F_124 ( struct V_4 * V_5 , char * V_12 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_11 * V_134 ;
struct V_11 * V_135 ;
int V_136 = 0 ;
if ( ! V_5 -> V_8 || ! F_125 ( V_5 ) )
return sprintf ( V_12 , L_18 ) ;
V_134 = V_7 -> type ;
F_9 ( & V_15 ) ;
F_5 (__e, &elv_list, list) {
if ( ! strcmp ( V_134 -> V_13 , V_135 -> V_13 ) )
V_136 += sprintf ( V_12 + V_136 , L_19 , V_134 -> V_13 ) ;
else
V_136 += sprintf ( V_12 + V_136 , L_20 , V_135 -> V_13 ) ;
}
F_10 ( & V_15 ) ;
V_136 += sprintf ( V_136 + V_12 , L_21 ) ;
return V_136 ;
}
struct V_1 * F_126 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
struct V_48 * V_137 = F_127 ( & V_2 -> V_48 ) ;
if ( V_137 )
return F_128 ( V_137 ) ;
return NULL ;
}
struct V_1 * F_129 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
struct V_48 * V_138 = F_130 ( & V_2 -> V_48 ) ;
if ( V_138 )
return F_128 ( V_138 ) ;
return NULL ;
}
