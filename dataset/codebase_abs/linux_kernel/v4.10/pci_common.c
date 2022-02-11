static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 ,
unsigned long V_4 ,
unsigned long V_5 )
{
if ( V_3 < V_2 -> V_6 ||
V_3 > V_2 -> V_7 )
return 1 ;
return 0 ;
}
static void * F_2 ( struct V_1 * V_2 ,
unsigned long V_3 ,
unsigned long V_4 ,
unsigned long V_5 )
{
unsigned long V_8 = V_2 -> V_9 ;
if ( F_1 ( V_2 , V_3 , V_4 , V_5 ) )
return NULL ;
V_5 = ( V_5 & ( ( 1 << V_8 ) - 1 ) ) ;
V_4 <<= V_8 ;
V_3 <<= V_8 + 8 ;
return ( void * ) ( V_2 -> V_10 | V_3 | V_4 | V_5 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned int V_4 ,
int V_11 , int V_12 , T_1 * V_13 )
{
T_1 V_14 , * V_15 ;
T_2 V_16 ;
T_3 V_17 ;
V_15 = F_2 ( V_2 , V_3 , V_4 , V_11 ) ;
if ( ! V_15 )
return V_18 ;
switch ( V_12 ) {
case 1 :
if ( V_11 < 8 ) {
unsigned long V_19 = ( unsigned long ) V_15 ;
V_19 &= ~ 1 ;
F_4 ( ( T_2 * ) V_19 , & V_16 ) ;
if ( V_11 & 1 )
* V_13 = V_16 >> 8 ;
else
* V_13 = V_16 & 0xff ;
} else {
F_5 ( ( T_3 * ) V_15 , & V_17 ) ;
* V_13 = ( T_1 ) V_17 ;
}
break;
case 2 :
if ( V_11 < 8 ) {
F_4 ( ( T_2 * ) V_15 , & V_16 ) ;
* V_13 = ( T_1 ) V_16 ;
} else {
F_5 ( ( T_3 * ) V_15 , & V_17 ) ;
* V_13 = ( T_1 ) V_17 ;
F_5 ( ( ( T_3 * ) V_15 ) + 1 , & V_17 ) ;
* V_13 |= ( ( T_1 ) V_17 ) << 8 ;
}
break;
case 4 :
V_14 = 0xffffffff ;
F_3 ( V_2 , V_3 , V_4 ,
V_11 , 2 , & V_14 ) ;
* V_13 = V_14 ;
V_14 = 0xffffffff ;
F_3 ( V_2 , V_3 , V_4 ,
V_11 + 2 , 2 , & V_14 ) ;
* V_13 |= V_14 << 16 ;
break;
}
return V_18 ;
}
static int F_6 ( struct V_20 * V_21 , unsigned int V_4 ,
int V_11 , int V_12 , T_1 * V_13 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
unsigned char V_3 = V_21 -> V_23 ;
T_1 * V_15 ;
T_2 V_16 ;
T_3 V_17 ;
switch ( V_12 ) {
case 1 :
* V_13 = 0xff ;
break;
case 2 :
* V_13 = 0xffff ;
break;
case 4 :
* V_13 = 0xffffffff ;
break;
}
if ( ! V_21 -> V_23 && ! F_7 ( V_4 ) )
return F_3 ( V_2 , V_3 , V_4 , V_11 ,
V_12 , V_13 ) ;
V_15 = F_2 ( V_2 , V_3 , V_4 , V_11 ) ;
if ( ! V_15 )
return V_18 ;
switch ( V_12 ) {
case 1 :
F_5 ( ( T_3 * ) V_15 , & V_17 ) ;
* V_13 = ( T_1 ) V_17 ;
break;
case 2 :
if ( V_11 & 0x01 ) {
F_8 ( L_1 ,
V_11 ) ;
return V_18 ;
}
F_4 ( ( T_2 * ) V_15 , & V_16 ) ;
* V_13 = ( T_1 ) V_16 ;
break;
case 4 :
if ( V_11 & 0x03 ) {
F_8 ( L_2 ,
V_11 ) ;
return V_18 ;
}
F_9 ( V_15 , V_13 ) ;
break;
}
return V_18 ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned int V_4 ,
int V_11 , int V_12 , T_1 V_13 )
{
T_1 * V_15 ;
V_15 = F_2 ( V_2 , V_3 , V_4 , V_11 ) ;
if ( ! V_15 )
return V_18 ;
switch ( V_12 ) {
case 1 :
if ( V_11 < 8 ) {
unsigned long V_19 = ( unsigned long ) V_15 ;
T_2 V_16 ;
V_19 &= ~ 1 ;
F_4 ( ( T_2 * ) V_19 , & V_16 ) ;
if ( V_11 & 1 ) {
V_16 &= 0x00ff ;
V_16 |= V_13 << 8 ;
} else {
V_16 &= 0xff00 ;
V_16 |= V_13 ;
}
F_11 ( ( T_2 * ) V_19 , V_16 ) ;
} else
F_12 ( ( T_3 * ) V_15 , V_13 ) ;
break;
case 2 :
if ( V_11 < 8 ) {
F_11 ( ( T_2 * ) V_15 , V_13 ) ;
} else {
F_12 ( ( T_3 * ) V_15 , V_13 & 0xff ) ;
F_12 ( ( ( T_3 * ) V_15 ) + 1 , V_13 >> 8 ) ;
}
break;
case 4 :
F_10 ( V_2 , V_3 , V_4 ,
V_11 , 2 , V_13 & 0xffff ) ;
F_10 ( V_2 , V_3 , V_4 ,
V_11 + 2 , 2 , V_13 >> 16 ) ;
break;
}
return V_18 ;
}
static int F_13 ( struct V_20 * V_21 , unsigned int V_4 ,
int V_11 , int V_12 , T_1 V_13 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
unsigned char V_3 = V_21 -> V_23 ;
T_1 * V_15 ;
if ( ! V_21 -> V_23 && ! F_7 ( V_4 ) )
return F_10 ( V_2 , V_3 , V_4 , V_11 ,
V_12 , V_13 ) ;
V_15 = F_2 ( V_2 , V_3 , V_4 , V_11 ) ;
if ( ! V_15 )
return V_18 ;
switch ( V_12 ) {
case 1 :
F_12 ( ( T_3 * ) V_15 , V_13 ) ;
break;
case 2 :
if ( V_11 & 0x01 ) {
F_8 ( L_3 ,
V_11 ) ;
return V_18 ;
}
F_11 ( ( T_2 * ) V_15 , V_13 ) ;
break;
case 4 :
if ( V_11 & 0x03 ) {
F_8 ( L_4 ,
V_11 ) ;
return V_18 ;
}
F_14 ( V_15 , V_13 ) ;
}
return V_18 ;
}
static int F_15 ( struct V_20 * V_21 , unsigned int V_4 ,
int V_11 , int V_12 , T_1 * V_13 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
T_1 V_24 = V_2 -> V_24 ;
unsigned int V_3 = V_21 -> V_23 ;
unsigned int V_25 = F_7 ( V_4 ) ;
unsigned int V_26 = F_16 ( V_4 ) ;
unsigned long V_27 ;
if ( F_1 ( V_2 , V_3 , V_4 , V_11 ) ) {
V_27 = ~ 0UL ;
} else {
V_27 = F_17 ( V_24 ,
F_18 ( V_3 , V_25 , V_26 ) ,
V_11 , V_12 ) ;
}
switch ( V_12 ) {
case 1 :
* V_13 = V_27 & 0xff ;
break;
case 2 :
* V_13 = V_27 & 0xffff ;
break;
case 4 :
* V_13 = V_27 & 0xffffffff ;
break;
}
return V_18 ;
}
static int F_19 ( struct V_20 * V_21 , unsigned int V_4 ,
int V_11 , int V_12 , T_1 V_13 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
T_1 V_24 = V_2 -> V_24 ;
unsigned int V_3 = V_21 -> V_23 ;
unsigned int V_25 = F_7 ( V_4 ) ;
unsigned int V_26 = F_16 ( V_4 ) ;
if ( F_1 ( V_2 , V_3 , V_4 , V_11 ) ) {
} else {
F_20 ( V_24 ,
F_18 ( V_3 , V_25 , V_26 ) ,
V_11 , V_12 , V_13 ) ;
}
return V_18 ;
}
void F_21 ( struct V_1 * V_2 )
{
const T_1 * V_28 = F_22 ( V_2 -> V_29 -> V_30 . V_31 , L_5 , NULL ) ;
V_2 -> V_6 = V_28 [ 0 ] ;
V_2 -> V_7 = V_28 [ 1 ] ;
V_28 = F_22 ( V_2 -> V_29 -> V_30 . V_31 , L_6 , NULL ) ;
if ( V_28 ) {
V_2 -> V_32 = ( ( ( V_33 ) V_28 [ 1 ] << 32UL ) |
( ( V_33 ) V_28 [ 0 ] << 0UL ) ) ;
}
}
static void F_23 ( struct V_34 * V_35 ,
struct V_34 * V_36 )
{
struct V_34 * V_37 ;
V_37 = F_24 ( sizeof( * V_37 ) , V_38 ) ;
if ( ! V_37 )
return;
V_37 -> V_39 = L_7 ;
V_37 -> V_40 = V_36 -> V_40 + 0xa0000UL ;
V_37 -> V_41 = V_37 -> V_40 + 0x1ffffUL ;
V_37 -> V_42 = V_43 ;
F_25 ( V_36 , V_37 ) ;
V_37 = F_24 ( sizeof( * V_37 ) , V_38 ) ;
if ( ! V_37 )
return;
V_37 -> V_39 = L_8 ;
V_37 -> V_40 = V_36 -> V_40 + 0xf0000UL ;
V_37 -> V_41 = V_37 -> V_40 + 0xffffUL ;
V_37 -> V_42 = V_43 ;
F_25 ( V_36 , V_37 ) ;
V_37 = F_24 ( sizeof( * V_37 ) , V_38 ) ;
if ( ! V_37 )
return;
V_37 -> V_39 = L_9 ;
V_37 -> V_40 = V_36 -> V_40 + 0xc0000UL ;
V_37 -> V_41 = V_37 -> V_40 + 0x7fffUL ;
V_37 -> V_42 = V_43 ;
F_25 ( V_36 , V_37 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
const T_1 * V_44 = F_22 ( V_2 -> V_29 -> V_30 . V_31 , L_10 ,
NULL ) ;
if ( V_44 ) {
struct V_34 * V_45 = F_24 ( sizeof( * V_45 ) , V_38 ) ;
if ( ! V_45 ) {
F_27 ( L_11 ,
V_2 -> V_39 ) ;
return;
}
V_45 -> V_39 = L_12 ;
V_45 -> V_40 = V_2 -> V_46 . V_40 + ( unsigned long ) V_44 [ 0 ] ;
V_45 -> V_41 = V_45 -> V_40 + ( unsigned long ) V_44 [ 1 ] - 1UL ;
V_45 -> V_42 = V_43 ;
if ( F_25 ( & V_2 -> V_46 , V_45 ) ) {
F_27 ( L_13 ,
V_2 -> V_39 ) ;
F_28 ( V_45 ) ;
}
}
}
void F_29 ( struct V_1 * V_2 )
{
const struct V_47 * V_48 ;
int V_49 , V_50 , V_51 ;
int V_52 ;
V_50 = V_51 = 0 ;
V_48 = F_22 ( V_2 -> V_29 -> V_30 . V_31 , L_14 , & V_49 ) ;
if ( ! V_48 ) {
F_30 ( L_15
L_16 ,
V_2 -> V_39 ) ;
F_31 () ;
}
V_52 = V_49 / sizeof( * V_48 ) ;
memset ( & V_2 -> V_53 , 0 , sizeof( struct V_34 ) ) ;
for ( V_49 = 0 ; V_49 < V_52 ; V_49 ++ ) {
const struct V_47 * V_54 = & V_48 [ V_49 ] ;
unsigned long V_55 , V_12 ;
T_1 V_56 , V_57 ;
T_1 V_58 , V_59 ;
int type ;
V_56 = V_54 -> V_56 ;
V_57 = V_54 -> V_57 ;
if ( V_60 == V_61 )
V_56 &= 0x0fffffff ;
V_58 = V_54 -> V_58 ;
V_59 = V_54 -> V_59 ;
type = ( V_54 -> V_62 >> 24 ) & 0x3 ;
V_55 = ( ( ( unsigned long ) V_56 << 32UL ) |
( ( unsigned long ) V_57 << 0UL ) ) ;
V_12 = ( ( ( unsigned long ) V_58 << 32UL ) |
( ( unsigned long ) V_59 << 0UL ) ) ;
switch ( type ) {
case 0 :
V_2 -> V_10 = V_55 ;
break;
case 1 :
V_2 -> V_63 . V_40 = V_55 ;
V_2 -> V_63 . V_41 = V_55 + V_12 - 1UL ;
V_2 -> V_63 . V_42 = V_64 ;
V_51 = 1 ;
break;
case 2 :
V_2 -> V_46 . V_40 = V_55 ;
V_2 -> V_46 . V_41 = V_55 + V_12 - 1UL ;
V_2 -> V_46 . V_42 = V_65 ;
V_50 = 1 ;
break;
case 3 :
V_2 -> V_53 . V_40 = V_55 ;
V_2 -> V_53 . V_41 = V_55 + V_12 - 1UL ;
V_2 -> V_53 . V_42 = V_65 ;
V_50 = 1 ;
break;
default:
break;
}
}
if ( ! V_51 || ! V_50 ) {
F_30 ( L_17 ,
V_2 -> V_39 ,
( ! V_51 ? L_18 : L_19 ) ) ;
F_31 () ;
}
F_8 ( L_20 ,
V_2 -> V_39 ,
V_2 -> V_63 . V_40 ,
V_2 -> V_46 . V_40 ) ;
if ( V_2 -> V_53 . V_42 )
F_8 ( L_21 ,
V_2 -> V_53 . V_40 ) ;
F_8 ( L_22 ) ;
V_2 -> V_63 . V_39 = V_2 -> V_46 . V_39 = V_2 -> V_39 ;
V_2 -> V_53 . V_39 = V_2 -> V_39 ;
F_25 ( & V_66 , & V_2 -> V_63 ) ;
F_25 ( & V_67 , & V_2 -> V_46 ) ;
if ( V_2 -> V_53 . V_42 )
F_25 ( & V_67 , & V_2 -> V_53 ) ;
F_23 ( & V_2 -> V_63 ,
& V_2 -> V_46 ) ;
F_26 ( V_2 ) ;
}
void F_32 ( struct V_1 * V_2 ,
struct V_20 * V_68 )
{
struct V_69 * V_70 ;
struct V_20 * V_3 ;
F_33 (pdev, &pbus->devices, bus_list) {
T_2 V_71 , V_72 ;
F_34 ( V_70 , V_73 , & V_71 ) ;
V_72 =
( V_71 & ( V_74 |
V_75 ) ) ;
if ( V_72 ) {
F_35 ( V_70 , V_73 , V_72 ) ;
F_8 ( L_23 ,
V_2 -> V_39 , F_36 ( V_70 ) , V_71 ) ;
}
}
F_33 (bus, &pbus->children, node)
F_32 ( V_2 , V_3 ) ;
}
void F_37 ( struct V_1 * V_2 ,
struct V_20 * V_68 )
{
struct V_69 * V_70 ;
struct V_20 * V_3 ;
F_33 (pdev, &pbus->devices, bus_list) {
T_2 V_71 , V_72 ;
F_34 ( V_70 , V_73 , & V_71 ) ;
V_72 =
( V_71 & ( V_76 ) ) ;
if ( V_72 ) {
F_35 ( V_70 , V_73 , V_72 ) ;
F_8 ( L_24 ,
V_2 -> V_39 , F_36 ( V_70 ) , V_71 ) ;
}
}
F_33 (bus, &pbus->children, node)
F_37 ( V_2 , V_3 ) ;
}
void F_38 ( struct V_1 * V_2 ,
struct V_20 * V_68 )
{
struct V_69 * V_70 ;
struct V_20 * V_3 ;
F_33 (pdev, &pbus->devices, bus_list) {
T_2 V_71 , V_72 ;
F_34 ( V_70 , V_73 , & V_71 ) ;
V_72 =
( V_71 & ( V_77 |
V_78 ) ) ;
if ( V_72 ) {
F_35 ( V_70 , V_73 , V_72 ) ;
F_8 ( L_25 ,
V_2 -> V_39 , F_36 ( V_70 ) , V_71 ) ;
}
}
F_33 (bus, &pbus->children, node)
F_38 ( V_2 , V_3 ) ;
}
