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
V_33 = V_30 -> V_10 -> V_46 -> V_47 ( V_30 -> V_10 , V_36 , V_32 , V_31 ,
V_37 , NULL ) ;
if ( V_33 )
goto V_48;
V_30 -> V_49 = V_32 [ V_36 - 1 ] ;
for ( V_35 = 0 ; V_35 < V_30 -> V_40 ; V_35 ++ ) {
F_13 ( & V_30 -> V_18 [ V_35 ] . V_19 ) ;
V_30 -> V_18 [ V_35 ] . V_7 = V_32 [ V_35 ] ;
V_30 -> V_18 [ V_35 ] . V_50 = F_14 ( V_39 , 1 ) ;
if ( ! V_30 -> V_18 [ V_35 ] . V_50 ) {
V_33 = - V_34 ;
goto V_51;
}
V_30 -> V_18 [ V_35 ] . V_50 -> V_52 =
V_53 ;
}
F_3 ( V_37 ) ;
F_3 ( V_31 ) ;
F_3 ( V_32 ) ;
return 0 ;
V_51:
V_48:
F_3 ( V_37 ) ;
V_44:
F_3 ( V_31 ) ;
V_43:
F_3 ( V_32 ) ;
V_42:
return V_33 ;
}
static int F_15 ( struct V_8 * V_30 )
{
V_30 -> V_18 = F_12 ( V_30 -> V_40 , sizeof( * V_30 -> V_18 ) ,
V_41 ) ;
if ( ! V_30 -> V_18 )
return - V_34 ;
return 0 ;
}
static void F_16 ( struct V_8 * V_30 , long V_54 )
{
int V_35 ;
if ( V_30 -> V_55 ) {
for ( V_35 = 0 ; V_35 < V_30 -> V_40 ; V_35 ++ )
F_17 ( V_30 -> V_18 [ V_35 ] . V_7 , - 1 ) ;
V_30 -> V_55 = false ;
}
}
static void F_18 ( struct V_8 * V_9 )
{
int V_35 = 0 ;
int V_56 ;
if ( V_9 -> V_57 == 1 || V_9 -> V_40 == 1 ) {
F_16 ( V_9 , - 1 ) ;
return;
}
F_19 (cpu) {
F_17 ( V_9 -> V_18 [ V_35 ] . V_7 , V_56 ) ;
if ( ++ V_35 >= V_9 -> V_40 )
break;
}
V_9 -> V_55 = true ;
}
static void F_20 ( struct V_8 * V_30 )
{
F_3 ( V_30 -> V_18 ) ;
}
static int F_21 ( struct V_8 * V_30 )
{
int V_33 ;
V_33 = F_15 ( V_30 ) ;
if ( V_33 )
goto V_58;
V_33 = F_11 ( V_30 ) ;
if ( V_33 )
goto V_59;
F_22 () ;
F_18 ( V_30 ) ;
F_23 () ;
return 0 ;
V_59:
F_20 ( V_30 ) ;
V_58:
return V_33 ;
}
static int F_24 ( struct V_8 * V_9 )
{
T_2 V_21 ;
int V_58 ;
F_25 ( V_9 -> V_10 ,
struct V_60 , V_21 , & V_21 ) ;
if ( V_21 & ( ~ V_61 ) ) {
F_26 ( & V_9 -> V_10 -> V_39 ,
L_3 , V_21 ) ;
F_27 ( V_9 -> V_10 ) ;
return - V_62 ;
}
if ( V_9 -> V_21 == V_21 )
return 0 ;
V_9 -> V_21 = V_21 ;
if ( V_9 -> V_21 & V_61 ) {
V_58 = F_28 ( V_9 ) ;
if ( V_58 ) {
F_29 ( & V_9 -> V_10 -> V_39 ,
L_4 ) ;
return - V_62 ;
}
F_30 ( & V_9 -> V_10 -> V_39 , L_5 ) ;
} else {
F_31 ( V_9 ) ;
F_30 ( & V_9 -> V_10 -> V_39 , L_6 ) ;
}
return 0 ;
}
static int F_32 ( struct V_8 * V_9 )
{
T_3 V_35 ;
int V_33 ;
for ( V_35 = 0 ; V_35 < V_9 -> V_40 ; V_35 ++ ) {
if ( V_9 -> V_18 [ V_35 ] . V_50 ) {
V_33 = F_33 ( V_9 -> V_18 [ V_35 ] . V_50 ) ;
if ( V_33 )
goto V_58;
}
}
return 0 ;
V_58:
while ( -- V_35 >= 0 )
if ( V_9 -> V_18 [ V_35 ] . V_50 )
F_34 ( V_9 -> V_18 [ V_35 ] . V_50 ) ;
return V_33 ;
}
static void F_35 ( struct V_8 * V_9 )
{
T_2 V_35 ;
for ( V_35 = 0 ; V_35 < V_9 -> V_40 ; V_35 ++ )
if ( V_9 -> V_18 [ V_35 ] . V_50 )
F_34 ( V_9 -> V_18 [ V_35 ] . V_50 ) ;
}
static void F_36 ( struct V_8 * V_9 )
{
struct V_63 * V_10 = V_9 -> V_10 ;
F_16 ( V_9 , - 1 ) ;
V_10 -> V_46 -> V_64 ( V_10 ) ;
F_20 ( V_9 ) ;
}
static int F_37 ( struct V_63 * V_10 )
{
int V_58 = - V_65 ;
struct V_8 * V_9 ;
T_2 V_40 = 0 , V_66 = 0 ;
T_2 V_67 = 0 ;
T_4 V_68 = 0 ;
if ( ! F_38 ( V_10 , V_69 ) )
return - V_70 ;
if ( ! V_10 -> V_46 -> V_71 ) {
F_29 ( & V_10 -> V_39 , L_7 ,
V_72 ) ;
return - V_25 ;
}
if ( F_39 () > 1 && F_40 ( & V_10 -> V_39 ) < 0 ) {
F_29 ( & V_10 -> V_39 , L_8 ) ;
return - V_25 ;
}
V_9 = F_41 ( sizeof( * V_9 ) , V_41 ,
F_40 ( & V_10 -> V_39 ) ) ;
if ( ! V_9 )
return - V_34 ;
F_25 ( V_10 , struct V_60 ,
V_73 , & V_40 ) ;
if ( V_40 < 1 )
V_40 = 1 ;
F_25 ( V_10 , struct V_60 ,
V_66 , & V_66 ) ;
F_25 ( V_10 , struct V_60 ,
V_67 , & V_67 ) ;
F_25 ( V_10 , struct V_60 ,
V_68 , & V_68 ) ;
V_58 = F_42 ( V_9 ) ;
if ( V_58 ) {
F_29 ( & V_10 -> V_39 , L_9 ) ;
goto free;
}
V_9 -> V_74 = V_75 ;
V_9 = V_10 -> V_11 = V_9 ;
V_9 -> V_10 = V_10 ;
F_13 ( & V_9 -> V_76 ) ;
V_9 -> V_57 = 1 ;
V_9 -> V_40 = V_40 ;
V_9 -> V_66 = V_66 ;
V_9 -> V_67 = V_67 ;
V_9 -> V_68 = V_68 ;
F_30 ( & V_10 -> V_39 ,
L_10 ,
V_9 -> V_40 ,
V_9 -> V_66 ,
V_9 -> V_67 ,
V_9 -> V_68 ) ;
V_58 = F_21 ( V_9 ) ;
if ( V_58 ) {
F_29 ( & V_10 -> V_39 , L_11 ) ;
goto V_77;
}
V_58 = F_32 ( V_9 ) ;
if ( V_58 )
goto V_78;
F_43 ( V_10 ) ;
V_58 = F_24 ( V_9 ) ;
if ( V_58 )
goto V_79;
return 0 ;
V_79:
F_35 ( V_9 ) ;
V_78:
V_9 -> V_10 -> V_46 -> V_80 ( V_10 ) ;
F_36 ( V_9 ) ;
V_77:
F_44 ( V_9 ) ;
free:
F_3 ( V_9 ) ;
return V_58 ;
}
static void F_45 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
int V_35 ;
struct V_6 * V_7 ;
for ( V_35 = 0 ; V_35 < V_9 -> V_40 ; V_35 ++ ) {
V_7 = V_9 -> V_18 [ V_35 ] . V_7 ;
while ( ( V_2 = F_46 ( V_7 ) ) != NULL ) {
F_3 ( V_2 -> V_4 ) ;
F_3 ( V_2 -> V_5 ) ;
}
}
}
static void F_47 ( struct V_63 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
F_30 ( & V_10 -> V_39 , L_12 ) ;
if ( F_48 ( V_9 ) )
F_31 ( V_9 ) ;
V_10 -> V_46 -> V_80 ( V_10 ) ;
F_45 ( V_9 ) ;
F_35 ( V_9 ) ;
F_36 ( V_9 ) ;
F_44 ( V_9 ) ;
F_3 ( V_9 ) ;
}
static void F_49 ( struct V_63 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
F_24 ( V_9 ) ;
}
static int F_50 ( struct V_63 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
V_10 -> V_46 -> V_80 ( V_10 ) ;
F_45 ( V_9 ) ;
if ( F_48 ( V_9 ) )
F_31 ( V_9 ) ;
F_35 ( V_9 ) ;
F_36 ( V_9 ) ;
return 0 ;
}
static int F_51 ( struct V_63 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
int V_58 ;
V_58 = F_21 ( V_9 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_32 ( V_9 ) ;
if ( V_58 )
goto V_78;
F_43 ( V_10 ) ;
V_58 = F_28 ( V_9 ) ;
if ( V_58 ) {
F_29 ( & V_10 -> V_39 , L_4 ) ;
goto V_79;
}
return 0 ;
V_79:
F_35 ( V_9 ) ;
V_78:
V_9 -> V_10 -> V_46 -> V_80 ( V_10 ) ;
F_36 ( V_9 ) ;
return V_58 ;
}
