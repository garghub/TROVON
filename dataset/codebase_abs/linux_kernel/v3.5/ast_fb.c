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
V_9 = V_2 -> V_15 . V_9 ;
V_11 = F_2 ( V_9 ) ;
V_18 = F_3 ( V_11 , true ) ;
if ( V_18 ) {
F_4 ( L_1 ) ;
return;
}
if ( ! V_11 -> V_20 . V_21 ) {
V_18 = F_5 ( & V_11 -> V_11 , 0 , V_11 -> V_11 . V_22 , & V_11 -> V_20 ) ;
if ( V_18 ) {
F_4 ( L_2 ) ;
F_6 ( V_11 ) ;
return;
}
V_19 = true ;
}
for ( V_7 = V_4 ; V_7 < V_4 + V_6 ; V_7 ++ ) {
V_12 = V_13 = V_7 * V_2 -> V_15 . V_16 . V_23 [ 0 ] + ( V_3 * V_14 ) ;
F_7 ( V_11 -> V_20 . V_21 + V_12 , V_2 -> V_24 + V_12 , V_5 * V_14 ) ;
}
if ( V_19 )
F_8 ( & V_11 -> V_20 ) ;
F_6 ( V_11 ) ;
}
static void F_9 ( struct V_25 * V_26 ,
const struct V_27 * V_28 )
{
struct V_1 * V_2 = V_26 -> V_29 ;
F_10 ( V_26 , V_28 ) ;
F_1 ( V_2 , V_28 -> V_30 , V_28 -> V_31 , V_28 -> V_5 ,
V_28 -> V_6 ) ;
}
static void F_11 ( struct V_25 * V_26 ,
const struct V_32 * V_33 )
{
struct V_1 * V_2 = V_26 -> V_29 ;
F_12 ( V_26 , V_33 ) ;
F_1 ( V_2 , V_33 -> V_30 , V_33 -> V_31 , V_33 -> V_5 ,
V_33 -> V_6 ) ;
}
static void F_13 ( struct V_25 * V_26 ,
const struct V_34 * V_35 )
{
struct V_1 * V_2 = V_26 -> V_29 ;
F_14 ( V_26 , V_35 ) ;
F_1 ( V_2 , V_35 -> V_30 , V_35 -> V_31 , V_35 -> V_5 ,
V_35 -> V_6 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_36 * V_37 ,
struct V_8 * * V_38 )
{
struct V_39 * V_40 = V_2 -> V_41 . V_40 ;
T_1 V_14 , V_42 ;
T_1 V_43 ;
struct V_8 * V_44 ;
int V_18 = 0 ;
F_16 ( V_37 -> V_45 , & V_42 , & V_14 ) ;
V_43 = V_37 -> V_23 [ 0 ] * V_37 -> V_6 ;
V_18 = F_17 ( V_40 , V_43 , true , & V_44 ) ;
if ( V_18 )
return V_18 ;
* V_38 = V_44 ;
return V_18 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_46 * V_47 )
{
struct V_39 * V_40 = V_2 -> V_41 . V_40 ;
struct V_36 V_37 ;
struct V_48 * V_49 ;
struct V_25 * V_26 ;
int V_43 , V_18 ;
struct V_50 * V_50 = & V_40 -> V_51 -> V_40 ;
void * V_24 ;
struct V_8 * V_44 = NULL ;
struct V_10 * V_11 = NULL ;
V_37 . V_5 = V_47 -> V_52 ;
V_37 . V_6 = V_47 -> V_53 ;
V_37 . V_23 [ 0 ] = V_37 . V_5 * ( ( V_47 -> V_54 + 7 ) / 8 ) ;
V_37 . V_45 = F_19 ( V_47 -> V_54 ,
V_47 -> V_55 ) ;
V_43 = V_37 . V_23 [ 0 ] * V_37 . V_6 ;
V_18 = F_15 ( V_2 , & V_37 , & V_44 ) ;
if ( V_18 ) {
F_4 ( L_3 , V_18 ) ;
return V_18 ;
}
V_11 = F_2 ( V_44 ) ;
V_24 = F_20 ( V_43 ) ;
if ( ! V_24 )
return - V_56 ;
V_26 = F_21 ( 0 , V_50 ) ;
if ( ! V_26 ) {
V_18 = - V_56 ;
goto V_57;
}
V_26 -> V_29 = V_2 ;
V_18 = F_22 ( V_40 , & V_2 -> V_15 , & V_37 , V_44 ) ;
if ( V_18 )
goto V_57;
V_2 -> V_24 = V_24 ;
V_2 -> V_43 = V_43 ;
V_49 = & V_2 -> V_15 . V_16 ;
V_2 -> V_41 . V_49 = V_49 ;
V_2 -> V_41 . V_58 = V_26 ;
strcpy ( V_26 -> V_59 . V_60 , L_4 ) ;
V_26 -> V_61 = V_62 | V_63 ;
V_26 -> V_64 = & V_65 ;
V_18 = F_23 ( & V_26 -> V_66 , 256 , 0 ) ;
if ( V_18 ) {
V_18 = - V_56 ;
goto V_57;
}
V_26 -> V_67 = F_24 ( 1 ) ;
if ( ! V_26 -> V_67 ) {
V_18 = - V_56 ;
goto V_57;
}
V_26 -> V_67 -> V_68 [ 0 ] . V_16 = F_25 ( V_40 -> V_51 , 0 ) ;
V_26 -> V_67 -> V_68 [ 0 ] . V_43 = F_26 ( V_40 -> V_51 , 0 ) ;
F_27 ( V_26 , V_49 -> V_23 [ 0 ] , V_49 -> V_42 ) ;
F_28 ( V_26 , & V_2 -> V_41 , V_47 -> V_69 , V_47 -> V_70 ) ;
V_26 -> V_71 = V_24 ;
V_26 -> V_72 = V_43 ;
V_26 -> V_73 . V_61 = V_74 ;
F_29 ( L_5 ,
V_49 -> V_5 , V_49 -> V_6 ) ;
return 0 ;
V_57:
return V_18 ;
}
static void F_30 ( struct V_75 * V_76 , T_2 V_77 , T_2 V_78 ,
T_2 V_79 , int V_80 )
{
struct V_81 * V_81 = F_31 ( V_76 ) ;
V_81 -> V_82 [ V_80 ] = V_77 >> 8 ;
V_81 -> V_83 [ V_80 ] = V_78 >> 8 ;
V_81 -> V_84 [ V_80 ] = V_79 >> 8 ;
}
static void F_32 ( struct V_75 * V_76 , T_2 * V_77 , T_2 * V_78 ,
T_2 * V_79 , int V_80 )
{
struct V_81 * V_81 = F_31 ( V_76 ) ;
* V_77 = V_81 -> V_82 [ V_80 ] << 8 ;
* V_78 = V_81 -> V_83 [ V_80 ] << 8 ;
* V_79 = V_81 -> V_84 [ V_80 ] << 8 ;
}
static int F_33 ( struct V_85 * V_41 ,
struct V_46 * V_47 )
{
struct V_1 * V_2 = (struct V_1 * ) V_41 ;
int V_86 = 0 ;
int V_18 ;
if ( ! V_41 -> V_49 ) {
V_18 = F_18 ( V_2 , V_47 ) ;
if ( V_18 )
return V_18 ;
V_86 = 1 ;
}
return V_86 ;
}
static void F_34 ( struct V_39 * V_40 ,
struct V_1 * V_2 )
{
struct V_25 * V_26 ;
struct V_87 * V_15 = & V_2 -> V_15 ;
if ( V_2 -> V_41 . V_58 ) {
V_26 = V_2 -> V_41 . V_58 ;
F_35 ( V_26 ) ;
if ( V_26 -> V_66 . V_88 )
F_36 ( & V_26 -> V_66 ) ;
F_37 ( V_26 ) ;
}
if ( V_15 -> V_9 ) {
F_38 ( V_15 -> V_9 ) ;
V_15 -> V_9 = NULL ;
}
F_39 ( & V_2 -> V_41 ) ;
F_40 ( V_2 -> V_24 ) ;
F_41 ( & V_15 -> V_16 ) ;
}
int F_42 ( struct V_39 * V_40 )
{
struct V_89 * V_90 = V_40 -> V_91 ;
struct V_1 * V_2 ;
int V_18 ;
V_2 = F_43 ( sizeof( struct V_1 ) , V_92 ) ;
if ( ! V_2 )
return - V_56 ;
V_90 -> V_58 = V_2 ;
V_2 -> V_41 . V_93 = & V_94 ;
V_18 = F_44 ( V_40 , & V_2 -> V_41 ,
1 , 1 ) ;
if ( V_18 ) {
F_45 ( V_2 ) ;
return V_18 ;
}
F_46 ( & V_2 -> V_41 ) ;
F_47 ( & V_2 -> V_41 , 32 ) ;
return 0 ;
}
void F_48 ( struct V_39 * V_40 )
{
struct V_89 * V_90 = V_40 -> V_91 ;
if ( ! V_90 -> V_58 )
return;
F_34 ( V_40 , V_90 -> V_58 ) ;
F_45 ( V_90 -> V_58 ) ;
V_90 -> V_58 = NULL ;
}
void F_49 ( struct V_39 * V_40 , int V_95 )
{
struct V_89 * V_90 = V_40 -> V_91 ;
if ( ! V_90 -> V_58 )
return;
F_50 ( V_90 -> V_58 -> V_41 . V_58 , V_95 ) ;
}
