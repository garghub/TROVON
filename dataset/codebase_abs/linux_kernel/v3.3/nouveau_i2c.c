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
static void
F_10 ( struct V_3 * V_4 , T_2 V_14 )
{
F_11 ( ( V_14 + 500 ) / 1000 ) ;
}
static bool
F_12 ( struct V_3 * V_4 )
{
T_2 V_15 = V_16 / V_17 ;
F_1 ( V_4 , 1 ) ;
do {
F_10 ( V_4 , V_17 ) ;
} while ( ! F_7 ( V_4 ) && -- V_15 );
return V_15 != 0 ;
}
static int
F_13 ( struct V_3 * V_4 )
{
int V_18 = 0 ;
V_4 -> V_2 = F_7 ( V_4 ) ;
V_4 -> V_2 |= F_9 ( V_4 ) << 1 ;
if ( V_4 -> V_2 != 3 ) {
F_1 ( V_4 , 0 ) ;
F_6 ( V_4 , 1 ) ;
if ( ! F_12 ( V_4 ) )
V_18 = - V_19 ;
}
F_6 ( V_4 , 0 ) ;
F_10 ( V_4 , V_20 ) ;
F_1 ( V_4 , 0 ) ;
F_10 ( V_4 , V_20 ) ;
return V_18 ;
}
static void
F_14 ( struct V_3 * V_4 )
{
F_1 ( V_4 , 0 ) ;
F_6 ( V_4 , 0 ) ;
F_10 ( V_4 , V_17 ) ;
F_1 ( V_4 , 1 ) ;
F_10 ( V_4 , V_20 ) ;
F_6 ( V_4 , 1 ) ;
F_10 ( V_4 , V_20 ) ;
}
static int
F_15 ( struct V_3 * V_4 , int V_21 )
{
F_6 ( V_4 , V_21 ) ;
F_10 ( V_4 , V_17 ) ;
if ( ! F_12 ( V_4 ) )
return - V_22 ;
F_10 ( V_4 , V_20 ) ;
F_1 ( V_4 , 0 ) ;
F_10 ( V_4 , V_20 ) ;
return 0 ;
}
static int
F_16 ( struct V_3 * V_4 )
{
int V_21 ;
F_6 ( V_4 , 1 ) ;
F_10 ( V_4 , V_17 ) ;
if ( ! F_12 ( V_4 ) )
return - V_22 ;
F_10 ( V_4 , V_20 ) ;
V_21 = F_9 ( V_4 ) ;
F_1 ( V_4 , 0 ) ;
F_10 ( V_4 , V_20 ) ;
return V_21 ;
}
static int
F_17 ( struct V_3 * V_4 , T_1 * V_23 , bool V_24 )
{
int V_25 , V_26 ;
* V_23 = 0 ;
for ( V_25 = 7 ; V_25 >= 0 ; V_25 -- ) {
V_26 = F_16 ( V_4 ) ;
if ( V_26 < 0 )
return V_26 ;
* V_23 |= V_26 << V_25 ;
}
return F_15 ( V_4 , V_24 ? 1 : 0 ) ;
}
static int
F_18 ( struct V_3 * V_4 , T_1 V_23 )
{
int V_25 , V_18 ;
for ( V_25 = 7 ; V_25 >= 0 ; V_25 -- ) {
V_18 = F_15 ( V_4 , ! ! ( V_23 & ( 1 << V_25 ) ) ) ;
if ( V_18 < 0 )
return V_18 ;
}
V_18 = F_16 ( V_4 ) ;
if ( V_18 == 1 )
V_18 = - V_27 ;
return V_18 ;
}
static int
F_19 ( struct V_3 * V_4 , struct V_28 * V_29 )
{
T_2 V_30 = V_29 -> V_30 << 1 ;
if ( V_29 -> V_31 & V_32 )
V_30 |= 1 ;
return F_18 ( V_4 , V_30 ) ;
}
static int
F_20 ( struct V_33 * V_34 , struct V_28 * V_35 , int V_36 )
{
struct V_3 * V_4 = (struct V_3 * ) V_34 ;
struct V_28 * V_29 = V_35 ;
int V_18 = 0 , V_37 = V_36 ;
while ( ! V_18 && V_37 -- ) {
T_1 V_38 = V_29 -> V_39 ;
T_1 * V_40 = V_29 -> V_41 ;
V_18 = F_13 ( V_4 ) ;
if ( V_18 == 0 )
V_18 = F_19 ( V_4 , V_29 ) ;
if ( V_29 -> V_31 & V_32 ) {
while ( ! V_18 && V_38 -- )
V_18 = F_17 ( V_4 , V_40 ++ , ! V_38 ) ;
} else {
while ( ! V_18 && V_38 -- )
V_18 = F_18 ( V_4 , * V_40 ++ ) ;
}
V_29 ++ ;
}
F_14 ( V_4 ) ;
return ( V_18 < 0 ) ? V_18 : V_36 ;
}
static T_2
F_21 ( struct V_33 * V_34 )
{
return V_42 | V_43 ;
}
static T_1 *
F_22 ( struct V_44 * V_6 , T_1 * V_45 )
{
T_1 * V_46 = F_23 ( V_6 ) , * V_47 = NULL ;
if ( V_46 ) {
if ( V_46 [ 0 ] >= 0x15 )
V_47 = F_24 ( V_6 , V_46 [ 2 ] ) ;
if ( V_46 [ 0 ] >= 0x30 )
V_47 = F_24 ( V_6 , V_46 [ 4 ] ) ;
}
if ( V_47 ) {
* V_45 = V_46 [ 0 ] ;
if ( * V_45 >= 0x30 )
* V_45 = V_47 [ 0 ] ;
}
return V_47 ;
}
int
F_25 ( struct V_44 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_48 * V_49 = & V_9 -> V_50 ;
struct V_3 * V_4 ;
T_1 * V_47 , * V_51 , V_52 [ 2 ] [ 4 ] = {} ;
T_1 V_45 , V_53 , V_54 ;
int V_18 , V_25 ;
F_26 ( & V_9 -> V_55 ) ;
V_47 = F_22 ( V_6 , & V_45 ) ;
if ( ! V_47 ) {
T_1 * V_56 = & V_49 -> V_1 [ V_49 -> V_57 ] ;
if ( V_49 -> type != V_58 )
return - V_59 ;
V_52 [ 0 ] [ 0 ] = V_60 ;
V_52 [ 0 ] [ 1 ] = V_61 ;
V_52 [ 1 ] [ 0 ] = V_62 ;
V_52 [ 1 ] [ 1 ] = V_63 ;
if ( V_56 [ 5 ] < 4 )
V_47 = & V_49 -> V_1 [ 0x48 ] ;
else
V_47 = & V_56 [ 0x36 ] ;
if ( V_47 [ 4 ] ) V_52 [ 0 ] [ 0 ] = V_47 [ 4 ] ;
if ( V_47 [ 5 ] ) V_52 [ 0 ] [ 1 ] = V_47 [ 5 ] ;
if ( V_47 [ 6 ] ) V_52 [ 1 ] [ 0 ] = V_47 [ 6 ] ;
if ( V_47 [ 7 ] ) V_52 [ 1 ] [ 1 ] = V_47 [ 7 ] ;
}
if ( V_47 && V_45 >= 0x30 ) {
V_51 = V_47 [ 1 ] + V_47 ;
V_53 = V_47 [ 2 ] ;
V_54 = V_47 [ 3 ] ;
} else
if ( V_47 ) {
V_51 = V_47 ;
V_53 = 16 ;
V_54 = 4 ;
} else {
V_51 = V_52 [ 0 ] ;
V_53 = 2 ;
V_54 = 4 ;
}
for ( V_25 = 0 ; V_25 < V_53 ; V_25 ++ , V_51 += V_54 ) {
V_4 = F_27 ( sizeof( * V_4 ) , V_64 ) ;
if ( V_4 == NULL ) {
F_28 ( V_6 ) ;
return - V_65 ;
}
V_4 -> type = V_51 [ 3 ] ;
if ( V_45 < 0x30 ) {
V_4 -> type &= 0x07 ;
if ( V_4 -> type == 0x07 )
V_4 -> type = 0xff ;
}
if ( V_4 -> type == 0xff ) {
F_29 ( V_4 ) ;
continue;
}
switch ( V_4 -> type ) {
case 0 :
V_4 -> V_7 = V_51 [ 0 ] ;
V_4 -> V_11 = V_51 [ 1 ] ;
V_4 -> V_66 . V_67 = & V_68 ;
break;
case 4 :
V_4 -> V_7 = 0x600800 + V_51 [ 1 ] ;
V_4 -> V_11 = V_4 -> V_7 ;
V_4 -> V_66 . V_67 = & V_68 ;
break;
case 5 :
V_4 -> V_7 = V_51 [ 0 ] & 0x0f ;
if ( V_9 -> V_12 < V_13 ) {
if ( V_4 -> V_7 >= F_30 ( V_69 ) )
break;
V_4 -> V_7 = V_69 [ V_4 -> V_7 ] ;
V_4 -> V_11 = V_4 -> V_7 ;
} else {
V_4 -> V_7 = 0x00d014 + ( V_4 -> V_7 * 0x20 ) ;
V_4 -> V_11 = V_4 -> V_7 ;
}
V_4 -> V_66 . V_67 = & V_68 ;
break;
case 6 :
V_4 -> V_7 = V_51 [ 0 ] ;
V_4 -> V_11 = V_4 -> V_7 ;
V_4 -> V_66 . V_67 = & V_70 ;
break;
default:
break;
}
if ( ! V_4 -> V_66 . V_67 ) {
F_31 ( V_6 , L_1 ,
V_25 , V_4 -> type , V_4 -> V_7 , V_4 -> V_11 ) ;
F_29 ( V_4 ) ;
continue;
}
snprintf ( V_4 -> V_66 . V_71 , sizeof( V_4 -> V_66 . V_71 ) ,
L_2 , F_32 ( V_6 -> V_72 ) , V_25 ) ;
V_4 -> V_66 . V_73 = V_74 ;
V_4 -> V_66 . V_6 . V_75 = & V_6 -> V_72 -> V_6 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_76 = V_25 ;
V_4 -> V_46 = F_33 ( V_51 [ 0 ] ) ;
F_34 ( & V_4 -> V_66 , V_47 ) ;
V_18 = F_35 ( & V_4 -> V_66 ) ;
if ( V_18 ) {
F_31 ( V_6 , L_3 , V_25 , V_18 ) ;
F_29 ( V_4 ) ;
continue;
}
F_36 ( & V_4 -> V_77 , & V_9 -> V_55 ) ;
}
return 0 ;
}
void
F_28 ( struct V_44 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_3 * V_4 , * V_78 ;
F_37 (port, tmp, &dev_priv->i2c_ports, head) {
F_38 ( & V_4 -> V_66 ) ;
F_29 ( V_4 ) ;
}
}
struct V_3 *
F_39 ( struct V_44 * V_6 , T_1 V_76 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_3 * V_4 ;
if ( V_76 == F_40 ( 0 ) ||
V_76 == F_40 ( 1 ) ) {
T_1 V_45 , * V_47 = F_22 ( V_6 , & V_45 ) ;
if ( V_47 && V_45 >= 0x30 ) {
if ( V_76 == F_40 ( 0 ) )
V_76 = ( V_47 [ 4 ] & 0x0f ) ;
else
V_76 = ( V_47 [ 4 ] & 0xf0 ) >> 4 ;
} else {
V_76 = 2 ;
}
}
F_41 (port, &dev_priv->i2c_ports, head) {
if ( V_4 -> V_76 == V_76 )
break;
}
if ( & V_4 -> V_77 == & V_9 -> V_55 )
return NULL ;
if ( V_9 -> V_12 >= V_79 && ( V_4 -> V_46 & 0x00000100 ) ) {
T_2 V_80 = 0x00e500 , V_5 ;
if ( V_4 -> type == 6 ) {
V_80 += V_4 -> V_7 * 0x50 ;
V_5 = 0x2002 ;
} else {
V_80 += ( ( V_4 -> V_46 & 0x1e00 ) >> 9 ) * 0x50 ;
V_5 = 0xe001 ;
}
F_4 ( V_6 , V_80 + 0x0c , 0x00000001 , 0x00000000 ) ;
F_4 ( V_6 , V_80 + 0x00 , 0x0000f003 , V_5 ) ;
}
return V_4 ;
}
bool
F_42 ( struct V_3 * V_47 , int V_30 )
{
T_3 V_41 [] = { 0 } ;
struct V_28 V_35 [] = {
{
. V_30 = V_30 ,
. V_31 = 0 ,
. V_39 = 1 ,
. V_41 = V_41 ,
} ,
{
. V_30 = V_30 ,
. V_31 = V_32 ,
. V_39 = 1 ,
. V_41 = V_41 ,
}
} ;
return F_43 ( & V_47 -> V_66 , V_35 , 2 ) == 2 ;
}
int
F_44 ( struct V_44 * V_6 , const char * V_81 ,
struct V_82 * V_83 ,
bool (* F_45)( struct V_3 * ,
struct V_82 * ) ,
int V_76 )
{
struct V_3 * V_47 = F_39 ( V_6 , V_76 ) ;
int V_25 ;
if ( ! V_47 ) {
F_46 ( V_6 , L_4 , V_81 , V_76 ) ;
return - V_59 ;
}
F_46 ( V_6 , L_5 , V_81 , V_47 -> V_76 ) ;
for ( V_25 = 0 ; V_83 [ V_25 ] . V_30 ; V_25 ++ ) {
if ( F_42 ( V_47 , V_83 [ V_25 ] . V_30 ) &&
( ! F_45 || F_45 ( V_47 , & V_83 [ V_25 ] ) ) ) {
F_47 ( V_6 , L_6 , V_81 , V_83 [ V_25 ] . type ) ;
return V_25 ;
}
}
F_46 ( V_6 , L_7 ) ;
return - V_59 ;
}
