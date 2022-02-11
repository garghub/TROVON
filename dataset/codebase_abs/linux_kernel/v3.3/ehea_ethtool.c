static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_7 ;
int V_8 ;
V_8 = F_3 ( V_6 ) ;
if ( V_8 )
return V_8 ;
if ( F_4 ( V_2 ) ) {
switch ( V_6 -> V_9 ) {
case V_10 :
V_7 = V_11 ;
break;
case V_12 :
V_7 = V_13 ;
break;
case V_14 :
V_7 = V_15 ;
break;
case V_16 :
V_7 = V_17 ;
break;
default:
V_7 = - 1 ;
break;
}
V_4 -> V_18 = V_6 -> V_19 == 1 ?
V_20 : V_21 ;
} else {
V_7 = ~ 0 ;
V_4 -> V_18 = - 1 ;
}
F_5 ( V_4 , V_7 ) ;
if ( V_4 -> V_7 == V_17 ) {
V_4 -> V_22 = ( V_23 | V_24 ) ;
V_4 -> V_25 = ( V_26 | V_27 ) ;
V_4 -> V_6 = V_28 ;
} else {
V_4 -> V_22 = ( V_29 | V_30
| V_31 | V_32
| V_33 | V_34
| V_35 ) ;
V_4 -> V_25 = ( V_36 | V_37
| V_38 ) ;
V_4 -> V_6 = V_39 ;
}
V_4 -> V_40 = V_6 -> V_40 == 1 ? V_41 : V_42 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_8 = 0 ;
T_1 V_43 ;
if ( V_4 -> V_40 == V_41 ) {
V_43 = V_44 ;
goto V_45;
}
switch ( V_4 -> V_7 ) {
case V_11 :
if ( V_4 -> V_18 == V_20 )
V_43 = V_46 ;
else
V_43 = V_47 ;
break;
case V_13 :
if ( V_4 -> V_18 == V_20 )
V_43 = V_48 ;
else
V_43 = V_49 ;
break;
case V_15 :
if ( V_4 -> V_18 == V_20 )
V_43 = V_50 ;
else
V_8 = - V_51 ;
break;
case V_17 :
if ( V_4 -> V_18 == V_20 )
V_43 = V_52 ;
else
V_8 = - V_51 ;
break;
default:
V_8 = - V_51 ;
break;
}
if ( V_8 )
goto V_53;
V_45:
V_8 = F_7 ( V_6 , V_43 ) ;
if ( ! V_8 )
F_8 ( V_2 ,
L_1 ,
V_6 -> V_9 ,
V_6 -> V_19 == 1 ? L_2 : L_3 ) ;
V_53:
return V_8 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_8 ;
V_8 = F_7 ( V_6 , V_44 ) ;
if ( ! V_8 )
F_8 ( V_6 -> V_54 ,
L_1 ,
V_6 -> V_9 ,
V_6 -> V_19 == 1 ? L_2 : L_3 ) ;
return V_8 ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
F_11 ( V_56 -> V_57 , V_58 , sizeof( V_56 -> V_57 ) ) ;
F_11 ( V_56 -> V_59 , V_60 , sizeof( V_56 -> V_59 ) ) ;
}
static T_1 F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_61 ;
}
static void F_13 ( struct V_1 * V_2 , T_1 V_62 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_61 = V_62 ;
}
static void F_14 ( struct V_1 * V_2 , T_1 V_63 , T_2 * V_64 )
{
if ( V_63 == V_65 ) {
memcpy ( V_64 , & V_66 ,
sizeof( V_66 ) ) ;
}
}
static int F_15 ( struct V_1 * V_2 , int V_67 )
{
switch ( V_67 ) {
case V_65 :
return F_16 ( V_66 ) ;
default:
return - V_68 ;
}
}
static void F_17 ( struct V_1 * V_2 ,
struct V_69 * V_70 , T_3 * V_64 )
{
int V_71 , V_72 , V_73 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
for ( V_71 = 0 ; V_71 < F_15 ( V_2 , V_65 ) ; V_71 ++ )
V_64 [ V_71 ] = 0 ;
V_71 = 0 ;
V_64 [ V_71 ++ ] = V_6 -> V_74 ;
V_64 [ V_71 ++ ] = V_6 -> V_75 [ 0 ] . V_76 ;
V_64 [ V_71 ++ ] = V_6 -> V_77 ;
for ( V_72 = 0 , V_73 = 0 ; V_72 < V_78 ; V_72 ++ )
V_73 += V_6 -> V_75 [ V_72 ] . V_79 . V_80 ;
V_64 [ V_71 ++ ] = V_73 ;
for ( V_72 = 0 , V_73 = 0 ; V_72 < V_78 ; V_72 ++ )
V_73 += V_6 -> V_75 [ V_72 ] . V_79 . V_81 ;
V_64 [ V_71 ++ ] = V_73 ;
for ( V_72 = 0 , V_73 = 0 ; V_72 < V_78 ; V_72 ++ )
V_73 += V_6 -> V_75 [ V_72 ] . V_79 . V_82 ;
V_64 [ V_71 ++ ] = V_73 ;
for ( V_72 = 0 , V_73 = 0 ; V_72 < V_78 ; V_72 ++ )
V_73 += V_6 -> V_75 [ V_72 ] . V_79 . V_83 ;
V_64 [ V_71 ++ ] = V_73 ;
for ( V_72 = 0 , V_73 = 0 ; V_72 < V_78 ; V_72 ++ )
V_73 += V_6 -> V_75 [ V_72 ] . V_79 . V_84 ;
V_64 [ V_71 ++ ] = V_73 ;
for ( V_72 = 0 ; V_72 < 16 ; V_72 ++ )
V_64 [ V_71 ++ ] = F_18 ( & V_6 -> V_75 [ V_72 ] . V_85 ) ;
}
void F_19 ( struct V_1 * V_54 )
{
F_20 ( V_54 , & V_86 ) ;
}
