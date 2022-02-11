static T_1 F_1 ( unsigned V_1 )
{
T_1 V_2 = 128 ;
V_1 /= 4 ;
V_1 = F_2 ( V_1 , 8192u ) ;
while ( V_2 < V_1 )
V_2 <<= 1 ;
return V_2 ;
}
static void F_3 ( struct V_3 * V_4 )
{
F_4 ( & V_4 -> V_5 ) ;
F_5 ( & V_4 -> V_6 ) ;
}
struct V_7 * F_6 ( unsigned V_1 )
{
unsigned V_8 ;
T_1 V_9 = F_1 ( V_1 ) ;
T_2 V_10 = sizeof( struct V_7 ) +
( sizeof( struct V_3 ) * V_9 ) ;
struct V_7 * V_11 = F_7 ( V_10 , V_12 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_13 = F_8 ( V_1 , V_14 ) ;
if ( ! V_11 -> V_13 ) {
F_9 ( V_11 ) ;
return NULL ;
}
V_11 -> V_9 = V_9 ;
V_11 -> V_15 = V_9 - 1 ;
V_11 -> V_16 = (struct V_3 * ) ( V_11 + 1 ) ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ )
F_3 ( V_11 -> V_16 + V_8 ) ;
return V_11 ;
}
void F_10 ( struct V_7 * V_11 )
{
F_11 ( V_11 -> V_13 ) ;
F_9 ( V_11 ) ;
}
struct V_17 * F_12 ( struct V_7 * V_11 , T_3 V_18 )
{
return F_13 ( V_11 -> V_13 , V_18 ) ;
}
void F_14 ( struct V_7 * V_11 ,
struct V_17 * V_19 )
{
F_15 ( V_19 , V_11 -> V_13 ) ;
}
static T_1 F_16 ( struct V_7 * V_11 , struct V_20 * V_21 )
{
const unsigned long V_22 = 4294967291UL ;
T_4 V_23 = V_21 -> V_24 * V_22 ;
return ( T_1 ) ( V_23 & V_11 -> V_15 ) ;
}
static int F_17 ( struct V_20 * V_25 , struct V_20 * V_26 )
{
return ( V_25 -> V_27 == V_26 -> V_27 ) &&
( V_25 -> V_28 == V_26 -> V_28 ) &&
( V_25 -> V_24 == V_26 -> V_24 ) ;
}
static struct V_3 * F_18 ( struct V_7 * V_11 ,
struct V_20 * V_21 )
{
return V_11 -> V_16 + F_16 ( V_11 , V_21 ) ;
}
static struct V_17 * F_19 ( struct V_3 * V_4 ,
struct V_20 * V_21 )
{
struct V_17 * V_19 ;
F_20 (cell, &b->cells, list)
if ( F_17 ( & V_19 -> V_21 , V_21 ) )
return V_19 ;
return NULL ;
}
static void F_21 ( struct V_3 * V_4 ,
struct V_20 * V_21 ,
struct V_29 * V_30 ,
struct V_17 * V_19 )
{
memcpy ( & V_19 -> V_21 , V_21 , sizeof( V_19 -> V_21 ) ) ;
V_19 -> V_30 = V_30 ;
F_22 ( & V_19 -> V_31 ) ;
F_23 ( & V_19 -> V_32 , & V_4 -> V_6 ) ;
}
static int F_24 ( struct V_3 * V_4 ,
struct V_20 * V_21 ,
struct V_29 * V_33 ,
struct V_17 * V_34 ,
struct V_17 * * V_35 )
{
struct V_17 * V_19 ;
V_19 = F_19 ( V_4 , V_21 ) ;
if ( V_19 ) {
if ( V_33 )
F_25 ( & V_19 -> V_31 , V_33 ) ;
* V_35 = V_19 ;
return 1 ;
}
F_21 ( V_4 , V_21 , V_33 , V_34 ) ;
* V_35 = V_34 ;
return 0 ;
}
static int F_26 ( struct V_7 * V_11 ,
struct V_20 * V_21 ,
struct V_29 * V_33 ,
struct V_17 * V_34 ,
struct V_17 * * V_35 )
{
int V_36 ;
unsigned long V_37 ;
struct V_3 * V_4 = F_18 ( V_11 , V_21 ) ;
F_27 ( & V_4 -> V_5 , V_37 ) ;
V_36 = F_24 ( V_4 , V_21 , V_33 , V_34 , V_35 ) ;
F_28 ( & V_4 -> V_5 , V_37 ) ;
return V_36 ;
}
int F_29 ( struct V_7 * V_11 ,
struct V_20 * V_21 ,
struct V_29 * V_33 ,
struct V_17 * V_34 ,
struct V_17 * * V_35 )
{
return F_26 ( V_11 , V_21 , V_33 , V_34 , V_35 ) ;
}
int F_30 ( struct V_7 * V_11 ,
struct V_20 * V_21 ,
struct V_17 * V_34 ,
struct V_17 * * V_35 )
{
return F_26 ( V_11 , V_21 , NULL , V_34 , V_35 ) ;
}
static void F_31 ( struct V_17 * V_19 ,
struct V_38 * V_39 )
{
F_32 ( & V_19 -> V_32 ) ;
if ( V_39 ) {
if ( V_19 -> V_30 )
F_25 ( V_39 , V_19 -> V_30 ) ;
F_33 ( V_39 , & V_19 -> V_31 ) ;
}
}
void F_34 ( struct V_7 * V_11 ,
struct V_17 * V_19 ,
struct V_38 * V_31 )
{
unsigned long V_37 ;
struct V_3 * V_4 = F_18 ( V_11 , & V_19 -> V_21 ) ;
F_27 ( & V_4 -> V_5 , V_37 ) ;
F_31 ( V_19 , V_31 ) ;
F_28 ( & V_4 -> V_5 , V_37 ) ;
}
static void F_35 ( struct V_17 * V_19 ,
struct V_38 * V_39 )
{
F_32 ( & V_19 -> V_32 ) ;
F_33 ( V_39 , & V_19 -> V_31 ) ;
}
void F_36 ( struct V_7 * V_11 ,
struct V_17 * V_19 ,
struct V_38 * V_39 )
{
unsigned long V_37 ;
struct V_3 * V_4 = F_18 ( V_11 , & V_19 -> V_21 ) ;
F_27 ( & V_4 -> V_5 , V_37 ) ;
F_35 ( V_19 , V_39 ) ;
F_28 ( & V_4 -> V_5 , V_37 ) ;
}
void F_37 ( struct V_7 * V_11 ,
struct V_17 * V_19 , int error )
{
struct V_38 V_31 ;
struct V_29 * V_29 ;
F_22 ( & V_31 ) ;
F_34 ( V_11 , V_19 , & V_31 ) ;
while ( ( V_29 = F_38 ( & V_31 ) ) )
F_39 ( V_29 , error ) ;
}
struct V_40 * F_40 ( void )
{
int V_8 ;
struct V_40 * V_41 ;
V_41 = F_7 ( sizeof( * V_41 ) , V_12 ) ;
if ( ! V_41 )
return NULL ;
F_4 ( & V_41 -> V_5 ) ;
V_41 -> V_42 = 0 ;
V_41 -> V_43 = 0 ;
for ( V_8 = 0 ; V_8 < V_44 ; V_8 ++ ) {
V_41 -> V_45 [ V_8 ] . V_41 = V_41 ;
V_41 -> V_45 [ V_8 ] . V_46 = 0 ;
F_41 ( & V_41 -> V_45 [ V_8 ] . V_47 ) ;
}
return V_41 ;
}
void F_42 ( struct V_40 * V_41 )
{
F_9 ( V_41 ) ;
}
struct V_48 * F_43 ( struct V_40 * V_41 )
{
unsigned long V_37 ;
struct V_48 * V_49 ;
F_27 ( & V_41 -> V_5 , V_37 ) ;
V_49 = V_41 -> V_45 + V_41 -> V_42 ;
V_49 -> V_46 ++ ;
F_28 ( & V_41 -> V_5 , V_37 ) ;
return V_49 ;
}
static unsigned F_44 ( unsigned V_50 )
{
return ( V_50 + 1 ) % V_44 ;
}
static void F_45 ( struct V_40 * V_41 , struct V_51 * V_52 )
{
while ( ( V_41 -> V_43 != V_41 -> V_42 ) &&
! V_41 -> V_45 [ V_41 -> V_43 ] . V_46 ) {
F_46 ( & V_41 -> V_45 [ V_41 -> V_43 ] . V_47 , V_52 ) ;
V_41 -> V_43 = F_44 ( V_41 -> V_43 ) ;
}
if ( ( V_41 -> V_43 == V_41 -> V_42 ) && ! V_41 -> V_45 [ V_41 -> V_43 ] . V_46 )
F_46 ( & V_41 -> V_45 [ V_41 -> V_43 ] . V_47 , V_52 ) ;
}
void F_47 ( struct V_48 * V_49 , struct V_51 * V_52 )
{
unsigned long V_37 ;
F_27 ( & V_49 -> V_41 -> V_5 , V_37 ) ;
F_48 ( ! V_49 -> V_46 ) ;
-- V_49 -> V_46 ;
F_45 ( V_49 -> V_41 , V_52 ) ;
F_28 ( & V_49 -> V_41 -> V_5 , V_37 ) ;
}
int F_49 ( struct V_40 * V_41 , struct V_51 * V_53 )
{
int V_36 = 1 ;
unsigned long V_37 ;
unsigned V_54 ;
F_27 ( & V_41 -> V_5 , V_37 ) ;
if ( ( V_41 -> V_43 == V_41 -> V_42 ) &&
! V_41 -> V_45 [ V_41 -> V_42 ] . V_46 )
V_36 = 0 ;
else {
F_50 ( V_53 , & V_41 -> V_45 [ V_41 -> V_42 ] . V_47 ) ;
V_54 = F_44 ( V_41 -> V_42 ) ;
if ( ! V_41 -> V_45 [ V_54 ] . V_46 )
V_41 -> V_42 = V_54 ;
}
F_28 ( & V_41 -> V_5 , V_37 ) ;
return V_36 ;
}
static int T_5 F_51 ( void )
{
V_14 = F_52 ( V_17 , 0 ) ;
if ( ! V_14 )
return - V_55 ;
return 0 ;
}
static void T_6 F_53 ( void )
{
F_54 ( V_14 ) ;
V_14 = NULL ;
}
