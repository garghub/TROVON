static T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_2 V_4 , V_5 ;
V_4 = F_2 ( & V_2 -> V_6 ) ;
V_5 = F_2 ( & V_2 -> V_7 ) ;
V_3 = ( ( T_1 ) V_5 ) << 32 ;
V_3 |= V_4 ;
V_3 <<= V_8 ;
return V_3 ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_5 , V_4 ;
V_3 >>= V_8 ;
V_5 = V_3 >> 32 ;
V_4 = V_3 & 0xffffffff ;
F_4 ( V_4 , & V_2 -> V_6 ) ;
F_4 ( V_5 , & V_2 -> V_7 ) ;
}
static T_3 F_5 ( int V_9 , void * V_10 )
{
struct V_11 * V_11 = V_10 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_12 V_13 ;
T_2 V_14 = 0 , V_4 , V_5 , V_15 ;
V_15 = F_2 ( & V_2 -> V_13 ) ;
if ( V_15 & V_16 ) {
V_14 |= V_16 ;
if ( V_11 -> V_17 ) {
V_5 = F_2 ( & V_2 -> V_18 ) ;
V_4 = F_2 ( & V_2 -> V_19 ) ;
V_13 . type = V_20 ;
V_13 . V_21 = 0 ;
V_13 . V_22 = ( ( T_1 ) V_5 ) << 32 ;
V_13 . V_22 |= V_4 ;
V_13 . V_22 <<= V_8 ;
V_12 ( V_11 -> V_23 , & V_13 ) ;
}
}
if ( V_15 & V_24 ) {
V_14 |= V_24 ;
if ( V_11 -> V_25 ) {
V_5 = F_2 ( & V_2 -> V_26 ) ;
V_4 = F_2 ( & V_2 -> V_27 ) ;
V_13 . type = V_20 ;
V_13 . V_21 = 1 ;
V_13 . V_22 = ( ( T_1 ) V_5 ) << 32 ;
V_13 . V_22 |= V_4 ;
V_13 . V_22 <<= V_8 ;
V_12 ( V_11 -> V_23 , & V_13 ) ;
}
}
if ( V_15 & V_28 )
V_14 |= V_28 ;
if ( V_14 ) {
F_4 ( V_14 , & V_2 -> V_13 ) ;
return V_29 ;
} else
return V_30 ;
}
static int F_6 ( struct V_31 * V_32 , T_4 V_33 )
{
T_1 V_34 ;
T_2 V_35 , V_36 ;
int V_37 = 0 ;
struct V_11 * V_11 = F_7 ( V_32 , struct V_11 , V_38 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
if ( V_33 < 0 ) {
V_37 = 1 ;
V_33 = - V_33 ;
}
V_36 = V_39 ;
V_34 = V_36 ;
V_34 *= V_33 ;
V_35 = F_8 ( V_34 , 1000000000ULL ) ;
V_36 = V_37 ? V_36 - V_35 : V_36 + V_35 ;
F_4 ( V_36 , & V_2 -> V_36 ) ;
return 0 ;
}
static int F_9 ( struct V_31 * V_32 , T_5 V_40 )
{
T_5 V_41 ;
unsigned long V_42 ;
struct V_11 * V_11 = F_7 ( V_32 , struct V_11 , V_38 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
F_10 ( & V_43 , V_42 ) ;
V_41 = F_1 ( V_2 ) ;
V_41 += V_40 ;
F_3 ( V_2 , V_41 ) ;
F_11 ( & V_43 , V_42 ) ;
return 0 ;
}
static int F_12 ( struct V_31 * V_32 , struct V_44 * V_45 )
{
T_1 V_3 ;
T_2 V_46 ;
unsigned long V_42 ;
struct V_11 * V_11 = F_7 ( V_32 , struct V_11 , V_38 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
F_10 ( & V_43 , V_42 ) ;
V_3 = F_1 ( V_2 ) ;
F_11 ( & V_43 , V_42 ) ;
V_45 -> V_47 = F_13 ( V_3 , 1000000000 , & V_46 ) ;
V_45 -> V_48 = V_46 ;
return 0 ;
}
static int F_14 ( struct V_31 * V_32 ,
const struct V_44 * V_45 )
{
T_1 V_3 ;
unsigned long V_42 ;
struct V_11 * V_11 = F_7 ( V_32 , struct V_11 , V_38 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
V_3 = V_45 -> V_47 * 1000000000ULL ;
V_3 += V_45 -> V_48 ;
F_10 ( & V_43 , V_42 ) ;
F_3 ( V_2 , V_3 ) ;
F_11 ( & V_43 , V_42 ) ;
return 0 ;
}
static int F_15 ( struct V_31 * V_32 ,
struct V_49 * V_50 , int V_51 )
{
struct V_11 * V_11 = F_7 ( V_32 , struct V_11 , V_38 ) ;
switch ( V_50 -> type ) {
case V_52 :
switch ( V_50 -> V_53 . V_21 ) {
case 0 :
V_11 -> V_17 = V_51 ? 1 : 0 ;
break;
case 1 :
V_11 -> V_25 = V_51 ? 1 : 0 ;
break;
default:
return - V_54 ;
}
return 0 ;
default:
break;
}
return - V_55 ;
}
static int F_16 ( int V_56 )
{
int V_9 ;
F_17 ( V_56 , V_57 ) ;
V_9 = F_18 ( V_56 ) ;
if ( V_58 == V_9 )
return V_58 ;
if ( F_19 ( V_9 , V_59 ) ) {
F_20 ( L_1 , V_9 ) ;
return V_58 ;
}
if ( F_21 ( V_9 , F_5 , 0 , V_60 , & V_11 ) ) {
F_20 ( L_2 , V_9 ) ;
return V_58 ;
}
return V_9 ;
}
static void T_6 F_22 ( void )
{
F_23 ( V_61 , & V_11 ) ;
F_23 ( V_62 , & V_11 ) ;
F_24 ( V_11 . V_23 ) ;
}
static int T_7 F_25 ( void )
{
if ( ! F_26 () )
return - V_63 ;
V_11 . V_2 =
(struct V_1 V_64 * ) V_65 ;
V_11 . V_38 = V_66 ;
V_11 . V_23 = F_27 ( & V_11 . V_38 ) ;
if ( F_28 ( V_11 . V_23 ) )
return F_29 ( V_11 . V_23 ) ;
F_4 ( V_39 , & V_11 . V_2 -> V_36 ) ;
F_4 ( 1 , & V_11 . V_2 -> V_67 ) ;
F_4 ( 0 , & V_11 . V_2 -> V_68 ) ;
F_4 ( V_28 , & V_11 . V_2 -> V_13 ) ;
if ( V_61 != F_16 ( V_69 ) ) {
F_20 ( L_3 , V_69 ) ;
goto V_70;
}
if ( V_62 != F_16 ( V_71 ) ) {
F_20 ( L_3 , V_71 ) ;
goto V_72;
}
return 0 ;
V_72:
F_23 ( V_61 , & V_11 ) ;
V_70:
F_24 ( V_11 . V_23 ) ;
return - V_63 ;
}
