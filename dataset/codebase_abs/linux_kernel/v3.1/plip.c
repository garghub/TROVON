static inline void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 != - 1 )
{
struct V_4 * V_5 =
( (struct V_6 * ) F_2 ( V_2 ) ) -> V_7 -> V_5 ;
V_5 -> V_8 -> V_9 ( V_5 ) ;
}
}
static inline void F_3 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 != - 1 )
{
struct V_4 * V_5 =
( (struct V_6 * ) F_2 ( V_2 ) ) -> V_7 -> V_5 ;
V_5 -> V_8 -> V_10 ( V_5 ) ;
}
}
static inline void F_4 ( struct V_1 * V_2 , unsigned char V_11 )
{
struct V_4 * V_5 =
( (struct V_6 * ) F_2 ( V_2 ) ) -> V_7 -> V_5 ;
V_5 -> V_8 -> F_4 ( V_5 , V_11 ) ;
}
static inline unsigned char F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 =
( (struct V_6 * ) F_2 ( V_2 ) ) -> V_7 -> V_5 ;
return V_5 -> V_8 -> F_5 ( V_5 ) ;
}
static void
F_6 ( struct V_1 * V_2 )
{
struct V_6 * V_12 = F_2 ( V_2 ) ;
V_2 -> V_13 = 10 ;
V_2 -> V_14 = V_15 | V_16 ;
memset ( V_2 -> V_17 , 0xfc , V_18 ) ;
V_2 -> V_19 = & V_20 ;
V_2 -> V_21 = & V_22 ;
V_12 -> V_23 = 0 ;
V_12 -> V_24 = V_25 ;
V_12 -> V_26 = V_27 ;
F_7 ( & V_12 -> V_28 , V_29 ) ;
F_8 ( & V_12 -> V_30 , V_31 ) ;
if ( V_2 -> V_3 == - 1 )
F_8 ( & V_12 -> V_32 , V_33 ) ;
F_9 ( & V_12 -> V_34 ) ;
}
static void
V_31 ( struct V_35 * V_36 )
{
struct V_6 * V_12 =
F_10 ( V_36 , struct V_6 , V_30 . V_36 ) ;
if ( V_12 -> V_37 )
F_11 ( & V_12 -> V_28 ) ;
}
static void
V_29 ( struct V_35 * V_36 )
{
struct V_6 * V_12 = F_10 ( V_36 , struct V_6 , V_28 ) ;
struct V_38 * V_39 = & V_12 -> V_40 ;
struct V_38 * V_41 = & V_12 -> V_42 ;
T_1 V_43 ;
int V_44 ;
V_12 -> V_37 = 0 ;
V_43 = V_45 [ V_12 -> V_46 ] ;
if ( ( V_44 = (* V_43)( V_12 -> V_2 , V_12 , V_39 , V_41 ) ) != V_47 &&
( V_44 = F_12 ( V_12 -> V_2 , V_12 , V_39 , V_41 , V_44 ) ) != V_47 ) {
V_12 -> V_37 = 1 ;
F_13 ( & V_12 -> V_30 , 1 ) ;
}
}
static void
V_33 ( struct V_35 * V_36 )
{
struct V_6 * V_12 =
F_10 ( V_36 , struct V_6 , V_32 . V_36 ) ;
if ( ! ( F_14 ( & V_12 -> V_48 ) ) ) {
F_15 ( V_12 -> V_2 ) ;
F_13 ( & V_12 -> V_32 , 1 ) ;
}
else {
F_16 ( & V_12 -> V_49 ) ;
}
}
static int
F_12 ( struct V_1 * V_2 , struct V_6 * V_12 ,
struct V_38 * V_39 , struct V_38 * V_41 ,
int error )
{
unsigned char V_50 ;
F_17 ( & V_12 -> V_34 ) ;
if ( V_12 -> V_46 == V_51 ) {
if ( error != ERROR ) {
V_12 -> V_52 ++ ;
if ( ( error == V_53 && V_12 -> V_52 <= 10 ) ||
V_12 -> V_52 <= 3 ) {
F_18 ( & V_12 -> V_34 ) ;
return V_54 ;
}
V_50 = F_5 ( V_2 ) ;
F_19 ( V_55 L_1 ,
V_2 -> V_56 , V_39 -> V_57 , V_50 ) ;
} else
error = V_53 ;
V_2 -> V_58 . V_59 ++ ;
V_2 -> V_58 . V_60 ++ ;
} else if ( V_12 -> V_46 == V_61 ) {
if ( V_41 -> V_57 == V_62 ) {
F_18 ( & V_12 -> V_34 ) ;
return V_47 ;
}
if ( error != ERROR ) {
if ( ++ V_12 -> V_52 <= 3 ) {
F_18 ( & V_12 -> V_34 ) ;
return V_54 ;
}
V_50 = F_5 ( V_2 ) ;
F_19 ( V_55 L_2 ,
V_2 -> V_56 , V_41 -> V_57 , V_50 ) ;
}
V_2 -> V_58 . V_63 ++ ;
}
V_41 -> V_57 = V_64 ;
if ( V_41 -> V_65 ) {
F_20 ( V_41 -> V_65 ) ;
V_41 -> V_65 = NULL ;
}
V_39 -> V_57 = V_64 ;
if ( V_39 -> V_65 ) {
F_21 ( V_39 -> V_65 ) ;
V_39 -> V_65 = NULL ;
}
F_18 ( & V_12 -> V_34 ) ;
if ( error == V_53 ) {
F_22 ( V_2 -> V_3 ) ;
F_23 ( V_2 -> V_3 ) ;
}
F_3 ( V_2 ) ;
F_24 ( V_2 ) ;
V_12 -> V_46 = V_66 ;
F_4 ( V_2 , 0x00 ) ;
return V_54 ;
}
static int
F_25 ( struct V_1 * V_2 , struct V_6 * V_12 ,
struct V_38 * V_39 , struct V_38 * V_41 )
{
return V_47 ;
}
static inline int
F_26 ( unsigned short V_67 , struct V_1 * V_2 ,
enum V_68 * V_69 , unsigned char * V_70 )
{
unsigned char V_50 , V_71 ;
unsigned int V_72 ;
switch ( * V_69 ) {
case V_73 :
V_72 = V_67 ;
while ( 1 ) {
V_50 = F_5 ( V_2 ) ;
F_27 ( V_74 ) ;
if ( ( V_50 & 0x80 ) == 0 ) {
V_71 = F_5 ( V_2 ) ;
if ( V_50 == V_71 )
break;
}
if ( -- V_72 == 0 )
return V_54 ;
}
* V_70 = ( V_50 >> 3 ) & 0x0f ;
F_4 ( V_2 , 0x10 ) ;
* V_69 = V_75 ;
case V_75 :
V_72 = V_67 ;
while ( 1 ) {
V_50 = F_5 ( V_2 ) ;
F_27 ( V_74 ) ;
if ( V_50 & 0x80 ) {
V_71 = F_5 ( V_2 ) ;
if ( V_50 == V_71 )
break;
}
if ( -- V_72 == 0 )
return V_54 ;
}
* V_70 |= ( V_50 << 1 ) & 0xf0 ;
F_4 ( V_2 , 0x00 ) ;
* V_69 = V_73 ;
case V_76 :
break;
}
return V_47 ;
}
static T_2 F_28 ( struct V_77 * V_65 , struct V_1 * V_2 )
{
struct V_78 * V_79 ;
unsigned char * V_80 ;
F_29 ( V_65 ) ;
F_30 ( V_65 , V_2 -> V_81 ) ;
V_79 = F_31 ( V_65 ) ;
if( * V_79 -> V_82 & 1 )
{
if( memcmp ( V_79 -> V_82 , V_2 -> V_83 , V_18 ) == 0 )
V_65 -> V_84 = V_85 ;
else
V_65 -> V_84 = V_86 ;
}
if ( F_32 ( V_79 -> V_87 ) >= 1536 )
return V_79 -> V_87 ;
V_80 = V_65 -> V_11 ;
if ( * ( unsigned short * ) V_80 == 0xFFFF )
return F_33 ( V_88 ) ;
return F_33 ( V_89 ) ;
}
static int
F_34 ( struct V_1 * V_2 , struct V_6 * V_12 ,
struct V_38 * V_39 , struct V_38 * V_41 )
{
unsigned short V_67 = V_12 -> V_26 ;
unsigned char * V_90 ;
switch ( V_41 -> V_57 ) {
case V_62 :
F_22 ( V_2 -> V_3 ) ;
F_3 ( V_2 ) ;
F_4 ( V_2 , 0x01 ) ;
if ( V_91 > 2 )
F_19 ( V_92 L_3 , V_2 -> V_56 ) ;
V_41 -> V_57 = V_93 ;
V_41 -> V_26 = V_73 ;
case V_93 :
if ( V_39 -> V_57 != V_64 ) {
if ( F_26 ( V_12 -> V_24 , V_2 ,
& V_41 -> V_26 , & V_41 -> V_94 . V_95 . V_96 ) ) {
V_41 -> V_57 = V_64 ;
V_12 -> V_37 = 1 ;
V_12 -> V_46 = V_51 ;
F_13 ( & V_12 -> V_30 , 1 ) ;
F_1 ( V_2 ) ;
F_35 ( V_2 -> V_3 ) ;
return V_47 ;
}
} else {
if ( F_26 ( V_67 , V_2 ,
& V_41 -> V_26 , & V_41 -> V_94 . V_95 . V_96 ) )
return V_54 ;
}
V_41 -> V_57 = V_97 ;
case V_97 :
if ( F_26 ( V_67 , V_2 ,
& V_41 -> V_26 , & V_41 -> V_94 . V_95 . V_98 ) )
return V_54 ;
if ( V_41 -> V_94 . V_99 > V_2 -> V_100 + V_2 -> V_81 ||
V_41 -> V_94 . V_99 < 8 ) {
F_19 ( V_55 L_4 , V_2 -> V_56 , V_41 -> V_94 . V_99 ) ;
return ERROR ;
}
V_41 -> V_65 = F_36 ( V_41 -> V_94 . V_99 + 2 ) ;
if ( V_41 -> V_65 == NULL ) {
F_19 ( V_101 L_5 , V_2 -> V_56 ) ;
return ERROR ;
}
F_37 ( V_41 -> V_65 , 2 ) ;
F_38 ( V_41 -> V_65 , V_41 -> V_94 . V_99 ) ;
V_41 -> V_65 -> V_2 = V_2 ;
V_41 -> V_57 = V_102 ;
V_41 -> V_103 = 0 ;
V_41 -> V_104 = 0 ;
case V_102 :
V_90 = V_41 -> V_65 -> V_11 ;
do {
if ( F_26 ( V_67 , V_2 ,
& V_41 -> V_26 , & V_90 [ V_41 -> V_103 ] ) )
return V_54 ;
} while ( ++ V_41 -> V_103 < V_41 -> V_94 . V_99 );
do {
V_41 -> V_104 += V_90 [ -- V_41 -> V_103 ] ;
} while ( V_41 -> V_103 );
V_41 -> V_57 = V_105 ;
case V_105 :
if ( F_26 ( V_67 , V_2 ,
& V_41 -> V_26 , & V_41 -> V_11 ) )
return V_54 ;
if ( V_41 -> V_11 != V_41 -> V_104 ) {
V_2 -> V_58 . V_106 ++ ;
if ( V_91 )
F_19 ( V_92 L_6 , V_2 -> V_56 ) ;
return ERROR ;
}
V_41 -> V_57 = V_64 ;
case V_64 :
V_41 -> V_65 -> V_107 = F_28 ( V_41 -> V_65 , V_2 ) ;
F_39 ( V_41 -> V_65 ) ;
V_2 -> V_58 . V_108 += V_41 -> V_94 . V_99 ;
V_2 -> V_58 . V_109 ++ ;
V_41 -> V_65 = NULL ;
if ( V_91 > 2 )
F_19 ( V_92 L_7 , V_2 -> V_56 ) ;
F_4 ( V_2 , 0x00 ) ;
F_17 ( & V_12 -> V_34 ) ;
if ( V_39 -> V_57 != V_64 ) {
V_12 -> V_46 = V_51 ;
F_18 ( & V_12 -> V_34 ) ;
F_11 ( & V_12 -> V_28 ) ;
F_1 ( V_2 ) ;
F_35 ( V_2 -> V_3 ) ;
return V_47 ;
} else {
V_12 -> V_46 = V_110 ;
F_18 ( & V_12 -> V_34 ) ;
F_1 ( V_2 ) ;
F_35 ( V_2 -> V_3 ) ;
return V_47 ;
}
}
return V_47 ;
}
static inline int
F_40 ( unsigned short V_67 , struct V_1 * V_2 ,
enum V_68 * V_69 , unsigned char V_11 )
{
unsigned char V_50 ;
unsigned int V_72 ;
switch ( * V_69 ) {
case V_73 :
F_4 ( V_2 , V_11 & 0x0f ) ;
* V_69 = V_75 ;
case V_75 :
F_4 ( V_2 , 0x10 | ( V_11 & 0x0f ) ) ;
V_72 = V_67 ;
while ( 1 ) {
V_50 = F_5 ( V_2 ) ;
if ( ( V_50 & 0x80 ) == 0 )
break;
if ( -- V_72 == 0 )
return V_54 ;
F_27 ( V_74 ) ;
}
F_4 ( V_2 , 0x10 | ( V_11 >> 4 ) ) ;
* V_69 = V_76 ;
case V_76 :
F_4 ( V_2 , ( V_11 >> 4 ) ) ;
V_72 = V_67 ;
while ( 1 ) {
V_50 = F_5 ( V_2 ) ;
if ( V_50 & 0x80 )
break;
if ( -- V_72 == 0 )
return V_54 ;
F_27 ( V_74 ) ;
}
* V_69 = V_73 ;
return V_47 ;
}
return V_47 ;
}
static int
F_41 ( struct V_1 * V_2 , struct V_6 * V_12 ,
struct V_38 * V_39 , struct V_38 * V_41 )
{
unsigned short V_67 = V_12 -> V_26 ;
unsigned char * V_90 ;
unsigned char V_50 ;
unsigned int V_72 ;
if ( V_39 -> V_65 == NULL || ( V_90 = V_39 -> V_65 -> V_11 ) == NULL ) {
F_19 ( V_92 L_8 , V_2 -> V_56 ) ;
V_39 -> V_57 = V_64 ;
V_39 -> V_65 = NULL ;
return ERROR ;
}
switch ( V_39 -> V_57 ) {
case V_62 :
if ( ( F_5 ( V_2 ) & 0xf8 ) != 0x80 )
return V_53 ;
F_4 ( V_2 , 0x08 ) ;
V_72 = V_12 -> V_24 ;
while ( 1 ) {
F_27 ( V_74 ) ;
F_17 ( & V_12 -> V_34 ) ;
if ( V_12 -> V_46 == V_61 ) {
F_18 ( & V_12 -> V_34 ) ;
V_2 -> V_58 . V_111 ++ ;
return V_47 ;
}
V_50 = F_5 ( V_2 ) ;
if ( V_50 & 0x08 ) {
F_18 ( & V_12 -> V_34 ) ;
F_22 ( V_2 -> V_3 ) ;
F_23 ( V_2 -> V_3 ) ;
if ( V_12 -> V_46 == V_61 ) {
F_35 ( V_2 -> V_3 ) ;
V_2 -> V_58 . V_111 ++ ;
return V_47 ;
}
F_3 ( V_2 ) ;
if ( V_91 > 2 )
F_19 ( V_92 L_9 , V_2 -> V_56 ) ;
V_39 -> V_57 = V_93 ;
V_39 -> V_26 = V_73 ;
V_12 -> V_52 = 0 ;
break;
}
F_18 ( & V_12 -> V_34 ) ;
if ( -- V_72 == 0 ) {
F_4 ( V_2 , 0x00 ) ;
return V_53 ;
}
}
case V_93 :
if ( F_40 ( V_67 , V_2 ,
& V_39 -> V_26 , V_39 -> V_94 . V_95 . V_96 ) )
return V_54 ;
V_39 -> V_57 = V_97 ;
case V_97 :
if ( F_40 ( V_67 , V_2 ,
& V_39 -> V_26 , V_39 -> V_94 . V_95 . V_98 ) )
return V_54 ;
V_39 -> V_57 = V_102 ;
V_39 -> V_103 = 0 ;
V_39 -> V_104 = 0 ;
case V_102 :
do {
if ( F_40 ( V_67 , V_2 ,
& V_39 -> V_26 , V_90 [ V_39 -> V_103 ] ) )
return V_54 ;
} while ( ++ V_39 -> V_103 < V_39 -> V_94 . V_99 );
do {
V_39 -> V_104 += V_90 [ -- V_39 -> V_103 ] ;
} while ( V_39 -> V_103 );
V_39 -> V_57 = V_105 ;
case V_105 :
if ( F_40 ( V_67 , V_2 ,
& V_39 -> V_26 , V_39 -> V_104 ) )
return V_54 ;
V_2 -> V_58 . V_112 += V_39 -> V_65 -> V_113 ;
F_21 ( V_39 -> V_65 ) ;
V_2 -> V_58 . V_114 ++ ;
V_39 -> V_57 = V_64 ;
case V_64 :
F_4 ( V_2 , 0x00 ) ;
V_39 -> V_65 = NULL ;
if ( V_91 > 2 )
F_19 ( V_92 L_10 , V_2 -> V_56 ) ;
V_12 -> V_46 = V_115 ;
V_12 -> V_37 = 1 ;
F_13 ( & V_12 -> V_30 , 1 ) ;
F_1 ( V_2 ) ;
F_35 ( V_2 -> V_3 ) ;
return V_47 ;
}
return V_47 ;
}
static int
F_42 ( struct V_1 * V_2 , struct V_6 * V_12 ,
struct V_38 * V_39 , struct V_38 * V_41 )
{
F_17 ( & V_12 -> V_34 ) ;
if ( V_12 -> V_46 == V_115 ) {
V_12 -> V_46 = V_110 ;
F_43 ( V_2 ) ;
}
F_18 ( & V_12 -> V_34 ) ;
if ( V_12 -> V_116 ) {
V_12 -> V_116 = V_12 -> V_23 = 0 ;
F_44 ( V_12 -> V_7 ) ;
}
return V_47 ;
}
static int
F_45 ( struct V_1 * V_2 , struct V_6 * V_12 ,
struct V_38 * V_39 , struct V_38 * V_41 )
{
unsigned char V_117 ;
V_117 = F_5 ( V_2 ) ;
if ( ( V_117 & 0xf8 ) == 0x80 ) {
if ( V_91 > 2 )
F_19 ( V_92 L_11 , V_2 -> V_56 ) ;
V_12 -> V_46 = V_110 ;
V_12 -> V_116 = 0 ;
F_46 ( V_2 ) ;
F_1 ( V_2 ) ;
F_35 ( V_2 -> V_3 ) ;
F_43 ( V_2 ) ;
} else {
V_12 -> V_37 = 1 ;
F_13 ( & V_12 -> V_30 , 1 ) ;
}
return V_47 ;
}
static void
F_15 ( void * V_118 )
{
struct V_1 * V_2 = V_118 ;
struct V_6 * V_12 ;
struct V_38 * V_41 ;
unsigned char V_50 ;
unsigned long V_14 ;
V_12 = F_2 ( V_2 ) ;
V_41 = & V_12 -> V_42 ;
F_47 ( & V_12 -> V_34 , V_14 ) ;
V_50 = F_5 ( V_2 ) ;
if ( ( V_50 & 0xf8 ) != 0xc0 ) {
if ( ( V_2 -> V_3 != - 1 ) && ( V_91 > 1 ) )
F_19 ( V_92 L_12 , V_2 -> V_56 ) ;
F_48 ( & V_12 -> V_34 , V_14 ) ;
return;
}
if ( V_91 > 3 )
F_19 ( V_92 L_13 , V_2 -> V_56 ) ;
switch ( V_12 -> V_46 ) {
case V_115 :
F_43 ( V_2 ) ;
case V_110 :
case V_51 :
V_41 -> V_57 = V_62 ;
V_12 -> V_46 = V_61 ;
V_12 -> V_52 = 0 ;
F_11 ( & V_12 -> V_28 ) ;
break;
case V_61 :
break;
case V_66 :
F_19 ( V_101 L_14 , V_2 -> V_56 ) ;
break;
}
F_48 ( & V_12 -> V_34 , V_14 ) ;
}
static int
F_49 ( struct V_77 * V_65 , struct V_1 * V_2 )
{
struct V_6 * V_12 = F_2 ( V_2 ) ;
struct V_38 * V_39 = & V_12 -> V_40 ;
if ( F_50 ( V_2 ) )
return V_119 ;
if ( ! V_12 -> V_23 ) {
if ( F_51 ( V_12 -> V_7 ) )
return V_119 ;
V_12 -> V_23 = 1 ;
}
F_24 ( V_2 ) ;
if ( V_65 -> V_113 > V_2 -> V_100 + V_2 -> V_81 ) {
F_19 ( V_55 L_15 , V_2 -> V_56 , ( int ) V_65 -> V_113 ) ;
F_46 ( V_2 ) ;
return V_119 ;
}
if ( V_91 > 2 )
F_19 ( V_92 L_16 , V_2 -> V_56 ) ;
F_17 ( & V_12 -> V_34 ) ;
V_39 -> V_65 = V_65 ;
V_39 -> V_94 . V_99 = V_65 -> V_113 ;
V_39 -> V_57 = V_62 ;
if ( V_12 -> V_46 == V_110 ) {
V_12 -> V_46 = V_51 ;
V_12 -> V_52 = 0 ;
}
F_11 ( & V_12 -> V_28 ) ;
F_18 ( & V_12 -> V_34 ) ;
return V_120 ;
}
static void
F_52 ( const struct V_1 * V_2 , struct V_78 * V_79 )
{
const struct V_121 * V_122 ;
F_53 () ;
V_122 = F_54 ( V_2 ) ;
if ( V_122 ) {
const struct V_123 * V_124 = V_122 -> V_125 ;
if ( V_124 ) {
memcpy ( V_79 -> V_126 , V_2 -> V_17 , 6 ) ;
memset ( V_79 -> V_82 , 0xfc , 2 ) ;
memcpy ( V_79 -> V_82 + 2 , & V_124 -> V_127 , 4 ) ;
}
}
F_55 () ;
}
static int
F_56 ( struct V_77 * V_65 , struct V_1 * V_2 ,
unsigned short type , const void * V_128 ,
const void * V_129 , unsigned V_113 )
{
int V_130 ;
V_130 = F_57 ( V_65 , V_2 , type , V_128 , V_129 , V_113 ) ;
if ( V_130 >= 0 )
F_52 ( V_2 , (struct V_78 * ) V_65 -> V_11 ) ;
return V_130 ;
}
static int F_58 ( const struct V_131 * V_132 ,
struct V_133 * V_134 , T_2 type )
{
int V_130 ;
V_130 = F_59 ( V_132 , V_134 , type ) ;
if ( V_130 == 0 ) {
struct V_78 * V_79 ;
V_79 = (struct V_78 * ) ( ( ( V_135 * ) V_134 -> V_136 ) +
F_60 ( sizeof( * V_79 ) ) ) ;
F_52 ( V_132 -> V_2 , V_79 ) ;
}
return V_130 ;
}
static int
F_61 ( struct V_1 * V_2 )
{
struct V_6 * V_12 = F_2 ( V_2 ) ;
struct V_121 * V_122 ;
if ( ! V_12 -> V_23 ) {
if ( F_51 ( V_12 -> V_7 ) ) return - V_137 ;
V_12 -> V_23 = 1 ;
}
V_12 -> V_116 = 0 ;
F_4 ( V_2 , 0x00 ) ;
F_1 ( V_2 ) ;
if ( V_2 -> V_3 == - 1 )
{
F_62 ( & V_12 -> V_48 , 0 ) ;
F_13 ( & V_12 -> V_32 , 1 ) ;
}
V_12 -> V_42 . V_57 = V_12 -> V_40 . V_57 = V_64 ;
V_12 -> V_42 . V_65 = V_12 -> V_40 . V_65 = NULL ;
V_12 -> V_46 = V_110 ;
V_12 -> V_37 = 0 ;
V_122 = F_63 ( V_2 ) ;
if ( V_122 ) {
struct V_123 * V_124 = V_122 -> V_125 ;
if ( V_124 != NULL ) {
memcpy ( V_2 -> V_17 + 2 , & V_124 -> V_138 , 4 ) ;
}
}
F_46 ( V_2 ) ;
return 0 ;
}
static int
F_64 ( struct V_1 * V_2 )
{
struct V_6 * V_12 = F_2 ( V_2 ) ;
struct V_38 * V_39 = & V_12 -> V_40 ;
struct V_38 * V_41 = & V_12 -> V_42 ;
F_24 ( V_2 ) ;
F_22 ( V_2 -> V_3 ) ;
F_23 ( V_2 -> V_3 ) ;
if ( V_2 -> V_3 == - 1 )
{
F_65 ( & V_12 -> V_49 ) ;
F_62 ( & V_12 -> V_48 , 1 ) ;
F_66 ( & V_12 -> V_49 ) ;
}
#ifdef F_67
F_68 ( 0x00 , F_69 ( V_2 ) ) ;
#endif
V_12 -> V_37 = 0 ;
V_12 -> V_46 = V_110 ;
if ( V_12 -> V_23 ) {
F_44 ( V_12 -> V_7 ) ;
V_12 -> V_23 = 0 ;
}
V_39 -> V_57 = V_64 ;
if ( V_39 -> V_65 ) {
F_21 ( V_39 -> V_65 ) ;
V_39 -> V_65 = NULL ;
}
V_41 -> V_57 = V_64 ;
if ( V_41 -> V_65 ) {
F_20 ( V_41 -> V_65 ) ;
V_41 -> V_65 = NULL ;
}
#ifdef F_67
F_68 ( 0x00 , F_70 ( V_2 ) ) ;
#endif
return 0 ;
}
static int
F_71 ( void * V_139 )
{
struct V_1 * V_2 = (struct V_1 * ) V_139 ;
struct V_6 * V_12 = F_2 ( V_2 ) ;
if ( V_12 -> V_46 != V_110 ) {
V_12 -> V_116 = 1 ;
return 1 ;
}
V_12 -> V_23 = 0 ;
return 0 ;
}
static void
F_72 ( void * V_139 )
{
struct V_1 * V_2 = (struct V_1 * ) V_139 ;
struct V_6 * V_12 = F_2 ( V_2 ) ;
if ( V_12 -> V_23 ) {
F_19 ( V_92 L_17 , V_2 -> V_56 ) ;
if ( ! F_51 ( V_12 -> V_7 ) )
F_19 ( V_92 L_18 , V_2 -> V_56 ) ;
else
return;
}
if ( ! ( V_2 -> V_14 & V_140 ) )
return;
if ( ! F_51 ( V_12 -> V_7 ) ) {
V_12 -> V_23 = 1 ;
F_4 ( V_2 , 0x00 ) ;
}
}
static int
F_73 ( struct V_1 * V_2 , struct V_141 * V_142 , int V_143 )
{
struct V_6 * V_12 = F_2 ( V_2 ) ;
struct V_144 * V_145 = (struct V_144 * ) & V_142 -> V_146 ;
if ( V_143 != V_147 )
return - V_148 ;
switch( V_145 -> V_149 ) {
case V_150 :
V_145 -> V_24 = V_12 -> V_24 ;
V_145 -> V_26 = V_12 -> V_26 ;
break;
case V_151 :
if( ! F_74 ( V_152 ) )
return - V_153 ;
V_12 -> V_24 = V_145 -> V_24 ;
V_12 -> V_26 = V_145 -> V_26 ;
break;
default:
return - V_148 ;
}
return 0 ;
}
static inline int
F_75 ( int V_154 [] , int V_155 )
{
int V_156 ;
for ( V_156 = 0 ; V_156 < V_157 && V_154 [ V_156 ] != - 1 ; V_156 ++ ) {
if ( V_154 [ V_156 ] == V_155 ) return 1 ;
}
return 0 ;
}
static void F_76 ( struct V_4 * V_5 )
{
static int V_158 ;
struct V_1 * V_2 ;
struct V_6 * V_12 ;
char V_56 [ V_159 ] ;
if ( ( V_4 [ 0 ] == - 1 && ( ! V_160 || ! V_5 -> V_161 ) ) ||
F_75 ( V_4 , V_5 -> V_162 ) ) {
if ( V_158 == V_157 ) {
F_19 ( V_101 L_19 ) ;
return;
}
sprintf ( V_56 , L_20 , V_158 ) ;
V_2 = F_77 ( sizeof( struct V_6 ) ) ;
if ( ! V_2 ) {
F_19 ( V_101 L_21 ) ;
return;
}
strcpy ( V_2 -> V_56 , V_56 ) ;
V_2 -> V_3 = V_5 -> V_3 ;
V_2 -> V_163 = V_5 -> V_164 ;
if ( V_5 -> V_3 == - 1 ) {
F_19 ( V_165 L_22
L_23 , V_5 -> V_56 ) ;
}
V_12 = F_2 ( V_2 ) ;
V_12 -> V_2 = V_2 ;
V_12 -> V_7 = F_78 ( V_5 , V_2 -> V_56 , F_71 ,
F_72 , F_15 ,
0 , V_2 ) ;
if ( ! V_12 -> V_7 ) {
F_19 ( V_101 L_24 , V_56 ) ;
goto V_166;
}
F_6 ( V_2 ) ;
if ( F_79 ( V_2 ) ) {
F_19 ( V_101 L_25 , V_56 ) ;
goto V_167;
}
F_19 ( V_165 L_26 , V_168 ) ;
if ( V_2 -> V_3 != - 1 )
F_19 ( V_165 L_27
L_28 ,
V_2 -> V_56 , V_2 -> V_163 , V_2 -> V_3 ) ;
else
F_19 ( V_165 L_27
L_29 ,
V_2 -> V_56 , V_2 -> V_163 ) ;
V_169 [ V_158 ++ ] = V_2 ;
}
return;
V_167:
F_80 ( V_12 -> V_7 ) ;
V_166:
F_81 ( V_2 ) ;
}
static void F_82 ( struct V_4 * V_5 )
{
}
static void T_3 F_83 ( void )
{
struct V_1 * V_2 ;
int V_156 ;
F_84 ( & V_170 ) ;
for ( V_156 = 0 ; V_156 < V_157 ; V_156 ++ ) {
if ( ( V_2 = V_169 [ V_156 ] ) ) {
struct V_6 * V_12 = F_2 ( V_2 ) ;
F_85 ( V_2 ) ;
if ( V_12 -> V_23 )
F_44 ( V_12 -> V_7 ) ;
F_80 ( V_12 -> V_7 ) ;
F_81 ( V_2 ) ;
V_169 [ V_156 ] = NULL ;
}
}
}
static int T_4 F_86 ( char * V_171 )
{
int V_172 [ 4 ] ;
V_171 = F_87 ( V_171 , F_88 ( V_172 ) , V_172 ) ;
if ( ! strncmp ( V_171 , L_30 , 7 ) ) {
int V_173 = F_89 ( V_171 + 7 , NULL , 10 ) ;
if ( V_174 < V_157 )
V_4 [ V_174 ++ ] = V_173 ;
else
F_19 ( V_165 L_31 ,
V_171 ) ;
} else if ( ! strcmp ( V_171 , L_32 ) ) {
V_160 = 1 ;
} else {
if ( V_172 [ 0 ] == 0 || V_172 [ 1 ] == 0 ) {
V_4 [ 0 ] = - 2 ;
} else {
F_19 ( V_55 L_33 ,
V_172 [ 1 ] ) ;
}
}
return 1 ;
}
static int T_4 F_90 ( void )
{
if ( V_4 [ 0 ] == - 2 )
return 0 ;
if ( V_4 [ 0 ] != - 1 && V_160 ) {
F_19 ( V_55 L_34 ) ;
V_160 = 0 ;
}
if ( F_91 ( & V_170 ) ) {
F_19 ( V_55 L_35 ) ;
return 1 ;
}
return 0 ;
}
