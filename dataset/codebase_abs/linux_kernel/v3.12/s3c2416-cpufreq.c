static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_5 ;
if ( V_2 -> V_6 != 0 )
return - V_7 ;
return F_2 ( V_2 , V_4 -> V_8 ) ;
}
static unsigned int F_3 ( unsigned int V_6 )
{
struct V_3 * V_4 = & V_5 ;
if ( V_6 != 0 )
return 0 ;
if ( V_4 -> V_9 )
return V_10 ;
return F_4 ( V_4 -> V_11 ) / 1000 ;
}
static int F_5 ( struct V_3 * V_4 ,
unsigned int V_12 )
{
int V_13 ;
if ( F_4 ( V_4 -> V_14 ) / 1000 != V_12 ) {
V_13 = F_6 ( V_4 -> V_14 , V_12 * 1000 ) ;
if ( V_13 < 0 ) {
F_7 ( L_1 ,
V_12 , V_13 ) ;
return V_13 ;
}
}
return 0 ;
}
static int F_8 ( struct V_3 * V_4 , int V_15 )
{
#ifdef F_9
struct V_16 * V_17 ;
#endif
int V_13 ;
if ( V_4 -> V_9 ) {
F_10 ( L_2 ) ;
return 0 ;
}
F_10 ( L_3 ,
F_4 ( V_4 -> V_18 ) / 1000 ) ;
V_13 = F_11 ( V_4 -> V_11 , V_4 -> V_18 ) ;
if ( V_13 < 0 ) {
F_7 ( L_4 , V_13 ) ;
return V_13 ;
}
#ifdef F_9
if ( V_4 -> V_19 ) {
V_17 = & V_20 [ V_15 ] ;
F_10 ( L_5 ,
V_17 -> V_21 , V_17 -> V_22 ) ;
V_13 = F_12 ( V_4 -> V_19 ,
V_17 -> V_21 ,
V_17 -> V_22 ) ;
if ( V_13 != 0 )
F_7 ( L_6 , V_13 ) ;
}
#endif
V_4 -> V_9 = 1 ;
return 0 ;
}
static int F_13 ( struct V_3 * V_4 , int V_15 )
{
#ifdef F_9
struct V_16 * V_17 ;
#endif
int V_13 ;
if ( ! V_4 -> V_9 ) {
F_10 ( L_7 ) ;
return 0 ;
}
#ifdef F_9
if ( V_4 -> V_19 ) {
V_17 = & V_20 [ V_15 ] ;
F_10 ( L_5 ,
V_17 -> V_21 , V_17 -> V_22 ) ;
V_13 = F_12 ( V_4 -> V_19 ,
V_17 -> V_21 ,
V_17 -> V_22 ) ;
if ( V_13 != 0 ) {
F_7 ( L_6 , V_13 ) ;
return V_13 ;
}
}
#endif
if ( F_4 ( V_4 -> V_14 ) > F_4 ( V_4 -> V_18 ) ) {
F_10 ( L_8 ,
F_4 ( V_4 -> V_18 ) / 1000 ) ;
V_13 = F_5 ( V_4 ,
F_4 ( V_4 -> V_18 ) / 1000 ) ;
if ( V_13 < 0 ) {
F_7 ( L_9 ,
F_4 ( V_4 -> V_18 ) / 1000 , V_13 ) ;
return V_13 ;
}
}
F_10 ( L_10 ,
F_4 ( V_4 -> V_14 ) / 1000 ) ;
V_13 = F_11 ( V_4 -> V_11 , V_4 -> V_14 ) ;
if ( V_13 < 0 ) {
F_7 ( L_11 ,
V_13 ) ;
return V_13 ;
}
V_4 -> V_9 = 0 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
unsigned int V_23 ,
unsigned int V_24 )
{
struct V_3 * V_4 = & V_5 ;
struct V_25 V_26 ;
int V_15 , V_13 , V_27 = 0 ;
unsigned int V_28 ;
F_15 ( & V_29 ) ;
F_10 ( L_12 , V_23 , V_24 ) ;
V_13 = F_16 ( V_2 , V_4 -> V_8 ,
V_23 , V_24 , & V_28 ) ;
if ( V_13 != 0 )
goto V_30;
V_15 = V_4 -> V_8 [ V_28 ] . V_31 ;
if ( V_15 == V_32 )
V_27 = 1 ;
if ( V_27 && V_4 -> V_33 ) {
F_10 ( L_13 ) ;
V_13 = - V_7 ;
goto V_30;
}
V_26 . V_34 = 0 ;
V_26 . V_35 = V_4 -> V_9 ? V_10
: F_4 ( V_4 -> V_11 ) / 1000 ;
V_26 . V_36 = ( V_4 -> V_9 && ! V_27 )
? F_4 ( V_4 -> V_18 ) / 1000
: V_4 -> V_8 [ V_28 ] . V_37 ;
F_10 ( L_14 , V_26 . V_35 , V_26 . V_36 ) ;
if ( ! V_27 && V_26 . V_35 == V_26 . V_36 )
goto V_30;
F_17 ( V_2 , & V_26 , V_38 ) ;
if ( V_27 ) {
F_10 ( L_15 ) ;
V_13 = F_8 ( V_4 , V_15 ) ;
} else if ( V_4 -> V_9 ) {
F_10 ( L_16 ) ;
V_13 = F_13 ( V_4 , V_15 ) ;
} else {
F_10 ( L_17 , V_26 . V_36 ) ;
V_13 = F_5 ( V_4 , V_26 . V_36 ) ;
}
F_17 ( V_2 , & V_26 , V_39 ) ;
V_30:
F_18 ( & V_29 ) ;
return V_13 ;
}
static void T_1 F_19 ( struct V_3 * V_4 )
{
int V_40 , V_41 , V_28 , V_42 ;
struct V_43 * V_12 ;
struct V_16 * V_17 ;
V_40 = F_20 ( V_4 -> V_19 ) ;
if ( V_40 < 0 ) {
F_7 ( L_18 ) ;
return;
}
V_12 = V_4 -> V_8 ;
while ( V_40 > 0 && V_12 -> V_37 != V_44 ) {
if ( V_12 -> V_37 == V_45 )
continue;
V_17 = & V_20 [ V_12 -> V_31 ] ;
V_42 = 0 ;
for ( V_28 = 0 ; V_28 < V_40 ; V_28 ++ ) {
V_41 = F_21 ( V_4 -> V_19 , V_28 ) ;
if ( V_41 >= V_17 -> V_21 )
V_42 = 1 ;
}
if ( ! V_42 ) {
F_10 ( L_19 ,
V_12 -> V_37 ) ;
V_12 -> V_37 = V_45 ;
}
V_12 ++ ;
}
V_4 -> V_46 = 1 * 1000 * 1000 ;
}
static int F_22 ( struct V_47 * V_48 ,
unsigned long V_49 , void * V_50 )
{
struct V_3 * V_4 = & V_5 ;
int V_13 ;
F_15 ( & V_29 ) ;
V_4 -> V_33 = 1 ;
F_18 ( & V_29 ) ;
if ( V_4 -> V_9 ) {
F_10 ( L_20 ) ;
V_13 = F_23 ( F_24 ( 0 ) , V_51 , 0 ) ;
if ( V_13 < 0 )
return V_52 ;
}
return V_53 ;
}
static int T_1 F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_5 ;
struct V_43 * V_12 ;
struct V_54 * V_55 ;
unsigned long V_56 ;
int V_13 ;
if ( V_2 -> V_6 != 0 )
return - V_7 ;
V_55 = F_26 ( NULL , L_21 ) ;
if ( F_27 ( V_55 ) ) {
V_13 = F_28 ( V_55 ) ;
F_7 ( L_22 , V_13 ) ;
return V_13 ;
}
V_56 = F_4 ( V_55 ) ;
if ( V_56 == 800 * 1000 * 1000 ) {
F_29 ( L_23 ,
V_56 / 1000 ) ;
V_4 -> V_8 = V_57 ;
V_2 -> V_58 . V_59 = 400000 ;
} else if ( V_56 / 1000 == 534000 ) {
F_29 ( L_24 ,
V_56 / 1000 ) ;
V_4 -> V_8 = V_60 ;
V_2 -> V_58 . V_59 = 534000 ;
}
F_30 ( V_55 ) ;
if ( V_4 -> V_8 == NULL ) {
F_7 ( L_25 ,
V_56 / 1000 ) ;
return - V_61 ;
}
V_4 -> V_9 = 0 ;
V_4 -> V_14 = F_26 ( NULL , L_26 ) ;
if ( F_27 ( V_4 -> V_14 ) ) {
V_13 = F_28 ( V_4 -> V_14 ) ;
F_7 ( L_27 , V_13 ) ;
return V_13 ;
}
V_4 -> V_18 = F_26 ( NULL , L_28 ) ;
if ( F_27 ( V_4 -> V_18 ) ) {
V_13 = F_28 ( V_4 -> V_18 ) ;
F_7 ( L_29 , V_13 ) ;
goto V_62;
}
V_56 = F_4 ( V_4 -> V_18 ) ;
if ( V_56 < 133 * 1000 * 1000 ) {
F_7 ( L_30 ) ;
F_30 ( V_4 -> V_18 ) ;
V_13 = - V_7 ;
goto V_63;
}
V_4 -> V_11 = F_26 ( NULL , L_31 ) ;
if ( F_27 ( V_4 -> V_11 ) ) {
V_13 = F_28 ( V_4 -> V_11 ) ;
F_7 ( L_32 , V_13 ) ;
goto V_63;
}
#ifdef F_9
V_4 -> V_19 = F_31 ( NULL , L_33 ) ;
if ( F_27 ( V_4 -> V_19 ) ) {
V_13 = F_28 ( V_4 -> V_19 ) ;
F_7 ( L_34 , V_13 ) ;
goto V_64;
}
F_19 ( V_4 ) ;
#else
V_4 -> V_46 = 0 ;
#endif
V_12 = V_4 -> V_8 ;
while ( V_12 -> V_37 != V_44 ) {
if ( V_12 -> V_31 == 0 ) {
if ( ! V_4 -> V_18 ) {
F_10 ( L_35 ,
V_12 -> V_37 ) ;
V_12 -> V_37 = V_45 ;
} else {
V_12 ++ ;
continue;
}
}
V_56 = F_32 ( V_4 -> V_14 ,
V_12 -> V_37 * 1000 ) ;
V_56 /= 1000 ;
if ( V_56 != V_12 -> V_37 ) {
F_10 ( L_36 ,
V_12 -> V_37 , V_56 ) ;
V_12 -> V_37 = V_45 ;
}
V_12 ++ ;
}
V_2 -> V_65 = F_4 ( V_4 -> V_11 ) / 1000 ;
V_2 -> V_58 . V_66 = ( 500 * 1000 ) +
V_4 -> V_46 ;
V_13 = F_33 ( V_2 , V_4 -> V_8 ) ;
if ( V_13 )
goto V_67;
F_34 ( V_4 -> V_8 , 0 ) ;
F_35 ( & V_68 ) ;
return 0 ;
V_67:
#ifdef F_9
F_36 ( V_4 -> V_19 ) ;
V_64:
#endif
F_30 ( V_4 -> V_11 ) ;
V_63:
F_30 ( V_4 -> V_18 ) ;
V_62:
F_30 ( V_4 -> V_14 ) ;
return V_13 ;
}
static int T_1 F_37 ( void )
{
return F_38 ( & V_69 ) ;
}
