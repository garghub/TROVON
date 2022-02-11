static T_1 F_1 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
T_1 V_6 , V_7 , V_8 , V_9 ;
const struct V_10 * V_11 ;
char T_2 * V_12 ;
void * V_13 , * V_14 ;
if ( F_2 ( V_3 > V_5 -> V_15 ) )
V_3 = V_5 -> V_15 ;
if ( F_2 ( ! V_3 ) )
return 0 ;
V_9 = V_3 ;
V_11 = V_5 -> V_11 ;
V_6 = V_5 -> V_16 ;
V_12 = V_11 -> V_17 + V_6 ;
V_7 = F_3 ( V_3 , V_11 -> V_18 - V_6 ) ;
if ( ! F_4 ( V_12 , V_7 ) ) {
V_13 = F_5 ( V_1 ) ;
V_14 = V_13 + V_2 ;
V_8 = F_6 ( V_12 , V_14 , V_7 ) ;
V_7 -= V_8 ;
V_6 += V_7 ;
V_14 += V_7 ;
V_3 -= V_7 ;
while ( F_2 ( ! V_8 && V_3 ) ) {
V_11 ++ ;
V_12 = V_11 -> V_17 ;
V_7 = F_3 ( V_3 , V_11 -> V_18 ) ;
V_8 = F_6 ( V_12 , V_14 , V_7 ) ;
V_7 -= V_8 ;
V_6 = V_7 ;
V_14 += V_7 ;
V_3 -= V_7 ;
}
if ( F_7 ( ! V_3 ) ) {
F_8 ( V_13 ) ;
goto V_19;
}
V_2 = V_14 - V_13 ;
V_12 += V_7 ;
F_8 ( V_13 ) ;
V_7 = F_3 ( V_3 , V_11 -> V_18 - V_6 ) ;
}
V_13 = F_9 ( V_1 ) ;
V_14 = V_13 + V_2 ;
V_8 = F_10 ( V_12 , V_14 , V_7 ) ;
V_7 -= V_8 ;
V_6 += V_7 ;
V_14 += V_7 ;
V_3 -= V_7 ;
while ( F_2 ( ! V_8 && V_3 ) ) {
V_11 ++ ;
V_12 = V_11 -> V_17 ;
V_7 = F_3 ( V_3 , V_11 -> V_18 ) ;
V_8 = F_10 ( V_12 , V_14 , V_7 ) ;
V_7 -= V_8 ;
V_6 = V_7 ;
V_14 += V_7 ;
V_3 -= V_7 ;
}
F_11 ( V_1 ) ;
V_19:
if ( V_6 == V_11 -> V_18 ) {
V_11 ++ ;
V_6 = 0 ;
}
V_5 -> V_15 -= V_9 - V_3 ;
V_5 -> V_20 -= V_11 - V_5 -> V_11 ;
V_5 -> V_11 = V_11 ;
V_5 -> V_16 = V_6 ;
return V_9 - V_3 ;
}
static T_1 F_12 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
T_1 V_6 , V_7 , V_8 , V_9 ;
const struct V_10 * V_11 ;
char T_2 * V_12 ;
void * V_13 , * V_21 ;
if ( F_2 ( V_3 > V_5 -> V_15 ) )
V_3 = V_5 -> V_15 ;
if ( F_2 ( ! V_3 ) )
return 0 ;
V_9 = V_3 ;
V_11 = V_5 -> V_11 ;
V_6 = V_5 -> V_16 ;
V_12 = V_11 -> V_17 + V_6 ;
V_7 = F_3 ( V_3 , V_11 -> V_18 - V_6 ) ;
if ( ! F_13 ( V_12 , V_7 ) ) {
V_13 = F_5 ( V_1 ) ;
V_21 = V_13 + V_2 ;
V_8 = F_14 ( V_21 , V_12 , V_7 ) ;
V_7 -= V_8 ;
V_6 += V_7 ;
V_21 += V_7 ;
V_3 -= V_7 ;
while ( F_2 ( ! V_8 && V_3 ) ) {
V_11 ++ ;
V_12 = V_11 -> V_17 ;
V_7 = F_3 ( V_3 , V_11 -> V_18 ) ;
V_8 = F_14 ( V_21 , V_12 , V_7 ) ;
V_7 -= V_8 ;
V_6 = V_7 ;
V_21 += V_7 ;
V_3 -= V_7 ;
}
if ( F_7 ( ! V_3 ) ) {
F_8 ( V_13 ) ;
goto V_19;
}
V_2 = V_21 - V_13 ;
V_12 += V_7 ;
F_8 ( V_13 ) ;
V_7 = F_3 ( V_3 , V_11 -> V_18 - V_6 ) ;
}
V_13 = F_9 ( V_1 ) ;
V_21 = V_13 + V_2 ;
V_8 = F_15 ( V_21 , V_12 , V_7 ) ;
V_7 -= V_8 ;
V_6 += V_7 ;
V_21 += V_7 ;
V_3 -= V_7 ;
while ( F_2 ( ! V_8 && V_3 ) ) {
V_11 ++ ;
V_12 = V_11 -> V_17 ;
V_7 = F_3 ( V_3 , V_11 -> V_18 ) ;
V_8 = F_15 ( V_21 , V_12 , V_7 ) ;
V_7 -= V_8 ;
V_6 = V_7 ;
V_21 += V_7 ;
V_3 -= V_7 ;
}
F_11 ( V_1 ) ;
V_19:
if ( V_6 == V_11 -> V_18 ) {
V_11 ++ ;
V_6 = 0 ;
}
V_5 -> V_15 -= V_9 - V_3 ;
V_5 -> V_20 -= V_11 - V_5 -> V_11 ;
V_5 -> V_11 = V_11 ;
V_5 -> V_16 = V_6 ;
return V_9 - V_3 ;
}
static T_1 F_16 ( char * V_22 ,
const struct V_10 * V_11 , T_1 V_23 , T_1 V_3 )
{
T_1 V_24 = 0 , V_8 = 0 ;
while ( V_3 ) {
char T_2 * V_12 = V_11 -> V_17 + V_23 ;
int V_7 = F_3 ( V_3 , V_11 -> V_18 - V_23 ) ;
V_23 = 0 ;
V_8 = F_14 ( V_22 , V_12 , V_7 ) ;
V_24 += V_7 ;
V_3 -= V_7 ;
V_22 += V_7 ;
V_11 ++ ;
if ( F_2 ( V_8 ) )
break;
}
return V_24 - V_8 ;
}
static T_1 F_17 ( struct V_1 * V_1 ,
struct V_4 * V_5 , unsigned long V_2 , T_1 V_3 )
{
char * V_13 ;
T_1 V_24 ;
V_13 = F_5 ( V_1 ) ;
if ( F_7 ( V_5 -> V_20 == 1 ) ) {
int V_8 ;
char T_2 * V_12 = V_5 -> V_11 -> V_17 + V_5 -> V_16 ;
V_8 = F_14 ( V_13 + V_2 , V_12 , V_3 ) ;
V_24 = V_3 - V_8 ;
} else {
V_24 = F_16 ( V_13 + V_2 ,
V_5 -> V_11 , V_5 -> V_16 , V_3 ) ;
}
F_8 ( V_13 ) ;
return V_24 ;
}
static void F_18 ( struct V_4 * V_5 , T_1 V_3 )
{
F_19 ( V_5 -> V_15 < V_3 ) ;
if ( F_7 ( V_5 -> V_20 == 1 ) ) {
V_5 -> V_16 += V_3 ;
V_5 -> V_15 -= V_3 ;
} else {
const struct V_10 * V_11 = V_5 -> V_11 ;
T_1 V_23 = V_5 -> V_16 ;
unsigned long V_20 = V_5 -> V_20 ;
while ( V_3 || F_2 ( V_5 -> V_15 && ! V_11 -> V_18 ) ) {
int V_7 ;
V_7 = F_3 ( V_3 , V_11 -> V_18 - V_23 ) ;
F_19 ( ! V_5 -> V_15 || V_5 -> V_15 < V_7 ) ;
V_5 -> V_15 -= V_7 ;
V_3 -= V_7 ;
V_23 += V_7 ;
if ( V_11 -> V_18 == V_23 ) {
V_11 ++ ;
V_20 -- ;
V_23 = 0 ;
}
}
V_5 -> V_11 = V_11 ;
V_5 -> V_16 = V_23 ;
V_5 -> V_20 = V_20 ;
}
}
int F_20 ( struct V_4 * V_5 , T_1 V_3 )
{
if ( ! ( V_5 -> type & V_25 ) ) {
char T_2 * V_12 = V_5 -> V_11 -> V_17 + V_5 -> V_16 ;
V_3 = F_3 ( V_3 , V_5 -> V_11 -> V_18 - V_5 -> V_16 ) ;
return F_13 ( V_12 , V_3 ) ;
}
return 0 ;
}
static unsigned long F_21 ( const struct V_4 * V_5 )
{
const struct V_10 * V_11 = V_5 -> V_11 ;
unsigned long V_26 ;
T_1 V_27 = V_5 -> V_15 ;
T_1 V_28 ;
if ( ! V_27 )
return 0 ;
V_26 = ( unsigned long ) V_11 -> V_17 + V_5 -> V_16 ;
V_28 = V_11 -> V_18 - V_5 -> V_16 ;
if ( V_28 >= V_27 )
return V_26 | V_27 ;
V_27 -= V_28 ;
V_26 |= V_28 ;
while ( V_27 > ( ++ V_11 ) -> V_18 ) {
V_26 |= ( unsigned long ) V_11 -> V_17 | V_11 -> V_18 ;
V_27 -= V_11 -> V_18 ;
}
V_26 |= ( unsigned long ) V_11 -> V_17 | V_27 ;
return V_26 ;
}
void F_22 ( struct V_4 * V_5 , int V_29 ,
const struct V_10 * V_11 , unsigned long V_20 ,
T_1 V_15 )
{
if ( F_23 ( F_24 () , V_30 ) )
V_29 |= V_31 ;
V_5 -> type = V_29 ;
V_5 -> V_11 = V_11 ;
V_5 -> V_20 = V_20 ;
V_5 -> V_16 = 0 ;
V_5 -> V_15 = V_15 ;
}
static T_3 F_25 ( struct V_4 * V_5 ,
struct V_1 * * V_32 , T_1 V_33 , unsigned V_34 ,
T_1 * V_35 )
{
T_1 V_2 = V_5 -> V_16 ;
const struct V_10 * V_11 = V_5 -> V_11 ;
T_1 V_36 ;
unsigned long V_37 ;
int V_28 ;
int V_26 ;
V_36 = V_11 -> V_18 - V_2 ;
if ( V_36 > V_5 -> V_15 )
V_36 = V_5 -> V_15 ;
if ( V_36 > V_33 )
V_36 = V_33 ;
V_37 = ( unsigned long ) V_11 -> V_17 + V_2 ;
V_36 += * V_35 = V_37 & ( V_38 - 1 ) ;
if ( V_36 > V_34 * V_38 )
V_36 = V_34 * V_38 ;
V_37 &= ~ ( V_38 - 1 ) ;
V_28 = ( V_36 + V_38 - 1 ) / V_38 ;
V_26 = F_26 ( V_37 , V_28 , ( V_5 -> type & V_39 ) != V_39 , V_32 ) ;
if ( F_2 ( V_26 < 0 ) )
return V_26 ;
return ( V_26 == V_28 ? V_36 : V_26 * V_38 ) - * V_35 ;
}
static T_3 F_27 ( struct V_4 * V_5 ,
struct V_1 * * * V_32 , T_1 V_33 ,
T_1 * V_35 )
{
T_1 V_2 = V_5 -> V_16 ;
const struct V_10 * V_11 = V_5 -> V_11 ;
T_1 V_36 ;
unsigned long V_37 ;
void * V_40 ;
int V_28 ;
int V_26 ;
V_36 = V_11 -> V_18 - V_2 ;
if ( V_36 > V_5 -> V_15 )
V_36 = V_5 -> V_15 ;
if ( V_36 > V_33 )
V_36 = V_33 ;
V_37 = ( unsigned long ) V_11 -> V_17 + V_2 ;
V_36 += * V_35 = V_37 & ( V_38 - 1 ) ;
V_37 &= ~ ( V_38 - 1 ) ;
V_28 = ( V_36 + V_38 - 1 ) / V_38 ;
V_40 = F_28 ( V_28 * sizeof( struct V_1 * ) , V_41 ) ;
if ( ! V_40 )
V_40 = F_29 ( V_28 * sizeof( struct V_1 * ) ) ;
if ( ! V_40 )
return - V_42 ;
V_26 = F_26 ( V_37 , V_28 , ( V_5 -> type & V_39 ) != V_39 , V_40 ) ;
if ( F_2 ( V_26 < 0 ) ) {
F_30 ( V_40 ) ;
return V_26 ;
}
* V_32 = V_40 ;
return ( V_26 == V_28 ? V_36 : V_26 * V_38 ) - * V_35 ;
}
static int F_31 ( const struct V_4 * V_5 , int V_34 )
{
T_1 V_2 = V_5 -> V_16 ;
T_1 V_27 = V_5 -> V_15 ;
const struct V_10 * V_11 = V_5 -> V_11 ;
int V_43 = 0 ;
int V_28 ;
for ( V_28 = 0 ; V_27 && V_28 < V_5 -> V_20 ; V_28 ++ , V_11 ++ ) {
unsigned long V_37 = ( unsigned long ) V_11 -> V_17 + V_2 ;
T_1 V_36 = V_11 -> V_18 - V_2 ;
V_2 = 0 ;
if ( F_2 ( ! V_36 ) )
continue;
if ( V_36 > V_27 )
V_36 = V_27 ;
V_43 += ( V_37 + V_36 + V_38 - 1 ) / V_38
- V_37 / V_38 ;
if ( V_43 >= V_34 )
return V_34 ;
V_27 -= V_36 ;
V_2 = 0 ;
}
return F_3 ( V_43 , V_34 ) ;
}
static void F_32 ( char * V_21 , struct V_1 * V_1 , T_1 V_2 , T_1 V_36 )
{
char * V_14 = F_5 ( V_1 ) ;
memcpy ( V_21 , V_14 + V_2 , V_36 ) ;
F_8 ( V_14 ) ;
}
static void F_33 ( struct V_1 * V_1 , T_1 V_2 , char * V_14 , T_1 V_36 )
{
char * V_21 = F_5 ( V_1 ) ;
memcpy ( V_21 + V_2 , V_14 , V_36 ) ;
F_8 ( V_21 ) ;
}
static T_1 F_34 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
T_1 V_6 , V_7 , V_9 ;
const struct V_44 * V_45 ;
void * V_13 , * V_14 ;
if ( F_2 ( V_3 > V_5 -> V_15 ) )
V_3 = V_5 -> V_15 ;
if ( F_2 ( ! V_3 ) )
return 0 ;
V_9 = V_3 ;
V_45 = V_5 -> V_45 ;
V_6 = V_5 -> V_16 ;
V_7 = F_35 ( T_1 , V_3 , V_45 -> V_46 - V_6 ) ;
V_13 = F_5 ( V_1 ) ;
V_14 = V_13 + V_2 ;
F_33 ( V_45 -> V_47 , V_6 + V_45 -> V_48 , V_14 , V_7 ) ;
V_6 += V_7 ;
V_14 += V_7 ;
V_3 -= V_7 ;
while ( V_3 ) {
V_45 ++ ;
V_7 = F_3 ( V_3 , ( T_1 ) V_45 -> V_46 ) ;
F_33 ( V_45 -> V_47 , V_45 -> V_48 , V_14 , V_7 ) ;
V_6 = V_7 ;
V_14 += V_7 ;
V_3 -= V_7 ;
}
F_8 ( V_13 ) ;
if ( V_6 == V_45 -> V_46 ) {
V_45 ++ ;
V_6 = 0 ;
}
V_5 -> V_15 -= V_9 - V_3 ;
V_5 -> V_20 -= V_45 - V_5 -> V_45 ;
V_5 -> V_45 = V_45 ;
V_5 -> V_16 = V_6 ;
return V_9 - V_3 ;
}
static T_1 F_36 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
T_1 V_6 , V_7 , V_9 ;
const struct V_44 * V_45 ;
void * V_13 , * V_21 ;
if ( F_2 ( V_3 > V_5 -> V_15 ) )
V_3 = V_5 -> V_15 ;
if ( F_2 ( ! V_3 ) )
return 0 ;
V_9 = V_3 ;
V_45 = V_5 -> V_45 ;
V_6 = V_5 -> V_16 ;
V_13 = F_5 ( V_1 ) ;
V_21 = V_13 + V_2 ;
V_7 = F_3 ( V_3 , V_45 -> V_46 - V_6 ) ;
F_32 ( V_21 , V_45 -> V_47 , V_45 -> V_48 + V_6 , V_7 ) ;
V_21 += V_7 ;
V_6 += V_7 ;
V_3 -= V_7 ;
while ( V_3 ) {
V_45 ++ ;
V_7 = F_3 ( V_3 , ( T_1 ) V_45 -> V_46 ) ;
F_32 ( V_21 , V_45 -> V_47 , V_45 -> V_48 , V_7 ) ;
V_6 = V_7 ;
V_21 += V_7 ;
V_3 -= V_7 ;
}
F_8 ( V_13 ) ;
if ( V_6 == V_45 -> V_46 ) {
V_45 ++ ;
V_6 = 0 ;
}
V_5 -> V_15 -= V_9 ;
V_5 -> V_20 -= V_45 - V_5 -> V_45 ;
V_5 -> V_45 = V_45 ;
V_5 -> V_16 = V_6 ;
return V_9 ;
}
static T_1 F_37 ( struct V_1 * V_1 ,
struct V_4 * V_5 , unsigned long V_2 , T_1 V_3 )
{
char * V_13 ;
T_1 V_8 ;
const struct V_44 * V_45 ;
T_1 V_23 = V_5 -> V_16 ;
V_13 = F_5 ( V_1 ) ;
for ( V_8 = V_3 , V_45 = V_5 -> V_45 ; V_8 ; V_45 ++ , V_23 = 0 ) {
T_1 V_7 = F_3 ( V_8 , V_45 -> V_46 - V_23 ) ;
if ( ! V_45 -> V_46 )
continue;
F_32 ( V_13 + V_2 , V_45 -> V_47 ,
V_45 -> V_48 + V_23 , V_7 ) ;
V_2 += V_7 ;
V_8 -= V_7 ;
}
F_8 ( V_13 ) ;
return V_3 ;
}
static void F_38 ( struct V_4 * V_5 , T_1 V_3 )
{
F_19 ( V_5 -> V_15 < V_3 ) ;
if ( F_7 ( V_5 -> V_20 == 1 ) ) {
V_5 -> V_16 += V_3 ;
V_5 -> V_15 -= V_3 ;
} else {
const struct V_44 * V_45 = V_5 -> V_45 ;
T_1 V_23 = V_5 -> V_16 ;
unsigned long V_20 = V_5 -> V_20 ;
while ( V_3 || F_2 ( V_5 -> V_15 && ! V_45 -> V_46 ) ) {
int V_7 ;
V_7 = F_3 ( V_3 , V_45 -> V_46 - V_23 ) ;
F_19 ( ! V_5 -> V_15 || V_5 -> V_15 < V_7 ) ;
V_5 -> V_15 -= V_7 ;
V_3 -= V_7 ;
V_23 += V_7 ;
if ( V_45 -> V_46 == V_23 ) {
V_45 ++ ;
V_20 -- ;
V_23 = 0 ;
}
}
V_5 -> V_45 = V_45 ;
V_5 -> V_16 = V_23 ;
V_5 -> V_20 = V_20 ;
}
}
static unsigned long F_39 ( const struct V_4 * V_5 )
{
const struct V_44 * V_45 = V_5 -> V_45 ;
unsigned long V_26 ;
T_1 V_27 = V_5 -> V_15 ;
T_1 V_28 ;
if ( ! V_27 )
return 0 ;
V_26 = V_45 -> V_48 + V_5 -> V_16 ;
V_28 = V_45 -> V_46 - V_5 -> V_16 ;
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
static T_3 F_40 ( struct V_4 * V_5 ,
struct V_1 * * V_32 , T_1 V_33 , unsigned V_34 ,
T_1 * V_35 )
{
const struct V_44 * V_45 = V_5 -> V_45 ;
T_1 V_36 = V_45 -> V_46 - V_5 -> V_16 ;
if ( V_36 > V_5 -> V_15 )
V_36 = V_5 -> V_15 ;
if ( V_36 > V_33 )
V_36 = V_33 ;
* V_35 = V_45 -> V_48 + V_5 -> V_16 ;
F_41 ( * V_32 = V_45 -> V_47 ) ;
return V_36 ;
}
static T_3 F_42 ( struct V_4 * V_5 ,
struct V_1 * * * V_32 , T_1 V_33 ,
T_1 * V_35 )
{
const struct V_44 * V_45 = V_5 -> V_45 ;
T_1 V_36 = V_45 -> V_46 - V_5 -> V_16 ;
if ( V_36 > V_5 -> V_15 )
V_36 = V_5 -> V_15 ;
if ( V_36 > V_33 )
V_36 = V_33 ;
* V_35 = V_45 -> V_48 + V_5 -> V_16 ;
* V_32 = F_28 ( sizeof( struct V_1 * ) , V_41 ) ;
if ( ! * V_32 )
return - V_42 ;
F_41 ( * * V_32 = V_45 -> V_47 ) ;
return V_36 ;
}
static int F_43 ( const struct V_4 * V_5 , int V_34 )
{
T_1 V_2 = V_5 -> V_16 ;
T_1 V_27 = V_5 -> V_15 ;
const struct V_44 * V_45 = V_5 -> V_45 ;
int V_43 = 0 ;
int V_28 ;
for ( V_28 = 0 ; V_27 && V_28 < V_5 -> V_20 ; V_28 ++ , V_45 ++ ) {
T_1 V_36 = V_45 -> V_46 - V_2 ;
V_2 = 0 ;
if ( F_2 ( ! V_36 ) )
continue;
if ( V_36 > V_27 )
V_36 = V_27 ;
V_43 ++ ;
if ( V_43 >= V_34 )
return V_34 ;
V_27 -= V_36 ;
V_2 = 0 ;
}
return F_3 ( V_43 , V_34 ) ;
}
T_1 F_44 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
if ( V_5 -> type & V_25 )
return F_34 ( V_1 , V_2 , V_3 , V_5 ) ;
else
return F_1 ( V_1 , V_2 , V_3 , V_5 ) ;
}
T_1 F_45 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
if ( V_5 -> type & V_25 )
return F_36 ( V_1 , V_2 , V_3 , V_5 ) ;
else
return F_12 ( V_1 , V_2 , V_3 , V_5 ) ;
}
T_1 F_46 ( struct V_1 * V_1 ,
struct V_4 * V_5 , unsigned long V_2 , T_1 V_3 )
{
if ( V_5 -> type & V_25 )
return F_37 ( V_1 , V_5 , V_2 , V_3 ) ;
else
return F_17 ( V_1 , V_5 , V_2 , V_3 ) ;
}
void F_47 ( struct V_4 * V_5 , T_1 V_27 )
{
if ( V_5 -> type & V_25 )
F_38 ( V_5 , V_27 ) ;
else
F_18 ( V_5 , V_27 ) ;
}
T_1 F_48 ( const struct V_4 * V_5 )
{
if ( V_5 -> V_20 == 1 )
return V_5 -> V_15 ;
else if ( V_5 -> type & V_25 )
return F_3 ( V_5 -> V_15 , V_5 -> V_11 -> V_18 - V_5 -> V_16 ) ;
else
return F_3 ( V_5 -> V_15 , V_5 -> V_45 -> V_46 - V_5 -> V_16 ) ;
}
unsigned long F_49 ( const struct V_4 * V_5 )
{
if ( V_5 -> type & V_25 )
return F_39 ( V_5 ) ;
else
return F_21 ( V_5 ) ;
}
T_3 F_50 ( struct V_4 * V_5 ,
struct V_1 * * V_32 , T_1 V_33 , unsigned V_34 ,
T_1 * V_35 )
{
if ( V_5 -> type & V_25 )
return F_40 ( V_5 , V_32 , V_33 , V_34 , V_35 ) ;
else
return F_25 ( V_5 , V_32 , V_33 , V_34 , V_35 ) ;
}
T_3 F_51 ( struct V_4 * V_5 ,
struct V_1 * * * V_32 , T_1 V_33 ,
T_1 * V_35 )
{
if ( V_5 -> type & V_25 )
return F_42 ( V_5 , V_32 , V_33 , V_35 ) ;
else
return F_27 ( V_5 , V_32 , V_33 , V_35 ) ;
}
int F_52 ( const struct V_4 * V_5 , int V_34 )
{
if ( V_5 -> type & V_25 )
return F_43 ( V_5 , V_34 ) ;
else
return F_31 ( V_5 , V_34 ) ;
}
