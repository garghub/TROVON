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
static void T_4 F_17 ( void )
{
unsigned long V_34 ;
unsigned V_35 ;
V_34 = F_18 ( F_19 ( NULL , L_1 ) ) / 16 ;
V_11 = ( V_34 + V_36 / 2 ) / V_36 ;
F_20 ( ( ( V_11 - 1 ) & ~ V_37 ) != 0 ) ;
F_15 () ;
V_35 = 12 + F_21 ( V_11 ) ;
V_38 . V_39 = F_22 ( V_35 ) ;
F_23 ( & V_38 , V_34 ) ;
F_24 ( V_40 , & V_41 ) ;
V_27 . V_42 = F_25 ( V_34 , V_43 , V_27 . V_44 ) ;
V_27 . V_45 = F_26 ( 0 ) ;
F_27 ( & V_27 ) ;
}
static void F_28 ( void )
{
F_3 ( V_18 , 0 ) ;
}
void T_4 F_29 ( T_2 V_46 )
{
V_2 = F_30 ( V_46 , 16 ) ;
if ( ! V_2 )
F_31 ( L_2 ) ;
}
