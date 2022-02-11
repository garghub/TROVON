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
V_15 = F_4 ( V_7 -> V_16 ) + V_9 ;
if ( F_5 ( V_11 ) < V_15 ) {
F_6 ( L_1 ) ;
return - 1 ;
}
F_7 ( V_11 , V_15 ) ;
memmove ( ( ( unsigned char * ) V_2 -> V_7 + V_15 ) , ( unsigned char * ) V_2 -> V_7 , F_2 ( V_2 -> V_8 ) ) ;
V_2 -> V_8 = F_8 ( F_2 ( V_2 -> V_8 ) + V_15 ) ;
memcpy ( ( unsigned char * ) V_2 -> V_7 , V_7 , V_15 ) ;
return V_15 ;
}
static int F_9 ( struct V_10 * V_11 , unsigned char * V_17 , int V_18 )
{
int V_19 ;
unsigned long V_20 , V_21 ;
if ( ( V_17 + V_18 ) > F_10 ( V_11 ) || V_11 -> V_18 < V_18 )
return - 1 ;
V_21 = ( unsigned long ) F_10 ( V_11 ) ;
V_20 = ( unsigned long ) V_17 + V_18 ;
if ( V_21 < V_20 )
return - 1 ;
V_19 = ( int ) ( V_21 - V_20 ) ;
if ( V_19 > 0 )
memmove ( V_17 , V_17 + V_18 , V_19 ) ;
F_11 ( V_11 , V_11 -> V_18 - V_18 ) ;
return 0 ;
}
static inline unsigned long F_12 ( struct V_22 * V_23 )
{
unsigned long V_24 ;
V_24 = V_25 - V_26 * V_27 ;
return V_24 ;
}
static inline int F_13 ( struct V_22 * V_23 ,
struct V_28 * V_29 )
{
if ( F_14 ( V_29 -> V_30 , F_12 ( V_23 ) ) )
return 1 ;
return 0 ;
}
static inline void F_15 ( unsigned char * V_31 ,
unsigned int * V_32 )
{
memset ( V_31 , 0 , V_33 ) ;
V_31 [ 0 ] = V_34 ;
memcpy ( V_31 + 7 , ( unsigned char * ) V_32 , 4 ) ;
}
static inline void F_16 ( unsigned char * V_31 ,
T_1 * V_35 , unsigned char * V_36 )
{
memset ( V_31 , 0 , V_33 ) ;
V_31 [ 0 ] = V_37 ;
memcpy ( V_31 + 1 , ( unsigned char * ) V_35 , 4 ) ;
memcpy ( V_31 + 5 , V_36 , 6 ) ;
}
static inline void F_17 ( unsigned char * V_31 ,
T_1 * V_35 , T_2 * V_38 )
{
memset ( V_31 , 0 , V_33 ) ;
V_31 [ 0 ] = V_37 ;
memcpy ( V_31 + 1 , ( unsigned char * ) V_35 , 4 ) ;
memcpy ( V_31 + 5 , ( unsigned char * ) V_38 , 2 ) ;
}
static inline void F_18 ( unsigned char * V_31 ,
T_2 * V_39 , unsigned char * V_40 )
{
memset ( V_31 , 0 , V_33 ) ;
V_31 [ 0 ] = V_41 ;
memcpy ( V_31 + 1 , ( unsigned char * ) V_39 , 2 ) ;
V_31 [ 3 ] = * V_40 ;
}
static inline void F_19 ( unsigned char * V_31 ,
unsigned char * V_42 , T_2 * V_43 )
{
memset ( V_31 , 0 , V_33 ) ;
V_31 [ 0 ] = V_44 ;
memcpy ( V_31 + 1 , ( unsigned char * ) V_43 , 2 ) ;
memcpy ( V_31 + 3 , ( unsigned char * ) V_42 , 6 ) ;
}
static void F_20 ( unsigned char * V_31 ,
T_1 * V_32 )
{
memset ( V_31 , 0 , V_33 ) ;
V_31 [ 0 ] = V_45 ;
memcpy ( V_31 + 1 , ( unsigned char * ) V_32 , 16 ) ;
}
static unsigned char * F_21 ( unsigned char * V_13 , int V_18 , unsigned char V_7 , unsigned char V_46 )
{
while ( V_18 > 0 ) {
if ( * V_13 == V_7 && * ( V_13 + 1 ) == V_46 && V_18 >= V_46 * 8 )
return V_13 + 2 ;
V_18 -= ( * ( V_13 + 1 ) ) * 8 ;
V_13 += ( * ( V_13 + 1 ) ) * 8 ;
}
return NULL ;
}
static int F_22 ( unsigned char * V_13 , int V_18 , unsigned char * V_47 )
{
struct V_48 * V_49 = (struct V_48 * ) V_13 ;
unsigned char * V_50 ;
if ( V_49 -> V_51 == V_52 ) {
if ( V_18 >= 8 ) {
V_50 = F_21 ( & V_13 [ 8 ] , V_18 - 8 , 1 , 1 ) ;
if ( V_50 ) {
F_23 ( L_2 ,
V_50 [ 0 ] , V_50 [ 1 ] , V_50 [ 2 ] , V_50 [ 3 ] , V_50 [ 4 ] , V_50 [ 5 ] ,
V_47 [ 0 ] , V_47 [ 1 ] , V_47 [ 2 ] , V_47 [ 3 ] , V_47 [ 4 ] , V_47 [ 5 ] ) ;
memcpy ( V_50 , V_47 , 6 ) ;
return 1 ;
}
}
} else if ( V_49 -> V_51 == V_53 ) {
if ( V_18 >= 16 ) {
V_50 = F_21 ( & V_13 [ 16 ] , V_18 - 16 , 1 , 1 ) ;
if ( V_50 ) {
F_23 ( L_3 ,
V_50 [ 0 ] , V_50 [ 1 ] , V_50 [ 2 ] , V_50 [ 3 ] , V_50 [ 4 ] , V_50 [ 5 ] ,
V_47 [ 0 ] , V_47 [ 1 ] , V_47 [ 2 ] , V_47 [ 3 ] , V_47 [ 4 ] , V_47 [ 5 ] ) ;
memcpy ( V_50 , V_47 , 6 ) ;
return 1 ;
}
}
} else if ( V_49 -> V_51 == V_54 ) {
if ( V_18 >= 24 ) {
V_50 = F_21 ( & V_13 [ 24 ] , V_18 - 24 , 1 , 1 ) ;
if ( V_50 ) {
F_23 ( L_4 ,
V_50 [ 0 ] , V_50 [ 1 ] , V_50 [ 2 ] , V_50 [ 3 ] , V_50 [ 4 ] , V_50 [ 5 ] ,
V_47 [ 0 ] , V_47 [ 1 ] , V_47 [ 2 ] , V_47 [ 3 ] , V_47 [ 4 ] , V_47 [ 5 ] ) ;
memcpy ( V_50 , V_47 , 6 ) ;
return 1 ;
}
}
} else if ( V_49 -> V_51 == V_55 ) {
if ( V_18 >= 24 ) {
V_50 = F_21 ( & V_13 [ 24 ] , V_18 - 24 , 2 , 1 ) ;
if ( V_50 ) {
F_23 ( L_5 ,
V_50 [ 0 ] , V_50 [ 1 ] , V_50 [ 2 ] , V_50 [ 3 ] , V_50 [ 4 ] , V_50 [ 5 ] ,
V_47 [ 0 ] , V_47 [ 1 ] , V_47 [ 2 ] , V_47 [ 3 ] , V_47 [ 4 ] , V_47 [ 5 ] ) ;
memcpy ( V_50 , V_47 , 6 ) ;
return 1 ;
}
}
} else if ( V_49 -> V_51 == V_56 ) {
if ( V_18 >= 40 ) {
V_50 = F_21 ( & V_13 [ 40 ] , V_18 - 40 , 2 , 1 ) ;
if ( V_50 ) {
F_23 ( L_6 ,
V_50 [ 0 ] , V_50 [ 1 ] , V_50 [ 2 ] , V_50 [ 3 ] , V_50 [ 4 ] , V_50 [ 5 ] ,
V_47 [ 0 ] , V_47 [ 1 ] , V_47 [ 2 ] , V_47 [ 3 ] , V_47 [ 4 ] , V_47 [ 5 ] ) ;
memcpy ( V_50 , V_47 , 6 ) ;
return 1 ;
}
}
}
return 0 ;
}
static inline int F_24 ( unsigned char * V_31 )
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
static inline void F_25 ( struct V_22 * V_23 ,
struct V_28 * V_60 , int V_61 )
{
V_60 -> V_62 = V_23 -> V_63 [ V_61 ] ;
if ( V_60 -> V_62 != NULL )
V_60 -> V_62 -> V_64 = & V_60 -> V_62 ;
V_23 -> V_63 [ V_61 ] = V_60 ;
V_60 -> V_64 = & V_23 -> V_63 [ V_61 ] ;
}
static inline void F_26 ( struct V_28 * V_60 )
{
* ( V_60 -> V_64 ) = V_60 -> V_62 ;
if ( V_60 -> V_62 != NULL )
V_60 -> V_62 -> V_64 = V_60 -> V_64 ;
V_60 -> V_62 = NULL ;
V_60 -> V_64 = NULL ;
}
static int F_27 ( struct V_22 * V_23 ,
struct V_10 * V_11 , unsigned char * V_31 )
{
struct V_28 * V_65 ;
F_28 ( & V_23 -> V_66 ) ;
V_65 = V_23 -> V_63 [ F_24 ( V_31 ) ] ;
while ( V_65 != NULL ) {
if ( ! memcmp ( V_65 -> V_31 , V_31 , V_33 ) ) {
if ( ! F_13 ( V_23 , V_65 ) ) {
memcpy ( V_11 -> V_13 , V_65 -> V_67 , V_68 ) ;
F_29 ( & V_65 -> V_69 ) ;
F_30 ( L_7
L_8 ,
V_65 -> V_67 [ 0 ] ,
V_65 -> V_67 [ 1 ] ,
V_65 -> V_67 [ 2 ] ,
V_65 -> V_67 [ 3 ] ,
V_65 -> V_67 [ 4 ] ,
V_65 -> V_67 [ 5 ] ,
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
F_31 ( & V_23 -> V_66 ) ;
return 1 ;
}
V_65 = V_65 -> V_62 ;
}
F_31 ( & V_23 -> V_66 ) ;
return 0 ;
}
static void F_32 ( struct V_22 * V_23 ,
unsigned char * V_67 , unsigned char * V_31 )
{
struct V_28 * V_65 ;
int V_61 ;
F_28 ( & V_23 -> V_66 ) ;
V_61 = F_24 ( V_31 ) ;
V_65 = V_23 -> V_63 [ V_61 ] ;
while ( V_65 != NULL ) {
if ( ! memcmp ( V_65 -> V_31 , V_31 , V_33 ) ) {
F_33 ( V_65 -> V_67 , V_67 ) ;
V_65 -> V_30 = V_25 ;
F_31 ( & V_23 -> V_66 ) ;
return;
}
V_65 = V_65 -> V_62 ;
}
V_65 = (struct V_28 * ) F_34 ( sizeof( * V_65 ) ) ;
if ( V_65 == NULL ) {
F_31 ( & V_23 -> V_66 ) ;
return;
}
memcpy ( V_65 -> V_31 , V_31 , V_33 ) ;
F_33 ( V_65 -> V_67 , V_67 ) ;
F_35 ( & V_65 -> V_69 , 1 ) ;
V_65 -> V_30 = V_25 ;
F_25 ( V_23 , V_65 , V_61 ) ;
F_31 ( & V_23 -> V_66 ) ;
}
static void F_36 ( struct V_22 * V_23 )
{
}
void F_37 ( struct V_22 * V_23 )
{
int V_59 ;
F_28 ( & V_23 -> V_66 ) ;
for ( V_59 = 0 ; V_59 < V_58 ; V_59 ++ ) {
struct V_28 * V_70 ;
V_70 = V_23 -> V_63 [ V_59 ] ;
while ( V_70 != NULL ) {
struct V_28 * V_71 ;
V_71 = V_70 -> V_62 ;
if ( V_23 -> V_72 == V_70 ) {
memset ( V_23 -> V_73 , 0 , V_68 ) ;
memset ( V_23 -> V_74 , 0 , 4 ) ;
V_23 -> V_72 = NULL ;
}
F_26 ( V_70 ) ;
F_38 ( V_70 ) ;
V_70 = V_71 ;
}
}
F_31 ( & V_23 -> V_66 ) ;
}
void F_39 ( struct V_22 * V_23 )
{
int V_59 ;
F_28 ( & V_23 -> V_66 ) ;
for ( V_59 = 0 ; V_59 < V_58 ; V_59 ++ ) {
struct V_28 * V_70 ;
V_70 = V_23 -> V_63 [ V_59 ] ;
while ( V_70 != NULL ) {
struct V_28 * V_71 ;
V_71 = V_70 -> V_62 ;
if ( F_13 ( V_23 , V_70 ) ) {
if ( F_40 ( & V_70 -> V_69 ) ) {
if ( V_23 -> V_72 == V_70 ) {
memset ( V_23 -> V_73 , 0 , V_68 ) ;
memset ( V_23 -> V_74 , 0 , 4 ) ;
V_23 -> V_72 = NULL ;
}
F_26 ( V_70 ) ;
F_38 ( V_70 ) ;
}
}
V_70 = V_71 ;
}
}
F_31 ( & V_23 -> V_66 ) ;
}
int F_41 ( struct V_22 * V_23 , struct V_10 * V_11 , int V_75 )
{
unsigned short V_76 ;
unsigned char V_31 [ V_33 ] ;
unsigned int V_77 ;
if ( V_11 == NULL )
return - 1 ;
if ( ( V_75 <= V_78 ) || ( V_75 >= V_79 ) )
return - 1 ;
V_76 = F_4 ( * ( ( T_2 * ) ( V_11 -> V_13 + 2 * V_68 ) ) ) ;
if ( V_76 == V_80 ) {
struct V_81 * V_82 = (struct V_81 * ) ( V_11 -> V_13 + V_14 ) ;
if ( ( ( unsigned char * ) ( V_82 ) + ( V_82 -> V_83 << 2 ) ) >= ( V_11 -> V_13 + V_14 + V_11 -> V_18 ) ) {
F_42 ( L_9 ) ;
return - 1 ;
}
switch ( V_75 ) {
case V_84 :
return - 1 ;
case V_85 :
if ( V_82 -> V_86 == 0 )
return 0 ;
V_77 = F_43 ( V_82 -> V_86 ) ;
F_30 ( L_10 , V_77 , V_82 -> V_87 ) ;
F_15 ( V_31 , & V_77 ) ;
F_32 ( V_23 , V_11 -> V_13 + V_68 , V_31 ) ;
F_36 ( V_23 ) ;
return 0 ;
case V_88 :
F_30 ( L_11 , V_82 -> V_86 , V_82 -> V_87 ) ;
V_77 = F_43 ( V_82 -> V_87 ) ;
F_15 ( V_31 , & V_77 ) ;
if ( ! F_27 ( V_23 , V_11 , V_31 ) ) {
if ( * ( ( unsigned char * ) & V_82 -> V_87 + 3 ) == 0xff ) {
F_30 ( L_12 ) ;
memset ( V_11 -> V_13 , 0xff , V_68 ) ;
} else {
F_30 ( L_13 ) ;
if ( ( * ( V_89 * ) V_23 -> V_90 ) == 0 && ( * ( V_91 * ) ( V_23 -> V_90 + 4 ) ) == 0 ) {
F_44 ( V_11 -> V_92 ,
L_14 ) ;
F_45 ( V_23 -> V_93 ) ;
}
memcpy ( V_11 -> V_13 , V_23 -> V_90 , V_68 ) ;
}
}
return 0 ;
default:
return - 1 ;
}
} else if ( V_76 == V_94 ) {
struct V_95 * V_96 = (struct V_95 * ) ( V_11 -> V_13 + V_14 ) ;
unsigned char * V_97 = ( unsigned char * ) ( V_96 + 1 ) ;
unsigned int * V_98 , * V_99 ;
if ( V_96 -> V_100 != F_46 ( V_80 ) ) {
F_42 ( L_15 , F_4 ( V_96 -> V_100 ) ) ;
return - 1 ;
}
switch ( V_75 ) {
case V_84 :
return 0 ;
case V_85 :
F_30 ( L_16 , V_97 [ 0 ] ,
V_97 [ 1 ] , V_97 [ 2 ] , V_97 [ 3 ] , V_97 [ 4 ] , V_97 [ 5 ] ) ;
memcpy ( V_97 , F_47 ( V_23 ) , V_68 ) ;
V_97 += V_96 -> V_101 ;
V_98 = ( unsigned int * ) V_97 ;
F_15 ( V_31 , V_98 ) ;
F_32 ( V_23 , V_11 -> V_13 + V_68 , V_31 ) ;
F_36 ( V_23 ) ;
return 0 ;
case V_88 :
F_30 ( L_17 ) ;
V_97 += V_96 -> V_101 ;
V_98 = ( unsigned int * ) V_97 ;
V_97 += ( V_96 -> V_101 + V_96 -> V_102 ) ;
V_99 = ( unsigned int * ) V_97 ;
F_15 ( V_31 , V_99 ) ;
F_27 ( V_23 , V_11 , V_31 ) ;
V_97 = ( unsigned char * ) ( V_96 + 1 ) ;
V_97 += ( V_96 -> V_101 + V_96 -> V_102 ) ;
memcpy ( V_97 , V_11 -> V_13 , V_68 ) ;
return 0 ;
default:
return - 1 ;
}
} else if ( ( V_76 == V_103 ) ||
( V_76 <= V_104 ) ) {
unsigned char V_105 [ 2 ] = { 0xFF , 0xFF } ;
struct V_106 * V_107 = NULL ;
struct V_108 * V_109 = NULL ;
struct V_110 * V_111 = NULL ;
unsigned char * V_112 = V_11 -> V_13 + V_14 ;
if ( V_76 == V_103 ) {
F_30 ( L_18 ) ;
V_107 = (struct V_106 * ) V_112 ;
} else if ( V_76 <= V_104 ) {
if ( ! memcmp ( V_105 , V_112 , 2 ) ) {
F_30 ( L_19 ) ;
V_107 = (struct V_106 * ) V_112 ;
} else {
unsigned char V_113 = 0xE0 ;
unsigned char V_114 = 0xAA ;
if ( * V_112 == V_114 ) {
unsigned char V_115 [ 5 ] = { 0x0 , 0x0 , 0x0 , 0x81 , 0x37 } ;
unsigned char V_116 [ 5 ] = { 0x00 , 0x00 , 0x00 , 0x80 , 0xF3 } ;
unsigned char V_117 [ 5 ] = { 0x08 , 0x00 , 0x07 , 0x80 , 0x9B } ;
V_112 += 3 ;
if ( ! memcmp ( V_115 , V_112 , 5 ) ) {
V_112 += 5 ;
F_30 ( L_20 ) ;
V_107 = (struct V_106 * ) V_112 ;
} else if ( ! memcmp ( V_116 , V_112 , 5 ) ) {
V_112 += 5 ;
V_109 = (struct V_108 * ) V_112 ;
} else if ( ! memcmp ( V_117 , V_112 , 5 ) ) {
V_112 += 5 ;
V_111 = (struct V_110 * ) V_112 ;
} else {
F_42 ( L_21 , V_112 [ 0 ] ,
V_112 [ 1 ] , V_112 [ 2 ] , V_112 [ 3 ] , V_112 [ 4 ] ) ;
return - 1 ;
}
} else if ( * V_112 == V_113 ) {
V_112 += 3 ;
if ( ! memcmp ( V_105 , V_112 , 2 ) ) {
F_30 ( L_22 ) ;
V_107 = (struct V_106 * ) V_112 ;
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
if ( V_107 != NULL ) {
switch ( V_75 ) {
case V_84 :
if ( ! memcmp ( V_11 -> V_13 + V_68 , V_107 -> V_118 . V_40 , V_68 ) )
F_30 ( L_23 ) ;
return 0 ;
case V_85 :
F_30 ( L_24 ,
V_107 -> V_119 . V_120 ,
V_107 -> V_119 . V_40 [ 0 ] ,
V_107 -> V_119 . V_40 [ 1 ] ,
V_107 -> V_119 . V_40 [ 2 ] ,
V_107 -> V_119 . V_40 [ 3 ] ,
V_107 -> V_119 . V_40 [ 4 ] ,
V_107 -> V_119 . V_40 [ 5 ] ,
V_107 -> V_119 . V_121 ,
V_107 -> V_118 . V_120 ,
V_107 -> V_118 . V_40 [ 0 ] ,
V_107 -> V_118 . V_40 [ 1 ] ,
V_107 -> V_118 . V_40 [ 2 ] ,
V_107 -> V_118 . V_40 [ 3 ] ,
V_107 -> V_118 . V_40 [ 4 ] ,
V_107 -> V_118 . V_40 [ 5 ] ,
V_107 -> V_118 . V_121 ) ;
if ( ! memcmp ( V_11 -> V_13 + V_68 , V_107 -> V_118 . V_40 , V_68 ) ) {
F_30 ( L_25 ) ;
F_17 ( V_31 , & V_107 -> V_118 . V_120 , & V_107 -> V_118 . V_121 ) ;
memcpy ( V_107 -> V_118 . V_40 , F_47 ( V_23 ) , V_68 ) ;
} else {
F_16 ( V_31 , & V_107 -> V_118 . V_120 , V_107 -> V_118 . V_40 ) ;
}
F_32 ( V_23 , V_11 -> V_13 + V_68 , V_31 ) ;
F_36 ( V_23 ) ;
return 0 ;
case V_88 :
if ( ! memcmp ( F_47 ( V_23 ) , V_107 -> V_119 . V_40 , V_68 ) ) {
F_30 ( L_26 ) ;
F_17 ( V_31 , & V_107 -> V_119 . V_120 , & V_107 -> V_119 . V_121 ) ;
F_27 ( V_23 , V_11 , V_31 ) ;
memcpy ( V_107 -> V_119 . V_40 , V_11 -> V_13 , V_68 ) ;
} else {
F_16 ( V_31 , & V_107 -> V_119 . V_120 , V_107 -> V_119 . V_40 ) ;
F_27 ( V_23 , V_11 , V_31 ) ;
}
return 0 ;
default:
return - 1 ;
}
} else if ( V_109 != NULL ) {
if ( V_109 -> V_122 != V_68 || V_109 -> V_123 != V_124 ) {
F_42 ( L_27 ) ;
return - 1 ;
}
switch ( V_75 ) {
case V_84 :
return 0 ;
case V_85 :
memcpy ( V_109 -> V_125 , F_47 ( V_23 ) , V_68 ) ;
F_30 ( L_28 ,
V_109 -> V_126 ,
V_109 -> V_127 ,
V_109 -> V_128 ,
V_109 -> V_129 ) ;
F_18 ( V_31 , & V_109 -> V_126 , & V_109 -> V_127 ) ;
F_32 ( V_23 , V_11 -> V_13 + V_68 , V_31 ) ;
F_36 ( V_23 ) ;
return 0 ;
case V_88 :
F_30 ( L_29 ,
V_109 -> V_126 ,
V_109 -> V_127 ,
V_109 -> V_128 ,
V_109 -> V_129 ) ;
F_18 ( V_31 , & V_109 -> V_128 , & V_109 -> V_129 ) ;
F_27 ( V_23 , V_11 , V_31 ) ;
memcpy ( V_109 -> V_130 , V_11 -> V_13 , V_68 ) ;
return 0 ;
default:
return - 1 ;
}
} else if ( V_111 != NULL ) {
switch ( V_75 ) {
case V_84 :
return - 1 ;
case V_85 :
F_30 ( L_30 ,
V_111 -> V_131 ,
V_111 -> V_132 ,
V_111 -> V_133 ,
V_111 -> V_134 ) ;
F_18 ( V_31 , & V_111 -> V_131 , & V_111 -> V_132 ) ;
F_32 ( V_23 , V_11 -> V_13 + V_68 , V_31 ) ;
F_36 ( V_23 ) ;
return 0 ;
case V_88 :
F_30 ( L_31 ,
V_111 -> V_131 ,
V_111 -> V_132 ,
V_111 -> V_133 ,
V_111 -> V_134 ) ;
F_18 ( V_31 , & V_111 -> V_133 , & V_111 -> V_134 ) ;
F_27 ( V_23 , V_11 , V_31 ) ;
return 0 ;
default:
return - 1 ;
}
}
return - 1 ;
} else if ( ( V_76 == V_135 ) ||
( V_76 == V_136 ) ) {
struct V_1 * V_2 = (struct V_1 * ) ( V_11 -> V_13 + V_14 ) ;
T_2 * V_137 ;
switch ( V_75 ) {
case V_84 :
if ( V_2 -> V_43 == 0 )
return 0 ;
return 1 ;
case V_85 :
if ( V_2 -> V_43 == 0 ) {
if ( V_2 -> V_138 == V_139 || V_2 -> V_138 == V_140 ) {
if ( V_23 -> V_141 . V_142 ) {
struct V_12 * V_7 , * V_143 ;
unsigned char V_144 [ 40 ] ;
int V_145 = 0 ;
V_7 = (struct V_12 * ) V_144 ;
V_143 = (struct V_12 * ) F_1 ( V_2 , F_2 ( V_146 ) ) ;
if ( V_143 ) {
V_145 = F_2 ( V_143 -> V_16 ) ;
if ( V_145 + V_9 + V_147 + V_148 > sizeof( V_144 ) ) {
F_48 ( L_32 ) ;
return - 1 ;
}
memcpy ( V_7 -> V_149 + V_147 + V_148 ,
V_143 -> V_149 , V_145 ) ;
if ( F_9 ( V_11 , ( unsigned char * ) V_143 , V_9 + V_145 ) < 0 ) {
F_48 ( L_33 ) ;
return - 1 ;
}
V_2 -> V_8 = F_8 ( F_2 ( V_2 -> V_8 ) - V_9 - V_145 ) ;
}
V_7 -> V_150 = V_146 ;
V_7 -> V_16 = F_8 ( V_147 + V_148 + V_145 ) ;
V_137 = ( T_2 * ) V_7 -> V_149 ;
* V_137 = F_8 ( V_151 ) ;
memcpy ( V_7 -> V_149 + V_147 , V_11 -> V_13 + V_68 , V_68 ) ;
if ( F_3 ( V_11 , V_7 ) < 0 )
return - 1 ;
F_30 ( L_34 ,
( V_2 -> V_138 == V_139 ? L_35 : L_36 ) ) ;
} else {
if ( V_23 -> V_152 &&
memcmp ( V_11 -> V_13 + V_68 , V_23 -> V_153 , V_68 ) ) {
F_48 ( L_37 ) ;
return - 2 ;
}
if ( V_23 -> V_152 == 0 )
memcpy ( V_23 -> V_153 , V_11 -> V_13 + V_68 , V_68 ) ;
V_23 -> V_152 = V_154 ;
}
} else {
return - 1 ;
}
} else {
F_30 ( L_38 , V_11 -> V_92 -> V_155 ) ;
F_19 ( V_31 , V_11 -> V_13 , & ( V_2 -> V_43 ) ) ;
F_32 ( V_23 , V_11 -> V_13 + V_68 , V_31 ) ;
F_36 ( V_23 ) ;
if ( ! V_23 -> V_141 . V_142 &&
V_23 -> V_152 &&
! memcmp ( V_11 -> V_13 + V_68 , V_23 -> V_153 , V_68 ) )
V_23 -> V_152 = 0 ;
}
return 0 ;
case V_88 :
if ( V_2 -> V_138 == V_156 || V_2 -> V_138 == V_157 ) {
if ( V_23 -> V_141 . V_142 ) {
struct V_12 * V_7 ;
unsigned char * V_158 ;
unsigned short V_6 , V_5 ;
int V_159 = 0 ;
V_158 = F_1 ( V_2 , F_2 ( V_146 ) ) ;
if ( V_158 == NULL ) {
F_48 ( L_39 ) ;
return - 1 ;
}
V_7 = (struct V_12 * ) V_158 ;
V_6 = ( unsigned short ) ( ( V_158 [ 0 ] << 8 ) + V_158 [ 1 ] ) ;
V_5 = ( unsigned short ) ( ( V_158 [ 2 ] << 8 ) + V_158 [ 3 ] ) ;
if ( ( V_6 != F_2 ( V_146 ) ) || ( V_5 < ( V_147 + V_148 ) ) ) {
F_48 ( L_40 , V_5 ) ;
return - 1 ;
}
V_137 = ( T_2 * ) V_7 -> V_149 ;
if ( F_2 ( * V_137 ) != V_151 ) {
F_48 ( L_41 ,
( V_2 -> V_138 == V_156 ? L_42 : L_43 ) ) ;
return - 1 ;
}
memcpy ( V_11 -> V_13 , V_7 -> V_149 + V_147 , V_68 ) ;
if ( V_5 > V_147 + V_148 )
V_159 = V_9 ;
if ( F_9 ( V_11 , V_158 + V_159 , V_9 + V_147 + V_148 - V_159 ) < 0 ) {
F_48 ( L_44 ) ;
return - 1 ;
}
V_2 -> V_8 = F_8 ( F_2 ( V_2 -> V_8 ) - ( V_9 + V_147 + V_148 - V_159 ) ) ;
if ( V_159 > 0 )
V_7 -> V_16 = F_8 ( V_5 - V_147 - V_148 ) ;
F_30 ( L_45 ,
( V_2 -> V_138 == V_156 ? L_42 : L_43 ) , V_11 -> V_92 -> V_155 ) ;
} else {
if ( ! V_23 -> V_152 ) {
F_48 ( L_46 ) ;
return - 1 ;
}
memcpy ( V_11 -> V_13 , V_23 -> V_153 , V_68 ) ;
V_23 -> V_152 = V_154 ;
}
} else {
if ( V_2 -> V_43 != 0 ) {
F_30 ( L_47 , V_11 -> V_92 -> V_155 ) ;
F_19 ( V_31 , V_11 -> V_13 + V_68 , & ( V_2 -> V_43 ) ) ;
F_27 ( V_23 , V_11 , V_31 ) ;
F_36 ( V_23 ) ;
} else {
return - 1 ;
}
}
return 0 ;
default:
return - 1 ;
}
} else if ( V_76 == 0x888e ) {
switch ( V_75 ) {
case V_84 :
return - 1 ;
case V_85 :
return 0 ;
case V_88 :
return 0 ;
default:
return - 1 ;
}
} else if ( ( V_76 == 0xe2ae ) || ( V_76 == 0xe2af ) ) {
switch ( V_75 ) {
case V_84 :
return - 1 ;
case V_85 :
return 0 ;
case V_88 :
return 0 ;
default:
return - 1 ;
}
} else if ( V_76 == V_160 ) {
struct V_161 * V_82 = (struct V_161 * ) ( V_11 -> V_13 + V_14 ) ;
if ( sizeof( * V_82 ) >= ( V_11 -> V_18 - V_14 ) ) {
F_42 ( L_48 ) ;
return - 1 ;
}
switch ( V_75 ) {
case V_84 :
if ( V_11 -> V_13 [ 0 ] & 1 )
return 0 ;
return - 1 ;
case V_85 :
F_30 ( L_49
L_50 ,
V_82 -> V_86 . V_162 [ 0 ] , V_82 -> V_86 . V_162 [ 1 ] , V_82 -> V_86 . V_162 [ 2 ] , V_82 -> V_86 . V_162 [ 3 ] ,
V_82 -> V_86 . V_162 [ 4 ] , V_82 -> V_86 . V_162 [ 5 ] , V_82 -> V_86 . V_162 [ 6 ] , V_82 -> V_86 . V_162 [ 7 ] ,
V_82 -> V_87 . V_162 [ 0 ] , V_82 -> V_87 . V_162 [ 1 ] , V_82 -> V_87 . V_162 [ 2 ] , V_82 -> V_87 . V_162 [ 3 ] ,
V_82 -> V_87 . V_162 [ 4 ] , V_82 -> V_87 . V_162 [ 5 ] , V_82 -> V_87 . V_162 [ 6 ] , V_82 -> V_87 . V_162 [ 7 ] ) ;
if ( memcmp ( & V_82 -> V_86 , L_51 , 16 ) ) {
F_20 ( V_31 , ( T_1 * ) & V_82 -> V_86 ) ;
F_32 ( V_23 , V_11 -> V_13 + V_68 , V_31 ) ;
F_36 ( V_23 ) ;
if ( V_82 -> V_163 == V_164 &&
V_11 -> V_18 > ( V_14 + sizeof( * V_82 ) + 4 ) ) {
if ( F_22 ( V_11 -> V_13 + V_14 + sizeof( * V_82 ) ,
V_11 -> V_18 - V_14 - sizeof( * V_82 ) , F_47 ( V_23 ) ) ) {
struct V_48 * V_165 = (struct V_48 * ) ( V_11 -> V_13 + V_14 + sizeof( * V_82 ) ) ;
V_165 -> V_166 = 0 ;
V_165 -> V_166 = F_49 ( & V_82 -> V_86 , & V_82 -> V_87 ,
F_4 ( V_82 -> V_167 ) ,
V_164 ,
F_50 ( ( V_168 * ) V_165 ,
F_4 ( V_82 -> V_167 ) , 0 ) ) ;
}
}
}
return 0 ;
case V_88 :
F_30 ( L_52 ,
V_82 -> V_86 . V_162 [ 0 ] , V_82 -> V_86 . V_162 [ 1 ] , V_82 -> V_86 . V_162 [ 2 ] , V_82 -> V_86 . V_162 [ 3 ] ,
V_82 -> V_86 . V_162 [ 4 ] , V_82 -> V_86 . V_162 [ 5 ] , V_82 -> V_86 . V_162 [ 6 ] , V_82 -> V_86 . V_162 [ 7 ] ,
V_82 -> V_87 . V_162 [ 0 ] , V_82 -> V_87 . V_162 [ 1 ] , V_82 -> V_87 . V_162 [ 2 ] , V_82 -> V_87 . V_162 [ 3 ] ,
V_82 -> V_87 . V_162 [ 4 ] , V_82 -> V_87 . V_162 [ 5 ] , V_82 -> V_87 . V_162 [ 6 ] , V_82 -> V_87 . V_162 [ 7 ] ) ;
F_20 ( V_31 , ( T_1 * ) & V_82 -> V_87 ) ;
F_27 ( V_23 , V_11 , V_31 ) ;
return 0 ;
default:
return - 1 ;
}
}
return - 1 ;
}
int F_51 ( struct V_22 * V_23 , struct V_10 * V_11 )
{
if ( ! ( V_11 -> V_13 [ 0 ] & 1 ) ) {
int V_169 = 0 , V_59 , V_170 = 0 ;
unsigned short V_171 = 0 ;
unsigned short V_76 ;
V_76 = F_4 ( * ( ( T_2 * ) ( V_11 -> V_13 + 2 * V_68 ) ) ) ;
if ( V_76 == V_172 ) {
V_169 = 1 ;
V_171 = * ( ( unsigned short * ) ( V_11 -> V_13 + V_68 * 2 + 2 ) ) ;
for ( V_59 = 0 ; V_59 < 6 ; V_59 ++ )
* ( ( unsigned short * ) ( V_11 -> V_13 + V_68 * 2 + 2 - V_59 * 2 ) ) = * ( ( unsigned short * ) ( V_11 -> V_13 + V_68 * 2 - 2 - V_59 * 2 ) ) ;
F_52 ( V_11 , 4 ) ;
}
if ( ! V_23 -> V_141 . V_173 ) {
F_28 ( & V_23 -> V_66 ) ;
if ( ! V_23 -> V_141 . V_174 &&
( F_4 ( * ( ( T_2 * ) ( V_11 -> V_13 + V_68 * 2 ) ) ) == V_80 ) &&
! memcmp ( V_23 -> V_74 , V_11 -> V_13 + V_14 + 16 , 4 ) ) {
memcpy ( V_11 -> V_13 , V_23 -> V_73 , V_68 ) ;
F_31 ( & V_23 -> V_66 ) ;
} else {
F_31 ( & V_23 -> V_66 ) ;
V_170 = F_41 ( V_23 , V_11 , V_88 ) ;
}
} else {
if ( ( ( F_4 ( * ( ( T_2 * ) ( V_11 -> V_13 + V_68 * 2 ) ) ) == V_80 ) &&
! memcmp ( V_23 -> V_175 , V_11 -> V_13 + V_14 + 16 , 4 ) ) ||
( ( F_4 ( * ( ( T_2 * ) ( V_11 -> V_13 + V_68 * 2 ) ) ) == V_94 ) &&
! memcmp ( V_23 -> V_175 , V_11 -> V_13 + V_14 + 24 , 4 ) ) ) {
V_170 = F_41 ( V_23 , V_11 , V_88 ) ;
}
}
if ( V_169 ) {
F_53 ( V_11 , 4 ) ;
for ( V_59 = 0 ; V_59 < 6 ; V_59 ++ )
* ( ( unsigned short * ) ( V_11 -> V_13 + V_59 * 2 ) ) = * ( ( unsigned short * ) ( V_11 -> V_13 + 4 + V_59 * 2 ) ) ;
* ( ( T_2 * ) ( V_11 -> V_13 + V_68 * 2 ) ) = F_46 ( V_172 ) ;
* ( ( unsigned short * ) ( V_11 -> V_13 + V_68 * 2 + 2 ) ) = V_171 ;
}
if ( V_170 == - 1 ) {
return - 1 ;
}
}
return 0 ;
}
void F_54 ( struct V_22 * V_23 , struct V_10 * V_11 )
{
if ( V_11 == NULL )
return;
if ( ! V_23 -> V_141 . V_176 ) {
T_2 V_76 = * ( ( T_2 * ) ( V_11 -> V_13 + 2 * V_68 ) ) ;
if ( V_76 == F_46 ( V_80 ) ) {
struct V_81 * V_82 = (struct V_81 * ) ( V_11 -> V_13 + V_14 ) ;
if ( V_82 -> V_76 == V_177 ) {
struct V_178 * V_179 = (struct V_178 * ) ( ( V_180 ) V_82 + ( V_82 -> V_83 << 2 ) ) ;
if ( ( V_179 -> V_181 == F_46 ( V_182 ) ) &&
( V_179 -> V_183 == F_46 ( V_184 ) ) ) {
struct V_185 * V_186 =
(struct V_185 * ) ( ( V_180 ) V_179 + sizeof( struct V_178 ) ) ;
V_89 V_187 = F_43 ( ( T_1 ) V_186 -> V_187 ) ;
if ( V_187 == V_188 ) {
if ( ! ( V_186 -> V_189 & F_8 ( V_190 ) ) ) {
register int V_191 = 0 ;
F_30 ( L_53 ) ;
V_186 -> V_189 |= F_8 ( V_190 ) ;
V_191 = ~ ( V_179 -> V_192 ) & 0xffff ;
V_191 += F_4 ( V_186 -> V_189 ) ;
while ( V_191 >> 16 )
V_191 = ( V_191 & 0xffff ) + ( V_191 >> 16 ) ;
V_179 -> V_192 = ~ V_191 ;
}
}
}
}
}
}
}
void * F_55 ( struct V_22 * V_23 , unsigned char * V_67 ,
unsigned char * V_32 )
{
unsigned char V_31 [ V_33 ] ;
struct V_28 * V_65 ;
int V_61 ;
F_15 ( V_31 , ( unsigned int * ) V_32 ) ;
V_61 = F_24 ( V_31 ) ;
V_65 = V_23 -> V_63 [ V_61 ] ;
while ( V_65 != NULL ) {
if ( ! memcmp ( V_65 -> V_31 , V_31 , V_33 ) )
return ( void * ) V_65 ;
V_65 = V_65 -> V_62 ;
}
return NULL ;
}
