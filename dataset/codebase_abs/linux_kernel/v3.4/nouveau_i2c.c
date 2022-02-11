static void
F_1 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
if ( V_4 -> type == 0 ) {
T_1 V_5 = F_2 ( V_4 -> V_6 , 0 , V_4 -> V_7 ) ;
if ( V_2 ) V_5 |= 0x20 ;
else V_5 &= 0xdf ;
F_3 ( V_4 -> V_6 , 0 , V_4 -> V_7 , V_5 | 0x01 ) ;
} else
if ( V_4 -> type == 4 ) {
F_4 ( V_4 -> V_6 , V_4 -> V_7 , 0x2f , V_2 ? 0x21 : 0x01 ) ;
} else
if ( V_4 -> type == 5 ) {
if ( V_2 ) V_4 -> V_2 |= 0x01 ;
else V_4 -> V_2 &= 0xfe ;
F_5 ( V_4 -> V_6 , V_4 -> V_7 , 4 | V_4 -> V_2 ) ;
}
}
static void
F_6 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
if ( V_4 -> type == 0 ) {
T_1 V_5 = F_2 ( V_4 -> V_6 , 0 , V_4 -> V_7 ) ;
if ( V_2 ) V_5 |= 0x10 ;
else V_5 &= 0xef ;
F_3 ( V_4 -> V_6 , 0 , V_4 -> V_7 , V_5 | 0x01 ) ;
} else
if ( V_4 -> type == 4 ) {
F_4 ( V_4 -> V_6 , V_4 -> V_7 , 0x1f , V_2 ? 0x11 : 0x01 ) ;
} else
if ( V_4 -> type == 5 ) {
if ( V_2 ) V_4 -> V_2 |= 0x02 ;
else V_4 -> V_2 &= 0xfd ;
F_5 ( V_4 -> V_6 , V_4 -> V_7 , 4 | V_4 -> V_2 ) ;
}
}
static int
F_7 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
struct V_8 * V_9 = V_4 -> V_6 -> V_10 ;
if ( V_4 -> type == 0 ) {
return ! ! ( F_2 ( V_4 -> V_6 , 0 , V_4 -> V_11 ) & 0x04 ) ;
} else
if ( V_4 -> type == 4 ) {
return ! ! ( F_8 ( V_4 -> V_6 , V_4 -> V_11 ) & 0x00040000 ) ;
} else
if ( V_4 -> type == 5 ) {
if ( V_9 -> V_12 < V_13 )
return ! ! ( F_8 ( V_4 -> V_6 , V_4 -> V_11 ) & 0x01 ) ;
else
return ! ! ( F_8 ( V_4 -> V_6 , V_4 -> V_11 ) & 0x10 ) ;
}
return 0 ;
}
static int
F_9 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
struct V_8 * V_9 = V_4 -> V_6 -> V_10 ;
if ( V_4 -> type == 0 ) {
return ! ! ( F_2 ( V_4 -> V_6 , 0 , V_4 -> V_11 ) & 0x08 ) ;
} else
if ( V_4 -> type == 4 ) {
return ! ! ( F_8 ( V_4 -> V_6 , V_4 -> V_11 ) & 0x00080000 ) ;
} else
if ( V_4 -> type == 5 ) {
if ( V_9 -> V_12 < V_13 )
return ! ! ( F_8 ( V_4 -> V_6 , V_4 -> V_11 ) & 0x02 ) ;
else
return ! ! ( F_8 ( V_4 -> V_6 , V_4 -> V_11 ) & 0x20 ) ;
}
return 0 ;
}
static T_1 *
F_10 ( struct V_14 * V_6 , T_1 * V_15 )
{
T_1 * V_16 = F_11 ( V_6 ) , * V_17 = NULL ;
if ( V_16 ) {
if ( V_16 [ 0 ] >= 0x15 )
V_17 = F_12 ( V_6 , V_16 [ 2 ] ) ;
if ( V_16 [ 0 ] >= 0x30 )
V_17 = F_12 ( V_6 , V_16 [ 4 ] ) ;
}
if ( V_17 ) {
* V_15 = V_16 [ 0 ] ;
if ( * V_15 >= 0x30 )
* V_15 = V_17 [ 0 ] ;
}
return V_17 ;
}
int
F_13 ( struct V_14 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_18 * V_19 = & V_9 -> V_20 ;
struct V_3 * V_4 ;
T_1 V_15 = 0x00 , V_21 , V_22 ;
T_1 * V_17 , * V_23 , V_24 [ 2 ] [ 4 ] = {} ;
int V_25 , V_26 ;
F_14 ( & V_9 -> V_27 ) ;
V_17 = F_10 ( V_6 , & V_15 ) ;
if ( ! V_17 ) {
T_1 * V_28 = & V_19 -> V_1 [ V_19 -> V_29 ] ;
if ( V_19 -> type != V_30 )
return - V_31 ;
V_24 [ 0 ] [ 0 ] = V_32 ;
V_24 [ 0 ] [ 1 ] = V_33 ;
V_24 [ 1 ] [ 0 ] = V_34 ;
V_24 [ 1 ] [ 1 ] = V_35 ;
if ( V_28 [ 5 ] < 4 )
V_17 = & V_19 -> V_1 [ 0x48 ] ;
else
V_17 = & V_28 [ 0x36 ] ;
if ( V_17 [ 4 ] ) V_24 [ 0 ] [ 0 ] = V_17 [ 4 ] ;
if ( V_17 [ 5 ] ) V_24 [ 0 ] [ 1 ] = V_17 [ 5 ] ;
if ( V_17 [ 6 ] ) V_24 [ 1 ] [ 0 ] = V_17 [ 6 ] ;
if ( V_17 [ 7 ] ) V_24 [ 1 ] [ 1 ] = V_17 [ 7 ] ;
}
if ( V_15 >= 0x30 ) {
V_23 = V_17 [ 1 ] + V_17 ;
V_21 = V_17 [ 2 ] ;
V_22 = V_17 [ 3 ] ;
} else
if ( V_15 ) {
V_23 = V_17 ;
V_21 = 16 ;
V_22 = 4 ;
} else {
V_23 = V_24 [ 0 ] ;
V_21 = 2 ;
V_22 = 4 ;
}
for ( V_26 = 0 ; V_26 < V_21 ; V_26 ++ , V_23 += V_22 ) {
V_4 = F_15 ( sizeof( * V_4 ) , V_36 ) ;
if ( V_4 == NULL ) {
F_16 ( V_6 ) ;
return - V_37 ;
}
V_4 -> type = V_23 [ 3 ] ;
if ( V_15 < 0x30 ) {
V_4 -> type &= 0x07 ;
if ( V_4 -> type == 0x07 )
V_4 -> type = 0xff ;
}
if ( V_4 -> type == 0xff ) {
F_17 ( V_4 ) ;
continue;
}
switch ( V_4 -> type ) {
case 0 :
V_4 -> V_7 = V_23 [ 0 ] ;
V_4 -> V_11 = V_23 [ 1 ] ;
break;
case 4 :
V_4 -> V_7 = 0x600800 + V_23 [ 1 ] ;
V_4 -> V_11 = V_4 -> V_7 ;
break;
case 5 :
V_4 -> V_7 = V_23 [ 0 ] & 0x0f ;
if ( V_9 -> V_12 < V_13 ) {
if ( V_4 -> V_7 >= F_18 ( V_38 ) )
break;
V_4 -> V_7 = V_38 [ V_4 -> V_7 ] ;
V_4 -> V_11 = V_4 -> V_7 ;
} else {
V_4 -> V_7 = 0x00d014 + ( V_4 -> V_7 * 0x20 ) ;
V_4 -> V_11 = V_4 -> V_7 ;
}
break;
case 6 :
V_4 -> V_7 = V_23 [ 0 ] ;
V_4 -> V_11 = V_4 -> V_7 ;
V_4 -> V_39 . V_40 = & V_41 ;
break;
default:
break;
}
if ( ! V_4 -> V_39 . V_40 && ! V_4 -> V_7 ) {
F_19 ( V_6 , L_1 ,
V_26 , V_4 -> type , V_4 -> V_7 , V_4 -> V_11 ) ;
F_17 ( V_4 ) ;
continue;
}
snprintf ( V_4 -> V_39 . V_42 , sizeof( V_4 -> V_39 . V_42 ) ,
L_2 , F_20 ( V_6 -> V_43 ) , V_26 ) ;
V_4 -> V_39 . V_44 = V_45 ;
V_4 -> V_39 . V_6 . V_46 = & V_6 -> V_43 -> V_6 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_47 = V_26 ;
V_4 -> V_16 = F_21 ( V_23 [ 0 ] ) ;
F_22 ( & V_4 -> V_39 , V_17 ) ;
if ( V_4 -> V_39 . V_40 != & V_41 ) {
V_4 -> V_39 . V_48 = & V_4 -> V_49 ;
V_4 -> V_49 . V_50 = 10 ;
V_4 -> V_49 . V_51 = F_23 ( 2200 ) ;
V_4 -> V_49 . V_1 = V_4 ;
V_4 -> V_49 . V_52 = F_6 ;
V_4 -> V_49 . V_53 = F_1 ;
V_4 -> V_49 . V_54 = F_9 ;
V_4 -> V_49 . V_55 = F_7 ;
F_1 ( V_4 , 0 ) ;
F_6 ( V_4 , 1 ) ;
F_1 ( V_4 , 1 ) ;
V_25 = F_24 ( & V_4 -> V_39 ) ;
} else {
V_4 -> V_39 . V_40 = & V_41 ;
V_25 = F_25 ( & V_4 -> V_39 ) ;
}
if ( V_25 ) {
F_19 ( V_6 , L_3 , V_26 , V_25 ) ;
F_17 ( V_4 ) ;
continue;
}
F_26 ( & V_4 -> V_56 , & V_9 -> V_27 ) ;
}
return 0 ;
}
void
F_16 ( struct V_14 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_3 * V_4 , * V_57 ;
F_27 (port, tmp, &dev_priv->i2c_ports, head) {
F_28 ( & V_4 -> V_39 ) ;
F_17 ( V_4 ) ;
}
}
struct V_3 *
F_29 ( struct V_14 * V_6 , T_1 V_47 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_3 * V_4 ;
if ( V_47 == F_30 ( 0 ) ||
V_47 == F_30 ( 1 ) ) {
T_1 V_15 , * V_17 = F_10 ( V_6 , & V_15 ) ;
if ( V_17 && V_15 >= 0x30 ) {
if ( V_47 == F_30 ( 0 ) )
V_47 = ( V_17 [ 4 ] & 0x0f ) ;
else
V_47 = ( V_17 [ 4 ] & 0xf0 ) >> 4 ;
} else {
V_47 = 2 ;
}
}
F_31 (port, &dev_priv->i2c_ports, head) {
if ( V_4 -> V_47 == V_47 )
break;
}
if ( & V_4 -> V_56 == & V_9 -> V_27 )
return NULL ;
if ( V_9 -> V_12 >= V_58 && ( V_4 -> V_16 & 0x00000100 ) ) {
T_2 V_59 = 0x00e500 , V_5 ;
if ( V_4 -> type == 6 ) {
V_59 += V_4 -> V_7 * 0x50 ;
V_5 = 0x2002 ;
} else {
V_59 += ( ( V_4 -> V_16 & 0x1e00 ) >> 9 ) * 0x50 ;
V_5 = 0xe001 ;
}
F_4 ( V_6 , V_59 + 0x0c , 0x00000001 , 0x00000000 ) ;
F_4 ( V_6 , V_59 + 0x00 , 0x0000f003 , V_5 ) ;
}
return V_4 ;
}
bool
F_32 ( struct V_3 * V_17 , int V_60 )
{
T_3 V_61 [] = { 0 } ;
struct V_62 V_63 [] = {
{
. V_60 = V_60 ,
. V_64 = 0 ,
. V_65 = 1 ,
. V_61 = V_61 ,
} ,
{
. V_60 = V_60 ,
. V_64 = V_66 ,
. V_65 = 1 ,
. V_61 = V_61 ,
}
} ;
return F_33 ( & V_17 -> V_39 , V_63 , 2 ) == 2 ;
}
int
F_34 ( struct V_14 * V_6 , const char * V_67 ,
struct V_68 * V_69 ,
bool (* F_35)( struct V_3 * ,
struct V_68 * ) ,
int V_47 )
{
struct V_3 * V_17 = F_29 ( V_6 , V_47 ) ;
int V_26 ;
if ( ! V_17 ) {
F_36 ( V_6 , L_4 , V_67 , V_47 ) ;
return - V_31 ;
}
F_36 ( V_6 , L_5 , V_67 , V_17 -> V_47 ) ;
for ( V_26 = 0 ; V_69 [ V_26 ] . V_60 ; V_26 ++ ) {
if ( F_32 ( V_17 , V_69 [ V_26 ] . V_60 ) &&
( ! F_35 || F_35 ( V_17 , & V_69 [ V_26 ] ) ) ) {
F_37 ( V_6 , L_6 , V_67 , V_69 [ V_26 ] . type ) ;
return V_26 ;
}
}
F_36 ( V_6 , L_7 ) ;
return - V_31 ;
}
