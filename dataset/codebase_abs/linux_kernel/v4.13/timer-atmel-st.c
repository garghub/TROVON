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
static void F_7 ( void )
{
unsigned int V_22 ;
F_8 ( V_3 , V_23 , V_14 | V_10 ) ;
F_2 ( V_3 , V_8 , & V_22 ) ;
V_16 = F_1 () ;
}
static int F_9 ( struct V_24 * V_25 )
{
F_7 () ;
V_9 = 0 ;
F_8 ( V_3 , V_26 , V_9 ) ;
return 0 ;
}
static int F_10 ( struct V_24 * V_27 )
{
F_7 () ;
V_9 = V_10 ;
F_8 ( V_3 , V_28 , V_16 ) ;
F_8 ( V_3 , V_26 , V_9 ) ;
return 0 ;
}
static int F_11 ( struct V_24 * V_27 )
{
F_7 () ;
V_9 = V_14 ;
F_8 ( V_3 , V_29 , V_18 ) ;
F_8 ( V_3 , V_26 , V_9 ) ;
return 0 ;
}
static int
F_12 ( unsigned long V_30 , struct V_24 * V_27 )
{
T_2 V_31 ;
int V_32 = 0 ;
unsigned int V_22 ;
F_13 ( V_30 < 2 ) ;
V_31 = F_1 () ;
F_8 ( V_3 , V_28 , V_31 ) ;
F_2 ( V_3 , V_8 , & V_22 ) ;
V_31 += V_30 ;
F_8 ( V_3 , V_28 , V_31 ) ;
return V_32 ;
}
static int T_4 F_14 ( struct V_33 * V_34 )
{
struct V_35 * V_36 ;
unsigned int V_37 , V_22 ;
int V_5 , V_38 ;
V_3 = F_15 ( V_34 ) ;
if ( F_16 ( V_3 ) ) {
F_17 ( L_1 ) ;
return F_18 ( V_3 ) ;
}
F_8 ( V_3 , V_23 ,
V_14 | V_39 | V_40 | V_10 ) ;
F_2 ( V_3 , V_8 , & V_22 ) ;
V_5 = F_19 ( V_34 , 0 ) ;
if ( ! V_5 ) {
F_17 ( L_2 ) ;
return - V_41 ;
}
V_38 = F_20 ( V_5 , F_3 ,
V_42 | V_43 | V_44 ,
L_3 , V_3 ) ;
if ( V_38 ) {
F_17 ( L_4 ) ;
return V_38 ;
}
V_36 = F_21 ( V_34 , 0 ) ;
if ( F_16 ( V_36 ) ) {
F_17 ( L_5 ) ;
return F_18 ( V_36 ) ;
}
V_38 = F_22 ( V_36 ) ;
if ( V_38 ) {
F_17 ( L_6 ) ;
return V_38 ;
}
V_37 = F_23 ( V_36 ) ;
if ( ! V_37 ) {
F_17 ( L_7 ) ;
return - V_41 ;
}
V_18 = ( V_37 + V_45 / 2 ) / V_45 ;
F_8 ( V_3 , V_46 , 1 ) ;
V_11 . V_47 = F_24 ( 0 ) ;
F_25 ( & V_11 , V_37 ,
2 , V_48 ) ;
return F_26 ( & V_49 , V_37 ) ;
}
