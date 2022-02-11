static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_9 = V_4 -> V_9 ;
struct V_8 * V_10 = V_4 -> V_10 ;
int V_11 = 0 ;
F_2 ( & V_4 -> V_12 , V_4 -> V_13 ) ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> V_16 ) {
V_11 = V_7 -> V_14 -> V_15 -> V_16 ( V_2 ) ;
if ( V_11 < 0 ) {
F_3 ( L_1 , V_7 -> V_17 ) ;
goto V_18;
}
}
if ( V_4 -> V_19 -> V_15 && V_4 -> V_19 -> V_15 -> V_20 ) {
V_11 = V_4 -> V_19 -> V_15 -> V_20 ( V_2 ) ;
if ( V_11 < 0 ) {
F_3 ( L_2 , V_4 -> V_19 -> V_17 ) ;
goto V_21;
}
}
if ( V_2 -> V_22 == V_23 ) {
V_9 -> V_24 ++ ;
V_10 -> V_24 ++ ;
} else {
V_9 -> V_25 ++ ;
V_10 -> V_25 ++ ;
}
V_9 -> V_26 ++ ;
V_10 -> V_26 ++ ;
V_4 -> V_27 -> V_26 ++ ;
F_4 ( & V_4 -> V_12 ) ;
return 0 ;
V_21:
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> free )
V_7 -> V_14 -> V_15 -> free ( V_2 ) ;
V_18:
F_4 ( & V_4 -> V_12 ) ;
return V_11 ;
}
static void F_5 ( struct V_28 * V_29 )
{
struct V_3 * V_4 =
F_6 ( V_29 , struct V_3 , V_30 . V_29 ) ;
struct V_8 * V_10 = V_4 -> V_10 ;
F_2 ( & V_4 -> V_12 , V_4 -> V_13 ) ;
F_7 ( V_4 -> V_31 , L_3 ,
V_10 -> V_14 -> V_32 . V_33 ,
V_10 -> V_24 ? L_4 : L_5 ,
V_4 -> V_34 ? L_6 : L_7 ) ;
if ( V_4 -> V_34 == 1 ) {
V_4 -> V_34 = 0 ;
F_8 ( V_4 , V_35 ,
V_36 ) ;
}
F_4 ( & V_4 -> V_12 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_9 = V_4 -> V_9 ;
struct V_8 * V_10 = V_4 -> V_10 ;
struct V_37 * V_27 = V_4 -> V_27 ;
F_2 ( & V_4 -> V_12 , V_4 -> V_13 ) ;
if ( V_2 -> V_22 == V_23 ) {
V_9 -> V_24 -- ;
V_10 -> V_24 -- ;
} else {
V_9 -> V_25 -- ;
V_10 -> V_25 -- ;
}
F_10 ( V_10 , 1 , V_2 -> V_22 ) ;
V_9 -> V_26 -- ;
V_10 -> V_26 -- ;
V_27 -> V_26 -- ;
if ( ! V_9 -> V_26 )
V_9 -> V_38 = 0 ;
if ( ! V_10 -> V_26 )
V_10 -> V_38 = 0 ;
if ( V_4 -> V_19 -> V_15 && V_4 -> V_19 -> V_15 -> V_39 )
V_4 -> V_19 -> V_15 -> V_39 ( V_2 ) ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> free )
V_7 -> V_14 -> V_15 -> free ( V_2 ) ;
V_9 -> V_40 = NULL ;
if ( V_2 -> V_22 == V_23 ) {
if ( ! V_4 -> V_41 || V_27 -> V_42 ||
V_4 -> V_19 -> V_42 ) {
F_8 ( V_4 ,
V_35 ,
V_36 ) ;
} else {
V_4 -> V_34 = 1 ;
F_11 ( & V_4 -> V_30 ,
F_12 ( V_4 -> V_41 ) ) ;
}
} else {
F_8 ( V_4 ,
V_43 ,
V_36 ) ;
}
F_4 ( & V_4 -> V_12 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , int V_44 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_10 = V_4 -> V_10 ;
int V_11 = 0 ;
F_2 ( & V_4 -> V_12 , V_4 -> V_13 ) ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> V_45 ) {
V_11 = V_7 -> V_14 -> V_15 -> V_45 ( V_2 , V_44 ) ;
if ( V_11 < 0 )
goto V_18;
}
switch ( V_44 ) {
case V_46 :
F_10 ( V_10 , 0 , V_2 -> V_22 ) ;
break;
case V_47 :
F_10 ( V_10 , 1 , V_2 -> V_22 ) ;
break;
}
V_18:
F_4 ( & V_4 -> V_12 ) ;
return V_11 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_48 * V_49 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_11 = 0 ;
F_2 ( & V_4 -> V_12 , V_4 -> V_13 ) ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> V_50 ) {
V_11 = V_7 -> V_14 -> V_15 -> V_50 ( V_2 , V_49 ) ;
if ( V_11 < 0 )
goto V_51;
}
if ( V_4 -> V_19 -> V_15 && V_4 -> V_19 -> V_15 -> V_50 ) {
V_11 = V_4 -> V_19 -> V_15 -> V_50 ( V_2 ) ;
if ( V_11 < 0 )
goto V_51;
}
F_8 ( V_4 , V_35 ,
V_52 ) ;
V_4 -> V_34 = 0 ;
F_4 ( & V_4 -> V_12 ) ;
F_15 ( & V_4 -> V_30 ) ;
return V_11 ;
V_51:
F_4 ( & V_4 -> V_12 ) ;
return V_11 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_53 * V_49 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_11 = 0 ;
F_2 ( & V_4 -> V_12 , V_4 -> V_13 ) ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> V_54 )
V_11 = V_7 -> V_14 -> V_15 -> V_54 ( V_2 , V_49 ) ;
F_4 ( & V_4 -> V_12 ) ;
return V_11 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_11 = 0 ;
F_2 ( & V_4 -> V_12 , V_4 -> V_13 ) ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> V_57 )
V_11 = V_7 -> V_14 -> V_15 -> V_57 ( V_2 , V_56 ) ;
F_4 ( & V_4 -> V_12 ) ;
return V_11 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_58 * V_27 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_11 = 0 ;
F_2 ( & V_4 -> V_12 , V_4 -> V_13 ) ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> V_59 )
V_11 = V_7 -> V_14 -> V_15 -> V_59 ( V_2 , V_27 ) ;
F_4 ( & V_4 -> V_12 ) ;
return V_11 ;
}
static int F_19 ( struct V_1 * V_2 , T_1 V_60 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_11 = 0 ;
F_2 ( & V_4 -> V_12 , V_4 -> V_13 ) ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> V_61 )
V_11 = V_7 -> V_14 -> V_15 -> V_61 ( V_2 , V_60 ) ;
F_4 ( & V_4 -> V_12 ) ;
return V_11 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_62 * V_63 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
F_2 ( & V_4 -> V_12 , V_4 -> V_13 ) ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> V_64 )
V_7 -> V_14 -> V_15 -> V_64 ( V_2 , V_63 ) ;
F_4 ( & V_4 -> V_12 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
const char T_2 * V_65 , T_1 V_66 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_11 = 0 ;
F_2 ( & V_4 -> V_12 , V_4 -> V_13 ) ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> V_67 )
V_11 = V_7 -> V_14 -> V_15 -> V_67 ( V_2 , V_65 , V_66 ) ;
F_4 ( & V_4 -> V_12 ) ;
return V_11 ;
}
int F_22 ( struct V_3 * V_4 , int V_68 )
{
struct V_37 * V_27 = V_4 -> V_27 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_10 = V_4 -> V_10 ;
struct V_8 * V_9 = V_4 -> V_9 ;
struct V_69 * V_70 ;
char V_71 [ 64 ] ;
int V_11 = 0 , V_22 = 0 ;
snprintf ( V_71 , sizeof( V_71 ) , L_8 ,
V_4 -> V_19 -> V_33 , V_10 -> V_17 , V_68 ) ;
V_22 = V_23 ;
V_70 = F_23 ( sizeof( * V_70 ) , V_72 ) ;
if ( V_70 == NULL ) {
F_24 ( V_73 L_9 ) ;
return - V_74 ;
}
V_70 -> V_75 = F_25 ( V_4 -> V_76 -> V_31 , sizeof( V_77 ) ,
V_72 ) ;
if ( V_70 -> V_75 == NULL ) {
F_26 ( V_4 -> V_76 -> V_31 , L_10 ) ;
V_11 = - V_74 ;
goto V_78;
}
memcpy ( V_70 -> V_75 , & V_77 , sizeof( V_77 ) ) ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> V_67 )
V_70 -> V_75 -> V_67 = F_21 ;
F_27 ( & V_70 -> V_79 ) ;
V_11 = F_28 ( V_4 -> V_76 -> V_80 , V_68 , V_22 , V_70 ) ;
if ( V_11 < 0 ) {
F_3 ( L_11 ,
V_27 -> V_17 ) ;
goto V_78;
}
F_29 ( & V_4 -> V_30 , F_5 ) ;
V_4 -> V_70 = V_70 ;
V_70 -> V_5 = V_4 ;
F_30 ( V_81 L_12 , V_10 -> V_17 ,
V_9 -> V_17 ) ;
return V_11 ;
V_78:
F_31 ( V_70 ) ;
return V_11 ;
}
