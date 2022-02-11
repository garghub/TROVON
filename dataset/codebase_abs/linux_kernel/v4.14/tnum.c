struct V_1 F_1 ( T_1 V_2 )
{
return F_2 ( V_2 , 0 ) ;
}
struct V_1 F_3 ( T_1 V_3 , T_1 V_4 )
{
T_1 V_5 = V_3 ^ V_4 , V_6 ;
T_2 V_7 = F_4 ( V_5 ) ;
if ( V_7 > 63 )
return V_8 ;
V_6 = ( 1ULL << V_7 ) - 1 ;
return F_2 ( V_3 & ~ V_6 , V_6 ) ;
}
struct V_1 F_5 ( struct V_1 V_9 , T_2 V_10 )
{
return F_2 ( V_9 . V_2 << V_10 , V_9 . V_11 << V_10 ) ;
}
struct V_1 F_6 ( struct V_1 V_9 , T_2 V_10 )
{
return F_2 ( V_9 . V_2 >> V_10 , V_9 . V_11 >> V_10 ) ;
}
struct V_1 F_7 ( struct V_1 V_9 , struct V_1 V_12 )
{
T_1 V_13 , V_14 , V_15 , V_5 , V_16 ;
V_13 = V_9 . V_11 + V_12 . V_11 ;
V_14 = V_9 . V_2 + V_12 . V_2 ;
V_15 = V_13 + V_14 ;
V_5 = V_15 ^ V_14 ;
V_16 = V_5 | V_9 . V_11 | V_12 . V_11 ;
return F_2 ( V_14 & ~ V_16 , V_16 ) ;
}
struct V_1 F_8 ( struct V_1 V_9 , struct V_1 V_12 )
{
T_1 V_17 , V_18 , V_19 , V_5 , V_16 ;
V_17 = V_9 . V_2 - V_12 . V_2 ;
V_18 = V_17 + V_9 . V_11 ;
V_19 = V_17 - V_12 . V_11 ;
V_5 = V_18 ^ V_19 ;
V_16 = V_5 | V_9 . V_11 | V_12 . V_11 ;
return F_2 ( V_17 & ~ V_16 , V_16 ) ;
}
struct V_1 F_9 ( struct V_1 V_9 , struct V_1 V_12 )
{
T_1 V_18 , V_19 , V_20 ;
V_18 = V_9 . V_2 | V_9 . V_11 ;
V_19 = V_12 . V_2 | V_12 . V_11 ;
V_20 = V_9 . V_2 & V_12 . V_2 ;
return F_2 ( V_20 , V_18 & V_19 & ~ V_20 ) ;
}
struct V_1 F_10 ( struct V_1 V_9 , struct V_1 V_12 )
{
T_1 V_20 , V_16 ;
V_20 = V_9 . V_2 | V_12 . V_2 ;
V_16 = V_9 . V_11 | V_12 . V_11 ;
return F_2 ( V_20 , V_16 & ~ V_20 ) ;
}
struct V_1 F_11 ( struct V_1 V_9 , struct V_1 V_12 )
{
T_1 V_20 , V_16 ;
V_20 = V_9 . V_2 ^ V_12 . V_2 ;
V_16 = V_9 . V_11 | V_12 . V_11 ;
return F_2 ( V_20 & ~ V_16 , V_16 ) ;
}
static struct V_1 F_12 ( struct V_1 V_21 , T_1 V_2 , T_1 V_11 )
{
while ( V_11 ) {
if ( V_11 & 1 )
V_21 = F_7 ( V_21 , F_2 ( 0 , V_2 ) ) ;
V_11 >>= 1 ;
V_2 <<= 1 ;
}
return V_21 ;
}
struct V_1 F_13 ( struct V_1 V_9 , struct V_1 V_12 )
{
struct V_1 V_21 ;
T_1 V_22 ;
V_22 = V_9 . V_2 * V_12 . V_2 ;
V_21 = F_12 ( F_2 ( V_22 , 0 ) , V_9 . V_11 , V_12 . V_11 | V_12 . V_2 ) ;
return F_12 ( V_21 , V_12 . V_11 , V_9 . V_2 ) ;
}
struct V_1 F_14 ( struct V_1 V_9 , struct V_1 V_12 )
{
T_1 V_20 , V_16 ;
V_20 = V_9 . V_2 | V_12 . V_2 ;
V_16 = V_9 . V_11 & V_12 . V_11 ;
return F_2 ( V_20 & ~ V_16 , V_16 ) ;
}
struct V_1 F_15 ( struct V_1 V_9 , T_2 V_23 )
{
V_9 . V_2 &= ( 1ULL << ( V_23 * 8 ) ) - 1 ;
V_9 . V_11 &= ( 1ULL << ( V_23 * 8 ) ) - 1 ;
return V_9 ;
}
bool F_16 ( struct V_1 V_9 , T_1 V_23 )
{
if ( ! V_23 )
return true ;
return ! ( ( V_9 . V_2 | V_9 . V_11 ) & ( V_23 - 1 ) ) ;
}
bool F_17 ( struct V_1 V_9 , struct V_1 V_12 )
{
if ( V_12 . V_11 & ~ V_9 . V_11 )
return false ;
V_12 . V_2 &= ~ V_9 . V_11 ;
return V_9 . V_2 == V_12 . V_2 ;
}
int F_18 ( char * V_24 , T_3 V_23 , struct V_1 V_9 )
{
return snprintf ( V_24 , V_23 , L_1 , V_9 . V_2 , V_9 . V_11 ) ;
}
int F_19 ( char * V_24 , T_3 V_23 , struct V_1 V_9 )
{
T_3 V_25 ;
for ( V_25 = 64 ; V_25 ; V_25 -- ) {
if ( V_25 < V_23 ) {
if ( V_9 . V_11 & 1 )
V_24 [ V_25 - 1 ] = 'x' ;
else if ( V_9 . V_2 & 1 )
V_24 [ V_25 - 1 ] = '1' ;
else
V_24 [ V_25 - 1 ] = '0' ;
}
V_9 . V_11 >>= 1 ;
V_9 . V_2 >>= 1 ;
}
V_24 [ V_3 ( V_23 - 1 , ( T_3 ) 64 ) ] = 0 ;
return 64 ;
}
