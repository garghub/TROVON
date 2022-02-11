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
F_11 ( V_43 ,
& V_4 -> V_30 ,
F_12 ( V_4 -> V_41 ) ) ;
}
} else {
F_8 ( V_4 ,
V_44 ,
V_36 ) ;
}
F_4 ( & V_4 -> V_12 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , int V_45 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_10 = V_4 -> V_10 ;
int V_11 = 0 ;
F_2 ( & V_4 -> V_12 , V_4 -> V_13 ) ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> V_46 ) {
V_11 = V_7 -> V_14 -> V_15 -> V_46 ( V_2 , V_45 ) ;
if ( V_11 < 0 )
goto V_18;
}
switch ( V_45 ) {
case V_47 :
F_10 ( V_10 , 0 , V_2 -> V_22 ) ;
break;
case V_48 :
F_10 ( V_10 , 1 , V_2 -> V_22 ) ;
break;
}
V_18:
F_4 ( & V_4 -> V_12 ) ;
return V_11 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_11 = 0 ;
F_2 ( & V_4 -> V_12 , V_4 -> V_13 ) ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> V_51 ) {
V_11 = V_7 -> V_14 -> V_15 -> V_51 ( V_2 , V_50 ) ;
if ( V_11 < 0 )
goto V_52;
}
if ( V_4 -> V_19 -> V_15 && V_4 -> V_19 -> V_15 -> V_51 ) {
V_11 = V_4 -> V_19 -> V_15 -> V_51 ( V_2 ) ;
if ( V_11 < 0 )
goto V_52;
}
if ( V_2 -> V_22 == V_23 )
F_8 ( V_4 , V_35 ,
V_53 ) ;
else
F_8 ( V_4 , V_44 ,
V_53 ) ;
V_4 -> V_34 = 0 ;
F_4 ( & V_4 -> V_12 ) ;
F_15 ( & V_4 -> V_30 ) ;
return V_11 ;
V_52:
F_4 ( & V_4 -> V_12 ) ;
return V_11 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_54 * V_50 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_11 = 0 ;
F_2 ( & V_4 -> V_12 , V_4 -> V_13 ) ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> V_55 )
V_11 = V_7 -> V_14 -> V_15 -> V_55 ( V_2 , V_50 ) ;
F_4 ( & V_4 -> V_12 ) ;
return V_11 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_56 * V_57 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_11 = 0 ;
F_2 ( & V_4 -> V_12 , V_4 -> V_13 ) ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> V_58 )
V_11 = V_7 -> V_14 -> V_15 -> V_58 ( V_2 , V_57 ) ;
F_4 ( & V_4 -> V_12 ) ;
return V_11 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_59 * V_27 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_11 = 0 ;
F_2 ( & V_4 -> V_12 , V_4 -> V_13 ) ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> V_60 )
V_11 = V_7 -> V_14 -> V_15 -> V_60 ( V_2 , V_27 ) ;
F_4 ( & V_4 -> V_12 ) ;
return V_11 ;
}
static int F_19 ( struct V_1 * V_2 , T_1 V_61 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_11 = 0 ;
F_2 ( & V_4 -> V_12 , V_4 -> V_13 ) ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> V_62 )
V_11 = V_7 -> V_14 -> V_15 -> V_62 ( V_2 , V_61 ) ;
F_4 ( & V_4 -> V_12 ) ;
return V_11 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
F_2 ( & V_4 -> V_12 , V_4 -> V_13 ) ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> V_65 )
V_7 -> V_14 -> V_15 -> V_65 ( V_2 , V_64 ) ;
F_4 ( & V_4 -> V_12 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
char T_2 * V_66 , T_1 V_67 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_11 = 0 ;
F_2 ( & V_4 -> V_12 , V_4 -> V_13 ) ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> V_68 )
V_11 = V_7 -> V_14 -> V_15 -> V_68 ( V_2 , V_66 , V_67 ) ;
F_4 ( & V_4 -> V_12 ) ;
return V_11 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_69 * V_70 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_11 = 0 ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> V_71 )
V_11 = V_7 -> V_14 -> V_15 -> V_71 ( V_2 , V_70 ) ;
return V_11 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_69 * V_70 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_11 = 0 ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> V_72 )
V_11 = V_7 -> V_14 -> V_15 -> V_72 ( V_2 , V_70 ) ;
return V_11 ;
}
int F_24 ( struct V_3 * V_4 , int V_73 )
{
struct V_37 * V_27 = V_4 -> V_27 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_10 = V_4 -> V_10 ;
struct V_8 * V_9 = V_4 -> V_9 ;
struct V_74 * V_75 ;
char V_76 [ 64 ] ;
int V_11 = 0 , V_22 = 0 ;
snprintf ( V_76 , sizeof( V_76 ) , L_8 ,
V_4 -> V_19 -> V_33 , V_10 -> V_17 , V_73 ) ;
if ( V_10 -> V_14 -> V_32 . V_77 )
V_22 = V_23 ;
else if ( V_10 -> V_14 -> V_78 . V_77 )
V_22 = V_79 ;
else
return - V_80 ;
V_75 = F_25 ( sizeof( * V_75 ) , V_81 ) ;
if ( V_75 == NULL ) {
F_26 ( V_82 L_9 ) ;
return - V_83 ;
}
V_75 -> V_84 = F_27 ( V_4 -> V_85 -> V_31 , sizeof( V_86 ) ,
V_81 ) ;
if ( V_75 -> V_84 == NULL ) {
F_28 ( V_4 -> V_85 -> V_31 , L_10 ) ;
V_11 = - V_83 ;
goto V_87;
}
memcpy ( V_75 -> V_84 , & V_86 , sizeof( V_86 ) ) ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> V_68 )
V_75 -> V_84 -> V_68 = F_21 ;
F_29 ( & V_75 -> V_88 ) ;
V_11 = F_30 ( V_4 -> V_85 -> V_89 , V_73 , V_22 , V_75 ) ;
if ( V_11 < 0 ) {
F_3 ( L_11 ,
V_27 -> V_17 ) ;
goto V_87;
}
F_31 ( & V_4 -> V_30 , F_5 ) ;
V_4 -> V_75 = V_75 ;
V_75 -> V_5 = V_4 ;
F_32 ( V_90 L_12 , V_10 -> V_17 ,
V_9 -> V_17 ) ;
return V_11 ;
V_87:
F_33 ( V_75 ) ;
return V_11 ;
}
