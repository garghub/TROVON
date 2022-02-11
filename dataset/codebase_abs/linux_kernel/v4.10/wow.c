static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 , V_6 ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ ) {
V_6 = F_2 ( V_4 , V_2 -> V_8 , V_5 , 0 ) ;
if ( V_6 ) {
F_3 ( V_4 , L_1 ,
F_4 ( V_5 ) , V_2 -> V_8 , V_6 ) ;
return V_6 ;
}
}
for ( V_5 = 0 ; V_5 < V_4 -> V_9 . V_10 ; V_5 ++ ) {
V_6 = F_5 ( V_4 , V_2 -> V_8 , V_5 ) ;
if ( V_6 ) {
F_3 ( V_4 , L_2 ,
V_5 , V_2 -> V_8 , V_6 ) ;
return V_6 ;
}
}
return 0 ;
}
static int F_6 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_6 ;
F_7 ( & V_4 -> V_11 ) ;
F_8 (arvif, &ar->arvifs, list) {
V_6 = F_1 ( V_2 ) ;
if ( V_6 ) {
F_3 ( V_4 , L_3 ,
V_2 -> V_8 , V_6 ) ;
return V_6 ;
}
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
int V_6 , V_5 ;
unsigned long V_14 = 0 ;
struct V_3 * V_4 = V_2 -> V_4 ;
const struct V_15 * V_16 = V_13 -> V_16 ;
int V_17 = 0 ;
switch ( V_2 -> V_18 ) {
case V_19 :
F_10 ( V_20 , & V_14 ) ;
case V_21 :
F_10 ( V_22 , & V_14 ) ;
F_10 ( V_23 , & V_14 ) ;
F_10 ( V_24 , & V_14 ) ;
F_10 ( V_25 , & V_14 ) ;
F_10 ( V_26 , & V_14 ) ;
F_10 ( V_27 , & V_14 ) ;
F_10 ( V_28 , & V_14 ) ;
break;
case V_29 :
if ( V_13 -> V_30 ) {
F_10 ( V_22 , & V_14 ) ;
F_10 ( V_23 , & V_14 ) ;
F_10 ( V_31 , & V_14 ) ;
F_10 ( V_32 , & V_14 ) ;
}
if ( V_13 -> V_33 )
F_10 ( V_34 , & V_14 ) ;
break;
default:
break;
}
for ( V_5 = 0 ; V_5 < V_13 -> V_35 ; V_5 ++ ) {
T_1 V_36 [ V_37 ] = {} ;
int V_38 ;
if ( V_16 [ V_5 ] . V_39 > V_37 )
continue;
for ( V_38 = 0 ; V_38 < V_16 [ V_5 ] . V_39 ; V_38 ++ )
if ( V_16 [ V_5 ] . V_40 [ V_38 / 8 ] & F_11 ( V_38 % 8 ) )
V_36 [ V_38 ] = 0xff ;
V_6 = F_12 ( V_4 , V_2 -> V_8 ,
V_17 ,
V_16 [ V_5 ] . V_41 ,
V_36 ,
V_16 [ V_5 ] . V_39 ,
V_16 [ V_5 ] . V_42 ) ;
if ( V_6 ) {
F_3 ( V_4 , L_4 ,
V_17 ,
V_2 -> V_8 , V_6 ) ;
return V_6 ;
}
V_17 ++ ;
F_10 ( V_43 , & V_14 ) ;
}
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ ) {
if ( ! F_13 ( V_5 , & V_14 ) )
continue;
V_6 = F_2 ( V_4 , V_2 -> V_8 , V_5 , 1 ) ;
if ( V_6 ) {
F_3 ( V_4 , L_5 ,
F_4 ( V_5 ) , V_2 -> V_8 , V_6 ) ;
return V_6 ;
}
}
return 0 ;
}
static int F_14 ( struct V_3 * V_4 ,
struct V_12 * V_13 )
{
struct V_1 * V_2 ;
int V_6 ;
F_7 ( & V_4 -> V_11 ) ;
F_8 (arvif, &ar->arvifs, list) {
V_6 = F_9 ( V_2 , V_13 ) ;
if ( V_6 ) {
F_3 ( V_4 , L_6 ,
V_2 -> V_8 , V_6 ) ;
return V_6 ;
}
}
return 0 ;
}
static int F_15 ( struct V_3 * V_4 )
{
int V_6 ;
F_7 ( & V_4 -> V_11 ) ;
F_16 ( & V_4 -> V_44 ) ;
V_6 = F_17 ( V_4 ) ;
if ( V_6 ) {
F_3 ( V_4 , L_7 , V_6 ) ;
return V_6 ;
}
V_6 = F_18 ( & V_4 -> V_44 , 3 * V_45 ) ;
if ( V_6 == 0 ) {
F_3 ( V_4 , L_8 ) ;
return - V_46 ;
}
return 0 ;
}
static int F_19 ( struct V_3 * V_4 )
{
int V_6 ;
F_7 ( & V_4 -> V_11 ) ;
F_16 ( & V_4 -> V_9 . V_47 ) ;
V_6 = F_20 ( V_4 ) ;
if ( V_6 ) {
F_3 ( V_4 , L_9 ,
V_6 ) ;
return V_6 ;
}
V_6 = F_18 ( & V_4 -> V_9 . V_47 , 3 * V_45 ) ;
if ( V_6 == 0 ) {
F_3 ( V_4 , L_10 ) ;
return - V_46 ;
}
return 0 ;
}
int F_21 ( struct V_48 * V_49 ,
struct V_12 * V_13 )
{
struct V_3 * V_4 = V_49 -> V_50 ;
int V_6 ;
F_22 ( & V_4 -> V_11 ) ;
if ( F_23 ( ! F_13 ( V_51 ,
V_4 -> V_52 -> V_53 . V_54 ) ) ) {
V_6 = 1 ;
goto exit;
}
V_6 = F_6 ( V_4 ) ;
if ( V_6 ) {
F_3 ( V_4 , L_11 ,
V_6 ) ;
goto exit;
}
V_6 = F_14 ( V_4 , V_13 ) ;
if ( V_6 ) {
F_3 ( V_4 , L_12 ,
V_6 ) ;
goto V_55;
}
V_6 = F_15 ( V_4 ) ;
if ( V_6 ) {
F_3 ( V_4 , L_13 , V_6 ) ;
goto V_55;
}
V_6 = F_24 ( V_4 ) ;
if ( V_6 ) {
F_3 ( V_4 , L_14 , V_6 ) ;
goto V_56;
}
goto exit;
V_56:
F_19 ( V_4 ) ;
V_55:
F_6 ( V_4 ) ;
exit:
F_25 ( & V_4 -> V_11 ) ;
return V_6 ? 1 : 0 ;
}
int F_26 ( struct V_48 * V_49 )
{
struct V_3 * V_4 = V_49 -> V_50 ;
int V_6 ;
F_22 ( & V_4 -> V_11 ) ;
if ( F_23 ( ! F_13 ( V_51 ,
V_4 -> V_52 -> V_53 . V_54 ) ) ) {
V_6 = 1 ;
goto exit;
}
V_6 = F_27 ( V_4 ) ;
if ( V_6 ) {
F_3 ( V_4 , L_15 , V_6 ) ;
goto exit;
}
V_6 = F_19 ( V_4 ) ;
if ( V_6 )
F_3 ( V_4 , L_16 , V_6 ) ;
exit:
if ( V_6 ) {
switch ( V_4 -> V_57 ) {
case V_58 :
V_4 -> V_57 = V_59 ;
V_6 = 1 ;
break;
case V_60 :
case V_59 :
case V_61 :
case V_62 :
case V_63 :
F_3 ( V_4 , L_17 ,
V_4 -> V_57 ) ;
V_6 = - V_64 ;
break;
}
}
F_25 ( & V_4 -> V_11 ) ;
return V_6 ;
}
int F_28 ( struct V_3 * V_4 )
{
if ( ! F_13 ( V_51 ,
V_4 -> V_52 -> V_53 . V_54 ) )
return 0 ;
if ( F_23 ( ! F_13 ( V_65 , V_4 -> V_66 . V_67 ) ) )
return - V_68 ;
V_4 -> V_9 . V_69 = V_70 ;
V_4 -> V_9 . V_69 . V_35 = V_4 -> V_9 . V_10 ;
V_4 -> V_49 -> V_71 -> V_13 = & V_4 -> V_9 . V_69 ;
return 0 ;
}
