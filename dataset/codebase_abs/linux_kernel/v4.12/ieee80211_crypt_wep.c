static void * F_1 ( int V_1 )
{
struct V_2 * V_3 ;
V_3 = F_2 ( sizeof( * V_3 ) , V_4 ) ;
if ( ! V_3 )
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
struct V_22 * V_23 = (struct V_22 * ) ( V_14 -> V_24 + V_25 ) ;
T_1 V_26 ;
T_2 * V_27 ;
struct V_28 V_29 ;
int V_30 ;
if ( F_10 ( V_14 ) < 4 || F_11 ( V_14 ) < 4 ||
V_14 -> V_18 < V_15 )
return - 1 ;
V_18 = V_14 -> V_18 - V_15 ;
V_21 = F_12 ( V_14 , 4 ) ;
memmove ( V_21 , V_21 + 4 , V_15 ) ;
V_21 += V_15 ;
V_17 = 3 + V_16 -> V_31 ;
V_16 -> V_11 ++ ;
if ( ( V_16 -> V_11 & 0xff00 ) == 0xff00 ) {
T_2 V_32 = ( V_16 -> V_11 >> 16 ) & 0xff ;
if ( V_32 >= 3 && V_32 < V_17 )
V_16 -> V_11 += 0x0100 ;
}
* V_21 ++ = V_19 [ 0 ] = ( V_16 -> V_11 >> 16 ) & 0xff ;
* V_21 ++ = V_19 [ 1 ] = ( V_16 -> V_11 >> 8 ) & 0xff ;
* V_21 ++ = V_19 [ 2 ] = V_16 -> V_11 & 0xff ;
* V_21 ++ = V_16 -> V_5 << 6 ;
memcpy ( V_19 + 3 , V_16 -> V_19 , V_16 -> V_31 ) ;
if ( ! V_23 -> V_33 ) {
F_13 ( V_34 , V_16 -> V_6 ) ;
V_26 = ~ F_14 ( ~ 0 , V_21 , V_18 ) ;
V_27 = F_15 ( V_14 , 4 ) ;
V_27 [ 0 ] = V_26 ;
V_27 [ 1 ] = V_26 >> 8 ;
V_27 [ 2 ] = V_26 >> 16 ;
V_27 [ 3 ] = V_26 >> 24 ;
F_16 ( V_16 -> V_6 , V_19 , V_17 ) ;
F_17 ( & V_29 , V_21 , V_18 + 4 ) ;
F_18 ( V_34 , V_16 -> V_6 ) ;
F_19 ( V_34 , 0 , NULL , NULL ) ;
F_20 ( V_34 , & V_29 , & V_29 , V_18 + 4 , NULL ) ;
V_30 = F_21 ( V_34 ) ;
F_22 ( V_34 ) ;
return V_30 ;
}
return 0 ;
}
static int F_23 ( struct V_13 * V_14 , int V_15 , void * V_3 )
{
struct V_2 * V_16 = V_3 ;
T_1 V_17 , V_35 ;
T_2 V_19 [ V_20 + 3 ] ;
T_2 V_1 , * V_21 ;
struct V_22 * V_23 = (struct V_22 * ) ( V_14 -> V_24 + V_25 ) ;
T_1 V_26 ;
T_2 V_27 [ 4 ] ;
struct V_28 V_29 ;
int V_30 ;
if ( V_14 -> V_18 < V_15 + 8 )
return - 1 ;
V_21 = V_14 -> V_36 + V_15 ;
V_19 [ 0 ] = * V_21 ++ ;
V_19 [ 1 ] = * V_21 ++ ;
V_19 [ 2 ] = * V_21 ++ ;
V_1 = * V_21 ++ >> 6 ;
if ( V_1 != V_16 -> V_5 )
return - 1 ;
V_17 = 3 + V_16 -> V_31 ;
memcpy ( V_19 + 3 , V_16 -> V_19 , V_16 -> V_31 ) ;
V_35 = V_14 -> V_18 - V_15 - 8 ;
if ( ! V_23 -> V_33 ) {
F_13 ( V_34 , V_16 -> V_9 ) ;
F_16 ( V_16 -> V_9 , V_19 , V_17 ) ;
F_17 ( & V_29 , V_21 , V_35 + 4 ) ;
F_18 ( V_34 , V_16 -> V_9 ) ;
F_19 ( V_34 , 0 , NULL , NULL ) ;
F_20 ( V_34 , & V_29 , & V_29 , V_35 + 4 , NULL ) ;
V_30 = F_24 ( V_34 ) ;
F_22 ( V_34 ) ;
if ( V_30 )
return - 7 ;
V_26 = ~ F_14 ( ~ 0 , V_21 , V_35 ) ;
V_27 [ 0 ] = V_26 ;
V_27 [ 1 ] = V_26 >> 8 ;
V_27 [ 2 ] = V_26 >> 16 ;
V_27 [ 3 ] = V_26 >> 24 ;
if ( memcmp ( V_27 , V_21 + V_35 , 4 ) != 0 ) {
return - 2 ;
}
}
memmove ( V_14 -> V_36 + 4 , V_14 -> V_36 , V_15 ) ;
F_25 ( V_14 , 4 ) ;
F_26 ( V_14 , V_14 -> V_18 - 4 ) ;
return 0 ;
}
static int F_27 ( void * V_19 , int V_18 , T_2 * V_37 , void * V_3 )
{
struct V_2 * V_16 = V_3 ;
if ( V_18 < 0 || V_18 > V_20 )
return - 1 ;
memcpy ( V_16 -> V_19 , V_19 , V_18 ) ;
V_16 -> V_31 = V_18 ;
return 0 ;
}
static int F_28 ( void * V_19 , int V_18 , T_2 * V_37 , void * V_3 )
{
struct V_2 * V_16 = V_3 ;
if ( V_18 < V_16 -> V_31 )
return - 1 ;
memcpy ( V_19 , V_16 -> V_19 , V_16 -> V_31 ) ;
return V_16 -> V_31 ;
}
static char * F_29 ( char * V_38 , void * V_3 )
{
struct V_2 * V_16 = V_3 ;
V_38 += sprintf ( V_38 , L_2 ,
V_16 -> V_5 , V_16 -> V_31 ) ;
return V_38 ;
}
int T_3 F_30 ( void )
{
return F_31 ( & V_39 ) ;
}
void T_4 F_32 ( void )
{
F_33 ( & V_39 ) ;
}
