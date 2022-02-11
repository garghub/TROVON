int F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
if ( V_4 . V_2 ) {
F_3 ( & V_3 ) ;
return - V_5 ;
}
V_4 . V_2 = V_2 ;
F_3 ( & V_3 ) ;
return 0 ;
}
void F_4 ( void )
{
F_2 ( & V_3 ) ;
V_4 . V_2 = NULL ;
F_3 ( & V_3 ) ;
}
static void F_5 ( void )
{
int V_6 ;
int V_7 ;
V_4 . V_2 -> V_8 () ;
for ( V_6 = 0 ; V_6 < V_9 ; V_6 ++ ) {
V_7 = V_4 . V_2 -> V_10 ( V_4 . V_11 [ V_6 ] . V_12 ) ;
if ( V_7 < 0 )
return;
V_4 . V_11 [ V_6 ] . V_13 = V_7 ;
}
F_6 ( & V_4 ) ;
V_4 . V_14 = true ;
}
int F_7 ( struct V_15 * V_12 ,
void (* F_8)( struct V_15 * V_12 , enum V_16 ) ,
void (* F_9)( struct V_15 * V_12 ) ,
bool (* F_10)( struct V_15 * V_12 ) )
{
int V_17 ;
F_2 ( & V_3 ) ;
if ( V_4 . V_18 & 1 )
V_17 = 1 ;
else
V_17 = 0 ;
V_4 . V_11 [ V_17 ] . V_19 = V_20 ;
V_4 . V_11 [ V_17 ] . V_12 = V_12 ;
V_4 . V_11 [ V_17 ] . F_8 = F_8 ;
V_4 . V_11 [ V_17 ] . F_9 = F_9 ;
V_4 . V_11 [ V_17 ] . F_10 = F_10 ;
V_4 . V_11 [ V_17 ] . V_13 = - 1 ;
if ( V_12 -> V_21 [ V_22 ] . V_23 & V_24 )
V_4 . V_11 [ V_17 ] . V_14 = true ;
V_4 . V_18 |= ( 1 << V_17 ) ;
if ( V_4 . V_18 == 0x3 && V_4 . V_2 ) {
F_11 ( V_25 L_1 ) ;
F_5 () ;
}
F_3 ( & V_3 ) ;
return 0 ;
}
void F_12 ( struct V_15 * V_12 )
{
int V_6 ;
F_2 ( & V_3 ) ;
for ( V_6 = 0 ; V_6 < V_9 ; V_6 ++ ) {
if ( V_4 . V_11 [ V_6 ] . V_12 == V_12 ) {
V_4 . V_18 &= ~ ( 1 << V_6 ) ;
break;
}
}
F_11 ( V_25 L_2 ) ;
F_13 ( & V_4 ) ;
V_4 . V_14 = false ;
F_3 ( & V_3 ) ;
}
void F_14 ( struct V_15 * V_12 ,
struct V_26 * V_27 )
{
int V_6 ;
F_2 ( & V_3 ) ;
for ( V_6 = 0 ; V_6 < V_9 ; V_6 ++ ) {
if ( V_4 . V_11 [ V_6 ] . V_12 == V_12 ) {
V_4 . V_11 [ V_6 ] . V_26 = V_27 ;
break;
}
}
F_3 ( & V_3 ) ;
}
static int F_15 ( struct V_28 * V_29 , void * V_30 )
{
int V_6 ;
F_2 ( & V_3 ) ;
for ( V_6 = 0 ; V_6 < V_9 ; V_6 ++ ) {
F_16 ( V_29 , L_3 , V_6 ,
V_4 . V_11 [ V_6 ] . V_13 == V_31 ? L_4 : L_5 ,
V_4 . V_11 [ V_6 ] . V_14 ? '+' : ' ' ,
V_4 . V_11 [ V_6 ] . V_19 ? L_6 : L_7 ,
F_17 ( V_4 . V_11 [ V_6 ] . V_12 ) ) ;
}
F_3 ( & V_3 ) ;
return 0 ;
}
static int F_18 ( struct V_32 * V_32 , struct V_33 * V_33 )
{
return F_19 ( V_33 , F_15 , NULL ) ;
}
static int F_20 ( struct V_34 * V_35 )
{
if ( V_4 . V_2 -> V_36 )
V_4 . V_2 -> V_36 ( V_35 -> V_13 , V_20 ) ;
V_35 -> F_8 ( V_35 -> V_12 , V_20 ) ;
V_35 -> V_19 = V_20 ;
return 0 ;
}
static int F_21 ( struct V_34 * V_35 )
{
V_35 -> F_8 ( V_35 -> V_12 , V_37 ) ;
if ( V_4 . V_2 -> V_36 )
V_4 . V_2 -> V_36 ( V_35 -> V_13 , V_37 ) ;
V_35 -> V_19 = V_37 ;
return 0 ;
}
static int F_22 ( struct V_34 * V_38 )
{
int V_6 ;
struct V_34 * V_14 = NULL ;
for ( V_6 = 0 ; V_6 < V_9 ; V_6 ++ ) {
if ( V_4 . V_11 [ V_6 ] . V_14 == true ) {
V_14 = & V_4 . V_11 [ V_6 ] ;
break;
}
}
if ( ! V_14 )
return 0 ;
if ( V_38 -> V_19 == V_37 )
F_20 ( V_38 ) ;
V_14 -> V_12 -> V_21 [ V_22 ] . V_23 &= ~ V_24 ;
V_38 -> V_12 -> V_21 [ V_22 ] . V_23 |= V_24 ;
return 0 ;
}
static int F_23 ( struct V_34 * V_38 )
{
int V_7 ;
int V_6 ;
struct V_34 * V_14 = NULL ;
for ( V_6 = 0 ; V_6 < V_9 ; V_6 ++ ) {
if ( V_4 . V_11 [ V_6 ] . V_14 == true ) {
V_14 = & V_4 . V_11 [ V_6 ] ;
break;
}
}
if ( ! V_14 )
return 0 ;
V_14 -> V_14 = false ;
if ( V_38 -> V_26 ) {
struct V_39 V_40 ;
V_40 . V_27 = V_38 -> V_26 ;
F_24 ( V_41 , & V_40 ) ;
}
V_7 = V_4 . V_2 -> V_42 ( V_38 -> V_13 ) ;
if ( V_7 )
return V_7 ;
if ( V_38 -> F_9 )
V_38 -> F_9 ( V_38 -> V_12 ) ;
if ( V_14 -> V_19 == V_20 )
F_21 ( V_14 ) ;
V_38 -> V_14 = true ;
return 0 ;
}
static T_1
F_25 ( struct V_33 * V_43 , const char T_2 * V_44 ,
T_3 V_45 , T_4 * V_46 )
{
char V_47 [ 64 ] ;
const char * V_48 ;
int V_6 , V_7 ;
bool V_49 = false , F_10 ;
bool V_50 = false ;
int V_51 = - 1 ;
struct V_34 * V_35 = NULL ;
if ( V_45 > 63 )
V_45 = 63 ;
if ( F_26 ( V_47 , V_44 , V_45 ) )
return - V_52 ;
F_2 ( & V_3 ) ;
if ( ! V_4 . V_14 ) {
V_45 = - V_5 ;
goto V_53;
}
if ( strncmp ( V_47 , L_8 , 3 ) == 0 ) {
for ( V_6 = 0 ; V_6 < V_9 ; V_6 ++ ) {
if ( V_4 . V_11 [ V_6 ] . V_14 )
continue;
if ( V_4 . V_11 [ V_6 ] . V_19 == V_20 )
F_21 ( & V_4 . V_11 [ V_6 ] ) ;
}
goto V_53;
}
if ( strncmp ( V_47 , L_9 , 2 ) == 0 ) {
for ( V_6 = 0 ; V_6 < V_9 ; V_6 ++ ) {
if ( V_4 . V_11 [ V_6 ] . V_14 )
continue;
if ( V_4 . V_11 [ V_6 ] . V_19 == V_37 )
F_20 ( & V_4 . V_11 [ V_6 ] ) ;
}
goto V_53;
}
if ( strncmp ( V_47 , L_10 , 4 ) == 0 ) {
V_51 = V_54 ;
V_49 = true ;
}
if ( strncmp ( V_47 , L_11 , 4 ) == 0 ) {
V_51 = V_31 ;
V_49 = true ;
}
if ( strncmp ( V_47 , L_5 , 3 ) == 0 )
V_51 = V_54 ;
if ( strncmp ( V_47 , L_4 , 3 ) == 0 )
V_51 = V_31 ;
if ( strncmp ( V_47 , L_12 , 4 ) == 0 ) {
V_50 = true ;
V_51 = V_54 ;
}
if ( strncmp ( V_47 , L_13 , 4 ) == 0 ) {
V_50 = true ;
V_51 = V_31 ;
}
if ( V_51 == - 1 )
goto V_53;
for ( V_6 = 0 ; V_6 < V_9 ; V_6 ++ ) {
if ( V_4 . V_11 [ V_6 ] . V_13 == V_51 ) {
V_35 = & V_4 . V_11 [ V_6 ] ;
break;
}
}
V_4 . V_55 = false ;
if ( V_50 ) {
V_7 = V_4 . V_2 -> V_42 ( V_51 ) ;
goto V_53;
}
if ( V_35 -> V_14 == true )
goto V_53;
F_10 = true ;
for ( V_6 = 0 ; V_6 < V_9 ; V_6 ++ ) {
F_10 = V_4 . V_11 [ V_6 ] . F_10 ( V_4 . V_11 [ V_6 ] . V_12 ) ;
if ( F_10 == false ) {
F_11 ( V_56 L_14 , V_6 ) ;
break;
}
}
if ( F_10 == false && V_49 == false )
goto V_53;
if ( F_10 == true ) {
V_48 = F_17 ( V_35 -> V_12 ) ;
V_7 = F_22 ( V_35 ) ;
if ( V_7 )
F_11 ( V_56 L_15 , V_7 ) ;
V_7 = F_23 ( V_35 ) ;
if ( V_7 )
F_11 ( V_56 L_16 , V_7 ) ;
} else {
F_11 ( V_25 L_17 , V_35 -> V_13 ) ;
V_4 . V_55 = true ;
V_4 . V_57 = V_51 ;
V_7 = F_22 ( V_35 ) ;
if ( V_7 )
F_11 ( V_56 L_18 , V_7 ) ;
}
V_53:
F_3 ( & V_3 ) ;
return V_45 ;
}
static void F_13 ( struct V_4 * V_58 )
{
if ( V_58 -> V_59 ) {
F_27 ( V_58 -> V_59 ) ;
V_58 -> V_59 = NULL ;
}
if ( V_58 -> V_60 ) {
F_27 ( V_58 -> V_60 ) ;
V_58 -> V_60 = NULL ;
}
}
static int F_6 ( struct V_4 * V_58 )
{
if ( V_58 -> V_60 )
return 0 ;
V_58 -> V_60 = F_28 ( L_19 , NULL ) ;
if ( ! V_58 -> V_60 ) {
F_11 ( V_56 L_20 ) ;
goto V_61;
}
V_58 -> V_59 = F_29 ( L_21 , 0644 ,
V_58 -> V_60 , NULL , & V_62 ) ;
if ( ! V_58 -> V_59 ) {
F_11 ( V_56 L_22 ) ;
goto V_61;
}
return 0 ;
V_61:
F_13 ( V_58 ) ;
return - 1 ;
}
int F_30 ( void )
{
struct V_34 * V_35 = NULL ;
const char * V_48 ;
bool F_10 = true ;
int V_6 ;
int V_7 ;
int V_63 = - V_5 ;
F_2 ( & V_3 ) ;
if ( ! V_4 . V_55 )
goto V_63;
F_11 ( V_25 L_23 , V_4 . V_57 ) ;
for ( V_6 = 0 ; V_6 < V_9 ; V_6 ++ ) {
if ( V_4 . V_11 [ V_6 ] . V_13 == V_4 . V_57 )
V_35 = & V_4 . V_11 [ V_6 ] ;
F_10 = V_4 . V_11 [ V_6 ] . F_10 ( V_4 . V_11 [ V_6 ] . V_12 ) ;
if ( F_10 == false ) {
F_11 ( V_56 L_14 , V_6 ) ;
break;
}
}
if ( F_10 == false || V_35 == NULL )
goto V_63;
V_48 = F_17 ( V_35 -> V_12 ) ;
V_7 = F_23 ( V_35 ) ;
if ( V_7 )
F_11 ( V_56 L_24 , V_7 ) ;
V_4 . V_55 = false ;
V_63 = 0 ;
V_63:
F_3 ( & V_3 ) ;
return V_63 ;
}
