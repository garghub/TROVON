static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 , V_2 -> V_4 ,
V_5 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_3 ( V_2 ) ;
V_2 -> V_6 = V_2 -> V_7 = V_2 -> V_8 ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 1 ;
}
static void F_6 ( struct V_1 * V_2 )
{
V_2 -> V_4 = 1000000000 / V_2 -> V_11 ;
}
static int F_7 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_8 ( V_13 ) ;
struct V_14 * V_15 = V_13 -> V_15 ;
V_15 -> V_16 = V_17 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_6 = V_2 -> V_7 = V_2 -> V_8 ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 1 ;
V_2 -> V_18 -> V_19 ( V_2 -> V_18 ) ;
return 0 ;
}
static int F_9 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_8 ( V_13 ) ;
V_2 -> V_13 = NULL ;
F_3 ( V_2 ) ;
V_2 -> V_18 -> V_20 ( V_2 -> V_18 ) ;
return 0 ;
}
static int F_10 ( struct V_12 * V_13 ,
struct V_21 * V_22 )
{
return F_11 ( V_13 ,
F_12 ( V_22 ) ) ;
}
static int F_13 ( struct V_12 * V_13 )
{
return F_14 ( V_13 ) ;
}
static int F_15 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_8 ( V_13 ) ;
struct V_14 * V_15 = V_2 -> V_13 -> V_15 ;
V_2 -> V_23 = V_15 -> V_23 ;
memset ( V_2 -> V_8 , 0 , V_2 -> V_18 -> V_23 ) ;
return 0 ;
}
static int F_16 ( struct V_12 * V_13 , int V_24 )
{
struct V_1 * V_2 = F_8 ( V_13 ) ;
switch ( V_24 ) {
case V_25 :
F_1 ( V_2 ) ;
break;
case V_26 :
V_2 -> V_6 = V_2 -> V_7 = V_2 -> V_8 ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 1 ;
F_3 ( V_2 ) ;
break;
default:
return - V_27 ;
}
return 0 ;
}
static int F_17 ( struct V_12 * V_13 , int V_28 ,
T_1 V_29 , void T_2 * V_30 , T_1 V_31 )
{
struct V_1 * V_2 = F_8 ( V_13 ) ;
struct V_14 * V_15 = V_13 -> V_15 ;
T_3 V_32 = F_18 ( V_15 , V_31 ) ;
T_3 V_33 = F_18 ( V_15 , V_29 ) ;
if ( V_31 < 0 )
return - V_27 ;
if ( ! V_31 )
return 0 ;
F_19 ( V_2 -> V_8 + V_33 , V_30 , V_32 ) ;
V_2 -> V_7 = V_2 -> V_8 + V_33 + V_32 ;
if ( V_2 -> V_10 ) {
V_2 -> V_10 = 0 ;
F_1 ( V_2 ) ;
}
return 0 ;
}
static int F_20 ( struct V_12 * V_13 ,
int V_28 , T_1 V_29 ,
T_1 V_31 )
{
struct V_1 * V_2 = F_8 ( V_13 ) ;
struct V_14 * V_15 = V_13 -> V_15 ;
T_3 V_32 = F_18 ( V_15 , V_31 ) ;
T_3 V_33 = F_18 ( V_15 , V_29 ) ;
if ( V_31 < 0 )
return - V_27 ;
if ( ! V_31 )
return 0 ;
F_21 ( V_2 -> V_8 + V_33 , 0 , V_32 ) ;
V_2 -> V_7 = V_2 -> V_8 + V_33 + V_32 ;
if ( V_2 -> V_10 ) {
V_2 -> V_10 = 0 ;
F_1 ( V_2 ) ;
}
return 0 ;
}
static
T_1 F_22 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_8 ( V_13 ) ;
int V_34 = V_2 -> V_6 - V_2 -> V_8 ;
return V_34 ;
}
static int F_23 ( struct V_1 * V_2 , int V_35 )
{
int V_36 ;
struct V_37 * V_38 ;
V_36 = F_24 ( V_2 -> V_39 , L_1 , V_35 , 1 , 0 , & V_38 ) ;
if ( V_36 < 0 )
return V_36 ;
V_38 -> V_40 = V_2 ;
strcpy ( V_38 -> V_41 , L_1 ) ;
F_25 ( V_38 , V_42 , & V_43 ) ;
F_26 ( V_38 , V_44 ,
F_27 ( V_45 ) ,
48 * 1024 ,
48 * 1024 ) ;
return 0 ;
}
static int F_28 ( struct V_46 * V_47 )
{
F_29 ( F_30 ( V_47 ) ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
F_32 ( V_2 -> V_8 ) ;
F_32 ( V_2 ) ;
return 0 ;
}
static int F_33 ( struct V_48 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_49 ;
return F_31 ( V_2 ) ;
}
static enum V_50 F_34 ( struct V_3 * V_51 )
{
struct V_1 * V_2 = F_35 ( V_51 , struct V_1 ,
V_3 ) ;
struct V_14 * V_15 = V_2 -> V_13 -> V_15 ;
T_3 V_52 = F_18 ( V_15 , V_15 -> V_53 ) ;
if ( ! V_2 -> V_10 ) {
F_36 ( * V_2 -> V_6 , V_2 -> V_18 -> V_28 ) ;
V_2 -> V_6 ++ ;
V_2 -> V_9 ++ ;
if ( V_2 -> V_9 >= V_52 ) {
V_2 -> V_9 -= V_52 ;
F_37 ( V_2 -> V_13 ) ;
}
if ( V_2 -> V_6 == ( V_2 -> V_8 +
V_2 -> V_23 - 1 ) )
V_2 -> V_6 = V_2 -> V_8 ;
if ( V_2 -> V_6 == V_2 -> V_7 )
V_2 -> V_10 = 1 ;
}
if ( ! V_2 -> V_10 )
F_2 ( & V_2 -> V_3 , V_2 -> V_4 ,
V_5 ) ;
return V_54 ;
}
static int F_38 ( struct V_55 * V_39 ,
struct V_46 * V_47 ,
struct V_1 * * V_56 )
{
struct V_1 * V_2 ;
int V_36 ;
static struct V_57 V_58 = {
. V_59 = F_33 ,
} ;
* V_56 = NULL ;
V_2 = F_39 ( sizeof( * V_2 ) , V_45 ) ;
if ( V_2 == NULL )
return - V_60 ;
V_2 -> V_39 = V_39 ;
F_40 ( & V_2 -> V_3 , V_61 , V_5 ) ;
V_2 -> V_3 . V_62 = F_34 ;
F_5 ( V_2 ) ;
V_2 -> V_11 = 8000 ;
F_6 ( V_2 ) ;
V_2 -> V_18 = V_47 -> V_63 . V_64 ;
V_2 -> V_8 = F_41 ( V_2 -> V_18 -> V_23 , V_45 ) ;
if ( V_2 -> V_8 == NULL ) {
F_32 ( V_2 ) ;
return - V_60 ;
}
V_36 = F_42 ( V_39 , V_65 , V_2 , & V_58 ) ;
if ( V_36 < 0 ) {
F_31 ( V_2 ) ;
return V_36 ;
}
* V_56 = V_2 ;
return 0 ;
}
static int F_43 ( struct V_46 * V_47 )
{
struct V_1 * V_2 ;
struct V_55 * V_39 ;
int V_36 ;
V_36 = F_44 ( & V_47 -> V_63 , V_66 , V_67 , V_68 , 0 , & V_39 ) ;
if ( V_36 < 0 ) {
F_45 ( V_69 L_2 ) ;
return V_36 ;
}
V_36 = F_38 ( V_39 , V_47 , & V_2 ) ;
if ( V_36 < 0 )
goto V_70;
V_36 = F_23 ( V_2 , 0 ) ;
if ( V_36 < 0 )
goto V_70;
strcpy ( V_39 -> V_71 , L_3 ) ;
strcpy ( V_39 -> V_72 , L_4 ) ;
F_46 ( V_73 L_5 , V_39 -> V_74 , V_39 -> V_72 ) ;
V_36 = F_47 ( V_39 ) ;
if ( V_36 < 0 )
goto V_70;
F_45 ( L_6 ) ;
F_48 ( V_47 , V_39 ) ;
return 0 ;
V_70:
F_29 ( V_39 ) ;
return V_36 ;
}
