bool F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
int V_4 ;
T_1 V_5 ;
T_2 V_6 , V_7 ;
if ( V_3 )
return false ;
if ( ! F_2 ( V_8 ) )
return false ;
if ( ! F_3 () )
return false ;
if ( F_4 ( V_2 ) )
return false ;
V_4 = F_5 ( V_2 , & V_6 , & V_5 , & V_7 ) ;
if ( V_4 )
return false ;
return true ;
}
static int F_6 ( void )
{
T_2 V_9 , V_10 ;
T_3 V_11 ;
V_11 = V_12 + ( 1ull << V_13 ) ;
V_9 = ( T_2 ) F_7 ( V_11 , V_14 ) ;
if ( ! V_9 )
return - V_15 ;
V_10 = ( V_9 + ( 1ull << V_13 ) - 1 ) &
( ~ 0ull << V_13 ) ;
F_8 ( ( V_10 + V_12 ) > ( V_9 + V_11 ) ,
L_1 ) ;
V_16 = F_9 ( ( void * ) V_10 ) ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
int V_4 ;
T_1 V_5 ;
T_2 V_6 , V_7 ;
if ( ! F_2 ( V_8 ) )
return - V_19 ;
F_11 ( & V_20 ) ;
if ( V_16 == V_21 ) {
V_4 = F_6 () ;
if ( V_4 ) {
F_12 ( & V_20 ) ;
return V_4 ;
}
}
F_12 ( & V_20 ) ;
V_4 = F_5 ( V_2 , & V_6 , & V_5 , & V_7 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_13 ( V_7 , & V_18 -> V_22 ) ;
if ( V_4 )
return V_4 ;
if ( F_2 ( V_23 ) ) {
V_18 -> V_22 |= ( ( T_2 ) 0x02 << ( 63 - 47 ) ) ;
}
V_18 -> V_24 = V_25 ;
V_18 -> V_26 = V_27 ;
V_18 -> V_28 = V_29 ;
V_18 -> V_30 = V_16 ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 , enum V_31 V_32 ,
unsigned long V_3 )
{
int V_4 = 0 ;
if ( ! F_2 ( V_8 ) )
return - V_19 ;
switch ( V_32 ) {
case V_33 :
V_4 = F_15 ( V_2 , V_34 ) ;
if ( V_4 )
V_4 = - V_35 ;
else
V_4 = - V_36 ;
break;
case V_37 :
if ( V_3 != V_38 )
return - V_19 ;
V_4 = F_15 ( V_2 , V_39 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_15 ( V_2 , V_40 ) ;
break;
default:
V_4 = - V_19 ;
}
return V_4 ;
}
int F_16 ( struct V_1 * V_2 , unsigned long V_3 )
{
int V_4 ;
if ( V_3 )
return - V_19 ;
V_4 = F_17 ( & V_2 -> V_2 , F_18 ( 64 ) ) ;
return V_4 ;
}
int F_19 ( struct V_41 * V_42 ,
unsigned long V_43 ,
struct V_44 * V_45 )
{
struct V_46 * V_47 = NULL ;
if ( V_43 != V_48 &&
V_43 != V_49 )
return - V_19 ;
V_45 -> V_50 = F_20 ( false ,
V_42 == NULL ,
V_43 == V_49 ,
true ) ;
V_45 -> V_51 = F_21 ( V_52 ) ;
if ( V_42 ) {
V_47 = F_22 ( V_42 ) ;
if ( V_47 == NULL )
return - V_19 ;
V_45 -> V_53 = V_47 -> V_54 . V_55 ;
F_23 ( V_47 ) ;
} else {
V_45 -> V_53 = 0 ;
}
V_45 -> V_56 = 0 ;
return 0 ;
}
int F_24 ( struct V_46 * V_47 , T_2 V_57 , T_2 V_58 , T_2 V_3 )
{
int V_4 ;
T_2 V_59 ;
struct V_60 * V_61 = NULL ;
unsigned long V_62 ;
if ( V_47 == NULL )
return - V_63 ;
F_25 ( & V_47 -> V_64 ) ;
V_61 = F_26 ( V_47 , V_57 ) ;
if ( ! V_61 ) {
F_27 ( L_2 , V_57 ) ;
V_4 = - V_63 ;
goto V_65;
}
V_62 = F_28 ( V_61 ) ;
for ( V_59 = ( V_57 & ~ ( V_62 - 1 ) ) ; V_59 < ( V_57 + V_58 ) ; V_59 += V_62 ) {
if ( V_59 < V_61 -> V_66 || V_59 >= V_61 -> V_67 ) {
V_61 = F_26 ( V_47 , V_57 ) ;
if ( ! V_61 ) {
F_27 ( L_2 , V_57 ) ;
V_4 = - V_63 ;
goto V_65;
}
V_62 = F_28 ( V_61 ) ;
}
V_4 = F_29 ( V_47 , V_3 , V_59 ) ;
if ( V_4 ) {
F_27 ( L_3 , V_4 ) ;
V_4 = - V_63 ;
goto V_65;
}
}
V_4 = 0 ;
V_65:
F_30 ( & V_47 -> V_64 ) ;
return V_4 ;
}
