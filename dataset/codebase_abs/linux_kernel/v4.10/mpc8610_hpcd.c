static T_1 F_1 ( int V_1 , void * V_2 )
{
F_2 ( L_1 , V_3 ) ;
return V_4 ;
}
static void T_2 F_3 ( void )
{
int V_1 ;
int V_5 ;
if ( ! V_6 )
return;
V_1 = F_4 ( V_6 , 0 ) ;
if ( ! V_1 ) {
F_5 ( L_2 , V_3 ) ;
return;
}
V_5 = F_6 ( V_1 , F_1 , 0 , L_3 , NULL ) ;
if ( V_5 ) {
F_5 ( L_4 ,
V_3 , V_5 ) ;
F_7 ( V_1 ) ;
}
F_8 ( V_1 ) ;
}
static inline void F_3 ( void ) { }
static int T_2 F_9 ( void )
{
F_10 ( L_5 ) ;
F_3 () ;
F_11 () ;
F_12 ( NULL , V_7 , NULL ) ;
return 0 ;
}
T_3 F_13 ( enum V_8 V_9 ,
unsigned int V_10 )
{
static const T_3 V_11 [] [ 3 ] = {
{
F_14 ( 3 , 0 , 2 , 1 , 3 , 8 , 8 , 8 , 8 ) ,
F_14 ( 4 , 2 , 0 , 1 , 2 , 8 , 8 , 8 , 0 ) ,
F_14 ( 4 , 0 , 2 , 1 , 1 , 5 , 6 , 5 , 0 )
} ,
{
F_14 ( 3 , 2 , 0 , 1 , 3 , 8 , 8 , 8 , 8 ) ,
F_14 ( 4 , 0 , 2 , 1 , 2 , 8 , 8 , 8 , 0 ) ,
F_14 ( 4 , 2 , 0 , 1 , 1 , 5 , 6 , 5 , 0 )
} ,
} ;
unsigned int V_12 ;
V_12 =
( ( * V_13 == 0x01 ) && ( V_9 == V_14 ) ) ? 0 : 1 ;
switch ( V_10 ) {
case 32 :
return V_11 [ V_12 ] [ 0 ] ;
case 24 :
return V_11 [ V_12 ] [ 1 ] ;
case 16 :
return V_11 [ V_12 ] [ 2 ] ;
default:
F_5 ( L_6 , V_10 ) ;
return 0 ;
}
}
void F_15 ( enum V_8 V_9 ,
char * V_15 )
{
int V_16 ;
if ( V_9 == V_17 ) {
for ( V_16 = 0 ; V_16 < 256 * 3 ; V_16 ++ )
V_15 [ V_16 ] = ( V_15 [ V_16 ] << 2 ) |
( ( V_15 [ V_16 ] >> 6 ) & 0x03 ) ;
}
}
void F_16 ( enum V_8 V_9 )
{
switch ( V_9 ) {
case V_14 :
F_17 ( V_18 , V_19 ,
V_20 | V_21 ) ;
break;
case V_22 :
F_17 ( V_18 , V_19 ,
V_21 ) ;
break;
case V_17 :
F_18 ( V_18 , V_19 ) ;
break;
}
}
void F_19 ( unsigned int V_23 )
{
struct V_24 * V_25 = NULL ;
struct V_26 T_4 * V_27 ;
unsigned long V_28 ;
T_5 V_29 ;
T_3 V_30 ;
V_25 = F_20 ( NULL , NULL , L_7 ) ;
if ( ! V_25 ) {
F_5 ( L_8 ) ;
return;
}
V_27 = F_21 ( V_25 , 0 ) ;
F_22 ( V_25 ) ;
if ( ! V_27 ) {
F_5 ( L_9 ) ;
return;
}
V_29 = 1000000000000ULL ;
F_23 ( V_29 , V_23 ) ;
V_28 = V_29 ;
V_30 = F_24 ( F_25 () , V_28 ) - 1 ;
V_30 = F_26 ( T_3 , V_30 , 2 , 31 ) ;
F_27 ( & V_27 -> V_31 ,
V_32 | V_33 | V_34 ) ;
F_28 ( & V_27 -> V_31 , V_32 | ( V_30 << 16 ) ) ;
F_29 ( V_27 ) ;
}
enum V_8
F_30 ( enum V_8 V_9 )
{
return V_9 ;
}
static void T_2 F_31 ( void )
{
struct V_35 V_36 ;
unsigned char * V_37 ;
if ( V_38 . V_39 )
V_38 . V_39 ( L_10 , 0 ) ;
F_32 () ;
#if F_33 ( V_40 ) || F_33 ( V_41 )
V_42 . V_43 = F_13 ;
V_42 . V_44 = F_15 ;
V_42 . V_45 = F_16 ;
V_42 . V_46 = F_19 ;
V_42 . V_47 = F_30 ;
#endif
V_6 = F_20 ( NULL , NULL , L_11 ) ;
if ( V_6 ) {
F_34 ( V_6 , 0 , & V_36 ) ;
F_22 ( V_6 ) ;
V_37 = F_35 ( V_36 . V_48 , 32 ) ;
if ( ! V_37 ) {
F_36 ( V_49 L_12 ) ;
return;
}
V_18 = V_37 + 8 ;
V_13 = V_37 + 1 ;
} else
F_36 ( V_49 L_13
L_14 ) ;
F_36 ( L_15 ) ;
}
static int T_2 F_37 ( void )
{
if ( F_38 ( L_16 ) )
return 1 ;
return 0 ;
}
