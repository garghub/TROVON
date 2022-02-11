int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_4 = (struct V_4 * ) & V_1 -> V_5 . V_6 ;
struct V_7 * V_7 ;
T_1 V_8 ;
T_2 V_9 = V_3 -> V_9 ;
int V_10 ;
V_10 = - V_11 ;
if ( V_9 <= 0 || V_9 > 1024 * 1024 || ! V_3 -> V_12 )
goto error;
V_10 = F_2 ( V_1 , 16 ) ;
if ( V_10 < 0 )
goto error;
V_1 -> V_13 . V_14 [ 1 ] = V_9 ;
if ( V_9 > V_15 ) {
V_7 = F_3 ( L_1 , V_9 , 0 ) ;
if ( F_4 ( V_7 ) ) {
V_10 = F_5 ( V_7 ) ;
goto V_16;
}
V_8 = F_6 ( V_7 , V_3 -> V_12 , V_3 -> V_9 , 0 ) ;
if ( V_8 != V_9 ) {
V_10 = V_8 ;
if ( V_8 >= 0 )
V_10 = - V_17 ;
goto V_18;
}
* V_4 = V_7 -> V_19 ;
F_7 ( V_4 ) ;
F_8 ( V_7 ) ;
} else {
void * V_12 = F_9 ( V_9 , V_20 ) ;
if ( ! V_12 ) {
V_10 = - V_17 ;
goto V_16;
}
V_1 -> V_5 . V_12 = memcpy ( V_12 , V_3 -> V_12 , V_3 -> V_9 ) ;
}
return 0 ;
V_18:
F_8 ( V_7 ) ;
V_16:
F_2 ( V_1 , 0 ) ;
error:
return V_10 ;
}
void F_10 ( struct V_1 * V_1 )
{
struct V_4 * V_4 = (struct V_4 * ) & V_1 -> V_5 . V_6 ;
F_2 ( V_1 , 0 ) ;
if ( F_11 ( V_1 ) && V_1 -> V_13 . V_14 [ 1 ] > V_15 )
F_12 ( V_4 , 0 ) ;
}
void F_13 ( struct V_1 * V_1 )
{
if ( V_1 -> V_13 . V_14 [ 1 ] > V_15 ) {
struct V_4 * V_4 = (struct V_4 * ) & V_1 -> V_5 . V_6 ;
F_14 ( V_4 ) ;
V_4 -> V_21 = NULL ;
V_4 -> V_22 = NULL ;
} else {
F_15 ( V_1 -> V_5 . V_12 ) ;
V_1 -> V_5 . V_12 = NULL ;
}
}
void F_16 ( const struct V_1 * V_1 , struct V_23 * V_24 )
{
unsigned long V_9 = V_1 -> V_13 . V_14 [ 1 ] ;
F_17 ( V_24 , V_1 -> V_25 ) ;
if ( F_11 ( V_1 ) )
F_18 ( V_24 , L_2 ,
V_9 ,
V_9 > V_15 ? L_3 : L_4 ) ;
}
long F_19 ( const struct V_1 * V_1 , char T_3 * V_26 , T_2 V_27 )
{
unsigned long V_9 = V_1 -> V_13 . V_14 [ 1 ] ;
long V_10 ;
if ( ! V_26 || V_27 < V_9 )
return V_9 ;
if ( V_9 > V_15 ) {
struct V_4 * V_4 = (struct V_4 * ) & V_1 -> V_5 . V_6 ;
struct V_7 * V_7 ;
T_4 V_28 ;
V_7 = F_20 ( V_4 , V_29 , F_21 () ) ;
if ( F_4 ( V_7 ) )
return F_5 ( V_7 ) ;
V_28 = 0 ;
V_10 = F_22 ( V_7 , V_26 , V_9 , & V_28 ) ;
F_8 ( V_7 ) ;
if ( V_10 >= 0 && V_10 != V_9 )
V_10 = - V_30 ;
} else {
V_10 = V_9 ;
if ( F_23 ( V_26 , V_1 -> V_5 . V_12 , V_9 ) != 0 )
V_10 = - V_31 ;
}
return V_10 ;
}
static int T_5 F_24 ( void )
{
return F_25 ( & V_32 ) ;
}
static void T_6 F_26 ( void )
{
F_27 ( & V_32 ) ;
}
