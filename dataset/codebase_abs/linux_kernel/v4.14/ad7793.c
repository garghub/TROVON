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
int V_39 , V_40 ;
unsigned long long V_41 ;
T_1 V_42 ;
V_40 = F_11 ( V_5 , V_15 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_14 ( & V_5 -> V_3 , 32 ) ;
if ( V_40 < 0 )
goto V_43;
F_15 ( 500 , 2000 ) ;
V_40 = F_16 ( & V_5 -> V_3 , V_44 , 1 , & V_42 ) ;
if ( V_40 )
goto V_43;
V_42 &= V_45 ;
if ( V_42 != V_5 -> V_23 -> V_42 ) {
F_17 ( & V_5 -> V_3 . V_46 -> V_47 , L_1 ) ;
goto V_43;
}
V_5 -> V_10 = F_18 ( 1 ) ;
V_5 -> V_6 = 0 ;
if ( V_5 -> V_23 -> V_24 & V_25 )
V_5 -> V_10 |= F_19 ( V_15 -> V_26 ) ;
if ( V_5 -> V_23 -> V_24 & V_28 )
V_5 -> V_6 |= F_20 ( V_15 -> V_29 ) ;
if ( V_5 -> V_23 -> V_24 & V_31 )
V_5 -> V_6 |= F_21 ( V_15 -> V_32 ) ;
if ( V_15 -> V_48 || ! ( V_5 -> V_23 -> V_24 & V_49 ) )
V_5 -> V_6 |= V_50 ;
if ( V_15 -> V_51 &&
( V_5 -> V_23 -> V_24 & V_31 ) )
V_5 -> V_6 |= V_52 ;
if ( V_15 -> V_53 )
V_5 -> V_6 |= V_54 ;
if ( V_15 -> V_55 )
V_5 -> V_6 |= V_56 ;
if ( ! ( V_5 -> V_23 -> V_24 & V_57 ) )
V_5 -> V_6 |= F_22 ( 7 ) ;
V_40 = F_6 ( & V_5 -> V_3 , V_58 ) ;
if ( V_40 )
goto V_43;
V_40 = F_3 ( & V_5 -> V_3 , 0 ) ;
if ( V_40 )
goto V_43;
if ( V_5 -> V_23 -> V_24 & V_34 ) {
V_40 = F_5 ( & V_5 -> V_3 , V_59 , 1 ,
V_15 -> V_19 |
( V_15 -> V_16 << 2 ) ) ;
if ( V_40 )
goto V_43;
}
V_40 = F_8 ( V_5 ) ;
if ( V_40 )
goto V_43;
for ( V_39 = 0 ; V_39 < F_10 ( V_5 -> V_60 ) ; V_39 ++ ) {
V_41 = ( ( V_61 ) V_38 * 100000000 )
>> ( V_5 -> V_23 -> V_62 [ 0 ] . V_63 . V_64 -
( ! ! ( V_5 -> V_6 & V_56 ) ? 0 : 1 ) ) ;
V_41 >>= V_39 ;
V_5 -> V_60 [ V_39 ] [ 1 ] = F_23 ( V_41 , 100000000 ) * 10 ;
V_5 -> V_60 [ V_39 ] [ 0 ] = V_41 ;
}
return 0 ;
V_43:
F_17 ( & V_5 -> V_3 . V_46 -> V_47 , L_2 ) ;
return V_40 ;
}
static T_2 F_24 ( struct V_65 * V_47 ,
struct V_66 * V_67 ,
char * V_68 )
{
struct V_36 * V_37 = F_25 ( V_47 ) ;
struct V_1 * V_5 = F_13 ( V_37 ) ;
return sprintf ( V_68 , L_3 ,
V_5 -> V_23 -> V_69 [ F_18 ( V_5 -> V_10 ) ] ) ;
}
static T_2 F_26 ( struct V_65 * V_47 ,
struct V_66 * V_67 ,
const char * V_68 ,
T_3 V_70 )
{
struct V_36 * V_37 = F_25 ( V_47 ) ;
struct V_1 * V_5 = F_13 ( V_37 ) ;
long V_71 ;
int V_39 , V_40 ;
V_40 = F_27 ( V_68 , 10 , & V_71 ) ;
if ( V_40 )
return V_40 ;
if ( V_71 == 0 )
return - V_22 ;
for ( V_39 = 0 ; V_39 < 16 ; V_39 ++ )
if ( V_71 == V_5 -> V_23 -> V_69 [ V_39 ] )
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
return V_70 ;
}
static T_2 F_30 ( struct V_65 * V_47 ,
struct V_66 * V_67 , char * V_68 )
{
struct V_36 * V_37 = F_25 ( V_47 ) ;
struct V_1 * V_5 = F_13 ( V_37 ) ;
int V_39 , V_70 = 0 ;
for ( V_39 = 0 ; V_39 < F_10 ( V_5 -> V_60 ) ; V_39 ++ )
V_70 += sprintf ( V_68 + V_70 , L_4 , V_5 -> V_60 [ V_39 ] [ 0 ] ,
V_5 -> V_60 [ V_39 ] [ 1 ] ) ;
V_70 += sprintf ( V_68 + V_70 , L_5 ) ;
return V_70 ;
}
static int F_31 ( struct V_36 * V_37 ,
struct V_72 const * V_73 ,
int * V_74 ,
int * V_75 ,
long V_76 )
{
struct V_1 * V_5 = F_13 ( V_37 ) ;
int V_40 ;
unsigned long long V_41 ;
bool V_55 = ! ! ( V_5 -> V_6 & V_56 ) ;
switch ( V_76 ) {
case V_77 :
V_40 = F_32 ( V_37 , V_73 , V_74 ) ;
if ( V_40 < 0 )
return V_40 ;
return V_78 ;
case V_79 :
switch ( V_73 -> type ) {
case V_80 :
if ( V_73 -> V_81 ) {
* V_74 = V_5 ->
V_60 [ ( V_5 -> V_6 >> 8 ) & 0x7 ] [ 0 ] ;
* V_75 = V_5 ->
V_60 [ ( V_5 -> V_6 >> 8 ) & 0x7 ] [ 1 ] ;
return V_82 ;
}
V_41 = ( 1170ULL * 1000000000ULL * 6ULL ) ;
break;
case V_83 :
V_41 = 1444444444444444ULL ;
break;
default:
return - V_22 ;
}
V_41 >>= ( V_73 -> V_63 . V_64 - ( V_55 ? 0 : 1 ) ) ;
* V_74 = 0 ;
* V_75 = V_41 ;
return V_82 ;
case V_84 :
if ( ! V_55 )
* V_74 = - ( 1 << ( V_73 -> V_63 . V_64 - 1 ) ) ;
else
* V_74 = 0 ;
if ( V_73 -> type == V_83 ) {
unsigned long long V_85 ;
unsigned int V_86 ;
V_86 = V_73 -> V_63 . V_64 - ( V_55 ? 0 : 1 ) ;
V_85 = 273ULL << V_86 ;
F_23 ( V_85 , 1444 ) ;
* V_74 -= V_85 ;
}
return V_78 ;
}
return - V_22 ;
}
static int F_33 ( struct V_36 * V_37 ,
struct V_72 const * V_73 ,
int V_74 ,
int V_75 ,
long V_87 )
{
struct V_1 * V_5 = F_13 ( V_37 ) ;
int V_40 , V_39 ;
unsigned int V_88 ;
V_40 = F_28 ( V_37 ) ;
if ( V_40 )
return V_40 ;
switch ( V_87 ) {
case V_79 :
V_40 = - V_22 ;
for ( V_39 = 0 ; V_39 < F_10 ( V_5 -> V_60 ) ; V_39 ++ )
if ( V_75 == V_5 -> V_60 [ V_39 ] [ 1 ] ) {
V_40 = 0 ;
V_88 = V_5 -> V_6 ;
V_5 -> V_6 &= ~ F_22 ( - 1 ) ;
V_5 -> V_6 |= F_22 ( V_39 ) ;
if ( V_88 == V_5 -> V_6 )
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
F_29 ( V_37 ) ;
return V_40 ;
}
static int F_34 ( struct V_36 * V_37 ,
struct V_72 const * V_73 ,
long V_87 )
{
return V_82 ;
}
static int F_35 ( struct V_89 * V_46 )
{
const struct V_14 * V_15 = V_46 -> V_47 . V_90 ;
struct V_1 * V_5 ;
struct V_36 * V_37 ;
int V_40 , V_38 = 0 ;
if ( ! V_15 ) {
F_17 ( & V_46 -> V_47 , L_6 ) ;
return - V_91 ;
}
if ( ! V_46 -> V_92 ) {
F_17 ( & V_46 -> V_47 , L_7 ) ;
return - V_91 ;
}
V_37 = F_36 ( & V_46 -> V_47 , sizeof( * V_5 ) ) ;
if ( V_37 == NULL )
return - V_93 ;
V_5 = F_13 ( V_37 ) ;
F_37 ( & V_5 -> V_3 , V_37 , V_46 , & V_94 ) ;
if ( V_15 -> V_29 != V_95 ) {
V_5 -> V_96 = F_38 ( & V_46 -> V_47 , L_8 ) ;
if ( F_39 ( V_5 -> V_96 ) )
return F_40 ( V_5 -> V_96 ) ;
V_40 = F_41 ( V_5 -> V_96 ) ;
if ( V_40 )
return V_40 ;
V_38 = F_42 ( V_5 -> V_96 ) ;
if ( V_38 < 0 ) {
V_40 = V_38 ;
goto V_97;
}
V_38 /= 1000 ;
} else {
V_38 = 1170 ;
}
V_5 -> V_23 =
& V_98 [ F_43 ( V_46 ) -> V_99 ] ;
F_44 ( V_46 , V_37 ) ;
V_37 -> V_47 . V_100 = & V_46 -> V_47 ;
V_37 -> V_47 . V_101 = V_46 -> V_47 . V_101 ;
V_37 -> V_102 = F_43 ( V_46 ) -> V_102 ;
V_37 -> V_103 = V_104 ;
V_37 -> V_62 = V_5 -> V_23 -> V_62 ;
V_37 -> V_105 = V_5 -> V_23 -> V_105 ;
V_37 -> V_106 = V_5 -> V_23 -> V_107 ;
V_40 = F_45 ( V_37 ) ;
if ( V_40 )
goto V_97;
V_40 = F_12 ( V_37 , V_15 , V_38 ) ;
if ( V_40 )
goto V_108;
V_40 = F_46 ( V_37 ) ;
if ( V_40 )
goto V_108;
return 0 ;
V_108:
F_47 ( V_37 ) ;
V_97:
if ( V_15 -> V_29 != V_95 )
F_48 ( V_5 -> V_96 ) ;
return V_40 ;
}
static int F_49 ( struct V_89 * V_46 )
{
const struct V_14 * V_15 = V_46 -> V_47 . V_90 ;
struct V_36 * V_37 = F_50 ( V_46 ) ;
struct V_1 * V_5 = F_13 ( V_37 ) ;
F_51 ( V_37 ) ;
F_47 ( V_37 ) ;
if ( V_15 -> V_29 != V_95 )
F_48 ( V_5 -> V_96 ) ;
return 0 ;
}
