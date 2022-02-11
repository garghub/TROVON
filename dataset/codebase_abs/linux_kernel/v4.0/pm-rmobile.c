static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 ;
if ( V_4 -> V_6 == ~ 0 )
return - V_7 ;
V_5 = 1 << V_4 -> V_6 ;
if ( V_4 -> V_8 ) {
int V_9 = V_4 -> V_8 () ;
if ( V_9 )
return V_9 ;
}
if ( F_3 ( V_4 -> V_10 + V_11 ) & V_5 ) {
unsigned int V_12 ;
F_4 ( V_5 , V_4 -> V_10 + V_13 ) ;
for ( V_12 = V_14 ; V_12 ; V_12 -- ) {
if ( ! ( F_3 ( V_4 -> V_10 + V_13 ) & V_5 ) )
break;
F_5 () ;
}
}
if ( ! V_4 -> V_15 )
F_6 ( L_1 ,
V_2 -> V_16 , V_5 ,
F_3 ( V_4 -> V_10 + V_11 ) ) ;
return 0 ;
}
static int F_7 ( struct V_3 * V_4 ,
bool V_17 )
{
unsigned int V_5 ;
unsigned int V_12 ;
int V_9 = 0 ;
if ( V_4 -> V_6 == ~ 0 )
return 0 ;
V_5 = 1 << V_4 -> V_6 ;
if ( F_3 ( V_4 -> V_10 + V_11 ) & V_5 )
goto V_18;
F_4 ( V_5 , V_4 -> V_10 + V_19 ) ;
for ( V_12 = 2 * V_14 ; V_12 ; V_12 -- ) {
if ( ! ( F_3 ( V_4 -> V_10 + V_19 ) & V_5 ) )
break;
if ( V_12 > V_14 )
F_8 ( V_20 ) ;
else
F_5 () ;
}
if ( ! V_12 )
V_9 = - V_21 ;
if ( ! V_4 -> V_15 )
F_6 ( L_2 ,
V_4 -> V_2 . V_16 , V_5 ,
F_3 ( V_4 -> V_10 + V_11 ) ) ;
V_18:
if ( V_9 == 0 && V_4 -> V_22 && V_17 )
V_4 -> V_22 () ;
return V_9 ;
}
static int F_9 ( struct V_1 * V_2 )
{
return F_7 ( F_2 ( V_2 ) , true ) ;
}
static bool F_10 ( struct V_23 * V_24 )
{
return true ;
}
static int F_11 ( struct V_1 * V_25 ,
struct V_23 * V_24 )
{
int error ;
error = F_12 ( V_24 ) ;
if ( error ) {
F_13 ( V_24 , L_3 , error ) ;
return error ;
}
error = F_14 ( V_24 , NULL ) ;
if ( error ) {
F_13 ( V_24 , L_4 , error ) ;
goto V_26;
}
return 0 ;
V_26:
F_15 ( V_24 ) ;
return error ;
}
static void F_16 ( struct V_1 * V_25 ,
struct V_23 * V_24 )
{
F_15 ( V_24 ) ;
}
static void F_17 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
struct V_27 * V_28 = V_4 -> V_28 ;
V_2 -> V_29 = V_30 ;
F_18 ( V_2 , V_28 ? : & V_31 , false ) ;
V_2 -> V_32 . V_33 = F_10 ;
V_2 -> V_34 = F_1 ;
V_2 -> V_35 = F_9 ;
V_2 -> V_36 = F_11 ;
V_2 -> V_37 = F_16 ;
F_7 ( V_4 , false ) ;
}
void F_19 ( struct V_3 V_38 [] , int V_39 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ )
F_17 ( & V_38 [ V_40 ] ) ;
}
void F_20 ( const char * V_41 ,
struct V_42 * V_43 ,
struct V_44 * V_45 )
{
struct V_23 * V_24 = & V_43 -> V_24 ;
F_21 ( V_41 , V_24 , V_45 ) ;
}
void F_22 ( struct V_46 V_47 [] ,
int V_48 )
{
struct V_44 V_49 = {
. V_50 = V_51 ,
. V_52 = V_51 ,
. V_53 = V_51 ,
. V_54 = V_51 ,
} ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_48 ; V_40 ++ )
F_20 ( V_47 [ V_40 ] . V_41 ,
V_47 [ V_40 ] . V_43 , & V_49 ) ;
}
static int F_23 ( void )
{
return - V_7 ;
}
static int F_24 ( void )
{
return V_55 ? 0 : - V_7 ;
}
static void T_1 F_25 ( struct V_56 * V_57 , enum V_58 type )
{
unsigned int V_59 ;
struct V_56 * V_60 ;
V_60 = F_26 ( V_57 , L_5 , 0 ) ;
if ( ! V_60 )
return;
for ( V_59 = 0 ; V_59 < V_61 ; V_59 ++ )
if ( V_60 == V_62 [ V_59 ] . V_60 && type == V_62 [ V_59 ] . type ) {
F_27 ( V_60 ) ;
return;
}
if ( V_61 == F_28 ( V_62 ) ) {
F_29 ( L_6 ) ;
F_27 ( V_60 ) ;
return;
}
F_6 ( L_7 , V_60 -> V_16 , type ,
V_57 -> V_63 ) ;
V_62 [ V_61 ] . V_60 = V_60 ;
V_62 [ V_61 ] . type = type ;
V_61 ++ ;
}
static void T_1 F_30 ( void )
{
struct V_56 * V_57 ;
const struct V_64 * V_65 ;
F_31 (np, L_8 )
F_25 ( V_57 , V_66 ) ;
if ( V_67 )
F_25 ( V_67 , V_68 ) ;
F_32 (np, special_ids, &id)
F_25 ( V_57 , (enum V_58 ) V_65 -> V_47 ) ;
}
static void T_1 F_33 ( void )
{
unsigned int V_59 ;
for ( V_59 = 0 ; V_59 < V_61 ; V_59 ++ )
F_27 ( V_62 [ V_59 ] . V_60 ) ;
}
static enum V_58 T_1 F_34 ( const struct V_56 * V_60 )
{
unsigned int V_59 ;
for ( V_59 = 0 ; V_59 < V_61 ; V_59 ++ )
if ( V_60 == V_62 [ V_59 ] . V_60 )
return V_62 [ V_59 ] . type ;
return V_69 ;
}
static void T_1 F_35 ( struct V_56 * V_57 ,
struct V_3 * V_60 )
{
const char * V_16 = V_60 -> V_2 . V_16 ;
switch ( F_34 ( V_57 ) ) {
case V_66 :
F_6 ( L_9 , V_16 ) ;
V_60 -> V_28 = & V_70 ;
V_60 -> V_8 = F_23 ;
break;
case V_68 :
F_6 ( L_10 , V_16 ) ;
V_60 -> V_28 = & V_70 ;
V_60 -> V_8 = F_24 ;
break;
case V_71 :
F_6 ( L_11 , V_16 ) ;
V_60 -> V_28 = & V_70 ;
V_60 -> V_8 = F_23 ;
break;
case V_72 :
F_6 ( L_12 , V_16 ) ;
V_60 -> V_28 = & V_70 ;
V_60 -> V_8 = F_23 ;
break;
case V_69 :
break;
}
F_17 ( V_60 ) ;
}
static int T_1 F_36 ( void T_2 * V_10 ,
struct V_56 * V_73 ,
struct V_1 * V_74 )
{
struct V_56 * V_57 ;
F_37 (parent, np) {
struct V_3 * V_60 ;
T_3 V_75 = ~ 0 ;
if ( F_38 ( V_57 , L_13 , & V_75 ) ) {
}
V_60 = F_39 ( sizeof( * V_60 ) , V_76 ) ;
if ( ! V_60 )
return - V_77 ;
V_60 -> V_2 . V_16 = V_57 -> V_16 ;
V_60 -> V_10 = V_10 ;
V_60 -> V_6 = V_75 ;
F_35 ( V_57 , V_60 ) ;
if ( V_74 )
F_40 ( V_74 , & V_60 -> V_2 ) ;
F_41 ( V_57 , & V_60 -> V_2 ) ;
F_36 ( V_10 , V_57 , & V_60 -> V_2 ) ;
}
return 0 ;
}
static int T_1 F_42 ( void )
{
struct V_56 * V_57 , * V_78 ;
bool V_79 = false ;
void T_2 * V_10 ;
int V_9 = 0 ;
F_43 (np, NULL, L_14 ) {
V_10 = F_44 ( V_57 , 0 ) ;
if ( ! V_10 ) {
F_29 ( L_15 , V_57 -> V_63 ) ;
continue;
}
V_78 = F_45 ( V_57 , L_16 ) ;
if ( ! V_78 ) {
F_29 ( L_17 , V_57 -> V_63 ) ;
continue;
}
if ( ! V_79 ) {
F_30 () ;
V_79 = true ;
}
V_9 = F_36 ( V_10 , V_78 , NULL ) ;
F_27 ( V_78 ) ;
if ( V_9 ) {
F_27 ( V_57 ) ;
break;
}
}
F_33 () ;
return V_9 ;
}
