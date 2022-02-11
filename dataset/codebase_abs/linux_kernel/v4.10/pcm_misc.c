int F_1 ( T_1 V_1 )
{
int V_2 ;
if ( ( INT ) V_1 < 0 || ( INT ) V_1 > ( INT ) V_3 )
return - V_4 ;
if ( ( V_2 = V_5 [ ( INT ) V_1 ] . V_6 ) < 0 )
return - V_4 ;
return V_2 ;
}
int F_2 ( T_1 V_1 )
{
int V_2 ;
V_2 = F_1 ( V_1 ) ;
if ( V_2 < 0 )
return V_2 ;
return ! V_2 ;
}
int F_3 ( T_1 V_1 )
{
return F_1 ( V_1 ) >= 0 ;
}
int F_4 ( T_1 V_1 )
{
int V_2 ;
if ( ( INT ) V_1 < 0 || ( INT ) V_1 > ( INT ) V_3 )
return - V_4 ;
if ( ( V_2 = V_5 [ ( INT ) V_1 ] . V_7 ) < 0 )
return - V_4 ;
return V_2 ;
}
int F_5 ( T_1 V_1 )
{
int V_2 ;
V_2 = F_4 ( V_1 ) ;
if ( V_2 < 0 )
return V_2 ;
return ! V_2 ;
}
int F_6 ( T_1 V_1 )
{
int V_2 ;
if ( ( INT ) V_1 < 0 || ( INT ) V_1 > ( INT ) V_3 )
return - V_4 ;
if ( ( V_2 = V_5 [ ( INT ) V_1 ] . V_8 ) == 0 )
return - V_4 ;
return V_2 ;
}
int F_7 ( T_1 V_1 )
{
int V_2 ;
if ( ( INT ) V_1 < 0 || ( INT ) V_1 > ( INT ) V_3 )
return - V_4 ;
if ( ( V_2 = V_5 [ ( INT ) V_1 ] . V_9 ) == 0 )
return - V_4 ;
return V_2 ;
}
T_2 F_8 ( T_1 V_1 , T_3 V_10 )
{
int V_11 = F_7 ( V_1 ) ;
if ( V_11 < 0 )
return - V_4 ;
return V_10 * V_11 / 8 ;
}
const unsigned char * F_9 ( T_1 V_1 )
{
if ( ( INT ) V_1 < 0 || ( INT ) V_1 > ( INT ) V_3 )
return NULL ;
if ( ! V_5 [ ( INT ) V_1 ] . V_9 )
return NULL ;
return V_5 [ ( INT ) V_1 ] . V_12 ;
}
int F_10 ( T_1 V_1 , void * V_13 , unsigned int V_10 )
{
int V_8 ;
unsigned char * V_14 , * V_15 ;
if ( ( INT ) V_1 < 0 || ( INT ) V_1 > ( INT ) V_3 )
return - V_4 ;
if ( V_10 == 0 )
return 0 ;
V_8 = V_5 [ ( INT ) V_1 ] . V_9 ;
V_15 = V_5 [ ( INT ) V_1 ] . V_12 ;
if ( ! V_8 )
return - V_4 ;
if ( V_5 [ ( INT ) V_1 ] . V_6 == 1 || V_8 <= 8 ) {
unsigned int V_16 = V_10 * V_8 / 8 ;
memset ( V_13 , * V_15 , V_16 ) ;
return 0 ;
}
V_8 /= 8 ;
V_14 = V_13 ;
#if 0
while (samples--) {
memcpy(dst, pat, width);
dst += width;
}
#else
switch ( V_8 ) {
case 2 :
while ( V_10 -- ) {
memcpy ( V_14 , V_15 , 2 ) ;
V_14 += 2 ;
}
break;
case 3 :
while ( V_10 -- ) {
memcpy ( V_14 , V_15 , 3 ) ;
V_14 += 3 ;
}
break;
case 4 :
while ( V_10 -- ) {
memcpy ( V_14 , V_15 , 4 ) ;
V_14 += 4 ;
}
break;
case 8 :
while ( V_10 -- ) {
memcpy ( V_14 , V_15 , 8 ) ;
V_14 += 8 ;
}
break;
}
#endif
return 0 ;
}
int F_11 ( struct V_17 * V_18 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < ( int ) V_20 . V_21 ; V_19 ++ ) {
if ( V_18 -> V_22 . V_23 & ( 1 << V_19 ) ) {
V_18 -> V_22 . V_24 = V_20 . V_25 [ V_19 ] ;
break;
}
}
for ( V_19 = ( int ) V_20 . V_21 - 1 ; V_19 >= 0 ; V_19 -- ) {
if ( V_18 -> V_22 . V_23 & ( 1 << V_19 ) ) {
V_18 -> V_22 . V_26 = V_20 . V_25 [ V_19 ] ;
break;
}
}
return 0 ;
}
unsigned int F_12 ( unsigned int V_27 )
{
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_20 . V_21 ; V_19 ++ )
if ( V_20 . V_25 [ V_19 ] == V_27 )
return 1u << V_19 ;
return V_28 ;
}
unsigned int F_13 ( unsigned int V_29 )
{
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_20 . V_21 ; V_19 ++ )
if ( ( 1u << V_19 ) == V_29 )
return V_20 . V_25 [ V_19 ] ;
return 0 ;
}
static unsigned int F_14 ( unsigned int V_23 )
{
if ( V_23 & V_30 )
return V_30 ;
else if ( V_23 & V_28 )
return V_28 ;
return V_23 ;
}
unsigned int F_15 ( unsigned int V_31 ,
unsigned int V_32 )
{
V_31 = F_14 ( V_31 ) ;
V_32 = F_14 ( V_32 ) ;
if ( V_31 & V_30 )
return V_32 ;
else if ( V_32 & V_30 )
return V_31 ;
else if ( V_31 & V_28 )
return V_32 ;
else if ( V_32 & V_28 )
return V_31 ;
return V_31 & V_32 ;
}
unsigned int F_16 ( unsigned int V_24 ,
unsigned int V_26 )
{
unsigned int V_23 = 0 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_20 . V_21 ; V_19 ++ ) {
if ( V_20 . V_25 [ V_19 ] >= V_24
&& V_20 . V_25 [ V_19 ] <= V_26 )
V_23 |= 1 << V_19 ;
}
if ( ! V_23 )
V_23 = V_28 ;
return V_23 ;
}
