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
static int V_20 [ 4 ] = {
V_21 , V_22 , V_23 , V_24
} ;
int V_25 , V_26 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
int V_31 ;
unsigned int V_32 ;
if ( ! V_2 || ! V_2 -> V_33 )
return - V_34 ;
if ( V_2 -> V_35 ) {
F_30 ( 1 , L_2 , V_2 ) ;
return - V_36 ;
}
V_28 = V_2 -> V_28 ;
if ( ( ! V_28 ) || ( V_28 -> V_37 < V_38 ) )
return - V_39 ;
V_30 = F_31 ( V_28 , V_2 -> V_40 ) ;
if ( ! V_30 )
return - V_41 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_42 = - V_43 ;
V_2 -> V_44 = 0 ;
V_25 = F_32 ( & V_30 -> V_45 ) ;
if ( V_25 == V_46 ) {
struct V_47 * V_48 =
(struct V_47 * ) V_2 -> V_49 ;
if ( ! V_48 )
return - V_50 ;
V_31 = ! ( V_48 -> V_51 & V_52 ) ||
! V_48 -> V_53 ;
} else {
V_31 = F_33 ( & V_30 -> V_45 ) ;
}
V_2 -> V_3 &= ~ ( V_54 | V_55 |
V_56 | V_57 | V_58 |
V_59 | V_60 |
V_61 ) ;
V_2 -> V_3 |= ( V_31 ? V_62 : V_63 ) ;
if ( V_25 != V_46 &&
V_28 -> V_37 < V_64 )
return - V_39 ;
V_26 = F_34 ( & V_30 -> V_45 ) ;
if ( V_26 <= 0 ) {
F_35 ( & V_28 -> V_28 ,
L_3 ,
F_36 ( & V_30 -> V_45 ) , V_31 ? L_4 : L_5 ,
V_65 , V_26 ) ;
return - V_66 ;
}
if ( V_25 == V_67 ) {
int V_68 , V_69 ;
if ( V_28 -> V_70 == V_71 ) {
int V_72 = 1 + V_30 -> V_73 . V_74 ;
int V_75 = F_37 ( V_30 -> V_73 . V_76 ) ;
V_26 *= V_72 ;
V_26 *= V_75 ;
}
if ( V_28 -> V_70 == V_77 ) {
int V_75 = 1 + ( ( V_26 >> 11 ) & 0x03 ) ;
V_26 &= 0x07ff ;
V_26 *= V_75 ;
}
if ( V_2 -> V_78 <= 0 )
return - V_34 ;
for ( V_68 = 0 ; V_68 < V_2 -> V_78 ; V_68 ++ ) {
V_69 = V_2 -> V_79 [ V_68 ] . V_80 ;
if ( V_69 < 0 || V_69 > V_26 )
return - V_66 ;
V_2 -> V_79 [ V_68 ] . V_42 = - V_81 ;
V_2 -> V_79 [ V_68 ] . V_44 = 0 ;
}
} else if ( V_2 -> V_82 && ! V_2 -> V_28 -> V_83 -> V_84 &&
V_28 -> V_70 != V_85 ) {
struct V_86 * V_87 ;
int V_88 ;
F_38 (urb->sg, sg, urb->num_sgs - 1 , i)
if ( V_87 -> V_80 % V_26 )
return - V_34 ;
}
if ( V_2 -> V_89 > V_90 )
return - V_66 ;
if ( F_39 ( V_2 -> V_40 ) != V_20 [ V_25 ] )
F_40 ( & V_28 -> V_28 , L_6 ,
F_39 ( V_2 -> V_40 ) , V_20 [ V_25 ] ) ;
V_32 = ( V_91 | V_92 | V_54 |
V_4 ) ;
switch ( V_25 ) {
case V_93 :
if ( V_31 )
V_32 |= V_94 ;
case V_46 :
V_32 |= V_95 ;
default:
if ( ! V_31 )
V_32 |= V_96 ;
break;
case V_67 :
V_32 |= V_97 ;
break;
}
V_32 &= V_2 -> V_3 ;
if ( V_32 != V_2 -> V_3 )
F_40 ( & V_28 -> V_28 , L_7 ,
V_2 -> V_3 , V_32 ) ;
switch ( V_25 ) {
case V_67 :
case V_98 :
switch ( V_28 -> V_70 ) {
case V_85 :
if ( ( V_2 -> V_99 < 6 )
&& ( V_25 == V_98 ) )
return - V_34 ;
default:
if ( V_2 -> V_99 <= 0 )
return - V_34 ;
break;
}
switch ( V_28 -> V_70 ) {
case V_71 :
if ( V_2 -> V_99 > ( 1 << 15 ) )
return - V_34 ;
V_26 = 1 << 15 ;
break;
case V_85 :
if ( V_2 -> V_99 > 16 )
return - V_34 ;
break;
case V_77 :
if ( V_2 -> V_99 > ( 1024 * 8 ) )
V_2 -> V_99 = 1024 * 8 ;
V_26 = 1024 * 8 ;
break;
case V_100 :
case V_101 :
if ( V_25 == V_98 ) {
if ( V_2 -> V_99 > 255 )
return - V_34 ;
V_26 = 128 ;
} else {
if ( V_2 -> V_99 > 1024 )
V_2 -> V_99 = 1024 ;
V_26 = 1024 ;
}
break;
default:
return - V_34 ;
}
if ( V_28 -> V_70 != V_85 ) {
V_2 -> V_99 = F_41 ( V_26 , 1 << F_42 ( V_2 -> V_99 ) ) ;
}
}
return F_43 ( V_2 , V_8 ) ;
}
int F_44 ( struct V_2 * V_2 )
{
if ( ! V_2 )
return - V_34 ;
if ( ! V_2 -> V_28 )
return - V_39 ;
if ( ! V_2 -> V_30 )
return - V_102 ;
return F_45 ( V_2 , - V_103 ) ;
}
void F_46 ( struct V_2 * V_2 )
{
F_47 () ;
if ( ! ( V_2 && V_2 -> V_28 && V_2 -> V_30 ) )
return;
F_18 ( & V_2 -> V_17 ) ;
F_45 ( V_2 , - V_41 ) ;
F_48 ( V_104 , F_21 ( & V_2 -> V_105 ) == 0 ) ;
F_49 ( & V_2 -> V_17 ) ;
}
void F_50 ( struct V_2 * V_2 )
{
F_47 () ;
if ( ! V_2 )
return;
F_18 ( & V_2 -> V_17 ) ;
if ( ! V_2 -> V_28 || ! V_2 -> V_30 )
return;
F_45 ( V_2 , - V_41 ) ;
F_48 ( V_104 , F_21 ( & V_2 -> V_105 ) == 0 ) ;
}
void F_51 ( struct V_2 * V_2 )
{
if ( ! V_2 )
return;
F_49 ( & V_2 -> V_17 ) ;
}
void F_52 ( struct V_2 * V_2 )
{
if ( ! V_2 )
return;
F_18 ( & V_2 -> V_17 ) ;
}
void F_53 ( struct V_11 * V_12 )
{
struct V_2 * V_106 ;
F_54 ( & V_12 -> V_14 ) ;
while ( ! F_22 ( & V_12 -> V_15 ) ) {
V_106 = F_55 ( V_12 -> V_15 . V_107 , struct V_2 ,
V_6 ) ;
F_12 ( V_106 ) ;
F_56 ( & V_12 -> V_14 ) ;
F_46 ( V_106 ) ;
F_25 ( V_106 ) ;
F_54 ( & V_12 -> V_14 ) ;
}
F_56 ( & V_12 -> V_14 ) ;
}
void F_57 ( struct V_11 * V_12 )
{
struct V_2 * V_106 ;
F_54 ( & V_12 -> V_14 ) ;
V_12 -> V_16 = 1 ;
while ( ! F_22 ( & V_12 -> V_15 ) ) {
V_106 = F_55 ( V_12 -> V_15 . V_107 , struct V_2 ,
V_6 ) ;
F_12 ( V_106 ) ;
F_56 ( & V_12 -> V_14 ) ;
F_50 ( V_106 ) ;
F_25 ( V_106 ) ;
F_54 ( & V_12 -> V_14 ) ;
}
F_56 ( & V_12 -> V_14 ) ;
}
void F_58 ( struct V_11 * V_12 )
{
unsigned long V_13 ;
struct V_2 * V_108 ;
F_15 ( & V_12 -> V_14 , V_13 ) ;
F_59 (lazarus, &anchor->urb_list, anchor_list) {
F_51 ( V_108 ) ;
}
V_12 -> V_16 = 0 ;
F_19 ( & V_12 -> V_14 , V_13 ) ;
}
void F_60 ( struct V_11 * V_12 )
{
struct V_2 * V_106 ;
while ( ( V_106 = F_61 ( V_12 ) ) != NULL ) {
F_44 ( V_106 ) ;
F_25 ( V_106 ) ;
}
}
void F_62 ( struct V_11 * V_12 )
{
if ( V_12 )
F_18 ( & V_12 -> V_18 ) ;
}
void F_63 ( struct V_11 * V_12 )
{
if ( ! V_12 )
return;
F_49 ( & V_12 -> V_18 ) ;
if ( F_20 ( V_12 ) )
F_26 ( & V_12 -> V_19 ) ;
}
int F_64 ( struct V_11 * V_12 ,
unsigned int V_109 )
{
return F_65 ( V_12 -> V_19 ,
F_20 ( V_12 ) ,
F_66 ( V_109 ) ) ;
}
struct V_2 * F_61 ( struct V_11 * V_12 )
{
struct V_2 * V_106 ;
unsigned long V_13 ;
F_15 ( & V_12 -> V_14 , V_13 ) ;
if ( ! F_22 ( & V_12 -> V_15 ) ) {
V_106 = F_55 ( V_12 -> V_15 . V_110 , struct V_2 ,
V_6 ) ;
F_12 ( V_106 ) ;
F_23 ( V_106 , V_12 ) ;
} else {
V_106 = NULL ;
}
F_19 ( & V_12 -> V_14 , V_13 ) ;
return V_106 ;
}
void F_67 ( struct V_11 * V_12 )
{
struct V_2 * V_106 ;
unsigned long V_13 ;
F_15 ( & V_12 -> V_14 , V_13 ) ;
while ( ! F_22 ( & V_12 -> V_15 ) ) {
V_106 = F_55 ( V_12 -> V_15 . V_107 , struct V_2 ,
V_6 ) ;
F_23 ( V_106 , V_12 ) ;
}
F_19 ( & V_12 -> V_14 , V_13 ) ;
}
int F_68 ( struct V_11 * V_12 )
{
return F_22 ( & V_12 -> V_15 ) ;
}
