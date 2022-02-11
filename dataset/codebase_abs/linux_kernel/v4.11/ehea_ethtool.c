static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_7 , V_8 ;
T_1 V_9 ;
int V_10 ;
V_10 = F_3 ( V_6 ) ;
if ( V_10 )
return V_10 ;
if ( F_4 ( V_2 ) ) {
switch ( V_6 -> V_11 ) {
case V_12 :
V_9 = V_13 ;
break;
case V_14 :
V_9 = V_15 ;
break;
case V_16 :
V_9 = V_17 ;
break;
case V_18 :
V_9 = V_19 ;
break;
default:
V_9 = - 1 ;
break;
}
V_4 -> V_20 . V_21 = V_6 -> V_22 == 1 ?
V_23 : V_24 ;
} else {
V_9 = V_25 ;
V_4 -> V_20 . V_21 = V_26 ;
}
V_4 -> V_20 . V_9 = V_9 ;
if ( V_4 -> V_20 . V_9 == V_19 ) {
V_7 = ( V_27 | V_28 ) ;
V_8 = ( V_29 | V_30 ) ;
V_4 -> V_20 . V_6 = V_31 ;
} else {
V_7 = ( V_32 | V_33
| V_34 | V_35
| V_36 | V_37
| V_38 ) ;
V_8 = ( V_39 | V_40
| V_41 ) ;
V_4 -> V_20 . V_6 = V_42 ;
}
V_4 -> V_20 . V_43 = V_6 -> V_43 == 1 ?
V_44 : V_45 ;
F_5 ( V_4 -> V_46 . V_7 ,
V_7 ) ;
F_5 ( V_4 -> V_46 . V_8 ,
V_8 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_10 = 0 ;
T_1 V_47 ;
if ( V_4 -> V_20 . V_43 == V_44 ) {
V_47 = V_48 ;
goto V_49;
}
switch ( V_4 -> V_20 . V_9 ) {
case V_13 :
if ( V_4 -> V_20 . V_21 == V_23 )
V_47 = V_50 ;
else
V_47 = V_51 ;
break;
case V_15 :
if ( V_4 -> V_20 . V_21 == V_23 )
V_47 = V_52 ;
else
V_47 = V_53 ;
break;
case V_17 :
if ( V_4 -> V_20 . V_21 == V_23 )
V_47 = V_54 ;
else
V_10 = - V_55 ;
break;
case V_19 :
if ( V_4 -> V_20 . V_21 == V_23 )
V_47 = V_56 ;
else
V_10 = - V_55 ;
break;
default:
V_10 = - V_55 ;
break;
}
if ( V_10 )
goto V_57;
V_49:
V_10 = F_7 ( V_6 , V_47 ) ;
if ( ! V_10 )
F_8 ( V_2 ,
L_1 ,
V_6 -> V_11 ,
V_6 -> V_22 == 1 ? L_2 : L_3 ) ;
V_57:
return V_10 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_10 ;
V_10 = F_7 ( V_6 , V_48 ) ;
if ( ! V_10 )
F_8 ( V_6 -> V_58 ,
L_1 ,
V_6 -> V_11 ,
V_6 -> V_22 == 1 ? L_2 : L_3 ) ;
return V_10 ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
F_11 ( V_60 -> V_61 , V_62 , sizeof( V_60 -> V_61 ) ) ;
F_11 ( V_60 -> V_63 , V_64 , sizeof( V_60 -> V_63 ) ) ;
}
static T_1 F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_65 ;
}
static void F_13 ( struct V_1 * V_2 , T_1 V_66 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_65 = V_66 ;
}
static void F_14 ( struct V_1 * V_2 , T_1 V_67 , T_2 * V_68 )
{
if ( V_67 == V_69 ) {
memcpy ( V_68 , & V_70 ,
sizeof( V_70 ) ) ;
}
}
static int F_15 ( struct V_1 * V_2 , int V_71 )
{
switch ( V_71 ) {
case V_69 :
return F_16 ( V_70 ) ;
default:
return - V_72 ;
}
}
static void F_17 ( struct V_1 * V_2 ,
struct V_73 * V_74 , T_3 * V_68 )
{
int V_75 , V_76 , V_77 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
for ( V_75 = 0 ; V_75 < F_15 ( V_2 , V_69 ) ; V_75 ++ )
V_68 [ V_75 ] = 0 ;
V_75 = 0 ;
V_68 [ V_75 ++ ] = V_6 -> V_78 ;
V_68 [ V_75 ++ ] = V_6 -> V_79 [ 0 ] . V_80 ;
V_68 [ V_75 ++ ] = V_6 -> V_81 ;
for ( V_76 = 0 , V_77 = 0 ; V_76 < V_82 ; V_76 ++ )
V_77 += V_6 -> V_79 [ V_76 ] . V_83 . V_84 ;
V_68 [ V_75 ++ ] = V_77 ;
for ( V_76 = 0 , V_77 = 0 ; V_76 < V_82 ; V_76 ++ )
V_77 += V_6 -> V_79 [ V_76 ] . V_83 . V_85 ;
V_68 [ V_75 ++ ] = V_77 ;
for ( V_76 = 0 , V_77 = 0 ; V_76 < V_82 ; V_76 ++ )
V_77 += V_6 -> V_79 [ V_76 ] . V_83 . V_86 ;
V_68 [ V_75 ++ ] = V_77 ;
for ( V_76 = 0 , V_77 = 0 ; V_76 < V_82 ; V_76 ++ )
V_77 += V_6 -> V_79 [ V_76 ] . V_83 . V_87 ;
V_68 [ V_75 ++ ] = V_77 ;
for ( V_76 = 0 , V_77 = 0 ; V_76 < V_82 ; V_76 ++ )
V_77 += V_6 -> V_79 [ V_76 ] . V_83 . V_88 ;
V_68 [ V_75 ++ ] = V_77 ;
for ( V_76 = 0 ; V_76 < 16 ; V_76 ++ )
V_68 [ V_75 ++ ] = F_18 ( & V_6 -> V_79 [ V_76 ] . V_89 ) ;
}
void F_19 ( struct V_1 * V_58 )
{
V_58 -> V_90 = & V_91 ;
}
