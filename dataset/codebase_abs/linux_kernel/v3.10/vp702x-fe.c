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
static int F_7 ( struct V_22 * V_23 , T_2 * V_24 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
F_1 ( V_2 ) ;
F_8 ( L_1 , V_26 ) ;
if ( V_2 -> V_12 == 0 )
* V_24 = V_27 | V_28 | V_29 | V_30 | V_31 ;
else
* V_24 = 0 ;
if ( * V_24 & V_27 )
V_2 -> V_16 = 1000 ;
else
V_2 -> V_16 = 250 ;
return 0 ;
}
static int F_9 ( struct V_22 * V_23 , T_3 * V_32 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
F_1 ( V_2 ) ;
* V_32 = 0 ;
return 0 ;
}
static int F_10 ( struct V_22 * V_23 , T_3 * V_33 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
F_1 ( V_2 ) ;
* V_33 = 0 ;
return 0 ;
}
static int F_11 ( struct V_22 * V_23 , T_4 * V_34 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
F_1 ( V_2 ) ;
* V_34 = ( V_2 -> V_15 << 8 ) | V_2 -> V_15 ;
return 0 ;
}
static int F_12 ( struct V_22 * V_23 , T_4 * V_14 )
{
T_1 V_35 ;
struct V_1 * V_2 = V_23 -> V_25 ;
F_1 ( V_2 ) ;
V_35 = ( V_2 -> V_14 & 0x1f ) * 0xff / 0x1f ;
* V_14 = ( V_35 << 8 ) | V_35 ;
return 0 ;
}
static int F_13 ( struct V_22 * V_23 , struct V_36 * V_37 )
{
F_8 ( L_1 , V_26 ) ;
V_37 -> V_38 = 2000 ;
return 0 ;
}
static int F_14 ( struct V_22 * V_23 )
{
struct V_39 * V_40 = & V_23 -> V_41 ;
struct V_1 * V_2 = V_23 -> V_25 ;
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
T_3 V_42 = V_40 -> V_43 / 1000 ;
T_5 V_44 ;
T_1 * V_45 ;
F_3 ( & V_4 -> V_10 ) ;
V_45 = V_4 -> V_7 ;
memset ( V_45 , 0 , 10 ) ;
V_45 [ 0 ] = ( V_42 >> 8 ) & 0x7f ;
V_45 [ 1 ] = V_42 & 0xff ;
V_45 [ 2 ] = 1 ;
V_44 = ( T_5 ) ( V_40 -> V_46 / 1000 ) << 20 ;
F_15 ( V_44 , 88000 ) ;
V_45 [ 3 ] = ( V_44 >> 12 ) & 0xff ;
V_45 [ 4 ] = ( V_44 >> 4 ) & 0xff ;
V_45 [ 5 ] = ( V_44 << 4 ) & 0xf0 ;
F_8 ( L_2 ,
V_40 -> V_43 , V_42 , V_42 , V_40 -> V_46 ,
( unsigned long ) V_44 , ( unsigned long ) V_44 ) ;
if ( V_2 -> V_47 == V_48 )
V_45 [ 6 ] |= 0x40 ;
V_45 [ 7 ] = F_6 ( V_45 , 0 , 7 ) ;
V_2 -> V_16 = 250 ;
V_2 -> V_9 = V_8 ;
F_16 ( V_2 -> V_5 , V_45 , 8 , V_45 , 10 , 100 ) ;
if ( V_45 [ 2 ] == 0 && V_45 [ 3 ] == 0 )
F_8 ( L_3 ) ;
else
F_8 ( L_4 ) ;
F_5 ( & V_4 -> V_10 ) ;
return 0 ;
}
static int F_17 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
F_8 ( L_1 , V_26 ) ;
F_4 ( V_2 -> V_5 , V_49 , 0 , 0 , NULL , 0 ) ;
return 0 ;
}
static int F_18 ( struct V_22 * V_23 )
{
F_8 ( L_1 , V_26 ) ;
return 0 ;
}
static int F_19 ( struct V_22 * V_23 ,
struct V_50 * V_51 )
{
T_1 * V_45 ;
struct V_1 * V_2 = V_23 -> V_25 ;
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
F_8 ( L_1 , V_26 ) ;
if ( V_51 -> V_52 > 4 )
return - V_53 ;
F_3 ( & V_4 -> V_10 ) ;
V_45 = V_4 -> V_7 ;
V_45 [ 1 ] = V_54 ;
V_45 [ 2 ] = V_51 -> V_52 ;
memcpy ( & V_45 [ 3 ] , V_51 -> V_55 , V_51 -> V_52 ) ;
V_45 [ 7 ] = F_6 ( V_45 , 0 , 7 ) ;
F_16 ( V_2 -> V_5 , V_45 , 8 , V_45 , 10 , 100 ) ;
if ( V_45 [ 2 ] == 0 && V_45 [ 3 ] == 0 )
F_8 ( L_5 ) ;
else
F_8 ( L_6 ) ;
F_5 ( & V_4 -> V_10 ) ;
return 0 ;
}
static int F_20 ( struct V_22 * V_23 , T_6 V_56 )
{
F_8 ( L_1 , V_26 ) ;
return 0 ;
}
static int F_21 ( struct V_22 * V_23 , T_7 V_57 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
T_1 * V_7 ;
F_8 ( L_1 , V_26 ) ;
V_2 -> V_58 = V_57 ;
if ( V_57 == V_59 )
V_2 -> V_60 [ 2 ] = 0x02 ;
else
V_2 -> V_60 [ 2 ] = 0x00 ;
V_2 -> V_60 [ 7 ] = F_6 ( V_2 -> V_60 , 0 , 7 ) ;
F_3 ( & V_4 -> V_10 ) ;
V_7 = V_4 -> V_7 ;
memcpy ( V_7 , V_2 -> V_60 , 8 ) ;
F_16 ( V_2 -> V_5 , V_7 , 8 , V_7 , 10 , 100 ) ;
if ( V_7 [ 2 ] == 0 && V_7 [ 3 ] == 0 )
F_8 ( L_7 ) ;
else
F_8 ( L_8 ) ;
F_5 ( & V_4 -> V_10 ) ;
return 0 ;
}
static int F_22 ( struct V_22 * V_23 , T_8
V_47 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
T_1 * V_7 ;
F_8 ( L_1 , V_26 ) ;
V_2 -> V_47 = V_47 ;
if ( V_47 != V_61 )
V_2 -> V_60 [ 4 ] = 0x01 ;
else
V_2 -> V_60 [ 4 ] = 0x00 ;
V_2 -> V_60 [ 7 ] = F_6 ( V_2 -> V_60 , 0 , 7 ) ;
F_3 ( & V_4 -> V_10 ) ;
V_7 = V_4 -> V_7 ;
memcpy ( V_7 , V_2 -> V_60 , 8 ) ;
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
struct V_1 * V_2 = V_23 -> V_25 ;
F_24 ( V_2 ) ;
}
struct V_22 * F_25 ( struct V_62 * V_5 )
{
struct V_1 * V_20 = F_26 ( sizeof( struct V_1 ) , V_63 ) ;
if ( V_20 == NULL )
goto error;
V_20 -> V_5 = V_5 ;
memcpy ( & V_20 -> V_23 . V_64 , & V_65 , sizeof( struct V_66 ) ) ;
V_20 -> V_23 . V_25 = V_20 ;
V_20 -> V_60 [ 1 ] = V_67 ;
V_20 -> V_60 [ 3 ] = 0xff ;
return & V_20 -> V_23 ;
error:
return NULL ;
}
