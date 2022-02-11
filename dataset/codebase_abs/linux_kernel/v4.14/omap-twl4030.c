static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_8 ;
switch ( F_2 ( V_4 ) ) {
case 2 :
V_8 = V_9 |
V_10 |
V_11 ;
break;
case 4 :
V_8 = V_12 |
V_13 |
V_11 ;
break;
default:
return - V_14 ;
}
return F_3 ( V_6 , V_8 ) ;
}
static inline void F_4 ( struct V_15 * V_16 ,
int V_17 , char * V_18 )
{
if ( ! V_17 )
F_5 ( V_16 , V_18 ) ;
}
static int F_6 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = V_6 -> V_20 ;
struct V_15 * V_16 = & V_20 -> V_16 ;
struct V_21 * V_22 = F_7 ( V_20 -> V_23 ) ;
struct V_24 * V_25 = F_8 ( V_20 ) ;
int V_26 = 0 ;
if ( V_25 -> V_27 > 0 ) {
V_28 [ 0 ] . V_29 = V_25 -> V_27 ;
V_26 = F_9 ( V_6 -> V_20 , L_1 ,
V_30 , & V_25 -> V_31 ,
V_32 ,
F_10 ( V_32 ) ) ;
if ( V_26 )
return V_26 ;
V_26 = F_11 ( & V_25 -> V_31 ,
F_10 ( V_28 ) ,
V_28 ) ;
if ( V_26 )
return V_26 ;
}
if ( ! V_22 || ! V_22 -> V_33 )
return V_26 ;
F_4 ( V_16 , V_22 -> V_34 , L_2 ) ;
F_4 ( V_16 , V_22 -> V_35 , L_3 ) ;
F_4 ( V_16 , V_22 -> V_36 , L_4 ) ;
F_4 ( V_16 , V_22 -> V_37 , L_5 ) ;
F_4 ( V_16 , V_22 -> V_38 , L_6 ) ;
F_4 ( V_16 , V_22 -> V_39 , L_7 ) ;
F_4 ( V_16 , V_22 -> V_40 , L_8 ) ;
F_4 ( V_16 , V_22 -> V_41 , L_9 ) ;
F_4 ( V_16 , V_22 -> V_42 , L_10 ) ;
F_4 ( V_16 , V_22 -> V_43 , L_11 ) ;
F_4 ( V_16 , V_22 -> V_44 , L_12 ) ;
F_4 ( V_16 , V_22 -> V_45 , L_13 ) ;
return V_26 ;
}
static int F_12 ( struct V_46 * V_47 )
{
struct V_21 * V_22 = F_7 ( & V_47 -> V_23 ) ;
struct V_48 * V_49 = V_47 -> V_23 . V_50 ;
struct V_19 * V_20 = & V_51 ;
struct V_24 * V_25 ;
int V_26 = 0 ;
V_20 -> V_23 = & V_47 -> V_23 ;
V_25 = F_13 ( & V_47 -> V_23 , sizeof( struct V_24 ) , V_52 ) ;
if ( V_25 == NULL )
return - V_53 ;
if ( V_49 ) {
struct V_48 * V_54 ;
struct V_55 * V_56 ;
if ( F_14 ( V_20 , L_14 ) ) {
F_15 ( & V_47 -> V_23 , L_15 ) ;
return - V_57 ;
}
V_54 = F_16 ( V_49 , L_16 , 0 ) ;
if ( ! V_54 ) {
F_15 ( & V_47 -> V_23 , L_17 ) ;
return - V_14 ;
}
V_58 [ 0 ] . V_59 = NULL ;
V_58 [ 0 ] . V_60 = V_54 ;
V_58 [ 0 ] . V_61 = NULL ;
V_58 [ 0 ] . V_62 = V_54 ;
V_54 = F_16 ( V_49 , L_18 , 0 ) ;
if ( ! V_54 ) {
V_20 -> V_63 = 1 ;
} else {
V_58 [ 1 ] . V_59 = NULL ;
V_58 [ 1 ] . V_60 = V_54 ;
V_58 [ 1 ] . V_61 = NULL ;
V_58 [ 1 ] . V_62 = V_54 ;
}
V_25 -> V_27 = F_17 ( V_49 ,
L_19 , 0 ) ;
V_56 = F_18 ( V_49 , L_20 , NULL ) ;
if ( V_56 ) {
V_26 = F_19 ( V_20 ,
L_20 ) ;
if ( V_26 )
return V_26 ;
V_20 -> V_64 = 1 ;
}
} else if ( V_22 ) {
if ( V_22 -> V_65 ) {
V_20 -> V_66 = V_22 -> V_65 ;
} else {
F_15 ( & V_47 -> V_23 , L_15 ) ;
return - V_57 ;
}
if ( ! V_22 -> V_67 )
V_20 -> V_63 = 1 ;
V_25 -> V_27 = V_22 -> V_27 ;
} else {
F_15 ( & V_47 -> V_23 , L_21 ) ;
return - V_57 ;
}
F_20 ( V_20 , V_25 ) ;
V_26 = F_21 ( & V_47 -> V_23 , V_20 ) ;
if ( V_26 ) {
F_15 ( & V_47 -> V_23 , L_22 ,
V_26 ) ;
return V_26 ;
}
return 0 ;
}
