static bool F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return V_2 -> V_3 + V_3 <= V_2 -> V_4 ;
}
int F_2 ( struct V_5 * V_6 , struct V_1 * V_2 )
{
unsigned int V_3 = F_3 ( V_2 ) ;
return F_4 ( V_6 , V_2 -> V_7 , V_3 ) ;
}
int F_5 ( struct V_1 * V_2 , const char * V_8 , T_2 args )
{
int V_3 ;
F_6 ( V_2 -> V_4 == 0 ) ;
if ( V_2 -> V_3 < V_2 -> V_4 ) {
V_3 = vsnprintf ( V_2 -> V_7 + V_2 -> V_3 , V_2 -> V_4 - V_2 -> V_3 , V_8 , args ) ;
if ( F_1 ( V_2 , V_3 ) ) {
V_2 -> V_3 += V_3 ;
return 0 ;
}
}
F_7 ( V_2 ) ;
return - 1 ;
}
int F_8 ( struct V_1 * V_2 , const char * V_8 , ... )
{
T_2 V_9 ;
int V_10 ;
va_start ( V_9 , V_8 ) ;
V_10 = F_5 ( V_2 , V_8 , V_9 ) ;
va_end ( V_9 ) ;
return V_10 ;
}
int F_9 ( struct V_1 * V_2 , const unsigned long * V_11 ,
int V_12 )
{
unsigned int V_3 = F_10 ( V_2 ) ;
int V_10 ;
F_6 ( V_2 -> V_4 == 0 ) ;
if ( V_3 > 1 ) {
V_10 = F_11 ( V_2 -> V_7 + V_2 -> V_3 , V_3 , V_11 , V_12 ) ;
if ( V_10 < V_3 ) {
V_2 -> V_3 += V_10 ;
return 0 ;
}
}
F_7 ( V_2 ) ;
return - 1 ;
}
int F_12 ( struct V_1 * V_2 , const char * V_8 , const T_3 * V_13 )
{
unsigned int V_3 = F_10 ( V_2 ) ;
int V_10 ;
F_6 ( V_2 -> V_4 == 0 ) ;
if ( V_2 -> V_3 < V_2 -> V_4 ) {
V_10 = F_13 ( V_2 -> V_7 + V_2 -> V_3 , V_3 , V_8 , V_13 ) ;
if ( F_1 ( V_2 , V_10 ) ) {
V_2 -> V_3 += V_10 ;
return 0 ;
}
}
F_7 ( V_2 ) ;
return - 1 ;
}
int F_14 ( struct V_1 * V_2 , const char * V_14 )
{
unsigned int V_3 = strlen ( V_14 ) ;
F_6 ( V_2 -> V_4 == 0 ) ;
if ( F_1 ( V_2 , V_3 ) ) {
memcpy ( V_2 -> V_7 + V_2 -> V_3 , V_14 , V_3 ) ;
V_2 -> V_3 += V_3 ;
return 0 ;
}
F_7 ( V_2 ) ;
return - 1 ;
}
int F_15 ( struct V_1 * V_2 , unsigned char V_15 )
{
F_6 ( V_2 -> V_4 == 0 ) ;
if ( F_1 ( V_2 , 1 ) ) {
V_2 -> V_7 [ V_2 -> V_3 ++ ] = V_15 ;
return 0 ;
}
F_7 ( V_2 ) ;
return - 1 ;
}
int F_16 ( struct V_1 * V_2 , const void * V_16 , unsigned int V_3 )
{
F_6 ( V_2 -> V_4 == 0 ) ;
if ( F_1 ( V_2 , V_3 ) ) {
memcpy ( V_2 -> V_7 + V_2 -> V_3 , V_16 , V_3 ) ;
V_2 -> V_3 += V_3 ;
return 0 ;
}
F_7 ( V_2 ) ;
return - 1 ;
}
int F_17 ( struct V_1 * V_2 , const struct V_17 * V_17 , const char * V_18 )
{
char * V_19 ;
T_1 V_4 = F_18 ( V_2 , & V_19 ) ;
int V_20 = - 1 ;
F_6 ( V_2 -> V_4 == 0 ) ;
if ( V_4 ) {
char * V_21 = F_19 ( V_17 , V_19 , V_4 ) ;
if ( ! F_20 ( V_21 ) ) {
char * V_22 = F_21 ( V_19 , V_21 , V_18 ) ;
if ( V_22 )
V_20 = V_22 - V_19 ;
}
}
F_22 ( V_2 , V_20 ) ;
return V_20 ;
}
int F_23 ( struct V_1 * V_2 , char T_4 * V_23 , int V_24 )
{
int V_3 ;
int V_10 ;
if ( ! V_24 )
return 0 ;
if ( V_2 -> V_3 <= V_2 -> V_25 )
return - V_26 ;
V_3 = F_3 ( V_2 ) - V_2 -> V_25 ;
if ( V_24 > V_3 )
V_24 = V_3 ;
V_10 = F_24 ( V_23 , V_2 -> V_7 + V_2 -> V_25 , V_24 ) ;
if ( V_10 == V_24 )
return - V_27 ;
V_24 -= V_10 ;
V_2 -> V_25 += V_24 ;
return V_24 ;
}
