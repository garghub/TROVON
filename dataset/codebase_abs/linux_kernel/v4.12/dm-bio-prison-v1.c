struct V_1 * F_1 ( void )
{
struct V_1 * V_2 = F_2 ( sizeof( * V_2 ) , V_3 ) ;
if ( ! V_2 )
return NULL ;
F_3 ( & V_2 -> V_4 ) ;
V_2 -> V_5 = F_4 ( V_6 , V_7 ) ;
if ( ! V_2 -> V_5 ) {
F_5 ( V_2 ) ;
return NULL ;
}
V_2 -> V_8 = V_9 ;
return V_2 ;
}
void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_5 ) ;
F_5 ( V_2 ) ;
}
struct V_10 * F_8 ( struct V_1 * V_2 , T_1 V_11 )
{
return F_9 ( V_2 -> V_5 , V_11 ) ;
}
void F_10 ( struct V_1 * V_2 ,
struct V_10 * V_12 )
{
F_11 ( V_12 , V_2 -> V_5 ) ;
}
static void F_12 ( struct V_13 * V_14 ,
struct V_15 * V_16 ,
struct V_10 * V_12 )
{
memcpy ( & V_12 -> V_14 , V_14 , sizeof( V_12 -> V_14 ) ) ;
V_12 -> V_16 = V_16 ;
F_13 ( & V_12 -> V_17 ) ;
}
static int F_14 ( struct V_13 * V_18 ,
struct V_13 * V_19 )
{
if ( V_18 -> V_20 < V_19 -> V_20 )
return - 1 ;
if ( V_18 -> V_20 > V_19 -> V_20 )
return 1 ;
if ( V_18 -> V_21 < V_19 -> V_21 )
return - 1 ;
if ( V_18 -> V_21 > V_19 -> V_21 )
return 1 ;
if ( V_18 -> V_22 <= V_19 -> V_23 )
return - 1 ;
if ( V_18 -> V_23 >= V_19 -> V_22 )
return 1 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_15 * V_24 ,
struct V_10 * V_25 ,
struct V_10 * * V_26 )
{
int V_27 ;
struct V_28 * * V_29 = & V_2 -> V_8 . V_28 , * V_30 = NULL ;
while ( * V_29 ) {
struct V_10 * V_12 =
F_16 ( * V_29 , struct V_10 , V_31 ) ;
V_27 = F_14 ( V_14 , & V_12 -> V_14 ) ;
V_30 = * V_29 ;
if ( V_27 < 0 )
V_29 = & ( ( * V_29 ) -> V_32 ) ;
else if ( V_27 > 0 )
V_29 = & ( ( * V_29 ) -> V_33 ) ;
else {
if ( V_24 )
F_17 ( & V_12 -> V_17 , V_24 ) ;
* V_26 = V_12 ;
return 1 ;
}
}
F_12 ( V_14 , V_24 , V_25 ) ;
* V_26 = V_25 ;
F_18 ( & V_25 -> V_31 , V_30 , V_29 ) ;
F_19 ( & V_25 -> V_31 , & V_2 -> V_8 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_15 * V_24 ,
struct V_10 * V_25 ,
struct V_10 * * V_26 )
{
int V_27 ;
unsigned long V_34 ;
F_21 ( & V_2 -> V_4 , V_34 ) ;
V_27 = F_15 ( V_2 , V_14 , V_24 , V_25 , V_26 ) ;
F_22 ( & V_2 -> V_4 , V_34 ) ;
return V_27 ;
}
int F_23 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_15 * V_24 ,
struct V_10 * V_25 ,
struct V_10 * * V_26 )
{
return F_20 ( V_2 , V_14 , V_24 , V_25 , V_26 ) ;
}
int F_24 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_10 * V_25 ,
struct V_10 * * V_26 )
{
return F_20 ( V_2 , V_14 , NULL , V_25 , V_26 ) ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_10 * V_12 ,
struct V_35 * V_36 )
{
F_26 ( & V_12 -> V_31 , & V_2 -> V_8 ) ;
if ( V_36 ) {
if ( V_12 -> V_16 )
F_17 ( V_36 , V_12 -> V_16 ) ;
F_27 ( V_36 , & V_12 -> V_17 ) ;
}
}
void F_28 ( struct V_1 * V_2 ,
struct V_10 * V_12 ,
struct V_35 * V_17 )
{
unsigned long V_34 ;
F_21 ( & V_2 -> V_4 , V_34 ) ;
F_25 ( V_2 , V_12 , V_17 ) ;
F_22 ( & V_2 -> V_4 , V_34 ) ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_10 * V_12 ,
struct V_35 * V_36 )
{
F_26 ( & V_12 -> V_31 , & V_2 -> V_8 ) ;
F_27 ( V_36 , & V_12 -> V_17 ) ;
}
void F_30 ( struct V_1 * V_2 ,
struct V_10 * V_12 ,
struct V_35 * V_36 )
{
unsigned long V_34 ;
F_21 ( & V_2 -> V_4 , V_34 ) ;
F_29 ( V_2 , V_12 , V_36 ) ;
F_22 ( & V_2 -> V_4 , V_34 ) ;
}
void F_31 ( struct V_1 * V_2 ,
struct V_10 * V_12 , int error )
{
struct V_35 V_17 ;
struct V_15 * V_15 ;
F_13 ( & V_17 ) ;
F_28 ( V_2 , V_12 , & V_17 ) ;
while ( ( V_15 = F_32 ( & V_17 ) ) ) {
V_15 -> V_37 = error ;
F_33 ( V_15 ) ;
}
}
void F_34 ( struct V_1 * V_2 ,
void (* F_35)( void * , struct V_10 * ) ,
void * V_38 ,
struct V_10 * V_12 )
{
unsigned long V_34 ;
F_21 ( & V_2 -> V_4 , V_34 ) ;
F_35 ( V_38 , V_12 ) ;
F_26 ( & V_12 -> V_31 , & V_2 -> V_8 ) ;
F_22 ( & V_2 -> V_4 , V_34 ) ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_10 * V_12 )
{
if ( F_37 ( & V_12 -> V_17 ) ) {
F_26 ( & V_12 -> V_31 , & V_2 -> V_8 ) ;
return 1 ;
}
V_12 -> V_16 = F_32 ( & V_12 -> V_17 ) ;
return 0 ;
}
int F_38 ( struct V_1 * V_2 ,
struct V_10 * V_12 )
{
int V_27 ;
unsigned long V_34 ;
F_21 ( & V_2 -> V_4 , V_34 ) ;
V_27 = F_36 ( V_2 , V_12 ) ;
F_22 ( & V_2 -> V_4 , V_34 ) ;
return V_27 ;
}
struct V_39 * F_39 ( void )
{
int V_40 ;
struct V_39 * V_41 ;
V_41 = F_2 ( sizeof( * V_41 ) , V_3 ) ;
if ( ! V_41 )
return NULL ;
F_3 ( & V_41 -> V_4 ) ;
V_41 -> V_42 = 0 ;
V_41 -> V_43 = 0 ;
for ( V_40 = 0 ; V_40 < V_44 ; V_40 ++ ) {
V_41 -> V_45 [ V_40 ] . V_41 = V_41 ;
V_41 -> V_45 [ V_40 ] . V_46 = 0 ;
F_40 ( & V_41 -> V_45 [ V_40 ] . V_47 ) ;
}
return V_41 ;
}
void F_41 ( struct V_39 * V_41 )
{
F_5 ( V_41 ) ;
}
struct V_48 * F_42 ( struct V_39 * V_41 )
{
unsigned long V_34 ;
struct V_48 * V_49 ;
F_21 ( & V_41 -> V_4 , V_34 ) ;
V_49 = V_41 -> V_45 + V_41 -> V_42 ;
V_49 -> V_46 ++ ;
F_22 ( & V_41 -> V_4 , V_34 ) ;
return V_49 ;
}
static unsigned F_43 ( unsigned V_50 )
{
return ( V_50 + 1 ) % V_44 ;
}
static void F_44 ( struct V_39 * V_41 , struct V_51 * V_52 )
{
while ( ( V_41 -> V_43 != V_41 -> V_42 ) &&
! V_41 -> V_45 [ V_41 -> V_43 ] . V_46 ) {
F_45 ( & V_41 -> V_45 [ V_41 -> V_43 ] . V_47 , V_52 ) ;
V_41 -> V_43 = F_43 ( V_41 -> V_43 ) ;
}
if ( ( V_41 -> V_43 == V_41 -> V_42 ) && ! V_41 -> V_45 [ V_41 -> V_43 ] . V_46 )
F_45 ( & V_41 -> V_45 [ V_41 -> V_43 ] . V_47 , V_52 ) ;
}
void F_46 ( struct V_48 * V_49 , struct V_51 * V_52 )
{
unsigned long V_34 ;
F_21 ( & V_49 -> V_41 -> V_4 , V_34 ) ;
F_47 ( ! V_49 -> V_46 ) ;
-- V_49 -> V_46 ;
F_44 ( V_49 -> V_41 , V_52 ) ;
F_22 ( & V_49 -> V_41 -> V_4 , V_34 ) ;
}
int F_48 ( struct V_39 * V_41 , struct V_51 * V_53 )
{
int V_27 = 1 ;
unsigned long V_34 ;
unsigned V_54 ;
F_21 ( & V_41 -> V_4 , V_34 ) ;
if ( ( V_41 -> V_43 == V_41 -> V_42 ) &&
! V_41 -> V_45 [ V_41 -> V_42 ] . V_46 )
V_27 = 0 ;
else {
F_49 ( V_53 , & V_41 -> V_45 [ V_41 -> V_42 ] . V_47 ) ;
V_54 = F_43 ( V_41 -> V_42 ) ;
if ( ! V_41 -> V_45 [ V_54 ] . V_46 )
V_41 -> V_42 = V_54 ;
}
F_22 ( & V_41 -> V_4 , V_34 ) ;
return V_27 ;
}
static int T_2 F_50 ( void )
{
V_7 = F_51 ( V_10 , 0 ) ;
if ( ! V_7 )
return - V_55 ;
return 0 ;
}
static void F_52 ( void )
{
F_53 ( V_7 ) ;
V_7 = NULL ;
}
static int T_2 F_54 ( void )
{
const int V_46 = F_55 ( V_56 ) ;
int V_27 , V_40 ;
for ( V_40 = 0 ; V_40 < V_46 ; V_40 ++ ) {
V_27 = V_56 [ V_40 ] ( ) ;
if ( V_27 )
goto V_57;
}
return 0 ;
V_57:
while ( V_40 -- )
V_58 [ V_40 ] ( ) ;
return V_27 ;
}
static void T_3 F_56 ( void )
{
int V_40 = F_55 ( V_58 ) ;
while ( V_40 -- )
V_58 [ V_40 ] ( ) ;
}
