int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 , bool V_5 )
{
int V_6 = V_3 ;
int V_7 = ( F_2 ( V_2 ) ) || V_5 ;
int V_8 = 0 ;
switch ( V_4 / 8 ) {
case 1 :
V_8 = V_7 ? 255 : 127 ;
break;
case 2 :
V_8 = V_7 ? 127 : 31 ;
break;
case 3 :
case 4 :
V_8 = V_7 ? 63 : 15 ;
break;
}
V_6 += V_8 ;
V_6 &= ~ V_8 ;
return V_6 ;
}
static void F_3 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
int V_13 ;
V_13 = F_5 ( V_12 , false ) ;
if ( F_6 ( V_13 == 0 ) ) {
F_7 ( V_12 ) ;
F_8 ( V_12 ) ;
F_9 ( V_12 ) ;
}
F_10 ( V_10 ) ;
}
static int F_11 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
struct V_9 * * V_18 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_9 * V_10 = NULL ;
struct V_11 * V_12 = NULL ;
bool V_19 = false ;
T_1 V_20 = 0 ;
int V_13 ;
int V_21 , V_22 ;
int V_23 = V_17 -> V_23 ;
V_17 -> V_24 = F_1 ( V_2 , V_17 -> V_3 , V_17 -> V_4 , V_19 ) * ( ( V_17 -> V_4 + 1 ) / 8 ) ;
if ( V_2 -> V_25 >= V_26 )
V_23 = F_12 ( V_17 -> V_23 , 8 ) ;
V_22 = V_17 -> V_24 * V_23 ;
V_21 = F_12 ( V_22 , V_27 ) ;
V_13 = F_13 ( V_2 , V_21 , 0 ,
V_28 ,
false , true ,
& V_10 ) ;
if ( V_13 ) {
F_14 ( V_29 L_1 ,
V_21 ) ;
return - V_30 ;
}
V_12 = F_4 ( V_10 ) ;
if ( V_19 )
V_20 = V_31 ;
#ifdef F_15
switch ( V_17 -> V_4 ) {
case 32 :
V_20 |= V_32 ;
break;
case 16 :
V_20 |= V_33 ;
default:
break;
}
#endif
if ( V_20 ) {
V_13 = F_16 ( V_12 ,
V_20 | V_34 ,
V_17 -> V_24 ) ;
if ( V_13 )
F_17 ( V_2 -> V_35 , L_2 ) ;
}
V_13 = F_5 ( V_12 , false ) ;
if ( F_18 ( V_13 != 0 ) )
goto V_36;
V_13 = F_19 ( V_12 , V_28 , NULL ) ;
if ( V_13 ) {
F_9 ( V_12 ) ;
goto V_36;
}
if ( V_19 )
F_20 ( V_12 , 0 , 0 ) ;
V_13 = F_21 ( V_12 , NULL ) ;
F_9 ( V_12 ) ;
if ( V_13 ) {
goto V_36;
}
* V_18 = V_10 ;
return 0 ;
V_36:
F_3 ( V_10 ) ;
* V_18 = NULL ;
return V_13 ;
}
static int F_22 ( struct V_14 * V_15 ,
struct V_37 * V_38 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_39 * V_40 ;
struct V_41 * V_42 = NULL ;
struct V_16 V_17 ;
struct V_9 * V_10 = NULL ;
struct V_11 * V_12 = NULL ;
struct V_43 * V_43 = & V_2 -> V_44 -> V_35 ;
int V_13 ;
unsigned long V_45 ;
V_17 . V_3 = V_38 -> V_46 ;
V_17 . V_23 = V_38 -> V_47 ;
if ( ( V_38 -> V_48 == 24 ) && F_2 ( V_2 ) )
V_38 -> V_48 = 32 ;
V_17 . V_4 = V_38 -> V_48 ;
V_17 . V_49 = V_38 -> V_50 ;
V_13 = F_11 ( V_15 , & V_17 , & V_10 ) ;
V_12 = F_4 ( V_10 ) ;
V_40 = F_23 ( 0 , V_43 ) ;
if ( V_40 == NULL ) {
V_13 = - V_30 ;
goto V_36;
}
V_40 -> V_51 = V_15 ;
F_24 ( V_2 -> V_52 , & V_15 -> V_53 , & V_17 , V_10 ) ;
V_42 = & V_15 -> V_53 . V_54 ;
V_15 -> V_55 . V_42 = V_42 ;
V_15 -> V_55 . V_56 = V_40 ;
F_25 ( V_12 -> V_57 , 0x0 , F_26 ( V_12 ) ) ;
strcpy ( V_40 -> V_58 . V_59 , L_3 ) ;
F_27 ( V_40 , V_42 -> V_24 , V_42 -> V_49 ) ;
V_40 -> V_60 = V_61 | V_62 ;
V_40 -> V_63 = & V_64 ;
V_45 = F_28 ( V_12 ) - V_2 -> V_65 . V_66 ;
V_40 -> V_58 . V_67 = V_2 -> V_65 . V_68 + V_45 ;
V_40 -> V_58 . V_69 = F_26 ( V_12 ) ;
V_40 -> V_70 = V_12 -> V_57 ;
V_40 -> V_71 = F_26 ( V_12 ) ;
F_29 ( V_40 , & V_15 -> V_55 , V_38 -> V_72 , V_38 -> V_73 ) ;
V_40 -> V_74 = F_30 ( 1 ) ;
if ( ! V_40 -> V_74 ) {
V_13 = - V_30 ;
goto V_36;
}
V_40 -> V_74 -> V_75 [ 0 ] . V_54 = V_2 -> V_52 -> V_76 . V_77 ;
V_40 -> V_74 -> V_75 [ 0 ] . V_22 = V_2 -> V_65 . V_78 ;
V_40 -> V_79 . V_22 = 64 * 1024 ;
V_40 -> V_79 . V_80 = 8 ;
V_40 -> V_79 . V_81 = 32 ;
V_40 -> V_79 . V_60 = V_82 ;
V_40 -> V_79 . V_83 = 1 ;
if ( V_40 -> V_70 == NULL ) {
V_13 = - V_84 ;
goto V_36;
}
V_13 = F_31 ( & V_40 -> V_85 , 256 , 0 ) ;
if ( V_13 ) {
V_13 = - V_30 ;
goto V_36;
}
F_32 ( L_4 , V_40 -> V_58 . V_67 ) ;
F_32 ( L_5 , ( unsigned long ) V_2 -> V_65 . V_68 ) ;
F_32 ( L_6 , ( unsigned long ) F_26 ( V_12 ) ) ;
F_32 ( L_7 , V_42 -> V_49 ) ;
F_32 ( L_8 , V_42 -> V_24 ) ;
F_33 ( V_2 -> V_52 -> V_44 , V_40 ) ;
return 0 ;
V_36:
if ( V_12 ) {
}
if ( V_42 && V_13 ) {
F_34 ( V_10 ) ;
F_35 ( V_42 ) ;
F_36 ( V_42 ) ;
}
return V_13 ;
}
static int F_37 ( struct V_86 * V_55 ,
struct V_37 * V_38 )
{
struct V_14 * V_15 = (struct V_14 * ) V_55 ;
int V_87 = 0 ;
int V_13 ;
if ( ! V_55 -> V_42 ) {
V_13 = F_22 ( V_15 , V_38 ) ;
if ( V_13 )
return V_13 ;
V_87 = 1 ;
}
return V_87 ;
}
int F_38 ( char * V_88 )
{
char * V_89 ;
if ( ! V_88 || ! * V_88 )
return 0 ;
while ( ( V_89 = F_39 ( & V_88 , L_9 ) ) != NULL ) {
if ( ! * V_89 )
continue;
V_90 = V_89 ;
}
return 0 ;
}
void F_40 ( struct V_1 * V_2 )
{
F_41 ( & V_2 -> V_91 . V_15 -> V_55 ) ;
}
static int F_42 ( struct V_92 * V_35 , struct V_14 * V_15 )
{
struct V_39 * V_40 ;
struct V_93 * V_53 = & V_15 -> V_53 ;
if ( V_15 -> V_55 . V_56 ) {
V_40 = V_15 -> V_55 . V_56 ;
F_43 ( V_40 ) ;
if ( V_40 -> V_85 . V_94 )
F_44 ( & V_40 -> V_85 ) ;
F_45 ( V_40 ) ;
}
if ( V_53 -> V_95 ) {
F_3 ( V_53 -> V_95 ) ;
V_53 -> V_95 = NULL ;
}
F_46 ( & V_15 -> V_55 ) ;
F_35 ( & V_53 -> V_54 ) ;
return 0 ;
}
int F_47 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
int V_96 = 32 ;
int V_13 ;
if ( F_48 ( V_2 ) || V_2 -> V_65 . V_97 <= ( 32 * 1024 * 1024 ) )
V_96 = 8 ;
V_15 = F_49 ( sizeof( struct V_14 ) , V_98 ) ;
if ( ! V_15 )
return - V_30 ;
V_15 -> V_2 = V_2 ;
V_2 -> V_91 . V_15 = V_15 ;
V_15 -> V_55 . V_99 = & V_100 ;
V_13 = F_50 ( V_2 -> V_52 , & V_15 -> V_55 ,
V_2 -> V_101 ,
V_102 ) ;
if ( V_13 ) {
F_36 ( V_15 ) ;
return V_13 ;
}
F_51 ( & V_15 -> V_55 ) ;
F_52 ( & V_15 -> V_55 , V_96 ) ;
return 0 ;
}
void F_53 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_91 . V_15 )
return;
F_42 ( V_2 -> V_52 , V_2 -> V_91 . V_15 ) ;
F_36 ( V_2 -> V_91 . V_15 ) ;
V_2 -> V_91 . V_15 = NULL ;
}
void F_54 ( struct V_1 * V_2 , int V_103 )
{
F_55 ( V_2 -> V_91 . V_15 -> V_55 . V_56 , V_103 ) ;
}
int F_56 ( struct V_1 * V_2 )
{
struct V_11 * V_104 ;
int V_22 = 0 ;
V_104 = F_4 ( V_2 -> V_91 . V_15 -> V_53 . V_95 ) ;
V_22 += F_26 ( V_104 ) ;
return V_22 ;
}
bool F_57 ( struct V_1 * V_2 , struct V_11 * V_104 )
{
if ( V_104 == F_4 ( V_2 -> V_91 . V_15 -> V_53 . V_95 ) )
return true ;
return false ;
}
