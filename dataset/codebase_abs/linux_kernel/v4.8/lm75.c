static inline long F_1 ( T_1 V_1 , T_2 V_2 )
{
return ( ( V_1 >> ( 16 - V_2 ) ) * 1000 ) >> ( V_2 - 8 ) ;
}
static int F_2 ( void * V_3 , int * V_1 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
unsigned int V_6 ;
int V_7 ;
V_7 = F_4 ( V_5 -> V_8 , V_9 , & V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_1 = F_1 ( V_6 , V_5 -> V_2 ) ;
return 0 ;
}
static T_3 F_5 ( struct V_10 * V_3 , struct V_11 * V_12 ,
char * V_13 )
{
struct V_14 * V_15 = F_6 ( V_12 ) ;
struct V_4 * V_5 = F_3 ( V_3 ) ;
unsigned int V_1 = 0 ;
int V_7 ;
V_7 = F_4 ( V_5 -> V_8 , V_15 -> V_16 , & V_1 ) ;
if ( V_7 < 0 )
return V_7 ;
return sprintf ( V_13 , L_1 , F_1 ( V_1 , V_5 -> V_2 ) ) ;
}
static T_3 F_7 ( struct V_10 * V_3 , struct V_11 * V_12 ,
const char * V_13 , T_4 V_17 )
{
struct V_14 * V_15 = F_6 ( V_12 ) ;
struct V_4 * V_5 = F_3 ( V_3 ) ;
long V_1 ;
int error ;
T_2 V_2 ;
error = F_8 ( V_13 , 10 , & V_1 ) ;
if ( error )
return error ;
if ( V_15 -> V_16 && V_5 -> V_18 )
V_2 = V_5 -> V_18 ;
else
V_2 = V_5 -> V_2 ;
V_1 = F_9 ( V_1 , V_19 , V_20 ) ;
V_1 = F_10 ( V_1 << ( V_2 - 8 ) ,
1000 ) << ( 16 - V_2 ) ;
error = F_11 ( V_5 -> V_8 , V_15 -> V_16 , V_1 ) ;
if ( error < 0 )
return error ;
return V_17 ;
}
static T_3 F_12 ( struct V_10 * V_3 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
return sprintf ( V_13 , L_2 , V_5 -> V_21 ) ;
}
static bool F_13 ( struct V_10 * V_3 , unsigned int V_22 )
{
return V_22 != V_9 ;
}
static bool F_14 ( struct V_10 * V_3 , unsigned int V_22 )
{
return V_22 == V_9 ;
}
static void F_15 ( void * V_5 )
{
struct V_4 * V_23 = V_5 ;
struct V_24 * V_25 = V_23 -> V_25 ;
F_16 ( V_25 , V_26 , V_23 -> V_27 ) ;
}
static int
F_17 ( struct V_24 * V_25 , const struct V_28 * V_29 )
{
struct V_10 * V_3 = & V_25 -> V_3 ;
struct V_10 * V_30 ;
struct V_4 * V_5 ;
int V_31 , V_7 ;
T_2 V_32 , V_33 ;
int V_34 ;
enum V_35 V_36 = V_29 -> V_37 ;
if ( ! F_18 ( V_25 -> V_38 ,
V_39 | V_40 ) )
return - V_41 ;
V_5 = F_19 ( V_3 , sizeof( struct V_4 ) , V_42 ) ;
if ( ! V_5 )
return - V_43 ;
V_5 -> V_25 = V_25 ;
V_5 -> V_8 = F_20 ( V_25 , & V_44 ) ;
if ( F_21 ( V_5 -> V_8 ) )
return F_22 ( V_5 -> V_8 ) ;
V_32 = 0 ;
V_33 = V_45 ;
switch ( V_36 ) {
case V_46 :
V_33 |= 1 << 5 ;
V_5 -> V_2 = 12 ;
V_5 -> V_21 = V_47 / 8 ;
break;
case V_48 :
case V_49 :
case V_50 :
V_33 |= 3 << 5 ;
V_32 |= 2 << 5 ;
V_5 -> V_2 = 11 ;
V_5 -> V_21 = V_47 ;
break;
case V_51 :
V_32 |= 3 << 5 ;
V_5 -> V_2 = 12 ;
V_5 -> V_21 = V_47 / 4 ;
break;
case V_52 :
case V_23 :
case V_53 :
V_5 -> V_2 = 9 ;
V_5 -> V_21 = V_47 / 2 ;
break;
case V_54 :
V_5 -> V_2 = 11 ;
V_5 -> V_21 = V_47 / 4 ;
break;
case V_55 :
V_5 -> V_2 = 9 ;
V_5 -> V_21 = V_47 / 4 ;
break;
case V_56 :
V_5 -> V_2 = 12 ;
V_5 -> V_18 = 9 ;
V_5 -> V_21 = V_47 / 4 ;
break;
case V_57 :
V_5 -> V_2 = 9 ;
V_5 -> V_21 = V_47 / 8 ;
break;
case V_58 :
V_5 -> V_18 = 9 ;
case V_59 :
case V_60 :
V_32 |= 3 << 5 ;
V_5 -> V_2 = 12 ;
V_5 -> V_21 = V_47 ;
V_33 |= 1 << 7 ;
break;
case V_61 :
V_32 |= 3 << 5 ;
V_33 |= 1 << 7 ;
V_5 -> V_2 = 12 ;
V_5 -> V_21 = V_47 / 4 ;
break;
case V_62 :
case V_63 :
case V_64 :
case V_65 :
V_32 |= 3 << 5 ;
V_33 |= 1 << 7 ;
V_5 -> V_2 = 12 ;
V_5 -> V_21 = V_47 / 2 ;
break;
case V_66 :
V_33 |= 1 << 5 ;
V_5 -> V_2 = 12 ;
V_5 -> V_21 = V_47 / 4 ;
break;
}
V_31 = F_23 ( V_25 , V_26 ) ;
if ( V_31 < 0 ) {
F_24 ( V_3 , L_3 , V_31 ) ;
return V_31 ;
}
V_5 -> V_27 = V_31 ;
V_34 = V_31 & ~ V_33 ;
V_34 |= V_32 ;
if ( V_31 != V_34 )
F_16 ( V_25 , V_26 , V_34 ) ;
V_7 = F_25 ( V_3 , F_15 , V_5 ) ;
if ( V_7 )
return V_7 ;
F_24 ( V_3 , L_4 , V_34 ) ;
V_30 = F_26 ( V_3 , V_25 -> V_67 ,
V_5 , V_68 ) ;
if ( F_21 ( V_30 ) )
return F_22 ( V_30 ) ;
F_27 ( V_30 , 0 ,
V_30 ,
& V_69 ) ;
F_28 ( V_3 , L_5 , F_29 ( V_30 ) , V_25 -> V_67 ) ;
return 0 ;
}
static int F_30 ( struct V_24 * V_70 ,
struct V_71 * V_72 )
{
struct V_73 * V_38 = V_70 -> V_38 ;
int V_74 ;
int V_75 , V_76 , V_77 ;
bool V_78 = 0 ;
if ( ! F_18 ( V_38 , V_39 |
V_40 ) )
return - V_79 ;
V_75 = F_23 ( V_70 , 1 ) ;
if ( V_75 & 0xe0 )
return - V_79 ;
if ( F_23 ( V_70 , 7 ) == V_80 ) {
if ( F_23 ( V_70 , 4 ) != 0xff
|| F_23 ( V_70 , 5 ) != 0xff
|| F_23 ( V_70 , 6 ) != 0xff )
return - V_79 ;
V_78 = 1 ;
V_76 = F_23 ( V_70 , 2 ) ;
V_77 = F_23 ( V_70 , 3 ) ;
} else {
V_76 = F_23 ( V_70 , 2 ) ;
if ( F_23 ( V_70 , 4 ) != V_76
|| F_23 ( V_70 , 5 ) != V_76
|| F_23 ( V_70 , 6 ) != V_76
|| F_23 ( V_70 , 7 ) != V_76 )
return - V_79 ;
V_77 = F_23 ( V_70 , 3 ) ;
if ( F_23 ( V_70 , 4 ) != V_77
|| F_23 ( V_70 , 5 ) != V_77
|| F_23 ( V_70 , 6 ) != V_77
|| F_23 ( V_70 , 7 ) != V_77 )
return - V_79 ;
}
if ( V_76 == 0 && V_77 == 0 )
return - V_79 ;
for ( V_74 = 8 ; V_74 <= 248 ; V_74 += 40 ) {
if ( F_23 ( V_70 , V_74 + 1 ) != V_75
|| F_23 ( V_70 , V_74 + 2 ) != V_76
|| F_23 ( V_70 , V_74 + 3 ) != V_77 )
return - V_79 ;
if ( V_78 && F_23 ( V_70 , V_74 + 7 )
!= V_80 )
return - V_79 ;
}
F_31 ( V_72 -> type , V_78 ? L_6 : L_7 , V_81 ) ;
return 0 ;
}
static int F_32 ( struct V_10 * V_3 )
{
int V_31 ;
struct V_24 * V_25 = F_33 ( V_3 ) ;
V_31 = F_23 ( V_25 , V_26 ) ;
if ( V_31 < 0 ) {
F_24 ( & V_25 -> V_3 , L_3 , V_31 ) ;
return V_31 ;
}
V_31 = V_31 | V_45 ;
F_16 ( V_25 , V_26 , V_31 ) ;
return 0 ;
}
static int F_34 ( struct V_10 * V_3 )
{
int V_31 ;
struct V_24 * V_25 = F_33 ( V_3 ) ;
V_31 = F_23 ( V_25 , V_26 ) ;
if ( V_31 < 0 ) {
F_24 ( & V_25 -> V_3 , L_3 , V_31 ) ;
return V_31 ;
}
V_31 = V_31 & ~ V_45 ;
F_16 ( V_25 , V_26 , V_31 ) ;
return 0 ;
}
