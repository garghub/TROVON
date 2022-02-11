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
F_8 ( & V_1 -> V_15 -> V_15 , L_1 , V_2 ) ;
}
F_4 ( & V_1 -> V_5 , V_4 ) ;
}
static void F_9 ( struct V_19 * V_19 )
{
struct V_1 * V_1 = V_19 -> V_20 ;
int V_21 ;
switch ( V_19 -> V_21 ) {
case 0 :
break;
case - V_22 :
case - V_23 :
case - V_24 :
F_10 ( L_2 ,
V_25 , V_19 -> V_21 ) ;
return;
default:
F_10 ( L_3 , V_25 , V_19 -> V_21 ) ;
goto exit;
}
F_11 ( V_1 ,
( V_1 -> V_26 [ 0 ] << 8 ) | ( V_19 -> V_27 - 1 ) , V_1 -> V_26 + 1 ) ;
exit:
V_21 = F_7 ( V_19 , V_18 ) ;
if ( V_21 )
F_12 ( L_4 ,
V_25 , V_21 ) ;
}
static void F_13 ( struct V_19 * V_19 )
{
struct V_1 * V_1 = V_19 -> V_20 ;
if ( V_19 -> V_21 ) {
F_3 ( V_9 , V_1 -> V_10 ) ;
F_10 ( L_5 , V_19 -> V_21 ) ;
return;
}
F_1 ( V_1 ) ;
F_14 ( & V_1 -> V_28 ) ;
}
static void F_15 ( struct V_19 * V_19 )
{
struct V_1 * V_1 = V_19 -> V_20 ;
if ( V_19 -> V_21 ) return;
V_1 -> V_29 = 0xff00 | V_19 -> V_27 ;
F_14 ( & V_1 -> V_28 ) ;
}
static int F_16 ( struct V_30 * V_31 ,
const struct V_32 * V_33 )
{
struct V_34 * V_15 = F_17 ( V_31 ) ;
struct V_35 * V_36 ;
struct V_37 * V_38 , * V_39 ;
struct V_1 * V_1 ;
int F_12 = - V_40 ;
V_36 = V_31 -> V_41 ;
V_38 = & V_36 -> V_42 [ 0 ] . V_43 ;
V_39 = & V_36 -> V_42 [ 1 ] . V_43 ;
if ( ! ( V_1 = F_18 ( sizeof( struct V_1 ) + 32 , V_44 ) ) )
goto V_45;
if ( ! ( V_1 -> V_46 = F_19 ( 0 , V_44 ) ) )
goto V_45;
if ( ! ( V_1 -> V_11 = F_19 ( 0 , V_44 ) ) )
goto V_45;
if ( ! ( V_1 -> V_47 = F_19 ( 0 , V_44 ) ) )
goto V_45;
V_1 -> V_48 = V_49 ;
V_1 -> V_16 = V_15 ;
V_1 -> V_50 . V_51 = V_52 | V_53 | V_54 ;
V_1 -> V_50 . V_55 = 0 ;
V_1 -> V_50 . V_56 = F_20 ( 16 ) ;
F_21 ( V_1 -> V_46 , V_15 , F_22 ( V_15 , V_38 -> V_57 ) ,
V_1 -> V_26 , 16 , F_9 , V_1 , V_38 -> V_58 ) ;
F_21 ( V_1 -> V_11 , V_15 , F_23 ( V_15 , V_39 -> V_57 ) ,
V_1 + 1 , 32 , F_13 , V_1 , V_39 -> V_58 ) ;
F_24 ( V_1 -> V_47 , V_15 , F_25 ( V_15 , 0 ) ,
( void * ) & V_1 -> V_50 , V_1 -> V_59 , 16 , F_15 , V_1 ) ;
F_12 = F_26 ( V_1 ) ;
if ( F_12 )
goto V_45;
F_27 ( V_31 , V_1 ) ;
return 0 ;
V_45:
if ( V_1 ) {
F_28 ( V_1 -> V_46 ) ;
F_28 ( V_1 -> V_11 ) ;
F_28 ( V_1 -> V_47 ) ;
F_29 ( V_1 ) ;
}
return F_12 ;
}
static void F_30 ( struct V_30 * V_31 )
{
struct V_1 * V_1 = F_31 ( V_31 ) ;
F_27 ( V_31 , NULL ) ;
F_32 ( V_1 -> V_15 ) ;
F_28 ( V_1 -> V_46 ) ;
F_28 ( V_1 -> V_11 ) ;
F_28 ( V_1 -> V_47 ) ;
F_29 ( V_1 ) ;
}
