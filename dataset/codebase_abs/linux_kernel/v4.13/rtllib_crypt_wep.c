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
F_7 ( V_3 -> V_7 ) ;
F_7 ( V_3 -> V_9 ) ;
F_8 ( V_3 ) ;
}
return NULL ;
}
static void F_9 ( void * V_3 )
{
struct V_2 * V_11 = V_3 ;
if ( V_11 ) {
F_7 ( V_11 -> V_7 ) ;
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
T_1 V_25 ;
T_2 * V_26 ;
struct V_27 V_28 ;
int V_29 ;
if ( F_11 ( V_13 ) < 4 || F_12 ( V_13 ) < 4 ||
V_13 -> V_17 < V_14 ) {
F_13 ( L_3 ,
F_11 ( V_13 ) , F_12 ( V_13 ) , V_13 -> V_17 , V_14 ) ;
return - 1 ;
}
V_17 = V_13 -> V_17 - V_14 ;
V_20 = F_14 ( V_13 , 4 ) ;
memmove ( V_20 , V_20 + 4 , V_14 ) ;
V_20 += V_14 ;
V_16 = 3 + V_15 -> V_30 ;
V_15 -> V_10 ++ ;
if ( ( V_15 -> V_10 & 0xff00 ) == 0xff00 ) {
T_2 V_31 = ( V_15 -> V_10 >> 16 ) & 0xff ;
if ( V_31 >= 3 && V_31 < V_16 )
V_15 -> V_10 += 0x0100 ;
}
* V_20 ++ = V_18 [ 0 ] = ( V_15 -> V_10 >> 16 ) & 0xff ;
* V_20 ++ = V_18 [ 1 ] = ( V_15 -> V_10 >> 8 ) & 0xff ;
* V_20 ++ = V_18 [ 2 ] = V_15 -> V_10 & 0xff ;
* V_20 ++ = V_15 -> V_6 << 6 ;
memcpy ( V_18 + 3 , V_15 -> V_18 , V_15 -> V_30 ) ;
if ( ! V_22 -> V_32 ) {
F_15 ( V_33 , V_15 -> V_7 ) ;
V_25 = ~ F_16 ( ~ 0 , V_20 , V_17 ) ;
V_26 = F_17 ( V_13 , 4 ) ;
V_26 [ 0 ] = V_25 ;
V_26 [ 1 ] = V_25 >> 8 ;
V_26 [ 2 ] = V_25 >> 16 ;
V_26 [ 3 ] = V_25 >> 24 ;
F_18 ( & V_28 , V_20 , V_17 + 4 ) ;
F_19 ( V_15 -> V_7 , V_18 , V_16 ) ;
F_20 ( V_33 , V_15 -> V_7 ) ;
F_21 ( V_33 , 0 , NULL , NULL ) ;
F_22 ( V_33 , & V_28 , & V_28 , V_17 + 4 , NULL ) ;
V_29 = F_23 ( V_33 ) ;
F_24 ( V_33 ) ;
return V_29 ;
}
return 0 ;
}
static int F_25 ( struct V_12 * V_13 , int V_14 , void * V_3 )
{
struct V_2 * V_15 = V_3 ;
T_1 V_16 , V_34 ;
T_2 V_18 [ V_19 + 3 ] ;
T_2 V_1 , * V_20 ;
struct V_21 * V_22 = (struct V_21 * ) ( V_13 -> V_23 +
V_24 ) ;
T_1 V_25 ;
T_2 V_26 [ 4 ] ;
struct V_27 V_28 ;
int V_29 ;
if ( V_13 -> V_17 < V_14 + 8 )
return - 1 ;
V_20 = V_13 -> V_35 + V_14 ;
V_18 [ 0 ] = * V_20 ++ ;
V_18 [ 1 ] = * V_20 ++ ;
V_18 [ 2 ] = * V_20 ++ ;
V_1 = * V_20 ++ >> 6 ;
if ( V_1 != V_15 -> V_6 )
return - 1 ;
V_16 = 3 + V_15 -> V_30 ;
memcpy ( V_18 + 3 , V_15 -> V_18 , V_15 -> V_30 ) ;
V_34 = V_13 -> V_17 - V_14 - 8 ;
if ( ! V_22 -> V_32 ) {
F_15 ( V_33 , V_15 -> V_9 ) ;
F_18 ( & V_28 , V_20 , V_34 + 4 ) ;
F_19 ( V_15 -> V_9 , V_18 , V_16 ) ;
F_20 ( V_33 , V_15 -> V_9 ) ;
F_21 ( V_33 , 0 , NULL , NULL ) ;
F_22 ( V_33 , & V_28 , & V_28 , V_34 + 4 , NULL ) ;
V_29 = F_26 ( V_33 ) ;
F_24 ( V_33 ) ;
if ( V_29 )
return - 7 ;
V_25 = ~ F_16 ( ~ 0 , V_20 , V_34 ) ;
V_26 [ 0 ] = V_25 ;
V_26 [ 1 ] = V_25 >> 8 ;
V_26 [ 2 ] = V_25 >> 16 ;
V_26 [ 3 ] = V_25 >> 24 ;
if ( memcmp ( V_26 , V_20 + V_34 , 4 ) != 0 ) {
return - 2 ;
}
}
memmove ( V_13 -> V_35 + 4 , V_13 -> V_35 , V_14 ) ;
F_27 ( V_13 , 4 ) ;
F_28 ( V_13 , V_13 -> V_17 - 4 ) ;
return 0 ;
}
static int F_29 ( void * V_18 , int V_17 , T_2 * V_36 , void * V_3 )
{
struct V_2 * V_15 = V_3 ;
if ( V_17 < 0 || V_17 > V_19 )
return - 1 ;
memcpy ( V_15 -> V_18 , V_18 , V_17 ) ;
V_15 -> V_30 = V_17 ;
return 0 ;
}
static int F_30 ( void * V_18 , int V_17 , T_2 * V_36 , void * V_3 )
{
struct V_2 * V_15 = V_3 ;
if ( V_17 < V_15 -> V_30 )
return - 1 ;
memcpy ( V_18 , V_15 -> V_18 , V_15 -> V_30 ) ;
return V_15 -> V_30 ;
}
static void F_31 ( struct V_37 * V_38 , void * V_3 )
{
struct V_2 * V_15 = V_3 ;
F_32 ( V_38 , L_4 , V_15 -> V_6 , V_15 -> V_30 ) ;
}
static int T_3 F_33 ( void )
{
return F_34 ( & V_39 ) ;
}
static void T_4 F_35 ( void )
{
F_36 ( & V_39 ) ;
}
