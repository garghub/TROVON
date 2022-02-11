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
static void F_5 ( struct V_12 * V_13 )
{
struct V_3 * V_11 ;
V_11 = F_6 ( V_13 , struct V_3 , V_14 ) ;
F_4 ( V_11 ) ;
}
int F_7 ( struct V_15 * V_15 , struct V_1 * V_2 )
{
struct V_3 * V_16 = NULL ;
int V_17 ;
V_17 = F_8 ( V_15 , V_2 -> V_5 ) ;
if ( V_17 < 0 )
return V_17 ;
V_15 -> V_18 = V_2 -> V_18 ;
if ( ! F_9 ( V_19 , & V_15 -> V_20 ) )
V_16 = F_10 ( V_15 ) ;
F_11 ( V_15 , V_2 -> V_11 . V_6 [ 0 ] ) ;
V_2 -> V_11 . V_6 [ 0 ] = NULL ;
if ( V_16 )
F_12 ( & V_16 -> V_14 , F_5 ) ;
return V_17 ;
}
void F_13 ( struct V_15 * V_15 )
{
struct V_3 * V_4 = F_14 ( V_15 ) ;
F_8 ( V_15 , 0 ) ;
if ( V_4 ) {
F_11 ( V_15 , NULL ) ;
F_12 ( & V_4 -> V_14 , F_5 ) ;
}
}
void F_15 ( struct V_15 * V_15 )
{
struct V_3 * V_4 = V_15 -> V_11 . V_6 [ 0 ] ;
F_4 ( V_4 ) ;
}
void F_16 ( const struct V_15 * V_15 , struct V_21 * V_22 )
{
F_17 ( V_22 , V_15 -> V_23 ) ;
if ( F_18 ( V_15 ) )
F_19 ( V_22 , L_1 , V_15 -> V_5 ) ;
}
long F_20 ( const struct V_15 * V_15 , char T_2 * V_24 , T_1 V_25 )
{
const struct V_3 * V_4 ;
long V_17 ;
V_4 = F_14 ( V_15 ) ;
V_17 = V_4 -> V_5 ;
if ( V_24 && V_25 > 0 ) {
if ( V_25 > V_4 -> V_5 )
V_25 = V_4 -> V_5 ;
if ( F_21 ( V_24 , V_4 -> V_6 , V_25 ) != 0 )
V_17 = - V_26 ;
}
return V_17 ;
}
static int F_22 ( const char * V_27 )
{
char * V_28 ;
V_28 = strchr ( V_27 , ':' ) ;
if ( ! V_28 )
return - V_7 ;
if ( V_28 == V_27 )
return - V_7 ;
return 0 ;
}
