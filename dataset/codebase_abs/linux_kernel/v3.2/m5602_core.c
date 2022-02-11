int F_1 ( struct V_1 * V_1 , const T_1 V_2 , T_1 * V_3 )
{
int V_4 ;
struct V_5 * V_6 = V_1 -> V_7 . V_8 ;
T_2 * V_9 = V_1 -> V_7 . V_10 ;
V_4 = F_2 ( V_6 , F_3 ( V_6 , 0 ) ,
0x04 , 0xc0 , 0x14 ,
0x8100 + V_2 , V_9 ,
1 , V_11 ) ;
* V_3 = V_9 [ 0 ] ;
F_4 ( V_12 , L_1 ,
V_2 , * V_3 ) ;
return ( V_4 < 0 ) ? V_4 : 0 ;
}
int F_5 ( struct V_1 * V_1 , const T_1 V_2 , const T_1 V_3 )
{
int V_4 ;
struct V_5 * V_6 = V_1 -> V_7 . V_8 ;
T_2 * V_9 = V_1 -> V_7 . V_10 ;
F_4 ( V_12 , L_2 ,
V_2 , V_3 ) ;
memcpy ( V_9 , V_13 ,
sizeof( V_13 ) ) ;
V_9 [ 1 ] = V_2 ;
V_9 [ 3 ] = V_3 ;
V_4 = F_2 ( V_6 , F_6 ( V_6 , 0 ) ,
0x04 , 0x40 , 0x19 ,
0x0000 , V_9 ,
4 , V_11 ) ;
return ( V_4 < 0 ) ? V_4 : 0 ;
}
static int F_7 ( struct V_1 * V_1 )
{
int V_4 ;
T_1 V_14 ;
do {
V_4 = F_1 ( V_1 , V_15 , & V_14 ) ;
} while ( ( V_14 & V_16 ) && ! V_4 );
return V_4 ;
}
int F_8 ( struct V_1 * V_1 , const T_1 V_2 ,
T_1 * V_3 , const T_1 V_17 )
{
int V_4 , V_18 ;
if ( ! V_17 || V_17 > V_1 -> V_19 -> V_20 )
return - V_21 ;
V_4 = F_7 ( V_1 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_5 ( V_1 , V_22 ,
V_1 -> V_19 -> V_23 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_5 ( V_1 , V_24 , V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_1 -> V_19 -> V_20 == 1 ) {
V_4 = F_5 ( V_1 , V_25 , 1 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_5 ( V_1 , V_25 , 0x08 ) ;
} else {
V_4 = F_5 ( V_1 , V_25 , 0x18 + V_17 ) ;
}
for ( V_18 = 0 ; ( V_18 < V_17 ) && ! V_4 ; V_18 ++ ) {
V_4 = F_7 ( V_1 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_1 ( V_1 , V_26 , & ( V_3 [ V_18 ] ) ) ;
F_4 ( V_12 , L_3
L_4 , V_2 , * V_3 ) ;
}
return V_4 ;
}
int F_9 ( struct V_1 * V_1 , const T_1 V_2 ,
T_1 * V_3 , const T_1 V_17 )
{
int V_4 , V_18 ;
T_1 * V_27 ;
struct V_5 * V_6 = V_1 -> V_7 . V_8 ;
T_2 * V_9 = V_1 -> V_7 . V_10 ;
if ( V_17 > V_1 -> V_19 -> V_20 || ! V_17 )
return - V_21 ;
memcpy ( V_9 , V_28 ,
sizeof( V_28 ) ) ;
V_9 [ 11 ] = V_1 -> V_19 -> V_23 ;
V_9 [ 15 ] = V_2 ;
V_27 = V_9 + 16 ;
for ( V_18 = 0 ; V_18 < V_17 ; V_18 ++ ) {
memcpy ( V_27 , V_28 + 16 , 4 ) ;
V_27 [ 3 ] = V_3 [ V_18 ] ;
V_27 += 4 ;
F_4 ( V_12 , L_5 ,
V_2 , V_3 [ V_18 ] ) ;
}
memcpy ( V_27 , V_28 + 20 , 4 ) ;
V_27 [ 3 ] = 0x10 + V_17 ;
V_4 = F_2 ( V_6 , F_6 ( V_6 , 0 ) ,
0x04 , 0x40 , 0x19 ,
0x0000 , V_9 ,
20 + V_17 * 4 , V_11 ) ;
return ( V_4 < 0 ) ? V_4 : 0 ;
}
static void F_10 ( struct V_1 * V_1 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < 0x80 ; V_18 ++ ) {
unsigned char V_29 = 0 ;
F_1 ( V_1 , V_18 , & V_29 ) ;
F_11 ( L_6 , V_18 , V_29 ) ;
}
F_11 ( L_7 ) ;
}
static int F_12 ( struct V_1 * V_1 )
{
V_1 -> V_19 = & V_30 ;
if ( ! V_1 -> V_19 -> V_31 ( V_1 ) )
return 0 ;
V_1 -> V_19 = & V_32 ;
if ( ! V_1 -> V_19 -> V_31 ( V_1 ) )
return 0 ;
V_1 -> V_19 = & V_33 ;
if ( ! V_1 -> V_19 -> V_31 ( V_1 ) )
return 0 ;
V_1 -> V_19 = & V_34 ;
if ( ! V_1 -> V_19 -> V_31 ( V_1 ) )
return 0 ;
V_1 -> V_19 = & V_35 ;
if ( ! V_1 -> V_19 -> V_31 ( V_1 ) )
return 0 ;
V_1 -> V_19 = & V_36 ;
if ( ! V_1 -> V_19 -> V_31 ( V_1 ) )
return 0 ;
F_11 ( L_8 ) ;
V_1 -> V_19 = NULL ;
return - V_37 ;
}
static int F_13 ( struct V_7 * V_7 )
{
struct V_1 * V_1 = (struct V_1 * ) V_7 ;
int V_4 ;
F_4 ( V_12 , L_9 ) ;
V_4 = V_1 -> V_19 -> V_38 ( V_1 ) ;
return V_4 ;
}
static int F_14 ( struct V_7 * V_7 )
{
struct V_1 * V_1 = (struct V_1 * ) V_7 ;
T_2 * V_9 = V_1 -> V_7 . V_10 ;
int V_4 ;
const T_1 V_39 [ 4 ] = { 0x13 , 0xf9 , 0x0f , 0x01 } ;
if ( V_1 -> V_19 -> V_40 )
V_1 -> V_19 -> V_40 ( V_1 ) ;
memcpy ( V_9 , V_39 , sizeof( V_39 ) ) ;
V_4 = F_2 ( V_7 -> V_8 ,
F_6 ( V_7 -> V_8 , 0 ) ,
0x04 , 0x40 , 0x19 , 0x0000 , V_9 ,
sizeof( V_39 ) , V_11 ) ;
F_4 ( V_41 , L_10 ) ;
return ( V_4 < 0 ) ? V_4 : 0 ;
}
static void F_15 ( struct V_7 * V_7 ,
T_1 * V_14 , int V_17 )
{
struct V_1 * V_1 = (struct V_1 * ) V_7 ;
if ( V_17 < 6 ) {
F_4 ( V_42 , L_11 ) ;
return;
}
if ( V_14 [ 0 ] == 0xff && V_14 [ 4 ] == 0xff && V_14 [ 5 ] == 0xff &&
V_14 [ 2 ] != V_1 -> V_43 ) {
F_4 ( V_44 , L_12 ) ;
V_1 -> V_43 = V_14 [ 2 ] ;
V_14 += 6 ;
V_17 -= 6 ;
F_16 ( V_7 , V_45 ,
NULL , 0 ) ;
V_1 -> V_46 ++ ;
F_16 ( V_7 , V_47 , V_14 , V_17 ) ;
F_4 ( V_44 , L_13 ,
V_1 -> V_46 ) ;
} else {
int V_48 ;
V_48 = V_7 -> V_49 ;
V_14 += 4 ;
V_17 -= 4 ;
if ( V_48 + V_17 <= V_7 -> V_50 ) {
F_4 ( V_44 , L_14 ,
V_1 -> V_46 , V_17 ) ;
F_16 ( V_7 , V_51 ,
V_14 , V_17 ) ;
} else {
F_16 ( V_7 , V_51 , V_14 ,
V_7 -> V_50 - V_48 ) ;
}
}
}
static void F_17 ( struct V_7 * V_7 )
{
struct V_1 * V_1 = (struct V_1 * ) V_7 ;
if ( V_1 -> V_19 -> V_52 )
V_1 -> V_19 -> V_52 ( V_1 ) ;
}
static int F_18 ( struct V_7 * V_7 ,
const struct V_53 * V_54 )
{
struct V_1 * V_1 = (struct V_1 * ) V_7 ;
struct V_55 * V_55 ;
int V_4 ;
V_55 = & V_7 -> V_55 ;
V_1 -> V_56 = & V_57 ;
if ( V_58 )
F_10 ( V_1 ) ;
V_4 = F_12 ( V_1 ) ;
if ( V_4 )
goto V_59;
return 0 ;
V_59:
F_4 ( V_60 , L_15 ) ;
V_55 -> V_61 = NULL ;
V_55 -> V_62 = 0 ;
return V_4 ;
}
static int F_19 ( struct V_63 * V_64 ,
const struct V_53 * V_54 )
{
return F_20 ( V_64 , V_54 , & V_57 , sizeof( struct V_1 ) ,
V_65 ) ;
}
static void F_21 ( struct V_63 * V_64 )
{
struct V_7 * V_7 = F_22 ( V_64 ) ;
struct V_1 * V_1 = (struct V_1 * ) V_7 ;
if ( V_1 -> V_19 -> V_66 )
V_1 -> V_19 -> V_66 ( V_1 ) ;
F_23 ( V_64 ) ;
}
static int T_3 F_24 ( void )
{
return F_25 ( & V_67 ) ;
}
static void T_4 F_26 ( void )
{
F_27 ( & V_67 ) ;
}
