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
static T_3 F_12 ( int V_25 , void * V_26 )
{
F_13 ( ! F_14 () ) ;
if ( ( V_27 . V_13 == V_16 )
&& ( F_1 ( V_28 ) & V_29 ) ) {
unsigned V_30 ;
V_30 = F_8 ( F_1 ( V_17 ) ) ;
do {
V_9 += V_11 ;
V_27 . V_31 ( & V_27 ) ;
V_30 -- ;
} while ( V_30 );
return V_32 ;
}
return V_33 ;
}
static void F_15 ( void )
{
F_3 ( V_18 , 0 ) ;
while ( F_9 ( F_1 ( V_17 ) ) != 0 )
F_16 () ;
F_3 ( V_18 , ( V_11 - 1 ) | V_19 ) ;
}
static int T_4 F_17 ( void )
{
struct V_34 * V_35 ;
int V_36 ;
V_35 = F_18 ( NULL , V_37 ) ;
if ( ! V_35 )
goto V_38;
V_2 = F_19 ( V_35 , 0 ) ;
if ( ! V_2 )
goto V_39;
V_36 = F_20 ( V_35 , 0 ) ;
if ( ! V_36 ) {
F_21 ( L_1 ) ;
goto V_40;
}
V_41 . V_25 = V_36 ;
F_22 ( V_35 ) ;
return 0 ;
V_40:
F_23 ( V_2 ) ;
V_39:
F_22 ( V_35 ) ;
V_38:
return - V_42 ;
}
static int T_4 F_17 ( void )
{
return - V_42 ;
}
static void T_4 F_24 ( void )
{
unsigned long V_43 ;
unsigned V_44 ;
int V_36 ;
F_17 () ;
V_43 = F_25 ( F_26 ( NULL , L_2 ) ) / 16 ;
V_11 = ( V_43 + V_45 / 2 ) / V_45 ;
F_27 ( ( ( V_11 - 1 ) & ~ V_46 ) != 0 ) ;
F_15 () ;
V_44 = 12 + F_28 ( V_11 ) ;
V_47 . V_48 = F_29 ( V_44 ) ;
F_30 ( & V_47 , V_43 ) ;
V_36 = F_31 ( V_41 . V_25 , & V_41 ) ;
if ( V_36 )
F_21 ( L_3 ) ;
V_27 . V_49 = F_32 ( V_43 , V_50 , V_27 . V_51 ) ;
V_27 . V_52 = F_33 ( 0 ) ;
F_34 ( & V_27 ) ;
}
static void F_35 ( void )
{
F_3 ( V_18 , 0 ) ;
}
void T_4 F_36 ( T_2 V_53 )
{
#if F_37 ( V_54 )
struct V_34 * V_35 =
F_18 ( NULL , V_37 ) ;
if ( V_35 ) {
F_22 ( V_35 ) ;
return;
}
#endif
V_2 = F_38 ( V_53 , 16 ) ;
if ( ! V_2 )
F_39 ( L_4 ) ;
}
