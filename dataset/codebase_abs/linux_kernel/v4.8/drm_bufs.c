static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_6 ;
F_2 (entry, &dev->maplist, head) {
if ( ! V_6 -> V_5 ||
V_5 -> type != V_6 -> V_5 -> type ||
V_6 -> V_7 != V_3 -> V_7 )
continue;
switch ( V_5 -> type ) {
case V_8 :
if ( V_5 -> V_9 != V_10 )
break;
return V_6 ;
case V_11 :
case V_12 :
if ( ( V_6 -> V_5 -> V_13 & 0xffffffff ) ==
( V_5 -> V_13 & 0xffffffff ) )
return V_6 ;
default:
;
}
if ( V_6 -> V_5 -> V_13 == V_5 -> V_13 )
return V_6 ;
}
return NULL ;
}
static int F_3 ( struct V_2 * V_3 , struct V_14 * V_15 ,
unsigned long V_16 , int V_17 , int V_18 )
{
int V_19 , V_20 ;
unsigned long V_21 ;
#if ( V_22 == 64 )
V_19 = ( ( V_16 & 0xFFFFFFFF00000000UL ) || V_17 ) ;
#elif ( V_22 == 32 )
V_19 = V_17 ;
#else
#error Unsupported long size. Neither 64 nor 32 bits.
#endif
if ( ! V_19 ) {
int V_23 ;
V_15 -> V_24 = V_16 >> V_25 ;
V_23 = F_4 ( & V_3 -> V_26 , V_15 ) ;
if ( V_23 != - V_27 )
return V_23 ;
}
V_20 = 0 ;
V_21 = V_28 >> V_25 ;
if ( V_18 && ( V_29 > V_30 ) ) {
int V_31 = F_5 ( V_29 >> V_25 ) + 1 ;
V_20 = V_31 ;
V_21 |= ( ( V_16 >> V_25 ) & ( ( 1UL << V_31 ) - 1UL ) ) ;
}
return F_6 ( & V_3 -> V_26 , V_15 ,
V_16 , 32 - V_25 - 3 ,
V_20 , V_21 ) ;
}
static int F_7 ( struct V_2 * V_3 , T_1 V_13 ,
unsigned int V_32 , enum V_33 type ,
enum V_34 V_9 ,
struct V_1 * * V_35 )
{
struct V_4 * V_5 ;
struct V_1 * V_36 ;
T_2 * V_37 ;
unsigned long V_16 ;
int V_23 ;
V_5 = F_8 ( sizeof( * V_5 ) , V_38 ) ;
if ( ! V_5 )
return - V_39 ;
V_5 -> V_13 = V_13 ;
V_5 -> V_32 = V_32 ;
V_5 -> V_9 = V_9 ;
V_5 -> type = type ;
if ( ( V_5 -> V_9 & V_40 ) && V_5 -> type != V_8 ) {
F_9 ( V_5 ) ;
return - V_27 ;
}
F_10 ( L_1 ,
( unsigned long long ) V_5 -> V_13 , V_5 -> V_32 , V_5 -> type ) ;
if ( V_5 -> type == V_8 )
V_5 -> V_32 = F_11 ( V_5 -> V_32 ) ;
if ( ( V_5 -> V_13 & ( ~ ( T_1 ) V_41 ) ) || ( V_5 -> V_32 & ( ~ V_41 ) ) ) {
F_9 ( V_5 ) ;
return - V_27 ;
}
V_5 -> V_42 = - 1 ;
V_5 -> V_43 = NULL ;
switch ( V_5 -> type ) {
case V_11 :
case V_12 :
#if ! F_12 ( V_44 ) && ! F_12 ( V_45 ) && ! F_12 ( V_46 ) && ! F_12 ( V_47 ) && ! F_12 ( V_48 ) && ! F_12 ( V_49 )
if ( V_5 -> V_13 + ( V_5 -> V_32 - 1 ) < V_5 -> V_13 ||
V_5 -> V_13 < F_13 ( V_50 ) ) {
F_9 ( V_5 ) ;
return - V_27 ;
}
#endif
V_36 = F_1 ( V_3 , V_5 ) ;
if ( V_36 != NULL ) {
if ( V_36 -> V_5 -> V_32 != V_5 -> V_32 ) {
F_10 ( L_2
L_3 ,
V_5 -> type , V_5 -> V_32 ,
V_36 -> V_5 -> V_32 ) ;
V_36 -> V_5 -> V_32 = V_5 -> V_32 ;
}
F_9 ( V_5 ) ;
* V_35 = V_36 ;
return 0 ;
}
if ( V_5 -> type == V_12 ||
( V_5 -> V_9 & V_51 ) ) {
V_5 -> V_42 =
F_14 ( V_5 -> V_13 , V_5 -> V_32 ) ;
}
if ( V_5 -> type == V_11 ) {
if ( V_5 -> V_9 & V_51 )
V_5 -> V_43 = F_15 ( V_5 -> V_13 ,
V_5 -> V_32 ) ;
else
V_5 -> V_43 = F_16 ( V_5 -> V_13 , V_5 -> V_32 ) ;
if ( ! V_5 -> V_43 ) {
F_9 ( V_5 ) ;
return - V_39 ;
}
}
break;
case V_8 :
V_36 = F_1 ( V_3 , V_5 ) ;
if ( V_36 != NULL ) {
if( V_36 -> V_5 -> V_32 != V_5 -> V_32 ) {
F_10 ( L_2
L_3 ,
V_5 -> type , V_5 -> V_32 , V_36 -> V_5 -> V_32 ) ;
V_36 -> V_5 -> V_32 = V_5 -> V_32 ;
}
F_9 ( V_5 ) ;
* V_35 = V_36 ;
return 0 ;
}
V_5 -> V_43 = F_17 ( V_5 -> V_32 ) ;
F_10 ( L_4 ,
V_5 -> V_32 , F_18 ( V_5 -> V_32 ) , V_5 -> V_43 ) ;
if ( ! V_5 -> V_43 ) {
F_9 ( V_5 ) ;
return - V_39 ;
}
V_5 -> V_13 = ( unsigned long ) V_5 -> V_43 ;
if ( V_5 -> V_9 & V_10 ) {
if ( V_3 -> V_7 -> V_52 . V_53 != NULL ) {
F_19 ( V_5 -> V_43 ) ;
F_9 ( V_5 ) ;
return - V_54 ;
}
V_3 -> V_55 . V_52 = V_3 -> V_7 -> V_52 . V_53 = V_5 -> V_43 ;
}
break;
case V_56 : {
struct V_57 * V_6 ;
int V_58 = 0 ;
if ( ! V_3 -> V_59 ) {
F_9 ( V_5 ) ;
return - V_27 ;
}
#ifdef V_45
V_5 -> V_13 += V_3 -> V_60 -> V_61 -> V_62 ;
#endif
if ( V_5 -> V_13 < V_3 -> V_59 -> V_63 ||
V_5 -> V_13 > V_3 -> V_59 -> V_63 +
V_3 -> V_59 -> V_64 . V_65 * 1024 * 1024 - 1 ) {
V_5 -> V_13 += V_3 -> V_59 -> V_63 ;
}
V_5 -> V_42 = V_3 -> V_59 -> V_66 ;
F_2 (entry, &dev->agp->memory, head) {
if ( ( V_5 -> V_13 >= V_6 -> V_67 ) &&
( V_5 -> V_13 + V_5 -> V_32 <= V_6 -> V_67 + V_6 -> V_68 * V_30 ) ) {
V_58 = 1 ;
break;
}
}
if ( ! F_20 ( & V_3 -> V_59 -> V_69 ) && ! V_58 ) {
F_9 ( V_5 ) ;
return - V_70 ;
}
F_10 ( L_5 ,
( unsigned long long ) V_5 -> V_13 , V_5 -> V_32 ) ;
break;
}
case V_71 :
if ( ! V_3 -> V_72 ) {
F_9 ( V_5 ) ;
return - V_27 ;
}
V_5 -> V_13 += ( unsigned long ) V_3 -> V_72 -> V_73 ;
break;
case V_74 :
V_37 = F_21 ( V_3 , V_5 -> V_32 , V_5 -> V_32 ) ;
if ( ! V_37 ) {
F_9 ( V_5 ) ;
return - V_39 ;
}
V_5 -> V_43 = V_37 -> V_75 ;
V_5 -> V_13 = ( unsigned long ) V_37 -> V_76 ;
F_9 ( V_37 ) ;
break;
default:
F_9 ( V_5 ) ;
return - V_27 ;
}
V_36 = F_22 ( sizeof( * V_36 ) , V_38 ) ;
if ( ! V_36 ) {
if ( V_5 -> type == V_11 )
F_23 ( V_5 -> V_43 ) ;
F_9 ( V_5 ) ;
return - V_27 ;
}
V_36 -> V_5 = V_5 ;
F_24 ( & V_3 -> V_77 ) ;
F_25 ( & V_36 -> V_78 , & V_3 -> V_35 ) ;
V_16 = ( V_5 -> type == V_8 ) ? ( unsigned long ) V_5 -> V_43 :
V_5 -> V_13 ;
V_23 = F_3 ( V_3 , & V_36 -> V_15 , V_16 , 0 ,
( V_5 -> type == V_8 ) ) ;
if ( V_23 ) {
if ( V_5 -> type == V_11 )
F_23 ( V_5 -> V_43 ) ;
F_9 ( V_5 ) ;
F_9 ( V_36 ) ;
F_26 ( & V_3 -> V_77 ) ;
return V_23 ;
}
V_36 -> V_16 = V_36 -> V_15 . V_24 << V_25 ;
F_26 ( & V_3 -> V_77 ) ;
if ( ! ( V_5 -> V_9 & V_79 ) )
V_36 -> V_7 = V_3 -> V_7 ;
* V_35 = V_36 ;
return 0 ;
}
int F_27 ( struct V_2 * V_3 , T_1 V_13 ,
unsigned int V_32 , enum V_33 type ,
enum V_34 V_9 , struct V_4 * * V_80 )
{
struct V_1 * V_36 ;
int V_81 ;
V_81 = F_7 ( V_3 , V_13 , V_32 , type , V_9 , & V_36 ) ;
if ( ! V_81 )
* V_80 = V_36 -> V_5 ;
return V_81 ;
}
int F_28 ( struct V_2 * V_3 , void * V_82 ,
struct V_83 * V_84 )
{
struct V_85 * V_5 = V_82 ;
struct V_1 * V_35 ;
int V_86 ;
if ( ! ( F_29 ( V_87 ) || V_5 -> type == V_56 || V_5 -> type == V_8 ) )
return - V_70 ;
if ( ! F_30 ( V_3 , V_88 ) &&
F_30 ( V_3 , V_89 ) )
return - V_27 ;
V_86 = F_7 ( V_3 , V_5 -> V_13 , V_5 -> V_32 , V_5 -> type ,
V_5 -> V_9 , & V_35 ) ;
if ( V_86 )
return V_86 ;
V_5 -> V_43 = ( void * ) ( unsigned long ) V_35 -> V_16 ;
V_5 -> V_42 = - 1 ;
return 0 ;
}
int F_31 ( struct V_2 * V_3 , void * V_82 ,
struct V_83 * V_84 )
{
struct V_85 * V_5 = V_82 ;
struct V_1 * V_90 = NULL ;
struct V_91 * V_36 ;
int V_92 ;
int V_93 ;
if ( ! F_30 ( V_3 , V_88 ) &&
F_30 ( V_3 , V_89 ) )
return - V_27 ;
V_92 = V_5 -> V_13 ;
if ( V_92 < 0 )
return - V_27 ;
V_93 = 0 ;
F_24 ( & V_3 -> V_77 ) ;
F_32 (list, &dev->maplist) {
if ( V_93 == V_92 ) {
V_90 = F_33 ( V_36 , struct V_1 , V_78 ) ;
break;
}
V_93 ++ ;
}
if ( ! V_90 || ! V_90 -> V_5 ) {
F_26 ( & V_3 -> V_77 ) ;
return - V_27 ;
}
V_5 -> V_13 = V_90 -> V_5 -> V_13 ;
V_5 -> V_32 = V_90 -> V_5 -> V_32 ;
V_5 -> type = V_90 -> V_5 -> type ;
V_5 -> V_9 = V_90 -> V_5 -> V_9 ;
V_5 -> V_43 = ( void * ) ( unsigned long ) V_90 -> V_16 ;
V_5 -> V_42 = F_34 ( V_90 -> V_5 -> V_42 ) ;
F_26 ( & V_3 -> V_77 ) ;
return 0 ;
}
int F_35 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_90 = NULL , * V_94 ;
T_2 V_37 ;
int V_95 = 0 ;
struct V_96 * V_7 ;
F_36 (r_list, list_t, &dev->maplist, head) {
if ( V_90 -> V_5 == V_5 ) {
V_7 = V_90 -> V_7 ;
F_37 ( & V_90 -> V_78 ) ;
F_38 ( & V_3 -> V_26 ,
V_90 -> V_16 >> V_25 ) ;
F_9 ( V_90 ) ;
V_95 = 1 ;
break;
}
}
if ( ! V_95 )
return - V_27 ;
switch ( V_5 -> type ) {
case V_11 :
F_23 ( V_5 -> V_43 ) ;
case V_12 :
F_39 ( V_5 -> V_42 ) ;
break;
case V_8 :
F_19 ( V_5 -> V_43 ) ;
if ( V_7 ) {
if ( V_3 -> V_55 . V_52 == V_7 -> V_52 . V_53 )
V_3 -> V_55 . V_52 = NULL ;
V_7 -> V_52 . V_53 = NULL ;
V_7 -> V_52 . V_84 = NULL ;
F_40 ( & V_7 -> V_52 . V_97 ) ;
}
break;
case V_56 :
case V_71 :
break;
case V_74 :
V_37 . V_75 = V_5 -> V_43 ;
V_37 . V_76 = V_5 -> V_13 ;
V_37 . V_32 = V_5 -> V_32 ;
F_41 ( V_3 , & V_37 ) ;
break;
}
F_9 ( V_5 ) ;
return 0 ;
}
void F_42 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
if ( ! F_30 ( V_3 , V_88 ) &&
F_30 ( V_3 , V_89 ) )
return;
F_24 ( & V_3 -> V_77 ) ;
F_35 ( V_3 , V_5 ) ;
F_26 ( & V_3 -> V_77 ) ;
}
void F_43 ( struct V_2 * V_3 , struct V_96 * V_7 )
{
struct V_1 * V_90 , * V_98 ;
if ( F_30 ( V_3 , V_89 ) )
return;
F_24 ( & V_3 -> V_77 ) ;
F_36 (r_list, list_temp, &dev->maplist, head) {
if ( V_90 -> V_7 == V_7 ) {
F_35 ( V_3 , V_90 -> V_5 ) ;
V_90 = NULL ;
}
}
F_26 ( & V_3 -> V_77 ) ;
}
int F_44 ( struct V_2 * V_3 , void * V_82 ,
struct V_83 * V_84 )
{
struct V_85 * V_99 = V_82 ;
struct V_4 * V_5 = NULL ;
struct V_1 * V_90 ;
int V_23 ;
if ( ! F_30 ( V_3 , V_88 ) &&
F_30 ( V_3 , V_89 ) )
return - V_27 ;
F_24 ( & V_3 -> V_77 ) ;
F_2 (r_list, &dev->maplist, head) {
if ( V_90 -> V_5 &&
V_90 -> V_16 == ( unsigned long ) V_99 -> V_43 &&
V_90 -> V_5 -> V_9 & V_40 ) {
V_5 = V_90 -> V_5 ;
break;
}
}
if ( F_20 ( & V_3 -> V_35 ) || ! V_5 ) {
F_26 ( & V_3 -> V_77 ) ;
return - V_27 ;
}
if ( ( V_5 -> type == V_11 ) || ( V_5 -> type == V_12 ) ) {
F_26 ( & V_3 -> V_77 ) ;
return 0 ;
}
V_23 = F_35 ( V_3 , V_5 ) ;
F_26 ( & V_3 -> V_77 ) ;
return V_23 ;
}
static void F_45 ( struct V_2 * V_3 ,
struct V_100 * V_6 )
{
int V_93 ;
if ( V_6 -> V_101 ) {
for ( V_93 = 0 ; V_93 < V_6 -> V_101 ; V_93 ++ ) {
if ( V_6 -> V_102 [ V_93 ] ) {
F_46 ( V_3 , V_6 -> V_102 [ V_93 ] ) ;
}
}
F_9 ( V_6 -> V_102 ) ;
V_6 -> V_101 = 0 ;
}
if ( V_6 -> V_103 ) {
for ( V_93 = 0 ; V_93 < V_6 -> V_103 ; V_93 ++ ) {
F_9 ( V_6 -> V_104 [ V_93 ] . V_105 ) ;
}
F_9 ( V_6 -> V_104 ) ;
V_6 -> V_103 = 0 ;
}
}
int F_47 ( struct V_2 * V_3 ,
struct V_106 * V_99 )
{
struct V_107 * V_108 = V_3 -> V_108 ;
struct V_100 * V_6 ;
struct V_57 * V_109 ;
struct V_110 * V_111 ;
unsigned long V_13 ;
unsigned long V_112 ;
int V_113 ;
int V_114 ;
int V_32 ;
int V_115 ;
int V_116 ;
int V_117 ;
int V_118 ;
int V_93 , V_58 ;
struct V_110 * * V_119 ;
if ( ! V_108 )
return - V_27 ;
V_113 = V_99 -> V_113 ;
V_114 = F_18 ( V_99 -> V_32 ) ;
V_32 = 1 << V_114 ;
V_115 = ( V_99 -> V_9 & V_120 )
? F_11 ( V_32 ) : V_32 ;
V_116 = V_114 - V_25 > 0 ? V_114 - V_25 : 0 ;
V_117 = V_30 << V_116 ;
V_118 = 0 ;
V_112 = V_3 -> V_59 -> V_63 + V_99 -> V_121 ;
F_10 ( L_6 , V_113 ) ;
F_10 ( L_7 , V_114 ) ;
F_10 ( L_8 , V_32 ) ;
F_10 ( L_9 , V_112 ) ;
F_10 ( L_10 , V_115 ) ;
F_10 ( L_11 , V_116 ) ;
F_10 ( L_12 , V_117 ) ;
if ( V_114 < V_122 || V_114 > V_123 )
return - V_27 ;
V_58 = 0 ;
F_2 (agp_entry, &dev->agp->memory, head) {
if ( ( V_112 >= V_109 -> V_67 ) &&
( V_112 + V_117 * V_113 <= V_109 -> V_67 + V_109 -> V_68 * V_30 ) ) {
V_58 = 1 ;
break;
}
}
if ( ! F_20 ( & V_3 -> V_59 -> V_69 ) && ! V_58 ) {
F_10 ( L_13 ) ;
return - V_27 ;
}
F_48 ( & V_3 -> V_124 ) ;
if ( V_3 -> V_125 ) {
F_49 ( & V_3 -> V_124 ) ;
return - V_54 ;
}
F_50 ( & V_3 -> V_126 ) ;
F_49 ( & V_3 -> V_124 ) ;
F_24 ( & V_3 -> V_77 ) ;
V_6 = & V_108 -> V_127 [ V_114 ] ;
if ( V_6 -> V_103 ) {
F_26 ( & V_3 -> V_77 ) ;
F_51 ( & V_3 -> V_126 ) ;
return - V_39 ;
}
if ( V_113 < 0 || V_113 > 4096 ) {
F_26 ( & V_3 -> V_77 ) ;
F_51 ( & V_3 -> V_126 ) ;
return - V_27 ;
}
V_6 -> V_104 = F_22 ( V_113 * sizeof( * V_6 -> V_104 ) , V_38 ) ;
if ( ! V_6 -> V_104 ) {
F_26 ( & V_3 -> V_77 ) ;
F_51 ( & V_3 -> V_126 ) ;
return - V_39 ;
}
V_6 -> V_128 = V_32 ;
V_6 -> V_116 = V_116 ;
V_13 = 0 ;
while ( V_6 -> V_103 < V_113 ) {
V_111 = & V_6 -> V_104 [ V_6 -> V_103 ] ;
V_111 -> V_92 = V_108 -> V_103 + V_6 -> V_103 ;
V_111 -> V_117 = V_115 ;
V_111 -> V_114 = V_114 ;
V_111 -> V_129 = 0 ;
V_111 -> V_13 = ( V_108 -> V_118 + V_13 ) ;
V_111 -> V_130 = V_112 + V_13 ;
V_111 -> V_131 = ( void * ) ( V_112 + V_13 ) ;
V_111 -> V_132 = NULL ;
V_111 -> V_133 = 0 ;
V_111 -> V_134 = 0 ;
V_111 -> V_84 = NULL ;
V_111 -> V_135 = V_3 -> V_136 -> V_135 ;
V_111 -> V_105 = F_22 ( V_111 -> V_135 , V_38 ) ;
if ( ! V_111 -> V_105 ) {
V_6 -> V_103 = V_113 ;
F_45 ( V_3 , V_6 ) ;
F_26 ( & V_3 -> V_77 ) ;
F_51 ( & V_3 -> V_126 ) ;
return - V_39 ;
}
F_10 ( L_14 , V_6 -> V_103 , V_111 -> V_131 ) ;
V_13 += V_115 ;
V_6 -> V_103 ++ ;
V_118 += V_30 << V_116 ;
}
F_10 ( L_15 , V_118 ) ;
V_119 = F_52 ( V_108 -> V_104 ,
( V_108 -> V_103 + V_6 -> V_103 ) *
sizeof( * V_108 -> V_104 ) , V_38 ) ;
if ( ! V_119 ) {
F_45 ( V_3 , V_6 ) ;
F_26 ( & V_3 -> V_77 ) ;
F_51 ( & V_3 -> V_126 ) ;
return - V_39 ;
}
V_108 -> V_104 = V_119 ;
for ( V_93 = 0 ; V_93 < V_6 -> V_103 ; V_93 ++ ) {
V_108 -> V_104 [ V_93 + V_108 -> V_103 ] = & V_6 -> V_104 [ V_93 ] ;
}
V_108 -> V_103 += V_6 -> V_103 ;
V_108 -> V_101 += V_6 -> V_101 ;
V_108 -> V_137 += V_118 >> V_25 ;
V_108 -> V_118 += V_118 ;
F_10 ( L_16 , V_108 -> V_103 ) ;
F_10 ( L_17 , V_6 -> V_103 ) ;
F_26 ( & V_3 -> V_77 ) ;
V_99 -> V_113 = V_6 -> V_103 ;
V_99 -> V_32 = V_32 ;
V_108 -> V_9 = V_138 ;
F_51 ( & V_3 -> V_126 ) ;
return 0 ;
}
int F_53 ( struct V_2 * V_3 ,
struct V_106 * V_99 )
{
struct V_107 * V_108 = V_3 -> V_108 ;
int V_113 ;
int V_114 ;
int V_32 ;
int V_117 ;
int V_116 ;
struct V_100 * V_6 ;
T_2 * V_37 ;
struct V_110 * V_111 ;
int V_115 ;
unsigned long V_13 ;
int V_93 ;
int V_118 ;
int V_137 ;
unsigned long * V_139 ;
struct V_110 * * V_119 ;
if ( ! F_30 ( V_3 , V_140 ) )
return - V_27 ;
if ( ! V_108 )
return - V_27 ;
if ( ! F_29 ( V_87 ) )
return - V_70 ;
V_113 = V_99 -> V_113 ;
V_114 = F_18 ( V_99 -> V_32 ) ;
V_32 = 1 << V_114 ;
F_10 ( L_18 ,
V_99 -> V_113 , V_99 -> V_32 , V_32 , V_114 ) ;
if ( V_114 < V_122 || V_114 > V_123 )
return - V_27 ;
V_115 = ( V_99 -> V_9 & V_120 )
? F_11 ( V_32 ) : V_32 ;
V_116 = V_114 - V_25 > 0 ? V_114 - V_25 : 0 ;
V_117 = V_30 << V_116 ;
F_48 ( & V_3 -> V_124 ) ;
if ( V_3 -> V_125 ) {
F_49 ( & V_3 -> V_124 ) ;
return - V_54 ;
}
F_50 ( & V_3 -> V_126 ) ;
F_49 ( & V_3 -> V_124 ) ;
F_24 ( & V_3 -> V_77 ) ;
V_6 = & V_108 -> V_127 [ V_114 ] ;
if ( V_6 -> V_103 ) {
F_26 ( & V_3 -> V_77 ) ;
F_51 ( & V_3 -> V_126 ) ;
return - V_39 ;
}
if ( V_113 < 0 || V_113 > 4096 ) {
F_26 ( & V_3 -> V_77 ) ;
F_51 ( & V_3 -> V_126 ) ;
return - V_27 ;
}
V_6 -> V_104 = F_22 ( V_113 * sizeof( * V_6 -> V_104 ) , V_38 ) ;
if ( ! V_6 -> V_104 ) {
F_26 ( & V_3 -> V_77 ) ;
F_51 ( & V_3 -> V_126 ) ;
return - V_39 ;
}
V_6 -> V_102 = F_22 ( V_113 * sizeof( * V_6 -> V_102 ) , V_38 ) ;
if ( ! V_6 -> V_102 ) {
F_9 ( V_6 -> V_104 ) ;
F_26 ( & V_3 -> V_77 ) ;
F_51 ( & V_3 -> V_126 ) ;
return - V_39 ;
}
V_139 = F_8 ( ( V_108 -> V_137 + ( V_113 << V_116 ) ) *
sizeof( * V_108 -> V_141 ) , V_38 ) ;
if ( ! V_139 ) {
F_9 ( V_6 -> V_104 ) ;
F_9 ( V_6 -> V_102 ) ;
F_26 ( & V_3 -> V_77 ) ;
F_51 ( & V_3 -> V_126 ) ;
return - V_39 ;
}
memcpy ( V_139 ,
V_108 -> V_141 , V_108 -> V_137 * sizeof( * V_108 -> V_141 ) ) ;
F_10 ( L_19 ,
V_108 -> V_137 + ( V_113 << V_116 ) ) ;
V_6 -> V_128 = V_32 ;
V_6 -> V_116 = V_116 ;
V_118 = 0 ;
V_137 = 0 ;
while ( V_6 -> V_103 < V_113 ) {
V_37 = F_21 ( V_3 , V_30 << V_116 , 0x1000 ) ;
if ( ! V_37 ) {
V_6 -> V_103 = V_113 ;
V_6 -> V_101 = V_113 ;
F_45 ( V_3 , V_6 ) ;
F_9 ( V_139 ) ;
F_26 ( & V_3 -> V_77 ) ;
F_51 ( & V_3 -> V_126 ) ;
return - V_39 ;
}
V_6 -> V_102 [ V_6 -> V_101 ++ ] = V_37 ;
for ( V_93 = 0 ; V_93 < ( 1 << V_116 ) ; V_93 ++ ) {
F_10 ( L_20 ,
V_108 -> V_137 + V_137 ,
( unsigned long ) V_37 -> V_75 + V_30 * V_93 ) ;
V_139 [ V_108 -> V_137 + V_137 ++ ]
= ( unsigned long ) V_37 -> V_75 + V_30 * V_93 ;
}
for ( V_13 = 0 ;
V_13 + V_32 <= V_117 && V_6 -> V_103 < V_113 ;
V_13 += V_115 , ++ V_6 -> V_103 ) {
V_111 = & V_6 -> V_104 [ V_6 -> V_103 ] ;
V_111 -> V_92 = V_108 -> V_103 + V_6 -> V_103 ;
V_111 -> V_117 = V_115 ;
V_111 -> V_114 = V_114 ;
V_111 -> V_129 = 0 ;
V_111 -> V_13 = ( V_108 -> V_118 + V_118 + V_13 ) ;
V_111 -> V_131 = ( void * ) ( V_37 -> V_75 + V_13 ) ;
V_111 -> V_130 = V_37 -> V_76 + V_13 ;
V_111 -> V_132 = NULL ;
V_111 -> V_133 = 0 ;
V_111 -> V_134 = 0 ;
V_111 -> V_84 = NULL ;
V_111 -> V_135 = V_3 -> V_136 -> V_135 ;
V_111 -> V_105 = F_22 ( V_111 -> V_135 ,
V_38 ) ;
if ( ! V_111 -> V_105 ) {
V_6 -> V_103 = V_113 ;
V_6 -> V_101 = V_113 ;
F_45 ( V_3 , V_6 ) ;
F_9 ( V_139 ) ;
F_26 ( & V_3 -> V_77 ) ;
F_51 ( & V_3 -> V_126 ) ;
return - V_39 ;
}
F_10 ( L_14 ,
V_6 -> V_103 , V_111 -> V_131 ) ;
}
V_118 += V_30 << V_116 ;
}
V_119 = F_52 ( V_108 -> V_104 ,
( V_108 -> V_103 + V_6 -> V_103 ) *
sizeof( * V_108 -> V_104 ) , V_38 ) ;
if ( ! V_119 ) {
F_45 ( V_3 , V_6 ) ;
F_9 ( V_139 ) ;
F_26 ( & V_3 -> V_77 ) ;
F_51 ( & V_3 -> V_126 ) ;
return - V_39 ;
}
V_108 -> V_104 = V_119 ;
for ( V_93 = 0 ; V_93 < V_6 -> V_103 ; V_93 ++ ) {
V_108 -> V_104 [ V_93 + V_108 -> V_103 ] = & V_6 -> V_104 [ V_93 ] ;
}
if ( V_108 -> V_137 ) {
F_9 ( V_108 -> V_141 ) ;
}
V_108 -> V_141 = V_139 ;
V_108 -> V_103 += V_6 -> V_103 ;
V_108 -> V_101 += V_6 -> V_101 ;
V_108 -> V_137 += V_6 -> V_101 << V_116 ;
V_108 -> V_118 += V_30 * ( V_6 -> V_101 << V_116 ) ;
F_26 ( & V_3 -> V_77 ) ;
V_99 -> V_113 = V_6 -> V_103 ;
V_99 -> V_32 = V_32 ;
if ( V_99 -> V_9 & V_142 )
V_108 -> V_9 = V_143 ;
F_51 ( & V_3 -> V_126 ) ;
return 0 ;
}
static int F_54 ( struct V_2 * V_3 ,
struct V_106 * V_99 )
{
struct V_107 * V_108 = V_3 -> V_108 ;
struct V_100 * V_6 ;
struct V_110 * V_111 ;
unsigned long V_13 ;
unsigned long V_112 ;
int V_113 ;
int V_114 ;
int V_32 ;
int V_115 ;
int V_116 ;
int V_117 ;
int V_118 ;
int V_93 ;
struct V_110 * * V_119 ;
if ( ! F_30 ( V_3 , V_144 ) )
return - V_27 ;
if ( ! V_108 )
return - V_27 ;
if ( ! F_29 ( V_87 ) )
return - V_70 ;
V_113 = V_99 -> V_113 ;
V_114 = F_18 ( V_99 -> V_32 ) ;
V_32 = 1 << V_114 ;
V_115 = ( V_99 -> V_9 & V_120 )
? F_11 ( V_32 ) : V_32 ;
V_116 = V_114 - V_25 > 0 ? V_114 - V_25 : 0 ;
V_117 = V_30 << V_116 ;
V_118 = 0 ;
V_112 = V_99 -> V_121 ;
F_10 ( L_6 , V_113 ) ;
F_10 ( L_7 , V_114 ) ;
F_10 ( L_8 , V_32 ) ;
F_10 ( L_21 , V_112 ) ;
F_10 ( L_10 , V_115 ) ;
F_10 ( L_11 , V_116 ) ;
F_10 ( L_12 , V_117 ) ;
if ( V_114 < V_122 || V_114 > V_123 )
return - V_27 ;
F_48 ( & V_3 -> V_124 ) ;
if ( V_3 -> V_125 ) {
F_49 ( & V_3 -> V_124 ) ;
return - V_54 ;
}
F_50 ( & V_3 -> V_126 ) ;
F_49 ( & V_3 -> V_124 ) ;
F_24 ( & V_3 -> V_77 ) ;
V_6 = & V_108 -> V_127 [ V_114 ] ;
if ( V_6 -> V_103 ) {
F_26 ( & V_3 -> V_77 ) ;
F_51 ( & V_3 -> V_126 ) ;
return - V_39 ;
}
if ( V_113 < 0 || V_113 > 4096 ) {
F_26 ( & V_3 -> V_77 ) ;
F_51 ( & V_3 -> V_126 ) ;
return - V_27 ;
}
V_6 -> V_104 = F_22 ( V_113 * sizeof( * V_6 -> V_104 ) ,
V_38 ) ;
if ( ! V_6 -> V_104 ) {
F_26 ( & V_3 -> V_77 ) ;
F_51 ( & V_3 -> V_126 ) ;
return - V_39 ;
}
V_6 -> V_128 = V_32 ;
V_6 -> V_116 = V_116 ;
V_13 = 0 ;
while ( V_6 -> V_103 < V_113 ) {
V_111 = & V_6 -> V_104 [ V_6 -> V_103 ] ;
V_111 -> V_92 = V_108 -> V_103 + V_6 -> V_103 ;
V_111 -> V_117 = V_115 ;
V_111 -> V_114 = V_114 ;
V_111 -> V_129 = 0 ;
V_111 -> V_13 = ( V_108 -> V_118 + V_13 ) ;
V_111 -> V_130 = V_112 + V_13 ;
V_111 -> V_131 = ( void * ) ( V_112 + V_13
+ ( unsigned long ) V_3 -> V_72 -> V_73 ) ;
V_111 -> V_132 = NULL ;
V_111 -> V_133 = 0 ;
V_111 -> V_134 = 0 ;
V_111 -> V_84 = NULL ;
V_111 -> V_135 = V_3 -> V_136 -> V_135 ;
V_111 -> V_105 = F_22 ( V_111 -> V_135 , V_38 ) ;
if ( ! V_111 -> V_105 ) {
V_6 -> V_103 = V_113 ;
F_45 ( V_3 , V_6 ) ;
F_26 ( & V_3 -> V_77 ) ;
F_51 ( & V_3 -> V_126 ) ;
return - V_39 ;
}
F_10 ( L_14 , V_6 -> V_103 , V_111 -> V_131 ) ;
V_13 += V_115 ;
V_6 -> V_103 ++ ;
V_118 += V_30 << V_116 ;
}
F_10 ( L_15 , V_118 ) ;
V_119 = F_52 ( V_108 -> V_104 ,
( V_108 -> V_103 + V_6 -> V_103 ) *
sizeof( * V_108 -> V_104 ) , V_38 ) ;
if ( ! V_119 ) {
F_45 ( V_3 , V_6 ) ;
F_26 ( & V_3 -> V_77 ) ;
F_51 ( & V_3 -> V_126 ) ;
return - V_39 ;
}
V_108 -> V_104 = V_119 ;
for ( V_93 = 0 ; V_93 < V_6 -> V_103 ; V_93 ++ ) {
V_108 -> V_104 [ V_93 + V_108 -> V_103 ] = & V_6 -> V_104 [ V_93 ] ;
}
V_108 -> V_103 += V_6 -> V_103 ;
V_108 -> V_101 += V_6 -> V_101 ;
V_108 -> V_137 += V_118 >> V_25 ;
V_108 -> V_118 += V_118 ;
F_10 ( L_16 , V_108 -> V_103 ) ;
F_10 ( L_17 , V_6 -> V_103 ) ;
F_26 ( & V_3 -> V_77 ) ;
V_99 -> V_113 = V_6 -> V_103 ;
V_99 -> V_32 = V_32 ;
V_108 -> V_9 = V_145 ;
F_51 ( & V_3 -> V_126 ) ;
return 0 ;
}
int F_55 ( struct V_2 * V_3 , void * V_82 ,
struct V_83 * V_84 )
{
struct V_106 * V_99 = V_82 ;
int V_23 ;
if ( F_30 ( V_3 , V_89 ) )
return - V_27 ;
if ( ! F_30 ( V_3 , V_146 ) )
return - V_27 ;
#if F_56 ( V_147 )
if ( V_99 -> V_9 & V_148 )
V_23 = F_47 ( V_3 , V_99 ) ;
else
#endif
if ( V_99 -> V_9 & V_149 )
V_23 = F_54 ( V_3 , V_99 ) ;
else if ( V_99 -> V_9 & V_150 )
V_23 = - V_27 ;
else
V_23 = F_53 ( V_3 , V_99 ) ;
return V_23 ;
}
int F_57 ( struct V_2 * V_3 , void * V_82 ,
struct V_83 * V_84 )
{
struct V_107 * V_108 = V_3 -> V_108 ;
struct V_151 * V_99 = V_82 ;
int V_93 ;
int V_113 ;
if ( F_30 ( V_3 , V_89 ) )
return - V_27 ;
if ( ! F_30 ( V_3 , V_146 ) )
return - V_27 ;
if ( ! V_108 )
return - V_27 ;
F_48 ( & V_3 -> V_124 ) ;
if ( F_58 ( & V_3 -> V_126 ) ) {
F_49 ( & V_3 -> V_124 ) ;
return - V_54 ;
}
++ V_3 -> V_125 ;
F_49 ( & V_3 -> V_124 ) ;
for ( V_93 = 0 , V_113 = 0 ; V_93 < V_123 + 1 ; V_93 ++ ) {
if ( V_108 -> V_127 [ V_93 ] . V_103 )
++ V_113 ;
}
F_10 ( L_22 , V_113 ) ;
if ( V_99 -> V_113 >= V_113 ) {
for ( V_93 = 0 , V_113 = 0 ; V_93 < V_123 + 1 ; V_93 ++ ) {
if ( V_108 -> V_127 [ V_93 ] . V_103 ) {
struct V_106 T_3 * V_152 =
& V_99 -> V_36 [ V_113 ] ;
struct V_100 * V_153 = & V_108 -> V_127 [ V_93 ] ;
if ( F_59 ( & V_152 -> V_113 ,
& V_153 -> V_103 ,
sizeof( V_153 -> V_103 ) ) ||
F_59 ( & V_152 -> V_32 ,
& V_153 -> V_128 ,
sizeof( V_153 -> V_128 ) ) ||
F_59 ( & V_152 -> V_154 ,
& V_153 -> V_154 ,
sizeof( V_153 -> V_154 ) ) ||
F_59 ( & V_152 -> V_155 ,
& V_153 -> V_155 ,
sizeof( V_153 -> V_155 ) ) )
return - V_156 ;
F_10 ( L_23 ,
V_93 ,
V_108 -> V_127 [ V_93 ] . V_103 ,
V_108 -> V_127 [ V_93 ] . V_128 ,
V_108 -> V_127 [ V_93 ] . V_154 ,
V_108 -> V_127 [ V_93 ] . V_155 ) ;
++ V_113 ;
}
}
}
V_99 -> V_113 = V_113 ;
return 0 ;
}
int F_60 ( struct V_2 * V_3 , void * V_82 ,
struct V_83 * V_84 )
{
struct V_107 * V_108 = V_3 -> V_108 ;
struct V_106 * V_99 = V_82 ;
int V_114 ;
struct V_100 * V_6 ;
if ( F_30 ( V_3 , V_89 ) )
return - V_27 ;
if ( ! F_30 ( V_3 , V_146 ) )
return - V_27 ;
if ( ! V_108 )
return - V_27 ;
F_10 ( L_24 ,
V_99 -> V_32 , V_99 -> V_154 , V_99 -> V_155 ) ;
V_114 = F_18 ( V_99 -> V_32 ) ;
if ( V_114 < V_122 || V_114 > V_123 )
return - V_27 ;
V_6 = & V_108 -> V_127 [ V_114 ] ;
if ( V_99 -> V_154 < 0 || V_99 -> V_154 > V_6 -> V_103 )
return - V_27 ;
if ( V_99 -> V_155 < 0 || V_99 -> V_155 > V_6 -> V_103 )
return - V_27 ;
V_6 -> V_154 = V_99 -> V_154 ;
V_6 -> V_155 = V_99 -> V_155 ;
return 0 ;
}
int F_61 ( struct V_2 * V_3 , void * V_82 ,
struct V_83 * V_84 )
{
struct V_107 * V_108 = V_3 -> V_108 ;
struct V_157 * V_99 = V_82 ;
int V_93 ;
int V_92 ;
struct V_110 * V_111 ;
if ( F_30 ( V_3 , V_89 ) )
return - V_27 ;
if ( ! F_30 ( V_3 , V_146 ) )
return - V_27 ;
if ( ! V_108 )
return - V_27 ;
F_10 ( L_25 , V_99 -> V_113 ) ;
for ( V_93 = 0 ; V_93 < V_99 -> V_113 ; V_93 ++ ) {
if ( F_62 ( & V_92 , & V_99 -> V_36 [ V_93 ] , sizeof( V_92 ) ) )
return - V_156 ;
if ( V_92 < 0 || V_92 >= V_108 -> V_103 ) {
F_63 ( L_26 ,
V_92 , V_108 -> V_103 - 1 ) ;
return - V_27 ;
}
V_111 = V_108 -> V_104 [ V_92 ] ;
if ( V_111 -> V_84 != V_84 ) {
F_63 ( L_27 ,
F_64 ( V_158 ) ) ;
return - V_27 ;
}
F_65 ( V_3 , V_111 ) ;
}
return 0 ;
}
int F_66 ( struct V_2 * V_3 , void * V_82 ,
struct V_83 * V_84 )
{
struct V_107 * V_108 = V_3 -> V_108 ;
int V_159 = 0 ;
const int V_160 = 0 ;
unsigned long V_73 ;
unsigned long V_131 ;
struct V_161 * V_99 = V_82 ;
int V_93 ;
if ( F_30 ( V_3 , V_89 ) )
return - V_27 ;
if ( ! F_30 ( V_3 , V_146 ) )
return - V_27 ;
if ( ! V_108 )
return - V_27 ;
F_48 ( & V_3 -> V_124 ) ;
if ( F_58 ( & V_3 -> V_126 ) ) {
F_49 ( & V_3 -> V_124 ) ;
return - V_54 ;
}
V_3 -> V_125 ++ ;
F_49 ( & V_3 -> V_124 ) ;
if ( V_99 -> V_113 >= V_108 -> V_103 ) {
if ( ( V_3 -> V_59 && ( V_108 -> V_9 & V_138 ) )
|| ( F_30 ( V_3 , V_144 )
&& ( V_108 -> V_9 & V_145 ) ) ) {
struct V_4 * V_5 = V_3 -> V_162 ;
unsigned long V_163 = V_3 -> V_164 ;
if ( ! V_5 ) {
V_159 = - V_27 ;
goto V_165;
}
V_73 = F_67 ( V_84 -> V_166 , 0 , V_5 -> V_32 ,
V_167 | V_168 ,
V_169 ,
V_163 ) ;
} else {
V_73 = F_67 ( V_84 -> V_166 , 0 , V_108 -> V_118 ,
V_167 | V_168 ,
V_169 , 0 ) ;
}
if ( V_73 > - 1024UL ) {
V_159 = ( signed long ) V_73 ;
goto V_165;
}
V_99 -> V_73 = ( void T_3 * ) V_73 ;
for ( V_93 = 0 ; V_93 < V_108 -> V_103 ; V_93 ++ ) {
if ( F_59 ( & V_99 -> V_36 [ V_93 ] . V_92 ,
& V_108 -> V_104 [ V_93 ] -> V_92 ,
sizeof( V_99 -> V_36 [ 0 ] . V_92 ) ) ) {
V_159 = - V_156 ;
goto V_165;
}
if ( F_59 ( & V_99 -> V_36 [ V_93 ] . V_117 ,
& V_108 -> V_104 [ V_93 ] -> V_117 ,
sizeof( V_99 -> V_36 [ 0 ] . V_117 ) ) ) {
V_159 = - V_156 ;
goto V_165;
}
if ( F_59 ( & V_99 -> V_36 [ V_93 ] . V_129 ,
& V_160 , sizeof( V_160 ) ) ) {
V_159 = - V_156 ;
goto V_165;
}
V_131 = V_73 + V_108 -> V_104 [ V_93 ] -> V_13 ;
if ( F_59 ( & V_99 -> V_36 [ V_93 ] . V_131 ,
& V_131 , sizeof( V_131 ) ) ) {
V_159 = - V_156 ;
goto V_165;
}
}
}
V_165:
V_99 -> V_113 = V_108 -> V_103 ;
F_10 ( L_28 , V_99 -> V_113 , V_159 ) ;
return V_159 ;
}
int F_68 ( struct V_2 * V_3 , void * V_82 ,
struct V_83 * V_84 )
{
if ( F_30 ( V_3 , V_89 ) )
return - V_27 ;
if ( V_3 -> V_136 -> V_170 )
return V_3 -> V_136 -> V_170 ( V_3 , V_82 , V_84 ) ;
else
return - V_27 ;
}
struct V_4 * F_69 ( struct V_2 * V_3 )
{
struct V_1 * V_6 ;
F_2 (entry, &dev->maplist, head) {
if ( V_6 -> V_5 && V_6 -> V_5 -> type == V_8 &&
( V_6 -> V_5 -> V_9 & V_10 ) ) {
return V_6 -> V_5 ;
}
}
return NULL ;
}
