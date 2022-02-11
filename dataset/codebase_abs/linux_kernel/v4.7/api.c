struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_1 * V_8 ;
int V_9 ;
V_7 = F_2 ( V_3 ) ;
V_8 = F_3 () ;
if ( F_4 ( V_8 ) ) {
V_9 = F_5 ( V_8 ) ;
goto V_10;
}
V_8 -> V_11 = true ;
V_5 = F_6 ( sizeof( struct V_4 ) , V_12 ) ;
if ( ! V_5 ) {
V_9 = - V_13 ;
goto V_14;
}
F_7 ( V_5 ) ;
V_9 = F_8 ( V_8 , V_7 , false , V_5 ) ;
if ( V_9 )
goto V_15;
return V_8 ;
V_15:
F_9 ( V_5 ) ;
V_14:
F_9 ( V_8 ) ;
V_10:
return F_10 ( V_9 ) ;
}
struct V_1 * F_11 ( struct V_2 * V_3 )
{
return V_3 -> V_3 . V_16 . V_17 ;
}
int F_12 ( struct V_1 * V_8 )
{
if ( V_8 -> V_18 >= V_19 )
return - V_20 ;
F_13 ( V_8 ) ;
return 0 ;
}
static T_1 F_14 ( struct V_1 * V_8 , int V_21 )
{
T_2 V_22 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
V_22 = V_8 -> V_25 . V_22 [ V_23 ] ;
if ( V_21 < V_22 ) {
return V_8 -> V_25 . V_26 [ V_23 ] + V_21 ;
}
V_21 -= V_22 ;
}
return 0 ;
}
int F_15 ( struct V_1 * V_8 , int V_21 )
{
int V_27 ;
T_1 V_28 ;
if ( V_21 == 0 )
V_21 = V_8 -> V_7 -> V_29 ;
V_27 = F_16 ( V_8 , V_21 ) ;
if ( ! V_27 && ! F_17 ( V_30 ) ) {
V_28 = F_14 ( V_8 , 0 ) ;
if ( V_28 )
F_18 ( V_8 -> V_7 -> V_31 , V_28 , V_32 -> V_33 , V_8 , L_1 ) ;
}
return V_27 ;
}
void F_19 ( struct V_1 * V_8 )
{
T_1 V_28 ;
unsigned int V_34 ;
if ( ! F_17 ( V_30 ) ) {
V_28 = F_14 ( V_8 , 0 ) ;
if ( V_28 ) {
V_34 = F_20 ( NULL , V_28 ) ;
if ( V_34 )
F_21 ( V_34 , V_8 ) ;
}
}
F_22 ( V_8 ) ;
V_32 -> V_35 ( & V_8 -> V_25 , V_8 -> V_7 -> V_31 ) ;
}
int F_23 ( struct V_1 * V_8 , int V_21 ,
T_3 V_36 , void * V_37 , char * V_38 )
{
T_1 V_28 ;
V_28 = F_14 ( V_8 , V_21 ) ;
if ( ! V_28 )
return - V_39 ;
return F_18 ( V_8 -> V_7 -> V_31 , V_28 , V_36 , V_37 , V_38 ) ;
}
void F_24 ( struct V_1 * V_8 , int V_21 , void * V_37 )
{
T_1 V_28 ;
unsigned int V_34 ;
V_28 = F_14 ( V_8 , V_21 ) ;
if ( ! V_28 )
return;
V_34 = F_20 ( NULL , V_28 ) ;
if ( V_34 )
F_21 ( V_34 , V_37 ) ;
}
int F_25 ( struct V_1 * V_8 , T_4 V_40 ,
struct V_41 * V_42 )
{
int V_9 = 0 ;
bool V_43 = true ;
F_26 ( L_2 , V_44 , V_8 -> V_45 ) ;
F_27 ( & V_8 -> V_46 ) ;
if ( V_8 -> V_18 == V_19 )
goto V_47;
if ( V_42 ) {
V_8 -> V_48 = F_28 ( V_42 , V_49 ) ;
V_8 -> V_50 = F_28 ( V_42 -> V_51 , V_49 ) ;
V_43 = false ;
V_8 -> V_52 = false ;
}
F_29 () ;
if ( ( V_9 = V_32 -> V_53 ( V_8 , V_43 , V_40 , 0 ) ) ) {
F_30 ( V_8 -> V_48 ) ;
F_31 () ;
goto V_47;
}
V_8 -> V_18 = V_19 ;
V_47:
F_32 ( & V_8 -> V_46 ) ;
return V_9 ;
}
int F_33 ( struct V_1 * V_8 )
{
return V_8 -> V_54 ;
}
int F_34 ( struct V_1 * V_8 )
{
return F_35 ( V_8 ) ;
}
void F_36 ( struct V_1 * V_8 )
{
V_8 -> V_55 = true ;
}
int F_37 ( struct V_1 * V_8 , bool V_52 )
{
if ( V_8 -> V_18 == V_19 ) {
return - V_20 ;
}
V_8 -> V_52 = V_52 ;
return 0 ;
}
int F_38 ( struct V_56 * V_56 , struct V_57 * V_57 )
{
return F_39 ( V_56 , V_57 ) ;
}
int F_40 ( struct V_56 * V_56 , struct V_57 * V_57 )
{
return F_41 ( V_56 , V_57 ) ;
}
long F_42 ( struct V_57 * V_57 , unsigned int V_58 , unsigned long V_59 )
{
return F_43 ( V_57 , V_58 , V_59 ) ;
}
int F_44 ( struct V_57 * V_57 , struct V_60 * V_61 )
{
return F_45 ( V_57 , V_61 ) ;
}
unsigned int F_46 ( struct V_57 * V_57 , struct V_62 * V_63 )
{
return F_47 ( V_57 , V_63 ) ;
}
T_5 F_48 ( struct V_57 * V_57 , char T_6 * V_64 , T_7 V_65 ,
T_8 * V_66 )
{
return F_49 ( V_57 , V_64 , V_65 , V_66 ) ;
}
struct V_57 * F_50 ( struct V_1 * V_8 , struct V_67 * V_68 ,
int * V_69 )
{
struct V_57 * V_57 ;
int V_9 , V_70 , V_71 ;
V_70 = V_72 | V_73 ;
V_9 = F_51 ( V_70 ) ;
if ( V_9 < 0 )
return F_10 ( V_9 ) ;
V_71 = V_9 ;
if ( V_68 ) {
F_52 ( V_74 ) ;
F_52 ( V_63 ) ;
F_52 ( V_75 ) ;
F_52 ( V_76 ) ;
F_52 ( V_77 ) ;
F_52 ( V_78 ) ;
F_52 ( V_79 ) ;
} else
V_68 = (struct V_67 * ) & V_80 ;
V_57 = F_53 ( L_3 , V_68 , V_8 , V_70 ) ;
if ( F_4 ( V_57 ) )
goto V_81;
V_57 -> V_82 = V_8 -> V_5 ;
* V_69 = V_71 ;
return V_57 ;
V_81:
F_54 ( V_71 ) ;
return NULL ;
}
struct V_1 * F_55 ( struct V_57 * V_57 )
{
return V_57 -> V_83 ;
}
int F_56 ( struct V_1 * V_8 ,
struct V_84 * V_85 )
{
int V_9 ;
if ( ! ( V_85 -> V_70 & V_86 ) )
V_85 -> V_87 = V_8 -> V_7 -> V_29 ;
else if ( ( V_85 -> V_87 < V_8 -> V_7 -> V_29 ) ||
( V_85 -> V_87 > V_8 -> V_7 -> V_88 ) ) {
return - V_89 ;
}
V_9 = F_57 ( V_8 , V_85 -> V_87 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_25 ( V_8 , V_85 -> V_90 , V_91 ) ;
if ( V_9 < 0 ) {
F_58 ( V_8 , V_8 ) ;
return V_9 ;
}
return 0 ;
}
void T_9 * F_59 ( struct V_1 * V_8 )
{
if ( V_8 -> V_18 != V_19 )
return NULL ;
F_26 ( L_4 ,
V_44 , V_8 -> V_92 , V_8 -> V_93 ) ;
return F_60 ( V_8 -> V_92 , V_8 -> V_93 ) ;
}
void F_61 ( void T_9 * V_94 )
{
F_62 ( V_94 ) ;
}
int F_63 ( struct V_1 * V_8 )
{
struct V_6 * V_7 = V_8 -> V_7 ;
int V_9 ;
V_9 = V_32 -> V_95 ( V_7 ) ;
if ( V_9 )
return V_9 ;
return V_32 -> V_96 ( V_7 ) ;
}
void F_64 ( struct V_6 * V_7 ,
bool V_97 )
{
V_7 -> V_31 -> V_98 = V_97 ;
}
T_5 F_65 ( struct V_2 * V_3 , void * V_64 , T_7 V_65 )
{
struct V_6 * V_7 = F_2 ( V_3 ) ;
return V_32 -> V_99 ( V_7 -> V_31 , V_64 , V_65 ) ;
}
