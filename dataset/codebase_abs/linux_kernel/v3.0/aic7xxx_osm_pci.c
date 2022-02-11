static int
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
if ( ( V_6 = F_3 ( V_5 ) ) )
return V_6 ;
F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
if ( V_3 . V_7 & V_8 )
F_6 ( V_2 , V_9 ) ;
return V_6 ;
}
static int
F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
F_6 ( V_2 , V_10 ) ;
F_8 ( V_2 ) ;
if ( ( V_6 = F_9 ( V_2 ) ) ) {
F_10 ( V_11 , & V_2 -> V_12 ,
L_1 , V_6 ) ;
return V_6 ;
}
F_11 ( V_2 ) ;
F_12 ( V_5 ) ;
return ( F_13 ( V_5 ) ) ;
}
static void
F_14 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_13 ;
if ( V_5 -> V_14 && V_5 -> V_14 -> V_15 )
F_15 ( V_5 -> V_14 -> V_15 ) ;
F_16 ( V_5 , & V_13 ) ;
F_17 ( V_5 , FALSE ) ;
F_18 ( V_5 , & V_13 ) ;
F_19 ( V_5 ) ;
}
static void
F_20 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_16 , * V_17 ;
unsigned int V_18 = F_21 ( F_22 ( V_2 -> V_19 ) , 0 ) ;
V_17 = F_23 ( V_2 -> V_20 , V_18 ) ;
if ( V_17 ) {
struct V_4 * V_21 = F_2 ( V_17 ) ;
if ( V_21 ) {
V_5 -> V_22 &= ~ V_23 ;
V_5 -> V_22 |= V_21 -> V_22 & V_23 ;
V_5 -> V_22 &= ~ V_24 ;
V_5 -> V_22 |= V_21 -> V_22 & V_24 ;
} else
F_24 ( V_11 L_2 ) ;
F_25 ( V_17 ) ;
}
}
static int
F_26 ( struct V_1 * V_2 , const struct V_25 * V_26 )
{
char V_27 [ 80 ] ;
const T_3 V_28 = 0x7FFFFFFFFFULL ;
struct V_4 * V_5 ;
T_4 V_29 ;
const struct V_30 * V_31 ;
char * V_32 ;
int error ;
struct V_33 * V_12 = & V_2 -> V_12 ;
V_29 = V_2 ;
V_31 = F_27 ( V_29 ) ;
if ( V_31 == NULL )
return ( - V_34 ) ;
sprintf ( V_27 , L_3 ,
F_28 ( V_29 ) ,
F_29 ( V_29 ) ,
F_30 ( V_29 ) ) ;
V_32 = F_31 ( strlen ( V_27 ) + 1 , V_35 ) ;
if ( V_32 == NULL )
return ( - V_36 ) ;
strcpy ( V_32 , V_27 ) ;
V_5 = F_32 ( NULL , V_32 ) ;
if ( V_5 == NULL )
return ( - V_36 ) ;
if ( F_9 ( V_2 ) ) {
F_19 ( V_5 ) ;
return ( - V_34 ) ;
}
F_11 ( V_2 ) ;
if ( sizeof( V_37 ) > 4
&& V_5 -> V_38 & V_39
&& F_33 ( V_12 , V_28 ) == 0
&& F_34 ( V_12 ) > F_35 ( 32 ) ) {
V_5 -> V_22 |= V_40 ;
} else {
if ( F_33 ( V_12 , F_35 ( 32 ) ) ) {
F_19 ( V_5 ) ;
F_24 ( V_41 L_4 ) ;
return ( - V_34 ) ;
}
}
V_5 -> V_16 = V_29 ;
error = F_36 ( V_5 , V_31 ) ;
if ( error != 0 ) {
F_19 ( V_5 ) ;
return ( - error ) ;
}
if ( ( V_5 -> V_38 & V_42 ) && F_37 ( V_2 -> V_19 ) != 0 )
F_20 ( V_5 ) ;
F_38 ( V_2 , V_5 ) ;
F_39 ( V_5 , & V_43 ) ;
return ( 0 ) ;
}
T_5
F_40 ( T_4 V_29 , int V_44 , int V_45 )
{
switch ( V_45 ) {
case 1 :
{
T_6 V_46 ;
F_41 ( V_29 , V_44 , & V_46 ) ;
return ( V_46 ) ;
}
case 2 :
{
T_7 V_46 ;
F_42 ( V_29 , V_44 , & V_46 ) ;
return ( V_46 ) ;
}
case 4 :
{
T_5 V_46 ;
F_43 ( V_29 , V_44 , & V_46 ) ;
return ( V_46 ) ;
}
default:
F_44 ( L_5 ) ;
return ( 0 ) ;
}
}
void
F_45 ( T_4 V_29 , int V_44 , T_5 V_47 , int V_45 )
{
switch ( V_45 ) {
case 1 :
F_46 ( V_29 , V_44 , V_47 ) ;
break;
case 2 :
F_47 ( V_29 , V_44 , V_47 ) ;
break;
case 4 :
F_48 ( V_29 , V_44 , V_47 ) ;
break;
default:
F_44 ( L_6 ) ;
}
}
int
F_49 ( void )
{
return F_50 ( & V_48 ) ;
}
void
F_51 ( void )
{
F_52 ( & V_48 ) ;
}
static int
F_53 ( struct V_4 * V_5 , T_8 * V_49 )
{
if ( V_50 == 0 )
return ( V_36 ) ;
* V_49 = F_54 ( V_5 -> V_16 , 0 ) ;
if ( * V_49 == 0 )
return ( V_36 ) ;
if ( ! F_55 ( * V_49 , 256 , L_7 ) )
return ( V_36 ) ;
return ( 0 ) ;
}
static int
F_56 ( struct V_4 * V_5 ,
T_8 * V_51 ,
T_6 T_9 * * V_52 )
{
T_8 V_53 ;
int error ;
error = 0 ;
V_53 = F_54 ( V_5 -> V_16 , 1 ) ;
if ( V_53 != 0 ) {
* V_51 = V_53 ;
if ( ! F_57 ( V_53 , 0x1000 , L_7 ) )
error = V_36 ;
if ( error == 0 ) {
* V_52 = F_58 ( V_53 , 256 ) ;
if ( * V_52 == NULL ) {
error = V_36 ;
F_59 ( V_53 , 0x1000 ) ;
}
}
} else
error = V_36 ;
return ( error ) ;
}
int
F_60 ( struct V_4 * V_5 )
{
T_5 V_54 ;
T_8 V_49 ;
T_6 T_9 * V_52 ;
int error ;
V_54 = F_40 ( V_5 -> V_16 , V_55 , 4 ) ;
V_54 &= ~ ( V_56 | V_57 ) ;
V_49 = 0 ;
V_52 = NULL ;
error = F_56 ( V_5 , & V_49 , & V_52 ) ;
if ( error == 0 ) {
V_5 -> V_14 -> V_58 = V_49 ;
V_5 -> V_59 = V_60 ;
V_5 -> V_61 . V_52 = V_52 ;
F_45 ( V_5 -> V_16 , V_55 ,
V_54 | V_57 , 4 ) ;
if ( F_61 ( V_5 ) != 0 ) {
F_24 ( L_8
L_9 ,
F_28 ( V_5 -> V_16 ) ,
F_29 ( V_5 -> V_16 ) ,
F_30 ( V_5 -> V_16 ) ) ;
F_62 ( V_52 ) ;
F_59 ( V_5 -> V_14 -> V_58 ,
0x1000 ) ;
V_5 -> V_61 . V_52 = NULL ;
V_52 = NULL ;
} else
V_54 |= V_57 ;
} else {
F_24 ( L_10
L_11 ,
F_28 ( V_5 -> V_16 ) ,
F_29 ( V_5 -> V_16 ) ,
F_30 ( V_5 -> V_16 ) ,
( unsigned long long ) V_49 ) ;
}
if ( V_52 == NULL ) {
error = F_53 ( V_5 , & V_49 ) ;
if ( error == 0 ) {
V_5 -> V_59 = V_62 ;
V_5 -> V_61 . V_63 = ( T_2 ) V_49 ;
V_54 |= V_56 ;
} else {
F_24 ( L_12
L_13 ,
F_28 ( V_5 -> V_16 ) ,
F_29 ( V_5 -> V_16 ) ,
F_30 ( V_5 -> V_16 ) ,
( unsigned long long ) V_49 ) ;
}
}
F_45 ( V_5 -> V_16 , V_55 , V_54 , 4 ) ;
return ( error ) ;
}
int
F_63 ( struct V_4 * V_5 )
{
int error ;
error = F_64 ( V_5 -> V_16 -> V_64 , V_65 ,
V_66 , L_7 , V_5 ) ;
if ( error == 0 )
V_5 -> V_14 -> V_64 = V_5 -> V_16 -> V_64 ;
return ( - error ) ;
}
