int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
if ( V_3 == 1UL << ( V_8 +
V_5 -> V_9 [ V_6 ] ) ) {
F_2 ( L_1 ,
V_10 , V_2 -> V_11 -> V_12 , V_3 , V_6 ) ;
return V_6 ;
}
}
F_3 ( L_2 , V_3 ) ;
return V_7 ;
}
static int F_4 ( unsigned long * V_13 ,
unsigned int V_14 ,
unsigned int V_15 ,
unsigned int V_16 ,
unsigned int V_17 )
{
unsigned long V_6 ;
V_6 = F_5 ( V_13 , V_14 , V_15 , V_16 , V_17 ) ;
if ( F_6 ( V_6 >= V_14 ) && ( V_15 > V_16 ) )
V_6 = F_5 ( V_13 , V_14 , 0 , V_15 - 1 ,
V_17 ) ;
if ( F_6 ( V_6 >= V_14 ) )
return - V_18 ;
F_7 ( V_13 , V_6 , V_16 ) ;
return ( int ) V_6 ;
}
static void F_8 ( struct V_1 * V_2 , int V_6 , int V_19 ,
unsigned long V_20 )
{
struct V_21 * V_22 = V_2 -> V_23 + V_6 ;
V_22 -> V_20 = V_20 ;
V_22 -> V_24 = V_19 ;
if ( V_22 -> V_25 == ( ( 1 << V_26 ) - 1 ) )
V_22 -> V_25 = 0 ;
else
V_22 -> V_25 ++ ;
}
static int F_9 ( struct V_1 * V_2 , unsigned int V_19 ,
unsigned long V_20 )
{
struct V_27 * V_28 ;
unsigned int V_29 ;
int V_6 ;
V_29 = F_10 () ;
V_28 = F_11 ( V_2 -> V_28 , V_29 ) ;
F_12 ( & V_28 -> V_30 ) ;
F_13 () ;
V_6 = F_4 ( V_28 -> V_13 , V_2 -> V_31 ,
V_28 -> V_32 , V_19 , 0 ) ;
if ( V_6 < 0 ) {
V_28 -> V_32 = 0 ;
F_14 ( & V_28 -> V_30 ) ;
return - V_18 ;
}
V_28 -> V_32 = V_6 + V_19 ;
if ( V_28 -> V_32 >= V_2 -> V_31 )
V_28 -> V_32 = 0 ;
F_14 ( & V_28 -> V_30 ) ;
F_2 ( L_3 ,
V_10 , V_29 , V_6 , V_19 , V_6 + V_29 * V_2 -> V_31 ,
V_28 -> V_32 ) ;
V_6 += V_29 * V_2 -> V_31 ;
F_8 ( V_2 , V_6 , V_19 , V_20 ) ;
return V_6 ;
}
static int F_15 ( struct V_1 * V_2 , unsigned int V_19 ,
unsigned long V_20 )
{
int V_6 ;
F_12 ( & V_2 -> V_33 ) ;
V_6 = F_4 ( V_2 -> V_34 , V_2 -> V_35 ,
V_2 -> V_32 , V_19 , 0 ) ;
if ( V_6 < 0 ) {
V_2 -> V_32 = 0 ;
F_14 ( & V_2 -> V_33 ) ;
F_2 ( L_4 ,
V_19 ) ;
return - V_18 ;
}
V_2 -> V_32 = V_6 + V_19 ;
if ( V_2 -> V_32 >= V_2 -> V_35 )
V_2 -> V_32 = 0 ;
F_14 ( & V_2 -> V_33 ) ;
F_2 ( L_5 ,
V_10 , V_6 , V_19 , V_6 + V_2 -> V_36 , V_2 -> V_32 ,
V_20 ) ;
V_6 += V_2 -> V_36 ;
F_8 ( V_2 , V_6 , V_19 , V_20 ) ;
return V_6 ;
}
static void F_16 ( struct V_1 * V_2 , int V_6 , int V_19 )
{
F_2 ( L_6 , V_10 , V_6 , V_19 ) ;
if ( V_6 < V_2 -> V_36 ) {
unsigned int V_29 ;
struct V_27 * V_28 ;
V_29 = V_6 / V_2 -> V_31 ;
V_6 %= V_2 -> V_31 ;
V_28 = F_11 ( V_2 -> V_28 , V_29 ) ;
F_12 ( & V_28 -> V_30 ) ;
F_17 ( V_28 -> V_13 , V_6 , V_19 ) ;
if ( V_6 < V_28 -> V_32 )
V_28 -> V_32 = V_6 ;
F_14 ( & V_28 -> V_30 ) ;
F_2 ( L_7 ,
V_10 , V_29 , V_6 , V_28 -> V_32 ) ;
} else {
F_12 ( & V_2 -> V_33 ) ;
V_6 -= V_2 -> V_36 ;
F_17 ( V_2 -> V_34 , V_6 , V_19 ) ;
if ( V_6 < V_2 -> V_32 )
V_2 -> V_32 = V_6 ;
F_14 ( & V_2 -> V_33 ) ;
F_2 ( L_8 , V_10 , V_6 , V_2 -> V_32 ) ;
}
}
void F_18 ( struct V_1 * V_2 , T_1 V_37 )
{
struct V_21 * V_22 ;
if ( V_37 >= V_2 -> V_38 ) {
F_19 ( L_9 , V_37 , V_2 -> V_38 ) ;
return;
}
V_22 = V_2 -> V_23 + V_37 ;
if ( ! V_22 -> V_24 ) {
F_19 ( L_10 , V_37 ) ;
return;
}
F_2 ( L_11 , V_37 , V_22 -> V_24 ) ;
F_16 ( V_2 , V_37 , V_22 -> V_24 ) ;
}
int F_20 ( struct V_1 * V_2 , unsigned short V_39 ,
T_1 V_40 , T_1 * V_41 ,
T_1 * V_42 , unsigned long V_20 )
{
struct V_21 * V_22 ;
unsigned int V_24 ;
int V_37 = - 1 ;
unsigned int V_43 ;
T_1 V_44 ;
V_24 = ( V_39 + V_45 - 1 ) >> V_46 ;
if ( ! V_24 ) {
F_19 ( L_12 ,
V_10 , V_39 , V_24 ) ;
return - V_47 ;
}
V_37 = F_9 ( V_2 , V_24 , V_20 ) ;
if ( V_37 < 0 )
V_37 = F_15 ( V_2 , V_24 , V_20 ) ;
if ( V_37 < 0 ) {
F_2 ( L_13 ,
V_39 , V_24 , V_2 -> V_32 , V_20 ) ;
return V_37 ;
}
V_22 = V_2 -> V_23 + V_37 ;
V_43 = V_2 -> V_48 + V_37 ;
V_44 = F_21 ( V_43 , V_22 -> V_25 ) ;
if ( V_40 )
V_44 |= ( V_40 << 30 ) & 0xC0000000 ;
* V_41 = V_37 ;
* V_42 = V_44 ;
F_2 ( L_14 ,
V_39 , V_44 , V_37 , V_24 , V_20 ) ;
return V_24 ;
}
void F_22 ( struct V_1 * V_2 , T_1 V_44 ,
unsigned int V_49 , unsigned int V_50 ,
unsigned int V_51 ,
struct V_52 * V_53 )
{
V_44 &= 0x3FFFFFFF ;
V_53 -> V_54 = F_23 ( V_55 | F_24 ( V_49 ) ) ;
V_53 -> V_56 = 0 ;
V_53 -> V_57 = F_23 ( V_44 & V_2 -> V_5 . V_58 ) ;
V_53 -> V_59 = F_23 ( V_51 ) ;
V_53 -> V_60 = F_23 ( V_50 ) ;
F_2 ( L_15 ,
V_44 , V_49 , V_51 , V_50 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_26 ( V_2 ) ;
}
static void F_27 ( struct V_61 * V_61 )
{
struct V_1 * V_2 = F_28 ( V_61 ,
struct V_1 ,
V_62 ) ;
F_3 ( L_16 ,
V_2 -> V_11 -> V_12 , V_2 ) ;
* V_2 -> V_63 = NULL ;
F_29 ( V_2 -> V_28 ) ;
F_25 ( V_2 ) ;
}
int F_30 ( struct V_1 * V_2 )
{
if ( V_2 ) {
int V_64 ;
V_64 = F_31 ( & V_2 -> V_62 , F_27 ) ;
return V_64 ;
}
return 1 ;
}
static struct V_27 * F_32 ( unsigned int * V_65 ,
unsigned int * V_66 )
{
struct V_27 * V_67 ;
unsigned int V_38 = ( * V_65 ) / F_33 () ;
unsigned int V_68 = ( V_69 - sizeof( * V_67 ) ) << 3 ;
unsigned int V_13 ;
unsigned int V_70 ;
unsigned int V_19 = 0 ;
unsigned int V_29 ;
if ( V_38 > V_68 )
V_38 = V_68 ;
V_13 = F_34 ( V_38 ) ;
V_38 = ( V_13 * sizeof( unsigned long ) ) << 3 ;
V_70 = sizeof( * V_67 ) + sizeof( unsigned long ) * V_13 ;
V_67 = F_35 ( V_70 , F_36 ( struct V_27 ) ) ;
if ( ! V_67 )
return NULL ;
F_37 (cpu) {
struct V_27 * V_71 = F_11 ( V_67 , V_29 ) ;
memset ( V_71 , 0 , V_70 ) ;
F_38 ( & V_71 -> V_30 ) ;
V_19 += V_38 ;
}
* V_65 = V_19 ;
* V_66 = V_38 ;
return V_67 ;
}
int F_39 ( void * * V_63 , struct V_72 * V_11 ,
struct V_73 * V_74 , void * V_75 ,
struct V_4 * V_5 ,
unsigned int V_38 ,
unsigned int V_76 ,
unsigned int V_15 ,
unsigned int V_77 )
{
struct V_1 * V_2 = (struct V_1 * ) ( * V_63 ) ;
struct V_27 * V_28 = NULL ;
unsigned int V_78 = 0 ;
unsigned int V_31 = 0 ;
unsigned int V_70 ;
unsigned int V_79 ;
if ( V_2 ) {
F_3 ( L_17 ,
V_11 -> V_12 , V_63 , V_2 , V_2 -> V_38 , V_38 ) ;
F_40 ( & V_2 -> V_62 ) ;
return 1 ;
}
if ( V_77 ) {
V_78 = V_38 / V_77 ;
V_28 = F_32 ( & V_78 , & V_31 ) ;
F_2 ( L_18 ,
V_11 -> V_12 , V_38 , V_78 , V_31 ) ;
}
V_79 = F_34 ( V_38 - V_78 ) ;
V_70 = sizeof( struct V_1 ) +
V_38 * ( sizeof( struct V_21 ) ) +
V_79 * sizeof( unsigned long ) ;
V_2 = F_41 ( V_70 ) ;
if ( ! V_2 )
goto V_80;
memset ( V_2 , 0 , V_70 ) ;
V_2 -> V_34 = ( unsigned long * ) ( & V_2 -> V_23 [ V_38 ] ) ;
if ( ( V_79 >> 3 ) > ( V_38 - V_78 ) ) {
unsigned int V_15 = V_38 - V_78 ;
unsigned int V_81 = V_79 >> 3 ;
F_7 ( V_2 -> V_34 , V_38 , V_81 - V_15 ) ;
F_3 ( L_19 ,
V_10 , V_38 , V_78 , V_79 , V_15 ,
V_81 ) ;
}
F_38 ( & V_2 -> V_33 ) ;
F_42 ( & V_2 -> V_62 ) ;
memcpy ( & V_2 -> V_5 , V_5 , sizeof( struct V_4 ) ) ;
V_2 -> V_63 = V_63 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_74 = V_74 ;
V_2 -> V_75 = V_75 ;
V_2 -> V_38 = V_38 ;
V_2 -> V_32 = 0 ;
V_2 -> V_76 = V_76 ;
V_2 -> V_48 = V_15 > V_76 ?
( V_15 - V_76 + 1 ) >> V_82 : 0 ;
V_2 -> V_35 = V_38 - V_78 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_36 = V_78 ;
V_2 -> V_31 = V_31 ;
if ( * V_63 ) {
F_25 ( V_2 ) ;
V_2 = (struct V_1 * ) ( * V_63 ) ;
F_3 ( L_17 ,
V_11 -> V_12 , V_63 , * V_63 , V_2 -> V_38 , V_38 ) ;
F_40 ( & V_2 -> V_62 ) ;
return 1 ;
}
* V_63 = V_2 ;
V_2 -> V_5 . V_83 = F_1 ( V_2 , V_84 ) ;
F_3 ( L_20 ,
V_11 -> V_12 , V_63 , V_2 , V_2 -> V_48 , V_2 -> V_38 , V_84 ,
V_2 -> V_5 . V_83 , V_2 -> V_36 ,
V_2 -> V_31 ) ;
return 0 ;
V_80:
F_29 ( V_28 ) ;
return - V_85 ;
}
unsigned int F_43 ( unsigned int V_38 )
{
unsigned int V_86 = F_44 ( V_38 ) ;
if ( V_86 > V_87 )
V_86 = V_87 ;
F_3 ( L_21 ,
V_38 , V_38 , V_86 , 1 << ( V_86 + V_26 ) ) ;
return 1 << ( V_86 + V_26 ) ;
}
