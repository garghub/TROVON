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
T_1 V_16 = V_17 ;
T_3 V_18 ;
if ( NULL == V_4 -> V_19 . V_12 ) {
V_16 = V_20 ;
F_2 ( V_2 , L_1 ) ;
goto exit;
}
if ( V_5 >= V_4 -> V_19 . V_21 ) {
V_16 = V_22 ;
F_2 ( V_2 , L_2 ) ;
goto exit;
}
V_12 = & V_4 -> V_19 . V_12 [ V_5 ] ;
if ( ! V_12 -> V_23 ) {
if ( V_24 == type ) {
T_4 = V_25 ;
V_18 = V_26 ;
} else {
T_4 = V_27 ;
V_18 = V_7 ;
}
V_16 = F_3 ( V_2 , & V_15 , T_4 , V_18 ,
V_28 ) ;
if ( V_16 )
goto exit;
V_13 = true ;
if ( V_24 == type ) {
V_16 = F_4 ( V_2 ,
& V_12 -> V_29 . V_30 . V_31 ,
sizeof( struct V_32 ) * 512 ) ;
if ( V_16 )
goto exit;
V_12 -> V_29 . V_30 . V_33 =
(struct V_32 * )
V_12 -> V_29 . V_30 . V_31 . V_34 ;
V_12 -> V_29 . V_30 . V_35 = V_15 ;
} else {
V_12 -> V_29 . V_36 . V_37 = V_15 ;
V_12 -> V_29 . V_36 . V_38 = V_5 ;
}
V_4 -> V_19 . V_12 [ V_5 ] . V_39 = type ;
F_5 ( & V_4 -> V_19 ) ;
}
if ( V_40 == V_12 -> V_39 )
F_6 ( & V_12 -> V_29 . V_36 ) ;
exit:
if ( V_16 )
if ( V_13 )
F_7 ( V_2 , & V_15 ) ;
return V_16 ;
}
T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_2 V_41 ,
struct V_14 * V_42 )
{
T_1 V_16 = 0 ;
struct V_43 * V_30 ;
struct V_32 * V_33 ;
struct V_14 V_15 ;
struct V_14 * V_44 = & V_15 ;
T_2 V_45 , V_46 ;
T_3 * V_47 ;
T_3 V_48 ;
if ( V_41 / V_49 >= V_4 -> V_19 . V_21 ) {
V_16 = V_50 ;
F_2 ( V_2 , L_3 ) ;
goto exit;
}
V_45 = ( V_41 / V_49 ) ;
if ( V_24 !=
V_4 -> V_19 . V_12 [ V_45 ] . V_39 )
goto exit;
V_46 = ( V_41 % V_49 ) ;
V_30 = & V_4 -> V_19 . V_12 [ V_45 ] . V_29 . V_30 ;
V_33 = & V_30 -> V_33 [ V_46 ] ;
if ( ! V_33 -> V_23 ) {
if ( V_42 ) {
V_33 -> V_42 = true ;
V_44 = V_42 ;
} else {
V_16 = F_3 ( V_2 , V_44 , V_51 ,
V_26 ,
V_28 ) ;
if ( V_16 )
goto exit;
V_33 -> V_42 = false ;
}
V_33 -> V_36 . V_37 = * V_44 ;
V_33 -> V_36 . V_38 = V_41 ;
V_33 -> V_36 . V_39 = V_24 ;
V_48 = V_44 -> V_52 | 0x1 ;
V_47 = ( T_3 * ) V_30 -> V_35 . V_34 ;
V_47 += V_46 ;
memcpy ( V_47 , & V_48 , sizeof( T_3 ) ) ;
V_33 -> V_5 = V_45 ;
V_33 -> V_23 = true ;
F_9 ( V_30 ) ;
}
F_6 ( & V_33 -> V_36 ) ;
exit:
return V_16 ;
}
T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_2 V_53 )
{
T_1 V_16 = 0 ;
struct V_32 * V_33 ;
struct V_43 * V_30 ;
struct V_11 * V_12 ;
T_2 V_45 , V_46 ;
T_3 * V_47 ;
V_45 = V_53 / V_49 ;
V_46 = V_53 % V_49 ;
if ( V_45 >= V_4 -> V_19 . V_21 ) {
V_16 = V_50 ;
F_2 ( V_2 , L_4 ) ;
goto exit;
}
V_12 = & V_4 -> V_19 . V_12 [ V_45 ] ;
if ( V_24 != V_12 -> V_39 ) {
V_16 = V_54 ;
F_2 ( V_2 , L_5 ) ;
goto exit;
}
V_30 = & V_4 -> V_19 . V_12 [ V_45 ] . V_29 . V_30 ;
V_33 = & V_30 -> V_33 [ V_46 ] ;
F_11 ( & V_33 -> V_36 ) ;
if ( V_33 -> V_36 . V_55 )
goto exit;
V_33 -> V_23 = false ;
F_12 ( V_30 ) ;
V_47 = ( T_3 * ) V_30 -> V_35 . V_34 ;
V_47 += V_46 ;
memset ( V_47 , 0 , sizeof( T_3 ) ) ;
F_13 ( V_2 , V_45 , V_53 ) ;
if ( ! V_33 -> V_42 )
V_16 = F_7 ( V_2 , & V_33 -> V_36 . V_37 ) ;
if ( V_16 )
goto exit;
if ( ! V_30 -> V_55 )
F_14 ( V_2 , & V_30 -> V_31 ) ;
exit:
return V_16 ;
}
T_1 F_15 ( struct V_3 * V_4 ,
T_2 V_53 )
{
T_1 V_16 = 0 ;
struct V_11 * V_12 ;
V_12 = & V_4 -> V_19 . V_12 [ V_53 ] ;
F_11 ( & V_12 -> V_29 . V_36 ) ;
if ( V_12 -> V_29 . V_36 . V_55 ) {
V_16 = V_56 ;
goto exit;
}
F_16 ( & V_4 -> V_19 ) ;
V_12 -> V_23 = false ;
exit:
return V_16 ;
}
T_1 F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_2 V_53 , bool V_57 )
{
struct V_11 * V_12 ;
if ( ! V_57 )
return V_58 ;
V_12 = & V_4 -> V_19 . V_12 [ V_53 ] ;
F_18 ( V_2 , V_53 , V_40 ) ;
return F_7 ( V_2 , & V_12 -> V_29 . V_36 . V_37 ) ;
}
T_1 F_19 ( struct V_3 * V_4 ,
T_2 V_53 )
{
T_1 V_16 = 0 ;
struct V_11 * V_12 ;
V_12 = & V_4 -> V_19 . V_12 [ V_53 ] ;
if ( V_12 -> V_29 . V_30 . V_55 ) {
V_16 = V_56 ;
goto exit;
}
V_12 -> V_23 = false ;
F_16 ( & V_4 -> V_19 ) ;
exit:
return V_16 ;
}
T_1 F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_2 V_53 , bool V_57 )
{
struct V_11 * V_12 ;
if ( ! V_57 )
return V_58 ;
V_12 = & V_4 -> V_19 . V_12 [ V_53 ] ;
F_18 ( V_2 , V_53 , V_24 ) ;
return F_7 ( V_2 , & V_12 -> V_29 . V_30 . V_35 ) ;
}
