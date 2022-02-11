static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_3 , V_4 ) ;
if ( F_3 ( V_5 != 0 ) )
return - V_7 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
int V_5 ;
V_5 = F_5 ( V_2 -> V_6 , V_3 , V_4 ) ;
if ( F_3 ( V_5 != 0 ) )
return - V_7 ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 ,
T_1 V_8 )
{
int V_9 ;
int V_10 = 0 ;
T_2 V_11 ;
T_2 V_12 ;
T_2 V_13 ;
T_1 V_14 ;
V_12 = ( V_8 * V_15 ) + V_16 ;
while ( 1 ) {
V_9 = F_1 ( V_2 , V_17 ,
( V_12 & 0x0000F000 ) >> 12 ) ;
if ( V_9 )
goto error;
V_9 = F_1 ( V_2 , V_18 ,
( V_12 & 0x00FF0000 ) >> 16 ) ;
if ( V_9 )
goto error;
V_9 = F_1 ( V_2 , V_19 ,
( V_12 & 0xFF000000 ) >> 24 ) ;
if ( V_9 )
goto error;
V_13 = 0 ;
V_9 = F_4 ( V_2 , V_17 , & V_14 ) ;
if ( V_9 )
goto error;
V_13 |= ( ( T_2 ) ( V_14 & 0x0F ) ) << 12 ;
V_9 = F_4 ( V_2 , V_18 , & V_14 ) ;
if ( V_9 )
goto error;
V_13 |= ( ( T_2 ) V_14 ) << 16 ;
V_9 = F_4 ( V_2 , V_19 , & V_14 ) ;
if ( V_9 )
goto error;
V_13 |= ( ( T_2 ) V_14 ) << 24 ;
V_11 = ( V_13 - V_16 ) / V_15 ;
if ( V_11 == V_8 )
break;
V_9 = - V_20 ;
if ( V_10 ++ > V_21 )
goto error;
F_7 ( 10 ) ;
}
return 0 ;
error:
F_8 ( L_1 , V_8 ) ;
return V_9 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
int V_9 ;
#if V_24
F_10 ( L_2 ,
F_11 ( V_23 -> V_25 . V_26 ) ,
V_23 -> V_27 ) ;
#endif
V_9 = F_6 ( V_2 , V_23 -> V_27 ) ;
if ( ! V_9 )
V_2 -> V_28 = V_23 ;
return V_9 ;
}
int F_12 ( struct V_1 * V_2 , T_1 V_29 )
{
int V_10 = 0 ;
int V_9 ;
T_1 V_14 ;
F_13 ( ( V_29 != 0 ) && ( V_29 != 1 ) ) ;
while ( 1 ) {
V_9 = F_1 ( V_2 , V_30 , V_29 ) ;
if ( V_9 )
goto error;
V_9 = F_4 ( V_2 , V_30 , & V_14 ) ;
if ( V_9 )
goto error;
if ( V_14 == V_29 )
break;
V_9 = - V_20 ;
if ( F_3 ( V_10 ++ > V_21 ) )
goto error;
F_7 ( 10 ) ;
}
V_2 -> V_31 = V_29 ;
return 0 ;
error:
F_8 ( L_3 ) ;
return V_9 ;
}
static int F_14 ( struct V_22 * V_23 ,
T_3 * V_3 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
int V_9 ;
T_1 V_32 ;
if ( * V_3 >= 0x800 ) {
* V_3 -= 0x800 ;
V_32 = 1 ;
} else
V_32 = 0 ;
if ( F_3 ( V_23 != V_2 -> V_28 ) ) {
V_9 = F_9 ( V_2 , V_23 ) ;
if ( F_3 ( V_9 ) )
return V_9 ;
}
if ( F_3 ( V_32 != V_2 -> V_31 ) ) {
V_9 = F_12 ( V_2 , V_32 ) ;
if ( F_3 ( V_9 ) )
return V_9 ;
}
return 0 ;
}
static T_1 F_15 ( struct V_22 * V_23 , T_3 V_3 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
unsigned long V_33 ;
int V_9 ;
T_1 V_4 = 0xFF ;
F_16 ( & V_2 -> V_34 , V_33 ) ;
V_9 = F_14 ( V_23 , & V_3 ) ;
if ( F_17 ( ! V_9 ) )
V_4 = F_18 ( V_2 -> V_35 + V_3 ) ;
F_19 ( & V_2 -> V_34 , V_33 ) ;
return V_4 ;
}
static T_3 F_20 ( struct V_22 * V_23 , T_3 V_3 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
unsigned long V_33 ;
int V_9 ;
T_3 V_4 = 0xFFFF ;
F_16 ( & V_2 -> V_34 , V_33 ) ;
V_9 = F_14 ( V_23 , & V_3 ) ;
if ( F_17 ( ! V_9 ) )
V_4 = F_21 ( V_2 -> V_35 + V_3 ) ;
F_19 ( & V_2 -> V_34 , V_33 ) ;
return V_4 ;
}
static T_2 F_22 ( struct V_22 * V_23 , T_3 V_3 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
unsigned long V_33 ;
int V_9 ;
T_2 V_36 = 0xFFFFFFFF , V_37 = 0xFFFFFFFF ;
F_16 ( & V_2 -> V_34 , V_33 ) ;
V_9 = F_14 ( V_23 , & V_3 ) ;
if ( F_17 ( ! V_9 ) ) {
V_36 = F_21 ( V_2 -> V_35 + V_3 ) ;
V_37 = F_21 ( V_2 -> V_35 + V_3 + 2 ) ;
}
F_19 ( & V_2 -> V_34 , V_33 ) ;
return ( V_36 | ( V_37 << 16 ) ) ;
}
static void F_23 ( struct V_22 * V_23 , void * V_38 ,
T_4 V_39 , T_3 V_3 , T_1 V_40 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
unsigned long V_33 ;
void T_5 * V_12 = V_2 -> V_35 + V_3 ;
int V_9 ;
F_16 ( & V_2 -> V_34 , V_33 ) ;
V_9 = F_14 ( V_23 , & V_3 ) ;
if ( F_3 ( V_9 ) ) {
memset ( V_38 , 0xFF , V_39 ) ;
goto V_41;
}
switch ( V_40 ) {
case sizeof( T_1 ) : {
T_1 * V_42 = V_38 ;
while ( V_39 ) {
* V_42 = F_24 ( V_12 ) ;
V_42 ++ ;
V_39 -- ;
}
break;
}
case sizeof( T_3 ) : {
T_6 * V_42 = V_38 ;
F_13 ( V_39 & 1 ) ;
while ( V_39 ) {
* V_42 = ( V_43 T_6 ) F_25 ( V_12 ) ;
V_42 ++ ;
V_39 -= 2 ;
}
break;
}
case sizeof( T_2 ) : {
T_6 * V_42 = V_38 ;
F_13 ( V_39 & 3 ) ;
while ( V_39 ) {
* V_42 = ( V_43 T_6 ) F_25 ( V_12 ) ;
V_42 ++ ;
* V_42 = ( V_43 T_6 ) F_25 ( V_12 + 2 ) ;
V_42 ++ ;
V_39 -= 4 ;
}
break;
}
default:
F_13 ( 1 ) ;
}
V_41:
F_19 ( & V_2 -> V_34 , V_33 ) ;
}
static void F_26 ( struct V_22 * V_23 , T_3 V_3 , T_1 V_4 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
unsigned long V_33 ;
int V_9 ;
F_16 ( & V_2 -> V_34 , V_33 ) ;
V_9 = F_14 ( V_23 , & V_3 ) ;
if ( F_17 ( ! V_9 ) )
F_27 ( V_4 , V_2 -> V_35 + V_3 ) ;
F_28 () ;
F_19 ( & V_2 -> V_34 , V_33 ) ;
}
static void F_29 ( struct V_22 * V_23 , T_3 V_3 , T_3 V_4 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
unsigned long V_33 ;
int V_9 ;
F_16 ( & V_2 -> V_34 , V_33 ) ;
V_9 = F_14 ( V_23 , & V_3 ) ;
if ( F_17 ( ! V_9 ) )
F_30 ( V_4 , V_2 -> V_35 + V_3 ) ;
F_28 () ;
F_19 ( & V_2 -> V_34 , V_33 ) ;
}
static void F_31 ( struct V_22 * V_23 , T_3 V_3 , T_2 V_4 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
unsigned long V_33 ;
int V_9 ;
F_16 ( & V_2 -> V_34 , V_33 ) ;
V_9 = F_14 ( V_23 , & V_3 ) ;
if ( F_17 ( ! V_9 ) ) {
F_30 ( ( V_4 & 0x0000FFFF ) , V_2 -> V_35 + V_3 ) ;
F_30 ( ( ( V_4 & 0xFFFF0000 ) >> 16 ) , V_2 -> V_35 + V_3 + 2 ) ;
}
F_28 () ;
F_19 ( & V_2 -> V_34 , V_33 ) ;
}
static void F_32 ( struct V_22 * V_23 , const void * V_38 ,
T_4 V_39 , T_3 V_3 , T_1 V_40 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
unsigned long V_33 ;
void T_5 * V_12 = V_2 -> V_35 + V_3 ;
int V_9 ;
F_16 ( & V_2 -> V_34 , V_33 ) ;
V_9 = F_14 ( V_23 , & V_3 ) ;
if ( F_3 ( V_9 ) )
goto V_41;
switch ( V_40 ) {
case sizeof( T_1 ) : {
const T_1 * V_42 = V_38 ;
while ( V_39 ) {
F_33 ( * V_42 , V_12 ) ;
V_42 ++ ;
V_39 -- ;
}
break;
}
case sizeof( T_3 ) : {
const T_6 * V_42 = V_38 ;
F_13 ( V_39 & 1 ) ;
while ( V_39 ) {
F_34 ( ( V_43 T_3 ) ( * V_42 ) , V_12 ) ;
V_42 ++ ;
V_39 -= 2 ;
}
break;
}
case sizeof( T_2 ) : {
const T_6 * V_42 = V_38 ;
F_13 ( V_39 & 3 ) ;
while ( V_39 ) {
F_34 ( ( V_43 T_3 ) ( * V_42 ) , V_12 ) ;
V_42 ++ ;
F_34 ( ( V_43 T_3 ) ( * V_42 ) , V_12 + 2 ) ;
V_42 ++ ;
V_39 -= 4 ;
}
break;
}
default:
F_13 ( 1 ) ;
}
V_41:
F_28 () ;
F_19 ( & V_2 -> V_34 , V_33 ) ;
}
static int F_35 ( struct V_1 * V_2 , T_1 V_44 )
{
unsigned int V_45 ;
int V_9 ;
T_1 V_4 ;
V_9 = F_1 ( V_2 , V_46 , V_44 ) ;
if ( V_9 )
return V_9 ;
for ( V_45 = 0 ; V_45 < 1000 ; V_45 ++ ) {
V_9 = F_4 ( V_2 , V_46 , & V_4 ) ;
if ( V_9 )
return V_9 ;
if ( V_4 & V_47 )
return 0 ;
F_7 ( 10 ) ;
}
return - V_20 ;
}
static int F_36 ( struct V_1 * V_2 , T_3 V_3 , T_3 * V_4 )
{
int V_9 ;
T_1 V_36 , V_37 ;
V_3 *= 2 ;
V_9 = F_1 ( V_2 , V_48 ,
( V_3 & 0x00FF ) ) ;
if ( V_9 )
return V_9 ;
V_9 = F_1 ( V_2 , V_49 ,
( V_3 & 0xFF00 ) >> 8 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_35 ( V_2 , V_50 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_4 ( V_2 , V_51 , & V_36 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_4 ( V_2 , V_52 , & V_37 ) ;
if ( V_9 )
return V_9 ;
* V_4 = ( V_36 | ( ( ( T_3 ) V_37 ) << 8 ) ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , T_3 V_3 , T_3 V_4 )
{
int V_9 ;
V_3 *= 2 ;
V_9 = F_1 ( V_2 , V_48 ,
( V_3 & 0x00FF ) ) ;
if ( V_9 )
return V_9 ;
V_9 = F_1 ( V_2 , V_49 ,
( V_3 & 0xFF00 ) >> 8 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_1 ( V_2 , V_51 ,
( V_4 & 0x00FF ) ) ;
if ( V_9 )
return V_9 ;
V_9 = F_1 ( V_2 , V_52 ,
( V_4 & 0xFF00 ) >> 8 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_35 ( V_2 , V_53 ) ;
if ( V_9 )
return V_9 ;
F_38 ( 20 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , T_3 * V_54 )
{
int V_9 , V_45 ;
for ( V_45 = 0 ; V_45 < V_55 ; V_45 ++ ) {
V_9 = F_36 ( V_2 , V_45 , & V_54 [ V_45 ] ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , const T_3 * V_54 )
{
int V_45 , V_9 ;
bool V_56 = 0 ;
T_4 V_57 = V_55 ;
F_41 ( L_4 ) ;
V_9 = F_35 ( V_2 , V_58 ) ;
if ( V_9 ) {
F_41 ( L_5 ) ;
return - V_7 ;
}
F_41 ( L_6 ) ;
F_38 ( 500 ) ;
for ( V_45 = 0 ; V_45 < V_57 ; V_45 ++ ) {
if ( V_45 == V_57 / 4 )
F_42 ( L_7 ) ;
else if ( V_45 == V_57 / 2 )
F_42 ( L_8 ) ;
else if ( V_45 == ( V_57 * 3 ) / 4 )
F_42 ( L_9 ) ;
else if ( V_45 % 2 )
F_42 ( L_10 ) ;
V_9 = F_37 ( V_2 , V_45 , V_54 [ V_45 ] ) ;
if ( V_9 ) {
F_41 ( L_11 ) ;
V_56 = 1 ;
break;
}
}
V_9 = F_35 ( V_2 , V_59 ) ;
if ( V_9 ) {
F_41 ( L_12 ) ;
V_56 = 1 ;
}
F_38 ( 500 ) ;
if ( ! V_56 ) {
F_42 ( L_13 ) ;
F_41 ( L_14 ) ;
}
return V_56 ? - V_7 : 0 ;
}
static int F_43 ( const T_3 * V_54 , T_4 V_57 )
{
return 0 ;
}
static int F_44 ( struct V_60 * V_61 ,
T_7 * V_62 ,
void * V_63 )
{
struct V_64 * V_54 = V_63 ;
if ( V_62 -> V_65 [ 0 ] != V_66 )
return - V_67 ;
if ( V_62 -> V_68 != V_69 + 2 )
return - V_67 ;
if ( V_62 -> V_65 [ 1 ] != V_69 )
return - V_67 ;
memcpy ( V_54 -> V_70 , & V_62 -> V_65 [ 2 ] , V_69 ) ;
return 0 ;
}
static int F_45 ( struct V_60 * V_61 ,
T_7 * V_62 ,
void * V_63 )
{
struct V_71 * V_72 = V_63 ;
struct V_64 * V_54 = & V_72 -> V_54 ;
struct V_73 * V_74 = & V_72 -> V_75 ;
const char * V_76 ;
F_46 ( V_62 -> V_68 < 1 , L_15 ) ;
switch ( V_62 -> V_65 [ 0 ] ) {
case V_77 :
F_46 ( ( V_62 -> V_68 != 5 ) &&
( V_62 -> V_68 != 7 ) ,
L_16 ) ;
V_74 -> V_78 = V_62 -> V_65 [ 1 ] |
( ( T_3 ) V_62 -> V_65 [ 2 ] << 8 ) ;
break;
case V_79 :
F_46 ( V_62 -> V_68 != 2 ,
L_17 ) ;
V_54 -> V_80 = V_62 -> V_65 [ 1 ] ;
break;
case V_81 :
F_46 ( ( V_62 -> V_68 != 9 ) &&
( V_62 -> V_68 != 10 ) ,
L_18 ) ;
V_54 -> V_82 = V_62 -> V_65 [ 1 ] |
( ( T_3 ) V_62 -> V_65 [ 2 ] << 8 ) ;
V_54 -> V_83 = V_62 -> V_65 [ 3 ] |
( ( T_3 ) V_62 -> V_65 [ 4 ] << 8 ) ;
V_54 -> V_84 = V_62 -> V_65 [ 5 ] |
( ( T_3 ) V_62 -> V_65 [ 6 ] << 8 ) ;
V_54 -> V_85 = V_62 -> V_65 [ 7 ] ;
V_54 -> V_86 = V_62 -> V_65 [ 7 ] ;
V_54 -> V_87 = V_62 -> V_65 [ 8 ] ;
V_54 -> V_88 = V_62 -> V_65 [ 8 ] ;
break;
case V_89 :
break;
case V_90 :
F_46 ( V_62 -> V_68 != 2 ,
L_19 ) ;
V_54 -> V_91 = V_62 -> V_65 [ 1 ] ;
break;
case V_92 :
F_46 ( V_62 -> V_68 != 2 ,
L_20 ) ;
V_54 -> V_93 = V_62 -> V_65 [ 1 ] ;
V_54 -> V_94 = V_62 -> V_65 [ 1 ] ;
break;
case V_95 :
F_46 ( V_62 -> V_68 != 2 ,
L_21 ) ;
V_54 -> V_96 . V_97 = V_62 -> V_65 [ 1 ] ;
V_54 -> V_96 . V_98 = V_62 -> V_65 [ 1 ] ;
V_54 -> V_96 . V_99 = V_62 -> V_65 [ 1 ] ;
V_54 -> V_96 . V_100 = V_62 -> V_65 [ 1 ] ;
break;
case V_101 :
F_46 ( ( V_62 -> V_68 != 3 ) &&
( V_62 -> V_68 != 5 ) ,
L_22 ) ;
V_54 -> V_102 = V_62 -> V_65 [ 1 ] |
( ( T_3 ) V_62 -> V_65 [ 2 ] << 8 ) ;
break;
case V_103 :
F_46 ( V_62 -> V_68 != 5 ,
L_23 ) ;
V_54 -> V_104 = V_62 -> V_65 [ 1 ] ;
V_54 -> V_105 = V_62 -> V_65 [ 2 ] ;
V_54 -> V_106 = V_62 -> V_65 [ 3 ] ;
V_54 -> V_107 = V_62 -> V_65 [ 4 ] ;
break;
}
return - V_108 ;
error:
F_8 (
L_24 ,
V_76 ) ;
return - V_109 ;
}
int F_47 ( struct V_1 * V_2 ,
struct V_71 * V_72 )
{
struct V_64 * V_54 = & V_72 -> V_54 ;
int V_5 ;
memset ( V_54 , 0xFF , sizeof( * V_54 ) ) ;
V_54 -> V_110 = 1 ;
V_54 -> V_102 = 0 ;
V_54 -> V_111 = 0 ;
V_5 = F_48 ( V_2 -> V_6 , V_112 ,
F_44 , V_54 ) ;
if ( V_5 != 0 ) {
F_8 (
L_25 ) ;
return - V_109 ;
}
V_5 = F_48 ( V_2 -> V_6 , V_113 ,
F_45 , V_72 ) ;
if ( ( V_5 == 0 ) || ( V_5 == - V_108 ) )
return 0 ;
F_8 (
L_26 ) ;
return - V_109 ;
}
static T_8 F_49 ( struct V_114 * V_115 ,
struct V_116 * V_117 ,
char * V_42 )
{
struct V_60 * V_118 =
F_50 ( V_115 , struct V_60 , V_23 ) ;
struct V_1 * V_2 ;
V_2 = F_51 ( V_118 ) ;
if ( ! V_2 )
return - V_109 ;
return F_52 ( V_2 , V_42 ,
F_39 ) ;
}
static T_8 F_53 ( struct V_114 * V_115 ,
struct V_116 * V_117 ,
const char * V_42 , T_4 V_39 )
{
struct V_60 * V_118 =
F_50 ( V_115 , struct V_60 , V_23 ) ;
struct V_1 * V_2 ;
V_2 = F_51 ( V_118 ) ;
if ( ! V_2 )
return - V_109 ;
return F_54 ( V_2 , V_42 , V_39 ,
F_43 ,
F_40 ) ;
}
static int F_55 ( struct V_1 * V_2 , T_1 V_119 )
{
T_1 V_14 ;
int V_9 ;
V_9 = F_4 ( V_2 , V_119 , & V_14 ) ;
if ( V_9 )
return V_9 ;
V_14 &= ~ V_120 ;
V_14 |= V_121 | V_122 | V_123 ;
V_9 = F_1 ( V_2 , V_119 , V_14 ) ;
if ( V_9 )
return V_9 ;
F_38 ( 40 ) ;
return 0 ;
}
int F_56 ( struct V_1 * V_2 )
{
int V_9 ;
if ( V_2 -> V_124 != V_125 )
return 0 ;
F_12 ( V_2 , 0 ) ;
V_9 = F_55 ( V_2 , V_126 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_55 ( V_2 , V_126 + 0x80 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
void F_57 ( struct V_1 * V_2 )
{
if ( V_2 -> V_124 != V_125 )
return;
F_58 ( & V_2 -> V_6 -> V_23 , & V_127 ) ;
}
int F_59 ( struct V_1 * V_2 )
{
int V_9 ;
if ( V_2 -> V_124 != V_125 )
return 0 ;
V_9 = F_56 ( V_2 ) ;
if ( V_9 )
goto error;
V_2 -> V_128 = V_55 ;
F_60 ( & V_2 -> V_129 ) ;
V_9 = F_61 ( & V_2 -> V_6 -> V_23 , & V_127 ) ;
if ( V_9 )
goto error;
return 0 ;
error:
F_8 ( L_27 ) ;
return V_9 ;
}
