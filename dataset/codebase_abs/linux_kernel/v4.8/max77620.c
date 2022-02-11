static int F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
int V_4 ;
V_4 = F_2 ( V_3 -> V_5 , V_6 ,
V_7 , V_7 ) ;
if ( V_4 < 0 )
F_3 ( V_3 -> V_8 , L_1 , V_4 ) ;
return V_4 ;
}
static int F_4 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
int V_4 ;
V_4 = F_2 ( V_3 -> V_5 , V_6 ,
V_7 , 0 ) ;
if ( V_4 < 0 )
F_3 ( V_3 -> V_8 , L_2 , V_4 ) ;
return V_4 ;
}
static int F_5 ( struct V_2 * V_3 ,
int V_9 )
{
int V_10 ;
int V_11 ;
switch ( V_3 -> V_12 ) {
case V_13 :
V_10 = V_14 ;
break;
case V_15 :
V_10 = V_16 ;
break;
default:
return - V_17 ;
}
for ( V_11 = 0 ; V_11 < 7 ; V_11 ++ ) {
if ( V_10 >= V_9 )
return V_11 ;
V_10 *= 2 ;
}
return V_11 ;
}
static int F_6 ( struct V_2 * V_3 ,
struct V_18 * V_19 )
{
struct V_20 * V_8 = V_3 -> V_8 ;
unsigned int V_21 = 0 , V_22 = 0 ;
T_1 V_23 ;
T_1 V_24 ;
int V_9 , V_25 ;
int V_4 ;
char V_26 [ 10 ] ;
switch ( V_3 -> V_12 ) {
case V_13 :
V_23 = V_27 ;
break;
case V_15 :
V_23 = V_28 ;
break;
default:
return - V_17 ;
}
for ( V_25 = 0 ; V_25 < V_29 ; V_25 ++ ) {
sprintf ( V_26 , L_3 , V_25 ) ;
if ( ! strcmp ( V_19 -> V_30 , V_26 ) )
break;
}
if ( V_25 == V_29 ) {
F_3 ( V_8 , L_4 , V_19 -> V_30 ) ;
return - V_17 ;
}
V_4 = F_7 ( V_19 , L_5 ,
& V_24 ) ;
if ( ! V_4 ) {
V_21 |= V_31 ;
V_3 -> V_32 [ V_25 ] = F_8 ( V_24 ,
V_23 ) ;
V_9 = F_5 ( V_3 ,
V_3 -> V_32 [ V_25 ] ) ;
V_22 |= V_9 << V_33 ;
}
V_4 = F_7 ( V_19 , L_6 ,
& V_24 ) ;
if ( ! V_4 )
V_3 -> V_34 [ V_25 ] = F_8 ( V_24 ,
V_23 ) ;
V_4 = F_7 ( V_19 , L_7 ,
& V_24 ) ;
if ( ! V_4 ) {
if ( V_24 > 2 ) {
F_3 ( V_8 , L_8 , V_25 ) ;
return - V_17 ;
}
V_21 |= V_35 ;
V_22 |= V_24 << V_36 ;
if ( V_24 == 2 ) {
V_21 |= V_37 ;
V_22 |= V_38 ;
}
}
if ( ! V_3 -> V_39 && ! V_3 -> V_40 ) {
V_4 = F_7 ( V_19 ,
L_9 ,
& V_24 ) ;
if ( ! V_4 ) {
if ( V_24 == 0 )
V_3 -> V_39 = true ;
else if ( V_24 == 1 )
V_3 -> V_40 = true ;
}
}
V_4 = F_2 ( V_3 -> V_5 , V_41 + V_25 ,
V_21 , V_22 ) ;
if ( V_4 < 0 ) {
F_3 ( V_8 , L_10 , V_4 ) ;
return V_4 ;
}
return 0 ;
}
static int F_9 ( struct V_2 * V_3 )
{
struct V_20 * V_8 = V_3 -> V_8 ;
struct V_18 * V_19 , * V_42 ;
T_2 V_22 ;
int V_25 ;
int V_4 ;
for ( V_25 = 0 ; V_25 < V_29 ; V_25 ++ ) {
V_3 -> V_32 [ V_25 ] = - 1 ;
V_3 -> V_34 [ V_25 ] = - 1 ;
}
V_19 = F_10 ( V_8 -> V_43 , L_11 ) ;
if ( ! V_19 )
goto V_44;
F_11 (fps_np, fps_child) {
V_4 = F_6 ( V_3 , V_42 ) ;
if ( V_4 < 0 )
return V_4 ;
}
V_22 = V_3 -> V_40 ? V_45 : 0 ;
V_4 = F_2 ( V_3 -> V_5 , V_46 ,
V_45 , V_22 ) ;
if ( V_4 < 0 ) {
F_3 ( V_8 , L_12 , V_4 ) ;
return V_4 ;
}
V_44:
V_4 = F_2 ( V_3 -> V_5 , V_46 ,
V_47 ,
V_47 ) ;
if ( V_4 < 0 ) {
F_3 ( V_8 , L_13 , V_4 ) ;
return V_4 ;
}
if ( ( V_3 -> V_12 == V_13 ) && V_3 -> V_39 ) {
V_22 = V_48 | V_49 ;
V_4 = F_2 ( V_3 -> V_5 , V_50 ,
V_22 , V_22 ) ;
if ( V_4 < 0 ) {
F_3 ( V_8 , L_14 , V_4 ) ;
return V_4 ;
}
}
return 0 ;
}
static int F_12 ( struct V_2 * V_3 )
{
unsigned int V_51 ;
T_2 V_52 [ 6 ] ;
int V_11 ;
int V_4 ;
for ( V_11 = V_53 ; V_11 <= V_54 ; V_11 ++ ) {
V_4 = F_13 ( V_3 -> V_5 , V_11 , & V_51 ) ;
if ( V_4 < 0 ) {
F_3 ( V_3 -> V_8 , L_15 , V_4 ) ;
return V_4 ;
}
F_14 ( V_3 -> V_8 , L_16 ,
V_11 - V_53 , V_51 ) ;
V_52 [ V_11 - V_53 ] = V_51 ;
}
F_15 ( V_3 -> V_8 , L_17 ,
V_52 [ 4 ] , F_16 ( V_52 [ 5 ] ) ) ;
return V_4 ;
}
static int F_17 ( struct V_55 * V_56 ,
const struct V_57 * V_58 )
{
const struct V_59 * V_60 ;
struct V_2 * V_3 ;
const struct V_61 * V_62 ;
int V_63 ;
int V_4 ;
V_3 = F_18 ( & V_56 -> V_8 , sizeof( * V_3 ) , V_64 ) ;
if ( ! V_3 )
return - V_65 ;
F_19 ( V_56 , V_3 ) ;
V_3 -> V_8 = & V_56 -> V_8 ;
V_3 -> V_66 = - 1 ;
V_3 -> V_67 = V_56 -> V_68 ;
V_3 -> V_12 = (enum V_69 ) V_58 -> V_70 ;
switch ( V_3 -> V_12 ) {
case V_15 :
V_62 = V_71 ;
V_63 = F_20 ( V_71 ) ;
V_60 = & V_72 ;
break;
case V_13 :
V_62 = V_73 ;
V_63 = F_20 ( V_73 ) ;
V_60 = & V_74 ;
break;
default:
F_3 ( V_3 -> V_8 , L_18 , V_3 -> V_12 ) ;
return - V_17 ;
}
V_3 -> V_5 = F_21 ( V_56 , V_60 ) ;
if ( F_22 ( V_3 -> V_5 ) ) {
V_4 = F_23 ( V_3 -> V_5 ) ;
F_3 ( V_3 -> V_8 , L_19 , V_4 ) ;
return V_4 ;
}
V_4 = F_12 ( V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
V_75 . V_1 = V_3 ;
V_4 = F_24 ( V_3 -> V_8 , V_3 -> V_5 , V_56 -> V_68 ,
V_76 | V_77 ,
V_3 -> V_66 , & V_75 ,
& V_3 -> V_78 ) ;
if ( V_4 < 0 ) {
F_3 ( V_3 -> V_8 , L_20 , V_4 ) ;
return V_4 ;
}
V_4 = F_9 ( V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_25 ( V_3 -> V_8 , V_79 ,
V_62 , V_63 , NULL , 0 ,
F_26 ( V_3 -> V_78 ) ) ;
if ( V_4 < 0 ) {
F_3 ( V_3 -> V_8 , L_21 , V_4 ) ;
return V_4 ;
}
return 0 ;
}
static int F_27 ( struct V_2 * V_3 ,
int V_25 , int V_80 )
{
int V_81 = F_5 ( V_3 , V_80 ) ;
int V_4 ;
V_4 = F_2 ( V_3 -> V_5 , V_41 + V_25 ,
V_31 ,
V_81 << V_33 ) ;
if ( V_4 < 0 ) {
F_3 ( V_3 -> V_8 , L_22 , V_4 ) ;
return V_4 ;
}
return 0 ;
}
static int F_28 ( struct V_20 * V_8 )
{
struct V_2 * V_3 = F_29 ( V_8 ) ;
struct V_55 * V_56 = F_30 ( V_8 ) ;
unsigned int V_22 ;
int V_82 ;
int V_4 ;
for ( V_82 = 0 ; V_82 < V_29 ; V_82 ++ ) {
if ( V_3 -> V_34 [ V_82 ] < 0 )
continue;
V_4 = F_27 ( V_3 , V_82 ,
V_3 -> V_34 [ V_82 ] ) ;
if ( V_4 < 0 )
return V_4 ;
}
if ( V_3 -> V_12 == V_13 )
goto V_83;
V_22 = ( V_3 -> V_39 ) ? V_48 : 0 ;
V_4 = F_2 ( V_3 -> V_5 , V_50 ,
V_48 ,
V_22 ) ;
if ( V_4 < 0 ) {
F_3 ( V_8 , L_23 , V_4 ) ;
return V_4 ;
}
V_4 = F_2 ( V_3 -> V_5 , V_46 ,
V_47 , 0 ) ;
if ( V_4 < 0 ) {
F_3 ( V_8 , L_24 , V_4 ) ;
return V_4 ;
}
V_83:
F_31 ( V_56 -> V_68 ) ;
return 0 ;
}
static int F_32 ( struct V_20 * V_8 )
{
struct V_2 * V_3 = F_29 ( V_8 ) ;
struct V_55 * V_56 = F_30 ( V_8 ) ;
int V_4 ;
int V_82 ;
for ( V_82 = 0 ; V_82 < V_29 ; V_82 ++ ) {
if ( V_3 -> V_32 [ V_82 ] < 0 )
continue;
V_4 = F_27 ( V_3 , V_82 ,
V_3 -> V_32 [ V_82 ] ) ;
if ( V_4 < 0 )
return V_4 ;
}
if ( V_3 -> V_12 == V_13 )
goto V_83;
V_4 = F_2 ( V_3 -> V_5 , V_46 ,
V_47 ,
V_47 ) ;
if ( V_4 < 0 ) {
F_3 ( V_8 , L_25 , V_4 ) ;
return V_4 ;
}
V_83:
F_33 ( V_56 -> V_68 ) ;
return 0 ;
}
