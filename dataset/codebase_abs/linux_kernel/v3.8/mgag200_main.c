static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 )
F_3 ( V_4 -> V_5 ) ;
F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
unsigned int * V_8 )
{
return 0 ;
}
int F_7 ( struct V_9 * V_10 ,
struct V_3 * V_11 ,
struct V_12 * V_13 ,
struct V_14 * V_5 )
{
int V_15 = F_8 ( V_10 , & V_11 -> V_16 , & V_17 ) ;
if ( V_15 ) {
F_9 ( L_1 , V_15 ) ;
return V_15 ;
}
F_10 ( & V_11 -> V_16 , V_13 ) ;
V_11 -> V_5 = V_5 ;
return 0 ;
}
static struct V_1 *
F_11 ( struct V_9 * V_10 ,
struct V_6 * V_18 ,
struct V_12 * V_13 )
{
struct V_14 * V_5 ;
struct V_3 * V_4 ;
int V_15 ;
V_5 = F_12 ( V_10 , V_18 , V_13 -> V_19 [ 0 ] ) ;
if ( V_5 == NULL )
return F_13 ( - V_20 ) ;
V_4 = F_14 ( sizeof( * V_4 ) , V_21 ) ;
if ( ! V_4 ) {
F_3 ( V_5 ) ;
return F_13 ( - V_22 ) ;
}
V_15 = F_7 ( V_10 , V_4 , V_13 , V_5 ) ;
if ( V_15 ) {
F_3 ( V_5 ) ;
F_5 ( V_4 ) ;
return F_13 ( V_15 ) ;
}
return & V_4 -> V_16 ;
}
static void F_15 ( struct V_23 * V_24 )
{
F_16 ( V_24 -> V_10 -> V_25 , V_24 -> V_26 ) ;
V_24 -> V_26 = NULL ;
if ( V_24 -> V_27 . V_28 )
F_17 ( V_24 -> V_27 . V_28 , V_24 -> V_27 . V_29 ) ;
}
static int F_18 ( struct V_23 * V_24 , void T_1 * V_30 )
{
int V_31 ;
int V_32 ;
int V_33 , V_34 ;
int V_35 , V_36 ;
V_32 = F_19 ( V_30 ) ;
F_20 ( 0 , V_30 ) ;
for ( V_31 = 0x100000 ; V_31 < V_24 -> V_27 . V_29 ; V_31 += 0x4000 ) {
V_35 = F_21 ( V_30 + V_31 ) ;
V_36 = F_21 ( V_30 + V_31 + 0x100 ) ;
F_20 ( 0xaa55 , V_30 + V_31 ) ;
F_20 ( 0xaa55 , V_30 + V_31 + 0x100 ) ;
V_33 = F_19 ( V_30 + V_31 ) ;
V_34 = F_19 ( V_30 ) ;
F_20 ( V_35 , V_30 + V_31 ) ;
F_20 ( V_36 , V_30 + V_31 + 0x100 ) ;
if ( V_33 != 0xaa55 ) {
break;
}
if ( V_34 ) {
break;
}
}
F_20 ( V_32 , V_30 ) ;
return V_31 - 65536 ;
}
static int F_22 ( struct V_23 * V_24 )
{
void T_1 * V_30 ;
struct V_37 * V_38 = F_23 ( 1 ) ;
if ( ! V_38 )
return - V_22 ;
V_24 -> V_27 . V_28 = F_24 ( V_24 -> V_10 -> V_25 , 0 ) ;
V_24 -> V_27 . V_29 = F_25 ( V_24 -> V_10 -> V_25 , 0 ) ;
V_38 -> V_39 [ 0 ] . V_16 = V_24 -> V_27 . V_28 ;
V_38 -> V_39 [ 0 ] . V_40 = V_24 -> V_27 . V_29 ;
F_26 ( V_38 , L_2 , true ) ;
F_5 ( V_38 ) ;
if ( ! F_27 ( V_24 -> V_27 . V_28 , V_24 -> V_27 . V_29 ,
L_3 ) ) {
F_9 ( L_4 ) ;
return - V_41 ;
}
V_30 = F_28 ( V_24 -> V_10 -> V_25 , 0 , 0 ) ;
V_24 -> V_27 . V_42 = F_18 ( V_24 , V_30 ) ;
F_16 ( V_24 -> V_10 -> V_25 , V_30 ) ;
return 0 ;
}
static int F_29 ( struct V_9 * V_10 ,
T_2 V_43 )
{
struct V_23 * V_24 = V_10 -> V_44 ;
int V_15 , V_45 ;
V_24 -> type = V_43 ;
V_24 -> V_46 = 1 ;
F_30 ( V_10 -> V_25 , V_47 , & V_45 ) ;
V_24 -> V_48 = ! ( V_45 & ( 1 << 14 ) ) ;
V_24 -> V_49 = F_24 ( V_24 -> V_10 -> V_25 , 1 ) ;
V_24 -> V_50 = F_25 ( V_24 -> V_10 -> V_25 , 1 ) ;
if ( ! F_27 ( V_24 -> V_49 , V_24 -> V_50 ,
L_5 ) ) {
F_9 ( L_6 ) ;
return - V_22 ;
}
V_24 -> V_26 = F_28 ( V_10 -> V_25 , 1 , 0 ) ;
if ( V_24 -> V_26 == NULL )
return - V_22 ;
if ( F_31 ( V_24 ) )
V_24 -> V_51 = F_32 ( 0x1e24 ) ;
V_15 = F_22 ( V_24 ) ;
if ( V_15 ) {
F_17 ( V_24 -> V_49 , V_24 -> V_50 ) ;
return V_15 ;
}
V_24 -> V_52 [ 0 ] = 0 ;
V_24 -> V_52 [ 1 ] = 1 ;
V_24 -> V_52 [ 2 ] = 0 ;
V_24 -> V_52 [ 3 ] = 2 ;
return 0 ;
}
void F_33 ( struct V_23 * V_24 )
{
F_17 ( V_24 -> V_49 , V_24 -> V_50 ) ;
F_15 ( V_24 ) ;
}
int F_34 ( struct V_9 * V_10 , unsigned long V_43 )
{
struct V_23 * V_24 ;
int V_53 ;
V_24 = F_14 ( sizeof( struct V_23 ) , V_21 ) ;
if ( V_24 == NULL )
return - V_22 ;
V_10 -> V_44 = ( void * ) V_24 ;
V_24 -> V_10 = V_10 ;
V_53 = F_29 ( V_10 , V_43 ) ;
if ( V_53 ) {
F_35 ( & V_10 -> V_25 -> V_10 , L_7 , V_53 ) ;
goto V_54;
}
V_53 = F_36 ( V_24 ) ;
if ( V_53 )
goto V_54;
F_37 ( V_10 ) ;
V_10 -> V_55 . V_56 = ( void * ) & V_57 ;
V_10 -> V_55 . V_58 = 0 ;
V_10 -> V_55 . V_59 = 0 ;
V_10 -> V_55 . V_60 = 24 ;
V_10 -> V_55 . V_61 = 1 ;
V_53 = F_38 ( V_24 ) ;
if ( V_53 )
F_35 ( & V_10 -> V_25 -> V_10 , L_8 , V_53 ) ;
V_54:
if ( V_53 )
F_39 ( V_10 ) ;
return V_53 ;
}
int F_39 ( struct V_9 * V_10 )
{
struct V_23 * V_24 = V_10 -> V_44 ;
if ( V_24 == NULL )
return 0 ;
F_40 ( V_24 ) ;
F_41 ( V_24 ) ;
F_42 ( V_10 ) ;
F_43 ( V_24 ) ;
F_33 ( V_24 ) ;
F_5 ( V_24 ) ;
V_10 -> V_44 = NULL ;
return 0 ;
}
int F_44 ( struct V_9 * V_10 ,
T_3 V_40 , bool V_62 ,
struct V_14 * * V_5 )
{
struct V_63 * V_64 ;
int V_15 ;
* V_5 = NULL ;
V_40 = F_45 ( V_40 , V_65 ) ;
if ( V_40 == 0 )
return - V_66 ;
V_15 = F_46 ( V_10 , V_40 , 0 , 0 , & V_64 ) ;
if ( V_15 ) {
if ( V_15 != - V_67 )
F_9 ( L_9 ) ;
return V_15 ;
}
* V_5 = & V_64 -> V_68 ;
return 0 ;
}
int F_47 ( struct V_6 * V_69 ,
struct V_9 * V_10 ,
struct V_70 * args )
{
int V_15 ;
struct V_14 * V_71 ;
T_3 V_8 ;
args -> V_72 = args -> V_73 * ( ( args -> V_74 + 7 ) / 8 ) ;
args -> V_40 = args -> V_72 * args -> V_75 ;
V_15 = F_44 ( V_10 , args -> V_40 , false ,
& V_71 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_48 ( V_69 , V_71 , & V_8 ) ;
F_3 ( V_71 ) ;
if ( V_15 )
return V_15 ;
args -> V_8 = V_8 ;
return 0 ;
}
int F_49 ( struct V_6 * V_69 ,
struct V_9 * V_10 ,
T_2 V_8 )
{
return F_50 ( V_69 , V_8 ) ;
}
int F_51 ( struct V_14 * V_5 )
{
F_52 () ;
return 0 ;
}
void F_53 ( struct V_63 * * V_76 )
{
struct V_77 * V_78 ;
if ( ( * V_76 ) == NULL )
return;
V_78 = & ( ( * V_76 ) -> V_76 ) ;
F_54 ( & V_78 ) ;
if ( V_78 == NULL )
* V_76 = NULL ;
}
void F_55 ( struct V_14 * V_5 )
{
struct V_63 * V_63 = F_56 ( V_5 ) ;
if ( ! V_63 )
return;
F_53 ( & V_63 ) ;
}
static inline T_4 F_57 ( struct V_63 * V_76 )
{
return V_76 -> V_76 . V_79 ;
}
int
F_58 ( struct V_6 * V_69 ,
struct V_9 * V_10 ,
T_2 V_8 ,
T_5 * V_31 )
{
struct V_14 * V_5 ;
int V_15 ;
struct V_63 * V_76 ;
F_59 ( & V_10 -> V_80 ) ;
V_5 = F_12 ( V_10 , V_69 , V_8 ) ;
if ( V_5 == NULL ) {
V_15 = - V_20 ;
goto V_81;
}
V_76 = F_56 ( V_5 ) ;
* V_31 = F_57 ( V_76 ) ;
F_60 ( V_5 ) ;
V_15 = 0 ;
V_81:
F_61 ( & V_10 -> V_80 ) ;
return V_15 ;
}
