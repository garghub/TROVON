static T_1 * F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
* V_4 = sizeof( V_5 ) ;
return V_5 ;
}
static int F_2 ( struct V_1 * V_2 , struct V_6 * V_7 ,
struct V_8 * V_9 , struct V_10 * V_11 ,
unsigned long * * V_12 , int * V_13 )
{
unsigned int V_14 = V_11 -> V_15 & V_16 ;
if ( ( V_11 -> V_15 & V_17 ) != V_18 )
return - 1 ;
switch ( V_11 -> V_19 ) {
case 1 :
if ( V_14 >= F_3 ( V_20 ) )
return - 1 ;
V_14 = V_20 [ V_14 ] ;
if ( ! V_14 )
return - 1 ;
break;
case 2 :
if ( V_14 >= F_3 ( V_21 ) )
return - 1 ;
V_14 = V_21 [ V_14 ] ;
if ( ! V_14 )
return - 1 ;
break;
default:
return - 1 ;
}
F_4 ( V_7 , V_11 , V_12 , V_13 , V_22 , V_14 ) ;
return 1 ;
}
static T_1 * F_5 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
struct V_23 * V_24 = F_6 ( V_2 ) ;
if ( ( V_24 -> V_25 & V_26 ) && * V_4 >= 56 &&
V_3 [ 2 ] == 0x09 && V_3 [ 3 ] == 0x02 &&
V_3 [ 54 ] == 0x81 && V_3 [ 55 ] == 0x07 ) {
F_7 ( V_2 , L_1 ) ;
V_3 [ 55 ] = 0x06 ;
}
if ( ( ( ( V_24 -> V_25 & V_27 ) && * V_4 == 148 ) ||
( ( V_24 -> V_25 & V_28 ) && * V_4 == 149 ) ) &&
V_3 [ 83 ] == 0x75 ) {
F_7 ( V_2 , L_2 ) ;
memcpy ( ( void * ) & V_3 [ 83 ] , ( void * ) & V_29 ,
sizeof( V_29 ) ) ;
} else if ( V_24 -> V_25 & V_27 &&
* V_4 > sizeof( V_30 ) ) {
F_7 ( V_2 , L_3 ,
* V_4 , ( int ) sizeof( V_30 ) ) ;
* V_4 = sizeof( V_30 ) ;
memcpy ( V_3 , & V_30 , * V_4 ) ;
}
if ( V_24 -> V_25 & V_31 )
return F_1 ( V_2 , V_3 , V_4 ) ;
return V_3 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_32 * V_33 ,
T_1 * V_34 , int V_35 )
{
struct V_23 * V_24 = F_6 ( V_2 ) ;
if ( ( V_24 -> V_25 & ( V_27 | V_28 ) ) &&
V_34 [ 0 ] == 0x01 && V_35 == 49 ) {
F_9 ( V_34 [ 41 ] , V_34 [ 42 ] ) ;
F_9 ( V_34 [ 43 ] , V_34 [ 44 ] ) ;
F_9 ( V_34 [ 45 ] , V_34 [ 46 ] ) ;
F_9 ( V_34 [ 47 ] , V_34 [ 48 ] ) ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_6 * V_7 ,
struct V_8 * V_9 , struct V_10 * V_11 ,
unsigned long * * V_12 , int * V_13 )
{
struct V_23 * V_24 = F_6 ( V_2 ) ;
if ( V_24 -> V_25 & V_36 ) {
unsigned int V_14 = V_11 -> V_15 & V_16 ;
if ( ( V_11 -> V_15 & V_17 ) != V_18 )
return - 1 ;
switch ( V_11 -> V_19 ) {
case 1 :
if ( V_14 >= F_3 ( V_37 ) )
return - 1 ;
V_14 = V_37 [ V_14 ] ;
if ( ! V_14 )
return - 1 ;
break;
default:
return - 1 ;
}
F_4 ( V_7 , V_11 , V_12 , V_13 , V_22 , V_14 ) ;
return 1 ;
}
if ( V_24 -> V_25 & V_31 )
return F_2 ( V_2 , V_7 , V_9 , V_11 , V_12 , V_13 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_15 , T_1 * V_38 ,
T_2 V_39 , unsigned char V_40 )
{
struct V_41 * V_42 = F_12 ( V_15 -> V_43 . V_44 ) ;
struct V_45 * V_43 = F_13 ( V_42 ) ;
struct V_46 * V_47 = V_42 -> V_48 ;
int V_49 = V_38 [ 0 ] ;
int V_50 ;
if ( V_40 == V_51 ) {
V_38 ++ ;
V_39 -- ;
}
V_50 = F_14 ( V_43 , F_15 ( V_43 , 0 ) ,
V_52 ,
V_53 | V_54 | V_55 ,
( ( V_40 + 1 ) << 8 ) | V_49 ,
V_47 -> V_56 . V_57 , V_38 , V_39 ,
V_58 ) ;
if ( V_50 > 0 && V_40 == V_51 )
V_50 ++ ;
return V_50 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_50 ;
char * V_38 = F_17 ( 18 , V_59 ) ;
if ( ! V_38 )
return - V_60 ;
V_50 = V_2 -> V_61 ( V_2 , 0xf2 , V_38 , 17 , V_62 ) ;
if ( V_50 < 0 )
F_18 ( V_2 , L_4 ) ;
F_19 ( V_38 ) ;
return V_50 ;
}
static int F_20 ( struct V_1 * V_2 )
{
unsigned char V_38 [] = { 0xf4 , 0x42 , 0x03 , 0x00 , 0x00 } ;
return V_2 -> V_63 ( V_2 , V_38 , sizeof( V_38 ) , V_62 ) ;
}
static void F_21 ( struct V_1 * V_2 , int V_64 )
{
struct V_65 * V_66 =
& V_2 -> V_67 [ V_51 ] . V_66 ;
struct V_32 * V_33 = F_22 ( V_66 -> V_68 ,
struct V_32 , V_69 ) ;
T_3 * V_70 = V_33 -> V_9 [ 0 ] -> V_70 ;
V_70 [ 0 ] = 0x00 ;
V_70 [ 1 ] = ( V_64 & 1 ) ? 0xff : 0x00 ;
V_70 [ 2 ] = ( V_64 & 2 ) ? 0xff : 0x00 ;
V_70 [ 3 ] = ( V_64 & 4 ) ? 0xff : 0x00 ;
V_70 [ 4 ] = ( V_64 & 8 ) ? 0xff : 0x00 ;
V_70 [ 5 ] = 0x00 ;
V_70 [ 6 ] = 0x00 ;
F_23 ( V_2 , V_33 , V_52 ) ;
}
static void F_24 ( struct V_71 * V_72 ,
enum V_73 V_70 )
{
struct V_74 * V_43 = V_72 -> V_43 -> V_44 ;
struct V_1 * V_2 = F_25 ( V_43 , struct V_1 , V_43 ) ;
struct V_23 * V_75 ;
struct V_76 * V_77 ;
int V_78 ;
V_75 = F_6 ( V_2 ) ;
if ( ! V_75 || ! V_75 -> V_79 ) {
F_18 ( V_2 , L_5 ) ;
return;
}
V_77 = V_75 -> V_79 ;
for ( V_78 = 0 ; V_78 < 4 ; V_78 ++ ) {
if ( V_72 == V_77 -> V_64 [ V_78 ] ) {
int V_80 = ! ! ( V_77 -> V_81 & ( 1 << V_78 ) ) ;
if ( V_70 == V_82 && V_80 ) {
V_77 -> V_81 &= ~ ( 1 << V_78 ) ;
F_21 ( V_2 , V_77 -> V_81 ) ;
} else if ( V_70 != V_82 && ! V_80 ) {
V_77 -> V_81 |= ( 1 << V_78 ) ;
F_21 ( V_2 , V_77 -> V_81 ) ;
}
break;
}
}
}
static enum V_73 F_26 ( struct V_71 * V_72 )
{
struct V_74 * V_43 = V_72 -> V_43 -> V_44 ;
struct V_1 * V_2 = F_25 ( V_43 , struct V_1 , V_43 ) ;
struct V_23 * V_75 ;
struct V_76 * V_77 ;
int V_78 ;
int V_80 = 0 ;
V_75 = F_6 ( V_2 ) ;
if ( ! V_75 || ! V_75 -> V_79 ) {
F_18 ( V_2 , L_5 ) ;
return V_82 ;
}
V_77 = V_75 -> V_79 ;
for ( V_78 = 0 ; V_78 < 4 ; V_78 ++ ) {
if ( V_72 == V_77 -> V_64 [ V_78 ] ) {
V_80 = ! ! ( V_77 -> V_81 & ( 1 << V_78 ) ) ;
break;
}
}
return V_80 ? V_83 : V_82 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_23 * V_75 ;
struct V_76 * V_77 ;
int V_78 , V_50 = 0 ;
struct V_71 * V_72 ;
T_2 V_84 ;
char * V_85 ;
V_75 = F_6 ( V_2 ) ;
F_28 ( ! ( V_75 -> V_25 & V_36 ) ) ;
if ( ! F_29 ( V_2 , V_51 , 0 , 0 , 7 ) )
return - V_86 ;
V_77 = F_30 ( sizeof( * V_77 ) , V_59 ) ;
if ( ! V_77 ) {
F_18 ( V_2 , L_6 ) ;
return - V_60 ;
}
V_75 -> V_79 = V_77 ;
F_21 ( V_2 , 0x00 ) ;
V_84 = strlen ( F_31 ( & V_2 -> V_43 ) ) + strlen ( L_7 ) + 1 ;
for ( V_78 = 0 ; V_78 < 4 ; V_78 ++ ) {
V_72 = F_30 ( sizeof( struct V_71 ) + V_84 , V_59 ) ;
if ( ! V_72 ) {
F_18 ( V_2 , L_8 , V_78 ) ;
goto V_87;
}
V_85 = ( void * ) ( & V_72 [ 1 ] ) ;
snprintf ( V_85 , V_84 , L_9 , F_31 ( & V_2 -> V_43 ) , V_78 + 1 ) ;
V_72 -> V_85 = V_85 ;
V_72 -> V_88 = 0 ;
V_72 -> V_89 = 1 ;
V_72 -> V_90 = F_26 ;
V_72 -> V_91 = F_24 ;
if ( F_32 ( & V_2 -> V_43 , V_72 ) ) {
F_18 ( V_2 , L_10 , V_78 ) ;
F_19 ( V_72 ) ;
goto V_87;
}
V_77 -> V_64 [ V_78 ] = V_72 ;
}
return V_50 ;
V_87:
for ( V_78 = 0 ; V_78 < 4 ; V_78 ++ ) {
V_72 = V_77 -> V_64 [ V_78 ] ;
V_77 -> V_64 [ V_78 ] = NULL ;
if ( ! V_72 )
continue;
F_33 ( V_72 ) ;
F_19 ( V_72 ) ;
}
F_19 ( V_75 -> V_79 ) ;
V_75 -> V_79 = NULL ;
return V_50 ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_23 * V_75 ;
struct V_76 * V_77 ;
struct V_71 * V_72 ;
int V_78 ;
V_75 = F_6 ( V_2 ) ;
F_28 ( ! ( V_75 -> V_25 & V_36 ) ) ;
V_77 = V_75 -> V_79 ;
for ( V_78 = 0 ; V_78 < 4 ; V_78 ++ ) {
V_72 = V_77 -> V_64 [ V_78 ] ;
V_77 -> V_64 [ V_78 ] = NULL ;
if ( ! V_72 )
continue;
F_33 ( V_72 ) ;
F_19 ( V_72 ) ;
}
F_19 ( V_75 -> V_79 ) ;
V_75 -> V_79 = NULL ;
}
static void F_35 ( struct V_92 * V_93 )
{
struct V_23 * V_24 = F_25 ( V_93 , struct V_23 , V_94 ) ;
unsigned char V_38 [] = {
0x01 ,
0x00 , 0xff , 0x00 , 0xff , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x03 ,
0xff , 0x27 , 0x10 , 0x00 , 0x32 ,
0xff , 0x27 , 0x10 , 0x00 , 0x32 ,
0xff , 0x27 , 0x10 , 0x00 , 0x32 ,
0xff , 0x27 , 0x10 , 0x00 , 0x32 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00
} ;
V_38 [ 3 ] = V_24 -> V_95 ;
V_38 [ 5 ] = V_24 -> V_96 ;
V_24 -> V_2 -> V_63 ( V_24 -> V_2 , V_38 , sizeof( V_38 ) ,
V_51 ) ;
}
static int F_36 ( struct V_97 * V_43 , void * V_98 ,
struct V_99 * V_100 )
{
struct V_1 * V_15 = F_37 ( V_43 ) ;
struct V_23 * V_24 = F_6 ( V_15 ) ;
if ( V_100 -> type != V_101 )
return 0 ;
V_24 -> V_96 = V_100 -> V_102 . V_103 . V_104 / 256 ;
V_24 -> V_95 = V_100 -> V_102 . V_103 . V_105 ? 1 : 0 ;
F_38 ( & V_24 -> V_94 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_6 * V_106 = F_22 ( V_2 -> V_107 . V_68 ,
struct V_6 , V_69 ) ;
struct V_97 * V_97 = V_106 -> V_108 ;
struct V_23 * V_24 = F_6 ( V_2 ) ;
V_24 -> V_2 = V_2 ;
F_40 ( & V_24 -> V_94 , F_35 ) ;
F_41 ( V_97 , V_109 , V_101 ) ;
return F_42 ( V_97 , NULL , F_36 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = F_6 ( V_2 ) ;
F_44 ( & V_24 -> V_94 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_43 ( struct V_1 * V_2 )
{
}
static int F_45 ( struct V_1 * V_2 , const struct V_110 * V_111 )
{
int V_50 ;
unsigned long V_25 = V_111 -> V_112 ;
struct V_23 * V_24 ;
unsigned int V_113 = V_114 ;
V_24 = F_46 ( & V_2 -> V_43 , sizeof( * V_24 ) , V_59 ) ;
if ( V_24 == NULL ) {
F_18 ( V_2 , L_11 ) ;
return - V_60 ;
}
V_24 -> V_25 = V_25 ;
F_47 ( V_2 , V_24 ) ;
V_50 = F_48 ( V_2 ) ;
if ( V_50 ) {
F_18 ( V_2 , L_12 ) ;
return V_50 ;
}
if ( V_24 -> V_25 & V_26 )
V_113 |= V_115 ;
else if ( V_24 -> V_25 & V_27 )
V_113 |= V_115 ;
else if ( V_24 -> V_25 & V_28 )
V_113 |= V_115 ;
V_50 = F_49 ( V_2 , V_113 ) ;
if ( V_50 ) {
F_18 ( V_2 , L_13 ) ;
return V_50 ;
}
if ( V_24 -> V_25 & V_27 ) {
V_2 -> V_63 = F_11 ;
V_50 = F_16 ( V_2 ) ;
}
else if ( V_24 -> V_25 & V_28 )
V_50 = F_20 ( V_2 ) ;
else if ( V_24 -> V_25 & V_36 )
V_50 = F_27 ( V_2 ) ;
else
V_50 = 0 ;
if ( V_50 < 0 )
goto V_116;
V_50 = F_39 ( V_2 ) ;
if ( V_50 < 0 )
goto V_116;
return 0 ;
V_116:
F_50 ( V_2 ) ;
return V_50 ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = F_6 ( V_2 ) ;
if ( V_24 -> V_25 & V_36 )
F_34 ( V_2 ) ;
F_43 ( V_2 ) ;
F_50 ( V_2 ) ;
}
