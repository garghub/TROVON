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
F_38 ( V_14 , V_56 ) ;
} else {
F_37 ( V_14 , & V_54 ,
V_57 ) ;
F_39 ( V_14 ) ;
}
F_40 ( V_14 , V_2 -> V_58 ) ;
return 0 ;
}
static int F_41 ( struct V_52 * V_2 ,
struct V_59 * V_60 ,
const T_2 * V_61 , unsigned int V_62 ,
unsigned long * V_63 ,
unsigned int * V_64 )
{
unsigned long V_15 = 0 ;
if ( F_42 ( V_2 ) != V_60 )
return - V_16 ;
if ( V_62 < 3 )
return - V_16 ;
* V_63 = V_61 [ 1 ] + 16 ;
if ( ! V_61 [ 0 ] )
* V_63 += 16 ;
* V_64 = V_61 [ 2 ] & V_65 ;
return V_15 ;
}
static int F_43 ( struct V_66 * V_67 ,
unsigned long V_68 ,
void * V_69 )
{
if ( V_68 == V_70 || V_68 == V_71 )
F_26 ( & V_4 ) ;
return V_72 ;
}
static int T_5
F_44 ( struct V_59 * V_73 , struct V_59 * V_74 )
{
T_6 V_75 = 16 ;
int V_43 , V_76 , V_42 ;
if ( F_45 ( ! V_73 ) )
return - V_77 ;
V_4 . V_5 = F_46 ( V_73 , 0 ) ;
F_47 ( ! V_4 . V_5 , L_2 ) ;
V_4 . V_6 = F_46 ( V_73 , 1 ) ;
F_47 ( ! V_4 . V_6 , L_3 ) ;
for ( V_42 = 0 ; V_42 < V_28 ; V_42 ++ )
V_31 [ V_42 ] = 0xffff ;
V_43 = F_16 ( V_4 . V_5 + V_78 ) & 0x1f ;
V_43 = ( V_43 + 1 ) * 32 ;
if ( V_43 > V_39 )
V_43 = V_39 ;
V_4 . V_43 = V_43 ;
V_43 -= V_75 ;
V_76 = F_48 ( - 1 , V_75 , V_43 , F_49 () ) ;
if ( V_76 < 0 ) {
F_50 ( L_4 ) ;
return - V_16 ;
}
V_4 . V_40 = F_51 ( V_73 , V_43 , V_76 ,
V_75 ,
& V_79 ,
& V_4 ) ;
if ( F_45 ( ! V_4 . V_40 ) )
return - V_16 ;
#ifdef F_20
F_52 ( F_30 ) ;
F_53 ( & V_80 ) ;
#endif
F_54 ( F_17 ) ;
F_24 ( & V_4 ) ;
F_26 ( & V_4 ) ;
return 0 ;
}
