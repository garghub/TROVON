static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 ;
void T_1 * V_6 ;
T_2 V_7 , V_8 ;
char * V_9 ;
V_5 = F_2 ( V_2 , struct V_4 , V_5 ) ;
V_6 = V_5 -> V_6 ;
V_8 = V_3 ? V_10 : 0 ;
F_3 ( V_8 , V_6 ) ;
V_7 = 10 ;
while ( ( F_4 ( V_6 + 0x4 ) & V_10 ) != V_8 ) {
if ( ! V_7 ) {
V_9 = ( V_3 ) ? L_1 : L_2 ;
F_5 ( L_3 , V_2 -> V_11 , V_9 ) ;
return - V_12 ;
}
V_7 -- ;
F_6 () ;
F_7 ( 80 , 100 ) ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , true ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , false ) ;
}
static T_3 int F_10 ( void )
{
struct V_13 * V_14 ;
F_11 (np, NULL, L_4 ) {
struct V_4 * V_5 ;
V_5 = F_12 ( sizeof( * V_5 ) , V_15 ) ;
if ( ! V_5 ) {
F_5 ( L_5 ,
V_16 ) ;
return - V_17 ;
}
if ( F_13 ( V_14 , L_6 , NULL ) )
V_5 -> V_18 = true ;
V_5 -> V_11 = V_14 -> V_11 ;
V_5 -> V_6 = F_14 ( V_14 , 0 ) ;
V_5 -> V_5 . V_19 = F_9 ;
V_5 -> V_5 . V_3 = F_8 ;
V_5 -> V_5 . V_20 = V_14 ;
F_15 ( & V_5 -> V_5 , NULL , false ) ;
}
return 0 ;
}
static T_3 int F_10 ( void )
{
return 0 ;
}
static T_3 T_4 void F_16 ( struct V_21 * V_22 ,
struct V_4 * V_5 )
{
if ( V_22 -> V_23 . V_24 ) {
if ( ! F_17 ( & V_5 -> V_5 , & V_22 -> V_23 ) )
F_18 ( & V_22 -> V_23 , true ) ;
else
F_19 ( L_7
L_8 , V_16 , F_20 ( & V_22 -> V_23 ) ,
V_5 -> V_11 ) ;
}
}
static T_3 int F_21 ( void )
{
int V_25 ;
if ( F_22 () )
return F_10 () ;
for ( V_25 = 0 ; V_25 < F_23 ( V_26 ) ; V_25 ++ ) {
struct V_4 * V_5 = V_26 [ V_25 ] ;
int V_27 = F_4 ( V_5 -> V_6 + 0x4 ) & V_10 ;
F_15 ( & V_5 -> V_5 , NULL , ! V_27 ) ;
}
#ifdef F_24
F_16 ( & V_28 , & V_29 ) ;
#endif
#ifdef F_25
F_16 ( & V_30 , & V_31 ) ;
F_16 ( & V_32 , & V_31 ) ;
#endif
#ifdef F_26
F_16 ( & V_33 , & V_34 ) ;
#endif
#ifdef F_27
F_16 ( & V_35 , & V_36 ) ;
#endif
#ifdef F_28
F_16 ( & V_37 , & V_36 ) ;
#endif
#ifdef F_29
F_16 ( & V_38 , & V_36 ) ;
#endif
#ifdef F_30
F_16 ( & V_39 , & V_36 ) ;
#endif
#ifdef F_31
F_16 ( & V_40 , & V_36 ) ;
#endif
#ifdef F_32
F_16 ( & V_41 , & V_36 ) ;
#endif
#ifdef F_33
F_16 ( & V_42 , & V_29 ) ;
#endif
#ifdef F_34
F_16 ( & V_43 , & V_36 ) ;
#endif
return 0 ;
}
int T_3 F_35 ( void )
{
F_36 () ;
return 0 ;
}
