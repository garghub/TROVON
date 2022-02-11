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
static T_1 F_11 ( struct V_3 * V_8 , struct V_15 * V_16 )
{
const unsigned long V_17 = 4294967291UL ;
T_3 V_18 = V_16 -> V_19 * V_17 ;
return ( T_1 ) ( V_18 & V_8 -> V_13 ) ;
}
static int F_12 ( struct V_15 * V_20 , struct V_15 * V_21 )
{
return ( V_20 -> V_22 == V_21 -> V_22 ) &&
( V_20 -> V_23 == V_21 -> V_23 ) &&
( V_20 -> V_19 == V_21 -> V_19 ) ;
}
static struct V_24 * F_13 ( struct V_7 * V_25 ,
struct V_15 * V_16 )
{
struct V_24 * V_26 ;
struct V_27 * V_28 ;
F_14 (cell, tmp, bucket, list)
if ( F_12 ( & V_26 -> V_16 , V_16 ) )
return V_26 ;
return NULL ;
}
int F_15 ( struct V_3 * V_8 , struct V_15 * V_16 ,
struct V_29 * V_30 , struct V_24 * * V_31 )
{
int V_32 = 1 ;
unsigned long V_33 ;
T_1 V_18 = F_11 ( V_8 , V_16 ) ;
struct V_24 * V_26 , * V_34 ;
F_16 ( V_18 > V_8 -> V_5 ) ;
F_17 ( & V_8 -> V_10 , V_33 ) ;
V_26 = F_13 ( V_8 -> V_14 + V_18 , V_16 ) ;
if ( V_26 ) {
F_18 ( & V_26 -> V_35 , V_30 ) ;
goto V_36;
}
F_19 ( & V_8 -> V_10 , V_33 ) ;
V_34 = F_20 ( V_8 -> V_11 , V_37 ) ;
F_17 ( & V_8 -> V_10 , V_33 ) ;
V_26 = F_13 ( V_8 -> V_14 + V_18 , V_16 ) ;
if ( V_26 ) {
F_21 ( V_34 , V_8 -> V_11 ) ;
F_18 ( & V_26 -> V_35 , V_30 ) ;
goto V_36;
}
V_26 = V_34 ;
V_26 -> V_8 = V_8 ;
memcpy ( & V_26 -> V_16 , V_16 , sizeof( V_26 -> V_16 ) ) ;
V_26 -> V_38 = V_30 ;
F_22 ( & V_26 -> V_35 ) ;
F_23 ( & V_26 -> V_39 , V_8 -> V_14 + V_18 ) ;
V_32 = 0 ;
V_36:
F_19 ( & V_8 -> V_10 , V_33 ) ;
* V_31 = V_26 ;
return V_32 ;
}
static void F_24 ( struct V_24 * V_26 , struct V_40 * V_41 )
{
struct V_3 * V_8 = V_26 -> V_8 ;
F_25 ( & V_26 -> V_39 ) ;
if ( V_41 ) {
F_18 ( V_41 , V_26 -> V_38 ) ;
F_26 ( V_41 , & V_26 -> V_35 ) ;
}
F_21 ( V_26 , V_8 -> V_11 ) ;
}
void F_27 ( struct V_24 * V_26 , struct V_40 * V_35 )
{
unsigned long V_33 ;
struct V_3 * V_8 = V_26 -> V_8 ;
F_17 ( & V_8 -> V_10 , V_33 ) ;
F_24 ( V_26 , V_35 ) ;
F_19 ( & V_8 -> V_10 , V_33 ) ;
}
static void F_28 ( struct V_24 * V_26 , struct V_29 * V_29 )
{
F_16 ( V_26 -> V_38 != V_29 ) ;
F_16 ( ! F_29 ( & V_26 -> V_35 ) ) ;
F_24 ( V_26 , NULL ) ;
}
void F_30 ( struct V_24 * V_26 , struct V_29 * V_29 )
{
unsigned long V_33 ;
struct V_3 * V_8 = V_26 -> V_8 ;
F_17 ( & V_8 -> V_10 , V_33 ) ;
F_28 ( V_26 , V_29 ) ;
F_19 ( & V_8 -> V_10 , V_33 ) ;
}
static void F_31 ( struct V_24 * V_26 , struct V_40 * V_41 )
{
struct V_3 * V_8 = V_26 -> V_8 ;
F_25 ( & V_26 -> V_39 ) ;
F_26 ( V_41 , & V_26 -> V_35 ) ;
F_21 ( V_26 , V_8 -> V_11 ) ;
}
void F_32 ( struct V_24 * V_26 , struct V_40 * V_41 )
{
unsigned long V_33 ;
struct V_3 * V_8 = V_26 -> V_8 ;
F_17 ( & V_8 -> V_10 , V_33 ) ;
F_31 ( V_26 , V_41 ) ;
F_19 ( & V_8 -> V_10 , V_33 ) ;
}
void F_33 ( struct V_24 * V_26 )
{
struct V_3 * V_8 = V_26 -> V_8 ;
struct V_40 V_35 ;
struct V_29 * V_29 ;
unsigned long V_33 ;
F_22 ( & V_35 ) ;
F_17 ( & V_8 -> V_10 , V_33 ) ;
F_24 ( V_26 , & V_35 ) ;
F_19 ( & V_8 -> V_10 , V_33 ) ;
while ( ( V_29 = F_34 ( & V_35 ) ) )
F_35 ( V_29 ) ;
}
struct V_42 * F_36 ( void )
{
int V_4 ;
struct V_42 * V_43 ;
V_43 = F_4 ( sizeof( * V_43 ) , V_9 ) ;
if ( ! V_43 )
return NULL ;
F_5 ( & V_43 -> V_10 ) ;
V_43 -> V_44 = 0 ;
V_43 -> V_45 = 0 ;
for ( V_4 = 0 ; V_4 < V_46 ; V_4 ++ ) {
V_43 -> V_47 [ V_4 ] . V_43 = V_43 ;
V_43 -> V_47 [ V_4 ] . V_48 = 0 ;
F_37 ( & V_43 -> V_47 [ V_4 ] . V_49 ) ;
}
return V_43 ;
}
void F_38 ( struct V_42 * V_43 )
{
F_7 ( V_43 ) ;
}
struct V_50 * F_39 ( struct V_42 * V_43 )
{
unsigned long V_33 ;
struct V_50 * V_51 ;
F_17 ( & V_43 -> V_10 , V_33 ) ;
V_51 = V_43 -> V_47 + V_43 -> V_44 ;
V_51 -> V_48 ++ ;
F_19 ( & V_43 -> V_10 , V_33 ) ;
return V_51 ;
}
static unsigned F_40 ( unsigned V_52 )
{
return ( V_52 + 1 ) % V_46 ;
}
static void F_41 ( struct V_42 * V_43 , struct V_53 * V_54 )
{
while ( ( V_43 -> V_45 != V_43 -> V_44 ) &&
! V_43 -> V_47 [ V_43 -> V_45 ] . V_48 ) {
F_42 ( & V_43 -> V_47 [ V_43 -> V_45 ] . V_49 , V_54 ) ;
V_43 -> V_45 = F_40 ( V_43 -> V_45 ) ;
}
if ( ( V_43 -> V_45 == V_43 -> V_44 ) && ! V_43 -> V_47 [ V_43 -> V_45 ] . V_48 )
F_42 ( & V_43 -> V_47 [ V_43 -> V_45 ] . V_49 , V_54 ) ;
}
void F_43 ( struct V_50 * V_51 , struct V_53 * V_54 )
{
unsigned long V_33 ;
F_17 ( & V_51 -> V_43 -> V_10 , V_33 ) ;
F_16 ( ! V_51 -> V_48 ) ;
-- V_51 -> V_48 ;
F_41 ( V_51 -> V_43 , V_54 ) ;
F_19 ( & V_51 -> V_43 -> V_10 , V_33 ) ;
}
int F_44 ( struct V_42 * V_43 , struct V_53 * V_55 )
{
int V_32 = 1 ;
unsigned long V_33 ;
unsigned V_56 ;
F_17 ( & V_43 -> V_10 , V_33 ) ;
if ( ( V_43 -> V_45 == V_43 -> V_44 ) &&
! V_43 -> V_47 [ V_43 -> V_44 ] . V_48 )
V_32 = 0 ;
else {
F_45 ( V_55 , & V_43 -> V_47 [ V_43 -> V_44 ] . V_49 ) ;
V_56 = F_40 ( V_43 -> V_44 ) ;
if ( ! V_43 -> V_47 [ V_56 ] . V_48 )
V_43 -> V_44 = V_56 ;
}
F_19 ( & V_43 -> V_10 , V_33 ) ;
return V_32 ;
}
static int T_4 F_46 ( void )
{
V_12 = F_47 ( V_24 , 0 ) ;
if ( ! V_12 )
return - V_57 ;
return 0 ;
}
static void T_5 F_48 ( void )
{
F_49 ( V_12 ) ;
V_12 = NULL ;
}
