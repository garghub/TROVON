static T_1 F_1 ( void * V_1 , T_1 V_2 , struct V_3 * V_4 )
{
T_1 V_5 , V_6 , V_7 , V_8 ;
const struct V_9 * V_10 ;
char T_2 * V_11 ;
if ( F_2 ( V_2 > V_4 -> V_12 ) )
V_2 = V_4 -> V_12 ;
if ( F_2 ( ! V_2 ) )
return 0 ;
V_8 = V_2 ;
V_10 = V_4 -> V_10 ;
V_5 = V_4 -> V_13 ;
V_11 = V_10 -> V_14 + V_5 ;
V_6 = F_3 ( V_2 , V_10 -> V_15 - V_5 ) ;
V_7 = F_4 ( V_11 , V_1 , V_6 ) ;
V_6 -= V_7 ;
V_5 += V_6 ;
V_1 += V_6 ;
V_2 -= V_6 ;
while ( F_2 ( ! V_7 && V_2 ) ) {
V_10 ++ ;
V_11 = V_10 -> V_14 ;
V_6 = F_3 ( V_2 , V_10 -> V_15 ) ;
V_7 = F_4 ( V_11 , V_1 , V_6 ) ;
V_6 -= V_7 ;
V_5 = V_6 ;
V_1 += V_6 ;
V_2 -= V_6 ;
}
if ( V_5 == V_10 -> V_15 ) {
V_10 ++ ;
V_5 = 0 ;
}
V_4 -> V_12 -= V_8 - V_2 ;
V_4 -> V_16 -= V_10 - V_4 -> V_10 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_13 = V_5 ;
return V_8 - V_2 ;
}
static T_1 F_5 ( void * V_17 , T_1 V_2 , struct V_3 * V_4 )
{
T_1 V_5 , V_6 , V_7 , V_8 ;
const struct V_9 * V_10 ;
char T_2 * V_11 ;
if ( F_2 ( V_2 > V_4 -> V_12 ) )
V_2 = V_4 -> V_12 ;
if ( F_2 ( ! V_2 ) )
return 0 ;
V_8 = V_2 ;
V_10 = V_4 -> V_10 ;
V_5 = V_4 -> V_13 ;
V_11 = V_10 -> V_14 + V_5 ;
V_6 = F_3 ( V_2 , V_10 -> V_15 - V_5 ) ;
V_7 = F_6 ( V_17 , V_11 , V_6 ) ;
V_6 -= V_7 ;
V_5 += V_6 ;
V_17 += V_6 ;
V_2 -= V_6 ;
while ( F_2 ( ! V_7 && V_2 ) ) {
V_10 ++ ;
V_11 = V_10 -> V_14 ;
V_6 = F_3 ( V_2 , V_10 -> V_15 ) ;
V_7 = F_6 ( V_17 , V_11 , V_6 ) ;
V_6 -= V_7 ;
V_5 = V_6 ;
V_17 += V_6 ;
V_2 -= V_6 ;
}
if ( V_5 == V_10 -> V_15 ) {
V_10 ++ ;
V_5 = 0 ;
}
V_4 -> V_12 -= V_8 - V_2 ;
V_4 -> V_16 -= V_10 - V_4 -> V_10 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_13 = V_5 ;
return V_8 - V_2 ;
}
static T_1 F_7 ( struct V_18 * V_18 , T_1 V_19 , T_1 V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 , V_6 , V_7 , V_8 ;
const struct V_9 * V_10 ;
char T_2 * V_11 ;
void * V_20 , * V_1 ;
if ( F_2 ( V_2 > V_4 -> V_12 ) )
V_2 = V_4 -> V_12 ;
if ( F_2 ( ! V_2 ) )
return 0 ;
V_8 = V_2 ;
V_10 = V_4 -> V_10 ;
V_5 = V_4 -> V_13 ;
V_11 = V_10 -> V_14 + V_5 ;
V_6 = F_3 ( V_2 , V_10 -> V_15 - V_5 ) ;
if ( ! F_8 ( V_11 , V_6 ) ) {
V_20 = F_9 ( V_18 ) ;
V_1 = V_20 + V_19 ;
V_7 = F_10 ( V_11 , V_1 , V_6 ) ;
V_6 -= V_7 ;
V_5 += V_6 ;
V_1 += V_6 ;
V_2 -= V_6 ;
while ( F_2 ( ! V_7 && V_2 ) ) {
V_10 ++ ;
V_11 = V_10 -> V_14 ;
V_6 = F_3 ( V_2 , V_10 -> V_15 ) ;
V_7 = F_10 ( V_11 , V_1 , V_6 ) ;
V_6 -= V_7 ;
V_5 = V_6 ;
V_1 += V_6 ;
V_2 -= V_6 ;
}
if ( F_11 ( ! V_2 ) ) {
F_12 ( V_20 ) ;
goto V_21;
}
V_19 = V_1 - V_20 ;
V_11 += V_6 ;
F_12 ( V_20 ) ;
V_6 = F_3 ( V_2 , V_10 -> V_15 - V_5 ) ;
}
V_20 = F_13 ( V_18 ) ;
V_1 = V_20 + V_19 ;
V_7 = F_4 ( V_11 , V_1 , V_6 ) ;
V_6 -= V_7 ;
V_5 += V_6 ;
V_1 += V_6 ;
V_2 -= V_6 ;
while ( F_2 ( ! V_7 && V_2 ) ) {
V_10 ++ ;
V_11 = V_10 -> V_14 ;
V_6 = F_3 ( V_2 , V_10 -> V_15 ) ;
V_7 = F_4 ( V_11 , V_1 , V_6 ) ;
V_6 -= V_7 ;
V_5 = V_6 ;
V_1 += V_6 ;
V_2 -= V_6 ;
}
F_14 ( V_18 ) ;
V_21:
if ( V_5 == V_10 -> V_15 ) {
V_10 ++ ;
V_5 = 0 ;
}
V_4 -> V_12 -= V_8 - V_2 ;
V_4 -> V_16 -= V_10 - V_4 -> V_10 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_13 = V_5 ;
return V_8 - V_2 ;
}
static T_1 F_15 ( struct V_18 * V_18 , T_1 V_19 , T_1 V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 , V_6 , V_7 , V_8 ;
const struct V_9 * V_10 ;
char T_2 * V_11 ;
void * V_20 , * V_17 ;
if ( F_2 ( V_2 > V_4 -> V_12 ) )
V_2 = V_4 -> V_12 ;
if ( F_2 ( ! V_2 ) )
return 0 ;
V_8 = V_2 ;
V_10 = V_4 -> V_10 ;
V_5 = V_4 -> V_13 ;
V_11 = V_10 -> V_14 + V_5 ;
V_6 = F_3 ( V_2 , V_10 -> V_15 - V_5 ) ;
if ( ! F_16 ( V_11 , V_6 ) ) {
V_20 = F_9 ( V_18 ) ;
V_17 = V_20 + V_19 ;
V_7 = F_17 ( V_17 , V_11 , V_6 ) ;
V_6 -= V_7 ;
V_5 += V_6 ;
V_17 += V_6 ;
V_2 -= V_6 ;
while ( F_2 ( ! V_7 && V_2 ) ) {
V_10 ++ ;
V_11 = V_10 -> V_14 ;
V_6 = F_3 ( V_2 , V_10 -> V_15 ) ;
V_7 = F_17 ( V_17 , V_11 , V_6 ) ;
V_6 -= V_7 ;
V_5 = V_6 ;
V_17 += V_6 ;
V_2 -= V_6 ;
}
if ( F_11 ( ! V_2 ) ) {
F_12 ( V_20 ) ;
goto V_21;
}
V_19 = V_17 - V_20 ;
V_11 += V_6 ;
F_12 ( V_20 ) ;
V_6 = F_3 ( V_2 , V_10 -> V_15 - V_5 ) ;
}
V_20 = F_13 ( V_18 ) ;
V_17 = V_20 + V_19 ;
V_7 = F_6 ( V_17 , V_11 , V_6 ) ;
V_6 -= V_7 ;
V_5 += V_6 ;
V_17 += V_6 ;
V_2 -= V_6 ;
while ( F_2 ( ! V_7 && V_2 ) ) {
V_10 ++ ;
V_11 = V_10 -> V_14 ;
V_6 = F_3 ( V_2 , V_10 -> V_15 ) ;
V_7 = F_6 ( V_17 , V_11 , V_6 ) ;
V_6 -= V_7 ;
V_5 = V_6 ;
V_17 += V_6 ;
V_2 -= V_6 ;
}
F_14 ( V_18 ) ;
V_21:
if ( V_5 == V_10 -> V_15 ) {
V_10 ++ ;
V_5 = 0 ;
}
V_4 -> V_12 -= V_8 - V_2 ;
V_4 -> V_16 -= V_10 - V_4 -> V_10 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_13 = V_5 ;
return V_8 - V_2 ;
}
static T_1 F_18 ( T_1 V_2 , struct V_3 * V_4 )
{
T_1 V_5 , V_6 , V_7 , V_8 ;
const struct V_9 * V_10 ;
char T_2 * V_11 ;
if ( F_2 ( V_2 > V_4 -> V_12 ) )
V_2 = V_4 -> V_12 ;
if ( F_2 ( ! V_2 ) )
return 0 ;
V_8 = V_2 ;
V_10 = V_4 -> V_10 ;
V_5 = V_4 -> V_13 ;
V_11 = V_10 -> V_14 + V_5 ;
V_6 = F_3 ( V_2 , V_10 -> V_15 - V_5 ) ;
V_7 = F_19 ( V_11 , V_6 ) ;
V_6 -= V_7 ;
V_5 += V_6 ;
V_2 -= V_6 ;
while ( F_2 ( ! V_7 && V_2 ) ) {
V_10 ++ ;
V_11 = V_10 -> V_14 ;
V_6 = F_3 ( V_2 , V_10 -> V_15 ) ;
V_7 = F_19 ( V_11 , V_6 ) ;
V_6 -= V_7 ;
V_5 = V_6 ;
V_2 -= V_6 ;
}
if ( V_5 == V_10 -> V_15 ) {
V_10 ++ ;
V_5 = 0 ;
}
V_4 -> V_12 -= V_8 - V_2 ;
V_4 -> V_16 -= V_10 - V_4 -> V_10 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_13 = V_5 ;
return V_8 - V_2 ;
}
static T_1 F_20 ( char * V_22 ,
const struct V_9 * V_10 , T_1 V_23 , T_1 V_2 )
{
T_1 V_24 = 0 , V_7 = 0 ;
while ( V_2 ) {
char T_2 * V_11 = V_10 -> V_14 + V_23 ;
int V_6 = F_3 ( V_2 , V_10 -> V_15 - V_23 ) ;
V_23 = 0 ;
V_7 = F_17 ( V_22 , V_11 , V_6 ) ;
V_24 += V_6 ;
V_2 -= V_6 ;
V_22 += V_6 ;
V_10 ++ ;
if ( F_2 ( V_7 ) )
break;
}
return V_24 - V_7 ;
}
static T_1 F_21 ( struct V_18 * V_18 ,
struct V_3 * V_4 , unsigned long V_19 , T_1 V_2 )
{
char * V_20 ;
T_1 V_24 ;
V_20 = F_9 ( V_18 ) ;
if ( F_11 ( V_4 -> V_16 == 1 ) ) {
int V_7 ;
char T_2 * V_11 = V_4 -> V_10 -> V_14 + V_4 -> V_13 ;
V_7 = F_17 ( V_20 + V_19 , V_11 , V_2 ) ;
V_24 = V_2 - V_7 ;
} else {
V_24 = F_20 ( V_20 + V_19 ,
V_4 -> V_10 , V_4 -> V_13 , V_2 ) ;
}
F_12 ( V_20 ) ;
return V_24 ;
}
static void F_22 ( struct V_3 * V_4 , T_1 V_2 )
{
F_23 ( V_4 -> V_12 < V_2 ) ;
if ( F_11 ( V_4 -> V_16 == 1 ) ) {
V_4 -> V_13 += V_2 ;
V_4 -> V_12 -= V_2 ;
} else {
const struct V_9 * V_10 = V_4 -> V_10 ;
T_1 V_23 = V_4 -> V_13 ;
unsigned long V_16 = V_4 -> V_16 ;
while ( V_2 || F_2 ( V_4 -> V_12 && ! V_10 -> V_15 ) ) {
int V_6 ;
V_6 = F_3 ( V_2 , V_10 -> V_15 - V_23 ) ;
F_23 ( ! V_4 -> V_12 || V_4 -> V_12 < V_6 ) ;
V_4 -> V_12 -= V_6 ;
V_2 -= V_6 ;
V_23 += V_6 ;
if ( V_10 -> V_15 == V_23 ) {
V_10 ++ ;
V_16 -- ;
V_23 = 0 ;
}
}
V_4 -> V_10 = V_10 ;
V_4 -> V_13 = V_23 ;
V_4 -> V_16 = V_16 ;
}
}
int F_24 ( struct V_3 * V_4 , T_1 V_2 )
{
if ( ! ( V_4 -> type & V_25 ) ) {
char T_2 * V_11 = V_4 -> V_10 -> V_14 + V_4 -> V_13 ;
V_2 = F_3 ( V_2 , V_4 -> V_10 -> V_15 - V_4 -> V_13 ) ;
return F_16 ( V_11 , V_2 ) ;
}
return 0 ;
}
static unsigned long F_25 ( const struct V_3 * V_4 )
{
const struct V_9 * V_10 = V_4 -> V_10 ;
unsigned long V_26 ;
T_1 V_27 = V_4 -> V_12 ;
T_1 V_28 ;
if ( ! V_27 )
return 0 ;
V_26 = ( unsigned long ) V_10 -> V_14 + V_4 -> V_13 ;
V_28 = V_10 -> V_15 - V_4 -> V_13 ;
if ( V_28 >= V_27 )
return V_26 | V_27 ;
V_27 -= V_28 ;
V_26 |= V_28 ;
while ( V_27 > ( ++ V_10 ) -> V_15 ) {
V_26 |= ( unsigned long ) V_10 -> V_14 | V_10 -> V_15 ;
V_27 -= V_10 -> V_15 ;
}
V_26 |= ( unsigned long ) V_10 -> V_14 | V_27 ;
return V_26 ;
}
void F_26 ( struct V_3 * V_4 , int V_29 ,
const struct V_9 * V_10 , unsigned long V_16 ,
T_1 V_12 )
{
if ( F_27 ( F_28 () , V_30 ) )
V_29 |= V_31 ;
V_4 -> type = V_29 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_16 = V_16 ;
V_4 -> V_13 = 0 ;
V_4 -> V_12 = V_12 ;
}
static T_3 F_29 ( struct V_3 * V_4 ,
struct V_18 * * V_32 , T_1 V_33 , unsigned V_34 ,
T_1 * V_35 )
{
T_1 V_19 = V_4 -> V_13 ;
const struct V_9 * V_10 = V_4 -> V_10 ;
T_1 V_36 ;
unsigned long V_37 ;
int V_28 ;
int V_26 ;
V_36 = V_10 -> V_15 - V_19 ;
if ( V_36 > V_4 -> V_12 )
V_36 = V_4 -> V_12 ;
if ( V_36 > V_33 )
V_36 = V_33 ;
V_37 = ( unsigned long ) V_10 -> V_14 + V_19 ;
V_36 += * V_35 = V_37 & ( V_38 - 1 ) ;
if ( V_36 > V_34 * V_38 )
V_36 = V_34 * V_38 ;
V_37 &= ~ ( V_38 - 1 ) ;
V_28 = ( V_36 + V_38 - 1 ) / V_38 ;
V_26 = F_30 ( V_37 , V_28 , ( V_4 -> type & V_39 ) != V_39 , V_32 ) ;
if ( F_2 ( V_26 < 0 ) )
return V_26 ;
return ( V_26 == V_28 ? V_36 : V_26 * V_38 ) - * V_35 ;
}
static T_3 F_31 ( struct V_3 * V_4 ,
struct V_18 * * * V_32 , T_1 V_33 ,
T_1 * V_35 )
{
T_1 V_19 = V_4 -> V_13 ;
const struct V_9 * V_10 = V_4 -> V_10 ;
T_1 V_36 ;
unsigned long V_37 ;
void * V_40 ;
int V_28 ;
int V_26 ;
V_36 = V_10 -> V_15 - V_19 ;
if ( V_36 > V_4 -> V_12 )
V_36 = V_4 -> V_12 ;
if ( V_36 > V_33 )
V_36 = V_33 ;
V_37 = ( unsigned long ) V_10 -> V_14 + V_19 ;
V_36 += * V_35 = V_37 & ( V_38 - 1 ) ;
V_37 &= ~ ( V_38 - 1 ) ;
V_28 = ( V_36 + V_38 - 1 ) / V_38 ;
V_40 = F_32 ( V_28 * sizeof( struct V_18 * ) , V_41 ) ;
if ( ! V_40 )
V_40 = F_33 ( V_28 * sizeof( struct V_18 * ) ) ;
if ( ! V_40 )
return - V_42 ;
V_26 = F_30 ( V_37 , V_28 , ( V_4 -> type & V_39 ) != V_39 , V_40 ) ;
if ( F_2 ( V_26 < 0 ) ) {
F_34 ( V_40 ) ;
return V_26 ;
}
* V_32 = V_40 ;
return ( V_26 == V_28 ? V_36 : V_26 * V_38 ) - * V_35 ;
}
static int F_35 ( const struct V_3 * V_4 , int V_34 )
{
T_1 V_19 = V_4 -> V_13 ;
T_1 V_27 = V_4 -> V_12 ;
const struct V_9 * V_10 = V_4 -> V_10 ;
int V_43 = 0 ;
int V_28 ;
for ( V_28 = 0 ; V_27 && V_28 < V_4 -> V_16 ; V_28 ++ , V_10 ++ ) {
unsigned long V_37 = ( unsigned long ) V_10 -> V_14 + V_19 ;
T_1 V_36 = V_10 -> V_15 - V_19 ;
V_19 = 0 ;
if ( F_2 ( ! V_36 ) )
continue;
if ( V_36 > V_27 )
V_36 = V_27 ;
V_43 += ( V_37 + V_36 + V_38 - 1 ) / V_38
- V_37 / V_38 ;
if ( V_43 >= V_34 )
return V_34 ;
V_27 -= V_36 ;
V_19 = 0 ;
}
return F_3 ( V_43 , V_34 ) ;
}
static void F_36 ( char * V_17 , struct V_18 * V_18 , T_1 V_19 , T_1 V_36 )
{
char * V_1 = F_9 ( V_18 ) ;
memcpy ( V_17 , V_1 + V_19 , V_36 ) ;
F_12 ( V_1 ) ;
}
static void F_37 ( struct V_18 * V_18 , T_1 V_19 , char * V_1 , T_1 V_36 )
{
char * V_17 = F_9 ( V_18 ) ;
memcpy ( V_17 + V_19 , V_1 , V_36 ) ;
F_12 ( V_17 ) ;
}
static void F_38 ( struct V_18 * V_18 , T_1 V_19 , T_1 V_36 )
{
char * V_37 = F_9 ( V_18 ) ;
memset ( V_37 + V_19 , 0 , V_36 ) ;
F_12 ( V_37 ) ;
}
static T_1 F_39 ( void * V_1 , T_1 V_2 , struct V_3 * V_4 )
{
T_1 V_5 , V_6 , V_8 ;
const struct V_44 * V_45 ;
if ( F_2 ( V_2 > V_4 -> V_12 ) )
V_2 = V_4 -> V_12 ;
if ( F_2 ( ! V_2 ) )
return 0 ;
V_8 = V_2 ;
V_45 = V_4 -> V_45 ;
V_5 = V_4 -> V_13 ;
V_6 = F_40 ( T_1 , V_2 , V_45 -> V_46 - V_5 ) ;
F_37 ( V_45 -> V_47 , V_5 + V_45 -> V_48 , V_1 , V_6 ) ;
V_5 += V_6 ;
V_1 += V_6 ;
V_2 -= V_6 ;
while ( V_2 ) {
V_45 ++ ;
V_6 = F_3 ( V_2 , ( T_1 ) V_45 -> V_46 ) ;
F_37 ( V_45 -> V_47 , V_45 -> V_48 , V_1 , V_6 ) ;
V_5 = V_6 ;
V_1 += V_6 ;
V_2 -= V_6 ;
}
if ( V_5 == V_45 -> V_46 ) {
V_45 ++ ;
V_5 = 0 ;
}
V_4 -> V_12 -= V_8 - V_2 ;
V_4 -> V_16 -= V_45 - V_4 -> V_45 ;
V_4 -> V_45 = V_45 ;
V_4 -> V_13 = V_5 ;
return V_8 - V_2 ;
}
static T_1 F_41 ( void * V_17 , T_1 V_2 , struct V_3 * V_4 )
{
T_1 V_5 , V_6 , V_8 ;
const struct V_44 * V_45 ;
if ( F_2 ( V_2 > V_4 -> V_12 ) )
V_2 = V_4 -> V_12 ;
if ( F_2 ( ! V_2 ) )
return 0 ;
V_8 = V_2 ;
V_45 = V_4 -> V_45 ;
V_5 = V_4 -> V_13 ;
V_6 = F_3 ( V_2 , V_45 -> V_46 - V_5 ) ;
F_36 ( V_17 , V_45 -> V_47 , V_45 -> V_48 + V_5 , V_6 ) ;
V_17 += V_6 ;
V_5 += V_6 ;
V_2 -= V_6 ;
while ( V_2 ) {
V_45 ++ ;
V_6 = F_3 ( V_2 , ( T_1 ) V_45 -> V_46 ) ;
F_36 ( V_17 , V_45 -> V_47 , V_45 -> V_48 , V_6 ) ;
V_5 = V_6 ;
V_17 += V_6 ;
V_2 -= V_6 ;
}
if ( V_5 == V_45 -> V_46 ) {
V_45 ++ ;
V_5 = 0 ;
}
V_4 -> V_12 -= V_8 ;
V_4 -> V_16 -= V_45 - V_4 -> V_45 ;
V_4 -> V_45 = V_45 ;
V_4 -> V_13 = V_5 ;
return V_8 ;
}
static T_1 F_42 ( struct V_18 * V_18 , T_1 V_19 ,
T_1 V_2 , struct V_3 * V_4 )
{
void * V_20 = F_9 ( V_18 ) ;
T_1 V_8 = F_39 ( V_20 + V_19 , V_2 , V_4 ) ;
F_12 ( V_20 ) ;
return V_8 ;
}
static T_1 F_43 ( struct V_18 * V_18 , T_1 V_19 ,
T_1 V_2 , struct V_3 * V_4 )
{
void * V_20 = F_9 ( V_18 ) ;
T_1 V_8 = F_41 ( V_20 + V_19 , V_2 , V_4 ) ;
F_12 ( V_20 ) ;
return V_8 ;
}
static T_1 F_44 ( T_1 V_2 , struct V_3 * V_4 )
{
T_1 V_5 , V_6 , V_8 ;
const struct V_44 * V_45 ;
if ( F_2 ( V_2 > V_4 -> V_12 ) )
V_2 = V_4 -> V_12 ;
if ( F_2 ( ! V_2 ) )
return 0 ;
V_8 = V_2 ;
V_45 = V_4 -> V_45 ;
V_5 = V_4 -> V_13 ;
V_6 = F_40 ( T_1 , V_2 , V_45 -> V_46 - V_5 ) ;
F_38 ( V_45 -> V_47 , V_5 + V_45 -> V_48 , V_6 ) ;
V_5 += V_6 ;
V_2 -= V_6 ;
while ( V_2 ) {
V_45 ++ ;
V_6 = F_3 ( V_2 , ( T_1 ) V_45 -> V_46 ) ;
F_38 ( V_45 -> V_47 , V_45 -> V_48 , V_6 ) ;
V_5 = V_6 ;
V_2 -= V_6 ;
}
if ( V_5 == V_45 -> V_46 ) {
V_45 ++ ;
V_5 = 0 ;
}
V_4 -> V_12 -= V_8 - V_2 ;
V_4 -> V_16 -= V_45 - V_4 -> V_45 ;
V_4 -> V_45 = V_45 ;
V_4 -> V_13 = V_5 ;
return V_8 - V_2 ;
}
static T_1 F_45 ( struct V_18 * V_18 ,
struct V_3 * V_4 , unsigned long V_19 , T_1 V_2 )
{
char * V_20 ;
T_1 V_7 ;
const struct V_44 * V_45 ;
T_1 V_23 = V_4 -> V_13 ;
V_20 = F_9 ( V_18 ) ;
for ( V_7 = V_2 , V_45 = V_4 -> V_45 ; V_7 ; V_45 ++ , V_23 = 0 ) {
T_1 V_6 = F_3 ( V_7 , V_45 -> V_46 - V_23 ) ;
if ( ! V_45 -> V_46 )
continue;
F_36 ( V_20 + V_19 , V_45 -> V_47 ,
V_45 -> V_48 + V_23 , V_6 ) ;
V_19 += V_6 ;
V_7 -= V_6 ;
}
F_12 ( V_20 ) ;
return V_2 ;
}
static void F_46 ( struct V_3 * V_4 , T_1 V_2 )
{
F_23 ( V_4 -> V_12 < V_2 ) ;
if ( F_11 ( V_4 -> V_16 == 1 ) ) {
V_4 -> V_13 += V_2 ;
V_4 -> V_12 -= V_2 ;
} else {
const struct V_44 * V_45 = V_4 -> V_45 ;
T_1 V_23 = V_4 -> V_13 ;
unsigned long V_16 = V_4 -> V_16 ;
while ( V_2 || F_2 ( V_4 -> V_12 && ! V_45 -> V_46 ) ) {
int V_6 ;
V_6 = F_3 ( V_2 , V_45 -> V_46 - V_23 ) ;
F_23 ( ! V_4 -> V_12 || V_4 -> V_12 < V_6 ) ;
V_4 -> V_12 -= V_6 ;
V_2 -= V_6 ;
V_23 += V_6 ;
if ( V_45 -> V_46 == V_23 ) {
V_45 ++ ;
V_16 -- ;
V_23 = 0 ;
}
}
V_4 -> V_45 = V_45 ;
V_4 -> V_13 = V_23 ;
V_4 -> V_16 = V_16 ;
}
}
static unsigned long F_47 ( const struct V_3 * V_4 )
{
const struct V_44 * V_45 = V_4 -> V_45 ;
unsigned long V_26 ;
T_1 V_27 = V_4 -> V_12 ;
T_1 V_28 ;
if ( ! V_27 )
return 0 ;
V_26 = V_45 -> V_48 + V_4 -> V_13 ;
V_28 = V_45 -> V_46 - V_4 -> V_13 ;
if ( V_28 >= V_27 )
return V_26 | V_27 ;
V_27 -= V_28 ;
V_26 |= V_28 ;
while ( V_27 > ( ++ V_45 ) -> V_46 ) {
V_26 |= V_45 -> V_48 | V_45 -> V_46 ;
V_27 -= V_45 -> V_46 ;
}
V_26 |= V_45 -> V_48 | V_27 ;
return V_26 ;
}
static T_3 F_48 ( struct V_3 * V_4 ,
struct V_18 * * V_32 , T_1 V_33 , unsigned V_34 ,
T_1 * V_35 )
{
const struct V_44 * V_45 = V_4 -> V_45 ;
T_1 V_36 = V_45 -> V_46 - V_4 -> V_13 ;
if ( V_36 > V_4 -> V_12 )
V_36 = V_4 -> V_12 ;
if ( V_36 > V_33 )
V_36 = V_33 ;
* V_35 = V_45 -> V_48 + V_4 -> V_13 ;
F_49 ( * V_32 = V_45 -> V_47 ) ;
return V_36 ;
}
static T_3 F_50 ( struct V_3 * V_4 ,
struct V_18 * * * V_32 , T_1 V_33 ,
T_1 * V_35 )
{
const struct V_44 * V_45 = V_4 -> V_45 ;
T_1 V_36 = V_45 -> V_46 - V_4 -> V_13 ;
if ( V_36 > V_4 -> V_12 )
V_36 = V_4 -> V_12 ;
if ( V_36 > V_33 )
V_36 = V_33 ;
* V_35 = V_45 -> V_48 + V_4 -> V_13 ;
* V_32 = F_32 ( sizeof( struct V_18 * ) , V_41 ) ;
if ( ! * V_32 )
return - V_42 ;
F_49 ( * * V_32 = V_45 -> V_47 ) ;
return V_36 ;
}
static int F_51 ( const struct V_3 * V_4 , int V_34 )
{
T_1 V_19 = V_4 -> V_13 ;
T_1 V_27 = V_4 -> V_12 ;
const struct V_44 * V_45 = V_4 -> V_45 ;
int V_43 = 0 ;
int V_28 ;
for ( V_28 = 0 ; V_27 && V_28 < V_4 -> V_16 ; V_28 ++ , V_45 ++ ) {
T_1 V_36 = V_45 -> V_46 - V_19 ;
V_19 = 0 ;
if ( F_2 ( ! V_36 ) )
continue;
if ( V_36 > V_27 )
V_36 = V_27 ;
V_43 ++ ;
if ( V_43 >= V_34 )
return V_34 ;
V_27 -= V_36 ;
V_19 = 0 ;
}
return F_3 ( V_43 , V_34 ) ;
}
T_1 F_52 ( struct V_18 * V_18 , T_1 V_19 , T_1 V_2 ,
struct V_3 * V_4 )
{
if ( V_4 -> type & V_25 )
return F_42 ( V_18 , V_19 , V_2 , V_4 ) ;
else
return F_7 ( V_18 , V_19 , V_2 , V_4 ) ;
}
T_1 F_53 ( struct V_18 * V_18 , T_1 V_19 , T_1 V_2 ,
struct V_3 * V_4 )
{
if ( V_4 -> type & V_25 )
return F_43 ( V_18 , V_19 , V_2 , V_4 ) ;
else
return F_15 ( V_18 , V_19 , V_2 , V_4 ) ;
}
T_1 F_54 ( void * V_37 , T_1 V_2 , struct V_3 * V_4 )
{
if ( V_4 -> type & V_25 )
return F_39 ( V_37 , V_2 , V_4 ) ;
else
return F_1 ( V_37 , V_2 , V_4 ) ;
}
T_1 F_55 ( void * V_37 , T_1 V_2 , struct V_3 * V_4 )
{
if ( V_4 -> type & V_25 )
return F_41 ( V_37 , V_2 , V_4 ) ;
else
return F_5 ( V_37 , V_2 , V_4 ) ;
}
T_1 F_56 ( T_1 V_2 , struct V_3 * V_4 )
{
if ( V_4 -> type & V_25 ) {
return F_44 ( V_2 , V_4 ) ;
} else {
return F_18 ( V_2 , V_4 ) ;
}
}
T_1 F_57 ( struct V_18 * V_18 ,
struct V_3 * V_4 , unsigned long V_19 , T_1 V_2 )
{
if ( V_4 -> type & V_25 )
return F_45 ( V_18 , V_4 , V_19 , V_2 ) ;
else
return F_21 ( V_18 , V_4 , V_19 , V_2 ) ;
}
void F_58 ( struct V_3 * V_4 , T_1 V_27 )
{
if ( V_4 -> type & V_25 )
F_46 ( V_4 , V_27 ) ;
else
F_22 ( V_4 , V_27 ) ;
}
T_1 F_59 ( const struct V_3 * V_4 )
{
if ( V_4 -> V_16 == 1 )
return V_4 -> V_12 ;
else if ( V_4 -> type & V_25 )
return F_3 ( V_4 -> V_12 , V_4 -> V_45 -> V_46 - V_4 -> V_13 ) ;
else
return F_3 ( V_4 -> V_12 , V_4 -> V_10 -> V_15 - V_4 -> V_13 ) ;
}
unsigned long F_60 ( const struct V_3 * V_4 )
{
if ( V_4 -> type & V_25 )
return F_47 ( V_4 ) ;
else
return F_25 ( V_4 ) ;
}
T_3 F_61 ( struct V_3 * V_4 ,
struct V_18 * * V_32 , T_1 V_33 , unsigned V_34 ,
T_1 * V_35 )
{
if ( V_4 -> type & V_25 )
return F_48 ( V_4 , V_32 , V_33 , V_34 , V_35 ) ;
else
return F_29 ( V_4 , V_32 , V_33 , V_34 , V_35 ) ;
}
T_3 F_62 ( struct V_3 * V_4 ,
struct V_18 * * * V_32 , T_1 V_33 ,
T_1 * V_35 )
{
if ( V_4 -> type & V_25 )
return F_50 ( V_4 , V_32 , V_33 , V_35 ) ;
else
return F_31 ( V_4 , V_32 , V_33 , V_35 ) ;
}
int F_63 ( const struct V_3 * V_4 , int V_34 )
{
if ( V_4 -> type & V_25 )
return F_51 ( V_4 , V_34 ) ;
else
return F_35 ( V_4 , V_34 ) ;
}
