int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_9 = 0 ;
int V_10 = 0 ;
if ( V_6 -> V_11 . V_3 == V_3 &&
V_6 -> V_11 . V_4 == V_4 )
return 0 ;
F_3 ( & V_8 -> V_12 ) ;
if ( V_6 -> V_9 ) {
V_9 = 1 ;
F_4 ( V_2 , 1 ) ;
}
F_5 ( V_6 ) ;
F_6 ( V_6 , L_1 ) ;
V_6 -> V_11 . V_3 = V_3 ;
V_6 -> V_11 . V_4 = V_4 ;
if ( V_4 != V_13 )
V_2 -> V_14 &= ~ V_15 ;
else
V_2 -> V_14 |= V_15 ;
V_10 = F_7 ( V_6 ) ;
if ( V_10 ) {
F_8 ( V_6 , L_2 ) ;
goto V_16;
}
if ( V_9 ) {
V_10 = F_9 ( V_2 ) ;
if ( V_10 )
F_8 ( V_6 , L_3 ) ;
}
V_16:
F_10 ( & V_8 -> V_12 ) ;
F_11 ( V_2 ) ;
return V_10 ;
}
static T_1 F_12 ( const struct V_17 * V_18 )
{
struct V_7 * V_8 =
F_13 ( V_18 , struct V_7 , V_19 ) ;
struct V_20 * V_2 = V_8 -> V_2 ;
return F_14 ( V_2 ) & V_18 -> V_21 ;
}
T_2 F_15 ( struct V_22 * V_23 )
{
T_2 V_24 , V_25 ;
struct V_26 * V_27 = (struct V_26 * ) V_23 ;
V_25 = ( T_2 ) F_16 ( V_27 -> V_28 ) ;
V_24 = ( ( T_2 ) F_17 ( V_27 -> V_29 ) + ! V_25 ) << 16 ;
return V_24 | V_25 ;
}
void F_18 ( struct V_7 * V_8 ,
struct V_30 * V_31 ,
T_2 V_32 )
{
unsigned long V_33 ;
T_2 V_34 ;
F_19 ( & V_8 -> V_35 , V_33 ) ;
V_34 = F_20 ( & V_8 -> clock , V_32 ) ;
F_21 ( & V_8 -> V_35 , V_33 ) ;
memset ( V_31 , 0 , sizeof( struct V_30 ) ) ;
V_31 -> V_36 = F_22 ( V_34 ) ;
}
void F_23 ( struct V_7 * V_8 )
{
if ( V_8 -> V_37 ) {
F_24 ( V_8 -> V_37 ) ;
V_8 -> V_37 = NULL ;
F_25 ( V_8 , L_4 ) ;
}
}
void F_26 ( struct V_7 * V_8 )
{
bool V_38 = F_27 ( V_8 -> V_39 +
V_8 -> V_40 ) ;
unsigned long V_33 ;
if ( V_38 ) {
F_28 ( & V_8 -> V_35 , V_33 ) ;
F_29 ( & V_8 -> clock ) ;
F_30 ( & V_8 -> V_35 , V_33 ) ;
V_8 -> V_39 = V_41 ;
}
}
static int F_31 ( struct V_42 * V_43 , T_3 V_44 )
{
T_2 V_45 ;
T_4 V_46 , V_47 ;
int V_48 = 0 ;
unsigned long V_33 ;
struct V_7 * V_8 = F_13 ( V_43 , struct V_7 ,
V_42 ) ;
if ( V_44 < 0 ) {
V_48 = 1 ;
V_44 = - V_44 ;
}
V_47 = V_8 -> V_49 ;
V_45 = V_47 ;
V_45 *= V_44 ;
V_46 = F_32 ( V_45 , 1000000000ULL ) ;
F_28 ( & V_8 -> V_35 , V_33 ) ;
F_29 ( & V_8 -> clock ) ;
V_8 -> V_19 . V_47 = V_48 ? V_47 - V_46 : V_47 + V_46 ;
F_30 ( & V_8 -> V_35 , V_33 ) ;
return 0 ;
}
static int F_33 ( struct V_42 * V_43 , T_5 V_44 )
{
struct V_7 * V_8 = F_13 ( V_43 , struct V_7 ,
V_42 ) ;
unsigned long V_33 ;
T_5 V_50 ;
F_28 ( & V_8 -> V_35 , V_33 ) ;
V_50 = F_29 ( & V_8 -> clock ) ;
V_50 += V_44 ;
F_34 ( & V_8 -> clock , & V_8 -> V_19 , V_50 ) ;
F_30 ( & V_8 -> V_35 , V_33 ) ;
return 0 ;
}
static int F_35 ( struct V_42 * V_43 , struct V_51 * V_52 )
{
struct V_7 * V_8 = F_13 ( V_43 , struct V_7 ,
V_42 ) ;
unsigned long V_33 ;
T_4 V_53 ;
T_2 V_54 ;
F_28 ( & V_8 -> V_35 , V_33 ) ;
V_54 = F_29 ( & V_8 -> clock ) ;
F_30 ( & V_8 -> V_35 , V_33 ) ;
V_52 -> V_55 = F_36 ( V_54 , V_56 , & V_53 ) ;
V_52 -> V_57 = V_53 ;
return 0 ;
}
static int F_37 ( struct V_42 * V_43 ,
const struct V_51 * V_52 )
{
struct V_7 * V_8 = F_13 ( V_43 , struct V_7 ,
V_42 ) ;
T_2 V_54 = F_38 ( V_52 ) ;
unsigned long V_33 ;
F_28 ( & V_8 -> V_35 , V_33 ) ;
F_34 ( & V_8 -> clock , & V_8 -> V_19 , V_54 ) ;
F_30 ( & V_8 -> V_35 , V_33 ) ;
return 0 ;
}
static int F_39 ( struct V_42 T_6 * V_43 ,
struct V_58 T_6 * V_59 ,
int T_6 V_60 )
{
return - V_61 ;
}
void F_40 ( struct V_7 * V_8 )
{
struct V_20 * V_2 = V_8 -> V_2 ;
unsigned long V_33 ;
T_2 V_54 ;
F_41 ( & V_8 -> V_35 ) ;
memset ( & V_8 -> V_19 , 0 , sizeof( V_8 -> V_19 ) ) ;
V_8 -> V_19 . V_62 = F_12 ;
V_8 -> V_19 . V_21 = F_42 ( 48 ) ;
V_8 -> V_19 . V_63 = 14 ;
V_8 -> V_19 . V_47 =
F_43 ( 1000 * V_2 -> V_64 . V_65 , V_8 -> V_19 . V_63 ) ;
V_8 -> V_49 = V_8 -> V_19 . V_47 ;
F_28 ( & V_8 -> V_35 , V_33 ) ;
F_34 ( & V_8 -> clock , & V_8 -> V_19 ,
F_44 ( F_45 () ) ) ;
F_30 ( & V_8 -> V_35 , V_33 ) ;
V_54 = F_46 ( & V_8 -> V_19 , V_8 -> V_19 . V_21 ) ;
F_47 ( V_54 , V_56 / 2 / V_66 ) ;
V_8 -> V_40 = V_54 ;
V_8 -> V_42 = V_67 ;
snprintf ( V_8 -> V_42 . V_68 , 16 , L_5 ) ;
V_8 -> V_37 = F_48 ( & V_8 -> V_42 ,
& V_8 -> V_69 -> V_2 ) ;
if ( F_49 ( V_8 -> V_37 ) ) {
V_8 -> V_37 = NULL ;
F_50 ( V_8 , L_6 ) ;
} else {
F_25 ( V_8 , L_7 ) ;
}
}
