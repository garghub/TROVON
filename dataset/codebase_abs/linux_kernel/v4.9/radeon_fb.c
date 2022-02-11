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
int V_17 = ( F_7 ( V_8 ) ) || V_15 ;
int V_18 = 0 ;
switch ( V_14 / 8 ) {
case 1 :
V_18 = V_17 ? 255 : 127 ;
break;
case 2 :
V_18 = V_17 ? 127 : 31 ;
break;
case 3 :
case 4 :
V_18 = V_17 ? 63 : 15 ;
break;
}
V_16 += V_18 ;
V_16 &= ~ V_18 ;
return V_16 ;
}
static void F_8 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = F_9 ( V_20 ) ;
int V_9 ;
V_9 = F_10 ( V_22 , false ) ;
if ( F_11 ( V_9 == 0 ) ) {
F_12 ( V_22 ) ;
F_13 ( V_22 ) ;
F_14 ( V_22 ) ;
}
F_15 ( V_20 ) ;
}
static int F_16 ( struct V_4 * V_5 ,
struct V_23 * V_24 ,
struct V_19 * * V_25 )
{
struct V_7 * V_8 = V_5 -> V_8 ;
struct V_19 * V_20 = NULL ;
struct V_21 * V_22 = NULL ;
bool V_26 = false ;
T_1 V_27 = 0 ;
int V_9 ;
int V_28 , V_29 ;
int V_30 = V_24 -> V_30 ;
T_1 V_14 , V_31 ;
F_17 ( V_24 -> V_32 , & V_31 , & V_14 ) ;
V_24 -> V_33 [ 0 ] = F_6 ( V_8 , V_24 -> V_13 , V_14 ,
V_26 ) * ( ( V_14 + 1 ) / 8 ) ;
if ( V_8 -> V_34 >= V_35 )
V_30 = F_18 ( V_24 -> V_30 , 8 ) ;
V_29 = V_24 -> V_33 [ 0 ] * V_30 ;
V_28 = F_18 ( V_29 , V_36 ) ;
V_9 = F_19 ( V_8 , V_28 , 0 ,
V_37 ,
0 , true , & V_20 ) ;
if ( V_9 ) {
F_20 ( V_38 L_1 ,
V_28 ) ;
return - V_39 ;
}
V_22 = F_9 ( V_20 ) ;
if ( V_26 )
V_27 = V_40 ;
#ifdef F_21
switch ( V_14 ) {
case 32 :
V_27 |= V_41 ;
break;
case 16 :
V_27 |= V_42 ;
default:
break;
}
#endif
if ( V_27 ) {
V_9 = F_22 ( V_22 ,
V_27 | V_43 ,
V_24 -> V_33 [ 0 ] ) ;
if ( V_9 )
F_23 ( V_8 -> V_11 , L_2 ) ;
}
V_9 = F_10 ( V_22 , false ) ;
if ( F_24 ( V_9 != 0 ) )
goto V_44;
V_9 = F_25 ( V_22 , V_37 ,
F_7 ( V_8 ) ? 0 : 1 << 27 ,
NULL ) ;
if ( V_9 ) {
F_14 ( V_22 ) ;
goto V_44;
}
if ( V_26 )
F_26 ( V_22 , 0 , 0 ) ;
V_9 = F_27 ( V_22 , NULL ) ;
F_14 ( V_22 ) ;
if ( V_9 ) {
goto V_44;
}
* V_25 = V_20 ;
return 0 ;
V_44:
F_8 ( V_20 ) ;
* V_25 = NULL ;
return V_9 ;
}
static int F_28 ( struct V_45 * V_46 ,
struct V_47 * V_48 )
{
struct V_4 * V_5 =
F_29 ( V_46 , struct V_4 , V_46 ) ;
struct V_7 * V_8 = V_5 -> V_8 ;
struct V_1 * V_2 ;
struct V_49 * V_50 = NULL ;
struct V_23 V_24 ;
struct V_19 * V_20 = NULL ;
struct V_21 * V_22 = NULL ;
int V_9 ;
unsigned long V_51 ;
V_24 . V_13 = V_48 -> V_52 ;
V_24 . V_30 = V_48 -> V_53 ;
if ( ( V_48 -> V_54 == 24 ) && F_7 ( V_8 ) )
V_48 -> V_54 = 32 ;
V_24 . V_32 = F_30 ( V_48 -> V_54 ,
V_48 -> V_55 ) ;
V_9 = F_16 ( V_5 , & V_24 , & V_20 ) ;
if ( V_9 ) {
F_31 ( L_3 , V_9 ) ;
return V_9 ;
}
V_22 = F_9 ( V_20 ) ;
V_2 = F_32 ( V_46 ) ;
if ( F_33 ( V_2 ) ) {
V_9 = F_34 ( V_2 ) ;
goto V_44;
}
V_2 -> V_6 = V_5 ;
V_2 -> V_56 = true ;
V_9 = F_35 ( V_8 -> V_10 , & V_5 -> V_57 , & V_24 , V_20 ) ;
if ( V_9 ) {
F_31 ( L_4 , V_9 ) ;
goto V_58;
}
V_50 = & V_5 -> V_57 . V_59 ;
V_5 -> V_46 . V_50 = V_50 ;
F_36 ( V_22 -> V_60 , 0x0 , F_37 ( V_22 ) ) ;
strcpy ( V_2 -> V_61 . V_62 , L_5 ) ;
F_38 ( V_2 , V_50 -> V_33 [ 0 ] , V_50 -> V_31 ) ;
V_2 -> V_63 = V_64 | V_65 ;
V_2 -> V_66 = & V_67 ;
V_51 = F_39 ( V_22 ) - V_8 -> V_68 . V_69 ;
V_2 -> V_61 . V_70 = V_8 -> V_68 . V_71 + V_51 ;
V_2 -> V_61 . V_72 = F_37 ( V_22 ) ;
V_2 -> V_73 = V_22 -> V_60 ;
V_2 -> V_74 = F_37 ( V_22 ) ;
F_40 ( V_2 , & V_5 -> V_46 , V_48 -> V_75 , V_48 -> V_76 ) ;
V_2 -> V_77 -> V_78 [ 0 ] . V_59 = V_8 -> V_10 -> V_79 . V_80 ;
V_2 -> V_77 -> V_78 [ 0 ] . V_29 = V_8 -> V_68 . V_81 ;
if ( V_2 -> V_73 == NULL ) {
V_9 = - V_82 ;
goto V_58;
}
F_41 ( L_6 , V_2 -> V_61 . V_70 ) ;
F_41 ( L_7 , ( unsigned long ) V_8 -> V_68 . V_71 ) ;
F_41 ( L_8 , ( unsigned long ) F_37 ( V_22 ) ) ;
F_41 ( L_9 , V_50 -> V_31 ) ;
F_41 ( L_10 , V_50 -> V_33 [ 0 ] ) ;
F_42 ( V_8 -> V_10 -> V_83 , V_2 ) ;
return 0 ;
V_58:
F_43 ( V_46 ) ;
V_44:
if ( V_22 ) {
}
if ( V_50 && V_9 ) {
F_15 ( V_20 ) ;
F_44 ( V_50 ) ;
F_45 ( V_50 ) ;
F_46 ( V_50 ) ;
}
return V_9 ;
}
void F_47 ( struct V_7 * V_8 )
{
if ( V_8 -> V_84 . V_5 )
F_48 ( & V_8 -> V_84 . V_5 -> V_46 ) ;
}
static int F_49 ( struct V_85 * V_11 , struct V_4 * V_5 )
{
struct V_86 * V_57 = & V_5 -> V_57 ;
F_50 ( & V_5 -> V_46 ) ;
F_43 ( & V_5 -> V_46 ) ;
if ( V_57 -> V_87 ) {
F_8 ( V_57 -> V_87 ) ;
V_57 -> V_87 = NULL ;
}
F_51 ( & V_5 -> V_46 ) ;
F_44 ( & V_57 -> V_59 ) ;
F_45 ( & V_57 -> V_59 ) ;
return 0 ;
}
int F_52 ( struct V_7 * V_8 )
{
struct V_4 * V_5 ;
int V_88 = 32 ;
int V_9 ;
if ( F_53 ( & V_8 -> V_10 -> V_79 . V_89 ) )
return 0 ;
if ( F_54 ( V_8 ) || V_8 -> V_68 . V_90 <= ( 32 * 1024 * 1024 ) )
V_88 = 8 ;
V_5 = F_55 ( sizeof( struct V_4 ) , V_91 ) ;
if ( ! V_5 )
return - V_39 ;
V_5 -> V_8 = V_8 ;
V_8 -> V_84 . V_5 = V_5 ;
F_56 ( V_8 -> V_10 , & V_5 -> V_46 ,
& V_92 ) ;
V_9 = F_57 ( V_8 -> V_10 , & V_5 -> V_46 ,
V_8 -> V_93 ,
V_94 ) ;
if ( V_9 )
goto free;
V_9 = F_58 ( & V_5 -> V_46 ) ;
if ( V_9 )
goto V_95;
F_59 ( V_8 -> V_10 ) ;
V_9 = F_60 ( & V_5 -> V_46 , V_88 ) ;
if ( V_9 )
goto V_95;
return 0 ;
V_95:
F_51 ( & V_5 -> V_46 ) ;
free:
F_46 ( V_5 ) ;
return V_9 ;
}
void F_61 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_84 . V_5 )
return;
F_49 ( V_8 -> V_10 , V_8 -> V_84 . V_5 ) ;
F_46 ( V_8 -> V_84 . V_5 ) ;
V_8 -> V_84 . V_5 = NULL ;
}
void F_62 ( struct V_7 * V_8 , int V_96 )
{
if ( V_8 -> V_84 . V_5 )
F_63 ( & V_8 -> V_84 . V_5 -> V_46 , V_96 ) ;
}
bool F_64 ( struct V_7 * V_8 , struct V_21 * V_97 )
{
if ( ! V_8 -> V_84 . V_5 )
return false ;
if ( V_97 == F_9 ( V_8 -> V_84 . V_5 -> V_57 . V_87 ) )
return true ;
return false ;
}
void F_65 ( struct V_7 * V_8 , struct V_98 * V_99 )
{
if ( V_8 -> V_84 . V_5 )
F_66 ( & V_8 -> V_84 . V_5 -> V_46 , V_99 ) ;
}
void F_67 ( struct V_7 * V_8 , struct V_98 * V_99 )
{
if ( V_8 -> V_84 . V_5 )
F_68 ( & V_8 -> V_84 . V_5 -> V_46 , V_99 ) ;
}
void F_69 ( struct V_7 * V_8 )
{
struct V_4 * V_5 = V_8 -> V_84 . V_5 ;
struct V_45 * V_100 ;
int V_9 ;
if ( ! V_5 )
return;
V_100 = & V_5 -> V_46 ;
V_9 = F_70 ( V_100 ) ;
if ( V_9 )
F_71 ( L_11 ) ;
}
