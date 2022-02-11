static int F_1 ( void T_1 * V_1 , unsigned int V_2 )
{
unsigned long V_3 ;
unsigned long V_4 = V_5 + 3 * V_6 ;
do {
V_3 = V_5 ;
if ( F_2 ( V_1 + V_2 ) & V_7 )
F_3 () ;
else
return 0 ;
} while ( ! F_4 ( V_3 , V_4 ) );
return - V_8 ;
}
static int F_5 ( struct V_9 * V_10 , int V_11 , int V_12 )
{
struct V_13 * V_14 = V_10 -> V_15 ;
struct V_16 * V_15 = F_6 ( V_14 ) ;
unsigned int V_17 = V_15 -> V_18 -> V_19 . V_20 ;
unsigned int V_21 = V_15 -> V_18 -> V_19 . V_22 ;
int V_22 ;
T_2 V_23 = ( ( ( V_11 << 11 ) & ( 0x0000F800 ) ) |
( ( V_12 << 6 ) & ( 0x000007C0 ) ) ) ;
V_23 |= V_7 | ( ( V_15 -> V_24 & 0xF ) << 2 ) ;
if ( F_1 ( V_15 -> V_1 , V_17 ) )
return - V_8 ;
F_7 ( V_23 , V_15 -> V_1 + V_17 ) ;
if ( F_1 ( V_15 -> V_1 , V_17 ) )
return - V_8 ;
V_22 = ( int ) F_2 ( V_15 -> V_1 + V_21 ) ;
return V_22 ;
}
static int F_8 ( struct V_9 * V_10 , int V_11 , int V_12 ,
T_2 V_25 )
{
struct V_13 * V_14 = V_10 -> V_15 ;
struct V_16 * V_15 = F_6 ( V_14 ) ;
unsigned int V_17 = V_15 -> V_18 -> V_19 . V_20 ;
unsigned int V_21 = V_15 -> V_18 -> V_19 . V_22 ;
T_2 V_26 =
( ( ( V_11 << 11 ) & ( 0x0000F800 ) ) | ( ( V_12 << 6 ) & ( 0x000007C0 ) ) )
| V_27 ;
V_26 |= V_7 | ( ( V_15 -> V_24 & 0xF ) << 2 ) ;
if ( F_1 ( V_15 -> V_1 , V_17 ) )
return - V_8 ;
F_7 ( V_25 , V_15 -> V_1 + V_21 ) ;
F_7 ( V_26 , V_15 -> V_1 + V_17 ) ;
return F_1 ( V_15 -> V_1 , V_17 ) ;
}
int F_9 ( struct V_9 * V_10 )
{
#if F_10 ( V_28 )
struct V_13 * V_14 = V_10 -> V_15 ;
struct V_16 * V_15 = F_6 ( V_14 ) ;
unsigned int V_17 = V_15 -> V_18 -> V_19 . V_20 ;
struct V_29 * V_22 = V_15 -> V_30 -> V_31 ;
#ifdef F_11
if ( V_15 -> V_32 -> V_33 ) {
int V_34 , V_35 ;
if ( V_22 -> V_34 < 0 ) {
struct V_36 * V_37 = V_15 -> V_32 -> V_33 ;
if ( ! V_37 )
return 0 ;
V_22 -> V_34 = F_12 ( V_37 ,
L_1 , 0 ) ;
if ( V_22 -> V_34 < 0 )
return 0 ;
V_22 -> V_35 = F_13 ( V_37 ,
L_2 ) ;
F_14 ( V_37 ,
L_3 , V_22 -> V_38 , 3 ) ;
}
V_34 = V_22 -> V_34 ;
V_35 = V_22 -> V_35 ;
if ( ! F_15 ( V_34 , L_4 ) ) {
F_16 ( V_34 , V_35 ? 1 : 0 ) ;
if ( V_22 -> V_38 [ 0 ] )
F_17 ( F_18 ( V_22 -> V_38 [ 0 ] , 1000 ) ) ;
F_19 ( V_34 , V_35 ? 0 : 1 ) ;
if ( V_22 -> V_38 [ 1 ] )
F_17 ( F_18 ( V_22 -> V_38 [ 1 ] , 1000 ) ) ;
F_19 ( V_34 , V_35 ? 1 : 0 ) ;
if ( V_22 -> V_38 [ 2 ] )
F_17 ( F_18 ( V_22 -> V_38 [ 2 ] , 1000 ) ) ;
}
}
#endif
if ( V_22 -> V_39 ) {
F_20 ( L_5 ) ;
V_22 -> V_39 ( V_15 -> V_30 -> V_40 ) ;
}
F_7 ( 0 , V_15 -> V_1 + V_17 ) ;
#endif
return 0 ;
}
int F_21 ( struct V_13 * V_14 )
{
int V_41 = 0 ;
struct V_9 * V_42 ;
int * V_43 ;
struct V_16 * V_15 = F_6 ( V_14 ) ;
struct V_29 * V_31 = V_15 -> V_30 -> V_31 ;
int V_20 , V_44 ;
if ( ! V_31 )
return 0 ;
V_42 = F_22 () ;
if ( V_42 == NULL )
return - V_45 ;
if ( V_31 -> V_46 ) {
V_43 = V_31 -> V_46 ;
} else {
for ( V_20 = 0 ; V_20 < V_47 ; V_20 ++ )
V_15 -> V_48 [ V_20 ] = V_49 ;
V_43 = V_15 -> V_48 ;
}
#ifdef F_11
if ( V_15 -> V_32 -> V_33 )
V_31 -> V_34 = - 1 ;
#endif
V_42 -> V_50 = L_6 ;
V_42 -> V_51 = & F_5 ;
V_42 -> V_52 = & F_8 ;
V_42 -> V_53 = & F_9 ;
snprintf ( V_42 -> V_54 , V_55 , L_7 ,
V_42 -> V_50 , V_15 -> V_30 -> V_56 ) ;
V_42 -> V_15 = V_14 ;
V_42 -> V_57 = V_43 ;
V_42 -> V_58 = V_31 -> V_58 ;
V_42 -> V_59 = V_15 -> V_32 ;
V_41 = F_23 ( V_42 ) ;
if ( V_41 != 0 ) {
F_24 ( L_8 , V_42 -> V_50 ) ;
goto V_60;
}
V_44 = 0 ;
for ( V_20 = 0 ; V_20 < V_47 ; V_20 ++ ) {
struct V_61 * V_62 = V_42 -> V_63 [ V_20 ] ;
if ( V_62 ) {
int V_64 = 0 ;
char V_65 [ 4 ] ;
char * V_66 ;
if ( ( V_31 -> V_46 == NULL ) &&
( V_31 -> V_67 > 0 ) ) {
V_43 [ V_20 ] = V_31 -> V_67 ;
V_62 -> V_57 = V_31 -> V_67 ;
}
if ( V_15 -> V_30 -> V_68 == - 1 )
V_15 -> V_30 -> V_68 = V_20 ;
V_64 = ( V_15 -> V_30 -> V_68 == V_20 ) ;
switch ( V_62 -> V_57 ) {
case V_49 :
V_66 = L_9 ;
break;
case V_69 :
V_66 = L_10 ;
break;
default:
sprintf ( V_65 , L_11 , V_62 -> V_57 ) ;
V_66 = V_65 ;
break;
}
F_25 ( L_12 ,
V_14 -> V_50 , V_62 -> V_70 , V_20 ,
V_66 , F_26 ( & V_62 -> V_71 ) ,
V_64 ? L_13 : L_14 ) ;
V_44 = 1 ;
}
}
if ( ! V_44 ) {
F_27 ( L_15 , V_14 -> V_50 ) ;
F_28 ( V_42 ) ;
F_29 ( V_42 ) ;
return - V_72 ;
}
V_15 -> V_19 = V_42 ;
return 0 ;
V_60:
F_29 ( V_42 ) ;
return V_41 ;
}
int F_30 ( struct V_13 * V_14 )
{
struct V_16 * V_15 = F_6 ( V_14 ) ;
if ( ! V_15 -> V_19 )
return 0 ;
F_28 ( V_15 -> V_19 ) ;
V_15 -> V_19 -> V_15 = NULL ;
F_29 ( V_15 -> V_19 ) ;
V_15 -> V_19 = NULL ;
return 0 ;
}
