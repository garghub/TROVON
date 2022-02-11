static void F_1 ( struct V_1 * V_2 , unsigned long * V_3 )
{
static bool V_4 = false ;
bool V_5 , V_6 = false ;
unsigned long V_7 ;
if ( V_4 )
return;
V_4 = true ;
F_2 ( L_1 ,
V_2 -> V_8 . type , V_2 -> V_8 . V_9 ,
V_2 -> V_10 , V_2 -> V_11 ) ;
for ( V_3 = V_2 -> V_12 ; V_3 < V_2 -> V_8 . V_13 ; V_3 ++ ) {
V_7 = F_3 ( * V_3 ) ;
V_5 = V_6 ;
V_6 = V_7 == 0 ;
if ( V_6 ) {
if ( ! V_5 )
F_2 ( L_2 , V_3 , 0 ) ;
continue;
}
F_2 ( L_3 , V_3 , V_7 , ( void * ) V_7 ) ;
}
}
unsigned long F_4 ( struct V_1 * V_2 )
{
unsigned long V_14 ;
unsigned long * V_15 = F_5 ( V_2 ) ;
if ( F_6 ( V_2 ) )
return 0 ;
if ( V_2 -> V_16 && F_7 ( V_2 -> V_16 ) )
return 0 ;
V_14 = F_8 ( V_2 -> V_17 , * V_15 ) ;
V_14 = F_9 ( V_2 -> V_17 , & V_2 -> V_11 , V_14 ,
V_15 ) ;
return F_10 ( V_14 ) ? V_14 : 0 ;
}
static T_1 F_11 ( struct V_18 * V_16 )
{
if ( F_12 ( V_19 ) && ! F_7 ( V_16 ) )
return sizeof( * V_16 ) - 2 * sizeof( long ) ;
return sizeof( * V_16 ) ;
}
static bool F_13 ( struct V_1 * V_2 )
{
unsigned long V_20 = ( unsigned long ) V_2 -> V_20 ;
unsigned long V_16 = ( unsigned long ) F_14 ( V_2 -> V_17 ) ;
return V_20 == V_16 - V_21 ||
V_20 == V_16 - V_21 - sizeof( long ) ;
}
static struct V_18 * F_15 ( unsigned long * V_20 )
{
unsigned long V_16 = ( unsigned long ) V_20 ;
if ( ! ( V_16 & 0x1 ) )
return NULL ;
return (struct V_18 * ) ( V_16 & ~ 0x1 ) ;
}
static bool F_16 ( struct V_1 * V_2 , void * V_14 ,
T_1 V_22 )
{
struct V_8 * V_23 = & V_2 -> V_8 ;
enum V_24 V_25 = V_23 -> type ;
while ( ! F_17 ( V_23 , V_14 , V_22 ) )
if ( F_18 ( V_23 -> V_9 , V_2 -> V_17 , V_23 ,
& V_2 -> V_10 ) )
return false ;
if ( ! V_2 -> V_12 || V_23 -> type != V_25 )
V_2 -> V_12 = V_14 ;
return true ;
}
bool F_19 ( struct V_1 * V_2 )
{
struct V_18 * V_16 ;
unsigned long * V_26 , * V_27 ;
T_1 V_28 ;
enum V_24 V_29 = V_2 -> V_8 . type ;
if ( F_6 ( V_2 ) )
return false ;
if ( V_2 -> V_16 && F_7 ( V_2 -> V_16 ) )
goto V_30;
if ( F_13 ( V_2 ) ) {
V_16 = F_14 ( V_2 -> V_17 ) ;
if ( ! F_7 ( V_16 ) )
goto V_30;
V_2 -> V_16 = V_16 ;
V_2 -> V_20 = NULL ;
return true ;
}
if ( V_2 -> V_16 )
V_26 = ( unsigned long * ) V_2 -> V_16 -> V_20 ;
else
V_26 = ( unsigned long * ) F_8 ( V_2 -> V_17 , * V_2 -> V_20 ) ;
V_16 = F_15 ( V_26 ) ;
if ( V_16 ) {
V_27 = ( unsigned long * ) V_16 ;
V_28 = sizeof( * V_16 ) ;
} else {
V_27 = V_26 ;
V_28 = V_21 ;
}
if ( ! F_16 ( V_2 , V_27 , V_28 ) ) {
if ( V_2 -> V_16 )
goto V_30;
goto V_31;
}
if ( V_2 -> V_8 . type == V_29 ) {
if ( V_2 -> V_16 && ( void * ) V_27 < ( void * ) V_2 -> V_16 + F_11 ( V_2 -> V_16 ) )
goto V_31;
if ( V_2 -> V_20 && ( void * ) V_27 < ( void * ) V_2 -> V_20 + V_21 )
goto V_31;
}
if ( V_16 ) {
V_2 -> V_16 = V_16 ;
V_2 -> V_20 = NULL ;
} else {
V_2 -> V_20 = V_26 ;
V_2 -> V_16 = NULL ;
}
return true ;
V_31:
if ( V_2 -> V_17 != V_32 )
goto V_30;
if ( V_2 -> V_16 ) {
F_20 ( V_33
L_4 ,
V_2 -> V_16 , V_2 -> V_17 -> V_34 ,
V_2 -> V_17 -> V_35 , V_27 ) ;
F_1 ( V_2 , ( unsigned long * ) V_2 -> V_16 ) ;
} else {
F_20 ( V_33
L_5 ,
V_2 -> V_20 , V_2 -> V_17 -> V_34 ,
V_2 -> V_17 -> V_35 , V_27 ) ;
F_1 ( V_2 , V_2 -> V_20 ) ;
}
V_30:
V_2 -> V_8 . type = V_36 ;
return false ;
}
void F_21 ( struct V_1 * V_2 , struct V_37 * V_17 ,
struct V_18 * V_16 , unsigned long * V_38 )
{
unsigned long * V_20 , * V_39 ;
T_1 V_22 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_17 = V_17 ;
if ( V_16 && F_7 ( V_16 ) ) {
V_2 -> V_8 . type = V_36 ;
return;
}
V_20 = F_22 ( V_17 , V_16 ) ;
V_16 = F_15 ( V_20 ) ;
if ( V_16 ) {
V_2 -> V_16 = V_16 ;
V_39 = ( unsigned long * ) V_16 ;
V_22 = sizeof( * V_16 ) ;
} else {
V_2 -> V_20 = V_20 ;
V_39 = V_20 ;
V_22 = V_21 ;
}
F_18 ( V_39 , V_2 -> V_17 , & V_2 -> V_8 ,
& V_2 -> V_10 ) ;
F_16 ( V_2 , V_39 , V_22 ) ;
while ( ! F_6 ( V_2 ) &&
( ! F_17 ( & V_2 -> V_8 , V_38 , sizeof( long ) ) ||
V_2 -> V_20 < V_38 ) )
F_19 ( V_2 ) ;
}
