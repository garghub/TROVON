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
static int F_14 ( struct V_21 * V_22 , void T_1 * V_23 )
{
int V_24 ;
int V_25 ;
int V_26 , V_27 ;
int V_28 , V_29 ;
V_25 = F_15 ( V_23 ) ;
F_16 ( 0 , V_23 ) ;
for ( V_24 = 0x100000 ; V_24 < V_22 -> V_30 . V_31 ; V_24 += 0x4000 ) {
V_28 = F_17 ( V_23 + V_24 ) ;
V_29 = F_17 ( V_23 + V_24 + 0x100 ) ;
F_16 ( 0xaa55 , V_23 + V_24 ) ;
F_16 ( 0xaa55 , V_23 + V_24 + 0x100 ) ;
V_26 = F_15 ( V_23 + V_24 ) ;
V_27 = F_15 ( V_23 ) ;
F_16 ( V_28 , V_23 + V_24 ) ;
F_16 ( V_29 , V_23 + V_24 + 0x100 ) ;
if ( V_26 != 0xaa55 ) {
break;
}
if ( V_27 ) {
break;
}
}
F_16 ( V_25 , V_23 ) ;
return V_24 - 65536 ;
}
static int F_18 ( struct V_21 * V_22 )
{
void T_1 * V_23 ;
struct V_32 * V_33 = F_19 ( 1 ) ;
if ( ! V_33 )
return - V_20 ;
V_22 -> V_30 . V_34 = F_20 ( V_22 -> V_7 -> V_35 , 0 ) ;
V_22 -> V_30 . V_31 = F_21 ( V_22 -> V_7 -> V_35 , 0 ) ;
V_33 -> V_36 [ 0 ] . V_13 = V_22 -> V_30 . V_34 ;
V_33 -> V_36 [ 0 ] . V_37 = V_22 -> V_30 . V_31 ;
F_22 ( V_33 , L_2 , true ) ;
F_5 ( V_33 ) ;
if ( ! F_23 ( V_22 -> V_7 -> V_7 , V_22 -> V_30 . V_34 , V_22 -> V_30 . V_31 ,
L_3 ) ) {
F_9 ( L_4 ) ;
return - V_38 ;
}
V_23 = F_24 ( V_22 -> V_7 -> V_35 , 0 , 0 ) ;
V_22 -> V_30 . V_39 = F_14 ( V_22 , V_23 ) ;
F_25 ( V_22 -> V_7 -> V_35 , V_23 ) ;
return 0 ;
}
static int F_26 ( struct V_6 * V_7 ,
T_2 V_40 )
{
struct V_21 * V_22 = V_7 -> V_41 ;
int V_12 , V_42 ;
V_22 -> type = V_40 ;
V_22 -> V_43 = 1 ;
F_27 ( V_7 -> V_35 , V_44 , & V_42 ) ;
V_22 -> V_45 = ! ( V_42 & ( 1 << 14 ) ) ;
V_22 -> V_46 = F_20 ( V_22 -> V_7 -> V_35 , 1 ) ;
V_22 -> V_47 = F_21 ( V_22 -> V_7 -> V_35 , 1 ) ;
if ( ! F_23 ( V_22 -> V_7 -> V_7 , V_22 -> V_46 , V_22 -> V_47 ,
L_5 ) ) {
F_9 ( L_6 ) ;
return - V_20 ;
}
V_22 -> V_48 = F_28 ( V_7 -> V_35 , 1 , 0 ) ;
if ( V_22 -> V_48 == NULL )
return - V_20 ;
if ( F_29 ( V_22 ) )
V_22 -> V_49 = F_30 ( 0x1e24 ) ;
V_12 = F_18 ( V_22 ) ;
if ( V_12 )
return V_12 ;
V_22 -> V_50 [ 0 ] = 0 ;
V_22 -> V_50 [ 1 ] = 1 ;
V_22 -> V_50 [ 2 ] = 0 ;
V_22 -> V_50 [ 3 ] = 2 ;
return 0 ;
}
int F_31 ( struct V_6 * V_7 , unsigned long V_40 )
{
struct V_21 * V_22 ;
int V_51 ;
V_22 = F_32 ( V_7 -> V_7 , sizeof( struct V_21 ) , V_19 ) ;
if ( V_22 == NULL )
return - V_20 ;
V_7 -> V_41 = ( void * ) V_22 ;
V_22 -> V_7 = V_7 ;
V_51 = F_26 ( V_7 , V_40 ) ;
if ( V_51 ) {
F_33 ( & V_7 -> V_35 -> V_7 , L_7 , V_51 ) ;
goto V_52;
}
V_51 = F_34 ( V_22 ) ;
if ( V_51 )
goto V_52;
F_35 ( V_7 ) ;
V_7 -> V_53 . V_54 = ( void * ) & V_55 ;
V_7 -> V_53 . V_56 = 24 ;
V_7 -> V_53 . V_57 = 1 ;
V_51 = F_36 ( V_22 ) ;
if ( V_51 )
F_33 ( & V_7 -> V_35 -> V_7 , L_8 , V_51 ) ;
V_52:
if ( V_51 )
F_37 ( V_7 ) ;
return V_51 ;
}
int F_37 ( struct V_6 * V_7 )
{
struct V_21 * V_22 = V_7 -> V_41 ;
if ( V_22 == NULL )
return 0 ;
F_38 ( V_22 ) ;
F_39 ( V_22 ) ;
F_40 ( V_7 ) ;
F_41 ( V_22 ) ;
V_7 -> V_41 = NULL ;
return 0 ;
}
int F_42 ( struct V_6 * V_7 ,
T_3 V_37 , bool V_58 ,
struct V_11 * * V_5 )
{
struct V_59 * V_60 ;
int V_12 ;
* V_5 = NULL ;
V_37 = F_43 ( V_37 , V_61 ) ;
if ( V_37 == 0 )
return - V_62 ;
V_12 = F_44 ( V_7 , V_37 , 0 , 0 , & V_60 ) ;
if ( V_12 ) {
if ( V_12 != - V_63 )
F_9 ( L_9 ) ;
return V_12 ;
}
* V_5 = & V_60 -> V_64 ;
return 0 ;
}
int F_45 ( struct V_15 * V_65 ,
struct V_6 * V_7 ,
struct V_66 * args )
{
int V_12 ;
struct V_11 * V_67 ;
T_3 V_68 ;
args -> V_69 = args -> V_70 * ( ( args -> V_71 + 7 ) / 8 ) ;
args -> V_37 = args -> V_69 * args -> V_72 ;
V_12 = F_42 ( V_7 , args -> V_37 , false ,
& V_67 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_46 ( V_65 , V_67 , & V_68 ) ;
F_3 ( V_67 ) ;
if ( V_12 )
return V_12 ;
args -> V_68 = V_68 ;
return 0 ;
}
int F_47 ( struct V_15 * V_65 ,
struct V_6 * V_7 ,
T_2 V_68 )
{
return F_48 ( V_65 , V_68 ) ;
}
int F_49 ( struct V_11 * V_5 )
{
F_50 () ;
return 0 ;
}
void F_51 ( struct V_59 * * V_73 )
{
struct V_74 * V_75 ;
if ( ( * V_73 ) == NULL )
return;
V_75 = & ( ( * V_73 ) -> V_73 ) ;
F_52 ( & V_75 ) ;
if ( V_75 == NULL )
* V_73 = NULL ;
}
void F_53 ( struct V_11 * V_5 )
{
struct V_59 * V_59 = F_54 ( V_5 ) ;
if ( ! V_59 )
return;
F_51 ( & V_59 ) ;
}
static inline T_4 F_55 ( struct V_59 * V_73 )
{
return V_73 -> V_73 . V_76 ;
}
int
F_56 ( struct V_15 * V_65 ,
struct V_6 * V_7 ,
T_2 V_68 ,
T_5 * V_24 )
{
struct V_11 * V_5 ;
int V_12 ;
struct V_59 * V_73 ;
F_57 ( & V_7 -> V_77 ) ;
V_5 = F_11 ( V_7 , V_65 , V_68 ) ;
if ( V_5 == NULL ) {
V_12 = - V_18 ;
goto V_78;
}
V_73 = F_54 ( V_5 ) ;
* V_24 = F_55 ( V_73 ) ;
F_58 ( V_5 ) ;
V_12 = 0 ;
V_78:
F_59 ( & V_7 -> V_77 ) ;
return V_12 ;
}
