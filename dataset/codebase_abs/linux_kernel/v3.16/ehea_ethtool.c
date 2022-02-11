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
V_7 = V_22 ;
V_4 -> V_18 = V_23 ;
}
F_5 ( V_4 , V_7 ) ;
if ( V_4 -> V_7 == V_17 ) {
V_4 -> V_24 = ( V_25 | V_26 ) ;
V_4 -> V_27 = ( V_28 | V_29 ) ;
V_4 -> V_6 = V_30 ;
} else {
V_4 -> V_24 = ( V_31 | V_32
| V_33 | V_34
| V_35 | V_36
| V_37 ) ;
V_4 -> V_27 = ( V_38 | V_39
| V_40 ) ;
V_4 -> V_6 = V_41 ;
}
V_4 -> V_42 = V_6 -> V_42 == 1 ? V_43 : V_44 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_8 = 0 ;
T_1 V_45 ;
if ( V_4 -> V_42 == V_43 ) {
V_45 = V_46 ;
goto V_47;
}
switch ( V_4 -> V_7 ) {
case V_11 :
if ( V_4 -> V_18 == V_20 )
V_45 = V_48 ;
else
V_45 = V_49 ;
break;
case V_13 :
if ( V_4 -> V_18 == V_20 )
V_45 = V_50 ;
else
V_45 = V_51 ;
break;
case V_15 :
if ( V_4 -> V_18 == V_20 )
V_45 = V_52 ;
else
V_8 = - V_53 ;
break;
case V_17 :
if ( V_4 -> V_18 == V_20 )
V_45 = V_54 ;
else
V_8 = - V_53 ;
break;
default:
V_8 = - V_53 ;
break;
}
if ( V_8 )
goto V_55;
V_47:
V_8 = F_7 ( V_6 , V_45 ) ;
if ( ! V_8 )
F_8 ( V_2 ,
L_1 ,
V_6 -> V_9 ,
V_6 -> V_19 == 1 ? L_2 : L_3 ) ;
V_55:
return V_8 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_8 ;
V_8 = F_7 ( V_6 , V_46 ) ;
if ( ! V_8 )
F_8 ( V_6 -> V_56 ,
L_1 ,
V_6 -> V_9 ,
V_6 -> V_19 == 1 ? L_2 : L_3 ) ;
return V_8 ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_57 * V_58 )
{
F_11 ( V_58 -> V_59 , V_60 , sizeof( V_58 -> V_59 ) ) ;
F_11 ( V_58 -> V_61 , V_62 , sizeof( V_58 -> V_61 ) ) ;
}
static T_1 F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_63 ;
}
static void F_13 ( struct V_1 * V_2 , T_1 V_64 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_63 = V_64 ;
}
static void F_14 ( struct V_1 * V_2 , T_1 V_65 , T_2 * V_66 )
{
if ( V_65 == V_67 ) {
memcpy ( V_66 , & V_68 ,
sizeof( V_68 ) ) ;
}
}
static int F_15 ( struct V_1 * V_2 , int V_69 )
{
switch ( V_69 ) {
case V_67 :
return F_16 ( V_68 ) ;
default:
return - V_70 ;
}
}
static void F_17 ( struct V_1 * V_2 ,
struct V_71 * V_72 , T_3 * V_66 )
{
int V_73 , V_74 , V_75 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
for ( V_73 = 0 ; V_73 < F_15 ( V_2 , V_67 ) ; V_73 ++ )
V_66 [ V_73 ] = 0 ;
V_73 = 0 ;
V_66 [ V_73 ++ ] = V_6 -> V_76 ;
V_66 [ V_73 ++ ] = V_6 -> V_77 [ 0 ] . V_78 ;
V_66 [ V_73 ++ ] = V_6 -> V_79 ;
for ( V_74 = 0 , V_75 = 0 ; V_74 < V_80 ; V_74 ++ )
V_75 += V_6 -> V_77 [ V_74 ] . V_81 . V_82 ;
V_66 [ V_73 ++ ] = V_75 ;
for ( V_74 = 0 , V_75 = 0 ; V_74 < V_80 ; V_74 ++ )
V_75 += V_6 -> V_77 [ V_74 ] . V_81 . V_83 ;
V_66 [ V_73 ++ ] = V_75 ;
for ( V_74 = 0 , V_75 = 0 ; V_74 < V_80 ; V_74 ++ )
V_75 += V_6 -> V_77 [ V_74 ] . V_81 . V_84 ;
V_66 [ V_73 ++ ] = V_75 ;
for ( V_74 = 0 , V_75 = 0 ; V_74 < V_80 ; V_74 ++ )
V_75 += V_6 -> V_77 [ V_74 ] . V_81 . V_85 ;
V_66 [ V_73 ++ ] = V_75 ;
for ( V_74 = 0 , V_75 = 0 ; V_74 < V_80 ; V_74 ++ )
V_75 += V_6 -> V_77 [ V_74 ] . V_81 . V_86 ;
V_66 [ V_73 ++ ] = V_75 ;
for ( V_74 = 0 ; V_74 < 16 ; V_74 ++ )
V_66 [ V_73 ++ ] = F_18 ( & V_6 -> V_77 [ V_74 ] . V_87 ) ;
}
void F_19 ( struct V_1 * V_56 )
{
V_56 -> V_88 = & V_89 ;
}
