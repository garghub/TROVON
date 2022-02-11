static char * F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
if ( V_5 == NULL )
return NULL ;
V_6 = F_3 ( V_5 , V_3 , F_4 ( 0 ) , V_7 ) ;
if ( V_6 >= 0 ) {
if ( ( V_6 & 0xfff0 ) == V_8 )
return L_1 ;
if ( ( V_6 & 0xfff0 ) == V_9 )
return L_2 ;
if ( V_6 == V_10 )
return L_3 ;
if ( V_6 == V_11 )
return L_4 ;
if ( ( V_6 & 0xfff0 ) == V_12 )
return L_5 ;
}
return NULL ;
}
static int F_5 ( struct V_13 * V_14 )
{
T_1 V_15 = F_6 ( V_14 ) ;
int V_6 ;
T_1 V_16 ;
V_6 = F_7 ( V_14 ) ;
if ( V_6 )
return V_6 ;
F_8 ( V_17 , V_18 ,
V_19 | V_20 ) ;
V_16 = V_15 << V_21 |
V_15 << V_22 |
V_15 << V_23 ;
F_8 ( V_17 , V_24 , V_16 ) ;
F_8 ( V_17 , 0x1c , V_14 -> V_25 & 0x1f ) ;
return 0 ;
}
static int F_9 ( struct V_13 * V_14 , int * V_26 )
{
int V_6 ;
* V_26 = 0 ;
V_6 = F_10 ( V_14 , 0 , 6 , 27 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_26 = ( V_6 & 0xff ) - 25 ;
return 0 ;
}
static int F_11 ( struct V_13 * V_14 , int * V_26 )
{
int V_6 ;
* V_26 = 0 ;
V_6 = F_10 ( V_14 , 0 , 6 , 26 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_26 = ( ( ( V_6 >> 8 ) & 0x1f ) * 5 ) - 25 ;
return 0 ;
}
static int F_12 ( struct V_13 * V_14 , int V_26 )
{
int V_6 ;
V_6 = F_10 ( V_14 , 0 , 6 , 26 ) ;
if ( V_6 < 0 )
return V_6 ;
V_26 = F_13 ( F_14 ( V_26 , 5 ) + 5 , 0 , 0x1f ) ;
return F_15 ( V_14 , 0 , 6 , 26 ,
( V_6 & 0xe0ff ) | ( V_26 << 8 ) ) ;
}
static int F_16 ( struct V_13 * V_14 , bool * V_27 )
{
int V_6 ;
* V_27 = false ;
V_6 = F_10 ( V_14 , 0 , 6 , 26 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_27 = ! ! ( V_6 & 0x40 ) ;
return 0 ;
}
static int F_17 ( struct V_13 * V_14 )
{
struct V_28 * V_29 = F_18 ( V_14 ) ;
int V_6 ;
V_6 = F_19 ( V_14 ) ;
if ( V_6 < 0 )
return V_6 ;
V_29 -> V_30 = 7 ;
F_20 ( & V_29 -> V_31 ) ;
V_6 = F_21 ( V_14 , true ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_5 ( V_14 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_22 ( V_14 ) ;
}
static int F_23 ( struct V_13 * V_14 , int V_32 )
{
struct V_28 * V_29 = F_18 ( V_14 ) ;
int V_6 ;
F_24 ( & V_29 -> V_31 ) ;
V_6 = F_25 ( V_14 , V_33 , 0x14 ,
0xc000 | ( V_32 & 0xff ) ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_26 ( V_14 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_27 ( V_14 , V_33 , 0x15 ) ;
error:
F_28 ( & V_29 -> V_31 ) ;
return V_6 ;
}
static int F_29 ( struct V_13 * V_14 ,
struct V_34 * V_35 , T_2 * V_36 )
{
int V_37 ;
int V_38 ;
int V_6 ;
V_37 = V_35 -> V_37 ;
V_38 = V_35 -> V_38 ;
V_35 -> V_38 = 0 ;
V_35 -> V_39 = 0xc3ec4951 ;
V_6 = F_30 ( V_14 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_37 & 1 ) {
int V_40 ;
V_40 = F_23 ( V_14 , V_37 >> 1 ) ;
if ( V_40 < 0 )
return V_40 ;
* V_36 ++ = ( V_40 >> 8 ) & 0xff ;
V_37 ++ ;
V_38 -- ;
V_35 -> V_38 ++ ;
}
while ( V_38 >= 2 ) {
int V_40 ;
V_40 = F_23 ( V_14 , V_37 >> 1 ) ;
if ( V_40 < 0 )
return V_40 ;
* V_36 ++ = V_40 & 0xff ;
* V_36 ++ = ( V_40 >> 8 ) & 0xff ;
V_37 += 2 ;
V_38 -= 2 ;
V_35 -> V_38 += 2 ;
}
if ( V_38 ) {
int V_40 ;
V_40 = F_23 ( V_14 , V_37 >> 1 ) ;
if ( V_40 < 0 )
return V_40 ;
* V_36 ++ = V_40 & 0xff ;
V_37 ++ ;
V_38 -- ;
V_35 -> V_38 ++ ;
}
return 0 ;
}
static int F_31 ( struct V_13 * V_14 )
{
int V_6 ;
V_6 = F_27 ( V_14 , V_33 , 0x14 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( ! ( V_6 & 0x0400 ) )
return - V_41 ;
return 0 ;
}
static int F_32 ( struct V_13 * V_14 , int V_32 ,
T_3 V_36 )
{
struct V_28 * V_29 = F_18 ( V_14 ) ;
int V_6 ;
F_24 ( & V_29 -> V_31 ) ;
V_6 = F_25 ( V_14 , V_33 , 0x15 , V_36 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_25 ( V_14 , V_33 , 0x14 ,
0xb000 | ( V_32 & 0xff ) ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_26 ( V_14 ) ;
error:
F_28 ( & V_29 -> V_31 ) ;
return V_6 ;
}
static int F_33 ( struct V_13 * V_14 ,
struct V_34 * V_35 , T_2 * V_36 )
{
int V_37 ;
int V_6 ;
int V_38 ;
if ( V_35 -> V_39 != 0xc3ec4951 )
return - V_42 ;
V_6 = F_31 ( V_14 ) ;
if ( V_6 )
return V_6 ;
V_37 = V_35 -> V_37 ;
V_38 = V_35 -> V_38 ;
V_35 -> V_38 = 0 ;
V_6 = F_30 ( V_14 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_37 & 1 ) {
int V_40 ;
V_40 = F_23 ( V_14 , V_37 >> 1 ) ;
if ( V_40 < 0 )
return V_40 ;
V_40 = ( * V_36 ++ << 8 ) | ( V_40 & 0xff ) ;
V_6 = F_32 ( V_14 , V_37 >> 1 , V_40 ) ;
if ( V_6 < 0 )
return V_6 ;
V_37 ++ ;
V_38 -- ;
V_35 -> V_38 ++ ;
}
while ( V_38 >= 2 ) {
int V_40 ;
V_40 = * V_36 ++ ;
V_40 |= * V_36 ++ << 8 ;
V_6 = F_32 ( V_14 , V_37 >> 1 , V_40 ) ;
if ( V_6 < 0 )
return V_6 ;
V_37 += 2 ;
V_38 -= 2 ;
V_35 -> V_38 += 2 ;
}
if ( V_38 ) {
int V_40 ;
V_40 = F_23 ( V_14 , V_37 >> 1 ) ;
if ( V_40 < 0 )
return V_40 ;
V_40 = ( V_40 & 0xff00 ) | * V_36 ++ ;
V_6 = F_32 ( V_14 , V_37 >> 1 , V_40 ) ;
if ( V_6 < 0 )
return V_6 ;
V_37 ++ ;
V_38 -- ;
V_35 -> V_38 ++ ;
}
return 0 ;
}
