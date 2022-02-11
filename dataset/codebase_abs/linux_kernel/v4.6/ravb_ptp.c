static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int error ;
error = F_2 ( V_5 , V_6 , V_7 , V_8 ) ;
if ( error )
return error ;
F_3 ( V_5 , V_6 , V_3 , V_3 ) ;
return F_2 ( V_5 , V_6 , V_7 , V_8 ) ;
}
static int F_4 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int error ;
error = F_1 ( V_2 , V_11 ) ;
if ( error )
return error ;
V_10 -> V_12 = F_5 ( V_5 , V_13 ) ;
V_10 -> V_14 = F_5 ( V_5 , V_15 ) |
( ( V_16 ) F_5 ( V_5 , V_17 ) << 32 ) ;
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
V_18 = F_5 ( V_5 , V_6 ) ;
if ( V_18 & V_20 )
return - V_21 ;
F_7 ( V_5 , V_10 -> V_12 , V_22 ) ;
F_7 ( V_5 , V_10 -> V_14 , V_23 ) ;
F_7 ( V_5 , ( V_10 -> V_14 >> 32 ) & 0xffff , V_24 ) ;
F_7 ( V_5 , V_18 | V_20 , V_6 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_25 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_26 = ( V_2 -> V_27 . V_28 >> 20 ) + 1 ;
T_1 V_18 ;
if ( V_25 < V_26 )
V_25 = V_26 ;
else if ( V_25 > 0 - V_26 )
V_25 = 0 - V_26 ;
V_18 = F_5 ( V_5 , V_6 ) ;
if ( V_18 & V_29 )
return - V_21 ;
F_7 ( V_5 , V_25 , V_30 ) ;
F_7 ( V_5 , V_18 | V_29 , V_6 ) ;
return 0 ;
}
static int F_9 ( struct V_31 * V_27 , T_2 V_32 )
{
struct V_1 * V_2 = F_10 ( V_27 , struct V_1 ,
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
V_35 = F_11 ( ( V_39 ) V_36 * V_32 , V_40 ) ;
V_36 = V_37 ? V_36 - V_35 : V_36 + V_35 ;
F_12 ( & V_2 -> V_41 , V_34 ) ;
V_2 -> V_27 . V_28 = V_36 ;
V_18 = F_5 ( V_5 , V_6 ) ;
if ( V_18 & V_42 ) {
F_13 ( & V_2 -> V_41 , V_34 ) ;
return - V_21 ;
}
F_7 ( V_5 , V_36 & V_43 , V_44 ) ;
F_7 ( V_5 , V_18 | V_42 , V_6 ) ;
F_13 ( & V_2 -> V_41 , V_34 ) ;
return 0 ;
}
static int F_14 ( struct V_31 * V_27 , V_16 V_45 )
{
struct V_1 * V_2 = F_10 ( V_27 , struct V_1 ,
V_27 . V_33 ) ;
struct V_9 V_10 ;
unsigned long V_34 ;
int error ;
F_12 ( & V_2 -> V_41 , V_34 ) ;
error = F_4 ( V_2 , & V_10 ) ;
if ( ! error ) {
V_39 V_46 = F_15 ( F_16 ( V_10 ) ) ;
V_10 = F_17 ( V_46 + V_45 ) ;
error = F_6 ( V_2 , & V_10 ) ;
}
F_13 ( & V_2 -> V_41 , V_34 ) ;
return error ;
}
static int F_18 ( struct V_31 * V_27 , struct V_9 * V_10 )
{
struct V_1 * V_2 = F_10 ( V_27 , struct V_1 ,
V_27 . V_33 ) ;
unsigned long V_34 ;
int error ;
F_12 ( & V_2 -> V_41 , V_34 ) ;
error = F_4 ( V_2 , V_10 ) ;
F_13 ( & V_2 -> V_41 , V_34 ) ;
return error ;
}
static int F_19 ( struct V_31 * V_27 ,
const struct V_9 * V_10 )
{
struct V_1 * V_2 = F_10 ( V_27 , struct V_1 ,
V_27 . V_33 ) ;
unsigned long V_34 ;
int error ;
F_12 ( & V_2 -> V_41 , V_34 ) ;
error = F_6 ( V_2 , V_10 ) ;
F_13 ( & V_2 -> V_41 , V_34 ) ;
return error ;
}
static int F_20 ( struct V_31 * V_27 ,
struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = F_10 ( V_27 , struct V_1 ,
V_27 . V_33 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned long V_34 ;
if ( V_48 -> V_50 )
return - V_51 ;
if ( V_2 -> V_27 . V_52 [ V_48 -> V_50 ] == V_49 )
return 0 ;
V_2 -> V_27 . V_52 [ V_48 -> V_50 ] = V_49 ;
F_12 ( & V_2 -> V_41 , V_34 ) ;
F_3 ( V_5 , V_53 , V_54 , V_49 ? V_54 : 0 ) ;
F_21 () ;
F_13 ( & V_2 -> V_41 , V_34 ) ;
return 0 ;
}
static int F_22 ( struct V_31 * V_27 ,
struct V_55 * V_48 , int V_49 )
{
struct V_1 * V_2 = F_10 ( V_27 , struct V_1 ,
V_27 . V_33 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct F_22 * V_56 ;
unsigned long V_34 ;
int error = 0 ;
if ( V_48 -> V_50 )
return - V_51 ;
if ( V_49 ) {
V_39 V_57 ;
V_39 V_58 ;
V_57 = V_48 -> V_59 . V_60 * V_40 + V_48 -> V_59 . V_61 ;
V_58 = V_48 -> V_62 . V_60 * V_40 + V_48 -> V_62 . V_61 ;
if ( V_57 > V_63 ) {
F_23 ( V_5 ,
L_1 ) ;
return - V_64 ;
}
if ( V_58 > V_63 ) {
F_23 ( V_5 ,
L_2 ) ;
return - V_64 ;
}
F_12 ( & V_2 -> V_41 , V_34 ) ;
V_56 = & V_2 -> V_27 . V_56 [ V_48 -> V_50 ] ;
V_56 -> V_65 = ( T_1 ) V_57 ;
V_56 -> V_62 = ( T_1 ) V_58 ;
error = F_8 ( V_2 , ( T_1 ) V_57 ) ;
if ( ! error ) {
F_3 ( V_5 , V_53 , V_66 , V_66 ) ;
}
} else {
F_12 ( & V_2 -> V_41 , V_34 ) ;
V_56 = & V_2 -> V_27 . V_56 [ V_48 -> V_50 ] ;
V_56 -> V_62 = 0 ;
F_3 ( V_5 , V_53 , V_66 , 0 ) ;
}
F_21 () ;
F_13 ( & V_2 -> V_41 , V_34 ) ;
return error ;
}
static int F_24 ( struct V_31 * V_27 ,
struct V_67 * V_48 , int V_49 )
{
switch ( V_48 -> type ) {
case V_68 :
return F_20 ( V_27 , & V_48 -> V_52 , V_49 ) ;
case V_69 :
return F_22 ( V_27 , & V_48 -> V_56 , V_49 ) ;
default:
return - V_70 ;
}
}
T_3 F_25 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_26 ( V_5 ) ;
T_1 V_71 = F_5 ( V_5 , V_72 ) ;
V_71 &= F_5 ( V_5 , V_53 ) ;
if ( V_71 & V_73 ) {
struct V_74 V_75 ;
V_75 . type = V_76 ;
V_75 . V_50 = 0 ;
V_75 . V_77 = F_5 ( V_5 , V_78 ) ;
V_74 ( V_2 -> V_27 . clock , & V_75 ) ;
}
if ( V_71 & V_79 ) {
struct F_22 * V_56 = V_2 -> V_27 . V_56 ;
if ( V_56 -> V_62 ) {
V_56 -> V_65 += V_56 -> V_62 ;
F_8 ( V_2 , V_56 -> V_65 ) ;
}
}
if ( V_71 ) {
F_7 ( V_5 , ~ V_71 , V_72 ) ;
return V_80 ;
}
return V_81 ;
}
void F_27 ( struct V_4 * V_5 , struct V_82 * V_83 )
{
struct V_1 * V_2 = F_26 ( V_5 ) ;
unsigned long V_34 ;
V_2 -> V_27 . V_33 = V_84 ;
V_2 -> V_27 . V_38 = F_5 ( V_5 , V_44 ) ;
V_2 -> V_27 . V_28 = V_2 -> V_27 . V_38 ;
F_12 ( & V_2 -> V_41 , V_34 ) ;
F_2 ( V_5 , V_6 , V_7 , V_8 ) ;
F_3 ( V_5 , V_6 , V_85 , V_86 ) ;
F_21 () ;
F_13 ( & V_2 -> V_41 , V_34 ) ;
V_2 -> V_27 . clock = F_28 ( & V_2 -> V_27 . V_33 , & V_83 -> V_87 ) ;
}
void F_29 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_26 ( V_5 ) ;
F_7 ( V_5 , 0 , V_53 ) ;
F_7 ( V_5 , 0 , V_72 ) ;
F_30 ( V_2 -> V_27 . clock ) ;
}
