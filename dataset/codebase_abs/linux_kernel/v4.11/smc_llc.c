static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_5 V_6 )
{
}
static int F_2 ( struct V_3 * V_4 ,
struct V_7 * * V_8 ,
struct V_1 * * V_2 )
{
int V_9 ;
V_9 = F_3 ( V_4 , F_1 , V_8 , V_2 ) ;
if ( V_9 < 0 )
return V_9 ;
F_4 (
sizeof( union V_10 ) > V_11 ,
L_1 ) ;
F_4 (
sizeof( union V_10 ) != V_12 ,
L_2 ) ;
F_4 (
sizeof( struct V_13 ) > V_14 ,
L_3 ) ;
return 0 ;
}
int F_5 ( struct V_3 * V_4 , T_1 V_15 [] ,
union V_16 * V_17 ,
enum V_18 V_19 )
{
struct V_20 * V_21 = F_6 ( V_4 , struct V_20 ,
V_22 [ V_23 ] ) ;
struct V_24 * V_25 ;
struct V_1 * V_2 ;
struct V_7 * V_8 ;
int V_9 ;
V_9 = F_2 ( V_4 , & V_8 , & V_2 ) ;
if ( V_9 )
return V_9 ;
V_25 = (struct V_24 * ) V_8 ;
memset ( V_25 , 0 , sizeof( * V_25 ) ) ;
V_25 -> V_26 . V_27 . type = V_28 ;
V_25 -> V_26 . V_29 = sizeof( struct V_24 ) ;
if ( V_19 == V_30 )
V_25 -> V_26 . V_31 |= V_32 ;
memcpy ( V_25 -> V_33 , V_15 , V_34 ) ;
memcpy ( V_25 -> V_35 , V_17 , V_36 ) ;
F_7 ( V_25 -> V_37 , V_4 -> V_38 -> V_39 ) ;
memcpy ( V_25 -> V_40 , V_21 -> V_41 , V_42 ) ;
V_25 -> V_43 = V_44 ;
V_9 = F_8 ( V_4 , V_2 ) ;
return V_9 ;
}
static void F_9 ( struct V_3 * V_4 ,
struct V_24 * V_45 )
{
struct V_20 * V_21 ;
V_21 = F_6 ( V_4 , struct V_20 , V_22 [ V_23 ] ) ;
if ( V_45 -> V_26 . V_31 & V_32 ) {
if ( V_21 -> V_46 == V_47 )
F_10 ( & V_4 -> V_48 ) ;
} else {
if ( V_21 -> V_46 == V_49 ) {
V_4 -> V_50 = V_45 -> V_51 ;
F_10 ( & V_4 -> V_52 ) ;
}
}
}
static void F_11 ( struct V_53 * V_54 , void * V_55 )
{
struct V_3 * V_4 = (struct V_3 * ) V_54 -> V_56 -> V_57 ;
union V_10 * V_45 = V_55 ;
if ( V_54 -> V_58 < sizeof( * V_45 ) )
return;
if ( V_45 -> V_59 . V_60 . V_29 != sizeof( * V_45 ) )
return;
if ( V_45 -> V_59 . V_60 . V_27 . type == V_28 )
F_9 ( V_4 , & V_45 -> V_61 ) ;
}
int T_2 F_12 ( void )
{
struct V_62 * V_63 ;
int V_9 = 0 ;
for ( V_63 = V_64 ; V_63 -> V_63 ; V_63 ++ ) {
F_13 ( & V_63 -> V_65 ) ;
V_9 = F_14 ( V_63 ) ;
if ( V_9 )
break;
}
return V_9 ;
}
