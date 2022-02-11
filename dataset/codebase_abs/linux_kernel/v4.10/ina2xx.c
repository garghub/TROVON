static int F_1 ( T_1 V_1 )
{
int V_2 = V_3 [ F_2 ( V_1 ) ] ;
return F_3 ( V_2 * V_4 , 1000 ) ;
}
static T_1 F_4 ( int V_5 )
{
int V_2 , V_6 ;
V_2 = F_3 ( V_5 * 1000 ,
V_4 ) ;
V_6 = F_5 ( V_2 , V_3 ,
F_6 ( V_3 ) ) ;
return F_7 ( V_6 ) ;
}
static int F_8 ( struct V_7 * V_8 )
{
T_1 V_9 = F_3 ( V_8 -> V_1 -> V_10 ,
V_8 -> V_11 ) ;
return F_9 ( V_8 -> V_12 , V_13 , V_9 ) ;
}
static int F_10 ( struct V_7 * V_8 )
{
int V_14 = F_9 ( V_8 -> V_12 , V_15 ,
V_8 -> V_1 -> V_16 ) ;
if ( V_14 < 0 )
return V_14 ;
return F_8 ( V_8 ) ;
}
static int F_11 ( struct V_17 * V_18 , int V_19 , unsigned int * V_20 )
{
struct V_7 * V_8 = F_12 ( V_18 ) ;
int V_14 , V_21 ;
F_13 ( V_18 , L_1 , V_19 ) ;
for ( V_21 = 5 ; V_21 ; V_21 -- ) {
V_14 = F_14 ( V_8 -> V_12 , V_19 , V_20 ) ;
if ( V_14 < 0 )
return V_14 ;
F_13 ( V_18 , L_2 , V_19 , * V_20 ) ;
if ( * V_20 == 0 ) {
unsigned int V_22 ;
V_14 = F_14 ( V_8 -> V_12 , V_13 ,
& V_22 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_22 == 0 ) {
F_15 ( V_18 , L_3 ) ;
V_14 = F_10 ( V_8 ) ;
if ( V_14 < 0 )
return V_14 ;
F_16 ( V_23 ) ;
continue;
}
}
return 0 ;
}
F_17 ( V_18 , L_4 ) ;
return - V_24 ;
}
static int F_18 ( struct V_7 * V_8 , T_2 V_19 ,
unsigned int V_20 )
{
int V_9 ;
switch ( V_19 ) {
case V_25 :
V_9 = F_3 ( ( V_26 ) V_20 , V_8 -> V_1 -> V_27 ) ;
break;
case V_28 :
V_9 = ( V_20 >> V_8 -> V_1 -> V_29 )
* V_8 -> V_1 -> V_30 ;
V_9 = F_3 ( V_9 , 1000 ) ;
break;
case V_31 :
V_9 = V_20 * V_8 -> V_1 -> V_32 ;
break;
case V_33 :
V_9 = ( V_26 ) V_20 ;
break;
case V_13 :
V_9 = F_3 ( V_8 -> V_1 -> V_10 ,
V_20 ) ;
break;
default:
F_19 ( 1 ) ;
V_9 = 0 ;
break;
}
return V_9 ;
}
static T_3 F_20 ( struct V_17 * V_18 ,
struct V_34 * V_35 , char * V_36 )
{
struct V_37 * V_38 = F_21 ( V_35 ) ;
struct V_7 * V_8 = F_12 ( V_18 ) ;
unsigned int V_20 ;
int V_39 = F_11 ( V_18 , V_38 -> V_40 , & V_20 ) ;
if ( V_39 < 0 )
return V_39 ;
return snprintf ( V_36 , V_41 , L_5 ,
F_18 ( V_8 , V_38 -> V_40 , V_20 ) ) ;
}
static T_3 F_22 ( struct V_17 * V_18 ,
struct V_34 * V_35 ,
const char * V_36 , T_4 V_42 )
{
unsigned long V_9 ;
int V_43 ;
struct V_7 * V_8 = F_12 ( V_18 ) ;
V_43 = F_23 ( V_36 , 10 , & V_9 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_9 == 0 ||
V_9 > V_8 -> V_1 -> V_10 )
return - V_44 ;
F_24 ( & V_8 -> V_45 ) ;
V_8 -> V_11 = V_9 ;
V_43 = F_8 ( V_8 ) ;
F_25 ( & V_8 -> V_45 ) ;
if ( V_43 < 0 )
return V_43 ;
return V_42 ;
}
static T_3 F_26 ( struct V_17 * V_18 ,
struct V_34 * V_35 ,
const char * V_36 , T_4 V_42 )
{
struct V_7 * V_8 = F_12 ( V_18 ) ;
unsigned long V_9 ;
int V_43 ;
V_43 = F_23 ( V_36 , 10 , & V_9 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_9 > V_46 || V_9 == 0 )
return - V_44 ;
V_43 = F_27 ( V_8 -> V_12 , V_15 ,
V_47 ,
F_4 ( V_9 ) ) ;
if ( V_43 < 0 )
return V_43 ;
return V_42 ;
}
static T_3 F_28 ( struct V_17 * V_18 ,
struct V_34 * V_35 , char * V_36 )
{
struct V_7 * V_8 = F_12 ( V_18 ) ;
int V_43 ;
unsigned int V_20 ;
V_43 = F_14 ( V_8 -> V_12 , V_15 , & V_20 ) ;
if ( V_43 )
return V_43 ;
return snprintf ( V_36 , V_41 , L_5 , F_1 ( V_20 ) ) ;
}
static int F_29 ( struct V_48 * V_49 ,
const struct V_50 * V_51 )
{
struct V_17 * V_18 = & V_49 -> V_18 ;
struct V_7 * V_8 ;
struct V_17 * V_52 ;
T_5 V_9 ;
int V_14 , V_53 = 0 ;
V_8 = F_30 ( V_18 , sizeof( * V_8 ) , V_54 ) ;
if ( ! V_8 )
return - V_55 ;
V_8 -> V_1 = & V_56 [ V_51 -> V_57 ] ;
if ( F_31 ( V_18 -> V_58 , L_6 , & V_9 ) < 0 ) {
struct V_59 * V_60 = F_32 ( V_18 ) ;
if ( V_60 )
V_9 = V_60 -> V_61 ;
else
V_9 = V_62 ;
}
if ( V_9 <= 0 || V_9 > V_8 -> V_1 -> V_10 )
return - V_24 ;
V_8 -> V_11 = V_9 ;
V_63 . V_64 = V_8 -> V_1 -> V_65 ;
V_8 -> V_12 = F_33 ( V_49 , & V_63 ) ;
if ( F_34 ( V_8 -> V_12 ) ) {
F_17 ( V_18 , L_7 ) ;
return F_35 ( V_8 -> V_12 ) ;
}
V_14 = F_10 ( V_8 ) ;
if ( V_14 < 0 ) {
F_17 ( V_18 , L_8 , V_14 ) ;
return - V_24 ;
}
F_36 ( & V_8 -> V_45 ) ;
V_8 -> V_66 [ V_53 ++ ] = & V_67 ;
if ( V_51 -> V_57 == V_68 )
V_8 -> V_66 [ V_53 ++ ] = & V_69 ;
V_52 = F_37 ( V_18 , V_49 -> V_70 ,
V_8 , V_8 -> V_66 ) ;
if ( F_34 ( V_52 ) )
return F_35 ( V_52 ) ;
F_38 ( V_18 , L_9 ,
V_51 -> V_70 , V_8 -> V_11 ) ;
return 0 ;
}
