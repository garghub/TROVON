static void F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 , int V_5 , int V_6 )
{
int V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
int V_12 , V_13 ;
int V_14 = ( V_2 -> V_15 . V_16 . V_17 + 7 ) / 8 ;
int V_18 ;
bool V_19 = false ;
bool V_20 = false ;
int V_21 , V_22 ;
unsigned long V_23 ;
V_9 = V_2 -> V_15 . V_9 ;
V_11 = F_2 ( V_9 ) ;
V_18 = F_3 ( V_11 , true ) ;
if ( V_18 ) {
if ( V_18 != - V_24 )
return;
V_20 = true ;
}
V_21 = V_3 + V_5 - 1 ;
V_22 = V_4 + V_6 - 1 ;
F_4 ( & V_2 -> V_25 , V_23 ) ;
if ( V_2 -> y1 < V_4 )
V_4 = V_2 -> y1 ;
if ( V_2 -> V_22 > V_22 )
V_22 = V_2 -> V_22 ;
if ( V_2 -> V_26 < V_3 )
V_3 = V_2 -> V_26 ;
if ( V_2 -> V_21 > V_21 )
V_21 = V_2 -> V_21 ;
if ( V_20 ) {
V_2 -> V_26 = V_3 ;
V_2 -> V_21 = V_21 ;
V_2 -> y1 = V_4 ;
V_2 -> V_22 = V_22 ;
F_5 ( & V_2 -> V_25 , V_23 ) ;
return;
}
V_2 -> V_26 = V_2 -> y1 = V_27 ;
V_2 -> V_21 = V_2 -> V_22 = 0 ;
F_5 ( & V_2 -> V_25 , V_23 ) ;
if ( ! V_11 -> V_28 . V_29 ) {
V_18 = F_6 ( & V_11 -> V_11 , 0 , V_11 -> V_11 . V_30 , & V_11 -> V_28 ) ;
if ( V_18 ) {
F_7 ( L_1 ) ;
F_8 ( V_11 ) ;
return;
}
V_19 = true ;
}
for ( V_7 = V_4 ; V_7 < V_4 + V_6 ; V_7 ++ ) {
V_12 = V_13 = V_7 * V_2 -> V_15 . V_16 . V_31 [ 0 ] + ( V_3 * V_14 ) ;
F_9 ( V_11 -> V_28 . V_29 + V_12 , V_2 -> V_32 + V_12 , V_5 * V_14 ) ;
}
if ( V_19 )
F_10 ( & V_11 -> V_28 ) ;
F_8 ( V_11 ) ;
}
static void F_11 ( struct V_33 * V_34 ,
const struct V_35 * V_36 )
{
struct V_1 * V_2 = V_34 -> V_37 ;
F_12 ( V_34 , V_36 ) ;
F_1 ( V_2 , V_36 -> V_38 , V_36 -> V_39 , V_36 -> V_5 ,
V_36 -> V_6 ) ;
}
static void F_13 ( struct V_33 * V_34 ,
const struct V_40 * V_41 )
{
struct V_1 * V_2 = V_34 -> V_37 ;
F_14 ( V_34 , V_41 ) ;
F_1 ( V_2 , V_41 -> V_38 , V_41 -> V_39 , V_41 -> V_5 ,
V_41 -> V_6 ) ;
}
static void F_15 ( struct V_33 * V_34 ,
const struct V_42 * V_43 )
{
struct V_1 * V_2 = V_34 -> V_37 ;
F_16 ( V_34 , V_43 ) ;
F_1 ( V_2 , V_43 -> V_38 , V_43 -> V_39 , V_43 -> V_5 ,
V_43 -> V_6 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_44 * V_45 ,
struct V_8 * * V_46 )
{
struct V_47 * V_48 = V_2 -> V_49 . V_48 ;
T_1 V_14 , V_50 ;
T_1 V_51 ;
struct V_8 * V_52 ;
int V_18 = 0 ;
F_18 ( V_45 -> V_53 , & V_50 , & V_14 ) ;
if ( V_14 > 24 )
return - V_54 ;
V_51 = V_45 -> V_31 [ 0 ] * V_45 -> V_6 ;
V_18 = F_19 ( V_48 , V_51 , true , & V_52 ) ;
if ( V_18 )
return V_18 ;
* V_46 = V_52 ;
return V_18 ;
}
static int F_20 ( struct V_55 * V_49 ,
struct V_56 * V_57 )
{
struct V_1 * V_58 = (struct V_1 * ) V_49 ;
struct V_47 * V_48 = V_58 -> V_49 . V_48 ;
struct V_59 * V_60 = V_58 -> V_49 . V_48 -> V_61 ;
struct V_33 * V_34 ;
struct V_62 * V_63 ;
struct V_44 V_45 ;
struct V_64 * V_64 = & V_48 -> V_65 -> V_48 ;
void * V_32 ;
struct V_8 * V_52 = NULL ;
struct V_10 * V_11 = NULL ;
int V_51 , V_18 ;
V_45 . V_5 = V_57 -> V_66 ;
V_45 . V_6 = V_57 -> V_67 ;
V_45 . V_31 [ 0 ] = V_45 . V_5 * ( ( V_57 -> V_68 + 7 ) / 8 ) ;
V_45 . V_53 = F_21 ( V_57 -> V_68 ,
V_57 -> V_69 ) ;
V_51 = V_45 . V_31 [ 0 ] * V_45 . V_6 ;
V_18 = F_17 ( V_58 , & V_45 , & V_52 ) ;
if ( V_18 ) {
F_7 ( L_2 , V_18 ) ;
return V_18 ;
}
V_11 = F_2 ( V_52 ) ;
V_32 = F_22 ( V_51 ) ;
if ( ! V_32 )
return - V_70 ;
V_34 = F_23 ( 0 , V_64 ) ;
if ( V_34 == NULL )
return - V_70 ;
V_34 -> V_37 = V_58 ;
V_18 = F_24 ( V_60 -> V_48 , & V_58 -> V_15 , & V_45 , V_52 ) ;
if ( V_18 )
return V_18 ;
V_58 -> V_32 = V_32 ;
V_58 -> V_51 = V_51 ;
V_63 = & V_58 -> V_15 . V_16 ;
if ( ! V_63 ) {
F_25 ( L_3 ) ;
return - V_54 ;
}
V_58 -> V_49 . V_63 = V_63 ;
V_58 -> V_49 . V_71 = V_34 ;
strcpy ( V_34 -> V_72 . V_73 , L_4 ) ;
V_34 -> V_23 = V_74 ;
V_34 -> V_75 = & V_76 ;
F_26 ( V_34 , V_63 -> V_31 [ 0 ] , V_63 -> V_50 ) ;
F_27 ( V_34 , & V_58 -> V_49 , V_57 -> V_77 ,
V_57 -> V_78 ) ;
V_34 -> V_79 = F_28 ( 1 ) ;
if ( ! V_34 -> V_79 ) {
V_18 = - V_70 ;
goto V_80;
}
V_34 -> V_79 -> V_81 [ 0 ] . V_16 = V_60 -> V_48 -> V_82 . V_83 ;
V_34 -> V_79 -> V_81 [ 0 ] . V_51 = V_60 -> V_84 . V_85 ;
V_34 -> V_86 = V_32 ;
V_34 -> V_87 = V_51 ;
V_34 -> V_72 . V_88 = 0 ;
V_34 -> V_72 . V_89 = 0 ;
V_18 = F_29 ( & V_34 -> V_90 , 256 , 0 ) ;
if ( V_18 ) {
F_7 ( L_5 , V_34 -> V_72 . V_73 ) ;
V_18 = - V_70 ;
goto V_80;
}
F_25 ( L_6 , V_34 -> V_72 . V_91 ) ;
F_25 ( L_7 , ( unsigned long ) V_34 -> V_72 . V_91 ) ;
F_25 ( L_8 , ( unsigned long ) V_34 -> V_72 . V_92 ) ;
F_25 ( L_9 , V_63 -> V_50 ) ;
F_25 ( L_10 , V_63 -> V_31 [ 0 ] ) ;
return 0 ;
V_80:
return V_18 ;
}
static int F_30 ( struct V_47 * V_48 ,
struct V_1 * V_58 )
{
struct V_33 * V_34 ;
struct V_93 * V_15 = & V_58 -> V_15 ;
if ( V_58 -> V_49 . V_71 ) {
V_34 = V_58 -> V_49 . V_71 ;
F_31 ( V_34 ) ;
if ( V_34 -> V_90 . V_94 )
F_32 ( & V_34 -> V_90 ) ;
F_33 ( V_34 ) ;
}
if ( V_15 -> V_9 ) {
F_34 ( V_15 -> V_9 ) ;
V_15 -> V_9 = NULL ;
}
F_35 ( V_58 -> V_32 ) ;
F_36 ( & V_58 -> V_49 ) ;
F_37 ( & V_15 -> V_16 ) ;
F_38 ( & V_15 -> V_16 ) ;
return 0 ;
}
int F_39 ( struct V_59 * V_60 )
{
struct V_1 * V_58 ;
int V_18 ;
int V_95 = 24 ;
V_58 = F_40 ( sizeof( struct V_1 ) , V_96 ) ;
if ( ! V_58 )
return - V_70 ;
V_60 -> V_97 . V_58 = V_58 ;
V_58 -> V_49 . V_98 = & V_99 ;
F_41 ( & V_58 -> V_25 ) ;
V_18 = F_42 ( V_60 -> V_48 , & V_58 -> V_49 ,
V_60 -> V_100 , V_101 ) ;
if ( V_18 ) {
F_43 ( V_58 ) ;
return V_18 ;
}
F_44 ( & V_58 -> V_49 ) ;
F_45 ( V_60 -> V_48 ) ;
F_46 ( & V_58 -> V_49 , V_95 ) ;
return 0 ;
}
void F_47 ( struct V_59 * V_60 )
{
if ( ! V_60 -> V_97 . V_58 )
return;
F_30 ( V_60 -> V_48 , V_60 -> V_97 . V_58 ) ;
F_43 ( V_60 -> V_97 . V_58 ) ;
V_60 -> V_97 . V_58 = NULL ;
}
