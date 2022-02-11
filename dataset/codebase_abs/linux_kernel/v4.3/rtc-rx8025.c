static T_1 F_1 ( const struct V_1 * V_2 , T_2 V_3 )
{
return F_2 ( V_2 , V_3 << 4 ) ;
}
static int F_3 ( const struct V_1 * V_2 ,
T_2 V_3 , T_2 V_4 , T_2 * V_5 )
{
int V_6 = F_4 ( V_2 , V_3 << 4 , V_4 ,
V_5 ) ;
if ( V_6 != V_4 )
return V_6 < 0 ? V_6 : - V_7 ;
return 0 ;
}
static T_1 F_5 ( const struct V_1 * V_2 , T_2 V_3 ,
T_2 V_8 )
{
return F_6 ( V_2 , V_3 << 4 , V_8 ) ;
}
static T_1 F_7 ( const struct V_1 * V_2 ,
T_2 V_3 , T_2 V_4 , const T_2 * V_5 )
{
return F_8 ( V_2 , V_3 << 4 ,
V_4 , V_5 ) ;
}
static int F_9 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_10 ( V_10 ) ;
int V_13 ;
V_13 = F_1 ( V_12 -> V_2 , V_14 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_13 & V_15 )
F_11 ( V_10 , L_1 ) ;
if ( V_13 & V_16 ) {
F_11 ( V_10 , L_2 ) ;
return - V_17 ;
}
if ( ! ( V_13 & V_18 ) ) {
F_11 ( V_10 , L_3 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_13 = F_1 ( V_2 , V_14 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 &= ~ ( V_16 | V_15 ) ;
return F_5 ( V_2 , V_14 ,
V_13 | V_18 ) ;
}
static T_3 F_13 ( int V_19 , void * V_20 )
{
struct V_1 * V_2 = V_20 ;
struct V_11 * V_12 = F_14 ( V_2 ) ;
int V_21 ;
V_21 = F_1 ( V_2 , V_14 ) ;
if ( V_21 < 0 )
goto V_22;
if ( ! ( V_21 & V_18 ) )
F_11 ( & V_2 -> V_10 , L_4
L_5 ) ;
if ( V_21 & V_23 ) {
V_21 &= ~ V_23 ;
F_15 ( V_12 -> V_24 , 1 , V_25 | V_26 ) ;
}
if ( V_21 & V_27 ) {
V_21 &= V_27 ;
if ( F_5 ( V_2 , V_28 ,
V_12 -> V_29 & ~ V_30 ) )
goto V_22;
F_15 ( V_12 -> V_24 , 1 , V_31 | V_26 ) ;
}
V_22:
return V_32 ;
}
static int F_16 ( struct V_9 * V_10 , struct V_33 * V_34 )
{
struct V_11 * V_12 = F_10 ( V_10 ) ;
T_2 V_35 [ 7 ] ;
int V_36 ;
V_36 = F_9 ( V_10 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_3 ( V_12 -> V_2 , V_37 , 7 , V_35 ) ;
if ( V_36 )
return V_36 ;
F_17 ( V_10 , L_6
L_7 , V_38 ,
V_35 [ 0 ] , V_35 [ 1 ] , V_35 [ 2 ] , V_35 [ 3 ] , V_35 [ 4 ] ,
V_35 [ 5 ] , V_35 [ 6 ] ) ;
V_34 -> V_39 = F_18 ( V_35 [ V_37 ] & 0x7f ) ;
V_34 -> V_40 = F_18 ( V_35 [ V_41 ] & 0x7f ) ;
if ( V_12 -> V_29 & V_42 )
V_34 -> V_43 = F_18 ( V_35 [ V_44 ] & 0x3f ) ;
else
V_34 -> V_43 = F_18 ( V_35 [ V_44 ] & 0x1f ) % 12
+ ( V_35 [ V_44 ] & 0x20 ? 12 : 0 ) ;
V_34 -> V_45 = F_18 ( V_35 [ V_46 ] & 0x3f ) ;
V_34 -> V_47 = F_18 ( V_35 [ V_48 ] & 0x1f ) - 1 ;
V_34 -> V_49 = F_18 ( V_35 [ V_50 ] ) + 100 ;
F_17 ( V_10 , L_8 , V_38 ,
V_34 -> V_39 , V_34 -> V_40 , V_34 -> V_43 ,
V_34 -> V_45 , V_34 -> V_47 , V_34 -> V_49 ) ;
return F_19 ( V_34 ) ;
}
static int F_20 ( struct V_9 * V_10 , struct V_33 * V_34 )
{
struct V_11 * V_12 = F_10 ( V_10 ) ;
T_2 V_35 [ 7 ] ;
int V_6 ;
if ( ( V_34 -> V_49 < 100 ) || ( V_34 -> V_49 > 199 ) )
return - V_17 ;
V_35 [ V_37 ] = F_21 ( V_34 -> V_39 ) ;
V_35 [ V_41 ] = F_21 ( V_34 -> V_40 ) ;
if ( V_12 -> V_29 & V_42 )
V_35 [ V_44 ] = F_21 ( V_34 -> V_43 ) ;
else
V_35 [ V_44 ] = ( V_34 -> V_43 >= 12 ? 0x20 : 0 )
| F_21 ( ( V_34 -> V_43 + 11 ) % 12 + 1 ) ;
V_35 [ V_51 ] = F_21 ( V_34 -> V_52 ) ;
V_35 [ V_46 ] = F_21 ( V_34 -> V_45 ) ;
V_35 [ V_48 ] = F_21 ( V_34 -> V_47 + 1 ) ;
V_35 [ V_50 ] = F_21 ( V_34 -> V_49 - 100 ) ;
F_17 ( V_10 ,
L_9 ,
V_38 ,
V_35 [ 0 ] , V_35 [ 1 ] , V_35 [ 2 ] , V_35 [ 3 ] , V_35 [ 4 ] , V_35 [ 5 ] , V_35 [ 6 ] ) ;
V_6 = F_7 ( V_12 -> V_2 , V_37 , 7 , V_35 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_12 ( V_12 -> V_2 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_14 ( V_2 ) ;
T_2 V_53 [ 2 ] , V_13 ;
int V_54 = 0 ;
int V_36 ;
V_36 = F_3 ( V_12 -> V_2 , V_28 , 2 , V_53 ) ;
if ( V_36 )
goto V_22;
V_12 -> V_29 = V_53 [ 0 ] & ~ V_55 ;
if ( V_53 [ 1 ] & ( V_27 | V_56 ) ) {
F_11 ( & V_2 -> V_10 , L_10 ) ;
V_54 = 1 ;
}
if ( V_53 [ 1 ] & V_23 )
V_54 = 1 ;
if ( V_54 ) {
V_13 = V_53 [ 1 ] ;
V_13 &= ~ ( V_23 | V_56 |
V_27 ) ;
V_36 = F_5 ( V_2 , V_14 , V_13 ) ;
}
V_22:
return V_36 ;
}
static int F_23 ( struct V_9 * V_10 , struct V_57 * V_58 )
{
struct V_11 * V_12 = F_10 ( V_10 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
T_2 V_59 [ 2 ] ;
int V_13 , V_36 ;
if ( V_2 -> V_19 <= 0 )
return - V_17 ;
V_36 = F_3 ( V_2 , V_60 , 2 , V_59 ) ;
if ( V_36 )
return V_36 ;
V_13 = F_1 ( V_2 , V_14 ) ;
if ( V_13 < 0 )
return V_13 ;
F_17 ( V_10 , L_11 ,
V_38 , V_59 [ 0 ] , V_59 [ 1 ] , V_13 ) ;
V_58 -> time . V_39 = 0 ;
V_58 -> time . V_40 = F_18 ( V_59 [ 0 ] & 0x7f ) ;
if ( V_12 -> V_29 & V_42 )
V_58 -> time . V_43 = F_18 ( V_59 [ 1 ] & 0x3f ) ;
else
V_58 -> time . V_43 = F_18 ( V_59 [ 1 ] & 0x1f ) % 12
+ ( V_59 [ 1 ] & 0x20 ? 12 : 0 ) ;
V_58 -> time . V_52 = - 1 ;
V_58 -> time . V_45 = - 1 ;
V_58 -> time . V_47 = - 1 ;
V_58 -> time . V_49 = - 1 ;
F_17 ( V_10 , L_12 ,
V_38 ,
V_58 -> time . V_39 , V_58 -> time . V_40 , V_58 -> time . V_43 ,
V_58 -> time . V_45 , V_58 -> time . V_47 , V_58 -> time . V_49 ) ;
V_58 -> V_61 = ! ! ( V_12 -> V_29 & V_30 ) ;
V_58 -> V_62 = ( V_13 & V_27 ) && V_58 -> V_61 ;
return V_36 ;
}
static int F_24 ( struct V_9 * V_10 , struct V_57 * V_58 )
{
struct V_1 * V_2 = F_25 ( V_10 ) ;
struct V_11 * V_12 = F_10 ( V_10 ) ;
T_2 V_59 [ 2 ] ;
int V_36 ;
if ( V_2 -> V_19 <= 0 )
return - V_17 ;
V_59 [ 0 ] = F_21 ( V_58 -> time . V_40 ) ;
if ( V_12 -> V_29 & V_42 )
V_59 [ 1 ] = F_21 ( V_58 -> time . V_43 ) ;
else
V_59 [ 1 ] = ( V_58 -> time . V_43 >= 12 ? 0x20 : 0 )
| F_21 ( ( V_58 -> time . V_43 + 11 ) % 12 + 1 ) ;
F_17 ( V_10 , L_13 , V_38 , V_59 [ 0 ] , V_59 [ 1 ] ) ;
if ( V_12 -> V_29 & V_30 ) {
V_12 -> V_29 &= ~ V_30 ;
V_36 = F_5 ( V_12 -> V_2 , V_28 ,
V_12 -> V_29 ) ;
if ( V_36 )
return V_36 ;
}
V_36 = F_7 ( V_12 -> V_2 , V_60 , 2 , V_59 ) ;
if ( V_36 )
return V_36 ;
if ( V_58 -> V_61 ) {
V_12 -> V_29 |= V_30 ;
V_36 = F_5 ( V_12 -> V_2 , V_28 ,
V_12 -> V_29 ) ;
if ( V_36 )
return V_36 ;
}
return 0 ;
}
static int F_26 ( struct V_9 * V_10 , unsigned int V_61 )
{
struct V_11 * V_12 = F_10 ( V_10 ) ;
T_2 V_29 ;
int V_36 ;
V_29 = V_12 -> V_29 ;
if ( V_61 )
V_29 |= V_30 ;
else
V_29 &= ~ V_30 ;
if ( V_29 != V_12 -> V_29 ) {
V_12 -> V_29 = V_29 ;
V_36 = F_5 ( V_12 -> V_2 , V_28 ,
V_12 -> V_29 ) ;
if ( V_36 )
return V_36 ;
}
return 0 ;
}
static int F_27 ( struct V_9 * V_10 , int * V_63 )
{
struct V_1 * V_2 = F_25 ( V_10 ) ;
int V_64 ;
V_64 = F_1 ( V_2 , V_65 ) ;
if ( V_64 < 0 )
return V_64 ;
* V_63 = V_64 >= 64 ? V_64 - 128 : V_64 ;
if ( * V_63 > 0 )
( * V_63 ) -- ;
* V_63 *= - V_66 ;
return 0 ;
}
static int F_28 ( struct V_9 * V_10 , int V_63 )
{
struct V_1 * V_2 = F_25 ( V_10 ) ;
T_2 V_64 ;
int V_36 ;
V_63 /= - V_66 ;
if ( V_63 > V_67 )
V_63 = V_67 ;
else if ( V_63 < V_68 )
V_63 = V_68 ;
else if ( V_63 > 0 )
V_63 ++ ;
else if ( V_63 < 0 )
V_63 += 128 ;
V_64 = V_63 ;
V_36 = F_5 ( V_2 , V_65 , V_64 ) ;
if ( V_36 )
return V_36 ;
F_17 ( V_10 , L_14 , V_38 , V_64 ) ;
return 0 ;
}
static T_4 F_29 ( struct V_9 * V_10 ,
struct V_69 * V_70 ,
char * V_71 )
{
int V_36 , V_63 ;
V_36 = F_27 ( V_10 , & V_63 ) ;
if ( V_36 )
return V_36 ;
return sprintf ( V_71 , L_15 , V_63 ) ;
}
static T_4 F_30 ( struct V_9 * V_10 ,
struct V_69 * V_70 ,
const char * V_71 , T_5 V_72 )
{
int V_63 , V_36 ;
if ( sscanf ( V_71 , L_16 , & V_63 ) != 1 )
return - V_17 ;
V_36 = F_28 ( V_10 , V_63 ) ;
return V_36 ? V_36 : V_72 ;
}
static int F_31 ( struct V_9 * V_10 )
{
return F_32 ( V_10 , & V_73 ) ;
}
static void F_33 ( struct V_9 * V_10 )
{
F_34 ( V_10 , & V_73 ) ;
}
static int F_35 ( struct V_1 * V_2 ,
const struct V_74 * V_75 )
{
struct V_76 * V_77 = F_36 ( V_2 -> V_10 . V_78 ) ;
struct V_11 * V_12 ;
int V_36 = 0 ;
if ( ! F_37 ( V_77 , V_79
| V_80 ) ) {
F_38 ( & V_77 -> V_10 ,
L_17 ) ;
return - V_7 ;
}
V_12 = F_39 ( & V_2 -> V_10 , sizeof( * V_12 ) , V_81 ) ;
if ( ! V_12 ) {
return - V_82 ;
}
V_12 -> V_2 = V_2 ;
F_40 ( V_2 , V_12 ) ;
V_36 = F_22 ( V_2 ) ;
if ( V_36 )
return V_36 ;
V_12 -> V_24 = F_41 ( & V_2 -> V_10 , V_2 -> V_83 ,
& V_84 , V_85 ) ;
if ( F_42 ( V_12 -> V_24 ) ) {
F_38 ( & V_2 -> V_10 , L_18 ) ;
return F_43 ( V_12 -> V_24 ) ;
}
if ( V_2 -> V_19 > 0 ) {
F_44 ( & V_2 -> V_10 , L_19 , V_2 -> V_19 ) ;
V_36 = F_45 ( & V_2 -> V_10 , V_2 -> V_19 , NULL ,
F_13 , 0 , L_20 ,
V_2 ) ;
if ( V_36 ) {
F_38 ( & V_2 -> V_10 , L_21 ) ;
V_2 -> V_19 = 0 ;
}
}
V_12 -> V_24 -> V_86 = 1 ;
V_36 = F_31 ( & V_2 -> V_10 ) ;
return V_36 ;
}
static int F_46 ( struct V_1 * V_2 )
{
F_33 ( & V_2 -> V_10 ) ;
return 0 ;
}
