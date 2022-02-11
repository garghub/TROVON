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
struct V_17 V_18 = { . V_19 = V_16 -> V_7 } ;
T_1 V_20 , V_21 ;
T_2 V_22 [ V_23 + 3 ] ;
T_2 * V_24 ;
T_1 V_25 ;
T_2 * V_26 ;
struct V_27 V_28 ;
if ( F_11 ( V_14 ) < 4 || F_12 ( V_14 ) < 4 ||
V_14 -> V_21 < V_15 )
return - 1 ;
V_21 = V_14 -> V_21 - V_15 ;
V_24 = F_13 ( V_14 , 4 ) ;
memmove ( V_24 , V_24 + 4 , V_15 ) ;
V_24 += V_15 ;
V_20 = 3 + V_16 -> V_29 ;
V_16 -> V_11 ++ ;
if ( ( V_16 -> V_11 & 0xff00 ) == 0xff00 ) {
T_2 V_30 = ( V_16 -> V_11 >> 16 ) & 0xff ;
if ( V_30 >= 3 && V_30 < V_20 )
V_16 -> V_11 += 0x0100 ;
}
* V_24 ++ = V_22 [ 0 ] = ( V_16 -> V_11 >> 16 ) & 0xff ;
* V_24 ++ = V_22 [ 1 ] = ( V_16 -> V_11 >> 8 ) & 0xff ;
* V_24 ++ = V_22 [ 2 ] = V_16 -> V_11 & 0xff ;
* V_24 ++ = V_16 -> V_6 << 6 ;
memcpy ( V_22 + 3 , V_16 -> V_22 , V_16 -> V_29 ) ;
V_25 = ~ F_14 ( ~ 0 , V_24 , V_21 ) ;
V_26 = F_15 ( V_14 , 4 ) ;
V_26 [ 0 ] = V_25 ;
V_26 [ 1 ] = V_25 >> 8 ;
V_26 [ 2 ] = V_25 >> 16 ;
V_26 [ 3 ] = V_25 >> 24 ;
F_16 ( V_16 -> V_7 , V_22 , V_20 ) ;
F_17 ( & V_28 , V_24 , V_21 + 4 ) ;
return F_18 ( & V_18 , & V_28 , & V_28 , V_21 + 4 ) ;
}
static int F_19 ( struct V_13 * V_14 , int V_15 , void * V_3 )
{
struct V_2 * V_16 = V_3 ;
struct V_17 V_18 = { . V_19 = V_16 -> V_10 } ;
T_1 V_20 , V_31 ;
T_2 V_22 [ V_23 + 3 ] ;
T_2 V_1 , * V_24 ;
T_1 V_25 ;
T_2 V_26 [ 4 ] ;
struct V_27 V_28 ;
if ( V_14 -> V_21 < V_15 + 8 )
return - 1 ;
V_24 = V_14 -> V_32 + V_15 ;
V_22 [ 0 ] = * V_24 ++ ;
V_22 [ 1 ] = * V_24 ++ ;
V_22 [ 2 ] = * V_24 ++ ;
V_1 = * V_24 ++ >> 6 ;
if ( V_1 != V_16 -> V_6 )
return - 1 ;
V_20 = 3 + V_16 -> V_29 ;
memcpy ( V_22 + 3 , V_16 -> V_22 , V_16 -> V_29 ) ;
V_31 = V_14 -> V_21 - V_15 - 8 ;
F_16 ( V_16 -> V_10 , V_22 , V_20 ) ;
F_17 ( & V_28 , V_24 , V_31 + 4 ) ;
if ( F_20 ( & V_18 , & V_28 , & V_28 , V_31 + 4 ) )
return - 7 ;
V_25 = ~ F_14 ( ~ 0 , V_24 , V_31 ) ;
V_26 [ 0 ] = V_25 ;
V_26 [ 1 ] = V_25 >> 8 ;
V_26 [ 2 ] = V_25 >> 16 ;
V_26 [ 3 ] = V_25 >> 24 ;
if ( memcmp ( V_26 , V_24 + V_31 , 4 ) != 0 ) {
return - 2 ;
}
memmove ( V_14 -> V_32 + 4 , V_14 -> V_32 , V_15 ) ;
F_21 ( V_14 , 4 ) ;
F_22 ( V_14 , V_14 -> V_21 - 4 ) ;
return 0 ;
}
static int F_23 ( void * V_22 , int V_21 , T_2 * V_33 , void * V_3 )
{
struct V_2 * V_16 = V_3 ;
if ( V_21 < 0 || V_21 > V_23 )
return - 1 ;
memcpy ( V_16 -> V_22 , V_22 , V_21 ) ;
V_16 -> V_29 = V_21 ;
return 0 ;
}
static int F_24 ( void * V_22 , int V_21 , T_2 * V_33 , void * V_3 )
{
struct V_2 * V_16 = V_3 ;
if ( V_21 < V_16 -> V_29 )
return - 1 ;
memcpy ( V_22 , V_16 -> V_22 , V_16 -> V_29 ) ;
return V_16 -> V_29 ;
}
static char * F_25 ( char * V_34 , void * V_3 )
{
struct V_2 * V_16 = V_3 ;
V_34 += sprintf ( V_34 , L_4 ,
V_16 -> V_6 , V_16 -> V_29 ) ;
return V_34 ;
}
int F_26 ( void )
{
return F_27 ( & V_35 ) ;
}
void F_28 ( void )
{
F_29 ( & V_35 ) ;
}
void F_30 ( void )
{
return;
}
