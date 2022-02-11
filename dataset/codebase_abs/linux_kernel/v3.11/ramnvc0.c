void
F_1 ( struct V_1 * V_2 , struct V_3 * * V_4 )
{
struct V_5 * V_6 = V_5 ( V_2 ) ;
struct V_3 * V_7 = * V_4 ;
* V_4 = NULL ;
if ( F_2 ( V_7 == NULL ) )
return;
F_3 ( & V_2 -> V_8 . V_9 ) ;
if ( V_7 -> V_10 )
V_6 -> V_11 ( V_6 , & V_7 -> V_10 ) ;
F_4 ( V_2 , V_7 ) ;
F_5 ( & V_2 -> V_8 . V_9 ) ;
F_6 ( V_7 ) ;
}
int
F_7 ( struct V_1 * V_2 , T_1 V_12 , T_2 V_13 , T_2 V_14 ,
T_2 V_15 , struct V_3 * * V_4 )
{
struct V_16 * V_17 = & V_2 -> V_18 ;
struct V_19 * V_20 ;
struct V_3 * V_7 ;
int type = ( V_15 & 0x0ff ) ;
int V_21 = ( V_15 & 0x800 ) ;
const bool V_22 = V_23 [ type ] != type ;
int V_24 ;
V_12 >>= 12 ;
V_13 >>= 12 ;
V_14 >>= 12 ;
if ( ! V_14 )
V_14 = V_12 ;
V_7 = F_8 ( sizeof( * V_7 ) , V_25 ) ;
if ( ! V_7 )
return - V_26 ;
F_9 ( & V_7 -> V_27 ) ;
V_7 -> V_12 = V_12 ;
F_3 ( & V_2 -> V_8 . V_9 ) ;
if ( V_22 ) {
struct V_5 * V_6 = V_5 ( V_2 ) ;
if ( V_13 == ( 1 << ( 17 - 12 ) ) ) {
int V_28 = V_12 >> 5 ;
V_6 -> V_29 ( V_6 , V_28 , & V_7 -> V_10 ) ;
}
if ( F_2 ( ! V_7 -> V_10 ) )
type = V_23 [ type ] ;
}
V_7 -> V_15 = type ;
do {
if ( V_21 )
V_24 = F_10 ( V_17 , 1 , V_12 , V_14 , V_13 , & V_20 ) ;
else
V_24 = F_11 ( V_17 , 1 , V_12 , V_14 , V_13 , & V_20 ) ;
if ( V_24 ) {
F_5 ( & V_2 -> V_8 . V_9 ) ;
V_2 -> V_30 -> V_31 ( V_2 , & V_7 ) ;
return V_24 ;
}
F_12 ( & V_20 -> V_32 , & V_7 -> V_27 ) ;
V_12 -= V_20 -> V_33 ;
} while ( V_12 );
F_5 ( & V_2 -> V_8 . V_9 ) ;
V_20 = F_13 ( & V_7 -> V_27 , struct V_19 , V_32 ) ;
V_7 -> V_34 = ( T_1 ) V_20 -> V_34 << 12 ;
* V_4 = V_7 ;
return 0 ;
}
static int
F_14 ( struct V_35 * V_36 , struct V_35 * V_37 ,
struct V_38 * V_39 , void * V_40 , T_2 V_12 ,
struct V_35 * * V_41 )
{
struct V_1 * V_2 = V_1 ( V_36 ) ;
struct V_42 * V_43 = V_42 ( V_2 ) ;
struct V_44 * V_30 ;
const T_2 V_45 = ( 256 * 1024 ) >> 12 ;
const T_2 V_46 = ( 1024 * 1024 ) >> 12 ;
T_2 V_47 = F_15 ( V_2 , 0x022438 ) ;
T_2 V_48 = F_15 ( V_2 , 0x022554 ) ;
T_2 V_49 = F_15 ( V_2 , 0x10f20c ) ;
T_2 V_34 , V_33 ;
bool V_50 = true ;
int V_24 , V_51 ;
V_24 = F_16 ( V_36 , V_37 , V_39 , & V_30 ) ;
* V_41 = F_17 ( V_30 ) ;
if ( V_24 )
return V_24 ;
F_18 ( V_2 , L_1 , F_15 ( V_2 , 0x100800 ) ) ;
F_18 ( V_2 , L_2 , V_47 , V_48 ) ;
V_30 -> type = F_19 ( V_43 ) ;
V_30 -> V_52 = ( F_15 ( V_2 , 0x10f200 ) & 0x00000004 ) ? 2 : 1 ;
for ( V_51 = 0 ; V_51 < V_47 ; V_51 ++ ) {
if ( ! ( V_48 & ( 1 << V_51 ) ) ) {
T_2 V_53 = F_15 ( V_2 , 0x11020c + ( V_51 * 0x1000 ) ) ;
if ( V_53 != V_49 ) {
if ( V_53 < V_49 )
V_49 = V_53 ;
V_50 = false ;
}
F_18 ( V_2 , L_3 , V_51 , V_53 ) ;
V_30 -> V_12 += ( T_1 ) V_53 << 20 ;
}
}
if ( V_50 ) {
V_34 = V_45 ;
V_33 = ( V_30 -> V_12 >> 12 ) - V_45 - V_46 ;
V_24 = F_20 ( & V_2 -> V_18 , V_34 , V_33 , 1 ) ;
} else {
V_24 = F_20 ( & V_2 -> V_18 , V_45 ,
( V_49 << 8 ) * V_47 , 1 ) ;
if ( V_24 )
return V_24 ;
V_34 = ( 0x0200000000ULL >> 12 ) + ( V_49 << 8 ) ;
V_33 = ( V_30 -> V_12 >> 12 ) - ( V_49 << 8 ) - V_46 ;
V_24 = F_20 ( & V_2 -> V_18 , V_34 , V_33 , 0 ) ;
if ( V_24 )
F_21 ( & V_2 -> V_18 ) ;
}
if ( V_24 )
return V_24 ;
V_30 -> V_54 = F_7 ;
V_30 -> V_31 = F_1 ;
return 0 ;
}
