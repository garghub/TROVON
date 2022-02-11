T_1 F_1 ( T_2 )
{
struct V_1 * V_2 = (struct V_1 * ) V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_3 V_6 ;
F_3 ( & V_5 -> V_7 ) ;
V_6 = F_4 ( V_5 -> V_8 + V_9 ) ;
F_5 ( & V_5 -> V_7 ) ;
if ( V_6 & V_10 )
F_6 ( & V_5 -> V_11 ) ;
if ( V_6 & V_12 )
F_6 ( & V_5 -> V_13 ) ;
if ( F_7 ( V_6 ) ) {
F_8 ( V_6 , V_5 -> V_8 + V_9 ) ;
return V_14 ;
}
return V_15 ;
}
static bool F_9 ( struct V_4 * V_5 , T_3 V_16 )
{
T_3 V_17 ;
F_10 ( & V_5 -> V_18 ) ;
V_17 = F_11 ( V_5 , V_19 ) ;
F_12 ( & V_5 -> V_18 ) ;
return ( V_17 == 0 ) ;
}
void F_13 ( struct V_4 * V_5 ,
struct V_20 * V_21 )
{
T_4 T_5 * V_22 = V_5 -> V_23 ;
T_3 V_16 = F_14 ( V_22 + V_24 ) ;
if ( V_5 -> V_25 != V_16 ) {
V_5 -> V_25 = V_16 ;
F_15 ( & V_21 -> V_11 , V_16 ) ;
}
}
bool F_16 ( struct V_4 * V_5 ,
T_3 V_16 )
{
struct V_20 * V_21 ;
bool V_26 ;
if ( F_7 ( V_5 -> V_25 - V_16 < V_27 ) )
return true ;
V_21 = & V_5 -> V_28 ;
F_13 ( V_5 , V_21 ) ;
if ( F_7 ( V_5 -> V_25 - V_16 < V_27 ) )
return true ;
if ( ! ( V_21 -> V_29 & V_30 ) &&
F_9 ( V_5 , V_16 ) )
return true ;
V_26 = ( ( F_17 ( & V_5 -> V_31 ) - V_16 )
> V_27 ) ;
return V_26 ;
}
int F_18 ( struct V_4 * V_5 ,
bool V_32 ,
bool V_33 ,
T_3 V_16 ,
bool V_34 ,
unsigned long V_35 )
{
struct V_20 * V_21 = & V_5 -> V_28 ;
T_3 V_36 = 0 ;
T_3 V_37 ;
int V_26 ;
unsigned long V_38 = V_39 + V_35 ;
bool (* F_19)( struct V_4 * , T_3 );
F_20 ( V_40 ) ;
F_19 = ( V_33 ) ? & F_9 :
& F_16 ;
if ( V_33 )
F_21 ( & V_21 -> V_41 ) ;
V_37 = F_17 ( & V_5 -> V_31 ) ;
V_26 = 0 ;
for (; ; ) {
F_22 ( & V_5 -> V_11 , & V_40 ,
( V_34 ) ?
V_42 : V_43 ) ;
if ( F_19 ( V_5 , V_16 ) )
break;
if ( F_23 ( V_39 , V_38 ) ) {
F_24 ( L_1 ) ;
break;
}
if ( V_32 )
F_25 ( 1 ) ;
else if ( ( ++ V_36 & 0x0F ) == 0 ) {
F_26 ( V_44 ) ;
F_27 () ;
F_26 ( ( V_34 ) ?
V_42 :
V_43 ) ;
}
if ( V_34 && F_28 ( V_45 ) ) {
V_26 = - V_46 ;
break;
}
}
F_29 ( & V_5 -> V_11 , & V_40 ) ;
if ( V_26 == 0 && V_33 ) {
T_4 T_5 * V_22 = V_5 -> V_23 ;
F_30 ( V_37 , V_22 + V_24 ) ;
}
F_6 ( & V_5 -> V_11 ) ;
if ( V_33 )
F_31 ( & V_21 -> V_41 ) ;
return V_26 ;
}
int F_32 ( struct V_4 * V_5 ,
bool V_32 , T_3 V_16 ,
bool V_34 , unsigned long V_35 )
{
long V_26 ;
unsigned long V_47 ;
struct V_20 * V_28 = & V_5 -> V_28 ;
if ( F_7 ( V_5 -> V_25 - V_16 < V_27 ) )
return 0 ;
if ( F_7 ( F_16 ( V_5 , V_16 ) ) )
return 0 ;
F_33 ( V_5 , V_48 ) ;
if ( ! ( V_28 -> V_29 & V_30 ) )
return F_18 ( V_5 , V_32 , true , V_16 ,
V_34 , V_35 ) ;
if ( ! ( V_5 -> V_29 & V_49 ) )
return F_18 ( V_5 , V_32 , false , V_16 ,
V_34 , V_35 ) ;
F_10 ( & V_5 -> V_18 ) ;
if ( F_34 ( 1 , & V_5 -> V_50 ) > 0 ) {
F_35 ( & V_5 -> V_7 , V_47 ) ;
F_8 ( V_10 ,
V_5 -> V_8 + V_9 ) ;
F_36 ( V_5 , V_51 ,
F_11 ( V_5 , V_51 ) |
V_10 ) ;
F_37 ( & V_5 -> V_7 , V_47 ) ;
}
F_12 ( & V_5 -> V_18 ) ;
if ( V_34 )
V_26 = F_38
( V_5 -> V_11 ,
F_16 ( V_5 , V_16 ) ,
V_35 ) ;
else
V_26 = F_39
( V_5 -> V_11 ,
F_16 ( V_5 , V_16 ) ,
V_35 ) ;
if ( F_40 ( V_26 == 0 ) )
V_26 = - V_52 ;
else if ( F_7 ( V_26 > 0 ) )
V_26 = 0 ;
F_10 ( & V_5 -> V_18 ) ;
if ( F_41 ( & V_5 -> V_50 ) ) {
F_35 ( & V_5 -> V_7 , V_47 ) ;
F_36 ( V_5 , V_51 ,
F_11 ( V_5 , V_51 ) &
~ V_10 ) ;
F_37 ( & V_5 -> V_7 , V_47 ) ;
}
F_12 ( & V_5 -> V_18 ) ;
return V_26 ;
}
void F_42 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_3 V_6 ;
if ( ! ( V_5 -> V_29 & V_49 ) )
return;
F_43 ( & V_5 -> V_7 ) ;
V_6 = F_4 ( V_5 -> V_8 + V_9 ) ;
F_8 ( V_6 , V_5 -> V_8 + V_9 ) ;
}
int F_44 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_45 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_3 V_6 ;
if ( ! ( V_5 -> V_29 & V_49 ) )
return;
F_10 ( & V_5 -> V_18 ) ;
F_36 ( V_5 , V_51 , 0 ) ;
F_12 ( & V_5 -> V_18 ) ;
V_6 = F_4 ( V_5 -> V_8 + V_9 ) ;
F_8 ( V_6 , V_5 -> V_8 + V_9 ) ;
}
int F_46 ( struct V_1 * V_2 , void * V_53 ,
struct V_54 * V_55 )
{
struct V_56 * V_3 =
(struct V_56 * ) V_53 ;
unsigned long V_35 ;
if ( ! V_3 -> V_57 ) {
V_3 -> V_57 = 1 ;
V_3 -> V_58 = V_39 + V_59 ;
}
V_35 = V_39 ;
if ( F_23 ( V_35 , ( unsigned long ) V_3 -> V_58 ) )
return - V_52 ;
V_35 = ( unsigned long ) V_3 -> V_58 - V_35 ;
return F_32 ( F_2 ( V_2 ) , true , V_3 -> V_16 , true , V_35 ) ;
}
