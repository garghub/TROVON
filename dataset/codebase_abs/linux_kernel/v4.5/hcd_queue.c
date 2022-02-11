static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 , V_8 , V_9 ;
char * V_10 , * type ;
F_2 ( V_2 -> V_11 , L_1 , V_12 ) ;
V_4 -> V_13 = F_3 ( & V_6 -> V_14 ) ;
V_4 -> V_15 = F_4 ( & V_6 -> V_14 ) ? 1 : 0 ;
V_4 -> V_16 = V_17 ;
V_4 -> V_18 = F_5 ( & V_6 -> V_14 ) ;
F_6 ( & V_4 -> V_19 ) ;
F_6 ( & V_4 -> V_20 ) ;
V_7 = F_7 ( V_2 , V_6 -> V_21 ) ;
F_8 ( V_2 , V_6 -> V_21 , & V_8 , & V_9 ) ;
if ( ( V_7 == V_22 || V_7 == V_23 ) &&
V_8 != 0 && V_8 != 1 ) {
F_2 ( V_2 -> V_11 ,
L_2 ,
F_9 ( & V_6 -> V_14 ) , V_8 ,
V_9 ) ;
V_4 -> V_24 = 1 ;
}
if ( V_4 -> V_13 == V_25 ||
V_4 -> V_13 == V_26 ) {
T_1 V_27 , V_28 ;
int V_29 =
F_10 ( V_4 -> V_18 ) * F_11 ( V_4 -> V_18 ) ;
V_4 -> V_30 = F_12 ( F_13 ( V_4 -> V_24 ?
V_31 : V_7 , V_4 -> V_15 ,
V_4 -> V_13 == V_26 ,
V_29 ) ) ;
V_2 -> V_32 = F_14 ( V_2 ) ;
V_4 -> V_33 = F_15 ( V_2 -> V_32 ,
V_34 ) ;
V_4 -> V_35 = V_6 -> V_35 ;
#if 0
if (qh->ep_type == USB_ENDPOINT_XFER_INT)
qh->interval = 8;
#endif
V_27 = F_16 ( V_2 -> V_36 + V_37 ) ;
V_28 = ( V_27 & V_38 ) >> V_39 ;
if ( V_28 == V_40 &&
( V_7 == V_22 ||
V_7 == V_23 ) ) {
V_4 -> V_35 *= 8 ;
V_4 -> V_33 |= 0x7 ;
V_4 -> V_41 = V_4 -> V_33 ;
}
F_17 ( V_2 -> V_11 , L_3 , V_4 -> V_35 ) ;
}
F_2 ( V_2 -> V_11 , L_4 ) ;
F_2 ( V_2 -> V_11 , L_5 , V_4 ) ;
F_2 ( V_2 -> V_11 , L_6 ,
F_18 ( & V_6 -> V_14 ) ) ;
F_2 ( V_2 -> V_11 , L_7 ,
F_9 ( & V_6 -> V_14 ) ,
F_4 ( & V_6 -> V_14 ) ? L_8 : L_9 ) ;
V_4 -> V_7 = V_7 ;
switch ( V_7 ) {
case V_22 :
V_10 = L_10 ;
break;
case V_23 :
V_10 = L_11 ;
break;
case V_31 :
V_10 = L_12 ;
break;
default:
V_10 = L_13 ;
break;
}
F_2 ( V_2 -> V_11 , L_14 , V_10 ) ;
switch ( V_4 -> V_13 ) {
case V_26 :
type = L_15 ;
break;
case V_25 :
type = L_16 ;
break;
case V_42 :
type = L_17 ;
break;
case V_43 :
type = L_18 ;
break;
default:
type = L_13 ;
break;
}
F_2 ( V_2 -> V_11 , L_19 , type ) ;
if ( V_4 -> V_13 == V_25 ) {
F_2 ( V_2 -> V_11 , L_20 ,
V_4 -> V_30 ) ;
F_2 ( V_2 -> V_11 , L_21 ,
V_4 -> V_35 ) ;
}
}
struct V_3 * F_19 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_2 V_44 )
{
struct V_3 * V_4 ;
if ( ! V_6 -> V_21 )
return NULL ;
V_4 = F_20 ( sizeof( * V_4 ) , V_44 ) ;
if ( ! V_4 )
return NULL ;
F_1 ( V_2 , V_4 , V_6 ) ;
if ( V_2 -> V_45 -> V_46 > 0 &&
F_21 ( V_2 , V_4 , V_44 ) < 0 ) {
F_22 ( V_2 , V_4 ) ;
return NULL ;
}
return V_4 ;
}
void F_22 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_47 ) {
F_23 ( V_2 , V_4 ) ;
} else {
F_24 ( V_4 -> V_48 ) ;
V_4 -> V_49 = ( V_50 ) 0 ;
}
F_24 ( V_4 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_51 ;
int V_52 ;
V_52 = V_2 -> V_45 -> V_53 ;
if ( V_2 -> V_54 + V_2 -> V_55 <
V_52
&& V_2 -> V_54 < V_52 - 1 ) {
V_51 = 0 ;
} else {
F_17 ( V_2 -> V_11 ,
L_22
L_23 , V_12 , V_52 ,
V_2 -> V_54 , V_2 -> V_55 ) ;
V_51 = - V_56 ;
}
return V_51 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_51 ;
T_3 V_57 ;
V_51 = 0 ;
if ( V_4 -> V_7 == V_31 || V_4 -> V_24 ) {
V_57 = 100 - V_4 -> V_30 ;
} else {
V_57 = 900 - V_4 -> V_30 ;
}
if ( V_2 -> V_58 > V_57 ) {
F_27 ( V_2 -> V_11 ,
L_24 ,
V_12 , V_2 -> V_58 , V_4 -> V_30 ) ;
V_51 = - V_56 ;
}
return V_51 ;
}
void F_28 ( struct V_1 * V_2 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < 8 ; V_59 ++ )
V_2 -> V_60 [ V_59 ] = V_61 [ V_59 ] ;
}
static int F_29 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned short V_62 = V_4 -> V_30 ;
int V_59 ;
for ( V_59 = 0 ; V_59 < 8 ; V_59 ++ ) {
if ( V_62 <= V_2 -> V_60 [ V_59 ] ) {
V_2 -> V_60 [ V_59 ] -= V_62 ;
V_4 -> V_60 [ V_59 ] += V_62 ;
return V_59 ;
}
}
return - V_56 ;
}
static int F_30 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned short V_62 = V_4 -> V_30 ;
unsigned short V_63 ;
int V_64 ;
int V_59 ;
int V_65 ;
int V_66 ;
for ( V_59 = 0 ; V_59 < 8 ; V_59 ++ ) {
if ( V_2 -> V_60 [ V_59 ] <= 0 )
continue;
V_63 = V_2 -> V_60 [ V_59 ] ;
for ( V_65 = V_59 + 1 ; V_65 < 8 ; V_65 ++ ) {
if ( V_63 + V_2 -> V_60 [ V_65 ] < V_62 ) {
if ( V_2 -> V_60 [ V_65 ] <
V_61 [ V_65 ] )
continue;
}
if ( V_63 >= V_62 ) {
V_64 = V_62 ;
for ( V_66 = V_59 ; V_66 < 8 ; V_66 ++ ) {
V_64 -= V_2 -> V_60 [ V_66 ] ;
if ( V_64 <= 0 ) {
V_4 -> V_60 [ V_66 ] +=
V_2 -> V_60 [ V_66 ]
+ V_64 ;
V_2 -> V_60 [ V_66 ] = - V_64 ;
return V_59 ;
} else {
V_4 -> V_60 [ V_66 ] +=
V_2 -> V_60 [ V_66 ] ;
V_2 -> V_60 [ V_66 ] = 0 ;
}
}
}
V_63 += V_2 -> V_60 [ V_65 ] ;
if ( V_63 < V_62 &&
V_2 -> V_60 [ V_65 ] == V_61 [ V_65 ] )
continue;
}
}
return - V_56 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_67 ;
if ( V_4 -> V_7 == V_31 ) {
V_67 = F_29 ( V_2 , V_4 ) ;
} else {
V_67 = F_30 ( V_2 , V_4 ) ;
}
return V_67 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_68 ;
T_1 V_69 ;
int V_51 = 0 ;
V_68 = F_11 ( V_4 -> V_18 ) * F_10 ( V_4 -> V_18 ) ;
V_69 = V_2 -> V_45 -> V_70 ;
if ( V_68 > V_69 ) {
F_27 ( V_2 -> V_11 ,
L_25 ,
V_12 , V_68 , V_69 ) ;
V_51 = - V_56 ;
}
return V_51 ;
}
static int F_33 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_51 ;
if ( V_2 -> V_45 -> V_71 > 0 ) {
int V_72 = - 1 ;
V_51 = F_31 ( V_2 , V_4 ) ;
if ( V_51 == 0 )
V_72 = 7 ;
else if ( V_51 > 0 )
V_72 = V_51 - 1 ;
if ( V_72 >= 0 ) {
V_4 -> V_33 &= ~ 0x7 ;
V_4 -> V_33 |= ( V_72 & 7 ) ;
}
if ( V_51 > 0 )
V_51 = 0 ;
} else {
V_51 = F_25 ( V_2 ) ;
if ( V_51 ) {
F_34 ( V_2 -> V_11 ,
L_26 ,
V_12 ) ;
return V_51 ;
}
V_51 = F_26 ( V_2 , V_4 ) ;
}
if ( V_51 ) {
F_17 ( V_2 -> V_11 ,
L_27 ,
V_12 ) ;
return V_51 ;
}
V_51 = F_32 ( V_2 , V_4 ) ;
if ( V_51 ) {
F_17 ( V_2 -> V_11 ,
L_28 ,
V_12 ) ;
return V_51 ;
}
if ( V_2 -> V_45 -> V_46 > 0 )
F_35 ( & V_4 -> V_20 , & V_2 -> V_73 ) ;
else
F_35 ( & V_4 -> V_20 ,
& V_2 -> V_74 ) ;
if ( V_2 -> V_45 -> V_71 <= 0 )
V_2 -> V_54 ++ ;
V_2 -> V_58 += V_4 -> V_30 ;
return V_51 ;
}
static void F_36 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_59 ;
F_37 ( & V_4 -> V_20 ) ;
V_2 -> V_58 -= V_4 -> V_30 ;
if ( V_2 -> V_45 -> V_71 > 0 ) {
for ( V_59 = 0 ; V_59 < 8 ; V_59 ++ ) {
V_2 -> V_60 [ V_59 ] += V_4 -> V_60 [ V_59 ] ;
V_4 -> V_60 [ V_59 ] = 0 ;
}
} else {
V_2 -> V_54 -- ;
}
}
int F_38 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_51 ;
T_1 V_75 ;
if ( F_39 ( V_4 ) )
F_2 ( V_2 -> V_11 , L_1 , V_12 ) ;
if ( ! F_40 ( & V_4 -> V_20 ) )
return 0 ;
if ( ! F_41 ( V_4 -> V_33 , V_2 -> V_32 ) &&
! V_2 -> V_32 ) {
F_17 ( V_2 -> V_11 ,
L_29 ) ;
V_4 -> V_33 = F_15 ( V_2 -> V_32 ,
V_34 ) ;
}
if ( F_42 ( V_4 ) ) {
F_35 ( & V_4 -> V_20 ,
& V_2 -> V_76 ) ;
return 0 ;
}
V_51 = F_33 ( V_2 , V_4 ) ;
if ( V_51 )
return V_51 ;
if ( ! V_2 -> V_77 ) {
V_75 = F_16 ( V_2 -> V_36 + V_78 ) ;
V_75 |= V_79 ;
F_43 ( V_75 , V_2 -> V_36 + V_78 ) ;
}
V_2 -> V_77 ++ ;
return 0 ;
}
void F_44 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_75 ;
F_2 ( V_2 -> V_11 , L_1 , V_12 ) ;
if ( F_40 ( & V_4 -> V_20 ) )
return;
if ( F_42 ( V_4 ) ) {
if ( V_2 -> V_80 == & V_4 -> V_20 )
V_2 -> V_80 =
V_2 -> V_80 -> V_81 ;
F_37 ( & V_4 -> V_20 ) ;
return;
}
F_36 ( V_2 , V_4 ) ;
V_2 -> V_77 -- ;
if ( ! V_2 -> V_77 ) {
V_75 = F_16 ( V_2 -> V_36 + V_78 ) ;
V_75 &= ~ V_79 ;
F_43 ( V_75 , V_2 -> V_36 + V_78 ) ;
}
}
static void F_45 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_4 V_32 ,
int V_82 )
{
T_4 V_83 ;
if ( V_82 ) {
V_4 -> V_33 = V_32 ;
V_83 = F_15 ( V_4 -> V_41 , 1 ) ;
if ( F_41 ( V_32 , V_83 ) ) {
if ( V_4 -> V_13 != V_26 ||
V_4 -> V_15 != 0 ) {
V_4 -> V_33 =
F_15 ( V_4 -> V_33 , 1 ) ;
}
}
} else {
V_4 -> V_33 = F_15 ( V_4 -> V_41 ,
V_4 -> V_35 ) ;
if ( F_41 ( V_4 -> V_33 , V_32 ) )
V_4 -> V_33 = V_32 ;
V_4 -> V_33 |= 0x7 ;
V_4 -> V_41 = V_4 -> V_33 ;
}
}
void F_46 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_82 )
{
T_4 V_32 ;
if ( F_39 ( V_4 ) )
F_2 ( V_2 -> V_11 , L_1 , V_12 ) ;
if ( F_42 ( V_4 ) ) {
F_44 ( V_2 , V_4 ) ;
if ( ! F_40 ( & V_4 -> V_19 ) )
F_38 ( V_2 , V_4 ) ;
return;
}
V_32 = F_14 ( V_2 ) ;
if ( V_4 -> V_24 ) {
F_45 ( V_2 , V_4 , V_32 ,
V_82 ) ;
} else {
V_4 -> V_33 = F_15 ( V_4 -> V_33 ,
V_4 -> V_35 ) ;
if ( F_41 ( V_4 -> V_33 , V_32 ) )
V_4 -> V_33 = V_32 ;
}
if ( F_40 ( & V_4 -> V_19 ) ) {
F_44 ( V_2 , V_4 ) ;
return;
}
if ( ( V_2 -> V_45 -> V_71 > 0 &&
F_41 ( V_4 -> V_33 , V_32 ) ) ||
( V_2 -> V_45 -> V_71 <= 0 &&
V_4 -> V_33 == V_32 ) )
F_47 ( & V_4 -> V_20 , & V_2 -> V_73 ) ;
else
F_47 ( & V_4 -> V_20 , & V_2 -> V_74 ) ;
}
void F_48 ( struct V_84 * V_85 , struct V_5 * V_6 )
{
V_85 -> V_6 = V_6 ;
if ( F_3 ( & V_6 -> V_14 ) ==
V_42 ) {
V_85 -> V_16 = V_86 ;
V_85 -> V_87 = V_88 ;
}
V_85 -> V_89 = 0 ;
V_85 -> V_90 = V_91 ;
V_85 -> V_92 = 0 ;
V_85 -> V_93 = 0 ;
V_6 -> V_85 = V_85 ;
}
int F_49 ( struct V_1 * V_2 , struct V_84 * V_85 ,
struct V_3 * V_4 )
{
int V_94 ;
if ( F_50 ( ! V_4 ) ) {
F_27 ( V_2 -> V_11 , L_30 , V_12 ) ;
V_94 = - V_95 ;
goto V_96;
}
V_94 = F_38 ( V_2 , V_4 ) ;
if ( V_94 )
goto V_96;
V_85 -> V_4 = V_4 ;
F_35 ( & V_85 -> V_97 , & V_4 -> V_19 ) ;
return 0 ;
V_96:
return V_94 ;
}
