static int F_1 ( struct V_1 * V_2 ) {
struct V_1 * V_3 ;
unsigned long V_4 ;
F_2 ( V_4 ) ;
V_3 = V_5 ;
while ( V_3 ) {
if ( V_3 == V_2 ) {
F_3 ( V_4 ) ;
return 1 ;
}
V_3 = V_3 -> V_6 ;
}
F_3 ( V_4 ) ;
return 0 ;
}
static int F_4 ( void )
{
if ( V_7 -> V_8 != V_9 ) return - V_10 ;
V_11 = V_12 ;
F_5 ( L_1 ) ;
return 0 ;
}
int F_6 ( void )
{
unsigned long V_4 ;
int V_13 ;
F_2 ( V_4 ) ;
V_13 = F_7 () ;
if ( V_13 ) goto V_14;
V_13 = F_8 ( V_15 , V_16 , V_17 , L_2 ,
V_16 ) ;
if ( V_13 ) goto V_14;
V_18 = V_19 ;
V_14:
F_3 ( V_4 ) ;
return V_13 ;
}
static int F_7 ( void )
{
unsigned char V_20 ;
V_11 [ V_21 ] = ( V_11 [ V_21 ] | V_22 | V_23 ) & ~ V_24 ;
V_11 [ V_25 ] |= V_26 ;
V_27 = V_11 [ V_25 ] & ( V_28 | V_24 ) ;
V_11 [ V_29 ] = ( V_11 [ V_29 ] & ~ V_30 ) | V_31 ;
V_20 = V_11 [ V_32 ] ;
return 0 ;
}
static void F_9 ( void )
{
int V_33 ;
int V_34 ;
static struct V_1 V_2 ;
if ( ! V_35 ) return;
V_33 = ( 1 << ( ( ( V_36 & 0xF0 ) >> 4 ) + 1 ) ) - 1 ;
if ( V_35 & ~ V_33 )
V_34 = F_10 ( V_35 & ~ V_33 ) - 1 ;
else
V_34 = F_10 ( V_35 ) - 1 ;
F_11 ( F_1 ( & V_2 ) ) ;
V_1 ( & V_2 , NULL , V_37 , 1 ,
F_12 ( V_34 , 0 ) ) ;
V_2 . V_38 = 0 ;
V_2 . V_39 = 0 ;
V_2 . V_40 = 0 ;
V_2 . V_6 = V_5 ;
if ( V_5 != NULL ) {
V_5 = & V_2 ;
} else {
V_5 = & V_2 ;
V_41 = & V_2 ;
}
}
static int F_13 ( struct V_1 * V_2 , int V_42 )
{
int V_13 ;
unsigned long V_4 ;
F_11 ( F_1 ( V_2 ) ) ;
F_2 ( V_4 ) ;
V_13 = F_14 ( V_2 ) ;
F_3 ( V_4 ) ;
if ( ! V_13 && V_42 ) {
while ( ! V_2 -> V_39 ) {
F_15 () ;
}
F_11 ( F_1 ( V_2 ) ) ;
}
return V_13 ;
}
static int F_14 ( struct V_1 * V_2 )
{
if ( V_2 -> V_43 < 2 || V_2 -> V_44 [ 0 ] != V_45 || V_2 -> V_43 > 15 ) {
V_2 -> V_39 = 1 ;
return - V_46 ;
}
V_2 -> V_6 = NULL ;
V_2 -> V_38 = 0 ;
V_2 -> V_39 = 0 ;
V_2 -> V_40 = 0 ;
if ( V_5 != NULL ) {
V_41 -> V_6 = V_2 ;
V_41 = V_2 ;
} else {
V_5 = V_2 ;
V_41 = V_2 ;
if ( V_18 == V_19 ) F_16 () ;
}
return 0 ;
}
static int F_17 ( int V_47 )
{
static struct V_1 V_2 ;
unsigned long V_4 ;
int V_13 = 0 ;
V_35 = V_47 & 0xFFFE ;
if ( ! V_35 ) return 0 ;
F_2 ( V_4 ) ;
if ( V_5 == NULL ) {
V_1 ( & V_2 , NULL , V_37 , 1 ,
F_12 ( F_10 ( V_35 ) - 1 , 0 ) ) ;
V_13 = F_14 ( & V_2 ) ;
}
F_3 ( V_4 ) ;
return V_13 ;
}
static inline int F_18 ( void ) {
if ( ( V_36 & 0x0F ) == 0x0C &&
( ( 1 << ( ( V_36 & 0xF0 ) >> 4 ) ) & V_35 ) )
return 0 ;
return 1 ;
}
static void F_15 ( void )
{
F_19 ( V_15 ) ;
V_16 ( 0 , NULL ) ;
F_20 ( V_15 ) ;
}
static int F_21 ( void )
{
static struct V_1 V_2 ;
if ( F_1 ( & V_2 ) )
return 0 ;
V_1 ( & V_2 , NULL , 0 , 1 , V_48 ) ;
F_22 ( 3000 ) ;
return 0 ;
}
static void F_16 ( void )
{
struct V_1 * V_2 ;
V_2 = V_5 ;
F_11 ( V_2 == NULL ) ;
F_11 ( V_18 != V_19 ) ;
V_36 = V_2 -> V_44 [ 1 ] ;
V_11 [ V_29 ] |= V_49 ;
V_11 [ V_32 ] = V_2 -> V_44 [ 1 ] ;
V_11 [ V_25 ] = ( V_11 [ V_25 ] & ~ V_28 ) | V_50 ;
V_18 = V_51 ;
V_52 = 2 ;
}
static T_1 V_16 ( int V_53 , void * V_54 )
{
int V_20 ;
static int V_55 ;
struct V_1 * V_2 ;
if ( ! V_54 ) {
if ( V_11 [ V_56 ] & V_57 )
V_11 [ V_56 ] = V_57 ;
else
return V_58 ;
}
F_11 ( V_55 ++ ) ;
V_27 = V_59 ;
V_59 = V_11 [ V_25 ] & ( V_28 | V_24 ) ;
switch ( V_18 ) {
case V_19 :
if ( V_60 ) {
V_61 = V_5 -> V_62 ;
} else {
F_11 ( V_5 != NULL ) ;
V_61 = V_63 ;
}
V_20 = V_11 [ V_32 ] ;
if ( ( V_59 & V_24 ) && ( V_20 == 0xFF ) ) {
V_40 = 0 ;
V_64 = 0 ;
V_18 = V_65 ;
} else {
V_18 = V_66 ;
* V_61 = V_20 ;
V_40 = 1 ;
}
V_11 [ V_25 ] = ( V_11 [ V_25 ] & ~ V_28 ) | V_22 ;
break;
case V_51 :
V_2 = V_5 ;
if ( V_52 >= V_2 -> V_43 ) {
V_2 -> V_38 = 1 ;
V_18 = V_19 ;
if ( V_2 -> V_67 ) {
V_60 = 1 ;
} else {
V_2 -> V_39 = 1 ;
V_5 = V_2 -> V_6 ;
if ( V_2 -> V_68 ) (* V_2 -> V_68 )( V_2 ) ;
if ( V_5 )
F_16 () ;
else
if ( F_18 () )
F_17 ( V_35 ) ;
}
if ( V_18 == V_19 ) {
V_11 [ V_29 ] &= ~ V_49 ;
V_20 = V_11 [ V_32 ] ;
V_11 [ V_25 ] = ( V_11 [ V_25 ] & ~ V_28 ) | V_26 ;
}
} else {
V_11 [ V_32 ] = V_2 -> V_44 [ V_52 ++ ] ;
if ( ( V_11 [ V_25 ] & V_28 ) == V_50 ) {
V_11 [ V_25 ] = ( V_11 [ V_25 ] & ~ V_28 ) | V_22 ;
} else {
V_11 [ V_25 ] ^= V_28 ;
}
}
break;
case V_66 :
V_20 = V_11 [ V_32 ] ;
F_11 ( ( V_59 & V_28 ) == V_50 ||
( V_59 & V_28 ) == V_26 ) ;
V_64 = 0 ;
if ( ! ( V_59 & V_24 ) ) {
if ( V_20 == 0xFF ) {
if ( ! ( V_27 & V_24 ) ) {
V_18 = V_65 ;
V_40 = 0 ;
V_64 = 1 ;
}
} else if ( V_20 == 0x00 ) {
V_18 = V_65 ;
if ( ! ( V_27 & V_24 ) )
V_64 = 1 ;
}
}
if ( V_18 == V_66 ) {
F_11 ( V_40 > 15 ) ;
V_61 ++ ;
* V_61 = V_20 ;
V_40 ++ ;
}
V_11 [ V_25 ] ^= V_28 ;
break;
case V_65 :
V_20 = V_11 [ V_32 ] ;
if ( V_60 ) {
V_60 = 0 ;
V_2 = V_5 ;
V_2 -> V_40 = V_40 ;
V_2 -> V_39 = 1 ;
V_5 = V_2 -> V_6 ;
if ( V_2 -> V_68 ) (* V_2 -> V_68 )( V_2 ) ;
} else if ( V_40 && V_35 )
F_23 ( V_63 , V_40 , 0 ) ;
V_18 = V_19 ;
if ( V_64 )
F_9 () ;
if ( V_5 )
F_16 () ;
else
if ( F_18 () )
F_17 ( V_35 ) ;
if ( V_18 == V_19 )
V_11 [ V_25 ] = ( V_11 [ V_25 ] & ~ V_28 ) | V_26 ;
break;
default:
break;
}
V_55 -- ;
return V_69 ;
}
