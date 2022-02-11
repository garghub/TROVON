static T_1 F_1 ( void )
{
struct V_1 * V_2 ;
T_1 V_3 ;
V_2 = F_2 ( NULL , L_1 ) ;
if ( ! V_2 )
return 0 ;
if ( F_3 ( V_2 , L_2 , & V_3 ) )
V_3 = 0 ;
F_4 ( V_2 ) ;
return V_3 ;
}
static struct V_4 * F_5 ( int V_5 )
{
struct V_1 * V_6 ;
struct V_4 * V_4 ;
if ( ! F_6 ( V_5 ) )
return NULL ;
V_6 = F_7 ( V_5 , NULL ) ;
if ( ! V_6 )
return NULL ;
V_4 = F_8 ( V_6 , 0 ) ;
F_4 ( V_6 ) ;
return V_4 ;
}
static void F_9 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_4 * V_4 ;
int V_12 ;
F_10 (i) {
V_4 = F_5 ( V_12 ) ;
if ( F_11 ( V_4 ) ) {
F_12 ( L_3 , V_13 , V_12 ) ;
continue;
}
if ( F_13 ( V_8 -> V_4 , V_4 ) )
F_14 ( V_12 , V_10 ) ;
}
}
static void F_15 ( struct V_14 * V_15 ,
int V_16 )
{
int V_12 , V_17 ;
for ( V_12 = 1 ; V_12 < V_16 ; V_12 ++ ) {
for ( V_17 = 0 ; V_17 < V_12 ; V_17 ++ ) {
if ( V_15 [ V_17 ] . V_18 == V_19 ||
V_15 [ V_17 ] . V_18 !=
V_15 [ V_12 ] . V_18 )
continue;
V_15 [ V_12 ] . V_18 = V_19 ;
break;
}
}
}
static void F_16 ( struct V_14 * V_15 ,
int V_16 )
{
int V_12 , V_17 , V_20 ;
unsigned int V_21 , V_22 ;
struct V_14 V_23 ;
for ( V_12 = 0 ; V_12 < V_16 - 1 ; V_12 ++ ) {
V_22 = V_15 [ V_12 ] . V_18 ;
V_20 = V_12 ;
for ( V_17 = V_12 + 1 ; V_17 < V_16 ; V_17 ++ ) {
V_21 = V_15 [ V_17 ] . V_18 ;
if ( V_21 == V_19 ||
V_21 <= V_22 )
continue;
V_20 = V_17 ;
V_22 = V_21 ;
}
if ( V_20 != V_12 ) {
V_23 . V_24 = V_15 [ V_12 ] . V_24 ;
V_23 . V_18 = V_15 [ V_12 ] . V_18 ;
V_15 [ V_12 ] . V_24 = V_15 [ V_20 ] . V_24 ;
V_15 [ V_12 ] . V_18 = V_15 [ V_20 ] . V_18 ;
V_15 [ V_20 ] . V_24 = V_23 . V_24 ;
V_15 [ V_20 ] . V_18 = V_23 . V_18 ;
}
}
}
static int F_17 ( struct V_7 * V_8 )
{
struct V_1 * V_6 ;
int V_12 , V_16 , V_25 ;
T_1 V_21 ;
struct V_4 * V_4 ;
const struct V_26 * V_27 ;
struct V_14 * V_23 ;
struct V_28 * V_29 ;
unsigned int V_5 = V_8 -> V_5 ;
T_2 V_30 ;
V_6 = F_7 ( V_5 , NULL ) ;
if ( ! V_6 )
return - V_31 ;
V_29 = F_18 ( sizeof( * V_29 ) , V_32 ) ;
if ( ! V_29 )
goto V_33;
V_8 -> V_4 = F_8 ( V_6 , 0 ) ;
if ( F_11 ( V_8 -> V_4 ) ) {
F_12 ( L_4 , V_13 ) ;
goto V_34;
}
V_27 = F_19 ( V_8 -> V_4 ) ;
V_16 = F_20 ( V_27 ) ;
V_29 -> V_35 = F_21 ( V_16 , sizeof( struct V_4 * ) , V_32 ) ;
if ( ! V_29 -> V_35 ) {
F_12 ( L_5 , V_13 ) ;
goto V_34;
}
V_23 = F_21 ( V_16 + 1 , sizeof( * V_23 ) , V_32 ) ;
if ( ! V_23 ) {
F_12 ( L_5 , V_13 ) ;
goto V_36;
}
for ( V_12 = 0 ; V_12 < V_16 ; V_12 ++ ) {
V_4 = F_22 ( V_27 , V_12 ) -> V_4 ;
V_29 -> V_35 [ V_12 ] = V_4 ;
V_21 = F_23 ( V_4 ) ;
V_23 [ V_12 ] . V_18 = V_21 / 1000 ;
V_23 [ V_12 ] . V_24 = V_12 ;
}
F_15 ( V_23 , V_16 ) ;
F_16 ( V_23 , V_16 ) ;
V_23 [ V_12 ] . V_18 = V_37 ;
V_25 = F_24 ( V_8 , V_23 ) ;
if ( V_25 ) {
F_12 ( L_6 , V_25 ) ;
goto V_38;
}
V_29 -> V_23 = V_23 ;
F_9 ( V_8 ) ;
V_8 -> V_24 = V_29 ;
V_30 = 12ULL * V_39 ;
F_25 ( V_30 , F_1 () ) ;
V_8 -> V_40 . V_41 = V_30 + 1 ;
F_4 ( V_6 ) ;
return 0 ;
V_38:
F_26 ( V_23 ) ;
V_36:
F_26 ( V_29 -> V_35 ) ;
V_34:
F_26 ( V_29 ) ;
V_33:
F_4 ( V_6 ) ;
return - V_31 ;
}
static int F_27 ( struct V_7 * V_8 )
{
struct V_28 * V_29 = V_8 -> V_24 ;
F_28 ( V_29 -> V_42 ) ;
F_26 ( V_29 -> V_35 ) ;
F_26 ( V_29 -> V_23 ) ;
F_26 ( V_29 ) ;
V_8 -> V_24 = NULL ;
return 0 ;
}
static int F_29 ( struct V_7 * V_8 ,
unsigned int V_43 )
{
struct V_4 * V_44 ;
struct V_28 * V_29 = V_8 -> V_24 ;
V_44 = V_29 -> V_35 [ V_29 -> V_23 [ V_43 ] . V_24 ] ;
return F_30 ( V_8 -> V_4 , V_44 ) ;
}
static void F_31 ( struct V_7 * V_8 )
{
struct V_28 * V_45 = V_8 -> V_24 ;
struct V_1 * V_6 = F_7 ( V_8 -> V_5 , NULL ) ;
if ( F_32 ( V_6 , L_7 , NULL ) ) {
V_45 -> V_42 = F_33 ( V_6 ,
V_8 -> V_46 ) ;
if ( F_11 ( V_45 -> V_42 ) && F_34 ( V_45 -> V_42 ) != - V_47 ) {
F_12 ( L_8 ,
V_8 -> V_5 , F_34 ( V_45 -> V_42 ) ) ;
V_45 -> V_42 = NULL ;
}
}
F_4 ( V_6 ) ;
}
static int T_3 F_35 ( void )
{
int V_25 ;
struct V_1 * V_6 ;
const struct V_48 * V_49 ;
const struct V_50 * V_29 ;
V_6 = F_36 ( NULL , V_51 ) ;
if ( ! V_6 )
return - V_31 ;
V_49 = F_37 ( V_51 , V_6 ) ;
V_29 = V_49 -> V_29 ;
F_4 ( V_6 ) ;
if ( V_29 && V_29 -> V_52 & V_53 )
return - V_31 ;
V_25 = F_38 ( & V_54 ) ;
if ( ! V_25 )
F_39 ( L_9 ) ;
return V_25 ;
}
static void T_4 F_40 ( void )
{
F_41 ( & V_54 ) ;
}
