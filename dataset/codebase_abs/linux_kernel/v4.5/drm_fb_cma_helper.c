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
const const struct V_17 * V_18 , struct V_19 * * V_10 ,
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
struct V_12 * V_13 , const struct V_17 * V_18 )
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
F_30 ( & V_16 -> V_49 . V_50 ) ;
F_31 (fb, dev)
F_26 ( V_7 , V_42 ) ;
F_32 ( & V_16 -> V_49 . V_50 ) ;
return 0 ;
}
static int F_33 ( struct V_2 * V_3 ,
struct V_51 * V_52 )
{
struct V_1 * V_53 = F_1 ( V_3 ) ;
struct V_17 V_18 = { 0 } ;
struct V_15 * V_16 = V_3 -> V_16 ;
struct V_19 * V_10 ;
struct V_6 * V_7 ;
unsigned int V_54 ;
unsigned long V_55 ;
struct V_56 * V_57 ;
T_1 V_38 ;
int V_21 ;
F_34 ( L_5 ,
V_52 -> V_58 , V_52 -> V_59 ,
V_52 -> V_60 ) ;
V_54 = F_35 ( V_52 -> V_60 , 8 ) ;
V_18 . V_30 = V_52 -> V_58 ;
V_18 . V_31 = V_52 -> V_59 ;
V_18 . V_36 [ 0 ] = V_52 -> V_58 * V_54 ;
V_18 . V_29 = F_36 ( V_52 -> V_60 ,
V_52 -> V_61 ) ;
V_38 = V_18 . V_36 [ 0 ] * V_18 . V_31 ;
V_10 = F_37 ( V_16 , V_38 ) ;
if ( F_23 ( V_10 ) )
return - V_23 ;
V_57 = F_38 ( V_3 ) ;
if ( F_23 ( V_57 ) ) {
V_21 = F_24 ( V_57 ) ;
goto V_62;
}
V_53 -> V_7 = F_10 ( V_16 , & V_18 , & V_10 , 1 ) ;
if ( F_23 ( V_53 -> V_7 ) ) {
F_15 ( V_16 -> V_16 , L_6 ) ;
V_21 = F_24 ( V_53 -> V_7 ) ;
goto V_63;
}
V_7 = & V_53 -> V_7 -> V_7 ;
V_3 -> V_7 = V_7 ;
V_57 -> V_64 = V_3 ;
V_57 -> V_65 = V_66 ;
V_57 -> V_67 = & V_68 ;
F_39 ( V_57 , V_7 -> V_36 [ 0 ] , V_7 -> V_69 ) ;
F_40 ( V_57 , V_3 , V_52 -> V_70 , V_52 -> V_71 ) ;
V_55 = V_57 -> V_72 . V_73 * V_54 ;
V_55 += V_57 -> V_72 . V_74 * V_7 -> V_36 [ 0 ] ;
V_16 -> V_49 . V_75 = ( V_76 ) V_10 -> V_77 ;
V_57 -> V_78 = V_10 -> V_79 + V_55 ;
V_57 -> V_80 . V_81 = ( unsigned long ) ( V_10 -> V_77 + V_55 ) ;
V_57 -> V_82 = V_38 ;
V_57 -> V_80 . V_83 = V_38 ;
return 0 ;
V_63:
F_41 ( V_3 ) ;
V_62:
V_16 -> V_84 -> V_85 ( & V_10 -> V_11 ) ;
return V_21 ;
}
struct V_1 * F_42 ( struct V_15 * V_16 ,
unsigned int V_86 , unsigned int V_87 ,
unsigned int V_88 )
{
struct V_1 * V_53 ;
struct V_2 * V_3 ;
int V_21 ;
V_53 = F_11 ( sizeof( * V_53 ) , V_22 ) ;
if ( ! V_53 ) {
F_15 ( V_16 -> V_16 , L_7 ) ;
return F_12 ( - V_23 ) ;
}
V_3 = & V_53 -> V_4 ;
F_43 ( V_16 , V_3 , & V_89 ) ;
V_21 = F_44 ( V_16 , V_3 , V_87 , V_88 ) ;
if ( V_21 < 0 ) {
F_15 ( V_16 -> V_16 , L_8 ) ;
goto V_90;
}
V_21 = F_45 ( V_3 ) ;
if ( V_21 < 0 ) {
F_15 ( V_16 -> V_16 , L_9 ) ;
goto V_91;
}
V_21 = F_46 ( V_3 , V_86 ) ;
if ( V_21 < 0 ) {
F_15 ( V_16 -> V_16 , L_10 ) ;
goto V_91;
}
return V_53 ;
V_91:
F_47 ( V_3 ) ;
V_90:
F_7 ( V_53 ) ;
return F_12 ( V_21 ) ;
}
void F_48 ( struct V_1 * V_53 )
{
F_49 ( & V_53 -> V_4 ) ;
F_41 ( & V_53 -> V_4 ) ;
if ( V_53 -> V_7 ) {
F_50 ( & V_53 -> V_7 -> V_7 ) ;
F_4 ( & V_53 -> V_7 -> V_7 ) ;
}
F_47 ( & V_53 -> V_4 ) ;
F_7 ( V_53 ) ;
}
void F_51 ( struct V_1 * V_53 )
{
if ( V_53 )
F_52 ( & V_53 -> V_4 ) ;
}
void F_53 ( struct V_1 * V_53 )
{
if ( V_53 )
F_54 ( & V_53 -> V_4 ) ;
}
