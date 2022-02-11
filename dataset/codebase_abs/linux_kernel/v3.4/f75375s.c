static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 , V_3 ) ;
}
static inline T_2 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return ( F_2 ( V_2 , V_3 ) << 8 )
| F_2 ( V_2 , V_3 + 1 ) ;
}
static inline void F_4 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
F_5 ( V_2 , V_3 , V_4 ) ;
}
static inline void F_6 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 )
{
int V_5 = F_5 ( V_2 , V_3 , ( V_4 >> 8 ) ) ;
if ( V_5 )
return;
F_5 ( V_2 , V_3 + 1 , ( V_4 & 0xFF ) ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_6 )
{
struct V_7 * V_8 = F_8 ( V_2 ) ;
if ( V_8 -> V_9 == V_10 )
F_6 ( V_2 , F_9 ( V_6 ) , V_8 -> V_11 [ V_6 ] ) ;
else
F_4 ( V_2 , F_10 ( V_6 ) ,
V_8 -> V_11 [ V_6 ] ) ;
}
static struct V_7 * F_11 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_12 ( V_13 ) ;
struct V_7 * V_8 = F_8 ( V_2 ) ;
int V_6 ;
F_13 ( & V_8 -> V_14 ) ;
if ( F_14 ( V_15 , V_8 -> V_16 + 60 * V_17 )
|| ! V_8 -> V_18 ) {
for ( V_6 = 0 ; V_6 < 2 ; V_6 ++ ) {
V_8 -> V_19 [ V_6 ] =
F_1 ( V_2 , F_15 ( V_6 ) ) ;
V_8 -> V_20 [ V_6 ] =
F_1 ( V_2 , F_16 ( V_6 ) ) ;
V_8 -> V_21 [ V_6 ] =
F_3 ( V_2 , F_17 ( V_6 ) ) ;
V_8 -> V_22 [ V_6 ] =
F_3 ( V_2 , F_18 ( V_6 ) ) ;
V_8 -> V_23 [ V_6 ] =
F_3 ( V_2 , F_9 ( V_6 ) ) ;
}
for ( V_6 = 0 ; V_6 < 4 ; V_6 ++ ) {
V_8 -> V_24 [ V_6 ] =
F_1 ( V_2 , F_19 ( V_6 ) ) ;
V_8 -> V_25 [ V_6 ] =
F_1 ( V_2 , F_20 ( V_6 ) ) ;
}
V_8 -> V_26 = F_1 ( V_2 , V_27 ) ;
V_8 -> V_16 = V_15 ;
}
if ( F_14 ( V_15 , V_8 -> V_28 + 2 * V_17 )
|| ! V_8 -> V_18 ) {
for ( V_6 = 0 ; V_6 < 2 ; V_6 ++ ) {
V_8 -> V_11 [ V_6 ] = F_1 ( V_2 ,
F_10 ( V_6 ) ) ;
V_8 -> V_29 [ V_6 ] =
F_1 ( V_2 , F_21 ( V_6 ) ) << 8 ;
if ( V_8 -> V_9 == V_10 )
V_8 -> V_29 [ V_6 ] |=
F_1 ( V_2 ,
F_22 ( V_6 ) ) ;
V_8 -> V_30 [ V_6 ] =
F_3 ( V_2 , F_23 ( V_6 ) ) ;
}
for ( V_6 = 0 ; V_6 < 4 ; V_6 ++ )
V_8 -> V_31 [ V_6 ] =
F_1 ( V_2 , F_24 ( V_6 ) ) ;
V_8 -> V_28 = V_15 ;
V_8 -> V_18 = 1 ;
}
F_25 ( & V_8 -> V_14 ) ;
return V_8 ;
}
static inline T_2 F_26 ( T_2 V_3 )
{
if ( V_3 == 0 || V_3 == 0xffff )
return 0 ;
return 1500000 / V_3 ;
}
static inline T_2 F_27 ( int V_32 )
{
if ( V_32 < 367 || V_32 > 0xffff )
return 0xffff ;
return 1500000 / V_32 ;
}
static bool F_28 ( T_1 V_33 )
{
switch ( V_33 ) {
case 0 :
case 1 :
case 4 :
return true ;
case 2 :
case 3 :
return false ;
default:
F_29 () ;
return true ;
}
}
static bool F_30 ( T_1 V_33 )
{
switch ( V_33 ) {
case 0 :
case 1 :
case 3 :
return false ;
case 2 :
case 4 :
return true ;
default:
F_29 () ;
return false ;
}
}
static T_3 F_31 ( struct V_12 * V_13 , struct V_34 * V_35 ,
const char * V_36 , T_4 V_37 )
{
int V_6 = F_32 ( V_35 ) -> V_38 ;
struct V_1 * V_2 = F_12 ( V_13 ) ;
struct V_7 * V_8 = F_8 ( V_2 ) ;
unsigned long V_39 ;
int V_5 ;
V_5 = F_33 ( V_36 , 10 , & V_39 ) ;
if ( V_5 < 0 )
return V_5 ;
F_13 ( & V_8 -> V_14 ) ;
V_8 -> V_22 [ V_6 ] = F_27 ( V_39 ) ;
F_6 ( V_2 , F_18 ( V_6 ) , V_8 -> V_22 [ V_6 ] ) ;
F_25 ( & V_8 -> V_14 ) ;
return V_37 ;
}
static T_3 F_34 ( struct V_12 * V_13 , struct V_34 * V_35 ,
const char * V_36 , T_4 V_37 )
{
int V_6 = F_32 ( V_35 ) -> V_38 ;
struct V_1 * V_2 = F_12 ( V_13 ) ;
struct V_7 * V_8 = F_8 ( V_2 ) ;
unsigned long V_39 ;
int V_5 ;
V_5 = F_33 ( V_36 , 10 , & V_39 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( F_30 ( V_8 -> V_33 [ V_6 ] ) )
return - V_40 ;
if ( V_8 -> V_9 == V_10 && F_28 ( V_8 -> V_33 [ V_6 ] ) )
return - V_40 ;
F_13 ( & V_8 -> V_14 ) ;
V_8 -> V_23 [ V_6 ] = F_27 ( V_39 ) ;
F_6 ( V_2 , F_9 ( V_6 ) , V_8 -> V_23 [ V_6 ] ) ;
F_25 ( & V_8 -> V_14 ) ;
return V_37 ;
}
static T_3 F_35 ( struct V_12 * V_13 , struct V_34 * V_35 ,
const char * V_36 , T_4 V_37 )
{
int V_6 = F_32 ( V_35 ) -> V_38 ;
struct V_1 * V_2 = F_12 ( V_13 ) ;
struct V_7 * V_8 = F_8 ( V_2 ) ;
unsigned long V_39 ;
int V_5 ;
V_5 = F_33 ( V_36 , 10 , & V_39 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( F_30 ( V_8 -> V_33 [ V_6 ] ) ||
! F_28 ( V_8 -> V_33 [ V_6 ] ) )
return - V_40 ;
F_13 ( & V_8 -> V_14 ) ;
V_8 -> V_11 [ V_6 ] = F_36 ( V_39 , 0 , 255 ) ;
F_7 ( V_2 , V_6 ) ;
F_25 ( & V_8 -> V_14 ) ;
return V_37 ;
}
static T_3 F_37 ( struct V_12 * V_13 , struct V_34
* V_35 , char * V_36 )
{
int V_6 = F_32 ( V_35 ) -> V_38 ;
struct V_7 * V_8 = F_11 ( V_13 ) ;
return sprintf ( V_36 , L_1 , V_8 -> V_33 [ V_6 ] ) ;
}
static int F_38 ( struct V_1 * V_2 , int V_6 , int V_39 )
{
struct V_7 * V_8 = F_8 ( V_2 ) ;
T_1 V_41 ;
if ( V_39 < 0 || V_39 > 4 )
return - V_40 ;
V_41 = F_1 ( V_2 , V_27 ) ;
if ( V_8 -> V_9 == V_10 ) {
if ( F_28 ( V_8 -> V_33 [ V_6 ] ) !=
F_28 ( V_39 ) )
return - V_42 ;
V_41 &= ~ ( 1 << F_39 ( V_6 ) ) ;
V_41 &= ~ ( 1 << F_40 ( V_6 ) ) ;
switch ( V_39 ) {
case 0 :
V_41 |= ( 1 << F_40 ( V_6 ) ) ;
V_41 |= ( 1 << F_39 ( V_6 ) ) ;
V_8 -> V_11 [ V_6 ] = 255 ;
break;
case 1 :
V_41 |= ( 1 << F_40 ( V_6 ) ) ;
V_41 |= ( 1 << F_39 ( V_6 ) ) ;
break;
case 2 :
break;
case 3 :
V_41 |= ( 1 << F_40 ( V_6 ) ) ;
break;
case 4 :
V_41 |= ( 1 << F_39 ( V_6 ) ) ;
break;
}
} else {
V_41 &= ~ ( 3 << F_41 ( V_6 ) ) ;
switch ( V_39 ) {
case 0 :
V_41 |= ( 3 << F_41 ( V_6 ) ) ;
V_8 -> V_11 [ V_6 ] = 255 ;
break;
case 1 :
V_41 |= ( 3 << F_41 ( V_6 ) ) ;
break;
case 2 :
V_41 |= ( 1 << F_41 ( V_6 ) ) ;
break;
case 3 :
break;
case 4 :
return - V_40 ;
}
}
F_4 ( V_2 , V_27 , V_41 ) ;
V_8 -> V_33 [ V_6 ] = V_39 ;
if ( V_39 == 0 )
F_7 ( V_2 , V_6 ) ;
return 0 ;
}
static T_3 F_42 ( struct V_12 * V_13 , struct V_34 * V_35 ,
const char * V_36 , T_4 V_37 )
{
int V_6 = F_32 ( V_35 ) -> V_38 ;
struct V_1 * V_2 = F_12 ( V_13 ) ;
struct V_7 * V_8 = F_8 ( V_2 ) ;
unsigned long V_39 ;
int V_5 ;
V_5 = F_33 ( V_36 , 10 , & V_39 ) ;
if ( V_5 < 0 )
return V_5 ;
F_13 ( & V_8 -> V_14 ) ;
V_5 = F_38 ( V_2 , V_6 , V_39 ) ;
F_25 ( & V_8 -> V_14 ) ;
return V_5 ? V_5 : V_37 ;
}
static T_3 F_43 ( struct V_12 * V_13 , struct V_34 * V_35 ,
const char * V_36 , T_4 V_37 )
{
int V_6 = F_32 ( V_35 ) -> V_38 ;
struct V_1 * V_2 = F_12 ( V_13 ) ;
struct V_7 * V_8 = F_8 ( V_2 ) ;
unsigned long V_39 ;
int V_5 ;
T_1 V_43 ;
char V_3 , V_44 ;
V_5 = F_33 ( V_36 , 10 , & V_39 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( ! ( V_39 == 0 || V_39 == 1 ) )
return - V_40 ;
if ( V_8 -> V_9 == V_45 && V_39 == 0 )
return - V_40 ;
if ( V_8 -> V_9 == V_10 ) {
V_3 = V_27 ;
V_44 = F_44 ( V_6 ) ;
} else {
V_3 = V_46 ;
V_44 = F_45 ( V_6 ) ;
}
F_13 ( & V_8 -> V_14 ) ;
V_43 = F_1 ( V_2 , V_3 ) ;
V_43 &= ~ ( 1 << V_44 ) ;
if ( V_39 == 0 )
V_43 |= ( 1 << V_44 ) ;
F_4 ( V_2 , V_3 , V_43 ) ;
V_8 -> V_47 [ V_6 ] = V_39 ;
F_25 ( & V_8 -> V_14 ) ;
return V_37 ;
}
static T_3 F_46 ( struct V_12 * V_13 , struct V_34
* V_35 , char * V_36 )
{
int V_6 = F_32 ( V_35 ) -> V_38 ;
struct V_7 * V_8 = F_11 ( V_13 ) ;
return sprintf ( V_36 , L_1 , V_8 -> V_11 [ V_6 ] ) ;
}
static T_3 F_47 ( struct V_12 * V_13 , struct V_34
* V_35 , char * V_36 )
{
int V_6 = F_32 ( V_35 ) -> V_38 ;
struct V_7 * V_8 = F_11 ( V_13 ) ;
return sprintf ( V_36 , L_1 , V_8 -> V_47 [ V_6 ] ) ;
}
static T_3 F_48 ( struct V_12 * V_13 , struct V_34 * V_35 ,
char * V_36 )
{
int V_6 = F_32 ( V_35 ) -> V_38 ;
struct V_7 * V_8 = F_11 ( V_13 ) ;
return sprintf ( V_36 , L_1 , F_49 ( V_8 -> V_31 [ V_6 ] ) ) ;
}
static T_3 F_50 ( struct V_12 * V_13 , struct V_34 * V_35 ,
char * V_36 )
{
int V_6 = F_32 ( V_35 ) -> V_38 ;
struct V_7 * V_8 = F_11 ( V_13 ) ;
return sprintf ( V_36 , L_1 , F_49 ( V_8 -> V_24 [ V_6 ] ) ) ;
}
static T_3 F_51 ( struct V_12 * V_13 , struct V_34 * V_35 ,
char * V_36 )
{
int V_6 = F_32 ( V_35 ) -> V_38 ;
struct V_7 * V_8 = F_11 ( V_13 ) ;
return sprintf ( V_36 , L_1 , F_49 ( V_8 -> V_25 [ V_6 ] ) ) ;
}
static T_3 F_52 ( struct V_12 * V_13 , struct V_34 * V_35 ,
const char * V_36 , T_4 V_37 )
{
int V_6 = F_32 ( V_35 ) -> V_38 ;
struct V_1 * V_2 = F_12 ( V_13 ) ;
struct V_7 * V_8 = F_8 ( V_2 ) ;
unsigned long V_39 ;
int V_5 ;
V_5 = F_33 ( V_36 , 10 , & V_39 ) ;
if ( V_5 < 0 )
return V_5 ;
V_39 = F_36 ( F_53 ( V_39 ) , 0 , 0xff ) ;
F_13 ( & V_8 -> V_14 ) ;
V_8 -> V_24 [ V_6 ] = V_39 ;
F_4 ( V_2 , F_19 ( V_6 ) , V_8 -> V_24 [ V_6 ] ) ;
F_25 ( & V_8 -> V_14 ) ;
return V_37 ;
}
static T_3 F_54 ( struct V_12 * V_13 , struct V_34 * V_35 ,
const char * V_36 , T_4 V_37 )
{
int V_6 = F_32 ( V_35 ) -> V_38 ;
struct V_1 * V_2 = F_12 ( V_13 ) ;
struct V_7 * V_8 = F_8 ( V_2 ) ;
unsigned long V_39 ;
int V_5 ;
V_5 = F_33 ( V_36 , 10 , & V_39 ) ;
if ( V_5 < 0 )
return V_5 ;
V_39 = F_36 ( F_53 ( V_39 ) , 0 , 0xff ) ;
F_13 ( & V_8 -> V_14 ) ;
V_8 -> V_25 [ V_6 ] = V_39 ;
F_4 ( V_2 , F_20 ( V_6 ) , V_8 -> V_25 [ V_6 ] ) ;
F_25 ( & V_8 -> V_14 ) ;
return V_37 ;
}
static T_3 F_55 ( struct V_12 * V_13 , struct V_34 * V_35 ,
char * V_36 )
{
int V_6 = F_32 ( V_35 ) -> V_38 ;
struct V_7 * V_8 = F_11 ( V_13 ) ;
return sprintf ( V_36 , L_1 , F_56 ( V_8 -> V_29 [ V_6 ] ) ) ;
}
static T_3 F_57 ( struct V_12 * V_13 , struct V_34 * V_35 ,
char * V_36 )
{
int V_6 = F_32 ( V_35 ) -> V_38 ;
struct V_7 * V_8 = F_11 ( V_13 ) ;
return sprintf ( V_36 , L_1 , F_58 ( V_8 -> V_19 [ V_6 ] ) ) ;
}
static T_3 F_59 ( struct V_12 * V_13 ,
struct V_34 * V_35 , char * V_36 )
{
int V_6 = F_32 ( V_35 ) -> V_38 ;
struct V_7 * V_8 = F_11 ( V_13 ) ;
return sprintf ( V_36 , L_1 , F_58 ( V_8 -> V_20 [ V_6 ] ) ) ;
}
static T_3 F_60 ( struct V_12 * V_13 , struct V_34 * V_35 ,
const char * V_36 , T_4 V_37 )
{
int V_6 = F_32 ( V_35 ) -> V_38 ;
struct V_1 * V_2 = F_12 ( V_13 ) ;
struct V_7 * V_8 = F_8 ( V_2 ) ;
unsigned long V_39 ;
int V_5 ;
V_5 = F_33 ( V_36 , 10 , & V_39 ) ;
if ( V_5 < 0 )
return V_5 ;
V_39 = F_36 ( F_61 ( V_39 ) , 0 , 127 ) ;
F_13 ( & V_8 -> V_14 ) ;
V_8 -> V_19 [ V_6 ] = V_39 ;
F_4 ( V_2 , F_15 ( V_6 ) , V_8 -> V_19 [ V_6 ] ) ;
F_25 ( & V_8 -> V_14 ) ;
return V_37 ;
}
static T_3 F_62 ( struct V_12 * V_13 ,
struct V_34 * V_35 , const char * V_36 , T_4 V_37 )
{
int V_6 = F_32 ( V_35 ) -> V_38 ;
struct V_1 * V_2 = F_12 ( V_13 ) ;
struct V_7 * V_8 = F_8 ( V_2 ) ;
unsigned long V_39 ;
int V_5 ;
V_5 = F_33 ( V_36 , 10 , & V_39 ) ;
if ( V_5 < 0 )
return V_5 ;
V_39 = F_36 ( F_61 ( V_39 ) , 0 , 127 ) ;
F_13 ( & V_8 -> V_14 ) ;
V_8 -> V_20 [ V_6 ] = V_39 ;
F_4 ( V_2 , F_16 ( V_6 ) ,
V_8 -> V_20 [ V_6 ] ) ;
F_25 ( & V_8 -> V_14 ) ;
return V_37 ;
}
static void F_63 ( struct V_1 * V_2 , struct V_7 * V_8 ,
struct V_48 * V_49 )
{
int V_6 ;
if ( ! V_49 ) {
T_1 V_43 , V_50 ;
int V_6 ;
V_43 = F_1 ( V_2 , V_46 ) ;
V_50 = F_1 ( V_2 , V_27 ) ;
for ( V_6 = 0 ; V_6 < 2 ; V_6 ++ ) {
if ( V_8 -> V_9 == V_10 ) {
bool V_51 , V_52 ;
if ( ! ( V_50 & ( 1 << F_44 ( V_6 ) ) ) )
V_8 -> V_47 [ V_6 ] = 1 ;
V_51 = ( ( V_50 >> F_40 ( V_6 ) ) & 1 ) ;
V_52 = ( ( V_50 >> F_39 ( V_6 ) ) & 1 ) ;
if ( ! V_51 && V_52 )
V_8 -> V_33 [ V_6 ] = 4 ;
else if ( V_51 && ! V_52 )
V_8 -> V_33 [ V_6 ] = 3 ;
else if ( ! V_51 && ! V_52 )
V_8 -> V_33 [ V_6 ] = 2 ;
else
V_8 -> V_33 [ V_6 ] = 1 ;
} else {
if ( ! ( V_43 & ( 1 << F_45 ( V_6 ) ) ) )
V_8 -> V_47 [ V_6 ] = 1 ;
switch ( ( V_50 >> F_41 ( V_6 ) ) & 3 ) {
case 0 :
V_8 -> V_33 [ V_6 ] = 3 ;
break;
case 1 :
V_8 -> V_33 [ V_6 ] = 2 ;
break;
default:
V_8 -> V_33 [ V_6 ] = 1 ;
break;
}
}
}
return;
}
F_38 ( V_2 , 0 , V_49 -> V_33 [ 0 ] ) ;
F_38 ( V_2 , 1 , V_49 -> V_33 [ 1 ] ) ;
for ( V_6 = 0 ; V_6 < 2 ; V_6 ++ ) {
if ( F_30 ( V_49 -> V_33 [ V_6 ] ) ||
! F_28 ( V_49 -> V_33 [ V_6 ] ) )
continue;
V_8 -> V_11 [ V_6 ] = F_36 ( V_49 -> V_11 [ V_6 ] , 0 , 255 ) ;
F_7 ( V_2 , V_6 ) ;
}
}
static int F_64 ( struct V_1 * V_2 ,
const struct V_53 * V_54 )
{
struct V_7 * V_8 ;
struct V_48 * V_49 = V_2 -> V_13 . V_55 ;
int V_5 ;
if ( ! F_65 ( V_2 -> V_56 ,
V_57 ) )
return - V_58 ;
V_8 = F_66 ( sizeof( struct V_7 ) , V_59 ) ;
if ( ! V_8 )
return - V_60 ;
F_67 ( V_2 , V_8 ) ;
F_68 ( & V_8 -> V_14 ) ;
V_8 -> V_9 = V_54 -> V_61 ;
V_5 = F_69 ( & V_2 -> V_13 . V_62 , & V_63 ) ;
if ( V_5 )
goto V_64;
if ( V_8 -> V_9 != V_45 ) {
V_5 = F_70 ( & V_2 -> V_13 . V_62 ,
& V_65 . V_66 . V_35 ,
V_67 | V_68 ) ;
if ( V_5 )
goto V_69;
V_5 = F_70 ( & V_2 -> V_13 . V_62 ,
& V_70 . V_66 . V_35 ,
V_67 | V_68 ) ;
if ( V_5 )
goto V_69;
}
V_8 -> V_71 = F_71 ( & V_2 -> V_13 ) ;
if ( F_72 ( V_8 -> V_71 ) ) {
V_5 = F_73 ( V_8 -> V_71 ) ;
goto V_69;
}
F_63 ( V_2 , V_8 , V_49 ) ;
return 0 ;
V_69:
F_74 ( & V_2 -> V_13 . V_62 , & V_63 ) ;
V_64:
F_75 ( V_8 ) ;
return V_5 ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_8 ( V_2 ) ;
F_77 ( V_8 -> V_71 ) ;
F_74 ( & V_2 -> V_13 . V_62 , & V_63 ) ;
F_75 ( V_8 ) ;
return 0 ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_72 * V_73 )
{
struct V_74 * V_56 = V_2 -> V_56 ;
T_2 V_75 , V_76 ;
T_1 V_77 ;
const char * V_78 ;
V_75 = F_3 ( V_2 , V_79 ) ;
V_76 = F_3 ( V_2 , V_80 ) ;
if ( V_75 != 0x1934 )
return - V_81 ;
if ( V_76 == 0x0306 )
V_78 = L_2 ;
else if ( V_76 == 0x0204 )
V_78 = L_3 ;
else if ( V_76 == 0x0410 )
V_78 = L_4 ;
else
return - V_81 ;
V_77 = F_1 ( V_2 , V_82 ) ;
F_79 ( & V_56 -> V_13 , L_5 , V_78 , V_77 ) ;
F_80 ( V_73 -> type , V_78 , V_83 ) ;
return 0 ;
}
