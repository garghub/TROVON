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
V_9 = F_9 ( V_21 , true ) ;
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
V_35 |
V_36 ,
true , & V_19 ) ;
if ( V_9 ) {
F_19 ( L_1 , V_27 ) ;
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
goto V_52;
}
V_2 -> V_6 = V_5 ;
V_2 -> V_53 = true ;
V_9 = F_32 ( V_8 -> V_10 , & V_5 -> V_54 , & V_23 , V_19 ) ;
if ( V_9 ) {
F_28 ( L_4 , V_9 ) ;
goto V_52;
}
V_46 = & V_5 -> V_54 . V_55 ;
V_5 -> V_42 . V_46 = V_46 ;
strcpy ( V_2 -> V_56 . V_57 , L_5 ) ;
F_33 ( V_2 , V_46 -> V_31 [ 0 ] , V_46 -> V_58 -> V_59 ) ;
V_2 -> V_60 = & V_61 ;
V_47 = F_34 ( V_21 ) - V_8 -> V_62 . V_63 ;
V_2 -> V_56 . V_64 = V_8 -> V_62 . V_65 + V_47 ;
V_2 -> V_56 . V_66 = F_35 ( V_21 ) ;
V_2 -> V_67 = F_36 ( V_21 ) ;
V_2 -> V_68 = F_35 ( V_21 ) ;
F_37 ( V_2 , & V_5 -> V_42 , V_44 -> V_69 , V_44 -> V_70 ) ;
V_2 -> V_71 -> V_72 [ 0 ] . V_55 = V_8 -> V_10 -> V_73 . V_74 ;
V_2 -> V_71 -> V_72 [ 0 ] . V_28 = V_8 -> V_62 . V_75 ;
if ( V_2 -> V_67 == NULL ) {
V_9 = - V_76 ;
goto V_52;
}
F_38 ( L_6 , V_2 -> V_56 . V_64 ) ;
F_38 ( L_7 , ( unsigned long ) V_8 -> V_62 . V_65 ) ;
F_38 ( L_8 , ( unsigned long ) F_35 ( V_21 ) ) ;
F_38 ( L_9 , V_46 -> V_58 -> V_59 ) ;
F_38 ( L_10 , V_46 -> V_31 [ 0 ] ) ;
F_39 ( V_8 -> V_10 -> V_77 , V_2 ) ;
return 0 ;
V_52:
if ( V_21 ) {
}
if ( V_46 && V_9 ) {
F_14 ( V_19 ) ;
F_40 ( V_46 ) ;
F_41 ( V_46 ) ;
F_42 ( V_46 ) ;
}
return V_9 ;
}
void F_43 ( struct V_7 * V_8 )
{
if ( V_8 -> V_78 . V_5 )
F_44 ( & V_8 -> V_78 . V_5 -> V_42 ) ;
}
static int F_45 ( struct V_79 * V_11 , struct V_4 * V_5 )
{
struct V_80 * V_54 = & V_5 -> V_54 ;
F_46 ( & V_5 -> V_42 ) ;
if ( V_54 -> V_81 ) {
F_7 ( V_54 -> V_81 ) ;
V_54 -> V_81 = NULL ;
}
F_47 ( & V_5 -> V_42 ) ;
F_40 ( & V_54 -> V_55 ) ;
F_41 ( & V_54 -> V_55 ) ;
return 0 ;
}
int F_48 ( struct V_7 * V_8 )
{
struct V_4 * V_5 ;
int V_82 = 32 ;
int V_9 ;
if ( ! V_8 -> V_78 . V_83 )
return 0 ;
if ( F_49 ( & V_8 -> V_10 -> V_73 . V_84 ) )
return 0 ;
if ( V_8 -> V_62 . V_85 <= ( 32 * 1024 * 1024 ) )
V_82 = 8 ;
V_5 = F_50 ( sizeof( struct V_4 ) , V_86 ) ;
if ( ! V_5 )
return - V_37 ;
V_5 -> V_8 = V_8 ;
V_8 -> V_78 . V_5 = V_5 ;
F_51 ( V_8 -> V_10 , & V_5 -> V_42 ,
& V_87 ) ;
V_9 = F_52 ( V_8 -> V_10 , & V_5 -> V_42 ,
V_88 ) ;
if ( V_9 ) {
F_42 ( V_5 ) ;
return V_9 ;
}
F_53 ( & V_5 -> V_42 ) ;
F_54 ( V_8 -> V_10 ) ;
F_55 ( & V_5 -> V_42 , V_82 ) ;
return 0 ;
}
void F_56 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_78 . V_5 )
return;
F_45 ( V_8 -> V_10 , V_8 -> V_78 . V_5 ) ;
F_42 ( V_8 -> V_78 . V_5 ) ;
V_8 -> V_78 . V_5 = NULL ;
}
void F_57 ( struct V_7 * V_8 , int V_89 )
{
if ( V_8 -> V_78 . V_5 )
F_58 ( & V_8 -> V_78 . V_5 -> V_42 ,
V_89 ) ;
}
int F_59 ( struct V_7 * V_8 )
{
struct V_20 * V_90 ;
int V_28 = 0 ;
if ( ! V_8 -> V_78 . V_5 )
return 0 ;
V_90 = F_8 ( V_8 -> V_78 . V_5 -> V_54 . V_81 ) ;
V_28 += F_35 ( V_90 ) ;
return V_28 ;
}
bool F_60 ( struct V_7 * V_8 , struct V_20 * V_90 )
{
if ( ! V_8 -> V_78 . V_5 )
return false ;
if ( V_90 == F_8 ( V_8 -> V_78 . V_5 -> V_54 . V_81 ) )
return true ;
return false ;
}
void F_61 ( struct V_7 * V_8 )
{
struct V_4 * V_91 ;
struct V_41 * V_92 ;
int V_9 ;
if ( ! V_8 )
return;
V_91 = V_8 -> V_78 . V_5 ;
if ( ! V_91 )
return;
V_92 = & V_91 -> V_42 ;
V_9 = F_62 ( V_92 ) ;
if ( V_9 )
F_63 ( L_11 ) ;
}
