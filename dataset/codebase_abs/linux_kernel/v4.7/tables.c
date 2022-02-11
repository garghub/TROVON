void F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
switch ( V_2 -> type ) {
case V_3 :
{
struct V_4 * V_5 =
(struct V_4 * ) V_2 ;
F_2 ( L_1 ,
V_5 -> V_6 , V_5 -> V_7 ,
( V_5 -> V_8 & V_9 ) ? L_2 : L_3 ) ;
}
break;
case V_10 :
{
struct V_11 * V_5 =
(struct V_11 * ) V_2 ;
F_2 ( L_4 ,
V_5 -> V_12 , V_5 -> V_13 ,
( V_5 -> V_8 & V_9 ) ? L_2 : L_3 ) ;
}
break;
case V_14 :
{
struct V_15 * V_5 =
(struct V_15 * ) V_2 ;
F_2 ( L_5 ,
V_5 -> V_7 , V_5 -> V_16 , V_5 -> V_17 ) ;
}
break;
case V_18 :
{
struct V_19 * V_5 =
(struct V_19 * ) V_2 ;
F_3 ( L_6 ,
V_5 -> V_20 , V_5 -> V_21 , V_5 -> V_22 ,
V_23 [ V_5 -> V_24 & V_25 ] ,
V_26 [ ( V_5 -> V_24 & V_27 ) >> 2 ] ) ;
if ( V_5 -> V_24 &
~ ( V_25 | V_27 ) )
F_3 ( L_7 ,
V_5 -> V_24 &
~ ( V_25 | V_27 ) ) ;
}
break;
case V_28 :
{
struct V_29 * V_5 =
(struct V_29 * ) V_2 ;
F_3 ( L_8 ,
V_23 [ V_5 -> V_24 & V_25 ] ,
V_26 [ ( V_5 -> V_24 & V_27 ) >> 2 ] ,
V_5 -> V_22 ) ;
}
break;
case V_30 :
{
struct V_31 * V_5 =
(struct V_31 * ) V_2 ;
F_3 ( L_9 ,
V_5 -> V_6 ,
V_23 [ V_5 -> V_24 & V_25 ] ,
V_26 [ ( V_5 -> V_24 & V_27 ) >> 2 ] ,
V_5 -> V_32 ) ;
}
break;
case V_33 :
{
T_1 V_34 , V_35 ;
struct V_36 * V_5 =
(struct V_36 * ) V_2 ;
V_34 = V_5 -> V_24 & V_25 ;
V_35 = ( V_5 -> V_24 & V_27 ) >> 2 ;
F_3 ( L_10 ,
V_5 -> V_13 ,
V_23 [ V_34 ] ,
V_26 [ V_35 ] ,
V_5 -> V_32 ) ;
}
break;
case V_37 :
{
struct V_38 * V_5 =
(struct V_38 * ) V_2 ;
F_3 ( L_11 ,
( void * ) ( unsigned long ) V_5 -> V_16 ) ;
}
break;
case V_39 :
{
struct V_40 * V_5 =
(struct V_40 * ) V_2 ;
F_2 ( L_12 ,
V_5 -> V_7 , ( void * ) ( unsigned long ) V_5 -> V_16 ,
V_5 -> V_17 ) ;
}
break;
case V_41 :
{
struct V_42 * V_5 =
(struct V_42 * ) V_2 ;
F_2 ( L_13 ,
V_5 -> V_6 , V_5 -> V_7 , V_5 -> V_43 ,
( V_5 -> V_8 & V_9 ) ? L_2 : L_3 ) ;
}
break;
case V_44 :
{
struct V_45 * V_5 =
(struct V_45 * ) V_2 ;
F_3 ( L_14 ,
V_23 [ V_5 -> V_24 & V_25 ] ,
V_26 [ ( V_5 -> V_24 & V_27 ) >> 2 ] ,
V_5 -> type , V_5 -> V_7 , V_5 -> V_43 , V_5 -> V_46 ,
V_5 -> V_22 ) ;
}
break;
case V_47 :
{
struct V_48 * V_5 =
(struct V_48 * ) V_2 ;
F_2 ( L_15 ,
V_5 -> V_13 , V_5 -> V_49 ,
V_5 -> V_50 ,
( V_5 -> V_51 & V_9 ) ? L_2 : L_3 ) ;
}
break;
case V_52 :
{
struct V_53 * V_5 =
(struct V_53 * ) V_2 ;
F_2 ( L_16 ,
V_5 -> V_54 , V_5 -> V_49 ,
V_5 -> V_17 ) ;
}
break;
default:
F_4 ( L_17 ,
V_2 -> type ) ;
break;
}
}
static int T_2
F_5 ( char * V_7 , unsigned long V_55 ,
struct V_56 * V_57 ,
struct V_58 * V_59 , int V_60 ,
unsigned int V_61 )
{
struct V_1 * V_62 ;
unsigned long V_63 ;
int V_64 = 0 ;
int V_65 ;
if ( V_66 )
return - V_67 ;
if ( ! V_7 )
return - V_68 ;
if ( ! V_55 )
return - V_68 ;
if ( ! V_57 ) {
F_4 ( L_18 , V_7 ) ;
return - V_67 ;
}
V_63 = ( unsigned long ) V_57 + V_57 -> V_69 ;
V_62 = (struct V_1 * )
( ( unsigned long ) V_57 + V_55 ) ;
while ( ( ( unsigned long ) V_62 ) + sizeof( struct V_1 ) <
V_63 ) {
if ( V_61 && V_64 >= V_61 )
break;
for ( V_65 = 0 ; V_65 < V_60 ; V_65 ++ ) {
if ( V_62 -> type != V_59 [ V_65 ] . V_7 )
continue;
if ( ! V_59 [ V_65 ] . V_70 ||
V_59 [ V_65 ] . V_70 ( V_62 , V_63 ) )
return - V_68 ;
V_59 -> V_64 ++ ;
break;
}
if ( V_65 != V_60 )
V_64 ++ ;
if ( V_62 -> V_69 == 0 ) {
F_6 ( L_19 , V_7 , V_59 -> V_7 ) ;
return - V_68 ;
}
V_62 = (struct V_1 * )
( ( unsigned long ) V_62 + V_62 -> V_69 ) ;
}
if ( V_61 && V_64 > V_61 ) {
F_4 ( L_20 ,
V_7 , V_59 -> V_7 , V_64 - V_61 , V_64 ) ;
}
return V_64 ;
}
int T_2
F_7 ( char * V_7 ,
unsigned long V_55 ,
T_3 V_70 ,
struct V_56 * V_57 ,
int V_71 , unsigned int V_61 )
{
struct V_58 V_59 = {
. V_7 = V_71 ,
. V_70 = V_70 ,
} ;
return F_5 ( V_7 , V_55 , V_57 ,
& V_59 , 1 , V_61 ) ;
}
int T_2
F_8 ( char * V_7 ,
unsigned long V_55 ,
struct V_58 * V_59 , int V_60 ,
unsigned int V_61 )
{
struct V_56 * V_57 = NULL ;
T_4 V_72 ;
int V_64 ;
T_5 V_73 = 0 ;
if ( V_66 )
return - V_67 ;
if ( ! V_7 )
return - V_68 ;
if ( ! strncmp ( V_7 , V_74 , 4 ) )
V_73 = V_75 ;
F_9 ( V_7 , V_73 , & V_57 , & V_72 ) ;
if ( ! V_57 ) {
F_4 ( L_18 , V_7 ) ;
return - V_67 ;
}
V_64 = F_5 ( V_7 , V_55 , V_57 ,
V_59 , V_60 , V_61 ) ;
F_10 ( ( char * ) V_57 , V_72 ) ;
return V_64 ;
}
int T_2
F_11 ( char * V_7 ,
unsigned long V_55 ,
int V_71 ,
T_3 V_70 ,
unsigned int V_61 )
{
struct V_58 V_59 = {
. V_7 = V_71 ,
. V_70 = V_70 ,
} ;
return F_8 ( V_7 , V_55 , & V_59 , 1 ,
V_61 ) ;
}
int T_2
F_12 ( enum V_76 V_7 ,
T_3 V_70 , unsigned int V_61 )
{
return F_11 ( V_74 ,
sizeof( struct V_77 ) , V_7 ,
V_70 , V_61 ) ;
}
int T_2 F_13 ( char * V_7 , T_6 V_70 )
{
struct V_56 * V_78 = NULL ;
T_4 V_72 ;
if ( V_66 )
return - V_67 ;
if ( ! V_7 || ! V_70 )
return - V_68 ;
if ( strncmp ( V_7 , V_74 , 4 ) == 0 )
F_9 ( V_7 , V_75 , & V_78 , & V_72 ) ;
else
F_9 ( V_7 , 0 , & V_78 , & V_72 ) ;
if ( V_78 ) {
V_70 ( V_78 ) ;
F_10 ( V_78 , V_72 ) ;
return 0 ;
} else
return - V_67 ;
}
static void T_2 F_14 ( void )
{
struct V_56 * V_78 = NULL ;
T_4 V_72 ;
F_9 ( V_74 , 2 , & V_78 , & V_72 ) ;
if ( V_78 ) {
F_4 ( L_21 ,
V_75 ) ;
F_4 ( L_22
L_23 ,
V_75 ? 0 : 2 ) ;
F_10 ( V_78 , V_72 ) ;
} else
V_75 = 0 ;
return;
}
static void F_15 ( struct V_56 * V_78 )
{
F_4 ( L_24 ,
V_78 -> V_79 , V_78 -> V_80 ) ;
F_16 ( V_81 , V_82 ) ;
}
static T_7 T_2 F_17 ( T_7 * V_83 , T_5 V_69 )
{
T_7 V_84 = 0 ;
T_7 * V_85 = V_83 + V_69 ;
while ( V_83 < V_85 )
V_84 = ( T_7 ) ( V_84 + * ( V_83 ++ ) ) ;
return V_84 ;
}
static void T_2 F_18 ( void * V_86 , T_8 V_87 )
{
int V_88 , V_89 , V_90 = 0 , V_91 = 0 ;
long V_92 = 0 ;
struct V_56 * V_78 ;
char V_93 [ 32 ] = L_25 ;
struct V_94 V_95 ;
if ( V_86 == NULL || V_87 == 0 )
return;
for ( V_89 = 0 ; V_89 < V_96 ; V_89 ++ ) {
V_95 = F_19 ( V_93 , V_86 , V_87 , & V_92 ) ;
if ( ! V_95 . V_86 )
break;
V_86 += V_92 ;
V_87 -= V_92 ;
if ( V_95 . V_87 < sizeof( struct V_56 ) ) {
F_6 ( L_26 ,
V_93 , V_95 . V_97 ) ;
continue;
}
V_78 = V_95 . V_86 ;
for ( V_88 = 0 ; V_98 [ V_88 ] ; V_88 ++ )
if ( ! memcmp ( V_78 -> V_79 , V_98 [ V_88 ] , 4 ) )
break;
if ( ! V_98 [ V_88 ] ) {
F_6 ( L_27 ,
V_93 , V_95 . V_97 ) ;
continue;
}
if ( V_95 . V_87 != V_78 -> V_69 ) {
F_6 ( L_28 ,
V_93 , V_95 . V_97 ) ;
continue;
}
if ( F_17 ( V_95 . V_86 , V_78 -> V_69 ) ) {
F_6 ( L_29 ,
V_93 , V_95 . V_97 ) ;
continue;
}
F_3 ( L_30 ,
V_78 -> V_79 , V_93 , V_95 . V_97 , V_78 -> V_69 ) ;
V_99 += V_78 -> V_69 ;
V_100 [ V_90 ] . V_86 = V_95 . V_86 ;
V_100 [ V_90 ] . V_87 = V_95 . V_87 ;
V_90 ++ ;
}
if ( V_90 == 0 )
return;
V_101 =
F_20 ( 0 , V_102 << V_103 ,
V_99 , V_104 ) ;
if ( ! V_101 ) {
F_21 ( 1 ) ;
return;
}
F_22 ( V_101 , V_99 ) ;
F_23 ( V_101 , V_99 ) ;
for ( V_89 = 0 ; V_89 < V_90 ; V_89 ++ ) {
unsigned char * V_105 = V_100 [ V_89 ] . V_86 ;
T_9 V_87 = V_100 [ V_89 ] . V_87 ;
T_9 V_106 = V_101 + V_91 ;
T_9 V_107 , V_108 ;
char * V_109 ;
V_91 += V_87 ;
while ( V_87 ) {
V_107 = V_106 & ~ V_110 ;
V_108 = V_87 ;
if ( V_108 > V_111 - V_107 )
V_108 = V_111 - V_107 ;
V_109 = F_24 ( V_106 & V_110 ,
V_108 + V_107 ) ;
memcpy ( V_109 + V_107 , V_105 , V_108 ) ;
F_25 ( V_109 , V_108 + V_107 ) ;
V_105 += V_108 ;
V_106 += V_108 ;
V_87 -= V_108 ;
}
}
}
static T_10
F_26 ( struct V_56 * V_112 ,
T_11 * V_16 , T_5 * V_69 )
{
int V_113 = 0 ;
int V_114 = 0 ;
struct V_56 * V_78 ;
T_5 V_115 ;
* V_69 = 0 ;
* V_16 = 0 ;
if ( ! V_101 )
return V_116 ;
while ( V_113 + V_117 <= V_99 ) {
V_78 = F_27 ( V_101 + V_113 ,
V_117 ) ;
if ( V_113 + V_78 -> V_69 > V_99 ) {
F_28 ( V_78 , V_117 ) ;
F_21 ( 1 ) ;
return V_116 ;
}
V_115 = V_78 -> V_69 ;
if ( memcmp ( V_112 -> V_79 , V_78 -> V_79 , 4 ) ||
memcmp ( V_78 -> V_118 , V_112 -> V_118 ,
V_119 ) ||
memcmp ( V_78 -> V_80 , V_112 -> V_80 ,
V_120 ) ) {
F_28 ( V_78 , V_117 ) ;
goto V_121;
}
if ( F_29 ( V_114 , V_122 ) ||
V_112 -> V_123 >= V_78 -> V_123 ) {
F_28 ( V_78 , V_117 ) ;
goto V_121;
}
* V_69 = V_115 ;
* V_16 = V_101 + V_113 ;
F_3 ( L_31 ,
V_78 -> V_79 , V_78 -> V_118 ,
V_78 -> V_80 ) ;
F_28 ( V_78 , V_117 ) ;
break;
V_121:
V_113 += V_115 ;
V_114 ++ ;
}
return V_116 ;
}
static void T_2 F_30 ( void )
{
int V_113 = 0 ;
int V_114 = 0 ;
T_5 V_115 ;
struct V_56 * V_78 ;
if ( ! V_101 )
return;
while ( V_113 + V_117 <= V_99 ) {
V_78 = F_27 ( V_101 + V_113 ,
V_117 ) ;
if ( V_113 + V_78 -> V_69 > V_99 ) {
F_28 ( V_78 , V_117 ) ;
F_21 ( 1 ) ;
return;
}
V_115 = V_78 -> V_69 ;
if ( F_31 ( V_78 -> V_79 , V_124 ) ||
F_31 ( V_78 -> V_79 , V_125 ) ) {
F_28 ( V_78 , V_117 ) ;
goto V_121;
}
if ( F_29 ( V_114 , V_122 ) ) {
F_28 ( V_78 , V_117 ) ;
goto V_121;
}
F_3 ( L_32 ,
V_78 -> V_79 , V_78 -> V_118 ,
V_78 -> V_80 ) ;
F_28 ( V_78 , V_117 ) ;
F_32 ( V_101 + V_113 , TRUE ) ;
V_121:
V_113 += V_115 ;
V_114 ++ ;
}
}
static void T_2 F_18 ( void * V_86 , T_8 V_87 )
{
}
static T_10
F_26 ( struct V_56 * V_112 ,
T_11 * V_16 ,
T_5 * V_115 )
{
* V_115 = 0 ;
* V_16 = 0 ;
return V_116 ;
}
static void T_2 F_30 ( void )
{
}
T_10
F_33 ( struct V_56 * V_112 ,
T_11 * V_16 ,
T_5 * V_115 )
{
return F_26 ( V_112 , V_16 ,
V_115 ) ;
}
T_10
F_34 ( struct V_56 * V_112 ,
struct V_56 * * V_126 )
{
if ( ! V_112 || ! V_126 )
return V_127 ;
* V_126 = NULL ;
#ifdef F_35
if ( strncmp ( V_112 -> V_79 , L_33 , 4 ) == 0 )
* V_126 = (struct V_56 * ) V_128 ;
#endif
if ( * V_126 != NULL )
F_15 ( V_112 ) ;
return V_116 ;
}
void T_2 F_36 ( void * V_86 , T_8 V_87 )
{
F_18 ( V_86 , V_87 ) ;
}
int T_2 F_37 ( void )
{
T_10 V_129 ;
if ( V_130 ) {
F_3 ( L_34 ) ;
V_131 = TRUE ;
} else {
F_3 ( L_35 ) ;
V_131 = FALSE ;
}
V_129 = F_38 ( V_132 , V_133 , 0 ) ;
if ( F_39 ( V_129 ) )
return - V_68 ;
F_30 () ;
F_14 () ;
return 0 ;
}
static int T_2 F_40 ( char * V_134 )
{
if ( ! V_134 )
return - V_68 ;
if ( F_41 ( V_134 , 0 , & V_75 ) )
return - V_68 ;
F_42 ( L_36 , V_75 ) ;
return 0 ;
}
static int T_2 F_43 ( char * V_135 )
{
V_130 = true ;
return 0 ;
}
static int T_2 F_44 ( char * V_135 )
{
F_3 ( L_37 ) ;
V_136 = TRUE ;
return 0 ;
}
