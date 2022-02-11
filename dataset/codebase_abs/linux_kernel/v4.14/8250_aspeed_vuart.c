static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_2 V_8 ;
V_8 = ( F_3 ( V_7 -> V_9 + V_10 ) << 8 ) |
( F_3 ( V_7 -> V_9 + V_11 ) ) ;
return snprintf ( V_5 , V_12 - 1 , L_1 , V_8 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_3 V_13 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned long V_14 ;
int V_15 ;
V_15 = F_5 ( V_5 , 0 , & V_14 ) ;
if ( V_15 )
return V_15 ;
F_6 ( V_14 >> 8 , V_7 -> V_9 + V_10 ) ;
F_6 ( V_14 >> 0 , V_7 -> V_9 + V_11 ) ;
return V_13 ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_4 V_16 ;
V_16 = F_3 ( V_7 -> V_9 + V_17 ) ;
V_16 &= V_18 ;
V_16 >>= V_19 ;
return snprintf ( V_5 , V_12 - 1 , L_2 , V_16 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_3 V_13 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned long V_14 ;
int V_15 ;
T_4 V_16 ;
V_15 = F_5 ( V_5 , 0 , & V_14 ) ;
if ( V_15 )
return V_15 ;
V_14 <<= V_19 ;
V_14 &= V_18 ;
V_16 = F_3 ( V_7 -> V_9 + V_17 ) ;
V_16 &= ~ V_18 ;
V_16 |= V_14 ;
F_6 ( V_16 , V_7 -> V_9 + V_17 ) ;
return V_13 ;
}
static void F_9 ( struct V_6 * V_7 , bool V_20 )
{
T_4 V_16 = F_3 ( V_7 -> V_9 + V_21 ) ;
if ( V_20 )
V_16 |= V_22 ;
else
V_16 &= ~ V_22 ;
F_6 ( V_16 , V_7 -> V_9 + V_21 ) ;
}
static void F_10 ( struct V_6 * V_7 ,
bool V_23 )
{
T_4 V_16 ;
V_16 = F_3 ( V_7 -> V_9 + V_21 ) ;
if ( ! V_23 )
V_16 |= V_24 ;
else
V_16 &= ~ V_24 ;
F_6 ( V_16 , V_7 -> V_9 + V_21 ) ;
}
static int F_11 ( struct V_25 * V_25 )
{
struct V_26 * V_26 = F_12 ( V_25 ) ;
struct V_6 * V_7 = V_26 -> V_27 . V_28 ;
int V_29 ;
V_29 = F_13 ( V_25 ) ;
if ( V_29 )
return V_29 ;
F_10 ( V_7 , false ) ;
return 0 ;
}
static void F_14 ( struct V_25 * V_25 )
{
struct V_26 * V_26 = F_12 ( V_25 ) ;
struct V_6 * V_7 = V_26 -> V_27 . V_28 ;
F_10 ( V_7 , true ) ;
F_15 ( V_25 ) ;
}
static int F_16 ( struct V_30 * V_31 )
{
struct V_26 V_27 ;
struct V_6 * V_7 ;
struct V_32 * V_33 ;
struct V_34 * V_35 ;
T_5 V_36 , V_37 ;
int V_29 ;
V_33 = V_31 -> V_2 . V_38 ;
V_7 = F_17 ( & V_31 -> V_2 , sizeof( * V_7 ) , V_39 ) ;
if ( ! V_7 )
return - V_40 ;
V_7 -> V_2 = & V_31 -> V_2 ;
V_35 = F_18 ( V_31 , V_41 , 0 ) ;
V_7 -> V_9 = F_19 ( & V_31 -> V_2 , V_35 ) ;
if ( F_20 ( V_7 -> V_9 ) )
return F_21 ( V_7 -> V_9 ) ;
memset ( & V_27 , 0 , sizeof( V_27 ) ) ;
V_27 . V_27 . V_28 = V_7 ;
V_27 . V_27 . V_42 = V_7 -> V_9 ;
V_27 . V_27 . V_43 = V_35 -> V_44 ;
V_27 . V_27 . V_45 = F_22 ( V_35 ) ;
V_27 . V_27 . V_46 = F_11 ;
V_27 . V_27 . V_47 = F_14 ;
V_27 . V_27 . V_2 = & V_31 -> V_2 ;
V_29 = F_23 ( & V_7 -> V_2 -> V_48 , & V_49 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( F_24 ( V_33 , L_3 , & V_36 ) ) {
V_7 -> V_36 = F_25 ( & V_31 -> V_2 , NULL ) ;
if ( F_20 ( V_7 -> V_36 ) ) {
F_26 ( & V_31 -> V_2 ,
L_4 ) ;
V_29 = F_21 ( V_7 -> V_36 ) ;
goto V_50;
}
V_29 = F_27 ( V_7 -> V_36 ) ;
if ( V_29 < 0 )
goto V_50;
V_36 = F_28 ( V_7 -> V_36 ) ;
}
if ( F_24 ( V_33 , L_5 , & V_37 ) == 0 )
V_27 . V_27 . V_51 = V_36 / ( 16 * V_37 ) ;
if ( F_24 ( V_33 , L_6 , & V_37 ) == 0 )
V_27 . V_27 . V_43 += V_37 ;
if ( F_24 ( V_33 , L_7 , & V_37 ) == 0 )
V_27 . V_27 . V_52 = V_37 ;
if ( F_24 ( V_33 , L_8 , & V_37 ) == 0 )
V_27 . V_27 . V_53 = V_37 ;
V_29 = F_29 ( V_33 , L_9 ) ;
if ( V_29 >= 0 )
V_27 . V_27 . line = V_29 ;
V_27 . V_27 . V_54 = F_30 ( V_33 , 0 ) ;
V_27 . V_27 . V_55 = V_56 ;
V_27 . V_27 . V_57 = V_58 ;
V_27 . V_27 . type = V_59 ;
V_27 . V_27 . V_60 = V_36 ;
V_27 . V_27 . V_61 = V_62 | V_63
| V_64 | V_65 | V_66 ;
if ( F_31 ( V_33 , L_10 ) )
V_27 . V_27 . V_61 |= V_67 ;
if ( V_27 . V_27 . V_53 )
V_27 . V_68 = V_69 ;
if ( F_31 ( V_33 , L_11 ) )
V_27 . V_68 |= V_70 ;
V_29 = F_32 ( & V_27 ) ;
if ( V_29 < 0 )
goto V_71;
V_7 -> line = V_29 ;
F_9 ( V_7 , true ) ;
F_10 ( V_7 , true ) ;
F_33 ( V_31 , V_7 ) ;
return 0 ;
V_71:
F_34 ( V_7 -> V_36 ) ;
F_35 ( V_27 . V_27 . V_54 ) ;
V_50:
F_36 ( & V_7 -> V_2 -> V_48 , & V_49 ) ;
return V_29 ;
}
static int F_37 ( struct V_30 * V_31 )
{
struct V_6 * V_7 = F_38 ( V_31 ) ;
F_9 ( V_7 , false ) ;
F_39 ( V_7 -> line ) ;
F_36 ( & V_7 -> V_2 -> V_48 , & V_49 ) ;
F_34 ( V_7 -> V_36 ) ;
return 0 ;
}
