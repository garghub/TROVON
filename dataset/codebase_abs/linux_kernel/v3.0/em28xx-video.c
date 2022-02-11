static inline void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
F_2 ( L_1 , V_6 , V_6 -> V_7 . V_8 ) ;
V_6 -> V_7 . V_9 = V_10 ;
V_6 -> V_7 . V_11 ++ ;
F_3 ( & V_6 -> V_7 . V_12 ) ;
V_2 -> V_13 . V_14 = NULL ;
F_4 ( & V_6 -> V_7 . V_15 ) ;
F_5 ( & V_6 -> V_7 . V_16 ) ;
}
static inline void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
F_2 ( L_1 , V_6 , V_6 -> V_7 . V_8 ) ;
V_6 -> V_7 . V_9 = V_10 ;
V_6 -> V_7 . V_11 ++ ;
F_3 ( & V_6 -> V_7 . V_12 ) ;
V_2 -> V_13 . V_17 = NULL ;
F_4 ( & V_6 -> V_7 . V_15 ) ;
F_5 ( & V_6 -> V_7 . V_16 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned char * V_18 ,
unsigned char * V_19 , unsigned long V_20 )
{
void * V_21 , * V_22 , * V_23 ;
int V_24 , V_25 , V_26 , V_27 , V_28 ;
int V_29 = V_2 -> V_30 << 1 ;
if ( V_4 -> V_31 + V_20 > V_6 -> V_7 . V_32 )
V_20 = V_6 -> V_7 . V_32 - V_4 -> V_31 ;
V_23 = V_18 ;
V_28 = V_20 ;
if ( V_2 -> V_33 )
V_21 = V_19 ;
else {
if ( V_6 -> V_34 )
V_21 = V_19 ;
else
V_21 = V_19 + V_29 ;
}
V_24 = V_4 -> V_31 / V_29 ;
V_25 = V_4 -> V_31 % V_29 ;
if ( V_2 -> V_33 )
V_26 = V_24 * V_29 + V_25 ;
else
V_26 = V_24 * V_29 * 2 + V_25 ;
V_22 = V_21 + V_26 ;
V_27 = V_29 - V_25 ;
V_27 = V_27 > V_28 ? V_28 : V_27 ;
if ( ( char * ) V_22 + V_27 > ( char * ) V_19 + V_6 -> V_7 . V_32 ) {
F_2 ( L_2 ,
( ( char * ) V_22 + V_27 ) -
( ( char * ) V_19 + V_6 -> V_7 . V_32 ) ) ;
V_28 = ( char * ) V_19 + V_6 -> V_7 . V_32 - ( char * ) V_22 ;
V_27 = V_28 ;
}
if ( V_27 <= 0 )
return;
memcpy ( V_22 , V_23 , V_27 ) ;
V_28 -= V_27 ;
while ( V_28 > 0 ) {
V_22 += V_27 + V_29 ;
V_23 += V_27 ;
if ( V_29 > V_28 )
V_27 = V_28 ;
else
V_27 = V_29 ;
if ( ( char * ) V_22 + V_27 > ( char * ) V_19 +
V_6 -> V_7 . V_32 ) {
F_2 ( L_3
L_4 ,
( ( char * ) V_22 + V_27 ) -
( ( char * ) V_19 + V_6 -> V_7 . V_32 ) ) ;
V_27 = V_28 = ( char * ) V_19 + V_6 -> V_7 . V_32 -
( char * ) V_22 ;
}
if ( V_27 <= 0 )
break;
memcpy ( V_22 , V_23 , V_27 ) ;
V_28 -= V_27 ;
}
V_4 -> V_31 += V_20 ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned char * V_18 ,
unsigned char * V_19 , unsigned long V_20 )
{
void * V_22 , * V_23 ;
int V_26 ;
int V_29 ;
if ( V_2 == NULL ) {
F_2 ( L_5 ) ;
return;
}
V_29 = V_2 -> V_35 ;
if ( V_4 == NULL ) {
F_2 ( L_6 ) ;
return;
}
if ( V_6 == NULL ) {
return;
}
if ( V_18 == NULL ) {
F_2 ( L_7 ) ;
return;
}
if ( V_19 == NULL ) {
F_2 ( L_8 ) ;
return;
}
if ( V_4 -> V_31 + V_20 > V_6 -> V_7 . V_32 )
V_20 = V_6 -> V_7 . V_32 - V_4 -> V_31 ;
V_23 = V_18 ;
V_22 = V_19 + V_4 -> V_31 ;
V_26 = V_4 -> V_31 ;
if ( V_6 -> V_34 == 0 ) {
V_22 += V_29 * V_2 -> V_36 ;
V_26 += V_29 * V_2 -> V_36 ;
}
memcpy ( V_22 , V_23 , V_20 ) ;
V_4 -> V_31 += V_20 ;
}
static inline void F_9 ( struct V_1 * V_2 ,
int V_37 , int V_38 )
{
char * V_39 = L_9 ;
switch ( V_38 ) {
case - V_40 :
V_39 = L_10 ;
break;
case - V_41 :
V_39 = L_11 ;
break;
case - V_42 :
V_39 = L_12 ;
break;
case - V_43 :
V_39 = L_13 ;
break;
case - V_44 :
V_39 = L_14 ;
break;
case - V_45 :
V_39 = L_15 ;
break;
case - V_46 :
V_39 = L_16 ;
break;
case - V_47 :
V_39 = L_17 ;
break;
}
if ( V_37 < 0 ) {
F_2 ( L_18 , V_38 , V_39 ) ;
} else {
F_2 ( L_19 ,
V_37 , V_38 , V_39 ) ;
}
}
static inline void F_10 ( struct V_3 * V_4 ,
struct V_5 * * V_6 )
{
struct V_1 * V_2 = F_11 ( V_4 , struct V_1 , V_48 ) ;
char * V_19 ;
if ( F_12 ( & V_4 -> V_49 ) ) {
F_2 ( L_20 ) ;
V_2 -> V_13 . V_14 = NULL ;
* V_6 = NULL ;
return;
}
* V_6 = F_13 ( V_4 -> V_49 . V_50 , struct V_5 , V_7 . V_15 ) ;
V_19 = F_14 ( & ( * V_6 ) -> V_7 ) ;
memset ( V_19 , 0 , ( * V_6 ) -> V_7 . V_32 ) ;
V_2 -> V_13 . V_14 = * V_6 ;
return;
}
static inline void F_15 ( struct V_3 * V_4 ,
struct V_5 * * V_6 )
{
struct V_1 * V_2 = F_11 ( V_4 , struct V_1 , V_51 ) ;
char * V_19 ;
if ( F_12 ( & V_4 -> V_49 ) ) {
F_2 ( L_20 ) ;
V_2 -> V_13 . V_17 = NULL ;
* V_6 = NULL ;
return;
}
* V_6 = F_13 ( V_4 -> V_49 . V_50 , struct V_5 , V_7 . V_15 ) ;
V_19 = F_14 ( & ( * V_6 ) -> V_7 ) ;
memset ( V_19 , 0x00 , ( * V_6 ) -> V_7 . V_32 ) ;
V_2 -> V_13 . V_17 = * V_6 ;
return;
}
static inline int F_16 ( struct V_1 * V_2 , struct V_52 * V_52 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 = & V_2 -> V_48 ;
unsigned char * V_19 = NULL ;
int V_8 , V_20 = 0 , V_53 = 1 ;
unsigned char * V_18 ;
if ( ! V_2 )
return 0 ;
if ( ( V_2 -> V_9 & V_54 ) || ( V_2 -> V_9 & V_55 ) )
return 0 ;
if ( V_52 -> V_38 < 0 ) {
F_9 ( V_2 , - 1 , V_52 -> V_38 ) ;
if ( V_52 -> V_38 == - V_40 )
return 0 ;
}
V_6 = V_2 -> V_13 . V_14 ;
if ( V_6 != NULL )
V_19 = F_14 ( & V_6 -> V_7 ) ;
for ( V_8 = 0 ; V_8 < V_52 -> V_56 ; V_8 ++ ) {
int V_38 = V_52 -> V_57 [ V_8 ] . V_38 ;
if ( V_38 < 0 ) {
F_9 ( V_2 , V_8 , V_38 ) ;
if ( V_52 -> V_57 [ V_8 ] . V_38 != - V_45 )
continue;
}
V_20 = V_52 -> V_57 [ V_8 ] . V_58 - 4 ;
if ( V_52 -> V_57 [ V_8 ] . V_58 <= 0 ) {
continue;
}
if ( V_52 -> V_57 [ V_8 ] . V_58 >
V_2 -> V_59 ) {
F_2 ( L_21 ) ;
continue;
}
V_18 = V_52 -> V_60 + V_52 -> V_57 [ V_8 ] . V_26 ;
if ( V_18 [ 0 ] == 0x33 && V_18 [ 1 ] == 0x95 && V_18 [ 2 ] == 0x00 ) {
F_2 ( L_22 ) ;
continue;
}
if ( V_18 [ 0 ] == 0x22 && V_18 [ 1 ] == 0x5a ) {
F_2 ( L_23 , V_18 [ 2 ] ,
V_20 , ( V_18 [ 2 ] & 1 ) ? L_24 : L_25 ) ;
if ( V_2 -> V_33 || ! ( V_18 [ 2 ] & 1 ) ) {
if ( V_6 != NULL )
F_1 ( V_2 , V_4 , V_6 ) ;
F_10 ( V_4 , & V_6 ) ;
if ( V_6 == NULL )
V_19 = NULL ;
else
V_19 = F_14 ( & V_6 -> V_7 ) ;
}
if ( V_6 != NULL ) {
if ( V_18 [ 2 ] & 1 )
V_6 -> V_34 = 0 ;
else
V_6 -> V_34 = 1 ;
}
V_4 -> V_31 = 0 ;
}
if ( V_6 != NULL ) {
if ( V_18 [ 0 ] != 0x88 && V_18 [ 0 ] != 0x22 ) {
F_2 ( L_26 ) ;
V_20 += 4 ;
} else {
V_18 += 4 ;
}
F_7 ( V_2 , V_4 , V_6 , V_18 , V_19 , V_20 ) ;
}
}
return V_53 ;
}
static inline int F_17 ( struct V_1 * V_2 , struct V_52 * V_52 )
{
struct V_5 * V_6 , * V_17 ;
struct V_3 * V_4 = & V_2 -> V_48 ;
struct V_3 * V_61 = & V_2 -> V_51 ;
unsigned char * V_19 = NULL ;
unsigned char * V_62 = NULL ;
int V_8 , V_20 = 0 , V_53 = 1 ;
unsigned char * V_18 ;
int V_63 ;
if ( ! V_2 )
return 0 ;
if ( ( V_2 -> V_9 & V_54 ) || ( V_2 -> V_9 & V_55 ) )
return 0 ;
if ( V_52 -> V_38 < 0 ) {
F_9 ( V_2 , - 1 , V_52 -> V_38 ) ;
if ( V_52 -> V_38 == - V_40 )
return 0 ;
}
V_6 = V_2 -> V_13 . V_14 ;
if ( V_6 != NULL )
V_19 = F_14 ( & V_6 -> V_7 ) ;
V_17 = V_2 -> V_13 . V_17 ;
if ( V_17 != NULL )
V_62 = F_14 ( & V_17 -> V_7 ) ;
for ( V_8 = 0 ; V_8 < V_52 -> V_56 ; V_8 ++ ) {
int V_38 = V_52 -> V_57 [ V_8 ] . V_38 ;
if ( V_38 < 0 ) {
F_9 ( V_2 , V_8 , V_38 ) ;
if ( V_52 -> V_57 [ V_8 ] . V_38 != - V_45 )
continue;
}
V_20 = V_52 -> V_57 [ V_8 ] . V_58 ;
if ( V_52 -> V_57 [ V_8 ] . V_58 <= 0 ) {
continue;
}
if ( V_52 -> V_57 [ V_8 ] . V_58 >
V_2 -> V_59 ) {
F_2 ( L_21 ) ;
continue;
}
V_18 = V_52 -> V_60 + V_52 -> V_57 [ V_8 ] . V_26 ;
if ( V_18 [ 0 ] == 0x33 && V_18 [ 1 ] == 0x95 ) {
V_2 -> V_64 = 0 ;
V_2 -> V_65 = 0 ;
F_2 ( L_27 ) ;
V_2 -> V_66 = V_18 [ 2 ] ;
V_18 += 4 ;
V_20 -= 4 ;
} else if ( V_18 [ 0 ] == 0x88 && V_18 [ 1 ] == 0x88 &&
V_18 [ 2 ] == 0x88 && V_18 [ 3 ] == 0x88 ) {
V_18 += 4 ;
V_20 -= 4 ;
} else if ( V_18 [ 0 ] == 0x22 && V_18 [ 1 ] == 0x5a ) {
V_18 += 4 ;
V_20 -= 4 ;
}
V_63 = V_2 -> V_35 * V_2 -> V_36 ;
if ( V_2 -> V_64 == 0 ) {
if ( V_2 -> V_65 >= V_63 ) {
F_2 ( L_28 ) ;
} else if ( ( V_2 -> V_65 + V_20 ) < V_63 ) {
if ( V_2 -> V_65 == 0 &&
( ! ( V_2 -> V_66 & 1 ) ) ) {
if ( V_17 != NULL )
F_6 ( V_2 ,
V_61 ,
V_17 ) ;
F_15 ( V_61 , & V_17 ) ;
if ( V_17 == NULL )
V_62 = NULL ;
else
V_62 = F_14 (
& V_17 -> V_7 ) ;
}
if ( V_2 -> V_65 == 0 ) {
V_61 -> V_31 = 0 ;
if ( V_17 != NULL ) {
if ( V_2 -> V_66 & 1 )
V_17 -> V_34 = 0 ;
else
V_17 -> V_34 = 1 ;
}
}
V_2 -> V_65 += V_20 ;
F_8 ( V_2 , V_61 , V_17 , V_18 ,
V_62 , V_20 ) ;
} else {
int V_67 = V_63 - V_2 -> V_65 ;
V_2 -> V_65 += V_67 ;
F_8 ( V_2 , V_61 , V_17 , V_18 ,
V_62 , V_67 ) ;
V_2 -> V_64 = 1 ;
V_18 += V_67 ;
V_20 -= V_67 ;
}
}
if ( V_2 -> V_64 == 1 ) {
V_2 -> V_64 = 2 ;
if ( V_2 -> V_33 || ! ( V_2 -> V_66 & 1 ) ) {
if ( V_6 != NULL )
F_1 ( V_2 , V_4 , V_6 ) ;
F_10 ( V_4 , & V_6 ) ;
if ( V_6 == NULL )
V_19 = NULL ;
else
V_19 = F_14 ( & V_6 -> V_7 ) ;
}
if ( V_6 != NULL ) {
if ( V_2 -> V_66 & 1 )
V_6 -> V_34 = 0 ;
else
V_6 -> V_34 = 1 ;
}
V_4 -> V_31 = 0 ;
}
if ( V_6 != NULL && V_2 -> V_64 == 2 ) {
if ( V_20 >= 4 && V_18 [ 0 ] == 0x88 && V_18 [ 1 ] == 0x88 &&
V_18 [ 2 ] == 0x88 && V_18 [ 3 ] == 0x88 ) {
V_18 += 4 ;
V_20 -= 4 ;
}
if ( V_20 >= 4 && V_18 [ 0 ] == 0x22 && V_18 [ 1 ] == 0x5a ) {
F_2 ( L_29 ,
V_18 [ 2 ] , V_20 , ( V_18 [ 2 ] & 1 ) ?
L_24 : L_25 ) ;
V_18 += 4 ;
V_20 -= 4 ;
}
if ( V_20 > 0 )
F_7 ( V_2 , V_4 , V_6 , V_18 , V_19 ,
V_20 ) ;
}
}
return V_53 ;
}
static int
F_18 ( struct V_68 * V_69 , unsigned int * V_70 , unsigned int * V_32 )
{
struct V_71 * V_72 = V_69 -> V_73 ;
struct V_1 * V_2 = V_72 -> V_2 ;
struct V_74 V_75 ;
* V_32 = ( V_72 -> V_2 -> V_30 * V_72 -> V_2 -> V_76 * V_2 -> V_77 -> V_78 + 7 )
>> 3 ;
if ( 0 == * V_70 )
* V_70 = V_79 ;
if ( * V_70 < V_80 )
* V_70 = V_80 ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_75 . V_81 = V_2 -> V_82 ;
V_75 . type = V_72 -> V_83 ? V_84 : V_85 ;
F_19 ( & V_2 -> V_86 , 0 , V_87 , V_88 , & V_75 ) ;
return 0 ;
}
static void F_20 ( struct V_68 * V_69 , struct V_5 * V_6 )
{
struct V_71 * V_72 = V_69 -> V_73 ;
struct V_1 * V_2 = V_72 -> V_2 ;
unsigned long V_89 = 0 ;
if ( F_21 () )
F_22 () ;
F_23 ( & V_2 -> V_90 , V_89 ) ;
if ( V_2 -> V_13 . V_14 == V_6 )
V_2 -> V_13 . V_14 = NULL ;
F_24 ( & V_2 -> V_90 , V_89 ) ;
F_25 ( & V_6 -> V_7 ) ;
V_6 -> V_7 . V_9 = V_91 ;
}
static int
F_26 ( struct V_68 * V_69 , struct V_92 * V_7 ,
enum V_93 V_94 )
{
struct V_71 * V_72 = V_69 -> V_73 ;
struct V_5 * V_6 = F_11 ( V_7 , struct V_5 , V_7 ) ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 = 0 , V_95 = 0 ;
V_6 -> V_7 . V_32 = ( V_72 -> V_2 -> V_30 * V_72 -> V_2 -> V_76 * V_2 -> V_77 -> V_78
+ 7 ) >> 3 ;
if ( 0 != V_6 -> V_7 . V_96 && V_6 -> V_7 . V_97 < V_6 -> V_7 . V_32 )
return - V_98 ;
V_6 -> V_7 . V_30 = V_2 -> V_30 ;
V_6 -> V_7 . V_76 = V_2 -> V_76 ;
V_6 -> V_7 . V_94 = V_94 ;
if ( V_91 == V_6 -> V_7 . V_9 ) {
V_53 = F_27 ( V_69 , & V_6 -> V_7 , NULL ) ;
if ( V_53 < 0 )
goto V_99;
}
if ( ! V_2 -> V_13 . V_100 )
V_95 = 1 ;
if ( V_95 ) {
if ( F_28 ( V_2 ) == 1 )
V_53 = F_29 ( V_2 , V_101 ,
V_102 ,
V_2 -> V_59 ,
F_17 ) ;
else
V_53 = F_29 ( V_2 , V_101 ,
V_102 ,
V_2 -> V_59 ,
F_16 ) ;
if ( V_53 < 0 )
goto V_99;
}
V_6 -> V_7 . V_9 = V_103 ;
return 0 ;
V_99:
F_20 ( V_69 , V_6 ) ;
return V_53 ;
}
static void
F_30 ( struct V_68 * V_69 , struct V_92 * V_7 )
{
struct V_5 * V_6 = F_11 ( V_7 ,
struct V_5 ,
V_7 ) ;
struct V_71 * V_72 = V_69 -> V_73 ;
struct V_1 * V_2 = V_72 -> V_2 ;
struct V_3 * V_48 = & V_2 -> V_48 ;
V_6 -> V_7 . V_9 = V_104 ;
F_31 ( & V_6 -> V_7 . V_15 , & V_48 -> V_49 ) ;
}
static void F_32 ( struct V_68 * V_69 ,
struct V_92 * V_7 )
{
struct V_5 * V_6 = F_11 ( V_7 ,
struct V_5 ,
V_7 ) ;
struct V_71 * V_72 = V_69 -> V_73 ;
struct V_1 * V_2 = (struct V_1 * ) V_72 -> V_2 ;
F_2 ( L_30 ) ;
F_20 ( V_69 , V_6 ) ;
}
static void F_33 ( struct V_1 * V_2 , int V_105 )
{
V_2 -> V_106 = V_105 ;
V_2 -> V_107 = F_34 ( V_105 ) -> V_108 ;
V_2 -> V_109 = F_34 ( V_105 ) -> V_110 ;
if ( ! V_2 -> V_109 )
V_2 -> V_109 = V_111 ;
F_19 ( & V_2 -> V_86 , 0 , V_112 , V_113 ,
F_34 ( V_105 ) -> V_114 , 0 , 0 ) ;
if ( V_2 -> V_115 . V_116 ) {
if ( V_2 -> V_117 ) {
F_19 ( & V_2 -> V_86 , 0 , V_118 ,
V_119 , V_2 -> V_117 ) ;
}
F_19 ( & V_2 -> V_86 , 0 , V_118 , V_113 ,
V_2 -> V_107 , F_35 ( V_120 ) , 0 ) ;
}
if ( V_2 -> V_115 . V_121 != V_122 ) {
F_19 ( & V_2 -> V_86 , 0 , V_118 , V_113 ,
V_2 -> V_107 , V_2 -> V_109 , 0 ) ;
}
F_36 ( V_2 ) ;
}
static int F_37 ( struct V_71 * V_72 , unsigned int V_123 )
{
struct V_1 * V_2 = V_72 -> V_2 ;
if ( V_72 -> V_124 & V_123 )
return 1 ;
if ( V_2 -> V_124 & V_123 ) {
return 0 ;
}
V_72 -> V_124 |= V_123 ;
V_2 -> V_124 |= V_123 ;
F_38 ( L_31 , V_123 ) ;
return 1 ;
}
static int F_39 ( struct V_71 * V_72 , unsigned int V_123 )
{
return V_72 -> V_124 & V_123 ;
}
static int F_40 ( struct V_1 * V_2 , unsigned int V_123 )
{
return V_2 -> V_124 & V_123 ;
}
static void F_41 ( struct V_71 * V_72 , unsigned int V_125 )
{
struct V_1 * V_2 = V_72 -> V_2 ;
F_42 ( ( V_72 -> V_124 & V_125 ) != V_125 ) ;
V_72 -> V_124 &= ~ V_125 ;
V_2 -> V_124 &= ~ V_125 ;
F_38 ( L_32 , V_125 ) ;
}
static int F_43 ( struct V_71 * V_72 )
{
switch ( V_72 -> type ) {
case V_126 :
return V_127 ;
case V_128 :
return V_129 ;
default:
F_22 () ;
return 0 ;
}
}
static int F_44 ( struct V_130 * V_131 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < F_45 ( V_132 ) ; V_8 ++ ) {
if ( V_131 -> V_133 && V_131 -> V_133 == V_132 [ V_8 ] . V_133 ) {
memcpy ( V_131 , & ( V_132 [ V_8 ] ) , sizeof( * V_131 ) ) ;
return 0 ;
}
}
return 1 ;
}
static int F_46 ( struct V_1 * V_2 , struct V_134 * V_135 )
{
switch ( V_135 -> V_133 ) {
case V_136 :
V_135 -> V_137 = V_2 -> V_138 ;
return 0 ;
case V_139 :
V_135 -> V_137 = V_2 -> V_140 ;
return 0 ;
default:
return 1 ;
}
}
static int F_47 ( struct V_1 * V_2 , const struct V_134 * V_135 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < F_45 ( V_132 ) ; V_8 ++ )
if ( V_135 -> V_133 == V_132 [ V_8 ] . V_133 )
goto V_141;
return 1 ;
V_141:
if ( V_135 -> V_137 < V_132 [ V_8 ] . V_142 ||
V_135 -> V_137 > V_132 [ V_8 ] . V_143 )
return - V_144 ;
switch ( V_135 -> V_133 ) {
case V_136 :
V_2 -> V_138 = V_135 -> V_137 ;
break;
case V_139 :
V_2 -> V_140 = V_135 -> V_137 ;
break;
}
return F_36 ( V_2 ) ;
}
static int F_48 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 & V_54 ) {
F_49 ( L_33 ) ;
return - V_145 ;
}
if ( V_2 -> V_9 & V_55 ) {
F_49 ( L_34
L_35 ) ;
return - V_146 ;
}
return 0 ;
}
static void F_50 ( struct V_1 * V_2 ,
unsigned int V_30 , unsigned int V_76 ,
unsigned int * V_147 , unsigned int * V_148 )
{
unsigned int V_149 = F_51 ( V_2 ) ;
unsigned int V_150 = F_52 ( V_2 ) ;
* V_147 = ( ( ( unsigned long ) V_149 ) << 12 ) / V_30 - 4096L ;
if ( * V_147 >= 0x4000 )
* V_147 = 0x3fff ;
* V_148 = ( ( ( unsigned long ) V_150 ) << 12 ) / V_76 - 4096L ;
if ( * V_148 >= 0x4000 )
* V_148 = 0x3fff ;
}
static int F_53 ( struct V_151 * V_151 , void * V_152 ,
struct V_153 * V_75 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
V_75 -> V_154 . V_155 . V_30 = V_2 -> V_30 ;
V_75 -> V_154 . V_155 . V_76 = V_2 -> V_76 ;
V_75 -> V_154 . V_155 . V_156 = V_2 -> V_77 -> V_157 ;
V_75 -> V_154 . V_155 . V_29 = ( V_2 -> V_30 * V_2 -> V_77 -> V_78 + 7 ) >> 3 ;
V_75 -> V_154 . V_155 . V_158 = V_75 -> V_154 . V_155 . V_29 * V_2 -> V_76 ;
V_75 -> V_154 . V_155 . V_159 = V_160 ;
if ( V_2 -> V_33 )
V_75 -> V_154 . V_155 . V_94 = V_161 ;
else
V_75 -> V_154 . V_155 . V_94 = V_2 -> V_162 ?
V_163 : V_164 ;
return 0 ;
}
static struct V_165 * F_54 ( unsigned int V_157 )
{
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < F_45 ( V_77 ) ; V_8 ++ )
if ( V_77 [ V_8 ] . V_157 == V_157 )
return & V_77 [ V_8 ] ;
return NULL ;
}
static int F_55 ( struct V_151 * V_151 , void * V_152 ,
struct V_153 * V_75 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
unsigned int V_30 = V_75 -> V_154 . V_155 . V_30 ;
unsigned int V_76 = V_75 -> V_154 . V_155 . V_76 ;
unsigned int V_149 = F_51 ( V_2 ) ;
unsigned int V_150 = F_52 ( V_2 ) ;
unsigned int V_147 , V_148 ;
struct V_165 * V_154 ;
V_154 = F_54 ( V_75 -> V_154 . V_155 . V_156 ) ;
if ( ! V_154 ) {
F_38 ( L_36 ,
V_75 -> V_154 . V_155 . V_156 ) ;
return - V_98 ;
}
if ( V_2 -> V_115 . V_166 ) {
V_76 = V_76 > ( 3 * V_150 / 4 ) ? V_150 : V_150 / 2 ;
V_30 = V_30 > ( 3 * V_149 / 4 ) ? V_149 : V_149 / 2 ;
} else {
F_56 ( & V_30 , 48 , V_149 , 1 , & V_76 , 32 , V_150 ,
1 , 0 ) ;
}
F_50 ( V_2 , V_30 , V_76 , & V_147 , & V_148 ) ;
V_30 = ( ( ( unsigned long ) V_149 ) << 12 ) / ( V_147 + 4096L ) ;
V_76 = ( ( ( unsigned long ) V_150 ) << 12 ) / ( V_148 + 4096L ) ;
V_75 -> V_154 . V_155 . V_30 = V_30 ;
V_75 -> V_154 . V_155 . V_76 = V_76 ;
V_75 -> V_154 . V_155 . V_156 = V_154 -> V_157 ;
V_75 -> V_154 . V_155 . V_29 = ( V_2 -> V_30 * V_154 -> V_78 + 7 ) >> 3 ;
V_75 -> V_154 . V_155 . V_158 = V_75 -> V_154 . V_155 . V_29 * V_76 ;
V_75 -> V_154 . V_155 . V_159 = V_160 ;
if ( V_2 -> V_33 )
V_75 -> V_154 . V_155 . V_94 = V_161 ;
else
V_75 -> V_154 . V_155 . V_94 = V_2 -> V_162 ?
V_163 : V_164 ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , unsigned int V_157 ,
unsigned V_30 , unsigned V_76 )
{
struct V_165 * V_154 ;
V_154 = F_54 ( V_157 ) ;
if ( ! V_154 )
return - V_98 ;
V_2 -> V_77 = V_154 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_76 = V_76 ;
F_50 ( V_2 , V_2 -> V_30 , V_2 -> V_76 , & V_2 -> V_147 , & V_2 -> V_148 ) ;
F_58 ( V_2 ) ;
F_59 ( V_2 ) ;
return 0 ;
}
static int F_60 ( struct V_151 * V_151 , void * V_152 ,
struct V_153 * V_75 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
F_55 ( V_151 , V_152 , V_75 ) ;
if ( F_61 ( & V_72 -> V_167 ) ) {
F_49 ( L_37 , V_168 ) ;
return - V_169 ;
}
return F_57 ( V_2 , V_75 -> V_154 . V_155 . V_156 ,
V_75 -> V_154 . V_155 . V_30 , V_75 -> V_154 . V_155 . V_76 ) ;
}
static int F_62 ( struct V_151 * V_151 , void * V_152 , T_1 * V_170 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
* V_170 = V_2 -> V_170 ;
return 0 ;
}
static int F_63 ( struct V_151 * V_151 , void * V_152 , T_1 * V_170 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
struct V_153 V_75 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
V_2 -> V_170 = * V_170 ;
V_75 . V_154 . V_155 . V_30 = V_2 -> V_30 ;
V_75 . V_154 . V_155 . V_76 = V_2 -> V_76 ;
F_55 ( V_151 , V_152 , & V_75 ) ;
V_2 -> V_30 = V_75 . V_154 . V_155 . V_30 ;
V_2 -> V_76 = V_75 . V_154 . V_155 . V_76 ;
F_50 ( V_2 , V_2 -> V_30 , V_2 -> V_76 , & V_2 -> V_147 , & V_2 -> V_148 ) ;
F_59 ( V_2 ) ;
F_19 ( & V_2 -> V_86 , 0 , V_171 , V_172 , V_2 -> V_170 ) ;
return 0 ;
}
static int F_64 ( struct V_151 * V_151 , void * V_152 ,
struct V_173 * V_18 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 = 0 ;
if ( V_18 -> type != V_126 )
return - V_98 ;
if ( V_2 -> V_115 . V_174 )
V_53 = F_65 ( & V_2 -> V_86 , 0 ,
V_112 , V_175 , V_18 ) ;
else
F_66 ( V_2 -> V_170 ,
& V_18 -> V_176 . V_177 . V_178 ) ;
return V_53 ;
}
static int F_67 ( struct V_151 * V_151 , void * V_152 ,
struct V_173 * V_18 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
if ( ! V_2 -> V_115 . V_174 )
return - V_98 ;
if ( V_18 -> type != V_126 )
return - V_98 ;
return F_65 ( & V_2 -> V_86 , 0 , V_112 , V_179 , V_18 ) ;
}
static int F_68 ( struct V_151 * V_151 , void * V_152 ,
struct V_180 * V_8 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
unsigned int V_181 ;
V_181 = V_8 -> V_105 ;
if ( V_181 >= V_182 )
return - V_98 ;
if ( 0 == F_34 ( V_181 ) -> type )
return - V_98 ;
V_8 -> V_105 = V_181 ;
V_8 -> type = V_183 ;
strcpy ( V_8 -> V_184 , V_185 [ F_34 ( V_181 ) -> type ] ) ;
if ( ( V_186 == F_34 ( V_181 ) -> type ) ||
( V_187 == F_34 ( V_181 ) -> type ) )
V_8 -> type = V_188 ;
V_8 -> V_189 = V_2 -> V_190 -> V_191 ;
return 0 ;
}
static int F_69 ( struct V_151 * V_151 , void * V_152 , unsigned int * V_8 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
* V_8 = V_2 -> V_106 ;
return 0 ;
}
static int F_70 ( struct V_151 * V_151 , void * V_152 , unsigned int V_8 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_8 >= V_182 )
return - V_98 ;
if ( 0 == F_34 ( V_8 ) -> type )
return - V_98 ;
V_2 -> V_106 = V_8 ;
F_33 ( V_2 , V_2 -> V_106 ) ;
return 0 ;
}
static int F_71 ( struct V_151 * V_151 , void * V_152 , struct V_192 * V_193 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
if ( ! V_2 -> V_194 . V_195 )
return - V_98 ;
switch ( V_193 -> V_105 ) {
case V_196 :
strcpy ( V_193 -> V_184 , L_38 ) ;
break;
case V_197 :
strcpy ( V_193 -> V_184 , L_39 ) ;
break;
case V_198 :
strcpy ( V_193 -> V_184 , L_40 ) ;
break;
case V_199 :
strcpy ( V_193 -> V_184 , L_41 ) ;
break;
case V_200 :
strcpy ( V_193 -> V_184 , L_42 ) ;
break;
case V_201 :
strcpy ( V_193 -> V_184 , L_43 ) ;
break;
case V_202 :
strcpy ( V_193 -> V_184 , L_44 ) ;
break;
case V_203 :
strcpy ( V_193 -> V_184 , L_45 ) ;
break;
default:
return - V_98 ;
}
V_193 -> V_105 = V_2 -> V_107 ;
V_193 -> V_204 = V_205 ;
return 0 ;
}
static int F_72 ( struct V_151 * V_151 , void * V_152 , struct V_192 * V_193 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
if ( ! V_2 -> V_194 . V_195 )
return - V_98 ;
if ( V_193 -> V_105 >= V_182 )
return - V_98 ;
if ( 0 == F_34 ( V_193 -> V_105 ) -> type )
return - V_98 ;
V_2 -> V_107 = F_34 ( V_193 -> V_105 ) -> V_108 ;
V_2 -> V_109 = F_34 ( V_193 -> V_105 ) -> V_110 ;
if ( ! V_2 -> V_109 )
V_2 -> V_109 = V_111 ;
return 0 ;
}
static int F_73 ( struct V_151 * V_151 , void * V_152 ,
struct V_130 * V_131 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_133 = V_131 -> V_133 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
memset ( V_131 , 0 , sizeof( * V_131 ) ) ;
V_131 -> V_133 = V_133 ;
if ( V_2 -> V_194 . V_206 != V_207 ) {
V_53 = F_44 ( V_131 ) ;
if ( ! V_53 )
return 0 ;
}
F_19 ( & V_2 -> V_86 , 0 , V_171 , V_208 , V_131 ) ;
if ( V_131 -> type )
return 0 ;
else
return - V_98 ;
}
static int F_74 ( struct V_1 * V_2 , int V_133 )
{
struct V_130 V_131 ;
memset ( & V_131 , 0 , sizeof( V_131 ) ) ;
V_131 . V_133 = V_133 ;
F_19 ( & V_2 -> V_86 , 0 , V_171 , V_208 , & V_131 ) ;
if ( V_131 . type )
return 0 ;
else
return - V_98 ;
}
static int F_75 ( struct V_151 * V_151 , void * V_152 ,
struct V_134 * V_135 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
V_53 = 0 ;
if ( V_2 -> V_194 . V_206 != V_207 )
V_53 = F_46 ( V_2 , V_135 ) ;
else
V_53 = 1 ;
if ( V_53 == 1 ) {
if ( F_74 ( V_2 , V_135 -> V_133 ) )
return - V_98 ;
F_19 ( & V_2 -> V_86 , 0 , V_171 , V_209 , V_135 ) ;
V_53 = 0 ;
}
return V_53 ;
}
static int F_76 ( struct V_151 * V_151 , void * V_152 ,
struct V_134 * V_135 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_2 -> V_194 . V_206 != V_207 )
V_53 = F_47 ( V_2 , V_135 ) ;
else
V_53 = 1 ;
if ( V_53 == 1 ) {
V_53 = F_74 ( V_2 , V_135 -> V_133 ) ;
if ( ! V_53 )
F_19 ( & V_2 -> V_86 , 0 ,
V_171 , V_210 , V_135 ) ;
switch ( V_135 -> V_133 ) {
case V_136 :
V_2 -> V_138 = V_135 -> V_137 ;
V_53 = F_36 ( V_2 ) ;
break;
case V_139 :
V_2 -> V_140 = V_135 -> V_137 ;
V_53 = F_36 ( V_2 ) ;
}
}
return ( V_53 < 0 ) ? V_53 : 0 ;
}
static int F_77 ( struct V_151 * V_151 , void * V_152 ,
struct V_211 * V_212 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( 0 != V_212 -> V_105 )
return - V_98 ;
strcpy ( V_212 -> V_184 , L_46 ) ;
V_212 -> type = V_85 ;
F_19 ( & V_2 -> V_86 , 0 , V_87 , V_213 , V_212 ) ;
return 0 ;
}
static int F_78 ( struct V_151 * V_151 , void * V_152 ,
struct V_211 * V_212 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( 0 != V_212 -> V_105 )
return - V_98 ;
F_19 ( & V_2 -> V_86 , 0 , V_87 , V_214 , V_212 ) ;
return 0 ;
}
static int F_79 ( struct V_151 * V_151 , void * V_152 ,
struct V_74 * V_75 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
V_75 -> type = V_72 -> V_83 ? V_84 : V_85 ;
V_75 -> V_81 = V_2 -> V_82 ;
return 0 ;
}
static int F_80 ( struct V_151 * V_151 , void * V_152 ,
struct V_74 * V_75 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( 0 != V_75 -> V_87 )
return - V_98 ;
if ( F_81 ( 0 == V_72 -> V_83 && V_75 -> type != V_85 ) )
return - V_98 ;
if ( F_81 ( 1 == V_72 -> V_83 && V_75 -> type != V_84 ) )
return - V_98 ;
V_2 -> V_82 = V_75 -> V_81 ;
F_19 ( & V_2 -> V_86 , 0 , V_87 , V_88 , V_75 ) ;
return 0 ;
}
static int F_82 ( int V_215 )
{
switch ( V_215 ) {
case V_216 :
case V_217 :
case V_218 :
return 2 ;
default:
return 1 ;
}
}
static int F_83 ( struct V_151 * V_151 , void * V_152 ,
struct V_219 * V_220 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
V_220 -> V_221 = V_222 ;
V_220 -> V_223 = 0 ;
F_19 ( & V_2 -> V_86 , 0 , V_171 , V_224 , V_220 ) ;
return 0 ;
}
static int F_84 ( struct V_151 * V_151 , void * V_152 ,
struct V_225 * V_215 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_226 ;
switch ( V_215 -> V_227 . type ) {
case V_228 :
V_226 = F_85 ( V_2 , V_215 -> V_215 ) ;
if ( V_226 < 0 )
return V_226 ;
V_215 -> V_229 = V_226 ;
V_215 -> V_32 = 1 ;
return 0 ;
case V_230 :
F_19 ( & V_2 -> V_86 , 0 , V_171 , V_231 , V_215 ) ;
return 0 ;
case V_232 :
F_19 ( & V_2 -> V_86 , 0 , V_171 , V_231 , V_215 ) ;
return 0 ;
default:
if ( ! F_86 ( & V_215 -> V_227 ) )
return - V_98 ;
}
V_215 -> V_32 = F_82 ( V_215 -> V_215 ) ;
if ( V_215 -> V_32 == 1 ) {
V_226 = F_87 ( V_2 , V_215 -> V_215 ) ;
if ( V_226 < 0 )
return V_226 ;
V_215 -> V_229 = V_226 ;
} else {
T_2 V_229 = 0 ;
V_226 = F_88 ( V_2 , V_233 ,
V_215 -> V_215 , ( char * ) & V_229 , 2 ) ;
if ( V_226 < 0 )
return V_226 ;
V_215 -> V_229 = F_89 ( V_229 ) ;
}
return 0 ;
}
static int F_90 ( struct V_151 * V_151 , void * V_152 ,
struct V_225 * V_215 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
T_2 V_6 ;
switch ( V_215 -> V_227 . type ) {
case V_228 :
return F_91 ( V_2 , V_215 -> V_215 , V_215 -> V_229 ) ;
case V_230 :
F_19 ( & V_2 -> V_86 , 0 , V_171 , V_234 , V_215 ) ;
return 0 ;
case V_232 :
F_19 ( & V_2 -> V_86 , 0 , V_171 , V_234 , V_215 ) ;
return 0 ;
default:
if ( ! F_86 ( & V_215 -> V_227 ) )
return - V_98 ;
}
V_6 = F_92 ( V_215 -> V_229 ) ;
return F_93 ( V_2 , V_215 -> V_215 , ( char * ) & V_6 ,
F_82 ( V_215 -> V_215 ) ) ;
}
static int F_94 ( struct V_151 * V_151 , void * V_152 ,
struct V_235 * V_236 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
if ( V_236 -> type != V_126 )
return - V_98 ;
V_236 -> V_237 . V_238 = 0 ;
V_236 -> V_237 . V_239 = 0 ;
V_236 -> V_237 . V_30 = V_2 -> V_30 ;
V_236 -> V_237 . V_76 = V_2 -> V_76 ;
V_236 -> V_240 = V_236 -> V_237 ;
V_236 -> V_241 . V_242 = 54 ;
V_236 -> V_241 . V_243 = 59 ;
return 0 ;
}
static int F_95 ( struct V_151 * V_151 , void * V_152 ,
enum V_244 type )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 = - V_98 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( F_81 ( type != V_72 -> type ) )
return - V_98 ;
F_38 ( L_47 ,
V_72 , type , V_72 -> V_124 , V_2 -> V_124 ) ;
if ( F_81 ( ! F_37 ( V_72 , F_43 ( V_72 ) ) ) )
return - V_169 ;
if ( V_72 -> type == V_126 )
V_53 = F_96 ( & V_72 -> V_167 ) ;
else if ( V_72 -> type == V_128 )
V_53 = F_96 ( & V_72 -> V_245 ) ;
return V_53 ;
}
static int F_97 ( struct V_151 * V_151 , void * V_152 ,
enum V_244 type )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_72 -> type != V_126 &&
V_72 -> type != V_128 )
return - V_98 ;
if ( type != V_72 -> type )
return - V_98 ;
F_38 ( L_48 ,
V_72 , type , V_72 -> V_124 , V_2 -> V_124 ) ;
if ( V_72 -> type == V_126 ) {
if ( F_39 ( V_72 , V_127 ) ) {
F_98 ( & V_72 -> V_167 ) ;
F_41 ( V_72 , V_127 ) ;
}
} else if ( V_72 -> type == V_128 ) {
if ( F_39 ( V_72 , V_129 ) ) {
F_98 ( & V_72 -> V_245 ) ;
F_41 ( V_72 , V_129 ) ;
}
}
return 0 ;
}
static int F_99 ( struct V_151 * V_151 , void * V_152 ,
struct V_246 * V_247 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
F_100 ( V_247 -> V_248 , L_49 , sizeof( V_247 -> V_248 ) ) ;
F_100 ( V_247 -> V_249 , V_250 [ V_2 -> V_251 ] . V_184 , sizeof( V_247 -> V_249 ) ) ;
F_101 ( V_2 -> V_252 , V_247 -> V_253 , sizeof( V_247 -> V_253 ) ) ;
V_247 -> V_254 = V_255 ;
V_247 -> V_256 =
V_257 |
V_258 |
V_259 | V_260 ;
if ( V_2 -> V_261 )
V_247 -> V_256 |= V_262 ;
if ( V_2 -> V_194 . V_195 )
V_247 -> V_256 |= V_263 ;
if ( V_2 -> V_264 != V_265 )
V_247 -> V_256 |= V_266 ;
return 0 ;
}
static int F_102 ( struct V_151 * V_151 , void * V_152 ,
struct V_267 * V_75 )
{
if ( F_81 ( V_75 -> V_105 >= F_45 ( V_77 ) ) )
return - V_98 ;
F_100 ( V_75 -> V_268 , V_77 [ V_75 -> V_105 ] . V_184 , sizeof( V_75 -> V_268 ) ) ;
V_75 -> V_156 = V_77 [ V_75 -> V_105 ] . V_157 ;
return 0 ;
}
static int F_103 ( struct V_151 * V_151 , void * V_152 ,
struct V_153 * V_75 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
V_75 -> V_154 . V_269 . V_270 = 0 ;
F_19 ( & V_2 -> V_86 , 0 , V_271 , V_272 , & V_75 -> V_154 . V_269 ) ;
if ( V_75 -> V_154 . V_269 . V_270 == 0 )
V_53 = - V_98 ;
return V_53 ;
}
static int F_104 ( struct V_151 * V_151 , void * V_152 ,
struct V_153 * V_75 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
F_19 ( & V_2 -> V_86 , 0 , V_271 , V_272 , & V_75 -> V_154 . V_269 ) ;
if ( V_75 -> V_154 . V_269 . V_270 == 0 )
return - V_98 ;
return 0 ;
}
static int F_105 ( struct V_151 * V_151 , void * V_152 ,
struct V_153 * V_77 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
V_77 -> V_154 . V_271 . V_273 = V_2 -> V_35 ;
V_77 -> V_154 . V_271 . V_274 = V_275 ;
V_77 -> V_154 . V_271 . V_26 = 0 ;
V_77 -> V_154 . V_271 . V_89 = 0 ;
V_77 -> V_154 . V_271 . V_276 = 6750000 * 4 / 2 ;
V_77 -> V_154 . V_271 . V_70 [ 0 ] = V_2 -> V_36 ;
V_77 -> V_154 . V_271 . V_70 [ 1 ] = V_2 -> V_36 ;
if ( V_2 -> V_170 & V_277 ) {
V_77 -> V_154 . V_271 . V_278 [ 0 ] = 10 ;
V_77 -> V_154 . V_271 . V_278 [ 1 ] = 273 ;
} else if ( V_2 -> V_170 & V_279 ) {
V_77 -> V_154 . V_271 . V_278 [ 0 ] = 6 ;
V_77 -> V_154 . V_271 . V_278 [ 1 ] = 318 ;
}
return 0 ;
}
static int F_106 ( struct V_151 * V_151 , void * V_152 ,
struct V_153 * V_77 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
V_77 -> V_154 . V_271 . V_273 = V_2 -> V_35 ;
V_77 -> V_154 . V_271 . V_274 = V_275 ;
V_77 -> V_154 . V_271 . V_26 = 0 ;
V_77 -> V_154 . V_271 . V_89 = 0 ;
V_77 -> V_154 . V_271 . V_276 = 6750000 * 4 / 2 ;
V_77 -> V_154 . V_271 . V_70 [ 0 ] = V_2 -> V_36 ;
V_77 -> V_154 . V_271 . V_70 [ 1 ] = V_2 -> V_36 ;
if ( V_2 -> V_170 & V_277 ) {
V_77 -> V_154 . V_271 . V_278 [ 0 ] = 10 ;
V_77 -> V_154 . V_271 . V_278 [ 1 ] = 273 ;
} else if ( V_2 -> V_170 & V_279 ) {
V_77 -> V_154 . V_271 . V_278 [ 0 ] = 6 ;
V_77 -> V_154 . V_271 . V_278 [ 1 ] = 318 ;
}
return 0 ;
}
static int F_107 ( struct V_151 * V_151 , void * V_152 ,
struct V_280 * V_281 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_72 -> type == V_126 )
return F_108 ( & V_72 -> V_167 , V_281 ) ;
else
return F_108 ( & V_72 -> V_245 , V_281 ) ;
}
static int F_109 ( struct V_151 * V_151 , void * V_152 ,
struct V_282 * V_283 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_72 -> type == V_126 )
return F_110 ( & V_72 -> V_167 , V_283 ) ;
else {
int V_284 = F_110 ( & V_72 -> V_245 , V_283 ) ;
V_283 -> V_285 = V_2 -> V_35 * V_2 -> V_36 * 2 ;
return V_284 ;
}
}
static int F_111 ( struct V_151 * V_151 , void * V_152 , struct V_282 * V_283 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_72 -> type == V_126 )
return F_112 ( & V_72 -> V_167 , V_283 ) ;
else
return F_112 ( & V_72 -> V_245 , V_283 ) ;
}
static int F_113 ( struct V_151 * V_151 , void * V_152 , struct V_282 * V_283 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_72 -> type == V_126 )
return F_114 ( & V_72 -> V_167 , V_283 , V_151 -> V_286 &
V_287 ) ;
else
return F_114 ( & V_72 -> V_245 , V_283 , V_151 -> V_286 &
V_287 ) ;
}
static int F_115 ( struct V_151 * V_151 , void * V_152 ,
struct V_246 * V_247 )
{
struct V_1 * V_2 = ( (struct V_71 * ) V_152 ) -> V_2 ;
F_100 ( V_247 -> V_248 , L_49 , sizeof( V_247 -> V_248 ) ) ;
F_100 ( V_247 -> V_249 , V_250 [ V_2 -> V_251 ] . V_184 , sizeof( V_247 -> V_249 ) ) ;
F_101 ( V_2 -> V_252 , V_247 -> V_253 , sizeof( V_247 -> V_253 ) ) ;
V_247 -> V_254 = V_255 ;
V_247 -> V_256 = V_266 ;
return 0 ;
}
static int F_116 ( struct V_151 * V_151 , void * V_152 ,
struct V_211 * V_212 )
{
struct V_1 * V_2 = ( (struct V_71 * ) V_152 ) -> V_2 ;
if ( F_81 ( V_212 -> V_105 > 0 ) )
return - V_98 ;
strcpy ( V_212 -> V_184 , L_50 ) ;
V_212 -> type = V_84 ;
F_19 ( & V_2 -> V_86 , 0 , V_87 , V_213 , V_212 ) ;
return 0 ;
}
static int F_117 ( struct V_151 * V_151 , void * V_152 ,
struct V_180 * V_8 )
{
if ( V_8 -> V_105 != 0 )
return - V_98 ;
strcpy ( V_8 -> V_184 , L_50 ) ;
V_8 -> type = V_188 ;
return 0 ;
}
static int F_118 ( struct V_151 * V_151 , void * V_152 , struct V_192 * V_193 )
{
if ( F_81 ( V_193 -> V_105 ) )
return - V_98 ;
strcpy ( V_193 -> V_184 , L_50 ) ;
return 0 ;
}
static int F_119 ( struct V_151 * V_151 , void * V_152 ,
struct V_211 * V_212 )
{
struct V_1 * V_2 = ( (struct V_71 * ) V_152 ) -> V_2 ;
if ( 0 != V_212 -> V_105 )
return - V_98 ;
F_19 ( & V_2 -> V_86 , 0 , V_87 , V_214 , V_212 ) ;
return 0 ;
}
static int F_120 ( struct V_151 * V_151 , void * V_72 ,
struct V_192 * V_193 )
{
return 0 ;
}
static int F_121 ( struct V_151 * V_151 , void * V_72 , unsigned int V_8 )
{
return 0 ;
}
static int F_122 ( struct V_151 * V_151 , void * V_152 ,
struct V_130 * V_131 )
{
int V_8 ;
if ( V_131 -> V_133 < V_288 ||
V_131 -> V_133 >= V_289 )
return - V_98 ;
for ( V_8 = 0 ; V_8 < F_45 ( V_132 ) ; V_8 ++ ) {
if ( V_131 -> V_133 && V_131 -> V_133 == V_132 [ V_8 ] . V_133 ) {
memcpy ( V_131 , & ( V_132 [ V_8 ] ) , sizeof( * V_131 ) ) ;
return 0 ;
}
}
return - V_98 ;
}
static int F_123 ( struct V_151 * V_290 )
{
int V_291 = 0 , V_83 = 0 ;
struct V_292 * V_190 = F_124 ( V_290 ) ;
struct V_1 * V_2 = F_125 ( V_290 ) ;
enum V_244 V_293 = 0 ;
struct V_71 * V_72 ;
enum V_93 V_94 ;
switch ( V_190 -> V_294 ) {
case V_295 :
V_293 = V_126 ;
break;
case V_296 :
V_293 = V_128 ;
break;
case V_297 :
V_83 = 1 ;
break;
}
F_38 ( L_51 ,
F_126 ( V_190 ) , V_298 [ V_293 ] ,
V_2 -> V_299 ) ;
V_72 = F_127 ( sizeof( struct V_71 ) , V_300 ) ;
if ( ! V_72 ) {
F_49 ( L_52 ) ;
return - V_301 ;
}
V_72 -> V_2 = V_2 ;
V_72 -> V_83 = V_83 ;
V_72 -> type = V_293 ;
V_290 -> V_302 = V_72 ;
if ( V_72 -> type == V_126 && V_2 -> V_299 == 0 ) {
F_128 ( V_2 , V_303 ) ;
F_58 ( V_2 ) ;
F_59 ( V_2 ) ;
F_129 ( V_2 ) ;
}
if ( V_72 -> V_83 ) {
F_38 ( L_53 ) ;
F_19 ( & V_2 -> V_86 , 0 , V_87 , V_304 ) ;
}
V_2 -> V_299 ++ ;
if ( V_2 -> V_33 )
V_94 = V_161 ;
else
V_94 = V_163 ;
F_130 ( & V_72 -> V_167 , & V_305 ,
NULL , & V_2 -> V_90 ,
V_126 , V_94 ,
sizeof( struct V_5 ) , V_72 , & V_2 -> V_306 ) ;
F_130 ( & V_72 -> V_245 , & V_307 ,
NULL , & V_2 -> V_90 ,
V_128 ,
V_308 ,
sizeof( struct V_5 ) , V_72 , & V_2 -> V_306 ) ;
return V_291 ;
}
void F_131 ( struct V_1 * V_2 )
{
if ( V_2 -> V_309 ) {
if ( F_132 ( V_2 -> V_309 ) )
F_133 ( V_2 -> V_309 ) ;
else
F_134 ( V_2 -> V_309 ) ;
V_2 -> V_309 = NULL ;
}
if ( V_2 -> V_261 ) {
F_135 ( L_54 ,
F_126 ( V_2 -> V_261 ) ) ;
if ( F_132 ( V_2 -> V_261 ) )
F_133 ( V_2 -> V_261 ) ;
else
F_134 ( V_2 -> V_261 ) ;
V_2 -> V_261 = NULL ;
}
if ( V_2 -> V_190 ) {
F_135 ( L_54 ,
F_126 ( V_2 -> V_190 ) ) ;
if ( F_132 ( V_2 -> V_190 ) )
F_133 ( V_2 -> V_190 ) ;
else
F_134 ( V_2 -> V_190 ) ;
V_2 -> V_190 = NULL ;
}
}
static int F_136 ( struct V_151 * V_290 )
{
struct V_71 * V_72 = V_290 -> V_302 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_291 ;
F_38 ( L_55 , V_2 -> V_299 ) ;
if ( F_39 ( V_72 , V_127 ) ) {
F_137 ( & V_72 -> V_167 ) ;
F_41 ( V_72 , V_127 ) ;
}
if ( F_39 ( V_72 , V_129 ) ) {
F_137 ( & V_72 -> V_245 ) ;
F_41 ( V_72 , V_129 ) ;
}
if ( V_2 -> V_299 == 1 ) {
if ( V_2 -> V_9 & V_54 ) {
F_138 ( V_2 ) ;
F_139 ( V_2 ) ;
return 0 ;
}
F_19 ( & V_2 -> V_86 , 0 , V_171 , V_310 , 0 ) ;
F_140 ( V_2 ) ;
F_128 ( V_2 , V_311 ) ;
V_2 -> V_312 = 0 ;
F_38 ( L_56 ) ;
V_291 = F_141 ( V_2 -> V_252 , 0 , 0 ) ;
if ( V_291 < 0 ) {
F_49 ( L_57
L_58 , V_291 ) ;
}
}
F_142 ( & V_72 -> V_167 ) ;
F_142 ( & V_72 -> V_245 ) ;
F_139 ( V_72 ) ;
V_2 -> V_299 -- ;
F_143 ( & V_2 -> V_313 , 1 ) ;
return 0 ;
}
static T_3
F_144 ( struct V_151 * V_290 , char T_4 * V_6 , T_5 V_70 ,
T_6 * V_31 )
{
struct V_71 * V_72 = V_290 -> V_302 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_72 -> type == V_126 ) {
if ( F_40 ( V_2 , V_127 ) )
return - V_169 ;
return F_145 ( & V_72 -> V_167 , V_6 , V_70 , V_31 , 0 ,
V_290 -> V_286 & V_287 ) ;
}
if ( V_72 -> type == V_128 ) {
if ( ! F_37 ( V_72 , V_129 ) )
return - V_169 ;
return F_145 ( & V_72 -> V_245 , V_6 , V_70 , V_31 , 0 ,
V_290 -> V_286 & V_287 ) ;
}
return 0 ;
}
static unsigned int F_146 ( struct V_151 * V_290 , T_7 * V_314 )
{
struct V_71 * V_72 = V_290 -> V_302 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_72 -> type == V_126 ) {
if ( ! F_37 ( V_72 , V_127 ) )
return V_315 ;
return F_147 ( V_290 , & V_72 -> V_167 , V_314 ) ;
} else if ( V_72 -> type == V_128 ) {
if ( ! F_37 ( V_72 , V_129 ) )
return V_315 ;
return F_147 ( V_290 , & V_72 -> V_245 , V_314 ) ;
} else {
return V_315 ;
}
}
static int F_148 ( struct V_151 * V_290 , struct V_316 * V_317 )
{
struct V_71 * V_72 = V_290 -> V_302 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_72 -> type == V_126 )
V_53 = F_149 ( & V_72 -> V_167 , V_317 ) ;
else if ( V_72 -> type == V_128 )
V_53 = F_149 ( & V_72 -> V_245 , V_317 ) ;
F_38 ( L_59 ,
( unsigned long ) V_317 -> V_318 ,
( unsigned long ) V_317 -> V_319 - ( unsigned long ) V_317 -> V_318 ,
V_53 ) ;
return V_53 ;
}
static struct V_292 * F_150 ( struct V_1 * V_2 ,
const struct V_292 * V_320 ,
const char * V_321 )
{
struct V_292 * V_322 ;
V_322 = F_151 () ;
if ( NULL == V_322 )
return NULL ;
* V_322 = * V_320 ;
V_322 -> V_86 = & V_2 -> V_86 ;
V_322 -> V_323 = F_134 ;
V_322 -> V_324 = V_325 ;
V_322 -> V_306 = & V_2 -> V_306 ;
snprintf ( V_322 -> V_184 , sizeof( V_322 -> V_184 ) , L_60 ,
V_2 -> V_184 , V_321 ) ;
F_152 ( V_322 , V_2 ) ;
return V_322 ;
}
int F_153 ( struct V_1 * V_2 )
{
T_8 V_229 ;
int V_226 ;
F_154 ( V_326 L_61 ,
V_2 -> V_184 ,
( V_255 >> 16 ) & 0xff ,
( V_255 >> 8 ) & 0xff , V_255 & 0xff ) ;
V_2 -> V_170 = V_327 . V_328 ;
F_19 ( & V_2 -> V_86 , 0 , V_171 , V_172 , V_2 -> V_170 ) ;
V_2 -> V_162 = V_329 ;
V_2 -> V_106 = 0 ;
V_2 -> V_77 = & V_77 [ 0 ] ;
F_57 ( V_2 , V_77 [ 0 ] . V_157 ,
F_51 ( V_2 ) , F_52 ( V_2 ) ) ;
F_33 ( V_2 , V_2 -> V_106 ) ;
V_2 -> V_138 = 1 ;
V_2 -> V_140 = 0x1f ;
V_229 = ( T_8 ) F_87 ( V_2 , V_330 ) ;
F_155 ( V_2 , V_330 ,
( V_331 | V_229 ) ) ;
F_156 ( V_2 ) ;
F_157 ( V_2 ) ;
F_158 ( V_2 ) ;
V_2 -> V_190 = F_150 ( V_2 , & V_327 , L_62 ) ;
if ( ! V_2 -> V_190 ) {
F_49 ( L_63 ) ;
return - V_145 ;
}
V_226 = F_159 ( V_2 -> V_190 , V_295 ,
V_332 [ V_2 -> V_333 ] ) ;
if ( V_226 ) {
F_49 ( L_64 ,
V_226 ) ;
return V_226 ;
}
if ( F_28 ( V_2 ) == 1 ) {
V_2 -> V_261 = F_150 ( V_2 , & V_327 ,
L_65 ) ;
V_226 = F_159 ( V_2 -> V_261 , V_296 ,
V_334 [ V_2 -> V_333 ] ) ;
if ( V_226 < 0 ) {
F_49 ( L_66 ) ;
return V_226 ;
}
}
if ( V_250 [ V_2 -> V_251 ] . V_83 . type == V_335 ) {
V_2 -> V_309 = F_150 ( V_2 , & V_336 ,
L_67 ) ;
if ( ! V_2 -> V_309 ) {
F_49 ( L_63 ) ;
return - V_145 ;
}
V_226 = F_159 ( V_2 -> V_309 , V_297 ,
V_337 [ V_2 -> V_333 ] ) ;
if ( V_226 < 0 ) {
F_49 ( L_68 ) ;
return V_226 ;
}
F_135 ( L_69 ,
F_126 ( V_2 -> V_309 ) ) ;
}
F_135 ( L_70 ,
F_126 ( V_2 -> V_190 ) ) ;
if ( V_2 -> V_261 )
F_135 ( L_71 ,
F_126 ( V_2 -> V_261 ) ) ;
return 0 ;
}
