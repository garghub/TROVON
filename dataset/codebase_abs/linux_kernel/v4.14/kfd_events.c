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
F_19 ( V_15 , V_31 ) ;
V_31 ++ )
;
if ( V_31 < V_36 ) {
V_15 -> V_35 = V_31 + 1 ;
return V_31 ;
}
for ( V_31 = V_37 ;
V_31 < V_36 &&
F_19 ( V_15 , V_31 ) ;
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
if ( ! V_15 -> V_40 ) {
F_25 ( L_5 ) ;
V_15 -> V_40 = true ;
}
return - V_41 ;
}
if ( ! F_15 ( V_14 , V_15 , & V_32 -> V_1 ,
& V_32 -> V_27 ) ) {
F_25 ( L_6 ) ;
return - V_41 ;
}
V_15 -> V_39 ++ ;
V_32 -> V_42 =
& V_32 -> V_1 -> V_43 [ V_32 -> V_27 ] ;
V_32 -> V_33 = F_21 ( V_32 -> V_1 ,
V_32 -> V_27 ) ;
F_6 ( L_7 ,
V_15 -> V_39 , V_32 -> V_33 ,
V_32 -> V_42 ) ;
return 0 ;
}
static int F_26 ( struct V_4 * V_15 , struct V_30 * V_32 )
{
V_32 -> V_33 = F_22 ( V_15 ) ;
if ( V_32 -> V_33 == 0 )
return - V_41 ;
return 0 ;
}
void F_27 ( struct V_4 * V_15 )
{
F_28 ( & V_15 -> V_44 ) ;
F_29 ( V_15 -> V_45 ) ;
F_30 ( & V_15 -> V_24 ) ;
V_15 -> V_35 = V_37 ;
V_15 -> V_39 = 0 ;
}
static void F_31 ( struct V_4 * V_15 , struct V_30 * V_32 )
{
if ( V_32 -> V_1 ) {
F_16 ( V_32 -> V_1 ,
V_32 -> V_27 ) ;
V_15 -> V_39 -- ;
}
F_32 ( & V_32 -> V_46 ) ;
F_33 ( & V_32 -> V_45 ) ;
F_14 ( V_32 ) ;
}
static void F_34 ( struct V_4 * V_15 )
{
struct V_30 * V_32 ;
struct V_47 * V_48 ;
unsigned int V_49 ;
F_35 (p->events, hash_bkt, tmp, ev, events)
F_31 ( V_15 , V_32 ) ;
}
static void F_36 ( struct V_4 * V_15 )
{
struct V_1 * V_2 , * V_48 ;
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
return V_32 -> type == V_50 ||
V_32 -> type == V_51 ;
}
static bool F_41 ( const struct V_30 * V_32 )
{
return V_32 -> type == V_50 ;
}
int F_42 ( struct V_13 * V_14 , struct V_4 * V_15 ,
T_3 V_52 , bool V_53 , T_3 V_54 ,
T_3 * V_33 , T_3 * V_55 ,
T_1 * V_56 , T_3 * V_57 )
{
int V_28 = 0 ;
struct V_30 * V_32 = F_8 ( sizeof( * V_32 ) , V_18 ) ;
if ( ! V_32 )
return - V_41 ;
V_32 -> type = V_52 ;
V_32 -> V_53 = V_53 ;
V_32 -> V_58 = false ;
F_30 ( & V_32 -> V_46 ) ;
* V_56 = 0 ;
F_43 ( & V_15 -> V_44 ) ;
switch ( V_52 ) {
case V_50 :
case V_51 :
V_28 = F_24 ( V_14 , V_15 , V_32 ) ;
if ( ! V_28 ) {
* V_56 = ( V_32 -> V_1 -> V_25 |
V_59 ) ;
* V_56 <<= V_60 ;
* V_57 = V_32 -> V_27 ;
}
break;
default:
V_28 = F_26 ( V_15 , V_32 ) ;
break;
}
if ( ! V_28 ) {
F_44 ( V_15 -> V_45 , & V_32 -> V_45 , V_32 -> V_33 ) ;
* V_33 = V_32 -> V_33 ;
* V_55 = V_32 -> V_33 ;
} else {
F_14 ( V_32 ) ;
}
F_45 ( & V_15 -> V_44 ) ;
return V_28 ;
}
int F_46 ( struct V_4 * V_15 , T_3 V_33 )
{
struct V_30 * V_32 ;
int V_28 = 0 ;
F_43 ( & V_15 -> V_44 ) ;
V_32 = F_19 ( V_15 , V_33 ) ;
if ( V_32 )
F_31 ( V_15 , V_32 ) ;
else
V_28 = - V_61 ;
F_45 ( & V_15 -> V_44 ) ;
return V_28 ;
}
static void F_47 ( struct V_30 * V_32 )
{
struct V_62 * V_63 ;
struct V_62 * V_64 ;
V_32 -> V_58 = ! V_32 -> V_53 || F_11 ( & V_32 -> V_46 ) ;
F_37 (waiter, next, &ev->waiters, waiters) {
V_63 -> V_65 = true ;
F_48 ( & V_63 -> V_46 ) ;
F_49 ( V_63 -> V_66 ) ;
}
}
int F_50 ( struct V_4 * V_15 , T_3 V_33 )
{
int V_28 = 0 ;
struct V_30 * V_32 ;
F_43 ( & V_15 -> V_44 ) ;
V_32 = F_19 ( V_15 , V_33 ) ;
if ( V_32 && F_41 ( V_32 ) )
F_47 ( V_32 ) ;
else
V_28 = - V_61 ;
F_45 ( & V_15 -> V_44 ) ;
return V_28 ;
}
static void F_51 ( struct V_30 * V_32 )
{
V_32 -> V_58 = false ;
}
int F_52 ( struct V_4 * V_15 , T_3 V_33 )
{
int V_28 = 0 ;
struct V_30 * V_32 ;
F_43 ( & V_15 -> V_44 ) ;
V_32 = F_19 ( V_15 , V_33 ) ;
if ( V_32 && F_41 ( V_32 ) )
F_51 ( V_32 ) ;
else
V_28 = - V_61 ;
F_45 ( & V_15 -> V_44 ) ;
return V_28 ;
}
static void F_53 ( struct V_4 * V_15 , struct V_30 * V_32 )
{
F_1 ( V_32 -> V_1 ) [ V_32 -> V_27 ] =
V_12 ;
}
static bool F_54 ( struct V_1 * V_2 , unsigned int V_67 )
{
return F_1 ( V_2 ) [ V_67 ] != V_12 ;
}
static void F_55 ( struct V_4 * V_15 ,
struct V_30 * V_32 )
{
if ( V_32 && F_40 ( V_32 ) ) {
F_53 ( V_15 , V_32 ) ;
F_47 ( V_32 ) ;
}
}
void F_56 ( unsigned int V_68 , T_3 V_69 ,
T_3 V_70 )
{
struct V_30 * V_32 ;
struct V_4 * V_15 = F_57 ( V_68 ) ;
if ( ! V_15 )
return;
F_43 ( & V_15 -> V_44 ) ;
if ( V_70 >= V_71 ) {
V_32 = F_19 ( V_15 , V_69 ) ;
F_55 ( V_15 , V_32 ) ;
} else {
struct V_1 * V_2 ;
unsigned int V_72 ;
F_3 (page, &p->signal_event_pages, event_pages)
for ( V_72 = 0 ; V_72 < V_11 ; V_72 ++ )
if ( F_54 ( V_2 , V_72 ) ) {
V_32 = F_23 ( V_15 ,
V_2 , V_72 ) ;
F_55 ( V_15 , V_32 ) ;
}
}
F_45 ( & V_15 -> V_44 ) ;
F_45 ( & V_15 -> V_73 ) ;
}
static struct V_62 * F_58 ( T_3 V_74 )
{
struct V_62 * V_75 ;
T_3 V_72 ;
V_75 = F_59 ( V_74 ,
sizeof( struct V_62 ) ,
V_18 ) ;
for ( V_72 = 0 ; ( V_75 ) && ( V_72 < V_74 ) ; V_72 ++ ) {
F_30 ( & V_75 [ V_72 ] . V_46 ) ;
V_75 [ V_72 ] . V_66 = V_76 ;
V_75 [ V_72 ] . V_65 = false ;
}
return V_75 ;
}
static int F_60 ( struct V_4 * V_15 ,
struct V_62 * V_63 ,
T_3 V_33 ,
T_3 V_77 )
{
struct V_30 * V_32 = F_19 ( V_15 , V_33 ) ;
if ( ! V_32 )
return - V_61 ;
V_63 -> V_78 = V_32 ;
V_63 -> V_77 = V_77 ;
V_63 -> V_65 = V_32 -> V_58 ;
V_32 -> V_58 = V_32 -> V_58 && ! V_32 -> V_53 ;
F_13 ( & V_63 -> V_46 , & V_32 -> V_46 ) ;
return 0 ;
}
static bool F_61 ( bool V_79 , T_3 V_74 ,
struct V_62 * V_75 )
{
T_3 V_72 ;
T_3 V_80 = 0 ;
for ( V_72 = 0 ; V_72 < V_74 ; V_72 ++ ) {
if ( V_75 [ V_72 ] . V_65 ) {
if ( ! V_79 )
return true ;
V_80 ++ ;
}
}
return V_80 == V_74 ;
}
static bool F_62 ( T_3 V_74 ,
struct V_62 * V_75 ,
struct V_81 T_5 * V_82 )
{
struct V_83 * V_84 ;
struct V_83 T_5 * V_85 ;
struct V_62 * V_63 ;
struct V_30 * V_78 ;
T_3 V_72 ;
for ( V_72 = 0 ; V_72 < V_74 ; V_72 ++ ) {
V_63 = & V_75 [ V_72 ] ;
V_78 = V_63 -> V_78 ;
if ( V_63 -> V_65 && V_78 -> type == V_86 ) {
V_85 = & V_82 [ V_63 -> V_77 ] . V_87 ;
V_84 = & V_78 -> V_87 ;
if ( F_63 ( V_85 , V_84 ,
sizeof( struct V_83 ) ) )
return false ;
}
}
return true ;
}
static long F_64 ( T_3 V_88 )
{
if ( V_88 == V_89 )
return 0 ;
if ( V_88 == V_90 )
return V_91 ;
V_88 = F_65 ( T_3 , V_88 , 0x7FFFFFFF ) ;
return F_66 ( V_88 ) + 1 ;
}
static void F_67 ( T_3 V_74 , struct V_62 * V_46 )
{
T_3 V_72 ;
for ( V_72 = 0 ; V_72 < V_74 ; V_72 ++ )
F_32 ( & V_46 [ V_72 ] . V_46 ) ;
F_14 ( V_46 ) ;
}
int F_68 ( struct V_4 * V_15 ,
T_3 V_74 , void T_5 * V_82 ,
bool V_79 , T_3 V_88 ,
enum V_92 * V_93 )
{
struct V_81 T_5 * V_45 =
(struct V_81 T_5 * ) V_82 ;
T_3 V_72 ;
int V_28 = 0 ;
struct V_62 * V_75 = NULL ;
long V_94 = F_64 ( V_88 ) ;
F_43 ( & V_15 -> V_44 ) ;
V_75 = F_58 ( V_74 ) ;
if ( ! V_75 ) {
V_28 = - V_41 ;
goto V_95;
}
for ( V_72 = 0 ; V_72 < V_74 ; V_72 ++ ) {
struct V_81 V_96 ;
if ( F_69 ( & V_96 , & V_45 [ V_72 ] ,
sizeof( struct V_81 ) ) ) {
V_28 = - V_97 ;
goto V_95;
}
V_28 = F_60 ( V_15 , & V_75 [ V_72 ] ,
V_96 . V_33 , V_72 ) ;
if ( V_28 )
goto V_95;
}
F_45 ( & V_15 -> V_44 ) ;
while ( true ) {
if ( F_70 ( V_76 ) ) {
V_28 = - V_98 ;
break;
}
if ( F_71 ( V_76 ) ) {
V_28 = - V_99 ;
break;
}
if ( F_61 ( V_79 , V_74 , V_75 ) ) {
if ( F_62 ( V_74 ,
V_75 , V_45 ) )
* V_93 = V_100 ;
else
* V_93 = V_101 ;
break;
}
if ( V_94 <= 0 ) {
* V_93 = V_102 ;
break;
}
V_94 = F_72 ( V_94 ) ;
}
F_73 ( V_103 ) ;
F_43 ( & V_15 -> V_44 ) ;
F_67 ( V_74 , V_75 ) ;
F_45 ( & V_15 -> V_44 ) ;
return V_28 ;
V_95:
if ( V_75 )
F_67 ( V_74 , V_75 ) ;
F_45 ( & V_15 -> V_44 ) ;
* V_93 = V_101 ;
return V_28 ;
}
int F_74 ( struct V_4 * V_15 , struct V_104 * V_105 )
{
unsigned int V_25 ;
unsigned long V_106 ;
struct V_1 * V_2 ;
if ( F_10 ( V_21 * 8 ) !=
F_10 ( V_105 -> V_107 - V_105 -> V_108 ) ) {
F_75 ( L_8 ) ;
return - V_61 ;
}
V_25 = V_105 -> V_109 ;
V_2 = F_18 ( V_15 , V_25 ) ;
if ( ! V_2 ) {
F_6 ( L_9 ,
V_25 ) ;
return - V_61 ;
}
V_106 = F_76 ( V_2 -> V_3 ) ;
V_106 >>= V_60 ;
V_105 -> V_110 |= V_111 | V_112 | V_113 | V_114
| V_115 | V_116 ;
F_6 ( L_10 ) ;
F_6 ( L_11 , V_105 -> V_108 ) ;
F_6 ( L_12 , V_105 -> V_107 ) ;
F_6 ( L_13 , V_106 ) ;
F_6 ( L_14 , V_105 -> V_110 ) ;
F_6 ( L_15 ,
V_105 -> V_107 - V_105 -> V_108 ) ;
V_2 -> V_43 = ( T_1 T_5 * ) V_105 -> V_108 ;
return F_77 ( V_105 , V_105 -> V_108 , V_106 ,
V_105 -> V_107 - V_105 -> V_108 , V_105 -> V_117 ) ;
}
static void F_78 ( struct V_4 * V_15 ,
int type , void * V_96 )
{
struct V_83 * V_118 ;
struct V_30 * V_32 ;
int V_119 ;
bool V_120 = true ;
V_118 = (struct V_83 * ) V_96 ;
F_79 (p->events, bkt, ev, events)
if ( V_32 -> type == type ) {
V_120 = false ;
F_80 ( V_121 ,
L_16 ,
V_32 -> V_33 , V_32 -> type ) ;
F_47 ( V_32 ) ;
if ( V_32 -> type == V_86 && V_118 )
V_32 -> V_87 = * V_118 ;
}
if ( V_120 ) {
if ( V_122 ) {
F_81 ( V_121 ,
L_17 ,
V_15 -> V_123 -> V_124 ) ;
F_82 ( V_125 , V_15 -> V_123 , 0 ) ;
} else {
F_83 ( V_121 ,
L_18 ,
V_15 -> V_123 -> V_124 ) ;
}
}
}
void F_84 ( struct V_126 * V_127 , unsigned int V_68 ,
unsigned long V_128 , bool V_129 ,
bool V_130 )
{
struct V_83 V_87 ;
struct V_104 * V_105 ;
struct V_4 * V_15 = F_57 ( V_68 ) ;
if ( ! V_15 )
return;
memset ( & V_87 , 0 , sizeof( V_87 ) ) ;
F_85 ( & V_15 -> V_131 -> V_132 ) ;
V_105 = F_86 ( V_15 -> V_131 , V_128 ) ;
V_87 . V_133 = V_127 -> V_31 ;
V_87 . V_134 = V_128 ;
V_87 . V_135 . V_136 = 1 ;
V_87 . V_135 . V_137 = 0 ;
V_87 . V_135 . V_138 = 0 ;
if ( V_105 ) {
if ( V_105 -> V_108 > V_128 ) {
V_87 . V_135 . V_136 = 1 ;
V_87 . V_135 . V_137 = 0 ;
V_87 . V_135 . V_138 = 0 ;
} else {
V_87 . V_135 . V_136 = 0 ;
if ( V_129 && ! ( V_105 -> V_110 & V_139 ) )
V_87 . V_135 . V_138 = 1 ;
else
V_87 . V_135 . V_138 = 0 ;
if ( V_130 && ! ( V_105 -> V_110 & V_140 ) )
V_87 . V_135 . V_137 = 1 ;
else
V_87 . V_135 . V_137 = 0 ;
}
}
F_87 ( & V_15 -> V_131 -> V_132 ) ;
F_43 ( & V_15 -> V_44 ) ;
F_78 ( V_15 , V_86 ,
& V_87 ) ;
F_45 ( & V_15 -> V_44 ) ;
F_45 ( & V_15 -> V_73 ) ;
}
void F_88 ( unsigned int V_68 )
{
struct V_4 * V_15 = F_57 ( V_68 ) ;
if ( ! V_15 )
return;
F_43 ( & V_15 -> V_44 ) ;
F_78 ( V_15 , V_141 , NULL ) ;
F_45 ( & V_15 -> V_44 ) ;
F_45 ( & V_15 -> V_73 ) ;
}
