static int
F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
void * V_4 )
{
struct V_5 * V_6 = V_4 ;
if ( ! F_2 ( V_7 , V_6 -> V_8 ) )
return 0 ;
if ( V_3 == V_9 ) {
F_3 ( L_1 ,
V_6 -> V_8 , V_6 -> V_10 ) ;
F_2 ( V_11 , V_6 -> V_8 ) = V_6 -> V_10 ;
}
return 0 ;
}
static int F_4 ( struct V_12 * V_13 , unsigned int V_6 )
{
int V_14 = - V_15 ;
F_3 ( L_2 , V_13 -> V_8 , V_6 ) ;
F_5 ( & V_16 ) ;
if ( ! F_2 ( V_7 , V_13 -> V_8 ) )
goto V_17;
F_2 ( V_18 , V_13 -> V_8 ) = V_6 ;
if ( V_6 < F_2 ( V_19 , V_13 -> V_8 ) )
V_6 = F_2 ( V_19 , V_13 -> V_8 ) ;
if ( V_6 > F_2 ( V_20 , V_13 -> V_8 ) )
V_6 = F_2 ( V_20 , V_13 -> V_8 ) ;
V_14 = F_6 ( V_13 , V_6 , V_21 ) ;
V_17:
F_7 ( & V_16 ) ;
return V_14 ;
}
static T_1 F_8 ( struct V_12 * V_13 , char * V_22 )
{
return sprintf ( V_22 , L_3 , F_2 ( V_11 , V_13 -> V_8 ) ) ;
}
static int F_9 ( struct V_12 * V_13 ,
unsigned int V_23 )
{
unsigned int V_8 = V_13 -> V_8 ;
int V_24 = 0 ;
switch ( V_23 ) {
case V_25 :
F_10 ( ! V_13 -> V_26 ) ;
F_5 ( & V_16 ) ;
if ( V_27 == 0 ) {
F_11 (
& V_28 ,
V_29 ) ;
}
V_27 ++ ;
F_2 ( V_7 , V_8 ) = 1 ;
F_2 ( V_19 , V_8 ) = V_13 -> V_30 ;
F_2 ( V_20 , V_8 ) = V_13 -> V_31 ;
F_2 ( V_11 , V_8 ) = V_13 -> V_26 ;
F_2 ( V_18 , V_8 ) = V_13 -> V_26 ;
F_3 ( L_4
L_5 ,
V_8 ,
F_2 ( V_19 , V_8 ) ,
F_2 ( V_20 , V_8 ) ,
F_2 ( V_11 , V_8 ) ) ;
F_7 ( & V_16 ) ;
break;
case V_32 :
F_5 ( & V_16 ) ;
V_27 -- ;
if ( V_27 == 0 ) {
F_12 (
& V_28 ,
V_29 ) ;
}
F_2 ( V_7 , V_8 ) = 0 ;
F_2 ( V_19 , V_8 ) = 0 ;
F_2 ( V_20 , V_8 ) = 0 ;
F_2 ( V_18 , V_8 ) = 0 ;
F_3 ( L_6 , V_8 ) ;
F_7 ( & V_16 ) ;
break;
case V_33 :
F_5 ( & V_16 ) ;
F_3 ( L_7
L_8 ,
V_8 , V_13 -> V_30 , V_13 -> V_31 ,
F_2 ( V_11 , V_8 ) ,
F_2 ( V_18 , V_8 ) ) ;
if ( V_13 -> V_31 < F_2 ( V_18 , V_8 ) ) {
F_6 ( V_13 , V_13 -> V_31 ,
V_34 ) ;
} else if ( V_13 -> V_30 > F_2 ( V_18 , V_8 ) ) {
F_6 ( V_13 , V_13 -> V_30 ,
V_21 ) ;
} else {
F_6 ( V_13 ,
F_2 ( V_18 , V_8 ) ,
V_21 ) ;
}
F_2 ( V_19 , V_8 ) = V_13 -> V_30 ;
F_2 ( V_20 , V_8 ) = V_13 -> V_31 ;
F_2 ( V_11 , V_8 ) = V_13 -> V_26 ;
F_7 ( & V_16 ) ;
break;
}
return V_24 ;
}
static int T_2 F_13 ( void )
{
return F_14 ( & V_35 ) ;
}
static void T_3 F_15 ( void )
{
F_16 ( & V_35 ) ;
}
