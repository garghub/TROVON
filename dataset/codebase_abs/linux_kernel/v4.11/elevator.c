static int F_1 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> V_9 && V_7 -> type -> V_10 . V_11 . V_12 )
return V_7 -> type -> V_10 . V_11 . V_12 ( V_5 , V_2 , V_3 ) ;
else if ( ! V_7 -> V_9 && V_7 -> type -> V_10 . V_13 . V_14 )
return V_7 -> type -> V_10 . V_13 . V_14 ( V_5 , V_2 , V_3 ) ;
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
static struct V_15 * F_4 ( const char * V_16 )
{
struct V_15 * V_7 ;
F_5 (e, &elv_list, list) {
if ( ! strcmp ( V_7 -> V_17 , V_16 ) )
return V_7 ;
}
return NULL ;
}
static void F_6 ( struct V_15 * V_7 )
{
F_7 ( V_7 -> V_18 ) ;
}
static struct V_15 * F_8 ( const char * V_16 , bool V_19 )
{
struct V_15 * V_7 ;
F_9 ( & V_20 ) ;
V_7 = F_4 ( V_16 ) ;
if ( ! V_7 && V_19 ) {
F_10 ( & V_20 ) ;
F_11 ( L_1 , V_16 ) ;
F_9 ( & V_20 ) ;
V_7 = F_4 ( V_16 ) ;
}
if ( V_7 && ! F_12 ( V_7 -> V_18 ) )
V_7 = NULL ;
F_10 ( & V_20 ) ;
return V_7 ;
}
static int T_1 F_13 ( char * V_21 )
{
strncpy ( V_22 , V_21 , sizeof( V_22 ) - 1 ) ;
return 1 ;
}
void T_1 F_14 ( void )
{
struct V_15 * V_7 ;
if ( ! V_22 [ 0 ] )
return;
F_9 ( & V_20 ) ;
V_7 = F_4 ( V_22 ) ;
F_10 ( & V_20 ) ;
if ( ! V_7 )
F_11 ( L_1 , V_22 ) ;
}
struct V_6 * F_15 ( struct V_4 * V_5 ,
struct V_15 * V_7 )
{
struct V_6 * V_23 ;
V_23 = F_16 ( sizeof( * V_23 ) , V_24 , V_5 -> V_25 ) ;
if ( F_17 ( ! V_23 ) )
return NULL ;
V_23 -> type = V_7 ;
F_18 ( & V_23 -> V_26 , & V_27 ) ;
F_19 ( & V_23 -> V_28 ) ;
F_20 ( V_23 -> V_29 ) ;
V_23 -> V_9 = V_7 -> V_9 ;
return V_23 ;
}
static void F_21 ( struct V_30 * V_26 )
{
struct V_6 * V_7 ;
V_7 = F_22 ( V_26 , struct V_6 , V_26 ) ;
F_6 ( V_7 -> type ) ;
F_23 ( V_7 ) ;
}
int F_24 ( struct V_4 * V_5 , char * V_16 )
{
struct V_15 * V_7 = NULL ;
int V_31 ;
F_25 ( & V_5 -> V_28 ) ;
if ( F_17 ( V_5 -> V_8 ) )
return 0 ;
F_26 ( & V_5 -> V_32 ) ;
V_5 -> V_33 = NULL ;
V_5 -> V_34 = 0 ;
V_5 -> V_35 = NULL ;
if ( V_16 ) {
V_7 = F_8 ( V_16 , true ) ;
if ( ! V_7 )
return - V_36 ;
}
if ( ! V_7 && ! V_5 -> V_37 && * V_22 ) {
V_7 = F_8 ( V_22 , false ) ;
if ( ! V_7 )
F_27 ( V_38 L_2 ,
V_22 ) ;
}
if ( ! V_7 ) {
if ( V_5 -> V_37 ) {
if ( V_5 -> V_39 == 1 )
V_7 = F_8 ( L_3 , false ) ;
if ( ! V_7 )
return 0 ;
} else
V_7 = F_8 ( V_40 , false ) ;
if ( ! V_7 ) {
F_27 ( V_38
L_4 \
L_5 ) ;
V_7 = F_8 ( L_6 , false ) ;
}
}
if ( V_7 -> V_9 )
V_31 = F_28 ( V_5 , V_7 ) ;
else
V_31 = V_7 -> V_10 . V_13 . V_41 ( V_5 , V_7 ) ;
if ( V_31 )
F_6 ( V_7 ) ;
return V_31 ;
}
void F_29 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
F_30 ( & V_7 -> V_28 ) ;
if ( V_7 -> V_9 && V_7 -> type -> V_10 . V_11 . V_42 )
F_31 ( V_5 , V_7 ) ;
else if ( ! V_7 -> V_9 && V_7 -> type -> V_10 . V_13 . V_43 )
V_7 -> type -> V_10 . V_13 . V_43 ( V_7 ) ;
F_32 ( & V_7 -> V_28 ) ;
F_33 ( & V_7 -> V_26 ) ;
}
static inline void F_34 ( struct V_1 * V_2 )
{
F_35 ( & V_2 -> V_29 ) ;
V_2 -> V_44 &= ~ V_45 ;
}
void F_36 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
if ( F_37 ( V_2 ) )
F_34 ( V_2 ) ;
}
void F_38 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
F_39 ( F_37 ( V_2 ) ) ;
F_40 ( V_7 -> V_29 , & V_2 -> V_29 , F_41 ( V_2 ) ) ;
V_2 -> V_44 |= V_45 ;
}
void F_42 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
F_34 ( V_2 ) ;
F_38 ( V_5 , V_2 ) ;
}
struct V_1 * F_43 ( struct V_4 * V_5 , T_2 V_46 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_47 * V_48 ;
struct V_1 * V_2 ;
F_44 (e->hash, rq, next, hash, offset) {
F_39 ( ! F_37 ( V_2 ) ) ;
if ( F_17 ( ! F_45 ( V_2 ) ) ) {
F_34 ( V_2 ) ;
continue;
}
if ( F_41 ( V_2 ) == V_46 )
return V_2 ;
}
return NULL ;
}
void F_46 ( struct V_49 * V_50 , struct V_1 * V_2 )
{
struct V_51 * * V_52 = & V_50 -> V_51 ;
struct V_51 * V_53 = NULL ;
struct V_1 * V_54 ;
while ( * V_52 ) {
V_53 = * V_52 ;
V_54 = F_47 ( V_53 , struct V_1 , V_51 ) ;
if ( F_48 ( V_2 ) < F_48 ( V_54 ) )
V_52 = & ( * V_52 ) -> V_55 ;
else if ( F_48 ( V_2 ) >= F_48 ( V_54 ) )
V_52 = & ( * V_52 ) -> V_56 ;
}
F_49 ( & V_2 -> V_51 , V_53 , V_52 ) ;
F_50 ( & V_2 -> V_51 , V_50 ) ;
}
void F_51 ( struct V_49 * V_50 , struct V_1 * V_2 )
{
F_39 ( F_52 ( & V_2 -> V_51 ) ) ;
F_53 ( & V_2 -> V_51 , V_50 ) ;
F_54 ( & V_2 -> V_51 ) ;
}
struct V_1 * F_55 ( struct V_49 * V_50 , T_2 V_57 )
{
struct V_51 * V_58 = V_50 -> V_51 ;
struct V_1 * V_2 ;
while ( V_58 ) {
V_2 = F_47 ( V_58 , struct V_1 , V_51 ) ;
if ( V_57 < F_48 ( V_2 ) )
V_58 = V_58 -> V_55 ;
else if ( V_57 > F_48 ( V_2 ) )
V_58 = V_58 -> V_56 ;
else
return V_2 ;
}
return NULL ;
}
void F_56 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
T_2 V_59 ;
struct V_60 * V_61 ;
if ( V_5 -> V_33 == V_2 )
V_5 -> V_33 = NULL ;
F_36 ( V_5 , V_2 ) ;
V_5 -> V_62 -- ;
V_59 = V_5 -> V_34 ;
F_57 (entry, &q->queue_head) {
struct V_1 * V_63 = F_58 ( V_61 ) ;
if ( F_59 ( V_2 ) != F_59 ( V_63 ) )
break;
if ( F_60 ( V_2 ) != F_60 ( V_63 ) )
break;
if ( V_63 -> V_44 & ( V_64 | V_65 ) )
break;
if ( F_48 ( V_2 ) >= V_59 ) {
if ( F_48 ( V_63 ) < V_59 )
continue;
} else {
if ( F_48 ( V_63 ) >= V_59 )
break;
}
if ( F_48 ( V_2 ) >= F_48 ( V_63 ) )
break;
}
F_61 ( & V_2 -> V_66 , V_61 ) ;
}
void F_62 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
if ( V_5 -> V_33 == V_2 )
V_5 -> V_33 = NULL ;
F_36 ( V_5 , V_2 ) ;
V_5 -> V_62 -- ;
V_5 -> V_34 = F_63 ( V_2 ) ;
V_5 -> V_35 = V_2 ;
F_64 ( & V_2 -> V_66 , & V_5 -> V_32 ) ;
}
enum V_67 V_67 ( struct V_4 * V_5 , struct V_1 * * V_68 ,
struct V_3 * V_3 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_1 * V_54 ;
if ( F_65 ( V_5 ) || ! F_66 ( V_3 ) )
return V_69 ;
if ( V_5 -> V_33 && F_2 ( V_5 -> V_33 , V_3 ) ) {
enum V_67 V_70 = F_67 ( V_5 -> V_33 , V_3 ) ;
if ( V_70 != V_69 ) {
* V_68 = V_5 -> V_33 ;
return V_70 ;
}
}
if ( F_68 ( V_5 ) )
return V_69 ;
V_54 = F_43 ( V_5 , V_3 -> V_71 . V_72 ) ;
if ( V_54 && F_2 ( V_54 , V_3 ) ) {
* V_68 = V_54 ;
return V_73 ;
}
if ( V_7 -> V_9 && V_7 -> type -> V_10 . V_11 . V_74 )
return V_7 -> type -> V_10 . V_11 . V_74 ( V_5 , V_68 , V_3 ) ;
else if ( ! V_7 -> V_9 && V_7 -> type -> V_10 . V_13 . V_75 )
return V_7 -> type -> V_10 . V_13 . V_75 ( V_5 , V_68 , V_3 ) ;
return V_69 ;
}
bool F_69 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
struct V_1 * V_54 ;
bool V_70 ;
if ( F_65 ( V_5 ) )
return false ;
if ( V_5 -> V_33 && F_70 ( V_5 , V_5 -> V_33 , V_2 ) )
return true ;
if ( F_68 ( V_5 ) )
return false ;
V_70 = false ;
while ( 1 ) {
V_54 = F_43 ( V_5 , F_48 ( V_2 ) ) ;
if ( ! V_54 || ! F_70 ( V_5 , V_54 , V_2 ) )
break;
V_70 = true ;
V_2 = V_54 ;
}
return V_70 ;
}
void F_71 ( struct V_4 * V_5 , struct V_1 * V_2 ,
enum V_67 type )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> V_9 && V_7 -> type -> V_10 . V_11 . V_76 )
V_7 -> type -> V_10 . V_11 . V_76 ( V_5 , V_2 , type ) ;
else if ( ! V_7 -> V_9 && V_7 -> type -> V_10 . V_13 . V_77 )
V_7 -> type -> V_10 . V_13 . V_77 ( V_5 , V_2 , type ) ;
if ( type == V_73 )
F_42 ( V_5 , V_2 ) ;
V_5 -> V_33 = V_2 ;
}
void F_72 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_1 * V_48 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
bool V_78 = false ;
if ( V_7 -> V_9 && V_7 -> type -> V_10 . V_11 . V_79 )
V_7 -> type -> V_10 . V_11 . V_79 ( V_5 , V_2 , V_48 ) ;
else if ( V_7 -> type -> V_10 . V_13 . V_80 ) {
V_78 = ( V_81 bool ) ( V_48 -> V_44 & V_82 ) ;
if ( V_78 )
V_7 -> type -> V_10 . V_13 . V_80 ( V_5 , V_2 , V_48 ) ;
}
F_42 ( V_5 , V_2 ) ;
if ( V_78 ) {
F_36 ( V_5 , V_48 ) ;
V_5 -> V_62 -- ;
}
V_5 -> V_33 = V_2 ;
}
void F_73 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_3 * V_3 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( F_74 ( V_7 -> V_9 ) )
return;
if ( V_7 -> type -> V_10 . V_13 . V_83 )
V_7 -> type -> V_10 . V_13 . V_83 ( V_5 , V_2 , V_3 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 -> V_84 && ! ( V_2 -> V_44 & V_85 ) )
V_2 -> V_5 -> V_86 -- ;
}
static void F_76 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
if ( V_5 -> V_84 && ! ( V_2 -> V_44 & V_85 ) && V_5 -> V_86 ++ == 0 &&
( V_5 -> V_87 == V_88 || V_5 -> V_87 == V_89 ) )
F_77 ( V_5 -> V_84 ) ;
}
static inline void F_75 ( struct V_1 * V_2 ) {}
static inline void F_76 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
}
void F_78 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
if ( F_79 ( V_2 ) ) {
V_5 -> V_90 [ F_80 ( V_2 ) ] -- ;
if ( V_2 -> V_44 & V_82 )
F_81 ( V_5 , V_2 ) ;
}
V_2 -> V_44 &= ~ V_64 ;
F_75 ( V_2 ) ;
F_82 ( V_5 , V_2 , V_91 ) ;
}
void F_83 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
static int V_92 ;
if ( F_74 ( V_7 -> V_9 ) )
return;
F_25 ( V_5 -> V_93 ) ;
while ( V_7 -> type -> V_10 . V_13 . V_94 ( V_5 , 1 ) )
;
if ( V_5 -> V_62 && V_92 ++ < 10 ) {
F_27 ( V_38 L_7
L_8 ,
V_5 -> V_8 -> type -> V_17 , V_5 -> V_62 ) ;
}
}
void F_82 ( struct V_4 * V_5 , struct V_1 * V_2 , int V_95 )
{
F_84 ( V_5 , V_2 ) ;
F_76 ( V_5 , V_2 ) ;
V_2 -> V_5 = V_5 ;
if ( V_2 -> V_44 & V_65 ) {
if ( ! F_85 ( V_2 ) ) {
V_5 -> V_34 = F_63 ( V_2 ) ;
V_5 -> V_35 = V_2 ;
}
} else if ( ! ( V_2 -> V_44 & V_96 ) &&
( V_95 == V_97 ||
V_95 == V_98 ) )
V_95 = V_99 ;
switch ( V_95 ) {
case V_91 :
case V_100 :
V_2 -> V_44 |= V_65 ;
F_61 ( & V_2 -> V_66 , & V_5 -> V_32 ) ;
break;
case V_99 :
V_2 -> V_44 |= V_65 ;
F_83 ( V_5 ) ;
F_64 ( & V_2 -> V_66 , & V_5 -> V_32 ) ;
F_86 ( V_5 ) ;
break;
case V_98 :
if ( F_69 ( V_5 , V_2 ) )
break;
case V_97 :
F_39 ( F_85 ( V_2 ) ) ;
V_2 -> V_44 |= V_82 ;
V_5 -> V_62 ++ ;
if ( F_45 ( V_2 ) ) {
F_38 ( V_5 , V_2 ) ;
if ( ! V_5 -> V_33 )
V_5 -> V_33 = V_2 ;
}
V_5 -> V_8 -> type -> V_10 . V_13 . V_101 ( V_5 , V_2 ) ;
break;
case V_102 :
V_2 -> V_44 |= V_65 ;
F_87 ( V_2 ) ;
break;
default:
F_27 ( V_38 L_9 ,
V_103 , V_95 ) ;
F_88 () ;
}
}
void F_89 ( struct V_4 * V_5 , struct V_1 * V_2 , int V_95 )
{
unsigned long V_104 ;
F_90 ( V_5 -> V_93 , V_104 ) ;
F_82 ( V_5 , V_2 , V_95 ) ;
F_91 ( V_5 -> V_93 , V_104 ) ;
}
struct V_1 * F_92 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> V_9 && V_7 -> type -> V_10 . V_11 . V_105 )
return V_7 -> type -> V_10 . V_11 . V_105 ( V_5 , V_2 ) ;
else if ( ! V_7 -> V_9 && V_7 -> type -> V_10 . V_13 . V_106 )
return V_7 -> type -> V_10 . V_13 . V_106 ( V_5 , V_2 ) ;
return NULL ;
}
struct V_1 * F_93 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> V_9 && V_7 -> type -> V_10 . V_11 . V_107 )
return V_7 -> type -> V_10 . V_11 . V_107 ( V_5 , V_2 ) ;
if ( ! V_7 -> V_9 && V_7 -> type -> V_10 . V_13 . V_108 )
return V_7 -> type -> V_10 . V_13 . V_108 ( V_5 , V_2 ) ;
return NULL ;
}
int F_94 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_3 * V_3 , T_3 V_109 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( F_74 ( V_7 -> V_9 ) )
return 0 ;
if ( V_7 -> type -> V_10 . V_13 . V_110 )
return V_7 -> type -> V_10 . V_13 . V_110 ( V_5 , V_2 , V_3 , V_109 ) ;
return 0 ;
}
void F_95 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( F_74 ( V_7 -> V_9 ) )
return;
if ( V_7 -> type -> V_10 . V_13 . V_111 )
V_7 -> type -> V_10 . V_13 . V_111 ( V_2 ) ;
}
int F_96 ( struct V_4 * V_5 , unsigned int V_112 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( F_74 ( V_7 -> V_9 ) )
return 0 ;
if ( V_7 -> type -> V_10 . V_13 . V_113 )
return V_7 -> type -> V_10 . V_13 . V_113 ( V_5 , V_112 ) ;
return V_114 ;
}
void F_97 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( F_74 ( V_7 -> V_9 ) )
return;
if ( F_79 ( V_2 ) ) {
V_5 -> V_90 [ F_80 ( V_2 ) ] -- ;
if ( ( V_2 -> V_44 & V_82 ) &&
V_7 -> type -> V_10 . V_13 . V_115 )
V_7 -> type -> V_10 . V_13 . V_115 ( V_5 , V_2 ) ;
}
}
static T_4
F_98 ( struct V_30 * V_26 , struct V_116 * V_117 , char * V_118 )
{
struct V_119 * V_61 = F_99 ( V_117 ) ;
struct V_6 * V_7 ;
T_4 error ;
if ( ! V_61 -> V_120 )
return - V_121 ;
V_7 = F_22 ( V_26 , struct V_6 , V_26 ) ;
F_30 ( & V_7 -> V_28 ) ;
error = V_7 -> type ? V_61 -> V_120 ( V_7 , V_118 ) : - V_122 ;
F_32 ( & V_7 -> V_28 ) ;
return error ;
}
static T_4
F_100 ( struct V_30 * V_26 , struct V_116 * V_117 ,
const char * V_118 , T_5 V_123 )
{
struct V_119 * V_61 = F_99 ( V_117 ) ;
struct V_6 * V_7 ;
T_4 error ;
if ( ! V_61 -> V_124 )
return - V_121 ;
V_7 = F_22 ( V_26 , struct V_6 , V_26 ) ;
F_30 ( & V_7 -> V_28 ) ;
error = V_7 -> type ? V_61 -> V_124 ( V_7 , V_118 , V_123 ) : - V_122 ;
F_32 ( & V_7 -> V_28 ) ;
return error ;
}
int F_101 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
int error ;
error = F_102 ( & V_7 -> V_26 , & V_5 -> V_26 , L_10 , L_11 ) ;
if ( ! error ) {
struct V_119 * V_117 = V_7 -> type -> V_125 ;
if ( V_117 ) {
while ( V_117 -> V_117 . V_16 ) {
if ( F_103 ( & V_7 -> V_26 , & V_117 -> V_117 ) )
break;
V_117 ++ ;
}
}
F_104 ( & V_7 -> V_26 , V_126 ) ;
V_7 -> V_127 = 1 ;
if ( ! V_7 -> V_9 && V_7 -> type -> V_10 . V_13 . V_128 )
V_7 -> type -> V_10 . V_13 . V_128 ( V_5 ) ;
}
return error ;
}
void F_105 ( struct V_4 * V_5 )
{
if ( V_5 ) {
struct V_6 * V_7 = V_5 -> V_8 ;
F_104 ( & V_7 -> V_26 , V_129 ) ;
F_106 ( & V_7 -> V_26 ) ;
V_7 -> V_127 = 0 ;
}
}
int F_107 ( struct V_15 * V_7 )
{
char * V_130 = L_12 ;
if ( V_7 -> V_131 ) {
if ( F_108 ( V_7 -> V_131 < sizeof( struct V_132 ) ) ||
F_108 ( V_7 -> V_133 < F_109 ( struct V_132 ) ) )
return - V_36 ;
snprintf ( V_7 -> V_134 , sizeof( V_7 -> V_134 ) ,
L_13 , V_7 -> V_17 ) ;
V_7 -> V_135 = F_110 ( V_7 -> V_134 , V_7 -> V_131 ,
V_7 -> V_133 , 0 , NULL ) ;
if ( ! V_7 -> V_135 )
return - V_136 ;
}
F_9 ( & V_20 ) ;
if ( F_4 ( V_7 -> V_17 ) ) {
F_10 ( & V_20 ) ;
if ( V_7 -> V_135 )
F_111 ( V_7 -> V_135 ) ;
return - V_137 ;
}
F_64 ( & V_7 -> V_138 , & V_139 ) ;
F_10 ( & V_20 ) ;
if ( ! strcmp ( V_7 -> V_17 , V_22 ) ||
( ! * V_22 &&
! strcmp ( V_7 -> V_17 , V_40 ) ) )
V_130 = L_14 ;
F_27 ( V_140 L_15 , V_7 -> V_17 ,
V_130 ) ;
return 0 ;
}
void F_112 ( struct V_15 * V_7 )
{
F_9 ( & V_20 ) ;
F_113 ( & V_7 -> V_138 ) ;
F_10 ( & V_20 ) ;
if ( V_7 -> V_135 ) {
F_114 () ;
F_111 ( V_7 -> V_135 ) ;
V_7 -> V_135 = NULL ;
}
}
static int F_115 ( struct V_4 * V_5 ,
struct V_15 * V_141 )
{
int V_70 ;
F_116 ( V_5 ) ;
F_117 ( V_5 ) ;
if ( V_5 -> V_8 ) {
if ( V_5 -> V_8 -> V_127 )
F_105 ( V_5 ) ;
F_118 ( V_5 ) ;
F_29 ( V_5 , V_5 -> V_8 ) ;
}
V_70 = F_28 ( V_5 , V_141 ) ;
if ( V_70 )
goto V_142;
if ( V_141 ) {
V_70 = F_101 ( V_5 ) ;
if ( V_70 ) {
F_29 ( V_5 , V_5 -> V_8 ) ;
goto V_142;
}
}
if ( V_141 )
F_119 ( V_5 , L_16 , V_141 -> V_17 ) ;
else
F_119 ( V_5 , L_17 ) ;
V_142:
F_120 ( V_5 ) ;
F_121 ( V_5 , true ) ;
return V_70 ;
}
static int F_122 ( struct V_4 * V_5 , struct V_15 * V_141 )
{
struct V_6 * V_143 = V_5 -> V_8 ;
bool V_144 = false ;
int V_31 ;
if ( V_5 -> V_37 )
return F_115 ( V_5 , V_141 ) ;
if ( V_143 ) {
V_144 = V_143 -> V_127 ;
F_123 ( V_5 ) ;
if ( V_144 )
F_105 ( V_5 ) ;
F_118 ( V_5 ) ;
}
V_31 = V_141 -> V_10 . V_13 . V_41 ( V_5 , V_141 ) ;
if ( V_31 )
goto V_145;
V_31 = F_101 ( V_5 ) ;
if ( V_31 )
goto V_146;
if ( V_143 ) {
F_29 ( V_5 , V_143 ) ;
F_124 ( V_5 ) ;
}
F_119 ( V_5 , L_16 , V_141 -> V_17 ) ;
return 0 ;
V_146:
F_29 ( V_5 , V_5 -> V_8 ) ;
V_145:
if ( V_143 ) {
V_5 -> V_8 = V_143 ;
F_101 ( V_5 ) ;
F_124 ( V_5 ) ;
}
return V_31 ;
}
static int F_125 ( struct V_4 * V_5 , const char * V_16 )
{
char V_17 [ V_147 ] ;
struct V_15 * V_7 ;
if ( V_5 -> V_37 && ! strncmp ( V_16 , L_18 , 4 ) )
return F_122 ( V_5 , NULL ) ;
F_126 ( V_17 , V_16 , sizeof( V_17 ) ) ;
V_7 = F_8 ( F_127 ( V_17 ) , true ) ;
if ( ! V_7 ) {
F_27 ( V_38 L_19 , V_17 ) ;
return - V_36 ;
}
if ( V_5 -> V_8 &&
! strcmp ( V_17 , V_5 -> V_8 -> type -> V_17 ) ) {
F_6 ( V_7 ) ;
return 0 ;
}
if ( ! V_7 -> V_9 && V_5 -> V_37 ) {
F_6 ( V_7 ) ;
return - V_36 ;
}
if ( V_7 -> V_9 && ! V_5 -> V_37 ) {
F_6 ( V_7 ) ;
return - V_36 ;
}
return F_122 ( V_5 , V_7 ) ;
}
int F_128 ( struct V_4 * V_5 , const char * V_16 )
{
int V_70 ;
F_30 ( & V_5 -> V_28 ) ;
V_70 = F_125 ( V_5 , V_16 ) ;
F_32 ( & V_5 -> V_28 ) ;
return V_70 ;
}
static inline bool F_129 ( struct V_4 * V_5 )
{
if ( V_5 -> V_37 && V_5 -> V_148 && ( V_5 -> V_148 -> V_104 &
V_149 ) )
return false ;
return true ;
}
T_4 F_130 ( struct V_4 * V_5 , const char * V_16 ,
T_5 V_150 )
{
int V_70 ;
if ( ! ( V_5 -> V_37 || V_5 -> V_151 ) || ! F_129 ( V_5 ) )
return V_150 ;
V_70 = F_125 ( V_5 , V_16 ) ;
if ( ! V_70 )
return V_150 ;
F_27 ( V_38 L_20 , V_16 ) ;
return V_70 ;
}
T_4 F_131 ( struct V_4 * V_5 , char * V_16 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_15 * V_152 = NULL ;
struct V_15 * V_153 ;
int V_154 = 0 ;
if ( ! F_132 ( V_5 ) )
return sprintf ( V_16 , L_21 ) ;
if ( ! V_5 -> V_8 )
V_154 += sprintf ( V_16 + V_154 , L_22 ) ;
else
V_152 = V_7 -> type ;
F_9 ( & V_20 ) ;
F_5 (__e, &elv_list, list) {
if ( V_152 && ! strcmp ( V_152 -> V_17 , V_153 -> V_17 ) ) {
V_154 += sprintf ( V_16 + V_154 , L_23 , V_152 -> V_17 ) ;
continue;
}
if ( V_153 -> V_9 && V_5 -> V_37 && F_129 ( V_5 ) )
V_154 += sprintf ( V_16 + V_154 , L_24 , V_153 -> V_17 ) ;
else if ( ! V_153 -> V_9 && ! V_5 -> V_37 )
V_154 += sprintf ( V_16 + V_154 , L_24 , V_153 -> V_17 ) ;
}
F_10 ( & V_20 ) ;
if ( V_5 -> V_37 && V_5 -> V_8 )
V_154 += sprintf ( V_16 + V_154 , L_18 ) ;
V_154 += sprintf ( V_154 + V_16 , L_25 ) ;
return V_154 ;
}
struct V_1 * F_133 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
struct V_51 * V_155 = F_134 ( & V_2 -> V_51 ) ;
if ( V_155 )
return F_135 ( V_155 ) ;
return NULL ;
}
struct V_1 * F_136 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
struct V_51 * V_156 = F_137 ( & V_2 -> V_51 ) ;
if ( V_156 )
return F_135 ( V_156 ) ;
return NULL ;
}
