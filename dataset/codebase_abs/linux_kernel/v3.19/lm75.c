static inline long F_1 ( T_1 V_1 , T_2 V_2 )
{
return ( ( V_1 >> ( 16 - V_2 ) ) * 1000 ) >> ( V_2 - 8 ) ;
}
static int F_2 ( void * V_3 , long * V_1 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
if ( F_4 ( V_5 ) )
return F_5 ( V_5 ) ;
* V_1 = F_1 ( V_5 -> V_1 [ 0 ] , V_5 -> V_2 ) ;
return 0 ;
}
static T_3 F_6 ( struct V_6 * V_3 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_10 * V_11 = F_7 ( V_8 ) ;
struct V_4 * V_5 = F_3 ( V_3 ) ;
if ( F_4 ( V_5 ) )
return F_5 ( V_5 ) ;
return sprintf ( V_9 , L_1 , F_1 ( V_5 -> V_1 [ V_11 -> V_12 ] ,
V_5 -> V_2 ) ) ;
}
static T_3 F_8 ( struct V_6 * V_3 , struct V_7 * V_8 ,
const char * V_9 , T_4 V_13 )
{
struct V_10 * V_11 = F_7 ( V_8 ) ;
struct V_4 * V_5 = F_9 ( V_3 ) ;
struct V_14 * V_15 = V_5 -> V_15 ;
int V_16 = V_11 -> V_12 ;
long V_1 ;
int error ;
T_2 V_2 ;
error = F_10 ( V_9 , 10 , & V_1 ) ;
if ( error )
return error ;
if ( V_11 -> V_12 && V_5 -> V_17 )
V_2 = V_5 -> V_17 ;
else
V_2 = V_5 -> V_2 ;
F_11 ( & V_5 -> V_18 ) ;
V_1 = F_12 ( V_1 , V_19 , V_20 ) ;
V_5 -> V_1 [ V_16 ] = F_13 ( V_1 << ( V_2 - 8 ) ,
1000 ) << ( 16 - V_2 ) ;
F_14 ( V_15 , V_21 [ V_16 ] , V_5 -> V_1 [ V_16 ] ) ;
F_15 ( & V_5 -> V_18 ) ;
return V_13 ;
}
static int
F_16 ( struct V_14 * V_15 , const struct V_22 * V_23 )
{
struct V_6 * V_3 = & V_15 -> V_3 ;
struct V_4 * V_5 ;
int V_24 ;
T_2 V_25 , V_26 ;
int V_27 ;
enum V_28 V_29 = V_23 -> V_30 ;
if ( ! F_17 ( V_15 -> V_31 ,
V_32 | V_33 ) )
return - V_34 ;
V_5 = F_18 ( V_3 , sizeof( struct V_4 ) , V_35 ) ;
if ( ! V_5 )
return - V_36 ;
V_5 -> V_15 = V_15 ;
F_19 ( V_15 , V_5 ) ;
F_20 ( & V_5 -> V_18 ) ;
V_25 = 0 ;
V_26 = V_37 ;
switch ( V_29 ) {
case V_38 :
V_26 |= 1 << 5 ;
V_5 -> V_2 = 12 ;
V_5 -> V_39 = V_40 / 8 ;
break;
case V_41 :
case V_42 :
case V_43 :
V_26 |= 3 << 5 ;
V_25 |= 2 << 5 ;
V_5 -> V_2 = 11 ;
V_5 -> V_39 = V_40 ;
break;
case V_44 :
V_25 |= 3 << 5 ;
V_5 -> V_2 = 12 ;
V_5 -> V_39 = V_40 / 4 ;
break;
case V_45 :
case V_46 :
case V_47 :
V_5 -> V_2 = 9 ;
V_5 -> V_39 = V_40 / 2 ;
break;
case V_48 :
V_5 -> V_2 = 11 ;
V_5 -> V_39 = V_40 / 4 ;
break;
case V_49 :
V_5 -> V_2 = 9 ;
V_5 -> V_39 = V_40 / 4 ;
break;
case V_50 :
V_5 -> V_2 = 12 ;
V_5 -> V_17 = 9 ;
V_5 -> V_39 = V_40 / 4 ;
break;
case V_51 :
V_5 -> V_2 = 9 ;
V_5 -> V_39 = V_40 / 8 ;
break;
case V_52 :
V_5 -> V_17 = 9 ;
case V_53 :
case V_54 :
V_25 |= 3 << 5 ;
V_5 -> V_2 = 12 ;
V_5 -> V_39 = V_40 ;
V_26 |= 1 << 7 ;
break;
case V_55 :
V_25 |= 3 << 5 ;
V_26 |= 1 << 7 ;
V_5 -> V_2 = 12 ;
V_5 -> V_39 = V_40 / 4 ;
break;
case V_56 :
case V_57 :
case V_58 :
case V_59 :
V_25 |= 3 << 5 ;
V_26 |= 1 << 7 ;
V_5 -> V_2 = 12 ;
V_5 -> V_39 = V_40 / 2 ;
break;
}
V_24 = F_21 ( V_15 , V_60 ) ;
if ( V_24 < 0 ) {
F_22 ( V_3 , L_2 , V_24 ) ;
return V_24 ;
}
V_5 -> V_61 = V_24 ;
V_27 = V_24 & ~ V_26 ;
V_27 |= V_25 ;
if ( V_24 != V_27 )
F_14 ( V_15 , V_60 , V_27 ) ;
F_22 ( V_3 , L_3 , V_27 ) ;
V_5 -> V_62 = F_23 ( V_3 , V_15 -> V_63 ,
V_5 , V_64 ) ;
if ( F_4 ( V_5 -> V_62 ) )
return F_5 ( V_5 -> V_62 ) ;
V_5 -> V_65 = F_24 ( V_5 -> V_62 , 0 ,
V_5 -> V_62 ,
& V_66 ) ;
if ( F_4 ( V_5 -> V_65 ) )
V_5 -> V_65 = NULL ;
F_25 ( V_3 , L_4 ,
F_26 ( V_5 -> V_62 ) , V_15 -> V_63 ) ;
return 0 ;
}
static int F_27 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = F_28 ( V_15 ) ;
F_29 ( V_5 -> V_62 , V_5 -> V_65 ) ;
F_30 ( V_5 -> V_62 ) ;
F_14 ( V_15 , V_60 , V_5 -> V_61 ) ;
return 0 ;
}
static int F_31 ( struct V_14 * V_67 ,
struct V_68 * V_69 )
{
struct V_70 * V_31 = V_67 -> V_31 ;
int V_71 ;
int V_72 , V_73 , V_74 ;
bool V_75 = 0 ;
if ( ! F_17 ( V_31 , V_32 |
V_33 ) )
return - V_76 ;
V_72 = F_32 ( V_67 , 1 ) ;
if ( V_72 & 0xe0 )
return - V_76 ;
if ( F_32 ( V_67 , 7 ) == V_77 ) {
if ( F_32 ( V_67 , 4 ) != 0xff
|| F_32 ( V_67 , 5 ) != 0xff
|| F_32 ( V_67 , 6 ) != 0xff )
return - V_76 ;
V_75 = 1 ;
V_73 = F_32 ( V_67 , 2 ) ;
V_74 = F_32 ( V_67 , 3 ) ;
} else {
V_73 = F_32 ( V_67 , 2 ) ;
if ( F_32 ( V_67 , 4 ) != V_73
|| F_32 ( V_67 , 5 ) != V_73
|| F_32 ( V_67 , 6 ) != V_73
|| F_32 ( V_67 , 7 ) != V_73 )
return - V_76 ;
V_74 = F_32 ( V_67 , 3 ) ;
if ( F_32 ( V_67 , 4 ) != V_74
|| F_32 ( V_67 , 5 ) != V_74
|| F_32 ( V_67 , 6 ) != V_74
|| F_32 ( V_67 , 7 ) != V_74 )
return - V_76 ;
}
if ( V_73 == 0 && V_74 == 0 )
return - V_76 ;
for ( V_71 = 8 ; V_71 <= 248 ; V_71 += 40 ) {
if ( F_32 ( V_67 , V_71 + 1 ) != V_72
|| F_32 ( V_67 , V_71 + 2 ) != V_73
|| F_32 ( V_67 , V_71 + 3 ) != V_74 )
return - V_76 ;
if ( V_75 && F_32 ( V_67 , V_71 + 7 )
!= V_77 )
return - V_76 ;
}
F_33 ( V_69 -> type , V_75 ? L_5 : L_6 , V_78 ) ;
return 0 ;
}
static int F_34 ( struct V_6 * V_3 )
{
int V_24 ;
struct V_14 * V_15 = F_35 ( V_3 ) ;
V_24 = F_21 ( V_15 , V_60 ) ;
if ( V_24 < 0 ) {
F_22 ( & V_15 -> V_3 , L_2 , V_24 ) ;
return V_24 ;
}
V_24 = V_24 | V_37 ;
F_14 ( V_15 , V_60 , V_24 ) ;
return 0 ;
}
static int F_36 ( struct V_6 * V_3 )
{
int V_24 ;
struct V_14 * V_15 = F_35 ( V_3 ) ;
V_24 = F_21 ( V_15 , V_60 ) ;
if ( V_24 < 0 ) {
F_22 ( & V_15 -> V_3 , L_2 , V_24 ) ;
return V_24 ;
}
V_24 = V_24 & ~ V_37 ;
F_14 ( V_15 , V_60 , V_24 ) ;
return 0 ;
}
static int F_21 ( struct V_14 * V_15 , T_2 V_79 )
{
if ( V_79 == V_60 )
return F_32 ( V_15 , V_79 ) ;
else
return F_37 ( V_15 , V_79 ) ;
}
static int F_14 ( struct V_14 * V_15 , T_2 V_79 , T_5 V_80 )
{
if ( V_79 == V_60 )
return F_38 ( V_15 , V_79 , V_80 ) ;
else
return F_39 ( V_15 , V_79 , V_80 ) ;
}
static struct V_4 * F_3 ( struct V_6 * V_3 )
{
struct V_4 * V_5 = F_9 ( V_3 ) ;
struct V_14 * V_15 = V_5 -> V_15 ;
struct V_4 * V_81 = V_5 ;
F_11 ( & V_5 -> V_18 ) ;
if ( F_40 ( V_82 , V_5 -> V_83 + V_5 -> V_39 )
|| ! V_5 -> V_84 ) {
int V_71 ;
F_22 ( & V_15 -> V_3 , L_7 ) ;
for ( V_71 = 0 ; V_71 < F_41 ( V_5 -> V_1 ) ; V_71 ++ ) {
int V_24 ;
V_24 = F_21 ( V_15 , V_21 [ V_71 ] ) ;
if ( F_42 ( V_24 < 0 ) ) {
F_22 ( V_3 ,
L_8 ,
V_21 [ V_71 ] , V_24 ) ;
V_81 = F_43 ( V_24 ) ;
V_5 -> V_84 = 0 ;
goto abort;
}
V_5 -> V_1 [ V_71 ] = V_24 ;
}
V_5 -> V_83 = V_82 ;
V_5 -> V_84 = 1 ;
}
abort:
F_15 ( & V_5 -> V_18 ) ;
return V_81 ;
}
