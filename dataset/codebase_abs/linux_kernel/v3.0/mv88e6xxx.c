static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < 16 ; V_5 ++ ) {
V_4 = F_2 ( V_2 , V_3 , 0 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( ( V_4 & 0x8000 ) == 0 )
return 0 ;
}
return - V_6 ;
}
int F_3 ( struct V_1 * V_2 , int V_3 , int V_7 , int V_8 )
{
int V_4 ;
if ( V_3 == 0 )
return F_2 ( V_2 , V_7 , V_8 ) ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_4 ( V_2 , V_3 , 0 , 0x9800 | ( V_7 << 5 ) | V_8 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_2 ( V_2 , V_3 , 1 ) ;
if ( V_4 < 0 )
return V_4 ;
return V_4 & 0xffff ;
}
int F_5 ( struct V_9 * V_10 , int V_7 , int V_8 )
{
struct V_11 * V_12 = ( void * ) ( V_10 + 1 ) ;
int V_4 ;
F_6 ( & V_12 -> V_13 ) ;
V_4 = F_3 ( V_10 -> V_14 ,
V_10 -> V_15 -> V_3 , V_7 , V_8 ) ;
F_7 ( & V_12 -> V_13 ) ;
return V_4 ;
}
int F_8 ( struct V_1 * V_2 , int V_3 , int V_7 ,
int V_8 , T_1 V_16 )
{
int V_4 ;
if ( V_3 == 0 )
return F_4 ( V_2 , V_7 , V_8 , V_16 ) ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_4 ( V_2 , V_3 , 1 , V_16 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_4 ( V_2 , V_3 , 0 , 0x9400 | ( V_7 << 5 ) | V_8 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
return 0 ;
}
int F_9 ( struct V_9 * V_10 , int V_7 , int V_8 , T_1 V_16 )
{
struct V_11 * V_12 = ( void * ) ( V_10 + 1 ) ;
int V_4 ;
F_6 ( & V_12 -> V_13 ) ;
V_4 = F_8 ( V_10 -> V_14 ,
V_10 -> V_15 -> V_3 , V_7 , V_8 , V_16 ) ;
F_7 ( & V_12 -> V_13 ) ;
return V_4 ;
}
int F_10 ( struct V_9 * V_10 )
{
F_11 ( V_17 , 0x10 , 0x0000 ) ;
F_11 ( V_17 , 0x11 , 0x0000 ) ;
F_11 ( V_17 , 0x12 , 0x5555 ) ;
F_11 ( V_17 , 0x13 , 0x5555 ) ;
F_11 ( V_17 , 0x14 , 0xaaaa ) ;
F_11 ( V_17 , 0x15 , 0xaaaa ) ;
F_11 ( V_17 , 0x16 , 0xffff ) ;
F_11 ( V_17 , 0x17 , 0xffff ) ;
F_11 ( V_17 , 0x18 , 0xfa41 ) ;
return 0 ;
}
int F_12 ( struct V_9 * V_10 , T_2 * V_7 )
{
F_11 ( V_17 , 0x01 , ( V_7 [ 0 ] << 8 ) | V_7 [ 1 ] ) ;
F_11 ( V_17 , 0x02 , ( V_7 [ 2 ] << 8 ) | V_7 [ 3 ] ) ;
F_11 ( V_17 , 0x03 , ( V_7 [ 4 ] << 8 ) | V_7 [ 5 ] ) ;
return 0 ;
}
int F_13 ( struct V_9 * V_10 , T_2 * V_7 )
{
int V_5 ;
int V_4 ;
for ( V_5 = 0 ; V_5 < 6 ; V_5 ++ ) {
int V_18 ;
F_11 ( V_19 , 0x0d , 0x8000 | ( V_5 << 8 ) | V_7 [ V_5 ] ) ;
for ( V_18 = 0 ; V_18 < 16 ; V_18 ++ ) {
V_4 = F_14 ( V_19 , 0x0d ) ;
if ( ( V_4 & 0x8000 ) == 0 )
break;
}
if ( V_18 == 16 )
return - V_6 ;
}
return 0 ;
}
int F_15 ( struct V_9 * V_10 , int V_7 , int V_20 )
{
if ( V_7 >= 0 )
return F_5 ( V_10 , V_7 , V_20 ) ;
return 0xffff ;
}
int F_16 ( struct V_9 * V_10 , int V_7 , int V_20 , T_1 V_16 )
{
if ( V_7 >= 0 )
return F_9 ( V_10 , V_7 , V_20 , V_16 ) ;
return 0 ;
}
static int F_17 ( struct V_9 * V_10 )
{
int V_4 ;
int V_5 ;
V_4 = F_14 ( V_17 , 0x04 ) ;
F_11 ( V_17 , 0x04 , V_4 & ~ 0x4000 ) ;
for ( V_5 = 0 ; V_5 < 1000 ; V_5 ++ ) {
V_4 = F_14 ( V_17 , 0x00 ) ;
F_18 ( 1 ) ;
if ( ( V_4 & 0xc000 ) != 0xc000 )
return 0 ;
}
return - V_6 ;
}
static int F_19 ( struct V_9 * V_10 )
{
int V_4 ;
int V_5 ;
V_4 = F_14 ( V_17 , 0x04 ) ;
F_11 ( V_17 , 0x04 , V_4 | 0x4000 ) ;
for ( V_5 = 0 ; V_5 < 1000 ; V_5 ++ ) {
V_4 = F_14 ( V_17 , 0x00 ) ;
F_18 ( 1 ) ;
if ( ( V_4 & 0xc000 ) == 0xc000 )
return 0 ;
}
return - V_6 ;
}
static void F_20 ( struct V_21 * V_22 )
{
struct V_11 * V_12 ;
V_12 = F_21 ( V_22 , struct V_11 , V_23 ) ;
if ( F_22 ( & V_12 -> V_24 ) ) {
struct V_9 * V_10 = ( (struct V_9 * ) V_12 ) - 1 ;
if ( F_19 ( V_10 ) == 0 )
V_12 -> V_25 = 0 ;
F_7 ( & V_12 -> V_24 ) ;
}
}
static void F_23 ( unsigned long V_26 )
{
struct V_11 * V_12 = ( void * ) V_26 ;
F_24 ( & V_12 -> V_23 ) ;
}
static int F_25 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = ( void * ) ( V_10 + 1 ) ;
int V_4 ;
F_6 ( & V_12 -> V_24 ) ;
if ( ! V_12 -> V_25 ) {
V_4 = F_17 ( V_10 ) ;
if ( V_4 < 0 ) {
F_7 ( & V_12 -> V_24 ) ;
return V_4 ;
}
V_12 -> V_25 = 1 ;
} else {
F_26 ( & V_12 -> V_27 ) ;
V_4 = 0 ;
}
return V_4 ;
}
static void F_27 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = ( void * ) ( V_10 + 1 ) ;
F_28 ( & V_12 -> V_27 , V_28 + F_29 ( 10 ) ) ;
F_7 ( & V_12 -> V_24 ) ;
}
void F_30 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = ( void * ) ( V_10 + 1 ) ;
F_31 ( & V_12 -> V_24 ) ;
F_32 ( & V_12 -> V_23 , F_20 ) ;
F_33 ( & V_12 -> V_27 ) ;
V_12 -> V_27 . V_29 = ( unsigned long ) V_12 ;
V_12 -> V_27 . V_30 = F_23 ;
}
int F_34 ( struct V_9 * V_10 , int V_7 , int V_20 )
{
int V_4 ;
V_4 = F_25 ( V_10 ) ;
if ( V_4 >= 0 ) {
V_4 = F_5 ( V_10 , V_7 , V_20 ) ;
F_27 ( V_10 ) ;
}
return V_4 ;
}
int F_35 ( struct V_9 * V_10 , int V_7 ,
int V_20 , T_1 V_16 )
{
int V_4 ;
V_4 = F_25 ( V_10 ) ;
if ( V_4 >= 0 ) {
V_4 = F_9 ( V_10 , V_7 , V_20 , V_16 ) ;
F_27 ( V_10 ) ;
}
return V_4 ;
}
void F_36 ( struct V_9 * V_10 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_31 ; V_5 ++ ) {
struct V_32 * V_33 ;
int V_34 ( V_35 ) ;
int V_36 ;
int V_37 ;
int V_38 ;
int V_39 ;
V_33 = V_10 -> V_40 [ V_5 ] ;
if ( V_33 == NULL )
continue;
V_36 = 0 ;
if ( V_33 -> V_41 & V_42 ) {
V_35 = F_5 ( V_10 , F_37 ( V_5 ) , 0x00 ) ;
if ( V_35 < 0 )
continue;
V_36 = ! ! ( V_35 & 0x0800 ) ;
}
if ( ! V_36 ) {
if ( F_38 ( V_33 ) ) {
F_39 ( V_43 L_1 , V_33 -> V_44 ) ;
F_40 ( V_33 ) ;
}
continue;
}
switch ( V_35 & 0x0300 ) {
case 0x0000 :
V_37 = 10 ;
break;
case 0x0100 :
V_37 = 100 ;
break;
case 0x0200 :
V_37 = 1000 ;
break;
default:
V_37 = - 1 ;
break;
}
V_38 = ( V_35 & 0x0400 ) ? 1 : 0 ;
V_39 = ( V_35 & 0x8000 ) ? 1 : 0 ;
if ( ! F_38 ( V_33 ) ) {
F_39 ( V_43 L_2
L_3 , V_33 -> V_44 ,
V_37 , V_38 ? L_4 : L_5 ,
V_39 ? L_6 : L_7 ) ;
F_41 ( V_33 ) ;
}
}
}
static int F_42 ( struct V_9 * V_10 )
{
int V_4 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < 10 ; V_5 ++ ) {
V_4 = F_14 ( V_17 , 0x1d ) ;
if ( ( V_4 & 0x8000 ) == 0 )
return 0 ;
}
return - V_6 ;
}
static int F_43 ( struct V_9 * V_10 , int V_45 )
{
int V_4 ;
F_11 ( V_17 , 0x1d , 0xdc00 | V_45 ) ;
V_4 = F_42 ( V_10 ) ;
if ( V_4 < 0 )
return V_4 ;
return 0 ;
}
static void F_44 ( struct V_9 * V_10 , int V_46 , T_3 * V_16 )
{
T_3 V_47 ;
int V_4 ;
* V_16 = 0 ;
V_4 = F_9 ( V_10 , V_17 , 0x1d , 0xcc00 | V_46 ) ;
if ( V_4 < 0 )
return;
V_4 = F_42 ( V_10 ) ;
if ( V_4 < 0 )
return;
V_4 = F_5 ( V_10 , V_17 , 0x1e ) ;
if ( V_4 < 0 )
return;
V_47 = V_4 << 16 ;
V_4 = F_5 ( V_10 , V_17 , 0x1f ) ;
if ( V_4 < 0 )
return;
* V_16 = V_47 | V_4 ;
}
void F_45 ( struct V_9 * V_10 ,
int V_48 , struct V_49 * V_50 ,
int V_45 , T_4 * V_29 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_48 ; V_5 ++ ) {
memcpy ( V_29 + V_5 * V_51 ,
V_50 [ V_5 ] . string , V_51 ) ;
}
}
void F_46 ( struct V_9 * V_10 ,
int V_48 , struct V_49 * V_50 ,
int V_45 , T_5 * V_29 )
{
struct V_11 * V_12 = ( void * ) ( V_10 + 1 ) ;
int V_4 ;
int V_5 ;
F_6 ( & V_12 -> V_52 ) ;
V_4 = F_43 ( V_10 , V_45 ) ;
if ( V_4 < 0 ) {
F_7 ( & V_12 -> V_52 ) ;
return;
}
for ( V_5 = 0 ; V_5 < V_48 ; V_5 ++ ) {
struct V_49 * V_53 = V_50 + V_5 ;
T_3 V_54 ;
T_3 V_55 ;
F_44 ( V_10 , V_53 -> V_8 , & V_54 ) ;
if ( V_53 -> V_56 == 8 )
F_44 ( V_10 , V_53 -> V_8 + 1 , & V_55 ) ;
else
V_55 = 0 ;
V_29 [ V_5 ] = ( ( ( V_57 ) V_55 ) << 32 ) | V_54 ;
}
F_7 ( & V_12 -> V_52 ) ;
}
