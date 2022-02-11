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
struct V_18 * F_12 ( struct V_2 * V_3 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_3 ) ;
return V_7 -> V_19 -> V_3 . V_20 ;
}
int F_13 ( struct V_1 * V_8 )
{
if ( V_8 -> V_21 >= V_22 )
return - V_23 ;
F_14 ( V_8 ) ;
return 0 ;
}
static T_1 F_15 ( struct V_1 * V_8 , int V_24 )
{
T_2 V_25 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ ) {
V_25 = V_8 -> V_28 . V_25 [ V_26 ] ;
if ( V_24 < V_25 ) {
return V_8 -> V_28 . V_29 [ V_26 ] + V_24 ;
}
V_24 -= V_25 ;
}
return 0 ;
}
int F_16 ( struct V_1 * V_8 , int V_24 )
{
int V_30 ;
T_1 V_31 ;
if ( V_24 == 0 )
V_24 = V_8 -> V_7 -> V_32 ;
V_30 = F_17 ( V_8 , V_24 ) ;
if ( ! V_30 && ! F_18 ( V_33 ) ) {
V_31 = F_15 ( V_8 , 0 ) ;
if ( V_31 )
F_19 ( V_8 -> V_7 -> V_19 , V_31 , V_34 -> V_35 , V_8 , L_1 ) ;
}
return V_30 ;
}
void F_20 ( struct V_1 * V_8 )
{
T_1 V_31 ;
unsigned int V_36 ;
if ( ! F_18 ( V_33 ) ) {
V_31 = F_15 ( V_8 , 0 ) ;
if ( V_31 ) {
V_36 = F_21 ( NULL , V_31 ) ;
if ( V_36 )
F_22 ( V_36 , V_8 ) ;
}
}
F_23 ( V_8 ) ;
V_34 -> V_37 ( & V_8 -> V_28 , V_8 -> V_7 -> V_19 ) ;
}
int F_24 ( struct V_1 * V_8 , int V_24 ,
T_3 V_38 , void * V_39 , char * V_40 )
{
T_1 V_31 ;
V_31 = F_15 ( V_8 , V_24 ) ;
if ( ! V_31 )
return - V_41 ;
return F_19 ( V_8 -> V_7 -> V_19 , V_31 , V_38 , V_39 , V_40 ) ;
}
void F_25 ( struct V_1 * V_8 , int V_24 , void * V_39 )
{
T_1 V_31 ;
unsigned int V_36 ;
V_31 = F_15 ( V_8 , V_24 ) ;
if ( ! V_31 )
return;
V_36 = F_21 ( NULL , V_31 ) ;
if ( V_36 )
F_22 ( V_36 , V_39 ) ;
}
int F_26 ( struct V_1 * V_8 , T_4 V_42 ,
struct V_43 * V_44 )
{
int V_9 = 0 ;
bool V_45 = true ;
F_27 ( L_2 , V_46 , V_8 -> V_47 ) ;
F_28 ( & V_8 -> V_48 ) ;
if ( V_8 -> V_21 == V_22 )
goto V_49;
if ( V_44 ) {
V_8 -> V_50 = F_29 ( V_44 , V_51 ) ;
V_8 -> V_52 = F_29 ( V_44 -> V_53 , V_51 ) ;
V_45 = false ;
}
F_30 () ;
if ( ( V_9 = V_34 -> V_54 ( V_8 , V_45 , V_42 , 0 ) ) ) {
F_31 ( V_8 -> V_50 ) ;
F_32 () ;
goto V_49;
}
V_8 -> V_21 = V_22 ;
V_49:
F_33 ( & V_8 -> V_48 ) ;
return V_9 ;
}
int F_34 ( struct V_1 * V_8 )
{
return V_8 -> V_55 ;
}
int F_35 ( struct V_1 * V_8 )
{
return F_36 ( V_8 ) ;
}
void F_37 ( struct V_1 * V_8 )
{
V_8 -> V_56 = true ;
}
int F_38 ( struct V_57 * V_57 , struct V_58 * V_58 )
{
return F_39 ( V_57 , V_58 ) ;
}
int F_40 ( struct V_57 * V_57 , struct V_58 * V_58 )
{
return F_41 ( V_57 , V_58 ) ;
}
long F_42 ( struct V_58 * V_58 , unsigned int V_59 , unsigned long V_60 )
{
return F_43 ( V_58 , V_59 , V_60 ) ;
}
int F_44 ( struct V_58 * V_58 , struct V_61 * V_62 )
{
return F_45 ( V_58 , V_62 ) ;
}
unsigned int F_46 ( struct V_58 * V_58 , struct V_63 * V_64 )
{
return F_47 ( V_58 , V_64 ) ;
}
T_5 F_48 ( struct V_58 * V_58 , char T_6 * V_65 , T_7 V_66 ,
T_8 * V_67 )
{
return F_49 ( V_58 , V_65 , V_66 , V_67 ) ;
}
struct V_58 * F_50 ( struct V_1 * V_8 , struct V_68 * V_69 ,
int * V_70 )
{
struct V_58 * V_58 ;
int V_9 , V_71 , V_72 ;
V_71 = V_73 | V_74 ;
V_9 = F_51 ( V_71 ) ;
if ( V_9 < 0 )
return F_10 ( V_9 ) ;
V_72 = V_9 ;
if ( V_69 ) {
F_52 ( V_75 ) ;
F_52 ( V_64 ) ;
F_52 ( V_76 ) ;
F_52 ( V_77 ) ;
F_52 ( V_78 ) ;
F_52 ( V_79 ) ;
F_52 ( V_80 ) ;
} else
V_69 = (struct V_68 * ) & V_81 ;
V_58 = F_53 ( L_3 , V_69 , V_8 , V_71 ) ;
if ( F_4 ( V_58 ) )
goto V_82;
V_58 -> V_83 = V_8 -> V_5 ;
* V_70 = V_72 ;
return V_58 ;
V_82:
F_54 ( V_72 ) ;
return NULL ;
}
struct V_1 * F_55 ( struct V_58 * V_58 )
{
return V_58 -> V_84 ;
}
int F_56 ( struct V_1 * V_8 ,
struct V_85 * V_86 )
{
int V_9 ;
if ( ! ( V_86 -> V_71 & V_87 ) )
V_86 -> V_88 = V_8 -> V_7 -> V_32 ;
else if ( ( V_86 -> V_88 < V_8 -> V_7 -> V_32 ) ||
( V_86 -> V_88 > V_8 -> V_7 -> V_89 ) ) {
return - V_90 ;
}
V_9 = F_57 ( V_8 , V_86 -> V_88 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_26 ( V_8 , V_86 -> V_91 , V_92 ) ;
if ( V_9 < 0 ) {
F_58 ( V_8 , V_8 ) ;
return V_9 ;
}
return 0 ;
}
void T_9 * F_59 ( struct V_1 * V_8 )
{
if ( V_8 -> V_21 != V_22 )
return NULL ;
F_27 ( L_4 ,
V_46 , V_8 -> V_93 , V_8 -> V_94 ) ;
return F_60 ( V_8 -> V_93 , V_8 -> V_94 ) ;
}
void F_61 ( void T_9 * V_95 )
{
F_62 ( V_95 ) ;
}
int F_63 ( struct V_1 * V_8 )
{
struct V_6 * V_7 = V_8 -> V_7 ;
int V_9 ;
V_9 = V_34 -> V_96 ( V_7 ) ;
if ( V_9 )
return V_9 ;
return V_34 -> V_97 ( V_7 ) ;
}
void F_64 ( struct V_6 * V_7 ,
bool V_98 )
{
V_7 -> V_19 -> V_99 = V_98 ;
}
T_5 F_65 ( struct V_2 * V_3 , void * V_65 , T_7 V_66 )
{
struct V_6 * V_7 = F_2 ( V_3 ) ;
return V_34 -> V_100 ( V_7 -> V_19 , V_65 , V_66 ) ;
}
