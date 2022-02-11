static T_1 F_1 ( unsigned V_1 )
{
T_1 V_2 = 128 ;
V_1 /= 4 ;
V_1 = F_2 ( V_1 , 8192u ) ;
while ( V_2 < V_1 )
V_2 <<= 1 ;
return V_2 ;
}
struct V_3 * F_3 ( unsigned V_1 )
{
unsigned V_4 ;
T_1 V_5 = F_1 ( V_1 ) ;
T_2 V_6 = sizeof( struct V_3 ) +
( sizeof( struct V_7 ) * V_5 ) ;
struct V_3 * V_8 = F_4 ( V_6 , V_9 ) ;
if ( ! V_8 )
return NULL ;
F_5 ( & V_8 -> V_10 ) ;
V_8 -> V_11 = F_6 ( V_1 , V_12 ) ;
if ( ! V_8 -> V_11 ) {
F_7 ( V_8 ) ;
return NULL ;
}
V_8 -> V_5 = V_5 ;
V_8 -> V_13 = V_5 - 1 ;
V_8 -> V_14 = (struct V_7 * ) ( V_8 + 1 ) ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ )
F_8 ( V_8 -> V_14 + V_4 ) ;
return V_8 ;
}
void F_9 ( struct V_3 * V_8 )
{
F_10 ( V_8 -> V_11 ) ;
F_7 ( V_8 ) ;
}
struct V_15 * F_11 ( struct V_3 * V_8 , T_3 V_16 )
{
return F_12 ( V_8 -> V_11 , V_16 ) ;
}
void F_13 ( struct V_3 * V_8 ,
struct V_15 * V_17 )
{
F_14 ( V_17 , V_8 -> V_11 ) ;
}
static T_1 F_15 ( struct V_3 * V_8 , struct V_18 * V_19 )
{
const unsigned long V_20 = 4294967291UL ;
T_4 V_21 = V_19 -> V_22 * V_20 ;
return ( T_1 ) ( V_21 & V_8 -> V_13 ) ;
}
static int F_16 ( struct V_18 * V_23 , struct V_18 * V_24 )
{
return ( V_23 -> V_25 == V_24 -> V_25 ) &&
( V_23 -> V_26 == V_24 -> V_26 ) &&
( V_23 -> V_22 == V_24 -> V_22 ) ;
}
static struct V_15 * F_17 ( struct V_7 * V_27 ,
struct V_18 * V_19 )
{
struct V_15 * V_17 ;
F_18 (cell, bucket, list)
if ( F_16 ( & V_17 -> V_19 , V_19 ) )
return V_17 ;
return NULL ;
}
static void F_19 ( struct V_3 * V_8 ,
struct V_18 * V_19 ,
struct V_28 * V_29 ,
T_1 V_21 ,
struct V_15 * V_17 )
{
memcpy ( & V_17 -> V_19 , V_19 , sizeof( V_17 -> V_19 ) ) ;
V_17 -> V_29 = V_29 ;
F_20 ( & V_17 -> V_30 ) ;
F_21 ( & V_17 -> V_31 , V_8 -> V_14 + V_21 ) ;
}
static int F_22 ( struct V_3 * V_8 ,
struct V_18 * V_19 ,
struct V_28 * V_32 ,
struct V_15 * V_33 ,
struct V_15 * * V_34 )
{
T_1 V_21 = F_15 ( V_8 , V_19 ) ;
struct V_15 * V_17 ;
V_17 = F_17 ( V_8 -> V_14 + V_21 , V_19 ) ;
if ( V_17 ) {
if ( V_32 )
F_23 ( & V_17 -> V_30 , V_32 ) ;
* V_34 = V_17 ;
return 1 ;
}
F_19 ( V_8 , V_19 , V_32 , V_21 , V_33 ) ;
* V_34 = V_33 ;
return 0 ;
}
static int F_24 ( struct V_3 * V_8 ,
struct V_18 * V_19 ,
struct V_28 * V_32 ,
struct V_15 * V_33 ,
struct V_15 * * V_34 )
{
int V_35 ;
unsigned long V_36 ;
F_25 ( & V_8 -> V_10 , V_36 ) ;
V_35 = F_22 ( V_8 , V_19 , V_32 , V_33 , V_34 ) ;
F_26 ( & V_8 -> V_10 , V_36 ) ;
return V_35 ;
}
int F_27 ( struct V_3 * V_8 ,
struct V_18 * V_19 ,
struct V_28 * V_32 ,
struct V_15 * V_33 ,
struct V_15 * * V_34 )
{
return F_24 ( V_8 , V_19 , V_32 , V_33 , V_34 ) ;
}
int F_28 ( struct V_3 * V_8 ,
struct V_18 * V_19 ,
struct V_15 * V_33 ,
struct V_15 * * V_34 )
{
return F_24 ( V_8 , V_19 , NULL , V_33 , V_34 ) ;
}
static void F_29 ( struct V_15 * V_17 ,
struct V_37 * V_38 )
{
F_30 ( & V_17 -> V_31 ) ;
if ( V_38 ) {
if ( V_17 -> V_29 )
F_23 ( V_38 , V_17 -> V_29 ) ;
F_31 ( V_38 , & V_17 -> V_30 ) ;
}
}
void F_32 ( struct V_3 * V_8 ,
struct V_15 * V_17 ,
struct V_37 * V_30 )
{
unsigned long V_36 ;
F_25 ( & V_8 -> V_10 , V_36 ) ;
F_29 ( V_17 , V_30 ) ;
F_26 ( & V_8 -> V_10 , V_36 ) ;
}
static void F_33 ( struct V_15 * V_17 ,
struct V_37 * V_38 )
{
F_30 ( & V_17 -> V_31 ) ;
F_31 ( V_38 , & V_17 -> V_30 ) ;
}
void F_34 ( struct V_3 * V_8 ,
struct V_15 * V_17 ,
struct V_37 * V_38 )
{
unsigned long V_36 ;
F_25 ( & V_8 -> V_10 , V_36 ) ;
F_33 ( V_17 , V_38 ) ;
F_26 ( & V_8 -> V_10 , V_36 ) ;
}
void F_35 ( struct V_3 * V_8 ,
struct V_15 * V_17 )
{
struct V_37 V_30 ;
struct V_28 * V_28 ;
unsigned long V_36 ;
F_20 ( & V_30 ) ;
F_25 ( & V_8 -> V_10 , V_36 ) ;
F_29 ( V_17 , & V_30 ) ;
F_26 ( & V_8 -> V_10 , V_36 ) ;
while ( ( V_28 = F_36 ( & V_30 ) ) )
F_37 ( V_28 ) ;
}
struct V_39 * F_38 ( void )
{
int V_4 ;
struct V_39 * V_40 ;
V_40 = F_4 ( sizeof( * V_40 ) , V_9 ) ;
if ( ! V_40 )
return NULL ;
F_5 ( & V_40 -> V_10 ) ;
V_40 -> V_41 = 0 ;
V_40 -> V_42 = 0 ;
for ( V_4 = 0 ; V_4 < V_43 ; V_4 ++ ) {
V_40 -> V_44 [ V_4 ] . V_40 = V_40 ;
V_40 -> V_44 [ V_4 ] . V_45 = 0 ;
F_39 ( & V_40 -> V_44 [ V_4 ] . V_46 ) ;
}
return V_40 ;
}
void F_40 ( struct V_39 * V_40 )
{
F_7 ( V_40 ) ;
}
struct V_47 * F_41 ( struct V_39 * V_40 )
{
unsigned long V_36 ;
struct V_47 * V_48 ;
F_25 ( & V_40 -> V_10 , V_36 ) ;
V_48 = V_40 -> V_44 + V_40 -> V_41 ;
V_48 -> V_45 ++ ;
F_26 ( & V_40 -> V_10 , V_36 ) ;
return V_48 ;
}
static unsigned F_42 ( unsigned V_49 )
{
return ( V_49 + 1 ) % V_43 ;
}
static void F_43 ( struct V_39 * V_40 , struct V_50 * V_51 )
{
while ( ( V_40 -> V_42 != V_40 -> V_41 ) &&
! V_40 -> V_44 [ V_40 -> V_42 ] . V_45 ) {
F_44 ( & V_40 -> V_44 [ V_40 -> V_42 ] . V_46 , V_51 ) ;
V_40 -> V_42 = F_42 ( V_40 -> V_42 ) ;
}
if ( ( V_40 -> V_42 == V_40 -> V_41 ) && ! V_40 -> V_44 [ V_40 -> V_42 ] . V_45 )
F_44 ( & V_40 -> V_44 [ V_40 -> V_42 ] . V_46 , V_51 ) ;
}
void F_45 ( struct V_47 * V_48 , struct V_50 * V_51 )
{
unsigned long V_36 ;
F_25 ( & V_48 -> V_40 -> V_10 , V_36 ) ;
F_46 ( ! V_48 -> V_45 ) ;
-- V_48 -> V_45 ;
F_43 ( V_48 -> V_40 , V_51 ) ;
F_26 ( & V_48 -> V_40 -> V_10 , V_36 ) ;
}
int F_47 ( struct V_39 * V_40 , struct V_50 * V_52 )
{
int V_35 = 1 ;
unsigned long V_36 ;
unsigned V_53 ;
F_25 ( & V_40 -> V_10 , V_36 ) ;
if ( ( V_40 -> V_42 == V_40 -> V_41 ) &&
! V_40 -> V_44 [ V_40 -> V_41 ] . V_45 )
V_35 = 0 ;
else {
F_48 ( V_52 , & V_40 -> V_44 [ V_40 -> V_41 ] . V_46 ) ;
V_53 = F_42 ( V_40 -> V_41 ) ;
if ( ! V_40 -> V_44 [ V_53 ] . V_45 )
V_40 -> V_41 = V_53 ;
}
F_26 ( & V_40 -> V_10 , V_36 ) ;
return V_35 ;
}
static int T_5 F_49 ( void )
{
V_12 = F_50 ( V_15 , 0 ) ;
if ( ! V_12 )
return - V_54 ;
return 0 ;
}
static void T_6 F_51 ( void )
{
F_52 ( V_12 ) ;
V_12 = NULL ;
}
