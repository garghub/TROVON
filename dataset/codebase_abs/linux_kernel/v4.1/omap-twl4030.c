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
struct V_21 * V_22 = V_6 -> V_22 ;
struct V_15 * V_16 = & V_20 -> V_16 ;
struct V_23 * V_24 = F_7 ( V_22 -> V_25 ) ;
struct V_26 * V_27 = F_8 ( V_22 ) ;
int V_28 = 0 ;
if ( V_27 -> V_29 > 0 ) {
V_30 [ 0 ] . V_31 = V_27 -> V_29 ;
V_28 = F_9 ( V_6 -> V_22 , L_1 ,
V_32 , & V_27 -> V_33 ,
V_34 ,
F_10 ( V_34 ) ) ;
if ( V_28 )
return V_28 ;
V_28 = F_11 ( & V_27 -> V_33 ,
F_10 ( V_30 ) ,
V_30 ) ;
if ( V_28 )
return V_28 ;
}
if ( ! V_24 || ! V_24 -> V_35 )
return V_28 ;
F_4 ( V_16 , V_24 -> V_36 , L_2 ) ;
F_4 ( V_16 , V_24 -> V_37 , L_3 ) ;
F_4 ( V_16 , V_24 -> V_38 , L_4 ) ;
F_4 ( V_16 , V_24 -> V_39 , L_5 ) ;
F_4 ( V_16 , V_24 -> V_40 , L_6 ) ;
F_4 ( V_16 , V_24 -> V_41 , L_7 ) ;
F_4 ( V_16 , V_24 -> V_42 , L_8 ) ;
F_4 ( V_16 , V_24 -> V_43 , L_9 ) ;
F_4 ( V_16 , V_24 -> V_44 , L_10 ) ;
F_4 ( V_16 , V_24 -> V_45 , L_11 ) ;
F_4 ( V_16 , V_24 -> V_46 , L_12 ) ;
F_4 ( V_16 , V_24 -> V_47 , L_13 ) ;
return V_28 ;
}
static int F_12 ( struct V_21 * V_22 )
{
struct V_26 * V_27 = F_8 ( V_22 ) ;
if ( V_27 -> V_29 > 0 )
F_13 ( & V_27 -> V_33 ,
F_10 ( V_30 ) ,
V_30 ) ;
return 0 ;
}
static int F_14 ( struct V_48 * V_49 )
{
struct V_23 * V_24 = F_7 ( & V_49 -> V_25 ) ;
struct V_50 * V_51 = V_49 -> V_25 . V_52 ;
struct V_21 * V_22 = & V_53 ;
struct V_26 * V_27 ;
int V_28 = 0 ;
V_22 -> V_25 = & V_49 -> V_25 ;
V_27 = F_15 ( & V_49 -> V_25 , sizeof( struct V_26 ) , V_54 ) ;
if ( V_27 == NULL )
return - V_55 ;
if ( V_51 ) {
struct V_50 * V_56 ;
struct V_57 * V_58 ;
if ( F_16 ( V_22 , L_14 ) ) {
F_17 ( & V_49 -> V_25 , L_15 ) ;
return - V_59 ;
}
V_56 = F_18 ( V_51 , L_16 , 0 ) ;
if ( ! V_56 ) {
F_17 ( & V_49 -> V_25 , L_17 ) ;
return - V_14 ;
}
V_60 [ 0 ] . V_61 = NULL ;
V_60 [ 0 ] . V_62 = V_56 ;
V_60 [ 0 ] . V_63 = NULL ;
V_60 [ 0 ] . V_64 = V_56 ;
V_56 = F_18 ( V_51 , L_18 , 0 ) ;
if ( ! V_56 ) {
V_22 -> V_65 = 1 ;
} else {
V_60 [ 1 ] . V_61 = NULL ;
V_60 [ 1 ] . V_62 = V_56 ;
V_60 [ 1 ] . V_63 = NULL ;
V_60 [ 1 ] . V_64 = V_56 ;
}
V_27 -> V_29 = F_19 ( V_51 ,
L_19 , 0 ) ;
V_58 = F_20 ( V_51 , L_20 , NULL ) ;
if ( V_58 ) {
V_28 = F_21 ( V_22 ,
L_20 ) ;
if ( V_28 )
return V_28 ;
V_22 -> V_66 = 1 ;
}
} else if ( V_24 ) {
if ( V_24 -> V_67 ) {
V_22 -> V_68 = V_24 -> V_67 ;
} else {
F_17 ( & V_49 -> V_25 , L_15 ) ;
return - V_59 ;
}
if ( ! V_24 -> V_69 )
V_22 -> V_65 = 1 ;
V_27 -> V_29 = V_24 -> V_29 ;
} else {
F_17 ( & V_49 -> V_25 , L_21 ) ;
return - V_59 ;
}
F_22 ( V_22 , V_27 ) ;
V_28 = F_23 ( & V_49 -> V_25 , V_22 ) ;
if ( V_28 ) {
F_17 ( & V_49 -> V_25 , L_22 ,
V_28 ) ;
return V_28 ;
}
return 0 ;
}
