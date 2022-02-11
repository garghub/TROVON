int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 , bool V_5 )
{
int V_6 = V_3 ;
int V_7 = 0 ;
switch ( V_4 / 8 ) {
case 1 :
V_7 = 255 ;
break;
case 2 :
V_7 = 127 ;
break;
case 3 :
case 4 :
V_7 = 63 ;
break;
}
V_6 += V_7 ;
V_6 &= ~ V_7 ;
return V_6 ;
}
static void F_2 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_3 ( V_9 ) ;
int V_12 ;
V_12 = F_4 ( V_11 , false ) ;
if ( F_5 ( V_12 == 0 ) ) {
F_6 ( V_11 ) ;
F_7 ( V_11 ) ;
F_8 ( V_11 ) ;
}
F_9 ( V_9 ) ;
}
static int F_10 ( struct V_13 * V_14 ,
struct V_15 * V_16 ,
struct V_8 * * V_17 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_8 * V_9 = NULL ;
struct V_10 * V_11 = NULL ;
bool V_18 = false ;
T_1 V_19 = 0 ;
int V_12 ;
int V_20 , V_21 ;
int V_22 = V_16 -> V_22 ;
T_1 V_4 , V_23 ;
F_11 ( V_16 -> V_24 , & V_23 , & V_4 ) ;
V_16 -> V_25 [ 0 ] = F_1 ( V_2 , V_16 -> V_3 , V_4 ,
V_18 ) * ( ( V_4 + 1 ) / 8 ) ;
V_22 = F_12 ( V_16 -> V_22 , 8 ) ;
V_21 = V_16 -> V_25 [ 0 ] * V_22 ;
V_20 = F_12 ( V_21 , V_26 ) ;
V_12 = F_13 ( V_2 , V_20 , 0 ,
V_27 ,
V_28 ,
true , & V_9 ) ;
if ( V_12 ) {
F_14 ( V_29 L_1 ,
V_20 ) ;
return - V_30 ;
}
V_11 = F_3 ( V_9 ) ;
if ( V_18 )
V_19 = F_15 ( V_31 , V_32 ) ;
V_12 = F_4 ( V_11 , false ) ;
if ( F_16 ( V_12 != 0 ) )
goto V_33;
if ( V_19 ) {
V_12 = F_17 ( V_11 ,
V_19 ) ;
if ( V_12 )
F_18 ( V_2 -> V_34 , L_2 ) ;
}
V_12 = F_19 ( V_11 , V_27 , 0 , 0 , NULL ) ;
if ( V_12 ) {
F_8 ( V_11 ) ;
goto V_33;
}
V_12 = F_20 ( V_11 , NULL ) ;
F_8 ( V_11 ) ;
if ( V_12 ) {
goto V_33;
}
* V_17 = V_9 ;
return 0 ;
V_33:
F_2 ( V_9 ) ;
* V_17 = NULL ;
return V_12 ;
}
static int F_21 ( struct V_35 * V_36 ,
struct V_37 * V_38 )
{
struct V_13 * V_14 = (struct V_13 * ) V_36 ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_39 * V_40 ;
struct V_41 * V_42 = NULL ;
struct V_15 V_16 ;
struct V_8 * V_9 = NULL ;
struct V_10 * V_11 = NULL ;
int V_12 ;
unsigned long V_43 ;
V_16 . V_3 = V_38 -> V_44 ;
V_16 . V_22 = V_38 -> V_45 ;
if ( V_38 -> V_46 == 24 )
V_38 -> V_46 = 32 ;
V_16 . V_24 = F_22 ( V_38 -> V_46 ,
V_38 -> V_47 ) ;
V_12 = F_10 ( V_14 , & V_16 , & V_9 ) ;
if ( V_12 ) {
F_23 ( L_3 , V_12 ) ;
return V_12 ;
}
V_11 = F_3 ( V_9 ) ;
V_40 = F_24 ( V_36 ) ;
if ( F_25 ( V_40 ) ) {
V_12 = F_26 ( V_40 ) ;
goto V_33;
}
V_40 -> V_48 = V_14 ;
V_40 -> V_49 = true ;
V_12 = F_27 ( V_2 -> V_50 , & V_14 -> V_51 , & V_16 , V_9 ) ;
if ( V_12 ) {
F_23 ( L_4 , V_12 ) ;
goto V_52;
}
V_42 = & V_14 -> V_51 . V_53 ;
V_14 -> V_36 . V_42 = V_42 ;
F_28 ( V_11 -> V_54 , 0x0 , F_29 ( V_11 ) ) ;
strcpy ( V_40 -> V_55 . V_56 , L_5 ) ;
F_30 ( V_40 , V_42 -> V_25 [ 0 ] , V_42 -> V_23 ) ;
V_40 -> V_57 = V_58 | V_59 ;
V_40 -> V_60 = & V_61 ;
V_43 = F_31 ( V_11 ) - V_2 -> V_62 . V_63 ;
V_40 -> V_55 . V_64 = V_2 -> V_62 . V_65 + V_43 ;
V_40 -> V_55 . V_66 = F_29 ( V_11 ) ;
V_40 -> V_67 = V_11 -> V_54 ;
V_40 -> V_68 = F_29 ( V_11 ) ;
F_32 ( V_40 , & V_14 -> V_36 , V_38 -> V_69 , V_38 -> V_70 ) ;
V_40 -> V_71 -> V_72 [ 0 ] . V_53 = V_2 -> V_50 -> V_73 . V_74 ;
V_40 -> V_71 -> V_72 [ 0 ] . V_21 = V_2 -> V_62 . V_75 ;
if ( V_40 -> V_67 == NULL ) {
V_12 = - V_76 ;
goto V_52;
}
F_33 ( L_6 , V_40 -> V_55 . V_64 ) ;
F_33 ( L_7 , ( unsigned long ) V_2 -> V_62 . V_65 ) ;
F_33 ( L_8 , ( unsigned long ) F_29 ( V_11 ) ) ;
F_33 ( L_9 , V_42 -> V_23 ) ;
F_33 ( L_10 , V_42 -> V_25 [ 0 ] ) ;
F_34 ( V_2 -> V_50 -> V_77 , V_40 ) ;
return 0 ;
V_52:
F_35 ( V_36 ) ;
V_33:
if ( V_11 ) {
}
if ( V_42 && V_12 ) {
F_36 ( V_9 ) ;
F_37 ( V_42 ) ;
F_38 ( V_42 ) ;
F_39 ( V_42 ) ;
}
return V_12 ;
}
void F_40 ( struct V_1 * V_2 )
{
if ( V_2 -> V_78 . V_14 )
F_41 ( & V_2 -> V_78 . V_14 -> V_36 ) ;
}
static int F_42 ( struct V_79 * V_34 , struct V_13 * V_14 )
{
struct V_80 * V_51 = & V_14 -> V_51 ;
F_43 ( & V_14 -> V_36 ) ;
F_35 ( & V_14 -> V_36 ) ;
if ( V_51 -> V_81 ) {
F_2 ( V_51 -> V_81 ) ;
V_51 -> V_81 = NULL ;
}
F_44 ( & V_14 -> V_36 ) ;
F_37 ( & V_51 -> V_53 ) ;
F_38 ( & V_51 -> V_53 ) ;
return 0 ;
}
static void F_45 ( struct V_82 * V_83 , T_2 V_84 , T_2 V_85 ,
T_2 V_86 , int V_87 )
{
struct V_88 * V_88 = F_46 ( V_83 ) ;
V_88 -> V_89 [ V_87 ] = V_84 >> 6 ;
V_88 -> V_90 [ V_87 ] = V_85 >> 6 ;
V_88 -> V_91 [ V_87 ] = V_86 >> 6 ;
}
static void F_47 ( struct V_82 * V_83 , T_2 * V_84 , T_2 * V_85 ,
T_2 * V_86 , int V_87 )
{
struct V_88 * V_88 = F_46 ( V_83 ) ;
* V_84 = V_88 -> V_89 [ V_87 ] << 6 ;
* V_85 = V_88 -> V_90 [ V_87 ] << 6 ;
* V_86 = V_88 -> V_91 [ V_87 ] << 6 ;
}
int F_48 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
int V_92 = 32 ;
int V_12 ;
if ( ! V_2 -> V_78 . V_93 )
return 0 ;
if ( V_2 -> V_62 . V_94 <= ( 32 * 1024 * 1024 ) )
V_92 = 8 ;
V_14 = F_49 ( sizeof( struct V_13 ) , V_95 ) ;
if ( ! V_14 )
return - V_30 ;
V_14 -> V_2 = V_2 ;
V_2 -> V_78 . V_14 = V_14 ;
F_50 ( V_2 -> V_50 , & V_14 -> V_36 ,
& V_96 ) ;
V_12 = F_51 ( V_2 -> V_50 , & V_14 -> V_36 ,
V_2 -> V_78 . V_97 ,
V_98 ) ;
if ( V_12 ) {
F_39 ( V_14 ) ;
return V_12 ;
}
F_52 ( & V_14 -> V_36 ) ;
F_53 ( V_2 -> V_50 ) ;
F_54 ( & V_14 -> V_36 , V_92 ) ;
return 0 ;
}
void F_55 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_78 . V_14 )
return;
F_42 ( V_2 -> V_50 , V_2 -> V_78 . V_14 ) ;
F_39 ( V_2 -> V_78 . V_14 ) ;
V_2 -> V_78 . V_14 = NULL ;
}
void F_56 ( struct V_1 * V_2 , int V_99 )
{
if ( V_2 -> V_78 . V_14 )
F_57 ( & V_2 -> V_78 . V_14 -> V_36 ,
V_99 ) ;
}
int F_58 ( struct V_1 * V_2 )
{
struct V_10 * V_100 ;
int V_21 = 0 ;
if ( ! V_2 -> V_78 . V_14 )
return 0 ;
V_100 = F_3 ( V_2 -> V_78 . V_14 -> V_51 . V_81 ) ;
V_21 += F_29 ( V_100 ) ;
return V_21 ;
}
bool F_59 ( struct V_1 * V_2 , struct V_10 * V_100 )
{
if ( ! V_2 -> V_78 . V_14 )
return false ;
if ( V_100 == F_3 ( V_2 -> V_78 . V_14 -> V_51 . V_81 ) )
return true ;
return false ;
}
void F_60 ( struct V_1 * V_2 )
{
struct V_13 * V_101 = V_2 -> V_78 . V_14 ;
struct V_35 * V_102 ;
int V_12 ;
if ( ! V_101 )
return;
V_102 = & V_101 -> V_36 ;
V_12 = F_61 ( V_102 ) ;
if ( V_12 )
F_62 ( L_11 ) ;
}
