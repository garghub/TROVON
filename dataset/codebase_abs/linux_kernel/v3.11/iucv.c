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
T_2 = F_3 ( V_7 ) ;
asm volatile(
" .long 0xb2f01000\n"
" ipm %0\n"
" srl %0,28\n"
: "=d" (ccode), "=m" (*parm), "+d" (reg0), "+a" (reg1)
: "m" (*parm) : "cc");
return ( V_9 == 1 ) ? V_7 -> V_10 . V_11 : V_9 ;
}
static int F_4 ( void )
{
register unsigned long T_1 V_8 ( L_1 ) ;
register unsigned long T_2 V_8 ( L_2 ) ;
void * V_12 ;
int V_9 ;
V_12 = F_5 ( sizeof( union V_6 ) , V_13 | V_14 ) ;
if ( ! V_12 )
return - V_15 ;
T_1 = V_16 ;
T_2 = ( unsigned long ) V_12 ;
asm volatile (
" .long 0xb2f01000\n"
" ipm %0\n"
" srl %0,28\n"
: "=d" (ccode), "+d" (reg0), "+d" (reg1) : : "cc");
if ( V_9 == 0 )
V_17 = T_2 ;
F_6 ( V_12 ) ;
return V_9 ? - V_18 : 0 ;
}
static void F_7 ( void * V_19 )
{
int V_20 = F_8 () ;
union V_6 * V_7 ;
V_7 = V_21 [ V_20 ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
V_7 -> V_22 . V_23 = 0xf8 ;
F_2 ( V_24 , V_7 ) ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
V_7 -> V_22 . V_23 = 0xf8 ;
F_2 ( V_25 , V_7 ) ;
F_9 ( V_20 , & V_26 ) ;
}
static void F_10 ( void * V_19 )
{
int V_20 = F_8 () ;
union V_6 * V_7 ;
V_7 = V_21 [ V_20 ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
F_2 ( V_24 , V_7 ) ;
F_11 ( V_20 , & V_26 ) ;
}
static void F_12 ( void * V_19 )
{
int V_20 = F_8 () ;
union V_6 * V_7 ;
V_7 = V_21 [ V_20 ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
V_7 -> V_22 . V_23 = 0x08 ;
F_2 ( V_24 , V_7 ) ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
V_7 -> V_22 . V_23 = 0x20 ;
F_2 ( V_25 , V_7 ) ;
F_11 ( V_20 , & V_26 ) ;
}
static void F_13 ( void * V_19 )
{
int V_20 = F_8 () ;
union V_6 * V_7 ;
int V_27 ;
if ( F_14 ( V_20 , & V_28 ) )
return;
V_7 = V_21 [ V_20 ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
V_7 -> V_29 . V_30 = F_3 ( V_31 [ V_20 ] ) ;
V_27 = F_2 ( V_32 , V_7 ) ;
if ( V_27 ) {
char * V_33 = L_3 ;
switch ( V_27 ) {
case 0x03 :
V_33 = L_4 ;
break;
case 0x0a :
V_33 = L_5 ;
break;
case 0x13 :
V_33 = L_6 ;
break;
case 0x3e :
V_33 = L_7 ;
break;
case 0x5c :
V_33 = L_8 ;
break;
}
F_15 ( L_9
L_10 , V_20 , V_27 , V_33 ) ;
return;
}
F_9 ( V_20 , & V_28 ) ;
if ( V_34 == 0 || F_16 ( & V_26 ) )
F_7 ( NULL ) ;
else
F_10 ( NULL ) ;
}
static void F_17 ( void * V_19 )
{
int V_20 = F_8 () ;
union V_6 * V_7 ;
if ( ! F_14 ( V_20 , & V_28 ) )
return;
F_10 ( NULL ) ;
V_7 = V_21 [ V_20 ] ;
F_2 ( V_35 , V_7 ) ;
F_11 ( V_20 , & V_28 ) ;
}
static void F_18 ( void )
{
int V_20 ;
F_19 () ;
F_20 (cpu)
if ( F_14 ( V_20 , & V_28 ) &&
! F_14 ( V_20 , & V_26 ) )
F_21 ( V_20 , F_7 ,
NULL , 1 ) ;
F_22 () ;
}
static void F_23 ( void )
{
T_3 V_36 ;
int V_20 ;
F_24 ( & V_36 , & V_26 ) ;
F_11 ( F_25 ( & V_26 ) , & V_36 ) ;
F_26 (cpu, &cpumask)
F_21 ( V_20 , F_10 , NULL , 1 ) ;
}
static int F_27 ( void )
{
T_4 V_37 ;
int V_20 , V_27 ;
F_19 () ;
V_27 = - V_15 ;
V_37 = V_17 * sizeof( struct V_38 ) ;
V_39 = F_5 ( V_37 , V_13 ) ;
if ( ! V_39 )
goto V_40;
V_27 = - V_41 ;
F_20 (cpu)
F_21 ( V_20 , F_13 , NULL , 1 ) ;
if ( F_16 ( & V_28 ) )
goto V_40;
F_22 () ;
return 0 ;
V_40:
F_6 ( V_39 ) ;
V_39 = NULL ;
F_22 () ;
return V_27 ;
}
static void F_28 ( void )
{
F_19 () ;
F_29 ( F_17 , NULL , 1 ) ;
F_6 ( V_39 ) ;
V_39 = NULL ;
F_22 () ;
}
static int F_30 ( struct V_42 * V_43 ,
unsigned long V_44 , void * V_45 )
{
T_3 V_36 ;
long V_20 = ( long ) V_45 ;
switch ( V_44 ) {
case V_46 :
case V_47 :
V_31 [ V_20 ] = F_31 ( sizeof( struct V_31 ) ,
V_13 | V_14 , F_32 ( V_20 ) ) ;
if ( ! V_31 [ V_20 ] )
return F_33 ( - V_15 ) ;
V_6 [ V_20 ] = F_31 ( sizeof( union V_6 ) ,
V_13 | V_14 , F_32 ( V_20 ) ) ;
if ( ! V_6 [ V_20 ] ) {
F_6 ( V_31 [ V_20 ] ) ;
V_31 [ V_20 ] = NULL ;
return F_33 ( - V_15 ) ;
}
V_21 [ V_20 ] = F_31 ( sizeof( union V_6 ) ,
V_13 | V_14 , F_32 ( V_20 ) ) ;
if ( ! V_21 [ V_20 ] ) {
F_6 ( V_6 [ V_20 ] ) ;
V_6 [ V_20 ] = NULL ;
F_6 ( V_31 [ V_20 ] ) ;
V_31 [ V_20 ] = NULL ;
return F_33 ( - V_15 ) ;
}
break;
case V_48 :
case V_49 :
case V_50 :
case V_51 :
F_6 ( V_21 [ V_20 ] ) ;
V_21 [ V_20 ] = NULL ;
F_6 ( V_6 [ V_20 ] ) ;
V_6 [ V_20 ] = NULL ;
F_6 ( V_31 [ V_20 ] ) ;
V_31 [ V_20 ] = NULL ;
break;
case V_52 :
case V_53 :
case V_54 :
case V_55 :
if ( ! V_39 )
break;
F_21 ( V_20 , F_13 , NULL , 1 ) ;
break;
case V_56 :
case V_57 :
if ( ! V_39 )
break;
F_24 ( & V_36 , & V_28 ) ;
F_11 ( V_20 , & V_36 ) ;
if ( F_16 ( & V_36 ) )
return F_33 ( - V_58 ) ;
F_21 ( V_20 , F_17 , NULL , 1 ) ;
if ( F_16 ( & V_26 ) )
F_21 (
F_25 ( & V_28 ) ,
F_7 , NULL , 1 ) ;
break;
}
return V_59 ;
}
static int F_34 ( T_5 V_60 , T_6 V_61 [ 16 ] )
{
union V_6 * V_7 ;
V_7 = V_21 [ F_8 () ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
if ( V_61 )
memcpy ( V_7 -> V_10 . V_62 , V_61 , sizeof( V_7 -> V_10 . V_62 ) ) ;
V_7 -> V_10 . V_63 = V_60 ;
return F_2 ( V_64 , V_7 ) ;
}
static void F_35 ( void * V_65 )
{
}
static void F_36 ( void )
{
struct V_66 * V_67 , * V_68 ;
F_37 ( F_35 , NULL , 1 ) ;
F_38 ( & V_69 ) ;
F_39 (p, n, &iucv_task_queue, list) {
if ( V_39 [ V_67 -> V_19 . V_63 ] == NULL ) {
F_40 ( & V_67 -> V_70 ) ;
F_6 ( V_67 ) ;
}
}
F_41 ( & V_69 ) ;
}
int F_42 ( struct V_71 * V_72 , int V_73 )
{
int V_27 ;
if ( ! V_74 )
return - V_75 ;
F_43 ( & V_76 ) ;
if ( ! V_73 )
V_34 ++ ;
if ( F_44 ( & V_77 ) ) {
V_27 = F_27 () ;
if ( V_27 )
goto V_78;
} else if ( ! V_73 && V_34 == 1 )
F_23 () ;
F_45 ( & V_72 -> V_79 ) ;
F_46 ( & V_80 ) ;
F_47 ( & V_72 -> V_70 , & V_77 ) ;
F_48 ( & V_80 ) ;
V_27 = 0 ;
V_78:
F_49 ( & V_76 ) ;
return V_27 ;
}
void F_50 ( struct V_71 * V_72 , int V_73 )
{
struct V_38 * V_67 , * V_68 ;
F_43 ( & V_76 ) ;
F_46 ( & V_80 ) ;
F_51 ( & V_72 -> V_70 ) ;
F_39 (p, n, &handler->paths, list) {
F_34 ( V_67 -> V_60 , NULL ) ;
V_39 [ V_67 -> V_60 ] = NULL ;
F_40 ( & V_67 -> V_70 ) ;
F_52 ( V_67 ) ;
}
F_48 ( & V_80 ) ;
if ( ! V_73 )
V_34 -- ;
if ( F_44 ( & V_77 ) )
F_28 () ;
else if ( ! V_73 && V_34 == 0 )
F_18 () ;
F_49 ( & V_76 ) ;
}
static int F_53 ( struct V_42 * V_81 ,
unsigned long V_82 , void * V_83 )
{
int V_84 ;
if ( F_16 ( & V_26 ) )
return V_85 ;
F_19 () ;
F_54 ( & V_26 , F_10 , NULL , 1 ) ;
F_55 () ;
for ( V_84 = 0 ; V_84 < V_17 ; V_84 ++ ) {
if ( V_39 [ V_84 ] )
F_34 ( V_84 , NULL ) ;
}
F_56 () ;
F_22 () ;
F_28 () ;
return V_85 ;
}
int F_57 ( struct V_38 * V_86 , struct V_71 * V_72 ,
T_6 V_61 [ 16 ] , void * V_87 )
{
union V_6 * V_7 ;
int V_27 ;
F_58 () ;
if ( F_16 ( & V_28 ) ) {
V_27 = - V_41 ;
goto V_40;
}
V_7 = V_6 [ F_8 () ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
V_7 -> V_10 . V_63 = V_86 -> V_60 ;
V_7 -> V_10 . V_88 = V_86 -> V_89 ;
if ( V_61 )
memcpy ( V_7 -> V_10 . V_62 , V_61 , sizeof( V_7 -> V_10 . V_62 ) ) ;
V_7 -> V_10 . V_90 = V_86 -> V_91 ;
V_27 = F_2 ( V_92 , V_7 ) ;
if ( ! V_27 ) {
V_86 -> V_87 = V_87 ;
V_86 -> V_89 = V_7 -> V_10 . V_88 ;
V_86 -> V_91 = V_7 -> V_10 . V_90 ;
}
V_40:
F_59 () ;
return V_27 ;
}
int F_60 ( struct V_38 * V_86 , struct V_71 * V_72 ,
T_6 V_93 [ 8 ] , T_6 system [ 8 ] , T_6 V_61 [ 16 ] ,
void * V_87 )
{
union V_6 * V_7 ;
int V_27 ;
F_46 ( & V_80 ) ;
F_36 () ;
if ( F_16 ( & V_28 ) ) {
V_27 = - V_41 ;
goto V_40;
}
V_7 = V_6 [ F_8 () ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
V_7 -> V_10 . V_88 = V_86 -> V_89 ;
V_7 -> V_10 . V_90 = V_86 -> V_91 ;
if ( V_93 ) {
memcpy ( V_7 -> V_10 . V_94 , V_93 , sizeof( V_7 -> V_10 . V_94 ) ) ;
F_61 ( V_7 -> V_10 . V_94 , sizeof( V_7 -> V_10 . V_94 ) ) ;
F_62 ( V_7 -> V_10 . V_94 , sizeof( V_7 -> V_10 . V_94 ) ) ;
}
if ( system ) {
memcpy ( V_7 -> V_10 . V_95 , system ,
sizeof( V_7 -> V_10 . V_95 ) ) ;
F_61 ( V_7 -> V_10 . V_95 , sizeof( V_7 -> V_10 . V_95 ) ) ;
F_62 ( V_7 -> V_10 . V_95 , sizeof( V_7 -> V_10 . V_95 ) ) ;
}
if ( V_61 )
memcpy ( V_7 -> V_10 . V_62 , V_61 , sizeof( V_7 -> V_10 . V_62 ) ) ;
V_27 = F_2 ( V_96 , V_7 ) ;
if ( ! V_27 ) {
if ( V_7 -> V_10 . V_63 < V_17 ) {
V_86 -> V_60 = V_7 -> V_10 . V_63 ;
V_86 -> V_89 = V_7 -> V_10 . V_88 ;
V_86 -> V_91 = V_7 -> V_10 . V_90 ;
V_86 -> V_72 = V_72 ;
V_86 -> V_87 = V_87 ;
F_47 ( & V_86 -> V_70 , & V_72 -> V_79 ) ;
V_39 [ V_86 -> V_60 ] = V_86 ;
} else {
F_34 ( V_7 -> V_10 . V_63 ,
V_97 ) ;
V_27 = - V_41 ;
}
}
V_40:
F_48 ( & V_80 ) ;
return V_27 ;
}
int F_63 ( struct V_38 * V_86 , T_6 V_61 [ 16 ] )
{
union V_6 * V_7 ;
int V_27 ;
F_58 () ;
if ( F_16 ( & V_28 ) ) {
V_27 = - V_41 ;
goto V_40;
}
V_7 = V_6 [ F_8 () ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
if ( V_61 )
memcpy ( V_7 -> V_10 . V_62 , V_61 , sizeof( V_7 -> V_10 . V_62 ) ) ;
V_7 -> V_10 . V_63 = V_86 -> V_60 ;
V_27 = F_2 ( V_98 , V_7 ) ;
V_40:
F_59 () ;
return V_27 ;
}
int F_64 ( struct V_38 * V_86 , T_6 V_61 [ 16 ] )
{
union V_6 * V_7 ;
int V_27 ;
F_58 () ;
if ( F_16 ( & V_28 ) ) {
V_27 = - V_41 ;
goto V_40;
}
V_7 = V_6 [ F_8 () ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
if ( V_61 )
memcpy ( V_7 -> V_10 . V_62 , V_61 , sizeof( V_7 -> V_10 . V_62 ) ) ;
V_7 -> V_10 . V_63 = V_86 -> V_60 ;
V_27 = F_2 ( V_99 , V_7 ) ;
V_40:
F_59 () ;
return V_27 ;
}
int F_65 ( struct V_38 * V_86 , T_6 V_61 [ 16 ] )
{
int V_27 ;
F_55 () ;
if ( F_16 ( & V_28 ) ) {
V_27 = - V_41 ;
goto V_40;
}
if ( V_100 != F_8 () )
F_46 ( & V_80 ) ;
V_27 = F_34 ( V_86 -> V_60 , V_61 ) ;
V_39 [ V_86 -> V_60 ] = NULL ;
F_51 ( & V_86 -> V_70 ) ;
if ( V_100 != F_8 () )
F_48 ( & V_80 ) ;
V_40:
F_56 () ;
return V_27 ;
}
int F_66 ( struct V_38 * V_86 , struct V_101 * V_102 ,
T_7 V_103 )
{
union V_6 * V_7 ;
int V_27 ;
F_58 () ;
if ( F_16 ( & V_28 ) ) {
V_27 = - V_41 ;
goto V_40;
}
V_7 = V_6 [ F_8 () ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
V_7 -> V_104 . V_63 = V_86 -> V_60 ;
V_7 -> V_104 . V_105 = V_102 -> V_106 ;
V_7 -> V_104 . V_107 = V_103 ;
V_7 -> V_104 . V_90 = V_108 | V_109 | V_110 ;
V_27 = F_2 ( V_111 , V_7 ) ;
if ( ! V_27 ) {
V_102 -> V_112 = ( * ( T_7 * ) & V_7 -> V_104 . V_113 ) >> 8 ;
V_102 -> V_114 = V_7 -> V_104 . V_115 ;
}
V_40:
F_59 () ;
return V_27 ;
}
static int F_67 ( struct V_38 * V_86 ,
struct V_101 * V_102 ,
T_6 V_91 , void * V_116 ,
T_4 V_117 , T_4 * V_118 )
{
struct V_119 * V_120 ;
T_6 * V_121 ;
T_4 V_122 ;
if ( V_118 )
* V_118 = abs ( V_117 - 8 ) ;
V_121 = V_102 -> V_121 ;
if ( V_91 & V_123 ) {
V_117 = ( V_117 < 8 ) ? V_117 : 8 ;
for ( V_120 = V_116 ; V_117 > 0 ; V_120 ++ ) {
V_122 = F_68 ( T_4 , V_117 , V_120 -> V_124 ) ;
memcpy ( ( T_6 * ) ( V_125 ) V_120 -> V_126 ,
V_121 , V_122 ) ;
V_121 += V_122 ;
V_117 -= V_122 ;
}
} else {
memcpy ( V_116 , V_121 , F_68 ( T_4 , V_117 , 8 ) ) ;
}
return 0 ;
}
int F_69 ( struct V_38 * V_86 , struct V_101 * V_102 ,
T_6 V_91 , void * V_116 , T_4 V_117 , T_4 * V_118 )
{
union V_6 * V_7 ;
int V_27 ;
if ( V_102 -> V_91 & V_127 )
return F_67 ( V_86 , V_102 , V_91 ,
V_116 , V_117 , V_118 ) ;
if ( F_16 ( & V_28 ) ) {
V_27 = - V_41 ;
goto V_40;
}
V_7 = V_6 [ F_8 () ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
V_7 -> V_29 . V_30 = ( T_7 ) ( V_125 ) V_116 ;
V_7 -> V_29 . V_128 = ( T_7 ) V_117 ;
V_7 -> V_29 . V_105 = V_102 -> V_106 ;
V_7 -> V_29 . V_63 = V_86 -> V_60 ;
V_7 -> V_29 . V_129 = V_102 -> V_130 ;
V_7 -> V_29 . V_90 = ( V_91 | V_110 |
V_109 | V_131 ) ;
V_27 = F_2 ( V_132 , V_7 ) ;
if ( ! V_27 || V_27 == 5 ) {
V_102 -> V_91 = V_7 -> V_29 . V_90 ;
if ( V_118 )
* V_118 = V_7 -> V_29 . V_128 ;
}
V_40:
return V_27 ;
}
int F_70 ( struct V_38 * V_86 , struct V_101 * V_102 ,
T_6 V_91 , void * V_116 , T_4 V_117 , T_4 * V_118 )
{
int V_27 ;
if ( V_102 -> V_91 & V_127 )
return F_67 ( V_86 , V_102 , V_91 ,
V_116 , V_117 , V_118 ) ;
F_58 () ;
V_27 = F_69 ( V_86 , V_102 , V_91 , V_116 , V_117 , V_118 ) ;
F_59 () ;
return V_27 ;
}
int F_71 ( struct V_38 * V_86 , struct V_101 * V_102 )
{
union V_6 * V_7 ;
int V_27 ;
F_58 () ;
if ( F_16 ( & V_28 ) ) {
V_27 = - V_41 ;
goto V_40;
}
V_7 = V_6 [ F_8 () ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
V_7 -> V_29 . V_63 = V_86 -> V_60 ;
V_7 -> V_29 . V_105 = V_102 -> V_106 ;
V_7 -> V_29 . V_129 = V_102 -> V_130 ;
V_7 -> V_29 . V_90 = ( V_131 | V_109 | V_110 ) ;
V_27 = F_2 ( V_133 , V_7 ) ;
V_40:
F_59 () ;
return V_27 ;
}
int F_72 ( struct V_38 * V_86 , struct V_101 * V_102 ,
T_6 V_91 , void * V_134 , T_4 V_117 )
{
union V_6 * V_7 ;
int V_27 ;
F_58 () ;
if ( F_16 ( & V_28 ) ) {
V_27 = - V_41 ;
goto V_40;
}
V_7 = V_6 [ F_8 () ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
if ( V_91 & V_127 ) {
V_7 -> V_135 . V_63 = V_86 -> V_60 ;
V_7 -> V_135 . V_90 = V_91 ;
V_7 -> V_135 . V_105 = V_102 -> V_106 ;
V_7 -> V_135 . V_129 = V_102 -> V_130 ;
memcpy ( V_7 -> V_135 . V_136 , V_134 , F_68 ( T_4 , V_117 , 8 ) ) ;
} else {
V_7 -> V_29 . V_30 = ( T_7 ) ( V_125 ) V_134 ;
V_7 -> V_29 . V_128 = ( T_7 ) V_117 ;
V_7 -> V_29 . V_63 = V_86 -> V_60 ;
V_7 -> V_29 . V_90 = V_91 ;
V_7 -> V_29 . V_105 = V_102 -> V_106 ;
V_7 -> V_29 . V_129 = V_102 -> V_130 ;
}
V_27 = F_2 ( V_137 , V_7 ) ;
V_40:
F_59 () ;
return V_27 ;
}
int F_73 ( struct V_38 * V_86 , struct V_101 * V_102 ,
T_6 V_91 , T_7 V_103 , void * V_116 , T_4 V_117 )
{
union V_6 * V_7 ;
int V_27 ;
if ( F_16 ( & V_28 ) ) {
V_27 = - V_41 ;
goto V_40;
}
V_7 = V_6 [ F_8 () ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
if ( V_91 & V_127 ) {
V_7 -> V_135 . V_63 = V_86 -> V_60 ;
V_7 -> V_135 . V_90 = V_91 | V_138 ;
V_7 -> V_135 . V_129 = V_102 -> V_130 ;
V_7 -> V_135 . V_107 = V_103 ;
V_7 -> V_135 . V_115 = V_102 -> V_114 ;
memcpy ( V_7 -> V_135 . V_136 , V_116 , 8 ) ;
} else {
V_7 -> V_29 . V_30 = ( T_7 ) ( V_125 ) V_116 ;
V_7 -> V_29 . V_128 = ( T_7 ) V_117 ;
V_7 -> V_29 . V_63 = V_86 -> V_60 ;
V_7 -> V_29 . V_90 = V_91 | V_138 ;
V_7 -> V_29 . V_129 = V_102 -> V_130 ;
V_7 -> V_29 . V_107 = V_103 ;
V_7 -> V_29 . V_115 = V_102 -> V_114 ;
}
V_27 = F_2 ( V_139 , V_7 ) ;
if ( ! V_27 )
V_102 -> V_106 = V_7 -> V_29 . V_105 ;
V_40:
return V_27 ;
}
int F_74 ( struct V_38 * V_86 , struct V_101 * V_102 ,
T_6 V_91 , T_7 V_103 , void * V_116 , T_4 V_117 )
{
int V_27 ;
F_58 () ;
V_27 = F_73 ( V_86 , V_102 , V_91 , V_103 , V_116 , V_117 ) ;
F_59 () ;
return V_27 ;
}
int F_75 ( struct V_38 * V_86 , struct V_101 * V_102 ,
T_6 V_91 , T_7 V_103 , void * V_116 , T_4 V_117 ,
void * V_140 , T_4 V_141 , T_4 * V_118 )
{
union V_6 * V_7 ;
int V_27 ;
F_58 () ;
if ( F_16 ( & V_28 ) ) {
V_27 = - V_41 ;
goto V_40;
}
V_7 = V_6 [ F_8 () ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
if ( V_91 & V_127 ) {
V_7 -> V_135 . V_63 = V_86 -> V_60 ;
V_7 -> V_135 . V_90 = V_86 -> V_91 ;
V_7 -> V_135 . V_129 = V_102 -> V_130 ;
V_7 -> V_135 . V_107 = V_103 ;
V_7 -> V_135 . V_115 = V_102 -> V_114 ;
V_7 -> V_135 . V_142 = ( T_7 ) ( V_125 ) V_140 ;
V_7 -> V_135 . V_143 = ( T_7 ) V_141 ;
memcpy ( V_7 -> V_135 . V_136 , V_116 , 8 ) ;
} else {
V_7 -> V_29 . V_63 = V_86 -> V_60 ;
V_7 -> V_29 . V_90 = V_86 -> V_91 ;
V_7 -> V_29 . V_129 = V_102 -> V_130 ;
V_7 -> V_29 . V_107 = V_103 ;
V_7 -> V_29 . V_115 = V_102 -> V_114 ;
V_7 -> V_29 . V_30 = ( T_7 ) ( V_125 ) V_116 ;
V_7 -> V_29 . V_128 = ( T_7 ) V_117 ;
V_7 -> V_29 . V_142 = ( T_7 ) ( V_125 ) V_140 ;
V_7 -> V_29 . V_143 = ( T_7 ) V_141 ;
}
V_27 = F_2 ( V_139 , V_7 ) ;
if ( ! V_27 )
V_102 -> V_106 = V_7 -> V_29 . V_105 ;
V_40:
F_59 () ;
return V_27 ;
}
static void F_76 ( struct V_31 * V_19 )
{
struct F_76 * V_144 = ( void * ) V_19 ;
struct V_71 * V_72 ;
struct V_38 * V_86 ;
char * error ;
F_77 ( V_39 [ V_144 -> V_63 ] ) ;
error = V_145 ;
V_86 = F_78 ( V_144 -> V_88 , V_144 -> V_90 , V_146 ) ;
if ( ! V_86 )
goto V_147;
V_86 -> V_60 = V_144 -> V_63 ;
V_39 [ V_86 -> V_60 ] = V_86 ;
F_79 ( V_144 -> V_94 , 8 ) ;
F_80 (handler, &iucv_handler_list, list) {
if ( ! V_72 -> V_148 )
continue;
F_81 ( & V_86 -> V_70 , & V_72 -> V_79 ) ;
V_86 -> V_72 = V_72 ;
if ( ! V_72 -> V_148 ( V_86 , V_144 -> V_94 , V_144 -> V_62 ) )
return;
F_40 ( & V_86 -> V_70 ) ;
V_86 -> V_72 = NULL ;
}
V_39 [ V_86 -> V_60 ] = NULL ;
F_52 ( V_86 ) ;
error = V_149 ;
V_147:
F_34 ( V_144 -> V_63 , error ) ;
}
static void F_82 ( struct V_31 * V_19 )
{
struct F_82 * V_150 = ( void * ) V_19 ;
struct V_38 * V_86 = V_39 [ V_150 -> V_63 ] ;
if ( V_86 )
V_86 -> V_91 = V_150 -> V_90 ;
if ( V_86 && V_86 -> V_72 && V_86 -> V_72 -> V_151 )
V_86 -> V_72 -> V_151 ( V_86 , V_150 -> V_62 ) ;
}
static void F_83 ( struct V_31 * V_19 )
{
struct F_83 * V_152 = ( void * ) V_19 ;
struct V_38 * V_86 = V_39 [ V_152 -> V_63 ] ;
if ( ! V_86 || ! V_86 -> V_72 )
return;
if ( V_86 -> V_72 -> V_153 )
V_86 -> V_72 -> V_153 ( V_86 , V_152 -> V_62 ) ;
else {
F_34 ( V_86 -> V_60 , NULL ) ;
V_39 [ V_86 -> V_60 ] = NULL ;
F_40 ( & V_86 -> V_70 ) ;
F_52 ( V_86 ) ;
}
}
static void F_84 ( struct V_31 * V_19 )
{
struct F_84 * V_154 = ( void * ) V_19 ;
struct V_38 * V_86 = V_39 [ V_154 -> V_63 ] ;
if ( V_86 && V_86 -> V_72 && V_86 -> V_72 -> V_155 )
V_86 -> V_72 -> V_155 ( V_86 , V_154 -> V_62 ) ;
}
static void F_85 ( struct V_31 * V_19 )
{
struct F_85 * V_156 = ( void * ) V_19 ;
struct V_38 * V_86 = V_39 [ V_156 -> V_63 ] ;
if ( V_86 && V_86 -> V_72 && V_86 -> V_72 -> V_157 )
V_86 -> V_72 -> V_157 ( V_86 , V_156 -> V_62 ) ;
}
static void F_86 ( struct V_31 * V_19 )
{
struct F_86 * V_158 = ( void * ) V_19 ;
struct V_38 * V_86 = V_39 [ V_158 -> V_63 ] ;
struct V_101 V_102 ;
if ( V_86 && V_86 -> V_72 && V_86 -> V_72 -> V_159 ) {
V_102 . V_91 = V_158 -> V_90 ;
V_102 . V_106 = V_158 -> V_105 ;
V_102 . V_112 = V_158 -> V_113 ;
memcpy ( V_102 . V_121 , V_158 -> V_136 , 8 ) ;
V_102 . V_130 = V_158 -> V_107 ;
V_102 . V_114 = V_158 -> V_115 ;
V_102 . V_124 = V_158 -> V_143 ;
V_86 -> V_72 -> V_159 ( V_86 , & V_102 ) ;
}
}
static void F_87 ( struct V_31 * V_19 )
{
struct F_87 * V_160 = ( void * ) V_19 ;
struct V_38 * V_86 = V_39 [ V_160 -> V_63 ] ;
struct V_101 V_102 ;
if ( V_86 && V_86 -> V_72 && V_86 -> V_72 -> V_161 ) {
V_102 . V_91 = V_160 -> V_90 ;
V_102 . V_106 = V_160 -> V_105 ;
V_102 . V_130 = V_160 -> V_129 ;
if ( V_160 -> V_90 & V_127 ) {
memcpy ( V_102 . V_121 , V_160 -> V_162 . V_163 , 8 ) ;
V_102 . V_124 = 8 ;
} else
V_102 . V_124 = V_160 -> V_164 . V_128 ;
V_102 . V_165 = V_160 -> V_143 ;
V_86 -> V_72 -> V_161 ( V_86 , & V_102 ) ;
}
}
static void F_88 ( unsigned long V_166 )
{
typedef void T_8 ( struct V_31 * );
static T_8 * V_167 [] = {
[ 0x02 ] = F_82 ,
[ 0x03 ] = F_83 ,
[ 0x04 ] = F_84 ,
[ 0x05 ] = F_85 ,
[ 0x06 ] = F_86 ,
[ 0x07 ] = F_86 ,
[ 0x08 ] = F_87 ,
[ 0x09 ] = F_87 ,
} ;
F_89 ( V_168 ) ;
struct V_66 * V_67 , * V_68 ;
if ( ! F_90 ( & V_80 ) ) {
F_91 ( & V_169 ) ;
return;
}
V_100 = F_8 () ;
F_38 ( & V_69 ) ;
F_92 ( & V_170 , & V_168 ) ;
F_41 ( & V_69 ) ;
F_39 (p, n, &task_queue, list) {
F_51 ( & V_67 -> V_70 ) ;
V_167 [ V_67 -> V_19 . V_171 ] ( & V_67 -> V_19 ) ;
F_6 ( V_67 ) ;
}
V_100 = - 1 ;
F_93 ( & V_80 ) ;
}
static void F_94 ( struct V_172 * V_173 )
{
F_89 ( V_174 ) ;
struct V_66 * V_67 , * V_68 ;
F_46 ( & V_80 ) ;
V_100 = F_8 () ;
F_38 ( & V_69 ) ;
F_92 ( & V_175 , & V_174 ) ;
F_41 ( & V_69 ) ;
F_36 () ;
F_39 (p, n, &work_queue, list) {
F_51 ( & V_67 -> V_70 ) ;
F_76 ( & V_67 -> V_19 ) ;
F_6 ( V_67 ) ;
}
V_100 = - 1 ;
F_48 ( & V_80 ) ;
}
static void F_95 ( struct V_176 V_176 ,
unsigned int V_177 , unsigned long V_178 )
{
struct V_31 * V_67 ;
struct V_66 * V_173 ;
F_96 ( V_179 ) ;
V_67 = V_31 [ F_8 () ] ;
if ( V_67 -> V_63 >= V_17 ) {
F_97 ( V_67 -> V_63 >= V_17 ) ;
F_34 ( V_67 -> V_63 , V_149 ) ;
return;
}
F_77 ( V_67 -> V_171 < 0x01 || V_67 -> V_171 > 0x09 ) ;
V_173 = F_98 ( sizeof( struct V_66 ) , V_146 ) ;
if ( ! V_173 ) {
F_15 ( L_11 ) ;
return;
}
memcpy ( & V_173 -> V_19 , V_67 , sizeof( V_173 -> V_19 ) ) ;
F_99 ( & V_69 ) ;
if ( V_67 -> V_171 == 0x01 ) {
F_47 ( & V_173 -> V_70 , & V_175 ) ;
F_100 ( & V_180 ) ;
} else {
F_47 ( & V_173 -> V_70 , & V_170 ) ;
F_91 ( & V_169 ) ;
}
F_93 ( & V_69 ) ;
}
static int F_101 ( struct V_1 * V_2 )
{
int V_27 = 0 ;
#ifdef F_102
F_103 ( V_181 L_12 ) ;
#endif
if ( V_2 -> V_182 && V_2 -> V_182 -> V_183 && V_2 -> V_182 -> V_183 -> V_184 )
V_27 = V_2 -> V_182 -> V_183 -> V_184 ( V_2 ) ;
return V_27 ;
}
static void F_104 ( struct V_1 * V_2 )
{
#ifdef F_102
F_103 ( V_181 L_13 ) ;
#endif
if ( V_2 -> V_182 && V_2 -> V_182 -> V_183 && V_2 -> V_182 -> V_183 -> V_185 )
V_2 -> V_182 -> V_183 -> V_185 ( V_2 ) ;
}
int F_105 ( void )
{
int V_84 ;
for ( V_84 = 0 ; V_84 < V_17 ; V_84 ++ ) {
if ( V_39 [ V_84 ] )
return 0 ;
}
return 1 ;
}
static int F_106 ( struct V_1 * V_2 )
{
int V_20 ;
struct V_66 * V_67 , * V_68 ;
int V_27 = 0 ;
#ifdef F_102
F_103 ( V_186 L_14 ) ;
#endif
if ( V_187 != V_188 ) {
F_26 (cpu, &iucv_irq_cpumask)
F_21 ( V_20 , F_12 ,
NULL , 1 ) ;
F_107 ( & V_180 ) ;
F_39 (p, n, &iucv_work_queue, list) {
F_51 ( & V_67 -> V_70 ) ;
F_34 ( V_67 -> V_19 . V_63 ,
V_149 ) ;
F_6 ( V_67 ) ;
}
}
V_187 = V_188 ;
if ( V_2 -> V_182 && V_2 -> V_182 -> V_183 && V_2 -> V_182 -> V_183 -> V_189 )
V_27 = V_2 -> V_182 -> V_183 -> V_189 ( V_2 ) ;
if ( F_105 () )
F_28 () ;
return V_27 ;
}
static int F_108 ( struct V_1 * V_2 )
{
int V_27 = 0 ;
#ifdef F_102
F_103 ( V_186 L_15 ) ;
#endif
V_187 = V_190 ;
if ( ! V_39 ) {
V_27 = F_27 () ;
if ( V_27 )
goto V_40;
}
if ( F_16 ( & V_26 ) ) {
if ( V_34 )
F_7 ( NULL ) ;
else
F_18 () ;
}
if ( V_2 -> V_182 && V_2 -> V_182 -> V_183 && V_2 -> V_182 -> V_183 -> V_191 )
V_27 = V_2 -> V_182 -> V_183 -> V_191 ( V_2 ) ;
V_40:
return V_27 ;
}
static int F_109 ( struct V_1 * V_2 )
{
int V_27 = 0 ;
#ifdef F_102
F_103 ( V_186 L_16 , V_39 ) ;
#endif
if ( ( V_187 != V_192 ) && V_39 )
F_15 ( L_17
L_18 ) ;
V_187 = V_192 ;
if ( F_16 ( & V_26 ) ) {
V_27 = F_4 () ;
V_27 = F_27 () ;
if ( V_27 )
goto V_40;
}
if ( V_2 -> V_182 && V_2 -> V_182 -> V_183 && V_2 -> V_182 -> V_183 -> V_193 )
V_27 = V_2 -> V_182 -> V_183 -> V_193 ( V_2 ) ;
V_40:
return V_27 ;
}
static int T_9 F_110 ( void )
{
int V_27 ;
int V_20 ;
if ( ! V_194 ) {
V_27 = - V_195 ;
goto V_40;
}
F_111 ( 0 , 1 ) ;
V_27 = F_4 () ;
if ( V_27 )
goto V_196;
V_27 = F_112 ( 0x4000 , F_95 ) ;
if ( V_27 )
goto V_196;
V_197 = F_113 ( L_19 ) ;
if ( F_114 ( V_197 ) ) {
V_27 = F_115 ( V_197 ) ;
goto V_198;
}
F_20 (cpu) {
V_31 [ V_20 ] = F_31 ( sizeof( struct V_31 ) ,
V_13 | V_14 , F_32 ( V_20 ) ) ;
if ( ! V_31 [ V_20 ] ) {
V_27 = - V_15 ;
goto V_199;
}
V_6 [ V_20 ] = F_31 ( sizeof( union V_6 ) ,
V_13 | V_14 , F_32 ( V_20 ) ) ;
if ( ! V_6 [ V_20 ] ) {
V_27 = - V_15 ;
goto V_199;
}
V_21 [ V_20 ] = F_31 ( sizeof( union V_6 ) ,
V_13 | V_14 , F_32 ( V_20 ) ) ;
if ( ! V_21 [ V_20 ] ) {
V_27 = - V_15 ;
goto V_199;
}
}
V_27 = F_116 ( & V_200 ) ;
if ( V_27 )
goto V_199;
V_27 = F_117 ( & V_201 ) ;
if ( V_27 )
goto V_202;
F_61 ( V_149 , 16 ) ;
F_61 ( V_145 , 16 ) ;
F_61 ( V_97 , 16 ) ;
V_74 = 1 ;
V_27 = F_118 ( & V_203 ) ;
if ( V_27 )
goto V_204;
V_205 . V_206 = V_197 ;
V_205 . V_207 = & V_203 ;
return 0 ;
V_204:
F_119 ( & V_201 ) ;
V_202:
F_120 ( & V_200 ) ;
V_199:
F_121 (cpu) {
F_6 ( V_21 [ V_20 ] ) ;
V_21 [ V_20 ] = NULL ;
F_6 ( V_6 [ V_20 ] ) ;
V_6 [ V_20 ] = NULL ;
F_6 ( V_31 [ V_20 ] ) ;
V_31 [ V_20 ] = NULL ;
}
F_122 ( V_197 ) ;
V_198:
F_123 ( 0x4000 , F_95 ) ;
V_196:
F_124 ( 0 , 1 ) ;
V_40:
return V_27 ;
}
static void T_10 F_125 ( void )
{
struct V_66 * V_67 , * V_68 ;
int V_20 ;
F_38 ( & V_69 ) ;
F_39 (p, n, &iucv_task_queue, list)
F_6 ( V_67 ) ;
F_39 (p, n, &iucv_work_queue, list)
F_6 ( V_67 ) ;
F_41 ( & V_69 ) ;
F_119 ( & V_201 ) ;
F_120 ( & V_200 ) ;
F_121 (cpu) {
F_6 ( V_21 [ V_20 ] ) ;
V_21 [ V_20 ] = NULL ;
F_6 ( V_6 [ V_20 ] ) ;
V_6 [ V_20 ] = NULL ;
F_6 ( V_31 [ V_20 ] ) ;
V_31 [ V_20 ] = NULL ;
}
F_122 ( V_197 ) ;
F_126 ( & V_203 ) ;
F_123 ( 0x4000 , F_95 ) ;
}
