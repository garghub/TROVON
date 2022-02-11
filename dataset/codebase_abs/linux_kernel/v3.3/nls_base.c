int F_1 ( const T_1 * V_1 , int V_2 , T_2 * V_3 )
{
unsigned long V_4 ;
int V_5 , V_6 , V_7 ;
const struct V_8 * V_9 ;
V_7 = 0 ;
V_5 = * V_1 ;
V_4 = V_5 ;
for ( V_9 = V_8 ; V_9 -> V_10 ; V_9 ++ ) {
V_7 ++ ;
if ( ( V_5 & V_9 -> V_10 ) == V_9 -> V_11 ) {
V_4 &= V_9 -> V_12 ;
if ( V_4 < V_9 -> V_13 || V_4 > V_14 ||
( V_4 & V_15 ) == V_16 )
return - 1 ;
* V_3 = ( T_2 ) V_4 ;
return V_7 ;
}
if ( V_2 <= V_7 )
return - 1 ;
V_1 ++ ;
V_6 = ( * V_1 ^ 0x80 ) & 0xFF ;
if ( V_6 & 0xC0 )
return - 1 ;
V_4 = ( V_4 << 6 ) | V_6 ;
}
return - 1 ;
}
int F_2 ( T_2 V_17 , T_1 * V_1 , int V_18 )
{
unsigned long V_4 ;
int V_6 , V_7 ;
const struct V_8 * V_9 ;
if ( ! V_1 )
return 0 ;
V_4 = V_17 ;
if ( V_4 > V_14 || ( V_4 & V_15 ) == V_16 )
return - 1 ;
V_7 = 0 ;
for ( V_9 = V_8 ; V_9 -> V_10 && V_18 ; V_9 ++ , V_18 -- ) {
V_7 ++ ;
if ( V_4 <= V_9 -> V_12 ) {
V_6 = V_9 -> V_19 ;
* V_1 = ( T_1 ) ( V_9 -> V_11 | ( V_4 >> V_6 ) ) ;
while ( V_6 > 0 ) {
V_6 -= 6 ;
V_1 ++ ;
* V_1 = ( T_1 ) ( 0x80 | ( ( V_4 >> V_6 ) & 0x3F ) ) ;
}
return V_7 ;
}
}
return - 1 ;
}
static inline void F_3 ( T_3 * V_1 , unsigned V_6 , enum V_20 V_21 )
{
switch ( V_21 ) {
default:
* V_1 = ( T_3 ) V_6 ;
break;
case V_22 :
* V_1 = F_4 ( V_6 ) ;
break;
case V_23 :
* V_1 = F_5 ( V_6 ) ;
break;
}
}
int F_6 ( const T_1 * V_1 , int V_2 , enum V_20 V_21 ,
T_3 * V_24 , int V_18 )
{
T_4 * V_25 ;
int V_26 ;
T_2 V_17 ;
V_25 = V_24 ;
while ( V_2 > 0 && V_18 > 0 && * V_1 ) {
if ( * V_1 & 0x80 ) {
V_26 = F_1 ( V_1 , V_2 , & V_17 ) ;
if ( V_26 < 0 )
return - V_27 ;
V_1 += V_26 ;
V_2 -= V_26 ;
if ( V_17 >= V_28 ) {
if ( V_18 < 2 )
break;
V_17 -= V_28 ;
F_3 ( V_25 ++ , V_16 |
( ( V_17 >> 10 ) & V_29 ) ,
V_21 ) ;
F_3 ( V_25 ++ , V_16 |
V_30 |
( V_17 & V_29 ) ,
V_21 ) ;
V_18 -= 2 ;
} else {
F_3 ( V_25 ++ , V_17 , V_21 ) ;
V_18 -- ;
}
} else {
F_3 ( V_25 ++ , * V_1 ++ , V_21 ) ;
V_2 -- ;
V_18 -- ;
}
}
return V_25 - V_24 ;
}
static inline unsigned long F_7 ( unsigned V_6 , enum V_20 V_21 )
{
switch ( V_21 ) {
default:
return V_6 ;
case V_22 :
return F_8 ( V_6 ) ;
case V_23 :
return F_9 ( V_6 ) ;
}
}
int F_10 ( const T_3 * V_24 , int V_2 , enum V_20 V_21 ,
T_1 * V_1 , int V_18 )
{
T_1 * V_25 ;
int V_26 ;
unsigned long V_17 , V_31 ;
V_25 = V_1 ;
while ( V_2 > 0 && V_18 > 0 ) {
V_17 = F_7 ( * V_24 , V_21 ) ;
if ( ! V_17 )
break;
V_24 ++ ;
V_2 -- ;
if ( V_17 > 0x7f ) {
if ( ( V_17 & V_15 ) == V_16 ) {
if ( V_17 & V_30 ) {
continue;
}
if ( V_2 <= 0 )
break;
V_31 = F_7 ( * V_24 , V_21 ) ;
if ( ( V_31 & V_15 ) != V_16 ||
! ( V_31 & V_30 ) ) {
continue;
}
V_17 = V_28 + ( ( V_17 & V_29 ) << 10 )
+ ( V_31 & V_29 ) ;
V_24 ++ ;
V_2 -- ;
}
V_26 = F_2 ( V_17 , V_25 , V_18 ) ;
if ( V_26 == - 1 ) {
} else {
V_25 += V_26 ;
V_18 -= V_26 ;
}
} else {
* V_25 ++ = ( T_1 ) V_17 ;
V_18 -- ;
}
}
return V_25 - V_1 ;
}
int F_11 ( struct V_32 * V_33 )
{
struct V_32 * * V_34 = & V_35 ;
if ( V_33 -> V_36 )
return - V_37 ;
F_12 ( & V_38 ) ;
while ( * V_34 ) {
if ( V_33 == * V_34 ) {
F_13 ( & V_38 ) ;
return - V_37 ;
}
V_34 = & ( * V_34 ) -> V_36 ;
}
V_33 -> V_36 = V_35 ;
V_35 = V_33 ;
F_13 ( & V_38 ) ;
return 0 ;
}
int F_14 ( struct V_32 * V_33 )
{
struct V_32 * * V_34 = & V_35 ;
F_12 ( & V_38 ) ;
while ( * V_34 ) {
if ( V_33 == * V_34 ) {
* V_34 = V_33 -> V_36 ;
F_13 ( & V_38 ) ;
return 0 ;
}
V_34 = & ( * V_34 ) -> V_36 ;
}
F_13 ( & V_38 ) ;
return - V_27 ;
}
static struct V_32 * F_15 ( char * V_39 )
{
struct V_32 * V_33 ;
F_12 ( & V_38 ) ;
for ( V_33 = V_35 ; V_33 ; V_33 = V_33 -> V_36 ) {
if ( ! strcmp ( V_33 -> V_39 , V_39 ) )
break;
if ( V_33 -> V_40 && ! strcmp ( V_33 -> V_40 , V_39 ) )
break;
}
if ( V_33 && ! F_16 ( V_33 -> V_41 ) )
V_33 = NULL ;
F_13 ( & V_38 ) ;
return V_33 ;
}
struct V_32 * F_17 ( char * V_39 )
{
return F_18 ( F_15 ( V_39 ) , L_1 , V_39 ) ;
}
void F_19 ( struct V_32 * V_33 )
{
if ( V_33 )
F_20 ( V_33 -> V_41 ) ;
}
static int F_21 ( T_3 V_42 , unsigned char * V_43 , int V_44 )
{
const unsigned char * V_45 ;
unsigned char V_46 = V_42 & 0x00ff ;
unsigned char V_47 = ( V_42 & 0xff00 ) >> 8 ;
if ( V_44 <= 0 )
return - V_48 ;
V_45 = V_49 [ V_47 ] ;
if ( V_45 && V_45 [ V_46 ] )
V_43 [ 0 ] = V_45 [ V_46 ] ;
else
return - V_27 ;
return 1 ;
}
static int F_22 ( const unsigned char * V_50 , int V_44 , T_3 * V_42 )
{
* V_42 = V_51 [ * V_50 ] ;
if ( * V_42 == 0x0000 )
return - V_27 ;
return 1 ;
}
struct V_32 * F_23 ( void )
{
struct V_32 * V_52 ;
V_52 = F_17 ( V_53 ) ;
if ( V_52 != NULL )
return V_52 ;
else
return & V_54 ;
}
