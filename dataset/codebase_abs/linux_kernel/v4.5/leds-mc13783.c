static unsigned int F_1 ( int V_1 )
{
if ( V_1 >= V_2 && V_1 <= V_3 )
return 0x0f ;
else if ( V_1 >= V_4 && V_1 <= V_5 )
return 0x1f ;
return 0x3f ;
}
static int F_2 ( struct V_6 * V_7 ,
enum V_8 V_9 )
{
struct V_10 * V_11 =
F_3 ( V_7 , struct V_10 , V_12 ) ;
struct V_13 * V_14 = V_11 -> V_14 ;
unsigned int V_15 , V_16 , V_17 , V_18 ;
switch ( V_11 -> V_1 ) {
case V_2 :
case V_19 :
case V_3 :
V_15 = 2 ;
V_18 = 9 + ( V_11 -> V_1 - V_2 ) * 4 ;
break;
case V_4 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_5 :
V_17 = V_11 -> V_1 - V_4 ;
V_16 = V_17 / 3 ;
V_15 = 3 + V_16 ;
V_18 = ( V_17 - V_16 * 3 ) * 5 + 6 ;
break;
case V_27 :
case V_28 :
case V_29 :
V_15 = ( V_11 -> V_1 - V_27 ) / 2 ;
V_18 = 3 + ( V_11 -> V_1 - V_27 ) * 12 ;
break;
case V_30 :
case V_31 :
case V_32 :
V_17 = V_11 -> V_1 - V_30 ;
V_16 = V_17 / 2 ;
V_15 = 2 + V_16 ;
V_18 = ( V_17 - V_16 * 2 ) * 12 + 3 ;
break;
case V_33 :
case V_34 :
V_15 = 0 ;
V_18 = 3 + ( V_11 -> V_1 - V_33 ) * 12 ;
break;
default:
F_4 () ;
}
return F_5 ( V_14 -> V_35 , V_14 -> V_36 -> V_37 + V_15 ,
F_1 ( V_11 -> V_1 ) << V_18 ,
V_9 << V_18 ) ;
}
static struct V_38 T_1 * F_6 (
struct V_39 * V_40 )
{
struct V_13 * V_14 = F_7 ( V_40 ) ;
struct V_38 * V_41 ;
struct V_42 * V_43 , * V_44 ;
struct V_45 * V_46 = & V_40 -> V_46 ;
int V_47 = 0 , V_48 = - V_49 ;
V_41 = F_8 ( V_46 , sizeof( * V_41 ) , V_50 ) ;
if ( ! V_41 )
return F_9 ( - V_51 ) ;
V_43 = F_10 ( V_46 -> V_43 -> V_52 , L_1 ) ;
if ( ! V_43 )
goto V_53;
V_48 = F_11 ( V_43 , L_2 ,
V_41 -> V_54 ,
V_14 -> V_36 -> V_55 ) ;
if ( V_48 )
goto V_53;
V_41 -> V_56 = F_12 ( V_43 ) ;
V_41 -> V_11 = F_8 ( V_46 , V_41 -> V_56 * sizeof( * V_41 -> V_11 ) ,
V_50 ) ;
if ( ! V_41 -> V_11 ) {
V_48 = - V_51 ;
goto V_53;
}
F_13 (parent, child) {
const char * V_57 ;
T_2 V_58 ;
if ( F_14 ( V_44 , L_3 , & V_58 ) )
continue;
V_41 -> V_11 [ V_47 ] . V_1 = V_14 -> V_36 -> V_59 + V_58 ;
if ( ! F_15 ( V_44 , L_4 , & V_57 ) )
V_41 -> V_11 [ V_47 ] . V_60 = V_57 ;
if ( ! F_15 ( V_44 , L_5 ,
& V_57 ) )
V_41 -> V_11 [ V_47 ] . V_61 = V_57 ;
V_47 ++ ;
}
V_41 -> V_56 = V_47 ;
V_48 = V_47 > 0 ? 0 : - V_49 ;
V_53:
F_16 ( V_43 ) ;
return V_48 ? F_9 ( V_48 ) : V_41 ;
}
static inline struct V_38 T_1 * F_6 (
struct V_39 * V_40 )
{
return F_9 ( - V_62 ) ;
}
static int T_1 F_17 ( struct V_39 * V_40 )
{
struct V_45 * V_46 = & V_40 -> V_46 ;
struct V_38 * V_41 = F_18 ( V_46 ) ;
struct V_63 * V_64 = F_19 ( V_46 -> V_43 ) ;
struct V_65 * V_36 =
(struct V_65 * ) V_40 -> V_66 -> V_67 ;
struct V_13 * V_14 ;
int V_47 , V_1 , V_48 = - V_49 ;
T_2 V_68 = 0 ;
V_14 = F_8 ( V_46 , sizeof( * V_14 ) , V_50 ) ;
if ( ! V_14 )
return - V_51 ;
V_14 -> V_36 = V_36 ;
V_14 -> V_35 = V_64 ;
F_20 ( V_40 , V_14 ) ;
if ( V_46 -> V_43 -> V_52 ) {
V_41 = F_6 ( V_40 ) ;
if ( F_21 ( V_41 ) )
return F_22 ( V_41 ) ;
} else if ( ! V_41 )
return - V_49 ;
V_14 -> V_56 = V_41 -> V_56 ;
if ( ( V_14 -> V_56 < 1 ) ||
( V_14 -> V_56 > ( V_36 -> V_69 - V_36 -> V_59 + 1 ) ) ) {
F_23 ( V_46 , L_6 , V_14 -> V_56 ) ;
return - V_70 ;
}
V_14 -> V_11 = F_8 ( V_46 , V_14 -> V_56 * sizeof( * V_14 -> V_11 ) ,
V_50 ) ;
if ( ! V_14 -> V_11 )
return - V_51 ;
for ( V_47 = 0 ; V_47 < V_36 -> V_55 ; V_47 ++ ) {
V_48 = F_24 ( V_64 , V_14 -> V_36 -> V_37 + V_47 ,
V_41 -> V_54 [ V_47 ] ) ;
if ( V_48 )
return V_48 ;
}
for ( V_47 = 0 ; V_47 < V_14 -> V_56 ; V_47 ++ ) {
const char * V_60 , * V_71 ;
V_48 = - V_70 ;
V_1 = V_41 -> V_11 [ V_47 ] . V_1 ;
V_60 = V_41 -> V_11 [ V_47 ] . V_60 ;
V_71 = V_41 -> V_11 [ V_47 ] . V_61 ;
if ( ( V_1 > V_36 -> V_69 ) || ( V_1 < V_36 -> V_59 ) ) {
F_23 ( V_46 , L_7 , V_1 ) ;
break;
}
if ( V_68 & ( 1 << V_1 ) ) {
F_25 ( V_46 , L_8 , V_1 ) ;
break;
}
V_68 |= 1 << V_1 ;
V_14 -> V_11 [ V_47 ] . V_1 = V_1 ;
V_14 -> V_11 [ V_47 ] . V_14 = V_14 ;
V_14 -> V_11 [ V_47 ] . V_12 . V_60 = V_60 ;
V_14 -> V_11 [ V_47 ] . V_12 . V_61 = V_71 ;
V_14 -> V_11 [ V_47 ] . V_12 . V_72 = V_73 ;
V_14 -> V_11 [ V_47 ] . V_12 . V_74 = F_2 ;
V_14 -> V_11 [ V_47 ] . V_12 . V_75 = F_1 ( V_1 ) ;
V_48 = F_26 ( V_46 -> V_43 , & V_14 -> V_11 [ V_47 ] . V_12 ) ;
if ( V_48 ) {
F_23 ( V_46 , L_9 , V_1 ) ;
break;
}
}
if ( V_48 )
while ( -- V_47 >= 0 )
F_27 ( & V_14 -> V_11 [ V_47 ] . V_12 ) ;
return V_48 ;
}
static int F_28 ( struct V_39 * V_40 )
{
struct V_13 * V_14 = F_7 ( V_40 ) ;
int V_47 ;
for ( V_47 = 0 ; V_47 < V_14 -> V_56 ; V_47 ++ )
F_27 ( & V_14 -> V_11 [ V_47 ] . V_12 ) ;
return 0 ;
}
