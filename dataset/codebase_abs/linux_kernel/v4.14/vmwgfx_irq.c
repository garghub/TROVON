static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_1 V_7 = V_8 ;
if ( F_3 ( V_9 ,
V_6 -> V_10 ) ) {
F_4 ( V_6 -> V_11 ) ;
F_5 ( & V_6 -> V_12 ) ;
V_7 = V_13 ;
}
if ( F_3 ( V_14 ,
V_6 -> V_10 ) ) {
F_6 ( V_6 -> V_15 ) ;
V_7 = V_13 ;
}
return V_7 ;
}
static T_1 F_7 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_2 V_16 , V_17 ;
T_1 V_7 = V_13 ;
V_16 = F_8 ( V_6 -> V_18 + V_19 ) ;
V_17 = V_16 & F_9 ( V_6 -> V_20 ) ;
if ( F_10 ( V_16 ) )
F_11 ( V_16 , V_6 -> V_18 + V_19 ) ;
if ( ! V_16 )
return V_8 ;
if ( V_17 & V_21 )
F_5 ( & V_6 -> V_22 ) ;
if ( ( V_17 & ( V_23 |
V_24 ) ) &&
! F_12 ( V_9 , V_6 -> V_10 ) )
V_7 = V_25 ;
if ( ( V_17 & ( V_26 |
V_27 ) ) &&
! F_12 ( V_14 ,
V_6 -> V_10 ) )
V_7 = V_25 ;
return V_7 ;
}
static bool F_13 ( struct V_5 * V_6 , T_2 V_28 )
{
return ( F_14 ( V_6 , V_29 ) == 0 ) ;
}
void F_15 ( struct V_5 * V_6 ,
struct V_30 * V_31 )
{
T_3 * V_32 = V_6 -> V_33 ;
T_2 V_28 = F_16 ( V_32 + V_34 ) ;
if ( V_6 -> V_35 != V_28 ) {
V_6 -> V_35 = V_28 ;
F_17 ( & V_31 -> V_36 , V_28 ) ;
F_4 ( V_6 -> V_11 ) ;
}
}
bool F_18 ( struct V_5 * V_6 ,
T_2 V_28 )
{
struct V_30 * V_31 ;
bool V_7 ;
if ( F_10 ( V_6 -> V_35 - V_28 < V_37 ) )
return true ;
V_31 = & V_6 -> V_38 ;
F_15 ( V_6 , V_31 ) ;
if ( F_10 ( V_6 -> V_35 - V_28 < V_37 ) )
return true ;
if ( ! ( V_31 -> V_39 & V_40 ) &&
F_13 ( V_6 , V_28 ) )
return true ;
V_7 = ( ( F_19 ( & V_6 -> V_41 ) - V_28 )
> V_37 ) ;
return V_7 ;
}
int F_20 ( struct V_5 * V_6 ,
bool V_42 ,
bool V_43 ,
T_2 V_28 ,
bool V_44 ,
unsigned long V_45 )
{
struct V_30 * V_31 = & V_6 -> V_38 ;
T_2 V_46 = 0 ;
T_2 V_47 ;
int V_7 ;
unsigned long V_48 = V_49 + V_45 ;
bool (* F_21)( struct V_5 * , T_2 );
F_22 ( V_50 ) ;
F_21 = ( V_43 ) ? & F_13 :
& F_18 ;
if ( V_43 ) {
F_23 ( & V_31 -> V_51 ) ;
if ( V_6 -> V_15 ) {
V_7 = F_24 ( V_6 -> V_15 , V_44 ,
10 * V_52 ) ;
if ( V_7 )
goto V_53;
}
}
V_47 = F_19 ( & V_6 -> V_41 ) ;
V_7 = 0 ;
for (; ; ) {
F_25 ( & V_6 -> V_12 , & V_50 ,
( V_44 ) ?
V_54 : V_55 ) ;
if ( F_21 ( V_6 , V_28 ) )
break;
if ( F_26 ( V_49 , V_48 ) ) {
F_27 ( L_1 ) ;
break;
}
if ( V_42 )
F_28 ( 1 ) ;
else if ( ( ++ V_46 & 0x0F ) == 0 ) {
F_29 ( V_56 ) ;
F_30 () ;
F_29 ( ( V_44 ) ?
V_54 :
V_55 ) ;
}
if ( V_44 && F_31 ( V_57 ) ) {
V_7 = - V_58 ;
break;
}
}
F_32 ( & V_6 -> V_12 , & V_50 ) ;
if ( V_7 == 0 && V_43 ) {
T_3 * V_32 = V_6 -> V_33 ;
F_33 ( V_47 , V_32 + V_34 ) ;
}
F_5 ( & V_6 -> V_12 ) ;
V_53:
if ( V_43 )
F_34 ( & V_31 -> V_51 ) ;
return V_7 ;
}
void F_35 ( struct V_5 * V_6 ,
T_3 V_59 , int * V_60 )
{
F_36 ( & V_6 -> V_61 ) ;
if ( ( * V_60 ) ++ == 0 ) {
F_11 ( V_59 , V_6 -> V_18 + V_19 ) ;
V_6 -> V_20 |= V_59 ;
F_37 ( V_6 , V_62 , V_6 -> V_20 ) ;
}
F_38 ( & V_6 -> V_61 ) ;
}
void F_39 ( struct V_5 * V_6 ,
T_3 V_59 , int * V_60 )
{
F_36 ( & V_6 -> V_61 ) ;
if ( -- ( * V_60 ) == 0 ) {
V_6 -> V_20 &= ~ V_59 ;
F_37 ( V_6 , V_62 , V_6 -> V_20 ) ;
}
F_38 ( & V_6 -> V_61 ) ;
}
void F_40 ( struct V_5 * V_6 )
{
F_35 ( V_6 , V_23 ,
& V_6 -> V_63 ) ;
}
void F_41 ( struct V_5 * V_6 )
{
F_39 ( V_6 , V_23 ,
& V_6 -> V_63 ) ;
}
void F_42 ( struct V_5 * V_6 )
{
F_35 ( V_6 , V_24 ,
& V_6 -> V_64 ) ;
}
void F_43 ( struct V_5 * V_6 )
{
F_39 ( V_6 , V_24 ,
& V_6 -> V_64 ) ;
}
int F_44 ( struct V_5 * V_6 ,
bool V_42 , T_2 V_28 ,
bool V_44 , unsigned long V_45 )
{
long V_7 ;
struct V_30 * V_38 = & V_6 -> V_38 ;
if ( F_10 ( V_6 -> V_35 - V_28 < V_37 ) )
return 0 ;
if ( F_10 ( F_18 ( V_6 , V_28 ) ) )
return 0 ;
F_45 ( V_6 , V_65 ) ;
if ( ! ( V_38 -> V_39 & V_40 ) )
return F_20 ( V_6 , V_42 , true , V_28 ,
V_44 , V_45 ) ;
if ( ! ( V_6 -> V_39 & V_66 ) )
return F_20 ( V_6 , V_42 , false , V_28 ,
V_44 , V_45 ) ;
F_40 ( V_6 ) ;
if ( V_44 )
V_7 = F_46
( V_6 -> V_12 ,
F_18 ( V_6 , V_28 ) ,
V_45 ) ;
else
V_7 = F_47
( V_6 -> V_12 ,
F_18 ( V_6 , V_28 ) ,
V_45 ) ;
F_41 ( V_6 ) ;
if ( F_48 ( V_7 == 0 ) )
V_7 = - V_67 ;
else if ( F_10 ( V_7 > 0 ) )
V_7 = 0 ;
return V_7 ;
}
static void F_49 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_2 V_16 ;
V_16 = F_8 ( V_6 -> V_18 + V_19 ) ;
F_11 ( V_16 , V_6 -> V_18 + V_19 ) ;
}
void F_50 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_2 V_16 ;
if ( ! ( V_6 -> V_39 & V_66 ) )
return;
if ( ! V_4 -> V_68 )
return;
F_37 ( V_6 , V_62 , 0 ) ;
V_16 = F_8 ( V_6 -> V_18 + V_19 ) ;
F_11 ( V_16 , V_6 -> V_18 + V_19 ) ;
V_4 -> V_68 = false ;
F_51 ( V_4 -> V_1 , V_4 ) ;
}
int F_52 ( struct V_3 * V_4 , int V_1 )
{
int V_7 ;
if ( V_4 -> V_68 )
return - V_67 ;
F_49 ( V_4 ) ;
V_7 = F_53 ( V_1 , F_7 , F_1 ,
V_69 , V_70 , V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
V_4 -> V_68 = true ;
V_4 -> V_1 = V_1 ;
return V_7 ;
}
