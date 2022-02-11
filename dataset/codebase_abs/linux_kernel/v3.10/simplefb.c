static int F_1 ( T_1 V_1 , T_1 V_2 , T_1 V_3 , T_1 V_4 ,
T_1 V_5 , struct V_6 * V_7 )
{
T_2 * V_8 = V_7 -> V_9 ;
T_2 V_10 = V_2 >> ( 16 - V_7 -> V_11 . V_2 . V_12 ) ;
T_2 V_13 = V_3 >> ( 16 - V_7 -> V_11 . V_3 . V_12 ) ;
T_2 V_14 = V_4 >> ( 16 - V_7 -> V_11 . V_4 . V_12 ) ;
T_2 V_15 ;
if ( V_1 >= 16 )
return - V_16 ;
V_15 = ( V_10 << V_7 -> V_11 . V_2 . V_17 ) |
( V_13 << V_7 -> V_11 . V_3 . V_17 ) |
( V_14 << V_7 -> V_11 . V_4 . V_17 ) ;
if ( V_7 -> V_11 . V_5 . V_12 > 0 ) {
T_2 V_18 = ( 1 << V_7 -> V_11 . V_5 . V_12 ) - 1 ;
V_18 <<= V_7 -> V_11 . V_5 . V_17 ;
V_15 |= V_18 ;
}
V_8 [ V_1 ] = V_15 ;
return 0 ;
}
static int F_2 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 = V_20 -> V_25 . V_26 ;
int V_27 ;
const char * V_28 ;
int V_29 ;
V_27 = F_3 ( V_24 , L_1 , & V_22 -> V_30 ) ;
if ( V_27 ) {
F_4 ( & V_20 -> V_25 , L_2 ) ;
return V_27 ;
}
V_27 = F_3 ( V_24 , L_3 , & V_22 -> V_31 ) ;
if ( V_27 ) {
F_4 ( & V_20 -> V_25 , L_4 ) ;
return V_27 ;
}
V_27 = F_3 ( V_24 , L_5 , & V_22 -> V_32 ) ;
if ( V_27 ) {
F_4 ( & V_20 -> V_25 , L_6 ) ;
return V_27 ;
}
V_27 = F_5 ( V_24 , L_7 , & V_28 ) ;
if ( V_27 ) {
F_4 ( & V_20 -> V_25 , L_8 ) ;
return V_27 ;
}
V_22 -> V_28 = NULL ;
for ( V_29 = 0 ; V_29 < F_6 ( V_33 ) ; V_29 ++ ) {
if ( strcmp ( V_28 , V_33 [ V_29 ] . V_34 ) )
continue;
V_22 -> V_28 = & V_33 [ V_29 ] ;
break;
}
if ( ! V_22 -> V_28 ) {
F_4 ( & V_20 -> V_25 , L_9 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_7 ( struct V_19 * V_20 )
{
int V_27 ;
struct V_21 V_22 ;
struct V_6 * V_7 ;
struct V_35 * V_36 ;
if ( F_8 ( L_10 , NULL ) )
return - V_37 ;
V_27 = F_2 ( V_20 , & V_22 ) ;
if ( V_27 )
return V_27 ;
V_36 = F_9 ( V_20 , V_38 , 0 ) ;
if ( ! V_36 ) {
F_4 ( & V_20 -> V_25 , L_11 ) ;
return - V_16 ;
}
V_7 = F_10 ( sizeof( T_2 ) * 16 , & V_20 -> V_25 ) ;
if ( ! V_7 )
return - V_39 ;
F_11 ( V_20 , V_7 ) ;
V_7 -> V_40 = V_41 ;
V_7 -> V_40 . V_42 = V_36 -> V_43 ;
V_7 -> V_40 . V_44 = F_12 ( V_36 ) ;
V_7 -> V_40 . V_45 = V_22 . V_32 ;
V_7 -> V_11 = V_46 ;
V_7 -> V_11 . V_47 = V_22 . V_30 ;
V_7 -> V_11 . V_48 = V_22 . V_31 ;
V_7 -> V_11 . V_49 = V_22 . V_30 ;
V_7 -> V_11 . V_50 = V_22 . V_31 ;
V_7 -> V_11 . V_51 = V_22 . V_28 -> V_51 ;
V_7 -> V_11 . V_2 = V_22 . V_28 -> V_2 ;
V_7 -> V_11 . V_3 = V_22 . V_28 -> V_3 ;
V_7 -> V_11 . V_4 = V_22 . V_28 -> V_4 ;
V_7 -> V_11 . V_5 = V_22 . V_28 -> V_5 ;
V_7 -> V_52 = & V_53 ;
V_7 -> V_54 = V_55 ;
V_7 -> V_56 = F_13 ( & V_20 -> V_25 , V_7 -> V_40 . V_42 ,
V_7 -> V_40 . V_44 ) ;
if ( ! V_7 -> V_56 ) {
F_14 ( V_7 ) ;
return - V_37 ;
}
V_7 -> V_9 = ( void * ) ( V_7 + 1 ) ;
V_27 = F_15 ( V_7 ) ;
if ( V_27 < 0 ) {
F_4 ( & V_20 -> V_25 , L_12 , V_27 ) ;
F_14 ( V_7 ) ;
return V_27 ;
}
F_16 ( & V_20 -> V_25 , L_13 , V_7 -> V_57 ) ;
return 0 ;
}
static int F_17 ( struct V_19 * V_20 )
{
struct V_6 * V_7 = F_18 ( V_20 ) ;
F_19 ( V_7 ) ;
F_14 ( V_7 ) ;
return 0 ;
}
