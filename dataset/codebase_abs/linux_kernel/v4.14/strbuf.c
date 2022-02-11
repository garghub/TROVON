int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
V_2 -> V_4 = V_2 -> V_5 = 0 ;
V_2 -> V_6 = V_7 ;
if ( V_3 )
return F_2 ( V_2 , V_3 ) ;
return 0 ;
}
void F_3 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 ) {
F_4 ( & V_2 -> V_6 ) ;
F_1 ( V_2 , 0 ) ;
}
}
char * F_5 ( struct V_1 * V_2 , T_2 * V_8 )
{
char * V_9 = V_2 -> V_4 ? V_2 -> V_6 : NULL ;
if ( V_8 )
* V_8 = V_2 -> V_5 ;
F_1 ( V_2 , 0 ) ;
return V_9 ;
}
int F_2 ( struct V_1 * V_2 , T_2 V_10 )
{
char * V_6 ;
T_2 V_11 = V_2 -> V_5 + V_10 + 1 ;
if ( V_11 < V_2 -> V_4 )
return 0 ;
if ( V_11 <= V_2 -> V_5 )
return - V_12 ;
if ( F_6 ( V_2 -> V_4 ) > V_11 )
V_11 = F_6 ( V_2 -> V_4 ) ;
V_6 = realloc ( V_2 -> V_4 ? V_2 -> V_6 : NULL , V_11 * sizeof( * V_6 ) ) ;
if ( ! V_6 )
return - V_13 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_4 = V_11 ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 , int V_14 )
{
int V_15 = F_2 ( V_2 , 1 ) ;
if ( V_15 )
return V_15 ;
V_2 -> V_6 [ V_2 -> V_5 ++ ] = V_14 ;
V_2 -> V_6 [ V_2 -> V_5 ] = '\0' ;
return 0 ;
}
int F_8 ( struct V_1 * V_2 , const void * V_16 , T_2 V_5 )
{
int V_15 = F_2 ( V_2 , V_5 ) ;
if ( V_15 )
return V_15 ;
memcpy ( V_2 -> V_6 + V_2 -> V_5 , V_16 , V_5 ) ;
return F_9 ( V_2 , V_2 -> V_5 + V_5 ) ;
}
static int F_10 ( struct V_1 * V_2 , const char * V_17 , T_3 V_18 )
{
int V_5 , V_15 ;
T_3 V_19 ;
if ( ! F_11 ( V_2 ) ) {
V_15 = F_2 ( V_2 , 64 ) ;
if ( V_15 )
return V_15 ;
}
F_12 ( V_19 , V_18 ) ;
V_5 = vsnprintf ( V_2 -> V_6 + V_2 -> V_5 , V_2 -> V_4 - V_2 -> V_5 , V_17 , V_18 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_5 > F_11 ( V_2 ) ) {
V_15 = F_2 ( V_2 , V_5 ) ;
if ( V_15 )
return V_15 ;
V_5 = vsnprintf ( V_2 -> V_6 + V_2 -> V_5 , V_2 -> V_4 - V_2 -> V_5 , V_17 , V_19 ) ;
va_end ( V_19 ) ;
if ( V_5 > F_11 ( V_2 ) ) {
F_13 ( L_1 ) ;
return - V_20 ;
}
}
return F_9 ( V_2 , V_2 -> V_5 + V_5 ) ;
}
int F_14 ( struct V_1 * V_2 , const char * V_17 , ... )
{
T_3 V_18 ;
int V_15 ;
va_start ( V_18 , V_17 ) ;
V_15 = F_10 ( V_2 , V_17 , V_18 ) ;
va_end ( V_18 ) ;
return V_15 ;
}
T_1 F_15 ( struct V_1 * V_2 , int V_21 , T_1 V_3 )
{
T_2 V_22 = V_2 -> V_5 ;
T_2 V_23 = V_2 -> V_4 ;
int V_15 ;
V_15 = F_2 ( V_2 , V_3 ? V_3 : 8192 ) ;
if ( V_15 )
return V_15 ;
for (; ; ) {
T_1 V_24 ;
V_24 = F_16 ( V_21 , V_2 -> V_6 + V_2 -> V_5 , V_2 -> V_4 - V_2 -> V_5 - 1 ) ;
if ( V_24 < 0 ) {
if ( V_23 == 0 )
F_3 ( V_2 ) ;
else
F_9 ( V_2 , V_22 ) ;
return V_24 ;
}
if ( ! V_24 )
break;
V_2 -> V_5 += V_24 ;
V_15 = F_2 ( V_2 , 8192 ) ;
if ( V_15 )
return V_15 ;
}
V_2 -> V_6 [ V_2 -> V_5 ] = '\0' ;
return V_2 -> V_5 - V_22 ;
}
