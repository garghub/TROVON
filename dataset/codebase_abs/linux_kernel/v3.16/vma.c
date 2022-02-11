void T_1 F_1 ( const struct V_1 * V_2 )
{
int V_3 ;
int V_4 = ( V_2 -> V_5 ) / V_6 ;
F_2 ( V_2 -> V_5 % V_6 != 0 ) ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ )
V_2 -> V_7 . V_8 [ V_3 ] =
F_3 ( V_2 -> V_9 + V_3 * V_6 ) ;
F_4 ( (struct V_10 * ) ( V_2 -> V_9 + V_2 -> V_11 ) ,
(struct V_10 * ) ( V_2 -> V_9 + V_2 -> V_11 +
V_2 -> V_12 ) ) ;
}
static int T_1 F_5 ( void )
{
F_1 ( & V_13 ) ;
#ifdef F_6
F_1 ( & V_14 ) ;
#endif
return 0 ;
}
static unsigned long F_7 ( unsigned long V_15 , unsigned V_16 )
{
#ifdef F_8
return 0 ;
#else
unsigned long V_17 , V_18 ;
unsigned V_19 ;
V_18 = ( V_15 + V_20 - 1 ) & V_21 ;
if ( V_18 >= V_22 )
V_18 = V_22 ;
V_18 -= V_16 ;
V_19 = F_9 () & ( V_23 - 1 ) ;
V_17 = V_15 + ( V_19 << V_24 ) ;
if ( V_17 >= V_18 )
V_17 = V_18 ;
V_17 = F_10 ( V_17 ) ;
V_17 = F_11 ( V_17 ) ;
return V_17 ;
#endif
}
static int F_12 ( const struct V_1 * V_2 , bool V_25 )
{
struct V_26 * V_27 = V_28 -> V_27 ;
struct V_29 * V_30 ;
unsigned long V_17 ;
int V_31 = 0 ;
static struct V_32 * V_33 [] = { NULL } ;
static struct V_34 V_35 = {
. V_36 = L_1 ,
. V_8 = V_33 ,
} ;
if ( V_25 ) {
V_17 = F_7 ( V_28 -> V_27 -> V_37 ,
V_2 -> V_38 ) ;
} else {
V_17 = 0 ;
}
F_13 ( & V_27 -> V_39 ) ;
V_17 = F_14 ( NULL , V_17 , V_2 -> V_38 , 0 , 0 ) ;
if ( F_15 ( V_17 ) ) {
V_31 = V_17 ;
goto V_40;
}
V_28 -> V_27 -> V_41 . V_42 = ( void V_43 * ) V_17 ;
V_30 = F_16 ( V_27 ,
V_17 ,
V_2 -> V_5 ,
V_44 | V_45 |
V_46 | V_47 | V_48 ,
& V_2 -> V_7 ) ;
if ( F_17 ( V_30 ) ) {
V_31 = F_18 ( V_30 ) ;
goto V_40;
}
V_30 = F_16 ( V_27 ,
V_17 + V_2 -> V_5 ,
V_2 -> V_38 - V_2 -> V_5 ,
V_44 ,
& V_35 ) ;
if ( F_17 ( V_30 ) ) {
V_31 = F_18 ( V_30 ) ;
goto V_40;
}
if ( V_2 -> V_49 )
V_31 = F_19 ( V_30 ,
V_17 + V_2 -> V_49 ,
F_20 ( & V_50 ) >> V_24 ,
V_6 ,
V_51 ) ;
if ( V_31 )
goto V_40;
#ifdef F_21
if ( V_52 && V_2 -> V_53 ) {
V_31 = F_22 ( V_30 ,
V_17 + V_2 -> V_53 ,
V_52 >> V_24 ,
V_6 ,
F_23 ( V_51 ) ) ;
if ( V_31 )
goto V_40;
}
#endif
V_40:
if ( V_31 )
V_28 -> V_27 -> V_41 . V_42 = NULL ;
F_24 ( & V_27 -> V_39 ) ;
return V_31 ;
}
static int F_25 ( void )
{
int V_31 ;
if ( V_54 != 1 )
return 0 ;
V_31 = F_12 ( V_55 , false ) ;
if ( V_31 )
return V_31 ;
if ( V_55 -> V_56 )
F_26 () -> V_57 =
V_28 -> V_27 -> V_41 . V_42 +
V_55 -> V_56 ;
return 0 ;
}
int F_27 ( struct V_58 * V_59 , int V_60 )
{
if ( ! V_61 )
return 0 ;
return F_12 ( & V_13 , true ) ;
}
int F_28 ( struct V_58 * V_59 ,
int V_60 )
{
#ifdef F_6
if ( F_29 ( V_62 ) ) {
if ( ! V_61 )
return 0 ;
return F_12 ( & V_14 , true ) ;
}
#endif
return F_25 () ;
}
int F_27 ( struct V_58 * V_59 , int V_60 )
{
return F_25 () ;
}
static T_1 int F_30 ( char * V_63 )
{
V_61 = F_31 ( V_63 , NULL , 0 ) ;
return 0 ;
}
