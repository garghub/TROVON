static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_6 -> V_7 -> V_8 ( V_4 , V_2 -> V_9 ) ;
}
static int F_2 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_12 * V_12 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_13 = V_11 -> V_13 ;
if ( ! V_4 )
return V_14 ;
V_12 = F_3 ( V_4 -> V_15 + ( V_13 << V_16 ) ) ;
if ( ! V_12 )
return V_17 ;
F_4 ( V_12 ) ;
V_11 -> V_12 = V_12 ;
return 0 ;
}
static struct V_12 * * F_5 ( unsigned int V_18 )
{
const T_2 V_19 = V_18 * sizeof( struct V_12 * ) ;
if ( V_19 > V_20 )
return F_6 ( V_19 ) ;
return F_7 ( V_19 , V_21 ) ;
}
static void F_8 ( struct V_12 * * V_22 )
{
F_9 ( V_22 ) ;
}
static int F_10 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
unsigned long V_23 = V_2 -> V_24 - V_2 -> V_25 ;
struct V_26 * V_27 = V_2 -> V_9 ;
if ( ! V_4 )
return - V_28 ;
if ( V_23 != ( unsigned long ) V_4 -> V_6 -> V_29 )
return - V_30 ;
V_2 -> V_31 = & V_32 ;
V_2 -> V_33 |= V_34 ;
V_2 -> V_5 = V_4 ;
V_4 -> V_6 -> V_7 -> V_35 ( V_4 , V_27 ) ;
return 0 ;
}
static void * F_11 ( struct V_3 * V_4 , T_2 * V_36 )
{
void * V_37 ;
unsigned int V_38 , V_39 , V_18 ;
* V_36 = F_12 ( * V_36 ) ;
V_18 = * V_36 >> V_16 ;
V_4 -> V_40 = F_5 ( V_18 ) ;
if ( ! V_4 -> V_40 )
return NULL ;
for ( V_38 = 0 ; V_38 < V_18 ; V_38 ++ ) {
V_4 -> V_40 [ V_38 ] = F_13 ( V_21 ) ;
if ( F_14 ( ! V_4 -> V_40 [ V_38 ] ) )
goto V_41;
F_15 ( V_4 -> V_40 [ V_38 ] , ( unsigned long ) V_4 ) ;
}
V_37 = F_16 ( V_4 -> V_40 , V_18 , V_42 , V_43 ) ;
if ( ! V_37 )
goto V_41;
memset ( V_37 , 0 , * V_36 ) ;
V_4 -> V_44 = V_18 ;
return V_37 ;
V_41:
for ( V_39 = 0 ; V_39 < V_38 ; V_39 ++ )
F_17 ( V_4 -> V_40 [ V_39 ] ) ;
F_8 ( V_4 -> V_40 ) ;
return NULL ;
}
static struct V_3 * F_18 ( struct V_45 * V_6 )
{
struct V_3 * V_4 ;
if ( V_6 -> V_46 > V_47 / sizeof( T_2 * ) )
return NULL ;
V_4 = F_7 ( sizeof( struct V_3 ) , V_21 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_48 = F_19 ( V_6 -> V_46 * sizeof( T_2 * ) , V_21 ) ;
if ( ! V_4 -> V_48 )
goto V_49;
V_4 -> V_15 = F_11 ( V_4 , & V_6 -> V_29 ) ;
if ( ! V_4 -> V_15 )
goto V_49;
V_4 -> V_6 = V_6 ;
F_20 ( & V_4 -> V_6 -> V_50 ) ;
return V_4 ;
V_49:
F_21 ( V_4 -> V_48 ) ;
F_21 ( V_4 ) ;
return NULL ;
}
static void F_22 ( struct V_50 * V_50 )
{
struct V_45 * V_6 = F_23 ( V_50 , struct V_45 , V_50 ) ;
F_21 ( V_6 ) ;
}
static void F_24 ( struct V_3 * V_4 )
{
struct V_45 * V_6 = V_4 -> V_6 ;
unsigned int V_38 ;
if ( F_25 ( V_4 -> V_15 ) ) {
F_26 ( V_4 -> V_15 ) ;
for ( V_38 = 0 ; V_38 < V_4 -> V_44 ; V_38 ++ )
F_17 ( V_4 -> V_40 [ V_38 ] ) ;
F_8 ( V_4 -> V_40 ) ;
}
* F_27 ( V_6 -> V_4 , V_4 -> V_51 ) = NULL ;
F_21 ( V_4 -> V_48 ) ;
F_21 ( V_4 ) ;
F_28 ( & V_6 -> V_50 , F_22 ) ;
}
static void F_29 ( struct V_50 * V_50 )
{
struct V_3 * V_4 = F_23 ( V_50 , struct V_3 , V_50 ) ;
F_24 ( V_4 ) ;
}
static int F_30 ( struct V_3 * V_4 )
{
return ( V_4 -> V_52 - V_4 -> V_53 ) ? 0 : 1 ;
}
int F_31 ( struct V_3 * V_4 )
{
T_2 V_54 = V_4 -> V_52 - V_4 -> V_53 ;
return ( V_54 >= V_4 -> V_6 -> V_46 ) ? 1 : 0 ;
}
static int F_32 ( struct V_3 * V_4 ,
void * V_55 ,
void * V_56 ,
T_2 V_57 )
{
if ( F_31 ( V_4 ) )
return 0 ;
return 1 ;
}
static void F_33 ( struct V_3 * V_4 ,
struct V_26 * V_27 )
{
}
static void F_34 ( struct V_3 * V_4 ,
struct V_26 * V_27 )
{
}
static struct V_58 * F_35 ( const char * V_59 ,
struct V_58 * V_60 ,
T_3 V_61 ,
struct V_3 * V_4 ,
int * V_62 )
{
return NULL ;
}
static int F_36 ( struct V_58 * V_58 )
{
return - V_30 ;
}
static void F_37 ( struct V_63 * V_64 )
{
struct V_3 * V_4 ;
V_4 = F_23 ( V_64 , struct V_3 , V_65 ) ;
F_38 ( & V_4 -> V_66 ) ;
}
static void F_39 ( struct V_3 * V_4 , unsigned int V_67 )
{
T_2 V_38 ;
if ( V_67 ) {
F_40 ( & V_4 -> V_66 ) ;
F_41 ( & V_4 -> V_50 ) ;
F_42 ( & V_4 -> V_65 , F_37 ) ;
} else {
F_43 ( & V_4 -> V_65 ) ;
}
V_4 -> V_52 = 0 ;
V_4 -> V_53 = 0 ;
V_4 -> V_68 = 0 ;
V_4 -> V_69 = 0 ;
V_4 -> V_70 = V_4 -> V_15 ;
V_4 -> V_71 = 0 ;
for ( V_38 = 0 ; V_38 < V_4 -> V_6 -> V_46 ; V_38 ++ )
V_4 -> V_48 [ V_38 ] = 0 ;
V_4 -> V_6 -> V_7 -> V_72 ( V_4 , V_4 -> V_70 , NULL , 0 ) ;
}
void F_44 ( struct V_45 * V_6 )
{
struct V_3 * V_4 ;
unsigned int V_38 ;
if ( ! V_6 )
return;
if ( V_6 -> V_62 && ( V_4 = * F_27 ( V_6 -> V_4 , 0 ) ) ) {
F_39 ( V_4 , 0 ) ;
return;
}
F_45 ( & V_73 ) ;
F_46 (i)
if ( ( V_4 = * F_27 ( V_6 -> V_4 , V_38 ) ) )
F_39 ( V_4 , 0 ) ;
F_47 ( & V_73 ) ;
}
static inline void F_48 ( struct V_3 * V_4 ,
struct V_58 * V_58 )
{
V_4 -> V_58 = V_58 ;
F_49 ( V_4 -> V_58 ) -> V_74 = V_4 -> V_75 ;
}
static struct V_58 * F_50 ( struct V_45 * V_6 ,
struct V_3 * V_4 ,
unsigned int V_51 )
{
struct V_58 * V_58 ;
char * V_76 ;
V_76 = F_7 ( V_77 + 1 , V_21 ) ;
if ( ! V_76 )
return NULL ;
snprintf ( V_76 , V_77 , L_1 , V_6 -> V_78 , V_51 ) ;
V_58 = V_6 -> V_7 -> V_79 ( V_76 , V_6 -> V_60 ,
V_80 , V_4 ,
& V_6 -> V_62 ) ;
F_21 ( V_76 ) ;
return V_58 ;
}
static struct V_3 * F_51 ( struct V_45 * V_6 , unsigned int V_51 )
{
struct V_3 * V_4 = NULL ;
struct V_58 * V_58 ;
if ( V_6 -> V_62 )
return * F_27 ( V_6 -> V_4 , 0 ) ;
V_4 = F_18 ( V_6 ) ;
if ( ! V_4 )
return NULL ;
if ( V_6 -> V_81 ) {
V_58 = F_50 ( V_6 , V_4 , V_51 ) ;
if ( ! V_58 )
goto V_49;
F_48 ( V_4 , V_58 ) ;
} else {
V_58 = V_6 -> V_7 -> V_79 ( NULL , NULL ,
V_80 , V_4 ,
& V_6 -> V_62 ) ;
if ( F_52 ( V_58 ) )
goto V_49;
}
V_4 -> V_51 = V_51 ;
F_39 ( V_4 , 1 ) ;
if( V_6 -> V_62 ) {
* F_27 ( V_6 -> V_4 , 0 ) = V_4 ;
V_4 -> V_51 = 0 ;
}
return V_4 ;
V_49:
F_24 ( V_4 ) ;
return NULL ;
}
static void F_53 ( struct V_3 * V_4 )
{
V_4 -> V_69 = 1 ;
F_43 ( & V_4 -> V_65 ) ;
V_4 -> V_6 -> V_7 -> V_82 ( V_4 -> V_58 ) ;
F_28 ( & V_4 -> V_50 , F_29 ) ;
}
static void F_54 ( struct V_45 * V_6 ,
struct V_83 * V_7 )
{
if ( ! V_7 ) {
V_6 -> V_7 = & V_84 ;
return;
}
if ( ! V_7 -> V_72 )
V_7 -> V_72 = F_32 ;
if ( ! V_7 -> V_35 )
V_7 -> V_35 = F_33 ;
if ( ! V_7 -> V_8 )
V_7 -> V_8 = F_34 ;
if ( ! V_7 -> V_79 )
V_7 -> V_79 = F_35 ;
if ( ! V_7 -> V_82 )
V_7 -> V_82 = F_36 ;
V_6 -> V_7 = V_7 ;
}
int F_55 ( unsigned int V_51 )
{
struct V_45 * V_6 ;
struct V_3 * V_4 ;
F_45 ( & V_73 ) ;
F_56 (chan, &relay_channels, list) {
if ( ( V_4 = * F_27 ( V_6 -> V_4 , V_51 ) ) )
continue;
V_4 = F_51 ( V_6 , V_51 ) ;
if ( ! V_4 ) {
F_57 ( L_2 , V_51 ) ;
F_47 ( & V_73 ) ;
return - V_85 ;
}
* F_27 ( V_6 -> V_4 , V_51 ) = V_4 ;
}
F_47 ( & V_73 ) ;
return 0 ;
}
struct V_45 * F_58 ( const char * V_78 ,
struct V_58 * V_60 ,
T_2 V_86 ,
T_2 V_46 ,
struct V_83 * V_7 ,
void * V_87 )
{
unsigned int V_38 ;
struct V_45 * V_6 ;
struct V_3 * V_4 ;
if ( ! ( V_86 && V_46 ) )
return NULL ;
if ( V_86 > V_47 / V_46 )
return NULL ;
V_6 = F_7 ( sizeof( struct V_45 ) , V_21 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_4 = F_59 ( struct V_3 * ) ;
V_6 -> V_88 = V_89 ;
V_6 -> V_46 = V_46 ;
V_6 -> V_86 = V_86 ;
V_6 -> V_29 = F_12 ( V_86 * V_46 ) ;
V_6 -> V_60 = V_60 ;
V_6 -> V_87 = V_87 ;
if ( V_78 ) {
V_6 -> V_81 = 1 ;
F_60 ( V_6 -> V_78 , V_78 , V_77 ) ;
}
F_54 ( V_6 , V_7 ) ;
F_41 ( & V_6 -> V_50 ) ;
F_45 ( & V_73 ) ;
F_61 (i) {
V_4 = F_51 ( V_6 , V_38 ) ;
if ( ! V_4 )
goto V_90;
* F_27 ( V_6 -> V_4 , V_38 ) = V_4 ;
}
F_62 ( & V_6 -> V_91 , & V_92 ) ;
F_47 ( & V_73 ) ;
return V_6 ;
V_90:
F_46 (i) {
if ( ( V_4 = * F_27 ( V_6 -> V_4 , V_38 ) ) )
F_53 ( V_4 ) ;
}
F_28 ( & V_6 -> V_50 , F_22 ) ;
F_47 ( & V_73 ) ;
F_21 ( V_6 ) ;
return NULL ;
}
static void F_63 ( void * V_93 )
{
struct V_94 * V_95 = V_93 ;
F_48 ( V_95 -> V_4 , V_95 -> V_58 ) ;
}
int F_64 ( struct V_45 * V_6 ,
const char * V_78 ,
struct V_58 * V_60 )
{
int V_96 = 0 ;
unsigned int V_38 , V_97 ;
unsigned long V_98 ;
struct V_58 * V_58 ;
struct V_3 * V_4 ;
struct V_94 V_99 ;
if ( ! V_6 || ! V_78 )
return - V_30 ;
F_60 ( V_6 -> V_78 , V_78 , V_77 ) ;
F_45 ( & V_73 ) ;
if ( F_14 ( V_6 -> V_81 ) ) {
F_47 ( & V_73 ) ;
return - V_100 ;
}
V_6 -> V_81 = 1 ;
V_6 -> V_60 = V_60 ;
if ( V_6 -> V_62 ) {
V_96 = - V_30 ;
V_4 = * F_27 ( V_6 -> V_4 , 0 ) ;
if ( ! F_65 ( ! V_4 ) ) {
V_58 = F_50 ( V_6 , V_4 , 0 ) ;
if ( V_58 && ! F_65 ( ! V_6 -> V_62 ) ) {
F_48 ( V_4 , V_58 ) ;
V_96 = 0 ;
}
}
F_47 ( & V_73 ) ;
return V_96 ;
}
V_97 = F_66 () ;
F_61 (i) {
V_4 = * F_27 ( V_6 -> V_4 , V_38 ) ;
if ( F_14 ( ! V_4 ) ) {
F_67 ( 1 , V_101 L_3 ) ;
V_96 = - V_30 ;
break;
}
V_58 = F_50 ( V_6 , V_4 , V_38 ) ;
if ( F_14 ( ! V_58 ) ) {
V_96 = - V_30 ;
break;
}
if ( V_97 == V_38 ) {
F_68 ( V_98 ) ;
F_48 ( V_4 , V_58 ) ;
F_69 ( V_98 ) ;
} else {
V_99 . V_4 = V_4 ;
V_99 . V_58 = V_58 ;
F_70 () ;
V_96 = F_71 ( V_38 ,
F_63 ,
& V_99 , 1 ) ;
}
if ( F_14 ( V_96 ) )
break;
}
F_72 () ;
F_47 ( & V_73 ) ;
return V_96 ;
}
T_2 F_73 ( struct V_3 * V_4 , T_2 V_23 )
{
void * V_102 , * V_103 ;
T_2 V_104 , V_105 ;
if ( F_14 ( V_23 > V_4 -> V_6 -> V_86 ) )
goto V_106;
if ( V_4 -> V_71 != V_4 -> V_6 -> V_86 + 1 ) {
V_4 -> V_57 = V_4 -> V_6 -> V_86 - V_4 -> V_71 ;
V_104 = V_4 -> V_52 % V_4 -> V_6 -> V_46 ;
V_4 -> V_48 [ V_104 ] = V_4 -> V_57 ;
V_4 -> V_52 ++ ;
if ( V_4 -> V_58 )
F_49 ( V_4 -> V_58 ) -> V_74 +=
V_4 -> V_6 -> V_86 -
V_4 -> V_48 [ V_104 ] ;
else
V_4 -> V_75 += V_4 -> V_6 -> V_86 -
V_4 -> V_48 [ V_104 ] ;
F_70 () ;
if ( F_74 ( & V_4 -> V_66 ) ) {
F_75 ( & V_4 -> V_65 ) ;
}
}
V_102 = V_4 -> V_70 ;
V_105 = V_4 -> V_52 % V_4 -> V_6 -> V_46 ;
V_103 = V_4 -> V_15 + V_105 * V_4 -> V_6 -> V_86 ;
V_4 -> V_71 = 0 ;
if ( ! V_4 -> V_6 -> V_7 -> V_72 ( V_4 , V_103 , V_102 , V_4 -> V_57 ) ) {
V_4 -> V_71 = V_4 -> V_6 -> V_86 + 1 ;
return 0 ;
}
V_4 -> V_70 = V_103 ;
V_4 -> V_48 [ V_105 ] = 0 ;
if ( F_14 ( V_23 + V_4 -> V_71 > V_4 -> V_6 -> V_86 ) )
goto V_106;
return V_23 ;
V_106:
V_4 -> V_6 -> V_107 = V_23 ;
return 0 ;
}
void F_76 ( struct V_45 * V_6 ,
unsigned int V_51 ,
T_2 V_53 )
{
struct V_3 * V_4 ;
if ( ! V_6 || V_51 >= V_108 )
return;
V_4 = * F_27 ( V_6 -> V_4 , V_51 ) ;
if ( ! V_4 || V_53 > V_6 -> V_46 )
return;
if ( V_53 > V_4 -> V_52 - V_4 -> V_53 )
V_4 -> V_53 = V_4 -> V_52 ;
else
V_4 -> V_53 += V_53 ;
}
void F_77 ( struct V_45 * V_6 )
{
struct V_3 * V_4 ;
unsigned int V_38 ;
if ( ! V_6 )
return;
F_45 ( & V_73 ) ;
if ( V_6 -> V_62 && ( V_4 = * F_27 ( V_6 -> V_4 , 0 ) ) )
F_53 ( V_4 ) ;
else
F_46 (i)
if ( ( V_4 = * F_27 ( V_6 -> V_4 , V_38 ) ) )
F_53 ( V_4 ) ;
if ( V_6 -> V_107 )
F_78 ( V_109 L_4
L_5 ,
V_6 -> V_107 , V_6 -> V_86 ) ;
F_79 ( & V_6 -> V_91 ) ;
F_28 ( & V_6 -> V_50 , F_22 ) ;
F_47 ( & V_73 ) ;
}
void F_80 ( struct V_45 * V_6 )
{
struct V_3 * V_4 ;
unsigned int V_38 ;
if ( ! V_6 )
return;
if ( V_6 -> V_62 && ( V_4 = * F_27 ( V_6 -> V_4 , 0 ) ) ) {
F_73 ( V_4 , 0 ) ;
return;
}
F_45 ( & V_73 ) ;
F_46 (i)
if ( ( V_4 = * F_27 ( V_6 -> V_4 , V_38 ) ) )
F_73 ( V_4 , 0 ) ;
F_47 ( & V_73 ) ;
}
static int F_81 ( struct V_110 * V_110 , struct V_26 * V_27 )
{
struct V_3 * V_4 = V_110 -> V_111 ;
F_20 ( & V_4 -> V_50 ) ;
V_27 -> V_87 = V_4 ;
return F_82 ( V_110 , V_27 ) ;
}
static int F_83 ( struct V_26 * V_27 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_27 -> V_87 ;
return F_10 ( V_4 , V_2 ) ;
}
static unsigned int F_84 ( struct V_26 * V_27 , T_4 * V_112 )
{
unsigned int V_113 = 0 ;
struct V_3 * V_4 = V_27 -> V_87 ;
if ( V_4 -> V_69 )
return V_114 ;
if ( V_27 -> V_115 & V_116 ) {
F_85 ( V_27 , & V_4 -> V_66 , V_112 ) ;
if ( ! F_30 ( V_4 ) )
V_113 |= V_117 | V_118 ;
}
return V_113 ;
}
static int F_86 ( struct V_110 * V_110 , struct V_26 * V_27 )
{
struct V_3 * V_4 = V_27 -> V_87 ;
F_28 ( & V_4 -> V_50 , F_29 ) ;
return 0 ;
}
static void F_87 ( struct V_3 * V_4 ,
T_2 V_119 ,
T_2 V_68 )
{
T_2 V_86 = V_4 -> V_6 -> V_86 ;
T_2 V_46 = V_4 -> V_6 -> V_46 ;
T_2 V_120 ;
if ( V_4 -> V_52 == V_4 -> V_53 &&
V_4 -> V_71 == V_4 -> V_68 )
return;
if ( V_4 -> V_68 + V_68 > V_86 ) {
F_76 ( V_4 -> V_6 , V_4 -> V_51 , 1 ) ;
V_4 -> V_68 = 0 ;
}
V_4 -> V_68 += V_68 ;
if ( ! V_119 )
V_120 = V_4 -> V_53 % V_46 ;
else
V_120 = V_119 / V_4 -> V_6 -> V_86 ;
if ( V_4 -> V_68 + V_4 -> V_48 [ V_120 ] == V_86 ) {
if ( ( V_120 == V_4 -> V_52 % V_46 ) &&
( V_4 -> V_71 == V_86 ) )
return;
F_76 ( V_4 -> V_6 , V_4 -> V_51 , 1 ) ;
V_4 -> V_68 = 0 ;
}
}
static int F_88 ( struct V_3 * V_4 , T_2 V_119 )
{
T_2 V_86 = V_4 -> V_6 -> V_86 ;
T_2 V_46 = V_4 -> V_6 -> V_46 ;
T_2 V_121 = V_4 -> V_52 ;
T_2 V_122 = V_4 -> V_53 ;
F_87 ( V_4 , V_119 , 0 ) ;
V_122 = V_4 -> V_53 ;
if ( F_14 ( V_4 -> V_71 > V_86 ) ) {
if ( V_121 == V_122 )
return 0 ;
return 1 ;
}
if ( F_14 ( V_121 - V_122 >= V_46 ) ) {
V_122 = V_121 - V_46 + 1 ;
V_4 -> V_53 = V_122 ;
V_4 -> V_68 = 0 ;
}
V_121 = ( V_121 % V_46 ) * V_86 + V_4 -> V_71 ;
V_122 = ( V_122 % V_46 ) * V_86 + V_4 -> V_68 ;
if ( V_122 > V_121 )
V_121 += V_46 * V_86 ;
if ( V_122 == V_121 ) {
if ( V_4 -> V_71 == V_86 &&
V_4 -> V_52 > V_4 -> V_53 )
return 1 ;
return 0 ;
}
return 1 ;
}
static T_2 F_89 ( T_2 V_119 ,
struct V_3 * V_4 )
{
T_2 V_48 , V_123 = 0 ;
T_2 V_120 , V_124 , V_125 , V_126 ;
T_2 V_86 = V_4 -> V_6 -> V_86 ;
V_125 = ( V_4 -> V_70 - V_4 -> V_15 ) / V_86 ;
V_126 = V_4 -> V_71 > V_86 ? V_86 : V_4 -> V_71 ;
V_120 = V_119 / V_86 ;
V_124 = V_119 % V_86 ;
V_48 = V_4 -> V_48 [ V_120 ] ;
if ( V_120 == V_125 ) {
if ( V_124 + V_48 < V_126 )
V_123 = V_126 - ( V_124 + V_48 ) ;
} else
V_123 = ( V_86 - V_48 ) - V_124 ;
return V_123 ;
}
static T_2 F_90 ( T_2 V_119 ,
struct V_3 * V_4 )
{
T_2 V_120 , V_48 , V_127 , V_128 ;
T_2 V_86 = V_4 -> V_6 -> V_86 ;
T_2 V_46 = V_4 -> V_6 -> V_46 ;
T_2 V_122 = V_4 -> V_53 % V_46 ;
if ( ! V_119 )
V_119 = V_122 * V_86 + V_4 -> V_68 ;
V_120 = V_119 / V_86 ;
V_48 = V_4 -> V_48 [ V_120 ] ;
V_127 = ( V_120 + 1 ) * V_86 - V_48 ;
V_128 = ( V_120 + 1 ) * V_86 ;
if ( V_119 >= V_127 && V_119 < V_128 ) {
V_120 = ( V_120 + 1 ) % V_46 ;
V_119 = V_120 * V_86 ;
}
return V_119 ;
}
static T_2 F_91 ( struct V_3 * V_4 ,
T_2 V_119 ,
T_2 V_129 )
{
T_2 V_120 , V_48 , V_130 ;
T_2 V_86 = V_4 -> V_6 -> V_86 ;
T_2 V_46 = V_4 -> V_6 -> V_46 ;
V_120 = V_119 / V_86 ;
V_48 = V_4 -> V_48 [ V_120 ] ;
if ( V_119 % V_86 + V_129 + V_48 == V_86 )
V_130 = ( V_120 + 1 ) * V_86 ;
else
V_130 = V_119 + V_129 ;
if ( V_130 >= V_86 * V_46 )
V_130 = 0 ;
return V_130 ;
}
static T_5 F_92 ( struct V_26 * V_27 ,
char T_6 * V_131 ,
T_2 V_129 ,
T_7 * V_132 )
{
struct V_3 * V_4 = V_27 -> V_87 ;
T_2 V_133 , V_123 ;
T_2 V_134 = 0 ;
int V_135 ;
if ( ! V_129 )
return 0 ;
F_93 ( F_94 ( V_27 ) ) ;
do {
void * V_136 ;
if ( ! F_88 ( V_4 , * V_132 ) )
break;
V_133 = F_90 ( * V_132 , V_4 ) ;
V_123 = F_89 ( V_133 , V_4 ) ;
if ( ! V_123 )
break;
V_123 = F_95 ( V_129 , V_123 ) ;
V_136 = V_4 -> V_15 + V_133 ;
V_135 = V_123 ;
if ( F_96 ( V_131 , V_136 , V_123 ) )
break;
V_131 += V_135 ;
V_134 += V_135 ;
V_129 -= V_135 ;
F_87 ( V_4 , V_133 , V_135 ) ;
* V_132 = F_91 ( V_4 , V_133 , V_135 ) ;
} while ( V_129 );
F_97 ( F_94 ( V_27 ) ) ;
return V_134 ;
}
static void F_98 ( struct V_3 * V_137 , int V_68 )
{
V_137 -> V_68 += V_68 ;
if ( V_137 -> V_68 >= V_137 -> V_6 -> V_86 ) {
F_76 ( V_137 -> V_6 , V_137 -> V_51 , 1 ) ;
V_137 -> V_68 %= V_137 -> V_6 -> V_86 ;
}
}
static void F_99 ( struct V_138 * V_139 ,
struct V_140 * V_4 )
{
struct V_3 * V_137 ;
V_137 = (struct V_3 * ) F_100 ( V_4 -> V_12 ) ;
F_98 ( V_137 , V_4 -> V_141 ) ;
}
static void F_101 ( struct V_142 * V_143 , unsigned int V_38 )
{
}
static T_5 F_102 ( struct V_26 * V_144 ,
T_7 * V_132 ,
struct V_138 * V_139 ,
T_2 V_145 ,
unsigned int V_98 ,
int * V_146 )
{
unsigned int V_147 , V_148 , V_149 , V_150 , V_151 ;
struct V_3 * V_137 = V_144 -> V_87 ;
unsigned int V_86 = V_137 -> V_6 -> V_86 ;
T_8 V_152 = ( T_8 ) * V_132 ;
T_9 V_29 = ( T_9 ) V_137 -> V_6 -> V_29 ;
T_2 V_133 = ( T_2 ) F_103 ( V_152 , V_29 ) ;
T_2 V_120 = V_133 / V_86 ;
T_2 V_48 = V_137 -> V_48 [ V_120 ] ;
T_2 V_153 = V_120 * V_86 + V_86 - V_48 ;
struct V_12 * V_154 [ V_155 ] ;
struct V_156 V_157 [ V_155 ] ;
struct V_142 V_143 = {
. V_154 = V_154 ,
. V_151 = 0 ,
. V_158 = V_155 ,
. V_157 = V_157 ,
. V_98 = V_98 ,
. V_159 = & V_160 ,
. V_161 = F_101 ,
} ;
T_5 V_135 ;
if ( V_137 -> V_52 == V_137 -> V_53 )
return 0 ;
if ( F_104 ( V_139 , & V_143 ) )
return - V_85 ;
if ( V_145 > ( V_86 - V_133 % V_86 ) )
V_145 = V_86 - V_133 % V_86 ;
V_150 = V_137 -> V_6 -> V_29 >> V_16 ;
V_147 = ( V_133 / V_20 ) % V_150 ;
V_148 = V_133 & ~ V_162 ;
V_151 = F_105 (unsigned int, subbuf_pages, spd.nr_pages_max) ;
for ( V_149 = 0 ; V_143 . V_151 < V_151 ; V_143 . V_151 ++ ) {
unsigned int V_163 , V_164 , V_141 ;
unsigned int V_165 = V_133 + V_149 ;
if ( ! V_145 )
break;
V_163 = F_105 (unsigned long, len, PAGE_SIZE - poff) ;
V_141 = V_163 ;
V_143 . V_154 [ V_143 . V_151 ] = V_137 -> V_40 [ V_147 ] ;
V_143 . V_157 [ V_143 . V_151 ] . V_71 = V_148 ;
V_164 = V_165 + V_163 ;
if ( V_164 >= V_153 ) {
V_163 = V_153 - V_165 ;
V_141 = V_163 + V_48 ;
}
V_143 . V_157 [ V_143 . V_151 ] . V_145 = V_163 ;
V_143 . V_157 [ V_143 . V_151 ] . V_141 = V_141 ;
V_145 -= V_163 ;
V_149 += V_163 ;
V_148 = 0 ;
V_147 = ( V_147 + 1 ) % V_150 ;
if ( V_164 >= V_153 ) {
V_143 . V_151 ++ ;
break;
}
}
V_135 = 0 ;
if ( ! V_143 . V_151 )
goto V_166;
V_135 = * V_146 = F_106 ( V_139 , & V_143 ) ;
if ( V_135 < 0 || V_135 < V_149 )
goto V_166;
if ( V_133 + V_135 == V_153 )
V_135 += V_48 ;
V_166:
F_107 ( & V_143 ) ;
return V_135 ;
}
static T_5 F_108 ( struct V_26 * V_144 ,
T_7 * V_132 ,
struct V_138 * V_139 ,
T_2 V_145 ,
unsigned int V_98 )
{
T_5 V_167 ;
int V_135 ;
int V_146 = 0 ;
V_135 = 0 ;
V_167 = 0 ;
while ( V_145 && ! V_167 ) {
V_135 = F_102 ( V_144 , V_132 , V_139 , V_145 , V_98 , & V_146 ) ;
if ( V_135 < 0 )
break;
else if ( ! V_135 ) {
if ( V_98 & V_168 )
V_135 = - V_169 ;
break;
}
* V_132 += V_135 ;
if ( V_135 > V_145 )
V_145 = 0 ;
else
V_145 -= V_135 ;
V_167 += V_146 ;
V_146 = 0 ;
}
if ( V_167 )
return V_167 ;
return V_135 ;
}
