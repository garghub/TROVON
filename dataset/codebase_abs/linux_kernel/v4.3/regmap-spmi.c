static int F_1 ( void * V_1 ,
const void * V_2 , T_1 V_3 ,
void * V_4 , T_1 V_5 )
{
T_2 V_6 = * ( T_2 * ) V_2 ;
int V_7 = 0 ;
F_2 ( V_3 != 1 ) ;
while ( V_5 -- && ! V_7 )
V_7 = F_3 ( V_1 , V_6 ++ , V_4 ++ ) ;
return V_7 ;
}
static int F_4 ( void * V_1 ,
const void * V_2 , T_1 V_3 ,
const void * V_4 , T_1 V_5 )
{
const T_2 * V_8 = V_4 ;
T_2 V_6 = * ( T_2 * ) V_2 ;
int V_7 = 0 ;
F_2 ( V_3 != 1 ) ;
if ( V_6 == 0 && V_5 ) {
V_7 = F_5 ( V_1 , * V_8 ) ;
if ( V_7 )
goto V_9;
V_8 ++ ;
V_6 ++ ;
V_5 -- ;
}
while ( V_5 ) {
V_7 = F_6 ( V_1 , V_6 , * V_8 ) ;
if ( V_7 )
goto V_9;
V_8 ++ ;
V_6 ++ ;
V_5 -- ;
}
V_9:
return V_7 ;
}
static int F_7 ( void * V_1 , const void * V_8 ,
T_1 V_10 )
{
F_2 ( V_10 < 1 ) ;
return F_4 ( V_1 , V_8 , 1 , V_8 + 1 ,
V_10 - 1 ) ;
}
struct V_11 * F_8 ( struct V_12 * V_13 ,
const struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 )
{
return F_9 ( & V_13 -> V_19 , & V_20 , V_13 , V_15 ,
V_17 , V_18 ) ;
}
struct V_11 * F_10 ( struct V_12 * V_13 ,
const struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 )
{
return F_11 ( & V_13 -> V_19 , & V_20 , V_13 , V_15 ,
V_17 , V_18 ) ;
}
static int F_12 ( void * V_1 ,
const void * V_2 , T_1 V_3 ,
void * V_4 , T_1 V_5 )
{
int V_7 = 0 ;
T_1 V_21 ;
T_3 V_6 ;
F_2 ( V_3 != 2 ) ;
V_6 = * ( T_3 * ) V_2 ;
while ( V_6 <= 0xFF && V_5 ) {
V_21 = F_13 ( T_1 , V_5 , 16 ) ;
V_7 = F_14 ( V_1 , V_6 , V_4 , V_21 ) ;
if ( V_7 )
goto V_9;
V_6 += V_21 ;
V_4 += V_21 ;
V_5 -= V_21 ;
}
while ( V_5 ) {
V_21 = F_13 ( T_1 , V_5 , 8 ) ;
V_7 = F_15 ( V_1 , V_6 , V_4 , V_5 ) ;
if ( V_7 )
goto V_9;
V_6 += V_21 ;
V_4 += V_21 ;
V_5 -= V_21 ;
}
V_9:
return V_7 ;
}
static int F_16 ( void * V_1 ,
const void * V_2 , T_1 V_3 ,
const void * V_4 , T_1 V_5 )
{
int V_7 = 0 ;
T_1 V_21 ;
T_3 V_6 ;
F_2 ( V_3 != 2 ) ;
V_6 = * ( T_3 * ) V_2 ;
while ( V_6 <= 0xFF && V_5 ) {
V_21 = F_13 ( T_1 , V_5 , 16 ) ;
V_7 = F_17 ( V_1 , V_6 , V_4 , V_21 ) ;
if ( V_7 )
goto V_9;
V_6 += V_21 ;
V_4 += V_21 ;
V_5 -= V_21 ;
}
while ( V_5 ) {
V_21 = F_13 ( T_1 , V_5 , 8 ) ;
V_7 = F_18 ( V_1 , V_6 , V_4 , V_21 ) ;
if ( V_7 )
goto V_9;
V_6 += V_21 ;
V_4 += V_21 ;
V_5 -= V_21 ;
}
V_9:
return V_7 ;
}
static int F_19 ( void * V_1 , const void * V_8 ,
T_1 V_10 )
{
F_2 ( V_10 < 2 ) ;
return F_16 ( V_1 , V_8 , 2 , V_8 + 2 ,
V_10 - 2 ) ;
}
struct V_11 * F_20 ( struct V_12 * V_13 ,
const struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 )
{
return F_9 ( & V_13 -> V_19 , & V_22 , V_13 , V_15 ,
V_17 , V_18 ) ;
}
struct V_11 * F_21 ( struct V_12 * V_13 ,
const struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 )
{
return F_11 ( & V_13 -> V_19 , & V_22 , V_13 , V_15 ,
V_17 , V_18 ) ;
}
