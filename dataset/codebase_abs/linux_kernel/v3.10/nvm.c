static inline void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
V_2 -> V_3 = F_2 ( V_3 ) ;
V_2 -> V_4 = F_2 ( V_4 ) ;
V_2 -> type = F_2 ( V_5 ) ;
}
static int F_3 ( struct V_6 * V_7 , T_1 V_5 ,
T_1 V_3 , T_1 V_4 , T_2 * V_8 )
{
struct V_1 V_9 = {} ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_14 V_2 = {
. V_15 = V_16 ,
. V_17 = V_18 | V_19 ,
. V_8 = { & V_9 , } ,
} ;
int V_20 , V_21 , V_22 ;
T_2 * V_23 ;
F_1 ( & V_9 , V_3 , V_4 , V_5 ) ;
V_2 . V_24 [ 0 ] = sizeof( struct V_1 ) ;
V_20 = F_4 ( V_7 , & V_2 ) ;
if ( V_20 )
return V_20 ;
V_13 = V_2 . V_25 ;
if ( V_13 -> V_26 . V_17 & V_27 ) {
F_5 ( V_7 , L_1 ,
V_13 -> V_26 . V_17 ) ;
V_20 = - V_28 ;
goto exit;
}
V_11 = ( void * ) V_13 -> V_8 ;
V_20 = F_6 ( V_11 -> V_29 ) ;
V_21 = F_6 ( V_11 -> V_4 ) ;
V_22 = F_6 ( V_11 -> V_3 ) ;
V_23 = V_11 -> V_8 ;
if ( V_20 ) {
F_5 ( V_7 ,
L_2 ,
V_20 , V_7 -> V_30 -> V_31 ) ;
V_20 = - V_32 ;
goto exit;
}
if ( V_22 != V_3 ) {
F_5 ( V_7 , L_3 ,
V_22 ) ;
V_20 = - V_32 ;
goto exit;
}
memcpy ( V_8 + V_3 , V_23 , V_21 ) ;
V_20 = V_21 ;
exit:
F_7 ( & V_2 ) ;
return V_20 ;
}
static int F_8 ( struct V_6 * V_7 , T_1 V_5 ,
T_2 * V_8 )
{
T_1 V_4 , V_3 = 0 ;
int V_20 ;
V_4 = V_33 ;
V_20 = V_4 ;
while ( V_20 == V_4 ) {
V_20 = F_3 ( V_7 , V_5 , V_3 , V_4 , V_8 ) ;
if ( V_20 < 0 ) {
F_5 ( V_7 ,
L_4 ,
V_5 , V_3 , V_4 ) ;
return V_20 ;
}
V_3 += V_20 ;
}
F_9 ( V_7 , L_5 , V_5 ) ;
return V_3 ;
}
static struct V_34 *
F_10 ( struct V_6 * V_7 )
{
struct V_35 * V_36 = V_7 -> V_37 ;
const T_3 * V_38 , * V_39 , * V_40 ;
if ( ! V_7 -> V_37 [ V_41 ] . V_8 ||
! V_7 -> V_37 [ V_42 ] . V_8 ) {
F_5 ( V_7 , L_6 ) ;
return NULL ;
}
if ( F_11 ( ! V_7 -> V_30 ) )
return NULL ;
V_38 = ( const T_3 * ) V_36 [ V_42 ] . V_8 ;
V_39 = ( const T_3 * ) V_36 [ V_41 ] . V_8 ;
V_40 = ( const T_3 * ) V_36 [ V_43 ] . V_8 ;
return F_12 ( V_7 -> V_44 -> V_45 , V_7 -> V_30 , V_38 , V_39 , V_40 ) ;
}
int F_13 ( struct V_6 * V_7 )
{
int V_20 , V_46 , V_5 ;
T_2 * V_47 , * V_48 ;
V_47 = F_14 ( V_7 -> V_30 -> V_49 -> V_50 ,
V_51 ) ;
if ( ! V_47 )
return - V_52 ;
for ( V_46 = 0 ; V_46 < F_15 ( V_53 ) ; V_46 ++ ) {
V_5 = V_53 [ V_46 ] ;
V_20 = F_8 ( V_7 , V_5 , V_47 ) ;
if ( V_20 < 0 )
break;
V_48 = F_16 ( V_47 , V_20 , V_51 ) ;
if ( ! V_48 ) {
V_20 = - V_52 ;
break;
}
V_7 -> V_37 [ V_5 ] . V_8 = V_48 ;
V_7 -> V_37 [ V_5 ] . V_4 = V_20 ;
}
F_17 ( V_47 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = 0 ;
V_7 -> V_54 = F_10 ( V_7 ) ;
return V_20 ;
}
