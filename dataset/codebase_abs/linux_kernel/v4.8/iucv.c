static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return 0 ;
}
static inline int F_2 ( int V_5 , union V_6 * V_7 )
{
register unsigned long T_1 V_8 ( L_1 ) ;
register unsigned long T_2 V_8 ( L_2 ) ;
int V_9 ;
T_1 = V_5 ;
T_2 = ( unsigned long ) V_7 ;
asm volatile(
" .long 0xb2f01000\n"
" ipm %0\n"
" srl %0,28\n"
: "=d" (ccode), "=m" (*parm), "+d" (reg0), "+a" (reg1)
: "m" (*parm) : "cc");
return V_9 ;
}
static inline int F_3 ( int V_5 , union V_6 * V_7 )
{
int V_9 ;
V_9 = F_2 ( V_5 , V_7 ) ;
return V_9 == 1 ? V_7 -> V_10 . V_11 : V_9 ;
}
static int F_4 ( void * V_12 , unsigned long * V_13 )
{
register unsigned long T_1 V_8 ( L_1 ) ;
register unsigned long T_2 V_8 ( L_2 ) ;
int V_9 ;
T_1 = V_14 ;
T_2 = ( unsigned long ) V_12 ;
asm volatile (
" .long 0xb2f01000\n"
" ipm %0\n"
" srl %0,28\n"
: "=d" (ccode), "+d" (reg0), "+d" (reg1) : : "cc");
* V_13 = T_2 ;
return V_9 ;
}
static int F_5 ( void )
{
unsigned long V_13 ;
void * V_12 ;
int V_9 ;
V_12 = F_6 ( sizeof( union V_6 ) , V_15 | V_16 ) ;
if ( ! V_12 )
return - V_17 ;
V_9 = F_4 ( V_12 , & V_13 ) ;
if ( V_9 == 0 )
V_18 = V_13 ;
F_7 ( V_12 ) ;
return V_9 ? - V_19 : 0 ;
}
static void F_8 ( void * V_20 )
{
int V_21 = F_9 () ;
union V_6 * V_7 ;
V_7 = V_22 [ V_21 ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
V_7 -> V_23 . V_24 = 0xf8 ;
F_3 ( V_25 , V_7 ) ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
V_7 -> V_23 . V_24 = 0xf8 ;
F_3 ( V_26 , V_7 ) ;
F_10 ( V_21 , & V_27 ) ;
}
static void F_11 ( void * V_20 )
{
int V_21 = F_9 () ;
union V_6 * V_7 ;
V_7 = V_22 [ V_21 ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
F_3 ( V_25 , V_7 ) ;
F_12 ( V_21 , & V_27 ) ;
}
static void F_13 ( void * V_20 )
{
int V_21 = F_9 () ;
union V_6 * V_7 ;
V_7 = V_22 [ V_21 ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
V_7 -> V_23 . V_24 = 0x08 ;
F_3 ( V_25 , V_7 ) ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
V_7 -> V_23 . V_24 = 0x20 ;
F_3 ( V_26 , V_7 ) ;
F_12 ( V_21 , & V_27 ) ;
}
static void F_14 ( void * V_20 )
{
int V_21 = F_9 () ;
union V_6 * V_7 ;
int V_28 ;
if ( F_15 ( V_21 , & V_29 ) )
return;
V_7 = V_22 [ V_21 ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
V_7 -> V_30 . V_31 = F_16 ( V_32 [ V_21 ] ) ;
V_28 = F_3 ( V_33 , V_7 ) ;
if ( V_28 ) {
char * V_34 = L_3 ;
switch ( V_28 ) {
case 0x03 :
V_34 = L_4 ;
break;
case 0x0a :
V_34 = L_5 ;
break;
case 0x13 :
V_34 = L_6 ;
break;
case 0x3e :
V_34 = L_7 ;
break;
case 0x5c :
V_34 = L_8 ;
break;
}
F_17 ( L_9 ,
V_21 , V_28 , V_34 ) ;
return;
}
F_10 ( V_21 , & V_29 ) ;
if ( V_35 == 0 || F_18 ( & V_27 ) )
F_8 ( NULL ) ;
else
F_11 ( NULL ) ;
}
static void F_19 ( void * V_20 )
{
int V_21 = F_9 () ;
union V_6 * V_7 ;
if ( ! F_15 ( V_21 , & V_29 ) )
return;
F_11 ( NULL ) ;
V_7 = V_22 [ V_21 ] ;
F_3 ( V_36 , V_7 ) ;
F_12 ( V_21 , & V_29 ) ;
}
static void F_20 ( void )
{
int V_21 ;
F_21 () ;
F_22 (cpu)
if ( F_15 ( V_21 , & V_29 ) &&
! F_15 ( V_21 , & V_27 ) )
F_23 ( V_21 , F_8 ,
NULL , 1 ) ;
F_24 () ;
}
static void F_25 ( void )
{
T_3 V_37 ;
int V_21 ;
F_26 ( & V_37 , & V_27 ) ;
F_12 ( F_27 ( & V_27 ) , & V_37 ) ;
F_28 (cpu, &cpumask)
F_23 ( V_21 , F_11 , NULL , 1 ) ;
}
static int F_29 ( void )
{
T_4 V_38 ;
int V_21 , V_28 ;
F_21 () ;
V_28 = - V_17 ;
V_38 = V_18 * sizeof( struct V_39 ) ;
V_40 = F_6 ( V_38 , V_15 ) ;
if ( ! V_40 )
goto V_41;
V_28 = - V_42 ;
F_22 (cpu)
F_23 ( V_21 , F_14 , NULL , 1 ) ;
if ( F_18 ( & V_29 ) )
goto V_41;
F_24 () ;
return 0 ;
V_41:
F_7 ( V_40 ) ;
V_40 = NULL ;
F_24 () ;
return V_28 ;
}
static void F_30 ( void )
{
F_21 () ;
F_31 ( F_19 , NULL , 1 ) ;
F_7 ( V_40 ) ;
V_40 = NULL ;
F_24 () ;
}
static void F_32 ( int V_21 )
{
F_7 ( V_22 [ V_21 ] ) ;
V_22 [ V_21 ] = NULL ;
F_7 ( V_6 [ V_21 ] ) ;
V_6 [ V_21 ] = NULL ;
F_7 ( V_32 [ V_21 ] ) ;
V_32 [ V_21 ] = NULL ;
}
static int F_33 ( int V_21 )
{
V_32 [ V_21 ] = F_34 ( sizeof( struct V_32 ) ,
V_15 | V_16 , F_35 ( V_21 ) ) ;
if ( ! V_32 [ V_21 ] )
goto V_43;
V_6 [ V_21 ] = F_34 ( sizeof( union V_6 ) ,
V_15 | V_16 , F_35 ( V_21 ) ) ;
if ( ! V_6 [ V_21 ] )
goto V_43;
V_22 [ V_21 ] = F_34 ( sizeof( union V_6 ) ,
V_15 | V_16 , F_35 ( V_21 ) ) ;
if ( ! V_22 [ V_21 ] )
goto V_43;
return 0 ;
V_43:
F_32 ( V_21 ) ;
return - V_17 ;
}
static int F_36 ( struct V_44 * V_45 ,
unsigned long V_46 , void * V_47 )
{
T_3 V_37 ;
long V_21 = ( long ) V_47 ;
switch ( V_46 ) {
case V_48 :
case V_49 :
if ( F_33 ( V_21 ) )
return F_37 ( - V_17 ) ;
break;
case V_50 :
case V_51 :
case V_52 :
case V_53 :
F_32 ( V_21 ) ;
break;
case V_54 :
case V_55 :
case V_56 :
case V_57 :
if ( ! V_40 )
break;
F_23 ( V_21 , F_14 , NULL , 1 ) ;
break;
case V_58 :
case V_59 :
if ( ! V_40 )
break;
F_26 ( & V_37 , & V_29 ) ;
F_12 ( V_21 , & V_37 ) ;
if ( F_18 ( & V_37 ) )
return F_37 ( - V_60 ) ;
F_23 ( V_21 , F_19 , NULL , 1 ) ;
if ( F_18 ( & V_27 ) )
F_23 (
F_27 ( & V_29 ) ,
F_8 , NULL , 1 ) ;
break;
}
return V_61 ;
}
static int F_38 ( T_5 V_62 , T_6 * V_63 )
{
union V_6 * V_7 ;
V_7 = V_22 [ F_9 () ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
if ( V_63 )
memcpy ( V_7 -> V_10 . V_64 , V_63 , sizeof( V_7 -> V_10 . V_64 ) ) ;
V_7 -> V_10 . V_65 = V_62 ;
return F_3 ( V_66 , V_7 ) ;
}
static void F_39 ( void * V_67 )
{
}
static void F_40 ( void )
{
struct V_68 * V_69 , * V_70 ;
F_41 ( F_39 , NULL , 1 ) ;
F_42 ( & V_71 ) ;
F_43 (p, n, &iucv_task_queue, list) {
if ( V_40 [ V_69 -> V_20 . V_65 ] == NULL ) {
F_44 ( & V_69 -> V_72 ) ;
F_7 ( V_69 ) ;
}
}
F_45 ( & V_71 ) ;
}
int F_46 ( struct V_73 * V_74 , int V_75 )
{
int V_28 ;
if ( ! V_76 )
return - V_77 ;
F_47 ( & V_78 ) ;
if ( ! V_75 )
V_35 ++ ;
if ( F_48 ( & V_79 ) ) {
V_28 = F_29 () ;
if ( V_28 )
goto V_80;
} else if ( ! V_75 && V_35 == 1 )
F_25 () ;
F_49 ( & V_74 -> V_81 ) ;
F_50 ( & V_82 ) ;
F_51 ( & V_74 -> V_72 , & V_79 ) ;
F_52 ( & V_82 ) ;
V_28 = 0 ;
V_80:
F_53 ( & V_78 ) ;
return V_28 ;
}
void F_54 ( struct V_73 * V_74 , int V_75 )
{
struct V_39 * V_69 , * V_70 ;
F_47 ( & V_78 ) ;
F_50 ( & V_82 ) ;
F_55 ( & V_74 -> V_72 ) ;
F_43 (p, n, &handler->paths, list) {
F_38 ( V_69 -> V_62 , NULL ) ;
V_40 [ V_69 -> V_62 ] = NULL ;
F_44 ( & V_69 -> V_72 ) ;
F_56 ( V_69 ) ;
}
F_52 ( & V_82 ) ;
if ( ! V_75 )
V_35 -- ;
if ( F_48 ( & V_79 ) )
F_30 () ;
else if ( ! V_75 && V_35 == 0 )
F_20 () ;
F_53 ( & V_78 ) ;
}
static int F_57 ( struct V_44 * V_83 ,
unsigned long V_84 , void * V_85 )
{
int V_86 ;
if ( F_18 ( & V_27 ) )
return V_87 ;
F_21 () ;
F_58 ( & V_27 , F_11 , NULL , 1 ) ;
F_59 () ;
for ( V_86 = 0 ; V_86 < V_18 ; V_86 ++ ) {
if ( V_40 [ V_86 ] )
F_38 ( V_86 , NULL ) ;
}
F_60 () ;
F_24 () ;
F_30 () ;
return V_87 ;
}
int F_61 ( struct V_39 * V_88 , struct V_73 * V_74 ,
T_6 * V_63 , void * V_89 )
{
union V_6 * V_7 ;
int V_28 ;
F_62 () ;
if ( F_18 ( & V_29 ) ) {
V_28 = - V_42 ;
goto V_41;
}
V_7 = V_6 [ F_9 () ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
V_7 -> V_10 . V_65 = V_88 -> V_62 ;
V_7 -> V_10 . V_90 = V_88 -> V_91 ;
if ( V_63 )
memcpy ( V_7 -> V_10 . V_64 , V_63 , sizeof( V_7 -> V_10 . V_64 ) ) ;
V_7 -> V_10 . V_92 = V_88 -> V_93 ;
V_28 = F_3 ( V_94 , V_7 ) ;
if ( ! V_28 ) {
V_88 -> V_89 = V_89 ;
V_88 -> V_91 = V_7 -> V_10 . V_90 ;
V_88 -> V_93 = V_7 -> V_10 . V_92 ;
}
V_41:
F_63 () ;
return V_28 ;
}
int F_64 ( struct V_39 * V_88 , struct V_73 * V_74 ,
T_6 * V_95 , T_6 * system , T_6 * V_63 ,
void * V_89 )
{
union V_6 * V_7 ;
int V_28 ;
F_50 ( & V_82 ) ;
F_40 () ;
if ( F_18 ( & V_29 ) ) {
V_28 = - V_42 ;
goto V_41;
}
V_7 = V_6 [ F_9 () ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
V_7 -> V_10 . V_90 = V_88 -> V_91 ;
V_7 -> V_10 . V_92 = V_88 -> V_93 ;
if ( V_95 ) {
memcpy ( V_7 -> V_10 . V_96 , V_95 , sizeof( V_7 -> V_10 . V_96 ) ) ;
F_65 ( V_7 -> V_10 . V_96 , sizeof( V_7 -> V_10 . V_96 ) ) ;
F_66 ( V_7 -> V_10 . V_96 , sizeof( V_7 -> V_10 . V_96 ) ) ;
}
if ( system ) {
memcpy ( V_7 -> V_10 . V_97 , system ,
sizeof( V_7 -> V_10 . V_97 ) ) ;
F_65 ( V_7 -> V_10 . V_97 , sizeof( V_7 -> V_10 . V_97 ) ) ;
F_66 ( V_7 -> V_10 . V_97 , sizeof( V_7 -> V_10 . V_97 ) ) ;
}
if ( V_63 )
memcpy ( V_7 -> V_10 . V_64 , V_63 , sizeof( V_7 -> V_10 . V_64 ) ) ;
V_28 = F_3 ( V_98 , V_7 ) ;
if ( ! V_28 ) {
if ( V_7 -> V_10 . V_65 < V_18 ) {
V_88 -> V_62 = V_7 -> V_10 . V_65 ;
V_88 -> V_91 = V_7 -> V_10 . V_90 ;
V_88 -> V_93 = V_7 -> V_10 . V_92 ;
V_88 -> V_74 = V_74 ;
V_88 -> V_89 = V_89 ;
F_51 ( & V_88 -> V_72 , & V_74 -> V_81 ) ;
V_40 [ V_88 -> V_62 ] = V_88 ;
} else {
F_38 ( V_7 -> V_10 . V_65 ,
V_99 ) ;
V_28 = - V_42 ;
}
}
V_41:
F_52 ( & V_82 ) ;
return V_28 ;
}
int F_67 ( struct V_39 * V_88 , T_6 * V_63 )
{
union V_6 * V_7 ;
int V_28 ;
F_62 () ;
if ( F_18 ( & V_29 ) ) {
V_28 = - V_42 ;
goto V_41;
}
V_7 = V_6 [ F_9 () ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
if ( V_63 )
memcpy ( V_7 -> V_10 . V_64 , V_63 , sizeof( V_7 -> V_10 . V_64 ) ) ;
V_7 -> V_10 . V_65 = V_88 -> V_62 ;
V_28 = F_3 ( V_100 , V_7 ) ;
V_41:
F_63 () ;
return V_28 ;
}
int F_68 ( struct V_39 * V_88 , T_6 * V_63 )
{
union V_6 * V_7 ;
int V_28 ;
F_62 () ;
if ( F_18 ( & V_29 ) ) {
V_28 = - V_42 ;
goto V_41;
}
V_7 = V_6 [ F_9 () ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
if ( V_63 )
memcpy ( V_7 -> V_10 . V_64 , V_63 , sizeof( V_7 -> V_10 . V_64 ) ) ;
V_7 -> V_10 . V_65 = V_88 -> V_62 ;
V_28 = F_3 ( V_101 , V_7 ) ;
V_41:
F_63 () ;
return V_28 ;
}
int F_69 ( struct V_39 * V_88 , T_6 * V_63 )
{
int V_28 ;
F_59 () ;
if ( F_18 ( & V_29 ) ) {
V_28 = - V_42 ;
goto V_41;
}
if ( V_102 != F_9 () )
F_50 ( & V_82 ) ;
V_28 = F_38 ( V_88 -> V_62 , V_63 ) ;
V_40 [ V_88 -> V_62 ] = NULL ;
F_55 ( & V_88 -> V_72 ) ;
if ( V_102 != F_9 () )
F_52 ( & V_82 ) ;
V_41:
F_60 () ;
return V_28 ;
}
int F_70 ( struct V_39 * V_88 , struct V_103 * V_104 ,
T_7 V_105 )
{
union V_6 * V_7 ;
int V_28 ;
F_62 () ;
if ( F_18 ( & V_29 ) ) {
V_28 = - V_42 ;
goto V_41;
}
V_7 = V_6 [ F_9 () ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
V_7 -> V_106 . V_65 = V_88 -> V_62 ;
V_7 -> V_106 . V_107 = V_104 -> V_108 ;
V_7 -> V_106 . V_109 = V_105 ;
V_7 -> V_106 . V_92 = V_110 | V_111 | V_112 ;
V_28 = F_3 ( V_113 , V_7 ) ;
if ( ! V_28 ) {
V_104 -> V_114 = ( * ( T_7 * ) & V_7 -> V_106 . V_115 ) >> 8 ;
V_104 -> V_116 = V_7 -> V_106 . V_117 ;
}
V_41:
F_63 () ;
return V_28 ;
}
static int F_71 ( struct V_39 * V_88 ,
struct V_103 * V_104 ,
T_6 V_93 , void * V_118 ,
T_4 V_119 , T_4 * V_120 )
{
struct V_121 * V_122 ;
T_6 * V_123 ;
T_4 V_124 ;
if ( V_120 )
* V_120 = abs ( V_119 - 8 ) ;
V_123 = V_104 -> V_123 ;
if ( V_93 & V_125 ) {
V_119 = ( V_119 < 8 ) ? V_119 : 8 ;
for ( V_122 = V_118 ; V_119 > 0 ; V_122 ++ ) {
V_124 = F_72 ( T_4 , V_119 , V_122 -> V_126 ) ;
memcpy ( ( T_6 * ) ( V_127 ) V_122 -> V_128 ,
V_123 , V_124 ) ;
V_123 += V_124 ;
V_119 -= V_124 ;
}
} else {
memcpy ( V_118 , V_123 , F_72 ( T_4 , V_119 , 8 ) ) ;
}
return 0 ;
}
int F_73 ( struct V_39 * V_88 , struct V_103 * V_104 ,
T_6 V_93 , void * V_118 , T_4 V_119 , T_4 * V_120 )
{
union V_6 * V_7 ;
int V_28 ;
if ( V_104 -> V_93 & V_129 )
return F_71 ( V_88 , V_104 , V_93 ,
V_118 , V_119 , V_120 ) ;
if ( F_18 ( & V_29 ) ) {
V_28 = - V_42 ;
goto V_41;
}
V_7 = V_6 [ F_9 () ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
V_7 -> V_30 . V_31 = ( T_7 ) ( V_127 ) V_118 ;
V_7 -> V_30 . V_130 = ( T_7 ) V_119 ;
V_7 -> V_30 . V_107 = V_104 -> V_108 ;
V_7 -> V_30 . V_65 = V_88 -> V_62 ;
V_7 -> V_30 . V_131 = V_104 -> V_132 ;
V_7 -> V_30 . V_92 = ( V_93 | V_112 |
V_111 | V_133 ) ;
V_28 = F_3 ( V_134 , V_7 ) ;
if ( ! V_28 || V_28 == 5 ) {
V_104 -> V_93 = V_7 -> V_30 . V_92 ;
if ( V_120 )
* V_120 = V_7 -> V_30 . V_130 ;
}
V_41:
return V_28 ;
}
int F_74 ( struct V_39 * V_88 , struct V_103 * V_104 ,
T_6 V_93 , void * V_118 , T_4 V_119 , T_4 * V_120 )
{
int V_28 ;
if ( V_104 -> V_93 & V_129 )
return F_71 ( V_88 , V_104 , V_93 ,
V_118 , V_119 , V_120 ) ;
F_62 () ;
V_28 = F_73 ( V_88 , V_104 , V_93 , V_118 , V_119 , V_120 ) ;
F_63 () ;
return V_28 ;
}
int F_75 ( struct V_39 * V_88 , struct V_103 * V_104 )
{
union V_6 * V_7 ;
int V_28 ;
F_62 () ;
if ( F_18 ( & V_29 ) ) {
V_28 = - V_42 ;
goto V_41;
}
V_7 = V_6 [ F_9 () ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
V_7 -> V_30 . V_65 = V_88 -> V_62 ;
V_7 -> V_30 . V_107 = V_104 -> V_108 ;
V_7 -> V_30 . V_131 = V_104 -> V_132 ;
V_7 -> V_30 . V_92 = ( V_133 | V_111 | V_112 ) ;
V_28 = F_3 ( V_135 , V_7 ) ;
V_41:
F_63 () ;
return V_28 ;
}
int F_76 ( struct V_39 * V_88 , struct V_103 * V_104 ,
T_6 V_93 , void * V_136 , T_4 V_119 )
{
union V_6 * V_7 ;
int V_28 ;
F_62 () ;
if ( F_18 ( & V_29 ) ) {
V_28 = - V_42 ;
goto V_41;
}
V_7 = V_6 [ F_9 () ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
if ( V_93 & V_129 ) {
V_7 -> V_137 . V_65 = V_88 -> V_62 ;
V_7 -> V_137 . V_92 = V_93 ;
V_7 -> V_137 . V_107 = V_104 -> V_108 ;
V_7 -> V_137 . V_131 = V_104 -> V_132 ;
memcpy ( V_7 -> V_137 . V_138 , V_136 , F_72 ( T_4 , V_119 , 8 ) ) ;
} else {
V_7 -> V_30 . V_31 = ( T_7 ) ( V_127 ) V_136 ;
V_7 -> V_30 . V_130 = ( T_7 ) V_119 ;
V_7 -> V_30 . V_65 = V_88 -> V_62 ;
V_7 -> V_30 . V_92 = V_93 ;
V_7 -> V_30 . V_107 = V_104 -> V_108 ;
V_7 -> V_30 . V_131 = V_104 -> V_132 ;
}
V_28 = F_3 ( V_139 , V_7 ) ;
V_41:
F_63 () ;
return V_28 ;
}
int F_77 ( struct V_39 * V_88 , struct V_103 * V_104 ,
T_6 V_93 , T_7 V_105 , void * V_118 , T_4 V_119 )
{
union V_6 * V_7 ;
int V_28 ;
if ( F_18 ( & V_29 ) ) {
V_28 = - V_42 ;
goto V_41;
}
V_7 = V_6 [ F_9 () ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
if ( V_93 & V_129 ) {
V_7 -> V_137 . V_65 = V_88 -> V_62 ;
V_7 -> V_137 . V_92 = V_93 | V_140 ;
V_7 -> V_137 . V_131 = V_104 -> V_132 ;
V_7 -> V_137 . V_109 = V_105 ;
V_7 -> V_137 . V_117 = V_104 -> V_116 ;
memcpy ( V_7 -> V_137 . V_138 , V_118 , 8 ) ;
} else {
V_7 -> V_30 . V_31 = ( T_7 ) ( V_127 ) V_118 ;
V_7 -> V_30 . V_130 = ( T_7 ) V_119 ;
V_7 -> V_30 . V_65 = V_88 -> V_62 ;
V_7 -> V_30 . V_92 = V_93 | V_140 ;
V_7 -> V_30 . V_131 = V_104 -> V_132 ;
V_7 -> V_30 . V_109 = V_105 ;
V_7 -> V_30 . V_117 = V_104 -> V_116 ;
}
V_28 = F_3 ( V_141 , V_7 ) ;
if ( ! V_28 )
V_104 -> V_108 = V_7 -> V_30 . V_107 ;
V_41:
return V_28 ;
}
int F_78 ( struct V_39 * V_88 , struct V_103 * V_104 ,
T_6 V_93 , T_7 V_105 , void * V_118 , T_4 V_119 )
{
int V_28 ;
F_62 () ;
V_28 = F_77 ( V_88 , V_104 , V_93 , V_105 , V_118 , V_119 ) ;
F_63 () ;
return V_28 ;
}
int F_79 ( struct V_39 * V_88 , struct V_103 * V_104 ,
T_6 V_93 , T_7 V_105 , void * V_118 , T_4 V_119 ,
void * V_142 , T_4 V_143 , T_4 * V_120 )
{
union V_6 * V_7 ;
int V_28 ;
F_62 () ;
if ( F_18 ( & V_29 ) ) {
V_28 = - V_42 ;
goto V_41;
}
V_7 = V_6 [ F_9 () ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
if ( V_93 & V_129 ) {
V_7 -> V_137 . V_65 = V_88 -> V_62 ;
V_7 -> V_137 . V_92 = V_88 -> V_93 ;
V_7 -> V_137 . V_131 = V_104 -> V_132 ;
V_7 -> V_137 . V_109 = V_105 ;
V_7 -> V_137 . V_117 = V_104 -> V_116 ;
V_7 -> V_137 . V_144 = ( T_7 ) ( V_127 ) V_142 ;
V_7 -> V_137 . V_145 = ( T_7 ) V_143 ;
memcpy ( V_7 -> V_137 . V_138 , V_118 , 8 ) ;
} else {
V_7 -> V_30 . V_65 = V_88 -> V_62 ;
V_7 -> V_30 . V_92 = V_88 -> V_93 ;
V_7 -> V_30 . V_131 = V_104 -> V_132 ;
V_7 -> V_30 . V_109 = V_105 ;
V_7 -> V_30 . V_117 = V_104 -> V_116 ;
V_7 -> V_30 . V_31 = ( T_7 ) ( V_127 ) V_118 ;
V_7 -> V_30 . V_130 = ( T_7 ) V_119 ;
V_7 -> V_30 . V_144 = ( T_7 ) ( V_127 ) V_142 ;
V_7 -> V_30 . V_145 = ( T_7 ) V_143 ;
}
V_28 = F_3 ( V_141 , V_7 ) ;
if ( ! V_28 )
V_104 -> V_108 = V_7 -> V_30 . V_107 ;
V_41:
F_63 () ;
return V_28 ;
}
static void F_80 ( struct V_32 * V_20 )
{
struct F_80 * V_146 = ( void * ) V_20 ;
struct V_73 * V_74 ;
struct V_39 * V_88 ;
char * error ;
F_81 ( V_40 [ V_146 -> V_65 ] ) ;
error = V_147 ;
V_88 = F_82 ( V_146 -> V_90 , V_146 -> V_92 , V_148 ) ;
if ( ! V_88 )
goto V_149;
V_88 -> V_62 = V_146 -> V_65 ;
V_40 [ V_88 -> V_62 ] = V_88 ;
F_83 ( V_146 -> V_96 , 8 ) ;
F_84 (handler, &iucv_handler_list, list) {
if ( ! V_74 -> V_150 )
continue;
F_85 ( & V_88 -> V_72 , & V_74 -> V_81 ) ;
V_88 -> V_74 = V_74 ;
if ( ! V_74 -> V_150 ( V_88 , V_146 -> V_96 , V_146 -> V_64 ) )
return;
F_44 ( & V_88 -> V_72 ) ;
V_88 -> V_74 = NULL ;
}
V_40 [ V_88 -> V_62 ] = NULL ;
F_56 ( V_88 ) ;
error = V_151 ;
V_149:
F_38 ( V_146 -> V_65 , error ) ;
}
static void F_86 ( struct V_32 * V_20 )
{
struct F_86 * V_152 = ( void * ) V_20 ;
struct V_39 * V_88 = V_40 [ V_152 -> V_65 ] ;
if ( V_88 )
V_88 -> V_93 = V_152 -> V_92 ;
if ( V_88 && V_88 -> V_74 && V_88 -> V_74 -> V_153 )
V_88 -> V_74 -> V_153 ( V_88 , V_152 -> V_64 ) ;
}
static void F_87 ( struct V_32 * V_20 )
{
struct F_87 * V_154 = ( void * ) V_20 ;
struct V_39 * V_88 = V_40 [ V_154 -> V_65 ] ;
if ( ! V_88 || ! V_88 -> V_74 )
return;
if ( V_88 -> V_74 -> V_155 )
V_88 -> V_74 -> V_155 ( V_88 , V_154 -> V_64 ) ;
else {
F_38 ( V_88 -> V_62 , NULL ) ;
V_40 [ V_88 -> V_62 ] = NULL ;
F_44 ( & V_88 -> V_72 ) ;
F_56 ( V_88 ) ;
}
}
static void F_88 ( struct V_32 * V_20 )
{
struct F_88 * V_156 = ( void * ) V_20 ;
struct V_39 * V_88 = V_40 [ V_156 -> V_65 ] ;
if ( V_88 && V_88 -> V_74 && V_88 -> V_74 -> V_157 )
V_88 -> V_74 -> V_157 ( V_88 , V_156 -> V_64 ) ;
}
static void F_89 ( struct V_32 * V_20 )
{
struct F_89 * V_158 = ( void * ) V_20 ;
struct V_39 * V_88 = V_40 [ V_158 -> V_65 ] ;
if ( V_88 && V_88 -> V_74 && V_88 -> V_74 -> V_159 )
V_88 -> V_74 -> V_159 ( V_88 , V_158 -> V_64 ) ;
}
static void F_90 ( struct V_32 * V_20 )
{
struct F_90 * V_160 = ( void * ) V_20 ;
struct V_39 * V_88 = V_40 [ V_160 -> V_65 ] ;
struct V_103 V_104 ;
if ( V_88 && V_88 -> V_74 && V_88 -> V_74 -> V_161 ) {
V_104 . V_93 = V_160 -> V_92 ;
V_104 . V_108 = V_160 -> V_107 ;
V_104 . V_114 = V_160 -> V_115 ;
memcpy ( V_104 . V_123 , V_160 -> V_138 , 8 ) ;
V_104 . V_132 = V_160 -> V_109 ;
V_104 . V_116 = V_160 -> V_117 ;
V_104 . V_126 = V_160 -> V_145 ;
V_88 -> V_74 -> V_161 ( V_88 , & V_104 ) ;
}
}
static void F_91 ( struct V_32 * V_20 )
{
struct F_91 * V_162 = ( void * ) V_20 ;
struct V_39 * V_88 = V_40 [ V_162 -> V_65 ] ;
struct V_103 V_104 ;
if ( V_88 && V_88 -> V_74 && V_88 -> V_74 -> V_163 ) {
V_104 . V_93 = V_162 -> V_92 ;
V_104 . V_108 = V_162 -> V_107 ;
V_104 . V_132 = V_162 -> V_131 ;
if ( V_162 -> V_92 & V_129 ) {
memcpy ( V_104 . V_123 , V_162 -> V_164 . V_165 , 8 ) ;
V_104 . V_126 = 8 ;
} else
V_104 . V_126 = V_162 -> V_166 . V_130 ;
V_104 . V_167 = V_162 -> V_145 ;
V_88 -> V_74 -> V_163 ( V_88 , & V_104 ) ;
}
}
static void F_92 ( unsigned long V_168 )
{
typedef void T_8 ( struct V_32 * );
static T_8 * V_169 [] = {
[ 0x02 ] = F_86 ,
[ 0x03 ] = F_87 ,
[ 0x04 ] = F_88 ,
[ 0x05 ] = F_89 ,
[ 0x06 ] = F_90 ,
[ 0x07 ] = F_90 ,
[ 0x08 ] = F_91 ,
[ 0x09 ] = F_91 ,
} ;
F_93 ( V_170 ) ;
struct V_68 * V_69 , * V_70 ;
if ( ! F_94 ( & V_82 ) ) {
F_95 ( & V_171 ) ;
return;
}
V_102 = F_9 () ;
F_42 ( & V_71 ) ;
F_96 ( & V_172 , & V_170 ) ;
F_45 ( & V_71 ) ;
F_43 (p, n, &task_queue, list) {
F_55 ( & V_69 -> V_72 ) ;
V_169 [ V_69 -> V_20 . V_173 ] ( & V_69 -> V_20 ) ;
F_7 ( V_69 ) ;
}
V_102 = - 1 ;
F_97 ( & V_82 ) ;
}
static void F_98 ( struct V_174 * V_175 )
{
F_93 ( V_176 ) ;
struct V_68 * V_69 , * V_70 ;
F_50 ( & V_82 ) ;
V_102 = F_9 () ;
F_42 ( & V_71 ) ;
F_96 ( & V_177 , & V_176 ) ;
F_45 ( & V_71 ) ;
F_40 () ;
F_43 (p, n, &work_queue, list) {
F_55 ( & V_69 -> V_72 ) ;
F_80 ( & V_69 -> V_20 ) ;
F_7 ( V_69 ) ;
}
V_102 = - 1 ;
F_52 ( & V_82 ) ;
}
static void F_99 ( struct V_178 V_178 ,
unsigned int V_179 , unsigned long V_180 )
{
struct V_32 * V_69 ;
struct V_68 * V_175 ;
F_100 ( V_181 ) ;
V_69 = V_32 [ F_9 () ] ;
if ( V_69 -> V_65 >= V_18 ) {
F_101 ( V_69 -> V_65 >= V_18 ) ;
F_38 ( V_69 -> V_65 , V_151 ) ;
return;
}
F_81 ( V_69 -> V_173 < 0x01 || V_69 -> V_173 > 0x09 ) ;
V_175 = F_102 ( sizeof( struct V_68 ) , V_148 ) ;
if ( ! V_175 ) {
F_17 ( L_10 ) ;
return;
}
memcpy ( & V_175 -> V_20 , V_69 , sizeof( V_175 -> V_20 ) ) ;
F_103 ( & V_71 ) ;
if ( V_69 -> V_173 == 0x01 ) {
F_51 ( & V_175 -> V_72 , & V_177 ) ;
F_104 ( & V_182 ) ;
} else {
F_51 ( & V_175 -> V_72 , & V_172 ) ;
F_95 ( & V_171 ) ;
}
F_97 ( & V_71 ) ;
}
static int F_105 ( struct V_1 * V_2 )
{
int V_28 = 0 ;
#ifdef F_106
F_107 ( V_183 L_11 ) ;
#endif
if ( V_2 -> V_184 && V_2 -> V_184 -> V_185 && V_2 -> V_184 -> V_185 -> V_186 )
V_28 = V_2 -> V_184 -> V_185 -> V_186 ( V_2 ) ;
return V_28 ;
}
static void F_108 ( struct V_1 * V_2 )
{
#ifdef F_106
F_107 ( V_183 L_12 ) ;
#endif
if ( V_2 -> V_184 && V_2 -> V_184 -> V_185 && V_2 -> V_184 -> V_185 -> V_187 )
V_2 -> V_184 -> V_185 -> V_187 ( V_2 ) ;
}
int F_109 ( void )
{
int V_86 ;
for ( V_86 = 0 ; V_86 < V_18 ; V_86 ++ ) {
if ( V_40 [ V_86 ] )
return 0 ;
}
return 1 ;
}
static int F_110 ( struct V_1 * V_2 )
{
int V_21 ;
struct V_68 * V_69 , * V_70 ;
int V_28 = 0 ;
#ifdef F_106
F_107 ( V_188 L_13 ) ;
#endif
if ( V_189 != V_190 ) {
F_28 (cpu, &iucv_irq_cpumask)
F_23 ( V_21 , F_13 ,
NULL , 1 ) ;
F_111 ( & V_182 ) ;
F_43 (p, n, &iucv_work_queue, list) {
F_55 ( & V_69 -> V_72 ) ;
F_38 ( V_69 -> V_20 . V_65 ,
V_151 ) ;
F_7 ( V_69 ) ;
}
}
V_189 = V_190 ;
if ( V_2 -> V_184 && V_2 -> V_184 -> V_185 && V_2 -> V_184 -> V_185 -> V_191 )
V_28 = V_2 -> V_184 -> V_185 -> V_191 ( V_2 ) ;
if ( F_109 () )
F_30 () ;
return V_28 ;
}
static int F_112 ( struct V_1 * V_2 )
{
int V_28 = 0 ;
#ifdef F_106
F_107 ( V_188 L_14 ) ;
#endif
V_189 = V_192 ;
if ( ! V_40 ) {
V_28 = F_29 () ;
if ( V_28 )
goto V_41;
}
if ( F_18 ( & V_27 ) ) {
if ( V_35 )
F_8 ( NULL ) ;
else
F_20 () ;
}
if ( V_2 -> V_184 && V_2 -> V_184 -> V_185 && V_2 -> V_184 -> V_185 -> V_193 )
V_28 = V_2 -> V_184 -> V_185 -> V_193 ( V_2 ) ;
V_41:
return V_28 ;
}
static int F_113 ( struct V_1 * V_2 )
{
int V_28 = 0 ;
#ifdef F_106
F_107 ( V_188 L_15 , V_40 ) ;
#endif
if ( ( V_189 != V_194 ) && V_40 )
F_17 ( L_16 ) ;
V_189 = V_194 ;
if ( F_18 ( & V_27 ) ) {
V_28 = F_5 () ;
V_28 = F_29 () ;
if ( V_28 )
goto V_41;
}
if ( V_2 -> V_184 && V_2 -> V_184 -> V_185 && V_2 -> V_184 -> V_185 -> V_195 )
V_28 = V_2 -> V_184 -> V_185 -> V_195 ( V_2 ) ;
V_41:
return V_28 ;
}
static int T_9 F_114 ( void )
{
int V_28 ;
int V_21 ;
if ( ! V_196 ) {
V_28 = - V_197 ;
goto V_41;
}
F_115 ( 0 , 1 ) ;
V_28 = F_5 () ;
if ( V_28 )
goto V_198;
V_28 = F_116 ( V_199 , F_99 ) ;
if ( V_28 )
goto V_198;
V_200 = F_117 ( L_17 ) ;
if ( F_118 ( V_200 ) ) {
V_28 = F_119 ( V_200 ) ;
goto V_201;
}
F_120 () ;
F_22 (cpu) {
if ( F_33 ( V_21 ) ) {
V_28 = - V_17 ;
goto V_43;
}
}
V_28 = F_121 ( & V_202 ) ;
if ( V_28 )
goto V_43;
F_122 () ;
V_28 = F_123 ( & V_203 ) ;
if ( V_28 )
goto V_204;
F_65 ( V_151 , 16 ) ;
F_65 ( V_147 , 16 ) ;
F_65 ( V_99 , 16 ) ;
V_76 = 1 ;
V_28 = F_124 ( & V_205 ) ;
if ( V_28 )
goto V_206;
V_207 . V_208 = V_200 ;
V_207 . V_209 = & V_205 ;
return 0 ;
V_206:
F_125 ( & V_203 ) ;
V_204:
F_120 () ;
F_126 ( & V_202 ) ;
V_43:
F_127 (cpu)
F_32 ( V_21 ) ;
F_122 () ;
F_128 ( V_200 ) ;
V_201:
F_129 ( V_199 , F_99 ) ;
V_198:
F_130 ( 0 , 1 ) ;
V_41:
return V_28 ;
}
static void T_10 F_131 ( void )
{
struct V_68 * V_69 , * V_70 ;
int V_21 ;
F_42 ( & V_71 ) ;
F_43 (p, n, &iucv_task_queue, list)
F_7 ( V_69 ) ;
F_43 (p, n, &iucv_work_queue, list)
F_7 ( V_69 ) ;
F_45 ( & V_71 ) ;
F_125 ( & V_203 ) ;
F_120 () ;
F_126 ( & V_202 ) ;
F_127 (cpu)
F_32 ( V_21 ) ;
F_122 () ;
F_128 ( V_200 ) ;
F_132 ( & V_205 ) ;
F_129 ( V_199 , F_99 ) ;
}
