static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
T_2 V_6 ;
V_6 = F_2 ( V_2 , V_3 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 &= ~ V_4 ;
V_6 |= ( V_5 & V_4 ) ;
return F_3 ( V_2 , V_3 , V_6 ) ;
}
static int F_4 ( struct V_1 * V_2 , bool V_7 )
{
int V_8 ;
V_8 = F_1 ( V_2 , V_9 , V_10 ,
V_7 ? V_10 : 0 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_1 ( V_2 , V_11 , V_12 ,
V_7 ? V_12 : 0 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_1 ( V_2 , V_13 , V_14 ,
V_7 ? V_14 : 0 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_1 ( V_2 , V_15 , V_16 ,
V_17 ) ;
if ( V_8 < 0 )
return V_8 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
T_3 V_18 )
{
T_3 V_5 ;
if ( V_18 >= 32000000 && V_18 < 56000000 )
V_5 = 0x0 ;
else if ( V_18 >= 16000000 && V_18 < 28000000 )
V_5 = 0x1 ;
else if ( V_18 >= 8000000 && V_18 < 14000000 )
V_5 = 0x2 ;
else
return - V_19 ;
return F_1 ( V_2 , V_13 ,
V_20 ,
F_6 ( V_5 ) ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_8 ( V_2 ) ;
T_2 V_5 ;
unsigned int V_23 ;
for ( V_23 = 0 ; V_23 < 256 ; V_23 ++ ) {
V_5 = F_2 ( V_2 , V_24 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( ! ( V_5 & V_25 ) )
return 0 ;
F_9 ( 1 ) ;
}
F_10 ( V_22 , L_1 ) ;
return - V_26 ;
}
static int F_11 ( struct V_1 * V_2 , bool V_7 )
{
return F_1 ( V_2 , V_24 ,
( V_27 | V_28 ) ,
V_7 ? 0 :
( V_27 | V_28 ) ) ;
}
static T_3 F_12 ( T_3 V_18 , T_3 V_29 )
{
T_4 V_30 ;
V_30 = ( T_4 ) V_29 << 20 ;
F_13 ( V_30 , V_18 ) ;
return V_30 ;
}
static unsigned long F_14 ( T_3 V_30 , T_3 V_18 )
{
T_4 V_29 ;
V_29 = ( T_4 ) V_30 * V_18 ;
return V_29 >> 20 ;
}
static int F_15 ( struct V_1 * V_2 ,
int V_31 , T_3 V_18 , T_3 V_29 )
{
T_3 V_5 ;
unsigned int V_23 ;
int V_8 ;
if ( F_16 ( V_31 ) )
return - V_19 ;
V_5 = F_12 ( V_18 , V_29 ) ;
for ( V_23 = 0 ; V_23 < V_32 ; V_23 ++ ) {
V_8 = F_3 ( V_2 ,
F_17 ( V_31 , V_23 ) ,
F_18 ( V_5 , V_23 ) ) ;
if ( V_8 < 0 )
return V_8 ;
}
return 0 ;
}
static T_3 F_19 ( struct V_1 * V_2 , int V_31 )
{
T_2 V_33 ;
T_3 V_5 ;
unsigned int V_23 ;
V_5 = 0 ;
for ( V_23 = 0 ; V_23 < V_32 ; V_23 ++ ) {
V_33 = F_2 ( V_2 , F_17 ( V_31 , V_23 ) ) ;
if ( V_33 < 0 )
return 0 ;
V_5 |= F_20 ( V_33 , V_23 ) ;
}
return V_5 ;
}
static int F_21 ( struct V_1 * V_2 , int V_31 )
{
int V_8 ;
if ( F_16 ( V_31 ) )
return - V_19 ;
V_8 = F_1 ( V_2 , V_9 , V_34 , F_22 ( V_31 ) ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_1 ( V_2 , V_35 ,
( V_36 | V_37 | V_38 ) ,
( F_23 ( V_31 ) | V_39 ) ) ;
if ( V_8 < 0 )
return V_8 ;
return 0 ;
}
static unsigned long F_24 ( struct V_40 * V_41 ,
unsigned long V_42 )
{
struct V_1 * V_2 = F_25 ( V_41 ) ;
int V_31 = 0 ;
T_3 V_30 ;
V_30 = F_19 ( V_2 , V_31 ) ;
return F_14 ( V_30 , V_42 ) ;
}
static long F_26 ( struct V_40 * V_41 , unsigned long V_43 ,
unsigned long * V_42 )
{
T_3 V_30 ;
V_30 = F_12 ( * V_42 , V_43 ) ;
return F_14 ( V_30 , * V_42 ) ;
}
static int F_27 ( struct V_1 * V_2 , int V_31 ,
unsigned long V_43 , unsigned long V_42 )
{
int V_8 ;
V_8 = F_5 ( V_2 , V_42 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_15 ( V_2 , V_31 , V_42 , V_43 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_21 ( V_2 , V_31 ) ;
if ( V_8 < 0 )
return V_8 ;
V_2 -> V_44 = V_43 ;
V_2 -> V_45 = V_42 ;
return 0 ;
}
static int F_28 ( struct V_40 * V_41 ,
unsigned long V_43 , unsigned long V_42 )
{
struct V_1 * V_2 = F_25 ( V_41 ) ;
int V_31 = 0 ;
return F_27 ( V_2 , V_31 , V_43 , V_42 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_31 = 0 ;
return F_27 ( V_2 , V_31 ,
V_2 -> V_44 ,
V_2 -> V_45 ) ;
}
static int F_30 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_25 ( V_41 ) ;
int V_8 ;
V_8 = F_4 ( V_2 , true ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_11 ( V_2 , true ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_7 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
return V_8 ;
}
static void F_31 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_25 ( V_41 ) ;
F_4 ( V_2 , false ) ;
F_11 ( V_2 , false ) ;
}
static T_1 F_32 ( struct V_40 * V_41 )
{
return V_46 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_8 ( V_2 ) ;
struct V_47 * V_48 , * V_49 ;
V_48 = F_34 ( V_22 , L_2 ) ;
if ( F_35 ( V_48 ) )
return - V_50 ;
V_49 = F_34 ( V_22 , L_3 ) ;
if ( F_35 ( V_49 ) )
return - V_50 ;
V_2 -> V_48 = V_48 ;
V_2 -> V_49 = V_49 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_8 ( V_2 ) ;
struct V_51 * V_52 = V_22 -> V_53 ;
struct V_54 V_55 ;
const char * V_56 = V_52 -> V_56 ;
static const char * V_57 [ V_58 ] ;
int V_31 = 0 ;
int V_43 ;
int V_8 ;
F_37 ( V_52 , L_4 , & V_56 ) ;
V_43 = F_38 ( V_2 -> V_49 ) ;
V_8 = F_27 ( V_2 , V_31 , V_43 , V_43 ) ;
if ( V_8 < 0 )
return V_8 ;
V_57 [ V_59 ] = F_39 ( V_2 -> V_48 ) ;
V_57 [ V_46 ] = F_39 ( V_2 -> V_49 ) ;
V_55 . V_56 = V_56 ;
V_55 . V_60 = & V_61 ;
V_55 . V_62 = V_63 ;
V_55 . V_57 = V_57 ;
V_55 . V_64 = F_40 ( V_57 ) ;
V_2 -> V_41 . V_55 = & V_55 ;
V_8 = F_41 ( V_22 , & V_2 -> V_41 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_42 ( V_52 , V_65 , & V_2 -> V_41 ) ;
if ( V_8 < 0 ) {
F_43 ( & V_2 -> V_41 ) ;
return V_8 ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_8 ( V_2 ) ;
T_2 V_5 ;
const char * V_66 ;
V_5 = F_2 ( V_2 , V_67 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_5 >> 3 )
return - V_68 ;
switch ( V_5 & V_69 ) {
case V_70 :
V_66 = L_5 ;
break;
case V_71 :
V_66 = L_6 ;
break;
default:
return - V_68 ;
}
F_45 ( V_22 , L_7 , V_66 ) ;
return 0 ;
}
static int F_46 ( struct V_72 * V_73 )
{
struct V_1 * V_2 = F_47 ( V_73 ) ;
struct V_21 * V_22 = F_8 ( V_2 ) ;
struct V_51 * V_52 = V_22 -> V_53 ;
F_48 ( V_52 ) ;
F_43 ( & V_2 -> V_41 ) ;
return 0 ;
}
static int F_49 ( struct V_72 * V_73 ,
const struct V_74 * V_75 )
{
struct V_1 * V_2 ;
struct V_21 * V_22 = & V_73 -> V_22 ;
int V_8 ;
V_2 = F_50 ( V_22 , sizeof( * V_2 ) , V_76 ) ;
if ( ! V_2 )
return - V_77 ;
V_2 -> V_73 = V_73 ;
F_51 ( V_73 , V_2 ) ;
V_8 = F_33 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_36 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_44 ( V_2 ) ;
if ( V_8 < 0 )
goto V_78;
return 0 ;
V_78:
F_46 ( V_73 ) ;
return V_8 ;
}
static int F_52 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_53 ( V_22 ) ;
return F_29 ( V_2 ) ;
}
