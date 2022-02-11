static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline int F_3 ( int V_4 )
{
if ( ! F_4 ( V_4 , 2 , V_5 ) ) {
F_5 ( V_5 L_1 ,
V_4 ) ;
return - V_6 ;
}
F_6 ( V_7 , V_4 ) ;
return 0 ;
}
static inline void F_7 ( int V_4 )
{
F_6 ( V_8 , V_4 ) ;
F_8 ( V_4 , 2 ) ;
}
static inline int F_9 ( int V_4 , int V_9 )
{
F_6 ( V_9 , V_4 ) ;
return F_10 ( V_4 + 1 ) ;
}
static inline void F_11 ( int V_4 , int V_9 , int V_10 )
{
F_6 ( V_9 , V_4 ) ;
F_6 ( V_10 , V_4 + 1 ) ;
}
static int F_12 ( struct V_2 * V_3 , unsigned V_11 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
if ( V_12 -> V_13 [ V_11 ] == 0 )
return - V_14 ;
if ( ! F_13 ( V_12 -> V_15 + V_12 -> V_13 [ V_11 ] ,
1 , V_5 ) ) {
F_14 ( V_3 -> V_16 , L_2 ,
V_12 -> V_15 + V_12 -> V_13 [ V_11 ] ) ;
return - V_6 ;
}
return 0 ;
}
static void F_15 ( struct V_2 * V_3 , unsigned V_11 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
if ( V_12 -> V_13 [ V_11 ] == 0 )
return;
F_8 ( V_12 -> V_15 + V_12 -> V_13 [ V_11 ] , 1 ) ;
}
static int F_16 ( struct V_2 * V_3 , unsigned V_11 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
unsigned char V_17 ;
F_17 ( & V_12 -> V_18 ) ;
V_17 = F_10 ( V_12 -> V_15 + V_12 -> V_19 ) ;
F_18 ( & V_12 -> V_18 ) ;
return ! ! ( V_17 & F_19 ( V_11 ) ) ;
}
static void F_20 ( struct V_1 * V_12 ,
unsigned V_11 , int V_20 )
{
unsigned char V_17 = F_10 ( V_12 -> V_15 + V_12 -> V_19 ) ;
if ( V_20 )
V_17 |= F_19 ( V_11 ) ;
else
V_17 &= ~ F_19 ( V_11 ) ;
F_6 ( V_17 , V_12 -> V_15 + V_12 -> V_19 ) ;
}
static void F_21 ( struct V_2 * V_3 , unsigned V_11 ,
int V_20 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
F_17 ( & V_12 -> V_18 ) ;
F_20 ( V_12 , V_11 , V_20 ) ;
F_18 ( & V_12 -> V_18 ) ;
}
static int F_22 ( struct V_2 * V_3 , unsigned V_11 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
F_17 ( & V_12 -> V_18 ) ;
F_6 ( V_21 , V_12 -> V_15 +
V_12 -> V_13 [ V_11 ] ) ;
F_18 ( & V_12 -> V_18 ) ;
return 0 ;
}
static int F_23 ( struct V_2 * V_3 , unsigned V_11 ,
int V_20 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
F_17 ( & V_12 -> V_18 ) ;
F_6 ( V_22 , V_12 -> V_15 +
V_12 -> V_13 [ V_11 ] ) ;
F_20 ( V_12 , V_11 , V_20 ) ;
F_18 ( & V_12 -> V_18 ) ;
return 0 ;
}
static int F_24 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = V_24 -> V_16 . V_27 ;
struct V_28 * V_29 ;
struct V_1 * V_12 ;
int V_30 , V_31 ;
if ( ! F_13 ( V_26 -> V_15 + V_32 , 6 , V_5 ) ) {
F_14 ( & V_24 -> V_16 , L_3 ,
V_26 -> V_15 + V_32 , V_26 -> V_15 + V_32 + 5 ) ;
return - V_6 ;
}
V_29 = F_25 ( & V_24 -> V_16 , sizeof( * V_29 ) , V_33 ) ;
if ( ! V_29 )
return - V_34 ;
F_26 ( V_24 , V_29 ) ;
for ( V_31 = 0 ; V_31 < F_27 ( V_29 -> V_35 ) ; V_31 ++ ) {
V_12 = & V_29 -> V_35 [ V_31 ] ;
F_28 ( & V_12 -> V_18 ) ;
V_12 -> V_3 . V_36 = V_5 ;
V_12 -> V_3 . V_37 = V_38 ;
V_12 -> V_3 . V_39 = F_12 ;
V_12 -> V_3 . free = F_15 ;
V_12 -> V_3 . V_40 = F_22 ;
V_12 -> V_3 . V_41 = F_23 ;
V_12 -> V_3 . V_42 = F_16 ;
V_12 -> V_3 . V_43 = F_21 ;
V_12 -> V_3 . V_44 = 8 ;
V_12 -> V_3 . V_16 = & V_24 -> V_16 ;
V_12 -> V_3 . V_45 = V_46 [ V_31 ] . V_45 ;
V_12 -> V_13 = V_46 [ V_31 ] . V_13 ;
V_12 -> V_19 = V_46 [ V_31 ] . V_19 ;
V_12 -> V_15 = V_26 -> V_15 ;
V_30 = F_29 ( & V_12 -> V_3 ) ;
if ( V_30 < 0 ) {
F_14 ( & V_24 -> V_16 ,
L_4 , V_30 ) ;
goto V_47;
}
F_30 ( & V_24 -> V_16 ,
L_5 , V_31 ) ;
}
return 0 ;
V_47:
F_8 ( V_26 -> V_15 + V_32 , 6 ) ;
for ( -- V_31 ; V_31 >= 0 ; V_31 -- )
F_31 ( & V_29 -> V_35 [ V_31 ] . V_3 ) ;
return V_30 ;
}
static int F_32 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = V_24 -> V_16 . V_27 ;
struct V_28 * V_29 = F_33 ( V_24 ) ;
int V_30 , V_31 ;
F_8 ( V_26 -> V_15 + V_32 , 6 ) ;
for ( V_31 = 0 ; V_31 < F_27 ( V_29 -> V_35 ) ; V_31 ++ ) {
V_30 = F_31 ( & V_29 -> V_35 [ V_31 ] . V_3 ) ;
if ( V_30 )
return V_30 ;
F_30 ( & V_24 -> V_16 ,
L_6 , V_31 ) ;
}
return 0 ;
}
static int T_1 F_34 ( int V_4 , unsigned short * V_48 )
{
int V_30 = 0 , V_9 ;
unsigned short V_49 ;
unsigned char V_50 ;
V_30 = F_3 ( V_4 ) ;
if ( V_30 )
return V_30 ;
V_9 = F_9 ( V_4 , 0x20 ) ;
switch ( V_9 ) {
case 0x7c :
V_50 = 2 ;
break;
case 0x7d :
V_50 = 4 ;
break;
case 0x7f :
V_50 = 6 ;
break;
default:
V_30 = - V_14 ;
goto exit;
}
F_11 ( V_4 , 0x07 , 0x0a ) ;
if ( ( F_9 ( V_4 , 0x30 ) & 0x01 ) == 0 )
F_35 ( L_7 ) ;
V_49 = ( F_9 ( V_4 , 0x60 ) << 8 ) |
F_9 ( V_4 , 0x61 ) ;
if ( ! V_49 ) {
F_5 ( L_8 ) ;
V_30 = - V_14 ;
goto exit;
}
* V_48 = V_49 ;
F_35 ( L_9 , V_50 , V_49 ) ;
exit:
F_7 ( V_4 ) ;
return V_30 ;
}
static int T_1 F_36 ( const unsigned short V_48 )
{
struct V_25 V_26 ;
int V_30 ;
V_26 . V_15 = V_48 ;
V_51 = F_37 ( V_5 , - 1 ) ;
if ( ! V_51 )
return - V_34 ;
V_30 = F_38 ( V_51 ,
& V_26 , sizeof( V_26 ) ) ;
if ( V_30 ) {
F_5 ( V_5 L_10 ) ;
goto V_30;
}
V_30 = F_39 ( V_51 ) ;
if ( V_30 ) {
F_5 ( V_5 L_11 ) ;
goto V_30;
}
return 0 ;
V_30:
F_40 ( V_51 ) ;
return V_30 ;
}
static int T_1 F_41 ( void )
{
int V_30 , V_31 ;
unsigned short V_48 = 0 ;
for ( V_31 = 0 ; V_31 < F_27 ( V_52 ) ; V_31 ++ )
if ( F_34 ( V_52 [ V_31 ] , & V_48 ) == 0 )
break;
if ( ! V_48 )
return - V_14 ;
V_30 = F_42 ( & V_53 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_36 ( V_48 ) ;
if ( V_30 )
goto V_54;
return 0 ;
V_54:
F_43 ( & V_53 ) ;
return V_30 ;
}
static void T_2 F_44 ( void )
{
F_45 ( V_51 ) ;
F_43 ( & V_53 ) ;
}
