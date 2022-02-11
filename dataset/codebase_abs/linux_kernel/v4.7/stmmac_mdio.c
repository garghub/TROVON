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
static int F_9 ( struct V_9 * V_10 , int V_11 , int V_12 )
{
struct V_13 * V_14 = V_10 -> V_15 ;
struct V_16 * V_15 = F_6 ( V_14 ) ;
unsigned int V_17 = V_15 -> V_18 -> V_19 . V_20 ;
unsigned int V_21 = V_15 -> V_18 -> V_19 . V_22 ;
int V_22 ;
T_3 V_26 = ( ( ( V_11 << V_28 ) &
( V_29 ) ) |
( ( V_12 << V_30 ) &
( V_31 ) ) ) | V_32 ;
V_26 |= V_7 | ( ( V_15 -> V_24 & V_33 )
<< V_34 ) ;
if ( F_1 ( V_15 -> V_1 , V_17 ) )
return - V_8 ;
F_7 ( V_26 , V_15 -> V_1 + V_17 ) ;
if ( F_1 ( V_15 -> V_1 , V_17 ) )
return - V_8 ;
V_22 = ( int ) F_2 ( V_15 -> V_1 + V_21 ) ;
return V_22 ;
}
static int F_10 ( struct V_9 * V_10 , int V_11 , int V_12 ,
T_2 V_25 )
{
struct V_13 * V_14 = V_10 -> V_15 ;
struct V_16 * V_15 = F_6 ( V_14 ) ;
unsigned int V_17 = V_15 -> V_18 -> V_19 . V_20 ;
unsigned int V_21 = V_15 -> V_18 -> V_19 . V_22 ;
T_3 V_26 = ( ( ( V_11 << V_28 ) &
( V_29 ) ) |
( ( V_12 << V_30 ) &
( V_31 ) ) ) | V_35 ;
V_26 |= V_7 | ( ( V_15 -> V_24 & V_33 )
<< V_34 ) ;
if ( F_1 ( V_15 -> V_1 , V_17 ) )
return - V_8 ;
F_7 ( V_25 , V_15 -> V_1 + V_21 ) ;
F_7 ( V_26 , V_15 -> V_1 + V_17 ) ;
return F_1 ( V_15 -> V_1 , V_17 ) ;
}
int F_11 ( struct V_9 * V_10 )
{
#if F_12 ( V_36 )
struct V_13 * V_14 = V_10 -> V_15 ;
struct V_16 * V_15 = F_6 ( V_14 ) ;
unsigned int V_17 = V_15 -> V_18 -> V_19 . V_20 ;
struct V_37 * V_22 = V_15 -> V_38 -> V_39 ;
#ifdef F_13
if ( V_15 -> V_40 -> V_41 ) {
if ( V_22 -> V_42 < 0 ) {
struct V_43 * V_44 = V_15 -> V_40 -> V_41 ;
if ( ! V_44 )
return 0 ;
V_22 -> V_42 = F_14 ( V_44 ,
L_1 , 0 ) ;
if ( V_22 -> V_42 < 0 )
return 0 ;
V_22 -> V_45 = F_15 ( V_44 ,
L_2 ) ;
F_16 ( V_44 ,
L_3 , V_22 -> V_46 , 3 ) ;
if ( F_17 ( V_22 -> V_42 , L_4 ) )
return 0 ;
}
F_18 ( V_22 -> V_42 ,
V_22 -> V_45 ? 1 : 0 ) ;
if ( V_22 -> V_46 [ 0 ] )
F_19 ( F_20 ( V_22 -> V_46 [ 0 ] , 1000 ) ) ;
F_21 ( V_22 -> V_42 , V_22 -> V_45 ? 0 : 1 ) ;
if ( V_22 -> V_46 [ 1 ] )
F_19 ( F_20 ( V_22 -> V_46 [ 1 ] , 1000 ) ) ;
F_21 ( V_22 -> V_42 , V_22 -> V_45 ? 1 : 0 ) ;
if ( V_22 -> V_46 [ 2 ] )
F_19 ( F_20 ( V_22 -> V_46 [ 2 ] , 1000 ) ) ;
}
#endif
if ( V_22 -> V_47 ) {
F_22 ( L_5 ) ;
V_22 -> V_47 ( V_15 -> V_38 -> V_48 ) ;
}
if ( ! V_15 -> V_38 -> V_49 )
F_7 ( 0 , V_15 -> V_1 + V_17 ) ;
#endif
return 0 ;
}
int F_23 ( struct V_13 * V_14 )
{
int V_50 = 0 ;
struct V_9 * V_51 ;
struct V_16 * V_15 = F_6 ( V_14 ) ;
struct V_37 * V_39 = V_15 -> V_38 -> V_39 ;
struct V_43 * V_52 = V_15 -> V_38 -> V_52 ;
int V_20 , V_53 ;
if ( ! V_39 )
return 0 ;
V_51 = F_24 () ;
if ( V_51 == NULL )
return - V_54 ;
if ( V_39 -> V_55 )
memcpy ( V_51 -> V_56 , V_39 -> V_55 , sizeof( V_51 -> V_56 ) ) ;
#ifdef F_13
if ( V_15 -> V_40 -> V_41 )
V_39 -> V_42 = - 1 ;
#endif
V_51 -> V_57 = L_6 ;
if ( V_15 -> V_38 -> V_49 ) {
V_51 -> V_58 = & F_9 ;
V_51 -> V_59 = & F_10 ;
} else {
V_51 -> V_58 = & F_5 ;
V_51 -> V_59 = & F_8 ;
}
V_51 -> V_60 = & F_11 ;
snprintf ( V_51 -> V_61 , V_62 , L_7 ,
V_51 -> V_57 , V_15 -> V_38 -> V_63 ) ;
V_51 -> V_15 = V_14 ;
V_51 -> V_64 = V_39 -> V_64 ;
V_51 -> V_65 = V_15 -> V_40 ;
if ( V_52 )
V_50 = F_25 ( V_51 , V_52 ) ;
else
V_50 = F_26 ( V_51 ) ;
if ( V_50 != 0 ) {
F_27 ( L_8 , V_51 -> V_57 ) ;
goto V_66;
}
if ( V_15 -> V_38 -> V_67 || V_52 )
goto V_68;
V_53 = 0 ;
for ( V_20 = 0 ; V_20 < V_69 ; V_20 ++ ) {
struct V_70 * V_71 = F_28 ( V_51 , V_20 ) ;
if ( V_71 ) {
int V_72 = 0 ;
char V_73 [ 4 ] ;
char * V_74 ;
if ( ( V_39 -> V_55 == NULL ) &&
( V_39 -> V_75 > 0 ) ) {
V_51 -> V_56 [ V_20 ] =
V_39 -> V_75 ;
V_71 -> V_56 = V_39 -> V_75 ;
}
if ( V_15 -> V_38 -> V_76 == - 1 )
V_15 -> V_38 -> V_76 = V_20 ;
V_72 = ( V_15 -> V_38 -> V_76 == V_20 ) ;
switch ( V_71 -> V_56 ) {
case V_77 :
V_74 = L_9 ;
break;
case V_78 :
V_74 = L_10 ;
break;
default:
sprintf ( V_73 , L_11 , V_71 -> V_56 ) ;
V_74 = V_73 ;
break;
}
F_29 ( L_12 ,
V_14 -> V_57 , V_71 -> V_79 , V_20 ,
V_74 , F_30 ( V_71 ) ,
V_72 ? L_13 : L_14 ) ;
V_53 = 1 ;
}
}
if ( ! V_53 && ! V_52 ) {
F_31 ( L_15 , V_14 -> V_57 ) ;
F_32 ( V_51 ) ;
F_33 ( V_51 ) ;
return - V_80 ;
}
V_68:
V_15 -> V_19 = V_51 ;
return 0 ;
V_66:
F_33 ( V_51 ) ;
return V_50 ;
}
int F_34 ( struct V_13 * V_14 )
{
struct V_16 * V_15 = F_6 ( V_14 ) ;
if ( ! V_15 -> V_19 )
return 0 ;
F_32 ( V_15 -> V_19 ) ;
V_15 -> V_19 -> V_15 = NULL ;
F_33 ( V_15 -> V_19 ) ;
V_15 -> V_19 = NULL ;
return 0 ;
}
