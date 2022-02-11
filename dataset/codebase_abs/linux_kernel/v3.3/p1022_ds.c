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
struct V_27 * V_27 = F_21 ( NULL , 0 ,
V_28 |
V_29 | V_30 |
V_31 ,
0 , 256 , L_11 ) ;
F_22 ( V_27 == NULL ) ;
F_23 ( V_27 ) ;
}
static void T_5 F_24 ( void )
{
#ifdef F_25
struct V_5 * V_6 ;
#endif
T_6 V_32 = 0xffffffff ;
if ( V_33 . V_34 )
V_33 . V_34 ( L_12 , 0 ) ;
#ifdef F_25
F_26 (np, L_13 , L_14 ) {
struct V_35 V_36 ;
struct V_37 * V_38 ;
F_27 ( V_6 , 0 , & V_36 ) ;
if ( ( V_36 . V_39 & 0xfffff ) == 0x8000 )
F_28 ( V_6 , 1 ) ;
else
F_28 ( V_6 , 0 ) ;
V_38 = F_29 ( V_6 ) ;
V_32 = F_30 ( V_32 , V_38 -> V_40 +
V_38 -> V_41 ) ;
}
#endif
#if F_31 ( V_42 ) || F_31 ( V_43 )
V_44 . V_45 = F_1 ;
V_44 . V_46 = F_4 ;
V_44 . V_47 = F_5 ;
V_44 . V_48 = F_11 ;
V_44 . V_49 = F_19 ;
#endif
F_32 () ;
#ifdef F_33
if ( F_34 () > V_32 ) {
V_50 = 1 ;
F_35 ( & V_51 ) ;
V_33 . V_52 = V_53 ;
}
#endif
F_36 ( L_15 ) ;
}
static int T_5 F_37 ( void )
{
F_38 () ;
return F_39 ( NULL , V_54 , NULL ) ;
}
static int T_5 F_40 ( void )
{
unsigned long V_55 = F_41 () ;
return F_42 ( V_55 , L_16 ) ;
}
