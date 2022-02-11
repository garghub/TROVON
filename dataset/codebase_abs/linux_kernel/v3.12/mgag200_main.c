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
return V_51 ;
}
V_51 = F_34 ( V_22 ) ;
if ( V_51 )
goto V_52;
F_35 ( V_7 ) ;
V_7 -> V_53 . V_54 = ( void * ) & V_55 ;
V_7 -> V_53 . V_56 = 24 ;
V_7 -> V_53 . V_57 = 1 ;
V_51 = F_36 ( V_22 ) ;
if ( V_51 ) {
F_33 ( & V_7 -> V_35 -> V_7 , L_8 , V_51 ) ;
goto V_52;
}
F_37 ( V_7 , F_38 ( 48 * 64 , V_58 ) , 0 , 0 ,
& V_22 -> V_59 . V_60 ) ;
F_37 ( V_7 , F_38 ( 48 * 64 , V_58 ) , 0 , 0 ,
& V_22 -> V_59 . V_61 ) ;
if ( ! V_22 -> V_59 . V_61 || ! V_22 -> V_59 . V_60 )
goto V_62;
V_22 -> V_59 . V_63 = V_22 -> V_59 . V_60 ;
V_22 -> V_59 . V_64 = V_22 -> V_59 . V_61 ;
goto V_65;
V_62:
V_22 -> V_59 . V_60 = NULL ;
V_22 -> V_59 . V_61 = NULL ;
F_39 ( & V_7 -> V_35 -> V_7 , L_9 ) ;
V_65:
V_52:
if ( V_51 )
F_40 ( V_7 ) ;
return V_51 ;
}
int F_40 ( struct V_6 * V_7 )
{
struct V_21 * V_22 = V_7 -> V_41 ;
if ( V_22 == NULL )
return 0 ;
F_41 ( V_22 ) ;
F_42 ( V_22 ) ;
F_43 ( V_7 ) ;
F_44 ( V_22 ) ;
V_7 -> V_41 = NULL ;
return 0 ;
}
int F_45 ( struct V_6 * V_7 ,
T_3 V_37 , bool V_66 ,
struct V_11 * * V_5 )
{
struct V_67 * V_68 ;
int V_12 ;
* V_5 = NULL ;
V_37 = F_38 ( V_37 , V_58 ) ;
if ( V_37 == 0 )
return - V_69 ;
V_12 = F_37 ( V_7 , V_37 , 0 , 0 , & V_68 ) ;
if ( V_12 ) {
if ( V_12 != - V_70 )
F_9 ( L_10 ) ;
return V_12 ;
}
* V_5 = & V_68 -> V_71 ;
return 0 ;
}
int F_46 ( struct V_15 * V_72 ,
struct V_6 * V_7 ,
struct V_73 * args )
{
int V_12 ;
struct V_11 * V_74 ;
T_3 V_75 ;
args -> V_76 = args -> V_77 * ( ( args -> V_78 + 7 ) / 8 ) ;
args -> V_37 = args -> V_76 * args -> V_79 ;
V_12 = F_45 ( V_7 , args -> V_37 , false ,
& V_74 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_47 ( V_72 , V_74 , & V_75 ) ;
F_3 ( V_74 ) ;
if ( V_12 )
return V_12 ;
args -> V_75 = V_75 ;
return 0 ;
}
int F_48 ( struct V_11 * V_5 )
{
F_49 () ;
return 0 ;
}
void F_50 ( struct V_67 * * V_80 )
{
struct V_81 * V_82 ;
if ( ( * V_80 ) == NULL )
return;
V_82 = & ( ( * V_80 ) -> V_80 ) ;
F_51 ( & V_82 ) ;
if ( V_82 == NULL )
* V_80 = NULL ;
}
void F_52 ( struct V_11 * V_5 )
{
struct V_67 * V_67 = F_53 ( V_5 ) ;
if ( ! V_67 )
return;
F_50 ( & V_67 ) ;
}
static inline T_4 F_54 ( struct V_67 * V_80 )
{
return F_55 ( & V_80 -> V_80 . V_83 ) ;
}
int
F_56 ( struct V_15 * V_72 ,
struct V_6 * V_7 ,
T_2 V_75 ,
T_5 * V_24 )
{
struct V_11 * V_5 ;
int V_12 ;
struct V_67 * V_80 ;
F_57 ( & V_7 -> V_84 ) ;
V_5 = F_11 ( V_7 , V_72 , V_75 ) ;
if ( V_5 == NULL ) {
V_12 = - V_18 ;
goto V_85;
}
V_80 = F_53 ( V_5 ) ;
* V_24 = F_54 ( V_80 ) ;
F_58 ( V_5 ) ;
V_12 = 0 ;
V_85:
F_59 ( & V_7 -> V_84 ) ;
return V_12 ;
}
