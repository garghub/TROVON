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
F_7 ( V_8 , L_2 ,
F_6 ( V_6 -> V_8 -> V_14 ) ? L_3 : L_4 ,
V_3 -> V_17 , V_9 -> V_13 -> V_17 , V_9 -> V_20 -> V_17 ) ;
return 0 ;
}
static void
F_8 ( struct V_5 * V_6 , struct V_2 * V_3 )
{
F_9 ( F_1 ( V_3 ) ) ;
}
static int F_10 ( struct V_1 * V_9 , struct V_27 * V_28 )
{
unsigned V_29 ;
T_2 * V_30 = V_28 -> V_30 ;
struct V_7 * V_8 = V_9 -> V_4 . V_31 -> V_8 ;
for ( V_29 = 0 ; V_29 < V_28 -> V_32 ; V_29 ++ , V_30 ++ ) {
switch ( V_33 ) {
case 0 :
if ( * V_30 == 0 )
continue;
break;
case 1 :
if ( * V_30 == ( T_2 ) ( V_29 % 63 ) )
continue;
break;
}
ERROR ( V_8 , L_5 , V_29 , * V_30 ) ;
F_11 ( V_9 -> V_20 ) ;
return - V_34 ;
}
return 0 ;
}
static void F_12 ( struct V_35 * V_36 , struct V_27 * V_28 )
{
unsigned V_29 ;
T_2 * V_30 = V_28 -> V_30 ;
switch ( V_33 ) {
case 0 :
memset ( V_28 -> V_30 , 0 , V_28 -> V_37 ) ;
break;
case 1 :
for ( V_29 = 0 ; V_29 < V_28 -> V_37 ; V_29 ++ )
* V_30 ++ = ( T_2 ) ( V_29 % 63 ) ;
break;
}
}
static void F_13 ( struct V_35 * V_36 , struct V_27 * V_28 )
{
struct V_1 * V_9 = V_36 -> V_19 ;
struct V_7 * V_8 = V_9 -> V_4 . V_31 -> V_8 ;
int V_38 = V_28 -> V_38 ;
switch ( V_38 ) {
case 0 :
if ( V_36 == V_9 -> V_20 ) {
F_10 ( V_9 , V_28 ) ;
memset ( V_28 -> V_30 , 0x55 , V_28 -> V_37 ) ;
} else
F_12 ( V_36 , V_28 ) ;
break;
case - V_39 :
case - V_40 :
case - V_41 :
F_14 ( V_8 , L_6 , V_36 -> V_17 , V_38 ,
V_28 -> V_32 , V_28 -> V_37 ) ;
if ( V_36 == V_9 -> V_20 )
F_10 ( V_9 , V_28 ) ;
F_15 ( V_36 , V_28 ) ;
return;
case - V_42 :
default:
#if 1
F_7 ( V_8 , L_7 , V_36 -> V_17 ,
V_38 , V_28 -> V_32 , V_28 -> V_37 ) ;
#endif
case - V_43 :
break;
}
V_38 = F_16 ( V_36 , V_28 , V_44 ) ;
if ( V_38 ) {
ERROR ( V_8 , L_8 ,
V_36 -> V_17 , V_28 -> V_37 , V_38 ) ;
F_11 ( V_36 ) ;
}
}
static int F_17 ( struct V_1 * V_9 , bool V_45 )
{
struct V_35 * V_36 ;
struct V_27 * V_28 ;
int V_38 ;
V_36 = V_45 ? V_9 -> V_13 : V_9 -> V_20 ;
V_28 = F_18 ( V_36 ) ;
if ( ! V_28 )
return - V_46 ;
V_28 -> V_47 = F_13 ;
if ( V_45 )
F_12 ( V_36 , V_28 ) ;
else
memset ( V_28 -> V_30 , 0x55 , V_28 -> V_37 ) ;
V_38 = F_16 ( V_36 , V_28 , V_44 ) ;
if ( V_38 ) {
struct V_7 * V_8 ;
V_8 = V_9 -> V_4 . V_31 -> V_8 ;
ERROR ( V_8 , L_9 ,
V_45 ? L_10 : L_11 ,
V_36 -> V_17 , V_38 ) ;
F_15 ( V_36 , V_28 ) ;
}
return V_38 ;
}
static void F_19 ( struct V_1 * V_9 )
{
struct V_7 * V_8 ;
V_8 = V_9 -> V_4 . V_31 -> V_8 ;
F_20 ( V_8 , V_9 -> V_13 , V_9 -> V_20 ) ;
F_14 ( V_8 , L_12 , V_9 -> V_4 . V_17 ) ;
}
static int
F_21 ( struct V_7 * V_8 , struct V_1 * V_9 )
{
int V_48 = 0 ;
const struct V_49 * V_50 , * V_51 ;
struct V_35 * V_36 ;
V_50 = F_22 ( V_8 -> V_14 , & V_22 , & V_15 ) ;
V_51 = F_22 ( V_8 -> V_14 , & V_24 , & V_21 ) ;
V_36 = V_9 -> V_13 ;
V_48 = F_23 ( V_36 , V_50 ) ;
if ( V_48 < 0 )
return V_48 ;
V_36 -> V_19 = V_9 ;
V_48 = F_17 ( V_9 , true ) ;
if ( V_48 < 0 ) {
V_52:
V_36 = V_9 -> V_13 ;
F_24 ( V_36 ) ;
V_36 -> V_19 = NULL ;
return V_48 ;
}
V_36 = V_9 -> V_20 ;
V_48 = F_23 ( V_36 , V_51 ) ;
if ( V_48 < 0 )
goto V_52;
V_36 -> V_19 = V_9 ;
V_48 = F_17 ( V_9 , false ) ;
if ( V_48 < 0 ) {
F_24 ( V_36 ) ;
V_36 -> V_19 = NULL ;
goto V_52;
}
F_7 ( V_8 , L_13 , V_9 -> V_4 . V_17 ) ;
return V_48 ;
}
static int F_25 ( struct V_2 * V_3 ,
unsigned V_53 , unsigned V_54 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_7 * V_8 = V_3 -> V_31 -> V_8 ;
if ( V_9 -> V_13 -> V_19 )
F_19 ( V_9 ) ;
return F_21 ( V_8 , V_9 ) ;
}
static void F_26 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_19 ( V_9 ) ;
}
static int T_1 F_27 ( struct V_5 * V_6 )
{
struct V_1 * V_9 ;
int V_38 ;
V_9 = F_28 ( sizeof *V_9 , V_55 ) ;
if ( ! V_9 )
return - V_46 ;
V_9 -> V_4 . V_17 = L_14 ;
V_9 -> V_4 . V_56 = V_57 ;
V_9 -> V_4 . V_58 = F_3 ;
V_9 -> V_4 . V_59 = F_8 ;
V_9 -> V_4 . V_60 = F_25 ;
V_9 -> V_4 . V_61 = F_26 ;
V_38 = F_29 ( V_6 , & V_9 -> V_4 ) ;
if ( V_38 )
F_9 ( V_9 ) ;
return V_38 ;
}
static int F_30 ( struct V_5 * V_6 ,
const struct V_62 * V_63 )
{
struct V_27 * V_28 = V_6 -> V_8 -> V_28 ;
int V_64 = - V_65 ;
T_3 V_66 = F_31 ( V_63 -> V_67 ) ;
T_3 V_68 = F_31 ( V_63 -> V_69 ) ;
T_3 V_70 = F_31 ( V_63 -> V_71 ) ;
switch ( V_63 -> V_72 ) {
case 0x5b :
if ( V_63 -> V_73 != ( V_74 | V_75 ) )
goto V_76;
if ( V_68 || V_66 )
break;
if ( V_70 > V_28 -> V_37 )
break;
V_64 = V_70 ;
break;
case 0x5c :
if ( V_63 -> V_73 != ( V_77 | V_75 ) )
goto V_76;
if ( V_68 || V_66 )
break;
if ( V_70 > V_28 -> V_37 )
break;
V_64 = V_70 ;
break;
default:
V_76:
F_14 ( V_6 -> V_8 ,
L_15 ,
V_63 -> V_73 , V_63 -> V_72 ,
V_68 , V_66 , V_70 ) ;
}
if ( V_64 >= 0 ) {
F_14 ( V_6 -> V_8 , L_16 ,
V_63 -> V_73 , V_63 -> V_72 ,
V_68 , V_66 , V_70 ) ;
V_28 -> V_78 = 0 ;
V_28 -> V_37 = V_64 ;
V_64 = F_16 ( V_6 -> V_8 -> V_14 -> V_79 , V_28 , V_44 ) ;
if ( V_64 < 0 )
ERROR ( V_6 -> V_8 , L_17 ,
V_64 ) ;
}
return V_64 ;
}
int T_1 F_32 ( struct V_7 * V_8 , bool V_80 )
{
int V_10 ;
V_10 = F_33 ( V_8 ) ;
if ( V_10 < 0 )
return V_10 ;
V_81 [ 0 ] . V_10 = V_10 ;
V_11 . V_82 = V_10 ;
V_83 . V_84 = V_10 ;
if ( V_80 )
V_83 . V_85 |= V_86 ;
if ( F_34 ( V_8 -> V_14 ) ) {
V_83 . V_56 = V_87 ;
V_83 . V_85 |= V_86 ;
}
return F_35 ( V_8 , & V_83 , F_27 ) ;
}
