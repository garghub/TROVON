void F_1 ( T_1 * V_1 , T_1 * V_2 , T_1 * V_3 )
{
T_2 V_4 = V_5 . V_6 ? V_5 . V_7 : V_5 . V_8 ;
if ( V_4 & 0x80 )
V_5 . V_9 ( V_2 , V_1 , V_3 ) ;
else
V_5 . V_9 ( V_1 , V_2 , V_3 ) ;
if ( V_4 & 0x04 )
* V_3 = ~ ( * V_3 ) ;
if ( V_4 & 0x02 )
* V_2 = ~ ( * V_2 ) ;
if ( V_4 & 0x01 )
* V_1 = ~ ( * V_1 ) ;
}
static T_3 F_2 ( struct V_10 * V_11 ,
struct V_12 * V_13 , char * V_14 )
{
T_1 V_1 , V_2 , V_3 ;
F_3 ( & V_5 . V_15 ) ;
F_1 ( & V_1 , & V_2 , & V_3 ) ;
F_4 ( & V_5 . V_15 ) ;
return snprintf ( V_14 , V_16 , L_1 , V_1 , V_2 , V_3 ) ;
}
static void F_5 ( void * V_17 )
{
enum V_18 V_19 = * ( (enum V_18 * ) V_17 ) ;
F_6 ( & V_5 . V_20 ) ;
V_5 . V_21 |= V_19 ;
F_7 ( & V_5 . V_22 ) ;
F_8 ( & V_5 . V_20 ) ;
}
static void F_9 ( struct V_23 * V_24 )
{
unsigned long V_25 ;
T_4 V_26 ;
F_3 ( & V_5 . V_15 ) ;
F_10 ( & V_5 . V_20 , V_25 ) ;
V_26 = V_5 . V_21 ;
if ( V_5 . V_21 & V_27 ) {
if ( V_28 )
F_11 ( V_29 L_2 ) ;
V_5 . V_21 &= ~ V_27 ;
}
if ( V_5 . V_21 & V_30 ) {
if ( V_28 )
F_11 ( V_29 L_3 ) ;
V_5 . V_21 &= ~ V_30 ;
}
F_12 ( & V_5 . V_20 , V_25 ) ;
V_5 . V_31 ( V_26 ) ;
F_4 ( & V_5 . V_15 ) ;
}
int F_13 ( void )
{
int V_32 ;
const T_2 * V_33 ;
V_33 = F_14 ( V_5 . V_34 , L_4 , NULL ) ;
if ( ! V_33 )
return - V_35 ;
V_5 . V_7 = * V_33 ;
V_5 . V_8 = * ( V_33 + 1 ) ;
V_32 = F_15 ( V_5 . V_34 ,
L_5 ,
& V_36 ) ;
if ( V_32 < 0 )
return - V_35 ;
V_5 . V_21 = 0 ;
V_32 = F_15 ( V_5 . V_34 ,
L_6 ,
& V_37 ) ;
if ( V_32 < 0 )
goto V_38;
V_5 . V_39 = F_16 ( V_5 . V_34 , L_7 , NULL ) ;
if ( ! V_5 . V_39 ) {
V_32 = - V_35 ;
goto V_40;
}
V_32 = F_17 ( & V_5 . V_39 -> V_11 , & V_41 ) ;
if ( V_32 )
goto V_42;
V_5 . V_6 = ! ! ( V_5 . V_43 () & 0x10 ) ;
V_32 = F_18 () ;
if ( V_32 )
goto V_44;
return V_32 ;
V_44:
F_19 ( & V_5 . V_39 -> V_11 , & V_41 ) ;
V_42:
F_20 ( V_5 . V_39 ) ;
V_40:
F_21 ( & V_37 ) ;
V_38:
F_21 ( & V_36 ) ;
return V_32 ;
}
int T_5 F_22 ( void )
{
struct V_45 * V_46 ;
F_23 ( & V_5 . V_20 ) ;
F_24 ( & V_5 . V_15 ) ;
F_25 ( & V_5 . V_22 , F_9 ) ;
#ifdef F_26
V_46 = F_27 ( NULL , L_8 ) ;
if ( V_46 && F_28 ( V_46 , L_9 ) )
return F_29 ( V_46 ) ;
#endif
#ifdef F_30
V_46 = F_27 ( NULL , L_10 ) ;
if ( V_46 && F_28 ( V_46 , L_10 ) )
return F_31 ( V_46 ) ;
#endif
return - V_35 ;
}
void F_32 ( void )
{
F_33 () ;
F_19 ( & V_5 . V_39 -> V_11 , & V_41 ) ;
F_34 ( & V_5 . V_22 ) ;
F_20 ( V_5 . V_39 ) ;
F_21 ( & V_37 ) ;
F_21 ( & V_36 ) ;
}
static void T_6 F_35 ( void )
{
V_5 . exit () ;
}
