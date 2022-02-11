static T_1 F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = false ;
return 0 ;
}
static T_1 F_2 ( struct V_1 * V_2 )
{
T_1 V_4 = V_2 -> V_5 . V_6 . V_7 ( V_2 ) ;
V_2 -> V_5 . V_6 . V_8 ( V_2 , V_2 -> V_5 . V_9 ) ;
return V_4 ;
}
static T_1 F_3 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = & V_2 -> V_11 ;
T_2 V_12 = V_13 ;
T_1 V_14 = V_15 ;
T_2 V_16 [ V_17 ] ;
T_3 * V_9 = ( T_3 * ) ( & V_16 [ 1 ] ) ;
V_2 -> V_5 . V_6 . V_18 ( V_2 ) ;
V_2 -> V_19 = V_20 ;
F_4 ( V_2 , V_21 , V_22 ) ;
F_5 ( V_2 ) ;
while ( ! V_11 -> V_6 . V_23 ( V_2 ) && V_12 ) {
V_12 -- ;
F_6 ( 5 ) ;
}
if ( ! V_12 )
return V_24 ;
V_11 -> V_12 = V_25 ;
V_16 [ 0 ] = V_26 ;
V_11 -> V_6 . V_27 ( V_2 , V_16 , 1 ) ;
F_7 ( 10 ) ;
V_14 = V_11 -> V_6 . V_28 ( V_2 , V_16 , V_17 ) ;
if ( V_14 )
return V_14 ;
if ( V_16 [ 0 ] != ( V_26 | V_29 ) )
return V_15 ;
memcpy ( V_2 -> V_5 . V_30 , V_9 , V_31 ) ;
V_2 -> V_5 . V_32 = V_16 [ V_33 ] ;
return 0 ;
}
static T_1 F_8 ( struct V_1 * V_2 )
{
T_2 V_34 ;
T_2 V_35 ;
T_4 V_36 ;
V_2 -> V_3 = true ;
V_34 = V_2 -> V_5 . V_37 ;
for ( V_36 = 0 ; V_36 < V_34 ; V_36 ++ ) {
V_35 = F_9 ( V_2 , F_10 ( V_36 ) ) ;
if ( V_35 & V_38 ) {
V_35 &= ~ V_38 ;
F_4 ( V_2 , F_10 ( V_36 ) , V_35 ) ;
}
}
F_5 ( V_2 ) ;
F_4 ( V_2 , V_39 , V_40 ) ;
F_9 ( V_2 , V_41 ) ;
V_34 = V_2 -> V_5 . V_42 ;
for ( V_36 = 0 ; V_36 < V_34 ; V_36 ++ ) {
V_35 = F_9 ( V_2 , F_11 ( V_36 ) ) ;
if ( V_35 & V_43 ) {
V_35 &= ~ V_43 ;
F_4 ( V_2 , F_11 ( V_36 ) , V_35 ) ;
}
}
return 0 ;
}
static T_1 F_12 ( struct V_1 * V_2 , T_3 * V_44 )
{
T_2 V_45 = 0 ;
switch ( V_2 -> V_5 . V_32 ) {
case 0 :
V_45 = ( ( V_44 [ 4 ] >> 4 ) | ( ( ( T_4 ) V_44 [ 5 ] ) << 4 ) ) ;
break;
case 1 :
V_45 = ( ( V_44 [ 4 ] >> 3 ) | ( ( ( T_4 ) V_44 [ 5 ] ) << 5 ) ) ;
break;
case 2 :
V_45 = ( ( V_44 [ 4 ] >> 2 ) | ( ( ( T_4 ) V_44 [ 5 ] ) << 6 ) ) ;
break;
case 3 :
V_45 = ( ( V_44 [ 4 ] ) | ( ( ( T_4 ) V_44 [ 5 ] ) << 8 ) ) ;
break;
default:
break;
}
V_45 &= 0xFFF ;
return V_45 ;
}
static T_1 F_13 ( struct V_1 * V_2 , T_3 * V_46 )
{
memcpy ( V_46 , V_2 -> V_5 . V_30 , V_31 ) ;
return 0 ;
}
static T_1 F_14 ( struct V_1 * V_2 , T_2 V_47 , T_3 * V_9 )
{
struct V_10 * V_11 = & V_2 -> V_11 ;
T_2 V_16 [ 3 ] ;
T_3 * V_48 = ( T_3 * ) ( & V_16 [ 1 ] ) ;
T_1 V_14 ;
memset ( V_16 , 0 , sizeof( V_16 ) ) ;
V_16 [ 0 ] |= V_47 << V_49 ;
V_16 [ 0 ] |= V_50 ;
if ( V_9 )
memcpy ( V_48 , V_9 , 6 ) ;
V_14 = V_11 -> V_6 . V_27 ( V_2 , V_16 , 3 ) ;
if ( ! V_14 )
V_14 = V_11 -> V_6 . V_28 ( V_2 , V_16 , 3 ) ;
V_16 [ 0 ] &= ~ V_51 ;
if ( ! V_14 )
if ( V_16 [ 0 ] ==
( V_50 | V_52 ) )
V_14 = - V_53 ;
return V_14 ;
}
static T_1 F_15 ( struct V_1 * V_2 , T_2 V_47 , T_3 * V_9 ,
T_2 V_54 )
{
struct V_10 * V_11 = & V_2 -> V_11 ;
T_2 V_16 [ 3 ] ;
T_3 * V_48 = ( T_3 * ) ( & V_16 [ 1 ] ) ;
T_1 V_14 ;
memset ( V_16 , 0 , sizeof( V_16 ) ) ;
V_16 [ 0 ] = V_55 ;
memcpy ( V_48 , V_9 , 6 ) ;
V_14 = V_11 -> V_6 . V_27 ( V_2 , V_16 , 3 ) ;
if ( ! V_14 )
V_14 = V_11 -> V_6 . V_28 ( V_2 , V_16 , 3 ) ;
V_16 [ 0 ] &= ~ V_51 ;
if ( ! V_14 &&
( V_16 [ 0 ] == ( V_55 | V_52 ) ) )
F_13 ( V_2 , V_2 -> V_5 . V_9 ) ;
return V_14 ;
}
static void F_16 ( struct V_1 * V_2 ,
T_2 * V_56 , T_4 V_57 )
{
struct V_10 * V_11 = & V_2 -> V_11 ;
T_2 V_58 [ V_59 ] ;
T_1 V_60 = V_11 -> V_6 . V_27 ( V_2 , V_56 , V_57 ) ;
if ( ! V_60 )
V_11 -> V_6 . V_28 ( V_2 , V_58 , V_57 ) ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
struct V_61 * V_62 )
{
struct V_63 * V_64 ;
T_2 V_16 [ V_59 ] ;
T_4 * V_65 = ( T_4 * ) & V_16 [ 1 ] ;
T_2 V_66 , V_36 ;
V_66 = F_18 ( V_62 ) ;
if ( V_66 > 30 )
V_66 = 30 ;
V_16 [ 0 ] = V_67 ;
V_16 [ 0 ] |= V_66 << V_49 ;
V_36 = 0 ;
F_19 (ha, netdev) {
if ( V_36 == V_66 )
break;
if ( F_20 ( V_64 -> V_9 ) )
continue;
V_65 [ V_36 ++ ] = F_12 ( V_2 , V_64 -> V_9 ) ;
}
F_16 ( V_2 , V_16 , V_59 ) ;
return 0 ;
}
static T_1 F_21 ( struct V_1 * V_2 , T_2 V_68 , T_2 V_69 ,
bool V_70 )
{
struct V_10 * V_11 = & V_2 -> V_11 ;
T_2 V_16 [ 2 ] ;
T_1 V_71 ;
V_16 [ 0 ] = V_72 ;
V_16 [ 1 ] = V_68 ;
V_16 [ 0 ] |= V_70 << V_49 ;
V_71 = V_11 -> V_6 . V_27 ( V_2 , V_16 , 2 ) ;
if ( V_71 )
goto V_73;
V_71 = V_11 -> V_6 . V_28 ( V_2 , V_16 , 2 ) ;
if ( V_71 )
goto V_73;
V_16 [ 0 ] &= ~ V_51 ;
V_16 [ 0 ] &= ~ ( 0xFF << V_49 ) ;
if ( V_16 [ 0 ] != ( V_72 | V_29 ) )
V_71 = V_74 ;
V_73:
return V_71 ;
}
static T_1 F_22 ( struct V_1 * V_2 ,
T_5 V_75 , bool V_76 ,
bool V_77 )
{
return 0 ;
}
static T_1 F_23 ( struct V_1 * V_2 ,
T_5 * V_75 ,
bool * V_78 ,
bool V_77 )
{
struct V_10 * V_11 = & V_2 -> V_11 ;
struct V_79 * V_5 = & V_2 -> V_5 ;
T_1 V_14 = 0 ;
T_2 V_80 ;
T_2 V_81 = 0 ;
if ( ! V_11 -> V_6 . V_23 ( V_2 ) || ! V_11 -> V_12 )
V_5 -> V_82 = true ;
if ( ! V_5 -> V_82 )
goto V_83;
V_80 = F_9 ( V_2 , V_84 ) ;
if ( ! ( V_80 & V_85 ) )
goto V_83;
switch ( V_80 & V_86 ) {
case V_87 :
* V_75 = V_88 ;
break;
case V_89 :
* V_75 = V_90 ;
break;
case V_91 :
* V_75 = V_92 ;
break;
}
if ( V_11 -> V_6 . V_93 ( V_2 , & V_81 , 1 ) )
goto V_83;
if ( ! ( V_81 & V_51 ) ) {
if ( V_81 & V_52 )
V_14 = - 1 ;
goto V_83;
}
if ( ! V_11 -> V_12 ) {
V_14 = - 1 ;
goto V_83;
}
V_5 -> V_82 = false ;
V_83:
* V_78 = ! V_5 -> V_82 ;
return V_14 ;
}
void F_24 ( struct V_1 * V_2 , T_4 V_94 )
{
T_2 V_16 [ 2 ] ;
V_16 [ 0 ] = V_95 ;
V_16 [ 1 ] = V_94 ;
F_16 ( V_2 , V_16 , 2 ) ;
}
int F_25 ( struct V_1 * V_2 , int V_96 )
{
int V_71 ;
T_2 V_56 [ 3 ] ;
V_56 [ 0 ] = V_97 ;
V_56 [ 1 ] = V_96 ;
V_56 [ 2 ] = 0 ;
V_71 = V_2 -> V_11 . V_6 . V_27 ( V_2 , V_56 , 3 ) ;
if ( ! V_71 )
V_71 = V_2 -> V_11 . V_6 . V_28 ( V_2 , V_56 , 3 ) ;
if ( ! V_71 ) {
V_56 [ 0 ] &= ~ V_51 ;
if ( V_56 [ 0 ] == ( V_97 | V_29 ) ) {
V_2 -> V_19 = V_96 ;
return 0 ;
}
V_71 = V_74 ;
}
return V_71 ;
}
int F_26 ( struct V_1 * V_2 , unsigned int * V_98 ,
unsigned int * V_99 )
{
int V_71 ;
T_2 V_56 [ 5 ] ;
switch ( V_2 -> V_19 ) {
case V_100 :
break;
default:
return 0 ;
}
V_56 [ 0 ] = V_101 ;
V_56 [ 1 ] = V_56 [ 2 ] = V_56 [ 3 ] = V_56 [ 4 ] = 0 ;
V_71 = V_2 -> V_11 . V_6 . V_27 ( V_2 , V_56 , 5 ) ;
if ( ! V_71 )
V_71 = V_2 -> V_11 . V_6 . V_28 ( V_2 , V_56 , 5 ) ;
if ( ! V_71 ) {
V_56 [ 0 ] &= ~ V_51 ;
if ( V_56 [ 0 ] != ( V_101 | V_29 ) )
return V_102 ;
V_2 -> V_5 . V_42 = V_56 [ V_103 ] ;
if ( V_2 -> V_5 . V_42 == 0 ||
V_2 -> V_5 . V_42 > V_104 )
V_2 -> V_5 . V_42 = V_104 ;
V_2 -> V_5 . V_37 = V_56 [ V_105 ] ;
if ( V_2 -> V_5 . V_37 == 0 ||
V_2 -> V_5 . V_37 > V_106 )
V_2 -> V_5 . V_37 = V_106 ;
* V_98 = V_56 [ V_107 ] ;
if ( * V_98 > V_2 -> V_5 . V_37 )
* V_98 = 1 ;
* V_99 = V_56 [ V_108 ] ;
if ( * V_99 >= V_2 -> V_5 . V_42 )
* V_99 = 0 ;
}
return V_71 ;
}
