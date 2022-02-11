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
if ( ! V_2 )
return NULL ;
F_4 ( V_2 ) ;
return V_2 ;
}
void F_9 ( struct V_2 * V_2 )
{
if ( V_2 )
F_10 ( & V_2 -> V_1 , F_1 ) ;
}
struct V_2 * F_11 ( struct V_2 * V_2 )
{
if ( V_2 )
F_12 ( & V_2 -> V_1 ) ;
return V_2 ;
}
void F_13 ( struct V_2 * V_2 , struct V_10 * V_11 )
{
unsigned long V_12 ;
F_14 ( & V_11 -> V_13 , V_12 ) ;
F_11 ( V_2 ) ;
F_15 ( & V_2 -> V_6 , & V_11 -> V_14 ) ;
V_2 -> V_11 = V_11 ;
if ( F_16 ( V_11 -> V_15 ) )
F_17 ( & V_2 -> V_16 ) ;
F_18 ( & V_11 -> V_13 , V_12 ) ;
}
static int F_19 ( struct V_10 * V_11 )
{
return F_20 ( & V_11 -> V_17 ) == 0 &&
F_21 ( & V_11 -> V_14 ) ;
}
static void F_22 ( struct V_2 * V_2 , struct V_10 * V_11 )
{
V_2 -> V_11 = NULL ;
F_23 ( & V_2 -> V_6 ) ;
F_24 ( V_2 ) ;
if ( F_19 ( V_11 ) )
F_25 ( & V_11 -> V_18 ) ;
}
void F_26 ( struct V_2 * V_2 )
{
unsigned long V_12 ;
struct V_10 * V_11 ;
if ( ! V_2 )
return;
V_11 = V_2 -> V_11 ;
if ( ! V_11 )
return;
F_14 ( & V_11 -> V_13 , V_12 ) ;
if ( F_27 ( V_11 == V_2 -> V_11 ) )
F_22 ( V_2 , V_11 ) ;
F_18 ( & V_11 -> V_13 , V_12 ) ;
}
int F_28 ( struct V_2 * V_2 , T_1 V_8 )
{
static int V_19 [ 4 ] = {
V_20 , V_21 , V_22 , V_23
} ;
int V_24 , V_25 ;
struct V_26 * V_27 ;
struct V_28 * V_29 ;
int V_30 ;
unsigned int V_31 ;
if ( ! V_2 || ! V_2 -> V_32 )
return - V_33 ;
if ( V_2 -> V_34 ) {
F_29 ( 1 , L_1 , V_2 ) ;
return - V_35 ;
}
V_27 = V_2 -> V_27 ;
if ( ( ! V_27 ) || ( V_27 -> V_36 < V_37 ) )
return - V_38 ;
V_29 = F_30 ( V_27 , V_2 -> V_39 ) ;
if ( ! V_29 )
return - V_40 ;
V_2 -> V_29 = V_29 ;
V_2 -> V_41 = - V_42 ;
V_2 -> V_43 = 0 ;
V_24 = F_31 ( & V_29 -> V_44 ) ;
if ( V_24 == V_45 ) {
struct V_46 * V_47 =
(struct V_46 * ) V_2 -> V_48 ;
if ( ! V_47 )
return - V_49 ;
V_30 = ! ( V_47 -> V_50 & V_51 ) ||
! V_47 -> V_52 ;
} else {
V_30 = F_32 ( & V_29 -> V_44 ) ;
}
V_2 -> V_3 &= ~ ( V_53 | V_54 |
V_55 | V_56 | V_57 |
V_58 | V_59 |
V_60 ) ;
V_2 -> V_3 |= ( V_30 ? V_61 : V_62 ) ;
if ( V_24 != V_45 &&
V_27 -> V_36 < V_63 )
return - V_38 ;
V_25 = F_33 ( & V_29 -> V_44 ) ;
if ( V_25 <= 0 ) {
F_34 ( & V_27 -> V_27 ,
L_2 ,
F_35 ( & V_29 -> V_44 ) , V_30 ? L_3 : L_4 ,
V_64 , V_25 ) ;
return - V_65 ;
}
if ( V_24 == V_66 ) {
int V_67 , V_68 ;
if ( V_27 -> V_69 >= V_70 ) {
int V_71 = 1 + V_29 -> V_72 . V_73 ;
int V_74 = F_36 ( V_29 -> V_72 . V_75 ) ;
V_25 *= V_71 ;
V_25 *= V_74 ;
}
if ( V_27 -> V_69 == V_76 ) {
int V_74 = 1 + ( ( V_25 >> 11 ) & 0x03 ) ;
V_25 &= 0x07ff ;
V_25 *= V_74 ;
}
if ( V_2 -> V_77 <= 0 )
return - V_33 ;
for ( V_67 = 0 ; V_67 < V_2 -> V_77 ; V_67 ++ ) {
V_68 = V_2 -> V_78 [ V_67 ] . V_79 ;
if ( V_68 < 0 || V_68 > V_25 )
return - V_65 ;
V_2 -> V_78 [ V_67 ] . V_41 = - V_80 ;
V_2 -> V_78 [ V_67 ] . V_43 = 0 ;
}
} else if ( V_2 -> V_81 && ! V_2 -> V_27 -> V_82 -> V_83 &&
V_27 -> V_69 != V_84 ) {
struct V_85 * V_86 ;
int V_87 ;
F_37 (urb->sg, sg, urb->num_sgs - 1 , i)
if ( V_86 -> V_79 % V_25 )
return - V_33 ;
}
if ( V_2 -> V_88 > V_89 )
return - V_65 ;
if ( F_38 ( V_2 -> V_39 ) != V_19 [ V_24 ] )
F_39 ( & V_27 -> V_27 , L_5 ,
F_38 ( V_2 -> V_39 ) , V_19 [ V_24 ] ) ;
V_31 = ( V_90 | V_91 | V_53 |
V_4 ) ;
switch ( V_24 ) {
case V_92 :
case V_93 :
if ( V_30 )
V_31 |= V_94 ;
case V_45 :
V_31 |= V_95 ;
default:
if ( ! V_30 )
V_31 |= V_96 ;
break;
case V_66 :
V_31 |= V_97 ;
break;
}
V_31 &= V_2 -> V_3 ;
if ( V_31 != V_2 -> V_3 )
F_39 ( & V_27 -> V_27 , L_6 ,
V_2 -> V_3 , V_31 ) ;
switch ( V_24 ) {
case V_66 :
case V_93 :
switch ( V_27 -> V_69 ) {
case V_84 :
if ( ( V_2 -> V_98 < 6 )
&& ( V_24 == V_93 ) )
return - V_33 ;
default:
if ( V_2 -> V_98 <= 0 )
return - V_33 ;
break;
}
switch ( V_27 -> V_69 ) {
case V_99 :
case V_70 :
if ( V_2 -> V_98 > ( 1 << 15 ) )
return - V_33 ;
V_25 = 1 << 15 ;
break;
case V_84 :
if ( V_2 -> V_98 > 16 )
return - V_33 ;
break;
case V_76 :
if ( V_2 -> V_98 > ( 1024 * 8 ) )
V_2 -> V_98 = 1024 * 8 ;
V_25 = 1024 * 8 ;
break;
case V_100 :
case V_101 :
if ( V_24 == V_93 ) {
if ( V_2 -> V_98 > 255 )
return - V_33 ;
V_25 = 128 ;
} else {
if ( V_2 -> V_98 > 1024 )
V_2 -> V_98 = 1024 ;
V_25 = 1024 ;
}
break;
default:
return - V_33 ;
}
if ( V_27 -> V_69 != V_84 ) {
V_2 -> V_98 = F_40 ( V_25 , 1 << F_41 ( V_2 -> V_98 ) ) ;
}
}
return F_42 ( V_2 , V_8 ) ;
}
int F_43 ( struct V_2 * V_2 )
{
if ( ! V_2 )
return - V_33 ;
if ( ! V_2 -> V_27 )
return - V_38 ;
if ( ! V_2 -> V_29 )
return - V_102 ;
return F_44 ( V_2 , - V_103 ) ;
}
void F_45 ( struct V_2 * V_2 )
{
F_46 () ;
if ( ! ( V_2 && V_2 -> V_27 && V_2 -> V_29 ) )
return;
F_17 ( & V_2 -> V_16 ) ;
F_44 ( V_2 , - V_40 ) ;
F_47 ( V_104 , F_20 ( & V_2 -> V_105 ) == 0 ) ;
F_48 ( & V_2 -> V_16 ) ;
}
void F_49 ( struct V_2 * V_2 )
{
F_46 () ;
if ( ! V_2 )
return;
F_17 ( & V_2 -> V_16 ) ;
if ( ! V_2 -> V_27 || ! V_2 -> V_29 )
return;
F_44 ( V_2 , - V_40 ) ;
F_47 ( V_104 , F_20 ( & V_2 -> V_105 ) == 0 ) ;
}
void F_50 ( struct V_2 * V_2 )
{
if ( ! V_2 )
return;
F_48 ( & V_2 -> V_16 ) ;
}
void F_51 ( struct V_2 * V_2 )
{
if ( ! V_2 )
return;
F_17 ( & V_2 -> V_16 ) ;
}
void F_52 ( struct V_10 * V_11 )
{
struct V_2 * V_106 ;
F_53 ( & V_11 -> V_13 ) ;
while ( ! F_21 ( & V_11 -> V_14 ) ) {
V_106 = F_54 ( V_11 -> V_14 . V_107 , struct V_2 ,
V_6 ) ;
F_11 ( V_106 ) ;
F_55 ( & V_11 -> V_13 ) ;
F_45 ( V_106 ) ;
F_24 ( V_106 ) ;
F_53 ( & V_11 -> V_13 ) ;
}
F_55 ( & V_11 -> V_13 ) ;
}
void F_56 ( struct V_10 * V_11 )
{
struct V_2 * V_106 ;
F_53 ( & V_11 -> V_13 ) ;
V_11 -> V_15 = 1 ;
while ( ! F_21 ( & V_11 -> V_14 ) ) {
V_106 = F_54 ( V_11 -> V_14 . V_107 , struct V_2 ,
V_6 ) ;
F_11 ( V_106 ) ;
F_55 ( & V_11 -> V_13 ) ;
F_49 ( V_106 ) ;
F_24 ( V_106 ) ;
F_53 ( & V_11 -> V_13 ) ;
}
F_55 ( & V_11 -> V_13 ) ;
}
void F_57 ( struct V_10 * V_11 )
{
unsigned long V_12 ;
struct V_2 * V_108 ;
F_14 ( & V_11 -> V_13 , V_12 ) ;
F_58 (lazarus, &anchor->urb_list, anchor_list) {
F_50 ( V_108 ) ;
}
V_11 -> V_15 = 0 ;
F_18 ( & V_11 -> V_13 , V_12 ) ;
}
void F_59 ( struct V_10 * V_11 )
{
struct V_2 * V_106 ;
while ( ( V_106 = F_60 ( V_11 ) ) != NULL ) {
F_43 ( V_106 ) ;
F_24 ( V_106 ) ;
}
}
void F_61 ( struct V_10 * V_11 )
{
if ( V_11 )
F_17 ( & V_11 -> V_17 ) ;
}
void F_62 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return;
F_48 ( & V_11 -> V_17 ) ;
if ( F_19 ( V_11 ) )
F_25 ( & V_11 -> V_18 ) ;
}
int F_63 ( struct V_10 * V_11 ,
unsigned int V_109 )
{
return F_64 ( V_11 -> V_18 ,
F_19 ( V_11 ) ,
F_65 ( V_109 ) ) ;
}
struct V_2 * F_60 ( struct V_10 * V_11 )
{
struct V_2 * V_106 ;
unsigned long V_12 ;
F_14 ( & V_11 -> V_13 , V_12 ) ;
if ( ! F_21 ( & V_11 -> V_14 ) ) {
V_106 = F_54 ( V_11 -> V_14 . V_110 , struct V_2 ,
V_6 ) ;
F_11 ( V_106 ) ;
F_22 ( V_106 , V_11 ) ;
} else {
V_106 = NULL ;
}
F_18 ( & V_11 -> V_13 , V_12 ) ;
return V_106 ;
}
void F_66 ( struct V_10 * V_11 )
{
struct V_2 * V_106 ;
unsigned long V_12 ;
F_14 ( & V_11 -> V_13 , V_12 ) ;
while ( ! F_21 ( & V_11 -> V_14 ) ) {
V_106 = F_54 ( V_11 -> V_14 . V_107 , struct V_2 ,
V_6 ) ;
F_22 ( V_106 , V_11 ) ;
}
F_18 ( & V_11 -> V_13 , V_12 ) ;
}
int F_67 ( struct V_10 * V_11 )
{
return F_21 ( & V_11 -> V_14 ) ;
}
