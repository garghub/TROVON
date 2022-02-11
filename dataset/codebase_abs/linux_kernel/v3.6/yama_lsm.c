static int F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
int V_4 = 0 ;
struct V_5 * V_6 ;
struct V_5 * V_7 , * V_8 = NULL ;
V_6 = F_2 ( sizeof( * V_6 ) , V_9 ) ;
if ( ! V_6 )
return - V_10 ;
F_3 ( & V_11 ) ;
F_4 (entry, &ptracer_relations, node)
if ( V_7 -> V_3 == V_3 ) {
V_8 = V_7 ;
break;
}
if ( ! V_8 ) {
V_8 = V_6 ;
V_8 -> V_3 = V_3 ;
F_5 ( & V_8 -> V_12 , & V_13 ) ;
}
V_8 -> V_2 = V_2 ;
F_6 ( & V_11 ) ;
if ( V_6 != V_8 )
F_7 ( V_6 ) ;
return V_4 ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
struct V_5 * V_8 , * V_14 ;
F_3 ( & V_11 ) ;
F_9 (relation, safe, &ptracer_relations, node)
if ( V_8 -> V_3 == V_3 ||
( V_2 && V_8 -> V_2 == V_2 ) ) {
F_10 ( & V_8 -> V_12 ) ;
F_7 ( V_8 ) ;
}
F_6 ( & V_11 ) ;
}
static void F_11 ( struct V_1 * V_15 )
{
F_8 ( V_15 , V_15 ) ;
}
static int F_12 ( int V_16 , unsigned long V_17 , unsigned long V_18 ,
unsigned long V_19 , unsigned long V_20 )
{
int V_4 ;
struct V_1 * V_21 = V_22 ;
V_4 = F_13 ( V_16 , V_17 , V_18 , V_19 , V_20 ) ;
if ( V_4 != - V_23 )
return V_4 ;
switch ( V_16 ) {
case V_24 :
F_14 () ;
if ( ! F_15 ( V_21 ) )
V_21 = F_16 ( V_21 -> V_25 ) ;
F_17 ( V_21 ) ;
F_18 () ;
if ( V_17 == 0 ) {
F_8 ( NULL , V_21 ) ;
V_4 = 0 ;
} else if ( V_17 == V_26 ) {
V_4 = F_1 ( NULL , V_21 ) ;
} else {
struct V_1 * V_2 ;
F_14 () ;
V_2 = F_19 ( V_17 ) ;
if ( V_2 )
F_17 ( V_2 ) ;
else
V_4 = - V_27 ;
F_18 () ;
if ( V_2 ) {
V_4 = F_1 ( V_2 , V_21 ) ;
F_20 ( V_2 ) ;
}
}
F_20 ( V_21 ) ;
break;
}
return V_4 ;
}
static int F_21 ( struct V_1 * V_28 ,
struct V_1 * V_29 )
{
int V_4 = 0 ;
struct V_1 * V_30 = V_29 ;
if ( ! V_28 || ! V_29 )
return 0 ;
F_14 () ;
if ( ! F_15 ( V_28 ) )
V_28 = F_16 ( V_28 -> V_25 ) ;
while ( V_30 -> V_31 > 0 ) {
if ( ! F_15 ( V_30 ) )
V_30 = F_16 ( V_30 -> V_25 ) ;
if ( V_30 == V_28 ) {
V_4 = 1 ;
break;
}
V_30 = F_16 ( V_30 -> V_32 ) ;
}
F_18 () ;
return V_4 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
int V_4 = 0 ;
struct V_5 * V_8 ;
struct V_1 * V_28 = NULL ;
bool V_33 = false ;
F_3 ( & V_11 ) ;
F_14 () ;
if ( ! F_15 ( V_3 ) )
V_3 = F_16 ( V_3 -> V_25 ) ;
F_4 (relation, &ptracer_relations, node)
if ( V_8 -> V_3 == V_3 ) {
V_28 = V_8 -> V_2 ;
V_33 = true ;
break;
}
if ( V_33 && ( V_28 == NULL || F_21 ( V_28 , V_2 ) ) )
V_4 = 1 ;
F_18 () ;
F_6 ( & V_11 ) ;
return V_4 ;
}
static int F_23 ( struct V_1 * V_29 ,
unsigned int V_34 )
{
int V_4 ;
V_4 = F_24 ( V_29 , V_34 ) ;
if ( V_4 )
return V_4 ;
if ( V_34 == V_35 ) {
switch ( V_36 ) {
case V_37 :
break;
case V_38 :
if ( ! F_21 ( V_22 , V_29 ) &&
! F_22 ( V_22 , V_29 ) &&
! F_25 ( F_26 ( V_29 ) , V_39 ) )
V_4 = - V_40 ;
break;
case V_41 :
if ( ! F_25 ( F_26 ( V_29 ) , V_39 ) )
V_4 = - V_40 ;
break;
case V_42 :
default:
V_4 = - V_40 ;
break;
}
}
if ( V_4 ) {
F_27 ( V_43
L_1 ,
V_29 -> V_31 , V_22 -> V_44 , V_22 -> V_31 ) ;
}
return V_4 ;
}
static int F_28 ( struct V_1 * V_28 )
{
int V_4 ;
V_4 = F_29 ( V_28 ) ;
if ( V_4 )
return V_4 ;
switch ( V_36 ) {
case V_41 :
if ( ! F_25 ( F_26 ( V_28 ) , V_39 ) )
V_4 = - V_40 ;
break;
case V_42 :
V_4 = - V_40 ;
break;
}
if ( V_4 ) {
F_27 ( V_43
L_2 ,
V_22 -> V_31 , V_28 -> V_44 , V_28 -> V_31 ) ;
}
return V_4 ;
}
static int F_30 ( struct V_45 * V_46 , int V_47 ,
void T_1 * V_48 , T_2 * V_49 , T_3 * V_50 )
{
int V_4 ;
if ( V_47 && ! F_31 ( V_39 ) )
return - V_40 ;
V_4 = F_32 ( V_46 , V_47 , V_48 , V_49 , V_50 ) ;
if ( V_4 )
return V_4 ;
if ( V_47 && * ( int * ) V_46 -> V_51 == * ( int * ) V_46 -> V_52 )
V_46 -> V_53 = V_46 -> V_52 ;
return V_4 ;
}
static T_4 int F_33 ( void )
{
if ( ! F_34 ( & V_54 ) )
return 0 ;
F_35 ( V_55 L_3 ) ;
if ( F_36 ( & V_54 ) )
F_37 ( L_4 ) ;
#ifdef F_38
if ( ! F_39 ( V_56 , V_57 ) )
F_37 ( L_5 ) ;
#endif
return 0 ;
}
