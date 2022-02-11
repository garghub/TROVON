int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 = V_7 ( V_2 ) ;
if ( F_2 ( V_2 ) )
return 0 ;
if ( V_8 ) {
V_6 = V_2 -> V_9 -> V_10 [ V_2 -> V_9 -> V_11 - 1 ] ;
if ( V_8 -> V_12 & V_13 || V_6 -> V_14 . V_12 & V_15 )
return 0 ;
V_6 -> V_16 -> V_17 ( V_6 , V_2 ) ;
V_4 = V_6 -> V_18 -> V_17 ( V_6 , V_2 , V_3 ) ;
if ( V_4 ) {
F_3 ( F_4 ( V_6 ) , V_19 ) ;
return V_4 ;
}
F_5 ( V_2 , V_2 -> V_20 - F_6 ( V_2 ) ) ;
}
return 0 ;
}
int F_7 ( struct V_21 * V_21 , struct V_5 * V_6 ,
struct V_22 * V_23 )
{
int V_4 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
struct V_28 * V_14 = & V_6 -> V_14 ;
T_2 * V_29 ;
T_2 * V_30 ;
if ( ! V_6 -> V_18 )
return 0 ;
if ( V_6 -> V_31 || V_6 -> V_32 || ( V_6 -> V_33 . V_12 & V_34 ) )
return 0 ;
V_27 = F_8 ( V_21 , V_23 -> V_35 ) ;
if ( ! V_27 ) {
if ( ! ( V_23 -> V_12 & V_15 ) ) {
V_29 = & V_6 -> V_33 . V_29 ;
V_30 = & V_6 -> V_36 . V_30 ;
} else {
V_29 = & V_6 -> V_36 . V_30 ;
V_30 = & V_6 -> V_33 . V_29 ;
}
V_25 = F_9 ( V_21 , 0 , 0 , V_29 , V_30 , V_6 -> V_33 . V_37 ) ;
if ( F_10 ( V_25 ) )
return 0 ;
V_27 = V_25 -> V_27 ;
F_11 ( V_27 ) ;
F_12 ( V_25 ) ;
}
if ( ! V_27 -> V_38 || ! V_27 -> V_38 -> V_39 ) {
F_13 ( V_27 ) ;
return 0 ;
}
V_14 -> V_27 = V_27 ;
V_14 -> V_40 = 1 ;
V_14 -> V_12 = V_23 -> V_12 ;
V_4 = V_27 -> V_38 -> V_39 ( V_6 ) ;
if ( V_4 ) {
F_13 ( V_27 ) ;
return V_4 ;
}
return 0 ;
}
bool F_14 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
int V_41 ;
struct V_24 * V_25 = F_15 ( V_2 ) ;
struct V_42 * V_43 = (struct V_42 * ) V_25 ;
struct V_26 * V_27 = V_6 -> V_14 . V_27 ;
if ( ! V_6 -> V_18 || V_6 -> V_31 )
return false ;
if ( ( V_6 -> V_14 . V_44 && ( V_27 == V_25 -> V_45 -> V_27 ) ) &&
! V_25 -> V_46 -> V_47 && V_6 -> type -> V_48 ) {
V_41 = V_6 -> type -> V_48 ( V_6 , V_43 -> V_49 ) ;
if ( V_2 -> V_11 <= V_41 )
goto V_50;
if ( F_2 ( V_2 ) && F_16 ( V_2 , V_41 ) )
goto V_50;
}
return false ;
V_50:
if ( V_27 && V_27 -> V_38 && V_27 -> V_38 -> V_51 )
return V_6 -> V_14 . V_27 -> V_38 -> V_51 ( V_2 , V_6 ) ;
return true ;
}
static int F_17 ( struct V_26 * V_27 )
{
if ( ( V_27 -> V_3 & V_52 ) && ! V_27 -> V_38 )
return V_53 ;
if ( ( V_27 -> V_3 & V_54 ) &&
! ( V_27 -> V_3 & V_52 ) )
return V_53 ;
return V_55 ;
}
static int F_18 ( struct V_26 * V_27 )
{
return V_55 ;
}
static int F_19 ( struct V_26 * V_27 )
{
if ( ( V_27 -> V_3 & V_52 ) && ! V_27 -> V_38 )
return V_53 ;
else if ( ! ( V_27 -> V_3 & V_52 ) )
V_27 -> V_38 = NULL ;
if ( ( V_27 -> V_3 & V_54 ) &&
! ( V_27 -> V_3 & V_52 ) )
return V_53 ;
return V_55 ;
}
static int F_20 ( struct V_26 * V_27 )
{
if ( V_27 -> V_3 & V_52 )
F_21 ( F_22 ( V_27 ) , V_27 , true ) ;
F_23 ( F_22 ( V_27 ) ) ;
return V_55 ;
}
static int F_24 ( struct V_56 * V_57 , unsigned long V_58 , void * V_59 )
{
struct V_26 * V_27 = F_25 ( V_59 ) ;
switch ( V_58 ) {
case V_60 :
return F_17 ( V_27 ) ;
case V_61 :
return F_18 ( V_27 ) ;
case V_62 :
return F_19 ( V_27 ) ;
case V_63 :
return F_20 ( V_27 ) ;
}
return V_55 ;
}
void T_3 F_26 ( void )
{
F_27 ( & V_64 ) ;
}
