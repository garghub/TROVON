int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
T_1 V_6 = V_3 -> V_6 ;
int V_7 ;
V_7 = - V_8 ;
if ( V_6 <= 0 || V_6 > 32767 || ! V_3 -> V_9 )
goto error;
V_7 = F_2 ( V_1 , V_6 ) ;
if ( V_7 < 0 )
goto error;
V_7 = - V_10 ;
V_5 = F_3 ( sizeof( * V_5 ) + V_6 , V_11 ) ;
if ( ! V_5 )
goto error;
V_5 -> V_6 = V_6 ;
memcpy ( V_5 -> V_9 , V_3 -> V_9 , V_6 ) ;
F_4 ( V_1 , V_5 ) ;
V_7 = 0 ;
error:
return V_7 ;
}
int F_5 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 , * V_12 ;
T_1 V_6 = V_3 -> V_6 ;
int V_7 ;
V_7 = - V_8 ;
if ( V_6 <= 0 || V_6 > 32767 || ! V_3 -> V_9 )
goto error;
V_7 = - V_10 ;
V_5 = F_3 ( sizeof( * V_5 ) + V_6 , V_11 ) ;
if ( ! V_5 )
goto error;
V_5 -> V_6 = V_6 ;
memcpy ( V_5 -> V_9 , V_3 -> V_9 , V_6 ) ;
V_12 = V_5 ;
V_7 = F_2 ( V_1 , V_6 ) ;
if ( V_7 == 0 ) {
V_12 = V_1 -> V_13 . V_9 ;
F_4 ( V_1 , V_5 ) ;
V_1 -> V_14 = 0 ;
}
if ( V_12 )
F_6 ( V_12 , V_15 ) ;
error:
return V_7 ;
}
int F_7 ( const struct V_1 * V_1 , const void * V_16 )
{
return strcmp ( V_1 -> V_16 , V_16 ) == 0 ;
}
void F_8 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = V_1 -> V_13 . V_9 ;
F_2 ( V_1 , 0 ) ;
if ( V_5 ) {
F_4 ( V_1 , NULL ) ;
F_6 ( V_5 , V_15 ) ;
}
}
void F_9 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = V_1 -> V_13 . V_9 ;
F_10 ( V_5 ) ;
}
void F_11 ( const struct V_1 * V_1 , struct V_17 * V_18 )
{
F_12 ( V_18 , V_1 -> V_16 ) ;
if ( F_13 ( V_1 ) )
F_14 ( V_18 , L_1 , V_1 -> V_6 ) ;
}
long F_15 ( const struct V_1 * V_1 , char T_2 * V_19 , T_1 V_20 )
{
struct V_4 * V_5 ;
long V_7 ;
V_5 = F_16 ( V_1 ) ;
V_7 = V_5 -> V_6 ;
if ( V_19 && V_20 > 0 ) {
if ( V_20 > V_5 -> V_6 )
V_20 = V_5 -> V_6 ;
if ( F_17 ( V_19 , V_5 -> V_9 , V_20 ) != 0 )
V_7 = - V_21 ;
}
return V_7 ;
}
static int F_18 ( const char * V_22 )
{
char * V_23 ;
V_23 = strchr ( V_22 , ':' ) ;
if ( ! V_23 )
return - V_8 ;
if ( V_23 == V_22 )
return - V_8 ;
return 0 ;
}
