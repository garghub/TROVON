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
V_2 -> V_11 . V_6 [ 0 ] = V_4 ;
V_4 -> V_5 = V_5 ;
memcpy ( V_4 -> V_6 , V_2 -> V_6 , V_5 ) ;
return 0 ;
}
void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_11 . V_6 [ 0 ] ) ;
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
if ( ! F_7 ( V_15 , & V_12 -> V_16 ) )
V_13 = V_12 -> V_11 . V_6 [ 0 ] ;
else
V_13 = NULL ;
F_8 ( V_12 , V_4 ) ;
V_12 -> V_17 = 0 ;
}
if ( V_13 )
F_9 ( V_13 , V_18 ) ;
error:
return V_14 ;
}
void F_10 ( struct V_12 * V_12 )
{
struct V_3 * V_4 = V_12 -> V_11 . V_6 [ 0 ] ;
F_6 ( V_12 , 0 ) ;
if ( V_4 ) {
F_8 ( V_12 , NULL ) ;
F_9 ( V_4 , V_18 ) ;
}
}
void F_11 ( struct V_12 * V_12 )
{
struct V_3 * V_4 = V_12 -> V_11 . V_6 [ 0 ] ;
F_4 ( V_4 ) ;
}
void F_12 ( const struct V_12 * V_12 , struct V_19 * V_20 )
{
F_13 ( V_20 , V_12 -> V_21 ) ;
if ( F_14 ( V_12 ) )
F_15 ( V_20 , L_1 , V_12 -> V_5 ) ;
}
long F_16 ( const struct V_12 * V_12 , char T_2 * V_22 , T_1 V_23 )
{
const struct V_3 * V_4 ;
long V_14 ;
V_4 = V_3 ( V_12 ) ;
V_14 = V_4 -> V_5 ;
if ( V_22 && V_23 > 0 ) {
if ( V_23 > V_4 -> V_5 )
V_23 = V_4 -> V_5 ;
if ( F_17 ( V_22 , V_4 -> V_6 , V_23 ) != 0 )
V_14 = - V_24 ;
}
return V_14 ;
}
static int F_18 ( const char * V_25 )
{
char * V_26 ;
V_26 = strchr ( V_25 , ':' ) ;
if ( ! V_26 )
return - V_7 ;
if ( V_26 == V_25 )
return - V_7 ;
return 0 ;
}
