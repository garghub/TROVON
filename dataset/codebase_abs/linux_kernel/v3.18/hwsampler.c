static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
V_3 -> V_4 = F_2 ( V_3 -> V_5 ) ;
}
static void F_3 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
V_3 -> V_4 = F_4 ( V_3 -> V_5 ) ;
}
static int F_5 ( int V_6 )
{
int V_4 ;
struct V_2 V_3 ;
struct V_7 * V_8 ;
V_8 = & F_6 ( V_9 , V_6 ) ;
V_8 -> V_10 . V_11 = 0 ;
V_8 -> V_10 . V_12 = 0 ;
V_3 . V_5 = & V_8 -> V_10 ;
F_7 ( V_6 , F_3 , & V_3 , 1 ) ;
V_4 = V_3 . V_4 ;
if ( V_4 ) {
F_8 ( V_13 L_1 , V_6 ) ;
F_9 () ;
}
V_3 . V_5 = & V_8 -> F_2 ;
F_7 ( V_6 , F_1 , & V_3 , 1 ) ;
if ( V_8 -> F_2 . V_11 || V_8 -> F_2 . V_12 ) {
F_8 ( V_14 L_2 ) ;
F_9 () ;
}
return V_4 ;
}
static int F_10 ( int V_6 )
{
int V_4 ;
struct V_2 V_3 ;
struct V_7 * V_8 ;
V_8 = & F_6 ( V_9 , V_6 ) ;
V_8 -> V_10 . V_11 = 1 ;
V_8 -> V_10 . V_12 = 0 ;
V_3 . V_5 = & V_8 -> V_10 ;
F_7 ( V_6 , F_3 , & V_3 , 1 ) ;
V_4 = V_3 . V_4 ;
if ( V_4 )
F_8 ( V_13 L_1 , V_6 ) ;
V_3 . V_5 = & V_8 -> F_2 ;
F_7 ( V_6 , F_1 , & V_3 , 1 ) ;
if ( V_8 -> F_2 . V_12 )
F_8 ( V_14 L_3 ) ;
return V_4 ;
}
static int F_11 ( int V_6 , unsigned long V_15 )
{
int V_4 ;
struct V_2 V_3 ;
struct V_7 * V_8 ;
V_8 = & F_6 ( V_9 , V_6 ) ;
V_8 -> V_10 . V_16 = 1 ;
V_8 -> V_10 . V_17 = V_8 -> V_18 ;
V_8 -> V_10 . V_19 = * ( unsigned long * ) V_8 -> V_18 ;
V_8 -> V_10 . V_15 = V_15 ;
V_8 -> V_10 . V_11 = 1 ;
V_8 -> V_10 . V_12 = 1 ;
V_3 . V_5 = & V_8 -> V_10 ;
F_7 ( V_6 , F_3 , & V_3 , 1 ) ;
V_4 = V_3 . V_4 ;
if ( V_4 )
F_8 ( V_13 L_1 , V_6 ) ;
V_3 . V_5 = & V_8 -> F_2 ;
F_7 ( V_6 , F_1 , & V_3 , 1 ) ;
if ( V_3 . V_4 )
F_8 ( V_13 L_4 , V_6 ) ;
return V_4 ;
}
static int F_12 ( int V_6 )
{
struct V_2 V_3 ;
struct V_7 * V_8 ;
V_8 = & F_6 ( V_9 , V_6 ) ;
V_3 . V_5 = & V_8 -> F_2 ;
F_7 ( V_6 , F_1 , & V_3 , 1 ) ;
return V_3 . V_4 ;
}
static void F_13 ( struct V_20 V_20 ,
unsigned int V_21 , unsigned long V_22 )
{
struct V_7 * V_8 = F_14 ( & V_9 ) ;
if ( ! ( V_21 & V_23 ) )
return;
if ( ! V_24 )
return;
F_15 ( V_25 ) ;
F_16 ( & V_8 -> V_26 , F_17 ( & V_8 -> V_26 ) | V_21 ) ;
if ( V_27 )
F_18 ( V_27 , & V_8 -> V_28 ) ;
}
static void F_19 ( void )
{
int V_6 ;
struct V_7 * V_8 ;
F_20 (cpu) {
V_8 = & F_6 ( V_9 , V_6 ) ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
}
}
static void F_21 ( void )
{
struct V_7 * V_8 ;
int V_6 ;
F_20 (cpu) {
V_8 = & F_6 ( V_9 , V_6 ) ;
F_22 ( & V_8 -> V_26 , 0 ) ;
V_8 -> V_29 = 0 ;
V_8 -> V_30 = 0 ;
V_8 -> V_31 = 0 ;
V_8 -> V_32 = 0 ;
V_8 -> V_33 = 0 ;
V_8 -> V_34 = 0 ;
V_8 -> V_35 = 0 ;
V_8 -> V_36 = 0 ;
V_8 -> V_37 = 0 ;
V_8 -> V_38 = 0 ;
}
}
static int F_23 ( int V_6 )
{
int V_39 , V_40 , V_4 ;
unsigned long * V_41 ;
unsigned long V_42 ;
unsigned long * V_43 ;
unsigned long * V_44 ;
struct V_7 * V_8 ;
V_8 = & F_6 ( V_9 , V_6 ) ;
if ( V_8 -> V_18 )
return - V_45 ;
V_41 = NULL ;
V_43 = V_41 ;
for ( V_39 = 0 ; V_39 < V_46 ; V_39 ++ ) {
V_41 = ( unsigned long * ) F_24 ( V_47 ) ;
F_25 ( & V_48 ) ;
F_26 () ;
if ( V_49 || ! V_41 ) {
if ( V_41 )
F_27 ( ( unsigned long ) V_41 ) ;
goto V_50;
}
if ( V_8 -> V_18 == 0 )
V_8 -> V_18 = ( unsigned long ) V_41 ;
if ( V_43 )
* V_43 = ( unsigned long ) ( void * ) V_41 + 1 ;
F_28 ( & V_48 ) ;
for ( V_40 = 0 ; V_40 < V_51 ; V_40 ++ ) {
V_42 = F_24 ( V_47 ) ;
F_25 ( & V_48 ) ;
F_26 () ;
if ( V_49 || ! V_42 ) {
if ( V_42 )
F_27 ( V_42 ) ;
goto V_50;
}
* V_41 = V_42 ;
V_44 = F_29 ( * V_41 ) ;
* V_44 = V_52 ;
V_41 ++ ;
F_28 ( & V_48 ) ;
}
V_43 = V_41 ;
}
F_25 ( & V_48 ) ;
if ( V_49 )
goto V_50;
V_4 = 0 ;
if ( V_43 )
* V_43 = ( unsigned long )
( ( void * ) V_8 -> V_18 ) + 1 ;
V_53:
F_28 ( & V_48 ) ;
return V_4 ;
V_50:
V_4 = - V_54 ;
goto V_53;
}
static int F_30 ( void )
{
int V_6 ;
int V_55 ;
V_55 = 0 ;
F_20 (cpu) {
unsigned long V_56 ;
unsigned long V_41 ;
unsigned long * V_57 ;
struct V_7 * V_8 ;
V_8 = & F_6 ( V_9 , V_6 ) ;
if ( ! V_8 -> V_18 )
continue;
V_41 = V_8 -> V_18 ;
V_57 = ( unsigned long * ) V_41 ;
V_56 = V_41 ;
while ( 1 ) {
if ( ! * V_57 || ! V_41 )
break;
if ( F_31 ( V_57 ) ) {
V_57 = F_32 ( V_57 ) ;
if ( V_41 )
F_27 ( V_41 ) ;
if ( ( unsigned long ) V_57 == V_56 )
break;
else
V_41 = ( unsigned long ) V_57 ;
} else {
if ( * V_57 ) {
F_27 ( * V_57 ) ;
V_57 ++ ;
}
}
V_55 ++ ;
}
V_8 -> V_18 = 0 ;
}
return V_55 ;
}
static int F_33 ( int V_6 )
{
int V_4 ;
struct V_7 * V_8 ;
V_8 = & F_6 ( V_9 , V_6 ) ;
V_4 = F_11 ( V_6 , V_15 ) ;
if ( V_4 ) {
F_8 ( V_58 L_5 , V_6 ) ;
goto V_59;
}
V_4 = - V_45 ;
if ( ! V_8 -> F_2 . V_11 ) {
F_8 ( V_58 L_6 , V_6 ) ;
goto V_59;
}
if ( ! V_8 -> F_2 . V_12 ) {
F_8 ( V_58 L_7 , V_6 ) ;
goto V_59;
}
F_8 ( V_58
L_8 ,
V_6 , V_15 ) ;
V_4 = 0 ;
V_59:
return V_4 ;
}
static int F_34 ( int V_6 )
{
unsigned long V_60 ;
int V_4 ;
struct V_7 * V_8 ;
V_4 = F_12 ( V_6 ) ;
F_35 ( V_4 ) ;
V_8 = & F_6 ( V_9 , V_6 ) ;
if ( ! V_4 && ! V_8 -> F_2 . V_11 )
F_8 ( V_58 L_9 , V_6 ) ;
V_4 = F_5 ( V_6 ) ;
if ( V_4 ) {
F_8 ( V_58 L_10 ,
V_6 , V_4 ) ;
goto V_61;
}
F_8 ( V_58 L_11 , V_6 ) ;
V_61:
V_60 = V_8 -> V_31 ;
if ( V_60 )
F_8 ( V_13 L_12
L_13 , V_6 , V_60 ) ;
V_60 = V_8 -> V_34 ;
if ( V_60 )
F_8 ( V_13 L_14
L_13 , V_6 , V_60 ) ;
V_60 = V_8 -> V_33 ;
if ( V_60 )
F_8 ( V_13 L_15
L_13 , V_6 , V_60 ) ;
V_60 = V_8 -> V_32 ;
if ( V_60 )
F_8 ( V_13
L_16
L_13 , V_6 , V_60 ) ;
V_60 = V_8 -> V_35 ;
if ( V_60 )
F_8 ( V_13
L_17
L_13 , V_6 , V_60 ) ;
return V_4 ;
}
static int F_36 ( void )
{
if ( ! F_37 ( 68 ) )
return - V_62 ;
return 0 ;
}
static int F_38 ( struct V_63 * V_64 ,
unsigned long V_65 , void * V_66 )
{
unsigned long * V_67 ;
int V_6 ;
struct V_7 * V_8 ;
V_67 = V_66 ;
F_25 ( & V_48 ) ;
if ( V_68 == V_69 ) {
if ( V_49 == 0 ) {
V_49 = 1 ;
* V_67 += F_30 () ;
}
} else {
int V_70 ;
V_6 = F_39 () ;
V_8 = & F_6 ( V_9 , V_6 ) ;
if ( ! V_8 -> V_37 ) {
F_20 (i) {
F_10 ( V_70 ) ;
V_8 -> V_37 = 1 ;
}
V_8 -> V_36 = 1 ;
F_8 ( V_58
L_18 ,
V_6 ) ;
}
}
F_28 ( & V_48 ) ;
return V_71 ;
}
static int F_40 ( struct V_63 * V_64 ,
unsigned long V_72 , void * V_73 )
{
return ( V_68 <= V_69 ) ? V_71 : V_74 ;
}
int F_41 ( unsigned int V_6 )
{
int V_4 ;
struct V_7 * V_8 ;
V_4 = 0 ;
F_25 ( & V_75 ) ;
V_8 = & F_6 ( V_9 , V_6 ) ;
if ( V_68 == V_76 ) {
V_4 = F_12 ( V_6 ) ;
F_35 ( V_4 ) ;
if ( V_8 -> F_2 . V_12 ) {
V_4 = F_10 ( V_6 ) ;
if ( V_4 ) {
F_8 ( V_58
L_19 , V_6 ) ;
V_8 -> V_36 = 1 ;
V_68 = V_77 ;
} else {
V_78 = 1 ;
F_42 ( V_6 , V_27 , & V_8 -> V_28 ) ;
}
}
}
F_28 ( & V_75 ) ;
if ( V_27 )
F_43 ( V_27 ) ;
return V_4 ;
}
int F_44 ( unsigned int V_6 )
{
int V_4 ;
struct V_7 * V_8 ;
V_4 = 0 ;
F_25 ( & V_75 ) ;
V_8 = & F_6 ( V_9 , V_6 ) ;
if ( V_68 == V_76 ) {
V_4 = F_12 ( V_6 ) ;
F_35 ( V_4 ) ;
if ( ! V_8 -> F_2 . V_12 ) {
V_78 = 0 ;
V_4 = F_11 ( V_6 , V_15 ) ;
if ( V_4 ) {
F_8 ( V_13
L_20 ,
V_6 ) ;
}
}
}
F_28 ( & V_75 ) ;
return V_4 ;
}
static int F_45 ( void )
{
int V_4 ;
unsigned int V_6 ;
struct V_7 * V_8 ;
F_20 (cpu) {
V_8 = & F_6 ( V_9 , V_6 ) ;
V_4 = F_12 ( V_6 ) ;
F_35 ( V_4 ) ;
if ( V_4 )
return - V_62 ;
if ( ! V_8 -> F_2 . V_79 ) {
F_8 ( V_58 L_21 ) ;
return - V_45 ;
}
if ( V_8 -> F_2 . V_11 ) {
F_8 ( V_80 L_22 ) ;
V_4 = F_5 ( V_6 ) ;
if ( V_4 )
return - V_45 ;
F_8 ( V_58
L_23 , V_6 ) ;
}
}
return 0 ;
}
static int F_46 ( void )
{
unsigned int V_6 ;
int V_4 ;
struct V_7 * V_8 ;
F_20 (cpu) {
V_8 = & F_6 ( V_9 , V_6 ) ;
V_4 = F_12 ( V_6 ) ;
F_35 ( V_4 ) ;
if ( ! V_8 -> F_2 . V_79 )
return - V_45 ;
if ( V_8 -> F_2 . V_11 )
return - V_45 ;
if ( V_8 -> F_2 . V_12 )
return - V_45 ;
}
return 0 ;
}
static void F_47 ( unsigned int V_6 )
{
struct V_7 * V_8 ;
V_8 = & F_6 ( V_9 , V_6 ) ;
V_8 -> V_29 = V_8 -> V_18 ;
}
static int F_48 ( unsigned int V_6 , int V_26 )
{
int V_4 ;
unsigned long * V_41 ;
struct V_7 * V_8 ;
V_4 = 0 ;
V_8 = & F_6 ( V_9 , V_6 ) ;
V_41 = ( unsigned long * ) V_8 -> V_29 ;
if ( ! V_41 || ! * V_41 )
return - V_45 ;
if ( V_26 & V_81 )
V_8 -> V_31 ++ ;
if ( V_26 & V_82 )
V_8 -> V_34 ++ ;
if ( V_26 & V_83 ) {
V_8 -> V_33 ++ ;
V_4 = - V_45 ;
}
if ( V_26 & V_84 ) {
V_8 -> V_32 ++ ;
V_4 = - V_45 ;
}
if ( V_26 & V_85 ) {
V_8 -> V_35 ++ ;
V_4 = - V_45 ;
}
return V_4 ;
}
static void F_49 ( unsigned int V_6 )
{
int V_4 , V_70 ;
struct V_7 * V_8 ;
V_8 = & F_6 ( V_9 , V_6 ) ;
if ( V_8 -> V_36 ) {
V_4 = F_12 ( V_6 ) ;
F_35 ( V_4 ) ;
if ( V_8 -> F_2 . V_11 ) {
F_8 ( V_58
L_24 ,
V_6 ) ;
V_4 = F_5 ( V_6 ) ;
if ( V_4 )
F_8 ( V_58
L_19 ,
V_6 ) ;
F_20 (i) {
if ( V_70 == V_6 )
continue;
if ( ! V_8 -> V_36 ) {
V_8 -> V_36 = 1 ;
F_42 ( V_70 , V_27 ,
& V_8 -> V_28 ) ;
}
}
}
}
}
static void F_50 ( unsigned int V_6 )
{
unsigned long * V_41 ;
unsigned char V_86 ;
struct V_7 * V_8 ;
V_8 = & F_6 ( V_9 , V_6 ) ;
V_41 = ( unsigned long * ) V_8 -> V_29 ;
V_86 = 0 ;
while ( ! V_86 && ! V_8 -> V_38 ) {
unsigned long * V_44 ;
struct V_87 * V_88 ;
unsigned long * V_19 = 0 ;
V_44 = F_29 ( * V_41 ) ;
if ( ! ( * V_44 & V_89 ) ) {
V_86 = 1 ;
if ( ! V_78 )
continue;
}
V_88 = (struct V_87 * ) V_44 ;
V_8 -> V_30 += V_88 -> V_90 ;
F_51 ( V_6 , V_41 , V_19 ) ;
F_52 ( ( unsigned char * ) V_88 , 0x40 ) ;
V_41 ++ ;
if ( F_31 ( V_41 ) )
V_41 = F_32 ( V_41 ) ;
V_8 -> V_29 = ( unsigned long ) V_41 ;
}
}
static void F_51 ( unsigned int V_6 , unsigned long * V_41 ,
unsigned long * V_19 )
{
struct V_91 * V_92 ;
unsigned long * V_44 ;
V_44 = F_29 ( * V_41 ) ;
if ( V_19 ) {
if ( V_19 > V_44 )
return;
V_44 = V_19 ;
}
V_92 = (struct V_91 * ) ( * V_41 ) ;
while ( ( unsigned long * ) V_92 < V_44 ) {
struct V_93 * V_94 = NULL ;
struct V_95 * V_96 = NULL ;
if ( V_92 -> V_97 != 1 ) {
break;
} else {
V_92 -> V_97 = 0 ;
}
if ( V_92 -> V_98 == 1 ) {
unsigned int V_99 = V_92 -> V_100 ;
if ( ! V_101 . V_102 )
goto V_103;
F_53 () ;
V_96 = F_54 ( F_55 ( V_99 ) , V_104 ) ;
if ( V_96 )
V_94 = F_56 ( V_96 ) ;
F_57 () ;
} else {
if ( ! V_101 . V_105 )
goto V_103;
V_94 = F_56 ( V_106 ) ;
}
F_25 ( & V_75 ) ;
F_58 ( V_92 -> V_107 , V_94 , 0 ,
! V_92 -> V_98 , V_96 ) ;
F_28 ( & V_75 ) ;
V_103:
V_92 ++ ;
}
}
static void V_28 ( struct V_108 * V_109 )
{
unsigned int V_6 ;
int V_26 ;
struct V_7 * V_8 ;
V_8 = F_59 ( V_109 , struct V_7 , V_28 ) ;
V_6 = F_60 () ;
V_26 = F_16 ( & V_8 -> V_26 , 0 ) ;
if ( ! V_8 -> V_29 )
F_47 ( V_6 ) ;
if ( F_48 ( V_6 , V_26 ) )
return;
if ( ! V_8 -> V_36 )
F_50 ( V_6 ) ;
if ( V_8 -> V_36 )
F_49 ( V_6 ) ;
}
int F_61 ( unsigned long V_41 , unsigned long V_42 )
{
int V_6 , V_4 ;
F_25 ( & V_75 ) ;
V_4 = - V_45 ;
if ( V_68 != V_69 )
goto V_110;
if ( V_41 < 1 )
goto V_110;
if ( V_42 > V_111 || V_42 < V_112 )
goto V_110;
V_46 = V_41 ;
V_51 = V_42 ;
V_49 = 0 ;
F_62 ( & V_113 ) ;
F_20 (cpu) {
if ( F_23 ( V_6 ) ) {
F_63 ( & V_113 ) ;
goto V_114;
}
}
F_63 ( & V_113 ) ;
if ( V_49 )
goto V_114;
V_68 = V_115 ;
V_4 = 0 ;
V_110:
F_28 ( & V_75 ) ;
return V_4 ;
V_114:
V_4 = - V_54 ;
F_8 ( V_13 L_25 ) ;
goto V_110;
}
int F_64 ( void )
{
int V_4 ;
F_25 ( & V_75 ) ;
V_4 = - V_45 ;
if ( V_68 != V_115 )
goto V_116;
F_65 ( V_117 ) ;
V_24 = 0 ;
F_30 () ;
V_68 = V_69 ;
V_4 = 0 ;
V_116:
F_28 ( & V_75 ) ;
return V_4 ;
}
unsigned long F_66 ( void )
{
return V_118 ;
}
unsigned long F_67 ( void )
{
return V_119 ;
}
unsigned long F_68 ( unsigned int V_6 )
{
struct V_7 * V_8 ;
V_8 = & F_6 ( V_9 , V_6 ) ;
return V_8 -> V_30 ;
}
int F_69 ( void )
{
int V_4 ;
int V_6 ;
struct V_7 * V_8 ;
F_25 ( & V_75 ) ;
V_4 = - V_45 ;
if ( V_68 )
goto V_120;
V_68 = V_121 ;
F_19 () ;
V_4 = F_36 () ;
if ( V_4 )
goto V_120;
V_4 = F_45 () ;
if ( V_4 )
goto V_120;
V_4 = - V_45 ;
V_27 = F_70 ( L_26 ) ;
if ( ! V_27 )
goto V_120;
F_71 ( & V_122 ) ;
F_20 (cpu) {
V_8 = & F_6 ( V_9 , V_6 ) ;
F_72 ( & V_8 -> V_28 , V_28 ) ;
V_4 = F_12 ( V_6 ) ;
F_35 ( V_4 ) ;
if ( V_118 != V_8 -> F_2 . V_123 ) {
if ( V_118 ) {
F_8 ( V_80
L_27 ) ;
if ( V_118 < V_8 -> F_2 . V_123 )
V_118 =
V_8 -> F_2 . V_123 ;
} else
V_118 = V_8 -> F_2 . V_123 ;
}
if ( V_119 != V_8 -> F_2 . V_124 ) {
if ( V_119 ) {
F_8 ( V_80
L_28 ) ;
if ( V_119 > V_8 -> F_2 . V_124 )
V_119 =
V_8 -> F_2 . V_124 ;
} else
V_119 = V_8 -> F_2 . V_124 ;
}
}
F_73 ( V_125 , F_13 ) ;
V_68 = V_69 ;
V_4 = 0 ;
V_120:
F_28 ( & V_75 ) ;
return V_4 ;
}
int F_74 ( void )
{
int V_4 ;
F_25 ( & V_75 ) ;
V_4 = - V_45 ;
if ( V_68 == V_69 || V_68 == V_115 ) {
F_28 ( & V_75 ) ;
if ( V_27 )
F_43 ( V_27 ) ;
F_25 ( & V_75 ) ;
if ( V_68 == V_115 ) {
F_65 ( V_117 ) ;
V_24 = 0 ;
F_30 () ;
}
if ( V_27 ) {
F_75 ( V_27 ) ;
V_27 = NULL ;
}
F_76 ( V_125 , F_13 ) ;
V_68 = V_121 ;
V_4 = 0 ;
}
F_28 ( & V_75 ) ;
F_77 ( & V_122 ) ;
return V_4 ;
}
int F_78 ( unsigned long V_126 )
{
int V_4 , V_6 ;
F_25 ( & V_75 ) ;
V_127 = 0 ;
V_4 = - V_45 ;
if ( V_68 != V_115 )
goto V_128;
V_15 = V_126 ;
if ( V_15 < V_118 || V_15 > V_119 )
goto V_128;
V_4 = F_46 () ;
if ( V_4 )
goto V_128;
F_21 () ;
F_20 (cpu) {
V_4 = F_33 ( V_6 ) ;
if ( V_4 )
break;
}
if ( V_4 ) {
F_20 (cpu) {
F_34 ( V_6 ) ;
}
goto V_128;
}
V_68 = V_76 ;
V_4 = 0 ;
V_128:
F_28 ( & V_75 ) ;
if ( V_4 )
return V_4 ;
F_62 ( & V_113 ) ;
V_127 = 1 ;
V_78 = 0 ;
V_24 = 1 ;
F_79 ( V_117 ) ;
return 0 ;
}
int F_80 ( void )
{
int V_129 , V_4 , V_6 ;
struct V_7 * V_8 ;
F_25 ( & V_75 ) ;
V_4 = 0 ;
if ( V_68 == V_121 ) {
F_28 ( & V_75 ) ;
return 0 ;
}
V_68 = V_77 ;
F_28 ( & V_75 ) ;
F_20 (cpu) {
V_8 = & F_6 ( V_9 , V_6 ) ;
V_8 -> V_38 = 1 ;
V_129 = F_34 ( V_6 ) ;
if ( V_129 )
V_4 = V_129 ;
}
if ( V_27 )
F_43 ( V_27 ) ;
F_25 ( & V_75 ) ;
if ( V_127 ) {
F_63 ( & V_113 ) ;
V_127 = 0 ;
}
V_68 = V_115 ;
F_28 ( & V_75 ) ;
return V_4 ;
}
