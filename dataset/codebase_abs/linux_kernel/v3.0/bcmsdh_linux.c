bool F_1 ( T_1 V_1 , T_1 V_2 )
{
#ifdef F_2
if ( V_1 == V_3 )
return true ;
if ( V_2 == V_4 && V_1 == V_5 )
return true ;
if ( V_2 == V_6 && V_1 == V_5 )
return true ;
if ( V_2 == V_7 && V_1 == V_8 )
return true ;
if ( V_2 == V_9 && V_1 == V_8 )
return true ;
if ( V_2 == V_10 && V_1 == V_11 )
return true ;
if ( V_2 == V_12 && V_1 == V_13 )
return true ;
#endif
#ifdef F_3
if ( V_2 == V_14 && V_1 == V_5 ) {
return true ;
}
#endif
return false ;
}
static
#endif
int F_4 ( struct V_2 * V_15 )
{
T_2 * V_16 = NULL ;
unsigned long V_17 = 0 ;
T_3 * V_18 = NULL ;
#if ! F_5 ( V_19 ) && F_5 ( V_20 )
struct V_21 * V_22 ;
struct V_23 * V_24 ;
#endif
int V_25 = 0 ;
T_4 V_26 ;
unsigned long V_27 = 0 ;
#if ! F_5 ( V_19 ) && F_5 ( V_20 )
V_22 = F_6 ( V_15 ) ;
V_24 = F_7 ( V_22 , V_28 , 0 ) ;
V_25 = F_8 ( V_22 , 0 ) ;
if ( ! V_24 || V_25 == V_29 )
return - V_30 ;
#endif
#if F_5 ( V_31 )
#ifdef F_9
V_27 =
V_32 | V_33 |
V_34 ;
#else
V_27 = V_35 ;
#endif
V_25 = F_10 ( & V_27 ) ;
if ( V_25 < 0 ) {
F_11 ( ( L_1 , V_36 ) ) ;
return 1 ;
}
#endif
V_16 = F_12 ( sizeof( T_2 ) , V_37 ) ;
if ( ! V_16 ) {
F_11 ( ( L_2 , V_36 ) ) ;
goto V_38;
}
V_16 -> V_15 = ( void * ) V_15 ;
#ifdef V_19
V_18 = F_13 ( ( void * ) 0 , ( void * * ) & V_17 , V_25 ) ;
if ( ! V_18 ) {
F_11 ( ( L_3 , V_36 ) ) ;
goto V_38;
}
#else
V_18 = F_13 ( ( void * ) V_24 -> V_39 , ( void * * ) & V_17 , V_25 ) ;
if ( ! V_18 ) {
F_11 ( ( L_3 , V_36 ) ) ;
goto V_38;
}
#endif
V_16 -> V_18 = V_18 ;
V_16 -> V_40 = V_25 ;
V_16 -> V_41 = V_27 ;
V_16 -> V_42 = false ;
#if F_5 ( V_31 )
F_14 ( & V_16 -> V_43 ) ;
#endif
V_16 -> V_44 = V_45 ;
V_45 = V_16 ;
V_26 = F_15 ( V_18 ) ;
V_16 -> V_46 = V_47 . V_48 ( ( V_26 >> 16 ) , ( V_26 & 0xFFFF ) ,
0 , 0 , 0 , 0 , ( void * ) V_17 , V_18 ) ;
if ( ! V_16 -> V_46 ) {
F_11 ( ( L_4 , V_36 ) ) ;
goto V_38;
}
return 0 ;
V_38:
if ( V_16 ) {
if ( V_16 -> V_18 )
F_16 ( V_16 -> V_18 ) ;
F_17 ( V_16 ) ;
}
return - V_49 ;
}
static
#endif
int F_18 ( struct V_2 * V_15 )
{
T_2 * V_16 , * V_50 ;
V_16 = V_45 ;
V_47 . V_51 ( V_16 -> V_46 ) ;
F_16 ( V_16 -> V_18 ) ;
for ( V_16 = V_45 , V_50 = NULL ; V_16 ; V_16 = V_16 -> V_44 ) {
if ( V_16 -> V_15 == ( void * ) V_15 ) {
if ( V_50 )
V_50 -> V_44 = V_16 -> V_44 ;
else
V_45 = NULL ;
break;
}
V_50 = V_16 ;
}
if ( ! V_16 ) {
F_11 ( ( L_5 , V_36 ) ) ;
return 0 ;
}
F_17 ( V_16 ) ;
#if ! F_5 ( V_19 )
F_19 ( V_15 , NULL ) ;
#endif
return 0 ;
}
int F_20 ( T_5 * V_52 )
{
V_47 = * V_52 ;
F_11 ( ( L_6 ) ) ;
return F_21 () ;
}
void F_22 ( void )
{
F_23 () ;
}
void F_24 ( bool V_53 )
{
static bool V_54 = 1 ;
unsigned long V_55 ;
F_25 ( & V_45 -> V_43 , V_55 ) ;
if ( V_54 != V_53 ) {
if ( V_53 )
F_26 ( V_45 -> V_40 ) ;
else
F_27 ( V_45 -> V_40 ) ;
V_54 = V_53 ;
}
F_28 ( & V_45 -> V_43 , V_55 ) ;
}
static T_6 F_29 ( int V_25 , void * V_56 )
{
T_7 * V_57 ;
V_57 = ( T_7 * ) F_30 ( V_45 -> V_15 ) ;
F_24 ( 0 ) ;
if ( V_57 == NULL ) {
F_11 ( ( L_7 ) ) ;
return V_58 ;
}
F_31 ( ( void * ) V_57 -> V_59 ) ;
return V_58 ;
}
int F_32 ( void * V_57 )
{
int error = 0 ;
F_11 ( ( L_8 , V_36 ) ) ;
V_45 -> V_41 =
V_32 | V_33 |
V_34 ;
F_19 ( V_45 -> V_15 , V_57 ) ;
if ( ! V_45 -> V_42 ) {
F_11 ( ( L_9 , V_36 ,
( int ) V_45 -> V_40 , ( int ) V_45 -> V_41 ) ) ;
error =
F_33 ( V_45 -> V_40 , F_29 ,
V_45 -> V_41 , L_10 , NULL ) ;
if ( error )
return - V_49 ;
F_34 ( V_45 -> V_40 , 1 ) ;
V_45 -> V_42 = true ;
}
return 0 ;
}
void F_35 ( void )
{
F_11 ( ( L_11 , V_36 ) ) ;
F_34 ( V_45 -> V_40 , 0 ) ;
F_36 ( V_45 -> V_40 ) ;
F_37 ( V_45 -> V_40 , NULL ) ;
V_45 -> V_42 = false ;
}
