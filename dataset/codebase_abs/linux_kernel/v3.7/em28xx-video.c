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
if ( ! V_2 -> V_13 . V_100 . V_101 )
V_95 = 1 ;
if ( V_95 ) {
if ( F_28 ( V_2 ) == 1 )
V_53 = F_29 ( V_2 , V_102 ,
V_103 ,
V_104 ,
V_2 -> V_59 ,
F_17 ) ;
else
V_53 = F_29 ( V_2 , V_102 ,
V_103 ,
V_104 ,
V_2 -> V_59 ,
F_16 ) ;
if ( V_53 < 0 )
goto V_99;
}
V_6 -> V_7 . V_9 = V_105 ;
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
V_6 -> V_7 . V_9 = V_106 ;
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
static void F_33 ( struct V_1 * V_2 , int V_107 )
{
V_2 -> V_108 = V_107 ;
V_2 -> V_109 = F_34 ( V_107 ) -> V_110 ;
V_2 -> V_111 = F_34 ( V_107 ) -> V_112 ;
if ( ! V_2 -> V_111 )
V_2 -> V_111 = V_113 ;
F_19 ( & V_2 -> V_86 , 0 , V_114 , V_115 ,
F_34 ( V_107 ) -> V_116 , 0 , 0 ) ;
if ( V_2 -> V_117 . V_118 ) {
if ( V_2 -> V_119 ) {
F_19 ( & V_2 -> V_86 , 0 , V_120 ,
V_121 , V_2 -> V_119 ) ;
}
F_19 ( & V_2 -> V_86 , 0 , V_120 , V_115 ,
V_2 -> V_109 , F_35 ( V_122 ) , 0 ) ;
}
if ( V_2 -> V_117 . V_123 != V_124 ) {
F_19 ( & V_2 -> V_86 , 0 , V_120 , V_115 ,
V_2 -> V_109 , V_2 -> V_111 , 0 ) ;
}
F_36 ( V_2 ) ;
}
static int F_37 ( struct V_71 * V_72 , unsigned int V_125 )
{
struct V_1 * V_2 = V_72 -> V_2 ;
if ( V_72 -> V_126 & V_125 )
return 1 ;
if ( V_2 -> V_126 & V_125 ) {
return 0 ;
}
V_72 -> V_126 |= V_125 ;
V_2 -> V_126 |= V_125 ;
F_38 ( L_31 , V_125 ) ;
return 1 ;
}
static int F_39 ( struct V_71 * V_72 , unsigned int V_125 )
{
return V_72 -> V_126 & V_125 ;
}
static int F_40 ( struct V_1 * V_2 , unsigned int V_125 )
{
return V_2 -> V_126 & V_125 ;
}
static void F_41 ( struct V_71 * V_72 , unsigned int V_127 )
{
struct V_1 * V_2 = V_72 -> V_2 ;
F_42 ( ( V_72 -> V_126 & V_127 ) != V_127 ) ;
V_72 -> V_126 &= ~ V_127 ;
V_2 -> V_126 &= ~ V_127 ;
F_38 ( L_32 , V_127 ) ;
}
static int F_43 ( struct V_71 * V_72 )
{
switch ( V_72 -> type ) {
case V_128 :
return V_129 ;
case V_130 :
return V_131 ;
default:
F_22 () ;
return 0 ;
}
}
static int F_44 ( struct V_132 * V_133 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < F_45 ( V_134 ) ; V_8 ++ ) {
if ( V_133 -> V_135 && V_133 -> V_135 == V_134 [ V_8 ] . V_135 ) {
memcpy ( V_133 , & ( V_134 [ V_8 ] ) , sizeof( * V_133 ) ) ;
return 0 ;
}
}
return 1 ;
}
static int F_46 ( struct V_1 * V_2 , struct V_136 * V_137 )
{
switch ( V_137 -> V_135 ) {
case V_138 :
V_137 -> V_139 = V_2 -> V_140 ;
return 0 ;
case V_141 :
V_137 -> V_139 = V_2 -> V_142 ;
return 0 ;
default:
return 1 ;
}
}
static int F_47 ( struct V_1 * V_2 , const struct V_136 * V_137 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < F_45 ( V_134 ) ; V_8 ++ )
if ( V_137 -> V_135 == V_134 [ V_8 ] . V_135 )
goto V_143;
return 1 ;
V_143:
if ( V_137 -> V_139 < V_134 [ V_8 ] . V_144 ||
V_137 -> V_139 > V_134 [ V_8 ] . V_145 )
return - V_146 ;
switch ( V_137 -> V_135 ) {
case V_138 :
V_2 -> V_140 = V_137 -> V_139 ;
break;
case V_141 :
V_2 -> V_142 = V_137 -> V_139 ;
break;
}
return F_36 ( V_2 ) ;
}
static int F_48 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 & V_54 ) {
F_49 ( L_33 ) ;
return - V_147 ;
}
if ( V_2 -> V_9 & V_55 ) {
F_49 ( L_34
L_35 ) ;
return - V_148 ;
}
return 0 ;
}
static void F_50 ( struct V_1 * V_2 ,
unsigned int V_30 , unsigned int V_76 ,
unsigned int * V_149 , unsigned int * V_150 )
{
unsigned int V_151 = F_51 ( V_2 ) ;
unsigned int V_152 = F_52 ( V_2 ) ;
* V_149 = ( ( ( unsigned long ) V_151 ) << 12 ) / V_30 - 4096L ;
if ( * V_149 >= 0x4000 )
* V_149 = 0x3fff ;
* V_150 = ( ( ( unsigned long ) V_152 ) << 12 ) / V_76 - 4096L ;
if ( * V_150 >= 0x4000 )
* V_150 = 0x3fff ;
}
static int F_53 ( struct V_153 * V_153 , void * V_154 ,
struct V_155 * V_75 )
{
struct V_71 * V_72 = V_154 ;
struct V_1 * V_2 = V_72 -> V_2 ;
V_75 -> V_156 . V_157 . V_30 = V_2 -> V_30 ;
V_75 -> V_156 . V_157 . V_76 = V_2 -> V_76 ;
V_75 -> V_156 . V_157 . V_158 = V_2 -> V_77 -> V_159 ;
V_75 -> V_156 . V_157 . V_29 = ( V_2 -> V_30 * V_2 -> V_77 -> V_78 + 7 ) >> 3 ;
V_75 -> V_156 . V_157 . V_160 = V_75 -> V_156 . V_157 . V_29 * V_2 -> V_76 ;
V_75 -> V_156 . V_157 . V_161 = V_162 ;
if ( V_2 -> V_33 )
V_75 -> V_156 . V_157 . V_94 = V_163 ;
else
V_75 -> V_156 . V_157 . V_94 = V_2 -> V_164 ?
V_165 : V_166 ;
return 0 ;
}
static struct V_167 * F_54 ( unsigned int V_159 )
{
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < F_45 ( V_77 ) ; V_8 ++ )
if ( V_77 [ V_8 ] . V_159 == V_159 )
return & V_77 [ V_8 ] ;
return NULL ;
}
static int F_55 ( struct V_153 * V_153 , void * V_154 ,
struct V_155 * V_75 )
{
struct V_71 * V_72 = V_154 ;
struct V_1 * V_2 = V_72 -> V_2 ;
unsigned int V_30 = V_75 -> V_156 . V_157 . V_30 ;
unsigned int V_76 = V_75 -> V_156 . V_157 . V_76 ;
unsigned int V_151 = F_51 ( V_2 ) ;
unsigned int V_152 = F_52 ( V_2 ) ;
unsigned int V_149 , V_150 ;
struct V_167 * V_156 ;
V_156 = F_54 ( V_75 -> V_156 . V_157 . V_158 ) ;
if ( ! V_156 ) {
F_38 ( L_36 ,
V_75 -> V_156 . V_157 . V_158 ) ;
return - V_98 ;
}
if ( V_2 -> V_117 . V_168 ) {
V_76 = V_76 > ( 3 * V_152 / 4 ) ? V_152 : V_152 / 2 ;
V_30 = V_30 > ( 3 * V_151 / 4 ) ? V_151 : V_151 / 2 ;
if ( V_30 == V_151 && V_76 == V_152 )
V_30 /= 2 ;
} else {
F_56 ( & V_30 , 48 , V_151 , 1 , & V_76 , 32 , V_152 ,
1 , 0 ) ;
}
F_50 ( V_2 , V_30 , V_76 , & V_149 , & V_150 ) ;
V_30 = ( ( ( unsigned long ) V_151 ) << 12 ) / ( V_149 + 4096L ) ;
V_76 = ( ( ( unsigned long ) V_152 ) << 12 ) / ( V_150 + 4096L ) ;
V_75 -> V_156 . V_157 . V_30 = V_30 ;
V_75 -> V_156 . V_157 . V_76 = V_76 ;
V_75 -> V_156 . V_157 . V_158 = V_156 -> V_159 ;
V_75 -> V_156 . V_157 . V_29 = ( V_2 -> V_30 * V_156 -> V_78 + 7 ) >> 3 ;
V_75 -> V_156 . V_157 . V_160 = V_75 -> V_156 . V_157 . V_29 * V_76 ;
V_75 -> V_156 . V_157 . V_161 = V_162 ;
if ( V_2 -> V_33 )
V_75 -> V_156 . V_157 . V_94 = V_163 ;
else
V_75 -> V_156 . V_157 . V_94 = V_2 -> V_164 ?
V_165 : V_166 ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , unsigned int V_159 ,
unsigned V_30 , unsigned V_76 )
{
struct V_167 * V_156 ;
V_156 = F_54 ( V_159 ) ;
if ( ! V_156 )
return - V_98 ;
V_2 -> V_77 = V_156 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_76 = V_76 ;
F_50 ( V_2 , V_2 -> V_30 , V_2 -> V_76 , & V_2 -> V_149 , & V_2 -> V_150 ) ;
F_58 ( V_2 ) ;
F_59 ( V_2 ) ;
return 0 ;
}
static int F_60 ( struct V_153 * V_153 , void * V_154 ,
struct V_155 * V_75 )
{
struct V_71 * V_72 = V_154 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
F_55 ( V_153 , V_154 , V_75 ) ;
if ( F_61 ( & V_72 -> V_169 ) ) {
F_49 ( L_37 , V_170 ) ;
return - V_171 ;
}
return F_57 ( V_2 , V_75 -> V_156 . V_157 . V_158 ,
V_75 -> V_156 . V_157 . V_30 , V_75 -> V_156 . V_157 . V_76 ) ;
}
static int F_62 ( struct V_153 * V_153 , void * V_154 , T_1 * V_172 )
{
struct V_71 * V_72 = V_154 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
* V_172 = V_2 -> V_172 ;
return 0 ;
}
static int F_63 ( struct V_153 * V_153 , void * V_154 , T_1 * V_172 )
{
struct V_71 * V_72 = V_154 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
F_19 ( & V_2 -> V_86 , 0 , V_114 , V_173 , V_172 ) ;
return 0 ;
}
static int F_64 ( struct V_153 * V_153 , void * V_154 , T_1 * V_172 )
{
struct V_71 * V_72 = V_154 ;
struct V_1 * V_2 = V_72 -> V_2 ;
struct V_155 V_75 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
V_2 -> V_172 = * V_172 ;
V_75 . V_156 . V_157 . V_30 = V_2 -> V_30 ;
V_75 . V_156 . V_157 . V_76 = V_2 -> V_76 ;
F_55 ( V_153 , V_154 , & V_75 ) ;
V_2 -> V_30 = V_75 . V_156 . V_157 . V_30 ;
V_2 -> V_76 = V_75 . V_156 . V_157 . V_76 ;
F_50 ( V_2 , V_2 -> V_30 , V_2 -> V_76 , & V_2 -> V_149 , & V_2 -> V_150 ) ;
F_59 ( V_2 ) ;
F_19 ( & V_2 -> V_86 , 0 , V_174 , V_175 , V_2 -> V_172 ) ;
return 0 ;
}
static int F_65 ( struct V_153 * V_153 , void * V_154 ,
struct V_176 * V_18 )
{
struct V_71 * V_72 = V_154 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 = 0 ;
if ( V_18 -> type != V_128 )
return - V_98 ;
if ( V_2 -> V_117 . V_177 )
V_53 = F_66 ( & V_2 -> V_86 , 0 ,
V_114 , V_178 , V_18 ) ;
else
F_67 ( V_2 -> V_172 ,
& V_18 -> V_179 . V_180 . V_181 ) ;
return V_53 ;
}
static int F_68 ( struct V_153 * V_153 , void * V_154 ,
struct V_176 * V_18 )
{
struct V_71 * V_72 = V_154 ;
struct V_1 * V_2 = V_72 -> V_2 ;
if ( ! V_2 -> V_117 . V_177 )
return - V_98 ;
if ( V_18 -> type != V_128 )
return - V_98 ;
return F_66 ( & V_2 -> V_86 , 0 , V_114 , V_182 , V_18 ) ;
}
static int F_69 ( struct V_153 * V_153 , void * V_154 ,
struct V_183 * V_8 )
{
struct V_71 * V_72 = V_154 ;
struct V_1 * V_2 = V_72 -> V_2 ;
unsigned int V_184 ;
V_184 = V_8 -> V_107 ;
if ( V_184 >= V_185 )
return - V_98 ;
if ( 0 == F_34 ( V_184 ) -> type )
return - V_98 ;
V_8 -> V_107 = V_184 ;
V_8 -> type = V_186 ;
strcpy ( V_8 -> V_187 , V_188 [ F_34 ( V_184 ) -> type ] ) ;
if ( ( V_189 == F_34 ( V_184 ) -> type ) ||
( V_190 == F_34 ( V_184 ) -> type ) )
V_8 -> type = V_191 ;
V_8 -> V_192 = V_2 -> V_193 -> V_194 ;
return 0 ;
}
static int F_70 ( struct V_153 * V_153 , void * V_154 , unsigned int * V_8 )
{
struct V_71 * V_72 = V_154 ;
struct V_1 * V_2 = V_72 -> V_2 ;
* V_8 = V_2 -> V_108 ;
return 0 ;
}
static int F_71 ( struct V_153 * V_153 , void * V_154 , unsigned int V_8 )
{
struct V_71 * V_72 = V_154 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_8 >= V_185 )
return - V_98 ;
if ( 0 == F_34 ( V_8 ) -> type )
return - V_98 ;
F_33 ( V_2 , V_8 ) ;
return 0 ;
}
static int F_72 ( struct V_153 * V_153 , void * V_154 , struct V_195 * V_196 )
{
struct V_71 * V_72 = V_154 ;
struct V_1 * V_2 = V_72 -> V_2 ;
if ( ! V_2 -> V_197 . V_198 )
return - V_98 ;
switch ( V_196 -> V_107 ) {
case V_199 :
strcpy ( V_196 -> V_187 , L_38 ) ;
break;
case V_200 :
strcpy ( V_196 -> V_187 , L_39 ) ;
break;
case V_201 :
strcpy ( V_196 -> V_187 , L_40 ) ;
break;
case V_202 :
strcpy ( V_196 -> V_187 , L_41 ) ;
break;
case V_203 :
strcpy ( V_196 -> V_187 , L_42 ) ;
break;
case V_204 :
strcpy ( V_196 -> V_187 , L_43 ) ;
break;
case V_205 :
strcpy ( V_196 -> V_187 , L_44 ) ;
break;
case V_206 :
strcpy ( V_196 -> V_187 , L_45 ) ;
break;
default:
return - V_98 ;
}
V_196 -> V_107 = V_2 -> V_109 ;
V_196 -> V_207 = V_208 ;
return 0 ;
}
static int F_73 ( struct V_153 * V_153 , void * V_154 , const struct V_195 * V_196 )
{
struct V_71 * V_72 = V_154 ;
struct V_1 * V_2 = V_72 -> V_2 ;
if ( ! V_2 -> V_197 . V_198 )
return - V_98 ;
if ( V_196 -> V_107 >= V_185 )
return - V_98 ;
if ( 0 == F_34 ( V_196 -> V_107 ) -> type )
return - V_98 ;
V_2 -> V_109 = F_34 ( V_196 -> V_107 ) -> V_110 ;
V_2 -> V_111 = F_34 ( V_196 -> V_107 ) -> V_112 ;
if ( ! V_2 -> V_111 )
V_2 -> V_111 = V_113 ;
return 0 ;
}
static int F_74 ( struct V_153 * V_153 , void * V_154 ,
struct V_132 * V_133 )
{
struct V_71 * V_72 = V_154 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_135 = V_133 -> V_135 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
memset ( V_133 , 0 , sizeof( * V_133 ) ) ;
V_133 -> V_135 = V_135 ;
if ( V_2 -> V_197 . V_209 != V_210 ) {
V_53 = F_44 ( V_133 ) ;
if ( ! V_53 )
return 0 ;
}
F_19 ( & V_2 -> V_86 , 0 , V_174 , V_211 , V_133 ) ;
if ( V_133 -> type )
return 0 ;
else
return - V_98 ;
}
static int F_75 ( struct V_1 * V_2 , int V_135 )
{
struct V_132 V_133 ;
memset ( & V_133 , 0 , sizeof( V_133 ) ) ;
V_133 . V_135 = V_135 ;
F_19 ( & V_2 -> V_86 , 0 , V_174 , V_211 , & V_133 ) ;
if ( V_133 . type )
return 0 ;
else
return - V_98 ;
}
static int F_76 ( struct V_153 * V_153 , void * V_154 ,
struct V_136 * V_137 )
{
struct V_71 * V_72 = V_154 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
V_53 = 0 ;
if ( V_2 -> V_197 . V_209 != V_210 )
V_53 = F_46 ( V_2 , V_137 ) ;
else
V_53 = 1 ;
if ( V_53 == 1 ) {
if ( F_75 ( V_2 , V_137 -> V_135 ) )
return - V_98 ;
F_19 ( & V_2 -> V_86 , 0 , V_174 , V_212 , V_137 ) ;
V_53 = 0 ;
}
return V_53 ;
}
static int F_77 ( struct V_153 * V_153 , void * V_154 ,
struct V_136 * V_137 )
{
struct V_71 * V_72 = V_154 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_2 -> V_197 . V_209 != V_210 )
V_53 = F_47 ( V_2 , V_137 ) ;
else
V_53 = 1 ;
if ( V_53 == 1 ) {
V_53 = F_75 ( V_2 , V_137 -> V_135 ) ;
if ( ! V_53 )
F_19 ( & V_2 -> V_86 , 0 ,
V_174 , V_213 , V_137 ) ;
switch ( V_137 -> V_135 ) {
case V_138 :
V_2 -> V_140 = V_137 -> V_139 ;
V_53 = F_36 ( V_2 ) ;
break;
case V_141 :
V_2 -> V_142 = V_137 -> V_139 ;
V_53 = F_36 ( V_2 ) ;
}
}
return ( V_53 < 0 ) ? V_53 : 0 ;
}
static int F_78 ( struct V_153 * V_153 , void * V_154 ,
struct V_214 * V_215 )
{
struct V_71 * V_72 = V_154 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( 0 != V_215 -> V_107 )
return - V_98 ;
strcpy ( V_215 -> V_187 , L_46 ) ;
V_215 -> type = V_85 ;
F_19 ( & V_2 -> V_86 , 0 , V_87 , V_216 , V_215 ) ;
return 0 ;
}
static int F_79 ( struct V_153 * V_153 , void * V_154 ,
struct V_214 * V_215 )
{
struct V_71 * V_72 = V_154 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( 0 != V_215 -> V_107 )
return - V_98 ;
F_19 ( & V_2 -> V_86 , 0 , V_87 , V_217 , V_215 ) ;
return 0 ;
}
static int F_80 ( struct V_153 * V_153 , void * V_154 ,
struct V_74 * V_75 )
{
struct V_71 * V_72 = V_154 ;
struct V_1 * V_2 = V_72 -> V_2 ;
V_75 -> type = V_72 -> V_83 ? V_84 : V_85 ;
V_75 -> V_81 = V_2 -> V_82 ;
return 0 ;
}
static int F_81 ( struct V_153 * V_153 , void * V_154 ,
struct V_74 * V_75 )
{
struct V_71 * V_72 = V_154 ;
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
static int F_83 ( int V_218 )
{
switch ( V_218 ) {
case V_219 :
case V_220 :
case V_221 :
return 2 ;
default:
return 1 ;
}
}
static int F_84 ( struct V_153 * V_153 , void * V_154 ,
struct V_222 * V_223 )
{
struct V_71 * V_72 = V_154 ;
struct V_1 * V_2 = V_72 -> V_2 ;
V_223 -> V_224 = V_225 ;
V_223 -> V_226 = 0 ;
F_19 ( & V_2 -> V_86 , 0 , V_174 , V_227 , V_223 ) ;
return 0 ;
}
static int F_85 ( struct V_153 * V_153 , void * V_154 ,
struct V_228 * V_218 )
{
struct V_71 * V_72 = V_154 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_229 ;
switch ( V_218 -> V_230 . type ) {
case V_231 :
V_229 = F_86 ( V_2 , V_218 -> V_218 ) ;
if ( V_229 < 0 )
return V_229 ;
V_218 -> V_232 = V_229 ;
V_218 -> V_32 = 1 ;
return 0 ;
case V_233 :
F_19 ( & V_2 -> V_86 , 0 , V_174 , V_234 , V_218 ) ;
return 0 ;
case V_235 :
F_19 ( & V_2 -> V_86 , 0 , V_174 , V_234 , V_218 ) ;
return 0 ;
default:
if ( ! F_87 ( & V_218 -> V_230 ) )
return - V_98 ;
}
V_218 -> V_32 = F_83 ( V_218 -> V_218 ) ;
if ( V_218 -> V_32 == 1 ) {
V_229 = F_88 ( V_2 , V_218 -> V_218 ) ;
if ( V_229 < 0 )
return V_229 ;
V_218 -> V_232 = V_229 ;
} else {
T_2 V_232 = 0 ;
V_229 = F_89 ( V_2 , V_236 ,
V_218 -> V_218 , ( char * ) & V_232 , 2 ) ;
if ( V_229 < 0 )
return V_229 ;
V_218 -> V_232 = F_90 ( V_232 ) ;
}
return 0 ;
}
static int F_91 ( struct V_153 * V_153 , void * V_154 ,
struct V_228 * V_218 )
{
struct V_71 * V_72 = V_154 ;
struct V_1 * V_2 = V_72 -> V_2 ;
T_2 V_6 ;
switch ( V_218 -> V_230 . type ) {
case V_231 :
return F_92 ( V_2 , V_218 -> V_218 , V_218 -> V_232 ) ;
case V_233 :
F_19 ( & V_2 -> V_86 , 0 , V_174 , V_237 , V_218 ) ;
return 0 ;
case V_235 :
F_19 ( & V_2 -> V_86 , 0 , V_174 , V_237 , V_218 ) ;
return 0 ;
default:
if ( ! F_87 ( & V_218 -> V_230 ) )
return - V_98 ;
}
V_6 = F_93 ( V_218 -> V_232 ) ;
return F_94 ( V_2 , V_218 -> V_218 , ( char * ) & V_6 ,
F_83 ( V_218 -> V_218 ) ) ;
}
static int F_95 ( struct V_153 * V_153 , void * V_154 ,
struct V_238 * V_239 )
{
struct V_71 * V_72 = V_154 ;
struct V_1 * V_2 = V_72 -> V_2 ;
if ( V_239 -> type != V_128 )
return - V_98 ;
V_239 -> V_240 . V_241 = 0 ;
V_239 -> V_240 . V_242 = 0 ;
V_239 -> V_240 . V_30 = V_2 -> V_30 ;
V_239 -> V_240 . V_76 = V_2 -> V_76 ;
V_239 -> V_243 = V_239 -> V_240 ;
V_239 -> V_244 . V_245 = 54 ;
V_239 -> V_244 . V_246 = 59 ;
return 0 ;
}
static int F_96 ( struct V_153 * V_153 , void * V_154 ,
enum V_247 type )
{
struct V_71 * V_72 = V_154 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 = - V_98 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( F_82 ( type != V_72 -> type ) )
return - V_98 ;
F_38 ( L_47 ,
V_72 , type , V_72 -> V_126 , V_2 -> V_126 ) ;
if ( F_82 ( ! F_37 ( V_72 , F_43 ( V_72 ) ) ) )
return - V_171 ;
if ( V_72 -> type == V_128 )
V_53 = F_97 ( & V_72 -> V_169 ) ;
else if ( V_72 -> type == V_130 )
V_53 = F_97 ( & V_72 -> V_248 ) ;
return V_53 ;
}
static int F_98 ( struct V_153 * V_153 , void * V_154 ,
enum V_247 type )
{
struct V_71 * V_72 = V_154 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_72 -> type != V_128 &&
V_72 -> type != V_130 )
return - V_98 ;
if ( type != V_72 -> type )
return - V_98 ;
F_38 ( L_48 ,
V_72 , type , V_72 -> V_126 , V_2 -> V_126 ) ;
if ( V_72 -> type == V_128 ) {
if ( F_39 ( V_72 , V_129 ) ) {
F_99 ( & V_72 -> V_169 ) ;
F_41 ( V_72 , V_129 ) ;
}
} else if ( V_72 -> type == V_130 ) {
if ( F_39 ( V_72 , V_131 ) ) {
F_99 ( & V_72 -> V_248 ) ;
F_41 ( V_72 , V_131 ) ;
}
}
return 0 ;
}
static int F_100 ( struct V_153 * V_153 , void * V_154 ,
struct V_249 * V_250 )
{
struct V_71 * V_72 = V_154 ;
struct V_1 * V_2 = V_72 -> V_2 ;
F_101 ( V_250 -> V_251 , L_49 , sizeof( V_250 -> V_251 ) ) ;
F_101 ( V_250 -> V_252 , V_253 [ V_2 -> V_254 ] . V_187 , sizeof( V_250 -> V_252 ) ) ;
F_102 ( V_2 -> V_255 , V_250 -> V_256 , sizeof( V_250 -> V_256 ) ) ;
V_250 -> V_257 =
V_258 |
V_259 |
V_260 | V_261 ;
if ( V_2 -> V_262 )
V_250 -> V_257 |= V_263 ;
if ( V_2 -> V_197 . V_198 )
V_250 -> V_257 |= V_264 ;
if ( V_2 -> V_265 != V_266 )
V_250 -> V_257 |= V_267 ;
return 0 ;
}
static int F_103 ( struct V_153 * V_153 , void * V_154 ,
struct V_268 * V_75 )
{
if ( F_82 ( V_75 -> V_107 >= F_45 ( V_77 ) ) )
return - V_98 ;
F_101 ( V_75 -> V_269 , V_77 [ V_75 -> V_107 ] . V_187 , sizeof( V_75 -> V_269 ) ) ;
V_75 -> V_158 = V_77 [ V_75 -> V_107 ] . V_159 ;
return 0 ;
}
static int F_104 ( struct V_153 * V_153 , void * V_154 ,
struct V_270 * V_271 )
{
struct V_71 * V_72 = V_154 ;
struct V_1 * V_2 = V_72 -> V_2 ;
struct V_167 * V_156 ;
unsigned int V_151 = F_51 ( V_2 ) ;
unsigned int V_152 = F_52 ( V_2 ) ;
V_156 = F_54 ( V_271 -> V_272 ) ;
if ( ! V_156 ) {
F_38 ( L_36 ,
V_271 -> V_272 ) ;
return - V_98 ;
}
if ( V_2 -> V_117 . V_168 ) {
if ( V_271 -> V_107 > 1 )
return - V_98 ;
V_271 -> type = V_273 ;
V_271 -> V_274 . V_30 = V_151 / ( 1 + V_271 -> V_107 ) ;
V_271 -> V_274 . V_76 = V_152 / ( 1 + V_271 -> V_107 ) ;
return 0 ;
}
if ( V_271 -> V_107 != 0 )
return - V_98 ;
V_271 -> type = V_275 ;
V_271 -> V_276 . V_277 = 48 ;
V_271 -> V_276 . V_278 = 32 ;
V_271 -> V_276 . V_279 = V_151 ;
V_271 -> V_276 . V_280 = V_152 ;
V_271 -> V_276 . V_281 = 1 ;
V_271 -> V_276 . V_282 = 1 ;
return 0 ;
}
static int F_105 ( struct V_153 * V_153 , void * V_154 ,
struct V_155 * V_75 )
{
struct V_71 * V_72 = V_154 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
V_75 -> V_156 . V_283 . V_284 = 0 ;
F_19 ( & V_2 -> V_86 , 0 , V_285 , V_286 , & V_75 -> V_156 . V_283 ) ;
if ( V_75 -> V_156 . V_283 . V_284 == 0 )
V_53 = - V_98 ;
return V_53 ;
}
static int F_106 ( struct V_153 * V_153 , void * V_154 ,
struct V_155 * V_75 )
{
struct V_71 * V_72 = V_154 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
F_19 ( & V_2 -> V_86 , 0 , V_285 , V_286 , & V_75 -> V_156 . V_283 ) ;
if ( V_75 -> V_156 . V_283 . V_284 == 0 )
return - V_98 ;
return 0 ;
}
static int F_107 ( struct V_153 * V_153 , void * V_154 ,
struct V_155 * V_77 )
{
struct V_71 * V_72 = V_154 ;
struct V_1 * V_2 = V_72 -> V_2 ;
V_77 -> V_156 . V_285 . V_287 = V_2 -> V_35 ;
V_77 -> V_156 . V_285 . V_288 = V_289 ;
V_77 -> V_156 . V_285 . V_26 = 0 ;
V_77 -> V_156 . V_285 . V_89 = 0 ;
V_77 -> V_156 . V_285 . V_290 = 6750000 * 4 / 2 ;
V_77 -> V_156 . V_285 . V_70 [ 0 ] = V_2 -> V_36 ;
V_77 -> V_156 . V_285 . V_70 [ 1 ] = V_2 -> V_36 ;
if ( V_2 -> V_172 & V_291 ) {
V_77 -> V_156 . V_285 . V_292 [ 0 ] = 10 ;
V_77 -> V_156 . V_285 . V_292 [ 1 ] = 273 ;
} else if ( V_2 -> V_172 & V_293 ) {
V_77 -> V_156 . V_285 . V_292 [ 0 ] = 6 ;
V_77 -> V_156 . V_285 . V_292 [ 1 ] = 318 ;
}
return 0 ;
}
static int F_108 ( struct V_153 * V_153 , void * V_154 ,
struct V_155 * V_77 )
{
struct V_71 * V_72 = V_154 ;
struct V_1 * V_2 = V_72 -> V_2 ;
V_77 -> V_156 . V_285 . V_287 = V_2 -> V_35 ;
V_77 -> V_156 . V_285 . V_288 = V_289 ;
V_77 -> V_156 . V_285 . V_26 = 0 ;
V_77 -> V_156 . V_285 . V_89 = 0 ;
V_77 -> V_156 . V_285 . V_290 = 6750000 * 4 / 2 ;
V_77 -> V_156 . V_285 . V_70 [ 0 ] = V_2 -> V_36 ;
V_77 -> V_156 . V_285 . V_70 [ 1 ] = V_2 -> V_36 ;
if ( V_2 -> V_172 & V_291 ) {
V_77 -> V_156 . V_285 . V_292 [ 0 ] = 10 ;
V_77 -> V_156 . V_285 . V_292 [ 1 ] = 273 ;
} else if ( V_2 -> V_172 & V_293 ) {
V_77 -> V_156 . V_285 . V_292 [ 0 ] = 6 ;
V_77 -> V_156 . V_285 . V_292 [ 1 ] = 318 ;
}
return 0 ;
}
static int F_109 ( struct V_153 * V_153 , void * V_154 ,
struct V_294 * V_295 )
{
struct V_71 * V_72 = V_154 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_72 -> type == V_128 )
return F_110 ( & V_72 -> V_169 , V_295 ) ;
else
return F_110 ( & V_72 -> V_248 , V_295 ) ;
}
static int F_111 ( struct V_153 * V_153 , void * V_154 ,
struct V_296 * V_297 )
{
struct V_71 * V_72 = V_154 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_72 -> type == V_128 )
return F_112 ( & V_72 -> V_169 , V_297 ) ;
else {
int V_298 = F_112 ( & V_72 -> V_248 , V_297 ) ;
V_297 -> V_299 = V_2 -> V_35 * V_2 -> V_36 * 2 ;
return V_298 ;
}
}
static int F_113 ( struct V_153 * V_153 , void * V_154 , struct V_296 * V_297 )
{
struct V_71 * V_72 = V_154 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_72 -> type == V_128 )
return F_114 ( & V_72 -> V_169 , V_297 ) ;
else
return F_114 ( & V_72 -> V_248 , V_297 ) ;
}
static int F_115 ( struct V_153 * V_153 , void * V_154 , struct V_296 * V_297 )
{
struct V_71 * V_72 = V_154 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_72 -> type == V_128 )
return F_116 ( & V_72 -> V_169 , V_297 , V_153 -> V_300 &
V_301 ) ;
else
return F_116 ( & V_72 -> V_248 , V_297 , V_153 -> V_300 &
V_301 ) ;
}
static int F_117 ( struct V_153 * V_153 , void * V_154 ,
struct V_249 * V_250 )
{
struct V_1 * V_2 = ( (struct V_71 * ) V_154 ) -> V_2 ;
F_101 ( V_250 -> V_251 , L_49 , sizeof( V_250 -> V_251 ) ) ;
F_101 ( V_250 -> V_252 , V_253 [ V_2 -> V_254 ] . V_187 , sizeof( V_250 -> V_252 ) ) ;
F_102 ( V_2 -> V_255 , V_250 -> V_256 , sizeof( V_250 -> V_256 ) ) ;
V_250 -> V_257 = V_267 ;
return 0 ;
}
static int F_118 ( struct V_153 * V_153 , void * V_154 ,
struct V_214 * V_215 )
{
struct V_1 * V_2 = ( (struct V_71 * ) V_154 ) -> V_2 ;
if ( F_82 ( V_215 -> V_107 > 0 ) )
return - V_98 ;
strcpy ( V_215 -> V_187 , L_50 ) ;
V_215 -> type = V_84 ;
F_19 ( & V_2 -> V_86 , 0 , V_87 , V_216 , V_215 ) ;
return 0 ;
}
static int F_119 ( struct V_153 * V_153 , void * V_154 ,
struct V_183 * V_8 )
{
if ( V_8 -> V_107 != 0 )
return - V_98 ;
strcpy ( V_8 -> V_187 , L_50 ) ;
V_8 -> type = V_191 ;
return 0 ;
}
static int F_120 ( struct V_153 * V_153 , void * V_154 , struct V_195 * V_196 )
{
if ( F_82 ( V_196 -> V_107 ) )
return - V_98 ;
strcpy ( V_196 -> V_187 , L_50 ) ;
return 0 ;
}
static int F_121 ( struct V_153 * V_153 , void * V_154 ,
struct V_214 * V_215 )
{
struct V_1 * V_2 = ( (struct V_71 * ) V_154 ) -> V_2 ;
if ( 0 != V_215 -> V_107 )
return - V_98 ;
F_19 ( & V_2 -> V_86 , 0 , V_87 , V_217 , V_215 ) ;
return 0 ;
}
static int F_122 ( struct V_153 * V_153 , void * V_72 ,
const struct V_195 * V_196 )
{
return 0 ;
}
static int F_123 ( struct V_153 * V_153 , void * V_72 , unsigned int V_8 )
{
return 0 ;
}
static int F_124 ( struct V_153 * V_153 , void * V_154 ,
struct V_132 * V_133 )
{
int V_8 ;
if ( V_133 -> V_135 < V_302 ||
V_133 -> V_135 >= V_303 )
return - V_98 ;
for ( V_8 = 0 ; V_8 < F_45 ( V_134 ) ; V_8 ++ ) {
if ( V_133 -> V_135 && V_133 -> V_135 == V_134 [ V_8 ] . V_135 ) {
memcpy ( V_133 , & ( V_134 [ V_8 ] ) , sizeof( * V_133 ) ) ;
return 0 ;
}
}
return - V_98 ;
}
static int F_125 ( struct V_153 * V_304 )
{
int V_305 = 0 , V_83 = 0 ;
struct V_306 * V_193 = F_126 ( V_304 ) ;
struct V_1 * V_2 = F_127 ( V_304 ) ;
enum V_247 V_307 = 0 ;
struct V_71 * V_72 ;
enum V_93 V_94 ;
switch ( V_193 -> V_308 ) {
case V_309 :
V_307 = V_128 ;
break;
case V_310 :
V_307 = V_130 ;
break;
case V_311 :
V_83 = 1 ;
break;
}
F_38 ( L_51 ,
F_128 ( V_193 ) , V_312 [ V_307 ] ,
V_2 -> V_313 ) ;
if ( F_129 ( & V_2 -> V_314 ) )
return - V_315 ;
V_72 = F_130 ( sizeof( struct V_71 ) , V_316 ) ;
if ( ! V_72 ) {
F_49 ( L_52 ) ;
F_131 ( & V_2 -> V_314 ) ;
return - V_317 ;
}
V_72 -> V_2 = V_2 ;
V_72 -> V_83 = V_83 ;
V_72 -> type = V_307 ;
V_304 -> V_318 = V_72 ;
if ( V_72 -> type == V_128 && V_2 -> V_313 == 0 ) {
F_132 ( V_2 , V_102 ) ;
F_58 ( V_2 ) ;
F_59 ( V_2 ) ;
F_133 ( V_2 ) ;
}
if ( V_72 -> V_83 ) {
F_38 ( L_53 ) ;
F_19 ( & V_2 -> V_86 , 0 , V_87 , V_319 ) ;
}
V_2 -> V_313 ++ ;
if ( V_2 -> V_33 )
V_94 = V_163 ;
else
V_94 = V_165 ;
F_134 ( & V_72 -> V_169 , & V_320 ,
NULL , & V_2 -> V_90 ,
V_128 , V_94 ,
sizeof( struct V_5 ) , V_72 , & V_2 -> V_314 ) ;
F_134 ( & V_72 -> V_248 , & V_321 ,
NULL , & V_2 -> V_90 ,
V_130 ,
V_322 ,
sizeof( struct V_5 ) , V_72 , & V_2 -> V_314 ) ;
F_131 ( & V_2 -> V_314 ) ;
return V_305 ;
}
void F_135 ( struct V_1 * V_2 )
{
if ( V_2 -> V_323 ) {
if ( F_136 ( V_2 -> V_323 ) )
F_137 ( V_2 -> V_323 ) ;
else
F_138 ( V_2 -> V_323 ) ;
V_2 -> V_323 = NULL ;
}
if ( V_2 -> V_262 ) {
F_139 ( L_54 ,
F_128 ( V_2 -> V_262 ) ) ;
if ( F_136 ( V_2 -> V_262 ) )
F_137 ( V_2 -> V_262 ) ;
else
F_138 ( V_2 -> V_262 ) ;
V_2 -> V_262 = NULL ;
}
if ( V_2 -> V_193 ) {
F_139 ( L_54 ,
F_128 ( V_2 -> V_193 ) ) ;
if ( F_136 ( V_2 -> V_193 ) )
F_137 ( V_2 -> V_193 ) ;
else
F_138 ( V_2 -> V_193 ) ;
V_2 -> V_193 = NULL ;
}
}
static int F_140 ( struct V_153 * V_304 )
{
struct V_71 * V_72 = V_304 -> V_318 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_305 ;
F_38 ( L_55 , V_2 -> V_313 ) ;
F_141 ( & V_2 -> V_314 ) ;
if ( F_39 ( V_72 , V_129 ) ) {
F_142 ( & V_72 -> V_169 ) ;
F_41 ( V_72 , V_129 ) ;
}
if ( F_39 ( V_72 , V_131 ) ) {
F_142 ( & V_72 -> V_248 ) ;
F_41 ( V_72 , V_131 ) ;
}
if ( V_2 -> V_313 == 1 ) {
if ( V_2 -> V_9 & V_54 ) {
F_143 ( V_2 ) ;
F_144 ( V_2 -> V_324 ) ;
F_131 ( & V_2 -> V_314 ) ;
F_144 ( V_2 ) ;
F_144 ( V_72 ) ;
return 0 ;
}
F_19 ( & V_2 -> V_86 , 0 , V_174 , V_325 , 0 ) ;
F_145 ( V_2 , V_102 ) ;
F_132 ( V_2 , V_326 ) ;
V_2 -> V_327 = 0 ;
F_38 ( L_56 ) ;
V_305 = F_146 ( V_2 -> V_255 , 0 , 0 ) ;
if ( V_305 < 0 ) {
F_49 ( L_57
L_58 , V_305 ) ;
}
}
F_147 ( & V_72 -> V_169 ) ;
F_147 ( & V_72 -> V_248 ) ;
F_144 ( V_72 ) ;
V_2 -> V_313 -- ;
F_131 ( & V_2 -> V_314 ) ;
return 0 ;
}
static T_3
F_148 ( struct V_153 * V_304 , char T_4 * V_6 , T_5 V_70 ,
T_6 * V_31 )
{
struct V_71 * V_72 = V_304 -> V_318 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( F_129 ( & V_2 -> V_314 ) )
return - V_315 ;
if ( V_72 -> type == V_128 ) {
if ( F_40 ( V_2 , V_129 ) )
V_53 = - V_171 ;
else
V_53 = F_149 ( & V_72 -> V_169 , V_6 , V_70 , V_31 , 0 ,
V_304 -> V_300 & V_301 ) ;
} else if ( V_72 -> type == V_130 ) {
if ( ! F_37 ( V_72 , V_131 ) )
V_53 = - V_171 ;
else
V_53 = F_149 ( & V_72 -> V_248 , V_6 , V_70 , V_31 , 0 ,
V_304 -> V_300 & V_301 ) ;
}
F_131 ( & V_2 -> V_314 ) ;
return V_53 ;
}
static unsigned int F_150 ( struct V_153 * V_304 , T_7 * V_328 )
{
struct V_71 * V_72 = V_304 -> V_318 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_72 -> type == V_128 ) {
if ( ! F_37 ( V_72 , V_129 ) )
return V_329 ;
return F_151 ( V_304 , & V_72 -> V_169 , V_328 ) ;
} else if ( V_72 -> type == V_130 ) {
if ( ! F_37 ( V_72 , V_131 ) )
return V_329 ;
return F_151 ( V_304 , & V_72 -> V_248 , V_328 ) ;
} else {
return V_329 ;
}
}
static unsigned int F_152 ( struct V_153 * V_304 , T_7 * V_328 )
{
struct V_71 * V_72 = V_304 -> V_318 ;
struct V_1 * V_2 = V_72 -> V_2 ;
unsigned int V_330 ;
F_141 ( & V_2 -> V_314 ) ;
V_330 = F_150 ( V_304 , V_328 ) ;
F_131 ( & V_2 -> V_314 ) ;
return V_330 ;
}
static int F_153 ( struct V_153 * V_304 , struct V_331 * V_332 )
{
struct V_71 * V_72 = V_304 -> V_318 ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_53 ;
V_53 = F_48 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( F_129 ( & V_2 -> V_314 ) )
return - V_315 ;
if ( V_72 -> type == V_128 )
V_53 = F_154 ( & V_72 -> V_169 , V_332 ) ;
else if ( V_72 -> type == V_130 )
V_53 = F_154 ( & V_72 -> V_248 , V_332 ) ;
F_131 ( & V_2 -> V_314 ) ;
F_38 ( L_59 ,
( unsigned long ) V_332 -> V_333 ,
( unsigned long ) V_332 -> V_334 - ( unsigned long ) V_332 -> V_333 ,
V_53 ) ;
return V_53 ;
}
static struct V_306 * F_155 ( struct V_1 * V_2 ,
const struct V_306 * V_335 ,
const char * V_336 )
{
struct V_306 * V_337 ;
V_337 = F_156 () ;
if ( NULL == V_337 )
return NULL ;
* V_337 = * V_335 ;
V_337 -> V_86 = & V_2 -> V_86 ;
V_337 -> V_338 = F_138 ;
V_337 -> V_339 = V_340 ;
V_337 -> V_314 = & V_2 -> V_314 ;
snprintf ( V_337 -> V_187 , sizeof( V_337 -> V_187 ) , L_60 ,
V_2 -> V_187 , V_336 ) ;
F_157 ( V_337 , V_2 ) ;
return V_337 ;
}
int F_158 ( struct V_1 * V_2 )
{
T_8 V_232 ;
int V_229 ;
unsigned int V_151 ;
F_159 ( V_341 L_61 ,
V_2 -> V_187 , V_342 ) ;
V_2 -> V_172 = V_343 . V_344 ;
F_19 ( & V_2 -> V_86 , 0 , V_174 , V_175 , V_2 -> V_172 ) ;
V_2 -> V_164 = V_345 ;
V_2 -> V_77 = & V_77 [ 0 ] ;
V_151 = F_51 ( V_2 ) ;
if ( V_2 -> V_117 . V_168 )
V_151 /= 2 ;
F_57 ( V_2 , V_77 [ 0 ] . V_159 ,
V_151 , F_52 ( V_2 ) ) ;
F_33 ( V_2 , 0 ) ;
V_2 -> V_140 = 1 ;
V_2 -> V_142 = 0x1f ;
V_232 = ( T_8 ) F_88 ( V_2 , V_346 ) ;
F_160 ( V_2 , V_346 ,
( V_347 | V_232 ) ) ;
F_161 ( V_2 ) ;
F_162 ( V_2 ) ;
F_163 ( V_2 ) ;
V_2 -> V_193 = F_155 ( V_2 , & V_343 , L_62 ) ;
if ( ! V_2 -> V_193 ) {
F_49 ( L_63 ) ;
return - V_147 ;
}
V_229 = F_164 ( V_2 -> V_193 , V_309 ,
V_348 [ V_2 -> V_349 ] ) ;
if ( V_229 ) {
F_49 ( L_64 ,
V_229 ) ;
return V_229 ;
}
if ( F_28 ( V_2 ) == 1 ) {
V_2 -> V_262 = F_155 ( V_2 , & V_343 ,
L_65 ) ;
V_229 = F_164 ( V_2 -> V_262 , V_310 ,
V_350 [ V_2 -> V_349 ] ) ;
if ( V_229 < 0 ) {
F_49 ( L_66 ) ;
return V_229 ;
}
}
if ( V_253 [ V_2 -> V_254 ] . V_83 . type == V_351 ) {
V_2 -> V_323 = F_155 ( V_2 , & V_352 ,
L_67 ) ;
if ( ! V_2 -> V_323 ) {
F_49 ( L_63 ) ;
return - V_147 ;
}
V_229 = F_164 ( V_2 -> V_323 , V_311 ,
V_353 [ V_2 -> V_349 ] ) ;
if ( V_229 < 0 ) {
F_49 ( L_68 ) ;
return V_229 ;
}
F_139 ( L_69 ,
F_128 ( V_2 -> V_323 ) ) ;
}
F_139 ( L_70 ,
F_128 ( V_2 -> V_193 ) ) ;
if ( V_2 -> V_262 )
F_139 ( L_71 ,
F_128 ( V_2 -> V_262 ) ) ;
return 0 ;
}
