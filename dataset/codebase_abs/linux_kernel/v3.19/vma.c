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
static unsigned long F_5 ( unsigned long V_13 , unsigned V_14 )
{
#ifdef F_6
return 0 ;
#else
unsigned long V_15 , V_16 ;
unsigned V_17 ;
V_13 = F_7 ( V_13 ) ;
V_16 = ( V_13 + V_14 + V_18 - 1 ) & V_19 ;
if ( V_16 >= V_20 )
V_16 = V_20 ;
V_16 -= V_14 ;
if ( V_16 > V_13 ) {
V_17 = F_8 () % ( ( ( V_16 - V_13 ) >> V_21 ) + 1 ) ;
V_15 = V_13 + ( V_17 << V_21 ) ;
} else {
V_15 = V_13 ;
}
V_15 = F_9 ( V_15 ) ;
return V_15 ;
#endif
}
static int F_10 ( const struct V_1 * V_2 , bool V_22 )
{
struct V_23 * V_24 = V_25 -> V_24 ;
struct V_26 * V_27 ;
unsigned long V_15 , V_28 ;
int V_29 = 0 ;
static struct V_30 * V_31 [] = { NULL } ;
static struct V_32 V_33 = {
. V_34 = L_1 ,
. V_8 = V_31 ,
} ;
if ( V_22 ) {
V_15 = F_5 ( V_25 -> V_24 -> V_35 ,
V_2 -> V_5 - V_2 -> V_36 ) ;
} else {
V_15 = 0 ;
}
F_11 ( & V_24 -> V_37 ) ;
V_15 = F_12 ( NULL , V_15 ,
V_2 -> V_5 - V_2 -> V_36 , 0 , 0 ) ;
if ( F_13 ( V_15 ) ) {
V_29 = V_15 ;
goto V_38;
}
V_28 = V_15 - V_2 -> V_36 ;
V_25 -> V_24 -> V_39 . V_40 = ( void V_41 * ) V_28 ;
V_27 = F_14 ( V_24 ,
V_28 ,
V_2 -> V_5 ,
V_42 | V_43 |
V_44 | V_45 | V_46 ,
& V_2 -> V_7 ) ;
if ( F_15 ( V_27 ) ) {
V_29 = F_16 ( V_27 ) ;
goto V_38;
}
V_27 = F_14 ( V_24 ,
V_15 ,
- V_2 -> V_36 ,
V_42 | V_44 ,
& V_33 ) ;
if ( F_15 ( V_27 ) ) {
V_29 = F_16 ( V_27 ) ;
goto V_38;
}
if ( V_2 -> V_47 )
V_29 = F_17 ( V_27 ,
V_28 + V_2 -> V_47 ,
F_18 ( & V_48 ) >> V_21 ,
V_6 ,
V_49 ) ;
if ( V_29 )
goto V_38;
#ifdef F_19
if ( V_50 && V_2 -> V_51 ) {
V_29 = F_20 ( V_27 ,
V_28 + V_2 -> V_51 ,
V_50 >> V_21 ,
V_6 ,
F_21 ( V_49 ) ) ;
if ( V_29 )
goto V_38;
}
#endif
V_38:
if ( V_29 )
V_25 -> V_24 -> V_39 . V_40 = NULL ;
F_22 ( & V_24 -> V_37 ) ;
return V_29 ;
}
static int F_23 ( void )
{
int V_29 ;
if ( V_52 != 1 )
return 0 ;
V_29 = F_10 ( V_53 , false ) ;
if ( V_29 )
return V_29 ;
if ( V_53 -> V_54 )
F_24 () -> V_55 =
V_25 -> V_24 -> V_39 . V_40 +
V_53 -> V_54 ;
return 0 ;
}
int F_25 ( struct V_56 * V_57 , int V_58 )
{
if ( ! V_59 )
return 0 ;
return F_10 ( & V_60 , true ) ;
}
int F_26 ( struct V_56 * V_57 ,
int V_58 )
{
#ifdef F_27
if ( F_28 ( V_61 ) ) {
if ( ! V_59 )
return 0 ;
return F_10 ( & V_62 , true ) ;
}
#endif
return F_23 () ;
}
int F_25 ( struct V_56 * V_57 , int V_58 )
{
return F_23 () ;
}
static T_1 int F_29 ( char * V_63 )
{
V_59 = F_30 ( V_63 , NULL , 0 ) ;
return 0 ;
}
static void F_31 ( void * V_64 )
{
int V_65 = F_32 () ;
struct V_66 V_67 = { } ;
unsigned long V_68 = 0 ;
#ifdef F_33
V_68 = F_34 ( V_65 ) ;
#endif
if ( F_35 ( & F_36 ( V_65 ) , V_69 ) )
F_37 ( ( V_68 << 12 ) | V_65 ) ;
V_67 . V_70 = V_65 | ( ( V_68 & 0xf ) << 12 ) ;
V_67 . V_71 = V_68 >> 4 ;
V_67 . type = 5 ;
V_67 . V_72 = 3 ;
V_67 . V_63 = 1 ;
V_67 . V_73 = 1 ;
V_67 . V_67 = 1 ;
F_38 ( F_39 ( V_65 ) , V_74 , & V_67 , V_75 ) ;
}
static int
F_40 ( struct V_76 * V_77 , unsigned long V_78 , void * V_64 )
{
long V_65 = ( long ) V_64 ;
if ( V_78 == V_79 || V_78 == V_80 )
F_41 ( V_65 , F_31 , NULL , 1 ) ;
return V_81 ;
}
static int T_1 F_42 ( void )
{
F_1 ( & V_60 ) ;
#ifdef F_27
F_1 ( & V_62 ) ;
#endif
F_43 () ;
F_44 ( F_31 , NULL , 1 ) ;
F_45 ( F_40 , 30 ) ;
F_46 () ;
return 0 ;
}
