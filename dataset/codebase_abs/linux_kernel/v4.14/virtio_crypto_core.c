void
F_1 ( struct V_1 * V_2 )
{
if ( V_2 ) {
F_2 ( V_2 -> V_3 ) ;
F_3 ( V_2 -> V_4 ) ;
}
}
static void F_4 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_1 * V_2 ;
unsigned long V_11 ;
unsigned int V_12 ;
unsigned int V_13 = V_6 -> V_14 ;
F_5 ( & V_8 -> V_15 [ V_13 ] . V_16 , V_11 ) ;
do {
F_6 ( V_6 ) ;
while ( ( V_2 = F_7 ( V_6 , & V_12 ) ) != NULL ) {
F_8 (
& V_8 -> V_15 [ V_13 ] . V_16 , V_11 ) ;
if ( V_2 -> V_17 )
V_2 -> V_17 ( V_2 , V_12 ) ;
F_5 (
& V_8 -> V_15 [ V_13 ] . V_16 , V_11 ) ;
}
} while ( ! F_9 ( V_6 ) );
F_8 ( & V_8 -> V_15 [ V_13 ] . V_16 , V_11 ) ;
}
static int F_10 ( struct V_7 * V_18 )
{
T_1 * * V_19 ;
struct V_5 * * V_20 ;
int V_21 = - V_22 ;
int V_23 , V_24 ;
const char * * V_25 ;
struct V_26 * V_27 = & V_18 -> V_9 -> V_27 ;
V_24 = V_18 -> V_28 + 1 ;
V_20 = F_11 ( V_24 , sizeof( * V_20 ) , V_29 ) ;
if ( ! V_20 )
goto V_30;
V_19 = F_11 ( V_24 , sizeof( * V_19 ) , V_29 ) ;
if ( ! V_19 )
goto V_31;
V_25 = F_11 ( V_24 , sizeof( * V_25 ) , V_29 ) ;
if ( ! V_25 )
goto V_32;
V_19 [ V_24 - 1 ] = NULL ;
V_25 [ V_24 - 1 ] = L_1 ;
for ( V_23 = 0 ; V_23 < V_18 -> V_28 ; V_23 ++ ) {
V_19 [ V_23 ] = F_4 ;
snprintf ( V_18 -> V_15 [ V_23 ] . V_33 , sizeof( V_18 -> V_15 [ V_23 ] . V_33 ) ,
L_2 , V_23 ) ;
V_25 [ V_23 ] = V_18 -> V_15 [ V_23 ] . V_33 ;
}
V_21 = F_12 ( V_18 -> V_9 , V_24 , V_20 , V_19 , V_25 , NULL ) ;
if ( V_21 )
goto V_34;
V_18 -> V_35 = V_20 [ V_24 - 1 ] ;
for ( V_23 = 0 ; V_23 < V_18 -> V_28 ; V_23 ++ ) {
F_13 ( & V_18 -> V_15 [ V_23 ] . V_16 ) ;
V_18 -> V_15 [ V_23 ] . V_6 = V_20 [ V_23 ] ;
V_18 -> V_15 [ V_23 ] . V_36 = F_14 ( V_27 , 1 ) ;
if ( ! V_18 -> V_15 [ V_23 ] . V_36 ) {
V_21 = - V_22 ;
goto V_37;
}
V_18 -> V_15 [ V_23 ] . V_36 -> V_38 =
V_39 ;
}
F_3 ( V_25 ) ;
F_3 ( V_19 ) ;
F_3 ( V_20 ) ;
return 0 ;
V_37:
V_34:
F_3 ( V_25 ) ;
V_32:
F_3 ( V_19 ) ;
V_31:
F_3 ( V_20 ) ;
V_30:
return V_21 ;
}
static int F_15 ( struct V_7 * V_18 )
{
V_18 -> V_15 = F_11 ( V_18 -> V_28 , sizeof( * V_18 -> V_15 ) ,
V_29 ) ;
if ( ! V_18 -> V_15 )
return - V_22 ;
return 0 ;
}
static void F_16 ( struct V_7 * V_18 , long V_40 )
{
int V_23 ;
if ( V_18 -> V_41 ) {
for ( V_23 = 0 ; V_23 < V_18 -> V_28 ; V_23 ++ )
F_17 ( V_18 -> V_15 [ V_23 ] . V_6 , - 1 ) ;
V_18 -> V_41 = false ;
}
}
static void F_18 ( struct V_7 * V_8 )
{
int V_23 = 0 ;
int V_42 ;
if ( V_8 -> V_43 == 1 || V_8 -> V_28 == 1 ) {
F_16 ( V_8 , - 1 ) ;
return;
}
F_19 (cpu) {
F_17 ( V_8 -> V_15 [ V_23 ] . V_6 , V_42 ) ;
if ( ++ V_23 >= V_8 -> V_28 )
break;
}
V_8 -> V_41 = true ;
}
static void F_20 ( struct V_7 * V_18 )
{
F_3 ( V_18 -> V_15 ) ;
}
static int F_21 ( struct V_7 * V_18 )
{
int V_21 ;
V_21 = F_15 ( V_18 ) ;
if ( V_21 )
goto V_44;
V_21 = F_10 ( V_18 ) ;
if ( V_21 )
goto V_45;
F_22 () ;
F_18 ( V_18 ) ;
F_23 () ;
return 0 ;
V_45:
F_20 ( V_18 ) ;
V_44:
return V_21 ;
}
static int F_24 ( struct V_7 * V_8 )
{
T_2 V_46 ;
int V_44 ;
F_25 ( V_8 -> V_9 ,
struct V_47 , V_46 , & V_46 ) ;
if ( V_46 & ( ~ V_48 ) ) {
F_26 ( & V_8 -> V_9 -> V_27 ,
L_3 , V_46 ) ;
F_27 ( V_8 -> V_9 ) ;
return - V_49 ;
}
if ( V_8 -> V_46 == V_46 )
return 0 ;
V_8 -> V_46 = V_46 ;
if ( V_8 -> V_46 & V_48 ) {
V_44 = F_28 ( V_8 ) ;
if ( V_44 ) {
F_29 ( & V_8 -> V_9 -> V_27 ,
L_4 ) ;
return - V_49 ;
}
F_30 ( & V_8 -> V_9 -> V_27 , L_5 ) ;
} else {
F_31 ( V_8 ) ;
F_30 ( & V_8 -> V_9 -> V_27 , L_6 ) ;
}
return 0 ;
}
static int F_32 ( struct V_7 * V_8 )
{
T_3 V_23 ;
int V_21 ;
for ( V_23 = 0 ; V_23 < V_8 -> V_28 ; V_23 ++ ) {
if ( V_8 -> V_15 [ V_23 ] . V_36 ) {
V_21 = F_33 ( V_8 -> V_15 [ V_23 ] . V_36 ) ;
if ( V_21 )
goto V_44;
}
}
return 0 ;
V_44:
while ( -- V_23 >= 0 )
if ( V_8 -> V_15 [ V_23 ] . V_36 )
F_34 ( V_8 -> V_15 [ V_23 ] . V_36 ) ;
return V_21 ;
}
static void F_35 ( struct V_7 * V_8 )
{
T_2 V_23 ;
for ( V_23 = 0 ; V_23 < V_8 -> V_28 ; V_23 ++ )
if ( V_8 -> V_15 [ V_23 ] . V_36 )
F_34 ( V_8 -> V_15 [ V_23 ] . V_36 ) ;
}
static void F_36 ( struct V_7 * V_8 )
{
struct V_50 * V_9 = V_8 -> V_9 ;
F_16 ( V_8 , - 1 ) ;
V_9 -> V_51 -> V_52 ( V_9 ) ;
F_20 ( V_8 ) ;
}
static int F_37 ( struct V_50 * V_9 )
{
int V_44 = - V_53 ;
struct V_7 * V_8 ;
T_2 V_28 = 0 , V_54 = 0 ;
T_2 V_55 = 0 ;
T_4 V_56 = 0 ;
if ( ! F_38 ( V_9 , V_57 ) )
return - V_58 ;
if ( ! V_9 -> V_51 -> V_59 ) {
F_29 ( & V_9 -> V_27 , L_7 ,
V_60 ) ;
return - V_61 ;
}
if ( F_39 () > 1 && F_40 ( & V_9 -> V_27 ) < 0 ) {
F_29 ( & V_9 -> V_27 , L_8 ) ;
return - V_61 ;
}
V_8 = F_41 ( sizeof( * V_8 ) , V_29 ,
F_40 ( & V_9 -> V_27 ) ) ;
if ( ! V_8 )
return - V_22 ;
F_25 ( V_9 , struct V_47 ,
V_62 , & V_28 ) ;
if ( V_28 < 1 )
V_28 = 1 ;
F_25 ( V_9 , struct V_47 ,
V_54 , & V_54 ) ;
F_25 ( V_9 , struct V_47 ,
V_55 , & V_55 ) ;
F_25 ( V_9 , struct V_47 ,
V_56 , & V_56 ) ;
V_44 = F_42 ( V_8 ) ;
if ( V_44 ) {
F_29 ( & V_9 -> V_27 , L_9 ) ;
goto free;
}
V_8 -> V_63 = V_64 ;
V_8 = V_9 -> V_10 = V_8 ;
V_8 -> V_9 = V_9 ;
F_13 ( & V_8 -> V_65 ) ;
V_8 -> V_43 = 1 ;
V_8 -> V_28 = V_28 ;
V_8 -> V_54 = V_54 ;
V_8 -> V_55 = V_55 ;
V_8 -> V_56 = V_56 ;
F_30 ( & V_9 -> V_27 ,
L_10 ,
V_8 -> V_28 ,
V_8 -> V_54 ,
V_8 -> V_55 ,
V_8 -> V_56 ) ;
V_44 = F_21 ( V_8 ) ;
if ( V_44 ) {
F_29 ( & V_9 -> V_27 , L_11 ) ;
goto V_66;
}
V_44 = F_32 ( V_8 ) ;
if ( V_44 )
goto V_67;
F_43 ( V_9 ) ;
V_44 = F_24 ( V_8 ) ;
if ( V_44 )
goto V_68;
return 0 ;
V_68:
F_35 ( V_8 ) ;
V_67:
V_8 -> V_9 -> V_51 -> V_69 ( V_9 ) ;
F_36 ( V_8 ) ;
V_66:
F_44 ( V_8 ) ;
free:
F_3 ( V_8 ) ;
return V_44 ;
}
static void F_45 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_23 ;
struct V_5 * V_6 ;
for ( V_23 = 0 ; V_23 < V_8 -> V_28 ; V_23 ++ ) {
V_6 = V_8 -> V_15 [ V_23 ] . V_6 ;
while ( ( V_2 = F_46 ( V_6 ) ) != NULL ) {
F_3 ( V_2 -> V_3 ) ;
F_3 ( V_2 -> V_4 ) ;
}
}
}
static void F_47 ( struct V_50 * V_9 )
{
struct V_7 * V_8 = V_9 -> V_10 ;
F_30 ( & V_9 -> V_27 , L_12 ) ;
if ( F_48 ( V_8 ) )
F_31 ( V_8 ) ;
V_9 -> V_51 -> V_69 ( V_9 ) ;
F_45 ( V_8 ) ;
F_35 ( V_8 ) ;
F_36 ( V_8 ) ;
F_44 ( V_8 ) ;
F_3 ( V_8 ) ;
}
static void F_49 ( struct V_50 * V_9 )
{
struct V_7 * V_8 = V_9 -> V_10 ;
F_24 ( V_8 ) ;
}
static int F_50 ( struct V_50 * V_9 )
{
struct V_7 * V_8 = V_9 -> V_10 ;
V_9 -> V_51 -> V_69 ( V_9 ) ;
F_45 ( V_8 ) ;
if ( F_48 ( V_8 ) )
F_31 ( V_8 ) ;
F_35 ( V_8 ) ;
F_36 ( V_8 ) ;
return 0 ;
}
static int F_51 ( struct V_50 * V_9 )
{
struct V_7 * V_8 = V_9 -> V_10 ;
int V_44 ;
V_44 = F_21 ( V_8 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_32 ( V_8 ) ;
if ( V_44 )
goto V_67;
F_43 ( V_9 ) ;
V_44 = F_28 ( V_8 ) ;
if ( V_44 ) {
F_29 ( & V_9 -> V_27 , L_4 ) ;
goto V_68;
}
return 0 ;
V_68:
F_35 ( V_8 ) ;
V_67:
V_8 -> V_9 -> V_51 -> V_69 ( V_9 ) ;
F_36 ( V_8 ) ;
return V_44 ;
}
