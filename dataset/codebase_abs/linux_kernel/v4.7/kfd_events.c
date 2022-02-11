static T_1 * F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 ;
}
static bool F_2 ( struct V_4 * V_5 ,
struct V_1 * * V_6 ,
unsigned int * V_7 )
{
struct V_1 * V_2 ;
F_3 (page, &process->signal_event_pages, event_pages) {
if ( V_2 -> V_8 > 0 ) {
unsigned int V_9 =
F_4 ( V_2 -> V_10 ,
V_11 ) ;
F_5 ( V_9 , V_2 -> V_10 ) ;
V_2 -> V_8 -- ;
F_1 ( V_2 ) [ V_9 ] = V_12 ;
* V_6 = V_2 ;
* V_7 = V_9 ;
F_6 ( L_1 ,
V_2 , V_9 ) ;
return true ;
}
}
F_6 ( L_2 ,
V_5 ) ;
return false ;
}
static bool F_7 ( struct V_13 * V_14 , struct V_4 * V_15 )
{
void * V_16 ;
struct V_1 * V_2 ;
V_2 = F_8 ( V_17 , V_18 ) ;
if ( ! V_2 )
goto V_19;
V_2 -> V_8 = V_11 ;
V_16 = ( void * ) F_9 ( V_18 | V_20 ,
F_10 ( V_21 * 8 ) ) ;
if ( ! V_16 )
goto V_22;
memset ( V_16 , ( V_23 ) V_12 ,
V_21 * 8 ) ;
V_2 -> V_3 = V_16 ;
if ( F_11 ( & V_15 -> V_24 ) )
V_2 -> V_25 = 0 ;
else
V_2 -> V_25 = F_12 ( & V_15 -> V_24 ,
struct V_1 ,
V_26 ) -> V_25 + 1 ;
F_6 ( L_3 ,
V_2 , V_15 ) ;
F_6 ( L_4 , V_2 -> V_25 ) ;
F_13 ( & V_2 -> V_26 , & V_15 -> V_24 ) ;
return true ;
V_22:
F_14 ( V_2 ) ;
V_19:
return false ;
}
static bool F_15 ( struct V_13 * V_14 ,
struct V_4 * V_15 ,
struct V_1 * * V_2 ,
unsigned int * V_27 )
{
bool V_28 ;
V_28 = F_2 ( V_15 , V_2 , V_27 ) ;
if ( ! V_28 ) {
V_28 = F_7 ( V_14 , V_15 ) ;
if ( V_28 )
V_28 = F_2 ( V_15 , V_2 , V_27 ) ;
}
return V_28 ;
}
static void F_16 ( struct V_1 * V_2 ,
T_2 V_29 )
{
F_17 ( V_29 , V_2 -> V_10 ) ;
V_2 -> V_8 ++ ;
}
static struct V_1 * F_18 ( struct V_4 * V_15 ,
unsigned int V_25 )
{
struct V_1 * V_2 ;
F_3 (page, &p->signal_event_pages, event_pages)
if ( V_2 -> V_25 == V_25 )
return V_2 ;
return NULL ;
}
static struct V_30 * F_19 ( struct V_4 * V_15 , T_3 V_31 )
{
struct V_30 * V_32 ;
F_20 (p->events, ev, events, id)
if ( V_32 -> V_33 == V_31 )
return V_32 ;
return NULL ;
}
static T_4 F_21 ( struct V_1 * V_2 ,
unsigned int V_27 )
{
return V_2 -> V_25 |
( V_27 << V_34 ) ;
}
static T_4 F_22 ( struct V_4 * V_15 )
{
T_4 V_31 ;
for ( V_31 = V_15 -> V_35 ;
V_31 < V_36 &&
F_19 ( V_15 , V_31 ) != NULL ;
V_31 ++ )
;
if ( V_31 < V_36 ) {
V_15 -> V_35 = V_31 + 1 ;
return V_31 ;
}
for ( V_31 = V_37 ;
V_31 < V_36 &&
F_19 ( V_15 , V_31 ) != NULL ;
V_31 ++ )
;
if ( V_31 < V_36 ) {
V_15 -> V_35 = V_31 + 1 ;
return V_31 ;
}
V_15 -> V_35 = V_37 ;
return 0 ;
}
static struct V_30 * F_23 ( struct V_4 * V_15 ,
struct V_1 * V_2 ,
unsigned int V_38 )
{
return F_19 ( V_15 , F_21 ( V_2 , V_38 ) ) ;
}
static int F_24 ( struct V_13 * V_14 ,
struct V_4 * V_15 ,
struct V_30 * V_32 )
{
if ( V_15 -> V_39 == V_21 ) {
F_25 ( L_5 ) ;
return - V_40 ;
}
if ( ! F_15 ( V_14 , V_15 , & V_32 -> V_1 ,
& V_32 -> V_27 ) ) {
F_25 ( L_6 ) ;
return - V_40 ;
}
V_15 -> V_39 ++ ;
V_32 -> V_41 =
& V_32 -> V_1 -> V_42 [ V_32 -> V_27 ] ;
V_32 -> V_33 = F_21 ( V_32 -> V_1 ,
V_32 -> V_27 ) ;
F_6 ( L_7 ,
V_15 -> V_39 , V_32 -> V_33 ,
V_32 -> V_41 ) ;
F_6 ( L_7 ,
V_15 -> V_39 , V_32 -> V_33 ,
V_32 -> V_41 ) ;
return 0 ;
}
static int F_26 ( struct V_4 * V_15 , struct V_30 * V_32 )
{
V_32 -> V_33 = F_22 ( V_15 ) ;
if ( V_32 -> V_33 == 0 )
return - V_40 ;
return 0 ;
}
void F_27 ( struct V_4 * V_15 )
{
F_28 ( & V_15 -> V_43 ) ;
F_29 ( V_15 -> V_44 ) ;
F_30 ( & V_15 -> V_24 ) ;
V_15 -> V_35 = V_37 ;
V_15 -> V_39 = 0 ;
}
static void F_31 ( struct V_4 * V_15 , struct V_30 * V_32 )
{
if ( V_32 -> V_1 != NULL ) {
F_16 ( V_32 -> V_1 ,
V_32 -> V_27 ) ;
V_15 -> V_39 -- ;
}
F_32 ( & V_32 -> V_45 ) ;
F_33 ( & V_32 -> V_44 ) ;
F_14 ( V_32 ) ;
}
static void F_34 ( struct V_4 * V_15 )
{
struct V_30 * V_32 ;
struct V_46 * V_47 ;
unsigned int V_48 ;
F_35 (p->events, hash_bkt, tmp, ev, events)
F_31 ( V_15 , V_32 ) ;
}
static void F_36 ( struct V_4 * V_15 )
{
struct V_1 * V_2 , * V_47 ;
F_37 (page, tmp, &p->signal_event_pages,
event_pages) {
F_38 ( ( unsigned long ) V_2 -> V_3 ,
F_10 ( V_21 * 8 ) ) ;
F_14 ( V_2 ) ;
}
}
void F_39 ( struct V_4 * V_15 )
{
F_34 ( V_15 ) ;
F_36 ( V_15 ) ;
}
static bool F_40 ( const struct V_30 * V_32 )
{
return V_32 -> type == V_49 ||
V_32 -> type == V_50 ;
}
static bool F_41 ( const struct V_30 * V_32 )
{
return V_32 -> type == V_49 ;
}
int F_42 ( struct V_13 * V_14 , struct V_4 * V_15 ,
T_3 V_51 , bool V_52 , T_3 V_53 ,
T_3 * V_33 , T_3 * V_54 ,
T_1 * V_55 , T_3 * V_56 )
{
int V_28 = 0 ;
struct V_30 * V_32 = F_8 ( sizeof( * V_32 ) , V_18 ) ;
if ( ! V_32 )
return - V_40 ;
V_32 -> type = V_51 ;
V_32 -> V_52 = V_52 ;
V_32 -> V_57 = false ;
F_30 ( & V_32 -> V_45 ) ;
* V_55 = 0 ;
F_43 ( & V_15 -> V_43 ) ;
switch ( V_51 ) {
case V_49 :
case V_50 :
V_28 = F_24 ( V_14 , V_15 , V_32 ) ;
if ( ! V_28 ) {
* V_55 = ( V_32 -> V_1 -> V_25 |
V_58 ) ;
* V_55 <<= V_59 ;
* V_56 = V_32 -> V_27 ;
}
break;
default:
V_28 = F_26 ( V_15 , V_32 ) ;
break;
}
if ( ! V_28 ) {
F_44 ( V_15 -> V_44 , & V_32 -> V_44 , V_32 -> V_33 ) ;
* V_33 = V_32 -> V_33 ;
* V_54 = V_32 -> V_33 ;
} else {
F_14 ( V_32 ) ;
}
F_45 ( & V_15 -> V_43 ) ;
return V_28 ;
}
int F_46 ( struct V_4 * V_15 , T_3 V_33 )
{
struct V_30 * V_32 ;
int V_28 = 0 ;
F_43 ( & V_15 -> V_43 ) ;
V_32 = F_19 ( V_15 , V_33 ) ;
if ( V_32 )
F_31 ( V_15 , V_32 ) ;
else
V_28 = - V_60 ;
F_45 ( & V_15 -> V_43 ) ;
return V_28 ;
}
static void F_47 ( struct V_30 * V_32 )
{
struct V_61 * V_62 ;
struct V_61 * V_63 ;
V_32 -> V_57 = ! V_32 -> V_52 || F_11 ( & V_32 -> V_45 ) ;
F_37 (waiter, next, &ev->waiters, waiters) {
V_62 -> V_64 = true ;
F_48 ( & V_62 -> V_45 ) ;
F_49 ( V_62 -> V_65 ) ;
}
}
int F_50 ( struct V_4 * V_15 , T_3 V_33 )
{
int V_28 = 0 ;
struct V_30 * V_32 ;
F_43 ( & V_15 -> V_43 ) ;
V_32 = F_19 ( V_15 , V_33 ) ;
if ( V_32 && F_41 ( V_32 ) )
F_47 ( V_32 ) ;
else
V_28 = - V_60 ;
F_45 ( & V_15 -> V_43 ) ;
return V_28 ;
}
static void F_51 ( struct V_30 * V_32 )
{
V_32 -> V_57 = false ;
}
int F_52 ( struct V_4 * V_15 , T_3 V_33 )
{
int V_28 = 0 ;
struct V_30 * V_32 ;
F_43 ( & V_15 -> V_43 ) ;
V_32 = F_19 ( V_15 , V_33 ) ;
if ( V_32 && F_41 ( V_32 ) )
F_51 ( V_32 ) ;
else
V_28 = - V_60 ;
F_45 ( & V_15 -> V_43 ) ;
return V_28 ;
}
static void F_53 ( struct V_4 * V_15 , struct V_30 * V_32 )
{
F_1 ( V_32 -> V_1 ) [ V_32 -> V_27 ] =
V_12 ;
}
static bool F_54 ( struct V_1 * V_2 , unsigned int V_66 )
{
return F_1 ( V_2 ) [ V_66 ] != V_12 ;
}
static void F_55 ( struct V_4 * V_15 ,
struct V_30 * V_32 )
{
if ( V_32 && F_40 ( V_32 ) ) {
F_53 ( V_15 , V_32 ) ;
F_47 ( V_32 ) ;
}
}
void F_56 ( unsigned int V_67 , T_3 V_68 ,
T_3 V_69 )
{
struct V_30 * V_32 ;
struct V_4 * V_15 = F_57 ( V_67 ) ;
if ( ! V_15 )
return;
F_43 ( & V_15 -> V_43 ) ;
if ( V_69 >= V_70 ) {
V_32 = F_19 ( V_15 , V_68 ) ;
F_55 ( V_15 , V_32 ) ;
} else {
struct V_1 * V_2 ;
unsigned V_71 ;
F_3 (page, &p->signal_event_pages, event_pages)
for ( V_71 = 0 ; V_71 < V_11 ; V_71 ++ )
if ( F_54 ( V_2 , V_71 ) ) {
V_32 = F_23 ( V_15 ,
V_2 , V_71 ) ;
F_55 ( V_15 , V_32 ) ;
}
}
F_45 ( & V_15 -> V_43 ) ;
F_45 ( & V_15 -> V_72 ) ;
}
static struct V_61 * F_58 ( T_3 V_73 )
{
struct V_61 * V_74 ;
T_3 V_71 ;
V_74 = F_59 ( V_73 ,
sizeof( struct V_61 ) ,
V_18 ) ;
for ( V_71 = 0 ; ( V_74 ) && ( V_71 < V_73 ) ; V_71 ++ ) {
F_30 ( & V_74 [ V_71 ] . V_45 ) ;
V_74 [ V_71 ] . V_65 = V_75 ;
V_74 [ V_71 ] . V_64 = false ;
}
return V_74 ;
}
static int F_60 ( struct V_4 * V_15 ,
struct V_61 * V_62 ,
T_3 V_33 ,
T_3 V_76 )
{
struct V_30 * V_32 = F_19 ( V_15 , V_33 ) ;
if ( ! V_32 )
return - V_60 ;
V_62 -> V_77 = V_32 ;
V_62 -> V_76 = V_76 ;
V_62 -> V_64 = V_32 -> V_57 ;
V_32 -> V_57 = V_32 -> V_57 && ! V_32 -> V_52 ;
F_13 ( & V_62 -> V_45 , & V_32 -> V_45 ) ;
return 0 ;
}
static bool F_61 ( bool V_78 , T_3 V_73 ,
struct V_61 * V_74 )
{
T_3 V_71 ;
T_3 V_79 = 0 ;
for ( V_71 = 0 ; V_71 < V_73 ; V_71 ++ ) {
if ( V_74 [ V_71 ] . V_64 ) {
if ( ! V_78 )
return true ;
V_79 ++ ;
}
}
return V_79 == V_73 ;
}
static bool F_62 ( T_3 V_73 ,
struct V_61 * V_74 ,
struct V_80 T_5 * V_81 )
{
struct V_82 * V_83 ;
struct V_82 T_5 * V_84 ;
struct V_61 * V_62 ;
struct V_30 * V_77 ;
T_3 V_71 ;
for ( V_71 = 0 ; V_71 < V_73 ; V_71 ++ ) {
V_62 = & V_74 [ V_71 ] ;
V_77 = V_62 -> V_77 ;
if ( V_62 -> V_64 && V_77 -> type == V_85 ) {
V_84 = & V_81 [ V_62 -> V_76 ] . V_86 ;
V_83 = & V_77 -> V_86 ;
if ( F_63 ( V_84 , V_83 ,
sizeof( struct V_82 ) ) )
return false ;
}
}
return true ;
}
static long F_64 ( T_3 V_87 )
{
if ( V_87 == V_88 )
return 0 ;
if ( V_87 == V_89 )
return V_90 ;
V_87 = F_65 ( T_3 , V_87 , 0x7FFFFFFF ) ;
return F_66 ( V_87 ) + 1 ;
}
static void F_67 ( T_3 V_73 , struct V_61 * V_45 )
{
T_3 V_71 ;
for ( V_71 = 0 ; V_71 < V_73 ; V_71 ++ )
F_32 ( & V_45 [ V_71 ] . V_45 ) ;
F_14 ( V_45 ) ;
}
int F_68 ( struct V_4 * V_15 ,
T_3 V_73 , void T_5 * V_81 ,
bool V_78 , T_3 V_87 ,
enum V_91 * V_92 )
{
struct V_80 T_5 * V_44 =
(struct V_80 T_5 * ) V_81 ;
T_3 V_71 ;
int V_28 = 0 ;
struct V_61 * V_74 = NULL ;
long V_93 = F_64 ( V_87 ) ;
F_43 ( & V_15 -> V_43 ) ;
V_74 = F_58 ( V_73 ) ;
if ( ! V_74 ) {
V_28 = - V_40 ;
goto V_94;
}
for ( V_71 = 0 ; V_71 < V_73 ; V_71 ++ ) {
struct V_80 V_95 ;
if ( F_69 ( & V_95 , & V_44 [ V_71 ] ,
sizeof( struct V_80 ) ) )
goto V_94;
V_28 = F_60 ( V_15 , & V_74 [ V_71 ] ,
V_95 . V_33 , V_71 ) ;
if ( V_28 )
goto V_94;
}
F_45 ( & V_15 -> V_43 ) ;
while ( true ) {
if ( F_70 ( V_75 ) ) {
V_28 = - V_96 ;
break;
}
if ( F_71 ( V_75 ) ) {
V_28 = - V_97 ;
break;
}
if ( F_61 ( V_78 , V_73 , V_74 ) ) {
if ( F_62 ( V_73 ,
V_74 , V_44 ) )
* V_92 = V_98 ;
else
* V_92 = V_99 ;
break;
}
if ( V_93 <= 0 ) {
* V_92 = V_100 ;
break;
}
V_93 = F_72 ( V_93 ) ;
}
F_73 ( V_101 ) ;
F_43 ( & V_15 -> V_43 ) ;
F_67 ( V_73 , V_74 ) ;
F_45 ( & V_15 -> V_43 ) ;
return V_28 ;
V_94:
if ( V_74 )
F_67 ( V_73 , V_74 ) ;
F_45 ( & V_15 -> V_43 ) ;
* V_92 = V_99 ;
return V_28 ;
}
int F_74 ( struct V_4 * V_15 , struct V_102 * V_103 )
{
unsigned int V_25 ;
unsigned long V_104 ;
struct V_1 * V_2 ;
if ( F_10 ( V_21 * 8 ) !=
F_10 ( V_103 -> V_105 - V_103 -> V_106 ) ) {
F_75 ( L_8 ) ;
return - V_60 ;
}
V_25 = V_103 -> V_107 ;
V_2 = F_18 ( V_15 , V_25 ) ;
if ( ! V_2 ) {
F_6 ( L_9 ,
V_25 ) ;
return - V_60 ;
}
V_104 = F_76 ( V_2 -> V_3 ) ;
V_104 >>= V_59 ;
V_103 -> V_108 |= V_109 | V_110 | V_111 | V_112
| V_113 | V_114 ;
F_6 ( L_10 ) ;
F_6 ( L_11 , V_103 -> V_106 ) ;
F_6 ( L_12 , V_103 -> V_105 ) ;
F_6 ( L_13 , V_104 ) ;
F_6 ( L_14 , V_103 -> V_108 ) ;
F_6 ( L_15 ,
V_103 -> V_105 - V_103 -> V_106 ) ;
V_2 -> V_42 = ( T_1 T_5 * ) V_103 -> V_106 ;
return F_77 ( V_103 , V_103 -> V_106 , V_104 ,
V_103 -> V_105 - V_103 -> V_106 , V_103 -> V_115 ) ;
}
static void F_78 ( struct V_4 * V_15 ,
int type , void * V_95 )
{
struct V_82 * V_116 ;
struct V_30 * V_32 ;
int V_117 ;
bool V_118 = true ;
V_116 = (struct V_82 * ) V_95 ;
F_79 (p->events, bkt, ev, events)
if ( V_32 -> type == type ) {
V_118 = false ;
F_80 ( V_119 ,
L_16 ,
V_32 -> V_33 , V_32 -> type ) ;
F_47 ( V_32 ) ;
if ( V_32 -> type == V_85 && V_116 )
V_32 -> V_86 = * V_116 ;
}
if ( V_118 ) {
if ( V_120 ) {
F_81 ( V_119 ,
L_17 ,
V_15 -> V_121 -> V_122 ) ;
F_82 ( V_123 , V_15 -> V_121 , 0 ) ;
} else {
F_83 ( V_119 ,
L_18 ,
V_15 -> V_121 -> V_122 ) ;
}
}
}
void F_84 ( struct V_124 * V_125 , unsigned int V_67 ,
unsigned long V_126 , bool V_127 ,
bool V_128 )
{
struct V_82 V_86 ;
struct V_102 * V_103 ;
struct V_4 * V_15 = F_57 ( V_67 ) ;
if ( ! V_15 )
return;
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
F_85 ( & V_15 -> V_129 -> V_130 ) ;
V_103 = F_86 ( V_15 -> V_129 , V_126 ) ;
V_86 . V_131 = V_125 -> V_31 ;
V_86 . V_132 = V_126 ;
V_86 . V_133 . V_134 = 1 ;
V_86 . V_133 . V_135 = 0 ;
V_86 . V_133 . V_136 = 0 ;
if ( V_103 ) {
if ( V_103 -> V_106 > V_126 ) {
V_86 . V_133 . V_134 = 1 ;
V_86 . V_133 . V_135 = 0 ;
V_86 . V_133 . V_136 = 0 ;
} else {
V_86 . V_133 . V_134 = 0 ;
if ( V_127 && ! ( V_103 -> V_108 & V_137 ) )
V_86 . V_133 . V_136 = 1 ;
else
V_86 . V_133 . V_136 = 0 ;
if ( V_128 && ! ( V_103 -> V_108 & V_138 ) )
V_86 . V_133 . V_135 = 1 ;
else
V_86 . V_133 . V_135 = 0 ;
}
}
F_87 ( & V_15 -> V_129 -> V_130 ) ;
F_43 ( & V_15 -> V_43 ) ;
F_78 ( V_15 , V_85 ,
& V_86 ) ;
F_45 ( & V_15 -> V_43 ) ;
F_45 ( & V_15 -> V_72 ) ;
}
void F_88 ( unsigned int V_67 )
{
struct V_4 * V_15 = F_57 ( V_67 ) ;
if ( ! V_15 )
return;
F_43 ( & V_15 -> V_43 ) ;
F_78 ( V_15 , V_139 , NULL ) ;
F_45 ( & V_15 -> V_43 ) ;
F_45 ( & V_15 -> V_72 ) ;
}
