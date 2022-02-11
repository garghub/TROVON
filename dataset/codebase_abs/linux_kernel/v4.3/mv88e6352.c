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
if ( V_6 == V_13 )
return L_6 ;
if ( V_6 == V_14 )
return L_7 ;
if ( ( V_6 & 0xfff0 ) == V_15 )
return L_8 ;
if ( V_6 == V_16 )
return L_9 ;
if ( V_6 == V_17 )
return L_10 ;
if ( ( V_6 & 0xfff0 ) == V_18 )
return L_11 ;
}
return NULL ;
}
static int F_5 ( struct V_19 * V_20 )
{
T_1 V_21 = F_6 ( V_20 ) ;
int V_6 ;
T_1 V_22 ;
V_6 = F_7 ( V_20 ) ;
if ( V_6 )
return V_6 ;
F_8 ( V_23 , V_24 ,
V_25 | V_26 ) ;
V_22 = V_21 << V_27 |
V_21 << V_28 |
V_21 << V_29 ;
F_8 ( V_23 , V_30 , V_22 ) ;
F_8 ( V_23 , 0x1c , V_20 -> V_31 & 0x1f ) ;
return 0 ;
}
static int F_9 ( struct V_19 * V_20 )
{
struct V_32 * V_33 = F_10 ( V_20 ) ;
int V_6 ;
V_6 = F_11 ( V_20 ) ;
if ( V_6 < 0 )
return V_6 ;
V_33 -> V_34 = 7 ;
F_12 ( & V_33 -> V_35 ) ;
V_6 = F_13 ( V_20 , true ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_5 ( V_20 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_14 ( V_20 ) ;
}
static int F_15 ( struct V_19 * V_20 , int V_36 )
{
struct V_32 * V_33 = F_10 ( V_20 ) ;
int V_6 ;
F_16 ( & V_33 -> V_35 ) ;
V_6 = F_17 ( V_20 , V_37 , V_38 ,
V_39 |
( V_36 & V_40 ) ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_18 ( V_20 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_19 ( V_20 , V_37 , V_41 ) ;
error:
F_20 ( & V_33 -> V_35 ) ;
return V_6 ;
}
static int F_21 ( struct V_19 * V_20 ,
struct V_42 * V_43 , T_2 * V_44 )
{
int V_45 ;
int V_46 ;
int V_6 ;
V_45 = V_43 -> V_45 ;
V_46 = V_43 -> V_46 ;
V_43 -> V_46 = 0 ;
V_43 -> V_47 = 0xc3ec4951 ;
V_6 = F_22 ( V_20 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_45 & 1 ) {
int V_48 ;
V_48 = F_15 ( V_20 , V_45 >> 1 ) ;
if ( V_48 < 0 )
return V_48 ;
* V_44 ++ = ( V_48 >> 8 ) & 0xff ;
V_45 ++ ;
V_46 -- ;
V_43 -> V_46 ++ ;
}
while ( V_46 >= 2 ) {
int V_48 ;
V_48 = F_15 ( V_20 , V_45 >> 1 ) ;
if ( V_48 < 0 )
return V_48 ;
* V_44 ++ = V_48 & 0xff ;
* V_44 ++ = ( V_48 >> 8 ) & 0xff ;
V_45 += 2 ;
V_46 -= 2 ;
V_43 -> V_46 += 2 ;
}
if ( V_46 ) {
int V_48 ;
V_48 = F_15 ( V_20 , V_45 >> 1 ) ;
if ( V_48 < 0 )
return V_48 ;
* V_44 ++ = V_48 & 0xff ;
V_45 ++ ;
V_46 -- ;
V_43 -> V_46 ++ ;
}
return 0 ;
}
static int F_23 ( struct V_19 * V_20 )
{
int V_6 ;
V_6 = F_19 ( V_20 , V_37 , V_38 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( ! ( V_6 & V_49 ) )
return - V_50 ;
return 0 ;
}
static int F_24 ( struct V_19 * V_20 , int V_36 ,
T_3 V_44 )
{
struct V_32 * V_33 = F_10 ( V_20 ) ;
int V_6 ;
F_16 ( & V_33 -> V_35 ) ;
V_6 = F_17 ( V_20 , V_37 , V_41 , V_44 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_17 ( V_20 , V_37 , V_38 ,
V_51 |
( V_36 & V_40 ) ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_18 ( V_20 ) ;
error:
F_20 ( & V_33 -> V_35 ) ;
return V_6 ;
}
static int F_25 ( struct V_19 * V_20 ,
struct V_42 * V_43 , T_2 * V_44 )
{
int V_45 ;
int V_6 ;
int V_46 ;
if ( V_43 -> V_47 != 0xc3ec4951 )
return - V_52 ;
V_6 = F_23 ( V_20 ) ;
if ( V_6 )
return V_6 ;
V_45 = V_43 -> V_45 ;
V_46 = V_43 -> V_46 ;
V_43 -> V_46 = 0 ;
V_6 = F_22 ( V_20 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_45 & 1 ) {
int V_48 ;
V_48 = F_15 ( V_20 , V_45 >> 1 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = ( * V_44 ++ << 8 ) | ( V_48 & 0xff ) ;
V_6 = F_24 ( V_20 , V_45 >> 1 , V_48 ) ;
if ( V_6 < 0 )
return V_6 ;
V_45 ++ ;
V_46 -- ;
V_43 -> V_46 ++ ;
}
while ( V_46 >= 2 ) {
int V_48 ;
V_48 = * V_44 ++ ;
V_48 |= * V_44 ++ << 8 ;
V_6 = F_24 ( V_20 , V_45 >> 1 , V_48 ) ;
if ( V_6 < 0 )
return V_6 ;
V_45 += 2 ;
V_46 -= 2 ;
V_43 -> V_46 += 2 ;
}
if ( V_46 ) {
int V_48 ;
V_48 = F_15 ( V_20 , V_45 >> 1 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = ( V_48 & 0xff00 ) | * V_44 ++ ;
V_6 = F_24 ( V_20 , V_45 >> 1 , V_48 ) ;
if ( V_6 < 0 )
return V_6 ;
V_45 ++ ;
V_46 -- ;
V_43 -> V_46 ++ ;
}
return 0 ;
}
