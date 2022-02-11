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
static T_1
F_19 ( void * * V_86 , unsigned long V_26 , T_7 * V_87 , T_7 * V_88 )
{
struct V_89 * V_90 = NULL , * V_91 ;
T_6 V_92 = V_93 ;
unsigned long V_94 ;
T_7 * V_79 = ( T_7 * ) V_86 ; ;
T_1 V_8 = V_55 ;
int V_81 ;
V_91 = NULL ;
V_94 = V_26 / sizeof( T_7 ) ;
for ( V_81 = 0 ; V_81 < V_94 ; V_81 ++ ) {
T_6 V_95 = V_78 ;
T_7 V_96 , V_5 , V_97 , V_98 ;
void * V_99 ;
T_7 V_3 = V_79 [ V_81 ] ;
V_8 = F_4 ( V_37 , V_3 ,
& V_92 , ( void * * ) & V_90 ) ;
if ( V_8 != V_16 )
continue;
F_4 ( V_37 , V_3 , & V_95 , & V_99 ) ;
V_8 = V_12 -> V_13 ( ( unsigned long ) V_90 -> V_100 , V_90 ,
& V_96 , & V_5 , & V_97 , & V_98 ) ;
if ( V_8 == V_16 && ( ! V_91 || V_99 ) ) {
* V_87 = V_96 ;
* V_88 = V_5 ;
if ( V_99 )
break;
V_91 = V_90 ;
}
}
return V_8 ;
}
static T_1
F_20 ( void * * V_86 , unsigned long V_26 , T_7 * V_87 , T_7 * V_88 )
{
struct V_89 * V_90 = NULL , * V_91 ;
T_6 V_92 = V_93 ;
unsigned long V_94 ;
T_3 * V_79 = ( T_3 * ) V_86 ; ;
T_1 V_8 = V_55 ;
int V_81 ;
V_91 = NULL ;
V_94 = V_26 / sizeof( T_3 ) ;
for ( V_81 = 0 ; V_81 < V_94 ; V_81 ++ ) {
T_6 V_95 = V_78 ;
T_7 V_96 , V_5 , V_97 , V_98 ;
void * V_99 ;
T_3 V_3 = V_79 [ V_81 ] ;
V_8 = F_4 ( V_37 , V_3 ,
& V_92 , ( void * * ) & V_90 ) ;
if ( V_8 != V_16 )
continue;
F_4 ( V_37 , V_3 , & V_95 , & V_99 ) ;
V_8 = V_12 -> V_13 ( ( unsigned long ) V_90 -> V_100 , V_90 ,
& V_96 , & V_5 , & V_97 , & V_98 ) ;
if ( V_8 == V_16 && ( ! V_91 || V_99 ) ) {
* V_87 = V_96 ;
* V_88 = V_5 ;
if ( V_99 )
break;
V_91 = V_90 ;
}
}
return V_8 ;
}
static T_1 F_21 ( struct V_101 * V_102 , T_6 * V_92 ,
unsigned long V_26 )
{
T_1 V_8 ;
T_7 V_87 , V_88 ;
void * * V_86 = NULL ;
V_8 = F_4 ( V_21 , V_22 ,
V_26 , ( void * * ) & V_86 ) ;
if ( V_8 != V_16 )
return V_8 ;
V_8 = F_4 ( V_83 ,
V_84 ,
V_92 , NULL , & V_26 , V_86 ) ;
if ( V_8 != V_16 )
goto V_85;
V_88 = 0 ;
V_87 = 0 ;
if ( V_12 -> V_25 )
V_8 = F_20 ( V_86 , V_26 , & V_87 , & V_88 ) ;
else
V_8 = F_19 ( V_86 , V_26 , & V_87 , & V_88 ) ;
if ( ! V_87 && ! V_88 )
goto V_85;
V_102 -> V_103 = V_104 ;
V_102 -> V_105 = 32 ;
V_102 -> V_106 = V_87 ;
V_102 -> V_107 = V_88 ;
V_102 -> V_108 = 8 ;
V_102 -> V_109 = 16 ;
V_102 -> V_110 = 8 ;
V_102 -> V_111 = 8 ;
V_102 -> V_112 = 8 ;
V_102 -> V_113 = 0 ;
V_102 -> V_114 = 8 ;
V_102 -> V_115 = 24 ;
V_85:
F_4 ( V_23 , V_86 ) ;
return V_8 ;
}
void F_22 ( struct V_74 * V_74 )
{
T_6 V_116 = V_117 ;
struct V_101 * V_102 ;
T_6 V_92 = V_93 ;
T_1 V_8 ;
unsigned long V_26 ;
void * * V_118 = NULL ;
void * * V_86 = NULL ;
V_102 = & V_74 -> V_101 ;
memset ( V_102 , 0 , sizeof( * V_102 ) ) ;
V_26 = 0 ;
V_8 = F_4 ( V_83 ,
V_84 ,
& V_116 , NULL , & V_26 , V_118 ) ;
if ( V_8 == V_19 )
V_8 = F_23 ( NULL , V_102 , & V_116 , V_26 ) ;
if ( V_8 != V_16 ) {
V_26 = 0 ;
V_8 = F_4 ( V_83 ,
V_84 ,
& V_92 , NULL , & V_26 , V_86 ) ;
if ( V_8 == V_19 )
F_21 ( V_102 , & V_92 , V_26 ) ;
}
}
struct V_74 * F_24 ( struct V_119 * V_120 )
{
struct V_74 * V_74 ;
struct V_121 * V_122 ;
struct V_123 * V_82 ;
T_17 * V_33 ;
void * V_124 , * V_3 ;
T_6 V_125 = V_126 ;
int V_127 = 0 ;
T_1 V_8 ;
char * V_128 ;
T_18 * V_129 ;
T_19 * V_130 ;
int V_81 ;
unsigned long V_131 ;
unsigned long V_132 ;
V_12 = V_120 ;
V_17 = ( T_9 * ) ( unsigned long ) V_12 -> V_39 ;
V_3 = ( void * ) ( unsigned long ) V_12 -> V_133 ;
if ( V_17 -> V_82 . V_134 != V_135 )
return NULL ;
if ( V_12 -> V_25 )
F_25 ( V_12 ) ;
else
F_26 ( V_12 ) ;
V_8 = F_4 ( V_37 , V_3 ,
& V_125 , ( void * ) & V_33 ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_12 ) ;
return NULL ;
}
V_8 = F_27 ( V_17 , 0x4000 , 1 ,
( unsigned long * ) & V_74 ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_13 ) ;
return NULL ;
}
memset ( V_74 , 0x0 , 0x4000 ) ;
V_82 = & V_74 -> V_82 ;
V_122 = & V_74 -> V_121 ;
memcpy ( & V_82 -> V_136 , V_33 -> V_137 + 512 , 512 ) ;
V_82 -> V_138 = 1 ;
V_82 -> V_139 = 0xffff ;
V_82 -> V_140 = 0xAA55 ;
V_82 -> V_141 = 0x21 ;
V_128 = F_28 ( V_17 , V_33 , & V_127 ) ;
if ( ! V_128 )
goto V_142;
V_82 -> V_143 = ( unsigned long ) V_128 ;
V_74 -> V_144 = ( T_3 ) ( unsigned long ) V_128 >> 32 ;
V_82 -> V_145 = 0 ;
V_82 -> V_132 = 0 ;
memset ( V_122 , 0 , sizeof( * V_122 ) ) ;
V_8 = F_29 ( V_128 ) ;
if ( V_8 != V_16 )
goto V_146;
V_8 = F_30 ( V_17 , V_33 ,
( char * ) ( unsigned long ) V_82 -> V_143 ,
L_14 , V_82 -> V_147 ,
& V_131 , & V_132 ) ;
if ( V_8 != V_16 &&
V_82 -> V_148 & V_149 ) {
F_2 ( V_17 , L_15 ) ;
V_8 = F_30 ( V_17 , V_33 ,
( char * ) ( unsigned long ) V_82 -> V_143 ,
L_14 , - 1UL ,
& V_131 , & V_132 ) ;
}
if ( V_8 != V_16 )
goto V_146;
V_82 -> V_145 = V_131 & 0xffffffff ;
V_82 -> V_132 = V_132 & 0xffffffff ;
V_74 -> V_150 = ( T_3 ) V_131 >> 32 ;
V_74 -> V_151 = ( T_3 ) V_132 >> 32 ;
return V_74 ;
V_146:
F_31 ( V_17 , V_127 , V_82 -> V_143 ) ;
V_142:
F_31 ( V_17 , 0x4000 , ( unsigned long ) V_74 ) ;
return NULL ;
}
static void F_32 ( struct V_74 * V_75 ,
struct V_59 * V_152 , T_7 V_153 )
{
struct V_59 * V_56 ;
T_1 V_8 ;
unsigned long V_26 ;
V_152 -> type = V_154 ;
V_152 -> V_58 = V_153 * sizeof( struct V_155 ) ;
V_152 -> V_60 = 0 ;
V_56 = (struct V_59 * ) ( unsigned long ) V_75 -> V_82 . V_59 ;
while ( V_56 && V_56 -> V_60 )
V_56 = (struct V_59 * ) ( unsigned long ) V_56 -> V_60 ;
if ( V_56 )
V_56 -> V_60 = ( unsigned long ) V_152 ;
else
V_75 -> V_82 . V_59 = ( unsigned long ) V_152 ;
}
static T_1 F_33 ( struct V_74 * V_75 ,
struct V_59 * V_152 , T_7 V_156 )
{
struct V_155 * V_157 = & V_75 -> V_157 [ 0 ] ;
struct V_158 * V_159 = & V_75 -> V_158 ;
struct V_155 * V_160 = NULL ;
T_7 V_153 ;
T_7 V_161 ;
int V_81 ;
V_153 = 0 ;
V_161 = V_159 -> V_162 / V_159 -> V_163 ;
for ( V_81 = 0 ; V_81 < V_161 ; V_81 ++ ) {
T_20 * V_164 ;
unsigned int V_165 = 0 ;
unsigned long V_166 = V_159 -> V_167 ;
#ifdef F_34
V_166 |= ( T_3 ) V_159 -> V_168 << 32 ;
#endif
V_164 = ( T_20 * ) ( V_166 + ( V_81 * V_159 -> V_163 ) ) ;
switch ( V_164 -> type ) {
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
V_165 = V_175 ;
break;
case V_176 :
V_165 = V_177 ;
break;
case V_178 :
V_165 = V_179 ;
break;
case V_180 :
case V_22 :
case V_181 :
case V_182 :
case V_183 :
V_165 = V_184 ;
break;
case V_185 :
V_165 = V_186 ;
break;
case V_187 :
V_165 = V_188 ;
break;
default:
continue;
}
if ( V_160 && V_160 -> type == V_165 &&
( V_160 -> V_27 + V_160 -> V_26 ) == V_164 -> V_189 ) {
V_160 -> V_26 += V_164 -> V_190 << 12 ;
continue;
}
if ( V_153 == F_35 ( V_75 -> V_157 ) ) {
T_7 V_191 = ( V_161 - V_81 ) * sizeof( struct V_155 ) +
sizeof( struct V_59 ) ;
if ( ! V_152 || V_156 < V_191 )
return V_19 ;
V_157 = (struct V_155 * ) V_152 -> V_56 ;
}
V_157 -> V_27 = V_164 -> V_189 ;
V_157 -> V_26 = V_164 -> V_190 << V_192 ;
V_157 -> type = V_165 ;
V_160 = V_157 ++ ;
V_153 ++ ;
}
if ( V_153 > F_35 ( V_75 -> V_157 ) ) {
T_7 V_193 = V_153 - F_35 ( V_75 -> V_157 ) ;
F_32 ( V_75 , V_152 , V_193 ) ;
V_153 -= V_193 ;
}
V_75 -> V_194 = ( T_19 ) V_153 ;
return V_16 ;
}
static T_1 F_36 ( T_7 V_161 , struct V_59 * * V_152 ,
T_7 * V_156 )
{
T_1 V_8 ;
unsigned long V_26 ;
V_26 = sizeof( struct V_59 ) +
sizeof( struct V_155 ) * V_161 ;
if ( * V_152 ) {
F_4 ( V_23 , * V_152 ) ;
* V_152 = NULL ;
* V_156 = 0 ;
}
V_8 = F_4 ( V_21 , V_22 ,
V_26 , ( void * * ) V_152 ) ;
if ( V_8 == V_16 )
* V_156 = V_26 ;
return V_8 ;
}
static T_1 F_37 ( T_9 * V_195 ,
struct V_196 * V_197 ,
void * V_198 )
{
static bool V_199 = true ;
const char * V_134 ;
T_21 V_161 ;
T_1 V_8 ;
struct V_200 * V_201 = V_198 ;
if ( V_199 ) {
V_161 = * V_197 -> V_202 / * V_197 -> V_203 ;
if ( V_161 > F_35 ( V_201 -> V_74 -> V_157 ) ) {
T_7 V_193 = V_161 -
F_35 ( V_201 -> V_74 -> V_157 ) ;
V_8 = F_36 ( V_193 , & V_201 -> V_152 ,
& V_201 -> V_156 ) ;
if ( V_8 != V_16 )
return V_8 ;
}
V_199 = false ;
}
V_134 = V_201 -> V_25 ? V_204 : V_205 ;
memcpy ( & V_201 -> V_159 -> V_206 , V_134 , sizeof( T_21 ) ) ;
V_201 -> V_159 -> V_207 = ( unsigned long ) V_195 ;
V_201 -> V_159 -> V_163 = * V_197 -> V_203 ;
V_201 -> V_159 -> V_208 = * V_197 -> V_209 ;
V_201 -> V_159 -> V_167 = ( unsigned long ) * V_197 -> V_197 ;
V_201 -> V_159 -> V_162 = * V_197 -> V_210 ;
#ifdef F_34
V_201 -> V_159 -> V_211 = ( unsigned long ) V_195 >> 32 ;
V_201 -> V_159 -> V_168 = ( unsigned long ) * V_197 -> V_197 >> 32 ;
#endif
return V_16 ;
}
static T_1 F_38 ( struct V_74 * V_74 ,
void * V_3 , bool V_25 )
{
unsigned long V_212 , V_213 , V_203 , V_202 ;
T_20 * V_214 ;
struct V_59 * V_152 ;
T_21 V_156 ;
T_1 V_8 ;
T_21 V_215 ;
struct V_196 V_197 ;
struct V_200 V_198 ;
V_197 . V_197 = & V_214 ;
V_197 . V_210 = & V_212 ;
V_197 . V_203 = & V_203 ;
V_197 . V_209 = & V_215 ;
V_197 . V_216 = & V_213 ;
V_197 . V_202 = & V_202 ;
V_198 . V_74 = V_74 ;
V_198 . V_159 = & V_74 -> V_158 ;
V_198 . V_152 = NULL ;
V_198 . V_156 = 0 ;
V_198 . V_25 = V_25 ;
V_8 = F_39 ( V_17 , V_3 , & V_197 , & V_198 ,
F_37 ) ;
if ( V_8 != V_16 )
return V_8 ;
V_152 = V_198 . V_152 ;
V_156 = V_198 . V_156 ;
V_74 -> V_217 = 32 * 1024 ;
V_8 = F_33 ( V_74 , V_152 , V_156 ) ;
if ( V_8 != V_16 )
return V_8 ;
return V_16 ;
}
struct V_74 * F_40 ( struct V_119 * V_120 ,
struct V_74 * V_74 )
{
struct V_218 * V_219 = NULL ;
T_17 * V_33 ;
struct V_123 * V_82 = & V_74 -> V_82 ;
T_1 V_8 ;
struct V_220 * V_221 ;
void * V_3 ;
T_9 * V_222 ;
bool V_25 ;
V_12 = V_120 ;
V_222 = ( T_9 * ) ( unsigned long ) V_12 -> V_39 ;
V_3 = ( void * ) ( unsigned long ) V_12 -> V_133 ;
V_25 = V_12 -> V_25 ;
V_17 = V_222 ;
if ( V_17 -> V_82 . V_134 != V_135 )
goto V_142;
if ( V_25 )
F_25 ( V_12 ) ;
else
F_26 ( V_12 ) ;
F_22 ( V_74 ) ;
F_18 ( V_74 ) ;
V_8 = F_4 ( V_21 , V_22 ,
sizeof( * V_219 ) , ( void * * ) & V_219 ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_16 ) ;
goto V_142;
}
V_219 -> V_26 = 0x800 ;
V_8 = F_27 ( V_17 , V_219 -> V_26 , 8 ,
( unsigned long * ) & V_219 -> V_223 ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_17 ) ;
goto V_142;
}
if ( V_82 -> V_224 != V_82 -> V_225 ) {
unsigned long V_226 = V_82 -> V_225 ;
V_8 = F_41 ( V_17 , & V_226 ,
V_82 -> V_227 , V_82 -> V_227 ,
V_82 -> V_224 ,
V_82 -> V_228 ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_18 ) ;
goto V_142;
}
V_82 -> V_224 = V_82 -> V_225 ;
V_82 -> V_225 = V_226 ;
}
V_8 = F_38 ( V_74 , V_3 , V_25 ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_19 ) ;
goto V_142;
}
memset ( ( char * ) V_219 -> V_223 , 0x0 , V_219 -> V_26 ) ;
V_221 = (struct V_220 * ) V_219 -> V_223 ;
V_221 += 2 ;
V_221 -> V_229 = 0xffff ;
V_221 -> V_230 = 0x0000 ;
V_221 -> V_231 = 0x0000 ;
V_221 -> type = V_232 | V_233 ;
V_221 -> V_234 = V_235 ;
V_221 -> V_236 = 0 ;
V_221 -> V_201 = 1 ;
V_221 -> V_237 = 0xf ;
V_221 -> V_238 = 0 ;
V_221 -> V_239 = 0 ;
V_221 -> V_164 = V_240 ;
V_221 -> V_241 = V_242 ;
V_221 -> V_243 = 0x00 ;
V_221 ++ ;
V_221 -> V_229 = 0xffff ;
V_221 -> V_230 = 0x0000 ;
V_221 -> V_231 = 0x0000 ;
V_221 -> type = V_244 | V_245 ;
V_221 -> V_234 = V_235 ;
V_221 -> V_236 = 0 ;
V_221 -> V_201 = 1 ;
V_221 -> V_237 = 0xf ;
V_221 -> V_238 = 0 ;
V_221 -> V_239 = 0 ;
V_221 -> V_164 = V_240 ;
V_221 -> V_241 = V_242 ;
V_221 -> V_243 = 0x00 ;
#ifdef F_34
V_221 ++ ;
V_221 -> V_229 = 0x0000 ;
V_221 -> V_230 = 0x0000 ;
V_221 -> V_231 = 0x0000 ;
V_221 -> type = V_246 ;
V_221 -> V_234 = 0 ;
V_221 -> V_236 = 0 ;
V_221 -> V_201 = 1 ;
V_221 -> V_237 = 0x0 ;
V_221 -> V_238 = 0 ;
V_221 -> V_239 = 0 ;
V_221 -> V_164 = 0 ;
V_221 -> V_241 = V_242 ;
V_221 -> V_243 = 0x00 ;
#endif
asm volatile("cli");
asm volatile ("lgdt %0" : : "m" (*gdt));
return V_74 ;
V_142:
F_2 ( V_17 , L_20 ) ;
return NULL ;
}
