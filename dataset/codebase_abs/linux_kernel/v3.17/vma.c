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
unsigned long V_17 , V_31 ;
int V_32 = 0 ;
static struct V_33 * V_34 [] = { NULL } ;
static struct V_35 V_36 = {
. V_37 = L_1 ,
. V_8 = V_34 ,
} ;
if ( V_25 ) {
V_17 = F_7 ( V_28 -> V_27 -> V_38 ,
V_2 -> V_5 - V_2 -> V_39 ) ;
} else {
V_17 = 0 ;
}
F_13 ( & V_27 -> V_40 ) ;
V_17 = F_14 ( NULL , V_17 ,
V_2 -> V_5 - V_2 -> V_39 , 0 , 0 ) ;
if ( F_15 ( V_17 ) ) {
V_32 = V_17 ;
goto V_41;
}
V_31 = V_17 - V_2 -> V_39 ;
V_28 -> V_27 -> V_42 . V_43 = ( void V_44 * ) V_31 ;
V_30 = F_16 ( V_27 ,
V_31 ,
V_2 -> V_5 ,
V_45 | V_46 |
V_47 | V_48 | V_49 ,
& V_2 -> V_7 ) ;
if ( F_17 ( V_30 ) ) {
V_32 = F_18 ( V_30 ) ;
goto V_41;
}
V_30 = F_16 ( V_27 ,
V_17 ,
- V_2 -> V_39 ,
V_45 | V_47 ,
& V_36 ) ;
if ( F_17 ( V_30 ) ) {
V_32 = F_18 ( V_30 ) ;
goto V_41;
}
if ( V_2 -> V_50 )
V_32 = F_19 ( V_30 ,
V_31 + V_2 -> V_50 ,
F_20 ( & V_51 ) >> V_24 ,
V_6 ,
V_52 ) ;
if ( V_32 )
goto V_41;
#ifdef F_21
if ( V_53 && V_2 -> V_54 ) {
V_32 = F_22 ( V_30 ,
V_31 + V_2 -> V_54 ,
V_53 >> V_24 ,
V_6 ,
F_23 ( V_52 ) ) ;
if ( V_32 )
goto V_41;
}
#endif
V_41:
if ( V_32 )
V_28 -> V_27 -> V_42 . V_43 = NULL ;
F_24 ( & V_27 -> V_40 ) ;
return V_32 ;
}
static int F_25 ( void )
{
int V_32 ;
if ( V_55 != 1 )
return 0 ;
V_32 = F_12 ( V_56 , false ) ;
if ( V_32 )
return V_32 ;
if ( V_56 -> V_57 )
F_26 () -> V_58 =
V_28 -> V_27 -> V_42 . V_43 +
V_56 -> V_57 ;
return 0 ;
}
int F_27 ( struct V_59 * V_60 , int V_61 )
{
if ( ! V_62 )
return 0 ;
return F_12 ( & V_13 , true ) ;
}
int F_28 ( struct V_59 * V_60 ,
int V_61 )
{
#ifdef F_6
if ( F_29 ( V_63 ) ) {
if ( ! V_62 )
return 0 ;
return F_12 ( & V_14 , true ) ;
}
#endif
return F_25 () ;
}
int F_27 ( struct V_59 * V_60 , int V_61 )
{
return F_25 () ;
}
static T_1 int F_30 ( char * V_64 )
{
V_62 = F_31 ( V_64 , NULL , 0 ) ;
return 0 ;
}
