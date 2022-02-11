static unsigned F_1 ( T_1 V_1 )
{
if ( V_1 & V_2 ) {
unsigned V_3 = 0 ;
V_1 &= ~ V_2 ;
if ( V_1 & V_4 ) {
V_3 = 12 ;
V_1 &= ~ V_4 ;
}
V_3 += F_2 ( V_1 ) ;
return V_3 - 1 ;
}
return F_2 ( V_1 ) ;
}
static T_1 F_3 ( bool V_5 , int V_3 )
{
if ( V_5 ) {
V_3 ++ ;
if ( V_3 <= 12 )
return V_2 | F_4 ( V_3 ) ;
V_3 -= 12 ;
return V_2 | V_4 | F_4 ( V_3 ) ;
}
return F_4 ( V_3 ) ;
}
static int F_5 ( struct V_6 * V_7 , unsigned int V_8 )
{
struct V_9 * V_9 = F_6 ( V_7 ) ;
T_1 V_10 [ 2 ] ;
long V_11 = - V_12 ;
V_10 [ 0 ] = V_13 | V_14 ;
V_10 [ 1 ] = V_9 -> V_15 [ 0 ] ;
if ( V_8 ) {
if ( V_9 -> V_15 [ 0 ] & V_16 )
goto V_17;
V_10 [ 1 ] |= V_16 ;
} else {
if ( ! ( V_10 [ 1 ] & V_16 ) )
goto V_17;
V_10 [ 1 ] &= ~ V_16 ;
}
V_11 = F_7 ( V_9 -> V_18 , V_10 , sizeof( V_10 ) , NULL , 0 ) ;
if ( V_11 >= 0 )
V_9 -> V_15 [ 0 ] = V_10 [ 1 ] ;
V_17:
return V_11 ;
}
static int F_8 ( struct V_6 * V_7 , struct V_19 * time )
{
struct V_9 * V_9 = F_6 ( V_7 ) ;
T_1 V_20 = V_21 ;
T_1 V_10 [ V_22 ] ;
int V_23 ;
V_23 = F_7 ( V_9 -> V_18 , & V_20 , sizeof( V_20 ) ,
V_10 , sizeof( V_10 ) ) ;
if ( V_23 < 0 )
return V_23 ;
F_9 ( V_7 , L_1 , L_2 , & V_10 [ 0 ] , & V_10 [ 3 ] ) ;
time -> V_24 = F_2 ( V_10 [ V_21 ] ) ;
time -> V_25 = F_2 ( V_10 [ V_26 ] ) ;
time -> V_27 = F_1 ( V_10 [ V_28 ] ) ;
time -> V_29 = V_10 [ V_30 ] - 1 ;
time -> V_31 = F_2 ( V_10 [ V_32 ] ) ;
time -> V_33 = F_2 ( V_10 [ V_34 ] ) - 1 ;
time -> V_35 = F_2 ( V_10 [ V_36 ] ) + 100 ;
F_9 ( V_7 , L_3
L_4 ,
L_2 , time -> V_24 , time -> V_25 ,
time -> V_27 , time -> V_31 ,
time -> V_33 , time -> V_35 , time -> V_29 ) ;
return F_10 ( time ) ;
}
static int F_11 ( struct V_6 * V_7 , struct V_19 * time )
{
struct V_9 * V_9 = F_6 ( V_7 ) ;
T_1 V_10 [ 1 + V_22 ] ;
T_1 * V_37 = V_10 ;
F_9 ( V_7 , L_3
L_4 ,
L_5 , time -> V_24 , time -> V_25 ,
time -> V_27 , time -> V_31 ,
time -> V_33 , time -> V_35 , time -> V_29 ) ;
* V_37 ++ = V_13 | V_21 ;
* V_37 ++ = F_4 ( time -> V_24 ) ;
* V_37 ++ = F_4 ( time -> V_25 ) ;
* V_37 ++ = F_3 ( V_9 -> V_5 , time -> V_27 ) ;
* V_37 ++ = ( time -> V_29 < 7 ) ? ( time -> V_29 + 1 ) : 1 ;
* V_37 ++ = F_4 ( time -> V_31 ) ;
* V_37 ++ = F_4 ( time -> V_33 + 1 ) ;
* V_37 ++ = F_4 ( time -> V_35 - 100 ) ;
F_12 ( V_7 , L_1 , L_5 , & V_10 [ 1 ] , & V_10 [ 4 ] ) ;
return F_7 ( V_9 -> V_18 , V_10 , sizeof( V_10 ) ,
NULL , 0 ) ;
}
static int F_13 ( struct V_6 * V_7 , struct V_38 * V_39 )
{
struct V_9 * V_9 = F_6 ( V_7 ) ;
struct V_40 * V_18 = V_9 -> V_18 ;
T_1 V_20 ;
int V_23 ;
T_1 V_10 [ V_41 ] ;
V_20 = V_14 ;
V_23 = F_7 ( V_18 , & V_20 , sizeof( V_20 ) ,
V_9 -> V_15 , sizeof( V_9 -> V_15 ) ) ;
if ( V_23 < 0 )
return V_23 ;
V_39 -> V_8 = ! ! ( V_9 -> V_15 [ 0 ] & V_16 ) ;
V_39 -> V_42 = ! ! ( V_9 -> V_15 [ 1 ] & V_16 ) ;
V_20 = F_14 ( V_21 ) ;
V_23 = F_7 ( V_18 , & V_20 , sizeof( V_20 ) ,
V_10 , sizeof( V_10 ) ) ;
if ( V_23 < 0 )
return V_23 ;
F_9 ( V_7 , L_6 ,
L_7 , V_10 [ V_21 ] , V_10 [ V_26 ] ,
V_10 [ V_28 ] , V_10 [ V_30 ] ) ;
if ( ( V_43 & V_10 [ V_21 ] )
|| ( V_43 & V_10 [ V_26 ] )
|| ( V_43 & V_10 [ V_28 ] ) )
return - V_44 ;
V_39 -> time . V_24 = F_2 ( V_10 [ V_21 ] ) ;
V_39 -> time . V_25 = F_2 ( V_10 [ V_26 ] ) ;
V_39 -> time . V_27 = F_1 ( V_10 [ V_28 ] ) ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 , struct V_38 * V_39 )
{
struct V_9 * V_9 = F_6 ( V_7 ) ;
struct V_40 * V_18 = V_9 -> V_18 ;
unsigned long V_45 , V_46 ;
struct V_19 V_47 ;
int V_23 ;
T_1 V_10 [ 1 + V_41 ] ;
V_23 = F_16 ( & V_39 -> time , & V_46 ) ;
if ( V_23 < 0 )
return V_23 ;
V_23 = F_8 ( V_7 , & V_47 ) ;
if ( V_23 < 0 )
return V_23 ;
V_23 = F_16 ( & V_47 , & V_45 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_46 <= V_45 )
return - V_12 ;
if ( ( V_46 - V_45 ) > 24 * 60 * 60 )
return - V_48 ;
if ( V_9 -> V_15 [ 0 ] & V_16 ) {
V_9 -> V_15 [ 0 ] &= ~ V_16 ;
V_10 [ 0 ] = V_13 | V_14 ;
V_10 [ 1 ] = V_9 -> V_15 [ 0 ] ;
V_23 = F_7 ( V_9 -> V_18 , V_10 , 2 , NULL , 0 ) ;
if ( V_23 < 0 )
return V_23 ;
}
V_10 [ 0 ] = V_13 | F_14 ( V_21 ) ;
V_10 [ 1 + V_21 ] = F_4 ( V_39 -> time . V_24 ) ;
V_10 [ 1 + V_26 ] = F_4 ( V_39 -> time . V_25 ) ;
V_10 [ 1 + V_28 ] = F_3 ( V_9 -> V_5 , V_39 -> time . V_27 ) ;
V_10 [ 1 + V_30 ] = V_43 ;
F_12 ( V_7 , L_6 ,
L_8 , V_10 [ 1 + V_21 ] , V_10 [ 1 + V_26 ] ,
V_10 [ 1 + V_28 ] , V_10 [ 1 + V_30 ] ) ;
V_23 = F_7 ( V_18 , V_10 , sizeof( V_10 ) , NULL , 0 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_39 -> V_8 ) {
V_9 -> V_15 [ 0 ] |= V_16 ;
V_10 [ 0 ] = V_13 | V_14 ;
V_10 [ 1 ] = V_9 -> V_15 [ 0 ] ;
V_23 = F_7 ( V_9 -> V_18 , V_10 , 2 , NULL , 0 ) ;
}
return V_23 ;
}
static int F_17 ( struct V_6 * V_7 , struct V_49 * V_50 )
{
struct V_9 * V_9 = F_6 ( V_7 ) ;
char * V_51 = L_9 ;
char * V_52 = L_10 ;
if ( ( V_9 -> V_15 [ 2 ] & 0xf0 ) == V_53 ) {
switch ( V_9 -> V_15 [ 2 ] & 0x0c ) {
case V_54 :
V_51 = L_11 ;
break;
case V_55 :
V_51 = L_12 ;
break;
default:
goto V_17;
}
switch ( V_9 -> V_15 [ 2 ] & 0x03 ) {
case V_56 :
V_52 = L_13 ;
break;
case V_57 :
V_52 = L_14 ;
break;
case V_58 :
V_52 = L_15 ;
break;
default:
V_51 = L_9 ;
break;
}
}
V_17:
F_18 ( V_50 , L_16 , V_51 , V_52 ) ;
return 0 ;
}
static void F_19 ( struct V_59 * V_60 )
{
struct V_9 * V_9 = F_20 ( V_60 , struct V_9 , V_60 ) ;
struct V_61 * V_62 = & V_9 -> V_63 -> V_64 ;
struct V_40 * V_18 = V_9 -> V_18 ;
T_1 V_10 [ 3 ] ;
int V_23 ;
F_21 ( V_62 ) ;
V_9 -> V_15 [ 0 ] &= ~ ( V_65 | V_16 ) ;
V_9 -> V_15 [ 1 ] = 0 ;
V_10 [ 0 ] = V_13 | V_14 ;
V_10 [ 1 ] = V_9 -> V_15 [ 0 ] ;
V_10 [ 2 ] = 0 ;
V_23 = F_7 ( V_18 , V_10 , sizeof( V_10 ) ,
NULL , 0 ) ;
if ( V_23 < 0 )
F_12 ( & V_18 -> V_7 , L_17 , V_23 ) ;
F_22 ( V_62 ) ;
if ( ! F_23 ( V_66 , & V_9 -> V_67 ) )
F_24 ( V_18 -> V_68 ) ;
F_25 ( V_9 -> V_63 , 1 , V_69 | V_70 ) ;
}
static T_2 F_26 ( int V_68 , void * V_71 )
{
struct V_9 * V_9 = V_71 ;
F_27 ( V_68 ) ;
F_28 ( & V_9 -> V_60 ) ;
return V_72 ;
}
static void F_29 ( struct V_73 * V_74 , struct V_75 * V_76 ,
T_1 * V_20 , T_3 V_77 , char * V_78 , char * V_79 )
{
F_30 ( V_74 ) ;
memset ( V_76 , 0 , 2 * sizeof( * V_76 ) ) ;
V_76 -> V_80 = V_20 ;
V_76 -> V_81 = 1 ;
F_31 ( V_76 , V_74 ) ;
V_76 ++ ;
V_76 -> V_80 = V_78 ;
V_76 -> V_82 = V_79 ;
V_76 -> V_81 = V_77 ;
F_31 ( V_76 , V_74 ) ;
}
static T_4
F_32 ( struct V_83 * V_84 , struct V_85 * V_86 ,
struct V_87 * V_88 ,
char * V_10 , T_5 V_89 , T_3 V_77 )
{
struct V_40 * V_18 ;
T_1 V_20 ;
struct V_73 V_74 ;
struct V_75 V_76 [ 2 ] ;
int V_23 ;
V_18 = F_33 ( F_34 ( V_86 ) ) ;
V_20 = V_90 + V_89 ;
F_29 ( & V_74 , V_76 , & V_20 , V_77 , NULL , V_10 ) ;
V_23 = F_35 ( V_18 , & V_74 ) ;
if ( V_23 < 0 )
F_36 ( & V_18 -> V_7 , L_18 , L_2 , V_23 ) ;
return ( V_23 < 0 ) ? V_23 : V_77 ;
}
static T_4
F_37 ( struct V_83 * V_84 , struct V_85 * V_86 ,
struct V_87 * V_88 ,
char * V_10 , T_5 V_89 , T_3 V_77 )
{
struct V_40 * V_18 ;
T_1 V_20 ;
struct V_73 V_74 ;
struct V_75 V_76 [ 2 ] ;
int V_23 ;
V_18 = F_33 ( F_34 ( V_86 ) ) ;
V_20 = ( V_13 | V_90 ) + V_89 ;
F_29 ( & V_74 , V_76 , & V_20 , V_77 , V_10 , NULL ) ;
V_23 = F_35 ( V_18 , & V_74 ) ;
if ( V_23 < 0 )
F_36 ( & V_18 -> V_7 , L_18 , L_5 , V_23 ) ;
return ( V_23 < 0 ) ? V_23 : V_77 ;
}
static int F_38 ( struct V_40 * V_18 )
{
struct V_9 * V_9 ;
int V_23 ;
T_1 V_20 , V_91 ;
struct V_92 * V_93 = F_39 ( & V_18 -> V_7 ) ;
bool V_94 = false ;
if ( ( V_18 -> V_95 && V_18 -> V_95 != 8 )
|| ( V_18 -> V_96 > 2000000 )
|| ! ( V_18 -> V_97 & V_98 ) )
return - V_12 ;
V_9 = F_40 ( & V_18 -> V_7 , sizeof( * V_9 ) , V_99 ) ;
if ( ! V_9 )
return - V_100 ;
V_9 -> V_18 = V_18 ;
F_41 ( V_18 , V_9 ) ;
V_20 = V_14 ;
V_23 = F_7 ( V_18 , & V_20 , sizeof( V_20 ) ,
V_9 -> V_15 , sizeof( V_9 -> V_15 ) ) ;
if ( V_23 < 0 ) {
F_12 ( & V_18 -> V_7 , L_19 ,
L_2 , V_23 ) ;
return V_23 ;
}
F_12 ( & V_18 -> V_7 , L_20 , L_2 , V_9 -> V_15 ) ;
if ( ( V_9 -> V_15 [ 0 ] & 0x38 ) != 0 || ( V_9 -> V_15 [ 1 ] & 0xfc ) != 0 ) {
F_12 ( & V_18 -> V_7 , L_21 ) ;
return - V_101 ;
}
if ( V_9 -> V_15 [ 2 ] == 0 )
F_12 ( & V_18 -> V_7 , L_22 ) ;
if ( V_9 -> V_15 [ 0 ] & V_102 ) {
T_1 V_10 [ 2 ] ;
V_9 -> V_15 [ 0 ] &= ~ V_102 ;
V_10 [ 0 ] = V_13 | V_14 ;
V_10 [ 1 ] = V_9 -> V_15 [ 0 ] ;
V_23 = F_7 ( V_18 , V_10 , sizeof( V_10 ) , NULL , 0 ) ;
F_12 ( & V_18 -> V_7 , L_23 , V_23 ) ;
if ( V_23 < 0 )
return V_23 ;
}
if ( V_9 -> V_15 [ 0 ] & V_103 ) {
V_9 -> V_15 [ 0 ] &= ~ V_103 ;
V_94 = true ;
F_42 ( & V_18 -> V_7 , L_24 ) ;
}
if ( V_9 -> V_15 [ 1 ] ) {
V_9 -> V_15 [ 1 ] = 0 ;
V_94 = true ;
}
if ( V_93 ) {
if ( ( ( V_9 -> V_15 [ 2 ] & 0xf0 ) != V_53 ) ) {
V_9 -> V_15 [ 2 ] = V_53
| V_93 -> V_104 ;
V_94 = true ;
}
if ( V_93 -> V_105 ) {
if ( V_93 -> V_106 ) {
if ( ! ( V_9 -> V_15 [ 0 ] & V_107 ) ) {
V_9 -> V_15 [ 0 ] |= V_107 ;
V_94 = true ;
}
} else {
if ( V_9 -> V_15 [ 0 ] & V_107 ) {
V_9 -> V_15 [ 0 ] &= ~ V_107 ;
V_94 = true ;
}
}
}
}
if ( V_94 ) {
T_1 V_10 [ 4 ] ;
V_10 [ 0 ] = V_13 | V_14 ;
V_10 [ 1 ] = V_9 -> V_15 [ 0 ] ;
V_10 [ 2 ] = V_9 -> V_15 [ 1 ] ;
V_10 [ 3 ] = V_9 -> V_15 [ 2 ] ;
V_23 = F_7 ( V_18 , V_10 , sizeof( V_10 ) , NULL , 0 ) ;
if ( V_23 < 0 ) {
F_12 ( & V_18 -> V_7 , L_19 ,
L_5 , V_23 ) ;
return V_23 ;
}
F_12 ( & V_18 -> V_7 , L_20 , L_5 , V_9 -> V_15 ) ;
}
V_20 = V_28 ;
V_23 = F_7 ( V_18 , & V_20 , sizeof( V_20 ) ,
& V_91 , sizeof( V_91 ) ) ;
if ( V_23 < 0 ) {
F_12 ( & V_18 -> V_7 , L_25 , V_23 ) ;
return V_23 ;
}
V_9 -> V_5 = ( V_2 & V_91 ) != 0 ;
if ( V_9 -> V_5 )
F_12 ( & V_18 -> V_7 , L_26 ) ;
V_9 -> V_63 = F_43 ( & V_18 -> V_7 , L_27 ,
& V_108 , V_109 ) ;
if ( F_44 ( V_9 -> V_63 ) ) {
V_23 = F_45 ( V_9 -> V_63 ) ;
F_12 ( & V_18 -> V_7 , L_28 , V_23 ) ;
return V_23 ;
}
if ( V_18 -> V_68 ) {
F_46 ( & V_9 -> V_60 , F_19 ) ;
V_23 = F_47 ( & V_18 -> V_7 , V_18 -> V_68 , F_26 ,
0 , F_48 ( & V_9 -> V_63 -> V_7 ) , V_9 ) ;
if ( V_23 < 0 ) {
F_36 ( & V_18 -> V_7 , L_29 ,
V_18 -> V_68 , V_23 ) ;
} else {
F_49 ( & V_18 -> V_7 , 1 ) ;
}
}
V_23 = F_50 ( & V_18 -> V_7 . V_86 , & V_110 ) ;
if ( V_23 < 0 ) {
F_36 ( & V_18 -> V_7 , L_30 , V_23 ) ;
}
return 0 ;
}
static int F_51 ( struct V_40 * V_18 )
{
struct V_9 * V_9 = F_52 ( V_18 ) ;
F_53 ( & V_18 -> V_7 . V_86 , & V_110 ) ;
if ( V_18 -> V_68 ) {
F_54 ( V_66 , & V_9 -> V_67 ) ;
F_55 ( & V_18 -> V_7 , V_18 -> V_68 , V_9 ) ;
F_56 ( & V_9 -> V_60 ) ;
}
return 0 ;
}
