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
F_12 ( T_2 * V_15 , const struct V_5 * V_8 ,
const struct V_7 * V_7 , const void * V_16 )
{
const struct V_5 * V_5 ;
V_5 = F_10 ( V_8 , F_8 ( V_7 ) , V_16 ) ;
if ( ! V_5 )
return 0 ;
if ( F_9 ( V_7 ) != F_7 ( V_5 ) )
return - V_17 ;
V_15 -> V_18 -> V_19 ( V_15 , V_7 -> V_14 , F_6 ( V_5 ) , F_9 ( V_7 ) ) ;
return 0 ;
}
int F_13 ( T_2 * V_15 ,
const char * V_8 ,
const void * V_16 ,
const T_3 * V_20 ,
const void * V_21 )
{
int V_22 ;
const struct V_7 * V_7 ;
const struct V_5 * V_5 ;
V_5 = ( const struct V_5 * ) V_8 ;
V_21 -= sizeof( struct V_7 ) ;
V_7 = ( const struct V_7 * ) ( V_20 + 2 ) ;
while ( ( ( void * ) V_7 <= V_21 ) &&
( F_8 ( V_7 ) != V_11 ) ) {
V_22 = F_12 ( V_15 , V_5 , V_7 , V_16 ) ;
if ( V_22 )
return V_22 ;
V_7 = ( const struct V_7 * ) & V_7 -> V_14 [ F_9 ( V_7 ) ] ;
}
return 0 ;
}
T_4
F_14 ( const char * V_23 , const void * V_10 )
{
const struct V_1 * V_2 = ( const struct V_1 * ) V_23 ;
int V_24 = 0 ;
int V_4 ;
V_10 -= sizeof( * V_2 ) ;
while ( ( ( void * ) V_2 <= V_10 ) &&
( F_1 ( V_2 ) != V_25 ) ) {
V_4 = F_3 ( V_2 ) ;
V_24 += sizeof( * V_2 ) + V_4 ;
V_2 = (struct V_1 * ) & V_2 -> V_14 [ V_4 ] ;
}
return V_24 ;
}
int F_15 ( T_2 * V_15 , const char * V_23 , const void * V_10 )
{
const struct V_1 * V_2 ;
T_1 V_26 ;
T_1 V_27 ;
int V_28 = 0 ;
V_2 = ( const struct V_1 * ) V_23 ;
if ( ( void * ) V_2 > ( V_10 - sizeof( * V_2 ) ) )
return - V_29 ;
V_26 = F_1 ( V_2 ) ;
V_27 = F_3 ( V_2 ) ;
while ( ( V_26 != V_25 ) &&
( ( ( void * ) V_2 + V_27 ) <= V_10 ) ) {
F_16 ( V_30 L_1
L_2 , V_27 , V_26 ) ;
V_28 = V_15 -> V_18 -> V_19 ( V_15 , V_2 -> V_14 , V_26 , V_27 ) ;
if ( V_28 )
break;
V_2 = ( const struct V_1 * ) & V_2 -> V_14 [ V_27 ] ;
if ( ( void * ) V_2 > ( V_10 - sizeof( * V_2 ) ) )
return - V_29 ;
V_26 = F_1 ( V_2 ) ;
V_27 = F_3 ( V_2 ) ;
}
return V_28 ;
}
int F_17 ( T_2 * V_15 ,
const char * V_8 ,
const void * V_16 ,
const T_3 * V_20 ,
const void * V_21 )
{
const struct V_5 * V_5 = ( const struct V_5 * ) V_8 ;
const struct V_7 * V_13 = ( const struct V_7 * ) & V_20 [ 2 ] ;
const struct V_7 * V_7 ;
const struct V_7 * V_31 = NULL ;
const struct V_7 * V_32 ;
int V_9 ;
V_16 -= sizeof( struct V_5 ) ;
while ( ( ( void * ) V_5 <= V_16 ) &&
( F_5 ( V_5 ) != V_11 ) ) {
if ( F_7 ( V_5 ) < 2 )
break;
V_9 = F_5 ( V_5 ) ;
V_7 = F_11 ( V_13 , V_9 , V_21 ) ;
if ( V_7 )
F_16 ( V_30 L_3 ,
V_9 , V_7 ) ;
switch ( V_9 ) {
case 0x110 :
case 0x120 :
V_32 = F_11 ( V_13 , V_9 + 1 ,
V_21 ) ;
V_31 = NULL ;
if ( V_32 ) {
V_7 = V_32 ;
F_16 ( V_30
L_4 ,
V_9 + 1 , V_7 ) ;
}
break;
case 0x5 :
V_31 = (struct V_7 * ) & F_18 ( 0x0005 ) ;
break;
case 0x108 :
V_31 = (struct V_7 * ) & F_18 ( 0x0108 ) ;
break;
case 0x109 :
V_31 = (struct V_7 * ) & F_18 ( 0x0109 ) ;
break;
case 0x150 :
V_31 = (struct V_7 * ) & F_18 ( 0x0150 ) ;
break;
case 0x160 :
V_31 = (struct V_7 * ) & F_18 ( 0x0160 ) ;
break;
case 0x161 :
V_31 = (struct V_7 * ) & F_18 ( 0x0161 ) ;
break;
default:
V_31 = NULL ;
break;
}
if ( ! V_7 && V_31 ) {
V_7 = V_31 ;
F_16 ( V_30 L_5 ,
V_9 , V_7 ) ;
}
if ( V_7 ) {
if ( ( F_9 ( V_7 ) == F_7 ( V_5 ) ) &&
( ( void * ) V_7 -> V_14 + F_9 ( V_7 ) < V_21 ) ) {
V_15 -> V_18 -> V_19 ( V_15 , V_7 -> V_14 , F_6 ( V_5 ) ,
F_9 ( V_7 ) ) ;
}
}
V_5 ++ ;
}
return 0 ;
}
