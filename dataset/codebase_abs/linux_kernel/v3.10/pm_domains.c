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
static void F_10 ( struct V_4 * V_5 ,
struct V_13 * V_14 )
{
int V_15 ;
F_11 ( V_14 , L_4 , V_5 -> V_5 . V_11 ) ;
while ( 1 ) {
V_15 = F_12 ( & V_5 -> V_5 , V_14 ) ;
if ( V_15 != - V_16 )
break;
F_13 () ;
}
F_14 ( V_14 , true ) ;
}
static void F_15 ( struct V_13 * V_14 )
{
struct V_1 * V_17 = F_16 ( V_14 ) ;
int V_15 ;
F_11 ( V_14 , L_5 , V_17 -> V_11 ) ;
while ( 1 ) {
V_15 = F_17 ( V_17 , V_14 ) ;
if ( V_15 != - V_16 )
break;
F_13 () ;
}
}
static void F_18 ( struct V_13 * V_14 )
{
struct V_18 * V_19 ;
struct V_4 * V_5 ;
struct V_20 * V_21 ;
V_21 = F_19 ( V_14 -> V_22 , L_6 , 0 ) ;
if ( ! V_21 )
return;
V_19 = F_20 ( V_21 ) ;
if ( ! V_19 )
return;
V_5 = F_21 ( V_19 ) ;
F_10 ( V_5 , V_14 ) ;
}
static int F_22 ( struct V_23 * V_24 ,
unsigned long V_25 , void * V_26 )
{
struct V_13 * V_14 = V_26 ;
switch ( V_25 ) {
case V_27 :
if ( V_14 -> V_22 )
F_18 ( V_14 ) ;
break;
case V_28 :
F_15 ( V_14 ) ;
break;
}
return V_29 ;
}
static T_3 int F_23 ( void )
{
struct V_18 * V_30 ;
struct V_20 * V_31 ;
F_24 (np, NULL, L_7 ) {
struct V_4 * V_5 ;
int V_32 ;
V_30 = F_20 ( V_31 ) ;
V_5 = F_25 ( sizeof( * V_5 ) , V_33 ) ;
if ( ! V_5 ) {
F_5 ( L_8 ,
V_34 ) ;
return - V_35 ;
}
V_5 -> V_5 . V_11 = F_26 ( V_31 -> V_11 , V_33 ) ;
V_5 -> V_11 = V_5 -> V_5 . V_11 ;
V_5 -> V_6 = F_27 ( V_31 , 0 ) ;
V_5 -> V_5 . V_36 = F_9 ;
V_5 -> V_5 . V_3 = F_8 ;
V_5 -> V_5 . V_22 = V_31 ;
F_28 ( V_30 , V_5 ) ;
V_32 = F_4 ( V_5 -> V_6 + 0x4 ) & V_10 ;
F_29 ( & V_5 -> V_5 , NULL , ! V_32 ) ;
}
F_30 ( & V_37 , & V_38 ) ;
return 0 ;
}
static T_3 int F_23 ( void )
{
return 0 ;
}
static T_3 T_4 void F_31 ( struct V_18 * V_30 ,
struct V_4 * V_5 )
{
if ( V_30 -> V_14 . V_39 ) {
if ( ! F_12 ( & V_5 -> V_5 , & V_30 -> V_14 ) )
F_14 ( & V_30 -> V_14 , true ) ;
else
F_32 ( L_9
L_10 , V_34 , F_33 ( & V_30 -> V_14 ) ,
V_5 -> V_11 ) ;
}
}
static T_3 int F_34 ( void )
{
int V_40 ;
if ( F_35 () )
return F_23 () ;
for ( V_40 = 0 ; V_40 < F_36 ( V_41 ) ; V_40 ++ ) {
struct V_4 * V_5 = V_41 [ V_40 ] ;
int V_32 = F_4 ( V_5 -> V_6 + 0x4 ) & V_10 ;
F_29 ( & V_5 -> V_5 , NULL , ! V_32 ) ;
}
#ifdef F_37
F_31 ( & V_42 , & V_43 ) ;
#endif
#ifdef F_38
F_31 ( & V_44 , & V_45 ) ;
F_31 ( & V_46 , & V_45 ) ;
#endif
#ifdef F_39
F_31 ( & V_47 , & V_48 ) ;
#endif
#ifdef F_40
F_31 ( & V_49 , & V_50 ) ;
#endif
#ifdef F_41
F_31 ( & V_51 , & V_50 ) ;
#endif
#ifdef F_42
F_31 ( & V_52 , & V_50 ) ;
#endif
#ifdef F_43
F_31 ( & V_53 , & V_50 ) ;
#endif
#ifdef F_44
F_31 ( & V_54 , & V_50 ) ;
#endif
#ifdef F_45
F_31 ( & V_55 , & V_50 ) ;
#endif
#ifdef F_46
F_31 ( & V_56 , & V_43 ) ;
#endif
#ifdef F_47
F_31 ( & V_57 , & V_50 ) ;
#endif
return 0 ;
}
int T_3 F_48 ( void )
{
F_49 () ;
return 0 ;
}
