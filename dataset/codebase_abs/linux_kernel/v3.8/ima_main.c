static int T_1 F_1 ( char * V_1 )
{
if ( strncmp ( V_1 , L_1 , 3 ) == 0 )
V_2 = L_1 ;
return 1 ;
}
static void F_2 ( struct V_3 * V_3 )
{
struct V_4 * V_4 = V_3 -> V_5 . V_4 ;
struct V_6 * V_6 = V_4 -> V_7 ;
T_2 V_8 = V_3 -> V_9 ;
int V_10 ;
bool V_11 = false , V_12 = false ;
unsigned char * V_13 = NULL , * V_14 = NULL ;
if ( ! F_3 ( V_6 -> V_15 ) || ! V_16 )
return;
F_4 ( & V_6 -> V_17 ) ;
if ( V_8 & V_18 ) {
if ( F_5 ( & V_6 -> V_19 ) && F_6 ( V_6 ) )
V_11 = true ;
goto V_20;
}
V_10 = F_7 ( V_6 , V_21 , V_22 ) ;
if ( ! V_10 )
goto V_20;
if ( F_5 ( & V_6 -> V_23 ) > 0 )
V_12 = true ;
V_20:
F_8 ( & V_6 -> V_17 ) ;
if ( ! V_11 && ! V_12 )
return;
V_14 = F_9 ( V_24 + 11 , V_25 ) ;
if ( V_14 ) {
V_13 = F_10 ( & V_3 -> V_5 , V_14 , V_24 + 11 ) ;
if ( F_11 ( V_13 ) )
V_13 = NULL ;
else if ( strlen ( V_13 ) > V_26 )
V_13 = NULL ;
}
if ( V_11 )
F_12 ( V_6 ,
! V_13 ? V_4 -> V_27 . V_28 : V_13 ,
L_2 , L_3 ) ;
if ( V_12 )
F_12 ( V_6 ,
! V_13 ? V_4 -> V_27 . V_28 : V_13 ,
L_2 , L_4 ) ;
F_13 ( V_14 ) ;
}
static void F_14 ( struct V_29 * V_30 ,
struct V_6 * V_6 , struct V_3 * V_3 )
{
T_2 V_8 = V_3 -> V_9 ;
if ( ! ( V_8 & V_18 ) )
return;
F_4 ( & V_6 -> V_17 ) ;
if ( F_5 ( & V_6 -> V_23 ) == 1 &&
V_30 -> V_31 != V_6 -> V_32 ) {
V_30 -> V_33 &= ~ V_34 ;
if ( V_30 -> V_33 & V_35 )
F_15 ( V_30 , V_3 ) ;
}
F_8 ( & V_6 -> V_17 ) ;
}
void F_16 ( struct V_3 * V_3 )
{
struct V_6 * V_6 = V_3 -> V_36 -> V_7 ;
struct V_29 * V_30 ;
if ( ! V_37 || ! F_3 ( V_6 -> V_15 ) )
return;
V_30 = F_17 ( V_6 ) ;
if ( ! V_30 )
return;
F_14 ( V_30 , V_6 , V_3 ) ;
}
static int F_18 ( struct V_3 * V_3 , const unsigned char * V_38 ,
int V_39 , int V_40 )
{
struct V_6 * V_6 = V_3 -> V_36 -> V_7 ;
struct V_29 * V_30 ;
unsigned char * V_13 = NULL , * V_14 = NULL ;
int V_41 = - V_42 , V_43 , V_44 ;
if ( ! V_16 || ! F_3 ( V_6 -> V_15 ) )
return 0 ;
V_43 = F_19 ( V_6 , V_39 , V_40 ) ;
if ( ! V_43 )
return 0 ;
V_44 = V_43 & V_35 ;
F_4 ( & V_6 -> V_17 ) ;
V_30 = F_20 ( V_6 ) ;
if ( ! V_30 )
goto V_20;
V_30 -> V_33 |= V_43 ;
V_43 &= ~ ( ( V_30 -> V_33 & V_34 ) >> 1 ) ;
if ( ! V_43 ) {
if ( V_30 -> V_33 & V_45 )
V_41 = V_30 -> V_46 ;
goto V_20;
}
V_41 = F_21 ( V_30 , V_3 ) ;
if ( V_41 != 0 )
goto V_20;
if ( V_40 != V_47 ) {
V_14 = F_9 ( V_24 + 11 , V_25 ) ;
if ( V_14 ) {
V_13 =
F_10 ( & V_3 -> V_5 , V_14 , V_24 + 11 ) ;
if ( F_11 ( V_13 ) )
V_13 = NULL ;
}
}
if ( V_43 & V_48 )
F_22 ( V_30 , V_3 ,
! V_13 ? V_38 : V_13 ) ;
if ( V_43 & V_35 )
V_41 = F_23 ( V_30 , V_3 ,
! V_13 ? V_38 : V_13 ) ;
if ( V_43 & V_49 )
F_24 ( V_30 , ! V_13 ? V_38 : V_13 ) ;
F_13 ( V_14 ) ;
V_20:
F_8 ( & V_6 -> V_17 ) ;
return ( V_41 && V_44 ) ? - V_50 : 0 ;
}
int F_25 ( struct V_3 * V_3 , unsigned long V_51 )
{
int V_41 = 0 ;
if ( ! V_3 )
return 0 ;
if ( V_51 & V_52 )
V_41 = F_18 ( V_3 , V_3 -> V_36 -> V_27 . V_28 ,
V_53 , V_54 ) ;
return ( V_55 & V_56 ) ? V_41 : 0 ;
}
int F_26 ( struct V_57 * V_58 )
{
int V_41 ;
V_41 = F_18 ( V_58 -> V_3 ,
( strcmp ( V_58 -> V_38 , V_58 -> V_59 ) == 0 ) ?
V_58 -> V_38 : V_58 -> V_59 ,
V_53 , V_47 ) ;
return ( V_55 & V_56 ) ? V_41 : 0 ;
}
int F_27 ( struct V_3 * V_3 , int V_39 )
{
int V_41 ;
F_2 ( V_3 ) ;
V_41 = F_18 ( V_3 , V_3 -> V_36 -> V_27 . V_28 ,
V_39 & ( V_21 | V_60 | V_53 ) ,
V_22 ) ;
return ( V_55 & V_56 ) ? V_41 : 0 ;
}
int F_28 ( struct V_3 * V_3 )
{
int V_41 = 0 ;
if ( ! V_3 ) {
if ( V_55 & V_61 ) {
#ifndef F_29
V_41 = - V_50 ;
#endif
}
} else
V_41 = F_18 ( V_3 , V_3 -> V_36 -> V_27 . V_28 ,
V_53 , V_62 ) ;
return ( V_55 & V_56 ) ? V_41 : 0 ;
}
static int T_1 F_30 ( void )
{
int error ;
error = F_31 () ;
if ( ! error )
V_16 = 1 ;
return error ;
}
