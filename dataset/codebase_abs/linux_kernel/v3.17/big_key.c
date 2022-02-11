int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = (struct V_3 * ) & V_2 -> V_4 ;
struct V_5 * V_5 ;
T_1 V_6 ;
T_2 V_7 = V_2 -> V_7 ;
int V_8 ;
V_8 = - V_9 ;
if ( V_7 <= 0 || V_7 > 1024 * 1024 || ! V_2 -> V_10 )
goto error;
V_2 -> V_11 = 16 ;
V_2 -> V_12 [ 1 ] = ( void * ) ( unsigned long ) V_7 ;
if ( V_7 > V_13 ) {
V_5 = F_2 ( L_1 , V_7 , 0 ) ;
if ( F_3 ( V_5 ) ) {
V_8 = F_4 ( V_5 ) ;
goto error;
}
V_6 = F_5 ( V_5 , V_2 -> V_10 , V_2 -> V_7 , 0 ) ;
if ( V_6 != V_7 ) {
V_8 = V_6 ;
if ( V_6 >= 0 )
V_8 = - V_14 ;
goto V_15;
}
* V_3 = V_5 -> V_16 ;
F_6 ( V_3 ) ;
F_7 ( V_5 ) ;
} else {
void * V_10 = F_8 ( V_7 , V_17 ) ;
if ( ! V_10 )
return - V_14 ;
V_2 -> V_4 [ 0 ] = memcpy ( V_10 , V_2 -> V_10 , V_2 -> V_7 ) ;
}
return 0 ;
V_15:
F_7 ( V_5 ) ;
error:
return V_8 ;
}
void F_9 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 > V_13 ) {
struct V_3 * V_3 = (struct V_3 * ) & V_2 -> V_4 ;
F_10 ( V_3 ) ;
} else {
F_11 ( V_2 -> V_4 [ 0 ] ) ;
}
}
void F_12 ( struct V_18 * V_18 )
{
struct V_3 * V_3 = (struct V_3 * ) & V_18 -> V_4 . V_19 ;
F_13 ( V_18 , 0 ) ;
if ( F_14 ( V_18 ) && V_18 -> V_12 . V_20 [ 1 ] > V_13 )
F_15 ( V_3 , 0 ) ;
}
void F_16 ( struct V_18 * V_18 )
{
if ( V_18 -> V_12 . V_20 [ 1 ] > V_13 ) {
struct V_3 * V_3 = (struct V_3 * ) & V_18 -> V_4 . V_19 ;
F_10 ( V_3 ) ;
V_3 -> V_21 = NULL ;
V_3 -> V_22 = NULL ;
} else {
F_11 ( V_18 -> V_4 . V_10 ) ;
V_18 -> V_4 . V_10 = NULL ;
}
}
void F_17 ( const struct V_18 * V_18 , struct V_23 * V_24 )
{
unsigned long V_7 = V_18 -> V_12 . V_20 [ 1 ] ;
F_18 ( V_24 , V_18 -> V_25 ) ;
if ( F_14 ( V_18 ) )
F_19 ( V_24 , L_2 ,
V_7 ,
V_7 > V_13 ? L_3 : L_4 ) ;
}
long F_20 ( const struct V_18 * V_18 , char T_3 * V_26 , T_2 V_27 )
{
unsigned long V_7 = V_18 -> V_12 . V_20 [ 1 ] ;
long V_8 ;
if ( ! V_26 || V_27 < V_7 )
return V_7 ;
if ( V_7 > V_13 ) {
struct V_3 * V_3 = (struct V_3 * ) & V_18 -> V_4 . V_19 ;
struct V_5 * V_5 ;
T_4 V_28 ;
V_5 = F_21 ( V_3 , V_29 , F_22 () ) ;
if ( F_3 ( V_5 ) )
return F_4 ( V_5 ) ;
V_28 = 0 ;
V_8 = F_23 ( V_5 , V_26 , V_7 , & V_28 ) ;
F_7 ( V_5 ) ;
if ( V_8 >= 0 && V_8 != V_7 )
V_8 = - V_30 ;
} else {
V_8 = V_7 ;
if ( F_24 ( V_26 , V_18 -> V_4 . V_10 , V_7 ) != 0 )
V_8 = - V_31 ;
}
return V_8 ;
}
static int T_5 F_25 ( void )
{
return F_26 ( & V_32 ) ;
}
static void T_6 F_27 ( void )
{
F_28 ( & V_32 ) ;
}
