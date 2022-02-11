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
T_1 V_4 , V_24 ;
F_12 ( V_17 -> V_25 , & V_24 , & V_4 ) ;
V_17 -> V_26 [ 0 ] = F_1 ( V_2 , V_17 -> V_3 , V_4 ,
V_19 ) * ( ( V_4 + 1 ) / 8 ) ;
if ( V_2 -> V_27 >= V_28 )
V_23 = F_13 ( V_17 -> V_23 , 8 ) ;
V_22 = V_17 -> V_26 [ 0 ] * V_23 ;
V_21 = F_13 ( V_22 , V_29 ) ;
V_13 = F_14 ( V_2 , V_21 , 0 ,
V_30 ,
0 , true , & V_10 ) ;
if ( V_13 ) {
F_15 ( V_31 L_1 ,
V_21 ) ;
return - V_32 ;
}
V_12 = F_4 ( V_10 ) ;
if ( V_19 )
V_20 = V_33 ;
#ifdef F_16
switch ( V_4 ) {
case 32 :
V_20 |= V_34 ;
break;
case 16 :
V_20 |= V_35 ;
default:
break;
}
#endif
if ( V_20 ) {
V_13 = F_17 ( V_12 ,
V_20 | V_36 ,
V_17 -> V_26 [ 0 ] ) ;
if ( V_13 )
F_18 ( V_2 -> V_37 , L_2 ) ;
}
V_13 = F_5 ( V_12 , false ) ;
if ( F_19 ( V_13 != 0 ) )
goto V_38;
V_13 = F_20 ( V_12 , V_30 ,
F_2 ( V_2 ) ? 0 : 1 << 27 ,
NULL ) ;
if ( V_13 ) {
F_9 ( V_12 ) ;
goto V_38;
}
if ( V_19 )
F_21 ( V_12 , 0 , 0 ) ;
V_13 = F_22 ( V_12 , NULL ) ;
F_9 ( V_12 ) ;
if ( V_13 ) {
goto V_38;
}
* V_18 = V_10 ;
return 0 ;
V_38:
F_3 ( V_10 ) ;
* V_18 = NULL ;
return V_13 ;
}
static int F_23 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_14 * V_15 =
F_24 ( V_40 , struct V_14 , V_40 ) ;
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_43 * V_44 ;
struct V_45 * V_46 = NULL ;
struct V_16 V_17 ;
struct V_9 * V_10 = NULL ;
struct V_11 * V_12 = NULL ;
int V_13 ;
unsigned long V_47 ;
V_17 . V_3 = V_42 -> V_48 ;
V_17 . V_23 = V_42 -> V_49 ;
if ( ( V_42 -> V_50 == 24 ) && F_2 ( V_2 ) )
V_42 -> V_50 = 32 ;
V_17 . V_25 = F_25 ( V_42 -> V_50 ,
V_42 -> V_51 ) ;
V_13 = F_11 ( V_15 , & V_17 , & V_10 ) ;
if ( V_13 ) {
F_26 ( L_3 , V_13 ) ;
return V_13 ;
}
V_12 = F_4 ( V_10 ) ;
V_44 = F_27 ( V_40 ) ;
if ( F_28 ( V_44 ) ) {
V_13 = F_29 ( V_44 ) ;
goto V_38;
}
V_44 -> V_52 = V_15 ;
V_44 -> V_53 = true ;
V_13 = F_30 ( V_2 -> V_54 , & V_15 -> V_55 , & V_17 , V_10 ) ;
if ( V_13 ) {
F_26 ( L_4 , V_13 ) ;
goto V_56;
}
V_46 = & V_15 -> V_55 . V_57 ;
V_15 -> V_40 . V_46 = V_46 ;
F_31 ( V_12 -> V_58 , 0x0 , F_32 ( V_12 ) ) ;
strcpy ( V_44 -> V_59 . V_60 , L_5 ) ;
F_33 ( V_44 , V_46 -> V_26 [ 0 ] , V_46 -> V_24 ) ;
V_44 -> V_61 = V_62 | V_63 ;
V_44 -> V_64 = & V_65 ;
V_47 = F_34 ( V_12 ) - V_2 -> V_66 . V_67 ;
V_44 -> V_59 . V_68 = V_2 -> V_66 . V_69 + V_47 ;
V_44 -> V_59 . V_70 = F_32 ( V_12 ) ;
V_44 -> V_71 = V_12 -> V_58 ;
V_44 -> V_72 = F_32 ( V_12 ) ;
F_35 ( V_44 , & V_15 -> V_40 , V_42 -> V_73 , V_42 -> V_74 ) ;
V_44 -> V_75 -> V_76 [ 0 ] . V_57 = V_2 -> V_54 -> V_77 . V_78 ;
V_44 -> V_75 -> V_76 [ 0 ] . V_22 = V_2 -> V_66 . V_79 ;
if ( V_44 -> V_71 == NULL ) {
V_13 = - V_80 ;
goto V_56;
}
F_36 ( L_6 , V_44 -> V_59 . V_68 ) ;
F_36 ( L_7 , ( unsigned long ) V_2 -> V_66 . V_69 ) ;
F_36 ( L_8 , ( unsigned long ) F_32 ( V_12 ) ) ;
F_36 ( L_9 , V_46 -> V_24 ) ;
F_36 ( L_10 , V_46 -> V_26 [ 0 ] ) ;
F_37 ( V_2 -> V_54 -> V_81 , V_44 ) ;
return 0 ;
V_56:
F_38 ( V_40 ) ;
V_38:
if ( V_12 ) {
}
if ( V_46 && V_13 ) {
F_39 ( V_10 ) ;
F_40 ( V_46 ) ;
F_41 ( V_46 ) ;
F_42 ( V_46 ) ;
}
return V_13 ;
}
void F_43 ( struct V_1 * V_2 )
{
F_44 ( & V_2 -> V_82 . V_15 -> V_40 ) ;
}
static int F_45 ( struct V_83 * V_37 , struct V_14 * V_15 )
{
struct V_84 * V_55 = & V_15 -> V_55 ;
F_46 ( & V_15 -> V_40 ) ;
F_38 ( & V_15 -> V_40 ) ;
if ( V_55 -> V_85 ) {
F_3 ( V_55 -> V_85 ) ;
V_55 -> V_85 = NULL ;
}
F_47 ( & V_15 -> V_40 ) ;
F_40 ( & V_55 -> V_57 ) ;
F_41 ( & V_55 -> V_57 ) ;
return 0 ;
}
int F_48 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
int V_86 = 32 ;
int V_13 ;
if ( F_49 ( V_2 ) || V_2 -> V_66 . V_87 <= ( 32 * 1024 * 1024 ) )
V_86 = 8 ;
V_15 = F_50 ( sizeof( struct V_14 ) , V_88 ) ;
if ( ! V_15 )
return - V_32 ;
V_15 -> V_2 = V_2 ;
V_2 -> V_82 . V_15 = V_15 ;
F_51 ( V_2 -> V_54 , & V_15 -> V_40 ,
& V_89 ) ;
V_13 = F_52 ( V_2 -> V_54 , & V_15 -> V_40 ,
V_2 -> V_90 ,
V_91 ) ;
if ( V_13 )
goto free;
V_13 = F_53 ( & V_15 -> V_40 ) ;
if ( V_13 )
goto V_92;
F_54 ( V_2 -> V_54 ) ;
V_13 = F_55 ( & V_15 -> V_40 , V_86 ) ;
if ( V_13 )
goto V_92;
return 0 ;
V_92:
F_47 ( & V_15 -> V_40 ) ;
free:
F_42 ( V_15 ) ;
return V_13 ;
}
void F_56 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_82 . V_15 )
return;
F_45 ( V_2 -> V_54 , V_2 -> V_82 . V_15 ) ;
F_42 ( V_2 -> V_82 . V_15 ) ;
V_2 -> V_82 . V_15 = NULL ;
}
void F_57 ( struct V_1 * V_2 , int V_93 )
{
F_58 ( V_2 -> V_82 . V_15 -> V_40 . V_94 , V_93 ) ;
}
bool F_59 ( struct V_1 * V_2 , struct V_11 * V_95 )
{
if ( V_95 == F_4 ( V_2 -> V_82 . V_15 -> V_55 . V_85 ) )
return true ;
return false ;
}
void F_60 ( struct V_1 * V_2 , struct V_96 * V_97 )
{
F_61 ( & V_2 -> V_82 . V_15 -> V_40 , V_97 ) ;
}
void F_62 ( struct V_1 * V_2 , struct V_96 * V_97 )
{
F_63 ( & V_2 -> V_82 . V_15 -> V_40 , V_97 ) ;
}
void F_64 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_82 . V_15 ;
struct V_39 * V_98 ;
int V_13 ;
if ( ! V_15 )
return;
V_98 = & V_15 -> V_40 ;
V_13 = F_65 ( V_98 ) ;
if ( V_13 )
F_66 ( L_11 ) ;
}
