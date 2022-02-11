static inline long F_1 ( T_1 V_1 , T_2 V_2 )
{
return ( ( V_1 >> ( 16 - V_2 ) ) * 1000 ) >> ( V_2 - 8 ) ;
}
static int F_2 ( struct V_3 * V_4 , enum V_5 type ,
T_3 V_6 , int V_7 , long * V_8 )
{
struct V_9 * V_10 = F_3 ( V_4 ) ;
unsigned int V_11 ;
int V_12 , V_13 ;
switch ( type ) {
case V_14 :
switch ( V_6 ) {
case V_15 :
* V_8 = V_10 -> V_16 ;
break; ;
default:
return - V_17 ;
}
break;
case V_18 :
switch ( V_6 ) {
case V_19 :
V_13 = V_20 ;
break;
case V_21 :
V_13 = V_22 ;
break;
case V_23 :
V_13 = V_24 ;
break;
default:
return - V_17 ;
}
V_12 = F_4 ( V_10 -> V_25 , V_13 , & V_11 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_8 = F_1 ( V_11 , V_10 -> V_2 ) ;
break;
default:
return - V_17 ;
}
return 0 ;
}
static int F_5 ( struct V_3 * V_4 , enum V_5 type ,
T_3 V_6 , int V_7 , long V_1 )
{
struct V_9 * V_10 = F_3 ( V_4 ) ;
T_2 V_2 ;
int V_13 ;
if ( type != V_18 )
return - V_17 ;
switch ( V_6 ) {
case V_21 :
V_13 = V_22 ;
break;
case V_23 :
V_13 = V_24 ;
break;
default:
return - V_17 ;
}
if ( V_10 -> V_26 )
V_2 = V_10 -> V_26 ;
else
V_2 = V_10 -> V_2 ;
V_1 = F_6 ( V_1 , V_27 , V_28 ) ;
V_1 = F_7 ( V_1 << ( V_2 - 8 ) ,
1000 ) << ( 16 - V_2 ) ;
return F_8 ( V_10 -> V_25 , V_13 , V_1 ) ;
}
static T_4 F_9 ( const void * V_10 , enum V_5 type ,
T_3 V_6 , int V_7 )
{
switch ( type ) {
case V_14 :
switch ( V_6 ) {
case V_15 :
return V_29 ;
}
break;
case V_18 :
switch ( V_6 ) {
case V_19 :
return V_29 ;
case V_21 :
case V_23 :
return V_29 | V_30 ;
}
break;
default:
break;
}
return 0 ;
}
static bool F_10 ( struct V_3 * V_4 , unsigned int V_13 )
{
return V_13 != V_20 ;
}
static bool F_11 ( struct V_3 * V_4 , unsigned int V_13 )
{
return V_13 == V_20 ;
}
static void F_12 ( void * V_10 )
{
struct V_9 * V_31 = V_10 ;
struct V_32 * V_33 = V_31 -> V_33 ;
F_13 ( V_33 , V_34 , V_31 -> V_35 ) ;
}
static int
F_14 ( struct V_32 * V_33 , const struct V_36 * V_37 )
{
struct V_3 * V_4 = & V_33 -> V_4 ;
struct V_3 * V_38 ;
struct V_9 * V_10 ;
int V_39 , V_12 ;
T_2 V_40 , V_41 ;
int V_42 ;
enum V_43 V_44 ;
if ( V_33 -> V_4 . V_45 )
V_44 = (enum V_43 ) F_15 ( & V_33 -> V_4 ) ;
else
V_44 = V_37 -> V_46 ;
if ( ! F_16 ( V_33 -> V_47 ,
V_48 | V_49 ) )
return - V_50 ;
V_10 = F_17 ( V_4 , sizeof( struct V_9 ) , V_51 ) ;
if ( ! V_10 )
return - V_52 ;
V_10 -> V_33 = V_33 ;
V_10 -> V_25 = F_18 ( V_33 , & V_53 ) ;
if ( F_19 ( V_10 -> V_25 ) )
return F_20 ( V_10 -> V_25 ) ;
V_40 = 0 ;
V_41 = V_54 ;
switch ( V_44 ) {
case V_55 :
V_41 |= 1 << 5 ;
V_10 -> V_2 = 12 ;
V_10 -> V_16 = V_56 / 8 ;
break;
case V_57 :
case V_58 :
case V_59 :
V_41 |= 3 << 5 ;
V_40 |= 2 << 5 ;
V_10 -> V_2 = 11 ;
V_10 -> V_16 = V_56 ;
break;
case V_60 :
V_40 |= 3 << 5 ;
V_10 -> V_2 = 12 ;
V_10 -> V_16 = V_56 / 4 ;
break;
case V_61 :
case V_31 :
case V_62 :
V_10 -> V_2 = 9 ;
V_10 -> V_16 = V_56 / 2 ;
break;
case V_63 :
V_10 -> V_2 = 11 ;
V_10 -> V_16 = V_56 / 4 ;
break;
case V_64 :
V_10 -> V_2 = 9 ;
V_10 -> V_16 = V_56 / 4 ;
break;
case V_65 :
V_10 -> V_2 = 12 ;
V_10 -> V_26 = 9 ;
V_10 -> V_16 = V_56 / 4 ;
break;
case V_66 :
V_10 -> V_2 = 9 ;
V_10 -> V_16 = V_56 / 8 ;
break;
case V_67 :
V_10 -> V_26 = 9 ;
case V_68 :
case V_69 :
V_40 |= 3 << 5 ;
V_10 -> V_2 = 12 ;
V_10 -> V_16 = V_56 ;
V_41 |= 1 << 7 ;
break;
case V_70 :
V_40 |= 3 << 5 ;
V_41 |= 1 << 7 ;
V_10 -> V_2 = 12 ;
V_10 -> V_16 = V_56 / 4 ;
break;
case V_71 :
case V_72 :
case V_73 :
case V_74 :
V_40 |= 3 << 5 ;
V_41 |= 1 << 7 ;
V_10 -> V_2 = 12 ;
V_10 -> V_16 = V_56 / 2 ;
break;
case V_75 :
V_41 |= 1 << 5 ;
V_10 -> V_2 = 12 ;
V_10 -> V_16 = V_56 / 4 ;
break;
}
V_39 = F_21 ( V_33 , V_34 ) ;
if ( V_39 < 0 ) {
F_22 ( V_4 , L_1 , V_39 ) ;
return V_39 ;
}
V_10 -> V_35 = V_39 ;
V_42 = V_39 & ~ V_41 ;
V_42 |= V_40 ;
if ( V_39 != V_42 )
F_13 ( V_33 , V_34 , V_42 ) ;
V_12 = F_23 ( V_4 , F_12 , V_10 ) ;
if ( V_12 )
return V_12 ;
F_22 ( V_4 , L_2 , V_42 ) ;
V_38 = F_24 ( V_4 , V_33 -> V_76 ,
V_10 , & V_77 ,
NULL ) ;
if ( F_19 ( V_38 ) )
return F_20 ( V_38 ) ;
F_25 ( V_4 , L_3 , F_26 ( V_38 ) , V_33 -> V_76 ) ;
return 0 ;
}
static int F_27 ( struct V_32 * V_78 ,
struct V_79 * V_80 )
{
struct V_81 * V_47 = V_78 -> V_47 ;
int V_82 ;
int V_83 , V_84 , V_85 ;
bool V_86 = 0 ;
if ( ! F_16 ( V_47 , V_48 |
V_49 ) )
return - V_87 ;
V_83 = F_21 ( V_78 , 1 ) ;
if ( V_83 & 0xe0 )
return - V_87 ;
if ( F_21 ( V_78 , 7 ) == V_88 ) {
if ( F_21 ( V_78 , 4 ) != 0xff
|| F_21 ( V_78 , 5 ) != 0xff
|| F_21 ( V_78 , 6 ) != 0xff )
return - V_87 ;
V_86 = 1 ;
V_84 = F_21 ( V_78 , 2 ) ;
V_85 = F_21 ( V_78 , 3 ) ;
} else {
V_84 = F_21 ( V_78 , 2 ) ;
if ( F_21 ( V_78 , 4 ) != V_84
|| F_21 ( V_78 , 5 ) != V_84
|| F_21 ( V_78 , 6 ) != V_84
|| F_21 ( V_78 , 7 ) != V_84 )
return - V_87 ;
V_85 = F_21 ( V_78 , 3 ) ;
if ( F_21 ( V_78 , 4 ) != V_85
|| F_21 ( V_78 , 5 ) != V_85
|| F_21 ( V_78 , 6 ) != V_85
|| F_21 ( V_78 , 7 ) != V_85 )
return - V_87 ;
}
if ( V_84 == 0 && V_85 == 0 )
return - V_87 ;
for ( V_82 = 8 ; V_82 <= 248 ; V_82 += 40 ) {
if ( F_21 ( V_78 , V_82 + 1 ) != V_83
|| F_21 ( V_78 , V_82 + 2 ) != V_84
|| F_21 ( V_78 , V_82 + 3 ) != V_85 )
return - V_87 ;
if ( V_86 && F_21 ( V_78 , V_82 + 7 )
!= V_88 )
return - V_87 ;
}
F_28 ( V_80 -> type , V_86 ? L_4 : L_5 , V_89 ) ;
return 0 ;
}
static int F_29 ( struct V_3 * V_4 )
{
int V_39 ;
struct V_32 * V_33 = F_30 ( V_4 ) ;
V_39 = F_21 ( V_33 , V_34 ) ;
if ( V_39 < 0 ) {
F_22 ( & V_33 -> V_4 , L_1 , V_39 ) ;
return V_39 ;
}
V_39 = V_39 | V_54 ;
F_13 ( V_33 , V_34 , V_39 ) ;
return 0 ;
}
static int F_31 ( struct V_3 * V_4 )
{
int V_39 ;
struct V_32 * V_33 = F_30 ( V_4 ) ;
V_39 = F_21 ( V_33 , V_34 ) ;
if ( V_39 < 0 ) {
F_22 ( & V_33 -> V_4 , L_1 , V_39 ) ;
return V_39 ;
}
V_39 = V_39 & ~ V_54 ;
F_13 ( V_33 , V_34 , V_39 ) ;
return 0 ;
}
