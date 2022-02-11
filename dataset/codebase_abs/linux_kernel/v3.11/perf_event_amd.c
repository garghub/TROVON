static T_1 F_1 ( int V_1 )
{
return V_2 [ V_1 ] ;
}
static inline int F_2 ( int V_3 , bool V_4 )
{
int V_5 ;
if ( ! V_3 )
return V_3 ;
if ( V_4 )
V_5 = V_6 [ V_3 ] ;
else
V_5 = V_7 [ V_3 ] ;
if ( V_5 )
return V_5 ;
if ( ! V_8 )
V_5 = V_3 ;
else
V_5 = V_3 << 1 ;
if ( V_4 )
V_6 [ V_3 ] = V_5 ;
else
V_7 [ V_3 ] = V_5 ;
return V_5 ;
}
static int F_3 ( struct V_9 * V_10 )
{
if ( V_10 -> V_11 . V_12 && V_10 -> V_11 . V_13 )
V_10 -> V_14 . V_15 &= ~ ( V_16 |
V_17 ) ;
else if ( V_10 -> V_11 . V_12 )
V_10 -> V_14 . V_15 |= V_18 ;
else if ( V_10 -> V_11 . V_13 )
V_10 -> V_14 . V_15 |= V_19 ;
return 0 ;
}
static inline unsigned int F_4 ( struct V_20 * V_21 )
{
return ( ( V_21 -> V_15 >> 24 ) & 0x0f00 ) | ( V_21 -> V_15 & 0x00ff ) ;
}
static inline int F_5 ( struct V_20 * V_21 )
{
return ( V_21 -> V_15 & 0xe0 ) == 0xe0 ;
}
static inline int F_6 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = V_23 -> V_24 ;
return V_25 && V_25 -> V_26 != - 1 ;
}
static int F_7 ( struct V_9 * V_10 )
{
int V_27 ;
if ( V_10 -> V_11 . V_28 && F_8 () )
return - V_29 ;
if ( F_9 ( V_10 ) )
return - V_30 ;
V_27 = F_10 ( V_10 ) ;
if ( V_27 )
return V_27 ;
if ( V_10 -> V_11 . type == V_31 )
V_10 -> V_14 . V_15 |= V_10 -> V_11 . V_15 & V_32 ;
return F_3 ( V_10 ) ;
}
static void F_11 ( struct V_22 * V_23 ,
struct V_9 * V_10 )
{
struct V_24 * V_25 = V_23 -> V_24 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_34 . V_35 ; V_33 ++ ) {
if ( F_12 ( V_25 -> V_36 + V_33 , V_10 , NULL ) == V_10 )
break;
}
}
static struct V_37 *
F_13 ( struct V_22 * V_23 , struct V_9 * V_10 ,
struct V_37 * V_38 )
{
struct V_20 * V_21 = & V_10 -> V_14 ;
struct V_24 * V_25 = V_23 -> V_24 ;
struct V_9 * V_39 ;
int V_40 , V_41 = - 1 ;
if ( ! V_38 )
V_38 = & V_42 ;
if ( V_23 -> V_43 )
return V_38 ;
F_14 (idx, c->idxmsk, x86_pmu.num_counters) {
if ( V_41 == - 1 || V_21 -> V_40 == V_40 )
V_39 = F_12 ( V_25 -> V_36 + V_40 , NULL , V_10 ) ;
else if ( V_25 -> V_36 [ V_40 ] == V_10 )
V_39 = V_10 ;
else
continue;
if ( V_39 && V_39 != V_10 )
continue;
if ( V_41 != - 1 )
F_12 ( V_25 -> V_36 + V_41 , V_10 , NULL ) ;
V_41 = V_40 ;
if ( V_39 == V_10 )
break;
}
if ( V_41 == - 1 )
return & V_44 ;
return & V_25 -> V_45 [ V_41 ] ;
}
static struct V_24 * F_15 ( int V_46 )
{
struct V_24 * V_25 ;
int V_33 ;
V_25 = F_16 ( sizeof( struct V_24 ) , V_47 | V_48 ,
F_17 ( V_46 ) ) ;
if ( ! V_25 )
return NULL ;
V_25 -> V_26 = - 1 ;
for ( V_33 = 0 ; V_33 < V_34 . V_35 ; V_33 ++ ) {
F_18 ( V_33 , V_25 -> V_45 [ V_33 ] . V_49 ) ;
V_25 -> V_45 [ V_33 ] . V_50 = 1 ;
}
return V_25 ;
}
static int F_19 ( int V_46 )
{
struct V_22 * V_23 = & F_20 ( V_22 , V_46 ) ;
F_21 ( V_23 -> V_24 ) ;
if ( V_51 . V_52 < 2 )
return V_53 ;
V_23 -> V_24 = F_15 ( V_46 ) ;
if ( ! V_23 -> V_24 )
return V_54 ;
return V_53 ;
}
static void F_22 ( int V_46 )
{
struct V_22 * V_23 = & F_20 ( V_22 , V_46 ) ;
struct V_24 * V_25 ;
int V_33 , V_26 ;
V_23 -> V_55 = V_19 ;
if ( V_51 . V_52 < 2 )
return;
V_26 = F_23 ( V_46 ) ;
F_21 ( V_26 == V_56 ) ;
F_24 (i) {
V_25 = F_20 ( V_22 , V_33 ) . V_24 ;
if ( F_21 ( ! V_25 ) )
continue;
if ( V_25 -> V_26 == V_26 ) {
V_23 -> V_57 = V_23 -> V_24 ;
V_23 -> V_24 = V_25 ;
break;
}
}
V_23 -> V_24 -> V_26 = V_26 ;
V_23 -> V_24 -> V_58 ++ ;
}
static void F_25 ( int V_46 )
{
struct V_22 * V_59 ;
if ( V_51 . V_52 < 2 )
return;
V_59 = & F_20 ( V_22 , V_46 ) ;
if ( V_59 -> V_24 ) {
struct V_24 * V_25 = V_59 -> V_24 ;
if ( V_25 -> V_26 == - 1 || -- V_25 -> V_58 == 0 )
F_26 ( V_25 ) ;
V_59 -> V_24 = NULL ;
}
}
static struct V_37 *
F_27 ( struct V_22 * V_23 , struct V_9 * V_10 )
{
if ( ! ( F_6 ( V_23 ) && F_5 ( & V_10 -> V_14 ) ) )
return & V_42 ;
return F_13 ( V_23 , V_10 , NULL ) ;
}
static void F_28 ( struct V_22 * V_23 ,
struct V_9 * V_10 )
{
if ( F_6 ( V_23 ) && F_5 ( & V_10 -> V_14 ) )
F_11 ( V_23 , V_10 ) ;
}
static struct V_37 *
F_29 ( struct V_22 * V_23 , struct V_9 * V_10 )
{
struct V_20 * V_21 = & V_10 -> V_14 ;
unsigned int V_60 = F_4 ( V_21 ) ;
switch ( V_60 & V_61 ) {
case V_62 :
switch ( V_60 ) {
case 0x000 :
if ( ! ( V_21 -> V_15 & 0x0000F000ULL ) )
break;
if ( ! ( V_21 -> V_15 & 0x00000F00ULL ) )
break;
return & V_63 ;
case 0x004 :
if ( F_30 ( V_21 -> V_15 & V_64 ) <= 1 )
break;
return & V_63 ;
case 0x003 :
case 0x00B :
case 0x00D :
return & V_63 ;
}
return & V_65 ;
case V_66 :
case V_67 :
case V_68 :
switch ( V_60 ) {
case 0x023 :
case 0x043 :
case 0x045 :
case 0x046 :
case 0x054 :
case 0x055 :
return & V_69 ;
case 0x02D :
return & V_63 ;
case 0x02E :
return & V_70 ;
case 0x031 :
if ( F_30 ( V_21 -> V_15 & V_64 ) <= 1 )
return & V_69 ;
return & V_44 ;
case 0x1C0 :
return & V_65 ;
default:
return & V_71 ;
}
case V_72 :
case V_73 :
case V_74 :
switch ( V_60 ) {
case 0x08F :
case 0x187 :
case 0x188 :
return & V_75 ;
case 0x0DB ... 0x0DF :
case 0x1D6 :
case 0x1D8 :
return & V_71 ;
default:
return & V_69 ;
}
case V_76 :
return & V_44 ;
default:
return & V_44 ;
}
}
static T_2 F_31 ( char * V_77 , T_1 V_15 )
{
T_1 V_10 = ( V_15 & V_78 ) |
( V_15 & V_79 ) >> 24 ;
return F_32 ( V_77 , V_15 , V_10 ) ;
}
static int T_3 F_33 ( void )
{
if ( ! V_8 )
return 0 ;
switch ( V_51 . V_80 ) {
case 0x15 :
F_34 ( L_1 ) ;
V_34 . V_81 = F_29 ;
break;
default:
F_35 ( L_2 ) ;
return - V_82 ;
}
V_34 . V_4 = V_83 ;
V_34 . V_84 = V_85 ;
V_34 . V_35 = V_86 ;
F_34 ( L_3 ) ;
return 0 ;
}
T_3 int F_36 ( void )
{
int V_27 ;
if ( V_51 . V_80 < 6 )
return - V_82 ;
V_34 = V_87 ;
V_27 = F_33 () ;
if ( V_27 )
return V_27 ;
memcpy ( V_88 , V_89 ,
sizeof( V_88 ) ) ;
return 0 ;
}
void F_37 ( void )
{
struct V_22 * V_23 = & F_38 ( V_22 ) ;
V_23 -> V_55 = 0 ;
F_39 () ;
F_40 ( 0 ) ;
}
void F_41 ( void )
{
struct V_22 * V_23 = & F_38 ( V_22 ) ;
V_23 -> V_55 = V_19 ;
F_39 () ;
F_40 ( 0 ) ;
}
