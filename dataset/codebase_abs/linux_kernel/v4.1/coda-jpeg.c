static void F_1 ( void * V_1 ,
const struct V_2 * V_3 )
{
T_1 * V_4 = V_1 + V_3 -> V_5 ;
const T_1 * V_6 = V_3 -> V_6 ;
int V_7 = V_3 -> V_7 / 4 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 += 2 ) {
V_4 [ V_8 + 1 ] = F_2 ( V_6 [ V_8 ] ) ;
V_4 [ V_8 ] = F_2 ( V_6 [ V_8 + 1 ] ) ;
}
}
int F_3 ( struct V_9 * V_10 )
{
int V_8 ;
static const struct V_2 V_11 [ 8 ] = {
{ 0 , V_12 , sizeof( V_12 ) } ,
{ 16 , V_13 , sizeof( V_13 ) } ,
{ 32 , V_14 , sizeof( V_14 ) } ,
{ 48 , V_15 , sizeof( V_15 ) } ,
{ 216 , V_16 , sizeof( V_16 ) } ,
{ 232 , V_17 , sizeof( V_17 ) } ,
{ 248 , V_18 , sizeof( V_18 ) } ,
{ 264 , V_19 , sizeof( V_19 ) } ,
} ;
struct V_2 V_20 [ 3 ] = {
{ 512 , V_10 -> V_21 . V_22 [ 0 ] , 64 } ,
{ 576 , V_10 -> V_21 . V_22 [ 1 ] , 64 } ,
{ 640 , V_10 -> V_21 . V_22 [ 1 ] , 64 } ,
} ;
for ( V_8 = 0 ; V_8 < F_4 ( V_11 ) ; V_8 ++ )
F_1 ( V_10 -> V_1 . V_23 , V_11 + V_8 ) ;
for ( V_8 = 0 ; V_8 < F_4 ( V_20 ) ; V_8 ++ )
F_1 ( V_10 -> V_1 . V_23 , V_20 + V_8 ) ;
return 0 ;
}
bool F_5 ( struct V_9 * V_10 , struct V_24 * V_25 )
{
void * V_23 = F_6 ( V_25 , 0 ) ;
T_2 V_26 = F_7 ( ( V_27 * ) V_23 ) ;
T_2 V_28 = F_7 ( ( V_27 * ) ( V_23 +
F_8 ( V_25 , 0 ) - 2 ) ) ;
return V_26 == V_29 && V_28 == V_30 ;
}
static void F_9 ( T_3 * V_31 , int V_32 )
{
unsigned int V_33 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < 64 ; V_8 ++ ) {
V_33 = F_10 ( ( unsigned int ) V_31 [ V_8 ] * V_32 , 100 ) ;
if ( V_33 <= 0 )
V_33 = 1 ;
if ( V_33 > 255 )
V_33 = 255 ;
V_31 [ V_8 ] = ( unsigned char ) V_33 ;
}
}
void F_11 ( struct V_9 * V_10 , int V_34 )
{
unsigned int V_32 ;
V_10 -> V_21 . V_35 = V_34 ;
if ( V_34 > 100 )
V_34 = 100 ;
if ( V_34 < 5 )
V_34 = 5 ;
if ( V_34 < 50 )
V_32 = 5000 / V_34 ;
else
V_32 = 200 - 2 * V_34 ;
if ( V_10 -> V_21 . V_22 [ 0 ] ) {
memcpy ( V_10 -> V_21 . V_22 [ 0 ] , V_36 , 64 ) ;
F_9 ( V_10 -> V_21 . V_22 [ 0 ] , V_32 ) ;
}
if ( V_10 -> V_21 . V_22 [ 1 ] ) {
memcpy ( V_10 -> V_21 . V_22 [ 1 ] , V_37 , 64 ) ;
F_9 ( V_10 -> V_21 . V_22 [ 1 ] , V_32 ) ;
}
}
