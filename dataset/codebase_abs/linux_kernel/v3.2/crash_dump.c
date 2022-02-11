T_1 F_1 ( unsigned long V_1 , char * V_2 ,
T_2 V_3 , unsigned long V_4 , int V_5 )
{
unsigned long V_6 ;
if ( ! V_3 )
return 0 ;
V_6 = ( V_1 << V_7 ) + V_4 ;
if ( V_6 < V_8 )
V_6 += V_9 ;
else if ( V_6 > V_9 &&
V_6 < V_9 + V_8 )
V_6 -= V_9 ;
if ( V_5 )
F_2 ( ( void V_10 V_11 * ) V_2 , ( void * ) V_6 ,
V_3 ) ;
else
F_3 ( V_2 , ( void * ) V_6 , V_3 ) ;
return V_3 ;
}
static int F_4 ( void * V_12 , void * V_6 , T_2 V_13 )
{
unsigned long V_14 = 0 ;
int V_15 ;
if ( ( unsigned long ) V_6 < V_8 ) {
V_14 = F_5 ( V_13 , V_8 - ( unsigned long ) V_6 ) ;
V_15 = F_3 ( V_12 , V_6 + V_9 , V_14 ) ;
if ( V_15 )
return V_15 ;
}
return F_3 ( V_12 + V_14 , V_6 + V_14 , V_13 - V_14 ) ;
}
static void * F_6 ( int V_16 )
{
void * V_15 ;
V_15 = F_7 ( V_16 , V_17 ) ;
if ( ! V_15 )
F_8 ( L_1 , V_16 ) ;
return V_15 ;
}
static struct V_18 * F_9 ( void )
{
struct V_18 * V_19 ;
V_19 = F_6 ( V_20 * sizeof( struct V_18 ) ) ;
F_10 ( V_19 ) ;
F_11 ( V_19 , V_9 , V_8 , V_21 ) ;
return V_19 ;
}
static void * F_12 ( void * V_2 , T_3 type , void * V_22 , int V_23 ,
const char * V_24 )
{
T_4 * V_25 ;
T_5 V_16 ;
V_25 = ( T_4 * ) V_2 ;
V_25 -> V_26 = strlen ( V_24 ) + 1 ;
V_25 -> V_27 = V_23 ;
V_25 -> V_28 = type ;
V_16 = sizeof( T_4 ) ;
memcpy ( V_2 + V_16 , V_24 , V_25 -> V_26 ) ;
V_16 = F_13 ( V_16 + V_25 -> V_26 , 4 ) ;
memcpy ( V_2 + V_16 , V_22 , V_25 -> V_27 ) ;
V_16 = F_13 ( V_16 + V_25 -> V_27 , 4 ) ;
return F_14 ( V_2 , V_16 ) ;
}
static void * F_15 ( void * V_29 , struct V_30 * V_31 )
{
struct V_32 F_15 ;
static int V_33 = 1 ;
memset ( & F_15 , 0 , sizeof( F_15 ) ) ;
memcpy ( & F_15 . V_34 . V_35 , V_31 -> V_36 , sizeof( V_31 -> V_36 ) ) ;
memcpy ( & F_15 . V_34 . V_37 , V_31 -> V_37 , sizeof( V_31 -> V_37 ) ) ;
memcpy ( & F_15 . V_34 . V_38 , V_31 -> V_39 , sizeof( V_31 -> V_39 ) ) ;
F_15 . V_40 = V_33 ;
V_33 ++ ;
return F_12 ( V_29 , V_41 , & F_15 , sizeof( F_15 ) ,
L_2 ) ;
}
static void * F_16 ( void * V_29 , struct V_30 * V_31 )
{
T_6 F_16 ;
memset ( & F_16 , 0 , sizeof( F_16 ) ) ;
memcpy ( & F_16 . V_42 , & V_31 -> V_43 , sizeof( V_31 -> V_43 ) ) ;
memcpy ( & F_16 . V_44 , & V_31 -> V_45 , sizeof( V_31 -> V_45 ) ) ;
return F_12 ( V_29 , V_46 , & F_16 , sizeof( F_16 ) ,
L_2 ) ;
}
static void * F_17 ( void * V_29 , struct V_30 * V_31 )
{
return F_12 ( V_29 , V_47 , & V_31 -> V_48 , sizeof( V_31 -> V_48 ) ,
V_49 ) ;
}
static void * F_18 ( void * V_29 , struct V_30 * V_31 )
{
return F_12 ( V_29 , V_50 , & V_31 -> V_51 ,
sizeof( V_31 -> V_51 ) , V_49 ) ;
}
static void * F_19 ( void * V_29 , struct V_30 * V_31 )
{
return F_12 ( V_29 , V_52 , & V_31 -> V_53 ,
sizeof( V_31 -> V_53 ) , V_49 ) ;
}
static void * F_20 ( void * V_29 , struct V_30 * V_31 )
{
return F_12 ( V_29 , V_54 , & V_31 -> V_55 ,
sizeof( V_31 -> V_55 ) , V_49 ) ;
}
static void * F_21 ( void * V_29 , struct V_30 * V_31 )
{
return F_12 ( V_29 , V_56 , & V_31 -> V_57 ,
sizeof( V_31 -> V_57 ) , V_49 ) ;
}
void * F_22 ( void * V_29 , struct V_30 * V_31 )
{
V_29 = F_15 ( V_29 , V_31 ) ;
V_29 = F_16 ( V_29 , V_31 ) ;
V_29 = F_17 ( V_29 , V_31 ) ;
V_29 = F_18 ( V_29 , V_31 ) ;
V_29 = F_19 ( V_29 , V_31 ) ;
V_29 = F_20 ( V_29 , V_31 ) ;
V_29 = F_21 ( V_29 , V_31 ) ;
return V_29 ;
}
static void * F_23 ( void * V_29 )
{
struct V_58 V_59 ;
memset ( & V_59 , 0 , sizeof( V_59 ) ) ;
V_59 . V_60 = 'R' ;
strcpy ( V_59 . V_61 , L_3 ) ;
return F_12 ( V_29 , V_62 , & V_59 , sizeof( V_59 ) ,
V_49 ) ;
}
static void * F_24 ( void * V_29 )
{
char V_63 [ 11 ] , * V_64 ;
T_4 V_25 ;
void * V_65 ;
if ( F_4 ( & V_65 , & V_66 . V_67 , sizeof( V_65 ) ) )
return V_29 ;
memset ( V_63 , 0 , sizeof( V_63 ) ) ;
if ( F_4 ( & V_25 , V_65 , sizeof( V_25 ) ) )
return V_29 ;
if ( F_4 ( V_63 , V_65 + sizeof( V_25 ) , sizeof( V_63 ) - 1 ) )
return V_29 ;
if ( strcmp ( V_63 , L_4 ) != 0 )
return V_29 ;
V_64 = F_6 ( V_25 . V_27 + 1 ) ;
if ( F_4 ( V_64 , V_65 + 24 , V_25 . V_27 ) )
return V_29 ;
V_64 [ V_25 . V_27 + 1 ] = 0 ;
return F_12 ( V_29 , 0 , V_64 , V_25 . V_27 , L_4 ) ;
}
static void * F_25 ( T_7 * V_68 , int V_69 )
{
memset ( V_68 , 0 , sizeof( * V_68 ) ) ;
memcpy ( V_68 -> V_70 , V_71 , V_72 ) ;
V_68 -> V_70 [ V_73 ] = V_74 ;
V_68 -> V_70 [ V_75 ] = V_76 ;
V_68 -> V_70 [ V_77 ] = V_78 ;
memset ( V_68 -> V_70 + V_79 , 0 , V_80 - V_79 ) ;
V_68 -> V_81 = V_82 ;
V_68 -> V_83 = V_84 ;
V_68 -> V_85 = V_78 ;
V_68 -> V_86 = sizeof( T_7 ) ;
V_68 -> V_87 = sizeof( T_7 ) ;
V_68 -> V_88 = sizeof( V_89 ) ;
V_68 -> V_90 = V_69 + 1 ;
return V_68 + 1 ;
}
static int F_26 ( void )
{
int V_91 , V_92 = 0 ;
for ( V_91 = 0 ; V_93 [ V_91 ] ; V_91 ++ ) {
if ( V_93 [ V_91 ] -> V_57 == 0 )
continue;
V_92 ++ ;
}
return V_92 ;
}
static int F_27 ( void )
{
struct V_18 * V_19 , * V_18 ;
int V_91 , V_94 = 0 ;
V_19 = F_9 () ;
for ( V_91 = 0 ; V_91 < V_20 ; V_91 ++ ) {
V_18 = & V_19 [ V_91 ] ;
if ( V_19 [ V_91 ] . type != V_95 &&
V_19 [ V_91 ] . type != V_96 )
continue;
if ( V_18 -> V_97 == 0 )
continue;
V_94 ++ ;
}
F_28 ( V_19 ) ;
return V_94 ;
}
static inline unsigned long F_29 ( unsigned long V_65 )
{
return V_9 + V_65 ;
}
static int F_30 ( V_89 * V_98 , T_5 V_99 )
{
struct V_18 * V_19 , * V_18 ;
int V_91 ;
V_19 = F_9 () ;
for ( V_91 = 0 ; V_91 < V_20 ; V_91 ++ ) {
V_18 = & V_19 [ V_91 ] ;
if ( V_18 -> V_97 == 0 )
break;
if ( V_19 [ V_91 ] . type != V_95 &&
V_19 [ V_91 ] . type != V_96 )
continue;
else
V_98 -> V_100 = V_18 -> V_97 ;
V_98 -> V_101 = V_102 ;
V_98 -> V_103 = V_18 -> V_65 ;
V_98 -> V_104 = V_18 -> V_65 ;
V_98 -> V_105 = V_18 -> V_65 ;
V_98 -> V_106 = V_18 -> V_97 ;
V_98 -> V_107 = V_108 | V_109 | V_110 ;
V_98 -> V_111 = V_112 ;
V_98 ++ ;
}
F_28 ( V_19 ) ;
return V_91 ;
}
static void * F_31 ( V_89 * V_98 , void * V_29 , T_5 V_113 )
{
struct V_30 * V_31 ;
void * V_114 = V_29 ;
int V_91 ;
V_29 = F_23 ( V_29 ) ;
for ( V_91 = 0 ; V_93 [ V_91 ] ; V_91 ++ ) {
V_31 = V_93 [ V_91 ] ;
if ( V_31 -> V_57 == 0 )
continue;
V_29 = F_22 ( V_29 , V_31 ) ;
}
V_29 = F_24 ( V_29 ) ;
memset ( V_98 , 0 , sizeof( * V_98 ) ) ;
V_98 -> V_101 = V_115 ;
V_98 -> V_103 = F_29 ( V_113 ) ;
V_98 -> V_100 = ( unsigned long ) F_32 ( V_29 , V_114 ) ;
V_98 -> V_106 = V_98 -> V_100 ;
return V_29 ;
}
static void F_33 ( char * * V_116 , T_2 * V_117 )
{
V_89 * V_118 , * V_119 ;
int V_69 ;
void * V_29 , * V_120 ;
T_8 V_121 ;
T_5 V_122 ;
V_69 = F_27 () ;
V_121 = 0x1000 + F_26 () * 0x300 +
V_69 * sizeof( V_89 ) ;
V_120 = F_6 ( V_121 ) ;
V_29 = F_25 ( V_120 , V_69 ) ;
V_118 = V_29 ;
V_29 = F_14 ( V_29 , sizeof( V_89 ) ) ;
V_119 = V_29 ;
V_29 = F_14 ( V_29 , sizeof( V_89 ) * V_69 ) ;
V_122 = F_34 ( V_29 , V_120 ) ;
V_29 = F_31 ( V_118 , V_29 , ( ( unsigned long ) V_120 ) + V_122 ) ;
V_122 = F_34 ( V_29 , V_120 ) ;
F_30 ( V_119 , ( ( unsigned long ) V_120 ) + V_122 ) ;
* V_117 = V_122 ;
* V_116 = ( void * ) F_29 ( ( unsigned long ) V_120 ) ;
F_35 ( * V_117 > V_121 ) ;
}
static int F_36 ( void )
{
T_2 V_117 ;
char * V_116 ;
if ( ! V_9 || F_37 () )
return - V_123 ;
F_33 ( & V_116 , & V_117 ) ;
V_124 = ( unsigned long long ) V_116 ;
V_125 = V_117 ;
return 0 ;
}
