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
char * V_13 = NULL ;
const char * V_14 ;
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
V_14 = F_9 ( & V_3 -> V_5 , & V_13 ) ;
if ( ! V_14 || strlen ( V_14 ) > V_24 )
V_14 = V_4 -> V_25 . V_26 ;
if ( V_11 )
F_10 ( V_6 , V_14 ,
L_2 , L_3 ) ;
if ( V_12 )
F_10 ( V_6 , V_14 ,
L_2 , L_4 ) ;
F_11 ( V_13 ) ;
}
static void F_12 ( struct V_27 * V_28 ,
struct V_6 * V_6 , struct V_3 * V_3 )
{
T_2 V_8 = V_3 -> V_9 ;
if ( ! ( V_8 & V_18 ) )
return;
F_4 ( & V_6 -> V_17 ) ;
if ( F_5 ( & V_6 -> V_23 ) == 1 &&
V_28 -> V_29 != V_6 -> V_30 ) {
V_28 -> V_31 &= ~ V_32 ;
if ( V_28 -> V_31 & V_33 )
F_13 ( V_28 , V_3 ) ;
}
F_8 ( & V_6 -> V_17 ) ;
}
void F_14 ( struct V_3 * V_3 )
{
struct V_6 * V_6 = F_15 ( V_3 ) ;
struct V_27 * V_28 ;
if ( ! V_34 || ! F_3 ( V_6 -> V_15 ) )
return;
V_28 = F_16 ( V_6 ) ;
if ( ! V_28 )
return;
F_12 ( V_28 , V_6 , V_3 ) ;
}
static int F_17 ( struct V_3 * V_3 , const char * V_35 ,
int V_36 , int V_37 )
{
struct V_6 * V_6 = F_15 ( V_3 ) ;
struct V_27 * V_28 ;
char * V_13 = NULL ;
const char * V_14 = NULL ;
int V_38 = - V_39 , V_40 , V_41 , V_42 ;
if ( ! V_16 || ! F_3 ( V_6 -> V_15 ) )
return 0 ;
V_40 = F_18 ( V_6 , V_36 , V_37 ) ;
if ( ! V_40 )
return 0 ;
V_41 = V_40 & V_33 ;
V_42 = ( V_40 & V_43 ) ? V_22 : V_37 ;
F_4 ( & V_6 -> V_17 ) ;
V_28 = F_19 ( V_6 ) ;
if ( ! V_28 )
goto V_20;
V_28 -> V_31 |= V_40 ;
V_40 &= V_44 ;
V_40 &= ~ ( ( V_28 -> V_31 & V_32 ) >> 1 ) ;
if ( ! V_40 ) {
if ( V_41 )
V_38 = F_20 ( V_28 , V_42 ) ;
goto V_45;
}
V_38 = F_21 ( V_28 , V_3 ) ;
if ( V_38 != 0 )
goto V_45;
if ( V_37 != V_46 )
V_14 = F_9 ( & V_3 -> V_5 , & V_13 ) ;
if ( ! V_14 )
V_14 = V_35 ;
if ( V_40 & V_47 )
F_22 ( V_28 , V_3 , V_14 ) ;
if ( V_40 & V_48 )
V_38 = F_23 ( V_42 , V_28 , V_3 , V_14 ) ;
if ( V_40 & V_49 )
F_24 ( V_28 , V_14 ) ;
F_11 ( V_13 ) ;
V_45:
if ( ( V_36 & V_50 ) && ( V_28 -> V_31 & V_51 ) )
V_38 = - V_52 ;
V_20:
F_8 ( & V_6 -> V_17 ) ;
if ( ( V_38 && V_41 ) && ( V_53 & V_54 ) )
return - V_52 ;
return 0 ;
}
int F_25 ( struct V_3 * V_3 , unsigned long V_55 )
{
if ( V_3 && ( V_55 & V_56 ) )
return F_17 ( V_3 , V_3 -> V_57 -> V_25 . V_26 ,
V_58 , V_59 ) ;
return 0 ;
}
int F_26 ( struct V_60 * V_61 )
{
return F_17 ( V_61 -> V_3 ,
( strcmp ( V_61 -> V_35 , V_61 -> V_62 ) == 0 ) ?
V_61 -> V_35 : V_61 -> V_62 ,
V_58 , V_46 ) ;
}
int F_27 ( struct V_3 * V_3 , int V_36 )
{
F_2 ( V_3 ) ;
return F_17 ( V_3 , V_3 -> V_57 -> V_25 . V_26 ,
V_36 & ( V_21 | V_50 | V_58 ) ,
V_22 ) ;
}
int F_28 ( struct V_3 * V_3 )
{
if ( ! V_3 ) {
#ifndef F_29
if ( ( V_53 & V_63 ) &&
( V_53 & V_54 ) )
return - V_52 ;
#endif
return 0 ;
}
return F_17 ( V_3 , V_3 -> V_57 -> V_25 . V_26 ,
V_58 , V_64 ) ;
}
static int T_1 F_30 ( void )
{
int error ;
error = F_31 () ;
if ( ! error )
V_16 = 1 ;
return error ;
}
