static void F_1 ( struct V_1 * V_2 ) {}
static int F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 = V_2 -> V_6 == - 1 ? - 1 : F_3 ( V_2 -> V_6 ) ;
V_4 = F_4 ( sizeof( struct V_3 ) , V_7 , V_5 ) ;
if ( ! V_4 )
return - V_8 ;
if ( V_2 -> V_9 )
memcpy ( V_4 , V_2 -> V_9 -> V_10 . V_11 ,
sizeof( * V_4 ) ) ;
V_2 -> V_10 . V_11 = V_4 ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( V_2 -> V_10 . V_11 ) ;
V_2 -> V_10 . V_11 = NULL ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_12 = 0 ;
if ( V_2 -> V_13 . type != V_14 . type ) {
V_12 = - V_15 ;
goto V_16;
}
V_12 = F_2 ( V_2 ) ;
if ( V_12 )
goto V_16;
V_2 -> V_17 = F_5 ;
V_16:
return V_12 ;
}
static void F_8 ( struct V_18 * V_19 )
{
int V_6 ;
T_1 * V_20 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
V_22 = F_9 ( V_19 , struct V_21 , V_19 ) ;
V_20 = & V_22 -> V_20 ;
if ( V_22 -> V_25 ) {
V_6 = F_10 ( V_20 ) ;
V_24 = F_11 ( V_22 -> V_26 [ V_6 ] ) ;
if ( F_12 ( V_24 ) -> V_27 )
F_12 ( V_24 ) -> V_27 ( V_22 -> V_25 ) ;
}
F_13 (cpu, mask) {
if ( ! ( F_14 ( V_22 -> V_26 [ V_6 ] ) ) )
F_15 ( V_22 -> V_26 [ V_6 ] ) ;
}
F_6 ( V_22 -> V_26 ) ;
F_6 ( V_22 ) ;
}
static void * F_16 ( int V_6 )
{
int V_28 ;
T_1 * V_20 ;
struct V_21 * V_22 ;
V_22 = F_17 ( sizeof( struct V_21 ) , V_7 ) ;
if ( ! V_22 )
return NULL ;
F_18 () ;
V_28 = F_19 () ;
V_20 = & V_22 -> V_20 ;
if ( V_6 != - 1 )
F_20 ( V_6 , V_20 ) ;
else
F_21 ( V_20 , V_29 ) ;
F_22 () ;
V_22 -> V_26 = F_23 ( V_28 ,
sizeof( struct V_30 * ) , V_7 ) ;
if ( ! V_22 -> V_26 ) {
F_6 ( V_22 ) ;
return NULL ;
}
return V_22 ;
}
static void F_24 ( void * V_31 )
{
struct V_21 * V_22 = V_31 ;
F_25 ( & V_22 -> V_19 ) ;
}
static void * F_26 ( int V_32 , void * * V_33 ,
int V_34 , bool V_35 )
{
int V_6 ;
T_1 * V_20 ;
struct V_23 * V_24 ;
struct V_21 * V_22 = NULL ;
V_22 = F_16 ( V_32 ) ;
if ( ! V_22 )
return NULL ;
V_24 = F_27 ( true ) ;
if ( ! V_24 )
goto V_36;
F_28 ( & V_22 -> V_19 , F_8 ) ;
V_20 = & V_22 -> V_20 ;
F_13 (cpu, mask) {
struct V_23 * V_37 ;
V_37 = F_29 ( V_38 , V_6 ) ;
if ( ! V_37 )
goto V_36;
V_22 -> V_26 [ V_6 ] = F_30 ( V_37 , V_24 ) ;
if ( F_31 ( V_22 -> V_26 [ V_6 ] ) )
goto V_36;
}
if ( ! F_12 ( V_24 ) -> V_39 )
goto V_36;
V_22 -> V_25 =
F_12 ( V_24 ) -> V_39 ( V_24 , V_6 , V_33 ,
V_34 , V_35 ) ;
if ( ! V_22 -> V_25 )
goto V_36;
V_16:
return V_22 ;
V_36:
F_24 ( V_22 ) ;
V_22 = NULL ;
goto V_16;
}
static void F_32 ( struct V_1 * V_2 , int V_40 )
{
int V_6 = F_33 () ;
struct V_21 * V_22 ;
struct V_41 * V_42 = F_34 ( & V_43 ) ;
struct V_23 * V_24 , * V_37 = F_29 ( V_38 , V_6 ) ;
if ( ! V_37 )
goto V_44;
V_22 = F_35 ( V_42 , V_2 ) ;
if ( ! V_22 )
goto V_44;
V_24 = F_11 ( V_22 -> V_26 [ V_6 ] ) ;
if ( F_36 ( ! V_24 || ! F_12 ( V_24 ) -> V_45 ) )
goto V_46;
if ( F_12 ( V_24 ) -> V_45 ( V_24 , V_42 ,
V_22 -> V_25 ) )
goto V_46;
if ( F_37 ( V_22 -> V_26 [ V_6 ] , V_47 ) )
goto V_46;
V_2 -> V_10 . V_48 = 0 ;
if ( F_38 ( V_37 ) -> F_39 ( V_37 , V_2 , V_47 ) )
goto V_46;
V_16:
return;
V_46:
F_40 ( V_42 , 0 , true ) ;
V_44:
V_2 -> V_10 . V_48 = V_49 ;
goto V_16;
}
static void F_41 ( struct V_1 * V_2 , int V_50 )
{
bool V_51 ;
int V_6 = F_33 () ;
unsigned long V_28 ;
struct V_23 * V_24 , * V_37 = F_29 ( V_38 , V_6 ) ;
struct V_41 * V_42 = F_34 ( & V_43 ) ;
struct V_21 * V_22 = F_42 ( V_42 ) ;
if ( V_2 -> V_10 . V_48 == V_49 )
return;
if ( ! V_37 )
return;
V_24 = F_11 ( V_22 -> V_26 [ V_6 ] ) ;
if ( ! V_24 )
return;
F_38 ( V_37 ) -> F_43 ( V_37 , V_2 ) ;
V_2 -> V_10 . V_48 = V_49 ;
if ( V_50 & V_52 ) {
if ( F_36 ( V_42 -> V_2 != V_2 ) )
return;
if ( ! F_12 ( V_24 ) -> V_53 )
return;
F_12 ( V_24 ) -> V_53 ( V_24 , V_42 ,
V_22 -> V_25 ) ;
if ( ! F_12 ( V_24 ) -> V_54 )
return;
V_28 = F_12 ( V_24 ) -> V_54 ( V_24 , V_42 ,
V_22 -> V_25 ,
& V_51 ) ;
F_40 ( V_42 , V_28 , V_51 ) ;
}
F_44 ( V_22 -> V_26 [ V_6 ] ) ;
}
static int F_45 ( struct V_1 * V_2 , int V_50 )
{
int V_12 = 0 ;
struct V_55 * V_56 = & V_2 -> V_10 ;
if ( V_50 & V_57 ) {
F_32 ( V_2 , 0 ) ;
if ( V_56 -> V_48 & V_49 )
V_12 = - V_58 ;
} else {
V_56 -> V_48 = V_49 ;
}
return V_12 ;
}
static void F_46 ( struct V_1 * V_2 , int V_50 )
{
F_41 ( V_2 , V_52 ) ;
}
static int F_47 ( struct V_30 * V_4 )
{
bool V_59 = false , V_60 = false ;
int V_61 = 0 ;
struct V_62 * V_63 ;
F_48 (filter, filters, entry) {
if ( ++ V_61 > V_64 )
return - V_65 ;
if ( ( V_63 -> V_59 == 1 ) && V_60 )
return - V_65 ;
if ( ( V_63 -> V_59 == 0 ) && V_59 )
return - V_65 ;
if ( V_63 -> V_59 && V_63 -> V_28 == 0 )
return - V_58 ;
if ( V_63 -> V_59 )
V_59 = true ;
else
V_60 = true ;
}
return 0 ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_66 * V_67 = F_50 ( V_2 ) ;
unsigned long V_68 , V_69 , * V_70 = V_2 -> V_71 ;
struct V_3 * V_4 = V_2 -> V_10 . V_11 ;
struct V_72 * V_72 ;
struct V_62 * V_63 ;
int V_73 = 0 ;
F_48 (filter, &head->list, entry) {
V_68 = V_63 -> V_74 + V_70 [ V_73 ] ;
V_69 = V_68 + V_63 -> V_28 ;
V_72 = & V_4 -> V_72 [ V_73 ] ;
if ( V_63 -> V_59 == 1 ) {
V_72 -> V_75 = V_68 ;
V_72 -> V_76 = V_69 ;
V_72 -> type = V_77 ;
} else {
if ( V_63 -> V_63 == 1 ) {
V_72 -> V_75 = V_68 ;
V_72 -> type = V_78 ;
} else {
V_72 -> V_76 = V_69 ;
V_72 -> type = V_79 ;
}
}
V_73 ++ ;
}
V_4 -> V_80 = V_73 ;
}
int F_51 ( struct V_23 * V_37 , bool V_81 )
{
char V_82 [ sizeof( L_1 ) ] ;
int V_12 = 0 , V_6 = F_38 ( V_37 ) -> F_52 ( V_37 ) ;
struct V_83 * V_84 = V_14 . V_85 ;
struct V_83 * V_86 = & V_37 -> V_85 ;
sprintf ( V_82 , L_2 , V_6 ) ;
if ( ! V_87 )
return - V_88 ;
if ( V_81 ) {
V_12 = F_53 ( & V_84 -> V_89 , & V_86 -> V_89 , V_82 ) ;
if ( V_12 )
return V_12 ;
F_29 ( V_38 , V_6 ) = V_37 ;
} else {
F_54 ( & V_84 -> V_89 , V_82 ) ;
F_29 ( V_38 , V_6 ) = NULL ;
}
return 0 ;
}
static int T_2 F_55 ( void )
{
int V_12 ;
V_14 . V_90 = V_91 ;
V_14 . V_92 = V_93 ;
V_14 . V_94 = V_95 ;
V_14 . V_96 = F_1 ;
V_14 . V_97 = F_7 ;
V_14 . V_98 = F_26 ;
V_14 . V_99 = F_24 ;
V_14 . V_68 = F_32 ;
V_14 . V_69 = F_41 ;
V_14 . V_100 = F_45 ;
V_14 . V_101 = F_46 ;
V_14 . V_102 = F_49 ;
V_14 . V_103 = F_47 ;
V_14 . V_104 = V_64 ;
V_12 = F_56 ( & V_14 , V_105 , - 1 ) ;
if ( V_12 == 0 )
V_87 = true ;
return V_12 ;
}
