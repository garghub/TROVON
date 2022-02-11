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
static int F_20 ( struct V_32 * V_2 ,
struct V_33 * V_34 ,
unsigned long * V_7 ,
unsigned int * type )
{
if ( F_21 ( V_34 -> V_35 ) ) {
if ( V_34 -> V_36 != 3 )
return - V_37 ;
if ( V_34 -> V_38 [ 0 ] != 0 )
return - V_37 ;
* V_7 = V_34 -> V_38 [ 1 ] ;
* type = V_34 -> V_38 [ 2 ] & V_39 ;
return 0 ;
}
return - V_37 ;
}
static int F_22 ( struct V_32 * V_40 ,
unsigned int V_41 ,
unsigned int V_42 , void * V_43 )
{
struct V_33 * V_34 = V_43 ;
struct V_33 V_44 ;
struct V_45 * V_46 = V_40 -> V_47 ;
T_3 V_7 ;
unsigned int V_18 ;
if ( V_34 -> V_36 != 3 )
return - V_37 ;
if ( V_34 -> V_38 [ 0 ] != V_48 )
return - V_37 ;
V_7 = V_34 -> V_38 [ 1 ] ;
if ( V_7 >= ( V_19 * 32 ) )
return - V_37 ;
for ( V_18 = 0 ; V_18 < V_42 ; V_18 ++ ) {
int V_20 = ( V_7 + V_18 ) / 32 ;
F_23 ( V_40 , V_41 + V_18 , V_7 + V_18 ,
& V_49 ,
V_46 -> V_4 [ V_20 ] ) ;
}
V_44 = * V_34 ;
V_44 . V_35 = V_40 -> V_50 -> V_35 ;
return F_24 ( V_40 , V_41 , V_42 ,
& V_44 ) ;
}
static int T_4 F_25 ( struct V_51 * V_52 ,
struct V_51 * V_50 )
{
struct V_32 * V_53 , * V_40 ;
const struct V_54 * V_55 ;
const struct V_56 * V_57 ;
unsigned int V_18 ;
int V_58 ;
if ( ! V_50 ) {
F_26 ( L_1 , V_52 -> V_59 ) ;
return - V_60 ;
}
V_53 = F_27 ( V_50 ) ;
if ( ! V_53 ) {
F_26 ( L_2 , V_52 -> V_59 ) ;
return - V_61 ;
}
V_55 = F_28 ( V_62 , V_52 ) ;
if ( ! V_55 )
return - V_60 ;
V_57 = V_55 -> V_43 ;
V_15 = F_29 ( sizeof( * V_15 ) , V_63 ) ;
if ( ! V_15 )
return - V_64 ;
for ( V_18 = 0 ; V_18 < V_65 ; V_18 ++ ) {
void T_1 * V_4 ;
V_4 = F_30 ( V_52 , V_18 ) ;
if ( ! V_4 )
break;
V_15 -> V_4 [ V_18 ] = V_4 ;
F_3 ( ~ 0UL , V_4 + V_8 ) ;
F_3 ( 0 , V_4 + V_24 ) ;
V_19 ++ ;
}
if ( ! V_19 ) {
F_26 ( L_3 , V_52 -> V_59 ) ;
V_58 = - V_64 ;
goto V_66;
}
F_31 ( V_19 != V_57 -> V_19 ,
L_4 ,
V_52 -> V_59 , V_19 , V_57 -> V_19 ) ;
V_40 = F_32 ( V_53 , 0 , V_19 * 32 ,
V_52 , & V_67 ,
V_15 ) ;
if ( ! V_40 ) {
F_26 ( L_5 , V_52 -> V_59 ) ;
V_58 = - V_64 ;
goto V_68;
}
F_18 () ;
F_33 ( L_6 ,
V_52 -> V_59 , V_19 * 32 , V_50 -> V_59 ) ;
return 0 ;
V_68:
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ )
F_34 ( V_15 -> V_4 [ V_18 ] ) ;
V_66:
F_35 ( V_15 ) ;
return V_58 ;
}
