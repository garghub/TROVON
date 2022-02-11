static int F_1 ( struct V_1 * V_2 ,
int V_3 )
{
int V_4 ;
int V_5 ;
switch ( V_2 -> V_6 ) {
case V_7 :
V_4 = V_8 ;
break;
case V_9 :
V_4 = V_10 ;
break;
default:
return - V_11 ;
}
for ( V_5 = 0 ; V_5 < 7 ; V_5 ++ ) {
if ( V_4 >= V_3 )
return V_5 ;
V_4 *= 2 ;
}
return V_5 ;
}
static int F_2 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
unsigned int V_16 = 0 , V_17 = 0 ;
T_1 V_18 ;
T_1 V_19 ;
int V_3 , V_20 ;
int V_21 ;
char V_22 [ 10 ] ;
switch ( V_2 -> V_6 ) {
case V_7 :
V_18 = V_23 ;
break;
case V_9 :
V_18 = V_24 ;
break;
default:
return - V_11 ;
}
for ( V_20 = 0 ; V_20 < V_25 ; V_20 ++ ) {
sprintf ( V_22 , L_1 , V_20 ) ;
if ( ! strcmp ( V_13 -> V_26 , V_22 ) )
break;
}
if ( V_20 == V_25 ) {
F_3 ( V_15 , L_2 , V_13 -> V_26 ) ;
return - V_11 ;
}
V_21 = F_4 ( V_13 , L_3 ,
& V_19 ) ;
if ( ! V_21 ) {
V_16 |= V_27 ;
V_2 -> V_28 [ V_20 ] = F_5 ( V_19 ,
V_18 ) ;
V_3 = F_1 ( V_2 ,
V_2 -> V_28 [ V_20 ] ) ;
V_17 |= V_3 << V_29 ;
}
V_21 = F_4 ( V_13 , L_4 ,
& V_19 ) ;
if ( ! V_21 )
V_2 -> V_30 [ V_20 ] = F_5 ( V_19 ,
V_18 ) ;
V_21 = F_4 ( V_13 , L_5 ,
& V_19 ) ;
if ( ! V_21 ) {
if ( V_19 > 2 ) {
F_3 ( V_15 , L_6 , V_20 ) ;
return - V_11 ;
}
V_16 |= V_31 ;
V_17 |= V_19 << V_32 ;
if ( V_19 == 2 ) {
V_16 |= V_33 ;
V_17 |= V_34 ;
}
}
if ( ! V_2 -> V_35 && ! V_2 -> V_36 ) {
V_21 = F_4 ( V_13 ,
L_7 ,
& V_19 ) ;
if ( ! V_21 ) {
if ( V_19 == 0 )
V_2 -> V_35 = true ;
else if ( V_19 == 1 )
V_2 -> V_36 = true ;
}
}
V_21 = F_6 ( V_2 -> V_37 , V_38 + V_20 ,
V_16 , V_17 ) ;
if ( V_21 < 0 ) {
F_3 ( V_15 , L_8 , V_21 ) ;
return V_21 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_12 * V_13 , * V_39 ;
T_2 V_17 ;
int V_20 ;
int V_21 ;
for ( V_20 = 0 ; V_20 < V_25 ; V_20 ++ ) {
V_2 -> V_28 [ V_20 ] = - 1 ;
V_2 -> V_30 [ V_20 ] = - 1 ;
}
V_13 = F_8 ( V_15 -> V_40 , L_9 ) ;
if ( ! V_13 )
goto V_41;
F_9 (fps_np, fps_child) {
V_21 = F_2 ( V_2 , V_39 ) ;
if ( V_21 < 0 )
return V_21 ;
}
V_17 = V_2 -> V_36 ? V_42 : 0 ;
V_21 = F_6 ( V_2 -> V_37 , V_43 ,
V_42 , V_17 ) ;
if ( V_21 < 0 ) {
F_3 ( V_15 , L_10 , V_21 ) ;
return V_21 ;
}
V_41:
V_21 = F_6 ( V_2 -> V_37 , V_43 ,
V_44 ,
V_44 ) ;
if ( V_21 < 0 ) {
F_3 ( V_15 , L_11 , V_21 ) ;
return V_21 ;
}
if ( ( V_2 -> V_6 == V_7 ) && V_2 -> V_35 ) {
V_17 = V_45 | V_46 ;
V_21 = F_6 ( V_2 -> V_37 , V_47 ,
V_17 , V_17 ) ;
if ( V_21 < 0 ) {
F_3 ( V_15 , L_12 , V_21 ) ;
return V_21 ;
}
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
unsigned int V_48 ;
T_2 V_49 [ 6 ] ;
int V_5 ;
int V_21 ;
for ( V_5 = V_50 ; V_5 <= V_51 ; V_5 ++ ) {
V_21 = F_11 ( V_2 -> V_37 , V_5 , & V_48 ) ;
if ( V_21 < 0 ) {
F_3 ( V_2 -> V_15 , L_13 , V_21 ) ;
return V_21 ;
}
F_12 ( V_2 -> V_15 , L_14 ,
V_5 - V_50 , V_48 ) ;
V_49 [ V_5 - V_50 ] = V_48 ;
}
F_13 ( V_2 -> V_15 , L_15 ,
V_49 [ 4 ] , F_14 ( V_49 [ 5 ] ) ) ;
return V_21 ;
}
static int F_15 ( struct V_52 * V_53 ,
const struct V_54 * V_55 )
{
const struct V_56 * V_57 ;
struct V_1 * V_2 ;
const struct V_58 * V_59 ;
int V_60 ;
int V_21 ;
V_2 = F_16 ( & V_53 -> V_15 , sizeof( * V_2 ) , V_61 ) ;
if ( ! V_2 )
return - V_62 ;
F_17 ( V_53 , V_2 ) ;
V_2 -> V_15 = & V_53 -> V_15 ;
V_2 -> V_63 = - 1 ;
V_2 -> V_64 = V_53 -> V_65 ;
V_2 -> V_6 = (enum V_66 ) V_55 -> V_67 ;
switch ( V_2 -> V_6 ) {
case V_9 :
V_59 = V_68 ;
V_60 = F_18 ( V_68 ) ;
V_57 = & V_69 ;
break;
case V_7 :
V_59 = V_70 ;
V_60 = F_18 ( V_70 ) ;
V_57 = & V_71 ;
break;
default:
F_3 ( V_2 -> V_15 , L_16 , V_2 -> V_6 ) ;
return - V_11 ;
}
V_2 -> V_37 = F_19 ( V_53 , V_57 ) ;
if ( F_20 ( V_2 -> V_37 ) ) {
V_21 = F_21 ( V_2 -> V_37 ) ;
F_3 ( V_2 -> V_15 , L_17 , V_21 ) ;
return V_21 ;
}
V_21 = F_10 ( V_2 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_22 ( V_2 -> V_15 , V_2 -> V_37 , V_53 -> V_65 ,
V_72 | V_73 ,
V_2 -> V_63 , & V_74 ,
& V_2 -> V_75 ) ;
if ( V_21 < 0 ) {
F_3 ( V_2 -> V_15 , L_18 , V_21 ) ;
return V_21 ;
}
V_21 = F_7 ( V_2 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_23 ( V_2 -> V_15 , V_76 ,
V_59 , V_60 , NULL , 0 ,
F_24 ( V_2 -> V_75 ) ) ;
if ( V_21 < 0 ) {
F_3 ( V_2 -> V_15 , L_19 , V_21 ) ;
return V_21 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
int V_20 , int V_77 )
{
int V_78 = F_1 ( V_2 , V_77 ) ;
int V_21 ;
V_21 = F_6 ( V_2 -> V_37 , V_38 + V_20 ,
V_27 ,
V_78 << V_29 ) ;
if ( V_21 < 0 ) {
F_3 ( V_2 -> V_15 , L_20 , V_21 ) ;
return V_21 ;
}
return 0 ;
}
static int F_26 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_27 ( V_15 ) ;
struct V_52 * V_53 = F_28 ( V_15 ) ;
unsigned int V_17 ;
int V_79 ;
int V_21 ;
for ( V_79 = 0 ; V_79 < V_25 ; V_79 ++ ) {
if ( V_2 -> V_30 [ V_79 ] < 0 )
continue;
V_21 = F_25 ( V_2 , V_79 ,
V_2 -> V_30 [ V_79 ] ) ;
if ( V_21 < 0 )
return V_21 ;
}
if ( V_2 -> V_6 == V_7 )
goto V_80;
V_17 = ( V_2 -> V_35 ) ? V_45 : 0 ;
V_21 = F_6 ( V_2 -> V_37 , V_47 ,
V_45 ,
V_17 ) ;
if ( V_21 < 0 ) {
F_3 ( V_15 , L_21 , V_21 ) ;
return V_21 ;
}
V_21 = F_6 ( V_2 -> V_37 , V_43 ,
V_44 , 0 ) ;
if ( V_21 < 0 ) {
F_3 ( V_15 , L_22 , V_21 ) ;
return V_21 ;
}
V_80:
F_29 ( V_53 -> V_65 ) ;
return 0 ;
}
static int F_30 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_27 ( V_15 ) ;
struct V_52 * V_53 = F_28 ( V_15 ) ;
int V_21 ;
int V_79 ;
for ( V_79 = 0 ; V_79 < V_25 ; V_79 ++ ) {
if ( V_2 -> V_28 [ V_79 ] < 0 )
continue;
V_21 = F_25 ( V_2 , V_79 ,
V_2 -> V_28 [ V_79 ] ) ;
if ( V_21 < 0 )
return V_21 ;
}
if ( V_2 -> V_6 == V_7 )
goto V_80;
V_21 = F_6 ( V_2 -> V_37 , V_43 ,
V_44 ,
V_44 ) ;
if ( V_21 < 0 ) {
F_3 ( V_15 , L_23 , V_21 ) ;
return V_21 ;
}
V_80:
F_31 ( V_53 -> V_65 ) ;
return 0 ;
}
