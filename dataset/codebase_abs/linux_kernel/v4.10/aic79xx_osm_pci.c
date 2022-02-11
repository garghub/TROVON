static int
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
if ( ( V_6 = F_3 ( V_5 ) ) )
return V_6 ;
F_4 ( V_5 ) ;
F_5 ( V_2 ) ;
F_6 ( V_2 ) ;
if ( V_3 . V_7 & V_8 )
F_7 ( V_2 , V_9 ) ;
return V_6 ;
}
static int
F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
F_7 ( V_2 , V_10 ) ;
F_9 ( V_2 ) ;
if ( ( V_6 = F_10 ( V_2 ) ) ) {
F_11 ( V_11 , & V_2 -> V_12 ,
L_1 , V_6 ) ;
return V_6 ;
}
F_12 ( V_2 ) ;
F_13 ( V_5 ) ;
F_14 ( V_5 ) ;
return V_6 ;
}
static void
F_15 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_13 ;
if ( V_5 -> V_14 && V_5 -> V_14 -> V_15 )
F_16 ( V_5 -> V_14 -> V_15 ) ;
F_17 ( V_5 , & V_13 ) ;
F_18 ( V_5 , FALSE ) ;
F_19 ( V_5 , & V_13 ) ;
F_20 ( V_5 ) ;
}
static void
F_21 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_16 , * V_17 ;
unsigned int V_18 = F_22 ( F_23 ( V_2 -> V_19 ) , 0 ) ;
V_17 = F_24 ( V_2 -> V_20 , V_18 ) ;
if ( V_17 ) {
struct V_4 * V_21 = F_2 ( V_17 ) ;
if ( V_21 ) {
V_5 -> V_22 &= ~ V_23 ;
V_5 -> V_22 |= V_21 -> V_22 & V_23 ;
} else
F_25 ( V_11 L_2 ) ;
F_26 ( V_17 ) ;
}
}
static int
F_27 ( struct V_1 * V_2 , const struct V_24 * V_25 )
{
char V_26 [ 80 ] ;
struct V_4 * V_5 ;
T_3 V_27 ;
const struct V_28 * V_29 ;
char * V_30 ;
int error ;
struct V_31 * V_12 = & V_2 -> V_12 ;
V_27 = V_2 ;
V_29 = F_28 ( V_27 ) ;
if ( V_29 == NULL )
return ( - V_32 ) ;
sprintf ( V_26 , L_3 ,
F_29 ( V_27 ) ,
F_30 ( V_27 ) ,
F_31 ( V_27 ) ) ;
V_30 = F_32 ( V_26 , V_33 ) ;
if ( V_30 == NULL )
return ( - V_34 ) ;
V_5 = F_33 ( NULL , V_30 ) ;
if ( V_5 == NULL )
return ( - V_34 ) ;
if ( F_10 ( V_2 ) ) {
F_20 ( V_5 ) ;
return ( - V_32 ) ;
}
F_12 ( V_2 ) ;
if ( sizeof( V_35 ) > 4 ) {
const T_4 V_36 = F_34 ( V_12 ) ;
if ( V_36 > F_35 ( 39 ) &&
F_36 ( V_12 , F_35 ( 64 ) ) == 0 )
V_5 -> V_22 |= V_37 ;
else if ( V_36 > F_35 ( 32 ) &&
F_36 ( V_12 , F_35 ( 39 ) ) == 0 )
V_5 -> V_22 |= V_38 ;
else
F_36 ( V_12 , F_35 ( 32 ) ) ;
} else {
F_36 ( V_12 , F_35 ( 32 ) ) ;
}
V_5 -> V_16 = V_27 ;
error = F_37 ( V_5 , V_29 ) ;
if ( error != 0 ) {
F_20 ( V_5 ) ;
return ( - error ) ;
}
if ( ( V_5 -> V_39 & V_40 ) && F_38 ( V_2 -> V_19 ) != 0 )
F_21 ( V_5 ) ;
F_39 ( V_2 , V_5 ) ;
F_40 ( V_5 , & V_41 ) ;
return ( 0 ) ;
}
int
F_41 ( void )
{
return F_42 ( & V_42 ) ;
}
void
F_43 ( void )
{
F_44 ( & V_42 ) ;
}
static int
F_45 ( struct V_4 * V_5 , T_5 * V_43 ,
T_5 * V_44 )
{
* V_43 = F_46 ( V_5 -> V_16 , 0 ) ;
* V_44 = F_46 ( V_5 -> V_16 , 3 ) ;
if ( * V_43 == 0 || * V_44 == 0 )
return ( V_34 ) ;
if ( ! F_47 ( * V_43 , 256 , L_4 ) )
return ( V_34 ) ;
if ( ! F_47 ( * V_44 , 256 , L_4 ) ) {
F_48 ( * V_43 , 256 ) ;
return ( V_34 ) ;
}
return ( 0 ) ;
}
static int
F_49 ( struct V_4 * V_5 ,
T_5 * V_45 ,
T_6 T_7 * * V_46 )
{
T_5 V_47 ;
T_5 V_48 ;
T_2 V_49 ;
int error = 0 ;
if ( V_50 == 0 )
return ( V_34 ) ;
if ( ( V_5 -> V_51 & V_52 ) != 0 )
return ( V_34 ) ;
V_47 = F_46 ( V_5 -> V_16 , 1 ) ;
V_48 = V_47 & V_53 ;
V_49 = V_47 - V_48 ;
if ( V_47 != 0 ) {
* V_45 = V_47 ;
if ( ! F_50 ( V_47 , 0x1000 , L_4 ) )
error = V_34 ;
if ( ! error ) {
* V_46 = F_51 ( V_48 , V_49 + 512 ) ;
if ( * V_46 == NULL ) {
error = V_34 ;
F_52 ( V_47 , 0x1000 ) ;
} else
* V_46 += V_49 ;
}
} else
error = V_34 ;
return ( error ) ;
}
int
F_53 ( struct V_4 * V_5 )
{
T_8 V_54 ;
T_5 V_43 ;
T_6 T_7 * V_46 ;
int error ;
V_54 = F_54 ( V_5 -> V_16 , V_55 , 4 ) ;
V_54 &= ~ ( V_56 | V_57 ) ;
V_43 = 0 ;
V_46 = NULL ;
error = F_49 ( V_5 , & V_43 , & V_46 ) ;
if ( error == 0 ) {
V_5 -> V_14 -> V_58 = V_43 ;
V_5 -> V_59 [ 0 ] = V_60 ;
V_5 -> V_61 [ 0 ] . V_46 = V_46 ;
V_5 -> V_59 [ 1 ] = V_60 ;
V_5 -> V_61 [ 1 ] . V_46 = V_46 + 0x100 ;
F_55 ( V_5 -> V_16 , V_55 ,
V_54 | V_57 , 4 ) ;
if ( F_56 ( V_5 ) != 0 ) {
F_25 ( L_5
L_6 ,
F_29 ( V_5 -> V_16 ) ,
F_30 ( V_5 -> V_16 ) ,
F_31 ( V_5 -> V_16 ) ) ;
F_57 ( V_46 ) ;
F_52 ( V_5 -> V_14 -> V_58 ,
0x1000 ) ;
V_5 -> V_61 [ 0 ] . V_46 = NULL ;
V_46 = NULL ;
} else
V_54 |= V_57 ;
} else if ( V_62 ) {
F_25 ( L_7
L_8 ,
F_29 ( V_5 -> V_16 ) ,
F_30 ( V_5 -> V_16 ) ,
F_31 ( V_5 -> V_16 ) ,
( unsigned long long ) V_43 ) ;
}
if ( V_46 == NULL ) {
T_5 V_44 ;
error = F_45 ( V_5 , & V_43 , & V_44 ) ;
if ( error == 0 ) {
V_5 -> V_59 [ 0 ] = V_63 ;
V_5 -> V_59 [ 1 ] = V_63 ;
V_5 -> V_61 [ 0 ] . V_64 = ( T_2 ) V_43 ;
V_5 -> V_61 [ 1 ] . V_64 = ( T_2 ) V_44 ;
V_54 |= V_56 ;
} else {
F_25 ( L_9
L_10 ,
F_29 ( V_5 -> V_16 ) ,
F_30 ( V_5 -> V_16 ) ,
F_31 ( V_5 -> V_16 ) ,
( unsigned long long ) V_43 ,
( unsigned long long ) V_44 ) ;
}
}
F_55 ( V_5 -> V_16 , V_55 , V_54 , 4 ) ;
return ( error ) ;
}
int
F_58 ( struct V_4 * V_5 )
{
int error ;
error = F_59 ( V_5 -> V_16 -> V_65 , V_66 ,
V_67 , L_4 , V_5 ) ;
if ( ! error )
V_5 -> V_14 -> V_65 = V_5 -> V_16 -> V_65 ;
return ( - error ) ;
}
void
F_60 ( struct V_4 * V_5 , T_9 V_68 )
{
F_7 ( V_5 -> V_16 , V_68 ) ;
}
