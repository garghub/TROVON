static void F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 ;
bool V_6 = V_2 == & V_7 [ V_8 ] ||
V_2 == & V_7 [ V_9 ] ;
if ( V_2 -> V_10 ) {
F_2 ( V_11 , L_1 ) ;
return;
}
if ( V_6 && ! V_12 && V_3 )
F_3 ( & V_13 ) ;
if ( ! V_2 -> V_14 )
return;
V_5 = F_4 ( V_2 -> V_14 , struct V_4 , V_15 ) ;
F_2 ( V_11 , L_2 ,
V_5 -> type , V_5 -> V_16 , F_5 ( V_5 -> V_17 ) ) ;
if ( V_6 && V_12 ) {
F_2 ( V_11 , L_3 ) ;
F_6 ( & V_13 , 1 * V_18 ) ;
return;
}
F_7 ( & V_2 -> V_19 ) ;
V_2 -> V_19 . V_15 . V_17 = F_8 ( V_2 -> V_20 , V_5 -> V_17 ) ;
V_2 -> V_19 . V_21 = F_8 ( V_2 -> V_20 , V_5 -> V_22 ) ;
F_9 ( & V_2 -> V_19 , V_23 ) ;
}
static void F_10 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = & V_7 [ V_5 -> type ] ;
struct V_24 * * V_25 = & V_2 -> V_7 . V_24 ;
struct V_24 * V_26 = NULL ;
struct V_4 * V_27 ;
int V_28 = 1 ;
bool V_29 = false ;
F_2 ( V_11 , L_4 ,
V_5 -> type , V_5 -> V_16 , F_5 ( V_5 -> V_17 ) ) ;
if ( V_2 -> V_14 == & V_5 -> V_15 ) {
V_2 -> V_14 = F_11 ( & V_5 -> V_15 ) ;
V_29 = true ;
}
if ( ! F_12 ( & V_5 -> V_15 ) ) {
F_13 ( & V_5 -> V_15 , & V_2 -> V_7 ) ;
F_14 ( & V_5 -> V_15 ) ;
}
while ( * V_25 ) {
V_26 = * V_25 ;
V_27 = F_15 ( V_26 , struct V_4 , V_15 ) ;
if ( V_5 -> V_17 . V_30 < V_27 -> V_17 . V_30 ) {
V_25 = & ( * V_25 ) -> V_31 ;
} else {
V_25 = & ( * V_25 ) -> V_32 ;
V_28 = 0 ;
}
}
if ( V_28 )
V_2 -> V_14 = & V_5 -> V_15 ;
if ( V_28 || V_29 )
F_1 ( V_2 , V_29 ) ;
F_16 ( & V_5 -> V_15 , V_26 , V_25 ) ;
F_17 ( & V_5 -> V_15 , & V_2 -> V_7 ) ;
}
void F_18 ( struct V_4 * V_5 ,
enum V_33 type , void (* V_16)( struct V_4 * ) )
{
F_14 ( & V_5 -> V_15 ) ;
V_5 -> type = type ;
V_5 -> V_16 = V_16 ;
F_2 ( V_11 , L_5 , type , V_16 ) ;
}
void F_19 ( struct V_4 * V_5 , T_1 V_34 ,
T_1 V_35 )
{
unsigned long V_36 ;
F_20 ( & V_37 , V_36 ) ;
V_5 -> V_22 = V_34 ;
V_5 -> V_17 = V_35 ;
F_10 ( V_5 ) ;
F_21 ( & V_37 , V_36 ) ;
}
int F_22 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = & V_7 [ V_5 -> type ] ;
unsigned long V_36 ;
bool V_14 = false ;
int V_38 = 0 ;
F_20 ( & V_37 , V_36 ) ;
if ( ! F_12 ( & V_5 -> V_15 ) ) {
F_2 ( V_11 , L_6 ,
V_5 -> type , V_5 -> V_16 ,
F_5 ( V_5 -> V_17 ) ) ;
V_38 = 1 ;
if ( V_2 -> V_14 == & V_5 -> V_15 ) {
V_2 -> V_14 = F_11 ( & V_5 -> V_15 ) ;
V_14 = true ;
}
F_13 ( & V_5 -> V_15 , & V_2 -> V_7 ) ;
F_14 ( & V_5 -> V_15 ) ;
if ( V_14 )
F_1 ( V_2 , true ) ;
} else
F_2 ( V_11 , L_7 ,
V_5 -> type , V_5 -> V_16 ) ;
F_21 ( & V_37 , V_36 ) ;
if ( ! V_38 && F_23 ( & V_2 -> V_19 ) )
V_38 = - 1 ;
return V_38 ;
}
int F_24 ( struct V_4 * V_5 )
{
for (; ; ) {
int V_38 = F_22 ( V_5 ) ;
if ( V_38 >= 0 )
return V_38 ;
F_25 () ;
}
}
int F_26 ( struct V_39 V_40 )
{
int V_41 ;
int V_38 ;
unsigned long V_36 ;
struct V_42 V_43 ;
struct V_39 V_44 ;
F_27 ( V_40 . V_45 , & V_43 ) ;
F_2 ( V_46 , L_8 ,
V_40 . V_45 , V_40 . V_47 ,
V_43 . V_48 , V_43 . V_49 ,
V_43 . V_50 , V_43 . V_51 + 1 ,
V_43 . V_52 ,
V_43 . V_53 + 1900 ) ;
F_28 ( & V_54 ) ;
F_20 ( & V_37 , V_36 ) ;
F_29 ( & V_13 ) ;
F_30 ( & V_44 ) ;
for ( V_41 = 0 ; V_41 < V_55 ; V_41 ++ ) {
F_7 ( & V_7 [ V_41 ] . V_19 ) ;
V_7 [ V_41 ] . V_10 = true ;
V_7 [ V_41 ] . V_56 = F_31 ( V_44 ) ;
}
V_7 [ V_9 ] . V_20 =
V_7 [ V_57 ] . V_20 =
F_32 ( V_7 [ V_57 ] . V_20 ,
F_31 ( F_33 ( V_44 , V_40 ) ) ) ;
F_21 ( & V_37 , V_36 ) ;
V_38 = F_34 ( & V_40 ) ;
F_20 ( & V_37 , V_36 ) ;
for ( V_41 = 0 ; V_41 < V_55 ; V_41 ++ ) {
V_7 [ V_41 ] . V_10 = false ;
F_1 ( & V_7 [ V_41 ] , false ) ;
}
F_21 ( & V_37 , V_36 ) ;
if ( V_38 < 0 ) {
F_2 ( ERROR , L_9 ) ;
goto V_58;
}
if ( ! V_59 ) {
F_2 ( ERROR ,
L_10 ) ;
goto V_58;
}
V_38 = F_35 ( V_59 , & V_43 ) ;
if ( V_38 < 0 )
F_2 ( ERROR , L_11
L_12 ) ;
V_58:
F_3 ( & V_13 ) ;
F_36 ( & V_54 ) ;
return V_38 ;
}
T_1 F_37 ( void )
{
T_1 V_60 ;
unsigned long V_36 ;
struct V_1 * V_2 = & V_7 [ V_57 ] ;
F_20 ( & V_37 , V_36 ) ;
V_60 = V_2 -> V_10 ? V_2 -> V_56 : F_38 () ;
V_60 = F_32 ( V_60 , V_2 -> V_20 ) ;
F_21 ( & V_37 , V_36 ) ;
return V_60 ;
}
static enum V_61 F_39 ( struct V_62 * V_19 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
unsigned long V_36 ;
T_1 V_60 ;
F_20 ( & V_37 , V_36 ) ;
V_2 = F_4 ( V_19 , struct V_1 , V_19 ) ;
V_60 = V_2 -> V_10 ? V_2 -> V_56 : F_40 ( V_19 ) ;
V_60 = F_32 ( V_60 , V_2 -> V_20 ) ;
F_2 ( INT , L_13 ,
V_2 - V_7 , F_5 ( V_60 ) ) ;
while ( V_2 -> V_14 ) {
V_5 = F_4 ( V_2 -> V_14 , struct V_4 , V_15 ) ;
if ( V_5 -> V_22 . V_30 > V_60 . V_30 ) {
F_2 ( V_11 , L_14 ,
V_5 -> V_16 , F_5 ( V_5 -> V_17 ) ,
F_5 ( V_5 -> V_22 ) ) ;
break;
}
V_2 -> V_14 = F_11 ( & V_5 -> V_15 ) ;
F_13 ( & V_5 -> V_15 , & V_2 -> V_7 ) ;
F_14 ( & V_5 -> V_15 ) ;
F_2 ( V_63 , L_15 ,
V_5 -> type , V_5 -> V_16 ,
F_5 ( V_5 -> V_17 ) ,
F_5 ( V_5 -> V_22 ) ) ;
F_21 ( & V_37 , V_36 ) ;
V_5 -> V_16 ( V_5 ) ;
F_20 ( & V_37 , V_36 ) ;
}
if ( ! V_2 -> V_14 )
F_2 ( V_11 , L_16 , V_2 - V_7 ) ;
F_1 ( V_2 , true ) ;
F_21 ( & V_37 , V_36 ) ;
return V_64 ;
}
static void F_41 ( void * V_65 )
{
struct V_66 * V_67 = V_59 ;
if ( ! ( V_67 -> V_68 & V_69 ) )
return;
F_2 ( INT , L_17 ) ;
F_6 ( & V_13 , 1 * V_18 ) ;
}
static int F_42 ( struct V_70 * V_71 , T_2 V_72 )
{
int V_58 = 0 ;
unsigned long V_36 ;
struct V_73 V_74 ;
struct V_42 V_75 ;
unsigned long V_76 ;
unsigned long V_77 ;
struct V_39 V_78 ;
struct V_39 V_79 ;
struct V_1 * V_80 = NULL ;
struct V_1 * V_81 = NULL ;
F_2 ( V_82 , L_18 , V_71 , V_72 . V_83 ) ;
F_20 ( & V_37 , V_36 ) ;
V_12 = true ;
F_21 ( & V_37 , V_36 ) ;
F_43 ( & V_7 [ V_8 ] . V_19 ) ;
F_43 ( & V_7 [
V_9 ] . V_19 ) ;
V_81 = & V_7 [ V_8 ] ;
if ( V_81 -> V_14 )
V_80 = V_81 ;
V_81 = & V_7 [ V_9 ] ;
if ( V_81 -> V_14 && ( ! V_80 ||
F_44 ( & V_81 -> V_19 ) . V_30 <
F_44 ( & V_80 -> V_19 ) . V_30 ) )
V_80 = V_81 ;
if ( V_80 ) {
F_45 ( V_59 , & V_75 ) ;
F_30 ( & V_79 ) ;
F_46 ( & V_75 , & V_76 ) ;
F_47 ( & V_78 ,
V_79 . V_45 - V_76 ,
V_79 . V_47 ) ;
V_77 = F_33 ( F_48 (
F_44 ( & V_80 -> V_19 ) ) ,
V_78 ) . V_45 ;
F_27 ( V_77 , & V_74 . time ) ;
V_74 . V_84 = 1 ;
F_49 ( V_59 , & V_74 ) ;
F_45 ( V_59 , & V_75 ) ;
F_46 ( & V_75 , & V_76 ) ;
F_2 ( V_82 ,
L_19 ,
V_77 , V_76 ,
V_78 . V_45 , V_78 . V_47 ) ;
if ( V_76 + 1 >= V_77 ) {
F_2 ( V_82 , L_20 ) ;
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_74 . V_84 = 0 ;
F_49 ( V_59 , & V_74 ) ;
F_20 ( & V_37 , V_36 ) ;
V_12 = false ;
F_6 ( & V_13 , 2 * V_18 ) ;
F_1 ( & V_7 [ V_8 ] ,
false ) ;
F_1 ( & V_7 [
V_9 ] , false ) ;
V_58 = - V_85 ;
F_21 ( & V_37 , V_36 ) ;
}
}
return V_58 ;
}
static int F_50 ( struct V_70 * V_71 )
{
struct V_73 V_5 ;
unsigned long V_36 ;
F_2 ( V_82 , L_21 , V_71 ) ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
V_5 . V_84 = 0 ;
F_49 ( V_59 , & V_5 ) ;
F_20 ( & V_37 , V_36 ) ;
V_12 = false ;
F_1 ( & V_7 [ V_8 ] , false ) ;
F_1 ( & V_7 [ V_9 ] ,
false ) ;
F_21 ( & V_37 , V_36 ) ;
return 0 ;
}
static int F_51 ( struct V_86 * V_87 ,
struct V_88 * V_89 )
{
int V_58 ;
struct V_66 * V_67 = F_52 ( V_87 ) ;
F_28 ( & V_54 ) ;
if ( V_59 ) {
V_58 = - V_85 ;
goto V_90;
}
V_91 =
F_53 ( L_22 , - 1 , NULL , 0 ) ;
if ( F_54 ( V_91 ) ) {
V_58 = F_55 ( V_91 ) ;
goto V_92;
}
V_58 = F_56 ( V_67 , & V_93 ) ;
if ( V_58 )
goto V_94;
V_59 = V_67 ;
F_2 ( V_95 , L_23 , V_67 -> V_96 ) ;
F_36 ( & V_54 ) ;
return 0 ;
V_94:
F_57 ( V_91 ) ;
V_92:
V_90:
F_36 ( & V_54 ) ;
return V_58 ;
}
static void F_58 ( struct V_86 * V_87 ,
struct V_88 * V_89 )
{
if ( V_87 == & V_59 -> V_87 ) {
F_2 ( V_95 , L_24 ) ;
F_59 ( V_59 , & V_93 ) ;
F_57 ( V_91 ) ;
V_59 = NULL ;
}
}
static int T_3 F_60 ( void )
{
unsigned long V_36 ;
struct V_39 V_44 , V_97 ;
F_20 ( & V_37 , V_36 ) ;
F_30 ( & V_44 ) ;
F_61 ( & V_97 ) ;
V_7 [ V_9 ] . V_20 =
V_7 [ V_57 ] . V_20 =
F_31 ( F_33 ( V_44 , V_97 ) ) ;
F_21 ( & V_37 , V_36 ) ;
return 0 ;
}
static int T_3 F_62 ( void )
{
int V_58 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_55 ; V_41 ++ ) {
F_63 ( & V_7 [ V_41 ] . V_19 ,
V_98 , V_23 ) ;
V_7 [ V_41 ] . V_19 . V_16 = F_39 ;
}
F_63 ( & V_7 [ V_55 ] . V_19 ,
V_99 , V_23 ) ;
V_7 [ V_55 ] . V_19 . V_16 = F_39 ;
V_58 = F_64 ( & V_100 ) ;
if ( V_58 < 0 )
goto V_90;
F_65 ( & V_13 , V_101 , L_25 ) ;
V_102 . V_103 = V_104 ;
V_58 = F_66 ( & V_102 ) ;
if ( V_58 < 0 )
goto V_92;
return 0 ;
V_92:
F_67 ( & V_13 ) ;
F_68 ( & V_100 ) ;
V_90:
return V_58 ;
}
static void T_4 F_69 ( void )
{
F_70 ( & V_102 ) ;
F_67 ( & V_13 ) ;
F_68 ( & V_100 ) ;
}
