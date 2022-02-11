static void * F_1 ( int V_1 )
{
struct V_2 * V_3 ;
V_3 = F_2 ( sizeof( * V_3 ) , V_4 ) ;
if ( V_3 == NULL )
goto V_5;
V_3 -> V_6 = V_1 ;
V_3 -> V_7 = F_3 ( L_1 , 0 , V_8 ) ;
if ( F_4 ( V_3 -> V_7 ) ) {
F_5 ( L_2
L_3 ) ;
V_3 -> V_7 = NULL ;
goto V_5;
}
V_3 -> V_9 = F_3 ( L_1 , 0 , V_8 ) ;
if ( F_4 ( V_3 -> V_9 ) ) {
F_5 ( L_2
L_3 ) ;
V_3 -> V_9 = NULL ;
goto V_5;
}
F_6 ( & V_3 -> V_10 , 4 ) ;
return V_3 ;
V_5:
if ( V_3 ) {
if ( V_3 -> V_7 )
F_7 ( V_3 -> V_7 ) ;
if ( V_3 -> V_9 )
F_7 ( V_3 -> V_9 ) ;
F_8 ( V_3 ) ;
}
return NULL ;
}
static void F_9 ( void * V_3 )
{
struct V_2 * V_11 = V_3 ;
if ( V_11 ) {
if ( V_11 -> V_7 )
F_7 ( V_11 -> V_7 ) ;
if ( V_11 -> V_9 )
F_7 ( V_11 -> V_9 ) ;
}
F_8 ( V_3 ) ;
}
static int F_10 ( struct V_12 * V_13 , int V_14 , void * V_3 )
{
struct V_2 * V_15 = V_3 ;
T_1 V_16 , V_17 ;
T_2 V_18 [ V_19 + 3 ] ;
T_2 * V_20 ;
struct V_21 * V_22 = (struct V_21 * ) ( V_13 -> V_23 +
V_24 ) ;
struct V_25 V_26 = { . V_27 = V_15 -> V_7 } ;
T_1 V_28 ;
T_2 * V_29 ;
struct V_30 V_31 ;
if ( F_11 ( V_13 ) < 4 || F_12 ( V_13 ) < 4 ||
V_13 -> V_17 < V_14 ) {
F_13 ( V_32 L_4
L_5 , F_11 ( V_13 ) , F_12 ( V_13 ) ,
V_13 -> V_17 , V_14 ) ;
return - 1 ;
}
V_17 = V_13 -> V_17 - V_14 ;
V_20 = F_14 ( V_13 , 4 ) ;
memmove ( V_20 , V_20 + 4 , V_14 ) ;
V_20 += V_14 ;
V_16 = 3 + V_15 -> V_33 ;
V_15 -> V_10 ++ ;
if ( ( V_15 -> V_10 & 0xff00 ) == 0xff00 ) {
T_2 V_34 = ( V_15 -> V_10 >> 16 ) & 0xff ;
if ( V_34 >= 3 && V_34 < V_16 )
V_15 -> V_10 += 0x0100 ;
}
* V_20 ++ = V_18 [ 0 ] = ( V_15 -> V_10 >> 16 ) & 0xff ;
* V_20 ++ = V_18 [ 1 ] = ( V_15 -> V_10 >> 8 ) & 0xff ;
* V_20 ++ = V_18 [ 2 ] = V_15 -> V_10 & 0xff ;
* V_20 ++ = V_15 -> V_6 << 6 ;
memcpy ( V_18 + 3 , V_15 -> V_18 , V_15 -> V_33 ) ;
if ( ! V_22 -> V_35 ) {
V_28 = ~ F_15 ( ~ 0 , V_20 , V_17 ) ;
V_29 = F_16 ( V_13 , 4 ) ;
V_29 [ 0 ] = V_28 ;
V_29 [ 1 ] = V_28 >> 8 ;
V_29 [ 2 ] = V_28 >> 16 ;
V_29 [ 3 ] = V_28 >> 24 ;
F_17 ( & V_31 , V_20 , V_17 + 4 ) ;
F_18 ( V_15 -> V_7 , V_18 , V_16 ) ;
return F_19 ( & V_26 , & V_31 , & V_31 , V_17 + 4 ) ;
}
return 0 ;
}
static int F_20 ( struct V_12 * V_13 , int V_14 , void * V_3 )
{
struct V_2 * V_15 = V_3 ;
T_1 V_16 , V_36 ;
T_2 V_18 [ V_19 + 3 ] ;
T_2 V_1 , * V_20 ;
struct V_21 * V_22 = (struct V_21 * ) ( V_13 -> V_23 +
V_24 ) ;
struct V_25 V_26 = { . V_27 = V_15 -> V_9 } ;
T_1 V_28 ;
T_2 V_29 [ 4 ] ;
struct V_30 V_31 ;
if ( V_13 -> V_17 < V_14 + 8 )
return - 1 ;
V_20 = V_13 -> V_37 + V_14 ;
V_18 [ 0 ] = * V_20 ++ ;
V_18 [ 1 ] = * V_20 ++ ;
V_18 [ 2 ] = * V_20 ++ ;
V_1 = * V_20 ++ >> 6 ;
if ( V_1 != V_15 -> V_6 )
return - 1 ;
V_16 = 3 + V_15 -> V_33 ;
memcpy ( V_18 + 3 , V_15 -> V_18 , V_15 -> V_33 ) ;
V_36 = V_13 -> V_17 - V_14 - 8 ;
if ( ! V_22 -> V_35 ) {
F_17 ( & V_31 , V_20 , V_36 + 4 ) ;
F_18 ( V_15 -> V_9 , V_18 , V_16 ) ;
if ( F_21 ( & V_26 , & V_31 , & V_31 , V_36 + 4 ) )
return - 7 ;
V_28 = ~ F_15 ( ~ 0 , V_20 , V_36 ) ;
V_29 [ 0 ] = V_28 ;
V_29 [ 1 ] = V_28 >> 8 ;
V_29 [ 2 ] = V_28 >> 16 ;
V_29 [ 3 ] = V_28 >> 24 ;
if ( memcmp ( V_29 , V_20 + V_36 , 4 ) != 0 ) {
return - 2 ;
}
}
memmove ( V_13 -> V_37 + 4 , V_13 -> V_37 , V_14 ) ;
F_22 ( V_13 , 4 ) ;
F_23 ( V_13 , V_13 -> V_17 - 4 ) ;
return 0 ;
}
static int F_24 ( void * V_18 , int V_17 , T_2 * V_38 , void * V_3 )
{
struct V_2 * V_15 = V_3 ;
if ( V_17 < 0 || V_17 > V_19 )
return - 1 ;
memcpy ( V_15 -> V_18 , V_18 , V_17 ) ;
V_15 -> V_33 = V_17 ;
return 0 ;
}
static int F_25 ( void * V_18 , int V_17 , T_2 * V_38 , void * V_3 )
{
struct V_2 * V_15 = V_3 ;
if ( V_17 < V_15 -> V_33 )
return - 1 ;
memcpy ( V_18 , V_15 -> V_18 , V_15 -> V_33 ) ;
return V_15 -> V_33 ;
}
static void F_26 ( struct V_39 * V_40 , void * V_3 )
{
struct V_2 * V_15 = V_3 ;
F_27 ( V_40 , L_6 , V_15 -> V_6 , V_15 -> V_33 ) ;
}
static int T_3 F_28 ( void )
{
return F_29 ( & V_41 ) ;
}
static void T_4 F_30 ( void )
{
F_31 ( & V_41 ) ;
}
