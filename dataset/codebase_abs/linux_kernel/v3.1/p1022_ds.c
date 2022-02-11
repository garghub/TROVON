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
void T_1 * V_6 ;
T_2 T_1 * V_7 ;
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
V_7 = V_6 + 9 ;
switch ( V_2 ) {
case 0 :
F_8 ( V_7 , V_8 | V_9 ,
V_10 ) ;
break;
case 1 :
F_8 ( V_7 , V_10 | V_9 ,
V_8 ) ;
break;
default:
F_3 ( L_5 , V_2 ) ;
}
F_9 ( V_6 ) ;
}
void F_10 ( unsigned int V_11 )
{
struct V_4 * V_12 = NULL ;
struct V_13 T_1 * V_14 ;
unsigned long V_15 ;
T_3 V_16 ;
T_4 V_17 ;
V_12 = F_6 ( NULL , NULL , L_6 ) ;
if ( ! V_12 ) {
F_3 ( L_7 ) ;
return;
}
V_14 = F_7 ( V_12 , 0 ) ;
F_11 ( V_12 ) ;
if ( ! V_14 ) {
F_3 ( L_8 ) ;
return;
}
V_16 = 1000000000000ULL ;
F_12 ( V_16 , V_11 ) ;
V_15 = V_16 ;
V_17 = F_13 ( F_14 () , V_15 ) ;
V_17 = F_15 ( T_4 , V_17 , 2 , 255 ) ;
F_16 ( & V_14 -> V_18 ,
V_19 | V_20 | V_21 ) ;
F_17 ( & V_14 -> V_18 , V_19 | ( V_17 << 16 ) ) ;
F_9 ( V_14 ) ;
}
T_5 F_18 ( int V_2 , char * V_22 )
{
return sprintf ( V_22 , L_9 ,
V_2 == 0 ? '*' : ' ' , V_2 == 1 ? '*' : ' ' ) ;
}
int F_19 ( int V_23 )
{
return V_23 < 2 ? V_23 : 0 ;
}
void T_6 F_20 ( void )
{
struct V_24 * V_24 ;
struct V_25 V_26 ;
struct V_4 * V_27 ;
V_27 = F_21 ( NULL , L_10 ) ;
if ( ! V_27 ) {
F_3 ( L_11 ) ;
return;
}
if ( F_22 ( V_27 , 0 , & V_26 ) ) {
F_3 ( L_12 ) ;
F_11 ( V_27 ) ;
return;
}
V_24 = F_23 ( V_27 , V_26 . V_28 ,
V_29 | V_30 |
V_31 | V_32 |
V_33 ,
0 , 256 , L_13 ) ;
F_24 ( V_24 == NULL ) ;
F_11 ( V_27 ) ;
F_25 ( V_24 ) ;
}
static void T_6 F_26 ( void )
{
#ifdef F_27
struct V_4 * V_27 ;
#endif
T_7 V_34 = 0xffffffff ;
if ( V_35 . V_36 )
V_35 . V_36 ( L_14 , 0 ) ;
#ifdef F_27
F_28 (np, L_15 , L_16 ) {
struct V_25 V_37 ;
struct V_38 * V_39 ;
F_22 ( V_27 , 0 , & V_37 ) ;
if ( ( V_37 . V_28 & 0xfffff ) == 0x8000 )
F_29 ( V_27 , 1 ) ;
else
F_29 ( V_27 , 0 ) ;
V_39 = F_30 ( V_27 ) ;
V_34 = F_31 ( V_34 , V_39 -> V_40 +
V_39 -> V_41 ) ;
}
#endif
#if F_32 ( V_42 ) || F_32 ( V_43 )
V_44 . V_45 = F_1 ;
V_44 . V_46 = F_4 ;
V_44 . V_47 = F_5 ;
V_44 . V_48 = F_10 ;
V_44 . V_49 = F_18 ;
V_44 . V_50 = F_19 ;
#endif
#ifdef F_33
F_34 () ;
#endif
#ifdef F_35
if ( F_36 () > V_34 ) {
V_51 = 1 ;
F_37 ( & V_52 ) ;
V_35 . V_53 = V_54 ;
}
#endif
F_38 ( L_17 ) ;
}
static int T_6 F_39 ( void )
{
return F_40 ( NULL , V_55 , NULL ) ;
}
static int T_6 F_41 ( void )
{
unsigned long V_56 = F_42 () ;
return F_43 ( V_56 , L_18 ) ;
}
