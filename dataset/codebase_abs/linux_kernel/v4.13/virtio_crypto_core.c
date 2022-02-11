void
F_1 ( struct V_1 * V_2 )
{
if ( V_2 ) {
F_2 ( V_2 -> V_3 ) ;
F_2 ( V_2 -> V_4 ) ;
F_3 ( V_2 -> V_5 ) ;
}
}
static void F_4 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 -> V_11 ;
struct V_1 * V_2 ;
unsigned long V_12 ;
unsigned int V_13 ;
struct V_14 * V_15 ;
int error ;
unsigned int V_16 = V_7 -> V_17 ;
F_5 ( & V_9 -> V_18 [ V_16 ] . V_19 , V_12 ) ;
do {
F_6 ( V_7 ) ;
while ( ( V_2 = F_7 ( V_7 , & V_13 ) ) != NULL ) {
if ( V_2 -> type == V_20 ) {
switch ( V_2 -> V_21 ) {
case V_22 :
error = 0 ;
break;
case V_23 :
case V_24 :
error = - V_25 ;
break;
case V_26 :
error = - V_27 ;
break;
default:
error = - V_28 ;
break;
}
V_15 = V_2 -> V_29 ;
F_8 (
& V_9 -> V_18 [ V_16 ] . V_19 , V_12 ) ;
F_9 ( V_2 ,
V_15 , error ) ;
F_5 (
& V_9 -> V_18 [ V_16 ] . V_19 , V_12 ) ;
}
}
} while ( ! F_10 ( V_7 ) );
F_8 ( & V_9 -> V_18 [ V_16 ] . V_19 , V_12 ) ;
}
static int F_11 ( struct V_8 * V_30 )
{
T_1 * * V_31 ;
struct V_6 * * V_32 ;
int V_33 = - V_34 ;
int V_35 , V_36 ;
const char * * V_37 ;
struct V_38 * V_39 = & V_30 -> V_10 -> V_39 ;
V_36 = V_30 -> V_40 + 1 ;
V_32 = F_12 ( V_36 , sizeof( * V_32 ) , V_41 ) ;
if ( ! V_32 )
goto V_42;
V_31 = F_12 ( V_36 , sizeof( * V_31 ) , V_41 ) ;
if ( ! V_31 )
goto V_43;
V_37 = F_12 ( V_36 , sizeof( * V_37 ) , V_41 ) ;
if ( ! V_37 )
goto V_44;
V_31 [ V_36 - 1 ] = NULL ;
V_37 [ V_36 - 1 ] = L_1 ;
for ( V_35 = 0 ; V_35 < V_30 -> V_40 ; V_35 ++ ) {
V_31 [ V_35 ] = F_4 ;
snprintf ( V_30 -> V_18 [ V_35 ] . V_45 , sizeof( V_30 -> V_18 [ V_35 ] . V_45 ) ,
L_2 , V_35 ) ;
V_37 [ V_35 ] = V_30 -> V_18 [ V_35 ] . V_45 ;
}
V_33 = F_13 ( V_30 -> V_10 , V_36 , V_32 , V_31 , V_37 , NULL ) ;
if ( V_33 )
goto V_46;
V_30 -> V_47 = V_32 [ V_36 - 1 ] ;
for ( V_35 = 0 ; V_35 < V_30 -> V_40 ; V_35 ++ ) {
F_14 ( & V_30 -> V_18 [ V_35 ] . V_19 ) ;
V_30 -> V_18 [ V_35 ] . V_7 = V_32 [ V_35 ] ;
V_30 -> V_18 [ V_35 ] . V_48 = F_15 ( V_39 , 1 ) ;
if ( ! V_30 -> V_18 [ V_35 ] . V_48 ) {
V_33 = - V_34 ;
goto V_49;
}
V_30 -> V_18 [ V_35 ] . V_48 -> V_50 =
V_51 ;
}
F_3 ( V_37 ) ;
F_3 ( V_31 ) ;
F_3 ( V_32 ) ;
return 0 ;
V_49:
V_46:
F_3 ( V_37 ) ;
V_44:
F_3 ( V_31 ) ;
V_43:
F_3 ( V_32 ) ;
V_42:
return V_33 ;
}
static int F_16 ( struct V_8 * V_30 )
{
V_30 -> V_18 = F_12 ( V_30 -> V_40 , sizeof( * V_30 -> V_18 ) ,
V_41 ) ;
if ( ! V_30 -> V_18 )
return - V_34 ;
return 0 ;
}
static void F_17 ( struct V_8 * V_30 , long V_52 )
{
int V_35 ;
if ( V_30 -> V_53 ) {
for ( V_35 = 0 ; V_35 < V_30 -> V_40 ; V_35 ++ )
F_18 ( V_30 -> V_18 [ V_35 ] . V_7 , - 1 ) ;
V_30 -> V_53 = false ;
}
}
static void F_19 ( struct V_8 * V_9 )
{
int V_35 = 0 ;
int V_54 ;
if ( V_9 -> V_55 == 1 || V_9 -> V_40 == 1 ) {
F_17 ( V_9 , - 1 ) ;
return;
}
F_20 (cpu) {
F_18 ( V_9 -> V_18 [ V_35 ] . V_7 , V_54 ) ;
if ( ++ V_35 >= V_9 -> V_40 )
break;
}
V_9 -> V_53 = true ;
}
static void F_21 ( struct V_8 * V_30 )
{
F_3 ( V_30 -> V_18 ) ;
}
static int F_22 ( struct V_8 * V_30 )
{
int V_33 ;
V_33 = F_16 ( V_30 ) ;
if ( V_33 )
goto V_56;
V_33 = F_11 ( V_30 ) ;
if ( V_33 )
goto V_57;
F_23 () ;
F_19 ( V_30 ) ;
F_24 () ;
return 0 ;
V_57:
F_21 ( V_30 ) ;
V_56:
return V_33 ;
}
static int F_25 ( struct V_8 * V_9 )
{
T_2 V_21 ;
int V_56 ;
F_26 ( V_9 -> V_10 ,
struct V_58 , V_21 , & V_21 ) ;
if ( V_21 & ( ~ V_59 ) ) {
F_27 ( & V_9 -> V_10 -> V_39 ,
L_3 , V_21 ) ;
F_28 ( V_9 -> V_10 ) ;
return - V_60 ;
}
if ( V_9 -> V_21 == V_21 )
return 0 ;
V_9 -> V_21 = V_21 ;
if ( V_9 -> V_21 & V_59 ) {
V_56 = F_29 ( V_9 ) ;
if ( V_56 ) {
F_30 ( & V_9 -> V_10 -> V_39 ,
L_4 ) ;
return - V_60 ;
}
F_31 ( & V_9 -> V_10 -> V_39 , L_5 ) ;
} else {
F_32 ( V_9 ) ;
F_31 ( & V_9 -> V_10 -> V_39 , L_6 ) ;
}
return 0 ;
}
static int F_33 ( struct V_8 * V_9 )
{
T_3 V_35 ;
int V_33 ;
for ( V_35 = 0 ; V_35 < V_9 -> V_40 ; V_35 ++ ) {
if ( V_9 -> V_18 [ V_35 ] . V_48 ) {
V_33 = F_34 ( V_9 -> V_18 [ V_35 ] . V_48 ) ;
if ( V_33 )
goto V_56;
}
}
return 0 ;
V_56:
while ( -- V_35 >= 0 )
if ( V_9 -> V_18 [ V_35 ] . V_48 )
F_35 ( V_9 -> V_18 [ V_35 ] . V_48 ) ;
return V_33 ;
}
static void F_36 ( struct V_8 * V_9 )
{
T_2 V_35 ;
for ( V_35 = 0 ; V_35 < V_9 -> V_40 ; V_35 ++ )
if ( V_9 -> V_18 [ V_35 ] . V_48 )
F_35 ( V_9 -> V_18 [ V_35 ] . V_48 ) ;
}
static void F_37 ( struct V_8 * V_9 )
{
struct V_61 * V_10 = V_9 -> V_10 ;
F_17 ( V_9 , - 1 ) ;
V_10 -> V_62 -> V_63 ( V_10 ) ;
F_21 ( V_9 ) ;
}
static int F_38 ( struct V_61 * V_10 )
{
int V_56 = - V_64 ;
struct V_8 * V_9 ;
T_2 V_40 = 0 , V_65 = 0 ;
T_2 V_66 = 0 ;
T_4 V_67 = 0 ;
if ( ! F_39 ( V_10 , V_68 ) )
return - V_69 ;
if ( ! V_10 -> V_62 -> V_70 ) {
F_30 ( & V_10 -> V_39 , L_7 ,
V_71 ) ;
return - V_25 ;
}
if ( F_40 () > 1 && F_41 ( & V_10 -> V_39 ) < 0 ) {
F_30 ( & V_10 -> V_39 , L_8 ) ;
return - V_25 ;
}
V_9 = F_42 ( sizeof( * V_9 ) , V_41 ,
F_41 ( & V_10 -> V_39 ) ) ;
if ( ! V_9 )
return - V_34 ;
F_26 ( V_10 , struct V_58 ,
V_72 , & V_40 ) ;
if ( V_40 < 1 )
V_40 = 1 ;
F_26 ( V_10 , struct V_58 ,
V_65 , & V_65 ) ;
F_26 ( V_10 , struct V_58 ,
V_66 , & V_66 ) ;
F_26 ( V_10 , struct V_58 ,
V_67 , & V_67 ) ;
V_56 = F_43 ( V_9 ) ;
if ( V_56 ) {
F_30 ( & V_10 -> V_39 , L_9 ) ;
goto free;
}
V_9 -> V_73 = V_74 ;
V_9 = V_10 -> V_11 = V_9 ;
V_9 -> V_10 = V_10 ;
F_14 ( & V_9 -> V_75 ) ;
V_9 -> V_55 = 1 ;
V_9 -> V_40 = V_40 ;
V_9 -> V_65 = V_65 ;
V_9 -> V_66 = V_66 ;
V_9 -> V_67 = V_67 ;
F_31 ( & V_10 -> V_39 ,
L_10 ,
V_9 -> V_40 ,
V_9 -> V_65 ,
V_9 -> V_66 ,
V_9 -> V_67 ) ;
V_56 = F_22 ( V_9 ) ;
if ( V_56 ) {
F_30 ( & V_10 -> V_39 , L_11 ) ;
goto V_76;
}
V_56 = F_33 ( V_9 ) ;
if ( V_56 )
goto V_77;
F_44 ( V_10 ) ;
V_56 = F_25 ( V_9 ) ;
if ( V_56 )
goto V_78;
return 0 ;
V_78:
F_36 ( V_9 ) ;
V_77:
V_9 -> V_10 -> V_62 -> V_79 ( V_10 ) ;
F_37 ( V_9 ) ;
V_76:
F_45 ( V_9 ) ;
free:
F_3 ( V_9 ) ;
return V_56 ;
}
static void F_46 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
int V_35 ;
struct V_6 * V_7 ;
for ( V_35 = 0 ; V_35 < V_9 -> V_40 ; V_35 ++ ) {
V_7 = V_9 -> V_18 [ V_35 ] . V_7 ;
while ( ( V_2 = F_47 ( V_7 ) ) != NULL ) {
F_3 ( V_2 -> V_4 ) ;
F_3 ( V_2 -> V_5 ) ;
}
}
}
static void F_48 ( struct V_61 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
F_31 ( & V_10 -> V_39 , L_12 ) ;
if ( F_49 ( V_9 ) )
F_32 ( V_9 ) ;
V_10 -> V_62 -> V_79 ( V_10 ) ;
F_46 ( V_9 ) ;
F_36 ( V_9 ) ;
F_37 ( V_9 ) ;
F_45 ( V_9 ) ;
F_3 ( V_9 ) ;
}
static void F_50 ( struct V_61 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
F_25 ( V_9 ) ;
}
static int F_51 ( struct V_61 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
V_10 -> V_62 -> V_79 ( V_10 ) ;
F_46 ( V_9 ) ;
if ( F_49 ( V_9 ) )
F_32 ( V_9 ) ;
F_36 ( V_9 ) ;
F_37 ( V_9 ) ;
return 0 ;
}
static int F_52 ( struct V_61 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
int V_56 ;
V_56 = F_22 ( V_9 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_33 ( V_9 ) ;
if ( V_56 )
goto V_77;
F_44 ( V_10 ) ;
V_56 = F_29 ( V_9 ) ;
if ( V_56 ) {
F_30 ( & V_10 -> V_39 , L_4 ) ;
goto V_78;
}
return 0 ;
V_78:
F_36 ( V_9 ) ;
V_77:
V_9 -> V_10 -> V_62 -> V_79 ( V_10 ) ;
F_37 ( V_9 ) ;
return V_56 ;
}
