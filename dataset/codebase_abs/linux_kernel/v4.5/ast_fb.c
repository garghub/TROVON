static void F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 , int V_5 , int V_6 )
{
int V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
int V_12 , V_13 ;
int V_14 = ( V_2 -> V_15 . V_16 . V_17 + 7 ) / 8 ;
int V_18 = - V_19 ;
bool V_20 = false ;
bool V_21 = false ;
int V_22 , V_23 ;
unsigned long V_24 ;
V_9 = V_2 -> V_15 . V_9 ;
V_11 = F_2 ( V_9 ) ;
if ( F_3 () )
V_18 = F_4 ( V_11 , true ) ;
if ( V_18 ) {
if ( V_18 != - V_19 )
return;
V_21 = true ;
}
V_22 = V_3 + V_5 - 1 ;
V_23 = V_4 + V_6 - 1 ;
F_5 ( & V_2 -> V_25 , V_24 ) ;
if ( V_2 -> y1 < V_4 )
V_4 = V_2 -> y1 ;
if ( V_2 -> V_23 > V_23 )
V_23 = V_2 -> V_23 ;
if ( V_2 -> V_26 < V_3 )
V_3 = V_2 -> V_26 ;
if ( V_2 -> V_22 > V_22 )
V_22 = V_2 -> V_22 ;
if ( V_21 ) {
V_2 -> V_26 = V_3 ;
V_2 -> V_22 = V_22 ;
V_2 -> y1 = V_4 ;
V_2 -> V_23 = V_23 ;
F_6 ( & V_2 -> V_25 , V_24 ) ;
return;
}
V_2 -> V_26 = V_2 -> y1 = V_27 ;
V_2 -> V_22 = V_2 -> V_23 = 0 ;
F_6 ( & V_2 -> V_25 , V_24 ) ;
if ( ! V_11 -> V_28 . V_29 ) {
V_18 = F_7 ( & V_11 -> V_11 , 0 , V_11 -> V_11 . V_30 , & V_11 -> V_28 ) ;
if ( V_18 ) {
F_8 ( L_1 ) ;
F_9 ( V_11 ) ;
return;
}
V_20 = true ;
}
for ( V_7 = V_4 ; V_7 <= V_23 ; V_7 ++ ) {
V_12 = V_13 = V_7 * V_2 -> V_15 . V_16 . V_31 [ 0 ] + ( V_3 * V_14 ) ;
F_10 ( V_11 -> V_28 . V_29 + V_12 , V_2 -> V_32 + V_12 , ( V_22 - V_3 + 1 ) * V_14 ) ;
}
if ( V_20 )
F_11 ( & V_11 -> V_28 ) ;
F_9 ( V_11 ) ;
}
static void F_12 ( struct V_33 * V_34 ,
const struct V_35 * V_36 )
{
struct V_1 * V_2 = V_34 -> V_37 ;
F_13 ( V_34 , V_36 ) ;
F_1 ( V_2 , V_36 -> V_38 , V_36 -> V_39 , V_36 -> V_5 ,
V_36 -> V_6 ) ;
}
static void F_14 ( struct V_33 * V_34 ,
const struct V_40 * V_41 )
{
struct V_1 * V_2 = V_34 -> V_37 ;
F_15 ( V_34 , V_41 ) ;
F_1 ( V_2 , V_41 -> V_38 , V_41 -> V_39 , V_41 -> V_5 ,
V_41 -> V_6 ) ;
}
static void F_16 ( struct V_33 * V_34 ,
const struct V_42 * V_43 )
{
struct V_1 * V_2 = V_34 -> V_37 ;
F_17 ( V_34 , V_43 ) ;
F_1 ( V_2 , V_43 -> V_38 , V_43 -> V_39 , V_43 -> V_5 ,
V_43 -> V_6 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
const struct V_44 * V_45 ,
struct V_8 * * V_46 )
{
struct V_47 * V_48 = V_2 -> V_49 . V_48 ;
T_1 V_14 , V_50 ;
T_1 V_51 ;
struct V_8 * V_52 ;
int V_18 = 0 ;
F_19 ( V_45 -> V_53 , & V_50 , & V_14 ) ;
V_51 = V_45 -> V_31 [ 0 ] * V_45 -> V_6 ;
V_18 = F_20 ( V_48 , V_51 , true , & V_52 ) ;
if ( V_18 )
return V_18 ;
* V_46 = V_52 ;
return V_18 ;
}
static int F_21 ( struct V_54 * V_49 ,
struct V_55 * V_56 )
{
struct V_1 * V_2 =
F_22 ( V_49 , struct V_1 , V_49 ) ;
struct V_47 * V_48 = V_2 -> V_49 . V_48 ;
struct V_44 V_45 ;
struct V_57 * V_58 ;
struct V_33 * V_34 ;
int V_51 , V_18 ;
void * V_32 ;
struct V_8 * V_52 = NULL ;
struct V_10 * V_11 = NULL ;
V_45 . V_5 = V_56 -> V_59 ;
V_45 . V_6 = V_56 -> V_60 ;
V_45 . V_31 [ 0 ] = V_45 . V_5 * ( ( V_56 -> V_61 + 7 ) / 8 ) ;
V_45 . V_53 = F_23 ( V_56 -> V_61 ,
V_56 -> V_62 ) ;
V_51 = V_45 . V_31 [ 0 ] * V_45 . V_6 ;
V_18 = F_18 ( V_2 , & V_45 , & V_52 ) ;
if ( V_18 ) {
F_8 ( L_2 , V_18 ) ;
return V_18 ;
}
V_11 = F_2 ( V_52 ) ;
V_32 = F_24 ( V_51 ) ;
if ( ! V_32 )
return - V_63 ;
V_34 = F_25 ( V_49 ) ;
if ( F_26 ( V_34 ) ) {
V_18 = F_27 ( V_34 ) ;
goto V_64;
}
V_34 -> V_37 = V_2 ;
V_18 = F_28 ( V_48 , & V_2 -> V_15 , & V_45 , V_52 ) ;
if ( V_18 )
goto V_65;
V_2 -> V_32 = V_32 ;
V_2 -> V_51 = V_51 ;
V_58 = & V_2 -> V_15 . V_16 ;
V_2 -> V_49 . V_58 = V_58 ;
strcpy ( V_34 -> V_66 . V_67 , L_3 ) ;
V_34 -> V_24 = V_68 | V_69 ;
V_34 -> V_70 = & V_71 ;
V_34 -> V_72 -> V_73 [ 0 ] . V_16 = F_29 ( V_48 -> V_74 , 0 ) ;
V_34 -> V_72 -> V_73 [ 0 ] . V_51 = F_30 ( V_48 -> V_74 , 0 ) ;
F_31 ( V_34 , V_58 -> V_31 [ 0 ] , V_58 -> V_50 ) ;
F_32 ( V_34 , & V_2 -> V_49 , V_56 -> V_75 , V_56 -> V_76 ) ;
V_34 -> V_77 = V_32 ;
V_34 -> V_78 = V_51 ;
V_34 -> V_79 . V_24 = V_80 ;
F_33 ( L_4 ,
V_58 -> V_5 , V_58 -> V_6 ) ;
return 0 ;
V_65:
F_34 ( V_49 ) ;
V_64:
F_35 ( V_2 -> V_32 ) ;
return V_18 ;
}
static void F_36 ( struct V_81 * V_82 , T_2 V_83 , T_2 V_84 ,
T_2 V_85 , int V_86 )
{
struct V_87 * V_87 = F_37 ( V_82 ) ;
V_87 -> V_88 [ V_86 ] = V_83 >> 8 ;
V_87 -> V_89 [ V_86 ] = V_84 >> 8 ;
V_87 -> V_90 [ V_86 ] = V_85 >> 8 ;
}
static void F_38 ( struct V_81 * V_82 , T_2 * V_83 , T_2 * V_84 ,
T_2 * V_85 , int V_86 )
{
struct V_87 * V_87 = F_37 ( V_82 ) ;
* V_83 = V_87 -> V_88 [ V_86 ] << 8 ;
* V_84 = V_87 -> V_89 [ V_86 ] << 8 ;
* V_85 = V_87 -> V_90 [ V_86 ] << 8 ;
}
static void F_39 ( struct V_47 * V_48 ,
struct V_1 * V_2 )
{
struct V_91 * V_15 = & V_2 -> V_15 ;
F_40 ( & V_2 -> V_49 ) ;
F_34 ( & V_2 -> V_49 ) ;
if ( V_15 -> V_9 ) {
F_41 ( V_15 -> V_9 ) ;
V_15 -> V_9 = NULL ;
}
F_42 ( & V_2 -> V_49 ) ;
F_35 ( V_2 -> V_32 ) ;
F_43 ( & V_15 -> V_16 ) ;
F_44 ( & V_15 -> V_16 ) ;
}
int F_45 ( struct V_47 * V_48 )
{
struct V_92 * V_93 = V_48 -> V_94 ;
struct V_1 * V_2 ;
int V_18 ;
V_2 = F_46 ( sizeof( struct V_1 ) , V_95 ) ;
if ( ! V_2 )
return - V_63 ;
V_93 -> V_96 = V_2 ;
F_47 ( & V_2 -> V_25 ) ;
F_48 ( V_48 , & V_2 -> V_49 , & V_97 ) ;
V_18 = F_49 ( V_48 , & V_2 -> V_49 ,
1 , 1 ) ;
if ( V_18 )
goto free;
V_18 = F_50 ( & V_2 -> V_49 ) ;
if ( V_18 )
goto V_98;
F_51 ( V_48 ) ;
V_18 = F_52 ( & V_2 -> V_49 , 32 ) ;
if ( V_18 )
goto V_98;
return 0 ;
V_98:
F_42 ( & V_2 -> V_49 ) ;
free:
F_53 ( V_2 ) ;
return V_18 ;
}
void F_54 ( struct V_47 * V_48 )
{
struct V_92 * V_93 = V_48 -> V_94 ;
if ( ! V_93 -> V_96 )
return;
F_39 ( V_48 , V_93 -> V_96 ) ;
F_53 ( V_93 -> V_96 ) ;
V_93 -> V_96 = NULL ;
}
void F_55 ( struct V_47 * V_48 , int V_99 )
{
struct V_92 * V_93 = V_48 -> V_94 ;
if ( ! V_93 -> V_96 )
return;
F_56 ( & V_93 -> V_96 -> V_49 , V_99 ) ;
}
void F_57 ( struct V_92 * V_93 , unsigned long V_100 )
{
V_93 -> V_96 -> V_49 . V_96 -> V_66 . V_101 =
V_93 -> V_96 -> V_49 . V_96 -> V_72 -> V_73 [ 0 ] . V_16 + V_100 ;
V_93 -> V_96 -> V_49 . V_96 -> V_66 . V_102 = V_93 -> V_103 - V_100 ;
}
