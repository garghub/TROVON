static inline void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = true ;
F_2 ( & V_2 -> V_4 , V_5 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; V_6 ++ )
if ( V_2 -> V_8 [ V_6 ] != 0 || V_2 -> V_9 [ V_6 ] != 0 ) {
F_1 ( V_2 ) ;
return;
}
F_4 ( & V_2 -> V_10 -> V_11 , L_1 ) ;
F_5 ( & V_2 -> V_4 ) ;
V_2 -> V_3 = false ;
}
static void F_6 ( struct V_12 * V_4 )
{
int V_13 , V_6 , V_14 ;
char V_15 [ 30 ] ;
bool V_16 , V_17 ;
struct V_1 * V_2 ;
V_2 = F_7 ( V_4 , struct V_1 , V_4 . V_4 ) ;
F_8 ( & V_2 -> V_18 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; V_6 ++ ) {
if ( V_2 -> V_8 [ V_6 ] == 0 && V_2 -> V_9 [ V_6 ] == 0 )
continue;
if ( V_2 -> V_8 [ V_6 ] < V_2 -> V_9 [ V_6 ] )
continue;
V_14 = V_2 -> V_19 . V_20 ( V_2 , V_2 -> V_21 [ V_6 ] , & V_13 ) ;
if ( V_14 < 0 ) {
F_9 ( & V_2 -> V_10 -> V_11 , L_2 ) ;
continue;
}
V_16 = false ;
V_17 = false ;
if ( V_2 -> V_9 [ V_6 ] != 0 ) {
if ( V_13 < V_2 -> V_9 [ V_6 ] ) {
if ( V_2 -> V_22 [ V_6 ] == false ) {
V_2 -> V_22 [ V_6 ] = true ;
V_16 = true ;
}
} else {
if ( V_2 -> V_22 [ V_6 ] == true ) {
V_2 -> V_22 [ V_6 ] = false ;
V_16 = true ;
}
}
}
if ( V_2 -> V_8 [ V_6 ] != 0 ) {
if ( V_13 > V_2 -> V_8 [ V_6 ] ) {
if ( V_2 -> V_23 [ V_6 ] == false ) {
V_2 -> V_23 [ V_6 ] = true ;
V_17 = true ;
}
} else if ( V_13 < V_2 -> V_8 [ V_6 ] - V_2 -> V_24 [ V_6 ] ) {
if ( V_2 -> V_23 [ V_6 ] == true ) {
V_2 -> V_23 [ V_6 ] = false ;
V_17 = true ;
}
}
}
if ( V_16 ) {
V_14 = sprintf ( V_15 , L_3 , V_6 + 1 ) ;
F_10 ( & V_2 -> V_10 -> V_11 . V_25 , NULL , V_15 ) ;
}
if ( V_17 ) {
V_14 = sprintf ( V_15 , L_4 , V_6 + 1 ) ;
F_10 ( & V_2 -> V_10 -> V_11 . V_25 , NULL , V_15 ) ;
}
}
F_1 ( V_2 ) ;
F_11 ( & V_2 -> V_18 ) ;
}
static T_1 F_12 ( struct V_26 * V_11 , struct V_27 * V_28 ,
char * V_29 )
{
struct V_1 * V_2 = F_13 ( V_11 ) ;
return V_2 -> V_19 . F_12 ( V_11 , V_28 , V_29 ) ;
}
static T_1 F_14 ( struct V_26 * V_11 ,
struct V_27 * V_28 , char * V_29 )
{
struct V_1 * V_2 = F_13 ( V_11 ) ;
return V_2 -> V_19 . F_14 ( V_11 , V_28 , V_29 ) ;
}
static T_1 F_15 ( struct V_26 * V_11 ,
struct V_27 * V_28 , char * V_29 )
{
int V_14 , V_13 ;
struct V_1 * V_2 = F_13 ( V_11 ) ;
struct V_30 * V_31 = F_16 ( V_28 ) ;
T_2 V_21 = V_2 -> V_21 [ V_31 -> V_32 ] ;
V_14 = V_2 -> V_19 . V_20 ( V_2 , V_21 , & V_13 ) ;
if ( V_14 < 0 )
return V_14 ;
return sprintf ( V_29 , L_5 , V_13 ) ;
}
static T_1 F_17 ( struct V_26 * V_11 , struct V_27 * V_28 ,
const char * V_29 , T_3 V_33 )
{
unsigned long V_34 ;
struct V_1 * V_2 = F_13 ( V_11 ) ;
struct V_30 * V_31 = F_16 ( V_28 ) ;
int V_35 = F_18 ( V_29 , 10 , & V_34 ) ;
if ( V_35 < 0 )
return V_35 ;
V_34 = F_19 ( V_34 , 0 , V_36 ) ;
F_8 ( & V_2 -> V_18 ) ;
V_2 -> V_9 [ V_31 -> V_32 ] = V_34 ;
F_3 ( V_2 ) ;
F_11 ( & V_2 -> V_18 ) ;
return V_33 ;
}
static T_1 F_20 ( struct V_26 * V_11 , struct V_27 * V_28 ,
const char * V_29 , T_3 V_33 )
{
unsigned long V_34 ;
struct V_1 * V_2 = F_13 ( V_11 ) ;
struct V_30 * V_31 = F_16 ( V_28 ) ;
int V_35 = F_18 ( V_29 , 10 , & V_34 ) ;
if ( V_35 < 0 )
return V_35 ;
V_34 = F_19 ( V_34 , 0 , V_36 ) ;
F_8 ( & V_2 -> V_18 ) ;
V_2 -> V_8 [ V_31 -> V_32 ] = V_34 ;
F_3 ( V_2 ) ;
F_11 ( & V_2 -> V_18 ) ;
return V_33 ;
}
static T_1 F_21 ( struct V_26 * V_11 ,
struct V_27 * V_28 ,
const char * V_29 , T_3 V_33 )
{
unsigned long V_34 ;
struct V_1 * V_2 = F_13 ( V_11 ) ;
struct V_30 * V_31 = F_16 ( V_28 ) ;
int V_35 = F_22 ( V_29 , 10 , & V_34 ) ;
if ( V_35 < 0 )
return V_35 ;
V_34 = F_19 ( V_34 , 0 , V_36 ) ;
F_8 ( & V_2 -> V_18 ) ;
V_2 -> V_24 [ V_31 -> V_32 ] = V_34 ;
F_3 ( V_2 ) ;
F_11 ( & V_2 -> V_18 ) ;
return V_33 ;
}
static T_1 F_23 ( struct V_26 * V_11 ,
struct V_27 * V_28 , char * V_29 )
{
struct V_1 * V_2 = F_13 ( V_11 ) ;
struct V_30 * V_31 = F_16 ( V_28 ) ;
return sprintf ( V_29 , L_6 , V_2 -> V_9 [ V_31 -> V_32 ] ) ;
}
static T_1 F_24 ( struct V_26 * V_11 ,
struct V_27 * V_28 , char * V_29 )
{
struct V_1 * V_2 = F_13 ( V_11 ) ;
struct V_30 * V_31 = F_16 ( V_28 ) ;
return sprintf ( V_29 , L_6 , V_2 -> V_8 [ V_31 -> V_32 ] ) ;
}
static T_1 F_25 ( struct V_26 * V_11 ,
struct V_27 * V_28 , char * V_29 )
{
struct V_1 * V_2 = F_13 ( V_11 ) ;
struct V_30 * V_31 = F_16 ( V_28 ) ;
return sprintf ( V_29 , L_6 , V_2 -> V_24 [ V_31 -> V_32 ] ) ;
}
static T_1 F_26 ( struct V_26 * V_11 ,
struct V_27 * V_28 , char * V_29 )
{
struct V_1 * V_2 = F_13 ( V_11 ) ;
struct V_30 * V_31 = F_16 ( V_28 ) ;
return sprintf ( V_29 , L_5 , V_2 -> V_22 [ V_31 -> V_32 ] ) ;
}
static T_1 F_27 ( struct V_26 * V_11 ,
struct V_27 * V_28 , char * V_29 )
{
struct V_1 * V_2 = F_13 ( V_11 ) ;
struct V_30 * V_31 = F_16 ( V_28 ) ;
return sprintf ( V_29 , L_5 , V_2 -> V_23 [ V_31 -> V_32 ] ) ;
}
static T_4 F_28 ( struct V_37 * V_25 ,
struct V_38 * V_31 , int V_39 )
{
struct V_26 * V_11 = F_7 ( V_25 , struct V_26 , V_25 ) ;
struct V_1 * V_2 = F_13 ( V_11 ) ;
if ( V_2 -> V_19 . V_40 )
return V_2 -> V_19 . V_40 ( V_31 , V_39 ) ;
return V_31 -> V_41 ;
}
static T_5 F_29 ( int V_42 , void * V_43 )
{
struct V_44 * V_10 = V_43 ;
struct V_1 * V_2 = F_30 ( V_10 ) ;
V_2 -> V_19 . V_45 ( V_42 , V_2 ) ;
return V_46 ;
}
static int F_31 ( struct V_44 * V_10 )
{
int V_14 ;
int V_42 = F_32 ( V_10 , L_7 ) ;
if ( V_42 < 0 ) {
F_9 ( & V_10 -> V_11 , L_8 ) ;
return V_42 ;
}
V_14 = F_33 ( & V_10 -> V_11 , V_42 , NULL ,
F_29 , 0 , L_9 , V_10 ) ;
if ( V_14 < 0 )
F_9 ( & V_10 -> V_11 , L_10 , V_14 ) ;
return V_14 ;
}
static int F_34 ( struct V_44 * V_10 )
{
struct V_1 * V_2 ;
int V_47 ;
V_2 = F_35 ( & V_10 -> V_11 , sizeof( * V_2 ) , V_48 ) ;
if ( ! V_2 )
return - V_49 ;
V_2 -> V_10 = V_10 ;
F_36 ( & V_2 -> V_18 ) ;
V_47 = F_37 ( V_2 ) ;
if ( V_47 < 0 || ! V_2 -> V_19 . V_20 || ! V_2 -> V_19 . F_12 ||
! V_2 -> V_19 . F_14 )
return V_47 ;
F_38 ( & V_2 -> V_4 , F_6 ) ;
F_39 ( V_10 , V_2 ) ;
V_47 = F_40 ( & V_10 -> V_11 . V_25 , & V_50 ) ;
if ( V_47 < 0 ) {
F_9 ( & V_10 -> V_11 , L_11 , V_47 ) ;
return V_47 ;
}
V_2 -> V_51 = F_41 ( & V_10 -> V_11 ) ;
if ( F_42 ( V_2 -> V_51 ) ) {
V_47 = F_43 ( V_2 -> V_51 ) ;
F_9 ( & V_10 -> V_11 , L_12 , V_47 ) ;
goto V_52;
}
if ( V_2 -> V_19 . V_45 ) {
V_47 = F_31 ( V_10 ) ;
if ( V_47 < 0 )
goto V_53;
}
return 0 ;
V_53:
F_44 ( V_2 -> V_51 ) ;
V_52:
F_45 ( & V_10 -> V_11 . V_25 , & V_50 ) ;
return V_47 ;
}
static int F_46 ( struct V_44 * V_10 )
{
struct V_1 * V_2 = F_30 ( V_10 ) ;
F_5 ( & V_2 -> V_4 ) ;
F_44 ( V_2 -> V_51 ) ;
F_45 ( & V_10 -> V_11 . V_25 , & V_50 ) ;
return 0 ;
}
static int F_47 ( struct V_44 * V_10 ,
T_6 V_54 )
{
struct V_1 * V_2 = F_30 ( V_10 ) ;
if ( V_2 -> V_3 )
F_5 ( & V_2 -> V_4 ) ;
return 0 ;
}
static int F_48 ( struct V_44 * V_10 )
{
struct V_1 * V_2 = F_30 ( V_10 ) ;
if ( V_2 -> V_3 )
F_1 ( V_2 ) ;
return 0 ;
}
