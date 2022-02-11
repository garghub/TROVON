static void
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
F_1 ( V_2 ) ;
F_8 (
& V_9 -> V_18 [ V_16 ] . V_19 , V_12 ) ;
V_15 -> V_30 . V_31 ( & V_15 -> V_30 , error ) ;
F_5 (
& V_9 -> V_18 [ V_16 ] . V_19 , V_12 ) ;
}
}
} while ( ! F_9 ( V_7 ) );
F_8 ( & V_9 -> V_18 [ V_16 ] . V_19 , V_12 ) ;
}
static int F_10 ( struct V_8 * V_32 )
{
T_1 * * V_33 ;
struct V_6 * * V_34 ;
int V_35 = - V_36 ;
int V_37 , V_38 ;
const char * * V_39 ;
V_38 = V_32 -> V_40 + 1 ;
V_34 = F_11 ( V_38 , sizeof( * V_34 ) , V_41 ) ;
if ( ! V_34 )
goto V_42;
V_33 = F_11 ( V_38 , sizeof( * V_33 ) , V_41 ) ;
if ( ! V_33 )
goto V_43;
V_39 = F_11 ( V_38 , sizeof( * V_39 ) , V_41 ) ;
if ( ! V_39 )
goto V_44;
V_33 [ V_38 - 1 ] = NULL ;
V_39 [ V_38 - 1 ] = L_1 ;
for ( V_37 = 0 ; V_37 < V_32 -> V_40 ; V_37 ++ ) {
V_33 [ V_37 ] = F_4 ;
snprintf ( V_32 -> V_18 [ V_37 ] . V_45 , sizeof( V_32 -> V_18 [ V_37 ] . V_45 ) ,
L_2 , V_37 ) ;
V_39 [ V_37 ] = V_32 -> V_18 [ V_37 ] . V_45 ;
}
V_35 = V_32 -> V_10 -> V_46 -> V_47 ( V_32 -> V_10 , V_38 , V_34 , V_33 ,
V_39 ) ;
if ( V_35 )
goto V_48;
V_32 -> V_49 = V_34 [ V_38 - 1 ] ;
for ( V_37 = 0 ; V_37 < V_32 -> V_40 ; V_37 ++ ) {
F_12 ( & V_32 -> V_18 [ V_37 ] . V_19 ) ;
V_32 -> V_18 [ V_37 ] . V_7 = V_34 [ V_37 ] ;
}
F_3 ( V_39 ) ;
F_3 ( V_33 ) ;
F_3 ( V_34 ) ;
return 0 ;
V_48:
F_3 ( V_39 ) ;
V_44:
F_3 ( V_33 ) ;
V_43:
F_3 ( V_34 ) ;
V_42:
return V_35 ;
}
static int F_13 ( struct V_8 * V_32 )
{
V_32 -> V_18 = F_11 ( V_32 -> V_40 , sizeof( * V_32 -> V_18 ) ,
V_41 ) ;
if ( ! V_32 -> V_18 )
return - V_36 ;
return 0 ;
}
static void F_14 ( struct V_8 * V_32 , long V_50 )
{
int V_37 ;
if ( V_32 -> V_51 ) {
for ( V_37 = 0 ; V_37 < V_32 -> V_40 ; V_37 ++ )
F_15 ( V_32 -> V_18 [ V_37 ] . V_7 , - 1 ) ;
V_32 -> V_51 = false ;
}
}
static void F_16 ( struct V_8 * V_9 )
{
int V_37 = 0 ;
int V_52 ;
if ( V_9 -> V_53 == 1 || V_9 -> V_40 == 1 ) {
F_14 ( V_9 , - 1 ) ;
return;
}
F_17 (cpu) {
F_15 ( V_9 -> V_18 [ V_37 ] . V_7 , V_52 ) ;
if ( ++ V_37 >= V_9 -> V_40 )
break;
}
V_9 -> V_51 = true ;
}
static void F_18 ( struct V_8 * V_32 )
{
F_3 ( V_32 -> V_18 ) ;
}
static int F_19 ( struct V_8 * V_32 )
{
int V_35 ;
V_35 = F_13 ( V_32 ) ;
if ( V_35 )
goto V_54;
V_35 = F_10 ( V_32 ) ;
if ( V_35 )
goto V_55;
F_20 () ;
F_16 ( V_32 ) ;
F_21 () ;
return 0 ;
V_55:
F_18 ( V_32 ) ;
V_54:
return V_35 ;
}
static int F_22 ( struct V_8 * V_9 )
{
T_2 V_21 ;
int V_54 ;
F_23 ( V_9 -> V_10 ,
struct V_56 , V_21 , & V_21 ) ;
if ( V_21 & ( ~ V_57 ) ) {
F_24 ( & V_9 -> V_10 -> V_58 ,
L_3 , V_21 ) ;
F_25 ( V_9 -> V_10 ) ;
return - V_59 ;
}
if ( V_9 -> V_21 == V_21 )
return 0 ;
V_9 -> V_21 = V_21 ;
if ( V_9 -> V_21 & V_57 ) {
V_54 = F_26 ( V_9 ) ;
if ( V_54 ) {
F_27 ( & V_9 -> V_10 -> V_58 ,
L_4 ) ;
return - V_59 ;
}
F_28 ( & V_9 -> V_10 -> V_58 , L_5 ) ;
} else {
F_29 ( V_9 ) ;
F_28 ( & V_9 -> V_10 -> V_58 , L_6 ) ;
}
return 0 ;
}
static void F_30 ( struct V_8 * V_9 )
{
struct V_60 * V_10 = V_9 -> V_10 ;
F_14 ( V_9 , - 1 ) ;
V_10 -> V_46 -> V_61 ( V_10 ) ;
F_18 ( V_9 ) ;
}
static int F_31 ( struct V_60 * V_10 )
{
int V_54 = - V_62 ;
struct V_8 * V_9 ;
T_2 V_40 = 0 , V_63 = 0 ;
T_2 V_64 = 0 ;
T_3 V_65 = 0 ;
if ( ! F_32 ( V_10 , V_66 ) )
return - V_67 ;
if ( ! V_10 -> V_46 -> V_68 ) {
F_27 ( & V_10 -> V_58 , L_7 ,
V_69 ) ;
return - V_25 ;
}
if ( F_33 () > 1 && F_34 ( & V_10 -> V_58 ) < 0 ) {
F_27 ( & V_10 -> V_58 , L_8 ) ;
return - V_25 ;
}
V_9 = F_35 ( sizeof( * V_9 ) , V_41 ,
F_34 ( & V_10 -> V_58 ) ) ;
if ( ! V_9 )
return - V_36 ;
F_23 ( V_10 , struct V_56 ,
V_70 , & V_40 ) ;
if ( V_40 < 1 )
V_40 = 1 ;
F_23 ( V_10 , struct V_56 ,
V_63 , & V_63 ) ;
F_23 ( V_10 , struct V_56 ,
V_64 , & V_64 ) ;
F_23 ( V_10 , struct V_56 ,
V_65 , & V_65 ) ;
V_54 = F_36 ( V_9 ) ;
if ( V_54 ) {
F_27 ( & V_10 -> V_58 , L_9 ) ;
goto free;
}
V_9 -> V_71 = V_72 ;
V_9 = V_10 -> V_11 = V_9 ;
V_9 -> V_10 = V_10 ;
F_12 ( & V_9 -> V_73 ) ;
V_9 -> V_53 = 1 ;
V_9 -> V_40 = V_40 ;
V_9 -> V_63 = V_63 ;
V_9 -> V_64 = V_64 ;
V_9 -> V_65 = V_65 ;
F_28 ( & V_10 -> V_58 ,
L_10 ,
V_9 -> V_40 ,
V_9 -> V_63 ,
V_9 -> V_64 ,
V_9 -> V_65 ) ;
V_54 = F_19 ( V_9 ) ;
if ( V_54 ) {
F_27 ( & V_10 -> V_58 , L_11 ) ;
goto V_74;
}
F_37 ( V_10 ) ;
V_54 = F_22 ( V_9 ) ;
if ( V_54 )
goto V_75;
return 0 ;
V_75:
V_9 -> V_10 -> V_46 -> V_76 ( V_10 ) ;
F_30 ( V_9 ) ;
V_74:
F_38 ( V_9 ) ;
free:
F_3 ( V_9 ) ;
return V_54 ;
}
static void F_39 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
int V_37 ;
struct V_6 * V_7 ;
for ( V_37 = 0 ; V_37 < V_9 -> V_40 ; V_37 ++ ) {
V_7 = V_9 -> V_18 [ V_37 ] . V_7 ;
while ( ( V_2 = F_40 ( V_7 ) ) != NULL ) {
F_3 ( V_2 -> V_4 ) ;
F_3 ( V_2 -> V_5 ) ;
}
}
}
static void F_41 ( struct V_60 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
F_28 ( & V_10 -> V_58 , L_12 ) ;
if ( F_42 ( V_9 ) )
F_29 ( V_9 ) ;
V_10 -> V_46 -> V_76 ( V_10 ) ;
F_39 ( V_9 ) ;
F_30 ( V_9 ) ;
F_38 ( V_9 ) ;
F_3 ( V_9 ) ;
}
static void F_43 ( struct V_60 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
F_22 ( V_9 ) ;
}
static int F_44 ( struct V_60 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
V_10 -> V_46 -> V_76 ( V_10 ) ;
F_39 ( V_9 ) ;
if ( F_42 ( V_9 ) )
F_29 ( V_9 ) ;
F_30 ( V_9 ) ;
return 0 ;
}
static int F_45 ( struct V_60 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
int V_54 ;
V_54 = F_19 ( V_9 ) ;
if ( V_54 )
return V_54 ;
F_37 ( V_10 ) ;
V_54 = F_26 ( V_9 ) ;
if ( V_54 ) {
F_27 ( & V_10 -> V_58 , L_4 ) ;
return - V_62 ;
}
return 0 ;
}
