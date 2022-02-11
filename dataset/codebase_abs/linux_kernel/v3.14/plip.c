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
if( F_32 ( V_79 -> V_82 ) )
{
if( F_33 ( V_79 -> V_82 , V_2 -> V_83 ) )
V_65 -> V_84 = V_85 ;
else
V_65 -> V_84 = V_86 ;
}
if ( F_34 ( V_79 -> V_87 ) >= V_88 )
return V_79 -> V_87 ;
V_80 = V_65 -> V_11 ;
if ( * ( unsigned short * ) V_80 == 0xFFFF )
return F_35 ( V_89 ) ;
return F_35 ( V_90 ) ;
}
static int
F_36 ( struct V_1 * V_2 , struct V_6 * V_12 ,
struct V_38 * V_39 , struct V_38 * V_41 )
{
unsigned short V_67 = V_12 -> V_26 ;
unsigned char * V_91 ;
switch ( V_41 -> V_57 ) {
case V_62 :
F_22 ( V_2 -> V_3 ) ;
F_3 ( V_2 ) ;
F_4 ( V_2 , 0x01 ) ;
if ( V_92 > 2 )
F_19 ( V_93 L_3 , V_2 -> V_56 ) ;
V_41 -> V_57 = V_94 ;
V_41 -> V_26 = V_73 ;
case V_94 :
if ( V_39 -> V_57 != V_64 ) {
if ( F_26 ( V_12 -> V_24 , V_2 ,
& V_41 -> V_26 , & V_41 -> V_95 . V_96 . V_97 ) ) {
V_41 -> V_57 = V_64 ;
V_12 -> V_37 = 1 ;
V_12 -> V_46 = V_51 ;
F_13 ( & V_12 -> V_30 , 1 ) ;
F_1 ( V_2 ) ;
F_37 ( V_2 -> V_3 ) ;
return V_47 ;
}
} else {
if ( F_26 ( V_67 , V_2 ,
& V_41 -> V_26 , & V_41 -> V_95 . V_96 . V_97 ) )
return V_54 ;
}
V_41 -> V_57 = V_98 ;
case V_98 :
if ( F_26 ( V_67 , V_2 ,
& V_41 -> V_26 , & V_41 -> V_95 . V_96 . V_99 ) )
return V_54 ;
if ( V_41 -> V_95 . V_100 > V_2 -> V_101 + V_2 -> V_81 ||
V_41 -> V_95 . V_100 < 8 ) {
F_19 ( V_55 L_4 , V_2 -> V_56 , V_41 -> V_95 . V_100 ) ;
return ERROR ;
}
V_41 -> V_65 = F_38 ( V_41 -> V_95 . V_100 + 2 ) ;
if ( V_41 -> V_65 == NULL ) {
F_19 ( V_102 L_5 , V_2 -> V_56 ) ;
return ERROR ;
}
F_39 ( V_41 -> V_65 , 2 ) ;
F_40 ( V_41 -> V_65 , V_41 -> V_95 . V_100 ) ;
V_41 -> V_65 -> V_2 = V_2 ;
V_41 -> V_57 = V_103 ;
V_41 -> V_104 = 0 ;
V_41 -> V_105 = 0 ;
case V_103 :
V_91 = V_41 -> V_65 -> V_11 ;
do {
if ( F_26 ( V_67 , V_2 ,
& V_41 -> V_26 , & V_91 [ V_41 -> V_104 ] ) )
return V_54 ;
} while ( ++ V_41 -> V_104 < V_41 -> V_95 . V_100 );
do {
V_41 -> V_105 += V_91 [ -- V_41 -> V_104 ] ;
} while ( V_41 -> V_104 );
V_41 -> V_57 = V_106 ;
case V_106 :
if ( F_26 ( V_67 , V_2 ,
& V_41 -> V_26 , & V_41 -> V_11 ) )
return V_54 ;
if ( V_41 -> V_11 != V_41 -> V_105 ) {
V_2 -> V_58 . V_107 ++ ;
if ( V_92 )
F_19 ( V_93 L_6 , V_2 -> V_56 ) ;
return ERROR ;
}
V_41 -> V_57 = V_64 ;
case V_64 :
V_41 -> V_65 -> V_108 = F_28 ( V_41 -> V_65 , V_2 ) ;
F_41 ( V_41 -> V_65 ) ;
V_2 -> V_58 . V_109 += V_41 -> V_95 . V_100 ;
V_2 -> V_58 . V_110 ++ ;
V_41 -> V_65 = NULL ;
if ( V_92 > 2 )
F_19 ( V_93 L_7 , V_2 -> V_56 ) ;
F_4 ( V_2 , 0x00 ) ;
F_17 ( & V_12 -> V_34 ) ;
if ( V_39 -> V_57 != V_64 ) {
V_12 -> V_46 = V_51 ;
F_18 ( & V_12 -> V_34 ) ;
F_11 ( & V_12 -> V_28 ) ;
F_1 ( V_2 ) ;
F_37 ( V_2 -> V_3 ) ;
return V_47 ;
} else {
V_12 -> V_46 = V_111 ;
F_18 ( & V_12 -> V_34 ) ;
F_1 ( V_2 ) ;
F_37 ( V_2 -> V_3 ) ;
return V_47 ;
}
}
return V_47 ;
}
static inline int
F_42 ( unsigned short V_67 , struct V_1 * V_2 ,
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
F_43 ( struct V_1 * V_2 , struct V_6 * V_12 ,
struct V_38 * V_39 , struct V_38 * V_41 )
{
unsigned short V_67 = V_12 -> V_26 ;
unsigned char * V_91 ;
unsigned char V_50 ;
unsigned int V_72 ;
if ( V_39 -> V_65 == NULL || ( V_91 = V_39 -> V_65 -> V_11 ) == NULL ) {
F_19 ( V_93 L_8 , V_2 -> V_56 ) ;
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
V_2 -> V_58 . V_112 ++ ;
return V_47 ;
}
V_50 = F_5 ( V_2 ) ;
if ( V_50 & 0x08 ) {
F_18 ( & V_12 -> V_34 ) ;
F_22 ( V_2 -> V_3 ) ;
F_23 ( V_2 -> V_3 ) ;
if ( V_12 -> V_46 == V_61 ) {
F_37 ( V_2 -> V_3 ) ;
V_2 -> V_58 . V_112 ++ ;
return V_47 ;
}
F_3 ( V_2 ) ;
if ( V_92 > 2 )
F_19 ( V_93 L_9 , V_2 -> V_56 ) ;
V_39 -> V_57 = V_94 ;
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
case V_94 :
if ( F_42 ( V_67 , V_2 ,
& V_39 -> V_26 , V_39 -> V_95 . V_96 . V_97 ) )
return V_54 ;
V_39 -> V_57 = V_98 ;
case V_98 :
if ( F_42 ( V_67 , V_2 ,
& V_39 -> V_26 , V_39 -> V_95 . V_96 . V_99 ) )
return V_54 ;
V_39 -> V_57 = V_103 ;
V_39 -> V_104 = 0 ;
V_39 -> V_105 = 0 ;
case V_103 :
do {
if ( F_42 ( V_67 , V_2 ,
& V_39 -> V_26 , V_91 [ V_39 -> V_104 ] ) )
return V_54 ;
} while ( ++ V_39 -> V_104 < V_39 -> V_95 . V_100 );
do {
V_39 -> V_105 += V_91 [ -- V_39 -> V_104 ] ;
} while ( V_39 -> V_104 );
V_39 -> V_57 = V_106 ;
case V_106 :
if ( F_42 ( V_67 , V_2 ,
& V_39 -> V_26 , V_39 -> V_105 ) )
return V_54 ;
V_2 -> V_58 . V_113 += V_39 -> V_65 -> V_114 ;
F_21 ( V_39 -> V_65 ) ;
V_2 -> V_58 . V_115 ++ ;
V_39 -> V_57 = V_64 ;
case V_64 :
F_4 ( V_2 , 0x00 ) ;
V_39 -> V_65 = NULL ;
if ( V_92 > 2 )
F_19 ( V_93 L_10 , V_2 -> V_56 ) ;
V_12 -> V_46 = V_116 ;
V_12 -> V_37 = 1 ;
F_13 ( & V_12 -> V_30 , 1 ) ;
F_1 ( V_2 ) ;
F_37 ( V_2 -> V_3 ) ;
return V_47 ;
}
return V_47 ;
}
static int
F_44 ( struct V_1 * V_2 , struct V_6 * V_12 ,
struct V_38 * V_39 , struct V_38 * V_41 )
{
F_17 ( & V_12 -> V_34 ) ;
if ( V_12 -> V_46 == V_116 ) {
V_12 -> V_46 = V_111 ;
F_45 ( V_2 ) ;
}
F_18 ( & V_12 -> V_34 ) ;
if ( V_12 -> V_117 ) {
V_12 -> V_117 = V_12 -> V_23 = 0 ;
F_46 ( V_12 -> V_7 ) ;
}
return V_47 ;
}
static int
F_47 ( struct V_1 * V_2 , struct V_6 * V_12 ,
struct V_38 * V_39 , struct V_38 * V_41 )
{
unsigned char V_118 ;
V_118 = F_5 ( V_2 ) ;
if ( ( V_118 & 0xf8 ) == 0x80 ) {
if ( V_92 > 2 )
F_19 ( V_93 L_11 , V_2 -> V_56 ) ;
V_12 -> V_46 = V_111 ;
V_12 -> V_117 = 0 ;
F_48 ( V_2 ) ;
F_1 ( V_2 ) ;
F_37 ( V_2 -> V_3 ) ;
F_45 ( V_2 ) ;
} else {
V_12 -> V_37 = 1 ;
F_13 ( & V_12 -> V_30 , 1 ) ;
}
return V_47 ;
}
static void
F_15 ( void * V_119 )
{
struct V_1 * V_2 = V_119 ;
struct V_6 * V_12 ;
struct V_38 * V_41 ;
unsigned char V_50 ;
unsigned long V_14 ;
V_12 = F_2 ( V_2 ) ;
V_41 = & V_12 -> V_42 ;
F_49 ( & V_12 -> V_34 , V_14 ) ;
V_50 = F_5 ( V_2 ) ;
if ( ( V_50 & 0xf8 ) != 0xc0 ) {
if ( ( V_2 -> V_3 != - 1 ) && ( V_92 > 1 ) )
F_19 ( V_93 L_12 , V_2 -> V_56 ) ;
F_50 ( & V_12 -> V_34 , V_14 ) ;
return;
}
if ( V_92 > 3 )
F_19 ( V_93 L_13 , V_2 -> V_56 ) ;
switch ( V_12 -> V_46 ) {
case V_116 :
F_45 ( V_2 ) ;
case V_111 :
case V_51 :
V_41 -> V_57 = V_62 ;
V_12 -> V_46 = V_61 ;
V_12 -> V_52 = 0 ;
F_11 ( & V_12 -> V_28 ) ;
break;
case V_61 :
break;
case V_66 :
F_19 ( V_102 L_14 , V_2 -> V_56 ) ;
break;
}
F_50 ( & V_12 -> V_34 , V_14 ) ;
}
static int
F_51 ( struct V_77 * V_65 , struct V_1 * V_2 )
{
struct V_6 * V_12 = F_2 ( V_2 ) ;
struct V_38 * V_39 = & V_12 -> V_40 ;
if ( F_52 ( V_2 ) )
return V_120 ;
if ( ! V_12 -> V_23 ) {
if ( F_53 ( V_12 -> V_7 ) )
return V_120 ;
V_12 -> V_23 = 1 ;
}
F_24 ( V_2 ) ;
if ( V_65 -> V_114 > V_2 -> V_101 + V_2 -> V_81 ) {
F_19 ( V_55 L_15 , V_2 -> V_56 , ( int ) V_65 -> V_114 ) ;
F_48 ( V_2 ) ;
return V_120 ;
}
if ( V_92 > 2 )
F_19 ( V_93 L_16 , V_2 -> V_56 ) ;
F_17 ( & V_12 -> V_34 ) ;
V_39 -> V_65 = V_65 ;
V_39 -> V_95 . V_100 = V_65 -> V_114 ;
V_39 -> V_57 = V_62 ;
if ( V_12 -> V_46 == V_111 ) {
V_12 -> V_46 = V_51 ;
V_12 -> V_52 = 0 ;
}
F_11 ( & V_12 -> V_28 ) ;
F_18 ( & V_12 -> V_34 ) ;
return V_121 ;
}
static void
F_54 ( const struct V_1 * V_2 , struct V_78 * V_79 )
{
const struct V_122 * V_123 ;
F_55 () ;
V_123 = F_56 ( V_2 ) ;
if ( V_123 ) {
const struct V_124 * V_125 = V_123 -> V_126 ;
if ( V_125 ) {
memcpy ( V_79 -> V_127 , V_2 -> V_17 , V_18 ) ;
memset ( V_79 -> V_82 , 0xfc , 2 ) ;
memcpy ( V_79 -> V_82 + 2 , & V_125 -> V_128 , 4 ) ;
}
}
F_57 () ;
}
static int
F_58 ( struct V_77 * V_65 , struct V_1 * V_2 ,
unsigned short type , const void * V_129 ,
const void * V_130 , unsigned V_114 )
{
int V_131 ;
V_131 = F_59 ( V_65 , V_2 , type , V_129 , V_130 , V_114 ) ;
if ( V_131 >= 0 )
F_54 ( V_2 , (struct V_78 * ) V_65 -> V_11 ) ;
return V_131 ;
}
static int F_60 ( const struct V_132 * V_133 ,
struct V_134 * V_135 , T_2 type )
{
int V_131 ;
V_131 = F_61 ( V_133 , V_135 , type ) ;
if ( V_131 == 0 ) {
struct V_78 * V_79 ;
V_79 = (struct V_78 * ) ( ( ( V_136 * ) V_135 -> V_137 ) +
F_62 ( sizeof( * V_79 ) ) ) ;
F_54 ( V_133 -> V_2 , V_79 ) ;
}
return V_131 ;
}
static int
F_63 ( struct V_1 * V_2 )
{
struct V_6 * V_12 = F_2 ( V_2 ) ;
struct V_122 * V_123 ;
if ( ! V_12 -> V_23 ) {
if ( F_53 ( V_12 -> V_7 ) ) return - V_138 ;
V_12 -> V_23 = 1 ;
}
V_12 -> V_117 = 0 ;
F_4 ( V_2 , 0x00 ) ;
F_1 ( V_2 ) ;
if ( V_2 -> V_3 == - 1 )
{
F_64 ( & V_12 -> V_48 , 0 ) ;
F_13 ( & V_12 -> V_32 , 1 ) ;
}
V_12 -> V_42 . V_57 = V_12 -> V_40 . V_57 = V_64 ;
V_12 -> V_42 . V_65 = V_12 -> V_40 . V_65 = NULL ;
V_12 -> V_46 = V_111 ;
V_12 -> V_37 = 0 ;
V_123 = F_65 ( V_2 ) ;
if ( V_123 ) {
struct V_124 * V_125 = V_123 -> V_126 ;
if ( V_125 != NULL ) {
memcpy ( V_2 -> V_17 + 2 , & V_125 -> V_139 , 4 ) ;
}
}
F_48 ( V_2 ) ;
return 0 ;
}
static int
F_66 ( struct V_1 * V_2 )
{
struct V_6 * V_12 = F_2 ( V_2 ) ;
struct V_38 * V_39 = & V_12 -> V_40 ;
struct V_38 * V_41 = & V_12 -> V_42 ;
F_24 ( V_2 ) ;
F_22 ( V_2 -> V_3 ) ;
F_23 ( V_2 -> V_3 ) ;
if ( V_2 -> V_3 == - 1 )
{
F_67 ( & V_12 -> V_49 ) ;
F_64 ( & V_12 -> V_48 , 1 ) ;
F_68 ( & V_12 -> V_49 ) ;
}
#ifdef F_69
F_70 ( 0x00 , F_71 ( V_2 ) ) ;
#endif
V_12 -> V_37 = 0 ;
V_12 -> V_46 = V_111 ;
if ( V_12 -> V_23 ) {
F_46 ( V_12 -> V_7 ) ;
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
#ifdef F_69
F_70 ( 0x00 , F_72 ( V_2 ) ) ;
#endif
return 0 ;
}
static int
F_73 ( void * V_140 )
{
struct V_1 * V_2 = (struct V_1 * ) V_140 ;
struct V_6 * V_12 = F_2 ( V_2 ) ;
if ( V_12 -> V_46 != V_111 ) {
V_12 -> V_117 = 1 ;
return 1 ;
}
V_12 -> V_23 = 0 ;
return 0 ;
}
static void
F_74 ( void * V_140 )
{
struct V_1 * V_2 = (struct V_1 * ) V_140 ;
struct V_6 * V_12 = F_2 ( V_2 ) ;
if ( V_12 -> V_23 ) {
F_19 ( V_93 L_17 , V_2 -> V_56 ) ;
if ( ! F_53 ( V_12 -> V_7 ) )
F_19 ( V_93 L_18 , V_2 -> V_56 ) ;
else
return;
}
if ( ! ( V_2 -> V_14 & V_141 ) )
return;
if ( ! F_53 ( V_12 -> V_7 ) ) {
V_12 -> V_23 = 1 ;
F_4 ( V_2 , 0x00 ) ;
}
}
static int
F_75 ( struct V_1 * V_2 , struct V_142 * V_143 , int V_144 )
{
struct V_6 * V_12 = F_2 ( V_2 ) ;
struct V_145 * V_146 = (struct V_145 * ) & V_143 -> V_147 ;
if ( V_144 != V_148 )
return - V_149 ;
switch( V_146 -> V_150 ) {
case V_151 :
V_146 -> V_24 = V_12 -> V_24 ;
V_146 -> V_26 = V_12 -> V_26 ;
break;
case V_152 :
if( ! F_76 ( V_153 ) )
return - V_154 ;
V_12 -> V_24 = V_146 -> V_24 ;
V_12 -> V_26 = V_146 -> V_26 ;
break;
default:
return - V_149 ;
}
return 0 ;
}
static inline int
F_77 ( int V_155 [] , int V_156 )
{
int V_157 ;
for ( V_157 = 0 ; V_157 < V_158 && V_155 [ V_157 ] != - 1 ; V_157 ++ ) {
if ( V_155 [ V_157 ] == V_156 ) return 1 ;
}
return 0 ;
}
static void F_78 ( struct V_4 * V_5 )
{
static int V_159 ;
struct V_1 * V_2 ;
struct V_6 * V_12 ;
char V_56 [ V_160 ] ;
if ( ( V_4 [ 0 ] == - 1 && ( ! V_161 || ! V_5 -> V_162 ) ) ||
F_77 ( V_4 , V_5 -> V_163 ) ) {
if ( V_159 == V_158 ) {
F_19 ( V_102 L_19 ) ;
return;
}
sprintf ( V_56 , L_20 , V_159 ) ;
V_2 = F_79 ( sizeof( struct V_6 ) ) ;
if ( ! V_2 )
return;
strcpy ( V_2 -> V_56 , V_56 ) ;
V_2 -> V_3 = V_5 -> V_3 ;
V_2 -> V_164 = V_5 -> V_165 ;
if ( V_5 -> V_3 == - 1 ) {
F_19 ( V_166 L_21
L_22 , V_5 -> V_56 ) ;
}
V_12 = F_2 ( V_2 ) ;
V_12 -> V_2 = V_2 ;
V_12 -> V_7 = F_80 ( V_5 , V_2 -> V_56 , F_73 ,
F_74 , F_15 ,
0 , V_2 ) ;
if ( ! V_12 -> V_7 ) {
F_19 ( V_102 L_23 , V_56 ) ;
goto V_167;
}
F_6 ( V_2 ) ;
if ( F_81 ( V_2 ) ) {
F_19 ( V_102 L_24 , V_56 ) ;
goto V_168;
}
F_19 ( V_166 L_25 , V_169 ) ;
if ( V_2 -> V_3 != - 1 )
F_19 ( V_166 L_26
L_27 ,
V_2 -> V_56 , V_2 -> V_164 , V_2 -> V_3 ) ;
else
F_19 ( V_166 L_26
L_28 ,
V_2 -> V_56 , V_2 -> V_164 ) ;
V_170 [ V_159 ++ ] = V_2 ;
}
return;
V_168:
F_82 ( V_12 -> V_7 ) ;
V_167:
F_83 ( V_2 ) ;
}
static void F_84 ( struct V_4 * V_5 )
{
}
static void T_3 F_85 ( void )
{
struct V_1 * V_2 ;
int V_157 ;
F_86 ( & V_171 ) ;
for ( V_157 = 0 ; V_157 < V_158 ; V_157 ++ ) {
if ( ( V_2 = V_170 [ V_157 ] ) ) {
struct V_6 * V_12 = F_2 ( V_2 ) ;
F_87 ( V_2 ) ;
if ( V_12 -> V_23 )
F_46 ( V_12 -> V_7 ) ;
F_82 ( V_12 -> V_7 ) ;
F_83 ( V_2 ) ;
V_170 [ V_157 ] = NULL ;
}
}
}
static int T_4 F_88 ( char * V_172 )
{
int V_173 [ 4 ] ;
V_172 = F_89 ( V_172 , F_90 ( V_173 ) , V_173 ) ;
if ( ! strncmp ( V_172 , L_29 , 7 ) ) {
int V_174 = F_91 ( V_172 + 7 , NULL , 10 ) ;
if ( V_175 < V_158 )
V_4 [ V_175 ++ ] = V_174 ;
else
F_19 ( V_166 L_30 ,
V_172 ) ;
} else if ( ! strcmp ( V_172 , L_31 ) ) {
V_161 = 1 ;
} else {
if ( V_173 [ 0 ] == 0 || V_173 [ 1 ] == 0 ) {
V_4 [ 0 ] = - 2 ;
} else {
F_19 ( V_55 L_32 ,
V_173 [ 1 ] ) ;
}
}
return 1 ;
}
static int T_4 F_92 ( void )
{
if ( V_4 [ 0 ] == - 2 )
return 0 ;
if ( V_4 [ 0 ] != - 1 && V_161 ) {
F_19 ( V_55 L_33 ) ;
V_161 = 0 ;
}
if ( F_93 ( & V_171 ) ) {
F_19 ( V_55 L_34 ) ;
return 1 ;
}
return 0 ;
}
