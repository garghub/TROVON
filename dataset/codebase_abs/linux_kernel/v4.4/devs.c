void T_1 F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , sizeof( struct V_1 ) ,
& V_3 ) ;
}
void T_1 F_3 ( struct V_4 * V_2 )
{
F_2 ( V_2 , sizeof( struct V_4 ) ,
& V_5 ) ;
}
void F_4 ( struct V_6 * V_2 )
{
F_5 ( V_2 , & V_7 ) ;
}
void F_6 ( struct V_6 * V_2 )
{
F_5 ( V_2 , & V_8 ) ;
}
void F_7 ( struct V_6 * V_2 )
{
F_5 ( V_2 , & V_9 ) ;
}
void F_8 ( struct V_6 * V_2 )
{
F_5 ( V_2 , & V_10 ) ;
}
void T_1 F_9 ( struct V_11 * V_2 )
{
struct V_11 * V_12 ;
if ( ! V_2 ) {
V_2 = & V_13 ;
V_2 -> V_14 = 0 ;
}
V_12 = F_2 ( V_2 , sizeof( struct V_11 ) ,
& V_15 ) ;
if ( ! V_12 -> V_16 )
V_12 -> V_16 = V_17 ;
}
void T_1 F_10 ( struct V_11 * V_2 )
{
struct V_11 * V_12 ;
if ( ! V_2 ) {
V_2 = & V_13 ;
V_2 -> V_14 = 1 ;
}
V_12 = F_2 ( V_2 , sizeof( struct V_11 ) ,
& V_18 ) ;
if ( ! V_12 -> V_16 )
V_12 -> V_16 = V_19 ;
}
void T_1 F_11 ( struct V_11 * V_2 )
{
struct V_11 * V_12 ;
if ( ! V_2 ) {
V_2 = & V_13 ;
V_2 -> V_14 = 2 ;
}
V_12 = F_2 ( V_2 , sizeof( struct V_11 ) ,
& V_20 ) ;
if ( ! V_12 -> V_16 )
V_12 -> V_16 = V_21 ;
}
void T_1 F_12 ( struct V_11 * V_2 )
{
struct V_11 * V_12 ;
if ( ! V_2 ) {
V_2 = & V_13 ;
V_2 -> V_14 = 3 ;
}
V_12 = F_2 ( V_2 , sizeof( struct V_11 ) ,
& V_22 ) ;
if ( ! V_12 -> V_16 )
V_12 -> V_16 = V_23 ;
}
void T_1 F_13 ( struct V_11 * V_2 )
{
struct V_11 * V_12 ;
if ( ! V_2 ) {
V_2 = & V_13 ;
V_2 -> V_14 = 4 ;
}
V_12 = F_2 ( V_2 , sizeof( struct V_11 ) ,
& V_24 ) ;
if ( ! V_12 -> V_16 )
V_12 -> V_16 = V_25 ;
}
void T_1 F_14 ( struct V_11 * V_2 )
{
struct V_11 * V_12 ;
if ( ! V_2 ) {
V_2 = & V_13 ;
V_2 -> V_14 = 5 ;
}
V_12 = F_2 ( V_2 , sizeof( struct V_11 ) ,
& V_26 ) ;
if ( ! V_12 -> V_16 )
V_12 -> V_16 = V_27 ;
}
void T_1 F_15 ( struct V_11 * V_2 )
{
struct V_11 * V_12 ;
if ( ! V_2 ) {
V_2 = & V_13 ;
V_2 -> V_14 = 6 ;
}
V_12 = F_2 ( V_2 , sizeof( struct V_11 ) ,
& V_28 ) ;
if ( ! V_12 -> V_16 )
V_12 -> V_16 = V_29 ;
}
void T_1 F_16 ( struct V_11 * V_2 )
{
struct V_11 * V_12 ;
if ( ! V_2 ) {
V_2 = & V_13 ;
V_2 -> V_14 = 7 ;
}
V_12 = F_2 ( V_2 , sizeof( struct V_11 ) ,
& V_30 ) ;
if ( ! V_12 -> V_16 )
V_12 -> V_16 = V_31 ;
}
void T_1 F_17 ( struct V_32 * V_33 )
{
F_2 ( V_33 , sizeof( struct V_32 ) ,
& V_34 ) ;
}
void T_1 F_18 ( struct V_35 * V_2 )
{
struct V_35 * V_12 ;
V_12 = F_2 ( V_2 , sizeof( struct V_35 ) ,
& V_36 ) ;
if ( ! V_12 -> V_16 )
V_12 -> V_16 = V_37 ;
}
void T_1 F_19 ( struct V_38 * V_2 )
{
struct V_38 * V_12 ;
V_12 = F_2 ( V_2 , sizeof( * V_12 ) , & V_39 ) ;
if ( V_12 ) {
V_12 -> V_40 = F_20 ( V_2 -> V_40 ,
sizeof( struct V_41 ) * V_12 -> V_42 ,
V_43 ) ;
if ( ! V_12 -> V_40 )
F_21 ( V_44 L_1 ) ;
} else {
F_21 ( V_44 L_2 ) ;
}
}
static int T_1 F_22 ( struct V_45 * V_46 )
{
void * V_47 ;
int V_48 ;
V_48 = sizeof( struct V_49 ) * V_46 -> V_50 ;
if ( V_48 ) {
V_47 = F_20 ( V_46 -> V_51 , V_48 , V_43 ) ;
V_46 -> V_51 = V_47 ;
if ( ! V_47 )
return - V_52 ;
}
if ( V_46 -> V_53 && V_46 -> V_54 ) {
V_48 = sizeof( int ) * V_46 -> V_54 ;
V_47 = F_20 ( V_46 -> V_53 , V_48 , V_43 ) ;
V_46 -> V_53 = V_47 ;
if ( ! V_47 )
return - V_52 ;
}
if ( V_46 -> V_55 ) {
V_47 = F_20 ( V_46 -> V_55 ,
sizeof( struct V_56 ) , V_43 ) ;
V_46 -> V_55 = V_47 ;
if ( ! V_47 )
return - V_52 ;
}
return 0 ;
}
void T_1 F_23 ( struct V_57 * V_58 )
{
struct V_57 * V_12 ;
int V_48 ;
int V_59 ;
V_12 = F_2 ( V_58 , sizeof( struct V_57 ) ,
& V_60 ) ;
if ( ! V_12 )
return;
V_48 = sizeof( struct V_45 ) * V_12 -> V_61 ;
if ( V_48 ) {
struct V_45 * V_62 = V_12 -> V_63 ;
struct V_45 * V_64 ;
int V_65 ;
V_64 = F_20 ( V_62 , V_48 , V_43 ) ;
V_12 -> V_63 = V_64 ;
if ( ! V_64 ) {
F_21 ( V_44 L_3 , V_66 ) ;
return;
}
for ( V_65 = 0 ; V_65 < V_12 -> V_61 ; V_65 ++ ) {
V_59 = F_22 ( V_64 ) ;
if ( V_59 ) {
F_21 ( V_44 L_4 ,
V_66 , V_65 ) ;
return;
}
V_64 ++ ;
}
}
}
void T_1 F_24 ( struct V_67 * V_33 )
{
F_2 ( V_33 , sizeof( struct V_67 ) ,
& V_68 ) ;
}
void T_1 F_25 ( struct V_69 * V_2 )
{
V_70 . V_71 . V_72 = V_2 ;
}
void T_1 F_26 ( struct V_73 * V_33 )
{
F_2 ( V_33 , sizeof( struct V_73 ) ,
& V_74 ) ;
}
void T_1 F_27 ( struct V_75 * V_76 )
{
F_2 ( V_76 ,
sizeof( struct V_75 ) , & V_77 ) ;
}
void T_1 F_27 ( struct V_75 * V_2 )
{
if ( ! V_2 )
V_2 = & V_78 ;
F_2 ( V_2 , sizeof( struct V_75 ) ,
& V_77 ) ;
}
void T_1 F_28 ( struct V_79 * V_80 )
{
F_2 ( V_80 , sizeof( struct V_79 ) ,
& V_81 ) ;
}
void T_1 F_29 ( struct V_82 * V_2 )
{
F_2 ( V_2 , sizeof( * V_2 ) , & V_83 ) ;
}
void T_1 F_30 ( struct V_84 * V_2 )
{
struct V_84 * V_12 ;
V_12 = F_2 ( V_2 , sizeof( struct V_84 ) ,
& V_85 ) ;
if ( ! V_12 -> V_86 )
V_12 -> V_86 = V_87 ;
if ( ! V_12 -> V_88 )
V_12 -> V_88 = V_89 ;
}
void T_1 F_31 ( struct V_90 * V_2 )
{
F_2 ( V_2 , sizeof( * V_2 ) , & V_91 ) ;
}
void T_1 F_32 ( int (* V_16)( void ) , int V_92 ,
int V_93 )
{
struct V_94 V_2 ;
if ( ! V_93 || V_92 < 0 ) {
F_33 ( L_5 , V_66 ) ;
return;
}
V_2 . V_93 = V_93 ;
V_2 . V_92 = V_92 ;
V_2 . V_16 = ( V_16 ) ? V_16 : V_95 ;
#if F_34 ( V_96 )
V_2 . V_97 = V_98 ;
#elif F_34 ( V_99 )
V_2 . V_97 = V_100 ;
#elif F_34 ( V_101 )
V_2 . V_97 = V_102 ;
#endif
F_2 ( & V_2 , sizeof( V_2 ) , & V_103 ) ;
}
void T_1 F_35 ( int (* V_16)( void ) , int V_92 ,
int V_93 )
{
struct V_94 V_2 ;
if ( ! V_93 || V_92 < 0 ) {
F_33 ( L_5 , V_66 ) ;
return;
}
V_2 . V_93 = V_93 ;
V_2 . V_92 = V_92 ;
V_2 . V_16 = ( V_16 ) ? V_16 : V_104 ;
#if F_34 ( V_96 )
V_2 . V_97 = V_98 ;
#elif F_34 ( V_99 )
V_2 . V_97 = V_100 ;
#endif
F_2 ( & V_2 , sizeof( V_2 ) , & V_105 ) ;
}
void T_1 F_36 ( int (* V_16)( void ) , int V_92 ,
int V_93 )
{
struct V_94 V_2 ;
if ( ! V_93 || V_92 < 0 ) {
F_33 ( L_5 , V_66 ) ;
return;
}
V_2 . V_93 = V_93 ;
V_2 . V_92 = V_92 ;
V_2 . V_16 = ( V_16 ) ? V_16 : V_106 ;
#if F_34 ( V_96 )
V_2 . V_97 = V_98 ;
#elif F_34 ( V_99 )
V_2 . V_97 = V_100 ;
#endif
F_2 ( & V_2 , sizeof( V_2 ) , & V_107 ) ;
}
