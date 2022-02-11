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
continue;
}
error = F_17 ( V_11 , NULL , & V_13 -> V_2 ,
& V_19 ) ;
if ( error < 0 )
continue;
}
}
static void F_18 ( struct V_7 * V_13 )
{
int V_20 ;
struct V_21 * V_22 = F_19 ( V_13 ) ;
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ ) {
struct V_24 * V_25 =
& V_22 -> V_26 [ V_20 ] ;
V_25 -> type = V_20 ;
V_25 -> V_27 = 0 ;
V_25 -> V_28 = 0 ;
V_25 -> V_22 = V_22 ;
F_20 ( & V_25 -> V_29 ) ;
F_21 ( & V_25 -> V_30 ) ;
}
}
static void F_22 ( struct V_7 * V_13 ,
enum V_31 V_20 )
{
struct V_32 * V_33 ;
struct V_32 * V_34 ;
struct V_21 * V_22 = F_19 ( V_13 ) ;
struct V_24 * V_25 =
& V_22 -> V_26 [ V_20 ] ;
int V_28 = 0 ;
F_2 ( V_25 -> type != V_20 ) ;
F_2 ( V_25 -> V_28 != V_25 -> V_27 ) ;
F_23 (resource, next, &res_pool->free_list, node) {
V_28 ++ ;
F_2 ( V_33 -> type != V_25 -> type ) ;
F_2 ( V_33 -> V_35 != V_25 ) ;
F_24 ( & V_13 -> V_2 , V_33 ) ;
}
F_2 ( V_28 != V_25 -> V_28 ) ;
}
static void F_25 ( struct V_7 * V_13 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ )
F_22 ( V_13 , V_20 ) ;
}
int F_26 ( struct V_7 * V_13 ,
unsigned int * V_36 )
{
int V_37 ;
int V_38 ;
int error ;
unsigned int V_39 = V_13 -> V_11 . V_39 ;
struct V_10 * V_40 = NULL ;
error = F_27 ( V_13 -> V_41 ,
0 ,
V_13 -> V_42 ,
& V_37 ) ;
if ( error < 0 ) {
F_14 ( & V_13 -> V_2 , L_2 ,
error ) ;
return error ;
}
if ( V_37 != 0 ) {
int V_4 ;
V_40 =
F_28 ( & V_13 -> V_2 , V_37 ,
sizeof( * V_40 ) ,
V_43 ) ;
if ( ! V_40 )
return - V_44 ;
V_38 = 0 ;
for ( V_4 = 0 ; V_4 < V_37 ; V_4 ++ ) {
struct V_10 * V_11 =
& V_40 [ V_4 ] ;
error = F_29 ( V_13 -> V_41 ,
0 ,
V_13 -> V_42 ,
V_4 , V_11 ) ;
if ( error < 0 ) {
F_14 ( & V_13 -> V_2 ,
L_3 ,
V_4 , error ) ;
V_11 -> type [ 0 ] = '\0' ;
V_11 -> V_45 = error ;
V_38 ++ ;
continue;
}
if ( ( strcmp ( V_11 -> type , L_4 ) == 0 ) &&
( V_11 -> V_46 < 4 ) )
V_11 -> V_47 |=
V_48 ;
V_39 += V_11 -> V_39 ;
F_30 ( & V_13 -> V_2 ,
L_5 ,
V_11 -> type , V_11 -> V_45 ) ;
}
if ( V_38 != 0 ) {
F_14 ( & V_13 -> V_2 ,
L_6 ,
V_38 , V_37 ) ;
}
}
* V_36 = V_39 ;
F_7 ( V_13 , V_40 ,
V_37 ) ;
F_16 ( V_13 , V_40 ,
V_37 ) ;
if ( V_40 )
F_24 ( & V_13 -> V_2 , V_40 ) ;
return 0 ;
}
int F_31 ( struct V_7 * V_13 )
{
int error ;
unsigned int V_39 ;
struct V_21 * V_22 = F_19 ( V_13 ) ;
F_18 ( V_13 ) ;
F_32 ( & V_22 -> V_49 ) ;
error = F_26 ( V_13 , & V_39 ) ;
F_33 ( & V_22 -> V_49 ) ;
if ( error < 0 )
goto error;
if ( F_34 ( & V_13 -> V_2 ) && ! V_22 -> V_50 ) {
if ( V_39 > V_51 ) {
F_35 ( & V_13 -> V_2 ,
L_7 ,
V_39 , V_51 ) ;
}
error = F_36 (
V_22 ,
V_51 ) ;
if ( error < 0 )
goto error;
}
return 0 ;
error:
F_25 ( V_13 ) ;
return error ;
}
static T_2 F_37 ( int V_52 , void * V_53 )
{
return V_54 ;
}
static T_2 F_38 ( int V_52 , void * V_53 )
{
int error ;
T_1 V_55 ;
struct V_1 * V_2 = V_53 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_21 * V_22 = F_19 ( V_8 ) ;
struct V_56 * V_41 = V_8 -> V_41 ;
struct V_57 * V_57 = V_8 -> V_58 [ 0 ] -> V_57 ;
F_30 ( V_2 , L_8 ,
V_52 , F_39 () ) ;
if ( F_2 ( ! ( V_8 -> V_47 & V_59 ) ) )
return V_60 ;
F_32 ( & V_22 -> V_49 ) ;
if ( F_2 ( ! V_57 || V_57 -> V_61 != ( T_1 ) V_52 ) )
goto V_62;
V_55 = 0 ;
error = F_40 ( V_41 , 0 , V_8 -> V_42 , 0 ,
& V_55 ) ;
if ( error < 0 ) {
F_14 ( V_2 ,
L_9 , error ) ;
goto V_62;
}
error = F_41 ( V_41 , 0 , V_8 -> V_42 , 0 ,
V_55 ) ;
if ( error < 0 ) {
F_14 ( V_2 ,
L_10 , error ) ;
goto V_62;
}
if ( V_55 & ( V_63 |
V_64 |
V_65 |
V_66 |
V_67 ) ) {
unsigned int V_39 ;
error = F_26 ( V_8 , & V_39 ) ;
if ( error < 0 ) {
if ( error != - V_68 ) {
F_14 ( V_2 , L_11 ,
error ) ;
}
goto V_62;
}
if ( V_39 > V_51 ) {
F_35 ( V_2 ,
L_7 ,
V_39 , V_51 ) ;
}
}
V_62:
F_33 ( & V_22 -> V_49 ) ;
return V_60 ;
}
static int F_42 ( struct V_7 * V_8 )
{
int error ;
struct V_56 * V_41 = V_8 -> V_41 ;
F_2 ( V_8 -> V_11 . V_39 != 1 ) ;
error = F_43 ( V_41 , 0 , V_8 -> V_42 , 0 , 0 ) ;
if ( error < 0 ) {
F_14 ( & V_8 -> V_2 ,
L_12 ,
error ) ;
return error ;
}
error = F_44 ( V_41 , 0 , V_8 -> V_42 , 0 , 0x0 ) ;
if ( error < 0 ) {
F_14 ( & V_8 -> V_2 ,
L_13 ,
error ) ;
return error ;
}
error = F_41 ( V_41 , 0 , V_8 -> V_42 , 0 , ~ 0x0U ) ;
if ( error < 0 ) {
F_14 ( & V_8 -> V_2 ,
L_14 ,
error ) ;
return error ;
}
return 0 ;
}
static int F_45 ( struct V_7 * V_8 )
{
int error ;
struct V_69 * V_61 = V_8 -> V_58 [ 0 ] ;
F_2 ( V_8 -> V_11 . V_39 != 1 ) ;
error = F_46 ( & V_8 -> V_2 ,
V_61 -> V_57 -> V_61 ,
F_37 ,
F_38 ,
V_70 | V_71 ,
L_15 ,
& V_8 -> V_2 ) ;
if ( error < 0 ) {
F_14 ( & V_8 -> V_2 ,
L_16 ,
error ) ;
return error ;
}
return 0 ;
}
static int F_47 ( struct V_7 * V_8 )
{
int error ;
error = F_44 ( V_8 -> V_41 , 0 , V_8 -> V_42 , 0 ,
~ 0x0u ) ;
if ( error < 0 ) {
F_14 ( & V_8 -> V_2 ,
L_17 ,
error ) ;
return error ;
}
error = F_43 ( V_8 -> V_41 , 0 , V_8 -> V_42 , 0 , 1 ) ;
if ( error < 0 ) {
F_14 ( & V_8 -> V_2 ,
L_18 ,
error ) ;
return error ;
}
return 0 ;
}
static int F_48 ( struct V_7 * V_8 )
{
int error ;
error = F_49 ( V_8 ) ;
if ( error < 0 )
return error ;
error = F_42 ( V_8 ) ;
if ( error < 0 )
goto V_72;
error = F_45 ( V_8 ) ;
if ( error < 0 )
goto V_72;
error = F_47 ( V_8 ) ;
if ( error < 0 )
goto V_72;
return 0 ;
V_72:
F_50 ( V_8 ) ;
return error ;
}
static int F_51 ( struct V_7 * V_8 )
{
int error ;
T_3 V_73 ;
struct V_1 * V_74 = V_8 -> V_2 . V_75 ;
struct V_21 * V_22 = F_19 ( V_8 ) ;
bool V_76 = false ;
bool V_77 = false ;
if ( F_2 ( strcmp ( V_8 -> V_11 . type , L_19 ) != 0 ) )
return - V_78 ;
if ( F_2 ( F_34 ( & V_8 -> V_2 ) ) )
return - V_78 ;
if ( ! V_8 -> V_41 ) {
if ( F_2 ( V_74 -> V_79 != & V_80 ) )
return - V_78 ;
if ( F_2 ( V_8 -> V_11 . V_81 == 0 ) )
return - V_78 ;
V_73 = V_8 -> V_82 [ 0 ] . V_83 -
V_8 -> V_82 [ 0 ] . V_84 + 1 ;
error = F_52 ( & V_8 -> V_2 ,
V_8 -> V_82 [ 0 ] . V_84 ,
V_73 ,
NULL ,
V_85 ,
& V_8 -> V_41 ) ;
if ( error < 0 )
return error ;
V_76 = true ;
F_53 ( & V_8 -> V_2 ,
F_34 ( V_74 ) ) ;
V_77 = true ;
} else {
struct V_86 * V_87 ;
if ( F_2 ( V_74 -> V_79 == & V_80 ) )
return - V_78 ;
error = F_54 ( V_74 ,
& V_87 ) ;
if ( error < 0 ) {
F_35 ( & V_8 -> V_2 ,
L_20 ) ;
} else {
F_53 ( & V_8 -> V_2 , V_87 ) ;
V_77 = true ;
}
}
error = F_55 ( V_8 -> V_41 , 0 , V_8 -> V_11 . V_45 ,
& V_8 -> V_42 ) ;
if ( error < 0 ) {
F_14 ( & V_8 -> V_2 , L_21 , error ) ;
goto V_88;
}
error = F_56 ( V_8 -> V_41 , 0 , V_8 -> V_42 ,
& V_22 -> V_89 ) ;
if ( error < 0 ) {
F_14 ( & V_8 -> V_2 , L_22 ,
error ) ;
goto V_90;
}
if ( V_22 -> V_89 . V_91 . V_92 < V_93 ||
( V_22 -> V_89 . V_91 . V_92 == V_93 &&
V_22 -> V_89 . V_91 . V_94 < V_95 ) ) {
F_14 ( & V_8 -> V_2 ,
L_23 ,
V_22 -> V_89 . V_91 . V_92 ,
V_22 -> V_89 . V_91 . V_94 ) ;
error = - V_96 ;
goto V_90;
}
F_21 ( & V_22 -> V_49 ) ;
error = F_31 ( V_8 ) ;
if ( error < 0 )
goto V_90;
error = F_48 ( V_8 ) ;
if ( error < 0 )
goto V_90;
F_57 ( & V_8 -> V_2 , L_24 ) ;
return 0 ;
V_90:
( void ) F_58 ( V_8 -> V_41 , 0 , V_8 -> V_42 ) ;
V_88:
if ( V_77 )
F_53 ( & V_8 -> V_2 , NULL ) ;
if ( V_76 ) {
F_59 ( V_8 -> V_41 ) ;
V_8 -> V_41 = NULL ;
}
return error ;
}
static void F_60 ( struct V_7 * V_8 )
{
struct V_69 * V_61 = V_8 -> V_58 [ 0 ] ;
( void ) F_42 ( V_8 ) ;
F_61 ( & V_8 -> V_2 , V_61 -> V_57 -> V_61 , & V_8 -> V_2 ) ;
F_50 ( V_8 ) ;
}
static int F_62 ( struct V_7 * V_8 )
{
int error ;
struct V_21 * V_22 = F_19 ( V_8 ) ;
if ( F_2 ( strcmp ( V_8 -> V_11 . type , L_19 ) != 0 ) )
return - V_78 ;
if ( F_2 ( ! V_8 -> V_41 ) )
return - V_78 ;
if ( F_2 ( ! V_22 -> V_50 ) )
return - V_78 ;
if ( F_34 ( & V_8 -> V_2 ) )
F_60 ( V_8 ) ;
F_8 ( & V_8 -> V_2 , NULL , F_6 ) ;
if ( F_34 ( & V_8 -> V_2 ) ) {
F_63 ( V_22 ) ;
F_53 ( & V_8 -> V_2 , NULL ) ;
}
F_25 ( V_8 ) ;
error = F_58 ( V_8 -> V_41 , 0 , V_8 -> V_42 ) ;
if ( error < 0 )
F_14 ( & V_8 -> V_2 , L_25 , error ) ;
if ( ! F_64 ( & V_8 -> V_2 ) ) {
F_59 ( V_8 -> V_41 ) ;
V_8 -> V_41 = NULL ;
}
F_57 ( & V_8 -> V_2 , L_26 ) ;
return 0 ;
}
int T_4 F_65 ( void )
{
return F_66 ( & V_97 ) ;
}
void F_67 ( void )
{
F_68 ( & V_97 ) ;
}
