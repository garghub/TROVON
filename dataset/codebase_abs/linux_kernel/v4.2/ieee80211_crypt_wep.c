static void * F_1 ( int V_1 )
{
struct V_2 * V_3 ;
V_3 = F_2 ( sizeof( * V_3 ) , V_4 ) ;
if ( V_3 == NULL )
return NULL ;
V_3 -> V_5 = V_1 ;
V_3 -> V_6 = F_3 ( L_1 , 0 , V_7 ) ;
if ( F_4 ( V_3 -> V_6 ) )
goto V_8;
V_3 -> V_9 = F_3 ( L_1 , 0 , V_7 ) ;
if ( F_4 ( V_3 -> V_9 ) )
goto V_10;
F_5 ( & V_3 -> V_11 , 4 ) ;
return V_3 ;
V_10:
F_6 ( V_3 -> V_6 ) ;
V_8:
F_7 ( V_3 ) ;
return NULL ;
}
static void F_8 ( void * V_3 )
{
struct V_2 * V_12 = V_3 ;
if ( V_12 ) {
if ( V_12 -> V_6 )
F_6 ( V_12 -> V_6 ) ;
if ( V_12 -> V_9 )
F_6 ( V_12 -> V_9 ) ;
}
F_7 ( V_3 ) ;
}
static int F_9 ( struct V_13 * V_14 , int V_15 , void * V_3 )
{
struct V_2 * V_16 = V_3 ;
T_1 V_17 , V_18 ;
T_2 V_19 [ V_20 + 3 ] ;
T_2 * V_21 ;
T_3 * V_22 = ( T_3 * ) ( V_14 -> V_23 + V_24 ) ;
struct V_25 V_26 = { . V_27 = V_16 -> V_6 } ;
T_1 V_28 ;
T_2 * V_29 ;
struct V_30 V_31 ;
if ( F_10 ( V_14 ) < 4 || F_11 ( V_14 ) < 4 ||
V_14 -> V_18 < V_15 )
return - 1 ;
V_18 = V_14 -> V_18 - V_15 ;
V_21 = F_12 ( V_14 , 4 ) ;
memmove ( V_21 , V_21 + 4 , V_15 ) ;
V_21 += V_15 ;
V_17 = 3 + V_16 -> V_32 ;
V_16 -> V_11 ++ ;
if ( ( V_16 -> V_11 & 0xff00 ) == 0xff00 ) {
T_2 V_33 = ( V_16 -> V_11 >> 16 ) & 0xff ;
if ( V_33 >= 3 && V_33 < V_17 )
V_16 -> V_11 += 0x0100 ;
}
* V_21 ++ = V_19 [ 0 ] = ( V_16 -> V_11 >> 16 ) & 0xff ;
* V_21 ++ = V_19 [ 1 ] = ( V_16 -> V_11 >> 8 ) & 0xff ;
* V_21 ++ = V_19 [ 2 ] = V_16 -> V_11 & 0xff ;
* V_21 ++ = V_16 -> V_5 << 6 ;
memcpy ( V_19 + 3 , V_16 -> V_19 , V_16 -> V_32 ) ;
if ( ! V_22 -> V_34 ) {
V_28 = ~ F_13 ( ~ 0 , V_21 , V_18 ) ;
V_29 = F_14 ( V_14 , 4 ) ;
V_29 [ 0 ] = V_28 ;
V_29 [ 1 ] = V_28 >> 8 ;
V_29 [ 2 ] = V_28 >> 16 ;
V_29 [ 3 ] = V_28 >> 24 ;
F_15 ( V_16 -> V_6 , V_19 , V_17 ) ;
F_16 ( & V_31 , V_21 , V_18 + 4 ) ;
return F_17 ( & V_26 , & V_31 , & V_31 , V_18 + 4 ) ;
}
return 0 ;
}
static int F_18 ( struct V_13 * V_14 , int V_15 , void * V_3 )
{
struct V_2 * V_16 = V_3 ;
T_1 V_17 , V_35 ;
T_2 V_19 [ V_20 + 3 ] ;
T_2 V_1 , * V_21 ;
T_3 * V_22 = ( T_3 * ) ( V_14 -> V_23 + V_24 ) ;
struct V_25 V_26 = { . V_27 = V_16 -> V_9 } ;
T_1 V_28 ;
T_2 V_29 [ 4 ] ;
struct V_30 V_31 ;
if ( V_14 -> V_18 < V_15 + 8 )
return - 1 ;
V_21 = V_14 -> V_36 + V_15 ;
V_19 [ 0 ] = * V_21 ++ ;
V_19 [ 1 ] = * V_21 ++ ;
V_19 [ 2 ] = * V_21 ++ ;
V_1 = * V_21 ++ >> 6 ;
if ( V_1 != V_16 -> V_5 )
return - 1 ;
V_17 = 3 + V_16 -> V_32 ;
memcpy ( V_19 + 3 , V_16 -> V_19 , V_16 -> V_32 ) ;
V_35 = V_14 -> V_18 - V_15 - 8 ;
if ( ! V_22 -> V_34 ) {
F_15 ( V_16 -> V_9 , V_19 , V_17 ) ;
F_16 ( & V_31 , V_21 , V_35 + 4 ) ;
if ( F_19 ( & V_26 , & V_31 , & V_31 , V_35 + 4 ) )
return - 7 ;
V_28 = ~ F_13 ( ~ 0 , V_21 , V_35 ) ;
V_29 [ 0 ] = V_28 ;
V_29 [ 1 ] = V_28 >> 8 ;
V_29 [ 2 ] = V_28 >> 16 ;
V_29 [ 3 ] = V_28 >> 24 ;
if ( memcmp ( V_29 , V_21 + V_35 , 4 ) != 0 ) {
return - 2 ;
}
}
memmove ( V_14 -> V_36 + 4 , V_14 -> V_36 , V_15 ) ;
F_20 ( V_14 , 4 ) ;
F_21 ( V_14 , V_14 -> V_18 - 4 ) ;
return 0 ;
}
static int F_22 ( void * V_19 , int V_18 , T_2 * V_37 , void * V_3 )
{
struct V_2 * V_16 = V_3 ;
if ( V_18 < 0 || V_18 > V_20 )
return - 1 ;
memcpy ( V_16 -> V_19 , V_19 , V_18 ) ;
V_16 -> V_32 = V_18 ;
return 0 ;
}
static int F_23 ( void * V_19 , int V_18 , T_2 * V_37 , void * V_3 )
{
struct V_2 * V_16 = V_3 ;
if ( V_18 < V_16 -> V_32 )
return - 1 ;
memcpy ( V_19 , V_16 -> V_19 , V_16 -> V_32 ) ;
return V_16 -> V_32 ;
}
static char * F_24 ( char * V_38 , void * V_3 )
{
struct V_2 * V_16 = V_3 ;
V_38 += sprintf ( V_38 , L_2 ,
V_16 -> V_5 , V_16 -> V_32 ) ;
return V_38 ;
}
int T_4 F_25 ( void )
{
return F_26 ( & V_39 ) ;
}
void T_5 F_27 ( void )
{
F_28 ( & V_39 ) ;
}
void F_29 ( void )
{
}
