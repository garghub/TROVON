static enum V_1 F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
T_1 V_7 ;
F_2 ( V_5 -> V_8 , V_9 , & V_7 ) ;
if ( V_7 & V_10 )
return V_11 ;
if ( V_7 & V_12 )
return V_13 ;
return V_14 ;
}
static void F_3 ( struct V_4 * V_5 , T_1 V_15 )
{
F_4 ( V_15 , V_5 -> V_16 ) ;
}
static void F_5 ( struct V_4 * V_5 , T_1 V_15 )
{
F_6 ( V_5 -> V_8 , V_17 , V_15 ) ;
}
static void F_7 ( struct V_4 * V_5 )
{
unsigned int V_18 ;
T_1 V_15 ;
F_2 ( V_5 -> V_8 , V_19 , & V_15 ) ;
V_15 &= ~ V_20 ;
V_15 |= 1 << V_21 ;
F_6 ( V_5 -> V_8 , V_19 , V_15 ) ;
for ( V_18 = 0 ; V_18 < V_22 ; V_18 ++ )
V_5 -> V_23 ( V_5 , 0 ) ;
}
static int F_8 ( struct V_4 * V_5 , T_1 V_24 ,
T_1 V_25 , int V_26 )
{
unsigned int V_27 ;
T_1 V_15 ;
V_27 = V_26 / 10 ;
if ( V_26 % 10 )
V_27 ++ ;
do {
F_2 ( V_5 -> V_8 , V_9 , & V_15 ) ;
if ( ( V_15 & V_24 ) == V_25 )
return 0 ;
F_9 ( 10 , 11 ) ;
} while ( -- V_27 );
return - V_28 ;
}
static int F_10 ( struct V_2 * V_3 ,
struct V_29 * V_30 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_8 * V_31 = V_5 -> V_8 ;
int V_32 ;
T_1 V_15 ;
F_2 ( V_31 , V_33 , & V_15 ) ;
V_15 &= ~ V_34 ;
F_6 ( V_31 , V_33 , V_15 ) ;
V_15 &= ~ V_35 ;
F_6 ( V_31 , V_33 , V_15 ) ;
F_7 ( V_5 ) ;
V_32 = F_8 ( V_5 , V_36 , 0 , 10 ) ;
if ( V_32 )
F_11 ( & V_3 -> V_37 , L_1 ) ;
return V_32 ;
}
static int F_12 ( struct V_2 * V_3 ,
struct V_29 * V_30 ,
const char * V_38 , T_2 V_39 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_8 * V_31 = V_5 -> V_8 ;
T_1 V_40 , V_15 ;
int V_32 ;
V_40 = V_30 ? V_30 -> V_41 : 0 ;
if ( V_40 & V_42 ) {
F_11 ( & V_3 -> V_37 , L_2 ) ;
return - V_43 ;
}
if ( V_40 & V_44 )
V_5 -> V_45 = 8 ;
else if ( V_40 & V_46 )
V_5 -> V_45 = 4 ;
else
V_5 -> V_45 = 1 ;
F_2 ( V_31 , V_9 , & V_15 ) ;
if ( ! ( V_15 & V_12 ) ) {
F_11 ( & V_3 -> V_37 , L_3 , V_15 ) ;
return - V_47 ;
}
if ( V_15 & V_36 ) {
F_13 ( & V_3 -> V_37 , L_4 ) ;
V_32 = F_10 ( V_3 , V_30 ) ;
if ( V_32 )
return V_32 ;
}
F_2 ( V_31 , V_19 , & V_15 ) ;
V_15 |= V_48 ;
F_6 ( V_31 , V_19 , V_15 ) ;
F_2 ( V_31 , V_19 , & V_15 ) ;
V_15 |= V_49 ;
F_6 ( V_31 , V_19 , V_15 ) ;
F_7 ( V_5 ) ;
F_2 ( V_31 , V_33 , & V_15 ) ;
V_15 |= V_35 ;
F_6 ( V_31 , V_33 , V_15 ) ;
V_32 = F_8 ( V_5 , V_36 ,
V_36 , 10 ) ;
if ( V_32 ) {
F_13 ( & V_3 -> V_37 , L_5 ) ;
return V_32 ;
}
F_7 ( V_5 ) ;
F_2 ( V_31 , V_33 , & V_15 ) ;
V_15 |= V_34 ;
F_6 ( V_31 , V_33 , V_15 ) ;
F_2 ( V_31 , V_19 , & V_15 ) ;
V_15 &= ~ V_20 ;
V_15 |= V_5 -> V_45 << V_21 ;
F_6 ( V_31 , V_19 , V_15 ) ;
return 0 ;
}
static inline int F_14 ( struct V_2 * V_3 , T_2 V_50 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
T_1 V_15 ;
F_2 ( V_5 -> V_8 , V_9 , & V_15 ) ;
if ( V_15 & V_51 ) {
F_11 ( & V_3 -> V_37 , L_6 ,
V_50 ) ;
return - V_52 ;
}
return 0 ;
}
static int F_15 ( struct V_2 * V_3 , const char * V_38 ,
T_2 V_39 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
const T_1 * V_53 ;
T_2 V_54 , V_55 ;
int V_7 = 0 ;
T_1 V_56 ;
V_53 = ( T_1 * ) V_38 ;
V_55 = V_39 ;
V_54 = 0 ;
while ( V_55 >= 4 ) {
V_5 -> V_23 ( V_5 , * V_53 ++ ) ;
V_54 += 4 ;
V_55 -= 4 ;
if ( V_57 && ! ( V_54 % V_58 ) ) {
V_7 = F_14 ( V_3 , V_54 ) ;
if ( V_7 < 0 )
return V_7 ;
}
}
V_56 = F_16 ( V_55 * 8 ) - 1 ;
if ( V_56 )
V_5 -> V_23 ( V_5 , * V_53 & V_56 ) ;
if ( V_57 )
V_7 = F_14 ( V_3 , V_39 ) ;
return V_7 ;
}
static int F_17 ( struct V_2 * V_3 ,
struct V_29 * V_30 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_8 * V_31 = V_5 -> V_8 ;
int V_32 ;
T_1 V_56 ;
T_1 V_15 ;
V_32 = F_10 ( V_3 , V_30 ) ;
if ( V_32 )
return V_32 ;
F_2 ( V_31 , V_59 , & V_15 ) ;
if ( V_15 & V_60 ) {
F_11 ( & V_3 -> V_37 , L_7 ) ;
return - V_52 ;
}
F_2 ( V_31 , V_19 , & V_15 ) ;
V_15 &= ~ V_48 ;
V_15 &= ~ V_49 ;
F_6 ( V_31 , V_19 , V_15 ) ;
V_56 = V_61 | V_62 ;
V_32 = F_8 ( V_5 , V_56 , V_56 , V_63 ) ;
if ( V_32 )
F_11 ( & V_3 -> V_37 , L_8 ) ;
return V_32 ;
}
static T_3 F_18 ( struct V_64 * V_37 , char * V_38 )
{
return snprintf ( V_38 , 3 , L_9 , V_57 ) ;
}
static T_3 F_19 ( struct V_64 * V_65 , const char * V_38 ,
T_2 V_39 )
{
int V_32 ;
V_32 = F_20 ( V_38 , & V_57 ) ;
if ( V_32 )
return V_32 ;
return V_39 ;
}
static int F_21 ( struct V_8 * V_31 ,
const struct V_66 * V_67 )
{
struct V_4 * V_5 ;
T_4 V_68 , V_15 ;
int V_32 ;
F_22 ( V_31 , V_69 , & V_15 ) ;
if ( V_15 != V_70 ) {
F_11 ( & V_31 -> V_37 , L_10 , V_15 ) ;
return - V_47 ;
}
V_5 = F_23 ( & V_31 -> V_37 , sizeof( * V_5 ) , V_71 ) ;
if ( ! V_5 )
return - V_72 ;
F_22 ( V_31 , V_73 , & V_68 ) ;
if ( ! ( V_68 & V_74 ) ) {
V_68 |= V_74 ;
F_24 ( V_31 , V_73 , V_68 ) ;
}
V_32 = F_25 ( V_31 , V_75 , L_11 ) ;
if ( V_32 ) {
F_11 ( & V_31 -> V_37 , L_12 ) ;
goto V_76;
}
V_5 -> V_8 = V_31 ;
V_5 -> V_23 = F_3 ;
V_5 -> V_16 = F_26 ( V_31 , V_75 , 0 ) ;
if ( ! V_5 -> V_16 ) {
F_13 ( & V_31 -> V_37 , L_13 ) ;
V_5 -> V_23 = F_5 ;
}
snprintf ( V_5 -> V_77 , sizeof( V_5 -> V_77 ) , L_14 ,
V_78 , F_27 ( V_31 ) ) ;
V_32 = F_28 ( & V_31 -> V_37 , V_5 -> V_77 ,
& V_79 , V_5 ) ;
if ( V_32 )
goto V_80;
V_32 = F_29 ( & V_81 . V_82 ,
& V_83 ) ;
if ( V_32 ) {
F_11 ( & V_31 -> V_37 , L_15 ) ;
F_30 ( & V_31 -> V_37 ) ;
goto V_80;
}
return 0 ;
V_80:
F_31 ( V_31 , V_5 -> V_16 ) ;
F_32 ( V_31 , V_75 ) ;
V_76:
V_68 &= ~ V_74 ;
F_24 ( V_31 , V_73 , V_68 ) ;
return V_32 ;
}
static void F_33 ( struct V_8 * V_31 )
{
struct V_2 * V_3 = F_34 ( V_31 ) ;
struct V_4 * V_5 = V_3 -> V_6 ;
T_4 V_68 ;
F_35 ( & V_81 . V_82 , & V_83 ) ;
F_30 ( & V_31 -> V_37 ) ;
F_31 ( V_31 , V_5 -> V_16 ) ;
F_32 ( V_31 , V_75 ) ;
F_22 ( V_31 , V_73 , & V_68 ) ;
V_68 &= ~ V_74 ;
F_24 ( V_31 , V_73 , V_68 ) ;
}
