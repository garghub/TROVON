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
struct V_2 * V_5 ;
int V_12 , V_15 , V_24 ;
T_1 V_20 , V_25 ;
struct V_26 * V_26 ;
struct V_13 * V_22 ;
struct V_27 * V_28 ;
unsigned int V_1 = V_8 -> V_1 ;
T_2 V_29 ;
V_5 = F_10 ( V_1 , NULL ) ;
if ( ! V_5 )
return - V_30 ;
V_28 = F_18 ( sizeof( * V_28 ) , V_31 ) ;
if ( ! V_28 )
goto V_32;
V_8 -> V_26 = F_19 ( V_5 , 0 ) ;
if ( F_20 ( V_8 -> V_26 ) ) {
F_21 ( L_4 , V_33 ) ;
goto V_34;
}
V_28 -> V_35 = F_11 ( V_5 , L_3 , 0 ) ;
if ( ! V_28 -> V_35 ) {
F_21 ( L_5 , V_33 ) ;
goto V_34;
}
V_15 = F_22 ( V_28 -> V_35 , L_6 ) ;
V_22 = F_23 ( V_15 + 1 , sizeof( * V_22 ) , V_31 ) ;
if ( ! V_22 ) {
F_21 ( L_7 , V_33 ) ;
goto V_36;
}
if ( V_37 )
V_25 = V_37 [ F_1 ( V_1 ) ] ;
else
V_25 = 0x0 ;
for ( V_12 = 0 ; V_12 < V_15 ; V_12 ++ ) {
V_26 = F_19 ( V_28 -> V_35 , V_12 ) ;
V_20 = F_24 ( V_26 ) ;
if ( V_20 < V_38 || ( V_25 & ( 1 << V_12 ) ) )
V_22 [ V_12 ] . V_17 = V_18 ;
else
V_22 [ V_12 ] . V_17 = V_20 / 1000 ;
V_22 [ V_12 ] . V_23 = V_12 ;
}
F_15 ( V_22 , V_15 ) ;
F_16 ( V_22 , V_15 ) ;
V_22 [ V_12 ] . V_17 = V_39 ;
V_24 = F_25 ( V_8 , V_22 ) ;
if ( V_24 ) {
F_21 ( L_8 , V_24 ) ;
goto V_40;
}
V_28 -> V_22 = V_22 ;
F_12 ( V_8 ) ;
V_8 -> V_23 = V_28 ;
V_29 = 12ULL * V_41 ;
F_26 ( V_29 , F_4 () ) ;
V_8 -> V_42 . V_43 = V_29 + 1 ;
F_7 ( V_5 ) ;
return 0 ;
V_40:
F_27 ( V_22 ) ;
V_36:
F_7 ( V_28 -> V_35 ) ;
V_34:
V_8 -> V_23 = NULL ;
F_27 ( V_28 ) ;
V_32:
F_7 ( V_5 ) ;
return - V_30 ;
}
static int T_3 F_28 ( struct V_7 * V_8 )
{
struct V_27 * V_28 = V_8 -> V_23 ;
F_7 ( V_28 -> V_35 ) ;
F_27 ( V_28 -> V_22 ) ;
F_27 ( V_28 ) ;
V_8 -> V_23 = NULL ;
return 0 ;
}
static int F_29 ( struct V_7 * V_8 ,
unsigned int V_44 )
{
struct V_26 * V_35 ;
struct V_27 * V_28 = V_8 -> V_23 ;
V_35 = F_19 ( V_28 -> V_35 , V_28 -> V_22 [ V_44 ] . V_23 ) ;
return F_30 ( V_8 -> V_26 , V_35 ) ;
}
static int T_4 F_31 ( void )
{
int V_24 ;
struct V_2 * V_5 ;
const struct V_45 * V_46 ;
const struct V_47 * V_28 ;
V_5 = F_32 ( NULL , V_48 ) ;
if ( ! V_5 )
return - V_30 ;
V_46 = F_33 ( V_48 , V_5 ) ;
V_28 = V_46 -> V_28 ;
if ( V_28 ) {
if ( V_28 -> V_49 )
V_37 = V_28 -> V_50 ;
V_38 = F_4 () ;
} else {
V_38 = F_4 () / 2 ;
}
F_7 ( V_5 ) ;
V_24 = F_34 ( & V_51 ) ;
if ( ! V_24 )
F_35 ( L_9 ) ;
return V_24 ;
}
static void T_3 F_36 ( void )
{
F_37 ( & V_51 ) ;
}
