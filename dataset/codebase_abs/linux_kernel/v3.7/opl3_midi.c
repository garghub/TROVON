void F_1 ( unsigned char * V_1 , int V_2 ,
struct V_3 * V_4 )
{
int V_5 , V_6 , V_7 ;
int V_8 ;
V_8 = ( V_2 * V_4 -> V_9 * V_4 -> V_10 ) / ( 127 * 127 ) ;
if ( V_8 > 127 )
V_8 = 127 ;
V_5 = V_11 - ( * V_1 & V_11 ) ;
V_6 = V_12 [ V_8 ] + V_5 ;
if ( V_6 > V_11 )
V_6 = V_11 ;
else if ( V_6 < 0 )
V_6 = 0 ;
V_7 = V_11 - ( V_6 & V_11 ) ;
* V_1 = ( * V_1 & V_13 ) | ( V_7 & V_11 ) ;
}
static void F_2 ( unsigned char * V_14 , unsigned char * V_15 ,
int V_16 , struct V_3 * V_4 )
{
int V_17 = ( ( V_16 / 12 ) & 0x07 ) - 1 ;
int V_18 = ( V_16 % 12 ) + 2 ;
int V_19 ;
if ( V_4 -> V_20 ) {
int V_21 = V_4 -> V_20 ;
int V_22 ;
if ( V_21 > 0x1FFF )
V_21 = 0x1FFF ;
V_22 = V_21 / 0x1000 ;
V_19 = V_23 [ V_18 + V_22 ] ;
V_19 += ( ( V_23 [ V_18 + V_22 + 1 ] - V_19 ) *
( V_21 % 0x1000 ) ) / 0x1000 ;
} else {
V_19 = V_23 [ V_18 ] ;
}
* V_14 = ( unsigned char ) V_19 ;
* V_15 = ( ( V_19 >> 8 ) & V_24 ) |
( ( V_17 << 2 ) & V_25 ) ;
}
static void F_3 ( struct V_26 * V_27 , char * V_28 , int V_29 ) {
int V_30 ;
char * V_31 = L_1 ;
F_4 ( V_32 L_2 , V_27 -> V_33 , V_28 , V_29 ) ;
for ( V_30 = 0 ; V_30 < V_27 -> V_34 ; V_30 ++ )
F_4 ( L_3 , * ( V_31 + V_27 -> V_35 [ V_30 ] . V_36 + 1 ) ) ;
F_4 ( L_4 ) ;
}
static int F_5 ( struct V_26 * V_27 , int V_37 ,
struct V_3 * V_4 ) {
int V_38 ;
int V_39 ;
struct V_40 * V_41 , * V_42 ;
unsigned int V_43 ;
int V_30 ;
#ifdef F_6
char * V_44 [ 3 ] = { L_5 , L_6 , L_7 } ;
#endif
enum {
FREE = 0 , V_45 , V_46 , V_47
};
struct V_48 {
unsigned int time ;
int V_29 ;
} V_48 [ V_47 ] ;
struct V_48 * V_49 ;
for ( V_30 = 0 ; V_30 < V_47 ; V_30 ++ ) {
V_48 [ V_30 ] . time = ( unsigned int ) ( - 1 ) ;
V_48 [ V_30 ] . V_29 = - 1 ;
}
for ( V_30 = 0 ; V_30 < V_27 -> V_34 ; V_30 ++ ) {
V_41 = & V_27 -> V_35 [ V_30 ] ;
if ( V_41 -> V_36 == V_50 )
continue;
V_43 = V_41 -> time ;
V_49 = V_48 ;
V_38 = ( ( V_30 < 3 ) || ( V_30 > 8 && V_30 < 12 ) ) ;
V_39 = ( ( V_30 > 2 && V_30 < 6 ) || ( V_30 > 11 && V_30 < 15 ) ) ;
if ( V_37 ) {
if ( ! V_38 )
continue;
if ( V_41 -> V_36 )
V_49 ++ ;
V_42 = & V_27 -> V_35 [ V_30 + 3 ] ;
if ( V_42 -> V_36 == V_51 ) {
V_49 ++ ;
V_43 = ( V_43 > V_41 -> time ) ?
V_43 : V_41 -> time ;
}
} else {
if ( ( V_38 ) || ( V_39 ) )
V_49 ++ ;
else if ( V_41 -> V_36 )
V_49 ++ ;
if ( V_41 -> V_36 )
V_49 ++ ;
}
if ( V_43 < V_49 -> time ) {
V_49 -> time = V_43 ;
V_49 -> V_29 = V_30 ;
}
}
for ( V_30 = 0 ; V_30 < V_47 ; V_30 ++ ) {
if ( V_48 [ V_30 ] . V_29 >= 0 ) {
#ifdef F_6
F_4 ( V_32 L_8 ,
V_44 [ V_30 ] , V_37 ? 4 : 2 ,
V_48 [ V_30 ] . V_29 ) ;
#endif
return V_48 [ V_30 ] . V_29 ;
}
}
return - 1 ;
}
void F_7 ( unsigned long V_52 )
{
struct V_26 * V_27 = (struct V_26 * ) V_52 ;
unsigned long V_53 ;
int V_54 = 0 ;
int V_30 ;
F_8 ( & V_27 -> V_55 , V_53 ) ;
for ( V_30 = 0 ; V_30 < V_27 -> V_34 ; V_30 ++ ) {
struct V_40 * V_41 = & V_27 -> V_35 [ V_30 ] ;
if ( V_41 -> V_36 > 0 && V_41 -> V_56 ) {
if ( V_41 -> V_57 == V_58 )
F_9 ( V_27 , V_41 -> V_16 , 0 ,
V_41 -> V_4 ) ;
else
V_54 ++ ;
}
}
F_10 ( & V_27 -> V_55 , V_53 ) ;
F_8 ( & V_27 -> V_59 , V_53 ) ;
if ( V_54 ) {
V_27 -> V_60 . V_61 = V_58 + 1 ;
F_11 ( & V_27 -> V_60 ) ;
} else {
V_27 -> V_62 = 0 ;
}
F_10 ( & V_27 -> V_59 , V_53 ) ;
}
static void F_12 ( struct V_26 * V_27 )
{
unsigned long V_53 ;
F_8 ( & V_27 -> V_59 , V_53 ) ;
if ( ! V_27 -> V_62 ) {
V_27 -> V_60 . V_61 = V_58 + 1 ;
F_11 ( & V_27 -> V_60 ) ;
V_27 -> V_62 = 1 ;
}
F_10 ( & V_27 -> V_59 , V_53 ) ;
}
void F_13 ( void * V_63 , int V_16 , int V_2 , struct V_3 * V_4 )
{
struct V_26 * V_27 ;
int V_37 ;
int V_29 ;
struct V_40 * V_41 , * V_42 ;
unsigned short V_64 ;
unsigned char V_65 ;
unsigned char V_66 [ 4 ] ;
int V_67 = 0 ;
unsigned short V_68 ;
unsigned char V_69 ;
unsigned char V_70 ;
unsigned short V_71 ;
unsigned char V_72 ;
unsigned char V_73 , V_74 ;
int V_75 = V_16 ;
unsigned char V_14 , V_15 ;
int V_30 ;
struct V_76 * V_77 ;
struct V_78 * V_79 ;
unsigned long V_53 ;
V_27 = V_63 ;
#ifdef F_14
F_15 ( V_32 L_9 ,
V_4 -> V_80 , V_4 -> V_81 , V_16 , V_2 ) ;
#endif
if ( V_27 -> V_82 == V_83 ) {
if ( V_4 -> V_84 ) {
V_74 = 128 ;
V_73 = V_16 ;
} else {
V_74 = V_4 -> V_85 ;
V_73 = V_4 -> V_81 ;
}
} else {
if ( V_4 -> V_80 >= V_86 )
return;
V_74 = 127 ;
V_73 = V_4 -> V_81 ;
}
F_8 ( & V_27 -> V_55 , V_53 ) ;
if ( V_87 ) {
F_16 ( V_27 , V_16 , V_2 , 1 , V_4 ) ;
F_10 ( & V_27 -> V_55 , V_53 ) ;
return;
}
V_88:
V_77 = F_17 ( V_27 , V_73 , V_74 , 0 ) ;
if ( ! V_77 ) {
F_10 ( & V_27 -> V_55 , V_53 ) ;
return;
}
V_79 = & V_77 -> V_89 ;
switch ( V_77 -> type ) {
case V_90 :
V_37 = 0 ;
break;
case V_91 :
if ( V_27 -> V_92 >= V_93 ) {
V_37 = 1 ;
break;
}
default:
F_10 ( & V_27 -> V_55 , V_53 ) ;
return;
}
#ifdef F_14
F_15 ( V_32 L_10 ,
V_37 ? 3 : 2 , V_77 -> V_94 ) ;
#endif
if ( V_27 -> V_82 == V_83 ) {
V_29 = F_5 ( V_27 , V_37 , V_4 ) ;
} else {
V_29 = V_95 [ V_4 -> V_80 ] ;
}
if ( V_29 < V_96 ) {
V_68 = V_97 ;
V_70 = V_29 ;
V_64 = ( V_98 << V_70 ) & 0x07 ;
} else {
V_68 = V_99 ;
V_70 = V_29 - V_96 ;
V_64 = ( V_100 << V_70 ) & 0x38 ;
}
V_41 = & V_27 -> V_35 [ V_29 ] ;
if ( V_41 -> V_36 > 0 ) {
V_71 = V_68 | ( V_101 + V_70 ) ;
V_72 = V_41 -> V_102 & ~ V_103 ;
V_27 -> V_104 ( V_27 , V_71 , V_72 ) ;
}
if ( V_37 ) {
V_42 = & V_27 -> V_35 [ V_29 + 3 ] ;
if ( V_41 -> V_36 > 0 ) {
V_71 = V_68 | ( V_101 +
V_70 + 3 ) ;
V_72 = V_41 -> V_102 & ~ V_103 ;
V_27 -> V_104 ( V_27 , V_71 , V_72 ) ;
}
}
if ( V_37 ) {
if ( ( V_27 -> V_105 ^ V_64 ) & V_64 ) {
V_27 -> V_105 |= V_64 ;
V_71 = V_99 | V_106 ;
V_27 -> V_104 ( V_27 , V_71 , V_27 -> V_105 ) ;
}
} else {
if ( ( V_27 -> V_105 ^ ~ V_64 ) & V_64 ) {
V_27 -> V_105 &= ~ V_64 ;
V_71 = V_99 | V_106 ;
V_27 -> V_104 ( V_27 , V_71 , V_27 -> V_105 ) ;
}
}
#ifdef F_14
F_15 ( V_32 L_11 ,
V_27 -> V_105 ) ;
#endif
for ( V_30 = 0 ; V_30 < ( V_37 ? 4 : 2 ) ; V_30 ++ )
V_66 [ V_30 ] = V_79 -> V_107 [ V_30 ] . V_108 ;
V_65 = V_79 -> V_109 [ 0 ] & 0x01 ;
if ( V_37 ) {
V_65 <<= 1 ;
V_65 |= V_79 -> V_109 [ 1 ] & 0x01 ;
F_1 ( & V_66 [ 3 ] , V_2 , V_4 ) ;
switch ( V_65 ) {
case 0x03 :
F_1 ( & V_66 [ 2 ] , V_2 , V_4 ) ;
case 0x02 :
F_1 ( & V_66 [ 0 ] , V_2 , V_4 ) ;
break;
case 0x01 :
F_1 ( & V_66 [ 1 ] , V_2 , V_4 ) ;
}
} else {
F_1 ( & V_66 [ 1 ] , V_2 , V_4 ) ;
if ( V_65 )
F_1 ( & V_66 [ 0 ] , V_2 , V_4 ) ;
}
for ( V_30 = 0 ; V_30 < ( V_37 ? 4 : 2 ) ; V_30 ++ ) {
#ifdef F_14
F_15 ( V_32 L_12 , V_30 ) ;
#endif
V_69 = V_110 [ V_70 ] [ V_30 ] ;
V_72 = V_79 -> V_107 [ V_30 ] . V_111 ;
V_71 = V_68 | ( V_112 + V_69 ) ;
V_27 -> V_104 ( V_27 , V_71 , V_72 ) ;
V_72 = V_66 [ V_30 ] ;
V_71 = V_68 | ( V_113 + V_69 ) ;
V_27 -> V_104 ( V_27 , V_71 , V_72 ) ;
V_72 = V_79 -> V_107 [ V_30 ] . V_114 ;
V_71 = V_68 | ( V_115 + V_69 ) ;
V_27 -> V_104 ( V_27 , V_71 , V_72 ) ;
V_72 = V_79 -> V_107 [ V_30 ] . V_116 ;
V_71 = V_68 | ( V_117 + V_69 ) ;
V_27 -> V_104 ( V_27 , V_71 , V_72 ) ;
V_72 = V_79 -> V_107 [ V_30 ] . V_118 ;
V_71 = V_68 | ( V_119 + V_69 ) ;
V_27 -> V_104 ( V_27 , V_71 , V_72 ) ;
}
V_72 = V_79 -> V_109 [ 0 ] ;
V_72 |= V_120 ;
if ( V_4 -> V_121 < 43 )
V_72 &= ~ V_122 ;
if ( V_4 -> V_121 > 85 )
V_72 &= ~ V_123 ;
V_71 = V_68 | ( V_124 + V_70 ) ;
V_27 -> V_104 ( V_27 , V_71 , V_72 ) ;
if ( V_37 ) {
V_72 = V_79 -> V_109 [ 1 ] & V_125 ;
V_72 |= V_120 ;
if ( V_4 -> V_121 < 43 )
V_72 &= ~ V_122 ;
if ( V_4 -> V_121 > 85 )
V_72 &= ~ V_123 ;
V_71 = V_68 | ( V_124 +
V_70 + 3 ) ;
V_27 -> V_104 ( V_27 , V_71 , V_72 ) ;
}
if ( V_79 -> V_126 )
V_16 = V_79 -> V_126 ;
if ( V_79 -> V_127 )
V_16 += ( V_79 -> V_127 - 64 ) ;
F_2 ( & V_14 , & V_15 , V_16 , V_4 ) ;
V_71 = V_68 | ( V_128 + V_70 ) ;
V_27 -> V_104 ( V_27 , V_71 , V_14 ) ;
V_27 -> V_35 [ V_29 ] . V_102 = V_15 ;
V_15 |= V_103 ;
#ifdef F_14
F_15 ( V_32 L_13 , V_29 ) ;
#endif
V_71 = V_68 | ( V_101 + V_70 ) ;
V_27 -> V_104 ( V_27 , V_71 , V_15 ) ;
if ( V_79 -> V_129 ) {
V_27 -> V_35 [ V_29 ] . V_57 = V_58 +
( V_79 -> V_129 * V_130 ) / 100 ;
F_12 ( V_27 ) ;
V_27 -> V_35 [ V_29 ] . V_56 = 1 ;
} else
V_27 -> V_35 [ V_29 ] . V_56 = 0 ;
V_67 = ( V_67 ) ? 0 : V_79 -> V_131 ;
V_41 -> time = V_27 -> V_33 ++ ;
V_41 -> V_16 = V_75 ;
V_41 -> V_4 = V_4 ;
if ( V_37 ) {
V_41 -> V_36 = V_132 ;
V_42 = & V_27 -> V_35 [ V_29 + 3 ] ;
V_42 -> time = V_27 -> V_33 ++ ;
V_42 -> V_16 = V_75 ;
V_42 -> V_4 = V_4 ;
V_42 -> V_36 = V_50 ;
} else {
if ( V_41 -> V_36 == V_132 ) {
V_42 = & V_27 -> V_35 [ V_29 + 3 ] ;
V_42 -> time = V_27 -> V_33 ++ ;
V_42 -> V_36 = V_133 ;
}
V_41 -> V_36 = V_51 ;
}
#ifdef F_6
F_3 ( V_27 , L_14 , V_29 ) ;
#endif
if ( V_67 ) {
if ( V_67 > 128 ) {
V_74 = 128 ;
V_73 = V_67 - 128 + 35 - 1 ;
} else {
V_74 = 0 ;
V_73 = V_67 - 1 ;
}
#ifdef F_14
F_15 ( V_32 L_15 ) ;
#endif
goto V_88;
}
F_10 ( & V_27 -> V_55 , V_53 ) ;
}
static void F_18 ( struct V_26 * V_27 , int V_29 )
{
unsigned short V_68 ;
unsigned char V_70 ;
unsigned short V_71 ;
struct V_40 * V_41 , * V_42 ;
if ( F_19 ( V_29 >= V_86 ) )
return;
V_41 = & V_27 -> V_35 [ V_29 ] ;
if ( V_29 < V_96 ) {
V_68 = V_97 ;
V_70 = V_29 ;
} else {
V_68 = V_99 ;
V_70 = V_29 - V_96 ;
}
#ifdef F_14
F_15 ( V_32 L_16 , V_29 ) ;
#endif
V_71 = V_68 | ( V_101 + V_70 ) ;
V_27 -> V_104 ( V_27 , V_71 , V_41 -> V_102 ) ;
V_41 -> time = V_27 -> V_33 ++ ;
if ( V_41 -> V_36 == V_132 ) {
V_42 = & V_27 -> V_35 [ V_29 + 3 ] ;
V_42 -> time = V_27 -> V_33 ++ ;
V_42 -> V_36 = V_133 ;
}
V_41 -> V_36 = V_133 ;
#ifdef F_6
F_3 ( V_27 , L_17 , V_29 ) ;
#endif
}
static void F_9 ( void * V_63 , int V_16 , int V_2 ,
struct V_3 * V_4 )
{
struct V_26 * V_27 ;
int V_29 ;
struct V_40 * V_41 ;
V_27 = V_63 ;
#ifdef F_14
F_15 ( V_32 L_18 ,
V_4 -> V_80 , V_4 -> V_81 , V_16 ) ;
#endif
if ( V_27 -> V_82 == V_83 ) {
if ( V_4 -> V_84 && V_87 ) {
F_16 ( V_27 , V_16 , V_2 , 0 , V_4 ) ;
return;
}
for ( V_29 = 0 ; V_29 < V_27 -> V_34 ; V_29 ++ ) {
V_41 = & V_27 -> V_35 [ V_29 ] ;
if ( V_41 -> V_36 > 0 && V_41 -> V_4 == V_4 && V_41 -> V_16 == V_16 ) {
F_18 ( V_27 , V_29 ) ;
}
}
} else {
if ( V_4 -> V_80 < V_86 ) {
V_29 = V_95 [ V_4 -> V_80 ] ;
F_18 ( V_27 , V_29 ) ;
}
}
}
void F_20 ( void * V_63 , int V_16 , int V_2 ,
struct V_3 * V_4 )
{
struct V_26 * V_27 = V_63 ;
unsigned long V_53 ;
F_8 ( & V_27 -> V_55 , V_53 ) ;
F_9 ( V_63 , V_16 , V_2 , V_4 ) ;
F_10 ( & V_27 -> V_55 , V_53 ) ;
}
void F_21 ( void * V_63 , int V_16 , int V_2 , struct V_3 * V_4 )
{
struct V_26 * V_27 ;
V_27 = V_63 ;
#ifdef F_14
F_15 ( V_32 L_19 ,
V_4 -> V_80 , V_4 -> V_81 ) ;
#endif
}
void F_22 ( void * V_63 , int V_16 , struct V_3 * V_4 )
{
struct V_26 * V_27 ;
V_27 = V_63 ;
#ifdef F_14
F_15 ( V_32 L_20 ,
V_4 -> V_80 , V_4 -> V_81 ) ;
#endif
}
static void F_23 ( struct V_26 * V_27 , int V_29 )
{
unsigned short V_68 ;
unsigned char V_70 ;
unsigned short V_71 ;
unsigned char V_14 , V_15 ;
struct V_40 * V_41 ;
if ( F_19 ( V_29 >= V_86 ) )
return;
V_41 = & V_27 -> V_35 [ V_29 ] ;
if ( V_41 -> V_4 == NULL )
return;
if ( V_29 < V_96 ) {
V_68 = V_97 ;
V_70 = V_29 ;
} else {
V_68 = V_99 ;
V_70 = V_29 - V_96 ;
}
F_2 ( & V_14 , & V_15 , V_41 -> V_16 , V_41 -> V_4 ) ;
V_71 = V_68 | ( V_128 + V_70 ) ;
V_27 -> V_104 ( V_27 , V_71 , V_14 ) ;
V_41 -> V_102 = V_15 ;
V_15 |= V_103 ;
V_71 = V_68 | ( V_101 + V_70 ) ;
V_27 -> V_104 ( V_27 , V_71 , V_15 ) ;
V_41 -> time = V_27 -> V_33 ++ ;
}
static void F_24 ( struct V_26 * V_27 , struct V_3 * V_4 )
{
int V_29 ;
struct V_40 * V_41 ;
unsigned long V_53 ;
F_8 ( & V_27 -> V_55 , V_53 ) ;
if ( V_27 -> V_82 == V_83 ) {
for ( V_29 = 0 ; V_29 < V_27 -> V_34 ; V_29 ++ ) {
V_41 = & V_27 -> V_35 [ V_29 ] ;
if ( V_41 -> V_36 > 0 && V_41 -> V_4 == V_4 ) {
F_23 ( V_27 , V_29 ) ;
}
}
} else {
if ( V_4 -> V_80 < V_86 ) {
V_29 = V_95 [ V_4 -> V_80 ] ;
F_23 ( V_27 , V_29 ) ;
}
}
F_10 ( & V_27 -> V_55 , V_53 ) ;
}
void F_25 ( void * V_63 , int type , struct V_3 * V_4 )
{
struct V_26 * V_27 ;
V_27 = V_63 ;
#ifdef F_14
F_15 ( V_32 L_21 ,
type , V_4 -> V_80 , V_4 -> V_81 ) ;
#endif
switch ( type ) {
case V_134 :
if ( V_4 -> V_135 [ V_134 ] > 63 )
V_27 -> V_136 |= V_137 ;
else
V_27 -> V_136 &= ~ V_137 ;
V_27 -> V_104 ( V_27 , V_97 | V_138 ,
V_27 -> V_136 ) ;
break;
case V_139 :
if ( V_4 -> V_135 [ V_139 ] > 63 )
V_27 -> V_136 |= V_140 ;
else
V_27 -> V_136 &= ~ V_140 ;
V_27 -> V_104 ( V_27 , V_97 | V_138 ,
V_27 -> V_136 ) ;
break;
case V_141 :
F_24 ( V_27 , V_4 ) ;
break;
}
}
void F_26 ( void * V_63 , struct V_3 * V_4 ,
struct V_142 * V_143 )
{
struct V_26 * V_27 ;
V_27 = V_63 ;
#ifdef F_14
F_15 ( V_32 L_22 ,
V_4 -> V_80 , V_4 -> V_81 ) ;
#endif
}
void F_27 ( void * V_63 , unsigned char * V_144 , int V_145 ,
int V_146 , struct V_142 * V_143 )
{
struct V_26 * V_27 ;
V_27 = V_63 ;
#ifdef F_14
F_15 ( V_32 L_23 ) ;
#endif
}
