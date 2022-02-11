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
struct V_41 * V_42 = F_12 ( V_2 -> V_43 . V_44 ) ;
struct V_45 * V_43 = F_13 ( V_42 ) ;
T_3 V_59 = V_42 -> V_48 -> V_56 . V_57 ;
int V_50 ;
char * V_38 = F_17 ( 18 , V_60 ) ;
if ( ! V_38 )
return - V_61 ;
V_50 = F_14 ( V_43 , F_18 ( V_43 , 0 ) ,
V_62 ,
V_63 | V_54 |
V_55 ,
( 3 << 8 ) | 0xf2 , V_59 , V_38 , 17 ,
V_64 ) ;
if ( V_50 < 0 )
F_19 ( V_2 , L_4 ) ;
F_20 ( V_38 ) ;
return V_50 ;
}
static int F_21 ( struct V_1 * V_2 )
{
unsigned char V_38 [] = { 0xf4 , 0x42 , 0x03 , 0x00 , 0x00 } ;
return V_2 -> V_65 ( V_2 , V_38 , sizeof( V_38 ) , V_66 ) ;
}
static void F_22 ( struct V_1 * V_2 , int V_67 )
{
struct V_68 * V_69 =
& V_2 -> V_70 [ V_51 ] . V_69 ;
struct V_32 * V_33 = F_23 ( V_69 -> V_71 ,
struct V_32 , V_72 ) ;
T_4 * V_73 = V_33 -> V_9 [ 0 ] -> V_73 ;
V_73 [ 0 ] = 0x00 ;
V_73 [ 1 ] = ( V_67 & 1 ) ? 0xff : 0x00 ;
V_73 [ 2 ] = ( V_67 & 2 ) ? 0xff : 0x00 ;
V_73 [ 3 ] = ( V_67 & 4 ) ? 0xff : 0x00 ;
V_73 [ 4 ] = ( V_67 & 8 ) ? 0xff : 0x00 ;
V_73 [ 5 ] = 0x00 ;
V_73 [ 6 ] = 0x00 ;
F_24 ( V_2 , V_33 , V_52 ) ;
}
static void F_25 ( struct V_74 * V_75 ,
enum V_76 V_73 )
{
struct V_77 * V_43 = V_75 -> V_43 -> V_44 ;
struct V_1 * V_2 = F_26 ( V_43 , struct V_1 , V_43 ) ;
struct V_23 * V_78 ;
struct V_79 * V_80 ;
int V_81 ;
V_78 = F_6 ( V_2 ) ;
if ( ! V_78 || ! V_78 -> V_82 ) {
F_19 ( V_2 , L_5 ) ;
return;
}
V_80 = V_78 -> V_82 ;
for ( V_81 = 0 ; V_81 < 4 ; V_81 ++ ) {
if ( V_75 == V_80 -> V_67 [ V_81 ] ) {
int V_83 = ! ! ( V_80 -> V_84 & ( 1 << V_81 ) ) ;
if ( V_73 == V_85 && V_83 ) {
V_80 -> V_84 &= ~ ( 1 << V_81 ) ;
F_22 ( V_2 , V_80 -> V_84 ) ;
} else if ( V_73 != V_85 && ! V_83 ) {
V_80 -> V_84 |= ( 1 << V_81 ) ;
F_22 ( V_2 , V_80 -> V_84 ) ;
}
break;
}
}
}
static enum V_76 F_27 ( struct V_74 * V_75 )
{
struct V_77 * V_43 = V_75 -> V_43 -> V_44 ;
struct V_1 * V_2 = F_26 ( V_43 , struct V_1 , V_43 ) ;
struct V_23 * V_78 ;
struct V_79 * V_80 ;
int V_81 ;
int V_83 = 0 ;
V_78 = F_6 ( V_2 ) ;
if ( ! V_78 || ! V_78 -> V_82 ) {
F_19 ( V_2 , L_5 ) ;
return V_85 ;
}
V_80 = V_78 -> V_82 ;
for ( V_81 = 0 ; V_81 < 4 ; V_81 ++ ) {
if ( V_75 == V_80 -> V_67 [ V_81 ] ) {
V_83 = ! ! ( V_80 -> V_84 & ( 1 << V_81 ) ) ;
break;
}
}
return V_83 ? V_86 : V_85 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_23 * V_78 ;
struct V_79 * V_80 ;
int V_81 , V_50 = 0 ;
struct V_74 * V_75 ;
T_2 V_87 ;
char * V_88 ;
V_78 = F_6 ( V_2 ) ;
F_29 ( ! ( V_78 -> V_25 & V_36 ) ) ;
if ( ! F_30 ( V_2 , V_51 , 0 , 0 , 7 ) )
return - V_89 ;
V_80 = F_31 ( sizeof( * V_80 ) , V_60 ) ;
if ( ! V_80 ) {
F_19 ( V_2 , L_6 ) ;
return - V_61 ;
}
V_78 -> V_82 = V_80 ;
F_22 ( V_2 , 0x00 ) ;
V_87 = strlen ( F_32 ( & V_2 -> V_43 ) ) + strlen ( L_7 ) + 1 ;
for ( V_81 = 0 ; V_81 < 4 ; V_81 ++ ) {
V_75 = F_31 ( sizeof( struct V_74 ) + V_87 , V_60 ) ;
if ( ! V_75 ) {
F_19 ( V_2 , L_8 , V_81 ) ;
goto V_90;
}
V_88 = ( void * ) ( & V_75 [ 1 ] ) ;
snprintf ( V_88 , V_87 , L_9 , F_32 ( & V_2 -> V_43 ) , V_81 + 1 ) ;
V_75 -> V_88 = V_88 ;
V_75 -> V_91 = 0 ;
V_75 -> V_92 = 1 ;
V_75 -> V_93 = F_27 ;
V_75 -> V_94 = F_25 ;
if ( F_33 ( & V_2 -> V_43 , V_75 ) ) {
F_19 ( V_2 , L_10 , V_81 ) ;
F_20 ( V_75 ) ;
goto V_90;
}
V_80 -> V_67 [ V_81 ] = V_75 ;
}
return V_50 ;
V_90:
for ( V_81 = 0 ; V_81 < 4 ; V_81 ++ ) {
V_75 = V_80 -> V_67 [ V_81 ] ;
V_80 -> V_67 [ V_81 ] = NULL ;
if ( ! V_75 )
continue;
F_34 ( V_75 ) ;
F_20 ( V_75 ) ;
}
F_20 ( V_78 -> V_82 ) ;
V_78 -> V_82 = NULL ;
return V_50 ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_23 * V_78 ;
struct V_79 * V_80 ;
struct V_74 * V_75 ;
int V_81 ;
V_78 = F_6 ( V_2 ) ;
F_29 ( ! ( V_78 -> V_25 & V_36 ) ) ;
V_80 = V_78 -> V_82 ;
for ( V_81 = 0 ; V_81 < 4 ; V_81 ++ ) {
V_75 = V_80 -> V_67 [ V_81 ] ;
V_80 -> V_67 [ V_81 ] = NULL ;
if ( ! V_75 )
continue;
F_34 ( V_75 ) ;
F_20 ( V_75 ) ;
}
F_20 ( V_78 -> V_82 ) ;
V_78 -> V_82 = NULL ;
}
static int F_36 ( struct V_1 * V_2 , const struct V_95 * V_96 )
{
int V_50 ;
unsigned long V_25 = V_96 -> V_97 ;
struct V_23 * V_24 ;
unsigned int V_98 = V_99 ;
V_24 = F_37 ( & V_2 -> V_43 , sizeof( * V_24 ) , V_60 ) ;
if ( V_24 == NULL ) {
F_19 ( V_2 , L_11 ) ;
return - V_61 ;
}
V_24 -> V_25 = V_25 ;
F_38 ( V_2 , V_24 ) ;
V_50 = F_39 ( V_2 ) ;
if ( V_50 ) {
F_19 ( V_2 , L_12 ) ;
return V_50 ;
}
if ( V_24 -> V_25 & V_26 )
V_98 |= V_100 ;
else if ( V_24 -> V_25 & V_27 )
V_98 |= V_100 ;
else if ( V_24 -> V_25 & V_28 )
V_98 |= V_100 ;
V_50 = F_40 ( V_2 , V_98 ) ;
if ( V_50 ) {
F_19 ( V_2 , L_13 ) ;
return V_50 ;
}
if ( V_24 -> V_25 & V_27 ) {
V_2 -> V_65 = F_11 ;
V_50 = F_16 ( V_2 ) ;
}
else if ( V_24 -> V_25 & V_28 )
V_50 = F_21 ( V_2 ) ;
else if ( V_24 -> V_25 & V_36 )
V_50 = F_28 ( V_2 ) ;
else
V_50 = 0 ;
if ( V_50 < 0 )
goto V_101;
return 0 ;
V_101:
F_41 ( V_2 ) ;
return V_50 ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = F_6 ( V_2 ) ;
if ( V_24 -> V_25 & V_36 )
F_35 ( V_2 ) ;
F_41 ( V_2 ) ;
}
