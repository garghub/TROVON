static inline unsigned long F_1 ( void )
{
unsigned int V_1 , V_2 ;
F_2 ( V_3 , V_4 , & V_1 ) ;
do {
F_2 ( V_3 , V_4 , & V_2 ) ;
if ( V_1 == V_2 )
break;
V_1 = V_2 ;
} while ( 1 );
return V_1 ;
}
static T_1 F_3 ( int V_5 , void * V_6 )
{
T_2 V_7 ;
F_2 ( V_3 , V_8 , & V_7 ) ;
V_7 &= V_9 ;
F_4 ( ! F_5 () ) ;
if ( V_7 & V_10 ) {
V_11 . V_12 ( & V_11 ) ;
return V_13 ;
}
if ( V_7 & V_14 ) {
T_2 V_15 = F_1 () ;
while ( ( ( V_15 - V_16 ) & V_17 ) >= V_18 ) {
V_16 += V_18 ;
V_11 . V_12 ( & V_11 ) ;
}
return V_13 ;
}
return V_19 ;
}
static T_3 F_6 ( struct V_20 * V_21 )
{
return F_1 () ;
}
static void
F_7 ( enum V_22 V_23 , struct V_24 * V_25 )
{
unsigned int V_26 ;
F_8 ( V_3 , V_27 , V_14 | V_10 ) ;
F_2 ( V_3 , V_8 , & V_26 ) ;
V_16 = F_1 () ;
switch ( V_23 ) {
case V_28 :
V_9 = V_14 ;
F_8 ( V_3 , V_29 , V_18 ) ;
break;
case V_30 :
V_9 = V_10 ;
F_8 ( V_3 , V_31 , V_16 ) ;
break;
case V_32 :
case V_33 :
case V_34 :
V_9 = 0 ;
break;
}
F_8 ( V_3 , V_35 , V_9 ) ;
}
static int
F_9 ( unsigned long V_36 , struct V_24 * V_25 )
{
T_2 V_37 ;
int V_38 = 0 ;
unsigned int V_26 ;
F_10 ( V_36 < 2 ) ;
V_37 = F_1 () ;
F_8 ( V_3 , V_31 , V_37 ) ;
F_2 ( V_3 , V_8 , & V_26 ) ;
V_37 += V_36 ;
F_8 ( V_3 , V_31 , V_37 ) ;
return V_38 ;
}
static void T_4 F_11 ( struct V_39 * V_40 )
{
unsigned int V_26 ;
int V_5 , V_41 ;
V_3 = F_12 ( V_40 ) ;
if ( F_13 ( V_3 ) )
F_14 ( F_15 ( L_1 ) ) ;
F_8 ( V_3 , V_27 ,
V_14 | V_42 | V_43 | V_10 ) ;
F_2 ( V_3 , V_8 , & V_26 ) ;
V_5 = F_16 ( V_40 , 0 ) ;
if ( ! V_5 )
F_14 ( F_15 ( L_2 ) ) ;
V_41 = F_17 ( V_5 , F_3 ,
V_44 | V_45 | V_46 ,
L_3 , V_3 ) ;
if ( V_41 )
F_14 ( F_15 ( L_4 ) ) ;
F_8 ( V_3 , V_47 , 1 ) ;
V_11 . V_48 = F_18 ( 0 ) ;
F_19 ( & V_11 , V_49 ,
2 , V_50 ) ;
F_20 ( & V_51 , V_49 ) ;
}
