static void F_1 ( struct V_1 * V_2 , const char * V_3 )
{
if ( V_4 && F_2 () ) {
char * V_5 = V_2 -> V_6 ? V_2 -> V_6 -> V_7 : L_1 ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
F_4 ( V_10 L_2 ,
V_3 , V_5 , F_5 ( V_9 -> V_11 ) , F_5 ( V_9 -> V_12 ) ,
F_5 ( V_9 -> V_13 ) , F_5 ( V_9 -> V_14 ) ) ;
}
}
static void F_6 ( struct V_15 * V_16 , struct V_1 * V_2 , unsigned short V_17 )
{
struct V_18 * V_19 = F_7 ( V_16 ) ;
unsigned short type = ( ( V_17 >> 12 ) & 0x0003 ) ;
int V_20 = 0 ;
switch ( type ) {
case 0 :
if ( F_8 ( V_17 , V_19 -> V_21 ) ) {
V_19 -> V_21 = V_17 & 0x0fff ;
V_20 |= F_9 ( V_16 , V_2 ,
& V_19 -> V_22 ,
V_17 ) ;
}
break;
case 1 :
break;
case 2 :
if ( F_8 ( V_17 , V_19 -> V_23 ) ) {
V_19 -> V_23 = V_17 & 0x0fff ;
V_20 |= F_9 ( V_16 , V_2 ,
& V_19 -> V_24 ,
V_17 ) ;
}
break;
case 3 :
break;
}
if ( V_20 && ! F_10 ( V_16 , V_25 ) )
V_16 -> V_26 ( V_16 ) ;
}
static int F_11 ( struct V_15 * V_16 , struct V_1 * V_2 , int V_27 )
{
T_1 * V_28 = ( T_1 * ) V_2 -> V_29 ;
int V_30 = 0 ;
unsigned short V_17 ;
if ( V_2 -> V_30 < 2 )
return V_30 ;
if ( ( V_17 = F_5 ( * V_28 ) ) & 0x8000 ) {
F_12 ( V_2 , 2 ) ;
V_28 ++ ;
V_30 += 2 ;
if ( ( V_17 & 0x4000 ) == 0 ) {
if ( V_27 )
V_17 ^= 0x2000 ;
F_6 ( V_16 , V_2 , V_17 ) ;
}
}
if ( V_2 -> V_30 < 2 )
return V_30 ;
if ( ( V_17 = F_5 ( * V_28 ) ) & 0x8000 ) {
F_12 ( V_2 , 2 ) ;
V_30 += 2 ;
if ( ( V_17 & 0x4000 ) == 0 ) {
if ( V_27 )
V_17 ^= 0x2000 ;
F_6 ( V_16 , V_2 , V_17 ) ;
}
}
return V_30 ;
}
static inline int F_13 ( unsigned char * * V_31 , int * V_30 , unsigned char V_32 , unsigned char V_33 )
{
unsigned char * V_28 = * V_31 ;
unsigned char V_34 = * V_28 ++ ;
( * V_30 ) -- ;
if ( V_34 > V_32 )
return - 1 ;
if ( ( V_34 + V_33 ) > * V_30 )
return - 1 ;
* V_30 -= V_34 ;
* V_31 = V_28 + V_34 ;
return 0 ;
}
static struct V_15 * F_14 ( struct V_1 * V_2 , unsigned short * V_35 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_36 * V_3 = (struct V_36 * ) V_2 -> V_29 ;
struct V_37 V_38 ;
struct V_37 V_39 ;
unsigned char type = 0 ;
int V_40 ;
int V_41 ;
unsigned char * V_28 ;
int V_30 ;
int V_42 = 0 ;
unsigned char V_43 ;
memset ( & V_38 , 0 , sizeof( struct V_37 ) ) ;
memset ( & V_39 , 0 , sizeof( struct V_37 ) ) ;
V_9 -> V_13 = V_3 -> V_39 ;
V_9 -> V_14 = V_3 -> V_38 ;
V_9 -> V_44 = V_3 -> V_44 ;
V_9 -> V_45 = V_3 -> V_45 ;
V_9 -> V_46 = F_5 ( V_3 -> V_46 ) ;
if ( ! F_15 ( V_2 , sizeof( * V_3 ) ) )
goto V_47;
F_12 ( V_2 , sizeof( * V_3 ) ) ;
V_30 = V_2 -> V_30 ;
V_28 = V_2 -> V_29 ;
V_40 = F_16 ( V_28 , V_30 , & V_38 , & type ) ;
V_42 ++ ;
if ( V_40 < 0 )
goto V_47;
V_42 ++ ;
if ( type > 1 )
goto V_47;
V_30 -= V_40 ;
V_28 += V_40 ;
V_41 = F_16 ( V_28 , V_30 , & V_39 , & type ) ;
V_42 ++ ;
if ( V_41 < 0 )
goto V_47;
V_30 -= V_41 ;
V_28 += V_41 ;
V_42 ++ ;
if ( V_30 < 1 )
goto V_47;
V_43 = * V_28 ;
V_28 ++ ;
V_30 -- ;
V_42 ++ ;
if ( ( V_43 & ( V_48 | V_49 ) ) && ( V_30 < 1 ) )
goto V_47;
V_42 ++ ;
if ( V_43 & V_48 ) {
if ( F_13 ( & V_28 , & V_30 , 39 , 1 ) )
goto V_47;
if ( F_13 ( & V_28 , & V_30 , 39 , 1 ) )
goto V_47;
if ( F_13 ( & V_28 , & V_30 , 39 , ( V_43 & V_49 ) ? 1 : 0 ) )
goto V_47;
}
V_42 ++ ;
if ( V_43 & V_49 ) {
if ( F_13 ( & V_28 , & V_30 , 16 , 0 ) )
goto V_47;
}
return F_17 ( & V_38 ) ;
V_47:
F_1 ( V_2 , V_50 [ V_42 ] . V_51 ) ;
* V_35 = V_50 [ V_42 ] . V_35 ;
return NULL ;
}
static void F_18 ( struct V_15 * V_16 , struct V_1 * V_2 )
{
if ( F_19 ( V_16 ) ) {
F_20 ( V_2 ) ;
return;
}
V_16 -> V_52 ++ ;
F_21 ( & V_16 -> V_53 , V_2 ) ;
V_16 -> V_26 ( V_16 ) ;
}
static void F_22 ( struct V_15 * V_16 , struct V_1 * V_2 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_18 * V_19 = F_7 ( V_16 ) ;
unsigned char * V_28 ;
if ( V_2 -> V_30 < 4 )
goto V_54;
V_28 = V_2 -> V_29 ;
V_9 -> V_44 = * V_28 ++ ;
V_9 -> V_45 = * V_28 ++ ;
V_9 -> V_46 = F_5 ( * ( T_1 * ) V_28 ) ;
if ( ( V_19 -> V_55 == V_56 ) || ( V_19 -> V_55 == V_57 ) ) {
V_19 -> V_58 = 0 ;
V_19 -> V_59 = V_9 -> V_13 ;
V_16 -> V_60 = V_61 ;
V_19 -> V_55 = V_62 ;
V_19 -> V_63 = V_9 -> V_44 ;
V_19 -> V_64 = V_9 -> V_45 ;
V_19 -> V_65 = V_9 -> V_46 ;
if ( ( V_19 -> V_63 & V_66 ) == V_67 )
V_19 -> V_68 = V_69 ;
if ( V_2 -> V_30 > 0 ) {
T_2 V_70 = * V_2 -> V_29 ;
if ( ( V_70 <= 16 ) && ( V_70 <= V_2 -> V_30 ) ) {
V_19 -> V_71 . V_72 = F_23 ( V_70 ) ;
F_24 ( V_2 , 1 ,
V_19 -> V_71 . V_73 , V_70 ) ;
}
}
F_25 ( V_16 , V_74 , 0 ) ;
if ( ! F_10 ( V_16 , V_25 ) )
V_16 -> V_26 ( V_16 ) ;
}
V_54:
F_20 ( V_2 ) ;
}
static void F_26 ( struct V_15 * V_16 , struct V_1 * V_2 )
{
struct V_18 * V_19 = F_7 ( V_16 ) ;
if ( V_19 -> V_55 == V_56 ) {
V_19 -> V_55 = V_57 ;
V_19 -> V_58 = 0 ;
}
F_20 ( V_2 ) ;
}
static void F_27 ( struct V_15 * V_16 , struct V_1 * V_2 )
{
struct V_18 * V_19 = F_7 ( V_16 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
unsigned short V_35 ;
if ( V_2 -> V_30 < 2 )
goto V_54;
V_35 = F_5 ( * ( T_1 * ) V_2 -> V_29 ) ;
F_12 ( V_2 , 2 ) ;
V_19 -> V_75 . V_76 = F_23 ( V_35 ) ;
V_19 -> V_75 . V_72 = 0 ;
memset ( V_19 -> V_75 . V_73 , 0 , 16 ) ;
if ( V_2 -> V_30 > 0 ) {
T_2 V_70 = * V_2 -> V_29 ;
if ( ( V_70 <= 16 ) && ( V_70 <= V_2 -> V_30 ) ) {
V_19 -> V_75 . V_72 = F_23 ( V_70 ) ;
F_24 ( V_2 , 1 , V_19 -> V_75 . V_73 , V_70 ) ;
}
}
V_19 -> V_59 = V_9 -> V_13 ;
V_16 -> V_60 = V_77 ;
switch ( V_19 -> V_55 ) {
case V_56 :
case V_57 :
V_19 -> V_55 = V_78 ;
V_16 -> V_79 = V_80 ;
break;
case V_62 :
V_16 -> V_81 |= V_82 ;
V_19 -> V_55 = V_83 ;
break;
case V_84 :
V_19 -> V_55 = V_85 ;
break;
}
if ( ! F_10 ( V_16 , V_25 ) ) {
if ( V_16 -> V_86 -> V_55 != V_87 )
V_16 -> V_86 -> V_55 = V_88 ;
V_16 -> V_26 ( V_16 ) ;
}
if ( V_19 -> V_59 ) {
F_28 ( V_16 , V_89 , V_90 , V_91 ) ;
}
V_19 -> V_92 = V_93 ;
V_19 -> V_58 = F_29 ( V_16 ) ;
V_54:
F_20 ( V_2 ) ;
}
static void F_30 ( struct V_15 * V_16 , struct V_1 * V_2 )
{
struct V_18 * V_19 = F_7 ( V_16 ) ;
unsigned short V_35 ;
if ( V_2 -> V_30 != 2 )
goto V_54;
V_35 = F_5 ( * ( T_1 * ) V_2 -> V_29 ) ;
V_16 -> V_60 = V_77 ;
switch ( V_19 -> V_55 ) {
case V_56 :
V_19 -> V_55 = V_94 ;
break;
case V_95 :
if ( V_35 == V_90 )
V_19 -> V_55 = V_96 ;
if ( V_35 == V_97 )
V_19 -> V_55 = V_98 ;
break;
case V_84 :
V_19 -> V_55 = V_85 ;
break;
case V_62 :
V_16 -> V_81 |= V_82 ;
case V_99 :
V_19 -> V_55 = V_98 ;
}
if ( ! F_10 ( V_16 , V_25 ) ) {
if ( V_16 -> V_86 -> V_55 != V_87 )
V_16 -> V_86 -> V_55 = V_88 ;
V_16 -> V_26 ( V_16 ) ;
}
V_19 -> V_92 = V_93 ;
V_19 -> V_58 = F_29 ( V_16 ) ;
V_54:
F_20 ( V_2 ) ;
}
static void F_31 ( struct V_15 * V_16 , struct V_1 * V_2 )
{
struct V_18 * V_19 = F_7 ( V_16 ) ;
unsigned short V_100 ;
unsigned char V_101 ;
signed char V_102 ;
int V_103 = 0 ;
char * V_28 = V_2 -> V_29 ;
unsigned char V_104 = V_19 -> V_63 & V_66 ;
if ( V_2 -> V_30 != 4 )
goto V_54;
V_100 = F_5 ( * ( T_1 * ) V_28 ) ;
V_28 += 2 ;
V_101 = * ( unsigned char * ) V_28 ++ ;
V_102 = * V_28 ;
if ( V_101 & 0xf8 )
goto V_54;
if ( F_32 ( V_19 -> V_105 , V_100 ) ) {
F_33 ( & V_19 -> V_105 , 1 ) ;
switch( V_101 & 0x04 ) {
case 0x00 :
switch( V_101 & 0x03 ) {
case 0x00 :
if ( V_102 < 0 ) {
unsigned char V_106 = - V_102 ;
if ( ( V_19 -> V_107 > V_106 ) &&
( V_104 == V_108 ) ) {
V_19 -> V_107 -= V_106 ;
}
} else if ( V_102 > 0 ) {
V_19 -> V_107 += V_102 ;
V_103 = 1 ;
}
break;
case 0x01 :
V_19 -> V_109 = V_110 ;
break;
case 0x02 :
V_19 -> V_109 = V_111 ;
F_34 ( V_16 ) ;
V_103 = 1 ;
}
break;
case 0x04 :
if ( V_102 > 0 ) {
V_19 -> V_112 += V_102 ;
V_103 = 1 ;
}
break;
}
if ( V_103 && ! F_10 ( V_16 , V_25 ) )
V_16 -> V_26 ( V_16 ) ;
}
F_35 ( V_16 ) ;
V_54:
F_20 ( V_2 ) ;
}
static T_3 int F_36 ( struct V_15 * V_16 , struct V_1 * V_2 , int V_113 , struct V_114 * V_115 )
{
int V_42 ;
int V_116 ;
if ( F_37 ( & V_16 -> V_117 ) + V_2 -> V_118 >=
( unsigned ) V_16 -> V_119 ) {
V_42 = - V_120 ;
goto V_54;
}
V_42 = F_38 ( V_16 , V_2 ) ;
if ( V_42 )
goto V_54;
V_116 = V_2 -> V_30 ;
F_39 ( V_2 , V_16 ) ;
F_21 ( V_115 , V_2 ) ;
if ( ! F_10 ( V_16 , V_25 ) )
V_16 -> V_121 ( V_16 , V_116 ) ;
V_54:
return V_42 ;
}
static void F_40 ( struct V_15 * V_16 , struct V_1 * V_2 )
{
struct V_18 * V_19 = F_7 ( V_16 ) ;
unsigned short V_100 ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
int V_122 = 0 ;
if ( V_2 -> V_30 < 2 )
goto V_54;
V_9 -> V_100 = V_100 = F_5 ( * ( T_1 * ) V_2 -> V_29 ) ;
F_12 ( V_2 , 2 ) ;
if ( F_32 ( V_19 -> V_105 , V_100 ) ) {
if ( F_36 ( V_16 , V_2 , V_123 , & V_19 -> V_124 ) == 0 ) {
F_33 ( & V_19 -> V_105 , 1 ) ;
V_19 -> V_125 = 0 ;
V_122 = 1 ;
}
}
F_35 ( V_16 ) ;
V_54:
if ( ! V_122 )
F_20 ( V_2 ) ;
}
static void F_41 ( struct V_15 * V_16 , struct V_1 * V_2 )
{
int V_122 = 0 ;
unsigned short V_100 ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_18 * V_19 = F_7 ( V_16 ) ;
if ( V_2 -> V_30 < 2 )
goto V_54;
V_9 -> V_100 = V_100 = F_5 ( * ( T_1 * ) V_2 -> V_29 ) ;
F_12 ( V_2 , 2 ) ;
if ( F_32 ( V_19 -> V_126 , V_100 ) ) {
if ( F_36 ( V_16 , V_2 , V_127 , & V_16 -> V_53 ) == 0 ) {
F_33 ( & V_19 -> V_126 , 1 ) ;
V_122 = 1 ;
}
if ( ( V_19 -> V_128 == V_111 ) && F_42 ( V_16 ) ) {
V_19 -> V_128 = V_110 ;
F_25 ( V_16 , V_110 , 0 ) ;
}
}
F_43 ( V_16 ) ;
V_54:
if ( ! V_122 )
F_20 ( V_2 ) ;
}
static void F_44 ( struct V_15 * V_16 , struct V_1 * V_2 )
{
struct V_18 * V_19 = F_7 ( V_16 ) ;
if ( V_19 -> V_55 == V_56 ) {
V_19 -> V_55 = V_129 ;
V_16 -> V_60 = V_77 ;
if ( ! F_10 ( V_16 , V_25 ) )
V_16 -> V_26 ( V_16 ) ;
}
F_20 ( V_2 ) ;
}
static int F_45 ( struct V_1 * V_2 , unsigned short V_35 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
int V_130 = V_131 ;
if ( V_9 -> V_132 & V_133 )
goto V_54;
if ( ( V_35 != V_134 ) && ( ( V_9 -> V_135 & 0x0c ) == 0x08 ) ) {
switch ( V_9 -> V_135 & 0x70 ) {
case 0x10 :
case 0x60 :
F_46 ( V_2 , V_136 , V_35 ) ;
V_130 = V_137 ;
break;
case 0x20 :
F_46 ( V_2 , V_89 , V_35 ) ;
V_130 = V_137 ;
break;
}
}
V_54:
F_20 ( V_2 ) ;
return V_130 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_15 * V_16 = NULL ;
unsigned char * V_28 = ( unsigned char * ) V_2 -> V_29 ;
unsigned short V_35 = V_97 ;
if ( ! F_15 ( V_2 , 2 ) )
goto V_138;
F_48 ( V_2 ) ;
V_9 -> V_135 = * V_28 ++ ;
if ( V_139 & 2 )
F_4 ( V_140 L_3 , ( int ) V_9 -> V_135 ) ;
if ( V_9 -> V_135 & 0x83 )
goto V_138;
if ( ( V_9 -> V_135 & 0x0c ) == 0x08 ) {
switch ( V_9 -> V_135 & 0x70 ) {
case 0x00 :
case 0x70 :
case 0x50 :
goto V_138;
case 0x10 :
case 0x60 :
if ( F_49 ( V_9 -> V_132 & V_133 ) )
goto V_138;
V_16 = F_14 ( V_2 , & V_35 ) ;
goto V_141;
}
}
if ( ! F_15 ( V_2 , 3 ) )
goto V_138;
V_9 -> V_14 = * ( T_1 * ) V_28 ;
V_9 -> V_13 = 0 ;
V_28 += 2 ;
if ( F_15 ( V_2 , 5 ) ) {
V_9 -> V_13 = * ( T_1 * ) V_28 ;
V_28 += 2 ;
F_12 ( V_2 , 5 ) ;
}
if ( F_49 ( V_9 -> V_132 & V_133 ) ) {
T_1 V_142 = V_9 -> V_14 ;
V_9 -> V_14 = V_9 -> V_13 ;
V_9 -> V_13 = V_142 ;
V_142 = V_9 -> V_12 ;
V_9 -> V_12 = V_9 -> V_11 ;
V_9 -> V_11 = V_142 ;
}
V_16 = F_50 ( V_2 ) ;
V_141:
if ( V_16 != NULL ) {
struct V_18 * V_19 = F_7 ( V_16 ) ;
V_19 -> V_143 = 0 ;
if ( V_9 -> V_135 & ~ 0x60 ) {
if ( F_49 ( F_51 ( V_2 ) ) )
goto V_138;
}
return F_52 ( V_16 , V_2 , 0 ) ;
}
return F_45 ( V_2 , V_35 ) ;
V_138:
F_20 ( V_2 ) ;
return V_131 ;
}
int F_53 ( struct V_1 * V_2 )
{
return F_54 ( V_144 , V_145 , V_2 , V_2 -> V_6 , NULL ,
F_47 ) ;
}
int F_55 ( struct V_15 * V_16 , struct V_1 * V_2 )
{
struct V_18 * V_19 = F_7 ( V_16 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
if ( V_9 -> V_132 & V_133 ) {
if ( V_9 -> V_135 == 0x18 || V_9 -> V_135 == 0x68 )
F_44 ( V_16 , V_2 ) ;
else
F_20 ( V_2 ) ;
return V_137 ;
}
if ( ( V_9 -> V_135 & 0x0c ) == 0x08 ) {
switch ( V_9 -> V_135 & 0x70 ) {
case 0x10 :
case 0x60 :
F_18 ( V_16 , V_2 ) ;
break;
case 0x20 :
F_22 ( V_16 , V_2 ) ;
break;
case 0x30 :
F_27 ( V_16 , V_2 ) ;
break;
case 0x40 :
F_30 ( V_16 , V_2 ) ;
break;
}
} else if ( V_9 -> V_135 == 0x24 ) {
F_26 ( V_16 , V_2 ) ;
} else {
int V_146 = 1 ;
if ( ( V_19 -> V_55 == V_99 ) && ! F_10 ( V_16 , V_25 ) ) {
V_19 -> V_55 = V_62 ;
V_16 -> V_60 = V_61 ;
V_16 -> V_26 ( V_16 ) ;
}
if ( ( V_9 -> V_135 & 0x1c ) == 0 )
V_146 = 0 ;
if ( V_9 -> V_135 == 0x04 )
V_146 = 0 ;
F_11 ( V_16 , V_2 , V_146 ) ;
if ( ( V_9 -> V_135 & 0x0c ) == 0 ) {
if ( V_19 -> V_55 != V_62 )
goto V_138;
switch ( V_9 -> V_135 ) {
case 0x10 :
F_31 ( V_16 , V_2 ) ;
break;
case 0x30 :
F_40 ( V_16 , V_2 ) ;
break;
default:
F_41 ( V_16 , V_2 ) ;
}
} else {
V_138:
F_20 ( V_2 ) ;
}
}
return V_137 ;
}
