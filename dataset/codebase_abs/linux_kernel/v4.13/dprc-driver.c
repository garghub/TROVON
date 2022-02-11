static bool F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return V_2 -> V_4 . V_5 == V_4 -> V_5 &&
! strcmp ( V_2 -> V_4 . type , V_4 -> type ) ;
}
static int F_2 ( struct V_6 * V_7 , void * V_8 )
{
int V_9 ;
struct V_10 * V_11 ;
struct V_1 * V_2 ;
F_3 ( ! V_7 ) ;
F_3 ( ! V_8 ) ;
V_2 = F_4 ( V_7 ) ;
V_11 = V_8 ;
for ( V_9 = 0 ; V_9 < V_11 -> V_12 ; V_9 ++ ) {
struct V_3 * V_4 = & V_11 -> V_13 [ V_9 ] ;
if ( strlen ( V_4 -> type ) != 0 &&
F_1 ( V_2 , V_4 ) )
break;
}
if ( V_9 == V_11 -> V_12 )
F_5 ( V_2 ) ;
return 0 ;
}
static int F_6 ( struct V_6 * V_7 , void * V_8 )
{
F_3 ( ! V_7 ) ;
F_3 ( V_8 ) ;
F_5 ( F_4 ( V_7 ) ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_14 ,
struct V_3 * V_15 ,
int V_16 )
{
if ( V_16 != 0 ) {
struct V_10 V_11 ;
V_11 . V_12 = V_16 ;
V_11 . V_13 = V_15 ;
F_8 ( & V_14 -> V_7 , & V_11 ,
F_2 ) ;
} else {
F_8 ( & V_14 -> V_7 , NULL ,
F_6 ) ;
}
}
static int F_9 ( struct V_6 * V_7 , void * V_8 )
{
struct V_3 * V_4 = V_8 ;
struct V_1 * V_2 = F_4 ( V_7 ) ;
return F_1 ( V_2 , V_4 ) ;
}
static struct V_1 * F_10 ( struct V_3
* V_4 ,
struct V_1
* V_14 )
{
struct V_6 * V_7 ;
V_7 = F_11 ( & V_14 -> V_7 , V_4 ,
F_9 ) ;
return V_7 ? F_4 ( V_7 ) : NULL ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int error ;
T_1 V_17 =
V_4 -> V_18 & V_19 ;
if ( V_17 !=
( V_2 -> V_4 . V_18 & V_19 ) ) {
if ( V_17 ) {
V_2 -> V_4 . V_18 |= V_19 ;
error = F_13 ( & V_2 -> V_7 ) ;
if ( error < 0 ) {
F_14 ( & V_2 -> V_7 ,
L_1 ,
error ) ;
}
} else {
V_2 -> V_4 . V_18 &= ~ V_19 ;
F_15 ( & V_2 -> V_7 ) ;
}
}
}
static void F_16 ( struct V_1 * V_14 ,
struct V_3 * V_15 ,
int V_16 )
{
int error ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_16 ; V_9 ++ ) {
struct V_1 * V_20 ;
struct V_3 * V_4 = & V_15 [ V_9 ] ;
if ( strlen ( V_4 -> type ) == 0 )
continue;
V_20 = F_10 ( V_4 , V_14 ) ;
if ( V_20 ) {
F_12 ( V_20 , V_4 ) ;
F_17 ( & V_20 -> V_7 ) ;
continue;
}
error = F_18 ( V_4 , NULL , & V_14 -> V_7 ,
& V_20 ) ;
if ( error < 0 )
continue;
}
}
static int F_19 ( struct V_1 * V_14 ,
unsigned int * V_21 )
{
int V_22 ;
int V_23 ;
int error ;
unsigned int V_24 = V_14 -> V_4 . V_24 ;
struct V_3 * V_25 = NULL ;
error = F_20 ( V_14 -> V_26 ,
0 ,
V_14 -> V_27 ,
& V_22 ) ;
if ( error < 0 ) {
F_14 ( & V_14 -> V_7 , L_2 ,
error ) ;
return error ;
}
if ( V_22 != 0 ) {
int V_9 ;
V_25 =
F_21 ( & V_14 -> V_7 , V_22 ,
sizeof( * V_25 ) ,
V_28 ) ;
if ( ! V_25 )
return - V_29 ;
V_23 = 0 ;
for ( V_9 = 0 ; V_9 < V_22 ; V_9 ++ ) {
struct V_3 * V_4 =
& V_25 [ V_9 ] ;
error = F_22 ( V_14 -> V_26 ,
0 ,
V_14 -> V_27 ,
V_9 , V_4 ) ;
if ( error < 0 ) {
F_14 ( & V_14 -> V_7 ,
L_3 ,
V_9 , error ) ;
V_4 -> type [ 0 ] = '\0' ;
V_4 -> V_5 = error ;
V_23 ++ ;
continue;
}
if ( ( strcmp ( V_4 -> type , L_4 ) == 0 ) &&
( V_4 -> V_30 < 4 ) )
V_4 -> V_31 |=
V_32 ;
V_24 += V_4 -> V_24 ;
F_23 ( & V_14 -> V_7 ,
L_5 ,
V_4 -> type , V_4 -> V_5 ) ;
}
if ( V_23 != 0 ) {
F_14 ( & V_14 -> V_7 ,
L_6 ,
V_23 , V_22 ) ;
}
}
* V_21 = V_24 ;
F_7 ( V_14 , V_25 ,
V_22 ) ;
F_16 ( V_14 , V_25 ,
V_22 ) ;
if ( V_25 )
F_24 ( & V_14 -> V_7 , V_25 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_14 )
{
int error ;
unsigned int V_24 ;
struct V_33 * V_34 = F_26 ( V_14 ) ;
F_27 ( V_14 ) ;
F_28 ( & V_34 -> V_35 ) ;
error = F_19 ( V_14 , & V_24 ) ;
F_29 ( & V_34 -> V_35 ) ;
if ( error < 0 )
goto error;
if ( F_30 ( & V_14 -> V_7 ) && ! V_34 -> V_36 ) {
if ( V_24 > V_37 ) {
F_31 ( & V_14 -> V_7 ,
L_7 ,
V_24 , V_37 ) ;
}
error = F_32 (
V_34 ,
V_37 ) ;
if ( error < 0 )
goto error;
}
return 0 ;
error:
F_33 ( V_14 ) ;
return error ;
}
static T_2 F_34 ( int V_38 , void * V_39 )
{
return V_40 ;
}
static T_2 F_35 ( int V_38 , void * V_39 )
{
int error ;
T_1 V_41 ;
struct V_6 * V_7 = V_39 ;
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_33 * V_34 = F_26 ( V_2 ) ;
struct V_42 * V_26 = V_2 -> V_26 ;
struct V_43 * V_43 = V_2 -> V_44 [ 0 ] -> V_43 ;
F_23 ( V_7 , L_8 ,
V_38 , F_36 () ) ;
if ( F_3 ( ! ( V_2 -> V_31 & V_45 ) ) )
return V_46 ;
F_28 ( & V_34 -> V_35 ) ;
if ( F_3 ( ! V_43 || V_43 -> V_47 != ( T_1 ) V_38 ) )
goto V_48;
V_41 = 0 ;
error = F_37 ( V_26 , 0 , V_2 -> V_27 , 0 ,
& V_41 ) ;
if ( error < 0 ) {
F_14 ( V_7 ,
L_9 , error ) ;
goto V_48;
}
error = F_38 ( V_26 , 0 , V_2 -> V_27 , 0 ,
V_41 ) ;
if ( error < 0 ) {
F_14 ( V_7 ,
L_10 , error ) ;
goto V_48;
}
if ( V_41 & ( V_49 |
V_50 |
V_51 |
V_52 |
V_53 ) ) {
unsigned int V_24 ;
error = F_19 ( V_2 , & V_24 ) ;
if ( error < 0 ) {
if ( error != - V_54 ) {
F_14 ( V_7 , L_11 ,
error ) ;
}
goto V_48;
}
if ( V_24 > V_37 ) {
F_31 ( V_7 ,
L_7 ,
V_24 , V_37 ) ;
}
}
V_48:
F_29 ( & V_34 -> V_35 ) ;
return V_46 ;
}
static int F_39 ( struct V_1 * V_2 )
{
int error ;
struct V_42 * V_26 = V_2 -> V_26 ;
F_3 ( V_2 -> V_4 . V_24 != 1 ) ;
error = F_40 ( V_26 , 0 , V_2 -> V_27 , 0 , 0 ) ;
if ( error < 0 ) {
F_14 ( & V_2 -> V_7 ,
L_12 ,
error ) ;
return error ;
}
error = F_41 ( V_26 , 0 , V_2 -> V_27 , 0 , 0x0 ) ;
if ( error < 0 ) {
F_14 ( & V_2 -> V_7 ,
L_13 ,
error ) ;
return error ;
}
error = F_38 ( V_26 , 0 , V_2 -> V_27 , 0 , ~ 0x0U ) ;
if ( error < 0 ) {
F_14 ( & V_2 -> V_7 ,
L_14 ,
error ) ;
return error ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
int error ;
struct V_55 * V_47 = V_2 -> V_44 [ 0 ] ;
F_3 ( V_2 -> V_4 . V_24 != 1 ) ;
error = F_43 ( & V_2 -> V_7 ,
V_47 -> V_43 -> V_47 ,
F_34 ,
F_35 ,
V_56 | V_57 ,
F_44 ( & V_2 -> V_7 ) ,
& V_2 -> V_7 ) ;
if ( error < 0 ) {
F_14 ( & V_2 -> V_7 ,
L_15 ,
error ) ;
return error ;
}
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
int error ;
error = F_41 ( V_2 -> V_26 , 0 , V_2 -> V_27 , 0 ,
~ 0x0u ) ;
if ( error < 0 ) {
F_14 ( & V_2 -> V_7 ,
L_16 ,
error ) ;
return error ;
}
error = F_40 ( V_2 -> V_26 , 0 , V_2 -> V_27 , 0 , 1 ) ;
if ( error < 0 ) {
F_14 ( & V_2 -> V_7 ,
L_17 ,
error ) ;
return error ;
}
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
int error ;
error = F_47 ( V_2 ) ;
if ( error < 0 )
return error ;
error = F_39 ( V_2 ) ;
if ( error < 0 )
goto V_58;
error = F_42 ( V_2 ) ;
if ( error < 0 )
goto V_58;
error = F_45 ( V_2 ) ;
if ( error < 0 )
goto V_58;
return 0 ;
V_58:
F_48 ( V_2 ) ;
return error ;
}
static int F_49 ( struct V_1 * V_2 )
{
int error ;
T_3 V_59 ;
struct V_6 * V_60 = V_2 -> V_7 . V_61 ;
struct V_33 * V_34 = F_26 ( V_2 ) ;
bool V_62 = false ;
bool V_63 = false ;
T_4 V_64 , V_65 ;
if ( F_3 ( strcmp ( V_2 -> V_4 . type , L_18 ) != 0 ) )
return - V_66 ;
if ( F_3 ( F_30 ( & V_2 -> V_7 ) ) )
return - V_66 ;
if ( ! V_2 -> V_26 ) {
if ( F_3 ( ! F_50 ( V_60 ) ) )
return - V_66 ;
if ( F_3 ( V_2 -> V_4 . V_67 == 0 ) )
return - V_66 ;
V_59 = V_2 -> V_68 [ 0 ] . V_69 -
V_2 -> V_68 [ 0 ] . V_70 + 1 ;
error = F_51 ( & V_2 -> V_7 ,
V_2 -> V_68 [ 0 ] . V_70 ,
V_59 ,
NULL ,
V_71 ,
& V_2 -> V_26 ) ;
if ( error < 0 )
return error ;
V_62 = true ;
F_52 ( & V_2 -> V_7 ,
F_30 ( V_60 ) ) ;
V_63 = true ;
} else {
struct V_72 * V_73 ;
if ( F_3 ( F_50 ( V_60 ) ) )
return - V_66 ;
error = F_53 ( V_60 ,
& V_73 ) ;
if ( error < 0 ) {
F_31 ( & V_2 -> V_7 ,
L_19 ) ;
} else {
F_52 ( & V_2 -> V_7 , V_73 ) ;
V_63 = true ;
}
}
error = F_54 ( V_2 -> V_26 , 0 , V_2 -> V_4 . V_5 ,
& V_2 -> V_27 ) ;
if ( error < 0 ) {
F_14 ( & V_2 -> V_7 , L_20 , error ) ;
goto V_74;
}
error = F_55 ( V_2 -> V_26 , 0 , V_2 -> V_27 ,
& V_34 -> V_75 ) ;
if ( error < 0 ) {
F_14 ( & V_2 -> V_7 , L_21 ,
error ) ;
goto V_76;
}
error = F_56 ( V_2 -> V_26 , 0 ,
& V_64 ,
& V_65 ) ;
if ( error < 0 ) {
F_14 ( & V_2 -> V_7 , L_22 ,
error ) ;
goto V_76;
}
if ( V_64 < V_77 ||
( V_64 == V_77 &&
V_65 < V_78 ) ) {
F_14 ( & V_2 -> V_7 ,
L_23 ,
V_64 , V_65 ) ;
error = - V_79 ;
goto V_76;
}
F_57 ( & V_34 -> V_35 ) ;
error = F_25 ( V_2 ) ;
if ( error < 0 )
goto V_76;
error = F_46 ( V_2 ) ;
if ( error < 0 )
goto V_76;
F_58 ( & V_2 -> V_7 , L_24 ) ;
return 0 ;
V_76:
( void ) F_59 ( V_2 -> V_26 , 0 , V_2 -> V_27 ) ;
V_74:
if ( V_63 )
F_52 ( & V_2 -> V_7 , NULL ) ;
if ( V_62 ) {
F_60 ( V_2 -> V_26 ) ;
V_2 -> V_26 = NULL ;
}
return error ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_55 * V_47 = V_2 -> V_44 [ 0 ] ;
( void ) F_39 ( V_2 ) ;
F_62 ( & V_2 -> V_7 , V_47 -> V_43 -> V_47 , & V_2 -> V_7 ) ;
F_48 ( V_2 ) ;
}
static int F_63 ( struct V_1 * V_2 )
{
int error ;
struct V_33 * V_34 = F_26 ( V_2 ) ;
if ( F_3 ( strcmp ( V_2 -> V_4 . type , L_18 ) != 0 ) )
return - V_66 ;
if ( F_3 ( ! V_2 -> V_26 ) )
return - V_66 ;
if ( F_3 ( ! V_34 -> V_36 ) )
return - V_66 ;
if ( F_30 ( & V_2 -> V_7 ) )
F_61 ( V_2 ) ;
F_8 ( & V_2 -> V_7 , NULL , F_6 ) ;
if ( F_30 ( & V_2 -> V_7 ) ) {
F_64 ( V_34 ) ;
F_52 ( & V_2 -> V_7 , NULL ) ;
}
F_33 ( V_2 ) ;
error = F_59 ( V_2 -> V_26 , 0 , V_2 -> V_27 ) ;
if ( error < 0 )
F_14 ( & V_2 -> V_7 , L_25 , error ) ;
if ( ! F_65 ( & V_2 -> V_7 ) ) {
F_60 ( V_2 -> V_26 ) ;
V_2 -> V_26 = NULL ;
}
F_58 ( & V_2 -> V_7 , L_26 ) ;
return 0 ;
}
int T_5 F_66 ( void )
{
return F_67 ( & V_80 ) ;
}
void F_68 ( void )
{
F_69 ( & V_80 ) ;
}
