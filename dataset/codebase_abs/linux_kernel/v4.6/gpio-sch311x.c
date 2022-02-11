static inline int F_1 ( int V_1 )
{
if ( ! F_2 ( V_1 , 2 , V_2 ) ) {
F_3 ( V_2 L_1 ,
V_1 ) ;
return - V_3 ;
}
F_4 ( V_4 , V_1 ) ;
return 0 ;
}
static inline void F_5 ( int V_1 )
{
F_4 ( V_5 , V_1 ) ;
F_6 ( V_1 , 2 ) ;
}
static inline int F_7 ( int V_1 , int V_6 )
{
F_4 ( V_6 , V_1 ) ;
return F_8 ( V_1 + 1 ) ;
}
static inline void F_9 ( int V_1 , int V_6 , int V_7 )
{
F_4 ( V_6 , V_1 ) ;
F_4 ( V_7 , V_1 + 1 ) ;
}
static int F_10 ( struct V_8 * V_9 , unsigned V_10 )
{
struct V_11 * V_12 = F_11 ( V_9 ) ;
if ( V_12 -> V_13 [ V_10 ] == 0 )
return - V_14 ;
if ( ! F_12 ( V_12 -> V_15 + V_12 -> V_13 [ V_10 ] ,
1 , V_2 ) ) {
F_13 ( V_9 -> V_16 , L_2 ,
V_12 -> V_15 + V_12 -> V_13 [ V_10 ] ) ;
return - V_3 ;
}
return 0 ;
}
static void F_14 ( struct V_8 * V_9 , unsigned V_10 )
{
struct V_11 * V_12 = F_11 ( V_9 ) ;
if ( V_12 -> V_13 [ V_10 ] == 0 )
return;
F_6 ( V_12 -> V_15 + V_12 -> V_13 [ V_10 ] , 1 ) ;
}
static int F_15 ( struct V_8 * V_9 , unsigned V_10 )
{
struct V_11 * V_12 = F_11 ( V_9 ) ;
unsigned char V_17 ;
F_16 ( & V_12 -> V_18 ) ;
V_17 = F_8 ( V_12 -> V_15 + V_12 -> V_19 ) ;
F_17 ( & V_12 -> V_18 ) ;
return ! ! ( V_17 & F_18 ( V_10 ) ) ;
}
static void F_19 ( struct V_11 * V_12 ,
unsigned V_10 , int V_20 )
{
unsigned char V_17 = F_8 ( V_12 -> V_15 + V_12 -> V_19 ) ;
if ( V_20 )
V_17 |= F_18 ( V_10 ) ;
else
V_17 &= ~ F_18 ( V_10 ) ;
F_4 ( V_17 , V_12 -> V_15 + V_12 -> V_19 ) ;
}
static void F_20 ( struct V_8 * V_9 , unsigned V_10 ,
int V_20 )
{
struct V_11 * V_12 = F_11 ( V_9 ) ;
F_16 ( & V_12 -> V_18 ) ;
F_19 ( V_12 , V_10 , V_20 ) ;
F_17 ( & V_12 -> V_18 ) ;
}
static int F_21 ( struct V_8 * V_9 , unsigned V_10 )
{
struct V_11 * V_12 = F_11 ( V_9 ) ;
F_16 ( & V_12 -> V_18 ) ;
F_4 ( V_21 , V_12 -> V_15 +
V_12 -> V_13 [ V_10 ] ) ;
F_17 ( & V_12 -> V_18 ) ;
return 0 ;
}
static int F_22 ( struct V_8 * V_9 , unsigned V_10 ,
int V_20 )
{
struct V_11 * V_12 = F_11 ( V_9 ) ;
F_16 ( & V_12 -> V_18 ) ;
F_4 ( V_22 , V_12 -> V_15 +
V_12 -> V_13 [ V_10 ] ) ;
F_19 ( V_12 , V_10 , V_20 ) ;
F_17 ( & V_12 -> V_18 ) ;
return 0 ;
}
static int F_23 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = F_24 ( & V_24 -> V_27 ) ;
struct V_28 * V_29 ;
struct V_11 * V_12 ;
int V_30 , V_31 ;
if ( ! F_25 ( & V_24 -> V_27 , V_26 -> V_15 + V_32 , 6 ,
V_2 ) ) {
F_13 ( & V_24 -> V_27 , L_3 ,
V_26 -> V_15 + V_32 , V_26 -> V_15 + V_32 + 5 ) ;
return - V_3 ;
}
V_29 = F_26 ( & V_24 -> V_27 , sizeof( * V_29 ) , V_33 ) ;
if ( ! V_29 )
return - V_34 ;
F_27 ( V_24 , V_29 ) ;
for ( V_31 = 0 ; V_31 < F_28 ( V_29 -> V_35 ) ; V_31 ++ ) {
V_12 = & V_29 -> V_35 [ V_31 ] ;
F_29 ( & V_12 -> V_18 ) ;
V_12 -> V_9 . V_36 = V_2 ;
V_12 -> V_9 . V_37 = V_38 ;
V_12 -> V_9 . V_39 = F_10 ;
V_12 -> V_9 . free = F_14 ;
V_12 -> V_9 . V_40 = F_21 ;
V_12 -> V_9 . V_41 = F_22 ;
V_12 -> V_9 . V_42 = F_15 ;
V_12 -> V_9 . V_43 = F_20 ;
V_12 -> V_9 . V_44 = 8 ;
V_12 -> V_9 . V_16 = & V_24 -> V_27 ;
V_12 -> V_9 . V_45 = V_46 [ V_31 ] . V_45 ;
V_12 -> V_13 = V_46 [ V_31 ] . V_13 ;
V_12 -> V_19 = V_46 [ V_31 ] . V_19 ;
V_12 -> V_15 = V_26 -> V_15 ;
V_30 = F_30 ( & V_12 -> V_9 , V_12 ) ;
if ( V_30 < 0 ) {
F_13 ( & V_24 -> V_27 ,
L_4 , V_30 ) ;
goto V_47;
}
F_31 ( & V_24 -> V_27 ,
L_5 , V_31 ) ;
}
return 0 ;
V_47:
for ( -- V_31 ; V_31 >= 0 ; V_31 -- )
F_32 ( & V_29 -> V_35 [ V_31 ] . V_9 ) ;
return V_30 ;
}
static int F_33 ( struct V_23 * V_24 )
{
struct V_28 * V_29 = F_34 ( V_24 ) ;
int V_31 ;
for ( V_31 = 0 ; V_31 < F_28 ( V_29 -> V_35 ) ; V_31 ++ ) {
F_32 ( & V_29 -> V_35 [ V_31 ] . V_9 ) ;
F_31 ( & V_24 -> V_27 ,
L_6 , V_31 ) ;
}
return 0 ;
}
static int T_1 F_35 ( int V_1 , unsigned short * V_48 )
{
int V_30 = 0 , V_6 ;
unsigned short V_49 ;
unsigned char V_50 ;
V_30 = F_1 ( V_1 ) ;
if ( V_30 )
return V_30 ;
V_6 = F_7 ( V_1 , 0x20 ) ;
switch ( V_6 ) {
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
F_9 ( V_1 , 0x07 , 0x0a ) ;
if ( ( F_7 ( V_1 , 0x30 ) & 0x01 ) == 0 )
F_36 ( L_7 ) ;
V_49 = ( F_7 ( V_1 , 0x60 ) << 8 ) |
F_7 ( V_1 , 0x61 ) ;
if ( ! V_49 ) {
F_3 ( L_8 ) ;
V_30 = - V_14 ;
goto exit;
}
* V_48 = V_49 ;
F_36 ( L_9 , V_50 , V_49 ) ;
exit:
F_5 ( V_1 ) ;
return V_30 ;
}
static int T_1 F_37 ( const unsigned short V_48 )
{
struct V_25 V_26 ;
int V_30 ;
V_26 . V_15 = V_48 ;
V_51 = F_38 ( V_2 , - 1 ) ;
if ( ! V_51 )
return - V_34 ;
V_30 = F_39 ( V_51 ,
& V_26 , sizeof( V_26 ) ) ;
if ( V_30 ) {
F_3 ( V_2 L_10 ) ;
goto V_30;
}
V_30 = F_40 ( V_51 ) ;
if ( V_30 ) {
F_3 ( V_2 L_11 ) ;
goto V_30;
}
return 0 ;
V_30:
F_41 ( V_51 ) ;
return V_30 ;
}
static int T_1 F_42 ( void )
{
int V_30 , V_31 ;
unsigned short V_48 = 0 ;
for ( V_31 = 0 ; V_31 < F_28 ( V_52 ) ; V_31 ++ )
if ( F_35 ( V_52 [ V_31 ] , & V_48 ) == 0 )
break;
if ( ! V_48 )
return - V_14 ;
V_30 = F_43 ( & V_53 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_37 ( V_48 ) ;
if ( V_30 )
goto V_54;
return 0 ;
V_54:
F_44 ( & V_53 ) ;
return V_30 ;
}
static void T_2 F_45 ( void )
{
F_46 ( V_51 ) ;
F_44 ( & V_53 ) ;
}
