static int F_1 ( struct V_1 * V_2 )
{
enum V_3 V_4 ;
V_2 -> V_5 = F_2 ( V_2 -> V_6 ) ;
if ( V_2 -> V_5 == V_7 )
V_2 -> V_5 = V_8 ;
V_4 = V_2 -> V_5 ;
if ( F_3 ( V_2 ) ) {
if ( F_4 ( V_9 ) ) {
F_5 ( V_2 -> V_6 ,
L_1 ) ;
return - V_10 ;
}
V_4 = V_11 ;
} else if ( F_6 ( V_2 ) ) {
if ( F_4 ( V_12 ) ) {
F_5 ( V_2 -> V_6 ,
L_2 ) ;
return - V_10 ;
}
V_4 = V_13 ;
} else {
if ( F_4 ( V_9 ) )
V_4 = V_13 ;
else if ( F_4 ( V_12 ) )
V_4 = V_11 ;
}
if ( V_4 != V_2 -> V_5 ) {
F_7 ( V_2 -> V_6 ,
L_3 ,
V_4 == V_13 ? L_4 : L_5 ) ;
V_2 -> V_5 = V_4 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_9 ( V_2 -> V_6 ) ;
int V_16 ;
V_16 = F_10 ( F_11 ( V_2 -> V_17 ) ,
V_2 -> V_17 ) ;
if ( V_16 )
return V_16 ;
if ( V_2 -> V_18 ) {
V_16 = F_12 ( V_2 -> V_18 ) ;
if ( V_16 )
return V_16 ;
}
if ( V_2 -> V_19 )
V_16 = F_13 ( V_2 -> V_19 ) ;
else if ( V_2 -> V_20 && V_2 -> V_20 -> V_21 )
V_16 = V_2 -> V_20 -> V_21 ( V_15 , V_2 -> V_20 -> V_22 ) ;
else {
V_16 = F_14 ( V_2 -> V_23 ) ;
if ( V_16 == 0 )
V_16 = V_21 ( V_2 -> V_23 ) ;
}
return V_16 ;
}
int F_15 ( struct V_1 * V_2 )
{
int V_16 = F_8 ( V_2 ) ;
if ( V_16 == 0 )
V_2 -> V_24 = true ;
return V_16 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_9 ( V_2 -> V_6 ) ;
int V_16 = 0 ;
if ( V_2 -> V_19 )
F_17 ( V_2 -> V_19 ) ;
else if ( V_2 -> V_20 && V_2 -> V_20 -> V_25 )
V_16 = V_2 -> V_20 -> V_25 ( V_15 , V_2 -> V_20 -> V_22 ) ;
else {
V_16 = V_25 ( V_2 -> V_23 ) ;
if ( V_16 == 0 )
V_16 = F_18 ( V_2 -> V_23 ) ;
}
if ( V_16 )
return V_16 ;
if ( V_2 -> V_18 )
F_19 ( V_2 -> V_18 ) ;
V_16 = F_20 ( F_11 ( V_2 -> V_17 ) ,
V_2 -> V_17 ) ;
return V_16 ;
}
int F_21 ( struct V_1 * V_2 )
{
int V_16 = F_16 ( V_2 ) ;
if ( V_16 == 0 )
V_2 -> V_24 = false ;
return V_16 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_26 , V_16 ;
V_2 -> V_27 = F_23 ( V_2 -> V_6 , L_6 ) ;
if ( F_24 ( V_2 -> V_27 ) ) {
V_16 = F_25 ( V_2 -> V_27 ) ;
switch ( V_16 ) {
case - V_28 :
case - V_29 :
V_2 -> V_27 = NULL ;
break;
default:
F_5 ( V_2 -> V_6 , L_7 ,
V_16 ) ;
return V_16 ;
}
}
if ( V_2 -> V_27 )
F_26 ( V_2 -> V_27 ) ;
V_2 -> V_30 = V_31 ;
V_2 -> V_23 = F_27 ( V_2 -> V_6 , L_8 ) ;
if ( F_24 ( V_2 -> V_23 ) ) {
V_16 = F_25 ( V_2 -> V_23 ) ;
switch ( V_16 ) {
case - V_32 :
case - V_33 :
V_2 -> V_23 = NULL ;
break;
case - V_34 :
return V_16 ;
default:
F_5 ( V_2 -> V_6 , L_9 , V_16 ) ;
return V_16 ;
}
}
if ( ! V_2 -> V_23 ) {
V_2 -> V_19 = F_28 ( V_2 -> V_6 , V_35 ) ;
if ( F_24 ( V_2 -> V_19 ) ) {
V_16 = F_25 ( V_2 -> V_19 ) ;
switch ( V_16 ) {
case - V_32 :
case - V_36 :
V_2 -> V_19 = NULL ;
break;
case - V_34 :
return V_16 ;
default:
F_5 ( V_2 -> V_6 , L_10 ,
V_16 ) ;
return V_16 ;
}
}
}
V_2 -> V_20 = F_29 ( V_2 -> V_6 ) ;
if ( V_2 -> V_23 ) {
if ( F_30 ( V_2 -> V_23 ) == 8 )
V_2 -> V_30 = V_37 ;
}
V_2 -> V_18 = F_31 ( V_2 -> V_6 , L_11 ) ;
if ( F_24 ( V_2 -> V_18 ) ) {
V_2 -> V_18 = NULL ;
F_32 ( V_2 -> V_6 , L_12 ) ;
}
for ( V_26 = 0 ; V_26 < F_11 ( V_2 -> V_17 ) ; V_26 ++ )
V_2 -> V_17 [ V_26 ] . V_38 = V_39 [ V_26 ] ;
V_16 = F_33 ( V_2 -> V_6 , F_11 ( V_2 -> V_17 ) ,
V_2 -> V_17 ) ;
if ( V_16 ) {
F_5 ( V_2 -> V_6 , L_13 , V_16 ) ;
return V_16 ;
}
return 0 ;
}
static int F_34 ( struct V_14 * V_6 )
{
struct V_1 * V_2 = F_35 ( V_6 ) ;
F_36 ( V_2 ) ;
if ( V_2 -> V_40 )
F_37 ( V_2 ) ;
if ( V_2 -> V_41 )
F_38 ( V_2 ) ;
if ( V_2 -> V_24 )
F_21 ( V_2 ) ;
if ( V_2 -> V_27 )
F_39 ( V_2 -> V_27 ) ;
return 0 ;
}
static void F_40 ( struct V_14 * V_6 )
{
struct V_1 * V_2 = F_35 ( V_6 ) ;
F_41 ( V_2 -> V_42 ) ;
}
static int F_42 ( struct V_14 * V_6 )
{
struct V_1 * V_2 ;
struct V_43 * V_44 ;
int V_45 ;
V_2 = F_43 ( & V_6 -> V_6 , sizeof( * V_2 ) , V_46 ) ;
if ( ! V_2 )
return - V_47 ;
V_2 -> V_6 = & V_6 -> V_6 ;
if ( ! V_6 -> V_6 . V_48 )
V_6 -> V_6 . V_48 = & V_6 -> V_6 . V_49 ;
V_45 = F_44 ( & V_6 -> V_6 , F_45 ( 32 ) ) ;
if ( V_45 )
return V_45 ;
V_44 = F_46 ( V_6 , V_50 , 0 ) ;
V_2 -> V_51 = F_47 ( & V_6 -> V_6 , V_44 ) ;
if ( F_24 ( V_2 -> V_51 ) )
return F_25 ( V_2 -> V_51 ) ;
F_32 ( & V_6 -> V_6 , L_14 ,
( unsigned long ) V_44 -> V_52 , V_2 -> V_51 ) ;
V_45 = F_22 ( V_2 ) ;
if ( V_45 )
return V_45 ;
F_48 ( & V_2 -> V_53 ) ;
V_2 -> V_42 = F_49 ( V_6 , 0 ) ;
if ( V_2 -> V_42 < 0 ) {
F_5 ( & V_6 -> V_6 , L_15 ) ;
return V_2 -> V_42 ;
}
F_32 ( V_2 -> V_6 , L_16 ,
V_2 -> V_42 ) ;
V_45 = F_50 ( V_2 -> V_6 , V_2 -> V_42 ,
V_54 , V_55 ,
F_51 ( V_2 -> V_6 ) , V_2 ) ;
if ( V_45 )
return V_45 ;
V_45 = F_15 ( V_2 ) ;
if ( V_45 )
return V_45 ;
V_45 = F_1 ( V_2 ) ;
if ( V_45 )
goto error;
F_52 ( V_2 ) ;
V_45 = F_53 ( V_2 ) ;
if ( V_45 )
goto error;
F_54 ( V_2 ) ;
V_45 = F_55 ( V_2 ) ;
if ( V_45 )
goto error;
if ( V_2 -> V_5 != V_13 ) {
V_45 = F_56 ( V_2 , V_2 -> V_42 ) ;
if ( V_45 )
goto error;
V_2 -> V_41 = 1 ;
}
if ( V_2 -> V_5 != V_11 ) {
V_45 = F_57 ( V_2 , V_2 -> V_42 ) ;
if ( V_45 ) {
if ( V_2 -> V_41 )
F_38 ( V_2 ) ;
goto error;
}
V_2 -> V_40 = 1 ;
}
F_58 ( V_6 , V_2 ) ;
F_59 ( V_2 ) ;
if ( V_2 -> V_5 == V_11 )
F_21 ( V_2 ) ;
return 0 ;
error:
F_21 ( V_2 ) ;
return V_45 ;
}
static int T_1 F_60 ( struct V_56 * V_6 )
{
struct V_1 * V_57 = F_61 ( V_6 ) ;
int V_16 = 0 ;
if ( F_62 ( V_57 ) )
F_63 ( V_57 ) ;
if ( V_57 -> V_24 )
V_16 = F_16 ( V_57 ) ;
return V_16 ;
}
static int T_1 F_64 ( struct V_56 * V_6 )
{
struct V_1 * V_57 = F_61 ( V_6 ) ;
int V_16 = 0 ;
if ( V_57 -> V_24 ) {
V_16 = F_8 ( V_57 ) ;
if ( V_16 )
return V_16 ;
}
if ( F_62 ( V_57 ) )
V_16 = F_65 ( V_57 ) ;
return V_16 ;
}
