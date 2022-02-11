static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
int V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
F_2 ( ! V_2 ) ;
F_2 ( ! V_3 ) ;
V_8 = F_3 ( V_2 ) ;
V_6 = V_3 ;
for ( V_4 = 0 ; V_4 < V_6 -> V_9 ; V_4 ++ ) {
struct V_10 * V_11 = & V_6 -> V_12 [ V_4 ] ;
if ( strlen ( V_11 -> type ) != 0 &&
F_4 ( V_8 , V_11 ) )
break;
}
if ( V_4 == V_6 -> V_9 )
F_5 ( V_8 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , void * V_3 )
{
F_2 ( ! V_2 ) ;
F_2 ( V_3 ) ;
F_5 ( F_3 ( V_2 ) ) ;
return 0 ;
}
static void F_7 ( struct V_7 * V_13 ,
struct V_10 * V_14 ,
int V_15 )
{
if ( V_15 != 0 ) {
struct V_5 V_6 ;
V_6 . V_9 = V_15 ;
V_6 . V_12 = V_14 ;
F_8 ( & V_13 -> V_2 , & V_6 ,
F_1 ) ;
} else {
F_8 ( & V_13 -> V_2 , NULL ,
F_6 ) ;
}
}
static int F_9 ( struct V_1 * V_2 , void * V_3 )
{
struct V_10 * V_11 = V_3 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
return F_4 ( V_8 , V_11 ) ;
}
static struct V_7 * F_10 ( struct V_10
* V_11 ,
struct V_7
* V_13 )
{
struct V_1 * V_2 ;
V_2 = F_11 ( & V_13 -> V_2 , V_11 ,
F_9 ) ;
return V_2 ? F_3 ( V_2 ) : NULL ;
}
static void F_12 ( struct V_7 * V_8 ,
struct V_10 * V_11 )
{
int error ;
T_1 V_16 =
V_11 -> V_17 & V_18 ;
if ( V_16 !=
( V_8 -> V_11 . V_17 & V_18 ) ) {
if ( V_16 ) {
V_8 -> V_11 . V_17 |= V_18 ;
error = F_13 ( & V_8 -> V_2 ) ;
if ( error < 0 ) {
F_14 ( & V_8 -> V_2 ,
L_1 ,
error ) ;
}
} else {
V_8 -> V_11 . V_17 &= ~ V_18 ;
F_15 ( & V_8 -> V_2 ) ;
}
}
}
static void F_16 ( struct V_7 * V_13 ,
struct V_10 * V_14 ,
int V_15 )
{
int error ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_15 ; V_4 ++ ) {
struct V_7 * V_19 ;
struct V_10 * V_11 = & V_14 [ V_4 ] ;
if ( strlen ( V_11 -> type ) == 0 )
continue;
V_19 = F_10 ( V_11 , V_13 ) ;
if ( V_19 ) {
F_12 ( V_19 , V_11 ) ;
F_17 ( & V_19 -> V_2 ) ;
continue;
}
error = F_18 ( V_11 , NULL , & V_13 -> V_2 ,
& V_19 ) ;
if ( error < 0 )
continue;
}
}
int F_19 ( struct V_7 * V_13 ,
unsigned int * V_20 )
{
int V_21 ;
int V_22 ;
int error ;
unsigned int V_23 = V_13 -> V_11 . V_23 ;
struct V_10 * V_24 = NULL ;
error = F_20 ( V_13 -> V_25 ,
0 ,
V_13 -> V_26 ,
& V_21 ) ;
if ( error < 0 ) {
F_14 ( & V_13 -> V_2 , L_2 ,
error ) ;
return error ;
}
if ( V_21 != 0 ) {
int V_4 ;
V_24 =
F_21 ( & V_13 -> V_2 , V_21 ,
sizeof( * V_24 ) ,
V_27 ) ;
if ( ! V_24 )
return - V_28 ;
V_22 = 0 ;
for ( V_4 = 0 ; V_4 < V_21 ; V_4 ++ ) {
struct V_10 * V_11 =
& V_24 [ V_4 ] ;
error = F_22 ( V_13 -> V_25 ,
0 ,
V_13 -> V_26 ,
V_4 , V_11 ) ;
if ( error < 0 ) {
F_14 ( & V_13 -> V_2 ,
L_3 ,
V_4 , error ) ;
V_11 -> type [ 0 ] = '\0' ;
V_11 -> V_29 = error ;
V_22 ++ ;
continue;
}
if ( ( strcmp ( V_11 -> type , L_4 ) == 0 ) &&
( V_11 -> V_30 < 4 ) )
V_11 -> V_31 |=
V_32 ;
V_23 += V_11 -> V_23 ;
F_23 ( & V_13 -> V_2 ,
L_5 ,
V_11 -> type , V_11 -> V_29 ) ;
}
if ( V_22 != 0 ) {
F_14 ( & V_13 -> V_2 ,
L_6 ,
V_22 , V_21 ) ;
}
}
* V_20 = V_23 ;
F_7 ( V_13 , V_24 ,
V_21 ) ;
F_16 ( V_13 , V_24 ,
V_21 ) ;
if ( V_24 )
F_24 ( & V_13 -> V_2 , V_24 ) ;
return 0 ;
}
int F_25 ( struct V_7 * V_13 )
{
int error ;
unsigned int V_23 ;
struct V_33 * V_34 = F_26 ( V_13 ) ;
F_27 ( V_13 ) ;
F_28 ( & V_34 -> V_35 ) ;
error = F_19 ( V_13 , & V_23 ) ;
F_29 ( & V_34 -> V_35 ) ;
if ( error < 0 )
goto error;
if ( F_30 ( & V_13 -> V_2 ) && ! V_34 -> V_36 ) {
if ( V_23 > V_37 ) {
F_31 ( & V_13 -> V_2 ,
L_7 ,
V_23 , V_37 ) ;
}
error = F_32 (
V_34 ,
V_37 ) ;
if ( error < 0 )
goto error;
}
return 0 ;
error:
F_33 ( V_13 ) ;
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
struct V_1 * V_2 = V_39 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_33 * V_34 = F_26 ( V_8 ) ;
struct V_42 * V_25 = V_8 -> V_25 ;
struct V_43 * V_43 = V_8 -> V_44 [ 0 ] -> V_43 ;
F_23 ( V_2 , L_8 ,
V_38 , F_36 () ) ;
if ( F_2 ( ! ( V_8 -> V_31 & V_45 ) ) )
return V_46 ;
F_28 ( & V_34 -> V_35 ) ;
if ( F_2 ( ! V_43 || V_43 -> V_47 != ( T_1 ) V_38 ) )
goto V_48;
V_41 = 0 ;
error = F_37 ( V_25 , 0 , V_8 -> V_26 , 0 ,
& V_41 ) ;
if ( error < 0 ) {
F_14 ( V_2 ,
L_9 , error ) ;
goto V_48;
}
error = F_38 ( V_25 , 0 , V_8 -> V_26 , 0 ,
V_41 ) ;
if ( error < 0 ) {
F_14 ( V_2 ,
L_10 , error ) ;
goto V_48;
}
if ( V_41 & ( V_49 |
V_50 |
V_51 |
V_52 |
V_53 ) ) {
unsigned int V_23 ;
error = F_19 ( V_8 , & V_23 ) ;
if ( error < 0 ) {
if ( error != - V_54 ) {
F_14 ( V_2 , L_11 ,
error ) ;
}
goto V_48;
}
if ( V_23 > V_37 ) {
F_31 ( V_2 ,
L_7 ,
V_23 , V_37 ) ;
}
}
V_48:
F_29 ( & V_34 -> V_35 ) ;
return V_46 ;
}
static int F_39 ( struct V_7 * V_8 )
{
int error ;
struct V_42 * V_25 = V_8 -> V_25 ;
F_2 ( V_8 -> V_11 . V_23 != 1 ) ;
error = F_40 ( V_25 , 0 , V_8 -> V_26 , 0 , 0 ) ;
if ( error < 0 ) {
F_14 ( & V_8 -> V_2 ,
L_12 ,
error ) ;
return error ;
}
error = F_41 ( V_25 , 0 , V_8 -> V_26 , 0 , 0x0 ) ;
if ( error < 0 ) {
F_14 ( & V_8 -> V_2 ,
L_13 ,
error ) ;
return error ;
}
error = F_38 ( V_25 , 0 , V_8 -> V_26 , 0 , ~ 0x0U ) ;
if ( error < 0 ) {
F_14 ( & V_8 -> V_2 ,
L_14 ,
error ) ;
return error ;
}
return 0 ;
}
static int F_42 ( struct V_7 * V_8 )
{
int error ;
struct V_55 * V_47 = V_8 -> V_44 [ 0 ] ;
F_2 ( V_8 -> V_11 . V_23 != 1 ) ;
error = F_43 ( & V_8 -> V_2 ,
V_47 -> V_43 -> V_47 ,
F_34 ,
F_35 ,
V_56 | V_57 ,
F_44 ( & V_8 -> V_2 ) ,
& V_8 -> V_2 ) ;
if ( error < 0 ) {
F_14 ( & V_8 -> V_2 ,
L_15 ,
error ) ;
return error ;
}
return 0 ;
}
static int F_45 ( struct V_7 * V_8 )
{
int error ;
error = F_41 ( V_8 -> V_25 , 0 , V_8 -> V_26 , 0 ,
~ 0x0u ) ;
if ( error < 0 ) {
F_14 ( & V_8 -> V_2 ,
L_16 ,
error ) ;
return error ;
}
error = F_40 ( V_8 -> V_25 , 0 , V_8 -> V_26 , 0 , 1 ) ;
if ( error < 0 ) {
F_14 ( & V_8 -> V_2 ,
L_17 ,
error ) ;
return error ;
}
return 0 ;
}
static int F_46 ( struct V_7 * V_8 )
{
int error ;
error = F_47 ( V_8 ) ;
if ( error < 0 )
return error ;
error = F_39 ( V_8 ) ;
if ( error < 0 )
goto V_58;
error = F_42 ( V_8 ) ;
if ( error < 0 )
goto V_58;
error = F_45 ( V_8 ) ;
if ( error < 0 )
goto V_58;
return 0 ;
V_58:
F_48 ( V_8 ) ;
return error ;
}
static int F_49 ( struct V_7 * V_8 )
{
int error ;
T_3 V_59 ;
struct V_1 * V_60 = V_8 -> V_2 . V_61 ;
struct V_33 * V_34 = F_26 ( V_8 ) ;
bool V_62 = false ;
bool V_63 = false ;
T_4 V_64 , V_65 ;
if ( F_2 ( strcmp ( V_8 -> V_11 . type , L_18 ) != 0 ) )
return - V_66 ;
if ( F_2 ( F_30 ( & V_8 -> V_2 ) ) )
return - V_66 ;
if ( ! V_8 -> V_25 ) {
if ( F_2 ( ! F_50 ( V_60 ) ) )
return - V_66 ;
if ( F_2 ( V_8 -> V_11 . V_67 == 0 ) )
return - V_66 ;
V_59 = V_8 -> V_68 [ 0 ] . V_69 -
V_8 -> V_68 [ 0 ] . V_70 + 1 ;
error = F_51 ( & V_8 -> V_2 ,
V_8 -> V_68 [ 0 ] . V_70 ,
V_59 ,
NULL ,
V_71 ,
& V_8 -> V_25 ) ;
if ( error < 0 )
return error ;
V_62 = true ;
F_52 ( & V_8 -> V_2 ,
F_30 ( V_60 ) ) ;
V_63 = true ;
} else {
struct V_72 * V_73 ;
if ( F_2 ( F_50 ( V_60 ) ) )
return - V_66 ;
error = F_53 ( V_60 ,
& V_73 ) ;
if ( error < 0 ) {
F_31 ( & V_8 -> V_2 ,
L_19 ) ;
} else {
F_52 ( & V_8 -> V_2 , V_73 ) ;
V_63 = true ;
}
}
error = F_54 ( V_8 -> V_25 , 0 , V_8 -> V_11 . V_29 ,
& V_8 -> V_26 ) ;
if ( error < 0 ) {
F_14 ( & V_8 -> V_2 , L_20 , error ) ;
goto V_74;
}
error = F_55 ( V_8 -> V_25 , 0 , V_8 -> V_26 ,
& V_34 -> V_75 ) ;
if ( error < 0 ) {
F_14 ( & V_8 -> V_2 , L_21 ,
error ) ;
goto V_76;
}
error = F_56 ( V_8 -> V_25 , 0 ,
& V_64 ,
& V_65 ) ;
if ( error < 0 ) {
F_14 ( & V_8 -> V_2 , L_22 ,
error ) ;
goto V_76;
}
if ( V_64 < V_77 ||
( V_64 == V_77 &&
V_65 < V_78 ) ) {
F_14 ( & V_8 -> V_2 ,
L_23 ,
V_64 , V_65 ) ;
error = - V_79 ;
goto V_76;
}
F_57 ( & V_34 -> V_35 ) ;
error = F_25 ( V_8 ) ;
if ( error < 0 )
goto V_76;
error = F_46 ( V_8 ) ;
if ( error < 0 )
goto V_76;
F_58 ( & V_8 -> V_2 , L_24 ) ;
return 0 ;
V_76:
( void ) F_59 ( V_8 -> V_25 , 0 , V_8 -> V_26 ) ;
V_74:
if ( V_63 )
F_52 ( & V_8 -> V_2 , NULL ) ;
if ( V_62 ) {
F_60 ( V_8 -> V_25 ) ;
V_8 -> V_25 = NULL ;
}
return error ;
}
static void F_61 ( struct V_7 * V_8 )
{
struct V_55 * V_47 = V_8 -> V_44 [ 0 ] ;
( void ) F_39 ( V_8 ) ;
F_62 ( & V_8 -> V_2 , V_47 -> V_43 -> V_47 , & V_8 -> V_2 ) ;
F_48 ( V_8 ) ;
}
static int F_63 ( struct V_7 * V_8 )
{
int error ;
struct V_33 * V_34 = F_26 ( V_8 ) ;
if ( F_2 ( strcmp ( V_8 -> V_11 . type , L_18 ) != 0 ) )
return - V_66 ;
if ( F_2 ( ! V_8 -> V_25 ) )
return - V_66 ;
if ( F_2 ( ! V_34 -> V_36 ) )
return - V_66 ;
if ( F_30 ( & V_8 -> V_2 ) )
F_61 ( V_8 ) ;
F_8 ( & V_8 -> V_2 , NULL , F_6 ) ;
if ( F_30 ( & V_8 -> V_2 ) ) {
F_64 ( V_34 ) ;
F_52 ( & V_8 -> V_2 , NULL ) ;
}
F_33 ( V_8 ) ;
error = F_59 ( V_8 -> V_25 , 0 , V_8 -> V_26 ) ;
if ( error < 0 )
F_14 ( & V_8 -> V_2 , L_25 , error ) ;
if ( ! F_65 ( & V_8 -> V_2 ) ) {
F_60 ( V_8 -> V_25 ) ;
V_8 -> V_25 = NULL ;
}
F_58 ( & V_8 -> V_2 , L_26 ) ;
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
