const struct V_1 * F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_1 * V_5 ;
for ( V_5 = V_2 ; V_5 -> V_6 != 0xff ; V_5 ++ )
if ( V_5 -> V_6 == V_4 -> V_6 . V_6 )
return V_5 ;
return NULL ;
}
struct V_3 * F_2 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
if ( ! V_4 )
return NULL ;
V_8 = F_3 ( & V_4 -> V_4 ) ;
if ( V_8 )
return F_4 ( V_8 ) ;
else
return NULL ;
}
void F_5 ( struct V_3 * V_4 )
{
if ( V_4 )
F_6 ( & V_4 -> V_4 ) ;
}
void F_7 ( struct V_7 * V_4 )
{
struct V_3 * V_9 ;
V_9 = F_4 ( V_4 ) ;
F_8 ( V_9 ) ;
}
int F_9 ( struct V_3 * V_9 )
{
V_9 -> V_4 . V_10 = & V_11 ;
V_9 -> V_4 . V_12 = & V_13 ;
return F_10 ( & V_9 -> V_4 ) ;
}
void F_11 ( struct V_3 * V_9 )
{
F_12 ( & V_9 -> V_4 ) ;
}
static int F_13 ( struct V_7 * V_4 , struct V_14 * V_15 )
{
struct V_3 * V_16 = F_4 ( V_4 ) ;
struct V_17 * V_18 = F_14 ( V_15 ) ;
return F_1 ( V_18 -> V_19 , V_16 ) != NULL ;
}
static int F_15 ( struct V_7 * V_4 )
{
int error = - V_20 ;
struct V_17 * V_15 ;
struct V_3 * V_16 ;
const struct V_1 * V_2 ;
V_15 = F_14 ( V_4 -> V_21 ) ;
V_16 = F_4 ( V_4 ) ;
if ( ! V_15 -> V_22 )
return error ;
F_2 ( V_16 ) ;
V_2 = F_1 ( V_15 -> V_19 , V_16 ) ;
if ( V_2 )
error = V_15 -> V_22 ( V_16 , V_2 ) ;
if ( error )
F_5 ( V_16 ) ;
return error ;
}
static int F_16 ( struct V_7 * V_4 )
{
struct V_3 * V_16 = F_4 ( V_4 ) ;
struct V_17 * V_15 = F_14 ( V_4 -> V_21 ) ;
if ( V_4 -> V_21 && V_15 -> remove )
V_15 -> remove ( V_16 ) ;
return 0 ;
}
static int F_17 ( struct V_7 * V_4 , T_1 V_23 )
{
struct V_3 * V_16 = F_4 ( V_4 ) ;
struct V_17 * V_15 = F_14 ( V_4 -> V_21 ) ;
int error = 0 ;
if ( V_4 -> V_21 && V_15 -> V_24 )
error = V_15 -> V_24 ( V_16 , V_23 ) ;
return error ;
}
static int F_18 ( struct V_7 * V_4 )
{
struct V_3 * V_16 = F_4 ( V_4 ) ;
struct V_17 * V_15 = F_14 ( V_4 -> V_21 ) ;
int error = 0 ;
if ( V_4 -> V_21 && V_15 -> V_25 )
error = V_15 -> V_25 ( V_16 ) ;
return error ;
}
static void F_19 ( struct V_7 * V_4 )
{
struct V_3 * V_16 = F_4 ( V_4 ) ;
struct V_17 * V_15 = F_14 ( V_4 -> V_21 ) ;
if ( V_4 -> V_21 && V_15 -> V_26 )
V_15 -> V_26 ( V_16 ) ;
}
static T_2 F_20 ( struct V_7 * V_4 , struct V_27 * V_28 ,
char * V_29 )
{
struct V_3 * V_16 = F_4 ( V_4 ) ;
int V_30 = snprintf ( V_29 , V_31 , L_1 , V_16 -> V_6 . V_6 ) ;
return ( V_30 >= V_31 ) ? ( V_31 - 1 ) : V_30 ;
}
static T_2 F_21 ( struct V_7 * V_4 ,
struct V_27 * V_32 , char * V_29 )
{
struct V_3 * V_9 ;
V_9 = F_4 ( V_4 ) ;
return sprintf ( V_29 , L_2 , V_9 -> V_33 ) ;
}
static T_2 F_22 ( struct V_7 * V_4 ,
struct V_27 * V_32 , char * V_29 )
{
struct V_3 * V_9 ;
V_9 = F_4 ( V_4 ) ;
return sprintf ( V_29 , L_3 , V_9 -> V_6 . V_6 ) ;
}
static int F_23 ( struct V_7 * V_4 , struct V_34 * V_35 )
{
struct V_3 * V_16 = F_4 ( V_4 ) ;
F_24 ( V_35 , L_4 , V_16 -> V_6 . V_6 ) ;
return 0 ;
}
int F_25 ( struct V_17 * V_15 )
{
if ( ! V_15 -> V_21 . V_33 )
V_15 -> V_21 . V_33 = V_15 -> V_33 ;
if ( ! V_15 -> V_21 . V_36 )
V_15 -> V_21 . V_36 = V_15 -> V_36 ;
V_15 -> V_21 . V_10 = & V_11 ;
return F_26 ( & V_15 -> V_21 ) ;
}
void F_27 ( struct V_17 * V_15 )
{
F_28 ( & V_15 -> V_21 ) ;
}
void F_29 ( struct V_3 * V_4 )
{
T_3 V_8 = V_37 -> V_38 ;
switch ( V_4 -> V_39 ) {
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
void F_30 ( int V_39 )
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
static int F_31 ( unsigned long V_46 , T_3 * V_47 )
{
T_4 V_48 ;
T_4 V_49 ;
T_3 V_50 ;
T_4 * V_51 ;
T_5 * V_52 ;
T_3 * V_53 ;
V_53 = ( void * ) F_32 ( V_46 ) ;
if ( ! F_33 ( V_50 , V_53 ) ) {
V_51 = ( void * ) F_32 ( V_46 + 3 ) ;
F_33 ( V_48 , V_51 ) ;
V_52 = ( void * ) F_32 ( V_46 + 2 ) ;
F_33 ( V_49 , V_52 ) ;
if ( V_48 == ( V_49 & 0xff ) &&
V_48 == ( V_50 & 0xff ) &&
V_49 == ( V_50 & 0xffff ) ) {
* V_47 = V_50 ;
return 1 ;
}
}
return 0 ;
}
static int F_34 ( unsigned long V_46 )
{
T_3 V_8 ;
T_3 * V_54 ;
V_54 = ( void * ) F_32 ( V_46 + V_55 ) ;
if ( ! F_33 ( V_8 , V_54 ) ) {
if ( V_8 == 0xdeadbeef )
return 1 ;
}
return 0 ;
}
static void F_35 ( int V_39 , unsigned long V_46 )
{
const char * V_33 = L_5 ;
struct V_3 * V_16 ;
T_3 V_8 ;
T_6 V_6 ;
int V_56 ;
if ( F_34 ( V_46 ) )
V_8 = 0x7f ;
else {
if ( ! F_31 ( V_46 , & V_8 ) ) {
if ( F_31 ( V_46 + V_57 , & V_8 ) )
V_8 = 0x7e ;
else
V_8 = 0 ;
}
}
if ( V_8 ) {
V_6 = F_36 ( V_8 ) ;
if ( V_8 & V_58 ) {
if ( V_8 & V_59 )
F_30 ( V_39 ) ;
}
for ( V_56 = 0 ; V_56 < F_37 ( V_60 ) ; V_56 ++ ) {
if ( V_6 == V_60 [ V_56 ] . V_6 ) {
V_33 = V_60 [ V_56 ] . V_33 ;
break;
}
}
F_38 ( V_61 L_6 ,
V_39 , V_33 , V_6 ) ;
V_16 = F_39 ( sizeof *V_16 , V_62 ) ;
V_16 -> V_33 = V_33 ;
V_16 -> V_39 = V_39 ;
V_16 -> V_6 . V_6 = V_6 ;
V_16 -> V_63 . V_64 = V_46 ;
V_16 -> V_63 . V_65 = V_46 + 0x3fffff ;
V_16 -> V_63 . V_66 = V_67 ;
F_40 ( & V_16 -> V_4 , L_7 , V_39 ) ;
F_9 ( V_16 ) ;
} else
F_38 ( V_61 L_8 , V_39 ) ;
}
int T_7 F_41 ( void )
{
unsigned int T_8 V_68 ;
int V_69 ;
V_69 = F_10 ( & V_13 ) ;
if ( V_69 )
return V_69 ;
V_69 = F_42 ( & V_11 ) ;
if ( ! V_69 ) {
F_43 ( & V_70 , & V_71 ) ;
F_38 ( V_61 L_9 ) ;
if ( F_44 () ||
! F_33 ( T_8 , ( unsigned int * ) & V_72 -> T_8 [ 1 ] ) ) {
F_35 ( 0 , V_73 ) ;
F_35 ( 1 , V_74 ) ;
} else {
F_35 ( 0 , V_73 ) ;
F_35 ( 1 , V_74 ) ;
F_35 ( 2 , V_75 ) ;
}
} else
F_12 ( & V_13 ) ;
return V_69 ;
}
