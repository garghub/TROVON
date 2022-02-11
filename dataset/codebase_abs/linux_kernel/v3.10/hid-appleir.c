static int F_1 ( int V_1 )
{
int V_2 = ( V_1 >> 1 ) & V_3 ;
if ( ( V_1 & V_4 ) )
V_2 = - V_2 ;
return V_2 ;
}
static void F_2 ( struct V_5 * V_6 , struct V_7 * V_7 , int V_2 )
{
F_3 ( V_7 -> V_8 , V_2 , 0 ) ;
F_4 ( V_7 -> V_8 ) ;
}
static void F_5 ( struct V_5 * V_6 , struct V_7 * V_7 , int V_2 )
{
F_3 ( V_7 -> V_8 , V_2 , 1 ) ;
F_4 ( V_7 -> V_8 ) ;
}
static void F_6 ( struct V_7 * V_7 )
{
F_7 ( & V_7 -> V_8 -> V_9 , L_1 ) ;
}
static void F_8 ( unsigned long V_1 )
{
struct V_7 * V_7 = (struct V_7 * ) V_1 ;
struct V_5 * V_6 = V_7 -> V_6 ;
unsigned long V_10 ;
F_9 ( & V_7 -> V_11 , V_10 ) ;
if ( V_7 -> V_12 ) {
F_2 ( V_6 , V_7 , V_7 -> V_12 ) ;
V_7 -> V_12 = 0 ;
}
F_10 ( & V_7 -> V_11 , V_10 ) ;
}
static int F_11 ( struct V_5 * V_6 , struct V_13 * V_14 ,
T_1 * V_1 , int V_15 )
{
struct V_7 * V_7 = F_12 ( V_6 ) ;
static const T_1 V_16 [] = { 0x25 , 0x87 , 0xee } ;
static const T_1 V_17 [] = { 0x26 , } ;
static const T_1 V_18 [] = { 0x25 , 0x87 , 0xe0 } ;
unsigned long V_10 ;
if ( V_15 != 5 )
goto V_19;
if ( ! memcmp ( V_1 , V_16 , sizeof( V_16 ) ) ) {
int V_20 ;
F_9 ( & V_7 -> V_11 , V_10 ) ;
if ( V_7 -> V_12 )
F_2 ( V_6 , V_7 , V_7 -> V_12 ) ;
if ( V_7 -> V_21 > 0 )
V_20 = V_7 -> V_21 ;
else
V_20 = F_1 ( V_1 [ 4 ] ) ;
if ( V_20 >= 0 ) {
V_7 -> V_12 = V_7 -> V_22 [ V_20 ] ;
F_5 ( V_6 , V_7 , V_7 -> V_12 ) ;
F_13 ( & V_7 -> V_23 , V_24 + V_25 / 8 ) ;
V_7 -> V_21 = 0 ;
} else
V_7 -> V_21 = - V_20 ;
F_10 ( & V_7 -> V_11 , V_10 ) ;
goto V_19;
}
V_7 -> V_21 = 0 ;
if ( ! memcmp ( V_1 , V_17 , sizeof( V_17 ) ) ) {
F_5 ( V_6 , V_7 , V_7 -> V_12 ) ;
F_13 ( & V_7 -> V_23 , V_24 + V_25 / 8 ) ;
goto V_19;
}
if ( ! memcmp ( V_1 , V_18 , sizeof( V_18 ) ) ) {
F_6 ( V_7 ) ;
}
V_19:
return 0 ;
}
static void F_14 ( struct V_5 * V_6 ,
struct V_26 * V_27 )
{
struct V_8 * V_8 = V_27 -> V_28 ;
struct V_7 * V_7 = F_12 ( V_6 ) ;
int V_29 ;
V_7 -> V_8 = V_8 ;
V_8 -> V_30 = V_7 -> V_22 ;
V_8 -> V_31 = sizeof( unsigned short ) ;
V_8 -> V_32 = F_15 ( V_7 -> V_22 ) ;
V_8 -> V_33 [ 0 ] = F_16 ( V_34 ) | F_16 ( V_35 ) ;
memcpy ( V_7 -> V_22 , V_36 , sizeof( V_7 -> V_22 ) ) ;
for ( V_29 = 0 ; V_29 < F_15 ( V_36 ) ; V_29 ++ )
F_17 ( V_7 -> V_22 [ V_29 ] , V_8 -> V_37 ) ;
F_18 ( V_38 , V_8 -> V_37 ) ;
}
static int F_19 ( struct V_5 * V_6 ,
struct V_26 * V_39 , struct V_40 * V_41 ,
struct V_42 * V_43 , unsigned long * * V_44 , int * V_45 )
{
return - 1 ;
}
static int F_20 ( struct V_5 * V_6 , const struct V_46 * V_47 )
{
int V_48 ;
struct V_7 * V_7 ;
V_7 = F_21 ( sizeof( struct V_7 ) , V_49 ) ;
if ( ! V_7 ) {
V_48 = - V_50 ;
goto V_51;
}
V_7 -> V_6 = V_6 ;
F_22 ( & V_7 -> V_11 ) ;
F_23 ( & V_7 -> V_23 ,
F_8 , ( unsigned long ) V_7 ) ;
F_24 ( V_6 , V_7 ) ;
V_48 = F_25 ( V_6 ) ;
if ( V_48 ) {
F_26 ( V_6 , L_2 ) ;
goto V_52;
}
V_48 = F_27 ( V_6 , V_53 | V_54 ) ;
if ( V_48 ) {
F_26 ( V_6 , L_3 ) ;
goto V_52;
}
return 0 ;
V_52:
F_28 ( V_7 ) ;
V_51:
return V_48 ;
}
static void F_29 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_12 ( V_6 ) ;
F_30 ( V_6 ) ;
F_31 ( & V_7 -> V_23 ) ;
F_28 ( V_7 ) ;
}
