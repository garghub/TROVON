static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
++ V_4 -> V_7 . V_8 ;
F_2 ( & V_4 -> V_9 ) ;
}
static void F_3 ( struct V_3 * V_4 , struct V_10 * V_10 )
{
if ( ! V_10 )
return;
F_4 ( V_4 -> V_11 , ( unsigned long ) V_10 -> V_12 ,
V_10 -> V_13 ) ;
F_5 ( V_10 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
unsigned long V_14 ;
F_7 ( V_2 != V_4 -> V_2 ) ;
for (; ; ) {
unsigned int V_15 ;
struct V_10 * V_10 ;
F_8 ( & V_4 -> V_16 , V_14 ) ;
V_10 = F_9 ( V_2 , & V_15 ) ;
F_10 ( & V_4 -> V_16 , V_14 ) ;
if ( ! V_10 )
break;
F_3 ( V_4 , V_10 ) ;
if ( V_4 -> V_2 -> V_17 <= V_4 -> V_18 )
continue;
if ( V_4 -> V_19 == 0 && V_4 -> V_11 )
V_4 -> V_19 =
F_11 ( V_4 -> V_11 ,
V_4 -> V_20 ) ;
if ( V_4 -> V_19 ) {
V_4 -> V_18 =
F_12 ( V_4 -> V_2 ) ;
F_13 ( V_4 -> V_21 ) ;
F_14 ( V_4 -> V_2 ) ;
++ V_4 -> V_7 . V_22 ;
} else {
F_15 ( V_4 -> V_18 >
F_12 ( V_4 -> V_2 ) ) ;
V_4 -> V_18 +=
F_12 ( V_4 -> V_2 ) / 4 ;
}
}
}
static struct V_23 * F_16 ( int * V_24 ,
struct V_3 * V_4 ,
T_1 * V_25 , T_2 V_26 )
{
struct V_23 * V_27 ;
T_2 V_28 , V_29 ;
* V_24 = 0 ;
if ( V_26 > V_4 -> V_30 || V_26 <= V_4 -> V_31 + V_4 -> V_32 ) {
F_17 ( V_4 -> V_21 ,
L_1 ,
V_26 , V_4 -> V_30 , V_4 -> V_31 ,
V_4 -> V_32 ) ;
* V_24 = - V_33 ;
return NULL ;
}
V_28 = V_26 - ( V_4 -> V_31 + V_4 -> V_32 ) ;
V_29 = ( unsigned long ) ( V_25 + V_4 -> V_31 ) & ( V_34 - 1 ) ;
V_27 = F_18 ( V_4 -> V_21 , V_26 + V_29 ) ;
if ( ! V_27 ) {
* V_24 = - V_35 ;
return NULL ;
}
F_19 ( V_27 , V_4 -> V_31 + V_29 ) ;
memcpy ( F_20 ( V_27 , V_28 ) , V_25 + V_4 -> V_31 , V_28 ) ;
return V_27 ;
}
static int F_21 ( struct V_36 * V_37 , int V_38 )
{
struct V_3 * V_4 = F_22 ( V_37 , struct V_3 , V_37 ) ;
int V_39 = 0 ;
int V_24 = 0 ;
void * V_40 ;
struct V_23 * V_27 ;
struct V_41 * V_42 = & V_4 -> V_43 . V_42 ;
unsigned int V_44 ;
V_45:
do {
V_27 = NULL ;
if ( V_42 -> V_46 == V_42 -> V_47 ) {
if ( V_4 -> V_43 . V_48 != V_49 ) {
F_23 ( V_4 -> V_50 ,
V_4 -> V_43 . V_48 ,
0 ) ;
V_4 -> V_43 . V_48 = V_49 ;
}
V_24 = F_24 (
V_4 -> V_50 ,
V_42 ,
NULL ,
& V_4 -> V_43 . V_48 ,
V_51 ) ;
if ( V_24 <= 0 )
goto exit;
}
V_40 = F_25 ( ( unsigned long ) V_42 -> V_52 [ V_42 -> V_46 ] . V_53 ) ;
V_27 = F_16 ( & V_24 , V_4 , V_40 ,
V_42 -> V_52 [ V_42 -> V_46 ] . V_54 ) ;
if ( F_26 ( V_24 ) )
goto exit;
V_44 = V_27 -> V_15 ;
V_27 -> V_55 = F_27 ( V_56 ) ;
F_28 ( V_27 ) ;
V_27 -> V_57 = V_4 -> V_21 ;
V_24 = F_29 ( V_27 ) ;
if ( F_26 ( V_24 ) ) {
++ V_4 -> V_21 -> V_7 . V_58 ;
} else {
++ V_4 -> V_21 -> V_7 . V_59 ;
V_4 -> V_21 -> V_7 . V_60 += V_44 ;
}
++ V_42 -> V_46 ;
++ V_39 ;
} while ( V_39 < V_38 );
++ V_4 -> V_7 . V_61 ;
goto V_62;
exit:
switch ( V_24 ) {
case 0 :
++ V_4 -> V_7 . V_63 ;
F_30 ( V_37 ) ;
if ( F_26 ( ! F_31 ( V_4 -> V_50 ) ) &&
F_32 ( V_37 ) ) {
F_33 ( V_4 -> V_50 ) ;
F_34 ( V_37 ) ;
goto V_45;
}
break;
case - V_35 :
++ V_4 -> V_7 . V_64 ;
F_35 ( V_27 ) ;
F_30 ( V_37 ) ;
F_31 ( V_4 -> V_50 ) ;
break;
default:
F_36 ( V_4 -> V_21 , L_2 ) ;
V_4 -> V_21 -> V_7 . V_58 = V_42 -> V_47 - V_42 -> V_46 ;
F_30 ( V_37 ) ;
F_33 ( V_4 -> V_50 ) ;
F_37 ( V_4 -> V_21 ) ;
break;
}
V_62:
if ( V_39 && F_38 ( V_4 -> V_50 ) > 0 )
F_39 ( V_4 -> V_50 ) ;
return V_39 ;
}
static void F_40 ( struct V_65 * V_5 , struct V_66 * V_50 )
{
struct V_3 * V_4 = V_5 -> V_6 ;
++ V_4 -> V_7 . V_67 ;
F_33 ( V_4 -> V_50 ) ;
F_41 ( & V_4 -> V_37 ) ;
}
static void F_42 ( struct V_3 * V_4 )
{
if ( V_4 -> V_68 )
F_43 ( V_4 -> V_5 -> V_57 . V_69 -> V_69 ,
V_4 -> V_70 , V_4 -> V_68 ,
V_4 -> V_71 ) ;
if ( ! V_4 -> V_11 )
return;
F_4 ( V_4 -> V_11 , V_4 -> V_19 ,
V_4 -> V_20 ) ;
F_44 ( V_4 -> V_11 ) ;
V_4 -> V_11 = NULL ;
}
static int F_45 ( struct V_3 * V_4 )
{
int V_24 ;
V_24 = - V_35 ;
V_4 -> V_70 = ( F_12 ( V_4 -> V_2 ) *
( V_72 + V_4 -> V_73 + V_4 -> V_74 ) * 11 ) / 10 ;
if ( V_4 -> V_70 <= ( F_46 () + 1 ) * V_4 -> V_21 -> V_75 )
return - V_76 ;
for (; ; ) {
if ( V_4 -> V_70 <= F_46 () * V_4 -> V_21 -> V_75 ) {
F_47 ( V_4 -> V_21 , L_3 ) ;
return - V_35 ;
}
V_4 -> V_68 = F_48 (
V_4 -> V_5 -> V_57 . V_69 -> V_69 ,
V_4 -> V_70 , & V_4 -> V_71 ,
V_51 ) ;
if ( V_4 -> V_68 )
break;
V_4 -> V_70 = ( V_4 -> V_70 * 3 ) >> 2 ;
}
F_49 ( V_4 -> V_21 , L_4 ,
V_4 -> V_70 ) ;
V_4 -> V_11 = F_50 ( 7 , - 1 ) ;
if ( ! V_4 -> V_11 )
goto V_24;
V_24 = F_51 ( V_4 -> V_11 , ( unsigned long ) V_4 -> V_68 ,
( V_77 ) F_52 ( V_4 -> V_68 ) ,
V_4 -> V_70 , - 1 ) ;
if ( V_24 )
goto V_24;
V_4 -> V_20 = F_46 () * V_4 -> V_21 -> V_75 ;
V_4 -> V_19 = F_11 ( V_4 -> V_11 ,
V_4 -> V_20 ) ;
if ( ! V_4 -> V_19 ) {
V_24 = - V_35 ;
goto V_24;
}
V_4 -> V_18 = F_12 ( V_4 -> V_2 ) ;
return 0 ;
V_24:
F_42 ( V_4 ) ;
return V_24 ;
}
static int F_53 ( struct V_78 * V_79 )
{
struct V_3 * V_4 = F_54 ( V_79 ) ;
if ( F_45 ( V_4 ) )
return - V_35 ;
F_55 ( V_79 ) ;
F_56 ( & V_4 -> V_37 ) ;
F_41 ( & V_4 -> V_37 ) ;
return 0 ;
}
static int F_57 ( struct V_78 * V_79 )
{
struct V_3 * V_4 = F_54 ( V_79 ) ;
unsigned long V_14 ;
struct V_10 * V_10 ;
F_37 ( V_79 ) ;
F_14 ( V_4 -> V_2 ) ;
F_33 ( V_4 -> V_50 ) ;
F_58 ( & V_4 -> V_37 ) ;
F_6 ( V_4 -> V_2 ) ;
F_8 ( & V_4 -> V_16 , V_14 ) ;
while ( ( V_10 = F_59 ( V_4 -> V_2 ) ) )
F_3 ( V_4 , V_10 ) ;
F_10 ( & V_4 -> V_16 , V_14 ) ;
F_42 ( V_4 ) ;
return 0 ;
}
static struct V_10 * F_60 ( struct V_3 * V_4 ,
struct V_23 * V_27 ,
struct V_80 * V_81 )
{
struct V_82 * V_83 = ( void * ) & V_27 -> V_84 ;
struct V_10 * V_10 = NULL ;
T_1 V_29 , V_85 ;
if ( ! V_4 -> V_11 )
goto V_24;
if ( F_26 ( V_4 -> V_73 + V_27 -> V_15 + V_4 -> V_74 > V_4 -> V_75 ) ) {
F_36 ( V_4 -> V_21 , L_5 ,
V_4 -> V_73 + V_27 -> V_15 + V_4 -> V_74 , V_4 -> V_75 ) ;
goto V_24;
}
V_10 = F_61 ( sizeof( struct V_10 ) , V_51 ) ;
if ( F_26 ( ! V_10 ) )
goto V_24;
V_85 = V_4 -> V_73 + V_83 -> V_86 ;
V_29 = V_85 & ( V_34 - 1 ) ;
V_10 -> V_13 = V_4 -> V_73 + V_27 -> V_15 + V_4 -> V_74 + V_29 ;
V_10 -> V_12 = ( void * ) F_11 ( V_4 -> V_11 , V_10 -> V_13 ) ;
if ( F_26 ( ! V_10 -> V_12 ) )
goto V_24;
F_62 ( V_27 , 0 , V_10 -> V_12 + V_4 -> V_73 + V_29 , V_27 -> V_15 ) ;
F_63 ( V_81 , V_10 -> V_12 + V_29 ,
V_27 -> V_15 + V_4 -> V_73 + V_4 -> V_31 ) ;
return V_10 ;
V_24:
F_5 ( V_10 ) ;
return NULL ;
}
static int F_64 ( struct V_23 * V_27 , struct V_78 * V_79 )
{
struct V_3 * V_4 = F_54 ( V_79 ) ;
struct V_10 * V_10 ;
struct V_80 V_81 ;
unsigned long V_14 ;
bool V_87 = false ;
int V_88 ;
F_6 ( V_4 -> V_2 ) ;
F_8 ( & V_4 -> V_16 , V_14 ) ;
if ( F_26 ( V_4 -> V_2 -> V_17 <= F_65 () ) ) {
V_87 = true ;
V_4 -> V_7 . V_89 ++ ;
}
V_10 = F_60 ( V_4 , V_27 , & V_81 ) ;
if ( F_26 ( ! V_10 ) ) {
V_4 -> V_7 . V_90 ++ ;
V_87 = true ;
if ( V_4 -> V_19 && V_4 -> V_11 ) {
F_4 ( V_4 -> V_11 , V_4 -> V_19 ,
V_4 -> V_20 ) ;
V_4 -> V_19 = 0 ;
V_10 = F_60 ( V_4 , V_27 , & V_81 ) ;
}
}
if ( F_26 ( V_87 ) ) {
V_4 -> V_18 = F_12 ( V_4 -> V_2 ) / 4 ;
F_66 ( V_4 -> V_2 ) ;
F_67 ( V_79 ) ;
}
if ( F_26 ( ! V_10 ) ) {
F_36 ( V_4 -> V_21 , L_6 ) ;
goto V_24;
}
V_88 = F_68 ( V_4 -> V_2 , & V_81 , 1 , V_10 , V_51 ) ;
if ( F_26 ( ( V_88 < 0 ) ) ) {
F_36 ( V_4 -> V_21 , L_7 ,
V_88 ) ;
goto V_24;
}
V_4 -> V_21 -> V_7 . V_91 ++ ;
V_4 -> V_21 -> V_7 . V_92 += V_27 -> V_15 ;
F_10 ( & V_4 -> V_16 , V_14 ) ;
F_69 ( V_4 -> V_2 ) ;
F_35 ( V_27 ) ;
return V_93 ;
V_24:
F_10 ( & V_4 -> V_16 , V_14 ) ;
V_4 -> V_21 -> V_7 . V_94 ++ ;
F_3 ( V_4 , V_10 ) ;
F_35 ( V_27 ) ;
return V_93 ;
}
static void F_70 ( unsigned long V_95 )
{
struct V_3 * V_4 = (struct V_3 * ) V_95 ;
F_6 ( V_4 -> V_2 ) ;
}
static void F_71 ( struct V_78 * V_79 )
{
V_79 -> V_96 = & V_97 ;
V_79 -> type = V_98 ;
V_79 -> V_99 = 100 ;
V_79 -> V_14 = V_100 | V_101 ;
V_79 -> V_75 = V_102 ;
V_79 -> V_103 = V_104 ;
}
static inline void F_72 ( struct V_3 * V_4 )
{
V_4 -> V_105 =
F_73 ( F_74 ( V_4 -> V_21 ) , NULL ) ;
if ( F_75 ( V_4 -> V_105 ) )
return;
F_76 ( L_8 , V_106 , V_4 -> V_105 ,
& V_4 -> V_7 . V_63 ) ;
F_76 ( L_9 , V_106 , V_4 -> V_105 ,
& V_4 -> V_7 . V_61 ) ;
F_76 ( L_10 , V_106 , V_4 -> V_105 ,
& V_4 -> V_7 . V_64 ) ;
F_76 ( L_11 , V_106 , V_4 -> V_105 ,
& V_4 -> V_7 . V_67 ) ;
F_76 ( L_12 , V_106 , V_4 -> V_105 ,
& V_4 -> V_7 . V_89 ) ;
F_76 ( L_13 , V_106 , V_4 -> V_105 ,
& V_4 -> V_7 . V_90 ) ;
F_76 ( L_14 , V_106 , V_4 -> V_105 ,
& V_4 -> V_7 . V_8 ) ;
F_76 ( L_15 , V_106 , V_4 -> V_105 ,
& V_4 -> V_7 . V_22 ) ;
}
static int F_77 ( struct V_65 * V_5 )
{
T_3 * V_107 = F_1 ;
T_4 * V_108 = F_40 ;
const char * V_109 = L_16 ;
const char * V_110 = L_17 ;
struct V_78 * V_79 ;
struct V_3 * V_4 ;
int V_24 = - V_76 ;
V_79 = F_78 ( sizeof( struct V_3 ) , V_110 ,
V_111 , F_71 ) ;
if ( ! V_79 )
return - V_35 ;
V_4 = F_54 ( V_79 ) ;
V_4 -> V_5 = V_5 ;
V_4 -> V_21 = V_79 ;
F_79 ( & V_4 -> V_16 ) ;
V_24 = - V_112 ;
if ( ! V_5 -> V_113 || ! V_5 -> V_113 -> V_114 )
goto V_24;
V_24 = V_5 -> V_113 -> V_114 ( V_5 , 1 , & V_4 -> V_50 , & V_108 ) ;
if ( V_24 )
goto V_24;
V_24 = V_5 -> V_115 -> V_116 ( V_5 , 1 , & V_4 -> V_2 , & V_107 , & V_109 ) ;
if ( V_24 )
goto V_24;
if ( V_5 -> V_115 -> V_117 ) {
F_80 ( V_5 , struct V_118 , V_119 ,
& V_4 -> V_73 ) ;
F_80 ( V_5 , struct V_118 , V_119 ,
& V_4 -> V_31 ) ;
F_80 ( V_5 , struct V_118 , V_120 ,
& V_4 -> V_74 ) ;
F_80 ( V_5 , struct V_118 , V_120 ,
& V_4 -> V_32 ) ;
F_80 ( V_5 , struct V_118 , V_75 ,
& V_4 -> V_75 ) ;
F_80 ( V_5 , struct V_118 , V_75 ,
& V_4 -> V_30 ) ;
} else {
V_4 -> V_73 = V_121 ;
V_4 -> V_31 = V_121 ;
V_4 -> V_74 = V_122 ;
V_4 -> V_32 = V_122 ;
V_4 -> V_75 = V_102 ;
V_4 -> V_30 = V_102 ;
}
V_79 -> V_123 = V_4 -> V_73 ;
V_79 -> V_124 = V_4 -> V_74 ;
F_14 ( V_4 -> V_2 ) ;
V_79 -> V_75 = V_4 -> V_75 - V_4 -> V_74 ;
V_5 -> V_6 = V_4 ;
F_81 ( & V_4 -> V_43 . V_42 , NULL , 0 ) ;
V_4 -> V_43 . V_48 = V_49 ;
F_82 ( V_79 , & V_4 -> V_37 , F_21 , V_125 ) ;
F_83 ( & V_4 -> V_9 ,
F_70 ,
( unsigned long ) V_4 ) ;
F_37 ( V_79 ) ;
V_24 = F_84 ( V_79 ) ;
if ( V_24 ) {
F_85 ( & V_5 -> V_57 , L_18 , V_24 ) ;
goto V_24;
}
F_72 ( V_4 ) ;
return 0 ;
V_24:
F_36 ( V_4 -> V_21 , L_19 , V_24 ) ;
if ( V_4 -> V_50 )
V_5 -> V_113 -> V_126 ( V_4 -> V_5 ) ;
if ( V_4 -> V_5 )
V_5 -> V_115 -> V_127 ( V_4 -> V_5 ) ;
V_104 ( V_79 ) ;
return V_24 ;
}
static void F_86 ( struct V_65 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_6 ;
F_87 () ;
F_88 ( V_4 -> V_21 ) ;
F_89 () ;
F_90 ( & V_4 -> V_9 ) ;
F_91 ( V_4 -> V_105 ) ;
F_92 ( & V_4 -> V_43 . V_42 ) ;
V_5 -> V_115 -> V_128 ( V_5 ) ;
V_5 -> V_113 -> V_126 ( V_4 -> V_5 ) ;
V_4 -> V_50 = NULL ;
V_5 -> V_115 -> V_127 ( V_4 -> V_5 ) ;
F_93 ( V_4 -> V_21 ) ;
}
