T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_2 V_7 , V_8 ;
F_3 ( & V_6 -> V_9 ) ;
V_7 = F_4 ( V_6 -> V_10 + V_11 ) ;
V_8 = V_7 & V_6 -> V_12 ;
F_5 ( & V_6 -> V_9 ) ;
if ( F_6 ( V_7 ) )
F_7 ( V_7 , V_6 -> V_10 + V_11 ) ;
if ( ! V_8 )
return V_13 ;
if ( V_8 & ( V_14 |
V_15 ) ) {
F_8 ( V_6 -> V_16 ) ;
F_9 ( & V_6 -> V_17 ) ;
}
if ( V_8 & V_18 )
F_9 ( & V_6 -> V_19 ) ;
return V_20 ;
}
static bool F_10 ( struct V_5 * V_6 , T_2 V_21 )
{
T_2 V_22 ;
F_11 ( & V_6 -> V_23 ) ;
V_22 = F_12 ( V_6 , V_24 ) ;
F_13 ( & V_6 -> V_23 ) ;
return ( V_22 == 0 ) ;
}
void F_14 ( struct V_5 * V_6 ,
struct V_25 * V_26 )
{
T_3 T_4 * V_27 = V_6 -> V_28 ;
T_2 V_21 = F_15 ( V_27 + V_29 ) ;
if ( V_6 -> V_30 != V_21 ) {
V_6 -> V_30 = V_21 ;
F_16 ( & V_26 -> V_31 , V_21 ) ;
F_8 ( V_6 -> V_16 ) ;
}
}
bool F_17 ( struct V_5 * V_6 ,
T_2 V_21 )
{
struct V_25 * V_26 ;
bool V_32 ;
if ( F_6 ( V_6 -> V_30 - V_21 < V_33 ) )
return true ;
V_26 = & V_6 -> V_34 ;
F_14 ( V_6 , V_26 ) ;
if ( F_6 ( V_6 -> V_30 - V_21 < V_33 ) )
return true ;
if ( ! ( V_26 -> V_35 & V_36 ) &&
F_10 ( V_6 , V_21 ) )
return true ;
V_32 = ( ( F_18 ( & V_6 -> V_37 ) - V_21 )
> V_33 ) ;
return V_32 ;
}
int F_19 ( struct V_5 * V_6 ,
bool V_38 ,
bool V_39 ,
T_2 V_21 ,
bool V_40 ,
unsigned long V_41 )
{
struct V_25 * V_26 = & V_6 -> V_34 ;
T_2 V_42 = 0 ;
T_2 V_43 ;
int V_32 ;
unsigned long V_44 = V_45 + V_41 ;
bool (* F_20)( struct V_5 * , T_2 );
F_21 ( V_46 ) ;
F_20 = ( V_39 ) ? & F_10 :
& F_17 ;
if ( V_39 )
F_22 ( & V_26 -> V_47 ) ;
V_43 = F_18 ( & V_6 -> V_37 ) ;
V_32 = 0 ;
for (; ; ) {
F_23 ( & V_6 -> V_17 , & V_46 ,
( V_40 ) ?
V_48 : V_49 ) ;
if ( F_20 ( V_6 , V_21 ) )
break;
if ( F_24 ( V_45 , V_44 ) ) {
F_25 ( L_1 ) ;
break;
}
if ( V_38 )
F_26 ( 1 ) ;
else if ( ( ++ V_42 & 0x0F ) == 0 ) {
F_27 ( V_50 ) ;
F_28 () ;
F_27 ( ( V_40 ) ?
V_48 :
V_49 ) ;
}
if ( V_40 && F_29 ( V_51 ) ) {
V_32 = - V_52 ;
break;
}
}
F_30 ( & V_6 -> V_17 , & V_46 ) ;
if ( V_32 == 0 && V_39 ) {
T_3 T_4 * V_27 = V_6 -> V_28 ;
F_31 ( V_43 , V_27 + V_29 ) ;
}
F_9 ( & V_6 -> V_17 ) ;
if ( V_39 )
F_32 ( & V_26 -> V_47 ) ;
return V_32 ;
}
void F_33 ( struct V_5 * V_6 )
{
F_11 ( & V_6 -> V_23 ) ;
if ( V_6 -> V_53 ++ == 0 ) {
unsigned long V_54 ;
F_34 ( & V_6 -> V_9 , V_54 ) ;
F_7 ( V_14 ,
V_6 -> V_10 + V_11 ) ;
V_6 -> V_12 |= V_14 ;
F_35 ( V_6 , V_55 , V_6 -> V_12 ) ;
F_36 ( & V_6 -> V_9 , V_54 ) ;
}
F_13 ( & V_6 -> V_23 ) ;
}
void F_37 ( struct V_5 * V_6 )
{
F_11 ( & V_6 -> V_23 ) ;
if ( -- V_6 -> V_53 == 0 ) {
unsigned long V_54 ;
F_34 ( & V_6 -> V_9 , V_54 ) ;
V_6 -> V_12 &= ~ V_14 ;
F_35 ( V_6 , V_55 , V_6 -> V_12 ) ;
F_36 ( & V_6 -> V_9 , V_54 ) ;
}
F_13 ( & V_6 -> V_23 ) ;
}
void F_38 ( struct V_5 * V_6 )
{
F_11 ( & V_6 -> V_23 ) ;
if ( V_6 -> V_56 ++ == 0 ) {
unsigned long V_54 ;
F_34 ( & V_6 -> V_9 , V_54 ) ;
F_7 ( V_15 ,
V_6 -> V_10 + V_11 ) ;
V_6 -> V_12 |= V_15 ;
F_35 ( V_6 , V_55 , V_6 -> V_12 ) ;
F_36 ( & V_6 -> V_9 , V_54 ) ;
}
F_13 ( & V_6 -> V_23 ) ;
}
void F_39 ( struct V_5 * V_6 )
{
F_11 ( & V_6 -> V_23 ) ;
if ( -- V_6 -> V_56 == 0 ) {
unsigned long V_54 ;
F_34 ( & V_6 -> V_9 , V_54 ) ;
V_6 -> V_12 &= ~ V_15 ;
F_35 ( V_6 , V_55 , V_6 -> V_12 ) ;
F_36 ( & V_6 -> V_9 , V_54 ) ;
}
F_13 ( & V_6 -> V_23 ) ;
}
int F_40 ( struct V_5 * V_6 ,
bool V_38 , T_2 V_21 ,
bool V_40 , unsigned long V_41 )
{
long V_32 ;
struct V_25 * V_34 = & V_6 -> V_34 ;
if ( F_6 ( V_6 -> V_30 - V_21 < V_33 ) )
return 0 ;
if ( F_6 ( F_17 ( V_6 , V_21 ) ) )
return 0 ;
F_41 ( V_6 , V_57 ) ;
if ( ! ( V_34 -> V_35 & V_36 ) )
return F_19 ( V_6 , V_38 , true , V_21 ,
V_40 , V_41 ) ;
if ( ! ( V_6 -> V_35 & V_58 ) )
return F_19 ( V_6 , V_38 , false , V_21 ,
V_40 , V_41 ) ;
F_33 ( V_6 ) ;
if ( V_40 )
V_32 = F_42
( V_6 -> V_17 ,
F_17 ( V_6 , V_21 ) ,
V_41 ) ;
else
V_32 = F_43
( V_6 -> V_17 ,
F_17 ( V_6 , V_21 ) ,
V_41 ) ;
F_37 ( V_6 ) ;
if ( F_44 ( V_32 == 0 ) )
V_32 = - V_59 ;
else if ( F_6 ( V_32 > 0 ) )
V_32 = 0 ;
return V_32 ;
}
void F_45 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_2 V_7 ;
if ( ! ( V_6 -> V_35 & V_58 ) )
return;
F_46 ( & V_6 -> V_9 ) ;
V_7 = F_4 ( V_6 -> V_10 + V_11 ) ;
F_7 ( V_7 , V_6 -> V_10 + V_11 ) ;
}
int F_47 ( struct V_3 * V_4 )
{
return 0 ;
}
void F_48 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_2 V_7 ;
if ( ! ( V_6 -> V_35 & V_58 ) )
return;
F_11 ( & V_6 -> V_23 ) ;
F_35 ( V_6 , V_55 , 0 ) ;
F_13 ( & V_6 -> V_23 ) ;
V_7 = F_4 ( V_6 -> V_10 + V_11 ) ;
F_7 ( V_7 , V_6 -> V_10 + V_11 ) ;
}
