T_1 F_1 ( T_2 )
{
struct V_1 * V_2 = (struct V_1 * ) V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_3 V_6 , V_7 ;
F_3 ( & V_5 -> V_8 ) ;
V_6 = F_4 ( V_5 -> V_9 + V_10 ) ;
V_7 = V_6 & V_5 -> V_11 ;
F_5 ( & V_5 -> V_8 ) ;
if ( F_6 ( V_6 ) )
F_7 ( V_6 , V_5 -> V_9 + V_10 ) ;
if ( ! V_7 )
return V_12 ;
if ( V_7 & ( V_13 |
V_14 ) ) {
F_8 ( V_5 -> V_15 ) ;
F_9 ( & V_5 -> V_16 ) ;
}
if ( V_7 & V_17 )
F_9 ( & V_5 -> V_18 ) ;
return V_19 ;
}
static bool F_10 ( struct V_4 * V_5 , T_3 V_20 )
{
T_3 V_21 ;
F_11 ( & V_5 -> V_22 ) ;
V_21 = F_12 ( V_5 , V_23 ) ;
F_13 ( & V_5 -> V_22 ) ;
return ( V_21 == 0 ) ;
}
void F_14 ( struct V_4 * V_5 ,
struct V_24 * V_25 )
{
T_4 T_5 * V_26 = V_5 -> V_27 ;
T_3 V_20 = F_15 ( V_26 + V_28 ) ;
if ( V_5 -> V_29 != V_20 ) {
V_5 -> V_29 = V_20 ;
F_16 ( & V_25 -> V_30 , V_20 ) ;
F_8 ( V_5 -> V_15 ) ;
}
}
bool F_17 ( struct V_4 * V_5 ,
T_3 V_20 )
{
struct V_24 * V_25 ;
bool V_31 ;
if ( F_6 ( V_5 -> V_29 - V_20 < V_32 ) )
return true ;
V_25 = & V_5 -> V_33 ;
F_14 ( V_5 , V_25 ) ;
if ( F_6 ( V_5 -> V_29 - V_20 < V_32 ) )
return true ;
if ( ! ( V_25 -> V_34 & V_35 ) &&
F_10 ( V_5 , V_20 ) )
return true ;
V_31 = ( ( F_18 ( & V_5 -> V_36 ) - V_20 )
> V_32 ) ;
return V_31 ;
}
int F_19 ( struct V_4 * V_5 ,
bool V_37 ,
bool V_38 ,
T_3 V_20 ,
bool V_39 ,
unsigned long V_40 )
{
struct V_24 * V_25 = & V_5 -> V_33 ;
T_3 V_41 = 0 ;
T_3 V_42 ;
int V_31 ;
unsigned long V_43 = V_44 + V_40 ;
bool (* F_20)( struct V_4 * , T_3 );
F_21 ( V_45 ) ;
F_20 = ( V_38 ) ? & F_10 :
& F_17 ;
if ( V_38 )
F_22 ( & V_25 -> V_46 ) ;
V_42 = F_18 ( & V_5 -> V_36 ) ;
V_31 = 0 ;
for (; ; ) {
F_23 ( & V_5 -> V_16 , & V_45 ,
( V_39 ) ?
V_47 : V_48 ) ;
if ( F_20 ( V_5 , V_20 ) )
break;
if ( F_24 ( V_44 , V_43 ) ) {
F_25 ( L_1 ) ;
break;
}
if ( V_37 )
F_26 ( 1 ) ;
else if ( ( ++ V_41 & 0x0F ) == 0 ) {
F_27 ( V_49 ) ;
F_28 () ;
F_27 ( ( V_39 ) ?
V_47 :
V_48 ) ;
}
if ( V_39 && F_29 ( V_50 ) ) {
V_31 = - V_51 ;
break;
}
}
F_30 ( & V_5 -> V_16 , & V_45 ) ;
if ( V_31 == 0 && V_38 ) {
T_4 T_5 * V_26 = V_5 -> V_27 ;
F_31 ( V_42 , V_26 + V_28 ) ;
}
F_9 ( & V_5 -> V_16 ) ;
if ( V_38 )
F_32 ( & V_25 -> V_46 ) ;
return V_31 ;
}
void F_33 ( struct V_4 * V_5 )
{
F_11 ( & V_5 -> V_22 ) ;
if ( V_5 -> V_52 ++ == 0 ) {
unsigned long V_53 ;
F_34 ( & V_5 -> V_8 , V_53 ) ;
F_7 ( V_13 ,
V_5 -> V_9 + V_10 ) ;
V_5 -> V_11 |= V_13 ;
F_35 ( V_5 , V_54 , V_5 -> V_11 ) ;
F_36 ( & V_5 -> V_8 , V_53 ) ;
}
F_13 ( & V_5 -> V_22 ) ;
}
void F_37 ( struct V_4 * V_5 )
{
F_11 ( & V_5 -> V_22 ) ;
if ( -- V_5 -> V_52 == 0 ) {
unsigned long V_53 ;
F_34 ( & V_5 -> V_8 , V_53 ) ;
V_5 -> V_11 &= ~ V_13 ;
F_35 ( V_5 , V_54 , V_5 -> V_11 ) ;
F_36 ( & V_5 -> V_8 , V_53 ) ;
}
F_13 ( & V_5 -> V_22 ) ;
}
void F_38 ( struct V_4 * V_5 )
{
F_11 ( & V_5 -> V_22 ) ;
if ( V_5 -> V_55 ++ == 0 ) {
unsigned long V_53 ;
F_34 ( & V_5 -> V_8 , V_53 ) ;
F_7 ( V_14 ,
V_5 -> V_9 + V_10 ) ;
V_5 -> V_11 |= V_14 ;
F_35 ( V_5 , V_54 , V_5 -> V_11 ) ;
F_36 ( & V_5 -> V_8 , V_53 ) ;
}
F_13 ( & V_5 -> V_22 ) ;
}
void F_39 ( struct V_4 * V_5 )
{
F_11 ( & V_5 -> V_22 ) ;
if ( -- V_5 -> V_55 == 0 ) {
unsigned long V_53 ;
F_34 ( & V_5 -> V_8 , V_53 ) ;
V_5 -> V_11 &= ~ V_14 ;
F_35 ( V_5 , V_54 , V_5 -> V_11 ) ;
F_36 ( & V_5 -> V_8 , V_53 ) ;
}
F_13 ( & V_5 -> V_22 ) ;
}
int F_40 ( struct V_4 * V_5 ,
bool V_37 , T_3 V_20 ,
bool V_39 , unsigned long V_40 )
{
long V_31 ;
struct V_24 * V_33 = & V_5 -> V_33 ;
if ( F_6 ( V_5 -> V_29 - V_20 < V_32 ) )
return 0 ;
if ( F_6 ( F_17 ( V_5 , V_20 ) ) )
return 0 ;
F_41 ( V_5 , V_56 ) ;
if ( ! ( V_33 -> V_34 & V_35 ) )
return F_19 ( V_5 , V_37 , true , V_20 ,
V_39 , V_40 ) ;
if ( ! ( V_5 -> V_34 & V_57 ) )
return F_19 ( V_5 , V_37 , false , V_20 ,
V_39 , V_40 ) ;
F_33 ( V_5 ) ;
if ( V_39 )
V_31 = F_42
( V_5 -> V_16 ,
F_17 ( V_5 , V_20 ) ,
V_40 ) ;
else
V_31 = F_43
( V_5 -> V_16 ,
F_17 ( V_5 , V_20 ) ,
V_40 ) ;
F_37 ( V_5 ) ;
if ( F_44 ( V_31 == 0 ) )
V_31 = - V_58 ;
else if ( F_6 ( V_31 > 0 ) )
V_31 = 0 ;
return V_31 ;
}
void F_45 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_3 V_6 ;
if ( ! ( V_5 -> V_34 & V_57 ) )
return;
F_46 ( & V_5 -> V_8 ) ;
V_6 = F_4 ( V_5 -> V_9 + V_10 ) ;
F_7 ( V_6 , V_5 -> V_9 + V_10 ) ;
}
int F_47 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_48 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_3 V_6 ;
if ( ! ( V_5 -> V_34 & V_57 ) )
return;
F_11 ( & V_5 -> V_22 ) ;
F_35 ( V_5 , V_54 , 0 ) ;
F_13 ( & V_5 -> V_22 ) ;
V_6 = F_4 ( V_5 -> V_9 + V_10 ) ;
F_7 ( V_6 , V_5 -> V_9 + V_10 ) ;
}
