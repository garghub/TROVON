static inline unsigned int F_1 ( unsigned int V_1 )
{
return F_2 ( V_2 + V_1 ) ;
}
static inline void F_3 ( unsigned int V_1 , unsigned long V_3 )
{
F_4 ( V_3 , V_2 + V_1 ) ;
}
static T_1 F_5 ( struct V_4 * V_5 )
{
unsigned long V_6 ;
T_2 V_7 ;
T_2 V_8 ;
F_6 ( V_6 ) ;
V_7 = V_9 ;
V_8 = F_1 ( V_10 ) ;
F_7 ( V_6 ) ;
V_7 += F_8 ( V_8 ) * V_11 ;
V_7 += F_9 ( V_8 ) ;
return V_7 ;
}
static void
F_10 ( enum V_12 V_13 , struct V_14 * V_15 )
{
switch ( V_13 ) {
case V_16 :
V_9 += V_11 * F_8 ( F_1 ( V_17 ) ) ;
F_3 ( V_18 , ( V_11 - 1 ) | V_19
| V_20 ) ;
break;
case V_21 :
F_11 () ;
case V_22 :
case V_23 :
F_3 ( V_18 , ( V_11 - 1 ) | V_19 ) ;
break;
case V_24 :
break;
}
}
static void F_12 ( struct V_14 * V_25 )
{
F_3 ( V_18 , 0 ) ;
}
static void F_13 ( void )
{
F_3 ( V_18 , 0 ) ;
while ( F_9 ( F_1 ( V_17 ) ) != 0 )
F_14 () ;
F_3 ( V_18 , ( V_11 - 1 ) | V_19 ) ;
}
static void F_15 ( struct V_14 * V_25 )
{
F_13 () ;
}
static T_3 F_16 ( int V_26 , void * V_27 )
{
F_17 ( ! F_18 () ) ;
if ( ( V_28 . V_13 == V_16 )
&& ( F_1 ( V_29 ) & V_30 ) ) {
unsigned V_31 ;
V_31 = F_8 ( F_1 ( V_17 ) ) ;
do {
V_9 += V_11 ;
V_28 . V_32 ( & V_28 ) ;
V_31 -- ;
} while ( V_31 );
return V_33 ;
}
return V_34 ;
}
static int T_4 F_19 ( void )
{
struct V_35 * V_36 ;
int V_37 ;
V_36 = F_20 ( NULL , V_38 ) ;
if ( ! V_36 )
goto V_39;
V_2 = F_21 ( V_36 , 0 ) ;
if ( ! V_2 )
goto V_40;
V_41 = F_22 ( V_36 , 0 ) ;
V_37 = F_23 ( V_36 , 0 ) ;
if ( ! V_37 ) {
F_24 ( L_1 ) ;
if ( ! F_25 ( V_41 ) )
F_26 ( V_41 ) ;
goto V_42;
}
V_43 . V_26 = V_37 ;
F_27 ( V_36 ) ;
return 0 ;
V_42:
F_28 ( V_2 ) ;
V_40:
F_27 ( V_36 ) ;
V_39:
return - V_44 ;
}
static int T_4 F_19 ( void )
{
return - V_44 ;
}
void T_4 F_29 ( void )
{
unsigned long V_45 ;
unsigned V_46 ;
int V_37 ;
V_41 = F_30 ( - V_47 ) ;
F_19 () ;
if ( F_25 ( V_41 ) )
V_41 = F_31 ( NULL , L_2 ) ;
if ( F_25 ( V_41 ) )
F_32 ( L_3 ) ;
V_45 = F_33 ( V_41 ) / 16 ;
V_11 = ( V_45 + V_48 / 2 ) / V_48 ;
F_34 ( ( ( V_11 - 1 ) & ~ V_49 ) != 0 ) ;
F_13 () ;
V_46 = 12 + F_35 ( V_11 ) ;
V_50 . V_51 = F_36 ( V_46 ) ;
F_37 ( & V_50 , V_45 ) ;
V_37 = F_38 ( V_43 . V_26 , & V_43 ) ;
if ( V_37 )
F_24 ( L_4 ) ;
V_28 . V_52 = F_39 ( V_45 , V_53 , V_28 . V_54 ) ;
V_28 . V_55 = F_40 ( 0 ) ;
F_41 ( & V_28 ) ;
}
void T_4 F_42 ( T_2 V_56 )
{
#if F_43 ( V_57 )
struct V_35 * V_36 =
F_20 ( NULL , V_38 ) ;
if ( V_36 ) {
F_27 ( V_36 ) ;
return;
}
#endif
V_2 = F_44 ( V_56 , 16 ) ;
if ( ! V_2 )
F_32 ( L_5 ) ;
}
