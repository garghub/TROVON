static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , unsigned int V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
V_5 -> V_6 &= ~ V_7 ;
V_5 -> V_6 |= F_4 ( V_4 ) ;
return F_5 ( & V_5 -> V_3 , V_8 , 2 , V_5 -> V_6 ) ;
}
static int F_6 ( struct V_2 * V_3 ,
enum V_9 V_10 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
V_5 -> V_10 &= ~ V_11 ;
V_5 -> V_10 |= F_7 ( V_10 ) ;
return F_5 ( & V_5 -> V_3 , V_12 , 2 , V_5 -> V_10 ) ;
}
static int F_8 ( struct V_1 * V_5 )
{
return F_9 ( & V_5 -> V_3 , V_13 ,
F_10 ( V_13 ) ) ;
}
static int F_11 ( struct V_14 * V_15 ,
const struct V_16 * V_17 )
{
struct V_1 * V_5 = F_12 ( V_15 ) ;
int V_18 , V_19 = - 1 ;
unsigned long long V_20 ;
T_1 V_21 ;
V_19 = F_13 ( V_5 -> V_3 . V_22 , ( V_23 * ) & V_19 , sizeof( V_19 ) ) ;
if ( V_19 < 0 )
goto V_24;
F_14 ( 1 ) ;
V_19 = F_15 ( & V_5 -> V_3 , V_25 , 1 , & V_21 ) ;
if ( V_19 )
goto V_24;
V_21 &= V_26 ;
if ( ! ( ( V_21 == V_27 ) || ( V_21 == V_28 ) || ( V_21 == V_29 ) ) ) {
F_16 ( & V_5 -> V_3 . V_22 -> V_30 , L_1 ) ;
goto V_24;
}
V_5 -> V_10 = V_17 -> V_10 ;
V_5 -> V_6 = V_17 -> V_6 ;
V_19 = F_6 ( & V_5 -> V_3 , V_31 ) ;
if ( V_19 )
goto V_24;
V_19 = F_3 ( & V_5 -> V_3 , 0 ) ;
if ( V_19 )
goto V_24;
V_19 = F_5 ( & V_5 -> V_3 , V_32 ,
sizeof( V_17 -> V_33 ) , V_17 -> V_33 ) ;
if ( V_19 )
goto V_24;
V_19 = F_8 ( V_5 ) ;
if ( V_19 )
goto V_24;
for ( V_18 = 0 ; V_18 < F_10 ( V_5 -> V_34 ) ; V_18 ++ ) {
V_20 = ( ( V_35 ) V_5 -> V_36 * 100000000 )
>> ( V_5 -> V_37 -> V_38 [ 0 ] . V_39 . V_40 -
( ! ! ( V_5 -> V_6 & V_41 ) ? 0 : 1 ) ) ;
V_20 >>= V_18 ;
V_5 -> V_34 [ V_18 ] [ 1 ] = F_17 ( V_20 , 100000000 ) * 10 ;
V_5 -> V_34 [ V_18 ] [ 0 ] = V_20 ;
}
return 0 ;
V_24:
F_16 ( & V_5 -> V_3 . V_22 -> V_30 , L_2 ) ;
return V_19 ;
}
static T_2 F_18 ( struct V_42 * V_30 ,
struct V_43 * V_44 ,
char * V_45 )
{
struct V_14 * V_15 = F_19 ( V_30 ) ;
struct V_1 * V_5 = F_12 ( V_15 ) ;
return sprintf ( V_45 , L_3 ,
V_46 [ F_20 ( V_5 -> V_10 ) ] ) ;
}
static T_2 F_21 ( struct V_42 * V_30 ,
struct V_43 * V_44 ,
const char * V_45 ,
T_3 V_47 )
{
struct V_14 * V_15 = F_19 ( V_30 ) ;
struct V_1 * V_5 = F_12 ( V_15 ) ;
long V_48 ;
int V_18 , V_19 ;
F_22 ( & V_15 -> V_49 ) ;
if ( F_23 ( V_15 ) ) {
F_24 ( & V_15 -> V_49 ) ;
return - V_50 ;
}
F_24 ( & V_15 -> V_49 ) ;
V_19 = F_25 ( V_45 , 10 , & V_48 ) ;
if ( V_19 )
return V_19 ;
V_19 = - V_51 ;
for ( V_18 = 0 ; V_18 < F_10 ( V_46 ) ; V_18 ++ )
if ( V_48 == V_46 [ V_18 ] ) {
F_22 ( & V_15 -> V_49 ) ;
V_5 -> V_10 &= ~ F_20 ( - 1 ) ;
V_5 -> V_10 |= F_20 ( V_18 ) ;
F_5 ( & V_5 -> V_3 , V_12 ,
sizeof( V_5 -> V_10 ) , V_5 -> V_10 ) ;
F_24 ( & V_15 -> V_49 ) ;
V_19 = 0 ;
}
return V_19 ? V_19 : V_47 ;
}
static T_2 F_26 ( struct V_42 * V_30 ,
struct V_43 * V_44 , char * V_45 )
{
struct V_14 * V_15 = F_19 ( V_30 ) ;
struct V_1 * V_5 = F_12 ( V_15 ) ;
int V_18 , V_47 = 0 ;
for ( V_18 = 0 ; V_18 < F_10 ( V_5 -> V_34 ) ; V_18 ++ )
V_47 += sprintf ( V_45 + V_47 , L_4 , V_5 -> V_34 [ V_18 ] [ 0 ] ,
V_5 -> V_34 [ V_18 ] [ 1 ] ) ;
V_47 += sprintf ( V_45 + V_47 , L_5 ) ;
return V_47 ;
}
static int F_27 ( struct V_14 * V_15 ,
struct V_52 const * V_53 ,
int * V_54 ,
int * V_55 ,
long V_56 )
{
struct V_1 * V_5 = F_12 ( V_15 ) ;
int V_19 ;
unsigned long long V_20 ;
bool V_57 = ! ! ( V_5 -> V_6 & V_41 ) ;
switch ( V_56 ) {
case V_58 :
V_19 = F_28 ( V_15 , V_53 , V_54 ) ;
if ( V_19 < 0 )
return V_19 ;
return V_59 ;
case V_60 :
switch ( V_53 -> type ) {
case V_61 :
if ( V_53 -> V_62 ) {
* V_54 = V_5 ->
V_34 [ ( V_5 -> V_6 >> 8 ) & 0x7 ] [ 0 ] ;
* V_55 = V_5 ->
V_34 [ ( V_5 -> V_6 >> 8 ) & 0x7 ] [ 1 ] ;
return V_63 ;
} else {
V_20 = ( 1170ULL * 100000000ULL * 6ULL ) ;
}
break;
case V_64 :
V_20 = 1444444444444ULL ;
break;
default:
return - V_51 ;
}
V_20 >>= ( V_53 -> V_39 . V_40 - ( V_57 ? 0 : 1 ) ) ;
* V_54 = 0 ;
* V_55 = V_20 ;
return V_63 ;
case V_65 :
if ( ! V_57 )
* V_54 = - ( 1 << ( V_53 -> V_39 . V_40 - 1 ) ) ;
else
* V_54 = 0 ;
if ( V_53 -> type == V_64 ) {
unsigned long long V_66 ;
unsigned int V_67 ;
V_67 = V_53 -> V_39 . V_40 - ( V_57 ? 0 : 1 ) ;
V_66 = 273ULL << V_67 ;
F_17 ( V_66 , 1444 ) ;
* V_54 -= V_66 ;
}
return V_59 ;
}
return - V_51 ;
}
static int F_29 ( struct V_14 * V_15 ,
struct V_52 const * V_53 ,
int V_54 ,
int V_55 ,
long V_68 )
{
struct V_1 * V_5 = F_12 ( V_15 ) ;
int V_19 , V_18 ;
unsigned int V_69 ;
F_22 ( & V_15 -> V_49 ) ;
if ( F_23 ( V_15 ) ) {
F_24 ( & V_15 -> V_49 ) ;
return - V_50 ;
}
switch ( V_68 ) {
case V_60 :
V_19 = - V_51 ;
for ( V_18 = 0 ; V_18 < F_10 ( V_5 -> V_34 ) ; V_18 ++ )
if ( V_55 == V_5 -> V_34 [ V_18 ] [ 1 ] ) {
V_19 = 0 ;
V_69 = V_5 -> V_6 ;
V_5 -> V_6 &= ~ F_30 ( - 1 ) ;
V_5 -> V_6 |= F_30 ( V_18 ) ;
if ( V_69 == V_5 -> V_6 )
break;
F_5 ( & V_5 -> V_3 , V_8 ,
sizeof( V_5 -> V_6 ) , V_5 -> V_6 ) ;
F_8 ( V_5 ) ;
break;
}
break;
default:
V_19 = - V_51 ;
}
F_24 ( & V_15 -> V_49 ) ;
return V_19 ;
}
static int F_31 ( struct V_14 * V_15 ,
struct V_52 const * V_53 ,
long V_68 )
{
return V_63 ;
}
static int T_4 F_32 ( struct V_70 * V_22 )
{
const struct V_16 * V_17 = V_22 -> V_30 . V_71 ;
struct V_1 * V_5 ;
struct V_14 * V_15 ;
int V_19 , V_72 = 0 ;
if ( ! V_17 ) {
F_16 ( & V_22 -> V_30 , L_6 ) ;
return - V_73 ;
}
if ( ! V_22 -> V_74 ) {
F_16 ( & V_22 -> V_30 , L_7 ) ;
return - V_73 ;
}
V_15 = F_33 ( sizeof( * V_5 ) ) ;
if ( V_15 == NULL )
return - V_75 ;
V_5 = F_12 ( V_15 ) ;
F_34 ( & V_5 -> V_3 , V_15 , V_22 , & V_76 ) ;
V_5 -> V_77 = F_35 ( & V_22 -> V_30 , L_8 ) ;
if ( ! F_36 ( V_5 -> V_77 ) ) {
V_19 = F_37 ( V_5 -> V_77 ) ;
if ( V_19 )
goto V_78;
V_72 = F_38 ( V_5 -> V_77 ) ;
}
V_5 -> V_37 =
& V_79 [ F_39 ( V_22 ) -> V_80 ] ;
if ( V_17 && V_17 -> V_81 )
V_5 -> V_36 = V_17 -> V_81 ;
else if ( V_72 )
V_5 -> V_36 = V_72 / 1000 ;
else
V_5 -> V_36 = 1170 ;
F_40 ( V_22 , V_15 ) ;
V_15 -> V_30 . V_82 = & V_22 -> V_30 ;
V_15 -> V_83 = F_39 ( V_22 ) -> V_83 ;
V_15 -> V_84 = V_85 ;
V_15 -> V_38 = V_5 -> V_37 -> V_38 ;
V_15 -> V_86 = V_5 -> V_37 -> V_86 ;
V_15 -> V_87 = & V_88 ;
V_19 = F_41 ( V_15 ) ;
if ( V_19 )
goto V_89;
V_19 = F_11 ( V_15 , V_17 ) ;
if ( V_19 )
goto V_90;
V_19 = F_42 ( V_15 ) ;
if ( V_19 )
goto V_90;
return 0 ;
V_90:
F_43 ( V_15 ) ;
V_89:
if ( ! F_36 ( V_5 -> V_77 ) )
F_44 ( V_5 -> V_77 ) ;
V_78:
if ( ! F_36 ( V_5 -> V_77 ) )
F_45 ( V_5 -> V_77 ) ;
F_46 ( V_15 ) ;
return V_19 ;
}
static int T_5 F_47 ( struct V_70 * V_22 )
{
struct V_14 * V_15 = F_48 ( V_22 ) ;
struct V_1 * V_5 = F_12 ( V_15 ) ;
F_49 ( V_15 ) ;
F_43 ( V_15 ) ;
if ( ! F_36 ( V_5 -> V_77 ) ) {
F_44 ( V_5 -> V_77 ) ;
F_45 ( V_5 -> V_77 ) ;
}
F_46 ( V_15 ) ;
return 0 ;
}
