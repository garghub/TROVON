static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = & F_2 ( V_6 ) ;
struct V_1 * V_7 = V_5 -> V_8 ;
struct V_9 * V_10 = V_11 -> V_12 ;
if ( ! V_7 )
return;
* V_7 = * V_2 ;
F_3 () ;
if ( V_3 + V_13 < V_10 -> V_14 )
return;
++ V_7 ;
if ( V_7 == V_5 -> V_15 )
V_7 = V_5 -> V_16 ;
V_5 -> V_8 = V_7 ;
F_4 () ;
++ V_5 -> V_17 ;
}
static int F_5 ( struct V_18 * V_18 )
{
struct V_4 * V_5 = & F_6 ( V_6 , V_18 -> V_19 ) ;
V_5 -> V_16 = V_18 -> V_16 ;
V_5 -> V_15 = V_18 -> V_16 + V_18 -> V_20 ;
V_5 -> V_17 = 0 ;
F_4 () ;
V_5 -> V_8 = V_18 -> V_16 ;
V_5 -> V_21 = F_7 ( V_18 -> V_19 ) . V_22 ;
F_7 ( V_18 -> V_19 ) . V_22 |= V_23 ;
V_24 = F_1 ;
F_8 ( & V_25 ) ;
return 0 ;
}
static void F_9 ( struct V_18 * V_18 )
{
struct V_4 * V_5 = & F_6 ( V_6 , V_18 -> V_19 ) ;
V_5 -> V_8 = NULL ;
F_4 () ;
V_5 -> V_16 = NULL ;
F_7 ( V_18 -> V_19 ) . V_22 = V_5 -> V_21 ;
if ( F_10 ( & V_25 ) )
V_24 = NULL ;
}
static T_1 F_11 ( struct V_18 * V_18 )
{
return F_6 ( V_6 , V_18 -> V_19 ) . V_17 ;
}
static int F_5 ( struct V_18 * V_18 )
{
unsigned long V_26 ;
int V_27 , V_28 ;
( ( V_29 * ) V_18 -> V_16 ) [ 1 ] = V_30 ;
V_28 = F_12 ( V_18 -> V_19 ) ;
V_26 = F_13 ( V_18 -> V_16 ) ;
V_27 = F_14 ( V_28 , V_26 ) ;
if ( V_27 ) {
F_15 ( V_31 L_1
L_2 , V_32 , V_18 -> V_19 , V_28 , V_27 ) ;
return - V_33 ;
}
F_7 ( V_18 -> V_19 ) . V_14 = 0 ;
F_4 () ;
F_7 ( V_18 -> V_19 ) . V_22 = V_23 ;
return 0 ;
}
static void F_9 ( struct V_18 * V_18 )
{
int V_28 = F_12 ( V_18 -> V_19 ) ;
F_7 ( V_18 -> V_19 ) . V_22 = 0x0 ;
F_16 ( V_28 ) ;
}
static T_1 F_11 ( struct V_18 * V_18 )
{
return F_7 ( V_18 -> V_19 ) . V_14 ;
}
static int F_17 ( struct V_18 * V_18 )
{
long int V_34 ;
long int V_35 ;
struct V_1 * V_16 = NULL ;
if ( ! V_36 )
return - V_37 ;
if ( V_18 -> V_16 )
return - V_38 ;
V_34 = V_39 ;
V_16 = F_18 ( V_36 , V_40 , F_19 ( V_18 -> V_19 ) ) ;
if ( ! V_16 ) {
F_15 ( V_31 L_3 ,
V_32 , V_18 -> V_19 ) ;
return - V_37 ;
}
F_20 ( & V_18 -> V_41 ) ;
V_35 = - V_38 ;
if ( ! V_18 -> V_16 ) {
V_18 -> V_20 = V_34 ;
V_18 -> V_16 = V_16 ;
V_18 -> V_42 = 0 ;
V_35 = F_5 ( V_18 ) ;
if ( V_35 )
V_18 -> V_16 = NULL ;
}
F_21 ( & V_18 -> V_41 ) ;
if ( V_35 )
F_22 ( V_36 , V_16 ) ;
return V_35 ;
}
static void F_23 ( struct V_18 * V_18 )
{
F_20 ( & V_18 -> V_41 ) ;
F_9 ( V_18 ) ;
F_22 ( V_36 , V_18 -> V_16 ) ;
V_18 -> V_16 = NULL ;
V_18 -> V_20 = 0 ;
F_21 ( & V_18 -> V_41 ) ;
}
static int F_24 ( struct V_43 * V_43 , struct V_44 * V_45 )
{
struct V_18 * V_18 = V_43 -> V_46 ;
int V_35 ;
V_35 = F_17 ( V_18 ) ;
if ( V_35 )
return V_35 ;
V_45 -> V_47 = V_18 ;
return 0 ;
}
static int F_25 ( struct V_43 * V_43 , struct V_44 * V_45 )
{
struct V_18 * V_18 = V_43 -> V_46 ;
F_23 ( V_18 ) ;
return 0 ;
}
static T_2 F_26 ( struct V_44 * V_45 , char T_3 * V_16 , T_4 V_48 ,
T_5 * V_49 )
{
long int V_35 , V_50 , V_51 , V_52 ;
struct V_18 * V_18 ;
T_1 V_53 , V_42 , V_54 ;
if ( ( V_48 % sizeof( struct V_1 ) ) != 0 )
return - V_55 ;
V_18 = V_45 -> V_47 ;
V_51 = V_48 / sizeof( struct V_1 ) ;
V_50 = 0 ;
F_20 ( & V_18 -> V_41 ) ;
V_53 = F_11 ( V_18 ) ;
V_42 = V_18 -> V_42 ;
if ( V_42 + V_18 -> V_20 <= V_53 )
V_42 = V_53 - V_18 -> V_20 + 1 ;
if ( V_42 + V_51 > V_53 )
V_51 = V_53 - V_42 ;
if ( V_51 > 0 )
V_18 -> V_42 = V_42 + V_51 ;
F_21 ( & V_18 -> V_41 ) ;
if ( V_51 <= 0 )
return 0 ;
V_54 = V_42 % V_18 -> V_20 ;
if ( V_54 + V_51 > V_18 -> V_20 ) {
V_52 = V_18 -> V_20 - V_54 ;
V_35 = F_27 ( V_16 , & V_18 -> V_16 [ V_54 ] ,
V_52 * sizeof( struct V_1 ) ) ;
if ( V_35 )
return - V_56 ;
V_54 = 0 ;
V_51 -= V_52 ;
V_50 += V_52 ;
V_16 += V_52 * sizeof( struct V_1 ) ;
}
V_35 = F_27 ( V_16 , & V_18 -> V_16 [ V_54 ] , V_51 * sizeof( struct V_1 ) ) ;
if ( V_35 )
return - V_56 ;
V_50 += V_51 ;
return V_50 * sizeof( struct V_1 ) ;
}
static int F_28 ( struct V_18 * V_18 )
{
char V_57 [ 10 ] ;
sprintf ( V_57 , L_4 , V_18 -> V_19 ) ;
V_18 -> V_44 = F_29 ( V_57 , 0400 , V_58 , V_18 , & V_59 ) ;
if ( ! V_18 -> V_44 )
return - V_37 ;
return 0 ;
}
static int F_30 ( void )
{
struct V_60 * V_61 , * V_62 ;
int V_35 , V_54 ;
if ( ! F_31 ( V_63 ) )
return - V_64 ;
V_35 = - V_37 ;
V_58 = F_32 ( L_5 , V_65 ) ;
if ( ! V_58 ) {
F_15 ( V_31 L_6 ,
V_32 ) ;
goto V_66;
}
V_61 = F_33 ( L_7 , 0600 ,
V_58 , & V_23 ) ;
V_62 = F_34 ( L_8 , 0400 ,
V_58 , & V_39 ) ;
if ( ! V_61 || ! V_62 ) {
F_15 ( V_31 L_9 , V_32 ) ;
goto V_67;
}
F_35 (i) {
struct V_18 * V_18 = & F_6 ( V_68 , V_54 ) ;
F_36 ( & V_18 -> V_41 ) ;
V_18 -> V_19 = V_54 ;
V_35 = F_28 ( V_18 ) ;
if ( V_35 )
goto V_67;
}
return 0 ;
V_67:
F_37 ( V_58 ) ;
V_66:
return V_35 ;
}
