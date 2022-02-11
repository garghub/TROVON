static T_1 F_1 ( int V_1 )
{
return V_2 [ V_1 ] ;
}
static int F_2 ( struct V_3 * V_4 )
{
int V_5 = F_3 ( V_4 ) ;
if ( V_5 )
return V_5 ;
if ( V_4 -> V_6 . V_7 && V_4 -> V_6 . V_8 )
V_4 -> V_9 . V_10 &= ~ ( V_11 |
V_12 ) ;
else if ( V_4 -> V_6 . V_7 )
V_4 -> V_9 . V_10 |= V_13 ;
else if ( V_4 -> V_6 . V_8 )
V_4 -> V_9 . V_10 |= V_14 ;
if ( V_4 -> V_6 . type != V_15 )
return 0 ;
V_4 -> V_9 . V_10 |= V_4 -> V_6 . V_10 & V_16 ;
return 0 ;
}
static inline unsigned int F_4 ( struct V_17 * V_18 )
{
return ( ( V_18 -> V_10 >> 24 ) & 0x0f00 ) | ( V_18 -> V_10 & 0x00ff ) ;
}
static inline int F_5 ( struct V_17 * V_18 )
{
return ( V_18 -> V_10 & 0xe0 ) == 0xe0 ;
}
static inline int F_6 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_21 ;
return V_22 && V_22 -> V_23 != - 1 ;
}
static void F_7 ( struct V_19 * V_20 ,
struct V_3 * V_4 )
{
struct V_17 * V_18 = & V_4 -> V_9 ;
struct V_21 * V_22 = V_20 -> V_21 ;
int V_24 ;
if ( ! ( F_6 ( V_20 ) && F_5 ( V_18 ) ) )
return;
for ( V_24 = 0 ; V_24 < V_25 . V_26 ; V_24 ++ ) {
if ( V_22 -> V_27 [ V_24 ] == V_4 ) {
F_8 ( V_22 -> V_27 + V_24 , V_4 , NULL ) ;
break;
}
}
}
static struct V_28 *
F_9 ( struct V_19 * V_20 , struct V_3 * V_4 )
{
struct V_17 * V_18 = & V_4 -> V_9 ;
struct V_21 * V_22 = V_20 -> V_21 ;
struct V_3 * V_29 = NULL ;
int V_30 = V_25 . V_26 ;
int V_24 , V_31 , V_32 = - 1 ;
if ( ! ( F_6 ( V_20 ) && F_5 ( V_18 ) ) )
return & V_33 ;
for ( V_24 = 0 ; V_24 < V_30 ; V_24 ++ ) {
if ( V_32 == - 1 && ! V_22 -> V_27 [ V_24 ] )
V_32 = V_24 ;
if ( V_22 -> V_27 [ V_24 ] == V_4 )
goto V_34;
}
if ( V_18 -> V_35 != - 1 ) {
V_24 = V_18 -> V_35 ;
} else if ( V_32 != - 1 ) {
V_24 = V_32 ;
} else {
V_24 = 0 ;
}
V_31 = V_24 ;
do {
V_29 = F_8 ( V_22 -> V_27 + V_24 , NULL , V_4 ) ;
if ( ! V_29 )
break;
if ( ++ V_24 == V_30 )
V_24 = 0 ;
} while ( V_24 != V_31 );
V_34:
if ( ! V_29 )
return & V_22 -> V_36 [ V_24 ] ;
return & V_37 ;
}
static struct V_21 * F_10 ( int V_38 )
{
struct V_21 * V_22 ;
int V_24 ;
V_22 = F_11 ( sizeof( struct V_21 ) , V_39 | V_40 ,
F_12 ( V_38 ) ) ;
if ( ! V_22 )
return NULL ;
V_22 -> V_23 = - 1 ;
for ( V_24 = 0 ; V_24 < V_25 . V_26 ; V_24 ++ ) {
F_13 ( V_24 , V_22 -> V_36 [ V_24 ] . V_41 ) ;
V_22 -> V_36 [ V_24 ] . V_42 = 1 ;
}
return V_22 ;
}
static int F_14 ( int V_38 )
{
struct V_19 * V_20 = & F_15 ( V_19 , V_38 ) ;
F_16 ( V_20 -> V_21 ) ;
if ( V_43 . V_44 < 2 )
return V_45 ;
V_20 -> V_21 = F_10 ( V_38 ) ;
if ( ! V_20 -> V_21 )
return V_46 ;
return V_45 ;
}
static void F_17 ( int V_38 )
{
struct V_19 * V_20 = & F_15 ( V_19 , V_38 ) ;
struct V_21 * V_22 ;
int V_24 , V_23 ;
if ( V_43 . V_44 < 2 )
return;
V_23 = F_18 ( V_38 ) ;
F_16 ( V_23 == V_47 ) ;
F_19 (i) {
V_22 = F_15 ( V_19 , V_24 ) . V_21 ;
if ( F_16 ( ! V_22 ) )
continue;
if ( V_22 -> V_23 == V_23 ) {
V_20 -> V_48 = V_20 -> V_21 ;
V_20 -> V_21 = V_22 ;
break;
}
}
V_20 -> V_21 -> V_23 = V_23 ;
V_20 -> V_21 -> V_49 ++ ;
}
static void F_20 ( int V_38 )
{
struct V_19 * V_50 ;
if ( V_43 . V_44 < 2 )
return;
V_50 = & F_15 ( V_19 , V_38 ) ;
if ( V_50 -> V_21 ) {
struct V_21 * V_22 = V_50 -> V_21 ;
if ( V_22 -> V_23 == - 1 || -- V_22 -> V_49 == 0 )
F_21 ( V_22 ) ;
V_50 -> V_21 = NULL ;
}
}
static struct V_28 *
F_22 ( struct V_19 * V_20 , struct V_3 * V_4 )
{
struct V_17 * V_18 = & V_4 -> V_9 ;
unsigned int V_51 = F_4 ( V_18 ) ;
switch ( V_51 & V_52 ) {
case V_53 :
switch ( V_51 ) {
case 0x000 :
if ( ! ( V_18 -> V_10 & 0x0000F000ULL ) )
break;
if ( ! ( V_18 -> V_10 & 0x00000F00ULL ) )
break;
return & V_54 ;
case 0x004 :
if ( F_23 ( V_18 -> V_10 & V_55 ) <= 1 )
break;
return & V_54 ;
case 0x003 :
case 0x00B :
case 0x00D :
return & V_54 ;
}
return & V_56 ;
case V_57 :
case V_58 :
case V_59 :
switch ( V_51 ) {
case 0x023 :
case 0x043 :
case 0x045 :
case 0x046 :
case 0x054 :
case 0x055 :
return & V_60 ;
case 0x02D :
return & V_54 ;
case 0x02E :
return & V_61 ;
default:
return & V_62 ;
}
case V_63 :
case V_64 :
case V_65 :
switch ( V_51 ) {
case 0x08F :
case 0x187 :
case 0x188 :
return & V_66 ;
case 0x0DB ... 0x0DF :
case 0x1D6 :
case 0x1D8 :
return & V_62 ;
default:
return & V_60 ;
}
case V_67 :
return & V_37 ;
default:
return & V_37 ;
}
}
T_2 int F_24 ( void )
{
if ( V_43 . V_68 < 6 )
return - V_69 ;
switch ( V_43 . V_68 ) {
case 0x15 :
if ( ! V_70 )
return - V_69 ;
V_25 = V_71 ;
break;
default:
if ( V_70 )
return - V_69 ;
V_25 = V_72 ;
break;
}
memcpy ( V_73 , V_74 ,
sizeof( V_73 ) ) ;
return 0 ;
}
