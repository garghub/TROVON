static int F_1 ( int V_1 )
{
return F_2 ( V_1 ) ;
}
static int F_1 ( int V_1 )
{
return F_3 ( V_1 ) ;
}
static T_1 F_4 ( void )
{
struct V_2 * V_3 ;
T_1 V_4 ;
V_3 = F_5 ( NULL , L_1 ) ;
if ( ! V_3 )
return 0 ;
if ( F_6 ( V_3 , L_2 , & V_4 ) )
V_4 = 0 ;
F_7 ( V_3 ) ;
return V_4 ;
}
static struct V_2 * F_8 ( int V_1 )
{
struct V_2 * V_5 , * V_6 ;
if ( ! F_9 ( V_1 ) )
return NULL ;
V_5 = F_10 ( V_1 , NULL ) ;
if ( ! V_5 )
return NULL ;
V_6 = F_11 ( V_5 , L_3 , 0 ) ;
if ( ! V_6 )
return NULL ;
F_7 ( V_5 ) ;
return V_6 ;
}
static void F_12 ( struct V_7 * V_8 )
{
struct V_2 * V_5 , * V_6 ;
struct V_9 * V_10 = V_8 -> V_11 ;
int V_12 ;
V_5 = F_8 ( V_8 -> V_1 ) ;
if ( ! V_5 )
return;
F_13 (i) {
V_6 = F_8 ( V_12 ) ;
if ( ! V_6 )
continue;
if ( V_6 == V_5 )
F_14 ( V_12 , V_10 ) ;
F_7 ( V_6 ) ;
}
F_7 ( V_5 ) ;
}
static void F_15 ( struct V_13 * V_14 ,
int V_15 )
{
int V_12 , V_16 ;
for ( V_12 = 1 ; V_12 < V_15 ; V_12 ++ ) {
for ( V_16 = 0 ; V_16 < V_12 ; V_16 ++ ) {
if ( V_14 [ V_16 ] . V_17 == V_18 ||
V_14 [ V_16 ] . V_17 !=
V_14 [ V_12 ] . V_17 )
continue;
V_14 [ V_12 ] . V_17 = V_18 ;
break;
}
}
}
static void F_16 ( struct V_13 * V_14 ,
int V_15 )
{
int V_12 , V_16 , V_19 ;
unsigned int V_20 , V_21 ;
struct V_13 V_22 ;
for ( V_12 = 0 ; V_12 < V_15 - 1 ; V_12 ++ ) {
V_21 = V_14 [ V_12 ] . V_17 ;
V_19 = V_12 ;
for ( V_16 = V_12 + 1 ; V_16 < V_15 ; V_16 ++ ) {
V_20 = V_14 [ V_16 ] . V_17 ;
if ( V_20 == V_18 ||
V_20 <= V_21 )
continue;
V_19 = V_16 ;
V_21 = V_20 ;
}
if ( V_19 != V_12 ) {
V_22 . V_23 = V_14 [ V_12 ] . V_23 ;
V_22 . V_17 = V_14 [ V_12 ] . V_17 ;
V_14 [ V_12 ] . V_23 = V_14 [ V_19 ] . V_23 ;
V_14 [ V_12 ] . V_17 = V_14 [ V_19 ] . V_17 ;
V_14 [ V_19 ] . V_23 = V_22 . V_23 ;
V_14 [ V_19 ] . V_17 = V_22 . V_17 ;
}
}
}
static int F_17 ( struct V_7 * V_8 )
{
struct V_2 * V_5 , * V_24 ;
int V_12 , V_15 , V_25 ;
T_1 V_20 , V_26 ;
struct V_27 * V_27 ;
struct V_13 * V_22 ;
struct V_28 * V_29 ;
unsigned int V_1 = V_8 -> V_1 ;
T_2 V_30 ;
V_5 = F_10 ( V_1 , NULL ) ;
if ( ! V_5 )
return - V_31 ;
V_29 = F_18 ( sizeof( * V_29 ) , V_32 ) ;
if ( ! V_29 )
goto V_33;
V_8 -> V_27 = F_19 ( V_5 , 0 ) ;
if ( F_20 ( V_8 -> V_27 ) ) {
F_21 ( L_4 , V_34 ) ;
goto V_35;
}
V_24 = F_11 ( V_5 , L_3 , 0 ) ;
if ( ! V_24 ) {
F_21 ( L_5 , V_34 ) ;
goto V_35;
}
V_15 = F_22 ( V_24 , L_6 ) ;
V_29 -> V_36 = F_23 ( V_15 , sizeof( struct V_27 * ) , V_32 ) ;
if ( ! V_29 -> V_36 ) {
F_21 ( L_7 , V_34 ) ;
goto V_37;
}
V_22 = F_23 ( V_15 + 1 , sizeof( * V_22 ) , V_32 ) ;
if ( ! V_22 ) {
F_21 ( L_7 , V_34 ) ;
goto V_38;
}
if ( V_39 )
V_26 = V_39 [ F_1 ( V_1 ) ] ;
else
V_26 = 0x0 ;
for ( V_12 = 0 ; V_12 < V_15 ; V_12 ++ ) {
V_27 = F_19 ( V_24 , V_12 ) ;
V_29 -> V_36 [ V_12 ] = V_27 ;
V_20 = F_24 ( V_27 ) ;
if ( V_20 < V_40 || ( V_26 & ( 1 << V_12 ) ) )
V_22 [ V_12 ] . V_17 = V_18 ;
else
V_22 [ V_12 ] . V_17 = V_20 / 1000 ;
V_22 [ V_12 ] . V_23 = V_12 ;
}
F_15 ( V_22 , V_15 ) ;
F_16 ( V_22 , V_15 ) ;
V_22 [ V_12 ] . V_17 = V_41 ;
V_25 = F_25 ( V_8 , V_22 ) ;
if ( V_25 ) {
F_21 ( L_8 , V_25 ) ;
goto V_42;
}
V_29 -> V_22 = V_22 ;
F_12 ( V_8 ) ;
V_8 -> V_23 = V_29 ;
V_30 = 12ULL * V_43 ;
F_26 ( V_30 , F_4 () ) ;
V_8 -> V_44 . V_45 = V_30 + 1 ;
F_7 ( V_5 ) ;
F_7 ( V_24 ) ;
return 0 ;
V_42:
F_27 ( V_22 ) ;
V_38:
F_27 ( V_29 -> V_36 ) ;
V_37:
F_7 ( V_24 ) ;
V_35:
V_8 -> V_23 = NULL ;
F_27 ( V_29 ) ;
V_33:
F_7 ( V_5 ) ;
return - V_31 ;
}
static int T_3 F_28 ( struct V_7 * V_8 )
{
struct V_28 * V_29 = V_8 -> V_23 ;
F_27 ( V_29 -> V_36 ) ;
F_27 ( V_29 -> V_22 ) ;
F_27 ( V_29 ) ;
V_8 -> V_23 = NULL ;
return 0 ;
}
static int F_29 ( struct V_7 * V_8 ,
unsigned int V_46 )
{
struct V_27 * V_47 ;
struct V_28 * V_29 = V_8 -> V_23 ;
V_47 = V_29 -> V_36 [ V_29 -> V_22 [ V_46 ] . V_23 ] ;
return F_30 ( V_8 -> V_27 , V_47 ) ;
}
static void F_31 ( struct V_7 * V_8 )
{
struct V_28 * V_48 = V_8 -> V_23 ;
struct V_2 * V_5 = F_10 ( V_8 -> V_1 , NULL ) ;
if ( F_32 ( V_5 , L_9 , NULL ) ) {
V_48 -> V_49 = F_33 ( V_5 ,
V_8 -> V_50 ) ;
if ( F_20 ( V_48 -> V_49 ) ) {
F_21 ( L_10 ,
V_8 -> V_1 , F_34 ( V_48 -> V_49 ) ) ;
V_48 -> V_49 = NULL ;
}
}
F_7 ( V_5 ) ;
}
static int T_4 F_35 ( void )
{
int V_25 ;
struct V_2 * V_5 ;
const struct V_51 * V_52 ;
const struct V_53 * V_29 ;
V_5 = F_36 ( NULL , V_54 ) ;
if ( ! V_5 )
return - V_31 ;
V_52 = F_37 ( V_54 , V_5 ) ;
V_29 = V_52 -> V_29 ;
if ( V_29 ) {
if ( V_29 -> V_55 )
V_39 = V_29 -> V_56 ;
V_40 = F_4 () ;
} else {
V_40 = F_4 () / 2 ;
}
F_7 ( V_5 ) ;
V_25 = F_38 ( & V_57 ) ;
if ( ! V_25 )
F_39 ( L_11 ) ;
return V_25 ;
}
static void T_3 F_40 ( void )
{
F_41 ( & V_57 ) ;
}
