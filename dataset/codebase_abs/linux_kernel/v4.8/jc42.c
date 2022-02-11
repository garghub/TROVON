static T_1 F_1 ( long V_1 , bool V_2 )
{
int V_3 = F_2 ( V_1 ,
V_2 ? V_4 :
V_5 , V_6 ) ;
return ( V_3 * 2 / 125 ) & 0x1fff ;
}
static int F_3 ( T_2 V_7 )
{
V_7 = F_4 ( V_7 , 12 ) ;
return V_7 * 125 / 2 ;
}
static struct V_8 * F_5 ( struct V_9 * V_10 )
{
struct V_8 * V_11 = F_6 ( V_10 ) ;
struct V_12 * V_13 = V_11 -> V_13 ;
struct V_8 * V_14 = V_11 ;
int V_15 , V_16 ;
F_7 ( & V_11 -> V_17 ) ;
if ( F_8 ( V_18 , V_11 -> V_19 + V_20 ) || ! V_11 -> V_21 ) {
for ( V_15 = 0 ; V_15 < V_22 ; V_15 ++ ) {
V_16 = F_9 ( V_13 , V_23 [ V_15 ] ) ;
if ( V_16 < 0 ) {
V_14 = F_10 ( V_16 ) ;
goto abort;
}
V_11 -> V_1 [ V_15 ] = V_16 ;
}
V_11 -> V_19 = V_18 ;
V_11 -> V_21 = true ;
}
abort:
F_11 ( & V_11 -> V_17 ) ;
return V_14 ;
}
static T_3 F_12 ( struct V_9 * V_10 , struct V_24 * V_25 ,
char * V_26 )
{
struct V_27 * V_28 = F_13 ( V_25 ) ;
struct V_8 * V_11 = F_5 ( V_10 ) ;
if ( F_14 ( V_11 ) )
return F_15 ( V_11 ) ;
return sprintf ( V_26 , L_1 ,
F_3 ( V_11 -> V_1 [ V_28 -> V_29 ] ) ) ;
}
static T_3 F_16 ( struct V_9 * V_10 ,
struct V_24 * V_25 , char * V_26 )
{
struct V_27 * V_28 = F_13 ( V_25 ) ;
struct V_8 * V_11 = F_5 ( V_10 ) ;
int V_1 , V_30 ;
if ( F_14 ( V_11 ) )
return F_15 ( V_11 ) ;
V_1 = F_3 ( V_11 -> V_1 [ V_28 -> V_29 ] ) ;
V_30 = V_31 [ ( V_11 -> V_32 & V_33 )
>> V_34 ] ;
return sprintf ( V_26 , L_1 , V_1 - V_30 ) ;
}
static T_3 F_17 ( struct V_9 * V_10 , struct V_24 * V_25 ,
const char * V_26 , T_4 V_35 )
{
struct V_27 * V_28 = F_13 ( V_25 ) ;
struct V_8 * V_11 = F_6 ( V_10 ) ;
int V_36 , V_14 = V_35 ;
int V_37 = V_28 -> V_29 ;
long V_16 ;
if ( F_18 ( V_26 , 10 , & V_16 ) < 0 )
return - V_38 ;
F_7 ( & V_11 -> V_17 ) ;
V_11 -> V_1 [ V_37 ] = F_1 ( V_16 , V_11 -> V_2 ) ;
V_36 = F_19 ( V_11 -> V_13 , V_23 [ V_37 ] ,
V_11 -> V_1 [ V_37 ] ) ;
if ( V_36 < 0 )
V_14 = V_36 ;
F_11 ( & V_11 -> V_17 ) ;
return V_14 ;
}
static T_3 F_20 ( struct V_9 * V_10 ,
struct V_24 * V_28 ,
const char * V_26 , T_4 V_35 )
{
struct V_8 * V_11 = F_6 ( V_10 ) ;
long V_16 ;
int V_39 , V_30 ;
int V_36 ;
int V_14 = V_35 ;
if ( F_18 ( V_26 , 10 , & V_16 ) < 0 )
return - V_38 ;
V_16 = F_2 ( V_16 , ( V_11 -> V_2 ? V_4 :
V_5 ) - 6000 , V_6 ) ;
V_39 = F_3 ( V_11 -> V_1 [ V_40 ] ) - V_16 ;
V_30 = 0 ;
if ( V_39 > 0 ) {
if ( V_39 < 2250 )
V_30 = 1 ;
else if ( V_39 < 4500 )
V_30 = 2 ;
else
V_30 = 3 ;
}
F_7 ( & V_11 -> V_17 ) ;
V_11 -> V_32 = ( V_11 -> V_32 & ~ V_33 )
| ( V_30 << V_34 ) ;
V_36 = F_19 ( V_11 -> V_13 , V_41 ,
V_11 -> V_32 ) ;
if ( V_36 < 0 )
V_14 = V_36 ;
F_11 ( & V_11 -> V_17 ) ;
return V_14 ;
}
static T_3 F_21 ( struct V_9 * V_10 ,
struct V_24 * V_28 , char * V_26 )
{
T_1 V_42 = F_13 ( V_28 ) -> V_29 ;
struct V_8 * V_11 = F_5 ( V_10 ) ;
T_1 V_16 ;
if ( F_14 ( V_11 ) )
return F_15 ( V_11 ) ;
V_16 = V_11 -> V_1 [ V_43 ] ;
if ( V_42 != V_44 && ( V_11 -> V_32 & V_45 ) )
V_16 = 0 ;
return sprintf ( V_26 , L_2 , ( V_16 >> V_42 ) & 1 ) ;
}
static T_5 F_22 ( struct V_46 * V_47 ,
struct V_48 * V_28 , int V_29 )
{
struct V_9 * V_10 = F_23 ( V_47 , struct V_9 , V_47 ) ;
struct V_8 * V_11 = F_6 ( V_10 ) ;
unsigned int V_32 = V_11 -> V_32 ;
bool V_49 ;
if ( V_28 == & V_50 . V_51 . V_28 )
V_49 = V_32 & V_52 ;
else if ( V_28 == & V_53 . V_51 . V_28 ||
V_28 == & V_54 . V_51 . V_28 )
V_49 = V_32 & V_55 ;
else if ( V_28 == & V_56 . V_51 . V_28 )
V_49 = V_32 & ( V_55 | V_52 ) ;
else
V_49 = true ;
return V_57 | ( V_49 ? 0 : V_58 ) ;
}
static int F_24 ( struct V_12 * V_13 , struct V_59 * V_60 )
{
struct V_61 * V_62 = V_13 -> V_62 ;
int V_15 , V_32 , V_63 , V_64 , V_65 ;
if ( ! F_25 ( V_62 , V_66 |
V_67 ) )
return - V_68 ;
V_63 = F_9 ( V_13 , V_69 ) ;
V_32 = F_9 ( V_13 , V_41 ) ;
V_64 = F_9 ( V_13 , V_70 ) ;
V_65 = F_9 ( V_13 , V_71 ) ;
if ( V_63 < 0 || V_32 < 0 || V_64 < 0 || V_65 < 0 )
return - V_68 ;
if ( ( V_63 & 0xff00 ) || ( V_32 & 0xf800 ) )
return - V_68 ;
for ( V_15 = 0 ; V_15 < F_26 ( V_72 ) ; V_15 ++ ) {
struct V_72 * V_73 = & V_72 [ V_15 ] ;
if ( V_64 == V_73 -> V_64 &&
( V_65 & V_73 -> V_74 ) == V_73 -> V_65 ) {
F_27 ( V_60 -> type , L_3 , V_75 ) ;
return 0 ;
}
}
return - V_68 ;
}
static int F_28 ( struct V_12 * V_13 , const struct V_76 * V_77 )
{
struct V_9 * V_10 = & V_13 -> V_10 ;
struct V_9 * V_78 ;
struct V_8 * V_11 ;
int V_32 , V_63 ;
V_11 = F_29 ( V_10 , sizeof( struct V_8 ) , V_79 ) ;
if ( ! V_11 )
return - V_80 ;
V_11 -> V_13 = V_13 ;
F_30 ( V_13 , V_11 ) ;
F_31 ( & V_11 -> V_17 ) ;
V_63 = F_9 ( V_13 , V_69 ) ;
if ( V_63 < 0 )
return V_63 ;
V_11 -> V_2 = ! ! ( V_63 & V_81 ) ;
V_32 = F_9 ( V_13 , V_41 ) ;
if ( V_32 < 0 )
return V_32 ;
V_11 -> V_82 = V_32 ;
if ( V_32 & V_83 ) {
V_32 &= ~ V_83 ;
F_19 ( V_13 , V_41 , V_32 ) ;
}
V_11 -> V_32 = V_32 ;
V_78 = F_32 ( V_10 , V_13 -> V_84 ,
V_11 ,
V_85 ) ;
return F_33 ( V_78 ) ;
}
static int F_34 ( struct V_12 * V_13 )
{
struct V_8 * V_11 = F_35 ( V_13 ) ;
if ( ( V_11 -> V_32 & ~ V_33 ) !=
( V_11 -> V_82 & ~ V_33 ) ) {
int V_32 ;
V_32 = ( V_11 -> V_82 & ~ V_33 )
| ( V_11 -> V_32 & V_33 ) ;
F_19 ( V_13 , V_41 , V_32 ) ;
}
return 0 ;
}
static int F_36 ( struct V_9 * V_10 )
{
struct V_8 * V_11 = F_6 ( V_10 ) ;
V_11 -> V_32 |= V_83 ;
F_19 ( V_11 -> V_13 , V_41 ,
V_11 -> V_32 ) ;
return 0 ;
}
static int F_37 ( struct V_9 * V_10 )
{
struct V_8 * V_11 = F_6 ( V_10 ) ;
V_11 -> V_32 &= ~ V_83 ;
F_19 ( V_11 -> V_13 , V_41 ,
V_11 -> V_32 ) ;
return 0 ;
}
