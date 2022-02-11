static inline void F_1 ( struct V_1 * V_2 , int V_3 , unsigned long V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
F_3 () ;
}
static inline unsigned long F_4 ( struct V_1 * V_2 , int V_3 )
{
return F_5 ( V_2 -> V_5 + V_3 ) ;
}
static int F_6 ( struct V_1 * V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_6 -> V_8 ; V_7 ++ ) {
if ( F_4 ( V_6 , V_9 ) & V_10 )
return 0 ;
F_7 ( 1 ) ;
}
return - V_11 ;
}
static int F_8 ( struct V_1 * V_6 )
{
unsigned long V_12 ;
if ( F_6 ( V_6 ) )
return - V_11 ;
V_12 = F_4 ( V_6 , V_13 ) ;
if ( ( V_12 & ( V_14 | V_15 | V_16 ) ) != 0 )
return - V_11 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < 2 * V_6 -> V_8 ; V_7 ++ ) {
if ( ( F_4 ( V_6 , V_13 ) & V_17 ) != 0 )
return 0 ;
F_7 ( 1 ) ;
}
return - V_11 ;
}
static int
F_10 ( struct V_1 * V_6 , unsigned int V_18 , int V_19 , int V_20 )
{
unsigned long V_12 ;
V_12 = F_4 ( V_6 , V_9 ) ;
F_1 ( V_6 , V_13 , V_21 ) ;
if ( ! ( V_12 & V_10 ) || ! ( V_12 & V_22 ) ) {
F_1 ( V_6 , V_23 , V_24 ) ;
while ( ( F_4 ( V_6 , V_23 ) & V_24 ) != 0 )
F_11 () ;
F_7 ( 50 ) ;
}
V_18 <<= 1 ;
if ( V_19 )
V_18 |= 1 ;
if ( V_20 )
V_18 |= V_25 ;
F_1 ( V_6 , V_26 , V_18 ) ;
F_1 ( V_6 , V_23 , V_27 ) ;
if ( F_8 ( V_6 ) )
return - V_28 ;
return ( V_20 ) ? F_9 ( V_6 ) : 0 ;
}
static int F_12 ( struct V_1 * V_6 , unsigned char * V_29 )
{
int V_30 ;
if ( F_6 ( V_6 ) )
return - V_28 ;
V_30 = V_6 -> V_8 * 100 ;
do {
V_30 -- ;
if ( V_30 <= 0 )
return - V_28 ;
if ( ( F_4 ( V_6 , V_9 ) & V_22 ) == 0 )
V_30 = 0 ;
else
F_7 ( 1 ) ;
} while ( V_30 > 0 );
* V_29 = F_4 ( V_6 , V_26 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_6 , unsigned char * V_31 ,
unsigned int V_32 )
{
int V_7 ;
if ( V_32 == 0 )
return 0 ;
V_7 = 0 ;
while ( V_7 < ( V_32 - 1 ) ) {
F_1 ( V_6 , V_26 , 0 ) ;
if ( F_12 ( V_6 , & V_31 [ V_7 ] ) )
return - V_28 ;
V_7 ++ ;
}
F_1 ( V_6 , V_26 , V_25 ) ;
if ( F_9 ( V_6 ) )
return - V_28 ;
V_31 [ V_7 ] = ( unsigned char ) ( F_4 ( V_6 , V_26 ) & 0xff ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_6 , unsigned char * V_31 ,
unsigned int V_32 )
{
int V_7 ;
unsigned long V_33 ;
if ( V_32 == 0 )
return 0 ;
V_7 = 0 ;
while ( V_7 < ( V_32 - 1 ) ) {
V_33 = V_31 [ V_7 ] ;
F_1 ( V_6 , V_26 , V_33 ) ;
if ( F_8 ( V_6 ) )
return - V_28 ;
V_7 ++ ;
}
V_33 = V_31 [ V_7 ] ;
V_33 |= V_25 ;
F_1 ( V_6 , V_26 , V_33 ) ;
if ( F_9 ( V_6 ) )
return - V_28 ;
return 0 ;
}
static int
F_15 ( struct V_34 * V_35 , struct V_36 * V_37 , int V_38 )
{
struct V_1 * V_6 = V_35 -> V_39 ;
struct V_36 * V_40 ;
int V_7 , V_41 = 0 ;
F_1 ( V_6 , V_42 , V_43 ) ;
for ( V_7 = 0 ; ! V_41 && V_7 < V_38 ; V_7 ++ ) {
V_40 = & V_37 [ V_7 ] ;
V_41 = F_10 ( V_6 , V_40 -> V_18 , V_40 -> V_44 & V_45 ,
( V_40 -> V_32 == 0 ) ) ;
if ( V_41 || ! V_40 -> V_32 )
continue;
if ( V_40 -> V_44 & V_45 )
V_41 = F_13 ( V_6 , V_40 -> V_31 , V_40 -> V_32 ) ;
else
V_41 = F_14 ( V_6 , V_40 -> V_31 , V_40 -> V_32 ) ;
}
if ( V_41 == 0 )
V_41 = V_38 ;
F_1 ( V_6 , V_42 , V_46 ) ;
return V_41 ;
}
static T_1 F_16 ( struct V_34 * V_6 )
{
return V_47 | V_48 ;
}
static void F_17 ( struct V_1 * V_49 )
{
unsigned long V_50 ;
F_1 ( V_49 , V_42 , V_51 ) ;
F_1 ( V_49 , V_52 , V_53 ) ;
F_1 ( V_49 , V_54 , 0 ) ;
F_1 ( V_49 , V_42 , V_43 ) ;
while ( ( F_4 ( V_49 , V_9 ) & V_55 ) == 0 )
F_11 () ;
V_50 = V_56 | V_57 | V_58 ;
F_1 ( V_49 , V_54 , V_50 ) ;
V_50 |= F_18 ( V_59 ) ;
F_1 ( V_49 , V_54 , V_50 ) ;
F_1 ( V_49 , V_60 , V_61 ) ;
F_1 ( V_49 , V_62 , F_19 ( 0 ) | F_20 ( 20 ) | \
F_21 ( 20 ) | F_22 ( 20 ) | \
F_23 ( 20 ) | F_24 ( 20 ) | \
F_25 ( 20 ) ) ;
V_50 |= V_63 ;
F_1 ( V_49 , V_54 , V_50 ) ;
while ( ( F_4 ( V_49 , V_9 ) & V_55 ) == 0 )
F_11 () ;
F_1 ( V_49 , V_42 , V_46 ) ;
}
static void F_26 ( struct V_1 * V_49 )
{
F_1 ( V_49 , V_54 , 0 ) ;
F_1 ( V_49 , V_42 , V_51 ) ;
}
static int
F_27 ( struct V_64 * V_65 )
{
struct V_1 * V_49 ;
struct V_66 * V_3 ;
int V_67 ;
V_49 = F_28 ( & V_65 -> V_68 , sizeof( struct V_1 ) ,
V_69 ) ;
if ( ! V_49 )
return - V_70 ;
V_3 = F_29 ( V_65 , V_71 , 0 ) ;
V_49 -> V_5 = F_30 ( & V_65 -> V_68 , V_3 ) ;
if ( F_31 ( V_49 -> V_5 ) )
return F_32 ( V_49 -> V_5 ) ;
V_49 -> V_8 = 200 ;
V_49 -> V_6 . V_72 = V_65 -> V_73 ;
V_49 -> V_6 . V_74 = & V_75 ;
V_49 -> V_6 . V_39 = V_49 ;
V_49 -> V_6 . V_68 . V_76 = & V_65 -> V_68 ;
F_33 ( V_49 -> V_6 . V_77 , L_1 , sizeof( V_49 -> V_6 . V_77 ) ) ;
F_17 ( V_49 ) ;
V_67 = F_34 ( & V_49 -> V_6 ) ;
if ( V_67 ) {
F_26 ( V_49 ) ;
return V_67 ;
}
F_35 ( V_65 , V_49 ) ;
return 0 ;
}
static int F_36 ( struct V_64 * V_65 )
{
struct V_1 * V_49 = F_37 ( V_65 ) ;
F_38 ( & V_49 -> V_6 ) ;
F_26 ( V_49 ) ;
return 0 ;
}
static int F_39 ( struct V_78 * V_68 )
{
struct V_1 * V_49 = F_40 ( V_68 ) ;
F_26 ( V_49 ) ;
return 0 ;
}
static int F_41 ( struct V_78 * V_68 )
{
struct V_1 * V_49 = F_40 ( V_68 ) ;
F_17 ( V_49 ) ;
return 0 ;
}
