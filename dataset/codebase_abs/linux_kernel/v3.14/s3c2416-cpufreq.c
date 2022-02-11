static unsigned int F_1 ( unsigned int V_1 )
{
struct V_2 * V_3 = & V_4 ;
if ( V_1 != 0 )
return 0 ;
if ( V_3 -> V_5 )
return V_6 ;
return F_2 ( V_3 -> V_7 ) / 1000 ;
}
static int F_3 ( struct V_2 * V_3 ,
unsigned int V_8 )
{
int V_9 ;
if ( F_2 ( V_3 -> V_10 ) / 1000 != V_8 ) {
V_9 = F_4 ( V_3 -> V_10 , V_8 * 1000 ) ;
if ( V_9 < 0 ) {
F_5 ( L_1 ,
V_8 , V_9 ) ;
return V_9 ;
}
}
return 0 ;
}
static int F_6 ( struct V_2 * V_3 , int V_11 )
{
#ifdef F_7
struct V_12 * V_13 ;
#endif
int V_9 ;
if ( V_3 -> V_5 ) {
F_8 ( L_2 ) ;
return 0 ;
}
F_8 ( L_3 ,
F_2 ( V_3 -> V_14 ) / 1000 ) ;
V_9 = F_9 ( V_3 -> V_7 , V_3 -> V_14 ) ;
if ( V_9 < 0 ) {
F_5 ( L_4 , V_9 ) ;
return V_9 ;
}
#ifdef F_7
if ( V_3 -> V_15 ) {
V_13 = & V_16 [ V_11 ] ;
F_8 ( L_5 ,
V_13 -> V_17 , V_13 -> V_18 ) ;
V_9 = F_10 ( V_3 -> V_15 ,
V_13 -> V_17 ,
V_13 -> V_18 ) ;
if ( V_9 != 0 )
F_5 ( L_6 , V_9 ) ;
}
#endif
V_3 -> V_5 = 1 ;
return 0 ;
}
static int F_11 ( struct V_2 * V_3 , int V_11 )
{
#ifdef F_7
struct V_12 * V_13 ;
#endif
int V_9 ;
if ( ! V_3 -> V_5 ) {
F_8 ( L_7 ) ;
return 0 ;
}
#ifdef F_7
if ( V_3 -> V_15 ) {
V_13 = & V_16 [ V_11 ] ;
F_8 ( L_5 ,
V_13 -> V_17 , V_13 -> V_18 ) ;
V_9 = F_10 ( V_3 -> V_15 ,
V_13 -> V_17 ,
V_13 -> V_18 ) ;
if ( V_9 != 0 ) {
F_5 ( L_6 , V_9 ) ;
return V_9 ;
}
}
#endif
if ( F_2 ( V_3 -> V_10 ) > F_2 ( V_3 -> V_14 ) ) {
F_8 ( L_8 ,
F_2 ( V_3 -> V_14 ) / 1000 ) ;
V_9 = F_3 ( V_3 ,
F_2 ( V_3 -> V_14 ) / 1000 ) ;
if ( V_9 < 0 ) {
F_5 ( L_9 ,
F_2 ( V_3 -> V_14 ) / 1000 , V_9 ) ;
return V_9 ;
}
}
F_8 ( L_10 ,
F_2 ( V_3 -> V_10 ) / 1000 ) ;
V_9 = F_9 ( V_3 -> V_7 , V_3 -> V_10 ) ;
if ( V_9 < 0 ) {
F_5 ( L_11 ,
V_9 ) ;
return V_9 ;
}
V_3 -> V_5 = 0 ;
return 0 ;
}
static int F_12 ( struct V_19 * V_20 ,
unsigned int V_21 )
{
struct V_2 * V_3 = & V_4 ;
unsigned int V_22 ;
int V_11 , V_9 , V_23 = 0 ;
F_13 ( & V_24 ) ;
V_11 = V_3 -> V_25 [ V_21 ] . V_26 ;
if ( V_11 == V_27 )
V_23 = 1 ;
if ( V_23 && V_3 -> V_28 ) {
F_8 ( L_12 ) ;
V_9 = - V_29 ;
goto V_30;
}
V_22 = ( V_3 -> V_5 && ! V_23 )
? F_2 ( V_3 -> V_14 ) / 1000
: V_3 -> V_25 [ V_21 ] . V_31 ;
if ( V_23 ) {
F_8 ( L_13 ) ;
V_9 = F_6 ( V_3 , V_11 ) ;
} else if ( V_3 -> V_5 ) {
F_8 ( L_14 ) ;
V_9 = F_11 ( V_3 , V_11 ) ;
} else {
F_8 ( L_15 , V_22 ) ;
V_9 = F_3 ( V_3 , V_22 ) ;
}
V_30:
F_14 ( & V_24 ) ;
return V_9 ;
}
static void T_1 F_15 ( struct V_2 * V_3 )
{
int V_32 , V_33 , V_34 , V_35 ;
struct V_36 * V_8 ;
struct V_12 * V_13 ;
V_32 = F_16 ( V_3 -> V_15 ) ;
if ( V_32 < 0 ) {
F_5 ( L_16 ) ;
return;
}
V_8 = V_3 -> V_25 ;
while ( V_32 > 0 && V_8 -> V_31 != V_37 ) {
if ( V_8 -> V_31 == V_38 )
continue;
V_13 = & V_16 [ V_8 -> V_26 ] ;
V_35 = 0 ;
for ( V_34 = 0 ; V_34 < V_32 ; V_34 ++ ) {
V_33 = F_17 ( V_3 -> V_15 , V_34 ) ;
if ( V_33 >= V_13 -> V_17 )
V_35 = 1 ;
}
if ( ! V_35 ) {
F_8 ( L_17 ,
V_8 -> V_31 ) ;
V_8 -> V_31 = V_38 ;
}
V_8 ++ ;
}
V_3 -> V_39 = 1 * 1000 * 1000 ;
}
static int F_18 ( struct V_40 * V_41 ,
unsigned long V_42 , void * V_43 )
{
struct V_2 * V_3 = & V_4 ;
int V_9 ;
F_13 ( & V_24 ) ;
V_3 -> V_28 = 1 ;
F_14 ( & V_24 ) ;
if ( V_3 -> V_5 ) {
F_8 ( L_18 ) ;
V_9 = F_19 ( F_20 ( 0 ) , V_44 , 0 ) ;
if ( V_9 < 0 )
return V_45 ;
}
return V_46 ;
}
static int T_1 F_21 ( struct V_19 * V_20 )
{
struct V_2 * V_3 = & V_4 ;
struct V_36 * V_8 ;
struct V_47 * V_48 ;
unsigned long V_49 ;
int V_9 ;
if ( V_20 -> V_1 != 0 )
return - V_29 ;
V_48 = F_22 ( NULL , L_19 ) ;
if ( F_23 ( V_48 ) ) {
V_9 = F_24 ( V_48 ) ;
F_5 ( L_20 , V_9 ) ;
return V_9 ;
}
V_49 = F_2 ( V_48 ) ;
if ( V_49 == 800 * 1000 * 1000 ) {
F_25 ( L_21 ,
V_49 / 1000 ) ;
V_3 -> V_25 = V_50 ;
V_20 -> V_51 . V_52 = 400000 ;
} else if ( V_49 / 1000 == 534000 ) {
F_25 ( L_22 ,
V_49 / 1000 ) ;
V_3 -> V_25 = V_53 ;
V_20 -> V_51 . V_52 = 534000 ;
}
F_26 ( V_48 ) ;
if ( V_3 -> V_25 == NULL ) {
F_5 ( L_23 ,
V_49 / 1000 ) ;
return - V_54 ;
}
V_3 -> V_5 = 0 ;
V_3 -> V_10 = F_22 ( NULL , L_24 ) ;
if ( F_23 ( V_3 -> V_10 ) ) {
V_9 = F_24 ( V_3 -> V_10 ) ;
F_5 ( L_25 , V_9 ) ;
return V_9 ;
}
V_3 -> V_14 = F_22 ( NULL , L_26 ) ;
if ( F_23 ( V_3 -> V_14 ) ) {
V_9 = F_24 ( V_3 -> V_14 ) ;
F_5 ( L_27 , V_9 ) ;
goto V_55;
}
V_49 = F_2 ( V_3 -> V_14 ) ;
if ( V_49 < 133 * 1000 * 1000 ) {
F_5 ( L_28 ) ;
F_26 ( V_3 -> V_14 ) ;
V_9 = - V_29 ;
goto V_56;
}
V_3 -> V_7 = F_22 ( NULL , L_29 ) ;
if ( F_23 ( V_3 -> V_7 ) ) {
V_9 = F_24 ( V_3 -> V_7 ) ;
F_5 ( L_30 , V_9 ) ;
goto V_56;
}
#ifdef F_7
V_3 -> V_15 = F_27 ( NULL , L_31 ) ;
if ( F_23 ( V_3 -> V_15 ) ) {
V_9 = F_24 ( V_3 -> V_15 ) ;
F_5 ( L_32 , V_9 ) ;
goto V_57;
}
F_15 ( V_3 ) ;
#else
V_3 -> V_39 = 0 ;
#endif
V_8 = V_3 -> V_25 ;
while ( V_8 -> V_31 != V_37 ) {
if ( V_8 -> V_26 == 0 ) {
if ( ! V_3 -> V_14 ) {
F_8 ( L_33 ,
V_8 -> V_31 ) ;
V_8 -> V_31 = V_38 ;
} else {
V_8 ++ ;
continue;
}
}
V_49 = F_28 ( V_3 -> V_10 ,
V_8 -> V_31 * 1000 ) ;
V_49 /= 1000 ;
if ( V_49 != V_8 -> V_31 ) {
F_8 ( L_34 ,
V_8 -> V_31 , V_49 ) ;
V_8 -> V_31 = V_38 ;
}
V_8 ++ ;
}
V_9 = F_29 ( V_20 , V_3 -> V_25 ,
( 500 * 1000 ) + V_3 -> V_39 ) ;
if ( V_9 )
goto V_58;
F_30 ( & V_59 ) ;
return 0 ;
V_58:
#ifdef F_7
F_31 ( V_3 -> V_15 ) ;
V_57:
#endif
F_26 ( V_3 -> V_7 ) ;
V_56:
F_26 ( V_3 -> V_14 ) ;
V_55:
F_26 ( V_3 -> V_10 ) ;
return V_9 ;
}
static int T_1 F_32 ( void )
{
return F_33 ( & V_60 ) ;
}
