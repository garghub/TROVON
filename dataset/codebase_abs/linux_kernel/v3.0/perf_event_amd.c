static T_1 F_1 ( int V_1 )
{
return V_2 [ V_1 ] ;
}
static int F_2 ( struct V_3 * V_4 )
{
int V_5 = F_3 ( V_4 ) ;
if ( V_5 )
return V_5 ;
if ( V_4 -> V_6 . type != V_7 )
return 0 ;
V_4 -> V_8 . V_9 |= V_4 -> V_6 . V_9 & V_10 ;
return 0 ;
}
static inline unsigned int F_4 ( struct V_11 * V_12 )
{
return ( ( V_12 -> V_9 >> 24 ) & 0x0f00 ) | ( V_12 -> V_9 & 0x00ff ) ;
}
static inline int F_5 ( struct V_11 * V_12 )
{
return ( V_12 -> V_9 & 0xe0 ) == 0xe0 ;
}
static inline int F_6 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_15 ;
return V_16 && V_16 -> V_17 != - 1 ;
}
static void F_7 ( struct V_13 * V_14 ,
struct V_3 * V_4 )
{
struct V_11 * V_12 = & V_4 -> V_8 ;
struct V_15 * V_16 = V_14 -> V_15 ;
int V_18 ;
if ( ! ( F_6 ( V_14 ) && F_5 ( V_12 ) ) )
return;
for ( V_18 = 0 ; V_18 < V_19 . V_20 ; V_18 ++ ) {
if ( V_16 -> V_21 [ V_18 ] == V_4 ) {
F_8 ( V_16 -> V_21 + V_18 , V_4 , NULL ) ;
break;
}
}
}
static struct V_22 *
F_9 ( struct V_13 * V_14 , struct V_3 * V_4 )
{
struct V_11 * V_12 = & V_4 -> V_8 ;
struct V_15 * V_16 = V_14 -> V_15 ;
struct V_3 * V_23 = NULL ;
int V_24 = V_19 . V_20 ;
int V_18 , V_25 , V_26 = - 1 ;
if ( ! ( F_6 ( V_14 ) && F_5 ( V_12 ) ) )
return & V_27 ;
for ( V_18 = 0 ; V_18 < V_24 ; V_18 ++ ) {
if ( V_26 == - 1 && ! V_16 -> V_21 [ V_18 ] )
V_26 = V_18 ;
if ( V_16 -> V_21 [ V_18 ] == V_4 )
goto V_28;
}
if ( V_12 -> V_29 != - 1 ) {
V_18 = V_12 -> V_29 ;
} else if ( V_26 != - 1 ) {
V_18 = V_26 ;
} else {
V_18 = 0 ;
}
V_25 = V_18 ;
do {
V_23 = F_8 ( V_16 -> V_21 + V_18 , NULL , V_4 ) ;
if ( ! V_23 )
break;
if ( ++ V_18 == V_24 )
V_18 = 0 ;
} while ( V_18 != V_25 );
V_28:
if ( ! V_23 )
return & V_16 -> V_30 [ V_18 ] ;
return & V_31 ;
}
static struct V_15 * F_10 ( int V_32 )
{
struct V_15 * V_16 ;
int V_18 ;
V_16 = F_11 ( sizeof( struct V_15 ) , V_33 | V_34 ,
F_12 ( V_32 ) ) ;
if ( ! V_16 )
return NULL ;
V_16 -> V_17 = - 1 ;
for ( V_18 = 0 ; V_18 < V_19 . V_20 ; V_18 ++ ) {
F_13 ( V_18 , V_16 -> V_30 [ V_18 ] . V_35 ) ;
V_16 -> V_30 [ V_18 ] . V_36 = 1 ;
}
return V_16 ;
}
static int F_14 ( int V_32 )
{
struct V_13 * V_14 = & F_15 ( V_13 , V_32 ) ;
F_16 ( V_14 -> V_15 ) ;
if ( V_37 . V_38 < 2 )
return V_39 ;
V_14 -> V_15 = F_10 ( V_32 ) ;
if ( ! V_14 -> V_15 )
return V_40 ;
return V_39 ;
}
static void F_17 ( int V_32 )
{
struct V_13 * V_14 = & F_15 ( V_13 , V_32 ) ;
struct V_15 * V_16 ;
int V_18 , V_17 ;
if ( V_37 . V_38 < 2 )
return;
V_17 = F_18 ( V_32 ) ;
F_16 ( V_17 == V_41 ) ;
F_19 (i) {
V_16 = F_15 ( V_13 , V_18 ) . V_15 ;
if ( F_16 ( ! V_16 ) )
continue;
if ( V_16 -> V_17 == V_17 ) {
F_20 ( V_14 -> V_15 ) ;
V_14 -> V_15 = V_16 ;
break;
}
}
V_14 -> V_15 -> V_17 = V_17 ;
V_14 -> V_15 -> V_42 ++ ;
}
static void F_21 ( int V_32 )
{
struct V_13 * V_43 ;
if ( V_37 . V_38 < 2 )
return;
V_43 = & F_15 ( V_13 , V_32 ) ;
if ( V_43 -> V_15 ) {
struct V_15 * V_16 = V_43 -> V_15 ;
if ( V_16 -> V_17 == - 1 || -- V_16 -> V_42 == 0 )
F_20 ( V_16 ) ;
V_43 -> V_15 = NULL ;
}
}
static struct V_22 *
F_22 ( struct V_13 * V_14 , struct V_3 * V_4 )
{
struct V_11 * V_12 = & V_4 -> V_8 ;
unsigned int V_44 = F_4 ( V_12 ) ;
switch ( V_44 & V_45 ) {
case V_46 :
switch ( V_44 ) {
case 0x000 :
if ( ! ( V_12 -> V_9 & 0x0000F000ULL ) )
break;
if ( ! ( V_12 -> V_9 & 0x00000F00ULL ) )
break;
return & V_47 ;
case 0x004 :
if ( F_23 ( V_12 -> V_9 & V_48 ) <= 1 )
break;
return & V_47 ;
case 0x003 :
case 0x00B :
case 0x00D :
return & V_47 ;
}
return & V_49 ;
case V_50 :
case V_51 :
case V_52 :
switch ( V_44 ) {
case 0x023 :
case 0x043 :
case 0x045 :
case 0x046 :
case 0x054 :
case 0x055 :
return & V_53 ;
case 0x02D :
return & V_47 ;
case 0x02E :
return & V_54 ;
default:
return & V_55 ;
}
case V_56 :
case V_57 :
case V_58 :
switch ( V_44 ) {
case 0x08F :
case 0x187 :
case 0x188 :
return & V_59 ;
case 0x0DB ... 0x0DF :
case 0x1D6 :
case 0x1D8 :
return & V_55 ;
default:
return & V_53 ;
}
case V_60 :
return & V_31 ;
default:
return & V_31 ;
}
}
static T_2 int F_24 ( void )
{
if ( V_37 . V_61 < 6 )
return - V_62 ;
switch ( V_37 . V_61 ) {
case 0x15 :
if ( ! V_63 )
return - V_62 ;
V_19 = V_64 ;
break;
default:
if ( V_63 )
return - V_62 ;
V_19 = V_65 ;
break;
}
memcpy ( V_66 , V_67 ,
sizeof( V_66 ) ) ;
return 0 ;
}
static int F_24 ( void )
{
return 0 ;
}
