static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( & V_5 ) ;
F_3 () ;
F_4 (relation, &ptracer_relations, node) {
if ( V_4 -> V_6 ) {
F_5 ( & V_4 -> V_7 ) ;
F_6 ( V_4 , V_8 ) ;
}
}
F_7 () ;
F_8 ( & V_5 ) ;
}
static int F_9 ( struct V_9 * V_10 ,
struct V_9 * V_11 )
{
struct V_3 * V_4 , * V_12 ;
V_12 = F_10 ( sizeof( * V_12 ) , V_13 ) ;
if ( ! V_12 )
return - V_14 ;
V_12 -> V_11 = V_11 ;
V_12 -> V_10 = V_10 ;
V_12 -> V_6 = false ;
F_2 ( & V_5 ) ;
F_3 () ;
F_4 (relation, &ptracer_relations, node) {
if ( V_4 -> V_6 )
continue;
if ( V_4 -> V_11 == V_11 ) {
F_11 ( & V_4 -> V_7 , & V_12 -> V_7 ) ;
F_6 ( V_4 , V_8 ) ;
goto V_15;
}
}
F_12 ( & V_12 -> V_7 , & V_16 ) ;
V_15:
F_7 () ;
F_8 ( & V_5 ) ;
return 0 ;
}
static void F_13 ( struct V_9 * V_10 ,
struct V_9 * V_11 )
{
struct V_3 * V_4 ;
bool V_17 = false ;
F_3 () ;
F_4 (relation, &ptracer_relations, node) {
if ( V_4 -> V_6 )
continue;
if ( V_4 -> V_11 == V_11 ||
( V_10 && V_4 -> V_10 == V_10 ) ) {
V_4 -> V_6 = true ;
V_17 = true ;
}
}
F_7 () ;
if ( V_17 )
F_14 ( & V_18 ) ;
}
void F_15 ( struct V_9 * V_19 )
{
F_13 ( V_19 , V_19 ) ;
}
int F_16 ( int V_20 , unsigned long V_21 , unsigned long V_22 ,
unsigned long V_23 , unsigned long V_24 )
{
int V_25 ;
struct V_9 * V_26 = V_27 ;
V_25 = F_17 ( V_20 , V_21 , V_22 , V_23 , V_24 ) ;
if ( V_25 != - V_28 )
return V_25 ;
switch ( V_20 ) {
case V_29 :
F_3 () ;
if ( ! F_18 ( V_26 ) )
V_26 = F_19 ( V_26 -> V_30 ) ;
F_20 ( V_26 ) ;
F_7 () ;
if ( V_21 == 0 ) {
F_13 ( NULL , V_26 ) ;
V_25 = 0 ;
} else if ( V_21 == V_31 || ( int ) V_21 == - 1 ) {
V_25 = F_9 ( NULL , V_26 ) ;
} else {
struct V_9 * V_10 ;
F_3 () ;
V_10 = F_21 ( V_21 ) ;
if ( V_10 )
F_20 ( V_10 ) ;
else
V_25 = - V_32 ;
F_7 () ;
if ( V_10 ) {
V_25 = F_9 ( V_10 , V_26 ) ;
F_22 ( V_10 ) ;
}
}
F_22 ( V_26 ) ;
break;
}
return V_25 ;
}
static int F_23 ( struct V_9 * V_33 ,
struct V_9 * V_34 )
{
int V_25 = 0 ;
struct V_9 * V_35 = V_34 ;
if ( ! V_33 || ! V_34 )
return 0 ;
F_3 () ;
if ( ! F_18 ( V_33 ) )
V_33 = F_19 ( V_33 -> V_30 ) ;
while ( V_35 -> V_36 > 0 ) {
if ( ! F_18 ( V_35 ) )
V_35 = F_19 ( V_35 -> V_30 ) ;
if ( V_35 == V_33 ) {
V_25 = 1 ;
break;
}
V_35 = F_19 ( V_35 -> V_37 ) ;
}
F_7 () ;
return V_25 ;
}
static int F_24 ( struct V_9 * V_10 ,
struct V_9 * V_11 )
{
int V_25 = 0 ;
struct V_3 * V_4 ;
struct V_9 * V_33 = NULL ;
bool V_38 = false ;
F_3 () ;
if ( ! F_18 ( V_11 ) )
V_11 = F_19 ( V_11 -> V_30 ) ;
F_4 (relation, &ptracer_relations, node) {
if ( V_4 -> V_6 )
continue;
if ( V_4 -> V_11 == V_11 ) {
V_33 = V_4 -> V_10 ;
V_38 = true ;
break;
}
}
if ( V_38 && ( V_33 == NULL || F_23 ( V_33 , V_10 ) ) )
V_25 = 1 ;
F_7 () ;
return V_25 ;
}
int F_25 ( struct V_9 * V_34 ,
unsigned int V_39 )
{
int V_25 ;
V_25 = F_26 ( V_34 , V_39 ) ;
if ( V_25 )
return V_25 ;
if ( V_39 == V_40 ) {
switch ( V_41 ) {
case V_42 :
break;
case V_43 :
F_3 () ;
if ( ! F_23 ( V_27 , V_34 ) &&
! F_24 ( V_27 , V_34 ) &&
! F_27 ( F_28 ( V_34 ) -> V_44 , V_45 ) )
V_25 = - V_46 ;
F_7 () ;
break;
case V_47 :
F_3 () ;
if ( ! F_27 ( F_28 ( V_34 ) -> V_44 , V_45 ) )
V_25 = - V_46 ;
F_7 () ;
break;
case V_48 :
default:
V_25 = - V_46 ;
break;
}
}
if ( V_25 ) {
F_29 ( V_49
L_1 ,
V_34 -> V_36 , V_27 -> V_50 , V_27 -> V_36 ) ;
}
return V_25 ;
}
int F_30 ( struct V_9 * V_33 )
{
int V_25 ;
V_25 = F_31 ( V_33 ) ;
if ( V_25 )
return V_25 ;
switch ( V_41 ) {
case V_47 :
F_3 () ;
if ( ! F_27 ( F_28 ( V_33 ) -> V_44 , V_45 ) )
V_25 = - V_46 ;
F_7 () ;
break;
case V_48 :
V_25 = - V_46 ;
break;
}
if ( V_25 ) {
F_29 ( V_49
L_2 ,
V_27 -> V_36 , V_33 -> V_50 , V_33 -> V_36 ) ;
}
return V_25 ;
}
static int F_32 ( struct V_51 * V_52 , int V_53 ,
void T_1 * V_54 , T_2 * V_55 , T_3 * V_56 )
{
int V_25 ;
if ( V_53 && ! F_33 ( V_45 ) )
return - V_46 ;
V_25 = F_34 ( V_52 , V_53 , V_54 , V_55 , V_56 ) ;
if ( V_25 )
return V_25 ;
if ( V_53 && * ( int * ) V_52 -> V_57 == * ( int * ) V_52 -> V_58 )
V_52 -> V_59 = V_52 -> V_58 ;
return V_25 ;
}
static T_4 int F_35 ( void )
{
#ifndef F_36
if ( ! F_37 ( & V_60 ) )
return 0 ;
#endif
F_38 ( V_61 L_3 ) ;
#ifndef F_36
if ( F_39 ( & V_60 ) )
F_40 ( L_4 ) ;
#endif
#ifdef F_41
if ( ! F_42 ( V_62 , V_63 ) )
F_40 ( L_5 ) ;
#endif
return 0 ;
}
