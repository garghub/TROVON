static int T_1 F_1 ( char * V_1 )
{
V_2 = 1 ;
return 0 ;
}
static unsigned long T_1 F_2 ( unsigned long V_3 )
{
unsigned long V_4 = F_3 ( V_3 , 8 ) ;
return F_4 ( V_4 , sizeof( long ) ) ;
}
unsigned long T_1 F_5 ( unsigned long V_3 )
{
unsigned long V_4 = F_2 ( V_3 ) ;
return F_6 ( V_4 ) >> V_5 ;
}
static void T_1 F_7 ( T_2 * V_6 )
{
T_2 * V_7 ;
F_8 (ent, &bdata_list, list) {
if ( V_6 -> V_8 < V_7 -> V_8 ) {
F_9 ( & V_6 -> V_9 , & V_7 -> V_9 ) ;
return;
}
}
F_9 ( & V_6 -> V_9 , & V_10 ) ;
}
static unsigned long T_1 F_10 ( T_2 * V_6 ,
unsigned long V_11 , unsigned long V_12 , unsigned long V_13 )
{
unsigned long V_14 ;
F_11 ( & V_12 , & V_13 ) ;
V_6 -> V_15 = F_12 ( F_13 ( V_11 ) ) ;
V_6 -> V_8 = V_12 ;
V_6 -> V_16 = V_13 ;
F_7 ( V_6 ) ;
V_14 = F_2 ( V_13 - V_12 ) ;
memset ( V_6 -> V_15 , 0xff , V_14 ) ;
F_14 ( L_1 ,
V_6 - V_17 , V_12 , V_11 , V_13 , V_14 ) ;
return V_14 ;
}
unsigned long T_1 F_15 ( T_3 * V_18 , unsigned long V_19 ,
unsigned long V_20 , unsigned long V_21 )
{
return F_10 ( V_18 -> V_6 , V_19 , V_20 , V_21 ) ;
}
unsigned long T_1 F_16 ( unsigned long V_12 , unsigned long V_3 )
{
V_22 = V_3 ;
V_23 = V_12 ;
return F_10 ( F_17 ( 0 ) -> V_6 , V_12 , 0 , V_3 ) ;
}
void T_1 F_18 ( unsigned long V_24 , unsigned long V_25 )
{
unsigned long V_26 , V_13 ;
F_19 ( F_20 ( V_24 ) , V_25 ) ;
V_26 = F_21 ( V_24 ) ;
V_13 = F_22 ( V_24 + V_25 ) ;
for (; V_26 < V_13 ; V_26 ++ ) {
F_23 ( F_24 ( V_26 ) , 0 ) ;
V_27 ++ ;
}
}
static unsigned long T_1 F_25 ( T_2 * V_6 )
{
struct V_28 * V_28 ;
unsigned long V_12 , V_13 , V_3 , V_29 = 0 ;
if ( ! V_6 -> V_15 )
return 0 ;
V_12 = V_6 -> V_8 ;
V_13 = V_6 -> V_16 ;
F_14 ( L_2 ,
V_6 - V_17 , V_12 , V_13 ) ;
while ( V_12 < V_13 ) {
unsigned long * V_30 , V_31 , V_32 ;
unsigned V_33 ;
V_30 = V_6 -> V_15 ;
V_31 = V_12 - V_6 -> V_8 ;
V_33 = V_31 & ( V_34 - 1 ) ;
V_32 = ~ V_30 [ V_31 / V_34 ] ;
if ( V_33 ) {
V_32 >>= V_33 ;
if ( V_13 - V_12 >= V_34 )
V_32 |= ~ V_30 [ V_31 / V_34 + 1 ] <<
( V_34 - V_33 ) ;
}
if ( F_26 ( V_12 , V_34 ) && V_32 == ~ 0UL ) {
int V_35 = F_27 ( V_34 ) ;
F_23 ( F_24 ( V_12 ) , V_35 ) ;
V_29 += V_34 ;
V_12 += V_34 ;
} else {
unsigned long V_36 = V_12 ;
V_12 = F_4 ( V_12 + 1 , V_34 ) ;
while ( V_32 && V_36 != V_12 ) {
if ( V_32 & 1 ) {
V_28 = F_24 ( V_36 ) ;
F_23 ( V_28 , 0 ) ;
V_29 ++ ;
}
V_32 >>= 1 ;
++ V_36 ;
}
}
}
V_28 = F_28 ( V_6 -> V_15 ) ;
V_3 = V_6 -> V_16 - V_6 -> V_8 ;
V_3 = F_5 ( V_3 ) ;
V_29 += V_3 ;
while ( V_3 -- )
F_23 ( V_28 ++ , 0 ) ;
F_14 ( L_3 , V_6 - V_17 , V_29 ) ;
return V_29 ;
}
static void F_29 ( T_3 * V_18 )
{
struct V_37 * V_38 ;
for ( V_38 = V_18 -> V_39 ; V_38 < V_18 -> V_39 + V_40 ; V_38 ++ )
if ( ! F_30 ( V_38 ) )
V_38 -> V_41 = 0 ;
}
unsigned long T_1 F_31 ( T_3 * V_18 )
{
F_32 ( V_18 ) ;
F_29 ( V_18 ) ;
return F_25 ( V_18 -> V_6 ) ;
}
unsigned long T_1 F_33 ( void )
{
unsigned long V_42 = 0 ;
T_2 * V_6 ;
struct V_43 * V_18 ;
F_34 (pgdat)
F_29 ( V_18 ) ;
F_8 (bdata, &bdata_list, list)
V_42 += F_25 ( V_6 ) ;
return V_42 ;
}
static void T_1 F_35 ( T_2 * V_6 ,
unsigned long V_44 , unsigned long V_45 )
{
unsigned long V_31 ;
F_14 ( L_2 , V_6 - V_17 ,
V_44 + V_6 -> V_8 ,
V_45 + V_6 -> V_8 ) ;
if ( V_6 -> V_46 > V_44 )
V_6 -> V_46 = V_44 ;
for ( V_31 = V_44 ; V_31 < V_45 ; V_31 ++ )
if ( ! F_36 ( V_31 , V_6 -> V_15 ) )
F_37 () ;
}
static int T_1 F_38 ( T_2 * V_6 , unsigned long V_44 ,
unsigned long V_45 , int V_47 )
{
unsigned long V_31 ;
int V_48 = V_47 & V_49 ;
F_14 ( L_4 ,
V_6 - V_17 ,
V_44 + V_6 -> V_8 ,
V_45 + V_6 -> V_8 ,
V_47 ) ;
for ( V_31 = V_44 ; V_31 < V_45 ; V_31 ++ )
if ( F_39 ( V_31 , V_6 -> V_15 ) ) {
if ( V_48 ) {
F_35 ( V_6 , V_44 , V_31 ) ;
return - V_50 ;
}
F_14 ( L_5 ,
V_31 + V_6 -> V_8 ) ;
}
return 0 ;
}
static int T_1 F_40 ( T_2 * V_6 ,
unsigned long V_12 , unsigned long V_13 ,
int V_51 , int V_47 )
{
unsigned long V_44 , V_45 ;
F_14 ( L_6 ,
V_6 - V_17 , V_12 , V_13 , V_51 , V_47 ) ;
F_41 ( V_12 < V_6 -> V_8 ) ;
F_41 ( V_13 > V_6 -> V_16 ) ;
V_44 = V_12 - V_6 -> V_8 ;
V_45 = V_13 - V_6 -> V_8 ;
if ( V_51 )
return F_38 ( V_6 , V_44 , V_45 , V_47 ) ;
else
F_35 ( V_6 , V_44 , V_45 ) ;
return 0 ;
}
static int T_1 F_42 ( unsigned long V_12 , unsigned long V_13 ,
int V_51 , int V_47 )
{
unsigned long V_52 ;
T_2 * V_6 ;
V_52 = V_12 ;
F_8 (bdata, &bdata_list, list) {
int V_53 ;
unsigned long V_54 ;
if ( V_52 < V_6 -> V_8 ||
V_52 >= V_6 -> V_16 ) {
F_41 ( V_52 != V_12 ) ;
continue;
}
V_54 = F_43 ( V_6 -> V_16 , V_13 ) ;
V_53 = F_40 ( V_6 , V_52 , V_54 , V_51 , V_47 ) ;
if ( V_51 && V_53 ) {
F_42 ( V_12 , V_52 , 0 , 0 ) ;
return V_53 ;
}
if ( V_54 == V_13 )
return 0 ;
V_52 = V_6 -> V_16 ;
}
F_37 () ;
}
void T_1 F_44 ( T_3 * V_18 , unsigned long V_24 ,
unsigned long V_25 )
{
unsigned long V_12 , V_13 ;
F_19 ( F_20 ( V_24 ) , V_25 ) ;
V_12 = F_21 ( V_24 ) ;
V_13 = F_22 ( V_24 + V_25 ) ;
F_40 ( V_18 -> V_6 , V_12 , V_13 , 0 , 0 ) ;
}
void T_1 F_45 ( unsigned long V_24 , unsigned long V_25 )
{
unsigned long V_12 , V_13 ;
F_19 ( F_20 ( V_24 ) , V_25 ) ;
V_12 = F_21 ( V_24 ) ;
V_13 = F_22 ( V_24 + V_25 ) ;
F_42 ( V_12 , V_13 , 0 , 0 ) ;
}
int T_1 F_46 ( T_3 * V_18 , unsigned long V_24 ,
unsigned long V_25 , int V_47 )
{
unsigned long V_12 , V_13 ;
V_12 = F_22 ( V_24 ) ;
V_13 = F_21 ( V_24 + V_25 ) ;
return F_40 ( V_18 -> V_6 , V_12 , V_13 , 1 , V_47 ) ;
}
int T_1 F_47 ( unsigned long V_55 , unsigned long V_25 ,
int V_47 )
{
unsigned long V_12 , V_13 ;
V_12 = F_22 ( V_55 ) ;
V_13 = F_21 ( V_55 + V_25 ) ;
return F_42 ( V_12 , V_13 , 1 , V_47 ) ;
}
static unsigned long T_1 F_48 ( struct V_56 * V_6 ,
unsigned long V_31 , unsigned long V_57 )
{
unsigned long V_58 = V_6 -> V_8 ;
return F_4 ( V_58 + V_31 , V_57 ) - V_58 ;
}
static unsigned long T_1 F_49 ( struct V_56 * V_6 ,
unsigned long V_59 , unsigned long V_60 )
{
unsigned long V_58 = F_13 ( V_6 -> V_8 ) ;
return F_4 ( V_58 + V_59 , V_60 ) - V_58 ;
}
static void * T_1 F_50 ( struct V_56 * V_6 ,
unsigned long V_25 , unsigned long V_60 ,
unsigned long V_61 , unsigned long V_62 )
{
unsigned long V_63 = 0 ;
unsigned long F_43 , V_54 , V_12 , V_44 , V_64 , V_57 ;
F_14 ( L_7 ,
V_6 - V_17 , V_25 , F_6 ( V_25 ) >> V_5 ,
V_60 , V_61 , V_62 ) ;
F_41 ( ! V_25 ) ;
F_41 ( V_60 & ( V_60 - 1 ) ) ;
F_41 ( V_62 && V_61 + V_25 > V_62 ) ;
if ( ! V_6 -> V_15 )
return NULL ;
F_43 = V_6 -> V_8 ;
V_54 = V_6 -> V_16 ;
V_61 >>= V_5 ;
V_62 >>= V_5 ;
if ( V_62 && V_54 > V_62 )
V_54 = V_62 ;
if ( V_54 <= F_43 )
return NULL ;
V_57 = V_54 ( V_60 >> V_5 , 1UL ) ;
if ( V_61 && F_43 < V_61 && V_61 < V_54 )
V_12 = F_4 ( V_61 , V_57 ) ;
else
V_12 = F_4 ( F_43 , V_57 ) ;
V_44 = V_12 - V_6 -> V_8 ;
V_64 = V_54 - V_6 -> V_8 ;
if ( V_6 -> V_46 > V_44 ) {
V_63 = V_44 + 1 ;
V_44 = F_48 ( V_6 , V_6 -> V_46 , V_57 ) ;
}
while ( 1 ) {
int V_65 ;
void * V_66 ;
unsigned long V_45 , V_67 , V_68 , V_69 ;
V_70:
V_44 = F_51 ( V_6 -> V_15 , V_64 , V_44 ) ;
V_44 = F_48 ( V_6 , V_44 , V_57 ) ;
V_45 = V_44 + F_21 ( V_25 ) ;
if ( V_44 >= V_64 || V_45 > V_64 )
break;
for ( V_67 = V_44 ; V_67 < V_45 ; V_67 ++ )
if ( F_52 ( V_67 , V_6 -> V_15 ) ) {
V_44 = F_48 ( V_6 , V_67 , V_57 ) ;
if ( V_44 == V_67 )
V_44 += V_57 ;
goto V_70;
}
if ( V_6 -> V_71 & ( V_72 - 1 ) &&
F_22 ( V_6 -> V_71 ) + 1 == V_44 )
V_68 = F_49 ( V_6 , V_6 -> V_71 , V_60 ) ;
else
V_68 = F_13 ( V_44 ) ;
V_65 = F_22 ( V_68 ) < V_44 ;
V_69 = V_68 + V_25 ;
V_6 -> V_71 = V_69 ;
V_6 -> V_46 = F_21 ( V_69 ) ;
if ( F_38 ( V_6 , F_22 ( V_68 ) + V_65 ,
F_21 ( V_69 ) , V_49 ) )
F_37 () ;
V_66 = F_12 ( F_13 ( V_6 -> V_8 ) +
V_68 ) ;
memset ( V_66 , 0 , V_25 ) ;
F_53 ( V_66 , V_25 , 0 , 0 ) ;
return V_66 ;
}
if ( V_63 ) {
V_44 = F_48 ( V_6 , V_63 - 1 , V_57 ) ;
V_63 = 0 ;
goto V_70;
}
return NULL ;
}
static void * T_1 F_54 ( unsigned long V_25 ,
unsigned long V_60 ,
unsigned long V_61 ,
unsigned long V_62 )
{
T_2 * V_6 ;
void * V_66 ;
if ( F_55 ( F_56 () ) )
return F_57 ( V_25 , V_73 ) ;
F_8 (bdata, &bdata_list, list) {
if ( V_61 && V_6 -> V_16 <= F_22 ( V_61 ) )
continue;
if ( V_62 && V_6 -> V_8 >= F_22 ( V_62 ) )
break;
V_66 = F_50 ( V_6 , V_25 , V_60 , V_61 , V_62 ) ;
if ( V_66 )
return V_66 ;
}
return NULL ;
}
static void * T_1 F_58 ( unsigned long V_25 ,
unsigned long V_60 ,
unsigned long V_61 ,
unsigned long V_62 )
{
void * V_74 ;
V_75:
V_74 = F_54 ( V_25 , V_60 , V_61 , V_62 ) ;
if ( V_74 )
return V_74 ;
if ( V_61 ) {
V_61 = 0 ;
goto V_75;
}
return NULL ;
}
void * T_1 F_59 ( unsigned long V_25 , unsigned long V_60 ,
unsigned long V_61 )
{
unsigned long V_62 = 0 ;
return F_58 ( V_25 , V_60 , V_61 , V_62 ) ;
}
static void * T_1 F_60 ( unsigned long V_25 , unsigned long V_60 ,
unsigned long V_61 , unsigned long V_62 )
{
void * V_76 = F_58 ( V_25 , V_60 , V_61 , V_62 ) ;
if ( V_76 )
return V_76 ;
F_61 ( V_77 L_8 , V_25 ) ;
F_62 ( L_9 ) ;
return NULL ;
}
void * T_1 F_63 ( unsigned long V_25 , unsigned long V_60 ,
unsigned long V_61 )
{
unsigned long V_62 = 0 ;
return F_60 ( V_25 , V_60 , V_61 , V_62 ) ;
}
void * T_1 F_64 ( T_3 * V_18 ,
unsigned long V_25 , unsigned long V_60 ,
unsigned long V_61 , unsigned long V_62 )
{
void * V_74 ;
if ( F_55 ( F_56 () ) )
return F_57 ( V_25 , V_73 ) ;
V_78:
if ( V_62 && V_61 + V_25 > V_62 )
V_62 = 0 ;
V_74 = F_50 ( V_18 -> V_6 , V_25 , V_60 , V_61 , V_62 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_54 ( V_25 , V_60 , V_61 , V_62 ) ;
if ( V_74 )
return V_74 ;
if ( V_61 ) {
V_61 = 0 ;
goto V_78;
}
return NULL ;
}
void * T_1 F_65 ( T_3 * V_18 , unsigned long V_25 ,
unsigned long V_60 , unsigned long V_61 )
{
if ( F_55 ( F_56 () ) )
return F_66 ( V_25 , V_73 , V_18 -> V_79 ) ;
return F_64 ( V_18 , V_25 , V_60 , V_61 , 0 ) ;
}
void * T_1 F_67 ( T_3 * V_18 , unsigned long V_25 ,
unsigned long V_60 , unsigned long V_61 ,
unsigned long V_62 )
{
void * V_74 ;
V_74 = F_64 ( V_18 , V_25 , V_60 , V_61 , 0 ) ;
if ( V_74 )
return V_74 ;
F_61 ( V_77 L_8 , V_25 ) ;
F_62 ( L_9 ) ;
return NULL ;
}
void * T_1 F_68 ( T_3 * V_18 , unsigned long V_25 ,
unsigned long V_60 , unsigned long V_61 )
{
if ( F_55 ( F_56 () ) )
return F_66 ( V_25 , V_73 , V_18 -> V_79 ) ;
return F_67 ( V_18 , V_25 , V_60 , V_61 , 0 ) ;
}
void * T_1 F_69 ( T_3 * V_18 , unsigned long V_25 ,
unsigned long V_60 , unsigned long V_61 )
{
#ifdef F_70
unsigned long V_80 ;
if ( F_55 ( F_56 () ) )
return F_66 ( V_25 , V_73 , V_18 -> V_79 ) ;
V_80 = V_18 -> V_81 + V_18 -> V_82 ;
if ( V_80 > F_70 + ( 128 >> ( 20 - V_5 ) ) &&
( V_61 >> V_5 ) < F_70 ) {
void * V_74 ;
unsigned long V_83 ;
V_83 = F_70 << V_5 ;
V_74 = F_50 ( V_18 -> V_6 , V_25 , V_60 ,
V_83 , 0 ) ;
if ( V_74 )
return V_74 ;
}
#endif
return F_68 ( V_18 , V_25 , V_60 , V_61 ) ;
}
void * T_1 F_71 ( unsigned long V_25 , unsigned long V_60 ,
unsigned long V_61 )
{
return F_60 ( V_25 , V_60 , V_61 , V_84 ) ;
}
void * T_1 F_72 ( unsigned long V_25 ,
unsigned long V_60 ,
unsigned long V_61 )
{
return F_58 ( V_25 , V_60 , V_61 ,
V_84 ) ;
}
void * T_1 F_73 ( T_3 * V_18 , unsigned long V_25 ,
unsigned long V_60 , unsigned long V_61 )
{
if ( F_55 ( F_56 () ) )
return F_66 ( V_25 , V_73 , V_18 -> V_79 ) ;
return F_67 ( V_18 , V_25 , V_60 ,
V_61 , V_84 ) ;
}
