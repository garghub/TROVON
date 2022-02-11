static void * F_1 ( int V_1 )
{
struct V_2 * V_3 ;
V_3 = F_2 ( sizeof( * V_3 ) , V_4 ) ;
if ( V_3 == NULL )
goto V_5;
V_3 -> V_6 = V_1 ;
V_3 -> V_7 = F_3 ( L_1 , 0 , V_8 ) ;
if ( F_4 ( V_3 -> V_7 ) ) {
V_3 -> V_7 = NULL ;
goto V_5;
}
V_3 -> V_9 = F_3 ( L_1 , 0 , V_8 ) ;
if ( F_4 ( V_3 -> V_9 ) ) {
V_3 -> V_9 = NULL ;
goto V_5;
}
F_5 ( & V_3 -> V_10 , 4 ) ;
return V_3 ;
V_5:
if ( V_3 ) {
if ( V_3 -> V_7 )
F_6 ( V_3 -> V_7 ) ;
if ( V_3 -> V_9 )
F_6 ( V_3 -> V_9 ) ;
F_7 ( V_3 ) ;
}
return NULL ;
}
static void F_8 ( void * V_3 )
{
struct V_2 * V_11 = V_3 ;
if ( V_11 ) {
if ( V_11 -> V_7 )
F_6 ( V_11 -> V_7 ) ;
if ( V_11 -> V_9 )
F_6 ( V_11 -> V_9 ) ;
}
F_7 ( V_3 ) ;
}
static int F_9 ( struct V_12 * V_13 , int V_14 ,
T_1 * V_15 , int V_16 , void * V_3 )
{
struct V_2 * V_17 = V_3 ;
T_2 V_18 ;
T_1 * V_19 ;
if ( F_10 ( V_13 ) < 4 || V_13 -> V_20 < V_14 )
return - 1 ;
V_19 = F_11 ( V_13 , 4 ) ;
memmove ( V_19 , V_19 + 4 , V_14 ) ;
V_19 += V_14 ;
V_18 = 3 + V_17 -> V_21 ;
V_17 -> V_10 ++ ;
if ( ( V_17 -> V_10 & 0xff00 ) == 0xff00 ) {
T_1 V_22 = ( V_17 -> V_10 >> 16 ) & 0xff ;
if ( V_22 >= 3 && V_22 < V_18 )
V_17 -> V_10 += 0x0100 ;
}
* V_19 ++ = ( V_17 -> V_10 >> 16 ) & 0xff ;
* V_19 ++ = ( V_17 -> V_10 >> 8 ) & 0xff ;
* V_19 ++ = V_17 -> V_10 & 0xff ;
* V_19 ++ = V_17 -> V_6 << 6 ;
return 0 ;
}
static int F_12 ( struct V_12 * V_13 , int V_14 , void * V_3 )
{
struct V_2 * V_17 = V_3 ;
struct V_23 V_24 = { . V_25 = V_17 -> V_7 } ;
T_2 V_26 , V_18 , V_20 ;
T_1 * V_19 , * V_27 ;
struct V_28 V_29 ;
T_1 V_15 [ V_30 + 3 ] ;
if ( F_13 ( V_13 ) < 4 )
return - 1 ;
if ( F_9 ( V_13 , V_14 , NULL , 0 , V_3 ) )
return - 1 ;
F_14 ( V_13 , V_14 , V_15 , 3 ) ;
memcpy ( V_15 + 3 , V_17 -> V_15 , V_17 -> V_21 ) ;
V_20 = V_13 -> V_20 - V_14 - 4 ;
V_19 = V_13 -> V_31 + V_14 + 4 ;
V_18 = 3 + V_17 -> V_21 ;
V_26 = ~ F_15 ( ~ 0 , V_19 , V_20 ) ;
V_27 = F_16 ( V_13 , 4 ) ;
V_27 [ 0 ] = V_26 ;
V_27 [ 1 ] = V_26 >> 8 ;
V_27 [ 2 ] = V_26 >> 16 ;
V_27 [ 3 ] = V_26 >> 24 ;
F_17 ( V_17 -> V_7 , V_15 , V_18 ) ;
F_18 ( & V_29 , V_19 , V_20 + 4 ) ;
return F_19 ( & V_24 , & V_29 , & V_29 , V_20 + 4 ) ;
}
static int F_20 ( struct V_12 * V_13 , int V_14 , void * V_3 )
{
struct V_2 * V_17 = V_3 ;
struct V_23 V_24 = { . V_25 = V_17 -> V_9 } ;
T_2 V_26 , V_18 , V_32 ;
T_1 V_15 [ V_30 + 3 ] ;
T_1 V_1 , * V_19 , V_27 [ 4 ] ;
struct V_28 V_29 ;
if ( V_13 -> V_20 < V_14 + 8 )
return - 1 ;
V_19 = V_13 -> V_31 + V_14 ;
V_15 [ 0 ] = * V_19 ++ ;
V_15 [ 1 ] = * V_19 ++ ;
V_15 [ 2 ] = * V_19 ++ ;
V_1 = * V_19 ++ >> 6 ;
if ( V_1 != V_17 -> V_6 )
return - 1 ;
V_18 = 3 + V_17 -> V_21 ;
memcpy ( V_15 + 3 , V_17 -> V_15 , V_17 -> V_21 ) ;
V_32 = V_13 -> V_20 - V_14 - 8 ;
F_17 ( V_17 -> V_9 , V_15 , V_18 ) ;
F_18 ( & V_29 , V_19 , V_32 + 4 ) ;
if ( F_21 ( & V_24 , & V_29 , & V_29 , V_32 + 4 ) )
return - 7 ;
V_26 = ~ F_15 ( ~ 0 , V_19 , V_32 ) ;
V_27 [ 0 ] = V_26 ;
V_27 [ 1 ] = V_26 >> 8 ;
V_27 [ 2 ] = V_26 >> 16 ;
V_27 [ 3 ] = V_26 >> 24 ;
if ( memcmp ( V_27 , V_19 + V_32 , 4 ) != 0 ) {
return - 2 ;
}
memmove ( V_13 -> V_31 + 4 , V_13 -> V_31 , V_14 ) ;
F_22 ( V_13 , 4 ) ;
F_23 ( V_13 , V_13 -> V_20 - 4 ) ;
return 0 ;
}
static int F_24 ( void * V_15 , int V_20 , T_1 * V_33 , void * V_3 )
{
struct V_2 * V_17 = V_3 ;
if ( V_20 < 0 || V_20 > V_30 )
return - 1 ;
memcpy ( V_17 -> V_15 , V_15 , V_20 ) ;
V_17 -> V_21 = V_20 ;
return 0 ;
}
static int F_25 ( void * V_15 , int V_20 , T_1 * V_33 , void * V_3 )
{
struct V_2 * V_17 = V_3 ;
if ( V_20 < V_17 -> V_21 )
return - 1 ;
memcpy ( V_15 , V_17 -> V_15 , V_17 -> V_21 ) ;
return V_17 -> V_21 ;
}
static void F_26 ( struct V_34 * V_35 , void * V_3 )
{
struct V_2 * V_17 = V_3 ;
F_27 ( V_35 , L_2 , V_17 -> V_6 , V_17 -> V_21 ) ;
}
static int T_3 F_28 ( void )
{
return F_29 ( & V_36 ) ;
}
static void T_4 F_30 ( void )
{
F_31 ( & V_36 ) ;
}
