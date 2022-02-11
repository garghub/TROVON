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
T_3 V_71 ,
struct V_56 * V_57 ,
int V_72 , unsigned int V_61 )
{
struct V_58 V_59 = {
. V_7 = V_72 ,
. V_71 = V_71 ,
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
T_4 V_73 ;
int V_64 ;
T_5 V_74 = 0 ;
if ( V_67 )
return - V_68 ;
if ( ! V_7 )
return - V_69 ;
if ( ! strncmp ( V_7 , V_75 , 4 ) )
V_74 = V_76 ;
F_9 ( V_7 , V_74 , & V_57 , & V_73 ) ;
if ( ! V_57 ) {
F_4 ( L_18 , V_7 ) ;
return - V_68 ;
}
V_64 = F_5 ( V_7 , V_55 , V_57 ,
V_59 , V_60 , V_61 ) ;
F_10 ( ( char * ) V_57 , V_73 ) ;
return V_64 ;
}
int T_2
F_11 ( char * V_7 ,
unsigned long V_55 ,
int V_72 ,
T_3 V_71 ,
unsigned int V_61 )
{
struct V_58 V_59 = {
. V_7 = V_72 ,
. V_71 = V_71 ,
} ;
return F_8 ( V_7 , V_55 , & V_59 , 1 ,
V_61 ) ;
}
int T_2
F_12 ( enum V_77 V_7 ,
T_3 V_71 , unsigned int V_61 )
{
return F_11 ( V_75 ,
sizeof( struct V_78 ) , V_7 ,
V_71 , V_61 ) ;
}
int T_2 F_13 ( char * V_7 , T_6 V_71 )
{
struct V_56 * V_79 = NULL ;
T_4 V_73 ;
if ( V_67 )
return - V_68 ;
if ( ! V_7 || ! V_71 )
return - V_69 ;
if ( strncmp ( V_7 , V_75 , 4 ) == 0 )
F_9 ( V_7 , V_76 , & V_79 , & V_73 ) ;
else
F_9 ( V_7 , 0 , & V_79 , & V_73 ) ;
if ( V_79 ) {
V_71 ( V_79 ) ;
F_10 ( V_79 , V_73 ) ;
return 0 ;
} else
return - V_68 ;
}
static void T_2 F_14 ( void )
{
struct V_56 * V_79 = NULL ;
T_4 V_73 ;
F_9 ( V_75 , 2 , & V_79 , & V_73 ) ;
if ( V_79 ) {
F_4 ( L_21 ,
V_76 ) ;
F_4 ( L_22
L_23 ,
V_76 ? 0 : 2 ) ;
F_10 ( V_79 , V_73 ) ;
} else
V_76 = 0 ;
return;
}
static void F_15 ( struct V_56 * V_79 )
{
F_4 ( L_24 ,
V_79 -> V_80 , V_79 -> V_81 ) ;
F_16 ( V_82 , V_83 ) ;
}
static T_7 T_2 F_17 ( T_7 * V_84 , T_5 V_70 )
{
T_7 V_85 = 0 ;
T_7 * V_86 = V_84 + V_70 ;
while ( V_84 < V_86 )
V_85 = ( T_7 ) ( V_85 + * ( V_84 ++ ) ) ;
return V_85 ;
}
void T_2 F_18 ( void )
{
void * V_87 = ( void * ) V_88 ;
T_8 V_89 = V_90 - V_88 ;
int V_91 , V_92 , V_93 = 0 , V_94 = 0 ;
long V_95 = 0 ;
struct V_56 * V_79 ;
char V_96 [ 32 ] = L_25 ;
struct V_97 V_98 ;
if ( V_87 == NULL || V_89 == 0 )
return;
for ( V_92 = 0 ; V_92 < V_99 ; V_92 ++ ) {
V_98 = F_19 ( V_96 , V_87 , V_89 , & V_95 ) ;
if ( ! V_98 . V_87 )
break;
V_87 += V_95 ;
V_89 -= V_95 ;
if ( V_98 . V_89 < sizeof( struct V_56 ) ) {
F_6 ( L_26 ,
V_96 , V_98 . V_100 ) ;
continue;
}
V_79 = V_98 . V_87 ;
for ( V_91 = 0 ; V_101 [ V_91 ] ; V_91 ++ )
if ( ! memcmp ( V_79 -> V_80 , V_101 [ V_91 ] , 4 ) )
break;
if ( ! V_101 [ V_91 ] ) {
F_6 ( L_27 ,
V_96 , V_98 . V_100 ) ;
continue;
}
if ( V_98 . V_89 != V_79 -> V_70 ) {
F_6 ( L_28 ,
V_96 , V_98 . V_100 ) ;
continue;
}
if ( F_17 ( V_98 . V_87 , V_79 -> V_70 ) ) {
F_6 ( L_29 ,
V_96 , V_98 . V_100 ) ;
continue;
}
F_3 ( L_30 ,
V_79 -> V_80 , V_96 , V_98 . V_100 , V_79 -> V_70 ) ;
V_102 += V_79 -> V_70 ;
V_103 [ V_93 ] . V_87 = V_98 . V_87 ;
V_103 [ V_93 ] . V_89 = V_98 . V_89 ;
V_93 ++ ;
}
if ( V_93 == 0 )
return;
V_104 =
F_20 ( 0 , V_105 ,
V_102 , V_106 ) ;
if ( ! V_104 ) {
F_21 ( 1 ) ;
return;
}
F_22 ( V_104 , V_102 ) ;
F_23 ( V_104 , V_102 ) ;
for ( V_92 = 0 ; V_92 < V_93 ; V_92 ++ ) {
unsigned char * V_107 = V_103 [ V_92 ] . V_87 ;
T_9 V_89 = V_103 [ V_92 ] . V_89 ;
T_9 V_108 = V_104 + V_94 ;
T_9 V_109 , V_110 ;
char * V_111 ;
V_94 += V_89 ;
while ( V_89 ) {
V_109 = V_108 & ~ V_112 ;
V_110 = V_89 ;
if ( V_110 > V_113 - V_109 )
V_110 = V_113 - V_109 ;
V_111 = F_24 ( V_108 & V_112 ,
V_110 + V_109 ) ;
memcpy ( V_111 + V_109 , V_107 , V_110 ) ;
F_25 ( V_111 , V_110 + V_109 ) ;
V_107 += V_110 ;
V_108 += V_110 ;
V_89 -= V_110 ;
}
}
}
static T_10
F_26 ( struct V_56 * V_114 ,
T_11 * V_16 , T_5 * V_70 )
{
int V_115 = 0 ;
int V_116 = 0 ;
struct V_56 * V_79 ;
T_5 V_117 ;
* V_70 = 0 ;
* V_16 = 0 ;
if ( ! V_104 )
return V_118 ;
while ( V_115 + V_119 <= V_102 ) {
V_79 = F_27 ( V_104 + V_115 ,
V_119 ) ;
if ( V_115 + V_79 -> V_70 > V_102 ) {
F_28 ( V_79 , V_119 ) ;
F_21 ( 1 ) ;
return V_118 ;
}
V_117 = V_79 -> V_70 ;
if ( memcmp ( V_114 -> V_80 , V_79 -> V_80 , 4 ) ||
memcmp ( V_79 -> V_120 , V_114 -> V_120 ,
V_121 ) ||
memcmp ( V_79 -> V_81 , V_114 -> V_81 ,
V_122 ) ) {
F_28 ( V_79 , V_119 ) ;
goto V_123;
}
if ( F_29 ( V_116 , V_124 ) ||
V_114 -> V_125 >= V_79 -> V_125 ) {
F_28 ( V_79 , V_119 ) ;
goto V_123;
}
* V_70 = V_117 ;
* V_16 = V_104 + V_115 ;
F_3 ( L_31 ,
V_79 -> V_80 , V_79 -> V_120 ,
V_79 -> V_81 ) ;
F_28 ( V_79 , V_119 ) ;
break;
V_123:
V_115 += V_117 ;
V_116 ++ ;
}
return V_118 ;
}
static void T_2 F_30 ( void )
{
int V_115 = 0 ;
int V_116 = 0 ;
T_5 V_117 ;
struct V_56 * V_79 ;
if ( ! V_104 )
return;
while ( V_115 + V_119 <= V_102 ) {
V_79 = F_27 ( V_104 + V_115 ,
V_119 ) ;
if ( V_115 + V_79 -> V_70 > V_102 ) {
F_28 ( V_79 , V_119 ) ;
F_21 ( 1 ) ;
return;
}
V_117 = V_79 -> V_70 ;
if ( F_31 ( V_79 -> V_80 , V_126 ) ||
F_31 ( V_79 -> V_80 , V_127 ) ) {
F_28 ( V_79 , V_119 ) ;
goto V_123;
}
if ( F_29 ( V_116 , V_124 ) ) {
F_28 ( V_79 , V_119 ) ;
goto V_123;
}
F_3 ( L_32 ,
V_79 -> V_80 , V_79 -> V_120 ,
V_79 -> V_81 ) ;
F_28 ( V_79 , V_119 ) ;
F_32 ( V_104 + V_115 , TRUE ) ;
V_123:
V_115 += V_117 ;
V_116 ++ ;
}
}
static T_10
F_26 ( struct V_56 * V_114 ,
T_11 * V_16 ,
T_5 * V_117 )
{
* V_117 = 0 ;
* V_16 = 0 ;
return V_118 ;
}
static void T_2 F_30 ( void )
{
}
T_10
F_33 ( struct V_56 * V_114 ,
T_11 * V_16 ,
T_5 * V_117 )
{
return F_26 ( V_114 , V_16 ,
V_117 ) ;
}
T_10
F_34 ( struct V_56 * V_114 ,
struct V_56 * * V_128 )
{
if ( ! V_114 || ! V_128 )
return V_129 ;
* V_128 = NULL ;
#ifdef F_35
if ( strncmp ( V_114 -> V_80 , L_33 , 4 ) == 0 )
* V_128 = (struct V_56 * ) V_130 ;
#endif
if ( * V_128 != NULL )
F_15 ( V_114 ) ;
return V_118 ;
}
int T_2 F_36 ( void )
{
T_10 V_131 ;
if ( V_132 ) {
F_3 ( L_34 ) ;
V_133 = TRUE ;
} else {
F_3 ( L_35 ) ;
V_133 = FALSE ;
}
V_131 = F_37 ( V_134 , V_135 , 0 ) ;
if ( F_38 ( V_131 ) )
return - V_69 ;
F_30 () ;
F_14 () ;
return 0 ;
}
static int T_2 F_39 ( char * V_136 )
{
if ( ! V_136 )
return - V_69 ;
if ( F_40 ( V_136 , 0 , & V_76 ) )
return - V_69 ;
F_41 ( L_36 , V_76 ) ;
return 0 ;
}
static int T_2 F_42 ( char * V_137 )
{
V_132 = true ;
return 0 ;
}
static int T_2 F_43 ( char * V_137 )
{
F_3 ( L_37 ) ;
V_138 = TRUE ;
return 0 ;
}
