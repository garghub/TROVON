static unsigned char T_1 F_1 ( unsigned char V_1 )
{
switch ( V_1 ) {
case 0x81 ... 0x89 :
return V_1 - 0x81 + 'a' ;
case 0x91 ... 0x99 :
return V_1 - 0x91 + 'j' ;
case 0xA2 ... 0xA9 :
return V_1 - 0xA2 + 's' ;
case 0xC1 ... 0xC9 :
return V_1 - 0xC1 + 'A' ;
case 0xD1 ... 0xD9 :
return V_1 - 0xD1 + 'J' ;
case 0xE2 ... 0xE9 :
return V_1 - 0xE2 + 'S' ;
case 0xF0 ... 0xF9 :
return V_1 - 0xF0 + '0' ;
}
return ' ' ;
}
static unsigned char * T_1 F_2 ( unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
int V_5 ;
V_4 = F_3 ( V_3 , V_4 ) ;
for ( V_5 = 0 ; V_5 < V_4 ; V_5 ++ )
V_2 [ V_5 ] = F_1 ( V_3 [ V_5 ] ) ;
return V_2 ;
}
static struct V_6 * T_1 F_4 ( void )
{
struct V_6 * V_7 ;
unsigned long V_8 ;
V_8 = V_9 - V_10 ;
V_7 = (struct V_6 * ) F_5 ( V_11 , 8 ) ;
V_7 -> V_12 . V_13 =
F_6 ( struct V_6 , V_14 ) ;
V_7 -> V_12 . V_15 = F_5 ( sizeof( * V_7 ) , 8 ) ;
V_7 -> V_12 . V_16 = V_7 -> V_12 . V_15
+ F_5 ( V_8 , 8 ) ;
V_17 = ( void * ) ( ( unsigned long ) V_7 + V_7 -> V_12 . V_16 ) ;
V_7 -> V_12 . V_18 = V_8 ;
V_7 -> V_12 . V_19 = F_7 () ;
memcpy ( ( char * ) V_7 + V_7 -> V_12 . V_15 , V_10 ,
V_8 ) ;
V_7 -> V_12 . V_20 = V_21 ;
V_7 -> V_12 . V_22 = 0x10 ;
V_7 -> V_12 . V_23 = 0x10 ;
V_7 -> V_14 [ 0 ] = 0 ;
V_7 -> V_14 [ 1 ] = 0 ;
return V_7 ;
}
static void T_1 F_8 ( struct V_6 * V_7 , T_3 V_24 )
{
* ( ( T_3 * ) V_17 ) = V_24 ;
V_17 += sizeof( T_3 ) ;
}
static void T_1 F_9 ( struct V_6 * V_7 , T_4 V_24 )
{
* ( ( T_4 * ) V_17 ) = V_24 ;
V_17 += sizeof( T_4 ) ;
}
static void T_1 F_10 ( struct V_6 * V_7 , const char * V_25 ,
int V_26 )
{
memcpy ( V_17 , V_25 , V_26 ) ;
V_17 += F_5 ( V_26 , 4 ) ;
}
static void T_1 F_11 ( struct V_6 * V_7 , const char * V_27 )
{
F_8 ( V_7 , V_28 ) ;
F_10 ( V_7 , V_27 , strlen ( V_27 ) + 1 ) ;
}
static void T_1 F_12 ( struct V_6 * V_7 , const char * V_27 ,
const void * V_25 , int V_26 )
{
unsigned long V_29 ;
F_8 ( V_7 , V_30 ) ;
F_8 ( V_7 , V_26 ) ;
V_29 = V_27 - V_10 ;
F_8 ( V_7 , ( T_3 ) V_29 ) ;
F_10 ( V_7 , V_25 , V_26 ) ;
}
static void T_1 F_13 ( struct V_6 * V_7 , const char * V_27 ,
T_3 V_25 )
{
F_12 ( V_7 , V_27 , & V_25 , sizeof( T_3 ) ) ;
}
static void T_1 T_5 F_14 ( struct V_6 * V_7 ,
const char * V_27 , T_4 V_25 )
{
F_12 ( V_7 , V_27 , & V_25 , sizeof( T_4 ) ) ;
}
static void T_1 F_15 ( struct V_6 * V_7 )
{
unsigned char V_31 [ 32 ] ;
unsigned char * V_32 ;
unsigned int V_5 , V_33 ;
struct V_34 * V_35 ;
T_3 V_36 [ 2 ] ;
snprintf ( V_31 , 32 , L_1 , V_37 -> V_38 ) ;
V_32 = strchr ( V_31 , ' ' ) ;
if ( ! V_32 ) V_32 = V_31 + strlen ( V_31 ) ;
F_11 ( V_7 , L_2 ) ;
F_16 ( V_7 , L_3 , 1 ) ;
F_16 ( V_7 , L_4 , 0 ) ;
V_36 [ 0 ] = 0 ;
V_36 [ 1 ] = F_17 ( F_18 () * V_39 ) ;
for ( V_5 = 0 ; V_5 < V_40 ; V_5 ++ ) {
if ( V_41 [ V_5 ] . V_42 >= 2 )
continue;
snprintf ( V_32 , 32 - ( V_32 - V_31 ) , L_5 , V_5 ) ;
F_11 ( V_7 , V_31 ) ;
F_19 ( V_7 , L_6 , V_43 ) ;
V_33 = V_41 [ V_5 ] . V_44 ;
V_35 = & V_45 [ V_33 ] ;
F_16 ( V_7 , L_7 , V_35 -> V_46 * 1024 ) ;
F_16 ( V_7 , L_8 , V_35 -> V_47 ) ;
F_16 ( V_7 , L_9 , V_35 -> V_48 * 1024 ) ;
F_16 ( V_7 , L_10 , V_35 -> V_49 ) ;
F_16 ( V_7 , L_11 ,
( ( 1UL << 34 ) * 1000000 ) / V_35 -> V_50 ) ;
F_16 ( V_7 , L_12 ,
( ( 1UL << 32 ) * 1000000 ) / V_35 -> V_51 ) ;
F_16 ( V_7 , L_13 , V_5 ) ;
F_20 ( V_7 , L_14 , V_36 , 2 ) ;
F_21 ( V_7 ) ;
}
F_21 ( V_7 ) ;
}
static void T_1 F_22 ( struct V_6 * V_7 )
{
char V_31 [ 16 ] = L_15 ;
F_2 ( V_31 + 4 , V_52 . V_53 + 2 , 2 ) ;
F_2 ( V_31 + 6 , V_52 . V_54 + 1 , 5 ) ;
V_31 [ 11 ] = '\0' ;
F_19 ( V_7 , L_16 , V_31 ) ;
F_2 ( V_31 + 4 , V_52 . V_55 , 4 ) ;
V_31 [ 8 ] = '\0' ;
F_19 ( V_7 , L_17 , V_31 ) ;
F_19 ( V_7 , L_18 , L_19 ) ;
F_16 ( V_7 , L_20 , F_23 () ) ;
}
static void T_1 F_24 ( struct V_6 * V_7 )
{
#ifdef F_25
if ( V_56 . V_57 ) {
F_26 ( V_7 , L_21 , ( T_4 ) V_56 . V_57 ) ;
F_26 ( V_7 , L_22 ,
( T_4 ) V_56 . V_57 + V_56 . V_58 * V_39 ) ;
}
#endif
}
static void T_1 F_27 ( struct V_6 * V_7 ,
const char * V_27 , T_3 V_59 , int V_60 ,
const char * type , const char * V_61 , int V_62 )
{
char V_31 [ 32 ] ;
snprintf ( V_31 , 32 , L_23 , V_27 , V_59 + ( ( V_60 >= 0 ) ? V_60 : 0 ) ) ;
F_11 ( V_7 , V_31 ) ;
F_19 ( V_7 , L_6 , type ) ;
if ( V_61 )
F_19 ( V_7 , L_18 , V_61 ) ;
F_16 ( V_7 , L_13 , V_59 + ( ( V_60 >= 0 ) ? V_60 : 0 ) ) ;
if ( V_60 >= 0 )
F_16 ( V_7 , L_24 , V_60 ) ;
if ( V_62 )
F_21 ( V_7 ) ;
}
static void T_1 F_28 ( struct V_6 * V_7 )
{
T_3 V_59 = 0 ;
T_6 V_63 ;
int V_5 ;
F_11 ( V_7 , L_25 ) ;
F_19 ( V_7 , L_6 , V_64 ) ;
F_19 ( V_7 , L_18 , L_26 ) ;
F_16 ( V_7 , L_3 , 1 ) ;
F_16 ( V_7 , L_4 , 0 ) ;
F_27 ( V_7 , L_27 , V_59 , - 1 , V_65 ,
L_28 , 1 ) ;
V_59 ++ ;
F_27 ( V_7 , L_29 , V_59 , - 1 , V_66 ,
L_30 , 1 ) ;
V_59 ++ ;
V_63 = F_29 () ;
for ( V_5 = 0 ; V_5 < V_67 ; V_5 ++ ) {
unsigned char V_68 [ V_69 ] ;
if ( ( V_63 & ( 0x8000 >> V_5 ) ) == 0 )
continue;
F_27 ( V_7 , L_31 , V_59 , V_5 , V_70 ,
L_32 , 0 ) ;
V_68 [ 0 ] = 0x02 ;
V_68 [ 1 ] = 0x01 ;
V_68 [ 2 ] = 0xff ;
V_68 [ 3 ] = V_5 ;
V_68 [ 4 ] = 0xff ;
V_68 [ 5 ] = F_30 () ;
F_31 ( V_7 , L_33 , ( char * ) V_68 , V_69 ) ;
F_31 ( V_7 , L_34 , ( char * ) V_68 , V_69 ) ;
F_16 ( V_7 , L_35 , 9000 ) ;
F_16 ( V_7 , L_36 , 48 ) ;
F_21 ( V_7 ) ;
}
F_21 ( V_7 ) ;
}
static struct V_71 * T_1 F_32 ( T_7 V_72 )
{
struct V_71 * V_73 ;
for ( V_73 = V_71 ;
V_73 < & V_71 [ F_33 ( V_71 ) ] ; V_73 ++ )
if ( V_73 -> V_74 == V_72 )
return V_73 ;
return NULL ;
}
static void T_1 F_34 ( struct V_6 * V_7 ,
T_8 V_75 , struct V_76 * V_77 )
{
T_9 V_78 = V_77 -> V_79 ;
T_7 V_80 ;
T_7 V_81 ;
T_3 V_82 ;
int V_83 ;
char V_31 [ 32 ] ;
T_3 V_59 [ 5 ] ;
int V_84 = F_35 ( V_78 ) ;
int V_85 = F_36 ( V_78 ) ;
T_10 V_86 = F_37 ( V_84 , V_85 ) ;
T_11 V_87 ;
struct V_71 * V_73 ;
for ( V_84 = 1 ; V_84 <= V_77 -> V_88 ; V_84 ++ ) {
for ( V_85 = 0 ; V_85 < 8 ; V_85 ++ ) {
T_10 V_89 = F_37 ( V_84 ,
V_85 ) ;
V_83 = F_38 ( V_75 , V_78 ,
V_89 , 0 ) ;
if ( V_83 ) {
if ( V_83 != 0x302 )
F_39 ( L_37 ,
V_75 , V_78 , V_89 , V_83 ) ;
continue;
}
V_83 = F_40 ( V_75 , V_78 , V_89 ,
V_90 , & V_80 ) ;
if ( V_83 ) {
F_39 ( L_38 ,
V_75 , V_78 , V_89 , V_83 ) ;
continue;
}
V_83 = F_40 ( V_75 , V_78 , V_89 ,
V_91 , & V_81 ) ;
if ( V_83 ) {
F_39 ( L_39 ,
V_75 , V_78 , V_89 , V_83 ) ;
continue;
}
V_83 = F_41 ( V_75 , V_78 , V_89 ,
V_92 , & V_82 ) ;
if ( V_83 ) {
F_39 ( L_40 ,
V_75 , V_78 , V_89 , V_83 ) ;
continue;
}
V_87 = F_42 ( F_43 ( V_86 ) ,
V_85 ) ;
V_73 = F_32 ( V_82 >> 16 ) ;
if ( V_73 && V_73 -> V_27 )
strncpy ( V_31 , V_73 -> V_27 , sizeof( V_31 ) - 1 ) ;
else
snprintf ( V_31 , sizeof( V_31 ) , L_41 ,
V_80 , V_81 ) ;
V_31 [ sizeof( V_31 ) - 1 ] = '\0' ;
snprintf ( V_31 + strlen ( V_31 ) , sizeof( V_31 ) - strlen ( V_31 ) ,
L_42 , F_44 ( V_87 ) ) ;
V_31 [ sizeof( V_31 ) - 1 ] = '\0' ;
if ( V_85 != 0 )
snprintf ( V_31 + strlen ( V_31 ) ,
sizeof( V_31 ) - strlen ( V_31 ) ,
L_43 , V_85 ) ;
F_11 ( V_7 , V_31 ) ;
V_59 [ 0 ] = ( V_75 << 16 ) | ( V_87 << 8 ) ;
V_59 [ 1 ] = 0 ;
V_59 [ 2 ] = 0 ;
V_59 [ 3 ] = 0 ;
V_59 [ 4 ] = 0 ;
F_20 ( V_7 , L_13 , V_59 , 5 ) ;
if ( V_73 && ( V_73 -> type || V_73 -> V_27 ) )
F_19 ( V_7 , L_6 ,
V_73 -> type ? V_73 -> type : V_73 -> V_27 ) ;
F_16 ( V_7 , L_44 , V_80 ) ;
F_16 ( V_7 , L_45 , V_81 ) ;
F_16 ( V_7 , L_46 , V_82 >> 8 ) ;
F_16 ( V_7 , L_47 , V_82 & 0xff ) ;
F_16 ( V_7 , L_48 , V_78 ) ;
F_16 ( V_7 , L_49 , V_89 ) ;
F_16 ( V_7 , L_50 ,
V_77 -> V_93 ) ;
F_21 ( V_7 ) ;
}
}
}
static void T_1 F_45 ( struct V_6 * V_7 , T_8 V_75 ,
T_9 V_78 , int V_84 )
{
struct V_76 V_77 ;
T_10 V_89 ;
int V_85 ;
int V_94 ;
for ( V_85 = 0 ; V_85 < 8 ; ++ V_85 ) {
V_89 = F_37 ( V_84 , V_85 ) ;
V_94 = F_38 ( V_75 , V_78 , V_89 , 0 ) ;
if ( V_94 != 0 ) {
if ( V_94 != 0xb )
F_39 ( L_37 ,
V_75 , V_78 , V_89 , V_94 ) ;
continue;
}
F_39 ( L_51 ,
V_75 , V_84 , V_85 , V_89 ) ;
V_94 = F_46 ( V_75 , V_78 , V_89 ,
F_47 ( & V_77 ) ,
sizeof( struct V_76 ) ) ;
if ( V_94 != 0 )
continue;
F_39 ( L_52
L_53 ,
V_77 . V_95 . V_96 ,
V_77 . V_79 ,
V_77 . V_88 ,
V_77 . V_97 ,
V_77 . V_93 ) ;
if ( V_77 . V_95 . V_96 ==
V_98 )
F_34 ( V_7 , V_75 , & V_77 ) ;
else
F_39 ( L_54 ,
V_77 . V_95 . V_96 ) ;
}
}
static void T_1 F_48 ( struct V_6 * V_7 , T_8 V_75 )
{
struct V_99 V_100 ;
const T_9 V_78 = 0 ;
int V_83 ;
int V_84 ;
const int V_101 = 8 ;
for ( V_84 = 1 ; V_84 < V_101 ; ++ V_84 ) {
V_83 = F_49 ( V_75 , V_78 , V_84 ,
F_47 ( & V_100 ) ,
sizeof( struct V_99 ) ) ;
if ( V_83 ) {
if ( V_83 != 0x302 )
F_39 ( L_55 ,
V_75 , V_78 , V_84 , V_83 ) ;
continue;
}
if ( V_100 . V_96 != V_102 ) {
F_39 ( L_56
L_57 ,
V_100 . V_96 , V_75 , V_84 ) ;
continue;
}
F_45 ( V_7 , V_75 , V_78 , V_84 ) ;
}
}
static void T_1 F_50 ( struct V_6 * V_7 )
{
T_8 V_75 ;
char V_31 [ 32 ] ;
T_3 V_103 [ 2 ] ;
int V_104 = 0 ;
for ( V_75 = 0 ; V_75 < 256 ; V_75 ++ ) {
int V_83 = F_51 ( V_75 ) ;
if ( V_83 ) {
if ( V_83 != 0x0301 )
F_39 ( L_58
L_59 , V_75 , V_83 ) ;
continue;
}
F_39 ( L_60 , V_75 ) ;
snprintf ( V_31 , 32 , L_61 , V_104 ) ;
F_11 ( V_7 , V_31 ) ;
F_19 ( V_7 , L_6 , V_105 ) ;
F_19 ( V_7 , L_18 , L_62 ) ;
F_16 ( V_7 , L_3 , 3 ) ;
F_16 ( V_7 , L_4 , 2 ) ;
V_103 [ 0 ] = V_103 [ 1 ] = V_75 ;
F_20 ( V_7 , L_63 , V_103 , 2 ) ;
F_48 ( V_7 , V_75 ) ;
F_21 ( V_7 ) ;
V_104 ++ ;
}
}
static void F_52 ( struct V_6 * V_7 )
{
F_8 ( V_7 , V_106 ) ;
V_7 -> V_12 . V_107 = ( unsigned long ) V_17 - ( unsigned long ) V_7 ;
V_11 = F_5 ( ( unsigned long ) V_17 , 8 ) ;
}
void * T_1 F_53 ( unsigned long V_108 )
{
struct V_6 * V_109 ;
T_4 V_110 [ 2 ] ;
V_109 = F_4 () ;
F_11 ( V_109 , L_64 ) ;
F_16 ( V_109 , L_3 , 2 ) ;
F_16 ( V_109 , L_4 , 2 ) ;
F_22 ( V_109 ) ;
F_11 ( V_109 , L_65 ) ;
F_19 ( V_109 , L_6 , V_111 ) ;
V_110 [ 0 ] = 0 ;
V_110 [ 1 ] = V_108 ;
F_54 ( V_109 , L_13 , V_110 , 2 ) ;
F_21 ( V_109 ) ;
F_11 ( V_109 , L_66 ) ;
F_19 ( V_109 , L_67 , V_112 ) ;
F_24 ( V_109 ) ;
F_21 ( V_109 ) ;
F_15 ( V_109 ) ;
F_28 ( V_109 ) ;
F_50 ( V_109 ) ;
F_21 ( V_109 ) ;
F_52 ( V_109 ) ;
return V_109 ;
}
