static const struct V_1 * F_1 ( const struct V_1 * V_2 ,
unsigned int V_3 ,
const char * V_4 ,
unsigned int V_5 )
{
unsigned int V_6 ;
const struct V_1 * V_7 ;
for ( V_6 = 0 ; V_6 < V_3 ; V_6 ++ ) {
V_7 = V_2 + V_6 ;
if ( strlen ( V_7 -> V_8 ) != V_5 ) continue;
if ( ! memcmp ( V_4 , V_7 -> V_8 , V_5 ) ) return V_7 ;
}
return NULL ;
}
int F_2 ( T_1 * V_9 , const char * V_4 ,
unsigned int V_5 )
{
T_1 V_10 = 0 ;
T_1 V_11 = 0 ;
T_1 V_12 ;
int V_13 = 0 ;
unsigned int V_14 ;
char V_15 ;
const struct V_1 * V_16 ;
while ( V_5 ) {
if ( ! V_13 ) {
V_14 = 0 ;
while ( ( V_14 < V_5 ) && ( V_4 [ V_14 ] != '-' ) ) V_14 ++ ;
if ( V_14 >= V_5 ) return 0 ;
V_16 = F_1 ( V_17 , F_3 ( V_17 ) ,
V_4 , V_14 ) ;
if ( ! V_16 ) return 0 ;
V_14 ++ ;
V_4 += V_14 ;
V_5 -= V_14 ;
V_13 = ! 0 ;
V_11 = V_16 -> V_10 ;
continue;
}
V_14 = 0 ;
while ( V_14 < V_5 ) {
V_15 = V_4 [ V_14 ] ;
if ( V_15 == ';' ) {
V_13 = 0 ;
break;
}
if ( V_15 == '/' ) break;
V_14 ++ ;
}
V_16 = F_1 ( V_18 , F_3 ( V_18 ) ,
V_4 , V_14 ) ;
if ( ! V_16 ) return 0 ;
V_12 = V_16 -> V_10 & V_11 ;
if ( ! V_12 ) return 0 ;
V_10 |= V_12 ;
if ( V_14 < V_5 ) V_14 ++ ;
V_4 += V_14 ;
V_5 -= V_14 ;
}
if ( V_9 ) * V_9 = V_10 ;
return ! 0 ;
}
unsigned int F_4 ( char * V_4 , unsigned int V_5 ,
T_1 V_10 )
{
unsigned int V_19 , V_20 ;
const struct V_1 * V_21 , * V_22 ;
int V_23 , V_24 ;
unsigned int V_25 , V_26 ;
V_24 = 0 ;
V_25 = 0 ;
for ( V_19 = 0 ; V_19 < F_3 ( V_17 ) ; V_19 ++ ) {
V_22 = V_17 + V_19 ;
V_23 = 0 ;
for ( V_20 = 0 ; V_20 < F_3 ( V_18 ) ; V_20 ++ ) {
V_21 = V_18 + V_20 ;
if ( ! ( V_22 -> V_10 & V_21 -> V_10 & V_10 ) ) continue;
if ( ! V_23 ) {
if ( V_24 ) {
V_26 = F_5 ( V_4 , V_5 , L_1 ) ;
V_25 += V_26 ;
V_5 -= V_26 ;
V_4 += V_26 ;
}
V_24 = ! 0 ;
V_26 = F_5 ( V_4 , V_5 ,
L_2 , V_22 -> V_8 ) ;
V_23 = ! 0 ;
} else {
V_26 = F_5 ( V_4 , V_5 , L_3 ) ;
}
V_25 += V_26 ;
V_5 -= V_26 ;
V_4 += V_26 ;
V_26 = F_5 ( V_4 , V_5 ,
V_21 -> V_8 ) ;
V_25 += V_26 ;
V_5 -= V_26 ;
V_4 += V_26 ;
}
}
return V_25 ;
}
static struct V_27 * F_6 ( T_1 V_10 )
{
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < F_3 ( V_28 ) ; V_6 ++ ) {
if ( V_28 [ V_6 ] . V_10 & V_10 ) {
return V_28 + V_6 ;
}
}
return NULL ;
}
static int F_7 ( struct V_27 * V_29 , T_1 V_10 )
{
struct V_27 * V_30 ;
int V_6 ;
unsigned int V_31 ;
V_30 = F_6 ( V_10 ) ;
if ( ! V_30 ) return 0 ;
V_6 = V_29 -> V_32 ;
memcpy ( V_29 , V_30 , sizeof( * V_30 ) ) ;
V_29 -> V_32 = V_6 ;
V_29 -> V_10 = V_10 ;
V_31 = F_4 ( V_29 -> V_8 , sizeof( V_29 -> V_8 ) - 1 , V_10 ) ;
V_29 -> V_8 [ V_31 ] = 0 ;
F_8 ( V_33 , L_4 ,
V_29 -> V_32 , V_29 -> V_8 ) ;
return ! 0 ;
}
struct V_27 * F_9 ( unsigned int * V_34 ,
T_1 V_10 )
{
unsigned int V_35 = 0 ;
unsigned int V_6 , V_31 , V_20 ;
T_1 V_36 , V_11 , V_37 ;
struct V_27 * V_38 ;
if ( V_39 & V_33 ) {
char V_40 [ 100 ] ;
V_31 = F_4 ( V_40 , sizeof( V_40 ) , V_10 ) ;
F_8 (
V_33 , L_5 ,
( int ) V_10 , V_31 , V_40 ) ;
}
* V_34 = 0 ;
V_35 = 0 ;
V_37 = 0 ;
for ( V_36 = 1 , V_11 = V_10 ; V_11 ; V_36 <<= 1 ) {
if ( ! ( V_36 & V_11 ) ) continue;
V_11 &= ~ V_36 ;
if ( F_6 ( V_36 ) ) {
V_35 ++ ;
continue;
}
V_37 |= V_36 ;
}
for ( V_20 = 0 ; V_20 < F_3 ( V_41 ) ; V_20 ++ ) {
if ( ( V_10 & V_41 [ V_20 ] ) == V_41 [ V_20 ] ) V_35 ++ ;
}
V_37 &= ~ V_42 ;
if ( V_37 ) {
char V_40 [ 100 ] ;
V_31 = F_4 ( V_40 , sizeof( V_40 ) , V_37 ) ;
F_8 (
V_43 ,
L_6 ,
V_31 , V_40 ) ;
}
F_8 ( V_33 , L_7 ,
V_35 ) ;
if ( ! V_35 ) return NULL ;
V_38 = F_10 ( sizeof( struct V_27 ) * V_35 ,
V_44 ) ;
if ( ! V_38 )
return NULL ;
for ( V_6 = 0 ; V_6 < V_35 ; V_6 ++ )
V_38 [ V_6 ] . V_32 = V_6 ;
V_6 = 0 ;
for ( V_20 = 0 ; ( V_20 < F_3 ( V_41 ) ) && ( V_6 < V_35 ) ;
V_20 ++ ) {
if ( ! ( V_10 & V_41 [ V_20 ] ) ) continue;
if ( F_7 ( V_38 + V_6 , V_41 [ V_20 ] ) ) V_6 ++ ;
}
for ( V_36 = 1 , V_11 = V_10 ; V_11 && ( V_6 < V_35 ) ; V_36 <<= 1 ) {
if ( ! ( V_36 & V_11 ) ) continue;
V_11 &= ~ V_36 ;
if ( ! F_7 ( V_38 + V_6 , V_36 ) ) continue;
V_6 ++ ;
}
* V_34 = V_35 ;
return V_38 ;
}
T_1 F_11 ( void )
{
return V_45 ;
}
