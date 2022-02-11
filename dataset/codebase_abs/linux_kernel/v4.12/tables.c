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
int V_65 = 0 ;
int V_66 ;
if ( V_67 )
return - V_68 ;
if ( ! V_7 )
return - V_69 ;
if ( ! V_55 )
return - V_69 ;
if ( ! V_57 ) {
F_4 ( L_18 , V_7 ) ;
return - V_68 ;
}
V_63 = ( unsigned long ) V_57 + V_57 -> V_70 ;
V_62 = (struct V_1 * )
( ( unsigned long ) V_57 + V_55 ) ;
while ( ( ( unsigned long ) V_62 ) + sizeof( struct V_1 ) <
V_63 ) {
if ( V_61 && V_64 >= V_61 )
break;
for ( V_66 = 0 ; V_66 < V_60 ; V_66 ++ ) {
if ( V_62 -> type != V_59 [ V_66 ] . V_7 )
continue;
if ( ! V_59 [ V_66 ] . V_71 ||
( ! V_65 && V_59 [ V_66 ] . V_71 ( V_62 , V_63 ) ) ) {
V_65 ++ ;
continue;
}
V_59 [ V_66 ] . V_64 ++ ;
break;
}
if ( V_66 != V_60 )
V_64 ++ ;
if ( V_62 -> V_70 == 0 ) {
F_6 ( L_19 , V_7 , V_59 -> V_7 ) ;
return - V_69 ;
}
V_62 = (struct V_1 * )
( ( unsigned long ) V_62 + V_62 -> V_70 ) ;
}
if ( V_61 && V_64 > V_61 ) {
F_4 ( L_20 ,
V_7 , V_59 -> V_7 , V_64 ) ;
}
return V_65 ? - V_69 : V_64 ;
}
int T_2
F_7 ( char * V_7 ,
unsigned long V_55 ,
struct V_58 * V_59 , int V_60 ,
unsigned int V_61 )
{
struct V_56 * V_57 = NULL ;
int V_64 ;
T_3 V_72 = 0 ;
if ( V_67 )
return - V_68 ;
if ( ! V_7 )
return - V_69 ;
if ( ! strncmp ( V_7 , V_73 , 4 ) )
V_72 = V_74 ;
F_8 ( V_7 , V_72 , & V_57 ) ;
if ( ! V_57 ) {
F_4 ( L_18 , V_7 ) ;
return - V_68 ;
}
V_64 = F_5 ( V_7 , V_55 , V_57 ,
V_59 , V_60 , V_61 ) ;
F_9 ( V_57 ) ;
return V_64 ;
}
int T_2
F_10 ( char * V_7 ,
unsigned long V_55 ,
int V_75 ,
T_4 V_71 ,
unsigned int V_61 )
{
struct V_58 V_59 = {
. V_7 = V_75 ,
. V_71 = V_71 ,
} ;
return F_7 ( V_7 , V_55 , & V_59 , 1 ,
V_61 ) ;
}
int T_2
F_11 ( enum V_76 V_7 ,
T_4 V_71 , unsigned int V_61 )
{
return F_10 ( V_73 ,
sizeof( struct V_77 ) , V_7 ,
V_71 , V_61 ) ;
}
int T_2 F_12 ( char * V_7 , T_5 V_71 )
{
struct V_56 * V_78 = NULL ;
if ( V_67 )
return - V_68 ;
if ( ! V_7 || ! V_71 )
return - V_69 ;
if ( strncmp ( V_7 , V_73 , 4 ) == 0 )
F_8 ( V_7 , V_74 , & V_78 ) ;
else
F_8 ( V_7 , 0 , & V_78 ) ;
if ( V_78 ) {
V_71 ( V_78 ) ;
F_9 ( V_78 ) ;
return 0 ;
} else
return - V_68 ;
}
static void T_2 F_13 ( void )
{
struct V_56 * V_78 = NULL ;
F_8 ( V_73 , 2 , & V_78 ) ;
if ( V_78 ) {
F_4 ( L_21 ,
V_74 ) ;
F_4 ( L_22
L_23 ,
V_74 ? 0 : 2 ) ;
F_9 ( V_78 ) ;
} else
V_74 = 0 ;
return;
}
static void F_14 ( struct V_56 * V_78 )
{
F_4 ( L_24 ,
V_78 -> V_79 , V_78 -> V_80 ) ;
F_15 ( V_81 , V_82 ) ;
}
static T_6 T_2 F_16 ( T_6 * V_83 , T_3 V_70 )
{
T_6 V_84 = 0 ;
T_6 * V_85 = V_83 + V_70 ;
while ( V_83 < V_85 )
V_84 = ( T_6 ) ( V_84 + * ( V_83 ++ ) ) ;
return V_84 ;
}
void T_2 F_17 ( void )
{
void * V_86 = ( void * ) V_87 ;
T_7 V_88 = V_89 - V_87 ;
int V_90 , V_91 , V_92 = 0 , V_93 = 0 ;
long V_94 = 0 ;
struct V_56 * V_78 ;
char V_95 [ 32 ] = L_25 ;
struct V_96 V_97 ;
if ( V_86 == NULL || V_88 == 0 )
return;
for ( V_91 = 0 ; V_91 < V_98 ; V_91 ++ ) {
V_97 = F_18 ( V_95 , V_86 , V_88 , & V_94 ) ;
if ( ! V_97 . V_86 )
break;
V_86 += V_94 ;
V_88 -= V_94 ;
if ( V_97 . V_88 < sizeof( struct V_56 ) ) {
F_6 ( L_26 ,
V_95 , V_97 . V_99 ) ;
continue;
}
V_78 = V_97 . V_86 ;
for ( V_90 = 0 ; V_100 [ V_90 ] ; V_90 ++ )
if ( ! memcmp ( V_78 -> V_79 , V_100 [ V_90 ] , 4 ) )
break;
if ( ! V_100 [ V_90 ] ) {
F_6 ( L_27 ,
V_95 , V_97 . V_99 ) ;
continue;
}
if ( V_97 . V_88 != V_78 -> V_70 ) {
F_6 ( L_28 ,
V_95 , V_97 . V_99 ) ;
continue;
}
if ( F_16 ( V_97 . V_86 , V_78 -> V_70 ) ) {
F_6 ( L_29 ,
V_95 , V_97 . V_99 ) ;
continue;
}
F_3 ( L_30 ,
V_78 -> V_79 , V_95 , V_97 . V_99 , V_78 -> V_70 ) ;
V_101 += V_78 -> V_70 ;
V_102 [ V_92 ] . V_86 = V_97 . V_86 ;
V_102 [ V_92 ] . V_88 = V_97 . V_88 ;
V_92 ++ ;
}
if ( V_92 == 0 )
return;
V_103 =
F_19 ( 0 , V_104 ,
V_101 , V_105 ) ;
if ( ! V_103 ) {
F_20 ( 1 ) ;
return;
}
F_21 ( V_103 , V_101 ) ;
F_22 ( V_103 , V_101 ) ;
for ( V_91 = 0 ; V_91 < V_92 ; V_91 ++ ) {
unsigned char * V_106 = V_102 [ V_91 ] . V_86 ;
T_8 V_88 = V_102 [ V_91 ] . V_88 ;
T_8 V_107 = V_103 + V_93 ;
T_8 V_108 , V_109 ;
char * V_110 ;
V_93 += V_88 ;
while ( V_88 ) {
V_108 = V_107 & ~ V_111 ;
V_109 = V_88 ;
if ( V_109 > V_112 - V_108 )
V_109 = V_112 - V_108 ;
V_110 = F_23 ( V_107 & V_111 ,
V_109 + V_108 ) ;
memcpy ( V_110 + V_108 , V_106 , V_109 ) ;
F_24 ( V_110 , V_109 + V_108 ) ;
V_106 += V_109 ;
V_107 += V_109 ;
V_88 -= V_109 ;
}
}
}
static T_9
F_25 ( struct V_56 * V_113 ,
T_10 * V_16 , T_3 * V_70 )
{
int V_114 = 0 ;
int V_115 = 0 ;
struct V_56 * V_78 ;
T_3 V_116 ;
* V_70 = 0 ;
* V_16 = 0 ;
if ( ! V_103 )
return V_117 ;
while ( V_114 + V_118 <= V_101 ) {
V_78 = F_26 ( V_103 + V_114 ,
V_118 ) ;
if ( V_114 + V_78 -> V_70 > V_101 ) {
F_27 ( V_78 , V_118 ) ;
F_20 ( 1 ) ;
return V_117 ;
}
V_116 = V_78 -> V_70 ;
if ( memcmp ( V_113 -> V_79 , V_78 -> V_79 , 4 ) ||
memcmp ( V_78 -> V_119 , V_113 -> V_119 ,
V_120 ) ||
memcmp ( V_78 -> V_80 , V_113 -> V_80 ,
V_121 ) ) {
F_27 ( V_78 , V_118 ) ;
goto V_122;
}
if ( F_28 ( V_115 , V_123 ) ||
V_113 -> V_124 >= V_78 -> V_124 ) {
F_27 ( V_78 , V_118 ) ;
goto V_122;
}
* V_70 = V_116 ;
* V_16 = V_103 + V_114 ;
F_3 ( L_31 ,
V_78 -> V_79 , V_78 -> V_119 ,
V_78 -> V_80 ) ;
F_27 ( V_78 , V_118 ) ;
break;
V_122:
V_114 += V_116 ;
V_115 ++ ;
}
return V_117 ;
}
static void T_2 F_29 ( void )
{
int V_114 = 0 ;
int V_115 = 0 ;
T_3 V_116 ;
struct V_56 * V_78 ;
if ( ! V_103 )
return;
while ( V_114 + V_118 <= V_101 ) {
V_78 = F_26 ( V_103 + V_114 ,
V_118 ) ;
if ( V_114 + V_78 -> V_70 > V_101 ) {
F_27 ( V_78 , V_118 ) ;
F_20 ( 1 ) ;
return;
}
V_116 = V_78 -> V_70 ;
if ( F_30 ( V_78 -> V_79 , V_125 ) ||
F_30 ( V_78 -> V_79 , V_126 ) ) {
F_27 ( V_78 , V_118 ) ;
goto V_122;
}
if ( F_28 ( V_115 , V_123 ) ) {
F_27 ( V_78 , V_118 ) ;
goto V_122;
}
F_3 ( L_32 ,
V_78 -> V_79 , V_78 -> V_119 ,
V_78 -> V_80 ) ;
F_27 ( V_78 , V_118 ) ;
F_31 ( V_103 + V_114 , TRUE ) ;
V_122:
V_114 += V_116 ;
V_115 ++ ;
}
}
static T_9
F_25 ( struct V_56 * V_113 ,
T_10 * V_16 ,
T_3 * V_116 )
{
* V_116 = 0 ;
* V_16 = 0 ;
return V_117 ;
}
static void T_2 F_29 ( void )
{
}
T_9
F_32 ( struct V_56 * V_113 ,
T_10 * V_16 ,
T_3 * V_116 )
{
return F_25 ( V_113 , V_16 ,
V_116 ) ;
}
T_9
F_33 ( struct V_56 * V_113 ,
struct V_56 * * V_127 )
{
if ( ! V_113 || ! V_127 )
return V_128 ;
* V_127 = NULL ;
#ifdef F_34
if ( strncmp ( V_113 -> V_79 , L_33 , 4 ) == 0 )
* V_127 = (struct V_56 * ) V_129 ;
#endif
if ( * V_127 != NULL )
F_14 ( V_113 ) ;
return V_117 ;
}
int T_2 F_35 ( void )
{
T_9 V_130 ;
if ( V_131 ) {
F_3 ( L_34 ) ;
V_132 = TRUE ;
} else {
F_3 ( L_35 ) ;
V_132 = FALSE ;
}
V_130 = F_36 ( V_133 , V_134 , 0 ) ;
if ( F_37 ( V_130 ) )
return - V_69 ;
F_29 () ;
F_13 () ;
return 0 ;
}
static int T_2 F_38 ( char * V_135 )
{
if ( ! V_135 )
return - V_69 ;
if ( F_39 ( V_135 , 0 , & V_74 ) )
return - V_69 ;
F_40 ( L_36 , V_74 ) ;
return 0 ;
}
static int T_2 F_41 ( char * V_136 )
{
V_131 = true ;
return 0 ;
}
static int T_2 F_42 ( char * V_136 )
{
F_3 ( L_37 ) ;
V_137 = TRUE ;
return 0 ;
}
