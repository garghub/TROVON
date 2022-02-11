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
struct V_35 * V_43 = V_15 -> V_30 -> V_43 ;
int V_20 , V_44 ;
if ( ! V_31 )
return 0 ;
V_42 = F_22 () ;
if ( V_42 == NULL )
return - V_45 ;
if ( V_31 -> V_46 )
memcpy ( V_42 -> V_47 , V_31 , sizeof( V_42 -> V_47 ) ) ;
#ifdef F_11
if ( V_15 -> V_32 -> V_33 )
V_31 -> V_34 = - 1 ;
#endif
V_42 -> V_48 = L_6 ;
V_42 -> V_49 = & F_5 ;
V_42 -> V_50 = & F_8 ;
V_42 -> V_51 = & F_9 ;
snprintf ( V_42 -> V_52 , V_53 , L_7 ,
V_42 -> V_48 , V_15 -> V_30 -> V_54 ) ;
V_42 -> V_15 = V_14 ;
V_42 -> V_55 = V_31 -> V_55 ;
V_42 -> V_56 = V_15 -> V_32 ;
if ( V_43 )
V_41 = F_23 ( V_42 , V_43 ) ;
else
V_41 = F_24 ( V_42 ) ;
if ( V_41 != 0 ) {
F_25 ( L_8 , V_42 -> V_48 ) ;
goto V_57;
}
if ( V_15 -> V_30 -> V_58 || V_43 )
goto V_59;
V_44 = 0 ;
for ( V_20 = 0 ; V_20 < V_60 ; V_20 ++ ) {
struct V_61 * V_62 = F_26 ( V_42 , V_20 ) ;
if ( V_62 ) {
int V_63 = 0 ;
char V_64 [ 4 ] ;
char * V_65 ;
if ( ( V_31 -> V_46 == NULL ) &&
( V_31 -> V_66 > 0 ) ) {
V_42 -> V_47 [ V_20 ] =
V_31 -> V_66 ;
V_62 -> V_47 = V_31 -> V_66 ;
}
if ( V_15 -> V_30 -> V_67 == - 1 )
V_15 -> V_30 -> V_67 = V_20 ;
V_63 = ( V_15 -> V_30 -> V_67 == V_20 ) ;
switch ( V_62 -> V_47 ) {
case V_68 :
V_65 = L_9 ;
break;
case V_69 :
V_65 = L_10 ;
break;
default:
sprintf ( V_64 , L_11 , V_62 -> V_47 ) ;
V_65 = V_64 ;
break;
}
F_27 ( L_12 ,
V_14 -> V_48 , V_62 -> V_70 , V_20 ,
V_65 , F_28 ( V_62 ) ,
V_63 ? L_13 : L_14 ) ;
V_44 = 1 ;
}
}
if ( ! V_44 && ! V_43 ) {
F_29 ( L_15 , V_14 -> V_48 ) ;
F_30 ( V_42 ) ;
F_31 ( V_42 ) ;
return - V_71 ;
}
V_59:
V_15 -> V_19 = V_42 ;
return 0 ;
V_57:
F_31 ( V_42 ) ;
return V_41 ;
}
int F_32 ( struct V_13 * V_14 )
{
struct V_16 * V_15 = F_6 ( V_14 ) ;
if ( ! V_15 -> V_19 )
return 0 ;
F_30 ( V_15 -> V_19 ) ;
V_15 -> V_19 -> V_15 = NULL ;
F_31 ( V_15 -> V_19 ) ;
V_15 -> V_19 = NULL ;
return 0 ;
}
