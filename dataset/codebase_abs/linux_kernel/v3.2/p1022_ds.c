static T_1 F_1 ( enum V_1 V_2 ,
unsigned int V_3 )
{
switch ( V_3 ) {
case 32 :
return F_2 ( 3 , 2 , 0 , 1 , 3 , 8 , 8 , 8 , 8 ) ;
case 24 :
return F_2 ( 4 , 0 , 1 , 2 , 2 , 0 , 8 , 8 , 8 ) ;
case 16 :
return F_2 ( 4 , 2 , 1 , 0 , 1 , 5 , 6 , 5 , 0 ) ;
default:
F_3 ( L_1 , V_3 ) ;
return 0 ;
}
}
static void F_4 ( enum V_1 V_2 ,
char * V_4 )
{
}
static void F_5 ( enum V_1 V_2 )
{
struct V_5 * V_6 ;
void T_2 * V_7 ;
T_3 T_2 * V_8 ;
V_6 = F_6 ( NULL , NULL , L_2 ) ;
if ( ! V_6 )
V_6 = F_6 ( NULL , NULL , L_3 ) ;
if ( ! V_6 ) {
F_3 ( L_4 ) ;
return;
}
V_7 = F_7 ( V_6 , 0 ) ;
if ( ! V_7 ) {
F_3 ( L_5 ) ;
return;
}
V_8 = V_7 + 9 ;
switch ( V_2 ) {
case V_9 :
F_8 ( V_10 L_6 , V_11 , __LINE__ ) ;
F_9 ( V_8 , V_12 | V_13 ,
V_14 ) ;
break;
case V_15 :
F_8 ( V_10 L_6 , V_11 , __LINE__ ) ;
F_9 ( V_8 , V_14 | V_13 ,
V_12 ) ;
break;
default:
F_3 ( L_7 , V_2 ) ;
}
F_10 ( V_7 ) ;
}
void F_11 ( unsigned int V_16 )
{
struct V_5 * V_17 = NULL ;
struct V_18 T_2 * V_19 ;
unsigned long V_20 ;
T_4 V_21 ;
T_1 V_22 ;
V_17 = F_6 ( NULL , NULL , L_8 ) ;
if ( ! V_17 ) {
F_3 ( L_9 ) ;
return;
}
V_19 = F_7 ( V_17 , 0 ) ;
F_12 ( V_17 ) ;
if ( ! V_19 ) {
F_3 ( L_10 ) ;
return;
}
V_21 = 1000000000000ULL ;
F_13 ( V_21 , V_16 ) ;
V_20 = V_21 ;
V_22 = F_14 ( F_15 () , V_20 ) ;
V_22 = F_16 ( T_1 , V_22 , 2 , 255 ) ;
F_17 ( & V_19 -> V_23 ,
V_24 | V_25 | V_26 ) ;
F_18 ( & V_19 -> V_23 , V_24 | ( V_22 << 16 ) ) ;
F_10 ( V_19 ) ;
}
enum V_1
F_19 ( enum V_1 V_2 )
{
switch ( V_2 ) {
case V_9 :
case V_15 :
return V_2 ;
default:
return V_9 ;
}
}
void T_5 F_20 ( void )
{
struct V_27 * V_27 ;
struct V_28 V_29 ;
struct V_5 * V_6 ;
V_6 = F_21 ( NULL , L_11 ) ;
if ( ! V_6 ) {
F_3 ( L_12 ) ;
return;
}
if ( F_22 ( V_6 , 0 , & V_29 ) ) {
F_3 ( L_13 ) ;
F_12 ( V_6 ) ;
return;
}
V_27 = F_23 ( V_6 , V_29 . V_30 ,
V_31 | V_32 |
V_33 | V_34 |
V_35 ,
0 , 256 , L_14 ) ;
F_24 ( V_27 == NULL ) ;
F_12 ( V_6 ) ;
F_25 ( V_27 ) ;
}
static void T_5 F_26 ( void )
{
#ifdef F_27
struct V_5 * V_6 ;
#endif
T_6 V_36 = 0xffffffff ;
if ( V_37 . V_38 )
V_37 . V_38 ( L_15 , 0 ) ;
#ifdef F_27
F_28 (np, L_16 , L_17 ) {
struct V_28 V_39 ;
struct V_40 * V_41 ;
F_22 ( V_6 , 0 , & V_39 ) ;
if ( ( V_39 . V_30 & 0xfffff ) == 0x8000 )
F_29 ( V_6 , 1 ) ;
else
F_29 ( V_6 , 0 ) ;
V_41 = F_30 ( V_6 ) ;
V_36 = F_31 ( V_36 , V_41 -> V_42 +
V_41 -> V_43 ) ;
}
#endif
#if F_32 ( V_44 ) || F_32 ( V_45 )
V_46 . V_47 = F_1 ;
V_46 . V_48 = F_4 ;
V_46 . V_49 = F_5 ;
V_46 . V_50 = F_11 ;
V_46 . V_51 = F_19 ;
#endif
#ifdef F_33
F_34 () ;
#endif
#ifdef F_35
if ( F_36 () > V_36 ) {
V_52 = 1 ;
F_37 ( & V_53 ) ;
V_37 . V_54 = V_55 ;
}
#endif
F_38 ( L_18 ) ;
}
static int T_5 F_39 ( void )
{
return F_40 ( NULL , V_56 , NULL ) ;
}
static int T_5 F_41 ( void )
{
unsigned long V_57 = F_42 () ;
return F_43 ( V_57 , L_19 ) ;
}
