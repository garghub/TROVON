static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_1 = F_2 ( V_2 ) ;
F_3 ( V_1 -> V_4 ) ;
F_3 ( V_1 ) ;
}
static inline const struct V_5 *
F_4 ( const struct V_5 * V_4 ,
const struct V_3 * V_1 )
{
if ( ( V_4 -> V_6 == V_7 ||
V_4 -> V_6 == V_1 -> V_8 ) &&
( V_4 -> V_9 == V_10 || V_4 -> V_9 == V_1 -> V_11 ) &&
( V_4 -> V_1 == V_10 || V_4 -> V_1 == V_1 -> V_12 ) )
return V_4 ;
return NULL ;
}
static const struct V_5 *
F_5 ( const struct V_5 * V_13 , struct V_3 * V_14 )
{
if ( V_13 ) {
while ( V_13 -> V_9 || V_13 -> V_1 ) {
if ( F_4 ( V_13 , V_14 ) )
return V_13 ;
V_13 ++ ;
}
}
return NULL ;
}
static int F_6 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_3 * V_14 = F_2 ( V_2 ) ;
struct V_17 * V_18 = F_7 ( V_16 ) ;
const struct V_5 * V_19 ;
V_19 = F_5 ( V_18 -> V_20 , V_14 ) ;
return V_19 ? 1 : 0 ;
}
static int F_8 ( struct V_1 * V_1 )
{
struct V_3 * V_2 = F_2 ( V_1 ) ;
struct V_17 * V_16 = F_7 ( V_1 -> V_21 ) ;
if ( ! V_16 -> V_22 -> V_23 )
return - V_24 ;
return V_16 -> V_22 -> V_23 ( V_2 ) ;
}
static int F_9 ( struct V_1 * V_1 )
{
struct V_3 * V_2 = F_2 ( V_1 ) ;
struct V_17 * V_16 = F_7 ( V_1 -> V_21 ) ;
if ( ! V_16 -> V_22 -> remove )
return - V_24 ;
V_16 -> V_22 -> remove ( V_2 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
struct V_3 * V_14 ;
if ( ! V_2 )
return - V_27 ;
V_14 = F_2 ( V_2 ) ;
if ( F_11 ( V_26 ,
L_1 , V_14 -> V_8 ,
V_14 -> V_11 , V_14 -> V_12 ) )
return - V_28 ;
return 0 ;
}
static T_1 F_12 ( struct V_1 * V_2 ,
struct V_29 * V_30 , char * V_31 )
{
unsigned int V_32 , V_33 , V_34 , V_35 ;
struct V_3 * V_14 = F_2 ( V_2 ) ;
switch ( V_14 -> V_8 ) {
case V_36 :
V_34 = 0x7 ; V_35 = 1 ; break;
case V_37 :
V_34 = 0xf ; V_35 = 2 ; break;
default:
return - V_38 ;
}
V_33 = 0 ;
for ( V_32 = 0 ; V_32 < V_14 -> V_39 ; V_32 ++ ) {
if ( V_32 > 0 ) {
if ( ( V_32 & V_34 ) == 0 )
V_31 [ V_33 ++ ] = '\n' ;
else if ( ( V_32 & V_35 ) == 0 )
V_31 [ V_33 ++ ] = ' ' ;
}
sprintf ( & V_31 [ V_33 ] , L_2 , V_14 -> V_4 [ V_32 ] ) ;
V_33 += 2 ;
}
V_31 [ V_33 ++ ] = '\n' ;
return V_33 ;
}
static T_1
F_13 ( struct V_1 * V_2 , struct V_29 * V_30 , char * V_31 )
{
struct V_3 * V_14 = F_2 ( V_2 ) ;
switch ( V_14 -> V_8 ) {
case V_36 :
return sprintf ( V_31 , L_3 , V_14 -> V_11 ) ;
case V_37 :
return sprintf ( V_31 , L_4 , V_14 -> V_11 ) ;
default:
return - V_38 ;
}
}
static T_1
F_14 ( struct V_1 * V_2 , struct V_29 * V_30 , char * V_31 )
{
struct V_3 * V_14 = F_2 ( V_2 ) ;
switch ( V_14 -> V_8 ) {
case V_36 :
return sprintf ( V_31 , L_3 , V_14 -> V_12 ) ;
case V_37 :
return sprintf ( V_31 , L_5 , V_14 -> V_12 ) ;
default:
return - V_38 ;
}
}
static T_1 F_15 ( struct V_1 * V_2 , struct V_29 * V_30 ,
char * V_31 )
{
struct V_3 * V_14 = F_2 ( V_2 ) ;
return sprintf ( V_31 , L_6 , V_14 -> V_8 ,
V_14 -> V_11 , V_14 -> V_12 ) ;
}
struct V_40 * F_16 ( struct V_1 * V_41 , int V_42 ,
const struct V_43 * V_22 )
{
int V_44 ;
struct V_40 * V_45 ;
V_45 = F_17 ( sizeof( struct V_40 ) , V_46 ) ;
if ( ! V_45 )
return NULL ;
V_44 = F_18 ( & V_47 , 0 , 0 , V_46 ) ;
if ( V_44 < 0 ) {
F_3 ( V_45 ) ;
return NULL ;
}
V_45 -> V_44 = V_44 ;
V_45 -> V_41 = V_41 ;
V_45 -> V_42 = V_42 ;
V_45 -> V_22 = V_22 ;
return V_45 ;
}
static int F_19 ( struct V_1 * V_2 , void * V_48 )
{
struct V_3 * V_14 = F_2 ( V_2 ) ;
struct V_40 * V_45 = V_48 ;
if ( V_14 -> V_44 == V_45 -> V_44 )
F_20 ( V_14 ) ;
return 1 ;
}
int F_21 ( struct V_40 * V_45 )
{
F_22 ( & V_49 , NULL , V_45 , F_19 ) ;
F_23 ( & V_47 , V_45 -> V_44 ) ;
F_3 ( V_45 ) ;
return 0 ;
}
int F_24 ( struct V_17 * V_50 , struct V_51 * V_52 ,
const char * V_53 )
{
V_50 -> V_21 . V_52 = V_52 ;
V_50 -> V_21 . V_53 = V_53 ;
V_50 -> V_21 . V_45 = & V_49 ;
return F_25 ( & V_50 -> V_21 ) ;
}
void F_26 ( struct V_17 * V_50 )
{
F_27 ( & V_50 -> V_21 ) ;
}
static T_2 F_28 ( T_2 V_54 , T_3 V_33 )
{
int V_32 ;
V_54 ^= V_33 << 8 ;
for ( V_32 = 0 ; V_32 < 8 ; V_32 ++ )
V_54 = ( V_54 << 1 ) ^ ( ( V_54 & 0x8000 ) ? 0x1021 : 0 ) ;
return V_54 ;
}
static T_3 F_29 ( struct V_3 * V_2 )
{
T_3 V_33 ;
T_2 V_54 ;
unsigned int V_32 ;
V_54 = 0xffff ;
for ( V_32 = 0 ; V_32 < V_2 -> V_39 ; V_32 ++ ) {
V_33 = ( V_32 != 11 ) ? V_2 -> V_4 [ V_32 ] : 0 ;
V_54 = F_28 ( V_54 , V_33 ) ;
}
V_54 = ~ V_54 ;
return V_54 & 0xff ;
}
static T_2 F_30 ( struct V_3 * V_2 )
{
T_3 V_33 ;
T_2 V_54 ;
unsigned int V_32 ;
V_54 = 0xffff ;
for ( V_32 = 0 ; V_32 < V_2 -> V_39 ; V_32 ++ ) {
V_33 = ( ( V_32 != 0x18 ) && ( V_32 != 0x19 ) ) ? V_2 -> V_4 [ V_32 ] : 0 ;
V_54 = F_28 ( V_54 , V_33 ) ;
}
V_54 = ~ V_54 ;
return V_54 ;
}
static void F_31 ( struct V_3 * V_2 )
{
T_3 * V_4 = V_2 -> V_4 ;
T_3 V_54 ;
V_2 -> V_11 = V_4 [ 4 ] ;
V_2 -> V_12 = V_4 [ 5 ] ;
V_2 -> V_55 = 1 ;
V_2 -> V_56 = ( V_4 [ 7 ] == 'H' ) ;
V_54 = F_29 ( V_2 ) ;
V_2 -> V_57 = ( V_54 == V_4 [ 11 ] ) ;
if ( ! V_2 -> V_57 ) {
F_32 ( & V_2 -> V_2 , L_7 ,
V_4 [ 11 ] , V_54 ) ;
}
}
static void F_33 ( struct V_3 * V_2 )
{
T_4 * V_4 = ( T_4 * ) V_2 -> V_4 ;
T_2 V_58 , V_54 ;
V_2 -> V_11 = ( ( F_34 ( V_4 [ 3 ] ) & 0xff ) << 16 )
+ F_34 ( V_4 [ 4 ] ) ;
V_2 -> V_12 = F_34 ( V_4 [ 5 ] ) ;
V_58 = F_34 ( V_4 [ 10 ] ) ;
V_2 -> V_55 = ! ! ( V_58 & 2 ) ;
V_2 -> V_56 = ! ! ( V_58 & 4 ) ;
V_54 = F_30 ( V_2 ) ;
V_2 -> V_57 = ( V_54 == F_34 ( V_4 [ 12 ] ) ) ;
if ( ! V_2 -> V_57 ) {
F_32 ( & V_2 -> V_2 , L_7 ,
V_4 [ 11 ] , V_54 ) ;
}
}
static int F_35 ( struct V_3 * V_2 )
{
T_3 T_5 * V_59 ;
int V_32 ;
int V_60 = 0 ;
V_60 = V_2 -> V_45 -> V_22 -> V_61 ( V_2 , 0 , V_62 ) ;
if ( V_60 ) {
F_36 ( & V_2 -> V_2 , L_8 ) ;
return V_60 ;
}
V_59 = V_2 -> V_63 . V_64 ;
if ( ( F_37 ( V_59 + 1 ) == 'I' ) &&
( F_37 ( V_59 + 3 ) == 'P' ) &&
( F_37 ( V_59 + 5 ) == 'A' ) &&
( ( F_37 ( V_59 + 7 ) == 'C' ) ||
( F_37 ( V_59 + 7 ) == 'H' ) ) ) {
V_2 -> V_8 = V_36 ;
V_2 -> V_39 = F_37 ( V_59 + 0x15 ) ;
if ( ( V_2 -> V_39 < 0x0c ) || ( V_2 -> V_39 > 0x40 ) ) {
F_32 ( & V_2 -> V_2 , L_9 ) ;
V_2 -> V_39 = 0x0c ;
}
} else if ( ( F_37 ( V_59 + 0 ) == 'I' ) &&
( F_37 ( V_59 + 1 ) == 'V' ) &&
( F_37 ( V_59 + 2 ) == 'A' ) &&
( F_37 ( V_59 + 3 ) == 'T' ) &&
( F_37 ( V_59 + 4 ) == ' ' ) &&
( F_37 ( V_59 + 5 ) == '4' ) ) {
V_2 -> V_8 = V_37 ;
V_2 -> V_39 = F_38 ( V_59 + 0x16 ) ;
if ( ( V_2 -> V_39 < 0x1a ) || ( V_2 -> V_39 > 0x40 ) ) {
F_32 ( & V_2 -> V_2 , L_9 ) ;
V_2 -> V_39 = 0x1a ;
}
} else {
V_2 -> V_8 = V_65 ;
V_2 -> V_39 = 0 ;
}
if ( ! V_2 -> V_39 ) {
V_60 = - V_27 ;
goto V_66;
}
V_2 -> V_4 = F_39 ( V_2 -> V_39 , V_46 ) ;
if ( ! V_2 -> V_4 ) {
F_36 ( & V_2 -> V_2 , L_10 ) ;
V_60 = - V_28 ;
goto V_66;
}
for ( V_32 = 0 ; V_32 < V_2 -> V_39 ; V_32 ++ ) {
if ( V_2 -> V_8 == V_36 )
V_2 -> V_4 [ V_32 ] = F_37 ( V_59 + ( V_32 << 1 ) + 1 ) ;
else
V_2 -> V_4 [ V_32 ] = F_37 ( V_59 + V_32 ) ;
}
switch ( V_2 -> V_8 ) {
case V_36 :
F_31 ( V_2 ) ;
break;
case V_37 :
F_33 ( V_2 ) ;
break;
}
V_66:
V_2 -> V_45 -> V_22 -> V_67 ( V_2 , V_62 ) ;
return V_60 ;
}
struct V_3 * F_40 ( struct V_40 * V_45 ,
int V_68 )
{
int V_60 ;
struct V_3 * V_2 ;
V_2 = F_17 ( sizeof( struct V_3 ) , V_46 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_2 . V_45 = & V_49 ;
V_2 -> V_2 . V_69 = F_1 ;
V_2 -> V_2 . V_41 = V_45 -> V_41 ;
V_2 -> V_68 = V_68 ;
V_2 -> V_44 = V_45 -> V_44 ;
V_2 -> V_45 = V_45 ;
F_41 ( & V_2 -> V_2 ,
L_11 , V_2 -> V_44 , V_2 -> V_68 ) ;
if ( V_45 -> V_22 -> V_70 ( V_2 , 8 ) )
F_32 ( & V_2 -> V_2 , L_12 ) ;
if ( V_45 -> V_22 -> V_71 ( V_2 ) )
F_32 ( & V_2 -> V_2 , L_13 ) ;
V_60 = F_35 ( V_2 ) ;
if ( V_60 < 0 ) {
F_36 ( & V_2 -> V_2 , L_14 ) ;
F_3 ( V_2 ) ;
return NULL ;
}
if ( V_2 -> V_56 ) {
V_60 = V_45 -> V_22 -> V_70 ( V_2 , 32 ) ;
if ( V_60 < 0 )
F_36 ( & V_2 -> V_2 , L_15 ) ;
}
V_60 = F_42 ( & V_2 -> V_2 ) ;
if ( V_60 < 0 ) {
F_3 ( V_2 -> V_4 ) ;
F_3 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
void F_20 ( struct V_3 * V_2 )
{
F_43 ( & V_2 -> V_2 ) ;
}
static int T_6 F_44 ( void )
{
F_45 ( & V_47 ) ;
return F_46 ( & V_49 ) ;
}
static void T_7 F_47 ( void )
{
F_48 ( & V_49 ) ;
F_49 ( & V_47 ) ;
}
