static int F_1 ( void )
{
int V_1 ;
V_1 = F_2 ( V_2 -> V_3 ) ;
if ( V_1 )
goto V_4;
V_1 = F_2 ( V_2 -> V_5 ) ;
if ( V_1 )
goto V_6;
V_1 = F_2 ( V_2 -> V_7 ) ;
if ( V_1 )
goto V_8;
return 0 ;
V_8:
F_3 ( V_2 -> V_5 ) ;
V_6:
F_3 ( V_2 -> V_3 ) ;
V_4:
return V_1 ;
}
static void F_4 ( void )
{
F_3 ( V_2 -> V_3 ) ;
F_3 ( V_2 -> V_5 ) ;
F_3 ( V_2 -> V_7 ) ;
}
int F_5 ( void * V_9 , const T_1 * V_10 )
{
return F_6 ( V_9 , V_10 ) ;
}
int F_7 ( void * V_9 , const T_1 * V_10 )
{
return F_8 ( V_2 -> V_11 , V_9 , V_10 ) ;
}
void F_9 ( T_2 V_12 )
{
F_10 ( V_12 ) ;
}
bool F_11 ( void )
{
int V_1 = F_1 () ;
if ( V_1 )
return V_1 ;
V_1 = F_12 ( V_2 -> V_11 , V_13 ,
V_14 ) ;
F_4 () ;
return V_1 > 0 ? true : false ;
}
int F_13 ( struct F_13 * V_15 , T_2 V_16 , T_2 * V_17 )
{
int V_1 = F_1 () ;
if ( V_1 )
return V_1 ;
V_1 = F_14 ( V_2 -> V_11 , V_15 , V_16 , V_17 ) ;
F_4 () ;
return V_1 ;
}
bool F_15 ( T_2 V_18 )
{
int V_1 ;
V_1 = F_12 ( V_2 -> V_11 , V_19 ,
V_20 ) ;
if ( V_1 <= 0 )
return false ;
return F_16 ( V_2 -> V_11 , V_18 ) ;
}
int F_17 ( T_2 V_18 , const void * V_21 , T_3 V_22 )
{
T_4 V_23 ;
void * V_24 ;
int V_1 ;
V_24 = F_18 ( V_2 -> V_11 , V_22 , & V_23 ,
V_25 ) ;
if ( ! V_24 ) {
F_19 ( V_2 -> V_11 , L_1 ) ;
return - V_26 ;
}
memcpy ( V_24 , V_21 , V_22 ) ;
V_1 = F_1 () ;
if ( V_1 )
goto V_27;
V_1 = F_20 ( V_2 -> V_11 , V_18 , V_23 ) ;
F_4 () ;
V_27:
F_21 ( V_2 -> V_11 , V_22 , V_24 , V_23 ) ;
return V_1 ;
}
int F_22 ( T_2 V_18 , T_5 V_28 , T_5 V_22 )
{
int V_1 ;
V_1 = F_1 () ;
if ( V_1 )
return V_1 ;
V_1 = F_23 ( V_2 -> V_11 , V_18 , V_28 , V_22 ) ;
F_4 () ;
return V_1 ;
}
int F_24 ( T_2 V_18 )
{
int V_1 ;
V_1 = F_1 () ;
if ( V_1 )
return V_1 ;
V_1 = F_25 ( V_2 -> V_11 , V_18 ) ;
F_4 () ;
return V_1 ;
}
int F_26 ( T_2 V_18 )
{
int V_1 ;
V_1 = F_1 () ;
if ( V_1 )
return V_1 ;
V_1 = F_27 ( V_2 -> V_11 , V_18 ) ;
F_4 () ;
return V_1 ;
}
static int F_28 ( struct V_29 * V_30 ,
unsigned long V_31 )
{
if ( V_31 != 0 )
return - V_32 ;
return F_29 ( V_2 -> V_11 , 1 ) ;
}
static int F_30 ( struct V_29 * V_30 ,
unsigned long V_31 )
{
if ( V_31 != 0 )
return - V_32 ;
return F_29 ( V_2 -> V_11 , 0 ) ;
}
bool F_31 ( void )
{
return ! ! V_2 ;
}
static int F_32 ( struct V_33 * V_34 )
{
struct V_35 * V_36 ;
int V_1 ;
V_36 = F_33 ( & V_34 -> V_11 , sizeof( * V_36 ) , V_25 ) ;
if ( ! V_36 )
return - V_26 ;
V_36 -> V_3 = F_34 ( & V_34 -> V_11 , L_2 ) ;
if ( F_35 ( V_36 -> V_3 ) ) {
if ( F_36 ( V_36 -> V_3 ) == - V_37 )
return F_36 ( V_36 -> V_3 ) ;
V_36 -> V_3 = NULL ;
}
if ( F_37 ( V_34 -> V_11 . V_38 , L_3 ) ) {
V_36 -> V_5 = F_34 ( & V_34 -> V_11 , L_4 ) ;
if ( F_35 ( V_36 -> V_5 ) ) {
if ( F_36 ( V_36 -> V_5 ) != - V_37 )
F_19 ( & V_34 -> V_11 , L_5 ) ;
return F_36 ( V_36 -> V_5 ) ;
}
V_36 -> V_7 = F_34 ( & V_34 -> V_11 , L_6 ) ;
if ( F_35 ( V_36 -> V_7 ) ) {
if ( F_36 ( V_36 -> V_7 ) != - V_37 )
F_19 ( & V_34 -> V_11 , L_7 ) ;
return F_36 ( V_36 -> V_7 ) ;
}
}
V_36 -> V_39 . V_40 = & V_41 ;
V_36 -> V_39 . V_42 = 1 ;
V_36 -> V_39 . V_38 = V_34 -> V_11 . V_38 ;
F_38 ( & V_36 -> V_39 ) ;
V_1 = F_39 ( V_36 -> V_3 , V_43 ) ;
if ( V_1 )
return V_1 ;
V_2 = V_36 ;
V_2 -> V_11 = & V_34 -> V_11 ;
F_40 () ;
return 0 ;
}
static int T_6 F_41 ( void )
{
struct V_44 * V_45 , * V_46 ;
int V_1 ;
V_46 = F_42 ( NULL , L_8 ) ;
if ( ! V_46 )
return - V_47 ;
V_45 = F_43 ( V_46 , V_48 ) ;
if ( ! V_45 ) {
F_44 ( V_46 ) ;
return - V_47 ;
}
F_44 ( V_45 ) ;
V_1 = F_45 ( V_46 , V_48 , NULL , NULL ) ;
F_44 ( V_46 ) ;
if ( V_1 )
return V_1 ;
return F_46 ( & V_49 ) ;
}
