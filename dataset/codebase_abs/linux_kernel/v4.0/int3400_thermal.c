static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_10 ;
int V_11 = 0 ;
for ( V_10 = 0 ; V_10 < V_12 ; V_10 ++ ) {
if ( V_9 -> V_13 & ( 1 << V_10 ) )
if ( V_14 - V_11 > 0 )
V_11 += snprintf ( & V_5 [ V_11 ] ,
V_14 - V_11 ,
L_1 ,
V_15 [ V_10 ] ) ;
}
return V_11 ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_16 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
if ( V_9 -> V_13 & ( 1 << V_9 -> V_17 ) )
return sprintf ( V_5 , L_1 ,
V_15 [ V_9 -> V_17 ] ) ;
else
return sprintf ( V_5 , L_2 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_18 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_12 ; ++ V_10 ) {
if ( ( V_9 -> V_13 & ( 1 << V_10 ) ) &&
! ( strncmp ( V_5 , V_15 [ V_10 ] ,
sizeof( V_15 [ V_10 ] ) - 1 ) ) ) {
V_9 -> V_17 = V_10 ;
return V_18 ;
}
}
return - V_19 ;
}
static int F_6 ( struct V_8 * V_9 )
{
struct V_20 V_5 = { V_21 , NULL } ;
union V_22 * V_23 , * V_24 ;
int V_10 , V_25 ;
int V_26 = 0 ;
T_3 V_27 ;
V_27 = F_7 ( V_9 -> V_28 -> V_29 , L_3 , NULL , & V_5 ) ;
if ( F_8 ( V_27 ) )
return - V_30 ;
V_23 = (union V_22 * ) V_5 . V_31 ;
if ( V_23 -> type != V_32 ) {
V_26 = - V_19 ;
goto V_33;
}
for ( V_10 = 0 ; V_10 < V_23 -> V_34 . V_18 ; V_10 ++ ) {
V_24 = & V_23 -> V_34 . V_35 [ V_10 ] ;
if ( V_24 -> type != V_36 ) {
V_26 = - V_19 ;
goto V_33;
}
if ( V_24 -> V_37 . V_11 != 16 ) {
V_26 = - V_19 ;
goto V_33;
}
for ( V_25 = 0 ; V_25 < V_12 ; V_25 ++ ) {
T_4 V_38 [ 16 ] ;
F_9 ( V_15 [ V_25 ] , V_38 ) ;
if ( ! strncmp ( V_38 , V_24 -> V_37 . V_31 , 16 ) ) {
V_9 -> V_13 |= ( 1 << V_25 ) ;
break;
}
}
}
V_33:
F_10 ( V_5 . V_31 ) ;
return V_26 ;
}
static int F_11 ( T_5 V_29 ,
enum V_39 V_38 , bool V_40 )
{
T_6 V_41 , V_5 [ 2 ] ;
T_3 V_27 ;
int V_26 = 0 ;
struct V_42 V_43 = {
. V_44 = V_15 [ V_38 ] ,
. V_45 = 1 ,
. V_46 . V_11 = 8 ,
} ;
V_5 [ V_47 ] = 0 ;
V_5 [ V_48 ] = V_40 ;
V_43 . V_46 . V_31 = V_5 ;
V_27 = F_12 ( V_29 , & V_43 ) ;
if ( F_13 ( V_27 ) ) {
V_41 = * ( ( T_6 * ) ( V_43 . V_41 . V_31 + 4 ) ) ;
if ( V_41 != V_40 )
V_26 = - V_49 ;
} else
V_26 = - V_49 ;
F_10 ( V_43 . V_41 . V_31 ) ;
return V_26 ;
}
static int F_14 ( struct V_50 * V_51 ,
unsigned long * V_52 )
{
* V_52 = 20 * 1000 ;
return 0 ;
}
static int F_15 ( struct V_50 * V_51 ,
enum V_53 * V_54 )
{
struct V_8 * V_9 = V_51 -> V_55 ;
if ( ! V_9 )
return - V_19 ;
* V_54 = V_9 -> V_54 ;
return 0 ;
}
static int F_16 ( struct V_50 * V_51 ,
enum V_53 V_54 )
{
struct V_8 * V_9 = V_51 -> V_55 ;
bool V_40 ;
int V_26 = 0 ;
if ( ! V_9 )
return - V_19 ;
if ( V_54 == V_56 )
V_40 = true ;
else if ( V_54 == V_57 )
V_40 = false ;
else
return - V_19 ;
if ( V_40 != V_9 -> V_54 ) {
V_9 -> V_54 = V_40 ;
V_26 = F_11 ( V_9 -> V_28 -> V_29 ,
V_9 -> V_17 ,
V_40 ) ;
}
return V_26 ;
}
static int F_17 ( struct V_6 * V_7 )
{
struct V_58 * V_28 = F_18 ( & V_7 -> V_2 ) ;
struct V_8 * V_9 ;
int V_26 ;
if ( ! V_28 )
return - V_30 ;
V_9 = F_19 ( sizeof( struct V_8 ) , V_59 ) ;
if ( ! V_9 )
return - V_60 ;
V_9 -> V_28 = V_28 ;
V_26 = F_6 ( V_9 ) ;
if ( V_26 )
goto V_61;
V_26 = F_20 ( V_9 -> V_28 -> V_29 , & V_9 -> V_62 ,
& V_9 -> V_63 , true ) ;
if ( V_26 )
F_21 ( & V_7 -> V_2 , L_4 ) ;
V_26 = F_22 ( V_9 -> V_28 -> V_29 , & V_9 -> V_64 ,
& V_9 -> V_65 , true ) ;
if ( V_26 )
F_21 ( & V_7 -> V_2 , L_5 ) ;
F_23 ( V_7 , V_9 ) ;
if ( V_9 -> V_13 & 1 << V_66 ) {
V_67 . V_68 = F_15 ;
V_67 . V_69 = F_16 ;
}
V_9 -> V_51 = F_24 ( L_6 , 0 , 0 ,
V_9 , & V_67 ,
& V_70 , 0 , 0 ) ;
if ( F_25 ( V_9 -> V_51 ) ) {
V_26 = F_26 ( V_9 -> V_51 ) ;
goto V_71;
}
V_9 -> V_72 = F_27 (
V_9 -> V_28 -> V_29 ) ;
V_26 = F_28 ( & V_7 -> V_2 . V_73 , & V_74 ) ;
if ( V_26 )
goto V_75;
return 0 ;
V_75:
F_29 ( V_9 -> V_51 ) ;
V_71:
F_10 ( V_9 -> V_65 ) ;
F_10 ( V_9 -> V_63 ) ;
V_61:
F_10 ( V_9 ) ;
return V_26 ;
}
static int F_30 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
if ( ! V_9 -> V_72 )
F_31 ( V_9 -> V_28 -> V_29 ) ;
F_32 ( & V_7 -> V_2 . V_73 , & V_74 ) ;
F_29 ( V_9 -> V_51 ) ;
F_10 ( V_9 -> V_65 ) ;
F_10 ( V_9 -> V_63 ) ;
F_10 ( V_9 ) ;
return 0 ;
}
