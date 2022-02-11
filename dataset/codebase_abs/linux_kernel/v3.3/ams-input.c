static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 , V_7 , V_8 ;
F_2 ( & V_9 . V_10 ) ;
F_3 ( & V_6 , & V_7 , & V_8 ) ;
V_6 -= V_9 . V_11 ;
V_7 -= V_9 . V_12 ;
V_8 -= V_9 . V_13 ;
F_4 ( V_4 , V_14 , V_15 ? - V_6 : V_6 ) ;
F_4 ( V_4 , V_16 , V_15 ? - V_7 : V_7 ) ;
F_4 ( V_4 , V_17 , V_8 ) ;
F_5 ( V_4 ) ;
F_6 ( & V_9 . V_10 ) ;
}
static int F_7 ( void )
{
struct V_3 * V_5 ;
T_1 V_6 , V_7 , V_8 ;
int error ;
F_3 ( & V_6 , & V_7 , & V_8 ) ;
V_9 . V_11 = V_6 ;
V_9 . V_12 = V_7 ;
V_9 . V_13 = V_8 ;
V_9 . V_4 = F_8 () ;
if ( ! V_9 . V_4 )
return - V_18 ;
V_9 . V_4 -> V_19 = F_1 ;
V_9 . V_4 -> V_20 = 25 ;
V_5 = V_9 . V_4 -> V_5 ;
V_5 -> V_21 = L_1 ;
V_5 -> V_22 . V_23 = V_9 . V_23 ;
V_5 -> V_22 . V_24 = 0 ;
V_5 -> V_2 . V_25 = & V_9 . V_26 -> V_2 ;
F_9 ( V_5 , V_14 , - 50 , 50 , 3 , 0 ) ;
F_9 ( V_5 , V_16 , - 50 , 50 , 3 , 0 ) ;
F_9 ( V_5 , V_17 , - 50 , 50 , 3 , 0 ) ;
F_10 ( V_27 , V_5 -> V_28 ) ;
F_10 ( V_29 , V_5 -> V_28 ) ;
F_10 ( V_30 , V_5 -> V_31 ) ;
error = F_11 ( V_9 . V_4 ) ;
if ( error ) {
F_12 ( V_9 . V_4 ) ;
V_9 . V_4 = NULL ;
return error ;
}
V_32 = 1 ;
return 0 ;
}
static void F_13 ( void )
{
if ( V_9 . V_4 ) {
F_14 ( V_9 . V_4 ) ;
F_12 ( V_9 . V_4 ) ;
V_9 . V_4 = NULL ;
}
V_32 = 0 ;
}
static T_2 F_15 ( struct V_33 * V_2 ,
struct V_34 * V_35 , char * V_36 )
{
return sprintf ( V_36 , L_2 , V_32 ) ;
}
static T_2 F_16 ( struct V_33 * V_2 ,
struct V_34 * V_35 , const char * V_36 , T_3 V_37 )
{
unsigned long V_38 ;
int error = 0 ;
if ( F_17 ( V_36 , 0 , & V_38 ) || V_38 > 1 )
return - V_39 ;
F_2 ( & V_40 ) ;
if ( V_38 != V_32 ) {
if ( V_38 )
error = F_7 () ;
else
F_13 () ;
}
F_6 ( & V_40 ) ;
return error ? error : V_37 ;
}
int F_18 ( void )
{
if ( V_32 )
F_7 () ;
return F_19 ( & V_9 . V_26 -> V_2 , & V_41 ) ;
}
void F_20 ( void )
{
F_21 ( & V_9 . V_26 -> V_2 , & V_41 ) ;
F_2 ( & V_40 ) ;
F_13 () ;
F_6 ( & V_40 ) ;
}
