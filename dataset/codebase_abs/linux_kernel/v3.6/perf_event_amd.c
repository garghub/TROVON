static T_1 F_1 ( int V_1 )
{
return V_2 [ V_1 ] ;
}
static int F_2 ( struct V_3 * V_4 )
{
int V_5 ;
if ( V_4 -> V_6 . V_7 && F_3 () )
return - V_8 ;
V_5 = F_4 ( V_4 ) ;
if ( V_5 )
return V_5 ;
if ( F_5 ( V_4 ) )
return - V_9 ;
if ( V_4 -> V_6 . V_10 && V_4 -> V_6 . V_11 )
V_4 -> V_12 . V_13 &= ~ ( V_14 |
V_15 ) ;
else if ( V_4 -> V_6 . V_10 )
V_4 -> V_12 . V_13 |= V_16 ;
else if ( V_4 -> V_6 . V_11 )
V_4 -> V_12 . V_13 |= V_17 ;
if ( V_4 -> V_6 . type != V_18 )
return 0 ;
V_4 -> V_12 . V_13 |= V_4 -> V_6 . V_13 & V_19 ;
return 0 ;
}
static inline unsigned int F_6 ( struct V_20 * V_21 )
{
return ( ( V_21 -> V_13 >> 24 ) & 0x0f00 ) | ( V_21 -> V_13 & 0x00ff ) ;
}
static inline int F_7 ( struct V_20 * V_21 )
{
return ( V_21 -> V_13 & 0xe0 ) == 0xe0 ;
}
static inline int F_8 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = V_23 -> V_24 ;
return V_25 && V_25 -> V_26 != - 1 ;
}
static void F_9 ( struct V_22 * V_23 ,
struct V_3 * V_4 )
{
struct V_20 * V_21 = & V_4 -> V_12 ;
struct V_24 * V_25 = V_23 -> V_24 ;
int V_27 ;
if ( ! ( F_8 ( V_23 ) && F_7 ( V_21 ) ) )
return;
for ( V_27 = 0 ; V_27 < V_28 . V_29 ; V_27 ++ ) {
if ( F_10 ( V_25 -> V_30 + V_27 , V_4 , NULL ) == V_4 )
break;
}
}
static struct V_31 *
F_11 ( struct V_22 * V_23 , struct V_3 * V_4 )
{
struct V_20 * V_21 = & V_4 -> V_12 ;
struct V_24 * V_25 = V_23 -> V_24 ;
struct V_3 * V_32 = NULL ;
int V_33 = V_28 . V_29 ;
int V_27 , V_34 , V_35 = - 1 ;
if ( ! ( F_8 ( V_23 ) && F_7 ( V_21 ) ) )
return & V_36 ;
for ( V_27 = 0 ; V_27 < V_33 ; V_27 ++ ) {
if ( V_35 == - 1 && ! V_25 -> V_30 [ V_27 ] )
V_35 = V_27 ;
if ( V_25 -> V_30 [ V_27 ] == V_4 )
goto V_37;
}
if ( V_21 -> V_38 != - 1 ) {
V_27 = V_21 -> V_38 ;
} else if ( V_35 != - 1 ) {
V_27 = V_35 ;
} else {
V_27 = 0 ;
}
V_34 = V_27 ;
do {
V_32 = F_10 ( V_25 -> V_30 + V_27 , NULL , V_4 ) ;
if ( ! V_32 )
break;
if ( ++ V_27 == V_33 )
V_27 = 0 ;
} while ( V_27 != V_34 );
V_37:
if ( ! V_32 )
return & V_25 -> V_39 [ V_27 ] ;
return & V_40 ;
}
static struct V_24 * F_12 ( int V_41 )
{
struct V_24 * V_25 ;
int V_27 ;
V_25 = F_13 ( sizeof( struct V_24 ) , V_42 | V_43 ,
F_14 ( V_41 ) ) ;
if ( ! V_25 )
return NULL ;
V_25 -> V_26 = - 1 ;
for ( V_27 = 0 ; V_27 < V_28 . V_29 ; V_27 ++ ) {
F_15 ( V_27 , V_25 -> V_39 [ V_27 ] . V_44 ) ;
V_25 -> V_39 [ V_27 ] . V_45 = 1 ;
}
return V_25 ;
}
static int F_16 ( int V_41 )
{
struct V_22 * V_23 = & F_17 ( V_22 , V_41 ) ;
F_18 ( V_23 -> V_24 ) ;
if ( V_46 . V_47 < 2 )
return V_48 ;
V_23 -> V_24 = F_12 ( V_41 ) ;
if ( ! V_23 -> V_24 )
return V_49 ;
return V_48 ;
}
static void F_19 ( int V_41 )
{
struct V_22 * V_23 = & F_17 ( V_22 , V_41 ) ;
struct V_24 * V_25 ;
int V_27 , V_26 ;
V_23 -> V_50 = V_17 ;
if ( V_46 . V_47 < 2 )
return;
V_26 = F_20 ( V_41 ) ;
F_18 ( V_26 == V_51 ) ;
F_21 (i) {
V_25 = F_17 ( V_22 , V_27 ) . V_24 ;
if ( F_18 ( ! V_25 ) )
continue;
if ( V_25 -> V_26 == V_26 ) {
V_23 -> V_52 = V_23 -> V_24 ;
V_23 -> V_24 = V_25 ;
break;
}
}
V_23 -> V_24 -> V_26 = V_26 ;
V_23 -> V_24 -> V_53 ++ ;
}
static void F_22 ( int V_41 )
{
struct V_22 * V_54 ;
if ( V_46 . V_47 < 2 )
return;
V_54 = & F_17 ( V_22 , V_41 ) ;
if ( V_54 -> V_24 ) {
struct V_24 * V_25 = V_54 -> V_24 ;
if ( V_25 -> V_26 == - 1 || -- V_25 -> V_53 == 0 )
F_23 ( V_25 ) ;
V_54 -> V_24 = NULL ;
}
}
static struct V_31 *
F_24 ( struct V_22 * V_23 , struct V_3 * V_4 )
{
struct V_20 * V_21 = & V_4 -> V_12 ;
unsigned int V_55 = F_6 ( V_21 ) ;
switch ( V_55 & V_56 ) {
case V_57 :
switch ( V_55 ) {
case 0x000 :
if ( ! ( V_21 -> V_13 & 0x0000F000ULL ) )
break;
if ( ! ( V_21 -> V_13 & 0x00000F00ULL ) )
break;
return & V_58 ;
case 0x004 :
if ( F_25 ( V_21 -> V_13 & V_59 ) <= 1 )
break;
return & V_58 ;
case 0x003 :
case 0x00B :
case 0x00D :
return & V_58 ;
}
return & V_60 ;
case V_61 :
case V_62 :
case V_63 :
switch ( V_55 ) {
case 0x023 :
case 0x043 :
case 0x045 :
case 0x046 :
case 0x054 :
case 0x055 :
return & V_64 ;
case 0x02D :
return & V_58 ;
case 0x02E :
return & V_65 ;
case 0x031 :
if ( F_25 ( V_21 -> V_13 & V_59 ) <= 1 )
return & V_64 ;
return & V_40 ;
case 0x1C0 :
return & V_60 ;
default:
return & V_66 ;
}
case V_67 :
case V_68 :
case V_69 :
switch ( V_55 ) {
case 0x08F :
case 0x187 :
case 0x188 :
return & V_70 ;
case 0x0DB ... 0x0DF :
case 0x1D6 :
case 0x1D8 :
return & V_66 ;
default:
return & V_64 ;
}
case V_71 :
return & V_40 ;
default:
return & V_40 ;
}
}
static int F_26 ( void )
{
if ( V_46 . V_72 >= 0x15 )
V_28 . V_73 = F_24 ;
return 0 ;
}
static int F_27 ( void )
{
if ( ! V_74 ) {
F_28 ( V_28 . V_73 == F_24 ,
V_75 L_1 ) ;
return - V_76 ;
}
F_28 ( V_28 . V_73 == F_11 ,
V_75 L_2 ) ;
V_28 . V_77 = V_78 ;
V_28 . V_79 = V_80 ;
V_28 . V_29 = V_81 ;
F_29 ( V_82 L_3 ) ;
return 0 ;
}
T_2 int F_30 ( void )
{
if ( V_46 . V_72 < 6 )
return - V_76 ;
V_28 = V_83 ;
F_26 () ;
F_27 () ;
memcpy ( V_84 , V_85 ,
sizeof( V_84 ) ) ;
return 0 ;
}
void F_31 ( void )
{
struct V_22 * V_23 = & F_32 ( V_22 ) ;
V_23 -> V_50 = 0 ;
F_33 () ;
F_34 ( 0 ) ;
}
void F_35 ( void )
{
struct V_22 * V_23 = & F_32 ( V_22 ) ;
V_23 -> V_50 = V_17 ;
F_33 () ;
F_34 ( 0 ) ;
}
