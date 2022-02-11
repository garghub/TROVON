int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned int V_5 = F_2 ( V_4 ) ;
int V_6 ;
V_6 = F_3 ( V_2 , V_4 -> V_7 , V_5 ) ;
if ( ! V_6 )
F_4 ( V_4 ) ;
return V_6 ;
}
int F_5 ( struct V_3 * V_4 , const char * V_8 , ... )
{
unsigned int V_5 = F_6 ( V_4 ) ;
T_1 V_9 ;
int V_6 ;
if ( V_4 -> V_10 || ! V_5 )
return 0 ;
va_start ( V_9 , V_8 ) ;
V_6 = vsnprintf ( V_4 -> V_7 + V_4 -> V_5 , V_5 , V_8 , V_9 ) ;
va_end ( V_9 ) ;
if ( V_6 >= V_5 ) {
V_4 -> V_10 = 1 ;
return 0 ;
}
V_4 -> V_5 += V_6 ;
return 1 ;
}
int F_7 ( struct V_3 * V_4 , const unsigned long * V_11 ,
int V_12 )
{
unsigned int V_5 = F_6 ( V_4 ) ;
int V_6 ;
if ( V_4 -> V_10 || ! V_5 )
return 0 ;
V_6 = F_8 ( V_4 -> V_7 , V_5 , V_11 , V_12 ) ;
V_4 -> V_5 += V_6 ;
return 1 ;
}
int F_9 ( struct V_3 * V_4 , const char * V_8 , T_1 args )
{
unsigned int V_5 = F_6 ( V_4 ) ;
int V_6 ;
if ( V_4 -> V_10 || ! V_5 )
return 0 ;
V_6 = vsnprintf ( V_4 -> V_7 + V_4 -> V_5 , V_5 , V_8 , args ) ;
if ( V_6 >= V_5 ) {
V_4 -> V_10 = 1 ;
return 0 ;
}
V_4 -> V_5 += V_6 ;
return V_5 ;
}
int F_10 ( struct V_3 * V_4 , const char * V_8 , const T_2 * V_13 )
{
unsigned int V_5 = F_6 ( V_4 ) ;
int V_6 ;
if ( V_4 -> V_10 || ! V_5 )
return 0 ;
V_6 = F_11 ( V_4 -> V_7 + V_4 -> V_5 , V_5 , V_8 , V_13 ) ;
if ( V_6 >= V_5 ) {
V_4 -> V_10 = 1 ;
return 0 ;
}
V_4 -> V_5 += V_6 ;
return V_5 ;
}
int F_12 ( struct V_3 * V_4 , const char * V_14 )
{
unsigned int V_5 = strlen ( V_14 ) ;
if ( V_4 -> V_10 )
return 0 ;
if ( V_5 > F_6 ( V_4 ) ) {
V_4 -> V_10 = 1 ;
return 0 ;
}
memcpy ( V_4 -> V_7 + V_4 -> V_5 , V_14 , V_5 ) ;
V_4 -> V_5 += V_5 ;
return V_5 ;
}
int F_13 ( struct V_3 * V_4 , unsigned char V_15 )
{
if ( V_4 -> V_10 )
return 0 ;
if ( F_6 ( V_4 ) < 1 ) {
V_4 -> V_10 = 1 ;
return 0 ;
}
V_4 -> V_7 [ V_4 -> V_5 ++ ] = V_15 ;
return 1 ;
}
int F_14 ( struct V_3 * V_4 , const void * V_16 , unsigned int V_5 )
{
if ( V_4 -> V_10 )
return 0 ;
if ( V_5 > F_6 ( V_4 ) ) {
V_4 -> V_10 = 1 ;
return 0 ;
}
memcpy ( V_4 -> V_7 + V_4 -> V_5 , V_16 , V_5 ) ;
V_4 -> V_5 += V_5 ;
return V_5 ;
}
int F_15 ( struct V_3 * V_4 , const struct V_17 * V_17 )
{
unsigned char * V_18 ;
if ( V_4 -> V_10 )
return 0 ;
if ( F_6 ( V_4 ) < 1 ) {
V_4 -> V_10 = 1 ;
return 0 ;
}
V_18 = F_16 ( V_17 , V_4 -> V_7 + V_4 -> V_5 , V_19 - V_4 -> V_5 ) ;
if ( ! F_17 ( V_18 ) ) {
V_18 = F_18 ( V_4 -> V_7 + V_4 -> V_5 , V_18 , L_1 ) ;
if ( V_18 ) {
V_4 -> V_5 = V_18 - V_4 -> V_7 ;
return 1 ;
}
} else {
V_4 -> V_7 [ V_4 -> V_5 ++ ] = '?' ;
return 1 ;
}
V_4 -> V_10 = 1 ;
return 0 ;
}
int F_19 ( struct V_3 * V_4 , char T_3 * V_20 , int V_21 )
{
int V_5 ;
int V_6 ;
if ( ! V_21 )
return 0 ;
if ( V_4 -> V_5 <= V_4 -> V_22 )
return - V_23 ;
V_5 = V_4 -> V_5 - V_4 -> V_22 ;
if ( V_21 > V_5 )
V_21 = V_5 ;
V_6 = F_20 ( V_20 , V_4 -> V_7 + V_4 -> V_22 , V_21 ) ;
if ( V_6 == V_21 )
return - V_24 ;
V_21 -= V_6 ;
V_4 -> V_22 += V_21 ;
return V_21 ;
}
