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
V_13 = F_8 ( V_15 , V_16 , 0 , L_2 ,
V_16 ) ;
if ( V_13 ) goto V_14;
V_17 = V_18 ;
V_14:
F_3 ( V_4 ) ;
return V_13 ;
}
static int F_7 ( void )
{
unsigned char V_19 ;
V_11 [ V_20 ] = ( V_11 [ V_20 ] | V_21 | V_22 ) & ~ V_23 ;
V_11 [ V_24 ] |= V_25 ;
V_26 = V_11 [ V_24 ] & ( V_27 | V_23 ) ;
V_11 [ V_28 ] = ( V_11 [ V_28 ] & ~ V_29 ) | V_30 ;
V_19 = V_11 [ V_31 ] ;
return 0 ;
}
static void F_9 ( void )
{
int V_32 ;
int V_33 ;
static struct V_1 V_2 ;
if ( ! V_34 ) return;
V_32 = ( 1 << ( ( ( V_35 & 0xF0 ) >> 4 ) + 1 ) ) - 1 ;
if ( V_34 & ~ V_32 )
V_33 = F_10 ( V_34 & ~ V_32 ) - 1 ;
else
V_33 = F_10 ( V_34 ) - 1 ;
F_11 ( F_1 ( & V_2 ) ) ;
V_1 ( & V_2 , NULL , V_36 , 1 ,
F_12 ( V_33 , 0 ) ) ;
V_2 . V_37 = 0 ;
V_2 . V_38 = 0 ;
V_2 . V_39 = 0 ;
V_2 . V_6 = V_5 ;
if ( V_5 != NULL ) {
V_5 = & V_2 ;
} else {
V_5 = & V_2 ;
V_40 = & V_2 ;
}
}
static int F_13 ( struct V_1 * V_2 , int V_41 )
{
int V_13 ;
unsigned long V_4 ;
F_11 ( F_1 ( V_2 ) ) ;
F_2 ( V_4 ) ;
V_13 = F_14 ( V_2 ) ;
F_3 ( V_4 ) ;
if ( ! V_13 && V_41 ) {
while ( ! V_2 -> V_38 ) {
F_15 () ;
}
F_11 ( F_1 ( V_2 ) ) ;
}
return V_13 ;
}
static int F_14 ( struct V_1 * V_2 )
{
if ( V_2 -> V_42 < 2 || V_2 -> V_43 [ 0 ] != V_44 || V_2 -> V_42 > 15 ) {
V_2 -> V_38 = 1 ;
return - V_45 ;
}
V_2 -> V_6 = NULL ;
V_2 -> V_37 = 0 ;
V_2 -> V_38 = 0 ;
V_2 -> V_39 = 0 ;
if ( V_5 != NULL ) {
V_40 -> V_6 = V_2 ;
V_40 = V_2 ;
} else {
V_5 = V_2 ;
V_40 = V_2 ;
if ( V_17 == V_18 ) F_16 () ;
}
return 0 ;
}
static int F_17 ( int V_46 )
{
static struct V_1 V_2 ;
unsigned long V_4 ;
int V_13 = 0 ;
V_34 = V_46 & 0xFFFE ;
if ( ! V_34 ) return 0 ;
F_2 ( V_4 ) ;
if ( V_5 == NULL ) {
V_1 ( & V_2 , NULL , V_36 , 1 ,
F_12 ( F_10 ( V_34 ) - 1 , 0 ) ) ;
V_13 = F_14 ( & V_2 ) ;
}
F_3 ( V_4 ) ;
return V_13 ;
}
static inline int F_18 ( void ) {
if ( ( V_35 & 0x0F ) == 0x0C &&
( ( 1 << ( ( V_35 & 0xF0 ) >> 4 ) ) & V_34 ) )
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
V_1 ( & V_2 , NULL , 0 , 1 , V_47 ) ;
F_22 ( 3000 ) ;
return 0 ;
}
static void F_16 ( void )
{
struct V_1 * V_2 ;
V_2 = V_5 ;
F_11 ( V_2 == NULL ) ;
F_11 ( V_17 != V_18 ) ;
V_35 = V_2 -> V_43 [ 1 ] ;
V_11 [ V_28 ] |= V_48 ;
V_11 [ V_31 ] = V_2 -> V_43 [ 1 ] ;
V_11 [ V_24 ] = ( V_11 [ V_24 ] & ~ V_27 ) | V_49 ;
V_17 = V_50 ;
V_51 = 2 ;
}
static T_1 V_16 ( int V_52 , void * V_53 )
{
int V_19 ;
static int V_54 ;
struct V_1 * V_2 ;
if ( ! V_53 ) {
if ( V_11 [ V_55 ] & V_56 )
V_11 [ V_55 ] = V_56 ;
else
return V_57 ;
}
F_11 ( V_54 ++ ) ;
V_26 = V_58 ;
V_58 = V_11 [ V_24 ] & ( V_27 | V_23 ) ;
switch ( V_17 ) {
case V_18 :
if ( V_59 ) {
V_60 = V_5 -> V_61 ;
} else {
F_11 ( V_5 != NULL ) ;
V_60 = V_62 ;
}
V_19 = V_11 [ V_31 ] ;
if ( ( V_58 & V_23 ) && ( V_19 == 0xFF ) ) {
V_39 = 0 ;
V_63 = 0 ;
V_17 = V_64 ;
} else {
V_17 = V_65 ;
* V_60 = V_19 ;
V_39 = 1 ;
}
V_11 [ V_24 ] = ( V_11 [ V_24 ] & ~ V_27 ) | V_21 ;
break;
case V_50 :
V_2 = V_5 ;
if ( V_51 >= V_2 -> V_42 ) {
V_2 -> V_37 = 1 ;
V_17 = V_18 ;
if ( V_2 -> V_66 ) {
V_59 = 1 ;
} else {
V_2 -> V_38 = 1 ;
V_5 = V_2 -> V_6 ;
if ( V_2 -> V_67 ) (* V_2 -> V_67 )( V_2 ) ;
if ( V_5 )
F_16 () ;
else
if ( F_18 () )
F_17 ( V_34 ) ;
}
if ( V_17 == V_18 ) {
V_11 [ V_28 ] &= ~ V_48 ;
V_19 = V_11 [ V_31 ] ;
V_11 [ V_24 ] = ( V_11 [ V_24 ] & ~ V_27 ) | V_25 ;
}
} else {
V_11 [ V_31 ] = V_2 -> V_43 [ V_51 ++ ] ;
if ( ( V_11 [ V_24 ] & V_27 ) == V_49 ) {
V_11 [ V_24 ] = ( V_11 [ V_24 ] & ~ V_27 ) | V_21 ;
} else {
V_11 [ V_24 ] ^= V_27 ;
}
}
break;
case V_65 :
V_19 = V_11 [ V_31 ] ;
F_11 ( ( V_58 & V_27 ) == V_49 ||
( V_58 & V_27 ) == V_25 ) ;
V_63 = 0 ;
if ( ! ( V_58 & V_23 ) ) {
if ( V_19 == 0xFF ) {
if ( ! ( V_26 & V_23 ) ) {
V_17 = V_64 ;
V_39 = 0 ;
V_63 = 1 ;
}
} else if ( V_19 == 0x00 ) {
V_17 = V_64 ;
if ( ! ( V_26 & V_23 ) )
V_63 = 1 ;
}
}
if ( V_17 == V_65 ) {
F_11 ( V_39 > 15 ) ;
V_60 ++ ;
* V_60 = V_19 ;
V_39 ++ ;
}
V_11 [ V_24 ] ^= V_27 ;
break;
case V_64 :
V_19 = V_11 [ V_31 ] ;
if ( V_59 ) {
V_59 = 0 ;
V_2 = V_5 ;
V_2 -> V_39 = V_39 ;
V_2 -> V_38 = 1 ;
V_5 = V_2 -> V_6 ;
if ( V_2 -> V_67 ) (* V_2 -> V_67 )( V_2 ) ;
} else if ( V_39 && V_34 )
F_23 ( V_62 , V_39 , 0 ) ;
V_17 = V_18 ;
if ( V_63 )
F_9 () ;
if ( V_5 )
F_16 () ;
else
if ( F_18 () )
F_17 ( V_34 ) ;
if ( V_17 == V_18 )
V_11 [ V_24 ] = ( V_11 [ V_24 ] & ~ V_27 ) | V_25 ;
break;
default:
break;
}
V_54 -- ;
return V_68 ;
}
