static void F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ )
F_2 ( V_2 -> V_3 [ V_4 ] , ( V_3 >> V_4 ) & 1 ) ;
}
static void F_3 ( struct V_1 * V_2 , int V_6 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_7 ; V_4 ++ )
F_2 ( V_2 -> V_6 [ V_4 ] , ( V_6 >> V_4 ) & 1 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_8 , 0 ) ;
F_2 ( V_2 -> V_8 , 1 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
int V_3 , int V_9 )
{
unsigned long V_10 ;
F_6 ( & V_11 , V_10 ) ;
F_1 ( V_2 , V_3 ) ;
F_3 ( V_2 , V_9 ) ;
F_4 ( V_2 ) ;
F_7 ( & V_11 , V_10 ) ;
}
static int T_1 F_8 ( struct V_1 * V_2 )
{
int V_12 ;
int V_13 ;
if ( F_9 ( ! V_2 ) )
return - V_14 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_5 ; V_13 ++ ) {
V_12 = F_10 ( V_2 -> V_3 [ V_13 ] , L_1 ) ;
if ( V_12 )
goto V_15;
V_12 = F_11 ( V_2 -> V_3 [ V_13 ] , 0 ) ;
if ( V_12 ) {
F_12 ( V_2 -> V_3 [ V_13 ] ) ;
goto V_15;
}
}
for ( V_13 = 0 ; V_13 < V_2 -> V_7 ; V_13 ++ ) {
V_12 = F_10 ( V_2 -> V_6 [ V_13 ] , L_2 ) ;
if ( V_12 )
goto V_16;
V_12 = F_11 ( V_2 -> V_6 [ V_13 ] , 0 ) ;
if ( V_12 ) {
F_12 ( V_2 -> V_6 [ V_13 ] ) ;
goto V_16;
}
}
V_12 = F_10 ( V_2 -> V_8 , L_3 ) ;
if ( V_12 )
goto V_16;
V_12 = F_11 ( V_2 -> V_8 , 0 ) ;
if ( V_12 ) {
F_12 ( V_2 -> V_8 ) ;
goto V_16;
}
return 0 ;
V_16:
for ( V_13 = V_13 - 1 ; V_13 >= 0 ; V_13 -- )
F_12 ( V_2 -> V_6 [ V_13 ] ) ;
V_13 = V_2 -> V_5 ;
V_15:
for ( V_13 = V_13 - 1 ; V_13 >= 0 ; V_13 -- )
F_12 ( V_2 -> V_3 [ V_13 ] ) ;
return V_12 ;
}
static void T_2 F_13 ( struct V_1 * V_2 )
{
int V_13 ;
F_12 ( V_2 -> V_8 ) ;
for ( V_13 = V_2 -> V_5 - 1 ; V_13 >= 0 ; V_13 -- )
F_12 ( V_2 -> V_3 [ V_13 ] ) ;
for ( V_13 = V_2 -> V_7 - 1 ; V_13 >= 0 ; V_13 -- )
F_12 ( V_2 -> V_6 [ V_13 ] ) ;
}
static int F_14 ( enum V_17 * V_18 ,
unsigned long V_19 ,
unsigned long V_20 ,
struct V_21 * V_22 ,
int V_23 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_23 ; V_13 ++ ) {
if ( V_22 [ V_13 ] . V_19 == V_19 &&
V_22 [ V_13 ] . V_20 == V_20 ) {
* V_18 = V_22 [ V_13 ] . V_18 ;
return 0 ;
}
}
return - V_14 ;
}
static int F_15 ( struct V_24 * V_25 ,
unsigned long * V_19 ,
unsigned long * V_20 )
{
struct V_26 * V_27 =
F_16 ( V_25 , struct V_26 , V_28 ) ;
enum V_17 V_18 ;
int V_29 ;
int V_30 ;
V_30 = F_14 ( & V_18 , * V_19 , * V_20 ,
V_27 -> V_22 , V_27 -> V_23 ) ;
if ( V_30 < 0 )
return V_30 ;
V_29 = V_27 -> V_29 [ V_18 ] ;
if ( V_29 == V_31 )
return - V_14 ;
F_17 ( & V_27 -> V_32 ) ;
F_5 ( V_27 -> V_2 , V_27 -> V_33 , V_29 ) ;
V_27 -> V_18 = V_18 ;
F_18 ( & V_27 -> V_32 ) ;
return 0 ;
}
static void F_19 ( struct V_24 * V_25 ,
enum V_34 V_9 )
{
struct V_26 * V_27 =
F_16 ( V_25 , struct V_26 , V_28 ) ;
enum V_17 V_18 ;
int V_29 , V_35 ;
int V_36 = 1 ;
unsigned long V_10 ;
F_6 ( & V_27 -> V_32 , V_10 ) ;
if ( V_9 == V_37 ) {
V_18 = V_38 ;
V_36 = 0 ;
} else {
if ( V_27 -> V_39 )
V_18 = V_40 ;
else if ( V_27 -> V_18 == V_38 )
V_18 = V_41 ;
else
V_18 = V_27 -> V_18 ;
}
V_29 = V_27 -> V_29 [ V_18 ] ;
F_5 ( V_27 -> V_2 , V_27 -> V_33 , V_29 ) ;
V_27 -> V_18 = V_18 ;
if ( V_36 ) {
V_35 = F_20 ( V_9 * V_27 -> V_42 ,
V_43 ) ;
F_5 ( V_27 -> V_2 ,
V_27 -> V_44 , V_35 ) ;
}
F_7 ( & V_27 -> V_32 , V_10 ) ;
}
static T_3 F_21 ( struct V_45 * V_46 ,
struct V_47 * V_48 ,
const char * V_49 , T_4 V_50 )
{
struct V_24 * V_25 = F_22 ( V_46 ) ;
struct V_26 * V_27 =
F_16 ( V_25 , struct V_26 , V_28 ) ;
unsigned long V_8 ;
enum V_17 V_18 ;
int V_29 ;
int V_30 ;
V_30 = F_23 ( V_49 , 10 , & V_8 ) ;
if ( V_30 < 0 )
return V_30 ;
V_8 = ! ! V_8 ;
F_17 ( & V_27 -> V_32 ) ;
if ( V_27 -> V_39 == V_8 ) {
V_30 = V_50 ;
goto V_51;
}
if ( V_27 -> V_18 != V_41 &&
V_27 -> V_18 != V_40 )
V_18 = V_27 -> V_18 ;
else if ( V_8 )
V_18 = V_40 ;
else
V_18 = V_41 ;
V_29 = V_27 -> V_29 [ V_18 ] ;
if ( V_29 == V_31 ) {
V_30 = - V_14 ;
goto V_51;
}
F_5 ( V_27 -> V_2 , V_27 -> V_33 , V_29 ) ;
V_27 -> V_18 = V_18 ;
V_27 -> V_39 = V_8 ;
V_30 = V_50 ;
V_51:
F_18 ( & V_27 -> V_32 ) ;
return V_30 ;
}
static T_3 F_24 ( struct V_45 * V_46 ,
struct V_47 * V_48 , char * V_52 )
{
struct V_24 * V_25 = F_22 ( V_46 ) ;
struct V_26 * V_27 =
F_16 ( V_25 , struct V_26 , V_28 ) ;
return sprintf ( V_52 , L_4 , V_27 -> V_39 ) ;
}
static void T_2 F_25 ( struct V_26 * V_27 )
{
if ( V_27 -> V_29 [ V_40 ] != V_31 )
F_26 ( V_27 -> V_28 . V_46 , & V_53 ) ;
F_27 ( & V_27 -> V_28 ) ;
}
static int T_1
F_28 ( struct V_54 * V_55 ,
struct V_26 * V_27 ,
const struct V_56 * V_57 )
{
struct V_58 * V_59 = V_55 -> V_46 . V_60 ;
int V_30 ;
F_29 ( & V_27 -> V_32 ) ;
V_27 -> V_2 = V_59 -> V_2 ;
V_27 -> V_28 . V_61 = V_57 -> V_61 ;
V_27 -> V_28 . V_62 = V_57 -> V_62 ;
V_27 -> V_28 . V_63 = F_15 ;
V_27 -> V_28 . V_64 = F_19 ;
V_27 -> V_39 = 0 ;
V_27 -> V_28 . V_65 = V_37 ;
V_27 -> V_28 . V_10 |= V_66 ;
V_27 -> V_33 = V_57 -> V_33 ;
V_27 -> V_29 = V_57 -> V_29 ;
V_27 -> V_44 = V_57 -> V_44 ;
V_27 -> V_42 = ( 1 << V_59 -> V_2 -> V_7 ) - 1 ;
V_27 -> V_22 = V_59 -> V_22 ;
V_27 -> V_23 = V_59 -> V_23 ;
V_30 = F_30 ( & V_55 -> V_46 , & V_27 -> V_28 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_27 -> V_29 [ V_40 ] != V_31 ) {
V_30 = F_31 ( V_27 -> V_28 . V_46 , & V_53 ) ;
if ( V_30 )
F_27 ( & V_27 -> V_28 ) ;
}
return V_30 ;
}
static int T_1 F_32 ( struct V_54 * V_55 )
{
struct V_58 * V_59 = V_55 -> V_46 . V_60 ;
struct V_26 * V_67 ;
int V_13 ;
int V_30 ;
if ( ! V_59 )
return - V_14 ;
V_67 = F_33 ( sizeof( struct V_26 ) * V_59 -> V_68 ,
V_69 ) ;
if ( ! V_67 )
return - V_70 ;
V_30 = F_8 ( V_59 -> V_2 ) ;
if ( V_30 < 0 )
goto V_16;
for ( V_13 = 0 ; V_13 < V_59 -> V_68 ; V_13 ++ ) {
V_30 = F_28 ( V_55 , & V_67 [ V_13 ] , & V_59 -> V_71 [ V_13 ] ) ;
if ( V_30 < 0 )
goto V_72;
}
F_34 ( V_55 , V_67 ) ;
return 0 ;
V_72:
for ( V_13 = V_13 - 1 ; V_13 >= 0 ; V_13 -- )
F_25 ( & V_67 [ V_13 ] ) ;
F_13 ( V_59 -> V_2 ) ;
V_16:
F_35 ( V_67 ) ;
return V_30 ;
}
static int T_2 F_36 ( struct V_54 * V_55 )
{
struct V_58 * V_59 = V_55 -> V_46 . V_60 ;
struct V_26 * V_67 ;
int V_13 ;
V_67 = F_37 ( V_55 ) ;
for ( V_13 = 0 ; V_13 < V_59 -> V_68 ; V_13 ++ )
F_25 ( & V_67 [ V_13 ] ) ;
F_13 ( V_59 -> V_2 ) ;
F_35 ( V_67 ) ;
return 0 ;
}
static int T_5 F_38 ( void )
{
return F_39 ( & V_73 ) ;
}
static void T_6 F_40 ( void )
{
F_41 ( & V_73 ) ;
}
