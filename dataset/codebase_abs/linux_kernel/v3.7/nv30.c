void
F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 , T_1 V_5 , T_1 V_6 ,
T_1 V_7 , struct V_8 * V_9 )
{
V_9 -> V_4 = V_4 | 1 ;
V_9 -> V_10 = F_2 ( 1u , V_4 + V_5 ) - 1 ;
V_9 -> V_6 = V_6 ;
}
void
F_3 ( struct V_1 * V_2 , int V_3 , struct V_8 * V_9 )
{
V_9 -> V_4 = 0 ;
V_9 -> V_10 = 0 ;
V_9 -> V_6 = 0 ;
}
static int
F_4 ( struct V_11 * V_12 , int V_13 , int V_3 , int V_14 )
{
struct V_15 * V_16 = F_5 ( V_12 ) ;
int V_17 = ( V_16 -> V_18 > 0x30 ?
F_6 ( V_12 , 0x122c + 0x10 * V_13 + 0x4 * V_14 ) >> ( 4 * ( V_3 ^ 1 ) ) :
0 ) & 0xf ;
return 2 * ( V_17 & 0x8 ? V_17 - 0x10 : V_17 ) ;
}
static int
F_7 ( struct V_11 * V_12 , int V_19 , int V_13 , int V_3 )
{
int V_14 , V_20 = 0 ;
for ( V_14 = 0 ; V_14 < 4 ; V_14 ++ ) {
int V_21 = ( V_19 >> ( 8 * V_3 ) & 0xff ) + F_4 ( V_12 , V_13 , V_3 , V_14 ) ;
V_20 |= ( 0x80 | F_8 ( V_21 , 0 , 0x1f ) ) << ( 8 * V_14 ) ;
}
return V_20 ;
}
static int
F_9 ( struct V_22 * V_23 )
{
struct V_15 * V_16 = F_5 ( V_23 ) ;
struct V_11 * V_12 = ( void * ) V_23 ;
int V_24 , V_3 , V_14 ;
V_24 = F_10 ( & V_12 -> V_25 ) ;
if ( V_24 )
return V_24 ;
if ( V_16 -> V_18 == 0x30 ||
V_16 -> V_18 == 0x31 ||
V_16 -> V_18 == 0x35 ) {
int V_26 = ( V_16 -> V_18 == 0x31 ? 2 : 4 ) ;
int V_19 = F_6 ( V_12 , 0x1003d0 ) ;
for ( V_3 = 0 ; V_3 < V_26 ; V_3 ++ ) {
for ( V_14 = 0 ; V_14 < 3 ; V_14 ++ )
F_11 ( V_12 , 0x10037c + 0xc * V_3 + 0x4 * V_14 ,
F_7 ( V_12 , V_19 , 0 , V_14 ) ) ;
for ( V_14 = 0 ; V_14 < 2 ; V_14 ++ )
F_11 ( V_12 , 0x1003ac + 0x8 * V_3 + 0x4 * V_14 ,
F_7 ( V_12 , V_19 , 1 , V_14 ) ) ;
}
}
return 0 ;
}
static int
F_12 ( struct V_22 * V_27 , struct V_22 * V_28 ,
struct V_29 * V_30 , void * V_31 , T_1 V_5 ,
struct V_22 * * V_32 )
{
struct V_11 * V_12 ;
T_1 V_33 ;
int V_24 ;
V_24 = F_13 ( V_27 , V_28 , V_30 , & V_12 ) ;
* V_32 = F_14 ( V_12 ) ;
if ( V_24 )
return V_24 ;
V_33 = F_6 ( V_12 , 0x001218 ) ;
switch ( V_33 & 0x00000300 ) {
case 0x00000000 : V_12 -> V_25 . V_34 . type = V_35 ; break;
case 0x00000100 : V_12 -> V_25 . V_34 . type = V_36 ; break;
case 0x00000200 : V_12 -> V_25 . V_34 . type = V_37 ; break;
case 0x00000300 : V_12 -> V_25 . V_34 . type = V_38 ; break;
}
V_12 -> V_25 . V_34 . V_5 = F_6 ( V_12 , 0x10020c ) & 0xff000000 ;
V_12 -> V_25 . V_39 = V_40 ;
V_12 -> V_25 . V_9 . V_41 = 8 ;
V_12 -> V_25 . V_9 . V_42 = F_1 ;
V_12 -> V_25 . V_9 . V_43 = F_3 ;
V_12 -> V_25 . V_9 . V_44 = V_45 ;
return F_15 ( & V_12 -> V_25 ) ;
}
