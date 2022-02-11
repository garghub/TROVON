static void F_1 ( T_1 * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 )
{
const struct V_6 * V_7 = V_5 -> V_7 ;
V_3 -> V_8 = V_1 [ V_9 ] & V_7 -> V_10 ;
V_3 -> V_11 = V_1 [ V_12 ] & V_7 -> V_13 ;
V_3 -> V_14 = V_1 [ V_15 ] & V_7 -> V_16 ;
V_3 -> V_17 = V_1 [ V_18 ] & V_7 -> V_19 ;
V_3 -> V_20 = F_2 ( V_1 [ V_21 ] &
V_7 -> V_22 ) ;
V_3 -> V_23 = F_3 ( V_1 [ V_24 ] &
V_7 -> V_25 ) ;
}
static void F_4 ( struct V_2 * V_3 , T_1 * V_1 ,
struct V_4 * V_5 )
{
const struct V_6 * V_7 = V_5 -> V_7 ;
V_1 [ V_9 ] &= ~ V_7 -> V_10 ;
V_1 [ V_9 ] |= V_3 -> V_8 & V_7 -> V_10 ;
V_1 [ V_12 ] &= ~ V_7 -> V_13 ;
V_1 [ V_12 ] |= V_3 -> V_11 & V_7 -> V_13 ;
V_1 [ V_15 ] &= ~ V_7 -> V_16 ;
V_1 [ V_15 ] |= V_3 -> V_14 & V_7 -> V_16 ;
V_1 [ V_18 ] &= ~ V_7 -> V_19 ;
V_1 [ V_18 ] |= V_3 -> V_17 & V_7 -> V_19 ;
V_1 [ V_21 ] &= ~ V_7 -> V_22 ;
V_1 [ V_21 ] |= F_5 ( V_3 -> V_20 ) &
V_7 -> V_22 ;
V_1 [ V_24 ] &= ~ V_7 -> V_25 ;
V_1 [ V_24 ] |= F_6 ( V_3 -> V_23 ) &
V_7 -> V_25 ;
}
static int F_7 ( struct V_26 * V_27 )
{
struct V_4 * V_5 = F_8 ( V_27 ) ;
const struct V_6 * V_7 = V_5 -> V_7 ;
return F_9 ( V_5 -> V_28 ,
V_7 -> V_29 ,
V_7 -> V_30 ,
0 ) ;
}
static int F_10 ( struct V_26 * V_27 )
{
struct V_4 * V_5 = F_8 ( V_27 ) ;
const struct V_6 * V_7 = V_5 -> V_7 ;
return F_9 ( V_5 -> V_28 ,
V_7 -> V_29 ,
V_7 -> V_30 ,
V_7 -> V_30 ) ;
}
static int F_11 ( struct V_26 * V_27 , struct V_2 * V_3 )
{
struct V_4 * V_5 = F_8 ( V_27 ) ;
const struct V_6 * V_7 = V_5 -> V_7 ;
unsigned long V_31 ;
unsigned long V_32 ;
T_1 V_1 [ V_33 ] ;
int V_34 ;
V_34 = F_12 ( V_5 -> V_28 ,
V_7 -> V_35 ,
V_1 , V_33 ) ;
if ( V_34 < 0 ) {
F_13 ( V_27 , L_1 , V_34 ) ;
return V_34 ;
}
if ( ! ( V_1 [ V_9 ] & V_7 -> V_36 ) ) {
F_14 ( V_27 , L_2 ) ;
return - V_37 ;
}
F_1 ( V_1 , V_3 , V_5 ) ;
F_15 ( V_3 , & V_31 ) ;
F_15 ( & V_5 -> V_38 , & V_32 ) ;
if ( V_5 -> V_39 == true && V_32 - V_31 == 1 )
memcpy ( V_3 , & V_5 -> V_38 , sizeof( struct V_2 ) ) ;
else
V_5 -> V_39 = false ;
return F_16 ( V_3 ) ;
}
static int F_17 ( struct V_26 * V_27 , struct V_2 * V_3 )
{
struct V_4 * V_5 = F_8 ( V_27 ) ;
const struct V_6 * V_7 = V_5 -> V_7 ;
T_1 V_1 [ V_33 ] ;
int V_34 ;
F_4 ( V_3 , V_1 , V_5 ) ;
V_34 = F_18 ( V_5 -> V_28 ,
V_7 -> V_35 ,
V_1 , V_33 ) ;
if ( V_34 < 0 )
F_13 ( V_27 , L_3 , V_34 ) ;
return V_34 ;
}
static int F_19 ( struct V_26 * V_27 , struct V_40 * V_41 )
{
struct V_4 * V_5 = F_8 ( V_27 ) ;
const struct V_6 * V_7 = V_5 -> V_7 ;
T_1 V_1 [ V_33 ] ;
int V_34 ;
unsigned int V_42 ;
V_1 [ V_9 ] = 0 ;
V_34 = F_12 ( V_5 -> V_28 ,
V_7 -> V_43 ,
& V_1 [ V_7 -> V_44 ] ,
V_7 -> V_45 ) ;
if ( V_34 < 0 )
return V_34 ;
F_1 ( V_1 , & V_41 -> time , V_5 ) ;
V_41 -> V_46 = ! ! ( V_1 [ V_24 ] & V_7 -> V_30 ) ;
V_34 = F_20 ( V_5 -> V_28 ,
V_7 -> V_47 ,
& V_42 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_42 & V_7 -> V_48 )
V_41 -> V_49 = 1 ;
else
V_41 -> V_49 = 0 ;
return 0 ;
}
static int F_21 ( struct V_26 * V_27 , struct V_40 * V_41 )
{
struct V_4 * V_5 = F_8 ( V_27 ) ;
const struct V_6 * V_7 = V_5 -> V_7 ;
T_1 V_1 [ V_33 ] ;
int V_34 ;
F_4 ( & V_41 -> time , V_1 , V_5 ) ;
V_34 = F_7 ( V_27 ) ;
if ( V_34 < 0 ) {
F_13 ( V_27 , L_4 , V_34 ) ;
return V_34 ;
}
V_34 = F_18 ( V_5 -> V_28 ,
V_7 -> V_43 ,
& V_1 [ V_7 -> V_44 ] ,
V_7 -> V_45 ) ;
if ( V_34 < 0 ) {
F_13 ( V_27 , L_5 , V_34 ) ;
return V_34 ;
}
F_1 ( V_1 , & V_5 -> V_38 , V_5 ) ;
if ( V_41 -> V_46 ) {
V_34 = F_10 ( V_27 ) ;
if ( V_34 < 0 ) {
F_13 ( V_27 , L_6 , V_34 ) ;
return V_34 ;
}
}
return V_34 ;
}
static int F_22 ( struct V_26 * V_27 ,
unsigned int V_46 )
{
if ( V_46 )
return F_10 ( V_27 ) ;
else
return F_7 ( V_27 ) ;
}
static T_2 F_23 ( int V_50 , void * V_1 )
{
struct V_4 * V_5 = V_1 ;
const struct V_6 * V_7 = V_5 -> V_7 ;
F_9 ( V_5 -> V_28 ,
V_7 -> V_29 ,
V_7 -> V_30 ,
0 ) ;
V_5 -> V_39 = true ;
F_24 ( V_5 -> V_51 , 1 , V_52 | V_53 ) ;
return V_54 ;
}
static int F_25 ( struct V_55 * V_56 )
{
struct V_4 * V_5 ;
const struct V_6 * V_7 ;
const struct V_57 * V_58 ;
int V_59 ;
T_1 V_1 [ V_33 ] ;
int V_34 ;
if ( ! V_56 -> V_27 . V_60 )
return - V_61 ;
V_58 = F_26 ( V_62 ,
V_56 -> V_27 . V_60 ) ;
V_5 = F_27 ( & V_56 -> V_27 , sizeof( * V_5 ) , V_63 ) ;
if ( ! V_5 )
return - V_64 ;
V_5 -> V_7 = V_58 -> V_1 ;
if ( F_28 ( V_56 -> V_27 . V_60 , L_7 ) ) {
struct V_65 * V_66 = F_8 ( V_56 -> V_27 . V_67 ) ;
if ( V_66 -> V_68 == V_69 )
V_5 -> V_7 = & V_70 ;
}
V_5 -> V_28 = F_29 ( V_56 -> V_27 . V_67 , NULL ) ;
if ( ! V_5 -> V_28 ) {
F_30 ( & V_56 -> V_27 , L_8 ) ;
return - V_61 ;
}
V_7 = V_5 -> V_7 ;
V_34 = F_9 ( V_5 -> V_28 ,
V_7 -> V_71 ,
V_7 -> V_72 ,
V_7 -> V_72 ) ;
if ( V_34 < 0 ) {
F_13 ( & V_56 -> V_27 , L_9 ) ;
return V_34 ;
}
V_34 = F_9 ( V_5 -> V_28 ,
V_7 -> V_73 ,
V_7 -> V_74 ,
V_7 -> V_74 ) ;
if ( V_34 < 0 ) {
F_13 ( & V_56 -> V_27 , L_10 ) ;
return V_34 ;
}
V_34 = F_9 ( V_5 -> V_28 ,
V_7 -> V_43 ,
V_7 -> V_75 ,
0 ) ;
if ( V_34 < 0 ) {
F_13 ( & V_56 -> V_27 , L_11 ) ;
return V_34 ;
}
V_34 = F_9 ( V_5 -> V_28 ,
V_7 -> V_43 ,
V_76 ,
V_76 ) ;
if ( V_34 < 0 ) {
F_13 ( & V_56 -> V_27 , L_11 ) ;
return V_34 ;
}
V_34 = F_9 ( V_5 -> V_28 ,
V_7 -> V_29 ,
V_7 -> V_77 ,
0 ) ;
if ( V_34 < 0 ) {
F_13 ( & V_56 -> V_27 , L_12 ) ;
return V_34 ;
}
V_1 [ V_9 ] = 0 ;
V_34 = F_12 ( V_5 -> V_28 ,
V_7 -> V_43 ,
& V_1 [ V_7 -> V_44 ] ,
V_7 -> V_45 ) ;
if ( V_34 < 0 ) {
F_13 ( & V_56 -> V_27 , L_13 ,
V_34 ) ;
return V_34 ;
}
F_31 ( V_56 , V_5 ) ;
V_59 = F_32 ( V_56 , L_14 ) ;
V_34 = F_33 ( & V_56 -> V_27 , V_59 , NULL ,
F_23 ,
V_78 | V_79 ,
L_14 , V_5 ) ;
if ( V_34 ) {
F_13 ( & V_56 -> V_27 , L_15 ,
V_59 , V_34 ) ;
return V_34 ;
}
V_5 -> V_51 = F_34 ( & V_56 -> V_27 , V_80 ,
& V_81 , V_82 ) ;
if ( F_35 ( V_5 -> V_51 ) )
return F_36 ( V_5 -> V_51 ) ;
F_1 ( V_1 , & V_5 -> V_38 , V_5 ) ;
V_5 -> V_39 = false ;
return V_34 ;
}
