int F_1 ( const char * V_1 , const char * V_2 )
{
for (; ; V_1 ++ , V_2 ++ )
if ( ! * V_2 )
return 0 ;
else if ( * V_1 != * V_2 )
return ( unsigned char ) * V_2 - ( unsigned char ) * V_1 ;
}
int F_2 ( struct V_3 * V_4 , T_1 V_5 )
{
V_4 -> V_6 = V_4 -> V_7 = 0 ;
V_4 -> V_8 = V_9 ;
if ( V_5 )
return F_3 ( V_4 , V_5 ) ;
return 0 ;
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
int F_3 ( struct V_3 * V_4 , T_2 V_12 )
{
char * V_8 ;
T_2 V_13 = V_4 -> V_7 + V_12 + 1 ;
if ( V_13 < V_4 -> V_6 )
return 0 ;
if ( V_13 <= V_4 -> V_7 )
return - V_14 ;
if ( F_7 ( V_4 -> V_6 ) > V_13 )
V_13 = F_7 ( V_4 -> V_6 ) ;
V_8 = realloc ( V_4 -> V_6 ? V_4 -> V_8 : NULL , V_13 * sizeof( * V_8 ) ) ;
if ( ! V_8 )
return - V_15 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_6 = V_13 ;
return 0 ;
}
int F_8 ( struct V_3 * V_4 , int V_16 )
{
int V_17 = F_3 ( V_4 , 1 ) ;
if ( V_17 )
return V_17 ;
V_4 -> V_8 [ V_4 -> V_7 ++ ] = V_16 ;
V_4 -> V_8 [ V_4 -> V_7 ] = '\0' ;
return 0 ;
}
int F_9 ( struct V_3 * V_4 , const void * V_18 , T_2 V_7 )
{
int V_17 = F_3 ( V_4 , V_7 ) ;
if ( V_17 )
return V_17 ;
memcpy ( V_4 -> V_8 + V_4 -> V_7 , V_18 , V_7 ) ;
return F_10 ( V_4 , V_4 -> V_7 + V_7 ) ;
}
static int F_11 ( struct V_3 * V_4 , const char * V_19 , T_3 V_20 )
{
int V_7 , V_17 ;
T_3 V_21 ;
if ( ! F_12 ( V_4 ) ) {
V_17 = F_3 ( V_4 , 64 ) ;
if ( V_17 )
return V_17 ;
}
F_13 ( V_21 , V_20 ) ;
V_7 = vsnprintf ( V_4 -> V_8 + V_4 -> V_7 , V_4 -> V_6 - V_4 -> V_7 , V_19 , V_20 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_7 > F_12 ( V_4 ) ) {
V_17 = F_3 ( V_4 , V_7 ) ;
if ( V_17 )
return V_17 ;
V_7 = vsnprintf ( V_4 -> V_8 + V_4 -> V_7 , V_4 -> V_6 - V_4 -> V_7 , V_19 , V_21 ) ;
va_end ( V_21 ) ;
if ( V_7 > F_12 ( V_4 ) ) {
F_14 ( L_1 ) ;
return - V_22 ;
}
}
return F_10 ( V_4 , V_4 -> V_7 + V_7 ) ;
}
int F_15 ( struct V_3 * V_4 , const char * V_19 , ... )
{
T_3 V_20 ;
int V_17 ;
va_start ( V_20 , V_19 ) ;
V_17 = F_11 ( V_4 , V_19 , V_20 ) ;
va_end ( V_20 ) ;
return V_17 ;
}
T_1 F_16 ( struct V_3 * V_4 , int V_23 , T_1 V_5 )
{
T_2 V_24 = V_4 -> V_7 ;
T_2 V_25 = V_4 -> V_6 ;
int V_17 ;
V_17 = F_3 ( V_4 , V_5 ? V_5 : 8192 ) ;
if ( V_17 )
return V_17 ;
for (; ; ) {
T_1 V_26 ;
V_26 = F_17 ( V_23 , V_4 -> V_8 + V_4 -> V_7 , V_4 -> V_6 - V_4 -> V_7 - 1 ) ;
if ( V_26 < 0 ) {
if ( V_25 == 0 )
F_4 ( V_4 ) ;
else
F_10 ( V_4 , V_24 ) ;
return V_26 ;
}
if ( ! V_26 )
break;
V_4 -> V_7 += V_26 ;
V_17 = F_3 ( V_4 , 8192 ) ;
if ( V_17 )
return V_17 ;
}
V_4 -> V_8 [ V_4 -> V_7 ] = '\0' ;
return V_4 -> V_7 - V_24 ;
}
