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
struct V_21 * V_22 = & V_12 -> V_23 -> V_24 ;
int V_25 ;
F_15 ( V_22 ) ;
V_25 = F_1 ( V_2 , V_14 ) ;
if ( V_25 < 0 )
goto V_26;
if ( ! ( V_25 & V_18 ) )
F_11 ( & V_2 -> V_10 , L_4
L_5 ) ;
if ( V_25 & V_27 ) {
V_25 &= ~ V_27 ;
F_16 ( V_12 -> V_23 , 1 , V_28 | V_29 ) ;
}
if ( V_25 & V_30 ) {
V_25 &= V_30 ;
if ( F_5 ( V_2 , V_31 ,
V_12 -> V_32 & ~ V_33 ) )
goto V_26;
F_16 ( V_12 -> V_23 , 1 , V_34 | V_29 ) ;
}
V_26:
F_17 ( V_22 ) ;
return V_35 ;
}
static int F_18 ( struct V_9 * V_10 , struct V_36 * V_37 )
{
struct V_11 * V_12 = F_10 ( V_10 ) ;
T_2 V_38 [ 7 ] ;
int V_39 ;
V_39 = F_9 ( V_10 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_3 ( V_12 -> V_2 , V_40 , 7 , V_38 ) ;
if ( V_39 )
return V_39 ;
F_19 ( V_10 , L_6
L_7 , V_41 ,
V_38 [ 0 ] , V_38 [ 1 ] , V_38 [ 2 ] , V_38 [ 3 ] , V_38 [ 4 ] ,
V_38 [ 5 ] , V_38 [ 6 ] ) ;
V_37 -> V_42 = F_20 ( V_38 [ V_40 ] & 0x7f ) ;
V_37 -> V_43 = F_20 ( V_38 [ V_44 ] & 0x7f ) ;
if ( V_12 -> V_32 & V_45 )
V_37 -> V_46 = F_20 ( V_38 [ V_47 ] & 0x3f ) ;
else
V_37 -> V_46 = F_20 ( V_38 [ V_47 ] & 0x1f ) % 12
+ ( V_38 [ V_47 ] & 0x20 ? 12 : 0 ) ;
V_37 -> V_48 = F_20 ( V_38 [ V_49 ] & 0x3f ) ;
V_37 -> V_50 = F_20 ( V_38 [ V_51 ] & 0x1f ) - 1 ;
V_37 -> V_52 = F_20 ( V_38 [ V_53 ] ) + 100 ;
F_19 ( V_10 , L_8 , V_41 ,
V_37 -> V_42 , V_37 -> V_43 , V_37 -> V_46 ,
V_37 -> V_48 , V_37 -> V_50 , V_37 -> V_52 ) ;
return F_21 ( V_37 ) ;
}
static int F_22 ( struct V_9 * V_10 , struct V_36 * V_37 )
{
struct V_11 * V_12 = F_10 ( V_10 ) ;
T_2 V_38 [ 7 ] ;
int V_6 ;
if ( ( V_37 -> V_52 < 100 ) || ( V_37 -> V_52 > 199 ) )
return - V_17 ;
V_38 [ V_40 ] = F_23 ( V_37 -> V_42 ) ;
V_38 [ V_44 ] = F_23 ( V_37 -> V_43 ) ;
if ( V_12 -> V_32 & V_45 )
V_38 [ V_47 ] = F_23 ( V_37 -> V_46 ) ;
else
V_38 [ V_47 ] = ( V_37 -> V_46 >= 12 ? 0x20 : 0 )
| F_23 ( ( V_37 -> V_46 + 11 ) % 12 + 1 ) ;
V_38 [ V_54 ] = F_23 ( V_37 -> V_55 ) ;
V_38 [ V_49 ] = F_23 ( V_37 -> V_48 ) ;
V_38 [ V_51 ] = F_23 ( V_37 -> V_50 + 1 ) ;
V_38 [ V_53 ] = F_23 ( V_37 -> V_52 - 100 ) ;
F_19 ( V_10 ,
L_9 ,
V_41 ,
V_38 [ 0 ] , V_38 [ 1 ] , V_38 [ 2 ] , V_38 [ 3 ] , V_38 [ 4 ] , V_38 [ 5 ] , V_38 [ 6 ] ) ;
V_6 = F_7 ( V_12 -> V_2 , V_40 , 7 , V_38 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_12 ( V_12 -> V_2 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_14 ( V_2 ) ;
T_2 V_56 [ 2 ] , V_13 ;
int V_57 = 0 ;
int V_39 ;
V_39 = F_3 ( V_12 -> V_2 , V_31 , 2 , V_56 ) ;
if ( V_39 )
goto V_26;
V_12 -> V_32 = V_56 [ 0 ] & ~ V_58 ;
if ( V_56 [ 1 ] & ( V_30 | V_59 ) ) {
F_11 ( & V_2 -> V_10 , L_10 ) ;
V_57 = 1 ;
}
if ( V_56 [ 1 ] & V_27 )
V_57 = 1 ;
if ( V_57 ) {
V_13 = V_56 [ 1 ] ;
V_13 &= ~ ( V_27 | V_59 |
V_30 ) ;
V_39 = F_5 ( V_2 , V_14 , V_13 ) ;
}
V_26:
return V_39 ;
}
static int F_25 ( struct V_9 * V_10 , struct V_60 * V_61 )
{
struct V_11 * V_12 = F_10 ( V_10 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
T_2 V_62 [ 2 ] ;
int V_13 , V_39 ;
if ( V_2 -> V_19 <= 0 )
return - V_17 ;
V_39 = F_3 ( V_2 , V_63 , 2 , V_62 ) ;
if ( V_39 )
return V_39 ;
V_13 = F_1 ( V_2 , V_14 ) ;
if ( V_13 < 0 )
return V_13 ;
F_19 ( V_10 , L_11 ,
V_41 , V_62 [ 0 ] , V_62 [ 1 ] , V_13 ) ;
V_61 -> time . V_42 = 0 ;
V_61 -> time . V_43 = F_20 ( V_62 [ 0 ] & 0x7f ) ;
if ( V_12 -> V_32 & V_45 )
V_61 -> time . V_46 = F_20 ( V_62 [ 1 ] & 0x3f ) ;
else
V_61 -> time . V_46 = F_20 ( V_62 [ 1 ] & 0x1f ) % 12
+ ( V_62 [ 1 ] & 0x20 ? 12 : 0 ) ;
V_61 -> time . V_55 = - 1 ;
V_61 -> time . V_48 = - 1 ;
V_61 -> time . V_50 = - 1 ;
V_61 -> time . V_52 = - 1 ;
F_19 ( V_10 , L_12 ,
V_41 ,
V_61 -> time . V_42 , V_61 -> time . V_43 , V_61 -> time . V_46 ,
V_61 -> time . V_48 , V_61 -> time . V_50 , V_61 -> time . V_52 ) ;
V_61 -> V_64 = ! ! ( V_12 -> V_32 & V_33 ) ;
V_61 -> V_65 = ( V_13 & V_30 ) && V_61 -> V_64 ;
return V_39 ;
}
static int F_26 ( struct V_9 * V_10 , struct V_60 * V_61 )
{
struct V_1 * V_2 = F_27 ( V_10 ) ;
struct V_11 * V_12 = F_10 ( V_10 ) ;
T_2 V_62 [ 2 ] ;
int V_39 ;
if ( V_2 -> V_19 <= 0 )
return - V_17 ;
if ( V_61 -> time . V_42 ) {
T_4 V_66 = F_28 ( & V_61 -> time ) ;
V_66 += 60 - V_61 -> time . V_42 ;
F_29 ( V_66 , & V_61 -> time ) ;
}
V_62 [ 0 ] = F_23 ( V_61 -> time . V_43 ) ;
if ( V_12 -> V_32 & V_45 )
V_62 [ 1 ] = F_23 ( V_61 -> time . V_46 ) ;
else
V_62 [ 1 ] = ( V_61 -> time . V_46 >= 12 ? 0x20 : 0 )
| F_23 ( ( V_61 -> time . V_46 + 11 ) % 12 + 1 ) ;
F_19 ( V_10 , L_13 , V_41 , V_62 [ 0 ] , V_62 [ 1 ] ) ;
if ( V_12 -> V_32 & V_33 ) {
V_12 -> V_32 &= ~ V_33 ;
V_39 = F_5 ( V_12 -> V_2 , V_31 ,
V_12 -> V_32 ) ;
if ( V_39 )
return V_39 ;
}
V_39 = F_7 ( V_12 -> V_2 , V_63 , 2 , V_62 ) ;
if ( V_39 )
return V_39 ;
if ( V_61 -> V_64 ) {
V_12 -> V_32 |= V_33 ;
V_39 = F_5 ( V_12 -> V_2 , V_31 ,
V_12 -> V_32 ) ;
if ( V_39 )
return V_39 ;
}
return 0 ;
}
static int F_30 ( struct V_9 * V_10 , unsigned int V_64 )
{
struct V_11 * V_12 = F_10 ( V_10 ) ;
T_2 V_32 ;
int V_39 ;
V_32 = V_12 -> V_32 ;
if ( V_64 )
V_32 |= V_33 ;
else
V_32 &= ~ V_33 ;
if ( V_32 != V_12 -> V_32 ) {
V_12 -> V_32 = V_32 ;
V_39 = F_5 ( V_12 -> V_2 , V_31 ,
V_12 -> V_32 ) ;
if ( V_39 )
return V_39 ;
}
return 0 ;
}
static int F_31 ( struct V_9 * V_10 , int * V_67 )
{
struct V_1 * V_2 = F_27 ( V_10 ) ;
int V_68 ;
V_68 = F_1 ( V_2 , V_69 ) ;
if ( V_68 < 0 )
return V_68 ;
* V_67 = V_68 >= 64 ? V_68 - 128 : V_68 ;
if ( * V_67 > 0 )
( * V_67 ) -- ;
* V_67 *= - V_70 ;
return 0 ;
}
static int F_32 ( struct V_9 * V_10 , int V_67 )
{
struct V_1 * V_2 = F_27 ( V_10 ) ;
T_2 V_68 ;
int V_39 ;
V_67 /= - V_70 ;
if ( V_67 > V_71 )
V_67 = V_71 ;
else if ( V_67 < V_72 )
V_67 = V_72 ;
else if ( V_67 > 0 )
V_67 ++ ;
else if ( V_67 < 0 )
V_67 += 128 ;
V_68 = V_67 ;
V_39 = F_5 ( V_2 , V_69 , V_68 ) ;
if ( V_39 )
return V_39 ;
F_19 ( V_10 , L_14 , V_41 , V_68 ) ;
return 0 ;
}
static T_5 F_33 ( struct V_9 * V_10 ,
struct V_73 * V_74 ,
char * V_75 )
{
int V_39 , V_67 ;
V_39 = F_31 ( V_10 , & V_67 ) ;
if ( V_39 )
return V_39 ;
return sprintf ( V_75 , L_15 , V_67 ) ;
}
static T_5 F_34 ( struct V_9 * V_10 ,
struct V_73 * V_74 ,
const char * V_75 , T_6 V_76 )
{
int V_67 , V_39 ;
if ( sscanf ( V_75 , L_16 , & V_67 ) != 1 )
return - V_17 ;
V_39 = F_32 ( V_10 , V_67 ) ;
return V_39 ? V_39 : V_76 ;
}
static int F_35 ( struct V_9 * V_10 )
{
return F_36 ( V_10 , & V_77 ) ;
}
static void F_37 ( struct V_9 * V_10 )
{
F_38 ( V_10 , & V_77 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
const struct V_78 * V_79 )
{
struct V_80 * V_81 = F_40 ( V_2 -> V_10 . V_82 ) ;
struct V_11 * V_12 ;
int V_39 = 0 ;
if ( ! F_41 ( V_81 , V_83
| V_84 ) ) {
F_42 ( & V_81 -> V_10 ,
L_17 ) ;
return - V_7 ;
}
V_12 = F_43 ( & V_2 -> V_10 , sizeof( * V_12 ) , V_85 ) ;
if ( ! V_12 )
return - V_86 ;
V_12 -> V_2 = V_2 ;
F_44 ( V_2 , V_12 ) ;
V_39 = F_24 ( V_2 ) ;
if ( V_39 )
return V_39 ;
V_12 -> V_23 = F_45 ( & V_2 -> V_10 , V_2 -> V_87 ,
& V_88 , V_89 ) ;
if ( F_46 ( V_12 -> V_23 ) ) {
F_42 ( & V_2 -> V_10 , L_18 ) ;
return F_47 ( V_12 -> V_23 ) ;
}
if ( V_2 -> V_19 > 0 ) {
F_48 ( & V_2 -> V_10 , L_19 , V_2 -> V_19 ) ;
V_39 = F_49 ( & V_2 -> V_10 , V_2 -> V_19 , NULL ,
F_13 ,
V_90 ,
L_20 , V_2 ) ;
if ( V_39 ) {
F_42 ( & V_2 -> V_10 , L_21 ) ;
V_2 -> V_19 = 0 ;
}
}
V_12 -> V_23 -> V_91 = 1 ;
V_12 -> V_23 -> V_92 = 1 ;
V_39 = F_35 ( & V_2 -> V_10 ) ;
return V_39 ;
}
static int F_50 ( struct V_1 * V_2 )
{
F_37 ( & V_2 -> V_10 ) ;
return 0 ;
}
