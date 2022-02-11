static unsigned int F_1 ( unsigned int V_1 ,
int V_2 )
{
switch ( V_1 ) {
case 32 :
return F_2 ( 3 , 2 , 0 , 1 , 3 , 8 , 8 , 8 , 8 ) ;
case 24 :
return F_2 ( 4 , 0 , 1 , 2 , 2 , 0 , 8 , 8 , 8 ) ;
case 16 :
return F_2 ( 4 , 2 , 1 , 0 , 1 , 5 , 6 , 5 , 0 ) ;
default:
F_3 ( L_1 , V_1 ) ;
return 0 ;
}
}
static void F_4 ( int V_2 , char * V_3 )
{
}
static void F_5 ( int V_2 )
{
struct V_4 * V_5 ;
T_1 T_2 * V_6 ;
V_5 = F_6 ( NULL , NULL , L_2 ) ;
if ( ! V_5 ) {
F_3 ( L_3 ) ;
return;
}
V_6 = F_7 ( V_5 , 0 ) ;
if ( ! V_6 ) {
F_3 ( L_4 ) ;
return;
}
V_6 += 9 ;
switch ( V_2 ) {
case 0 :
F_8 ( V_6 , V_7 | V_8 ,
V_9 ) ;
break;
case 1 :
F_8 ( V_6 , V_9 | V_8 ,
V_7 ) ;
break;
default:
F_3 ( L_5 , V_2 ) ;
}
}
void F_9 ( unsigned int V_10 )
{
struct V_4 * V_11 = NULL ;
struct V_12 T_2 * V_13 ;
unsigned long V_14 ;
T_3 V_15 ;
T_4 V_16 ;
V_11 = F_6 ( NULL , NULL , L_6 ) ;
if ( ! V_11 ) {
F_3 ( L_7 ) ;
return;
}
V_13 = F_7 ( V_11 , 0 ) ;
F_10 ( V_11 ) ;
if ( ! V_13 ) {
F_3 ( L_8 ) ;
return;
}
V_15 = 1000000000000ULL ;
F_11 ( V_15 , V_10 ) ;
V_14 = V_15 ;
V_16 = F_12 ( F_13 () , V_14 ) ;
F_14 ( & V_13 -> V_17 ,
V_18 | V_19 | V_20 ) ;
F_15 ( & V_13 -> V_17 , V_18 | ( V_16 << 16 ) ) ;
}
T_5 F_16 ( int V_2 , char * V_21 )
{
return sprintf ( V_21 , L_9 ,
V_2 == 0 ? '*' : ' ' , V_2 == 1 ? '*' : ' ' ) ;
}
int F_17 ( int V_22 )
{
return V_22 < 2 ? V_22 : 0 ;
}
void T_6 F_18 ( void )
{
struct V_23 * V_23 ;
struct V_24 V_25 ;
struct V_4 * V_26 ;
V_26 = F_19 ( NULL , L_10 ) ;
if ( ! V_26 ) {
F_3 ( L_11 ) ;
return;
}
if ( F_20 ( V_26 , 0 , & V_25 ) ) {
F_3 ( L_12 ) ;
F_10 ( V_26 ) ;
return;
}
V_23 = F_21 ( V_26 , V_25 . V_27 ,
V_28 | V_29 |
V_30 | V_31 |
V_32 ,
0 , 256 , L_13 ) ;
F_22 ( V_23 == NULL ) ;
F_10 ( V_26 ) ;
F_23 ( V_23 ) ;
}
static void T_6 F_24 ( void )
{
#ifdef F_25
struct V_4 * V_26 ;
#endif
T_7 V_33 = 0xffffffff ;
if ( V_34 . V_35 )
V_34 . V_35 ( L_14 , 0 ) ;
#ifdef F_25
F_26 (np, L_15 , L_16 ) {
struct V_24 V_36 ;
struct V_37 * V_38 ;
F_20 ( V_26 , 0 , & V_36 ) ;
if ( ( V_36 . V_27 & 0xfffff ) == 0x8000 )
F_27 ( V_26 , 1 ) ;
else
F_27 ( V_26 , 0 ) ;
V_38 = F_28 ( V_26 ) ;
V_33 = F_29 ( V_33 , V_38 -> V_39 +
V_38 -> V_40 ) ;
}
#endif
#if F_30 ( V_41 ) || F_30 ( V_42 )
V_43 . V_44 = F_1 ;
V_43 . V_45 = F_4 ;
V_43 . V_46 = F_5 ;
V_43 . V_47 = F_9 ;
V_43 . V_48 = F_16 ;
V_43 . V_49 = F_17 ;
#endif
#ifdef F_31
F_32 () ;
#endif
#ifdef F_33
if ( F_34 () > V_33 ) {
V_50 = 1 ;
F_35 ( & V_51 ) ;
V_34 . V_52 = V_53 ;
}
#endif
F_36 ( L_17 ) ;
}
static int T_6 F_37 ( void )
{
return F_38 ( NULL , V_54 , NULL ) ;
}
static int T_6 F_39 ( void )
{
unsigned long V_55 = F_40 () ;
return F_41 ( V_55 , L_18 ) ;
}
