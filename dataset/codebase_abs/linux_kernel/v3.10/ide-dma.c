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
F_5 ( V_1 , 0 ,
F_6 ( V_4 -> V_17 ) << 9 ) ;
return V_18 ;
}
F_7 ( V_19 L_1 ,
V_1 -> V_20 , V_21 , V_6 ) ;
}
return F_8 ( V_1 , L_2 , V_5 ) ;
}
int F_9 ( T_2 * V_1 )
{
return F_10 ( V_1 -> V_22 , V_23 ) ;
}
static int F_11 ( T_2 * V_1 , struct V_3 * V_4 )
{
T_3 * V_2 = V_1 -> V_2 ;
struct V_24 * V_25 = V_2 -> V_26 ;
int V_27 ;
if ( V_4 -> V_15 & V_28 )
V_4 -> V_29 = V_30 ;
else
V_4 -> V_29 = V_31 ;
V_27 = F_12 ( V_2 -> V_32 , V_25 , V_4 -> V_33 , V_4 -> V_29 ) ;
if ( V_27 ) {
V_4 -> V_34 = V_4 -> V_33 ;
V_4 -> V_33 = V_27 ;
}
return V_27 ;
}
void F_2 ( T_2 * V_1 , struct V_3 * V_4 )
{
T_3 * V_2 = V_1 -> V_2 ;
F_13 ( V_2 -> V_32 , V_2 -> V_26 , V_4 -> V_34 ,
V_4 -> V_29 ) ;
}
void F_14 ( T_2 * V_1 )
{
V_1 -> V_35 &= ~ V_36 ;
F_15 ( V_1 , 0 ) ;
V_1 -> V_2 -> V_8 -> V_37 ( V_1 , 0 ) ;
}
void F_16 ( T_2 * V_1 )
{
F_7 ( V_38 L_3 , V_1 -> V_20 ) ;
F_14 ( V_1 ) ;
}
void F_17 ( T_2 * V_1 )
{
V_1 -> V_35 |= V_36 ;
F_15 ( V_1 , 1 ) ;
V_1 -> V_2 -> V_8 -> V_37 ( V_1 , 1 ) ;
}
int F_18 ( T_2 * V_1 )
{
T_5 * V_22 = V_1 -> V_22 ;
int V_39 = F_10 ( V_22 , V_40 ) ;
if ( V_39 ) {
F_7 ( V_41 L_4 ,
V_1 -> V_20 , ( char * ) & V_22 [ V_42 ] ) ;
return V_39 ;
}
return 0 ;
}
static unsigned int F_19 ( T_2 * V_1 , T_4 V_43 , T_4 V_44 )
{
T_5 * V_22 = V_1 -> V_22 ;
T_3 * V_2 = V_1 -> V_2 ;
const struct V_45 * V_46 = V_2 -> V_46 ;
unsigned int V_47 = 0 ;
switch ( V_43 ) {
case V_48 :
if ( ( V_22 [ V_49 ] & 4 ) == 0 )
break;
V_47 = V_22 [ V_50 ] ;
if ( V_46 && V_46 -> V_51 )
V_47 &= V_46 -> V_51 ( V_1 ) ;
else
V_47 &= V_2 -> V_52 ;
if ( V_44 > V_53 ) {
if ( ( V_47 & 0x78 ) && ( F_20 ( V_1 ) == 0 ) )
V_47 &= 0x07 ;
}
break;
case V_54 :
V_47 = V_22 [ V_55 ] ;
if ( F_21 ( V_22 ) && ( V_22 [ V_56 ] & 0x38 ) ) {
T_4 V_57 = ( ( V_22 [ V_56 ] & 0x38 ) >> 3 ) - 1 ;
V_47 |= ( ( 2 << V_57 ) - 1 ) << 3 ;
}
if ( V_46 && V_46 -> V_58 )
V_47 &= V_46 -> V_58 ( V_1 ) ;
else
V_47 &= V_2 -> V_59 ;
break;
case V_60 :
V_47 = V_22 [ V_61 ] ;
if ( ! ( V_47 & V_62 ) && ( V_22 [ V_63 ] >> 8 ) ) {
T_4 V_57 = V_22 [ V_63 ] >> 8 ;
if ( V_57 <= 2 )
V_47 = ( 2 << V_57 ) - 1 ;
}
V_47 &= V_2 -> V_64 ;
break;
default:
F_22 () ;
break;
}
return V_47 ;
}
T_4 F_23 ( T_2 * V_1 , T_4 V_44 )
{
T_3 * V_2 = V_1 -> V_2 ;
unsigned int V_47 ;
int V_65 , V_27 ;
T_4 V_57 = 0 ;
if ( V_1 -> V_66 != V_67 ) {
if ( V_2 -> V_68 & V_69 )
return 0 ;
}
for ( V_27 = 0 ; V_27 < F_24 ( V_70 ) ; V_27 ++ ) {
if ( V_44 < V_70 [ V_27 ] )
continue;
V_47 = F_19 ( V_1 , V_70 [ V_27 ] , V_44 ) ;
V_65 = F_25 ( V_47 ) - 1 ;
if ( V_65 >= 0 ) {
V_57 = V_70 [ V_27 ] + V_65 ;
break;
}
}
if ( V_2 -> V_71 == V_72 && V_57 == 0 ) {
if ( F_9 ( V_1 ) &&
V_1 -> V_22 [ V_73 ] < 150 )
V_57 = V_74 ;
}
V_57 = F_26 ( V_57 , V_44 ) ;
F_7 ( V_38 L_5 , V_1 -> V_20 ,
V_57 ? F_27 ( V_57 ) : L_6 ) ;
return V_57 ;
}
static int F_28 ( T_2 * V_1 )
{
T_3 * V_2 = V_1 -> V_2 ;
T_4 V_75 ;
if ( F_29 ( V_1 -> V_22 ) == 0 ||
( V_1 -> V_35 & V_76 ) )
return 0 ;
if ( F_18 ( V_1 ) )
return 0 ;
if ( V_2 -> V_68 & V_77 )
return F_30 ( V_1 ) ;
V_75 = F_31 ( V_1 ) ;
if ( ! V_75 )
return 0 ;
if ( F_32 ( V_1 , V_75 ) )
return 0 ;
return 1 ;
}
static int F_33 ( T_2 * V_1 )
{
T_3 * V_2 = V_1 -> V_2 ;
if ( F_28 ( V_1 ) )
return 0 ;
if ( V_2 -> V_68 & V_77 )
return - 1 ;
F_34 ( V_1 ) ;
return - 1 ;
}
int F_35 ( T_2 * V_1 )
{
int V_78 ;
F_14 ( V_1 ) ;
V_78 = F_33 ( V_1 ) ;
if ( V_78 )
return V_78 ;
F_17 ( V_1 ) ;
return 0 ;
}
void F_36 ( T_2 * V_1 )
{
T_4 V_57 ;
F_14 ( V_1 ) ;
V_1 -> V_79 = 0 ;
V_57 = V_1 -> V_80 ;
if ( V_57 > V_48 && V_57 <= V_81 )
V_57 -- ;
else
V_57 = V_82 ;
F_37 ( V_1 , V_57 ) ;
if ( V_1 -> V_80 >= V_60 )
F_17 ( V_1 ) ;
}
void F_38 ( T_2 * V_1 )
{
F_7 ( V_19 L_7 , V_1 -> V_20 ) ;
}
T_1 F_39 ( T_2 * V_1 , int error )
{
T_3 * V_2 = V_1 -> V_2 ;
const struct V_83 * V_8 = V_2 -> V_8 ;
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_84 = V_18 ;
if ( error < 0 ) {
F_7 ( V_41 L_8 , V_1 -> V_20 ) ;
V_1 -> V_7 = 0 ;
( void ) V_8 -> V_9 ( V_1 ) ;
F_2 ( V_1 , V_4 ) ;
V_84 = F_8 ( V_1 , L_9 ,
V_2 -> V_10 -> V_11 ( V_2 ) ) ;
} else {
F_7 ( V_41 L_10 , V_1 -> V_20 ) ;
if ( V_8 -> V_85 )
V_8 -> V_85 ( V_1 ) ;
F_7 ( V_19 L_11 , V_1 -> V_20 ) ;
if ( V_8 -> V_86 ( V_1 ) == 0 ) {
F_40 ( V_1 , L_12 ,
V_2 -> V_10 -> V_11 ( V_2 ) ) ;
V_1 -> V_7 = 0 ;
( void ) V_8 -> V_9 ( V_1 ) ;
F_2 ( V_1 , V_4 ) ;
}
}
V_1 -> V_35 |= V_87 ;
V_1 -> V_88 ++ ;
F_14 ( V_1 ) ;
if ( V_2 -> V_17 )
V_2 -> V_17 -> V_89 = 0 ;
return V_84 ;
}
void F_41 ( T_3 * V_2 )
{
if ( V_2 -> V_90 ) {
int V_91 = V_2 -> V_92 * V_2 -> V_93 ;
F_42 ( V_2 -> V_32 , V_91 ,
V_2 -> V_90 , V_2 -> V_94 ) ;
V_2 -> V_90 = NULL ;
}
}
int F_43 ( T_3 * V_2 )
{
int V_91 ;
if ( V_2 -> V_92 == 0 )
V_2 -> V_92 = V_95 ;
if ( V_2 -> V_93 == 0 )
V_2 -> V_93 = V_96 ;
V_91 = V_2 -> V_92 * V_2 -> V_93 ;
V_2 -> V_90 = F_44 ( V_2 -> V_32 , V_91 ,
& V_2 -> V_94 ,
V_97 ) ;
if ( V_2 -> V_90 == NULL ) {
F_7 ( V_19 L_13 ,
V_2 -> V_20 ) ;
return - V_98 ;
}
return 0 ;
}
int F_45 ( T_2 * V_1 , struct V_3 * V_4 )
{
const struct V_83 * V_8 = V_1 -> V_2 -> V_8 ;
if ( ( V_1 -> V_35 & V_36 ) == 0 ||
( V_8 -> V_99 && V_8 -> V_99 ( V_1 , V_4 ) ) )
goto V_100;
F_46 ( V_1 , V_4 ) ;
if ( F_11 ( V_1 , V_4 ) == 0 )
goto V_101;
if ( V_8 -> V_102 ( V_1 , V_4 ) )
goto V_103;
V_1 -> V_7 = 1 ;
return 0 ;
V_103:
F_2 ( V_1 , V_4 ) ;
V_101:
F_46 ( V_1 , V_4 ) ;
V_100:
return 1 ;
}
