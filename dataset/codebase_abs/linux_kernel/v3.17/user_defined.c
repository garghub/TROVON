int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_1 V_5 = V_2 -> V_5 ;
if ( V_5 <= 0 || V_5 > 32767 || ! V_2 -> V_6 )
return - V_7 ;
V_4 = F_2 ( sizeof( * V_4 ) + V_5 , V_8 ) ;
if ( ! V_4 )
return - V_9 ;
V_2 -> V_10 = V_5 ;
V_2 -> V_11 [ 0 ] = V_4 ;
V_4 -> V_5 = V_5 ;
memcpy ( V_4 -> V_6 , V_2 -> V_6 , V_5 ) ;
return 0 ;
}
void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_11 [ 0 ] ) ;
}
int F_5 ( struct V_12 * V_12 , struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_13 ;
T_1 V_5 = V_2 -> V_5 ;
int V_14 ;
V_14 = - V_7 ;
if ( V_5 <= 0 || V_5 > 32767 || ! V_2 -> V_6 )
goto error;
V_14 = - V_9 ;
V_4 = F_2 ( sizeof( * V_4 ) + V_5 , V_8 ) ;
if ( ! V_4 )
goto error;
V_4 -> V_5 = V_5 ;
memcpy ( V_4 -> V_6 , V_2 -> V_6 , V_5 ) ;
V_13 = V_4 ;
V_14 = F_6 ( V_12 , V_5 ) ;
if ( V_14 == 0 ) {
V_13 = V_12 -> V_11 . V_6 ;
F_7 ( V_12 , V_4 ) ;
V_12 -> V_15 = 0 ;
}
if ( V_13 )
F_8 ( V_13 , V_16 ) ;
error:
return V_14 ;
}
int F_9 ( const struct V_12 * V_12 , const void * V_17 )
{
return strcmp ( V_12 -> V_17 , V_17 ) == 0 ;
}
void F_10 ( struct V_12 * V_12 )
{
struct V_3 * V_4 = V_12 -> V_11 . V_6 ;
F_6 ( V_12 , 0 ) ;
if ( V_4 ) {
F_7 ( V_12 , NULL ) ;
F_8 ( V_4 , V_16 ) ;
}
}
void F_11 ( struct V_12 * V_12 )
{
struct V_3 * V_4 = V_12 -> V_11 . V_6 ;
F_4 ( V_4 ) ;
}
void F_12 ( const struct V_12 * V_12 , struct V_18 * V_19 )
{
F_13 ( V_19 , V_12 -> V_17 ) ;
if ( F_14 ( V_12 ) )
F_15 ( V_19 , L_1 , V_12 -> V_5 ) ;
}
long F_16 ( const struct V_12 * V_12 , char T_2 * V_20 , T_1 V_21 )
{
struct V_3 * V_4 ;
long V_14 ;
V_4 = F_17 ( V_12 ) ;
V_14 = V_4 -> V_5 ;
if ( V_20 && V_21 > 0 ) {
if ( V_21 > V_4 -> V_5 )
V_21 = V_4 -> V_5 ;
if ( F_18 ( V_20 , V_4 -> V_6 , V_21 ) != 0 )
V_14 = - V_22 ;
}
return V_14 ;
}
static int F_19 ( const char * V_23 )
{
char * V_24 ;
V_24 = strchr ( V_23 , ':' ) ;
if ( ! V_24 )
return - V_7 ;
if ( V_24 == V_23 )
return - V_7 ;
return 0 ;
}
