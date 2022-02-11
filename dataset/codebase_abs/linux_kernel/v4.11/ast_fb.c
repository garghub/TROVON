static void F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 , int V_5 , int V_6 )
{
int V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
int V_12 , V_13 ;
int V_14 = V_2 -> V_15 . V_16 . V_17 -> V_18 [ 0 ] ;
int V_19 = - V_20 ;
bool V_21 = false ;
bool V_22 = false ;
int V_23 , V_24 ;
unsigned long V_25 ;
V_9 = V_2 -> V_15 . V_9 ;
V_11 = F_2 ( V_9 ) ;
if ( F_3 () )
V_19 = F_4 ( V_11 , true ) ;
if ( V_19 ) {
if ( V_19 != - V_20 )
return;
V_22 = true ;
}
V_23 = V_3 + V_5 - 1 ;
V_24 = V_4 + V_6 - 1 ;
F_5 ( & V_2 -> V_26 , V_25 ) ;
if ( V_2 -> y1 < V_4 )
V_4 = V_2 -> y1 ;
if ( V_2 -> V_24 > V_24 )
V_24 = V_2 -> V_24 ;
if ( V_2 -> V_27 < V_3 )
V_3 = V_2 -> V_27 ;
if ( V_2 -> V_23 > V_23 )
V_23 = V_2 -> V_23 ;
if ( V_22 ) {
V_2 -> V_27 = V_3 ;
V_2 -> V_23 = V_23 ;
V_2 -> y1 = V_4 ;
V_2 -> V_24 = V_24 ;
F_6 ( & V_2 -> V_26 , V_25 ) ;
return;
}
V_2 -> V_27 = V_2 -> y1 = V_28 ;
V_2 -> V_23 = V_2 -> V_24 = 0 ;
F_6 ( & V_2 -> V_26 , V_25 ) ;
if ( ! V_11 -> V_29 . V_30 ) {
V_19 = F_7 ( & V_11 -> V_11 , 0 , V_11 -> V_11 . V_31 , & V_11 -> V_29 ) ;
if ( V_19 ) {
F_8 ( L_1 ) ;
F_9 ( V_11 ) ;
return;
}
V_21 = true ;
}
for ( V_7 = V_4 ; V_7 <= V_24 ; V_7 ++ ) {
V_12 = V_13 = V_7 * V_2 -> V_15 . V_16 . V_32 [ 0 ] + ( V_3 * V_14 ) ;
F_10 ( V_11 -> V_29 . V_30 + V_12 , V_2 -> V_33 + V_12 , ( V_23 - V_3 + 1 ) * V_14 ) ;
}
if ( V_21 )
F_11 ( & V_11 -> V_29 ) ;
F_9 ( V_11 ) ;
}
static void F_12 ( struct V_34 * V_35 ,
const struct V_36 * V_37 )
{
struct V_1 * V_2 = V_35 -> V_38 ;
F_13 ( V_35 , V_37 ) ;
F_1 ( V_2 , V_37 -> V_39 , V_37 -> V_40 , V_37 -> V_5 ,
V_37 -> V_6 ) ;
}
static void F_14 ( struct V_34 * V_35 ,
const struct V_41 * V_42 )
{
struct V_1 * V_2 = V_35 -> V_38 ;
F_15 ( V_35 , V_42 ) ;
F_1 ( V_2 , V_42 -> V_39 , V_42 -> V_40 , V_42 -> V_5 ,
V_42 -> V_6 ) ;
}
static void F_16 ( struct V_34 * V_35 ,
const struct V_43 * V_44 )
{
struct V_1 * V_2 = V_35 -> V_38 ;
F_17 ( V_35 , V_44 ) ;
F_1 ( V_2 , V_44 -> V_39 , V_44 -> V_40 , V_44 -> V_5 ,
V_44 -> V_6 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
const struct V_45 * V_46 ,
struct V_8 * * V_47 )
{
struct V_48 * V_49 = V_2 -> V_50 . V_49 ;
T_1 V_51 ;
struct V_8 * V_52 ;
int V_19 = 0 ;
V_51 = V_46 -> V_32 [ 0 ] * V_46 -> V_6 ;
V_19 = F_19 ( V_49 , V_51 , true , & V_52 ) ;
if ( V_19 )
return V_19 ;
* V_47 = V_52 ;
return V_19 ;
}
static int F_20 ( struct V_53 * V_50 ,
struct V_54 * V_55 )
{
struct V_1 * V_2 =
F_21 ( V_50 , struct V_1 , V_50 ) ;
struct V_48 * V_49 = V_2 -> V_50 . V_49 ;
struct V_45 V_46 ;
struct V_56 * V_57 ;
struct V_34 * V_35 ;
int V_51 , V_19 ;
void * V_33 ;
struct V_8 * V_52 = NULL ;
struct V_10 * V_11 = NULL ;
V_46 . V_5 = V_55 -> V_58 ;
V_46 . V_6 = V_55 -> V_59 ;
V_46 . V_32 [ 0 ] = V_46 . V_5 * ( ( V_55 -> V_60 + 7 ) / 8 ) ;
V_46 . V_61 = F_22 ( V_55 -> V_60 ,
V_55 -> V_62 ) ;
V_51 = V_46 . V_32 [ 0 ] * V_46 . V_6 ;
V_19 = F_18 ( V_2 , & V_46 , & V_52 ) ;
if ( V_19 ) {
F_8 ( L_2 , V_19 ) ;
return V_19 ;
}
V_11 = F_2 ( V_52 ) ;
V_33 = F_23 ( V_51 ) ;
if ( ! V_33 )
return - V_63 ;
V_35 = F_24 ( V_50 ) ;
if ( F_25 ( V_35 ) ) {
V_19 = F_26 ( V_35 ) ;
goto V_64;
}
V_35 -> V_38 = V_2 ;
V_19 = F_27 ( V_49 , & V_2 -> V_15 , & V_46 , V_52 ) ;
if ( V_19 )
goto V_65;
V_2 -> V_33 = V_33 ;
V_2 -> V_51 = V_51 ;
V_57 = & V_2 -> V_15 . V_16 ;
V_2 -> V_50 . V_57 = V_57 ;
strcpy ( V_35 -> V_66 . V_67 , L_3 ) ;
V_35 -> V_25 = V_68 | V_69 ;
V_35 -> V_70 = & V_71 ;
V_35 -> V_72 -> V_73 [ 0 ] . V_16 = F_28 ( V_49 -> V_74 , 0 ) ;
V_35 -> V_72 -> V_73 [ 0 ] . V_51 = F_29 ( V_49 -> V_74 , 0 ) ;
F_30 ( V_35 , V_57 -> V_32 [ 0 ] , V_57 -> V_17 -> V_75 ) ;
F_31 ( V_35 , & V_2 -> V_50 , V_55 -> V_76 , V_55 -> V_77 ) ;
V_35 -> V_78 = V_33 ;
V_35 -> V_79 = V_51 ;
V_35 -> V_80 . V_25 = V_81 ;
F_32 ( L_4 ,
V_57 -> V_5 , V_57 -> V_6 ) ;
return 0 ;
V_65:
F_33 ( V_50 ) ;
V_64:
F_34 ( V_33 ) ;
return V_19 ;
}
static void F_35 ( struct V_82 * V_83 , T_2 V_84 , T_2 V_85 ,
T_2 V_86 , int V_87 )
{
struct V_88 * V_88 = F_36 ( V_83 ) ;
V_88 -> V_89 [ V_87 ] = V_84 >> 8 ;
V_88 -> V_90 [ V_87 ] = V_85 >> 8 ;
V_88 -> V_91 [ V_87 ] = V_86 >> 8 ;
}
static void F_37 ( struct V_82 * V_83 , T_2 * V_84 , T_2 * V_85 ,
T_2 * V_86 , int V_87 )
{
struct V_88 * V_88 = F_36 ( V_83 ) ;
* V_84 = V_88 -> V_89 [ V_87 ] << 8 ;
* V_85 = V_88 -> V_90 [ V_87 ] << 8 ;
* V_86 = V_88 -> V_91 [ V_87 ] << 8 ;
}
static void F_38 ( struct V_48 * V_49 ,
struct V_1 * V_2 )
{
struct V_92 * V_15 = & V_2 -> V_15 ;
F_39 ( & V_2 -> V_50 ) ;
F_33 ( & V_2 -> V_50 ) ;
if ( V_15 -> V_9 ) {
F_40 ( V_15 -> V_9 ) ;
V_15 -> V_9 = NULL ;
}
F_41 ( & V_2 -> V_50 ) ;
F_34 ( V_2 -> V_33 ) ;
F_42 ( & V_15 -> V_16 ) ;
F_43 ( & V_15 -> V_16 ) ;
}
int F_44 ( struct V_48 * V_49 )
{
struct V_93 * V_94 = V_49 -> V_95 ;
struct V_1 * V_2 ;
int V_19 ;
V_2 = F_45 ( sizeof( struct V_1 ) , V_96 ) ;
if ( ! V_2 )
return - V_63 ;
V_94 -> V_97 = V_2 ;
F_46 ( & V_2 -> V_26 ) ;
F_47 ( V_49 , & V_2 -> V_50 , & V_98 ) ;
V_19 = F_48 ( V_49 , & V_2 -> V_50 , 1 ) ;
if ( V_19 )
goto free;
V_19 = F_49 ( & V_2 -> V_50 ) ;
if ( V_19 )
goto V_99;
F_50 ( V_49 ) ;
V_19 = F_51 ( & V_2 -> V_50 , 32 ) ;
if ( V_19 )
goto V_99;
return 0 ;
V_99:
F_41 ( & V_2 -> V_50 ) ;
free:
F_52 ( V_2 ) ;
return V_19 ;
}
void F_53 ( struct V_48 * V_49 )
{
struct V_93 * V_94 = V_49 -> V_95 ;
if ( ! V_94 -> V_97 )
return;
F_38 ( V_49 , V_94 -> V_97 ) ;
F_52 ( V_94 -> V_97 ) ;
V_94 -> V_97 = NULL ;
}
void F_54 ( struct V_48 * V_49 , int V_100 )
{
struct V_93 * V_94 = V_49 -> V_95 ;
if ( ! V_94 -> V_97 )
return;
F_55 ( & V_94 -> V_97 -> V_50 , V_100 ) ;
}
void F_56 ( struct V_93 * V_94 , unsigned long V_101 )
{
V_94 -> V_97 -> V_50 . V_97 -> V_66 . V_102 =
V_94 -> V_97 -> V_50 . V_97 -> V_72 -> V_73 [ 0 ] . V_16 + V_101 ;
V_94 -> V_97 -> V_50 . V_97 -> V_66 . V_103 = V_94 -> V_104 - V_101 ;
}
