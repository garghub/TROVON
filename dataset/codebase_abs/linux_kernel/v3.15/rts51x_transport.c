unsigned int F_1 ( unsigned char * V_1 ,
unsigned int V_2 , void * V_3 ,
void * * V_4 , unsigned int * V_5 ,
enum V_6 V_7 )
{
unsigned int V_8 ;
struct V_9 * V_10 = (struct V_9 * ) * V_4 ;
if ( ! V_10 )
V_10 = (struct V_9 * ) V_3 ;
V_8 = 0 ;
while ( V_8 < V_2 && V_10 ) {
struct V_11 * V_11 = F_2 ( V_10 ) +
( ( V_10 -> V_5 + * V_5 ) >> V_12 ) ;
unsigned int V_13 = ( V_10 -> V_5 + * V_5 ) & ( V_14 - 1 ) ;
unsigned int V_15 = V_10 -> V_16 - * V_5 ;
if ( V_15 > V_2 - V_8 ) {
V_15 = V_2 - V_8 ;
* V_5 += V_15 ;
} else {
* V_5 = 0 ;
V_10 = F_3 ( V_10 ) ;
}
while ( V_15 > 0 ) {
unsigned int V_17 = F_4 ( V_15 , ( unsigned int )
V_14 - V_13 ) ;
unsigned char * V_18 = F_5 ( V_11 ) ;
if ( V_7 == V_19 )
memcpy ( V_18 + V_13 , V_1 + V_8 , V_17 ) ;
else
memcpy ( V_1 + V_8 , V_18 + V_13 , V_17 ) ;
F_6 ( V_11 ) ;
V_13 = 0 ;
++ V_11 ;
V_8 += V_17 ;
V_15 -= V_17 ;
}
}
* V_4 = V_10 ;
return V_8 ;
}
static unsigned int F_7 ( unsigned char * V_1 ,
unsigned int V_2 , struct V_20 * V_21 ,
struct V_9 * * V_4 ,
unsigned int * V_5 , enum V_6 V_7 )
{
return F_1 ( V_1 , V_2 , ( void * ) F_8 ( V_21 ) ,
( void * * ) V_4 , V_5 , V_7 ) ;
}
void F_9 ( unsigned char * V_1 ,
unsigned int V_2 , struct V_20 * V_21 )
{
unsigned int V_5 = 0 ;
struct V_9 * V_10 = NULL ;
V_2 = F_4 ( V_2 , F_10 ( V_21 ) ) ;
V_2 = F_7 ( V_1 , V_2 , V_21 , & V_10 , & V_5 ,
V_19 ) ;
if ( V_2 < F_10 ( V_21 ) )
F_11 ( V_21 , F_10 ( V_21 ) - V_2 ) ;
}
void F_12 ( unsigned char * V_1 ,
unsigned int V_2 , struct V_20 * V_21 )
{
unsigned int V_5 = 0 ;
struct V_9 * V_10 = NULL ;
V_2 = F_4 ( V_2 , F_10 ( V_21 ) ) ;
V_2 = F_7 ( V_1 , V_2 , V_21 , & V_10 , & V_5 ,
V_22 ) ;
if ( V_2 < F_10 ( V_21 ) )
F_11 ( V_21 , F_10 ( V_21 ) - V_2 ) ;
}
static void F_13 ( struct V_23 * V_23 )
{
struct V_24 * V_25 = V_23 -> V_26 ;
if ( V_25 )
F_14 ( V_25 ) ;
}
static int F_15 ( struct V_27 * V_28 , struct V_23 * V_23 ,
int V_29 )
{
struct V_30 * V_31 = V_28 -> V_32 ;
struct V_24 V_33 ;
long V_34 ;
int V_35 ;
if ( F_16 ( V_36 , & V_31 -> V_37 ) )
F_17 ( V_28 , - V_38 ) ;
F_18 ( & V_33 ) ;
V_23 -> V_26 = & V_33 ;
V_23 -> V_39 = 0 ;
V_23 -> V_40 = 0 ;
V_23 -> V_35 = 0 ;
V_23 -> V_41 = V_42 ;
if ( V_23 -> V_43 == V_31 -> V_44 ) {
V_23 -> V_41 |= V_45 ;
V_23 -> V_46 = V_31 -> V_47 ;
}
V_23 -> V_48 = V_31 -> V_49 ;
V_35 = F_19 ( V_23 , V_50 ) ;
if ( V_35 ) {
F_17 ( V_28 , V_35 ) ;
}
F_20 ( V_51 , & V_31 -> V_37 ) ;
if ( F_16 ( V_36 , & V_31 -> V_37 ) ) {
if ( F_21 ( V_51 , & V_31 -> V_37 ) ) {
F_22 ( L_1 ) ;
F_23 ( V_23 ) ;
}
}
V_34 =
F_24 ( & V_33 ,
( V_29 * V_52 /
1000 ) ? :
V_53 ) ;
F_25 ( V_51 , & V_31 -> V_37 ) ;
if ( V_34 <= 0 ) {
F_22 ( L_2 ,
V_34 == 0 ? L_3 : L_4 ) ;
F_26 ( V_23 ) ;
if ( V_34 == 0 )
V_35 = - V_54 ;
else
V_35 = - V_55 ;
} else {
V_35 = V_23 -> V_35 ;
}
return V_35 ;
}
static int F_27 ( struct V_27 * V_28 , unsigned int V_56 ,
unsigned int V_16 , int V_57 ,
unsigned int V_58 )
{
int V_59 = V_60 ;
switch ( V_57 ) {
case 0 :
if ( V_58 != V_16 ) {
F_22 ( L_5 ) ;
F_17 ( V_28 , V_61 ) ;
}
return V_60 ;
case - V_62 :
if ( F_28 ( V_56 ) ) {
F_22 ( L_6 ) ;
F_17 ( V_28 , V_63 ) ;
}
F_22 ( L_7 , V_56 ) ;
if ( F_29 ( V_28 , V_56 ) < 0 )
F_17 ( V_28 , V_64 ) ;
V_59 = V_63 ;
F_30 ( V_28 , Exit ) ;
case - V_65 :
F_22 ( L_8 ) ;
V_59 = V_66 ;
F_30 ( V_28 , Exit ) ;
case - V_67 :
F_22 ( L_9 ) ;
V_59 = V_64 ;
F_30 ( V_28 , Exit ) ;
case - V_68 :
F_22 ( L_10 ) ;
V_59 = V_61 ;
F_30 ( V_28 , Exit ) ;
case - V_38 :
F_22 ( L_11 ) ;
V_59 = V_64 ;
F_30 ( V_28 , Exit ) ;
case - V_54 :
F_22 ( L_12 ) ;
V_59 = V_69 ;
F_30 ( V_28 , Exit ) ;
default:
F_22 ( L_13 ) ;
V_59 = V_64 ;
F_30 ( V_28 , Exit ) ;
}
Exit:
if ( ( V_59 != V_60 ) && ! F_28 ( V_56 ) )
F_31 ( V_28 ) ;
return V_59 ;
}
int F_32 ( struct V_27 * V_28 , unsigned int V_56 ,
T_1 V_70 , T_1 V_71 , T_2 V_72 , T_2 V_73 ,
void * V_74 , T_2 V_75 , int V_29 )
{
struct V_30 * V_31 = V_28 -> V_32 ;
int V_57 ;
F_22 ( L_14 ,
V_76 , V_70 , V_71 , V_72 , V_73 , V_75 ) ;
V_31 -> V_77 -> V_78 = V_71 ;
V_31 -> V_77 -> V_79 = V_70 ;
V_31 -> V_77 -> V_80 = F_33 ( V_72 ) ;
V_31 -> V_77 -> V_81 = F_33 ( V_73 ) ;
V_31 -> V_77 -> V_82 = F_33 ( V_75 ) ;
F_34 ( V_31 -> V_83 , V_31 -> V_84 , V_56 ,
( unsigned char * ) V_31 -> V_77 , V_74 , V_75 ,
F_13 , NULL ) ;
V_57 = F_15 ( V_28 , V_31 -> V_83 , V_29 ) ;
return F_27 ( V_28 , V_56 , V_75 , V_57 ,
V_31 -> V_83 -> V_39 ) ;
}
static int F_29 ( struct V_27 * V_28 , unsigned int V_56 )
{
int V_57 ;
int V_85 = F_35 ( V_56 ) ;
if ( F_36 ( V_56 ) )
V_85 |= V_86 ;
V_57 = F_32 ( V_28 , F_37 ( V_28 ) ,
V_87 , V_88 ,
V_89 , V_85 , NULL , 0 , 3000 ) ;
if ( V_57 != V_60 )
F_17 ( V_28 , V_90 ) ;
F_38 ( V_28 -> V_32 -> V_84 , V_85 ) ;
return V_60 ;
}
static void F_39 ( struct V_91 * V_92 )
{
if ( V_92 -> V_93 ) {
while ( V_92 -> V_94 -- )
F_40 ( V_92 -> V_93 [ V_92 -> V_94 ] ) ;
F_41 ( V_92 -> V_93 ) ;
V_92 -> V_93 = NULL ;
}
V_92 -> V_95 = NULL ;
}
static int F_42 ( struct V_91 * V_92 , struct V_96 * V_95 ,
unsigned V_56 , unsigned V_97 , struct V_9 * V_10 ,
int V_98 , T_3 V_16 , T_4 V_99 )
{
return F_43 ( V_92 , V_95 , V_56 , V_97 , V_10 , V_98 , V_16 , V_99 ) ;
}
static int F_44 ( struct V_91 * V_92 , int V_29 )
{
long V_34 ;
int V_100 ;
int V_94 = V_92 -> V_94 ;
F_45 ( & V_92 -> V_101 ) ;
V_100 = 0 ;
while ( V_100 < V_94 && ! V_92 -> V_35 ) {
int V_59 ;
V_92 -> V_93 [ V_100 ] -> V_95 = V_92 -> V_95 ;
V_59 = F_19 ( V_92 -> V_93 [ V_100 ] , V_102 ) ;
F_46 ( & V_92 -> V_101 ) ;
switch ( V_59 ) {
case - V_103 :
case - V_104 :
case - V_105 :
V_92 -> V_93 [ V_100 ] -> V_95 = NULL ;
V_59 = 0 ;
F_47 () ;
break;
case 0 :
++ V_100 ;
F_48 () ;
break;
default:
V_92 -> V_93 [ V_100 ] -> V_95 = NULL ;
V_92 -> V_93 [ V_100 ] -> V_35 = V_59 ;
F_49 ( & V_92 -> V_95 -> V_95 , L_15 ,
V_76 , V_59 ) ;
F_50 ( V_92 ) ;
}
F_45 ( & V_92 -> V_101 ) ;
if ( V_59 && ( V_92 -> V_35 == 0 || V_92 -> V_35 == - V_67 ) )
V_92 -> V_35 = V_59 ;
}
V_92 -> V_106 -= V_94 - V_100 ;
if ( V_92 -> V_106 == 0 )
F_14 ( & V_92 -> F_14 ) ;
F_46 ( & V_92 -> V_101 ) ;
V_34 =
F_24 ( & V_92 -> F_14 ,
( V_29 * V_52 /
1000 ) ? :
V_53 ) ;
if ( V_34 <= 0 ) {
F_22 ( L_16 ,
V_34 == 0 ? L_3 : L_4 ) ;
F_50 ( V_92 ) ;
if ( V_34 == 0 )
V_92 -> V_35 = - V_54 ;
else
V_92 -> V_35 = - V_55 ;
}
F_39 ( V_92 ) ;
return V_92 -> V_35 ;
}
static int F_51 ( struct V_27 * V_28 ,
unsigned int V_56 ,
struct V_9 * V_10 , int V_107 ,
unsigned int V_16 ,
unsigned int * V_108 , int V_29 )
{
int V_57 ;
if ( F_16 ( V_36 , & V_28 -> V_32 -> V_37 ) )
F_17 ( V_28 , V_64 ) ;
F_22 ( L_17 , V_76 ,
V_16 , V_107 ) ;
V_57 =
F_42 ( & V_28 -> V_32 -> V_109 , V_28 -> V_32 -> V_84 , V_56 , 0 ,
V_10 , V_107 , V_16 , V_50 ) ;
if ( V_57 ) {
F_22 ( L_18 , V_57 ) ;
F_17 ( V_28 , V_64 ) ;
}
F_20 ( V_110 , & V_28 -> V_32 -> V_37 ) ;
if ( F_16 ( V_36 , & V_28 -> V_32 -> V_37 ) ) {
if ( F_21 ( V_110 , & V_28 -> V_32 -> V_37 ) ) {
F_22 ( L_19 ) ;
F_50 ( & V_28 -> V_32 -> V_109 ) ;
}
}
V_57 = F_44 ( & V_28 -> V_32 -> V_109 , V_29 ) ;
F_25 ( V_110 , & V_28 -> V_32 -> V_37 ) ;
if ( V_108 )
* V_108 = V_28 -> V_32 -> V_109 . V_111 ;
return F_27 ( V_28 , V_56 , V_16 , V_57 ,
V_28 -> V_32 -> V_109 . V_111 ) ;
}
static int F_52 ( struct V_27 * V_28 ,
unsigned int V_56 ,
void * V_112 , unsigned int V_16 ,
unsigned int * V_108 , int V_29 )
{
int V_57 ;
F_53 ( V_28 -> V_32 -> V_83 , V_28 -> V_32 -> V_84 , V_56 ,
V_112 , V_16 , F_13 , NULL ) ;
V_57 = F_15 ( V_28 , V_28 -> V_32 -> V_83 , V_29 ) ;
if ( V_108 )
* V_108 = V_28 -> V_32 -> V_83 -> V_39 ;
return F_27 ( V_28 , V_56 , V_16 , V_57 ,
V_28 -> V_32 -> V_83 -> V_39 ) ;
}
int F_54 ( struct V_27 * V_28 , unsigned int V_56 ,
void * V_112 , unsigned int V_113 , int V_114 ,
unsigned int * V_108 , int V_29 )
{
int V_57 ;
if ( V_29 < 600 )
V_29 = 600 ;
if ( V_114 ) {
V_57 =
F_51 ( V_28 , V_56 ,
(struct V_9 * ) V_112 ,
V_114 , V_113 , V_108 , V_29 ) ;
} else {
V_57 =
F_52 ( V_28 , V_56 , V_112 , V_113 , V_108 ,
V_29 ) ;
}
return V_57 ;
}
int F_55 ( struct V_27 * V_28 , unsigned int V_56 ,
void * V_112 , void * * V_18 , unsigned int * V_5 ,
unsigned int V_113 , int V_114 ,
unsigned int * V_108 , int V_29 )
{
int V_57 ;
if ( V_29 < 600 )
V_29 = 600 ;
if ( V_114 ) {
void * V_115 = F_56 ( V_113 , V_116 ) ;
if ( ! V_115 )
F_17 ( V_28 , V_117 ) ;
if ( F_57 ( V_56 ) ) {
F_1 ( V_115 , V_113 , V_112 , V_18 , V_5 ,
V_22 ) ;
}
V_57 =
F_52 ( V_28 , V_56 , V_115 , V_113 , V_108 ,
V_29 ) ;
if ( V_57 == V_60 ) {
if ( F_36 ( V_56 ) ) {
F_1 ( V_115 , V_113 , V_112 , V_18 ,
V_5 , V_19 ) ;
}
}
F_41 ( V_115 ) ;
} else {
unsigned int V_118 = 0 ;
if ( V_5 )
V_118 = * V_5 ;
V_57 =
F_52 ( V_28 , V_56 , V_112 + V_118 , V_113 ,
V_108 , V_29 ) ;
if ( V_108 )
V_118 += * V_108 ;
else
V_118 += V_113 ;
if ( V_5 )
* V_5 = V_118 ;
}
return V_57 ;
}
int F_58 ( struct V_27 * V_28 , T_2 * V_35 )
{
unsigned int V_56 = F_59 ( V_28 ) ;
struct V_119 * V_120 ;
struct V_24 V_33 ;
int V_57 ;
if ( ! V_35 )
F_17 ( V_28 , V_64 ) ;
F_18 ( & V_33 ) ;
V_120 = V_28 -> V_32 -> V_84 -> V_121 [ F_35 ( V_56 ) ] ;
F_60 ( V_28 -> V_32 -> V_122 , V_28 -> V_32 -> V_84 , V_56 ,
V_35 , 2 , F_13 , & V_33 , 10 ) ;
V_57 = F_15 ( V_28 , V_28 -> V_32 -> V_122 , 100 ) ;
return F_27 ( V_28 , V_56 , 2 , V_57 ,
V_28 -> V_32 -> V_122 -> V_39 ) ;
}
void F_61 ( struct V_20 * V_21 , struct V_27 * V_28 )
{
int V_57 ;
#ifdef F_62
if ( V_28 -> V_123 . V_124 ) {
if ( V_21 -> V_125 [ 0 ] == V_126 ) {
if ( F_63 ( V_28 , V_127 ) ) {
if ( F_64 ( V_28 ,
F_65 ( V_21 ) ) ) {
V_21 -> V_57 = V_128 ;
} else {
V_21 -> V_57 = V_129 ;
memcpy ( V_21 -> V_130 ,
V_131 , V_132 ) ;
}
return;
}
} else if ( V_21 -> V_125 [ 0 ] == V_133 ) {
if ( F_63 ( V_28 , V_127 ) ) {
int V_134 = V_21 -> V_125 [ 4 ] & 0x1 ;
if ( V_134 ) {
V_21 -> V_57 = V_129 ;
memcpy ( V_21 -> V_130 ,
V_135 , V_132 ) ;
} else {
V_21 -> V_57 = V_128 ;
}
return;
}
} else {
if ( F_63 ( V_28 , V_127 )
|| F_63 ( V_28 , V_136 ) ) {
F_22 ( L_20 ) ;
V_28 -> V_137 = 1 ;
F_66 ( V_28 ) ;
if ( F_63 ( V_28 , V_127 ) ) {
F_67 ( 3000 ) ;
F_68 ( V_28 ) ;
F_69 ( V_28 ) ;
}
}
}
}
#endif
V_57 = F_70 ( V_21 , V_28 ) ;
if ( V_57 == V_138 ) {
F_22 ( L_21 ) ;
V_21 -> V_57 = V_139 << 16 ;
goto V_140;
}
V_21 -> V_57 = V_128 ;
if ( V_57 == V_141 ) {
V_21 -> V_57 = V_129 ;
memcpy ( V_21 -> V_130 ,
( unsigned char * ) & ( V_28 -> V_130 [ F_65 ( V_21 ) ] ) ,
sizeof( struct V_142 ) ) ;
}
return;
V_140:
return;
}
