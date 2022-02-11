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
0 , true ,
& V_9 ) ;
if ( V_12 ) {
F_14 ( V_28 L_1 ,
V_20 ) ;
return - V_29 ;
}
V_11 = F_3 ( V_9 ) ;
if ( V_18 )
V_19 = F_15 ( V_30 , V_31 ) ;
V_12 = F_4 ( V_11 , false ) ;
if ( F_16 ( V_12 != 0 ) )
goto V_32;
if ( V_19 ) {
V_12 = F_17 ( V_11 ,
V_19 ) ;
if ( V_12 )
F_18 ( V_2 -> V_33 , L_2 ) ;
}
V_12 = F_19 ( V_11 , V_27 , 0 , 0 , NULL ) ;
if ( V_12 ) {
F_8 ( V_11 ) ;
goto V_32;
}
V_12 = F_20 ( V_11 , NULL ) ;
F_8 ( V_11 ) ;
if ( V_12 ) {
goto V_32;
}
* V_17 = V_9 ;
return 0 ;
V_32:
F_2 ( V_9 ) ;
* V_17 = NULL ;
return V_12 ;
}
static int F_21 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
struct V_13 * V_14 = (struct V_13 * ) V_35 ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_38 * V_39 ;
struct V_40 * V_41 = NULL ;
struct V_15 V_16 ;
struct V_8 * V_9 = NULL ;
struct V_10 * V_11 = NULL ;
struct V_42 * V_42 = & V_2 -> V_43 -> V_33 ;
int V_12 ;
unsigned long V_44 ;
V_16 . V_3 = V_37 -> V_45 ;
V_16 . V_22 = V_37 -> V_46 ;
if ( V_37 -> V_47 == 24 )
V_37 -> V_47 = 32 ;
V_16 . V_24 = F_22 ( V_37 -> V_47 ,
V_37 -> V_48 ) ;
V_12 = F_10 ( V_14 , & V_16 , & V_9 ) ;
if ( V_12 ) {
F_23 ( L_3 , V_12 ) ;
return V_12 ;
}
V_11 = F_3 ( V_9 ) ;
V_39 = F_24 ( 0 , V_42 ) ;
if ( V_39 == NULL ) {
V_12 = - V_29 ;
goto V_32;
}
V_39 -> V_49 = V_14 ;
V_12 = F_25 ( V_2 -> V_50 , & V_14 -> V_51 , & V_16 , V_9 ) ;
if ( V_12 ) {
F_23 ( L_4 , V_12 ) ;
goto V_32;
}
V_41 = & V_14 -> V_51 . V_52 ;
V_14 -> V_35 . V_41 = V_41 ;
V_14 -> V_35 . V_53 = V_39 ;
F_26 ( V_11 -> V_54 , 0x0 , F_27 ( V_11 ) ) ;
strcpy ( V_39 -> V_55 . V_56 , L_5 ) ;
F_28 ( V_39 , V_41 -> V_25 [ 0 ] , V_41 -> V_23 ) ;
V_39 -> V_57 = V_58 | V_59 ;
V_39 -> V_60 = & V_61 ;
V_44 = F_29 ( V_11 ) - V_2 -> V_62 . V_63 ;
V_39 -> V_55 . V_64 = V_2 -> V_62 . V_65 + V_44 ;
V_39 -> V_55 . V_66 = F_27 ( V_11 ) ;
V_39 -> V_67 = V_11 -> V_54 ;
V_39 -> V_68 = F_27 ( V_11 ) ;
F_30 ( V_39 , & V_14 -> V_35 , V_37 -> V_69 , V_37 -> V_70 ) ;
V_39 -> V_71 = F_31 ( 1 ) ;
if ( ! V_39 -> V_71 ) {
V_12 = - V_29 ;
goto V_32;
}
V_39 -> V_71 -> V_72 [ 0 ] . V_52 = V_2 -> V_50 -> V_73 . V_74 ;
V_39 -> V_71 -> V_72 [ 0 ] . V_21 = V_2 -> V_62 . V_75 ;
if ( V_39 -> V_67 == NULL ) {
V_12 = - V_76 ;
goto V_32;
}
V_12 = F_32 ( & V_39 -> V_77 , 256 , 0 ) ;
if ( V_12 ) {
V_12 = - V_29 ;
goto V_32;
}
F_33 ( L_6 , V_39 -> V_55 . V_64 ) ;
F_33 ( L_7 , ( unsigned long ) V_2 -> V_62 . V_65 ) ;
F_33 ( L_8 , ( unsigned long ) F_27 ( V_11 ) ) ;
F_33 ( L_9 , V_41 -> V_23 ) ;
F_33 ( L_10 , V_41 -> V_25 [ 0 ] ) ;
F_34 ( V_2 -> V_50 -> V_43 , V_39 ) ;
return 0 ;
V_32:
if ( V_11 ) {
}
if ( V_41 && V_12 ) {
F_35 ( V_9 ) ;
F_36 ( V_41 ) ;
F_37 ( V_41 ) ;
F_38 ( V_41 ) ;
}
return V_12 ;
}
void F_39 ( struct V_1 * V_2 )
{
if ( V_2 -> V_78 . V_14 )
F_40 ( & V_2 -> V_78 . V_14 -> V_35 ) ;
}
static int F_41 ( struct V_79 * V_33 , struct V_13 * V_14 )
{
struct V_38 * V_39 ;
struct V_80 * V_51 = & V_14 -> V_51 ;
if ( V_14 -> V_35 . V_53 ) {
V_39 = V_14 -> V_35 . V_53 ;
F_42 ( V_39 ) ;
if ( V_39 -> V_77 . V_81 )
F_43 ( & V_39 -> V_77 ) ;
F_44 ( V_39 ) ;
}
if ( V_51 -> V_82 ) {
F_2 ( V_51 -> V_82 ) ;
V_51 -> V_82 = NULL ;
}
F_45 ( & V_14 -> V_35 ) ;
F_36 ( & V_51 -> V_52 ) ;
F_37 ( & V_51 -> V_52 ) ;
return 0 ;
}
static void F_46 ( struct V_83 * V_84 , T_2 V_85 , T_2 V_86 ,
T_2 V_87 , int V_88 )
{
struct V_89 * V_89 = F_47 ( V_84 ) ;
V_89 -> V_90 [ V_88 ] = V_85 >> 6 ;
V_89 -> V_91 [ V_88 ] = V_86 >> 6 ;
V_89 -> V_92 [ V_88 ] = V_87 >> 6 ;
}
static void F_48 ( struct V_83 * V_84 , T_2 * V_85 , T_2 * V_86 ,
T_2 * V_87 , int V_88 )
{
struct V_89 * V_89 = F_47 ( V_84 ) ;
* V_85 = V_89 -> V_90 [ V_88 ] << 6 ;
* V_86 = V_89 -> V_91 [ V_88 ] << 6 ;
* V_87 = V_89 -> V_92 [ V_88 ] << 6 ;
}
int F_49 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
int V_93 = 32 ;
int V_12 ;
if ( ! V_2 -> V_78 . V_94 )
return 0 ;
if ( V_2 -> V_62 . V_95 <= ( 32 * 1024 * 1024 ) )
V_93 = 8 ;
V_14 = F_50 ( sizeof( struct V_13 ) , V_96 ) ;
if ( ! V_14 )
return - V_29 ;
V_14 -> V_2 = V_2 ;
V_2 -> V_78 . V_14 = V_14 ;
F_51 ( V_2 -> V_50 , & V_14 -> V_35 ,
& V_97 ) ;
V_12 = F_52 ( V_2 -> V_50 , & V_14 -> V_35 ,
V_2 -> V_78 . V_98 ,
V_99 ) ;
if ( V_12 ) {
F_38 ( V_14 ) ;
return V_12 ;
}
F_53 ( & V_14 -> V_35 ) ;
F_54 ( V_2 -> V_50 ) ;
F_55 ( & V_14 -> V_35 , V_93 ) ;
return 0 ;
}
void F_56 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_78 . V_14 )
return;
F_41 ( V_2 -> V_50 , V_2 -> V_78 . V_14 ) ;
F_38 ( V_2 -> V_78 . V_14 ) ;
V_2 -> V_78 . V_14 = NULL ;
}
void F_57 ( struct V_1 * V_2 , int V_100 )
{
if ( V_2 -> V_78 . V_14 )
F_58 ( V_2 -> V_78 . V_14 -> V_35 . V_53 , V_100 ) ;
}
int F_59 ( struct V_1 * V_2 )
{
struct V_10 * V_101 ;
int V_21 = 0 ;
if ( ! V_2 -> V_78 . V_14 )
return 0 ;
V_101 = F_3 ( V_2 -> V_78 . V_14 -> V_51 . V_82 ) ;
V_21 += F_27 ( V_101 ) ;
return V_21 ;
}
bool F_60 ( struct V_1 * V_2 , struct V_10 * V_101 )
{
if ( ! V_2 -> V_78 . V_14 )
return false ;
if ( V_101 == F_3 ( V_2 -> V_78 . V_14 -> V_51 . V_82 ) )
return true ;
return false ;
}
