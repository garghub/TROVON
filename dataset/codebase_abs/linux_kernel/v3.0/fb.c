void F_1 ( struct V_1 * V_2 )
{
}
static inline int F_2 ( unsigned long V_3 , unsigned long V_4 ,
unsigned long V_5 , unsigned long V_6 )
{
return ( V_3 >= V_5 && V_3 < V_5 + V_6 ) ||
( V_5 >= V_3 && V_5 < V_3 + V_4 ) ;
}
static inline int F_3 ( unsigned long V_3 , unsigned long V_4 ,
unsigned long V_5 , unsigned long V_6 )
{
return V_3 >= V_5 && V_3 + V_4 <= V_5 + V_6 ;
}
static int F_4 ( unsigned long V_7 , T_1 V_8 )
{
struct V_9 * V_10 ;
int V_11 ;
V_10 = & V_12 . V_13 . V_14 [ 0 ] ;
for ( V_11 = 0 ; V_11 < V_15 ; V_11 ++ , V_10 ++ ) {
if ( ! V_10 -> V_16 )
continue;
if ( F_2 ( V_7 , V_8 , V_10 -> V_16 , V_10 -> V_8 ) )
return 1 ;
}
return 0 ;
}
static int T_2 F_5 ( int V_17 , struct V_9 * V_10 )
{
const struct V_18 * V_19 ;
T_3 V_16 ;
V_19 = F_6 ( V_20 ,
struct V_18 , V_17 ) ;
if ( V_19 == NULL )
return - V_21 ;
V_16 = V_19 -> V_7 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> type = V_16 & ~ V_22 ;
V_10 -> V_16 = V_16 & V_22 ;
V_10 -> V_8 = F_7 ( V_19 -> V_8 ) ;
return 0 ;
}
static int F_8 ( struct V_9 * V_10 , int V_23 ,
unsigned long V_24 ,
unsigned long V_25 )
{
if ( V_10 -> type || ! V_10 -> V_16 )
return 0 ;
if ( F_2 ( V_10 -> V_16 , V_10 -> V_8 , V_24 , V_25 ) ) {
V_10 -> type = V_23 ;
return 0 ;
}
return - 1 ;
}
static int F_9 ( int V_17 , struct V_9 * V_10 ,
unsigned long V_26 , unsigned V_27 )
{
unsigned long V_16 = V_10 -> V_16 ;
T_1 V_8 = V_10 -> V_8 ;
if ( V_10 -> type > V_28 ) {
F_10 ( V_29
L_1 , V_17 ) ;
return - V_30 ;
}
if ( ! V_10 -> V_8 ) {
F_10 ( V_29 L_2 , V_17 ) ;
return - V_30 ;
}
if ( ! V_16 )
return 0 ;
if ( F_4 ( V_16 , V_8 ) ||
! F_3 ( V_16 , V_8 , V_26 , V_27 ) ) {
F_10 ( V_29 L_3
L_4 , V_17 ) ;
return - V_30 ;
}
return 0 ;
}
static int F_11 ( unsigned long V_31 , unsigned long V_8 )
{
return F_12 ( V_31 , V_8 ) ;
}
static int F_13 ( unsigned long V_31 , unsigned long V_8 )
{
if ( F_14 ( V_31 , V_8 ) )
return - V_32 ;
if ( F_15 ( V_31 , V_8 ) )
return - V_33 ;
return 0 ;
}
void T_2 F_16 ( void )
{
unsigned long V_34 = 0 ;
int V_11 ;
if ( V_35 )
return;
for ( V_11 = 0 ; ; V_11 ++ ) {
struct V_9 V_10 ;
if ( F_5 ( V_11 , & V_10 ) < 0 )
break;
if ( V_11 == V_15 ) {
F_17 ( L_5 ) ;
V_35 = 1 ;
return;
}
if ( V_10 . type != V_36 )
continue;
if ( V_10 . V_16 && ! F_11 ( V_10 . V_16 , V_10 . V_8 ) )
continue;
if ( V_10 . V_8 == 0 ) {
F_17 ( L_2 , V_11 ) ;
V_35 = 1 ;
return;
}
if ( V_10 . V_16 ) {
if ( F_13 ( V_10 . V_16 , V_10 . V_8 ) ) {
F_17 ( L_6 ,
V_11 ) ;
V_35 = 1 ;
return;
}
V_34 += V_10 . V_8 ;
}
if ( V_12 . V_13 . V_14 [ V_11 ] . V_8 ) {
F_17 ( L_7 , V_11 ) ;
V_35 = 1 ;
return;
}
V_12 . V_13 . V_14 [ V_11 ] = V_10 ;
V_37 ++ ;
}
V_12 . V_13 . V_38 = V_11 ;
if ( V_34 )
F_18 ( L_8 ,
V_34 ) ;
}
unsigned long T_2 F_19 ( unsigned long V_39 ,
unsigned long V_40 ,
unsigned long V_41 ,
unsigned long V_42 ,
unsigned long V_27 )
{
struct V_9 V_10 ;
unsigned long V_43 ;
unsigned long V_34 ;
int V_11 ;
if ( V_35 )
return 0 ;
V_34 = 0 ;
V_43 = V_42 + V_27 ;
for ( V_11 = 0 ; ; V_11 ++ ) {
if ( F_5 ( V_11 , & V_10 ) < 0 )
break;
if ( V_11 == V_15 ) {
F_10 ( V_29
L_5 ) ;
V_35 = 1 ;
return 0 ;
}
if ( F_8 ( & V_10 , V_44 ,
V_39 , V_41 ) < 0 ||
( V_10 . type != V_44 ) )
continue;
F_20 ( V_12 . V_13 . V_14 [ V_11 ] . V_8 ) ;
if ( F_9 ( V_11 , & V_10 , V_42 , V_27 ) < 0 ) {
V_35 = 1 ;
return 0 ;
}
if ( ! V_10 . V_16 ) {
if ( ( V_27 & V_22 ) < V_10 . V_8 ) {
F_10 ( L_9 ,
V_11 ) ;
V_35 = 1 ;
return 0 ;
}
V_27 = ( V_27 - V_10 . V_8 ) & V_22 ;
V_10 . V_16 = V_42 + V_27 ;
}
if ( V_43 - V_10 . V_16 > V_34 )
V_34 = V_43 - V_10 . V_16 ;
V_27 = V_43 - V_34 - V_42 ;
V_10 . V_45 = ( void * ) ( V_40 + V_10 . V_16 - V_39 ) ;
V_12 . V_13 . V_14 [ V_11 ] = V_10 ;
V_37 ++ ;
}
V_12 . V_13 . V_38 = V_11 ;
if ( V_34 )
F_18 ( L_10 ,
V_34 ) ;
return V_34 ;
}
void F_21 ( void * V_2 )
{
V_12 . V_46 = V_2 ;
}
static int T_2 F_22 ( void )
{
const struct V_47 * V_19 ;
if ( V_35 )
return 0 ;
if ( V_37 != V_12 . V_13 . V_38 ) {
F_10 ( V_29 L_11 ) ;
return 0 ;
}
V_19 = F_23 ( V_48 , struct V_47 ) ;
if ( V_19 == NULL ) {
if ( V_37 )
F_10 ( V_29 L_12 ) ;
return 0 ;
}
V_12 . V_49 = * V_19 ;
return F_24 ( & V_50 ) ;
}
void F_1 ( struct V_1 * V_2 )
{
V_12 = * V_2 ;
}
static int T_2 F_22 ( void )
{
return F_24 ( & V_50 ) ;
}
void F_16 ( void )
{
}
unsigned long T_2 F_19 ( unsigned long V_39 ,
unsigned long V_40 ,
unsigned long V_41 ,
unsigned long V_26 ,
unsigned long V_27 )
{
return 0 ;
}
void F_1 ( struct V_1 * V_2 )
{
}
void F_16 ( void )
{
}
unsigned long T_2 F_19 ( unsigned long V_39 ,
unsigned long V_40 ,
unsigned long V_41 ,
unsigned long V_26 ,
unsigned long V_27 )
{
return 0 ;
}
