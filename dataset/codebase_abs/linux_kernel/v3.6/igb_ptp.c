static T_1 F_1 ( const struct V_1 * V_2 )
{
T_2 V_3 ;
T_3 V_4 , V_5 ;
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
struct V_8 * V_9 = & V_7 -> V_9 ;
V_4 = F_3 ( V_10 ) ;
V_5 = F_3 ( V_11 ) ;
V_3 = ( ( T_2 ) V_5 ) << 32 ;
V_3 |= V_4 ;
return V_3 ;
}
static T_1 F_4 ( const struct V_1 * V_2 )
{
T_2 V_3 ;
T_3 V_4 , V_5 , V_12 ;
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
struct V_8 * V_9 = & V_7 -> V_9 ;
V_12 = F_3 ( V_13 ) ;
V_4 = F_3 ( V_10 ) ;
V_5 = F_3 ( V_11 ) ;
V_3 = ( ( T_2 ) V_5 ) << 32 ;
V_3 |= V_4 ;
return V_3 ;
}
static int F_5 ( struct V_14 * V_15 , T_4 V_16 )
{
T_2 V_17 ;
T_3 V_18 ;
int V_19 = 0 ;
struct V_6 * V_7 = F_2 ( V_15 , struct V_6 , V_20 ) ;
struct V_8 * V_9 = & V_7 -> V_9 ;
if ( V_16 < 0 ) {
V_19 = 1 ;
V_16 = - V_16 ;
}
V_17 = V_16 ;
V_17 <<= 14 ;
V_17 = F_6 ( V_17 , 1953125 ) ;
V_18 = 16 << V_21 ;
if ( V_19 )
V_18 -= V_17 ;
else
V_18 += V_17 ;
F_7 ( V_22 , V_23 | ( V_18 & V_24 ) ) ;
return 0 ;
}
static int F_8 ( struct V_14 * V_15 , T_4 V_16 )
{
T_2 V_17 ;
T_3 V_25 ;
int V_19 = 0 ;
struct V_6 * V_7 = F_2 ( V_15 , struct V_6 , V_20 ) ;
struct V_8 * V_9 = & V_7 -> V_9 ;
if ( V_16 < 0 ) {
V_19 = 1 ;
V_16 = - V_16 ;
}
V_17 = V_16 ;
V_17 <<= 26 ;
V_17 = F_6 ( V_17 , 1953125 ) ;
V_25 = V_17 & V_26 ;
if ( V_19 )
V_25 |= V_27 ;
F_7 ( V_22 , V_25 ) ;
return 0 ;
}
static int F_9 ( struct V_14 * V_15 , T_5 V_28 )
{
T_5 V_29 ;
unsigned long V_30 ;
struct V_6 * V_7 = F_2 ( V_15 , struct V_6 , V_20 ) ;
F_10 ( & V_7 -> V_31 , V_30 ) ;
V_29 = F_11 ( & V_7 -> V_32 ) ;
V_29 += V_28 ;
F_12 ( & V_7 -> V_32 , & V_7 -> V_2 , V_29 ) ;
F_13 ( & V_7 -> V_31 , V_30 ) ;
return 0 ;
}
static int F_14 ( struct V_14 * V_15 , struct V_33 * V_34 )
{
T_2 V_35 ;
T_3 V_36 ;
unsigned long V_30 ;
struct V_6 * V_7 = F_2 ( V_15 , struct V_6 , V_20 ) ;
F_10 ( & V_7 -> V_31 , V_30 ) ;
V_35 = F_11 ( & V_7 -> V_32 ) ;
F_13 ( & V_7 -> V_31 , V_30 ) ;
V_34 -> V_37 = F_15 ( V_35 , 1000000000 , & V_36 ) ;
V_34 -> V_38 = V_36 ;
return 0 ;
}
static int F_16 ( struct V_14 * V_15 , const struct V_33 * V_34 )
{
T_2 V_35 ;
unsigned long V_30 ;
struct V_6 * V_7 = F_2 ( V_15 , struct V_6 , V_20 ) ;
V_35 = V_34 -> V_37 * 1000000000ULL ;
V_35 += V_34 -> V_38 ;
F_10 ( & V_7 -> V_31 , V_30 ) ;
F_12 ( & V_7 -> V_32 , & V_7 -> V_2 , V_35 ) ;
F_13 ( & V_7 -> V_31 , V_30 ) ;
return 0 ;
}
static int F_17 ( struct V_14 * V_15 ,
struct V_39 * V_40 , int V_41 )
{
return - V_42 ;
}
static int F_18 ( struct V_14 * V_15 ,
struct V_39 * V_40 , int V_41 )
{
return - V_42 ;
}
static void F_19 ( struct V_43 * V_44 )
{
struct V_33 V_34 ;
struct V_6 * V_7 =
F_2 ( V_44 , struct V_6 , V_45 . V_44 ) ;
F_14 ( & V_7 -> V_20 , & V_34 ) ;
F_20 ( L_1 , V_34 . V_37 , V_34 . V_38 ) ;
F_21 ( & V_7 -> V_45 , V_46 ) ;
}
void F_22 ( struct V_6 * V_47 )
{
struct V_8 * V_9 = & V_47 -> V_9 ;
switch ( V_9 -> V_48 . type ) {
case V_49 :
case V_50 :
case V_51 :
case V_52 :
V_47 -> V_20 . V_53 = V_54 ;
strcpy ( V_47 -> V_20 . V_55 , L_2 ) ;
V_47 -> V_20 . V_56 = 62499999 ;
V_47 -> V_20 . V_57 = 0 ;
V_47 -> V_20 . V_58 = 0 ;
V_47 -> V_20 . V_59 = F_8 ;
V_47 -> V_20 . V_60 = F_9 ;
V_47 -> V_20 . V_61 = F_14 ;
V_47 -> V_20 . V_62 = F_16 ;
V_47 -> V_20 . V_63 = F_18 ;
V_47 -> V_2 . V_64 = F_4 ;
V_47 -> V_2 . V_65 = F_23 ( V_66 ) ;
V_47 -> V_2 . V_67 = 1 ;
V_47 -> V_2 . V_68 = 0 ;
F_7 ( V_69 , 0x0 ) ;
break;
case V_70 :
V_47 -> V_20 . V_53 = V_54 ;
strcpy ( V_47 -> V_20 . V_55 , L_3 ) ;
V_47 -> V_20 . V_56 = 1000000000 ;
V_47 -> V_20 . V_57 = 0 ;
V_47 -> V_20 . V_58 = 0 ;
V_47 -> V_20 . V_59 = F_5 ;
V_47 -> V_20 . V_60 = F_9 ;
V_47 -> V_20 . V_61 = F_14 ;
V_47 -> V_20 . V_62 = F_16 ;
V_47 -> V_20 . V_63 = F_17 ;
V_47 -> V_2 . V_64 = F_1 ;
V_47 -> V_2 . V_65 = F_23 ( 64 ) ;
V_47 -> V_2 . V_67 = 1 ;
V_47 -> V_2 . V_68 = V_21 ;
F_7 ( V_22 , V_23 | V_71 ) ;
break;
default:
V_47 -> V_72 = NULL ;
return;
}
F_24 () ;
F_12 ( & V_47 -> V_32 , & V_47 -> V_2 ,
F_25 ( F_26 () ) ) ;
F_27 ( & V_47 -> V_45 , F_19 ) ;
F_28 ( & V_47 -> V_31 ) ;
F_21 ( & V_47 -> V_45 , V_46 ) ;
V_47 -> V_72 = F_29 ( & V_47 -> V_20 ) ;
if ( F_30 ( V_47 -> V_72 ) ) {
V_47 -> V_72 = NULL ;
F_31 ( & V_47 -> V_73 -> V_74 , L_4 ) ;
} else
F_32 ( & V_47 -> V_73 -> V_74 , L_5 ,
V_47 -> V_75 -> V_55 ) ;
}
void F_33 ( struct V_6 * V_47 )
{
switch ( V_47 -> V_9 . V_48 . type ) {
case V_50 :
case V_49 :
case V_51 :
case V_52 :
case V_70 :
F_34 ( & V_47 -> V_45 ) ;
break;
default:
return;
}
if ( V_47 -> V_72 ) {
F_35 ( V_47 -> V_72 ) ;
F_32 ( & V_47 -> V_73 -> V_74 , L_6 ,
V_47 -> V_75 -> V_55 ) ;
}
}
void F_36 ( struct V_6 * V_47 ,
struct V_76 * V_77 ,
T_2 V_78 )
{
T_2 V_35 ;
unsigned long V_30 ;
switch ( V_47 -> V_9 . V_48 . type ) {
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_70 :
break;
default:
return;
}
F_10 ( & V_47 -> V_31 , V_30 ) ;
V_35 = F_37 ( & V_47 -> V_32 , V_78 ) ;
F_13 ( & V_47 -> V_31 , V_30 ) ;
memset ( V_77 , 0 , sizeof( * V_77 ) ) ;
V_77 -> V_79 = F_38 ( V_35 ) ;
}
