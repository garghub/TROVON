static inline void F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
void T_1 * V_4 = ( void T_1 V_5 * ) V_2 -> V_6 ;
T_2 V_7 ;
V_7 = F_2 ( V_2 -> V_8 % 32 ) ;
F_3 ( V_7 , V_4 + V_3 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_9 ) ;
F_5 ( V_2 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_10 ) ;
F_7 ( V_2 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_11 ) ;
F_9 ( V_2 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_12 ) ;
return F_11 ( V_2 ) ;
}
static int F_12 ( struct V_1 * V_2 , unsigned int V_13 )
{
T_2 V_14 = V_2 -> V_8 ;
T_2 V_15 , V_7 ;
V_15 = ( V_14 / 32 ) ;
V_7 = F_2 ( V_14 % 32 ) ;
if ( V_13 )
V_16 -> V_17 [ V_15 ] |= V_7 ;
else
V_16 -> V_17 [ V_15 ] &= ~ V_7 ;
return 0 ;
}
static int F_13 ( void )
{
unsigned long V_18 ;
unsigned int V_19 ;
F_14 ( V_18 ) ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ ) {
void T_1 * V_21 = V_16 -> V_4 [ V_19 ] ;
V_16 -> V_22 [ V_19 ] = F_15 ( V_21 + V_23 ) ;
V_16 -> V_24 [ V_19 ] = F_15 ( V_21 + V_25 ) ;
V_16 -> V_26 [ V_19 ] = F_15 ( V_21 + V_27 ) ;
V_16 -> V_28 [ V_19 ] = F_15 ( V_21 + V_29 ) ;
F_3 ( ~ 0ul , V_21 + V_30 ) ;
F_3 ( ~ 0ul , V_21 + V_9 ) ;
F_3 ( V_16 -> V_17 [ V_19 ] , V_21 + V_10 ) ;
}
F_16 ( V_18 ) ;
return 0 ;
}
static void F_17 ( void )
{
unsigned long V_18 ;
unsigned int V_19 ;
F_14 ( V_18 ) ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ ) {
void T_1 * V_21 = V_16 -> V_4 [ V_19 ] ;
F_3 ( V_16 -> V_24 [ V_19 ] ,
V_21 + V_25 ) ;
F_3 ( ~ 0ul , V_21 + V_9 ) ;
F_3 ( V_16 -> V_22 [ V_19 ] ,
V_21 + V_10 ) ;
F_3 ( V_16 -> V_28 [ V_19 ] ,
V_21 + V_29 ) ;
F_3 ( ~ 0ul , V_21 + V_30 ) ;
F_3 ( V_16 -> V_26 [ V_19 ] ,
V_21 + V_31 ) ;
}
F_16 ( V_18 ) ;
}
static void F_18 ( void )
{
F_19 ( & V_32 ) ;
}
static inline void F_18 ( void ) {}
static int F_20 ( struct V_33 * V_2 ,
struct V_34 * V_35 ,
unsigned long * V_8 ,
unsigned int * type )
{
if ( F_21 ( V_35 -> V_36 ) ) {
if ( V_35 -> V_37 != 3 )
return - V_38 ;
if ( V_35 -> V_39 [ 0 ] != 0 )
return - V_38 ;
* V_8 = V_35 -> V_39 [ 1 ] ;
* type = V_35 -> V_39 [ 2 ] & V_40 ;
return 0 ;
}
return - V_38 ;
}
static int F_22 ( struct V_33 * V_41 ,
unsigned int V_42 ,
unsigned int V_43 , void * V_44 )
{
struct V_34 * V_35 = V_44 ;
struct V_34 V_45 ;
struct V_46 * V_47 = V_41 -> V_48 ;
T_3 V_8 ;
unsigned int V_19 ;
if ( V_35 -> V_37 != 3 )
return - V_38 ;
if ( V_35 -> V_39 [ 0 ] != V_49 )
return - V_38 ;
V_8 = V_35 -> V_39 [ 1 ] ;
if ( V_8 >= ( V_20 * 32 ) )
return - V_38 ;
for ( V_19 = 0 ; V_19 < V_43 ; V_19 ++ ) {
int V_21 = ( V_8 + V_19 ) / 32 ;
F_23 ( V_41 , V_42 + V_19 , V_8 + V_19 ,
& V_50 ,
( void V_5 * ) V_47 -> V_4 [ V_21 ] ) ;
}
V_45 = * V_35 ;
V_45 . V_36 = V_41 -> V_51 -> V_36 ;
return F_24 ( V_41 , V_42 , V_43 ,
& V_45 ) ;
}
static int T_4 F_25 ( struct V_52 * V_53 ,
struct V_52 * V_51 )
{
struct V_33 * V_54 , * V_41 ;
const struct V_55 * V_56 ;
const struct V_57 * V_58 ;
unsigned int V_19 ;
int V_59 ;
if ( ! V_51 ) {
F_26 ( L_1 , V_53 ) ;
return - V_60 ;
}
V_54 = F_27 ( V_51 ) ;
if ( ! V_54 ) {
F_26 ( L_2 , V_53 ) ;
return - V_61 ;
}
V_56 = F_28 ( V_62 , V_53 ) ;
if ( ! V_56 )
return - V_60 ;
V_58 = V_56 -> V_44 ;
V_16 = F_29 ( sizeof( * V_16 ) , V_63 ) ;
if ( ! V_16 )
return - V_64 ;
for ( V_19 = 0 ; V_19 < V_65 ; V_19 ++ ) {
void T_1 * V_4 ;
V_4 = F_30 ( V_53 , V_19 ) ;
if ( ! V_4 )
break;
V_16 -> V_4 [ V_19 ] = V_4 ;
F_3 ( ~ 0UL , V_4 + V_9 ) ;
F_3 ( 0 , V_4 + V_25 ) ;
V_20 ++ ;
}
if ( ! V_20 ) {
F_26 ( L_3 , V_53 ) ;
V_59 = - V_64 ;
goto V_66;
}
F_31 ( V_20 != V_58 -> V_20 ,
L_4 ,
V_53 , V_20 , V_58 -> V_20 ) ;
V_41 = F_32 ( V_54 , 0 , V_20 * 32 ,
V_53 , & V_67 ,
V_16 ) ;
if ( ! V_41 ) {
F_26 ( L_5 , V_53 ) ;
V_59 = - V_64 ;
goto V_68;
}
F_18 () ;
F_33 ( L_6 ,
V_53 , V_20 * 32 , V_51 ) ;
return 0 ;
V_68:
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ )
F_34 ( V_16 -> V_4 [ V_19 ] ) ;
V_66:
F_35 ( V_16 ) ;
return V_59 ;
}
