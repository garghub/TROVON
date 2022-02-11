static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
struct V_11 * V_12 = V_6 -> V_12 ;
struct V_13 * V_14 = V_12 -> V_14 ;
unsigned int V_15 ;
int V_16 ;
switch ( F_2 ( V_4 ) ) {
case 2 :
V_15 = V_17 |
V_18 |
V_19 ;
break;
case 4 :
V_15 = V_20 |
V_21 |
V_19 ;
break;
default:
return - V_22 ;
}
V_16 = F_3 ( V_9 , V_15 ) ;
if ( V_16 < 0 ) {
F_4 ( V_14 -> V_23 , L_1 ) ;
return V_16 ;
}
V_16 = F_3 ( V_10 , V_15 ) ;
if ( V_16 < 0 ) {
F_4 ( V_14 -> V_23 , L_2 ) ;
return V_16 ;
}
return 0 ;
}
static inline void F_5 ( struct V_24 * V_25 ,
int V_26 , char * V_27 )
{
if ( ! V_26 )
F_6 ( V_25 , V_27 ) ;
}
static int F_7 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = V_6 -> V_12 ;
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_24 * V_25 = & V_12 -> V_25 ;
struct V_28 * V_29 = F_8 ( V_14 -> V_23 ) ;
struct V_30 * V_31 = F_9 ( V_14 ) ;
int V_16 = 0 ;
if ( V_31 -> V_32 > 0 ) {
V_33 [ 0 ] . V_34 = V_31 -> V_32 ;
V_16 = F_10 ( V_12 , L_3 , V_35 ,
& V_31 -> V_36 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_11 ( & V_31 -> V_36 ,
F_12 ( V_37 ) ,
V_37 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_13 ( & V_31 -> V_36 ,
F_12 ( V_33 ) ,
V_33 ) ;
if ( V_16 )
return V_16 ;
}
if ( ! V_29 || ! V_29 -> V_38 )
return V_16 ;
F_5 ( V_25 , V_29 -> V_39 , L_4 ) ;
F_5 ( V_25 , V_29 -> V_40 , L_5 ) ;
F_5 ( V_25 , V_29 -> V_41 , L_6 ) ;
F_5 ( V_25 , V_29 -> V_42 , L_7 ) ;
F_5 ( V_25 , V_29 -> V_43 , L_8 ) ;
F_5 ( V_25 , V_29 -> V_44 , L_9 ) ;
F_5 ( V_25 , V_29 -> V_45 , L_10 ) ;
F_5 ( V_25 , V_29 -> V_46 , L_11 ) ;
F_5 ( V_25 , V_29 -> V_47 , L_12 ) ;
F_5 ( V_25 , V_29 -> V_48 , L_13 ) ;
F_5 ( V_25 , V_29 -> V_49 , L_14 ) ;
F_5 ( V_25 , V_29 -> V_50 , L_15 ) ;
return V_16 ;
}
static int F_14 ( struct V_51 * V_52 )
{
struct V_28 * V_29 = F_8 ( & V_52 -> V_23 ) ;
struct V_53 * V_54 = V_52 -> V_23 . V_55 ;
struct V_13 * V_14 = & V_56 ;
struct V_30 * V_31 ;
int V_16 = 0 ;
V_14 -> V_23 = & V_52 -> V_23 ;
V_31 = F_15 ( & V_52 -> V_23 , sizeof( struct V_30 ) , V_57 ) ;
if ( V_31 == NULL )
return - V_58 ;
if ( V_54 ) {
struct V_53 * V_59 ;
struct V_60 * V_61 ;
if ( F_16 ( V_14 , L_16 ) ) {
F_4 ( & V_52 -> V_23 , L_17 ) ;
return - V_62 ;
}
V_59 = F_17 ( V_54 , L_18 , 0 ) ;
if ( ! V_59 ) {
F_4 ( & V_52 -> V_23 , L_19 ) ;
return - V_22 ;
}
V_63 [ 0 ] . V_64 = NULL ;
V_63 [ 0 ] . V_65 = V_59 ;
V_59 = F_17 ( V_54 , L_20 , 0 ) ;
if ( ! V_59 ) {
V_14 -> V_66 = 1 ;
} else {
V_63 [ 1 ] . V_64 = NULL ;
V_63 [ 1 ] . V_65 = V_59 ;
}
V_31 -> V_32 = F_18 ( V_54 ,
L_21 , 0 ) ;
V_61 = F_19 ( V_54 , L_22 , NULL ) ;
if ( V_61 ) {
V_16 = F_20 ( V_14 ,
L_22 ) ;
if ( V_16 )
return V_16 ;
V_14 -> V_67 = 1 ;
}
} else if ( V_29 ) {
if ( V_29 -> V_68 ) {
V_14 -> V_69 = V_29 -> V_68 ;
} else {
F_4 ( & V_52 -> V_23 , L_17 ) ;
return - V_62 ;
}
if ( ! V_29 -> V_70 )
V_14 -> V_66 = 1 ;
V_31 -> V_32 = V_29 -> V_32 ;
} else {
F_4 ( & V_52 -> V_23 , L_23 ) ;
return - V_62 ;
}
F_21 ( V_14 , V_31 ) ;
V_16 = F_22 ( & V_52 -> V_23 , V_14 ) ;
if ( V_16 ) {
F_4 ( & V_52 -> V_23 , L_24 ,
V_16 ) ;
return V_16 ;
}
return 0 ;
}
static int F_23 ( struct V_51 * V_52 )
{
struct V_13 * V_14 = F_24 ( V_52 ) ;
struct V_30 * V_31 = F_9 ( V_14 ) ;
if ( V_31 -> V_32 > 0 )
F_25 ( & V_31 -> V_36 ,
F_12 ( V_33 ) ,
V_33 ) ;
return 0 ;
}
