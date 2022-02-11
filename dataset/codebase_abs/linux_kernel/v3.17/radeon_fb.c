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
struct V_14 * V_15 = (struct V_14 * ) V_40 ;
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_43 * V_44 ;
struct V_45 * V_46 = NULL ;
struct V_16 V_17 ;
struct V_9 * V_10 = NULL ;
struct V_11 * V_12 = NULL ;
struct V_47 * V_47 = & V_2 -> V_48 -> V_37 ;
int V_13 ;
unsigned long V_49 ;
V_17 . V_3 = V_42 -> V_50 ;
V_17 . V_23 = V_42 -> V_51 ;
if ( ( V_42 -> V_52 == 24 ) && F_2 ( V_2 ) )
V_42 -> V_52 = 32 ;
V_17 . V_25 = F_24 ( V_42 -> V_52 ,
V_42 -> V_53 ) ;
V_13 = F_11 ( V_15 , & V_17 , & V_10 ) ;
if ( V_13 ) {
F_25 ( L_3 , V_13 ) ;
return V_13 ;
}
V_12 = F_4 ( V_10 ) ;
V_44 = F_26 ( 0 , V_47 ) ;
if ( V_44 == NULL ) {
V_13 = - V_32 ;
goto V_38;
}
V_44 -> V_54 = V_15 ;
V_13 = F_27 ( V_2 -> V_55 , & V_15 -> V_56 , & V_17 , V_10 ) ;
if ( V_13 ) {
F_25 ( L_4 , V_13 ) ;
goto V_38;
}
V_46 = & V_15 -> V_56 . V_57 ;
V_15 -> V_40 . V_46 = V_46 ;
V_15 -> V_40 . V_58 = V_44 ;
F_28 ( V_12 -> V_59 , 0x0 , F_29 ( V_12 ) ) ;
strcpy ( V_44 -> V_60 . V_61 , L_5 ) ;
F_30 ( V_44 , V_46 -> V_26 [ 0 ] , V_46 -> V_24 ) ;
V_44 -> V_62 = V_63 | V_64 ;
V_44 -> V_65 = & V_66 ;
V_49 = F_31 ( V_12 ) - V_2 -> V_67 . V_68 ;
V_44 -> V_60 . V_69 = V_2 -> V_67 . V_70 + V_49 ;
V_44 -> V_60 . V_71 = F_29 ( V_12 ) ;
V_44 -> V_72 = V_12 -> V_59 ;
V_44 -> V_73 = F_29 ( V_12 ) ;
F_32 ( V_44 , & V_15 -> V_40 , V_42 -> V_74 , V_42 -> V_75 ) ;
V_44 -> V_76 = F_33 ( 1 ) ;
if ( ! V_44 -> V_76 ) {
V_13 = - V_32 ;
goto V_38;
}
V_44 -> V_76 -> V_77 [ 0 ] . V_57 = V_2 -> V_55 -> V_78 . V_79 ;
V_44 -> V_76 -> V_77 [ 0 ] . V_22 = V_2 -> V_67 . V_80 ;
if ( V_44 -> V_72 == NULL ) {
V_13 = - V_81 ;
goto V_38;
}
V_13 = F_34 ( & V_44 -> V_82 , 256 , 0 ) ;
if ( V_13 ) {
V_13 = - V_32 ;
goto V_38;
}
F_35 ( L_6 , V_44 -> V_60 . V_69 ) ;
F_35 ( L_7 , ( unsigned long ) V_2 -> V_67 . V_70 ) ;
F_35 ( L_8 , ( unsigned long ) F_29 ( V_12 ) ) ;
F_35 ( L_9 , V_46 -> V_24 ) ;
F_35 ( L_10 , V_46 -> V_26 [ 0 ] ) ;
F_36 ( V_2 -> V_55 -> V_48 , V_44 ) ;
return 0 ;
V_38:
if ( V_12 ) {
}
if ( V_46 && V_13 ) {
F_37 ( V_10 ) ;
F_38 ( V_46 ) ;
F_39 ( V_46 ) ;
F_40 ( V_46 ) ;
}
return V_13 ;
}
void F_41 ( struct V_1 * V_2 )
{
F_42 ( & V_2 -> V_83 . V_15 -> V_40 ) ;
}
static int F_43 ( struct V_84 * V_37 , struct V_14 * V_15 )
{
struct V_43 * V_44 ;
struct V_85 * V_56 = & V_15 -> V_56 ;
if ( V_15 -> V_40 . V_58 ) {
V_44 = V_15 -> V_40 . V_58 ;
F_44 ( V_44 ) ;
if ( V_44 -> V_82 . V_86 )
F_45 ( & V_44 -> V_82 ) ;
F_46 ( V_44 ) ;
}
if ( V_56 -> V_87 ) {
F_3 ( V_56 -> V_87 ) ;
V_56 -> V_87 = NULL ;
}
F_47 ( & V_15 -> V_40 ) ;
F_38 ( & V_56 -> V_57 ) ;
F_39 ( & V_56 -> V_57 ) ;
return 0 ;
}
int F_48 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
int V_88 = 32 ;
int V_13 ;
if ( F_49 ( V_2 ) || V_2 -> V_67 . V_89 <= ( 32 * 1024 * 1024 ) )
V_88 = 8 ;
V_15 = F_50 ( sizeof( struct V_14 ) , V_90 ) ;
if ( ! V_15 )
return - V_32 ;
V_15 -> V_2 = V_2 ;
V_2 -> V_83 . V_15 = V_15 ;
F_51 ( V_2 -> V_55 , & V_15 -> V_40 ,
& V_91 ) ;
V_13 = F_52 ( V_2 -> V_55 , & V_15 -> V_40 ,
V_2 -> V_92 ,
V_93 ) ;
if ( V_13 ) {
F_40 ( V_15 ) ;
return V_13 ;
}
F_53 ( & V_15 -> V_40 ) ;
F_54 ( V_2 -> V_55 ) ;
F_55 ( & V_15 -> V_40 , V_88 ) ;
return 0 ;
}
void F_56 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_83 . V_15 )
return;
F_43 ( V_2 -> V_55 , V_2 -> V_83 . V_15 ) ;
F_40 ( V_2 -> V_83 . V_15 ) ;
V_2 -> V_83 . V_15 = NULL ;
}
void F_57 ( struct V_1 * V_2 , int V_94 )
{
F_58 ( V_2 -> V_83 . V_15 -> V_40 . V_58 , V_94 ) ;
}
int F_59 ( struct V_1 * V_2 )
{
struct V_11 * V_95 ;
int V_22 = 0 ;
V_95 = F_4 ( V_2 -> V_83 . V_15 -> V_56 . V_87 ) ;
V_22 += F_29 ( V_95 ) ;
return V_22 ;
}
bool F_60 ( struct V_1 * V_2 , struct V_11 * V_95 )
{
if ( V_95 == F_4 ( V_2 -> V_83 . V_15 -> V_56 . V_87 ) )
return true ;
return false ;
}
