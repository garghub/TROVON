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
F_6 ( V_3 -> V_7 ) ;
F_6 ( V_3 -> V_9 ) ;
F_7 ( V_3 ) ;
}
return NULL ;
}
static void F_8 ( void * V_3 )
{
struct V_2 * V_11 = V_3 ;
if ( V_11 ) {
F_6 ( V_11 -> V_7 ) ;
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
F_13 ( V_23 , V_17 -> V_7 ) ;
T_2 V_24 , V_18 , V_20 ;
T_1 * V_19 , * V_25 ;
struct V_26 V_27 ;
T_1 V_15 [ V_28 + 3 ] ;
int V_29 ;
if ( F_14 ( V_13 ) < 4 )
return - 1 ;
if ( F_9 ( V_13 , V_14 , NULL , 0 , V_3 ) )
return - 1 ;
F_15 ( V_13 , V_14 , V_15 , 3 ) ;
memcpy ( V_15 + 3 , V_17 -> V_15 , V_17 -> V_21 ) ;
V_20 = V_13 -> V_20 - V_14 - 4 ;
V_19 = V_13 -> V_30 + V_14 + 4 ;
V_18 = 3 + V_17 -> V_21 ;
V_24 = ~ F_16 ( ~ 0 , V_19 , V_20 ) ;
V_25 = F_17 ( V_13 , 4 ) ;
V_25 [ 0 ] = V_24 ;
V_25 [ 1 ] = V_24 >> 8 ;
V_25 [ 2 ] = V_24 >> 16 ;
V_25 [ 3 ] = V_24 >> 24 ;
F_18 ( V_17 -> V_7 , V_15 , V_18 ) ;
F_19 ( & V_27 , V_19 , V_20 + 4 ) ;
F_20 ( V_23 , V_17 -> V_7 ) ;
F_21 ( V_23 , 0 , NULL , NULL ) ;
F_22 ( V_23 , & V_27 , & V_27 , V_20 + 4 , NULL ) ;
V_29 = F_23 ( V_23 ) ;
F_24 ( V_23 ) ;
return V_29 ;
}
static int F_25 ( struct V_12 * V_13 , int V_14 , void * V_3 )
{
struct V_2 * V_17 = V_3 ;
F_13 ( V_23 , V_17 -> V_9 ) ;
T_2 V_24 , V_18 , V_31 ;
T_1 V_15 [ V_28 + 3 ] ;
T_1 V_1 , * V_19 , V_25 [ 4 ] ;
struct V_26 V_27 ;
int V_29 ;
if ( V_13 -> V_20 < V_14 + 8 )
return - 1 ;
V_19 = V_13 -> V_30 + V_14 ;
V_15 [ 0 ] = * V_19 ++ ;
V_15 [ 1 ] = * V_19 ++ ;
V_15 [ 2 ] = * V_19 ++ ;
V_1 = * V_19 ++ >> 6 ;
if ( V_1 != V_17 -> V_6 )
return - 1 ;
V_18 = 3 + V_17 -> V_21 ;
memcpy ( V_15 + 3 , V_17 -> V_15 , V_17 -> V_21 ) ;
V_31 = V_13 -> V_20 - V_14 - 8 ;
F_18 ( V_17 -> V_9 , V_15 , V_18 ) ;
F_19 ( & V_27 , V_19 , V_31 + 4 ) ;
F_20 ( V_23 , V_17 -> V_9 ) ;
F_21 ( V_23 , 0 , NULL , NULL ) ;
F_22 ( V_23 , & V_27 , & V_27 , V_31 + 4 , NULL ) ;
V_29 = F_26 ( V_23 ) ;
F_24 ( V_23 ) ;
if ( V_29 )
return - 7 ;
V_24 = ~ F_16 ( ~ 0 , V_19 , V_31 ) ;
V_25 [ 0 ] = V_24 ;
V_25 [ 1 ] = V_24 >> 8 ;
V_25 [ 2 ] = V_24 >> 16 ;
V_25 [ 3 ] = V_24 >> 24 ;
if ( memcmp ( V_25 , V_19 + V_31 , 4 ) != 0 ) {
return - 2 ;
}
memmove ( V_13 -> V_30 + 4 , V_13 -> V_30 , V_14 ) ;
F_27 ( V_13 , 4 ) ;
F_28 ( V_13 , V_13 -> V_20 - 4 ) ;
return 0 ;
}
static int F_29 ( void * V_15 , int V_20 , T_1 * V_32 , void * V_3 )
{
struct V_2 * V_17 = V_3 ;
if ( V_20 < 0 || V_20 > V_28 )
return - 1 ;
memcpy ( V_17 -> V_15 , V_15 , V_20 ) ;
V_17 -> V_21 = V_20 ;
return 0 ;
}
static int F_30 ( void * V_15 , int V_20 , T_1 * V_32 , void * V_3 )
{
struct V_2 * V_17 = V_3 ;
if ( V_20 < V_17 -> V_21 )
return - 1 ;
memcpy ( V_15 , V_17 -> V_15 , V_17 -> V_21 ) ;
return V_17 -> V_21 ;
}
static void F_31 ( struct V_33 * V_34 , void * V_3 )
{
struct V_2 * V_17 = V_3 ;
F_32 ( V_34 , L_2 , V_17 -> V_6 , V_17 -> V_21 ) ;
}
static int T_3 F_33 ( void )
{
return F_34 ( & V_35 ) ;
}
static void T_4 F_35 ( void )
{
F_36 ( & V_35 ) ;
}
