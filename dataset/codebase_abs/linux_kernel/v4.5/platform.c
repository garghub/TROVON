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
V_2 -> V_27 = V_28 ;
V_2 -> V_23 = F_23 ( V_2 -> V_6 , L_6 ) ;
if ( F_24 ( V_2 -> V_23 ) ) {
V_16 = F_25 ( V_2 -> V_23 ) ;
switch ( V_16 ) {
case - V_29 :
case - V_30 :
V_2 -> V_23 = NULL ;
break;
case - V_31 :
return V_16 ;
default:
F_5 ( V_2 -> V_6 , L_7 , V_16 ) ;
return V_16 ;
}
}
if ( ! V_2 -> V_23 ) {
V_2 -> V_19 = F_26 ( V_2 -> V_6 , V_32 ) ;
if ( F_24 ( V_2 -> V_19 ) ) {
V_16 = F_25 ( V_2 -> V_19 ) ;
switch ( V_16 ) {
case - V_29 :
case - V_33 :
V_2 -> V_19 = NULL ;
break;
case - V_31 :
return V_16 ;
default:
F_5 ( V_2 -> V_6 , L_8 ,
V_16 ) ;
return V_16 ;
}
}
}
V_2 -> V_20 = F_27 ( V_2 -> V_6 ) ;
if ( V_2 -> V_23 ) {
if ( F_28 ( V_2 -> V_23 ) == 8 )
V_2 -> V_27 = V_34 ;
}
V_2 -> V_18 = F_29 ( V_2 -> V_6 , L_9 ) ;
if ( F_24 ( V_2 -> V_18 ) ) {
V_2 -> V_18 = NULL ;
F_30 ( V_2 -> V_6 , L_10 ) ;
}
for ( V_26 = 0 ; V_26 < F_11 ( V_2 -> V_17 ) ; V_26 ++ )
V_2 -> V_17 [ V_26 ] . V_35 = V_36 [ V_26 ] ;
V_16 = F_31 ( V_2 -> V_6 , F_11 ( V_2 -> V_17 ) ,
V_2 -> V_17 ) ;
if ( V_16 ) {
F_5 ( V_2 -> V_6 , L_11 , V_16 ) ;
return V_16 ;
}
return 0 ;
}
static int F_32 ( struct V_14 * V_6 )
{
struct V_1 * V_2 = F_33 ( V_6 ) ;
F_34 ( V_2 ) ;
if ( V_2 -> V_37 )
F_35 ( V_2 ) ;
if ( V_2 -> V_38 )
F_36 ( V_2 ) ;
if ( V_2 -> V_24 )
F_21 ( V_2 ) ;
return 0 ;
}
static void F_37 ( struct V_14 * V_6 )
{
struct V_1 * V_2 = F_33 ( V_6 ) ;
F_38 ( V_2 -> V_39 ) ;
}
static int F_39 ( struct V_14 * V_6 )
{
const struct V_40 * V_41 ;
const struct V_42 * V_43 ;
struct V_42 V_44 ;
struct V_1 * V_2 ;
struct V_45 * V_46 ;
int V_47 ;
V_41 = F_40 ( V_48 , & V_6 -> V_6 ) ;
if ( V_41 && V_41 -> V_49 ) {
V_43 = V_41 -> V_49 ;
} else {
F_41 ( & V_44 , - 1 ) ;
V_43 = & V_44 ;
V_44 . V_50 = 0 ;
V_44 . V_51 = 0 ;
}
V_2 = F_42 ( & V_6 -> V_6 , sizeof( * V_2 ) , V_52 ) ;
if ( ! V_2 )
return - V_53 ;
V_2 -> V_6 = & V_6 -> V_6 ;
if ( ! V_6 -> V_6 . V_54 )
V_6 -> V_6 . V_54 = & V_6 -> V_6 . V_55 ;
V_47 = F_43 ( & V_6 -> V_6 , F_44 ( 32 ) ) ;
if ( V_47 )
return V_47 ;
V_46 = F_45 ( V_6 , V_56 , 0 ) ;
V_2 -> V_57 = F_46 ( & V_6 -> V_6 , V_46 ) ;
if ( F_24 ( V_2 -> V_57 ) )
return F_25 ( V_2 -> V_57 ) ;
F_30 ( & V_6 -> V_6 , L_12 ,
( unsigned long ) V_46 -> V_58 , V_2 -> V_57 ) ;
V_47 = F_22 ( V_2 ) ;
if ( V_47 )
return V_47 ;
F_47 ( & V_2 -> V_59 ) ;
V_2 -> V_60 = F_42 ( & V_6 -> V_6 ,
sizeof( * V_2 -> V_60 ) , V_52 ) ;
if ( ! V_2 -> V_60 )
return - V_53 ;
F_41 ( V_2 -> V_60 , - 1 ) ;
V_2 -> V_39 = F_48 ( V_6 , 0 ) ;
if ( V_2 -> V_39 < 0 ) {
F_5 ( & V_6 -> V_6 , L_13 ) ;
return V_2 -> V_39 ;
}
F_30 ( V_2 -> V_6 , L_14 ,
V_2 -> V_39 ) ;
V_47 = F_49 ( V_2 -> V_6 , V_2 -> V_39 ,
V_61 , V_62 ,
F_50 ( V_2 -> V_6 ) , V_2 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_15 ( V_2 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_1 ( V_2 ) ;
if ( V_47 )
return V_47 ;
F_51 ( V_2 ) ;
V_47 = F_52 ( V_2 ) ;
if ( V_47 )
goto error;
F_53 ( V_2 , V_43 ) ;
F_54 ( V_2 ) ;
if ( V_2 -> V_5 != V_13 ) {
V_47 = F_55 ( V_2 , V_2 -> V_39 ) ;
if ( V_47 )
goto error;
V_2 -> V_38 = 1 ;
}
if ( V_2 -> V_5 != V_11 ) {
V_47 = F_56 ( V_2 , V_2 -> V_39 ) ;
if ( V_47 ) {
if ( V_2 -> V_38 )
F_36 ( V_2 ) ;
goto error;
}
V_2 -> V_37 = 1 ;
}
F_57 ( V_6 , V_2 ) ;
F_58 ( V_2 ) ;
if ( V_2 -> V_5 == V_11 )
F_21 ( V_2 ) ;
return 0 ;
error:
F_21 ( V_2 ) ;
return V_47 ;
}
static int T_1 F_59 ( struct V_63 * V_6 )
{
struct V_1 * V_64 = F_60 ( V_6 ) ;
int V_16 = 0 ;
if ( F_61 ( V_64 ) )
F_62 ( V_64 ) ;
if ( V_64 -> V_24 )
V_16 = F_16 ( V_64 ) ;
return V_16 ;
}
static int T_1 F_63 ( struct V_63 * V_6 )
{
struct V_1 * V_64 = F_60 ( V_6 ) ;
int V_16 = 0 ;
if ( V_64 -> V_24 ) {
V_16 = F_8 ( V_64 ) ;
if ( V_16 )
return V_16 ;
}
if ( F_61 ( V_64 ) )
V_16 = F_64 ( V_64 ) ;
return V_16 ;
}
