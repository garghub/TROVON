struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( sizeof( * V_4 ) , V_5 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_3 = V_3 ;
F_3 ( & V_4 -> V_6 ) ;
V_4 -> V_7 = F_4 ( V_8 , V_9 ) ;
if ( ! V_4 -> V_7 ) {
F_5 ( V_4 ) ;
return NULL ;
}
V_4 -> V_10 = V_11 ;
return V_4 ;
}
void F_6 ( struct V_1 * V_4 )
{
F_7 ( V_4 -> V_7 ) ;
F_5 ( V_4 ) ;
}
struct V_12 * F_8 ( struct V_1 * V_4 , T_1 V_13 )
{
return F_9 ( V_4 -> V_7 , V_13 ) ;
}
void F_10 ( struct V_1 * V_4 ,
struct V_12 * V_14 )
{
F_11 ( V_14 , V_4 -> V_7 ) ;
}
static void F_12 ( struct V_15 * V_16 ,
struct V_12 * V_14 )
{
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
memcpy ( & V_14 -> V_16 , V_16 , sizeof( V_14 -> V_16 ) ) ;
F_13 ( & V_14 -> V_17 ) ;
}
static int F_14 ( struct V_15 * V_18 ,
struct V_15 * V_19 )
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
static bool F_15 ( struct V_1 * V_4 ,
struct V_15 * V_16 ,
struct V_12 * V_24 ,
struct V_12 * * V_25 )
{
int V_26 ;
struct V_27 * * V_28 = & V_4 -> V_10 . V_27 , * V_29 = NULL ;
while ( * V_28 ) {
struct V_12 * V_14 =
F_16 ( * V_28 , struct V_12 , V_30 ) ;
V_26 = F_14 ( V_16 , & V_14 -> V_16 ) ;
V_29 = * V_28 ;
if ( V_26 < 0 )
V_28 = & ( ( * V_28 ) -> V_31 ) ;
else if ( V_26 > 0 )
V_28 = & ( ( * V_28 ) -> V_32 ) ;
else {
* V_25 = V_14 ;
return true ;
}
}
F_12 ( V_16 , V_24 ) ;
* V_25 = V_24 ;
F_17 ( & V_24 -> V_30 , V_29 , V_28 ) ;
F_18 ( & V_24 -> V_30 , & V_4 -> V_10 ) ;
return false ;
}
static bool F_19 ( struct V_1 * V_4 ,
struct V_15 * V_16 ,
unsigned V_33 ,
struct V_34 * V_35 ,
struct V_12 * V_24 ,
struct V_12 * * V_14 )
{
if ( F_15 ( V_4 , V_16 , V_24 , V_14 ) ) {
if ( ( * V_14 ) -> V_36 ) {
if ( V_33 <= ( * V_14 ) -> V_37 ) {
F_20 ( & ( * V_14 ) -> V_17 , V_35 ) ;
return false ;
}
}
( * V_14 ) -> V_38 ++ ;
} else
( * V_14 ) -> V_38 = 1 ;
return true ;
}
bool F_21 ( struct V_1 * V_4 ,
struct V_15 * V_16 ,
unsigned V_33 ,
struct V_34 * V_35 ,
struct V_12 * V_24 ,
struct V_12 * * V_39 )
{
int V_26 ;
unsigned long V_40 ;
F_22 ( & V_4 -> V_6 , V_40 ) ;
V_26 = F_19 ( V_4 , V_16 , V_33 , V_35 , V_24 , V_39 ) ;
F_23 ( & V_4 -> V_6 , V_40 ) ;
return V_26 ;
}
static bool F_24 ( struct V_1 * V_4 ,
struct V_12 * V_14 )
{
F_25 ( ! V_14 -> V_38 ) ;
V_14 -> V_38 -- ;
if ( ! V_14 -> V_38 ) {
if ( V_14 -> V_36 ) {
if ( V_14 -> V_41 ) {
F_26 ( V_4 -> V_3 , V_14 -> V_41 ) ;
V_14 -> V_41 = NULL ;
}
} else {
F_27 ( & V_14 -> V_30 , & V_4 -> V_10 ) ;
return true ;
}
}
return false ;
}
bool F_28 ( struct V_1 * V_4 ,
struct V_12 * V_14 )
{
bool V_26 ;
unsigned long V_40 ;
F_22 ( & V_4 -> V_6 , V_40 ) ;
V_26 = F_24 ( V_4 , V_14 ) ;
F_23 ( & V_4 -> V_6 , V_40 ) ;
return V_26 ;
}
static int F_29 ( struct V_1 * V_4 ,
struct V_15 * V_16 ,
unsigned V_33 ,
struct V_12 * V_24 ,
struct V_12 * * V_39 )
{
struct V_12 * V_14 ;
if ( F_15 ( V_4 , V_16 , V_24 , & V_14 ) ) {
if ( V_14 -> V_36 )
return - V_42 ;
V_14 -> V_36 = true ;
V_14 -> V_37 = V_33 ;
* V_39 = V_14 ;
return V_14 -> V_38 > 0 ;
} else {
V_14 = V_24 ;
V_14 -> V_38 = 0 ;
V_14 -> V_36 = true ;
V_14 -> V_37 = V_33 ;
* V_39 = V_14 ;
}
return 0 ;
}
int F_30 ( struct V_1 * V_4 ,
struct V_15 * V_16 ,
unsigned V_33 ,
struct V_12 * V_24 ,
struct V_12 * * V_39 )
{
int V_26 ;
unsigned long V_40 ;
F_22 ( & V_4 -> V_6 , V_40 ) ;
V_26 = F_29 ( V_4 , V_16 , V_33 , V_24 , V_39 ) ;
F_23 ( & V_4 -> V_6 , V_40 ) ;
return V_26 ;
}
static void F_31 ( struct V_1 * V_4 ,
struct V_12 * V_14 ,
struct V_43 * V_44 )
{
if ( ! V_14 -> V_38 )
F_26 ( V_4 -> V_3 , V_44 ) ;
else
V_14 -> V_41 = V_44 ;
}
void F_32 ( struct V_1 * V_4 ,
struct V_12 * V_14 ,
struct V_43 * V_44 )
{
unsigned long V_40 ;
F_22 ( & V_4 -> V_6 , V_40 ) ;
F_31 ( V_4 , V_14 , V_44 ) ;
F_23 ( & V_4 -> V_6 , V_40 ) ;
}
static int F_33 ( struct V_1 * V_4 ,
struct V_12 * V_14 ,
unsigned V_45 )
{
if ( ! V_14 -> V_36 )
return - V_46 ;
V_14 -> V_37 = V_45 ;
return V_14 -> V_38 > 0 ;
}
int F_34 ( struct V_1 * V_4 ,
struct V_12 * V_14 ,
unsigned V_45 )
{
int V_26 ;
unsigned long V_40 ;
F_22 ( & V_4 -> V_6 , V_40 ) ;
V_26 = F_33 ( V_4 , V_14 , V_45 ) ;
F_23 ( & V_4 -> V_6 , V_40 ) ;
return V_26 ;
}
static bool F_35 ( struct V_1 * V_4 ,
struct V_12 * V_14 ,
struct V_47 * V_17 )
{
F_25 ( ! V_14 -> V_36 ) ;
F_36 ( V_17 , & V_14 -> V_17 ) ;
F_13 ( & V_14 -> V_17 ) ;
if ( V_14 -> V_38 ) {
V_14 -> V_36 = 0 ;
return false ;
}
F_27 ( & V_14 -> V_30 , & V_4 -> V_10 ) ;
return true ;
}
bool F_37 ( struct V_1 * V_4 ,
struct V_12 * V_14 ,
struct V_47 * V_17 )
{
bool V_26 ;
unsigned long V_40 ;
F_22 ( & V_4 -> V_6 , V_40 ) ;
V_26 = F_35 ( V_4 , V_14 , V_17 ) ;
F_23 ( & V_4 -> V_6 , V_40 ) ;
return V_26 ;
}
int T_2 F_38 ( void )
{
V_9 = F_39 ( V_12 , 0 ) ;
if ( ! V_9 )
return - V_48 ;
return 0 ;
}
void F_40 ( void )
{
F_41 ( V_9 ) ;
V_9 = NULL ;
}
