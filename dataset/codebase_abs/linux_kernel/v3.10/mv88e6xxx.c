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
unsigned long V_21 ;
V_4 = F_14 ( V_17 , 0x04 ) ;
F_11 ( V_17 , 0x04 , V_4 & ~ 0x4000 ) ;
V_21 = V_22 + 1 * V_23 ;
while ( F_18 ( V_22 , V_21 ) ) {
V_4 = F_14 ( V_17 , 0x00 ) ;
F_19 ( 1000 , 2000 ) ;
if ( ( V_4 & 0xc000 ) != 0xc000 )
return 0 ;
}
return - V_6 ;
}
static int F_20 ( struct V_9 * V_10 )
{
int V_4 ;
unsigned long V_21 ;
V_4 = F_14 ( V_17 , 0x04 ) ;
F_11 ( V_17 , 0x04 , V_4 | 0x4000 ) ;
V_21 = V_22 + 1 * V_23 ;
while ( F_18 ( V_22 , V_21 ) ) {
V_4 = F_14 ( V_17 , 0x00 ) ;
F_19 ( 1000 , 2000 ) ;
if ( ( V_4 & 0xc000 ) == 0xc000 )
return 0 ;
}
return - V_6 ;
}
static void F_21 ( struct V_24 * V_25 )
{
struct V_11 * V_12 ;
V_12 = F_22 ( V_25 , struct V_11 , V_26 ) ;
if ( F_23 ( & V_12 -> V_27 ) ) {
struct V_9 * V_10 = ( (struct V_9 * ) V_12 ) - 1 ;
if ( F_20 ( V_10 ) == 0 )
V_12 -> V_28 = 0 ;
F_7 ( & V_12 -> V_27 ) ;
}
}
static void F_24 ( unsigned long V_29 )
{
struct V_11 * V_12 = ( void * ) V_29 ;
F_25 ( & V_12 -> V_26 ) ;
}
static int F_26 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = ( void * ) ( V_10 + 1 ) ;
int V_4 ;
F_6 ( & V_12 -> V_27 ) ;
if ( ! V_12 -> V_28 ) {
V_4 = F_17 ( V_10 ) ;
if ( V_4 < 0 ) {
F_7 ( & V_12 -> V_27 ) ;
return V_4 ;
}
V_12 -> V_28 = 1 ;
} else {
F_27 ( & V_12 -> V_30 ) ;
V_4 = 0 ;
}
return V_4 ;
}
static void F_28 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = ( void * ) ( V_10 + 1 ) ;
F_29 ( & V_12 -> V_30 , V_22 + F_30 ( 10 ) ) ;
F_7 ( & V_12 -> V_27 ) ;
}
void F_31 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = ( void * ) ( V_10 + 1 ) ;
F_32 ( & V_12 -> V_27 ) ;
F_33 ( & V_12 -> V_26 , F_21 ) ;
F_34 ( & V_12 -> V_30 ) ;
V_12 -> V_30 . V_31 = ( unsigned long ) V_12 ;
V_12 -> V_30 . V_32 = F_24 ;
}
int F_35 ( struct V_9 * V_10 , int V_7 , int V_20 )
{
int V_4 ;
V_4 = F_26 ( V_10 ) ;
if ( V_4 >= 0 ) {
V_4 = F_5 ( V_10 , V_7 , V_20 ) ;
F_28 ( V_10 ) ;
}
return V_4 ;
}
int F_36 ( struct V_9 * V_10 , int V_7 ,
int V_20 , T_1 V_16 )
{
int V_4 ;
V_4 = F_26 ( V_10 ) ;
if ( V_4 >= 0 ) {
V_4 = F_9 ( V_10 , V_7 , V_20 , V_16 ) ;
F_28 ( V_10 ) ;
}
return V_4 ;
}
void F_37 ( struct V_9 * V_10 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_33 ; V_5 ++ ) {
struct V_34 * V_35 ;
int V_36 ( V_37 ) ;
int V_38 ;
int V_39 ;
int V_40 ;
int V_41 ;
V_35 = V_10 -> V_42 [ V_5 ] ;
if ( V_35 == NULL )
continue;
V_38 = 0 ;
if ( V_35 -> V_43 & V_44 ) {
V_37 = F_5 ( V_10 , F_38 ( V_5 ) , 0x00 ) ;
if ( V_37 < 0 )
continue;
V_38 = ! ! ( V_37 & 0x0800 ) ;
}
if ( ! V_38 ) {
if ( F_39 ( V_35 ) ) {
F_40 ( V_35 , L_1 ) ;
F_41 ( V_35 ) ;
}
continue;
}
switch ( V_37 & 0x0300 ) {
case 0x0000 :
V_39 = 10 ;
break;
case 0x0100 :
V_39 = 100 ;
break;
case 0x0200 :
V_39 = 1000 ;
break;
default:
V_39 = - 1 ;
break;
}
V_40 = ( V_37 & 0x0400 ) ? 1 : 0 ;
V_41 = ( V_37 & 0x8000 ) ? 1 : 0 ;
if ( ! F_39 ( V_35 ) ) {
F_40 ( V_35 ,
L_2 ,
V_39 ,
V_40 ? L_3 : L_4 ,
V_41 ? L_5 : L_6 ) ;
F_42 ( V_35 ) ;
}
}
}
static int F_43 ( struct V_9 * V_10 )
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
static int F_44 ( struct V_9 * V_10 , int V_45 )
{
int V_4 ;
F_11 ( V_17 , 0x1d , 0xdc00 | V_45 ) ;
V_4 = F_43 ( V_10 ) ;
if ( V_4 < 0 )
return V_4 ;
return 0 ;
}
static void F_45 ( struct V_9 * V_10 , int V_46 , T_3 * V_16 )
{
T_3 V_47 ;
int V_4 ;
* V_16 = 0 ;
V_4 = F_9 ( V_10 , V_17 , 0x1d , 0xcc00 | V_46 ) ;
if ( V_4 < 0 )
return;
V_4 = F_43 ( V_10 ) ;
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
void F_46 ( struct V_9 * V_10 ,
int V_48 , struct V_49 * V_50 ,
int V_45 , T_4 * V_31 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_48 ; V_5 ++ ) {
memcpy ( V_31 + V_5 * V_51 ,
V_50 [ V_5 ] . string , V_51 ) ;
}
}
void F_47 ( struct V_9 * V_10 ,
int V_48 , struct V_49 * V_50 ,
int V_45 , T_5 * V_31 )
{
struct V_11 * V_12 = ( void * ) ( V_10 + 1 ) ;
int V_4 ;
int V_5 ;
F_6 ( & V_12 -> V_52 ) ;
V_4 = F_44 ( V_10 , V_45 ) ;
if ( V_4 < 0 ) {
F_7 ( & V_12 -> V_52 ) ;
return;
}
for ( V_5 = 0 ; V_5 < V_48 ; V_5 ++ ) {
struct V_49 * V_53 = V_50 + V_5 ;
T_3 V_54 ;
T_3 V_55 ;
F_45 ( V_10 , V_53 -> V_8 , & V_54 ) ;
if ( V_53 -> V_56 == 8 )
F_45 ( V_10 , V_53 -> V_8 + 1 , & V_55 ) ;
else
V_55 = 0 ;
V_31 [ V_5 ] = ( ( ( V_57 ) V_55 ) << 32 ) | V_54 ;
}
F_7 ( & V_12 -> V_52 ) ;
}
static int T_6 F_48 ( void )
{
#if F_49 ( V_58 )
F_50 ( & V_59 ) ;
#endif
#if F_49 ( V_60 )
F_50 ( & V_61 ) ;
#endif
return 0 ;
}
static void T_7 F_51 ( void )
{
#if F_49 ( V_60 )
F_52 ( & V_61 ) ;
#endif
#if F_49 ( V_58 )
F_52 ( & V_59 ) ;
#endif
}
