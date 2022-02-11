static T_1 F_1 ( struct V_1 * V_1 ,
char T_2 * V_2 , T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
T_5 V_8 , V_9 , V_10 ;
char V_11 [ 16 ] ;
T_3 V_12 ;
int V_13 ;
V_13 = F_2 ( & V_6 -> V_14 , V_15 , & V_8 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_2 ( & V_6 -> V_14 , V_16 , & V_9 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_2 ( & V_6 -> V_14 , V_17 ,
& V_10 ) ;
if ( V_13 < 0 )
return V_13 ;
V_12 = snprintf ( V_11 , sizeof( V_11 ) , L_1 , V_8 , V_9 ,
V_10 ) ;
return F_3 ( V_2 , V_3 , V_4 , V_11 , V_12 ) ;
}
static int F_4 ( void * V_18 , T_6 * V_19 )
{
struct V_5 * V_6 = V_18 ;
T_7 V_20 ;
int V_13 ;
V_13 = F_2 ( & V_6 -> V_14 , V_21 , & V_20 ) ;
if ( V_13 < 0 )
return V_13 ;
* V_19 = V_20 ;
return 0 ;
}
static int F_5 ( void * V_18 , T_6 * V_19 )
{
struct V_5 * V_6 = V_18 ;
T_7 V_22 ;
int V_13 ;
V_13 = F_2 ( & V_6 -> V_14 , V_23 , & V_22 ) ;
if ( V_13 < 0 )
return V_13 ;
* V_19 = V_22 ;
return 0 ;
}
static int F_6 ( struct V_24 * V_25 )
{
struct V_5 * V_6 = F_7 ( V_25 ) ;
if ( V_6 -> V_26 -> V_27 & V_28 )
F_8 ( L_2 , 0400 ,
V_25 -> V_29 , V_6 ,
& V_30 ) ;
if ( V_6 -> V_26 -> V_27 & V_31 )
F_8 ( L_3 , 0400 ,
V_25 -> V_29 , V_6 ,
& V_32 ) ;
F_8 ( L_4 , 0400 , V_25 -> V_29 ,
V_6 , & V_33 ) ;
return 0 ;
}
static int F_6 ( struct V_24 * V_25 )
{
return 0 ;
}
static int F_9 ( struct V_5 * V_6 )
{
int V_13 ;
T_7 V_34 ;
V_13 = F_2 ( & V_6 -> V_14 , V_35 , & V_34 ) ;
if ( V_13 < 0 )
return V_13 ;
V_34 >>= V_36 ;
return 819200 >> V_34 ;
}
static int F_10 ( struct V_5 * V_6 , unsigned int V_37 )
{
unsigned int V_34 ;
if ( V_37 < 819200 )
V_34 = F_11 ( 819200 / V_37 ) ;
else
V_34 = 0 ;
if ( V_34 > 0x31 )
V_34 = 0x31 ;
V_34 <<= V_36 ;
V_34 |= V_38 ;
return F_12 ( & V_6 -> V_14 , V_35 , V_34 ) ;
}
static int F_13 ( struct V_5 * V_6 )
{
int V_39 , V_13 ;
T_7 V_34 ;
V_13 = F_2 ( & V_6 -> V_14 , V_35 , & V_34 ) ;
if ( V_13 < 0 )
return V_13 ;
V_39 = ( V_34 & V_40 ) ? 52851 : 1638404 ;
V_39 /= ( V_34 & V_41 ) + 1 ;
return V_39 ;
}
static int F_14 ( struct V_5 * V_6 , unsigned int V_37 )
{
unsigned int V_34 ;
T_8 V_19 = 0 ;
V_34 = 1638404 / V_37 ;
if ( V_34 >= 128 ) {
V_19 |= V_40 ;
V_34 = 52851 / V_37 ;
if ( V_34 >= 128 )
V_34 = 127 ;
} else if ( V_34 != 0 ) {
V_34 -- ;
}
V_19 |= V_34 ;
if ( V_34 >= 0x0A || ( V_19 & V_40 ) )
V_6 -> V_14 . V_42 -> V_43 = V_44 ;
else
V_6 -> V_14 . V_42 -> V_43 = V_45 ;
return F_15 ( & V_6 -> V_14 , V_35 , V_19 ) ;
}
static int F_16 ( struct V_24 * V_25 , int V_39 , int V_19 )
{
struct V_5 * V_6 = F_7 ( V_25 ) ;
T_7 V_46 ;
int V_47 , V_13 ;
for ( V_47 = F_17 ( V_48 ) - 1 ; V_47 >= 1 ; V_47 -- ) {
if ( V_39 / V_48 [ V_47 ] >= V_19 )
break;
}
V_13 = F_2 ( & V_6 -> V_14 , V_49 , & V_46 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_12 ( & V_6 -> V_14 , V_49 ,
( V_46 & ~ 0x07 ) | V_47 ) ;
return V_13 ;
}
static int F_18 ( struct V_24 * V_25 )
{
struct V_5 * V_6 = F_7 ( V_25 ) ;
int V_13 ;
V_13 = F_12 ( & V_6 -> V_14 , V_50 ,
V_51 ) ;
if ( V_13 )
F_19 ( & V_25 -> V_52 ,
L_5 ) ;
return V_13 ;
}
static int F_20 ( struct V_24 * V_25 )
{
struct V_5 * V_6 = F_7 ( V_25 ) ;
T_7 V_20 , V_53 ;
unsigned int V_54 ;
int V_13 ;
if ( V_6 -> V_26 -> V_27 & V_55 )
V_6 -> V_14 . V_42 -> V_43 = V_44 ;
else
V_6 -> V_14 . V_42 -> V_43 = V_45 ;
V_6 -> V_14 . V_42 -> V_56 = V_57 ;
F_21 ( V_6 -> V_14 . V_42 ) ;
V_13 = F_22 ( & V_6 -> V_14 ) ;
if ( V_13 )
return V_13 ;
if ( V_6 -> V_26 -> V_27 & V_31 ) {
V_13 = F_2 ( & V_6 -> V_14 ,
V_21 , & V_20 ) ;
if ( V_13 )
goto V_58;
V_13 = sscanf ( V_25 -> V_59 , L_6 , & V_54 ) ;
if ( V_13 != 1 ) {
V_13 = - V_60 ;
goto V_58;
}
if ( V_20 != V_54 )
F_23 ( & V_25 -> V_52 , L_7 ,
V_54 , V_20 ) ;
F_24 ( & V_25 -> V_52 , L_8 ,
V_25 -> V_59 , V_20 ,
V_6 -> V_14 . V_42 -> V_61 , V_6 -> V_14 . V_42 -> V_62 ) ;
}
if ( V_6 -> V_26 -> V_27 & V_55 ) {
V_13 = F_2 ( & V_6 -> V_14 , V_35 , & V_53 ) ;
if ( V_13 )
goto V_58;
if ( ( V_53 & V_41 ) < 0x0A ) {
V_6 -> V_14 . V_42 -> V_43 = V_45 ;
F_21 ( V_6 -> V_14 . V_42 ) ;
}
}
V_58:
return V_13 ;
}
static int F_25 ( struct V_24 * V_25 ,
struct V_63 const * V_64 , int V_19 , int V_65 , long V_66 )
{
struct V_5 * V_6 = F_7 ( V_25 ) ;
int V_13 , V_39 ;
switch ( V_66 ) {
case V_67 :
F_26 ( & V_25 -> V_68 ) ;
V_13 = F_12 ( & V_6 -> V_14 ,
V_69 [ V_64 -> V_70 ] , V_19 ) ;
F_27 ( & V_25 -> V_68 ) ;
return V_13 ;
case V_71 :
F_26 ( & V_25 -> V_68 ) ;
V_6 -> V_72 = V_19 ;
V_39 = V_6 -> V_26 -> V_73 ( V_6 ) ;
if ( V_39 < 0 ) {
F_27 ( & V_25 -> V_68 ) ;
return V_39 ;
}
V_13 = F_16 ( V_25 , V_39 ,
V_19 * 1000 + V_65 / 1000 ) ;
F_27 ( & V_25 -> V_68 ) ;
return V_13 ;
case V_74 :
V_39 = V_19 * 1000 + V_65 / 1000 ;
if ( V_39 <= 0 )
return - V_60 ;
F_26 ( & V_25 -> V_68 ) ;
V_13 = V_6 -> V_26 -> V_75 ( V_6 , V_39 ) ;
F_27 ( & V_25 -> V_68 ) ;
return V_13 ;
default:
return - V_60 ;
}
}
static int F_28 ( struct V_24 * V_25 ,
struct V_63 const * V_64 , int * V_19 , int * V_65 , long V_66 )
{
struct V_5 * V_6 = F_7 ( V_25 ) ;
T_9 V_46 ;
int V_13 ;
switch ( V_66 ) {
case V_76 :
return F_29 ( V_25 , V_64 , 0 , V_19 ) ;
case V_77 :
switch ( V_64 -> type ) {
case V_78 :
* V_19 = 0 ;
* V_65 = V_6 -> V_26 -> V_79 ;
return V_80 ;
case V_81 :
* V_19 = 0 ;
if ( V_64 -> V_82 == 0 ) {
* V_19 = 2 ;
* V_65 = 418000 ;
} else {
* V_19 = 0 ;
* V_65 = 805800 ;
}
return V_80 ;
case V_83 :
* V_19 = 0 ;
* V_65 = V_6 -> V_26 -> V_84 ;
return V_80 ;
case V_85 :
* V_19 = 0 ;
* V_65 = 500 ;
return V_80 ;
case V_86 :
* V_19 = V_6 -> V_26 -> V_87 / 1000000 ;
* V_65 = ( V_6 -> V_26 -> V_87 % 1000000 ) ;
return V_80 ;
case V_88 :
* V_19 = 0 ;
* V_65 = 2000 ;
return V_80 ;
default:
return - V_60 ;
}
case V_67 :
F_26 ( & V_25 -> V_68 ) ;
V_13 = F_2 ( & V_6 -> V_14 ,
V_69 [ V_64 -> V_70 ] , & V_46 ) ;
F_27 ( & V_25 -> V_68 ) ;
if ( V_13 )
return V_13 ;
V_46 = F_30 ( V_46 , 11 ) ;
* V_19 = V_46 ;
return V_89 ;
case V_90 :
* V_19 = V_6 -> V_26 -> V_91 ;
return V_89 ;
case V_71 :
F_26 ( & V_25 -> V_68 ) ;
V_13 = F_2 ( & V_6 -> V_14 ,
V_49 ,
& V_46 ) ;
if ( V_13 < 0 ) {
F_27 ( & V_25 -> V_68 ) ;
return V_13 ;
}
V_13 = V_6 -> V_26 -> V_73 ( V_6 ) ;
if ( V_13 >= 0 ) {
V_13 /= V_48 [ V_46 & 0x07 ] ;
* V_19 = V_13 / 1000 ;
* V_65 = ( V_13 % 1000 ) * 1000 ;
}
F_27 ( & V_25 -> V_68 ) ;
if ( V_13 < 0 )
return V_13 ;
return V_80 ;
case V_74 :
V_13 = V_6 -> V_26 -> V_73 ( V_6 ) ;
if ( V_13 < 0 )
return V_13 ;
* V_19 = V_13 / 1000 ;
* V_65 = ( V_13 % 1000 ) * 1000 ;
return V_80 ;
default:
return - V_60 ;
}
}
static void F_31 ( struct V_5 * V_6 )
{
const struct V_92 * V_93 = V_6 -> V_26 ;
unsigned int V_47 ;
for ( V_47 = 0 ; V_47 < V_93 -> V_94 ; V_47 ++ ) {
const struct V_63 * V_95 = & V_93 -> V_96 [ V_47 ] ;
if ( V_95 -> V_70 >= 0 &&
V_95 -> V_70 != V_97 )
V_6 -> V_98 [ 0 ] |= F_32 ( V_95 -> V_70 ) ;
}
}
static int F_33 ( struct V_99 * V_42 )
{
struct V_5 * V_6 ;
struct V_24 * V_25 ;
int V_13 ;
V_25 = F_34 ( & V_42 -> V_52 , sizeof( * V_6 ) ) ;
if ( V_25 == NULL )
return - V_100 ;
V_6 = F_7 ( V_25 ) ;
F_35 ( V_42 , V_25 ) ;
V_6 -> V_26 = & V_101 [ F_36 ( V_42 ) -> V_102 ] ;
V_25 -> V_52 . V_103 = & V_42 -> V_52 ;
V_25 -> V_59 = F_36 ( V_42 ) -> V_59 ;
V_25 -> V_96 = V_6 -> V_26 -> V_96 ;
V_25 -> V_94 = V_6 -> V_26 -> V_94 ;
V_25 -> V_66 = & V_104 ;
V_25 -> V_105 = V_106 ;
if ( ! ( V_6 -> V_26 -> V_27 & V_107 ) ) {
F_31 ( V_6 ) ;
V_25 -> V_108 = V_6 -> V_98 ;
}
V_13 = F_37 ( & V_6 -> V_14 , V_25 , V_42 , & V_109 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_38 ( & V_6 -> V_14 , V_25 ,
V_110 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_20 ( V_25 ) ;
if ( V_13 )
goto V_111;
V_13 = F_39 ( V_25 ) ;
if ( V_13 )
goto V_111;
F_6 ( V_25 ) ;
return 0 ;
V_111:
F_40 ( & V_6 -> V_14 , V_25 ) ;
return V_13 ;
}
static int F_41 ( struct V_99 * V_42 )
{
struct V_24 * V_25 = F_42 ( V_42 ) ;
struct V_5 * V_6 = F_7 ( V_25 ) ;
F_43 ( V_25 ) ;
F_18 ( V_25 ) ;
F_40 ( & V_6 -> V_14 , V_25 ) ;
return 0 ;
}
