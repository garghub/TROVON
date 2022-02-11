static inline T_1
F_1 ( const struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 ) ;
}
static inline T_1
F_3 ( const struct V_1 * V_2 )
{
return F_4 ( V_2 -> V_4 ) ;
}
static inline T_1
F_5 ( const struct V_5 * V_5 )
{
return F_2 ( V_5 -> V_6 ) ;
}
static inline T_1
F_6 ( const struct V_5 * V_5 )
{
return F_2 ( V_5 -> V_3 ) ;
}
static inline T_1
F_7 ( const struct V_5 * V_5 )
{
return F_2 ( V_5 -> V_4 ) ;
}
static inline T_1
F_8 ( const struct V_7 * V_7 )
{
return F_4 ( V_7 -> V_6 ) ;
}
static inline T_1
F_9 ( const struct V_7 * V_7 )
{
return 2 * ( F_4 ( V_7 -> V_4 ) - 1 ) ;
}
static const struct V_5 *
F_10 ( const struct V_5 * V_8 , T_1 V_9 , const void * V_10 )
{
const struct V_5 * V_5 = V_8 ;
V_10 -= sizeof( struct V_5 ) ;
while ( ( ( void * ) V_5 <= V_10 ) &&
( F_5 ( V_5 ) != V_11 ) ) {
if ( F_7 ( V_5 ) < 2 )
return NULL ;
if ( F_5 ( V_5 ) == V_9 )
return V_5 ;
V_5 = (struct V_5 * ) V_5 -> V_12 ;
}
return NULL ;
}
static const struct V_7 *
F_11 ( const struct V_7 * V_13 , T_1 V_9 , const void * V_10 )
{
const struct V_7 * V_7 = V_13 ;
V_10 -= sizeof( struct V_7 ) ;
while ( ( ( void * ) V_7 <= V_10 ) &&
( F_8 ( V_7 ) != V_11 ) ) {
if ( F_8 ( V_7 ) == V_9 )
return V_7 ;
V_7 = (struct V_7 * ) & V_7 -> V_14 [ F_9 ( V_7 ) ] ;
}
return NULL ;
}
static int
F_12 ( struct V_15 * V_16 , const struct V_5 * V_8 ,
const struct V_7 * V_7 , const void * V_17 )
{
const struct V_5 * V_5 ;
V_5 = F_10 ( V_8 , F_8 ( V_7 ) , V_17 ) ;
if ( ! V_5 )
return 0 ;
if ( F_9 ( V_7 ) != F_7 ( V_5 ) )
return - V_18 ;
V_16 -> V_19 -> V_20 ( V_16 , V_7 -> V_14 , F_6 ( V_5 ) , F_9 ( V_7 ) ) ;
return 0 ;
}
int F_13 ( struct V_15 * V_16 ,
const char * V_8 ,
const void * V_17 ,
const T_2 * V_21 ,
const void * V_22 )
{
int V_23 ;
const struct V_7 * V_7 ;
const struct V_5 * V_5 ;
V_5 = ( const struct V_5 * ) V_8 ;
V_22 -= sizeof( struct V_7 ) ;
V_7 = ( const struct V_7 * ) ( V_21 + 2 ) ;
while ( ( ( void * ) V_7 <= V_22 ) &&
( F_8 ( V_7 ) != V_11 ) ) {
V_23 = F_12 ( V_16 , V_5 , V_7 , V_17 ) ;
if ( V_23 )
return V_23 ;
V_7 = ( const struct V_7 * ) & V_7 -> V_14 [ F_9 ( V_7 ) ] ;
}
return 0 ;
}
T_3
F_14 ( const char * V_24 , const void * V_10 )
{
const struct V_1 * V_2 = ( const struct V_1 * ) V_24 ;
int V_25 = 0 ;
int V_4 ;
V_10 -= sizeof( * V_2 ) ;
while ( ( ( void * ) V_2 <= V_10 ) &&
( F_1 ( V_2 ) != V_26 ) ) {
V_4 = F_3 ( V_2 ) ;
V_25 += sizeof( * V_2 ) + V_4 ;
V_2 = (struct V_1 * ) & V_2 -> V_14 [ V_4 ] ;
}
return V_25 ;
}
int F_15 ( struct V_15 * V_16 , const char * V_24 , const void * V_10 )
{
const struct V_1 * V_2 ;
T_1 V_27 ;
T_1 V_28 ;
int V_29 = 0 ;
V_2 = ( const struct V_1 * ) V_24 ;
if ( ( void * ) V_2 > ( V_10 - sizeof( * V_2 ) ) )
return - V_30 ;
V_27 = F_1 ( V_2 ) ;
V_28 = F_3 ( V_2 ) ;
while ( ( V_27 != V_26 ) &&
( ( ( void * ) V_2 + V_28 ) <= V_10 ) ) {
F_16 ( V_31 L_1
L_2 , V_28 , V_27 ) ;
V_29 = V_16 -> V_19 -> V_20 ( V_16 , V_2 -> V_14 , V_27 , V_28 ) ;
if ( V_29 )
break;
V_2 = ( const struct V_1 * ) & V_2 -> V_14 [ V_28 ] ;
if ( ( void * ) V_2 > ( V_10 - sizeof( * V_2 ) ) )
return - V_30 ;
V_27 = F_1 ( V_2 ) ;
V_28 = F_3 ( V_2 ) ;
}
return V_29 ;
}
int F_17 ( struct V_15 * V_16 ,
const char * V_8 ,
const void * V_17 ,
const T_2 * V_21 ,
const void * V_22 )
{
const struct V_5 * V_5 = ( const struct V_5 * ) V_8 ;
const struct V_7 * V_13 = ( const struct V_7 * ) & V_21 [ 2 ] ;
const struct V_7 * V_7 ;
const struct V_7 * V_32 = NULL ;
const struct V_7 * V_33 ;
int V_9 ;
V_17 -= sizeof( struct V_5 ) ;
while ( ( ( void * ) V_5 <= V_17 ) &&
( F_5 ( V_5 ) != V_11 ) ) {
if ( F_7 ( V_5 ) < 2 )
break;
V_9 = F_5 ( V_5 ) ;
V_7 = F_11 ( V_13 , V_9 , V_22 ) ;
if ( V_7 )
F_16 ( V_31 L_3 ,
V_9 , V_7 ) ;
switch ( V_9 ) {
case 0x110 :
case 0x120 :
V_33 = F_11 ( V_13 , V_9 + 1 ,
V_22 ) ;
V_32 = NULL ;
if ( V_33 ) {
V_7 = V_33 ;
F_16 ( V_31
L_4 ,
V_9 + 1 , V_7 ) ;
}
break;
case 0x5 :
V_32 = (struct V_7 * ) & F_18 ( 0x0005 ) ;
break;
case 0x108 :
V_32 = (struct V_7 * ) & F_18 ( 0x0108 ) ;
break;
case 0x109 :
V_32 = (struct V_7 * ) & F_18 ( 0x0109 ) ;
break;
case 0x150 :
V_32 = (struct V_7 * ) & F_18 ( 0x0150 ) ;
break;
case 0x160 :
V_32 = (struct V_7 * ) & F_18 ( 0x0160 ) ;
break;
case 0x161 :
V_32 = (struct V_7 * ) & F_18 ( 0x0161 ) ;
break;
default:
V_32 = NULL ;
break;
}
if ( ! V_7 && V_32 ) {
V_7 = V_32 ;
F_16 ( V_31 L_5 ,
V_9 , V_7 ) ;
}
if ( V_7 ) {
if ( ( F_9 ( V_7 ) == F_7 ( V_5 ) ) &&
( ( void * ) V_7 -> V_14 + F_9 ( V_7 ) < V_22 ) ) {
V_16 -> V_19 -> V_20 ( V_16 , V_7 -> V_14 , F_6 ( V_5 ) ,
F_9 ( V_7 ) ) ;
}
}
V_5 ++ ;
}
return 0 ;
}
