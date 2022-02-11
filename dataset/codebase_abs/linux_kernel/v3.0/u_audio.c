static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_1 V_4 ;
V_4 . V_5 = 0 ;
V_4 . V_6 = V_4 . V_7 = V_3 ;
V_4 . V_8 = V_4 . V_9 = 0 ;
V_4 . integer = 1 ;
return F_2 ( V_2 , & V_4 ) ;
}
static int F_3 ( struct V_10 * V_11 ,
T_1 V_12 , unsigned int V_3 ,
int V_13 )
{
int V_14 ;
if ( F_4 ( V_12 ) ) {
struct V_15 * V_16 = F_5 ( V_11 , V_12 ) ;
if ( V_3 == 0 && V_13 < 0 ) {
V_14 = - V_17 ;
F_6 ( V_16 ) ;
} else {
if ( V_13 > 0 )
V_3 ++ ;
else if ( V_13 < 0 )
V_3 -- ;
V_14 = F_7 (
F_5 ( V_11 , V_12 ) , V_3 ) ;
}
} else if ( F_8 ( V_12 ) ) {
struct V_1 * V_2 = F_9 ( V_11 , V_12 ) ;
if ( V_3 == 0 && V_13 < 0 ) {
V_14 = - V_17 ;
F_10 ( V_2 ) ;
} else if ( V_13 == 0 )
V_14 = F_1 ( V_2 , V_3 ) ;
else {
struct V_1 V_4 ;
V_4 . V_8 = 1 ;
V_4 . V_9 = 1 ;
V_4 . V_5 = 0 ;
V_4 . integer = 0 ;
if ( V_13 < 0 ) {
V_4 . V_6 = V_3 - 1 ;
V_4 . V_7 = V_3 ;
} else {
V_4 . V_6 = V_3 ;
V_4 . V_7 = V_3 + 1 ;
}
V_14 = F_2 ( V_2 , & V_4 ) ;
}
} else
return - V_17 ;
if ( V_14 ) {
V_11 -> V_18 |= 1 << V_12 ;
V_11 -> V_19 |= 1 << V_12 ;
}
return V_14 ;
}
static int F_11 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_23 ;
struct V_10 * V_11 ;
T_2 V_24 ;
V_21 -> V_25 = V_26 ;
V_21 -> V_27 = V_28 ;
V_21 -> V_29 = 2 ;
V_21 -> V_30 = 48000 ;
V_11 = F_12 ( sizeof( * V_11 ) , V_31 ) ;
if ( ! V_11 )
return - V_32 ;
F_13 ( V_11 ) ;
F_3 ( V_11 , V_33 ,
V_21 -> V_25 , 0 ) ;
F_3 ( V_11 , V_34 ,
V_21 -> V_27 , 0 ) ;
F_3 ( V_11 , V_35 ,
V_21 -> V_29 , 0 ) ;
F_3 ( V_11 , V_36 ,
V_21 -> V_30 , 0 ) ;
F_14 ( V_23 , V_37 , NULL ) ;
F_14 ( V_23 , V_38 , V_11 ) ;
V_24 = F_14 ( V_23 , V_39 , NULL ) ;
if ( V_24 < 0 ) {
ERROR ( V_21 -> V_40 ,
L_1 , ( int ) V_24 ) ;
F_15 ( V_11 ) ;
return V_24 ;
}
V_21 -> V_25 = F_16 ( V_11 ) ;
V_21 -> V_27 = F_17 ( V_11 ) ;
V_21 -> V_29 = F_18 ( V_11 ) ;
V_21 -> V_30 = F_19 ( V_11 ) ;
F_15 ( V_11 ) ;
F_20 ( V_21 -> V_40 ,
L_2 ,
V_21 -> V_25 , V_21 -> V_27 , V_21 -> V_29 , V_21 -> V_30 ) ;
return 0 ;
}
static T_3 F_21 ( struct V_41 * V_40 , void * V_42 , T_3 V_43 )
{
struct V_20 * V_21 = & V_40 -> V_44 ;
struct V_22 * V_23 = V_21 -> V_23 ;
struct V_45 * V_46 = V_23 -> V_46 ;
T_4 V_47 ;
T_5 V_24 ;
T_2 V_48 ;
V_49:
if ( V_46 -> V_50 -> V_51 == V_52 ||
V_46 -> V_50 -> V_51 == V_53 ) {
V_24 = F_14 ( V_23 ,
V_39 , NULL ) ;
if ( V_24 < 0 ) {
ERROR ( V_40 , L_1 ,
( int ) V_24 ) ;
return V_24 ;
}
}
V_48 = F_22 ( V_46 , V_43 ) ;
V_47 = F_23 () ;
F_24 ( V_54 ) ;
V_24 = F_25 ( V_21 -> V_23 , V_42 , V_48 ) ;
if ( V_24 != V_48 ) {
ERROR ( V_40 , L_3 , ( int ) V_24 ) ;
F_24 ( V_47 ) ;
goto V_49;
}
F_24 ( V_47 ) ;
return 0 ;
}
static int F_26 ( struct V_41 * V_40 )
{
return V_40 -> V_44 . V_29 ;
}
static int F_27 ( struct V_41 * V_40 )
{
return V_40 -> V_44 . V_30 ;
}
static int F_28 ( struct V_41 * V_40 )
{
struct V_55 * V_56 ;
struct V_20 * V_21 ;
if ( ! V_40 )
return - V_57 ;
V_21 = & V_40 -> V_58 ;
V_21 -> V_59 = F_29 ( V_60 , V_61 , 0 ) ;
if ( F_30 ( V_21 -> V_59 ) ) {
int V_62 = F_31 ( V_21 -> V_59 ) ;
ERROR ( V_40 , L_4 ,
V_60 ) ;
V_21 -> V_59 = NULL ;
return V_62 ;
}
V_21 -> V_40 = V_40 ;
V_21 = & V_40 -> V_44 ;
V_21 -> V_59 = F_29 ( V_63 , V_64 , 0 ) ;
if ( F_30 ( V_21 -> V_59 ) ) {
ERROR ( V_40 , L_5 , V_63 ) ;
V_21 -> V_59 = NULL ;
}
V_56 = V_21 -> V_59 -> V_65 ;
V_21 -> V_23 = V_56 -> V_23 ;
V_21 -> V_40 = V_40 ;
F_11 ( V_21 ) ;
V_21 = & V_40 -> V_66 ;
V_21 -> V_59 = F_29 ( V_67 , V_68 , 0 ) ;
if ( F_30 ( V_21 -> V_59 ) ) {
ERROR ( V_40 , L_6 , V_67 ) ;
V_21 -> V_23 = NULL ;
V_21 -> V_40 = NULL ;
V_21 -> V_59 = NULL ;
} else {
V_56 = V_21 -> V_59 -> V_65 ;
V_21 -> V_23 = V_56 -> V_23 ;
V_21 -> V_40 = V_40 ;
}
return 0 ;
}
static int F_32 ( struct V_41 * V_69 )
{
struct V_20 * V_21 ;
V_21 = & V_69 -> V_58 ;
if ( V_21 -> V_59 )
F_33 ( V_21 -> V_59 , V_70 -> V_71 ) ;
V_21 = & V_69 -> V_44 ;
if ( V_21 -> V_59 )
F_33 ( V_21 -> V_59 , V_70 -> V_71 ) ;
V_21 = & V_69 -> V_66 ;
if ( V_21 -> V_59 )
F_33 ( V_21 -> V_59 , V_70 -> V_71 ) ;
return 0 ;
}
int T_6 F_34 ( struct V_41 * V_40 )
{
int V_62 ;
V_62 = F_28 ( V_40 ) ;
if ( V_62 )
ERROR ( V_40 , L_7 ) ;
else if ( ! V_72 )
V_72 = V_40 ;
return V_62 ;
}
void F_35 ( void )
{
if ( V_72 ) {
F_32 ( V_72 ) ;
V_72 = NULL ;
}
}
