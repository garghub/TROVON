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
static int F_9 ( struct V_9 * V_10 )
{
#if F_10 ( V_28 )
struct V_13 * V_14 = V_10 -> V_15 ;
struct V_16 * V_15 = F_6 ( V_14 ) ;
unsigned int V_17 = V_15 -> V_18 -> V_19 . V_20 ;
if ( V_15 -> V_29 -> V_30 -> V_31 ) {
F_11 ( L_1 ) ;
V_15 -> V_29 -> V_30 -> V_31 ( V_15 -> V_29 -> V_32 ) ;
}
F_7 ( 0 , V_15 -> V_1 + V_17 ) ;
#endif
return 0 ;
}
int F_12 ( struct V_13 * V_14 )
{
int V_33 = 0 ;
struct V_9 * V_34 ;
int * V_35 ;
struct V_16 * V_15 = F_6 ( V_14 ) ;
struct V_36 * V_30 = V_15 -> V_29 -> V_30 ;
int V_20 , V_37 ;
if ( ! V_30 )
return 0 ;
V_34 = F_13 () ;
if ( V_34 == NULL )
return - V_38 ;
if ( V_30 -> V_39 )
V_35 = V_30 -> V_39 ;
else
V_35 = V_15 -> V_40 ;
V_34 -> V_41 = L_2 ;
V_34 -> V_42 = & F_5 ;
V_34 -> V_43 = & F_8 ;
V_34 -> V_44 = & F_9 ;
snprintf ( V_34 -> V_45 , V_46 , L_3 ,
V_34 -> V_41 , V_15 -> V_29 -> V_47 ) ;
V_34 -> V_15 = V_14 ;
V_34 -> V_48 = V_35 ;
V_34 -> V_49 = V_30 -> V_49 ;
V_34 -> V_50 = V_15 -> V_51 ;
V_33 = F_14 ( V_34 ) ;
if ( V_33 != 0 ) {
F_15 ( L_4 , V_34 -> V_41 ) ;
goto V_52;
}
V_15 -> V_19 = V_34 ;
V_37 = 0 ;
for ( V_20 = 0 ; V_20 < V_53 ; V_20 ++ ) {
struct V_54 * V_55 = V_34 -> V_56 [ V_20 ] ;
if ( V_55 ) {
int V_57 = 0 ;
char V_58 [ 4 ] ;
char * V_59 ;
if ( ( V_30 -> V_39 == NULL ) &&
( V_30 -> V_60 > 0 ) ) {
V_35 [ V_20 ] = V_30 -> V_60 ;
V_55 -> V_48 = V_30 -> V_60 ;
}
if ( V_15 -> V_29 -> V_61 == - 1 )
V_15 -> V_29 -> V_61 = V_20 ;
V_57 = ( V_15 -> V_29 -> V_61 == V_20 ) ;
switch ( V_55 -> V_48 ) {
case V_62 :
V_59 = L_5 ;
break;
case V_63 :
V_59 = L_6 ;
break;
default:
sprintf ( V_58 , L_7 , V_55 -> V_48 ) ;
V_59 = V_58 ;
break;
}
F_16 ( L_8 ,
V_14 -> V_41 , V_55 -> V_64 , V_20 ,
V_59 , F_17 ( & V_55 -> V_65 ) ,
V_57 ? L_9 : L_10 ) ;
V_37 = 1 ;
}
}
if ( ! V_37 )
F_18 ( L_11 , V_14 -> V_41 ) ;
return 0 ;
V_52:
F_19 ( V_34 ) ;
return V_33 ;
}
int F_20 ( struct V_13 * V_14 )
{
struct V_16 * V_15 = F_6 ( V_14 ) ;
if ( ! V_15 -> V_19 )
return 0 ;
F_21 ( V_15 -> V_19 ) ;
V_15 -> V_19 -> V_15 = NULL ;
F_19 ( V_15 -> V_19 ) ;
V_15 -> V_19 = NULL ;
return 0 ;
}
