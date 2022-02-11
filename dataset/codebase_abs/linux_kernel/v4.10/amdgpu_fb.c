static int
F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
int V_9 = F_2 ( V_8 -> V_10 -> V_11 ) ;
if ( V_9 < 0 && V_9 != - V_12 ) {
F_3 ( V_8 -> V_10 -> V_11 ) ;
F_4 ( V_8 -> V_10 -> V_11 ) ;
return V_9 ;
}
return 0 ;
}
static int
F_5 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
F_3 ( V_8 -> V_10 -> V_11 ) ;
F_4 ( V_8 -> V_10 -> V_11 ) ;
return 0 ;
}
int F_6 ( struct V_7 * V_8 , int V_13 , int V_14 , bool V_15 )
{
int V_16 = V_13 ;
int V_17 = 0 ;
switch ( V_14 ) {
case 1 :
V_17 = 255 ;
break;
case 2 :
V_17 = 127 ;
break;
case 3 :
case 4 :
V_17 = 63 ;
break;
}
V_16 += V_17 ;
V_16 &= ~ V_17 ;
return V_16 * V_14 ;
}
static void F_7 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = F_8 ( V_19 ) ;
int V_9 ;
V_9 = F_9 ( V_21 , false ) ;
if ( F_10 ( V_9 == 0 ) ) {
F_11 ( V_21 ) ;
F_12 ( V_21 ) ;
F_13 ( V_21 ) ;
}
F_14 ( V_19 ) ;
}
static int F_15 ( struct V_4 * V_5 ,
struct V_22 * V_23 ,
struct V_18 * * V_24 )
{
struct V_7 * V_8 = V_5 -> V_8 ;
struct V_18 * V_19 = NULL ;
struct V_20 * V_21 = NULL ;
bool V_25 = false ;
T_1 V_26 = 0 ;
int V_9 ;
int V_27 , V_28 ;
int V_29 = V_23 -> V_29 ;
T_1 V_14 ;
V_14 = F_16 ( V_23 -> V_30 , 0 ) ;
V_23 -> V_31 [ 0 ] = F_6 ( V_8 , V_23 -> V_13 , V_14 ,
V_25 ) ;
V_29 = F_17 ( V_23 -> V_29 , 8 ) ;
V_28 = V_23 -> V_31 [ 0 ] * V_29 ;
V_27 = F_17 ( V_28 , V_32 ) ;
V_9 = F_18 ( V_8 , V_27 , 0 ,
V_33 ,
V_34 |
V_35 ,
true , & V_19 ) ;
if ( V_9 ) {
F_19 ( V_36 L_1 ,
V_27 ) ;
return - V_37 ;
}
V_21 = F_8 ( V_19 ) ;
if ( V_25 )
V_26 = F_20 ( V_38 , V_39 ) ;
V_9 = F_9 ( V_21 , false ) ;
if ( F_21 ( V_9 != 0 ) )
goto V_40;
if ( V_26 ) {
V_9 = F_22 ( V_21 ,
V_26 ) ;
if ( V_9 )
F_23 ( V_8 -> V_11 , L_2 ) ;
}
V_9 = F_24 ( V_21 , V_33 , NULL ) ;
if ( V_9 ) {
F_13 ( V_21 ) ;
goto V_40;
}
V_9 = F_25 ( V_21 , NULL ) ;
F_13 ( V_21 ) ;
if ( V_9 ) {
goto V_40;
}
* V_24 = V_19 ;
return 0 ;
V_40:
F_7 ( V_19 ) ;
* V_24 = NULL ;
return V_9 ;
}
static int F_26 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
struct V_4 * V_5 = (struct V_4 * ) V_42 ;
struct V_7 * V_8 = V_5 -> V_8 ;
struct V_1 * V_2 ;
struct V_45 * V_46 = NULL ;
struct V_22 V_23 ;
struct V_18 * V_19 = NULL ;
struct V_20 * V_21 = NULL ;
int V_9 ;
unsigned long V_47 ;
V_23 . V_13 = V_44 -> V_48 ;
V_23 . V_29 = V_44 -> V_49 ;
if ( V_44 -> V_50 == 24 )
V_44 -> V_50 = 32 ;
V_23 . V_30 = F_27 ( V_44 -> V_50 ,
V_44 -> V_51 ) ;
V_9 = F_15 ( V_5 , & V_23 , & V_19 ) ;
if ( V_9 ) {
F_28 ( L_3 , V_9 ) ;
return V_9 ;
}
V_21 = F_8 ( V_19 ) ;
V_2 = F_29 ( V_42 ) ;
if ( F_30 ( V_2 ) ) {
V_9 = F_31 ( V_2 ) ;
goto V_40;
}
V_2 -> V_6 = V_5 ;
V_2 -> V_52 = true ;
V_9 = F_32 ( V_8 -> V_10 , & V_5 -> V_53 , & V_23 , V_19 ) ;
if ( V_9 ) {
F_28 ( L_4 , V_9 ) ;
goto V_54;
}
V_46 = & V_5 -> V_53 . V_55 ;
V_5 -> V_42 . V_46 = V_46 ;
F_33 ( V_21 -> V_56 , 0x0 , F_34 ( V_21 ) ) ;
strcpy ( V_2 -> V_57 . V_58 , L_5 ) ;
F_35 ( V_2 , V_46 -> V_31 [ 0 ] , V_46 -> V_59 ) ;
V_2 -> V_60 = V_61 | V_62 ;
V_2 -> V_63 = & V_64 ;
V_47 = F_36 ( V_21 ) - V_8 -> V_65 . V_66 ;
V_2 -> V_57 . V_67 = V_8 -> V_65 . V_68 + V_47 ;
V_2 -> V_57 . V_69 = F_34 ( V_21 ) ;
V_2 -> V_70 = V_21 -> V_56 ;
V_2 -> V_71 = F_34 ( V_21 ) ;
F_37 ( V_2 , & V_5 -> V_42 , V_44 -> V_72 , V_44 -> V_73 ) ;
V_2 -> V_74 -> V_75 [ 0 ] . V_55 = V_8 -> V_10 -> V_76 . V_77 ;
V_2 -> V_74 -> V_75 [ 0 ] . V_28 = V_8 -> V_65 . V_78 ;
if ( V_2 -> V_70 == NULL ) {
V_9 = - V_79 ;
goto V_54;
}
F_38 ( L_6 , V_2 -> V_57 . V_67 ) ;
F_38 ( L_7 , ( unsigned long ) V_8 -> V_65 . V_68 ) ;
F_38 ( L_8 , ( unsigned long ) F_34 ( V_21 ) ) ;
F_38 ( L_9 , V_46 -> V_59 ) ;
F_38 ( L_10 , V_46 -> V_31 [ 0 ] ) ;
F_39 ( V_8 -> V_10 -> V_80 , V_2 ) ;
return 0 ;
V_54:
F_40 ( V_42 ) ;
V_40:
if ( V_21 ) {
}
if ( V_46 && V_9 ) {
F_14 ( V_19 ) ;
F_41 ( V_46 ) ;
F_42 ( V_46 ) ;
F_43 ( V_46 ) ;
}
return V_9 ;
}
void F_44 ( struct V_7 * V_8 )
{
if ( V_8 -> V_81 . V_5 )
F_45 ( & V_8 -> V_81 . V_5 -> V_42 ) ;
}
static int F_46 ( struct V_82 * V_11 , struct V_4 * V_5 )
{
struct V_83 * V_53 = & V_5 -> V_53 ;
F_47 ( & V_5 -> V_42 ) ;
F_40 ( & V_5 -> V_42 ) ;
if ( V_53 -> V_84 ) {
F_7 ( V_53 -> V_84 ) ;
V_53 -> V_84 = NULL ;
}
F_48 ( & V_5 -> V_42 ) ;
F_41 ( & V_53 -> V_55 ) ;
F_42 ( & V_53 -> V_55 ) ;
return 0 ;
}
static void F_49 ( struct V_85 * V_86 , T_2 V_87 , T_2 V_88 ,
T_2 V_89 , int V_90 )
{
struct V_91 * V_91 = F_50 ( V_86 ) ;
V_91 -> V_92 [ V_90 ] = V_87 >> 6 ;
V_91 -> V_93 [ V_90 ] = V_88 >> 6 ;
V_91 -> V_94 [ V_90 ] = V_89 >> 6 ;
}
static void F_51 ( struct V_85 * V_86 , T_2 * V_87 , T_2 * V_88 ,
T_2 * V_89 , int V_90 )
{
struct V_91 * V_91 = F_50 ( V_86 ) ;
* V_87 = V_91 -> V_92 [ V_90 ] << 6 ;
* V_88 = V_91 -> V_93 [ V_90 ] << 6 ;
* V_89 = V_91 -> V_94 [ V_90 ] << 6 ;
}
int F_52 ( struct V_7 * V_8 )
{
struct V_4 * V_5 ;
int V_95 = 32 ;
int V_9 ;
if ( ! V_8 -> V_81 . V_96 )
return 0 ;
if ( F_53 ( & V_8 -> V_10 -> V_76 . V_97 ) )
return 0 ;
if ( V_8 -> V_65 . V_98 <= ( 32 * 1024 * 1024 ) )
V_95 = 8 ;
V_5 = F_54 ( sizeof( struct V_4 ) , V_99 ) ;
if ( ! V_5 )
return - V_37 ;
V_5 -> V_8 = V_8 ;
V_8 -> V_81 . V_5 = V_5 ;
F_55 ( V_8 -> V_10 , & V_5 -> V_42 ,
& V_100 ) ;
V_9 = F_56 ( V_8 -> V_10 , & V_5 -> V_42 ,
V_8 -> V_81 . V_101 ,
V_102 ) ;
if ( V_9 ) {
F_43 ( V_5 ) ;
return V_9 ;
}
F_57 ( & V_5 -> V_42 ) ;
F_58 ( V_8 -> V_10 ) ;
F_59 ( & V_5 -> V_42 , V_95 ) ;
return 0 ;
}
void F_60 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_81 . V_5 )
return;
F_46 ( V_8 -> V_10 , V_8 -> V_81 . V_5 ) ;
F_43 ( V_8 -> V_81 . V_5 ) ;
V_8 -> V_81 . V_5 = NULL ;
}
void F_61 ( struct V_7 * V_8 , int V_103 )
{
if ( V_8 -> V_81 . V_5 )
F_62 ( & V_8 -> V_81 . V_5 -> V_42 ,
V_103 ) ;
}
int F_63 ( struct V_7 * V_8 )
{
struct V_20 * V_104 ;
int V_28 = 0 ;
if ( ! V_8 -> V_81 . V_5 )
return 0 ;
V_104 = F_8 ( V_8 -> V_81 . V_5 -> V_53 . V_84 ) ;
V_28 += F_34 ( V_104 ) ;
return V_28 ;
}
bool F_64 ( struct V_7 * V_8 , struct V_20 * V_104 )
{
if ( ! V_8 -> V_81 . V_5 )
return false ;
if ( V_104 == F_8 ( V_8 -> V_81 . V_5 -> V_53 . V_84 ) )
return true ;
return false ;
}
void F_65 ( struct V_7 * V_8 )
{
struct V_4 * V_105 = V_8 -> V_81 . V_5 ;
struct V_41 * V_106 ;
int V_9 ;
if ( ! V_105 )
return;
V_106 = & V_105 -> V_42 ;
V_9 = F_66 ( V_106 ) ;
if ( V_9 )
F_67 ( L_11 ) ;
}
