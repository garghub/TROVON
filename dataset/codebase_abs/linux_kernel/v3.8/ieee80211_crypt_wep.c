static void * F_1 ( int V_1 )
{
struct V_2 * V_3 ;
V_3 = F_2 ( sizeof( * V_3 ) , V_4 ) ;
if ( V_3 == NULL )
goto V_5;
V_3 -> V_6 = V_1 ;
V_3 -> V_7 = F_3 ( L_1 , 0 , V_8 ) ;
if ( F_4 ( V_3 -> V_7 ) ) {
F_5 ( L_2 ) ;
V_3 -> V_7 = NULL ;
goto V_5;
}
V_3 -> V_9 = F_3 ( L_1 , 0 , V_8 ) ;
if ( F_4 ( V_3 -> V_9 ) ) {
F_5 ( L_2 ) ;
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
struct V_16 V_17 = { . V_18 = V_15 -> V_7 } ;
T_1 V_19 , V_20 ;
T_2 V_21 [ V_22 + 3 ] ;
T_2 * V_23 ;
T_1 V_24 ;
T_2 * V_25 ;
struct V_26 V_27 ;
if ( F_11 ( V_13 ) < 4 || F_12 ( V_13 ) < 4 ||
V_13 -> V_20 < V_14 )
return - 1 ;
V_20 = V_13 -> V_20 - V_14 ;
V_23 = F_13 ( V_13 , 4 ) ;
memmove ( V_23 , V_23 + 4 , V_14 ) ;
V_23 += V_14 ;
V_19 = 3 + V_15 -> V_28 ;
V_15 -> V_10 ++ ;
if ( ( V_15 -> V_10 & 0xff00 ) == 0xff00 ) {
T_2 V_29 = ( V_15 -> V_10 >> 16 ) & 0xff ;
if ( V_29 >= 3 && V_29 < V_19 )
V_15 -> V_10 += 0x0100 ;
}
* V_23 ++ = V_21 [ 0 ] = ( V_15 -> V_10 >> 16 ) & 0xff ;
* V_23 ++ = V_21 [ 1 ] = ( V_15 -> V_10 >> 8 ) & 0xff ;
* V_23 ++ = V_21 [ 2 ] = V_15 -> V_10 & 0xff ;
* V_23 ++ = V_15 -> V_6 << 6 ;
memcpy ( V_21 + 3 , V_15 -> V_21 , V_15 -> V_28 ) ;
V_24 = ~ F_14 ( ~ 0 , V_23 , V_20 ) ;
V_25 = F_15 ( V_13 , 4 ) ;
V_25 [ 0 ] = V_24 ;
V_25 [ 1 ] = V_24 >> 8 ;
V_25 [ 2 ] = V_24 >> 16 ;
V_25 [ 3 ] = V_24 >> 24 ;
F_16 ( V_15 -> V_7 , V_21 , V_19 ) ;
F_17 ( & V_27 , V_23 , V_20 + 4 ) ;
return F_18 ( & V_17 , & V_27 , & V_27 , V_20 + 4 ) ;
}
static int F_19 ( struct V_12 * V_13 , int V_14 , void * V_3 )
{
struct V_2 * V_15 = V_3 ;
struct V_16 V_17 = { . V_18 = V_15 -> V_9 } ;
T_1 V_19 , V_30 ;
T_2 V_21 [ V_22 + 3 ] ;
T_2 V_1 , * V_23 ;
T_1 V_24 ;
T_2 V_25 [ 4 ] ;
struct V_26 V_27 ;
if ( V_13 -> V_20 < V_14 + 8 )
return - 1 ;
V_23 = V_13 -> V_31 + V_14 ;
V_21 [ 0 ] = * V_23 ++ ;
V_21 [ 1 ] = * V_23 ++ ;
V_21 [ 2 ] = * V_23 ++ ;
V_1 = * V_23 ++ >> 6 ;
if ( V_1 != V_15 -> V_6 )
return - 1 ;
V_19 = 3 + V_15 -> V_28 ;
memcpy ( V_21 + 3 , V_15 -> V_21 , V_15 -> V_28 ) ;
V_30 = V_13 -> V_20 - V_14 - 8 ;
F_16 ( V_15 -> V_9 , V_21 , V_19 ) ;
F_17 ( & V_27 , V_23 , V_30 + 4 ) ;
if ( F_20 ( & V_17 , & V_27 , & V_27 , V_30 + 4 ) )
return - 7 ;
V_24 = ~ F_14 ( ~ 0 , V_23 , V_30 ) ;
V_25 [ 0 ] = V_24 ;
V_25 [ 1 ] = V_24 >> 8 ;
V_25 [ 2 ] = V_24 >> 16 ;
V_25 [ 3 ] = V_24 >> 24 ;
if ( memcmp ( V_25 , V_23 + V_30 , 4 ) != 0 ) {
return - 2 ;
}
memmove ( V_13 -> V_31 + 4 , V_13 -> V_31 , V_14 ) ;
F_21 ( V_13 , 4 ) ;
F_22 ( V_13 , V_13 -> V_20 - 4 ) ;
return 0 ;
}
static int F_23 ( void * V_21 , int V_20 , T_2 * V_32 , void * V_3 )
{
struct V_2 * V_15 = V_3 ;
if ( V_20 < 0 || V_20 > V_22 )
return - 1 ;
memcpy ( V_15 -> V_21 , V_21 , V_20 ) ;
V_15 -> V_28 = V_20 ;
return 0 ;
}
static int F_24 ( void * V_21 , int V_20 , T_2 * V_32 , void * V_3 )
{
struct V_2 * V_15 = V_3 ;
if ( V_20 < V_15 -> V_28 )
return - 1 ;
memcpy ( V_21 , V_15 -> V_21 , V_15 -> V_28 ) ;
return V_15 -> V_28 ;
}
static char * F_25 ( char * V_33 , void * V_3 )
{
struct V_2 * V_15 = V_3 ;
V_33 += sprintf ( V_33 , L_3 ,
V_15 -> V_6 , V_15 -> V_28 ) ;
return V_33 ;
}
int F_26 ( void )
{
return F_27 ( & V_34 ) ;
}
void F_28 ( void )
{
F_29 ( & V_34 ) ;
}
void F_30 ( void )
{
return;
}
