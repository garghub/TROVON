static inline T_1 F_1 ( int V_1 )
{
return F_2 ( V_1 * V_2 ,
V_3 ) ;
}
static inline int F_3 ( T_1 V_4 )
{
return F_2 ( V_4 * V_3 ,
V_2 ) ;
}
static int F_4 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ )
if ( V_6 -> V_11 [ V_9 ] == V_8 )
return V_9 ;
return - V_12 ;
}
static int F_5 ( struct V_13 * V_14 ,
struct V_7 * V_8 )
{
struct V_5 * V_6 = V_14 -> V_15 ;
struct V_16 * V_17 = V_6 -> V_18 -> V_17 ;
int V_9 , V_19 ;
if ( F_4 ( V_6 , V_8 ) < 0 )
return 0 ;
for ( V_9 = 0 ; V_9 < V_20 ; V_9 ++ ) {
const struct V_21 * V_22 = & V_6 -> V_23 [ V_9 ] ;
V_19 = F_6 ( V_14 , V_9 , V_8 ,
V_22 -> V_24 ,
V_22 -> V_25 ,
V_26 ) ;
if ( V_19 < 0 ) {
F_7 ( V_17 , L_1 , V_9 ) ;
return V_19 ;
}
}
return 0 ;
}
static int F_8 ( struct V_13 * V_14 ,
struct V_7 * V_8 )
{
struct V_5 * V_6 = V_14 -> V_15 ;
struct V_16 * V_17 = V_6 -> V_18 -> V_17 ;
int V_9 ;
int V_19 ;
if ( F_4 ( V_6 , V_8 ) < 0 )
return 0 ;
for ( V_9 = 0 ; V_9 < V_20 ; V_9 ++ ) {
V_19 = F_9 ( V_14 , V_9 , V_8 ) ;
if ( V_19 < 0 ) {
F_7 ( V_17 , L_2 ) ;
return V_19 ;
}
}
return 0 ;
}
static int F_10 ( struct V_13 * V_14 ,
enum V_27 * V_28 )
{
struct V_5 * V_6 = V_14 -> V_15 ;
* V_28 = V_6 -> V_28 ;
return 0 ;
}
static int F_11 ( struct V_13 * V_14 ,
enum V_27 V_28 )
{
struct V_5 * V_6 = V_14 -> V_15 ;
F_12 ( & V_14 -> V_29 ) ;
if ( V_28 == V_30 )
V_14 -> V_31 = V_32 ;
else
V_14 -> V_31 = 0 ;
F_13 ( & V_14 -> V_29 ) ;
V_6 -> V_28 = V_28 ;
F_14 ( V_14 , V_33 ) ;
return 0 ;
}
static int F_15 ( struct V_13 * V_14 ,
int * V_34 )
{
struct V_5 * V_6 = V_14 -> V_15 ;
struct V_16 * V_17 = V_6 -> V_18 -> V_17 ;
char V_35 [ V_36 ] ;
unsigned int V_37 ;
int V_19 ;
F_16 ( V_35 , 0 , false , false ) ;
V_19 = F_17 ( V_6 -> V_38 , F_18 ( V_39 ) , V_35 ) ;
if ( V_19 ) {
F_7 ( V_17 , L_3 ) ;
return V_19 ;
}
F_19 ( V_35 , & V_37 , NULL , NULL ) ;
* V_34 = ( int ) V_37 ;
return 0 ;
}
static int F_20 ( struct V_13 * V_14 ,
int V_22 ,
enum V_40 * V_41 )
{
struct V_5 * V_6 = V_14 -> V_15 ;
if ( V_22 < 0 || V_22 >= V_20 )
return - V_42 ;
* V_41 = V_6 -> V_23 [ V_22 ] . type ;
return 0 ;
}
static int F_21 ( struct V_13 * V_14 ,
int V_22 , int * V_34 )
{
struct V_5 * V_6 = V_14 -> V_15 ;
if ( V_22 < 0 || V_22 >= V_20 )
return - V_42 ;
* V_34 = V_6 -> V_23 [ V_22 ] . V_37 ;
return 0 ;
}
static int F_22 ( struct V_13 * V_14 ,
int V_22 , int V_37 )
{
struct V_5 * V_6 = V_14 -> V_15 ;
if ( V_22 < 0 || V_22 >= V_20 ||
V_37 > V_43 )
return - V_42 ;
V_6 -> V_23 [ V_22 ] . V_37 = V_37 ;
return 0 ;
}
static int F_23 ( struct V_7 * V_8 ,
unsigned long * V_44 )
{
* V_44 = V_3 ;
return 0 ;
}
static int F_24 ( struct V_7 * V_8 ,
unsigned long * V_44 )
{
struct V_5 * V_6 = V_8 -> V_15 ;
struct V_16 * V_17 = V_6 -> V_18 -> V_17 ;
char V_45 [ V_46 ] ;
int V_19 , V_47 ;
T_1 V_4 ;
V_47 = F_4 ( V_6 , V_8 ) ;
if ( V_47 < 0 )
return V_47 ;
F_25 ( V_45 , V_47 , 0 ) ;
V_19 = F_17 ( V_6 -> V_38 , F_18 ( V_48 ) , V_45 ) ;
if ( V_19 ) {
F_7 ( V_17 , L_4 ) ;
return V_19 ;
}
V_4 = F_26 ( V_45 ) ;
* V_44 = F_3 ( V_4 ) ;
return 0 ;
}
static int F_27 ( struct V_7 * V_8 ,
unsigned long V_1 )
{
struct V_5 * V_6 = V_8 -> V_15 ;
struct V_16 * V_17 = V_6 -> V_18 -> V_17 ;
char V_45 [ V_46 ] ;
int V_19 , V_47 ;
V_47 = F_4 ( V_6 , V_8 ) ;
if ( V_47 < 0 )
return V_47 ;
F_25 ( V_45 , V_47 , F_1 ( V_1 ) ) ;
V_19 = F_28 ( V_6 -> V_38 , F_18 ( V_48 ) , V_45 ) ;
if ( V_19 ) {
F_7 ( V_17 , L_5 ) ;
return V_19 ;
}
return 0 ;
}
int F_29 ( struct V_49 * V_38 ,
const struct V_50 * V_18 ,
struct V_5 * * V_51 )
{
char V_52 [ V_53 ] = { 0 } ;
enum V_54 V_55 ;
struct V_16 * V_17 = V_18 -> V_17 ;
struct V_5 * V_6 ;
T_2 V_56 ;
T_1 V_57 ;
int V_19 , V_9 ;
V_6 = F_30 ( V_17 , sizeof( * V_6 ) ,
V_58 ) ;
if ( ! V_6 )
return - V_59 ;
V_6 -> V_38 = V_38 ;
V_6 -> V_18 = V_18 ;
memcpy ( V_6 -> V_23 , V_60 , sizeof( V_6 -> V_23 ) ) ;
V_19 = F_17 ( V_6 -> V_38 , F_18 ( V_61 ) , V_52 ) ;
if ( V_19 ) {
F_7 ( V_17 , L_6 ) ;
goto V_62;
}
F_31 ( V_52 , & V_55 , & V_56 , & V_57 ) ;
for ( V_9 = 0 ; V_9 < V_63 ; V_9 ++ ) {
if ( V_56 & F_32 ( V_9 ) ) {
char V_64 [ V_65 ] ;
F_33 ( V_64 , V_9 , 0 , 0 ) ;
V_19 = F_17 ( V_6 -> V_38 , F_18 ( V_66 ) ,
V_64 ) ;
if ( V_19 )
goto V_62;
F_34 ( V_64 , 0 ) ;
V_19 = F_28 ( V_6 -> V_38 , F_18 ( V_66 ) ,
V_64 ) ;
if ( V_19 )
goto V_62;
}
}
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
if ( V_57 & F_32 ( V_9 ) ) {
struct V_7 * V_8 ;
V_8 = F_35 ( L_7 , V_6 ,
& V_67 ) ;
if ( F_36 ( V_8 ) ) {
V_19 = F_37 ( V_8 ) ;
F_7 ( V_17 , L_8 ) ;
goto V_68;
}
V_6 -> V_11 [ V_9 ] = V_8 ;
}
}
V_6 -> V_14 = F_38 ( L_9 ,
V_20 ,
V_69 ,
V_6 ,
& V_70 ,
NULL , 0 ,
V_32 ) ;
if ( F_36 ( V_6 -> V_14 ) ) {
V_19 = F_37 ( V_6 -> V_14 ) ;
F_7 ( V_17 , L_10 ) ;
goto V_68;
}
V_6 -> V_28 = V_30 ;
* V_51 = V_6 ;
return 0 ;
V_68:
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ )
if ( V_6 -> V_11 [ V_9 ] )
F_39 ( V_6 -> V_11 [ V_9 ] ) ;
V_62:
F_40 ( V_17 , V_6 ) ;
return V_19 ;
}
void F_41 ( struct V_5 * V_6 )
{
int V_9 ;
if ( V_6 -> V_14 ) {
F_42 ( V_6 -> V_14 ) ;
V_6 -> V_14 = NULL ;
}
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
if ( V_6 -> V_11 [ V_9 ] ) {
F_39 ( V_6 -> V_11 [ V_9 ] ) ;
V_6 -> V_11 [ V_9 ] = NULL ;
}
}
F_40 ( V_6 -> V_18 -> V_17 , V_6 ) ;
}
