static void F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( F_2 ( V_2 ) ) {
if ( ( V_2 -> V_4 -> V_5 == 1 ) && ( V_3 != V_6 ) )
return;
}
V_2 -> V_7 . V_8 &= ~ V_9 ;
V_2 -> V_7 . V_8 |= ( V_3 << V_10 ) ;
if ( V_2 -> V_11 -> V_12 ) {
F_3 ( V_2 ) ;
F_4 ( V_2 , true ) ;
}
}
void F_5 ( struct V_1 * V_2 )
{
T_1 * V_13 = V_2 -> V_14 -> V_13 ;
T_2 V_15 , V_16 ;
V_15 = F_6 ( V_13 ) ;
V_16 = V_15 & 0xf ;
if ( V_2 -> V_4 -> V_16 == V_2 -> V_4 -> V_17 ) {
if ( V_16 && ( V_16 < V_2 -> V_4 -> V_17 ) ) {
F_7 ( V_2 , V_16 , true ) ;
}
} else if ( V_2 -> V_4 -> V_16 < V_2 -> V_4 -> V_17 ) {
if ( V_16 == V_2 -> V_4 -> V_17 ) {
F_7 ( V_2 , V_16 , true ) ;
}
}
}
void
F_8 ( struct V_1 * V_2 , T_3 * V_18 ,
T_4 V_19 )
{
T_5 V_20 ;
T_6 V_21 , V_22 , V_23 ;
* V_18 = 0 ;
if ( ! V_2 -> V_11 -> V_12 ) {
* V_18 = ( T_3 ) - 1 ;
return;
}
F_9 ( V_2 -> V_14 -> V_13 , & V_20 ,
F_10 ( V_19 ) ) ;
V_21 = ( F_11 ( V_19 ) ) ?
V_24 : V_25 ;
V_22 = ( F_11 ( V_19 ) ) ?
V_26 : V_27 ;
V_23 = ( F_11 ( V_19 ) ) ?
V_28 : V_29 ;
if ( V_20 . V_30 [ V_21 ] > ( V_20 . V_30 [ V_22 ] + 12 ) )
F_12 ( V_18 , V_31 ) ;
else
F_12 ( V_18 , V_32 ) ;
if ( V_20 . V_30 [ V_21 ] <= ( V_20 . V_30 [ V_23 ] + 12 ) )
F_12 ( V_18 , V_33 ) ;
}
static bool F_13 ( struct V_1 * V_2 , T_7 V_34 )
{
if ( ( V_34 != AUTO ) && ( V_34 != V_35 ) && ( V_34 != V_36 ) ) {
return false ;
}
if ( ( V_34 == V_36 ) && ( V_2 -> V_4 -> V_37 == 1 ) )
return false ;
if ( ( V_34 == V_35 ) || ( V_2 -> V_4 -> V_37 == 1 )
|| ! F_14 ( V_2 ) )
V_2 -> V_7 . V_8 &= ~ V_38 ;
else
V_2 -> V_7 . V_8 |= V_38 ;
V_2 -> V_39 [ V_40 ] -> V_41 = ( V_42 ) V_34 ;
V_2 -> V_39 [ V_43 ] -> V_41 = ( V_42 ) V_34 ;
return true ;
}
bool F_15 ( struct V_1 * V_2 , T_7 V_34 )
{
if ( ( V_34 != V_6 )
&& ( V_34 != V_44 ) ) {
return false ;
}
if ( F_2 ( V_2 ) ) {
if ( ( V_34 != V_6 )
&& ( V_2 -> V_4 -> V_5 == 1 ) )
return false ;
}
F_1 ( V_2 , V_34 ) ;
return true ;
}
static int F_16 ( struct V_1 * V_2 , T_6 V_45 , T_6 V_46 )
{
F_17 ( V_2 -> V_47 , L_1 ,
V_2 -> V_11 -> V_48 , V_45 , V_46 ) ;
if ( F_18 ( V_46 ) > V_2 -> V_4 -> V_37 ) {
V_46 = 0 ;
}
if ( ( F_18 ( V_46 ) == V_2 -> V_4 -> V_37 ) &&
( ( V_46 & ~ V_2 -> V_4 -> V_16 )
|| ! ( V_46 & V_2 -> V_4 -> V_16 ) ) ) {
V_46 = V_2 -> V_4 -> V_16 ;
}
V_2 -> V_4 -> V_49 [ V_45 ] = V_46 ;
if ( V_45 == 1 ) {
V_2 -> V_4 -> V_50 = V_46 << V_51 ;
F_19 ( V_2 -> V_52 , V_2 -> V_4 -> V_50 ) ;
if ( V_2 -> V_53 ) {
F_20 ( V_2 ) ;
F_21 ( V_2 , V_2 -> V_54 ) ;
F_22 ( V_2 ) ;
}
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , int V_3 )
{
int V_55 ;
T_6 V_46 = 0 ;
F_17 ( V_2 -> V_47 , L_2 , V_2 -> V_11 -> V_48 , V_3 ) ;
V_2 -> V_4 -> V_56 = ( V_42 ) V_3 ;
for ( V_55 = 1 ; V_55 <= V_57 ; V_55 ++ ) {
V_46 = ( V_3 == V_58 ) ?
V_2 -> V_4 -> V_16 : V_59 [ V_55 ] ;
F_16 ( V_2 , ( T_6 ) V_55 , V_46 ) ;
}
return 0 ;
}
int F_7 ( struct V_1 * V_2 , T_7 V_34 , bool V_60 )
{
T_6 V_16 = ( T_6 ) V_34 ;
T_6 V_37 ;
T_2 V_55 ;
if ( V_2 -> V_4 -> V_16 == V_16 )
return 0 ;
if ( ( V_16 & ~ V_2 -> V_4 -> V_17 )
|| ! ( V_16 & V_2 -> V_4 -> V_17 ) )
return - V_61 ;
V_37 = ( T_6 ) F_18 ( V_16 ) ;
if ( V_37 > V_57 )
return - V_61 ;
if ( V_37 == 1 ) {
for ( V_55 = 0 ; V_55 < F_24 ( V_2 ) ; V_55 ++ )
if ( ( F_25 ( V_2 -> V_39 [ V_55 ] -> V_62 ) !=
V_31 )
|| ( F_25 ( V_2 -> V_39 [ V_55 ] -> V_63 ) !=
V_31 ) ) {
if ( ! V_60 )
return - V_64 ;
if ( F_25 ( V_2 -> V_39 [ V_55 ] -> V_62 )
!= V_31 ) {
V_2 -> V_39 [ V_55 ] -> V_62 = 0 ;
F_26 ( V_2 -> V_47 , L_3
L_4
L_5 ,
V_65 ) ;
}
if ( F_25
( V_2 -> V_39 [ V_55 ] -> V_63 ) !=
V_31 ) {
V_2 -> V_39 [ V_55 ] -> V_63 = 0 ;
F_26 ( V_2 -> V_47 , L_3
L_4
L_6 ,
V_65 ) ;
}
}
}
V_2 -> V_4 -> V_16 = V_16 ;
V_2 -> V_4 -> V_37 = V_37 ;
F_13 ( V_2 , V_2 -> V_14 -> V_41 ) ;
F_27 ( V_2 , V_2 -> V_39 [ V_40 ] ) ;
F_27 ( V_2 , V_2 -> V_39 [ V_43 ] ) ;
V_2 -> V_4 -> V_66 =
( V_2 -> V_4 -> V_37 == 1 ) ? V_67 : V_68 ;
F_28 ( V_2 ) ;
F_29 ( V_2 -> V_14 -> V_13 , V_2 -> V_4 -> V_16 ,
V_2 -> V_4 -> V_69 ) ;
for ( V_55 = 1 ; V_55 <= V_57 ; V_55 ++ )
F_16 ( V_2 , ( T_6 ) V_55 , V_59 [ V_55 ] ) ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 , struct V_70 * V_14 )
{
int V_71 = 0 ;
T_6 V_72 ;
T_6 V_73 ;
V_72 = V_2 -> V_4 -> V_74 ;
if ( F_14 ( V_2 ) &&
V_2 -> V_4 -> V_75
&& ( V_2 -> V_4 -> V_18 != ( T_3 ) - 1 ) ) {
V_73 = ( V_2 -> V_4 -> V_76 || ( V_2 -> V_4 -> V_37 == 1 )
|| F_30 ( & V_2 -> V_4 -> V_18 ,
V_31 ) ) ? V_31
: V_32 ;
} else {
if ( V_2 -> V_14 != V_14 )
return V_71 ;
V_73 = ( V_2 -> V_4 -> V_76
|| ( V_2 -> V_4 -> V_37 ==
1 ) ) ? V_31 : V_14 ->
V_77 ;
}
if ( V_72 != V_73 ) {
V_2 -> V_4 -> V_74 = V_73 ;
F_31 ( V_2 -> V_52 , V_73 ) ;
}
return V_71 ;
}
int F_32 ( struct V_1 * V_2 )
{
V_2 -> V_39 [ V_40 ] -> V_77 = V_31 ;
V_2 -> V_39 [ V_43 ] -> V_77 = V_32 ;
if ( F_33 ( V_2 -> V_14 ) &&
( F_34 ( V_2 -> V_14 -> V_13 ) != V_78 ) )
V_2 -> V_39 [ V_40 ] -> V_77 =
V_32 ;
F_27 ( V_2 , V_2 -> V_39 [ V_40 ] ) ;
F_27 ( V_2 , V_2 -> V_39 [ V_43 ] ) ;
F_1 ( V_2 , V_6 ) ;
V_2 -> V_39 [ V_40 ] -> V_41 = V_35 ;
V_2 -> V_39 [ V_43 ] -> V_41 = V_35 ;
if ( F_14 ( V_2 ) ) {
V_2 -> V_4 -> V_75 = true ;
V_2 -> V_4 -> V_18 = ( T_3 ) - 1 ;
}
return 0 ;
}
void F_35 ( struct V_1 * V_2 )
{
}
int F_36 ( struct V_1 * V_2 , V_42 V_3 )
{
int V_79 = 0 ;
if ( F_33 ( V_2 -> V_14 ) && ( V_2 -> V_4 -> V_37 == 1 ) )
return ( ( V_3 == V_2 -> V_4 -> V_66 ) ? V_79 : - V_61 ) ;
switch ( V_3 ) {
case - 1 :
V_3 = V_68 ;
break;
case 0 :
V_3 = V_67 ;
break;
case 1 :
V_3 = V_80 ;
break;
case 3 :
V_3 = V_81 ;
break;
default:
V_79 = - V_61 ;
break;
}
if ( V_79 == 0 )
V_2 -> V_4 -> V_66 = ( V_42 ) V_3 ;
return V_79 ;
}
static void F_28 ( struct V_1 * V_2 )
{
V_42 V_66 ;
V_66 = ( V_42 ) V_2 -> V_4 -> V_66 ;
if ( F_37 ( V_2 -> V_14 ) ) {
if ( V_66 == V_67 ) {
V_2 -> V_4 -> V_50 = V_82 ;
} else if ( V_66 == V_80 ) {
V_2 -> V_4 -> V_50 = V_83 ;
if ( F_33 ( V_2 -> V_14 ) &&
F_38 ( V_2 -> V_14 -> V_84 , 3 )
&& F_39 ( V_2 -> V_14 -> V_84 , 7 ) ) {
V_2 -> V_4 -> V_50 = V_85 ;
}
} else {
if ( F_40 ( V_2 -> V_14 ) || F_41 ( V_2 -> V_14 ) )
V_2 -> V_4 -> V_50 = V_86 ;
else {
F_42 ( V_2 -> V_4 -> V_16 <= 0 ) ;
V_2 -> V_4 -> V_50 =
V_2 -> V_4 -> V_16 << V_51 ;
}
}
} else {
if ( V_66 == V_67 )
V_2 -> V_4 -> V_50 = V_87 ;
else if ( V_66 == V_80 )
V_2 -> V_4 -> V_50 = V_88 ;
else
V_2 -> V_4 -> V_50 = V_89 ;
}
F_19 ( V_2 -> V_52 , V_2 -> V_4 -> V_50 ) ;
}
void F_43 ( struct V_1 * V_2 )
{
F_28 ( V_2 ) ;
}
void F_44 ( struct V_1 * V_2 )
{
V_2 -> V_4 -> V_17 = ( T_6 ) F_45 ( V_2 -> V_11 -> V_90 , L_7 ) ;
V_2 -> V_4 -> V_91 = ( T_6 ) F_45 ( V_2 -> V_11 -> V_90 , L_8 ) ;
if ( V_2 -> V_4 -> V_17 == 0 || V_2 -> V_4 -> V_17 == 0xf ) {
if ( F_33 ( V_2 -> V_14 ) ) {
V_2 -> V_4 -> V_17 = V_92 ;
} else {
V_2 -> V_4 -> V_17 = V_93 ;
}
}
V_2 -> V_4 -> V_16 = V_2 -> V_4 -> V_17 ;
V_2 -> V_4 -> V_37 = ( T_6 ) F_18 ( V_2 -> V_4 -> V_17 ) ;
if ( V_2 -> V_4 -> V_91 == 0 || V_2 -> V_4 -> V_91 == 0xf ) {
if ( F_33 ( V_2 -> V_14 ) ) {
V_2 -> V_4 -> V_91 = V_94 ;
} else {
V_2 -> V_4 -> V_91 = V_95 ;
}
}
V_2 -> V_4 -> V_69 = V_2 -> V_4 -> V_91 ;
V_2 -> V_4 -> V_5 = ( T_6 ) F_18 ( V_2 -> V_4 -> V_91 ) ;
memcpy ( V_2 -> V_4 -> V_49 , V_59 , sizeof( V_2 -> V_4 -> V_49 ) ) ;
V_2 -> V_4 -> V_56 = V_96 ;
F_23 ( V_2 , V_96 ) ;
}
static T_3 F_46 ( struct V_1 * V_2 , T_8 V_97 )
{
T_3 V_50 = V_2 -> V_4 -> V_50 ;
if ( F_25 ( V_97 ) != V_31 ) {
V_50 = V_2 -> V_4 -> V_16 << V_51 ;
} else if ( V_2 -> V_4 -> V_66 == V_68 )
V_50 = V_2 -> V_4 -> V_16 << V_51 ;
V_50 &= V_98 ;
return V_50 ;
}
T_3 F_47 ( struct V_1 * V_2 , T_8 V_97 )
{
return F_46 ( V_2 , V_97 ) ;
}
T_3 F_48 ( struct V_1 * V_2 , T_8 V_97 )
{
T_3 V_50 = V_2 -> V_4 -> V_50 ;
T_3 V_99 = V_98 ;
if ( F_33 ( V_2 -> V_14 ) ) {
V_50 = F_46 ( V_2 , V_97 ) ;
V_99 = V_100 ;
}
V_50 |= V_50 & V_99 ;
return V_50 ;
}
