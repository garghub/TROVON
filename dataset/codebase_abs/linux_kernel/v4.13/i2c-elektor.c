static void F_1 ( void * V_1 , int V_2 , int V_3 )
{
T_1 T_2 * V_4 = V_2 ? ( V_5 + 1 ) : V_5 ;
if ( V_2 && V_6 && ( V_3 & V_7 ) ) {
V_3 |= V_8 ;
}
F_2 ( L_1 , V_9 . V_10 , V_4 , V_3 ) ;
F_3 ( V_3 , V_4 ) ;
#ifdef F_4
F_3 ( V_3 , V_4 ) ;
#endif
}
static int F_5 ( void * V_1 , int V_2 )
{
T_1 T_2 * V_4 = V_2 ? ( V_5 + 1 ) : V_5 ;
int V_3 = F_6 ( V_4 ) ;
F_2 ( L_2 , V_9 . V_10 , V_4 , V_3 ) ;
return ( V_3 ) ;
}
static int F_7 ( void * V_1 )
{
return ( V_11 ) ;
}
static int F_8 ( void * V_1 )
{
return ( clock ) ;
}
static void F_9 ( void * V_1 )
{
F_10 ( V_12 ) ;
int V_13 = 2 ;
unsigned long V_14 ;
if ( V_6 > 0 ) {
F_11 ( & V_15 , V_14 ) ;
if ( V_16 == 0 ) {
F_12 ( & V_15 , V_14 ) ;
F_13 ( & V_17 , & V_12 , V_18 ) ;
if ( F_14 ( V_13 * V_19 ) ) {
F_11 ( & V_15 , V_14 ) ;
if ( V_16 == 1 ) {
V_16 = 0 ;
}
F_12 ( & V_15 , V_14 ) ;
}
F_15 ( & V_17 , & V_12 ) ;
} else {
V_16 = 0 ;
F_12 ( & V_15 , V_14 ) ;
}
} else {
F_16 ( 100 ) ;
}
}
static T_3 F_17 ( int V_20 , void * V_21 ) {
F_18 ( & V_15 ) ;
V_16 = 1 ;
F_19 ( & V_15 ) ;
F_20 ( & V_17 ) ;
return V_22 ;
}
static int F_21 ( void )
{
F_22 ( & V_15 ) ;
if ( ! V_23 ) {
if ( ! F_23 ( V_24 , 2 , V_9 . V_10 ) ) {
F_24 ( V_25 L_3
L_4 , V_9 . V_10 , V_24 ) ;
return - V_26 ;
}
V_5 = F_25 ( V_24 , 2 ) ;
if ( ! V_5 ) {
F_24 ( V_25 L_5 ,
V_9 . V_10 , V_24 ) ;
F_26 ( V_24 , 2 ) ;
return - V_26 ;
}
} else {
if ( ! F_27 ( V_24 , 2 , V_9 . V_10 ) ) {
F_24 ( V_25 L_6
L_7 , V_9 . V_10 , V_24 ) ;
return - V_26 ;
}
V_5 = F_28 ( V_24 , 2 ) ;
if ( V_5 == NULL ) {
F_24 ( V_25 L_8
L_9 , V_9 . V_10 , V_24 ) ;
F_29 ( V_24 , 2 ) ;
return - V_26 ;
}
}
F_2 ( L_10 , V_9 . V_10 , V_24 ,
V_5 ) ;
if ( V_6 > 0 ) {
if ( F_30 ( V_6 , F_17 , 0 , V_9 . V_10 ,
NULL ) < 0 ) {
F_24 ( V_25 L_11 ,
V_9 . V_10 , V_6 ) ;
V_6 = 0 ;
} else
F_31 ( V_6 ) ;
}
return 0 ;
}
static int F_32 ( struct V_27 * V_28 , unsigned int V_29 )
{
#ifdef F_4
if ( V_24 == 0 ) {
struct V_30 * V_31 ;
V_31 = F_33 ( V_32 ,
V_33 , NULL ) ;
if ( V_31 ) {
unsigned char V_34 ;
if ( ! F_34 ( V_31 , 0x47 , & V_34 ) ) {
F_35 ( V_28 , L_12
L_13 , V_34 ) ;
if ( ( V_34 & 0x7f ) == 0x61 ) {
V_24 = 0xe0000 ;
V_23 = 1 ;
clock = V_35 | V_36 ;
F_36 ( V_28 , L_14
L_15
L_16 ) ;
}
}
F_37 ( V_31 ) ;
}
}
#endif
if ( V_23 && V_24 < 0xc8000 ) {
F_38 ( V_28 , L_17
L_18 , V_24 ) ;
return 0 ;
}
if ( V_24 == 0 ) {
V_24 = V_37 ;
}
return 1 ;
}
static int F_39 ( struct V_27 * V_28 , unsigned int V_29 )
{
F_40 ( & V_17 ) ;
if ( F_21 () )
return - V_26 ;
V_9 . V_28 . V_38 = V_28 ;
if ( F_41 ( & V_9 ) < 0 )
goto V_39;
F_36 ( V_28 , L_19 , V_24 ) ;
return 0 ;
V_39:
if ( V_6 > 0 ) {
F_42 ( V_6 ) ;
F_43 ( V_6 , NULL ) ;
}
if ( ! V_23 ) {
F_44 ( V_5 ) ;
F_26 ( V_24 , 2 ) ;
} else {
F_45 ( V_5 ) ;
F_29 ( V_24 , 2 ) ;
}
return - V_26 ;
}
static int F_46 ( struct V_27 * V_28 , unsigned int V_29 )
{
F_47 ( & V_9 ) ;
if ( V_6 > 0 ) {
F_42 ( V_6 ) ;
F_43 ( V_6 , NULL ) ;
}
if ( ! V_23 ) {
F_44 ( V_5 ) ;
F_26 ( V_24 , 2 ) ;
} else {
F_45 ( V_5 ) ;
F_29 ( V_24 , 2 ) ;
}
return 0 ;
}
