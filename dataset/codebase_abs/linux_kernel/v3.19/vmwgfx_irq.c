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
return ( F_11 ( V_6 , V_22 ) == 0 ) ;
}
void F_12 ( struct V_5 * V_6 ,
struct V_23 * V_24 )
{
T_3 T_4 * V_25 = V_6 -> V_26 ;
T_2 V_21 = F_13 ( V_25 + V_27 ) ;
if ( V_6 -> V_28 != V_21 ) {
V_6 -> V_28 = V_21 ;
F_14 ( & V_24 -> V_29 , V_21 ) ;
F_8 ( V_6 -> V_16 ) ;
}
}
bool F_15 ( struct V_5 * V_6 ,
T_2 V_21 )
{
struct V_23 * V_24 ;
bool V_30 ;
if ( F_6 ( V_6 -> V_28 - V_21 < V_31 ) )
return true ;
V_24 = & V_6 -> V_32 ;
F_12 ( V_6 , V_24 ) ;
if ( F_6 ( V_6 -> V_28 - V_21 < V_31 ) )
return true ;
if ( ! ( V_24 -> V_33 & V_34 ) &&
F_10 ( V_6 , V_21 ) )
return true ;
V_30 = ( ( F_16 ( & V_6 -> V_35 ) - V_21 )
> V_31 ) ;
return V_30 ;
}
int F_17 ( struct V_5 * V_6 ,
bool V_36 ,
bool V_37 ,
T_2 V_21 ,
bool V_38 ,
unsigned long V_39 )
{
struct V_23 * V_24 = & V_6 -> V_32 ;
T_2 V_40 = 0 ;
T_2 V_41 ;
int V_30 ;
unsigned long V_42 = V_43 + V_39 ;
bool (* F_18)( struct V_5 * , T_2 );
F_19 ( V_44 ) ;
F_18 = ( V_37 ) ? & F_10 :
& F_15 ;
if ( V_37 )
F_20 ( & V_24 -> V_45 ) ;
V_41 = F_16 ( & V_6 -> V_35 ) ;
V_30 = 0 ;
for (; ; ) {
F_21 ( & V_6 -> V_17 , & V_44 ,
( V_38 ) ?
V_46 : V_47 ) ;
if ( F_18 ( V_6 , V_21 ) )
break;
if ( F_22 ( V_43 , V_42 ) ) {
F_23 ( L_1 ) ;
break;
}
if ( V_36 )
F_24 ( 1 ) ;
else if ( ( ++ V_40 & 0x0F ) == 0 ) {
F_25 ( V_48 ) ;
F_26 () ;
F_25 ( ( V_38 ) ?
V_46 :
V_47 ) ;
}
if ( V_38 && F_27 ( V_49 ) ) {
V_30 = - V_50 ;
break;
}
}
F_28 ( & V_6 -> V_17 , & V_44 ) ;
if ( V_30 == 0 && V_37 ) {
T_3 T_4 * V_25 = V_6 -> V_26 ;
F_29 ( V_41 , V_25 + V_27 ) ;
}
F_9 ( & V_6 -> V_17 ) ;
if ( V_37 )
F_30 ( & V_24 -> V_45 ) ;
return V_30 ;
}
void F_31 ( struct V_5 * V_6 )
{
F_3 ( & V_6 -> V_51 ) ;
if ( V_6 -> V_52 ++ == 0 ) {
unsigned long V_53 ;
F_32 ( & V_6 -> V_9 , V_53 ) ;
F_7 ( V_14 ,
V_6 -> V_10 + V_11 ) ;
V_6 -> V_12 |= V_14 ;
F_33 ( V_6 , V_54 , V_6 -> V_12 ) ;
F_34 ( & V_6 -> V_9 , V_53 ) ;
}
F_5 ( & V_6 -> V_51 ) ;
}
void F_35 ( struct V_5 * V_6 )
{
F_3 ( & V_6 -> V_51 ) ;
if ( -- V_6 -> V_52 == 0 ) {
unsigned long V_53 ;
F_32 ( & V_6 -> V_9 , V_53 ) ;
V_6 -> V_12 &= ~ V_14 ;
F_33 ( V_6 , V_54 , V_6 -> V_12 ) ;
F_34 ( & V_6 -> V_9 , V_53 ) ;
}
F_5 ( & V_6 -> V_51 ) ;
}
void F_36 ( struct V_5 * V_6 )
{
F_3 ( & V_6 -> V_51 ) ;
if ( V_6 -> V_55 ++ == 0 ) {
unsigned long V_53 ;
F_32 ( & V_6 -> V_9 , V_53 ) ;
F_7 ( V_15 ,
V_6 -> V_10 + V_11 ) ;
V_6 -> V_12 |= V_15 ;
F_33 ( V_6 , V_54 , V_6 -> V_12 ) ;
F_34 ( & V_6 -> V_9 , V_53 ) ;
}
F_5 ( & V_6 -> V_51 ) ;
}
void F_37 ( struct V_5 * V_6 )
{
F_3 ( & V_6 -> V_51 ) ;
if ( -- V_6 -> V_55 == 0 ) {
unsigned long V_53 ;
F_32 ( & V_6 -> V_9 , V_53 ) ;
V_6 -> V_12 &= ~ V_15 ;
F_33 ( V_6 , V_54 , V_6 -> V_12 ) ;
F_34 ( & V_6 -> V_9 , V_53 ) ;
}
F_5 ( & V_6 -> V_51 ) ;
}
int F_38 ( struct V_5 * V_6 ,
bool V_36 , T_2 V_21 ,
bool V_38 , unsigned long V_39 )
{
long V_30 ;
struct V_23 * V_32 = & V_6 -> V_32 ;
if ( F_6 ( V_6 -> V_28 - V_21 < V_31 ) )
return 0 ;
if ( F_6 ( F_15 ( V_6 , V_21 ) ) )
return 0 ;
F_39 ( V_6 , V_56 ) ;
if ( ! ( V_32 -> V_33 & V_34 ) )
return F_17 ( V_6 , V_36 , true , V_21 ,
V_38 , V_39 ) ;
if ( ! ( V_6 -> V_33 & V_57 ) )
return F_17 ( V_6 , V_36 , false , V_21 ,
V_38 , V_39 ) ;
F_31 ( V_6 ) ;
if ( V_38 )
V_30 = F_40
( V_6 -> V_17 ,
F_15 ( V_6 , V_21 ) ,
V_39 ) ;
else
V_30 = F_41
( V_6 -> V_17 ,
F_15 ( V_6 , V_21 ) ,
V_39 ) ;
F_35 ( V_6 ) ;
if ( F_42 ( V_30 == 0 ) )
V_30 = - V_58 ;
else if ( F_6 ( V_30 > 0 ) )
V_30 = 0 ;
return V_30 ;
}
void F_43 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_2 V_7 ;
if ( ! ( V_6 -> V_33 & V_57 ) )
return;
F_44 ( & V_6 -> V_9 ) ;
V_7 = F_4 ( V_6 -> V_10 + V_11 ) ;
F_7 ( V_7 , V_6 -> V_10 + V_11 ) ;
}
int F_45 ( struct V_3 * V_4 )
{
return 0 ;
}
void F_46 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_2 V_7 ;
if ( ! ( V_6 -> V_33 & V_57 ) )
return;
F_33 ( V_6 , V_54 , 0 ) ;
V_7 = F_4 ( V_6 -> V_10 + V_11 ) ;
F_7 ( V_7 , V_6 -> V_10 + V_11 ) ;
}
