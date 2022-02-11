static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_9 = V_4 -> V_9 ;
struct V_8 * V_10 = V_4 -> V_10 ;
int V_11 = 0 ;
if ( V_7 -> V_12 -> V_13 && V_7 -> V_12 -> V_13 -> V_14 ) {
V_11 = V_7 -> V_12 -> V_13 -> V_14 ( V_2 ) ;
if ( V_11 < 0 ) {
F_2 ( L_1 , V_7 -> V_15 ) ;
goto V_16;
}
}
if ( V_4 -> V_17 -> V_13 && V_4 -> V_17 -> V_13 -> V_18 ) {
V_11 = V_4 -> V_17 -> V_13 -> V_18 ( V_2 ) ;
if ( V_11 < 0 ) {
F_2 ( L_2 , V_4 -> V_17 -> V_15 ) ;
goto V_19;
}
}
if ( V_2 -> V_20 == V_21 ) {
V_9 -> V_22 ++ ;
V_10 -> V_22 ++ ;
} else {
V_9 -> V_23 ++ ;
V_10 -> V_23 ++ ;
}
V_9 -> V_24 ++ ;
V_10 -> V_24 ++ ;
V_4 -> V_25 -> V_24 ++ ;
return 0 ;
V_19:
if ( V_7 -> V_12 -> V_13 && V_7 -> V_12 -> V_13 -> free )
V_7 -> V_12 -> V_13 -> free ( V_2 ) ;
V_16:
return V_11 ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_9 = V_4 -> V_9 ;
struct V_8 * V_10 = V_4 -> V_10 ;
struct V_26 * V_25 = V_4 -> V_25 ;
if ( V_2 -> V_20 == V_21 ) {
V_9 -> V_22 -- ;
V_10 -> V_22 -- ;
} else {
V_9 -> V_23 -- ;
V_10 -> V_23 -- ;
}
F_4 ( V_10 , 1 ) ;
V_9 -> V_24 -- ;
V_10 -> V_24 -- ;
V_25 -> V_24 -- ;
if ( ! V_9 -> V_24 )
V_9 -> V_27 = 0 ;
if ( ! V_10 -> V_24 )
V_10 -> V_27 = 0 ;
if ( V_4 -> V_17 -> V_13 && V_4 -> V_17 -> V_13 -> V_28 )
V_4 -> V_17 -> V_13 -> V_28 ( V_2 ) ;
if ( V_7 -> V_12 -> V_13 && V_7 -> V_12 -> V_13 -> free )
V_7 -> V_12 -> V_13 -> free ( V_2 ) ;
V_9 -> V_29 = NULL ;
if ( V_2 -> V_20 == V_21 ) {
if ( ! V_4 -> V_30 || V_25 -> V_31 ||
V_4 -> V_17 -> V_31 ) {
F_5 ( V_4 ,
V_32 ,
V_33 ) ;
} else
V_10 -> V_34 = 1 ;
F_6 ( & V_4 -> V_35 ,
F_7 ( V_4 -> V_30 ) ) ;
} else {
F_5 ( V_4 ,
V_36 ,
V_33 ) ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , int V_37 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_10 = V_4 -> V_10 ;
int V_11 = 0 ;
if ( V_7 -> V_12 -> V_13 && V_7 -> V_12 -> V_13 -> V_38 ) {
V_11 = V_7 -> V_12 -> V_13 -> V_38 ( V_2 , V_37 ) ;
if ( V_11 < 0 )
return V_11 ;
}
if ( V_37 == V_39 )
F_4 ( V_10 , 0 ) ;
else if ( V_37 == V_40 )
F_4 ( V_10 , 1 ) ;
return V_11 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_11 = 0 ;
if ( V_7 -> V_12 -> V_13 && V_7 -> V_12 -> V_13 -> V_43 ) {
V_11 = V_7 -> V_12 -> V_13 -> V_43 ( V_2 , V_42 ) ;
if ( V_11 < 0 )
return V_11 ;
}
if ( V_4 -> V_17 -> V_13 && V_4 -> V_17 -> V_13 -> V_43 ) {
V_11 = V_4 -> V_17 -> V_13 -> V_43 ( V_2 ) ;
if ( V_11 < 0 )
return V_11 ;
}
F_5 ( V_4 , V_32 ,
V_44 ) ;
return V_11 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_45 * V_42 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_11 = 0 ;
if ( V_7 -> V_12 -> V_13 && V_7 -> V_12 -> V_13 -> V_46 )
V_11 = V_7 -> V_12 -> V_13 -> V_46 ( V_2 , V_42 ) ;
return V_11 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_11 = 0 ;
if ( V_7 -> V_12 -> V_13 && V_7 -> V_12 -> V_13 -> V_49 )
V_11 = V_7 -> V_12 -> V_13 -> V_49 ( V_2 , V_48 ) ;
return V_11 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_50 * V_25 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_11 = 0 ;
if ( V_7 -> V_12 -> V_13 && V_7 -> V_12 -> V_13 -> V_51 )
V_11 = V_7 -> V_12 -> V_13 -> V_51 ( V_2 , V_25 ) ;
return V_11 ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_52 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_11 = 0 ;
if ( V_7 -> V_12 -> V_13 && V_7 -> V_12 -> V_13 -> V_53 )
V_11 = V_7 -> V_12 -> V_13 -> V_53 ( V_2 , V_52 ) ;
return V_11 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
if ( V_7 -> V_12 -> V_13 && V_7 -> V_12 -> V_13 -> V_56 )
V_7 -> V_12 -> V_13 -> V_56 ( V_2 , V_55 ) ;
return 0 ;
}
int F_15 ( struct V_3 * V_4 , int V_57 )
{
struct V_26 * V_25 = V_4 -> V_25 ;
struct V_8 * V_10 = V_4 -> V_10 ;
struct V_8 * V_9 = V_4 -> V_9 ;
struct V_58 * V_59 ;
char V_60 [ 64 ] ;
int V_11 = 0 , V_20 = 0 ;
snprintf ( V_60 , sizeof( V_60 ) , L_3 ,
V_4 -> V_17 -> V_61 , V_10 -> V_15 , V_57 ) ;
V_20 = V_21 ;
V_59 = F_16 ( sizeof( * V_59 ) , V_62 ) ;
if ( V_59 == NULL ) {
F_17 ( V_63 L_4 ) ;
return - V_64 ;
}
V_59 -> V_65 = & V_66 ;
F_18 ( & V_59 -> V_67 ) ;
V_11 = F_19 ( V_4 -> V_68 -> V_69 , V_57 , V_20 , V_59 ) ;
if ( V_11 < 0 ) {
F_2 ( L_5 ,
V_25 -> V_15 ) ;
F_20 ( V_59 ) ;
return V_11 ;
}
V_4 -> V_59 = V_59 ;
V_59 -> V_5 = V_4 ;
F_21 ( V_70 L_6 , V_10 -> V_15 ,
V_9 -> V_15 ) ;
return V_11 ;
}
