static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_6 ;
F_2 (entry, &dev->maplist, head) {
if ( ! V_6 -> V_5 ||
V_5 -> type != V_6 -> V_5 -> type ||
V_6 -> V_7 != V_3 -> V_8 -> V_7 )
continue;
switch ( V_5 -> type ) {
case V_9 :
if ( V_5 -> V_10 != V_11 )
break;
return V_6 ;
case V_12 :
case V_13 :
if ( ( V_6 -> V_5 -> V_14 & 0xffffffff ) ==
( V_5 -> V_14 & 0xffffffff ) )
return V_6 ;
default:
;
}
if ( V_6 -> V_5 -> V_14 == V_5 -> V_14 )
return V_6 ;
}
return NULL ;
}
static int F_3 ( struct V_2 * V_3 , struct V_15 * V_16 ,
unsigned long V_17 , int V_18 , int V_19 )
{
int V_20 , V_21 ;
unsigned long V_22 ;
#if ( V_23 == 64 )
V_20 = ( ( V_17 & 0xFFFFFFFF00000000UL ) || V_18 ) ;
#elif ( V_23 == 32 )
V_20 = V_18 ;
#else
#error Unsupported long size. Neither 64 nor 32 bits.
#endif
if ( ! V_20 ) {
int V_24 ;
V_16 -> V_25 = V_17 >> V_26 ;
V_24 = F_4 ( & V_3 -> V_27 , V_16 ) ;
if ( V_24 != - V_28 )
return V_24 ;
}
V_21 = 0 ;
V_22 = V_29 >> V_26 ;
if ( V_19 && ( V_30 > V_31 ) ) {
int V_32 = F_5 ( V_30 >> V_26 ) + 1 ;
V_21 = V_32 ;
V_22 |= ( ( V_17 >> V_26 ) & ( ( 1UL << V_32 ) - 1UL ) ) ;
}
return F_6 ( & V_3 -> V_27 , V_16 ,
V_17 , 32 - V_26 - 3 ,
V_21 , V_22 ) ;
}
static int F_7 ( struct V_2 * V_3 , T_1 V_14 ,
unsigned int V_33 , enum V_34 type ,
enum V_35 V_10 ,
struct V_1 * * V_36 )
{
struct V_4 * V_5 ;
struct V_1 * V_37 ;
T_2 * V_38 ;
unsigned long V_17 ;
int V_24 ;
V_5 = F_8 ( sizeof( * V_5 ) , V_39 ) ;
if ( ! V_5 )
return - V_40 ;
V_5 -> V_14 = V_14 ;
V_5 -> V_33 = V_33 ;
V_5 -> V_10 = V_10 ;
V_5 -> type = type ;
if ( ( V_5 -> V_10 & V_41 ) && V_5 -> type != V_9 ) {
F_9 ( V_5 ) ;
return - V_28 ;
}
F_10 ( L_1 ,
( unsigned long long ) V_5 -> V_14 , V_5 -> V_33 , V_5 -> type ) ;
if ( V_5 -> type == V_9 )
V_5 -> V_33 = F_11 ( V_5 -> V_33 ) ;
if ( ( V_5 -> V_14 & ( ~ ( T_1 ) V_42 ) ) || ( V_5 -> V_33 & ( ~ V_42 ) ) ) {
F_9 ( V_5 ) ;
return - V_28 ;
}
V_5 -> V_43 = - 1 ;
V_5 -> V_44 = NULL ;
switch ( V_5 -> type ) {
case V_12 :
case V_13 :
#if ! F_12 ( V_45 ) && ! F_12 ( V_46 ) && ! F_12 ( V_47 ) && ! F_12 ( V_48 ) && ! F_12 ( V_49 ) && ! F_12 ( V_50 )
if ( V_5 -> V_14 + ( V_5 -> V_33 - 1 ) < V_5 -> V_14 ||
V_5 -> V_14 < F_13 ( V_51 ) ) {
F_9 ( V_5 ) ;
return - V_28 ;
}
#endif
V_37 = F_1 ( V_3 , V_5 ) ;
if ( V_37 != NULL ) {
if ( V_37 -> V_5 -> V_33 != V_5 -> V_33 ) {
F_10 ( L_2
L_3 ,
V_5 -> type , V_5 -> V_33 ,
V_37 -> V_5 -> V_33 ) ;
V_37 -> V_5 -> V_33 = V_5 -> V_33 ;
}
F_9 ( V_5 ) ;
* V_36 = V_37 ;
return 0 ;
}
if ( V_5 -> type == V_13 ||
( V_5 -> V_10 & V_52 ) ) {
V_5 -> V_43 =
F_14 ( V_5 -> V_14 , V_5 -> V_33 ) ;
}
if ( V_5 -> type == V_12 ) {
if ( V_5 -> V_10 & V_52 )
V_5 -> V_44 = F_15 ( V_5 -> V_14 ,
V_5 -> V_33 ) ;
else
V_5 -> V_44 = F_16 ( V_5 -> V_14 , V_5 -> V_33 ) ;
if ( ! V_5 -> V_44 ) {
F_9 ( V_5 ) ;
return - V_40 ;
}
}
break;
case V_9 :
V_37 = F_1 ( V_3 , V_5 ) ;
if ( V_37 != NULL ) {
if( V_37 -> V_5 -> V_33 != V_5 -> V_33 ) {
F_10 ( L_2
L_3 ,
V_5 -> type , V_5 -> V_33 , V_37 -> V_5 -> V_33 ) ;
V_37 -> V_5 -> V_33 = V_5 -> V_33 ;
}
F_9 ( V_5 ) ;
* V_36 = V_37 ;
return 0 ;
}
V_5 -> V_44 = F_17 ( V_5 -> V_33 ) ;
F_10 ( L_4 ,
V_5 -> V_33 , F_18 ( V_5 -> V_33 ) , V_5 -> V_44 ) ;
if ( ! V_5 -> V_44 ) {
F_9 ( V_5 ) ;
return - V_40 ;
}
V_5 -> V_14 = ( unsigned long ) V_5 -> V_44 ;
if ( V_5 -> V_10 & V_11 ) {
if ( V_3 -> V_8 -> V_7 -> V_53 . V_54 != NULL ) {
F_19 ( V_5 -> V_44 ) ;
F_9 ( V_5 ) ;
return - V_55 ;
}
V_3 -> V_56 . V_53 = V_3 -> V_8 -> V_7 -> V_53 . V_54 = V_5 -> V_44 ;
}
break;
case V_57 : {
struct V_58 * V_6 ;
int V_59 = 0 ;
if ( ! V_3 -> V_60 ) {
F_9 ( V_5 ) ;
return - V_28 ;
}
#ifdef V_46
V_5 -> V_14 += V_3 -> V_61 -> V_62 -> V_63 ;
#endif
if ( V_5 -> V_14 < V_3 -> V_60 -> V_64 ||
V_5 -> V_14 > V_3 -> V_60 -> V_64 +
V_3 -> V_60 -> V_65 . V_66 * 1024 * 1024 - 1 ) {
V_5 -> V_14 += V_3 -> V_60 -> V_64 ;
}
V_5 -> V_43 = V_3 -> V_60 -> V_67 ;
F_2 (entry, &dev->agp->memory, head) {
if ( ( V_5 -> V_14 >= V_6 -> V_68 ) &&
( V_5 -> V_14 + V_5 -> V_33 <= V_6 -> V_68 + V_6 -> V_69 * V_31 ) ) {
V_59 = 1 ;
break;
}
}
if ( ! F_20 ( & V_3 -> V_60 -> V_70 ) && ! V_59 ) {
F_9 ( V_5 ) ;
return - V_71 ;
}
F_10 ( L_5 ,
( unsigned long long ) V_5 -> V_14 , V_5 -> V_33 ) ;
break;
}
case V_72 :
if ( ! V_3 -> V_73 ) {
F_9 ( V_5 ) ;
return - V_28 ;
}
V_5 -> V_14 += ( unsigned long ) V_3 -> V_73 -> V_74 ;
break;
case V_75 :
V_38 = F_21 ( V_3 , V_5 -> V_33 , V_5 -> V_33 ) ;
if ( ! V_38 ) {
F_9 ( V_5 ) ;
return - V_40 ;
}
V_5 -> V_44 = V_38 -> V_76 ;
V_5 -> V_14 = ( unsigned long ) V_38 -> V_77 ;
F_9 ( V_38 ) ;
break;
default:
F_9 ( V_5 ) ;
return - V_28 ;
}
V_37 = F_22 ( sizeof( * V_37 ) , V_39 ) ;
if ( ! V_37 ) {
if ( V_5 -> type == V_12 )
F_23 ( V_5 -> V_44 ) ;
F_9 ( V_5 ) ;
return - V_28 ;
}
V_37 -> V_5 = V_5 ;
F_24 ( & V_3 -> V_78 ) ;
F_25 ( & V_37 -> V_79 , & V_3 -> V_36 ) ;
V_17 = ( V_5 -> type == V_9 ) ? ( unsigned long ) V_5 -> V_44 :
V_5 -> V_14 ;
V_24 = F_3 ( V_3 , & V_37 -> V_16 , V_17 , 0 ,
( V_5 -> type == V_9 ) ) ;
if ( V_24 ) {
if ( V_5 -> type == V_12 )
F_23 ( V_5 -> V_44 ) ;
F_9 ( V_5 ) ;
F_9 ( V_37 ) ;
F_26 ( & V_3 -> V_78 ) ;
return V_24 ;
}
V_37 -> V_17 = V_37 -> V_16 . V_25 << V_26 ;
F_26 ( & V_3 -> V_78 ) ;
if ( ! ( V_5 -> V_10 & V_80 ) )
V_37 -> V_7 = V_3 -> V_8 -> V_7 ;
* V_36 = V_37 ;
return 0 ;
}
int F_27 ( struct V_2 * V_3 , T_1 V_14 ,
unsigned int V_33 , enum V_34 type ,
enum V_35 V_10 , struct V_4 * * V_81 )
{
struct V_1 * V_37 ;
int V_82 ;
V_82 = F_7 ( V_3 , V_14 , V_33 , type , V_10 , & V_37 ) ;
if ( ! V_82 )
* V_81 = V_37 -> V_5 ;
return V_82 ;
}
int F_28 ( struct V_2 * V_3 , void * V_83 ,
struct V_84 * V_85 )
{
struct V_86 * V_5 = V_83 ;
struct V_1 * V_36 ;
int V_87 ;
if ( ! ( F_29 ( V_88 ) || V_5 -> type == V_57 || V_5 -> type == V_9 ) )
return - V_71 ;
if ( ! F_30 ( V_3 , V_89 ) &&
F_30 ( V_3 , V_90 ) )
return - V_28 ;
V_87 = F_7 ( V_3 , V_5 -> V_14 , V_5 -> V_33 , V_5 -> type ,
V_5 -> V_10 , & V_36 ) ;
if ( V_87 )
return V_87 ;
V_5 -> V_44 = ( void * ) ( unsigned long ) V_36 -> V_17 ;
V_5 -> V_43 = - 1 ;
return 0 ;
}
int F_31 ( struct V_2 * V_3 , void * V_83 ,
struct V_84 * V_85 )
{
struct V_86 * V_5 = V_83 ;
struct V_1 * V_91 = NULL ;
struct V_92 * V_37 ;
int V_93 ;
int V_94 ;
if ( ! F_30 ( V_3 , V_89 ) &&
F_30 ( V_3 , V_90 ) )
return - V_28 ;
V_93 = V_5 -> V_14 ;
if ( V_93 < 0 )
return - V_28 ;
V_94 = 0 ;
F_24 ( & V_3 -> V_78 ) ;
F_32 (list, &dev->maplist) {
if ( V_94 == V_93 ) {
V_91 = F_33 ( V_37 , struct V_1 , V_79 ) ;
break;
}
V_94 ++ ;
}
if ( ! V_91 || ! V_91 -> V_5 ) {
F_26 ( & V_3 -> V_78 ) ;
return - V_28 ;
}
V_5 -> V_14 = V_91 -> V_5 -> V_14 ;
V_5 -> V_33 = V_91 -> V_5 -> V_33 ;
V_5 -> type = V_91 -> V_5 -> type ;
V_5 -> V_10 = V_91 -> V_5 -> V_10 ;
V_5 -> V_44 = ( void * ) ( unsigned long ) V_91 -> V_17 ;
V_5 -> V_43 = F_34 ( V_91 -> V_5 -> V_43 ) ;
F_26 ( & V_3 -> V_78 ) ;
return 0 ;
}
int F_35 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_91 = NULL , * V_95 ;
T_2 V_38 ;
int V_96 = 0 ;
struct V_97 * V_7 ;
F_36 (r_list, list_t, &dev->maplist, head) {
if ( V_91 -> V_5 == V_5 ) {
V_7 = V_91 -> V_7 ;
F_37 ( & V_91 -> V_79 ) ;
F_38 ( & V_3 -> V_27 ,
V_91 -> V_17 >> V_26 ) ;
F_9 ( V_91 ) ;
V_96 = 1 ;
break;
}
}
if ( ! V_96 )
return - V_28 ;
switch ( V_5 -> type ) {
case V_12 :
F_23 ( V_5 -> V_44 ) ;
case V_13 :
F_39 ( V_5 -> V_43 ) ;
break;
case V_9 :
F_19 ( V_5 -> V_44 ) ;
if ( V_7 ) {
if ( V_3 -> V_56 . V_53 == V_7 -> V_53 . V_54 )
V_3 -> V_56 . V_53 = NULL ;
V_7 -> V_53 . V_54 = NULL ;
V_7 -> V_53 . V_85 = NULL ;
F_40 ( & V_7 -> V_53 . V_98 ) ;
}
break;
case V_57 :
case V_72 :
break;
case V_75 :
V_38 . V_76 = V_5 -> V_44 ;
V_38 . V_77 = V_5 -> V_14 ;
V_38 . V_33 = V_5 -> V_33 ;
F_41 ( V_3 , & V_38 ) ;
break;
}
F_9 ( V_5 ) ;
return 0 ;
}
void F_42 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
if ( ! F_30 ( V_3 , V_89 ) &&
F_30 ( V_3 , V_90 ) )
return;
F_24 ( & V_3 -> V_78 ) ;
F_35 ( V_3 , V_5 ) ;
F_26 ( & V_3 -> V_78 ) ;
}
void F_43 ( struct V_2 * V_3 , struct V_97 * V_7 )
{
struct V_1 * V_91 , * V_99 ;
if ( F_30 ( V_3 , V_90 ) )
return;
F_24 ( & V_3 -> V_78 ) ;
F_36 (r_list, list_temp, &dev->maplist, head) {
if ( V_91 -> V_7 == V_7 ) {
F_35 ( V_3 , V_91 -> V_5 ) ;
V_91 = NULL ;
}
}
F_26 ( & V_3 -> V_78 ) ;
}
int F_44 ( struct V_2 * V_3 , void * V_83 ,
struct V_84 * V_85 )
{
struct V_86 * V_100 = V_83 ;
struct V_4 * V_5 = NULL ;
struct V_1 * V_91 ;
int V_24 ;
if ( ! F_30 ( V_3 , V_89 ) &&
F_30 ( V_3 , V_90 ) )
return - V_28 ;
F_24 ( & V_3 -> V_78 ) ;
F_2 (r_list, &dev->maplist, head) {
if ( V_91 -> V_5 &&
V_91 -> V_17 == ( unsigned long ) V_100 -> V_44 &&
V_91 -> V_5 -> V_10 & V_41 ) {
V_5 = V_91 -> V_5 ;
break;
}
}
if ( F_20 ( & V_3 -> V_36 ) || ! V_5 ) {
F_26 ( & V_3 -> V_78 ) ;
return - V_28 ;
}
if ( ( V_5 -> type == V_12 ) || ( V_5 -> type == V_13 ) ) {
F_26 ( & V_3 -> V_78 ) ;
return 0 ;
}
V_24 = F_35 ( V_3 , V_5 ) ;
F_26 ( & V_3 -> V_78 ) ;
return V_24 ;
}
static void F_45 ( struct V_2 * V_3 ,
struct V_101 * V_6 )
{
int V_94 ;
if ( V_6 -> V_102 ) {
for ( V_94 = 0 ; V_94 < V_6 -> V_102 ; V_94 ++ ) {
if ( V_6 -> V_103 [ V_94 ] ) {
F_46 ( V_3 , V_6 -> V_103 [ V_94 ] ) ;
}
}
F_9 ( V_6 -> V_103 ) ;
V_6 -> V_102 = 0 ;
}
if ( V_6 -> V_104 ) {
for ( V_94 = 0 ; V_94 < V_6 -> V_104 ; V_94 ++ ) {
F_9 ( V_6 -> V_105 [ V_94 ] . V_106 ) ;
}
F_9 ( V_6 -> V_105 ) ;
V_6 -> V_104 = 0 ;
}
}
int F_47 ( struct V_2 * V_3 ,
struct V_107 * V_100 )
{
struct V_108 * V_109 = V_3 -> V_109 ;
struct V_101 * V_6 ;
struct V_58 * V_110 ;
struct V_111 * V_112 ;
unsigned long V_14 ;
unsigned long V_113 ;
int V_114 ;
int V_115 ;
int V_33 ;
int V_116 ;
int V_117 ;
int V_118 ;
int V_119 ;
int V_94 , V_59 ;
struct V_111 * * V_120 ;
if ( ! V_109 )
return - V_28 ;
V_114 = V_100 -> V_114 ;
V_115 = F_18 ( V_100 -> V_33 ) ;
V_33 = 1 << V_115 ;
V_116 = ( V_100 -> V_10 & V_121 )
? F_11 ( V_33 ) : V_33 ;
V_117 = V_115 - V_26 > 0 ? V_115 - V_26 : 0 ;
V_118 = V_31 << V_117 ;
V_119 = 0 ;
V_113 = V_3 -> V_60 -> V_64 + V_100 -> V_122 ;
F_10 ( L_6 , V_114 ) ;
F_10 ( L_7 , V_115 ) ;
F_10 ( L_8 , V_33 ) ;
F_10 ( L_9 , V_113 ) ;
F_10 ( L_10 , V_116 ) ;
F_10 ( L_11 , V_117 ) ;
F_10 ( L_12 , V_118 ) ;
if ( V_115 < V_123 || V_115 > V_124 )
return - V_28 ;
V_59 = 0 ;
F_2 (agp_entry, &dev->agp->memory, head) {
if ( ( V_113 >= V_110 -> V_68 ) &&
( V_113 + V_118 * V_114 <= V_110 -> V_68 + V_110 -> V_69 * V_31 ) ) {
V_59 = 1 ;
break;
}
}
if ( ! F_20 ( & V_3 -> V_60 -> V_70 ) && ! V_59 ) {
F_10 ( L_13 ) ;
return - V_28 ;
}
F_48 ( & V_3 -> V_125 ) ;
if ( V_3 -> V_126 ) {
F_49 ( & V_3 -> V_125 ) ;
return - V_55 ;
}
F_50 ( & V_3 -> V_127 ) ;
F_49 ( & V_3 -> V_125 ) ;
F_24 ( & V_3 -> V_78 ) ;
V_6 = & V_109 -> V_128 [ V_115 ] ;
if ( V_6 -> V_104 ) {
F_26 ( & V_3 -> V_78 ) ;
F_51 ( & V_3 -> V_127 ) ;
return - V_40 ;
}
if ( V_114 < 0 || V_114 > 4096 ) {
F_26 ( & V_3 -> V_78 ) ;
F_51 ( & V_3 -> V_127 ) ;
return - V_28 ;
}
V_6 -> V_105 = F_22 ( V_114 * sizeof( * V_6 -> V_105 ) , V_39 ) ;
if ( ! V_6 -> V_105 ) {
F_26 ( & V_3 -> V_78 ) ;
F_51 ( & V_3 -> V_127 ) ;
return - V_40 ;
}
V_6 -> V_129 = V_33 ;
V_6 -> V_117 = V_117 ;
V_14 = 0 ;
while ( V_6 -> V_104 < V_114 ) {
V_112 = & V_6 -> V_105 [ V_6 -> V_104 ] ;
V_112 -> V_93 = V_109 -> V_104 + V_6 -> V_104 ;
V_112 -> V_118 = V_116 ;
V_112 -> V_115 = V_115 ;
V_112 -> V_130 = 0 ;
V_112 -> V_14 = ( V_109 -> V_119 + V_14 ) ;
V_112 -> V_131 = V_113 + V_14 ;
V_112 -> V_132 = ( void * ) ( V_113 + V_14 ) ;
V_112 -> V_133 = NULL ;
V_112 -> V_134 = 0 ;
V_112 -> V_135 = 0 ;
V_112 -> V_85 = NULL ;
V_112 -> V_136 = V_3 -> V_137 -> V_136 ;
V_112 -> V_106 = F_22 ( V_112 -> V_136 , V_39 ) ;
if ( ! V_112 -> V_106 ) {
V_6 -> V_104 = V_114 ;
F_45 ( V_3 , V_6 ) ;
F_26 ( & V_3 -> V_78 ) ;
F_51 ( & V_3 -> V_127 ) ;
return - V_40 ;
}
F_10 ( L_14 , V_6 -> V_104 , V_112 -> V_132 ) ;
V_14 += V_116 ;
V_6 -> V_104 ++ ;
V_119 += V_31 << V_117 ;
}
F_10 ( L_15 , V_119 ) ;
V_120 = F_52 ( V_109 -> V_105 ,
( V_109 -> V_104 + V_6 -> V_104 ) *
sizeof( * V_109 -> V_105 ) , V_39 ) ;
if ( ! V_120 ) {
F_45 ( V_3 , V_6 ) ;
F_26 ( & V_3 -> V_78 ) ;
F_51 ( & V_3 -> V_127 ) ;
return - V_40 ;
}
V_109 -> V_105 = V_120 ;
for ( V_94 = 0 ; V_94 < V_6 -> V_104 ; V_94 ++ ) {
V_109 -> V_105 [ V_94 + V_109 -> V_104 ] = & V_6 -> V_105 [ V_94 ] ;
}
V_109 -> V_104 += V_6 -> V_104 ;
V_109 -> V_102 += V_6 -> V_102 ;
V_109 -> V_138 += V_119 >> V_26 ;
V_109 -> V_119 += V_119 ;
F_10 ( L_16 , V_109 -> V_104 ) ;
F_10 ( L_17 , V_6 -> V_104 ) ;
F_26 ( & V_3 -> V_78 ) ;
V_100 -> V_114 = V_6 -> V_104 ;
V_100 -> V_33 = V_33 ;
V_109 -> V_10 = V_139 ;
F_51 ( & V_3 -> V_127 ) ;
return 0 ;
}
int F_53 ( struct V_2 * V_3 ,
struct V_107 * V_100 )
{
struct V_108 * V_109 = V_3 -> V_109 ;
int V_114 ;
int V_115 ;
int V_33 ;
int V_118 ;
int V_117 ;
struct V_101 * V_6 ;
T_2 * V_38 ;
struct V_111 * V_112 ;
int V_116 ;
unsigned long V_14 ;
int V_94 ;
int V_119 ;
int V_138 ;
unsigned long * V_140 ;
struct V_111 * * V_120 ;
if ( ! F_30 ( V_3 , V_141 ) )
return - V_28 ;
if ( ! V_109 )
return - V_28 ;
if ( ! F_29 ( V_88 ) )
return - V_71 ;
V_114 = V_100 -> V_114 ;
V_115 = F_18 ( V_100 -> V_33 ) ;
V_33 = 1 << V_115 ;
F_10 ( L_18 ,
V_100 -> V_114 , V_100 -> V_33 , V_33 , V_115 ) ;
if ( V_115 < V_123 || V_115 > V_124 )
return - V_28 ;
V_116 = ( V_100 -> V_10 & V_121 )
? F_11 ( V_33 ) : V_33 ;
V_117 = V_115 - V_26 > 0 ? V_115 - V_26 : 0 ;
V_118 = V_31 << V_117 ;
F_48 ( & V_3 -> V_125 ) ;
if ( V_3 -> V_126 ) {
F_49 ( & V_3 -> V_125 ) ;
return - V_55 ;
}
F_50 ( & V_3 -> V_127 ) ;
F_49 ( & V_3 -> V_125 ) ;
F_24 ( & V_3 -> V_78 ) ;
V_6 = & V_109 -> V_128 [ V_115 ] ;
if ( V_6 -> V_104 ) {
F_26 ( & V_3 -> V_78 ) ;
F_51 ( & V_3 -> V_127 ) ;
return - V_40 ;
}
if ( V_114 < 0 || V_114 > 4096 ) {
F_26 ( & V_3 -> V_78 ) ;
F_51 ( & V_3 -> V_127 ) ;
return - V_28 ;
}
V_6 -> V_105 = F_22 ( V_114 * sizeof( * V_6 -> V_105 ) , V_39 ) ;
if ( ! V_6 -> V_105 ) {
F_26 ( & V_3 -> V_78 ) ;
F_51 ( & V_3 -> V_127 ) ;
return - V_40 ;
}
V_6 -> V_103 = F_22 ( V_114 * sizeof( * V_6 -> V_103 ) , V_39 ) ;
if ( ! V_6 -> V_103 ) {
F_9 ( V_6 -> V_105 ) ;
F_26 ( & V_3 -> V_78 ) ;
F_51 ( & V_3 -> V_127 ) ;
return - V_40 ;
}
V_140 = F_8 ( ( V_109 -> V_138 + ( V_114 << V_117 ) ) *
sizeof( * V_109 -> V_142 ) , V_39 ) ;
if ( ! V_140 ) {
F_9 ( V_6 -> V_105 ) ;
F_9 ( V_6 -> V_103 ) ;
F_26 ( & V_3 -> V_78 ) ;
F_51 ( & V_3 -> V_127 ) ;
return - V_40 ;
}
memcpy ( V_140 ,
V_109 -> V_142 , V_109 -> V_138 * sizeof( * V_109 -> V_142 ) ) ;
F_10 ( L_19 ,
V_109 -> V_138 + ( V_114 << V_117 ) ) ;
V_6 -> V_129 = V_33 ;
V_6 -> V_117 = V_117 ;
V_119 = 0 ;
V_138 = 0 ;
while ( V_6 -> V_104 < V_114 ) {
V_38 = F_21 ( V_3 , V_31 << V_117 , 0x1000 ) ;
if ( ! V_38 ) {
V_6 -> V_104 = V_114 ;
V_6 -> V_102 = V_114 ;
F_45 ( V_3 , V_6 ) ;
F_9 ( V_140 ) ;
F_26 ( & V_3 -> V_78 ) ;
F_51 ( & V_3 -> V_127 ) ;
return - V_40 ;
}
V_6 -> V_103 [ V_6 -> V_102 ++ ] = V_38 ;
for ( V_94 = 0 ; V_94 < ( 1 << V_117 ) ; V_94 ++ ) {
F_10 ( L_20 ,
V_109 -> V_138 + V_138 ,
( unsigned long ) V_38 -> V_76 + V_31 * V_94 ) ;
V_140 [ V_109 -> V_138 + V_138 ++ ]
= ( unsigned long ) V_38 -> V_76 + V_31 * V_94 ;
}
for ( V_14 = 0 ;
V_14 + V_33 <= V_118 && V_6 -> V_104 < V_114 ;
V_14 += V_116 , ++ V_6 -> V_104 ) {
V_112 = & V_6 -> V_105 [ V_6 -> V_104 ] ;
V_112 -> V_93 = V_109 -> V_104 + V_6 -> V_104 ;
V_112 -> V_118 = V_116 ;
V_112 -> V_115 = V_115 ;
V_112 -> V_130 = 0 ;
V_112 -> V_14 = ( V_109 -> V_119 + V_119 + V_14 ) ;
V_112 -> V_132 = ( void * ) ( V_38 -> V_76 + V_14 ) ;
V_112 -> V_131 = V_38 -> V_77 + V_14 ;
V_112 -> V_133 = NULL ;
V_112 -> V_134 = 0 ;
V_112 -> V_135 = 0 ;
V_112 -> V_85 = NULL ;
V_112 -> V_136 = V_3 -> V_137 -> V_136 ;
V_112 -> V_106 = F_22 ( V_112 -> V_136 ,
V_39 ) ;
if ( ! V_112 -> V_106 ) {
V_6 -> V_104 = V_114 ;
V_6 -> V_102 = V_114 ;
F_45 ( V_3 , V_6 ) ;
F_9 ( V_140 ) ;
F_26 ( & V_3 -> V_78 ) ;
F_51 ( & V_3 -> V_127 ) ;
return - V_40 ;
}
F_10 ( L_14 ,
V_6 -> V_104 , V_112 -> V_132 ) ;
}
V_119 += V_31 << V_117 ;
}
V_120 = F_52 ( V_109 -> V_105 ,
( V_109 -> V_104 + V_6 -> V_104 ) *
sizeof( * V_109 -> V_105 ) , V_39 ) ;
if ( ! V_120 ) {
F_45 ( V_3 , V_6 ) ;
F_9 ( V_140 ) ;
F_26 ( & V_3 -> V_78 ) ;
F_51 ( & V_3 -> V_127 ) ;
return - V_40 ;
}
V_109 -> V_105 = V_120 ;
for ( V_94 = 0 ; V_94 < V_6 -> V_104 ; V_94 ++ ) {
V_109 -> V_105 [ V_94 + V_109 -> V_104 ] = & V_6 -> V_105 [ V_94 ] ;
}
if ( V_109 -> V_138 ) {
F_9 ( V_109 -> V_142 ) ;
}
V_109 -> V_142 = V_140 ;
V_109 -> V_104 += V_6 -> V_104 ;
V_109 -> V_102 += V_6 -> V_102 ;
V_109 -> V_138 += V_6 -> V_102 << V_117 ;
V_109 -> V_119 += V_31 * ( V_6 -> V_102 << V_117 ) ;
F_26 ( & V_3 -> V_78 ) ;
V_100 -> V_114 = V_6 -> V_104 ;
V_100 -> V_33 = V_33 ;
if ( V_100 -> V_10 & V_143 )
V_109 -> V_10 = V_144 ;
F_51 ( & V_3 -> V_127 ) ;
return 0 ;
}
static int F_54 ( struct V_2 * V_3 ,
struct V_107 * V_100 )
{
struct V_108 * V_109 = V_3 -> V_109 ;
struct V_101 * V_6 ;
struct V_111 * V_112 ;
unsigned long V_14 ;
unsigned long V_113 ;
int V_114 ;
int V_115 ;
int V_33 ;
int V_116 ;
int V_117 ;
int V_118 ;
int V_119 ;
int V_94 ;
struct V_111 * * V_120 ;
if ( ! F_30 ( V_3 , V_145 ) )
return - V_28 ;
if ( ! V_109 )
return - V_28 ;
if ( ! F_29 ( V_88 ) )
return - V_71 ;
V_114 = V_100 -> V_114 ;
V_115 = F_18 ( V_100 -> V_33 ) ;
V_33 = 1 << V_115 ;
V_116 = ( V_100 -> V_10 & V_121 )
? F_11 ( V_33 ) : V_33 ;
V_117 = V_115 - V_26 > 0 ? V_115 - V_26 : 0 ;
V_118 = V_31 << V_117 ;
V_119 = 0 ;
V_113 = V_100 -> V_122 ;
F_10 ( L_6 , V_114 ) ;
F_10 ( L_7 , V_115 ) ;
F_10 ( L_8 , V_33 ) ;
F_10 ( L_21 , V_113 ) ;
F_10 ( L_10 , V_116 ) ;
F_10 ( L_11 , V_117 ) ;
F_10 ( L_12 , V_118 ) ;
if ( V_115 < V_123 || V_115 > V_124 )
return - V_28 ;
F_48 ( & V_3 -> V_125 ) ;
if ( V_3 -> V_126 ) {
F_49 ( & V_3 -> V_125 ) ;
return - V_55 ;
}
F_50 ( & V_3 -> V_127 ) ;
F_49 ( & V_3 -> V_125 ) ;
F_24 ( & V_3 -> V_78 ) ;
V_6 = & V_109 -> V_128 [ V_115 ] ;
if ( V_6 -> V_104 ) {
F_26 ( & V_3 -> V_78 ) ;
F_51 ( & V_3 -> V_127 ) ;
return - V_40 ;
}
if ( V_114 < 0 || V_114 > 4096 ) {
F_26 ( & V_3 -> V_78 ) ;
F_51 ( & V_3 -> V_127 ) ;
return - V_28 ;
}
V_6 -> V_105 = F_22 ( V_114 * sizeof( * V_6 -> V_105 ) ,
V_39 ) ;
if ( ! V_6 -> V_105 ) {
F_26 ( & V_3 -> V_78 ) ;
F_51 ( & V_3 -> V_127 ) ;
return - V_40 ;
}
V_6 -> V_129 = V_33 ;
V_6 -> V_117 = V_117 ;
V_14 = 0 ;
while ( V_6 -> V_104 < V_114 ) {
V_112 = & V_6 -> V_105 [ V_6 -> V_104 ] ;
V_112 -> V_93 = V_109 -> V_104 + V_6 -> V_104 ;
V_112 -> V_118 = V_116 ;
V_112 -> V_115 = V_115 ;
V_112 -> V_130 = 0 ;
V_112 -> V_14 = ( V_109 -> V_119 + V_14 ) ;
V_112 -> V_131 = V_113 + V_14 ;
V_112 -> V_132 = ( void * ) ( V_113 + V_14
+ ( unsigned long ) V_3 -> V_73 -> V_74 ) ;
V_112 -> V_133 = NULL ;
V_112 -> V_134 = 0 ;
V_112 -> V_135 = 0 ;
V_112 -> V_85 = NULL ;
V_112 -> V_136 = V_3 -> V_137 -> V_136 ;
V_112 -> V_106 = F_22 ( V_112 -> V_136 , V_39 ) ;
if ( ! V_112 -> V_106 ) {
V_6 -> V_104 = V_114 ;
F_45 ( V_3 , V_6 ) ;
F_26 ( & V_3 -> V_78 ) ;
F_51 ( & V_3 -> V_127 ) ;
return - V_40 ;
}
F_10 ( L_14 , V_6 -> V_104 , V_112 -> V_132 ) ;
V_14 += V_116 ;
V_6 -> V_104 ++ ;
V_119 += V_31 << V_117 ;
}
F_10 ( L_15 , V_119 ) ;
V_120 = F_52 ( V_109 -> V_105 ,
( V_109 -> V_104 + V_6 -> V_104 ) *
sizeof( * V_109 -> V_105 ) , V_39 ) ;
if ( ! V_120 ) {
F_45 ( V_3 , V_6 ) ;
F_26 ( & V_3 -> V_78 ) ;
F_51 ( & V_3 -> V_127 ) ;
return - V_40 ;
}
V_109 -> V_105 = V_120 ;
for ( V_94 = 0 ; V_94 < V_6 -> V_104 ; V_94 ++ ) {
V_109 -> V_105 [ V_94 + V_109 -> V_104 ] = & V_6 -> V_105 [ V_94 ] ;
}
V_109 -> V_104 += V_6 -> V_104 ;
V_109 -> V_102 += V_6 -> V_102 ;
V_109 -> V_138 += V_119 >> V_26 ;
V_109 -> V_119 += V_119 ;
F_10 ( L_16 , V_109 -> V_104 ) ;
F_10 ( L_17 , V_6 -> V_104 ) ;
F_26 ( & V_3 -> V_78 ) ;
V_100 -> V_114 = V_6 -> V_104 ;
V_100 -> V_33 = V_33 ;
V_109 -> V_10 = V_146 ;
F_51 ( & V_3 -> V_127 ) ;
return 0 ;
}
int F_55 ( struct V_2 * V_3 , void * V_83 ,
struct V_84 * V_85 )
{
struct V_107 * V_100 = V_83 ;
int V_24 ;
if ( F_30 ( V_3 , V_90 ) )
return - V_28 ;
if ( ! F_30 ( V_3 , V_147 ) )
return - V_28 ;
#if F_56 ( V_148 )
if ( V_100 -> V_10 & V_149 )
V_24 = F_47 ( V_3 , V_100 ) ;
else
#endif
if ( V_100 -> V_10 & V_150 )
V_24 = F_54 ( V_3 , V_100 ) ;
else if ( V_100 -> V_10 & V_151 )
V_24 = - V_28 ;
else
V_24 = F_53 ( V_3 , V_100 ) ;
return V_24 ;
}
int F_57 ( struct V_2 * V_3 , void * V_83 ,
struct V_84 * V_85 )
{
struct V_108 * V_109 = V_3 -> V_109 ;
struct V_152 * V_100 = V_83 ;
int V_94 ;
int V_114 ;
if ( F_30 ( V_3 , V_90 ) )
return - V_28 ;
if ( ! F_30 ( V_3 , V_147 ) )
return - V_28 ;
if ( ! V_109 )
return - V_28 ;
F_48 ( & V_3 -> V_125 ) ;
if ( F_58 ( & V_3 -> V_127 ) ) {
F_49 ( & V_3 -> V_125 ) ;
return - V_55 ;
}
++ V_3 -> V_126 ;
F_49 ( & V_3 -> V_125 ) ;
for ( V_94 = 0 , V_114 = 0 ; V_94 < V_124 + 1 ; V_94 ++ ) {
if ( V_109 -> V_128 [ V_94 ] . V_104 )
++ V_114 ;
}
F_10 ( L_22 , V_114 ) ;
if ( V_100 -> V_114 >= V_114 ) {
for ( V_94 = 0 , V_114 = 0 ; V_94 < V_124 + 1 ; V_94 ++ ) {
if ( V_109 -> V_128 [ V_94 ] . V_104 ) {
struct V_107 T_3 * V_153 =
& V_100 -> V_37 [ V_114 ] ;
struct V_101 * V_154 = & V_109 -> V_128 [ V_94 ] ;
if ( F_59 ( & V_153 -> V_114 ,
& V_154 -> V_104 ,
sizeof( V_154 -> V_104 ) ) ||
F_59 ( & V_153 -> V_33 ,
& V_154 -> V_129 ,
sizeof( V_154 -> V_129 ) ) ||
F_59 ( & V_153 -> V_155 ,
& V_154 -> V_155 ,
sizeof( V_154 -> V_155 ) ) ||
F_59 ( & V_153 -> V_156 ,
& V_154 -> V_156 ,
sizeof( V_154 -> V_156 ) ) )
return - V_157 ;
F_10 ( L_23 ,
V_94 ,
V_109 -> V_128 [ V_94 ] . V_104 ,
V_109 -> V_128 [ V_94 ] . V_129 ,
V_109 -> V_128 [ V_94 ] . V_155 ,
V_109 -> V_128 [ V_94 ] . V_156 ) ;
++ V_114 ;
}
}
}
V_100 -> V_114 = V_114 ;
return 0 ;
}
int F_60 ( struct V_2 * V_3 , void * V_83 ,
struct V_84 * V_85 )
{
struct V_108 * V_109 = V_3 -> V_109 ;
struct V_107 * V_100 = V_83 ;
int V_115 ;
struct V_101 * V_6 ;
if ( F_30 ( V_3 , V_90 ) )
return - V_28 ;
if ( ! F_30 ( V_3 , V_147 ) )
return - V_28 ;
if ( ! V_109 )
return - V_28 ;
F_10 ( L_24 ,
V_100 -> V_33 , V_100 -> V_155 , V_100 -> V_156 ) ;
V_115 = F_18 ( V_100 -> V_33 ) ;
if ( V_115 < V_123 || V_115 > V_124 )
return - V_28 ;
V_6 = & V_109 -> V_128 [ V_115 ] ;
if ( V_100 -> V_155 < 0 || V_100 -> V_155 > V_6 -> V_104 )
return - V_28 ;
if ( V_100 -> V_156 < 0 || V_100 -> V_156 > V_6 -> V_104 )
return - V_28 ;
V_6 -> V_155 = V_100 -> V_155 ;
V_6 -> V_156 = V_100 -> V_156 ;
return 0 ;
}
int F_61 ( struct V_2 * V_3 , void * V_83 ,
struct V_84 * V_85 )
{
struct V_108 * V_109 = V_3 -> V_109 ;
struct V_158 * V_100 = V_83 ;
int V_94 ;
int V_93 ;
struct V_111 * V_112 ;
if ( F_30 ( V_3 , V_90 ) )
return - V_28 ;
if ( ! F_30 ( V_3 , V_147 ) )
return - V_28 ;
if ( ! V_109 )
return - V_28 ;
F_10 ( L_25 , V_100 -> V_114 ) ;
for ( V_94 = 0 ; V_94 < V_100 -> V_114 ; V_94 ++ ) {
if ( F_62 ( & V_93 , & V_100 -> V_37 [ V_94 ] , sizeof( V_93 ) ) )
return - V_157 ;
if ( V_93 < 0 || V_93 >= V_109 -> V_104 ) {
F_63 ( L_26 ,
V_93 , V_109 -> V_104 - 1 ) ;
return - V_28 ;
}
V_112 = V_109 -> V_105 [ V_93 ] ;
if ( V_112 -> V_85 != V_85 ) {
F_63 ( L_27 ,
F_64 ( V_159 ) ) ;
return - V_28 ;
}
F_65 ( V_3 , V_112 ) ;
}
return 0 ;
}
int F_66 ( struct V_2 * V_3 , void * V_83 ,
struct V_84 * V_85 )
{
struct V_108 * V_109 = V_3 -> V_109 ;
int V_160 = 0 ;
const int V_161 = 0 ;
unsigned long V_74 ;
unsigned long V_132 ;
struct V_162 * V_100 = V_83 ;
int V_94 ;
if ( F_30 ( V_3 , V_90 ) )
return - V_28 ;
if ( ! F_30 ( V_3 , V_147 ) )
return - V_28 ;
if ( ! V_109 )
return - V_28 ;
F_48 ( & V_3 -> V_125 ) ;
if ( F_58 ( & V_3 -> V_127 ) ) {
F_49 ( & V_3 -> V_125 ) ;
return - V_55 ;
}
V_3 -> V_126 ++ ;
F_49 ( & V_3 -> V_125 ) ;
if ( V_100 -> V_114 >= V_109 -> V_104 ) {
if ( ( V_3 -> V_60 && ( V_109 -> V_10 & V_139 ) )
|| ( F_30 ( V_3 , V_145 )
&& ( V_109 -> V_10 & V_146 ) ) ) {
struct V_4 * V_5 = V_3 -> V_163 ;
unsigned long V_164 = V_3 -> V_165 ;
if ( ! V_5 ) {
V_160 = - V_28 ;
goto V_166;
}
V_74 = F_67 ( V_85 -> V_167 , 0 , V_5 -> V_33 ,
V_168 | V_169 ,
V_170 ,
V_164 ) ;
} else {
V_74 = F_67 ( V_85 -> V_167 , 0 , V_109 -> V_119 ,
V_168 | V_169 ,
V_170 , 0 ) ;
}
if ( V_74 > - 1024UL ) {
V_160 = ( signed long ) V_74 ;
goto V_166;
}
V_100 -> V_74 = ( void T_3 * ) V_74 ;
for ( V_94 = 0 ; V_94 < V_109 -> V_104 ; V_94 ++ ) {
if ( F_59 ( & V_100 -> V_37 [ V_94 ] . V_93 ,
& V_109 -> V_105 [ V_94 ] -> V_93 ,
sizeof( V_100 -> V_37 [ 0 ] . V_93 ) ) ) {
V_160 = - V_157 ;
goto V_166;
}
if ( F_59 ( & V_100 -> V_37 [ V_94 ] . V_118 ,
& V_109 -> V_105 [ V_94 ] -> V_118 ,
sizeof( V_100 -> V_37 [ 0 ] . V_118 ) ) ) {
V_160 = - V_157 ;
goto V_166;
}
if ( F_59 ( & V_100 -> V_37 [ V_94 ] . V_130 ,
& V_161 , sizeof( V_161 ) ) ) {
V_160 = - V_157 ;
goto V_166;
}
V_132 = V_74 + V_109 -> V_105 [ V_94 ] -> V_14 ;
if ( F_59 ( & V_100 -> V_37 [ V_94 ] . V_132 ,
& V_132 , sizeof( V_132 ) ) ) {
V_160 = - V_157 ;
goto V_166;
}
}
}
V_166:
V_100 -> V_114 = V_109 -> V_104 ;
F_10 ( L_28 , V_100 -> V_114 , V_160 ) ;
return V_160 ;
}
int F_68 ( struct V_2 * V_3 , void * V_83 ,
struct V_84 * V_85 )
{
if ( F_30 ( V_3 , V_90 ) )
return - V_28 ;
if ( V_3 -> V_137 -> V_171 )
return V_3 -> V_137 -> V_171 ( V_3 , V_83 , V_85 ) ;
else
return - V_28 ;
}
struct V_4 * F_69 ( struct V_2 * V_3 )
{
struct V_1 * V_6 ;
F_2 (entry, &dev->maplist, head) {
if ( V_6 -> V_5 && V_6 -> V_5 -> type == V_9 &&
( V_6 -> V_5 -> V_10 & V_11 ) ) {
return V_6 -> V_5 ;
}
}
return NULL ;
}
