void F_1 ( struct V_1 * V_1 )
{
int V_2 , V_3 ;
unsigned long V_4 ;
F_2 ( & V_1 -> V_5 , V_4 ) ;
if ( V_1 -> V_6 . V_7 == V_1 -> V_6 . V_8 ) {
F_3 ( V_9 , V_1 -> V_10 ) ;
F_4 ( & V_1 -> V_5 , V_4 ) ;
return;
}
( ( char * ) V_1 -> V_11 -> V_12 ) [ 0 ] = V_1 -> V_6 . V_13 [ V_1 -> V_6 . V_8 ] ;
F_5 ( V_1 -> V_6 . V_8 , 1 ) ;
V_2 = V_1 -> V_6 . V_13 [ V_1 -> V_6 . V_8 ] ;
F_5 ( V_1 -> V_6 . V_8 , 1 ) ;
V_1 -> V_11 -> V_14 = V_2 + 1 ;
V_1 -> V_11 -> V_15 = V_1 -> V_16 ;
V_3 = F_6 ( V_1 -> V_6 . V_7 , V_1 -> V_6 . V_8 , V_17 ) ;
if ( V_2 < V_3 ) V_3 = V_2 ;
memcpy ( V_1 -> V_11 -> V_12 + 1 ,
& V_1 -> V_6 . V_13 [ V_1 -> V_6 . V_8 ] ,
V_3 ) ;
if ( V_2 != V_3 ) {
memcpy ( V_1 -> V_11 -> V_12 + 1 + V_3 ,
& V_1 -> V_6 . V_13 [ 0 ] ,
V_2 - V_3 ) ;
}
F_5 ( V_1 -> V_6 . V_8 , V_2 ) ;
if ( ( V_2 = F_7 ( V_1 -> V_11 , V_18 ) ) ) {
F_3 ( V_9 , V_1 -> V_10 ) ;
F_8 ( & V_1 -> V_19 -> V_15 , L_1 , V_2 ) ;
}
F_4 ( & V_1 -> V_5 , V_4 ) ;
}
static void F_9 ( struct V_20 * V_20 )
{
struct V_1 * V_1 = V_20 -> V_21 ;
struct V_22 * V_15 = & V_1 -> V_19 -> V_15 ;
int V_23 ;
switch ( V_20 -> V_23 ) {
case 0 :
break;
case - V_24 :
case - V_25 :
case - V_26 :
F_10 ( V_15 , L_2 ,
V_27 , V_20 -> V_23 ) ;
return;
default:
F_10 ( V_15 , L_3 ,
V_27 , V_20 -> V_23 ) ;
goto exit;
}
F_11 ( V_1 ,
( V_1 -> V_28 [ 0 ] << 8 ) | ( V_20 -> V_29 - 1 ) , V_1 -> V_28 + 1 ) ;
exit:
V_23 = F_7 ( V_20 , V_18 ) ;
if ( V_23 )
F_12 ( V_15 , L_4 ,
V_27 , V_23 ) ;
}
static void F_13 ( struct V_20 * V_20 )
{
struct V_1 * V_1 = V_20 -> V_21 ;
if ( V_20 -> V_23 ) {
F_3 ( V_9 , V_1 -> V_10 ) ;
F_10 ( & V_1 -> V_19 -> V_15 , L_5 ,
V_20 -> V_23 ) ;
return;
}
F_1 ( V_1 ) ;
F_14 ( & V_1 -> V_30 ) ;
}
static void F_15 ( struct V_20 * V_20 )
{
struct V_1 * V_1 = V_20 -> V_21 ;
if ( V_20 -> V_23 ) return;
V_1 -> V_31 = 0xff00 | V_20 -> V_29 ;
F_14 ( & V_1 -> V_30 ) ;
}
static int F_16 ( struct V_32 * V_19 ,
const struct V_33 * V_34 )
{
struct V_35 * V_15 = F_17 ( V_19 ) ;
struct V_36 * V_37 ;
struct V_38 * V_39 , * V_40 ;
struct V_1 * V_1 ;
int V_41 = - V_42 ;
V_37 = V_19 -> V_43 ;
V_39 = & V_37 -> V_44 [ 0 ] . V_45 ;
V_40 = & V_37 -> V_44 [ 1 ] . V_45 ;
if ( ! ( V_1 = F_18 ( sizeof( struct V_1 ) + 32 , V_46 ) ) )
goto V_47;
if ( ! ( V_1 -> V_48 = F_19 ( 0 , V_46 ) ) )
goto V_47;
if ( ! ( V_1 -> V_11 = F_19 ( 0 , V_46 ) ) )
goto V_47;
if ( ! ( V_1 -> V_49 = F_19 ( 0 , V_46 ) ) )
goto V_47;
V_1 -> V_50 = V_51 ;
V_1 -> V_16 = V_15 ;
V_1 -> V_19 = V_19 ;
V_1 -> V_52 . V_53 = V_54 | V_55 | V_56 ;
V_1 -> V_52 . V_57 = 0 ;
V_1 -> V_52 . V_58 = F_20 ( 16 ) ;
F_21 ( V_1 -> V_48 , V_15 , F_22 ( V_15 , V_39 -> V_59 ) ,
V_1 -> V_28 , 16 , F_9 , V_1 , V_39 -> V_60 ) ;
F_21 ( V_1 -> V_11 , V_15 , F_23 ( V_15 , V_40 -> V_59 ) ,
V_1 + 1 , 32 , F_13 , V_1 , V_40 -> V_60 ) ;
F_24 ( V_1 -> V_49 , V_15 , F_25 ( V_15 , 0 ) ,
( void * ) & V_1 -> V_52 , V_1 -> V_61 , 16 , F_15 , V_1 ) ;
V_41 = F_26 ( V_1 ) ;
if ( V_41 )
goto V_47;
F_27 ( V_19 , V_1 ) ;
return 0 ;
V_47:
if ( V_1 ) {
F_28 ( V_1 -> V_48 ) ;
F_28 ( V_1 -> V_11 ) ;
F_28 ( V_1 -> V_49 ) ;
F_29 ( V_1 ) ;
}
return V_41 ;
}
static void F_30 ( struct V_32 * V_19 )
{
struct V_1 * V_1 = F_31 ( V_19 ) ;
F_27 ( V_19 , NULL ) ;
F_32 ( V_1 -> V_15 ) ;
F_28 ( V_1 -> V_48 ) ;
F_28 ( V_1 -> V_11 ) ;
F_28 ( V_1 -> V_49 ) ;
F_29 ( V_1 ) ;
}
