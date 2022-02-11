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
static void F_14 ( unsigned long V_47 , T_14 * V_48 , T_14 * V_26 )
{
T_14 V_49 , V_50 ;
V_49 = 0 ;
V_50 = 0 ;
if ( V_47 ) {
while ( ! ( V_47 & 0x1 ) ) {
V_47 = V_47 >> 1 ;
V_49 ++ ;
}
while ( V_47 & 0x1 ) {
V_47 = V_47 >> 1 ;
V_50 ++ ;
}
}
* V_48 = V_49 ;
* V_26 = V_50 ;
}
static T_1
F_15 ( T_15 * V_51 , struct V_52 * * V_53 )
{
struct V_52 * V_54 = NULL ;
T_1 V_8 ;
unsigned long V_26 ;
T_16 V_55 ;
V_8 = V_12 -> V_13 ( V_51 -> V_55 , V_51 ,
V_56 , 0 , 0 ,
& V_55 ) ;
if ( V_8 != V_16 )
return V_8 ;
if ( ! V_51 -> V_57 || ! V_51 -> V_58 )
return V_59 ;
V_26 = V_51 -> V_58 + sizeof( * V_54 ) ;
V_8 = F_4 ( V_21 , V_22 , V_26 , & V_54 ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_8 ) ;
return V_8 ;
}
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
V_54 -> V_60 . type = V_61 ;
V_54 -> V_60 . V_50 = V_26 - sizeof( struct V_62 ) ;
V_54 -> V_60 . V_63 = 0 ;
V_54 -> V_64 = V_51 -> V_58 ;
* V_53 = V_54 ;
V_8 = V_12 -> V_13 ( V_51 -> V_51 . V_29 , V_51 , V_65 ,
V_66 , 1 , & ( V_54 -> V_67 ) ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_9 ) ;
goto V_68;
}
V_8 = V_12 -> V_13 ( V_51 -> V_51 . V_29 , V_51 , V_65 ,
V_69 , 1 , & ( V_54 -> V_70 ) ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_10 ) ;
goto V_68;
}
V_8 = V_12 -> V_13 ( V_51 -> V_71 , V_51 , & ( V_54 -> V_72 ) ,
& ( V_54 -> V_73 ) , & ( V_54 -> V_74 ) , & ( V_54 -> V_75 ) ) ;
if ( V_8 != V_16 )
goto V_68;
memcpy ( V_54 -> V_76 , V_51 -> V_57 , V_51 -> V_58 ) ;
return V_8 ;
V_68:
F_4 ( V_23 , V_54 ) ;
return V_8 ;
}
static void
F_16 ( struct V_77 * V_78 , void * * V_79 ,
unsigned long V_26 )
{
T_15 * V_51 = NULL ;
T_6 V_80 = V_81 ;
T_7 * V_82 = ( T_7 * ) ( unsigned long ) V_79 ;
T_1 V_8 ;
unsigned long V_83 ;
struct V_62 * V_60 ;
int V_84 ;
V_60 = (struct V_62 * ) ( unsigned long ) V_78 -> V_85 . V_62 ;
while ( V_60 && V_60 -> V_63 )
V_60 = (struct V_62 * ) ( unsigned long ) V_60 -> V_63 ;
V_83 = V_26 / sizeof( T_7 ) ;
for ( V_84 = 0 ; V_84 < V_83 ; V_84 ++ ) {
struct V_52 * V_54 = NULL ;
T_7 V_5 = V_82 [ V_84 ] ;
V_8 = F_4 ( V_37 , V_5 ,
& V_80 , ( void * * ) & V_51 ) ;
if ( V_8 != V_16 )
continue;
if ( ! V_51 )
continue;
V_8 = F_15 ( V_51 , & V_54 ) ;
if ( V_8 != V_16 )
continue;
if ( V_60 )
V_60 -> V_63 = ( unsigned long ) V_54 ;
else
V_78 -> V_85 . V_62 = ( unsigned long ) V_54 ;
V_60 = (struct V_62 * ) V_54 ;
}
}
static T_1
F_17 ( T_17 * V_51 , struct V_52 * * V_53 )
{
struct V_52 * V_54 ;
T_1 V_8 ;
unsigned long V_26 ;
T_16 V_55 ;
V_8 = V_12 -> V_13 ( V_51 -> V_55 , V_51 ,
V_56 , 0 ,
& V_55 ) ;
if ( V_8 != V_16 )
return V_8 ;
if ( ! V_51 -> V_57 || ! V_51 -> V_58 )
return V_59 ;
V_26 = V_51 -> V_58 + sizeof( * V_54 ) ;
V_8 = F_4 ( V_21 , V_22 , V_26 , & V_54 ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_8 ) ;
return V_8 ;
}
V_54 -> V_60 . type = V_61 ;
V_54 -> V_60 . V_50 = V_26 - sizeof( struct V_62 ) ;
V_54 -> V_60 . V_63 = 0 ;
V_54 -> V_64 = V_51 -> V_58 ;
* V_53 = V_54 ;
V_8 = V_12 -> V_13 ( V_51 -> V_51 . V_29 , V_51 , V_65 ,
V_66 , 1 , & ( V_54 -> V_67 ) ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_9 ) ;
goto V_68;
}
V_8 = V_12 -> V_13 ( V_51 -> V_51 . V_29 , V_51 , V_65 ,
V_69 , 1 , & ( V_54 -> V_70 ) ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_10 ) ;
goto V_68;
}
V_8 = V_12 -> V_13 ( V_51 -> V_71 , V_51 , & ( V_54 -> V_72 ) ,
& ( V_54 -> V_73 ) , & ( V_54 -> V_74 ) , & ( V_54 -> V_75 ) ) ;
if ( V_8 != V_16 )
goto V_68;
memcpy ( V_54 -> V_76 , V_51 -> V_57 , V_51 -> V_58 ) ;
return V_8 ;
V_68:
F_4 ( V_23 , V_54 ) ;
return V_8 ;
}
static void
F_18 ( struct V_77 * V_78 , void * * V_79 ,
unsigned long V_26 )
{
T_17 * V_51 = NULL ;
T_6 V_80 = V_81 ;
T_3 * V_82 = ( T_3 * ) ( unsigned long ) V_79 ;
T_1 V_8 ;
unsigned long V_83 ;
struct V_62 * V_60 ;
int V_84 ;
V_60 = (struct V_62 * ) ( unsigned long ) V_78 -> V_85 . V_62 ;
while ( V_60 && V_60 -> V_63 )
V_60 = (struct V_62 * ) ( unsigned long ) V_60 -> V_63 ;
V_83 = V_26 / sizeof( T_3 ) ;
for ( V_84 = 0 ; V_84 < V_83 ; V_84 ++ ) {
struct V_52 * V_54 = NULL ;
T_3 V_5 = V_82 [ V_84 ] ;
V_8 = F_4 ( V_37 , V_5 ,
& V_80 , ( void * * ) & V_51 ) ;
if ( V_8 != V_16 )
continue;
if ( ! V_51 )
continue;
V_8 = F_17 ( V_51 , & V_54 ) ;
if ( V_8 != V_16 )
continue;
if ( V_60 )
V_60 -> V_63 = ( unsigned long ) V_54 ;
else
V_78 -> V_85 . V_62 = ( unsigned long ) V_54 ;
V_60 = (struct V_62 * ) V_54 ;
}
}
static void F_19 ( struct V_77 * V_78 )
{
T_1 V_8 ;
void * * V_79 = NULL ;
T_6 V_80 = V_81 ;
unsigned long V_26 = 0 ;
V_8 = F_4 ( V_86 ,
V_87 ,
& V_80 , NULL , & V_26 , V_79 ) ;
if ( V_8 == V_19 ) {
V_8 = F_4 ( V_21 ,
V_22 ,
V_26 , ( void * * ) & V_79 ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_11 ) ;
return;
}
V_8 = F_4 ( V_86 ,
V_87 , & V_80 ,
NULL , & V_26 , V_79 ) ;
}
if ( V_8 != V_16 )
goto V_88;
if ( V_12 -> V_25 )
F_18 ( V_78 , V_79 , V_26 ) ;
else
F_16 ( V_78 , V_79 , V_26 ) ;
V_88:
F_4 ( V_23 , V_79 ) ;
}
static T_1
F_20 ( void * * V_89 , unsigned long V_26 , T_7 * V_90 , T_7 * V_91 )
{
struct V_92 * V_93 = NULL , * V_94 ;
T_6 V_95 = V_96 ;
unsigned long V_97 ;
T_7 * V_82 = ( T_7 * ) V_89 ; ;
T_1 V_8 ;
int V_84 ;
V_94 = NULL ;
V_97 = V_26 / sizeof( T_7 ) ;
for ( V_84 = 0 ; V_84 < V_97 ; V_84 ++ ) {
T_6 V_98 = V_81 ;
T_7 V_99 , V_5 , V_100 , V_101 ;
void * V_102 ;
T_7 V_3 = V_82 [ V_84 ] ;
V_8 = F_4 ( V_37 , V_3 ,
& V_95 , ( void * * ) & V_93 ) ;
if ( V_8 != V_16 )
continue;
F_4 ( V_37 , V_3 , & V_98 , & V_102 ) ;
V_8 = V_12 -> V_13 ( ( unsigned long ) V_93 -> V_103 , V_93 ,
& V_99 , & V_5 , & V_100 , & V_101 ) ;
if ( V_8 == V_16 && ( ! V_94 || V_102 ) ) {
* V_90 = V_99 ;
* V_91 = V_5 ;
if ( V_102 )
break;
V_94 = V_93 ;
}
}
return V_8 ;
}
static T_1
F_21 ( void * * V_89 , unsigned long V_26 , T_7 * V_90 , T_7 * V_91 )
{
struct V_92 * V_93 = NULL , * V_94 ;
T_6 V_95 = V_96 ;
unsigned long V_97 ;
T_3 * V_82 = ( T_3 * ) V_89 ; ;
T_1 V_8 ;
int V_84 ;
V_94 = NULL ;
V_97 = V_26 / sizeof( T_3 ) ;
for ( V_84 = 0 ; V_84 < V_97 ; V_84 ++ ) {
T_6 V_98 = V_81 ;
T_7 V_99 , V_5 , V_100 , V_101 ;
void * V_102 ;
T_3 V_3 = V_82 [ V_84 ] ;
V_8 = F_4 ( V_37 , V_3 ,
& V_95 , ( void * * ) & V_93 ) ;
if ( V_8 != V_16 )
continue;
F_4 ( V_37 , V_3 , & V_98 , & V_102 ) ;
V_8 = V_12 -> V_13 ( ( unsigned long ) V_93 -> V_103 , V_93 ,
& V_99 , & V_5 , & V_100 , & V_101 ) ;
if ( V_8 == V_16 && ( ! V_94 || V_102 ) ) {
* V_90 = V_99 ;
* V_91 = V_5 ;
if ( V_102 )
break;
V_94 = V_93 ;
}
}
return V_8 ;
}
static T_1 F_22 ( struct V_104 * V_105 , T_6 * V_95 ,
unsigned long V_26 )
{
T_1 V_8 ;
T_7 V_90 , V_91 ;
void * * V_89 = NULL ;
V_8 = F_4 ( V_21 , V_22 ,
V_26 , ( void * * ) & V_89 ) ;
if ( V_8 != V_16 )
return V_8 ;
V_8 = F_4 ( V_86 ,
V_87 ,
V_95 , NULL , & V_26 , V_89 ) ;
if ( V_8 != V_16 )
goto V_88;
V_91 = 0 ;
V_90 = 0 ;
if ( V_12 -> V_25 )
V_8 = F_21 ( V_89 , V_26 , & V_90 , & V_91 ) ;
else
V_8 = F_20 ( V_89 , V_26 , & V_90 , & V_91 ) ;
if ( ! V_90 && ! V_91 )
goto V_88;
V_105 -> V_106 = V_107 ;
V_105 -> V_108 = 32 ;
V_105 -> V_109 = V_90 ;
V_105 -> V_110 = V_91 ;
V_105 -> V_111 = 8 ;
V_105 -> V_112 = 16 ;
V_105 -> V_113 = 8 ;
V_105 -> V_114 = 8 ;
V_105 -> V_115 = 8 ;
V_105 -> V_116 = 0 ;
V_105 -> V_117 = 8 ;
V_105 -> V_118 = 24 ;
V_88:
F_4 ( V_23 , V_89 ) ;
return V_8 ;
}
void F_23 ( struct V_77 * V_77 )
{
T_6 V_119 = V_120 ;
struct V_104 * V_105 ;
T_6 V_95 = V_96 ;
T_1 V_8 ;
unsigned long V_26 ;
void * * V_121 = NULL ;
void * * V_89 = NULL ;
V_105 = & V_77 -> V_104 ;
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
V_26 = 0 ;
V_8 = F_4 ( V_86 ,
V_87 ,
& V_119 , NULL , & V_26 , V_121 ) ;
if ( V_8 == V_19 )
V_8 = F_24 ( NULL , V_105 , & V_119 , V_26 ) ;
if ( V_8 != V_16 ) {
V_26 = 0 ;
V_8 = F_4 ( V_86 ,
V_87 ,
& V_95 , NULL , & V_26 , V_89 ) ;
if ( V_8 == V_19 )
F_22 ( V_105 , & V_95 , V_26 ) ;
}
}
struct V_77 * F_25 ( struct V_122 * V_123 )
{
struct V_77 * V_77 ;
struct V_124 * V_125 ;
struct V_126 * V_85 ;
T_18 * V_33 ;
void * V_127 , * V_3 ;
T_6 V_128 = V_129 ;
int V_130 = 0 ;
T_1 V_8 ;
char * V_131 ;
T_19 * V_132 ;
T_14 * V_133 ;
int V_84 ;
unsigned long V_134 ;
unsigned long V_135 ;
V_12 = V_123 ;
V_17 = ( T_9 * ) ( unsigned long ) V_12 -> V_39 ;
V_3 = ( void * ) ( unsigned long ) V_12 -> V_136 ;
if ( V_17 -> V_85 . V_137 != V_138 )
return NULL ;
if ( V_12 -> V_25 )
F_26 ( V_12 ) ;
else
F_27 ( V_12 ) ;
V_8 = F_4 ( V_37 , V_3 ,
& V_128 , ( void * ) & V_33 ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_12 ) ;
return NULL ;
}
V_8 = F_28 ( V_17 , 0x4000 , 1 ,
( unsigned long * ) & V_77 ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_13 ) ;
return NULL ;
}
memset ( V_77 , 0x0 , 0x4000 ) ;
V_85 = & V_77 -> V_85 ;
V_125 = & V_77 -> V_124 ;
memcpy ( & V_85 -> V_139 , V_33 -> V_140 + 512 , 512 ) ;
V_85 -> V_141 = 1 ;
V_85 -> V_142 = 0xffff ;
V_85 -> V_143 = 0xAA55 ;
V_85 -> V_144 = 0x21 ;
V_131 = F_29 ( V_17 , V_33 , & V_130 ) ;
if ( ! V_131 )
goto V_145;
V_85 -> V_146 = ( unsigned long ) V_131 ;
V_77 -> V_147 = ( T_3 ) ( unsigned long ) V_131 >> 32 ;
V_85 -> V_148 = 0 ;
V_85 -> V_135 = 0 ;
memset ( V_125 , 0 , sizeof( * V_125 ) ) ;
V_8 = F_30 ( V_131 ) ;
if ( V_8 != V_16 )
goto V_149;
V_8 = F_31 ( V_17 , V_33 ,
( char * ) ( unsigned long ) V_85 -> V_146 ,
L_14 , V_85 -> V_150 ,
& V_134 , & V_135 ) ;
if ( V_8 != V_16 &&
V_85 -> V_151 & V_152 ) {
F_2 ( V_17 , L_15 ) ;
V_8 = F_31 ( V_17 , V_33 ,
( char * ) ( unsigned long ) V_85 -> V_146 ,
L_14 , - 1UL ,
& V_134 , & V_135 ) ;
}
if ( V_8 != V_16 )
goto V_149;
V_85 -> V_148 = V_134 & 0xffffffff ;
V_85 -> V_135 = V_135 & 0xffffffff ;
V_77 -> V_153 = ( T_3 ) V_134 >> 32 ;
V_77 -> V_154 = ( T_3 ) V_135 >> 32 ;
return V_77 ;
V_149:
F_32 ( V_17 , V_130 , V_85 -> V_146 ) ;
V_145:
F_32 ( V_17 , 0x4000 , ( unsigned long ) V_77 ) ;
return NULL ;
}
static void F_33 ( struct V_77 * V_78 ,
struct V_62 * V_155 , T_7 V_156 )
{
struct V_62 * V_60 ;
T_1 V_8 ;
unsigned long V_26 ;
V_155 -> type = V_157 ;
V_155 -> V_50 = V_156 * sizeof( struct V_158 ) ;
V_155 -> V_63 = 0 ;
V_60 = (struct V_62 * ) ( unsigned long ) V_78 -> V_85 . V_62 ;
while ( V_60 && V_60 -> V_63 )
V_60 = (struct V_62 * ) ( unsigned long ) V_60 -> V_63 ;
if ( V_60 )
V_60 -> V_63 = ( unsigned long ) V_155 ;
else
V_78 -> V_85 . V_62 = ( unsigned long ) V_155 ;
}
static T_1 F_34 ( struct V_77 * V_78 ,
struct V_62 * V_155 , T_7 V_159 )
{
struct V_158 * V_160 = & V_78 -> V_160 [ 0 ] ;
struct V_161 * V_162 = & V_78 -> V_161 ;
struct V_158 * V_163 = NULL ;
T_7 V_156 ;
T_7 V_164 ;
int V_84 ;
V_156 = 0 ;
V_164 = V_162 -> V_165 / V_162 -> V_166 ;
for ( V_84 = 0 ; V_84 < V_164 ; V_84 ++ ) {
T_20 * V_167 ;
unsigned int V_168 = 0 ;
unsigned long V_169 = V_162 -> V_170 ;
#ifdef F_35
V_169 |= ( T_3 ) V_162 -> V_171 << 32 ;
#endif
V_167 = ( T_20 * ) ( V_169 + ( V_84 * V_162 -> V_166 ) ) ;
switch ( V_167 -> type ) {
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
V_168 = V_178 ;
break;
case V_179 :
V_168 = V_180 ;
break;
case V_181 :
V_168 = V_182 ;
break;
case V_183 :
case V_22 :
case V_184 :
case V_185 :
case V_186 :
V_168 = V_187 ;
break;
case V_188 :
V_168 = V_189 ;
break;
case V_190 :
V_168 = V_191 ;
break;
default:
continue;
}
if ( V_163 && V_163 -> type == V_168 &&
( V_163 -> V_27 + V_163 -> V_26 ) == V_167 -> V_192 ) {
V_163 -> V_26 += V_167 -> V_193 << 12 ;
continue;
}
if ( V_156 == F_36 ( V_78 -> V_160 ) ) {
T_7 V_194 = ( V_164 - V_84 ) * sizeof( struct V_158 ) +
sizeof( struct V_62 ) ;
if ( ! V_155 || V_159 < V_194 )
return V_19 ;
V_160 = (struct V_158 * ) V_155 -> V_60 ;
}
V_160 -> V_27 = V_167 -> V_192 ;
V_160 -> V_26 = V_167 -> V_193 << V_195 ;
V_160 -> type = V_168 ;
V_163 = V_160 ++ ;
V_156 ++ ;
}
if ( V_156 > F_36 ( V_78 -> V_160 ) ) {
T_7 V_196 = V_156 - F_36 ( V_78 -> V_160 ) ;
F_33 ( V_78 , V_155 , V_196 ) ;
V_156 -= V_196 ;
}
V_78 -> V_197 = ( T_14 ) V_156 ;
return V_16 ;
}
static T_1 F_37 ( T_7 V_164 , struct V_62 * * V_155 ,
T_7 * V_159 )
{
T_1 V_8 ;
unsigned long V_26 ;
V_26 = sizeof( struct V_62 ) +
sizeof( struct V_158 ) * V_164 ;
if ( * V_155 ) {
F_4 ( V_23 , * V_155 ) ;
* V_155 = NULL ;
* V_159 = 0 ;
}
V_8 = F_4 ( V_21 , V_22 ,
V_26 , ( void * * ) V_155 ) ;
if ( V_8 == V_16 )
* V_159 = V_26 ;
return V_8 ;
}
static T_1 F_38 ( T_9 * V_198 ,
struct V_199 * V_200 ,
void * V_201 )
{
static bool V_49 = true ;
const char * V_137 ;
T_21 V_164 ;
T_1 V_8 ;
struct V_202 * V_203 = V_201 ;
if ( V_49 ) {
V_164 = * V_200 -> V_204 / * V_200 -> V_205 ;
if ( V_164 > F_36 ( V_203 -> V_77 -> V_160 ) ) {
T_7 V_196 = V_164 -
F_36 ( V_203 -> V_77 -> V_160 ) ;
V_8 = F_37 ( V_196 , & V_203 -> V_155 ,
& V_203 -> V_159 ) ;
if ( V_8 != V_16 )
return V_8 ;
}
V_49 = false ;
}
V_137 = V_203 -> V_25 ? V_206 : V_207 ;
memcpy ( & V_203 -> V_162 -> V_208 , V_137 , sizeof( T_21 ) ) ;
V_203 -> V_162 -> V_209 = ( unsigned long ) V_198 ;
V_203 -> V_162 -> V_166 = * V_200 -> V_205 ;
V_203 -> V_162 -> V_210 = * V_200 -> V_211 ;
V_203 -> V_162 -> V_170 = ( unsigned long ) * V_200 -> V_200 ;
V_203 -> V_162 -> V_165 = * V_200 -> V_212 ;
#ifdef F_35
V_203 -> V_162 -> V_213 = ( unsigned long ) V_198 >> 32 ;
V_203 -> V_162 -> V_171 = ( unsigned long ) * V_200 -> V_200 >> 32 ;
#endif
return V_16 ;
}
static T_1 F_39 ( struct V_77 * V_77 ,
void * V_3 , bool V_25 )
{
unsigned long V_214 , V_215 , V_205 , V_204 ;
T_20 * V_216 ;
struct V_62 * V_155 ;
T_21 V_159 ;
T_1 V_8 ;
T_21 V_217 ;
struct V_199 V_200 ;
struct V_202 V_201 ;
V_200 . V_200 = & V_216 ;
V_200 . V_212 = & V_214 ;
V_200 . V_205 = & V_205 ;
V_200 . V_211 = & V_217 ;
V_200 . V_218 = & V_215 ;
V_200 . V_204 = & V_204 ;
V_201 . V_77 = V_77 ;
V_201 . V_162 = & V_77 -> V_161 ;
V_201 . V_155 = NULL ;
V_201 . V_159 = 0 ;
V_201 . V_25 = V_25 ;
V_8 = F_40 ( V_17 , V_3 , & V_200 , & V_201 ,
F_38 ) ;
if ( V_8 != V_16 )
return V_8 ;
V_155 = V_201 . V_155 ;
V_159 = V_201 . V_159 ;
V_77 -> V_219 = 32 * 1024 ;
V_8 = F_34 ( V_77 , V_155 , V_159 ) ;
if ( V_8 != V_16 )
return V_8 ;
return V_16 ;
}
struct V_77 * F_41 ( struct V_122 * V_123 ,
struct V_77 * V_77 )
{
struct V_220 * V_221 = NULL ;
T_18 * V_33 ;
struct V_126 * V_85 = & V_77 -> V_85 ;
T_1 V_8 ;
struct V_222 * V_223 ;
void * V_3 ;
T_9 * V_224 ;
bool V_25 ;
V_12 = V_123 ;
V_224 = ( T_9 * ) ( unsigned long ) V_12 -> V_39 ;
V_3 = ( void * ) ( unsigned long ) V_12 -> V_136 ;
V_25 = V_12 -> V_25 ;
V_17 = V_224 ;
if ( V_17 -> V_85 . V_137 != V_138 )
goto V_145;
if ( V_25 )
F_26 ( V_12 ) ;
else
F_27 ( V_12 ) ;
F_23 ( V_77 ) ;
F_19 ( V_77 ) ;
V_8 = F_4 ( V_21 , V_22 ,
sizeof( * V_221 ) , ( void * * ) & V_221 ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_16 ) ;
goto V_145;
}
V_221 -> V_26 = 0x800 ;
V_8 = F_28 ( V_17 , V_221 -> V_26 , 8 ,
( unsigned long * ) & V_221 -> V_225 ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_17 ) ;
goto V_145;
}
if ( V_85 -> V_226 != V_85 -> V_227 ) {
unsigned long V_228 = V_85 -> V_227 ;
V_8 = F_42 ( V_17 , & V_228 ,
V_85 -> V_229 , V_85 -> V_229 ,
V_85 -> V_226 ,
V_85 -> V_230 ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_18 ) ;
goto V_145;
}
V_85 -> V_226 = V_85 -> V_227 ;
V_85 -> V_227 = V_228 ;
}
V_8 = F_39 ( V_77 , V_3 , V_25 ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_19 ) ;
goto V_145;
}
memset ( ( char * ) V_221 -> V_225 , 0x0 , V_221 -> V_26 ) ;
V_223 = (struct V_222 * ) V_221 -> V_225 ;
V_223 += 2 ;
V_223 -> V_231 = 0xffff ;
V_223 -> V_232 = 0x0000 ;
V_223 -> V_233 = 0x0000 ;
V_223 -> type = V_234 | V_235 ;
V_223 -> V_236 = V_237 ;
V_223 -> V_238 = 0 ;
V_223 -> V_203 = 1 ;
V_223 -> V_239 = 0xf ;
V_223 -> V_240 = 0 ;
V_223 -> V_241 = 0 ;
V_223 -> V_167 = V_242 ;
V_223 -> V_243 = V_244 ;
V_223 -> V_245 = 0x00 ;
V_223 ++ ;
V_223 -> V_231 = 0xffff ;
V_223 -> V_232 = 0x0000 ;
V_223 -> V_233 = 0x0000 ;
V_223 -> type = V_246 | V_247 ;
V_223 -> V_236 = V_237 ;
V_223 -> V_238 = 0 ;
V_223 -> V_203 = 1 ;
V_223 -> V_239 = 0xf ;
V_223 -> V_240 = 0 ;
V_223 -> V_241 = 0 ;
V_223 -> V_167 = V_242 ;
V_223 -> V_243 = V_244 ;
V_223 -> V_245 = 0x00 ;
#ifdef F_35
V_223 ++ ;
V_223 -> V_231 = 0x0000 ;
V_223 -> V_232 = 0x0000 ;
V_223 -> V_233 = 0x0000 ;
V_223 -> type = V_248 ;
V_223 -> V_236 = 0 ;
V_223 -> V_238 = 0 ;
V_223 -> V_203 = 1 ;
V_223 -> V_239 = 0x0 ;
V_223 -> V_240 = 0 ;
V_223 -> V_241 = 0 ;
V_223 -> V_167 = 0 ;
V_223 -> V_243 = V_244 ;
V_223 -> V_245 = 0x00 ;
#endif
asm volatile("cli");
asm volatile ("lgdt %0" : : "m" (*gdt));
return V_77 ;
V_145:
F_2 ( V_17 , L_20 ) ;
return NULL ;
}
