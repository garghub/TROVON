int F_1 ( struct V_1 * V_2 , char * V_3 , int V_4 , T_1 V_5 ,
int V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 , struct V_7 , V_2 ) ;
if ( ! V_2 )
return - V_9 ;
F_3 ( & V_8 -> V_10 -> V_11 ) ;
if ( V_4 > V_12 || V_4 < 0 ) {
V_5 = 0 ;
goto V_13;
}
V_5 = F_4 ( int , V_5 , V_12 - V_4 ) ;
if ( F_5 ( V_8 ) == 0 ) {
if ( V_6 ) {
F_6 ( V_8 -> V_10 , V_14 ) ;
F_6 ( V_8 -> V_10 , V_4 ) ;
F_7 ( V_8 -> V_10 , V_3 , V_5 ) ;
} else {
F_6 ( V_8 -> V_10 , V_15 ) ;
F_6 ( V_8 -> V_10 , V_4 ) ;
V_5 = F_8 ( V_8 -> V_10 , V_3 , V_5 ) ;
}
}
V_13:
F_9 ( & V_8 -> V_10 -> V_11 ) ;
return V_5 ;
}
int F_10 ( struct V_1 * V_2 , int V_4 , int V_16 )
{
struct V_7 * V_8 = F_2 ( V_2 , struct V_7 , V_2 ) ;
if ( ! V_2 )
return - V_17 ;
F_3 ( & V_8 -> V_10 -> V_11 ) ;
if ( F_5 ( V_8 ) == 0 ) {
F_6 ( V_8 -> V_10 , V_16 ) ;
F_6 ( V_8 -> V_10 , V_4 ) ;
}
F_9 ( & V_8 -> V_10 -> V_11 ) ;
return 0 ;
}
static T_2 F_11 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
struct V_22 * V_23 ,
char * V_3 , T_3 V_24 , T_1 V_5 )
{
struct V_1 * V_2 = F_2 ( V_21 , struct V_1 , V_21 ) ;
return F_1 ( V_2 , V_3 , V_24 , V_5 , 0 ) ;
}
static int F_12 ( void )
{
int V_25 ;
while ( 1 ) {
int V_26 ;
V_25 = F_13 ( & V_27 , V_28 ) ;
if ( V_25 == 0 )
return - V_29 ;
F_3 ( & V_30 ) ;
V_25 = F_14 ( & V_27 , NULL , & V_26 ) ;
F_9 ( & V_30 ) ;
if ( V_25 == 0 ) {
V_25 = V_26 & V_31 ;
break;
} else if ( V_25 == - V_32 ) {
continue;
} else {
break;
}
}
return V_25 ;
}
static void F_15 ( int V_26 )
{
F_3 ( & V_30 ) ;
F_16 ( & V_27 , V_26 ) ;
F_9 ( & V_30 ) ;
}
static int F_17 ( struct V_7 * V_8 )
{
int V_25 ;
int V_26 ;
struct V_33 * V_34 ;
V_26 = F_12 () ;
if ( V_26 < 0 ) {
V_25 = V_26 ;
goto V_35;
}
V_34 = F_18 ( L_1 , V_26 ) ;
if ( ! V_34 ) {
V_25 = - V_29 ;
goto V_36;
}
V_34 -> V_2 . V_37 = & V_8 -> V_2 ;
V_25 = F_19 ( V_34 ) ;
if ( V_25 )
goto V_38;
V_25 = F_20 ( & V_8 -> V_2 . V_21 , & V_39 ) ;
if ( V_25 )
goto V_40;
F_21 ( & V_8 -> V_2 , V_34 ) ;
return 0 ;
V_40:
V_38:
F_22 ( V_34 ) ;
V_36:
F_15 ( V_26 ) ;
V_35:
return V_25 ;
}
static void F_23 ( struct V_7 * V_8 )
{
struct V_33 * V_34 = F_24 ( & V_8 -> V_2 ) ;
int V_26 = V_34 -> V_26 ;
F_22 ( V_34 ) ;
F_15 ( V_26 ) ;
F_25 ( & V_8 -> V_2 . V_21 , & V_39 ) ;
}
static int T_4 F_26 ( void )
{
F_27 ( & V_27 ) ;
return F_28 ( & V_41 ) ;
}
static void T_5 F_29 ( void )
{
F_30 ( & V_41 ) ;
F_31 ( & V_27 ) ;
}
