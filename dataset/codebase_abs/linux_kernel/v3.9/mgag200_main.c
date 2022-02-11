static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 )
F_3 ( V_4 -> V_5 ) ;
F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
}
int F_6 ( struct V_6 * V_7 ,
struct V_3 * V_8 ,
struct V_9 * V_10 ,
struct V_11 * V_5 )
{
int V_12 ;
F_7 ( & V_8 -> V_13 , V_10 ) ;
V_8 -> V_5 = V_5 ;
V_12 = F_8 ( V_7 , & V_8 -> V_13 , & V_14 ) ;
if ( V_12 ) {
F_9 ( L_1 , V_12 ) ;
return V_12 ;
}
return 0 ;
}
static struct V_1 *
F_10 ( struct V_6 * V_7 ,
struct V_15 * V_16 ,
struct V_9 * V_10 )
{
struct V_11 * V_5 ;
struct V_3 * V_4 ;
int V_12 ;
V_5 = F_11 ( V_7 , V_16 , V_10 -> V_17 [ 0 ] ) ;
if ( V_5 == NULL )
return F_12 ( - V_18 ) ;
V_4 = F_13 ( sizeof( * V_4 ) , V_19 ) ;
if ( ! V_4 ) {
F_3 ( V_5 ) ;
return F_12 ( - V_20 ) ;
}
V_12 = F_6 ( V_7 , V_4 , V_10 , V_5 ) ;
if ( V_12 ) {
F_3 ( V_5 ) ;
F_5 ( V_4 ) ;
return F_12 ( V_12 ) ;
}
return & V_4 -> V_13 ;
}
static void F_14 ( struct V_21 * V_22 )
{
F_15 ( V_22 -> V_7 -> V_23 , V_22 -> V_24 ) ;
V_22 -> V_24 = NULL ;
if ( V_22 -> V_25 . V_26 )
F_16 ( V_22 -> V_25 . V_26 , V_22 -> V_25 . V_27 ) ;
}
static int F_17 ( struct V_21 * V_22 , void T_1 * V_28 )
{
int V_29 ;
int V_30 ;
int V_31 , V_32 ;
int V_33 , V_34 ;
V_30 = F_18 ( V_28 ) ;
F_19 ( 0 , V_28 ) ;
for ( V_29 = 0x100000 ; V_29 < V_22 -> V_25 . V_27 ; V_29 += 0x4000 ) {
V_33 = F_20 ( V_28 + V_29 ) ;
V_34 = F_20 ( V_28 + V_29 + 0x100 ) ;
F_19 ( 0xaa55 , V_28 + V_29 ) ;
F_19 ( 0xaa55 , V_28 + V_29 + 0x100 ) ;
V_31 = F_18 ( V_28 + V_29 ) ;
V_32 = F_18 ( V_28 ) ;
F_19 ( V_33 , V_28 + V_29 ) ;
F_19 ( V_34 , V_28 + V_29 + 0x100 ) ;
if ( V_31 != 0xaa55 ) {
break;
}
if ( V_32 ) {
break;
}
}
F_19 ( V_30 , V_28 ) ;
return V_29 - 65536 ;
}
static int F_21 ( struct V_21 * V_22 )
{
void T_1 * V_28 ;
struct V_35 * V_36 = F_22 ( 1 ) ;
if ( ! V_36 )
return - V_20 ;
V_22 -> V_25 . V_26 = F_23 ( V_22 -> V_7 -> V_23 , 0 ) ;
V_22 -> V_25 . V_27 = F_24 ( V_22 -> V_7 -> V_23 , 0 ) ;
V_36 -> V_37 [ 0 ] . V_13 = V_22 -> V_25 . V_26 ;
V_36 -> V_37 [ 0 ] . V_38 = V_22 -> V_25 . V_27 ;
F_25 ( V_36 , L_2 , true ) ;
F_5 ( V_36 ) ;
if ( ! F_26 ( V_22 -> V_25 . V_26 , V_22 -> V_25 . V_27 ,
L_3 ) ) {
F_9 ( L_4 ) ;
return - V_39 ;
}
V_28 = F_27 ( V_22 -> V_7 -> V_23 , 0 , 0 ) ;
V_22 -> V_25 . V_40 = F_17 ( V_22 , V_28 ) ;
F_15 ( V_22 -> V_7 -> V_23 , V_28 ) ;
return 0 ;
}
static int F_28 ( struct V_6 * V_7 ,
T_2 V_41 )
{
struct V_21 * V_22 = V_7 -> V_42 ;
int V_12 , V_43 ;
V_22 -> type = V_41 ;
V_22 -> V_44 = 1 ;
F_29 ( V_7 -> V_23 , V_45 , & V_43 ) ;
V_22 -> V_46 = ! ( V_43 & ( 1 << 14 ) ) ;
V_22 -> V_47 = F_23 ( V_22 -> V_7 -> V_23 , 1 ) ;
V_22 -> V_48 = F_24 ( V_22 -> V_7 -> V_23 , 1 ) ;
if ( ! F_26 ( V_22 -> V_47 , V_22 -> V_48 ,
L_5 ) ) {
F_9 ( L_6 ) ;
return - V_20 ;
}
V_22 -> V_24 = F_27 ( V_7 -> V_23 , 1 , 0 ) ;
if ( V_22 -> V_24 == NULL )
return - V_20 ;
if ( F_30 ( V_22 ) )
V_22 -> V_49 = F_31 ( 0x1e24 ) ;
V_12 = F_21 ( V_22 ) ;
if ( V_12 ) {
F_16 ( V_22 -> V_47 , V_22 -> V_48 ) ;
return V_12 ;
}
V_22 -> V_50 [ 0 ] = 0 ;
V_22 -> V_50 [ 1 ] = 1 ;
V_22 -> V_50 [ 2 ] = 0 ;
V_22 -> V_50 [ 3 ] = 2 ;
return 0 ;
}
void F_32 ( struct V_21 * V_22 )
{
F_16 ( V_22 -> V_47 , V_22 -> V_48 ) ;
F_14 ( V_22 ) ;
}
int F_33 ( struct V_6 * V_7 , unsigned long V_41 )
{
struct V_21 * V_22 ;
int V_51 ;
V_22 = F_13 ( sizeof( struct V_21 ) , V_19 ) ;
if ( V_22 == NULL )
return - V_20 ;
V_7 -> V_42 = ( void * ) V_22 ;
V_22 -> V_7 = V_7 ;
V_51 = F_28 ( V_7 , V_41 ) ;
if ( V_51 ) {
F_34 ( & V_7 -> V_23 -> V_7 , L_7 , V_51 ) ;
goto V_52;
}
V_51 = F_35 ( V_22 ) ;
if ( V_51 )
goto V_52;
F_36 ( V_7 ) ;
V_7 -> V_53 . V_54 = ( void * ) & V_55 ;
V_7 -> V_53 . V_56 = 0 ;
V_7 -> V_53 . V_57 = 0 ;
V_7 -> V_53 . V_58 = 24 ;
V_7 -> V_53 . V_59 = 1 ;
V_51 = F_37 ( V_22 ) ;
if ( V_51 )
F_34 ( & V_7 -> V_23 -> V_7 , L_8 , V_51 ) ;
V_52:
if ( V_51 )
F_38 ( V_7 ) ;
return V_51 ;
}
int F_38 ( struct V_6 * V_7 )
{
struct V_21 * V_22 = V_7 -> V_42 ;
if ( V_22 == NULL )
return 0 ;
F_39 ( V_22 ) ;
F_40 ( V_22 ) ;
F_41 ( V_7 ) ;
F_42 ( V_22 ) ;
F_32 ( V_22 ) ;
F_5 ( V_22 ) ;
V_7 -> V_42 = NULL ;
return 0 ;
}
int F_43 ( struct V_6 * V_7 ,
T_3 V_38 , bool V_60 ,
struct V_11 * * V_5 )
{
struct V_61 * V_62 ;
int V_12 ;
* V_5 = NULL ;
V_38 = F_44 ( V_38 , V_63 ) ;
if ( V_38 == 0 )
return - V_64 ;
V_12 = F_45 ( V_7 , V_38 , 0 , 0 , & V_62 ) ;
if ( V_12 ) {
if ( V_12 != - V_65 )
F_9 ( L_9 ) ;
return V_12 ;
}
* V_5 = & V_62 -> V_66 ;
return 0 ;
}
int F_46 ( struct V_15 * V_67 ,
struct V_6 * V_7 ,
struct V_68 * args )
{
int V_12 ;
struct V_11 * V_69 ;
T_3 V_70 ;
args -> V_71 = args -> V_72 * ( ( args -> V_73 + 7 ) / 8 ) ;
args -> V_38 = args -> V_71 * args -> V_74 ;
V_12 = F_43 ( V_7 , args -> V_38 , false ,
& V_69 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_47 ( V_67 , V_69 , & V_70 ) ;
F_3 ( V_69 ) ;
if ( V_12 )
return V_12 ;
args -> V_70 = V_70 ;
return 0 ;
}
int F_48 ( struct V_15 * V_67 ,
struct V_6 * V_7 ,
T_2 V_70 )
{
return F_49 ( V_67 , V_70 ) ;
}
int F_50 ( struct V_11 * V_5 )
{
F_51 () ;
return 0 ;
}
void F_52 ( struct V_61 * * V_75 )
{
struct V_76 * V_77 ;
if ( ( * V_75 ) == NULL )
return;
V_77 = & ( ( * V_75 ) -> V_75 ) ;
F_53 ( & V_77 ) ;
if ( V_77 == NULL )
* V_75 = NULL ;
}
void F_54 ( struct V_11 * V_5 )
{
struct V_61 * V_61 = F_55 ( V_5 ) ;
if ( ! V_61 )
return;
F_52 ( & V_61 ) ;
}
static inline T_4 F_56 ( struct V_61 * V_75 )
{
return V_75 -> V_75 . V_78 ;
}
int
F_57 ( struct V_15 * V_67 ,
struct V_6 * V_7 ,
T_2 V_70 ,
T_5 * V_29 )
{
struct V_11 * V_5 ;
int V_12 ;
struct V_61 * V_75 ;
F_58 ( & V_7 -> V_79 ) ;
V_5 = F_11 ( V_7 , V_67 , V_70 ) ;
if ( V_5 == NULL ) {
V_12 = - V_18 ;
goto V_80;
}
V_75 = F_55 ( V_5 ) ;
* V_29 = F_56 ( V_75 ) ;
F_59 ( V_5 ) ;
V_12 = 0 ;
V_80:
F_60 ( & V_7 -> V_79 ) ;
return V_12 ;
}
