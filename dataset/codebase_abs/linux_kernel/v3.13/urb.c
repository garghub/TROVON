static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = F_2 ( V_1 ) ;
if ( V_2 -> V_3 & V_4 )
F_3 ( V_2 -> V_5 ) ;
F_3 ( V_2 ) ;
}
void F_4 ( struct V_2 * V_2 )
{
if ( V_2 ) {
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_5 ( & V_2 -> V_1 ) ;
F_6 ( & V_2 -> V_6 ) ;
}
}
struct V_2 * F_7 ( int V_7 , T_1 V_8 )
{
struct V_2 * V_2 ;
V_2 = F_8 ( sizeof( struct V_2 ) +
V_7 * sizeof( struct V_9 ) ,
V_8 ) ;
if ( ! V_2 ) {
F_9 ( V_10 L_1 ) ;
return NULL ;
}
F_4 ( V_2 ) ;
return V_2 ;
}
void F_10 ( struct V_2 * V_2 )
{
if ( V_2 )
F_11 ( & V_2 -> V_1 , F_1 ) ;
}
struct V_2 * F_12 ( struct V_2 * V_2 )
{
if ( V_2 )
F_13 ( & V_2 -> V_1 ) ;
return V_2 ;
}
void F_14 ( struct V_2 * V_2 , struct V_11 * V_12 )
{
unsigned long V_13 ;
F_15 ( & V_12 -> V_14 , V_13 ) ;
F_12 ( V_2 ) ;
F_16 ( & V_2 -> V_6 , & V_12 -> V_15 ) ;
V_2 -> V_12 = V_12 ;
if ( F_17 ( V_12 -> V_16 ) ) {
F_18 ( & V_2 -> V_17 ) ;
}
F_19 ( & V_12 -> V_14 , V_13 ) ;
}
static int F_20 ( struct V_11 * V_12 )
{
return F_21 ( & V_12 -> V_18 ) == 0 &&
F_22 ( & V_12 -> V_15 ) ;
}
static void F_23 ( struct V_2 * V_2 , struct V_11 * V_12 )
{
V_2 -> V_12 = NULL ;
F_24 ( & V_2 -> V_6 ) ;
F_25 ( V_2 ) ;
if ( F_20 ( V_12 ) )
F_26 ( & V_12 -> V_19 ) ;
}
void F_27 ( struct V_2 * V_2 )
{
unsigned long V_13 ;
struct V_11 * V_12 ;
if ( ! V_2 )
return;
V_12 = V_2 -> V_12 ;
if ( ! V_12 )
return;
F_15 ( & V_12 -> V_14 , V_13 ) ;
if ( F_28 ( V_12 == V_2 -> V_12 ) )
F_23 ( V_2 , V_12 ) ;
F_19 ( & V_12 -> V_14 , V_13 ) ;
}
int F_29 ( struct V_2 * V_2 , T_1 V_8 )
{
int V_20 , V_21 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
int V_26 ;
if ( ! V_2 || ! V_2 -> V_27 )
return - V_28 ;
if ( V_2 -> V_29 ) {
F_30 ( 1 , L_2 , V_2 ) ;
return - V_30 ;
}
V_23 = V_2 -> V_23 ;
if ( ( ! V_23 ) || ( V_23 -> V_31 < V_32 ) )
return - V_33 ;
V_25 = F_31 ( V_23 , V_2 -> V_34 ) ;
if ( ! V_25 )
return - V_35 ;
V_2 -> V_25 = V_25 ;
V_2 -> V_36 = - V_37 ;
V_2 -> V_38 = 0 ;
V_20 = F_32 ( & V_25 -> V_39 ) ;
if ( V_20 == V_40 ) {
struct V_41 * V_42 =
(struct V_41 * ) V_2 -> V_43 ;
if ( ! V_42 )
return - V_44 ;
V_26 = ! ( V_42 -> V_45 & V_46 ) ||
! V_42 -> V_47 ;
} else {
V_26 = F_33 ( & V_25 -> V_39 ) ;
}
V_2 -> V_3 &= ~ ( V_48 | V_49 |
V_50 | V_51 | V_52 |
V_53 | V_54 |
V_55 ) ;
V_2 -> V_3 |= ( V_26 ? V_56 : V_57 ) ;
if ( V_20 != V_40 &&
V_23 -> V_31 < V_58 )
return - V_33 ;
V_21 = F_34 ( & V_25 -> V_39 ) ;
if ( V_21 <= 0 ) {
F_35 ( & V_23 -> V_23 ,
L_3 ,
F_36 ( & V_25 -> V_39 ) , V_26 ? L_4 : L_5 ,
V_59 , V_21 ) ;
return - V_60 ;
}
if ( V_20 == V_61 ) {
int V_62 , V_63 ;
if ( V_23 -> V_64 == V_65 ) {
int V_66 = 1 + V_25 -> V_67 . V_68 ;
int V_69 = F_37 ( V_25 -> V_67 . V_70 ) ;
V_21 *= V_66 ;
V_21 *= V_69 ;
}
if ( V_23 -> V_64 == V_71 ) {
int V_69 = 1 + ( ( V_21 >> 11 ) & 0x03 ) ;
V_21 &= 0x07ff ;
V_21 *= V_69 ;
}
if ( V_2 -> V_72 <= 0 )
return - V_28 ;
for ( V_62 = 0 ; V_62 < V_2 -> V_72 ; V_62 ++ ) {
V_63 = V_2 -> V_73 [ V_62 ] . V_74 ;
if ( V_63 < 0 || V_63 > V_21 )
return - V_60 ;
V_2 -> V_73 [ V_62 ] . V_36 = - V_75 ;
V_2 -> V_73 [ V_62 ] . V_38 = 0 ;
}
} else if ( V_2 -> V_76 && ! V_2 -> V_23 -> V_77 -> V_78 &&
V_23 -> V_64 != V_79 ) {
struct V_80 * V_81 ;
int V_82 ;
F_38 (urb->sg, sg, urb->num_sgs - 1 , i)
if ( V_81 -> V_74 % V_21 )
return - V_28 ;
}
if ( V_2 -> V_83 > V_84 )
return - V_60 ;
#ifdef F_39
{
unsigned int V_85 ;
static int V_86 [ 4 ] = {
V_87 , V_88 , V_89 , V_90
} ;
if ( F_40 ( V_2 -> V_34 ) != V_86 [ V_20 ] )
F_41 ( & V_23 -> V_23 , L_6 ,
F_40 ( V_2 -> V_34 ) , V_86 [ V_20 ] ) ;
V_85 = ( V_91 | V_92 | V_48 |
V_4 ) ;
switch ( V_20 ) {
case V_93 :
if ( V_26 )
V_85 |= V_94 ;
case V_40 :
V_85 |= V_95 ;
default:
if ( ! V_26 )
V_85 |= V_96 ;
break;
case V_61 :
V_85 |= V_97 ;
break;
}
V_85 &= V_2 -> V_3 ;
if ( V_85 != V_2 -> V_3 )
F_41 ( & V_23 -> V_23 , L_7 ,
V_2 -> V_3 , V_85 ) ;
}
#endif
switch ( V_20 ) {
case V_61 :
case V_98 :
switch ( V_23 -> V_64 ) {
case V_79 :
if ( V_2 -> V_99 < 6 )
return - V_28 ;
break;
default:
if ( V_2 -> V_99 <= 0 )
return - V_28 ;
break;
}
switch ( V_23 -> V_64 ) {
case V_65 :
if ( V_2 -> V_99 > ( 1 << 15 ) )
return - V_28 ;
V_21 = 1 << 15 ;
break;
case V_79 :
if ( V_2 -> V_99 > 16 )
return - V_28 ;
break;
case V_71 :
if ( V_2 -> V_99 > ( 1024 * 8 ) )
V_2 -> V_99 = 1024 * 8 ;
V_21 = 1024 * 8 ;
break;
case V_100 :
case V_101 :
if ( V_20 == V_98 ) {
if ( V_2 -> V_99 > 255 )
return - V_28 ;
V_21 = 128 ;
} else {
if ( V_2 -> V_99 > 1024 )
V_2 -> V_99 = 1024 ;
V_21 = 1024 ;
}
break;
default:
return - V_28 ;
}
if ( V_23 -> V_64 != V_79 ) {
V_2 -> V_99 = F_42 ( V_21 , 1 << F_43 ( V_2 -> V_99 ) ) ;
}
}
return F_44 ( V_2 , V_8 ) ;
}
int F_45 ( struct V_2 * V_2 )
{
if ( ! V_2 )
return - V_28 ;
if ( ! V_2 -> V_23 )
return - V_33 ;
if ( ! V_2 -> V_25 )
return - V_102 ;
return F_46 ( V_2 , - V_103 ) ;
}
void F_47 ( struct V_2 * V_2 )
{
F_48 () ;
if ( ! ( V_2 && V_2 -> V_23 && V_2 -> V_25 ) )
return;
F_18 ( & V_2 -> V_17 ) ;
F_46 ( V_2 , - V_35 ) ;
F_49 ( V_104 , F_21 ( & V_2 -> V_105 ) == 0 ) ;
F_50 ( & V_2 -> V_17 ) ;
}
void F_51 ( struct V_2 * V_2 )
{
F_48 () ;
if ( ! V_2 )
return;
F_18 ( & V_2 -> V_17 ) ;
if ( ! V_2 -> V_23 || ! V_2 -> V_25 )
return;
F_46 ( V_2 , - V_35 ) ;
F_49 ( V_104 , F_21 ( & V_2 -> V_105 ) == 0 ) ;
}
void F_52 ( struct V_2 * V_2 )
{
if ( ! V_2 )
return;
F_50 ( & V_2 -> V_17 ) ;
}
void F_53 ( struct V_2 * V_2 )
{
if ( ! V_2 )
return;
F_18 ( & V_2 -> V_17 ) ;
}
void F_54 ( struct V_11 * V_12 )
{
struct V_2 * V_106 ;
F_55 ( & V_12 -> V_14 ) ;
while ( ! F_22 ( & V_12 -> V_15 ) ) {
V_106 = F_56 ( V_12 -> V_15 . V_107 , struct V_2 ,
V_6 ) ;
F_12 ( V_106 ) ;
F_57 ( & V_12 -> V_14 ) ;
F_47 ( V_106 ) ;
F_25 ( V_106 ) ;
F_55 ( & V_12 -> V_14 ) ;
}
F_57 ( & V_12 -> V_14 ) ;
}
void F_58 ( struct V_11 * V_12 )
{
struct V_2 * V_106 ;
F_55 ( & V_12 -> V_14 ) ;
V_12 -> V_16 = 1 ;
while ( ! F_22 ( & V_12 -> V_15 ) ) {
V_106 = F_56 ( V_12 -> V_15 . V_107 , struct V_2 ,
V_6 ) ;
F_12 ( V_106 ) ;
F_57 ( & V_12 -> V_14 ) ;
F_51 ( V_106 ) ;
F_25 ( V_106 ) ;
F_55 ( & V_12 -> V_14 ) ;
}
F_57 ( & V_12 -> V_14 ) ;
}
void F_59 ( struct V_11 * V_12 )
{
unsigned long V_13 ;
struct V_2 * V_108 ;
F_15 ( & V_12 -> V_14 , V_13 ) ;
F_60 (lazarus, &anchor->urb_list, anchor_list) {
F_52 ( V_108 ) ;
}
V_12 -> V_16 = 0 ;
F_19 ( & V_12 -> V_14 , V_13 ) ;
}
void F_61 ( struct V_11 * V_12 )
{
struct V_2 * V_106 ;
while ( ( V_106 = F_62 ( V_12 ) ) != NULL ) {
F_45 ( V_106 ) ;
F_25 ( V_106 ) ;
}
}
void F_63 ( struct V_11 * V_12 )
{
if ( V_12 )
F_18 ( & V_12 -> V_18 ) ;
}
void F_64 ( struct V_11 * V_12 )
{
if ( ! V_12 )
return;
F_50 ( & V_12 -> V_18 ) ;
if ( F_20 ( V_12 ) )
F_26 ( & V_12 -> V_19 ) ;
}
int F_65 ( struct V_11 * V_12 ,
unsigned int V_109 )
{
return F_66 ( V_12 -> V_19 ,
F_20 ( V_12 ) ,
F_67 ( V_109 ) ) ;
}
struct V_2 * F_62 ( struct V_11 * V_12 )
{
struct V_2 * V_106 ;
unsigned long V_13 ;
F_15 ( & V_12 -> V_14 , V_13 ) ;
if ( ! F_22 ( & V_12 -> V_15 ) ) {
V_106 = F_56 ( V_12 -> V_15 . V_110 , struct V_2 ,
V_6 ) ;
F_12 ( V_106 ) ;
F_23 ( V_106 , V_12 ) ;
} else {
V_106 = NULL ;
}
F_19 ( & V_12 -> V_14 , V_13 ) ;
return V_106 ;
}
void F_68 ( struct V_11 * V_12 )
{
struct V_2 * V_106 ;
unsigned long V_13 ;
F_15 ( & V_12 -> V_14 , V_13 ) ;
while ( ! F_22 ( & V_12 -> V_15 ) ) {
V_106 = F_56 ( V_12 -> V_15 . V_107 , struct V_2 ,
V_6 ) ;
F_23 ( V_106 , V_12 ) ;
}
F_19 ( & V_12 -> V_14 , V_13 ) ;
}
int F_69 ( struct V_11 * V_12 )
{
return F_22 ( & V_12 -> V_15 ) ;
}
