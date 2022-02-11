static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_6 ;
while ( V_5 -> V_7 ) {
if ( V_5 -> V_7 == V_3 )
return V_5 -> V_8 ;
V_5 ++ ;
}
F_2 () ;
return 0xffffffffU ;
}
static unsigned long F_3 ( struct V_9 * V_10 , unsigned long V_11 )
{
if ( F_4 ( V_10 -> V_12 ) )
V_11 &= ~ ( ( 0xE << V_13 ) | V_14 ) ;
return V_11 ;
}
static int F_5 ( struct V_1 * V_2 )
{
T_2 V_15 , V_16 ;
struct V_17 * V_18 = F_6 ( V_2 -> V_19 -> V_20 ) ;
F_7 ( V_18 , 0x5B , & V_15 ) ;
F_8 ( V_18 , 0x5B , V_15 & ~ 0x01 ) ;
F_9 ( 10 ) ;
F_7 ( V_18 , 0x5A , & V_16 ) ;
F_8 ( V_18 , 0x5B , V_15 ) ;
if ( V_16 & ( 2 >> V_2 -> V_21 ) )
return V_22 ;
else
return V_23 ;
}
static int F_10 ( struct V_24 * V_25 , unsigned long V_26 )
{
struct V_1 * V_2 = V_25 -> V_2 ;
struct V_17 * V_18 = F_6 ( V_2 -> V_19 -> V_20 ) ;
F_8 ( V_18 , 0x50 + 4 * V_2 -> V_21 , 0x37 ) ;
F_9 ( 100 ) ;
return F_11 ( V_25 , V_26 ) ;
}
static void F_12 ( struct V_1 * V_2 , struct V_9 * V_10 ,
T_2 V_27 )
{
struct V_17 * V_18 = F_6 ( V_2 -> V_19 -> V_20 ) ;
T_1 V_28 , V_29 ;
T_1 V_30 , V_8 , V_11 ;
T_2 V_31 ;
V_28 = 0x40 + 4 * ( V_10 -> V_32 + 2 * V_2 -> V_21 ) ;
V_29 = 0x51 + 4 * V_2 -> V_21 ;
F_7 ( V_18 , V_29 , & V_31 ) ;
V_31 &= ~ 0x07 ;
F_8 ( V_18 , V_29 , V_31 ) ;
if ( V_27 < V_33 )
V_11 = 0xcfc3ffff ;
else if ( V_27 < V_34 )
V_11 = 0x31c001ff ;
else
V_11 = 0x303c0000 ;
V_8 = F_1 ( V_2 , V_27 ) ;
F_13 ( V_18 , V_28 , & V_30 ) ;
V_30 = ( V_30 & ~ V_11 ) | ( V_8 & V_11 ) ;
F_14 ( V_18 , V_28 , V_30 ) ;
}
static void F_15 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
F_12 ( V_2 , V_10 , V_10 -> V_35 ) ;
}
static void F_16 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
F_12 ( V_2 , V_10 , V_10 -> V_36 ) ;
}
static void F_17 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_2 ;
struct V_17 * V_18 = F_6 ( V_2 -> V_19 -> V_20 ) ;
int V_39 = 0x50 + 2 * V_2 -> V_21 ;
T_2 V_40 , V_41 ;
F_7 ( V_18 , 0x6A , & V_40 ) ;
F_7 ( V_18 , V_39 , & V_41 ) ;
if ( V_40 & ( 1 << V_2 -> V_21 ) )
F_8 ( V_18 , V_39 , V_41 | 0x30 ) ;
F_18 ( V_38 ) ;
}
static void F_19 ( struct V_1 * V_2 , int V_42 )
{
void T_3 * V_43 = V_2 -> V_44 . V_45 - V_2 -> V_21 * 8 ;
F_20 ( 0x80 , V_43 + 0x73 ) ;
F_20 ( 0x80 , V_43 + 0x77 ) ;
F_20 ( V_42 , V_43 + 0x7B ) ;
F_20 ( 0xC0 , V_43 + 0x79 ) ;
F_20 ( F_21 ( V_43 + 0x70 ) | 0x32 , V_43 + 0x70 ) ;
F_20 ( F_21 ( V_43 + 0x74 ) | 0x32 , V_43 + 0x74 ) ;
F_20 ( 0x00 , V_43 + 0x79 ) ;
F_20 ( 0x00 , V_43 + 0x73 ) ;
F_20 ( 0x00 , V_43 + 0x77 ) ;
}
static int F_22 ( struct V_1 * V_2 , int V_46 )
{
long V_47 = ( long ) V_2 -> V_19 -> V_48 ;
if ( V_46 )
return V_49 ;
if ( V_47 & V_50 )
return V_49 ;
return 0 ;
}
static int F_23 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_2 ;
struct V_1 * V_51 = V_2 -> V_19 -> V_52 [ V_2 -> V_21 ^ 1 ] ;
int V_53 , V_47 = ( long ) V_2 -> V_19 -> V_48 ;
int V_54 = F_22 ( V_2 , V_38 -> V_55 . V_47 & V_56 ) ;
V_53 = F_24 ( V_38 ) ;
if ( V_53 != 0 )
return V_53 ;
if ( ( V_47 & V_49 ) != V_54 && V_51 -> V_57 )
return V_58 ;
return 0 ;
}
static unsigned int F_25 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_2 ;
int V_47 = ( long ) V_2 -> V_19 -> V_48 ;
int V_54 = F_22 ( V_2 , V_38 -> V_55 . V_47 & V_56 ) ;
if ( ( V_47 & V_49 ) != V_54 ) {
V_47 &= ~ V_49 ;
V_47 |= V_54 ;
V_2 -> V_19 -> V_48 = ( void * ) ( long ) V_47 ;
F_19 ( V_2 , V_54 ? 0x21 : 0x23 ) ;
}
return F_26 ( V_38 ) ;
}
static int F_27 ( struct V_17 * V_20 )
{
T_2 V_59 ;
T_1 V_60 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < 0x5000 ; V_61 ++ ) {
F_9 ( 50 ) ;
F_7 ( V_20 , 0x5b , & V_59 ) ;
if ( V_59 & 0x80 ) {
for ( V_61 = 0 ; V_61 < 0x1000 ; V_61 ++ ) {
F_7 ( V_20 , 0x5b , & V_59 ) ;
if ( ( V_59 & 0x80 ) == 0 )
return 0 ;
}
F_13 ( V_20 , 0x5c , & V_60 ) ;
F_14 ( V_20 , 0x5c , V_60 & ~ 0x100 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_28 ( struct V_17 * V_18 )
{
unsigned long V_62 ;
T_1 V_63 ;
unsigned long V_64 = F_29 ( V_18 , 4 ) ;
V_63 = F_30 ( V_64 + 0x90 ) ;
if ( ( V_63 >> 12 ) != 0xABCDE ) {
int V_65 ;
T_4 V_66 ;
T_1 V_67 = 0 ;
F_31 ( L_1 ) ;
for ( V_65 = 0 ; V_65 < 128 ; V_65 ++ ) {
F_32 ( V_18 , 0x78 , & V_66 ) ;
V_67 += V_66 & 0x1FF ;
F_9 ( 15 ) ;
}
V_63 = V_67 / 128 ;
}
V_63 &= 0x1FF ;
V_62 = ( V_63 * 77 ) / 192 ;
if ( V_62 < 40 )
return 33 ;
if ( V_62 < 45 )
return 40 ;
if ( V_62 < 55 )
return 50 ;
return 66 ;
}
static int F_33 ( struct V_17 * V_20 , const struct V_68 * V_12 )
{
static const struct V_69 V_70 = {
. V_47 = V_71 ,
. V_72 = V_73 ,
. V_74 = V_75 ,
. V_76 = V_77 ,
. V_78 = & V_79
} ;
static const struct V_69 V_80 = {
. V_47 = V_71 ,
. V_72 = V_73 ,
. V_74 = V_75 ,
. V_76 = V_77 ,
. V_78 = & V_81
} ;
const struct V_69 * V_82 [] = { & V_80 , NULL } ;
T_2 V_83 = V_20 -> V_84 ;
T_2 V_85 ;
unsigned int V_86 ;
unsigned int V_87 , V_88 ;
int V_89 ;
unsigned long V_64 = F_29 ( V_20 , 4 ) ;
void * V_90 = ( void * ) V_49 ;
int V_53 ;
V_53 = F_34 ( V_20 ) ;
if ( V_53 )
return V_53 ;
switch ( V_20 -> V_91 ) {
case V_92 :
if ( V_83 < 6 )
return - V_93 ;
goto V_94;
case V_95 :
if ( V_83 < 2 )
return - V_93 ;
break;
case V_96 :
if ( V_83 < 2 )
return - V_93 ;
goto V_94;
case V_97 :
if ( V_83 < 2 )
return - V_93 ;
break;
case V_98 :
V_94:
V_82 [ 0 ] = & V_70 ;
break;
default:
F_35 ( L_2 , V_20 -> V_91 ) ;
return - V_93 ;
}
F_8 ( V_20 , V_99 , ( V_100 / 4 ) ) ;
F_8 ( V_20 , V_101 , 0x78 ) ;
F_8 ( V_20 , V_102 , 0x08 ) ;
F_8 ( V_20 , V_103 , 0x08 ) ;
F_7 ( V_20 , 0x5A , & V_85 ) ;
V_85 &= ~ 0x10 ;
F_8 ( V_20 , 0x5a , V_85 ) ;
if ( V_20 -> V_91 == V_95 ) {
T_2 V_104 ;
F_7 ( V_20 , 0x50 , & V_104 ) ;
V_104 &= ~ 0x04 ;
F_8 ( V_20 , 0x50 , V_104 ) ;
}
V_86 = F_28 ( V_20 ) ;
V_87 = ( V_86 * 48 ) / 66 ;
V_88 = V_87 + 2 ;
F_14 ( V_20 , 0x5C , ( V_88 << 16 ) | V_87 | 0x100 ) ;
F_8 ( V_20 , 0x5B , 0x21 ) ;
for ( V_89 = 0 ; V_89 < 8 ; V_89 ++ ) {
if ( F_27 ( V_20 ) )
break;
F_14 ( V_20 , 0x5C , ( V_88 << 16 ) | V_87 ) ;
}
if ( V_89 == 8 ) {
F_35 ( L_3 ) ;
return - V_93 ;
}
F_36 ( L_4 , V_86 ) ;
if ( V_86 > 60 )
V_90 = ( void * ) ( V_50 | V_49 ) ;
if ( V_20 -> V_91 == V_95 )
F_37 ( F_38 ( V_64 + 0x9c ) | 0x04 , V_64 + 0x9c ) ;
return F_39 ( V_20 , V_82 , & V_105 , V_90 , 0 ) ;
}
