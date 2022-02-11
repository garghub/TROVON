static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
long V_10 ;
if ( F_4 ( V_9 ) )
return F_5 ( V_9 ) ;
V_10 = ( ( V_9 -> V_10 [ V_7 -> V_11 ] >> ( 16 - V_9 -> V_12 ) ) * 1000 )
>> ( V_9 -> V_12 - 8 ) ;
return sprintf ( V_5 , L_1 , V_10 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_13 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_14 * V_15 = F_7 ( V_2 ) ;
struct V_8 * V_9 = F_8 ( V_15 ) ;
int V_16 = V_7 -> V_11 ;
long V_10 ;
int error ;
T_3 V_12 ;
error = F_9 ( V_5 , 10 , & V_10 ) ;
if ( error )
return error ;
if ( V_7 -> V_11 && V_9 -> V_17 )
V_12 = V_9 -> V_17 ;
else
V_12 = V_9 -> V_12 ;
F_10 ( & V_9 -> V_18 ) ;
V_10 = F_11 ( V_10 , V_19 , V_20 ) ;
V_9 -> V_10 [ V_16 ] = F_12 ( V_10 << ( V_12 - 8 ) ,
1000 ) << ( 16 - V_12 ) ;
F_13 ( V_15 , V_21 [ V_16 ] , V_9 -> V_10 [ V_16 ] ) ;
F_14 ( & V_9 -> V_18 ) ;
return V_13 ;
}
static int
F_15 ( struct V_14 * V_15 , const struct V_22 * V_23 )
{
struct V_8 * V_9 ;
int V_24 ;
T_3 V_25 , V_26 ;
int V_27 ;
enum V_28 V_29 = V_23 -> V_30 ;
if ( ! F_16 ( V_15 -> V_31 ,
V_32 | V_33 ) )
return - V_34 ;
V_9 = F_17 ( & V_15 -> V_2 , sizeof( struct V_8 ) , V_35 ) ;
if ( ! V_9 )
return - V_36 ;
F_18 ( V_15 , V_9 ) ;
F_19 ( & V_9 -> V_18 ) ;
V_25 = 0 ;
V_26 = V_37 ;
switch ( V_29 ) {
case V_38 :
V_26 |= 1 << 5 ;
V_9 -> V_12 = 12 ;
V_9 -> V_39 = V_40 / 8 ;
break;
case V_41 :
case V_42 :
case V_43 :
V_26 |= 3 << 5 ;
V_25 |= 2 << 5 ;
V_9 -> V_12 = 11 ;
V_9 -> V_39 = V_40 ;
break;
case V_44 :
V_25 |= 3 << 5 ;
V_9 -> V_12 = 12 ;
V_9 -> V_39 = V_40 / 4 ;
break;
case V_45 :
case V_46 :
V_9 -> V_12 = 9 ;
V_9 -> V_39 = V_40 / 2 ;
break;
case V_47 :
V_9 -> V_12 = 9 ;
V_9 -> V_39 = V_40 / 4 ;
break;
case V_48 :
V_9 -> V_12 = 12 ;
V_9 -> V_17 = 9 ;
V_9 -> V_39 = V_40 / 4 ;
break;
case V_49 :
V_9 -> V_12 = 9 ;
V_9 -> V_39 = V_40 / 8 ;
break;
case V_50 :
V_9 -> V_17 = 9 ;
case V_51 :
case V_52 :
V_25 |= 3 << 5 ;
V_9 -> V_12 = 12 ;
V_9 -> V_39 = V_40 ;
V_26 |= 1 << 7 ;
break;
case V_53 :
case V_54 :
case V_55 :
case V_56 :
V_25 |= 3 << 5 ;
V_26 |= 1 << 7 ;
V_9 -> V_12 = 12 ;
V_9 -> V_39 = V_40 / 2 ;
break;
}
V_24 = F_20 ( V_15 , V_57 ) ;
if ( V_24 < 0 ) {
F_21 ( & V_15 -> V_2 , L_2 , V_24 ) ;
return V_24 ;
}
V_9 -> V_58 = V_24 ;
V_27 = V_24 & ~ V_26 ;
V_27 |= V_25 ;
if ( V_24 != V_27 )
F_13 ( V_15 , V_57 , V_27 ) ;
F_21 ( & V_15 -> V_2 , L_3 , V_27 ) ;
V_24 = F_22 ( & V_15 -> V_2 . V_59 , & V_60 ) ;
if ( V_24 )
return V_24 ;
V_9 -> V_61 = F_23 ( & V_15 -> V_2 ) ;
if ( F_4 ( V_9 -> V_61 ) ) {
V_24 = F_5 ( V_9 -> V_61 ) ;
goto V_62;
}
F_24 ( & V_15 -> V_2 , L_4 ,
F_25 ( V_9 -> V_61 ) , V_15 -> V_63 ) ;
return 0 ;
V_62:
F_26 ( & V_15 -> V_2 . V_59 , & V_60 ) ;
return V_24 ;
}
static int F_27 ( struct V_14 * V_15 )
{
struct V_8 * V_9 = F_8 ( V_15 ) ;
F_28 ( V_9 -> V_61 ) ;
F_26 ( & V_15 -> V_2 . V_59 , & V_60 ) ;
F_13 ( V_15 , V_57 , V_9 -> V_58 ) ;
return 0 ;
}
static int F_29 ( struct V_14 * V_64 ,
struct V_65 * V_66 )
{
struct V_67 * V_31 = V_64 -> V_31 ;
int V_68 ;
int V_69 , V_70 , V_71 ;
bool V_72 = 0 ;
if ( ! F_16 ( V_31 , V_32 |
V_33 ) )
return - V_73 ;
V_69 = F_30 ( V_64 , 1 ) ;
if ( V_69 & 0xe0 )
return - V_73 ;
if ( F_30 ( V_64 , 7 ) == V_74 ) {
if ( F_30 ( V_64 , 4 ) != 0xff
|| F_30 ( V_64 , 5 ) != 0xff
|| F_30 ( V_64 , 6 ) != 0xff )
return - V_73 ;
V_72 = 1 ;
V_70 = F_30 ( V_64 , 2 ) ;
V_71 = F_30 ( V_64 , 3 ) ;
} else {
V_70 = F_30 ( V_64 , 2 ) ;
if ( F_30 ( V_64 , 4 ) != V_70
|| F_30 ( V_64 , 5 ) != V_70
|| F_30 ( V_64 , 6 ) != V_70
|| F_30 ( V_64 , 7 ) != V_70 )
return - V_73 ;
V_71 = F_30 ( V_64 , 3 ) ;
if ( F_30 ( V_64 , 4 ) != V_71
|| F_30 ( V_64 , 5 ) != V_71
|| F_30 ( V_64 , 6 ) != V_71
|| F_30 ( V_64 , 7 ) != V_71 )
return - V_73 ;
}
for ( V_68 = 8 ; V_68 <= 248 ; V_68 += 40 ) {
if ( F_30 ( V_64 , V_68 + 1 ) != V_69
|| F_30 ( V_64 , V_68 + 2 ) != V_70
|| F_30 ( V_64 , V_68 + 3 ) != V_71 )
return - V_73 ;
if ( V_72 && F_30 ( V_64 , V_68 + 7 )
!= V_74 )
return - V_73 ;
}
F_31 ( V_66 -> type , V_72 ? L_5 : L_6 , V_75 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_24 ;
struct V_14 * V_15 = F_7 ( V_2 ) ;
V_24 = F_20 ( V_15 , V_57 ) ;
if ( V_24 < 0 ) {
F_21 ( & V_15 -> V_2 , L_2 , V_24 ) ;
return V_24 ;
}
V_24 = V_24 | V_37 ;
F_13 ( V_15 , V_57 , V_24 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_24 ;
struct V_14 * V_15 = F_7 ( V_2 ) ;
V_24 = F_20 ( V_15 , V_57 ) ;
if ( V_24 < 0 ) {
F_21 ( & V_15 -> V_2 , L_2 , V_24 ) ;
return V_24 ;
}
V_24 = V_24 & ~ V_37 ;
F_13 ( V_15 , V_57 , V_24 ) ;
return 0 ;
}
static int F_20 ( struct V_14 * V_15 , T_3 V_76 )
{
if ( V_76 == V_57 )
return F_30 ( V_15 , V_76 ) ;
else
return F_34 ( V_15 , V_76 ) ;
}
static int F_13 ( struct V_14 * V_15 , T_3 V_76 , T_4 V_77 )
{
if ( V_76 == V_57 )
return F_35 ( V_15 , V_76 , V_77 ) ;
else
return F_36 ( V_15 , V_76 , V_77 ) ;
}
static struct V_8 * F_3 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_7 ( V_2 ) ;
struct V_8 * V_9 = F_8 ( V_15 ) ;
struct V_8 * V_78 = V_9 ;
F_10 ( & V_9 -> V_18 ) ;
if ( F_37 ( V_79 , V_9 -> V_80 + V_9 -> V_39 )
|| ! V_9 -> V_81 ) {
int V_68 ;
F_21 ( & V_15 -> V_2 , L_7 ) ;
for ( V_68 = 0 ; V_68 < F_38 ( V_9 -> V_10 ) ; V_68 ++ ) {
int V_24 ;
V_24 = F_20 ( V_15 , V_21 [ V_68 ] ) ;
if ( F_39 ( V_24 < 0 ) ) {
F_21 ( V_2 ,
L_8 ,
V_21 [ V_68 ] , V_24 ) ;
V_78 = F_40 ( V_24 ) ;
V_9 -> V_81 = 0 ;
goto abort;
}
V_9 -> V_10 [ V_68 ] = V_24 ;
}
V_9 -> V_80 = V_79 ;
V_9 -> V_81 = 1 ;
}
abort:
F_14 ( & V_9 -> V_18 ) ;
return V_78 ;
}
