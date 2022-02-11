unsigned long F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
return 0 ;
return F_3 ( V_2 -> V_3 ) ? V_2 -> V_3 : 0 ;
}
unsigned long * F_4 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
return NULL ;
return V_2 -> V_4 ? & V_2 -> V_4 -> V_3 : V_2 -> V_5 + 1 ;
}
static void F_5 ( struct V_1 * V_2 )
{
static bool V_6 = false ;
bool V_7 , V_8 = false ;
unsigned long V_9 , * V_10 ;
struct V_11 V_11 = { 0 } ;
unsigned long V_12 = 0 ;
if ( V_6 )
return;
V_6 = true ;
F_6 ( L_1 ,
V_2 -> V_11 . type , V_2 -> V_11 . V_13 ,
V_2 -> V_14 , V_2 -> V_15 ) ;
for ( V_10 = F_7 ( V_2 -> V_16 , sizeof( long ) ) ; V_10 ;
V_10 = F_7 ( V_11 . V_13 , sizeof( long ) ) ) {
if ( F_8 ( V_10 , V_2 -> V_17 , & V_11 , & V_12 ) )
break;
for (; V_10 < V_11 . V_18 ; V_10 ++ ) {
V_9 = F_9 ( * V_10 ) ;
V_7 = V_8 ;
V_8 = V_9 == 0 ;
if ( V_8 ) {
if ( ! V_7 )
F_6 ( L_2 ,
V_10 , V_19 / 4 , 0 ) ;
continue;
}
F_6 ( L_3 ,
V_10 , V_19 / 4 , V_9 , ( void * ) V_9 ) ;
}
}
}
static T_1 F_10 ( struct V_20 * V_4 )
{
if ( F_11 ( V_21 ) && ! F_12 ( V_4 ) )
return sizeof( * V_4 ) - 2 * sizeof( long ) ;
return sizeof( * V_4 ) ;
}
static bool F_13 ( unsigned long V_3 )
{
char * V_22 = ( char * ) V_3 ;
if ( V_22 >= V_23 && V_22 < V_24 )
return true ;
if ( V_22 >= V_25 && V_22 < V_26 )
return true ;
return false ;
}
static inline unsigned long * F_14 ( struct V_1 * V_2 )
{
return ( unsigned long * ) F_15 ( V_2 -> V_17 ) - 2 ;
}
static bool F_16 ( struct V_1 * V_2 )
{
return V_2 -> V_5 == F_14 ( V_2 ) ;
}
static inline unsigned long * F_17 ( struct V_1 * V_2 )
{
return F_14 ( V_2 ) - V_27 ;
}
static bool F_18 ( struct V_1 * V_2 )
{
unsigned long * V_28 = F_14 ( V_2 ) ;
unsigned long * V_29 = F_17 ( V_2 ) ;
return ( V_2 -> V_5 == V_29 && * ( V_29 + 1 ) == * ( V_28 + 1 ) ) ;
}
static bool F_19 ( struct V_1 * V_2 )
{
unsigned long * V_28 = F_14 ( V_2 ) ;
unsigned long * V_30 = V_28 - 3 ;
return ( V_2 -> V_5 == V_30 &&
* V_2 -> V_5 == * ( V_2 -> V_5 + 2 ) &&
* ( V_2 -> V_5 + 1 ) == * ( V_2 -> V_5 + 4 ) ) ;
}
static bool F_20 ( struct V_1 * V_2 )
{
return F_16 ( V_2 ) || F_18 ( V_2 ) ||
F_19 ( V_2 ) ;
}
static struct V_20 * F_21 ( unsigned long * V_5 )
{
unsigned long V_4 = ( unsigned long ) V_5 ;
if ( ! ( V_4 & 0x1 ) )
return NULL ;
return (struct V_20 * ) ( V_4 & ~ 0x1 ) ;
}
static struct V_20 * F_21 ( unsigned long * V_5 )
{
unsigned long V_4 = ( unsigned long ) V_5 ;
if ( V_4 & 0x80000000 )
return NULL ;
return (struct V_20 * ) ( V_4 | 0x80000000 ) ;
}
static bool F_22 ( struct V_1 * V_2 ,
unsigned long * V_31 )
{
struct V_11 * V_32 = & V_2 -> V_11 ;
enum V_33 V_34 = V_32 -> type ;
struct V_20 * V_4 ;
unsigned long * V_35 , * V_36 , * V_37 , V_22 ;
T_1 V_38 ;
if ( V_2 -> V_4 )
V_36 = ( void * ) V_2 -> V_4 + F_10 ( V_2 -> V_4 ) ;
else
V_36 = ( void * ) V_2 -> V_5 + V_39 ;
V_4 = F_21 ( V_31 ) ;
if ( V_4 ) {
V_35 = ( unsigned long * ) V_4 ;
V_38 = V_40 ;
V_2 -> V_41 = true ;
} else {
V_35 = V_31 ;
V_38 = V_39 ;
}
while ( ! F_23 ( V_32 , V_35 , V_38 ) )
if ( F_8 ( V_32 -> V_13 , V_2 -> V_17 , V_32 ,
& V_2 -> V_14 ) )
return false ;
if ( V_2 -> V_16 && V_2 -> V_11 . type == V_34 &&
V_35 < V_36 )
return false ;
if ( F_11 ( V_21 ) && V_4 && F_12 ( V_4 ) &&
! F_23 ( V_32 , V_35 , V_38 + 2 * sizeof( long ) ) )
return false ;
if ( V_4 ) {
V_2 -> V_4 = V_4 ;
V_2 -> V_5 = NULL ;
} else {
V_2 -> V_5 = V_31 ;
V_2 -> V_4 = NULL ;
}
if ( V_2 -> V_4 && F_12 ( V_2 -> V_4 ) )
V_2 -> V_3 = 0 ;
else {
V_37 = F_4 ( V_2 ) ;
V_22 = F_24 ( V_2 -> V_17 , * V_37 ) ;
V_2 -> V_3 = F_25 ( V_2 -> V_17 , & V_2 -> V_15 ,
V_22 , V_37 ) ;
}
if ( ! V_2 -> V_16 )
V_2 -> V_16 = V_35 ;
return true ;
}
bool F_26 ( struct V_1 * V_2 )
{
struct V_20 * V_4 ;
unsigned long * V_31 ;
if ( F_2 ( V_2 ) )
return false ;
if ( V_2 -> V_4 && F_12 ( V_2 -> V_4 ) )
goto V_42;
if ( F_20 ( V_2 ) ) {
V_4 = F_15 ( V_2 -> V_17 ) ;
if ( ! F_12 ( V_4 ) )
goto V_42;
V_2 -> V_4 = V_4 ;
V_2 -> V_5 = NULL ;
V_2 -> V_3 = 0 ;
return true ;
}
if ( V_2 -> V_4 )
V_31 = ( unsigned long * ) V_2 -> V_4 -> V_5 ;
else
V_31 = ( unsigned long * ) F_24 ( V_2 -> V_17 , * V_2 -> V_5 ) ;
if ( ! F_22 ( V_2 , V_31 ) )
goto V_43;
return true ;
V_43:
V_2 -> error = true ;
if ( V_2 -> V_17 != V_44 )
goto V_42;
if ( V_2 -> V_41 && F_13 ( V_2 -> V_3 ) )
goto V_42;
if ( V_2 -> V_4 &&
V_2 -> V_4 -> V_10 >= ( unsigned long ) F_17 ( V_2 ) &&
V_2 -> V_4 -> V_10 < ( unsigned long ) F_15 ( V_2 -> V_17 ) )
goto V_42;
if ( F_11 ( V_21 ) )
goto V_42;
if ( V_2 -> V_4 ) {
F_27 ( V_45
L_4 ,
V_2 -> V_4 , V_2 -> V_17 -> V_46 ,
V_2 -> V_17 -> V_47 , V_31 ) ;
F_5 ( V_2 ) ;
} else {
F_27 ( V_45
L_5 ,
V_2 -> V_5 , V_2 -> V_17 -> V_46 ,
V_2 -> V_17 -> V_47 , V_31 ) ;
F_5 ( V_2 ) ;
}
V_42:
V_2 -> V_11 . type = V_48 ;
return false ;
}
void F_28 ( struct V_1 * V_2 , struct V_49 * V_17 ,
struct V_20 * V_4 , unsigned long * V_50 )
{
unsigned long * V_5 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_17 = V_17 ;
V_2 -> V_41 = ( V_4 ) ;
if ( V_4 && F_12 ( V_4 ) ) {
V_2 -> V_11 . type = V_48 ;
return;
}
V_5 = F_29 ( V_17 , V_4 ) ;
F_8 ( V_5 , V_2 -> V_17 , & V_2 -> V_11 ,
& V_2 -> V_14 ) ;
F_22 ( V_2 , V_5 ) ;
while ( ! F_2 ( V_2 ) &&
( ! F_23 ( & V_2 -> V_11 , V_50 , sizeof( long ) ) ||
V_2 -> V_5 < V_50 ) )
F_26 ( V_2 ) ;
}
