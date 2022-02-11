int F_1 ( const char * V_1 , const char * V_2 )
{
for (; ; V_1 ++ , V_2 ++ )
if ( ! * V_2 )
return 0 ;
else if ( * V_1 != * V_2 )
return ( unsigned char ) * V_2 - ( unsigned char ) * V_1 ;
}
void F_2 ( struct V_3 * V_4 , T_1 V_5 )
{
V_4 -> V_6 = V_4 -> V_7 = 0 ;
V_4 -> V_8 = V_9 ;
if ( V_5 )
F_3 ( V_4 , V_5 ) ;
}
void F_4 ( struct V_3 * V_4 )
{
if ( V_4 -> V_6 ) {
F_5 ( & V_4 -> V_8 ) ;
F_2 ( V_4 , 0 ) ;
}
}
char * F_6 ( struct V_3 * V_4 , T_2 * V_10 )
{
char * V_11 = V_4 -> V_6 ? V_4 -> V_8 : NULL ;
if ( V_10 )
* V_10 = V_4 -> V_7 ;
F_2 ( V_4 , 0 ) ;
return V_11 ;
}
void F_3 ( struct V_3 * V_4 , T_2 V_12 )
{
if ( V_4 -> V_7 + V_12 + 1 <= V_4 -> V_7 )
F_7 ( L_1 ) ;
if ( ! V_4 -> V_6 )
V_4 -> V_8 = NULL ;
F_8 ( V_4 -> V_8 , V_4 -> V_7 + V_12 + 1 , V_4 -> V_6 ) ;
}
static void F_9 ( struct V_3 * V_4 , T_2 V_13 , T_2 V_7 ,
const void * V_14 , T_2 V_15 )
{
if ( V_13 + V_7 < V_13 )
F_7 ( L_1 ) ;
if ( V_13 > V_4 -> V_7 )
F_7 ( L_2 ) ;
if ( V_13 + V_7 > V_4 -> V_7 )
F_7 ( L_3 ) ;
if ( V_15 >= V_7 )
F_3 ( V_4 , V_15 - V_7 ) ;
memmove ( V_4 -> V_8 + V_13 + V_15 ,
V_4 -> V_8 + V_13 + V_7 ,
V_4 -> V_7 - V_13 - V_7 ) ;
memcpy ( V_4 -> V_8 + V_13 , V_14 , V_15 ) ;
F_10 ( V_4 , V_4 -> V_7 + V_15 - V_7 ) ;
}
void F_11 ( struct V_3 * V_4 , T_2 V_13 , T_2 V_7 )
{
F_9 ( V_4 , V_13 , V_7 , NULL , 0 ) ;
}
void F_12 ( struct V_3 * V_4 , const void * V_14 , T_2 V_7 )
{
F_3 ( V_4 , V_7 ) ;
memcpy ( V_4 -> V_8 + V_4 -> V_7 , V_14 , V_7 ) ;
F_10 ( V_4 , V_4 -> V_7 + V_7 ) ;
}
void F_13 ( struct V_3 * V_4 , const char * V_16 , T_3 V_17 )
{
int V_7 ;
T_3 V_18 ;
if ( ! F_14 ( V_4 ) )
F_3 ( V_4 , 64 ) ;
F_15 ( V_18 , V_17 ) ;
V_7 = vsnprintf ( V_4 -> V_8 + V_4 -> V_7 , V_4 -> V_6 - V_4 -> V_7 , V_16 , V_17 ) ;
if ( V_7 < 0 )
F_7 ( L_4 ) ;
if ( V_7 > F_14 ( V_4 ) ) {
F_3 ( V_4 , V_7 ) ;
V_7 = vsnprintf ( V_4 -> V_8 + V_4 -> V_7 , V_4 -> V_6 - V_4 -> V_7 , V_16 , V_18 ) ;
va_end ( V_18 ) ;
if ( V_7 > F_14 ( V_4 ) ) {
F_7 ( L_5 ) ;
}
}
F_10 ( V_4 , V_4 -> V_7 + V_7 ) ;
}
void F_16 ( struct V_3 * V_4 , const char * V_16 , ... )
{
T_3 V_17 ;
va_start ( V_17 , V_16 ) ;
F_13 ( V_4 , V_16 , V_17 ) ;
va_end ( V_17 ) ;
}
T_1 F_17 ( struct V_3 * V_4 , int V_19 , T_1 V_5 )
{
T_2 V_20 = V_4 -> V_7 ;
T_2 V_21 = V_4 -> V_6 ;
F_3 ( V_4 , V_5 ? V_5 : 8192 ) ;
for (; ; ) {
T_1 V_22 ;
V_22 = F_18 ( V_19 , V_4 -> V_8 + V_4 -> V_7 , V_4 -> V_6 - V_4 -> V_7 - 1 ) ;
if ( V_22 < 0 ) {
if ( V_21 == 0 )
F_4 ( V_4 ) ;
else
F_10 ( V_4 , V_20 ) ;
return - 1 ;
}
if ( ! V_22 )
break;
V_4 -> V_7 += V_22 ;
F_3 ( V_4 , 8192 ) ;
}
V_4 -> V_8 [ V_4 -> V_7 ] = '\0' ;
return V_4 -> V_7 - V_20 ;
}
