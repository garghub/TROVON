static void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( & V_2 -> V_4 , V_3 ) ;
if ( ! V_2 -> V_5 ) {
F_3 ( V_2 -> V_6 ) ;
V_2 -> V_5 = true ;
}
F_4 ( & V_2 -> V_4 , V_3 ) ;
}
static int F_5 ( void * V_7 , void * V_8 )
{
struct V_1 * V_2 = V_7 ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_6 ( struct V_9 * V_10 ,
unsigned V_11 , unsigned V_12 ,
unsigned V_13 , T_1 V_3 ,
void * V_14 )
{
if ( V_12 != 0 || V_13 != 1 )
return - V_15 ;
if ( ! ( V_10 -> V_16 [ V_11 ] . V_3 & V_17 ) )
return - V_15 ;
if ( V_3 & V_18 ) {
T_2 V_19 = * ( T_2 * ) V_14 ;
if ( V_19 >= 0 )
return F_7 ( ( void * ) & V_10 -> V_16 [ V_11 ] ,
F_5 ,
NULL , NULL ,
& V_10 -> V_16 [ V_11 ] . V_20 , V_19 ) ;
F_8 ( & V_10 -> V_16 [ V_11 ] . V_20 ) ;
return 0 ;
}
if ( V_3 & V_21 ) {
F_1 ( & V_10 -> V_16 [ V_11 ] ) ;
} else if ( V_3 & V_22 ) {
T_3 V_20 = * ( T_3 * ) V_14 ;
if ( V_20 )
F_1 ( & V_10 -> V_16 [ V_11 ] ) ;
}
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( & V_2 -> V_4 , V_3 ) ;
if ( V_2 -> V_5 ) {
F_10 ( V_2 -> V_6 ) ;
V_2 -> V_5 = false ;
}
F_4 ( & V_2 -> V_4 , V_3 ) ;
}
static int F_11 ( void * V_7 , void * V_8 )
{
struct V_1 * V_2 = V_7 ;
F_9 ( V_2 ) ;
return 0 ;
}
static int F_12 ( struct V_9 * V_10 ,
unsigned V_11 , unsigned V_12 ,
unsigned V_13 , T_1 V_3 ,
void * V_14 )
{
if ( V_12 != 0 || V_13 != 1 )
return - V_15 ;
if ( ! ( V_10 -> V_16 [ V_11 ] . V_3 & V_17 ) )
return - V_15 ;
if ( V_3 & V_18 ) {
T_2 V_19 = * ( T_2 * ) V_14 ;
if ( V_19 >= 0 )
return F_7 ( ( void * ) & V_10 -> V_16 [ V_11 ] ,
F_11 ,
NULL , NULL ,
& V_10 -> V_16 [ V_11 ] . V_23 ,
V_19 ) ;
F_8 ( & V_10 -> V_16 [ V_11 ] . V_23 ) ;
return 0 ;
}
if ( V_3 & V_21 ) {
F_9 ( & V_10 -> V_16 [ V_11 ] ) ;
} else if ( V_3 & V_22 ) {
T_3 V_23 = * ( T_3 * ) V_14 ;
if ( V_23 )
F_9 ( & V_10 -> V_16 [ V_11 ] ) ;
}
return 0 ;
}
static T_4 F_13 ( int V_24 , void * V_25 )
{
struct V_1 * V_2 = V_25 ;
unsigned long V_3 ;
int V_26 = V_27 ;
F_2 ( & V_2 -> V_4 , V_3 ) ;
if ( ! V_2 -> V_5 ) {
V_26 = V_28 ;
F_3 ( V_2 -> V_6 ) ;
V_2 -> V_5 = true ;
}
F_4 ( & V_2 -> V_4 , V_3 ) ;
if ( V_26 == V_28 )
F_14 ( V_2 -> V_29 , 1 ) ;
return V_26 ;
}
static T_4 F_15 ( int V_24 , void * V_25 )
{
struct V_1 * V_2 = V_25 ;
F_14 ( V_2 -> V_29 , 1 ) ;
return V_28 ;
}
static int F_16 ( struct V_9 * V_10 , int V_11 ,
int V_19 , T_5 V_30 )
{
struct V_1 * V_24 = & V_10 -> V_16 [ V_11 ] ;
struct V_31 * V_29 ;
int V_26 ;
if ( V_24 -> V_29 ) {
F_17 ( V_24 -> V_6 , V_24 ) ;
F_18 ( V_24 -> V_32 ) ;
F_19 ( V_24 -> V_29 ) ;
V_24 -> V_29 = NULL ;
}
if ( V_19 < 0 )
return 0 ;
V_24 -> V_32 = F_20 ( V_33 , L_1 ,
V_24 -> V_6 , V_10 -> V_32 ) ;
if ( ! V_24 -> V_32 )
return - V_34 ;
V_29 = F_21 ( V_19 ) ;
if ( F_22 ( V_29 ) ) {
F_18 ( V_24 -> V_32 ) ;
return F_23 ( V_29 ) ;
}
V_24 -> V_29 = V_29 ;
F_24 ( V_24 -> V_6 , V_35 ) ;
V_26 = F_25 ( V_24 -> V_6 , V_30 , 0 , V_24 -> V_32 , V_24 ) ;
if ( V_26 ) {
F_18 ( V_24 -> V_32 ) ;
F_19 ( V_29 ) ;
V_24 -> V_29 = NULL ;
return V_26 ;
}
if ( ! V_24 -> V_5 )
F_10 ( V_24 -> V_6 ) ;
return 0 ;
}
static int F_26 ( struct V_9 * V_10 ,
unsigned V_11 , unsigned V_12 ,
unsigned V_13 , T_1 V_3 ,
void * V_14 )
{
struct V_1 * V_24 = & V_10 -> V_16 [ V_11 ] ;
T_5 V_30 ;
if ( V_10 -> V_16 [ V_11 ] . V_3 & V_36 )
V_30 = F_13 ;
else
V_30 = F_15 ;
if ( ! V_13 && ( V_3 & V_21 ) )
return F_16 ( V_10 , V_11 , - 1 , V_30 ) ;
if ( V_12 != 0 || V_13 != 1 )
return - V_15 ;
if ( V_3 & V_18 ) {
T_2 V_19 = * ( T_2 * ) V_14 ;
return F_16 ( V_10 , V_11 , V_19 , V_30 ) ;
}
if ( V_3 & V_21 ) {
V_30 ( V_24 -> V_6 , V_24 ) ;
} else if ( V_3 & V_22 ) {
T_3 V_29 = * ( T_3 * ) V_14 ;
if ( V_29 )
V_30 ( V_24 -> V_6 , V_24 ) ;
}
return 0 ;
}
int F_27 ( struct V_9 * V_10 ,
T_1 V_3 , unsigned V_11 , unsigned V_12 ,
unsigned V_13 , void * V_14 )
{
int (* F_28)( struct V_9 * V_10 , unsigned V_11 ,
unsigned V_12 , unsigned V_13 , T_1 V_3 ,
void * V_14 ) = NULL ;
switch ( V_3 & V_37 ) {
case V_38 :
F_28 = F_6 ;
break;
case V_39 :
F_28 = F_12 ;
break;
case V_40 :
F_28 = F_26 ;
break;
}
if ( ! F_28 )
return - V_41 ;
return F_28 ( V_10 , V_11 , V_12 , V_13 , V_3 , V_14 ) ;
}
int F_29 ( struct V_9 * V_10 )
{
int V_42 = 0 , V_43 ;
while ( V_10 -> V_44 ( V_10 , V_42 ) >= 0 )
V_42 ++ ;
V_10 -> V_16 = F_30 ( V_42 , sizeof( struct V_1 ) , V_33 ) ;
if ( ! V_10 -> V_16 )
return - V_34 ;
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ ) {
int V_6 = V_10 -> V_44 ( V_10 , V_43 ) ;
if ( V_6 < 0 )
goto V_45;
F_31 ( & V_10 -> V_16 [ V_43 ] . V_4 ) ;
V_10 -> V_16 [ V_43 ] . V_3 = V_46 ;
if ( F_32 ( V_6 ) & V_47 )
V_10 -> V_16 [ V_43 ] . V_3 |= V_17
| V_36 ;
V_10 -> V_16 [ V_43 ] . V_13 = 1 ;
V_10 -> V_16 [ V_43 ] . V_6 = V_6 ;
V_10 -> V_16 [ V_43 ] . V_5 = false ;
}
V_10 -> V_48 = V_42 ;
return 0 ;
V_45:
F_18 ( V_10 -> V_16 ) ;
return - V_15 ;
}
void F_33 ( struct V_9 * V_10 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_10 -> V_48 ; V_43 ++ )
F_16 ( V_10 , V_43 , - 1 , NULL ) ;
V_10 -> V_48 = 0 ;
F_18 ( V_10 -> V_16 ) ;
}
