static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( 0 , V_4 -> V_5 + V_6 ) ;
return F_4 ( V_4 -> V_5 + V_7 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_8 ;
F_6 ( V_2 ) ;
for ( V_8 = 0 ; V_8 < F_7 ( V_2 -> V_9 ) ; V_8 ++ ) {
F_3 ( V_8 , V_4 -> V_5 + V_10 ) ;
F_3 ( V_2 -> V_9 [ V_8 ] ,
V_4 -> V_5 + V_11 ) ;
}
}
static void F_8 ( struct V_1 * V_2 , unsigned V_12 ,
void * V_13 , unsigned V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 * V_15 = V_13 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_14 ; V_8 ++ )
V_15 [ V_8 ] = F_9 ( V_4 -> V_5 + V_16 + V_12 + V_8 ) ;
}
static void F_10 ( struct V_1 * V_2 , unsigned V_12 ,
const void * V_13 , unsigned V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const T_2 * V_15 = V_13 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_14 ; V_8 ++ )
F_11 ( V_15 [ V_8 ] , V_4 -> V_5 + V_16 + V_12 + V_8 ) ;
}
static T_2 F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_4 ( V_4 -> V_5 + V_17 ) & 0xff ;
}
static void F_13 ( struct V_1 * V_2 , T_2 V_18 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_14 ( V_18 == 0 ) ;
F_3 ( V_18 , V_4 -> V_5 + V_17 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( 0 , V_4 -> V_5 + V_17 ) ;
}
static void F_16 ( struct V_19 * V_20 )
{
struct V_3 * V_4 = F_2 ( V_20 -> V_2 ) ;
struct V_21 * V_22 = V_20 -> V_23 ;
F_3 ( V_22 -> V_24 , V_4 -> V_5 + V_25 ) ;
}
static T_3 F_17 ( int V_26 , void * V_27 )
{
struct V_3 * V_4 = V_27 ;
struct V_21 * V_22 ;
struct V_28 * V_29 = F_18 ( V_4 -> V_2 . V_30 . V_31 ,
struct V_28 , V_31 ) ;
unsigned long V_18 ;
unsigned long V_32 ;
T_3 V_33 = V_34 ;
V_18 = F_4 ( V_4 -> V_5 + V_35 ) ;
F_3 ( V_18 , V_4 -> V_5 + V_36 ) ;
if ( F_19 ( V_18 & V_37 )
&& V_29 && V_29 -> V_38 ) {
V_29 -> V_38 ( & V_4 -> V_2 ) ;
V_33 = V_39 ;
}
if ( F_20 ( V_18 & V_40 ) ) {
F_21 ( & V_4 -> V_41 , V_32 ) ;
F_22 (info, &vm_dev->virtqueues, node)
V_33 |= F_23 ( V_26 , V_22 -> V_20 ) ;
F_24 ( & V_4 -> V_41 , V_32 ) ;
}
return V_33 ;
}
static void F_25 ( struct V_19 * V_20 )
{
struct V_3 * V_4 = F_2 ( V_20 -> V_2 ) ;
struct V_21 * V_22 = V_20 -> V_23 ;
unsigned long V_32 , V_42 ;
F_21 ( & V_4 -> V_41 , V_32 ) ;
F_26 ( & V_22 -> V_43 ) ;
F_24 ( & V_4 -> V_41 , V_32 ) ;
F_27 ( V_20 ) ;
F_3 ( V_22 -> V_24 , V_4 -> V_5 + V_44 ) ;
F_3 ( 0 , V_4 -> V_5 + V_45 ) ;
V_42 = F_28 ( F_29 ( V_22 -> V_46 , V_47 ) ) ;
F_30 ( V_22 -> V_48 , V_42 ) ;
F_31 ( V_22 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_19 * V_20 , * V_49 ;
F_33 (vq, n, &vdev->vqs, list)
F_25 ( V_20 ) ;
F_34 ( F_35 ( V_4 -> V_50 , 0 ) , V_4 ) ;
}
static struct V_19 * F_36 ( struct V_1 * V_2 , unsigned V_51 ,
void (* F_37)( struct V_19 * V_20 ) ,
const char * V_52 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_21 * V_22 ;
struct V_19 * V_20 ;
unsigned long V_32 , V_42 ;
int V_53 ;
F_3 ( V_51 , V_4 -> V_5 + V_44 ) ;
if ( F_4 ( V_4 -> V_5 + V_45 ) ) {
V_53 = - V_54 ;
goto V_55;
}
V_22 = F_38 ( sizeof( * V_22 ) , V_56 ) ;
if ( ! V_22 ) {
V_53 = - V_57 ;
goto V_58;
}
V_22 -> V_24 = V_51 ;
V_22 -> V_46 = F_4 ( V_4 -> V_5 + V_59 ) ;
while ( 1 ) {
V_42 = F_28 ( F_29 ( V_22 -> V_46 ,
V_47 ) ) ;
if ( V_42 <= V_47 * 2 ) {
V_53 = - V_57 ;
goto V_60;
}
V_22 -> V_48 = F_39 ( V_42 , V_56 | V_61 ) ;
if ( V_22 -> V_48 )
break;
V_22 -> V_46 /= 2 ;
}
F_3 ( V_22 -> V_46 , V_4 -> V_5 + V_62 ) ;
F_3 ( V_47 ,
V_4 -> V_5 + V_63 ) ;
F_3 ( F_40 ( V_22 -> V_48 ) >> V_64 ,
V_4 -> V_5 + V_45 ) ;
V_20 = F_41 ( V_22 -> V_46 , V_47 ,
V_2 , V_22 -> V_48 , F_16 , F_37 , V_52 ) ;
if ( ! V_20 ) {
V_53 = - V_57 ;
goto V_65;
}
V_20 -> V_23 = V_22 ;
V_22 -> V_20 = V_20 ;
F_21 ( & V_4 -> V_41 , V_32 ) ;
F_42 ( & V_22 -> V_43 , & V_4 -> V_66 ) ;
F_24 ( & V_4 -> V_41 , V_32 ) ;
return V_20 ;
V_65:
F_3 ( 0 , V_4 -> V_5 + V_45 ) ;
F_30 ( V_22 -> V_48 , V_42 ) ;
V_60:
F_31 ( V_22 ) ;
V_58:
V_55:
return F_43 ( V_53 ) ;
}
static int F_44 ( struct V_1 * V_2 , unsigned V_67 ,
struct V_19 * V_68 [] ,
T_4 * V_69 [] ,
const char * V_70 [] )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_26 = F_35 ( V_4 -> V_50 , 0 ) ;
int V_8 , V_53 ;
V_53 = F_45 ( V_26 , F_17 , V_71 ,
F_46 ( & V_2 -> V_30 ) , V_4 ) ;
if ( V_53 )
return V_53 ;
for ( V_8 = 0 ; V_8 < V_67 ; ++ V_8 ) {
V_68 [ V_8 ] = F_36 ( V_2 , V_8 , V_69 [ V_8 ] , V_70 [ V_8 ] ) ;
if ( F_47 ( V_68 [ V_8 ] ) ) {
F_32 ( V_2 ) ;
return F_48 ( V_68 [ V_8 ] ) ;
}
}
return 0 ;
}
static int T_5 F_49 ( struct V_72 * V_50 )
{
struct V_3 * V_4 ;
struct V_73 * V_74 ;
unsigned long V_75 ;
V_74 = F_50 ( V_50 , V_76 , 0 ) ;
if ( ! V_74 )
return - V_77 ;
if ( ! F_51 ( & V_50 -> V_30 , V_74 -> V_78 ,
F_52 ( V_74 ) , V_50 -> V_52 ) )
return - V_79 ;
V_4 = F_53 ( & V_50 -> V_30 , sizeof( * V_4 ) , V_56 ) ;
if ( ! V_4 )
return - V_57 ;
V_4 -> V_2 . V_30 . V_80 = & V_50 -> V_30 ;
V_4 -> V_2 . V_81 = & V_82 ;
V_4 -> V_50 = V_50 ;
F_54 ( & V_4 -> V_66 ) ;
F_55 ( & V_4 -> V_41 ) ;
V_4 -> V_5 = F_56 ( & V_50 -> V_30 , V_74 -> V_78 , F_52 ( V_74 ) ) ;
if ( V_4 -> V_5 == NULL )
return - V_83 ;
V_75 = F_4 ( V_4 -> V_5 + V_84 ) ;
if ( memcmp ( & V_75 , L_1 , 4 ) != 0 ) {
F_57 ( & V_50 -> V_30 , L_2 , V_75 ) ;
return - V_85 ;
}
V_4 -> V_86 = F_4 ( V_4 -> V_5 + V_87 ) ;
if ( V_4 -> V_86 != 1 ) {
F_58 ( & V_50 -> V_30 , L_3 ,
V_4 -> V_86 ) ;
return - V_88 ;
}
V_4 -> V_2 . V_89 . V_90 = F_4 ( V_4 -> V_5 + V_91 ) ;
V_4 -> V_2 . V_89 . V_92 = F_4 ( V_4 -> V_5 + V_93 ) ;
F_3 ( V_94 , V_4 -> V_5 + V_95 ) ;
F_59 ( V_50 , V_4 ) ;
return F_60 ( & V_4 -> V_2 ) ;
}
static int T_6 F_61 ( struct V_72 * V_50 )
{
struct V_3 * V_4 = F_62 ( V_50 ) ;
F_63 ( & V_4 -> V_2 ) ;
return 0 ;
}
static int T_7 F_64 ( void )
{
return F_65 ( & V_96 ) ;
}
static void T_8 F_66 ( void )
{
F_67 ( & V_96 ) ;
}
