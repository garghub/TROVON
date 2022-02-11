static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
T_1 * V_7 ;
if ( F_2 ( V_8 , V_2 -> V_9 ) ) {
F_3 ( & V_4 -> V_10 ) ;
V_7 = V_4 -> V_7 ;
F_4 ( V_2 -> V_5 , V_11 , 0 , 0 , V_7 , 10 ) ;
V_2 -> V_12 = V_7 [ 4 ] ;
F_4 ( V_2 -> V_5 , V_13 , 0x11 , 0 , V_7 , 1 ) ;
V_2 -> V_14 = V_7 [ 0 ] ;
F_4 ( V_2 -> V_5 , V_13 , 0x15 , 0 , V_7 , 1 ) ;
V_2 -> V_15 = V_7 [ 0 ] ;
F_5 ( & V_4 -> V_10 ) ;
V_2 -> V_9 = V_8 + ( V_2 -> V_16 * V_17 ) / 1000 ;
}
return 0 ;
}
static T_1 F_6 ( T_1 * V_7 , int V_18 , int V_19 )
{
T_1 V_20 = 0 ;
int V_21 ;
for ( V_21 = V_18 ; V_21 < V_18 + V_19 ; V_21 ++ )
V_20 += V_7 [ V_21 ] ;
return ~ V_20 + 1 ;
}
static int F_7 ( struct V_22 * V_23 ,
enum V_24 * V_25 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
F_1 ( V_2 ) ;
F_8 ( L_1 , V_27 ) ;
if ( V_2 -> V_12 == 0 )
* V_25 = V_28 | V_29 | V_30 | V_31 | V_32 ;
else
* V_25 = 0 ;
if ( * V_25 & V_28 )
V_2 -> V_16 = 1000 ;
else
V_2 -> V_16 = 250 ;
return 0 ;
}
static int F_9 ( struct V_22 * V_23 , T_2 * V_33 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
F_1 ( V_2 ) ;
* V_33 = 0 ;
return 0 ;
}
static int F_10 ( struct V_22 * V_23 , T_2 * V_34 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
F_1 ( V_2 ) ;
* V_34 = 0 ;
return 0 ;
}
static int F_11 ( struct V_22 * V_23 , T_3 * V_35 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
F_1 ( V_2 ) ;
* V_35 = ( V_2 -> V_15 << 8 ) | V_2 -> V_15 ;
return 0 ;
}
static int F_12 ( struct V_22 * V_23 , T_3 * V_14 )
{
T_1 V_36 ;
struct V_1 * V_2 = V_23 -> V_26 ;
F_1 ( V_2 ) ;
V_36 = ( V_2 -> V_14 & 0x1f ) * 0xff / 0x1f ;
* V_14 = ( V_36 << 8 ) | V_36 ;
return 0 ;
}
static int F_13 ( struct V_22 * V_23 , struct V_37 * V_38 )
{
F_8 ( L_1 , V_27 ) ;
V_38 -> V_39 = 2000 ;
return 0 ;
}
static int F_14 ( struct V_22 * V_23 )
{
struct V_40 * V_41 = & V_23 -> V_42 ;
struct V_1 * V_2 = V_23 -> V_26 ;
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
T_2 V_43 = V_41 -> V_44 / 1000 ;
T_4 V_45 ;
T_1 * V_46 ;
F_3 ( & V_4 -> V_10 ) ;
V_46 = V_4 -> V_7 ;
memset ( V_46 , 0 , 10 ) ;
V_46 [ 0 ] = ( V_43 >> 8 ) & 0x7f ;
V_46 [ 1 ] = V_43 & 0xff ;
V_46 [ 2 ] = 1 ;
V_45 = ( T_4 ) ( V_41 -> V_47 / 1000 ) << 20 ;
F_15 ( V_45 , 88000 ) ;
V_46 [ 3 ] = ( V_45 >> 12 ) & 0xff ;
V_46 [ 4 ] = ( V_45 >> 4 ) & 0xff ;
V_46 [ 5 ] = ( V_45 << 4 ) & 0xf0 ;
F_8 ( L_2 ,
V_41 -> V_44 , V_43 , V_43 , V_41 -> V_47 ,
( unsigned long ) V_45 , ( unsigned long ) V_45 ) ;
if ( V_2 -> V_48 == V_49 )
V_46 [ 6 ] |= 0x40 ;
V_46 [ 7 ] = F_6 ( V_46 , 0 , 7 ) ;
V_2 -> V_16 = 250 ;
V_2 -> V_9 = V_8 ;
F_16 ( V_2 -> V_5 , V_46 , 8 , V_46 , 10 , 100 ) ;
if ( V_46 [ 2 ] == 0 && V_46 [ 3 ] == 0 )
F_8 ( L_3 ) ;
else
F_8 ( L_4 ) ;
F_5 ( & V_4 -> V_10 ) ;
return 0 ;
}
static int F_17 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
F_8 ( L_1 , V_27 ) ;
F_4 ( V_2 -> V_5 , V_50 , 0 , 0 , NULL , 0 ) ;
return 0 ;
}
static int F_18 ( struct V_22 * V_23 )
{
F_8 ( L_1 , V_27 ) ;
return 0 ;
}
static int F_19 ( struct V_22 * V_23 ,
struct V_51 * V_52 )
{
T_1 * V_46 ;
struct V_1 * V_2 = V_23 -> V_26 ;
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
F_8 ( L_1 , V_27 ) ;
if ( V_52 -> V_53 > 4 )
return - V_54 ;
F_3 ( & V_4 -> V_10 ) ;
V_46 = V_4 -> V_7 ;
V_46 [ 1 ] = V_55 ;
V_46 [ 2 ] = V_52 -> V_53 ;
memcpy ( & V_46 [ 3 ] , V_52 -> V_56 , V_52 -> V_53 ) ;
V_46 [ 7 ] = F_6 ( V_46 , 0 , 7 ) ;
F_16 ( V_2 -> V_5 , V_46 , 8 , V_46 , 10 , 100 ) ;
if ( V_46 [ 2 ] == 0 && V_46 [ 3 ] == 0 )
F_8 ( L_5 ) ;
else
F_8 ( L_6 ) ;
F_5 ( & V_4 -> V_10 ) ;
return 0 ;
}
static int F_20 ( struct V_22 * V_23 ,
enum V_57 V_58 )
{
F_8 ( L_1 , V_27 ) ;
return 0 ;
}
static int F_21 ( struct V_22 * V_23 ,
enum V_59 V_60 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
T_1 * V_7 ;
F_8 ( L_1 , V_27 ) ;
V_2 -> V_61 = V_60 ;
if ( V_60 == V_62 )
V_2 -> V_63 [ 2 ] = 0x02 ;
else
V_2 -> V_63 [ 2 ] = 0x00 ;
V_2 -> V_63 [ 7 ] = F_6 ( V_2 -> V_63 , 0 , 7 ) ;
F_3 ( & V_4 -> V_10 ) ;
V_7 = V_4 -> V_7 ;
memcpy ( V_7 , V_2 -> V_63 , 8 ) ;
F_16 ( V_2 -> V_5 , V_7 , 8 , V_7 , 10 , 100 ) ;
if ( V_7 [ 2 ] == 0 && V_7 [ 3 ] == 0 )
F_8 ( L_7 ) ;
else
F_8 ( L_8 ) ;
F_5 ( & V_4 -> V_10 ) ;
return 0 ;
}
static int F_22 ( struct V_22 * V_23 ,
enum V_64 V_48 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
T_1 * V_7 ;
F_8 ( L_1 , V_27 ) ;
V_2 -> V_48 = V_48 ;
if ( V_48 != V_65 )
V_2 -> V_63 [ 4 ] = 0x01 ;
else
V_2 -> V_63 [ 4 ] = 0x00 ;
V_2 -> V_63 [ 7 ] = F_6 ( V_2 -> V_63 , 0 , 7 ) ;
F_3 ( & V_4 -> V_10 ) ;
V_7 = V_4 -> V_7 ;
memcpy ( V_7 , V_2 -> V_63 , 8 ) ;
F_16 ( V_2 -> V_5 , V_7 , 8 , V_7 , 10 , 100 ) ;
if ( V_7 [ 2 ] == 0 && V_7 [ 3 ] == 0 )
F_8 ( L_9 ) ;
else
F_8 ( L_10 ) ;
F_5 ( & V_4 -> V_10 ) ;
return 0 ;
}
static void F_23 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
F_24 ( V_2 ) ;
}
struct V_22 * F_25 ( struct V_66 * V_5 )
{
struct V_1 * V_20 = F_26 ( sizeof( struct V_1 ) , V_67 ) ;
if ( V_20 == NULL )
goto error;
V_20 -> V_5 = V_5 ;
memcpy ( & V_20 -> V_23 . V_68 , & V_69 , sizeof( struct V_70 ) ) ;
V_20 -> V_23 . V_26 = V_20 ;
V_20 -> V_63 [ 1 ] = V_71 ;
V_20 -> V_63 [ 3 ] = 0xff ;
return & V_20 -> V_23 ;
error:
return NULL ;
}
