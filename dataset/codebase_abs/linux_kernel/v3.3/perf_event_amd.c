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
V_20 -> V_47 = V_14 ;
if ( V_43 . V_44 < 2 || V_43 . V_48 == 0x15 )
return;
V_23 = F_18 ( V_38 ) ;
F_16 ( V_23 == V_49 ) ;
F_19 (i) {
V_22 = F_15 ( V_19 , V_24 ) . V_21 ;
if ( F_16 ( ! V_22 ) )
continue;
if ( V_22 -> V_23 == V_23 ) {
V_20 -> V_50 = V_20 -> V_21 ;
V_20 -> V_21 = V_22 ;
break;
}
}
V_20 -> V_21 -> V_23 = V_23 ;
V_20 -> V_21 -> V_51 ++ ;
}
static void F_20 ( int V_38 )
{
struct V_19 * V_52 ;
if ( V_43 . V_44 < 2 )
return;
V_52 = & F_15 ( V_19 , V_38 ) ;
if ( V_52 -> V_21 ) {
struct V_21 * V_22 = V_52 -> V_21 ;
if ( V_22 -> V_23 == - 1 || -- V_22 -> V_51 == 0 )
F_21 ( V_22 ) ;
V_52 -> V_21 = NULL ;
}
}
static struct V_28 *
F_22 ( struct V_19 * V_20 , struct V_3 * V_4 )
{
struct V_17 * V_18 = & V_4 -> V_9 ;
unsigned int V_53 = F_4 ( V_18 ) ;
switch ( V_53 & V_54 ) {
case V_55 :
switch ( V_53 ) {
case 0x000 :
if ( ! ( V_18 -> V_10 & 0x0000F000ULL ) )
break;
if ( ! ( V_18 -> V_10 & 0x00000F00ULL ) )
break;
return & V_56 ;
case 0x004 :
if ( F_23 ( V_18 -> V_10 & V_57 ) <= 1 )
break;
return & V_56 ;
case 0x003 :
case 0x00B :
case 0x00D :
return & V_56 ;
}
return & V_58 ;
case V_59 :
case V_60 :
case V_61 :
switch ( V_53 ) {
case 0x023 :
case 0x043 :
case 0x045 :
case 0x046 :
case 0x054 :
case 0x055 :
return & V_62 ;
case 0x02D :
return & V_56 ;
case 0x02E :
return & V_63 ;
default:
return & V_64 ;
}
case V_65 :
case V_66 :
case V_67 :
switch ( V_53 ) {
case 0x08F :
case 0x187 :
case 0x188 :
return & V_68 ;
case 0x0DB ... 0x0DF :
case 0x1D6 :
case 0x1D8 :
return & V_64 ;
default:
return & V_62 ;
}
case V_69 :
return & V_37 ;
default:
return & V_37 ;
}
}
T_2 int F_24 ( void )
{
if ( V_43 . V_48 < 6 )
return - V_70 ;
switch ( V_43 . V_48 ) {
case 0x15 :
if ( ! V_71 )
return - V_70 ;
V_25 = V_72 ;
break;
default:
if ( V_71 )
return - V_70 ;
V_25 = V_73 ;
break;
}
memcpy ( V_74 , V_75 ,
sizeof( V_74 ) ) ;
return 0 ;
}
void F_25 ( void )
{
struct V_19 * V_20 = & F_26 ( V_19 ) ;
V_20 -> V_47 = 0 ;
F_27 () ;
F_28 ( 0 ) ;
}
void F_29 ( void )
{
struct V_19 * V_20 = & F_26 ( V_19 ) ;
V_20 -> V_47 = V_14 ;
F_27 () ;
F_28 ( 0 ) ;
}
