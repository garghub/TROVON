static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
int V_4 ;
int V_5 ;
if ( ! V_2 -> V_6 || ! V_2 -> V_7 )
return - V_8 ;
V_3 = F_2 ( V_2 -> V_9 ,
F_3 ( V_2 -> V_9 , V_2 -> V_10 ) ,
V_2 -> V_11 , V_2 -> V_6 , & V_4 ,
V_12 ) ;
if ( ! V_3 ) {
for ( V_5 = 0 ; V_5 < V_2 -> V_7 ; V_5 ++ ) {
int V_13 ;
V_13 = F_2 ( V_2 -> V_9 ,
F_4 ( V_2 -> V_9 ,
V_2 -> V_14 ) ,
V_2 -> V_15 ,
sizeof( V_2 -> V_15 ) , & V_4 ,
V_12 ) ;
if ( V_3 < 0 )
continue;
V_3 = V_13 ;
if ( V_3 == 0 && V_4 > 0 ) {
switch ( V_2 -> V_15 [ V_4 - 1 ] ) {
case V_16 :
V_3 = V_5 == 1 ? - V_17 : - V_18 ;
break;
case V_19 :
V_3 = - V_20 ;
break;
case V_21 :
V_3 = V_4 - 1 ;
break;
default:
V_3 = - V_18 ;
break;
}
}
}
}
V_2 -> V_6 = 0 ;
V_2 -> V_7 = 0 ;
return V_3 ;
}
static int F_5 ( struct V_1 * V_2 , bool V_22 )
{
if ( V_22 || V_2 -> V_6 >= V_23 )
return F_1 ( V_2 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_24 , bool V_22 )
{
V_2 -> V_11 [ V_2 -> V_6 ++ ] = V_24 ;
V_2 -> V_7 ++ ;
return F_5 ( V_2 , V_22 ) ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_24 , T_1 V_25 ,
bool V_22 )
{
V_2 -> V_11 [ V_2 -> V_6 ++ ] = V_24 ;
V_2 -> V_11 [ V_2 -> V_6 ++ ] = V_25 ;
V_2 -> V_7 ++ ;
return F_5 ( V_2 , V_22 ) ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_24 , T_1 V_26 ,
T_1 V_27 , bool V_22 )
{
V_2 -> V_11 [ V_2 -> V_6 ++ ] = V_24 ;
V_2 -> V_11 [ V_2 -> V_6 ++ ] = V_26 ;
V_2 -> V_11 [ V_2 -> V_6 ++ ] = V_27 ;
V_2 -> V_7 ++ ;
return F_5 ( V_2 , V_22 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < 10 ; V_5 ++ ) {
int V_4 = 0 ;
int V_3 ;
V_3 = F_2 ( V_2 -> V_9 ,
F_4 ( V_2 -> V_9 , V_2 -> V_14 ) ,
V_2 -> V_15 , sizeof( V_2 -> V_15 ) , & V_4 ,
V_12 ) ;
if ( V_3 < 0 || V_4 == 0 )
break;
}
if ( V_5 == 10 )
F_10 ( & V_2 -> V_28 -> V_2 , L_1 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
return F_6 ( V_2 , V_29 , false ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
return F_6 ( V_2 , V_30 , false ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
return F_6 ( V_2 , V_31 , true ) ;
}
static int F_14 ( struct V_1 * V_2 , bool V_32 ,
T_1 * V_33 )
{
int V_3 ;
V_3 = F_7 ( V_2 , V_34 , V_32 , true ) ;
if ( V_3 > 0 )
* V_33 = V_2 -> V_15 [ 0 ] ;
else if ( V_3 == 0 )
V_3 = - V_18 ;
return V_3 ;
}
static int F_15 ( struct V_1 * V_2 , T_1 V_33 )
{
return F_7 ( V_2 , V_35 , V_33 , false ) ;
}
static int F_16 ( struct V_1 * V_2 , T_1 V_36 )
{
return F_7 ( V_2 , V_37 , V_36 , true ) ;
}
static int F_17 ( struct V_1 * V_2 , bool V_38 )
{
return F_7 ( V_2 , V_39 , V_38 , true ) ;
}
static int F_18 ( struct V_1 * V_2 , int V_40 )
{
int V_41 = V_40 * 10 ;
return F_8 ( V_2 , V_42 ,
V_41 & 0xff , ( V_41 >> 8 ) & 0xff , true ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_6 ( V_2 , V_43 , true ) ;
if ( V_3 >= 2 )
F_20 ( & V_2 -> V_28 -> V_2 ,
L_2 ,
( unsigned int ) V_2 -> V_15 [ 0 ] ,
( unsigned int ) V_2 -> V_15 [ 1 ] ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
int V_3 ;
T_2 V_44 ;
V_3 = F_6 ( V_2 , V_45 , true ) ;
if ( V_3 >= 4 ) {
V_44 = F_22 ( * ( T_2 * ) V_2 -> V_15 ) ;
F_20 ( & V_2 -> V_28 -> V_2 ,
L_3 , V_44 ) ;
}
}
static int F_23 ( struct V_1 * V_2 )
{
int V_36 , V_3 ;
if ( V_46 >= 200000 ) {
V_36 = V_47 ;
V_46 = V_48 ;
} else if ( V_46 >= 100000 || V_46 == 0 ) {
V_36 = V_49 ;
V_46 = V_50 ;
} else {
V_36 = F_24 ( V_46 ) ;
if ( V_36 > V_51 )
V_36 = V_51 ;
V_46 = F_25 ( V_36 ) ;
}
F_20 ( & V_2 -> V_28 -> V_2 ,
L_4 ,
V_2 -> V_9 -> V_52 -> V_53 , V_2 -> V_9 -> V_54 , V_46 ) ;
F_9 ( V_2 ) ;
F_19 ( V_2 ) ;
F_21 ( V_2 ) ;
V_3 = F_16 ( V_2 , V_36 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_17 ( V_2 , V_36 != V_47 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_36 != V_47 )
V_3 = F_18 ( V_2 , V_55 ) ;
return V_3 ;
}
static int F_26 ( struct V_56 * V_57 , struct V_58 * V_59 ,
int V_60 )
{
struct V_1 * V_2 = F_27 ( V_57 ) ;
struct V_58 * V_61 ;
int V_5 , V_62 ;
int V_3 , V_63 ;
V_3 = F_11 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
for ( V_5 = 0 ; V_5 < V_60 ; V_5 ++ ) {
V_61 = & V_59 [ V_5 ] ;
if ( V_5 ) {
V_3 = F_12 ( V_2 ) ;
if ( V_3 < 0 )
goto abort;
}
if ( V_61 -> V_64 & V_65 ) {
V_3 =
F_15 ( V_2 , ( V_61 -> V_66 << 1 ) | 1 ) ;
if ( V_3 < 0 )
goto abort;
for ( V_62 = 0 ; V_62 < V_61 -> V_67 ; V_62 ++ ) {
T_1 V_33 ;
bool V_32 = V_62 < V_61 -> V_67 - 1 ;
if ( V_62 == 0 && ( V_61 -> V_64 & V_68 ) )
V_32 = true ;
V_3 = F_14 ( V_2 , V_32 , & V_33 ) ;
if ( V_3 < 0 )
goto abort;
if ( V_62 == 0 && ( V_61 -> V_64 & V_68 ) ) {
if ( V_33 == 0
|| V_33 > V_69 ) {
V_3 = - V_70 ;
goto abort;
}
V_61 -> V_67 += V_33 ;
}
V_61 -> V_71 [ V_62 ] = V_33 ;
}
} else {
V_3 = F_15 ( V_2 , V_61 -> V_66 << 1 ) ;
if ( V_3 < 0 )
goto abort;
for ( V_62 = 0 ; V_62 < V_61 -> V_67 ; V_62 ++ ) {
V_3 = F_15 ( V_2 ,
V_61 -> V_71 [ V_62 ] ) ;
if ( V_3 < 0 )
goto abort;
}
}
}
V_3 = V_60 ;
abort:
V_63 = F_13 ( V_2 ) ;
if ( V_63 < 0 && V_3 >= 0 )
V_3 = V_63 ;
return V_3 ;
}
static T_2 F_28 ( struct V_56 * V_72 )
{
return V_73 | V_74 |
V_75 | V_76 ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_30 ( V_2 -> V_9 ) ;
F_31 ( V_2 ) ;
}
static int F_32 ( struct V_77 * V_28 ,
const struct V_78 * V_79 )
{
struct V_80 * V_81 = V_28 -> V_82 ;
struct V_1 * V_2 ;
int V_3 ;
if ( V_81 -> V_83 . V_84 != 0
|| V_81 -> V_83 . V_85 < 2 )
return - V_86 ;
V_2 = F_33 ( sizeof( * V_2 ) , V_87 ) ;
if ( V_2 == NULL ) {
V_3 = - V_88 ;
goto error;
}
V_2 -> V_10 = V_81 -> V_89 [ 0 ] . V_83 . V_90 ;
V_2 -> V_14 = V_81 -> V_89 [ 1 ] . V_83 . V_90 ;
V_2 -> V_9 = F_34 ( F_35 ( V_28 ) ) ;
V_2 -> V_28 = V_28 ;
F_36 ( V_28 , V_2 ) ;
V_2 -> V_57 . V_91 = V_92 ;
V_2 -> V_57 . V_93 = V_94 ;
V_2 -> V_57 . V_95 = & V_96 ;
F_37 ( & V_2 -> V_57 , V_2 ) ;
snprintf ( V_2 -> V_57 . V_97 , sizeof( V_2 -> V_57 . V_97 ) ,
V_98 L_5 ,
V_2 -> V_9 -> V_52 -> V_53 , V_2 -> V_9 -> V_54 ) ;
V_2 -> V_57 . V_2 . V_99 = & V_2 -> V_28 -> V_2 ;
V_3 = F_23 ( V_2 ) ;
if ( V_3 < 0 ) {
F_10 ( & V_28 -> V_2 , L_6 ) ;
goto V_100;
}
V_3 = F_38 ( & V_2 -> V_57 ) ;
if ( V_3 < 0 )
goto V_100;
F_39 ( & V_28 -> V_2 , L_7 V_98 L_8 ) ;
return 0 ;
V_100:
F_36 ( V_28 , NULL ) ;
F_29 ( V_2 ) ;
error:
return V_3 ;
}
static void F_40 ( struct V_77 * V_28 )
{
struct V_1 * V_2 = F_41 ( V_28 ) ;
F_42 ( & V_2 -> V_57 ) ;
F_36 ( V_28 , NULL ) ;
F_29 ( V_2 ) ;
F_39 ( & V_28 -> V_2 , L_9 ) ;
}
