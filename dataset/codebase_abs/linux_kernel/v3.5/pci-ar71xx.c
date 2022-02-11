static inline T_1 F_1 ( int V_1 , int V_2 , int V_3 )
{
T_1 V_4 ;
V_4 = V_5 [ V_2 & 3 ] [ V_1 & 3 ] ;
F_2 ( V_4 == 0xf ) ;
V_4 <<= ( V_3 ) ? 20 : 4 ;
return V_4 ;
}
static inline T_1 F_3 ( struct V_6 * V_7 , unsigned int V_8 ,
int V_1 )
{
T_1 V_9 ;
if ( ! V_7 -> V_10 ) {
V_9 = ( 1 << F_4 ( V_8 ) ) | ( F_5 ( V_8 ) << 8 ) |
( V_1 & ~ 3 ) ;
} else {
V_9 = ( V_7 -> V_10 << 16 ) | ( F_4 ( V_8 ) << 11 ) |
( F_5 ( V_8 ) << 8 ) | ( V_1 & ~ 3 ) | 1 ;
}
return V_9 ;
}
static int F_6 ( int V_11 )
{
void T_2 * V_12 = V_13 ;
T_1 V_14 ;
T_1 V_15 ;
V_14 = F_7 ( V_12 + V_16 ) & 3 ;
if ( V_14 ) {
if ( ! V_11 ) {
T_1 V_17 ;
V_17 = F_7 ( V_12 + V_18 ) ;
F_8 ( L_1 ,
L_2 , V_14 , V_17 ) ;
}
F_9 ( V_14 , V_12 + V_16 ) ;
}
V_15 = F_7 ( V_12 + V_19 ) & 1 ;
if ( V_15 ) {
if ( ! V_11 ) {
T_1 V_17 ;
V_17 = F_7 ( V_12 + V_20 ) ;
F_8 ( L_1 ,
L_3 , V_15 , V_17 ) ;
}
F_9 ( V_15 , V_12 + V_19 ) ;
}
return ! ! ( V_15 | V_14 ) ;
}
static inline void F_10 ( int V_1 , int V_2 , T_1 V_21 )
{
void T_2 * V_12 = V_13 ;
T_1 V_22 ;
V_21 = V_21 << ( 8 * ( V_1 & 3 ) ) ;
V_22 = V_23 | ( V_1 & ~ 3 ) ;
V_22 |= F_1 ( V_1 , V_2 , 1 ) ;
F_9 ( V_22 , V_12 + V_24 ) ;
F_9 ( V_21 , V_12 + V_25 ) ;
}
static inline int F_11 ( struct V_6 * V_7 ,
unsigned int V_8 ,
int V_1 , int V_2 , T_1 V_26 )
{
void T_2 * V_12 = V_13 ;
T_1 V_17 ;
V_17 = F_3 ( V_7 , V_8 , V_1 ) ;
F_9 ( V_17 , V_12 + V_27 ) ;
F_9 ( V_26 | F_1 ( V_1 , V_2 , 0 ) ,
V_12 + V_28 ) ;
return F_6 ( 1 ) ;
}
static int F_12 ( struct V_6 * V_7 , unsigned int V_8 ,
int V_1 , int V_2 , T_1 * V_21 )
{
void T_2 * V_12 = V_13 ;
unsigned long V_29 ;
T_1 V_30 ;
int V_31 ;
int V_9 ;
V_9 = V_32 ;
V_30 = ~ 0 ;
F_13 ( & V_33 , V_29 ) ;
V_31 = F_11 ( V_7 , V_8 , V_1 , V_2 ,
V_34 ) ;
if ( V_31 )
V_9 = V_35 ;
else
V_30 = F_7 ( V_12 + V_36 ) ;
F_14 ( & V_33 , V_29 ) ;
* V_21 = ( V_30 >> ( 8 * ( V_1 & 3 ) ) ) & V_37 [ V_2 & 7 ] ;
return V_9 ;
}
static int F_15 ( struct V_6 * V_7 , unsigned int V_8 ,
int V_1 , int V_2 , T_1 V_21 )
{
void T_2 * V_12 = V_13 ;
unsigned long V_29 ;
int V_31 ;
int V_9 ;
V_21 = V_21 << ( 8 * ( V_1 & 3 ) ) ;
V_9 = V_32 ;
F_13 ( & V_33 , V_29 ) ;
V_31 = F_11 ( V_7 , V_8 , V_1 , V_2 ,
V_38 ) ;
if ( V_31 )
V_9 = V_35 ;
else
F_9 ( V_21 , V_12 + V_39 ) ;
F_14 ( & V_33 , V_29 ) ;
return V_9 ;
}
static void F_16 ( unsigned int V_40 , struct V_41 * V_42 )
{
void T_2 * V_12 = V_43 ;
T_1 V_44 ;
V_44 = F_7 ( V_12 + V_45 ) &
F_7 ( V_12 + V_46 ) ;
if ( V_44 & V_47 )
F_17 ( F_18 ( 0 ) ) ;
else if ( V_44 & V_48 )
F_17 ( F_18 ( 1 ) ) ;
else if ( V_44 & V_49 )
F_17 ( F_18 ( 2 ) ) ;
else if ( V_44 & V_50 )
F_17 ( F_18 ( 4 ) ) ;
else
F_19 () ;
}
static void F_20 ( struct V_51 * V_52 )
{
unsigned int V_40 = V_52 -> V_40 - V_53 ;
void T_2 * V_12 = V_43 ;
T_1 V_4 ;
V_4 = F_7 ( V_12 + V_46 ) ;
F_9 ( V_4 | ( 1 << V_40 ) , V_12 + V_46 ) ;
F_7 ( V_12 + V_46 ) ;
}
static void F_21 ( struct V_51 * V_52 )
{
unsigned int V_40 = V_52 -> V_40 - V_53 ;
void T_2 * V_12 = V_43 ;
T_1 V_4 ;
V_4 = F_7 ( V_12 + V_46 ) ;
F_9 ( V_4 & ~ ( 1 << V_40 ) , V_12 + V_46 ) ;
F_7 ( V_12 + V_46 ) ;
}
static T_3 void F_22 ( void )
{
void T_2 * V_12 = V_43 ;
int V_54 ;
F_9 ( 0 , V_12 + V_46 ) ;
F_9 ( 0 , V_12 + V_45 ) ;
F_23 ( V_55 < V_56 ) ;
for ( V_54 = V_53 ;
V_54 < V_53 + V_56 ; V_54 ++ )
F_24 ( V_54 , & V_57 ,
V_58 ) ;
F_25 ( V_59 , F_16 ) ;
}
static T_3 void F_26 ( void )
{
void T_2 * V_60 = V_61 ;
F_27 ( V_62 | V_63 ) ;
F_28 ( 100 ) ;
F_29 ( V_62 | V_63 ) ;
F_28 ( 100 ) ;
F_9 ( V_64 , V_60 + V_65 ) ;
F_9 ( V_66 , V_60 + V_67 ) ;
F_9 ( V_68 , V_60 + V_69 ) ;
F_9 ( V_70 , V_60 + V_71 ) ;
F_9 ( V_72 , V_60 + V_73 ) ;
F_9 ( V_74 , V_60 + V_75 ) ;
F_9 ( V_76 , V_60 + V_77 ) ;
F_9 ( V_78 , V_60 + V_79 ) ;
F_28 ( 100 ) ;
}
T_3 int F_30 ( void )
{
T_1 V_4 ;
V_13 = F_31 ( V_80 , V_81 ) ;
if ( V_13 == NULL )
return - V_82 ;
F_26 () ;
V_4 = V_83 | V_84 | V_85
| V_86 | V_87 | V_88 ;
F_10 ( V_89 , 4 , V_4 ) ;
F_6 ( 1 ) ;
F_22 () ;
F_32 ( & V_90 ) ;
return 0 ;
}
