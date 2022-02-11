static inline void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
V_2 -> V_3 = F_2 ( V_3 ) ;
V_2 -> V_4 = F_2 ( V_4 ) ;
V_2 -> V_5 = 1 ;
}
static inline void F_3 ( struct V_6 * V_2 ,
T_1 V_3 , T_1 V_4 , T_1 V_7 )
{
V_2 -> V_3 = F_2 ( V_3 ) ;
V_2 -> V_4 = F_2 ( V_4 ) ;
V_2 -> type = F_2 ( V_7 ) ;
}
static int F_4 ( struct V_8 * V_9 , T_1 V_7 ,
T_1 V_3 , T_1 V_4 , T_2 * V_10 )
{
union V_11 V_12 ;
union V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_17 V_2 = {
. V_18 = V_19 ,
. V_20 = V_21 | V_22 ,
. V_10 = { & V_12 , } ,
} ;
int V_23 , V_24 , V_25 ;
T_2 * V_26 ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
if ( V_9 -> V_27 -> V_28 == V_29 ) {
F_3 ( & ( V_12 . V_30 ) ,
V_3 , V_4 , V_7 ) ;
V_2 . V_31 [ 0 ] = sizeof( struct V_6 ) ;
} else {
F_1 ( & ( V_12 . V_32 ) ,
V_3 , V_4 ) ;
V_2 . V_31 [ 0 ] = sizeof( struct V_1 ) ;
}
V_23 = F_5 ( V_9 , & V_2 ) ;
if ( V_23 )
return V_23 ;
V_16 = V_2 . V_33 ;
if ( V_16 -> V_34 . V_20 & V_35 ) {
F_6 ( V_9 , L_1 ,
V_16 -> V_34 . V_20 ) ;
V_23 = - V_36 ;
goto exit;
}
V_14 = ( void * ) V_16 -> V_10 ;
if ( V_9 -> V_27 -> V_28 == V_29 ) {
V_23 = F_7 ( V_14 -> V_30 . V_37 ) ;
V_24 = F_7 ( V_14 -> V_30 . V_4 ) ;
V_25 = F_7 ( V_14 -> V_30 . V_3 ) ;
V_26 = V_14 -> V_30 . V_10 ;
} else {
V_23 = F_7 ( V_14 -> V_32 . V_4 ) <= 0 ;
V_24 = F_7 ( V_14 -> V_32 . V_4 ) ;
V_25 = F_7 ( V_14 -> V_32 . V_3 ) ;
V_26 = V_14 -> V_32 . V_10 ;
}
if ( V_23 ) {
F_6 ( V_9 ,
L_2 ,
V_23 , V_9 -> V_27 -> V_38 ) ;
V_23 = - V_39 ;
goto exit;
}
if ( V_25 != V_3 ) {
F_6 ( V_9 , L_3 ,
V_25 ) ;
V_23 = - V_39 ;
goto exit;
}
memcpy ( V_10 + V_3 , V_26 , V_24 ) ;
V_23 = V_24 ;
exit:
F_8 ( & V_2 ) ;
return V_23 ;
}
static int F_9 ( struct V_8 * V_9 , T_1 V_7 ,
T_2 * V_10 )
{
T_1 V_4 , V_3 = 0 ;
int V_23 ;
bool V_40 = V_9 -> V_27 -> V_28 != V_29 ;
V_4 = ( V_41 . V_42 ? ( 8 * 1024 ) : ( 4 * 1024 ) )
- sizeof( union V_11 )
- sizeof( struct V_15 ) ;
if ( V_40 && V_4 > V_9 -> V_27 -> V_43 -> V_44 )
V_4 = V_9 -> V_27 -> V_43 -> V_44 ;
V_23 = V_4 ;
while ( V_23 == V_4 ) {
V_23 = F_4 ( V_9 , V_7 , V_3 , V_4 , V_10 ) ;
if ( V_23 < 0 ) {
F_6 ( V_9 ,
L_4 ,
V_7 , V_3 , V_4 ) ;
return V_23 ;
}
V_3 += V_23 ;
if ( V_40 && V_3 == V_9 -> V_27 -> V_43 -> V_44 )
break;
}
F_10 ( V_9 , L_5 , V_7 ) ;
return V_3 ;
}
static struct V_45 *
F_11 ( struct V_8 * V_9 )
{
struct V_46 * V_47 = V_9 -> V_48 ;
const T_3 * V_49 , * V_50 , * V_51 ;
if ( ! V_9 -> V_48 [ V_52 ] . V_10 ||
! V_9 -> V_48 [ V_53 ] . V_10 ) {
F_6 ( V_9 , L_6 ) ;
return NULL ;
}
if ( F_12 ( ! V_9 -> V_27 ) )
return NULL ;
V_49 = ( const T_3 * ) V_47 [ V_53 ] . V_10 ;
V_50 = ( const T_3 * ) V_47 [ V_52 ] . V_10 ;
V_51 = ( const T_3 * ) V_47 [ V_54 ] . V_10 ;
return F_13 ( V_9 -> V_55 -> V_56 , V_9 -> V_27 , V_49 , V_50 , V_51 ) ;
}
int F_14 ( struct V_8 * V_9 )
{
int V_23 , V_57 , V_7 ;
T_2 * V_58 , * V_59 ;
if ( V_9 -> V_27 -> V_28 == V_29 ) {
V_58 = F_15 ( V_9 -> V_27 -> V_43 -> V_44 ,
V_60 ) ;
if ( ! V_58 )
return - V_61 ;
for ( V_57 = 0 ; V_57 < F_16 ( V_62 ) ; V_57 ++ ) {
V_7 = V_62 [ V_57 ] ;
V_23 = F_9 ( V_9 , V_7 , V_58 ) ;
if ( V_23 < 0 )
break;
V_59 = F_17 ( V_58 , V_23 , V_60 ) ;
if ( ! V_59 ) {
V_23 = - V_61 ;
break;
}
V_9 -> V_48 [ V_7 ] . V_10 = V_59 ;
V_9 -> V_48 [ V_7 ] . V_4 = V_23 ;
}
F_18 ( V_58 ) ;
if ( V_23 < 0 )
return V_23 ;
} else {
V_9 -> V_63 = V_9 -> V_27 -> V_43 -> V_44 ;
F_19 ( V_9 -> V_55 -> V_56 , L_7 ,
V_9 -> V_63 ) ;
V_9 -> V_64 = F_20 ( V_9 -> V_63 , V_60 ) ;
if ( ! V_9 -> V_64 )
return - V_61 ;
V_23 = F_9 ( V_9 , 0 , V_9 -> V_64 ) ;
if ( V_23 != V_9 -> V_63 ) {
F_6 ( V_9 , L_8 ,
V_23 , V_9 -> V_63 ) ;
F_18 ( V_9 -> V_64 ) ;
V_9 -> V_64 = NULL ;
return - V_39 ;
}
}
V_23 = 0 ;
if ( V_9 -> V_27 -> V_28 == V_29 )
V_9 -> V_65 = F_11 ( V_9 ) ;
else
V_9 -> V_65 =
F_21 ( V_9 -> V_55 -> V_56 ,
V_9 -> V_27 ,
V_9 -> V_64 ,
V_9 -> V_63 ) ;
if ( ! V_9 -> V_65 ) {
F_18 ( V_9 -> V_64 ) ;
V_9 -> V_64 = NULL ;
V_23 = - V_61 ;
}
return V_23 ;
}
