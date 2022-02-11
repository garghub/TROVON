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
V_87 = F_7 ( V_3 , V_5 -> V_14 , V_5 -> V_33 , V_5 -> type ,
V_5 -> V_10 , & V_36 ) ;
if ( V_87 )
return V_87 ;
V_5 -> V_44 = ( void * ) ( unsigned long ) V_36 -> V_17 ;
V_5 -> V_43 = - 1 ;
return 0 ;
}
int F_30 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_89 = NULL , * V_90 ;
T_2 V_38 ;
int V_91 = 0 ;
struct V_92 * V_7 ;
F_31 (r_list, list_t, &dev->maplist, head) {
if ( V_89 -> V_5 == V_5 ) {
V_7 = V_89 -> V_7 ;
F_32 ( & V_89 -> V_79 ) ;
F_33 ( & V_3 -> V_27 ,
V_89 -> V_17 >> V_26 ) ;
F_9 ( V_89 ) ;
V_91 = 1 ;
break;
}
}
if ( ! V_91 )
return - V_28 ;
switch ( V_5 -> type ) {
case V_12 :
F_23 ( V_5 -> V_44 ) ;
case V_13 :
F_34 ( V_5 -> V_43 ) ;
break;
case V_9 :
F_19 ( V_5 -> V_44 ) ;
if ( V_7 ) {
if ( V_3 -> V_56 . V_53 == V_7 -> V_53 . V_54 )
V_3 -> V_56 . V_53 = NULL ;
V_7 -> V_53 . V_54 = NULL ;
V_7 -> V_53 . V_85 = NULL ;
F_35 ( & V_7 -> V_53 . V_93 ) ;
}
break;
case V_57 :
case V_72 :
break;
case V_75 :
V_38 . V_76 = V_5 -> V_44 ;
V_38 . V_77 = V_5 -> V_14 ;
V_38 . V_33 = V_5 -> V_33 ;
F_36 ( V_3 , & V_38 ) ;
break;
}
F_9 ( V_5 ) ;
return 0 ;
}
int F_37 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
int V_24 ;
F_24 ( & V_3 -> V_78 ) ;
V_24 = F_30 ( V_3 , V_5 ) ;
F_26 ( & V_3 -> V_78 ) ;
return V_24 ;
}
int F_38 ( struct V_2 * V_3 , void * V_83 ,
struct V_84 * V_85 )
{
struct V_86 * V_94 = V_83 ;
struct V_4 * V_5 = NULL ;
struct V_1 * V_89 ;
int V_24 ;
F_24 ( & V_3 -> V_78 ) ;
F_2 (r_list, &dev->maplist, head) {
if ( V_89 -> V_5 &&
V_89 -> V_17 == ( unsigned long ) V_94 -> V_44 &&
V_89 -> V_5 -> V_10 & V_41 ) {
V_5 = V_89 -> V_5 ;
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
V_24 = F_30 ( V_3 , V_5 ) ;
F_26 ( & V_3 -> V_78 ) ;
return V_24 ;
}
static void F_39 ( struct V_2 * V_3 ,
struct V_95 * V_6 )
{
int V_96 ;
if ( V_6 -> V_97 ) {
for ( V_96 = 0 ; V_96 < V_6 -> V_97 ; V_96 ++ ) {
if ( V_6 -> V_98 [ V_96 ] ) {
F_40 ( V_3 , V_6 -> V_98 [ V_96 ] ) ;
}
}
F_9 ( V_6 -> V_98 ) ;
V_6 -> V_97 = 0 ;
}
if ( V_6 -> V_99 ) {
for ( V_96 = 0 ; V_96 < V_6 -> V_99 ; V_96 ++ ) {
F_9 ( V_6 -> V_100 [ V_96 ] . V_101 ) ;
}
F_9 ( V_6 -> V_100 ) ;
V_6 -> V_99 = 0 ;
}
}
int F_41 ( struct V_2 * V_3 , struct V_102 * V_94 )
{
struct V_103 * V_104 = V_3 -> V_104 ;
struct V_95 * V_6 ;
struct V_58 * V_105 ;
struct V_106 * V_107 ;
unsigned long V_14 ;
unsigned long V_108 ;
int V_109 ;
int V_110 ;
int V_33 ;
int V_111 ;
int V_112 ;
int V_113 ;
int V_114 ;
int V_96 , V_59 ;
struct V_106 * * V_115 ;
if ( ! V_104 )
return - V_28 ;
V_109 = V_94 -> V_109 ;
V_110 = F_18 ( V_94 -> V_33 ) ;
V_33 = 1 << V_110 ;
V_111 = ( V_94 -> V_10 & V_116 )
? F_11 ( V_33 ) : V_33 ;
V_112 = V_110 - V_26 > 0 ? V_110 - V_26 : 0 ;
V_113 = V_31 << V_112 ;
V_114 = 0 ;
V_108 = V_3 -> V_60 -> V_64 + V_94 -> V_117 ;
F_10 ( L_6 , V_109 ) ;
F_10 ( L_7 , V_110 ) ;
F_10 ( L_8 , V_33 ) ;
F_10 ( L_9 , V_108 ) ;
F_10 ( L_10 , V_111 ) ;
F_10 ( L_11 , V_112 ) ;
F_10 ( L_12 , V_113 ) ;
if ( V_110 < V_118 || V_110 > V_119 )
return - V_28 ;
V_59 = 0 ;
F_2 (agp_entry, &dev->agp->memory, head) {
if ( ( V_108 >= V_105 -> V_68 ) &&
( V_108 + V_113 * V_109 <= V_105 -> V_68 + V_105 -> V_69 * V_31 ) ) {
V_59 = 1 ;
break;
}
}
if ( ! F_20 ( & V_3 -> V_60 -> V_70 ) && ! V_59 ) {
F_10 ( L_13 ) ;
return - V_28 ;
}
F_42 ( & V_3 -> V_120 ) ;
if ( V_3 -> V_121 ) {
F_43 ( & V_3 -> V_120 ) ;
return - V_55 ;
}
F_44 ( & V_3 -> V_122 ) ;
F_43 ( & V_3 -> V_120 ) ;
F_24 ( & V_3 -> V_78 ) ;
V_6 = & V_104 -> V_123 [ V_110 ] ;
if ( V_6 -> V_99 ) {
F_26 ( & V_3 -> V_78 ) ;
F_45 ( & V_3 -> V_122 ) ;
return - V_40 ;
}
if ( V_109 < 0 || V_109 > 4096 ) {
F_26 ( & V_3 -> V_78 ) ;
F_45 ( & V_3 -> V_122 ) ;
return - V_28 ;
}
V_6 -> V_100 = F_22 ( V_109 * sizeof( * V_6 -> V_100 ) , V_39 ) ;
if ( ! V_6 -> V_100 ) {
F_26 ( & V_3 -> V_78 ) ;
F_45 ( & V_3 -> V_122 ) ;
return - V_40 ;
}
V_6 -> V_124 = V_33 ;
V_6 -> V_112 = V_112 ;
V_14 = 0 ;
while ( V_6 -> V_99 < V_109 ) {
V_107 = & V_6 -> V_100 [ V_6 -> V_99 ] ;
V_107 -> V_125 = V_104 -> V_99 + V_6 -> V_99 ;
V_107 -> V_113 = V_111 ;
V_107 -> V_110 = V_110 ;
V_107 -> V_126 = 0 ;
V_107 -> V_14 = ( V_104 -> V_114 + V_14 ) ;
V_107 -> V_127 = V_108 + V_14 ;
V_107 -> V_128 = ( void * ) ( V_108 + V_14 ) ;
V_107 -> V_129 = NULL ;
V_107 -> V_130 = 0 ;
V_107 -> V_131 = 0 ;
V_107 -> V_85 = NULL ;
V_107 -> V_132 = V_3 -> V_133 -> V_132 ;
V_107 -> V_101 = F_22 ( V_107 -> V_132 , V_39 ) ;
if ( ! V_107 -> V_101 ) {
V_6 -> V_99 = V_109 ;
F_39 ( V_3 , V_6 ) ;
F_26 ( & V_3 -> V_78 ) ;
F_45 ( & V_3 -> V_122 ) ;
return - V_40 ;
}
F_10 ( L_14 , V_6 -> V_99 , V_107 -> V_128 ) ;
V_14 += V_111 ;
V_6 -> V_99 ++ ;
V_114 += V_31 << V_112 ;
}
F_10 ( L_15 , V_114 ) ;
V_115 = F_46 ( V_104 -> V_100 ,
( V_104 -> V_99 + V_6 -> V_99 ) *
sizeof( * V_104 -> V_100 ) , V_39 ) ;
if ( ! V_115 ) {
F_39 ( V_3 , V_6 ) ;
F_26 ( & V_3 -> V_78 ) ;
F_45 ( & V_3 -> V_122 ) ;
return - V_40 ;
}
V_104 -> V_100 = V_115 ;
for ( V_96 = 0 ; V_96 < V_6 -> V_99 ; V_96 ++ ) {
V_104 -> V_100 [ V_96 + V_104 -> V_99 ] = & V_6 -> V_100 [ V_96 ] ;
}
V_104 -> V_99 += V_6 -> V_99 ;
V_104 -> V_97 += V_6 -> V_97 ;
V_104 -> V_134 += V_114 >> V_26 ;
V_104 -> V_114 += V_114 ;
F_10 ( L_16 , V_104 -> V_99 ) ;
F_10 ( L_17 , V_6 -> V_99 ) ;
F_26 ( & V_3 -> V_78 ) ;
V_94 -> V_109 = V_6 -> V_99 ;
V_94 -> V_33 = V_33 ;
V_104 -> V_10 = V_135 ;
F_45 ( & V_3 -> V_122 ) ;
return 0 ;
}
int F_47 ( struct V_2 * V_3 , struct V_102 * V_94 )
{
struct V_103 * V_104 = V_3 -> V_104 ;
int V_109 ;
int V_110 ;
int V_33 ;
int V_113 ;
int V_112 ;
struct V_95 * V_6 ;
T_2 * V_38 ;
struct V_106 * V_107 ;
int V_111 ;
unsigned long V_14 ;
int V_96 ;
int V_114 ;
int V_134 ;
unsigned long * V_136 ;
struct V_106 * * V_115 ;
if ( ! F_48 ( V_3 , V_137 ) )
return - V_28 ;
if ( ! V_104 )
return - V_28 ;
if ( ! F_29 ( V_88 ) )
return - V_71 ;
V_109 = V_94 -> V_109 ;
V_110 = F_18 ( V_94 -> V_33 ) ;
V_33 = 1 << V_110 ;
F_10 ( L_18 ,
V_94 -> V_109 , V_94 -> V_33 , V_33 , V_110 ) ;
if ( V_110 < V_118 || V_110 > V_119 )
return - V_28 ;
V_111 = ( V_94 -> V_10 & V_116 )
? F_11 ( V_33 ) : V_33 ;
V_112 = V_110 - V_26 > 0 ? V_110 - V_26 : 0 ;
V_113 = V_31 << V_112 ;
F_42 ( & V_3 -> V_120 ) ;
if ( V_3 -> V_121 ) {
F_43 ( & V_3 -> V_120 ) ;
return - V_55 ;
}
F_44 ( & V_3 -> V_122 ) ;
F_43 ( & V_3 -> V_120 ) ;
F_24 ( & V_3 -> V_78 ) ;
V_6 = & V_104 -> V_123 [ V_110 ] ;
if ( V_6 -> V_99 ) {
F_26 ( & V_3 -> V_78 ) ;
F_45 ( & V_3 -> V_122 ) ;
return - V_40 ;
}
if ( V_109 < 0 || V_109 > 4096 ) {
F_26 ( & V_3 -> V_78 ) ;
F_45 ( & V_3 -> V_122 ) ;
return - V_28 ;
}
V_6 -> V_100 = F_22 ( V_109 * sizeof( * V_6 -> V_100 ) , V_39 ) ;
if ( ! V_6 -> V_100 ) {
F_26 ( & V_3 -> V_78 ) ;
F_45 ( & V_3 -> V_122 ) ;
return - V_40 ;
}
V_6 -> V_98 = F_22 ( V_109 * sizeof( * V_6 -> V_98 ) , V_39 ) ;
if ( ! V_6 -> V_98 ) {
F_9 ( V_6 -> V_100 ) ;
F_26 ( & V_3 -> V_78 ) ;
F_45 ( & V_3 -> V_122 ) ;
return - V_40 ;
}
V_136 = F_8 ( ( V_104 -> V_134 + ( V_109 << V_112 ) ) *
sizeof( * V_104 -> V_138 ) , V_39 ) ;
if ( ! V_136 ) {
F_9 ( V_6 -> V_100 ) ;
F_9 ( V_6 -> V_98 ) ;
F_26 ( & V_3 -> V_78 ) ;
F_45 ( & V_3 -> V_122 ) ;
return - V_40 ;
}
memcpy ( V_136 ,
V_104 -> V_138 , V_104 -> V_134 * sizeof( * V_104 -> V_138 ) ) ;
F_10 ( L_19 ,
V_104 -> V_134 + ( V_109 << V_112 ) ) ;
V_6 -> V_124 = V_33 ;
V_6 -> V_112 = V_112 ;
V_114 = 0 ;
V_134 = 0 ;
while ( V_6 -> V_99 < V_109 ) {
V_38 = F_21 ( V_3 , V_31 << V_112 , 0x1000 ) ;
if ( ! V_38 ) {
V_6 -> V_99 = V_109 ;
V_6 -> V_97 = V_109 ;
F_39 ( V_3 , V_6 ) ;
F_9 ( V_136 ) ;
F_26 ( & V_3 -> V_78 ) ;
F_45 ( & V_3 -> V_122 ) ;
return - V_40 ;
}
V_6 -> V_98 [ V_6 -> V_97 ++ ] = V_38 ;
for ( V_96 = 0 ; V_96 < ( 1 << V_112 ) ; V_96 ++ ) {
F_10 ( L_20 ,
V_104 -> V_134 + V_134 ,
( unsigned long ) V_38 -> V_76 + V_31 * V_96 ) ;
V_136 [ V_104 -> V_134 + V_134 ++ ]
= ( unsigned long ) V_38 -> V_76 + V_31 * V_96 ;
}
for ( V_14 = 0 ;
V_14 + V_33 <= V_113 && V_6 -> V_99 < V_109 ;
V_14 += V_111 , ++ V_6 -> V_99 ) {
V_107 = & V_6 -> V_100 [ V_6 -> V_99 ] ;
V_107 -> V_125 = V_104 -> V_99 + V_6 -> V_99 ;
V_107 -> V_113 = V_111 ;
V_107 -> V_110 = V_110 ;
V_107 -> V_126 = 0 ;
V_107 -> V_14 = ( V_104 -> V_114 + V_114 + V_14 ) ;
V_107 -> V_128 = ( void * ) ( V_38 -> V_76 + V_14 ) ;
V_107 -> V_127 = V_38 -> V_77 + V_14 ;
V_107 -> V_129 = NULL ;
V_107 -> V_130 = 0 ;
V_107 -> V_131 = 0 ;
V_107 -> V_85 = NULL ;
V_107 -> V_132 = V_3 -> V_133 -> V_132 ;
V_107 -> V_101 = F_22 ( V_107 -> V_132 ,
V_39 ) ;
if ( ! V_107 -> V_101 ) {
V_6 -> V_99 = V_109 ;
V_6 -> V_97 = V_109 ;
F_39 ( V_3 , V_6 ) ;
F_9 ( V_136 ) ;
F_26 ( & V_3 -> V_78 ) ;
F_45 ( & V_3 -> V_122 ) ;
return - V_40 ;
}
F_10 ( L_14 ,
V_6 -> V_99 , V_107 -> V_128 ) ;
}
V_114 += V_31 << V_112 ;
}
V_115 = F_46 ( V_104 -> V_100 ,
( V_104 -> V_99 + V_6 -> V_99 ) *
sizeof( * V_104 -> V_100 ) , V_39 ) ;
if ( ! V_115 ) {
F_39 ( V_3 , V_6 ) ;
F_9 ( V_136 ) ;
F_26 ( & V_3 -> V_78 ) ;
F_45 ( & V_3 -> V_122 ) ;
return - V_40 ;
}
V_104 -> V_100 = V_115 ;
for ( V_96 = 0 ; V_96 < V_6 -> V_99 ; V_96 ++ ) {
V_104 -> V_100 [ V_96 + V_104 -> V_99 ] = & V_6 -> V_100 [ V_96 ] ;
}
if ( V_104 -> V_134 ) {
F_9 ( V_104 -> V_138 ) ;
}
V_104 -> V_138 = V_136 ;
V_104 -> V_99 += V_6 -> V_99 ;
V_104 -> V_97 += V_6 -> V_97 ;
V_104 -> V_134 += V_6 -> V_97 << V_112 ;
V_104 -> V_114 += V_31 * ( V_6 -> V_97 << V_112 ) ;
F_26 ( & V_3 -> V_78 ) ;
V_94 -> V_109 = V_6 -> V_99 ;
V_94 -> V_33 = V_33 ;
if ( V_94 -> V_10 & V_139 )
V_104 -> V_10 = V_140 ;
F_45 ( & V_3 -> V_122 ) ;
return 0 ;
}
static int F_49 ( struct V_2 * V_3 , struct V_102 * V_94 )
{
struct V_103 * V_104 = V_3 -> V_104 ;
struct V_95 * V_6 ;
struct V_106 * V_107 ;
unsigned long V_14 ;
unsigned long V_108 ;
int V_109 ;
int V_110 ;
int V_33 ;
int V_111 ;
int V_112 ;
int V_113 ;
int V_114 ;
int V_96 ;
struct V_106 * * V_115 ;
if ( ! F_48 ( V_3 , V_141 ) )
return - V_28 ;
if ( ! V_104 )
return - V_28 ;
if ( ! F_29 ( V_88 ) )
return - V_71 ;
V_109 = V_94 -> V_109 ;
V_110 = F_18 ( V_94 -> V_33 ) ;
V_33 = 1 << V_110 ;
V_111 = ( V_94 -> V_10 & V_116 )
? F_11 ( V_33 ) : V_33 ;
V_112 = V_110 - V_26 > 0 ? V_110 - V_26 : 0 ;
V_113 = V_31 << V_112 ;
V_114 = 0 ;
V_108 = V_94 -> V_117 ;
F_10 ( L_6 , V_109 ) ;
F_10 ( L_7 , V_110 ) ;
F_10 ( L_8 , V_33 ) ;
F_10 ( L_21 , V_108 ) ;
F_10 ( L_10 , V_111 ) ;
F_10 ( L_11 , V_112 ) ;
F_10 ( L_12 , V_113 ) ;
if ( V_110 < V_118 || V_110 > V_119 )
return - V_28 ;
F_42 ( & V_3 -> V_120 ) ;
if ( V_3 -> V_121 ) {
F_43 ( & V_3 -> V_120 ) ;
return - V_55 ;
}
F_44 ( & V_3 -> V_122 ) ;
F_43 ( & V_3 -> V_120 ) ;
F_24 ( & V_3 -> V_78 ) ;
V_6 = & V_104 -> V_123 [ V_110 ] ;
if ( V_6 -> V_99 ) {
F_26 ( & V_3 -> V_78 ) ;
F_45 ( & V_3 -> V_122 ) ;
return - V_40 ;
}
if ( V_109 < 0 || V_109 > 4096 ) {
F_26 ( & V_3 -> V_78 ) ;
F_45 ( & V_3 -> V_122 ) ;
return - V_28 ;
}
V_6 -> V_100 = F_22 ( V_109 * sizeof( * V_6 -> V_100 ) ,
V_39 ) ;
if ( ! V_6 -> V_100 ) {
F_26 ( & V_3 -> V_78 ) ;
F_45 ( & V_3 -> V_122 ) ;
return - V_40 ;
}
V_6 -> V_124 = V_33 ;
V_6 -> V_112 = V_112 ;
V_14 = 0 ;
while ( V_6 -> V_99 < V_109 ) {
V_107 = & V_6 -> V_100 [ V_6 -> V_99 ] ;
V_107 -> V_125 = V_104 -> V_99 + V_6 -> V_99 ;
V_107 -> V_113 = V_111 ;
V_107 -> V_110 = V_110 ;
V_107 -> V_126 = 0 ;
V_107 -> V_14 = ( V_104 -> V_114 + V_14 ) ;
V_107 -> V_127 = V_108 + V_14 ;
V_107 -> V_128 = ( void * ) ( V_108 + V_14
+ ( unsigned long ) V_3 -> V_73 -> V_74 ) ;
V_107 -> V_129 = NULL ;
V_107 -> V_130 = 0 ;
V_107 -> V_131 = 0 ;
V_107 -> V_85 = NULL ;
V_107 -> V_132 = V_3 -> V_133 -> V_132 ;
V_107 -> V_101 = F_22 ( V_107 -> V_132 , V_39 ) ;
if ( ! V_107 -> V_101 ) {
V_6 -> V_99 = V_109 ;
F_39 ( V_3 , V_6 ) ;
F_26 ( & V_3 -> V_78 ) ;
F_45 ( & V_3 -> V_122 ) ;
return - V_40 ;
}
F_10 ( L_14 , V_6 -> V_99 , V_107 -> V_128 ) ;
V_14 += V_111 ;
V_6 -> V_99 ++ ;
V_114 += V_31 << V_112 ;
}
F_10 ( L_15 , V_114 ) ;
V_115 = F_46 ( V_104 -> V_100 ,
( V_104 -> V_99 + V_6 -> V_99 ) *
sizeof( * V_104 -> V_100 ) , V_39 ) ;
if ( ! V_115 ) {
F_39 ( V_3 , V_6 ) ;
F_26 ( & V_3 -> V_78 ) ;
F_45 ( & V_3 -> V_122 ) ;
return - V_40 ;
}
V_104 -> V_100 = V_115 ;
for ( V_96 = 0 ; V_96 < V_6 -> V_99 ; V_96 ++ ) {
V_104 -> V_100 [ V_96 + V_104 -> V_99 ] = & V_6 -> V_100 [ V_96 ] ;
}
V_104 -> V_99 += V_6 -> V_99 ;
V_104 -> V_97 += V_6 -> V_97 ;
V_104 -> V_134 += V_114 >> V_26 ;
V_104 -> V_114 += V_114 ;
F_10 ( L_16 , V_104 -> V_99 ) ;
F_10 ( L_17 , V_6 -> V_99 ) ;
F_26 ( & V_3 -> V_78 ) ;
V_94 -> V_109 = V_6 -> V_99 ;
V_94 -> V_33 = V_33 ;
V_104 -> V_10 = V_142 ;
F_45 ( & V_3 -> V_122 ) ;
return 0 ;
}
int F_50 ( struct V_2 * V_3 , void * V_83 ,
struct V_84 * V_85 )
{
struct V_102 * V_94 = V_83 ;
int V_24 ;
if ( F_48 ( V_3 , V_143 ) )
return - V_28 ;
if ( ! F_48 ( V_3 , V_144 ) )
return - V_28 ;
#if V_145
if ( V_94 -> V_10 & V_146 )
V_24 = F_41 ( V_3 , V_94 ) ;
else
#endif
if ( V_94 -> V_10 & V_147 )
V_24 = F_49 ( V_3 , V_94 ) ;
else if ( V_94 -> V_10 & V_148 )
V_24 = - V_28 ;
else
V_24 = F_47 ( V_3 , V_94 ) ;
return V_24 ;
}
int F_51 ( struct V_2 * V_3 , void * V_83 ,
struct V_84 * V_85 )
{
struct V_103 * V_104 = V_3 -> V_104 ;
struct V_149 * V_94 = V_83 ;
int V_96 ;
int V_109 ;
if ( F_48 ( V_3 , V_143 ) )
return - V_28 ;
if ( ! F_48 ( V_3 , V_144 ) )
return - V_28 ;
if ( ! V_104 )
return - V_28 ;
F_42 ( & V_3 -> V_120 ) ;
if ( F_52 ( & V_3 -> V_122 ) ) {
F_43 ( & V_3 -> V_120 ) ;
return - V_55 ;
}
++ V_3 -> V_121 ;
F_43 ( & V_3 -> V_120 ) ;
for ( V_96 = 0 , V_109 = 0 ; V_96 < V_119 + 1 ; V_96 ++ ) {
if ( V_104 -> V_123 [ V_96 ] . V_99 )
++ V_109 ;
}
F_10 ( L_22 , V_109 ) ;
if ( V_94 -> V_109 >= V_109 ) {
for ( V_96 = 0 , V_109 = 0 ; V_96 < V_119 + 1 ; V_96 ++ ) {
if ( V_104 -> V_123 [ V_96 ] . V_99 ) {
struct V_102 T_3 * V_150 =
& V_94 -> V_37 [ V_109 ] ;
struct V_95 * V_151 = & V_104 -> V_123 [ V_96 ] ;
if ( F_53 ( & V_150 -> V_109 ,
& V_151 -> V_99 ,
sizeof( V_151 -> V_99 ) ) ||
F_53 ( & V_150 -> V_33 ,
& V_151 -> V_124 ,
sizeof( V_151 -> V_124 ) ) ||
F_53 ( & V_150 -> V_152 ,
& V_151 -> V_152 ,
sizeof( V_151 -> V_152 ) ) ||
F_53 ( & V_150 -> V_153 ,
& V_151 -> V_153 ,
sizeof( V_151 -> V_153 ) ) )
return - V_154 ;
F_10 ( L_23 ,
V_96 ,
V_104 -> V_123 [ V_96 ] . V_99 ,
V_104 -> V_123 [ V_96 ] . V_124 ,
V_104 -> V_123 [ V_96 ] . V_152 ,
V_104 -> V_123 [ V_96 ] . V_153 ) ;
++ V_109 ;
}
}
}
V_94 -> V_109 = V_109 ;
return 0 ;
}
int F_54 ( struct V_2 * V_3 , void * V_83 ,
struct V_84 * V_85 )
{
struct V_103 * V_104 = V_3 -> V_104 ;
struct V_102 * V_94 = V_83 ;
int V_110 ;
struct V_95 * V_6 ;
if ( F_48 ( V_3 , V_143 ) )
return - V_28 ;
if ( ! F_48 ( V_3 , V_144 ) )
return - V_28 ;
if ( ! V_104 )
return - V_28 ;
F_10 ( L_24 ,
V_94 -> V_33 , V_94 -> V_152 , V_94 -> V_153 ) ;
V_110 = F_18 ( V_94 -> V_33 ) ;
if ( V_110 < V_118 || V_110 > V_119 )
return - V_28 ;
V_6 = & V_104 -> V_123 [ V_110 ] ;
if ( V_94 -> V_152 < 0 || V_94 -> V_152 > V_6 -> V_99 )
return - V_28 ;
if ( V_94 -> V_153 < 0 || V_94 -> V_153 > V_6 -> V_99 )
return - V_28 ;
V_6 -> V_152 = V_94 -> V_152 ;
V_6 -> V_153 = V_94 -> V_153 ;
return 0 ;
}
int F_55 ( struct V_2 * V_3 , void * V_83 ,
struct V_84 * V_85 )
{
struct V_103 * V_104 = V_3 -> V_104 ;
struct V_155 * V_94 = V_83 ;
int V_96 ;
int V_125 ;
struct V_106 * V_107 ;
if ( F_48 ( V_3 , V_143 ) )
return - V_28 ;
if ( ! F_48 ( V_3 , V_144 ) )
return - V_28 ;
if ( ! V_104 )
return - V_28 ;
F_10 ( L_25 , V_94 -> V_109 ) ;
for ( V_96 = 0 ; V_96 < V_94 -> V_109 ; V_96 ++ ) {
if ( F_56 ( & V_125 , & V_94 -> V_37 [ V_96 ] , sizeof( V_125 ) ) )
return - V_154 ;
if ( V_125 < 0 || V_125 >= V_104 -> V_99 ) {
F_57 ( L_26 ,
V_125 , V_104 -> V_99 - 1 ) ;
return - V_28 ;
}
V_107 = V_104 -> V_100 [ V_125 ] ;
if ( V_107 -> V_85 != V_85 ) {
F_57 ( L_27 ,
F_58 ( V_156 ) ) ;
return - V_28 ;
}
F_59 ( V_3 , V_107 ) ;
}
return 0 ;
}
int F_60 ( struct V_2 * V_3 , void * V_83 ,
struct V_84 * V_85 )
{
struct V_103 * V_104 = V_3 -> V_104 ;
int V_157 = 0 ;
const int V_158 = 0 ;
unsigned long V_74 ;
unsigned long V_128 ;
struct V_159 * V_94 = V_83 ;
int V_96 ;
if ( F_48 ( V_3 , V_143 ) )
return - V_28 ;
if ( ! F_48 ( V_3 , V_144 ) )
return - V_28 ;
if ( ! V_104 )
return - V_28 ;
F_42 ( & V_3 -> V_120 ) ;
if ( F_52 ( & V_3 -> V_122 ) ) {
F_43 ( & V_3 -> V_120 ) ;
return - V_55 ;
}
V_3 -> V_121 ++ ;
F_43 ( & V_3 -> V_120 ) ;
if ( V_94 -> V_109 >= V_104 -> V_99 ) {
if ( ( V_3 -> V_60 && ( V_104 -> V_10 & V_135 ) )
|| ( F_48 ( V_3 , V_141 )
&& ( V_104 -> V_10 & V_142 ) ) ) {
struct V_4 * V_5 = V_3 -> V_160 ;
unsigned long V_161 = V_3 -> V_162 ;
if ( ! V_5 ) {
V_157 = - V_28 ;
goto V_163;
}
V_74 = F_61 ( V_85 -> V_164 , 0 , V_5 -> V_33 ,
V_165 | V_166 ,
V_167 ,
V_161 ) ;
} else {
V_74 = F_61 ( V_85 -> V_164 , 0 , V_104 -> V_114 ,
V_165 | V_166 ,
V_167 , 0 ) ;
}
if ( V_74 > - 1024UL ) {
V_157 = ( signed long ) V_74 ;
goto V_163;
}
V_94 -> V_74 = ( void T_3 * ) V_74 ;
for ( V_96 = 0 ; V_96 < V_104 -> V_99 ; V_96 ++ ) {
if ( F_53 ( & V_94 -> V_37 [ V_96 ] . V_125 ,
& V_104 -> V_100 [ V_96 ] -> V_125 ,
sizeof( V_94 -> V_37 [ 0 ] . V_125 ) ) ) {
V_157 = - V_154 ;
goto V_163;
}
if ( F_53 ( & V_94 -> V_37 [ V_96 ] . V_113 ,
& V_104 -> V_100 [ V_96 ] -> V_113 ,
sizeof( V_94 -> V_37 [ 0 ] . V_113 ) ) ) {
V_157 = - V_154 ;
goto V_163;
}
if ( F_53 ( & V_94 -> V_37 [ V_96 ] . V_126 ,
& V_158 , sizeof( V_158 ) ) ) {
V_157 = - V_154 ;
goto V_163;
}
V_128 = V_74 + V_104 -> V_100 [ V_96 ] -> V_14 ;
if ( F_53 ( & V_94 -> V_37 [ V_96 ] . V_128 ,
& V_128 , sizeof( V_128 ) ) ) {
V_157 = - V_154 ;
goto V_163;
}
}
}
V_163:
V_94 -> V_109 = V_104 -> V_99 ;
F_10 ( L_28 , V_94 -> V_109 , V_157 ) ;
return V_157 ;
}
int F_62 ( struct V_2 * V_3 , void * V_83 ,
struct V_84 * V_85 )
{
if ( F_48 ( V_3 , V_143 ) )
return - V_28 ;
if ( V_3 -> V_133 -> V_168 )
return V_3 -> V_133 -> V_168 ( V_3 , V_83 , V_85 ) ;
else
return - V_28 ;
}
struct V_4 * F_63 ( struct V_2 * V_3 )
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
