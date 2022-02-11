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
static T_1 F_16 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_11 )
{
struct V_24 * V_25 = F_17 ( V_47 ) ;
struct V_5 * V_6 = F_7 ( V_25 ) ;
int V_13 ;
V_13 = V_6 -> V_26 -> V_50 ( V_6 ) ;
if ( V_13 < 0 )
return V_13 ;
return sprintf ( V_11 , L_5 , V_13 / 1000 , V_13 % 1000 ) ;
}
static int F_18 ( struct V_24 * V_25 , int V_39 , int V_19 )
{
struct V_5 * V_6 = F_7 ( V_25 ) ;
T_7 V_51 ;
int V_52 , V_13 ;
for ( V_52 = F_19 ( V_53 ) - 1 ; V_52 >= 1 ; V_52 -- ) {
if ( V_39 / V_53 [ V_52 ] >= V_19 )
break;
}
V_13 = F_2 ( & V_6 -> V_14 , V_54 , & V_51 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_12 ( & V_6 -> V_14 , V_54 ,
( V_51 & ~ 0x07 ) | V_52 ) ;
return V_13 ;
}
static T_1 F_20 ( struct V_46 * V_47 ,
struct V_48 * V_49 , const char * V_11 , T_3 V_12 )
{
struct V_24 * V_25 = F_17 ( V_47 ) ;
struct V_5 * V_6 = F_7 ( V_25 ) ;
int V_52 , V_55 , V_19 ;
int V_13 ;
V_13 = F_21 ( V_11 , 100 , & V_52 , & V_55 ) ;
if ( V_13 )
return V_13 ;
V_19 = V_52 * 1000 + V_55 ;
if ( V_19 <= 0 )
return - V_56 ;
F_22 ( & V_25 -> V_57 ) ;
V_6 -> V_26 -> V_58 ( V_6 , V_19 ) ;
F_23 ( & V_25 -> V_57 ) ;
return V_12 ;
}
static int F_24 ( struct V_24 * V_25 )
{
struct V_5 * V_6 = F_7 ( V_25 ) ;
int V_13 ;
V_13 = F_12 ( & V_6 -> V_14 , V_59 ,
V_60 ) ;
if ( V_13 )
F_25 ( & V_25 -> V_47 ,
L_6 ) ;
return V_13 ;
}
static int F_26 ( struct V_24 * V_25 )
{
struct V_5 * V_6 = F_7 ( V_25 ) ;
T_7 V_20 , V_61 ;
unsigned int V_62 ;
int V_13 ;
if ( V_6 -> V_26 -> V_27 & V_63 )
V_6 -> V_14 . V_42 -> V_43 = V_44 ;
else
V_6 -> V_14 . V_42 -> V_43 = V_45 ;
V_6 -> V_14 . V_42 -> V_64 = V_65 ;
F_27 ( V_6 -> V_14 . V_42 ) ;
V_13 = F_28 ( & V_6 -> V_14 ) ;
if ( V_13 )
return V_13 ;
if ( V_6 -> V_26 -> V_27 & V_31 ) {
V_13 = F_2 ( & V_6 -> V_14 ,
V_21 , & V_20 ) ;
if ( V_13 )
goto V_66;
sscanf ( V_25 -> V_67 , L_7 , & V_62 ) ;
if ( V_20 != V_62 )
F_29 ( & V_25 -> V_47 , L_8 ,
V_62 , V_20 ) ;
F_30 ( & V_25 -> V_47 , L_9 ,
V_25 -> V_67 , V_20 ,
V_6 -> V_14 . V_42 -> V_68 , V_6 -> V_14 . V_42 -> V_69 ) ;
}
if ( V_6 -> V_26 -> V_27 & V_63 ) {
V_13 = F_2 ( & V_6 -> V_14 , V_35 , & V_61 ) ;
if ( V_13 )
goto V_66;
if ( ( V_61 & V_41 ) < 0x0A ) {
V_6 -> V_14 . V_42 -> V_43 = V_45 ;
F_27 ( V_6 -> V_14 . V_42 ) ;
}
}
V_66:
return V_13 ;
}
static int F_31 ( struct V_24 * V_25 ,
struct V_70 const * V_71 , int V_19 , int V_72 , long V_73 )
{
struct V_5 * V_6 = F_7 ( V_25 ) ;
int V_13 , V_39 ;
switch ( V_73 ) {
case V_74 :
F_22 ( & V_25 -> V_57 ) ;
V_13 = F_12 ( & V_6 -> V_14 ,
V_75 [ V_71 -> V_76 ] , V_19 ) ;
F_23 ( & V_25 -> V_57 ) ;
return V_13 ;
case V_77 :
F_22 ( & V_25 -> V_57 ) ;
V_6 -> V_78 = V_19 ;
V_39 = V_6 -> V_26 -> V_50 ( V_6 ) ;
if ( V_39 < 0 ) {
F_23 ( & V_25 -> V_57 ) ;
return V_39 ;
}
V_13 = F_18 ( V_25 , V_39 ,
V_19 * 1000 + V_72 / 1000 ) ;
F_23 ( & V_25 -> V_57 ) ;
return V_13 ;
default:
return - V_56 ;
}
}
static int F_32 ( struct V_24 * V_25 ,
struct V_70 const * V_71 , int * V_19 , int * V_72 , long V_73 )
{
struct V_5 * V_6 = F_7 ( V_25 ) ;
T_9 V_51 ;
int V_13 ;
switch ( V_73 ) {
case V_79 :
return F_33 ( V_25 , V_71 , 0 , V_19 ) ;
case V_80 :
switch ( V_71 -> type ) {
case V_81 :
* V_19 = 0 ;
* V_72 = V_6 -> V_26 -> V_82 ;
return V_83 ;
case V_84 :
* V_19 = 0 ;
if ( V_71 -> V_85 == 0 ) {
* V_19 = 2 ;
* V_72 = 418000 ;
} else {
* V_19 = 0 ;
* V_72 = 805800 ;
}
return V_83 ;
case V_86 :
* V_19 = 0 ;
* V_72 = V_6 -> V_26 -> V_87 ;
return V_83 ;
case V_88 :
* V_19 = 0 ;
* V_72 = 500 ;
return V_83 ;
case V_89 :
* V_19 = V_6 -> V_26 -> V_90 / 1000000 ;
* V_72 = ( V_6 -> V_26 -> V_90 % 1000000 ) ;
return V_83 ;
default:
return - V_56 ;
}
case V_74 :
F_22 ( & V_25 -> V_57 ) ;
V_13 = F_2 ( & V_6 -> V_14 ,
V_75 [ V_71 -> V_76 ] , & V_51 ) ;
F_23 ( & V_25 -> V_57 ) ;
if ( V_13 )
return V_13 ;
V_51 = ( ( V_51 & 0xFFF ) << 4 ) >> 4 ;
* V_19 = V_51 ;
return V_91 ;
case V_92 :
* V_19 = V_6 -> V_26 -> V_93 ;
return V_91 ;
case V_77 :
F_22 ( & V_25 -> V_57 ) ;
V_13 = F_2 ( & V_6 -> V_14 ,
V_54 ,
& V_51 ) ;
if ( V_13 < 0 ) {
F_23 ( & V_25 -> V_57 ) ;
return V_13 ;
}
V_13 = V_6 -> V_26 -> V_50 ( V_6 ) ;
if ( V_13 >= 0 ) {
V_13 /= V_53 [ V_51 & 0x07 ] ;
* V_19 = V_13 / 1000 ;
* V_72 = ( V_13 % 1000 ) * 1000 ;
}
F_23 ( & V_25 -> V_57 ) ;
if ( V_13 < 0 )
return V_13 ;
return V_83 ;
default:
return - V_56 ;
}
}
static int F_34 ( struct V_94 * V_42 )
{
struct V_5 * V_6 ;
struct V_24 * V_25 ;
int V_13 ;
V_25 = F_35 ( & V_42 -> V_47 , sizeof( * V_6 ) ) ;
if ( V_25 == NULL )
return - V_95 ;
V_6 = F_7 ( V_25 ) ;
F_36 ( V_42 , V_25 ) ;
V_6 -> V_26 = & V_96 [ F_37 ( V_42 ) -> V_97 ] ;
V_25 -> V_47 . V_98 = & V_42 -> V_47 ;
V_25 -> V_67 = F_37 ( V_42 ) -> V_67 ;
V_25 -> V_99 = V_6 -> V_26 -> V_99 ;
V_25 -> V_100 = V_6 -> V_26 -> V_100 ;
V_25 -> V_73 = & V_101 ;
V_25 -> V_102 = V_103 ;
if ( ! ( V_6 -> V_26 -> V_27 & V_104 ) )
V_25 -> V_105 = V_106 ;
V_13 = F_38 ( & V_6 -> V_14 , V_25 , V_42 , & V_107 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_39 ( & V_6 -> V_14 , V_25 ,
V_108 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_26 ( V_25 ) ;
if ( V_13 )
goto V_109;
V_13 = F_40 ( V_25 ) ;
if ( V_13 )
goto V_109;
F_6 ( V_25 ) ;
return 0 ;
V_109:
F_41 ( & V_6 -> V_14 , V_25 ) ;
return V_13 ;
}
static int F_42 ( struct V_94 * V_42 )
{
struct V_24 * V_25 = F_43 ( V_42 ) ;
struct V_5 * V_6 = F_7 ( V_25 ) ;
F_44 ( V_25 ) ;
F_24 ( V_25 ) ;
F_41 ( & V_6 -> V_14 , V_25 ) ;
return 0 ;
}
