static int
F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
int V_3 ;
T_1 V_4 ;
V_3 = F_2 ( V_1 , V_5 , V_6 ) ;
if ( V_3 )
return V_3 ;
V_4 = V_7 | V_2 ;
return F_2 ( V_1 , V_8 , V_4 ) ;
}
static int
F_3 ( struct V_9 * V_10 , struct V_11 * V_12 ,
T_1 V_4 )
{
unsigned int V_13 = ( V_12 -> V_14 % 4 ) * 2 ;
unsigned int V_15 = V_16 << V_13 ;
unsigned int V_17 = V_10 -> V_18 + ( V_12 -> V_14 >> 2 ) ;
V_4 = V_4 << V_13 ;
return F_4 ( V_10 -> V_1 , V_17 , V_15 , V_4 ) ;
}
static int
F_5 ( struct V_9 * V_10 , struct V_11 * V_12 ,
T_1 V_19 )
{
T_1 V_20 = F_6 ( V_12 -> V_14 ) ;
return F_2 ( V_10 -> V_1 , V_20 , V_19 ) ;
}
static int
F_7 ( struct V_21 * V_22 ,
enum V_23 V_19 )
{
struct V_11 * V_12 = F_8 ( V_22 ) ;
struct V_9 * V_10 = V_12 -> V_10 ;
int V_3 ;
switch ( V_19 ) {
case 0 :
V_3 = F_3 ( V_10 , V_12 , V_24 ) ;
break;
case V_25 :
V_3 = F_3 ( V_10 , V_12 , V_26 ) ;
break;
default:
V_3 = F_3 ( V_10 , V_12 , V_27 ) ;
if ( ! V_3 )
V_3 = F_5 ( V_10 , V_12 , V_19 ) ;
}
return V_3 ;
}
static void
F_9 ( struct V_9 * V_10 , unsigned int V_28 )
{
int V_13 = V_28 ;
while ( -- V_13 >= 0 ) {
if ( V_10 -> V_29 [ V_13 ] . V_30 )
F_10 ( & V_10 -> V_29 [ V_13 ] . V_31 ) ;
}
}
static int
F_11 ( struct V_32 * V_33 ,
struct V_9 * V_10 ,
const struct V_34 * V_34 )
{
unsigned int V_13 ;
int V_3 = 0 ;
F_1 ( V_10 -> V_1 , V_35 ) ;
for ( V_13 = 0 ; V_13 < V_36 ; V_13 ++ ) {
struct V_11 * V_12 = & V_10 -> V_29 [ V_13 ] ;
if ( ! V_12 -> V_30 )
continue;
V_12 -> V_10 = V_10 ;
V_12 -> V_14 = V_13 ;
V_12 -> V_31 . V_37 = F_7 ;
V_12 -> V_31 . V_38 = V_25 ;
V_3 = F_12 ( V_33 , & V_12 -> V_31 ) ;
if ( V_3 < 0 ) {
F_13 ( V_33 , L_1 ,
V_12 -> V_31 . V_39 ) ;
goto exit;
}
}
return 0 ;
exit:
F_9 ( V_10 , V_13 ) ;
return V_3 ;
}
static int
F_14 ( struct V_40 * V_41 ,
const struct V_42 * V_43 )
{
struct V_44 * V_45 = V_41 -> V_33 . V_46 , * V_47 ;
struct V_32 * V_33 = & V_41 -> V_33 ;
const struct V_48 * V_49 ;
const struct V_34 * V_34 ;
struct V_9 * V_10 ;
int V_3 , V_50 , V_51 ;
V_49 = F_15 ( V_52 , V_33 ) ;
if ( ! V_49 )
return - V_53 ;
V_34 = V_49 -> V_54 ;
if ( ! V_45 )
return - V_53 ;
V_50 = F_16 ( V_45 ) ;
if ( ! V_50 || V_50 > V_34 -> V_55 )
return - V_56 ;
V_10 = F_17 ( V_33 , sizeof( * V_10 ) , V_57 ) ;
if ( ! V_10 )
return - V_58 ;
V_10 -> V_1 = F_18 ( V_41 , & V_59 ) ;
if ( F_19 ( V_10 -> V_1 ) ) {
V_3 = F_20 ( V_10 -> V_1 ) ;
F_13 ( V_33 , L_2 , V_3 ) ;
return V_3 ;
}
V_10 -> V_18 = V_34 -> V_18 ;
F_21 ( V_41 , V_10 ) ;
F_22 (np, child) {
V_3 = F_23 ( V_47 , L_3 , & V_51 ) ;
if ( V_3 ) {
F_24 ( V_47 ) ;
return V_3 ;
}
if ( V_51 < 0 || V_51 >= V_34 -> V_55 ||
V_10 -> V_29 [ V_51 ] . V_30 ) {
F_24 ( V_47 ) ;
return - V_56 ;
}
V_10 -> V_29 [ V_51 ] . V_30 = true ;
V_10 -> V_29 [ V_51 ] . V_31 . V_39 =
F_25 ( V_47 , L_4 , NULL ) ? : V_47 -> V_39 ;
V_10 -> V_29 [ V_51 ] . V_31 . V_60 =
F_25 ( V_47 , L_5 , NULL ) ;
}
return F_11 ( V_33 , V_10 , V_34 ) ;
}
static int
F_26 ( struct V_40 * V_41 )
{
struct V_9 * V_10 = F_27 ( V_41 ) ;
F_9 ( V_10 , V_36 ) ;
return 0 ;
}
