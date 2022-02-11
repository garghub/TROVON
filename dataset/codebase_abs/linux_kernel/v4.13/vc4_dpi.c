static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_4 ) ;
}
int F_3 ( struct V_5 * V_6 , void * V_7 )
{
struct V_8 * V_9 = (struct V_8 * ) V_6 -> V_10 ;
struct V_11 * V_12 = V_9 -> V_13 -> V_12 ;
struct V_14 * V_15 = F_4 ( V_12 ) ;
struct V_16 * V_17 = V_15 -> V_17 ;
int V_18 ;
if ( ! V_17 )
return 0 ;
for ( V_18 = 0 ; V_18 < F_5 ( V_19 ) ; V_18 ++ ) {
F_6 ( V_6 , L_1 ,
V_19 [ V_18 ] . V_20 , V_19 [ V_18 ] . V_21 ,
F_7 ( V_19 [ V_18 ] . V_21 ) ) ;
}
return 0 ;
}
static void F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_22 = F_1 ( V_3 ) ;
struct V_16 * V_17 = V_22 -> V_17 ;
F_9 ( V_17 -> V_23 ) ;
}
static void F_10 ( struct V_2 * V_3 )
{
struct V_24 * V_25 = & V_3 -> V_26 -> V_25 ;
struct V_1 * V_22 = F_1 ( V_3 ) ;
struct V_16 * V_17 = V_22 -> V_17 ;
T_1 V_27 = V_28 | V_29 ;
int V_30 ;
if ( V_17 -> V_31 -> V_32 . V_33 ) {
T_1 V_34 = V_17 -> V_31 -> V_32 . V_35 [ 0 ] ;
switch ( V_34 ) {
case V_36 :
V_27 |= F_11 ( V_37 ,
V_38 ) ;
break;
case V_39 :
V_27 |= F_11 ( V_37 ,
V_38 ) ;
V_27 |= F_11 ( V_40 , V_41 ) ;
break;
case V_42 :
V_27 |= F_11 ( V_43 ,
V_38 ) ;
break;
case V_44 :
V_27 |= F_11 ( V_45 ,
V_38 ) ;
break;
case V_46 :
V_27 |= F_11 ( V_47 ,
V_38 ) ;
break;
default:
F_12 ( L_2 , V_34 ) ;
break;
}
}
if ( V_25 -> V_48 & V_49 )
V_27 |= V_50 ;
else if ( ! ( V_25 -> V_48 & V_51 ) )
V_27 |= V_52 ;
if ( V_25 -> V_48 & V_53 )
V_27 |= V_54 ;
else if ( ! ( V_25 -> V_48 & V_55 ) )
V_27 |= V_56 ;
F_13 ( V_57 , V_27 ) ;
V_30 = F_14 ( V_17 -> V_23 , V_25 -> clock * 1000 ) ;
if ( V_30 )
F_12 ( L_3 , V_30 ) ;
V_30 = F_15 ( V_17 -> V_23 ) ;
if ( V_30 )
F_12 ( L_3 , V_30 ) ;
}
static bool F_16 ( struct V_2 * V_3 ,
const struct V_24 * V_25 ,
struct V_24 * V_58 )
{
if ( V_58 -> V_48 & V_59 )
return false ;
return true ;
}
static int F_17 ( struct V_16 * V_17 )
{
struct V_60 * V_12 = & V_17 -> V_61 -> V_12 ;
struct V_62 * V_63 ;
int V_30 ;
V_30 = F_18 ( V_12 -> V_64 , 0 , 0 ,
& V_63 , & V_17 -> V_65 ) ;
if ( V_30 ) {
if ( V_30 == - V_66 )
return 0 ;
else
return V_30 ;
}
if ( V_63 ) {
V_17 -> V_65 = F_19 ( V_63 ,
V_67 ) ;
V_17 -> V_68 = true ;
}
return F_20 ( V_17 -> V_3 , V_17 -> V_65 , NULL ) ;
}
static int F_21 ( struct V_60 * V_12 , struct V_60 * V_69 , void * V_70 )
{
struct V_71 * V_61 = F_22 ( V_12 ) ;
struct V_11 * V_72 = F_23 ( V_69 ) ;
struct V_14 * V_15 = F_4 ( V_72 ) ;
struct V_16 * V_17 ;
struct V_1 * V_1 ;
int V_30 ;
V_17 = F_24 ( V_12 , sizeof( * V_17 ) , V_73 ) ;
if ( ! V_17 )
return - V_74 ;
V_1 = F_24 ( V_12 , sizeof( * V_1 ) ,
V_73 ) ;
if ( ! V_1 )
return - V_74 ;
V_1 -> V_4 . type = V_75 ;
V_1 -> V_17 = V_17 ;
V_17 -> V_3 = & V_1 -> V_4 . V_4 ;
V_17 -> V_61 = V_61 ;
V_17 -> V_76 = F_25 ( V_61 , 0 ) ;
if ( F_26 ( V_17 -> V_76 ) )
return F_27 ( V_17 -> V_76 ) ;
if ( F_7 ( V_77 ) != V_78 ) {
F_28 ( V_12 , L_4 ,
F_7 ( V_77 ) , V_78 ) ;
return - V_66 ;
}
V_17 -> V_79 = F_29 ( V_12 , L_5 ) ;
if ( F_26 ( V_17 -> V_79 ) ) {
V_30 = F_27 ( V_17 -> V_79 ) ;
if ( V_30 != - V_80 )
F_12 ( L_6 , V_30 ) ;
return V_30 ;
}
V_17 -> V_23 = F_29 ( V_12 , L_7 ) ;
if ( F_26 ( V_17 -> V_23 ) ) {
V_30 = F_27 ( V_17 -> V_23 ) ;
if ( V_30 != - V_80 )
F_12 ( L_8 , V_30 ) ;
return V_30 ;
}
V_30 = F_15 ( V_17 -> V_79 ) ;
if ( V_30 )
F_12 ( L_9 , V_30 ) ;
F_30 ( V_72 , V_17 -> V_3 , & V_81 ,
V_82 , NULL ) ;
F_31 ( V_17 -> V_3 , & V_83 ) ;
V_30 = F_17 ( V_17 ) ;
if ( V_30 )
goto V_84;
F_32 ( V_12 , V_17 ) ;
V_15 -> V_17 = V_17 ;
return 0 ;
V_84:
F_33 ( V_17 -> V_3 ) ;
F_9 ( V_17 -> V_79 ) ;
return V_30 ;
}
static void F_34 ( struct V_60 * V_12 , struct V_60 * V_69 ,
void * V_70 )
{
struct V_11 * V_72 = F_23 ( V_69 ) ;
struct V_14 * V_15 = F_4 ( V_72 ) ;
struct V_16 * V_17 = F_23 ( V_12 ) ;
if ( V_17 -> V_68 )
F_35 ( V_17 -> V_65 ) ;
F_33 ( V_17 -> V_3 ) ;
F_9 ( V_17 -> V_79 ) ;
V_15 -> V_17 = NULL ;
}
static int F_36 ( struct V_71 * V_61 )
{
return F_37 ( & V_61 -> V_12 , & V_85 ) ;
}
static int F_38 ( struct V_71 * V_61 )
{
F_39 ( & V_61 -> V_12 , & V_85 ) ;
return 0 ;
}
