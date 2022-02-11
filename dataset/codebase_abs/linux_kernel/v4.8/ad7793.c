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
static int F_11 ( struct V_1 * V_5 ,
const struct V_14 * V_15 )
{
if ( ( V_15 -> V_16 == V_17 ||
V_15 -> V_16 == V_18 ) &&
( ( V_15 -> V_19 != V_20 ) &&
( V_15 -> V_19 != V_21 ) ) )
return - V_22 ;
if ( ! ( V_5 -> V_23 -> V_24 & V_25 ) &&
V_15 -> V_26 != V_27 )
return - V_22 ;
if ( ! ( V_5 -> V_23 -> V_24 & V_28 ) &&
V_15 -> V_29 != V_30 )
return - V_22 ;
if ( ! ( V_5 -> V_23 -> V_24 & V_31 ) &&
V_15 -> V_32 != V_33 )
return - V_22 ;
if ( ! ( V_5 -> V_23 -> V_24 & V_34 ) &&
V_15 -> V_19 != V_35 )
return - V_22 ;
return 0 ;
}
static int F_12 ( struct V_36 * V_37 ,
const struct V_14 * V_15 ,
unsigned int V_38 )
{
struct V_1 * V_5 = F_13 ( V_37 ) ;
int V_39 , V_40 = - 1 ;
unsigned long long V_41 ;
T_1 V_42 ;
V_40 = F_11 ( V_5 , V_15 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_14 ( V_5 -> V_3 . V_43 , ( V_44 * ) & V_40 , sizeof( V_40 ) ) ;
if ( V_40 < 0 )
goto V_45;
F_15 ( 500 , 2000 ) ;
V_40 = F_16 ( & V_5 -> V_3 , V_46 , 1 , & V_42 ) ;
if ( V_40 )
goto V_45;
V_42 &= V_47 ;
if ( V_42 != V_5 -> V_23 -> V_42 ) {
F_17 ( & V_5 -> V_3 . V_43 -> V_48 , L_1 ) ;
goto V_45;
}
V_5 -> V_10 = F_18 ( 1 ) ;
V_5 -> V_6 = 0 ;
if ( V_5 -> V_23 -> V_24 & V_25 )
V_5 -> V_10 |= F_19 ( V_15 -> V_26 ) ;
if ( V_5 -> V_23 -> V_24 & V_28 )
V_5 -> V_6 |= F_20 ( V_15 -> V_29 ) ;
if ( V_5 -> V_23 -> V_24 & V_31 )
V_5 -> V_6 |= F_21 ( V_15 -> V_32 ) ;
if ( V_15 -> V_49 || ! ( V_5 -> V_23 -> V_24 & V_50 ) )
V_5 -> V_6 |= V_51 ;
if ( V_15 -> V_52 &&
( V_5 -> V_23 -> V_24 & V_31 ) )
V_5 -> V_6 |= V_53 ;
if ( V_15 -> V_54 )
V_5 -> V_6 |= V_55 ;
if ( V_15 -> V_56 )
V_5 -> V_6 |= V_57 ;
if ( ! ( V_5 -> V_23 -> V_24 & V_58 ) )
V_5 -> V_6 |= F_22 ( 7 ) ;
V_40 = F_6 ( & V_5 -> V_3 , V_59 ) ;
if ( V_40 )
goto V_45;
V_40 = F_3 ( & V_5 -> V_3 , 0 ) ;
if ( V_40 )
goto V_45;
if ( V_5 -> V_23 -> V_24 & V_34 ) {
V_40 = F_5 ( & V_5 -> V_3 , V_60 , 1 ,
V_15 -> V_19 |
( V_15 -> V_16 << 2 ) ) ;
if ( V_40 )
goto V_45;
}
V_40 = F_8 ( V_5 ) ;
if ( V_40 )
goto V_45;
for ( V_39 = 0 ; V_39 < F_10 ( V_5 -> V_61 ) ; V_39 ++ ) {
V_41 = ( ( V_62 ) V_38 * 100000000 )
>> ( V_5 -> V_23 -> V_63 [ 0 ] . V_64 . V_65 -
( ! ! ( V_5 -> V_6 & V_57 ) ? 0 : 1 ) ) ;
V_41 >>= V_39 ;
V_5 -> V_61 [ V_39 ] [ 1 ] = F_23 ( V_41 , 100000000 ) * 10 ;
V_5 -> V_61 [ V_39 ] [ 0 ] = V_41 ;
}
return 0 ;
V_45:
F_17 ( & V_5 -> V_3 . V_43 -> V_48 , L_2 ) ;
return V_40 ;
}
static T_2 F_24 ( struct V_66 * V_48 ,
struct V_67 * V_68 ,
char * V_69 )
{
struct V_36 * V_37 = F_25 ( V_48 ) ;
struct V_1 * V_5 = F_13 ( V_37 ) ;
return sprintf ( V_69 , L_3 ,
V_5 -> V_23 -> V_70 [ F_18 ( V_5 -> V_10 ) ] ) ;
}
static T_2 F_26 ( struct V_66 * V_48 ,
struct V_67 * V_68 ,
const char * V_69 ,
T_3 V_71 )
{
struct V_36 * V_37 = F_25 ( V_48 ) ;
struct V_1 * V_5 = F_13 ( V_37 ) ;
long V_72 ;
int V_39 , V_40 ;
V_40 = F_27 ( V_69 , 10 , & V_72 ) ;
if ( V_40 )
return V_40 ;
if ( V_72 == 0 )
return - V_22 ;
for ( V_39 = 0 ; V_39 < 16 ; V_39 ++ )
if ( V_72 == V_5 -> V_23 -> V_70 [ V_39 ] )
break;
if ( V_39 == 16 )
return - V_22 ;
V_40 = F_28 ( V_37 ) ;
if ( V_40 )
return V_40 ;
V_5 -> V_10 &= ~ F_18 ( - 1 ) ;
V_5 -> V_10 |= F_18 ( V_39 ) ;
F_5 ( & V_5 -> V_3 , V_12 , sizeof( V_5 -> V_10 ) , V_5 -> V_10 ) ;
F_29 ( V_37 ) ;
return V_71 ;
}
static T_2 F_30 ( struct V_66 * V_48 ,
struct V_67 * V_68 , char * V_69 )
{
struct V_36 * V_37 = F_25 ( V_48 ) ;
struct V_1 * V_5 = F_13 ( V_37 ) ;
int V_39 , V_71 = 0 ;
for ( V_39 = 0 ; V_39 < F_10 ( V_5 -> V_61 ) ; V_39 ++ )
V_71 += sprintf ( V_69 + V_71 , L_4 , V_5 -> V_61 [ V_39 ] [ 0 ] ,
V_5 -> V_61 [ V_39 ] [ 1 ] ) ;
V_71 += sprintf ( V_69 + V_71 , L_5 ) ;
return V_71 ;
}
static int F_31 ( struct V_36 * V_37 ,
struct V_73 const * V_74 ,
int * V_75 ,
int * V_76 ,
long V_77 )
{
struct V_1 * V_5 = F_13 ( V_37 ) ;
int V_40 ;
unsigned long long V_41 ;
bool V_56 = ! ! ( V_5 -> V_6 & V_57 ) ;
switch ( V_77 ) {
case V_78 :
V_40 = F_32 ( V_37 , V_74 , V_75 ) ;
if ( V_40 < 0 )
return V_40 ;
return V_79 ;
case V_80 :
switch ( V_74 -> type ) {
case V_81 :
if ( V_74 -> V_82 ) {
* V_75 = V_5 ->
V_61 [ ( V_5 -> V_6 >> 8 ) & 0x7 ] [ 0 ] ;
* V_76 = V_5 ->
V_61 [ ( V_5 -> V_6 >> 8 ) & 0x7 ] [ 1 ] ;
return V_83 ;
}
V_41 = ( 1170ULL * 1000000000ULL * 6ULL ) ;
break;
case V_84 :
V_41 = 1444444444444444ULL ;
break;
default:
return - V_22 ;
}
V_41 >>= ( V_74 -> V_64 . V_65 - ( V_56 ? 0 : 1 ) ) ;
* V_75 = 0 ;
* V_76 = V_41 ;
return V_83 ;
case V_85 :
if ( ! V_56 )
* V_75 = - ( 1 << ( V_74 -> V_64 . V_65 - 1 ) ) ;
else
* V_75 = 0 ;
if ( V_74 -> type == V_84 ) {
unsigned long long V_86 ;
unsigned int V_87 ;
V_87 = V_74 -> V_64 . V_65 - ( V_56 ? 0 : 1 ) ;
V_86 = 273ULL << V_87 ;
F_23 ( V_86 , 1444 ) ;
* V_75 -= V_86 ;
}
return V_79 ;
}
return - V_22 ;
}
static int F_33 ( struct V_36 * V_37 ,
struct V_73 const * V_74 ,
int V_75 ,
int V_76 ,
long V_88 )
{
struct V_1 * V_5 = F_13 ( V_37 ) ;
int V_40 , V_39 ;
unsigned int V_89 ;
F_34 ( & V_37 -> V_90 ) ;
if ( F_35 ( V_37 ) ) {
F_36 ( & V_37 -> V_90 ) ;
return - V_91 ;
}
switch ( V_88 ) {
case V_80 :
V_40 = - V_22 ;
for ( V_39 = 0 ; V_39 < F_10 ( V_5 -> V_61 ) ; V_39 ++ )
if ( V_76 == V_5 -> V_61 [ V_39 ] [ 1 ] ) {
V_40 = 0 ;
V_89 = V_5 -> V_6 ;
V_5 -> V_6 &= ~ F_22 ( - 1 ) ;
V_5 -> V_6 |= F_22 ( V_39 ) ;
if ( V_89 == V_5 -> V_6 )
break;
F_5 ( & V_5 -> V_3 , V_8 ,
sizeof( V_5 -> V_6 ) , V_5 -> V_6 ) ;
F_8 ( V_5 ) ;
break;
}
break;
default:
V_40 = - V_22 ;
}
F_36 ( & V_37 -> V_90 ) ;
return V_40 ;
}
static int F_37 ( struct V_36 * V_37 ,
struct V_73 const * V_74 ,
long V_88 )
{
return V_83 ;
}
static int F_38 ( struct V_92 * V_43 )
{
const struct V_14 * V_15 = V_43 -> V_48 . V_93 ;
struct V_1 * V_5 ;
struct V_36 * V_37 ;
int V_40 , V_38 = 0 ;
if ( ! V_15 ) {
F_17 ( & V_43 -> V_48 , L_6 ) ;
return - V_94 ;
}
if ( ! V_43 -> V_95 ) {
F_17 ( & V_43 -> V_48 , L_7 ) ;
return - V_94 ;
}
V_37 = F_39 ( & V_43 -> V_48 , sizeof( * V_5 ) ) ;
if ( V_37 == NULL )
return - V_96 ;
V_5 = F_13 ( V_37 ) ;
F_40 ( & V_5 -> V_3 , V_37 , V_43 , & V_97 ) ;
if ( V_15 -> V_29 != V_98 ) {
V_5 -> V_99 = F_41 ( & V_43 -> V_48 , L_8 ) ;
if ( F_42 ( V_5 -> V_99 ) )
return F_43 ( V_5 -> V_99 ) ;
V_40 = F_44 ( V_5 -> V_99 ) ;
if ( V_40 )
return V_40 ;
V_38 = F_45 ( V_5 -> V_99 ) ;
if ( V_38 < 0 ) {
V_40 = V_38 ;
goto V_100;
}
V_38 /= 1000 ;
} else {
V_38 = 1170 ;
}
V_5 -> V_23 =
& V_101 [ F_46 ( V_43 ) -> V_102 ] ;
F_47 ( V_43 , V_37 ) ;
V_37 -> V_48 . V_103 = & V_43 -> V_48 ;
V_37 -> V_48 . V_104 = V_43 -> V_48 . V_104 ;
V_37 -> V_105 = F_46 ( V_43 ) -> V_105 ;
V_37 -> V_106 = V_107 ;
V_37 -> V_63 = V_5 -> V_23 -> V_63 ;
V_37 -> V_108 = V_5 -> V_23 -> V_108 ;
V_37 -> V_109 = V_5 -> V_23 -> V_110 ;
V_40 = F_48 ( V_37 ) ;
if ( V_40 )
goto V_100;
V_40 = F_12 ( V_37 , V_15 , V_38 ) ;
if ( V_40 )
goto V_111;
V_40 = F_49 ( V_37 ) ;
if ( V_40 )
goto V_111;
return 0 ;
V_111:
F_50 ( V_37 ) ;
V_100:
if ( V_15 -> V_29 != V_98 )
F_51 ( V_5 -> V_99 ) ;
return V_40 ;
}
static int F_52 ( struct V_92 * V_43 )
{
const struct V_14 * V_15 = V_43 -> V_48 . V_93 ;
struct V_36 * V_37 = F_53 ( V_43 ) ;
struct V_1 * V_5 = F_13 ( V_37 ) ;
F_54 ( V_37 ) ;
F_50 ( V_37 ) ;
if ( V_15 -> V_29 != V_98 )
F_51 ( V_5 -> V_99 ) ;
return 0 ;
}
