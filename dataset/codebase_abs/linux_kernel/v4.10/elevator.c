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
return false ;
if ( ! F_1 ( V_2 , V_3 ) )
return false ;
return true ;
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
void F_34 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
if ( F_35 ( V_2 ) )
F_32 ( V_2 ) ;
}
void F_36 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
F_37 ( F_35 ( V_2 ) ) ;
F_38 ( V_7 -> V_25 , & V_2 -> V_25 , F_39 ( V_2 ) ) ;
V_2 -> V_37 |= V_38 ;
}
void F_40 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
F_32 ( V_2 ) ;
F_36 ( V_5 , V_2 ) ;
}
struct V_1 * F_41 ( struct V_4 * V_5 , T_2 V_39 )
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
if ( V_5 -> V_29 == V_2 )
V_5 -> V_29 = NULL ;
F_34 ( V_5 , V_2 ) ;
V_5 -> V_55 -- ;
V_52 = V_5 -> V_30 ;
F_55 (entry, &q->queue_head) {
struct V_1 * V_56 = F_56 ( V_54 ) ;
if ( F_57 ( V_2 ) != F_57 ( V_56 ) )
break;
if ( F_58 ( V_2 ) != F_58 ( V_56 ) )
break;
if ( V_56 -> V_37 & ( V_57 | V_58 ) )
break;
if ( F_46 ( V_2 ) >= V_52 ) {
if ( F_46 ( V_56 ) < V_52 )
continue;
} else {
if ( F_46 ( V_56 ) >= V_52 )
break;
}
if ( F_46 ( V_2 ) >= F_46 ( V_56 ) )
break;
}
F_59 ( & V_2 -> V_59 , V_54 ) ;
}
void F_60 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
if ( V_5 -> V_29 == V_2 )
V_5 -> V_29 = NULL ;
F_34 ( V_5 , V_2 ) ;
V_5 -> V_55 -- ;
V_5 -> V_30 = F_61 ( V_2 ) ;
V_5 -> V_31 = V_2 ;
F_62 ( & V_2 -> V_59 , & V_5 -> V_28 ) ;
}
int F_63 ( struct V_4 * V_5 , struct V_1 * * V_60 , struct V_3 * V_3 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_1 * V_47 ;
int V_61 ;
if ( F_64 ( V_5 ) || ! F_65 ( V_3 ) )
return V_62 ;
if ( V_5 -> V_29 && F_2 ( V_5 -> V_29 , V_3 ) ) {
V_61 = F_66 ( V_5 -> V_29 , V_3 ) ;
if ( V_61 != V_62 ) {
* V_60 = V_5 -> V_29 ;
return V_61 ;
}
}
if ( F_67 ( V_5 ) )
return V_62 ;
V_47 = F_41 ( V_5 , V_3 -> V_63 . V_64 ) ;
if ( V_47 && F_2 ( V_47 , V_3 ) ) {
* V_60 = V_47 ;
return V_65 ;
}
if ( V_7 -> type -> V_9 . V_66 )
return V_7 -> type -> V_9 . V_66 ( V_5 , V_60 , V_3 ) ;
return V_62 ;
}
static bool F_68 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
struct V_1 * V_47 ;
bool V_61 ;
if ( F_64 ( V_5 ) )
return false ;
if ( V_5 -> V_29 && F_69 ( V_5 , V_5 -> V_29 , V_2 ) )
return true ;
if ( F_67 ( V_5 ) )
return false ;
V_61 = false ;
while ( 1 ) {
V_47 = F_41 ( V_5 , F_46 ( V_2 ) ) ;
if ( ! V_47 || ! F_69 ( V_5 , V_47 , V_2 ) )
break;
V_61 = true ;
V_2 = V_47 ;
}
return V_61 ;
}
void F_70 ( struct V_4 * V_5 , struct V_1 * V_2 , int type )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> type -> V_9 . V_67 )
V_7 -> type -> V_9 . V_67 ( V_5 , V_2 , type ) ;
if ( type == V_65 )
F_40 ( V_5 , V_2 ) ;
V_5 -> V_29 = V_2 ;
}
void F_71 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_1 * V_41 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
const int V_68 = V_41 -> V_37 & V_69 ;
if ( V_68 && V_7 -> type -> V_9 . V_70 )
V_7 -> type -> V_9 . V_70 ( V_5 , V_2 , V_41 ) ;
F_40 ( V_5 , V_2 ) ;
if ( V_68 ) {
F_34 ( V_5 , V_41 ) ;
V_5 -> V_55 -- ;
}
V_5 -> V_29 = V_2 ;
}
void F_72 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_3 * V_3 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> type -> V_9 . V_71 )
V_7 -> type -> V_9 . V_71 ( V_5 , V_2 , V_3 ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 -> V_72 && ! ( V_2 -> V_37 & V_73 ) )
V_2 -> V_5 -> V_74 -- ;
}
static void F_74 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
if ( V_5 -> V_72 && ! ( V_2 -> V_37 & V_73 ) && V_5 -> V_74 ++ == 0 &&
( V_5 -> V_75 == V_76 || V_5 -> V_75 == V_77 ) )
F_75 ( V_5 -> V_72 ) ;
}
static inline void F_73 ( struct V_1 * V_2 ) {}
static inline void F_74 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
}
void F_76 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
if ( F_77 ( V_2 ) ) {
V_5 -> V_78 [ F_78 ( V_2 ) ] -- ;
if ( V_2 -> V_37 & V_69 )
F_79 ( V_5 , V_2 ) ;
}
V_2 -> V_37 &= ~ V_57 ;
F_73 ( V_2 ) ;
F_80 ( V_5 , V_2 , V_79 ) ;
}
void F_81 ( struct V_4 * V_5 )
{
static int V_80 ;
F_25 ( V_5 -> V_81 ) ;
while ( V_5 -> V_8 -> type -> V_9 . V_82 ( V_5 , 1 ) )
;
if ( V_5 -> V_55 && V_80 ++ < 10 ) {
F_27 ( V_33 L_6
L_7 ,
V_5 -> V_8 -> type -> V_13 , V_5 -> V_55 ) ;
}
}
void F_80 ( struct V_4 * V_5 , struct V_1 * V_2 , int V_83 )
{
F_82 ( V_5 , V_2 ) ;
F_74 ( V_5 , V_2 ) ;
V_2 -> V_5 = V_5 ;
if ( V_2 -> V_37 & V_58 ) {
if ( V_2 -> V_84 == V_85 ) {
V_5 -> V_30 = F_61 ( V_2 ) ;
V_5 -> V_31 = V_2 ;
}
} else if ( ! ( V_2 -> V_37 & V_86 ) &&
( V_83 == V_87 ||
V_83 == V_88 ) )
V_83 = V_89 ;
switch ( V_83 ) {
case V_79 :
case V_90 :
V_2 -> V_37 |= V_58 ;
F_59 ( & V_2 -> V_59 , & V_5 -> V_28 ) ;
break;
case V_89 :
V_2 -> V_37 |= V_58 ;
F_81 ( V_5 ) ;
F_62 ( & V_2 -> V_59 , & V_5 -> V_28 ) ;
F_83 ( V_5 ) ;
break;
case V_88 :
if ( F_68 ( V_5 , V_2 ) )
break;
case V_87 :
F_37 ( V_2 -> V_84 != V_85 ) ;
V_2 -> V_37 |= V_69 ;
V_5 -> V_55 ++ ;
if ( F_43 ( V_2 ) ) {
F_36 ( V_5 , V_2 ) ;
if ( ! V_5 -> V_29 )
V_5 -> V_29 = V_2 ;
}
V_5 -> V_8 -> type -> V_9 . V_91 ( V_5 , V_2 ) ;
break;
case V_92 :
V_2 -> V_37 |= V_58 ;
F_84 ( V_2 ) ;
break;
default:
F_27 ( V_33 L_8 ,
V_93 , V_83 ) ;
F_85 () ;
}
}
void F_86 ( struct V_4 * V_5 , struct V_1 * V_2 , int V_83 )
{
unsigned long V_94 ;
F_87 ( V_5 -> V_81 , V_94 ) ;
F_80 ( V_5 , V_2 , V_83 ) ;
F_88 ( V_5 -> V_81 , V_94 ) ;
}
struct V_1 * F_89 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> type -> V_9 . V_95 )
return V_7 -> type -> V_9 . V_95 ( V_5 , V_2 ) ;
return NULL ;
}
struct V_1 * F_90 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> type -> V_9 . V_96 )
return V_7 -> type -> V_9 . V_96 ( V_5 , V_2 ) ;
return NULL ;
}
int F_91 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_3 * V_3 , T_3 V_97 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> type -> V_9 . V_98 )
return V_7 -> type -> V_9 . V_98 ( V_5 , V_2 , V_3 , V_97 ) ;
return 0 ;
}
void F_92 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> type -> V_9 . V_99 )
V_7 -> type -> V_9 . V_99 ( V_2 ) ;
}
int F_93 ( struct V_4 * V_5 , unsigned int V_100 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> type -> V_9 . V_101 )
return V_7 -> type -> V_9 . V_101 ( V_5 , V_100 ) ;
return V_102 ;
}
void F_94 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( F_77 ( V_2 ) ) {
V_5 -> V_78 [ F_78 ( V_2 ) ] -- ;
if ( ( V_2 -> V_37 & V_69 ) &&
V_7 -> type -> V_9 . V_103 )
V_7 -> type -> V_9 . V_103 ( V_5 , V_2 ) ;
}
}
static T_4
F_95 ( struct V_26 * V_22 , struct V_104 * V_105 , char * V_106 )
{
struct V_107 * V_54 = F_96 ( V_105 ) ;
struct V_6 * V_7 ;
T_4 error ;
if ( ! V_54 -> V_108 )
return - V_109 ;
V_7 = F_22 ( V_22 , struct V_6 , V_22 ) ;
F_29 ( & V_7 -> V_24 ) ;
error = V_7 -> type ? V_54 -> V_108 ( V_7 , V_106 ) : - V_110 ;
F_30 ( & V_7 -> V_24 ) ;
return error ;
}
static T_4
F_97 ( struct V_26 * V_22 , struct V_104 * V_105 ,
const char * V_106 , T_5 V_111 )
{
struct V_107 * V_54 = F_96 ( V_105 ) ;
struct V_6 * V_7 ;
T_4 error ;
if ( ! V_54 -> V_112 )
return - V_109 ;
V_7 = F_22 ( V_22 , struct V_6 , V_22 ) ;
F_29 ( & V_7 -> V_24 ) ;
error = V_7 -> type ? V_54 -> V_112 ( V_7 , V_106 , V_111 ) : - V_110 ;
F_30 ( & V_7 -> V_24 ) ;
return error ;
}
int F_98 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
int error ;
error = F_99 ( & V_7 -> V_22 , & V_5 -> V_22 , L_9 , L_10 ) ;
if ( ! error ) {
struct V_107 * V_105 = V_7 -> type -> V_113 ;
if ( V_105 ) {
while ( V_105 -> V_105 . V_12 ) {
if ( F_100 ( & V_7 -> V_22 , & V_105 -> V_105 ) )
break;
V_105 ++ ;
}
}
F_101 ( & V_7 -> V_22 , V_114 ) ;
V_7 -> V_115 = 1 ;
if ( V_7 -> type -> V_9 . V_116 )
V_7 -> type -> V_9 . V_116 ( V_5 ) ;
}
return error ;
}
void F_102 ( struct V_4 * V_5 )
{
if ( V_5 ) {
struct V_6 * V_7 = V_5 -> V_8 ;
F_101 ( & V_7 -> V_22 , V_117 ) ;
F_103 ( & V_7 -> V_22 ) ;
V_7 -> V_115 = 0 ;
}
}
int F_104 ( struct V_11 * V_7 )
{
char * V_118 = L_11 ;
if ( V_7 -> V_119 ) {
if ( F_105 ( V_7 -> V_119 < sizeof( struct V_120 ) ) ||
F_105 ( V_7 -> V_121 < F_106 ( struct V_120 ) ) )
return - V_32 ;
snprintf ( V_7 -> V_122 , sizeof( V_7 -> V_122 ) ,
L_12 , V_7 -> V_13 ) ;
V_7 -> V_123 = F_107 ( V_7 -> V_122 , V_7 -> V_119 ,
V_7 -> V_121 , 0 , NULL ) ;
if ( ! V_7 -> V_123 )
return - V_124 ;
}
F_9 ( & V_16 ) ;
if ( F_4 ( V_7 -> V_13 ) ) {
F_10 ( & V_16 ) ;
if ( V_7 -> V_123 )
F_108 ( V_7 -> V_123 ) ;
return - V_125 ;
}
F_62 ( & V_7 -> V_126 , & V_127 ) ;
F_10 ( & V_16 ) ;
if ( ! strcmp ( V_7 -> V_13 , V_18 ) ||
( ! * V_18 &&
! strcmp ( V_7 -> V_13 , V_34 ) ) )
V_118 = L_13 ;
F_27 ( V_128 L_14 , V_7 -> V_13 ,
V_118 ) ;
return 0 ;
}
void F_109 ( struct V_11 * V_7 )
{
F_9 ( & V_16 ) ;
F_110 ( & V_7 -> V_126 ) ;
F_10 ( & V_16 ) ;
if ( V_7 -> V_123 ) {
F_111 () ;
F_108 ( V_7 -> V_123 ) ;
V_7 -> V_123 = NULL ;
}
}
static int F_112 ( struct V_4 * V_5 , struct V_11 * V_129 )
{
struct V_6 * V_130 = V_5 -> V_8 ;
bool V_115 = V_130 -> V_115 ;
int V_27 ;
F_113 ( V_5 ) ;
if ( V_115 )
F_102 ( V_5 ) ;
F_114 ( V_5 -> V_81 ) ;
F_115 ( V_5 ) ;
F_116 ( V_5 -> V_81 ) ;
V_27 = V_129 -> V_9 . V_35 ( V_5 , V_129 ) ;
if ( V_27 )
goto V_131;
if ( V_115 ) {
V_27 = F_98 ( V_5 ) ;
if ( V_27 )
goto V_132;
}
F_28 ( V_130 ) ;
F_117 ( V_5 ) ;
F_118 ( V_5 , L_15 , V_129 -> V_13 ) ;
return 0 ;
V_132:
F_28 ( V_5 -> V_8 ) ;
V_131:
V_5 -> V_8 = V_130 ;
F_98 ( V_5 ) ;
F_117 ( V_5 ) ;
return V_27 ;
}
static int F_119 ( struct V_4 * V_5 , const char * V_12 )
{
char V_13 [ V_133 ] ;
struct V_11 * V_7 ;
if ( ! V_5 -> V_8 )
return - V_134 ;
F_120 ( V_13 , V_12 , sizeof( V_13 ) ) ;
V_7 = F_8 ( F_121 ( V_13 ) , true ) ;
if ( ! V_7 ) {
F_27 ( V_33 L_16 , V_13 ) ;
return - V_32 ;
}
if ( ! strcmp ( V_13 , V_5 -> V_8 -> type -> V_13 ) ) {
F_6 ( V_7 ) ;
return 0 ;
}
return F_112 ( V_5 , V_7 ) ;
}
int F_122 ( struct V_4 * V_5 , const char * V_12 )
{
int V_61 ;
F_29 ( & V_5 -> V_24 ) ;
V_61 = F_119 ( V_5 , V_12 ) ;
F_30 ( & V_5 -> V_24 ) ;
return V_61 ;
}
T_4 F_123 ( struct V_4 * V_5 , const char * V_12 ,
T_5 V_135 )
{
int V_61 ;
if ( ! V_5 -> V_8 )
return V_135 ;
V_61 = F_119 ( V_5 , V_12 ) ;
if ( ! V_61 )
return V_135 ;
F_27 ( V_33 L_17 , V_12 ) ;
return V_61 ;
}
T_4 F_124 ( struct V_4 * V_5 , char * V_12 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_11 * V_136 ;
struct V_11 * V_137 ;
int V_138 = 0 ;
if ( ! V_5 -> V_8 || ! F_125 ( V_5 ) )
return sprintf ( V_12 , L_18 ) ;
V_136 = V_7 -> type ;
F_9 ( & V_16 ) ;
F_5 (__e, &elv_list, list) {
if ( ! strcmp ( V_136 -> V_13 , V_137 -> V_13 ) )
V_138 += sprintf ( V_12 + V_138 , L_19 , V_136 -> V_13 ) ;
else
V_138 += sprintf ( V_12 + V_138 , L_20 , V_137 -> V_13 ) ;
}
F_10 ( & V_16 ) ;
V_138 += sprintf ( V_138 + V_12 , L_21 ) ;
return V_138 ;
}
struct V_1 * F_126 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
struct V_44 * V_139 = F_127 ( & V_2 -> V_44 ) ;
if ( V_139 )
return F_128 ( V_139 ) ;
return NULL ;
}
struct V_1 * F_129 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
struct V_44 * V_140 = F_130 ( & V_2 -> V_44 ) ;
if ( V_140 )
return F_128 ( V_140 ) ;
return NULL ;
}
