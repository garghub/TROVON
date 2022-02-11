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
V_8 = F_3 ( V_15 [ V_3 ] , 0 , 0 ) ;
if ( F_4 ( V_8 ) )
return ( F_5 ( V_8 ) == - V_16 ) ? F_6 ( - V_17 ) : F_7 ( V_8 ) ;
V_12 = F_8 ( V_8 ) + sizeof( * V_10 ) ;
V_11 = F_9 ( V_8 ) ;
V_13 = - V_18 ;
V_6 = F_10 ( V_11 + sizeof( * V_6 ) + V_12 , V_19 ) ;
if ( ! V_6 )
goto V_20;
V_6 -> V_21 = V_3 ;
V_6 -> V_22 = ( V_23 * ) V_6 + sizeof( * V_6 ) + V_12 ;
V_6 -> V_11 = V_11 ;
V_10 = ( void * ) V_6 + sizeof( * V_6 ) ;
V_10 -> V_8 = V_8 ;
V_10 -> V_24 = V_25 ;
V_13 = F_11 ( V_10 ) ;
if ( V_13 < 0 )
goto error;
V_13 = F_12 ( V_10 , V_4 , V_5 , V_6 -> V_22 ) ;
if ( V_13 < 0 )
goto error;
F_13 ( V_8 ) ;
F_2 ( L_2 , V_14 ) ;
return V_6 ;
error:
F_14 ( V_6 ) ;
V_20:
F_13 ( V_8 ) ;
F_2 ( L_3 , V_14 , V_13 ) ;
return F_6 ( V_13 ) ;
}
static int F_15 ( struct V_1 * V_6 ,
const void * V_26 , T_1 V_27 )
{
T_1 V_28 ;
T_2 V_29 ;
if ( V_27 < 3 )
return - V_30 ;
V_28 = ( ( const V_23 * ) V_26 ) [ 0 ] << 8 | ( ( const V_23 * ) V_26 ) [ 1 ] ;
V_26 += 2 ;
V_27 -= 2 ;
if ( V_27 != V_28 )
return - V_30 ;
V_29 = F_16 ( V_26 , V_28 ) ;
if ( ! V_29 )
return - V_18 ;
V_6 -> V_29 [ 0 ] = V_29 ;
V_6 -> V_31 = 1 ;
return 0 ;
}
static struct V_32 * F_17 ( const char * V_33 , T_1 V_34 ,
const V_23 * V_35 , T_1 V_36 )
{
T_3 V_32 ;
T_1 V_37 ;
char * V_38 , * V_39 ;
F_2 ( L_4 , V_14 , V_34 , V_36 ) ;
V_38 = F_18 ( V_34 + 2 + V_36 * 2 + 1 , V_19 ) ;
if ( ! V_38 )
return F_6 ( - V_40 ) ;
memcpy ( V_38 , V_33 , V_34 ) ;
V_39 = V_38 + V_34 ;
* V_39 ++ = ':' ;
* V_39 ++ = ' ' ;
for ( V_37 = 0 ; V_37 < V_36 ; V_37 ++ ) {
* V_39 ++ = V_41 [ * V_35 >> 4 ] ;
* V_39 ++ = V_41 [ * V_35 ++ & 0x0f ] ;
}
* V_39 = 0 ;
F_19 ( L_5 , V_38 ) ;
V_32 = F_20 ( F_21 ( V_42 , 1 ) ,
& V_43 , V_38 ) ;
if ( F_4 ( V_32 ) )
F_22 ( L_6 ,
V_38 , F_5 ( V_32 ) ) ;
F_14 ( V_38 ) ;
if ( F_4 ( V_32 ) ) {
switch ( F_5 ( V_32 ) ) {
case - V_44 :
case - V_45 :
case - V_46 :
return F_6 ( - V_40 ) ;
default:
return F_7 ( V_32 ) ;
}
}
F_2 ( L_7 , V_14 , F_23 ( F_24 ( V_32 ) ) ) ;
return F_24 ( V_32 ) ;
}
int F_25 ( const void * V_4 , unsigned long * V_47 )
{
struct V_1 * V_6 ;
struct V_48 V_49 ;
struct V_32 * V_32 ;
const void * V_50 ;
T_1 V_5 = * V_47 , V_51 ;
int V_13 ;
F_2 ( L_8 , V_14 , V_5 ) ;
if ( V_5 <= sizeof( V_49 ) )
return - V_30 ;
memcpy ( & V_49 , V_4 + ( V_5 - sizeof( V_49 ) ) , sizeof( V_49 ) ) ;
V_5 -= sizeof( V_49 ) ;
V_51 = F_26 ( V_49 . V_51 ) ;
if ( V_51 >= V_5 )
return - V_30 ;
V_5 -= V_51 ;
if ( ( T_1 ) V_49 . V_34 + V_49 . V_36 >= V_5 )
return - V_30 ;
V_5 -= ( T_1 ) V_49 . V_34 + V_49 . V_36 ;
* V_47 = V_5 ;
V_50 = V_4 + V_5 ;
if ( V_49 . V_52 != V_53 ||
V_49 . V_54 != V_55 )
return - V_17 ;
if ( V_49 . V_3 >= V_56 ||
! V_15 [ V_49 . V_3 ] )
return - V_17 ;
V_32 = F_17 ( V_50 , V_49 . V_34 ,
V_50 + V_49 . V_34 , V_49 . V_36 ) ;
if ( F_4 ( V_32 ) )
return F_5 ( V_32 ) ;
V_6 = F_1 ( V_49 . V_3 , V_4 , V_5 ) ;
if ( F_4 ( V_6 ) ) {
V_13 = F_5 ( V_6 ) ;
goto V_57;
}
V_13 = F_15 ( V_6 , V_50 + V_49 . V_34 + V_49 . V_36 ,
V_51 ) ;
if ( V_13 < 0 )
goto V_58;
V_13 = F_27 ( V_32 , V_6 ) ;
F_2 ( L_9 , V_13 ) ;
V_58:
F_28 ( V_6 -> V_59 . V_60 ) ;
F_14 ( V_6 ) ;
V_57:
F_29 ( V_32 ) ;
F_2 ( L_3 , V_14 , V_13 ) ;
return V_13 ;
}
