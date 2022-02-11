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
if ( V_22 -> V_34 < 0 ) {
struct V_35 * V_36 = V_15 -> V_32 -> V_33 ;
if ( ! V_36 )
return 0 ;
V_22 -> V_34 = F_12 ( V_36 ,
L_1 , 0 ) ;
if ( V_22 -> V_34 < 0 )
return 0 ;
V_22 -> V_37 = F_13 ( V_36 ,
L_2 ) ;
F_14 ( V_36 ,
L_3 , V_22 -> V_38 , 3 ) ;
if ( F_15 ( V_22 -> V_34 , L_4 ) )
return 0 ;
}
F_16 ( V_22 -> V_34 ,
V_22 -> V_37 ? 1 : 0 ) ;
if ( V_22 -> V_38 [ 0 ] )
F_17 ( F_18 ( V_22 -> V_38 [ 0 ] , 1000 ) ) ;
F_19 ( V_22 -> V_34 , V_22 -> V_37 ? 0 : 1 ) ;
if ( V_22 -> V_38 [ 1 ] )
F_17 ( F_18 ( V_22 -> V_38 [ 1 ] , 1000 ) ) ;
F_19 ( V_22 -> V_34 , V_22 -> V_37 ? 1 : 0 ) ;
if ( V_22 -> V_38 [ 2 ] )
F_17 ( F_18 ( V_22 -> V_38 [ 2 ] , 1000 ) ) ;
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
struct V_16 * V_15 = F_6 ( V_14 ) ;
struct V_29 * V_31 = V_15 -> V_30 -> V_31 ;
int V_20 , V_43 ;
struct V_35 * V_44 = V_15 -> V_30 -> V_44 ;
if ( ! V_31 )
return 0 ;
if ( F_22 ( F_11 ) ) {
if ( V_44 ) {
F_23 ( V_14 , L_6 ) ;
} else {
F_24 ( V_14 , L_7 ) ;
}
}
V_42 = F_25 () ;
if ( V_42 == NULL )
return - V_45 ;
if ( V_31 -> V_46 )
memcpy ( V_42 -> V_47 , V_31 , sizeof( V_42 -> V_47 ) ) ;
#ifdef F_11
if ( V_15 -> V_32 -> V_33 )
V_31 -> V_34 = - 1 ;
#endif
V_42 -> V_48 = L_8 ;
V_42 -> V_49 = & F_5 ;
V_42 -> V_50 = & F_8 ;
V_42 -> V_51 = & F_9 ;
snprintf ( V_42 -> V_52 , V_53 , L_9 ,
V_42 -> V_48 , V_15 -> V_30 -> V_54 ) ;
V_42 -> V_15 = V_14 ;
V_42 -> V_55 = V_31 -> V_55 ;
V_42 -> V_56 = V_15 -> V_32 ;
if ( V_44 )
V_41 = F_26 ( V_42 , V_44 ) ;
else
V_41 = F_27 ( V_42 ) ;
if ( V_41 != 0 ) {
F_28 ( L_10 , V_42 -> V_48 ) ;
goto V_57;
}
V_43 = 0 ;
for ( V_20 = 0 ; V_20 < V_58 ; V_20 ++ ) {
struct V_59 * V_60 = F_29 ( V_42 , V_20 ) ;
if ( V_60 ) {
int V_61 = 0 ;
char V_62 [ 4 ] ;
char * V_63 ;
if ( ( V_31 -> V_46 == NULL ) &&
( V_31 -> V_64 > 0 ) ) {
V_42 -> V_47 [ V_20 ] =
V_31 -> V_64 ;
V_60 -> V_47 = V_31 -> V_64 ;
}
if ( V_15 -> V_30 -> V_65 == - 1 )
V_15 -> V_30 -> V_65 = V_20 ;
V_61 = ( V_15 -> V_30 -> V_65 == V_20 ) ;
switch ( V_60 -> V_47 ) {
case V_66 :
V_63 = L_11 ;
break;
case V_67 :
V_63 = L_12 ;
break;
default:
sprintf ( V_62 , L_13 , V_60 -> V_47 ) ;
V_63 = V_62 ;
break;
}
F_30 ( L_14 ,
V_14 -> V_48 , V_60 -> V_68 , V_20 ,
V_63 , F_31 ( V_60 ) ,
V_61 ? L_15 : L_16 ) ;
V_43 = 1 ;
}
}
if ( ! V_43 && ! V_44 ) {
F_32 ( L_17 , V_14 -> V_48 ) ;
F_33 ( V_42 ) ;
F_34 ( V_42 ) ;
return - V_69 ;
}
V_15 -> V_19 = V_42 ;
return 0 ;
V_57:
F_34 ( V_42 ) ;
return V_41 ;
}
int F_35 ( struct V_13 * V_14 )
{
struct V_16 * V_15 = F_6 ( V_14 ) ;
if ( ! V_15 -> V_19 )
return 0 ;
F_33 ( V_15 -> V_19 ) ;
V_15 -> V_19 -> V_15 = NULL ;
F_34 ( V_15 -> V_19 ) ;
V_15 -> V_19 = NULL ;
return 0 ;
}
