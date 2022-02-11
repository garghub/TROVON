static int
F_1 ( const T_1 V_1 )
{
int V_2 = 0 ;
while ( ( V_1 & ( 1 << V_2 ) ) == 0 )
V_2 ++ ;
return V_2 ;
}
static void F_2 ( T_2 V_3 )
{
V_4 = ( V_5 * ) V_3 ;
}
static T_3
F_3 ( T_4 V_6 , T_4 V_7 )
{
const T_5 * V_8 = V_6 ;
const T_5 * V_9 = V_7 ;
return F_4 ( V_8 -> V_10 , V_9 -> V_10 ) ;
}
void
F_5 ( void (F_6)( T_6 V_11 , T_2 V_12 ) ,
void (F_7)( T_6 V_11 , T_2 V_12 ) ,
T_6 V_11 ,
T_2 V_12 )
{
static T_7 V_13 [] = {
{ & V_14 ,
{ L_1 , L_2 , V_15 , V_16 , NULL , 0x0 ,
NULL , V_17 } } ,
} ;
F_8 () ;
V_18 = F_9 ( V_19 , V_20 , V_21 , NULL ) ;
V_22 = F_10 ( V_23 , V_24 ) ;
V_25 = F_10 ( V_23 , V_24 ) ;
V_26 . V_27 = 0 ;
V_26 . V_28 = 0 ;
V_26 . V_29 = NULL ;
V_30 = F_11 ( V_31 , NULL , NULL , F_2 ) ;
F_12 () ;
F_13 ( - 1 , V_13 , F_14 ( V_13 ) ) ;
F_6 ( V_11 , V_12 ) ;
#ifdef F_15
if ( V_11 )
(* V_11)( V_32 , NULL , V_12 ) ;
F_16 () ;
#endif
#ifdef F_17
if ( V_11 )
(* V_11)( V_33 , NULL , V_12 ) ;
F_18 () ;
F_19 () ;
#endif
F_7 ( V_11 , V_12 ) ;
#ifdef F_15
if ( V_11 )
(* V_11)( V_34 , NULL , V_12 ) ;
F_20 () ;
#endif
#ifdef F_17
if ( V_11 )
(* V_11)( V_35 , NULL , V_12 ) ;
F_21 () ;
#endif
V_36 = F_22 ( V_36 , F_3 ) ;
V_37 = F_23 ( V_38 , V_39 ) ;
}
void
F_8 ( void )
{
if ( V_30 ) {
F_24 ( V_30 ) ;
V_30 = NULL ;
}
while ( V_36 ) {
T_5 * V_40 = V_36 -> V_3 ;
V_5 * V_41 ;
F_25 ( V_40 -> V_42 , V_41 ) ;
F_26 ( V_40 -> V_42 == V_41 -> V_43 ) ;
F_27 ( V_5 , V_41 ) ;
F_28 ( V_40 -> V_44 ) ;
V_36 = F_29 ( V_36 , V_40 ) ;
V_21 ( V_40 ) ;
}
if ( V_18 ) {
F_30 ( V_18 ) ;
V_18 = NULL ;
}
if ( V_22 ) {
F_30 ( V_22 ) ;
V_22 = NULL ;
}
if ( V_25 ) {
F_30 ( V_25 ) ;
V_25 = NULL ;
}
if ( V_26 . V_28 ) {
V_26 . V_27 = 0 ;
V_26 . V_28 = 0 ;
V_21 ( V_26 . V_29 ) ;
V_26 . V_29 = NULL ;
}
V_21 ( V_37 ) ;
V_37 = NULL ;
}
static V_38
F_31 ( T_8 * V_45 , T_9 V_46 ,
T_2 V_3 )
{
T_10 * V_47 = V_45 ;
T_10 * V_48 ;
T_10 * V_49 ;
if ( V_46 ( V_47 , V_3 ) )
return TRUE ;
V_48 = V_47 -> V_50 ;
while ( V_48 != NULL ) {
V_49 = V_48 ;
V_48 = V_49 -> V_51 ;
if ( F_31 ( ( T_8 * ) V_49 , V_46 , V_3 ) )
return TRUE ;
}
return FALSE ;
}
V_38
F_32 ( T_8 * V_45 , T_9 V_46 ,
T_2 V_3 )
{
T_10 * V_47 = V_45 ;
T_10 * V_48 ;
T_10 * V_49 ;
V_48 = V_47 -> V_50 ;
while ( V_48 != NULL ) {
V_49 = V_48 ;
V_48 = V_49 -> V_51 ;
if ( F_32 ( ( T_8 * ) V_49 , V_46 , V_3 ) )
return TRUE ;
}
if ( V_46 ( V_47 , V_3 ) )
return TRUE ;
return FALSE ;
}
void
F_33 ( T_8 * V_45 , T_11 V_46 ,
T_2 V_3 )
{
T_10 * V_52 = V_45 ;
T_10 * V_49 ;
V_52 = V_52 -> V_50 ;
while ( V_52 != NULL ) {
V_49 = V_52 ;
V_52 = V_49 -> V_51 ;
V_46 ( ( T_8 * ) V_49 , V_3 ) ;
}
}
void
F_34 ( T_8 * V_45 )
{
F_32 ( V_45 , V_53 , NULL ) ;
}
static void
F_35 ( T_2 V_54 , T_2 V_55 , T_2 T_12 V_56 )
{
T_13 * V_57 = V_55 ;
T_3 V_58 = ( T_3 ) ( long ) V_54 ;
V_5 * V_41 ;
F_25 ( V_58 , V_41 ) ;
if ( V_41 -> V_59 != V_60 ) {
if ( V_41 -> V_61 != - 1 ) {
V_5 * V_62 ;
F_25 ( V_41 -> V_61 , V_62 ) ;
V_62 -> V_59 = V_60 ;
}
V_41 -> V_59 = V_60 ;
}
F_36 ( V_57 , TRUE ) ;
}
static void
F_37 ( T_14 * V_63 )
{
if ( V_63 -> V_64 ) {
F_38 ( V_63 -> V_64 ,
F_35 , NULL ) ;
F_30 ( V_63 -> V_64 ) ;
}
V_21 ( V_63 ) ;
}
static V_38
V_53 ( T_10 * V_52 , T_2 V_3 V_56 )
{
T_15 * V_65 = F_39 ( V_52 ) ;
#if 0
proto_node *parent = node->parent;
#endif
if ( V_65 == NULL ) {
if ( F_40 ( V_52 ) )
F_37 ( F_40 ( V_52 ) ) ;
}
else {
F_41 ( V_65 ) ;
}
#if 0
if (parent) {
proto_item *prev_item = NULL;
if (parent->first_child == node) {
parent->first_child = node->next;
} else {
for (prev_item = parent->first_child; prev_item; prev_item = prev_item->next) {
if (prev_item->next == node) {
break;
}
}
DISSECTOR_ASSERT(prev_item);
prev_item->next = node->next;
}
if (parent->last_child == node) {
parent->last_child = prev_item;
}
}
DISSECTOR_ASSERT(node->first_child == NULL && node->last_child == NULL);
#endif
F_42 ( V_52 ) ;
return FALSE ;
}
V_38
F_43 ( T_8 * V_45 , V_38 V_66 )
{
V_38 V_67 = F_40 ( V_45 ) -> V_66 ;
F_40 ( V_45 ) -> V_66 = V_66 ;
return V_67 ;
}
void
F_44 ( T_8 * V_45 , V_38 V_68 )
{
F_40 ( V_45 ) -> V_68 = V_68 ;
}
V_38
F_45 ( T_8 * V_45 , int V_42 )
{
register V_5 * V_41 ;
if ( ! V_45 )
return FALSE ;
if ( F_40 ( V_45 ) -> V_66 )
return TRUE ;
F_25 ( V_42 , V_41 ) ;
if ( V_41 -> V_59 != V_60 )
return TRUE ;
if ( V_41 -> type == V_69 && ! F_40 ( V_45 ) -> V_68 )
return TRUE ;
return FALSE ;
}
V_5 *
F_46 ( T_16 V_70 )
{
register V_5 * V_41 ;
F_25 ( V_70 , V_41 ) ;
return V_41 ;
}
static T_16
F_47 ( T_4 V_54 ) {
T_17 * V_71 = F_48 ( V_54 ) ;
T_17 * V_72 = V_71 ;
for (; * V_72 ; V_72 ++ ) {
if ( * V_72 == '.' ) {
* V_72 = 0 ;
break;
}
}
return F_49 ( V_71 ) ;
}
static V_38
F_50 ( T_4 V_73 , T_4 V_74 ) {
const T_17 * V_75 = V_73 ;
const T_17 * V_76 = V_74 ;
do {
T_17 V_77 = * V_75 ++ ;
T_17 V_78 = * V_76 ++ ;
if ( ( V_77 == '.' || V_77 == '\0' ) && ( V_78 == '.' || V_78 == '\0' ) ) return TRUE ;
if ( ( V_77 == '.' || V_77 == '\0' ) && ! ( V_78 == '.' || V_78 == '\0' ) ) return FALSE ;
if ( ( V_78 == '.' || V_78 == '\0' ) && ! ( V_77 == '.' || V_77 == '\0' ) ) return FALSE ;
if ( V_77 != V_78 ) return FALSE ;
} while ( 1 );
return FALSE ;
}
void
F_51 ( const char * V_79 , T_18 V_80 ) {
if ( ! V_81 ) {
V_81 = F_10 ( F_47 , F_50 ) ;
}
F_52 ( V_81 , ( T_2 ) V_79 , V_80 ) ;
}
static V_38
F_53 ( T_2 V_82 , T_2 V_83 , T_2 T_19 V_56 ) {
( ( T_18 ) V_83 ) ( V_82 ) ;
return TRUE ;
}
void
F_54 ( void ) {
F_55 ( V_81 , F_53 , NULL ) ;
}
V_5 *
F_56 ( const char * V_84 )
{
V_5 * V_41 ;
T_18 V_80 ;
if ( ! V_84 )
return NULL ;
V_41 = F_57 ( V_30 , V_84 ) ;
if ( V_41 )
return V_41 ;
if ( ! V_81 )
return NULL ;
if ( ( V_80 = F_58 ( V_81 , V_84 ) ) != NULL ) {
V_80 ( V_84 ) ;
F_59 ( V_81 , V_84 ) ;
} else {
return NULL ;
}
return F_57 ( V_30 , V_84 ) ;
}
static void
F_60 ( T_20 * V_85 )
{
T_21 * V_86 ;
F_26 ( V_85 -> V_87 <= V_88 - V_89 ) ;
V_85 -> V_87 += V_89 ;
V_86 = F_61 ( sizeof( T_21 ) * V_85 -> V_87 ) ;
F_26 ( V_86 != NULL ) ;
if ( V_85 -> V_86 )
memcpy ( V_86 , V_85 -> V_86 , V_85 -> V_87 - V_89 ) ;
V_85 -> V_86 = V_86 ;
}
static void
F_62 ( T_20 * V_85 )
{
V_85 -> V_86 = NULL ;
V_85 -> V_87 = 0 ;
F_26 ( V_85 -> V_90 == 0 ) ;
V_85 -> V_90 = 0 ;
}
T_20 *
F_63 ( T_8 * V_45 , T_22 * V_91 , T_3 V_92 )
{
T_20 * V_85 ;
V_85 = F_61 ( sizeof( T_20 ) ) ;
V_85 -> V_45 = V_45 ;
V_85 -> V_91 = V_91 ;
V_85 -> V_92 = V_92 ;
V_85 -> V_86 = NULL ;
V_85 -> V_87 = 0 ;
V_85 -> V_90 = 0 ;
return V_85 ;
}
void
F_64 ( T_20 * V_85 )
{
F_62 ( V_85 ) ;
}
T_22 *
F_65 ( T_20 * V_85 )
{
return V_85 -> V_91 ;
}
T_3
F_66 ( T_20 * V_85 )
{
return V_85 -> V_92 ;
}
T_8 *
F_67 ( T_20 * V_85 )
{
if ( ! V_85 )
return NULL ;
return V_85 -> V_45 ;
}
void
F_68 ( T_20 * V_85 , T_8 * V_45 )
{
V_85 -> V_45 = V_45 ;
}
T_8 *
F_69 ( T_20 * V_85 , T_23 * V_93 , T_3 V_94 )
{
T_21 * V_95 ;
if ( V_85 -> V_90 >= V_85 -> V_87 )
F_60 ( V_85 ) ;
V_95 = V_85 -> V_86 + V_85 -> V_90 ;
V_95 -> V_45 = V_85 -> V_45 ;
V_95 -> V_93 = NULL ;
V_85 -> V_90 ++ ;
return F_70 ( V_85 , V_93 , V_94 ) ;
}
void
F_71 ( T_20 * V_85 )
{
T_21 * V_95 ;
if ( V_85 -> V_90 <= 0 )
return;
V_85 -> V_90 -- ;
V_95 = V_85 -> V_86 + V_85 -> V_90 ;
if ( V_95 -> V_93 != NULL )
F_72 ( V_95 -> V_93 , F_66 ( V_85 ) - V_95 -> V_96 ) ;
V_85 -> V_45 = V_95 -> V_45 ;
}
static void
F_73 ( T_20 * V_85 , T_23 * V_93 )
{
T_21 * V_95 ;
F_26 ( V_85 -> V_90 > 0 ) ;
V_95 = V_85 -> V_86 + V_85 -> V_90 - 1 ;
V_95 -> V_93 = V_93 ;
V_95 -> V_96 = F_66 ( V_85 ) ;
}
T_8 *
F_70 ( T_20 * V_85 , T_23 * V_93 , T_3 V_94 )
{
V_85 -> V_45 = F_74 ( V_93 , V_94 ) ;
return V_85 -> V_45 ;
}
static T_8 *
F_75 ( T_20 * V_85 , T_23 * V_93 , T_3 V_94 , T_3 V_97 )
{
F_69 ( V_85 , V_93 , V_94 ) ;
if ( V_97 == V_98 )
F_73 ( V_85 , V_93 ) ;
return F_67 ( V_85 ) ;
}
T_8 *
F_76 ( T_20 * V_85 , int V_70 , T_3 V_97 ,
const T_16 V_99 , T_3 V_94 )
{
T_23 * V_93 ;
V_93 = F_77 ( V_85 , V_70 , V_97 , V_99 ) ;
return F_75 ( V_85 , V_93 , V_94 , V_97 ) ;
}
T_8 *
F_78 ( T_20 * V_85 , T_3 V_97 ,
T_3 V_94 , const char * V_100 , ... )
{
T_23 * V_93 ;
T_24 V_73 ;
V_5 * V_41 ;
F_79 ( F_67 ( V_85 ) , V_14 , V_41 ) ;
V_93 = F_80 ( F_67 ( V_85 ) , F_65 ( V_85 ) ,
F_66 ( V_85 ) , V_97 ) ;
if ( V_93 == NULL )
return NULL ;
va_start ( V_73 , V_100 ) ;
F_81 ( V_93 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
return F_75 ( V_85 , V_93 , V_94 , V_97 ) ;
}
static T_23 *
F_80 ( T_8 * V_45 , T_22 * V_91 , T_3 V_101 , T_3 V_97 )
{
T_23 * V_80 ;
V_80 = F_82 ( V_45 , V_14 , V_91 , V_101 , & V_97 , NULL ) ;
if ( V_80 == NULL )
return NULL ;
return V_80 ;
}
T_23 *
F_83 ( T_8 * V_45 , T_22 * V_91 , T_3 V_101 , T_3 V_97 ,
const char * V_100 , ... )
{
T_23 * V_80 ;
T_24 V_73 ;
V_5 * V_41 ;
F_79 ( V_45 , V_14 , V_41 ) ;
V_80 = F_80 ( V_45 , V_91 , V_101 , V_97 ) ;
if ( V_80 == NULL )
return NULL ;
F_84 ( V_45 , V_80 ) ;
va_start ( V_73 , V_100 ) ;
F_81 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
return V_80 ;
}
T_23 *
F_85 ( T_8 * V_45 , T_22 * V_91 , T_3 V_101 ,
T_3 V_97 , const char * V_100 , T_24 V_73 )
{
T_23 * V_80 ;
V_5 * V_41 ;
F_79 ( V_45 , V_14 , V_41 ) ;
V_80 = F_80 ( V_45 , V_91 , V_101 , V_97 ) ;
if ( V_80 == NULL )
return NULL ;
F_84 ( V_45 , V_80 ) ;
F_81 ( V_80 , V_100 , V_73 ) ;
return V_80 ;
}
T_23 *
F_86 ( T_8 * V_45 , const char * V_100 , ... )
{
T_23 * V_80 ;
T_24 V_73 ;
V_80 = F_80 ( V_45 , NULL , 0 , 0 ) ;
if ( V_80 ) {
va_start ( V_73 , V_100 ) ;
F_81 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
}
va_start ( V_73 , V_100 ) ;
vprintf ( V_100 , V_73 ) ;
va_end ( V_73 ) ;
printf ( L_3 ) ;
return V_80 ;
}
static T_1
F_87 ( T_22 * V_91 , T_3 V_92 , T_3 V_97 , const T_16 V_99 )
{
T_1 V_55 ;
switch ( V_97 ) {
case 1 :
V_55 = F_88 ( V_91 , V_92 ) ;
break;
case 2 :
V_55 = V_99 ? F_89 ( V_91 , V_92 )
: F_90 ( V_91 , V_92 ) ;
break;
case 3 :
V_55 = V_99 ? F_91 ( V_91 , V_92 )
: F_92 ( V_91 , V_92 ) ;
break;
case 4 :
V_55 = V_99 ? F_93 ( V_91 , V_92 )
: F_94 ( V_91 , V_92 ) ;
break;
default:
F_95 () ;
V_55 = 0 ;
break;
}
return V_55 ;
}
static T_25
F_96 ( T_22 * V_91 , T_3 V_92 , T_3 V_97 , const T_16 V_99 )
{
T_25 V_55 ;
switch ( V_97 ) {
case 1 :
V_55 = ( V_102 ) F_88 ( V_91 , V_92 ) ;
break;
case 2 :
V_55 = ( V_103 ) ( V_99 ? F_89 ( V_91 , V_92 )
: F_90 ( V_91 , V_92 ) ) ;
break;
case 3 :
V_55 = V_99 ? F_91 ( V_91 , V_92 )
: F_92 ( V_91 , V_92 ) ;
if ( V_55 & 0x00800000 ) {
V_55 |= 0xFF000000 ;
}
break;
case 4 :
V_55 = V_99 ? F_93 ( V_91 , V_92 )
: F_94 ( V_91 , V_92 ) ;
break;
default:
F_95 () ;
V_55 = 0 ;
break;
}
return V_55 ;
}
static T_13 *
F_97 ( T_8 * V_45 ,
V_5 * V_41 )
{
T_13 * V_57 = NULL ;
F_26 ( V_45 ) ;
F_26 ( V_41 ) ;
if ( V_41 -> V_59 == V_104 ) {
if ( F_40 ( V_45 ) -> V_64 == NULL ) {
F_40 ( V_45 ) -> V_64 =
F_10 ( V_105 , NULL ) ;
}
V_57 = F_58 ( F_40 ( V_45 ) -> V_64 ,
F_98 ( V_41 -> V_43 ) ) ;
if ( ! V_57 ) {
V_57 = F_99 () ;
F_52 ( F_40 ( V_45 ) -> V_64 ,
F_98 ( V_41 -> V_43 ) , V_57 ) ;
}
}
return V_57 ;
}
static T_23 *
F_100 ( T_15 * V_106 , T_8 * V_45 ,
T_22 * V_91 , T_3 V_101 , T_3 V_97 ,
const T_16 V_107 )
{
T_16 V_99 = V_107 ;
T_23 * V_80 ;
T_1 V_55 , V_108 ;
float V_109 ;
double V_110 ;
const char * string ;
T_26 V_111 ;
T_13 * V_57 ;
if ( V_112 ) {
F_101 ( V_112 ) ;
}
V_112 = V_106 ;
switch ( V_106 -> V_41 -> type ) {
case V_15 :
break;
case V_69 :
F_102 ( V_106 , V_91 ) ;
break;
case V_113 :
F_103 ( V_106 , V_91 , V_101 , V_97 ) ;
break;
case V_114 :
if ( V_99 )
V_99 = V_115 ;
V_108 = F_87 ( V_91 , V_101 , V_97 , V_99 ) ;
F_103 ( V_106 , V_91 , V_101 + V_97 , V_108 ) ;
V_106 -> V_97 = V_108 + V_97 ;
break;
case V_116 :
if ( V_99 )
V_99 = V_115 ;
F_104 ( V_106 ,
F_87 ( V_91 , V_101 , V_97 , V_99 ) ) ;
break;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
if ( V_99 )
V_99 = V_115 ;
F_105 ( V_106 ,
F_87 ( V_91 , V_101 , V_97 , V_99 ) ) ;
break;
case V_121 :
case V_122 :
if ( V_99 )
V_99 = V_115 ;
F_26 ( V_97 <= 8 && V_97 >= 1 ) ;
F_106 ( V_106 , V_91 , V_101 , V_97 , V_99 ) ;
break;
case V_123 :
case V_124 :
case V_125 :
case V_126 :
if ( V_99 )
V_99 = V_115 ;
F_107 ( V_106 ,
F_96 ( V_91 , V_101 , V_97 , V_99 ) ) ;
break;
case V_127 :
if ( V_99 )
V_99 = V_115 ;
F_26 ( V_97 == V_128 ) ;
V_55 = F_108 ( V_91 , V_101 ) ;
F_109 ( V_106 , V_99 ? F_110 ( V_55 ) : V_55 ) ;
break;
case V_129 :
F_26 ( V_97 == V_130 ) ;
F_111 ( V_106 ,
F_87 ( V_91 , V_101 , 4 , FALSE ) ) ;
break;
case V_131 :
F_26 ( V_97 >= 0 && V_97 <= V_132 ) ;
F_112 ( V_106 , V_91 , V_101 , V_97 ) ;
break;
case V_133 :
F_26 ( V_97 == V_134 ) ;
F_113 ( V_106 , V_91 , V_101 ) ;
break;
case V_135 :
if ( V_99 )
V_99 = V_115 ;
F_26 ( V_97 == V_136 ) ;
F_114 ( V_106 , V_91 , V_101 , V_99 ) ;
break;
case V_137 :
if ( V_99 )
V_99 = V_115 ;
F_26 ( V_97 == V_138 ) ;
F_115 ( V_106 , V_91 , V_101 , V_99 ) ;
break;
case V_139 :
F_116 ( V_106 , V_91 , V_101 , V_97 ) ;
break;
case V_140 :
if ( V_99 )
V_99 = V_115 ;
F_26 ( V_97 == 4 ) ;
if ( V_99 )
V_109 = F_117 ( V_91 , V_101 ) ;
else
V_109 = F_118 ( V_91 , V_101 ) ;
F_119 ( V_106 , V_109 ) ;
break;
case V_141 :
if ( V_99 == TRUE )
V_99 = V_115 ;
F_26 ( V_97 == 8 ) ;
if ( V_99 )
V_110 = F_120 ( V_91 , V_101 ) ;
else
V_110 = F_121 ( V_91 , V_101 ) ;
F_122 ( V_106 , V_110 ) ;
break;
case V_142 :
F_123 ( V_106 , V_91 , V_101 , V_97 ,
V_99 ) ;
break;
case V_143 :
F_26 ( V_97 >= - 1 ) ;
if ( V_97 == - 1 ) {
string = F_124 ( V_91 , V_101 , & V_97 , V_99 ) ;
} else if ( V_97 == 0 ) {
string = L_4 ;
} else {
string = F_125 ( V_91 , V_101 , V_97 , V_99 ) ;
}
V_106 -> V_97 = V_97 ;
F_126 ( V_106 , string ) ;
break;
case V_144 :
if ( V_99 == TRUE )
V_99 = V_145 | V_115 ;
V_108 = F_87 ( V_91 , V_101 , V_97 , V_99 ) ;
F_123 ( V_106 , V_91 , V_101 + V_97 , V_108 ,
V_99 ) ;
V_106 -> V_97 = V_108 + V_97 ;
break;
case V_146 :
if ( V_99 == TRUE )
V_99 = V_147 | V_115 ;
switch ( V_99 ) {
case V_147 | V_148 :
F_26 ( V_97 == 8 || V_97 == 4 ) ;
V_111 . V_149 = F_94 ( V_91 , V_101 ) ;
if ( V_97 == 8 )
V_111 . V_150 = F_94 ( V_91 , V_101 + 4 ) ;
else
V_111 . V_150 = 0 ;
break;
case V_147 | V_115 :
F_26 ( V_97 == 8 || V_97 == 4 ) ;
V_111 . V_149 = F_93 ( V_91 , V_101 ) ;
if ( V_97 == 8 )
V_111 . V_150 = F_93 ( V_91 , V_101 + 4 ) ;
else
V_111 . V_150 = 0 ;
break;
case V_151 | V_148 :
F_26 ( V_97 == 8 || V_97 == 4 ) ;
#define F_127 2208988800ul
V_111 . V_149 = F_94 ( V_91 , V_101 ) ;
if ( V_111 . V_149 )
V_111 . V_149 -= F_127 ;
if ( V_97 == 8 ) {
V_111 . V_150 = ( int ) ( 1000000 * ( F_94 ( V_91 , V_101 + 4 ) / 4294967296.0 ) ) ;
V_111 . V_150 *= 1000 ;
} else {
V_111 . V_150 = 0 ;
}
break;
case V_151 | V_115 :
F_26 ( V_97 == 8 || V_97 == 4 ) ;
V_111 . V_149 = F_93 ( V_91 , V_101 ) ;
if ( V_111 . V_149 )
V_111 . V_149 -= F_127 ;
if ( V_97 == 8 ) {
V_111 . V_150 = ( int ) ( 1000000 * ( F_93 ( V_91 , V_101 + 4 ) / 4294967296.0 ) ) ;
V_111 . V_150 *= 1000 ;
} else {
V_111 . V_150 = 0 ;
}
break;
default:
F_95 () ;
V_111 . V_149 = 0 ;
V_111 . V_150 = 0 ;
break;
}
F_128 ( V_106 , & V_111 ) ;
break;
case V_152 :
if ( V_99 == TRUE )
V_99 = V_147 | V_115 ;
switch ( V_99 ) {
case V_147 | V_148 :
F_26 ( V_97 == 8 || V_97 == 4 ) ;
V_111 . V_149 = F_94 ( V_91 , V_101 ) ;
if ( V_97 == 8 )
V_111 . V_150 = F_94 ( V_91 , V_101 + 4 ) ;
else
V_111 . V_150 = 0 ;
break;
case V_147 | V_115 :
F_26 ( V_97 == 8 || V_97 == 4 ) ;
V_111 . V_149 = F_93 ( V_91 , V_101 ) ;
if ( V_97 == 8 )
V_111 . V_150 = F_93 ( V_91 , V_101 + 4 ) ;
else
V_111 . V_150 = 0 ;
break;
}
F_128 ( V_106 , & V_111 ) ;
break;
default:
F_129 ( L_5 ,
V_106 -> V_41 -> type ,
F_130 ( V_106 -> V_41 -> type ) ) ;
F_95 () ;
break;
}
F_131 ( V_106 , ( V_99 & V_115 ) ? V_153 : V_154 ) ;
V_80 = F_132 ( V_45 , V_106 ) ;
V_112 = NULL ;
V_57 = F_97 ( V_45 , V_106 -> V_41 ) ;
if ( V_57 )
F_133 ( V_57 , V_106 ) ;
return V_80 ;
}
T_23 *
F_134 ( T_20 * V_85 , int V_70 , T_3 V_97 ,
const T_16 V_99 )
{
T_15 * V_106 ;
V_5 * V_41 ;
T_3 V_155 ;
T_1 V_108 ;
int V_92 ;
V_92 = V_85 -> V_92 ;
V_41 = F_135 ( V_70 , V_85 -> V_91 , V_92 , & V_97 ,
& V_155 ) ;
V_85 -> V_92 += V_97 ;
if ( V_41 -> type == V_114 || V_41 -> type == V_144 ) {
V_108 = F_87 ( V_85 -> V_91 , V_92 , V_97 , V_99 ) ;
V_85 -> V_92 += V_108 ;
}
F_79 ( V_85 -> V_45 , V_70 , V_41 ) ;
V_106 = F_136 ( V_85 -> V_45 , V_41 , V_85 -> V_91 , V_92 , V_155 ) ;
if ( V_106 == NULL )
return NULL ;
return F_100 ( V_106 , V_85 -> V_45 , V_85 -> V_91 ,
V_92 , V_97 , V_99 ) ;
}
T_23 *
F_137 ( T_8 * V_45 , const int V_70 , T_22 * V_91 ,
const T_3 V_101 , T_3 V_97 , const T_16 V_99 )
{
T_15 * V_106 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
V_106 = F_138 ( V_45 , V_70 , V_91 , V_101 , & V_97 ) ;
if ( V_106 == NULL )
return NULL ;
return F_100 ( V_106 , V_45 , V_91 , V_101 ,
V_97 , V_99 ) ;
}
T_23 *
F_139 ( T_8 * V_45 , const int V_70 , T_22 * V_91 ,
const T_3 V_101 , T_3 V_97 , const char * V_100 ,
... )
{
T_23 * V_80 ;
T_24 V_73 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
F_26 ( V_41 -> type == V_15 ) ;
V_80 = F_82 ( V_45 , V_70 , V_91 , V_101 , & V_97 , NULL ) ;
F_84 ( V_45 , V_80 ) ;
va_start ( V_73 , V_100 ) ;
F_81 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
return V_80 ;
}
T_23 *
F_77 ( T_20 * V_85 , int V_13 , T_3 V_97 ,
const T_16 V_99 )
{
T_23 * V_156 ;
V_156 = F_137 ( V_85 -> V_45 , V_13 , V_85 -> V_91 , V_85 -> V_92 ,
V_97 , V_99 ) ;
return V_156 ;
}
void
F_140 ( T_20 * V_85 , T_3 V_97 )
{
V_85 -> V_92 += V_97 ;
}
static void
F_102 ( T_15 * V_157 , T_22 * V_91 )
{
F_141 ( & V_157 -> V_55 , V_91 , TRUE ) ;
}
T_23 *
F_142 ( T_8 * V_45 , int V_70 , T_22 * V_91 ,
T_3 V_101 , T_3 V_97 , const char * V_100 , ... )
{
T_23 * V_80 ;
T_24 V_73 ;
T_15 * V_106 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
F_26 ( V_41 -> type == V_69 ) ;
V_80 = F_82 ( V_45 , V_70 , V_91 , V_101 , & V_97 , & V_106 ) ;
F_102 ( V_106 , ( V_101 == 0 ? V_91 : F_143 ( V_91 , V_101 , V_97 , V_97 ) ) ) ;
F_84 ( V_45 , V_80 ) ;
va_start ( V_73 , V_100 ) ;
F_81 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
return V_80 ;
}
T_23 *
F_144 ( T_8 * V_45 , int V_70 , T_22 * V_91 , T_3 V_101 ,
T_3 V_97 , const T_27 * V_158 )
{
T_23 * V_80 ;
T_15 * V_106 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
F_26 ( V_41 -> type == V_113 ) ;
V_80 = F_82 ( V_45 , V_70 , V_91 , V_101 , & V_97 , & V_106 ) ;
F_145 ( V_106 , V_158 , V_97 ) ;
return V_80 ;
}
T_23 *
F_146 ( T_8 * V_45 , int V_70 , T_22 * V_91 ,
T_3 V_101 , T_3 V_97 ,
const T_27 * V_158 ,
const char * V_100 , ... )
{
T_23 * V_80 ;
T_24 V_73 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
if ( V_158 )
V_80 = F_144 ( V_45 , V_70 , V_91 , V_101 , V_97 ,
V_158 ) ;
else
V_80 = F_144 ( V_45 , V_70 , V_91 , V_101 , V_97 ,
F_147 ( V_91 , V_101 , V_97 ) ) ;
if ( V_80 == NULL )
return NULL ;
F_84 ( V_45 , V_80 ) ;
va_start ( V_73 , V_100 ) ;
F_148 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
return V_80 ;
}
T_23 *
F_149 ( T_8 * V_45 , int V_70 , T_22 * V_91 ,
T_3 V_101 , T_3 V_97 , const T_27 * V_158 ,
const char * V_100 , ... )
{
T_23 * V_80 ;
T_24 V_73 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
if ( V_158 )
V_80 = F_144 ( V_45 , V_70 , V_91 , V_101 , V_97 ,
V_158 ) ;
else
V_80 = F_144 ( V_45 , V_70 , V_91 , V_101 , V_97 ,
F_147 ( V_91 , V_101 , V_97 ) ) ;
if ( V_80 == NULL )
return NULL ;
F_84 ( V_45 , V_80 ) ;
va_start ( V_73 , V_100 ) ;
F_81 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
return V_80 ;
}
static void
F_145 ( T_15 * V_157 , const T_27 * V_158 , T_3 V_97 )
{
T_28 * V_159 ;
V_159 = F_150 () ;
if ( V_97 > 0 ) {
F_151 ( V_159 , V_158 , V_97 ) ;
}
F_141 ( & V_157 -> V_55 , V_159 , TRUE ) ;
}
static void
F_103 ( T_15 * V_157 , T_22 * V_91 , T_3 V_92 , T_3 V_97 )
{
F_145 ( V_157 , F_147 ( V_91 , V_92 , V_97 ) , V_97 ) ;
}
T_23 *
F_152 ( T_8 * V_45 , int V_70 , T_22 * V_91 , T_3 V_101 ,
T_3 V_97 , T_26 * V_160 )
{
T_23 * V_80 ;
T_15 * V_106 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
F_26 ( V_41 -> type == V_146 ||
V_41 -> type == V_152 ) ;
V_80 = F_82 ( V_45 , V_70 , V_91 , V_101 , & V_97 , & V_106 ) ;
F_128 ( V_106 , V_160 ) ;
return V_80 ;
}
T_23 *
F_153 ( T_8 * V_45 , int V_70 , T_22 * V_91 ,
T_3 V_101 , T_3 V_97 , T_26 * V_160 ,
const char * V_100 , ... )
{
T_23 * V_80 ;
T_24 V_73 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
V_80 = F_152 ( V_45 , V_70 , V_91 , V_101 , V_97 , V_160 ) ;
if ( V_80 == NULL )
return NULL ;
F_84 ( V_45 , V_80 ) ;
va_start ( V_73 , V_100 ) ;
F_148 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
return V_80 ;
}
T_23 *
F_154 ( T_8 * V_45 , int V_70 , T_22 * V_91 ,
T_3 V_101 , T_3 V_97 , T_26 * V_160 ,
const char * V_100 , ... )
{
T_23 * V_80 ;
T_24 V_73 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
V_80 = F_152 ( V_45 , V_70 , V_91 , V_101 , V_97 , V_160 ) ;
if ( V_80 == NULL )
return NULL ;
F_84 ( V_45 , V_80 ) ;
va_start ( V_73 , V_100 ) ;
F_81 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
return V_80 ;
}
static void
F_128 ( T_15 * V_157 , T_26 * V_160 )
{
F_26 ( V_160 != NULL ) ;
F_141 ( & V_157 -> V_55 , V_160 , FALSE ) ;
}
T_23 *
F_155 ( T_8 * V_45 , int V_70 , T_22 * V_91 , T_3 V_101 ,
T_3 V_97 , T_1 V_55 )
{
T_23 * V_80 ;
T_15 * V_106 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
F_26 ( V_41 -> type == V_129 ) ;
V_80 = F_82 ( V_45 , V_70 , V_91 , V_101 , & V_97 , & V_106 ) ;
F_111 ( V_106 , V_55 ) ;
return V_80 ;
}
T_23 *
F_156 ( T_8 * V_45 , int V_70 , T_22 * V_91 ,
T_3 V_101 , T_3 V_97 , T_1 V_55 ,
const char * V_100 , ... )
{
T_23 * V_80 ;
T_24 V_73 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
V_80 = F_155 ( V_45 , V_70 , V_91 , V_101 , V_97 , V_55 ) ;
if ( V_80 == NULL )
return NULL ;
F_84 ( V_45 , V_80 ) ;
va_start ( V_73 , V_100 ) ;
F_148 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
return V_80 ;
}
T_23 *
F_157 ( T_8 * V_45 , int V_70 , T_22 * V_91 ,
T_3 V_101 , T_3 V_97 , T_1 V_55 ,
const char * V_100 , ... )
{
T_23 * V_80 ;
T_24 V_73 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
V_80 = F_155 ( V_45 , V_70 , V_91 , V_101 , V_97 , V_55 ) ;
if ( V_80 == NULL )
return NULL ;
F_84 ( V_45 , V_80 ) ;
va_start ( V_73 , V_100 ) ;
F_81 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
return V_80 ;
}
static void
F_111 ( T_15 * V_157 , T_1 V_55 )
{
F_158 ( & V_157 -> V_55 , V_55 ) ;
}
T_23 *
F_159 ( T_8 * V_45 , int V_70 , T_22 * V_91 , T_3 V_101 ,
T_3 V_97 , T_1 V_55 )
{
T_23 * V_80 ;
T_15 * V_106 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
F_26 ( V_41 -> type == V_127 ) ;
V_80 = F_82 ( V_45 , V_70 , V_91 , V_101 , & V_97 , & V_106 ) ;
F_109 ( V_106 , V_55 ) ;
return V_80 ;
}
T_23 *
F_160 ( T_8 * V_45 , int V_70 , T_22 * V_91 ,
T_3 V_101 , T_3 V_97 , T_1 V_55 ,
const char * V_100 , ... )
{
T_23 * V_80 ;
T_24 V_73 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
V_80 = F_159 ( V_45 , V_70 , V_91 , V_101 , V_97 , V_55 ) ;
if ( V_80 == NULL )
return NULL ;
F_84 ( V_45 , V_80 ) ;
va_start ( V_73 , V_100 ) ;
F_148 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
return V_80 ;
}
T_23 *
F_161 ( T_8 * V_45 , int V_70 , T_22 * V_91 ,
T_3 V_101 , T_3 V_97 , T_1 V_55 ,
const char * V_100 , ... )
{
T_23 * V_80 ;
T_24 V_73 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
V_80 = F_159 ( V_45 , V_70 , V_91 , V_101 , V_97 , V_55 ) ;
if ( V_80 == NULL )
return NULL ;
F_84 ( V_45 , V_80 ) ;
va_start ( V_73 , V_100 ) ;
F_81 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
return V_80 ;
}
static void
F_109 ( T_15 * V_157 , T_1 V_55 )
{
F_158 ( & V_157 -> V_55 , V_55 ) ;
}
T_23 *
F_162 ( T_8 * V_45 , int V_70 , T_22 * V_91 , T_3 V_101 ,
T_3 V_97 , const T_27 * V_160 )
{
T_23 * V_80 ;
T_15 * V_106 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
F_26 ( V_41 -> type == V_131 ) ;
V_80 = F_82 ( V_45 , V_70 , V_91 , V_101 , & V_97 , & V_106 ) ;
F_163 ( V_106 , V_160 ) ;
return V_80 ;
}
T_23 *
F_164 ( T_8 * V_45 , int V_70 , T_22 * V_91 ,
T_3 V_101 , T_3 V_97 ,
const T_27 * V_160 ,
const char * V_100 , ... )
{
T_23 * V_80 ;
T_24 V_73 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
V_80 = F_162 ( V_45 , V_70 , V_91 , V_101 , V_97 , V_160 ) ;
if ( V_80 == NULL )
return NULL ;
F_84 ( V_45 , V_80 ) ;
va_start ( V_73 , V_100 ) ;
F_148 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
return V_80 ;
}
T_23 *
F_165 ( T_8 * V_45 , int V_70 , T_22 * V_91 ,
T_3 V_101 , T_3 V_97 , const T_27 * V_160 ,
const char * V_100 , ... )
{
T_23 * V_80 ;
T_24 V_73 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
V_80 = F_162 ( V_45 , V_70 , V_91 , V_101 , V_97 , V_160 ) ;
if ( V_80 == NULL )
return NULL ;
F_84 ( V_45 , V_80 ) ;
va_start ( V_73 , V_100 ) ;
F_81 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
return V_80 ;
}
static void
F_163 ( T_15 * V_157 , const T_27 * V_160 )
{
F_26 ( V_160 != NULL ) ;
F_141 ( & V_157 -> V_55 , ( T_2 ) V_160 , FALSE ) ;
}
static void
F_112 ( T_15 * V_157 , T_22 * V_91 , T_3 V_101 , T_3 V_97 )
{
F_163 ( V_157 , F_147 ( V_91 , V_101 , V_97 ) ) ;
}
T_23 *
F_166 ( T_8 * V_45 , int V_70 , T_22 * V_91 , T_3 V_101 ,
T_3 V_97 , const T_29 * V_160 )
{
T_23 * V_80 ;
T_15 * V_106 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
F_26 ( V_41 -> type == V_137 ) ;
V_80 = F_82 ( V_45 , V_70 , V_91 , V_101 , & V_97 , & V_106 ) ;
F_167 ( V_106 , V_160 ) ;
return V_80 ;
}
T_23 *
F_168 ( T_8 * V_45 , int V_70 , T_22 * V_91 ,
T_3 V_101 , T_3 V_97 ,
const T_29 * V_160 ,
const char * V_100 , ... )
{
T_23 * V_80 ;
T_24 V_73 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
V_80 = F_166 ( V_45 , V_70 , V_91 , V_101 , V_97 , V_160 ) ;
if ( V_80 == NULL )
return NULL ;
F_84 ( V_45 , V_80 ) ;
va_start ( V_73 , V_100 ) ;
F_148 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
return V_80 ;
}
T_23 *
F_169 ( T_8 * V_45 , int V_70 , T_22 * V_91 ,
T_3 V_101 , T_3 V_97 , const T_29 * V_160 ,
const char * V_100 , ... )
{
T_23 * V_80 ;
T_24 V_73 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
V_80 = F_166 ( V_45 , V_70 , V_91 , V_101 , V_97 , V_160 ) ;
if ( V_80 == NULL )
return NULL ;
F_84 ( V_45 , V_80 ) ;
va_start ( V_73 , V_100 ) ;
F_81 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
return V_80 ;
}
static void
F_167 ( T_15 * V_157 , const T_29 * V_160 )
{
F_26 ( V_160 != NULL ) ;
F_141 ( & V_157 -> V_55 , ( T_2 ) V_160 , FALSE ) ;
}
static void
F_115 ( T_15 * V_157 , T_22 * V_91 , T_3 V_101 ,
const T_16 V_99 )
{
T_29 V_161 ;
F_170 ( V_91 , V_101 , & V_161 , V_99 ) ;
F_167 ( V_157 , & V_161 ) ;
}
T_23 *
F_171 ( T_8 * V_45 , int V_70 , T_22 * V_91 , T_3 V_101 ,
T_3 V_97 , const T_27 * V_160 )
{
T_23 * V_80 ;
T_15 * V_106 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
F_26 ( V_41 -> type == V_139 ) ;
V_80 = F_82 ( V_45 , V_70 , V_91 , V_101 , & V_97 , & V_106 ) ;
F_172 ( V_106 , V_160 , V_97 ) ;
return V_80 ;
}
T_23 *
F_173 ( T_8 * V_45 , int V_70 , T_22 * V_91 ,
T_3 V_101 , T_3 V_97 ,
const T_27 * V_160 ,
const char * V_100 , ... )
{
T_23 * V_80 ;
T_24 V_73 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
V_80 = F_171 ( V_45 , V_70 , V_91 , V_101 , V_97 , V_160 ) ;
if ( V_80 == NULL )
return NULL ;
F_84 ( V_45 , V_80 ) ;
va_start ( V_73 , V_100 ) ;
F_148 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
return V_80 ;
}
T_23 *
F_174 ( T_8 * V_45 , int V_70 , T_22 * V_91 ,
T_3 V_101 , T_3 V_97 , const T_27 * V_160 ,
const char * V_100 , ... )
{
T_23 * V_80 ;
T_24 V_73 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
V_80 = F_171 ( V_45 , V_70 , V_91 , V_101 , V_97 , V_160 ) ;
if ( V_80 == NULL )
return NULL ;
F_84 ( V_45 , V_80 ) ;
va_start ( V_73 , V_100 ) ;
F_81 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
return V_80 ;
}
static void
F_172 ( T_15 * V_157 , const T_27 * V_160 , T_3 V_97 )
{
T_28 * V_159 ;
F_26 ( V_160 != NULL ) ;
V_159 = F_150 () ;
if ( V_97 > 0 ) {
F_151 ( V_159 , V_160 , V_97 ) ;
}
F_141 ( & V_157 -> V_55 , V_159 , TRUE ) ;
}
static void
F_116 ( T_15 * V_157 , T_22 * V_91 , T_3 V_101 , T_3 V_97 )
{
F_172 ( V_157 , F_147 ( V_91 , V_101 , V_97 ) , V_97 ) ;
}
static void
F_175 ( T_15 * V_157 , T_30 V_55 )
{
F_176 ( & V_157 -> V_55 , V_55 ) ;
}
static void
F_106 ( T_15 * V_157 , T_22 * V_91 , T_3 V_101 ,
T_16 V_97 , const T_16 V_99 )
{
T_30 V_55 = 0 ;
T_27 * V_76 = F_177 ( V_91 , V_101 , V_97 ) ;
if ( V_99 ) {
V_76 += V_97 ;
switch ( V_97 ) {
default: F_95 () ;
case 8 : V_55 <<= 8 ; V_55 += * -- V_76 ;
case 7 : V_55 <<= 8 ; V_55 += * -- V_76 ;
case 6 : V_55 <<= 8 ; V_55 += * -- V_76 ;
case 5 : V_55 <<= 8 ; V_55 += * -- V_76 ;
case 4 : V_55 <<= 8 ; V_55 += * -- V_76 ;
case 3 : V_55 <<= 8 ; V_55 += * -- V_76 ;
case 2 : V_55 <<= 8 ; V_55 += * -- V_76 ;
case 1 : V_55 <<= 8 ; V_55 += * -- V_76 ;
break;
}
} else {
switch ( V_97 ) {
default: F_95 () ;
case 8 : V_55 <<= 8 ; V_55 += * V_76 ++ ;
case 7 : V_55 <<= 8 ; V_55 += * V_76 ++ ;
case 6 : V_55 <<= 8 ; V_55 += * V_76 ++ ;
case 5 : V_55 <<= 8 ; V_55 += * V_76 ++ ;
case 4 : V_55 <<= 8 ; V_55 += * V_76 ++ ;
case 3 : V_55 <<= 8 ; V_55 += * V_76 ++ ;
case 2 : V_55 <<= 8 ; V_55 += * V_76 ++ ;
case 1 : V_55 <<= 8 ; V_55 += * V_76 ++ ;
break;
}
}
F_175 ( V_157 , V_55 ) ;
}
T_23 *
F_178 ( T_8 * V_45 , int V_70 , T_22 * V_91 , T_3 V_101 ,
T_3 V_97 , const char * V_55 )
{
T_23 * V_80 ;
T_15 * V_106 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
F_26 ( V_41 -> type == V_142 || V_41 -> type == V_143 ) ;
V_80 = F_82 ( V_45 , V_70 , V_91 , V_101 , & V_97 , & V_106 ) ;
F_26 ( V_97 >= 0 ) ;
F_126 ( V_106 , V_55 ) ;
return V_80 ;
}
T_23 *
F_179 ( T_8 * V_45 , int V_70 , T_22 * V_91 ,
T_3 V_101 , T_3 V_97 , const char * V_55 ,
const char * V_100 ,
... )
{
T_23 * V_80 ;
T_24 V_73 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
V_80 = F_178 ( V_45 , V_70 , V_91 , V_101 , V_97 , V_55 ) ;
if ( V_80 == NULL )
return NULL ;
F_84 ( V_45 , V_80 ) ;
va_start ( V_73 , V_100 ) ;
F_148 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
return V_80 ;
}
T_23 *
F_180 ( T_8 * V_45 , int V_70 , T_22 * V_91 ,
T_3 V_101 , T_3 V_97 , const char * V_55 ,
const char * V_100 , ... )
{
T_23 * V_80 ;
T_24 V_73 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
V_80 = F_178 ( V_45 , V_70 , V_91 , V_101 , V_97 , V_55 ) ;
if ( V_80 == NULL )
return NULL ;
F_84 ( V_45 , V_80 ) ;
va_start ( V_73 , V_100 ) ;
F_81 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
return V_80 ;
}
void
F_181 ( T_23 * V_80 , const char * V_162 )
{
T_15 * V_157 ;
V_5 * V_41 ;
T_17 * V_163 , * V_164 ;
if ( ! V_80 )
return;
if ( ! * V_162 )
return;
V_157 = F_182 ( V_80 ) ;
F_183 ( V_157 , L_6 ) ;
V_41 = V_157 -> V_41 ;
if ( V_41 -> type == V_69 ) {
return;
}
F_26 ( V_41 -> type == V_142 || V_41 -> type == V_143 ) ;
V_163 = F_184 ( & V_157 -> V_55 ) ;
V_164 = F_185 ( L_7 , V_163 , V_162 ) ;
F_141 ( & V_157 -> V_55 , V_164 , FALSE ) ;
}
static void
F_126 ( T_15 * V_157 , const char * V_55 )
{
if ( V_55 ) {
F_141 ( & V_157 -> V_55 , ( T_2 ) V_55 , FALSE ) ;
} else {
F_141 ( & V_157 -> V_55 , ( T_2 ) L_8 , FALSE ) ;
}
}
static void
F_123 ( T_15 * V_157 , T_22 * V_91 , T_3 V_101 , T_3 V_97 , T_3 V_99 )
{
T_17 * string ;
if ( V_97 == - 1 ) {
V_97 = F_186 ( V_91 , V_101 ) ;
}
string = F_125 ( V_91 , V_101 , V_97 , V_99 ) ;
F_126 ( V_157 , string ) ;
}
T_23 *
F_187 ( T_8 * V_45 , int V_70 , T_22 * V_91 , T_3 V_101 ,
T_3 V_97 , const T_27 * V_55 )
{
T_23 * V_80 ;
T_15 * V_106 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
F_26 ( V_41 -> type == V_133 ) ;
V_80 = F_82 ( V_45 , V_70 , V_91 , V_101 , & V_97 , & V_106 ) ;
F_188 ( V_106 , V_55 ) ;
return V_80 ;
}
T_23 *
F_189 ( T_8 * V_45 , int V_70 , T_22 * V_91 ,
T_3 V_101 , T_3 V_97 , const T_27 * V_55 ,
const char * V_100 , ... )
{
T_23 * V_80 ;
T_24 V_73 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
V_80 = F_187 ( V_45 , V_70 , V_91 , V_101 , V_97 , V_55 ) ;
if ( V_80 == NULL )
return NULL ;
F_84 ( V_45 , V_80 ) ;
va_start ( V_73 , V_100 ) ;
F_148 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
return V_80 ;
}
T_23 *
F_190 ( T_8 * V_45 , int V_70 , T_22 * V_91 ,
T_3 V_101 , T_3 V_97 , const T_27 * V_55 ,
const char * V_100 , ... )
{
T_23 * V_80 ;
T_24 V_73 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
V_80 = F_187 ( V_45 , V_70 , V_91 , V_101 , V_97 , V_55 ) ;
if ( V_80 == NULL )
return NULL ;
F_84 ( V_45 , V_80 ) ;
va_start ( V_73 , V_100 ) ;
F_81 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
return V_80 ;
}
static void
F_188 ( T_15 * V_157 , const T_27 * V_55 )
{
F_141 ( & V_157 -> V_55 , ( T_2 ) V_55 , FALSE ) ;
}
static void
F_113 ( T_15 * V_157 , T_22 * V_91 , T_3 V_101 )
{
F_188 ( V_157 , F_147 ( V_91 , V_101 , V_134 ) ) ;
}
T_23 *
F_191 ( T_8 * V_45 , int V_70 , T_22 * V_91 , T_3 V_101 ,
T_3 V_97 , T_1 V_55 )
{
T_23 * V_80 ;
T_15 * V_106 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
F_26 ( V_41 -> type == V_116 ) ;
V_80 = F_82 ( V_45 , V_70 , V_91 , V_101 , & V_97 , & V_106 ) ;
F_104 ( V_106 , V_55 ) ;
return V_80 ;
}
T_23 *
F_192 ( T_8 * V_45 , int V_70 ,
T_22 * V_91 , T_3 V_101 , T_3 V_97 ,
T_1 V_55 , const char * V_100 , ... )
{
T_23 * V_80 ;
T_24 V_73 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
V_80 = F_191 ( V_45 , V_70 , V_91 , V_101 , V_97 , V_55 ) ;
if ( V_80 == NULL )
return NULL ;
F_84 ( V_45 , V_80 ) ;
va_start ( V_73 , V_100 ) ;
F_148 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
return V_80 ;
}
T_23 *
F_193 ( T_8 * V_45 , int V_70 , T_22 * V_91 ,
T_3 V_101 , T_3 V_97 , T_1 V_55 ,
const char * V_100 , ... )
{
T_23 * V_80 ;
T_24 V_73 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
V_80 = F_191 ( V_45 , V_70 , V_91 , V_101 , V_97 , V_55 ) ;
if ( V_80 == NULL )
return NULL ;
F_84 ( V_45 , V_80 ) ;
va_start ( V_73 , V_100 ) ;
F_81 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
return V_80 ;
}
static void
F_104 ( T_15 * V_157 , T_1 V_55 )
{
F_105 ( V_157 , V_55 ) ;
}
T_23 *
F_194 ( T_8 * V_45 , int V_70 , T_22 * V_91 , T_3 V_101 ,
T_3 V_97 , float V_55 )
{
T_23 * V_80 ;
T_15 * V_106 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
F_26 ( V_41 -> type == V_140 ) ;
V_80 = F_82 ( V_45 , V_70 , V_91 , V_101 , & V_97 , & V_106 ) ;
F_119 ( V_106 , V_55 ) ;
return V_80 ;
}
T_23 *
F_195 ( T_8 * V_45 , int V_70 , T_22 * V_91 ,
T_3 V_101 , T_3 V_97 , float V_55 ,
const char * V_100 , ... )
{
T_23 * V_80 ;
T_24 V_73 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
V_80 = F_194 ( V_45 , V_70 , V_91 , V_101 , V_97 , V_55 ) ;
if ( V_80 == NULL )
return NULL ;
F_84 ( V_45 , V_80 ) ;
va_start ( V_73 , V_100 ) ;
F_148 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
return V_80 ;
}
T_23 *
F_196 ( T_8 * V_45 , int V_70 , T_22 * V_91 ,
T_3 V_101 , T_3 V_97 , float V_55 ,
const char * V_100 , ... )
{
T_23 * V_80 ;
T_24 V_73 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
V_80 = F_194 ( V_45 , V_70 , V_91 , V_101 , V_97 , V_55 ) ;
if ( V_80 == NULL )
return NULL ;
F_84 ( V_45 , V_80 ) ;
va_start ( V_73 , V_100 ) ;
F_81 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
return V_80 ;
}
static void
F_119 ( T_15 * V_157 , float V_55 )
{
F_197 ( & V_157 -> V_55 , V_55 ) ;
}
T_23 *
F_198 ( T_8 * V_45 , int V_70 , T_22 * V_91 , T_3 V_101 ,
T_3 V_97 , double V_55 )
{
T_23 * V_80 ;
T_15 * V_106 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
F_26 ( V_41 -> type == V_141 ) ;
V_80 = F_82 ( V_45 , V_70 , V_91 , V_101 , & V_97 , & V_106 ) ;
F_122 ( V_106 , V_55 ) ;
return V_80 ;
}
T_23 *
F_199 ( T_8 * V_45 , int V_70 , T_22 * V_91 ,
T_3 V_101 , T_3 V_97 , double V_55 ,
const char * V_100 , ... )
{
T_23 * V_80 ;
T_24 V_73 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
V_80 = F_198 ( V_45 , V_70 , V_91 , V_101 , V_97 , V_55 ) ;
if ( V_80 == NULL )
return NULL ;
F_84 ( V_45 , V_80 ) ;
va_start ( V_73 , V_100 ) ;
F_148 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
return V_80 ;
}
T_23 *
F_200 ( T_8 * V_45 , int V_70 , T_22 * V_91 ,
T_3 V_101 , T_3 V_97 , double V_55 ,
const char * V_100 , ... )
{
T_23 * V_80 ;
T_24 V_73 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
V_80 = F_198 ( V_45 , V_70 , V_91 , V_101 , V_97 , V_55 ) ;
if ( V_80 == NULL )
return NULL ;
F_84 ( V_45 , V_80 ) ;
va_start ( V_73 , V_100 ) ;
F_81 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
return V_80 ;
}
static void
F_122 ( T_15 * V_157 , double V_55 )
{
F_197 ( & V_157 -> V_55 , V_55 ) ;
}
T_23 *
F_201 ( T_8 * V_45 , int V_70 , T_22 * V_91 , T_3 V_101 ,
T_3 V_97 , T_1 V_55 )
{
T_23 * V_80 = NULL ;
T_15 * V_106 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
switch ( V_41 -> type ) {
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_165 :
V_80 = F_82 ( V_45 , V_70 , V_91 , V_101 , & V_97 ,
& V_106 ) ;
F_105 ( V_106 , V_55 ) ;
break;
default:
F_95 () ;
}
return V_80 ;
}
T_23 *
F_202 ( T_8 * V_45 , int V_70 , T_22 * V_91 ,
T_3 V_101 , T_3 V_97 , T_1 V_55 ,
const char * V_100 , ... )
{
T_23 * V_80 ;
T_24 V_73 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
V_80 = F_201 ( V_45 , V_70 , V_91 , V_101 , V_97 , V_55 ) ;
if ( V_80 == NULL )
return NULL ;
F_84 ( V_45 , V_80 ) ;
va_start ( V_73 , V_100 ) ;
F_148 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
return V_80 ;
}
T_23 *
F_203 ( T_8 * V_45 , int V_70 , T_22 * V_91 ,
T_3 V_101 , T_3 V_97 , T_1 V_55 ,
const char * V_100 , ... )
{
T_23 * V_80 ;
T_24 V_73 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
V_80 = F_201 ( V_45 , V_70 , V_91 , V_101 , V_97 , V_55 ) ;
if ( V_80 == NULL )
return NULL ;
F_84 ( V_45 , V_80 ) ;
va_start ( V_73 , V_100 ) ;
F_81 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
return V_80 ;
}
static void
F_105 ( T_15 * V_157 , T_1 V_55 )
{
V_5 * V_41 ;
T_1 integer ;
V_41 = V_157 -> V_41 ;
integer = V_55 ;
if ( V_41 -> V_1 ) {
integer &= V_41 -> V_1 ;
if ( V_41 -> V_2 > 0 ) {
integer >>= V_41 -> V_2 ;
}
}
F_158 ( & V_157 -> V_55 , integer ) ;
}
T_23 *
F_204 ( T_8 * V_45 , int V_70 , T_22 * V_91 , T_3 V_101 ,
T_3 V_97 , T_30 V_55 )
{
T_23 * V_80 = NULL ;
T_15 * V_106 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
F_26 ( V_41 -> type == V_122 ) ;
V_80 = F_82 ( V_45 , V_70 , V_91 , V_101 , & V_97 , & V_106 ) ;
F_175 ( V_106 , V_55 ) ;
return V_80 ;
}
T_23 *
F_205 ( T_8 * V_45 , int V_70 , T_22 * V_91 ,
T_3 V_101 , T_3 V_97 , T_30 V_55 ,
const char * V_100 , ... )
{
T_23 * V_80 ;
T_24 V_73 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
V_80 = F_204 ( V_45 , V_70 , V_91 , V_101 , V_97 , V_55 ) ;
if ( V_80 == NULL )
return NULL ;
F_84 ( V_45 , V_80 ) ;
va_start ( V_73 , V_100 ) ;
F_148 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
return V_80 ;
}
T_23 *
F_206 ( T_8 * V_45 , int V_70 , T_22 * V_91 ,
T_3 V_101 , T_3 V_97 , T_30 V_55 ,
const char * V_100 , ... )
{
T_23 * V_80 ;
T_24 V_73 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
V_80 = F_204 ( V_45 , V_70 , V_91 , V_101 , V_97 , V_55 ) ;
if ( V_80 == NULL )
return NULL ;
F_84 ( V_45 , V_80 ) ;
va_start ( V_73 , V_100 ) ;
F_81 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
return V_80 ;
}
T_23 *
F_207 ( T_8 * V_45 , int V_70 , T_22 * V_91 , T_3 V_101 ,
T_3 V_97 , T_25 V_55 )
{
T_23 * V_80 = NULL ;
T_15 * V_106 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
switch ( V_41 -> type ) {
case V_123 :
case V_124 :
case V_125 :
case V_126 :
V_80 = F_82 ( V_45 , V_70 , V_91 , V_101 , & V_97 ,
& V_106 ) ;
F_107 ( V_106 , V_55 ) ;
break;
default:
F_95 () ;
}
return V_80 ;
}
T_23 *
F_208 ( T_8 * V_45 , int V_70 , T_22 * V_91 ,
T_3 V_101 , T_3 V_97 , T_25 V_55 ,
const char * V_100 , ... )
{
T_23 * V_80 = NULL ;
T_24 V_73 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
V_80 = F_207 ( V_45 , V_70 , V_91 , V_101 , V_97 , V_55 ) ;
if ( V_80 == NULL )
return NULL ;
F_84 ( V_45 , V_80 ) ;
va_start ( V_73 , V_100 ) ;
F_148 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
return V_80 ;
}
T_23 *
F_209 ( T_8 * V_45 , int V_70 , T_22 * V_91 ,
T_3 V_101 , T_3 V_97 , T_25 V_55 ,
const char * V_100 , ... )
{
T_23 * V_80 = NULL ;
T_24 V_73 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
V_80 = F_207 ( V_45 , V_70 , V_91 , V_101 , V_97 , V_55 ) ;
if ( V_80 == NULL )
return NULL ;
F_84 ( V_45 , V_80 ) ;
va_start ( V_73 , V_100 ) ;
F_81 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
return V_80 ;
}
static void
F_107 ( T_15 * V_157 , T_25 V_55 )
{
V_5 * V_41 ;
T_1 integer ;
V_41 = V_157 -> V_41 ;
integer = ( T_1 ) V_55 ;
if ( V_41 -> V_1 ) {
integer &= V_41 -> V_1 ;
if ( V_41 -> V_2 > 0 ) {
integer >>= V_41 -> V_2 ;
}
}
F_210 ( & V_157 -> V_55 , integer ) ;
}
T_23 *
F_211 ( T_8 * V_45 , int V_70 , T_22 * V_91 , T_3 V_101 ,
T_3 V_97 , T_31 V_55 )
{
T_23 * V_80 = NULL ;
T_15 * V_106 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
F_26 ( V_41 -> type == V_121 ) ;
V_80 = F_82 ( V_45 , V_70 , V_91 , V_101 , & V_97 , & V_106 ) ;
F_175 ( V_106 , ( T_30 ) V_55 ) ;
return V_80 ;
}
T_23 *
F_212 ( T_8 * V_45 , int V_70 , T_22 * V_91 ,
T_3 V_101 , T_3 V_97 , T_31 V_55 ,
const char * V_100 , ... )
{
T_23 * V_80 ;
T_24 V_73 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
V_80 = F_211 ( V_45 , V_70 , V_91 , V_101 , V_97 , V_55 ) ;
if ( V_80 == NULL )
return NULL ;
F_84 ( V_45 , V_80 ) ;
va_start ( V_73 , V_100 ) ;
F_148 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
return V_80 ;
}
T_23 *
F_213 ( T_8 * V_45 , int V_70 , T_22 * V_91 ,
T_3 V_101 , T_3 V_97 , T_31 V_55 ,
const char * V_100 , ... )
{
T_23 * V_80 ;
T_24 V_73 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
V_80 = F_211 ( V_45 , V_70 , V_91 , V_101 , V_97 , V_55 ) ;
if ( V_80 == NULL )
return NULL ;
F_84 ( V_45 , V_80 ) ;
va_start ( V_73 , V_100 ) ;
F_81 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
return V_80 ;
}
T_23 *
F_214 ( T_8 * V_45 , int V_70 , T_22 * V_91 , T_3 V_101 ,
T_3 V_97 , const T_30 V_55 )
{
T_23 * V_80 ;
T_15 * V_106 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
F_26 ( V_41 -> type == V_135 ) ;
V_80 = F_82 ( V_45 , V_70 , V_91 , V_101 , & V_97 , & V_106 ) ;
F_215 ( V_106 , V_55 ) ;
return V_80 ;
}
T_23 *
F_216 ( T_8 * V_45 , int V_70 , T_22 * V_91 ,
T_3 V_101 , T_3 V_97 , const T_30 V_55 ,
const char * V_100 , ... )
{
T_23 * V_80 ;
T_24 V_73 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
V_80 = F_214 ( V_45 , V_70 , V_91 , V_101 , V_97 , V_55 ) ;
if ( V_80 == NULL )
return NULL ;
F_84 ( V_45 , V_80 ) ;
va_start ( V_73 , V_100 ) ;
F_148 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
return V_80 ;
}
T_23 *
F_217 ( T_8 * V_45 , int V_70 , T_22 * V_91 ,
T_3 V_101 , T_3 V_97 , const T_30 V_55 ,
const char * V_100 , ... )
{
T_23 * V_80 ;
T_24 V_73 ;
V_5 * V_41 ;
F_79 ( V_45 , V_70 , V_41 ) ;
V_80 = F_214 ( V_45 , V_70 , V_91 , V_101 , V_97 , V_55 ) ;
if ( V_80 == NULL )
return NULL ;
F_84 ( V_45 , V_80 ) ;
va_start ( V_73 , V_100 ) ;
F_81 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
return V_80 ;
}
static void
F_215 ( T_15 * V_157 , const T_30 V_55 )
{
F_176 ( & V_157 -> V_55 , V_55 ) ;
}
static void
F_114 ( T_15 * V_157 , T_22 * V_91 , T_3 V_101 , const T_16 V_99 )
{
if ( V_99 )
{
F_215 ( V_157 , F_218 ( V_91 , V_101 ) ) ;
} else {
F_215 ( V_157 , F_219 ( V_91 , V_101 ) ) ;
}
}
static T_23 *
F_132 ( T_8 * V_45 , T_15 * V_157 )
{
T_10 * V_47 , * V_166 , * V_167 ;
T_15 * V_168 ;
V_166 = V_45 ;
V_168 = F_39 ( V_166 ) ;
if ( V_168 != NULL && ( V_168 -> V_169 < 0 || V_168 -> V_169 >= V_39 ) ) {
F_220 ( F_185 ( L_9 ,
V_157 -> V_41 -> V_170 , V_157 -> V_41 -> V_171 , V_168 -> V_169 , __FILE__ , __LINE__ ) ) ;
}
F_26 ( V_168 == NULL ||
( V_168 -> V_169 >= 0 && V_168 -> V_169 < V_39 ) ) ;
F_221 ( V_47 ) ;
V_47 -> V_61 = V_166 ;
F_39 ( V_47 ) = V_157 ;
V_47 -> V_63 = F_40 ( V_45 ) ;
if ( V_166 -> V_172 != NULL ) {
V_167 = V_166 -> V_172 ;
F_26 ( V_167 -> V_51 == NULL ) ;
V_167 -> V_51 = V_47 ;
} else
V_166 -> V_50 = V_47 ;
V_166 -> V_172 = V_47 ;
return ( T_23 * ) V_47 ;
}
static T_23 *
F_82 ( T_8 * V_45 , int V_70 , T_22 * V_91 , T_3 V_101 ,
T_3 * V_97 , T_15 * * V_173 )
{
T_23 * V_80 ;
T_15 * V_157 ;
T_13 * V_57 ;
if ( ! V_45 )
return NULL ;
V_157 = F_138 ( V_45 , V_70 , V_91 , V_101 , V_97 ) ;
V_80 = F_132 ( V_45 , V_157 ) ;
V_57 = F_97 ( V_45 , V_157 -> V_41 ) ;
if ( V_57 )
F_133 ( V_57 , V_157 ) ;
if ( V_173 ) {
* V_173 = V_157 ;
}
return V_80 ;
}
static V_5 *
F_135 ( int V_70 , T_22 * V_91 , const T_3 V_101 , T_3 * V_97 ,
T_3 * V_155 )
{
V_5 * V_41 ;
T_3 V_174 ;
F_26 ( V_91 != NULL || * V_97 == 0 ) ;
F_25 ( V_70 , V_41 ) ;
if ( * V_97 == - 1 ) {
switch ( V_41 -> type ) {
case V_69 :
* V_97 = F_222 ( V_91 , V_101 ) ;
if ( * V_97 < 0 ) {
F_223 ( V_91 , V_101 , 0 ) ;
}
F_26 ( * V_97 >= 0 ) ;
break;
case V_15 :
case V_113 :
case V_142 :
* V_97 = F_186 ( V_91 , V_101 ) ;
F_26 ( * V_97 >= 0 ) ;
break;
case V_143 :
break;
default:
F_95 () ;
}
* V_155 = * V_97 ;
} else {
* V_155 = * V_97 ;
if ( V_41 -> type == V_69 || V_41 -> type == V_15 ) {
if ( V_91 ) {
V_174 = F_222 ( V_91 , V_101 ) ;
if ( * V_155 < 0 ||
( * V_155 > 0 &&
( V_174 < * V_155 ) ) )
* V_155 = V_174 ;
}
}
if ( * V_155 < 0 ) {
F_224 ( V_175 ) ;
}
}
return V_41 ;
}
static T_15 *
F_136 ( T_8 * V_45 , V_5 * V_41 , T_22 * V_91 ,
const T_3 V_101 , const T_3 V_155 )
{
T_15 * V_157 ;
F_225 ( V_157 ) ;
V_157 -> V_41 = V_41 ;
V_157 -> V_101 = V_101 ;
V_157 -> V_101 += ( V_91 ) ? F_226 ( V_91 ) : 0 ;
V_157 -> V_97 = V_155 ;
V_157 -> V_169 = - 1 ;
V_157 -> V_176 = 0 ;
if ( ! F_40 ( V_45 ) -> V_66 )
F_131 ( V_157 , V_177 ) ;
F_227 ( & V_157 -> V_55 , V_157 -> V_41 -> type ) ;
V_157 -> V_178 = NULL ;
V_157 -> V_179 = V_91 ? F_228 ( V_91 ) : NULL ;
V_157 -> V_180 = 0 ;
V_157 -> V_181 = 0 ;
return V_157 ;
}
static T_15 *
F_138 ( T_8 * V_45 , int V_70 , T_22 * V_91 , const T_3 V_101 ,
T_3 * V_97 )
{
V_5 * V_41 ;
T_3 V_155 ;
V_41 = F_135 ( V_70 , V_91 , V_101 , V_97 , & V_155 ) ;
return F_136 ( V_45 , V_41 , V_91 , V_101 , V_155 ) ;
}
static void
F_148 ( T_23 * V_80 , const char * V_100 , T_24 V_73 )
{
int V_182 ;
T_15 * V_157 = F_182 ( V_80 ) ;
V_5 * V_13 ;
F_26 ( V_157 ) ;
V_13 = V_157 -> V_41 ;
if ( ! F_229 ( V_80 ) ) {
F_230 ( V_157 -> V_178 ) ;
if ( V_13 -> V_1 && ( V_13 -> type == V_116 || F_231 ( V_13 -> type ) ) ) {
char V_183 [ 64 ] ;
T_1 V_184 ;
V_184 = F_232 ( & V_157 -> V_55 ) ;
if ( V_13 -> V_2 > 0 ) {
V_184 <<= V_13 -> V_2 ;
}
F_233 ( V_183 , V_184 , V_13 -> V_1 , F_234 ( V_13 ) ) ;
V_182 = F_235 ( V_157 -> V_178 -> V_185 , V_186 ,
L_10 , V_183 , V_157 -> V_41 -> V_170 ) ;
} else {
V_182 = F_235 ( V_157 -> V_178 -> V_185 , V_186 ,
L_11 , V_157 -> V_41 -> V_170 ) ;
}
if ( V_182 < V_186 ) {
V_182 += F_236 ( V_157 -> V_178 -> V_185 + V_182 ,
V_186 - V_182 , V_100 , V_73 ) ;
}
if ( V_182 >= V_186 ) {
char * V_187 ;
V_187 = F_237 ( V_157 -> V_178 -> V_185 ) ;
F_235 ( V_157 -> V_178 -> V_185 ,
V_186 ,
L_12 ,
V_187 ) ;
V_21 ( V_187 ) ;
}
}
}
static void
F_81 ( T_23 * V_80 , const char * V_100 , T_24 V_73 )
{
int V_182 ;
T_15 * V_157 = F_182 ( V_80 ) ;
F_26 ( V_157 ) ;
if ( ! F_229 ( V_80 ) ) {
F_230 ( V_157 -> V_178 ) ;
V_182 = F_236 ( V_157 -> V_178 -> V_185 , V_186 ,
V_100 , V_73 ) ;
if ( V_182 >= V_186 ) {
char * V_187 ;
V_187 = F_237 ( V_157 -> V_178 -> V_185 ) ;
F_235 ( V_157 -> V_178 -> V_185 , V_186 ,
L_12 , V_187 ) ;
V_21 ( V_187 ) ;
}
}
}
static int
F_238 ( T_17 * V_188 , const T_17 * V_189 , T_32 V_190 )
{
T_32 V_191 = F_239 ( V_188 , V_189 , V_190 ) ;
if ( V_191 > V_190 )
V_191 = V_190 ;
return ( int ) V_191 ;
}
const T_17 *
F_240 ( T_8 * V_45 , const int V_192 , T_3 V_193 ,
T_17 * V_194 , T_17 * V_195 , const int V_196 )
{
T_1 V_197 ;
T_25 integer ;
T_27 * V_159 ;
T_33 * V_198 ;
struct V_199 * V_200 ;
T_34 V_201 ;
T_1 V_202 ;
const T_35 * V_203 ;
int V_27 , V_204 = 0 , V_205 , V_206 , V_207 = 0 , V_208 = 0 ;
T_13 * V_209 ;
T_15 * V_65 = NULL ;
V_5 * V_41 ;
const T_17 * V_171 = NULL ;
F_241 ( V_192 >= 0 ) ;
V_41 = F_46 ( ( T_16 ) V_192 ) ;
if ( ! V_41 )
return L_13 ;
if ( V_193 < 0 ) {
while ( V_41 -> V_210 ) {
V_41 = V_41 -> V_210 ;
}
}
while ( V_41 ) {
V_209 = F_242 ( V_45 , V_41 -> V_43 ) ;
if ( ! V_209 || ! ( V_27 = F_243 ( V_209 ) ) ) {
if ( V_193 < 0 ) {
V_41 = V_41 -> V_211 ;
} else {
V_41 = V_41 -> V_210 ;
}
continue;
}
if ( ( ( V_193 - V_204 ) > V_27 ) || ( ( V_193 + V_204 ) < - V_27 ) ) {
if ( V_193 < 0 ) {
V_41 = V_41 -> V_211 ;
} else {
V_41 = V_41 -> V_210 ;
}
V_204 += V_27 ;
continue;
}
if ( V_193 < 0 ) {
V_206 = V_193 + V_27 + V_204 ;
V_205 = V_206 ;
} else if ( V_193 > 0 ) {
V_206 = V_193 - 1 - V_204 ;
V_205 = V_206 ;
} else {
V_206 = 0 ;
V_205 = V_27 - 1 ;
}
V_204 += V_27 ;
while ( V_206 <= V_205 ) {
V_65 = F_244 ( V_209 , V_206 ) ;
if ( V_207 && ( V_207 < ( V_196 - 2 ) ) )
V_194 [ V_207 ++ ] = ',' ;
if ( V_208 && ( V_208 < ( V_196 - 2 ) ) )
V_195 [ V_208 ++ ] = ',' ;
switch ( V_41 -> type ) {
case V_15 :
if ( V_207 == 0 ) {
V_194 [ 0 ] = '\0' ;
} else if ( V_194 [ V_207 - 1 ] == ',' ) {
V_194 [ V_207 - 1 ] = '\0' ;
}
break;
case V_69 :
F_239 ( V_194 , L_14 , V_196 ) ;
break;
case V_114 :
case V_113 :
V_159 = F_184 ( & V_65 -> V_55 ) ;
V_207 += F_238 ( V_194 + V_207 ,
F_245 ( V_159 ,
F_246 ( & V_65 -> V_55 ) ) ,
V_196 - V_207 ) ;
break;
case V_146 :
V_207 += F_238 ( V_194 + V_207 ,
F_247 ( F_184 ( & V_65 -> V_55 ) ,
V_41 -> V_212 , TRUE ) ,
V_196 - V_207 ) ;
break;
case V_152 :
V_207 += F_238 ( V_194 + V_207 ,
F_248 ( F_184 ( & V_65 -> V_55 ) ) ,
V_196 - V_207 ) ;
break;
case V_116 :
V_197 = F_232 ( & V_65 -> V_55 ) ;
V_203 = ( const T_35 * ) & V_213 ;
if ( V_41 -> V_214 ) {
V_203 = ( const struct T_35 * ) V_41 -> V_214 ;
}
V_207 += F_238 ( V_194 + V_207 ,
V_197 ?
V_203 -> V_215 :
V_203 -> V_216 , V_196 - V_207 ) ;
F_235 ( V_195 + V_208 , V_196 - V_208 , L_15 ,
F_232 ( & V_65 -> V_55 ) ? 1 : 0 ) ;
V_208 = ( int ) strlen ( V_195 ) ;
break;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_165 :
V_197 = F_232 ( & V_65 -> V_55 ) ;
if ( ( V_41 -> V_212 & V_217 ) == V_218 ) {
T_17 V_219 [ V_186 ] ;
T_36 V_220 = ( T_36 ) V_41 -> V_214 ;
F_26 ( V_220 ) ;
V_220 ( V_219 , V_197 ) ;
F_235 ( V_194 + V_207 , V_196 - V_207 , L_16 , V_219 ) ;
} else if ( V_41 -> V_214 ) {
if ( V_41 -> V_212 & V_221 ) {
F_239 ( V_194 + V_207 ,
F_249 ( V_197 , V_41 -> V_214 , L_15 ) ,
V_196 - V_207 ) ;
} else if ( V_41 -> V_212 & V_222 ) {
F_239 ( V_194 + V_207 ,
F_250 ( V_197 ,
( V_223 * ) ( V_41 -> V_214 ) ,
L_15 ) , V_196 - V_207 ) ;
} else {
F_239 ( V_194 + V_207 ,
F_251 ( V_197 , F_252 ( V_41 -> V_214 ) , L_15 ) ,
V_196 - V_207 ) ;
}
} else if ( F_253 ( V_41 -> V_212 ) ) {
F_235 ( V_194 + V_207 , V_196 - V_207 ,
F_254 ( V_41 ) , V_197 , V_197 ) ;
} else {
F_235 ( V_194 + V_207 , V_196 - V_207 ,
F_254 ( V_41 ) , V_197 ) ;
}
if ( V_41 -> V_214 && ( V_41 -> V_212 & V_217 ) == V_16 ) {
F_235 ( V_195 + V_208 , V_196 - V_208 ,
L_17 , V_194 + V_207 ) ;
} else {
F_235 ( V_195 + V_208 , V_196 - V_208 ,
F_255 ( V_41 ) ,
F_232 ( & V_65 -> V_55 ) ) ;
}
V_207 = ( int ) strlen ( V_194 ) ;
V_208 = ( int ) strlen ( V_195 ) ;
break;
case V_121 :
F_235 ( V_194 + V_207 , V_196 - V_207 ,
L_18 V_224 L_19 ,
F_256 ( & V_65 -> V_55 ) ) ;
V_207 = ( int ) strlen ( V_194 ) ;
break;
case V_122 :
F_235 ( V_194 + V_207 , V_196 - V_207 ,
L_18 V_224 L_20 ,
F_256 ( & V_65 -> V_55 ) ) ;
V_207 = ( int ) strlen ( V_194 ) ;
break;
case V_135 :
V_207 += F_238 ( V_194 + V_207 ,
F_257 ( F_256 ( & V_65 -> V_55 ) ) ,
V_196 - V_207 ) ;
break;
case V_123 :
case V_124 :
case V_125 :
case V_126 :
integer = F_258 ( & V_65 -> V_55 ) ;
if ( ( V_41 -> V_212 & V_217 ) == V_218 ) {
T_17 V_219 [ V_186 ] ;
T_36 V_220 = ( T_36 ) V_41 -> V_214 ;
F_26 ( V_220 ) ;
V_220 ( V_219 , integer ) ;
F_235 ( V_194 + V_207 , V_196 - V_207 , L_16 , V_219 ) ;
} else if ( V_41 -> V_214 ) {
if ( V_41 -> V_212 & V_221 ) {
F_239 ( V_194 + V_207 ,
F_249 ( integer , V_41 -> V_214 , L_21 ) ,
V_196 - V_207 ) ;
} else if ( V_41 -> V_212 & V_222 ) {
F_239 ( V_194 + V_207 ,
F_250 ( integer ,
( V_223 * ) ( V_41 -> V_214 ) ,
L_21 ) ,
V_196 - V_207 ) ;
} else {
F_239 ( V_194 + V_207 ,
F_251 ( integer , F_252 ( V_41 -> V_214 ) , L_21 ) ,
V_196 - V_207 ) ;
}
} else if ( F_253 ( V_41 -> V_212 ) ) {
F_235 ( V_194 + V_207 , V_196 - V_207 ,
F_259 ( V_41 ) , integer , integer ) ;
} else {
F_235 ( V_194 + V_207 , V_196 - V_207 ,
F_259 ( V_41 ) , integer ) ;
}
if ( V_41 -> V_214 && ( V_41 -> V_212 & V_217 ) == V_16 ) {
F_235 ( V_195 + V_208 , V_196 - V_208 , L_17 , V_194 + V_207 ) ;
} else {
F_235 ( V_195 + V_208 , V_196 - V_208 ,
F_255 ( V_41 ) ,
F_258 ( & V_65 -> V_55 ) ) ;
}
V_207 = ( int ) strlen ( V_194 ) ;
V_208 = ( int ) strlen ( V_195 ) ;
break;
case V_127 :
V_198 = F_184 ( & V_65 -> V_55 ) ;
V_202 = F_260 ( V_198 ) ;
V_207 += F_238 ( V_194 + V_207 ,
F_261 ( ( T_27 * ) & V_202 ) ,
V_196 - V_207 ) ;
break;
case V_131 :
V_200 = F_184 ( & V_65 -> V_55 ) ;
F_262 ( & V_201 , V_225 , sizeof( struct V_199 ) , V_200 ) ;
F_263 ( & V_201 , V_194 + V_207 , V_196 - V_207 ) ;
V_207 = ( int ) strlen ( V_194 ) ;
break;
case V_133 :
V_207 += F_238 ( V_194 + V_207 ,
F_264 ( F_184 ( & V_65 -> V_55 ) ,
V_134 , ':' ) ,
V_196 - V_207 ) ;
break;
case V_137 :
V_207 += F_238 ( V_194 + V_207 ,
F_265 ( ( T_29 * ) F_184 ( & V_65 -> V_55 ) ) ,
V_196 - V_207 ) ;
break;
case V_139 :
V_159 = F_184 ( & V_65 -> V_55 ) ;
V_207 += F_238 ( V_194 + V_207 ,
F_266 ( V_159 ,
F_246 ( & V_65 -> V_55 ) ) ,
V_196 - V_207 ) ;
V_208 += F_238 ( V_195 + V_208 ,
F_267 ( V_159 , F_246 ( & V_65 -> V_55 ) ) ,
V_196 - V_208 ) ;
break;
case V_140 :
F_235 ( V_194 + V_207 , V_196 - V_207 ,
L_22 F_268 ( V_226 ) L_23 , F_269 ( & V_65 -> V_55 ) ) ;
V_207 = ( int ) strlen ( V_194 ) ;
break;
case V_141 :
F_235 ( V_194 + V_207 , V_196 - V_207 ,
L_22 F_268 ( V_227 ) L_23 , F_269 ( & V_65 -> V_55 ) ) ;
V_207 = ( int ) strlen ( V_194 ) ;
break;
case V_142 :
case V_143 :
case V_144 :
V_159 = F_184 ( & V_65 -> V_55 ) ;
V_207 += F_238 ( V_194 + V_207 ,
F_270 ( V_159 , strlen ( V_159 ) ) ,
V_196 - V_207 ) ;
break;
case V_129 :
case V_228 :
default:
F_129 ( L_24 ,
V_41 -> type ,
F_130 ( V_41 -> type ) ) ;
F_95 () ;
break;
}
V_206 ++ ;
}
switch ( V_41 -> type ) {
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_165 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_139 :
break;
default:
F_239 ( V_195 , V_194 , V_196 ) ;
break;
}
if ( ! V_171 ) {
V_171 = V_41 -> V_171 ;
}
if ( V_193 == 0 ) {
V_41 = V_41 -> V_210 ;
} else {
V_41 = NULL ;
}
}
return V_171 ? V_171 : L_13 ;
}
void
F_271 ( T_23 * V_80 , const char * V_100 , ... )
{
T_15 * V_157 = NULL ;
T_24 V_73 ;
if ( V_80 == NULL ) {
return;
}
V_157 = F_182 ( V_80 ) ;
if ( V_157 == NULL )
return;
if ( V_157 -> V_178 ) {
F_272 ( V_157 -> V_178 ) ;
}
va_start ( V_73 , V_100 ) ;
F_81 ( V_80 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
}
void
F_273 ( T_23 * V_80 , const char * V_100 , ... )
{
T_15 * V_157 = NULL ;
T_37 V_229 ;
T_24 V_73 ;
if ( V_80 == NULL ) {
return;
}
V_157 = F_182 ( V_80 ) ;
if ( V_157 == NULL ) {
return;
}
if ( ! F_229 ( V_80 ) ) {
if ( V_157 -> V_178 == NULL ) {
F_230 ( V_157 -> V_178 ) ;
F_274 ( V_157 , V_157 -> V_178 -> V_185 ) ;
}
V_229 = strlen ( V_157 -> V_178 -> V_185 ) ;
if ( V_186 > V_229 ) {
va_start ( V_73 , V_100 ) ;
F_236 ( V_157 -> V_178 -> V_185 + V_229 ,
V_186 - ( V_230 ) V_229 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
}
}
}
void
F_275 ( T_23 * V_80 , const char * V_100 , ... )
{
T_15 * V_157 = NULL ;
char V_185 [ V_186 ] ;
T_24 V_73 ;
if ( V_80 == NULL ) {
return;
}
V_157 = F_182 ( V_80 ) ;
if ( V_157 == NULL ) {
return;
}
if ( ! F_229 ( V_80 ) ) {
if ( V_157 -> V_178 == NULL ) {
F_230 ( V_157 -> V_178 ) ;
F_274 ( V_157 , V_157 -> V_178 -> V_185 ) ;
}
F_239 ( V_185 , V_157 -> V_178 -> V_185 , V_186 ) ;
va_start ( V_73 , V_100 ) ;
F_236 ( V_157 -> V_178 -> V_185 ,
V_186 , V_100 , V_73 ) ;
va_end ( V_73 ) ;
F_276 ( V_157 -> V_178 -> V_185 , V_185 , V_186 ) ;
}
}
void
F_72 ( T_23 * V_80 , const T_3 V_97 )
{
T_15 * V_157 ;
if ( V_80 == NULL )
return;
V_157 = F_182 ( V_80 ) ;
if ( V_157 == NULL )
return;
F_26 ( V_97 >= 0 ) ;
V_157 -> V_97 = V_97 ;
if ( V_157 -> V_55 . V_231 -> V_231 == V_113 && V_97 <= ( T_3 ) V_157 -> V_55 . V_55 . V_159 -> V_27 )
V_157 -> V_55 . V_55 . V_159 -> V_27 = V_97 ;
}
void
F_277 ( T_23 * V_80 , T_22 * V_91 , T_3 V_232 )
{
T_15 * V_157 ;
if ( V_80 == NULL )
return;
V_157 = F_182 ( V_80 ) ;
if ( V_157 == NULL )
return;
V_232 += F_226 ( V_91 ) ;
F_26 ( V_232 >= V_157 -> V_101 ) ;
V_157 -> V_97 = V_232 - V_157 -> V_101 ;
}
int
F_278 ( const T_23 * V_80 )
{
T_15 * V_157 = F_182 ( V_80 ) ;
return V_157 ? V_157 -> V_97 : - 1 ;
}
V_38
F_279 ( T_23 * V_80 , const int V_233 , const T_16 V_234 )
{
if ( V_80 == NULL || F_182 ( V_80 ) == NULL )
return FALSE ;
if ( V_234 >= F_280 ( F_182 ( V_80 ) , V_235 ) ) {
F_281 ( F_182 ( V_80 ) , V_236 , V_233 ) ;
F_281 ( F_182 ( V_80 ) , V_235 , V_234 ) ;
return TRUE ;
}
return FALSE ;
}
T_8 *
F_282 ( void )
{
T_10 * V_47 ;
F_221 ( V_47 ) ;
V_47 -> V_61 = NULL ;
F_39 ( V_47 ) = NULL ;
V_47 -> V_63 = F_283 ( T_14 , 1 ) ;
V_47 -> V_63 -> V_64 = NULL ;
V_47 -> V_63 -> V_66 = FALSE ;
V_47 -> V_63 -> V_68 = TRUE ;
V_47 -> V_63 -> V_237 = 0 ;
return ( T_8 * ) V_47 ;
}
void
F_284 ( T_8 * V_45 V_56 , const T_3 V_58 )
{
V_5 * V_41 ;
F_25 ( V_58 , V_41 ) ;
V_41 -> V_59 = V_104 ;
if ( V_41 -> V_61 != - 1 ) {
V_5 * V_62 ;
F_25 ( V_41 -> V_61 , V_62 ) ;
if ( V_62 -> V_59 != V_104 )
V_62 -> V_59 = V_238 ;
}
}
T_8 *
F_74 ( T_23 * V_80 , const T_3 V_239 ) {
T_15 * V_157 ;
if ( ! V_80 )
return NULL ;
F_26 ( V_239 >= 0 && V_239 < V_39 ) ;
V_157 = F_182 ( V_80 ) ;
if ( ! V_157 )
return ( T_8 * ) V_80 ;
V_157 -> V_169 = V_239 ;
return ( T_8 * ) V_80 ;
}
T_8 *
F_285 ( const T_23 * V_80 ) {
T_15 * V_157 ;
if ( ! V_80 )
return NULL ;
V_157 = F_182 ( V_80 ) ;
if ( ( ! V_157 ) || ( V_157 -> V_169 == - 1 ) )
return NULL ;
return ( T_8 * ) V_80 ;
}
T_23 *
F_286 ( const T_23 * V_240 ) {
if ( ! V_240 )
return NULL ;
return V_240 -> V_61 ;
}
T_23 *
F_287 ( T_23 * V_240 , int V_241 ) {
if ( ! V_240 )
return NULL ;
while ( V_241 -- ) {
V_240 = V_240 -> V_61 ;
if ( ! V_240 )
return NULL ;
}
return V_240 ;
}
T_23 *
F_288 ( const T_8 * V_45 ) {
if ( ! V_45 )
return NULL ;
return ( T_23 * ) V_45 ;
}
T_8 *
F_289 ( T_8 * V_45 ) {
if ( ! V_45 )
return NULL ;
while ( V_45 -> V_61 ) {
V_45 = V_45 -> V_61 ;
}
return V_45 ;
}
void
F_290 ( T_8 * V_45 , T_23 * V_242 ,
T_23 * V_243 )
{
if ( ! V_45 || ! F_40 ( V_45 ) -> V_66 )
return;
F_26 ( V_243 -> V_61 == V_45 ) ;
F_26 ( V_242 -> V_61 == V_45 ) ;
if ( V_45 -> V_50 == V_243 ) {
V_45 -> V_50 = V_243 -> V_51 ;
F_26 ( V_45 -> V_172 != V_243 ) ;
} else {
T_23 * V_244 ;
for( V_244 = V_45 -> V_50 ; V_244 != NULL ; V_244 = V_244 -> V_51 ) {
if ( V_244 -> V_51 == V_243 ) {
break;
}
}
F_26 ( V_244 ) ;
V_244 -> V_51 = V_243 -> V_51 ;
if ( V_45 -> V_172 == V_243 ) {
V_45 -> V_172 = V_244 ;
}
}
V_243 -> V_51 = V_242 -> V_51 ;
V_242 -> V_51 = V_243 ;
if ( V_45 -> V_172 == V_242 ) {
V_45 -> V_172 = V_243 ;
}
}
void
F_291 ( T_8 * V_45 , T_22 * V_91 , T_3 V_101 ,
const T_3 V_97 )
{
T_15 * V_157 ;
if ( V_45 == NULL )
return;
V_157 = F_292 ( V_45 ) ;
if ( V_157 == NULL )
return;
V_101 += F_226 ( V_91 ) ;
F_26 ( V_101 >= 0 ) ;
F_26 ( V_97 >= 0 ) ;
V_157 -> V_180 = V_101 ;
V_157 -> V_181 = V_97 ;
}
int
F_293 ( const char * V_170 , const char * V_10 ,
const char * V_245 )
{
T_5 * V_40 ;
V_5 * V_41 ;
int V_42 ;
char * V_246 ;
T_3 * V_54 ;
T_16 V_206 ;
T_38 V_72 ;
V_38 V_247 ;
V_54 = F_294 ( sizeof( T_3 ) ) ;
* V_54 = V_23 ( V_170 ) ;
V_246 = F_58 ( V_18 , V_54 ) ;
if ( V_246 != NULL ) {
F_129 ( L_25
L_26 , V_170 ) ;
}
F_52 ( V_18 , V_54 , ( T_2 ) V_170 ) ;
V_246 = F_58 ( V_22 , ( T_2 ) V_10 ) ;
if ( V_246 != NULL ) {
F_129 ( L_27
L_26 , V_10 ) ;
}
F_52 ( V_22 , ( T_2 ) V_10 , ( T_2 ) V_10 ) ;
V_247 = FALSE ;
for ( V_206 = 0 ; V_245 [ V_206 ] ; V_206 ++ ) {
V_72 = V_245 [ V_206 ] ;
if ( ! ( islower ( V_72 ) || isdigit ( V_72 ) || V_72 == '-' || V_72 == '_' || V_72 == '.' ) ) {
V_247 = TRUE ;
}
}
if ( V_247 ) {
F_129 ( L_28
L_29
L_26 , V_245 ) ;
}
V_246 = F_58 ( V_25 , ( T_2 ) V_245 ) ;
if ( V_246 != NULL ) {
F_129 ( L_30
L_26 , V_245 ) ;
}
F_52 ( V_25 , ( T_2 ) V_245 , ( T_2 ) V_245 ) ;
V_40 = F_283 ( T_5 , 1 ) ;
V_40 -> V_170 = V_170 ;
V_40 -> V_10 = V_10 ;
V_40 -> V_245 = V_245 ;
V_40 -> V_44 = NULL ;
V_40 -> V_248 = TRUE ;
V_40 -> V_249 = TRUE ;
V_40 -> V_250 = FALSE ;
V_36 = F_295 ( V_36 , V_40 ) ;
V_41 = F_296 ( V_5 ) ;
V_41 -> V_170 = V_170 ;
V_41 -> V_171 = V_245 ;
V_41 -> type = V_69 ;
V_41 -> V_212 = V_16 ;
V_41 -> V_214 = V_40 ;
V_41 -> V_1 = 0 ;
V_41 -> V_2 = 0 ;
V_41 -> V_59 = V_60 ;
V_41 -> V_251 = NULL ;
V_41 -> V_61 = - 1 ;
V_42 = F_297 ( V_41 , V_41 -> V_61 ) ;
V_40 -> V_42 = V_42 ;
return V_42 ;
}
void
F_298 ( const int V_42 )
{
T_5 * V_40 = F_299 ( V_42 ) ;
if ( V_40 )
V_40 -> V_250 = TRUE ;
}
V_38
F_300 ( const int V_42 )
{
T_5 * V_40 = F_299 ( V_42 ) ;
if ( V_40 )
return V_40 -> V_250 ;
else
return FALSE ;
}
int
F_301 ( void * * V_252 )
{
T_5 * V_40 ;
if ( V_36 == NULL )
return - 1 ;
* V_252 = V_36 ;
V_40 = V_36 -> V_3 ;
return V_40 -> V_42 ;
}
int
F_302 ( void * V_252 )
{
T_39 * V_253 = V_252 ;
T_5 * V_40 = V_253 -> V_3 ;
return V_40 -> V_42 ;
}
int
F_303 ( void * * V_252 )
{
T_39 * V_253 = * V_252 ;
T_5 * V_40 ;
V_253 = F_304 ( V_253 ) ;
if ( V_253 == NULL )
return - 1 ;
* V_252 = V_253 ;
V_40 = V_253 -> V_3 ;
return V_40 -> V_42 ;
}
V_5 *
F_305 ( const int V_42 , void * * V_252 )
{
T_5 * V_40 = F_299 ( V_42 ) ;
T_7 * V_254 ;
if ( ( V_40 == NULL ) || ( V_40 -> V_44 == NULL ) )
return NULL ;
* V_252 = V_40 -> V_44 ;
V_254 = V_40 -> V_44 -> V_3 ;
return & V_254 -> V_41 ;
}
V_5 *
F_306 ( void * * V_252 )
{
T_39 * V_253 = * V_252 ;
T_7 * V_254 ;
V_253 = F_304 ( V_253 ) ;
if ( V_253 == NULL )
return NULL ;
* V_252 = V_253 ;
V_254 = V_253 -> V_3 ;
return & V_254 -> V_41 ;
}
T_5 *
F_299 ( const int V_42 )
{
V_5 * V_41 ;
if ( V_42 < 0 )
return NULL ;
F_25 ( V_42 , V_41 ) ;
F_26 ( V_41 -> type == V_69 ) ;
return ( T_5 * ) V_41 -> V_214 ;
}
static T_3 F_307 ( T_4 V_255 ,
T_4 V_245 )
{
const T_5 * V_40 = V_255 ;
const T_17 * V_256 = V_245 ;
return ( strcmp ( V_40 -> V_245 , V_256 ) ) ;
}
int
F_308 ( const T_5 * V_40 )
{
return V_40 -> V_42 ;
}
int F_309 ( const T_17 * V_245 )
{
T_39 * V_257 ;
T_5 * V_40 ;
V_257 = F_310 ( V_36 , V_245 ,
F_307 ) ;
if ( V_257 == NULL )
return - 1 ;
V_40 = V_257 -> V_3 ;
return V_40 -> V_42 ;
}
const char *
F_311 ( const int V_42 )
{
T_5 * V_40 ;
V_40 = F_299 ( V_42 ) ;
if ( V_40 == NULL )
return NULL ;
return V_40 -> V_170 ;
}
const char *
F_312 ( const T_5 * V_40 )
{
if ( V_40 == NULL )
return L_31 ;
return V_40 -> V_10 ;
}
const char *
F_313 ( const T_5 * V_40 )
{
if ( V_40 == NULL )
return L_31 ;
return V_40 -> V_170 ;
}
const char *
F_314 ( const int V_42 )
{
T_5 * V_40 ;
V_40 = F_299 ( V_42 ) ;
if ( V_40 == NULL )
return L_31 ;
return V_40 -> V_245 ;
}
V_38
F_315 ( const T_5 * V_40 )
{
return V_40 -> V_248 ;
}
V_38
F_316 ( const int V_42 )
{
T_5 * V_40 ;
V_40 = F_299 ( V_42 ) ;
return V_40 -> V_249 ;
}
void
F_317 ( const int V_42 , const V_38 V_258 )
{
T_5 * V_40 ;
V_40 = F_299 ( V_42 ) ;
F_26 ( V_40 -> V_249 ) ;
V_40 -> V_248 = V_258 ;
}
void
F_318 ( void )
{
T_5 * V_40 ;
T_39 * V_253 = V_36 ;
if ( V_36 == NULL )
return;
while ( V_253 ) {
V_40 = V_253 -> V_3 ;
if ( V_40 -> V_249 )
V_40 -> V_248 = TRUE ;
V_253 = F_304 ( V_253 ) ;
}
}
void
F_319 ( const int V_42 )
{
T_5 * V_40 ;
V_40 = F_299 ( V_42 ) ;
V_40 -> V_249 = FALSE ;
}
void
F_13 ( const int V_61 , T_7 * V_13 , const int V_259 )
{
int V_192 , V_206 ;
T_7 * V_254 = V_13 ;
T_5 * V_260 ;
V_260 = F_299 ( V_61 ) ;
for ( V_206 = 0 ; V_206 < V_259 ; V_206 ++ , V_254 ++ ) {
if ( * V_254 -> V_261 != - 1 && * V_254 -> V_261 != 0 ) {
fprintf ( V_262 ,
L_32 ,
V_254 -> V_41 . V_171 ) ;
return;
}
if ( V_260 != NULL ) {
if ( V_260 -> V_44 == NULL ) {
V_260 -> V_44 = F_320 ( NULL , V_254 ) ;
V_260 -> V_263 = V_260 -> V_44 ;
} else {
V_260 -> V_263 =
F_320 ( V_260 -> V_263 , V_254 ) -> V_51 ;
}
}
V_192 = F_297 ( & V_254 -> V_41 , V_61 ) ;
* V_254 -> V_261 = V_192 ;
}
}
void
F_321 ( const int V_61 , T_3 V_264 )
{
T_7 * V_13 ;
T_5 * V_260 ;
T_39 * V_265 ;
if ( V_264 == - 1 || V_264 == 0 )
return;
V_260 = F_299 ( V_61 ) ;
if ( ! V_260 || ! V_260 -> V_44 ) {
return;
}
for ( V_265 = F_322 ( V_260 -> V_44 ) ; V_265 ; V_265 = F_304 ( V_265 ) ) {
V_13 = V_265 -> V_3 ;
if ( * V_13 -> V_261 == V_264 ) {
F_323 ( V_30 , V_13 -> V_41 . V_171 ) ;
V_260 -> V_44 = F_324 ( V_260 -> V_44 , V_265 ) ;
V_260 -> V_263 = F_325 ( V_260 -> V_44 ) ;
break;
}
}
}
static void
F_326 ( V_5 * V_41 ) {
static const T_40 V_266 [] = {
{ V_15 , L_33 } ,
{ V_69 , L_34 } ,
{ V_116 , L_35 } ,
{ V_117 , L_36 } ,
{ V_118 , L_37 } ,
{ V_119 , L_38 } ,
{ V_120 , L_39 } ,
{ V_122 , L_40 } ,
{ V_123 , L_41 } ,
{ V_124 , L_42 } ,
{ V_125 , L_43 } ,
{ V_126 , L_44 } ,
{ V_121 , L_45 } ,
{ V_135 , L_46 } ,
{ V_140 , L_47 } ,
{ V_141 , L_48 } ,
{ V_146 , L_49 } ,
{ V_152 , L_50 } ,
{ V_142 , L_51 } ,
{ V_143 , L_52 } ,
{ V_144 , L_53 } ,
{ V_133 , L_54 } ,
{ V_113 , L_55 } ,
{ V_114 , L_56 } ,
{ V_127 , L_57 } ,
{ V_131 , L_58 } ,
{ V_129 , L_59 } ,
{ V_165 , L_60 } ,
{ V_228 , L_61 } ,
{ V_137 , L_62 } ,
{ V_139 , L_63 } ,
{ 0 , NULL } } ;
static const T_40 V_267 [] = {
{ V_16 , L_64 } ,
{ V_268 , L_65 } ,
{ V_269 , L_66 } ,
{ V_270 , L_67 } ,
{ V_271 , L_68 } ,
{ V_272 , L_69 } ,
{ V_218 , L_70 } ,
{ V_16 | V_221 , L_71 } ,
{ V_268 | V_221 , L_72 } ,
{ V_269 | V_221 , L_73 } ,
{ V_270 | V_221 , L_74 } ,
{ V_271 | V_221 , L_75 } ,
{ V_272 | V_221 , L_76 } ,
{ V_218 | V_221 , L_77 } ,
{ V_273 , L_78 } ,
{ V_274 , L_79 } ,
{ V_275 , L_80 } ,
{ 0 , NULL } } ;
if ( ! V_41 -> V_170 || ! V_41 -> V_170 [ 0 ] ) {
if ( V_41 -> V_171 )
F_129 ( L_81 ,
V_41 -> V_171 ) ;
else
F_129 ( L_82 ) ;
}
if ( ! V_41 -> V_171 || ! V_41 -> V_171 [ 0 ] )
F_129 ( L_83 , V_41 -> V_170 ) ;
if ( V_41 -> V_214 != NULL && ! (
( V_41 -> type == V_117 ) ||
( V_41 -> type == V_118 ) ||
( V_41 -> type == V_119 ) ||
( V_41 -> type == V_120 ) ||
( V_41 -> type == V_123 ) ||
( V_41 -> type == V_124 ) ||
( V_41 -> type == V_125 ) ||
( V_41 -> type == V_126 ) ||
( V_41 -> type == V_116 ) ||
( V_41 -> type == V_69 ) ||
( V_41 -> type == V_165 ) ) )
F_129 ( L_84
L_85 ,
V_41 -> V_170 , V_41 -> V_171 ,
F_251 ( V_41 -> type , V_266 , L_86 ) ) ;
#if 0
if ((hfinfo->strings != NULL) &&
!(hfinfo->display & BASE_RANGE_STRING) &&
!((hfinfo->display & BASE_DISPLAY_E_MASK) == BASE_CUSTOM) &&
(
(hfinfo->type == FT_UINT8) ||
(hfinfo->type == FT_UINT16) ||
(hfinfo->type == FT_UINT24) ||
(hfinfo->type == FT_UINT32) ||
(hfinfo->type == FT_INT8) ||
(hfinfo->type == FT_INT16) ||
(hfinfo->type == FT_INT24) ||
(hfinfo->type == FT_INT32) ||
(hfinfo->type == FT_FRAMENUM) )) {
int n, m;
const value_string *start_values;
const value_string *current;
if (hfinfo->display & BASE_EXT_STRING)
start_values = VALUE_STRING_EXT_VS_P(((const value_string_ext*)hfinfo->strings));
else
start_values = (const value_string*)hfinfo->strings;
current = start_values;
for (n=0; current; n++, current++) {
if ((current->value == 0) && (current->strptr == NULL)) {
break;
}
for (m=0; m < n; m++) {
if ((start_values[m].value == current->value) &&
(strcmp(start_values[m].strptr, current->strptr) != 0)) {
g_warning("Field '%s' (%s) has a conflicting entry in its"
" value_string: %u is at indices %u (%s) and %u (%s))\n",
hfinfo->name, hfinfo->abbrev,
current->value, m, start_values[m].strptr, n, current->strptr);
}
}
}
}
#endif
switch ( V_41 -> type ) {
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_121 :
if ( V_41 -> V_212 == V_269 ||
V_41 -> V_212 == V_270 )
F_129 ( L_87 ,
V_41 -> V_170 , V_41 -> V_171 ,
F_251 ( V_41 -> type , V_266 , L_86 ) ,
F_251 ( V_41 -> V_212 , V_267 , L_88 ) ) ;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_122 :
if ( V_41 -> V_214 == NULL ) {
if ( V_41 -> V_212 == V_16 )
F_129 ( L_89
L_90 ,
V_41 -> V_170 , V_41 -> V_171 ,
F_251 ( V_41 -> type , V_266 , L_86 ) ) ;
}
break;
case V_69 :
case V_165 :
if ( V_41 -> V_212 != V_16 )
F_129 ( L_91 ,
V_41 -> V_170 , V_41 -> V_171 ,
F_251 ( V_41 -> type , V_266 , L_86 ) ,
F_251 ( V_41 -> V_212 , V_267 , L_88 ) ) ;
if ( V_41 -> V_1 != 0 )
F_129 ( L_92 ,
V_41 -> V_170 , V_41 -> V_171 ,
F_251 ( V_41 -> type , V_266 , L_86 ) ) ;
break;
case V_116 :
break;
case V_146 :
if ( ! ( V_41 -> V_212 == V_273 ||
V_41 -> V_212 == V_274 ||
V_41 -> V_212 == V_275 ) )
F_129 ( L_93 ,
V_41 -> V_170 , V_41 -> V_171 ,
F_251 ( V_41 -> type , V_266 , L_86 ) ,
F_251 ( V_41 -> V_212 , V_267 , L_88 ) ) ;
if ( V_41 -> V_1 != 0 )
F_129 ( L_92 ,
V_41 -> V_170 , V_41 -> V_171 ,
F_251 ( V_41 -> type , V_266 , L_86 ) ) ;
break;
default:
if ( V_41 -> V_212 != V_16 )
F_129 ( L_91 ,
V_41 -> V_170 , V_41 -> V_171 ,
F_251 ( V_41 -> type , V_266 , L_86 ) ,
F_251 ( V_41 -> V_212 , V_267 , L_88 ) ) ;
if ( V_41 -> V_1 != 0 )
F_129 ( L_92 ,
V_41 -> V_170 , V_41 -> V_171 ,
F_251 ( V_41 -> type , V_266 , L_86 ) ) ;
if ( V_41 -> V_214 != NULL )
F_129 ( L_94 ,
V_41 -> V_170 , V_41 -> V_171 ,
F_251 ( V_41 -> type , V_266 , L_86 ) ) ;
break;
}
}
static int
F_297 ( V_5 * V_41 , const int V_61 )
{
F_326 ( V_41 ) ;
if ( V_41 -> V_1 ) {
V_41 -> V_2 = F_1 ( V_41 -> V_1 ) ;
}
V_41 -> V_61 = V_61 ;
V_41 -> V_211 = NULL ;
V_41 -> V_210 = NULL ;
if ( V_26 . V_27 >= V_26 . V_28 ) {
if ( ! V_26 . V_29 ) {
V_26 . V_28 = V_276 ;
V_26 . V_29 = F_294 ( sizeof( V_5 * ) * V_276 ) ;
} else {
V_26 . V_28 += 1000 ;
V_26 . V_29 = F_327 ( V_26 . V_29 ,
sizeof( V_5 * ) * V_26 . V_28 ) ;
}
}
V_26 . V_29 [ V_26 . V_27 ] = V_41 ;
V_26 . V_27 ++ ;
V_41 -> V_43 = V_26 . V_27 - 1 ;
if ( ( V_41 -> V_170 [ 0 ] != 0 ) && ( V_41 -> V_171 [ 0 ] != 0 ) ) {
V_5 * V_277 ;
T_38 V_72 ;
V_72 = F_328 ( V_278 , V_41 -> V_171 ) ;
if ( V_72 ) {
fprintf ( V_262 , L_95 , V_72 , V_41 -> V_171 ) ;
F_26 ( ! V_72 ) ;
}
V_4 = NULL ;
F_329 ( V_30 , ( T_2 ) ( V_41 -> V_171 ) , V_41 ) ;
if ( V_4 ) {
V_277 =
V_4 -> V_211 ;
V_41 -> V_211 = V_277 ;
if ( V_277 )
V_277 -> V_210 = V_41 ;
V_4 -> V_211 = V_41 ;
V_41 -> V_210 = V_4 ;
}
}
return V_41 -> V_43 ;
}
void
F_330 ( T_3 * const * V_279 , const int V_280 )
{
int V_206 ;
T_3 * const * V_254 = V_279 ;
if ( V_37 != NULL ) {
V_37 =
F_327 ( V_37 ,
( V_39 + V_280 ) * sizeof ( V_38 ) ) ;
memset ( V_37 + V_39 , 0 ,
V_280 * sizeof ( V_38 ) ) ;
}
for ( V_206 = 0 ; V_206 < V_280 ; V_206 ++ , V_254 ++ , V_39 ++ ) {
if ( * * V_254 != - 1 ) {
F_129 ( L_96
L_97
L_98
L_99 ) ;
}
* * V_254 = V_39 ;
}
}
void
F_274 ( T_15 * V_157 , T_17 * V_281 )
{
V_5 * V_41 ;
T_27 * V_159 ;
T_1 integer ;
T_30 V_282 ;
T_33 * V_198 ;
T_29 * V_161 ;
T_1 V_202 ;
const T_17 * V_170 ;
int V_182 ;
if ( ! V_157 ) {
if ( V_281 )
V_281 [ 0 ] = '\0' ;
return;
}
V_41 = V_157 -> V_41 ;
switch ( V_41 -> type ) {
case V_15 :
case V_69 :
F_239 ( V_281 , V_41 -> V_170 , V_186 ) ;
break;
case V_116 :
F_331 ( V_157 , V_281 ) ;
break;
case V_113 :
case V_114 :
V_159 = F_184 ( & V_157 -> V_55 ) ;
if ( V_159 ) {
V_182 = F_235 ( V_281 , V_186 ,
L_100 , V_41 -> V_170 ,
F_245 ( V_159 , F_246 ( & V_157 -> V_55 ) ) ) ;
if ( V_182 >= V_186 ) {
F_235 ( V_281 , V_186 ,
L_101 ,
V_41 -> V_170 ,
F_245 ( V_159 , F_246 ( & V_157 -> V_55 ) ) ) ;
}
}
else {
F_235 ( V_281 , V_186 , L_102 , V_41 -> V_170 ) ;
}
break;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
if ( V_41 -> V_1 ) {
F_332 ( V_157 , V_281 ) ;
} else {
F_333 ( V_157 , V_281 ) ;
}
break;
case V_165 :
F_333 ( V_157 , V_281 ) ;
break;
case V_122 :
F_334 ( V_157 , V_281 ) ;
break;
case V_123 :
case V_124 :
case V_125 :
case V_126 :
F_26 ( ! V_41 -> V_1 ) ;
F_335 ( V_157 , V_281 ) ;
break;
case V_121 :
F_336 ( V_157 , V_281 ) ;
break;
case V_140 :
F_235 ( V_281 , V_186 ,
L_103 F_268 ( V_226 ) L_23 ,
V_41 -> V_170 , F_269 ( & V_157 -> V_55 ) ) ;
break;
case V_141 :
F_235 ( V_281 , V_186 ,
L_103 F_268 ( V_227 ) L_23 ,
V_41 -> V_170 , F_269 ( & V_157 -> V_55 ) ) ;
break;
case V_146 :
F_235 ( V_281 , V_186 ,
L_100 , V_41 -> V_170 ,
F_247 ( F_184 ( & V_157 -> V_55 ) , V_41 -> V_212 , TRUE ) ) ;
break;
case V_152 :
F_235 ( V_281 , V_186 ,
L_104 , V_41 -> V_170 ,
F_248 ( F_184 ( & V_157 -> V_55 ) ) ) ;
break;
case V_129 :
integer = F_232 ( & V_157 -> V_55 ) ;
F_235 ( V_281 , V_186 ,
L_105 , V_41 -> V_170 ,
F_337 ( integer ) , integer ) ;
break;
case V_133 :
V_159 = F_184 ( & V_157 -> V_55 ) ;
F_235 ( V_281 , V_186 ,
L_106 , V_41 -> V_170 ,
F_338 ( V_159 ) ,
F_339 ( V_159 ) ) ;
break;
case V_127 :
V_198 = F_184 ( & V_157 -> V_55 ) ;
V_202 = F_260 ( V_198 ) ;
F_235 ( V_281 , V_186 ,
L_106 , V_41 -> V_170 ,
F_340 ( V_202 ) ,
F_261 ( ( T_27 * ) & V_202 ) ) ;
break;
case V_131 :
V_159 = F_184 ( & V_157 -> V_55 ) ;
F_235 ( V_281 , V_186 ,
L_106 , V_41 -> V_170 ,
F_341 ( (struct V_199 * ) V_159 ) ,
F_342 ( (struct V_199 * ) V_159 ) ) ;
break;
case V_137 :
V_161 = F_184 ( & V_157 -> V_55 ) ;
F_235 ( V_281 , V_186 ,
L_100 , V_41 -> V_170 ,
F_265 ( V_161 ) ) ;
break;
case V_139 :
V_159 = F_184 ( & V_157 -> V_55 ) ;
V_170 = F_266 ( V_159 , F_246 ( & V_157 -> V_55 ) ) ;
if ( V_170 ) {
F_235 ( V_281 , V_186 ,
L_106 , V_41 -> V_170 ,
F_267 ( V_159 , F_246 ( & V_157 -> V_55 ) ) , V_170 ) ;
} else {
F_235 ( V_281 , V_186 ,
L_100 , V_41 -> V_170 ,
F_267 ( V_159 , F_246 ( & V_157 -> V_55 ) ) ) ;
}
break;
case V_135 :
V_282 = F_256 ( & V_157 -> V_55 ) ;
F_235 ( V_281 , V_186 ,
L_106 , V_41 -> V_170 ,
F_343 ( V_282 ) ,
F_257 ( V_282 ) ) ;
break;
case V_142 :
case V_143 :
case V_144 :
V_159 = F_184 ( & V_157 -> V_55 ) ;
V_182 = F_235 ( V_281 , V_186 ,
L_100 , V_41 -> V_170 ,
F_270 ( V_159 , strlen ( V_159 ) ) ) ;
if ( V_182 >= V_186 ) {
F_235 ( V_281 , V_186 ,
L_101 , V_41 -> V_170 ,
F_270 ( V_159 , strlen ( V_159 ) ) ) ;
}
break;
default:
F_129 ( L_24 ,
V_41 -> type , F_130 ( V_41 -> type ) ) ;
F_95 () ;
break;
}
}
static void
F_331 ( T_15 * V_157 , T_17 * V_281 )
{
char * V_283 = V_281 ;
int V_284 = 0 , V_285 ;
T_1 V_286 ;
T_1 V_55 ;
V_5 * V_41 = V_157 -> V_41 ;
const T_35 * V_203 = ( const T_35 * ) & V_213 ;
if ( V_41 -> V_214 ) {
V_203 = ( const struct T_35 * ) V_41 -> V_214 ;
}
V_55 = F_232 ( & V_157 -> V_55 ) ;
if ( V_41 -> V_1 ) {
V_285 = F_234 ( V_41 ) ;
V_286 = V_55 ;
if ( V_41 -> V_2 > 0 ) {
V_286 <<= V_41 -> V_2 ;
}
V_283 = F_233 ( V_281 , V_286 , V_41 -> V_1 , V_285 ) ;
V_284 = ( int ) ( V_283 - V_281 ) ;
}
F_235 ( V_283 , V_186 - V_284 ,
L_100 , V_41 -> V_170 ,
V_55 ? V_203 -> V_215 : V_203 -> V_216 ) ;
}
static void
F_332 ( T_15 * V_157 , T_17 * V_281 )
{
const char * V_100 = NULL ;
char * V_283 ;
int V_284 , V_285 ;
T_1 V_286 ;
T_1 V_55 ;
V_5 * V_41 = V_157 -> V_41 ;
V_285 = F_234 ( V_41 ) ;
V_286 = F_232 ( & V_157 -> V_55 ) ;
V_55 = V_286 ;
if ( V_41 -> V_2 > 0 ) {
V_286 <<= V_41 -> V_2 ;
}
V_283 = F_233 ( V_281 , V_286 , V_41 -> V_1 , V_285 ) ;
V_284 = ( int ) ( V_283 - V_281 ) ;
if ( V_41 -> V_212 == V_218 ) {
T_17 V_219 [ V_186 ] ;
T_36 V_220 = ( T_36 ) V_41 -> V_214 ;
F_26 ( V_220 ) ;
V_220 ( V_219 , V_55 ) ;
F_235 ( V_283 , V_186 - V_284 ,
L_100 , V_41 -> V_170 , V_219 ) ;
}
else if ( V_41 -> V_214 ) {
V_100 = F_344 ( V_41 ) ;
if ( V_41 -> V_212 & V_221 ) {
F_235 ( V_283 , V_186 - V_284 ,
V_100 , V_41 -> V_170 ,
F_249 ( V_55 , V_41 -> V_214 , L_107 ) , V_55 ) ;
} else if ( V_41 -> V_212 & V_222 ) {
F_235 ( V_283 , V_186 - V_284 ,
V_100 , V_41 -> V_170 ,
F_345 ( V_55 , ( V_223 * ) V_41 -> V_214 , L_107 ) , V_55 ) ;
} else {
F_235 ( V_283 , V_186 - V_284 ,
V_100 , V_41 -> V_170 ,
F_346 ( V_55 , F_252 ( V_41 -> V_214 ) , L_107 ) , V_55 ) ;
}
}
else {
V_100 = F_347 ( V_41 ) ;
if ( F_253 ( V_41 -> V_212 ) ) {
F_235 ( V_283 , V_186 - V_284 ,
V_100 , V_41 -> V_170 , V_55 , V_55 ) ;
} else {
F_235 ( V_283 , V_186 - V_284 ,
V_100 , V_41 -> V_170 , V_55 ) ;
}
}
}
static void
F_333 ( T_15 * V_157 , T_17 * V_281 )
{
const char * V_100 = NULL ;
V_5 * V_41 = V_157 -> V_41 ;
T_1 V_55 ;
V_55 = F_232 ( & V_157 -> V_55 ) ;
if ( V_41 -> V_212 == V_218 ) {
T_17 V_219 [ V_186 ] ;
T_36 V_220 = ( T_36 ) V_41 -> V_214 ;
F_26 ( V_220 ) ;
V_220 ( V_219 , V_55 ) ;
F_235 ( V_281 , V_186 , L_100 , V_41 -> V_170 , V_219 ) ;
}
else if ( V_41 -> V_214 ) {
V_100 = F_344 ( V_41 ) ;
if ( V_41 -> V_212 & V_221 ) {
F_235 ( V_281 , V_186 ,
V_100 , V_41 -> V_170 ,
F_249 ( V_55 , V_41 -> V_214 , L_107 ) , V_55 ) ;
} else if ( V_41 -> V_212 & V_222 ) {
F_235 ( V_281 , V_186 ,
V_100 , V_41 -> V_170 ,
F_345 ( V_55 , ( V_223 * ) V_41 -> V_214 , L_107 ) , V_55 ) ;
} else {
F_235 ( V_281 , V_186 ,
V_100 , V_41 -> V_170 ,
F_346 ( V_55 , F_252 ( V_41 -> V_214 ) , L_107 ) , V_55 ) ;
}
}
else {
V_100 = F_347 ( V_41 ) ;
if ( F_253 ( V_41 -> V_212 ) ) {
F_235 ( V_281 , V_186 ,
V_100 , V_41 -> V_170 , V_55 , V_55 ) ;
} else {
F_235 ( V_281 , V_186 ,
V_100 , V_41 -> V_170 , V_55 ) ;
}
}
}
static void
F_334 ( T_15 * V_157 , T_17 * V_281 )
{
const char * V_100 = NULL ;
V_5 * V_41 = V_157 -> V_41 ;
T_30 V_55 ;
V_100 = F_348 ( V_41 ) ;
V_55 = F_256 ( & V_157 -> V_55 ) ;
if ( F_253 ( V_41 -> V_212 ) ) {
F_235 ( V_281 , V_186 ,
V_100 , V_41 -> V_170 , V_55 , V_55 ) ;
} else {
F_235 ( V_281 , V_186 ,
V_100 , V_41 -> V_170 , V_55 ) ;
}
}
static void
F_335 ( T_15 * V_157 , T_17 * V_281 )
{
const char * V_100 = NULL ;
V_5 * V_41 = V_157 -> V_41 ;
T_1 V_55 ;
V_55 = F_258 ( & V_157 -> V_55 ) ;
if ( V_41 -> V_212 == V_218 ) {
T_17 V_219 [ V_186 ] ;
T_36 V_220 = ( T_36 ) V_41 -> V_214 ;
F_26 ( V_220 ) ;
V_220 ( V_219 , V_55 ) ;
F_235 ( V_281 , V_186 , L_100 , V_41 -> V_170 , V_219 ) ;
}
else if ( V_41 -> V_214 ) {
V_100 = F_349 ( V_41 ) ;
if ( V_41 -> V_212 & V_221 ) {
F_235 ( V_281 , V_186 ,
V_100 , V_41 -> V_170 ,
F_249 ( V_55 , V_41 -> V_214 , L_107 ) , V_55 ) ;
} else if ( V_41 -> V_212 & V_222 ) {
F_235 ( V_281 , V_186 ,
V_100 , V_41 -> V_170 ,
F_345 ( V_55 , ( V_223 * ) V_41 -> V_214 , L_107 ) , V_55 ) ;
} else {
F_235 ( V_281 , V_186 ,
V_100 , V_41 -> V_170 ,
F_346 ( V_55 , F_252 ( V_41 -> V_214 ) , L_107 ) , V_55 ) ;
}
}
else {
V_100 = F_350 ( V_41 ) ;
if ( F_253 ( V_41 -> V_212 ) ) {
F_235 ( V_281 , V_186 ,
V_100 , V_41 -> V_170 , V_55 , V_55 ) ;
} else {
F_235 ( V_281 , V_186 ,
V_100 , V_41 -> V_170 , V_55 ) ;
}
}
}
static void
F_336 ( T_15 * V_157 , T_17 * V_281 )
{
const char * V_100 = NULL ;
V_5 * V_41 = V_157 -> V_41 ;
T_30 V_55 ;
V_100 = F_351 ( V_41 ) ;
V_55 = F_256 ( & V_157 -> V_55 ) ;
if ( F_253 ( V_41 -> V_212 ) ) {
F_235 ( V_281 , V_186 ,
V_100 , V_41 -> V_170 , V_55 , V_55 ) ;
} else {
F_235 ( V_281 , V_186 ,
V_100 , V_41 -> V_170 , V_55 ) ;
}
}
int
F_234 ( const V_5 * V_41 )
{
int V_285 = 0 ;
if ( ! V_41 -> V_1 ) {
return 0 ;
}
switch ( V_41 -> type ) {
case V_117 :
case V_123 :
V_285 = 8 ;
break;
case V_118 :
case V_124 :
V_285 = 16 ;
break;
case V_119 :
case V_125 :
V_285 = 24 ;
break;
case V_120 :
case V_126 :
V_285 = 32 ;
break;
case V_116 :
V_285 = V_41 -> V_212 ;
break;
default:
F_95 () ;
;
}
return V_285 ;
}
static const char *
F_344 ( const V_5 * V_41 )
{
const char * V_100 = NULL ;
switch ( V_41 -> V_212 & V_217 ) {
case V_16 :
V_100 = L_100 ;
break;
case V_268 :
case V_271 :
V_100 = L_108 ;
break;
case V_270 :
V_100 = L_109 ;
break;
case V_269 :
case V_272 :
switch ( V_41 -> type ) {
case V_117 :
V_100 = L_110 ;
break;
case V_118 :
V_100 = L_111 ;
break;
case V_119 :
V_100 = L_112 ;
break;
case V_120 :
V_100 = L_113 ;
break;
default:
F_95 () ;
;
}
break;
default:
F_95 () ;
;
}
return V_100 ;
}
static const char *
F_347 ( const V_5 * V_41 )
{
const char * V_100 = NULL ;
if ( V_41 -> type == V_165 ) {
V_100 = L_114 ;
} else {
switch ( V_41 -> V_212 ) {
case V_268 :
V_100 = L_114 ;
break;
case V_271 :
switch ( V_41 -> type ) {
case V_117 :
V_100 = L_115 ;
break;
case V_118 :
V_100 = L_116 ;
break;
case V_119 :
V_100 = L_117 ;
break;
case V_120 :
V_100 = L_118 ;
break;
default:
F_95 () ;
;
}
break;
case V_270 :
V_100 = L_119 ;
break;
case V_269 :
switch ( V_41 -> type ) {
case V_117 :
V_100 = L_120 ;
break;
case V_118 :
V_100 = L_121 ;
break;
case V_119 :
V_100 = L_122 ;
break;
case V_120 :
V_100 = L_123 ;
break;
default:
F_95 () ;
;
}
break;
case V_272 :
switch ( V_41 -> type ) {
case V_117 :
V_100 = L_124 ;
break;
case V_118 :
V_100 = L_125 ;
break;
case V_119 :
V_100 = L_126 ;
break;
case V_120 :
V_100 = L_127 ;
break;
default:
F_95 () ;
;
}
break;
default:
F_95 () ;
;
}
}
return V_100 ;
}
static const char *
F_254 ( const V_5 * V_41 )
{
const char * V_100 = NULL ;
if ( V_41 -> type == V_165 ) {
V_100 = L_15 ;
} else {
switch ( V_41 -> V_212 ) {
case V_268 :
V_100 = L_15 ;
break;
case V_271 :
switch ( V_41 -> type ) {
case V_117 :
V_100 = L_128 ;
break;
case V_118 :
V_100 = L_129 ;
break;
case V_119 :
V_100 = L_130 ;
break;
case V_120 :
V_100 = L_131 ;
break;
default:
F_95 () ;
;
}
break;
case V_270 :
V_100 = L_132 ;
break;
case V_269 :
switch ( V_41 -> type ) {
case V_117 :
V_100 = L_133 ;
break;
case V_118 :
V_100 = L_134 ;
break;
case V_119 :
V_100 = L_135 ;
break;
case V_120 :
V_100 = L_136 ;
break;
default:
F_95 () ;
;
}
break;
case V_272 :
switch ( V_41 -> type ) {
case V_117 :
V_100 = L_137 ;
break;
case V_118 :
V_100 = L_138 ;
break;
case V_119 :
V_100 = L_139 ;
break;
case V_120 :
V_100 = L_140 ;
break;
default:
F_95 () ;
;
}
break;
default:
F_95 () ;
;
}
}
return V_100 ;
}
static const char *
F_349 ( const V_5 * V_41 )
{
const char * V_100 = NULL ;
switch ( V_41 -> V_212 & V_217 ) {
case V_16 :
V_100 = L_100 ;
break;
case V_268 :
case V_271 :
V_100 = L_141 ;
break;
case V_270 :
V_100 = L_109 ;
break;
case V_269 :
case V_272 :
switch ( V_41 -> type ) {
case V_123 :
V_100 = L_110 ;
break;
case V_124 :
V_100 = L_111 ;
break;
case V_125 :
V_100 = L_112 ;
break;
case V_126 :
V_100 = L_113 ;
break;
default:
F_95 () ;
;
}
break;
default:
F_95 () ;
;
}
return V_100 ;
}
static const char *
F_348 ( const V_5 * V_41 )
{
const char * V_100 = NULL ;
switch ( V_41 -> V_212 ) {
case V_268 :
V_100 = L_142 V_224 L_20 ;
break;
case V_271 :
V_100 = L_142 V_224 L_143 V_224 L_144 ;
break;
case V_270 :
V_100 = L_145 V_224 L_146 ;
break;
case V_269 :
V_100 = L_147 V_224 L_148 ;
break;
case V_272 :
V_100 = L_147 V_224 L_149 V_224 L_150 ;
break;
default:
F_95 () ;
;
}
return V_100 ;
}
static const char *
F_350 ( const V_5 * V_41 )
{
const char * V_100 = NULL ;
switch ( V_41 -> V_212 ) {
case V_268 :
V_100 = L_151 ;
break;
case V_271 :
switch ( V_41 -> type ) {
case V_123 :
V_100 = L_152 ;
break;
case V_124 :
V_100 = L_153 ;
break;
case V_125 :
V_100 = L_154 ;
break;
case V_126 :
V_100 = L_155 ;
break;
default:
F_95 () ;
;
}
break;
case V_270 :
V_100 = L_119 ;
break;
case V_269 :
switch ( V_41 -> type ) {
case V_123 :
V_100 = L_120 ;
break;
case V_124 :
V_100 = L_121 ;
break;
case V_125 :
V_100 = L_122 ;
break;
case V_126 :
V_100 = L_123 ;
break;
default:
F_95 () ;
;
}
break;
case V_272 :
switch ( V_41 -> type ) {
case V_123 :
V_100 = L_156 ;
break;
case V_124 :
V_100 = L_157 ;
break;
case V_125 :
V_100 = L_158 ;
break;
case V_126 :
V_100 = L_159 ;
break;
default:
F_95 () ;
;
}
break;
default:
F_95 () ;
;
}
return V_100 ;
}
static const char *
F_259 ( const V_5 * V_41 )
{
const char * V_100 = NULL ;
switch ( V_41 -> V_212 ) {
case V_268 :
V_100 = L_21 ;
break;
case V_271 :
switch ( V_41 -> type ) {
case V_123 :
V_100 = L_160 ;
break;
case V_124 :
V_100 = L_161 ;
break;
case V_125 :
V_100 = L_162 ;
break;
case V_126 :
V_100 = L_163 ;
break;
default:
F_95 () ;
;
}
break;
case V_270 :
V_100 = L_132 ;
break;
case V_269 :
switch ( V_41 -> type ) {
case V_123 :
V_100 = L_133 ;
break;
case V_124 :
V_100 = L_134 ;
break;
case V_125 :
V_100 = L_135 ;
break;
case V_126 :
V_100 = L_136 ;
break;
default:
F_95 () ;
;
}
break;
case V_272 :
switch ( V_41 -> type ) {
case V_123 :
V_100 = L_164 ;
break;
case V_124 :
V_100 = L_165 ;
break;
case V_125 :
V_100 = L_166 ;
break;
case V_126 :
V_100 = L_167 ;
break;
default:
F_95 () ;
;
}
break;
default:
F_95 () ;
;
}
return V_100 ;
}
static const char *
F_351 ( const V_5 * V_41 )
{
const char * V_100 = NULL ;
switch ( V_41 -> V_212 ) {
case V_268 :
V_100 = L_142 V_224 L_19 ;
break;
case V_271 :
V_100 = L_142 V_224 L_168 V_224 L_144 ;
break;
case V_270 :
V_100 = L_145 V_224 L_146 ;
break;
case V_269 :
V_100 = L_147 V_224 L_148 ;
break;
case V_272 :
V_100 = L_147 V_224 L_149 V_224 L_169 ;
break;
default:
F_95 () ;
;
}
return V_100 ;
}
int
F_352 ( void )
{
return V_26 . V_27 ;
}
const char *
F_353 ( const int V_108 )
{
V_5 * V_41 ;
F_25 ( V_108 , V_41 ) ;
return V_41 -> V_170 ;
}
const char *
F_354 ( const int V_108 )
{
V_5 * V_41 ;
F_25 ( V_108 , V_41 ) ;
return V_41 -> V_171 ;
}
enum V_287
F_355 ( const int V_108 )
{
V_5 * V_41 ;
F_25 ( V_108 , V_41 ) ;
return V_41 -> type ;
}
int
F_356 ( const int V_108 )
{
V_5 * V_41 ;
F_25 ( V_108 , V_41 ) ;
return V_41 -> V_61 ;
}
V_38
F_357 ( const int V_108 )
{
V_5 * V_41 ;
F_25 ( V_108 , V_41 ) ;
return ( V_41 -> V_61 == - 1 ? TRUE : FALSE ) ;
}
T_3
F_358 ( const int V_108 )
{
V_5 * V_41 ;
F_25 ( V_108 , V_41 ) ;
return F_359 ( V_41 -> type ) ;
}
V_38
F_360 ( const T_8 * V_45 , const int V_43 )
{
T_13 * V_57 = F_242 ( V_45 , V_43 ) ;
if ( ! V_57 ) {
return FALSE ;
}
else if ( F_243 ( V_57 ) > 0 ) {
return TRUE ;
}
else {
return FALSE ;
}
}
T_13 *
F_242 ( const T_8 * V_45 , const int V_43 )
{
if ( ! V_45 )
return NULL ;
if ( F_40 ( V_45 ) -> V_64 != NULL )
return F_58 ( F_40 ( V_45 ) -> V_64 ,
F_98 ( V_43 ) ) ;
else
return NULL ;
}
V_38
F_361 ( const T_8 * V_45 )
{
if ( ! V_45 )
return FALSE ;
return ( F_40 ( V_45 ) -> V_64 != NULL ) ;
}
static V_38
F_362 ( T_10 * V_52 , T_2 V_3 )
{
T_15 * V_157 = F_39 ( V_52 ) ;
if ( V_157 && V_157 -> V_41 ) {
if ( V_157 -> V_41 -> V_43 == ( ( V_288 * ) V_3 ) -> V_43 ) {
F_133 ( ( ( V_288 * ) V_3 ) -> V_289 , V_157 ) ;
}
}
return FALSE ;
}
T_13 *
F_363 ( T_8 * V_45 , const int V_43 )
{
V_288 V_290 ;
V_290 . V_289 = F_99 () ;
V_290 . V_43 = V_43 ;
F_31 ( V_45 , F_362 , & V_290 ) ;
return V_290 . V_289 ;
}
static V_38
F_364 ( T_10 * V_52 , T_2 V_3 )
{
T_15 * V_157 = F_39 ( V_52 ) ;
if ( V_157 && V_157 -> V_41 ) {
F_133 ( ( ( V_288 * ) V_3 ) -> V_289 , V_157 ) ;
}
return FALSE ;
}
T_13 *
F_365 ( T_8 * V_45 )
{
V_288 V_290 ;
V_290 . V_289 = F_99 () ;
V_290 . V_43 = 0 ;
F_31 ( V_45 , F_364 , & V_290 ) ;
return V_290 . V_289 ;
}
static V_38
F_366 ( T_10 * V_52 , const T_2 V_3 )
{
T_15 * V_157 = F_39 ( V_52 ) ;
T_41 * V_291 = V_3 ;
if ( V_157 && ! F_229 ( V_52 ) && V_157 -> V_179 && V_291 -> V_91 == V_157 -> V_179 ) {
if ( V_291 -> V_92 >= ( T_16 ) V_157 -> V_101 &&
V_291 -> V_92 < ( T_16 ) ( V_157 -> V_101 + V_157 -> V_97 ) ) {
V_291 -> V_65 = V_157 ;
return FALSE ;
}
}
return FALSE ;
}
T_15 *
F_367 ( T_8 * V_45 , T_16 V_92 , T_22 * V_91 )
{
T_41 V_291 ;
V_291 . V_92 = V_92 ;
V_291 . V_65 = NULL ;
V_291 . V_91 = V_91 ;
F_31 ( V_45 , F_366 , & V_291 ) ;
return V_291 . V_65 ;
}
void
F_368 ( void )
{
T_5 * V_40 ;
int V_206 ;
void * V_252 = NULL ;
V_206 = F_301 ( & V_252 ) ;
while ( V_206 != - 1 ) {
V_40 = F_299 ( V_206 ) ;
printf ( L_170 , V_40 -> V_170 , V_40 -> V_10 ,
V_40 -> V_245 ) ;
V_206 = F_303 ( & V_252 ) ;
}
}
void
F_369 ( void )
{
V_5 * V_41 ;
int V_206 , V_27 , V_292 ;
const T_40 * V_293 ;
const T_42 * V_294 ;
const T_35 * V_295 ;
V_27 = V_26 . V_27 ;
for ( V_206 = 0 ; V_206 < V_27 ; V_206 ++ ) {
F_25 ( V_206 , V_41 ) ;
if ( V_41 -> V_43 == V_14 ) {
continue;
}
if ( F_357 ( V_206 ) ) {
continue;
}
else {
if ( V_41 -> V_210 != NULL )
continue;
V_293 = NULL ;
V_294 = NULL ;
V_295 = NULL ;
if ( V_41 -> V_214 != NULL ) {
if ( ( V_41 -> V_212 & V_217 ) != V_218 &&
( V_41 -> type == V_117 ||
V_41 -> type == V_118 ||
V_41 -> type == V_119 ||
V_41 -> type == V_120 ||
V_41 -> type == V_122 ||
V_41 -> type == V_123 ||
V_41 -> type == V_124 ||
V_41 -> type == V_125 ||
V_41 -> type == V_126 ||
V_41 -> type == V_121 ) ) {
if ( V_41 -> V_212 & V_222 ) {
V_293 = F_370 ( ( V_223 * ) V_41 -> V_214 ) ;
} else if ( ( V_41 -> V_212 & V_221 ) == 0 ) {
V_293 = V_41 -> V_214 ;
} else {
V_294 = V_41 -> V_214 ;
}
}
else if ( V_41 -> type == V_116 ) {
V_295 = V_41 -> V_214 ;
}
}
if ( V_293 ) {
if ( V_41 -> V_212 & V_222 ) {
V_223 * V_296 = ( V_223 * ) V_41 -> V_214 ;
if ( ! F_371 ( V_296 ) ) {
F_372 ( L_171 , V_41 -> V_171 ) ;
continue;
}
F_373 ( 0 , V_296 ) ;
printf ( L_172 ,
V_41 -> V_171 ,
F_374 ( V_296 ) ,
F_375 ( V_296 ) ,
F_376 ( V_296 ) ) ;
}
V_292 = 0 ;
while ( V_293 [ V_292 ] . V_297 ) {
if ( V_41 -> V_212 == V_269 ) {
printf ( L_173 ,
V_41 -> V_171 ,
V_293 [ V_292 ] . V_55 ,
V_293 [ V_292 ] . V_297 ) ;
}
else {
printf ( L_174 ,
V_41 -> V_171 ,
V_293 [ V_292 ] . V_55 ,
V_293 [ V_292 ] . V_297 ) ;
}
V_292 ++ ;
}
}
else if ( V_294 ) {
V_292 = 0 ;
while ( V_294 [ V_292 ] . V_297 ) {
if ( ( V_41 -> V_212 & V_217 ) == V_269 ) {
printf ( L_175 ,
V_41 -> V_171 ,
V_294 [ V_292 ] . V_298 ,
V_294 [ V_292 ] . V_299 ,
V_294 [ V_292 ] . V_297 ) ;
}
else {
printf ( L_176 ,
V_41 -> V_171 ,
V_294 [ V_292 ] . V_298 ,
V_294 [ V_292 ] . V_299 ,
V_294 [ V_292 ] . V_297 ) ;
}
V_292 ++ ;
}
}
else if ( V_295 ) {
printf ( L_177 , V_41 -> V_171 ,
V_295 -> V_215 , V_295 -> V_216 ) ;
}
}
}
}
void
F_377 ( const int V_100 )
{
V_5 * V_41 , * V_62 ;
int V_206 , V_27 ;
const char * V_300 ;
const char * V_301 ;
const char * V_251 ;
char V_302 [ 5 ] ;
V_27 = V_26 . V_27 ;
for ( V_206 = 0 ; V_206 < V_27 ; V_206 ++ ) {
F_25 ( V_206 , V_41 ) ;
if ( V_41 -> V_43 == V_14 )
continue;
if ( F_357 ( V_206 ) ) {
printf ( L_178 , V_41 -> V_170 , V_41 -> V_171 ) ;
}
else {
if ( V_41 -> V_210 != NULL )
continue;
F_25 ( V_41 -> V_61 , V_62 ) ;
V_300 = F_130 ( V_41 -> type ) ;
V_301 = L_13 ;
if ( V_100 > 1 ) {
if ( V_41 -> type == V_117 ||
V_41 -> type == V_118 ||
V_41 -> type == V_119 ||
V_41 -> type == V_120 ||
V_41 -> type == V_122 ||
V_41 -> type == V_123 ||
V_41 -> type == V_124 ||
V_41 -> type == V_125 ||
V_41 -> type == V_126 ||
V_41 -> type == V_121 ) {
switch ( V_41 -> V_212 & V_217 ) {
case V_16 :
V_301 = L_64 ;
break;
case V_268 :
V_301 = L_65 ;
break;
case V_269 :
V_301 = L_66 ;
break;
case V_270 :
V_301 = L_67 ;
break;
case V_271 :
V_301 = L_68 ;
break;
case V_272 :
V_301 = L_69 ;
break;
case V_218 :
V_301 = L_70 ;
break;
default:
V_301 = L_179 ;
break;
}
} else if ( V_41 -> type == V_116 ) {
F_235 ( V_302 , sizeof( V_302 ) , L_21 , V_41 -> V_212 ) ;
V_301 = V_302 ;
}
}
V_251 = V_41 -> V_251 ;
if ( V_251 == NULL )
V_251 = L_13 ;
else if ( strlen ( V_251 ) == 0 )
V_251 = L_180 ;
if ( V_100 == 1 ) {
printf ( L_181 ,
V_41 -> V_170 , V_41 -> V_171 , V_300 ,
V_62 -> V_171 , V_251 ) ;
}
else if ( V_100 == 2 ) {
printf ( L_182 ,
V_41 -> V_170 , V_41 -> V_171 , V_300 ,
V_62 -> V_171 , V_251 ,
V_301 , V_251 ) ;
}
else if ( V_100 == 3 ) {
printf ( L_183 ,
V_41 -> V_170 , V_41 -> V_171 , V_300 ,
V_62 -> V_171 , V_251 ,
V_301 , V_41 -> V_1 ) ;
}
else {
F_378 () ;
}
}
}
}
void
F_379 ( void )
{
T_43 V_303 ;
for ( V_303 = 0 ; V_303 < V_304 ; V_303 ++ ) {
printf ( L_184 , F_130 ( V_303 ) , F_380 ( V_303 ) ) ;
}
}
static const char *
F_381 ( const V_5 * V_41 )
{
const char * V_100 = NULL ;
if ( V_41 -> type == V_165 ) {
V_100 = L_185 ;
} else {
switch ( V_41 -> V_212 & V_217 ) {
case V_268 :
case V_271 :
case V_270 :
case V_218 :
switch ( V_41 -> type ) {
case V_117 :
case V_118 :
case V_119 :
case V_120 :
V_100 = L_185 ;
break;
case V_122 :
V_100 = L_186 V_224 L_20 ;
break;
case V_123 :
case V_124 :
case V_125 :
case V_126 :
V_100 = L_187 ;
break;
case V_121 :
V_100 = L_186 V_224 L_19 ;
break;
default:
F_95 () ;
;
}
break;
case V_269 :
case V_272 :
switch ( V_41 -> type ) {
case V_117 :
case V_123 :
V_100 = L_188 ;
break;
case V_118 :
case V_124 :
V_100 = L_189 ;
break;
case V_119 :
case V_125 :
V_100 = L_190 ;
break;
case V_120 :
case V_126 :
V_100 = L_191 ;
break;
case V_122 :
case V_121 :
V_100 = L_192 V_224 L_148 ;
break;
default:
F_95 () ;
;
}
break;
default:
F_95 () ;
;
}
}
return V_100 ;
}
static const char *
F_255 ( const V_5 * V_41 )
{
const char * V_100 = NULL ;
if ( V_41 -> type == V_165 ) {
V_100 = L_15 ;
} else {
switch ( V_41 -> V_212 & V_217 ) {
case V_16 :
case V_268 :
case V_271 :
case V_270 :
case V_218 :
switch ( V_41 -> type ) {
case V_117 :
case V_118 :
case V_119 :
case V_120 :
V_100 = L_15 ;
break;
case V_122 :
V_100 = L_18 V_224 L_20 ;
break;
case V_123 :
case V_124 :
case V_125 :
case V_126 :
V_100 = L_21 ;
break;
case V_121 :
V_100 = L_18 V_224 L_19 ;
break;
default:
F_95 () ;
;
}
break;
case V_269 :
case V_272 :
switch ( V_41 -> type ) {
case V_117 :
case V_123 :
V_100 = L_133 ;
break;
case V_118 :
case V_124 :
V_100 = L_134 ;
break;
case V_119 :
case V_125 :
V_100 = L_135 ;
break;
case V_120 :
case V_126 :
V_100 = L_136 ;
break;
case V_122 :
case V_121 :
V_100 = L_193 V_224 L_148 ;
break;
default:
F_95 () ;
;
}
break;
default:
F_95 () ;
;
}
}
return V_100 ;
}
static V_38
F_382 ( T_15 * V_65 , T_44 * V_305 ,
char * * V_306 )
{
V_5 * V_41 ;
int V_307 ;
char * V_254 ;
int V_308 ;
const char * V_100 ;
int V_309 , V_206 ;
T_3 V_101 , V_97 , V_174 ;
T_27 V_72 ;
T_17 V_310 = FALSE ;
V_41 = V_65 -> V_41 ;
F_26 ( V_41 ) ;
V_307 = ( int ) strlen ( V_41 -> V_171 ) ;
if ( V_41 -> V_214 && ( V_41 -> V_212 & V_217 ) == V_16 ) {
const T_17 * V_162 = NULL ;
switch ( V_41 -> type ) {
case V_123 :
case V_124 :
case V_125 :
case V_126 :
if ( V_41 -> V_212 & V_221 ) {
V_162 = F_383 ( F_258 ( & V_65 -> V_55 ) , V_41 -> V_214 ) ;
} else if ( V_41 -> V_212 & V_222 ) {
V_162 = F_373 ( F_258 ( & V_65 -> V_55 ) , V_41 -> V_214 ) ;
} else {
V_162 = F_384 ( F_258 ( & V_65 -> V_55 ) , V_41 -> V_214 ) ;
}
break;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
if ( V_41 -> V_212 & V_221 ) {
V_162 = F_383 ( F_232 ( & V_65 -> V_55 ) , V_41 -> V_214 ) ;
} else if ( V_41 -> V_212 & V_222 ) {
V_162 = F_373 ( F_232 ( & V_65 -> V_55 ) , V_41 -> V_214 ) ;
} else {
V_162 = F_384 ( F_232 ( & V_65 -> V_55 ) , V_41 -> V_214 ) ;
}
break;
default:
break;
}
if ( V_162 != NULL && V_306 != NULL ) {
* V_306 = F_185 ( L_194 , V_41 -> V_171 , V_162 ) ;
return TRUE ;
}
}
switch ( V_41 -> type ) {
case V_123 :
case V_124 :
case V_125 :
case V_126 :
V_310 = TRUE ;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
if ( V_306 != NULL ) {
V_100 = F_381 ( V_41 ) ;
if ( V_310 ) {
* V_306 = F_185 ( V_100 ,
V_41 -> V_171 ,
F_258 ( & V_65 -> V_55 ) ) ;
} else {
* V_306 = F_185 ( V_100 ,
V_41 -> V_171 ,
F_232 ( & V_65 -> V_55 ) ) ;
}
}
break;
case V_165 :
F_26 ( ! V_310 ) ;
if ( V_306 != NULL ) {
V_100 = F_381 ( V_41 ) ;
* V_306 = F_185 ( V_100 ,
V_41 -> V_171 ,
F_232 ( & V_65 -> V_55 ) ) ;
}
break;
case V_121 :
case V_122 :
if ( V_306 != NULL ) {
V_100 = F_381 ( V_41 ) ;
* V_306 = F_185 ( V_100 ,
V_41 -> V_171 ,
F_256 ( & V_65 -> V_55 ) ) ;
}
break;
case V_69 :
if ( V_306 != NULL )
* V_306 = F_48 ( V_65 -> V_41 -> V_171 ) ;
break;
case V_15 :
V_97 = V_65 -> V_97 ;
if ( V_97 == 0 ) {
if ( V_306 != NULL )
* V_306 = F_48 ( V_65 -> V_41 -> V_171 ) ;
break;
}
if ( V_97 < 0 )
return FALSE ;
if ( V_305 == NULL )
return FALSE ;
if ( V_65 -> V_179 != V_305 -> V_91 )
return FALSE ;
V_174 = F_222 ( V_65 -> V_179 , V_65 -> V_101 ) ;
if ( V_97 > V_174 )
V_97 = V_174 ;
if ( V_97 <= 0 )
return FALSE ;
if ( V_306 != NULL ) {
V_101 = V_65 -> V_101 ;
V_308 = 32 + V_97 * 3 ;
* V_306 = F_385 ( V_308 ) ;
V_254 = * V_306 ;
V_254 += F_235 ( V_254 , ( V_230 ) ( V_308 - ( V_254 - * V_306 ) ) ,
L_195 , V_65 -> V_101 , V_97 ) ;
for ( V_206 = 0 ; V_206 < V_97 ; V_206 ++ ) {
V_72 = F_88 ( V_65 -> V_179 , V_101 ) ;
V_101 ++ ;
if ( V_206 == 0 ) {
V_254 += F_235 ( V_254 , ( V_230 ) ( V_308 - ( V_254 - * V_306 ) ) , L_196 , V_72 ) ;
}
else {
V_254 += F_235 ( V_254 , ( V_230 ) ( V_308 - ( V_254 - * V_306 ) ) , L_197 , V_72 ) ;
}
}
}
break;
case V_228 :
F_95 () ;
break;
default:
if ( V_306 != NULL ) {
V_309 = F_386 ( & V_65 -> V_55 ,
V_311 ) ;
V_309 += V_307 + 4 + 1 ;
* V_306 = F_385 ( V_309 ) ;
F_235 ( * V_306 , V_309 , L_198 ,
V_41 -> V_171 ) ;
F_387 ( & V_65 -> V_55 ,
V_311 ,
& ( * V_306 ) [ V_307 + 4 ] ) ;
}
break;
}
return TRUE ;
}
V_38
F_388 ( T_15 * V_65 , T_44 * V_305 )
{
return F_382 ( V_65 , V_305 , NULL ) ;
}
char *
F_389 ( T_15 * V_65 , T_44 * V_305 )
{
char * V_306 ;
if ( ! F_382 ( V_65 , V_305 , & V_306 ) )
return NULL ;
return V_306 ;
}
static V_38
F_390 ( T_23 * V_156 , T_22 * V_91 , const int V_92 ,
const int V_27 , const T_3 V_312 , const int * * V_44 ,
const T_16 V_99 , const int V_176 ,
V_38 V_313 )
{
T_1 V_55 = 0 ;
T_1 V_314 ;
T_8 * V_45 = NULL ;
V_5 * V_13 ;
const char * V_315 ;
switch ( V_27 ) {
case 1 :
V_55 = F_88 ( V_91 , V_92 ) ;
break;
case 2 :
V_55 = V_99 ? F_89 ( V_91 , V_92 ) :
F_90 ( V_91 , V_92 ) ;
break;
case 3 :
V_55 = V_99 ? F_91 ( V_91 , V_92 ) :
F_92 ( V_91 , V_92 ) ;
break;
case 4 :
V_55 = V_99 ? F_93 ( V_91 , V_92 ) :
F_94 ( V_91 , V_92 ) ;
break;
default:
F_378 () ;
}
V_45 = F_74 ( V_156 , V_312 ) ;
while ( * V_44 ) {
F_137 ( V_45 , * * V_44 , V_91 , V_92 , V_27 , V_99 ) ;
if ( V_176 & V_316 ) {
V_44 ++ ;
continue;
}
V_13 = F_46 ( * * V_44 ) ;
F_26 ( V_13 -> V_1 != 0 ) ;
V_314 = ( V_55 & V_13 -> V_1 ) >> V_13 -> V_2 ;
switch ( V_13 -> type ) {
case V_123 :
case V_117 :
case V_124 :
case V_118 :
case V_125 :
case V_119 :
case V_126 :
case V_120 :
F_26 ( V_27 == F_359 ( V_13 -> type ) ) ;
if ( V_13 -> V_212 == V_218 ) {
T_17 V_317 [ V_186 ] ;
T_36 V_220 = ( T_36 ) V_13 -> V_214 ;
F_26 ( V_220 ) ;
V_220 ( V_317 , V_314 ) ;
F_273 ( V_156 , L_199 , V_313 ? L_13 : L_200 ,
V_13 -> V_170 , V_317 ) ;
V_313 = FALSE ;
}
else if ( V_13 -> V_214 ) {
if ( V_13 -> V_212 & V_221 ) {
F_273 ( V_156 , L_199 , V_313 ? L_13 : L_200 ,
V_13 -> V_170 , F_249 ( V_314 , V_13 -> V_214 , L_107 ) ) ;
} else if ( V_13 -> V_212 & V_222 ) {
F_273 ( V_156 , L_199 , V_313 ? L_13 : L_200 ,
V_13 -> V_170 , F_345 ( V_314 , ( V_223 * ) ( V_13 -> V_214 ) , L_107 ) ) ;
} else {
F_273 ( V_156 , L_199 , V_313 ? L_13 : L_200 ,
V_13 -> V_170 , F_346 ( V_314 , F_252 ( V_13 -> V_214 ) , L_107 ) ) ;
}
V_313 = FALSE ;
}
else if ( ! ( V_176 & V_318 ) ) {
if ( ! V_313 ) {
F_273 ( V_156 , L_200 ) ;
}
V_315 = F_391 ( V_13 -> type ) ? F_350 ( V_13 ) : F_347 ( V_13 ) ;
if ( F_253 ( V_13 -> V_212 ) ) {
F_273 ( V_156 , V_315 , V_13 -> V_170 , V_314 , V_314 ) ;
} else {
F_273 ( V_156 , V_315 , V_13 -> V_170 , V_314 ) ;
}
V_313 = FALSE ;
}
break;
case V_116 :
F_26 ( V_27 * 8 == V_13 -> V_212 ) ;
if ( V_13 -> V_214 && ! ( V_176 & V_319 ) ) {
const struct T_35 * V_295 =
( const struct T_35 * ) V_13 -> V_214 ;
if ( V_314 ) {
F_273 ( V_156 , L_199 , V_313 ? L_13 : L_200 ,
V_13 -> V_170 , V_295 -> V_215 ) ;
V_313 = FALSE ;
} else if ( ! ( V_176 & V_320 ) ) {
F_273 ( V_156 , L_199 , V_313 ? L_13 : L_200 ,
V_13 -> V_170 , V_295 -> V_216 ) ;
V_313 = FALSE ;
}
} else if ( V_13 -> V_1 & V_55 ) {
F_273 ( V_156 , L_7 , V_313 ? L_13 : L_200 , V_13 -> V_170 ) ;
V_313 = FALSE ;
}
break;
default:
F_378 () ;
}
V_44 ++ ;
}
return V_313 ;
}
T_23 *
F_392 ( T_8 * V_321 , T_22 * V_91 ,
const T_16 V_92 , const int V_322 ,
const T_3 V_312 , const int * * V_44 ,
const T_16 V_99 )
{
T_23 * V_156 = NULL ;
V_5 * V_13 ;
int V_27 ;
V_13 = F_46 ( V_322 ) ;
F_26 ( F_391 ( V_13 -> type ) || F_231 ( V_13 -> type ) ) ;
V_27 = F_359 ( V_13 -> type ) ;
if ( V_321 ) {
V_156 = F_137 ( V_321 , V_322 , V_91 , V_92 , V_27 , V_99 ) ;
F_390 ( V_156 , V_91 , V_92 , V_27 , V_312 , V_44 , V_99 ,
V_318 | V_319 , FALSE ) ;
}
return V_156 ;
}
T_23 *
F_393 ( T_8 * V_321 , T_22 * V_91 ,
const T_16 V_92 , const T_16 V_27 ,
const char * V_170 , const char * V_323 ,
const T_3 V_312 , const int * * V_44 ,
const T_16 V_99 , const int V_176 )
{
T_23 * V_156 = NULL ;
if ( V_321 ) {
V_156 = F_83 ( V_321 , V_91 , V_92 , V_27 , L_16 , V_170 ? V_170 : L_13 ) ;
if ( F_390 ( V_156 , V_91 , V_92 , V_27 , V_312 , V_44 , V_99 ,
V_176 , TRUE ) && V_323 ) {
F_273 ( V_156 , L_16 , V_323 ) ;
}
}
return V_156 ;
}
T_23 *
F_394 ( T_8 * V_45 , const int V_324 , T_22 * V_91 ,
const T_16 V_325 , const T_3 V_326 ,
const T_16 V_99 )
{
V_5 * V_41 ;
F_79 ( V_45 , V_324 , V_41 ) ;
return F_395 ( V_45 , V_324 , V_91 , V_325 , V_326 , NULL , V_99 ) ;
}
static T_23 *
F_396 ( T_8 * V_45 , const int V_324 , T_22 * V_91 ,
const T_16 V_325 , const T_3 V_326 ,
T_30 * V_327 , const T_16 V_99 )
{
T_3 V_92 ;
T_16 V_97 ;
T_27 V_328 ;
char * V_329 ;
char V_330 [ V_186 ] ;
T_30 V_55 = 0 ;
T_23 * V_80 ;
V_5 * V_331 ;
const T_35 * V_203 ;
F_25 ( V_324 , V_331 ) ;
if ( V_331 -> V_1 != 0 ) {
F_220 ( F_185 ( L_201
L_202 ,
V_331 -> V_171 , V_331 -> V_170 ) ) ;
}
F_26 ( V_326 > 0 ) ;
V_92 = V_325 >> 3 ;
V_328 = ( ( V_325 & 0x7 ) + V_326 ) ;
V_97 = V_328 >> 3 ;
if ( V_328 & 0x07 )
V_97 ++ ;
if ( V_326 < 65 ) {
V_55 = F_397 ( V_91 , V_325 , V_326 , V_99 ) ;
} else {
F_95 () ;
return NULL ;
}
switch ( V_331 -> type ) {
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_121 :
if ( V_55 & ( F_398 ( 1 ) << ( V_326 - 1 ) ) )
V_55 |= ( F_398 ( - 1 ) << V_326 ) ;
break;
default:
break;
}
if ( V_327 ) {
* V_327 = V_55 ;
}
F_79 ( V_45 , V_324 , V_331 ) ;
V_329 = F_399 ( V_325 , V_326 , V_55 ) ;
switch ( V_331 -> type ) {
case V_116 :
V_203 = ( const T_35 * ) & V_213 ;
if ( V_331 -> V_214 )
V_203 = ( const T_35 * ) V_331 -> V_214 ;
return F_193 ( V_45 , V_324 , V_91 , V_92 , V_97 , ( T_1 ) V_55 ,
L_203 ,
V_329 , V_331 -> V_170 ,
( T_1 ) V_55 ? V_203 -> V_215 : V_203 -> V_216 ) ;
break;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
V_80 = F_201 ( V_45 , V_324 , V_91 , V_92 , V_97 , ( T_1 ) V_55 ) ;
F_333 ( F_182 ( V_80 ) , V_330 ) ;
break;
case V_123 :
case V_124 :
case V_125 :
case V_126 :
V_80 = F_207 ( V_45 , V_324 , V_91 , V_92 , V_97 , ( T_25 ) V_55 ) ;
F_335 ( F_182 ( V_80 ) , V_330 ) ;
break;
case V_122 :
V_80 = F_204 ( V_45 , V_324 , V_91 , V_92 , V_97 , V_55 ) ;
F_334 ( F_182 ( V_80 ) , V_330 ) ;
break;
case V_121 :
V_80 = F_211 ( V_45 , V_324 , V_91 , V_92 , V_97 , ( T_31 ) V_55 ) ;
F_336 ( F_182 ( V_80 ) , V_330 ) ;
break;
default:
F_95 () ;
return NULL ;
break;
}
F_271 ( V_80 , L_204 , V_329 , V_330 ) ;
return V_80 ;
}
T_23 *
F_400 ( T_8 * V_45 , const int V_324 , T_22 * V_91 ,
const T_16 V_325 , const T_45 * V_332 ,
T_30 * V_327 )
{
T_23 * V_80 ;
T_3 V_326 ;
T_3 V_333 ;
T_16 V_334 ;
T_16 V_335 ;
T_16 V_336 ;
T_27 V_206 ;
char * V_329 ;
char V_330 [ V_186 ] ;
T_30 V_55 ;
T_30 V_337 ;
T_30 V_338 ;
V_5 * V_331 ;
const T_35 * V_203 ;
F_25 ( V_324 , V_331 ) ;
if ( V_331 -> V_1 != 0 ) {
F_220 ( F_185 (
L_205
L_202 ,
V_331 -> V_171 , V_331 -> V_170 ) ) ;
}
V_334 = V_325 % 8 ;
V_326 = 0 ;
V_55 = 0 ;
V_206 = 0 ;
V_335 = 0 ;
V_337 = 0 ;
V_338 = 0 ;
while ( V_332 [ V_206 ] . V_339 != 0 ) {
T_30 V_340 , V_341 ;
T_27 V_342 ;
F_26 ( V_206 < 64 ) ;
V_341 = F_397 ( V_91 ,
V_325 + V_332 [ V_206 ] . V_343 ,
V_332 [ V_206 ] . V_339 ,
V_148 ) ;
V_55 += V_341 ;
V_326 += V_332 [ V_206 ] . V_339 ;
if ( V_335 < 32 ) {
V_342 = V_334
+ V_332 [ V_206 ] . V_343
+ V_332 [ V_206 ] . V_339 ;
V_340 = ( F_401 ( 1 ) << V_332 [ V_206 ] . V_339 ) - 1 ;
if ( V_342 > V_335 ) {
V_335 = V_342 ;
}
V_337 |= ( V_340 << ( 64 - V_342 ) ) ;
V_338 |= ( V_341 << ( 64 - V_342 ) ) ;
}
V_55 <<= V_332 [ ++ V_206 ] . V_339 ;
}
switch ( V_331 -> type ) {
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_121 :
if ( V_55 & V_326 && ( F_398 ( 1 ) << ( V_326 - 1 ) ) )
V_55 |= ( F_398 ( - 1 ) << V_326 ) ;
break;
default:
break;
}
if ( V_327 ) {
* V_327 = V_55 ;
}
F_79 ( V_45 , V_324 , V_331 ) ;
V_329 = F_61 ( 256 ) ;
V_329 [ 0 ] = '\0' ;
V_333 = V_325 >> 3 ;
V_336 = ( ( V_335 + 7 ) >> 3 ) ;
V_335 = V_336 << 3 ;
if ( V_335 <= 32 ) {
F_402 ( V_329 ,
( T_1 ) ( V_338 >> ( 64 - V_335 ) ) ,
( T_1 ) ( V_337 >> ( 64 - V_335 ) ) ,
V_335 ) ;
}
switch ( V_331 -> type ) {
case V_116 :
V_203 = ( const T_35 * ) & V_213 ;
if ( V_331 -> V_214 )
V_203 = ( const T_35 * ) V_331 -> V_214 ;
return F_193 ( V_45 , V_324 ,
V_91 , V_333 , V_336 , ( T_1 ) V_55 ,
L_203 ,
V_329 , V_331 -> V_170 ,
( T_1 ) V_55 ? V_203 -> V_215 : V_203 -> V_216 ) ;
break;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
V_80 = F_201 ( V_45 , V_324 , V_91 , V_333 , V_336 , ( T_1 ) V_55 ) ;
F_333 ( F_182 ( V_80 ) , V_330 ) ;
break;
case V_123 :
case V_124 :
case V_125 :
case V_126 :
V_80 = F_207 ( V_45 , V_324 , V_91 , V_333 , V_336 , ( T_25 ) V_55 ) ;
F_335 ( F_182 ( V_80 ) , V_330 ) ;
break;
case V_122 :
V_80 = F_204 ( V_45 , V_324 , V_91 , V_333 , V_336 , V_55 ) ;
F_334 ( F_182 ( V_80 ) , V_330 ) ;
break;
case V_121 :
V_80 = F_211 ( V_45 , V_324 , V_91 , V_333 , V_336 , ( T_31 ) V_55 ) ;
F_336 ( F_182 ( V_80 ) , V_330 ) ;
break;
default:
F_95 () ;
return NULL ;
break;
}
F_271 ( V_80 , L_204 , V_329 , V_330 ) ;
return V_80 ;
}
void
F_403 ( T_8 * V_45 , const int V_324 , T_22 * V_91 , const T_16 V_325 ,
const T_45 * V_332 , T_46 V_344 )
{
V_5 * V_345 ;
F_25 ( V_324 , V_345 ) ;
F_83 ( V_45 , V_91 ,
V_325 >> 3 ,
( ( V_325 + V_332 [ V_344 ] . V_339 - 1 ) >> 3 ) - ( V_325 >> 3 ) + 1 ,
L_206 ,
F_399 ( V_325 , V_332 [ V_344 ] . V_339 ,
F_404 ( V_91 ,
V_325 ,
V_332 [ V_344 ] . V_339 ,
V_148 ) ) ,
V_344 ,
V_345 -> V_170 ) ;
}
T_23 *
F_395 ( T_8 * V_45 , const int V_324 , T_22 * V_91 ,
const T_16 V_325 , const T_3 V_326 ,
T_30 * V_327 , const T_16 V_99 )
{
T_23 * V_156 ;
if ( ( V_156 = F_396 ( V_45 , V_324 , V_91 ,
V_325 , V_326 ,
V_327 , V_99 ) ) ) {
F_131 ( F_39 ( V_156 ) , F_405 ( V_325 ) ) ;
F_131 ( F_39 ( V_156 ) , F_406 ( V_326 ) ) ;
}
return V_156 ;
}
static T_23 *
F_407 ( T_8 * V_45 , const int V_324 ,
T_22 * V_91 , const T_16 V_325 ,
const T_3 V_326 , void * V_160 ,
T_17 * V_346 )
{
T_3 V_92 ;
T_16 V_97 ;
T_27 V_328 ;
char * V_162 ;
T_30 V_55 = 0 ;
V_5 * V_331 ;
F_79 ( V_45 , V_324 , V_331 ) ;
if ( V_331 -> V_1 != 0 ) {
F_220 ( F_185 (
L_207
L_202 ,
V_331 -> V_171 , V_331 -> V_170 ) ) ;
}
F_26 ( V_326 > 0 ) ;
V_92 = V_325 >> 3 ;
V_328 = ( ( V_325 & 0x7 ) + V_326 ) ;
V_97 = V_328 >> 3 ;
if ( V_328 & 0x07 )
V_97 ++ ;
if ( V_326 < 65 ) {
V_55 = F_397 ( V_91 , V_325 , V_326 , V_148 ) ;
} else {
F_95 () ;
return NULL ;
}
V_162 = F_399 ( V_325 , V_326 , V_55 ) ;
strcat ( V_162 , L_208 ) ;
strcat ( V_162 , V_331 -> V_170 ) ;
switch ( V_331 -> type ) {
case V_116 :
return F_193 ( V_45 , V_324 , V_91 , V_92 , V_97 , * ( T_1 * ) V_160 ,
L_100 , V_162 , V_346 ) ;
break;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
return F_203 ( V_45 , V_324 , V_91 , V_92 , V_97 , * ( T_1 * ) V_160 ,
L_100 , V_162 , V_346 ) ;
break;
case V_122 :
return F_206 ( V_45 , V_324 , V_91 , V_92 , V_97 , * ( T_30 * ) V_160 ,
L_100 , V_162 , V_346 ) ;
break;
case V_123 :
case V_124 :
case V_125 :
case V_126 :
return F_209 ( V_45 , V_324 , V_91 , V_92 , V_97 , * ( T_25 * ) V_160 ,
L_100 , V_162 , V_346 ) ;
break;
case V_121 :
return F_213 ( V_45 , V_324 , V_91 , V_92 , V_97 , * ( T_31 * ) V_160 ,
L_100 , V_162 , V_346 ) ;
break;
case V_140 :
return F_196 ( V_45 , V_324 , V_91 , V_92 , V_97 , * ( float * ) V_160 ,
L_100 , V_162 , V_346 ) ;
break;
default:
F_95 () ;
return NULL ;
break;
}
}
T_23 *
F_408 ( T_8 * V_45 , const int V_324 ,
T_22 * V_91 , const T_16 V_325 ,
const T_3 V_326 , void * V_160 ,
T_17 * V_346 )
{
T_23 * V_156 ;
if ( ( V_156 = F_407 ( V_45 , V_324 ,
V_91 , V_325 , V_326 ,
V_160 , V_346 ) ) ) {
F_131 ( F_39 ( V_156 ) , F_405 ( V_325 ) ) ;
F_131 ( F_39 ( V_156 ) , F_406 ( V_326 ) ) ;
}
return V_156 ;
}
T_23 *
F_409 ( T_8 * V_45 , const int V_324 ,
T_22 * V_91 , const T_16 V_325 ,
const T_3 V_326 , T_1 V_55 ,
const char * V_100 , ... )
{
T_24 V_73 ;
T_17 * V_347 ;
V_5 * V_331 ;
F_79 ( V_45 , V_324 , V_331 ) ;
switch ( V_331 -> type ) {
case V_117 :
case V_118 :
case V_119 :
case V_120 :
break;
default:
F_95 () ;
return NULL ;
break;
}
F_410 ( V_347 , V_100 , V_73 ) ;
return F_408 ( V_45 , V_324 , V_91 , V_325 , V_326 , & V_55 , V_347 ) ;
}
T_23 *
F_411 ( T_8 * V_45 , const int V_324 ,
T_22 * V_91 , const T_16 V_325 ,
const T_3 V_326 , float V_55 ,
const char * V_100 , ... )
{
T_24 V_73 ;
T_17 * V_347 ;
V_5 * V_331 ;
F_79 ( V_45 , V_324 , V_331 ) ;
F_26 ( V_331 -> type == V_140 ) ;
F_410 ( V_347 , V_100 , V_73 ) ;
return F_408 ( V_45 , V_324 , V_91 , V_325 , V_326 , & V_55 , V_347 ) ;
}
T_23 *
F_412 ( T_8 * V_45 , const int V_324 ,
T_22 * V_91 , const T_16 V_325 ,
const T_3 V_326 , T_25 V_55 ,
const char * V_100 , ... )
{
T_24 V_73 ;
T_17 * V_347 ;
V_5 * V_331 ;
F_79 ( V_45 , V_324 , V_331 ) ;
switch ( V_331 -> type ) {
case V_123 :
case V_124 :
case V_125 :
case V_126 :
break;
default:
F_95 () ;
return NULL ;
break;
}
F_410 ( V_347 , V_100 , V_73 ) ;
return F_408 ( V_45 , V_324 , V_91 , V_325 , V_326 , & V_55 , V_347 ) ;
}
T_23 *
F_413 ( T_8 * V_45 , const int V_324 ,
T_22 * V_91 , const T_16 V_325 ,
const T_3 V_326 , T_1 V_55 ,
const char * V_100 , ... )
{
T_24 V_73 ;
T_17 * V_347 ;
V_5 * V_331 ;
F_79 ( V_45 , V_324 , V_331 ) ;
F_26 ( V_331 -> type == V_116 ) ;
F_410 ( V_347 , V_100 , V_73 ) ;
return F_408 ( V_45 , V_324 , V_91 , V_325 , V_326 , & V_55 , V_347 ) ;
}
T_38
F_414 ( const T_17 * V_84 )
{
return F_328 ( V_278 , V_84 ) ;
}
