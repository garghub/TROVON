static inline int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 ) ;
}
static int
F_3 ( struct V_1 * V_2 , unsigned V_4 )
{
int V_5 ;
if ( V_4 > sizeof( * V_2 -> V_6 ) ) {
F_4 ( 1 ) ;
return - V_7 ;
}
V_2 -> V_5 . V_4 = V_4 ;
if ( V_2 -> V_8 )
F_5 ( V_2 -> V_8 ,
V_2 -> V_9 , sizeof( * V_2 -> V_6 ) ,
V_10 ) ;
V_5 = F_6 ( V_2 -> V_3 , & V_2 -> V_11 ) ;
if ( V_2 -> V_8 )
F_7 ( V_2 -> V_8 ,
V_2 -> V_9 , sizeof( * V_2 -> V_6 ) ,
V_10 ) ;
return V_5 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned long V_12 ,
unsigned V_13 , T_1 V_14 )
{
T_1 * V_15 = V_2 -> V_6 -> V_5 ;
unsigned long V_16 = V_17 ;
while ( 1 ) {
int V_5 ;
unsigned V_18 ;
V_5 = F_3 ( V_2 , V_13 ) ;
if ( V_5 < 0 )
return V_5 ;
for ( V_18 = 0 ; V_18 < V_13 ; V_18 ++ ) {
if ( V_15 [ V_18 ] != V_14 )
return V_15 [ V_18 ] ;
}
if ( F_9 ( V_16 + V_12 ) )
break;
if ( F_9 ( V_16 + 1 ) )
F_10 () ;
}
return - V_19 ;
}
static inline int
F_11 ( struct V_1 * V_2 , unsigned long V_12 )
{
return F_8 ( V_2 , V_12 , sizeof( V_2 -> V_6 -> V_5 ) , 0 ) ;
}
static int F_12 ( struct V_1 * V_2 , unsigned long V_12 )
{
return F_8 ( V_2 , V_12 , 1 , 0xff ) ;
}
static char * F_13 ( struct V_20 * V_21 )
{
switch ( F_14 ( V_21 ) ) {
case V_22 : return L_1 ;
case V_23 : return L_2 ;
case V_24 : return L_3 ;
case V_25 : return L_4 ;
default: return L_5 ;
}
}
static int F_15 ( struct V_1 * V_2 ,
struct V_20 * V_21 , int V_26 )
{
T_1 * V_15 = V_2 -> V_6 -> V_5 ;
T_1 * V_27 = V_15 + V_2 -> V_28 . V_4 ;
int V_29 = 0 ;
int V_30 ;
T_1 V_31 = 0 ;
unsigned short V_32 ;
int V_18 ;
char V_33 [ 32 ] ;
snprintf ( V_33 , sizeof( V_33 ) , L_6 ,
V_21 -> V_34 , F_13 ( V_21 ) ) ;
V_15 += 8 ;
while ( V_15 < V_27 && * V_15 == 0xff )
V_15 ++ ;
if ( V_15 == V_27 ) {
V_15 = V_2 -> V_6 -> V_5 ;
V_27 = V_15 + 1 ;
for ( V_18 = 2 ; V_18 < 16 ; V_18 ++ ) {
V_29 = F_3 ( V_2 , 1 ) ;
if ( V_29 < 0 )
goto V_35;
if ( * V_15 != 0xff )
goto V_36;
}
V_29 = - V_19 ;
goto V_35;
}
V_36:
V_30 = 0 ;
if ( * V_15 & 0x80 ) {
V_32 = * V_15 ++ << 8 ;
if ( V_15 == V_27 ) {
V_29 = F_3 ( V_2 , 1 ) ;
if ( V_29 < 0 )
goto V_35;
V_15 = V_2 -> V_6 -> V_5 ;
V_27 = V_15 + 1 ;
}
V_32 |= * V_15 ++ ;
while ( V_32 & 0x8000 ) {
V_30 ++ ;
V_32 <<= 1 ;
}
V_21 -> V_37 [ 0 ] = V_32 >> 8 ;
V_31 = V_32 ;
} else {
V_21 -> V_37 [ 0 ] = * V_15 ++ ;
}
V_21 -> error = 0 ;
if ( V_21 -> V_37 [ 0 ] != 0 ) {
if ( ( V_38 | V_39 )
& V_21 -> V_37 [ 0 ] )
V_29 = - V_40 ;
else if ( V_41 & V_21 -> V_37 [ 0 ] )
V_29 = - V_42 ;
else if ( V_43 & V_21 -> V_37 [ 0 ] )
V_29 = - V_44 ;
else if ( ( V_45 | V_46 )
& V_21 -> V_37 [ 0 ] )
V_29 = - V_7 ;
}
switch ( F_14 ( V_21 ) ) {
case V_23 :
while ( V_15 < V_27 && * V_15 == 0 )
V_15 ++ ;
if ( V_15 == V_27 )
F_11 ( V_2 , V_47 ) ;
break;
case V_24 :
if ( V_15 == V_27 ) {
V_29 = F_3 ( V_2 , 1 ) ;
if ( V_29 < 0 )
goto V_35;
V_15 = V_2 -> V_6 -> V_5 ;
V_27 = V_15 + 1 ;
}
if ( V_30 ) {
V_32 = V_31 << 8 ;
V_32 |= * V_15 << V_30 ;
V_21 -> V_37 [ 0 ] |= ( V_32 & 0xFF00 ) ;
} else {
V_21 -> V_37 [ 0 ] |= * V_15 << 8 ;
}
break;
case V_25 :
V_32 = V_31 << 8 ;
V_21 -> V_37 [ 1 ] = 0 ;
for ( V_18 = 0 ; V_18 < 4 ; V_18 ++ ) {
V_21 -> V_37 [ 1 ] <<= 8 ;
if ( V_15 == V_27 ) {
V_29 = F_3 ( V_2 , 1 ) ;
if ( V_29 < 0 )
goto V_35;
V_15 = V_2 -> V_6 -> V_5 ;
V_27 = V_15 + 1 ;
}
if ( V_30 ) {
V_32 |= * V_15 ++ << V_30 ;
V_21 -> V_37 [ 1 ] |= ( V_32 >> 8 ) ;
V_32 <<= 8 ;
} else {
V_21 -> V_37 [ 1 ] |= * V_15 ++ ;
}
}
break;
case V_22 :
break;
default:
F_16 ( & V_2 -> V_3 -> V_48 , L_7 ,
F_14 ( V_21 ) ) ;
if ( V_29 >= 0 )
V_29 = - V_49 ;
goto V_35;
}
if ( V_29 < 0 )
F_16 ( & V_2 -> V_3 -> V_48 , L_8 ,
V_33 , V_21 -> V_37 [ 0 ] , V_21 -> V_37 [ 1 ] ) ;
if ( V_29 >= 0 && V_26 )
return V_29 ;
V_35:
if ( V_29 < 0 )
V_21 -> error = V_29 ;
F_1 ( V_2 ) ;
return V_29 ;
}
static int
F_17 ( struct V_1 * V_2 ,
struct V_50 * V_51 ,
struct V_20 * V_21 , int V_26 )
{
struct V_52 * V_6 = V_2 -> V_6 ;
T_1 * V_15 = V_6 -> V_5 ;
int V_5 ;
struct V_53 * V_28 ;
memset ( V_15 , 0xff , sizeof( V_6 -> V_5 ) ) ;
V_15 [ 1 ] = 0x40 | V_21 -> V_34 ;
F_18 ( V_21 -> V_54 , V_15 + 2 ) ;
V_15 [ 6 ] = F_19 ( 0 , V_15 + 1 , 5 ) | 0x01 ;
V_15 += 7 ;
if ( V_26 && ( V_51 -> V_6 -> V_55 & V_56 ) ) {
V_15 += 2 ;
} else {
V_15 += 10 ;
if ( V_21 -> V_55 & V_57 )
V_15 ++ ;
else if ( V_21 -> V_55 & V_58 )
V_15 += 4 ;
else if ( V_21 -> V_55 & V_59 )
V_15 = V_6 -> V_5 + sizeof( V_6 -> V_5 ) ;
}
F_16 ( & V_2 -> V_3 -> V_48 , L_9 ,
V_21 -> V_34 , F_13 ( V_21 ) ) ;
F_20 ( & V_2 -> V_60 ) ;
V_28 = & V_2 -> V_28 ;
memset ( V_28 , 0 , sizeof( * V_28 ) ) ;
V_28 -> V_61 = V_28 -> V_62 = V_6 -> V_5 ;
V_28 -> V_63 = V_28 -> V_64 = V_2 -> V_9 ;
V_28 -> V_4 = V_15 - V_6 -> V_5 ;
V_28 -> V_65 = 1 ;
F_21 ( V_28 , & V_2 -> V_60 ) ;
if ( V_2 -> V_8 ) {
V_2 -> V_60 . V_66 = 1 ;
F_5 ( V_2 -> V_8 ,
V_2 -> V_9 , sizeof( * V_2 -> V_6 ) ,
V_67 ) ;
}
V_5 = F_6 ( V_2 -> V_3 , & V_2 -> V_60 ) ;
if ( V_2 -> V_8 )
F_7 ( V_2 -> V_8 ,
V_2 -> V_9 , sizeof( * V_2 -> V_6 ) ,
V_67 ) ;
if ( V_5 < 0 ) {
F_16 ( & V_2 -> V_3 -> V_48 , L_10 , V_5 ) ;
V_21 -> error = V_5 ;
return V_5 ;
}
return F_15 ( V_2 , V_21 , V_26 ) ;
}
static void
F_22 (
struct V_1 * V_2 ,
int V_68 ,
enum V_69 V_70 )
{
struct V_53 * V_28 ;
struct V_52 * V_52 = V_2 -> V_6 ;
T_2 V_71 = V_2 -> V_9 ;
F_20 ( & V_2 -> V_60 ) ;
if ( V_71 )
V_2 -> V_60 . V_66 = 1 ;
if ( V_70 == V_72 ) {
V_28 = & V_2 -> V_73 ;
memset ( V_28 , 0 , sizeof( * V_28 ) ) ;
V_28 -> V_4 = 1 ;
if ( V_68 )
V_52 -> V_74 = V_75 ;
else
V_52 -> V_74 = V_76 ;
V_28 -> V_61 = & V_52 -> V_74 ;
if ( V_71 )
V_28 -> V_63 = V_71 + F_23 ( struct V_52 , V_74 ) ;
F_21 ( V_28 , & V_2 -> V_60 ) ;
}
V_28 = & V_2 -> V_28 ;
memset ( V_28 , 0 , sizeof( * V_28 ) ) ;
V_28 -> V_61 = V_2 -> V_77 ;
V_28 -> V_63 = V_2 -> V_78 ;
F_21 ( V_28 , & V_2 -> V_60 ) ;
V_28 = & V_2 -> V_79 ;
memset ( V_28 , 0 , sizeof( * V_28 ) ) ;
V_28 -> V_4 = 2 ;
if ( V_70 == V_72 ) {
V_28 -> V_61 = & V_52 -> V_80 ;
if ( V_71 )
V_28 -> V_63 = V_71 + F_23 ( struct V_52 , V_80 ) ;
} else {
V_28 -> V_61 = V_2 -> V_77 ;
V_28 -> V_63 = V_2 -> V_78 ;
V_28 -> V_62 = & V_52 -> V_80 ;
if ( V_71 )
V_28 -> V_64 = V_71 + F_23 ( struct V_52 , V_80 ) ;
}
F_21 ( V_28 , & V_2 -> V_60 ) ;
if ( V_68 || V_70 == V_72 ) {
V_28 = & V_2 -> V_81 ;
memset ( V_28 , 0 , sizeof( * V_28 ) ) ;
V_28 -> V_4 = ( V_70 == V_72 )
? sizeof( V_52 -> V_5 )
: 1 ;
V_28 -> V_61 = V_2 -> V_77 ;
V_28 -> V_63 = V_2 -> V_78 ;
V_28 -> V_62 = V_52 -> V_5 ;
if ( V_71 )
V_28 -> V_64 = V_71 + F_23 ( struct V_52 , V_5 ) ;
V_28 -> V_65 = 1 ;
F_21 ( V_28 , & V_2 -> V_60 ) ;
}
}
static int
F_24 ( struct V_1 * V_2 , struct V_53 * V_28 ,
unsigned long V_12 )
{
struct V_82 * V_3 = V_2 -> V_3 ;
int V_5 , V_18 ;
struct V_52 * V_52 = V_2 -> V_6 ;
T_3 V_83 ;
if ( V_2 -> V_84 -> V_85 )
V_52 -> V_80 = F_25 (
F_26 ( 0 , V_28 -> V_61 , V_28 -> V_4 ) ) ;
if ( V_2 -> V_8 )
F_5 ( V_2 -> V_8 ,
V_2 -> V_9 , sizeof( * V_52 ) ,
V_67 ) ;
V_5 = F_6 ( V_3 , & V_2 -> V_60 ) ;
if ( V_5 != 0 ) {
F_16 ( & V_3 -> V_48 , L_11 , V_5 ) ;
return V_5 ;
}
if ( V_2 -> V_8 )
F_7 ( V_2 -> V_8 ,
V_2 -> V_9 , sizeof( * V_52 ) ,
V_67 ) ;
V_83 = F_27 ( V_52 -> V_5 ) ;
V_83 |= 0xE0000000 ;
while ( V_83 & 0x80000000 )
V_83 <<= 1 ;
V_83 >>= 27 ;
switch ( V_83 ) {
case V_86 :
V_5 = 0 ;
break;
case V_87 :
V_5 = - V_44 ;
break;
case V_88 :
V_5 = - V_7 ;
break;
default:
V_5 = - V_89 ;
break;
}
if ( V_5 != 0 ) {
F_16 ( & V_3 -> V_48 , L_12 ,
V_52 -> V_5 [ 0 ] , V_5 ) ;
return V_5 ;
}
V_28 -> V_61 += V_28 -> V_4 ;
if ( V_2 -> V_8 )
V_28 -> V_63 += V_28 -> V_4 ;
for ( V_18 = 4 ; V_18 < sizeof( V_52 -> V_5 ) ; V_18 ++ ) {
if ( V_52 -> V_5 [ V_18 ] & 0x01 )
return 0 ;
}
return F_11 ( V_2 , V_12 ) ;
}
static int
F_28 ( struct V_1 * V_2 , struct V_53 * V_28 ,
unsigned long V_12 )
{
struct V_82 * V_3 = V_2 -> V_3 ;
int V_5 ;
struct V_52 * V_52 = V_2 -> V_6 ;
unsigned int V_30 ;
T_1 V_31 ;
V_5 = F_3 ( V_2 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = V_52 -> V_5 [ 0 ] ;
if ( V_5 == 0xff || V_5 == 0 )
V_5 = F_12 ( V_2 , V_12 ) ;
if ( V_5 < 0 ) {
F_16 ( & V_3 -> V_48 , L_13 , V_5 , V_5 ) ;
return V_5 ;
}
V_30 = 7 ;
while ( V_5 & 0x80 ) {
V_5 <<= 1 ;
V_30 -- ;
}
V_31 = V_5 << 1 ;
if ( V_2 -> V_8 ) {
F_5 ( V_2 -> V_8 ,
V_2 -> V_9 , sizeof( * V_52 ) ,
V_67 ) ;
F_5 ( V_2 -> V_8 ,
V_28 -> V_64 , V_28 -> V_4 ,
V_10 ) ;
}
V_5 = F_6 ( V_3 , & V_2 -> V_60 ) ;
if ( V_2 -> V_8 ) {
F_7 ( V_2 -> V_8 ,
V_2 -> V_9 , sizeof( * V_52 ) ,
V_67 ) ;
F_7 ( V_2 -> V_8 ,
V_28 -> V_64 , V_28 -> V_4 ,
V_10 ) ;
}
if ( V_30 ) {
T_1 * V_15 = V_28 -> V_62 ;
unsigned int V_4 ;
unsigned int V_90 = 8 - V_30 ;
T_1 V_91 ;
for ( V_4 = V_28 -> V_4 ; V_4 ; V_4 -- ) {
V_91 = * V_15 ;
* V_15 ++ = V_31 | ( V_91 >> V_30 ) ;
V_31 = V_91 << V_90 ;
}
V_15 = ( T_1 * ) & V_52 -> V_80 ;
V_91 = * V_15 ;
* V_15 ++ = V_31 | ( V_91 >> V_30 ) ;
V_31 = V_91 << V_90 ;
V_91 = * V_15 ;
* V_15 = V_31 | ( V_91 >> V_30 ) ;
}
if ( V_2 -> V_84 -> V_85 ) {
T_4 V_79 = F_26 ( 0 , V_28 -> V_62 , V_28 -> V_4 ) ;
F_29 ( & V_52 -> V_80 ) ;
if ( V_52 -> V_80 != V_79 ) {
F_16 ( & V_3 -> V_48 , L_14
L_15 ,
V_52 -> V_80 , V_79 , V_28 -> V_4 ) ;
return - V_44 ;
}
}
V_28 -> V_62 += V_28 -> V_4 ;
if ( V_2 -> V_8 )
V_28 -> V_64 += V_28 -> V_4 ;
return 0 ;
}
static void
F_30 ( struct V_1 * V_2 , struct V_20 * V_21 ,
struct V_92 * V_6 , T_3 V_93 )
{
struct V_82 * V_3 = V_2 -> V_3 ;
struct V_94 * V_8 = V_2 -> V_8 ;
struct V_53 * V_28 ;
enum V_69 V_70 ;
struct V_95 * V_96 ;
unsigned V_97 ;
int V_68 = ( V_6 -> V_98 > 1 ) ;
T_3 V_99 ;
unsigned long V_12 ;
if ( V_6 -> V_55 & V_56 )
V_70 = V_10 ;
else
V_70 = V_72 ;
F_22 ( V_2 , V_68 , V_70 ) ;
V_28 = & V_2 -> V_28 ;
if ( V_28 -> V_100 )
V_99 = V_28 -> V_100 ;
else
V_99 = V_3 -> V_101 ;
V_12 = V_6 -> V_102 +
V_6 -> V_103 * 1000000 / V_99 ;
V_12 = F_31 ( ( unsigned int ) ( V_12 / 1000 ) ) + 1 ;
for ( V_96 = V_6 -> V_96 , V_97 = V_6 -> V_104 ; V_97 ; V_97 -- , V_96 ++ ) {
int V_5 = 0 ;
T_2 V_105 = 0 ;
void * V_106 ;
unsigned V_107 = V_96 -> V_107 ;
enum V_69 V_108 = V_70 ;
if ( V_8 ) {
if ( ( V_96 -> V_109 != 0 || V_107 != V_110 )
&& V_108 == V_10 )
V_108 = V_67 ;
V_105 = F_32 ( V_8 , F_33 ( V_96 ) , 0 ,
V_110 , V_108 ) ;
if ( F_34 ( V_8 , V_105 ) ) {
V_6 -> error = - V_40 ;
break;
}
if ( V_70 == V_72 )
V_28 -> V_63 = V_105 + V_96 -> V_109 ;
else
V_28 -> V_64 = V_105 + V_96 -> V_109 ;
}
V_106 = F_35 ( F_33 ( V_96 ) ) ;
if ( V_70 == V_72 )
V_28 -> V_61 = V_106 + V_96 -> V_109 ;
else
V_28 -> V_62 = V_106 + V_96 -> V_109 ;
while ( V_107 ) {
V_28 -> V_4 = F_36 ( V_107 , V_93 ) ;
F_16 ( & V_2 -> V_3 -> V_48 ,
L_16 ,
( V_70 == V_72 )
? L_17
: L_18 ,
V_28 -> V_4 ) ;
if ( V_70 == V_72 )
V_5 = F_24 ( V_2 , V_28 , V_12 ) ;
else
V_5 = F_28 ( V_2 , V_28 , V_12 ) ;
if ( V_5 < 0 )
break;
V_6 -> V_111 += V_28 -> V_4 ;
V_107 -= V_28 -> V_4 ;
if ( ! V_68 )
break;
}
if ( V_70 == V_10 )
F_37 ( F_33 ( V_96 ) ) ;
F_38 ( F_33 ( V_96 ) ) ;
if ( V_8 )
F_39 ( V_8 , V_105 , V_110 , V_108 ) ;
if ( V_5 < 0 ) {
V_6 -> error = V_5 ;
F_16 ( & V_3 -> V_48 , L_19 ,
( V_70 == V_72 )
? L_17 : L_18 ,
V_5 ) ;
break;
}
}
if ( V_70 == V_72 && V_68 ) {
struct V_52 * V_52 = V_2 -> V_6 ;
int V_112 ;
const unsigned V_113 = sizeof( V_52 -> V_5 ) ;
F_16 ( & V_3 -> V_48 , L_20 ) ;
F_40 ( & V_2 -> V_60 . V_114 ) ;
F_41 ( & V_2 -> V_81 . V_115 ,
& V_2 -> V_60 . V_114 ) ;
memset ( V_52 -> V_5 , 0xff , V_113 ) ;
V_52 -> V_5 [ 0 ] = V_116 ;
V_2 -> V_81 . V_61 = V_2 -> V_81 . V_62 ;
V_2 -> V_81 . V_63 = V_2 -> V_81 . V_64 ;
V_2 -> V_81 . V_4 = V_113 ;
if ( V_2 -> V_8 )
F_5 ( V_2 -> V_8 ,
V_2 -> V_9 , sizeof( * V_52 ) ,
V_67 ) ;
V_112 = F_6 ( V_3 , & V_2 -> V_60 ) ;
if ( V_2 -> V_8 )
F_7 ( V_2 -> V_8 ,
V_2 -> V_9 , sizeof( * V_52 ) ,
V_67 ) ;
if ( V_112 < 0 ) {
if ( ! V_6 -> error )
V_6 -> error = V_112 ;
return;
}
for ( V_112 = 2 ; V_112 < V_113 ; V_112 ++ ) {
if ( V_52 -> V_5 [ V_112 ] != 0 )
return;
}
V_112 = F_11 ( V_2 , V_12 ) ;
if ( V_112 < 0 && ! V_6 -> error )
V_6 -> error = V_112 ;
}
}
static void F_42 ( struct V_117 * V_84 , struct V_50 * V_51 )
{
struct V_1 * V_2 = F_43 ( V_84 ) ;
int V_5 = - V_49 ;
int V_118 = 5 ;
struct V_20 V_119 ;
#ifdef F_44
{
struct V_20 * V_21 ;
int V_120 = 0 ;
V_21 = V_51 -> V_21 ;
if ( ! F_14 ( V_21 ) ) {
F_16 ( & V_2 -> V_3 -> V_48 , L_21 ) ;
V_21 -> error = - V_49 ;
V_120 = 1 ;
}
V_21 = V_51 -> V_119 ;
if ( V_21 && ! F_14 ( V_21 ) ) {
F_16 ( & V_2 -> V_3 -> V_48 , L_22 ) ;
V_21 -> error = - V_49 ;
V_120 = 1 ;
}
if ( V_120 ) {
F_45 () ;
F_46 ( V_2 -> V_84 , V_51 ) ;
return;
}
}
#endif
F_47 ( V_2 -> V_3 -> V_121 ) ;
V_122:
V_5 = F_17 ( V_2 , V_51 , V_51 -> V_21 , V_51 -> V_6 != NULL ) ;
if ( V_5 == 0 && V_51 -> V_6 ) {
F_30 ( V_2 , V_51 -> V_21 , V_51 -> V_6 , V_51 -> V_6 -> V_123 ) ;
if ( V_51 -> V_6 -> error == - V_44 && V_118 ) {
V_119 . V_34 = V_124 ;
V_119 . V_54 = 0 ;
V_119 . V_55 = V_23 | V_125 | V_126 ;
V_5 = F_17 ( V_2 , V_51 , & V_119 , 0 ) ;
V_118 -- ;
V_51 -> V_6 -> error = 0 ;
goto V_122;
}
if ( V_51 -> V_119 )
V_5 = F_17 ( V_2 , V_51 , V_51 -> V_119 , 0 ) ;
else
F_1 ( V_2 ) ;
}
F_48 ( V_2 -> V_3 -> V_121 ) ;
F_46 ( V_2 -> V_84 , V_51 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_11 ( V_2 , V_47 ) ;
F_3 ( V_2 , 10 ) ;
V_2 -> V_3 -> V_127 |= V_128 ;
if ( F_2 ( V_2 -> V_3 ) != 0 ) {
F_50 ( & V_2 -> V_3 -> V_48 ,
L_23 ) ;
V_2 -> V_3 -> V_127 &= ~ V_128 ;
} else {
F_3 ( V_2 , 18 ) ;
V_2 -> V_3 -> V_127 &= ~ V_128 ;
if ( F_2 ( V_2 -> V_3 ) != 0 ) {
F_51 ( & V_2 -> V_3 -> V_48 ,
L_24 ) ;
}
}
}
static char * F_52 ( T_1 V_129 )
{
switch ( V_129 ) {
case V_130 : return L_25 ;
case V_131 : return L_26 ;
case V_132 : return L_27 ;
}
return L_5 ;
}
static void F_53 ( struct V_117 * V_84 , struct V_133 * V_134 )
{
struct V_1 * V_2 = F_43 ( V_84 ) ;
if ( V_2 -> V_129 != V_134 -> V_129 ) {
int V_135 ;
V_135 = V_2 -> V_136 && V_2 -> V_136 -> V_137 ;
F_16 ( & V_2 -> V_3 -> V_48 , L_28 ,
F_52 ( V_134 -> V_129 ) ,
V_134 -> V_138 ,
V_135 ? L_29 : L_30 ) ;
if ( V_135 ) {
switch ( V_134 -> V_129 ) {
case V_130 :
case V_131 :
V_2 -> V_136 -> V_137 ( & V_2 -> V_3 -> V_48 ,
V_134 -> V_138 ) ;
if ( V_134 -> V_129 == V_131 )
F_54 ( V_2 -> V_139 ) ;
}
}
if ( V_134 -> V_129 == V_132 )
F_49 ( V_2 ) ;
if ( V_135 && V_134 -> V_129 == V_130 ) {
int V_140 ;
T_1 V_141 = 0 ;
V_2 -> V_3 -> V_127 &= ~ ( V_142 | V_143 ) ;
V_140 = F_2 ( V_2 -> V_3 ) ;
if ( V_140 < 0 )
F_16 ( & V_2 -> V_3 -> V_48 ,
L_31 ) ;
if ( F_55 ( V_2 -> V_3 , & V_141 , 1 ) < 0 )
F_16 ( & V_2 -> V_3 -> V_48 ,
L_32 ) ;
F_54 ( 10 ) ;
if ( V_140 == 0 ) {
V_2 -> V_3 -> V_127 |= ( V_142 | V_143 ) ;
V_140 = F_2 ( V_2 -> V_3 ) ;
if ( V_140 < 0 )
F_16 ( & V_2 -> V_3 -> V_48 ,
L_33
L_34 ) ;
}
}
V_2 -> V_129 = V_134 -> V_129 ;
}
if ( V_2 -> V_3 -> V_101 != V_134 -> clock && V_134 -> clock != 0 ) {
int V_5 ;
V_2 -> V_3 -> V_101 = V_134 -> clock ;
V_5 = F_2 ( V_2 -> V_3 ) ;
F_16 ( & V_2 -> V_3 -> V_48 ,
L_35 ,
V_2 -> V_3 -> V_101 , V_5 ) ;
}
}
static T_5
F_56 ( int V_144 , void * V_84 )
{
struct V_1 * V_2 = F_43 ( V_84 ) ;
T_4 V_145 = F_57 ( V_2 -> V_136 -> V_146 , ( T_4 ) 100 ) ;
F_58 ( V_84 , F_59 ( V_145 ) ) ;
return V_147 ;
}
static int F_60 ( struct V_82 * V_3 )
{
void * V_77 ;
struct V_117 * V_84 ;
struct V_1 * V_2 ;
int V_5 ;
bool V_148 = false ;
if ( V_3 -> V_121 -> V_55 & V_149 )
return - V_49 ;
if ( V_3 -> V_127 != V_150 )
V_3 -> V_127 = V_151 ;
V_3 -> V_152 = 8 ;
V_5 = F_2 ( V_3 ) ;
if ( V_5 < 0 ) {
F_16 ( & V_3 -> V_48 , L_36 ,
V_3 -> V_127 , V_3 -> V_101 / 1000 ,
V_5 ) ;
return V_5 ;
}
V_5 = - V_153 ;
V_77 = F_61 ( V_154 , V_155 ) ;
if ( ! V_77 )
goto V_156;
memset ( V_77 , 0xff , V_154 ) ;
V_84 = F_62 ( sizeof( * V_2 ) , & V_3 -> V_48 ) ;
if ( ! V_84 )
goto V_156;
V_84 -> V_157 = & V_158 ;
V_84 -> V_159 = V_154 ;
V_84 -> V_160 = V_161 ;
V_84 -> V_162 = V_161 * V_154 ;
V_84 -> V_163 = V_161 ;
V_84 -> V_164 = V_165 ;
V_84 -> V_166 = 400000 ;
V_84 -> V_167 = V_3 -> V_101 ;
V_2 = F_43 ( V_84 ) ;
V_2 -> V_84 = V_84 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_77 = V_77 ;
V_2 -> V_136 = F_63 ( V_3 ) ;
if ( V_2 -> V_136 )
V_84 -> V_168 = V_2 -> V_136 -> V_169 ;
if ( ! V_84 -> V_168 ) {
F_50 ( & V_3 -> V_48 , L_37 ) ;
V_84 -> V_168 = V_170 | V_171 ;
}
if ( V_2 -> V_136 && V_2 -> V_136 -> V_137 ) {
V_2 -> V_139 = V_2 -> V_136 -> V_139 ;
if ( ! V_2 -> V_139 || V_2 -> V_139 > 250 )
V_2 -> V_139 = 250 ;
}
F_64 ( & V_3 -> V_48 , V_84 ) ;
V_2 -> V_6 = F_61 ( sizeof( * V_2 -> V_6 ) , V_155 ) ;
if ( ! V_2 -> V_6 )
goto V_172;
if ( V_3 -> V_121 -> V_48 . V_173 -> V_174 ) {
struct V_94 * V_48 = V_3 -> V_121 -> V_48 . V_173 ;
V_2 -> V_8 = V_48 ;
V_2 -> V_78 = F_65 ( V_48 , V_77 ,
V_154 , V_72 ) ;
if ( F_34 ( V_48 , V_2 -> V_78 ) )
goto V_175;
V_2 -> V_9 = F_65 ( V_48 , V_2 -> V_6 ,
sizeof( * V_2 -> V_6 ) , V_67 ) ;
if ( F_34 ( V_48 , V_2 -> V_9 ) )
goto V_176;
F_7 ( V_2 -> V_8 ,
V_2 -> V_9 , sizeof( * V_2 -> V_6 ) ,
V_67 ) ;
}
F_20 ( & V_2 -> V_11 ) ;
V_2 -> V_11 . V_66 = ( V_2 -> V_8 != NULL ) ;
F_21 ( & V_2 -> V_5 , & V_2 -> V_11 ) ;
V_2 -> V_5 . V_61 = V_2 -> V_77 ;
V_2 -> V_5 . V_63 = V_2 -> V_78 ;
V_2 -> V_5 . V_62 = & V_2 -> V_6 -> V_5 ;
V_2 -> V_5 . V_64 = V_2 -> V_9 + F_23 ( struct V_52 , V_5 ) ;
V_2 -> V_5 . V_65 = 1 ;
if ( V_2 -> V_136 && V_2 -> V_136 -> V_177 ) {
V_5 = V_2 -> V_136 -> V_177 ( & V_3 -> V_48 , F_56 , V_84 ) ;
if ( V_5 != 0 )
goto V_178;
}
if ( V_2 -> V_136 ) {
V_84 -> V_164 |= V_2 -> V_136 -> V_164 ;
V_84 -> V_179 |= V_2 -> V_136 -> V_179 ;
}
V_5 = F_66 ( V_84 ) ;
if ( V_5 != 0 )
goto V_180;
if ( V_2 -> V_136 && V_2 -> V_136 -> V_55 & V_181 ) {
V_5 = F_67 ( V_84 , V_2 -> V_136 -> V_182 ,
V_2 -> V_136 -> V_183 ) ;
if ( V_5 != 0 )
goto V_180;
V_84 -> V_164 &= ~ V_184 ;
F_68 ( V_84 ) ;
}
if ( V_2 -> V_136 && V_2 -> V_136 -> V_55 & V_185 ) {
V_148 = true ;
V_5 = F_69 ( V_84 , V_2 -> V_136 -> V_186 ) ;
if ( V_5 != 0 )
goto V_180;
}
F_70 ( & V_3 -> V_48 , L_38 ,
F_71 ( & V_84 -> V_187 ) ,
V_2 -> V_8 ? L_30 : L_39 ,
V_148 ? L_30 : L_40 ,
( V_2 -> V_136 && V_2 -> V_136 -> V_137 )
? L_30 : L_41 ,
( V_84 -> V_164 & V_184 )
? L_42 : L_30 ) ;
return 0 ;
V_180:
F_72 ( V_84 ) ;
V_178:
if ( V_2 -> V_8 )
F_73 ( V_2 -> V_8 , V_2 -> V_9 ,
sizeof( * V_2 -> V_6 ) , V_67 ) ;
V_176:
if ( V_2 -> V_8 )
F_73 ( V_2 -> V_8 , V_2 -> V_78 ,
V_154 , V_72 ) ;
V_175:
F_74 ( V_2 -> V_6 ) ;
V_172:
F_75 ( V_84 ) ;
F_76 ( V_3 ) ;
F_64 ( & V_3 -> V_48 , NULL ) ;
V_156:
F_74 ( V_77 ) ;
return V_5 ;
}
static int F_77 ( struct V_82 * V_3 )
{
struct V_117 * V_84 = F_78 ( & V_3 -> V_48 ) ;
struct V_1 * V_2 ;
if ( V_84 ) {
V_2 = F_43 ( V_84 ) ;
if ( V_2 -> V_136 && V_2 -> V_136 -> exit )
V_2 -> V_136 -> exit ( & V_3 -> V_48 , V_84 ) ;
F_72 ( V_84 ) ;
if ( V_2 -> V_8 ) {
F_73 ( V_2 -> V_8 , V_2 -> V_78 ,
V_154 , V_72 ) ;
F_73 ( V_2 -> V_8 , V_2 -> V_9 ,
sizeof( * V_2 -> V_6 ) , V_67 ) ;
}
F_74 ( V_2 -> V_6 ) ;
F_74 ( V_2 -> V_77 ) ;
V_3 -> V_101 = V_84 -> V_167 ;
F_75 ( V_84 ) ;
F_76 ( V_3 ) ;
F_64 ( & V_3 -> V_48 , NULL ) ;
}
return 0 ;
}
