static T_1 F_1 ( void )
{
struct V_1 * V_2 ;
T_1 V_3 ;
struct V_4 * V_5 ;
int V_6 ;
V_2 = F_2 ( NULL , L_1 ) ;
if ( V_2 ) {
V_6 = F_3 ( V_2 , L_2 , & V_3 ) ;
F_4 ( V_2 ) ;
if ( ! V_6 )
return V_3 ;
}
V_5 = F_5 ( NULL , L_3 ) ;
if ( F_6 ( V_5 ) ) {
F_7 ( L_4 ,
V_7 , F_8 ( V_5 ) ) ;
return F_8 ( V_5 ) ;
}
return F_9 ( V_5 ) ;
}
static struct V_4 * F_10 ( int V_8 )
{
struct V_1 * V_9 ;
struct V_4 * V_4 ;
if ( ! F_11 ( V_8 ) )
return NULL ;
V_9 = F_12 ( V_8 , NULL ) ;
if ( ! V_9 )
return NULL ;
V_4 = F_13 ( V_9 , 0 ) ;
F_4 ( V_9 ) ;
return V_4 ;
}
static void F_14 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_4 * V_4 ;
int V_15 ;
F_15 (i) {
V_4 = F_10 ( V_15 ) ;
if ( F_6 ( V_4 ) ) {
F_7 ( L_5 , V_7 , V_15 ) ;
continue;
}
if ( F_16 ( V_11 -> V_4 , V_4 ) )
F_17 ( V_15 , V_13 ) ;
}
}
static void F_18 ( struct V_16 * V_17 ,
int V_18 )
{
int V_15 , V_19 ;
for ( V_15 = 1 ; V_15 < V_18 ; V_15 ++ ) {
for ( V_19 = 0 ; V_19 < V_15 ; V_19 ++ ) {
if ( V_17 [ V_19 ] . V_20 == V_21 ||
V_17 [ V_19 ] . V_20 !=
V_17 [ V_15 ] . V_20 )
continue;
V_17 [ V_15 ] . V_20 = V_21 ;
break;
}
}
}
static void F_19 ( struct V_16 * V_17 ,
int V_18 )
{
int V_15 , V_19 , V_22 ;
unsigned int V_23 , V_24 ;
struct V_16 V_25 ;
for ( V_15 = 0 ; V_15 < V_18 - 1 ; V_15 ++ ) {
V_24 = V_17 [ V_15 ] . V_20 ;
V_22 = V_15 ;
for ( V_19 = V_15 + 1 ; V_19 < V_18 ; V_19 ++ ) {
V_23 = V_17 [ V_19 ] . V_20 ;
if ( V_23 == V_21 ||
V_23 <= V_24 )
continue;
V_22 = V_19 ;
V_24 = V_23 ;
}
if ( V_22 != V_15 ) {
V_25 . V_26 = V_17 [ V_15 ] . V_26 ;
V_25 . V_20 = V_17 [ V_15 ] . V_20 ;
V_17 [ V_15 ] . V_26 = V_17 [ V_22 ] . V_26 ;
V_17 [ V_15 ] . V_20 = V_17 [ V_22 ] . V_20 ;
V_17 [ V_22 ] . V_26 = V_25 . V_26 ;
V_17 [ V_22 ] . V_20 = V_25 . V_20 ;
}
}
}
static int F_20 ( struct V_10 * V_11 )
{
struct V_1 * V_9 ;
int V_15 , V_18 , V_6 ;
T_1 V_23 ;
struct V_4 * V_4 ;
const struct V_27 * V_28 ;
struct V_16 * V_25 ;
struct V_29 * V_30 ;
unsigned int V_8 = V_11 -> V_8 ;
T_2 V_31 ;
V_9 = F_12 ( V_8 , NULL ) ;
if ( ! V_9 )
return - V_32 ;
V_30 = F_21 ( sizeof( * V_30 ) , V_33 ) ;
if ( ! V_30 )
goto V_34;
V_11 -> V_4 = F_13 ( V_9 , 0 ) ;
if ( F_6 ( V_11 -> V_4 ) ) {
F_7 ( L_6 , V_7 ) ;
goto V_35;
}
V_28 = F_22 ( V_11 -> V_4 ) ;
V_18 = F_23 ( V_28 ) ;
V_30 -> V_36 = F_24 ( V_18 , sizeof( struct V_4 * ) , V_33 ) ;
if ( ! V_30 -> V_36 ) {
F_7 ( L_7 , V_7 ) ;
goto V_35;
}
V_25 = F_24 ( V_18 + 1 , sizeof( * V_25 ) , V_33 ) ;
if ( ! V_25 ) {
F_7 ( L_7 , V_7 ) ;
goto V_37;
}
for ( V_15 = 0 ; V_15 < V_18 ; V_15 ++ ) {
V_4 = F_25 ( V_28 , V_15 ) -> V_4 ;
V_30 -> V_36 [ V_15 ] = V_4 ;
V_23 = F_9 ( V_4 ) ;
V_25 [ V_15 ] . V_20 = V_23 / 1000 ;
V_25 [ V_15 ] . V_26 = V_15 ;
}
F_18 ( V_25 , V_18 ) ;
F_19 ( V_25 , V_18 ) ;
V_25 [ V_15 ] . V_20 = V_38 ;
V_6 = F_26 ( V_11 , V_25 ) ;
if ( V_6 ) {
F_7 ( L_8 , V_6 ) ;
goto V_39;
}
V_30 -> V_25 = V_25 ;
F_14 ( V_11 ) ;
V_11 -> V_26 = V_30 ;
V_31 = 12ULL * V_40 ;
F_27 ( V_31 , F_1 () ) ;
V_11 -> V_41 . V_42 = V_31 + 1 ;
F_4 ( V_9 ) ;
return 0 ;
V_39:
F_28 ( V_25 ) ;
V_37:
F_28 ( V_30 -> V_36 ) ;
V_35:
F_28 ( V_30 ) ;
V_34:
F_4 ( V_9 ) ;
return - V_32 ;
}
static int F_29 ( struct V_10 * V_11 )
{
struct V_29 * V_30 = V_11 -> V_26 ;
F_30 ( V_30 -> V_43 ) ;
F_28 ( V_30 -> V_36 ) ;
F_28 ( V_30 -> V_25 ) ;
F_28 ( V_30 ) ;
V_11 -> V_26 = NULL ;
return 0 ;
}
static int F_31 ( struct V_10 * V_11 ,
unsigned int V_44 )
{
struct V_4 * V_45 ;
struct V_29 * V_30 = V_11 -> V_26 ;
V_45 = V_30 -> V_36 [ V_30 -> V_25 [ V_44 ] . V_26 ] ;
return F_32 ( V_11 -> V_4 , V_45 ) ;
}
static void F_33 ( struct V_10 * V_11 )
{
struct V_29 * V_46 = V_11 -> V_26 ;
struct V_1 * V_9 = F_12 ( V_11 -> V_8 , NULL ) ;
if ( F_34 ( V_9 , L_9 , NULL ) ) {
V_46 -> V_43 = F_35 ( V_9 ,
V_11 -> V_47 ) ;
if ( F_6 ( V_46 -> V_43 ) && F_8 ( V_46 -> V_43 ) != - V_48 ) {
F_7 ( L_10 ,
V_11 -> V_8 , F_8 ( V_46 -> V_43 ) ) ;
V_46 -> V_43 = NULL ;
}
}
F_4 ( V_9 ) ;
}
static int T_3 F_36 ( void )
{
int V_6 ;
struct V_1 * V_9 ;
const struct V_49 * V_50 ;
const struct V_51 * V_30 ;
V_9 = F_37 ( NULL , V_52 ) ;
if ( ! V_9 )
return - V_32 ;
V_50 = F_38 ( V_52 , V_9 ) ;
V_30 = V_50 -> V_30 ;
F_4 ( V_9 ) ;
if ( V_30 && V_30 -> V_53 & V_54 )
return - V_32 ;
V_6 = F_39 ( & V_55 ) ;
if ( ! V_6 )
F_40 ( L_11 ) ;
return V_6 ;
}
static void T_4 F_41 ( void )
{
F_42 ( & V_55 ) ;
}
