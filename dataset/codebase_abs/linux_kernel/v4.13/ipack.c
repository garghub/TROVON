static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_1 = F_2 ( V_2 ) ;
F_3 ( V_1 -> V_4 ) ;
V_1 -> V_5 ( V_1 ) ;
}
static inline const struct V_6 *
F_4 ( const struct V_6 * V_4 ,
const struct V_3 * V_1 )
{
if ( ( V_4 -> V_7 == V_8 ||
V_4 -> V_7 == V_1 -> V_9 ) &&
( V_4 -> V_10 == V_11 || V_4 -> V_10 == V_1 -> V_12 ) &&
( V_4 -> V_1 == V_11 || V_4 -> V_1 == V_1 -> V_13 ) )
return V_4 ;
return NULL ;
}
static const struct V_6 *
F_5 ( const struct V_6 * V_14 , struct V_3 * V_15 )
{
if ( V_14 ) {
while ( V_14 -> V_10 || V_14 -> V_1 ) {
if ( F_4 ( V_14 , V_15 ) )
return V_14 ;
V_14 ++ ;
}
}
return NULL ;
}
static int F_6 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
struct V_3 * V_15 = F_2 ( V_2 ) ;
struct V_18 * V_19 = F_7 ( V_17 ) ;
const struct V_6 * V_20 ;
V_20 = F_5 ( V_19 -> V_21 , V_15 ) ;
return V_20 ? 1 : 0 ;
}
static int F_8 ( struct V_1 * V_1 )
{
struct V_3 * V_2 = F_2 ( V_1 ) ;
struct V_18 * V_17 = F_7 ( V_1 -> V_22 ) ;
if ( ! V_17 -> V_23 -> V_24 )
return - V_25 ;
return V_17 -> V_23 -> V_24 ( V_2 ) ;
}
static int F_9 ( struct V_1 * V_1 )
{
struct V_3 * V_2 = F_2 ( V_1 ) ;
struct V_18 * V_17 = F_7 ( V_1 -> V_22 ) ;
if ( ! V_17 -> V_23 -> remove )
return - V_25 ;
V_17 -> V_23 -> remove ( V_2 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
struct V_3 * V_15 ;
if ( ! V_2 )
return - V_28 ;
V_15 = F_2 ( V_2 ) ;
if ( F_11 ( V_27 ,
L_1 , V_15 -> V_9 ,
V_15 -> V_12 , V_15 -> V_13 ) )
return - V_29 ;
return 0 ;
}
static T_1 F_12 ( struct V_1 * V_2 ,
struct V_30 * V_31 , char * V_32 )
{
unsigned int V_33 , V_34 , V_35 , V_36 ;
struct V_3 * V_15 = F_2 ( V_2 ) ;
switch ( V_15 -> V_9 ) {
case V_37 :
V_35 = 0x7 ; V_36 = 1 ; break;
case V_38 :
V_35 = 0xf ; V_36 = 2 ; break;
default:
return - V_39 ;
}
V_34 = 0 ;
for ( V_33 = 0 ; V_33 < V_15 -> V_40 ; V_33 ++ ) {
if ( V_33 > 0 ) {
if ( ( V_33 & V_35 ) == 0 )
V_32 [ V_34 ++ ] = '\n' ;
else if ( ( V_33 & V_36 ) == 0 )
V_32 [ V_34 ++ ] = ' ' ;
}
sprintf ( & V_32 [ V_34 ] , L_2 , V_15 -> V_4 [ V_33 ] ) ;
V_34 += 2 ;
}
V_32 [ V_34 ++ ] = '\n' ;
return V_34 ;
}
static T_1
F_13 ( struct V_1 * V_2 , struct V_30 * V_31 , char * V_32 )
{
struct V_3 * V_15 = F_2 ( V_2 ) ;
switch ( V_15 -> V_9 ) {
case V_37 :
return sprintf ( V_32 , L_3 , V_15 -> V_12 ) ;
case V_38 :
return sprintf ( V_32 , L_4 , V_15 -> V_12 ) ;
default:
return - V_39 ;
}
}
static T_1
F_14 ( struct V_1 * V_2 , struct V_30 * V_31 , char * V_32 )
{
struct V_3 * V_15 = F_2 ( V_2 ) ;
switch ( V_15 -> V_9 ) {
case V_37 :
return sprintf ( V_32 , L_3 , V_15 -> V_13 ) ;
case V_38 :
return sprintf ( V_32 , L_5 , V_15 -> V_13 ) ;
default:
return - V_39 ;
}
}
static T_1 F_15 ( struct V_1 * V_2 , struct V_30 * V_31 ,
char * V_32 )
{
struct V_3 * V_15 = F_2 ( V_2 ) ;
return sprintf ( V_32 , L_6 , V_15 -> V_9 ,
V_15 -> V_12 , V_15 -> V_13 ) ;
}
struct V_41 * F_16 ( struct V_1 * V_42 , int V_43 ,
const struct V_44 * V_23 ,
struct V_45 * V_46 )
{
int V_47 ;
struct V_41 * V_48 ;
V_48 = F_17 ( sizeof( * V_48 ) , V_49 ) ;
if ( ! V_48 )
return NULL ;
V_47 = F_18 ( & V_50 , 0 , 0 , V_49 ) ;
if ( V_47 < 0 ) {
F_3 ( V_48 ) ;
return NULL ;
}
V_48 -> V_47 = V_47 ;
V_48 -> V_42 = V_42 ;
V_48 -> V_43 = V_43 ;
V_48 -> V_23 = V_23 ;
V_48 -> V_46 = V_46 ;
return V_48 ;
}
static int F_19 ( struct V_1 * V_2 , void * V_51 )
{
struct V_3 * V_15 = F_2 ( V_2 ) ;
struct V_41 * V_48 = V_51 ;
if ( V_15 -> V_48 == V_48 )
F_20 ( V_15 ) ;
return 1 ;
}
int F_21 ( struct V_41 * V_48 )
{
F_22 ( & V_52 , NULL , V_48 ,
F_19 ) ;
F_23 ( & V_50 , V_48 -> V_47 ) ;
F_3 ( V_48 ) ;
return 0 ;
}
int F_24 ( struct V_18 * V_53 , struct V_45 * V_46 ,
const char * V_54 )
{
V_53 -> V_22 . V_46 = V_46 ;
V_53 -> V_22 . V_54 = V_54 ;
V_53 -> V_22 . V_48 = & V_52 ;
return F_25 ( & V_53 -> V_22 ) ;
}
void F_26 ( struct V_18 * V_53 )
{
F_27 ( & V_53 -> V_22 ) ;
}
static T_2 F_28 ( T_2 V_55 , T_3 V_34 )
{
int V_33 ;
V_55 ^= V_34 << 8 ;
for ( V_33 = 0 ; V_33 < 8 ; V_33 ++ )
V_55 = ( V_55 << 1 ) ^ ( ( V_55 & 0x8000 ) ? 0x1021 : 0 ) ;
return V_55 ;
}
static T_3 F_29 ( struct V_3 * V_2 )
{
T_3 V_34 ;
T_2 V_55 ;
unsigned int V_33 ;
V_55 = 0xffff ;
for ( V_33 = 0 ; V_33 < V_2 -> V_40 ; V_33 ++ ) {
V_34 = ( V_33 != 11 ) ? V_2 -> V_4 [ V_33 ] : 0 ;
V_55 = F_28 ( V_55 , V_34 ) ;
}
V_55 = ~ V_55 ;
return V_55 & 0xff ;
}
static T_2 F_30 ( struct V_3 * V_2 )
{
T_3 V_34 ;
T_2 V_55 ;
unsigned int V_33 ;
V_55 = 0xffff ;
for ( V_33 = 0 ; V_33 < V_2 -> V_40 ; V_33 ++ ) {
V_34 = ( ( V_33 != 0x18 ) && ( V_33 != 0x19 ) ) ? V_2 -> V_4 [ V_33 ] : 0 ;
V_55 = F_28 ( V_55 , V_34 ) ;
}
V_55 = ~ V_55 ;
return V_55 ;
}
static void F_31 ( struct V_3 * V_2 )
{
T_3 * V_4 = V_2 -> V_4 ;
T_3 V_55 ;
V_2 -> V_12 = V_4 [ 4 ] ;
V_2 -> V_13 = V_4 [ 5 ] ;
V_2 -> V_56 = 1 ;
V_2 -> V_57 = ( V_4 [ 7 ] == 'H' ) ;
V_55 = F_29 ( V_2 ) ;
V_2 -> V_58 = ( V_55 == V_4 [ 11 ] ) ;
if ( ! V_2 -> V_58 ) {
F_32 ( & V_2 -> V_2 , L_7 ,
V_4 [ 11 ] , V_55 ) ;
}
}
static void F_33 ( struct V_3 * V_2 )
{
T_4 * V_4 = ( T_4 * ) V_2 -> V_4 ;
T_2 V_59 , V_55 ;
V_2 -> V_12 = ( ( F_34 ( V_4 [ 3 ] ) & 0xff ) << 16 )
+ F_34 ( V_4 [ 4 ] ) ;
V_2 -> V_13 = F_34 ( V_4 [ 5 ] ) ;
V_59 = F_34 ( V_4 [ 10 ] ) ;
V_2 -> V_56 = ! ! ( V_59 & 2 ) ;
V_2 -> V_57 = ! ! ( V_59 & 4 ) ;
V_55 = F_30 ( V_2 ) ;
V_2 -> V_58 = ( V_55 == F_34 ( V_4 [ 12 ] ) ) ;
if ( ! V_2 -> V_58 ) {
F_32 ( & V_2 -> V_2 , L_7 ,
V_4 [ 11 ] , V_55 ) ;
}
}
static int F_35 ( struct V_3 * V_2 )
{
T_3 T_5 * V_60 ;
int V_33 ;
int V_61 = 0 ;
V_60 = F_36 ( V_2 -> V_62 [ V_63 ] . V_64 ,
V_2 -> V_62 [ V_63 ] . V_65 ) ;
if ( ! V_60 ) {
F_37 ( & V_2 -> V_2 , L_8 ) ;
return - V_29 ;
}
if ( ( F_38 ( V_60 + 1 ) == 'I' ) &&
( F_38 ( V_60 + 3 ) == 'P' ) &&
( F_38 ( V_60 + 5 ) == 'A' ) &&
( ( F_38 ( V_60 + 7 ) == 'C' ) ||
( F_38 ( V_60 + 7 ) == 'H' ) ) ) {
V_2 -> V_9 = V_37 ;
V_2 -> V_40 = F_38 ( V_60 + 0x15 ) ;
if ( ( V_2 -> V_40 < 0x0c ) || ( V_2 -> V_40 > 0x40 ) ) {
F_32 ( & V_2 -> V_2 , L_9 ) ;
V_2 -> V_40 = 0x0c ;
}
} else if ( ( F_38 ( V_60 + 0 ) == 'I' ) &&
( F_38 ( V_60 + 1 ) == 'V' ) &&
( F_38 ( V_60 + 2 ) == 'A' ) &&
( F_38 ( V_60 + 3 ) == 'T' ) &&
( F_38 ( V_60 + 4 ) == ' ' ) &&
( F_38 ( V_60 + 5 ) == '4' ) ) {
V_2 -> V_9 = V_38 ;
V_2 -> V_40 = F_39 ( V_60 + 0x16 ) ;
if ( ( V_2 -> V_40 < 0x1a ) || ( V_2 -> V_40 > 0x40 ) ) {
F_32 ( & V_2 -> V_2 , L_9 ) ;
V_2 -> V_40 = 0x1a ;
}
} else {
V_2 -> V_9 = V_66 ;
V_2 -> V_40 = 0 ;
}
if ( ! V_2 -> V_40 ) {
V_61 = - V_28 ;
goto V_67;
}
V_2 -> V_4 = F_40 ( V_2 -> V_40 , V_49 ) ;
if ( ! V_2 -> V_4 ) {
V_61 = - V_29 ;
goto V_67;
}
for ( V_33 = 0 ; V_33 < V_2 -> V_40 ; V_33 ++ ) {
if ( V_2 -> V_9 == V_37 )
V_2 -> V_4 [ V_33 ] = F_38 ( V_60 + ( V_33 << 1 ) + 1 ) ;
else
V_2 -> V_4 [ V_33 ] = F_38 ( V_60 + V_33 ) ;
}
switch ( V_2 -> V_9 ) {
case V_37 :
F_31 ( V_2 ) ;
break;
case V_38 :
F_33 ( V_2 ) ;
break;
}
V_67:
F_41 ( V_60 ) ;
return V_61 ;
}
int F_42 ( struct V_3 * V_2 )
{
int V_61 ;
V_2 -> V_2 . V_48 = & V_52 ;
V_2 -> V_2 . V_5 = F_1 ;
V_2 -> V_2 . V_42 = V_2 -> V_48 -> V_42 ;
F_43 ( & V_2 -> V_2 ,
L_10 , V_2 -> V_48 -> V_47 , V_2 -> V_68 ) ;
F_44 ( & V_2 -> V_2 ) ;
if ( V_2 -> V_48 -> V_23 -> V_69 ( V_2 , 8 ) )
F_32 ( & V_2 -> V_2 , L_11 ) ;
if ( V_2 -> V_48 -> V_23 -> V_70 ( V_2 ) )
F_32 ( & V_2 -> V_2 , L_12 ) ;
V_61 = F_35 ( V_2 ) ;
if ( V_61 < 0 ) {
F_37 ( & V_2 -> V_2 , L_13 ) ;
return V_61 ;
}
if ( V_2 -> V_57 ) {
V_61 = V_2 -> V_48 -> V_23 -> V_69 ( V_2 , 32 ) ;
if ( V_61 < 0 )
F_37 ( & V_2 -> V_2 , L_14 ) ;
}
return 0 ;
}
int F_45 ( struct V_3 * V_2 )
{
return F_46 ( & V_2 -> V_2 ) ;
}
void F_20 ( struct V_3 * V_2 )
{
F_47 ( & V_2 -> V_2 ) ;
F_48 ( V_2 ) ;
}
void F_49 ( struct V_3 * V_2 )
{
F_50 ( & V_2 -> V_2 ) ;
}
void F_48 ( struct V_3 * V_2 )
{
F_51 ( & V_2 -> V_2 ) ;
}
static int T_6 F_52 ( void )
{
F_53 ( & V_50 ) ;
return F_54 ( & V_52 ) ;
}
static void T_7 F_55 ( void )
{
F_56 ( & V_52 ) ;
F_57 ( & V_50 ) ;
}
