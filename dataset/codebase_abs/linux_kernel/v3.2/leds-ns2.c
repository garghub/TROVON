static int F_1 ( struct V_1 * V_2 ,
enum V_3 * V_4 )
{
int V_5 ;
int V_6 = - V_7 ;
int V_8 ;
int V_9 ;
F_2 ( & V_2 -> V_10 ) ;
V_8 = F_3 ( V_2 -> V_11 ) ;
V_9 = F_3 ( V_2 -> V_12 ) ;
for ( V_5 = 0 ; V_5 < F_4 ( V_13 ) ; V_5 ++ ) {
if ( V_8 == V_13 [ V_5 ] . V_8 &&
V_9 == V_13 [ V_5 ] . V_9 ) {
* V_4 = V_13 [ V_5 ] . V_4 ;
V_6 = 0 ;
break;
}
}
F_5 ( & V_2 -> V_10 ) ;
return V_6 ;
}
static void F_6 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
int V_5 ;
unsigned long V_14 ;
F_7 ( & V_2 -> V_10 , V_14 ) ;
for ( V_5 = 0 ; V_5 < F_4 ( V_13 ) ; V_5 ++ ) {
if ( V_4 == V_13 [ V_5 ] . V_4 ) {
F_8 ( V_2 -> V_11 ,
V_13 [ V_5 ] . V_8 ) ;
F_8 ( V_2 -> V_12 ,
V_13 [ V_5 ] . V_9 ) ;
}
}
F_9 ( & V_2 -> V_10 , V_14 ) ;
}
static void F_10 ( struct V_15 * V_16 ,
enum V_17 V_18 )
{
struct V_1 * V_2 =
F_11 ( V_16 , struct V_1 , V_19 ) ;
enum V_3 V_4 ;
if ( V_18 == V_20 )
V_4 = V_21 ;
else if ( V_2 -> V_22 )
V_4 = V_23 ;
else
V_4 = V_24 ;
F_6 ( V_2 , V_4 ) ;
}
static T_1 F_12 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
const char * V_29 , T_2 V_30 )
{
struct V_15 * V_16 = F_13 ( V_26 ) ;
struct V_1 * V_2 =
F_11 ( V_16 , struct V_1 , V_19 ) ;
int V_6 ;
unsigned long V_31 ;
enum V_3 V_4 ;
V_6 = F_14 ( V_29 , 10 , & V_31 ) ;
if ( V_6 < 0 )
return V_6 ;
V_31 = ! ! V_31 ;
if ( V_2 -> V_22 == V_31 )
return V_30 ;
V_6 = F_1 ( V_2 , & V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_31 && V_4 == V_24 )
F_6 ( V_2 , V_23 ) ;
if ( ! V_31 && V_4 == V_23 )
F_6 ( V_2 , V_24 ) ;
V_2 -> V_22 = V_31 ;
return V_30 ;
}
static T_1 F_15 ( struct V_25 * V_26 ,
struct V_27 * V_28 , char * V_32 )
{
struct V_15 * V_16 = F_13 ( V_26 ) ;
struct V_1 * V_2 =
F_11 ( V_16 , struct V_1 , V_19 ) ;
return sprintf ( V_32 , L_1 , V_2 -> V_22 ) ;
}
static int T_3
F_16 ( struct V_33 * V_34 , struct V_1 * V_2 ,
const struct V_35 * V_36 )
{
int V_6 ;
enum V_3 V_4 ;
V_6 = F_17 ( V_36 -> V_11 , V_36 -> V_37 ) ;
if ( V_6 == 0 ) {
V_6 = F_18 ( V_36 -> V_11 ,
F_3 ( V_36 -> V_11 ) ) ;
if ( V_6 )
F_19 ( V_36 -> V_11 ) ;
}
if ( V_6 ) {
F_20 ( & V_34 -> V_26 , L_2 ,
V_36 -> V_37 ) ;
}
V_6 = F_17 ( V_36 -> V_12 , V_36 -> V_37 ) ;
if ( V_6 == 0 ) {
V_6 = F_18 ( V_36 -> V_12 ,
F_3 ( V_36 -> V_12 ) ) ;
if ( V_6 )
F_19 ( V_36 -> V_12 ) ;
}
if ( V_6 ) {
F_20 ( & V_34 -> V_26 , L_3 ,
V_36 -> V_37 ) ;
goto V_38;
}
F_21 ( & V_2 -> V_10 ) ;
V_2 -> V_19 . V_37 = V_36 -> V_37 ;
V_2 -> V_19 . V_39 = V_36 -> V_39 ;
V_2 -> V_19 . V_40 = NULL ;
V_2 -> V_19 . V_41 = F_10 ;
V_2 -> V_19 . V_14 |= V_42 ;
V_2 -> V_11 = V_36 -> V_11 ;
V_2 -> V_12 = V_36 -> V_12 ;
V_6 = F_1 ( V_2 , & V_4 ) ;
if ( V_6 < 0 )
goto V_43;
V_2 -> V_22 = ( V_4 == V_23 ) ? 1 : 0 ;
V_2 -> V_19 . V_44 =
( V_4 == V_21 ) ? V_20 : V_45 ;
V_6 = F_22 ( & V_34 -> V_26 , & V_2 -> V_19 ) ;
if ( V_6 < 0 )
goto V_43;
V_6 = F_23 ( V_2 -> V_19 . V_26 , & V_46 ) ;
if ( V_6 < 0 )
goto V_47;
return 0 ;
V_47:
F_24 ( & V_2 -> V_19 ) ;
V_43:
F_19 ( V_2 -> V_12 ) ;
V_38:
F_19 ( V_2 -> V_11 ) ;
return V_6 ;
}
static void T_4 F_25 ( struct V_1 * V_2 )
{
F_26 ( V_2 -> V_19 . V_26 , & V_46 ) ;
F_24 ( & V_2 -> V_19 ) ;
F_19 ( V_2 -> V_11 ) ;
F_19 ( V_2 -> V_12 ) ;
}
static int T_3 F_27 ( struct V_33 * V_34 )
{
struct V_48 * V_49 = V_34 -> V_26 . V_50 ;
struct V_1 * V_51 ;
int V_5 ;
int V_6 ;
if ( ! V_49 )
return - V_7 ;
V_51 = F_28 ( sizeof( struct V_1 ) *
V_49 -> V_52 , V_53 ) ;
if ( ! V_51 )
return - V_54 ;
for ( V_5 = 0 ; V_5 < V_49 -> V_52 ; V_5 ++ ) {
V_6 = F_16 ( V_34 , & V_51 [ V_5 ] , & V_49 -> V_55 [ V_5 ] ) ;
if ( V_6 < 0 )
goto V_56;
}
F_29 ( V_34 , V_51 ) ;
return 0 ;
V_56:
for ( V_5 = V_5 - 1 ; V_5 >= 0 ; V_5 -- )
F_25 ( & V_51 [ V_5 ] ) ;
F_30 ( V_51 ) ;
return V_6 ;
}
static int T_4 F_31 ( struct V_33 * V_34 )
{
int V_5 ;
struct V_48 * V_49 = V_34 -> V_26 . V_50 ;
struct V_1 * V_51 ;
V_51 = F_32 ( V_34 ) ;
for ( V_5 = 0 ; V_5 < V_49 -> V_52 ; V_5 ++ )
F_25 ( & V_51 [ V_5 ] ) ;
F_30 ( V_51 ) ;
F_29 ( V_34 , NULL ) ;
return 0 ;
}
static int T_5 F_33 ( void )
{
return F_34 ( & V_57 ) ;
}
static void T_6 F_35 ( void )
{
F_36 ( & V_57 ) ;
}
