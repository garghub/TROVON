static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
unsigned char V_6 [ 10 ] ;
int V_7 ;
V_7 = F_3 ( V_5 -> V_8 , V_9 , V_6 ,
sizeof( V_6 ) ) ;
if ( V_7 ) {
F_4 ( V_2 , L_1 , V_10 ) ;
return V_7 ;
}
if ( V_6 [ V_11 ] & V_12 )
F_5 ( V_2 ,
L_2 ) ;
if ( V_6 [ V_13 ] & V_14 ) {
F_6 ( V_2 ,
L_3 ) ;
return - V_15 ;
}
F_7 ( V_2 ,
L_4
L_5
L_6 ,
V_10 ,
V_6 [ 0 ] , V_6 [ 1 ] , V_6 [ 2 ] ,
V_6 [ 3 ] , V_6 [ 4 ] , V_6 [ 5 ] ,
V_6 [ 6 ] , V_6 [ 7 ] , V_6 [ 8 ] , V_6 [ 9 ] ) ;
V_4 -> V_16 = F_8 ( V_6 [ V_13 ] & 0x7F ) ;
V_4 -> V_17 = F_8 ( V_6 [ V_18 ] & 0x7F ) ;
V_4 -> V_19 = F_8 ( V_6 [ V_20 ] & 0x3F ) ;
V_4 -> V_21 = F_8 ( V_6 [ V_22 ] & 0x3F ) ;
V_4 -> V_23 = V_6 [ V_24 ] & 0x07 ;
V_4 -> V_25 = F_8 ( V_6 [ V_26 ] & 0x1F ) - 1 ;
V_4 -> V_27 = F_8 ( V_6 [ V_28 ] ) ;
if ( V_4 -> V_27 < 70 )
V_4 -> V_27 += 100 ;
F_7 ( V_2 , L_7
L_8 ,
V_10 ,
V_4 -> V_16 , V_4 -> V_17 , V_4 -> V_19 ,
V_4 -> V_21 , V_4 -> V_25 , V_4 -> V_27 , V_4 -> V_23 ) ;
return F_9 ( V_4 ) ;
}
static int F_10 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
unsigned char V_6 [ 7 ] ;
int V_29 = 0 , V_30 ;
F_7 ( V_2 , L_9
L_8 ,
V_10 ,
V_4 -> V_16 , V_4 -> V_17 , V_4 -> V_19 ,
V_4 -> V_21 , V_4 -> V_25 , V_4 -> V_27 , V_4 -> V_23 ) ;
V_6 [ V_29 ++ ] = F_11 ( V_4 -> V_16 ) ;
V_6 [ V_29 ++ ] = F_11 ( V_4 -> V_17 ) ;
V_6 [ V_29 ++ ] = F_11 ( V_4 -> V_19 ) ;
V_6 [ V_29 ++ ] = F_11 ( V_4 -> V_21 ) ;
V_6 [ V_29 ++ ] = V_4 -> V_23 & 0x07 ;
V_6 [ V_29 ++ ] = F_11 ( V_4 -> V_25 + 1 ) ;
V_6 [ V_29 ++ ] = F_11 ( V_4 -> V_27 % 100 ) ;
V_30 = F_12 ( V_5 -> V_8 , V_13 , V_6 , V_29 ) ;
if ( V_30 ) {
F_4 ( V_2 ,
L_10 , V_10 , V_30 ) ;
return V_30 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
unsigned int V_31 , unsigned long V_32 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
int V_33 ;
int V_7 ;
switch ( V_31 ) {
case V_34 :
V_7 = F_14 ( V_5 -> V_8 , V_11 , & V_33 ) ;
if ( V_7 )
return V_7 ;
V_33 = V_33 & V_12 ? 1 : 0 ;
if ( F_15 ( ( void V_35 * ) V_32 , & V_33 , sizeof( int ) ) )
return - V_36 ;
return 0 ;
default:
return - V_37 ;
}
}
static int F_16 ( struct V_1 * V_2 , struct V_8 * V_8 ,
const char * V_38 )
{
struct V_5 * V_5 ;
F_7 ( V_2 , L_11 , V_10 ) ;
V_5 = F_17 ( V_2 , sizeof( * V_5 ) , V_39 ) ;
if ( ! V_5 )
return - V_40 ;
V_5 -> V_8 = V_8 ;
F_18 ( V_2 , V_5 ) ;
V_5 -> V_41 = F_19 ( V_2 , V_38 , & V_42 ,
V_43 ) ;
return F_20 ( V_5 -> V_41 ) ;
}
static int F_21 ( void * V_44 , const void * V_45 , T_1 V_46 )
{
struct V_1 * V_2 = V_44 ;
struct V_47 * V_48 = F_22 ( V_2 ) ;
int V_7 ;
V_7 = F_23 ( V_48 , V_45 , V_46 ) ;
if ( V_7 != V_46 )
return V_7 < 0 ? V_7 : - V_49 ;
return 0 ;
}
static int F_24 ( void * V_44 ,
const void * V_50 , T_1 V_51 ,
const void * V_52 , T_1 V_53 )
{
struct V_1 * V_2 = V_44 ;
struct V_47 * V_48 = F_22 ( V_2 ) ;
int V_7 ;
void * V_6 ;
if ( F_25 ( V_51 != 1 ) )
return - V_15 ;
V_6 = F_26 ( V_53 + 1 , V_39 ) ;
if ( ! V_6 )
return - V_40 ;
memcpy ( V_6 , V_50 , 1 ) ;
memcpy ( V_6 + 1 , V_52 , V_53 ) ;
V_7 = F_23 ( V_48 , V_6 , V_53 + 1 ) ;
if ( V_7 != V_53 + 1 )
return V_7 < 0 ? V_7 : - V_49 ;
return 0 ;
}
static int F_27 ( void * V_44 , const void * V_50 , T_1 V_51 ,
void * V_52 , T_1 V_53 )
{
struct V_1 * V_2 = V_44 ;
struct V_47 * V_48 = F_22 ( V_2 ) ;
int V_7 ;
if ( F_25 ( V_51 != 1 ) )
return - V_15 ;
V_7 = F_23 ( V_48 , V_50 , 1 ) ;
if ( V_7 != 1 )
return V_7 < 0 ? V_7 : - V_49 ;
V_7 = F_28 ( V_48 , V_52 , V_53 ) ;
if ( V_7 != V_53 )
return V_7 < 0 ? V_7 : - V_49 ;
return 0 ;
}
static int F_29 ( struct V_47 * V_48 ,
const struct V_54 * V_55 )
{
struct V_8 * V_8 ;
static const struct V_56 V_57 = {
. V_58 = 8 ,
. V_59 = 8 ,
} ;
if ( ! F_30 ( V_48 -> V_60 , V_61 ) )
return - V_62 ;
V_8 = F_31 ( & V_48 -> V_2 , & V_63 ,
& V_48 -> V_2 , & V_57 ) ;
if ( F_32 ( V_8 ) ) {
F_4 ( & V_48 -> V_2 , L_12 ,
V_10 , F_33 ( V_8 ) ) ;
return F_33 ( V_8 ) ;
}
return F_16 ( & V_48 -> V_2 , V_8 ,
V_64 . V_65 . V_38 ) ;
}
static int F_34 ( void )
{
return F_35 ( & V_64 ) ;
}
static void F_36 ( void )
{
F_37 ( & V_64 ) ;
}
static int F_34 ( void )
{
return 0 ;
}
static void F_36 ( void )
{
}
static int F_38 ( struct V_66 * V_67 )
{
static const struct V_56 V_57 = {
. V_58 = 8 ,
. V_59 = 8 ,
. V_68 = 0xa0 ,
. V_69 = 0x20 ,
} ;
struct V_8 * V_8 ;
V_8 = F_39 ( V_67 , & V_57 ) ;
if ( F_32 ( V_8 ) ) {
F_4 ( & V_67 -> V_2 , L_12 ,
V_10 , F_33 ( V_8 ) ) ;
return F_33 ( V_8 ) ;
}
return F_16 ( & V_67 -> V_2 , V_8 , V_70 . V_65 . V_38 ) ;
}
static int F_40 ( void )
{
return F_41 ( & V_70 ) ;
}
static void F_42 ( void )
{
F_43 ( & V_70 ) ;
}
static int F_40 ( void )
{
return 0 ;
}
static void F_42 ( void )
{
}
static int T_2 F_44 ( void )
{
int V_7 ;
V_7 = F_34 () ;
if ( V_7 ) {
F_45 ( L_13 , V_7 ) ;
return V_7 ;
}
V_7 = F_40 () ;
if ( V_7 ) {
F_45 ( L_14 , V_7 ) ;
F_36 () ;
}
return V_7 ;
}
static void T_3 F_46 ( void )
{
F_42 () ;
F_36 () ;
}
