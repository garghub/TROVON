static void * F_1 ( int V_1 )
{
struct V_2 * V_3 ;
V_3 = F_2 ( sizeof( * V_3 ) , V_4 ) ;
if ( V_3 == NULL )
goto V_5;
V_3 -> V_6 = V_1 ;
V_3 -> V_7 = F_3 ( L_1 , 0 , V_8 ) ;
if ( F_4 ( V_3 -> V_7 ) ) {
F_5 ( V_9 L_2
L_3 ) ;
V_3 -> V_7 = NULL ;
goto V_5;
}
V_3 -> V_10 = F_3 ( L_1 , 0 , V_8 ) ;
if ( F_4 ( V_3 -> V_10 ) ) {
F_5 ( V_9 L_2
L_3 ) ;
V_3 -> V_10 = NULL ;
goto V_5;
}
F_6 ( & V_3 -> V_11 , 4 ) ;
return V_3 ;
V_5:
if ( V_3 ) {
if ( V_3 -> V_7 )
F_7 ( V_3 -> V_7 ) ;
if ( V_3 -> V_10 )
F_7 ( V_3 -> V_10 ) ;
F_8 ( V_3 ) ;
}
return NULL ;
}
static void F_9 ( void * V_3 )
{
struct V_2 * V_12 = V_3 ;
if ( V_12 ) {
if ( V_12 -> V_7 )
F_7 ( V_12 -> V_7 ) ;
if ( V_12 -> V_10 )
F_7 ( V_12 -> V_10 ) ;
}
F_8 ( V_3 ) ;
}
static int F_10 ( struct V_13 * V_14 , int V_15 , void * V_3 )
{
struct V_2 * V_16 = V_3 ;
T_1 V_17 , V_18 ;
T_2 V_19 [ V_20 + 3 ] ;
T_2 * V_21 ;
struct V_22 * V_23 = (struct V_22 * ) ( V_14 -> V_24 +
V_25 ) ;
struct V_26 V_27 = { . V_28 = V_16 -> V_7 } ;
T_1 V_29 ;
T_2 * V_30 ;
struct V_31 V_32 ;
if ( F_11 ( V_14 ) < 4 || F_12 ( V_14 ) < 4 ||
V_14 -> V_18 < V_15 ) {
F_5 ( V_33 L_4
L_5 , F_11 ( V_14 ) , F_12 ( V_14 ) ,
V_14 -> V_18 , V_15 ) ;
return - 1 ;
}
V_18 = V_14 -> V_18 - V_15 ;
V_21 = F_13 ( V_14 , 4 ) ;
memmove ( V_21 , V_21 + 4 , V_15 ) ;
V_21 += V_15 ;
V_17 = 3 + V_16 -> V_34 ;
V_16 -> V_11 ++ ;
if ( ( V_16 -> V_11 & 0xff00 ) == 0xff00 ) {
T_2 V_35 = ( V_16 -> V_11 >> 16 ) & 0xff ;
if ( V_35 >= 3 && V_35 < V_17 )
V_16 -> V_11 += 0x0100 ;
}
* V_21 ++ = V_19 [ 0 ] = ( V_16 -> V_11 >> 16 ) & 0xff ;
* V_21 ++ = V_19 [ 1 ] = ( V_16 -> V_11 >> 8 ) & 0xff ;
* V_21 ++ = V_19 [ 2 ] = V_16 -> V_11 & 0xff ;
* V_21 ++ = V_16 -> V_6 << 6 ;
memcpy ( V_19 + 3 , V_16 -> V_19 , V_16 -> V_34 ) ;
if ( ! V_23 -> V_36 ) {
V_29 = ~ F_14 ( ~ 0 , V_21 , V_18 ) ;
V_30 = F_15 ( V_14 , 4 ) ;
V_30 [ 0 ] = V_29 ;
V_30 [ 1 ] = V_29 >> 8 ;
V_30 [ 2 ] = V_29 >> 16 ;
V_30 [ 3 ] = V_29 >> 24 ;
F_16 ( & V_32 , V_21 , V_18 + 4 ) ;
F_17 ( V_16 -> V_7 , V_19 , V_17 ) ;
return F_18 ( & V_27 , & V_32 , & V_32 , V_18 + 4 ) ;
}
return 0 ;
}
static int F_19 ( struct V_13 * V_14 , int V_15 , void * V_3 )
{
struct V_2 * V_16 = V_3 ;
T_1 V_17 , V_37 ;
T_2 V_19 [ V_20 + 3 ] ;
T_2 V_1 , * V_21 ;
struct V_22 * V_23 = (struct V_22 * ) ( V_14 -> V_24 +
V_25 ) ;
struct V_26 V_27 = { . V_28 = V_16 -> V_10 } ;
T_1 V_29 ;
T_2 V_30 [ 4 ] ;
struct V_31 V_32 ;
if ( V_14 -> V_18 < V_15 + 8 )
return - 1 ;
V_21 = V_14 -> V_38 + V_15 ;
V_19 [ 0 ] = * V_21 ++ ;
V_19 [ 1 ] = * V_21 ++ ;
V_19 [ 2 ] = * V_21 ++ ;
V_1 = * V_21 ++ >> 6 ;
if ( V_1 != V_16 -> V_6 )
return - 1 ;
V_17 = 3 + V_16 -> V_34 ;
memcpy ( V_19 + 3 , V_16 -> V_19 , V_16 -> V_34 ) ;
V_37 = V_14 -> V_18 - V_15 - 8 ;
if ( ! V_23 -> V_36 ) {
F_16 ( & V_32 , V_21 , V_37 + 4 ) ;
F_17 ( V_16 -> V_10 , V_19 , V_17 ) ;
if ( F_20 ( & V_27 , & V_32 , & V_32 , V_37 + 4 ) )
return - 7 ;
V_29 = ~ F_14 ( ~ 0 , V_21 , V_37 ) ;
V_30 [ 0 ] = V_29 ;
V_30 [ 1 ] = V_29 >> 8 ;
V_30 [ 2 ] = V_29 >> 16 ;
V_30 [ 3 ] = V_29 >> 24 ;
if ( memcmp ( V_30 , V_21 + V_37 , 4 ) != 0 ) {
return - 2 ;
}
}
memmove ( V_14 -> V_38 + 4 , V_14 -> V_38 , V_15 ) ;
F_21 ( V_14 , 4 ) ;
F_22 ( V_14 , V_14 -> V_18 - 4 ) ;
return 0 ;
}
static int F_23 ( void * V_19 , int V_18 , T_2 * V_39 , void * V_3 )
{
struct V_2 * V_16 = V_3 ;
if ( V_18 < 0 || V_18 > V_20 )
return - 1 ;
memcpy ( V_16 -> V_19 , V_19 , V_18 ) ;
V_16 -> V_34 = V_18 ;
return 0 ;
}
static int F_24 ( void * V_19 , int V_18 , T_2 * V_39 , void * V_3 )
{
struct V_2 * V_16 = V_3 ;
if ( V_18 < V_16 -> V_34 )
return - 1 ;
memcpy ( V_19 , V_16 -> V_19 , V_16 -> V_34 ) ;
return V_16 -> V_34 ;
}
static void F_25 ( struct V_40 * V_41 , void * V_3 )
{
struct V_2 * V_16 = V_3 ;
F_26 ( V_41 , L_6 , V_16 -> V_6 , V_16 -> V_34 ) ;
}
int T_3 F_27 ( void )
{
return F_28 ( & V_42 ) ;
}
void T_4 F_29 ( void )
{
F_30 ( & V_42 ) ;
}
