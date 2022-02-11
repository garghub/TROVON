static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 ;
V_3 = F_2 ( V_2 -> V_5 , V_6 , & V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_4 ) {
if ( V_4 & V_7 )
F_3 ( V_2 -> V_8 , L_1 ) ;
if ( V_4 & V_9 )
F_3 ( V_2 -> V_8 , L_2 ) ;
if ( V_4 & V_10 )
F_3 ( V_2 -> V_8 , L_3 ) ;
if ( V_4 & V_11 )
F_3 ( V_2 -> V_8 , L_4 ) ;
if ( V_4 & V_12 )
F_3 ( V_2 -> V_8 , L_5 ) ;
if ( V_4 & V_13 )
F_3 ( V_2 -> V_8 , L_6 ) ;
if ( V_4 & V_14 )
F_3 ( V_2 -> V_8 , L_7 ) ;
if ( V_4 & V_15 )
F_3 ( V_2 -> V_8 , L_8 ) ;
V_3 = F_4 ( V_2 -> V_5 , V_6 ,
V_4 ) ;
}
return V_3 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_16 , V_17 , V_18 , V_19 ;
char * type ;
int V_3 ;
V_3 = F_2 ( V_2 -> V_5 , V_20 , & V_16 ) ;
if ( V_3 < 0 ) {
F_6 ( V_2 -> V_8 , L_9 ) ;
return - V_21 ;
}
if ( V_16 != V_22 ) {
F_6 ( V_2 -> V_8 , L_10 , V_16 ) ;
return - V_23 ;
}
V_3 = F_2 ( V_2 -> V_5 , V_24 , & V_17 ) ;
if ( V_3 < 0 ) {
F_6 ( V_2 -> V_8 , L_11 ) ;
return - V_21 ;
}
V_19 = ( V_17 & V_25 ) >> V_26 ;
switch ( V_19 ) {
case V_27 :
type = L_12 ;
break;
case V_28 :
type = L_13 ;
break;
default:
type = L_14 ;
break;
}
F_7 ( V_2 -> V_8 ,
L_15 ,
V_16 , V_17 , type ) ;
V_18 = ( V_17 & V_29 ) >> V_30 ;
if ( V_18 < V_31 ) {
F_6 ( V_2 -> V_8 ,
L_16 , V_18 ) ;
return - V_23 ;
}
return V_3 ;
}
static int F_8 ( struct V_32 * V_33 ,
const struct V_34 * V_35 )
{
struct V_1 * V_2 ;
const struct V_36 * V_37 ;
unsigned int V_38 ;
const struct V_39 * V_40 ;
const struct V_41 * V_42 ;
const struct V_43 * V_44 ;
int V_45 ;
int V_3 ;
V_2 = F_9 ( & V_33 -> V_8 , sizeof( * V_2 ) , V_46 ) ;
if ( ! V_2 )
return - V_47 ;
if ( V_33 -> V_8 . V_48 ) {
V_37 = F_10 ( V_49 , V_33 -> V_8 . V_48 ) ;
if ( ! V_37 )
return - V_50 ;
V_2 -> V_51 = ( V_52 ) V_37 -> V_53 ;
} else {
V_2 -> V_51 = V_35 -> V_54 ;
}
F_11 ( V_33 , V_2 ) ;
V_2 -> V_8 = & V_33 -> V_8 ;
if ( ! V_33 -> V_55 ) {
F_6 ( V_2 -> V_8 , L_17 ) ;
return - V_50 ;
}
switch ( V_2 -> V_51 ) {
case V_56 :
V_40 = V_57 ;
V_45 = F_12 ( V_57 ) ;
V_42 = & V_58 ;
V_44 = & V_59 ;
break;
case V_60 :
V_40 = V_61 ;
V_45 = F_12 ( V_61 ) ;
V_42 = & V_62 ;
V_44 = & V_63 ;
break;
default:
F_6 ( V_2 -> V_8 , L_18 ) ;
return - V_23 ;
}
V_2 -> V_5 = F_13 ( V_33 , V_44 ) ;
if ( F_14 ( V_2 -> V_5 ) ) {
V_3 = F_15 ( V_2 -> V_5 ) ;
F_6 ( V_2 -> V_8 , L_19 ,
V_3 ) ;
return V_3 ;
}
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 )
F_16 ( V_2 -> V_8 , L_20 ) ;
V_3 = F_5 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_17 ( V_2 -> V_5 , V_33 -> V_55 ,
V_64 | V_65 | V_66 ,
- 1 , V_42 ,
& V_2 -> V_67 ) ;
if ( V_3 ) {
F_6 ( V_2 -> V_8 , L_21 ,
V_33 -> V_55 , V_3 ) ;
return V_3 ;
}
V_38 = F_18 ( V_2 -> V_67 ) ;
V_3 = F_19 ( V_2 -> V_8 , V_68 , V_40 ,
V_45 , NULL , V_38 ,
NULL ) ;
if ( V_3 ) {
F_6 ( V_2 -> V_8 , L_22 ) ;
F_20 ( V_33 -> V_55 , V_2 -> V_67 ) ;
return V_3 ;
}
return V_3 ;
}
static int F_21 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_22 ( V_33 ) ;
F_23 ( V_2 -> V_8 ) ;
F_20 ( V_33 -> V_55 , V_2 -> V_67 ) ;
return 0 ;
}
