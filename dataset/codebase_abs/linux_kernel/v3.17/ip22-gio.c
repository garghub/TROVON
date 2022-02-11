static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
}
const struct V_3 * F_3 ( const struct V_3 * V_4 ,
const struct V_5 * V_2 )
{
const struct V_3 * V_6 ;
for ( V_6 = V_4 ; V_6 -> V_7 != 0xff ; V_6 ++ )
if ( V_6 -> V_7 == V_2 -> V_7 . V_7 )
return V_6 ;
return NULL ;
}
struct V_5 * F_4 ( struct V_5 * V_2 )
{
struct V_1 * V_8 ;
if ( ! V_2 )
return NULL ;
V_8 = F_5 ( & V_2 -> V_2 ) ;
if ( V_8 )
return F_6 ( V_8 ) ;
else
return NULL ;
}
void F_7 ( struct V_5 * V_2 )
{
if ( V_2 )
F_8 ( & V_2 -> V_2 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_9 ;
V_9 = F_6 ( V_2 ) ;
F_2 ( V_9 ) ;
}
int F_10 ( struct V_5 * V_9 )
{
V_9 -> V_2 . V_10 = & V_11 ;
V_9 -> V_2 . V_12 = & V_13 ;
return F_11 ( & V_9 -> V_2 ) ;
}
void F_12 ( struct V_5 * V_9 )
{
F_13 ( & V_9 -> V_2 ) ;
}
static int F_14 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_5 * V_16 = F_6 ( V_2 ) ;
struct V_17 * V_18 = F_15 ( V_15 ) ;
return F_3 ( V_18 -> V_19 , V_16 ) != NULL ;
}
static int F_16 ( struct V_1 * V_2 )
{
int error = - V_20 ;
struct V_17 * V_15 ;
struct V_5 * V_16 ;
const struct V_3 * V_4 ;
V_15 = F_15 ( V_2 -> V_21 ) ;
V_16 = F_6 ( V_2 ) ;
if ( ! V_15 -> V_22 )
return error ;
F_4 ( V_16 ) ;
V_4 = F_3 ( V_15 -> V_19 , V_16 ) ;
if ( V_4 )
error = V_15 -> V_22 ( V_16 , V_4 ) ;
if ( error )
F_7 ( V_16 ) ;
return error ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_16 = F_6 ( V_2 ) ;
struct V_17 * V_15 = F_15 ( V_2 -> V_21 ) ;
if ( V_2 -> V_21 && V_15 -> remove )
V_15 -> remove ( V_16 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , T_1 V_23 )
{
struct V_5 * V_16 = F_6 ( V_2 ) ;
struct V_17 * V_15 = F_15 ( V_2 -> V_21 ) ;
int error = 0 ;
if ( V_2 -> V_21 && V_15 -> V_24 )
error = V_15 -> V_24 ( V_16 , V_23 ) ;
return error ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_5 * V_16 = F_6 ( V_2 ) ;
struct V_17 * V_15 = F_15 ( V_2 -> V_21 ) ;
int error = 0 ;
if ( V_2 -> V_21 && V_15 -> V_25 )
error = V_15 -> V_25 ( V_16 ) ;
return error ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_16 = F_6 ( V_2 ) ;
struct V_17 * V_15 = F_15 ( V_2 -> V_21 ) ;
if ( V_2 -> V_21 && V_15 -> V_26 )
V_15 -> V_26 ( V_16 ) ;
}
static T_2 F_21 ( struct V_1 * V_2 , struct V_27 * V_28 ,
char * V_29 )
{
struct V_5 * V_16 = F_6 ( V_2 ) ;
int V_30 = snprintf ( V_29 , V_31 , L_1 , V_16 -> V_7 . V_7 ) ;
return ( V_30 >= V_31 ) ? ( V_31 - 1 ) : V_30 ;
}
static T_2 F_22 ( struct V_1 * V_2 ,
struct V_27 * V_32 , char * V_29 )
{
struct V_5 * V_9 ;
V_9 = F_6 ( V_2 ) ;
return sprintf ( V_29 , L_2 , V_9 -> V_33 ) ;
}
static T_2 F_23 ( struct V_1 * V_2 ,
struct V_27 * V_32 , char * V_29 )
{
struct V_5 * V_9 ;
V_9 = F_6 ( V_2 ) ;
return sprintf ( V_29 , L_3 , V_9 -> V_7 . V_7 ) ;
}
static int F_24 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
struct V_5 * V_16 = F_6 ( V_2 ) ;
F_25 ( V_35 , L_4 , V_16 -> V_7 . V_7 ) ;
return 0 ;
}
int F_26 ( struct V_17 * V_15 )
{
if ( ! V_15 -> V_21 . V_33 )
V_15 -> V_21 . V_33 = V_15 -> V_33 ;
if ( ! V_15 -> V_21 . V_36 )
V_15 -> V_21 . V_36 = V_15 -> V_36 ;
V_15 -> V_21 . V_10 = & V_11 ;
return F_27 ( & V_15 -> V_21 ) ;
}
void F_28 ( struct V_17 * V_15 )
{
F_29 ( & V_15 -> V_21 ) ;
}
void F_30 ( struct V_5 * V_2 )
{
T_3 V_8 = V_37 -> V_38 ;
switch ( V_2 -> V_39 ) {
case 0 :
V_8 |= V_40 ;
break;
case 1 :
V_8 |= V_41 ;
break;
case 2 :
V_8 |= V_42 ;
break;
}
V_37 -> V_38 = V_8 ;
}
void F_31 ( int V_39 )
{
T_3 V_8 = V_37 -> V_38 ;
switch ( V_39 ) {
case 0 :
V_8 |= V_43 ;
break;
case 1 :
V_8 |= V_44 ;
break;
case 2 :
V_8 |= V_45 ;
break;
}
V_37 -> V_38 = V_8 ;
}
static int F_32 ( unsigned long V_46 , T_3 * V_47 )
{
T_4 V_48 ;
T_4 V_49 ;
T_3 V_50 ;
T_4 * V_51 ;
T_5 * V_52 ;
T_3 * V_53 ;
V_53 = ( void * ) F_33 ( V_46 ) ;
if ( ! F_34 ( V_50 , V_53 ) ) {
V_51 = ( void * ) F_33 ( V_46 + 3 ) ;
if ( F_34 ( V_48 , V_51 ) ) {
* V_47 = V_50 ;
return 1 ;
}
V_52 = ( void * ) F_33 ( V_46 + 2 ) ;
F_34 ( V_49 , V_52 ) ;
if ( V_48 == ( V_49 & 0xff ) &&
V_48 == ( V_50 & 0xff ) &&
V_49 == ( V_50 & 0xffff ) ) {
* V_47 = V_50 ;
return 1 ;
}
}
return 0 ;
}
static int F_35 ( unsigned long V_46 )
{
T_3 V_8 ;
T_3 * V_54 ;
V_54 = ( void * ) F_33 ( V_46 + V_55 ) ;
if ( ! F_34 ( V_8 , V_54 ) ) {
if ( V_8 == 0xdeadbeef )
return 1 ;
}
return 0 ;
}
static void F_36 ( int V_39 , unsigned long V_46 , int V_56 )
{
const char * V_33 = L_5 ;
struct V_5 * V_16 ;
T_3 V_8 ;
T_6 V_7 ;
int V_57 ;
if ( F_35 ( V_46 ) )
V_8 = 0x7f ;
else {
if ( ! F_32 ( V_46 , & V_8 ) ) {
if ( F_32 ( V_46 + V_58 , & V_8 ) )
V_8 = 0x7e ;
else
V_8 = 0 ;
}
}
if ( V_8 ) {
V_7 = F_37 ( V_8 ) ;
if ( V_8 & V_59 ) {
if ( V_8 & V_60 )
F_31 ( V_39 ) ;
}
for ( V_57 = 0 ; V_57 < F_38 ( V_61 ) ; V_57 ++ ) {
if ( V_7 == V_61 [ V_57 ] . V_7 ) {
V_33 = V_61 [ V_57 ] . V_33 ;
break;
}
}
F_39 ( V_62 L_6 ,
V_39 , V_33 , V_7 ) ;
V_16 = F_40 ( sizeof *V_16 , V_63 ) ;
V_16 -> V_33 = V_33 ;
V_16 -> V_39 = V_39 ;
V_16 -> V_7 . V_7 = V_7 ;
V_16 -> V_64 . V_65 = V_46 ;
V_16 -> V_64 . V_66 = V_46 + 0x3fffff ;
V_16 -> V_64 . V_67 = V_68 ;
V_16 -> V_56 = V_56 ;
F_41 ( & V_16 -> V_2 , L_7 , V_39 ) ;
F_10 ( V_16 ) ;
} else
F_39 ( V_62 L_8 , V_39 ) ;
}
int T_7 F_42 ( void )
{
unsigned int T_8 V_69 ;
int V_70 ;
V_70 = F_11 ( & V_13 ) ;
if ( V_70 ) {
F_8 ( & V_13 ) ;
return V_70 ;
}
V_70 = F_43 ( & V_11 ) ;
if ( ! V_70 ) {
F_44 ( & V_71 , & V_72 ) ;
F_39 ( V_62 L_9 ) ;
if ( F_45 () ) {
F_36 ( 0 , V_73 , V_74 ) ;
F_36 ( 1 , V_75 , V_74 ) ;
} else {
if ( F_34 ( T_8 , ( unsigned int * ) & V_76 -> T_8 [ 1 ] ) )
F_36 ( 0 , V_73 ,
V_77 ) ;
F_36 ( 1 , V_75 , V_78 ) ;
F_36 ( 2 , V_79 , V_80 ) ;
}
} else
F_13 ( & V_13 ) ;
return V_70 ;
}
