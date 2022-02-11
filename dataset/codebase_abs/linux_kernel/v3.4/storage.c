static int F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
void * V_4 , T_1 V_5 )
{
T_1 V_6 ;
int V_7 ;
V_7 = F_2 ( V_2 , V_3 , V_5 , & V_6 , V_4 ) ;
return ( V_7 < 0 || V_6 != V_5 ) ? - V_8 : 0 ;
}
static T_2 F_3 ( struct V_1 * V_2 ,
unsigned long V_3 , T_1 V_9 )
{
T_2 V_10 = 0 ;
T_1 V_11 ;
T_3 V_4 [ 16 ] , * V_12 ;
T_1 V_13 ;
int V_7 ;
while ( V_9 > 0 ) {
V_11 = F_4 ( T_1 , V_9 , 16 ) ;
V_7 = F_2 ( V_2 , V_3 , V_11 , & V_13 , V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
V_12 = memchr ( V_4 , 0 , V_13 ) ;
if ( V_12 )
return V_10 + ( V_12 - V_4 ) ;
V_9 -= V_13 ;
V_3 += V_13 ;
V_10 += V_13 ;
}
return V_10 ;
}
static int F_5 ( struct V_1 * V_2 , unsigned long V_3 ,
const char * V_14 , T_1 V_15 )
{
T_3 V_4 [ 17 ] ;
T_1 V_13 , V_11 ;
int V_7 ;
V_4 [ 0 ] = 0xff ;
while ( V_15 > 0 ) {
V_11 = F_4 ( T_1 , V_15 + 1 , 17 ) ;
V_7 = F_2 ( V_2 , V_3 , V_11 , & V_13 , V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
V_13 -- ;
if ( memcmp ( V_4 , V_14 , V_13 ) != 0 )
return 0 ;
V_4 [ 0 ] = V_4 [ V_13 ] ;
V_15 -= V_13 ;
V_3 += V_13 ;
V_14 += V_13 ;
}
if ( V_4 [ 0 ] )
return 0 ;
return 1 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned long V_3 ,
void * V_4 , T_1 V_5 )
{
struct V_16 * V_17 ;
unsigned long V_18 ;
T_1 V_11 ;
while ( V_5 > 0 ) {
V_18 = V_3 & ( V_19 - 1 ) ;
V_11 = F_4 ( T_1 , V_5 , V_19 - V_18 ) ;
V_17 = F_7 ( V_2 , V_3 >> V_20 ) ;
if ( ! V_17 )
return - V_8 ;
memcpy ( V_4 , V_17 -> V_21 + V_18 , V_11 ) ;
F_8 ( V_17 ) ;
V_4 += V_11 ;
V_5 -= V_11 ;
V_3 += V_11 ;
}
return 0 ;
}
static T_2 F_9 ( struct V_1 * V_2 ,
unsigned long V_3 , T_1 V_22 )
{
struct V_16 * V_17 ;
unsigned long V_18 ;
T_2 V_10 = 0 ;
T_1 V_11 ;
T_3 * V_4 , * V_12 ;
while ( V_22 > 0 ) {
V_18 = V_3 & ( V_19 - 1 ) ;
V_11 = F_4 ( T_1 , V_22 , V_19 - V_18 ) ;
V_17 = F_7 ( V_2 , V_3 >> V_20 ) ;
if ( ! V_17 )
return - V_8 ;
V_4 = V_17 -> V_21 + V_18 ;
V_12 = memchr ( V_4 , 0 , V_11 ) ;
F_8 ( V_17 ) ;
if ( V_12 )
return V_10 + ( V_12 - V_4 ) ;
V_22 -= V_11 ;
V_3 += V_11 ;
V_10 += V_11 ;
}
return V_10 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned long V_3 ,
const char * V_14 , T_1 V_15 )
{
struct V_16 * V_17 ;
unsigned long V_18 ;
T_1 V_11 ;
bool V_23 , V_24 = false ;
while ( V_15 > 0 ) {
V_18 = V_3 & ( V_19 - 1 ) ;
V_11 = F_4 ( T_1 , V_15 , V_19 - V_18 ) ;
V_17 = F_7 ( V_2 , V_3 >> V_20 ) ;
if ( ! V_17 )
return - V_8 ;
V_23 = ( memcmp ( V_17 -> V_21 + V_18 , V_14 , V_11 ) == 0 ) ;
V_15 -= V_11 ;
V_3 += V_11 ;
V_14 += V_11 ;
if ( V_23 && V_15 == 0 && V_18 + V_11 < V_19 ) {
if ( ! V_17 -> V_21 [ V_18 + V_11 ] )
V_24 = true ;
else
V_23 = false ;
}
F_8 ( V_17 ) ;
if ( ! V_23 )
return 0 ;
}
if ( ! V_24 ) {
F_11 ( ( V_3 & ( V_19 - 1 ) ) != 0 ) ;
V_17 = F_7 ( V_2 , V_3 >> V_20 ) ;
if ( ! V_17 )
return - V_8 ;
V_23 = ! V_17 -> V_21 [ 0 ] ;
F_8 ( V_17 ) ;
if ( ! V_23 )
return 0 ;
}
return 1 ;
}
int F_12 ( struct V_1 * V_2 , unsigned long V_3 ,
void * V_4 , T_1 V_5 )
{
T_1 V_22 ;
V_22 = F_13 ( V_2 ) ;
if ( V_3 >= V_22 )
return - V_8 ;
if ( V_5 > V_22 - V_3 )
V_5 = V_22 - V_3 ;
#ifdef F_14
if ( V_2 -> V_25 )
return F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
#endif
#ifdef F_15
if ( V_2 -> V_26 )
return F_6 ( V_2 , V_3 , V_4 , V_5 ) ;
#endif
return - V_8 ;
}
T_2 F_16 ( struct V_1 * V_2 ,
unsigned long V_3 , T_1 V_9 )
{
T_1 V_22 ;
V_22 = F_13 ( V_2 ) ;
if ( V_3 >= V_22 )
return - V_8 ;
if ( V_9 > V_22 - V_3 )
V_9 = V_22 - V_3 ;
#ifdef F_14
if ( V_2 -> V_25 )
return F_3 ( V_2 , V_3 , V_9 ) ;
#endif
#ifdef F_15
if ( V_2 -> V_26 )
return F_9 ( V_2 , V_3 , V_9 ) ;
#endif
return - V_8 ;
}
int F_17 ( struct V_1 * V_2 , unsigned long V_3 ,
const char * V_14 , T_1 V_15 )
{
T_1 V_22 ;
V_22 = F_13 ( V_2 ) ;
if ( V_3 >= V_22 )
return - V_8 ;
if ( V_15 > V_27 )
return - V_28 ;
if ( V_15 + 1 > V_22 - V_3 )
return - V_8 ;
#ifdef F_14
if ( V_2 -> V_25 )
return F_5 ( V_2 , V_3 , V_14 , V_15 ) ;
#endif
#ifdef F_15
if ( V_2 -> V_26 )
return F_10 ( V_2 , V_3 , V_14 , V_15 ) ;
#endif
return - V_8 ;
}
