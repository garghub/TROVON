static inline void F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
V_6 = F_2 ( V_2 -> V_7 % 32 ) ;
F_3 ( V_6 , V_4 + V_3 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_8 ) ;
F_5 ( V_2 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_9 ) ;
F_7 ( V_2 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_10 ) ;
F_9 ( V_2 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_11 ) ;
return F_11 ( V_2 ) ;
}
static int F_12 ( struct V_1 * V_2 , unsigned int V_12 )
{
T_2 V_13 = V_2 -> V_7 ;
T_2 V_14 , V_6 ;
V_14 = ( V_13 / 32 ) ;
V_6 = F_2 ( V_13 % 32 ) ;
if ( V_12 )
V_15 -> V_16 [ V_14 ] |= V_6 ;
else
V_15 -> V_16 [ V_14 ] &= ~ V_6 ;
return 0 ;
}
static int F_13 ( void )
{
unsigned long V_17 ;
unsigned int V_18 ;
F_14 ( V_17 ) ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ ) {
void T_1 * V_20 = V_15 -> V_4 [ V_18 ] ;
V_15 -> V_21 [ V_18 ] = F_15 ( V_20 + V_22 ) ;
V_15 -> V_23 [ V_18 ] = F_15 ( V_20 + V_24 ) ;
V_15 -> V_25 [ V_18 ] = F_15 ( V_20 + V_26 ) ;
V_15 -> V_27 [ V_18 ] = F_15 ( V_20 + V_28 ) ;
F_3 ( ~ 0ul , V_20 + V_29 ) ;
F_3 ( ~ 0ul , V_20 + V_8 ) ;
F_3 ( V_15 -> V_16 [ V_18 ] , V_20 + V_9 ) ;
}
F_16 ( V_17 ) ;
return 0 ;
}
static void F_17 ( void )
{
unsigned long V_17 ;
unsigned int V_18 ;
F_14 ( V_17 ) ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ ) {
void T_1 * V_20 = V_15 -> V_4 [ V_18 ] ;
F_3 ( V_15 -> V_23 [ V_18 ] ,
V_20 + V_24 ) ;
F_3 ( ~ 0ul , V_20 + V_8 ) ;
F_3 ( V_15 -> V_21 [ V_18 ] ,
V_20 + V_9 ) ;
F_3 ( V_15 -> V_27 [ V_18 ] ,
V_20 + V_28 ) ;
F_3 ( ~ 0ul , V_20 + V_29 ) ;
F_3 ( V_15 -> V_25 [ V_18 ] ,
V_20 + V_30 ) ;
}
F_16 ( V_17 ) ;
}
static void F_18 ( void )
{
F_19 ( & V_31 ) ;
}
static inline void F_18 ( void ) {}
static int F_20 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const T_2 * V_36 ,
unsigned int V_37 ,
unsigned long * V_38 ,
unsigned int * V_39 )
{
if ( V_33 -> V_40 != V_35 )
return - V_41 ;
if ( V_37 != 3 )
return - V_41 ;
if ( V_36 [ 0 ] != V_42 )
return - V_41 ;
* V_38 = V_36 [ 1 ] ;
* V_39 = V_36 [ 2 ] ;
return 0 ;
}
static int F_21 ( struct V_32 * V_33 ,
unsigned int V_43 ,
unsigned int V_44 , void * V_45 )
{
struct V_46 * args = V_45 ;
struct V_46 V_47 ;
struct V_48 * V_49 = V_33 -> V_50 ;
T_3 V_7 ;
unsigned int V_18 ;
if ( args -> V_51 != 3 )
return - V_41 ;
if ( args -> args [ 0 ] != V_42 )
return - V_41 ;
V_7 = args -> args [ 1 ] ;
if ( V_7 >= ( V_19 * 32 ) )
return - V_41 ;
for ( V_18 = 0 ; V_18 < V_44 ; V_18 ++ ) {
int V_20 = ( V_7 + V_18 ) / 32 ;
F_22 ( V_33 , V_43 + V_18 , V_7 + V_18 ,
& V_52 ,
V_49 -> V_4 [ V_20 ] ) ;
}
V_47 = * args ;
V_47 . V_53 = V_33 -> V_54 -> V_40 ;
return F_23 ( V_33 , V_43 , V_44 , & V_47 ) ;
}
static void F_24 ( struct V_32 * V_33 ,
unsigned int V_43 ,
unsigned int V_44 )
{
unsigned int V_18 ;
for ( V_18 = 0 ; V_18 < V_44 ; V_18 ++ ) {
struct V_1 * V_2 = F_25 ( V_33 , V_43 + V_18 ) ;
F_26 ( V_2 ) ;
}
}
static int T_4 F_27 ( struct V_34 * V_55 ,
struct V_34 * V_54 )
{
struct V_32 * V_56 , * V_33 ;
const struct V_57 * V_58 ;
const struct V_59 * V_60 ;
unsigned int V_18 ;
int V_61 ;
if ( ! V_54 ) {
F_28 ( L_1 , V_55 -> V_62 ) ;
return - V_63 ;
}
V_56 = F_29 ( V_54 ) ;
if ( ! V_56 ) {
F_28 ( L_2 , V_55 -> V_62 ) ;
return - V_64 ;
}
V_58 = F_30 ( V_65 , V_55 ) ;
if ( ! V_58 )
return - V_63 ;
V_60 = V_58 -> V_45 ;
V_15 = F_31 ( sizeof( * V_15 ) , V_66 ) ;
if ( ! V_15 )
return - V_67 ;
for ( V_18 = 0 ; V_18 < V_68 ; V_18 ++ ) {
void T_1 * V_4 ;
V_4 = F_32 ( V_55 , V_18 ) ;
if ( ! V_4 )
break;
V_15 -> V_4 [ V_18 ] = V_4 ;
F_3 ( ~ 0UL , V_4 + V_8 ) ;
F_3 ( 0 , V_4 + V_24 ) ;
V_19 ++ ;
}
if ( ! V_19 ) {
F_28 ( L_3 , V_55 -> V_62 ) ;
V_61 = - V_67 ;
goto V_69;
}
F_33 ( V_19 != V_60 -> V_19 ,
L_4 ,
V_55 -> V_62 , V_19 , V_60 -> V_19 ) ;
V_33 = F_34 ( V_56 , 0 , V_19 * 32 ,
V_55 , & V_70 ,
V_15 ) ;
if ( ! V_33 ) {
F_28 ( L_5 , V_55 -> V_62 ) ;
V_61 = - V_67 ;
goto V_71;
}
F_18 () ;
F_35 ( L_6 ,
V_55 -> V_62 , V_19 * 32 , V_54 -> V_62 ) ;
return 0 ;
V_71:
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ )
F_36 ( V_15 -> V_4 [ V_18 ] ) ;
V_69:
F_37 ( V_15 ) ;
return V_61 ;
}
