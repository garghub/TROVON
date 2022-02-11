T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_2 V_5 ,
enum V_6 type ,
T_3 V_7 )
{
enum V_8 T_4 V_9 ( ( V_10 ) ) ;
struct V_11 * V_12 ;
bool V_13 = false ;
struct V_14 V_15 ;
T_1 V_16 ;
T_3 V_17 ;
if ( NULL == V_4 -> V_18 . V_12 ) {
V_16 = V_19 ;
F_2 ( V_2 , L_1 ) ;
goto exit;
}
if ( V_5 >= V_4 -> V_18 . V_20 ) {
V_16 = V_21 ;
F_2 ( V_2 , L_2 ) ;
goto exit;
}
V_12 = & V_4 -> V_18 . V_12 [ V_5 ] ;
if ( ! V_12 -> V_22 ) {
if ( V_23 == type ) {
T_4 = V_24 ;
V_17 = V_25 ;
} else {
T_4 = V_26 ;
V_17 = V_7 ;
}
V_16 = F_3 ( V_2 , & V_15 , T_4 , V_17 ,
V_27 ) ;
if ( V_16 )
goto exit;
V_13 = true ;
if ( V_23 == type ) {
V_16 = F_4 ( V_2 ,
& V_12 -> V_28 . V_29 . V_30 ,
sizeof( struct V_31 ) * 512 ) ;
if ( V_16 )
goto exit;
V_12 -> V_28 . V_29 . V_32 =
(struct V_31 * )
V_12 -> V_28 . V_29 . V_30 . V_33 ;
V_12 -> V_28 . V_29 . V_34 = V_15 ;
} else {
V_12 -> V_28 . V_35 . V_36 = V_15 ;
V_12 -> V_28 . V_35 . V_37 = V_5 ;
}
V_4 -> V_18 . V_12 [ V_5 ] . V_38 = type ;
F_5 ( & V_4 -> V_18 ) ;
}
if ( V_39 == V_12 -> V_38 )
F_6 ( & V_12 -> V_28 . V_35 ) ;
exit:
if ( V_16 )
if ( V_13 )
F_7 ( V_2 , & V_15 ) ;
return V_16 ;
}
T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_2 V_40 ,
struct V_14 * V_41 )
{
T_1 V_16 = 0 ;
struct V_42 * V_29 ;
struct V_31 * V_32 ;
struct V_14 V_15 ;
struct V_14 * V_43 = & V_15 ;
T_2 V_44 , V_45 ;
T_3 * V_46 ;
T_3 V_47 ;
if ( V_40 / V_48 >= V_4 -> V_18 . V_20 ) {
V_16 = V_49 ;
F_2 ( V_2 , L_3 ) ;
goto exit;
}
V_44 = ( V_40 / V_48 ) ;
if ( V_23 !=
V_4 -> V_18 . V_12 [ V_44 ] . V_38 )
goto exit;
V_45 = ( V_40 % V_48 ) ;
V_29 = & V_4 -> V_18 . V_12 [ V_44 ] . V_28 . V_29 ;
V_32 = & V_29 -> V_32 [ V_45 ] ;
if ( ! V_32 -> V_22 ) {
if ( V_41 ) {
V_32 -> V_41 = true ;
V_43 = V_41 ;
} else {
V_16 = F_3 ( V_2 , V_43 , V_50 ,
V_25 ,
V_27 ) ;
if ( V_16 )
goto exit;
V_32 -> V_41 = false ;
}
V_32 -> V_35 . V_36 = * V_43 ;
V_32 -> V_35 . V_37 = V_40 ;
V_32 -> V_35 . V_38 = V_23 ;
V_47 = V_43 -> V_51 | 0x1 ;
V_46 = ( T_3 * ) V_29 -> V_34 . V_33 ;
V_46 += V_45 ;
memcpy ( V_46 , & V_47 , sizeof( T_3 ) ) ;
V_32 -> V_5 = V_44 ;
V_32 -> V_22 = true ;
F_9 ( V_29 ) ;
}
F_6 ( & V_32 -> V_35 ) ;
exit:
return V_16 ;
}
T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_2 V_52 )
{
T_1 V_16 = 0 ;
struct V_31 * V_32 ;
struct V_42 * V_29 ;
struct V_11 * V_12 ;
T_2 V_44 , V_45 ;
T_3 * V_46 ;
V_44 = V_52 / V_48 ;
V_45 = V_52 % V_48 ;
if ( V_44 >= V_4 -> V_18 . V_20 ) {
V_16 = V_49 ;
F_2 ( V_2 , L_4 ) ;
goto exit;
}
V_12 = & V_4 -> V_18 . V_12 [ V_44 ] ;
if ( V_23 != V_12 -> V_38 ) {
V_16 = V_53 ;
F_2 ( V_2 , L_5 ) ;
goto exit;
}
V_29 = & V_4 -> V_18 . V_12 [ V_44 ] . V_28 . V_29 ;
V_32 = & V_29 -> V_32 [ V_45 ] ;
F_11 ( & V_32 -> V_35 ) ;
if ( V_32 -> V_35 . V_54 )
goto exit;
V_32 -> V_22 = false ;
F_12 ( V_29 ) ;
V_46 = ( T_3 * ) V_29 -> V_34 . V_33 ;
V_46 += V_45 ;
memset ( V_46 , 0 , sizeof( T_3 ) ) ;
F_13 ( V_2 , V_44 , V_52 ) ;
if ( ! V_32 -> V_41 )
V_16 = F_7 ( V_2 , & V_32 -> V_35 . V_36 ) ;
if ( V_16 )
goto exit;
if ( ! V_29 -> V_54 )
F_14 ( V_2 , & V_29 -> V_30 ) ;
exit:
return V_16 ;
}
T_1 F_15 ( struct V_3 * V_4 ,
T_2 V_52 )
{
T_1 V_16 = 0 ;
struct V_11 * V_12 ;
V_12 = & V_4 -> V_18 . V_12 [ V_52 ] ;
F_11 ( & V_12 -> V_28 . V_35 ) ;
if ( V_12 -> V_28 . V_35 . V_54 ) {
V_16 = V_55 ;
goto exit;
}
F_16 ( & V_4 -> V_18 ) ;
V_12 -> V_22 = false ;
exit:
return V_16 ;
}
T_1 F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_2 V_52 , bool V_56 )
{
struct V_11 * V_12 ;
if ( ! V_56 )
return V_57 ;
V_12 = & V_4 -> V_18 . V_12 [ V_52 ] ;
F_18 ( V_2 , V_52 , V_39 ) ;
return F_7 ( V_2 , & V_12 -> V_28 . V_35 . V_36 ) ;
}
T_1 F_19 ( struct V_3 * V_4 ,
T_2 V_52 )
{
T_1 V_16 = 0 ;
struct V_11 * V_12 ;
V_12 = & V_4 -> V_18 . V_12 [ V_52 ] ;
if ( V_12 -> V_28 . V_29 . V_54 ) {
V_16 = V_55 ;
goto exit;
}
V_12 -> V_22 = false ;
F_16 ( & V_4 -> V_18 ) ;
exit:
return V_16 ;
}
T_1 F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_2 V_52 , bool V_56 )
{
struct V_11 * V_12 ;
if ( ! V_56 )
return V_57 ;
V_12 = & V_4 -> V_18 . V_12 [ V_52 ] ;
F_18 ( V_2 , V_52 , V_23 ) ;
return F_7 ( V_2 , & V_12 -> V_28 . V_29 . V_34 ) ;
}
