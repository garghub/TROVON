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
}
return NULL ;
}
static int F_5 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_6 ( V_11 ) ;
int V_6 ;
int V_14 ;
F_7 ( V_15 , 0x04 , 0x6000 ) ;
F_7 ( V_15 , 0x0a , 0x0148 ) ;
V_6 = F_8 ( V_11 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( F_9 ( F_4 ( 0 ) , 0x03 ) == 0x1710 )
F_7 ( V_15 , 0x1a , ( F_10 ( V_11 ) * 0x1111 ) ) ;
else
F_7 ( V_15 , 0x1a , ( F_10 ( V_11 ) * 0x1110 ) ) ;
F_7 ( V_15 , 0x1c , V_11 -> V_16 & 0x1f ) ;
F_7 ( V_17 , 0x02 , 0xffff ) ;
F_7 ( V_17 , 0x03 , 0xffff ) ;
F_7 ( V_17 , 0x05 , 0x00ff ) ;
for ( V_14 = 0 ; V_14 < 32 ; V_14 ++ ) {
int V_18 ;
V_18 = 0x1f ;
if ( V_14 != V_11 -> V_16 && V_14 < V_11 -> V_19 -> V_20 -> V_21 )
V_18 = V_11 -> V_20 -> V_22 [ V_14 ] & 0x1f ;
F_7 ( V_17 , 0x06 , 0x8000 | ( V_14 << 8 ) | V_18 ) ;
}
for ( V_14 = 0 ; V_14 < V_13 -> V_23 ; V_14 ++ )
F_7 ( V_17 , 0x07 , 0x8000 | ( V_14 << 12 ) | 0xff ) ;
for ( V_14 = 0 ; V_14 < 16 ; V_14 ++ )
F_7 ( V_17 , 0x08 , 0x8000 | ( V_14 << 11 ) ) ;
for ( V_14 = 0 ; V_14 < 6 ; V_14 ++ )
F_7 ( V_17 , 0x09 , 0x9000 | ( V_14 << 8 ) ) ;
F_7 ( V_17 , 0x0b , 0x9000 ) ;
for ( V_14 = 0 ; V_14 < 16 ; V_14 ++ )
F_7 ( V_17 , 0x0f , 0x8000 | ( V_14 << 8 ) ) ;
return 0 ;
}
static int F_11 ( struct V_10 * V_11 , int V_24 )
{
int V_25 = F_4 ( V_24 ) ;
T_1 V_26 ;
V_26 = F_9 ( V_25 , 0x01 ) ;
if ( F_12 ( V_11 , V_24 ) || V_11 -> V_27 & ( 1 << V_24 ) )
F_7 ( V_25 , 0x01 , V_26 | 0x003e ) ;
else
F_7 ( V_25 , 0x01 , V_26 | 0x0003 ) ;
F_7 ( V_25 , 0x02 , 0x0000 ) ;
V_26 = 0x0433 ;
if ( F_12 ( V_11 , V_24 ) ) {
if ( V_11 -> V_19 -> V_28 == V_29 )
V_26 |= 0x3300 ;
else
V_26 |= 0x0100 ;
}
if ( V_11 -> V_27 & ( 1 << V_24 ) )
V_26 |= 0x0100 ;
if ( V_24 == F_10 ( V_11 ) )
V_26 |= 0x000c ;
F_7 ( V_25 , 0x04 , V_26 ) ;
F_7 ( V_25 , 0x08 , 0x2080 ) ;
F_7 ( V_25 , 0x09 , 0x0001 ) ;
F_7 ( V_25 , 0x0a , 0x0000 ) ;
F_7 ( V_25 , 0x0b , 1 << V_24 ) ;
F_7 ( V_25 , 0x0c , 0x0000 ) ;
F_7 ( V_25 , 0x0d , 0x0000 ) ;
F_7 ( V_25 , 0x0f , V_30 ) ;
F_7 ( V_25 , 0x18 , 0x3210 ) ;
F_7 ( V_25 , 0x19 , 0x7654 ) ;
return F_13 ( V_11 , V_24 ) ;
}
static int F_14 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_6 ( V_11 ) ;
int V_14 ;
int V_6 ;
V_6 = F_15 ( V_11 ) ;
if ( V_6 < 0 )
return V_6 ;
V_13 -> V_23 = 7 ;
V_6 = F_16 ( V_11 , true ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_5 ( V_11 ) ;
if ( V_6 < 0 )
return V_6 ;
for ( V_14 = 0 ; V_14 < V_13 -> V_23 ; V_14 ++ ) {
if ( ! ( F_12 ( V_11 , V_14 ) || V_11 -> V_31 & ( 1 << V_14 ) ) )
continue;
V_6 = F_11 ( V_11 , V_14 ) ;
if ( V_6 < 0 )
return V_6 ;
}
return 0 ;
}
static int F_17 ( struct V_10 * V_11 , int V_32 ,
struct V_33 * V_34 )
{
struct V_12 * V_13 = F_6 ( V_11 ) ;
if ( V_13 -> V_35 == V_9 )
return F_18 ( V_11 , V_32 , V_34 ) ;
return - V_36 ;
}
static int F_19 ( struct V_10 * V_11 , int V_32 ,
struct V_37 * V_38 , struct V_33 * V_34 )
{
struct V_12 * V_13 = F_6 ( V_11 ) ;
if ( V_13 -> V_35 == V_9 )
return F_20 ( V_11 , V_32 , V_38 , V_34 ) ;
return - V_36 ;
}
