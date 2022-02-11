static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int T_1
F_3 ( struct V_5 * V_6 , struct V_2 * V_3 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_1 * V_9 = F_1 ( V_3 ) ;
int V_10 ;
V_10 = F_4 ( V_6 , V_3 ) ;
if ( V_10 < 0 )
return V_10 ;
V_11 . V_12 = V_10 ;
V_9 -> V_13 = F_5 ( V_8 -> V_14 , & V_15 ) ;
if ( ! V_9 -> V_13 ) {
V_16:
ERROR ( V_8 , L_1 ,
V_3 -> V_17 , V_8 -> V_14 -> V_17 ) ;
return - V_18 ;
}
V_9 -> V_13 -> V_19 = V_8 ;
V_9 -> V_20 = F_5 ( V_8 -> V_14 , & V_21 ) ;
if ( ! V_9 -> V_20 )
goto V_16;
V_9 -> V_20 -> V_19 = V_8 ;
if ( F_6 ( V_6 -> V_8 -> V_14 ) ) {
V_22 . V_23 =
V_15 . V_23 ;
V_24 . V_23 =
V_21 . V_23 ;
V_3 -> V_25 = V_26 ;
}
if ( F_7 ( V_6 -> V_8 -> V_14 ) ) {
V_27 . V_23 =
V_15 . V_23 ;
V_28 . V_23 =
V_21 . V_23 ;
V_3 -> V_29 = V_30 ;
}
F_8 ( V_8 , L_2 ,
( F_7 ( V_6 -> V_8 -> V_14 ) ? L_3 :
( F_6 ( V_6 -> V_8 -> V_14 ) ? L_4 : L_5 ) ) ,
V_3 -> V_17 , V_9 -> V_13 -> V_17 , V_9 -> V_20 -> V_17 ) ;
return 0 ;
}
static void
F_9 ( struct V_5 * V_6 , struct V_2 * V_3 )
{
F_10 ( F_1 ( V_3 ) ) ;
}
static int F_11 ( struct V_1 * V_9 , struct V_31 * V_32 )
{
unsigned V_33 ;
T_2 * V_34 = V_32 -> V_34 ;
struct V_7 * V_8 = V_9 -> V_4 . V_35 -> V_8 ;
for ( V_33 = 0 ; V_33 < V_32 -> V_36 ; V_33 ++ , V_34 ++ ) {
switch ( V_37 ) {
case 0 :
if ( * V_34 == 0 )
continue;
break;
case 1 :
if ( * V_34 == ( T_2 ) ( V_33 % 63 ) )
continue;
break;
}
ERROR ( V_8 , L_6 , V_33 , * V_34 ) ;
F_12 ( V_9 -> V_20 ) ;
return - V_38 ;
}
return 0 ;
}
static void F_13 ( struct V_39 * V_40 , struct V_31 * V_32 )
{
unsigned V_33 ;
T_2 * V_34 = V_32 -> V_34 ;
switch ( V_37 ) {
case 0 :
memset ( V_32 -> V_34 , 0 , V_32 -> V_41 ) ;
break;
case 1 :
for ( V_33 = 0 ; V_33 < V_32 -> V_41 ; V_33 ++ )
* V_34 ++ = ( T_2 ) ( V_33 % 63 ) ;
break;
}
}
static void F_14 ( struct V_39 * V_40 , struct V_31 * V_32 )
{
struct V_1 * V_9 = V_40 -> V_19 ;
struct V_7 * V_8 = V_9 -> V_4 . V_35 -> V_8 ;
int V_42 = V_32 -> V_42 ;
switch ( V_42 ) {
case 0 :
if ( V_40 == V_9 -> V_20 ) {
F_11 ( V_9 , V_32 ) ;
memset ( V_32 -> V_34 , 0x55 , V_32 -> V_41 ) ;
} else
F_13 ( V_40 , V_32 ) ;
break;
case - V_43 :
case - V_44 :
case - V_45 :
F_15 ( V_8 , L_7 , V_40 -> V_17 , V_42 ,
V_32 -> V_36 , V_32 -> V_41 ) ;
if ( V_40 == V_9 -> V_20 )
F_11 ( V_9 , V_32 ) ;
F_16 ( V_40 , V_32 ) ;
return;
case - V_46 :
default:
#if 1
F_8 ( V_8 , L_8 , V_40 -> V_17 ,
V_42 , V_32 -> V_36 , V_32 -> V_41 ) ;
#endif
case - V_47 :
break;
}
V_42 = F_17 ( V_40 , V_32 , V_48 ) ;
if ( V_42 ) {
ERROR ( V_8 , L_9 ,
V_40 -> V_17 , V_32 -> V_41 , V_42 ) ;
F_12 ( V_40 ) ;
}
}
static int F_18 ( struct V_1 * V_9 , bool V_49 )
{
struct V_39 * V_40 ;
struct V_31 * V_32 ;
int V_42 ;
V_40 = V_49 ? V_9 -> V_13 : V_9 -> V_20 ;
V_32 = F_19 ( V_40 ) ;
if ( ! V_32 )
return - V_50 ;
V_32 -> V_51 = F_14 ;
if ( V_49 )
F_13 ( V_40 , V_32 ) ;
else
memset ( V_32 -> V_34 , 0x55 , V_32 -> V_41 ) ;
V_42 = F_17 ( V_40 , V_32 , V_48 ) ;
if ( V_42 ) {
struct V_7 * V_8 ;
V_8 = V_9 -> V_4 . V_35 -> V_8 ;
ERROR ( V_8 , L_10 ,
V_49 ? L_11 : L_12 ,
V_40 -> V_17 , V_42 ) ;
F_16 ( V_40 , V_32 ) ;
}
return V_42 ;
}
static void F_20 ( struct V_1 * V_9 )
{
struct V_7 * V_8 ;
V_8 = V_9 -> V_4 . V_35 -> V_8 ;
F_21 ( V_8 , V_9 -> V_13 , V_9 -> V_20 ) ;
F_15 ( V_8 , L_13 , V_9 -> V_4 . V_17 ) ;
}
static int
F_22 ( struct V_7 * V_8 , struct V_1 * V_9 )
{
int V_52 = 0 ;
struct V_39 * V_40 ;
V_40 = V_9 -> V_13 ;
V_52 = F_23 ( V_8 -> V_14 , & ( V_9 -> V_4 ) , V_40 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_24 ( V_40 ) ;
if ( V_52 < 0 )
return V_52 ;
V_40 -> V_19 = V_9 ;
V_52 = F_18 ( V_9 , true ) ;
if ( V_52 < 0 ) {
V_53:
V_40 = V_9 -> V_13 ;
F_25 ( V_40 ) ;
V_40 -> V_19 = NULL ;
return V_52 ;
}
V_40 = V_9 -> V_20 ;
V_52 = F_23 ( V_8 -> V_14 , & ( V_9 -> V_4 ) , V_40 ) ;
if ( V_52 )
goto V_53;
V_52 = F_24 ( V_40 ) ;
if ( V_52 < 0 )
goto V_53;
V_40 -> V_19 = V_9 ;
V_52 = F_18 ( V_9 , false ) ;
if ( V_52 < 0 ) {
F_25 ( V_40 ) ;
V_40 -> V_19 = NULL ;
goto V_53;
}
F_8 ( V_8 , L_14 , V_9 -> V_4 . V_17 ) ;
return V_52 ;
}
static int F_26 ( struct V_2 * V_3 ,
unsigned V_54 , unsigned V_55 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_7 * V_8 = V_3 -> V_35 -> V_8 ;
if ( V_9 -> V_13 -> V_19 )
F_20 ( V_9 ) ;
return F_22 ( V_8 , V_9 ) ;
}
static void F_27 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_20 ( V_9 ) ;
}
static int T_1 F_28 ( struct V_5 * V_6 )
{
struct V_1 * V_9 ;
int V_42 ;
V_9 = F_29 ( sizeof *V_9 , V_56 ) ;
if ( ! V_9 )
return - V_50 ;
V_9 -> V_4 . V_17 = L_15 ;
V_9 -> V_4 . V_57 = V_58 ;
V_9 -> V_4 . V_59 = F_3 ;
V_9 -> V_4 . V_60 = F_9 ;
V_9 -> V_4 . V_61 = F_26 ;
V_9 -> V_4 . V_62 = F_27 ;
V_42 = F_30 ( V_6 , & V_9 -> V_4 ) ;
if ( V_42 )
F_10 ( V_9 ) ;
return V_42 ;
}
static int F_31 ( struct V_5 * V_6 ,
const struct V_63 * V_64 )
{
struct V_31 * V_32 = V_6 -> V_8 -> V_32 ;
int V_65 = - V_66 ;
T_3 V_67 = F_32 ( V_64 -> V_68 ) ;
T_3 V_69 = F_32 ( V_64 -> V_70 ) ;
T_3 V_71 = F_32 ( V_64 -> V_72 ) ;
V_32 -> V_41 = V_73 ;
switch ( V_64 -> V_74 ) {
case 0x5b :
if ( V_64 -> V_75 != ( V_76 | V_77 ) )
goto V_78;
if ( V_69 || V_67 )
break;
if ( V_71 > V_32 -> V_41 )
break;
V_65 = V_71 ;
break;
case 0x5c :
if ( V_64 -> V_75 != ( V_79 | V_77 ) )
goto V_78;
if ( V_69 || V_67 )
break;
if ( V_71 > V_32 -> V_41 )
break;
V_65 = V_71 ;
break;
default:
V_78:
F_15 ( V_6 -> V_8 ,
L_16 ,
V_64 -> V_75 , V_64 -> V_74 ,
V_69 , V_67 , V_71 ) ;
}
if ( V_65 >= 0 ) {
F_15 ( V_6 -> V_8 , L_17 ,
V_64 -> V_75 , V_64 -> V_74 ,
V_69 , V_67 , V_71 ) ;
V_32 -> V_80 = 0 ;
V_32 -> V_41 = V_65 ;
V_65 = F_17 ( V_6 -> V_8 -> V_14 -> V_81 , V_32 , V_48 ) ;
if ( V_65 < 0 )
ERROR ( V_6 -> V_8 , L_18 ,
V_65 ) ;
}
return V_65 ;
}
int T_1 F_33 ( struct V_7 * V_8 , bool V_82 )
{
int V_10 ;
V_10 = F_34 ( V_8 ) ;
if ( V_10 < 0 )
return V_10 ;
V_83 [ 0 ] . V_10 = V_10 ;
V_11 . V_84 = V_10 ;
V_85 . V_86 = V_10 ;
if ( V_82 )
V_85 . V_87 |= V_88 ;
if ( F_35 ( V_8 -> V_14 ) ) {
V_85 . V_57 = V_89 ;
V_85 . V_87 |= V_88 ;
}
return F_36 ( V_8 , & V_85 , F_28 ) ;
}
