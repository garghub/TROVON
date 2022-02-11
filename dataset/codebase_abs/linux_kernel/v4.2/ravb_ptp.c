static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int error ;
error = F_2 ( V_5 , V_6 , V_7 , V_8 ) ;
if ( error )
return error ;
F_3 ( V_5 , F_4 ( V_5 , V_6 ) | V_3 , V_6 ) ;
return F_2 ( V_5 , V_6 , V_7 , V_8 ) ;
}
static int F_5 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int error ;
error = F_1 ( V_2 , V_11 ) ;
if ( error )
return error ;
V_10 -> V_12 = F_4 ( V_5 , V_13 ) ;
V_10 -> V_14 = F_4 ( V_5 , V_15 ) |
( ( V_16 ) F_4 ( V_5 , V_17 ) << 32 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
const struct V_9 * V_10 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int error ;
T_1 V_18 ;
error = F_1 ( V_2 , V_19 ) ;
if ( error )
return error ;
V_18 = F_4 ( V_5 , V_6 ) ;
if ( V_18 & V_20 )
return - V_21 ;
F_3 ( V_5 , V_10 -> V_12 , V_22 ) ;
F_3 ( V_5 , V_10 -> V_14 , V_23 ) ;
F_3 ( V_5 , ( V_10 -> V_14 >> 32 ) & 0xffff , V_24 ) ;
F_3 ( V_5 , V_18 | V_20 , V_6 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_25 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_26 = ( V_2 -> V_27 . V_28 >> 20 ) + 1 ;
T_1 V_18 ;
if ( V_25 < V_26 )
V_25 = V_26 ;
else if ( V_25 > 0 - V_26 )
V_25 = 0 - V_26 ;
V_18 = F_4 ( V_5 , V_6 ) ;
if ( V_18 & V_29 )
return - V_21 ;
F_3 ( V_5 , V_25 , V_30 ) ;
F_3 ( V_5 , V_18 | V_29 , V_6 ) ;
return 0 ;
}
static int F_8 ( struct V_31 * V_27 , T_2 V_32 )
{
struct V_1 * V_2 = F_9 ( V_27 , struct V_1 ,
V_27 . V_33 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned long V_34 ;
T_1 V_35 , V_36 ;
bool V_37 = false ;
T_1 V_18 ;
if ( V_32 < 0 ) {
V_37 = true ;
V_32 = - V_32 ;
}
V_36 = V_2 -> V_27 . V_38 ;
V_35 = F_10 ( ( V_39 ) V_36 * V_32 , V_40 ) ;
V_36 = V_37 ? V_36 - V_35 : V_36 + V_35 ;
F_11 ( & V_2 -> V_41 , V_34 ) ;
V_2 -> V_27 . V_28 = V_36 ;
V_18 = F_4 ( V_5 , V_6 ) ;
if ( V_18 & V_42 ) {
F_12 ( & V_2 -> V_41 , V_34 ) ;
return - V_21 ;
}
F_3 ( V_5 , V_36 & V_43 , V_44 ) ;
F_3 ( V_5 , V_18 | V_42 , V_6 ) ;
F_12 ( & V_2 -> V_41 , V_34 ) ;
return 0 ;
}
static int F_13 ( struct V_31 * V_27 , V_16 V_45 )
{
struct V_1 * V_2 = F_9 ( V_27 , struct V_1 ,
V_27 . V_33 ) ;
struct V_9 V_10 ;
unsigned long V_34 ;
int error ;
F_11 ( & V_2 -> V_41 , V_34 ) ;
error = F_5 ( V_2 , & V_10 ) ;
if ( ! error ) {
V_39 V_46 = F_14 ( F_15 ( V_10 ) ) ;
V_10 = F_16 ( V_46 + V_45 ) ;
error = F_6 ( V_2 , & V_10 ) ;
}
F_12 ( & V_2 -> V_41 , V_34 ) ;
return error ;
}
static int F_17 ( struct V_31 * V_27 , struct V_9 * V_10 )
{
struct V_1 * V_2 = F_9 ( V_27 , struct V_1 ,
V_27 . V_33 ) ;
unsigned long V_34 ;
int error ;
F_11 ( & V_2 -> V_41 , V_34 ) ;
error = F_5 ( V_2 , V_10 ) ;
F_12 ( & V_2 -> V_41 , V_34 ) ;
return error ;
}
static int F_18 ( struct V_31 * V_27 ,
const struct V_9 * V_10 )
{
struct V_1 * V_2 = F_9 ( V_27 , struct V_1 ,
V_27 . V_33 ) ;
unsigned long V_34 ;
int error ;
F_11 ( & V_2 -> V_41 , V_34 ) ;
error = F_6 ( V_2 , V_10 ) ;
F_12 ( & V_2 -> V_41 , V_34 ) ;
return error ;
}
static int F_19 ( struct V_31 * V_27 ,
struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = F_9 ( V_27 , struct V_1 ,
V_27 . V_33 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned long V_34 ;
T_1 V_50 ;
if ( V_48 -> V_51 )
return - V_52 ;
if ( V_2 -> V_27 . V_53 [ V_48 -> V_51 ] == V_49 )
return 0 ;
V_2 -> V_27 . V_53 [ V_48 -> V_51 ] = V_49 ;
F_11 ( & V_2 -> V_41 , V_34 ) ;
V_50 = F_4 ( V_5 , V_54 ) ;
if ( V_49 )
V_50 |= V_55 ;
else
V_50 &= ~ V_55 ;
F_3 ( V_5 , V_50 , V_54 ) ;
F_20 () ;
F_12 ( & V_2 -> V_41 , V_34 ) ;
return 0 ;
}
static int F_21 ( struct V_31 * V_27 ,
struct V_56 * V_48 , int V_49 )
{
struct V_1 * V_2 = F_9 ( V_27 , struct V_1 ,
V_27 . V_33 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct F_21 * V_57 ;
unsigned long V_34 ;
int error = 0 ;
T_1 V_50 ;
if ( V_48 -> V_51 )
return - V_52 ;
if ( V_49 ) {
V_39 V_58 ;
V_39 V_59 ;
V_58 = V_48 -> V_60 . V_61 * V_40 + V_48 -> V_60 . V_62 ;
V_59 = V_48 -> V_63 . V_61 * V_40 + V_48 -> V_63 . V_62 ;
if ( V_58 > V_64 ) {
F_22 ( V_5 ,
L_1 ) ;
return - V_65 ;
}
if ( V_59 > V_64 ) {
F_22 ( V_5 ,
L_2 ) ;
return - V_65 ;
}
F_11 ( & V_2 -> V_41 , V_34 ) ;
V_57 = & V_2 -> V_27 . V_57 [ V_48 -> V_51 ] ;
V_57 -> V_66 = ( T_1 ) V_58 ;
V_57 -> V_63 = ( T_1 ) V_59 ;
error = F_7 ( V_2 , ( T_1 ) V_58 ) ;
if ( ! error ) {
V_50 = F_4 ( V_5 , V_54 ) ;
V_50 |= V_67 ;
F_3 ( V_5 , V_50 , V_54 ) ;
}
} else {
F_11 ( & V_2 -> V_41 , V_34 ) ;
V_57 = & V_2 -> V_27 . V_57 [ V_48 -> V_51 ] ;
V_57 -> V_63 = 0 ;
V_50 = F_4 ( V_5 , V_54 ) ;
V_50 &= ~ V_67 ;
F_3 ( V_5 , V_50 , V_54 ) ;
}
F_20 () ;
F_12 ( & V_2 -> V_41 , V_34 ) ;
return error ;
}
static int F_23 ( struct V_31 * V_27 ,
struct V_68 * V_48 , int V_49 )
{
switch ( V_48 -> type ) {
case V_69 :
return F_19 ( V_27 , & V_48 -> V_53 , V_49 ) ;
case V_70 :
return F_21 ( V_27 , & V_48 -> V_57 , V_49 ) ;
default:
return - V_71 ;
}
}
T_3 F_24 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_25 ( V_5 ) ;
T_1 V_72 = F_4 ( V_5 , V_73 ) ;
V_72 &= F_4 ( V_5 , V_54 ) ;
if ( V_72 & V_74 ) {
struct V_75 V_76 ;
V_76 . type = V_77 ;
V_76 . V_51 = 0 ;
V_76 . V_78 = F_4 ( V_5 , V_79 ) ;
V_75 ( V_2 -> V_27 . clock , & V_76 ) ;
}
if ( V_72 & V_80 ) {
struct F_21 * V_57 = V_2 -> V_27 . V_57 ;
if ( V_57 -> V_63 ) {
V_57 -> V_66 += V_57 -> V_63 ;
F_7 ( V_2 , V_57 -> V_66 ) ;
}
}
if ( V_72 ) {
F_3 ( V_5 , ~ V_72 , V_73 ) ;
return V_81 ;
}
return V_82 ;
}
void F_26 ( struct V_4 * V_5 , struct V_83 * V_84 )
{
struct V_1 * V_2 = F_25 ( V_5 ) ;
unsigned long V_34 ;
T_1 V_18 ;
V_2 -> V_27 . V_33 = V_85 ;
V_2 -> V_27 . V_38 = F_4 ( V_5 , V_44 ) ;
V_2 -> V_27 . V_28 = V_2 -> V_27 . V_38 ;
F_11 ( & V_2 -> V_41 , V_34 ) ;
F_2 ( V_5 , V_6 , V_7 , V_8 ) ;
V_18 = F_4 ( V_5 , V_6 ) & ~ V_86 ;
F_3 ( V_5 , V_18 | V_87 , V_6 ) ;
F_20 () ;
F_12 ( & V_2 -> V_41 , V_34 ) ;
V_2 -> V_27 . clock = F_27 ( & V_2 -> V_27 . V_33 , & V_84 -> V_88 ) ;
}
void F_28 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_25 ( V_5 ) ;
F_3 ( V_5 , 0 , V_54 ) ;
F_3 ( V_5 , 0 , V_73 ) ;
F_29 ( V_2 -> V_27 . clock ) ;
}
