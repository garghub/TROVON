T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_2 V_7 , V_8 ;
V_7 = F_3 ( V_6 -> V_9 + V_10 ) ;
V_8 = V_7 & F_4 ( V_6 -> V_11 ) ;
if ( F_5 ( V_7 ) )
F_6 ( V_7 , V_6 -> V_9 + V_10 ) ;
if ( ! V_7 )
return V_12 ;
if ( V_8 & ( V_13 |
V_14 ) ) {
F_7 ( V_6 -> V_15 ) ;
F_8 ( & V_6 -> V_16 ) ;
}
if ( V_8 & V_17 )
F_8 ( & V_6 -> V_18 ) ;
if ( V_8 & ( V_19 |
V_20 ) )
F_9 ( V_6 -> V_21 ) ;
return V_22 ;
}
static bool F_10 ( struct V_5 * V_6 , T_2 V_23 )
{
return ( F_11 ( V_6 , V_24 ) == 0 ) ;
}
void F_12 ( struct V_5 * V_6 ,
struct V_25 * V_26 )
{
T_3 * V_27 = V_6 -> V_28 ;
T_2 V_23 = F_13 ( V_27 + V_29 ) ;
if ( V_6 -> V_30 != V_23 ) {
V_6 -> V_30 = V_23 ;
F_14 ( & V_26 -> V_31 , V_23 ) ;
F_7 ( V_6 -> V_15 ) ;
}
}
bool F_15 ( struct V_5 * V_6 ,
T_2 V_23 )
{
struct V_25 * V_26 ;
bool V_32 ;
if ( F_5 ( V_6 -> V_30 - V_23 < V_33 ) )
return true ;
V_26 = & V_6 -> V_34 ;
F_12 ( V_6 , V_26 ) ;
if ( F_5 ( V_6 -> V_30 - V_23 < V_33 ) )
return true ;
if ( ! ( V_26 -> V_35 & V_36 ) &&
F_10 ( V_6 , V_23 ) )
return true ;
V_32 = ( ( F_16 ( & V_6 -> V_37 ) - V_23 )
> V_33 ) ;
return V_32 ;
}
int F_17 ( struct V_5 * V_6 ,
bool V_38 ,
bool V_39 ,
T_2 V_23 ,
bool V_40 ,
unsigned long V_41 )
{
struct V_25 * V_26 = & V_6 -> V_34 ;
T_2 V_42 = 0 ;
T_2 V_43 ;
int V_32 ;
unsigned long V_44 = V_45 + V_41 ;
bool (* F_18)( struct V_5 * , T_2 );
F_19 ( V_46 ) ;
F_18 = ( V_39 ) ? & F_10 :
& F_15 ;
if ( V_39 ) {
F_20 ( & V_26 -> V_47 ) ;
if ( V_6 -> V_21 ) {
V_32 = F_21 ( V_6 -> V_21 , V_40 ,
10 * V_48 ) ;
if ( V_32 )
goto V_49;
}
}
V_43 = F_16 ( & V_6 -> V_37 ) ;
V_32 = 0 ;
for (; ; ) {
F_22 ( & V_6 -> V_16 , & V_46 ,
( V_40 ) ?
V_50 : V_51 ) ;
if ( F_18 ( V_6 , V_23 ) )
break;
if ( F_23 ( V_45 , V_44 ) ) {
F_24 ( L_1 ) ;
break;
}
if ( V_38 )
F_25 ( 1 ) ;
else if ( ( ++ V_42 & 0x0F ) == 0 ) {
F_26 ( V_52 ) ;
F_27 () ;
F_26 ( ( V_40 ) ?
V_50 :
V_51 ) ;
}
if ( V_40 && F_28 ( V_53 ) ) {
V_32 = - V_54 ;
break;
}
}
F_29 ( & V_6 -> V_16 , & V_46 ) ;
if ( V_32 == 0 && V_39 ) {
T_3 * V_27 = V_6 -> V_28 ;
F_30 ( V_43 , V_27 + V_29 ) ;
}
F_8 ( & V_6 -> V_16 ) ;
V_49:
if ( V_39 )
F_31 ( & V_26 -> V_47 ) ;
return V_32 ;
}
void F_32 ( struct V_5 * V_6 ,
T_3 V_55 , int * V_56 )
{
F_33 ( & V_6 -> V_57 ) ;
if ( ( * V_56 ) ++ == 0 ) {
F_6 ( V_55 , V_6 -> V_9 + V_10 ) ;
V_6 -> V_11 |= V_55 ;
F_34 ( V_6 , V_58 , V_6 -> V_11 ) ;
}
F_35 ( & V_6 -> V_57 ) ;
}
void F_36 ( struct V_5 * V_6 ,
T_3 V_55 , int * V_56 )
{
F_33 ( & V_6 -> V_57 ) ;
if ( -- ( * V_56 ) == 0 ) {
V_6 -> V_11 &= ~ V_55 ;
F_34 ( V_6 , V_58 , V_6 -> V_11 ) ;
}
F_35 ( & V_6 -> V_57 ) ;
}
void F_37 ( struct V_5 * V_6 )
{
F_32 ( V_6 , V_13 ,
& V_6 -> V_59 ) ;
}
void F_38 ( struct V_5 * V_6 )
{
F_36 ( V_6 , V_13 ,
& V_6 -> V_59 ) ;
}
void F_39 ( struct V_5 * V_6 )
{
F_32 ( V_6 , V_14 ,
& V_6 -> V_60 ) ;
}
void F_40 ( struct V_5 * V_6 )
{
F_36 ( V_6 , V_14 ,
& V_6 -> V_60 ) ;
}
int F_41 ( struct V_5 * V_6 ,
bool V_38 , T_2 V_23 ,
bool V_40 , unsigned long V_41 )
{
long V_32 ;
struct V_25 * V_34 = & V_6 -> V_34 ;
if ( F_5 ( V_6 -> V_30 - V_23 < V_33 ) )
return 0 ;
if ( F_5 ( F_15 ( V_6 , V_23 ) ) )
return 0 ;
F_42 ( V_6 , V_61 ) ;
if ( ! ( V_34 -> V_35 & V_36 ) )
return F_17 ( V_6 , V_38 , true , V_23 ,
V_40 , V_41 ) ;
if ( ! ( V_6 -> V_35 & V_62 ) )
return F_17 ( V_6 , V_38 , false , V_23 ,
V_40 , V_41 ) ;
F_37 ( V_6 ) ;
if ( V_40 )
V_32 = F_43
( V_6 -> V_16 ,
F_15 ( V_6 , V_23 ) ,
V_41 ) ;
else
V_32 = F_44
( V_6 -> V_16 ,
F_15 ( V_6 , V_23 ) ,
V_41 ) ;
F_38 ( V_6 ) ;
if ( F_45 ( V_32 == 0 ) )
V_32 = - V_63 ;
else if ( F_5 ( V_32 > 0 ) )
V_32 = 0 ;
return V_32 ;
}
void F_46 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_2 V_7 ;
if ( ! ( V_6 -> V_35 & V_62 ) )
return;
V_7 = F_3 ( V_6 -> V_9 + V_10 ) ;
F_6 ( V_7 , V_6 -> V_9 + V_10 ) ;
}
int F_47 ( struct V_3 * V_4 )
{
return 0 ;
}
void F_48 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_2 V_7 ;
if ( ! ( V_6 -> V_35 & V_62 ) )
return;
F_34 ( V_6 , V_58 , 0 ) ;
V_7 = F_3 ( V_6 -> V_9 + V_10 ) ;
F_6 ( V_7 , V_6 -> V_9 + V_10 ) ;
}
