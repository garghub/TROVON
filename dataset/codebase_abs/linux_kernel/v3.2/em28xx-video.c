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
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
F_19 ( & V_2 -> V_86 , 0 , V_112 , V_171 , V_170 ) ;
return 0 ;
}
static int F_64 ( struct V_151 * V_151 , void * V_152 , T_1 * V_170 )
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
F_19 ( & V_2 -> V_86 , 0 , V_172 , V_173 , V_2 -> V_170 ) ;
return 0 ;
}
static int F_65 ( struct V_151 * V_151 , void * V_152 ,
struct V_174 * V_18 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 = 0 ;
if ( V_18 -> type != V_126 )
return - V_98 ;
if ( V_2 -> V_115 . V_175 )
V_53 = F_66 ( & V_2 -> V_86 , 0 ,
V_112 , V_176 , V_18 ) ;
else
F_67 ( V_2 -> V_170 ,
& V_18 -> V_177 . V_178 . V_179 ) ;
return V_53 ;
}
static int F_68 ( struct V_151 * V_151 , void * V_152 ,
struct V_174 * V_18 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
if ( ! V_2 -> V_115 . V_175 )
return - V_98 ;
if ( V_18 -> type != V_126 )
return - V_98 ;
return F_66 ( & V_2 -> V_86 , 0 , V_112 , V_180 , V_18 ) ;
}
static int F_69 ( struct V_151 * V_151 , void * V_152 ,
struct V_181 * V_8 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
unsigned int V_182 ;
V_182 = V_8 -> V_105 ;
if ( V_182 >= V_183 )
return - V_98 ;
if ( 0 == F_34 ( V_182 ) -> type )
return - V_98 ;
V_8 -> V_105 = V_182 ;
V_8 -> type = V_184 ;
strcpy ( V_8 -> V_185 , V_186 [ F_34 ( V_182 ) -> type ] ) ;
if ( ( V_187 == F_34 ( V_182 ) -> type ) ||
( V_188 == F_34 ( V_182 ) -> type ) )
V_8 -> type = V_189 ;
V_8 -> V_190 = V_2 -> V_191 -> V_192 ;
return 0 ;
}
static int F_70 ( struct V_151 * V_151 , void * V_152 , unsigned int * V_8 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
* V_8 = V_2 -> V_106 ;
return 0 ;
}
static int F_71 ( struct V_151 * V_151 , void * V_152 , unsigned int V_8 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_8 >= V_183 )
return - V_98 ;
if ( 0 == F_34 ( V_8 ) -> type )
return - V_98 ;
V_2 -> V_106 = V_8 ;
F_33 ( V_2 , V_2 -> V_106 ) ;
return 0 ;
}
static int F_72 ( struct V_151 * V_151 , void * V_152 , struct V_193 * V_194 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
if ( ! V_2 -> V_195 . V_196 )
return - V_98 ;
switch ( V_194 -> V_105 ) {
case V_197 :
strcpy ( V_194 -> V_185 , L_38 ) ;
break;
case V_198 :
strcpy ( V_194 -> V_185 , L_39 ) ;
break;
case V_199 :
strcpy ( V_194 -> V_185 , L_40 ) ;
break;
case V_200 :
strcpy ( V_194 -> V_185 , L_41 ) ;
break;
case V_201 :
strcpy ( V_194 -> V_185 , L_42 ) ;
break;
case V_202 :
strcpy ( V_194 -> V_185 , L_43 ) ;
break;
case V_203 :
strcpy ( V_194 -> V_185 , L_44 ) ;
break;
case V_204 :
strcpy ( V_194 -> V_185 , L_45 ) ;
break;
default:
return - V_98 ;
}
V_194 -> V_105 = V_2 -> V_107 ;
V_194 -> V_205 = V_206 ;
return 0 ;
}
static int F_73 ( struct V_151 * V_151 , void * V_152 , struct V_193 * V_194 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
if ( ! V_2 -> V_195 . V_196 )
return - V_98 ;
if ( V_194 -> V_105 >= V_183 )
return - V_98 ;
if ( 0 == F_34 ( V_194 -> V_105 ) -> type )
return - V_98 ;
V_2 -> V_107 = F_34 ( V_194 -> V_105 ) -> V_108 ;
V_2 -> V_109 = F_34 ( V_194 -> V_105 ) -> V_110 ;
if ( ! V_2 -> V_109 )
V_2 -> V_109 = V_111 ;
return 0 ;
}
static int F_74 ( struct V_151 * V_151 , void * V_152 ,
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
if ( V_2 -> V_195 . V_207 != V_208 ) {
V_53 = F_44 ( V_131 ) ;
if ( ! V_53 )
return 0 ;
}
F_19 ( & V_2 -> V_86 , 0 , V_172 , V_209 , V_131 ) ;
if ( V_131 -> type )
return 0 ;
else
return - V_98 ;
}
static int F_75 ( struct V_1 * V_2 , int V_133 )
{
struct V_130 V_131 ;
memset ( & V_131 , 0 , sizeof( V_131 ) ) ;
V_131 . V_133 = V_133 ;
F_19 ( & V_2 -> V_86 , 0 , V_172 , V_209 , & V_131 ) ;
if ( V_131 . type )
return 0 ;
else
return - V_98 ;
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
V_53 = 0 ;
if ( V_2 -> V_195 . V_207 != V_208 )
V_53 = F_46 ( V_2 , V_135 ) ;
else
V_53 = 1 ;
if ( V_53 == 1 ) {
if ( F_75 ( V_2 , V_135 -> V_133 ) )
return - V_98 ;
F_19 ( & V_2 -> V_86 , 0 , V_172 , V_210 , V_135 ) ;
V_53 = 0 ;
}
return V_53 ;
}
static int F_77 ( struct V_151 * V_151 , void * V_152 ,
struct V_134 * V_135 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_2 -> V_195 . V_207 != V_208 )
V_53 = F_47 ( V_2 , V_135 ) ;
else
V_53 = 1 ;
if ( V_53 == 1 ) {
V_53 = F_75 ( V_2 , V_135 -> V_133 ) ;
if ( ! V_53 )
F_19 ( & V_2 -> V_86 , 0 ,
V_172 , V_211 , V_135 ) ;
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
static int F_78 ( struct V_151 * V_151 , void * V_152 ,
struct V_212 * V_213 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( 0 != V_213 -> V_105 )
return - V_98 ;
strcpy ( V_213 -> V_185 , L_46 ) ;
V_213 -> type = V_85 ;
F_19 ( & V_2 -> V_86 , 0 , V_87 , V_214 , V_213 ) ;
return 0 ;
}
static int F_79 ( struct V_151 * V_151 , void * V_152 ,
struct V_212 * V_213 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( 0 != V_213 -> V_105 )
return - V_98 ;
F_19 ( & V_2 -> V_86 , 0 , V_87 , V_215 , V_213 ) ;
return 0 ;
}
static int F_80 ( struct V_151 * V_151 , void * V_152 ,
struct V_74 * V_75 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
V_75 -> type = V_72 -> V_83 ? V_84 : V_85 ;
V_75 -> V_81 = V_2 -> V_82 ;
return 0 ;
}
static int F_81 ( struct V_151 * V_151 , void * V_152 ,
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
if ( F_82 ( 0 == V_72 -> V_83 && V_75 -> type != V_85 ) )
return - V_98 ;
if ( F_82 ( 1 == V_72 -> V_83 && V_75 -> type != V_84 ) )
return - V_98 ;
V_2 -> V_82 = V_75 -> V_81 ;
F_19 ( & V_2 -> V_86 , 0 , V_87 , V_88 , V_75 ) ;
return 0 ;
}
static int F_83 ( int V_216 )
{
switch ( V_216 ) {
case V_217 :
case V_218 :
case V_219 :
return 2 ;
default:
return 1 ;
}
}
static int F_84 ( struct V_151 * V_151 , void * V_152 ,
struct V_220 * V_221 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
V_221 -> V_222 = V_223 ;
V_221 -> V_224 = 0 ;
F_19 ( & V_2 -> V_86 , 0 , V_172 , V_225 , V_221 ) ;
return 0 ;
}
static int F_85 ( struct V_151 * V_151 , void * V_152 ,
struct V_226 * V_216 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_227 ;
switch ( V_216 -> V_228 . type ) {
case V_229 :
V_227 = F_86 ( V_2 , V_216 -> V_216 ) ;
if ( V_227 < 0 )
return V_227 ;
V_216 -> V_230 = V_227 ;
V_216 -> V_32 = 1 ;
return 0 ;
case V_231 :
F_19 ( & V_2 -> V_86 , 0 , V_172 , V_232 , V_216 ) ;
return 0 ;
case V_233 :
F_19 ( & V_2 -> V_86 , 0 , V_172 , V_232 , V_216 ) ;
return 0 ;
default:
if ( ! F_87 ( & V_216 -> V_228 ) )
return - V_98 ;
}
V_216 -> V_32 = F_83 ( V_216 -> V_216 ) ;
if ( V_216 -> V_32 == 1 ) {
V_227 = F_88 ( V_2 , V_216 -> V_216 ) ;
if ( V_227 < 0 )
return V_227 ;
V_216 -> V_230 = V_227 ;
} else {
T_2 V_230 = 0 ;
V_227 = F_89 ( V_2 , V_234 ,
V_216 -> V_216 , ( char * ) & V_230 , 2 ) ;
if ( V_227 < 0 )
return V_227 ;
V_216 -> V_230 = F_90 ( V_230 ) ;
}
return 0 ;
}
static int F_91 ( struct V_151 * V_151 , void * V_152 ,
struct V_226 * V_216 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
T_2 V_6 ;
switch ( V_216 -> V_228 . type ) {
case V_229 :
return F_92 ( V_2 , V_216 -> V_216 , V_216 -> V_230 ) ;
case V_231 :
F_19 ( & V_2 -> V_86 , 0 , V_172 , V_235 , V_216 ) ;
return 0 ;
case V_233 :
F_19 ( & V_2 -> V_86 , 0 , V_172 , V_235 , V_216 ) ;
return 0 ;
default:
if ( ! F_87 ( & V_216 -> V_228 ) )
return - V_98 ;
}
V_6 = F_93 ( V_216 -> V_230 ) ;
return F_94 ( V_2 , V_216 -> V_216 , ( char * ) & V_6 ,
F_83 ( V_216 -> V_216 ) ) ;
}
static int F_95 ( struct V_151 * V_151 , void * V_152 ,
struct V_236 * V_237 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
if ( V_237 -> type != V_126 )
return - V_98 ;
V_237 -> V_238 . V_239 = 0 ;
V_237 -> V_238 . V_240 = 0 ;
V_237 -> V_238 . V_30 = V_2 -> V_30 ;
V_237 -> V_238 . V_76 = V_2 -> V_76 ;
V_237 -> V_241 = V_237 -> V_238 ;
V_237 -> V_242 . V_243 = 54 ;
V_237 -> V_242 . V_244 = 59 ;
return 0 ;
}
static int F_96 ( struct V_151 * V_151 , void * V_152 ,
enum V_245 type )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 = - V_98 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( F_82 ( type != V_72 -> type ) )
return - V_98 ;
F_38 ( L_47 ,
V_72 , type , V_72 -> V_124 , V_2 -> V_124 ) ;
if ( F_82 ( ! F_37 ( V_72 , F_43 ( V_72 ) ) ) )
return - V_169 ;
if ( V_72 -> type == V_126 )
V_53 = F_97 ( & V_72 -> V_167 ) ;
else if ( V_72 -> type == V_128 )
V_53 = F_97 ( & V_72 -> V_246 ) ;
return V_53 ;
}
static int F_98 ( struct V_151 * V_151 , void * V_152 ,
enum V_245 type )
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
F_99 ( & V_72 -> V_167 ) ;
F_41 ( V_72 , V_127 ) ;
}
} else if ( V_72 -> type == V_128 ) {
if ( F_39 ( V_72 , V_129 ) ) {
F_99 ( & V_72 -> V_246 ) ;
F_41 ( V_72 , V_129 ) ;
}
}
return 0 ;
}
static int F_100 ( struct V_151 * V_151 , void * V_152 ,
struct V_247 * V_248 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
F_101 ( V_248 -> V_249 , L_49 , sizeof( V_248 -> V_249 ) ) ;
F_101 ( V_248 -> V_250 , V_251 [ V_2 -> V_252 ] . V_185 , sizeof( V_248 -> V_250 ) ) ;
F_102 ( V_2 -> V_253 , V_248 -> V_254 , sizeof( V_248 -> V_254 ) ) ;
V_248 -> V_255 =
V_256 |
V_257 |
V_258 | V_259 ;
if ( V_2 -> V_260 )
V_248 -> V_255 |= V_261 ;
if ( V_2 -> V_195 . V_196 )
V_248 -> V_255 |= V_262 ;
if ( V_2 -> V_263 != V_264 )
V_248 -> V_255 |= V_265 ;
return 0 ;
}
static int F_103 ( struct V_151 * V_151 , void * V_152 ,
struct V_266 * V_75 )
{
if ( F_82 ( V_75 -> V_105 >= F_45 ( V_77 ) ) )
return - V_98 ;
F_101 ( V_75 -> V_267 , V_77 [ V_75 -> V_105 ] . V_185 , sizeof( V_75 -> V_267 ) ) ;
V_75 -> V_156 = V_77 [ V_75 -> V_105 ] . V_157 ;
return 0 ;
}
static int F_104 ( struct V_151 * V_151 , void * V_152 ,
struct V_268 * V_269 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
struct V_165 * V_154 ;
unsigned int V_149 = F_51 ( V_2 ) ;
unsigned int V_150 = F_52 ( V_2 ) ;
V_154 = F_54 ( V_269 -> V_270 ) ;
if ( ! V_154 ) {
F_38 ( L_36 ,
V_269 -> V_270 ) ;
return - V_98 ;
}
if ( V_2 -> V_115 . V_166 ) {
if ( V_269 -> V_105 > 1 )
return - V_98 ;
V_269 -> type = V_271 ;
V_269 -> V_272 . V_30 = V_149 / ( 1 + V_269 -> V_105 ) ;
V_269 -> V_272 . V_76 = V_150 / ( 1 + V_269 -> V_105 ) ;
return 0 ;
}
if ( V_269 -> V_105 != 0 )
return - V_98 ;
V_269 -> type = V_273 ;
V_269 -> V_274 . V_275 = 48 ;
V_269 -> V_274 . V_276 = 32 ;
V_269 -> V_274 . V_277 = V_149 ;
V_269 -> V_274 . V_278 = V_150 ;
V_269 -> V_274 . V_279 = 1 ;
V_269 -> V_274 . V_280 = 1 ;
return 0 ;
}
static int F_105 ( struct V_151 * V_151 , void * V_152 ,
struct V_153 * V_75 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
V_75 -> V_154 . V_281 . V_282 = 0 ;
F_19 ( & V_2 -> V_86 , 0 , V_283 , V_284 , & V_75 -> V_154 . V_281 ) ;
if ( V_75 -> V_154 . V_281 . V_282 == 0 )
V_53 = - V_98 ;
return V_53 ;
}
static int F_106 ( struct V_151 * V_151 , void * V_152 ,
struct V_153 * V_75 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
F_19 ( & V_2 -> V_86 , 0 , V_283 , V_284 , & V_75 -> V_154 . V_281 ) ;
if ( V_75 -> V_154 . V_281 . V_282 == 0 )
return - V_98 ;
return 0 ;
}
static int F_107 ( struct V_151 * V_151 , void * V_152 ,
struct V_153 * V_77 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
V_77 -> V_154 . V_283 . V_285 = V_2 -> V_35 ;
V_77 -> V_154 . V_283 . V_286 = V_287 ;
V_77 -> V_154 . V_283 . V_26 = 0 ;
V_77 -> V_154 . V_283 . V_89 = 0 ;
V_77 -> V_154 . V_283 . V_288 = 6750000 * 4 / 2 ;
V_77 -> V_154 . V_283 . V_70 [ 0 ] = V_2 -> V_36 ;
V_77 -> V_154 . V_283 . V_70 [ 1 ] = V_2 -> V_36 ;
if ( V_2 -> V_170 & V_289 ) {
V_77 -> V_154 . V_283 . V_290 [ 0 ] = 10 ;
V_77 -> V_154 . V_283 . V_290 [ 1 ] = 273 ;
} else if ( V_2 -> V_170 & V_291 ) {
V_77 -> V_154 . V_283 . V_290 [ 0 ] = 6 ;
V_77 -> V_154 . V_283 . V_290 [ 1 ] = 318 ;
}
return 0 ;
}
static int F_108 ( struct V_151 * V_151 , void * V_152 ,
struct V_153 * V_77 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
V_77 -> V_154 . V_283 . V_285 = V_2 -> V_35 ;
V_77 -> V_154 . V_283 . V_286 = V_287 ;
V_77 -> V_154 . V_283 . V_26 = 0 ;
V_77 -> V_154 . V_283 . V_89 = 0 ;
V_77 -> V_154 . V_283 . V_288 = 6750000 * 4 / 2 ;
V_77 -> V_154 . V_283 . V_70 [ 0 ] = V_2 -> V_36 ;
V_77 -> V_154 . V_283 . V_70 [ 1 ] = V_2 -> V_36 ;
if ( V_2 -> V_170 & V_289 ) {
V_77 -> V_154 . V_283 . V_290 [ 0 ] = 10 ;
V_77 -> V_154 . V_283 . V_290 [ 1 ] = 273 ;
} else if ( V_2 -> V_170 & V_291 ) {
V_77 -> V_154 . V_283 . V_290 [ 0 ] = 6 ;
V_77 -> V_154 . V_283 . V_290 [ 1 ] = 318 ;
}
return 0 ;
}
static int F_109 ( struct V_151 * V_151 , void * V_152 ,
struct V_292 * V_293 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_72 -> type == V_126 )
return F_110 ( & V_72 -> V_167 , V_293 ) ;
else
return F_110 ( & V_72 -> V_246 , V_293 ) ;
}
static int F_111 ( struct V_151 * V_151 , void * V_152 ,
struct V_294 * V_295 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_72 -> type == V_126 )
return F_112 ( & V_72 -> V_167 , V_295 ) ;
else {
int V_296 = F_112 ( & V_72 -> V_246 , V_295 ) ;
V_295 -> V_297 = V_2 -> V_35 * V_2 -> V_36 * 2 ;
return V_296 ;
}
}
static int F_113 ( struct V_151 * V_151 , void * V_152 , struct V_294 * V_295 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_72 -> type == V_126 )
return F_114 ( & V_72 -> V_167 , V_295 ) ;
else
return F_114 ( & V_72 -> V_246 , V_295 ) ;
}
static int F_115 ( struct V_151 * V_151 , void * V_152 , struct V_294 * V_295 )
{
struct V_71 * V_72 = V_152 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_72 -> type == V_126 )
return F_116 ( & V_72 -> V_167 , V_295 , V_151 -> V_298 &
V_299 ) ;
else
return F_116 ( & V_72 -> V_246 , V_295 , V_151 -> V_298 &
V_299 ) ;
}
static int F_117 ( struct V_151 * V_151 , void * V_152 ,
struct V_247 * V_248 )
{
struct V_1 * V_2 = ( (struct V_71 * ) V_152 ) -> V_2 ;
F_101 ( V_248 -> V_249 , L_49 , sizeof( V_248 -> V_249 ) ) ;
F_101 ( V_248 -> V_250 , V_251 [ V_2 -> V_252 ] . V_185 , sizeof( V_248 -> V_250 ) ) ;
F_102 ( V_2 -> V_253 , V_248 -> V_254 , sizeof( V_248 -> V_254 ) ) ;
V_248 -> V_255 = V_265 ;
return 0 ;
}
static int F_118 ( struct V_151 * V_151 , void * V_152 ,
struct V_212 * V_213 )
{
struct V_1 * V_2 = ( (struct V_71 * ) V_152 ) -> V_2 ;
if ( F_82 ( V_213 -> V_105 > 0 ) )
return - V_98 ;
strcpy ( V_213 -> V_185 , L_50 ) ;
V_213 -> type = V_84 ;
F_19 ( & V_2 -> V_86 , 0 , V_87 , V_214 , V_213 ) ;
return 0 ;
}
static int F_119 ( struct V_151 * V_151 , void * V_152 ,
struct V_181 * V_8 )
{
if ( V_8 -> V_105 != 0 )
return - V_98 ;
strcpy ( V_8 -> V_185 , L_50 ) ;
V_8 -> type = V_189 ;
return 0 ;
}
static int F_120 ( struct V_151 * V_151 , void * V_152 , struct V_193 * V_194 )
{
if ( F_82 ( V_194 -> V_105 ) )
return - V_98 ;
strcpy ( V_194 -> V_185 , L_50 ) ;
return 0 ;
}
static int F_121 ( struct V_151 * V_151 , void * V_152 ,
struct V_212 * V_213 )
{
struct V_1 * V_2 = ( (struct V_71 * ) V_152 ) -> V_2 ;
if ( 0 != V_213 -> V_105 )
return - V_98 ;
F_19 ( & V_2 -> V_86 , 0 , V_87 , V_215 , V_213 ) ;
return 0 ;
}
static int F_122 ( struct V_151 * V_151 , void * V_72 ,
struct V_193 * V_194 )
{
return 0 ;
}
static int F_123 ( struct V_151 * V_151 , void * V_72 , unsigned int V_8 )
{
return 0 ;
}
static int F_124 ( struct V_151 * V_151 , void * V_152 ,
struct V_130 * V_131 )
{
int V_8 ;
if ( V_131 -> V_133 < V_300 ||
V_131 -> V_133 >= V_301 )
return - V_98 ;
for ( V_8 = 0 ; V_8 < F_45 ( V_132 ) ; V_8 ++ ) {
if ( V_131 -> V_133 && V_131 -> V_133 == V_132 [ V_8 ] . V_133 ) {
memcpy ( V_131 , & ( V_132 [ V_8 ] ) , sizeof( * V_131 ) ) ;
return 0 ;
}
}
return - V_98 ;
}
static int F_125 ( struct V_151 * V_302 )
{
int V_303 = 0 , V_83 = 0 ;
struct V_304 * V_191 = F_126 ( V_302 ) ;
struct V_1 * V_2 = F_127 ( V_302 ) ;
enum V_245 V_305 = 0 ;
struct V_71 * V_72 ;
enum V_93 V_94 ;
switch ( V_191 -> V_306 ) {
case V_307 :
V_305 = V_126 ;
break;
case V_308 :
V_305 = V_128 ;
break;
case V_309 :
V_83 = 1 ;
break;
}
F_38 ( L_51 ,
F_128 ( V_191 ) , V_310 [ V_305 ] ,
V_2 -> V_311 ) ;
V_72 = F_129 ( sizeof( struct V_71 ) , V_312 ) ;
if ( ! V_72 ) {
F_49 ( L_52 ) ;
return - V_313 ;
}
V_72 -> V_2 = V_2 ;
V_72 -> V_83 = V_83 ;
V_72 -> type = V_305 ;
V_302 -> V_314 = V_72 ;
if ( V_72 -> type == V_126 && V_2 -> V_311 == 0 ) {
F_130 ( V_2 , V_315 ) ;
F_58 ( V_2 ) ;
F_59 ( V_2 ) ;
F_131 ( V_2 ) ;
}
if ( V_72 -> V_83 ) {
F_38 ( L_53 ) ;
F_19 ( & V_2 -> V_86 , 0 , V_87 , V_316 ) ;
}
V_2 -> V_311 ++ ;
if ( V_2 -> V_33 )
V_94 = V_161 ;
else
V_94 = V_163 ;
F_132 ( & V_72 -> V_167 , & V_317 ,
NULL , & V_2 -> V_90 ,
V_126 , V_94 ,
sizeof( struct V_5 ) , V_72 , & V_2 -> V_318 ) ;
F_132 ( & V_72 -> V_246 , & V_319 ,
NULL , & V_2 -> V_90 ,
V_128 ,
V_320 ,
sizeof( struct V_5 ) , V_72 , & V_2 -> V_318 ) ;
return V_303 ;
}
void F_133 ( struct V_1 * V_2 )
{
if ( V_2 -> V_321 ) {
if ( F_134 ( V_2 -> V_321 ) )
F_135 ( V_2 -> V_321 ) ;
else
F_136 ( V_2 -> V_321 ) ;
V_2 -> V_321 = NULL ;
}
if ( V_2 -> V_260 ) {
F_137 ( L_54 ,
F_128 ( V_2 -> V_260 ) ) ;
if ( F_134 ( V_2 -> V_260 ) )
F_135 ( V_2 -> V_260 ) ;
else
F_136 ( V_2 -> V_260 ) ;
V_2 -> V_260 = NULL ;
}
if ( V_2 -> V_191 ) {
F_137 ( L_54 ,
F_128 ( V_2 -> V_191 ) ) ;
if ( F_134 ( V_2 -> V_191 ) )
F_135 ( V_2 -> V_191 ) ;
else
F_136 ( V_2 -> V_191 ) ;
V_2 -> V_191 = NULL ;
}
}
static int F_138 ( struct V_151 * V_302 )
{
struct V_71 * V_72 = V_302 -> V_314 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_303 ;
F_38 ( L_55 , V_2 -> V_311 ) ;
if ( F_39 ( V_72 , V_127 ) ) {
F_139 ( & V_72 -> V_167 ) ;
F_41 ( V_72 , V_127 ) ;
}
if ( F_39 ( V_72 , V_129 ) ) {
F_139 ( & V_72 -> V_246 ) ;
F_41 ( V_72 , V_129 ) ;
}
if ( V_2 -> V_311 == 1 ) {
if ( V_2 -> V_9 & V_54 ) {
F_140 ( V_2 ) ;
F_141 ( V_2 -> V_322 ) ;
F_141 ( V_2 ) ;
return 0 ;
}
F_19 ( & V_2 -> V_86 , 0 , V_172 , V_323 , 0 ) ;
F_142 ( V_2 ) ;
F_130 ( V_2 , V_324 ) ;
V_2 -> V_325 = 0 ;
F_38 ( L_56 ) ;
V_303 = F_143 ( V_2 -> V_253 , 0 , 0 ) ;
if ( V_303 < 0 ) {
F_49 ( L_57
L_58 , V_303 ) ;
}
}
F_144 ( & V_72 -> V_167 ) ;
F_144 ( & V_72 -> V_246 ) ;
F_141 ( V_72 ) ;
V_2 -> V_311 -- ;
F_145 ( & V_2 -> V_326 , 1 ) ;
return 0 ;
}
static T_3
F_146 ( struct V_151 * V_302 , char T_4 * V_6 , T_5 V_70 ,
T_6 * V_31 )
{
struct V_71 * V_72 = V_302 -> V_314 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_72 -> type == V_126 ) {
if ( F_40 ( V_2 , V_127 ) )
return - V_169 ;
return F_147 ( & V_72 -> V_167 , V_6 , V_70 , V_31 , 0 ,
V_302 -> V_298 & V_299 ) ;
}
if ( V_72 -> type == V_128 ) {
if ( ! F_37 ( V_72 , V_129 ) )
return - V_169 ;
return F_147 ( & V_72 -> V_246 , V_6 , V_70 , V_31 , 0 ,
V_302 -> V_298 & V_299 ) ;
}
return 0 ;
}
static unsigned int F_148 ( struct V_151 * V_302 , T_7 * V_327 )
{
struct V_71 * V_72 = V_302 -> V_314 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_72 -> type == V_126 ) {
if ( ! F_37 ( V_72 , V_127 ) )
return V_328 ;
return F_149 ( V_302 , & V_72 -> V_167 , V_327 ) ;
} else if ( V_72 -> type == V_128 ) {
if ( ! F_37 ( V_72 , V_129 ) )
return V_328 ;
return F_149 ( V_302 , & V_72 -> V_246 , V_327 ) ;
} else {
return V_328 ;
}
}
static int F_150 ( struct V_151 * V_302 , struct V_329 * V_330 )
{
struct V_71 * V_72 = V_302 -> V_314 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_72 -> type == V_126 )
V_53 = F_151 ( & V_72 -> V_167 , V_330 ) ;
else if ( V_72 -> type == V_128 )
V_53 = F_151 ( & V_72 -> V_246 , V_330 ) ;
F_38 ( L_59 ,
( unsigned long ) V_330 -> V_331 ,
( unsigned long ) V_330 -> V_332 - ( unsigned long ) V_330 -> V_331 ,
V_53 ) ;
return V_53 ;
}
static struct V_304 * F_152 ( struct V_1 * V_2 ,
const struct V_304 * V_333 ,
const char * V_334 )
{
struct V_304 * V_335 ;
V_335 = F_153 () ;
if ( NULL == V_335 )
return NULL ;
* V_335 = * V_333 ;
V_335 -> V_86 = & V_2 -> V_86 ;
V_335 -> V_336 = F_136 ;
V_335 -> V_337 = V_338 ;
V_335 -> V_318 = & V_2 -> V_318 ;
snprintf ( V_335 -> V_185 , sizeof( V_335 -> V_185 ) , L_60 ,
V_2 -> V_185 , V_334 ) ;
F_154 ( V_335 , V_2 ) ;
return V_335 ;
}
int F_155 ( struct V_1 * V_2 )
{
T_8 V_230 ;
int V_227 ;
F_156 ( V_339 L_61 ,
V_2 -> V_185 , V_340 ) ;
V_2 -> V_170 = V_341 . V_342 ;
F_19 ( & V_2 -> V_86 , 0 , V_172 , V_173 , V_2 -> V_170 ) ;
V_2 -> V_162 = V_343 ;
V_2 -> V_106 = 0 ;
V_2 -> V_77 = & V_77 [ 0 ] ;
F_57 ( V_2 , V_77 [ 0 ] . V_157 ,
F_51 ( V_2 ) , F_52 ( V_2 ) ) ;
F_33 ( V_2 , V_2 -> V_106 ) ;
V_2 -> V_138 = 1 ;
V_2 -> V_140 = 0x1f ;
V_230 = ( T_8 ) F_88 ( V_2 , V_344 ) ;
F_157 ( V_2 , V_344 ,
( V_345 | V_230 ) ) ;
F_158 ( V_2 ) ;
F_159 ( V_2 ) ;
F_160 ( V_2 ) ;
V_2 -> V_191 = F_152 ( V_2 , & V_341 , L_62 ) ;
if ( ! V_2 -> V_191 ) {
F_49 ( L_63 ) ;
return - V_145 ;
}
V_227 = F_161 ( V_2 -> V_191 , V_307 ,
V_346 [ V_2 -> V_347 ] ) ;
if ( V_227 ) {
F_49 ( L_64 ,
V_227 ) ;
return V_227 ;
}
if ( F_28 ( V_2 ) == 1 ) {
V_2 -> V_260 = F_152 ( V_2 , & V_341 ,
L_65 ) ;
V_227 = F_161 ( V_2 -> V_260 , V_308 ,
V_348 [ V_2 -> V_347 ] ) ;
if ( V_227 < 0 ) {
F_49 ( L_66 ) ;
return V_227 ;
}
}
if ( V_251 [ V_2 -> V_252 ] . V_83 . type == V_349 ) {
V_2 -> V_321 = F_152 ( V_2 , & V_350 ,
L_67 ) ;
if ( ! V_2 -> V_321 ) {
F_49 ( L_63 ) ;
return - V_145 ;
}
V_227 = F_161 ( V_2 -> V_321 , V_309 ,
V_351 [ V_2 -> V_347 ] ) ;
if ( V_227 < 0 ) {
F_49 ( L_68 ) ;
return V_227 ;
}
F_137 ( L_69 ,
F_128 ( V_2 -> V_321 ) ) ;
}
F_137 ( L_70 ,
F_128 ( V_2 -> V_191 ) ) ;
if ( V_2 -> V_260 )
F_137 ( L_71 ,
F_128 ( V_2 -> V_260 ) ) ;
return 0 ;
}
