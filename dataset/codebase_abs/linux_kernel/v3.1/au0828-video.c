static inline void F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
char * V_5 = L_1 ;
switch ( V_4 ) {
case - V_6 :
V_5 = L_2 ;
break;
case - V_7 :
V_5 = L_3 ;
break;
case - V_8 :
V_5 = L_4 ;
break;
case - V_9 :
V_5 = L_5 ;
break;
case - V_10 :
V_5 = L_6 ;
break;
case - V_11 :
V_5 = L_7 ;
break;
case - V_12 :
V_5 = L_8 ;
break;
case - V_13 :
V_5 = L_9 ;
break;
}
if ( V_3 < 0 ) {
F_2 ( L_10 , V_4 , V_5 ) ;
} else {
F_2 ( L_11 ,
V_3 , V_4 , V_5 ) ;
}
}
static int F_3 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 & V_15 ) {
F_4 ( V_16 L_12 ) ;
return - V_17 ;
}
if ( V_2 -> V_14 & V_18 ) {
F_4 ( V_16 L_13
L_14 ) ;
return - V_19 ;
}
return 0 ;
}
static void F_5 ( struct V_20 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_1 * V_2 = F_6 ( V_22 , struct V_1 , V_24 ) ;
unsigned long V_25 = 0 ;
int V_26 , V_27 ;
switch ( V_20 -> V_4 ) {
case 0 :
case - V_28 :
break;
case - V_7 :
case - V_6 :
case - V_29 :
F_2 ( L_15 ) ;
return;
default:
F_2 ( L_16 , V_20 -> V_4 ) ;
break;
}
F_7 ( & V_2 -> V_30 , V_25 ) ;
V_26 = V_2 -> V_31 . V_32 ( V_2 , V_20 ) ;
F_8 ( & V_2 -> V_30 , V_25 ) ;
for ( V_27 = 0 ; V_27 < V_20 -> V_33 ; V_27 ++ ) {
V_20 -> V_34 [ V_27 ] . V_4 = 0 ;
V_20 -> V_34 [ V_27 ] . V_35 = 0 ;
}
V_20 -> V_4 = 0 ;
V_20 -> V_4 = F_9 ( V_20 , V_36 ) ;
if ( V_20 -> V_4 ) {
F_2 ( L_17 ,
V_20 -> V_4 ) ;
}
}
void F_10 ( struct V_1 * V_2 )
{
struct V_20 * V_20 ;
int V_27 ;
F_2 ( L_18 ) ;
V_2 -> V_31 . V_37 = - 1 ;
for ( V_27 = 0 ; V_27 < V_2 -> V_31 . V_38 ; V_27 ++ ) {
V_20 = V_2 -> V_31 . V_20 [ V_27 ] ;
if ( V_20 ) {
if ( ! F_11 () )
F_12 ( V_20 ) ;
else
F_13 ( V_20 ) ;
if ( V_2 -> V_31 . V_39 [ V_27 ] ) {
F_14 ( V_2 -> V_40 ,
V_20 -> V_41 ,
V_2 -> V_31 . V_39 [ V_27 ] ,
V_20 -> V_42 ) ;
}
F_15 ( V_20 ) ;
V_2 -> V_31 . V_20 [ V_27 ] = NULL ;
}
V_2 -> V_31 . V_39 [ V_27 ] = NULL ;
}
F_16 ( V_2 -> V_31 . V_20 ) ;
F_16 ( V_2 -> V_31 . V_39 ) ;
V_2 -> V_31 . V_20 = NULL ;
V_2 -> V_31 . V_39 = NULL ;
V_2 -> V_31 . V_38 = 0 ;
}
int F_17 ( struct V_1 * V_2 , int V_43 ,
int V_38 , int V_44 ,
int (* V_32) ( struct V_1 * V_2 , struct V_20 * V_20 ) )
{
struct V_21 * V_22 = & V_2 -> V_24 ;
int V_27 ;
int V_45 , V_46 ;
struct V_20 * V_20 ;
int V_47 , V_48 ;
int V_26 ;
F_2 ( L_19 ) ;
F_10 ( V_2 ) ;
V_2 -> V_31 . V_32 = V_32 ;
V_2 -> V_31 . V_38 = V_38 ;
V_2 -> V_31 . V_20 = F_18 ( sizeof( void * ) * V_38 , V_49 ) ;
if ( ! V_2 -> V_31 . V_20 ) {
F_2 ( L_20 ) ;
return - V_50 ;
}
V_2 -> V_31 . V_39 = F_18 ( sizeof( void * ) * V_38 ,
V_49 ) ;
if ( ! V_2 -> V_31 . V_39 ) {
F_2 ( L_21 ) ;
F_16 ( V_2 -> V_31 . V_20 ) ;
return - V_50 ;
}
V_2 -> V_31 . V_44 = V_44 ;
V_2 -> V_31 . V_51 = NULL ;
V_45 = V_43 * V_2 -> V_31 . V_44 ;
for ( V_27 = 0 ; V_27 < V_2 -> V_31 . V_38 ; V_27 ++ ) {
V_20 = F_19 ( V_43 , V_49 ) ;
if ( ! V_20 ) {
F_2 ( L_22 , V_27 ) ;
F_10 ( V_2 ) ;
return - V_50 ;
}
V_2 -> V_31 . V_20 [ V_27 ] = V_20 ;
V_2 -> V_31 . V_39 [ V_27 ] = F_20 ( V_2 -> V_40 ,
V_45 , V_49 , & V_20 -> V_42 ) ;
if ( ! V_2 -> V_31 . V_39 [ V_27 ] ) {
F_4 ( L_23
L_24 ,
V_45 , V_27 ,
F_21 () ? L_25 : L_26 ) ;
F_10 ( V_2 ) ;
return - V_50 ;
}
memset ( V_2 -> V_31 . V_39 [ V_27 ] , 0 , V_45 ) ;
V_46 = F_22 ( V_2 -> V_40 ,
V_2 -> V_52 ) ,
F_23 ( V_20 , V_2 -> V_40 , V_46 ,
V_2 -> V_31 . V_39 [ V_27 ] , V_45 ,
F_5 , V_22 , 1 ) ;
V_20 -> V_33 = V_43 ;
V_20 -> V_53 = V_54 | V_55 ;
V_48 = 0 ;
for ( V_47 = 0 ; V_47 < V_43 ; V_47 ++ ) {
V_20 -> V_34 [ V_47 ] . V_56 = V_48 ;
V_20 -> V_34 [ V_47 ] . V_57 =
V_2 -> V_31 . V_44 ;
V_48 += V_2 -> V_31 . V_44 ;
}
}
F_24 ( & V_22 -> V_58 ) ;
for ( V_27 = 0 ; V_27 < V_2 -> V_31 . V_38 ; V_27 ++ ) {
V_26 = F_9 ( V_2 -> V_31 . V_20 [ V_27 ] , V_36 ) ;
if ( V_26 ) {
F_2 ( L_27 ,
V_27 , V_26 ) ;
F_10 ( V_2 ) ;
return V_26 ;
}
}
return 0 ;
}
static inline void F_25 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_59 * V_51 )
{
F_2 ( L_28 , V_51 , V_51 -> V_60 . V_27 ) ;
V_51 -> V_60 . V_61 = V_62 ;
V_51 -> V_60 . V_63 ++ ;
F_26 ( & V_51 -> V_60 . V_64 ) ;
V_2 -> V_31 . V_51 = NULL ;
F_27 ( & V_51 -> V_60 . V_65 ) ;
F_28 ( & V_51 -> V_60 . V_66 ) ;
}
static inline void F_29 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_59 * V_51 )
{
F_2 ( L_28 , V_51 , V_51 -> V_60 . V_27 ) ;
V_51 -> V_60 . V_61 = V_62 ;
V_51 -> V_60 . V_63 ++ ;
F_26 ( & V_51 -> V_60 . V_64 ) ;
V_2 -> V_31 . V_67 = NULL ;
F_27 ( & V_51 -> V_60 . V_65 ) ;
F_28 ( & V_51 -> V_60 . V_66 ) ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_59 * V_51 ,
unsigned char * V_68 ,
unsigned char * V_69 , unsigned long V_70 )
{
void * V_71 , * V_72 , * V_73 ;
int V_74 , V_75 , V_56 , V_76 , V_77 ;
int V_78 = V_2 -> V_79 << 1 ;
if ( V_70 == 0 )
return;
if ( V_22 -> V_80 + V_70 > V_51 -> V_60 . V_81 )
V_70 = V_51 -> V_60 . V_81 - V_22 -> V_80 ;
V_73 = V_68 ;
V_77 = V_70 ;
if ( V_51 -> V_82 )
V_71 = V_69 ;
else
V_71 = V_69 + V_78 ;
V_74 = V_22 -> V_80 / V_78 ;
V_75 = V_22 -> V_80 % V_78 ;
V_56 = V_74 * V_78 * 2 + V_75 ;
V_72 = V_71 + V_56 ;
V_76 = V_78 - V_75 ;
V_76 = V_76 > V_77 ? V_77 : V_76 ;
if ( ( char * ) V_72 + V_76 > ( char * ) V_69 + V_51 -> V_60 . V_81 ) {
F_2 ( L_29 ,
( ( char * ) V_72 + V_76 ) -
( ( char * ) V_69 + V_51 -> V_60 . V_81 ) ) ;
V_77 = ( char * ) V_69 + V_51 -> V_60 . V_81 - ( char * ) V_72 ;
V_76 = V_77 ;
}
if ( V_76 <= 0 )
return;
memcpy ( V_72 , V_73 , V_76 ) ;
V_77 -= V_76 ;
while ( V_77 > 0 ) {
V_72 += V_76 + V_78 ;
V_73 += V_76 ;
if ( V_78 > V_77 )
V_76 = V_77 ;
else
V_76 = V_78 ;
if ( ( char * ) V_72 + V_76 > ( char * ) V_69 +
V_51 -> V_60 . V_81 ) {
F_2 ( L_30 ,
( ( char * ) V_72 + V_76 ) -
( ( char * ) V_69 + V_51 -> V_60 . V_81 ) ) ;
V_76 = V_77 = ( char * ) V_69 + V_51 -> V_60 . V_81 -
( char * ) V_72 ;
}
if ( V_76 <= 0 )
break;
memcpy ( V_72 , V_73 , V_76 ) ;
V_77 -= V_76 ;
}
if ( V_56 > 1440 ) {
if ( V_69 [ 0 ] < 0x60 && V_69 [ 1440 ] < 0x60 )
V_2 -> V_83 = 1 ;
}
V_22 -> V_80 += V_70 ;
}
static inline void F_31 ( struct V_21 * V_22 ,
struct V_59 * * V_51 )
{
struct V_1 * V_2 = F_6 ( V_22 , struct V_1 , V_24 ) ;
if ( F_32 ( & V_22 -> V_84 ) ) {
F_2 ( L_31 ) ;
V_2 -> V_31 . V_51 = NULL ;
* V_51 = NULL ;
return;
}
* V_51 = F_33 ( V_22 -> V_84 . V_85 , struct V_59 , V_60 . V_65 ) ;
V_2 -> V_31 . V_51 = * V_51 ;
return;
}
static void F_34 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_59 * V_51 ,
unsigned char * V_68 ,
unsigned char * V_69 , unsigned long V_70 )
{
unsigned char * V_72 , * V_73 ;
int V_78 ;
int V_27 , V_47 = 0 ;
if ( V_2 == NULL ) {
F_2 ( L_32 ) ;
return;
}
if ( V_22 == NULL ) {
F_2 ( L_33 ) ;
return;
}
if ( V_51 == NULL )
return;
if ( V_68 == NULL ) {
F_2 ( L_34 ) ;
return;
}
if ( V_69 == NULL ) {
F_2 ( L_35 ) ;
return;
}
V_78 = V_2 -> V_86 ;
if ( V_22 -> V_80 + V_70 > V_51 -> V_60 . V_81 )
V_70 = V_51 -> V_60 . V_81 - V_22 -> V_80 ;
V_73 = V_68 ;
V_72 = V_69 + ( V_22 -> V_80 / 2 ) ;
if ( V_51 -> V_82 == 0 )
V_72 += V_78 * V_2 -> V_87 ;
for ( V_27 = 0 ; V_27 < V_70 ; V_27 += 2 )
V_72 [ V_47 ++ ] = V_73 [ V_27 + 1 ] ;
V_22 -> V_80 += V_70 ;
}
static inline void F_35 ( struct V_21 * V_22 ,
struct V_59 * * V_51 )
{
struct V_1 * V_2 = F_6 ( V_22 , struct V_1 , V_88 ) ;
char * V_69 ;
if ( F_32 ( & V_22 -> V_84 ) ) {
F_2 ( L_31 ) ;
V_2 -> V_31 . V_67 = NULL ;
* V_51 = NULL ;
return;
}
* V_51 = F_33 ( V_22 -> V_84 . V_85 , struct V_59 , V_60 . V_65 ) ;
V_69 = F_36 ( & ( * V_51 ) -> V_60 ) ;
memset ( V_69 , 0x00 , ( * V_51 ) -> V_60 . V_81 ) ;
V_2 -> V_31 . V_67 = * V_51 ;
return;
}
static inline int F_37 ( struct V_1 * V_2 , struct V_20 * V_20 )
{
struct V_59 * V_51 ;
struct V_59 * V_67 ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_21 * V_89 = & V_2 -> V_88 ;
unsigned char * V_69 = NULL ;
unsigned char * V_90 = NULL ;
int V_27 , V_70 = 0 , V_26 = 1 ;
unsigned char * V_68 ;
unsigned char V_91 ;
unsigned int V_92 ;
unsigned int V_77 , V_76 ;
if ( ! V_2 )
return 0 ;
if ( ( V_2 -> V_14 & V_15 ) ||
( V_2 -> V_14 & V_18 ) )
return 0 ;
if ( V_20 -> V_4 < 0 ) {
F_1 ( V_2 , - 1 , V_20 -> V_4 ) ;
if ( V_20 -> V_4 == - V_6 )
return 0 ;
}
V_51 = V_2 -> V_31 . V_51 ;
if ( V_51 != NULL )
V_69 = F_36 ( & V_51 -> V_60 ) ;
V_67 = V_2 -> V_31 . V_67 ;
if ( V_67 != NULL )
V_90 = F_36 ( & V_67 -> V_60 ) ;
for ( V_27 = 0 ; V_27 < V_20 -> V_33 ; V_27 ++ ) {
int V_4 = V_20 -> V_34 [ V_27 ] . V_4 ;
if ( V_4 < 0 ) {
F_1 ( V_2 , V_27 , V_4 ) ;
if ( V_20 -> V_34 [ V_27 ] . V_4 != - V_11 )
continue;
}
if ( V_20 -> V_34 [ V_27 ] . V_35 <= 0 )
continue;
if ( V_20 -> V_34 [ V_27 ] . V_35 >
V_2 -> V_44 ) {
F_2 ( L_36 ) ;
continue;
}
V_68 = V_20 -> V_39 + V_20 -> V_34 [ V_27 ] . V_56 ;
V_91 = V_68 [ 0 ] ;
V_70 = V_20 -> V_34 [ V_27 ] . V_35 - 4 ;
V_68 += 4 ;
if ( V_91 & 0x80 ) {
V_70 -= 4 ;
V_68 += 4 ;
F_2 ( L_37 ,
( V_91 & 0x40 ) ? L_38 : L_39 ) ;
if ( V_91 & 0x40 ) {
if ( V_67 != NULL )
F_29 ( V_2 ,
V_89 ,
V_67 ) ;
F_35 ( V_89 , & V_67 ) ;
if ( V_67 == NULL )
V_90 = NULL ;
else
V_90 = F_36 (
& V_67 -> V_60 ) ;
if ( V_51 != NULL )
F_25 ( V_2 , V_22 , V_51 ) ;
F_31 ( V_22 , & V_51 ) ;
if ( V_51 == NULL )
V_69 = NULL ;
else
V_69 = F_36 ( & V_51 -> V_60 ) ;
if ( V_2 -> V_93 )
F_38 ( & V_2 -> V_94 ,
V_95 + ( V_96 / 10 ) ) ;
if ( V_2 -> V_97 )
F_38 ( & V_2 -> V_98 ,
V_95 + ( V_96 / 10 ) ) ;
}
if ( V_51 != NULL ) {
if ( V_91 & 0x40 )
V_51 -> V_82 = 1 ;
else
V_51 -> V_82 = 0 ;
}
if ( V_67 != NULL ) {
if ( V_91 & 0x40 )
V_67 -> V_82 = 1 ;
else
V_67 -> V_82 = 0 ;
}
V_2 -> V_99 = 0 ;
V_89 -> V_80 = 0 ;
V_22 -> V_80 = 0 ;
}
V_92 = V_2 -> V_86 * V_2 -> V_87 * 2 ;
if ( V_2 -> V_99 < V_92 ) {
V_77 = V_92 - V_2 -> V_99 ;
if ( V_70 < V_77 )
V_76 = V_70 ;
else
V_76 = V_77 ;
if ( V_67 != NULL )
F_34 ( V_2 , V_89 , V_67 , V_68 ,
V_90 , V_70 ) ;
V_70 -= V_76 ;
V_68 += V_76 ;
V_2 -> V_99 += V_76 ;
}
if ( V_2 -> V_99 >= V_92 && V_51 != NULL )
F_30 ( V_2 , V_22 , V_51 , V_68 , V_69 , V_70 ) ;
}
return V_26 ;
}
static int
F_39 ( struct V_100 * V_101 , unsigned int * V_102 ,
unsigned int * V_81 )
{
struct V_103 * V_104 = V_101 -> V_105 ;
* V_81 = ( V_104 -> V_2 -> V_79 * V_104 -> V_2 -> V_106 * 16 + 7 ) >> 3 ;
if ( 0 == * V_102 )
* V_102 = V_107 ;
if ( * V_102 < V_108 )
* V_102 = V_108 ;
return 0 ;
}
static void F_40 ( struct V_100 * V_101 , struct V_59 * V_51 )
{
struct V_103 * V_104 = V_101 -> V_105 ;
struct V_1 * V_2 = V_104 -> V_2 ;
unsigned long V_25 = 0 ;
if ( F_21 () )
F_41 () ;
F_7 ( & V_2 -> V_30 , V_25 ) ;
if ( V_2 -> V_31 . V_51 == V_51 )
V_2 -> V_31 . V_51 = NULL ;
F_8 ( & V_2 -> V_30 , V_25 ) ;
F_42 ( & V_51 -> V_60 ) ;
V_51 -> V_60 . V_61 = V_109 ;
}
static int
F_43 ( struct V_100 * V_101 , struct V_110 * V_60 ,
enum V_111 V_112 )
{
struct V_103 * V_104 = V_101 -> V_105 ;
struct V_59 * V_51 = F_6 ( V_60 , struct V_59 , V_60 ) ;
struct V_1 * V_2 = V_104 -> V_2 ;
int V_26 = 0 , V_113 = 0 ;
V_51 -> V_60 . V_81 = ( V_104 -> V_2 -> V_79 * V_104 -> V_2 -> V_106 * 16 + 7 ) >> 3 ;
if ( 0 != V_51 -> V_60 . V_114 && V_51 -> V_60 . V_115 < V_51 -> V_60 . V_81 )
return - V_116 ;
V_51 -> V_60 . V_79 = V_2 -> V_79 ;
V_51 -> V_60 . V_106 = V_2 -> V_106 ;
V_51 -> V_60 . V_112 = V_112 ;
if ( V_109 == V_51 -> V_60 . V_61 ) {
V_26 = F_44 ( V_101 , & V_51 -> V_60 , NULL ) ;
if ( V_26 < 0 ) {
F_4 ( V_16 L_40 ) ;
goto V_117;
}
}
if ( ! V_2 -> V_31 . V_38 )
V_113 = 1 ;
if ( V_113 ) {
V_26 = F_17 ( V_2 , V_118 ,
V_119 , V_2 -> V_44 ,
F_37 ) ;
if ( V_26 < 0 ) {
F_4 ( V_16 L_41 ) ;
goto V_117;
}
}
V_51 -> V_60 . V_61 = V_120 ;
return 0 ;
V_117:
F_40 ( V_101 , V_51 ) ;
return V_26 ;
}
static void
F_45 ( struct V_100 * V_101 , struct V_110 * V_60 )
{
struct V_59 * V_51 = F_6 ( V_60 ,
struct V_59 ,
V_60 ) ;
struct V_103 * V_104 = V_101 -> V_105 ;
struct V_1 * V_2 = V_104 -> V_2 ;
struct V_21 * V_24 = & V_2 -> V_24 ;
V_51 -> V_60 . V_61 = V_121 ;
F_46 ( & V_51 -> V_60 . V_65 , & V_24 -> V_84 ) ;
}
static void F_47 ( struct V_100 * V_101 ,
struct V_110 * V_60 )
{
struct V_59 * V_51 = F_6 ( V_60 ,
struct V_59 ,
V_60 ) ;
F_40 ( V_101 , V_51 ) ;
}
static int F_48 ( struct V_1 * V_2 )
{
F_49 ( V_2 , V_122 , 0x01 ) ;
return 0 ;
}
int F_50 ( struct V_1 * V_123 )
{
F_51 ( 1 , L_42 ) ;
F_49 ( V_123 , V_124 , 0x00 ) ;
F_49 ( V_123 , 0x106 , 0x00 ) ;
F_49 ( V_123 , 0x110 , 0x00 ) ;
F_49 ( V_123 , 0x111 , 0x00 ) ;
F_49 ( V_123 , 0x114 , 0xa0 ) ;
F_49 ( V_123 , 0x115 , 0x05 ) ;
F_49 ( V_123 , 0x112 , 0x00 ) ;
F_49 ( V_123 , 0x113 , 0x00 ) ;
F_49 ( V_123 , 0x116 , 0xf2 ) ;
F_49 ( V_123 , 0x117 , 0x00 ) ;
F_49 ( V_123 , V_125 , 0xb3 ) ;
return 0 ;
}
int F_52 ( struct V_1 * V_123 )
{
F_51 ( 1 , L_43 ) ;
F_49 ( V_123 , V_125 , 0x0 ) ;
return 0 ;
}
void F_53 ( struct V_1 * V_2 )
{
F_51 ( 1 , L_44 ) ;
F_49 ( V_2 , V_125 , 0x0 ) ;
F_54 ( 30 ) ;
F_49 ( V_2 , V_125 , 0xb3 ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
int V_126 = 0 ;
V_2 -> V_127 = V_128 ;
if ( V_2 -> V_14 == V_15 )
return - V_17 ;
else if ( V_126 ) {
V_2 -> V_14 = V_18 ;
F_51 ( 1 , L_45 , V_129 ) ;
return V_126 ;
}
return 0 ;
}
void F_56 ( struct V_1 * V_2 )
{
F_51 ( 1 , L_46 ) ;
F_57 ( & V_130 ) ;
if ( V_2 -> V_131 )
F_58 ( V_2 -> V_131 ) ;
if ( V_2 -> V_132 )
F_58 ( V_2 -> V_132 ) ;
F_59 ( & V_130 ) ;
}
static int F_60 ( struct V_103 * V_104 , unsigned int V_133 )
{
struct V_1 * V_2 = V_104 -> V_2 ;
if ( V_104 -> V_134 & V_133 )
return 1 ;
F_57 ( & V_2 -> V_135 ) ;
if ( V_2 -> V_134 & V_133 ) {
F_59 ( & V_2 -> V_135 ) ;
return 0 ;
}
V_104 -> V_134 |= V_133 ;
V_2 -> V_134 |= V_133 ;
F_51 ( 1 , L_47 , V_133 ) ;
F_59 ( & V_2 -> V_135 ) ;
return 1 ;
}
static int F_61 ( struct V_103 * V_104 , unsigned int V_133 )
{
return V_104 -> V_134 & V_133 ;
}
static int F_62 ( struct V_1 * V_2 , unsigned int V_133 )
{
return V_2 -> V_134 & V_133 ;
}
static void F_63 ( struct V_103 * V_104 , unsigned int V_136 )
{
struct V_1 * V_2 = V_104 -> V_2 ;
F_64 ( ( V_104 -> V_134 & V_136 ) != V_136 ) ;
F_57 ( & V_2 -> V_135 ) ;
V_104 -> V_134 &= ~ V_136 ;
V_2 -> V_134 &= ~ V_136 ;
F_51 ( 1 , L_48 , V_136 ) ;
F_59 ( & V_2 -> V_135 ) ;
}
static int F_65 ( struct V_103 * V_104 )
{
switch ( V_104 -> type ) {
case V_137 :
return V_138 ;
case V_139 :
return V_140 ;
default:
F_41 () ;
return 0 ;
}
}
void F_66 ( unsigned long V_141 )
{
struct V_1 * V_2 = (struct V_1 * ) V_141 ;
struct V_21 * V_22 = & V_2 -> V_24 ;
struct V_59 * V_51 ;
unsigned char * V_142 ;
unsigned long V_25 = 0 ;
F_7 ( & V_2 -> V_30 , V_25 ) ;
V_51 = V_2 -> V_31 . V_51 ;
if ( V_51 != NULL ) {
V_142 = F_36 ( & V_51 -> V_60 ) ;
memset ( V_142 , 0x00 , V_51 -> V_60 . V_81 ) ;
F_25 ( V_2 , V_22 , V_51 ) ;
}
F_31 ( V_22 , & V_51 ) ;
if ( V_2 -> V_93 == 1 )
F_38 ( & V_2 -> V_94 , V_95 + ( V_96 / 10 ) ) ;
F_8 ( & V_2 -> V_30 , V_25 ) ;
}
void F_67 ( unsigned long V_141 )
{
struct V_1 * V_2 = (struct V_1 * ) V_141 ;
struct V_21 * V_22 = & V_2 -> V_88 ;
struct V_59 * V_51 ;
unsigned char * V_143 ;
unsigned long V_25 = 0 ;
F_7 ( & V_2 -> V_30 , V_25 ) ;
V_51 = V_2 -> V_31 . V_67 ;
if ( V_51 != NULL ) {
V_143 = F_36 ( & V_51 -> V_60 ) ;
memset ( V_143 , 0x00 , V_51 -> V_60 . V_81 ) ;
F_29 ( V_2 , V_22 , V_51 ) ;
}
F_35 ( V_22 , & V_51 ) ;
if ( V_2 -> V_97 == 1 )
F_38 ( & V_2 -> V_98 , V_95 + ( V_96 / 10 ) ) ;
F_8 ( & V_2 -> V_30 , V_25 ) ;
}
static int F_68 ( struct V_144 * V_145 )
{
int V_126 = 0 ;
struct V_146 * V_131 = F_69 ( V_145 ) ;
struct V_1 * V_2 = F_70 ( V_145 ) ;
struct V_103 * V_104 ;
int type ;
switch ( V_131 -> V_147 ) {
case V_148 :
type = V_137 ;
break;
case V_149 :
type = V_139 ;
break;
default:
return - V_116 ;
}
V_104 = F_18 ( sizeof( struct V_103 ) , V_49 ) ;
if ( NULL == V_104 ) {
F_51 ( 1 , L_49 ) ;
return - V_50 ;
}
V_104 -> type = type ;
V_104 -> V_2 = V_2 ;
V_145 -> V_150 = V_104 ;
if ( V_104 -> type == V_137 && V_2 -> V_151 == 0 ) {
V_126 = F_71 ( V_2 -> V_40 , 0 , 5 ) ;
if ( V_126 < 0 ) {
F_4 ( V_16 L_50 ) ;
return - V_152 ;
}
V_2 -> V_79 = V_153 ;
V_2 -> V_106 = V_154 ;
V_2 -> V_155 = V_2 -> V_79 * V_2 -> V_106 * 2 ;
V_2 -> V_156 = V_2 -> V_79 * V_2 -> V_106 ;
V_2 -> V_78 = V_2 -> V_79 * 2 ;
F_50 ( V_2 ) ;
F_53 ( V_2 ) ;
F_48 ( V_2 ) ;
V_2 -> V_127 = V_157 ;
V_2 -> V_14 |= V_158 ;
}
V_2 -> V_151 ++ ;
F_72 ( & V_104 -> V_159 , & V_160 ,
NULL , & V_2 -> V_30 ,
V_137 ,
V_161 ,
sizeof( struct V_59 ) , V_104 , NULL ) ;
V_2 -> V_86 = 720 ;
V_2 -> V_87 = 1 ;
F_72 ( & V_104 -> V_162 , & V_163 ,
NULL , & V_2 -> V_30 ,
V_139 ,
V_164 ,
sizeof( struct V_59 ) , V_104 , NULL ) ;
return V_126 ;
}
static int F_73 ( struct V_144 * V_145 )
{
int V_126 ;
struct V_103 * V_104 = V_145 -> V_150 ;
struct V_1 * V_2 = V_104 -> V_2 ;
if ( F_61 ( V_104 , V_138 ) ) {
V_2 -> V_93 = 0 ;
F_74 ( & V_2 -> V_94 ) ;
F_75 ( & V_104 -> V_159 ) ;
F_63 ( V_104 , V_138 ) ;
}
if ( F_61 ( V_104 , V_140 ) ) {
V_2 -> V_97 = 0 ;
F_74 ( & V_2 -> V_98 ) ;
F_75 ( & V_104 -> V_162 ) ;
F_63 ( V_104 , V_140 ) ;
}
if ( V_2 -> V_151 == 1 ) {
if ( V_2 -> V_14 & V_15 ) {
F_56 ( V_2 ) ;
F_16 ( V_2 ) ;
return 0 ;
}
F_52 ( V_2 ) ;
F_10 ( V_2 ) ;
F_76 ( & V_2 -> V_165 , 0 , V_166 , V_167 , 0 ) ;
V_126 = F_71 ( V_2 -> V_40 , 0 , 0 ) ;
if ( V_126 < 0 )
F_4 ( V_16 L_51 ) ;
}
F_77 ( & V_104 -> V_159 ) ;
F_77 ( & V_104 -> V_162 ) ;
F_16 ( V_104 ) ;
V_2 -> V_151 -- ;
F_78 ( & V_2 -> V_168 , 1 ) ;
return 0 ;
}
static T_1 F_79 ( struct V_144 * V_145 , char T_2 * V_51 ,
T_3 V_102 , T_4 * V_80 )
{
struct V_103 * V_104 = V_145 -> V_150 ;
struct V_1 * V_2 = V_104 -> V_2 ;
int V_26 ;
V_26 = F_3 ( V_2 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_104 -> type == V_137 ) {
if ( F_62 ( V_2 , V_138 ) )
return - V_152 ;
return F_80 ( & V_104 -> V_159 , V_51 , V_102 , V_80 , 0 ,
V_145 -> V_169 & V_170 ) ;
}
if ( V_104 -> type == V_139 ) {
if ( ! F_60 ( V_104 , V_140 ) )
return - V_152 ;
if ( V_2 -> V_97 == 0 ) {
V_2 -> V_97 = 1 ;
F_38 ( & V_2 -> V_98 , V_95 + ( V_96 / 10 ) ) ;
}
return F_80 ( & V_104 -> V_162 , V_51 , V_102 , V_80 , 0 ,
V_145 -> V_169 & V_170 ) ;
}
return 0 ;
}
static unsigned int F_81 ( struct V_144 * V_145 , T_5 * V_171 )
{
struct V_103 * V_104 = V_145 -> V_150 ;
struct V_1 * V_2 = V_104 -> V_2 ;
int V_26 ;
V_26 = F_3 ( V_2 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_104 -> type == V_137 ) {
if ( ! F_60 ( V_104 , V_138 ) )
return V_172 ;
return F_82 ( V_145 , & V_104 -> V_159 , V_171 ) ;
} else if ( V_104 -> type == V_139 ) {
if ( ! F_60 ( V_104 , V_140 ) )
return V_172 ;
return F_82 ( V_145 , & V_104 -> V_162 , V_171 ) ;
} else {
return V_172 ;
}
}
static int F_83 ( struct V_144 * V_145 , struct V_173 * V_174 )
{
struct V_103 * V_104 = V_145 -> V_150 ;
struct V_1 * V_2 = V_104 -> V_2 ;
int V_26 ;
V_26 = F_3 ( V_2 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_104 -> type == V_137 )
V_26 = F_84 ( & V_104 -> V_159 , V_174 ) ;
else if ( V_104 -> type == V_139 )
V_26 = F_84 ( & V_104 -> V_162 , V_174 ) ;
return V_26 ;
}
static int F_85 ( struct V_1 * V_2 , unsigned int V_175 ,
struct V_176 * V_177 )
{
int V_126 ;
int V_79 = V_177 -> V_178 . V_179 . V_79 ;
int V_106 = V_177 -> V_178 . V_179 . V_106 ;
if ( V_177 -> type != V_137 )
return - V_116 ;
if ( V_177 -> V_178 . V_179 . V_180 != V_181 )
return - V_116 ;
if ( V_79 != 720 )
V_79 = 720 ;
if ( V_106 != 480 )
V_106 = 480 ;
V_177 -> V_178 . V_179 . V_79 = V_79 ;
V_177 -> V_178 . V_179 . V_106 = V_106 ;
V_177 -> V_178 . V_179 . V_180 = V_181 ;
V_177 -> V_178 . V_179 . V_78 = V_79 * 2 ;
V_177 -> V_178 . V_179 . V_182 = V_79 * V_106 * 2 ;
V_177 -> V_178 . V_179 . V_183 = V_184 ;
V_177 -> V_178 . V_179 . V_112 = V_161 ;
if ( V_175 == V_185 )
return 0 ;
V_2 -> V_79 = V_79 ;
V_2 -> V_106 = V_106 ;
V_2 -> V_155 = V_79 * V_106 * 2 ;
V_2 -> V_156 = V_79 * V_106 ;
V_2 -> V_78 = V_79 * 2 ;
if ( V_2 -> V_127 == V_186 ) {
F_51 ( 1 , L_52 ) ;
V_126 = F_55 ( V_2 ) ;
if ( V_126 != 0 ) {
F_51 ( 1 , L_53 ) ;
return V_126 ;
}
}
V_126 = F_71 ( V_2 -> V_40 , 0 , 5 ) ;
if ( V_126 < 0 ) {
F_4 ( V_16 L_54 ) ;
return - V_152 ;
}
F_50 ( V_2 ) ;
return 0 ;
}
static int F_86 ( struct V_144 * V_144 , void * V_187 ,
struct V_188 * V_189 )
{
struct V_103 * V_104 = V_187 ;
struct V_1 * V_2 = V_104 -> V_2 ;
F_76 ( & V_2 -> V_165 , 0 , V_166 , V_190 , V_189 ) ;
if ( V_189 -> type )
return 0 ;
else
return - V_116 ;
}
static int F_87 ( struct V_144 * V_144 , void * V_187 ,
struct V_191 * V_192 )
{
struct V_103 * V_104 = V_187 ;
struct V_1 * V_2 = V_104 -> V_2 ;
F_88 ( V_192 -> V_193 , L_55 , sizeof( V_192 -> V_193 ) ) ;
F_88 ( V_192 -> V_194 , V_2 -> V_195 . V_196 , sizeof( V_192 -> V_194 ) ) ;
F_88 ( V_192 -> V_197 , V_2 -> V_165 . V_196 , sizeof( V_192 -> V_197 ) ) ;
V_192 -> V_198 = V_199 |
V_200 |
V_201 |
V_202 |
V_203 |
V_204 ;
return 0 ;
}
static int F_89 ( struct V_144 * V_144 , void * V_187 ,
struct V_205 * V_206 )
{
if ( V_206 -> V_207 )
return - V_116 ;
V_206 -> type = V_137 ;
strcpy ( V_206 -> V_208 , L_56 ) ;
V_206 -> V_25 = 0 ;
V_206 -> V_180 = V_181 ;
return 0 ;
}
static int F_90 ( struct V_144 * V_144 , void * V_187 ,
struct V_176 * V_206 )
{
struct V_103 * V_104 = V_187 ;
struct V_1 * V_2 = V_104 -> V_2 ;
V_206 -> V_178 . V_179 . V_79 = V_2 -> V_79 ;
V_206 -> V_178 . V_179 . V_106 = V_2 -> V_106 ;
V_206 -> V_178 . V_179 . V_180 = V_181 ;
V_206 -> V_178 . V_179 . V_78 = V_2 -> V_78 ;
V_206 -> V_178 . V_179 . V_182 = V_2 -> V_155 ;
V_206 -> V_178 . V_179 . V_183 = V_184 ;
V_206 -> V_178 . V_179 . V_112 = V_161 ;
return 0 ;
}
static int F_91 ( struct V_144 * V_144 , void * V_187 ,
struct V_176 * V_206 )
{
struct V_103 * V_104 = V_187 ;
struct V_1 * V_2 = V_104 -> V_2 ;
return F_85 ( V_2 , V_185 , V_206 ) ;
}
static int F_92 ( struct V_144 * V_144 , void * V_187 ,
struct V_176 * V_206 )
{
struct V_103 * V_104 = V_187 ;
struct V_1 * V_2 = V_104 -> V_2 ;
int V_26 ;
V_26 = F_3 ( V_2 ) ;
if ( V_26 < 0 )
return V_26 ;
F_57 ( & V_2 -> V_135 ) ;
if ( F_93 ( & V_104 -> V_159 ) ) {
F_4 ( V_16 L_57 , V_129 ) ;
V_26 = - V_152 ;
goto V_209;
}
V_26 = F_85 ( V_2 , V_210 , V_206 ) ;
V_209:
F_59 ( & V_2 -> V_135 ) ;
return V_26 ;
}
static int F_94 ( struct V_144 * V_144 , void * V_187 , T_6 * V_211 )
{
struct V_103 * V_104 = V_187 ;
struct V_1 * V_2 = V_104 -> V_2 ;
F_76 ( & V_2 -> V_165 , 0 , V_166 , V_212 , * V_211 ) ;
return 0 ;
}
static int F_95 ( struct V_144 * V_144 , void * V_187 ,
struct V_213 * V_214 )
{
struct V_103 * V_104 = V_187 ;
struct V_1 * V_2 = V_104 -> V_2 ;
unsigned int V_215 ;
static const char * V_216 [] = {
[ V_217 ] = L_58 ,
[ V_218 ] = L_59 ,
[ V_219 ] = L_60 ,
[ V_220 ] = L_61 ,
[ V_221 ] = L_62 ,
[ V_222 ] = L_63 ,
[ V_223 ] = L_64
} ;
V_215 = V_214 -> V_207 ;
if ( V_215 >= V_224 )
return - V_116 ;
if ( F_96 ( V_215 ) . type == 0 )
return - V_116 ;
V_214 -> V_207 = V_215 ;
strcpy ( V_214 -> V_196 , V_216 [ F_96 ( V_215 ) . type ] ) ;
if ( ( F_96 ( V_215 ) . type == V_221 ) ||
( F_96 ( V_215 ) . type == V_220 ) )
V_214 -> type |= V_225 ;
else
V_214 -> type |= V_226 ;
V_214 -> V_227 = V_2 -> V_131 -> V_228 ;
return 0 ;
}
static int F_97 ( struct V_144 * V_144 , void * V_187 , unsigned int * V_27 )
{
struct V_103 * V_104 = V_187 ;
struct V_1 * V_2 = V_104 -> V_2 ;
* V_27 = V_2 -> V_229 ;
return 0 ;
}
static int F_98 ( struct V_144 * V_144 , void * V_187 , unsigned int V_207 )
{
struct V_103 * V_104 = V_187 ;
struct V_1 * V_2 = V_104 -> V_2 ;
int V_27 ;
F_51 ( 1 , L_65 , V_129 ,
V_207 ) ;
if ( V_207 >= V_224 )
return - V_116 ;
if ( F_96 ( V_207 ) . type == 0 )
return - V_116 ;
V_2 -> V_229 = V_207 ;
switch ( F_96 ( V_207 ) . type ) {
case V_219 :
V_2 -> V_230 = V_219 ;
break;
case V_218 :
V_2 -> V_230 = V_218 ;
break;
case V_221 :
V_2 -> V_230 = V_221 ;
break;
default:
F_51 ( 1 , L_66 ,
F_96 ( V_207 ) . type ) ;
break;
}
F_76 ( & V_2 -> V_165 , 0 , V_231 , V_232 ,
F_96 ( V_207 ) . V_233 , 0 , 0 ) ;
for ( V_27 = 0 ; V_27 < V_224 ; V_27 ++ ) {
int V_234 = 0 ;
if ( F_96 ( V_27 ) . V_235 == NULL )
continue;
if ( V_27 == V_207 )
V_234 = 1 ;
else
V_234 = 0 ;
if ( V_234 ) {
( F_96 ( V_27 ) . V_235 ) ( V_2 , V_234 ) ;
} else {
if ( ( F_96 ( V_27 ) . V_235 ) !=
( ( F_96 ( V_207 ) . V_235 ) ) ) {
( F_96 ( V_27 ) . V_235 ) ( V_2 , V_234 ) ;
}
}
}
F_76 ( & V_2 -> V_165 , 0 , V_236 , V_232 ,
F_96 ( V_207 ) . V_237 , 0 , 0 ) ;
return 0 ;
}
static int F_99 ( struct V_144 * V_144 , void * V_187 , struct V_238 * V_239 )
{
struct V_103 * V_104 = V_187 ;
struct V_1 * V_2 = V_104 -> V_2 ;
unsigned int V_207 = V_239 -> V_207 ;
if ( V_239 -> V_207 > 1 )
return - V_116 ;
V_207 = V_2 -> V_240 ;
if ( V_207 == 0 )
strcpy ( V_239 -> V_196 , L_62 ) ;
else
strcpy ( V_239 -> V_196 , L_67 ) ;
V_239 -> V_241 = V_242 ;
V_239 -> V_207 = V_207 ;
return 0 ;
}
static int F_100 ( struct V_144 * V_144 , void * V_187 , struct V_238 * V_239 )
{
struct V_103 * V_104 = V_187 ;
struct V_1 * V_2 = V_104 -> V_2 ;
if ( V_239 -> V_207 != V_2 -> V_240 )
return - V_116 ;
return 0 ;
}
static int F_101 ( struct V_144 * V_144 , void * V_187 ,
struct V_243 * V_244 )
{
struct V_103 * V_104 = V_187 ;
struct V_1 * V_2 = V_104 -> V_2 ;
F_76 ( & V_2 -> V_165 , 0 , V_166 , V_245 , V_244 ) ;
return 0 ;
}
static int F_102 ( struct V_144 * V_144 , void * V_187 ,
struct V_243 * V_244 )
{
struct V_103 * V_104 = V_187 ;
struct V_1 * V_2 = V_104 -> V_2 ;
F_76 ( & V_2 -> V_165 , 0 , V_166 , V_246 , V_244 ) ;
return 0 ;
}
static int F_103 ( struct V_144 * V_144 , void * V_187 , struct V_247 * V_248 )
{
struct V_103 * V_104 = V_187 ;
struct V_1 * V_2 = V_104 -> V_2 ;
if ( V_248 -> V_207 != 0 )
return - V_116 ;
strcpy ( V_248 -> V_196 , L_68 ) ;
F_76 ( & V_2 -> V_165 , 0 , V_249 , V_250 , V_248 ) ;
return 0 ;
}
static int F_104 ( struct V_144 * V_144 , void * V_187 ,
struct V_247 * V_248 )
{
struct V_103 * V_104 = V_187 ;
struct V_1 * V_2 = V_104 -> V_2 ;
if ( V_248 -> V_207 != 0 )
return - V_116 ;
V_248 -> type = V_251 ;
F_76 ( & V_2 -> V_165 , 0 , V_249 , V_252 , V_248 ) ;
F_51 ( 1 , L_69 , V_248 -> signal ,
V_248 -> V_253 ) ;
return 0 ;
}
static int F_105 ( struct V_144 * V_144 , void * V_187 ,
struct V_254 * V_255 )
{
struct V_103 * V_104 = V_187 ;
struct V_1 * V_2 = V_104 -> V_2 ;
V_255 -> type = V_251 ;
V_255 -> V_256 = V_2 -> V_257 ;
return 0 ;
}
static int F_106 ( struct V_144 * V_144 , void * V_187 ,
struct V_254 * V_255 )
{
struct V_103 * V_104 = V_187 ;
struct V_1 * V_2 = V_104 -> V_2 ;
if ( V_255 -> V_249 != 0 )
return - V_116 ;
if ( V_255 -> type != V_251 )
return - V_116 ;
V_2 -> V_257 = V_255 -> V_256 ;
F_76 ( & V_2 -> V_165 , 0 , V_249 , V_258 , V_255 ) ;
F_53 ( V_2 ) ;
return 0 ;
}
static int F_107 ( struct V_144 * V_144 , void * V_187 ,
struct V_176 * V_177 )
{
struct V_103 * V_104 = V_187 ;
struct V_1 * V_2 = V_104 -> V_2 ;
V_177 -> V_178 . V_259 . V_260 = V_2 -> V_86 ;
V_177 -> V_178 . V_259 . V_261 = V_262 ;
V_177 -> V_178 . V_259 . V_56 = 0 ;
V_177 -> V_178 . V_259 . V_25 = 0 ;
V_177 -> V_178 . V_259 . V_263 = 6750000 * 4 / 2 ;
V_177 -> V_178 . V_259 . V_102 [ 0 ] = V_2 -> V_87 ;
V_177 -> V_178 . V_259 . V_102 [ 1 ] = V_2 -> V_87 ;
V_177 -> V_178 . V_259 . V_264 [ 0 ] = 21 ;
V_177 -> V_178 . V_259 . V_264 [ 1 ] = 284 ;
return 0 ;
}
static int F_108 ( struct V_144 * V_144 , void * V_187 ,
struct V_265 * V_266 )
{
struct V_103 * V_104 = V_187 ;
struct V_1 * V_2 = V_104 -> V_2 ;
V_266 -> V_267 = V_268 ;
V_266 -> V_269 = 0 ;
if ( F_109 ( & V_266 -> V_270 ) ) {
V_266 -> V_267 = V_271 ;
return 0 ;
}
F_76 ( & V_2 -> V_165 , 0 , V_166 , V_272 , V_266 ) ;
if ( V_266 -> V_267 == V_268 )
return - V_116 ;
return 0 ;
}
static int F_110 ( struct V_144 * V_144 , void * V_187 ,
struct V_273 * V_274 )
{
struct V_103 * V_104 = V_187 ;
struct V_1 * V_2 = V_104 -> V_2 ;
if ( V_274 -> type != V_137 )
return - V_116 ;
V_274 -> V_275 . V_276 = 0 ;
V_274 -> V_275 . V_277 = 0 ;
V_274 -> V_275 . V_79 = V_2 -> V_79 ;
V_274 -> V_275 . V_106 = V_2 -> V_106 ;
V_274 -> V_278 = V_274 -> V_275 ;
V_274 -> V_279 . V_280 = 54 ;
V_274 -> V_279 . V_281 = 59 ;
return 0 ;
}
static int F_111 ( struct V_144 * V_144 , void * V_187 ,
enum V_282 type )
{
struct V_103 * V_104 = V_187 ;
struct V_1 * V_2 = V_104 -> V_2 ;
int V_26 = - V_116 ;
V_26 = F_3 ( V_2 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( F_112 ( type != V_104 -> type ) )
return - V_116 ;
F_51 ( 1 , L_70 ,
V_104 , type , V_104 -> V_134 , V_2 -> V_134 ) ;
if ( F_112 ( ! F_60 ( V_104 , F_65 ( V_104 ) ) ) )
return - V_152 ;
if ( type == V_137 ) {
F_50 ( V_2 ) ;
F_76 ( & V_2 -> V_165 , 0 , V_231 , V_283 , 1 ) ;
}
if ( V_104 -> type == V_137 ) {
V_26 = F_113 ( & V_104 -> V_159 ) ;
V_2 -> V_93 = 1 ;
F_38 ( & V_2 -> V_94 , V_95 + ( V_96 / 10 ) ) ;
} else if ( V_104 -> type == V_139 ) {
V_26 = F_113 ( & V_104 -> V_162 ) ;
V_2 -> V_97 = 1 ;
F_38 ( & V_2 -> V_98 , V_95 + ( V_96 / 10 ) ) ;
}
return V_26 ;
}
static int F_114 ( struct V_144 * V_144 , void * V_187 ,
enum V_282 type )
{
struct V_103 * V_104 = V_187 ;
struct V_1 * V_2 = V_104 -> V_2 ;
int V_26 ;
int V_27 ;
V_26 = F_3 ( V_2 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_104 -> type != V_137 &&
V_104 -> type != V_139 )
return - V_116 ;
if ( type != V_104 -> type )
return - V_116 ;
F_51 ( 1 , L_71 ,
V_104 , type , V_104 -> V_134 , V_2 -> V_134 ) ;
if ( V_104 -> type == V_137 ) {
V_2 -> V_93 = 0 ;
F_74 ( & V_2 -> V_94 ) ;
F_76 ( & V_2 -> V_165 , 0 , V_231 , V_283 , 0 ) ;
V_26 = F_55 ( V_2 ) ;
if ( V_26 != 0 )
return V_26 ;
for ( V_27 = 0 ; V_27 < V_224 ; V_27 ++ ) {
if ( F_96 ( V_27 ) . V_235 == NULL )
continue;
( F_96 ( V_27 ) . V_235 ) ( V_2 , 0 ) ;
}
F_115 ( & V_104 -> V_159 ) ;
F_63 ( V_104 , V_138 ) ;
} else if ( V_104 -> type == V_139 ) {
V_2 -> V_97 = 0 ;
F_74 ( & V_2 -> V_98 ) ;
F_115 ( & V_104 -> V_162 ) ;
F_63 ( V_104 , V_140 ) ;
}
return 0 ;
}
static int F_116 ( struct V_144 * V_144 , void * V_187 ,
struct V_284 * V_285 )
{
struct V_103 * V_104 = V_187 ;
struct V_1 * V_2 = V_104 -> V_2 ;
switch ( V_285 -> V_270 . type ) {
case V_286 :
F_76 ( & V_2 -> V_165 , 0 , V_166 , V_287 , V_285 ) ;
return 0 ;
default:
return - V_116 ;
}
}
static int F_117 ( struct V_144 * V_144 , void * V_187 ,
struct V_284 * V_285 )
{
struct V_103 * V_104 = V_187 ;
struct V_1 * V_2 = V_104 -> V_2 ;
switch ( V_285 -> V_270 . type ) {
case V_286 :
F_76 ( & V_2 -> V_165 , 0 , V_166 , V_288 , V_285 ) ;
return 0 ;
default:
return - V_116 ;
}
return 0 ;
}
static int F_118 ( struct V_144 * V_144 , void * V_187 ,
struct V_289 * V_290 )
{
struct V_103 * V_104 = V_187 ;
struct V_1 * V_2 = V_104 -> V_2 ;
int V_26 ;
V_26 = F_3 ( V_2 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_104 -> type == V_137 )
V_26 = F_119 ( & V_104 -> V_159 , V_290 ) ;
else if ( V_104 -> type == V_139 )
V_26 = F_119 ( & V_104 -> V_162 , V_290 ) ;
return V_26 ;
}
static int F_120 ( struct V_144 * V_144 , void * V_187 ,
struct V_291 * V_292 )
{
struct V_103 * V_104 = V_187 ;
struct V_1 * V_2 = V_104 -> V_2 ;
int V_26 ;
V_26 = F_3 ( V_2 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_104 -> type == V_137 )
V_26 = F_121 ( & V_104 -> V_159 , V_292 ) ;
else if ( V_104 -> type == V_139 )
V_26 = F_121 ( & V_104 -> V_162 , V_292 ) ;
return V_26 ;
}
static int F_122 ( struct V_144 * V_144 , void * V_187 , struct V_291 * V_292 )
{
struct V_103 * V_104 = V_187 ;
struct V_1 * V_2 = V_104 -> V_2 ;
int V_26 ;
V_26 = F_3 ( V_2 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_104 -> type == V_137 )
V_26 = F_123 ( & V_104 -> V_159 , V_292 ) ;
else if ( V_104 -> type == V_139 )
V_26 = F_123 ( & V_104 -> V_162 , V_292 ) ;
return V_26 ;
}
static int F_124 ( struct V_144 * V_144 , void * V_187 , struct V_291 * V_292 )
{
struct V_103 * V_104 = V_187 ;
struct V_1 * V_2 = V_104 -> V_2 ;
int V_26 ;
V_26 = F_3 ( V_2 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_2 -> V_83 == 1 ) {
F_51 ( 1 , L_72 ) ;
F_53 ( V_2 ) ;
V_2 -> V_83 = 0 ;
}
if ( V_104 -> type == V_137 )
V_26 = F_125 ( & V_104 -> V_159 , V_292 , V_144 -> V_169 & V_170 ) ;
else if ( V_104 -> type == V_139 )
V_26 = F_125 ( & V_104 -> V_162 , V_292 , V_144 -> V_169 & V_170 ) ;
return V_26 ;
}
int F_126 ( struct V_1 * V_2 ,
struct V_293 * V_294 )
{
int V_295 = - V_50 ;
struct V_296 * V_297 ;
struct V_298 * V_299 ;
int V_27 ;
F_51 ( 1 , L_73 ) ;
V_295 = F_71 ( V_2 -> V_40 ,
V_294 -> V_300 -> V_301 . V_302 , 5 ) ;
if ( V_295 != 0 ) {
F_4 ( V_16 L_74 ) ;
return V_295 ;
}
V_297 = V_294 -> V_300 ;
for ( V_27 = 0 ; V_27 < V_297 -> V_301 . V_303 ; V_27 ++ ) {
V_299 = & V_297 -> V_299 [ V_27 ] . V_301 ;
if ( ( ( V_299 -> V_304 & V_305 )
== V_306 ) &&
( ( V_299 -> V_307 & V_308 )
== V_309 ) ) {
T_7 V_215 = F_127 ( V_299 -> V_310 ) ;
V_2 -> V_44 = ( V_215 & 0x07ff ) *
( ( ( V_215 & 0x1800 ) >> 11 ) + 1 ) ;
V_2 -> V_52 = V_299 -> V_304 ;
}
}
if ( ! ( V_2 -> V_52 ) ) {
F_4 ( V_16 L_75 ) ;
F_16 ( V_2 ) ;
return - V_17 ;
}
F_24 ( & V_2 -> V_168 ) ;
F_128 ( & V_2 -> V_30 ) ;
F_129 ( & V_2 -> V_135 ) ;
F_130 ( & V_2 -> V_24 . V_84 ) ;
F_130 ( & V_2 -> V_24 . V_311 ) ;
F_130 ( & V_2 -> V_88 . V_84 ) ;
F_130 ( & V_2 -> V_88 . V_311 ) ;
V_2 -> V_94 . V_312 = F_66 ;
V_2 -> V_94 . V_141 = ( unsigned long ) V_2 ;
F_131 ( & V_2 -> V_94 ) ;
V_2 -> V_98 . V_312 = F_67 ;
V_2 -> V_98 . V_141 = ( unsigned long ) V_2 ;
F_131 ( & V_2 -> V_98 ) ;
V_2 -> V_79 = V_153 ;
V_2 -> V_106 = V_154 ;
V_2 -> V_156 = V_2 -> V_79 * V_2 -> V_106 ;
V_2 -> V_155 = V_2 -> V_156 << 1 ;
V_2 -> V_78 = V_2 -> V_79 << 1 ;
V_2 -> V_240 = 0 ;
V_2 -> V_131 = F_132 () ;
if ( NULL == V_2 -> V_131 ) {
F_51 ( 1 , L_76 ) ;
return - V_50 ;
}
V_2 -> V_132 = F_132 () ;
if ( NULL == V_2 -> V_132 ) {
F_51 ( 1 , L_77 ) ;
F_16 ( V_2 -> V_131 ) ;
return - V_50 ;
}
* V_2 -> V_131 = V_313 ;
V_2 -> V_131 -> V_314 = & V_2 -> V_40 -> V_2 ;
strcpy ( V_2 -> V_131 -> V_196 , L_78 ) ;
* V_2 -> V_132 = V_313 ;
V_2 -> V_132 -> V_314 = & V_2 -> V_40 -> V_2 ;
strcpy ( V_2 -> V_132 -> V_196 , L_79 ) ;
F_133 ( V_2 -> V_131 , V_2 ) ;
V_295 = F_134 ( V_2 -> V_131 , V_148 , - 1 ) ;
if ( V_295 != 0 ) {
F_51 ( 1 , L_80 ,
V_295 ) ;
F_135 ( V_2 -> V_131 ) ;
return - V_17 ;
}
F_133 ( V_2 -> V_132 , V_2 ) ;
V_295 = F_134 ( V_2 -> V_132 , V_149 , - 1 ) ;
if ( V_295 != 0 ) {
F_51 ( 1 , L_81 ,
V_295 ) ;
F_135 ( V_2 -> V_132 ) ;
F_135 ( V_2 -> V_131 ) ;
return - V_17 ;
}
F_51 ( 1 , L_82 , V_129 ) ;
return 0 ;
}
