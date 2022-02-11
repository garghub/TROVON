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
static int F_10 ( struct V_13 * V_14 , int V_15 ,
T_1 * V_16 , int V_17 , void * V_3 )
{
struct V_2 * V_18 = V_3 ;
T_2 V_19 ;
T_1 * V_20 ;
if ( F_11 ( V_14 ) < 4 || V_14 -> V_21 < V_15 )
return - 1 ;
V_20 = F_12 ( V_14 , 4 ) ;
memmove ( V_20 , V_20 + 4 , V_15 ) ;
V_20 += V_15 ;
V_19 = 3 + V_18 -> V_22 ;
V_18 -> V_11 ++ ;
if ( ( V_18 -> V_11 & 0xff00 ) == 0xff00 ) {
T_1 V_23 = ( V_18 -> V_11 >> 16 ) & 0xff ;
if ( V_23 >= 3 && V_23 < V_19 )
V_18 -> V_11 += 0x0100 ;
}
* V_20 ++ = ( V_18 -> V_11 >> 16 ) & 0xff ;
* V_20 ++ = ( V_18 -> V_11 >> 8 ) & 0xff ;
* V_20 ++ = V_18 -> V_11 & 0xff ;
* V_20 ++ = V_18 -> V_6 << 6 ;
return 0 ;
}
static int F_13 ( struct V_13 * V_14 , int V_15 , void * V_3 )
{
struct V_2 * V_18 = V_3 ;
struct V_24 V_25 = { . V_26 = V_18 -> V_7 } ;
T_2 V_27 , V_19 , V_21 ;
T_1 * V_20 , * V_28 ;
struct V_29 V_30 ;
T_1 V_16 [ V_31 + 3 ] ;
if ( F_14 ( V_14 ) < 4 )
return - 1 ;
if ( F_10 ( V_14 , V_15 , NULL , 0 , V_3 ) )
return - 1 ;
F_15 ( V_14 , V_15 , V_16 , 3 ) ;
memcpy ( V_16 + 3 , V_18 -> V_16 , V_18 -> V_22 ) ;
V_21 = V_14 -> V_21 - V_15 - 4 ;
V_20 = V_14 -> V_32 + V_15 + 4 ;
V_19 = 3 + V_18 -> V_22 ;
V_27 = ~ F_16 ( ~ 0 , V_20 , V_21 ) ;
V_28 = F_17 ( V_14 , 4 ) ;
V_28 [ 0 ] = V_27 ;
V_28 [ 1 ] = V_27 >> 8 ;
V_28 [ 2 ] = V_27 >> 16 ;
V_28 [ 3 ] = V_27 >> 24 ;
F_18 ( V_18 -> V_7 , V_16 , V_19 ) ;
F_19 ( & V_30 , V_20 , V_21 + 4 ) ;
return F_20 ( & V_25 , & V_30 , & V_30 , V_21 + 4 ) ;
}
static int F_21 ( struct V_13 * V_14 , int V_15 , void * V_3 )
{
struct V_2 * V_18 = V_3 ;
struct V_24 V_25 = { . V_26 = V_18 -> V_10 } ;
T_2 V_27 , V_19 , V_33 ;
T_1 V_16 [ V_31 + 3 ] ;
T_1 V_1 , * V_20 , V_28 [ 4 ] ;
struct V_29 V_30 ;
if ( V_14 -> V_21 < V_15 + 8 )
return - 1 ;
V_20 = V_14 -> V_32 + V_15 ;
V_16 [ 0 ] = * V_20 ++ ;
V_16 [ 1 ] = * V_20 ++ ;
V_16 [ 2 ] = * V_20 ++ ;
V_1 = * V_20 ++ >> 6 ;
if ( V_1 != V_18 -> V_6 )
return - 1 ;
V_19 = 3 + V_18 -> V_22 ;
memcpy ( V_16 + 3 , V_18 -> V_16 , V_18 -> V_22 ) ;
V_33 = V_14 -> V_21 - V_15 - 8 ;
F_18 ( V_18 -> V_10 , V_16 , V_19 ) ;
F_19 ( & V_30 , V_20 , V_33 + 4 ) ;
if ( F_22 ( & V_25 , & V_30 , & V_30 , V_33 + 4 ) )
return - 7 ;
V_27 = ~ F_16 ( ~ 0 , V_20 , V_33 ) ;
V_28 [ 0 ] = V_27 ;
V_28 [ 1 ] = V_27 >> 8 ;
V_28 [ 2 ] = V_27 >> 16 ;
V_28 [ 3 ] = V_27 >> 24 ;
if ( memcmp ( V_28 , V_20 + V_33 , 4 ) != 0 ) {
return - 2 ;
}
memmove ( V_14 -> V_32 + 4 , V_14 -> V_32 , V_15 ) ;
F_23 ( V_14 , 4 ) ;
F_24 ( V_14 , V_14 -> V_21 - 4 ) ;
return 0 ;
}
static int F_25 ( void * V_16 , int V_21 , T_1 * V_34 , void * V_3 )
{
struct V_2 * V_18 = V_3 ;
if ( V_21 < 0 || V_21 > V_31 )
return - 1 ;
memcpy ( V_18 -> V_16 , V_16 , V_21 ) ;
V_18 -> V_22 = V_21 ;
return 0 ;
}
static int F_26 ( void * V_16 , int V_21 , T_1 * V_34 , void * V_3 )
{
struct V_2 * V_18 = V_3 ;
if ( V_21 < V_18 -> V_22 )
return - 1 ;
memcpy ( V_16 , V_18 -> V_16 , V_18 -> V_22 ) ;
return V_18 -> V_22 ;
}
static char * F_27 ( char * V_35 , void * V_3 )
{
struct V_2 * V_18 = V_3 ;
V_35 += sprintf ( V_35 , L_4 , V_18 -> V_6 , V_18 -> V_22 ) ;
return V_35 ;
}
static int T_3 F_28 ( void )
{
return F_29 ( & V_36 ) ;
}
static void T_4 F_30 ( void )
{
F_31 ( & V_36 ) ;
}
