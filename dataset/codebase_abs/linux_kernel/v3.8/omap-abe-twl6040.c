static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_13 ;
struct V_14 * V_15 = F_2 ( V_13 ) ;
int V_16 , V_17 ;
int V_18 ;
V_16 = F_3 ( V_6 -> V_11 ) ;
if ( V_16 == V_19 )
V_17 = V_15 -> V_20 ;
else if ( V_16 == V_21 )
V_17 = 32768 ;
else
return - V_22 ;
V_18 = F_4 ( V_9 , V_16 , V_17 ,
V_23 ) ;
if ( V_18 ) {
F_5 ( V_24 L_1 ) ;
return V_18 ;
}
return V_18 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_25 = V_6 -> V_25 ;
int V_18 = 0 ;
V_18 = F_4 ( V_25 , V_26 ,
19200000 , V_23 ) ;
if ( V_18 < 0 ) {
F_5 ( V_24 L_2 ) ;
return V_18 ;
}
V_18 = F_4 ( V_25 , V_27 , 2400000 ,
V_28 ) ;
if ( V_18 < 0 ) {
F_5 ( V_24 L_3 ) ;
return V_18 ;
}
return 0 ;
}
static inline void F_7 ( struct V_29 * V_30 ,
int V_31 , char * V_32 )
{
if ( ! V_31 )
F_8 ( V_30 , V_32 ) ;
}
static int F_9 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_13 ;
struct V_29 * V_30 = & V_11 -> V_30 ;
struct V_33 * V_34 = F_10 ( V_13 -> V_35 ) ;
struct V_14 * V_15 = F_2 ( V_13 ) ;
int V_36 ;
int V_18 = 0 ;
V_36 = F_11 ( V_11 , V_37 ) ;
F_12 ( V_6 , F_13 ( V_36 ) ,
F_14 ( V_36 ) ) ;
if ( V_15 -> V_38 ) {
V_18 = F_15 ( V_11 , L_4 ,
V_39 , & V_40 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_16 ( & V_40 , F_17 ( V_41 ) ,
V_41 ) ;
F_18 ( V_11 , & V_40 , V_39 ) ;
}
if ( ! V_34 )
return V_18 ;
F_7 ( V_30 , V_34 -> V_42 , L_5 ) ;
F_7 ( V_30 , V_34 -> V_43 , L_6 ) ;
F_7 ( V_30 , V_34 -> V_44 , L_7 ) ;
F_7 ( V_30 , V_34 -> V_45 , L_8 ) ;
F_7 ( V_30 , V_34 -> V_46 , L_9 ) ;
F_7 ( V_30 , V_34 -> V_47 , L_10 ) ;
F_7 ( V_30 , V_34 -> V_48 , L_11 ) ;
F_7 ( V_30 , V_34 -> V_49 , L_12 ) ;
F_7 ( V_30 , V_34 -> V_50 , L_13 ) ;
return V_18 ;
}
static int F_19 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_29 * V_30 = & V_11 -> V_30 ;
return F_20 ( V_30 , V_51 ,
F_17 ( V_51 ) ) ;
}
static int F_21 ( struct V_52 * V_53 )
{
struct V_33 * V_34 = F_10 ( & V_53 -> V_35 ) ;
struct V_54 * V_55 = V_53 -> V_35 . V_56 ;
struct V_12 * V_13 = & V_57 ;
struct V_14 * V_15 ;
int V_58 = 0 ;
int V_18 = 0 ;
V_13 -> V_35 = & V_53 -> V_35 ;
V_15 = F_22 ( & V_53 -> V_35 , sizeof( struct V_14 ) , V_59 ) ;
if ( V_15 == NULL )
return - V_60 ;
V_15 -> V_61 = F_23 ( - V_22 ) ;
if ( V_55 ) {
struct V_54 * V_62 ;
if ( F_24 ( V_13 , L_14 ) ) {
F_25 ( & V_53 -> V_35 , L_15 ) ;
return - V_63 ;
}
V_18 = F_26 ( V_13 ,
L_16 ) ;
if ( V_18 ) {
F_25 ( & V_53 -> V_35 ,
L_17 ) ;
return V_18 ;
}
V_62 = F_27 ( V_55 , L_18 , 0 ) ;
if ( ! V_62 ) {
F_25 ( & V_53 -> V_35 , L_19 ) ;
return - V_22 ;
}
V_64 [ 0 ] . V_65 = NULL ;
V_64 [ 0 ] . V_66 = V_62 ;
V_62 = F_27 ( V_55 , L_20 , 0 ) ;
if ( V_62 ) {
V_58 = 2 ;
V_64 [ 1 ] . V_65 = NULL ;
V_64 [ 1 ] . V_66 = V_62 ;
V_15 -> V_61 = F_28 (
L_21 , - 1 , NULL , 0 ) ;
if ( F_29 ( V_15 -> V_61 ) ) {
F_25 ( & V_53 -> V_35 ,
L_22 ) ;
return F_30 ( V_15 -> V_61 ) ;
}
} else {
V_58 = 1 ;
}
V_15 -> V_38 = F_31 ( V_55 ,
L_23 ) ;
F_32 ( V_55 , L_24 ,
& V_15 -> V_20 ) ;
if ( ! V_15 -> V_20 ) {
F_25 ( & V_53 -> V_35 , L_25 ) ;
V_18 = - V_22 ;
goto V_67;
}
V_57 . V_68 = 1 ;
} else if ( V_34 ) {
if ( V_34 -> V_69 ) {
V_13 -> V_70 = V_34 -> V_69 ;
} else {
F_25 ( & V_53 -> V_35 , L_15 ) ;
return - V_63 ;
}
if ( V_34 -> V_71 )
V_58 = 2 ;
else
V_58 = 1 ;
V_15 -> V_38 = V_34 -> V_38 ;
V_15 -> V_20 = V_34 -> V_20 ;
} else {
F_25 ( & V_53 -> V_35 , L_26 ) ;
return - V_63 ;
}
if ( ! V_15 -> V_20 ) {
F_25 ( & V_53 -> V_35 , L_27 ) ;
V_18 = - V_63 ;
goto V_67;
}
V_13 -> V_72 = V_64 ;
V_13 -> V_58 = V_58 ;
F_33 ( V_13 , V_15 ) ;
V_18 = F_34 ( V_13 ) ;
if ( V_18 ) {
F_25 ( & V_53 -> V_35 , L_28 ,
V_18 ) ;
goto V_67;
}
return 0 ;
V_67:
if ( ! F_29 ( V_15 -> V_61 ) )
F_35 ( V_15 -> V_61 ) ;
return V_18 ;
}
static int F_36 ( struct V_52 * V_53 )
{
struct V_12 * V_13 = F_37 ( V_53 ) ;
struct V_14 * V_15 = F_2 ( V_13 ) ;
F_38 ( V_13 ) ;
if ( ! F_29 ( V_15 -> V_61 ) )
F_35 ( V_15 -> V_61 ) ;
return 0 ;
}
