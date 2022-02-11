static void F_1 ( struct V_1 * V_2 )
{
static bool V_3 = false ;
bool V_4 , V_5 = false ;
unsigned long V_6 , * V_7 ;
struct V_8 V_8 = { 0 } ;
unsigned long V_9 = 0 ;
if ( V_3 )
return;
V_3 = true ;
F_2 ( L_1 ,
V_2 -> V_8 . type , V_2 -> V_8 . V_10 ,
V_2 -> V_11 , V_2 -> V_12 ) ;
for ( V_7 = V_2 -> V_13 ; V_7 ; V_7 = F_3 ( V_8 . V_10 , sizeof( long ) ) ) {
if ( F_4 ( V_7 , V_2 -> V_14 , & V_8 , & V_9 ) )
break;
for (; V_7 < V_8 . V_15 ; V_7 ++ ) {
V_6 = F_5 ( * V_7 ) ;
V_4 = V_5 ;
V_5 = V_6 == 0 ;
if ( V_5 ) {
if ( ! V_4 )
F_2 ( L_2 ,
V_7 , V_16 / 4 , 0 ) ;
continue;
}
F_2 ( L_3 ,
V_7 , V_16 / 4 , V_6 , ( void * ) V_6 ) ;
}
}
}
unsigned long F_6 ( struct V_1 * V_2 )
{
if ( F_7 ( V_2 ) )
return 0 ;
return F_8 ( V_2 -> V_17 ) ? V_2 -> V_17 : 0 ;
}
static T_1 F_9 ( struct V_18 * V_19 )
{
if ( F_10 ( V_20 ) && ! F_11 ( V_19 ) )
return sizeof( * V_19 ) - 2 * sizeof( long ) ;
return sizeof( * V_19 ) ;
}
static bool F_12 ( unsigned long V_17 )
{
char * V_21 = ( char * ) V_17 ;
if ( V_21 >= V_22 && V_21 < V_23 )
return true ;
#if F_13 ( V_24 ) || F_13 ( V_25 )
if ( V_21 >= V_26 && V_21 < V_27 )
return true ;
#endif
return false ;
}
static inline unsigned long * F_14 ( struct V_1 * V_2 )
{
return ( unsigned long * ) F_15 ( V_2 -> V_14 ) - 2 ;
}
static bool F_16 ( struct V_1 * V_2 )
{
return V_2 -> V_28 == F_14 ( V_2 ) ;
}
static inline unsigned long * F_17 ( struct V_1 * V_2 )
{
return F_14 ( V_2 ) - V_29 ;
}
static bool F_18 ( struct V_1 * V_2 )
{
unsigned long * V_30 = F_14 ( V_2 ) ;
unsigned long * V_31 = F_17 ( V_2 ) ;
return ( V_2 -> V_28 == V_31 && * ( V_31 + 1 ) == * ( V_30 + 1 ) ) ;
}
static bool F_19 ( struct V_1 * V_2 )
{
unsigned long * V_30 = F_14 ( V_2 ) ;
unsigned long * V_32 = V_30 - 3 ;
return ( V_2 -> V_28 == V_32 &&
* V_2 -> V_28 == * ( V_2 -> V_28 + 2 ) &&
* ( V_2 -> V_28 + 1 ) == * ( V_2 -> V_28 + 4 ) ) ;
}
static bool F_20 ( struct V_1 * V_2 )
{
return F_16 ( V_2 ) || F_18 ( V_2 ) ||
F_19 ( V_2 ) ;
}
static struct V_18 * F_21 ( unsigned long * V_28 )
{
unsigned long V_19 = ( unsigned long ) V_28 ;
if ( ! ( V_19 & 0x1 ) )
return NULL ;
return (struct V_18 * ) ( V_19 & ~ 0x1 ) ;
}
static bool F_22 ( struct V_1 * V_2 ,
unsigned long * V_33 )
{
struct V_8 * V_34 = & V_2 -> V_8 ;
enum V_35 V_36 = V_34 -> type ;
struct V_18 * V_19 ;
unsigned long * V_37 , * V_38 , * V_39 , V_21 ;
T_1 V_40 ;
if ( V_2 -> V_19 )
V_38 = ( void * ) V_2 -> V_19 + F_9 ( V_2 -> V_19 ) ;
else
V_38 = ( void * ) V_2 -> V_28 + V_41 ;
V_19 = F_21 ( V_33 ) ;
if ( V_19 ) {
V_37 = ( unsigned long * ) V_19 ;
V_40 = F_9 ( V_19 ) ;
V_2 -> V_42 = true ;
} else {
V_37 = V_33 ;
V_40 = V_41 ;
}
while ( ! F_23 ( V_34 , V_37 , V_40 ) )
if ( F_4 ( V_34 -> V_10 , V_2 -> V_14 , V_34 ,
& V_2 -> V_11 ) )
return false ;
if ( V_2 -> V_13 && V_2 -> V_8 . type == V_36 &&
V_37 < V_38 )
return false ;
if ( V_19 ) {
V_2 -> V_19 = V_19 ;
V_2 -> V_28 = NULL ;
} else {
V_2 -> V_28 = V_33 ;
V_2 -> V_19 = NULL ;
}
if ( V_2 -> V_19 && F_11 ( V_2 -> V_19 ) )
V_2 -> V_17 = 0 ;
else {
V_39 = F_24 ( V_2 ) ;
V_21 = F_25 ( V_2 -> V_14 , * V_39 ) ;
V_2 -> V_17 = F_26 ( V_2 -> V_14 , & V_2 -> V_12 ,
V_21 , V_39 ) ;
}
if ( ! V_2 -> V_13 )
V_2 -> V_13 = V_37 ;
return true ;
}
bool F_27 ( struct V_1 * V_2 )
{
struct V_18 * V_19 ;
unsigned long * V_33 ;
if ( F_7 ( V_2 ) )
return false ;
if ( V_2 -> V_19 && F_11 ( V_2 -> V_19 ) )
goto V_43;
if ( F_20 ( V_2 ) ) {
V_19 = F_15 ( V_2 -> V_14 ) ;
if ( ! F_11 ( V_19 ) )
goto V_43;
V_2 -> V_19 = V_19 ;
V_2 -> V_28 = NULL ;
V_2 -> V_17 = 0 ;
return true ;
}
if ( V_2 -> V_19 )
V_33 = ( unsigned long * ) V_2 -> V_19 -> V_28 ;
else
V_33 = ( unsigned long * ) F_25 ( V_2 -> V_14 , * V_2 -> V_28 ) ;
if ( ! F_22 ( V_2 , V_33 ) )
goto V_44;
return true ;
V_44:
V_2 -> error = true ;
if ( V_2 -> V_14 != V_45 )
goto V_43;
if ( V_2 -> V_42 && F_12 ( V_2 -> V_17 ) )
goto V_43;
if ( V_2 -> V_19 &&
V_2 -> V_19 -> V_7 >= ( unsigned long ) F_17 ( V_2 ) &&
V_2 -> V_19 -> V_7 < ( unsigned long ) F_15 ( V_2 -> V_14 ) )
goto V_43;
if ( V_2 -> V_19 ) {
F_28 ( V_46
L_4 ,
V_2 -> V_19 , V_2 -> V_14 -> V_47 ,
V_2 -> V_14 -> V_48 , V_33 ) ;
F_1 ( V_2 ) ;
} else {
F_28 ( V_46
L_5 ,
V_2 -> V_28 , V_2 -> V_14 -> V_47 ,
V_2 -> V_14 -> V_48 , V_33 ) ;
F_1 ( V_2 ) ;
}
V_43:
V_2 -> V_8 . type = V_49 ;
return false ;
}
void F_29 ( struct V_1 * V_2 , struct V_50 * V_14 ,
struct V_18 * V_19 , unsigned long * V_51 )
{
unsigned long * V_28 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_14 = V_14 ;
V_2 -> V_42 = ( V_19 ) ;
if ( V_19 && F_11 ( V_19 ) ) {
V_2 -> V_8 . type = V_49 ;
return;
}
V_28 = F_30 ( V_14 , V_19 ) ;
F_4 ( V_28 , V_2 -> V_14 , & V_2 -> V_8 ,
& V_2 -> V_11 ) ;
F_22 ( V_2 , V_28 ) ;
while ( ! F_7 ( V_2 ) &&
( ! F_23 ( & V_2 -> V_8 , V_51 , sizeof( long ) ) ||
V_2 -> V_28 < V_51 ) )
F_27 ( V_2 ) ;
}
