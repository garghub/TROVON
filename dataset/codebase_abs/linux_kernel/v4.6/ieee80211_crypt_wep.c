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
F_6 ( V_12 -> V_6 ) ;
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
T_1 V_25 ;
T_2 * V_26 ;
struct V_27 V_28 ;
int V_29 ;
if ( F_10 ( V_14 ) < 4 || F_11 ( V_14 ) < 4 ||
V_14 -> V_18 < V_15 )
return - 1 ;
V_18 = V_14 -> V_18 - V_15 ;
V_21 = F_12 ( V_14 , 4 ) ;
memmove ( V_21 , V_21 + 4 , V_15 ) ;
V_21 += V_15 ;
V_17 = 3 + V_16 -> V_30 ;
V_16 -> V_11 ++ ;
if ( ( V_16 -> V_11 & 0xff00 ) == 0xff00 ) {
T_2 V_31 = ( V_16 -> V_11 >> 16 ) & 0xff ;
if ( V_31 >= 3 && V_31 < V_17 )
V_16 -> V_11 += 0x0100 ;
}
* V_21 ++ = V_19 [ 0 ] = ( V_16 -> V_11 >> 16 ) & 0xff ;
* V_21 ++ = V_19 [ 1 ] = ( V_16 -> V_11 >> 8 ) & 0xff ;
* V_21 ++ = V_19 [ 2 ] = V_16 -> V_11 & 0xff ;
* V_21 ++ = V_16 -> V_5 << 6 ;
memcpy ( V_19 + 3 , V_16 -> V_19 , V_16 -> V_30 ) ;
if ( ! V_22 -> V_32 ) {
F_13 ( V_33 , V_16 -> V_6 ) ;
V_25 = ~ F_14 ( ~ 0 , V_21 , V_18 ) ;
V_26 = F_15 ( V_14 , 4 ) ;
V_26 [ 0 ] = V_25 ;
V_26 [ 1 ] = V_25 >> 8 ;
V_26 [ 2 ] = V_25 >> 16 ;
V_26 [ 3 ] = V_25 >> 24 ;
F_16 ( V_16 -> V_6 , V_19 , V_17 ) ;
F_17 ( & V_28 , V_21 , V_18 + 4 ) ;
F_18 ( V_33 , V_16 -> V_6 ) ;
F_19 ( V_33 , 0 , NULL , NULL ) ;
F_20 ( V_33 , & V_28 , & V_28 , V_18 + 4 , NULL ) ;
V_29 = F_21 ( V_33 ) ;
F_22 ( V_33 ) ;
return V_29 ;
}
return 0 ;
}
static int F_23 ( struct V_13 * V_14 , int V_15 , void * V_3 )
{
struct V_2 * V_16 = V_3 ;
T_1 V_17 , V_34 ;
T_2 V_19 [ V_20 + 3 ] ;
T_2 V_1 , * V_21 ;
T_3 * V_22 = ( T_3 * ) ( V_14 -> V_23 + V_24 ) ;
T_1 V_25 ;
T_2 V_26 [ 4 ] ;
struct V_27 V_28 ;
int V_29 ;
if ( V_14 -> V_18 < V_15 + 8 )
return - 1 ;
V_21 = V_14 -> V_35 + V_15 ;
V_19 [ 0 ] = * V_21 ++ ;
V_19 [ 1 ] = * V_21 ++ ;
V_19 [ 2 ] = * V_21 ++ ;
V_1 = * V_21 ++ >> 6 ;
if ( V_1 != V_16 -> V_5 )
return - 1 ;
V_17 = 3 + V_16 -> V_30 ;
memcpy ( V_19 + 3 , V_16 -> V_19 , V_16 -> V_30 ) ;
V_34 = V_14 -> V_18 - V_15 - 8 ;
if ( ! V_22 -> V_32 ) {
F_13 ( V_33 , V_16 -> V_9 ) ;
F_16 ( V_16 -> V_9 , V_19 , V_17 ) ;
F_17 ( & V_28 , V_21 , V_34 + 4 ) ;
F_18 ( V_33 , V_16 -> V_9 ) ;
F_19 ( V_33 , 0 , NULL , NULL ) ;
F_20 ( V_33 , & V_28 , & V_28 , V_34 + 4 , NULL ) ;
V_29 = F_24 ( V_33 ) ;
F_22 ( V_33 ) ;
if ( V_29 )
return - 7 ;
V_25 = ~ F_14 ( ~ 0 , V_21 , V_34 ) ;
V_26 [ 0 ] = V_25 ;
V_26 [ 1 ] = V_25 >> 8 ;
V_26 [ 2 ] = V_25 >> 16 ;
V_26 [ 3 ] = V_25 >> 24 ;
if ( memcmp ( V_26 , V_21 + V_34 , 4 ) != 0 ) {
return - 2 ;
}
}
memmove ( V_14 -> V_35 + 4 , V_14 -> V_35 , V_15 ) ;
F_25 ( V_14 , 4 ) ;
F_26 ( V_14 , V_14 -> V_18 - 4 ) ;
return 0 ;
}
static int F_27 ( void * V_19 , int V_18 , T_2 * V_36 , void * V_3 )
{
struct V_2 * V_16 = V_3 ;
if ( V_18 < 0 || V_18 > V_20 )
return - 1 ;
memcpy ( V_16 -> V_19 , V_19 , V_18 ) ;
V_16 -> V_30 = V_18 ;
return 0 ;
}
static int F_28 ( void * V_19 , int V_18 , T_2 * V_36 , void * V_3 )
{
struct V_2 * V_16 = V_3 ;
if ( V_18 < V_16 -> V_30 )
return - 1 ;
memcpy ( V_19 , V_16 -> V_19 , V_16 -> V_30 ) ;
return V_16 -> V_30 ;
}
static char * F_29 ( char * V_37 , void * V_3 )
{
struct V_2 * V_16 = V_3 ;
V_37 += sprintf ( V_37 , L_2 ,
V_16 -> V_5 , V_16 -> V_30 ) ;
return V_37 ;
}
int T_4 F_30 ( void )
{
return F_31 ( & V_38 ) ;
}
void T_5 F_32 ( void )
{
F_33 ( & V_38 ) ;
}
