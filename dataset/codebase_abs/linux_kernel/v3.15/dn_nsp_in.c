static void F_1 ( struct V_1 * V_2 , const char * V_3 )
{
if ( V_4 ) {
char * V_5 = V_2 -> V_6 ? V_2 -> V_6 -> V_7 : L_1 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_3 ( L_2 ,
V_3 , V_5 ,
F_4 ( V_9 -> V_10 ) ,
F_4 ( V_9 -> V_11 ) ,
F_4 ( V_9 -> V_12 ) ,
F_4 ( V_9 -> V_13 ) ) ;
}
}
static void F_5 ( struct V_14 * V_15 , struct V_1 * V_2 , unsigned short V_16 )
{
struct V_17 * V_18 = F_6 ( V_15 ) ;
unsigned short type = ( ( V_16 >> 12 ) & 0x0003 ) ;
int V_19 = 0 ;
switch ( type ) {
case 0 :
if ( F_7 ( V_16 , V_18 -> V_20 ) ) {
V_18 -> V_20 = V_16 & 0x0fff ;
V_19 |= F_8 ( V_15 , V_2 ,
& V_18 -> V_21 ,
V_16 ) ;
}
break;
case 1 :
break;
case 2 :
if ( F_7 ( V_16 , V_18 -> V_22 ) ) {
V_18 -> V_22 = V_16 & 0x0fff ;
V_19 |= F_8 ( V_15 , V_2 ,
& V_18 -> V_23 ,
V_16 ) ;
}
break;
case 3 :
break;
}
if ( V_19 && ! F_9 ( V_15 , V_24 ) )
V_15 -> V_25 ( V_15 ) ;
}
static int F_10 ( struct V_14 * V_15 , struct V_1 * V_2 , int V_26 )
{
T_1 * V_27 = ( T_1 * ) V_2 -> V_28 ;
int V_29 = 0 ;
unsigned short V_16 ;
if ( V_2 -> V_29 < 2 )
return V_29 ;
if ( ( V_16 = F_4 ( * V_27 ) ) & 0x8000 ) {
F_11 ( V_2 , 2 ) ;
V_27 ++ ;
V_29 += 2 ;
if ( ( V_16 & 0x4000 ) == 0 ) {
if ( V_26 )
V_16 ^= 0x2000 ;
F_5 ( V_15 , V_2 , V_16 ) ;
}
}
if ( V_2 -> V_29 < 2 )
return V_29 ;
if ( ( V_16 = F_4 ( * V_27 ) ) & 0x8000 ) {
F_11 ( V_2 , 2 ) ;
V_29 += 2 ;
if ( ( V_16 & 0x4000 ) == 0 ) {
if ( V_26 )
V_16 ^= 0x2000 ;
F_5 ( V_15 , V_2 , V_16 ) ;
}
}
return V_29 ;
}
static inline int F_12 ( unsigned char * * V_30 , int * V_29 , unsigned char V_31 , unsigned char V_32 )
{
unsigned char * V_27 = * V_30 ;
unsigned char V_33 = * V_27 ++ ;
( * V_29 ) -- ;
if ( V_33 > V_31 )
return - 1 ;
if ( ( V_33 + V_32 ) > * V_29 )
return - 1 ;
* V_29 -= V_33 ;
* V_30 = V_27 + V_33 ;
return 0 ;
}
static struct V_14 * F_13 ( struct V_1 * V_2 , unsigned short * V_34 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_35 * V_3 = (struct V_35 * ) V_2 -> V_28 ;
struct V_36 V_37 ;
struct V_36 V_38 ;
unsigned char type = 0 ;
int V_39 ;
int V_40 ;
unsigned char * V_27 ;
int V_29 ;
int V_41 = 0 ;
unsigned char V_42 ;
memset ( & V_37 , 0 , sizeof( struct V_36 ) ) ;
memset ( & V_38 , 0 , sizeof( struct V_36 ) ) ;
V_9 -> V_12 = V_3 -> V_38 ;
V_9 -> V_13 = V_3 -> V_37 ;
V_9 -> V_43 = V_3 -> V_43 ;
V_9 -> V_44 = V_3 -> V_44 ;
V_9 -> V_45 = F_4 ( V_3 -> V_45 ) ;
if ( ! F_14 ( V_2 , sizeof( * V_3 ) ) )
goto V_46;
F_11 ( V_2 , sizeof( * V_3 ) ) ;
V_29 = V_2 -> V_29 ;
V_27 = V_2 -> V_28 ;
V_39 = F_15 ( V_27 , V_29 , & V_37 , & type ) ;
V_41 ++ ;
if ( V_39 < 0 )
goto V_46;
V_41 ++ ;
if ( type > 1 )
goto V_46;
V_29 -= V_39 ;
V_27 += V_39 ;
V_40 = F_15 ( V_27 , V_29 , & V_38 , & type ) ;
V_41 ++ ;
if ( V_40 < 0 )
goto V_46;
V_29 -= V_40 ;
V_27 += V_40 ;
V_41 ++ ;
if ( V_29 < 1 )
goto V_46;
V_42 = * V_27 ;
V_27 ++ ;
V_29 -- ;
V_41 ++ ;
if ( ( V_42 & ( V_47 | V_48 ) ) && ( V_29 < 1 ) )
goto V_46;
V_41 ++ ;
if ( V_42 & V_47 ) {
if ( F_12 ( & V_27 , & V_29 , 39 , 1 ) )
goto V_46;
if ( F_12 ( & V_27 , & V_29 , 39 , 1 ) )
goto V_46;
if ( F_12 ( & V_27 , & V_29 , 39 , ( V_42 & V_48 ) ? 1 : 0 ) )
goto V_46;
}
V_41 ++ ;
if ( V_42 & V_48 ) {
if ( F_12 ( & V_27 , & V_29 , 16 , 0 ) )
goto V_46;
}
return F_16 ( & V_37 ) ;
V_46:
F_1 ( V_2 , V_49 [ V_41 ] . V_50 ) ;
* V_34 = V_49 [ V_41 ] . V_34 ;
return NULL ;
}
static void F_17 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
if ( F_18 ( V_15 ) ) {
F_19 ( V_2 ) ;
return;
}
V_15 -> V_51 ++ ;
F_20 ( & V_15 -> V_52 , V_2 ) ;
V_15 -> V_25 ( V_15 ) ;
}
static void F_21 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_17 * V_18 = F_6 ( V_15 ) ;
unsigned char * V_27 ;
if ( V_2 -> V_29 < 4 )
goto V_53;
V_27 = V_2 -> V_28 ;
V_9 -> V_43 = * V_27 ++ ;
V_9 -> V_44 = * V_27 ++ ;
V_9 -> V_45 = F_4 ( * ( T_1 * ) V_27 ) ;
if ( ( V_18 -> V_54 == V_55 ) || ( V_18 -> V_54 == V_56 ) ) {
V_18 -> V_57 = 0 ;
V_18 -> V_58 = V_9 -> V_12 ;
V_15 -> V_59 = V_60 ;
V_18 -> V_54 = V_61 ;
V_18 -> V_62 = V_9 -> V_43 ;
V_18 -> V_63 = V_9 -> V_44 ;
V_18 -> V_64 = V_9 -> V_45 ;
if ( ( V_18 -> V_62 & V_65 ) == V_66 )
V_18 -> V_67 = V_68 ;
if ( V_2 -> V_29 > 0 ) {
T_2 V_69 = * V_2 -> V_28 ;
if ( ( V_69 <= 16 ) && ( V_69 <= V_2 -> V_29 ) ) {
V_18 -> V_70 . V_71 = F_22 ( V_69 ) ;
F_23 ( V_2 , 1 ,
V_18 -> V_70 . V_72 , V_69 ) ;
}
}
F_24 ( V_15 , V_73 , 0 ) ;
if ( ! F_9 ( V_15 , V_24 ) )
V_15 -> V_25 ( V_15 ) ;
}
V_53:
F_19 ( V_2 ) ;
}
static void F_25 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
struct V_17 * V_18 = F_6 ( V_15 ) ;
if ( V_18 -> V_54 == V_55 ) {
V_18 -> V_54 = V_56 ;
V_18 -> V_57 = 0 ;
}
F_19 ( V_2 ) ;
}
static void F_26 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
struct V_17 * V_18 = F_6 ( V_15 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned short V_34 ;
if ( V_2 -> V_29 < 2 )
goto V_53;
V_34 = F_4 ( * ( T_1 * ) V_2 -> V_28 ) ;
F_11 ( V_2 , 2 ) ;
V_18 -> V_74 . V_75 = F_22 ( V_34 ) ;
V_18 -> V_74 . V_71 = 0 ;
memset ( V_18 -> V_74 . V_72 , 0 , 16 ) ;
if ( V_2 -> V_29 > 0 ) {
T_2 V_69 = * V_2 -> V_28 ;
if ( ( V_69 <= 16 ) && ( V_69 <= V_2 -> V_29 ) ) {
V_18 -> V_74 . V_71 = F_22 ( V_69 ) ;
F_23 ( V_2 , 1 , V_18 -> V_74 . V_72 , V_69 ) ;
}
}
V_18 -> V_58 = V_9 -> V_12 ;
V_15 -> V_59 = V_76 ;
switch ( V_18 -> V_54 ) {
case V_55 :
case V_56 :
V_18 -> V_54 = V_77 ;
V_15 -> V_78 = V_79 ;
break;
case V_61 :
V_15 -> V_80 |= V_81 ;
V_18 -> V_54 = V_82 ;
break;
case V_83 :
V_18 -> V_54 = V_84 ;
break;
}
if ( ! F_9 ( V_15 , V_24 ) ) {
if ( V_15 -> V_85 -> V_54 != V_86 )
V_15 -> V_85 -> V_54 = V_87 ;
V_15 -> V_25 ( V_15 ) ;
}
if ( V_18 -> V_58 ) {
F_27 ( V_15 , V_88 , V_89 , V_90 ) ;
}
V_18 -> V_91 = V_92 ;
V_18 -> V_57 = F_28 ( V_15 ) ;
V_53:
F_19 ( V_2 ) ;
}
static void F_29 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
struct V_17 * V_18 = F_6 ( V_15 ) ;
unsigned short V_34 ;
if ( V_2 -> V_29 != 2 )
goto V_53;
V_34 = F_4 ( * ( T_1 * ) V_2 -> V_28 ) ;
V_15 -> V_59 = V_76 ;
switch ( V_18 -> V_54 ) {
case V_55 :
V_18 -> V_54 = V_93 ;
break;
case V_94 :
if ( V_34 == V_89 )
V_18 -> V_54 = V_95 ;
if ( V_34 == V_96 )
V_18 -> V_54 = V_97 ;
break;
case V_83 :
V_18 -> V_54 = V_84 ;
break;
case V_61 :
V_15 -> V_80 |= V_81 ;
case V_98 :
V_18 -> V_54 = V_97 ;
}
if ( ! F_9 ( V_15 , V_24 ) ) {
if ( V_15 -> V_85 -> V_54 != V_86 )
V_15 -> V_85 -> V_54 = V_87 ;
V_15 -> V_25 ( V_15 ) ;
}
V_18 -> V_91 = V_92 ;
V_18 -> V_57 = F_28 ( V_15 ) ;
V_53:
F_19 ( V_2 ) ;
}
static void F_30 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
struct V_17 * V_18 = F_6 ( V_15 ) ;
unsigned short V_99 ;
unsigned char V_100 ;
signed char V_101 ;
int V_102 = 0 ;
char * V_27 = V_2 -> V_28 ;
unsigned char V_103 = V_18 -> V_62 & V_65 ;
if ( V_2 -> V_29 != 4 )
goto V_53;
V_99 = F_4 ( * ( T_1 * ) V_27 ) ;
V_27 += 2 ;
V_100 = * ( unsigned char * ) V_27 ++ ;
V_101 = * V_27 ;
if ( V_100 & 0xf8 )
goto V_53;
if ( F_31 ( V_18 -> V_104 , V_99 ) ) {
F_32 ( & V_18 -> V_104 , 1 ) ;
switch( V_100 & 0x04 ) {
case 0x00 :
switch( V_100 & 0x03 ) {
case 0x00 :
if ( V_101 < 0 ) {
unsigned char V_105 = - V_101 ;
if ( ( V_18 -> V_106 > V_105 ) &&
( V_103 == V_107 ) ) {
V_18 -> V_106 -= V_105 ;
}
} else if ( V_101 > 0 ) {
V_18 -> V_106 += V_101 ;
V_102 = 1 ;
}
break;
case 0x01 :
V_18 -> V_108 = V_109 ;
break;
case 0x02 :
V_18 -> V_108 = V_110 ;
F_33 ( V_15 ) ;
V_102 = 1 ;
}
break;
case 0x04 :
if ( V_101 > 0 ) {
V_18 -> V_111 += V_101 ;
V_102 = 1 ;
}
break;
}
if ( V_102 && ! F_9 ( V_15 , V_24 ) )
V_15 -> V_25 ( V_15 ) ;
}
F_34 ( V_15 ) ;
V_53:
F_19 ( V_2 ) ;
}
static T_3 int F_35 ( struct V_14 * V_15 , struct V_1 * V_2 , int V_112 , struct V_113 * V_114 )
{
int V_41 ;
if ( F_36 ( & V_15 -> V_115 ) + V_2 -> V_116 >=
( unsigned int ) V_15 -> V_117 ) {
V_41 = - V_118 ;
goto V_53;
}
V_41 = F_37 ( V_15 , V_2 ) ;
if ( V_41 )
goto V_53;
F_38 ( V_2 , V_15 ) ;
F_20 ( V_114 , V_2 ) ;
if ( ! F_9 ( V_15 , V_24 ) )
V_15 -> V_119 ( V_15 ) ;
V_53:
return V_41 ;
}
static void F_39 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
struct V_17 * V_18 = F_6 ( V_15 ) ;
unsigned short V_99 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_120 = 0 ;
if ( V_2 -> V_29 < 2 )
goto V_53;
V_9 -> V_99 = V_99 = F_4 ( * ( T_1 * ) V_2 -> V_28 ) ;
F_11 ( V_2 , 2 ) ;
if ( F_31 ( V_18 -> V_104 , V_99 ) ) {
if ( F_35 ( V_15 , V_2 , V_121 , & V_18 -> V_122 ) == 0 ) {
F_32 ( & V_18 -> V_104 , 1 ) ;
V_18 -> V_123 = 0 ;
V_120 = 1 ;
}
}
F_34 ( V_15 ) ;
V_53:
if ( ! V_120 )
F_19 ( V_2 ) ;
}
static void F_40 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
int V_120 = 0 ;
unsigned short V_99 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_17 * V_18 = F_6 ( V_15 ) ;
if ( V_2 -> V_29 < 2 )
goto V_53;
V_9 -> V_99 = V_99 = F_4 ( * ( T_1 * ) V_2 -> V_28 ) ;
F_11 ( V_2 , 2 ) ;
if ( F_31 ( V_18 -> V_124 , V_99 ) ) {
if ( F_35 ( V_15 , V_2 , V_125 , & V_15 -> V_52 ) == 0 ) {
F_32 ( & V_18 -> V_124 , 1 ) ;
V_120 = 1 ;
}
if ( ( V_18 -> V_126 == V_110 ) && F_41 ( V_15 ) ) {
V_18 -> V_126 = V_109 ;
F_24 ( V_15 , V_109 , 0 ) ;
}
}
F_42 ( V_15 ) ;
V_53:
if ( ! V_120 )
F_19 ( V_2 ) ;
}
static void F_43 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
struct V_17 * V_18 = F_6 ( V_15 ) ;
if ( V_18 -> V_54 == V_55 ) {
V_18 -> V_54 = V_127 ;
V_15 -> V_59 = V_76 ;
if ( ! F_9 ( V_15 , V_24 ) )
V_15 -> V_25 ( V_15 ) ;
}
F_19 ( V_2 ) ;
}
static int F_44 ( struct V_1 * V_2 , unsigned short V_34 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_128 = V_129 ;
if ( V_9 -> V_130 & V_131 )
goto V_53;
if ( ( V_34 != V_132 ) && ( ( V_9 -> V_133 & 0x0c ) == 0x08 ) ) {
switch ( V_9 -> V_133 & 0x70 ) {
case 0x10 :
case 0x60 :
F_45 ( V_2 , V_134 , V_34 ) ;
V_128 = V_135 ;
break;
case 0x20 :
F_45 ( V_2 , V_88 , V_34 ) ;
V_128 = V_135 ;
break;
}
}
V_53:
F_19 ( V_2 ) ;
return V_128 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_14 * V_15 = NULL ;
unsigned char * V_27 = ( unsigned char * ) V_2 -> V_28 ;
unsigned short V_34 = V_96 ;
if ( ! F_14 ( V_2 , 2 ) )
goto V_136;
F_47 ( V_2 ) ;
V_9 -> V_133 = * V_27 ++ ;
if ( V_137 & 2 )
F_48 ( V_138 L_3 , ( int ) V_9 -> V_133 ) ;
if ( V_9 -> V_133 & 0x83 )
goto V_136;
if ( ( V_9 -> V_133 & 0x0c ) == 0x08 ) {
switch ( V_9 -> V_133 & 0x70 ) {
case 0x00 :
case 0x70 :
case 0x50 :
goto V_136;
case 0x10 :
case 0x60 :
if ( F_49 ( V_9 -> V_130 & V_131 ) )
goto V_136;
V_15 = F_13 ( V_2 , & V_34 ) ;
goto V_139;
}
}
if ( ! F_14 ( V_2 , 3 ) )
goto V_136;
V_9 -> V_13 = * ( T_1 * ) V_27 ;
V_9 -> V_12 = 0 ;
V_27 += 2 ;
if ( F_14 ( V_2 , 5 ) ) {
V_9 -> V_12 = * ( T_1 * ) V_27 ;
V_27 += 2 ;
F_11 ( V_2 , 5 ) ;
}
if ( F_49 ( V_9 -> V_130 & V_131 ) ) {
T_1 V_140 = V_9 -> V_13 ;
V_9 -> V_13 = V_9 -> V_12 ;
V_9 -> V_12 = V_140 ;
V_140 = V_9 -> V_11 ;
V_9 -> V_11 = V_9 -> V_10 ;
V_9 -> V_10 = V_140 ;
}
V_15 = F_50 ( V_2 ) ;
V_139:
if ( V_15 != NULL ) {
struct V_17 * V_18 = F_6 ( V_15 ) ;
V_18 -> V_141 = 0 ;
if ( V_9 -> V_133 & ~ 0x60 ) {
if ( F_49 ( F_51 ( V_2 ) ) )
goto V_136;
}
return F_52 ( V_15 , V_2 , 0 ) ;
}
return F_44 ( V_2 , V_34 ) ;
V_136:
F_19 ( V_2 ) ;
return V_129 ;
}
int F_53 ( struct V_1 * V_2 )
{
return F_54 ( V_142 , V_143 , V_2 , V_2 -> V_6 , NULL ,
F_46 ) ;
}
int F_55 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
struct V_17 * V_18 = F_6 ( V_15 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_130 & V_131 ) {
if ( V_9 -> V_133 == 0x18 || V_9 -> V_133 == 0x68 )
F_43 ( V_15 , V_2 ) ;
else
F_19 ( V_2 ) ;
return V_135 ;
}
if ( ( V_9 -> V_133 & 0x0c ) == 0x08 ) {
switch ( V_9 -> V_133 & 0x70 ) {
case 0x10 :
case 0x60 :
F_17 ( V_15 , V_2 ) ;
break;
case 0x20 :
F_21 ( V_15 , V_2 ) ;
break;
case 0x30 :
F_26 ( V_15 , V_2 ) ;
break;
case 0x40 :
F_29 ( V_15 , V_2 ) ;
break;
}
} else if ( V_9 -> V_133 == 0x24 ) {
F_25 ( V_15 , V_2 ) ;
} else {
int V_144 = 1 ;
if ( ( V_18 -> V_54 == V_98 ) && ! F_9 ( V_15 , V_24 ) ) {
V_18 -> V_54 = V_61 ;
V_15 -> V_59 = V_60 ;
V_15 -> V_25 ( V_15 ) ;
}
if ( ( V_9 -> V_133 & 0x1c ) == 0 )
V_144 = 0 ;
if ( V_9 -> V_133 == 0x04 )
V_144 = 0 ;
F_10 ( V_15 , V_2 , V_144 ) ;
if ( ( V_9 -> V_133 & 0x0c ) == 0 ) {
if ( V_18 -> V_54 != V_61 )
goto V_136;
switch ( V_9 -> V_133 ) {
case 0x10 :
F_30 ( V_15 , V_2 ) ;
break;
case 0x30 :
F_39 ( V_15 , V_2 ) ;
break;
default:
F_40 ( V_15 , V_2 ) ;
}
} else {
V_136:
F_19 ( V_2 ) ;
}
}
return V_135 ;
}
