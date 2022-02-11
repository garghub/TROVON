static inline int F_1 ( T_1 V_1 , T_1 V_2 )
{
return F_2 ( V_3 , V_2 , V_1 ) ;
}
static inline int F_3 ( T_1 V_1 , T_1 * V_2 )
{
return F_4 ( V_3 , V_2 , V_1 , 2 ) ;
}
static int F_5 ( T_1 V_4 )
{
int V_5 ;
V_5 = F_6 ( V_4 , V_6 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_6 ( V_4 , V_7 ) ;
return V_5 ;
}
static void F_7 ( T_1 V_4 )
{
F_8 ( V_4 , V_6 ) ;
F_8 ( V_4 , V_7 ) ;
}
static T_2 F_9 ( int V_8 , void * V_9 )
{
struct V_10 * V_11 = F_10 ( V_9 ) ;
F_11 ( & V_11 -> V_12 ) ;
return V_13 ;
}
static int F_12 ( int V_14 )
{
return F_1 ( V_15 ,
V_16 ) ;
}
static int F_13 ( int V_14 )
{
int V_5 ;
V_5 = F_1 ( V_17 , V_14 ) ;
if ( V_5 )
return V_5 ;
return F_1 ( V_18 ,
V_16 ) ;
}
static T_1 F_14 ( int V_14 )
{
return V_19 + 2 * V_14 ;
}
static T_1 F_15 ( int V_14 )
{
return V_20 ;
}
static int F_16 ( const struct V_21 * V_22 ,
int V_14 , int V_23 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_23 ; V_24 ++ )
if ( V_22 [ V_24 ] . V_14 == V_14 )
break;
return V_24 ;
}
static int F_17 ( const struct V_25
* V_26 , int V_14 )
{
const struct V_21 * V_22 = V_26 -> V_22 ;
int V_24 ;
V_24 = F_16 ( V_22 , V_14 , V_26 -> V_27 ) ;
return V_26 -> V_22 [ V_24 ] . V_28 ;
}
static int F_18 ( struct V_10 * V_11 ,
int V_14 , int V_29 )
{
const struct V_21 * V_22 = V_11 -> V_26 -> V_22 ;
int V_30 ;
int V_24 ;
V_24 = F_16 ( V_22 , V_14 , V_11 -> V_26 -> V_27 ) ;
V_30 = ( ( V_29 * 1000 ) -
V_11 -> V_31 [ V_24 ] . V_32 ) /
V_11 -> V_31 [ V_24 ] . V_33 ;
return V_30 ;
}
static int F_19 ( struct V_10 * V_11 ,
int V_14 , int * V_34 )
{
T_1 V_1 = V_11 -> V_26 -> V_35 ( V_14 ) ;
T_3 V_2 ;
int V_29 ;
int V_5 ;
V_5 = F_3 ( V_1 , ( T_1 * ) & V_2 ) ;
if ( V_5 ) {
F_20 ( V_11 -> V_36 , L_1 , V_1 ) ;
return V_5 ;
}
V_29 = F_21 ( V_2 ) ;
F_20 ( V_11 -> V_36 , L_2 , V_29 ) ;
if ( F_17 ( V_11 -> V_26 , V_14 ) )
* V_34 = F_18 ( V_11 , V_14 , V_29 ) ;
else
* V_34 = V_29 ;
return V_5 ;
}
static int F_22 ( struct V_10 * V_11 ,
int V_14 , int * V_2 )
{
const struct V_21 * V_22 = V_11 -> V_26 -> V_22 ;
int V_30 ;
int V_37 ;
int V_24 ;
int V_5 ;
V_5 = F_19 ( V_11 , V_14 , & V_30 ) ;
if ( V_5 )
return V_5 ;
V_24 = F_16 ( V_22 , V_14 , V_11 -> V_26 -> V_27 ) ;
V_37 = V_30 *
V_11 -> V_31 [ V_24 ] . V_38 ;
V_37 /= 1000 ;
F_20 ( V_11 -> V_36 , L_3 , V_30 ) ;
F_20 ( V_11 -> V_36 , L_4 , V_37 ) ;
* V_2 = V_37 ;
return V_5 ;
}
static int F_23 ( struct V_39 * V_9 ,
const struct V_40 * V_41 ,
int * V_2 , int * V_42 , long V_4 )
{
struct V_10 * V_11 = F_10 ( V_9 ) ;
int V_5 ;
long V_43 ;
F_24 ( & V_11 -> V_44 ) ;
V_5 = V_11 -> V_26 -> V_45 ( V_41 -> V_14 ) ;
if ( V_5 ) {
F_25 ( V_11 -> V_36 , L_5 ) ;
goto V_46;
}
V_43 = F_26 (
& V_11 -> V_12 , F_27 ( 5000 ) ) ;
if ( V_43 == 0 ) {
V_5 = - V_47 ;
goto V_46;
} else if ( V_43 < 0 ) {
V_5 = - V_48 ;
goto V_46;
}
switch ( V_4 ) {
case V_49 :
V_5 = F_19 ( V_11 , V_41 -> V_14 , V_2 ) ;
V_5 = V_5 ? - V_50 : V_51 ;
break;
case V_52 :
V_5 = F_22 ( V_11 , V_41 -> V_14 , V_2 ) ;
V_5 = V_5 ? - V_50 : V_51 ;
break;
default:
break;
}
V_46:
F_28 ( & V_11 -> V_44 ) ;
return V_5 ;
}
static void F_29 ( struct V_10 * V_11 ,
int V_14 , int V_53 , int V_54 )
{
int V_55 , V_56 , V_38 , V_57 , V_58 , V_24 ;
const struct V_21 * V_22 = V_11 -> V_26 -> V_22 ;
V_24 = F_16 ( V_22 , V_14 , V_11 -> V_26 -> V_27 ) ;
V_38 = ( ( V_22 [ V_24 ] . V_59 - V_22 [ V_24 ] . V_60 ) * 1000 ) /
( V_22 [ V_24 ] . V_28 - V_22 [ V_24 ] . V_61 ) ;
V_57 = V_22 [ V_24 ] . V_61 ;
V_58 = V_22 [ V_24 ] . V_28 ;
V_56 = 1000 + ( ( ( V_54 - V_53 ) * 1000 ) / ( V_58 - V_57 ) ) ;
V_55 = ( V_53 * 1000 ) - ( V_56 - 1000 ) * V_57 ;
V_11 -> V_31 [ V_24 ] . V_38 = V_38 ;
V_11 -> V_31 [ V_24 ] . V_33 = V_56 ;
V_11 -> V_31 [ V_24 ] . V_32 = V_55 ;
F_20 ( V_11 -> V_36 , L_6 , V_14 , V_53 ) ;
F_20 ( V_11 -> V_36 , L_7 , V_14 , V_54 ) ;
F_20 ( V_11 -> V_36 , L_8 , V_14 , V_57 ) ;
F_20 ( V_11 -> V_36 , L_9 , V_14 , V_58 ) ;
F_20 ( V_11 -> V_36 , L_10 , V_14 , V_38 ) ;
F_20 ( V_11 -> V_36 , L_11 , V_14 , V_56 ) ;
F_20 ( V_11 -> V_36 , L_12 , V_14 , V_55 ) ;
}
static inline int F_30 ( T_4 V_62 )
{
T_5 V_63 = ( ( V_62 & 0x7f ) >> 1 ) | ( ( V_62 & 1 ) << 6 ) ;
return F_31 ( V_63 , 6 ) ;
}
static int F_32 ( struct V_10 * V_11 )
{
int V_5 ;
int V_64 ;
T_1 V_65 [ V_66 ] ;
T_4 V_53 , V_54 ;
V_5 = F_4 ( V_67 , V_65 ,
V_68 , V_66 ) ;
if ( V_5 < 0 ) {
F_25 ( V_11 -> V_36 , L_13 ) ;
return V_5 ;
}
for ( V_64 = 0 ; V_64 < V_69 ; V_64 ++ ) {
switch ( V_64 ) {
case 0 :
V_53 = V_65 [ 0 ] ;
V_54 = V_65 [ 1 ] ;
break;
case 1 :
case 3 :
case 4 :
case 5 :
case 6 :
V_53 = V_65 [ 4 ] ;
V_54 = V_65 [ 5 ] ;
break;
case 2 :
V_53 = V_65 [ 12 ] ;
V_54 = V_65 [ 13 ] ;
break;
case 7 :
V_53 = V_65 [ 6 ] ;
V_54 = V_65 [ 7 ] ;
break;
case 8 :
V_53 = V_65 [ 2 ] ;
V_54 = V_65 [ 3 ] ;
break;
case 9 :
V_53 = V_65 [ 8 ] ;
V_54 = V_65 [ 9 ] ;
break;
case 10 :
V_53 = V_65 [ 10 ] ;
V_54 = V_65 [ 11 ] ;
break;
case 14 :
V_53 = V_65 [ 14 ] ;
V_54 = V_65 [ 15 ] ;
break;
default:
continue;
}
V_53 = F_30 ( V_53 ) ;
V_54 = F_30 ( V_54 ) ;
F_29 ( V_11 , V_64 , V_53 , V_54 ) ;
}
return 0 ;
}
static int F_33 ( T_1 * V_65 , unsigned int V_70 ,
unsigned int V_71 , unsigned int V_72 , unsigned int V_73 ,
unsigned int V_74 )
{
int V_2 ;
V_2 = ( V_65 [ V_70 ] & V_72 ) << V_74 ;
V_2 |= ( V_65 [ V_71 ] & V_73 ) >> 1 ;
if ( V_65 [ V_71 ] & 0x01 )
V_2 = - V_2 ;
return V_2 ;
}
static int F_34 ( struct V_10 * V_11 )
{
int V_64 , V_53 = 0 , V_54 = 0 , V_63 ;
T_1 V_65 [ V_66 ] ;
int V_5 ;
V_5 = F_4 ( V_67 , V_65 ,
V_68 , V_66 ) ;
if ( V_5 < 0 ) {
F_25 ( V_11 -> V_36 , L_13 ) ;
return V_5 ;
}
for ( V_64 = 0 ; V_64 < V_75 ; V_64 ++ ) {
switch ( V_64 ) {
case 0 :
case 1 :
case 2 :
case 3 :
case 4 :
case 5 :
case 6 :
case 11 :
case 14 :
V_53 = F_33 ( V_65 , 2 , 0 , 0x1f ,
0x06 , 2 ) ;
V_54 = F_33 ( V_65 , 3 , 1 , 0x3f ,
0x06 , 2 ) ;
break;
case 8 :
V_63 = F_33 ( V_65 , 2 , 0 , 0x1f ,
0x06 , 2 ) ;
V_53 = V_63 + F_33 ( V_65 , 7 , 6 ,
0x18 , 0x1E , 1 ) ;
V_63 = F_33 ( V_65 , 3 , 1 , 0x3F ,
0x06 , 2 ) ;
V_54 = V_63 + F_33 ( V_65 , 9 , 7 ,
0x1F , 0x06 , 2 ) ;
break;
case 9 :
V_63 = F_33 ( V_65 , 2 , 0 , 0x1f ,
0x06 , 2 ) ;
V_53 = V_63 + F_33 ( V_65 , 13 , 11 ,
0x18 , 0x1E , 1 ) ;
V_63 = F_33 ( V_65 , 3 , 1 , 0x3f ,
0x06 , 2 ) ;
V_54 = V_63 + F_33 ( V_65 , 15 , 13 ,
0x1F , 0x06 , 1 ) ;
break;
case 10 :
V_53 = F_33 ( V_65 , 10 , 8 , 0x0f ,
0x0E , 3 ) ;
V_54 = F_33 ( V_65 , 14 , 12 , 0x0f ,
0x0E , 3 ) ;
break;
case 7 :
case 18 :
V_63 = F_33 ( V_65 , 2 , 0 , 0x1f ,
0x06 , 2 ) ;
V_53 = ( V_65 [ 4 ] & 0x7E ) >> 1 ;
if ( V_65 [ 4 ] & 0x01 )
V_53 = - V_53 ;
V_53 += V_63 ;
V_63 = F_33 ( V_65 , 3 , 1 , 0x3f ,
0x06 , 2 ) ;
V_54 = ( V_65 [ 5 ] & 0xFE ) >> 1 ;
if ( V_65 [ 5 ] & 0x01 )
V_54 = - V_54 ;
V_54 += V_63 ;
break;
default:
continue;
}
F_29 ( V_11 , V_64 , V_53 , V_54 ) ;
}
return 0 ;
}
static int F_35 ( struct V_76 * V_77 )
{
struct V_78 * V_36 = & V_77 -> V_36 ;
struct V_10 * V_11 ;
const struct V_25 * V_26 ;
const struct V_79 * V_80 ;
struct V_39 * V_9 ;
int V_8 ;
int V_5 ;
V_80 = F_36 ( V_81 , V_36 ) ;
if ( ! V_80 )
return - V_82 ;
V_26 = V_80 -> V_83 ;
V_9 = F_37 ( V_36 , sizeof( * V_11 ) ) ;
if ( ! V_9 )
return - V_84 ;
V_11 = F_10 ( V_9 ) ;
V_11 -> V_31 = F_38 ( V_36 ,
sizeof( * V_11 -> V_31 ) *
V_26 -> V_27 , V_85 ) ;
if ( ! V_11 -> V_31 )
return - V_84 ;
V_11 -> V_36 = V_36 ;
V_11 -> V_26 = V_26 ;
F_39 ( V_77 , V_9 ) ;
F_40 ( & V_11 -> V_44 ) ;
F_41 ( & V_11 -> V_12 ) ;
V_5 = V_26 -> V_86 ( V_11 ) ;
if ( V_5 < 0 ) {
F_25 ( & V_77 -> V_36 , L_14 ) ;
return V_5 ;
}
V_8 = F_42 ( V_77 , 0 ) ;
if ( V_8 < 0 ) {
F_25 ( & V_77 -> V_36 , L_15 ) ;
return V_8 ;
}
V_5 = F_43 ( V_36 , V_8 , NULL ,
F_9 ,
V_87 , L_16 , V_9 ) ;
V_5 = F_5 ( V_88 ) ;
if ( V_5 < 0 ) {
F_25 ( & V_77 -> V_36 , L_17 ) ;
return V_5 ;
}
V_5 = F_2 ( V_89 , V_90 ,
V_91 ) ;
if ( V_5 < 0 ) {
F_25 ( & V_77 -> V_36 , L_18 ) ;
return V_5 ;
}
V_9 -> V_92 = V_93 ;
V_9 -> V_36 . V_94 = V_36 ;
V_9 -> V_95 = & V_96 ;
V_9 -> V_97 = V_98 ;
V_9 -> V_99 = V_26 -> V_100 ;
V_9 -> V_101 = V_26 -> V_27 ;
return F_44 ( V_9 ) ;
}
static int F_45 ( struct V_76 * V_77 )
{
struct V_39 * V_9 = F_46 ( V_77 ) ;
F_7 ( V_88 ) ;
F_47 ( V_9 ) ;
return 0 ;
}
static int F_48 ( struct V_78 * V_77 )
{
int V_5 ;
V_5 = F_2 ( V_89 , V_102 ,
V_91 ) ;
if ( V_5 )
F_25 ( V_77 , L_19 , V_5 ) ;
return 0 ;
}
static int F_49 ( struct V_78 * V_77 )
{
int V_5 ;
V_5 = F_2 ( V_89 , V_90 ,
V_91 ) ;
if ( V_5 )
F_25 ( V_77 , L_20 , V_5 ) ;
return 0 ;
}
