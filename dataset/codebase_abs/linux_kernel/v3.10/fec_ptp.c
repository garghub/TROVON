static T_1 F_1 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
T_2 V_5 ;
V_5 = F_3 ( V_4 -> V_6 + V_7 ) ;
V_5 |= V_8 ;
F_4 ( V_5 , V_4 -> V_6 + V_7 ) ;
return F_3 ( V_4 -> V_6 + V_9 ) ;
}
void F_5 ( struct V_10 * V_11 )
{
struct V_3 * V_4 = F_6 ( V_11 ) ;
unsigned long V_12 ;
int V_13 ;
V_13 = 1000000000 / V_4 -> V_14 ;
F_7 ( & V_4 -> V_15 , V_12 ) ;
F_4 ( V_13 << V_16 , V_4 -> V_6 + V_17 ) ;
F_4 ( 0 , V_4 -> V_6 + V_18 ) ;
F_4 ( V_19 , V_4 -> V_6 + V_7 ) ;
memset ( & V_4 -> V_2 , 0 , sizeof( V_4 -> V_2 ) ) ;
V_4 -> V_2 . V_20 = F_1 ;
V_4 -> V_2 . V_21 = F_8 ( 32 ) ;
V_4 -> V_2 . V_22 = 31 ;
V_4 -> V_2 . V_23 = V_24 ;
F_9 ( & V_4 -> V_25 , & V_4 -> V_2 , F_10 ( F_11 () ) ) ;
F_12 ( & V_4 -> V_15 , V_12 ) ;
}
static int F_13 ( struct V_26 * V_27 , T_3 V_28 )
{
T_4 V_29 ;
unsigned long V_12 ;
int V_30 = 0 ;
T_2 V_23 = V_24 ;
struct V_3 * V_4 =
F_2 ( V_27 , struct V_3 , V_31 ) ;
if ( V_28 < 0 ) {
V_28 = - V_28 ;
V_30 = 1 ;
}
V_29 = V_23 ;
V_29 *= V_28 ;
V_29 = F_14 ( V_29 , 1000000000ULL ) ;
F_7 ( & V_4 -> V_15 , V_12 ) ;
F_15 ( & V_4 -> V_25 ) ;
V_4 -> V_2 . V_23 = V_30 ? V_23 - V_29 : V_23 + V_29 ;
F_12 ( & V_4 -> V_15 , V_12 ) ;
return 0 ;
}
static int F_16 ( struct V_26 * V_27 , T_5 V_32 )
{
struct V_3 * V_4 =
F_2 ( V_27 , struct V_3 , V_31 ) ;
unsigned long V_12 ;
T_4 V_33 ;
F_7 ( & V_4 -> V_15 , V_12 ) ;
V_33 = F_15 ( & V_4 -> V_25 ) ;
V_33 += V_32 ;
F_9 ( & V_4 -> V_25 , & V_4 -> V_2 , V_33 ) ;
F_12 ( & V_4 -> V_15 , V_12 ) ;
return 0 ;
}
static int F_17 ( struct V_26 * V_27 , struct V_34 * V_35 )
{
struct V_3 * V_36 =
F_2 ( V_27 , struct V_3 , V_31 ) ;
T_4 V_37 ;
T_2 V_38 ;
unsigned long V_12 ;
F_7 ( & V_36 -> V_15 , V_12 ) ;
V_37 = F_15 ( & V_36 -> V_25 ) ;
F_12 ( & V_36 -> V_15 , V_12 ) ;
V_35 -> V_39 = F_18 ( V_37 , 1000000000ULL , & V_38 ) ;
V_35 -> V_40 = V_38 ;
return 0 ;
}
static int F_19 ( struct V_26 * V_27 ,
const struct V_34 * V_35 )
{
struct V_3 * V_4 =
F_2 ( V_27 , struct V_3 , V_31 ) ;
T_4 V_37 ;
unsigned long V_12 ;
V_37 = V_35 -> V_39 * 1000000000ULL ;
V_37 += V_35 -> V_40 ;
F_7 ( & V_4 -> V_15 , V_12 ) ;
F_9 ( & V_4 -> V_25 , & V_4 -> V_2 , V_37 ) ;
F_12 ( & V_4 -> V_15 , V_12 ) ;
return 0 ;
}
static int F_20 ( struct V_26 * V_27 ,
struct V_41 * V_42 , int V_43 )
{
return - V_44 ;
}
int F_21 ( struct V_10 * V_11 , struct V_45 * V_46 , int V_47 )
{
struct V_3 * V_4 = F_6 ( V_11 ) ;
struct V_48 V_49 ;
if ( F_22 ( & V_49 , V_46 -> V_50 , sizeof( V_49 ) ) )
return - V_51 ;
if ( V_49 . V_12 )
return - V_52 ;
switch ( V_49 . V_53 ) {
case V_54 :
V_4 -> V_55 = 0 ;
break;
case V_56 :
V_4 -> V_55 = 1 ;
break;
default:
return - V_57 ;
}
switch ( V_49 . V_58 ) {
case V_59 :
if ( V_4 -> V_60 )
V_4 -> V_60 = 0 ;
V_49 . V_58 = V_59 ;
break;
default:
V_4 -> V_60 = 1 ;
V_49 . V_58 = V_61 ;
break;
}
return F_23 ( V_46 -> V_50 , & V_49 , sizeof( V_49 ) ) ?
- V_51 : 0 ;
}
static void F_24 ( unsigned long V_62 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 ;
T_4 V_37 ;
unsigned long V_12 ;
F_7 ( & V_4 -> V_15 , V_12 ) ;
V_37 = F_15 ( & V_4 -> V_25 ) ;
F_12 ( & V_4 -> V_15 , V_12 ) ;
F_25 ( & V_4 -> V_63 , V_64 + V_65 ) ;
}
void F_26 ( struct V_10 * V_11 , struct V_66 * V_67 )
{
struct V_3 * V_4 = F_6 ( V_11 ) ;
V_4 -> V_31 . V_68 = V_69 ;
snprintf ( V_4 -> V_31 . V_70 , 16 , L_1 ) ;
V_4 -> V_31 . V_71 = 250000000 ;
V_4 -> V_31 . V_72 = 0 ;
V_4 -> V_31 . V_73 = 0 ;
V_4 -> V_31 . V_74 = 0 ;
V_4 -> V_31 . V_75 = 0 ;
V_4 -> V_31 . V_76 = F_13 ;
V_4 -> V_31 . V_77 = F_16 ;
V_4 -> V_31 . V_78 = F_17 ;
V_4 -> V_31 . V_79 = F_19 ;
V_4 -> V_31 . V_80 = F_20 ;
V_4 -> V_14 = F_27 ( V_4 -> V_81 ) ;
F_28 ( & V_4 -> V_15 ) ;
F_5 ( V_11 ) ;
F_29 ( & V_4 -> V_63 ) ;
V_4 -> V_63 . V_82 = ( unsigned long ) V_4 ;
V_4 -> V_63 . V_83 = F_24 ;
V_4 -> V_63 . V_84 = V_64 + V_65 ;
F_30 ( & V_4 -> V_63 ) ;
V_4 -> V_85 = F_31 ( & V_4 -> V_31 , & V_67 -> V_86 ) ;
if ( F_32 ( V_4 -> V_85 ) ) {
V_4 -> V_85 = NULL ;
F_33 ( L_2 ) ;
}
}
