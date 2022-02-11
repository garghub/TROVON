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
if ( V_2 -> V_3 + V_3 < V_2 -> V_4 ) {
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
int F_9 ( struct V_1 * V_2 , const char * V_8 , const T_3 * V_11 )
{
unsigned int V_3 = F_10 ( V_2 ) ;
int V_10 ;
F_6 ( V_2 -> V_4 == 0 ) ;
if ( V_2 -> V_3 < V_2 -> V_4 ) {
V_10 = F_11 ( V_2 -> V_7 + V_2 -> V_3 , V_3 , V_8 , V_11 ) ;
if ( V_2 -> V_3 + V_10 < V_2 -> V_4 ) {
V_2 -> V_3 += V_10 ;
return 0 ;
}
}
F_7 ( V_2 ) ;
return - 1 ;
}
int F_12 ( struct V_1 * V_2 , const char * V_12 )
{
unsigned int V_3 = strlen ( V_12 ) ;
F_6 ( V_2 -> V_4 == 0 ) ;
if ( F_1 ( V_2 , V_3 ) ) {
memcpy ( V_2 -> V_7 + V_2 -> V_3 , V_12 , V_3 ) ;
V_2 -> V_3 += V_3 ;
return 0 ;
}
F_7 ( V_2 ) ;
return - 1 ;
}
int F_13 ( struct V_1 * V_2 , unsigned char V_13 )
{
F_6 ( V_2 -> V_4 == 0 ) ;
if ( F_1 ( V_2 , 1 ) ) {
V_2 -> V_7 [ V_2 -> V_3 ++ ] = V_13 ;
return 0 ;
}
F_7 ( V_2 ) ;
return - 1 ;
}
int F_14 ( struct V_1 * V_2 , const void * V_14 , unsigned int V_3 )
{
F_6 ( V_2 -> V_4 == 0 ) ;
if ( F_1 ( V_2 , V_3 ) ) {
memcpy ( V_2 -> V_7 + V_2 -> V_3 , V_14 , V_3 ) ;
V_2 -> V_3 += V_3 ;
return 0 ;
}
F_7 ( V_2 ) ;
return - 1 ;
}
int F_15 ( struct V_1 * V_2 , const struct V_15 * V_15 , const char * V_16 )
{
char * V_17 ;
T_1 V_4 = F_16 ( V_2 , & V_17 ) ;
int V_18 = - 1 ;
F_6 ( V_2 -> V_4 == 0 ) ;
if ( V_4 ) {
char * V_19 = F_17 ( V_15 , V_17 , V_4 ) ;
if ( ! F_18 ( V_19 ) ) {
char * V_20 = F_19 ( V_17 , V_19 , V_16 ) ;
if ( V_20 )
V_18 = V_20 - V_17 ;
}
}
F_20 ( V_2 , V_18 ) ;
return V_18 ;
}
int F_21 ( struct V_1 * V_2 , char T_4 * V_21 , int V_22 )
{
int V_3 ;
int V_10 ;
if ( ! V_22 )
return 0 ;
V_3 = F_3 ( V_2 ) ;
if ( V_3 <= V_2 -> V_23 )
return - V_24 ;
V_3 -= V_2 -> V_23 ;
if ( V_22 > V_3 )
V_22 = V_3 ;
V_10 = F_22 ( V_21 , V_2 -> V_7 + V_2 -> V_23 , V_22 ) ;
if ( V_10 == V_22 )
return - V_25 ;
V_22 -= V_10 ;
V_2 -> V_23 += V_22 ;
return V_22 ;
}
