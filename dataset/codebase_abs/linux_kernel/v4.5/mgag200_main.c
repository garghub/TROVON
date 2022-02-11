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
const struct V_9 * V_10 ,
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
const struct V_9 * V_10 )
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
unsigned int V_30 ;
V_25 = F_15 ( V_23 ) ;
F_16 ( 0 , V_23 ) ;
V_30 = V_22 -> V_31 . V_32 ;
if ( ( V_22 -> type == V_33 ) && ( V_30 >= 0x1000000 ) ) {
V_30 = V_30 - 0x400000 ;
}
for ( V_24 = 0x100000 ; V_24 < V_30 ; V_24 += 0x4000 ) {
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
struct V_34 * V_35 = F_19 ( 1 ) ;
if ( ! V_35 )
return - V_20 ;
V_22 -> V_31 . V_36 = F_20 ( V_22 -> V_7 -> V_37 , 0 ) ;
V_22 -> V_31 . V_32 = F_21 ( V_22 -> V_7 -> V_37 , 0 ) ;
V_35 -> V_38 [ 0 ] . V_13 = V_22 -> V_31 . V_36 ;
V_35 -> V_38 [ 0 ] . V_39 = V_22 -> V_31 . V_32 ;
F_22 ( V_35 , L_2 , true ) ;
F_5 ( V_35 ) ;
if ( ! F_23 ( V_22 -> V_7 -> V_7 , V_22 -> V_31 . V_36 , V_22 -> V_31 . V_32 ,
L_3 ) ) {
F_9 ( L_4 ) ;
return - V_40 ;
}
V_23 = F_24 ( V_22 -> V_7 -> V_37 , 0 , 0 ) ;
V_22 -> V_31 . V_30 = F_14 ( V_22 , V_23 ) ;
F_25 ( V_22 -> V_7 -> V_37 , V_23 ) ;
return 0 ;
}
static int F_26 ( struct V_6 * V_7 ,
T_2 V_41 )
{
struct V_21 * V_22 = V_7 -> V_42 ;
int V_12 , V_43 ;
V_22 -> type = V_41 ;
V_22 -> V_44 = 1 ;
F_27 ( V_7 -> V_37 , V_45 , & V_43 ) ;
V_22 -> V_46 = ! ( V_43 & ( 1 << 14 ) ) ;
V_22 -> V_47 = F_20 ( V_22 -> V_7 -> V_37 , 1 ) ;
V_22 -> V_48 = F_21 ( V_22 -> V_7 -> V_37 , 1 ) ;
if ( ! F_23 ( V_22 -> V_7 -> V_7 , V_22 -> V_47 , V_22 -> V_48 ,
L_5 ) ) {
F_9 ( L_6 ) ;
return - V_20 ;
}
V_22 -> V_49 = F_28 ( V_7 -> V_37 , 1 , 0 ) ;
if ( V_22 -> V_49 == NULL )
return - V_20 ;
if ( F_29 ( V_22 ) )
V_22 -> V_50 = F_30 ( 0x1e24 ) ;
V_12 = F_18 ( V_22 ) ;
if ( V_12 )
return V_12 ;
V_22 -> V_51 [ 0 ] = 0 ;
V_22 -> V_51 [ 1 ] = 1 ;
V_22 -> V_51 [ 2 ] = 0 ;
V_22 -> V_51 [ 3 ] = 2 ;
return 0 ;
}
int F_31 ( struct V_6 * V_7 , unsigned long V_41 )
{
struct V_21 * V_22 ;
int V_52 ;
V_22 = F_32 ( V_7 -> V_7 , sizeof( struct V_21 ) , V_19 ) ;
if ( V_22 == NULL )
return - V_20 ;
V_7 -> V_42 = ( void * ) V_22 ;
V_22 -> V_7 = V_7 ;
V_52 = F_26 ( V_7 , V_41 ) ;
if ( V_52 ) {
F_33 ( & V_7 -> V_37 -> V_7 , L_7 , V_52 ) ;
return V_52 ;
}
V_52 = F_34 ( V_22 ) ;
if ( V_52 )
goto V_53;
F_35 ( V_7 ) ;
V_7 -> V_54 . V_55 = ( void * ) & V_56 ;
if ( F_29 ( V_22 ) && V_22 -> V_31 . V_30 < ( 2048 * 1024 ) )
V_7 -> V_54 . V_57 = 16 ;
else
V_7 -> V_54 . V_57 = 24 ;
V_7 -> V_54 . V_58 = 1 ;
V_52 = F_36 ( V_22 ) ;
if ( V_52 ) {
F_33 ( & V_7 -> V_37 -> V_7 , L_8 , V_52 ) ;
goto V_59;
}
F_37 ( V_7 , F_38 ( 48 * 64 , V_60 ) , 0 , 0 ,
& V_22 -> V_61 . V_62 ) ;
F_37 ( V_7 , F_38 ( 48 * 64 , V_60 ) , 0 , 0 ,
& V_22 -> V_61 . V_63 ) ;
if ( ! V_22 -> V_61 . V_63 || ! V_22 -> V_61 . V_62 ) {
V_22 -> V_61 . V_62 = NULL ;
V_22 -> V_61 . V_63 = NULL ;
F_39 ( & V_7 -> V_37 -> V_7 ,
L_9 ) ;
} else {
V_22 -> V_61 . V_64 = V_22 -> V_61 . V_62 ;
V_22 -> V_61 . V_65 = V_22 -> V_61 . V_63 ;
}
return 0 ;
V_59:
F_40 ( V_7 ) ;
F_41 ( V_22 ) ;
V_53:
V_7 -> V_42 = NULL ;
return V_52 ;
}
int F_42 ( struct V_6 * V_7 )
{
struct V_21 * V_22 = V_7 -> V_42 ;
if ( V_22 == NULL )
return 0 ;
F_43 ( V_22 ) ;
F_44 ( V_22 ) ;
F_40 ( V_7 ) ;
F_41 ( V_22 ) ;
V_7 -> V_42 = NULL ;
return 0 ;
}
int F_45 ( struct V_6 * V_7 ,
T_3 V_39 , bool V_66 ,
struct V_11 * * V_5 )
{
struct V_67 * V_68 ;
int V_12 ;
* V_5 = NULL ;
V_39 = F_38 ( V_39 , V_60 ) ;
if ( V_39 == 0 )
return - V_69 ;
V_12 = F_37 ( V_7 , V_39 , 0 , 0 , & V_68 ) ;
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
args -> V_39 = args -> V_76 * args -> V_79 ;
V_12 = F_45 ( V_7 , args -> V_39 , false ,
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
static void F_48 ( struct V_67 * * V_80 )
{
struct V_81 * V_82 ;
if ( ( * V_80 ) == NULL )
return;
V_82 = & ( ( * V_80 ) -> V_80 ) ;
F_49 ( & V_82 ) ;
* V_80 = NULL ;
}
void F_50 ( struct V_11 * V_5 )
{
struct V_67 * V_67 = F_51 ( V_5 ) ;
F_48 ( & V_67 ) ;
}
static inline T_4 F_52 ( struct V_67 * V_80 )
{
return F_53 ( & V_80 -> V_80 . V_83 ) ;
}
int
F_54 ( struct V_15 * V_72 ,
struct V_6 * V_7 ,
T_2 V_75 ,
T_5 * V_24 )
{
struct V_11 * V_5 ;
struct V_67 * V_80 ;
V_5 = F_11 ( V_7 , V_72 , V_75 ) ;
if ( V_5 == NULL )
return - V_18 ;
V_80 = F_51 ( V_5 ) ;
* V_24 = F_52 ( V_80 ) ;
F_3 ( V_5 ) ;
return 0 ;
}
