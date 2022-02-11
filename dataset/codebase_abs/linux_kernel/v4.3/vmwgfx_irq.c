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
if ( V_8 & ( V_20 |
V_21 ) )
F_10 ( V_6 -> V_22 ) ;
return V_23 ;
}
static bool F_11 ( struct V_5 * V_6 , T_2 V_24 )
{
return ( F_12 ( V_6 , V_25 ) == 0 ) ;
}
void F_13 ( struct V_5 * V_6 ,
struct V_26 * V_27 )
{
T_3 T_4 * V_28 = V_6 -> V_29 ;
T_2 V_24 = F_14 ( V_28 + V_30 ) ;
if ( V_6 -> V_31 != V_24 ) {
V_6 -> V_31 = V_24 ;
F_15 ( & V_27 -> V_32 , V_24 ) ;
F_8 ( V_6 -> V_16 ) ;
}
}
bool F_16 ( struct V_5 * V_6 ,
T_2 V_24 )
{
struct V_26 * V_27 ;
bool V_33 ;
if ( F_6 ( V_6 -> V_31 - V_24 < V_34 ) )
return true ;
V_27 = & V_6 -> V_35 ;
F_13 ( V_6 , V_27 ) ;
if ( F_6 ( V_6 -> V_31 - V_24 < V_34 ) )
return true ;
if ( ! ( V_27 -> V_36 & V_37 ) &&
F_11 ( V_6 , V_24 ) )
return true ;
V_33 = ( ( F_17 ( & V_6 -> V_38 ) - V_24 )
> V_34 ) ;
return V_33 ;
}
int F_18 ( struct V_5 * V_6 ,
bool V_39 ,
bool V_40 ,
T_2 V_24 ,
bool V_41 ,
unsigned long V_42 )
{
struct V_26 * V_27 = & V_6 -> V_35 ;
T_2 V_43 = 0 ;
T_2 V_44 ;
int V_33 ;
unsigned long V_45 = V_46 + V_42 ;
bool (* F_19)( struct V_5 * , T_2 );
F_20 ( V_47 ) ;
F_19 = ( V_40 ) ? & F_11 :
& F_16 ;
if ( V_40 ) {
F_21 ( & V_27 -> V_48 ) ;
if ( V_6 -> V_22 ) {
V_33 = F_22 ( V_6 -> V_22 , V_41 ,
10 * V_49 ) ;
if ( V_33 )
goto V_50;
}
}
V_44 = F_17 ( & V_6 -> V_38 ) ;
V_33 = 0 ;
for (; ; ) {
F_23 ( & V_6 -> V_17 , & V_47 ,
( V_41 ) ?
V_51 : V_52 ) ;
if ( F_19 ( V_6 , V_24 ) )
break;
if ( F_24 ( V_46 , V_45 ) ) {
F_25 ( L_1 ) ;
break;
}
if ( V_39 )
F_26 ( 1 ) ;
else if ( ( ++ V_43 & 0x0F ) == 0 ) {
F_27 ( V_53 ) ;
F_28 () ;
F_27 ( ( V_41 ) ?
V_51 :
V_52 ) ;
}
if ( V_41 && F_29 ( V_54 ) ) {
V_33 = - V_55 ;
break;
}
}
F_30 ( & V_6 -> V_17 , & V_47 ) ;
if ( V_33 == 0 && V_40 ) {
T_3 T_4 * V_28 = V_6 -> V_29 ;
F_31 ( V_44 , V_28 + V_30 ) ;
}
F_9 ( & V_6 -> V_17 ) ;
V_50:
if ( V_40 )
F_32 ( & V_27 -> V_48 ) ;
return V_33 ;
}
void F_33 ( struct V_5 * V_6 )
{
F_3 ( & V_6 -> V_56 ) ;
if ( V_6 -> V_57 ++ == 0 ) {
unsigned long V_58 ;
F_34 ( & V_6 -> V_9 , V_58 ) ;
F_7 ( V_14 ,
V_6 -> V_10 + V_11 ) ;
V_6 -> V_12 |= V_14 ;
F_35 ( V_6 , V_59 , V_6 -> V_12 ) ;
F_36 ( & V_6 -> V_9 , V_58 ) ;
}
F_5 ( & V_6 -> V_56 ) ;
}
void F_37 ( struct V_5 * V_6 )
{
F_3 ( & V_6 -> V_56 ) ;
if ( -- V_6 -> V_57 == 0 ) {
unsigned long V_58 ;
F_34 ( & V_6 -> V_9 , V_58 ) ;
V_6 -> V_12 &= ~ V_14 ;
F_35 ( V_6 , V_59 , V_6 -> V_12 ) ;
F_36 ( & V_6 -> V_9 , V_58 ) ;
}
F_5 ( & V_6 -> V_56 ) ;
}
void F_38 ( struct V_5 * V_6 )
{
F_3 ( & V_6 -> V_56 ) ;
if ( V_6 -> V_60 ++ == 0 ) {
unsigned long V_58 ;
F_34 ( & V_6 -> V_9 , V_58 ) ;
F_7 ( V_15 ,
V_6 -> V_10 + V_11 ) ;
V_6 -> V_12 |= V_15 ;
F_35 ( V_6 , V_59 , V_6 -> V_12 ) ;
F_36 ( & V_6 -> V_9 , V_58 ) ;
}
F_5 ( & V_6 -> V_56 ) ;
}
void F_39 ( struct V_5 * V_6 )
{
F_3 ( & V_6 -> V_56 ) ;
if ( -- V_6 -> V_60 == 0 ) {
unsigned long V_58 ;
F_34 ( & V_6 -> V_9 , V_58 ) ;
V_6 -> V_12 &= ~ V_15 ;
F_35 ( V_6 , V_59 , V_6 -> V_12 ) ;
F_36 ( & V_6 -> V_9 , V_58 ) ;
}
F_5 ( & V_6 -> V_56 ) ;
}
int F_40 ( struct V_5 * V_6 ,
bool V_39 , T_2 V_24 ,
bool V_41 , unsigned long V_42 )
{
long V_33 ;
struct V_26 * V_35 = & V_6 -> V_35 ;
if ( F_6 ( V_6 -> V_31 - V_24 < V_34 ) )
return 0 ;
if ( F_6 ( F_16 ( V_6 , V_24 ) ) )
return 0 ;
F_41 ( V_6 , V_61 ) ;
if ( ! ( V_35 -> V_36 & V_37 ) )
return F_18 ( V_6 , V_39 , true , V_24 ,
V_41 , V_42 ) ;
if ( ! ( V_6 -> V_36 & V_62 ) )
return F_18 ( V_6 , V_39 , false , V_24 ,
V_41 , V_42 ) ;
F_33 ( V_6 ) ;
if ( V_41 )
V_33 = F_42
( V_6 -> V_17 ,
F_16 ( V_6 , V_24 ) ,
V_42 ) ;
else
V_33 = F_43
( V_6 -> V_17 ,
F_16 ( V_6 , V_24 ) ,
V_42 ) ;
F_37 ( V_6 ) ;
if ( F_44 ( V_33 == 0 ) )
V_33 = - V_63 ;
else if ( F_6 ( V_33 > 0 ) )
V_33 = 0 ;
return V_33 ;
}
void F_45 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_2 V_7 ;
if ( ! ( V_6 -> V_36 & V_62 ) )
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
if ( ! ( V_6 -> V_36 & V_62 ) )
return;
F_35 ( V_6 , V_59 , 0 ) ;
V_7 = F_4 ( V_6 -> V_10 + V_11 ) ;
F_7 ( V_7 , V_6 -> V_10 + V_11 ) ;
}
void F_49 ( struct V_5 * V_6 ,
T_3 V_64 , int * V_65 )
{
unsigned long V_58 ;
F_34 ( & V_6 -> V_9 , V_58 ) ;
if ( ( * V_65 ) ++ == 0 ) {
F_7 ( V_64 , V_6 -> V_10 + V_11 ) ;
V_6 -> V_12 |= V_64 ;
F_35 ( V_6 , V_59 , V_6 -> V_12 ) ;
}
F_36 ( & V_6 -> V_9 , V_58 ) ;
}
void F_50 ( struct V_5 * V_6 ,
T_3 V_64 , int * V_65 )
{
unsigned long V_58 ;
F_34 ( & V_6 -> V_9 , V_58 ) ;
if ( -- ( * V_65 ) == 0 ) {
V_6 -> V_12 &= ~ V_64 ;
F_35 ( V_6 , V_59 , V_6 -> V_12 ) ;
}
F_36 ( & V_6 -> V_9 , V_58 ) ;
}
