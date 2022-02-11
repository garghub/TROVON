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
if ( ! V_2 || ! V_2 -> V_26 )
return - V_27 ;
if ( V_2 -> V_28 ) {
F_28 ( 1 , L_2 , V_2 ) ;
return - V_29 ;
}
V_22 = V_2 -> V_22 ;
if ( ( ! V_22 ) || ( V_22 -> V_30 < V_31 ) )
return - V_32 ;
V_24 = F_29 ( V_22 , V_2 -> V_33 ) ;
if ( ! V_24 )
return - V_34 ;
V_2 -> V_24 = V_24 ;
V_2 -> V_35 = - V_36 ;
V_2 -> V_37 = 0 ;
V_19 = F_30 ( & V_24 -> V_38 ) ;
if ( V_19 == V_39 ) {
struct V_40 * V_41 =
(struct V_40 * ) V_2 -> V_42 ;
if ( ! V_41 )
return - V_43 ;
V_25 = ! ( V_41 -> V_44 & V_45 ) ||
! V_41 -> V_46 ;
} else {
V_25 = F_31 ( & V_24 -> V_38 ) ;
}
V_2 -> V_3 &= ~ ( V_47 | V_48 |
V_49 | V_50 | V_51 |
V_52 | V_53 |
V_54 ) ;
V_2 -> V_3 |= ( V_25 ? V_55 : V_56 ) ;
if ( V_19 != V_39 &&
V_22 -> V_30 < V_57 )
return - V_32 ;
V_20 = F_32 ( & V_24 -> V_38 ) ;
if ( V_20 <= 0 ) {
F_33 ( & V_22 -> V_22 ,
L_3 ,
F_34 ( & V_24 -> V_38 ) , V_25 ? L_4 : L_5 ,
V_58 , V_20 ) ;
return - V_59 ;
}
if ( V_19 == V_60 ) {
int V_61 , V_62 ;
if ( V_22 -> V_63 == V_64 ) {
int V_65 = 1 + V_24 -> V_66 . V_67 ;
int V_68 = F_35 ( V_24 -> V_66 . V_69 ) ;
V_20 *= V_65 ;
V_20 *= V_68 ;
}
if ( V_22 -> V_63 == V_70 ) {
int V_68 = 1 + ( ( V_20 >> 11 ) & 0x03 ) ;
V_20 &= 0x07ff ;
V_20 *= V_68 ;
}
if ( V_2 -> V_71 <= 0 )
return - V_27 ;
for ( V_61 = 0 ; V_61 < V_2 -> V_71 ; V_61 ++ ) {
V_62 = V_2 -> V_72 [ V_61 ] . V_73 ;
if ( V_62 < 0 || V_62 > V_20 )
return - V_59 ;
V_2 -> V_72 [ V_61 ] . V_35 = - V_74 ;
V_2 -> V_72 [ V_61 ] . V_37 = 0 ;
}
}
if ( V_2 -> V_75 > V_76 )
return - V_59 ;
#ifdef F_36
{
unsigned int V_77 ;
static int V_78 [ 4 ] = {
V_79 , V_80 , V_81 , V_82
} ;
if ( F_37 ( V_2 -> V_33 ) != V_78 [ V_19 ] )
F_38 ( & V_22 -> V_22 , L_6 ,
F_37 ( V_2 -> V_33 ) , V_78 [ V_19 ] ) ;
V_77 = ( V_83 | V_84 | V_47 |
V_4 ) ;
switch ( V_19 ) {
case V_85 :
if ( V_25 )
V_77 |= V_86 ;
case V_39 :
V_77 |= V_87 ;
default:
if ( ! V_25 )
V_77 |= V_88 ;
break;
case V_60 :
V_77 |= V_89 ;
break;
}
V_77 &= V_2 -> V_3 ;
if ( V_77 != V_2 -> V_3 )
F_38 ( & V_22 -> V_22 , L_7 ,
V_2 -> V_3 , V_77 ) ;
}
#endif
switch ( V_19 ) {
case V_60 :
case V_90 :
switch ( V_22 -> V_63 ) {
case V_91 :
if ( V_2 -> V_92 < 6 )
return - V_27 ;
break;
default:
if ( V_2 -> V_92 <= 0 )
return - V_27 ;
break;
}
switch ( V_22 -> V_63 ) {
case V_64 :
if ( V_2 -> V_92 > ( 1 << 15 ) )
return - V_27 ;
V_20 = 1 << 15 ;
break;
case V_91 :
if ( V_2 -> V_92 > 16 )
return - V_27 ;
break;
case V_70 :
if ( V_2 -> V_92 > ( 1024 * 8 ) )
V_2 -> V_92 = 1024 * 8 ;
V_20 = 1024 * 8 ;
break;
case V_93 :
case V_94 :
if ( V_19 == V_90 ) {
if ( V_2 -> V_92 > 255 )
return - V_27 ;
V_20 = 128 ;
} else {
if ( V_2 -> V_92 > 1024 )
V_2 -> V_92 = 1024 ;
V_20 = 1024 ;
}
break;
default:
return - V_27 ;
}
if ( V_22 -> V_63 != V_91 ) {
V_2 -> V_92 = F_39 ( V_20 , 1 << F_40 ( V_2 -> V_92 ) ) ;
}
}
return F_41 ( V_2 , V_8 ) ;
}
int F_42 ( struct V_2 * V_2 )
{
if ( ! V_2 )
return - V_27 ;
if ( ! V_2 -> V_22 )
return - V_32 ;
if ( ! V_2 -> V_24 )
return - V_95 ;
return F_43 ( V_2 , - V_96 ) ;
}
void F_44 ( struct V_2 * V_2 )
{
F_45 () ;
if ( ! ( V_2 && V_2 -> V_22 && V_2 -> V_24 ) )
return;
F_18 ( & V_2 -> V_17 ) ;
F_43 ( V_2 , - V_34 ) ;
F_46 ( V_97 , F_47 ( & V_2 -> V_98 ) == 0 ) ;
F_48 ( & V_2 -> V_17 ) ;
}
void F_49 ( struct V_2 * V_2 )
{
F_45 () ;
if ( ! V_2 )
return;
F_18 ( & V_2 -> V_17 ) ;
if ( ! V_2 -> V_22 || ! V_2 -> V_24 )
return;
F_43 ( V_2 , - V_34 ) ;
F_46 ( V_97 , F_47 ( & V_2 -> V_98 ) == 0 ) ;
}
void F_50 ( struct V_2 * V_2 )
{
if ( ! V_2 )
return;
F_48 ( & V_2 -> V_17 ) ;
}
void F_51 ( struct V_2 * V_2 )
{
if ( ! V_2 )
return;
F_18 ( & V_2 -> V_17 ) ;
}
void F_52 ( struct V_11 * V_12 )
{
struct V_2 * V_99 ;
F_53 ( & V_12 -> V_14 ) ;
while ( ! F_23 ( & V_12 -> V_15 ) ) {
V_99 = F_54 ( V_12 -> V_15 . V_100 , struct V_2 ,
V_6 ) ;
F_12 ( V_99 ) ;
F_55 ( & V_12 -> V_14 ) ;
F_44 ( V_99 ) ;
F_22 ( V_99 ) ;
F_53 ( & V_12 -> V_14 ) ;
}
F_55 ( & V_12 -> V_14 ) ;
}
void F_56 ( struct V_11 * V_12 )
{
struct V_2 * V_99 ;
F_53 ( & V_12 -> V_14 ) ;
V_12 -> V_16 = 1 ;
while ( ! F_23 ( & V_12 -> V_15 ) ) {
V_99 = F_54 ( V_12 -> V_15 . V_100 , struct V_2 ,
V_6 ) ;
F_12 ( V_99 ) ;
F_55 ( & V_12 -> V_14 ) ;
F_49 ( V_99 ) ;
F_22 ( V_99 ) ;
F_53 ( & V_12 -> V_14 ) ;
}
F_55 ( & V_12 -> V_14 ) ;
}
void F_57 ( struct V_11 * V_12 )
{
unsigned long V_13 ;
struct V_2 * V_101 ;
F_15 ( & V_12 -> V_14 , V_13 ) ;
F_58 (lazarus, &anchor->urb_list, anchor_list) {
F_50 ( V_101 ) ;
}
V_12 -> V_16 = 0 ;
F_19 ( & V_12 -> V_14 , V_13 ) ;
}
void F_59 ( struct V_11 * V_12 )
{
struct V_2 * V_99 ;
while ( ( V_99 = F_60 ( V_12 ) ) != NULL ) {
F_42 ( V_99 ) ;
F_22 ( V_99 ) ;
}
}
int F_61 ( struct V_11 * V_12 ,
unsigned int V_102 )
{
return F_62 ( V_12 -> V_18 , F_23 ( & V_12 -> V_15 ) ,
F_63 ( V_102 ) ) ;
}
struct V_2 * F_60 ( struct V_11 * V_12 )
{
struct V_2 * V_99 ;
unsigned long V_13 ;
F_15 ( & V_12 -> V_14 , V_13 ) ;
if ( ! F_23 ( & V_12 -> V_15 ) ) {
V_99 = F_54 ( V_12 -> V_15 . V_103 , struct V_2 ,
V_6 ) ;
F_12 ( V_99 ) ;
F_20 ( V_99 , V_12 ) ;
} else {
V_99 = NULL ;
}
F_19 ( & V_12 -> V_14 , V_13 ) ;
return V_99 ;
}
void F_64 ( struct V_11 * V_12 )
{
struct V_2 * V_99 ;
unsigned long V_13 ;
F_15 ( & V_12 -> V_14 , V_13 ) ;
while ( ! F_23 ( & V_12 -> V_15 ) ) {
V_99 = F_54 ( V_12 -> V_15 . V_100 , struct V_2 ,
V_6 ) ;
F_20 ( V_99 , V_12 ) ;
}
F_19 ( & V_12 -> V_14 , V_13 ) ;
}
int F_65 ( struct V_11 * V_12 )
{
return F_23 ( & V_12 -> V_15 ) ;
}
