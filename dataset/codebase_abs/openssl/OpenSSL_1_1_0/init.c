static void F_1 ( void * V_1 )
{
F_2 ( (struct V_2 * ) V_1 ) ;
}
static struct V_2 * F_3 ( int V_3 )
{
struct V_2 * V_1 =
F_4 ( & V_4 ) ;
if ( V_1 == NULL && V_3 ) {
V_1 = F_5 ( sizeof *V_1 ) ;
F_6 ( & V_4 , V_1 ) ;
}
if ( ! V_3 ) {
F_6 ( & V_4 , NULL ) ;
}
return V_1 ;
}
static void F_2 ( struct V_2 * V_5 )
{
if ( V_5 == NULL )
return;
if ( V_5 -> V_6 ) {
#ifdef F_7
fprintf ( V_7 , L_1
L_2 ) ;
#endif
F_8 () ;
}
if ( V_5 -> V_8 ) {
#ifdef F_7
fprintf ( V_7 , L_1
L_3 ) ;
#endif
F_9 () ;
}
F_10 ( V_5 ) ;
}
void F_11 ( void )
{
F_2 (
(struct V_2 * ) F_3 ( 0 ) ) ;
}
int F_12 ( T_1 V_9 )
{
struct V_2 * V_5 = F_3 ( 1 ) ;
if ( V_5 == NULL )
return 0 ;
if ( V_9 & V_10 ) {
#ifdef F_7
fprintf ( V_7 , L_4
L_5 ) ;
#endif
V_5 -> V_6 = 1 ;
}
if ( V_9 & V_11 ) {
#ifdef F_7
fprintf ( V_7 , L_4
L_6 ) ;
#endif
V_5 -> V_8 = 1 ;
}
return 1 ;
}
void F_13 ( void )
{
T_2 * V_12 , * V_13 ;
if ( ! V_14 )
return;
if ( V_15 )
return;
V_15 = 1 ;
F_2 ( F_3 ( 0 ) ) ;
V_12 = V_16 ;
while ( V_12 != NULL ) {
V_12 -> V_17 () ;
V_13 = V_12 ;
V_12 = V_12 -> V_18 ;
F_10 ( V_13 ) ;
}
V_16 = NULL ;
F_14 ( V_19 ) ;
#ifndef F_15
if ( V_20 ) {
#ifdef F_7
fprintf ( V_7 , L_7
L_8 ) ;
#endif
F_16 () ;
}
#endif
if ( V_21 ) {
# ifdef F_7
fprintf ( V_7 , L_7
L_9 ) ;
# endif
F_17 () ;
}
if ( V_22 ) {
#ifdef F_7
fprintf ( V_7 , L_7
L_10 ) ;
#endif
F_18 () ;
}
F_19 ( & V_4 ) ;
#ifdef F_7
fprintf ( V_7 , L_7
L_11 ) ;
fprintf ( V_7 , L_7
L_12 ) ;
#ifndef F_20
fprintf ( V_7 , L_7
L_13 ) ;
#endif
fprintf ( V_7 , L_7
L_14 ) ;
fprintf ( V_7 , L_7
L_15 ) ;
fprintf ( V_7 , L_7
L_16 ) ;
fprintf ( V_7 , L_7
L_17 ) ;
fprintf ( V_7 , L_7
L_18 ) ;
fprintf ( V_7 , L_7
L_19 ) ;
#endif
F_21 () ;
F_22 () ;
#ifndef F_20
F_23 () ;
#endif
F_24 () ;
F_25 () ;
F_26 () ;
F_27 () ;
F_28 () ;
V_14 = 0 ;
}
int F_29 ( T_1 V_9 , const T_3 * V_23 )
{
static int V_24 = 0 ;
if ( V_15 ) {
if ( ! V_24 ) {
V_24 = 1 ;
F_30 ( V_25 , V_26 ) ;
}
return 0 ;
}
if ( ! F_31 ( & V_27 , V_28 ) )
return 0 ;
if ( ( V_9 & V_29 )
&& ! F_31 ( & V_30 ,
V_31 ) )
return 0 ;
if ( ( V_9 & V_32 )
&& ! F_31 ( & V_30 , V_33 ) )
return 0 ;
if ( ( V_9 & V_34 )
&& ! F_31 ( & V_35 , V_36 ) )
return 0 ;
if ( ( V_9 & V_37 )
&& ! F_31 ( & V_35 , V_38 ) )
return 0 ;
if ( ( V_9 & V_39 )
&& ! F_31 ( & V_40 , V_36 ) )
return 0 ;
if ( ( V_9 & V_41 )
&& ! F_31 ( & V_40 , V_42 ) )
return 0 ;
if ( ( V_9 & V_43 )
&& ! F_31 ( & V_44 , V_45 ) )
return 0 ;
if ( V_9 & V_46 ) {
int V_47 ;
F_32 ( V_19 ) ;
V_48 = ( V_23 == NULL ) ? NULL : V_23 -> V_48 ;
V_47 = F_31 ( & V_44 , V_49 ) ;
F_33 ( V_19 ) ;
if ( ! V_47 )
return 0 ;
}
if ( ( V_9 & V_50 )
&& ! F_31 ( & V_6 , V_51 ) )
return 0 ;
#ifndef F_20
if ( ( V_9 & V_52 )
&& ! F_31 ( & V_53 , V_54 ) )
return 0 ;
# if ! F_34 ( V_55 ) && \
( F_34 ( V_56 ) || F_34 ( V_57 ) || F_34 ( V_58 ) )
if ( ( V_9 & V_59 )
&& ! F_31 ( & V_60 , V_61 ) )
return 0 ;
# endif
# ifndef F_35
if ( ( V_9 & V_62 )
&& ! F_31 ( & V_63 , V_64 ) )
return 0 ;
# endif
if ( ( V_9 & V_65 )
&& ! F_31 ( & V_66 , V_67 ) )
return 0 ;
# ifndef F_36
# if ! F_34 ( V_55 ) && ! F_34 ( V_68 )
if ( ( V_9 & V_69 )
&& ! F_31 ( & V_70 , V_71 ) )
return 0 ;
# endif
# if F_34 ( V_72 ) && ! F_34 ( V_73 )
if ( ( V_9 & V_74 )
&& ! F_31 ( & V_75 , V_76 ) )
return 0 ;
# endif
# if ! F_34 ( V_77 )
if ( ( V_9 & V_78 )
&& ! F_31 ( & V_79 , V_80 ) )
return 0 ;
# endif
# endif
if ( V_9 & ( V_81
| V_52
| V_78 ) ) {
F_37 () ;
}
#endif
#ifndef F_15
if ( ( V_9 & V_82 )
&& ! F_31 ( & V_83 , V_84 ) )
return 0 ;
#endif
return 1 ;
}
int F_38 ( void (* V_17)( void ) )
{
T_2 * V_85 ;
V_85 = F_39 ( sizeof( * V_85 ) ) ;
if ( V_85 == NULL )
return 0 ;
V_85 -> V_17 = V_17 ;
V_85 -> V_18 = V_16 ;
V_16 = V_85 ;
return 1 ;
}
