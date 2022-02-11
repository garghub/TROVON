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
int F_21 ( struct V_10 * V_11 , struct V_45 * V_46 )
{
struct V_3 * V_4 = F_6 ( V_11 ) ;
struct V_47 V_48 ;
if ( F_22 ( & V_48 , V_46 -> V_49 , sizeof( V_48 ) ) )
return - V_50 ;
if ( V_48 . V_12 )
return - V_51 ;
switch ( V_48 . V_52 ) {
case V_53 :
V_4 -> V_54 = 0 ;
break;
case V_55 :
V_4 -> V_54 = 1 ;
break;
default:
return - V_56 ;
}
switch ( V_48 . V_57 ) {
case V_58 :
if ( V_4 -> V_59 )
V_4 -> V_59 = 0 ;
V_48 . V_57 = V_58 ;
break;
default:
V_4 -> V_59 = 1 ;
V_48 . V_57 = V_60 ;
break;
}
return F_23 ( V_46 -> V_49 , & V_48 , sizeof( V_48 ) ) ?
- V_50 : 0 ;
}
int F_24 ( struct V_10 * V_11 , struct V_45 * V_46 )
{
struct V_3 * V_4 = F_6 ( V_11 ) ;
struct V_47 V_48 ;
V_48 . V_12 = 0 ;
V_48 . V_52 = V_4 -> V_54 ? V_55 : V_53 ;
V_48 . V_57 = ( V_4 -> V_59 ?
V_60 : V_58 ) ;
return F_23 ( V_46 -> V_49 , & V_48 , sizeof( V_48 ) ) ?
- V_50 : 0 ;
}
static void F_25 ( unsigned long V_61 )
{
struct V_3 * V_4 = (struct V_3 * ) V_61 ;
T_4 V_37 ;
unsigned long V_12 ;
F_7 ( & V_4 -> V_15 , V_12 ) ;
V_37 = F_15 ( & V_4 -> V_25 ) ;
F_12 ( & V_4 -> V_15 , V_12 ) ;
F_26 ( & V_4 -> V_62 , V_63 + V_64 ) ;
}
void F_27 ( struct V_65 * V_66 )
{
struct V_10 * V_11 = F_28 ( V_66 ) ;
struct V_3 * V_4 = F_6 ( V_11 ) ;
V_4 -> V_31 . V_67 = V_68 ;
snprintf ( V_4 -> V_31 . V_69 , 16 , L_1 ) ;
V_4 -> V_31 . V_70 = 250000000 ;
V_4 -> V_31 . V_71 = 0 ;
V_4 -> V_31 . V_72 = 0 ;
V_4 -> V_31 . V_73 = 0 ;
V_4 -> V_31 . V_74 = 0 ;
V_4 -> V_31 . V_75 = F_13 ;
V_4 -> V_31 . V_76 = F_16 ;
V_4 -> V_31 . V_77 = F_17 ;
V_4 -> V_31 . V_78 = F_19 ;
V_4 -> V_31 . V_79 = F_20 ;
V_4 -> V_14 = F_29 ( V_4 -> V_80 ) ;
F_30 ( & V_4 -> V_15 ) ;
F_5 ( V_11 ) ;
F_31 ( & V_4 -> V_62 ) ;
V_4 -> V_62 . V_81 = ( unsigned long ) V_4 ;
V_4 -> V_62 . V_82 = F_25 ;
V_4 -> V_62 . V_83 = V_63 + V_64 ;
F_32 ( & V_4 -> V_62 ) ;
V_4 -> V_84 = F_33 ( & V_4 -> V_31 , & V_66 -> V_85 ) ;
if ( F_34 ( V_4 -> V_84 ) ) {
V_4 -> V_84 = NULL ;
F_35 ( L_2 ) ;
}
}
