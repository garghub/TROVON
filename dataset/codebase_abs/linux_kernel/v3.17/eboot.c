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
if ( V_8 != V_16 )
return V_8 ;
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
V_54 -> V_60 . type = V_61 ;
V_54 -> V_60 . V_50 = V_26 - sizeof( struct V_62 ) ;
V_54 -> V_60 . V_63 = 0 ;
V_54 -> V_64 = V_51 -> V_58 ;
* V_53 = V_54 ;
V_8 = V_12 -> V_13 ( V_51 -> V_51 . V_29 , V_51 , V_65 ,
V_66 , 1 , & ( V_54 -> V_67 ) ) ;
if ( V_8 != V_16 )
goto V_68;
V_8 = V_12 -> V_13 ( V_51 -> V_51 . V_29 , V_51 , V_65 ,
V_69 , 1 , & ( V_54 -> V_70 ) ) ;
if ( V_8 != V_16 )
goto V_68;
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
if ( V_8 != V_16 )
return V_8 ;
V_54 -> V_60 . type = V_61 ;
V_54 -> V_60 . V_50 = V_26 - sizeof( struct V_62 ) ;
V_54 -> V_60 . V_63 = 0 ;
V_54 -> V_64 = V_51 -> V_58 ;
* V_53 = V_54 ;
V_8 = V_12 -> V_13 ( V_51 -> V_51 . V_29 , V_51 , V_65 ,
V_66 , 1 , & ( V_54 -> V_67 ) ) ;
if ( V_8 != V_16 )
goto V_68;
V_8 = V_12 -> V_13 ( V_51 -> V_51 . V_29 , V_51 , V_65 ,
V_69 , 1 , & ( V_54 -> V_70 ) ) ;
if ( V_8 != V_16 )
goto V_68;
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
if ( V_8 != V_16 )
return;
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
static void
F_20 ( struct V_89 * V_90 , T_7 V_91 ,
struct V_92 V_93 , int V_94 )
{
if ( V_94 == V_95 ) {
V_90 -> V_96 = 32 ;
V_90 -> V_97 = V_91 * 4 ;
V_90 -> V_98 = 8 ;
V_90 -> V_99 = 0 ;
V_90 -> V_100 = 8 ;
V_90 -> V_101 = 8 ;
V_90 -> V_102 = 8 ;
V_90 -> V_103 = 16 ;
V_90 -> V_104 = 8 ;
V_90 -> V_105 = 24 ;
} else if ( V_94 == V_106 ) {
V_90 -> V_96 = 32 ;
V_90 -> V_97 = V_91 * 4 ;
V_90 -> V_98 = 8 ;
V_90 -> V_99 = 16 ;
V_90 -> V_100 = 8 ;
V_90 -> V_101 = 8 ;
V_90 -> V_102 = 8 ;
V_90 -> V_103 = 0 ;
V_90 -> V_104 = 8 ;
V_90 -> V_105 = 24 ;
} else if ( V_94 == V_107 ) {
F_14 ( V_93 . V_108 , & V_90 -> V_99 , & V_90 -> V_98 ) ;
F_14 ( V_93 . V_109 , & V_90 -> V_101 ,
& V_90 -> V_100 ) ;
F_14 ( V_93 . V_110 , & V_90 -> V_103 , & V_90 -> V_102 ) ;
F_14 ( V_93 . V_111 , & V_90 -> V_105 ,
& V_90 -> V_104 ) ;
V_90 -> V_96 = V_90 -> V_98 + V_90 -> V_100 +
V_90 -> V_102 + V_90 -> V_104 ;
V_90 -> V_97 = ( V_91 * V_90 -> V_96 ) / 8 ;
} else {
V_90 -> V_96 = 4 ;
V_90 -> V_97 = V_90 -> V_112 / 2 ;
V_90 -> V_98 = 0 ;
V_90 -> V_99 = 0 ;
V_90 -> V_100 = 0 ;
V_90 -> V_101 = 0 ;
V_90 -> V_102 = 0 ;
V_90 -> V_103 = 0 ;
V_90 -> V_104 = 0 ;
V_90 -> V_105 = 0 ;
}
}
static T_1
F_21 ( struct V_113 * V_114 ,
struct V_115 * * V_7 ,
unsigned long * V_26 , T_7 * V_116 )
{
struct V_117 * V_118 ;
T_1 V_8 ;
unsigned long V_119 ;
V_119 = V_114 -> V_118 ;
V_118 = (struct V_117 * ) V_119 ;
V_8 = V_12 -> V_13 ( V_114 -> V_120 , V_114 ,
V_118 -> V_118 , V_26 , V_7 ) ;
if ( V_8 != V_16 )
return V_8 ;
* V_116 = V_118 -> V_121 ;
return V_8 ;
}
static T_1
F_22 ( struct V_89 * V_90 , T_6 * V_122 ,
unsigned long V_26 , void * * V_123 )
{
struct V_113 * V_114 , * V_124 ;
unsigned long V_125 ;
T_18 V_126 , V_127 ;
T_7 V_91 ;
T_7 V_116 ;
struct V_92 V_93 ;
int V_94 ;
T_1 V_8 ;
T_7 * V_82 = ( T_7 * ) ( unsigned long ) V_123 ;
int V_84 ;
V_124 = NULL ;
V_114 = NULL ;
V_125 = V_26 / sizeof( T_7 ) ;
for ( V_84 = 0 ; V_84 < V_125 ; V_84 ++ ) {
struct V_115 * V_7 = NULL ;
T_6 V_128 = V_129 ;
bool V_130 = false ;
void * V_131 = NULL ;
T_7 V_5 = V_82 [ V_84 ] ;
V_8 = F_4 ( V_37 , V_5 ,
V_122 , ( void * * ) & V_114 ) ;
if ( V_8 != V_16 )
continue;
V_8 = F_4 ( V_37 , V_5 ,
& V_128 , & V_131 ) ;
if ( V_8 == V_16 )
V_130 = true ;
V_8 = F_21 ( V_114 , & V_7 , & V_26 , & V_116 ) ;
if ( V_8 == V_16 && ( ! V_124 || V_130 ) ) {
V_126 = V_7 -> V_132 ;
V_127 = V_7 -> V_133 ;
V_94 = V_7 -> V_94 ;
V_93 = V_7 -> V_134 ;
V_91 = V_7 -> V_91 ;
V_124 = V_114 ;
if ( V_130 )
break;
}
}
if ( ! V_124 )
goto V_44;
V_90 -> V_135 = V_136 ;
V_90 -> V_112 = V_126 ;
V_90 -> V_137 = V_127 ;
V_90 -> V_138 = V_116 ;
V_90 -> V_139 = 1 ;
F_20 ( V_90 , V_91 , V_93 , V_94 ) ;
V_90 -> V_140 = V_90 -> V_97 * V_90 -> V_137 ;
V_90 -> V_141 |= V_142 ;
V_44:
return V_8 ;
}
static T_1
F_23 ( struct V_143 * V_144 ,
struct V_115 * * V_7 ,
unsigned long * V_26 , T_7 * V_116 )
{
struct V_145 * V_118 ;
T_1 V_8 ;
unsigned long V_119 ;
V_119 = V_144 -> V_118 ;
V_118 = (struct V_145 * ) V_119 ;
V_8 = V_12 -> V_13 ( V_144 -> V_120 , V_144 ,
V_118 -> V_118 , V_26 , V_7 ) ;
if ( V_8 != V_16 )
return V_8 ;
* V_116 = V_118 -> V_121 ;
return V_8 ;
}
static T_1
F_24 ( struct V_89 * V_90 , T_6 * V_122 ,
unsigned long V_26 , void * * V_123 )
{
struct V_143 * V_144 , * V_124 ;
unsigned long V_125 ;
T_18 V_126 , V_127 ;
T_7 V_91 ;
T_7 V_116 ;
struct V_92 V_93 ;
int V_94 ;
T_1 V_8 ;
T_3 * V_82 = ( T_3 * ) ( unsigned long ) V_123 ;
int V_84 ;
V_124 = NULL ;
V_144 = NULL ;
V_125 = V_26 / sizeof( T_3 ) ;
for ( V_84 = 0 ; V_84 < V_125 ; V_84 ++ ) {
struct V_115 * V_7 = NULL ;
T_6 V_128 = V_129 ;
bool V_130 = false ;
void * V_131 = NULL ;
T_3 V_5 = V_82 [ V_84 ] ;
V_8 = F_4 ( V_37 , V_5 ,
V_122 , ( void * * ) & V_144 ) ;
if ( V_8 != V_16 )
continue;
V_8 = F_4 ( V_37 , V_5 ,
& V_128 , & V_131 ) ;
if ( V_8 == V_16 )
V_130 = true ;
V_8 = F_23 ( V_144 , & V_7 , & V_26 , & V_116 ) ;
if ( V_8 == V_16 && ( ! V_124 || V_130 ) ) {
V_126 = V_7 -> V_132 ;
V_127 = V_7 -> V_133 ;
V_94 = V_7 -> V_94 ;
V_93 = V_7 -> V_134 ;
V_91 = V_7 -> V_91 ;
V_124 = V_144 ;
if ( V_130 )
break;
}
}
if ( ! V_124 )
goto V_44;
V_90 -> V_135 = V_136 ;
V_90 -> V_112 = V_126 ;
V_90 -> V_137 = V_127 ;
V_90 -> V_138 = V_116 ;
V_90 -> V_139 = 1 ;
F_20 ( V_90 , V_91 , V_93 , V_94 ) ;
V_90 -> V_140 = V_90 -> V_97 * V_90 -> V_137 ;
V_90 -> V_141 |= V_142 ;
V_44:
return V_8 ;
}
static T_1 F_25 ( struct V_89 * V_90 , T_6 * V_122 ,
unsigned long V_26 )
{
T_1 V_8 ;
void * * V_123 = NULL ;
V_8 = F_4 ( V_21 , V_22 ,
V_26 , ( void * * ) & V_123 ) ;
if ( V_8 != V_16 )
return V_8 ;
V_8 = F_4 ( V_86 ,
V_87 ,
V_122 , NULL , & V_26 , V_123 ) ;
if ( V_8 != V_16 )
goto V_88;
if ( V_12 -> V_25 )
V_8 = F_24 ( V_90 , V_122 , V_26 , V_123 ) ;
else
V_8 = F_22 ( V_90 , V_122 , V_26 , V_123 ) ;
V_88:
F_4 ( V_23 , V_123 ) ;
return V_8 ;
}
static T_1
F_26 ( void * * V_146 , unsigned long V_26 , T_7 * V_126 , T_7 * V_127 )
{
struct V_147 * V_148 = NULL , * V_149 ;
T_6 V_150 = V_151 ;
unsigned long V_152 ;
T_7 * V_82 = ( T_7 * ) V_146 ; ;
T_1 V_8 ;
int V_84 ;
V_149 = NULL ;
V_152 = V_26 / sizeof( T_7 ) ;
for ( V_84 = 0 ; V_84 < V_152 ; V_84 ++ ) {
T_6 V_153 = V_81 ;
T_7 V_154 , V_5 , V_155 , V_156 ;
void * V_157 ;
T_7 V_3 = V_82 [ V_84 ] ;
V_8 = F_4 ( V_37 , V_3 ,
& V_150 , ( void * * ) & V_148 ) ;
if ( V_8 != V_16 )
continue;
F_4 ( V_37 , V_3 , & V_153 , & V_157 ) ;
V_8 = V_12 -> V_13 ( ( unsigned long ) V_148 -> V_158 , V_148 ,
& V_154 , & V_5 , & V_155 , & V_156 ) ;
if ( V_8 == V_16 && ( ! V_149 || V_157 ) ) {
* V_126 = V_154 ;
* V_127 = V_5 ;
if ( V_157 )
break;
V_149 = V_148 ;
}
}
return V_8 ;
}
static T_1
F_27 ( void * * V_146 , unsigned long V_26 , T_7 * V_126 , T_7 * V_127 )
{
struct V_147 * V_148 = NULL , * V_149 ;
T_6 V_150 = V_151 ;
unsigned long V_152 ;
T_3 * V_82 = ( T_3 * ) V_146 ; ;
T_1 V_8 ;
int V_84 ;
V_149 = NULL ;
V_152 = V_26 / sizeof( T_3 ) ;
for ( V_84 = 0 ; V_84 < V_152 ; V_84 ++ ) {
T_6 V_153 = V_81 ;
T_7 V_154 , V_5 , V_155 , V_156 ;
void * V_157 ;
T_3 V_3 = V_82 [ V_84 ] ;
V_8 = F_4 ( V_37 , V_3 ,
& V_150 , ( void * * ) & V_148 ) ;
if ( V_8 != V_16 )
continue;
F_4 ( V_37 , V_3 , & V_153 , & V_157 ) ;
V_8 = V_12 -> V_13 ( ( unsigned long ) V_148 -> V_158 , V_148 ,
& V_154 , & V_5 , & V_155 , & V_156 ) ;
if ( V_8 == V_16 && ( ! V_149 || V_157 ) ) {
* V_126 = V_154 ;
* V_127 = V_5 ;
if ( V_157 )
break;
V_149 = V_148 ;
}
}
return V_8 ;
}
static T_1 F_28 ( struct V_89 * V_90 , T_6 * V_150 ,
unsigned long V_26 )
{
T_1 V_8 ;
T_7 V_126 , V_127 ;
void * * V_146 = NULL ;
V_8 = F_4 ( V_21 , V_22 ,
V_26 , ( void * * ) & V_146 ) ;
if ( V_8 != V_16 )
return V_8 ;
V_8 = F_4 ( V_86 ,
V_87 ,
V_150 , NULL , & V_26 , V_146 ) ;
if ( V_8 != V_16 )
goto V_88;
V_127 = 0 ;
V_126 = 0 ;
if ( V_12 -> V_25 )
V_8 = F_27 ( V_146 , V_26 , & V_126 , & V_127 ) ;
else
V_8 = F_26 ( V_146 , V_26 , & V_126 , & V_127 ) ;
if ( ! V_126 && ! V_127 )
goto V_88;
V_90 -> V_135 = V_136 ;
V_90 -> V_96 = 32 ;
V_90 -> V_112 = V_126 ;
V_90 -> V_137 = V_127 ;
V_90 -> V_98 = 8 ;
V_90 -> V_99 = 16 ;
V_90 -> V_100 = 8 ;
V_90 -> V_101 = 8 ;
V_90 -> V_102 = 8 ;
V_90 -> V_103 = 0 ;
V_90 -> V_104 = 8 ;
V_90 -> V_105 = 24 ;
V_88:
F_4 ( V_23 , V_146 ) ;
return V_8 ;
}
void F_29 ( struct V_77 * V_77 )
{
T_6 V_159 = V_160 ;
struct V_89 * V_90 ;
T_6 V_150 = V_151 ;
T_1 V_8 ;
unsigned long V_26 ;
void * * V_123 = NULL ;
void * * V_146 = NULL ;
V_90 = & V_77 -> V_89 ;
memset ( V_90 , 0 , sizeof( * V_90 ) ) ;
V_26 = 0 ;
V_8 = F_4 ( V_86 ,
V_87 ,
& V_159 , NULL , & V_26 , V_123 ) ;
if ( V_8 == V_19 )
V_8 = F_25 ( V_90 , & V_159 , V_26 ) ;
if ( V_8 != V_16 ) {
V_26 = 0 ;
V_8 = F_4 ( V_86 ,
V_87 ,
& V_150 , NULL , & V_26 , V_146 ) ;
if ( V_8 == V_19 )
F_28 ( V_90 , & V_150 , V_26 ) ;
}
}
struct V_77 * F_30 ( struct V_161 * V_162 )
{
struct V_77 * V_77 ;
struct V_163 * V_164 ;
struct V_165 * V_166 ;
struct V_167 * V_85 ;
struct V_168 * V_169 ;
T_19 * V_33 ;
void * V_170 , * V_3 ;
T_6 V_122 = V_171 ;
int V_172 = 0 ;
T_1 V_8 ;
char * V_173 ;
T_18 * V_174 ;
T_14 * V_175 ;
int V_84 ;
unsigned long V_176 ;
unsigned long V_177 ;
V_12 = V_162 ;
V_17 = ( T_9 * ) ( unsigned long ) V_12 -> V_39 ;
V_3 = ( void * ) ( unsigned long ) V_12 -> V_178 ;
if ( V_17 -> V_85 . V_179 != V_180 )
return NULL ;
if ( V_12 -> V_25 )
F_31 ( V_12 ) ;
else
F_32 ( V_12 ) ;
V_8 = F_4 ( V_37 , V_3 ,
& V_122 , ( void * ) & V_33 ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_8 ) ;
return NULL ;
}
V_8 = F_33 ( V_17 , 0x4000 , 1 ,
( unsigned long * ) & V_77 ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_9 ) ;
return NULL ;
}
memset ( V_77 , 0x0 , 0x4000 ) ;
V_85 = & V_77 -> V_85 ;
V_169 = & V_77 -> V_168 ;
V_166 = & V_77 -> V_165 ;
V_164 = & V_77 -> V_163 ;
memcpy ( & V_85 -> V_181 , V_33 -> V_182 + 512 , 512 ) ;
V_85 -> V_183 = 1 ;
V_85 -> V_184 = 0xffff ;
V_85 -> V_185 = 0xAA55 ;
V_85 -> V_186 = 0x21 ;
V_173 = F_34 ( V_17 , V_33 , & V_172 ) ;
if ( ! V_173 )
goto V_187;
V_85 -> V_188 = ( unsigned long ) V_173 ;
V_85 -> V_189 = 0 ;
V_85 -> V_177 = 0 ;
memset ( V_166 , 0 , sizeof( * V_166 ) ) ;
memset ( V_164 , 0 , sizeof( * V_164 ) ) ;
V_8 = F_35 ( V_17 , V_33 ,
( char * ) ( unsigned long ) V_85 -> V_188 ,
L_10 , V_85 -> V_190 ,
& V_176 , & V_177 ) ;
if ( V_8 != V_16 &&
V_85 -> V_191 & V_192 ) {
F_2 ( V_17 , L_11 ) ;
V_8 = F_35 ( V_17 , V_33 ,
( char * ) ( unsigned long ) V_85 -> V_188 ,
L_10 , - 1UL ,
& V_176 , & V_177 ) ;
}
if ( V_8 != V_16 )
goto V_193;
V_85 -> V_189 = V_176 & 0xffffffff ;
V_85 -> V_177 = V_177 & 0xffffffff ;
V_77 -> V_194 = ( T_3 ) V_176 >> 32 ;
V_77 -> V_195 = ( T_3 ) V_177 >> 32 ;
return V_77 ;
V_193:
F_36 ( V_17 , V_172 , V_85 -> V_188 ) ;
V_187:
F_36 ( V_17 , 0x4000 , ( unsigned long ) V_77 ) ;
return NULL ;
}
static void F_37 ( struct V_77 * V_78 ,
struct V_62 * V_196 , T_7 V_197 )
{
struct V_62 * V_60 ;
T_1 V_8 ;
unsigned long V_26 ;
V_196 -> type = V_198 ;
V_196 -> V_50 = V_197 * sizeof( struct V_199 ) ;
V_196 -> V_63 = 0 ;
V_60 = (struct V_62 * ) ( unsigned long ) V_78 -> V_85 . V_62 ;
while ( V_60 && V_60 -> V_63 )
V_60 = (struct V_62 * ) ( unsigned long ) V_60 -> V_63 ;
if ( V_60 )
V_60 -> V_63 = ( unsigned long ) V_196 ;
else
V_78 -> V_85 . V_62 = ( unsigned long ) V_196 ;
}
static T_1 F_38 ( struct V_77 * V_78 ,
struct V_62 * V_196 , T_7 V_200 )
{
struct V_199 * V_201 = & V_78 -> V_201 [ 0 ] ;
struct V_168 * V_169 = & V_78 -> V_168 ;
struct V_199 * V_202 = NULL ;
T_7 V_197 ;
T_7 V_203 ;
int V_84 ;
V_197 = 0 ;
V_203 = V_169 -> V_204 / V_169 -> V_205 ;
for ( V_84 = 0 ; V_84 < V_203 ; V_84 ++ ) {
T_20 * V_206 ;
unsigned int V_207 = 0 ;
unsigned long V_119 = V_169 -> V_208 ;
V_206 = ( T_20 * ) ( V_119 + ( V_84 * V_169 -> V_205 ) ) ;
switch ( V_206 -> type ) {
case V_209 :
case V_210 :
case V_211 :
case V_212 :
case V_213 :
case V_214 :
V_207 = V_215 ;
break;
case V_216 :
V_207 = V_217 ;
break;
case V_218 :
V_207 = V_219 ;
break;
case V_220 :
case V_22 :
case V_221 :
case V_222 :
case V_223 :
V_207 = V_224 ;
break;
case V_225 :
V_207 = V_226 ;
break;
default:
continue;
}
if ( V_202 && V_202 -> type == V_207 &&
( V_202 -> V_27 + V_202 -> V_26 ) == V_206 -> V_227 ) {
V_202 -> V_26 += V_206 -> V_228 << 12 ;
continue;
}
if ( V_197 == F_39 ( V_78 -> V_201 ) ) {
T_7 V_229 = ( V_203 - V_84 ) * sizeof( struct V_199 ) +
sizeof( struct V_62 ) ;
if ( ! V_196 || V_200 < V_229 )
return V_19 ;
V_201 = (struct V_199 * ) V_196 -> V_60 ;
}
V_201 -> V_27 = V_206 -> V_227 ;
V_201 -> V_26 = V_206 -> V_228 << V_230 ;
V_201 -> type = V_207 ;
V_202 = V_201 ++ ;
V_197 ++ ;
}
if ( V_197 > F_39 ( V_78 -> V_201 ) ) {
T_7 V_231 = V_197 - F_39 ( V_78 -> V_201 ) ;
F_37 ( V_78 , V_196 , V_231 ) ;
V_197 -= V_231 ;
}
V_78 -> V_232 = ( T_14 ) V_197 ;
return V_16 ;
}
static T_1 F_40 ( T_7 V_203 , struct V_62 * * V_196 ,
T_7 * V_200 )
{
T_1 V_8 ;
unsigned long V_26 ;
V_26 = sizeof( struct V_62 ) +
sizeof( struct V_199 ) * V_203 ;
if ( * V_196 ) {
F_4 ( V_23 , * V_196 ) ;
* V_196 = NULL ;
* V_200 = 0 ;
}
V_8 = F_4 ( V_21 , V_22 ,
V_26 , ( void * * ) V_196 ) ;
if ( V_8 == V_16 )
* V_200 = V_26 ;
return V_8 ;
}
static T_1 F_41 ( struct V_77 * V_77 ,
void * V_3 , bool V_25 )
{
struct V_168 * V_169 = & V_77 -> V_168 ;
unsigned long V_233 , V_234 , V_235 ;
T_20 * V_236 ;
struct V_62 * V_196 ;
const char * V_179 ;
T_21 V_200 ;
T_21 V_203 , V_237 ;
T_1 V_8 ;
T_21 V_238 ;
bool V_239 = false ;
T_14 V_197 ;
int V_84 ;
V_203 = 0 ;
V_196 = NULL ;
V_200 = 0 ;
V_240:
V_8 = F_42 ( V_17 , & V_236 , & V_233 , & V_235 ,
& V_238 , & V_234 ) ;
if ( V_8 != V_16 )
return V_8 ;
V_237 = V_203 ;
V_203 = V_233 / V_235 ;
if ( V_203 > V_237 &&
V_203 > F_39 ( V_77 -> V_201 ) ) {
T_7 V_231 = V_203 - F_39 ( V_77 -> V_201 ) ;
V_8 = F_40 ( V_231 , & V_196 , & V_200 ) ;
if ( V_8 != V_16 )
goto V_241;
F_4 ( V_23 , V_236 ) ;
goto V_240;
}
V_179 = V_25 ? V_242 : V_243 ;
memcpy ( & V_169 -> V_244 , V_179 , sizeof( T_21 ) ) ;
V_169 -> V_245 = ( unsigned long ) V_17 ;
V_169 -> V_205 = V_235 ;
V_169 -> V_246 = V_238 ;
V_169 -> V_208 = ( unsigned long ) V_236 ;
V_169 -> V_204 = V_233 ;
#ifdef F_43
V_169 -> V_247 = ( unsigned long ) V_17 >> 32 ;
V_169 -> V_248 = ( unsigned long ) V_236 >> 32 ;
#endif
V_8 = F_4 ( V_249 , V_3 , V_234 ) ;
if ( V_8 != V_16 ) {
if ( V_239 )
goto V_241;
V_239 = true ;
F_4 ( V_23 , V_236 ) ;
goto V_240;
}
V_77 -> V_250 = 32 * 1024 ;
V_8 = F_38 ( V_77 , V_196 , V_200 ) ;
if ( V_8 != V_16 )
return V_8 ;
return V_16 ;
V_241:
F_4 ( V_23 , V_236 ) ;
return V_8 ;
}
struct V_77 * F_44 ( struct V_161 * V_162 ,
struct V_77 * V_77 )
{
struct V_251 * V_252 = NULL ;
T_19 * V_33 ;
struct V_167 * V_85 = & V_77 -> V_85 ;
T_1 V_8 ;
struct V_253 * V_254 ;
void * V_3 ;
T_9 * V_255 ;
bool V_25 ;
V_12 = V_162 ;
V_255 = ( T_9 * ) ( unsigned long ) V_12 -> V_39 ;
V_3 = ( void * ) ( unsigned long ) V_12 -> V_178 ;
V_25 = V_12 -> V_25 ;
V_17 = V_255 ;
if ( V_17 -> V_85 . V_179 != V_180 )
goto V_187;
if ( V_25 )
F_31 ( V_12 ) ;
else
F_32 ( V_12 ) ;
F_29 ( V_77 ) ;
F_19 ( V_77 ) ;
V_8 = F_4 ( V_21 , V_22 ,
sizeof( * V_252 ) , ( void * * ) & V_252 ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_12 ) ;
goto V_187;
}
V_252 -> V_26 = 0x800 ;
V_8 = F_33 ( V_17 , V_252 -> V_26 , 8 ,
( unsigned long * ) & V_252 -> V_256 ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_13 ) ;
goto V_187;
}
if ( V_85 -> V_257 != V_85 -> V_258 ) {
unsigned long V_259 = V_85 -> V_258 ;
V_8 = F_45 ( V_17 , & V_259 ,
V_85 -> V_260 , V_85 -> V_260 ,
V_85 -> V_257 ,
V_85 -> V_261 ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_14 ) ;
goto V_187;
}
V_85 -> V_257 = V_85 -> V_258 ;
V_85 -> V_258 = V_259 ;
}
V_8 = F_41 ( V_77 , V_3 , V_25 ) ;
if ( V_8 != V_16 ) {
F_2 ( V_17 , L_15 ) ;
goto V_187;
}
memset ( ( char * ) V_252 -> V_256 , 0x0 , V_252 -> V_26 ) ;
V_254 = (struct V_253 * ) V_252 -> V_256 ;
V_254 += 2 ;
V_254 -> V_262 = 0xffff ;
V_254 -> V_263 = 0x0000 ;
V_254 -> V_264 = 0x0000 ;
V_254 -> type = V_265 | V_266 ;
V_254 -> V_267 = V_268 ;
V_254 -> V_269 = 0 ;
V_254 -> V_270 = 1 ;
V_254 -> V_271 = 0xf ;
V_254 -> V_272 = 0 ;
V_254 -> V_273 = 0 ;
V_254 -> V_206 = V_274 ;
V_254 -> V_275 = V_276 ;
V_254 -> V_277 = 0x00 ;
V_254 ++ ;
V_254 -> V_262 = 0xffff ;
V_254 -> V_263 = 0x0000 ;
V_254 -> V_264 = 0x0000 ;
V_254 -> type = V_278 | V_279 ;
V_254 -> V_267 = V_268 ;
V_254 -> V_269 = 0 ;
V_254 -> V_270 = 1 ;
V_254 -> V_271 = 0xf ;
V_254 -> V_272 = 0 ;
V_254 -> V_273 = 0 ;
V_254 -> V_206 = V_274 ;
V_254 -> V_275 = V_276 ;
V_254 -> V_277 = 0x00 ;
#ifdef F_43
V_254 ++ ;
V_254 -> V_262 = 0x0000 ;
V_254 -> V_263 = 0x0000 ;
V_254 -> V_264 = 0x0000 ;
V_254 -> type = V_280 ;
V_254 -> V_267 = 0 ;
V_254 -> V_269 = 0 ;
V_254 -> V_270 = 1 ;
V_254 -> V_271 = 0x0 ;
V_254 -> V_272 = 0 ;
V_254 -> V_273 = 0 ;
V_254 -> V_206 = 0 ;
V_254 -> V_275 = V_276 ;
V_254 -> V_277 = 0x00 ;
#endif
asm volatile("cli");
asm volatile ("lgdt %0" : : "m" (*gdt));
return V_77 ;
V_187:
F_2 ( V_17 , L_16 ) ;
return NULL ;
}
