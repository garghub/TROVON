static const char * F_1 ( T_1 * V_1 , T_2 V_2 )
{
if ( ( V_2 == V_3 ) && ( V_1 -> V_4 . type == V_5 ) )
return L_1 ;
if ( ( V_2 == V_6 ) && ( V_1 -> V_7 . type == V_5 ) )
return L_2 ;
if ( ( V_2 == V_8 ) && ( V_1 -> V_4 . type == V_5 ) )
return L_3 ;
return V_9 ;
}
static int
F_2 ( void * V_10 , T_3 * V_11 , T_4 * T_5 V_12 , const void * V_13 )
{
T_6 * V_14 = ( T_6 * ) V_10 ;
const T_7 * V_15 = ( const T_7 * ) V_13 ;
F_3 ( V_14 , & V_15 -> V_16 , & V_15 -> V_17 , 0 , 0 , 1 , V_11 -> V_18 -> V_19 , & V_11 -> V_20 , & V_11 -> V_18 -> V_21 , & V_22 , V_23 ) ;
return 1 ;
}
static const char * F_4 ( T_8 * V_24 , T_2 V_2 )
{
if ( ( V_2 == V_8 ) && ( V_24 -> V_25 . type == V_5 ) )
return L_3 ;
return V_9 ;
}
static int
F_5 ( void * V_26 , T_3 * V_11 , T_4 * T_5 V_12 , const void * V_13 )
{
T_6 * V_14 = ( T_6 * ) V_26 ;
const T_7 * V_15 = ( const T_7 * ) V_13 ;
F_6 ( V_14 , & V_15 -> V_16 , 0 , TRUE , 1 , V_11 -> V_18 -> V_19 , & V_27 , V_23 ) ;
F_6 ( V_14 , & V_15 -> V_17 , 0 , FALSE , 1 , V_11 -> V_18 -> V_19 , & V_27 , V_23 ) ;
return 1 ;
}
static
int F_7 ( T_9 * V_28 )
{
const T_10 * V_29 ;
int V_30 , V_31 ;
V_31 = F_8 ( V_28 ) ;
if ( V_31 > 19 ) {
V_31 = 19 ;
}
V_29 = F_9 ( V_28 , 0 , V_31 ) ;
for( V_30 = 1 ; V_30 <= V_31 - 1 ; V_30 ++ )
{
if ( memcmp ( & V_29 [ 0 ] , & V_29 [ V_30 ] , V_30 ) == 0 )
{
return V_30 ;
}
}
return 0 ;
}
static
int F_10 ( const T_11 * V_32 )
{
int V_30 ;
for( V_30 = 1 ; V_30 <= 18 ; V_30 ++ )
{
if ( memcmp ( & V_32 [ 0 ] , & V_32 [ V_30 ] , V_30 ) == 0 )
{
return V_30 ;
}
}
return 0 ;
}
void
F_11 ( const T_11 * V_32 , int V_33 , int V_34 , T_12 * V_35 ) {
int V_36 = 0 ;
int V_37 ;
int V_30 ;
T_10 V_38 ;
T_10 V_39 ;
T_13 V_40 ;
T_10 V_41 ;
const T_10 * V_42 ;
if ( ! F_12 ( V_33 , V_34 , V_43 ) ) {
V_35 -> V_44 ++ ;
return;
}
if ( ( V_30 = F_10 ( V_32 ) ) )
{
V_33 += V_30 ;
}
V_41 = V_32 [ V_33 + 1 ] ;
V_42 = & V_32 [ V_33 + 8 ] ;
V_37 = ( V_41 & 192 ) >> 6 ;
V_36 = V_42 [ 0 ] & 128 ;
V_38 = V_32 [ V_33 + 14 ] & 31 ;
if ( V_45 ) {
if ( ! V_36 && V_38 > 0 ) {
if ( V_32 [ V_33 + 0x0e ] != V_32 [ V_33 + 0x0f ] ) {
V_40 = F_13 ( & V_32 [ V_33 + 0xe0 + V_38 ] ) ;
if (
( V_40 == 0xaaaa &&
V_32 [ V_33 + 0x10 + V_38 ] == 0x03 ) ||
V_40 == 0xe0e0 ||
V_40 == 0xe0aa ) {
V_36 = 1 ;
}
}
}
}
if ( V_36 ) {
V_39 = V_38 ;
}
else {
V_38 = 0 ;
V_39 = 0 ;
}
if ( V_45 ) {
if ( ( V_36 && V_38 == 2 && V_37 == 1 ) ||
( ! V_36 && V_37 == 1 ) ) {
if ( ( V_32 [ V_33 + 0x20 ] == 0xaa && V_32 [ V_33 + 0x21 ] == 0xaa && V_32 [ V_33 + 0x22 ] == 03 ) ||
( V_32 [ V_33 + 0x20 ] == 0xe0 && V_32 [ V_33 + 0x21 ] == 0xe0 ) ) {
V_39 = 18 ;
} else if (
V_32 [ V_33 + 0x23 ] == 0 &&
V_32 [ V_33 + 0x24 ] == 0 &&
V_32 [ V_33 + 0x25 ] == 0 &&
V_32 [ V_33 + 0x26 ] == 0x00 &&
V_32 [ V_33 + 0x27 ] == 0x11 ) {
V_39 = 18 ;
V_33 += 8 ;
}
}
}
V_33 += V_39 + V_43 ;
switch ( V_37 ) {
case 0 :
V_35 -> V_44 ++ ;
break;
case 1 :
F_14 ( V_32 , V_33 , V_34 , V_35 ) ;
break;
default:
V_35 -> V_44 ++ ;
break;
}
}
static void
F_15 ( T_9 * V_28 , T_3 * V_11 , T_14 * V_46 )
{
T_14 * V_47 ;
T_15 * V_48 , * V_49 ;
T_10 V_50 , V_51 ;
T_9 * V_52 ;
volatile int V_37 ;
volatile int V_53 = 0 ;
volatile int V_36 = 0 ;
volatile T_10 V_38 ;
volatile T_10 V_39 ;
volatile T_10 V_54 ;
volatile T_10 V_55 ;
volatile T_13 V_40 ;
T_9 * volatile V_56 ;
static T_7 V_57 [ 4 ] ;
static int V_58 = 0 ;
T_7 * volatile V_59 ;
T_10 * V_60 = ( T_10 * ) F_16 ( V_11 -> V_61 , 6 ) ;
int V_30 ;
static const char * V_62 [] = { L_4 , L_5 , L_6 , L_7 } ;
V_58 ++ ;
if( V_58 == 4 ) {
V_58 = 0 ;
}
V_59 = & V_57 [ V_58 ] ;
F_17 ( V_11 -> V_63 , V_64 , L_8 ) ;
if ( V_45 )
V_30 = F_7 ( ( T_9 * ) V_28 ) ;
else
V_30 = 0 ;
if ( V_30 != 0 ) {
V_56 = F_18 ( ( T_9 * ) V_28 , V_30 ) ;
}
else {
V_56 = V_28 ;
}
V_59 -> V_62 = F_19 ( V_56 , 1 ) ;
F_20 ( & V_59 -> V_16 , V_5 , V_56 , 8 , 6 ) ;
F_20 ( & V_59 -> V_17 , V_5 , V_56 , 2 , 6 ) ;
memcpy ( V_60 , V_59 -> V_16 . V_29 , 6 ) ;
V_36 = V_60 [ 0 ] & 128 ;
V_60 [ 0 ] &= 127 ;
V_37 = ( V_59 -> V_62 & 192 ) >> 6 ;
F_21 ( V_11 -> V_63 , V_65 , L_9 , V_62 [ V_37 ] ) ;
V_38 = F_19 ( V_56 , 14 ) & 31 ;
if ( V_45 ) {
if ( V_37 == 1 && ! V_36 && V_38 > 0 ) {
F_22 {
V_54 = F_19 ( V_56 , 14 ) ;
V_55 = F_19 ( V_56 , 15 ) ;
if ( V_54 != V_55 ) {
V_40 = F_23 ( V_56 , V_38 + 0x0e ) ;
if ( ( V_40 == 0xaaaa &&
F_19 ( V_56 , V_38 + 0x10 ) == 0x03 ) ||
V_40 == 0xe0e0 ||
V_40 == 0xe0aa ) {
V_36 = 1 ;
}
}
}
F_24 (BoundsError) {
;
}
V_66 ;
}
}
if ( V_36 ) {
V_39 = V_38 ;
}
else {
V_38 = 0 ;
V_39 = 0 ;
}
if ( V_45 ) {
F_22 {
if ( V_37 == 1 && ( ( V_36 && V_38 == 2 ) ||
! V_36 ) ) {
if (
( F_23 ( V_56 , 0x20 ) == 0xaaaa &&
F_19 ( V_56 , 0x22 ) == 0x03 )
||
F_23 ( V_56 , 0x20 ) == 0xe0e0 ) {
V_39 = 18 ;
}
else if (
F_25 ( V_56 , 0x23 ) == 0 &&
F_19 ( V_56 , 0x27 ) == 0x11 ) {
V_39 = 18 ;
V_53 += 8 ;
}
}
}
F_24 (BoundsError) {
;
}
V_66 ;
}
F_26 ( & V_11 -> V_67 , V_5 , 6 , V_60 ) ;
F_27 ( & V_11 -> V_16 , & V_11 -> V_67 ) ;
F_26 ( & V_11 -> V_68 , V_5 , 6 , V_59 -> V_17 . V_29 ) ;
F_27 ( & V_11 -> V_17 , & V_11 -> V_68 ) ;
if ( V_46 ) {
static const int * V_69 [] = {
& V_70 ,
& V_71 ,
& V_72 ,
& V_73 ,
NULL
} ;
static const int * V_74 [] = {
& V_75 ,
& V_76 ,
NULL
} ;
V_48 = F_28 ( V_46 , V_77 , V_56 , 0 , V_43 + V_39 , V_78 ) ;
V_47 = F_29 ( V_48 , V_79 ) ;
V_59 -> V_69 = F_19 ( V_56 , 0 ) ;
F_30 ( V_47 , V_56 , 0 , V_80 , V_81 , V_69 , V_78 ) ;
F_30 ( V_47 , V_56 , 1 , V_82 , V_83 , V_74 , V_78 ) ;
F_31 ( V_47 , V_84 , V_56 , 2 , 6 , ( const T_10 * ) V_59 -> V_17 . V_29 ) ;
F_31 ( V_47 , V_85 , V_56 , 8 , 6 , ( const T_10 * ) V_59 -> V_16 . V_29 ) ;
V_49 = F_31 ( V_47 , V_86 , V_56 , 2 , 6 , ( const T_10 * ) V_59 -> V_17 . V_29 ) ;
F_32 ( V_49 ) ;
V_49 = F_31 ( V_47 , V_86 , V_56 , 8 , 6 , ( const T_10 * ) V_59 -> V_16 . V_29 ) ;
F_32 ( V_49 ) ;
F_33 ( V_47 , V_87 , V_56 , 8 , 1 , V_36 ) ;
V_49 = F_31 ( V_47 , V_85 , V_56 , 8 , 6 , V_60 ) ;
F_32 ( V_49 ) ;
if ( V_36 ) {
V_50 = F_19 ( V_56 , 14 ) ;
F_34 ( V_47 , V_88 , V_56 , 14 , 1 , V_38 ) ;
F_34 ( V_47 , V_89 , V_56 , 14 , 1 , V_50 & 224 ) ;
V_51 = F_19 ( V_56 , 15 ) ;
F_34 ( V_47 , V_90 , V_56 , 15 , 1 , V_51 & 112 ) ;
F_34 ( V_47 , V_91 , V_56 , 15 , 1 , V_51 & 128 ) ;
if ( V_38 > 2 ) {
F_35 ( V_38 , V_56 , V_47 ) ;
}
}
if ( V_39 > V_38 ) {
F_36 ( V_47 , V_11 , & V_92 , V_56 , V_43 + V_38 , V_39 - V_38 ) ;
}
if ( V_53 ) {
F_36 ( V_47 , V_11 , & V_93 , V_56 , V_43 + 18 , 8 ) ;
}
}
V_52 = F_18 ( V_56 , V_43 + V_39 + V_53 ) ;
switch ( V_37 ) {
case 0 :
F_37 ( V_94 , V_52 , V_11 , V_46 ) ;
break;
case 1 :
F_37 ( V_95 , V_52 , V_11 , V_46 ) ;
break;
default:
F_37 ( V_96 , V_52 , V_11 , V_46 ) ;
break;
}
F_38 ( V_97 , V_11 , V_59 ) ;
}
static void
F_35 ( int V_98 , T_9 * V_28 , T_14 * V_46 )
{
T_15 * V_49 ;
int V_99 ;
int V_100 , V_101 , V_102 ;
#define F_39 16
#define F_40 30
T_16 * V_103 ;
#define F_41 3 + (RIF_BYTES_TO_PROCESS / 2) * 6 + 1
V_103 = F_42 ( F_43 () ,
F_41 , F_41 ) ;
V_102 = V_98 - F_40 ;
V_98 = F_44 ( V_98 , F_40 ) ;
V_98 -= 2 ;
for( V_99 = 1 ; V_99 < V_98 - 1 ; V_99 += 2 ) {
if ( V_99 == 1 ) {
V_100 = F_23 ( V_28 , F_39 ) >> 4 ;
F_45 ( V_103 , L_10 , V_100 ) ;
V_49 = F_34 ( V_46 , V_104 , V_28 , V_43 + 2 , 2 , V_100 ) ;
F_32 ( V_49 ) ;
}
V_100 = F_23 ( V_28 , F_39 + 1 + V_99 ) >> 4 ;
V_101 = F_19 ( V_28 , F_39 + V_99 ) & 0x0f ;
F_45 ( V_103 , L_11 , V_101 , V_100 ) ;
V_49 = F_34 ( V_46 , V_104 , V_28 , V_43 + 3 + V_99 , 2 , V_100 ) ;
F_32 ( V_49 ) ;
V_49 = F_34 ( V_46 , V_105 , V_28 , V_43 + 2 + V_99 , 1 , V_101 ) ;
F_32 ( V_49 ) ;
}
F_46 ( V_46 , V_106 , V_28 , V_43 + 2 , V_98 , F_47 ( V_103 ) ) ;
if ( V_102 > 0 ) {
F_28 ( V_46 , V_107 , V_28 , V_43 + F_40 , V_102 , V_78 ) ;
}
}
void
F_48 ( void )
{
static T_17 V_108 [] = {
{ & V_80 ,
{ L_12 , L_13 , V_109 , V_110 , NULL , 0x0 ,
NULL , V_111 } } ,
{ & V_70 ,
{ L_14 , L_15 , V_109 , V_112 , NULL , 0xe0 ,
NULL , V_111 } } ,
{ & V_71 ,
{ L_16 , L_17 , V_113 , 8 , F_49 ( & V_114 ) , 0x10 ,
NULL , V_111 } } ,
{ & V_72 ,
{ L_18 , L_19 , V_109 , V_112 , NULL , 0x08 ,
NULL , V_111 } } ,
{ & V_73 ,
{ L_20 , L_21 , V_109 , V_112 , NULL , 0x07 ,
NULL , V_111 } } ,
{ & V_82 ,
{ L_22 , L_23 , V_109 , V_110 , NULL , 0x0 ,
NULL , V_111 } } ,
{ & V_75 ,
{ L_24 , L_25 , V_109 , V_112 , F_50 ( V_115 ) , 0xc0 ,
NULL , V_111 } } ,
{ & V_76 ,
{ L_26 , L_27 , V_109 , V_112 , F_50 ( V_116 ) , 0x0f ,
NULL , V_111 } } ,
{ & V_84 ,
{ L_28 , L_2 , V_117 , V_118 , NULL , 0x0 ,
L_29 , V_111 } } ,
{ & V_85 ,
{ L_30 , L_1 , V_117 , V_118 , NULL , 0x0 ,
L_31 , V_111 } } ,
{ & V_86 ,
{ L_32 , L_3 , V_117 , V_118 , NULL , 0x0 ,
L_33 , V_111 } } ,
{ & V_87 ,
{ L_34 , L_35 , V_113 , V_118 , NULL , 0x0 ,
NULL , V_111 } } ,
{ & V_88 ,
{ L_36 , L_37 , V_109 , V_112 , NULL , 0x0 ,
L_38 , V_111 } } ,
{ & V_89 ,
{ L_39 , L_40 , V_109 , V_112 , F_50 ( V_119 ) , 0x0 ,
L_41 , V_111 } } ,
{ & V_90 ,
{ L_42 , L_43 , V_109 , V_112 , F_50 ( V_120 ) ,
0x0 ,
NULL , V_111 } } ,
{ & V_91 ,
{ L_44 , L_45 , V_109 , V_112 , F_50 ( V_121 ) , 0x0 ,
L_46 , V_111 } } ,
{ & V_106 ,
{ L_47 , L_48 , V_122 , V_118 , NULL , 0x0 ,
L_49 , V_111 } } ,
{ & V_104 ,
{ L_50 , L_51 , V_123 , V_110 , NULL , 0x0 ,
NULL , V_111 } } ,
{ & V_105 ,
{ L_52 , L_53 , V_109 , V_110 , NULL , 0x0 ,
NULL , V_111 } } ,
{ & V_107 ,
{ L_54 , L_55 , V_124 , V_118 , NULL , 0x0 ,
NULL , V_111 } } ,
} ;
static T_18 * V_125 [] = {
& V_79 ,
& V_81 ,
& V_83 ,
} ;
static T_19 V_126 [] = {
{ & V_92 , { L_56 , V_127 , V_128 , L_57 , V_129 } } ,
{ & V_93 , { L_58 , V_127 , V_128 , L_59 , V_129 } } ,
} ;
T_20 * V_130 ;
T_21 * V_131 ;
V_77 = F_51 ( L_60 , L_60 , L_61 ) ;
F_52 ( V_77 , V_108 , F_53 ( V_108 ) ) ;
F_54 ( V_125 , F_53 ( V_125 ) ) ;
V_131 = F_55 ( V_77 ) ;
F_56 ( V_131 , V_126 , F_53 ( V_126 ) ) ;
V_130 = F_57 ( V_77 , NULL ) ;
F_58 ( V_130 , L_62 ,
L_63 ,
L_64 ,
& V_45 ) ;
F_59 ( L_61 , F_15 , V_77 ) ;
V_97 = F_60 ( L_61 ) ;
F_61 ( V_77 , TRUE , F_2 , F_5 ) ;
}
void
F_62 ( void )
{
T_22 V_132 ;
V_94 = F_63 ( L_65 ) ;
V_95 = F_63 ( L_66 ) ;
V_96 = F_63 ( L_67 ) ;
V_132 = F_63 ( L_61 ) ;
F_64 ( L_68 , V_133 , V_132 ) ;
F_64 ( L_69 , V_134 , V_132 ) ;
}
