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
static void
F_7 ( struct V_21 * V_22 )
{
struct V_11 * V_12 = F_8 ( V_22 ) ;
struct V_9 * V_10 = V_12 -> V_10 ;
enum V_23 V_19 = V_12 -> V_24 . V_19 ;
int V_3 ;
switch ( V_19 ) {
case 0 :
V_3 = F_3 ( V_10 , V_12 , V_25 ) ;
break;
case V_26 :
V_3 = F_3 ( V_10 , V_12 , V_27 ) ;
break;
default:
V_3 = F_3 ( V_10 , V_12 , V_28 ) ;
if ( ! V_3 )
V_3 = F_5 ( V_10 , V_12 , V_19 ) ;
}
if ( V_3 )
F_9 ( V_12 -> V_24 . V_29 , L_1 ) ;
}
static void
F_10 ( struct V_30 * V_31 ,
enum V_23 V_19 )
{
struct V_11 * V_12 = F_11 ( V_31 ) ;
V_12 -> V_24 . V_19 = V_19 ;
F_12 ( & V_12 -> V_22 ) ;
}
static void
F_13 ( struct V_9 * V_10 , unsigned int V_32 )
{
int V_13 = V_32 ;
while ( -- V_13 >= 0 ) {
if ( V_10 -> V_33 [ V_13 ] . V_34 ) {
F_14 ( & V_10 -> V_33 [ V_13 ] . V_24 ) ;
F_15 ( & V_10 -> V_33 [ V_13 ] . V_22 ) ;
}
}
}
static int
F_16 ( struct V_35 * V_29 ,
struct V_9 * V_10 ,
const struct V_36 * V_36 )
{
unsigned int V_13 ;
int V_3 = 0 ;
F_1 ( V_10 -> V_1 , V_37 ) ;
for ( V_13 = 0 ; V_13 < V_38 ; V_13 ++ ) {
struct V_11 * V_12 = & V_10 -> V_33 [ V_13 ] ;
if ( ! V_12 -> V_34 )
continue;
V_12 -> V_10 = V_10 ;
V_12 -> V_14 = V_13 ;
V_12 -> V_24 . V_39 = F_10 ;
V_12 -> V_24 . V_40 = V_26 ;
F_17 ( & V_12 -> V_22 , F_7 ) ;
V_3 = F_18 ( V_29 , & V_12 -> V_24 ) ;
if ( V_3 < 0 ) {
F_9 ( V_29 , L_2 ,
V_12 -> V_24 . V_41 ) ;
goto exit;
}
}
return 0 ;
exit:
F_13 ( V_10 , V_13 ) ;
return V_3 ;
}
static int
F_19 ( struct V_42 * V_43 ,
const struct V_44 * V_45 )
{
struct V_46 * V_47 = V_43 -> V_29 . V_48 , * V_49 ;
struct V_35 * V_29 = & V_43 -> V_29 ;
const struct V_50 * V_51 ;
const struct V_36 * V_36 ;
struct V_9 * V_10 ;
int V_3 , V_52 , V_53 ;
V_51 = F_20 ( V_54 , V_29 ) ;
if ( ! V_51 )
return - V_55 ;
V_36 = V_51 -> V_56 ;
if ( ! V_47 )
return - V_55 ;
V_52 = F_21 ( V_47 ) ;
if ( ! V_52 || V_52 > V_36 -> V_57 )
return - V_58 ;
if ( ! F_22 ( V_43 -> V_59 ,
V_60 ) )
return - V_61 ;
V_10 = F_23 ( V_29 , sizeof( * V_10 ) , V_62 ) ;
if ( ! V_10 )
return - V_63 ;
V_10 -> V_1 = F_24 ( V_43 , & V_64 ) ;
if ( F_25 ( V_10 -> V_1 ) ) {
V_3 = F_26 ( V_10 -> V_1 ) ;
F_9 ( V_29 , L_3 , V_3 ) ;
return V_3 ;
}
V_10 -> V_18 = V_36 -> V_18 ;
F_27 ( V_43 , V_10 ) ;
F_28 (np, child) {
V_3 = F_29 ( V_49 , L_4 , & V_53 ) ;
if ( V_3 )
return V_3 ;
if ( V_53 < 0 || V_53 >= V_36 -> V_57 )
return - V_58 ;
if ( V_10 -> V_33 [ V_53 ] . V_34 )
return - V_58 ;
V_10 -> V_33 [ V_53 ] . V_34 = true ;
V_10 -> V_33 [ V_53 ] . V_24 . V_41 =
F_30 ( V_49 , L_5 , NULL ) ? : V_49 -> V_41 ;
V_10 -> V_33 [ V_53 ] . V_24 . V_65 =
F_30 ( V_49 , L_6 , NULL ) ;
}
return F_16 ( V_29 , V_10 , V_36 ) ;
}
static int
F_31 ( struct V_42 * V_43 )
{
struct V_9 * V_10 = F_32 ( V_43 ) ;
F_13 ( V_10 , V_38 ) ;
return 0 ;
}
