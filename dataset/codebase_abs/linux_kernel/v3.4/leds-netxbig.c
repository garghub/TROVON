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
V_12 = F_10 ( V_2 -> V_3 [ V_13 ] , V_15 ,
L_1 ) ;
if ( V_12 )
goto V_16;
}
for ( V_13 = 0 ; V_13 < V_2 -> V_7 ; V_13 ++ ) {
V_12 = F_10 ( V_2 -> V_6 [ V_13 ] , V_15 ,
L_2 ) ;
if ( V_12 )
goto V_17;
}
V_12 = F_10 ( V_2 -> V_8 , V_15 ,
L_3 ) ;
if ( V_12 )
goto V_17;
return 0 ;
V_17:
for ( V_13 = V_13 - 1 ; V_13 >= 0 ; V_13 -- )
F_11 ( V_2 -> V_6 [ V_13 ] ) ;
V_13 = V_2 -> V_5 ;
V_16:
for ( V_13 = V_13 - 1 ; V_13 >= 0 ; V_13 -- )
F_11 ( V_2 -> V_3 [ V_13 ] ) ;
return V_12 ;
}
static void F_12 ( struct V_1 * V_2 )
{
int V_13 ;
F_11 ( V_2 -> V_8 ) ;
for ( V_13 = V_2 -> V_5 - 1 ; V_13 >= 0 ; V_13 -- )
F_11 ( V_2 -> V_3 [ V_13 ] ) ;
for ( V_13 = V_2 -> V_7 - 1 ; V_13 >= 0 ; V_13 -- )
F_11 ( V_2 -> V_6 [ V_13 ] ) ;
}
static int F_13 ( enum V_18 * V_19 ,
unsigned long V_20 ,
unsigned long V_21 ,
struct V_22 * V_23 ,
int V_24 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_24 ; V_13 ++ ) {
if ( V_23 [ V_13 ] . V_20 == V_20 &&
V_23 [ V_13 ] . V_21 == V_21 ) {
* V_19 = V_23 [ V_13 ] . V_19 ;
return 0 ;
}
}
return - V_14 ;
}
static int F_14 ( struct V_25 * V_26 ,
unsigned long * V_20 ,
unsigned long * V_21 )
{
struct V_27 * V_28 =
F_15 ( V_26 , struct V_27 , V_29 ) ;
enum V_18 V_19 ;
int V_30 ;
int V_31 ;
V_31 = F_13 ( & V_19 , * V_20 , * V_21 ,
V_28 -> V_23 , V_28 -> V_24 ) ;
if ( V_31 < 0 )
return V_31 ;
V_30 = V_28 -> V_30 [ V_19 ] ;
if ( V_30 == V_32 )
return - V_14 ;
F_16 ( & V_28 -> V_33 ) ;
F_5 ( V_28 -> V_2 , V_28 -> V_34 , V_30 ) ;
V_28 -> V_19 = V_19 ;
F_17 ( & V_28 -> V_33 ) ;
return 0 ;
}
static void F_18 ( struct V_25 * V_26 ,
enum V_35 V_9 )
{
struct V_27 * V_28 =
F_15 ( V_26 , struct V_27 , V_29 ) ;
enum V_18 V_19 ;
int V_30 , V_36 ;
int V_37 = 1 ;
unsigned long V_10 ;
F_6 ( & V_28 -> V_33 , V_10 ) ;
if ( V_9 == V_38 ) {
V_19 = V_39 ;
V_37 = 0 ;
} else {
if ( V_28 -> V_40 )
V_19 = V_41 ;
else if ( V_28 -> V_19 == V_39 )
V_19 = V_42 ;
else
V_19 = V_28 -> V_19 ;
}
V_30 = V_28 -> V_30 [ V_19 ] ;
F_5 ( V_28 -> V_2 , V_28 -> V_34 , V_30 ) ;
V_28 -> V_19 = V_19 ;
if ( V_37 ) {
V_36 = F_19 ( V_9 * V_28 -> V_43 ,
V_44 ) ;
F_5 ( V_28 -> V_2 ,
V_28 -> V_45 , V_36 ) ;
}
F_7 ( & V_28 -> V_33 , V_10 ) ;
}
static T_2 F_20 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
const char * V_50 , T_3 V_51 )
{
struct V_25 * V_26 = F_21 ( V_47 ) ;
struct V_27 * V_28 =
F_15 ( V_26 , struct V_27 , V_29 ) ;
unsigned long V_8 ;
enum V_18 V_19 ;
int V_30 ;
int V_31 ;
V_31 = F_22 ( V_50 , 10 , & V_8 ) ;
if ( V_31 < 0 )
return V_31 ;
V_8 = ! ! V_8 ;
F_16 ( & V_28 -> V_33 ) ;
if ( V_28 -> V_40 == V_8 ) {
V_31 = V_51 ;
goto V_52;
}
if ( V_28 -> V_19 != V_42 &&
V_28 -> V_19 != V_41 )
V_19 = V_28 -> V_19 ;
else if ( V_8 )
V_19 = V_41 ;
else
V_19 = V_42 ;
V_30 = V_28 -> V_30 [ V_19 ] ;
if ( V_30 == V_32 ) {
V_31 = - V_14 ;
goto V_52;
}
F_5 ( V_28 -> V_2 , V_28 -> V_34 , V_30 ) ;
V_28 -> V_19 = V_19 ;
V_28 -> V_40 = V_8 ;
V_31 = V_51 ;
V_52:
F_17 ( & V_28 -> V_33 ) ;
return V_31 ;
}
static T_2 F_23 ( struct V_46 * V_47 ,
struct V_48 * V_49 , char * V_53 )
{
struct V_25 * V_26 = F_21 ( V_47 ) ;
struct V_27 * V_28 =
F_15 ( V_26 , struct V_27 , V_29 ) ;
return sprintf ( V_53 , L_4 , V_28 -> V_40 ) ;
}
static void F_24 ( struct V_27 * V_28 )
{
if ( V_28 -> V_30 [ V_41 ] != V_32 )
F_25 ( V_28 -> V_29 . V_47 , & V_54 ) ;
F_26 ( & V_28 -> V_29 ) ;
}
static int T_1
F_27 ( struct V_55 * V_56 ,
struct V_27 * V_28 ,
const struct V_57 * V_58 )
{
struct V_59 * V_60 = V_56 -> V_47 . V_61 ;
int V_31 ;
F_28 ( & V_28 -> V_33 ) ;
V_28 -> V_2 = V_60 -> V_2 ;
V_28 -> V_29 . V_62 = V_58 -> V_62 ;
V_28 -> V_29 . V_63 = V_58 -> V_63 ;
V_28 -> V_29 . V_64 = F_14 ;
V_28 -> V_29 . V_65 = F_18 ;
V_28 -> V_40 = 0 ;
V_28 -> V_29 . V_66 = V_38 ;
V_28 -> V_29 . V_10 |= V_67 ;
V_28 -> V_34 = V_58 -> V_34 ;
V_28 -> V_30 = V_58 -> V_30 ;
V_28 -> V_45 = V_58 -> V_45 ;
V_28 -> V_43 = ( 1 << V_60 -> V_2 -> V_7 ) - 1 ;
V_28 -> V_23 = V_60 -> V_23 ;
V_28 -> V_24 = V_60 -> V_24 ;
V_31 = F_29 ( & V_56 -> V_47 , & V_28 -> V_29 ) ;
if ( V_31 < 0 )
return V_31 ;
if ( V_28 -> V_30 [ V_41 ] != V_32 ) {
V_31 = F_30 ( V_28 -> V_29 . V_47 , & V_54 ) ;
if ( V_31 )
F_26 ( & V_28 -> V_29 ) ;
}
return V_31 ;
}
static int T_1 F_31 ( struct V_55 * V_56 )
{
struct V_59 * V_60 = V_56 -> V_47 . V_61 ;
struct V_27 * V_68 ;
int V_13 ;
int V_31 ;
if ( ! V_60 )
return - V_14 ;
V_68 = F_32 ( sizeof( struct V_27 ) * V_60 -> V_69 ,
V_70 ) ;
if ( ! V_68 )
return - V_71 ;
V_31 = F_8 ( V_60 -> V_2 ) ;
if ( V_31 < 0 )
goto V_17;
for ( V_13 = 0 ; V_13 < V_60 -> V_69 ; V_13 ++ ) {
V_31 = F_27 ( V_56 , & V_68 [ V_13 ] , & V_60 -> V_72 [ V_13 ] ) ;
if ( V_31 < 0 )
goto V_73;
}
F_33 ( V_56 , V_68 ) ;
return 0 ;
V_73:
for ( V_13 = V_13 - 1 ; V_13 >= 0 ; V_13 -- )
F_24 ( & V_68 [ V_13 ] ) ;
F_12 ( V_60 -> V_2 ) ;
V_17:
F_34 ( V_68 ) ;
return V_31 ;
}
static int T_4 F_35 ( struct V_55 * V_56 )
{
struct V_59 * V_60 = V_56 -> V_47 . V_61 ;
struct V_27 * V_68 ;
int V_13 ;
V_68 = F_36 ( V_56 ) ;
for ( V_13 = 0 ; V_13 < V_60 -> V_69 ; V_13 ++ )
F_24 ( & V_68 [ V_13 ] ) ;
F_12 ( V_60 -> V_2 ) ;
F_34 ( V_68 ) ;
return 0 ;
}
