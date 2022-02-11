static inline unsigned long F_1 ( void )
{
unsigned long V_1 , V_2 ;
V_1 = F_2 ( V_3 ) ;
do {
V_2 = F_2 ( V_3 ) ;
if ( V_1 == V_2 )
break;
V_1 = V_2 ;
} while ( 1 );
return V_1 ;
}
static T_1 F_3 ( int V_4 , void * V_5 )
{
T_2 V_6 = F_2 ( V_7 ) & V_8 ;
F_4 ( ! F_5 () ) ;
if ( V_6 & V_9 ) {
V_10 . V_11 ( & V_10 ) ;
return V_12 ;
}
if ( V_6 & V_13 ) {
T_2 V_14 = F_1 () ;
while ( ( ( V_14 - V_15 ) & V_16 ) >= V_17 ) {
V_15 += V_17 ;
V_10 . V_11 ( & V_10 ) ;
}
return V_12 ;
}
return V_18 ;
}
static T_3 F_6 ( struct V_19 * V_20 )
{
return F_1 () ;
}
static void
F_7 ( enum V_21 V_22 , struct V_23 * V_24 )
{
F_8 ( V_25 , V_13 | V_9 ) ;
F_2 ( V_7 ) ;
V_15 = F_1 () ;
switch ( V_22 ) {
case V_26 :
V_8 = V_13 ;
F_8 ( V_27 , V_17 ) ;
break;
case V_28 :
V_8 = V_9 ;
F_8 ( V_29 , V_15 ) ;
break;
case V_30 :
case V_31 :
case V_32 :
V_8 = 0 ;
break;
}
F_8 ( V_33 , V_8 ) ;
}
static int
F_9 ( unsigned long V_34 , struct V_23 * V_24 )
{
T_2 V_35 ;
int V_36 = 0 ;
F_10 ( V_34 < 2 ) ;
V_35 = F_1 () ;
F_8 ( V_29 , V_35 ) ;
F_2 ( V_7 ) ;
V_35 += V_34 ;
F_8 ( V_29 , V_35 ) ;
return V_36 ;
}
void T_4 F_11 ( T_2 V_37 )
{
V_38 = F_12 ( V_37 , 256 ) ;
if ( ! V_38 )
F_13 ( L_1 ) ;
}
void T_4 F_14 ( void )
{
F_8 ( V_25 ,
V_13 | V_39 | V_40 | V_9 ) ;
F_2 ( V_7 ) ;
F_15 ( V_41 + V_42 , & V_43 ) ;
F_8 ( V_44 , 1 ) ;
V_10 . V_45 = F_16 ( V_46 , V_47 , V_10 . V_48 ) ;
V_10 . V_49 = F_17 ( V_50 , & V_10 ) ;
V_10 . V_51 = F_17 ( 2 , & V_10 ) + 1 ;
V_10 . V_52 = F_18 ( 0 ) ;
F_19 ( & V_10 ) ;
F_20 ( & V_53 , V_46 ) ;
}
