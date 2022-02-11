static int T_1 F_1 ( char * V_1 )
{
if ( strncmp ( V_1 , L_1 , 3 ) == 0 )
V_2 = L_1 ;
return 1 ;
}
static void F_2 ( struct V_3 * V_3 )
{
struct V_4 * V_4 = V_3 -> V_5 . V_4 ;
struct V_6 * V_6 = F_3 ( V_3 ) ;
T_2 V_7 = V_3 -> V_8 ;
int V_9 ;
bool V_10 = false , V_11 = false ;
char * V_12 = NULL ;
const char * V_13 ;
if ( ! F_4 ( V_6 -> V_14 ) || ! V_15 )
return;
F_5 ( & V_6 -> V_16 ) ;
if ( V_7 & V_17 ) {
if ( F_6 ( & V_6 -> V_18 ) && F_7 ( V_6 ) )
V_10 = true ;
goto V_19;
}
V_9 = F_8 ( V_6 , V_20 , V_21 ) ;
if ( ! V_9 )
goto V_19;
if ( F_6 ( & V_6 -> V_22 ) > 0 )
V_11 = true ;
V_19:
F_9 ( & V_6 -> V_16 ) ;
if ( ! V_10 && ! V_11 )
return;
V_13 = F_10 ( & V_3 -> V_5 , & V_12 ) ;
if ( ! V_13 || strlen ( V_13 ) > V_23 )
V_13 = V_4 -> V_24 . V_25 ;
if ( V_10 )
F_11 ( V_6 , V_13 ,
L_2 , L_3 ) ;
if ( V_11 )
F_11 ( V_6 , V_13 ,
L_2 , L_4 ) ;
F_12 ( V_12 ) ;
}
static void F_13 ( struct V_26 * V_27 ,
struct V_6 * V_6 , struct V_3 * V_3 )
{
T_2 V_7 = V_3 -> V_8 ;
if ( ! ( V_7 & V_17 ) )
return;
F_5 ( & V_6 -> V_16 ) ;
if ( F_6 ( & V_6 -> V_22 ) == 1 &&
V_27 -> V_28 != V_6 -> V_29 ) {
V_27 -> V_30 &= ~ V_31 ;
if ( V_27 -> V_30 & V_32 )
F_14 ( V_27 , V_3 ) ;
}
F_9 ( & V_6 -> V_16 ) ;
}
void F_15 ( struct V_3 * V_3 )
{
struct V_6 * V_6 = F_3 ( V_3 ) ;
struct V_26 * V_27 ;
if ( ! V_33 || ! F_4 ( V_6 -> V_14 ) )
return;
V_27 = F_16 ( V_6 ) ;
if ( ! V_27 )
return;
F_13 ( V_27 , V_6 , V_3 ) ;
}
static int F_17 ( struct V_3 * V_3 , const char * V_34 ,
int V_35 , int V_36 )
{
struct V_6 * V_6 = F_3 ( V_3 ) ;
struct V_26 * V_27 ;
char * V_12 = NULL ;
const char * V_13 = NULL ;
int V_37 = - V_38 , V_39 , V_40 , V_41 ;
if ( ! V_15 || ! F_4 ( V_6 -> V_14 ) )
return 0 ;
V_39 = F_18 ( V_6 , V_35 , V_36 ) ;
if ( ! V_39 )
return 0 ;
V_40 = V_39 & V_32 ;
V_41 = ( V_39 & V_42 ) ? V_21 : V_36 ;
F_5 ( & V_6 -> V_16 ) ;
V_27 = F_19 ( V_6 ) ;
if ( ! V_27 )
goto V_19;
V_27 -> V_30 |= V_39 ;
V_39 &= V_43 ;
V_39 &= ~ ( ( V_27 -> V_30 & V_31 ) >> 1 ) ;
if ( ! V_39 ) {
if ( V_40 )
V_37 = F_20 ( V_27 , V_41 ) ;
goto V_44;
}
V_37 = F_21 ( V_27 , V_3 ) ;
if ( V_37 != 0 )
goto V_44;
V_13 = ! V_34 ? F_10 ( & V_3 -> V_5 , & V_12 ) : V_34 ;
if ( ! V_13 )
V_13 = ( const char * ) V_3 -> V_45 -> V_24 . V_25 ;
if ( V_39 & V_46 )
F_22 ( V_27 , V_3 , V_13 ) ;
if ( V_39 & V_47 )
V_37 = F_23 ( V_41 , V_27 , V_3 , V_13 ) ;
if ( V_39 & V_48 )
F_24 ( V_27 , V_13 ) ;
F_12 ( V_12 ) ;
V_44:
if ( ( V_35 & V_49 ) && ( V_27 -> V_30 & V_50 ) )
V_37 = - V_51 ;
V_19:
F_9 ( & V_6 -> V_16 ) ;
if ( ( V_37 && V_40 ) && ( V_52 & V_53 ) )
return - V_51 ;
return 0 ;
}
int F_25 ( struct V_3 * V_3 , unsigned long V_54 )
{
if ( V_3 && ( V_54 & V_55 ) )
return F_17 ( V_3 , NULL , V_56 , V_57 ) ;
return 0 ;
}
int F_26 ( struct V_58 * V_59 )
{
return F_17 ( V_59 -> V_3 ,
( strcmp ( V_59 -> V_34 , V_59 -> V_60 ) == 0 ) ?
V_59 -> V_34 : V_59 -> V_60 ,
V_56 , V_61 ) ;
}
int F_27 ( struct V_3 * V_3 , int V_35 )
{
F_2 ( V_3 ) ;
return F_17 ( V_3 , NULL ,
V_35 & ( V_20 | V_49 | V_56 ) ,
V_21 ) ;
}
int F_28 ( struct V_3 * V_3 )
{
if ( ! V_3 ) {
#ifndef F_29
if ( ( V_52 & V_62 ) &&
( V_52 & V_53 ) )
return - V_51 ;
#endif
return 0 ;
}
return F_17 ( V_3 , NULL , V_56 , V_63 ) ;
}
static int T_1 F_30 ( void )
{
int error ;
error = F_31 () ;
if ( ! error )
V_15 = 1 ;
return error ;
}
