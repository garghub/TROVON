static inline unsigned char * F_1 ( struct V_1 * V_2 , unsigned short type )
{
unsigned char * V_3 , * V_4 ;
unsigned short V_5 , V_6 ;
V_4 = V_3 = ( unsigned char * ) V_2 -> V_7 ;
while ( ( V_3 - V_4 ) < F_2 ( V_2 -> V_8 ) ) {
V_6 = ( unsigned short ) ( ( V_3 [ 0 ] << 8 ) + V_3 [ 1 ] ) ;
V_5 = ( unsigned short ) ( ( V_3 [ 2 ] << 8 ) + V_3 [ 3 ] ) ;
if ( V_6 == type )
return V_3 ;
V_3 = V_3 + V_9 + V_5 ;
}
return NULL ;
}
static inline int F_3 ( struct V_10 * V_11 , struct V_12 * V_7 )
{
struct V_1 * V_2 = (struct V_1 * ) ( V_11 -> V_13 + V_14 ) ;
int V_15 ;
V_15 = V_7 -> V_16 + V_9 ;
if ( F_4 ( V_11 ) < V_15 ) {
F_5 ( L_1 ) ;
return - 1 ;
}
F_6 ( V_11 , V_15 ) ;
memmove ( ( ( unsigned char * ) V_2 -> V_7 + V_15 ) , ( unsigned char * ) V_2 -> V_7 , F_2 ( V_2 -> V_8 ) ) ;
V_2 -> V_8 = F_7 ( F_2 ( V_2 -> V_8 ) + V_15 ) ;
memcpy ( ( unsigned char * ) V_2 -> V_7 , V_7 , V_15 ) ;
return V_15 ;
}
static int F_8 ( struct V_10 * V_11 , unsigned char * V_17 , int V_18 )
{
int V_19 ;
unsigned long V_20 , V_21 ;
if ( ( V_17 + V_18 ) > F_9 ( V_11 ) || V_11 -> V_18 < V_18 )
return - 1 ;
V_21 = ( unsigned long ) F_9 ( V_11 ) ;
V_20 = ( unsigned long ) V_17 + V_18 ;
if ( V_21 < V_20 )
return - 1 ;
V_19 = ( int ) ( V_21 - V_20 ) ;
if ( V_19 > 0 )
memmove ( V_17 , V_17 + V_18 , V_19 ) ;
F_10 ( V_11 , V_11 -> V_18 - V_18 ) ;
return 0 ;
}
static inline unsigned long F_11 ( struct V_22 * V_23 )
{
unsigned long V_24 ;
V_24 = V_25 - V_26 * V_27 ;
return V_24 ;
}
static inline int F_12 ( struct V_22 * V_23 ,
struct V_28 * V_29 )
{
if ( F_13 ( V_29 -> V_30 , F_11 ( V_23 ) ) )
return 1 ;
return 0 ;
}
static inline void F_14 ( unsigned char * V_31 ,
unsigned int * V_32 )
{
memset ( V_31 , 0 , V_33 ) ;
V_31 [ 0 ] = V_34 ;
memcpy ( V_31 + 7 , ( unsigned char * ) V_32 , 4 ) ;
}
static inline void F_15 ( unsigned char * V_31 ,
unsigned int * V_35 , unsigned char * V_36 )
{
memset ( V_31 , 0 , V_33 ) ;
V_31 [ 0 ] = V_37 ;
memcpy ( V_31 + 1 , ( unsigned char * ) V_35 , 4 ) ;
memcpy ( V_31 + 5 , V_36 , 6 ) ;
}
static inline void F_16 ( unsigned char * V_31 ,
unsigned int * V_35 , unsigned short * V_38 )
{
memset ( V_31 , 0 , V_33 ) ;
V_31 [ 0 ] = V_37 ;
memcpy ( V_31 + 1 , ( unsigned char * ) V_35 , 4 ) ;
memcpy ( V_31 + 5 , ( unsigned char * ) V_38 , 2 ) ;
}
static inline void F_17 ( unsigned char * V_31 ,
unsigned short * V_39 , unsigned char * V_40 )
{
memset ( V_31 , 0 , V_33 ) ;
V_31 [ 0 ] = V_41 ;
memcpy ( V_31 + 1 , ( unsigned char * ) V_39 , 2 ) ;
V_31 [ 3 ] = * V_40 ;
}
static inline void F_18 ( unsigned char * V_31 ,
unsigned char * V_42 , unsigned short * V_43 )
{
memset ( V_31 , 0 , V_33 ) ;
V_31 [ 0 ] = V_44 ;
memcpy ( V_31 + 1 , ( unsigned char * ) V_43 , 2 ) ;
memcpy ( V_31 + 3 , ( unsigned char * ) V_42 , 6 ) ;
}
static void F_19 ( unsigned char * V_31 ,
unsigned int * V_32 )
{
memset ( V_31 , 0 , V_33 ) ;
V_31 [ 0 ] = V_45 ;
memcpy ( V_31 + 1 , ( unsigned char * ) V_32 , 16 ) ;
}
static unsigned char * F_20 ( unsigned char * V_13 , int V_18 , unsigned char V_7 , unsigned char V_46 )
{
while ( V_18 > 0 ) {
if ( * V_13 == V_7 && * ( V_13 + 1 ) == V_46 && V_18 >= V_46 * 8 )
return V_13 + 2 ;
V_18 -= ( * ( V_13 + 1 ) ) * 8 ;
V_13 += ( * ( V_13 + 1 ) ) * 8 ;
}
return NULL ;
}
static int F_21 ( unsigned char * V_13 , int V_18 , unsigned char * V_47 )
{
struct V_48 * V_49 = (struct V_48 * ) V_13 ;
unsigned char * V_50 ;
if ( V_49 -> V_51 == V_52 ) {
if ( V_18 >= 8 ) {
V_50 = F_20 ( & V_13 [ 8 ] , V_18 - 8 , 1 , 1 ) ;
if ( V_50 ) {
F_22 ( L_2 ,
V_50 [ 0 ] , V_50 [ 1 ] , V_50 [ 2 ] , V_50 [ 3 ] , V_50 [ 4 ] , V_50 [ 5 ] ,
V_47 [ 0 ] , V_47 [ 1 ] , V_47 [ 2 ] , V_47 [ 3 ] , V_47 [ 4 ] , V_47 [ 5 ] ) ;
memcpy ( V_50 , V_47 , 6 ) ;
return 1 ;
}
}
} else if ( V_49 -> V_51 == V_53 ) {
if ( V_18 >= 16 ) {
V_50 = F_20 ( & V_13 [ 16 ] , V_18 - 16 , 1 , 1 ) ;
if ( V_50 ) {
F_22 ( L_3 ,
V_50 [ 0 ] , V_50 [ 1 ] , V_50 [ 2 ] , V_50 [ 3 ] , V_50 [ 4 ] , V_50 [ 5 ] ,
V_47 [ 0 ] , V_47 [ 1 ] , V_47 [ 2 ] , V_47 [ 3 ] , V_47 [ 4 ] , V_47 [ 5 ] ) ;
memcpy ( V_50 , V_47 , 6 ) ;
return 1 ;
}
}
} else if ( V_49 -> V_51 == V_54 ) {
if ( V_18 >= 24 ) {
V_50 = F_20 ( & V_13 [ 24 ] , V_18 - 24 , 1 , 1 ) ;
if ( V_50 ) {
F_22 ( L_4 ,
V_50 [ 0 ] , V_50 [ 1 ] , V_50 [ 2 ] , V_50 [ 3 ] , V_50 [ 4 ] , V_50 [ 5 ] ,
V_47 [ 0 ] , V_47 [ 1 ] , V_47 [ 2 ] , V_47 [ 3 ] , V_47 [ 4 ] , V_47 [ 5 ] ) ;
memcpy ( V_50 , V_47 , 6 ) ;
return 1 ;
}
}
} else if ( V_49 -> V_51 == V_55 ) {
if ( V_18 >= 24 ) {
V_50 = F_20 ( & V_13 [ 24 ] , V_18 - 24 , 2 , 1 ) ;
if ( V_50 ) {
F_22 ( L_5 ,
V_50 [ 0 ] , V_50 [ 1 ] , V_50 [ 2 ] , V_50 [ 3 ] , V_50 [ 4 ] , V_50 [ 5 ] ,
V_47 [ 0 ] , V_47 [ 1 ] , V_47 [ 2 ] , V_47 [ 3 ] , V_47 [ 4 ] , V_47 [ 5 ] ) ;
memcpy ( V_50 , V_47 , 6 ) ;
return 1 ;
}
}
} else if ( V_49 -> V_51 == V_56 ) {
if ( V_18 >= 40 ) {
V_50 = F_20 ( & V_13 [ 40 ] , V_18 - 40 , 2 , 1 ) ;
if ( V_50 ) {
F_22 ( L_6 ,
V_50 [ 0 ] , V_50 [ 1 ] , V_50 [ 2 ] , V_50 [ 3 ] , V_50 [ 4 ] , V_50 [ 5 ] ,
V_47 [ 0 ] , V_47 [ 1 ] , V_47 [ 2 ] , V_47 [ 3 ] , V_47 [ 4 ] , V_47 [ 5 ] ) ;
memcpy ( V_50 , V_47 , 6 ) ;
return 1 ;
}
}
}
return 0 ;
}
static inline int F_23 ( unsigned char * V_31 )
{
if ( V_31 [ 0 ] == V_34 ) {
unsigned long V_57 ;
V_57 = V_31 [ 7 ] ^ V_31 [ 8 ] ^ V_31 [ 9 ] ^ V_31 [ 10 ] ;
return V_57 & ( V_58 - 1 ) ;
} else if ( V_31 [ 0 ] == V_37 ) {
unsigned long V_57 ;
V_57 = V_31 [ 1 ] ^ V_31 [ 2 ] ^ V_31 [ 3 ] ^ V_31 [ 4 ] ^ V_31 [ 5 ] ^
V_31 [ 6 ] ^ V_31 [ 7 ] ^ V_31 [ 8 ] ^ V_31 [ 9 ] ^ V_31 [ 10 ] ;
return V_57 & ( V_58 - 1 ) ;
} else if ( V_31 [ 0 ] == V_41 ) {
unsigned long V_57 ;
V_57 = V_31 [ 1 ] ^ V_31 [ 2 ] ^ V_31 [ 3 ] ;
return V_57 & ( V_58 - 1 ) ;
} else if ( V_31 [ 0 ] == V_44 ) {
unsigned long V_57 ;
V_57 = V_31 [ 0 ] ^ V_31 [ 1 ] ^ V_31 [ 2 ] ^ V_31 [ 3 ] ^ V_31 [ 4 ] ^ V_31 [ 5 ] ^ V_31 [ 6 ] ^ V_31 [ 7 ] ^ V_31 [ 8 ] ;
return V_57 & ( V_58 - 1 ) ;
} else if ( V_31 [ 0 ] == V_45 ) {
unsigned long V_57 ;
V_57 = V_31 [ 1 ] ^ V_31 [ 2 ] ^ V_31 [ 3 ] ^ V_31 [ 4 ] ^ V_31 [ 5 ] ^
V_31 [ 6 ] ^ V_31 [ 7 ] ^ V_31 [ 8 ] ^ V_31 [ 9 ] ^ V_31 [ 10 ] ^
V_31 [ 11 ] ^ V_31 [ 12 ] ^ V_31 [ 13 ] ^ V_31 [ 14 ] ^ V_31 [ 15 ] ^
V_31 [ 16 ] ;
return V_57 & ( V_58 - 1 ) ;
} else {
unsigned long V_57 = 0 ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_33 ; V_59 ++ )
V_57 ^= V_31 [ V_59 ] ;
return V_57 & ( V_58 - 1 ) ;
}
}
static inline void F_24 ( struct V_22 * V_23 ,
struct V_28 * V_60 , int V_61 )
{
V_60 -> V_62 = V_23 -> V_63 [ V_61 ] ;
if ( V_60 -> V_62 != NULL )
V_60 -> V_62 -> V_64 = & V_60 -> V_62 ;
V_23 -> V_63 [ V_61 ] = V_60 ;
V_60 -> V_64 = & V_23 -> V_63 [ V_61 ] ;
}
static inline void F_25 ( struct V_28 * V_60 )
{
* ( V_60 -> V_64 ) = V_60 -> V_62 ;
if ( V_60 -> V_62 != NULL )
V_60 -> V_62 -> V_64 = V_60 -> V_64 ;
V_60 -> V_62 = NULL ;
V_60 -> V_64 = NULL ;
}
static int F_26 ( struct V_22 * V_23 ,
struct V_10 * V_11 , unsigned char * V_31 )
{
struct V_28 * V_65 ;
unsigned long V_66 ;
F_27 ( & V_23 -> V_67 , & V_66 ) ;
V_65 = V_23 -> V_63 [ F_23 ( V_31 ) ] ;
while ( V_65 != NULL ) {
if ( ! memcmp ( V_65 -> V_31 , V_31 , V_33 ) ) {
if ( ! F_12 ( V_23 , V_65 ) ) {
memcpy ( V_11 -> V_13 , V_65 -> V_68 , V_69 ) ;
F_28 ( & V_65 -> V_70 ) ;
F_29 ( L_7
L_8 ,
V_65 -> V_68 [ 0 ] ,
V_65 -> V_68 [ 1 ] ,
V_65 -> V_68 [ 2 ] ,
V_65 -> V_68 [ 3 ] ,
V_65 -> V_68 [ 4 ] ,
V_65 -> V_68 [ 5 ] ,
V_65 -> V_31 [ 0 ] ,
V_65 -> V_31 [ 1 ] ,
V_65 -> V_31 [ 2 ] ,
V_65 -> V_31 [ 3 ] ,
V_65 -> V_31 [ 4 ] ,
V_65 -> V_31 [ 5 ] ,
V_65 -> V_31 [ 6 ] ,
V_65 -> V_31 [ 7 ] ,
V_65 -> V_31 [ 8 ] ,
V_65 -> V_31 [ 9 ] ,
V_65 -> V_31 [ 10 ] ,
V_65 -> V_31 [ 11 ] ,
V_65 -> V_31 [ 12 ] ,
V_65 -> V_31 [ 13 ] ,
V_65 -> V_31 [ 14 ] ,
V_65 -> V_31 [ 15 ] ,
V_65 -> V_31 [ 16 ] ) ;
}
F_30 ( & V_23 -> V_67 , & V_66 ) ;
return 1 ;
}
V_65 = V_65 -> V_62 ;
}
F_30 ( & V_23 -> V_67 , & V_66 ) ;
return 0 ;
}
static void F_31 ( struct V_22 * V_23 ,
unsigned char * V_68 , unsigned char * V_31 )
{
struct V_28 * V_65 ;
int V_61 ;
unsigned long V_66 ;
F_27 ( & V_23 -> V_67 , & V_66 ) ;
V_61 = F_23 ( V_31 ) ;
V_65 = V_23 -> V_63 [ V_61 ] ;
while ( V_65 != NULL ) {
if ( ! memcmp ( V_65 -> V_31 , V_31 , V_33 ) ) {
memcpy ( V_65 -> V_68 , V_68 , V_69 ) ;
V_65 -> V_30 = V_25 ;
F_30 ( & V_23 -> V_67 , & V_66 ) ;
return;
}
V_65 = V_65 -> V_62 ;
}
V_65 = (struct V_28 * ) F_32 ( sizeof( * V_65 ) ) ;
if ( V_65 == NULL ) {
F_30 ( & V_23 -> V_67 , & V_66 ) ;
return;
}
memcpy ( V_65 -> V_31 , V_31 , V_33 ) ;
memcpy ( V_65 -> V_68 , V_68 , V_69 ) ;
F_33 ( & V_65 -> V_70 , 1 ) ;
V_65 -> V_30 = V_25 ;
F_24 ( V_23 , V_65 , V_61 ) ;
F_30 ( & V_23 -> V_67 , & V_66 ) ;
}
static void F_34 ( struct V_22 * V_23 )
{
}
void F_35 ( struct V_22 * V_23 )
{
int V_59 ;
unsigned long V_66 ;
F_27 ( & V_23 -> V_67 , & V_66 ) ;
for ( V_59 = 0 ; V_59 < V_58 ; V_59 ++ ) {
struct V_28 * V_71 ;
V_71 = V_23 -> V_63 [ V_59 ] ;
while ( V_71 != NULL ) {
struct V_28 * V_72 ;
V_72 = V_71 -> V_62 ;
if ( V_23 -> V_73 == V_71 ) {
memset ( V_23 -> V_74 , 0 , V_69 ) ;
memset ( V_23 -> V_75 , 0 , 4 ) ;
V_23 -> V_73 = NULL ;
}
F_25 ( V_71 ) ;
F_36 ( V_71 ) ;
V_71 = V_72 ;
}
}
F_30 ( & V_23 -> V_67 , & V_66 ) ;
}
void F_37 ( struct V_22 * V_23 )
{
int V_59 ;
unsigned long V_66 ;
F_27 ( & V_23 -> V_67 , & V_66 ) ;
for ( V_59 = 0 ; V_59 < V_58 ; V_59 ++ ) {
struct V_28 * V_71 ;
V_71 = V_23 -> V_63 [ V_59 ] ;
while ( V_71 != NULL ) {
struct V_28 * V_72 ;
V_72 = V_71 -> V_62 ;
if ( F_12 ( V_23 , V_71 ) ) {
if ( F_38 ( & V_71 -> V_70 ) ) {
if ( V_23 -> V_73 == V_71 ) {
memset ( V_23 -> V_74 , 0 , V_69 ) ;
memset ( V_23 -> V_75 , 0 , 4 ) ;
V_23 -> V_73 = NULL ;
}
F_25 ( V_71 ) ;
F_36 ( V_71 ) ;
}
}
V_71 = V_72 ;
}
}
F_30 ( & V_23 -> V_67 , & V_66 ) ;
}
int F_39 ( struct V_22 * V_23 , struct V_10 * V_11 , int V_76 )
{
unsigned short V_77 ;
unsigned char V_31 [ V_33 ] ;
unsigned int V_78 ;
if ( V_11 == NULL )
return - 1 ;
if ( ( V_76 <= V_79 ) || ( V_76 >= V_80 ) )
return - 1 ;
V_77 = F_40 ( * ( ( V_81 * ) ( V_11 -> V_13 + 2 * V_69 ) ) ) ;
if ( V_77 == V_82 ) {
struct V_83 * V_84 = (struct V_83 * ) ( V_11 -> V_13 + V_14 ) ;
if ( ( ( unsigned char * ) ( V_84 ) + ( V_84 -> V_85 << 2 ) ) >= ( V_11 -> V_13 + V_14 + V_11 -> V_18 ) ) {
F_41 ( L_9 ) ;
return - 1 ;
}
switch ( V_76 ) {
case V_86 :
return - 1 ;
case V_87 :
if ( V_84 -> V_88 == 0 )
return 0 ;
V_78 = F_42 ( V_84 -> V_88 ) ;
F_29 ( L_10 , V_78 , V_84 -> V_89 ) ;
F_14 ( V_31 , & V_78 ) ;
F_31 ( V_23 , V_11 -> V_13 + V_69 , V_31 ) ;
F_34 ( V_23 ) ;
return 0 ;
case V_90 :
F_29 ( L_11 , V_84 -> V_88 , V_84 -> V_89 ) ;
V_78 = F_42 ( V_84 -> V_89 ) ;
F_14 ( V_31 , & V_78 ) ;
if ( ! F_26 ( V_23 , V_11 , V_31 ) ) {
if ( * ( ( unsigned char * ) & V_84 -> V_89 + 3 ) == 0xff ) {
F_29 ( L_12 ) ;
memset ( V_11 -> V_13 , 0xff , V_69 ) ;
} else {
F_29 ( L_13 ) ;
if ( ( * ( V_91 * ) V_23 -> V_92 ) == 0 && ( * ( V_93 * ) ( V_23 -> V_92 + 4 ) ) == 0 ) {
F_43 ( L_14 ) ;
F_44 ( V_23 -> V_94 ) ;
}
memcpy ( V_11 -> V_13 , V_23 -> V_92 , V_69 ) ;
}
}
return 0 ;
default:
return - 1 ;
}
} else if ( V_77 == V_95 ) {
struct V_96 * V_97 = (struct V_96 * ) ( V_11 -> V_13 + V_14 ) ;
unsigned char * V_98 = ( unsigned char * ) ( V_97 + 1 ) ;
unsigned int * V_99 , * V_100 ;
if ( V_97 -> V_101 != F_45 ( V_82 ) ) {
F_41 ( L_15 , F_40 ( V_97 -> V_101 ) ) ;
return - 1 ;
}
switch ( V_76 ) {
case V_86 :
return 0 ;
case V_87 :
F_29 ( L_16 , V_98 [ 0 ] ,
V_98 [ 1 ] , V_98 [ 2 ] , V_98 [ 3 ] , V_98 [ 4 ] , V_98 [ 5 ] ) ;
memcpy ( V_98 , F_46 ( V_23 ) , V_69 ) ;
V_98 += V_97 -> V_102 ;
V_99 = ( unsigned int * ) V_98 ;
F_14 ( V_31 , V_99 ) ;
F_31 ( V_23 , V_11 -> V_13 + V_69 , V_31 ) ;
F_34 ( V_23 ) ;
return 0 ;
case V_90 :
F_29 ( L_17 ) ;
V_98 += V_97 -> V_102 ;
V_99 = ( unsigned int * ) V_98 ;
V_98 += ( V_97 -> V_102 + V_97 -> V_103 ) ;
V_100 = ( unsigned int * ) V_98 ;
F_14 ( V_31 , V_100 ) ;
F_26 ( V_23 , V_11 , V_31 ) ;
V_98 = ( unsigned char * ) ( V_97 + 1 ) ;
V_98 += ( V_97 -> V_102 + V_97 -> V_103 ) ;
memcpy ( V_98 , V_11 -> V_13 , V_69 ) ;
return 0 ;
default:
return - 1 ;
}
} else if ( ( V_77 == V_104 ) ||
( V_77 <= V_105 ) ) {
unsigned char V_106 [ 2 ] = { 0xFF , 0xFF } ;
struct V_107 * V_108 = NULL ;
struct V_109 * V_110 = NULL ;
struct V_111 * V_112 = NULL ;
unsigned char * V_113 = V_11 -> V_13 + V_14 ;
if ( V_77 == V_104 ) {
F_29 ( L_18 ) ;
V_108 = (struct V_107 * ) V_113 ;
} else if ( V_77 <= V_105 ) {
if ( ! memcmp ( V_106 , V_113 , 2 ) ) {
F_29 ( L_19 ) ;
V_108 = (struct V_107 * ) V_113 ;
} else {
unsigned char V_114 = 0xE0 ;
unsigned char V_115 = 0xAA ;
if ( * V_113 == V_115 ) {
unsigned char V_116 [ 5 ] = { 0x0 , 0x0 , 0x0 , 0x81 , 0x37 } ;
unsigned char V_117 [ 5 ] = { 0x00 , 0x00 , 0x00 , 0x80 , 0xF3 } ;
unsigned char V_118 [ 5 ] = { 0x08 , 0x00 , 0x07 , 0x80 , 0x9B } ;
V_113 += 3 ;
if ( ! memcmp ( V_116 , V_113 , 5 ) ) {
V_113 += 5 ;
F_29 ( L_20 ) ;
V_108 = (struct V_107 * ) V_113 ;
} else if ( ! memcmp ( V_117 , V_113 , 5 ) ) {
V_113 += 5 ;
V_110 = (struct V_109 * ) V_113 ;
} else if ( ! memcmp ( V_118 , V_113 , 5 ) ) {
V_113 += 5 ;
V_112 = (struct V_111 * ) V_113 ;
} else {
F_41 ( L_21 , V_113 [ 0 ] ,
V_113 [ 1 ] , V_113 [ 2 ] , V_113 [ 3 ] , V_113 [ 4 ] ) ;
return - 1 ;
}
} else if ( * V_113 == V_114 ) {
V_113 += 3 ;
if ( ! memcmp ( V_106 , V_113 , 2 ) ) {
F_29 ( L_22 ) ;
V_108 = (struct V_107 * ) V_113 ;
} else {
return - 1 ;
}
} else {
return - 1 ;
}
}
} else {
return - 1 ;
}
if ( V_108 != NULL ) {
switch ( V_76 ) {
case V_86 :
if ( ! memcmp ( V_11 -> V_13 + V_69 , V_108 -> V_119 . V_40 , V_69 ) )
F_29 ( L_23 ) ;
return 0 ;
return - 1 ;
case V_87 :
F_29 ( L_24 ,
V_108 -> V_120 . V_121 ,
V_108 -> V_120 . V_40 [ 0 ] ,
V_108 -> V_120 . V_40 [ 1 ] ,
V_108 -> V_120 . V_40 [ 2 ] ,
V_108 -> V_120 . V_40 [ 3 ] ,
V_108 -> V_120 . V_40 [ 4 ] ,
V_108 -> V_120 . V_40 [ 5 ] ,
V_108 -> V_120 . V_122 ,
V_108 -> V_119 . V_121 ,
V_108 -> V_119 . V_40 [ 0 ] ,
V_108 -> V_119 . V_40 [ 1 ] ,
V_108 -> V_119 . V_40 [ 2 ] ,
V_108 -> V_119 . V_40 [ 3 ] ,
V_108 -> V_119 . V_40 [ 4 ] ,
V_108 -> V_119 . V_40 [ 5 ] ,
V_108 -> V_119 . V_122 ) ;
if ( ! memcmp ( V_11 -> V_13 + V_69 , V_108 -> V_119 . V_40 , V_69 ) ) {
F_29 ( L_25 ) ;
F_16 ( V_31 , & V_108 -> V_119 . V_121 , & V_108 -> V_119 . V_122 ) ;
memcpy ( V_108 -> V_119 . V_40 , F_46 ( V_23 ) , V_69 ) ;
} else {
F_15 ( V_31 , & V_108 -> V_119 . V_121 , V_108 -> V_119 . V_40 ) ;
}
F_31 ( V_23 , V_11 -> V_13 + V_69 , V_31 ) ;
F_34 ( V_23 ) ;
return 0 ;
case V_90 :
if ( ! memcmp ( F_46 ( V_23 ) , V_108 -> V_120 . V_40 , V_69 ) ) {
F_29 ( L_26 ) ;
F_16 ( V_31 , & V_108 -> V_120 . V_121 , & V_108 -> V_120 . V_122 ) ;
F_26 ( V_23 , V_11 , V_31 ) ;
memcpy ( V_108 -> V_120 . V_40 , V_11 -> V_13 , V_69 ) ;
} else {
F_15 ( V_31 , & V_108 -> V_120 . V_121 , V_108 -> V_120 . V_40 ) ;
F_26 ( V_23 , V_11 , V_31 ) ;
}
return 0 ;
default:
return - 1 ;
}
} else if ( V_110 != NULL ) {
if ( V_110 -> V_123 != V_69 || V_110 -> V_124 != V_125 ) {
F_41 ( L_27 ) ;
return - 1 ;
}
switch ( V_76 ) {
case V_86 :
return 0 ;
case V_87 :
memcpy ( V_110 -> V_126 , F_46 ( V_23 ) , V_69 ) ;
F_29 ( L_28 ,
V_110 -> V_127 ,
V_110 -> V_128 ,
V_110 -> V_129 ,
V_110 -> V_130 ) ;
F_17 ( V_31 , & V_110 -> V_127 , & V_110 -> V_128 ) ;
F_31 ( V_23 , V_11 -> V_13 + V_69 , V_31 ) ;
F_34 ( V_23 ) ;
return 0 ;
case V_90 :
F_29 ( L_29 ,
V_110 -> V_127 ,
V_110 -> V_128 ,
V_110 -> V_129 ,
V_110 -> V_130 ) ;
F_17 ( V_31 , & V_110 -> V_129 , & V_110 -> V_130 ) ;
F_26 ( V_23 , V_11 , V_31 ) ;
memcpy ( V_110 -> V_131 , V_11 -> V_13 , V_69 ) ;
return 0 ;
default:
return - 1 ;
}
} else if ( V_112 != NULL ) {
switch ( V_76 ) {
case V_86 :
return - 1 ;
case V_87 :
F_29 ( L_30 ,
V_112 -> V_132 ,
V_112 -> V_133 ,
V_112 -> V_134 ,
V_112 -> V_135 ) ;
F_17 ( V_31 , & V_112 -> V_132 , & V_112 -> V_133 ) ;
F_31 ( V_23 , V_11 -> V_13 + V_69 , V_31 ) ;
F_34 ( V_23 ) ;
return 0 ;
case V_90 :
F_29 ( L_31 ,
V_112 -> V_132 ,
V_112 -> V_133 ,
V_112 -> V_134 ,
V_112 -> V_135 ) ;
F_17 ( V_31 , & V_112 -> V_134 , & V_112 -> V_135 ) ;
F_26 ( V_23 , V_11 , V_31 ) ;
return 0 ;
default:
return - 1 ;
}
}
return - 1 ;
} else if ( ( V_77 == V_136 ) ||
( V_77 == V_137 ) ) {
struct V_1 * V_2 = (struct V_1 * ) ( V_11 -> V_13 + V_14 ) ;
unsigned short * V_138 ;
switch ( V_76 ) {
case V_86 :
if ( V_2 -> V_43 == 0 )
return 0 ;
return 1 ;
case V_87 :
if ( V_2 -> V_43 == 0 ) {
if ( V_2 -> V_139 == V_140 || V_2 -> V_139 == V_141 ) {
if ( V_23 -> V_142 . V_143 ) {
struct V_12 * V_7 , * V_144 ;
unsigned char V_145 [ 40 ] ;
int V_146 = 0 ;
V_7 = (struct V_12 * ) V_145 ;
V_144 = (struct V_12 * ) F_1 ( V_2 , F_2 ( V_147 ) ) ;
if ( V_144 ) {
V_146 = F_2 ( V_144 -> V_16 ) ;
if ( V_146 + V_9 + V_148 + V_149 > sizeof( V_145 ) ) {
F_47 ( L_32 ) ;
return - 1 ;
}
memcpy ( V_7 -> V_150 + V_148 + V_149 ,
V_144 -> V_150 , V_146 ) ;
if ( F_8 ( V_11 , ( unsigned char * ) V_144 , V_9 + V_146 ) < 0 ) {
F_47 ( L_33 ) ;
return - 1 ;
}
V_2 -> V_8 = F_7 ( F_2 ( V_2 -> V_8 ) - V_9 - V_146 ) ;
}
V_7 -> V_151 = V_147 ;
V_7 -> V_16 = F_7 ( V_148 + V_149 + V_146 ) ;
V_138 = ( unsigned short * ) V_7 -> V_150 ;
* V_138 = F_7 ( V_152 ) ;
memcpy ( V_7 -> V_150 + V_148 , V_11 -> V_13 + V_69 , V_69 ) ;
if ( F_3 ( V_11 , V_7 ) < 0 )
return - 1 ;
F_29 ( L_34 ,
( V_2 -> V_139 == V_140 ? L_35 : L_36 ) ) ;
} else {
if ( V_23 -> V_153 &&
memcmp ( V_11 -> V_13 + V_69 , V_23 -> V_154 , V_69 ) ) {
F_47 ( L_37 ) ;
return - 2 ;
}
if ( V_23 -> V_153 == 0 )
memcpy ( V_23 -> V_154 , V_11 -> V_13 + V_69 , V_69 ) ;
V_23 -> V_153 = V_155 ;
}
} else {
return - 1 ;
}
} else {
F_29 ( L_38 , V_11 -> V_156 -> V_157 ) ;
F_18 ( V_31 , V_11 -> V_13 , & ( V_2 -> V_43 ) ) ;
F_31 ( V_23 , V_11 -> V_13 + V_69 , V_31 ) ;
F_34 ( V_23 ) ;
if ( ! V_23 -> V_142 . V_143 &&
V_23 -> V_153 &&
! memcmp ( V_11 -> V_13 + V_69 , V_23 -> V_154 , V_69 ) )
V_23 -> V_153 = 0 ;
}
return 0 ;
case V_90 :
if ( V_2 -> V_139 == V_158 || V_2 -> V_139 == V_159 ) {
if ( V_23 -> V_142 . V_143 ) {
struct V_12 * V_7 ;
unsigned char * V_160 ;
unsigned short V_6 , V_5 ;
int V_161 = 0 ;
V_160 = F_1 ( V_2 , F_2 ( V_147 ) ) ;
if ( V_160 == NULL ) {
F_47 ( L_39 ) ;
return - 1 ;
}
V_7 = (struct V_12 * ) V_160 ;
V_6 = ( unsigned short ) ( ( V_160 [ 0 ] << 8 ) + V_160 [ 1 ] ) ;
V_5 = ( unsigned short ) ( ( V_160 [ 2 ] << 8 ) + V_160 [ 3 ] ) ;
if ( ( V_6 != F_2 ( V_147 ) ) || ( V_5 < ( V_148 + V_149 ) ) ) {
F_47 ( L_40 , V_5 ) ;
return - 1 ;
}
V_138 = ( unsigned short * ) V_7 -> V_150 ;
if ( F_2 ( * V_138 ) != V_152 ) {
F_47 ( L_41 ,
( V_2 -> V_139 == V_158 ? L_42 : L_43 ) ) ;
return - 1 ;
}
memcpy ( V_11 -> V_13 , V_7 -> V_150 + V_148 , V_69 ) ;
if ( V_5 > V_148 + V_149 )
V_161 = V_9 ;
if ( F_8 ( V_11 , V_160 + V_161 , V_9 + V_148 + V_149 - V_161 ) < 0 ) {
F_47 ( L_44 ) ;
return - 1 ;
}
V_2 -> V_8 = F_7 ( F_2 ( V_2 -> V_8 ) - ( V_9 + V_148 + V_149 - V_161 ) ) ;
if ( V_161 > 0 )
V_7 -> V_16 = F_7 ( V_5 - V_148 - V_149 ) ;
F_29 ( L_45 ,
( V_2 -> V_139 == V_158 ? L_42 : L_43 ) , V_11 -> V_156 -> V_157 ) ;
} else {
if ( ! V_23 -> V_153 ) {
F_47 ( L_46 ) ;
return - 1 ;
}
memcpy ( V_11 -> V_13 , V_23 -> V_154 , V_69 ) ;
V_23 -> V_153 = V_155 ;
}
} else {
if ( V_2 -> V_43 != 0 ) {
F_29 ( L_47 , V_11 -> V_156 -> V_157 ) ;
F_18 ( V_31 , V_11 -> V_13 + V_69 , & ( V_2 -> V_43 ) ) ;
F_26 ( V_23 , V_11 , V_31 ) ;
F_34 ( V_23 ) ;
} else {
return - 1 ;
}
}
return 0 ;
default:
return - 1 ;
}
} else if ( V_77 == 0x888e ) {
switch ( V_76 ) {
case V_86 :
return - 1 ;
case V_87 :
return 0 ;
case V_90 :
return 0 ;
default:
return - 1 ;
}
} else if ( ( V_77 == 0xe2ae ) || ( V_77 == 0xe2af ) ) {
switch ( V_76 ) {
case V_86 :
return - 1 ;
case V_87 :
return 0 ;
case V_90 :
return 0 ;
default:
return - 1 ;
}
} else if ( V_77 == V_162 ) {
struct V_163 * V_84 = (struct V_163 * ) ( V_11 -> V_13 + V_14 ) ;
if ( sizeof( * V_84 ) >= ( V_11 -> V_18 - V_14 ) ) {
F_41 ( L_48 ) ;
return - 1 ;
}
switch ( V_76 ) {
case V_86 :
if ( V_11 -> V_13 [ 0 ] & 1 )
return 0 ;
return - 1 ;
case V_87 :
F_29 ( L_49
L_50 ,
V_84 -> V_88 . V_164 [ 0 ] , V_84 -> V_88 . V_164 [ 1 ] , V_84 -> V_88 . V_164 [ 2 ] , V_84 -> V_88 . V_164 [ 3 ] ,
V_84 -> V_88 . V_164 [ 4 ] , V_84 -> V_88 . V_164 [ 5 ] , V_84 -> V_88 . V_164 [ 6 ] , V_84 -> V_88 . V_164 [ 7 ] ,
V_84 -> V_89 . V_164 [ 0 ] , V_84 -> V_89 . V_164 [ 1 ] , V_84 -> V_89 . V_164 [ 2 ] , V_84 -> V_89 . V_164 [ 3 ] ,
V_84 -> V_89 . V_164 [ 4 ] , V_84 -> V_89 . V_164 [ 5 ] , V_84 -> V_89 . V_164 [ 6 ] , V_84 -> V_89 . V_164 [ 7 ] ) ;
if ( memcmp ( & V_84 -> V_88 , L_51 , 16 ) ) {
F_19 ( V_31 , ( unsigned int * ) & V_84 -> V_88 ) ;
F_31 ( V_23 , V_11 -> V_13 + V_69 , V_31 ) ;
F_34 ( V_23 ) ;
if ( V_84 -> V_165 == V_166 &&
V_11 -> V_18 > ( V_14 + sizeof( * V_84 ) + 4 ) ) {
if ( F_21 ( V_11 -> V_13 + V_14 + sizeof( * V_84 ) ,
V_11 -> V_18 - V_14 - sizeof( * V_84 ) , F_46 ( V_23 ) ) ) {
struct V_48 * V_167 = (struct V_48 * ) ( V_11 -> V_13 + V_14 + sizeof( * V_84 ) ) ;
V_167 -> V_168 = 0 ;
V_167 -> V_168 = F_48 ( & V_84 -> V_88 , & V_84 -> V_89 ,
V_84 -> V_169 ,
V_166 ,
F_49 ( ( V_170 * ) V_167 , V_84 -> V_169 , 0 ) ) ;
}
}
}
return 0 ;
case V_90 :
F_29 ( L_52 ,
V_84 -> V_88 . V_164 [ 0 ] , V_84 -> V_88 . V_164 [ 1 ] , V_84 -> V_88 . V_164 [ 2 ] , V_84 -> V_88 . V_164 [ 3 ] ,
V_84 -> V_88 . V_164 [ 4 ] , V_84 -> V_88 . V_164 [ 5 ] , V_84 -> V_88 . V_164 [ 6 ] , V_84 -> V_88 . V_164 [ 7 ] ,
V_84 -> V_89 . V_164 [ 0 ] , V_84 -> V_89 . V_164 [ 1 ] , V_84 -> V_89 . V_164 [ 2 ] , V_84 -> V_89 . V_164 [ 3 ] ,
V_84 -> V_89 . V_164 [ 4 ] , V_84 -> V_89 . V_164 [ 5 ] , V_84 -> V_89 . V_164 [ 6 ] , V_84 -> V_89 . V_164 [ 7 ] ) ;
F_19 ( V_31 , ( unsigned int * ) & V_84 -> V_89 ) ;
F_26 ( V_23 , V_11 , V_31 ) ;
return 0 ;
default:
return - 1 ;
}
}
return - 1 ;
}
int F_50 ( struct V_22 * V_23 , struct V_10 * V_11 )
{
if ( ! ( V_11 -> V_13 [ 0 ] & 1 ) ) {
int V_171 = 0 , V_59 , V_172 = 0 ;
unsigned short V_173 = 0 ;
unsigned short V_77 ;
V_77 = F_40 ( * ( ( V_81 * ) ( V_11 -> V_13 + 2 * V_69 ) ) ) ;
if ( V_77 == V_174 ) {
V_171 = 1 ;
V_173 = * ( ( unsigned short * ) ( V_11 -> V_13 + V_69 * 2 + 2 ) ) ;
for ( V_59 = 0 ; V_59 < 6 ; V_59 ++ )
* ( ( unsigned short * ) ( V_11 -> V_13 + V_69 * 2 + 2 - V_59 * 2 ) ) = * ( ( unsigned short * ) ( V_11 -> V_13 + V_69 * 2 - 2 - V_59 * 2 ) ) ;
F_51 ( V_11 , 4 ) ;
}
if ( ! V_23 -> V_142 . V_175 ) {
unsigned long V_66 ;
F_27 ( & V_23 -> V_67 , & V_66 ) ;
if ( ! V_23 -> V_142 . V_176 &&
( F_40 ( * ( ( V_81 * ) ( V_11 -> V_13 + V_69 * 2 ) ) ) == V_82 ) &&
! memcmp ( V_23 -> V_75 , V_11 -> V_13 + V_14 + 16 , 4 ) ) {
memcpy ( V_11 -> V_13 , V_23 -> V_74 , V_69 ) ;
F_30 ( & V_23 -> V_67 , & V_66 ) ;
} else {
F_30 ( & V_23 -> V_67 , & V_66 ) ;
V_172 = F_39 ( V_23 , V_11 , V_90 ) ;
}
} else {
if ( ( ( F_40 ( * ( ( V_81 * ) ( V_11 -> V_13 + V_69 * 2 ) ) ) == V_82 ) &&
! memcmp ( V_23 -> V_177 , V_11 -> V_13 + V_14 + 16 , 4 ) ) ||
( ( F_40 ( * ( ( V_81 * ) ( V_11 -> V_13 + V_69 * 2 ) ) ) == V_95 ) &&
! memcmp ( V_23 -> V_177 , V_11 -> V_13 + V_14 + 24 , 4 ) ) ) {
V_172 = F_39 ( V_23 , V_11 , V_90 ) ;
}
}
if ( V_171 ) {
F_52 ( V_11 , 4 ) ;
for ( V_59 = 0 ; V_59 < 6 ; V_59 ++ )
* ( ( unsigned short * ) ( V_11 -> V_13 + V_59 * 2 ) ) = * ( ( unsigned short * ) ( V_11 -> V_13 + 4 + V_59 * 2 ) ) ;
* ( ( V_81 * ) ( V_11 -> V_13 + V_69 * 2 ) ) = F_45 ( V_174 ) ;
* ( ( unsigned short * ) ( V_11 -> V_13 + V_69 * 2 + 2 ) ) = V_173 ;
}
if ( V_172 == - 1 ) {
return - 1 ;
}
}
return 0 ;
}
void F_53 ( struct V_22 * V_23 , struct V_10 * V_11 )
{
if ( V_11 == NULL )
return;
if ( ! V_23 -> V_142 . V_178 ) {
V_81 V_77 = * ( ( V_81 * ) ( V_11 -> V_13 + 2 * V_69 ) ) ;
if ( V_77 == F_45 ( V_82 ) ) {
struct V_83 * V_84 = (struct V_83 * ) ( V_11 -> V_13 + V_14 ) ;
if ( V_84 -> V_77 == V_179 ) {
struct V_180 * V_181 = (struct V_180 * ) ( ( V_182 ) V_84 + ( V_84 -> V_85 << 2 ) ) ;
if ( ( V_181 -> V_183 == F_45 ( V_184 ) ) &&
( V_181 -> V_185 == F_45 ( V_186 ) ) ) {
struct V_187 * V_188 =
(struct V_187 * ) ( ( V_182 ) V_181 + sizeof( struct V_180 ) ) ;
V_91 V_189 = F_42 ( ( V_190 ) V_188 -> V_189 ) ;
if ( V_189 == V_191 ) {
if ( ! ( V_188 -> V_192 & F_7 ( V_193 ) ) ) {
register int V_194 = 0 ;
F_29 ( L_53 ) ;
V_188 -> V_192 |= F_7 ( V_193 ) ;
V_194 = ~ ( V_181 -> V_195 ) & 0xffff ;
V_194 += F_40 ( V_188 -> V_192 ) ;
while ( V_194 >> 16 )
V_194 = ( V_194 & 0xffff ) + ( V_194 >> 16 ) ;
V_181 -> V_195 = ~ V_194 ;
}
}
}
}
}
}
}
void * F_54 ( struct V_22 * V_23 , unsigned char * V_68 ,
unsigned char * V_32 )
{
unsigned char V_31 [ V_33 ] ;
struct V_28 * V_65 ;
int V_61 ;
F_14 ( V_31 , ( unsigned int * ) V_32 ) ;
V_61 = F_23 ( V_31 ) ;
V_65 = V_23 -> V_63 [ V_61 ] ;
while ( V_65 != NULL ) {
if ( ! memcmp ( V_65 -> V_31 , V_31 , V_33 ) ) {
return ( void * ) V_65 ;
}
V_65 = V_65 -> V_62 ;
}
return NULL ;
}
