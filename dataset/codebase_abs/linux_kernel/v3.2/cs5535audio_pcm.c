static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
V_7 -> V_8 = V_9 ;
V_7 -> V_8 . V_10 = V_5 -> V_11 -> V_10 [ V_12 ] ;
F_3 ( V_7 ) ;
V_5 -> V_13 = V_2 ;
V_7 -> V_14 = & ( V_5 -> V_15 [ V_16 ] ) ;
if ( ( V_3 = F_4 ( V_7 ,
V_17 ) ) < 0 )
return V_3 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_6 ( struct V_4 * V_5 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
unsigned int V_20 ,
unsigned int V_21 )
{
unsigned int V_22 ;
T_1 V_23 , V_24 , V_25 ;
struct V_26 * V_27 ;
if ( V_20 > V_28 )
return - V_29 ;
if ( V_19 -> V_30 . V_31 == NULL ) {
if ( F_7 ( V_32 ,
F_8 ( V_5 -> V_33 ) ,
V_34 + 1 ,
& V_19 -> V_30 ) < 0 )
return - V_29 ;
V_19 -> V_21 = V_19 -> V_20 = 0 ;
}
if ( V_19 -> V_20 == V_20 && V_19 -> V_21 == V_21 )
return 0 ;
V_23 = ( T_1 ) V_2 -> V_7 -> V_35 ;
V_24 = ( T_1 ) V_19 -> V_30 . V_23 ;
for ( V_22 = 0 ; V_22 < V_20 ; V_22 ++ ) {
struct V_26 * V_36 =
& ( (struct V_26 * ) V_19 -> V_30 . V_31 ) [ V_22 ] ;
V_36 -> V_23 = F_9 ( V_23 ) ;
V_36 -> V_37 = F_10 ( V_21 ) ;
V_36 -> V_38 = F_10 ( V_39 ) ;
V_24 += sizeof( struct V_26 ) ;
V_23 += V_21 ;
}
V_27 = & ( (struct V_26 * ) V_19 -> V_30 . V_31 ) [ V_20 ] ;
V_27 -> V_23 = F_9 ( ( T_1 ) V_19 -> V_30 . V_23 ) ;
V_27 -> V_37 = 0 ;
V_27 -> V_38 = F_10 ( V_40 ) ;
V_25 = F_9 ( V_27 -> V_23 +
( sizeof( struct V_26 ) * V_20 ) ) ;
V_19 -> V_2 = V_2 ;
V_19 -> V_21 = V_21 ;
V_19 -> V_20 = V_20 ;
F_11 ( & V_5 -> V_41 ) ;
V_19 -> V_42 -> V_43 ( V_5 ) ;
V_19 -> V_42 -> V_44 ( V_5 , V_25 ) ;
F_12 ( & V_5 -> V_41 ) ;
return 0 ;
}
static void F_13 ( struct V_4 * V_5 )
{
F_14 ( V_5 , V_45 , V_46 ) ;
}
static void F_15 ( struct V_4 * V_5 )
{
F_14 ( V_5 , V_45 , 0 ) ;
}
static void F_16 ( struct V_4 * V_5 )
{
F_14 ( V_5 , V_45 , V_47 ) ;
}
static void F_17 ( struct V_4 * V_5 ,
T_1 V_48 )
{
F_18 ( V_5 , V_49 , V_48 ) ;
}
static T_1 F_19 ( struct V_4 * V_5 )
{
return F_20 ( V_5 , V_49 ) ;
}
static T_1 F_21 ( struct V_4 * V_5 )
{
return F_20 ( V_5 , V_50 ) ;
}
static void F_22 ( struct V_4 * V_5 )
{
F_14 ( V_5 , V_51 , V_46 ) ;
}
static void F_23 ( struct V_4 * V_5 )
{
F_14 ( V_5 , V_51 , 0 ) ;
}
static void F_24 ( struct V_4 * V_5 )
{
F_14 ( V_5 , V_51 , V_47 ) ;
}
static void F_25 ( struct V_4 * V_5 ,
T_1 V_48 )
{
F_18 ( V_5 , V_52 , V_48 ) ;
}
static T_1 F_26 ( struct V_4 * V_5 )
{
return F_20 ( V_5 , V_52 ) ;
}
static T_1 F_27 ( struct V_4 * V_5 )
{
return F_20 ( V_5 , V_53 ) ;
}
static void F_28 ( struct V_4 * V_5 ,
struct V_18 * V_19 ,
struct V_1 * V_2 )
{
F_29 ( & V_19 -> V_30 ) ;
V_19 -> V_30 . V_31 = NULL ;
V_19 -> V_2 = NULL ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_18 * V_19 = V_2 -> V_7 -> V_14 ;
int V_3 ;
V_3 = F_31 ( V_2 ,
F_32 ( V_55 ) ) ;
if ( V_3 < 0 )
return V_3 ;
V_19 -> V_56 = V_2 -> V_7 -> V_35 ;
V_19 -> V_57 = F_32 ( V_55 ) ;
V_3 = F_6 ( V_5 , V_19 , V_2 ,
F_33 ( V_55 ) ,
F_34 ( V_55 ) ) ;
if ( ! V_3 )
V_19 -> V_58 = 1 ;
return V_3 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_18 * V_19 = V_2 -> V_7 -> V_14 ;
if ( V_19 -> V_58 ) {
if ( V_2 == V_5 -> V_13 )
F_36 ( V_5 -> V_11 ,
V_59 , 0 ) ;
else
F_36 ( V_5 -> V_11 ,
V_60 , 0 ) ;
V_19 -> V_58 = 0 ;
}
F_28 ( V_5 , V_19 , V_2 ) ;
return F_37 ( V_2 ) ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_39 ( V_5 -> V_11 , V_59 ,
V_2 -> V_7 -> V_61 ) ;
}
static int F_40 ( struct V_1 * V_2 , int V_62 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_18 * V_19 = V_2 -> V_7 -> V_14 ;
int V_3 = 0 ;
F_41 ( & V_5 -> V_41 ) ;
switch ( V_62 ) {
case V_63 :
V_19 -> V_42 -> V_64 ( V_5 ) ;
break;
case V_65 :
V_19 -> V_42 -> V_66 ( V_5 ) ;
break;
case V_67 :
V_19 -> V_42 -> V_66 ( V_5 ) ;
break;
case V_68 :
V_19 -> V_42 -> V_66 ( V_5 ) ;
break;
case V_69 :
V_19 -> V_42 -> V_43 ( V_5 ) ;
break;
case V_70 :
V_19 -> V_42 -> V_43 ( V_5 ) ;
break;
default:
F_42 ( V_71 L_1 ) ;
V_3 = - V_72 ;
break;
}
F_43 ( & V_5 -> V_41 ) ;
return V_3 ;
}
static T_2 F_44 ( struct V_1
* V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_73 ;
struct V_18 * V_19 ;
V_19 = V_2 -> V_7 -> V_14 ;
V_73 = V_19 -> V_42 -> V_74 ( V_5 ) ;
if ( V_73 < V_19 -> V_56 ) {
F_42 ( V_71 L_2 ,
V_73 , V_19 -> V_56 ) ;
return 0 ;
}
V_73 -= V_19 -> V_56 ;
if ( V_73 >= V_19 -> V_57 ) {
F_42 ( V_71 L_3 ,
V_73 , V_19 -> V_57 ) ;
return 0 ;
}
return F_45 ( V_2 -> V_7 , V_73 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
V_7 -> V_8 = V_75 ;
V_7 -> V_8 . V_10 = V_5 -> V_11 -> V_10 [ V_76 ] ;
F_3 ( V_7 ) ;
V_5 -> V_77 = V_2 ;
V_7 -> V_14 = & ( V_5 -> V_15 [ V_78 ] ) ;
if ( ( V_3 = F_4 ( V_7 ,
V_17 ) ) < 0 )
return V_3 ;
F_47 ( V_5 -> V_11 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_49 ( V_5 -> V_11 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_39 ( V_5 -> V_11 , V_60 ,
V_2 -> V_7 -> V_61 ) ;
}
int T_3 F_51 ( struct V_4 * V_5 )
{
struct V_79 * V_80 ;
int V_3 ;
V_3 = F_52 ( V_5 -> V_81 , L_4 , 0 , 1 , 1 , & V_80 ) ;
if ( V_3 < 0 )
return V_3 ;
V_5 -> V_15 [ V_16 ] . V_42 =
& V_82 ;
V_5 -> V_15 [ V_78 ] . V_42 =
& V_83 ;
F_53 ( V_80 , V_84 ,
& V_85 ) ;
F_53 ( V_80 , V_86 ,
& V_87 ) ;
V_80 -> V_14 = V_5 ;
V_80 -> V_88 = 0 ;
strcpy ( V_80 -> V_89 , L_4 ) ;
F_54 ( V_80 , V_32 ,
F_8 ( V_5 -> V_33 ) ,
64 * 1024 , 128 * 1024 ) ;
V_5 -> V_80 = V_80 ;
return 0 ;
}
