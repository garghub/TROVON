T_1 F_1 ( T_2 * V_1 )
{
T_3 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = & V_2 -> V_4 ;
T_4 V_5 = 0 , V_6 = 0 ;
V_1 -> V_7 = 0 ;
V_6 = V_2 -> V_8 -> V_9 ( V_1 ) ;
F_2 ( V_1 , V_4 ) ;
V_5 = V_2 -> V_10 -> V_11 ( V_2 ) ;
if ( F_3 ( V_5 , V_12 , V_1 -> V_13 | V_14 ) ) {
if ( ! V_6 ) {
if ( ( V_4 -> V_15 & V_16 ) == 0 )
F_4 ( V_1 , V_4 , V_5 ) ;
else
F_5 ( V_1 , V_17 ,
F_6 ( V_4 -> V_18 ) << 9 ) ;
return V_19 ;
}
F_7 ( V_20 L_1 ,
V_1 -> V_21 , V_22 , V_6 ) ;
}
return F_8 ( V_1 , L_2 , V_5 ) ;
}
int F_9 ( T_2 * V_1 )
{
return F_10 ( V_1 -> V_23 , V_24 ) ;
}
static int F_11 ( T_2 * V_1 , struct V_3 * V_4 )
{
T_3 * V_2 = V_1 -> V_2 ;
struct V_25 * V_26 = V_2 -> V_27 ;
int V_28 ;
if ( V_4 -> V_15 & V_29 )
V_4 -> V_30 = V_31 ;
else
V_4 -> V_30 = V_32 ;
V_28 = F_12 ( V_2 -> V_33 , V_26 , V_4 -> V_34 , V_4 -> V_30 ) ;
if ( V_28 ) {
V_4 -> V_35 = V_4 -> V_34 ;
V_4 -> V_34 = V_28 ;
}
return V_28 ;
}
void F_2 ( T_2 * V_1 , struct V_3 * V_4 )
{
T_3 * V_2 = V_1 -> V_2 ;
F_13 ( V_2 -> V_33 , V_2 -> V_27 , V_4 -> V_35 ,
V_4 -> V_30 ) ;
}
void F_14 ( T_2 * V_1 )
{
V_1 -> V_36 &= ~ V_37 ;
F_15 ( V_1 , 0 ) ;
V_1 -> V_2 -> V_8 -> V_38 ( V_1 , 0 ) ;
}
void F_16 ( T_2 * V_1 )
{
F_7 ( V_39 L_3 , V_1 -> V_21 ) ;
F_14 ( V_1 ) ;
}
void F_17 ( T_2 * V_1 )
{
V_1 -> V_36 |= V_37 ;
F_15 ( V_1 , 1 ) ;
V_1 -> V_2 -> V_8 -> V_38 ( V_1 , 1 ) ;
}
int F_18 ( T_2 * V_1 )
{
T_5 * V_23 = V_1 -> V_23 ;
int V_40 = F_10 ( V_23 , V_41 ) ;
if ( V_40 ) {
F_7 ( V_42 L_4 ,
V_1 -> V_21 , ( char * ) & V_23 [ V_43 ] ) ;
return V_40 ;
}
return 0 ;
}
static unsigned int F_19 ( T_2 * V_1 , T_4 V_44 , T_4 V_45 )
{
T_5 * V_23 = V_1 -> V_23 ;
T_3 * V_2 = V_1 -> V_2 ;
const struct V_46 * V_47 = V_2 -> V_47 ;
unsigned int V_48 = 0 ;
switch ( V_44 ) {
case V_49 :
if ( ( V_23 [ V_50 ] & 4 ) == 0 )
break;
V_48 = V_23 [ V_51 ] ;
if ( V_47 && V_47 -> V_52 )
V_48 &= V_47 -> V_52 ( V_1 ) ;
else
V_48 &= V_2 -> V_53 ;
if ( V_45 > V_54 ) {
if ( ( V_48 & 0x78 ) && ( F_20 ( V_1 ) == 0 ) )
V_48 &= 0x07 ;
}
break;
case V_55 :
V_48 = V_23 [ V_56 ] ;
if ( F_21 ( V_23 ) && ( V_23 [ V_57 ] & 0x38 ) ) {
T_4 V_58 = ( ( V_23 [ V_57 ] & 0x38 ) >> 3 ) - 1 ;
V_48 |= ( ( 2 << V_58 ) - 1 ) << 3 ;
}
if ( V_47 && V_47 -> V_59 )
V_48 &= V_47 -> V_59 ( V_1 ) ;
else
V_48 &= V_2 -> V_60 ;
break;
case V_61 :
V_48 = V_23 [ V_62 ] ;
if ( ! ( V_48 & V_63 ) && ( V_23 [ V_64 ] >> 8 ) ) {
T_4 V_58 = V_23 [ V_64 ] >> 8 ;
if ( V_58 <= 2 )
V_48 = ( 2 << V_58 ) - 1 ;
}
V_48 &= V_2 -> V_65 ;
break;
default:
F_22 () ;
break;
}
return V_48 ;
}
T_4 F_23 ( T_2 * V_1 , T_4 V_45 )
{
T_3 * V_2 = V_1 -> V_2 ;
unsigned int V_48 ;
int V_66 , V_28 ;
T_4 V_58 = 0 ;
if ( V_1 -> V_67 != V_68 ) {
if ( V_2 -> V_69 & V_70 )
return 0 ;
}
for ( V_28 = 0 ; V_28 < F_24 ( V_71 ) ; V_28 ++ ) {
if ( V_45 < V_71 [ V_28 ] )
continue;
V_48 = F_19 ( V_1 , V_71 [ V_28 ] , V_45 ) ;
V_66 = F_25 ( V_48 ) - 1 ;
if ( V_66 >= 0 ) {
V_58 = V_71 [ V_28 ] + V_66 ;
break;
}
}
if ( V_2 -> V_72 == V_73 && V_58 == 0 ) {
if ( F_9 ( V_1 ) &&
V_1 -> V_23 [ V_74 ] < 150 )
V_58 = V_75 ;
}
V_58 = F_26 ( V_58 , V_45 ) ;
F_7 ( V_39 L_5 , V_1 -> V_21 ,
V_58 ? F_27 ( V_58 ) : L_6 ) ;
return V_58 ;
}
static int F_28 ( T_2 * V_1 )
{
T_3 * V_2 = V_1 -> V_2 ;
T_4 V_76 ;
if ( F_29 ( V_1 -> V_23 ) == 0 ||
( V_1 -> V_36 & V_77 ) )
return 0 ;
if ( F_18 ( V_1 ) )
return 0 ;
if ( V_2 -> V_69 & V_78 )
return F_30 ( V_1 ) ;
V_76 = F_31 ( V_1 ) ;
if ( ! V_76 )
return 0 ;
if ( F_32 ( V_1 , V_76 ) )
return 0 ;
return 1 ;
}
static int F_33 ( T_2 * V_1 )
{
T_3 * V_2 = V_1 -> V_2 ;
if ( F_28 ( V_1 ) )
return 0 ;
if ( V_2 -> V_69 & V_78 )
return - 1 ;
F_34 ( V_1 ) ;
return - 1 ;
}
int F_35 ( T_2 * V_1 )
{
int V_79 ;
F_14 ( V_1 ) ;
V_79 = F_33 ( V_1 ) ;
if ( V_79 )
return V_79 ;
F_17 ( V_1 ) ;
return 0 ;
}
void F_36 ( T_2 * V_1 )
{
T_4 V_58 ;
F_14 ( V_1 ) ;
V_1 -> V_80 = 0 ;
V_58 = V_1 -> V_81 ;
if ( V_58 > V_49 && V_58 <= V_82 )
V_58 -- ;
else
V_58 = V_83 ;
F_37 ( V_1 , V_58 ) ;
if ( V_1 -> V_81 >= V_61 )
F_17 ( V_1 ) ;
}
void F_38 ( T_2 * V_1 )
{
F_7 ( V_20 L_7 , V_1 -> V_21 ) ;
}
T_1 F_39 ( T_2 * V_1 , int error )
{
T_3 * V_2 = V_1 -> V_2 ;
const struct V_84 * V_8 = V_2 -> V_8 ;
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_85 = V_19 ;
if ( error < 0 ) {
F_7 ( V_42 L_8 , V_1 -> V_21 ) ;
V_1 -> V_7 = 0 ;
( void ) V_8 -> V_9 ( V_1 ) ;
F_2 ( V_1 , V_4 ) ;
V_85 = F_8 ( V_1 , L_9 ,
V_2 -> V_10 -> V_11 ( V_2 ) ) ;
} else {
F_7 ( V_42 L_10 , V_1 -> V_21 ) ;
if ( V_8 -> V_86 )
V_8 -> V_86 ( V_1 ) ;
F_7 ( V_20 L_11 , V_1 -> V_21 ) ;
if ( V_8 -> V_87 ( V_1 ) == 0 ) {
F_40 ( V_1 , L_12 ,
V_2 -> V_10 -> V_11 ( V_2 ) ) ;
V_1 -> V_7 = 0 ;
( void ) V_8 -> V_9 ( V_1 ) ;
F_2 ( V_1 , V_4 ) ;
}
}
V_1 -> V_36 |= V_88 ;
V_1 -> V_89 ++ ;
F_14 ( V_1 ) ;
if ( V_2 -> V_18 )
F_41 ( V_2 -> V_18 ) -> V_90 = 0 ;
return V_85 ;
}
void F_42 ( T_3 * V_2 )
{
if ( V_2 -> V_91 ) {
int V_92 = V_2 -> V_93 * V_2 -> V_94 ;
F_43 ( V_2 -> V_33 , V_92 ,
V_2 -> V_91 , V_2 -> V_95 ) ;
V_2 -> V_91 = NULL ;
}
}
int F_44 ( T_3 * V_2 )
{
int V_92 ;
if ( V_2 -> V_93 == 0 )
V_2 -> V_93 = V_96 ;
if ( V_2 -> V_94 == 0 )
V_2 -> V_94 = V_97 ;
V_92 = V_2 -> V_93 * V_2 -> V_94 ;
V_2 -> V_91 = F_45 ( V_2 -> V_33 , V_92 ,
& V_2 -> V_95 ,
V_98 ) ;
if ( V_2 -> V_91 == NULL ) {
F_7 ( V_20 L_13 ,
V_2 -> V_21 ) ;
return - V_99 ;
}
return 0 ;
}
int F_46 ( T_2 * V_1 , struct V_3 * V_4 )
{
const struct V_84 * V_8 = V_1 -> V_2 -> V_8 ;
if ( ( V_1 -> V_36 & V_37 ) == 0 ||
( V_8 -> V_100 && V_8 -> V_100 ( V_1 , V_4 ) ) )
goto V_101;
F_47 ( V_1 , V_4 ) ;
if ( F_11 ( V_1 , V_4 ) == 0 )
goto V_102;
if ( V_8 -> V_103 ( V_1 , V_4 ) )
goto V_104;
V_1 -> V_7 = 1 ;
return 0 ;
V_104:
F_2 ( V_1 , V_4 ) ;
V_102:
F_47 ( V_1 , V_4 ) ;
V_101:
return 1 ;
}
