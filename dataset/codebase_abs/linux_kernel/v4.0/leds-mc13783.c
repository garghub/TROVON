static unsigned int F_1 ( int V_1 )
{
if ( V_1 >= V_2 && V_1 <= V_3 )
return 0x0f ;
else if ( V_1 >= V_4 && V_1 <= V_5 )
return 0x1f ;
return 0x3f ;
}
static void F_2 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_3 ( V_7 , struct V_8 , V_7 ) ;
struct V_10 * V_11 = V_9 -> V_11 ;
unsigned int V_12 , V_13 , V_14 , V_15 ;
switch ( V_9 -> V_1 ) {
case V_2 :
case V_16 :
case V_3 :
V_12 = 2 ;
V_15 = 9 + ( V_9 -> V_1 - V_2 ) * 4 ;
break;
case V_4 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_5 :
V_14 = V_9 -> V_1 - V_4 ;
V_13 = V_14 / 3 ;
V_12 = 3 + V_13 ;
V_15 = ( V_14 - V_13 * 3 ) * 5 + 6 ;
break;
case V_24 :
case V_25 :
case V_26 :
V_12 = ( V_9 -> V_1 - V_24 ) / 2 ;
V_15 = 3 + ( V_9 -> V_1 - V_24 ) * 12 ;
break;
case V_27 :
case V_28 :
case V_29 :
V_14 = V_9 -> V_1 - V_27 ;
V_13 = V_14 / 2 ;
V_12 = 2 + V_13 ;
V_15 = ( V_14 - V_13 * 2 ) * 12 + 3 ;
break;
case V_30 :
case V_31 :
V_12 = 0 ;
V_15 = 3 + ( V_9 -> V_1 - V_30 ) * 12 ;
break;
default:
F_4 () ;
}
F_5 ( V_11 -> V_32 , V_11 -> V_33 -> V_34 + V_12 ,
F_1 ( V_9 -> V_1 ) << V_15 ,
V_9 -> V_35 << V_15 ) ;
}
static void F_6 ( struct V_36 * V_37 ,
enum V_38 V_39 )
{
struct V_8 * V_9 =
F_3 ( V_37 , struct V_8 , V_40 ) ;
V_9 -> V_35 = V_39 ;
F_7 ( & V_9 -> V_7 ) ;
}
static struct V_41 T_1 * F_8 (
struct V_42 * V_43 )
{
struct V_10 * V_11 = F_9 ( V_43 ) ;
struct V_41 * V_44 ;
struct V_45 * V_46 , * V_47 ;
struct V_48 * V_49 = & V_43 -> V_49 ;
int V_50 = 0 , V_51 = - V_52 ;
V_44 = F_10 ( V_49 , sizeof( * V_44 ) , V_53 ) ;
if ( ! V_44 )
return F_11 ( - V_54 ) ;
V_46 = F_12 ( V_49 -> V_46 -> V_55 , L_1 ) ;
if ( ! V_46 )
goto V_56;
V_51 = F_13 ( V_46 , L_2 ,
V_44 -> V_57 ,
V_11 -> V_33 -> V_58 ) ;
if ( V_51 )
goto V_56;
V_44 -> V_59 = F_14 ( V_46 ) ;
V_44 -> V_9 = F_10 ( V_49 , V_44 -> V_59 * sizeof( * V_44 -> V_9 ) ,
V_53 ) ;
if ( ! V_44 -> V_9 ) {
V_51 = - V_54 ;
goto V_56;
}
F_15 (parent, child) {
const char * V_60 ;
T_2 V_61 ;
if ( F_16 ( V_47 , L_3 , & V_61 ) )
continue;
V_44 -> V_9 [ V_50 ] . V_1 = V_11 -> V_33 -> V_62 + V_61 ;
if ( ! F_17 ( V_47 , L_4 , & V_60 ) )
V_44 -> V_9 [ V_50 ] . V_63 = V_60 ;
if ( ! F_17 ( V_47 , L_5 ,
& V_60 ) )
V_44 -> V_9 [ V_50 ] . V_64 = V_60 ;
V_50 ++ ;
}
V_44 -> V_59 = V_50 ;
V_51 = V_50 > 0 ? 0 : - V_52 ;
V_56:
F_18 ( V_46 ) ;
return V_51 ? F_11 ( V_51 ) : V_44 ;
}
static inline struct V_41 T_1 * F_8 (
struct V_42 * V_43 )
{
return F_11 ( - V_65 ) ;
}
static int T_1 F_19 ( struct V_42 * V_43 )
{
struct V_48 * V_49 = & V_43 -> V_49 ;
struct V_41 * V_44 = F_20 ( V_49 ) ;
struct V_66 * V_67 = F_21 ( V_49 -> V_46 ) ;
struct V_68 * V_33 =
(struct V_68 * ) V_43 -> V_69 -> V_70 ;
struct V_10 * V_11 ;
int V_50 , V_1 , V_51 = - V_52 ;
T_2 V_71 = 0 ;
V_11 = F_10 ( V_49 , sizeof( * V_11 ) , V_53 ) ;
if ( ! V_11 )
return - V_54 ;
V_11 -> V_33 = V_33 ;
V_11 -> V_32 = V_67 ;
F_22 ( V_43 , V_11 ) ;
if ( V_49 -> V_46 -> V_55 ) {
V_44 = F_8 ( V_43 ) ;
if ( F_23 ( V_44 ) )
return F_24 ( V_44 ) ;
} else if ( ! V_44 )
return - V_52 ;
V_11 -> V_59 = V_44 -> V_59 ;
if ( ( V_11 -> V_59 < 1 ) ||
( V_11 -> V_59 > ( V_33 -> V_72 - V_33 -> V_62 + 1 ) ) ) {
F_25 ( V_49 , L_6 , V_11 -> V_59 ) ;
return - V_73 ;
}
V_11 -> V_9 = F_10 ( V_49 , V_11 -> V_59 * sizeof( * V_11 -> V_9 ) ,
V_53 ) ;
if ( ! V_11 -> V_9 )
return - V_54 ;
for ( V_50 = 0 ; V_50 < V_33 -> V_58 ; V_50 ++ ) {
V_51 = F_26 ( V_67 , V_11 -> V_33 -> V_34 + V_50 ,
V_44 -> V_57 [ V_50 ] ) ;
if ( V_51 )
return V_51 ;
}
for ( V_50 = 0 ; V_50 < V_11 -> V_59 ; V_50 ++ ) {
const char * V_63 , * V_74 ;
V_51 = - V_73 ;
V_1 = V_44 -> V_9 [ V_50 ] . V_1 ;
V_63 = V_44 -> V_9 [ V_50 ] . V_63 ;
V_74 = V_44 -> V_9 [ V_50 ] . V_64 ;
if ( ( V_1 > V_33 -> V_72 ) || ( V_1 < V_33 -> V_62 ) ) {
F_25 ( V_49 , L_7 , V_1 ) ;
break;
}
if ( V_71 & ( 1 << V_1 ) ) {
F_27 ( V_49 , L_8 , V_1 ) ;
break;
}
V_71 |= 1 << V_1 ;
V_11 -> V_9 [ V_50 ] . V_1 = V_1 ;
V_11 -> V_9 [ V_50 ] . V_11 = V_11 ;
V_11 -> V_9 [ V_50 ] . V_40 . V_63 = V_63 ;
V_11 -> V_9 [ V_50 ] . V_40 . V_64 = V_74 ;
V_11 -> V_9 [ V_50 ] . V_40 . V_75 = V_76 ;
V_11 -> V_9 [ V_50 ] . V_40 . V_77 = F_6 ;
V_11 -> V_9 [ V_50 ] . V_40 . V_78 = F_1 ( V_1 ) ;
F_28 ( & V_11 -> V_9 [ V_50 ] . V_7 , F_2 ) ;
V_51 = F_29 ( V_49 -> V_46 , & V_11 -> V_9 [ V_50 ] . V_40 ) ;
if ( V_51 ) {
F_25 ( V_49 , L_9 , V_1 ) ;
break;
}
}
if ( V_51 )
while ( -- V_50 >= 0 ) {
F_30 ( & V_11 -> V_9 [ V_50 ] . V_40 ) ;
F_31 ( & V_11 -> V_9 [ V_50 ] . V_7 ) ;
}
return V_51 ;
}
static int F_32 ( struct V_42 * V_43 )
{
struct V_10 * V_11 = F_9 ( V_43 ) ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_11 -> V_59 ; V_50 ++ ) {
F_30 ( & V_11 -> V_9 [ V_50 ] . V_40 ) ;
F_31 ( & V_11 -> V_9 [ V_50 ] . V_7 ) ;
}
return 0 ;
}
