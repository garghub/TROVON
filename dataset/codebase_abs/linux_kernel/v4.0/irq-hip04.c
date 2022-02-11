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
int V_15 ;
if ( V_14 < 16 )
return - V_16 ;
if ( V_14 >= 32 && type != V_17 &&
type != V_18 )
return - V_16 ;
F_6 ( & V_9 ) ;
V_15 = F_12 ( V_14 , type , V_13 , NULL ) ;
F_8 ( & V_9 ) ;
return V_15 ;
}
static int F_13 ( struct V_1 * V_2 ,
const struct V_19 * V_20 ,
bool V_21 )
{
void T_1 * V_22 ;
unsigned int V_23 , V_24 = ( F_4 ( V_2 ) % 2 ) * 16 ;
T_2 V_25 , V_8 , V_26 ;
if ( ! V_21 )
V_23 = F_14 ( V_20 , V_27 ) ;
else
V_23 = F_15 ( V_20 ) ;
if ( V_23 >= V_28 || V_23 >= V_29 )
return - V_16 ;
F_6 ( & V_9 ) ;
V_22 = F_1 ( V_2 ) + V_30 + ( ( F_4 ( V_2 ) * 2 ) & ~ 3 ) ;
V_8 = 0xffff << V_24 ;
V_26 = V_31 [ V_23 ] << V_24 ;
V_25 = F_16 ( V_22 ) & ~ V_8 ;
F_7 ( V_25 | V_26 , V_22 ) ;
F_8 ( & V_9 ) ;
return V_32 ;
}
static void T_3 F_17 ( struct V_33 * V_34 )
{
T_2 V_35 , V_36 ;
void T_1 * V_6 = V_4 . V_6 ;
do {
V_35 = F_16 ( V_6 + V_37 ) ;
V_36 = V_35 & V_38 ;
if ( F_18 ( V_36 > 15 && V_36 <= V_39 ) ) {
F_19 ( V_4 . V_40 , V_36 , V_34 ) ;
continue;
}
if ( V_36 < 16 ) {
F_7 ( V_35 , V_6 + V_12 ) ;
#ifdef F_20
F_21 ( V_36 , V_34 ) ;
#endif
continue;
}
break;
} while ( 1 );
}
static T_4 F_22 ( struct V_3 * V_41 )
{
void T_1 * V_13 = V_41 -> V_5 ;
T_2 V_8 , V_42 ;
for ( V_42 = V_8 = 0 ; V_42 < 32 ; V_42 += 2 ) {
V_8 = F_16 ( V_13 + V_30 + V_42 * 2 ) ;
V_8 |= V_8 >> 16 ;
if ( V_8 )
break;
}
if ( ! V_8 )
F_23 ( L_1 ) ;
return V_8 ;
}
static void T_5 F_24 ( struct V_3 * V_41 )
{
unsigned int V_42 ;
T_2 V_19 ;
unsigned int V_43 = V_41 -> V_43 ;
void T_1 * V_13 = V_41 -> V_5 ;
F_7 ( 0 , V_13 + V_44 ) ;
V_19 = F_22 ( V_41 ) ;
V_19 |= V_19 << 16 ;
for ( V_42 = 32 ; V_42 < V_43 ; V_42 += 2 )
F_7 ( V_19 , V_13 + V_30 + ( ( V_42 * 2 ) & ~ 3 ) ) ;
F_25 ( V_13 , V_43 , NULL ) ;
F_7 ( 1 , V_13 + V_44 ) ;
}
static void F_26 ( struct V_3 * V_41 )
{
void T_1 * V_5 = V_41 -> V_5 ;
void T_1 * V_13 = V_41 -> V_6 ;
unsigned int V_45 , V_23 = F_27 () ;
int V_42 ;
F_28 ( V_23 >= V_28 ) ;
V_45 = F_22 ( V_41 ) ;
V_31 [ V_23 ] = V_45 ;
for ( V_42 = 0 ; V_42 < V_28 ; V_42 ++ )
if ( V_42 != V_23 )
V_31 [ V_42 ] &= ~ V_45 ;
F_29 ( V_5 , NULL ) ;
F_7 ( 0xf0 , V_13 + V_46 ) ;
F_7 ( 1 , V_13 + V_47 ) ;
}
static void F_30 ( const struct V_19 * V_8 , unsigned int V_14 )
{
int V_23 ;
unsigned long V_48 , V_49 = 0 ;
F_31 ( & V_9 , V_48 ) ;
F_32 (cpu, mask)
V_49 |= V_31 [ V_23 ] ;
F_33 ( V_50 ) ;
F_7 ( V_49 << 8 | V_14 , V_4 . V_5 + V_51 ) ;
F_34 ( & V_9 , V_48 ) ;
}
static int F_35 ( struct V_52 * V_2 , unsigned int V_14 ,
T_6 V_53 )
{
if ( V_53 < 32 ) {
F_36 ( V_14 ) ;
F_37 ( V_14 , & V_54 ,
V_55 ) ;
F_38 ( V_14 , V_56 | V_57 ) ;
} else {
F_37 ( V_14 , & V_54 ,
V_58 ) ;
F_38 ( V_14 , V_56 | V_59 ) ;
}
F_39 ( V_14 , V_2 -> V_60 ) ;
return 0 ;
}
static int F_40 ( struct V_52 * V_2 ,
struct V_61 * V_62 ,
const T_2 * V_63 , unsigned int V_64 ,
unsigned long * V_65 ,
unsigned int * V_66 )
{
unsigned long V_15 = 0 ;
if ( V_2 -> V_67 != V_62 )
return - V_16 ;
if ( V_64 < 3 )
return - V_16 ;
* V_65 = V_63 [ 1 ] + 16 ;
if ( ! V_63 [ 0 ] )
* V_65 += 16 ;
* V_66 = V_63 [ 2 ] & V_68 ;
return V_15 ;
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
F_42 ( struct V_61 * V_76 , struct V_61 * V_77 )
{
T_6 V_78 = 16 ;
int V_43 , V_79 , V_42 ;
if ( F_43 ( ! V_76 ) )
return - V_80 ;
V_4 . V_5 = F_44 ( V_76 , 0 ) ;
F_45 ( ! V_4 . V_5 , L_2 ) ;
V_4 . V_6 = F_44 ( V_76 , 1 ) ;
F_45 ( ! V_4 . V_6 , L_3 ) ;
for ( V_42 = 0 ; V_42 < V_28 ; V_42 ++ )
V_31 [ V_42 ] = 0xffff ;
V_43 = F_16 ( V_4 . V_5 + V_81 ) & 0x1f ;
V_43 = ( V_43 + 1 ) * 32 ;
if ( V_43 > V_39 )
V_43 = V_39 ;
V_4 . V_43 = V_43 ;
V_43 -= V_78 ;
V_79 = F_46 ( - 1 , V_78 , V_43 , F_47 () ) ;
if ( F_48 ( V_79 ) ) {
F_49 ( L_4 ) ;
return - V_16 ;
}
V_4 . V_40 = F_50 ( V_76 , V_43 , V_79 ,
V_78 ,
& V_82 ,
& V_4 ) ;
if ( F_43 ( ! V_4 . V_40 ) )
return - V_16 ;
#ifdef F_20
F_51 ( F_30 ) ;
F_52 ( & V_83 ) ;
#endif
F_53 ( F_17 ) ;
F_24 ( & V_4 ) ;
F_26 ( & V_4 ) ;
return 0 ;
}
