static T_1 F_1 ( int V_1 )
{
return V_2 [ V_1 ] ;
}
static int F_2 ( struct V_3 * V_4 )
{
int V_5 = F_3 ( V_4 ) ;
if ( V_5 )
return V_5 ;
if ( F_4 ( V_4 ) )
return - V_6 ;
if ( V_4 -> V_7 . V_8 && V_4 -> V_7 . V_9 )
V_4 -> V_10 . V_11 &= ~ ( V_12 |
V_13 ) ;
else if ( V_4 -> V_7 . V_8 )
V_4 -> V_10 . V_11 |= V_14 ;
else if ( V_4 -> V_7 . V_9 )
V_4 -> V_10 . V_11 |= V_15 ;
if ( V_4 -> V_7 . type != V_16 )
return 0 ;
V_4 -> V_10 . V_11 |= V_4 -> V_7 . V_11 & V_17 ;
return 0 ;
}
static inline unsigned int F_5 ( struct V_18 * V_19 )
{
return ( ( V_19 -> V_11 >> 24 ) & 0x0f00 ) | ( V_19 -> V_11 & 0x00ff ) ;
}
static inline int F_6 ( struct V_18 * V_19 )
{
return ( V_19 -> V_11 & 0xe0 ) == 0xe0 ;
}
static inline int F_7 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_22 ;
return V_23 && V_23 -> V_24 != - 1 ;
}
static void F_8 ( struct V_20 * V_21 ,
struct V_3 * V_4 )
{
struct V_18 * V_19 = & V_4 -> V_10 ;
struct V_22 * V_23 = V_21 -> V_22 ;
int V_25 ;
if ( ! ( F_7 ( V_21 ) && F_6 ( V_19 ) ) )
return;
for ( V_25 = 0 ; V_25 < V_26 . V_27 ; V_25 ++ ) {
if ( V_23 -> V_28 [ V_25 ] == V_4 ) {
F_9 ( V_23 -> V_28 + V_25 , V_4 , NULL ) ;
break;
}
}
}
static struct V_29 *
F_10 ( struct V_20 * V_21 , struct V_3 * V_4 )
{
struct V_18 * V_19 = & V_4 -> V_10 ;
struct V_22 * V_23 = V_21 -> V_22 ;
struct V_3 * V_30 = NULL ;
int V_31 = V_26 . V_27 ;
int V_25 , V_32 , V_33 = - 1 ;
if ( ! ( F_7 ( V_21 ) && F_6 ( V_19 ) ) )
return & V_34 ;
for ( V_25 = 0 ; V_25 < V_31 ; V_25 ++ ) {
if ( V_33 == - 1 && ! V_23 -> V_28 [ V_25 ] )
V_33 = V_25 ;
if ( V_23 -> V_28 [ V_25 ] == V_4 )
goto V_35;
}
if ( V_19 -> V_36 != - 1 ) {
V_25 = V_19 -> V_36 ;
} else if ( V_33 != - 1 ) {
V_25 = V_33 ;
} else {
V_25 = 0 ;
}
V_32 = V_25 ;
do {
V_30 = F_9 ( V_23 -> V_28 + V_25 , NULL , V_4 ) ;
if ( ! V_30 )
break;
if ( ++ V_25 == V_31 )
V_25 = 0 ;
} while ( V_25 != V_32 );
V_35:
if ( ! V_30 )
return & V_23 -> V_37 [ V_25 ] ;
return & V_38 ;
}
static struct V_22 * F_11 ( int V_39 )
{
struct V_22 * V_23 ;
int V_25 ;
V_23 = F_12 ( sizeof( struct V_22 ) , V_40 | V_41 ,
F_13 ( V_39 ) ) ;
if ( ! V_23 )
return NULL ;
V_23 -> V_24 = - 1 ;
for ( V_25 = 0 ; V_25 < V_26 . V_27 ; V_25 ++ ) {
F_14 ( V_25 , V_23 -> V_37 [ V_25 ] . V_42 ) ;
V_23 -> V_37 [ V_25 ] . V_43 = 1 ;
}
return V_23 ;
}
static int F_15 ( int V_39 )
{
struct V_20 * V_21 = & F_16 ( V_20 , V_39 ) ;
F_17 ( V_21 -> V_22 ) ;
if ( V_44 . V_45 < 2 )
return V_46 ;
V_21 -> V_22 = F_11 ( V_39 ) ;
if ( ! V_21 -> V_22 )
return V_47 ;
return V_46 ;
}
static void F_18 ( int V_39 )
{
struct V_20 * V_21 = & F_16 ( V_20 , V_39 ) ;
struct V_22 * V_23 ;
int V_25 , V_24 ;
V_21 -> V_48 = V_15 ;
if ( V_44 . V_45 < 2 || V_44 . V_49 == 0x15 )
return;
V_24 = F_19 ( V_39 ) ;
F_17 ( V_24 == V_50 ) ;
F_20 (i) {
V_23 = F_16 ( V_20 , V_25 ) . V_22 ;
if ( F_17 ( ! V_23 ) )
continue;
if ( V_23 -> V_24 == V_24 ) {
V_21 -> V_51 = V_21 -> V_22 ;
V_21 -> V_22 = V_23 ;
break;
}
}
V_21 -> V_22 -> V_24 = V_24 ;
V_21 -> V_22 -> V_52 ++ ;
}
static void F_21 ( int V_39 )
{
struct V_20 * V_53 ;
if ( V_44 . V_45 < 2 )
return;
V_53 = & F_16 ( V_20 , V_39 ) ;
if ( V_53 -> V_22 ) {
struct V_22 * V_23 = V_53 -> V_22 ;
if ( V_23 -> V_24 == - 1 || -- V_23 -> V_52 == 0 )
F_22 ( V_23 ) ;
V_53 -> V_22 = NULL ;
}
}
static struct V_29 *
F_23 ( struct V_20 * V_21 , struct V_3 * V_4 )
{
struct V_18 * V_19 = & V_4 -> V_10 ;
unsigned int V_54 = F_5 ( V_19 ) ;
switch ( V_54 & V_55 ) {
case V_56 :
switch ( V_54 ) {
case 0x000 :
if ( ! ( V_19 -> V_11 & 0x0000F000ULL ) )
break;
if ( ! ( V_19 -> V_11 & 0x00000F00ULL ) )
break;
return & V_57 ;
case 0x004 :
if ( F_24 ( V_19 -> V_11 & V_58 ) <= 1 )
break;
return & V_57 ;
case 0x003 :
case 0x00B :
case 0x00D :
return & V_57 ;
}
return & V_59 ;
case V_60 :
case V_61 :
case V_62 :
switch ( V_54 ) {
case 0x023 :
case 0x043 :
case 0x045 :
case 0x046 :
case 0x054 :
case 0x055 :
return & V_63 ;
case 0x02D :
return & V_57 ;
case 0x02E :
return & V_64 ;
default:
return & V_65 ;
}
case V_66 :
case V_67 :
case V_68 :
switch ( V_54 ) {
case 0x08F :
case 0x187 :
case 0x188 :
return & V_69 ;
case 0x0DB ... 0x0DF :
case 0x1D6 :
case 0x1D8 :
return & V_65 ;
default:
return & V_63 ;
}
case V_70 :
return & V_38 ;
default:
return & V_38 ;
}
}
T_2 int F_25 ( void )
{
if ( V_44 . V_49 < 6 )
return - V_71 ;
switch ( V_44 . V_49 ) {
case 0x15 :
if ( ! V_72 )
return - V_71 ;
V_26 = V_73 ;
break;
default:
if ( V_72 )
return - V_71 ;
V_26 = V_74 ;
break;
}
memcpy ( V_75 , V_76 ,
sizeof( V_75 ) ) ;
return 0 ;
}
void F_26 ( void )
{
struct V_20 * V_21 = & F_27 ( V_20 ) ;
V_21 -> V_48 = 0 ;
F_28 () ;
F_29 ( 0 ) ;
}
void F_30 ( void )
{
struct V_20 * V_21 = & F_27 ( V_20 ) ;
V_21 -> V_48 = V_15 ;
F_28 () ;
F_29 ( 0 ) ;
}
