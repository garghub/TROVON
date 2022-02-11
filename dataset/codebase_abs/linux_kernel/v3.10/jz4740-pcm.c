static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned long V_5 ;
if ( V_2 -> V_6 == V_2 -> V_7 )
V_2 -> V_6 = V_2 -> V_8 ;
if ( V_2 -> V_6 + V_2 -> V_9 > V_2 -> V_7 )
V_5 = V_2 -> V_7 - V_2 -> V_6 ;
else
V_5 = V_2 -> V_9 ;
F_2 ( V_2 -> V_10 ) ;
if ( V_4 -> V_11 == V_12 ) {
F_3 ( V_2 -> V_10 , V_2 -> V_6 ) ;
F_4 ( V_2 -> V_10 , V_2 -> V_13 ) ;
} else {
F_3 ( V_2 -> V_10 , V_2 -> V_13 ) ;
F_4 ( V_2 -> V_10 , V_2 -> V_6 ) ;
}
F_5 ( V_2 -> V_10 , V_5 ) ;
V_2 -> V_6 += V_5 ;
F_6 ( V_2 -> V_10 ) ;
}
static void F_7 ( struct V_14 * V_10 , int V_15 ,
void * V_16 )
{
struct V_3 * V_4 = V_16 ;
struct V_17 * V_18 = V_4 -> V_18 ;
struct V_1 * V_2 = V_18 -> V_19 ;
F_8 ( V_4 ) ;
F_1 ( V_2 , V_4 ) ;
}
static int F_9 ( struct V_3 * V_4 ,
struct V_20 * V_21 )
{
struct V_17 * V_18 = V_4 -> V_18 ;
struct V_1 * V_2 = V_18 -> V_19 ;
struct V_22 * V_23 = V_4 -> V_19 ;
struct V_24 * V_25 ;
V_25 = F_10 ( V_23 -> V_26 , V_4 ) ;
if ( ! V_25 )
return 0 ;
if ( ! V_2 -> V_10 ) {
if ( V_4 -> V_11 == V_27 )
V_2 -> V_10 = F_11 ( V_4 , L_1 ) ;
else
V_2 -> V_10 = F_11 ( V_4 , L_2 ) ;
}
if ( ! V_2 -> V_10 )
return - V_28 ;
F_12 ( V_2 -> V_10 , & V_25 -> V_29 ) ;
V_2 -> V_13 = V_25 -> V_13 ;
F_13 ( V_2 -> V_10 , F_7 ) ;
F_14 ( V_4 , & V_4 -> V_30 ) ;
V_18 -> V_31 = F_15 ( V_21 ) ;
V_2 -> V_9 = F_16 ( V_21 ) ;
V_2 -> V_8 = V_18 -> V_32 ;
V_2 -> V_6 = V_2 -> V_8 ;
V_2 -> V_7 = V_2 -> V_8 + V_18 -> V_31 ;
return 0 ;
}
static int F_17 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_18 -> V_19 ;
F_14 ( V_4 , NULL ) ;
if ( V_2 -> V_10 ) {
F_18 ( V_2 -> V_10 ) ;
V_2 -> V_10 = NULL ;
}
return 0 ;
}
static int F_19 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_18 -> V_19 ;
if ( ! V_2 -> V_10 )
return - V_28 ;
V_2 -> V_6 = V_2 -> V_8 ;
return 0 ;
}
static int F_20 ( struct V_3 * V_4 , int V_33 )
{
struct V_17 * V_18 = V_4 -> V_18 ;
struct V_1 * V_2 = V_18 -> V_19 ;
switch ( V_33 ) {
case V_34 :
case V_35 :
case V_36 :
F_1 ( V_2 , V_4 ) ;
break;
case V_37 :
case V_38 :
case V_39 :
F_2 ( V_2 -> V_10 ) ;
break;
default:
break;
}
return 0 ;
}
static T_1 F_21 ( struct V_3 * V_4 )
{
struct V_17 * V_18 = V_4 -> V_18 ;
struct V_1 * V_2 = V_18 -> V_19 ;
unsigned long V_40 ;
T_1 V_41 ;
struct V_14 * V_10 = V_2 -> V_10 ;
V_40 = V_2 -> V_6 - V_2 -> V_8 ;
V_40 -= F_22 ( V_10 ) ;
V_41 = F_23 ( V_18 , V_40 ) ;
if ( V_41 >= V_18 -> V_42 )
V_41 = 0 ;
return V_41 ;
}
static int F_24 ( struct V_3 * V_4 )
{
struct V_17 * V_18 = V_4 -> V_18 ;
struct V_1 * V_2 ;
V_2 = F_25 ( sizeof( * V_2 ) , V_43 ) ;
if ( V_2 == NULL )
return - V_44 ;
F_26 ( V_4 , & V_45 ) ;
V_18 -> V_19 = V_2 ;
return 0 ;
}
static int F_27 ( struct V_3 * V_4 )
{
struct V_17 * V_18 = V_4 -> V_18 ;
struct V_1 * V_2 = V_18 -> V_19 ;
F_28 ( V_2 ) ;
return 0 ;
}
static int F_29 ( struct V_3 * V_4 ,
struct V_46 * V_47 )
{
return F_30 ( V_47 , V_47 -> V_48 ,
V_4 -> V_30 . V_49 >> V_50 ,
V_47 -> V_51 - V_47 -> V_48 , V_47 -> V_52 ) ;
}
static int F_31 ( struct V_53 * V_54 , int V_11 )
{
struct V_3 * V_4 = V_54 -> V_55 [ V_11 ] . V_4 ;
struct V_56 * V_57 = & V_4 -> V_30 ;
T_2 V_58 = V_45 . V_59 ;
V_57 -> V_60 . type = V_61 ;
V_57 -> V_60 . V_60 = V_54 -> V_62 -> V_60 ;
V_57 -> V_19 = NULL ;
V_57 -> V_63 = F_32 ( V_54 -> V_62 -> V_60 , V_58 ,
& V_57 -> V_49 , V_43 ) ;
if ( ! V_57 -> V_63 )
return - V_44 ;
V_57 -> V_64 = V_58 ;
return 0 ;
}
static void F_33 ( struct V_53 * V_54 )
{
struct V_3 * V_4 ;
struct V_56 * V_57 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_65 ; ++ V_11 ) {
V_4 = V_54 -> V_55 [ V_11 ] . V_4 ;
if ( ! V_4 )
continue;
V_57 = & V_4 -> V_30 ;
if ( ! V_57 -> V_63 )
continue;
F_34 ( V_54 -> V_62 -> V_60 , V_57 -> V_64 , V_57 -> V_63 ,
V_57 -> V_49 ) ;
V_57 -> V_63 = NULL ;
}
}
static int F_35 ( struct V_22 * V_23 )
{
struct V_66 * V_62 = V_23 -> V_62 -> V_66 ;
struct V_53 * V_54 = V_23 -> V_54 ;
int V_67 = 0 ;
if ( ! V_62 -> V_60 -> V_68 )
V_62 -> V_60 -> V_68 = & V_69 ;
if ( ! V_62 -> V_60 -> V_70 )
V_62 -> V_60 -> V_70 = F_36 ( 32 ) ;
if ( V_54 -> V_55 [ V_12 ] . V_4 ) {
V_67 = F_31 ( V_54 ,
V_12 ) ;
if ( V_67 )
goto V_15;
}
if ( V_54 -> V_55 [ V_27 ] . V_4 ) {
V_67 = F_31 ( V_54 ,
V_27 ) ;
if ( V_67 )
goto V_15;
}
V_15:
return V_67 ;
}
static int F_37 ( struct V_71 * V_72 )
{
return F_38 ( & V_72 -> V_60 , & V_73 ) ;
}
static int F_39 ( struct V_71 * V_72 )
{
F_40 ( & V_72 -> V_60 ) ;
return 0 ;
}
