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
T_2 V_40 )
{
T_1 V_16 = 0 ;
struct V_41 * V_29 ;
struct V_31 * V_32 ;
struct V_14 V_15 ;
T_2 V_42 , V_43 ;
T_3 * V_44 ;
T_3 V_45 ;
if ( V_40 / V_46 >= V_4 -> V_18 . V_20 ) {
V_16 = V_47 ;
F_2 ( V_2 , L_3 ) ;
goto exit;
}
V_42 = ( V_40 / V_46 ) ;
if ( V_23 !=
V_4 -> V_18 . V_12 [ V_42 ] . V_38 )
goto exit;
V_43 = ( V_40 % V_46 ) ;
V_29 = & V_4 -> V_18 . V_12 [ V_42 ] . V_28 . V_29 ;
V_32 = & V_29 -> V_32 [ V_43 ] ;
if ( ! V_32 -> V_22 ) {
V_16 = F_3 ( V_2 , & V_15 , V_48 ,
V_25 ,
V_27 ) ;
if ( V_16 )
goto exit;
V_32 -> V_35 . V_36 = V_15 ;
V_32 -> V_35 . V_37 = V_40 ;
V_32 -> V_35 . V_38 = V_23 ;
V_45 = V_15 . V_49 | 0x1 ;
V_44 = ( T_3 * ) V_29 -> V_34 . V_33 ;
V_44 += V_43 ;
memcpy ( V_44 , & V_45 , sizeof( T_3 ) ) ;
V_32 -> V_5 = V_42 ;
V_32 -> V_22 = true ;
F_9 ( V_29 ) ;
}
F_6 ( & V_32 -> V_35 ) ;
exit:
return V_16 ;
}
T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_2 V_50 , bool V_51 )
{
T_1 V_16 = 0 ;
struct V_31 * V_32 ;
struct V_41 * V_29 ;
struct V_11 * V_12 ;
T_2 V_42 , V_43 ;
T_3 * V_44 ;
V_42 = V_50 / V_46 ;
V_43 = V_50 % V_46 ;
if ( V_42 >= V_4 -> V_18 . V_20 ) {
V_16 = V_47 ;
F_2 ( V_2 , L_4 ) ;
goto exit;
}
V_12 = & V_4 -> V_18 . V_12 [ V_42 ] ;
if ( V_23 != V_12 -> V_38 ) {
V_16 = V_52 ;
F_2 ( V_2 , L_5 ) ;
goto exit;
}
V_29 = & V_4 -> V_18 . V_12 [ V_42 ] . V_28 . V_29 ;
V_32 = & V_29 -> V_32 [ V_43 ] ;
F_11 ( & V_32 -> V_35 ) ;
if ( V_32 -> V_35 . V_53 )
goto exit;
V_32 -> V_22 = false ;
F_12 ( V_29 ) ;
V_44 = ( T_3 * ) V_29 -> V_34 . V_33 ;
V_44 += V_43 ;
memset ( V_44 , 0 , sizeof( T_3 ) ) ;
if ( V_51 )
F_13 ( V_2 , V_42 , V_50 ) ;
else
F_14 ( V_2 , V_42 , V_50 , V_4 -> V_54 ) ;
V_16 = F_7 ( V_2 , & ( V_32 -> V_35 . V_36 ) ) ;
if ( V_16 )
goto exit;
if ( ! V_29 -> V_53 )
F_15 ( V_2 , & V_29 -> V_30 ) ;
exit:
return V_16 ;
}
T_1 F_16 ( struct V_3 * V_4 ,
T_2 V_50 )
{
T_1 V_16 = 0 ;
struct V_11 * V_12 ;
V_12 = & V_4 -> V_18 . V_12 [ V_50 ] ;
F_11 ( & V_12 -> V_28 . V_35 ) ;
if ( V_12 -> V_28 . V_35 . V_53 ) {
V_16 = V_55 ;
goto exit;
}
F_17 ( & V_4 -> V_18 ) ;
V_12 -> V_22 = false ;
exit:
return V_16 ;
}
T_1 F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_2 V_50 , bool V_51 )
{
struct V_11 * V_12 ;
T_1 V_16 = 0 ;
V_12 = & V_4 -> V_18 . V_12 [ V_50 ] ;
if ( V_51 ) {
F_19 ( V_2 , V_50 , V_39 ) ;
} else {
V_16 = V_56 ;
goto exit;
}
V_16 = F_7 ( V_2 , & ( V_12 -> V_28 . V_35 . V_36 ) ) ;
if ( V_16 )
goto exit;
exit:
return V_16 ;
}
T_1 F_20 ( struct V_3 * V_4 ,
T_2 V_50 )
{
T_1 V_16 = 0 ;
struct V_11 * V_12 ;
V_12 = & V_4 -> V_18 . V_12 [ V_50 ] ;
if ( V_12 -> V_28 . V_29 . V_53 ) {
V_16 = V_55 ;
goto exit;
}
V_12 -> V_22 = false ;
F_17 ( & V_4 -> V_18 ) ;
exit:
return V_16 ;
}
T_1 F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_2 V_50 , bool V_51 )
{
T_1 V_16 = 0 ;
struct V_11 * V_12 ;
V_12 = & V_4 -> V_18 . V_12 [ V_50 ] ;
if ( V_51 ) {
F_19 ( V_2 , V_50 , V_23 ) ;
} else {
V_16 = V_56 ;
goto exit;
}
V_16 = F_7 ( V_2 , & ( V_12 -> V_28 . V_29 . V_34 ) ) ;
if ( V_16 )
goto exit;
exit:
return V_16 ;
}
