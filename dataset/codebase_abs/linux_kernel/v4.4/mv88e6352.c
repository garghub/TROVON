static char * F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 , V_3 , V_4 ,
F_3 ( V_4 ) ) ;
}
static int F_4 ( struct V_5 * V_6 )
{
T_1 V_7 = F_5 ( V_6 ) ;
int V_8 ;
T_1 V_9 ;
V_8 = F_6 ( V_6 ) ;
if ( V_8 )
return V_8 ;
F_7 ( V_10 , V_11 ,
V_12 | V_13 ) ;
V_9 = V_7 << V_14 |
V_7 << V_15 |
V_7 << V_16 ;
F_7 ( V_10 , V_17 , V_9 ) ;
F_7 ( V_10 , 0x1c , V_6 -> V_18 & 0x1f ) ;
return 0 ;
}
static int F_8 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = F_9 ( V_6 ) ;
int V_8 ;
V_8 = F_10 ( V_6 ) ;
if ( V_8 < 0 )
return V_8 ;
V_20 -> V_21 = 7 ;
F_11 ( & V_20 -> V_22 ) ;
V_8 = F_12 ( V_6 , true ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_4 ( V_6 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_13 ( V_6 ) ;
}
static int F_14 ( struct V_5 * V_6 , int V_23 )
{
struct V_19 * V_20 = F_9 ( V_6 ) ;
int V_8 ;
F_15 ( & V_20 -> V_22 ) ;
V_8 = F_16 ( V_6 , V_24 , V_25 ,
V_26 |
( V_23 & V_27 ) ) ;
if ( V_8 < 0 )
goto error;
V_8 = F_17 ( V_6 ) ;
if ( V_8 < 0 )
goto error;
V_8 = F_18 ( V_6 , V_24 , V_28 ) ;
error:
F_19 ( & V_20 -> V_22 ) ;
return V_8 ;
}
static int F_20 ( struct V_5 * V_6 ,
struct V_29 * V_30 , T_2 * V_31 )
{
int V_32 ;
int V_33 ;
int V_8 ;
V_32 = V_30 -> V_32 ;
V_33 = V_30 -> V_33 ;
V_30 -> V_33 = 0 ;
V_30 -> V_34 = 0xc3ec4951 ;
V_8 = F_21 ( V_6 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_32 & 1 ) {
int V_35 ;
V_35 = F_14 ( V_6 , V_32 >> 1 ) ;
if ( V_35 < 0 )
return V_35 ;
* V_31 ++ = ( V_35 >> 8 ) & 0xff ;
V_32 ++ ;
V_33 -- ;
V_30 -> V_33 ++ ;
}
while ( V_33 >= 2 ) {
int V_35 ;
V_35 = F_14 ( V_6 , V_32 >> 1 ) ;
if ( V_35 < 0 )
return V_35 ;
* V_31 ++ = V_35 & 0xff ;
* V_31 ++ = ( V_35 >> 8 ) & 0xff ;
V_32 += 2 ;
V_33 -= 2 ;
V_30 -> V_33 += 2 ;
}
if ( V_33 ) {
int V_35 ;
V_35 = F_14 ( V_6 , V_32 >> 1 ) ;
if ( V_35 < 0 )
return V_35 ;
* V_31 ++ = V_35 & 0xff ;
V_32 ++ ;
V_33 -- ;
V_30 -> V_33 ++ ;
}
return 0 ;
}
static int F_22 ( struct V_5 * V_6 )
{
int V_8 ;
V_8 = F_18 ( V_6 , V_24 , V_25 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( ! ( V_8 & V_36 ) )
return - V_37 ;
return 0 ;
}
static int F_23 ( struct V_5 * V_6 , int V_23 ,
T_3 V_31 )
{
struct V_19 * V_20 = F_9 ( V_6 ) ;
int V_8 ;
F_15 ( & V_20 -> V_22 ) ;
V_8 = F_16 ( V_6 , V_24 , V_28 , V_31 ) ;
if ( V_8 < 0 )
goto error;
V_8 = F_16 ( V_6 , V_24 , V_25 ,
V_38 |
( V_23 & V_27 ) ) ;
if ( V_8 < 0 )
goto error;
V_8 = F_17 ( V_6 ) ;
error:
F_19 ( & V_20 -> V_22 ) ;
return V_8 ;
}
static int F_24 ( struct V_5 * V_6 ,
struct V_29 * V_30 , T_2 * V_31 )
{
int V_32 ;
int V_8 ;
int V_33 ;
if ( V_30 -> V_34 != 0xc3ec4951 )
return - V_39 ;
V_8 = F_22 ( V_6 ) ;
if ( V_8 )
return V_8 ;
V_32 = V_30 -> V_32 ;
V_33 = V_30 -> V_33 ;
V_30 -> V_33 = 0 ;
V_8 = F_21 ( V_6 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_32 & 1 ) {
int V_35 ;
V_35 = F_14 ( V_6 , V_32 >> 1 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = ( * V_31 ++ << 8 ) | ( V_35 & 0xff ) ;
V_8 = F_23 ( V_6 , V_32 >> 1 , V_35 ) ;
if ( V_8 < 0 )
return V_8 ;
V_32 ++ ;
V_33 -- ;
V_30 -> V_33 ++ ;
}
while ( V_33 >= 2 ) {
int V_35 ;
V_35 = * V_31 ++ ;
V_35 |= * V_31 ++ << 8 ;
V_8 = F_23 ( V_6 , V_32 >> 1 , V_35 ) ;
if ( V_8 < 0 )
return V_8 ;
V_32 += 2 ;
V_33 -= 2 ;
V_30 -> V_33 += 2 ;
}
if ( V_33 ) {
int V_35 ;
V_35 = F_14 ( V_6 , V_32 >> 1 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = ( V_35 & 0xff00 ) | * V_31 ++ ;
V_8 = F_23 ( V_6 , V_32 >> 1 , V_35 ) ;
if ( V_8 < 0 )
return V_8 ;
V_32 ++ ;
V_33 -- ;
V_30 -> V_33 ++ ;
}
return 0 ;
}
