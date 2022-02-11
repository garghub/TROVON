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
static void F_20 ( struct V_2 * V_2 , struct V_11 * V_12 )
{
V_2 -> V_12 = NULL ;
F_21 ( & V_2 -> V_6 ) ;
F_22 ( V_2 ) ;
if ( F_23 ( & V_12 -> V_15 ) )
F_24 ( & V_12 -> V_18 ) ;
}
void F_25 ( struct V_2 * V_2 )
{
unsigned long V_13 ;
struct V_11 * V_12 ;
if ( ! V_2 )
return;
V_12 = V_2 -> V_12 ;
if ( ! V_12 )
return;
F_15 ( & V_12 -> V_14 , V_13 ) ;
if ( F_26 ( V_12 == V_2 -> V_12 ) )
F_20 ( V_2 , V_12 ) ;
F_19 ( & V_12 -> V_14 , V_13 ) ;
}
int F_27 ( struct V_2 * V_2 , T_1 V_8 )
{
int V_19 , V_20 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
int V_25 ;
if ( ! V_2 || V_2 -> V_26 || ! V_2 -> V_27 )
return - V_28 ;
V_22 = V_2 -> V_22 ;
if ( ( ! V_22 ) || ( V_22 -> V_29 < V_30 ) )
return - V_31 ;
V_24 = F_28 ( V_22 , V_2 -> V_32 ) ;
if ( ! V_24 )
return - V_33 ;
V_2 -> V_24 = V_24 ;
V_2 -> V_34 = - V_35 ;
V_2 -> V_36 = 0 ;
V_19 = F_29 ( & V_24 -> V_37 ) ;
if ( V_19 == V_38 ) {
struct V_39 * V_40 =
(struct V_39 * ) V_2 -> V_41 ;
if ( ! V_40 )
return - V_42 ;
V_25 = ! ( V_40 -> V_43 & V_44 ) ||
! V_40 -> V_45 ;
} else {
V_25 = F_30 ( & V_24 -> V_37 ) ;
}
V_2 -> V_3 &= ~ ( V_46 | V_47 |
V_48 | V_49 | V_50 |
V_51 | V_52 |
V_53 ) ;
V_2 -> V_3 |= ( V_25 ? V_54 : V_55 ) ;
if ( V_19 != V_38 &&
V_22 -> V_29 < V_56 )
return - V_31 ;
V_20 = F_31 ( & V_24 -> V_37 ) ;
if ( V_20 <= 0 ) {
F_32 ( & V_22 -> V_22 ,
L_2 ,
F_33 ( & V_24 -> V_37 ) , V_25 ? L_3 : L_4 ,
V_57 , V_20 ) ;
return - V_58 ;
}
if ( V_19 == V_59 ) {
int V_60 , V_61 ;
if ( V_22 -> V_62 == V_63 ) {
int V_64 = 1 + V_24 -> V_65 . V_66 ;
int V_67 = F_34 ( V_24 -> V_65 . V_68 ) ;
V_20 *= V_64 ;
V_20 *= V_67 ;
}
if ( V_22 -> V_62 == V_69 ) {
int V_67 = 1 + ( ( V_20 >> 11 ) & 0x03 ) ;
V_20 &= 0x07ff ;
V_20 *= V_67 ;
}
if ( V_2 -> V_70 <= 0 )
return - V_28 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_70 ; V_60 ++ ) {
V_61 = V_2 -> V_71 [ V_60 ] . V_72 ;
if ( V_61 < 0 || V_61 > V_20 )
return - V_58 ;
V_2 -> V_71 [ V_60 ] . V_34 = - V_73 ;
V_2 -> V_71 [ V_60 ] . V_36 = 0 ;
}
}
if ( V_2 -> V_74 > V_75 )
return - V_58 ;
#ifdef F_35
{
unsigned int V_76 ;
static int V_77 [ 4 ] = {
V_78 , V_79 , V_80 , V_81
} ;
if ( F_36 ( V_2 -> V_32 ) != V_77 [ V_19 ] )
F_37 ( & V_22 -> V_22 , L_5 ,
F_36 ( V_2 -> V_32 ) , V_77 [ V_19 ] ) ;
V_76 = ( V_82 | V_83 | V_46 |
V_4 ) ;
switch ( V_19 ) {
case V_84 :
if ( V_25 )
V_76 |= V_85 ;
case V_38 :
V_76 |= V_86 ;
default:
if ( ! V_25 )
V_76 |= V_87 ;
break;
case V_59 :
V_76 |= V_88 ;
break;
}
V_76 &= V_2 -> V_3 ;
if ( V_76 != V_2 -> V_3 )
F_37 ( & V_22 -> V_22 , L_6 ,
V_2 -> V_3 , V_76 ) ;
}
#endif
switch ( V_19 ) {
case V_59 :
case V_89 :
switch ( V_22 -> V_62 ) {
case V_90 :
if ( V_2 -> V_91 < 6 )
return - V_28 ;
break;
default:
if ( V_2 -> V_91 <= 0 )
return - V_28 ;
break;
}
switch ( V_22 -> V_62 ) {
case V_63 :
if ( V_2 -> V_91 > ( 1 << 15 ) )
return - V_28 ;
V_20 = 1 << 15 ;
break;
case V_90 :
if ( V_2 -> V_91 > 16 )
return - V_28 ;
break;
case V_69 :
if ( V_2 -> V_91 > ( 1024 * 8 ) )
V_2 -> V_91 = 1024 * 8 ;
V_20 = 1024 * 8 ;
break;
case V_92 :
case V_93 :
if ( V_19 == V_89 ) {
if ( V_2 -> V_91 > 255 )
return - V_28 ;
V_20 = 128 ;
} else {
if ( V_2 -> V_91 > 1024 )
V_2 -> V_91 = 1024 ;
V_20 = 1024 ;
}
break;
default:
return - V_28 ;
}
if ( V_22 -> V_62 != V_90 ) {
V_2 -> V_91 = F_38 ( V_20 , 1 << F_39 ( V_2 -> V_91 ) ) ;
}
}
return F_40 ( V_2 , V_8 ) ;
}
int F_41 ( struct V_2 * V_2 )
{
if ( ! V_2 )
return - V_28 ;
if ( ! V_2 -> V_22 )
return - V_31 ;
if ( ! V_2 -> V_24 )
return - V_94 ;
return F_42 ( V_2 , - V_95 ) ;
}
void F_43 ( struct V_2 * V_2 )
{
F_44 () ;
if ( ! ( V_2 && V_2 -> V_22 && V_2 -> V_24 ) )
return;
F_18 ( & V_2 -> V_17 ) ;
F_42 ( V_2 , - V_33 ) ;
F_45 ( V_96 , F_46 ( & V_2 -> V_97 ) == 0 ) ;
F_47 ( & V_2 -> V_17 ) ;
}
void F_48 ( struct V_2 * V_2 )
{
F_44 () ;
if ( ! ( V_2 && V_2 -> V_22 && V_2 -> V_24 ) )
return;
F_18 ( & V_2 -> V_17 ) ;
F_42 ( V_2 , - V_33 ) ;
F_45 ( V_96 , F_46 ( & V_2 -> V_97 ) == 0 ) ;
}
void F_49 ( struct V_2 * V_2 )
{
if ( ! V_2 )
return;
F_47 ( & V_2 -> V_17 ) ;
}
void F_50 ( struct V_11 * V_12 )
{
struct V_2 * V_98 ;
F_51 ( & V_12 -> V_14 ) ;
while ( ! F_23 ( & V_12 -> V_15 ) ) {
V_98 = F_52 ( V_12 -> V_15 . V_99 , struct V_2 ,
V_6 ) ;
F_12 ( V_98 ) ;
F_53 ( & V_12 -> V_14 ) ;
F_43 ( V_98 ) ;
F_22 ( V_98 ) ;
F_51 ( & V_12 -> V_14 ) ;
}
F_53 ( & V_12 -> V_14 ) ;
}
void F_54 ( struct V_11 * V_12 )
{
struct V_2 * V_98 ;
F_51 ( & V_12 -> V_14 ) ;
V_12 -> V_16 = 1 ;
while ( ! F_23 ( & V_12 -> V_15 ) ) {
V_98 = F_52 ( V_12 -> V_15 . V_99 , struct V_2 ,
V_6 ) ;
F_12 ( V_98 ) ;
F_53 ( & V_12 -> V_14 ) ;
F_48 ( V_98 ) ;
F_22 ( V_98 ) ;
F_51 ( & V_12 -> V_14 ) ;
}
F_53 ( & V_12 -> V_14 ) ;
}
void F_55 ( struct V_11 * V_12 )
{
unsigned long V_13 ;
struct V_2 * V_100 ;
F_15 ( & V_12 -> V_14 , V_13 ) ;
F_56 (lazarus, &anchor->urb_list, anchor_list) {
F_49 ( V_100 ) ;
}
V_12 -> V_16 = 0 ;
F_19 ( & V_12 -> V_14 , V_13 ) ;
}
void F_57 ( struct V_11 * V_12 )
{
struct V_2 * V_98 ;
while ( ( V_98 = F_58 ( V_12 ) ) != NULL ) {
F_41 ( V_98 ) ;
F_22 ( V_98 ) ;
}
}
int F_59 ( struct V_11 * V_12 ,
unsigned int V_101 )
{
return F_60 ( V_12 -> V_18 , F_23 ( & V_12 -> V_15 ) ,
F_61 ( V_101 ) ) ;
}
struct V_2 * F_58 ( struct V_11 * V_12 )
{
struct V_2 * V_98 ;
unsigned long V_13 ;
F_15 ( & V_12 -> V_14 , V_13 ) ;
if ( ! F_23 ( & V_12 -> V_15 ) ) {
V_98 = F_52 ( V_12 -> V_15 . V_102 , struct V_2 ,
V_6 ) ;
F_12 ( V_98 ) ;
F_20 ( V_98 , V_12 ) ;
} else {
V_98 = NULL ;
}
F_19 ( & V_12 -> V_14 , V_13 ) ;
return V_98 ;
}
void F_62 ( struct V_11 * V_12 )
{
struct V_2 * V_98 ;
unsigned long V_13 ;
F_15 ( & V_12 -> V_14 , V_13 ) ;
while ( ! F_23 ( & V_12 -> V_15 ) ) {
V_98 = F_52 ( V_12 -> V_15 . V_99 , struct V_2 ,
V_6 ) ;
F_20 ( V_98 , V_12 ) ;
}
F_19 ( & V_12 -> V_14 , V_13 ) ;
}
int F_63 ( struct V_11 * V_12 )
{
return F_23 ( & V_12 -> V_15 ) ;
}
