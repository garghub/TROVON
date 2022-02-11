static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 , V_6 ;
int V_7 ;
F_2 ( & V_2 -> V_8 ) ;
V_5 = F_3 ( V_2 -> V_4 ,
V_9 , V_10 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_4 -> V_11 , L_1 , V_5 ) ;
F_5 ( & V_2 -> V_8 ) ;
return V_5 ;
}
V_7 = 1 + V_2 -> V_12 / 172 ;
F_6 ( V_7 ) ;
for ( V_6 = 0 ; V_6 < 4 ; V_6 ++ ) {
V_5 = F_7 ( V_2 -> V_4 ,
V_13 ) ;
if ( V_5 < 255 && V_5 > 0 )
break;
F_6 ( 5 ) ;
}
if ( V_5 >= 255 || V_5 <= 0 ) {
F_4 ( & V_4 -> V_11 , L_2 ) ;
F_5 ( & V_2 -> V_8 ) ;
return - V_14 ;
}
V_5 = F_8 ( V_2 -> V_4 ,
V_15 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_4 -> V_11 , L_3 , V_5 ) ;
F_5 ( & V_2 -> V_8 ) ;
return V_5 ;
}
F_5 ( & V_2 -> V_8 ) ;
return V_5 ;
}
static T_1 F_9 ( int V_16 , void * V_17 )
{
struct V_18 * V_19 = V_17 ;
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_1 * V_2 = F_10 ( V_21 ) ;
T_2 V_22 ;
V_22 = F_1 ( V_2 ) ;
if ( V_22 < 0 )
goto V_23;
F_2 ( & V_2 -> V_8 ) ;
V_2 -> V_24 [ 0 ] = V_22 ;
F_11 ( V_21 ,
V_2 -> V_24 , V_19 -> V_25 ) ;
F_5 ( & V_2 -> V_8 ) ;
V_23:
F_12 ( V_21 -> V_26 ) ;
return V_27 ;
}
static int F_13 ( struct V_20 * V_21 ,
struct V_28 const * V_29 , int * V_30 ,
int * V_31 , long V_32 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
int V_5 ;
if ( V_29 -> type != V_33 )
return - V_34 ;
switch ( V_32 ) {
case V_35 :
V_5 = F_1 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
* V_30 = V_5 ;
return V_36 ;
case V_37 :
* V_30 = 0 ;
* V_31 = 10000 ;
return V_38 ;
default:
return - V_34 ;
}
}
static T_3 F_14 ( struct V_39 * V_11 ,
struct V_40 * V_41 , char * V_42 )
{
return sprintf ( V_42 , L_4 ) ;
}
static T_3 F_15 ( struct V_39 * V_11 ,
struct V_40 * V_41 , char * V_42 )
{
struct V_20 * V_21 = F_16 ( V_11 ) ;
struct V_1 * V_2 = F_10 ( V_21 ) ;
return sprintf ( V_42 , L_5 , V_2 -> V_12 / 1000 ,
V_2 -> V_12 % 1000 ) ;
}
static T_3 F_17 ( struct V_1 * V_2 , unsigned int V_30 )
{
int V_5 ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_43 ;
T_4 V_44 ;
V_5 = V_30 / 43 - 1 ;
V_43 = V_30 % 43 ;
if ( V_43 || ( V_5 < 0 ) || ( V_5 > 255 ) )
return - V_34 ;
V_44 = V_5 ;
F_2 ( & V_2 -> V_8 ) ;
V_5 = F_3 ( V_4 , V_45 , V_44 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_4 -> V_11 , L_6 , V_5 ) ;
F_5 ( & V_2 -> V_8 ) ;
return V_5 ;
}
V_2 -> V_12 = V_30 ;
F_5 ( & V_2 -> V_8 ) ;
return 0 ;
}
static T_3 F_18 ( struct V_39 * V_11 ,
struct V_40 * V_41 ,
const char * V_42 , T_5 V_46 )
{
struct V_20 * V_21 = F_16 ( V_11 ) ;
struct V_1 * V_2 = F_10 ( V_21 ) ;
int V_5 ;
int integer , V_47 ;
V_5 = F_19 ( V_42 , 100 , & integer , & V_47 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_17 ( V_2 , integer * 1000 + V_47 ) ;
if ( V_5 < 0 )
return V_5 ;
return V_46 ;
}
static T_3 F_20 ( struct V_39 * V_11 ,
struct V_40 * V_41 , char * V_42 )
{
int V_6 , V_46 = 0 ;
struct V_20 * V_21 = F_16 ( V_11 ) ;
struct V_1 * V_2 = F_10 ( V_21 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_48 -> V_49 ; V_6 ++ )
if ( V_2 -> V_48 -> V_50 [ V_6 ] )
V_46 += sprintf ( V_42 + V_46 , L_7 ,
V_2 -> V_48 -> V_50 [ V_6 ] ) ;
V_46 += sprintf ( V_42 + V_46 , L_8 ) ;
return V_46 ;
}
static T_3 F_21 ( struct V_39 * V_11 ,
struct V_40 * V_41 , char * V_42 )
{
struct V_20 * V_21 = F_16 ( V_11 ) ;
struct V_1 * V_2 = F_10 ( V_21 ) ;
int V_46 ;
V_46 = sprintf ( V_42 , L_9 , V_2 -> V_51 ) ;
return V_46 ;
}
static T_3 F_22 ( struct V_1 * V_2 ,
unsigned int V_30 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 , V_6 ;
T_4 V_44 ;
if ( ! V_30 )
return - V_34 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_48 -> V_49 ; V_6 ++ )
if ( V_30 && ( V_30 == V_2 -> V_48 -> V_50 [ V_6 ] ) ) {
V_44 = V_6 ;
break;
}
if ( V_6 >= V_2 -> V_48 -> V_49 )
return - V_34 ;
F_2 ( & V_2 -> V_8 ) ;
V_5 = F_3 ( V_4 , V_52 , V_44 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_4 -> V_11 , L_10 , V_5 ) ;
F_5 ( & V_2 -> V_8 ) ;
return V_5 ;
}
V_2 -> V_51 = V_30 ;
F_5 ( & V_2 -> V_8 ) ;
return 0 ;
}
static T_3 F_23 ( struct V_39 * V_11 ,
struct V_40 * V_41 ,
const char * V_42 , T_5 V_46 )
{
struct V_20 * V_21 = F_16 ( V_11 ) ;
struct V_1 * V_2 = F_10 ( V_21 ) ;
int V_5 ;
unsigned int V_30 ;
V_5 = F_24 ( V_42 , 10 , & V_30 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_22 ( V_2 , V_30 ) ;
if ( V_5 < 0 )
return V_5 ;
return V_46 ;
}
static int F_25 ( struct V_3 * V_4 ,
const struct V_53 * V_54 )
{
struct V_20 * V_21 ;
struct V_1 * V_2 ;
int V_5 ;
if ( ! F_26 ( V_4 -> V_55 ,
V_56 |
V_57 |
V_58 ) )
return - V_59 ;
V_21 = F_27 ( & V_4 -> V_11 , sizeof( * V_2 ) ) ;
if ( ! V_21 )
return - V_60 ;
V_2 = F_10 ( V_21 ) ;
F_28 ( V_4 , V_21 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_61 = (enum V_62 ) V_54 -> V_63 ;
switch ( V_2 -> V_61 ) {
case V_64 :
V_2 -> V_48 = & V_65 ;
V_21 -> V_66 = & V_67 ;
break;
case V_68 :
V_2 -> V_48 = & V_69 ;
V_21 -> V_66 = & V_70 ;
break;
case V_71 :
V_2 -> V_48 = & V_72 ;
V_21 -> V_66 = & V_70 ;
break;
default:
return - V_34 ;
}
V_21 -> V_73 = V_54 -> V_73 ;
V_21 -> V_11 . V_74 = & V_4 -> V_11 ;
V_21 -> V_75 = V_76 ;
V_21 -> V_77 = V_78 ;
V_21 -> V_79 = F_29 ( V_78 ) ;
F_30 ( & V_2 -> V_8 ) ;
V_5 = F_31 ( & V_4 -> V_11 , V_21 ,
V_80 , F_9 , NULL ) ;
if ( V_5 < 0 ) {
F_4 ( & V_4 -> V_11 , L_11 ) ;
return V_5 ;
}
if ( V_2 -> V_48 -> V_81 ) {
V_5 = F_17 ( V_2 ,
V_2 -> V_48 -> V_81 ) ;
if ( V_5 < 0 )
return V_5 ;
}
if ( V_2 -> V_48 -> V_82 ) {
V_5 = F_22 ( V_2 ,
V_2 -> V_48 -> V_82 ) ;
if ( V_5 < 0 )
return V_5 ;
}
return F_32 ( & V_4 -> V_11 , V_21 ) ;
}
