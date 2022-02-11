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
struct V_11 * V_12 = F_6 ( V_10 ) ;
struct V_1 * V_2 = F_7 ( V_10 -> V_13 ) ;
int V_4 ;
if ( V_2 == NULL )
return - V_14 ;
F_8 ( & V_12 -> V_15 ) ;
V_4 = F_3 ( V_2 , V_10 -> V_16 -> V_3 , V_7 , V_8 ) ;
F_9 ( & V_12 -> V_15 ) ;
if ( V_4 < 0 )
return V_4 ;
F_10 ( V_10 -> V_13 , L_1 ,
V_7 , V_8 , V_4 ) ;
return V_4 ;
}
int F_11 ( struct V_1 * V_2 , int V_3 , int V_7 ,
int V_8 , T_1 V_17 )
{
int V_4 ;
if ( V_3 == 0 )
return F_4 ( V_2 , V_7 , V_8 , V_17 ) ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_4 ( V_2 , V_3 , 1 , V_17 ) ;
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
int F_12 ( struct V_9 * V_10 , int V_7 , int V_8 , T_1 V_17 )
{
struct V_11 * V_12 = F_6 ( V_10 ) ;
struct V_1 * V_2 = F_7 ( V_10 -> V_13 ) ;
int V_4 ;
if ( V_2 == NULL )
return - V_14 ;
F_10 ( V_10 -> V_13 , L_2 ,
V_7 , V_8 , V_17 ) ;
F_8 ( & V_12 -> V_15 ) ;
V_4 = F_11 ( V_2 , V_10 -> V_16 -> V_3 , V_7 , V_8 , V_17 ) ;
F_9 ( & V_12 -> V_15 ) ;
return V_4 ;
}
int F_13 ( struct V_9 * V_10 )
{
F_14 ( V_18 , 0x10 , 0x0000 ) ;
F_14 ( V_18 , 0x11 , 0x0000 ) ;
F_14 ( V_18 , 0x12 , 0x5555 ) ;
F_14 ( V_18 , 0x13 , 0x5555 ) ;
F_14 ( V_18 , 0x14 , 0xaaaa ) ;
F_14 ( V_18 , 0x15 , 0xaaaa ) ;
F_14 ( V_18 , 0x16 , 0xffff ) ;
F_14 ( V_18 , 0x17 , 0xffff ) ;
F_14 ( V_18 , 0x18 , 0xfa41 ) ;
return 0 ;
}
int F_15 ( struct V_9 * V_10 , T_2 * V_7 )
{
F_14 ( V_18 , 0x01 , ( V_7 [ 0 ] << 8 ) | V_7 [ 1 ] ) ;
F_14 ( V_18 , 0x02 , ( V_7 [ 2 ] << 8 ) | V_7 [ 3 ] ) ;
F_14 ( V_18 , 0x03 , ( V_7 [ 4 ] << 8 ) | V_7 [ 5 ] ) ;
return 0 ;
}
int F_16 ( struct V_9 * V_10 , T_2 * V_7 )
{
int V_5 ;
int V_4 ;
for ( V_5 = 0 ; V_5 < 6 ; V_5 ++ ) {
int V_19 ;
F_14 ( V_20 , 0x0d , 0x8000 | ( V_5 << 8 ) | V_7 [ V_5 ] ) ;
for ( V_19 = 0 ; V_19 < 16 ; V_19 ++ ) {
V_4 = F_17 ( V_20 , 0x0d ) ;
if ( ( V_4 & 0x8000 ) == 0 )
break;
}
if ( V_19 == 16 )
return - V_6 ;
}
return 0 ;
}
int F_18 ( struct V_9 * V_10 , int V_7 , int V_21 )
{
if ( V_7 >= 0 )
return F_5 ( V_10 , V_7 , V_21 ) ;
return 0xffff ;
}
int F_19 ( struct V_9 * V_10 , int V_7 , int V_21 , T_1 V_17 )
{
if ( V_7 >= 0 )
return F_12 ( V_10 , V_7 , V_21 , V_17 ) ;
return 0 ;
}
static int F_20 ( struct V_9 * V_10 )
{
int V_4 ;
unsigned long V_22 ;
V_4 = F_17 ( V_18 , 0x04 ) ;
F_14 ( V_18 , 0x04 , V_4 & ~ 0x4000 ) ;
V_22 = V_23 + 1 * V_24 ;
while ( F_21 ( V_23 , V_22 ) ) {
V_4 = F_17 ( V_18 , 0x00 ) ;
F_22 ( 1000 , 2000 ) ;
if ( ( V_4 & 0xc000 ) != 0xc000 )
return 0 ;
}
return - V_6 ;
}
static int F_23 ( struct V_9 * V_10 )
{
int V_4 ;
unsigned long V_22 ;
V_4 = F_17 ( V_18 , 0x04 ) ;
F_14 ( V_18 , 0x04 , V_4 | 0x4000 ) ;
V_22 = V_23 + 1 * V_24 ;
while ( F_21 ( V_23 , V_22 ) ) {
V_4 = F_17 ( V_18 , 0x00 ) ;
F_22 ( 1000 , 2000 ) ;
if ( ( V_4 & 0xc000 ) == 0xc000 )
return 0 ;
}
return - V_6 ;
}
static void F_24 ( struct V_25 * V_26 )
{
struct V_11 * V_12 ;
V_12 = F_25 ( V_26 , struct V_11 , V_27 ) ;
if ( F_26 ( & V_12 -> V_28 ) ) {
struct V_9 * V_10 = ( (struct V_9 * ) V_12 ) - 1 ;
if ( F_23 ( V_10 ) == 0 )
V_12 -> V_29 = 0 ;
F_9 ( & V_12 -> V_28 ) ;
}
}
static void F_27 ( unsigned long V_30 )
{
struct V_11 * V_12 = ( void * ) V_30 ;
F_28 ( & V_12 -> V_27 ) ;
}
static int F_29 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_6 ( V_10 ) ;
int V_4 ;
F_8 ( & V_12 -> V_28 ) ;
if ( ! V_12 -> V_29 ) {
V_4 = F_20 ( V_10 ) ;
if ( V_4 < 0 ) {
F_9 ( & V_12 -> V_28 ) ;
return V_4 ;
}
V_12 -> V_29 = 1 ;
} else {
F_30 ( & V_12 -> V_31 ) ;
V_4 = 0 ;
}
return V_4 ;
}
static void F_31 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_6 ( V_10 ) ;
F_32 ( & V_12 -> V_31 , V_23 + F_33 ( 10 ) ) ;
F_9 ( & V_12 -> V_28 ) ;
}
void F_34 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_6 ( V_10 ) ;
F_35 ( & V_12 -> V_28 ) ;
F_36 ( & V_12 -> V_27 , F_24 ) ;
F_37 ( & V_12 -> V_31 ) ;
V_12 -> V_31 . V_32 = ( unsigned long ) V_12 ;
V_12 -> V_31 . V_33 = F_27 ;
}
int F_38 ( struct V_9 * V_10 , int V_7 , int V_21 )
{
int V_4 ;
V_4 = F_29 ( V_10 ) ;
if ( V_4 >= 0 ) {
V_4 = F_5 ( V_10 , V_7 , V_21 ) ;
F_31 ( V_10 ) ;
}
return V_4 ;
}
int F_39 ( struct V_9 * V_10 , int V_7 ,
int V_21 , T_1 V_17 )
{
int V_4 ;
V_4 = F_29 ( V_10 ) ;
if ( V_4 >= 0 ) {
V_4 = F_12 ( V_10 , V_7 , V_21 , V_17 ) ;
F_31 ( V_10 ) ;
}
return V_4 ;
}
void F_40 ( struct V_9 * V_10 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_34 ; V_5 ++ ) {
struct V_35 * V_36 ;
int V_37 ( V_38 ) ;
int V_39 ;
int V_40 ;
int V_41 ;
int V_42 ;
V_36 = V_10 -> V_43 [ V_5 ] ;
if ( V_36 == NULL )
continue;
V_39 = 0 ;
if ( V_36 -> V_44 & V_45 ) {
V_38 = F_5 ( V_10 , F_41 ( V_5 ) , 0x00 ) ;
if ( V_38 < 0 )
continue;
V_39 = ! ! ( V_38 & 0x0800 ) ;
}
if ( ! V_39 ) {
if ( F_42 ( V_36 ) ) {
F_43 ( V_36 , L_3 ) ;
F_44 ( V_36 ) ;
}
continue;
}
switch ( V_38 & 0x0300 ) {
case 0x0000 :
V_40 = 10 ;
break;
case 0x0100 :
V_40 = 100 ;
break;
case 0x0200 :
V_40 = 1000 ;
break;
default:
V_40 = - 1 ;
break;
}
V_41 = ( V_38 & 0x0400 ) ? 1 : 0 ;
V_42 = ( V_38 & 0x8000 ) ? 1 : 0 ;
if ( ! F_42 ( V_36 ) ) {
F_43 ( V_36 ,
L_4 ,
V_40 ,
V_41 ? L_5 : L_6 ,
V_42 ? L_7 : L_8 ) ;
F_45 ( V_36 ) ;
}
}
}
static int F_46 ( struct V_9 * V_10 )
{
int V_4 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < 10 ; V_5 ++ ) {
V_4 = F_17 ( V_18 , 0x1d ) ;
if ( ( V_4 & 0x8000 ) == 0 )
return 0 ;
}
return - V_6 ;
}
static int F_47 ( struct V_9 * V_10 , int V_46 )
{
int V_4 ;
F_14 ( V_18 , 0x1d , 0xdc00 | V_46 ) ;
V_4 = F_46 ( V_10 ) ;
if ( V_4 < 0 )
return V_4 ;
return 0 ;
}
static void F_48 ( struct V_9 * V_10 , int V_47 , T_3 * V_17 )
{
T_3 V_48 ;
int V_4 ;
* V_17 = 0 ;
V_4 = F_12 ( V_10 , V_18 , 0x1d , 0xcc00 | V_47 ) ;
if ( V_4 < 0 )
return;
V_4 = F_46 ( V_10 ) ;
if ( V_4 < 0 )
return;
V_4 = F_5 ( V_10 , V_18 , 0x1e ) ;
if ( V_4 < 0 )
return;
V_48 = V_4 << 16 ;
V_4 = F_5 ( V_10 , V_18 , 0x1f ) ;
if ( V_4 < 0 )
return;
* V_17 = V_48 | V_4 ;
}
void F_49 ( struct V_9 * V_10 ,
int V_49 , struct V_50 * V_51 ,
int V_46 , T_4 * V_32 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_49 ; V_5 ++ ) {
memcpy ( V_32 + V_5 * V_52 ,
V_51 [ V_5 ] . string , V_52 ) ;
}
}
void F_50 ( struct V_9 * V_10 ,
int V_49 , struct V_50 * V_51 ,
int V_46 , T_5 * V_32 )
{
struct V_11 * V_12 = F_6 ( V_10 ) ;
int V_4 ;
int V_5 ;
F_8 ( & V_12 -> V_53 ) ;
V_4 = F_47 ( V_10 , V_46 ) ;
if ( V_4 < 0 ) {
F_9 ( & V_12 -> V_53 ) ;
return;
}
for ( V_5 = 0 ; V_5 < V_49 ; V_5 ++ ) {
struct V_50 * V_54 = V_51 + V_5 ;
T_3 V_55 ;
T_3 V_56 = 0 ;
if ( V_54 -> V_8 >= 0x100 ) {
int V_4 ;
V_4 = F_5 ( V_10 , F_41 ( V_46 ) ,
V_54 -> V_8 - 0x100 ) ;
if ( V_4 < 0 )
goto error;
V_55 = V_4 ;
if ( V_54 -> V_57 == 4 ) {
V_4 = F_5 ( V_10 , F_41 ( V_46 ) ,
V_54 -> V_8 - 0x100 + 1 ) ;
if ( V_4 < 0 )
goto error;
V_56 = V_4 ;
}
V_32 [ V_5 ] = ( ( ( V_58 ) V_56 ) << 16 ) | V_55 ;
continue;
}
F_48 ( V_10 , V_54 -> V_8 , & V_55 ) ;
if ( V_54 -> V_57 == 8 )
F_48 ( V_10 , V_54 -> V_8 + 1 , & V_56 ) ;
V_32 [ V_5 ] = ( ( ( V_58 ) V_56 ) << 32 ) | V_55 ;
}
error:
F_9 ( & V_12 -> V_53 ) ;
}
int F_51 ( struct V_9 * V_10 , int V_46 )
{
return 32 * sizeof( T_1 ) ;
}
void F_52 ( struct V_9 * V_10 , int V_46 ,
struct V_59 * V_60 , void * V_61 )
{
T_1 * V_62 = V_61 ;
int V_5 ;
V_60 -> V_63 = 0 ;
memset ( V_62 , 0xff , 32 * sizeof( T_1 ) ) ;
for ( V_5 = 0 ; V_5 < 32 ; V_5 ++ ) {
int V_4 ;
V_4 = F_5 ( V_10 , F_41 ( V_46 ) , V_5 ) ;
if ( V_4 >= 0 )
V_62 [ V_5 ] = V_4 ;
}
}
int F_53 ( struct V_9 * V_10 , int * V_64 )
{
struct V_11 * V_12 = F_6 ( V_10 ) ;
int V_4 ;
int V_17 ;
* V_64 = 0 ;
F_8 ( & V_12 -> V_65 ) ;
V_4 = F_19 ( V_10 , 0x0 , 0x16 , 0x6 ) ;
if ( V_4 < 0 )
goto error;
V_4 = F_18 ( V_10 , 0x0 , 0x1a ) ;
if ( V_4 < 0 )
goto error;
V_4 = F_19 ( V_10 , 0x0 , 0x1a , V_4 | ( 1 << 5 ) ) ;
if ( V_4 < 0 )
goto error;
F_22 ( 10000 , 12000 ) ;
V_17 = F_18 ( V_10 , 0x0 , 0x1a ) ;
if ( V_17 < 0 ) {
V_4 = V_17 ;
goto error;
}
V_4 = F_19 ( V_10 , 0x0 , 0x1a , V_4 & ~ ( 1 << 5 ) ) ;
if ( V_4 < 0 )
goto error;
* V_64 = ( ( V_17 & 0x1f ) - 5 ) * 5 ;
error:
F_19 ( V_10 , 0x0 , 0x16 , 0x0 ) ;
F_9 ( & V_12 -> V_65 ) ;
return V_4 ;
}
static int T_6 F_54 ( void )
{
#if F_55 ( V_66 )
F_56 ( & V_67 ) ;
#endif
#if F_55 ( V_68 )
F_56 ( & V_69 ) ;
#endif
#if F_55 ( V_70 )
F_56 ( & V_71 ) ;
#endif
#if F_55 ( V_72 )
F_56 ( & V_73 ) ;
#endif
return 0 ;
}
static void T_7 F_57 ( void )
{
#if F_55 ( V_72 )
F_58 ( & V_73 ) ;
#endif
#if F_55 ( V_68 )
F_58 ( & V_69 ) ;
#endif
#if F_55 ( V_66 )
F_58 ( & V_67 ) ;
#endif
}
