static inline void T_1 * F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static inline void T_1 * F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_6 ;
}
static inline unsigned int F_4 ( struct V_1 * V_2 )
{
return V_2 -> V_7 ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_2 V_8 = 1 << ( F_4 ( V_2 ) % 32 ) ;
F_6 ( & V_9 ) ;
F_7 ( V_8 , F_1 ( V_2 ) + V_10 +
( F_4 ( V_2 ) / 32 ) * 4 ) ;
F_8 ( & V_9 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
T_2 V_8 = 1 << ( F_4 ( V_2 ) % 32 ) ;
F_6 ( & V_9 ) ;
F_7 ( V_8 , F_1 ( V_2 ) + V_11 +
( F_4 ( V_2 ) / 32 ) * 4 ) ;
F_8 ( & V_9 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_7 ( F_4 ( V_2 ) , F_3 ( V_2 ) + V_12 ) ;
}
static int F_11 ( struct V_1 * V_2 , unsigned int type )
{
void T_1 * V_13 = F_1 ( V_2 ) ;
unsigned int V_14 = F_4 ( V_2 ) ;
if ( V_14 < 16 )
return - V_15 ;
if ( type != V_16 && type != V_17 )
return - V_15 ;
F_6 ( & V_9 ) ;
F_12 ( V_14 , type , V_13 , NULL ) ;
F_8 ( & V_9 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
const struct V_18 * V_19 ,
bool V_20 )
{
void T_1 * V_21 ;
unsigned int V_22 , V_23 = ( F_4 ( V_2 ) % 2 ) * 16 ;
T_2 V_24 , V_8 , V_25 ;
if ( ! V_20 )
V_22 = F_14 ( V_19 , V_26 ) ;
else
V_22 = F_15 ( V_19 ) ;
if ( V_22 >= V_27 || V_22 >= V_28 )
return - V_15 ;
F_6 ( & V_9 ) ;
V_21 = F_1 ( V_2 ) + V_29 + ( ( F_4 ( V_2 ) * 2 ) & ~ 3 ) ;
V_8 = 0xffff << V_23 ;
V_25 = V_30 [ V_22 ] << V_23 ;
V_24 = F_16 ( V_21 ) & ~ V_8 ;
F_7 ( V_24 | V_25 , V_21 ) ;
F_8 ( & V_9 ) ;
return V_31 ;
}
static void T_3 F_17 ( struct V_32 * V_33 )
{
T_2 V_34 , V_35 ;
void T_1 * V_6 = V_4 . V_6 ;
do {
V_34 = F_16 ( V_6 + V_36 ) ;
V_35 = V_34 & V_37 ;
if ( F_18 ( V_35 > 15 && V_35 <= V_38 ) ) {
F_19 ( V_4 . V_39 , V_35 , V_33 ) ;
continue;
}
if ( V_35 < 16 ) {
F_7 ( V_34 , V_6 + V_12 ) ;
#ifdef F_20
F_21 ( V_35 , V_33 ) ;
#endif
continue;
}
break;
} while ( 1 );
}
static T_4 F_22 ( struct V_3 * V_40 )
{
void T_1 * V_13 = V_40 -> V_5 ;
T_2 V_8 , V_41 ;
for ( V_41 = V_8 = 0 ; V_41 < 32 ; V_41 += 2 ) {
V_8 = F_16 ( V_13 + V_29 + V_41 * 2 ) ;
V_8 |= V_8 >> 16 ;
if ( V_8 )
break;
}
if ( ! V_8 )
F_23 ( L_1 ) ;
return V_8 ;
}
static void T_5 F_24 ( struct V_3 * V_40 )
{
unsigned int V_41 ;
T_2 V_18 ;
unsigned int V_42 = V_40 -> V_42 ;
void T_1 * V_13 = V_40 -> V_5 ;
F_7 ( 0 , V_13 + V_43 ) ;
V_18 = F_22 ( V_40 ) ;
V_18 |= V_18 << 16 ;
for ( V_41 = 32 ; V_41 < V_42 ; V_41 += 2 )
F_7 ( V_18 , V_13 + V_29 + ( ( V_41 * 2 ) & ~ 3 ) ) ;
F_25 ( V_13 , V_42 , NULL ) ;
F_7 ( 1 , V_13 + V_43 ) ;
}
static void F_26 ( struct V_3 * V_40 )
{
void T_1 * V_5 = V_40 -> V_5 ;
void T_1 * V_13 = V_40 -> V_6 ;
unsigned int V_44 , V_22 = F_27 () ;
int V_41 ;
F_28 ( V_22 >= V_27 ) ;
V_44 = F_22 ( V_40 ) ;
V_30 [ V_22 ] = V_44 ;
for ( V_41 = 0 ; V_41 < V_27 ; V_41 ++ )
if ( V_41 != V_22 )
V_30 [ V_41 ] &= ~ V_44 ;
F_29 ( V_5 , NULL ) ;
F_7 ( 0xf0 , V_13 + V_45 ) ;
F_7 ( 1 , V_13 + V_46 ) ;
}
static void F_30 ( const struct V_18 * V_8 , unsigned int V_14 )
{
int V_22 ;
unsigned long V_47 , V_48 = 0 ;
F_31 ( & V_9 , V_47 ) ;
F_32 (cpu, mask)
V_48 |= V_30 [ V_22 ] ;
F_33 ( V_49 ) ;
F_7 ( V_48 << 8 | V_14 , V_4 . V_5 + V_50 ) ;
F_34 ( & V_9 , V_47 ) ;
}
static int F_35 ( struct V_51 * V_2 , unsigned int V_14 ,
T_6 V_52 )
{
if ( V_52 < 32 ) {
F_36 ( V_14 ) ;
F_37 ( V_14 , & V_53 ,
V_54 ) ;
F_38 ( V_14 , V_55 | V_56 ) ;
} else {
F_37 ( V_14 , & V_53 ,
V_57 ) ;
F_38 ( V_14 , V_55 | V_58 ) ;
}
F_39 ( V_14 , V_2 -> V_59 ) ;
return 0 ;
}
static int F_40 ( struct V_51 * V_2 ,
struct V_60 * V_61 ,
const T_2 * V_62 , unsigned int V_63 ,
unsigned long * V_64 ,
unsigned int * V_65 )
{
unsigned long V_66 = 0 ;
if ( V_2 -> V_67 != V_61 )
return - V_15 ;
if ( V_63 < 3 )
return - V_15 ;
* V_64 = V_62 [ 1 ] + 16 ;
if ( ! V_62 [ 0 ] )
* V_64 += 16 ;
* V_65 = V_62 [ 2 ] & V_68 ;
return V_66 ;
}
static int F_41 ( struct V_69 * V_70 ,
unsigned long V_71 ,
void * V_72 )
{
if ( V_71 == V_73 || V_71 == V_74 )
F_26 ( & V_4 ) ;
return V_75 ;
}
static int T_5
F_42 ( struct V_60 * V_76 , struct V_60 * V_77 )
{
T_6 V_78 = 16 ;
int V_42 , V_79 , V_41 ;
if ( F_43 ( ! V_76 ) )
return - V_80 ;
V_4 . V_5 = F_44 ( V_76 , 0 ) ;
F_45 ( ! V_4 . V_5 , L_2 ) ;
V_4 . V_6 = F_44 ( V_76 , 1 ) ;
F_45 ( ! V_4 . V_6 , L_3 ) ;
for ( V_41 = 0 ; V_41 < V_27 ; V_41 ++ )
V_30 [ V_41 ] = 0xffff ;
V_42 = F_16 ( V_4 . V_5 + V_81 ) & 0x1f ;
V_42 = ( V_42 + 1 ) * 32 ;
if ( V_42 > V_38 )
V_42 = V_38 ;
V_4 . V_42 = V_42 ;
V_42 -= V_78 ;
V_79 = F_46 ( - 1 , V_78 , V_42 , F_47 () ) ;
if ( F_48 ( V_79 ) ) {
F_49 ( L_4 ) ;
return - V_15 ;
}
V_4 . V_39 = F_50 ( V_76 , V_42 , V_79 ,
V_78 ,
& V_82 ,
& V_4 ) ;
if ( F_43 ( ! V_4 . V_39 ) )
return - V_15 ;
#ifdef F_20
F_51 ( F_30 ) ;
F_52 ( & V_83 ) ;
#endif
F_53 ( F_17 ) ;
F_24 ( & V_4 ) ;
F_26 ( & V_4 ) ;
return 0 ;
}
