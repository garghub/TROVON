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
while ( ( V_15 = F_32 ( & V_17 ) ) )
F_33 ( V_15 , error ) ;
}
void F_34 ( struct V_1 * V_2 ,
void (* F_35)( void * , struct V_10 * ) ,
void * V_37 ,
struct V_10 * V_12 )
{
unsigned long V_34 ;
F_21 ( & V_2 -> V_4 , V_34 ) ;
F_35 ( V_37 , V_12 ) ;
F_26 ( & V_12 -> V_31 , & V_2 -> V_8 ) ;
F_22 ( & V_2 -> V_4 , V_34 ) ;
}
struct V_38 * F_36 ( void )
{
int V_39 ;
struct V_38 * V_40 ;
V_40 = F_2 ( sizeof( * V_40 ) , V_3 ) ;
if ( ! V_40 )
return NULL ;
F_3 ( & V_40 -> V_4 ) ;
V_40 -> V_41 = 0 ;
V_40 -> V_42 = 0 ;
for ( V_39 = 0 ; V_39 < V_43 ; V_39 ++ ) {
V_40 -> V_44 [ V_39 ] . V_40 = V_40 ;
V_40 -> V_44 [ V_39 ] . V_45 = 0 ;
F_37 ( & V_40 -> V_44 [ V_39 ] . V_46 ) ;
}
return V_40 ;
}
void F_38 ( struct V_38 * V_40 )
{
F_5 ( V_40 ) ;
}
struct V_47 * F_39 ( struct V_38 * V_40 )
{
unsigned long V_34 ;
struct V_47 * V_48 ;
F_21 ( & V_40 -> V_4 , V_34 ) ;
V_48 = V_40 -> V_44 + V_40 -> V_41 ;
V_48 -> V_45 ++ ;
F_22 ( & V_40 -> V_4 , V_34 ) ;
return V_48 ;
}
static unsigned F_40 ( unsigned V_49 )
{
return ( V_49 + 1 ) % V_43 ;
}
static void F_41 ( struct V_38 * V_40 , struct V_50 * V_51 )
{
while ( ( V_40 -> V_42 != V_40 -> V_41 ) &&
! V_40 -> V_44 [ V_40 -> V_42 ] . V_45 ) {
F_42 ( & V_40 -> V_44 [ V_40 -> V_42 ] . V_46 , V_51 ) ;
V_40 -> V_42 = F_40 ( V_40 -> V_42 ) ;
}
if ( ( V_40 -> V_42 == V_40 -> V_41 ) && ! V_40 -> V_44 [ V_40 -> V_42 ] . V_45 )
F_42 ( & V_40 -> V_44 [ V_40 -> V_42 ] . V_46 , V_51 ) ;
}
void F_43 ( struct V_47 * V_48 , struct V_50 * V_51 )
{
unsigned long V_34 ;
F_21 ( & V_48 -> V_40 -> V_4 , V_34 ) ;
F_44 ( ! V_48 -> V_45 ) ;
-- V_48 -> V_45 ;
F_41 ( V_48 -> V_40 , V_51 ) ;
F_22 ( & V_48 -> V_40 -> V_4 , V_34 ) ;
}
int F_45 ( struct V_38 * V_40 , struct V_50 * V_52 )
{
int V_27 = 1 ;
unsigned long V_34 ;
unsigned V_53 ;
F_21 ( & V_40 -> V_4 , V_34 ) ;
if ( ( V_40 -> V_42 == V_40 -> V_41 ) &&
! V_40 -> V_44 [ V_40 -> V_41 ] . V_45 )
V_27 = 0 ;
else {
F_46 ( V_52 , & V_40 -> V_44 [ V_40 -> V_41 ] . V_46 ) ;
V_53 = F_40 ( V_40 -> V_41 ) ;
if ( ! V_40 -> V_44 [ V_53 ] . V_45 )
V_40 -> V_41 = V_53 ;
}
F_22 ( & V_40 -> V_4 , V_34 ) ;
return V_27 ;
}
static int T_2 F_47 ( void )
{
V_7 = F_48 ( V_10 , 0 ) ;
if ( ! V_7 )
return - V_54 ;
return 0 ;
}
static void T_3 F_49 ( void )
{
F_50 ( V_7 ) ;
V_7 = NULL ;
}
