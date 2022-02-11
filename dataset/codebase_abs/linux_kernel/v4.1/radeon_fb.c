static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 ) ;
if ( V_3 == 0 ) {
struct V_4 * V_5 = V_2 -> V_6 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_5 -> V_8 ; V_7 ++ ) {
struct V_9 * V_10 = V_5 -> V_11 [ V_7 ] . V_12 . V_10 ;
F_3 ( V_10 , NULL , 0 , 0 , 0 , 0 , 0 ) ;
}
}
return V_3 ;
}
int F_4 ( struct V_13 * V_14 , int V_15 , int V_16 , bool V_17 )
{
int V_18 = V_15 ;
int V_19 = ( F_5 ( V_14 ) ) || V_17 ;
int V_20 = 0 ;
switch ( V_16 / 8 ) {
case 1 :
V_20 = V_19 ? 255 : 127 ;
break;
case 2 :
V_20 = V_19 ? 127 : 31 ;
break;
case 3 :
case 4 :
V_20 = V_19 ? 63 : 15 ;
break;
}
V_18 += V_20 ;
V_18 &= ~ V_20 ;
return V_18 ;
}
static void F_6 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_7 ( V_22 ) ;
int V_3 ;
V_3 = F_8 ( V_24 , false ) ;
if ( F_9 ( V_3 == 0 ) ) {
F_10 ( V_24 ) ;
F_11 ( V_24 ) ;
F_12 ( V_24 ) ;
}
F_13 ( V_22 ) ;
}
static int F_14 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
struct V_21 * * V_29 )
{
struct V_13 * V_14 = V_26 -> V_14 ;
struct V_21 * V_22 = NULL ;
struct V_23 * V_24 = NULL ;
bool V_30 = false ;
T_1 V_31 = 0 ;
int V_3 ;
int V_32 , V_33 ;
int V_34 = V_28 -> V_34 ;
T_1 V_16 , V_35 ;
F_15 ( V_28 -> V_36 , & V_35 , & V_16 ) ;
V_28 -> V_37 [ 0 ] = F_4 ( V_14 , V_28 -> V_15 , V_16 ,
V_30 ) * ( ( V_16 + 1 ) / 8 ) ;
if ( V_14 -> V_38 >= V_39 )
V_34 = F_16 ( V_28 -> V_34 , 8 ) ;
V_33 = V_28 -> V_37 [ 0 ] * V_34 ;
V_32 = F_16 ( V_33 , V_40 ) ;
V_3 = F_17 ( V_14 , V_32 , 0 ,
V_41 ,
0 , true , & V_22 ) ;
if ( V_3 ) {
F_18 ( V_42 L_1 ,
V_32 ) ;
return - V_43 ;
}
V_24 = F_7 ( V_22 ) ;
if ( V_30 )
V_31 = V_44 ;
#ifdef F_19
switch ( V_16 ) {
case 32 :
V_31 |= V_45 ;
break;
case 16 :
V_31 |= V_46 ;
default:
break;
}
#endif
if ( V_31 ) {
V_3 = F_20 ( V_24 ,
V_31 | V_47 ,
V_28 -> V_37 [ 0 ] ) ;
if ( V_3 )
F_21 ( V_14 -> V_48 , L_2 ) ;
}
V_3 = F_8 ( V_24 , false ) ;
if ( F_22 ( V_3 != 0 ) )
goto V_49;
V_3 = F_23 ( V_24 , V_41 ,
F_5 ( V_14 ) ? 0 : 1 << 27 ,
NULL ) ;
if ( V_3 ) {
F_12 ( V_24 ) ;
goto V_49;
}
if ( V_30 )
F_24 ( V_24 , 0 , 0 ) ;
V_3 = F_25 ( V_24 , NULL ) ;
F_12 ( V_24 ) ;
if ( V_3 ) {
goto V_49;
}
* V_29 = V_22 ;
return 0 ;
V_49:
F_6 ( V_22 ) ;
* V_29 = NULL ;
return V_3 ;
}
static int F_26 ( struct V_4 * V_50 ,
struct V_51 * V_52 )
{
struct V_25 * V_26 =
F_27 ( V_50 , struct V_25 , V_50 ) ;
struct V_13 * V_14 = V_26 -> V_14 ;
struct V_1 * V_2 ;
struct V_53 * V_54 = NULL ;
struct V_27 V_28 ;
struct V_21 * V_22 = NULL ;
struct V_23 * V_24 = NULL ;
struct V_55 * V_55 = & V_14 -> V_56 -> V_48 ;
int V_3 ;
unsigned long V_57 ;
V_28 . V_15 = V_52 -> V_58 ;
V_28 . V_34 = V_52 -> V_59 ;
if ( ( V_52 -> V_60 == 24 ) && F_5 ( V_14 ) )
V_52 -> V_60 = 32 ;
V_28 . V_36 = F_28 ( V_52 -> V_60 ,
V_52 -> V_61 ) ;
V_3 = F_14 ( V_26 , & V_28 , & V_22 ) ;
if ( V_3 ) {
F_29 ( L_3 , V_3 ) ;
return V_3 ;
}
V_24 = F_7 ( V_22 ) ;
V_2 = F_30 ( 0 , V_55 ) ;
if ( V_2 == NULL ) {
V_3 = - V_43 ;
goto V_49;
}
V_2 -> V_6 = V_26 ;
V_2 -> V_62 = true ;
V_3 = F_31 ( V_14 -> V_63 , & V_26 -> V_64 , & V_28 , V_22 ) ;
if ( V_3 ) {
F_29 ( L_4 , V_3 ) ;
goto V_49;
}
V_54 = & V_26 -> V_64 . V_65 ;
V_26 -> V_50 . V_54 = V_54 ;
V_26 -> V_50 . V_66 = V_2 ;
F_32 ( V_24 -> V_67 , 0x0 , F_33 ( V_24 ) ) ;
strcpy ( V_2 -> V_68 . V_69 , L_5 ) ;
F_34 ( V_2 , V_54 -> V_37 [ 0 ] , V_54 -> V_35 ) ;
V_2 -> V_70 = V_71 | V_72 ;
V_2 -> V_73 = & V_74 ;
V_57 = F_35 ( V_24 ) - V_14 -> V_75 . V_76 ;
V_2 -> V_68 . V_77 = V_14 -> V_75 . V_78 + V_57 ;
V_2 -> V_68 . V_79 = F_33 ( V_24 ) ;
V_2 -> V_80 = V_24 -> V_67 ;
V_2 -> V_81 = F_33 ( V_24 ) ;
F_36 ( V_2 , & V_26 -> V_50 , V_52 -> V_82 , V_52 -> V_83 ) ;
V_2 -> V_84 = F_37 ( 1 ) ;
if ( ! V_2 -> V_84 ) {
V_3 = - V_43 ;
goto V_49;
}
V_2 -> V_84 -> V_85 [ 0 ] . V_65 = V_14 -> V_63 -> V_86 . V_87 ;
V_2 -> V_84 -> V_85 [ 0 ] . V_33 = V_14 -> V_75 . V_88 ;
if ( V_2 -> V_80 == NULL ) {
V_3 = - V_89 ;
goto V_49;
}
V_3 = F_38 ( & V_2 -> V_90 , 256 , 0 ) ;
if ( V_3 ) {
V_3 = - V_43 ;
goto V_49;
}
F_39 ( L_6 , V_2 -> V_68 . V_77 ) ;
F_39 ( L_7 , ( unsigned long ) V_14 -> V_75 . V_78 ) ;
F_39 ( L_8 , ( unsigned long ) F_33 ( V_24 ) ) ;
F_39 ( L_9 , V_54 -> V_35 ) ;
F_39 ( L_10 , V_54 -> V_37 [ 0 ] ) ;
F_40 ( V_14 -> V_63 -> V_56 , V_2 ) ;
return 0 ;
V_49:
if ( V_24 ) {
}
if ( V_54 && V_3 ) {
F_41 ( V_22 ) ;
F_42 ( V_54 ) ;
F_43 ( V_54 ) ;
F_44 ( V_54 ) ;
}
return V_3 ;
}
void F_45 ( struct V_13 * V_14 )
{
F_46 ( & V_14 -> V_91 . V_26 -> V_50 ) ;
}
static int F_47 ( struct V_92 * V_48 , struct V_25 * V_26 )
{
struct V_1 * V_2 ;
struct V_93 * V_64 = & V_26 -> V_64 ;
if ( V_26 -> V_50 . V_66 ) {
V_2 = V_26 -> V_50 . V_66 ;
F_48 ( V_2 ) ;
if ( V_2 -> V_90 . V_94 )
F_49 ( & V_2 -> V_90 ) ;
F_50 ( V_2 ) ;
}
if ( V_64 -> V_95 ) {
F_6 ( V_64 -> V_95 ) ;
V_64 -> V_95 = NULL ;
}
F_51 ( & V_26 -> V_50 ) ;
F_42 ( & V_64 -> V_65 ) ;
F_43 ( & V_64 -> V_65 ) ;
return 0 ;
}
int F_52 ( struct V_13 * V_14 )
{
struct V_25 * V_26 ;
int V_96 = 32 ;
int V_3 ;
if ( F_53 ( V_14 ) || V_14 -> V_75 . V_97 <= ( 32 * 1024 * 1024 ) )
V_96 = 8 ;
V_26 = F_54 ( sizeof( struct V_25 ) , V_98 ) ;
if ( ! V_26 )
return - V_43 ;
V_26 -> V_14 = V_14 ;
V_14 -> V_91 . V_26 = V_26 ;
F_55 ( V_14 -> V_63 , & V_26 -> V_50 ,
& V_99 ) ;
V_3 = F_56 ( V_14 -> V_63 , & V_26 -> V_50 ,
V_14 -> V_100 ,
V_101 ) ;
if ( V_3 )
goto free;
V_3 = F_57 ( & V_26 -> V_50 ) ;
if ( V_3 )
goto V_102;
F_58 ( V_14 -> V_63 ) ;
V_3 = F_59 ( & V_26 -> V_50 , V_96 ) ;
if ( V_3 )
goto V_102;
return 0 ;
V_102:
F_51 ( & V_26 -> V_50 ) ;
free:
F_44 ( V_26 ) ;
return V_3 ;
}
void F_60 ( struct V_13 * V_14 )
{
if ( ! V_14 -> V_91 . V_26 )
return;
F_47 ( V_14 -> V_63 , V_14 -> V_91 . V_26 ) ;
F_44 ( V_14 -> V_91 . V_26 ) ;
V_14 -> V_91 . V_26 = NULL ;
}
void F_61 ( struct V_13 * V_14 , int V_103 )
{
F_62 ( V_14 -> V_91 . V_26 -> V_50 . V_66 , V_103 ) ;
}
bool F_63 ( struct V_13 * V_14 , struct V_23 * V_104 )
{
if ( V_104 == F_7 ( V_14 -> V_91 . V_26 -> V_64 . V_95 ) )
return true ;
return false ;
}
void F_64 ( struct V_13 * V_14 , struct V_105 * V_106 )
{
F_65 ( & V_14 -> V_91 . V_26 -> V_50 , V_106 ) ;
}
void F_66 ( struct V_13 * V_14 , struct V_105 * V_106 )
{
F_67 ( & V_14 -> V_91 . V_26 -> V_50 , V_106 ) ;
}
