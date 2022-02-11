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
F_15 ( V_18 ) ;
}
static int
F_16 ( struct V_30 * V_31 )
{
unsigned long V_32 , V_27 ;
unsigned long V_33 ;
T_1 V_21 = V_31 -> V_34 ;
struct V_17 * V_18 = V_31 -> V_16 -> V_19 ;
V_27 = ( volatile unsigned long ) V_18 -> V_27 [ V_21 ] ;
if ( V_27 == 0 ) {
V_27 = F_17 ( F_18 () , 1 ) ;
if ( V_27 == 0 )
return V_35 ;
F_19 ( & V_18 -> V_36 ) ;
if ( V_18 -> V_27 [ V_21 ] == 0 ) {
V_18 -> V_37 ++ ;
V_18 -> V_27 [ V_21 ] = V_27 ;
} else {
F_13 ( V_27 , 1 ) ;
V_27 = V_18 -> V_27 [ V_21 ] ;
}
F_20 ( & V_18 -> V_36 ) ;
}
if ( V_18 -> type == V_38 )
V_32 = F_6 ( V_27 ) ;
else
V_32 = V_27 & ~ V_12 ;
V_33 = V_32 >> V_26 ;
F_21 ( V_31 -> V_16 , V_31 -> V_39 , V_33 ) ;
return V_40 ;
}
static int
F_22 ( struct V_41 * V_41 , struct V_15 * V_16 ,
enum V_42 type )
{
struct V_17 * V_18 ;
int V_43 , V_44 ;
if ( V_16 -> V_45 != 0 )
return - V_46 ;
if ( ( V_16 -> V_47 & V_48 ) == 0 )
return - V_46 ;
if ( ( V_16 -> V_47 & V_49 ) == 0 )
return - V_50 ;
V_43 = F_23 ( V_16 ) ;
V_44 = sizeof( struct V_17 ) + V_43 * sizeof( long ) ;
if ( V_44 <= V_28 )
V_18 = F_24 ( V_44 , V_51 ) ;
else
V_18 = F_25 ( V_44 ) ;
if ( ! V_18 )
return - V_52 ;
V_18 -> V_25 = V_16 -> V_25 ;
V_18 -> V_24 = V_16 -> V_24 ;
V_18 -> type = type ;
F_26 ( & V_18 -> V_36 ) ;
F_27 ( & V_18 -> V_20 , 1 ) ;
V_16 -> V_19 = V_18 ;
V_16 -> V_47 |= V_53 | V_54 | V_55 | V_56 ;
if ( V_18 -> type == V_38 || V_18 -> type == V_57 )
V_16 -> V_58 = F_28 ( V_16 -> V_58 ) ;
V_16 -> V_59 = & V_60 ;
return 0 ;
}
static int
F_29 ( struct V_41 * V_41 , struct V_15 * V_16 )
{
return F_22 ( V_41 , V_16 , V_38 ) ;
}
static int
F_30 ( struct V_41 * V_41 , struct V_15 * V_16 )
{
return F_22 ( V_41 , V_16 , V_61 ) ;
}
static int
F_31 ( struct V_41 * V_41 , struct V_15 * V_16 )
{
return F_22 ( V_41 , V_16 , V_57 ) ;
}
static int T_2
F_32 ( void )
{
int V_62 ;
int V_5 ;
#ifdef F_33
if ( F_34 ( L_3 ) ) {
V_4 = 1 ;
if ( F_2 () ) {
V_62 = - V_52 ;
F_35 (nid, N_ONLINE) {
int V_63 ;
int V_64 ;
unsigned long V_65 ;
V_8 [ V_5 ] = F_17 ( V_5 , 1 ) ;
if ( V_8 [ V_5 ] == 0 )
goto V_66;
V_65 = F_5 ( V_8 [ V_5 ] ) ;
V_64 = F_4 ( V_65 ) ;
V_63 = F_3 ( V_64 ) ;
if ( V_63 != V_5 )
goto V_66;
}
}
V_62 = F_36 ( & V_67 ) ;
if ( V_62 ) {
F_14 ( V_68
L_4 ,
V_69 , V_62 ) ;
goto V_66;
}
}
#endif
V_62 = F_36 ( & V_70 ) ;
if ( V_62 ) {
F_14 ( V_68 L_4 ,
V_71 , V_62 ) ;
if ( V_4 )
F_37 ( & V_67 ) ;
goto V_66;
}
V_62 = F_36 ( & V_72 ) ;
if ( V_62 ) {
F_14 ( V_68 L_4 ,
V_73 , V_62 ) ;
F_37 ( & V_70 ) ;
if ( V_4 )
F_37 ( & V_67 ) ;
goto V_66;
}
F_14 ( V_74 L_5 ,
V_75 , V_76 , V_4 ? V_69 : L_6 ,
V_71 , V_73 ) ;
return 0 ;
V_66:
F_38 (nid) {
if ( V_8 [ V_5 ] != 0 )
F_13 ( V_8 [ V_5 ] , 1 ) ;
}
return V_62 ;
}
static void T_3
F_39 ( void )
{
int V_5 ;
F_37 ( & V_72 ) ;
F_37 ( & V_70 ) ;
if ( V_4 ) {
F_37 ( & V_67 ) ;
F_38 (nid) {
if ( V_8 [ V_5 ] != 0 )
F_13 ( V_8 [ V_5 ] , 1 ) ;
}
}
}
