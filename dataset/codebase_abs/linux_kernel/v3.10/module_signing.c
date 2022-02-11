static struct V_1 * F_1 ( enum V_2 V_3 ,
const void * V_4 ,
unsigned long V_5 )
{
struct V_1 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
T_1 V_11 , V_12 ;
int V_13 ;
F_2 ( L_1 , V_14 ) ;
V_8 = F_3 ( V_2 [ V_3 ] , 0 , 0 ) ;
if ( F_4 ( V_8 ) )
return ( F_5 ( V_8 ) == - V_15 ) ? F_6 ( - V_16 ) : F_7 ( V_8 ) ;
V_12 = F_8 ( V_8 ) + sizeof( * V_10 ) ;
V_11 = F_9 ( V_8 ) ;
V_13 = - V_17 ;
V_6 = F_10 ( V_11 + sizeof( * V_6 ) + V_12 , V_18 ) ;
if ( ! V_6 )
goto V_19;
V_6 -> V_2 = V_3 ;
V_6 -> V_20 = ( V_21 * ) V_6 + sizeof( * V_6 ) + V_12 ;
V_6 -> V_11 = V_11 ;
V_10 = ( void * ) V_6 + sizeof( * V_6 ) ;
V_10 -> V_8 = V_8 ;
V_10 -> V_22 = V_23 ;
V_13 = F_11 ( V_10 ) ;
if ( V_13 < 0 )
goto error;
V_13 = F_12 ( V_10 , V_4 , V_5 , V_6 -> V_20 ) ;
if ( V_13 < 0 )
goto error;
F_13 ( V_8 ) ;
F_2 ( L_2 , V_14 ) ;
return V_6 ;
error:
F_14 ( V_6 ) ;
V_19:
F_13 ( V_8 ) ;
F_2 ( L_3 , V_14 , V_13 ) ;
return F_6 ( V_13 ) ;
}
static int F_15 ( struct V_1 * V_6 ,
const void * V_24 , T_1 V_25 )
{
T_1 V_26 ;
T_2 V_27 ;
if ( V_25 < 3 )
return - V_28 ;
V_26 = ( ( const V_21 * ) V_24 ) [ 0 ] << 8 | ( ( const V_21 * ) V_24 ) [ 1 ] ;
V_24 += 2 ;
V_25 -= 2 ;
if ( V_25 != V_26 )
return - V_28 ;
V_27 = F_16 ( V_24 , V_26 ) ;
if ( ! V_27 )
return - V_17 ;
V_6 -> V_27 [ 0 ] = V_27 ;
V_6 -> V_29 = 1 ;
return 0 ;
}
static struct V_30 * F_17 ( const char * V_31 , T_1 V_32 ,
const V_21 * V_33 , T_1 V_34 )
{
T_3 V_30 ;
T_1 V_35 ;
char * V_36 , * V_37 ;
F_2 ( L_4 , V_14 , V_32 , V_34 ) ;
V_36 = F_18 ( V_32 + 2 + V_34 * 2 + 1 , V_18 ) ;
if ( ! V_36 )
return F_6 ( - V_38 ) ;
memcpy ( V_36 , V_31 , V_32 ) ;
V_37 = V_36 + V_32 ;
* V_37 ++ = ':' ;
* V_37 ++ = ' ' ;
for ( V_35 = 0 ; V_35 < V_34 ; V_35 ++ ) {
* V_37 ++ = V_39 [ * V_33 >> 4 ] ;
* V_37 ++ = V_39 [ * V_33 ++ & 0x0f ] ;
}
* V_37 = 0 ;
F_19 ( L_5 , V_36 ) ;
V_30 = F_20 ( F_21 ( V_40 , 1 ) ,
& V_41 , V_36 ) ;
if ( F_4 ( V_30 ) )
F_22 ( L_6 ,
V_36 , F_5 ( V_30 ) ) ;
F_14 ( V_36 ) ;
if ( F_4 ( V_30 ) ) {
switch ( F_5 ( V_30 ) ) {
case - V_42 :
case - V_43 :
case - V_44 :
return F_6 ( - V_38 ) ;
default:
return F_7 ( V_30 ) ;
}
}
F_2 ( L_7 , V_14 , F_23 ( F_24 ( V_30 ) ) ) ;
return F_24 ( V_30 ) ;
}
int F_25 ( const void * V_4 , unsigned long * V_45 )
{
struct V_1 * V_6 ;
struct V_46 V_47 ;
struct V_30 * V_30 ;
const void * V_48 ;
T_1 V_5 = * V_45 , V_49 ;
int V_13 ;
F_2 ( L_8 , V_14 , V_5 ) ;
if ( V_5 <= sizeof( V_47 ) )
return - V_28 ;
memcpy ( & V_47 , V_4 + ( V_5 - sizeof( V_47 ) ) , sizeof( V_47 ) ) ;
V_5 -= sizeof( V_47 ) ;
V_49 = F_26 ( V_47 . V_49 ) ;
if ( V_49 >= V_5 )
return - V_28 ;
V_5 -= V_49 ;
if ( ( T_1 ) V_47 . V_32 + V_47 . V_34 >= V_5 )
return - V_28 ;
V_5 -= ( T_1 ) V_47 . V_32 + V_47 . V_34 ;
* V_45 = V_5 ;
V_48 = V_4 + V_5 ;
if ( V_47 . V_50 != V_51 ||
V_47 . V_52 != V_53 )
return - V_16 ;
if ( V_47 . V_3 >= V_54 ||
! V_2 [ V_47 . V_3 ] )
return - V_16 ;
V_30 = F_17 ( V_48 , V_47 . V_32 ,
V_48 + V_47 . V_32 , V_47 . V_34 ) ;
if ( F_4 ( V_30 ) )
return F_5 ( V_30 ) ;
V_6 = F_1 ( V_47 . V_3 , V_4 , V_5 ) ;
if ( F_4 ( V_6 ) ) {
V_13 = F_5 ( V_6 ) ;
goto V_55;
}
V_13 = F_15 ( V_6 , V_48 + V_47 . V_32 + V_47 . V_34 ,
V_49 ) ;
if ( V_13 < 0 )
goto V_56;
V_13 = F_27 ( V_30 , V_6 ) ;
F_2 ( L_9 , V_13 ) ;
V_56:
F_28 ( V_6 -> V_57 . V_58 ) ;
F_14 ( V_6 ) ;
V_55:
F_29 ( V_30 ) ;
F_2 ( L_3 , V_14 , V_13 ) ;
return V_13 ;
}
