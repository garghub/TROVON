int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = (struct V_3 * ) & V_2 -> V_4 . V_5 [ V_6 ] ;
struct V_7 * V_7 ;
T_1 V_8 ;
T_2 V_9 = V_2 -> V_9 ;
int V_10 ;
V_10 = - V_11 ;
if ( V_9 <= 0 || V_9 > 1024 * 1024 || ! V_2 -> V_5 )
goto error;
V_2 -> V_12 = 16 ;
V_2 -> V_4 . V_5 [ V_13 ] = ( void * ) ( unsigned long ) V_9 ;
if ( V_9 > V_14 ) {
V_7 = F_2 ( L_1 , V_9 , 0 ) ;
if ( F_3 ( V_7 ) ) {
V_10 = F_4 ( V_7 ) ;
goto error;
}
V_8 = F_5 ( V_7 , V_2 -> V_5 , V_2 -> V_9 , 0 ) ;
if ( V_8 != V_9 ) {
V_10 = V_8 ;
if ( V_8 >= 0 )
V_10 = - V_15 ;
goto V_16;
}
* V_3 = V_7 -> V_17 ;
F_6 ( V_3 ) ;
F_7 ( V_7 ) ;
} else {
void * V_5 = F_8 ( V_9 , V_18 ) ;
if ( ! V_5 )
return - V_15 ;
V_2 -> V_4 . V_5 [ V_19 ] = V_5 ;
memcpy ( V_5 , V_2 -> V_5 , V_2 -> V_9 ) ;
}
return 0 ;
V_16:
F_7 ( V_7 ) ;
error:
return V_10 ;
}
void F_9 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 > V_14 ) {
struct V_3 * V_3 = (struct V_3 * ) & V_2 -> V_4 . V_5 [ V_6 ] ;
F_10 ( V_3 ) ;
} else {
F_11 ( V_2 -> V_4 . V_5 [ V_19 ] ) ;
}
}
void F_12 ( struct V_20 * V_20 )
{
struct V_3 * V_3 = (struct V_3 * ) & V_20 -> V_4 . V_5 [ V_6 ] ;
F_13 ( V_20 , 0 ) ;
if ( F_14 ( V_20 ) &&
( T_2 ) V_20 -> V_4 . V_5 [ V_13 ] > V_14 )
F_15 ( V_3 , 0 ) ;
}
void F_16 ( struct V_20 * V_20 )
{
T_2 V_9 = ( T_2 ) V_20 -> V_4 . V_5 [ V_13 ] ;
if ( V_9 ) {
struct V_3 * V_3 = (struct V_3 * ) & V_20 -> V_4 . V_5 [ V_6 ] ;
F_10 ( V_3 ) ;
V_3 -> V_21 = NULL ;
V_3 -> V_22 = NULL ;
} else {
F_11 ( V_20 -> V_4 . V_5 [ V_19 ] ) ;
V_20 -> V_4 . V_5 [ V_19 ] = NULL ;
}
}
void F_17 ( const struct V_20 * V_20 , struct V_23 * V_24 )
{
T_2 V_9 = ( T_2 ) V_20 -> V_4 . V_5 [ V_13 ] ;
F_18 ( V_24 , V_20 -> V_25 ) ;
if ( F_14 ( V_20 ) )
F_19 ( V_24 , L_2 ,
V_9 ,
V_9 > V_14 ? L_3 : L_4 ) ;
}
long F_20 ( const struct V_20 * V_20 , char T_3 * V_26 , T_2 V_27 )
{
T_2 V_9 = ( T_2 ) V_20 -> V_4 . V_5 [ V_13 ] ;
long V_10 ;
if ( ! V_26 || V_27 < V_9 )
return V_9 ;
if ( V_9 > V_14 ) {
struct V_3 * V_3 = (struct V_3 * ) & V_20 -> V_4 . V_5 [ V_6 ] ;
struct V_7 * V_7 ;
T_4 V_28 ;
V_7 = F_21 ( V_3 , V_29 , F_22 () ) ;
if ( F_3 ( V_7 ) )
return F_4 ( V_7 ) ;
V_28 = 0 ;
V_10 = F_23 ( V_7 , V_26 , V_9 , & V_28 ) ;
F_7 ( V_7 ) ;
if ( V_10 >= 0 && V_10 != V_9 )
V_10 = - V_30 ;
} else {
V_10 = V_9 ;
if ( F_24 ( V_26 , V_20 -> V_4 . V_5 [ V_19 ] ,
V_9 ) != 0 )
V_10 = - V_31 ;
}
return V_10 ;
}
static int T_5 F_25 ( void )
{
return F_26 ( & V_32 ) ;
}
