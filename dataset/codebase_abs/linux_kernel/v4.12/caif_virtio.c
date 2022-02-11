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
do {
V_27 = NULL ;
if ( V_42 -> V_45 == V_42 -> V_46 ) {
if ( V_4 -> V_43 . V_47 != V_48 ) {
F_23 ( V_4 -> V_49 ,
V_4 -> V_43 . V_47 ,
0 ) ;
V_4 -> V_43 . V_47 = V_48 ;
}
V_24 = F_24 (
V_4 -> V_49 ,
V_42 ,
NULL ,
& V_4 -> V_43 . V_47 ,
V_50 ) ;
if ( V_24 <= 0 )
goto exit;
}
V_40 = F_25 ( ( unsigned long ) V_42 -> V_51 [ V_42 -> V_45 ] . V_52 ) ;
V_27 = F_16 ( & V_24 , V_4 , V_40 ,
V_42 -> V_51 [ V_42 -> V_45 ] . V_53 ) ;
if ( F_26 ( V_24 ) )
goto exit;
V_44 = V_27 -> V_15 ;
V_27 -> V_54 = F_27 ( V_55 ) ;
F_28 ( V_27 ) ;
V_27 -> V_56 = V_4 -> V_21 ;
V_24 = F_29 ( V_27 ) ;
if ( F_26 ( V_24 ) ) {
++ V_4 -> V_21 -> V_7 . V_57 ;
} else {
++ V_4 -> V_21 -> V_7 . V_58 ;
V_4 -> V_21 -> V_7 . V_59 += V_44 ;
}
++ V_42 -> V_45 ;
++ V_39 ;
} while ( V_39 < V_38 );
++ V_4 -> V_7 . V_60 ;
goto V_61;
exit:
switch ( V_24 ) {
case 0 :
++ V_4 -> V_7 . V_62 ;
F_30 ( V_37 ) ;
if ( F_26 ( ! F_31 ( V_4 -> V_49 ) ) &&
F_32 ( V_37 ) ) {
F_33 ( V_4 -> V_49 ) ;
F_34 ( V_37 ) ;
}
break;
case - V_35 :
++ V_4 -> V_7 . V_63 ;
F_35 ( V_27 ) ;
F_30 ( V_37 ) ;
F_31 ( V_4 -> V_49 ) ;
break;
default:
F_36 ( V_4 -> V_21 , L_2 ) ;
V_4 -> V_21 -> V_7 . V_57 = V_42 -> V_46 - V_42 -> V_45 ;
F_30 ( V_37 ) ;
F_33 ( V_4 -> V_49 ) ;
F_37 ( V_4 -> V_21 ) ;
break;
}
V_61:
if ( V_39 && F_38 ( V_4 -> V_49 ) > 0 )
F_39 ( V_4 -> V_49 ) ;
return V_39 ;
}
static void F_40 ( struct V_64 * V_5 , struct V_65 * V_49 )
{
struct V_3 * V_4 = V_5 -> V_6 ;
++ V_4 -> V_7 . V_66 ;
F_33 ( V_4 -> V_49 ) ;
F_41 ( & V_4 -> V_37 ) ;
}
static void F_42 ( struct V_3 * V_4 )
{
if ( V_4 -> V_67 )
F_43 ( V_4 -> V_5 -> V_56 . V_68 -> V_68 ,
V_4 -> V_69 , V_4 -> V_67 ,
V_4 -> V_70 ) ;
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
V_4 -> V_69 = ( F_12 ( V_4 -> V_2 ) *
( V_71 + V_4 -> V_72 + V_4 -> V_73 ) * 11 ) / 10 ;
if ( V_4 -> V_69 <= ( F_46 () + 1 ) * V_4 -> V_21 -> V_74 )
return - V_75 ;
for (; ; ) {
if ( V_4 -> V_69 <= F_46 () * V_4 -> V_21 -> V_74 ) {
F_47 ( V_4 -> V_21 , L_3 ) ;
return - V_35 ;
}
V_4 -> V_67 = F_48 (
V_4 -> V_5 -> V_56 . V_68 -> V_68 ,
V_4 -> V_69 , & V_4 -> V_70 ,
V_50 ) ;
if ( V_4 -> V_67 )
break;
V_4 -> V_69 = ( V_4 -> V_69 * 3 ) >> 2 ;
}
F_49 ( V_4 -> V_21 , L_4 ,
V_4 -> V_69 ) ;
V_4 -> V_11 = F_50 ( 7 , - 1 ) ;
if ( ! V_4 -> V_11 )
goto V_24;
V_24 = F_51 ( V_4 -> V_11 , ( unsigned long ) V_4 -> V_67 ,
( V_76 ) F_52 ( V_4 -> V_67 ) ,
V_4 -> V_69 , - 1 ) ;
if ( V_24 )
goto V_24;
V_4 -> V_20 = F_46 () * V_4 -> V_21 -> V_74 ;
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
static int F_53 ( struct V_77 * V_78 )
{
struct V_3 * V_4 = F_54 ( V_78 ) ;
if ( F_45 ( V_4 ) )
return - V_35 ;
F_55 ( V_78 ) ;
F_56 ( & V_4 -> V_37 ) ;
F_41 ( & V_4 -> V_37 ) ;
return 0 ;
}
static int F_57 ( struct V_77 * V_78 )
{
struct V_3 * V_4 = F_54 ( V_78 ) ;
unsigned long V_14 ;
struct V_10 * V_10 ;
F_37 ( V_78 ) ;
F_14 ( V_4 -> V_2 ) ;
F_33 ( V_4 -> V_49 ) ;
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
struct V_79 * V_80 )
{
struct V_81 * V_82 = ( void * ) & V_27 -> V_83 ;
struct V_10 * V_10 = NULL ;
T_1 V_29 , V_84 ;
if ( ! V_4 -> V_11 )
goto V_24;
if ( F_26 ( V_4 -> V_72 + V_27 -> V_15 + V_4 -> V_73 > V_4 -> V_74 ) ) {
F_36 ( V_4 -> V_21 , L_5 ,
V_4 -> V_72 + V_27 -> V_15 + V_4 -> V_73 , V_4 -> V_74 ) ;
goto V_24;
}
V_10 = F_61 ( sizeof( struct V_10 ) , V_50 ) ;
if ( F_26 ( ! V_10 ) )
goto V_24;
V_84 = V_4 -> V_72 + V_82 -> V_85 ;
V_29 = V_84 & ( V_34 - 1 ) ;
V_10 -> V_13 = V_4 -> V_72 + V_27 -> V_15 + V_4 -> V_73 + V_29 ;
V_10 -> V_12 = ( void * ) F_11 ( V_4 -> V_11 , V_10 -> V_13 ) ;
if ( F_26 ( ! V_10 -> V_12 ) )
goto V_24;
F_62 ( V_27 , 0 , V_10 -> V_12 + V_4 -> V_72 + V_29 , V_27 -> V_15 ) ;
F_63 ( V_80 , V_10 -> V_12 + V_29 ,
V_27 -> V_15 + V_4 -> V_72 + V_4 -> V_31 ) ;
return V_10 ;
V_24:
F_5 ( V_10 ) ;
return NULL ;
}
static int F_64 ( struct V_23 * V_27 , struct V_77 * V_78 )
{
struct V_3 * V_4 = F_54 ( V_78 ) ;
struct V_10 * V_10 ;
struct V_79 V_80 ;
unsigned long V_14 ;
bool V_86 = false ;
int V_87 ;
F_6 ( V_4 -> V_2 ) ;
F_8 ( & V_4 -> V_16 , V_14 ) ;
if ( F_26 ( V_4 -> V_2 -> V_17 <= F_65 () ) ) {
V_86 = true ;
V_4 -> V_7 . V_88 ++ ;
}
V_10 = F_60 ( V_4 , V_27 , & V_80 ) ;
if ( F_26 ( ! V_10 ) ) {
V_4 -> V_7 . V_89 ++ ;
V_86 = true ;
if ( V_4 -> V_19 && V_4 -> V_11 ) {
F_4 ( V_4 -> V_11 , V_4 -> V_19 ,
V_4 -> V_20 ) ;
V_4 -> V_19 = 0 ;
V_10 = F_60 ( V_4 , V_27 , & V_80 ) ;
}
}
if ( F_26 ( V_86 ) ) {
V_4 -> V_18 = F_12 ( V_4 -> V_2 ) / 4 ;
F_66 ( V_4 -> V_2 ) ;
F_67 ( V_78 ) ;
}
if ( F_26 ( ! V_10 ) ) {
F_36 ( V_4 -> V_21 , L_6 ) ;
goto V_24;
}
V_87 = F_68 ( V_4 -> V_2 , & V_80 , 1 , V_10 , V_50 ) ;
if ( F_26 ( ( V_87 < 0 ) ) ) {
F_36 ( V_4 -> V_21 , L_7 ,
V_87 ) ;
goto V_24;
}
V_4 -> V_21 -> V_7 . V_90 ++ ;
V_4 -> V_21 -> V_7 . V_91 += V_27 -> V_15 ;
F_10 ( & V_4 -> V_16 , V_14 ) ;
F_69 ( V_4 -> V_2 ) ;
F_35 ( V_27 ) ;
return V_92 ;
V_24:
F_10 ( & V_4 -> V_16 , V_14 ) ;
V_4 -> V_21 -> V_7 . V_93 ++ ;
F_3 ( V_4 , V_10 ) ;
F_35 ( V_27 ) ;
return V_92 ;
}
static void F_70 ( unsigned long V_94 )
{
struct V_3 * V_4 = (struct V_3 * ) V_94 ;
F_6 ( V_4 -> V_2 ) ;
}
static void F_71 ( struct V_77 * V_78 )
{
V_78 -> V_95 = & V_96 ;
V_78 -> type = V_97 ;
V_78 -> V_98 = 100 ;
V_78 -> V_14 = V_99 | V_100 ;
V_78 -> V_74 = V_101 ;
V_78 -> V_102 = true ;
}
static inline void F_72 ( struct V_3 * V_4 )
{
V_4 -> V_103 =
F_73 ( F_74 ( V_4 -> V_21 ) , NULL ) ;
if ( F_75 ( V_4 -> V_103 ) )
return;
F_76 ( L_8 , V_104 , V_4 -> V_103 ,
& V_4 -> V_7 . V_62 ) ;
F_76 ( L_9 , V_104 , V_4 -> V_103 ,
& V_4 -> V_7 . V_60 ) ;
F_76 ( L_10 , V_104 , V_4 -> V_103 ,
& V_4 -> V_7 . V_63 ) ;
F_76 ( L_11 , V_104 , V_4 -> V_103 ,
& V_4 -> V_7 . V_66 ) ;
F_76 ( L_12 , V_104 , V_4 -> V_103 ,
& V_4 -> V_7 . V_88 ) ;
F_76 ( L_13 , V_104 , V_4 -> V_103 ,
& V_4 -> V_7 . V_89 ) ;
F_76 ( L_14 , V_104 , V_4 -> V_103 ,
& V_4 -> V_7 . V_8 ) ;
F_76 ( L_15 , V_104 , V_4 -> V_103 ,
& V_4 -> V_7 . V_22 ) ;
}
static int F_77 ( struct V_64 * V_5 )
{
T_3 * V_105 = F_1 ;
T_4 * V_106 = F_40 ;
const char * V_107 = L_16 ;
const char * V_108 = L_17 ;
struct V_77 * V_78 ;
struct V_3 * V_4 ;
int V_24 = - V_75 ;
V_78 = F_78 ( sizeof( struct V_3 ) , V_108 ,
V_109 , F_71 ) ;
if ( ! V_78 )
return - V_35 ;
V_4 = F_54 ( V_78 ) ;
V_4 -> V_5 = V_5 ;
V_4 -> V_21 = V_78 ;
F_79 ( & V_4 -> V_16 ) ;
V_24 = - V_110 ;
if ( ! V_5 -> V_111 || ! V_5 -> V_111 -> V_112 )
goto V_24;
V_24 = V_5 -> V_111 -> V_112 ( V_5 , 1 , & V_4 -> V_49 , & V_106 ) ;
if ( V_24 )
goto V_24;
V_24 = F_80 ( V_5 , 1 , & V_4 -> V_2 , & V_105 , & V_107 , NULL ) ;
if ( V_24 )
goto V_24;
if ( V_5 -> V_113 -> V_114 ) {
F_81 ( V_5 , struct V_115 , V_116 ,
& V_4 -> V_72 ) ;
F_81 ( V_5 , struct V_115 , V_116 ,
& V_4 -> V_31 ) ;
F_81 ( V_5 , struct V_115 , V_117 ,
& V_4 -> V_73 ) ;
F_81 ( V_5 , struct V_115 , V_117 ,
& V_4 -> V_32 ) ;
F_81 ( V_5 , struct V_115 , V_74 ,
& V_4 -> V_74 ) ;
F_81 ( V_5 , struct V_115 , V_74 ,
& V_4 -> V_30 ) ;
} else {
V_4 -> V_72 = V_118 ;
V_4 -> V_31 = V_118 ;
V_4 -> V_73 = V_119 ;
V_4 -> V_32 = V_119 ;
V_4 -> V_74 = V_101 ;
V_4 -> V_30 = V_101 ;
}
V_78 -> V_120 = V_4 -> V_72 ;
V_78 -> V_121 = V_4 -> V_73 ;
F_14 ( V_4 -> V_2 ) ;
V_78 -> V_74 = V_4 -> V_74 - V_4 -> V_73 ;
V_5 -> V_6 = V_4 ;
F_82 ( & V_4 -> V_43 . V_42 , NULL , 0 ) ;
V_4 -> V_43 . V_47 = V_48 ;
F_83 ( V_78 , & V_4 -> V_37 , F_21 , V_122 ) ;
F_84 ( & V_4 -> V_9 ,
F_70 ,
( unsigned long ) V_4 ) ;
F_37 ( V_78 ) ;
V_24 = F_85 ( V_78 ) ;
if ( V_24 ) {
F_86 ( & V_5 -> V_56 , L_18 , V_24 ) ;
goto V_24;
}
F_72 ( V_4 ) ;
return 0 ;
V_24:
F_36 ( V_4 -> V_21 , L_19 , V_24 ) ;
if ( V_4 -> V_49 )
V_5 -> V_111 -> V_123 ( V_4 -> V_5 ) ;
if ( V_4 -> V_5 )
V_5 -> V_113 -> V_124 ( V_4 -> V_5 ) ;
F_87 ( V_78 ) ;
return V_24 ;
}
static void F_88 ( struct V_64 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_6 ;
F_89 () ;
F_90 ( V_4 -> V_21 ) ;
F_91 () ;
F_92 ( & V_4 -> V_9 ) ;
F_93 ( V_4 -> V_103 ) ;
F_94 ( & V_4 -> V_43 . V_42 ) ;
V_5 -> V_113 -> V_125 ( V_5 ) ;
V_5 -> V_111 -> V_123 ( V_4 -> V_5 ) ;
V_4 -> V_49 = NULL ;
V_5 -> V_113 -> V_124 ( V_4 -> V_5 ) ;
F_95 ( V_4 -> V_21 ) ;
}
