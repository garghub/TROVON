static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 , const char * V_6 )
{
unsigned int V_7 ;
F_2 ( V_4 , V_5 , V_8 , & V_7 ) ;
F_3 ( V_2 , L_1 , V_5 , V_6 , V_7 ) ;
F_2 ( V_4 , V_5 , V_9 , & V_7 ) ;
F_3 ( V_2 , L_2 , V_7 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 , unsigned int V_10 ,
const char * V_6 )
{
unsigned int V_7 ;
F_2 ( V_4 , V_5 , V_8 , & V_7 ) ;
F_3 ( V_2 , L_1 , V_5 , V_6 , V_7 ) ;
if ( V_7 == 0x00400200 )
return;
F_2 ( V_4 , V_5 , V_10 , & V_7 ) ;
F_3 ( V_2 , L_3 , V_7 ) ;
F_3 ( V_2 , L_4 ,
F_5 ( V_7 ) ,
F_6 ( V_7 ) ,
F_7 ( V_7 ) ,
F_8 ( V_7 ) ) ;
F_9 ( V_4 , V_5 , V_11 , 0 , 0 , & V_7 , NULL ) ;
F_3 ( V_2 , L_5 , V_7 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
int V_12 , V_13 , V_14 ;
unsigned int V_7 ;
F_2 ( V_4 , V_5 , V_8 , & V_7 ) ;
F_3 ( V_2 , L_6 , V_5 , V_7 ) ;
V_14 = V_7 & 0xff ;
for ( V_12 = 0 ; V_12 < V_14 ; V_12 += 4 ) {
unsigned int V_15 ;
unsigned short V_16 [ 4 ] ;
const char * V_6 ;
F_9 ( V_4 , V_5 , V_17 ,
V_12 , 0 , & V_7 , & V_15 ) ;
V_16 [ 0 ] = V_7 & 0xfff ;
V_16 [ 1 ] = ( V_7 >> 16 ) & 0xfff ;
V_16 [ 2 ] = V_15 & 0xfff ;
V_16 [ 3 ] = ( V_15 >> 16 ) & 0xfff ;
for ( V_13 = 0 ; V_13 < 4 ; V_13 ++ ) {
unsigned char type = V_16 [ V_13 ] >> 8 ;
unsigned int V_18 = V_16 [ V_13 ] & 0xff ;
if ( V_12 + V_13 >= V_14 )
break;
if ( type == V_19 ) {
V_6 = L_7 ;
V_18 = F_11 ( V_18 ) ;
} else if ( type == V_20 ) {
V_6 = L_8 ;
V_18 = F_11 ( V_18 ) ;
} else {
V_6 = L_9 ;
}
F_3 ( V_2 , L_10 ,
V_12 + V_13 , type , V_6 , V_18 ) ;
}
}
}
static void F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
unsigned int V_7 ;
F_2 ( V_4 , V_5 , V_8 , & V_7 ) ;
F_3 ( V_2 , L_11 , V_5 , V_7 ) ;
}
static void F_13 ( struct V_21 * V_22 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = V_22 -> V_23 ;
unsigned int V_7 ;
int V_12 , V_5 ;
F_2 ( V_4 , 0 , V_24 , & V_7 ) ;
F_3 ( V_2 , L_12 , V_7 ) ;
F_2 ( V_4 , 1 , V_25 , & V_7 ) ;
F_3 ( V_2 , L_13 , V_7 ) ;
F_2 ( V_4 , 1 , V_26 , & V_7 ) ;
F_3 ( V_2 , L_14 , V_7 ) ;
F_3 ( V_2 , L_15 ,
V_4 -> V_27 [ V_28 ] . V_29 , V_4 -> V_27 [ V_30 ] . V_29 ) ;
V_5 = 2 ;
for ( V_12 = 0 ; V_12 < V_4 -> V_31 [ V_28 ] . V_32 ; V_12 ++ , V_5 ++ )
F_1 ( V_2 , V_4 , V_5 , L_16 ) ;
for ( V_12 = 0 ; V_12 < V_4 -> V_31 [ V_30 ] . V_32 ; V_12 ++ , V_5 ++ )
F_1 ( V_2 , V_4 , V_5 , L_17 ) ;
for ( V_12 = 0 ; V_12 < V_4 -> V_27 [ V_28 ] . V_29 ; V_12 ++ , V_5 ++ )
F_4 ( V_2 , V_4 , V_5 , V_33 ,
L_18 ) ;
for ( V_12 = 0 ; V_12 < V_4 -> V_27 [ V_30 ] . V_29 ; V_12 ++ , V_5 ++ )
F_4 ( V_2 , V_4 , V_5 , V_34 ,
L_19 ) ;
if ( F_14 ( V_4 -> V_35 ) ) {
F_10 ( V_2 , V_4 , V_5 ) ;
V_5 ++ ;
}
if ( F_15 ( V_4 -> V_35 ) ) {
F_12 ( V_2 , V_4 , V_5 ) ;
V_5 ++ ;
}
}
static void F_16 ( struct V_21 * V_22 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = V_22 -> V_23 ;
char line [ 64 ] ;
unsigned int V_36 , V_37 , V_38 , V_39 ;
while ( ! F_17 ( V_2 , line , sizeof( line ) ) ) {
if ( sscanf ( line , L_20 , & V_36 , & V_37 , & V_38 , & V_39 ) != 4 )
continue;
F_9 ( V_4 , V_36 , V_37 , V_38 , V_39 ,
& V_4 -> V_40 ,
& V_4 -> V_41 ) ;
}
}
static void F_18 ( struct V_21 * V_22 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = V_22 -> V_23 ;
F_3 ( V_2 , L_21 , V_4 -> V_40 , V_4 -> V_41 ) ;
}
static void F_19 ( struct V_21 * V_22 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = V_22 -> V_23 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < 0x40 ; V_12 += 4 ) {
F_3 ( V_2 , L_22 , V_12 ,
F_20 ( V_4 -> V_42 [ V_43 ] . V_44 + V_12 ) ) ;
}
F_3 ( V_2 , L_23 ) ;
for ( V_12 = 0 ; V_12 < 0x30 ; V_12 += 4 ) {
F_3 ( V_2 , L_24 , V_12 ,
F_20 ( V_4 -> V_42 [ V_45 ] . V_44 + V_12 ) ) ;
}
F_3 ( V_2 , L_23 ) ;
for ( V_12 = 0x80 ; V_12 < 0xa0 ; V_12 += 4 ) {
F_3 ( V_2 , L_24 , V_12 ,
F_20 ( V_4 -> V_42 [ V_45 ] . V_44 + V_12 ) ) ;
}
F_3 ( V_2 , L_23 ) ;
for ( V_12 = 0 ; V_12 < 32 ; V_12 ++ ) {
F_3 ( V_2 , L_25 , V_12 ,
F_21 ( V_4 , V_12 , V_46 ) ) ;
F_3 ( V_2 , L_26 , V_12 ,
F_21 ( V_4 , V_12 , V_47 ) ) ;
F_3 ( V_2 , L_27 , V_12 ,
F_21 ( V_4 , V_12 , V_48 ) ) ;
F_3 ( V_2 , L_28 , V_12 ,
F_21 ( V_4 , V_12 , V_49 ) ) ;
F_3 ( V_2 , L_29 , V_12 ,
F_21 ( V_4 , V_12 , V_50 ) ) ;
F_3 ( V_2 , L_30 , V_12 ,
F_21 ( V_4 , V_12 , V_51 ) ) ;
}
}
void F_22 ( struct V_3 * V_4 )
{
struct V_21 * V_22 ;
if ( ! F_23 ( V_4 -> V_52 , L_31 , & V_22 ) )
F_24 ( V_22 , V_4 , F_13 ) ;
if ( ! F_23 ( V_4 -> V_52 , L_32 , & V_22 ) ) {
F_24 ( V_22 , V_4 , F_18 ) ;
V_22 -> V_53 |= V_54 ;
V_22 -> V_55 . V_56 . V_57 = F_16 ;
}
if ( ! F_23 ( V_4 -> V_52 , L_33 , & V_22 ) )
F_24 ( V_22 , V_4 , F_19 ) ;
}
