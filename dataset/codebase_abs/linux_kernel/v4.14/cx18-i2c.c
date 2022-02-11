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
V_10 -> type = V_20 | V_21 |
V_22 ;
V_10 -> V_23 = V_2 -> V_24 ;
V_8 . V_25 = V_10 ;
break;
}
return F_3 ( V_4 , & V_8 , V_12 , NULL ) == NULL ?
- 1 : 0 ;
}
int F_4 ( struct V_1 * V_2 , unsigned V_26 )
{
struct V_27 * V_28 ;
int V_29 = V_30 [ V_26 ] ;
struct V_3 * V_4 = & V_2 -> V_31 [ V_29 ] ;
const char * type = V_32 [ V_26 ] ;
T_1 V_5 = 1 << V_26 ;
if ( V_5 == V_33 ) {
V_28 = F_5 ( & V_2 -> V_34 ,
V_4 , type , 0 , V_2 -> V_35 -> V_36 ) ;
if ( V_28 != NULL )
V_28 -> V_37 = V_5 ;
V_28 = F_5 ( & V_2 -> V_34 ,
V_4 , type , 0 , V_2 -> V_35 -> V_38 ) ;
if ( V_28 != NULL )
V_28 -> V_37 = V_5 ;
V_28 = F_5 ( & V_2 -> V_34 ,
V_4 , type , 0 , V_2 -> V_35 -> V_39 ) ;
if ( V_28 != NULL )
V_28 -> V_37 = V_5 ;
return V_28 != NULL ? 0 : - 1 ;
}
if ( V_5 & V_40 )
return F_1 ( V_2 , V_4 , V_5 , type , V_41 [ V_26 ] ) ;
if ( ! V_41 [ V_26 ] )
return - 1 ;
V_28 = F_5 ( & V_2 -> V_34 , V_4 , type , V_41 [ V_26 ] ,
NULL ) ;
if ( V_28 != NULL )
V_28 -> V_37 = V_5 ;
return V_28 != NULL ? 0 : - 1 ;
}
struct V_27 * F_6 ( struct V_1 * V_2 , T_1 V_5 )
{
struct V_27 * V_42 = NULL ;
struct V_27 * V_28 ;
F_7 ( & V_2 -> V_34 . V_43 ) ;
F_8 (sd, &cx->v4l2_dev) {
if ( V_28 -> V_37 == V_5 ) {
V_42 = V_28 ;
break;
}
}
F_9 ( & V_2 -> V_34 . V_43 ) ;
return V_42 ;
}
static void F_10 ( void * V_44 , int V_45 )
{
struct V_1 * V_2 = ( (struct V_46 * ) V_44 ) -> V_2 ;
int V_47 = ( (struct V_46 * ) V_44 ) -> V_47 ;
T_1 V_6 = V_47 ? V_48 : V_49 ;
T_1 V_50 = F_11 ( V_2 , V_6 ) ;
if ( V_45 )
F_12 ( V_2 , V_50 | V_51 , V_6 ) ;
else
F_12 ( V_2 , V_50 & ~ V_51 , V_6 ) ;
}
static void F_13 ( void * V_44 , int V_45 )
{
struct V_1 * V_2 = ( (struct V_46 * ) V_44 ) -> V_2 ;
int V_47 = ( (struct V_46 * ) V_44 ) -> V_47 ;
T_1 V_6 = V_47 ? V_48 : V_49 ;
T_1 V_50 = F_11 ( V_2 , V_6 ) ;
if ( V_45 )
F_12 ( V_2 , V_50 | V_52 , V_6 ) ;
else
F_12 ( V_2 , V_50 & ~ V_52 , V_6 ) ;
}
static int F_14 ( void * V_44 )
{
struct V_1 * V_2 = ( (struct V_46 * ) V_44 ) -> V_2 ;
int V_47 = ( (struct V_46 * ) V_44 ) -> V_47 ;
T_1 V_6 = V_47 ? V_53 : V_54 ;
return F_11 ( V_2 , V_6 ) & V_55 ;
}
static int F_15 ( void * V_44 )
{
struct V_1 * V_2 = ( (struct V_46 * ) V_44 ) -> V_2 ;
int V_47 = ( (struct V_46 * ) V_44 ) -> V_47 ;
T_1 V_6 = V_47 ? V_53 : V_54 ;
return F_11 ( V_2 , V_6 ) & V_56 ;
}
int F_16 ( struct V_1 * V_2 )
{
int V_57 , V_58 ;
F_17 ( L_1 ) ;
for ( V_57 = 0 ; V_57 < 2 ; V_57 ++ ) {
V_2 -> V_59 [ V_57 ] = V_60 ;
V_2 -> V_61 [ V_57 ] . V_2 = V_2 ;
V_2 -> V_61 [ V_57 ] . V_47 = V_57 ;
V_2 -> V_59 [ V_57 ] . V_44 = & V_2 -> V_61 [ V_57 ] ;
V_2 -> V_31 [ V_57 ] = V_62 ;
V_2 -> V_31 [ V_57 ] . V_63 = & V_2 -> V_59 [ V_57 ] ;
sprintf ( V_2 -> V_31 [ V_57 ] . V_23 + strlen ( V_2 -> V_31 [ V_57 ] . V_23 ) ,
L_2 , V_2 -> V_64 , V_57 ) ;
F_18 ( & V_2 -> V_31 [ V_57 ] , & V_2 -> V_34 ) ;
V_2 -> V_31 [ V_57 ] . V_65 . V_66 = & V_2 -> V_67 -> V_65 ;
}
if ( F_11 ( V_2 , V_48 ) != 0x0003c02f ) {
F_19 ( V_2 , 0x10000000 , 0xc71004 ,
0x00000000 , 0x10001000 ) ;
F_19 ( V_2 , 0x10001000 , 0xc71024 ,
0x00001000 , 0x10001000 ) ;
}
F_19 ( V_2 , 0x00c00000 , 0xc7001c , 0x00000000 , 0x00c000c0 ) ;
F_20 ( 10 ) ;
F_19 ( V_2 , 0x00c000c0 , 0xc7001c , 0x000000c0 , 0x00c000c0 ) ;
F_20 ( 10 ) ;
F_19 ( V_2 , 0x00c00000 , 0xc7001c , 0x00000000 , 0x00c000c0 ) ;
F_20 ( 10 ) ;
F_12 ( V_2 , 0x00c00000 , 0xc730c8 ) ;
F_19 ( V_2 , V_68 | V_69 , V_70 ,
~ ( V_68 | V_69 ) , V_68 | V_69 ) ;
F_12 ( V_2 , 0x00021c0f & ~ 4 , V_49 ) ;
F_10 ( & V_2 -> V_61 [ 0 ] , 1 ) ;
F_13 ( & V_2 -> V_61 [ 0 ] , 1 ) ;
F_12 ( V_2 , 0x00021c0f & ~ 4 , V_48 ) ;
F_10 ( & V_2 -> V_61 [ 1 ] , 1 ) ;
F_13 ( & V_2 -> V_61 [ 1 ] , 1 ) ;
F_21 ( V_2 , V_71 ,
V_72 , V_73 , ( T_1 ) V_74 ) ;
V_58 = F_22 ( & V_2 -> V_31 [ 0 ] ) ;
if ( V_58 )
goto V_58;
V_58 = F_22 ( & V_2 -> V_31 [ 1 ] ) ;
if ( V_58 )
goto V_75;
return 0 ;
V_75:
F_23 ( & V_2 -> V_31 [ 0 ] ) ;
V_58:
return V_58 ;
}
void F_24 ( struct V_1 * V_2 )
{
int V_57 ;
F_17 ( L_3 ) ;
F_12 ( V_2 , F_11 ( V_2 , V_49 ) | 4 ,
V_49 ) ;
F_12 ( V_2 , F_11 ( V_2 , V_48 ) | 4 ,
V_48 ) ;
for ( V_57 = 0 ; V_57 < 2 ; V_57 ++ ) {
F_23 ( & V_2 -> V_31 [ V_57 ] ) ;
}
}
