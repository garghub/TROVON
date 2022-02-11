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
static void F_18 ( struct V_1 * V_2 )
{
struct V_5 * V_16 = F_6 ( V_2 ) ;
struct V_17 * V_15 = F_15 ( V_2 -> V_21 ) ;
if ( V_2 -> V_21 && V_15 -> V_23 )
V_15 -> V_23 ( V_16 ) ;
}
static T_1 F_19 ( struct V_1 * V_2 , struct V_24 * V_25 ,
char * V_26 )
{
struct V_5 * V_16 = F_6 ( V_2 ) ;
int V_27 = snprintf ( V_26 , V_28 , L_1 , V_16 -> V_7 . V_7 ) ;
return ( V_27 >= V_28 ) ? ( V_28 - 1 ) : V_27 ;
}
static T_1 F_20 ( struct V_1 * V_2 ,
struct V_24 * V_29 , char * V_26 )
{
struct V_5 * V_9 ;
V_9 = F_6 ( V_2 ) ;
return sprintf ( V_26 , L_2 , V_9 -> V_30 ) ;
}
static T_1 F_21 ( struct V_1 * V_2 ,
struct V_24 * V_29 , char * V_26 )
{
struct V_5 * V_9 ;
V_9 = F_6 ( V_2 ) ;
return sprintf ( V_26 , L_3 , V_9 -> V_7 . V_7 ) ;
}
static int F_22 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
struct V_5 * V_16 = F_6 ( V_2 ) ;
F_23 ( V_32 , L_4 , V_16 -> V_7 . V_7 ) ;
return 0 ;
}
int F_24 ( struct V_17 * V_15 )
{
if ( ! V_15 -> V_21 . V_30 )
V_15 -> V_21 . V_30 = V_15 -> V_30 ;
if ( ! V_15 -> V_21 . V_33 )
V_15 -> V_21 . V_33 = V_15 -> V_33 ;
V_15 -> V_21 . V_10 = & V_11 ;
return F_25 ( & V_15 -> V_21 ) ;
}
void F_26 ( struct V_17 * V_15 )
{
F_27 ( & V_15 -> V_21 ) ;
}
void F_28 ( struct V_5 * V_2 )
{
T_2 V_8 = V_34 -> V_35 ;
switch ( V_2 -> V_36 ) {
case 0 :
V_8 |= V_37 ;
break;
case 1 :
V_8 |= V_38 ;
break;
case 2 :
V_8 |= V_39 ;
break;
}
V_34 -> V_35 = V_8 ;
}
void F_29 ( int V_36 )
{
T_2 V_8 = V_34 -> V_35 ;
switch ( V_36 ) {
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
V_34 -> V_35 = V_8 ;
}
static int F_30 ( unsigned long V_43 , T_2 * V_44 )
{
T_3 V_45 ;
T_3 V_46 ;
T_2 V_47 ;
T_3 * V_48 ;
T_4 * V_49 ;
T_2 * V_50 ;
V_50 = ( void * ) F_31 ( V_43 ) ;
if ( ! F_32 ( V_47 , V_50 ) ) {
V_48 = ( void * ) F_31 ( V_43 + 3 ) ;
if ( F_32 ( V_45 , V_48 ) ) {
* V_44 = V_47 ;
return 1 ;
}
V_49 = ( void * ) F_31 ( V_43 + 2 ) ;
F_32 ( V_46 , V_49 ) ;
if ( V_45 == ( V_46 & 0xff ) &&
V_45 == ( V_47 & 0xff ) &&
V_46 == ( V_47 & 0xffff ) ) {
* V_44 = V_47 ;
return 1 ;
}
}
return 0 ;
}
static int F_33 ( unsigned long V_43 )
{
T_2 V_8 ;
T_2 * V_51 ;
V_51 = ( void * ) F_31 ( V_43 + V_52 ) ;
if ( ! F_32 ( V_8 , V_51 ) ) {
if ( V_8 == 0xdeadbeef )
return 1 ;
}
return 0 ;
}
static void F_34 ( int V_36 , unsigned long V_43 , int V_53 )
{
const char * V_30 = L_5 ;
struct V_5 * V_16 ;
T_2 V_8 ;
T_5 V_7 ;
int V_54 ;
if ( F_33 ( V_43 ) )
V_8 = 0x7f ;
else {
if ( ! F_30 ( V_43 , & V_8 ) ) {
if ( F_30 ( V_43 + V_55 , & V_8 ) )
V_8 = 0x7e ;
else
V_8 = 0 ;
}
}
if ( V_8 ) {
V_7 = F_35 ( V_8 ) ;
if ( V_8 & V_56 ) {
if ( V_8 & V_57 )
F_29 ( V_36 ) ;
}
for ( V_54 = 0 ; V_54 < F_36 ( V_58 ) ; V_54 ++ ) {
if ( V_7 == V_58 [ V_54 ] . V_7 ) {
V_30 = V_58 [ V_54 ] . V_30 ;
break;
}
}
F_37 ( V_59 L_6 ,
V_36 , V_30 , V_7 ) ;
V_16 = F_38 ( sizeof *V_16 , V_60 ) ;
V_16 -> V_30 = V_30 ;
V_16 -> V_36 = V_36 ;
V_16 -> V_7 . V_7 = V_7 ;
V_16 -> V_61 . V_62 = V_43 ;
V_16 -> V_61 . V_63 = V_43 + 0x3fffff ;
V_16 -> V_61 . V_64 = V_65 ;
V_16 -> V_53 = V_53 ;
F_39 ( & V_16 -> V_2 , L_7 , V_36 ) ;
F_10 ( V_16 ) ;
} else
F_37 ( V_59 L_8 , V_36 ) ;
}
int T_6 F_40 ( void )
{
unsigned int T_7 V_66 ;
int V_67 ;
V_67 = F_11 ( & V_13 ) ;
if ( V_67 ) {
F_8 ( & V_13 ) ;
return V_67 ;
}
V_67 = F_41 ( & V_11 ) ;
if ( ! V_67 ) {
F_42 ( & V_68 , & V_69 ) ;
F_37 ( V_59 L_9 ) ;
if ( F_43 () ) {
F_34 ( 0 , V_70 , V_71 ) ;
F_34 ( 1 , V_72 , V_71 ) ;
} else {
if ( F_32 ( T_7 , ( unsigned int * ) & V_73 -> T_7 [ 1 ] ) )
F_34 ( 0 , V_70 ,
V_74 ) ;
F_34 ( 1 , V_72 , V_75 ) ;
F_34 ( 2 , V_76 , V_77 ) ;
}
} else
F_13 ( & V_13 ) ;
return V_67 ;
}
