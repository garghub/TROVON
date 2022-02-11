static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 V_6 [ 1 ] ;
F_2 ( V_6 , V_4 , sizeof( * V_4 ) ) ;
F_3 ( V_2 -> V_7 , V_6 , 1 , V_4 , V_8 ) ;
}
static void F_4 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_11 -> V_12 ;
struct V_3 * V_13 ;
unsigned long V_14 ;
unsigned int V_15 ;
F_5 ( & V_2 -> V_16 , V_14 ) ;
if ( V_2 -> V_17 ) {
while ( ( V_13 = F_6 ( V_2 -> V_7 , & V_15 ) ) != NULL ) {
F_7 ( & V_2 -> V_16 , V_14 ) ;
F_8 ( V_2 -> V_18 ,
F_9 ( V_13 -> type ) ,
F_9 ( V_13 -> V_19 ) ,
F_10 ( V_13 -> V_20 ) ) ;
F_5 ( & V_2 -> V_16 , V_14 ) ;
F_1 ( V_2 , V_13 ) ;
}
F_11 ( V_10 ) ;
}
F_7 ( & V_2 -> V_16 , V_14 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
T_1 type , T_1 V_19 , T_2 V_20 )
{
struct V_3 * V_21 ;
struct V_5 V_6 [ 1 ] ;
unsigned long V_14 ;
int V_22 ;
V_21 = F_13 ( sizeof( * V_21 ) , V_8 ) ;
if ( ! V_21 )
return - V_23 ;
V_21 -> type = F_14 ( type ) ;
V_21 -> V_19 = F_14 ( V_19 ) ;
V_21 -> V_20 = F_15 ( V_20 ) ;
F_2 ( V_6 , V_21 , sizeof( * V_21 ) ) ;
F_5 ( & V_2 -> V_16 , V_14 ) ;
if ( V_2 -> V_17 ) {
V_22 = F_16 ( V_2 -> V_24 , V_6 , 1 , V_21 , V_8 ) ;
F_11 ( V_2 -> V_24 ) ;
} else {
V_22 = - V_25 ;
}
F_7 ( & V_2 -> V_16 , V_14 ) ;
if ( V_22 != 0 )
F_17 ( V_21 ) ;
return V_22 ;
}
static void F_18 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_11 -> V_12 ;
struct V_3 * V_21 ;
unsigned long V_14 ;
unsigned int V_15 ;
F_5 ( & V_2 -> V_16 , V_14 ) ;
while ( ( V_21 = F_6 ( V_2 -> V_24 , & V_15 ) ) != NULL )
F_17 ( V_21 ) ;
F_7 ( & V_2 -> V_16 , V_14 ) ;
}
static int F_19 ( struct V_26 * V_18 , unsigned int type ,
unsigned int V_19 , int V_20 )
{
struct V_1 * V_2 = F_20 ( V_18 ) ;
return F_12 ( V_2 , type , V_19 , V_20 ) ;
}
static T_3 F_21 ( struct V_1 * V_2 ,
T_3 V_27 , T_3 V_28 )
{
T_3 V_29 ;
F_22 ( V_2 -> V_11 , struct V_30 , V_27 , & V_27 ) ;
F_22 ( V_2 -> V_11 , struct V_30 , V_28 , & V_28 ) ;
F_23 ( V_2 -> V_11 , struct V_30 , V_29 , & V_29 ) ;
return V_29 ;
}
static void F_24 ( struct V_1 * V_2 , int V_27 , int V_28 ,
unsigned long * V_31 , unsigned int V_32 )
{
unsigned int V_33 ;
T_3 * V_34 ;
T_3 V_35 ;
V_35 = F_21 ( V_2 , V_27 , V_28 ) ;
if ( ! V_35 )
return;
if ( V_32 > V_35 * 8 )
V_32 = V_35 * 8 ;
V_34 = F_13 ( V_35 , V_36 ) ;
if ( ! V_34 )
return;
F_25 ( V_2 -> V_11 , F_26 ( struct V_30 ,
V_37 . V_38 ) ,
V_34 , V_35 ) ;
for ( V_33 = 0 ; V_33 < V_32 ; V_33 ++ ) {
if ( V_34 [ V_33 / 8 ] & ( 1 << ( V_33 % 8 ) ) )
F_27 ( V_33 , V_31 ) ;
}
F_17 ( V_34 ) ;
if ( V_27 == V_39 )
F_27 ( V_28 , V_2 -> V_18 -> V_40 ) ;
}
static void F_28 ( struct V_1 * V_2 , int abs )
{
T_4 V_41 , V_42 , V_43 , V_44 , V_45 ;
F_21 ( V_2 , V_46 , abs ) ;
F_23 ( V_2 -> V_11 , struct V_30 , V_37 . abs . V_47 , & V_41 ) ;
F_23 ( V_2 -> V_11 , struct V_30 , V_37 . abs . V_48 , & V_42 ) ;
F_23 ( V_2 -> V_11 , struct V_30 , V_37 . abs . V_49 , & V_43 ) ;
F_23 ( V_2 -> V_11 , struct V_30 , V_37 . abs . V_50 , & V_44 ) ;
F_23 ( V_2 -> V_11 , struct V_30 , V_37 . abs . V_51 , & V_45 ) ;
F_29 ( V_2 -> V_18 , abs , V_41 , V_42 , V_44 , V_45 ) ;
F_30 ( V_2 -> V_18 , abs , V_43 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_9 * V_52 [ 2 ] ;
T_5 * V_53 [] = { F_4 ,
F_18 } ;
static const char * const V_54 [] = { L_1 , L_2 } ;
int V_55 ;
V_55 = F_32 ( V_2 -> V_11 , 2 , V_52 , V_53 , V_54 , NULL ) ;
if ( V_55 )
return V_55 ;
V_2 -> V_7 = V_52 [ 0 ] ;
V_2 -> V_24 = V_52 [ 1 ] ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 )
{
unsigned long V_14 ;
int V_56 , V_29 ;
F_5 ( & V_2 -> V_16 , V_14 ) ;
V_29 = F_34 ( V_2 -> V_7 ) ;
if ( V_29 > F_35 ( V_2 -> V_57 ) )
V_29 = F_35 ( V_2 -> V_57 ) ;
for ( V_56 = 0 ; V_56 < V_29 ; V_56 ++ )
F_1 ( V_2 , & V_2 -> V_57 [ V_56 ] ) ;
F_11 ( V_2 -> V_7 ) ;
F_7 ( & V_2 -> V_16 , V_14 ) ;
}
static int F_36 ( struct V_58 * V_11 )
{
struct V_1 * V_2 ;
unsigned long V_14 ;
T_6 V_29 ;
int abs , V_55 ;
if ( ! F_37 ( V_11 , V_59 ) )
return - V_25 ;
V_2 = F_13 ( sizeof( * V_2 ) , V_36 ) ;
if ( ! V_2 )
return - V_23 ;
V_11 -> V_12 = V_2 ;
V_2 -> V_11 = V_11 ;
F_38 ( & V_2 -> V_16 ) ;
V_55 = F_31 ( V_2 ) ;
if ( V_55 )
goto V_60;
V_2 -> V_18 = F_39 () ;
if ( ! V_2 -> V_18 ) {
V_55 = - V_23 ;
goto V_61;
}
F_40 ( V_2 -> V_18 , V_2 ) ;
V_29 = F_21 ( V_2 , V_62 , 0 ) ;
F_25 ( V_2 -> V_11 , F_26 ( struct V_30 ,
V_37 . string ) ,
V_2 -> V_63 , V_47 ( V_29 , sizeof( V_2 -> V_63 ) ) ) ;
V_29 = F_21 ( V_2 , V_64 , 0 ) ;
F_25 ( V_2 -> V_11 , F_26 ( struct V_30 ,
V_37 . string ) ,
V_2 -> V_65 , V_47 ( V_29 , sizeof( V_2 -> V_65 ) ) ) ;
snprintf ( V_2 -> V_66 , sizeof( V_2 -> V_66 ) ,
L_3 , V_11 -> V_67 ) ;
V_2 -> V_18 -> V_63 = V_2 -> V_63 ;
V_2 -> V_18 -> V_66 = V_2 -> V_66 ;
V_2 -> V_18 -> V_68 = V_2 -> V_65 ;
V_29 = F_21 ( V_2 , V_69 , 0 ) ;
if ( V_29 >= sizeof( struct V_70 ) ) {
F_23 ( V_2 -> V_11 , struct V_30 ,
V_37 . V_71 . V_72 , & V_2 -> V_18 -> V_73 . V_72 ) ;
F_23 ( V_2 -> V_11 , struct V_30 ,
V_37 . V_71 . V_74 , & V_2 -> V_18 -> V_73 . V_74 ) ;
F_23 ( V_2 -> V_11 , struct V_30 ,
V_37 . V_71 . V_75 , & V_2 -> V_18 -> V_73 . V_75 ) ;
F_23 ( V_2 -> V_11 , struct V_30 ,
V_37 . V_71 . V_76 , & V_2 -> V_18 -> V_73 . V_76 ) ;
} else {
V_2 -> V_18 -> V_73 . V_72 = V_77 ;
}
F_24 ( V_2 , V_78 , 0 ,
V_2 -> V_18 -> V_79 , V_80 ) ;
V_29 = F_21 ( V_2 , V_39 , V_81 ) ;
if ( V_29 )
F_27 ( V_81 , V_2 -> V_18 -> V_40 ) ;
V_2 -> V_18 -> V_82 . V_83 = & V_11 -> V_82 ;
V_2 -> V_18 -> V_13 = F_19 ;
F_24 ( V_2 , V_39 , V_84 ,
V_2 -> V_18 -> V_85 , V_86 ) ;
F_24 ( V_2 , V_39 , V_87 ,
V_2 -> V_18 -> V_88 , V_89 ) ;
F_24 ( V_2 , V_39 , V_90 ,
V_2 -> V_18 -> V_91 , V_92 ) ;
F_24 ( V_2 , V_39 , V_93 ,
V_2 -> V_18 -> V_94 , V_95 ) ;
F_24 ( V_2 , V_39 , V_96 ,
V_2 -> V_18 -> V_97 , V_98 ) ;
F_24 ( V_2 , V_39 , V_99 ,
V_2 -> V_18 -> V_100 , V_101 ) ;
F_24 ( V_2 , V_39 , V_102 ,
V_2 -> V_18 -> V_103 , V_104 ) ;
if ( F_41 ( V_90 , V_2 -> V_18 -> V_40 ) ) {
for ( abs = 0 ; abs < V_92 ; abs ++ ) {
if ( ! F_41 ( abs , V_2 -> V_18 -> V_91 ) )
continue;
F_28 ( V_2 , abs ) ;
}
}
F_42 ( V_11 ) ;
V_2 -> V_17 = true ;
V_55 = F_43 ( V_2 -> V_18 ) ;
if ( V_55 )
goto V_105;
F_33 ( V_2 ) ;
return 0 ;
V_105:
F_5 ( & V_2 -> V_16 , V_14 ) ;
V_2 -> V_17 = false ;
F_7 ( & V_2 -> V_16 , V_14 ) ;
F_44 ( V_2 -> V_18 ) ;
V_61:
V_11 -> V_106 -> V_107 ( V_11 ) ;
V_60:
F_17 ( V_2 ) ;
return V_55 ;
}
static void F_45 ( struct V_58 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_12 ;
void * V_108 ;
unsigned long V_14 ;
F_5 ( & V_2 -> V_16 , V_14 ) ;
V_2 -> V_17 = false ;
F_7 ( & V_2 -> V_16 , V_14 ) ;
F_46 ( V_2 -> V_18 ) ;
V_11 -> V_106 -> V_109 ( V_11 ) ;
while ( ( V_108 = F_47 ( V_2 -> V_24 ) ) != NULL )
F_17 ( V_108 ) ;
V_11 -> V_106 -> V_107 ( V_11 ) ;
F_17 ( V_2 ) ;
}
static int F_48 ( struct V_58 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_12 ;
unsigned long V_14 ;
F_5 ( & V_2 -> V_16 , V_14 ) ;
V_2 -> V_17 = false ;
F_7 ( & V_2 -> V_16 , V_14 ) ;
V_11 -> V_106 -> V_107 ( V_11 ) ;
return 0 ;
}
static int F_49 ( struct V_58 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_12 ;
int V_55 ;
V_55 = F_31 ( V_2 ) ;
if ( V_55 )
return V_55 ;
F_42 ( V_11 ) ;
V_2 -> V_17 = true ;
F_33 ( V_2 ) ;
return 0 ;
}
