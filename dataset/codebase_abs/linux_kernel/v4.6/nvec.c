int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_5 )
{
return F_2 ( & V_2 -> V_6 , V_4 ) ;
}
int F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return F_4 ( & V_2 -> V_6 , V_4 ) ;
}
static int F_5 ( struct V_3 * V_4 ,
unsigned long V_7 , void * V_8 )
{
struct V_1 * V_2 = F_6 ( V_4 , struct V_1 ,
F_5 ) ;
unsigned char * V_9 = V_8 ;
if ( V_7 != V_10 )
return V_11 ;
F_7 ( V_2 -> V_12 , L_1 , V_7 ) ;
F_8 ( V_13 , L_2 , V_14 , 16 , 1 ,
V_9 , V_9 [ 1 ] + 2 , true ) ;
return V_15 ;
}
static struct V_16 * F_9 ( struct V_1 * V_2 ,
enum V_17 V_18 )
{
int V_19 = ( V_18 == V_20 ) ? ( V_21 / 4 ) : 0 ;
for (; V_19 < V_21 ; V_19 ++ ) {
if ( F_10 ( & V_2 -> V_22 [ V_19 ] . V_23 , 1 ) == 0 ) {
F_11 ( V_2 -> V_12 , L_3 , V_19 ) ;
return & V_2 -> V_22 [ V_19 ] ;
}
}
F_12 ( V_2 -> V_12 , L_4 ,
( V_18 == V_20 ) ? L_5 : L_6 ) ;
return NULL ;
}
void F_13 ( struct V_1 * V_2 , struct V_16 * V_9 )
{
if ( V_9 != & V_2 -> V_24 )
F_11 ( V_2 -> V_12 , L_7 , V_9 - V_2 -> V_22 ) ;
F_14 ( & V_9 -> V_23 , 0 ) ;
}
static bool F_15 ( struct V_16 * V_9 )
{
return V_9 -> V_8 [ 0 ] >> 7 ;
}
static T_1 F_16 ( struct V_16 * V_9 )
{
bool V_25 = F_15 ( V_9 ) ;
int V_26 = ( V_9 -> V_8 [ 0 ] & 0x60 ) >> 5 ;
if ( ! V_25 || V_26 == V_27 )
return ( V_9 -> V_28 || V_9 -> V_29 ) ? ( V_9 -> V_8 [ 1 ] + 2 ) : 0 ;
else if ( V_26 == V_30 )
return 2 ;
else if ( V_26 == V_31 )
return 3 ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 , int V_32 )
{
F_18 ( V_2 -> V_12 , L_8 ,
F_19 ( V_2 -> V_33 ) , V_32 ) ;
F_20 ( V_2 -> V_33 , V_32 ) ;
}
int F_21 ( struct V_1 * V_2 , const unsigned char * V_8 ,
short V_29 )
{
struct V_16 * V_9 ;
unsigned long V_34 ;
V_9 = F_9 ( V_2 , V_20 ) ;
if ( V_9 == NULL )
return - V_35 ;
V_9 -> V_8 [ 0 ] = V_29 ;
memcpy ( V_9 -> V_8 + 1 , V_8 , V_29 ) ;
V_9 -> V_29 = V_29 + 1 ;
F_22 ( & V_2 -> V_36 , V_34 ) ;
F_23 ( & V_9 -> V_37 , & V_2 -> V_38 ) ;
F_24 ( & V_2 -> V_36 , V_34 ) ;
F_25 ( & V_2 -> V_39 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 ,
const unsigned char * V_8 , short V_29 ,
struct V_16 * * V_9 )
{
F_27 ( & V_2 -> V_40 ) ;
* V_9 = NULL ;
V_2 -> V_41 = ( V_8 [ 1 ] << 8 ) + V_8 [ 0 ] ;
if ( F_21 ( V_2 , V_8 , V_29 ) < 0 ) {
F_28 ( & V_2 -> V_40 ) ;
return - V_35 ;
}
F_18 ( V_2 -> V_12 , L_9 ,
V_2 -> V_41 ) ;
if ( ! ( F_29 ( & V_2 -> V_42 ,
F_30 ( 2000 ) ) ) ) {
F_7 ( V_2 -> V_12 ,
L_10 ) ;
F_28 ( & V_2 -> V_40 ) ;
return - V_43 ;
}
F_18 ( V_2 -> V_12 , L_11 ) ;
* V_9 = V_2 -> V_44 ;
F_28 ( & V_2 -> V_40 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_2 , bool V_45 )
{
unsigned char V_46 [] = { V_47 , V_48 , V_45 } ;
F_21 ( V_2 , V_46 , 3 ) ;
}
static void F_32 ( char * V_49 , T_2 V_50 )
{
V_49 [ 3 ] = V_50 >> 16 & 0xff ;
V_49 [ 4 ] = V_50 >> 24 & 0xff ;
V_49 [ 5 ] = V_50 >> 0 & 0xff ;
V_49 [ 6 ] = V_50 >> 8 & 0xff ;
}
static void F_33 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = F_6 ( V_52 , struct V_1 , V_39 ) ;
unsigned long V_34 ;
long V_53 ;
struct V_16 * V_9 ;
F_22 ( & V_2 -> V_36 , V_34 ) ;
while ( ! F_34 ( & V_2 -> V_38 ) ) {
V_9 = F_35 ( & V_2 -> V_38 , struct V_16 , V_37 ) ;
F_24 ( & V_2 -> V_36 , V_34 ) ;
F_17 ( V_2 , 0 ) ;
V_53 = F_36 (
& V_2 -> V_54 , F_30 ( 5000 ) ) ;
if ( V_53 == 0 ) {
F_7 ( V_2 -> V_12 , L_12 ) ;
F_17 ( V_2 , 1 ) ;
V_9 -> V_28 = 0 ;
}
F_22 ( & V_2 -> V_36 , V_34 ) ;
if ( V_53 > 0 ) {
F_37 ( & V_9 -> V_37 ) ;
F_13 ( V_2 , V_9 ) ;
}
}
F_24 ( & V_2 -> V_36 , V_34 ) ;
}
static int F_38 ( struct V_1 * V_2 , struct V_16 * V_9 )
{
if ( ( V_9 -> V_8 [ 0 ] & 1 << 7 ) == 0 && V_9 -> V_8 [ 3 ] ) {
F_12 ( V_2 -> V_12 , L_13 , 4 , V_9 -> V_8 ) ;
return - V_55 ;
}
if ( ( V_9 -> V_8 [ 0 ] >> 7 ) == 1 && ( V_9 -> V_8 [ 0 ] & 0x0f ) == 5 )
F_8 ( V_13 , L_14 ,
V_14 , 16 , 1 , V_9 -> V_8 ,
V_9 -> V_8 [ 1 ] + 2 , true ) ;
F_39 ( & V_2 -> V_6 , V_9 -> V_8 [ 0 ] & 0x8f ,
V_9 -> V_8 ) ;
return 0 ;
}
static void F_40 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = F_6 ( V_52 , struct V_1 , V_56 ) ;
unsigned long V_34 ;
struct V_16 * V_9 ;
F_22 ( & V_2 -> V_57 , V_34 ) ;
while ( ! F_34 ( & V_2 -> V_58 ) ) {
V_9 = F_35 ( & V_2 -> V_58 , struct V_16 , V_37 ) ;
F_37 ( & V_9 -> V_37 ) ;
F_24 ( & V_2 -> V_57 , V_34 ) ;
if ( V_2 -> V_41 ==
( V_9 -> V_8 [ 2 ] << 8 ) + V_9 -> V_8 [ 0 ] ) {
F_18 ( V_2 -> V_12 , L_15 ) ;
V_2 -> V_41 = 0 ;
V_2 -> V_44 = V_9 ;
F_41 ( & V_2 -> V_42 ) ;
} else {
F_38 ( V_2 , V_9 ) ;
F_13 ( V_2 , V_9 ) ;
}
F_22 ( & V_2 -> V_57 , V_34 ) ;
}
F_24 ( & V_2 -> V_57 , V_34 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
if ( V_2 -> V_59 -> V_28 != V_2 -> V_59 -> V_29 ) {
F_12 ( V_2 -> V_12 , L_16 ) ;
V_2 -> V_59 -> V_28 = 0 ;
F_17 ( V_2 , 0 ) ;
} else {
V_2 -> V_45 = 0 ;
}
}
static void F_43 ( struct V_1 * V_2 )
{
if ( V_2 -> V_60 -> V_28 != F_16 ( V_2 -> V_60 ) ) {
F_12 ( V_2 -> V_12 , L_17 ,
( V_61 ) F_16 ( V_2 -> V_60 ) ,
( V_61 ) V_2 -> V_60 -> V_28 ) ;
F_13 ( V_2 , V_2 -> V_60 ) ;
V_2 -> V_45 = 0 ;
if ( V_2 -> V_60 -> V_8 [ 0 ] == V_62 )
F_41 ( & V_2 -> V_54 ) ;
return;
}
F_44 ( & V_2 -> V_57 ) ;
F_23 ( & V_2 -> V_60 -> V_37 , & V_2 -> V_58 ) ;
F_45 ( & V_2 -> V_57 ) ;
V_2 -> V_45 = 0 ;
if ( ! F_15 ( V_2 -> V_60 ) )
F_41 ( & V_2 -> V_54 ) ;
F_25 ( & V_2 -> V_56 ) ;
}
static void F_46 ( struct V_1 * V_2 , unsigned int V_63 ,
bool V_64 )
{
F_12 ( V_2 -> V_12 , L_18 ,
V_63 , V_2 -> V_45 ) ;
if ( V_64 )
V_2 -> V_45 = 0 ;
}
static void F_47 ( struct V_1 * V_2 )
{
F_44 ( & V_2 -> V_36 ) ;
if ( F_34 ( & V_2 -> V_38 ) ) {
F_12 ( V_2 -> V_12 , L_19 ) ;
memcpy ( V_2 -> V_24 . V_8 , L_20 , 3 ) ;
V_2 -> V_24 . V_29 = 3 ;
V_2 -> V_24 . V_28 = 0 ;
V_2 -> V_59 = & V_2 -> V_24 ;
F_23 ( & V_2 -> V_59 -> V_37 , & V_2 -> V_38 ) ;
} else {
V_2 -> V_59 = F_35 ( & V_2 -> V_38 , struct V_16 ,
V_37 ) ;
V_2 -> V_59 -> V_28 = 0 ;
}
F_45 ( & V_2 -> V_36 ) ;
F_18 ( V_2 -> V_12 , L_21 ,
( V_61 ) V_2 -> V_59 -> V_29 , V_2 -> V_59 -> V_8 [ 1 ] ) ;
}
static T_3 F_48 ( int V_65 , void * V_12 )
{
unsigned long V_63 ;
unsigned int V_66 = 0 ;
unsigned char V_67 = 0xff ;
const unsigned long V_68 = V_69 | V_70 | V_71 | V_72 ;
struct V_1 * V_2 = V_12 ;
unsigned int V_45 = V_2 -> V_45 ;
V_63 = F_49 ( V_2 -> V_73 + V_74 ) ;
if ( ( V_63 & V_68 ) == 0 && ( V_63 & ~ V_68 ) != 0 ) {
F_12 ( V_2 -> V_12 , L_22 , V_63 ) ;
return V_75 ;
}
if ( ( V_63 & V_69 ) == 0 ) {
F_12 ( V_2 -> V_12 , L_23 ) ;
return V_75 ;
}
if ( ( V_63 & V_72 ) == 0 ) {
V_66 = F_49 ( V_2 -> V_73 + V_76 ) ;
if ( V_63 & V_71 )
F_50 ( 0 , V_2 -> V_73 + V_76 ) ;
}
if ( V_63 == ( V_69 | V_71 ) )
V_2 -> V_45 = 0 ;
switch ( V_2 -> V_45 ) {
case 0 :
if ( V_63 != ( V_69 | V_71 ) )
F_46 ( V_2 , V_63 , false ) ;
break;
case 1 :
if ( V_63 != V_69 ) {
F_46 ( V_2 , V_63 , true ) ;
} else {
V_2 -> V_60 = F_9 ( V_2 , V_77 ) ;
if ( F_51 ( V_2 -> V_60 == NULL ) ) {
V_2 -> V_45 = 0 ;
break;
}
V_2 -> V_60 -> V_8 [ 0 ] = V_66 ;
V_2 -> V_60 -> V_28 = 1 ;
V_2 -> V_45 = 2 ;
}
break;
case 2 :
if ( V_63 == ( V_69 | V_72 | V_71 ) ) {
F_52 ( 33 ) ;
if ( V_2 -> V_60 -> V_8 [ 0 ] != 0x01 ) {
F_12 ( V_2 -> V_12 ,
L_24 ) ;
V_2 -> V_45 = 0 ;
break;
}
F_13 ( V_2 , V_2 -> V_60 ) ;
V_2 -> V_45 = 3 ;
F_47 ( V_2 ) ;
V_67 = V_2 -> V_59 -> V_8 [ 0 ] ;
V_2 -> V_59 -> V_28 = 1 ;
} else if ( V_63 == ( V_69 ) ) {
V_2 -> V_60 -> V_8 [ 1 ] = V_66 ;
V_2 -> V_60 -> V_28 = 2 ;
V_2 -> V_45 = 4 ;
} else {
F_46 ( V_2 , V_63 , true ) ;
}
break;
case 3 :
if ( V_63 & V_70 ) {
F_42 ( V_2 ) ;
} else if ( ( V_63 & V_72 ) == 0 || ( V_63 & V_71 ) ) {
F_46 ( V_2 , V_63 , true ) ;
} else if ( V_2 -> V_59 && V_2 -> V_59 -> V_28 < V_2 -> V_59 -> V_29 ) {
V_67 = V_2 -> V_59 -> V_8 [ V_2 -> V_59 -> V_28 ++ ] ;
} else {
F_12 ( V_2 -> V_12 , L_25 ,
V_2 -> V_59 ,
( V_61 ) ( V_2 -> V_59 ? V_2 -> V_59 -> V_28 : 0 ) ,
( V_61 ) ( V_2 -> V_59 ? V_2 -> V_59 -> V_29 : 0 ) ) ;
V_2 -> V_45 = 0 ;
}
break;
case 4 :
if ( ( V_63 & ( V_70 | V_72 ) ) == V_70 )
F_43 ( V_2 ) ;
else if ( V_63 & ( V_72 | V_71 ) )
F_46 ( V_2 , V_63 , true ) ;
else if ( V_2 -> V_60 && V_2 -> V_60 -> V_28 < V_78 )
V_2 -> V_60 -> V_8 [ V_2 -> V_60 -> V_28 ++ ] = V_66 ;
else
F_12 ( V_2 -> V_12 ,
L_26 ,
V_2 -> V_60 , V_2 -> V_60 ? V_2 -> V_60 -> V_28 : 0 ,
V_78 ) ;
break;
default:
V_2 -> V_45 = 0 ;
}
if ( ( V_63 & ( V_71 | V_72 ) ) == V_71 ) {
if ( V_66 != V_2 -> V_79 )
F_12 ( V_2 -> V_12 ,
L_27 ,
V_66 , V_2 -> V_79 ) ;
V_2 -> V_45 = 1 ;
}
if ( ( V_63 & ( V_72 | V_70 ) ) == V_72 )
F_50 ( V_67 , V_2 -> V_73 + V_76 ) ;
if ( V_63 == ( V_69 | V_72 | V_71 ) )
F_17 ( V_2 , 1 ) ;
F_18 ( V_2 -> V_12 ,
L_28 ,
( V_63 & V_72 ) == 0 ? L_29 : L_30 ,
V_66 ,
( V_63 & ( V_72 | V_70 ) ) ? L_31 : L_32 ,
V_67 ,
V_45 ,
V_63 & V_70 ? L_33 : L_34 ,
V_63 & V_71 ? L_35 : L_34 ,
V_63 & V_72 ? L_36 : L_34 ) ;
F_52 ( 100 ) ;
return V_75 ;
}
static void F_53 ( struct V_1 * V_2 )
{
T_2 V_80 ;
F_54 ( V_2 -> V_81 ) ;
F_55 ( V_2 -> V_82 ) ;
F_52 ( 2 ) ;
F_56 ( V_2 -> V_82 ) ;
V_80 = V_83 | V_84 |
( 0x2 << V_85 ) ;
F_50 ( V_80 , V_2 -> V_73 + V_86 ) ;
F_57 ( V_2 -> V_81 , 8 * 80000 ) ;
F_50 ( V_87 , V_2 -> V_73 + V_88 ) ;
F_50 ( 0x1E , V_2 -> V_73 + V_89 ) ;
F_50 ( V_2 -> V_79 >> 1 , V_2 -> V_73 + V_90 ) ;
F_50 ( 0 , V_2 -> V_73 + V_91 ) ;
F_58 ( V_2 -> V_65 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
F_60 ( V_2 -> V_65 ) ;
F_50 ( V_87 | V_92 , V_2 -> V_73 + V_88 ) ;
F_61 ( V_2 -> V_81 ) ;
}
static void F_62 ( void )
{
char V_93 [] = { V_47 , V_94 } ;
F_31 ( V_95 , false ) ;
F_21 ( V_95 , V_93 , 2 ) ;
}
static int F_63 ( struct V_1 * V_2 )
{
V_2 -> V_33 = F_64 ( V_2 -> V_12 -> V_96 , L_37 , 0 ) ;
if ( V_2 -> V_33 < 0 ) {
F_12 ( V_2 -> V_12 , L_38 ) ;
return - V_97 ;
}
if ( F_65 ( V_2 -> V_12 -> V_96 , L_39 ,
& V_2 -> V_79 ) ) {
F_12 ( V_2 -> V_12 , L_40 ) ;
return - V_97 ;
}
return 0 ;
}
static int F_66 ( struct V_98 * V_99 )
{
int V_53 , V_100 ;
struct V_101 * V_81 ;
struct V_1 * V_2 ;
struct V_16 * V_9 ;
struct V_102 * V_103 ;
void T_4 * V_73 ;
char V_104 [] = { V_10 , V_105 } ,
V_106 [] = { V_107 , 0x10 , 0x59 , 0x95 } ,
V_108 [ 7 ] = { V_109 , V_110 , true } ;
if ( ! V_99 -> V_12 . V_96 ) {
F_12 ( & V_99 -> V_12 , L_41 ) ;
return - V_97 ;
}
V_2 = F_67 ( & V_99 -> V_12 , sizeof( struct V_1 ) , V_111 ) ;
if ( ! V_2 )
return - V_35 ;
F_68 ( V_99 , V_2 ) ;
V_2 -> V_12 = & V_99 -> V_12 ;
V_53 = F_63 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
V_103 = F_69 ( V_99 , V_112 , 0 ) ;
V_73 = F_70 ( & V_99 -> V_12 , V_103 ) ;
if ( F_71 ( V_73 ) )
return F_72 ( V_73 ) ;
V_2 -> V_65 = F_73 ( V_99 , 0 ) ;
if ( V_2 -> V_65 < 0 ) {
F_12 ( & V_99 -> V_12 , L_42 ) ;
return - V_97 ;
}
V_81 = F_74 ( & V_99 -> V_12 , L_43 ) ;
if ( F_71 ( V_81 ) ) {
F_12 ( V_2 -> V_12 , L_44 ) ;
return - V_97 ;
}
V_2 -> V_82 = F_75 ( & V_99 -> V_12 , L_45 ) ;
if ( F_71 ( V_2 -> V_82 ) ) {
F_12 ( V_2 -> V_12 , L_46 ) ;
return F_72 ( V_2 -> V_82 ) ;
}
V_2 -> V_73 = V_73 ;
V_2 -> V_81 = V_81 ;
V_2 -> V_60 = & V_2 -> V_22 [ 0 ] ;
F_76 ( & V_2 -> V_6 ) ;
F_77 ( & V_2 -> V_42 ) ;
F_77 ( & V_2 -> V_54 ) ;
F_78 ( & V_2 -> V_40 ) ;
F_79 ( & V_2 -> V_36 ) ;
F_79 ( & V_2 -> V_57 ) ;
F_80 ( & V_2 -> V_58 ) ;
F_80 ( & V_2 -> V_38 ) ;
F_81 ( & V_2 -> V_56 , F_40 ) ;
F_81 ( & V_2 -> V_39 , F_33 ) ;
V_53 = F_82 ( & V_99 -> V_12 , V_2 -> V_33 , V_113 ,
L_47 ) ;
if ( V_53 < 0 ) {
F_12 ( V_2 -> V_12 , L_48 ) ;
return - V_97 ;
}
V_53 = F_83 ( & V_99 -> V_12 , V_2 -> V_65 , F_48 , 0 ,
L_49 , V_2 ) ;
if ( V_53 ) {
F_12 ( V_2 -> V_12 , L_50 ) ;
return - V_97 ;
}
F_60 ( V_2 -> V_65 ) ;
F_53 ( V_2 ) ;
F_31 ( V_2 , true ) ;
V_2 -> F_5 . V_114 = F_5 ;
F_1 ( V_2 , & V_2 -> F_5 , 0 ) ;
V_95 = V_2 ;
V_115 = F_62 ;
V_53 = F_26 ( V_2 , V_104 , 2 , & V_9 ) ;
if ( ! V_53 ) {
F_7 ( V_2 -> V_12 ,
L_51 ,
V_9 -> V_8 [ 4 ] , V_9 -> V_8 [ 5 ] ,
V_9 -> V_8 [ 6 ] , V_9 -> V_8 [ 7 ] ) ;
F_13 ( V_2 , V_9 ) ;
}
V_100 = F_84 ( V_2 -> V_12 , 0 , V_116 ,
F_85 ( V_116 ) , NULL , 0 , NULL ) ;
if ( V_100 )
F_12 ( V_2 -> V_12 , L_52 ) ;
F_21 ( V_2 , V_106 , 4 ) ;
F_32 ( V_108 , V_117 ) ;
F_21 ( V_2 , V_108 , 7 ) ;
F_32 ( V_108 , V_118 ) ;
F_21 ( V_2 , V_108 , 7 ) ;
return 0 ;
}
static int F_86 ( struct V_98 * V_99 )
{
struct V_1 * V_2 = F_87 ( V_99 ) ;
F_31 ( V_2 , false ) ;
F_88 ( V_2 -> V_12 ) ;
F_3 ( V_2 , & V_2 -> F_5 ) ;
F_89 ( & V_2 -> V_56 ) ;
F_89 ( & V_2 -> V_39 ) ;
V_115 = NULL ;
return 0 ;
}
static int F_90 ( struct V_119 * V_12 )
{
int V_53 ;
struct V_98 * V_99 = F_91 ( V_12 ) ;
struct V_1 * V_2 = F_87 ( V_99 ) ;
struct V_16 * V_9 ;
char V_120 [] = { V_47 , V_121 } ;
F_18 ( V_2 -> V_12 , L_53 ) ;
F_31 ( V_2 , false ) ;
V_53 = F_26 ( V_2 , V_120 , sizeof( V_120 ) , & V_9 ) ;
if ( ! V_53 )
F_13 ( V_2 , V_9 ) ;
F_59 ( V_2 ) ;
return 0 ;
}
static int F_92 ( struct V_119 * V_12 )
{
struct V_98 * V_99 = F_91 ( V_12 ) ;
struct V_1 * V_2 = F_87 ( V_99 ) ;
F_18 ( V_2 -> V_12 , L_54 ) ;
F_53 ( V_2 ) ;
F_31 ( V_2 , true ) ;
return 0 ;
}
