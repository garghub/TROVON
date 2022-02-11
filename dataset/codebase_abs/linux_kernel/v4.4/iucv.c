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
F_15 ( L_9 ,
V_20 , V_27 , V_33 ) ;
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
static void F_30 ( int V_20 )
{
F_6 ( V_21 [ V_20 ] ) ;
V_21 [ V_20 ] = NULL ;
F_6 ( V_6 [ V_20 ] ) ;
V_6 [ V_20 ] = NULL ;
F_6 ( V_31 [ V_20 ] ) ;
V_31 [ V_20 ] = NULL ;
}
static int F_31 ( int V_20 )
{
V_31 [ V_20 ] = F_32 ( sizeof( struct V_31 ) ,
V_13 | V_14 , F_33 ( V_20 ) ) ;
if ( ! V_31 [ V_20 ] )
goto V_42;
V_6 [ V_20 ] = F_32 ( sizeof( union V_6 ) ,
V_13 | V_14 , F_33 ( V_20 ) ) ;
if ( ! V_6 [ V_20 ] )
goto V_42;
V_21 [ V_20 ] = F_32 ( sizeof( union V_6 ) ,
V_13 | V_14 , F_33 ( V_20 ) ) ;
if ( ! V_21 [ V_20 ] )
goto V_42;
return 0 ;
V_42:
F_30 ( V_20 ) ;
return - V_15 ;
}
static int F_34 ( struct V_43 * V_44 ,
unsigned long V_45 , void * V_46 )
{
T_3 V_36 ;
long V_20 = ( long ) V_46 ;
switch ( V_45 ) {
case V_47 :
case V_48 :
if ( F_31 ( V_20 ) )
return F_35 ( - V_15 ) ;
break;
case V_49 :
case V_50 :
case V_51 :
case V_52 :
F_30 ( V_20 ) ;
break;
case V_53 :
case V_54 :
case V_55 :
case V_56 :
if ( ! V_39 )
break;
F_21 ( V_20 , F_13 , NULL , 1 ) ;
break;
case V_57 :
case V_58 :
if ( ! V_39 )
break;
F_24 ( & V_36 , & V_28 ) ;
F_11 ( V_20 , & V_36 ) ;
if ( F_16 ( & V_36 ) )
return F_35 ( - V_59 ) ;
F_21 ( V_20 , F_17 , NULL , 1 ) ;
if ( F_16 ( & V_26 ) )
F_21 (
F_25 ( & V_28 ) ,
F_7 , NULL , 1 ) ;
break;
}
return V_60 ;
}
static int F_36 ( T_5 V_61 , T_6 * V_62 )
{
union V_6 * V_7 ;
V_7 = V_21 [ F_8 () ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
if ( V_62 )
memcpy ( V_7 -> V_10 . V_63 , V_62 , sizeof( V_7 -> V_10 . V_63 ) ) ;
V_7 -> V_10 . V_64 = V_61 ;
return F_2 ( V_65 , V_7 ) ;
}
static void F_37 ( void * V_66 )
{
}
static void F_38 ( void )
{
struct V_67 * V_68 , * V_69 ;
F_39 ( F_37 , NULL , 1 ) ;
F_40 ( & V_70 ) ;
F_41 (p, n, &iucv_task_queue, list) {
if ( V_39 [ V_68 -> V_19 . V_64 ] == NULL ) {
F_42 ( & V_68 -> V_71 ) ;
F_6 ( V_68 ) ;
}
}
F_43 ( & V_70 ) ;
}
int F_44 ( struct V_72 * V_73 , int V_74 )
{
int V_27 ;
if ( ! V_75 )
return - V_76 ;
F_45 ( & V_77 ) ;
if ( ! V_74 )
V_34 ++ ;
if ( F_46 ( & V_78 ) ) {
V_27 = F_27 () ;
if ( V_27 )
goto V_79;
} else if ( ! V_74 && V_34 == 1 )
F_23 () ;
F_47 ( & V_73 -> V_80 ) ;
F_48 ( & V_81 ) ;
F_49 ( & V_73 -> V_71 , & V_78 ) ;
F_50 ( & V_81 ) ;
V_27 = 0 ;
V_79:
F_51 ( & V_77 ) ;
return V_27 ;
}
void F_52 ( struct V_72 * V_73 , int V_74 )
{
struct V_38 * V_68 , * V_69 ;
F_45 ( & V_77 ) ;
F_48 ( & V_81 ) ;
F_53 ( & V_73 -> V_71 ) ;
F_41 (p, n, &handler->paths, list) {
F_36 ( V_68 -> V_61 , NULL ) ;
V_39 [ V_68 -> V_61 ] = NULL ;
F_42 ( & V_68 -> V_71 ) ;
F_54 ( V_68 ) ;
}
F_50 ( & V_81 ) ;
if ( ! V_74 )
V_34 -- ;
if ( F_46 ( & V_78 ) )
F_28 () ;
else if ( ! V_74 && V_34 == 0 )
F_18 () ;
F_51 ( & V_77 ) ;
}
static int F_55 ( struct V_43 * V_82 ,
unsigned long V_83 , void * V_84 )
{
int V_85 ;
if ( F_16 ( & V_26 ) )
return V_86 ;
F_19 () ;
F_56 ( & V_26 , F_10 , NULL , 1 ) ;
F_57 () ;
for ( V_85 = 0 ; V_85 < V_17 ; V_85 ++ ) {
if ( V_39 [ V_85 ] )
F_36 ( V_85 , NULL ) ;
}
F_58 () ;
F_22 () ;
F_28 () ;
return V_86 ;
}
int F_59 ( struct V_38 * V_87 , struct V_72 * V_73 ,
T_6 * V_62 , void * V_88 )
{
union V_6 * V_7 ;
int V_27 ;
F_60 () ;
if ( F_16 ( & V_28 ) ) {
V_27 = - V_41 ;
goto V_40;
}
V_7 = V_6 [ F_8 () ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
V_7 -> V_10 . V_64 = V_87 -> V_61 ;
V_7 -> V_10 . V_89 = V_87 -> V_90 ;
if ( V_62 )
memcpy ( V_7 -> V_10 . V_63 , V_62 , sizeof( V_7 -> V_10 . V_63 ) ) ;
V_7 -> V_10 . V_91 = V_87 -> V_92 ;
V_27 = F_2 ( V_93 , V_7 ) ;
if ( ! V_27 ) {
V_87 -> V_88 = V_88 ;
V_87 -> V_90 = V_7 -> V_10 . V_89 ;
V_87 -> V_92 = V_7 -> V_10 . V_91 ;
}
V_40:
F_61 () ;
return V_27 ;
}
int F_62 ( struct V_38 * V_87 , struct V_72 * V_73 ,
T_6 * V_94 , T_6 * system , T_6 * V_62 ,
void * V_88 )
{
union V_6 * V_7 ;
int V_27 ;
F_48 ( & V_81 ) ;
F_38 () ;
if ( F_16 ( & V_28 ) ) {
V_27 = - V_41 ;
goto V_40;
}
V_7 = V_6 [ F_8 () ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
V_7 -> V_10 . V_89 = V_87 -> V_90 ;
V_7 -> V_10 . V_91 = V_87 -> V_92 ;
if ( V_94 ) {
memcpy ( V_7 -> V_10 . V_95 , V_94 , sizeof( V_7 -> V_10 . V_95 ) ) ;
F_63 ( V_7 -> V_10 . V_95 , sizeof( V_7 -> V_10 . V_95 ) ) ;
F_64 ( V_7 -> V_10 . V_95 , sizeof( V_7 -> V_10 . V_95 ) ) ;
}
if ( system ) {
memcpy ( V_7 -> V_10 . V_96 , system ,
sizeof( V_7 -> V_10 . V_96 ) ) ;
F_63 ( V_7 -> V_10 . V_96 , sizeof( V_7 -> V_10 . V_96 ) ) ;
F_64 ( V_7 -> V_10 . V_96 , sizeof( V_7 -> V_10 . V_96 ) ) ;
}
if ( V_62 )
memcpy ( V_7 -> V_10 . V_63 , V_62 , sizeof( V_7 -> V_10 . V_63 ) ) ;
V_27 = F_2 ( V_97 , V_7 ) ;
if ( ! V_27 ) {
if ( V_7 -> V_10 . V_64 < V_17 ) {
V_87 -> V_61 = V_7 -> V_10 . V_64 ;
V_87 -> V_90 = V_7 -> V_10 . V_89 ;
V_87 -> V_92 = V_7 -> V_10 . V_91 ;
V_87 -> V_73 = V_73 ;
V_87 -> V_88 = V_88 ;
F_49 ( & V_87 -> V_71 , & V_73 -> V_80 ) ;
V_39 [ V_87 -> V_61 ] = V_87 ;
} else {
F_36 ( V_7 -> V_10 . V_64 ,
V_98 ) ;
V_27 = - V_41 ;
}
}
V_40:
F_50 ( & V_81 ) ;
return V_27 ;
}
int F_65 ( struct V_38 * V_87 , T_6 * V_62 )
{
union V_6 * V_7 ;
int V_27 ;
F_60 () ;
if ( F_16 ( & V_28 ) ) {
V_27 = - V_41 ;
goto V_40;
}
V_7 = V_6 [ F_8 () ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
if ( V_62 )
memcpy ( V_7 -> V_10 . V_63 , V_62 , sizeof( V_7 -> V_10 . V_63 ) ) ;
V_7 -> V_10 . V_64 = V_87 -> V_61 ;
V_27 = F_2 ( V_99 , V_7 ) ;
V_40:
F_61 () ;
return V_27 ;
}
int F_66 ( struct V_38 * V_87 , T_6 * V_62 )
{
union V_6 * V_7 ;
int V_27 ;
F_60 () ;
if ( F_16 ( & V_28 ) ) {
V_27 = - V_41 ;
goto V_40;
}
V_7 = V_6 [ F_8 () ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
if ( V_62 )
memcpy ( V_7 -> V_10 . V_63 , V_62 , sizeof( V_7 -> V_10 . V_63 ) ) ;
V_7 -> V_10 . V_64 = V_87 -> V_61 ;
V_27 = F_2 ( V_100 , V_7 ) ;
V_40:
F_61 () ;
return V_27 ;
}
int F_67 ( struct V_38 * V_87 , T_6 * V_62 )
{
int V_27 ;
F_57 () ;
if ( F_16 ( & V_28 ) ) {
V_27 = - V_41 ;
goto V_40;
}
if ( V_101 != F_8 () )
F_48 ( & V_81 ) ;
V_27 = F_36 ( V_87 -> V_61 , V_62 ) ;
V_39 [ V_87 -> V_61 ] = NULL ;
F_53 ( & V_87 -> V_71 ) ;
if ( V_101 != F_8 () )
F_50 ( & V_81 ) ;
V_40:
F_58 () ;
return V_27 ;
}
int F_68 ( struct V_38 * V_87 , struct V_102 * V_103 ,
T_7 V_104 )
{
union V_6 * V_7 ;
int V_27 ;
F_60 () ;
if ( F_16 ( & V_28 ) ) {
V_27 = - V_41 ;
goto V_40;
}
V_7 = V_6 [ F_8 () ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
V_7 -> V_105 . V_64 = V_87 -> V_61 ;
V_7 -> V_105 . V_106 = V_103 -> V_107 ;
V_7 -> V_105 . V_108 = V_104 ;
V_7 -> V_105 . V_91 = V_109 | V_110 | V_111 ;
V_27 = F_2 ( V_112 , V_7 ) ;
if ( ! V_27 ) {
V_103 -> V_113 = ( * ( T_7 * ) & V_7 -> V_105 . V_114 ) >> 8 ;
V_103 -> V_115 = V_7 -> V_105 . V_116 ;
}
V_40:
F_61 () ;
return V_27 ;
}
static int F_69 ( struct V_38 * V_87 ,
struct V_102 * V_103 ,
T_6 V_92 , void * V_117 ,
T_4 V_118 , T_4 * V_119 )
{
struct V_120 * V_121 ;
T_6 * V_122 ;
T_4 V_123 ;
if ( V_119 )
* V_119 = abs ( V_118 - 8 ) ;
V_122 = V_103 -> V_122 ;
if ( V_92 & V_124 ) {
V_118 = ( V_118 < 8 ) ? V_118 : 8 ;
for ( V_121 = V_117 ; V_118 > 0 ; V_121 ++ ) {
V_123 = F_70 ( T_4 , V_118 , V_121 -> V_125 ) ;
memcpy ( ( T_6 * ) ( V_126 ) V_121 -> V_127 ,
V_122 , V_123 ) ;
V_122 += V_123 ;
V_118 -= V_123 ;
}
} else {
memcpy ( V_117 , V_122 , F_70 ( T_4 , V_118 , 8 ) ) ;
}
return 0 ;
}
int F_71 ( struct V_38 * V_87 , struct V_102 * V_103 ,
T_6 V_92 , void * V_117 , T_4 V_118 , T_4 * V_119 )
{
union V_6 * V_7 ;
int V_27 ;
if ( V_103 -> V_92 & V_128 )
return F_69 ( V_87 , V_103 , V_92 ,
V_117 , V_118 , V_119 ) ;
if ( F_16 ( & V_28 ) ) {
V_27 = - V_41 ;
goto V_40;
}
V_7 = V_6 [ F_8 () ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
V_7 -> V_29 . V_30 = ( T_7 ) ( V_126 ) V_117 ;
V_7 -> V_29 . V_129 = ( T_7 ) V_118 ;
V_7 -> V_29 . V_106 = V_103 -> V_107 ;
V_7 -> V_29 . V_64 = V_87 -> V_61 ;
V_7 -> V_29 . V_130 = V_103 -> V_131 ;
V_7 -> V_29 . V_91 = ( V_92 | V_111 |
V_110 | V_132 ) ;
V_27 = F_2 ( V_133 , V_7 ) ;
if ( ! V_27 || V_27 == 5 ) {
V_103 -> V_92 = V_7 -> V_29 . V_91 ;
if ( V_119 )
* V_119 = V_7 -> V_29 . V_129 ;
}
V_40:
return V_27 ;
}
int F_72 ( struct V_38 * V_87 , struct V_102 * V_103 ,
T_6 V_92 , void * V_117 , T_4 V_118 , T_4 * V_119 )
{
int V_27 ;
if ( V_103 -> V_92 & V_128 )
return F_69 ( V_87 , V_103 , V_92 ,
V_117 , V_118 , V_119 ) ;
F_60 () ;
V_27 = F_71 ( V_87 , V_103 , V_92 , V_117 , V_118 , V_119 ) ;
F_61 () ;
return V_27 ;
}
int F_73 ( struct V_38 * V_87 , struct V_102 * V_103 )
{
union V_6 * V_7 ;
int V_27 ;
F_60 () ;
if ( F_16 ( & V_28 ) ) {
V_27 = - V_41 ;
goto V_40;
}
V_7 = V_6 [ F_8 () ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
V_7 -> V_29 . V_64 = V_87 -> V_61 ;
V_7 -> V_29 . V_106 = V_103 -> V_107 ;
V_7 -> V_29 . V_130 = V_103 -> V_131 ;
V_7 -> V_29 . V_91 = ( V_132 | V_110 | V_111 ) ;
V_27 = F_2 ( V_134 , V_7 ) ;
V_40:
F_61 () ;
return V_27 ;
}
int F_74 ( struct V_38 * V_87 , struct V_102 * V_103 ,
T_6 V_92 , void * V_135 , T_4 V_118 )
{
union V_6 * V_7 ;
int V_27 ;
F_60 () ;
if ( F_16 ( & V_28 ) ) {
V_27 = - V_41 ;
goto V_40;
}
V_7 = V_6 [ F_8 () ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
if ( V_92 & V_128 ) {
V_7 -> V_136 . V_64 = V_87 -> V_61 ;
V_7 -> V_136 . V_91 = V_92 ;
V_7 -> V_136 . V_106 = V_103 -> V_107 ;
V_7 -> V_136 . V_130 = V_103 -> V_131 ;
memcpy ( V_7 -> V_136 . V_137 , V_135 , F_70 ( T_4 , V_118 , 8 ) ) ;
} else {
V_7 -> V_29 . V_30 = ( T_7 ) ( V_126 ) V_135 ;
V_7 -> V_29 . V_129 = ( T_7 ) V_118 ;
V_7 -> V_29 . V_64 = V_87 -> V_61 ;
V_7 -> V_29 . V_91 = V_92 ;
V_7 -> V_29 . V_106 = V_103 -> V_107 ;
V_7 -> V_29 . V_130 = V_103 -> V_131 ;
}
V_27 = F_2 ( V_138 , V_7 ) ;
V_40:
F_61 () ;
return V_27 ;
}
int F_75 ( struct V_38 * V_87 , struct V_102 * V_103 ,
T_6 V_92 , T_7 V_104 , void * V_117 , T_4 V_118 )
{
union V_6 * V_7 ;
int V_27 ;
if ( F_16 ( & V_28 ) ) {
V_27 = - V_41 ;
goto V_40;
}
V_7 = V_6 [ F_8 () ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
if ( V_92 & V_128 ) {
V_7 -> V_136 . V_64 = V_87 -> V_61 ;
V_7 -> V_136 . V_91 = V_92 | V_139 ;
V_7 -> V_136 . V_130 = V_103 -> V_131 ;
V_7 -> V_136 . V_108 = V_104 ;
V_7 -> V_136 . V_116 = V_103 -> V_115 ;
memcpy ( V_7 -> V_136 . V_137 , V_117 , 8 ) ;
} else {
V_7 -> V_29 . V_30 = ( T_7 ) ( V_126 ) V_117 ;
V_7 -> V_29 . V_129 = ( T_7 ) V_118 ;
V_7 -> V_29 . V_64 = V_87 -> V_61 ;
V_7 -> V_29 . V_91 = V_92 | V_139 ;
V_7 -> V_29 . V_130 = V_103 -> V_131 ;
V_7 -> V_29 . V_108 = V_104 ;
V_7 -> V_29 . V_116 = V_103 -> V_115 ;
}
V_27 = F_2 ( V_140 , V_7 ) ;
if ( ! V_27 )
V_103 -> V_107 = V_7 -> V_29 . V_106 ;
V_40:
return V_27 ;
}
int F_76 ( struct V_38 * V_87 , struct V_102 * V_103 ,
T_6 V_92 , T_7 V_104 , void * V_117 , T_4 V_118 )
{
int V_27 ;
F_60 () ;
V_27 = F_75 ( V_87 , V_103 , V_92 , V_104 , V_117 , V_118 ) ;
F_61 () ;
return V_27 ;
}
int F_77 ( struct V_38 * V_87 , struct V_102 * V_103 ,
T_6 V_92 , T_7 V_104 , void * V_117 , T_4 V_118 ,
void * V_141 , T_4 V_142 , T_4 * V_119 )
{
union V_6 * V_7 ;
int V_27 ;
F_60 () ;
if ( F_16 ( & V_28 ) ) {
V_27 = - V_41 ;
goto V_40;
}
V_7 = V_6 [ F_8 () ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
if ( V_92 & V_128 ) {
V_7 -> V_136 . V_64 = V_87 -> V_61 ;
V_7 -> V_136 . V_91 = V_87 -> V_92 ;
V_7 -> V_136 . V_130 = V_103 -> V_131 ;
V_7 -> V_136 . V_108 = V_104 ;
V_7 -> V_136 . V_116 = V_103 -> V_115 ;
V_7 -> V_136 . V_143 = ( T_7 ) ( V_126 ) V_141 ;
V_7 -> V_136 . V_144 = ( T_7 ) V_142 ;
memcpy ( V_7 -> V_136 . V_137 , V_117 , 8 ) ;
} else {
V_7 -> V_29 . V_64 = V_87 -> V_61 ;
V_7 -> V_29 . V_91 = V_87 -> V_92 ;
V_7 -> V_29 . V_130 = V_103 -> V_131 ;
V_7 -> V_29 . V_108 = V_104 ;
V_7 -> V_29 . V_116 = V_103 -> V_115 ;
V_7 -> V_29 . V_30 = ( T_7 ) ( V_126 ) V_117 ;
V_7 -> V_29 . V_129 = ( T_7 ) V_118 ;
V_7 -> V_29 . V_143 = ( T_7 ) ( V_126 ) V_141 ;
V_7 -> V_29 . V_144 = ( T_7 ) V_142 ;
}
V_27 = F_2 ( V_140 , V_7 ) ;
if ( ! V_27 )
V_103 -> V_107 = V_7 -> V_29 . V_106 ;
V_40:
F_61 () ;
return V_27 ;
}
static void F_78 ( struct V_31 * V_19 )
{
struct F_78 * V_145 = ( void * ) V_19 ;
struct V_72 * V_73 ;
struct V_38 * V_87 ;
char * error ;
F_79 ( V_39 [ V_145 -> V_64 ] ) ;
error = V_146 ;
V_87 = F_80 ( V_145 -> V_89 , V_145 -> V_91 , V_147 ) ;
if ( ! V_87 )
goto V_148;
V_87 -> V_61 = V_145 -> V_64 ;
V_39 [ V_87 -> V_61 ] = V_87 ;
F_81 ( V_145 -> V_95 , 8 ) ;
F_82 (handler, &iucv_handler_list, list) {
if ( ! V_73 -> V_149 )
continue;
F_83 ( & V_87 -> V_71 , & V_73 -> V_80 ) ;
V_87 -> V_73 = V_73 ;
if ( ! V_73 -> V_149 ( V_87 , V_145 -> V_95 , V_145 -> V_63 ) )
return;
F_42 ( & V_87 -> V_71 ) ;
V_87 -> V_73 = NULL ;
}
V_39 [ V_87 -> V_61 ] = NULL ;
F_54 ( V_87 ) ;
error = V_150 ;
V_148:
F_36 ( V_145 -> V_64 , error ) ;
}
static void F_84 ( struct V_31 * V_19 )
{
struct F_84 * V_151 = ( void * ) V_19 ;
struct V_38 * V_87 = V_39 [ V_151 -> V_64 ] ;
if ( V_87 )
V_87 -> V_92 = V_151 -> V_91 ;
if ( V_87 && V_87 -> V_73 && V_87 -> V_73 -> V_152 )
V_87 -> V_73 -> V_152 ( V_87 , V_151 -> V_63 ) ;
}
static void F_85 ( struct V_31 * V_19 )
{
struct F_85 * V_153 = ( void * ) V_19 ;
struct V_38 * V_87 = V_39 [ V_153 -> V_64 ] ;
if ( ! V_87 || ! V_87 -> V_73 )
return;
if ( V_87 -> V_73 -> V_154 )
V_87 -> V_73 -> V_154 ( V_87 , V_153 -> V_63 ) ;
else {
F_36 ( V_87 -> V_61 , NULL ) ;
V_39 [ V_87 -> V_61 ] = NULL ;
F_42 ( & V_87 -> V_71 ) ;
F_54 ( V_87 ) ;
}
}
static void F_86 ( struct V_31 * V_19 )
{
struct F_86 * V_155 = ( void * ) V_19 ;
struct V_38 * V_87 = V_39 [ V_155 -> V_64 ] ;
if ( V_87 && V_87 -> V_73 && V_87 -> V_73 -> V_156 )
V_87 -> V_73 -> V_156 ( V_87 , V_155 -> V_63 ) ;
}
static void F_87 ( struct V_31 * V_19 )
{
struct F_87 * V_157 = ( void * ) V_19 ;
struct V_38 * V_87 = V_39 [ V_157 -> V_64 ] ;
if ( V_87 && V_87 -> V_73 && V_87 -> V_73 -> V_158 )
V_87 -> V_73 -> V_158 ( V_87 , V_157 -> V_63 ) ;
}
static void F_88 ( struct V_31 * V_19 )
{
struct F_88 * V_159 = ( void * ) V_19 ;
struct V_38 * V_87 = V_39 [ V_159 -> V_64 ] ;
struct V_102 V_103 ;
if ( V_87 && V_87 -> V_73 && V_87 -> V_73 -> V_160 ) {
V_103 . V_92 = V_159 -> V_91 ;
V_103 . V_107 = V_159 -> V_106 ;
V_103 . V_113 = V_159 -> V_114 ;
memcpy ( V_103 . V_122 , V_159 -> V_137 , 8 ) ;
V_103 . V_131 = V_159 -> V_108 ;
V_103 . V_115 = V_159 -> V_116 ;
V_103 . V_125 = V_159 -> V_144 ;
V_87 -> V_73 -> V_160 ( V_87 , & V_103 ) ;
}
}
static void F_89 ( struct V_31 * V_19 )
{
struct F_89 * V_161 = ( void * ) V_19 ;
struct V_38 * V_87 = V_39 [ V_161 -> V_64 ] ;
struct V_102 V_103 ;
if ( V_87 && V_87 -> V_73 && V_87 -> V_73 -> V_162 ) {
V_103 . V_92 = V_161 -> V_91 ;
V_103 . V_107 = V_161 -> V_106 ;
V_103 . V_131 = V_161 -> V_130 ;
if ( V_161 -> V_91 & V_128 ) {
memcpy ( V_103 . V_122 , V_161 -> V_163 . V_164 , 8 ) ;
V_103 . V_125 = 8 ;
} else
V_103 . V_125 = V_161 -> V_165 . V_129 ;
V_103 . V_166 = V_161 -> V_144 ;
V_87 -> V_73 -> V_162 ( V_87 , & V_103 ) ;
}
}
static void F_90 ( unsigned long V_167 )
{
typedef void T_8 ( struct V_31 * );
static T_8 * V_168 [] = {
[ 0x02 ] = F_84 ,
[ 0x03 ] = F_85 ,
[ 0x04 ] = F_86 ,
[ 0x05 ] = F_87 ,
[ 0x06 ] = F_88 ,
[ 0x07 ] = F_88 ,
[ 0x08 ] = F_89 ,
[ 0x09 ] = F_89 ,
} ;
F_91 ( V_169 ) ;
struct V_67 * V_68 , * V_69 ;
if ( ! F_92 ( & V_81 ) ) {
F_93 ( & V_170 ) ;
return;
}
V_101 = F_8 () ;
F_40 ( & V_70 ) ;
F_94 ( & V_171 , & V_169 ) ;
F_43 ( & V_70 ) ;
F_41 (p, n, &task_queue, list) {
F_53 ( & V_68 -> V_71 ) ;
V_168 [ V_68 -> V_19 . V_172 ] ( & V_68 -> V_19 ) ;
F_6 ( V_68 ) ;
}
V_101 = - 1 ;
F_95 ( & V_81 ) ;
}
static void F_96 ( struct V_173 * V_174 )
{
F_91 ( V_175 ) ;
struct V_67 * V_68 , * V_69 ;
F_48 ( & V_81 ) ;
V_101 = F_8 () ;
F_40 ( & V_70 ) ;
F_94 ( & V_176 , & V_175 ) ;
F_43 ( & V_70 ) ;
F_38 () ;
F_41 (p, n, &work_queue, list) {
F_53 ( & V_68 -> V_71 ) ;
F_78 ( & V_68 -> V_19 ) ;
F_6 ( V_68 ) ;
}
V_101 = - 1 ;
F_50 ( & V_81 ) ;
}
static void F_97 ( struct V_177 V_177 ,
unsigned int V_178 , unsigned long V_179 )
{
struct V_31 * V_68 ;
struct V_67 * V_174 ;
F_98 ( V_180 ) ;
V_68 = V_31 [ F_8 () ] ;
if ( V_68 -> V_64 >= V_17 ) {
F_99 ( V_68 -> V_64 >= V_17 ) ;
F_36 ( V_68 -> V_64 , V_150 ) ;
return;
}
F_79 ( V_68 -> V_172 < 0x01 || V_68 -> V_172 > 0x09 ) ;
V_174 = F_100 ( sizeof( struct V_67 ) , V_147 ) ;
if ( ! V_174 ) {
F_15 ( L_10 ) ;
return;
}
memcpy ( & V_174 -> V_19 , V_68 , sizeof( V_174 -> V_19 ) ) ;
F_101 ( & V_70 ) ;
if ( V_68 -> V_172 == 0x01 ) {
F_49 ( & V_174 -> V_71 , & V_176 ) ;
F_102 ( & V_181 ) ;
} else {
F_49 ( & V_174 -> V_71 , & V_171 ) ;
F_93 ( & V_170 ) ;
}
F_95 ( & V_70 ) ;
}
static int F_103 ( struct V_1 * V_2 )
{
int V_27 = 0 ;
#ifdef F_104
F_105 ( V_182 L_11 ) ;
#endif
if ( V_2 -> V_183 && V_2 -> V_183 -> V_184 && V_2 -> V_183 -> V_184 -> V_185 )
V_27 = V_2 -> V_183 -> V_184 -> V_185 ( V_2 ) ;
return V_27 ;
}
static void F_106 ( struct V_1 * V_2 )
{
#ifdef F_104
F_105 ( V_182 L_12 ) ;
#endif
if ( V_2 -> V_183 && V_2 -> V_183 -> V_184 && V_2 -> V_183 -> V_184 -> V_186 )
V_2 -> V_183 -> V_184 -> V_186 ( V_2 ) ;
}
int F_107 ( void )
{
int V_85 ;
for ( V_85 = 0 ; V_85 < V_17 ; V_85 ++ ) {
if ( V_39 [ V_85 ] )
return 0 ;
}
return 1 ;
}
static int F_108 ( struct V_1 * V_2 )
{
int V_20 ;
struct V_67 * V_68 , * V_69 ;
int V_27 = 0 ;
#ifdef F_104
F_105 ( V_187 L_13 ) ;
#endif
if ( V_188 != V_189 ) {
F_26 (cpu, &iucv_irq_cpumask)
F_21 ( V_20 , F_12 ,
NULL , 1 ) ;
F_109 ( & V_181 ) ;
F_41 (p, n, &iucv_work_queue, list) {
F_53 ( & V_68 -> V_71 ) ;
F_36 ( V_68 -> V_19 . V_64 ,
V_150 ) ;
F_6 ( V_68 ) ;
}
}
V_188 = V_189 ;
if ( V_2 -> V_183 && V_2 -> V_183 -> V_184 && V_2 -> V_183 -> V_184 -> V_190 )
V_27 = V_2 -> V_183 -> V_184 -> V_190 ( V_2 ) ;
if ( F_107 () )
F_28 () ;
return V_27 ;
}
static int F_110 ( struct V_1 * V_2 )
{
int V_27 = 0 ;
#ifdef F_104
F_105 ( V_187 L_14 ) ;
#endif
V_188 = V_191 ;
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
if ( V_2 -> V_183 && V_2 -> V_183 -> V_184 && V_2 -> V_183 -> V_184 -> V_192 )
V_27 = V_2 -> V_183 -> V_184 -> V_192 ( V_2 ) ;
V_40:
return V_27 ;
}
static int F_111 ( struct V_1 * V_2 )
{
int V_27 = 0 ;
#ifdef F_104
F_105 ( V_187 L_15 , V_39 ) ;
#endif
if ( ( V_188 != V_193 ) && V_39 )
F_15 ( L_16 ) ;
V_188 = V_193 ;
if ( F_16 ( & V_26 ) ) {
V_27 = F_4 () ;
V_27 = F_27 () ;
if ( V_27 )
goto V_40;
}
if ( V_2 -> V_183 && V_2 -> V_183 -> V_184 && V_2 -> V_183 -> V_184 -> V_194 )
V_27 = V_2 -> V_183 -> V_184 -> V_194 ( V_2 ) ;
V_40:
return V_27 ;
}
static int T_9 F_112 ( void )
{
int V_27 ;
int V_20 ;
if ( ! V_195 ) {
V_27 = - V_196 ;
goto V_40;
}
F_113 ( 0 , 1 ) ;
V_27 = F_4 () ;
if ( V_27 )
goto V_197;
V_27 = F_114 ( V_198 , F_97 ) ;
if ( V_27 )
goto V_197;
V_199 = F_115 ( L_17 ) ;
if ( F_116 ( V_199 ) ) {
V_27 = F_117 ( V_199 ) ;
goto V_200;
}
F_118 () ;
F_20 (cpu) {
if ( F_31 ( V_20 ) ) {
V_27 = - V_15 ;
goto V_42;
}
}
V_27 = F_119 ( & V_201 ) ;
if ( V_27 )
goto V_42;
F_120 () ;
V_27 = F_121 ( & V_202 ) ;
if ( V_27 )
goto V_203;
F_63 ( V_150 , 16 ) ;
F_63 ( V_146 , 16 ) ;
F_63 ( V_98 , 16 ) ;
V_75 = 1 ;
V_27 = F_122 ( & V_204 ) ;
if ( V_27 )
goto V_205;
V_206 . V_207 = V_199 ;
V_206 . V_208 = & V_204 ;
return 0 ;
V_205:
F_123 ( & V_202 ) ;
V_203:
F_118 () ;
F_124 ( & V_201 ) ;
V_42:
F_125 (cpu)
F_30 ( V_20 ) ;
F_120 () ;
F_126 ( V_199 ) ;
V_200:
F_127 ( V_198 , F_97 ) ;
V_197:
F_128 ( 0 , 1 ) ;
V_40:
return V_27 ;
}
static void T_10 F_129 ( void )
{
struct V_67 * V_68 , * V_69 ;
int V_20 ;
F_40 ( & V_70 ) ;
F_41 (p, n, &iucv_task_queue, list)
F_6 ( V_68 ) ;
F_41 (p, n, &iucv_work_queue, list)
F_6 ( V_68 ) ;
F_43 ( & V_70 ) ;
F_123 ( & V_202 ) ;
F_118 () ;
F_124 ( & V_201 ) ;
F_125 (cpu)
F_30 ( V_20 ) ;
F_120 () ;
F_126 ( V_199 ) ;
F_130 ( & V_204 ) ;
F_127 ( V_198 , F_97 ) ;
}
