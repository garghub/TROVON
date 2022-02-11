static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 V_5 ,
const char * type , T_2 V_6 )
{
struct V_7 V_8 ;
struct V_9 * V_10 = & V_2 -> V_11 ;
unsigned short V_12 [ 2 ] = { V_6 , V_13 } ;
memset ( & V_8 , 0 , sizeof( struct V_7 ) ) ;
F_2 ( V_8 . type , type , V_14 ) ;
switch ( V_5 ) {
case V_15 :
V_10 -> V_16 = V_17 ;
V_10 -> V_18 = V_19 ;
V_10 -> type = V_20 ;
V_10 -> V_21 = V_2 -> V_22 ;
V_8 . V_23 = V_10 ;
break;
}
return F_3 ( V_4 , & V_8 , V_12 , NULL ) == NULL ?
- 1 : 0 ;
}
int F_4 ( struct V_1 * V_2 , unsigned V_24 )
{
struct V_25 * V_26 ;
int V_27 = V_28 [ V_24 ] ;
struct V_3 * V_4 = & V_2 -> V_29 [ V_27 ] ;
const char * type = V_30 [ V_24 ] ;
T_1 V_5 = 1 << V_24 ;
if ( V_24 >= F_5 ( V_31 ) )
return - 1 ;
if ( V_5 == V_32 ) {
V_26 = F_6 ( & V_2 -> V_33 ,
V_4 , type , 0 , V_2 -> V_34 -> V_35 ) ;
if ( V_26 != NULL )
V_26 -> V_36 = V_5 ;
V_26 = F_6 ( & V_2 -> V_33 ,
V_4 , type , 0 , V_2 -> V_34 -> V_37 ) ;
if ( V_26 != NULL )
V_26 -> V_36 = V_5 ;
V_26 = F_6 ( & V_2 -> V_33 ,
V_4 , type , 0 , V_2 -> V_34 -> V_38 ) ;
if ( V_26 != NULL )
V_26 -> V_36 = V_5 ;
return V_26 != NULL ? 0 : - 1 ;
}
if ( V_5 & V_39 )
return F_1 ( V_2 , V_4 , V_5 , type , V_31 [ V_24 ] ) ;
if ( ! V_31 [ V_24 ] )
return - 1 ;
V_26 = F_6 ( & V_2 -> V_33 , V_4 , type , V_31 [ V_24 ] ,
NULL ) ;
if ( V_26 != NULL )
V_26 -> V_36 = V_5 ;
return V_26 != NULL ? 0 : - 1 ;
}
struct V_25 * F_7 ( struct V_1 * V_2 , T_1 V_5 )
{
struct V_25 * V_40 = NULL ;
struct V_25 * V_26 ;
F_8 ( & V_2 -> V_33 . V_41 ) ;
F_9 (sd, &cx->v4l2_dev) {
if ( V_26 -> V_36 == V_5 ) {
V_40 = V_26 ;
break;
}
}
F_10 ( & V_2 -> V_33 . V_41 ) ;
return V_40 ;
}
static void F_11 ( void * V_42 , int V_43 )
{
struct V_1 * V_2 = ( (struct V_44 * ) V_42 ) -> V_2 ;
int V_45 = ( (struct V_44 * ) V_42 ) -> V_45 ;
T_1 V_6 = V_45 ? V_46 : V_47 ;
T_1 V_48 = F_12 ( V_2 , V_6 ) ;
if ( V_43 )
F_13 ( V_2 , V_48 | V_49 , V_6 ) ;
else
F_13 ( V_2 , V_48 & ~ V_49 , V_6 ) ;
}
static void F_14 ( void * V_42 , int V_43 )
{
struct V_1 * V_2 = ( (struct V_44 * ) V_42 ) -> V_2 ;
int V_45 = ( (struct V_44 * ) V_42 ) -> V_45 ;
T_1 V_6 = V_45 ? V_46 : V_47 ;
T_1 V_48 = F_12 ( V_2 , V_6 ) ;
if ( V_43 )
F_13 ( V_2 , V_48 | V_50 , V_6 ) ;
else
F_13 ( V_2 , V_48 & ~ V_50 , V_6 ) ;
}
static int F_15 ( void * V_42 )
{
struct V_1 * V_2 = ( (struct V_44 * ) V_42 ) -> V_2 ;
int V_45 = ( (struct V_44 * ) V_42 ) -> V_45 ;
T_1 V_6 = V_45 ? V_51 : V_52 ;
return F_12 ( V_2 , V_6 ) & V_53 ;
}
static int F_16 ( void * V_42 )
{
struct V_1 * V_2 = ( (struct V_44 * ) V_42 ) -> V_2 ;
int V_45 = ( (struct V_44 * ) V_42 ) -> V_45 ;
T_1 V_6 = V_45 ? V_51 : V_52 ;
return F_12 ( V_2 , V_6 ) & V_54 ;
}
int F_17 ( struct V_1 * V_2 )
{
int V_55 , V_56 ;
F_18 ( L_1 ) ;
for ( V_55 = 0 ; V_55 < 2 ; V_55 ++ ) {
memcpy ( & V_2 -> V_57 [ V_55 ] , & V_58 ,
sizeof( struct V_59 ) ) ;
V_2 -> V_60 [ V_55 ] . V_2 = V_2 ;
V_2 -> V_60 [ V_55 ] . V_45 = V_55 ;
V_2 -> V_57 [ V_55 ] . V_42 = & V_2 -> V_60 [ V_55 ] ;
memcpy ( & V_2 -> V_29 [ V_55 ] , & V_61 ,
sizeof( struct V_3 ) ) ;
V_2 -> V_29 [ V_55 ] . V_62 = & V_2 -> V_57 [ V_55 ] ;
sprintf ( V_2 -> V_29 [ V_55 ] . V_21 + strlen ( V_2 -> V_29 [ V_55 ] . V_21 ) ,
L_2 , V_2 -> V_63 , V_55 ) ;
F_19 ( & V_2 -> V_29 [ V_55 ] , & V_2 -> V_33 ) ;
V_2 -> V_29 [ V_55 ] . V_64 . V_65 = & V_2 -> V_66 -> V_64 ;
}
if ( F_12 ( V_2 , V_46 ) != 0x0003c02f ) {
F_20 ( V_2 , 0x10000000 , 0xc71004 ,
0x00000000 , 0x10001000 ) ;
F_20 ( V_2 , 0x10001000 , 0xc71024 ,
0x00001000 , 0x10001000 ) ;
}
F_20 ( V_2 , 0x00c00000 , 0xc7001c , 0x00000000 , 0x00c000c0 ) ;
F_21 ( 10 ) ;
F_20 ( V_2 , 0x00c000c0 , 0xc7001c , 0x000000c0 , 0x00c000c0 ) ;
F_21 ( 10 ) ;
F_20 ( V_2 , 0x00c00000 , 0xc7001c , 0x00000000 , 0x00c000c0 ) ;
F_21 ( 10 ) ;
F_13 ( V_2 , 0x00c00000 , 0xc730c8 ) ;
F_20 ( V_2 , V_67 | V_68 , V_69 ,
~ ( V_67 | V_68 ) , V_67 | V_68 ) ;
F_13 ( V_2 , 0x00021c0f & ~ 4 , V_47 ) ;
F_11 ( & V_2 -> V_60 [ 0 ] , 1 ) ;
F_14 ( & V_2 -> V_60 [ 0 ] , 1 ) ;
F_13 ( V_2 , 0x00021c0f & ~ 4 , V_46 ) ;
F_11 ( & V_2 -> V_60 [ 1 ] , 1 ) ;
F_14 ( & V_2 -> V_60 [ 1 ] , 1 ) ;
F_22 ( V_2 , V_70 ,
V_71 , V_72 , ( T_1 ) V_73 ) ;
V_56 = F_23 ( & V_2 -> V_29 [ 0 ] ) ;
if ( V_56 )
goto V_56;
V_56 = F_23 ( & V_2 -> V_29 [ 1 ] ) ;
if ( V_56 )
goto V_74;
return 0 ;
V_74:
F_24 ( & V_2 -> V_29 [ 0 ] ) ;
V_56:
return V_56 ;
}
void F_25 ( struct V_1 * V_2 )
{
int V_55 ;
F_18 ( L_3 ) ;
F_13 ( V_2 , F_12 ( V_2 , V_47 ) | 4 ,
V_47 ) ;
F_13 ( V_2 , F_12 ( V_2 , V_46 ) | 4 ,
V_46 ) ;
for ( V_55 = 0 ; V_55 < 2 ; V_55 ++ ) {
F_24 ( & V_2 -> V_29 [ V_55 ] ) ;
}
}
