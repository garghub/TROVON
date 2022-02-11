static int F_1 ( T_1 V_1 )
{
int V_2 = V_3 [ F_2 ( V_1 ) ] ;
return F_3 ( V_2 * V_4 , 1000 ) ;
}
static T_1 F_4 ( int V_5 , T_1 V_1 )
{
int V_2 , V_6 ;
V_2 = F_3 ( V_5 * 1000 ,
V_4 ) ;
V_6 = F_5 ( V_2 , V_3 ,
F_6 ( V_3 ) ) ;
return ( V_1 & ~ V_7 ) | F_7 ( V_6 ) ;
}
static void F_8 ( struct V_8 * V_9 )
{
int V_10 ;
V_10 = F_1 ( V_9 -> V_11 ) ;
V_9 -> V_12 = F_9 ( V_10 ) ;
}
static int F_10 ( struct V_8 * V_9 )
{
T_1 V_13 = F_3 ( V_9 -> V_1 -> V_14 ,
V_9 -> V_15 ) ;
return F_11 ( V_9 -> V_16 ,
V_17 , V_13 ) ;
}
static int F_12 ( struct V_8 * V_9 )
{
struct V_18 * V_16 = V_9 -> V_16 ;
int V_19 ;
V_19 = F_11 ( V_16 , V_20 ,
V_9 -> V_11 ) ;
if ( V_19 < 0 )
return V_19 ;
return F_10 ( V_9 ) ;
}
static int F_13 ( struct V_21 * V_22 )
{
struct V_8 * V_9 = F_14 ( V_22 ) ;
struct V_18 * V_16 = V_9 -> V_16 ;
int V_23 , V_24 , V_25 ;
F_15 ( & V_16 -> V_22 , L_1 ) ;
for ( V_25 = 5 ; V_25 ; V_25 -- ) {
for ( V_23 = 0 ; V_23 < V_9 -> V_1 -> V_26 ; V_23 ++ ) {
V_24 = F_16 ( V_16 , V_23 ) ;
if ( V_24 < 0 )
return V_24 ;
V_9 -> V_27 [ V_23 ] = V_24 ;
}
if ( V_9 -> V_27 [ V_17 ] == 0 ) {
F_17 ( V_22 , L_2 ) ;
V_24 = F_12 ( V_9 ) ;
if ( V_24 < 0 )
return V_24 ;
F_18 ( V_28 ) ;
continue;
}
V_9 -> V_29 = V_30 ;
V_9 -> V_31 = 1 ;
return 0 ;
}
F_19 ( V_22 , L_3 ) ;
return - V_32 ;
}
static struct V_8 * F_20 ( struct V_21 * V_22 )
{
struct V_8 * V_9 = F_14 ( V_22 ) ;
struct V_8 * V_19 = V_9 ;
unsigned long V_33 ;
int V_24 ;
F_21 ( & V_9 -> V_34 ) ;
V_33 = V_9 -> V_29 + V_9 -> V_12 ;
if ( F_22 ( V_30 , V_33 ) || ! V_9 -> V_31 ) {
V_24 = F_13 ( V_22 ) ;
if ( V_24 < 0 )
V_19 = F_23 ( V_24 ) ;
}
F_24 ( & V_9 -> V_34 ) ;
return V_19 ;
}
static int F_25 ( struct V_8 * V_9 , T_2 V_35 )
{
int V_13 ;
switch ( V_35 ) {
case V_36 :
V_13 = F_3 ( ( V_37 ) V_9 -> V_27 [ V_35 ] ,
V_9 -> V_1 -> V_38 ) ;
break;
case V_39 :
V_13 = ( V_9 -> V_27 [ V_35 ] >> V_9 -> V_1 -> V_40 )
* V_9 -> V_1 -> V_41 ;
V_13 = F_3 ( V_13 , 1000 ) ;
break;
case V_42 :
V_13 = V_9 -> V_27 [ V_35 ] * V_9 -> V_1 -> V_43 ;
break;
case V_44 :
V_13 = ( V_37 ) V_9 -> V_27 [ V_35 ] ;
break;
case V_17 :
V_13 = F_3 ( V_9 -> V_1 -> V_14 ,
V_9 -> V_27 [ V_35 ] ) ;
break;
default:
F_26 ( 1 ) ;
V_13 = 0 ;
break;
}
return V_13 ;
}
static T_3 F_27 ( struct V_21 * V_22 ,
struct V_45 * V_46 , char * V_47 )
{
struct V_48 * V_49 = F_28 ( V_46 ) ;
struct V_8 * V_9 = F_20 ( V_22 ) ;
if ( F_29 ( V_9 ) )
return F_30 ( V_9 ) ;
return snprintf ( V_47 , V_50 , L_4 ,
F_25 ( V_9 , V_49 -> V_51 ) ) ;
}
static T_3 F_31 ( struct V_21 * V_22 ,
struct V_45 * V_46 ,
const char * V_47 , T_4 V_52 )
{
struct V_8 * V_9 = F_20 ( V_22 ) ;
unsigned long V_13 ;
int V_53 ;
if ( F_29 ( V_9 ) )
return F_30 ( V_9 ) ;
V_53 = F_32 ( V_47 , 10 , & V_13 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_13 == 0 ||
V_13 > V_9 -> V_1 -> V_14 )
return - V_54 ;
F_21 ( & V_9 -> V_34 ) ;
V_9 -> V_15 = V_13 ;
V_53 = F_10 ( V_9 ) ;
F_24 ( & V_9 -> V_34 ) ;
if ( V_53 < 0 )
return V_53 ;
return V_52 ;
}
static T_3 F_33 ( struct V_21 * V_22 ,
struct V_45 * V_46 ,
const char * V_47 , T_4 V_52 )
{
struct V_8 * V_9 = F_14 ( V_22 ) ;
unsigned long V_13 ;
int V_53 ;
V_53 = F_32 ( V_47 , 10 , & V_13 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_13 > V_55 || V_13 == 0 )
return - V_54 ;
F_21 ( & V_9 -> V_34 ) ;
V_9 -> V_11 = F_4 ( V_13 ,
V_9 -> V_27 [ V_20 ] ) ;
V_53 = F_11 ( V_9 -> V_16 ,
V_20 ,
V_9 -> V_11 ) ;
F_8 ( V_9 ) ;
V_9 -> V_31 = 0 ;
F_24 ( & V_9 -> V_34 ) ;
if ( V_53 < 0 )
return V_53 ;
return V_52 ;
}
static T_3 F_34 ( struct V_21 * V_22 ,
struct V_45 * V_46 , char * V_47 )
{
struct V_8 * V_9 = F_20 ( V_22 ) ;
if ( F_29 ( V_9 ) )
return F_30 ( V_9 ) ;
return snprintf ( V_47 , V_50 , L_4 ,
F_1 ( V_9 -> V_27 [ V_20 ] ) ) ;
}
static int F_35 ( struct V_18 * V_16 ,
const struct V_56 * V_57 )
{
struct V_58 * V_59 = V_16 -> V_59 ;
struct V_60 * V_61 ;
struct V_21 * V_22 = & V_16 -> V_22 ;
struct V_8 * V_9 ;
struct V_21 * V_62 ;
T_5 V_13 ;
int V_19 , V_63 = 0 ;
if ( ! F_36 ( V_59 , V_64 ) )
return - V_32 ;
V_9 = F_37 ( V_22 , sizeof( * V_9 ) , V_65 ) ;
if ( ! V_9 )
return - V_66 ;
if ( F_38 ( V_22 ) ) {
V_61 = F_38 ( V_22 ) ;
V_9 -> V_15 = V_61 -> V_67 ;
} else if ( ! F_39 ( V_22 -> V_68 ,
L_5 , & V_13 ) ) {
V_9 -> V_15 = V_13 ;
} else {
V_9 -> V_15 = V_69 ;
}
V_9 -> V_70 = V_57 -> V_71 ;
V_9 -> V_1 = & V_72 [ V_9 -> V_70 ] ;
V_9 -> V_11 = V_9 -> V_1 -> V_73 ;
V_9 -> V_16 = V_16 ;
if ( V_9 -> V_70 == V_74 )
F_8 ( V_9 ) ;
else
V_9 -> V_12 = V_75 / V_76 ;
if ( V_9 -> V_15 <= 0 ||
V_9 -> V_15 > V_9 -> V_1 -> V_14 )
return - V_32 ;
V_19 = F_12 ( V_9 ) ;
if ( V_19 < 0 ) {
F_19 ( V_22 , L_6 , V_19 ) ;
return - V_32 ;
}
F_40 ( & V_9 -> V_34 ) ;
V_9 -> V_77 [ V_63 ++ ] = & V_78 ;
if ( V_9 -> V_70 == V_74 )
V_9 -> V_77 [ V_63 ++ ] = & V_79 ;
V_62 = F_41 ( V_22 , V_16 -> V_80 ,
V_9 , V_9 -> V_77 ) ;
if ( F_29 ( V_62 ) )
return F_30 ( V_62 ) ;
F_42 ( V_22 , L_7 ,
V_57 -> V_80 , V_9 -> V_15 ) ;
return 0 ;
}
