static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
unsigned char V_6 [ 10 ] ;
int V_7 ;
int V_8 ;
for ( V_8 = 0 ; V_8 <= V_9 ; V_8 ++ ) {
V_7 = F_3 ( V_5 -> V_10 , V_11 + V_8 ,
( unsigned int * ) ( V_6 + V_8 ) ) ;
if ( V_7 ) {
F_4 ( V_2 , L_1 , V_12 ) ;
return V_7 ;
}
}
V_7 = F_5 ( V_5 -> V_10 , V_13 ,
( V_6 + V_13 ) ,
F_6 ( V_6 ) - V_13 ) ;
if ( V_7 ) {
F_4 ( V_2 , L_1 , V_12 ) ;
return V_7 ;
}
if ( V_6 [ V_9 ] & V_14 )
F_7 ( V_2 ,
L_2 ) ;
if ( V_6 [ V_13 ] & V_15 ) {
F_8 ( V_2 ,
L_3 ) ;
return - V_16 ;
}
F_9 ( V_2 ,
L_4
L_5
L_6 ,
V_12 ,
V_6 [ 0 ] , V_6 [ 1 ] , V_6 [ 2 ] ,
V_6 [ 3 ] , V_6 [ 4 ] , V_6 [ 5 ] ,
V_6 [ 6 ] , V_6 [ 7 ] , V_6 [ 8 ] , V_6 [ 9 ] ) ;
V_4 -> V_17 = F_10 ( V_6 [ V_13 ] & 0x7F ) ;
V_4 -> V_18 = F_10 ( V_6 [ V_19 ] & 0x7F ) ;
V_4 -> V_20 = F_10 ( V_6 [ V_21 ] & 0x3F ) ;
V_4 -> V_22 = F_10 ( V_6 [ V_23 ] & 0x3F ) ;
V_4 -> V_24 = V_6 [ V_25 ] & 0x07 ;
V_4 -> V_26 = F_10 ( V_6 [ V_27 ] & 0x1F ) - 1 ;
V_4 -> V_28 = F_10 ( V_6 [ V_29 ] ) ;
if ( V_4 -> V_28 < 70 )
V_4 -> V_28 += 100 ;
F_9 ( V_2 , L_7
L_8 ,
V_12 ,
V_4 -> V_17 , V_4 -> V_18 , V_4 -> V_20 ,
V_4 -> V_22 , V_4 -> V_26 , V_4 -> V_28 , V_4 -> V_24 ) ;
return F_11 ( V_4 ) ;
}
static int F_12 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
unsigned char V_6 [ 7 ] ;
int V_8 = 0 , V_30 ;
F_9 ( V_2 , L_9
L_8 ,
V_12 ,
V_4 -> V_17 , V_4 -> V_18 , V_4 -> V_20 ,
V_4 -> V_22 , V_4 -> V_26 , V_4 -> V_28 , V_4 -> V_24 ) ;
V_6 [ V_8 ++ ] = F_13 ( V_4 -> V_17 ) ;
V_6 [ V_8 ++ ] = F_13 ( V_4 -> V_18 ) ;
V_6 [ V_8 ++ ] = F_13 ( V_4 -> V_20 ) ;
V_6 [ V_8 ++ ] = F_13 ( V_4 -> V_22 ) ;
V_6 [ V_8 ++ ] = V_4 -> V_24 & 0x07 ;
V_6 [ V_8 ++ ] = F_13 ( V_4 -> V_26 + 1 ) ;
V_6 [ V_8 ++ ] = F_13 ( V_4 -> V_28 % 100 ) ;
V_30 = F_14 ( V_5 -> V_10 , V_13 , V_6 , V_8 ) ;
if ( V_30 ) {
F_4 ( V_2 ,
L_10 , V_12 , V_30 ) ;
return V_30 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
unsigned int V_31 , unsigned long V_32 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
int V_33 ;
int V_7 ;
switch ( V_31 ) {
case V_34 :
V_7 = F_3 ( V_5 -> V_10 , V_9 , & V_33 ) ;
if ( V_7 )
return V_7 ;
V_33 = V_33 & V_14 ? 1 : 0 ;
if ( F_16 ( ( void V_35 * ) V_32 , & V_33 , sizeof( int ) ) )
return - V_36 ;
return 0 ;
default:
return - V_37 ;
}
}
static int F_17 ( struct V_1 * V_2 , struct V_10 * V_10 ,
const char * V_38 )
{
struct V_5 * V_5 ;
F_9 ( V_2 , L_11 , V_12 ) ;
V_5 = F_18 ( V_2 , sizeof( * V_5 ) , V_39 ) ;
if ( ! V_5 )
return - V_40 ;
V_5 -> V_10 = V_10 ;
F_19 ( V_2 , V_5 ) ;
V_5 -> V_41 = F_20 ( V_2 , V_38 , & V_42 ,
V_43 ) ;
return F_21 ( V_5 -> V_41 ) ;
}
static int F_22 ( void * V_44 , const void * V_45 , T_1 V_46 )
{
struct V_1 * V_2 = V_44 ;
struct V_47 * V_48 = F_23 ( V_2 ) ;
int V_7 ;
V_7 = F_24 ( V_48 , V_45 , V_46 ) ;
if ( V_7 != V_46 )
return V_7 < 0 ? V_7 : - V_49 ;
return 0 ;
}
static int F_25 ( void * V_44 ,
const void * V_50 , T_1 V_51 ,
const void * V_52 , T_1 V_53 )
{
struct V_1 * V_2 = V_44 ;
struct V_47 * V_48 = F_23 ( V_2 ) ;
int V_7 ;
void * V_6 ;
if ( F_26 ( V_51 != 1 ) )
return - V_16 ;
V_6 = F_27 ( V_53 + 1 , V_39 ) ;
if ( ! V_6 )
return - V_40 ;
memcpy ( V_6 , V_50 , 1 ) ;
memcpy ( V_6 + 1 , V_52 , V_53 ) ;
V_7 = F_24 ( V_48 , V_6 , V_53 + 1 ) ;
if ( V_7 != V_53 + 1 )
return V_7 < 0 ? V_7 : - V_49 ;
return 0 ;
}
static int F_28 ( void * V_44 , const void * V_50 , T_1 V_51 ,
void * V_52 , T_1 V_53 )
{
struct V_1 * V_2 = V_44 ;
struct V_47 * V_48 = F_23 ( V_2 ) ;
int V_7 ;
if ( F_26 ( V_51 != 1 ) )
return - V_16 ;
V_7 = F_24 ( V_48 , V_50 , 1 ) ;
if ( V_7 != 1 )
return V_7 < 0 ? V_7 : - V_49 ;
V_7 = F_29 ( V_48 , V_52 , V_53 ) ;
if ( V_7 != V_53 )
return V_7 < 0 ? V_7 : - V_49 ;
return 0 ;
}
static int F_30 ( struct V_47 * V_48 ,
const struct V_54 * V_55 )
{
struct V_10 * V_10 ;
static const struct V_56 V_57 = {
. V_58 = 8 ,
. V_59 = 8 ,
} ;
if ( ! F_31 ( V_48 -> V_60 , V_61 ) )
return - V_62 ;
V_10 = F_32 ( & V_48 -> V_2 , & V_63 ,
& V_48 -> V_2 , & V_57 ) ;
if ( F_33 ( V_10 ) ) {
F_4 ( & V_48 -> V_2 , L_12 ,
V_12 , F_34 ( V_10 ) ) ;
return F_34 ( V_10 ) ;
}
return F_17 ( & V_48 -> V_2 , V_10 ,
V_64 . V_65 . V_38 ) ;
}
static int F_35 ( void )
{
return F_36 ( & V_64 ) ;
}
static void F_37 ( void )
{
F_38 ( & V_64 ) ;
}
static int F_35 ( void )
{
return 0 ;
}
static void F_37 ( void )
{
}
static int F_39 ( struct V_66 * V_67 )
{
static const struct V_56 V_57 = {
. V_58 = 8 ,
. V_59 = 8 ,
. V_68 = 0xa0 ,
. V_69 = 0x20 ,
} ;
struct V_10 * V_10 ;
V_10 = F_40 ( V_67 , & V_57 ) ;
if ( F_33 ( V_10 ) ) {
F_4 ( & V_67 -> V_2 , L_12 ,
V_12 , F_34 ( V_10 ) ) ;
return F_34 ( V_10 ) ;
}
return F_17 ( & V_67 -> V_2 , V_10 , V_70 . V_65 . V_38 ) ;
}
static int F_41 ( void )
{
return F_42 ( & V_70 ) ;
}
static void F_43 ( void )
{
F_44 ( & V_70 ) ;
}
static int F_41 ( void )
{
return 0 ;
}
static void F_43 ( void )
{
}
static int T_2 F_45 ( void )
{
int V_7 ;
V_7 = F_35 () ;
if ( V_7 ) {
F_46 ( L_13 , V_7 ) ;
return V_7 ;
}
V_7 = F_41 () ;
if ( V_7 ) {
F_46 ( L_14 , V_7 ) ;
F_37 () ;
}
return V_7 ;
}
static void T_3 F_47 ( void )
{
F_43 () ;
F_37 () ;
}
