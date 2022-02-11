static inline int
F_1 ( unsigned long V_1 , int V_2 )
{
int V_3 ;
if ( V_4 ) {
if ( F_2 () ) {
int V_5 ;
void * V_6 ;
int V_7 ;
V_5 = F_3 ( F_4 ( F_5 ( V_1 ) ) ) ;
V_6 = ( void * ) F_6 ( V_8 [ V_5 ] ) ;
for ( V_7 = 0 ; V_7 < V_9 ; V_7 ++ ) {
F_7 ( V_6 , V_10 ) ;
V_6 += V_11 ;
}
}
V_3 = F_8 ( 0 , V_1 & ~ V_12 , V_2 ,
V_13 | V_14 , NULL ) ;
} else {
memset ( ( char * ) V_1 , 0 , V_2 ) ;
V_3 = 0 ;
}
return V_3 ;
}
static void
F_9 ( struct V_15 * V_16 )
{
struct V_17 * V_18 ;
V_18 = V_16 -> V_19 ;
F_10 ( & V_18 -> V_20 ) ;
}
static void
F_11 ( struct V_15 * V_16 )
{
struct V_17 * V_18 ;
int V_21 , V_22 ;
unsigned long V_23 ;
V_18 = V_16 -> V_19 ;
if ( ! F_12 ( & V_18 -> V_20 ) )
return;
V_22 = ( V_18 -> V_24 - V_18 -> V_25 ) >> V_26 ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
if ( V_18 -> V_27 [ V_21 ] == 0 )
continue;
V_23 = V_18 -> V_27 [ V_21 ] ;
V_18 -> V_27 [ V_21 ] = 0 ;
if ( ! F_1 ( V_23 , V_28 ) )
F_13 ( V_23 , 1 ) ;
else
F_14 ( V_29 L_1
L_2 , V_23 ) ;
}
if ( V_18 -> V_30 & V_31 )
F_15 ( V_18 ) ;
else
F_16 ( V_18 ) ;
}
static int
F_17 ( struct V_15 * V_16 , struct V_32 * V_33 )
{
unsigned long V_34 , V_27 ;
unsigned long V_35 ;
T_1 V_21 = V_33 -> V_36 ;
struct V_17 * V_18 = V_16 -> V_19 ;
V_27 = ( volatile unsigned long ) V_18 -> V_27 [ V_21 ] ;
if ( V_27 == 0 ) {
V_27 = F_18 ( F_19 () , 1 ) ;
if ( V_27 == 0 )
return V_37 ;
F_20 ( & V_18 -> V_38 ) ;
if ( V_18 -> V_27 [ V_21 ] == 0 ) {
V_18 -> V_39 ++ ;
V_18 -> V_27 [ V_21 ] = V_27 ;
} else {
F_13 ( V_27 , 1 ) ;
V_27 = V_18 -> V_27 [ V_21 ] ;
}
F_21 ( & V_18 -> V_38 ) ;
}
if ( V_18 -> type == V_40 )
V_34 = F_6 ( V_27 ) ;
else
V_34 = V_27 & ~ V_12 ;
V_35 = V_34 >> V_26 ;
F_22 ( V_16 , ( unsigned long ) V_33 -> V_41 , V_35 ) ;
return V_42 ;
}
static int
F_23 ( struct V_43 * V_43 , struct V_15 * V_16 ,
enum V_44 type )
{
struct V_17 * V_18 ;
int V_45 , V_46 , V_30 = 0 ;
if ( V_16 -> V_47 != 0 )
return - V_48 ;
if ( ( V_16 -> V_49 & V_50 ) == 0 )
return - V_48 ;
if ( ( V_16 -> V_49 & V_51 ) == 0 )
return - V_52 ;
V_45 = F_24 ( V_16 ) ;
V_46 = sizeof( struct V_17 ) + V_45 * sizeof( long ) ;
if ( V_46 <= V_28 )
V_18 = F_25 ( V_46 , V_53 ) ;
else {
V_18 = F_26 ( V_46 ) ;
V_30 = V_31 ;
}
if ( ! V_18 )
return - V_54 ;
V_18 -> V_25 = V_16 -> V_25 ;
V_18 -> V_24 = V_16 -> V_24 ;
V_18 -> V_30 = V_30 ;
V_18 -> type = type ;
F_27 ( & V_18 -> V_38 ) ;
F_28 ( & V_18 -> V_20 , 1 ) ;
V_16 -> V_19 = V_18 ;
V_16 -> V_49 |= V_55 | V_56 | V_57 | V_58 ;
if ( V_18 -> type == V_40 || V_18 -> type == V_59 )
V_16 -> V_60 = F_29 ( V_16 -> V_60 ) ;
V_16 -> V_61 = & V_62 ;
return 0 ;
}
static int
F_30 ( struct V_43 * V_43 , struct V_15 * V_16 )
{
return F_23 ( V_43 , V_16 , V_40 ) ;
}
static int
F_31 ( struct V_43 * V_43 , struct V_15 * V_16 )
{
return F_23 ( V_43 , V_16 , V_63 ) ;
}
static int
F_32 ( struct V_43 * V_43 , struct V_15 * V_16 )
{
return F_23 ( V_43 , V_16 , V_59 ) ;
}
static int T_2
F_33 ( void )
{
int V_64 ;
int V_5 ;
#ifdef F_34
if ( F_35 ( L_3 ) ) {
V_4 = 1 ;
if ( F_2 () ) {
V_64 = - V_54 ;
F_36 (nid, N_ONLINE) {
int V_65 ;
int V_66 ;
unsigned long V_67 ;
V_8 [ V_5 ] = F_18 ( V_5 , 1 ) ;
if ( V_8 [ V_5 ] == 0 )
goto V_68;
V_67 = F_5 ( V_8 [ V_5 ] ) ;
V_66 = F_4 ( V_67 ) ;
V_65 = F_3 ( V_66 ) ;
if ( V_65 != V_5 )
goto V_68;
}
}
V_64 = F_37 ( & V_69 ) ;
if ( V_64 ) {
F_14 ( V_70
L_4 ,
V_71 , V_64 ) ;
goto V_68;
}
}
#endif
V_64 = F_37 ( & V_72 ) ;
if ( V_64 ) {
F_14 ( V_70 L_4 ,
V_73 , V_64 ) ;
if ( V_4 )
F_38 ( & V_69 ) ;
goto V_68;
}
V_64 = F_37 ( & V_74 ) ;
if ( V_64 ) {
F_14 ( V_70 L_4 ,
V_75 , V_64 ) ;
F_38 ( & V_72 ) ;
if ( V_4 )
F_38 ( & V_69 ) ;
goto V_68;
}
F_14 ( V_76 L_5 ,
V_77 , V_78 , V_4 ? V_71 : L_6 ,
V_73 , V_75 ) ;
return 0 ;
V_68:
F_39 (nid) {
if ( V_8 [ V_5 ] != 0 )
F_13 ( V_8 [ V_5 ] , 1 ) ;
}
return V_64 ;
}
static void T_3
F_40 ( void )
{
int V_5 ;
F_38 ( & V_74 ) ;
F_38 ( & V_72 ) ;
if ( V_4 ) {
F_38 ( & V_69 ) ;
F_39 (nid) {
if ( V_8 [ V_5 ] != 0 )
F_13 ( V_8 [ V_5 ] , 1 ) ;
}
}
}
