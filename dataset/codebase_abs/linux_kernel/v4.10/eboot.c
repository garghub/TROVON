static T_1
F_1 ( void * V_1 , T_2 * V_2 ,
void * * V_3 , T_3 * V_4 )
{
T_4 * V_5 , * V_6 = V_1 ;
T_5 * V_7 ;
T_1 V_8 ;
T_6 V_9 = V_10 ;
T_7 V_11 ;
V_8 = V_12 -> V_13 ( ( unsigned long ) V_6 -> V_14 , V_6 , & V_5 , V_2 ,
V_15 , ( T_3 ) 0 ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_1 ) ;
F_3 ( V_17 , V_2 ) ;
F_2 ( V_17 , L_2 ) ;
return V_8 ;
}
* V_3 = V_5 ;
V_11 = 0 ;
V_8 = V_12 -> V_13 ( ( unsigned long ) V_5 -> V_18 , V_5 , & V_9 ,
& V_11 , NULL ) ;
if ( V_8 != V_19 ) {
F_2 ( V_17 , L_3 ) ;
return V_8 ;
}
V_20:
V_8 = F_4 ( V_21 , V_22 ,
V_11 , ( void * * ) & V_7 ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_4 ) ;
return V_8 ;
}
V_8 = V_12 -> V_13 ( ( unsigned long ) V_5 -> V_18 , V_5 , & V_9 ,
& V_11 , V_7 ) ;
if ( V_8 == V_19 ) {
F_4 ( V_23 , V_7 ) ;
goto V_20;
}
* V_4 = V_7 -> V_24 ;
F_4 ( V_23 , V_7 ) ;
if ( V_8 != V_16 )
F_2 ( V_17 , L_5 ) ;
return V_8 ;
}
static T_1
F_5 ( void * V_1 , T_2 * V_2 ,
void * * V_3 , T_3 * V_4 )
{
T_8 * V_5 , * V_6 = V_1 ;
T_5 * V_7 ;
T_1 V_8 ;
T_6 V_9 = V_10 ;
T_3 V_11 ;
V_8 = V_12 -> V_13 ( ( unsigned long ) V_6 -> V_14 , V_6 , & V_5 , V_2 ,
V_15 , ( T_3 ) 0 ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_1 ) ;
F_3 ( V_17 , V_2 ) ;
F_2 ( V_17 , L_2 ) ;
return V_8 ;
}
* V_3 = V_5 ;
V_11 = 0 ;
V_8 = V_12 -> V_13 ( ( unsigned long ) V_5 -> V_18 , V_5 , & V_9 ,
& V_11 , NULL ) ;
if ( V_8 != V_19 ) {
F_2 ( V_17 , L_3 ) ;
return V_8 ;
}
V_20:
V_8 = F_4 ( V_21 , V_22 ,
V_11 , ( void * * ) & V_7 ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_4 ) ;
return V_8 ;
}
V_8 = V_12 -> V_13 ( ( unsigned long ) V_5 -> V_18 , V_5 , & V_9 ,
& V_11 , V_7 ) ;
if ( V_8 == V_19 ) {
F_4 ( V_23 , V_7 ) ;
goto V_20;
}
* V_4 = V_7 -> V_24 ;
F_4 ( V_23 , V_7 ) ;
if ( V_8 != V_16 )
F_2 ( V_17 , L_5 ) ;
return V_8 ;
}
T_1
F_6 ( T_9 * V_17 , void * V_1 ,
T_2 * V_2 , void * * V_3 , T_3 * V_4 )
{
if ( V_12 -> V_25 )
return F_5 ( V_1 , V_2 , V_3 , V_4 ) ;
return F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
}
T_1
F_7 ( void * V_3 , unsigned long * V_26 , void * V_27 )
{
unsigned long V_28 ;
if ( V_12 -> V_25 ) {
T_8 * V_6 = V_3 ;
V_28 = ( unsigned long ) V_6 -> V_29 ;
return V_12 -> V_13 ( V_28 , V_3 , V_26 , V_27 ) ;
} else {
T_4 * V_6 = V_3 ;
V_28 = ( unsigned long ) V_6 -> V_29 ;
return V_12 -> V_13 ( V_28 , V_3 , V_26 , V_27 ) ;
}
}
T_1 F_8 ( void * V_3 )
{
if ( V_12 -> V_25 ) {
T_8 * V_6 = V_3 ;
return V_12 -> V_13 ( ( unsigned long ) V_6 -> V_30 , V_3 ) ;
} else {
T_4 * V_6 = V_3 ;
return V_12 -> V_13 ( ( unsigned long ) V_6 -> V_30 , V_3 ) ;
}
}
static inline T_1 F_9 ( void * V_31 , void * * V_1 )
{
T_10 * V_32 ;
T_11 * V_33 = V_31 ;
T_4 * V_6 ;
T_6 V_34 = V_35 ;
T_1 V_8 ;
void * V_3 = ( void * ) ( unsigned long ) V_33 -> V_36 ;
unsigned long V_28 ;
V_8 = F_4 ( V_37 , V_3 ,
& V_34 , ( void * * ) & V_32 ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_6 ) ;
return V_8 ;
}
V_28 = ( unsigned long ) V_32 -> V_38 ;
V_8 = V_12 -> V_13 ( V_28 , V_32 , & V_6 ) ;
if ( V_8 != V_16 )
F_2 ( V_17 , L_7 ) ;
* V_1 = V_6 ;
return V_8 ;
}
static inline T_1 F_10 ( void * V_31 , void * * V_1 )
{
T_10 * V_32 ;
T_12 * V_33 = V_31 ;
T_8 * V_6 ;
T_6 V_34 = V_35 ;
T_1 V_8 ;
void * V_3 = ( void * ) ( unsigned long ) V_33 -> V_36 ;
unsigned long V_28 ;
V_8 = F_4 ( V_37 , V_3 ,
& V_34 , ( void * * ) & V_32 ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_6 ) ;
return V_8 ;
}
V_28 = ( unsigned long ) V_32 -> V_38 ;
V_8 = V_12 -> V_13 ( V_28 , V_32 , & V_6 ) ;
if ( V_8 != V_16 )
F_2 ( V_17 , L_7 ) ;
* V_1 = V_6 ;
return V_8 ;
}
T_1
F_11 ( T_9 * V_17 , void * V_31 , void * * V_1 )
{
if ( V_12 -> V_25 )
return F_10 ( V_31 , V_1 ) ;
return F_9 ( V_31 , V_1 ) ;
}
void F_3 ( T_9 * V_39 , T_2 * V_40 )
{
unsigned long V_41 ;
T_13 V_42 ;
if ( V_12 -> V_25 ) {
struct V_43 * V_44 ;
T_3 * V_28 ;
V_42 = F_12 ( F_13 ( * V_44 ) , V_41 ) ;
V_41 = V_12 -> V_45 + V_42 ;
V_44 = ( F_13 ( V_44 ) ) ( unsigned long ) V_12 -> V_45 ;
V_28 = ( T_3 * ) V_41 ;
V_12 -> V_13 ( * V_28 , V_44 , V_40 ) ;
} else {
struct V_46 * V_44 ;
T_7 * V_28 ;
V_42 = F_12 ( F_13 ( * V_44 ) , V_41 ) ;
V_41 = V_12 -> V_45 + V_42 ;
V_44 = ( F_13 ( V_44 ) ) ( unsigned long ) V_12 -> V_45 ;
V_28 = ( T_7 * ) V_41 ;
V_12 -> V_13 ( * V_28 , V_44 , V_40 ) ;
}
}
static T_1
F_14 ( T_14 * V_47 , struct V_48 * * V_49 )
{
struct V_48 * V_50 = NULL ;
T_1 V_8 ;
unsigned long V_26 ;
T_15 V_51 ;
V_8 = V_12 -> V_13 ( V_47 -> V_51 , V_47 ,
V_52 , 0 , 0 ,
& V_51 ) ;
if ( V_8 != V_16 )
return V_8 ;
if ( ! V_47 -> V_53 || ! V_47 -> V_54 )
return V_55 ;
V_26 = V_47 -> V_54 + sizeof( * V_50 ) ;
V_8 = F_4 ( V_21 , V_22 , V_26 , & V_50 ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_8 ) ;
return V_8 ;
}
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
V_50 -> V_56 . type = V_57 ;
V_50 -> V_56 . V_58 = V_26 - sizeof( struct V_59 ) ;
V_50 -> V_56 . V_60 = 0 ;
V_50 -> V_61 = V_47 -> V_54 ;
* V_49 = V_50 ;
V_8 = V_12 -> V_13 ( V_47 -> V_47 . V_29 , V_47 , V_62 ,
V_63 , 1 , & ( V_50 -> V_64 ) ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_9 ) ;
goto V_65;
}
V_8 = V_12 -> V_13 ( V_47 -> V_47 . V_29 , V_47 , V_62 ,
V_66 , 1 , & ( V_50 -> V_67 ) ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_10 ) ;
goto V_65;
}
V_8 = V_12 -> V_13 ( V_47 -> V_68 , V_47 , & ( V_50 -> V_69 ) ,
& ( V_50 -> V_70 ) , & ( V_50 -> V_71 ) , & ( V_50 -> V_72 ) ) ;
if ( V_8 != V_16 )
goto V_65;
memcpy ( V_50 -> V_73 , V_47 -> V_53 , V_47 -> V_54 ) ;
return V_8 ;
V_65:
F_4 ( V_23 , V_50 ) ;
return V_8 ;
}
static void
F_15 ( struct V_74 * V_75 , void * * V_76 ,
unsigned long V_26 )
{
T_14 * V_47 = NULL ;
T_6 V_77 = V_78 ;
T_7 * V_79 = ( T_7 * ) ( unsigned long ) V_76 ;
T_1 V_8 ;
unsigned long V_80 ;
struct V_59 * V_56 ;
int V_81 ;
V_56 = (struct V_59 * ) ( unsigned long ) V_75 -> V_82 . V_59 ;
while ( V_56 && V_56 -> V_60 )
V_56 = (struct V_59 * ) ( unsigned long ) V_56 -> V_60 ;
V_80 = V_26 / sizeof( T_7 ) ;
for ( V_81 = 0 ; V_81 < V_80 ; V_81 ++ ) {
struct V_48 * V_50 = NULL ;
T_7 V_5 = V_79 [ V_81 ] ;
V_8 = F_4 ( V_37 , V_5 ,
& V_77 , ( void * * ) & V_47 ) ;
if ( V_8 != V_16 )
continue;
if ( ! V_47 )
continue;
V_8 = F_14 ( V_47 , & V_50 ) ;
if ( V_8 != V_16 )
continue;
if ( V_56 )
V_56 -> V_60 = ( unsigned long ) V_50 ;
else
V_75 -> V_82 . V_59 = ( unsigned long ) V_50 ;
V_56 = (struct V_59 * ) V_50 ;
}
}
static T_1
F_16 ( T_16 * V_47 , struct V_48 * * V_49 )
{
struct V_48 * V_50 ;
T_1 V_8 ;
unsigned long V_26 ;
T_15 V_51 ;
V_8 = V_12 -> V_13 ( V_47 -> V_51 , V_47 ,
V_52 , 0 ,
& V_51 ) ;
if ( V_8 != V_16 )
return V_8 ;
if ( ! V_47 -> V_53 || ! V_47 -> V_54 )
return V_55 ;
V_26 = V_47 -> V_54 + sizeof( * V_50 ) ;
V_8 = F_4 ( V_21 , V_22 , V_26 , & V_50 ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_8 ) ;
return V_8 ;
}
V_50 -> V_56 . type = V_57 ;
V_50 -> V_56 . V_58 = V_26 - sizeof( struct V_59 ) ;
V_50 -> V_56 . V_60 = 0 ;
V_50 -> V_61 = V_47 -> V_54 ;
* V_49 = V_50 ;
V_8 = V_12 -> V_13 ( V_47 -> V_47 . V_29 , V_47 , V_62 ,
V_63 , 1 , & ( V_50 -> V_64 ) ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_9 ) ;
goto V_65;
}
V_8 = V_12 -> V_13 ( V_47 -> V_47 . V_29 , V_47 , V_62 ,
V_66 , 1 , & ( V_50 -> V_67 ) ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_10 ) ;
goto V_65;
}
V_8 = V_12 -> V_13 ( V_47 -> V_68 , V_47 , & ( V_50 -> V_69 ) ,
& ( V_50 -> V_70 ) , & ( V_50 -> V_71 ) , & ( V_50 -> V_72 ) ) ;
if ( V_8 != V_16 )
goto V_65;
memcpy ( V_50 -> V_73 , V_47 -> V_53 , V_47 -> V_54 ) ;
return V_8 ;
V_65:
F_4 ( V_23 , V_50 ) ;
return V_8 ;
}
static void
F_17 ( struct V_74 * V_75 , void * * V_76 ,
unsigned long V_26 )
{
T_16 * V_47 = NULL ;
T_6 V_77 = V_78 ;
T_3 * V_79 = ( T_3 * ) ( unsigned long ) V_76 ;
T_1 V_8 ;
unsigned long V_80 ;
struct V_59 * V_56 ;
int V_81 ;
V_56 = (struct V_59 * ) ( unsigned long ) V_75 -> V_82 . V_59 ;
while ( V_56 && V_56 -> V_60 )
V_56 = (struct V_59 * ) ( unsigned long ) V_56 -> V_60 ;
V_80 = V_26 / sizeof( T_3 ) ;
for ( V_81 = 0 ; V_81 < V_80 ; V_81 ++ ) {
struct V_48 * V_50 = NULL ;
T_3 V_5 = V_79 [ V_81 ] ;
V_8 = F_4 ( V_37 , V_5 ,
& V_77 , ( void * * ) & V_47 ) ;
if ( V_8 != V_16 )
continue;
if ( ! V_47 )
continue;
V_8 = F_16 ( V_47 , & V_50 ) ;
if ( V_8 != V_16 )
continue;
if ( V_56 )
V_56 -> V_60 = ( unsigned long ) V_50 ;
else
V_75 -> V_82 . V_59 = ( unsigned long ) V_50 ;
V_56 = (struct V_59 * ) V_50 ;
}
}
static void F_18 ( struct V_74 * V_75 )
{
T_1 V_8 ;
void * * V_76 = NULL ;
T_6 V_77 = V_78 ;
unsigned long V_26 = 0 ;
V_8 = F_4 ( V_83 ,
V_84 ,
& V_77 , NULL , & V_26 , V_76 ) ;
if ( V_8 == V_19 ) {
V_8 = F_4 ( V_21 ,
V_22 ,
V_26 , ( void * * ) & V_76 ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_11 ) ;
return;
}
V_8 = F_4 ( V_83 ,
V_84 , & V_77 ,
NULL , & V_26 , V_76 ) ;
}
if ( V_8 != V_16 )
goto V_85;
if ( V_12 -> V_25 )
F_17 ( V_75 , V_76 , V_26 ) ;
else
F_15 ( V_75 , V_76 , V_26 ) ;
V_85:
F_4 ( V_23 , V_76 ) ;
}
static void F_19 ( struct V_74 * V_74 )
{
T_6 V_86 = V_87 ;
struct V_59 * V_56 , * V_88 ;
T_1 V_8 ;
T_7 V_26 = 0 ;
void * V_89 ;
V_8 = F_4 ( V_90 , & V_86 , NULL , & V_89 ) ;
if ( V_8 != V_16 )
return;
if ( F_20 ( V_91 , V_92 , V_89 ) != 0x10000 ) {
F_2 ( V_17 , L_12 ) ;
return;
}
F_21 ( V_91 , V_93 , V_89 , NULL , & V_26 ) ;
if ( ! V_26 )
return;
do {
V_8 = F_4 ( V_21 , V_22 ,
V_26 + sizeof( struct V_59 ) , & V_88 ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 ,
L_13 ) ;
return;
}
V_8 = F_21 ( V_91 , V_93 , V_89 ,
V_88 -> V_56 , & V_26 ) ;
if ( V_8 == V_19 )
F_4 ( V_23 , V_88 ) ;
} while ( V_8 == V_19 );
V_88 -> type = V_94 ;
V_88 -> V_58 = V_26 ;
V_88 -> V_60 = 0 ;
V_56 = (struct V_59 * ) ( unsigned long ) V_74 -> V_82 . V_59 ;
if ( ! V_56 )
V_74 -> V_82 . V_59 = ( unsigned long ) V_88 ;
else {
while ( V_56 -> V_60 )
V_56 = (struct V_59 * ) ( unsigned long ) V_56 -> V_60 ;
V_56 -> V_60 = ( unsigned long ) V_88 ;
}
}
static void F_22 ( struct V_74 * V_74 )
{
T_2 const V_95 [] = { 'A' , 'p' , 'p' , 'l' , 'e' , 0 } ;
T_2 * V_96 = ( T_2 * ) ( unsigned long )
F_20 ( V_97 , V_96 , V_17 ) ;
if ( ! memcmp ( V_96 , V_95 , sizeof( V_95 ) ) ) {
if ( F_23 ( V_98 ) )
F_19 ( V_74 ) ;
}
}
static T_1
F_24 ( void * * V_99 , unsigned long V_26 , T_7 * V_100 , T_7 * V_101 )
{
struct V_102 * V_103 = NULL , * V_104 ;
T_6 V_105 = V_106 ;
unsigned long V_107 ;
T_7 * V_79 = ( T_7 * ) V_99 ; ;
T_1 V_8 = V_55 ;
int V_81 ;
V_104 = NULL ;
V_107 = V_26 / sizeof( T_7 ) ;
for ( V_81 = 0 ; V_81 < V_107 ; V_81 ++ ) {
T_6 V_108 = V_78 ;
T_7 V_109 , V_5 , V_110 , V_111 ;
void * V_112 ;
T_7 V_3 = V_79 [ V_81 ] ;
V_8 = F_4 ( V_37 , V_3 ,
& V_105 , ( void * * ) & V_103 ) ;
if ( V_8 != V_16 )
continue;
F_4 ( V_37 , V_3 , & V_108 , & V_112 ) ;
V_8 = V_12 -> V_13 ( ( unsigned long ) V_103 -> V_113 , V_103 ,
& V_109 , & V_5 , & V_110 , & V_111 ) ;
if ( V_8 == V_16 && ( ! V_104 || V_112 ) ) {
* V_100 = V_109 ;
* V_101 = V_5 ;
if ( V_112 )
break;
V_104 = V_103 ;
}
}
return V_8 ;
}
static T_1
F_25 ( void * * V_99 , unsigned long V_26 , T_7 * V_100 , T_7 * V_101 )
{
struct V_102 * V_103 = NULL , * V_104 ;
T_6 V_105 = V_106 ;
unsigned long V_107 ;
T_3 * V_79 = ( T_3 * ) V_99 ; ;
T_1 V_8 = V_55 ;
int V_81 ;
V_104 = NULL ;
V_107 = V_26 / sizeof( T_3 ) ;
for ( V_81 = 0 ; V_81 < V_107 ; V_81 ++ ) {
T_6 V_108 = V_78 ;
T_7 V_109 , V_5 , V_110 , V_111 ;
void * V_112 ;
T_3 V_3 = V_79 [ V_81 ] ;
V_8 = F_4 ( V_37 , V_3 ,
& V_105 , ( void * * ) & V_103 ) ;
if ( V_8 != V_16 )
continue;
F_4 ( V_37 , V_3 , & V_108 , & V_112 ) ;
V_8 = V_12 -> V_13 ( ( unsigned long ) V_103 -> V_113 , V_103 ,
& V_109 , & V_5 , & V_110 , & V_111 ) ;
if ( V_8 == V_16 && ( ! V_104 || V_112 ) ) {
* V_100 = V_109 ;
* V_101 = V_5 ;
if ( V_112 )
break;
V_104 = V_103 ;
}
}
return V_8 ;
}
static T_1 F_26 ( struct V_114 * V_115 , T_6 * V_105 ,
unsigned long V_26 )
{
T_1 V_8 ;
T_7 V_100 , V_101 ;
void * * V_99 = NULL ;
V_8 = F_4 ( V_21 , V_22 ,
V_26 , ( void * * ) & V_99 ) ;
if ( V_8 != V_16 )
return V_8 ;
V_8 = F_4 ( V_83 ,
V_84 ,
V_105 , NULL , & V_26 , V_99 ) ;
if ( V_8 != V_16 )
goto V_85;
V_101 = 0 ;
V_100 = 0 ;
if ( V_12 -> V_25 )
V_8 = F_25 ( V_99 , V_26 , & V_100 , & V_101 ) ;
else
V_8 = F_24 ( V_99 , V_26 , & V_100 , & V_101 ) ;
if ( ! V_100 && ! V_101 )
goto V_85;
V_115 -> V_116 = V_117 ;
V_115 -> V_118 = 32 ;
V_115 -> V_119 = V_100 ;
V_115 -> V_120 = V_101 ;
V_115 -> V_121 = 8 ;
V_115 -> V_122 = 16 ;
V_115 -> V_123 = 8 ;
V_115 -> V_124 = 8 ;
V_115 -> V_125 = 8 ;
V_115 -> V_126 = 0 ;
V_115 -> V_127 = 8 ;
V_115 -> V_128 = 24 ;
V_85:
F_4 ( V_23 , V_99 ) ;
return V_8 ;
}
void F_27 ( struct V_74 * V_74 )
{
T_6 V_129 = V_130 ;
struct V_114 * V_115 ;
T_6 V_105 = V_106 ;
T_1 V_8 ;
unsigned long V_26 ;
void * * V_131 = NULL ;
void * * V_99 = NULL ;
V_115 = & V_74 -> V_114 ;
memset ( V_115 , 0 , sizeof( * V_115 ) ) ;
V_26 = 0 ;
V_8 = F_4 ( V_83 ,
V_84 ,
& V_129 , NULL , & V_26 , V_131 ) ;
if ( V_8 == V_19 )
V_8 = F_28 ( NULL , V_115 , & V_129 , V_26 ) ;
if ( V_8 != V_16 ) {
V_26 = 0 ;
V_8 = F_4 ( V_83 ,
V_84 ,
& V_105 , NULL , & V_26 , V_99 ) ;
if ( V_8 == V_19 )
F_26 ( V_115 , & V_105 , V_26 ) ;
}
}
struct V_74 * F_29 ( struct V_132 * V_133 )
{
struct V_74 * V_74 ;
struct V_134 * V_135 ;
struct V_136 * V_82 ;
T_17 * V_33 ;
void * V_137 , * V_3 ;
T_6 V_138 = V_139 ;
int V_140 = 0 ;
T_1 V_8 ;
char * V_141 ;
T_18 * V_142 ;
T_19 * V_143 ;
int V_81 ;
unsigned long V_144 ;
unsigned long V_145 ;
V_12 = V_133 ;
V_17 = ( T_9 * ) ( unsigned long ) V_12 -> V_39 ;
V_3 = ( void * ) ( unsigned long ) V_12 -> V_146 ;
if ( V_17 -> V_82 . V_147 != V_148 )
return NULL ;
if ( V_12 -> V_25 )
F_30 ( V_12 ) ;
else
F_31 ( V_12 ) ;
V_8 = F_4 ( V_37 , V_3 ,
& V_138 , ( void * ) & V_33 ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_14 ) ;
return NULL ;
}
V_8 = F_32 ( V_17 , 0x4000 , 1 ,
( unsigned long * ) & V_74 ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_15 ) ;
return NULL ;
}
memset ( V_74 , 0x0 , 0x4000 ) ;
V_82 = & V_74 -> V_82 ;
V_135 = & V_74 -> V_134 ;
memcpy ( & V_82 -> V_149 , V_33 -> V_150 + 512 , 512 ) ;
V_82 -> V_151 = 1 ;
V_82 -> V_152 = 0xffff ;
V_82 -> V_153 = 0xAA55 ;
V_82 -> V_154 = 0x21 ;
V_141 = F_33 ( V_17 , V_33 , & V_140 ) ;
if ( ! V_141 )
goto V_155;
V_82 -> V_156 = ( unsigned long ) V_141 ;
V_74 -> V_157 = ( T_3 ) ( unsigned long ) V_141 >> 32 ;
V_82 -> V_158 = 0 ;
V_82 -> V_145 = 0 ;
memset ( V_135 , 0 , sizeof( * V_135 ) ) ;
V_8 = F_34 ( V_141 ) ;
if ( V_8 != V_16 )
goto V_159;
V_8 = F_35 ( V_17 , V_33 ,
( char * ) ( unsigned long ) V_82 -> V_156 ,
L_16 , V_82 -> V_160 ,
& V_144 , & V_145 ) ;
if ( V_8 != V_16 &&
V_82 -> V_161 & V_162 ) {
F_2 ( V_17 , L_17 ) ;
V_8 = F_35 ( V_17 , V_33 ,
( char * ) ( unsigned long ) V_82 -> V_156 ,
L_16 , - 1UL ,
& V_144 , & V_145 ) ;
}
if ( V_8 != V_16 )
goto V_159;
V_82 -> V_158 = V_144 & 0xffffffff ;
V_82 -> V_145 = V_145 & 0xffffffff ;
V_74 -> V_163 = ( T_3 ) V_144 >> 32 ;
V_74 -> V_164 = ( T_3 ) V_145 >> 32 ;
return V_74 ;
V_159:
F_36 ( V_17 , V_140 , V_82 -> V_156 ) ;
V_155:
F_36 ( V_17 , 0x4000 , ( unsigned long ) V_74 ) ;
return NULL ;
}
static void F_37 ( struct V_74 * V_75 ,
struct V_59 * V_165 , T_7 V_166 )
{
struct V_59 * V_56 ;
T_1 V_8 ;
unsigned long V_26 ;
V_165 -> type = V_167 ;
V_165 -> V_58 = V_166 * sizeof( struct V_168 ) ;
V_165 -> V_60 = 0 ;
V_56 = (struct V_59 * ) ( unsigned long ) V_75 -> V_82 . V_59 ;
while ( V_56 && V_56 -> V_60 )
V_56 = (struct V_59 * ) ( unsigned long ) V_56 -> V_60 ;
if ( V_56 )
V_56 -> V_60 = ( unsigned long ) V_165 ;
else
V_75 -> V_82 . V_59 = ( unsigned long ) V_165 ;
}
static T_1 F_38 ( struct V_74 * V_75 ,
struct V_59 * V_165 , T_7 V_169 )
{
struct V_168 * V_170 = & V_75 -> V_170 [ 0 ] ;
struct V_171 * V_172 = & V_75 -> V_171 ;
struct V_168 * V_173 = NULL ;
T_7 V_166 ;
T_7 V_174 ;
int V_81 ;
V_166 = 0 ;
V_174 = V_172 -> V_175 / V_172 -> V_176 ;
for ( V_81 = 0 ; V_81 < V_174 ; V_81 ++ ) {
T_20 * V_177 ;
unsigned int V_178 = 0 ;
unsigned long V_179 = V_172 -> V_180 ;
#ifdef F_39
V_179 |= ( T_3 ) V_172 -> V_181 << 32 ;
#endif
V_177 = ( T_20 * ) ( V_179 + ( V_81 * V_172 -> V_176 ) ) ;
switch ( V_177 -> type ) {
case V_182 :
case V_183 :
case V_184 :
case V_185 :
case V_186 :
case V_187 :
V_178 = V_188 ;
break;
case V_189 :
V_178 = V_190 ;
break;
case V_191 :
V_178 = V_192 ;
break;
case V_193 :
case V_22 :
case V_194 :
case V_195 :
case V_196 :
V_178 = V_197 ;
break;
case V_198 :
V_178 = V_199 ;
break;
case V_200 :
V_178 = V_201 ;
break;
default:
continue;
}
if ( V_173 && V_173 -> type == V_178 &&
( V_173 -> V_27 + V_173 -> V_26 ) == V_177 -> V_202 ) {
V_173 -> V_26 += V_177 -> V_203 << 12 ;
continue;
}
if ( V_166 == F_40 ( V_75 -> V_170 ) ) {
T_7 V_204 = ( V_174 - V_81 ) * sizeof( struct V_168 ) +
sizeof( struct V_59 ) ;
if ( ! V_165 || V_169 < V_204 )
return V_19 ;
V_170 = (struct V_168 * ) V_165 -> V_56 ;
}
V_170 -> V_27 = V_177 -> V_202 ;
V_170 -> V_26 = V_177 -> V_203 << V_205 ;
V_170 -> type = V_178 ;
V_173 = V_170 ++ ;
V_166 ++ ;
}
if ( V_166 > F_40 ( V_75 -> V_170 ) ) {
T_7 V_206 = V_166 - F_40 ( V_75 -> V_170 ) ;
F_37 ( V_75 , V_165 , V_206 ) ;
V_166 -= V_206 ;
}
V_75 -> V_207 = ( T_19 ) V_166 ;
return V_16 ;
}
static T_1 F_41 ( T_7 V_174 , struct V_59 * * V_165 ,
T_7 * V_169 )
{
T_1 V_8 ;
unsigned long V_26 ;
V_26 = sizeof( struct V_59 ) +
sizeof( struct V_168 ) * V_174 ;
if ( * V_165 ) {
F_4 ( V_23 , * V_165 ) ;
* V_165 = NULL ;
* V_169 = 0 ;
}
V_8 = F_4 ( V_21 , V_22 ,
V_26 , ( void * * ) V_165 ) ;
if ( V_8 == V_16 )
* V_169 = V_26 ;
return V_8 ;
}
static T_1 F_42 ( T_9 * V_208 ,
struct V_209 * V_210 ,
void * V_211 )
{
static bool V_212 = true ;
const char * V_147 ;
T_21 V_174 ;
T_1 V_8 ;
struct V_213 * V_89 = V_211 ;
if ( V_212 ) {
V_174 = * V_210 -> V_214 / * V_210 -> V_215 ;
if ( V_174 > F_40 ( V_89 -> V_74 -> V_170 ) ) {
T_7 V_206 = V_174 -
F_40 ( V_89 -> V_74 -> V_170 ) ;
V_8 = F_41 ( V_206 , & V_89 -> V_165 ,
& V_89 -> V_169 ) ;
if ( V_8 != V_16 )
return V_8 ;
}
V_212 = false ;
}
V_147 = V_89 -> V_25 ? V_216 : V_217 ;
memcpy ( & V_89 -> V_172 -> V_218 , V_147 , sizeof( T_21 ) ) ;
V_89 -> V_172 -> V_219 = ( unsigned long ) V_208 ;
V_89 -> V_172 -> V_176 = * V_210 -> V_215 ;
V_89 -> V_172 -> V_220 = * V_210 -> V_221 ;
V_89 -> V_172 -> V_180 = ( unsigned long ) * V_210 -> V_210 ;
V_89 -> V_172 -> V_175 = * V_210 -> V_222 ;
#ifdef F_39
V_89 -> V_172 -> V_223 = ( unsigned long ) V_208 >> 32 ;
V_89 -> V_172 -> V_181 = ( unsigned long ) * V_210 -> V_210 >> 32 ;
#endif
return V_16 ;
}
static T_1 F_43 ( struct V_74 * V_74 ,
void * V_3 , bool V_25 )
{
unsigned long V_224 , V_225 , V_215 , V_214 ;
T_20 * V_226 ;
struct V_59 * V_165 ;
T_21 V_169 ;
T_1 V_8 ;
T_21 V_227 ;
struct V_209 V_210 ;
struct V_213 V_211 ;
V_210 . V_210 = & V_226 ;
V_210 . V_222 = & V_224 ;
V_210 . V_215 = & V_215 ;
V_210 . V_221 = & V_227 ;
V_210 . V_228 = & V_225 ;
V_210 . V_214 = & V_214 ;
V_211 . V_74 = V_74 ;
V_211 . V_172 = & V_74 -> V_171 ;
V_211 . V_165 = NULL ;
V_211 . V_169 = 0 ;
V_211 . V_25 = V_25 ;
V_8 = F_44 ( V_17 , V_3 , & V_210 , & V_211 ,
F_42 ) ;
if ( V_8 != V_16 )
return V_8 ;
V_165 = V_211 . V_165 ;
V_169 = V_211 . V_169 ;
V_74 -> V_229 = 32 * 1024 ;
V_8 = F_38 ( V_74 , V_165 , V_169 ) ;
if ( V_8 != V_16 )
return V_8 ;
return V_16 ;
}
struct V_74 * F_45 ( struct V_132 * V_133 ,
struct V_74 * V_74 )
{
struct V_230 * V_231 = NULL ;
T_17 * V_33 ;
struct V_136 * V_82 = & V_74 -> V_82 ;
T_1 V_8 ;
struct V_232 * V_233 ;
void * V_3 ;
T_9 * V_234 ;
bool V_25 ;
V_12 = V_133 ;
V_234 = ( T_9 * ) ( unsigned long ) V_12 -> V_39 ;
V_3 = ( void * ) ( unsigned long ) V_12 -> V_146 ;
V_25 = V_12 -> V_25 ;
V_17 = V_234 ;
if ( V_17 -> V_82 . V_147 != V_148 )
goto V_155;
if ( V_25 )
F_30 ( V_12 ) ;
else
F_31 ( V_12 ) ;
F_27 ( V_74 ) ;
F_18 ( V_74 ) ;
F_22 ( V_74 ) ;
V_8 = F_4 ( V_21 , V_22 ,
sizeof( * V_231 ) , ( void * * ) & V_231 ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_18 ) ;
goto V_155;
}
V_231 -> V_26 = 0x800 ;
V_8 = F_32 ( V_17 , V_231 -> V_26 , 8 ,
( unsigned long * ) & V_231 -> V_235 ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_19 ) ;
goto V_155;
}
if ( V_82 -> V_236 != V_82 -> V_237 ) {
unsigned long V_238 = V_82 -> V_237 ;
V_8 = F_46 ( V_17 , & V_238 ,
V_82 -> V_239 , V_82 -> V_239 ,
V_82 -> V_236 ,
V_82 -> V_240 ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_20 ) ;
goto V_155;
}
V_82 -> V_236 = V_82 -> V_237 ;
V_82 -> V_237 = V_238 ;
}
V_8 = F_43 ( V_74 , V_3 , V_25 ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_21 ) ;
goto V_155;
}
memset ( ( char * ) V_231 -> V_235 , 0x0 , V_231 -> V_26 ) ;
V_233 = (struct V_232 * ) V_231 -> V_235 ;
V_233 += 2 ;
V_233 -> V_241 = 0xffff ;
V_233 -> V_242 = 0x0000 ;
V_233 -> V_243 = 0x0000 ;
V_233 -> type = V_244 | V_245 ;
V_233 -> V_246 = V_247 ;
V_233 -> V_248 = 0 ;
V_233 -> V_89 = 1 ;
V_233 -> V_249 = 0xf ;
V_233 -> V_250 = 0 ;
V_233 -> V_251 = 0 ;
V_233 -> V_177 = V_252 ;
V_233 -> V_253 = V_254 ;
V_233 -> V_255 = 0x00 ;
V_233 ++ ;
V_233 -> V_241 = 0xffff ;
V_233 -> V_242 = 0x0000 ;
V_233 -> V_243 = 0x0000 ;
V_233 -> type = V_256 | V_257 ;
V_233 -> V_246 = V_247 ;
V_233 -> V_248 = 0 ;
V_233 -> V_89 = 1 ;
V_233 -> V_249 = 0xf ;
V_233 -> V_250 = 0 ;
V_233 -> V_251 = 0 ;
V_233 -> V_177 = V_252 ;
V_233 -> V_253 = V_254 ;
V_233 -> V_255 = 0x00 ;
#ifdef F_39
V_233 ++ ;
V_233 -> V_241 = 0x0000 ;
V_233 -> V_242 = 0x0000 ;
V_233 -> V_243 = 0x0000 ;
V_233 -> type = V_258 ;
V_233 -> V_246 = 0 ;
V_233 -> V_248 = 0 ;
V_233 -> V_89 = 1 ;
V_233 -> V_249 = 0x0 ;
V_233 -> V_250 = 0 ;
V_233 -> V_251 = 0 ;
V_233 -> V_177 = 0 ;
V_233 -> V_253 = V_254 ;
V_233 -> V_255 = 0x00 ;
#endif
asm volatile("cli");
asm volatile ("lgdt %0" : : "m" (*gdt));
return V_74 ;
V_155:
F_2 ( V_17 , L_22 ) ;
return NULL ;
}
