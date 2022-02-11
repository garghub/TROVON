int F_1 ( struct V_1 * V_1 , const void * V_2 , T_1 V_3 )
{
struct V_4 * V_5 ;
int V_6 ;
V_6 = - V_7 ;
if ( V_3 <= 0 || V_3 > 32767 || ! V_2 )
goto error;
V_6 = F_2 ( V_1 , V_3 ) ;
if ( V_6 < 0 )
goto error;
V_6 = - V_8 ;
V_5 = F_3 ( sizeof( * V_5 ) + V_3 , V_9 ) ;
if ( ! V_5 )
goto error;
V_5 -> V_3 = V_3 ;
memcpy ( V_5 -> V_2 , V_2 , V_3 ) ;
F_4 ( V_1 -> V_10 . V_2 , V_5 ) ;
V_6 = 0 ;
error:
return V_6 ;
}
int F_5 ( struct V_1 * V_1 , const void * V_2 , T_1 V_3 )
{
struct V_4 * V_5 , * V_11 ;
int V_6 ;
V_6 = - V_7 ;
if ( V_3 <= 0 || V_3 > 32767 || ! V_2 )
goto error;
V_6 = - V_8 ;
V_5 = F_3 ( sizeof( * V_5 ) + V_3 , V_9 ) ;
if ( ! V_5 )
goto error;
V_5 -> V_3 = V_3 ;
memcpy ( V_5 -> V_2 , V_2 , V_3 ) ;
V_11 = V_5 ;
V_6 = F_2 ( V_1 , V_3 ) ;
if ( V_6 == 0 ) {
V_11 = V_1 -> V_10 . V_2 ;
F_4 ( V_1 -> V_10 . V_2 , V_5 ) ;
V_1 -> V_12 = 0 ;
}
if ( V_11 )
F_6 ( V_11 , V_13 ) ;
error:
return V_6 ;
}
int F_7 ( const struct V_1 * V_1 , const void * V_14 )
{
return strcmp ( V_1 -> V_14 , V_14 ) == 0 ;
}
void F_8 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = V_1 -> V_10 . V_2 ;
F_2 ( V_1 , 0 ) ;
if ( V_5 ) {
F_4 ( V_1 -> V_10 . V_2 , NULL ) ;
F_6 ( V_5 , V_13 ) ;
}
}
void F_9 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = V_1 -> V_10 . V_2 ;
F_10 ( V_5 ) ;
}
void F_11 ( const struct V_1 * V_1 , struct V_15 * V_16 )
{
F_12 ( V_16 , V_1 -> V_14 ) ;
if ( F_13 ( V_1 ) )
F_14 ( V_16 , L_1 , V_1 -> V_3 ) ;
}
long F_15 ( const struct V_1 * V_1 , char T_2 * V_17 , T_1 V_18 )
{
struct V_4 * V_5 ;
long V_6 ;
V_5 = F_16 ( V_1 ) ;
V_6 = V_5 -> V_3 ;
if ( V_17 && V_18 > 0 ) {
if ( V_18 > V_5 -> V_3 )
V_18 = V_5 -> V_3 ;
if ( F_17 ( V_17 , V_5 -> V_2 , V_18 ) != 0 )
V_6 = - V_19 ;
}
return V_6 ;
}
