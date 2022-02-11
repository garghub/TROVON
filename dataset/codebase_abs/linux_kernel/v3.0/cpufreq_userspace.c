static int
F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
void * V_4 )
{
struct V_5 * V_6 = V_4 ;
if ( ! F_2 ( V_7 , V_6 -> V_8 ) )
return 0 ;
F_3 ( L_1 ,
V_6 -> V_8 , V_6 -> V_9 ) ;
F_2 ( V_10 , V_6 -> V_8 ) = V_6 -> V_9 ;
return 0 ;
}
static int F_4 ( struct V_11 * V_12 , unsigned int V_6 )
{
int V_13 = - V_14 ;
F_3 ( L_2 , V_12 -> V_8 , V_6 ) ;
F_5 ( & V_15 ) ;
if ( ! F_2 ( V_7 , V_12 -> V_8 ) )
goto V_16;
F_2 ( V_17 , V_12 -> V_8 ) = V_6 ;
if ( V_6 < F_2 ( V_18 , V_12 -> V_8 ) )
V_6 = F_2 ( V_18 , V_12 -> V_8 ) ;
if ( V_6 > F_2 ( V_19 , V_12 -> V_8 ) )
V_6 = F_2 ( V_19 , V_12 -> V_8 ) ;
V_13 = F_6 ( V_12 , V_6 , V_20 ) ;
V_16:
F_7 ( & V_15 ) ;
return V_13 ;
}
static T_1 F_8 ( struct V_11 * V_12 , char * V_21 )
{
return sprintf ( V_21 , L_3 , F_2 ( V_10 , V_12 -> V_8 ) ) ;
}
static int F_9 ( struct V_11 * V_12 ,
unsigned int V_22 )
{
unsigned int V_8 = V_12 -> V_8 ;
int V_23 = 0 ;
switch ( V_22 ) {
case V_24 :
if ( ! F_10 ( V_8 ) )
return - V_14 ;
F_11 ( ! V_12 -> V_25 ) ;
F_5 ( & V_15 ) ;
if ( V_26 == 0 ) {
F_12 (
& V_27 ,
V_28 ) ;
}
V_26 ++ ;
F_2 ( V_7 , V_8 ) = 1 ;
F_2 ( V_18 , V_8 ) = V_12 -> V_29 ;
F_2 ( V_19 , V_8 ) = V_12 -> V_30 ;
F_2 ( V_10 , V_8 ) = V_12 -> V_25 ;
F_2 ( V_17 , V_8 ) = V_12 -> V_25 ;
F_3 ( L_4
L_5 ,
V_8 ,
F_2 ( V_18 , V_8 ) ,
F_2 ( V_19 , V_8 ) ,
F_2 ( V_10 , V_8 ) ) ;
F_7 ( & V_15 ) ;
break;
case V_31 :
F_5 ( & V_15 ) ;
V_26 -- ;
if ( V_26 == 0 ) {
F_13 (
& V_27 ,
V_28 ) ;
}
F_2 ( V_7 , V_8 ) = 0 ;
F_2 ( V_18 , V_8 ) = 0 ;
F_2 ( V_19 , V_8 ) = 0 ;
F_2 ( V_17 , V_8 ) = 0 ;
F_3 ( L_6 , V_8 ) ;
F_7 ( & V_15 ) ;
break;
case V_32 :
F_5 ( & V_15 ) ;
F_3 ( L_7
L_8 ,
V_8 , V_12 -> V_29 , V_12 -> V_30 ,
F_2 ( V_10 , V_8 ) ,
F_2 ( V_17 , V_8 ) ) ;
if ( V_12 -> V_30 < F_2 ( V_17 , V_8 ) ) {
F_6 ( V_12 , V_12 -> V_30 ,
V_33 ) ;
} else if ( V_12 -> V_29 > F_2 ( V_17 , V_8 ) ) {
F_6 ( V_12 , V_12 -> V_29 ,
V_20 ) ;
} else {
F_6 ( V_12 ,
F_2 ( V_17 , V_8 ) ,
V_20 ) ;
}
F_2 ( V_18 , V_8 ) = V_12 -> V_29 ;
F_2 ( V_19 , V_8 ) = V_12 -> V_30 ;
F_2 ( V_10 , V_8 ) = V_12 -> V_25 ;
F_7 ( & V_15 ) ;
break;
}
return V_23 ;
}
static int T_2 F_14 ( void )
{
return F_15 ( & V_34 ) ;
}
static void T_3 F_16 ( void )
{
F_17 ( & V_34 ) ;
}
