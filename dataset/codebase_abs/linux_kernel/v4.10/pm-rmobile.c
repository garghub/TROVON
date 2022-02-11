static inline
struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_6 ;
if ( V_5 -> V_7 == ~ 0 )
return - V_8 ;
V_6 = F_4 ( V_5 -> V_7 ) ;
if ( V_5 -> V_9 ) {
int V_10 = V_5 -> V_9 () ;
if ( V_10 )
return V_10 ;
}
if ( F_5 ( V_5 -> V_11 + V_12 ) & V_6 ) {
unsigned int V_13 ;
F_6 ( V_6 , V_5 -> V_11 + V_14 ) ;
for ( V_13 = V_15 ; V_13 ; V_13 -- ) {
if ( ! ( F_5 ( V_5 -> V_11 + V_14 ) & V_6 ) )
break;
F_7 () ;
}
}
if ( ! V_5 -> V_16 )
F_8 ( L_1 ,
V_4 -> V_17 , V_6 ,
F_5 ( V_5 -> V_11 + V_12 ) ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_5 ,
bool V_18 )
{
unsigned int V_6 ;
unsigned int V_13 ;
int V_10 = 0 ;
if ( V_5 -> V_7 == ~ 0 )
return 0 ;
V_6 = F_4 ( V_5 -> V_7 ) ;
if ( F_5 ( V_5 -> V_11 + V_12 ) & V_6 )
goto V_19;
F_6 ( V_6 , V_5 -> V_11 + V_20 ) ;
for ( V_13 = 2 * V_15 ; V_13 ; V_13 -- ) {
if ( ! ( F_5 ( V_5 -> V_11 + V_20 ) & V_6 ) )
break;
if ( V_13 > V_15 )
F_10 ( V_21 ) ;
else
F_7 () ;
}
if ( ! V_13 )
V_10 = - V_22 ;
if ( ! V_5 -> V_16 )
F_8 ( L_2 ,
V_5 -> V_4 . V_17 , V_6 ,
F_5 ( V_5 -> V_11 + V_12 ) ) ;
V_19:
if ( V_10 == 0 && V_5 -> V_23 && V_18 )
V_5 -> V_23 () ;
return V_10 ;
}
static int F_11 ( struct V_2 * V_4 )
{
return F_9 ( F_1 ( V_4 ) , true ) ;
}
static bool F_12 ( struct V_24 * V_25 )
{
return true ;
}
static void F_13 ( struct V_1 * V_5 )
{
struct V_2 * V_4 = & V_5 -> V_4 ;
struct V_26 * V_27 = V_5 -> V_27 ;
V_4 -> V_28 = V_29 ;
V_4 -> V_30 . V_31 = F_12 ;
V_4 -> V_32 = F_3 ;
V_4 -> V_33 = F_11 ;
V_4 -> V_34 = V_35 ;
V_4 -> V_36 = V_37 ;
F_9 ( V_5 , false ) ;
F_14 ( V_4 , V_27 ? : & V_38 , false ) ;
}
static int F_15 ( void )
{
return - V_8 ;
}
static int F_16 ( void )
{
return V_39 ? 0 : - V_8 ;
}
static void T_1 F_17 ( struct V_40 * V_41 , enum V_42 type )
{
unsigned int V_43 ;
struct V_40 * V_44 ;
V_44 = F_18 ( V_41 , L_3 , 0 ) ;
if ( ! V_44 )
return;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ )
if ( V_44 == V_46 [ V_43 ] . V_44 && type == V_46 [ V_43 ] . type ) {
F_19 ( V_44 ) ;
return;
}
if ( V_45 == F_20 ( V_46 ) ) {
F_21 ( L_4 ) ;
F_19 ( V_44 ) ;
return;
}
F_8 ( L_5 , V_44 -> V_17 , type ,
V_41 -> V_47 ) ;
V_46 [ V_45 ] . V_44 = V_44 ;
V_46 [ V_45 ] . type = type ;
V_45 ++ ;
}
static void T_1 F_22 ( void )
{
struct V_40 * V_41 ;
const struct V_48 * V_49 ;
F_23 (np, L_6 )
F_17 ( V_41 , V_50 ) ;
if ( V_51 )
F_17 ( V_51 , V_52 ) ;
F_24 (np, special_ids, &id)
F_17 ( V_41 , (enum V_42 ) V_49 -> V_53 ) ;
}
static void T_1 F_25 ( void )
{
unsigned int V_43 ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ )
F_19 ( V_46 [ V_43 ] . V_44 ) ;
}
static enum V_42 T_1 F_26 ( const struct V_40 * V_44 )
{
unsigned int V_43 ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ )
if ( V_44 == V_46 [ V_43 ] . V_44 )
return V_46 [ V_43 ] . type ;
return V_54 ;
}
static void T_1 F_27 ( struct V_40 * V_41 ,
struct V_1 * V_44 )
{
const char * V_17 = V_44 -> V_4 . V_17 ;
switch ( F_26 ( V_41 ) ) {
case V_50 :
F_8 ( L_7 , V_17 ) ;
V_44 -> V_27 = & V_55 ;
V_44 -> V_9 = F_15 ;
break;
case V_52 :
F_8 ( L_8 , V_17 ) ;
V_44 -> V_27 = & V_55 ;
V_44 -> V_9 = F_16 ;
break;
case V_56 :
F_8 ( L_9 , V_17 ) ;
V_44 -> V_27 = & V_55 ;
V_44 -> V_9 = F_15 ;
break;
case V_57 :
F_8 ( L_10 , V_17 ) ;
V_44 -> V_27 = & V_55 ;
V_44 -> V_9 = F_15 ;
break;
case V_54 :
break;
}
F_13 ( V_44 ) ;
}
static int T_1 F_28 ( void T_2 * V_11 ,
struct V_40 * V_58 ,
struct V_2 * V_59 )
{
struct V_40 * V_41 ;
F_29 (parent, np) {
struct V_1 * V_44 ;
T_3 V_60 = ~ 0 ;
if ( F_30 ( V_41 , L_11 , & V_60 ) ) {
}
V_44 = F_31 ( sizeof( * V_44 ) , V_61 ) ;
if ( ! V_44 ) {
F_19 ( V_41 ) ;
return - V_62 ;
}
V_44 -> V_4 . V_17 = V_41 -> V_17 ;
V_44 -> V_11 = V_11 ;
V_44 -> V_7 = V_60 ;
F_27 ( V_41 , V_44 ) ;
if ( V_59 )
F_32 ( V_59 , & V_44 -> V_4 ) ;
F_33 ( V_41 , & V_44 -> V_4 ) ;
F_28 ( V_11 , V_41 , & V_44 -> V_4 ) ;
}
return 0 ;
}
static int T_1 F_34 ( void )
{
struct V_40 * V_41 , * V_63 ;
bool V_64 = false ;
void T_2 * V_11 ;
int V_10 = 0 ;
F_35 (np, NULL, L_12 ) {
V_11 = F_36 ( V_41 , 0 ) ;
if ( ! V_11 ) {
F_21 ( L_13 , V_41 -> V_47 ) ;
continue;
}
V_63 = F_37 ( V_41 , L_14 ) ;
if ( ! V_63 ) {
F_21 ( L_15 , V_41 -> V_47 ) ;
continue;
}
if ( ! V_64 ) {
F_22 () ;
V_64 = true ;
}
V_10 = F_28 ( V_11 , V_63 , NULL ) ;
F_19 ( V_63 ) ;
if ( V_10 ) {
F_19 ( V_41 ) ;
break;
}
}
F_25 () ;
return V_10 ;
}
