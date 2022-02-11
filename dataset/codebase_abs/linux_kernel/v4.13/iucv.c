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
static int F_32 ( unsigned int V_21 )
{
F_7 ( V_22 [ V_21 ] ) ;
V_22 [ V_21 ] = NULL ;
F_7 ( V_6 [ V_21 ] ) ;
V_6 [ V_21 ] = NULL ;
F_7 ( V_32 [ V_21 ] ) ;
V_32 [ V_21 ] = NULL ;
return 0 ;
}
static int F_33 ( unsigned int V_21 )
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
static int F_36 ( unsigned int V_21 )
{
if ( ! V_40 )
return 0 ;
F_14 ( NULL ) ;
return 0 ;
}
static int F_37 ( unsigned int V_21 )
{
T_3 V_37 ;
if ( ! V_40 )
return 0 ;
F_26 ( & V_37 , & V_29 ) ;
F_12 ( V_21 , & V_37 ) ;
if ( F_18 ( & V_37 ) )
return - V_44 ;
F_19 ( NULL ) ;
if ( ! F_18 ( & V_27 ) )
return 0 ;
F_23 ( F_27 ( & V_29 ) ,
F_8 , NULL , 1 ) ;
return 0 ;
}
static int F_38 ( T_5 V_45 , T_6 * V_46 )
{
union V_6 * V_7 ;
V_7 = V_22 [ F_9 () ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
if ( V_46 )
memcpy ( V_7 -> V_10 . V_47 , V_46 , sizeof( V_7 -> V_10 . V_47 ) ) ;
V_7 -> V_10 . V_48 = V_45 ;
return F_3 ( V_49 , V_7 ) ;
}
static void F_39 ( void * V_50 )
{
}
static void F_40 ( void )
{
struct V_51 * V_52 , * V_53 ;
F_41 ( F_39 , NULL , 1 ) ;
F_42 ( & V_54 ) ;
F_43 (p, n, &iucv_task_queue, list) {
if ( V_40 [ V_52 -> V_20 . V_48 ] == NULL ) {
F_44 ( & V_52 -> V_55 ) ;
F_7 ( V_52 ) ;
}
}
F_45 ( & V_54 ) ;
}
int F_46 ( struct V_56 * V_57 , int V_58 )
{
int V_28 ;
if ( ! V_59 )
return - V_60 ;
F_47 ( & V_61 ) ;
if ( ! V_58 )
V_35 ++ ;
if ( F_48 ( & V_62 ) ) {
V_28 = F_29 () ;
if ( V_28 )
goto V_63;
} else if ( ! V_58 && V_35 == 1 )
F_25 () ;
F_49 ( & V_57 -> V_64 ) ;
F_50 ( & V_65 ) ;
F_51 ( & V_57 -> V_55 , & V_62 ) ;
F_52 ( & V_65 ) ;
V_28 = 0 ;
V_63:
F_53 ( & V_61 ) ;
return V_28 ;
}
void F_54 ( struct V_56 * V_57 , int V_58 )
{
struct V_39 * V_52 , * V_53 ;
F_47 ( & V_61 ) ;
F_50 ( & V_65 ) ;
F_55 ( & V_57 -> V_55 ) ;
F_43 (p, n, &handler->paths, list) {
F_38 ( V_52 -> V_45 , NULL ) ;
V_40 [ V_52 -> V_45 ] = NULL ;
F_44 ( & V_52 -> V_55 ) ;
F_56 ( V_52 ) ;
}
F_52 ( & V_65 ) ;
if ( ! V_58 )
V_35 -- ;
if ( F_48 ( & V_62 ) )
F_30 () ;
else if ( ! V_58 && V_35 == 0 )
F_20 () ;
F_53 ( & V_61 ) ;
}
static int F_57 ( struct V_66 * V_67 ,
unsigned long V_68 , void * V_69 )
{
int V_70 ;
if ( F_18 ( & V_27 ) )
return V_71 ;
F_21 () ;
F_58 ( & V_27 , F_11 , NULL , 1 ) ;
F_59 () ;
for ( V_70 = 0 ; V_70 < V_18 ; V_70 ++ ) {
if ( V_40 [ V_70 ] )
F_38 ( V_70 , NULL ) ;
}
F_60 () ;
F_24 () ;
F_30 () ;
return V_71 ;
}
int F_61 ( struct V_39 * V_72 , struct V_56 * V_57 ,
T_6 * V_46 , void * V_73 )
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
V_7 -> V_10 . V_48 = V_72 -> V_45 ;
V_7 -> V_10 . V_74 = V_72 -> V_75 ;
if ( V_46 )
memcpy ( V_7 -> V_10 . V_47 , V_46 , sizeof( V_7 -> V_10 . V_47 ) ) ;
V_7 -> V_10 . V_76 = V_72 -> V_77 ;
V_28 = F_3 ( V_78 , V_7 ) ;
if ( ! V_28 ) {
V_72 -> V_73 = V_73 ;
V_72 -> V_75 = V_7 -> V_10 . V_74 ;
V_72 -> V_77 = V_7 -> V_10 . V_76 ;
}
V_41:
F_63 () ;
return V_28 ;
}
int F_64 ( struct V_39 * V_72 , struct V_56 * V_57 ,
T_6 * V_79 , T_6 * system , T_6 * V_46 ,
void * V_73 )
{
union V_6 * V_7 ;
int V_28 ;
F_50 ( & V_65 ) ;
F_40 () ;
if ( F_18 ( & V_29 ) ) {
V_28 = - V_42 ;
goto V_41;
}
V_7 = V_6 [ F_9 () ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
V_7 -> V_10 . V_74 = V_72 -> V_75 ;
V_7 -> V_10 . V_76 = V_72 -> V_77 ;
if ( V_79 ) {
memcpy ( V_7 -> V_10 . V_80 , V_79 , sizeof( V_7 -> V_10 . V_80 ) ) ;
F_65 ( V_7 -> V_10 . V_80 , sizeof( V_7 -> V_10 . V_80 ) ) ;
F_66 ( V_7 -> V_10 . V_80 , sizeof( V_7 -> V_10 . V_80 ) ) ;
}
if ( system ) {
memcpy ( V_7 -> V_10 . V_81 , system ,
sizeof( V_7 -> V_10 . V_81 ) ) ;
F_65 ( V_7 -> V_10 . V_81 , sizeof( V_7 -> V_10 . V_81 ) ) ;
F_66 ( V_7 -> V_10 . V_81 , sizeof( V_7 -> V_10 . V_81 ) ) ;
}
if ( V_46 )
memcpy ( V_7 -> V_10 . V_47 , V_46 , sizeof( V_7 -> V_10 . V_47 ) ) ;
V_28 = F_3 ( V_82 , V_7 ) ;
if ( ! V_28 ) {
if ( V_7 -> V_10 . V_48 < V_18 ) {
V_72 -> V_45 = V_7 -> V_10 . V_48 ;
V_72 -> V_75 = V_7 -> V_10 . V_74 ;
V_72 -> V_77 = V_7 -> V_10 . V_76 ;
V_72 -> V_57 = V_57 ;
V_72 -> V_73 = V_73 ;
F_51 ( & V_72 -> V_55 , & V_57 -> V_64 ) ;
V_40 [ V_72 -> V_45 ] = V_72 ;
} else {
F_38 ( V_7 -> V_10 . V_48 ,
V_83 ) ;
V_28 = - V_42 ;
}
}
V_41:
F_52 ( & V_65 ) ;
return V_28 ;
}
int F_67 ( struct V_39 * V_72 , T_6 * V_46 )
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
if ( V_46 )
memcpy ( V_7 -> V_10 . V_47 , V_46 , sizeof( V_7 -> V_10 . V_47 ) ) ;
V_7 -> V_10 . V_48 = V_72 -> V_45 ;
V_28 = F_3 ( V_84 , V_7 ) ;
V_41:
F_63 () ;
return V_28 ;
}
int F_68 ( struct V_39 * V_72 , T_6 * V_46 )
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
if ( V_46 )
memcpy ( V_7 -> V_10 . V_47 , V_46 , sizeof( V_7 -> V_10 . V_47 ) ) ;
V_7 -> V_10 . V_48 = V_72 -> V_45 ;
V_28 = F_3 ( V_85 , V_7 ) ;
V_41:
F_63 () ;
return V_28 ;
}
int F_69 ( struct V_39 * V_72 , T_6 * V_46 )
{
int V_28 ;
F_59 () ;
if ( F_18 ( & V_29 ) ) {
V_28 = - V_42 ;
goto V_41;
}
if ( V_86 != F_9 () )
F_50 ( & V_65 ) ;
V_28 = F_38 ( V_72 -> V_45 , V_46 ) ;
V_40 [ V_72 -> V_45 ] = NULL ;
F_55 ( & V_72 -> V_55 ) ;
if ( V_86 != F_9 () )
F_52 ( & V_65 ) ;
V_41:
F_60 () ;
return V_28 ;
}
int F_70 ( struct V_39 * V_72 , struct V_87 * V_88 ,
T_7 V_89 )
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
V_7 -> V_90 . V_48 = V_72 -> V_45 ;
V_7 -> V_90 . V_91 = V_88 -> V_92 ;
V_7 -> V_90 . V_93 = V_89 ;
V_7 -> V_90 . V_76 = V_94 | V_95 | V_96 ;
V_28 = F_3 ( V_97 , V_7 ) ;
if ( ! V_28 ) {
V_88 -> V_98 = ( * ( T_7 * ) & V_7 -> V_90 . V_99 ) >> 8 ;
V_88 -> V_100 = V_7 -> V_90 . V_101 ;
}
V_41:
F_63 () ;
return V_28 ;
}
static int F_71 ( struct V_39 * V_72 ,
struct V_87 * V_88 ,
T_6 V_77 , void * V_102 ,
T_4 V_103 , T_4 * V_104 )
{
struct V_105 * V_106 ;
T_6 * V_107 ;
T_4 V_108 ;
if ( V_104 )
* V_104 = abs ( V_103 - 8 ) ;
V_107 = V_88 -> V_107 ;
if ( V_77 & V_109 ) {
V_103 = ( V_103 < 8 ) ? V_103 : 8 ;
for ( V_106 = V_102 ; V_103 > 0 ; V_106 ++ ) {
V_108 = F_72 ( T_4 , V_103 , V_106 -> V_110 ) ;
memcpy ( ( T_6 * ) ( V_111 ) V_106 -> V_112 ,
V_107 , V_108 ) ;
V_107 += V_108 ;
V_103 -= V_108 ;
}
} else {
memcpy ( V_102 , V_107 , F_72 ( T_4 , V_103 , 8 ) ) ;
}
return 0 ;
}
int F_73 ( struct V_39 * V_72 , struct V_87 * V_88 ,
T_6 V_77 , void * V_102 , T_4 V_103 , T_4 * V_104 )
{
union V_6 * V_7 ;
int V_28 ;
if ( V_88 -> V_77 & V_113 )
return F_71 ( V_72 , V_88 , V_77 ,
V_102 , V_103 , V_104 ) ;
if ( F_18 ( & V_29 ) ) {
V_28 = - V_42 ;
goto V_41;
}
V_7 = V_6 [ F_9 () ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
V_7 -> V_30 . V_31 = ( T_7 ) ( V_111 ) V_102 ;
V_7 -> V_30 . V_114 = ( T_7 ) V_103 ;
V_7 -> V_30 . V_91 = V_88 -> V_92 ;
V_7 -> V_30 . V_48 = V_72 -> V_45 ;
V_7 -> V_30 . V_115 = V_88 -> V_116 ;
V_7 -> V_30 . V_76 = ( V_77 | V_96 |
V_95 | V_117 ) ;
V_28 = F_3 ( V_118 , V_7 ) ;
if ( ! V_28 || V_28 == 5 ) {
V_88 -> V_77 = V_7 -> V_30 . V_76 ;
if ( V_104 )
* V_104 = V_7 -> V_30 . V_114 ;
}
V_41:
return V_28 ;
}
int F_74 ( struct V_39 * V_72 , struct V_87 * V_88 ,
T_6 V_77 , void * V_102 , T_4 V_103 , T_4 * V_104 )
{
int V_28 ;
if ( V_88 -> V_77 & V_113 )
return F_71 ( V_72 , V_88 , V_77 ,
V_102 , V_103 , V_104 ) ;
F_62 () ;
V_28 = F_73 ( V_72 , V_88 , V_77 , V_102 , V_103 , V_104 ) ;
F_63 () ;
return V_28 ;
}
int F_75 ( struct V_39 * V_72 , struct V_87 * V_88 )
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
V_7 -> V_30 . V_48 = V_72 -> V_45 ;
V_7 -> V_30 . V_91 = V_88 -> V_92 ;
V_7 -> V_30 . V_115 = V_88 -> V_116 ;
V_7 -> V_30 . V_76 = ( V_117 | V_95 | V_96 ) ;
V_28 = F_3 ( V_119 , V_7 ) ;
V_41:
F_63 () ;
return V_28 ;
}
int F_76 ( struct V_39 * V_72 , struct V_87 * V_88 ,
T_6 V_77 , void * V_120 , T_4 V_103 )
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
if ( V_77 & V_113 ) {
V_7 -> V_121 . V_48 = V_72 -> V_45 ;
V_7 -> V_121 . V_76 = V_77 ;
V_7 -> V_121 . V_91 = V_88 -> V_92 ;
V_7 -> V_121 . V_115 = V_88 -> V_116 ;
memcpy ( V_7 -> V_121 . V_122 , V_120 , F_72 ( T_4 , V_103 , 8 ) ) ;
} else {
V_7 -> V_30 . V_31 = ( T_7 ) ( V_111 ) V_120 ;
V_7 -> V_30 . V_114 = ( T_7 ) V_103 ;
V_7 -> V_30 . V_48 = V_72 -> V_45 ;
V_7 -> V_30 . V_76 = V_77 ;
V_7 -> V_30 . V_91 = V_88 -> V_92 ;
V_7 -> V_30 . V_115 = V_88 -> V_116 ;
}
V_28 = F_3 ( V_123 , V_7 ) ;
V_41:
F_63 () ;
return V_28 ;
}
int F_77 ( struct V_39 * V_72 , struct V_87 * V_88 ,
T_6 V_77 , T_7 V_89 , void * V_102 , T_4 V_103 )
{
union V_6 * V_7 ;
int V_28 ;
if ( F_18 ( & V_29 ) ) {
V_28 = - V_42 ;
goto V_41;
}
V_7 = V_6 [ F_9 () ] ;
memset ( V_7 , 0 , sizeof( union V_6 ) ) ;
if ( V_77 & V_113 ) {
V_7 -> V_121 . V_48 = V_72 -> V_45 ;
V_7 -> V_121 . V_76 = V_77 | V_124 ;
V_7 -> V_121 . V_115 = V_88 -> V_116 ;
V_7 -> V_121 . V_93 = V_89 ;
V_7 -> V_121 . V_101 = V_88 -> V_100 ;
memcpy ( V_7 -> V_121 . V_122 , V_102 , 8 ) ;
} else {
V_7 -> V_30 . V_31 = ( T_7 ) ( V_111 ) V_102 ;
V_7 -> V_30 . V_114 = ( T_7 ) V_103 ;
V_7 -> V_30 . V_48 = V_72 -> V_45 ;
V_7 -> V_30 . V_76 = V_77 | V_124 ;
V_7 -> V_30 . V_115 = V_88 -> V_116 ;
V_7 -> V_30 . V_93 = V_89 ;
V_7 -> V_30 . V_101 = V_88 -> V_100 ;
}
V_28 = F_3 ( V_125 , V_7 ) ;
if ( ! V_28 )
V_88 -> V_92 = V_7 -> V_30 . V_91 ;
V_41:
return V_28 ;
}
int F_78 ( struct V_39 * V_72 , struct V_87 * V_88 ,
T_6 V_77 , T_7 V_89 , void * V_102 , T_4 V_103 )
{
int V_28 ;
F_62 () ;
V_28 = F_77 ( V_72 , V_88 , V_77 , V_89 , V_102 , V_103 ) ;
F_63 () ;
return V_28 ;
}
int F_79 ( struct V_39 * V_72 , struct V_87 * V_88 ,
T_6 V_77 , T_7 V_89 , void * V_102 , T_4 V_103 ,
void * V_126 , T_4 V_127 , T_4 * V_104 )
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
if ( V_77 & V_113 ) {
V_7 -> V_121 . V_48 = V_72 -> V_45 ;
V_7 -> V_121 . V_76 = V_72 -> V_77 ;
V_7 -> V_121 . V_115 = V_88 -> V_116 ;
V_7 -> V_121 . V_93 = V_89 ;
V_7 -> V_121 . V_101 = V_88 -> V_100 ;
V_7 -> V_121 . V_128 = ( T_7 ) ( V_111 ) V_126 ;
V_7 -> V_121 . V_129 = ( T_7 ) V_127 ;
memcpy ( V_7 -> V_121 . V_122 , V_102 , 8 ) ;
} else {
V_7 -> V_30 . V_48 = V_72 -> V_45 ;
V_7 -> V_30 . V_76 = V_72 -> V_77 ;
V_7 -> V_30 . V_115 = V_88 -> V_116 ;
V_7 -> V_30 . V_93 = V_89 ;
V_7 -> V_30 . V_101 = V_88 -> V_100 ;
V_7 -> V_30 . V_31 = ( T_7 ) ( V_111 ) V_102 ;
V_7 -> V_30 . V_114 = ( T_7 ) V_103 ;
V_7 -> V_30 . V_128 = ( T_7 ) ( V_111 ) V_126 ;
V_7 -> V_30 . V_129 = ( T_7 ) V_127 ;
}
V_28 = F_3 ( V_125 , V_7 ) ;
if ( ! V_28 )
V_88 -> V_92 = V_7 -> V_30 . V_91 ;
V_41:
F_63 () ;
return V_28 ;
}
static void F_80 ( struct V_32 * V_20 )
{
struct F_80 * V_130 = ( void * ) V_20 ;
struct V_56 * V_57 ;
struct V_39 * V_72 ;
char * error ;
F_81 ( V_40 [ V_130 -> V_48 ] ) ;
error = V_131 ;
V_72 = F_82 ( V_130 -> V_74 , V_130 -> V_76 , V_132 ) ;
if ( ! V_72 )
goto V_133;
V_72 -> V_45 = V_130 -> V_48 ;
V_40 [ V_72 -> V_45 ] = V_72 ;
F_83 ( V_130 -> V_80 , 8 ) ;
F_84 (handler, &iucv_handler_list, list) {
if ( ! V_57 -> V_134 )
continue;
F_85 ( & V_72 -> V_55 , & V_57 -> V_64 ) ;
V_72 -> V_57 = V_57 ;
if ( ! V_57 -> V_134 ( V_72 , V_130 -> V_80 , V_130 -> V_47 ) )
return;
F_44 ( & V_72 -> V_55 ) ;
V_72 -> V_57 = NULL ;
}
V_40 [ V_72 -> V_45 ] = NULL ;
F_56 ( V_72 ) ;
error = V_135 ;
V_133:
F_38 ( V_130 -> V_48 , error ) ;
}
static void F_86 ( struct V_32 * V_20 )
{
struct F_86 * V_136 = ( void * ) V_20 ;
struct V_39 * V_72 = V_40 [ V_136 -> V_48 ] ;
if ( V_72 )
V_72 -> V_77 = V_136 -> V_76 ;
if ( V_72 && V_72 -> V_57 && V_72 -> V_57 -> V_137 )
V_72 -> V_57 -> V_137 ( V_72 , V_136 -> V_47 ) ;
}
static void F_87 ( struct V_32 * V_20 )
{
struct F_87 * V_138 = ( void * ) V_20 ;
struct V_39 * V_72 = V_40 [ V_138 -> V_48 ] ;
if ( ! V_72 || ! V_72 -> V_57 )
return;
if ( V_72 -> V_57 -> V_139 )
V_72 -> V_57 -> V_139 ( V_72 , V_138 -> V_47 ) ;
else {
F_38 ( V_72 -> V_45 , NULL ) ;
V_40 [ V_72 -> V_45 ] = NULL ;
F_44 ( & V_72 -> V_55 ) ;
F_56 ( V_72 ) ;
}
}
static void F_88 ( struct V_32 * V_20 )
{
struct F_88 * V_140 = ( void * ) V_20 ;
struct V_39 * V_72 = V_40 [ V_140 -> V_48 ] ;
if ( V_72 && V_72 -> V_57 && V_72 -> V_57 -> V_141 )
V_72 -> V_57 -> V_141 ( V_72 , V_140 -> V_47 ) ;
}
static void F_89 ( struct V_32 * V_20 )
{
struct F_89 * V_142 = ( void * ) V_20 ;
struct V_39 * V_72 = V_40 [ V_142 -> V_48 ] ;
if ( V_72 && V_72 -> V_57 && V_72 -> V_57 -> V_143 )
V_72 -> V_57 -> V_143 ( V_72 , V_142 -> V_47 ) ;
}
static void F_90 ( struct V_32 * V_20 )
{
struct F_90 * V_144 = ( void * ) V_20 ;
struct V_39 * V_72 = V_40 [ V_144 -> V_48 ] ;
struct V_87 V_88 ;
if ( V_72 && V_72 -> V_57 && V_72 -> V_57 -> V_145 ) {
V_88 . V_77 = V_144 -> V_76 ;
V_88 . V_92 = V_144 -> V_91 ;
V_88 . V_98 = V_144 -> V_99 ;
memcpy ( V_88 . V_107 , V_144 -> V_122 , 8 ) ;
V_88 . V_116 = V_144 -> V_93 ;
V_88 . V_100 = V_144 -> V_101 ;
V_88 . V_110 = V_144 -> V_129 ;
V_72 -> V_57 -> V_145 ( V_72 , & V_88 ) ;
}
}
static void F_91 ( struct V_32 * V_20 )
{
struct F_91 * V_146 = ( void * ) V_20 ;
struct V_39 * V_72 = V_40 [ V_146 -> V_48 ] ;
struct V_87 V_88 ;
if ( V_72 && V_72 -> V_57 && V_72 -> V_57 -> V_147 ) {
V_88 . V_77 = V_146 -> V_76 ;
V_88 . V_92 = V_146 -> V_91 ;
V_88 . V_116 = V_146 -> V_115 ;
if ( V_146 -> V_76 & V_113 ) {
memcpy ( V_88 . V_107 , V_146 -> V_148 . V_149 , 8 ) ;
V_88 . V_110 = 8 ;
} else
V_88 . V_110 = V_146 -> V_150 . V_114 ;
V_88 . V_151 = V_146 -> V_129 ;
V_72 -> V_57 -> V_147 ( V_72 , & V_88 ) ;
}
}
static void F_92 ( unsigned long V_152 )
{
typedef void T_8 ( struct V_32 * );
static T_8 * V_153 [] = {
[ 0x02 ] = F_86 ,
[ 0x03 ] = F_87 ,
[ 0x04 ] = F_88 ,
[ 0x05 ] = F_89 ,
[ 0x06 ] = F_90 ,
[ 0x07 ] = F_90 ,
[ 0x08 ] = F_91 ,
[ 0x09 ] = F_91 ,
} ;
F_93 ( V_154 ) ;
struct V_51 * V_52 , * V_53 ;
if ( ! F_94 ( & V_65 ) ) {
F_95 ( & V_155 ) ;
return;
}
V_86 = F_9 () ;
F_42 ( & V_54 ) ;
F_96 ( & V_156 , & V_154 ) ;
F_45 ( & V_54 ) ;
F_43 (p, n, &task_queue, list) {
F_55 ( & V_52 -> V_55 ) ;
V_153 [ V_52 -> V_20 . V_157 ] ( & V_52 -> V_20 ) ;
F_7 ( V_52 ) ;
}
V_86 = - 1 ;
F_97 ( & V_65 ) ;
}
static void F_98 ( struct V_158 * V_159 )
{
F_93 ( V_160 ) ;
struct V_51 * V_52 , * V_53 ;
F_50 ( & V_65 ) ;
V_86 = F_9 () ;
F_42 ( & V_54 ) ;
F_96 ( & V_161 , & V_160 ) ;
F_45 ( & V_54 ) ;
F_40 () ;
F_43 (p, n, &work_queue, list) {
F_55 ( & V_52 -> V_55 ) ;
F_80 ( & V_52 -> V_20 ) ;
F_7 ( V_52 ) ;
}
V_86 = - 1 ;
F_52 ( & V_65 ) ;
}
static void F_99 ( struct V_162 V_162 ,
unsigned int V_163 , unsigned long V_164 )
{
struct V_32 * V_52 ;
struct V_51 * V_159 ;
F_100 ( V_165 ) ;
V_52 = V_32 [ F_9 () ] ;
if ( V_52 -> V_48 >= V_18 ) {
F_101 ( V_52 -> V_48 >= V_18 ) ;
F_38 ( V_52 -> V_48 , V_135 ) ;
return;
}
F_81 ( V_52 -> V_157 < 0x01 || V_52 -> V_157 > 0x09 ) ;
V_159 = F_102 ( sizeof( struct V_51 ) , V_132 ) ;
if ( ! V_159 ) {
F_17 ( L_10 ) ;
return;
}
memcpy ( & V_159 -> V_20 , V_52 , sizeof( V_159 -> V_20 ) ) ;
F_103 ( & V_54 ) ;
if ( V_52 -> V_157 == 0x01 ) {
F_51 ( & V_159 -> V_55 , & V_161 ) ;
F_104 ( & V_166 ) ;
} else {
F_51 ( & V_159 -> V_55 , & V_156 ) ;
F_95 ( & V_155 ) ;
}
F_97 ( & V_54 ) ;
}
static int F_105 ( struct V_1 * V_2 )
{
int V_28 = 0 ;
#ifdef F_106
F_107 ( V_167 L_11 ) ;
#endif
if ( V_2 -> V_168 && V_2 -> V_168 -> V_169 && V_2 -> V_168 -> V_169 -> V_170 )
V_28 = V_2 -> V_168 -> V_169 -> V_170 ( V_2 ) ;
return V_28 ;
}
static void F_108 ( struct V_1 * V_2 )
{
#ifdef F_106
F_107 ( V_167 L_12 ) ;
#endif
if ( V_2 -> V_168 && V_2 -> V_168 -> V_169 && V_2 -> V_168 -> V_169 -> V_171 )
V_2 -> V_168 -> V_169 -> V_171 ( V_2 ) ;
}
int F_109 ( void )
{
int V_70 ;
for ( V_70 = 0 ; V_70 < V_18 ; V_70 ++ ) {
if ( V_40 [ V_70 ] )
return 0 ;
}
return 1 ;
}
static int F_110 ( struct V_1 * V_2 )
{
int V_21 ;
struct V_51 * V_52 , * V_53 ;
int V_28 = 0 ;
#ifdef F_106
F_107 ( V_172 L_13 ) ;
#endif
if ( V_173 != V_174 ) {
F_28 (cpu, &iucv_irq_cpumask)
F_23 ( V_21 , F_13 ,
NULL , 1 ) ;
F_111 ( & V_166 ) ;
F_43 (p, n, &iucv_work_queue, list) {
F_55 ( & V_52 -> V_55 ) ;
F_38 ( V_52 -> V_20 . V_48 ,
V_135 ) ;
F_7 ( V_52 ) ;
}
}
V_173 = V_174 ;
if ( V_2 -> V_168 && V_2 -> V_168 -> V_169 && V_2 -> V_168 -> V_169 -> V_175 )
V_28 = V_2 -> V_168 -> V_169 -> V_175 ( V_2 ) ;
if ( F_109 () )
F_30 () ;
return V_28 ;
}
static int F_112 ( struct V_1 * V_2 )
{
int V_28 = 0 ;
#ifdef F_106
F_107 ( V_172 L_14 ) ;
#endif
V_173 = V_176 ;
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
if ( V_2 -> V_168 && V_2 -> V_168 -> V_169 && V_2 -> V_168 -> V_169 -> V_177 )
V_28 = V_2 -> V_168 -> V_169 -> V_177 ( V_2 ) ;
V_41:
return V_28 ;
}
static int F_113 ( struct V_1 * V_2 )
{
int V_28 = 0 ;
#ifdef F_106
F_107 ( V_172 L_15 , V_40 ) ;
#endif
if ( ( V_173 != V_178 ) && V_40 )
F_17 ( L_16 ) ;
V_173 = V_178 ;
if ( F_18 ( & V_27 ) ) {
V_28 = F_5 () ;
V_28 = F_29 () ;
if ( V_28 )
goto V_41;
}
if ( V_2 -> V_168 && V_2 -> V_168 -> V_169 && V_2 -> V_168 -> V_169 -> V_179 )
V_28 = V_2 -> V_168 -> V_169 -> V_179 ( V_2 ) ;
V_41:
return V_28 ;
}
static int T_9 F_114 ( void )
{
int V_28 ;
if ( ! V_180 ) {
V_28 = - V_181 ;
goto V_41;
}
F_115 ( 0 , 1 ) ;
V_28 = F_5 () ;
if ( V_28 )
goto V_182;
V_28 = F_116 ( V_183 , F_99 ) ;
if ( V_28 )
goto V_182;
V_184 = F_117 ( L_17 ) ;
if ( F_118 ( V_184 ) ) {
V_28 = F_119 ( V_184 ) ;
goto V_185;
}
V_28 = F_120 ( V_186 , L_18 ,
F_33 , F_32 ) ;
if ( V_28 )
goto V_187;
V_28 = F_120 ( V_188 , L_19 ,
F_36 , F_37 ) ;
if ( V_28 < 0 )
goto V_189;
V_190 = V_28 ;
V_28 = F_121 ( & V_191 ) ;
if ( V_28 )
goto V_192;
F_65 ( V_135 , 16 ) ;
F_65 ( V_131 , 16 ) ;
F_65 ( V_83 , 16 ) ;
V_59 = 1 ;
V_28 = F_122 ( & V_193 ) ;
if ( V_28 )
goto V_194;
V_195 . V_196 = V_184 ;
V_195 . V_197 = & V_193 ;
return 0 ;
V_194:
F_123 ( & V_191 ) ;
V_192:
F_124 ( V_190 ) ;
V_189:
F_124 ( V_186 ) ;
V_187:
F_125 ( V_184 ) ;
V_185:
F_126 ( V_183 , F_99 ) ;
V_182:
F_127 ( 0 , 1 ) ;
V_41:
return V_28 ;
}
static void T_10 F_128 ( void )
{
struct V_51 * V_52 , * V_53 ;
F_42 ( & V_54 ) ;
F_43 (p, n, &iucv_task_queue, list)
F_7 ( V_52 ) ;
F_43 (p, n, &iucv_work_queue, list)
F_7 ( V_52 ) ;
F_45 ( & V_54 ) ;
F_123 ( & V_191 ) ;
F_129 ( V_190 ) ;
F_124 ( V_186 ) ;
F_125 ( V_184 ) ;
F_130 ( & V_193 ) ;
F_126 ( V_183 , F_99 ) ;
}
