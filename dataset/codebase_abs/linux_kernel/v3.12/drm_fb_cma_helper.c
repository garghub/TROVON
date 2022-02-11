static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 * F_3 ( struct V_6 * V_7 )
{
return F_2 ( V_7 , struct V_5 , V_7 ) ;
}
static void F_4 ( struct V_6 * V_7 )
{
struct V_5 * V_8 = F_3 ( V_7 ) ;
int V_9 ;
for ( V_9 = 0 ; V_9 < 4 ; V_9 ++ ) {
if ( V_8 -> V_10 [ V_9 ] )
F_5 ( & V_8 -> V_10 [ V_9 ] -> V_11 ) ;
}
F_6 ( V_7 ) ;
F_7 ( V_8 ) ;
}
static int F_8 ( struct V_6 * V_7 ,
struct V_12 * V_13 , unsigned int * V_14 )
{
struct V_5 * V_8 = F_3 ( V_7 ) ;
return F_9 ( V_13 ,
& V_8 -> V_10 [ 0 ] -> V_11 , V_14 ) ;
}
static struct V_5 * F_10 ( struct V_15 * V_16 ,
struct V_17 * V_18 , struct V_19 * * V_10 ,
unsigned int V_20 )
{
struct V_5 * V_8 ;
int V_21 ;
int V_9 ;
V_8 = F_11 ( sizeof( * V_8 ) , V_22 ) ;
if ( ! V_8 )
return F_12 ( - V_23 ) ;
F_13 ( & V_8 -> V_7 , V_18 ) ;
for ( V_9 = 0 ; V_9 < V_20 ; V_9 ++ )
V_8 -> V_10 [ V_9 ] = V_10 [ V_9 ] ;
V_21 = F_14 ( V_16 , & V_8 -> V_7 , & V_24 ) ;
if ( V_21 ) {
F_15 ( V_16 -> V_16 , L_1 , V_21 ) ;
F_7 ( V_8 ) ;
return F_12 ( V_21 ) ;
}
return V_8 ;
}
struct V_6 * F_16 ( struct V_15 * V_16 ,
struct V_12 * V_13 , struct V_17 * V_18 )
{
struct V_5 * V_8 ;
struct V_19 * V_25 [ 4 ] ;
struct V_26 * V_10 ;
unsigned int V_27 ;
unsigned int V_28 ;
int V_21 ;
int V_9 ;
V_27 = F_17 ( V_18 -> V_29 ) ;
V_28 = F_18 ( V_18 -> V_29 ) ;
for ( V_9 = 0 ; V_9 < F_19 ( V_18 -> V_29 ) ; V_9 ++ ) {
unsigned int V_30 = V_18 -> V_30 / ( V_9 ? V_27 : 1 ) ;
unsigned int V_31 = V_18 -> V_31 / ( V_9 ? V_28 : 1 ) ;
unsigned int V_32 ;
V_10 = F_20 ( V_16 , V_13 , V_18 -> V_33 [ V_9 ] ) ;
if ( ! V_10 ) {
F_15 ( V_16 -> V_16 , L_2 ) ;
V_21 = - V_34 ;
goto V_35;
}
V_32 = ( V_31 - 1 ) * V_18 -> V_36 [ V_9 ]
+ V_30 * F_21 ( V_18 -> V_29 , V_9 )
+ V_18 -> V_37 [ V_9 ] ;
if ( V_10 -> V_38 < V_32 ) {
F_5 ( V_10 ) ;
V_21 = - V_39 ;
goto V_35;
}
V_25 [ V_9 ] = F_22 ( V_10 ) ;
}
V_8 = F_10 ( V_16 , V_18 , V_25 , V_9 ) ;
if ( F_23 ( V_8 ) ) {
V_21 = F_24 ( V_8 ) ;
goto V_35;
}
return & V_8 -> V_7 ;
V_35:
for ( V_9 -- ; V_9 >= 0 ; V_9 -- )
F_5 ( & V_25 [ V_9 ] -> V_11 ) ;
return F_12 ( V_21 ) ;
}
struct V_19 * F_25 ( struct V_6 * V_7 ,
unsigned int V_40 )
{
struct V_5 * V_8 = F_3 ( V_7 ) ;
if ( V_40 >= 4 )
return NULL ;
return V_8 -> V_10 [ V_40 ] ;
}
static void F_26 ( struct V_6 * V_7 , struct V_41 * V_42 )
{
struct V_5 * V_8 = F_3 ( V_7 ) ;
int V_9 , V_43 = F_19 ( V_7 -> V_29 ) ;
F_27 ( V_42 , L_3 , V_7 -> V_30 , V_7 -> V_31 ,
( char * ) & V_7 -> V_29 ) ;
for ( V_9 = 0 ; V_9 < V_43 ; V_9 ++ ) {
F_27 ( V_42 , L_4 ,
V_9 , V_7 -> V_37 [ V_9 ] , V_7 -> V_36 [ V_9 ] ) ;
F_28 ( V_8 -> V_10 [ V_9 ] , V_42 ) ;
}
}
int F_29 ( struct V_41 * V_42 , void * V_44 )
{
struct V_45 * V_46 = (struct V_45 * ) V_42 -> V_47 ;
struct V_15 * V_16 = V_46 -> V_48 -> V_16 ;
struct V_6 * V_7 ;
int V_21 ;
V_21 = F_30 ( & V_16 -> V_49 . V_50 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_30 ( & V_16 -> V_51 ) ;
if ( V_21 ) {
F_31 ( & V_16 -> V_49 . V_50 ) ;
return V_21 ;
}
F_32 (fb, &dev->mode_config.fb_list, head)
F_26 ( V_7 , V_42 ) ;
F_31 ( & V_16 -> V_51 ) ;
F_31 ( & V_16 -> V_49 . V_50 ) ;
return 0 ;
}
static int F_33 ( struct V_2 * V_3 ,
struct V_52 * V_53 )
{
struct V_1 * V_54 = F_1 ( V_3 ) ;
struct V_17 V_18 = { 0 } ;
struct V_15 * V_16 = V_3 -> V_16 ;
struct V_19 * V_10 ;
struct V_6 * V_7 ;
unsigned int V_55 ;
unsigned long V_56 ;
struct V_57 * V_58 ;
T_1 V_38 ;
int V_21 ;
F_34 ( L_5 ,
V_53 -> V_59 , V_53 -> V_60 ,
V_53 -> V_61 ) ;
V_55 = F_35 ( V_53 -> V_61 , 8 ) ;
V_18 . V_30 = V_53 -> V_59 ;
V_18 . V_31 = V_53 -> V_60 ;
V_18 . V_36 [ 0 ] = V_53 -> V_59 * V_55 ;
V_18 . V_29 = F_36 ( V_53 -> V_61 ,
V_53 -> V_62 ) ;
V_38 = V_18 . V_36 [ 0 ] * V_18 . V_31 ;
V_10 = F_37 ( V_16 , V_38 ) ;
if ( F_23 ( V_10 ) )
return - V_23 ;
V_58 = F_38 ( 0 , V_16 -> V_16 ) ;
if ( ! V_58 ) {
F_15 ( V_16 -> V_16 , L_6 ) ;
V_21 = - V_23 ;
goto V_63;
}
V_54 -> V_7 = F_10 ( V_16 , & V_18 , & V_10 , 1 ) ;
if ( F_23 ( V_54 -> V_7 ) ) {
F_15 ( V_16 -> V_16 , L_7 ) ;
V_21 = F_24 ( V_54 -> V_7 ) ;
goto V_64;
}
V_7 = & V_54 -> V_7 -> V_7 ;
V_3 -> V_7 = V_7 ;
V_3 -> V_65 = V_58 ;
V_58 -> V_66 = V_3 ;
V_58 -> V_67 = V_68 ;
V_58 -> V_69 = & V_70 ;
V_21 = F_39 ( & V_58 -> V_71 , 256 , 0 ) ;
if ( V_21 ) {
F_15 ( V_16 -> V_16 , L_8 ) ;
goto V_72;
}
F_40 ( V_58 , V_7 -> V_36 [ 0 ] , V_7 -> V_73 ) ;
F_41 ( V_58 , V_3 , V_7 -> V_30 , V_7 -> V_31 ) ;
V_56 = V_58 -> V_74 . V_75 * V_55 ;
V_56 += V_58 -> V_74 . V_76 * V_7 -> V_36 [ 0 ] ;
V_16 -> V_49 . V_77 = ( V_78 ) V_10 -> V_79 ;
V_58 -> V_80 = V_10 -> V_81 + V_56 ;
V_58 -> V_82 . V_83 = ( unsigned long ) ( V_10 -> V_79 + V_56 ) ;
V_58 -> V_84 = V_38 ;
V_58 -> V_82 . V_85 = V_38 ;
return 0 ;
V_72:
F_42 ( V_7 ) ;
F_4 ( V_7 ) ;
V_64:
F_43 ( V_58 ) ;
V_63:
F_44 ( & V_10 -> V_11 ) ;
return V_21 ;
}
struct V_1 * F_45 ( struct V_15 * V_16 ,
unsigned int V_86 , unsigned int V_87 ,
unsigned int V_88 )
{
struct V_1 * V_54 ;
struct V_2 * V_3 ;
int V_21 ;
V_54 = F_11 ( sizeof( * V_54 ) , V_22 ) ;
if ( ! V_54 ) {
F_15 ( V_16 -> V_16 , L_9 ) ;
return F_12 ( - V_23 ) ;
}
V_54 -> V_4 . V_89 = & V_90 ;
V_3 = & V_54 -> V_4 ;
V_21 = F_46 ( V_16 , V_3 , V_87 , V_88 ) ;
if ( V_21 < 0 ) {
F_15 ( V_16 -> V_16 , L_10 ) ;
goto V_91;
}
V_21 = F_47 ( V_3 ) ;
if ( V_21 < 0 ) {
F_15 ( V_16 -> V_16 , L_11 ) ;
goto V_92;
}
F_48 ( V_16 ) ;
V_21 = F_49 ( V_3 , V_86 ) ;
if ( V_21 < 0 ) {
F_15 ( V_16 -> V_16 , L_12 ) ;
goto V_92;
}
return V_54 ;
V_92:
F_50 ( V_3 ) ;
V_91:
F_7 ( V_54 ) ;
return F_12 ( V_21 ) ;
}
void F_51 ( struct V_1 * V_54 )
{
if ( V_54 -> V_4 . V_65 ) {
struct V_57 * V_93 ;
int V_21 ;
V_93 = V_54 -> V_4 . V_65 ;
V_21 = F_52 ( V_93 ) ;
if ( V_21 < 0 )
F_34 ( L_13 ) ;
if ( V_93 -> V_71 . V_94 )
F_53 ( & V_93 -> V_71 ) ;
F_43 ( V_93 ) ;
}
if ( V_54 -> V_7 ) {
F_42 ( & V_54 -> V_7 -> V_7 ) ;
F_4 ( & V_54 -> V_7 -> V_7 ) ;
}
F_50 ( & V_54 -> V_4 ) ;
F_7 ( V_54 ) ;
}
void F_54 ( struct V_1 * V_54 )
{
if ( V_54 ) {
struct V_15 * V_16 = V_54 -> V_4 . V_16 ;
F_55 ( V_16 ) ;
F_56 ( & V_54 -> V_4 ) ;
F_57 ( V_16 ) ;
}
}
void F_58 ( struct V_1 * V_54 )
{
if ( V_54 )
F_59 ( & V_54 -> V_4 ) ;
}
