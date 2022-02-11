static int F_1 ( int V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) - 1 ; V_2 ++ ) {
if ( V_1 <= ( V_3 [ V_2 ] + V_3 [ V_2 + 1 ] ) / 2 )
break;
}
return V_2 ;
}
static int F_3 ( T_1 V_4 )
{
int V_1 = V_3 [ F_4 ( V_4 ) ] ;
return F_5 ( V_1 * V_5 , 1000 ) ;
}
static T_1 F_6 ( int V_6 , T_1 V_4 )
{
int V_1 , V_7 ;
V_1 = F_5 ( V_6 * 1000 ,
V_5 ) ;
V_7 = F_1 ( V_1 ) ;
return ( V_4 & ~ V_8 ) | F_7 ( V_7 ) ;
}
static void F_8 ( struct V_9 * V_10 )
{
int V_11 ;
V_11 = F_3 ( V_10 -> V_12 ) ;
V_10 -> V_13 = F_9 ( V_11 ) ;
}
static int F_10 ( struct V_9 * V_10 )
{
T_1 V_14 = F_5 ( V_10 -> V_4 -> V_15 ,
V_10 -> V_16 ) ;
return F_11 ( V_10 -> V_17 ,
V_18 , V_14 ) ;
}
static int F_12 ( struct V_9 * V_10 )
{
struct V_19 * V_17 = V_10 -> V_17 ;
int V_20 ;
V_20 = F_11 ( V_17 , V_21 ,
V_10 -> V_12 ) ;
if ( V_20 < 0 )
return V_20 ;
return F_10 ( V_10 ) ;
}
static int F_13 ( struct V_22 * V_23 )
{
struct V_9 * V_10 = F_14 ( V_23 ) ;
struct V_19 * V_17 = V_10 -> V_17 ;
int V_2 , V_24 , V_25 ;
F_15 ( & V_17 -> V_23 , L_1 ) ;
for ( V_25 = 5 ; V_25 ; V_25 -- ) {
for ( V_2 = 0 ; V_2 < V_10 -> V_4 -> V_26 ; V_2 ++ ) {
V_24 = F_16 ( V_17 , V_2 ) ;
if ( V_24 < 0 )
return V_24 ;
V_10 -> V_27 [ V_2 ] = V_24 ;
}
if ( V_10 -> V_27 [ V_18 ] == 0 ) {
F_17 ( V_23 , L_2 ) ;
V_24 = F_12 ( V_10 ) ;
if ( V_24 < 0 )
return V_24 ;
F_18 ( V_28 ) ;
continue;
}
V_10 -> V_29 = V_30 ;
V_10 -> V_31 = 1 ;
return 0 ;
}
F_19 ( V_23 , L_3 ) ;
return - V_32 ;
}
static struct V_9 * F_20 ( struct V_22 * V_23 )
{
struct V_9 * V_10 = F_14 ( V_23 ) ;
struct V_9 * V_20 = V_10 ;
unsigned long V_33 ;
int V_24 ;
F_21 ( & V_10 -> V_34 ) ;
V_33 = V_10 -> V_29 + V_10 -> V_13 ;
if ( F_22 ( V_30 , V_33 ) || ! V_10 -> V_31 ) {
V_24 = F_13 ( V_23 ) ;
if ( V_24 < 0 )
V_20 = F_23 ( V_24 ) ;
}
F_24 ( & V_10 -> V_34 ) ;
return V_20 ;
}
static int F_25 ( struct V_9 * V_10 , T_2 V_35 )
{
int V_14 ;
switch ( V_35 ) {
case V_36 :
V_14 = F_5 ( ( V_37 ) V_10 -> V_27 [ V_35 ] ,
V_10 -> V_4 -> V_38 ) ;
break;
case V_39 :
V_14 = ( V_10 -> V_27 [ V_35 ] >> V_10 -> V_4 -> V_40 )
* V_10 -> V_4 -> V_41 ;
V_14 = F_5 ( V_14 , 1000 ) ;
break;
case V_42 :
V_14 = V_10 -> V_27 [ V_35 ] * V_10 -> V_4 -> V_43 ;
break;
case V_44 :
V_14 = ( V_37 ) V_10 -> V_27 [ V_35 ] ;
break;
case V_18 :
V_14 = F_5 ( V_10 -> V_4 -> V_15 ,
V_10 -> V_27 [ V_35 ] ) ;
break;
default:
F_26 ( 1 ) ;
V_14 = 0 ;
break;
}
return V_14 ;
}
static T_3 F_27 ( struct V_22 * V_23 ,
struct V_45 * V_46 , char * V_47 )
{
struct V_48 * V_49 = F_28 ( V_46 ) ;
struct V_9 * V_10 = F_20 ( V_23 ) ;
if ( F_29 ( V_10 ) )
return F_30 ( V_10 ) ;
return snprintf ( V_47 , V_50 , L_4 ,
F_25 ( V_10 , V_49 -> V_51 ) ) ;
}
static T_3 F_31 ( struct V_22 * V_23 ,
struct V_45 * V_46 ,
const char * V_47 , T_4 V_52 )
{
struct V_9 * V_10 = F_20 ( V_23 ) ;
unsigned long V_14 ;
int V_53 ;
if ( F_29 ( V_10 ) )
return F_30 ( V_10 ) ;
V_53 = F_32 ( V_47 , 10 , & V_14 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_14 == 0 ||
V_14 > V_10 -> V_4 -> V_15 )
return - V_54 ;
F_21 ( & V_10 -> V_34 ) ;
V_10 -> V_16 = V_14 ;
V_53 = F_10 ( V_10 ) ;
F_24 ( & V_10 -> V_34 ) ;
if ( V_53 < 0 )
return V_53 ;
return V_52 ;
}
static T_3 F_33 ( struct V_22 * V_23 ,
struct V_45 * V_46 ,
const char * V_47 , T_4 V_52 )
{
struct V_9 * V_10 = F_14 ( V_23 ) ;
unsigned long V_14 ;
int V_53 ;
V_53 = F_32 ( V_47 , 10 , & V_14 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_14 > V_55 || V_14 == 0 )
return - V_54 ;
F_21 ( & V_10 -> V_34 ) ;
V_10 -> V_12 = F_6 ( V_14 ,
V_10 -> V_27 [ V_21 ] ) ;
V_53 = F_11 ( V_10 -> V_17 ,
V_21 ,
V_10 -> V_12 ) ;
F_8 ( V_10 ) ;
V_10 -> V_31 = 0 ;
F_24 ( & V_10 -> V_34 ) ;
if ( V_53 < 0 )
return V_53 ;
return V_52 ;
}
static T_3 F_34 ( struct V_22 * V_23 ,
struct V_45 * V_46 , char * V_47 )
{
struct V_9 * V_10 = F_20 ( V_23 ) ;
if ( F_29 ( V_10 ) )
return F_30 ( V_10 ) ;
return snprintf ( V_47 , V_50 , L_4 ,
F_3 ( V_10 -> V_27 [ V_21 ] ) ) ;
}
static int F_35 ( struct V_19 * V_17 ,
const struct V_56 * V_57 )
{
struct V_58 * V_59 = V_17 -> V_59 ;
struct V_60 * V_61 ;
struct V_22 * V_23 = & V_17 -> V_23 ;
struct V_9 * V_10 ;
struct V_22 * V_62 ;
T_5 V_14 ;
int V_20 , V_63 = 0 ;
if ( ! F_36 ( V_59 , V_64 ) )
return - V_32 ;
V_10 = F_37 ( V_23 , sizeof( * V_10 ) , V_65 ) ;
if ( ! V_10 )
return - V_66 ;
if ( F_38 ( V_23 ) ) {
V_61 = F_38 ( V_23 ) ;
V_10 -> V_16 = V_61 -> V_67 ;
} else if ( ! F_39 ( V_23 -> V_68 ,
L_5 , & V_14 ) ) {
V_10 -> V_16 = V_14 ;
} else {
V_10 -> V_16 = V_69 ;
}
V_10 -> V_70 = V_57 -> V_71 ;
V_10 -> V_4 = & V_72 [ V_10 -> V_70 ] ;
V_10 -> V_12 = V_10 -> V_4 -> V_73 ;
V_10 -> V_17 = V_17 ;
if ( V_10 -> V_70 == V_74 )
F_8 ( V_10 ) ;
else
V_10 -> V_13 = V_75 / V_76 ;
if ( V_10 -> V_16 <= 0 ||
V_10 -> V_16 > V_10 -> V_4 -> V_15 )
return - V_32 ;
V_20 = F_12 ( V_10 ) ;
if ( V_20 < 0 ) {
F_19 ( V_23 , L_6 , V_20 ) ;
return - V_32 ;
}
F_40 ( & V_10 -> V_34 ) ;
V_10 -> V_77 [ V_63 ++ ] = & V_78 ;
if ( V_10 -> V_70 == V_74 )
V_10 -> V_77 [ V_63 ++ ] = & V_79 ;
V_62 = F_41 ( V_23 , V_17 -> V_80 ,
V_10 , V_10 -> V_77 ) ;
if ( F_29 ( V_62 ) )
return F_30 ( V_62 ) ;
F_42 ( V_23 , L_7 ,
V_57 -> V_80 , V_10 -> V_16 ) ;
return 0 ;
}
