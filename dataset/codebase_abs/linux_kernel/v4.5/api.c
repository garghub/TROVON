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
F_9 ( V_8 ) ;
return V_8 ;
V_15:
F_10 ( V_5 ) ;
V_14:
F_10 ( V_8 ) ;
V_10:
return F_11 ( V_9 ) ;
}
struct V_1 * F_12 ( struct V_2 * V_3 )
{
return V_3 -> V_3 . V_16 . V_17 ;
}
struct V_18 * F_13 ( struct V_2 * V_3 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_3 ) ;
return V_7 -> V_19 -> V_3 . V_20 ;
}
int F_14 ( struct V_1 * V_8 )
{
if ( V_8 -> V_21 >= V_22 )
return - V_23 ;
F_15 ( V_8 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_8 , int V_24 )
{
if ( V_24 == 0 )
V_24 = V_8 -> V_7 -> V_25 ;
return F_17 ( V_8 , V_24 ) ;
}
void F_18 ( struct V_1 * V_8 )
{
F_19 ( V_8 ) ;
F_20 ( & V_8 -> V_26 , V_8 -> V_7 -> V_19 ) ;
}
static T_1 F_21 ( struct V_1 * V_8 , int V_24 )
{
T_2 V_27 ;
int V_28 ;
F_22 ( V_24 == 0 ) ;
for ( V_28 = 0 ; V_28 < V_29 ; V_28 ++ ) {
V_27 = V_8 -> V_26 . V_27 [ V_28 ] ;
if ( V_24 < V_27 ) {
return V_8 -> V_26 . V_30 [ V_28 ] + V_24 ;
}
V_24 -= V_27 ;
}
return 0 ;
}
int F_23 ( struct V_1 * V_8 , int V_24 ,
T_3 V_31 , void * V_32 , char * V_33 )
{
T_1 V_34 ;
V_34 = F_21 ( V_8 , V_24 ) ;
if ( ! V_34 )
return - V_35 ;
return F_24 ( V_8 -> V_7 -> V_19 , V_34 , V_31 , V_32 , V_33 ) ;
}
void F_25 ( struct V_1 * V_8 , int V_24 , void * V_32 )
{
T_1 V_34 ;
unsigned int V_36 ;
V_34 = F_21 ( V_8 , V_24 ) ;
if ( ! V_34 )
return;
V_36 = F_26 ( NULL , V_34 ) ;
if ( V_36 )
F_27 ( V_36 , V_32 ) ;
}
int F_28 ( struct V_1 * V_8 , T_4 V_37 ,
struct V_38 * V_39 )
{
int V_9 = 0 ;
bool V_40 = true ;
F_29 ( L_1 , V_41 , V_8 -> V_42 ) ;
F_30 ( & V_8 -> V_43 ) ;
if ( V_8 -> V_21 == V_22 )
goto V_44;
if ( V_39 ) {
V_8 -> V_45 = F_31 ( V_39 , V_46 ) ;
V_8 -> V_47 = F_31 ( V_39 -> V_48 , V_46 ) ;
V_40 = false ;
}
F_32 () ;
if ( ( V_9 = F_33 ( V_8 , V_40 , V_37 , 0 ) ) ) {
F_34 ( V_8 -> V_45 ) ;
F_35 () ;
goto V_44;
}
V_8 -> V_21 = V_22 ;
V_44:
F_36 ( & V_8 -> V_43 ) ;
return V_9 ;
}
int F_37 ( struct V_1 * V_8 )
{
return V_8 -> V_42 ;
}
int F_38 ( struct V_1 * V_8 )
{
return F_39 ( V_8 ) ;
}
void F_40 ( struct V_1 * V_8 )
{
V_8 -> V_49 = true ;
F_9 ( V_8 ) ;
}
int F_41 ( struct V_50 * V_50 , struct V_51 * V_51 )
{
return F_42 ( V_50 , V_51 ) ;
}
int F_43 ( struct V_50 * V_50 , struct V_51 * V_51 )
{
return F_44 ( V_50 , V_51 ) ;
}
long F_45 ( struct V_51 * V_51 , unsigned int V_52 , unsigned long V_53 )
{
return F_46 ( V_51 , V_52 , V_53 ) ;
}
int F_47 ( struct V_51 * V_51 , struct V_54 * V_55 )
{
return F_48 ( V_51 , V_55 ) ;
}
unsigned int F_49 ( struct V_51 * V_51 , struct V_56 * V_57 )
{
return F_50 ( V_51 , V_57 ) ;
}
T_5 F_51 ( struct V_51 * V_51 , char T_6 * V_58 , T_7 V_59 ,
T_8 * V_60 )
{
return F_52 ( V_51 , V_58 , V_59 , V_60 ) ;
}
struct V_51 * F_53 ( struct V_1 * V_8 , struct V_61 * V_62 ,
int * V_63 )
{
struct V_51 * V_51 ;
int V_9 , V_64 , V_65 ;
V_64 = V_66 | V_67 ;
V_9 = F_54 ( V_64 ) ;
if ( V_9 < 0 )
return F_11 ( V_9 ) ;
V_65 = V_9 ;
if ( V_62 ) {
F_55 ( V_68 ) ;
F_55 ( V_57 ) ;
F_55 ( V_69 ) ;
F_55 ( V_70 ) ;
F_55 ( V_71 ) ;
F_55 ( V_72 ) ;
F_55 ( V_73 ) ;
} else
V_62 = (struct V_61 * ) & V_74 ;
V_51 = F_56 ( L_2 , V_62 , V_8 , V_64 ) ;
if ( F_4 ( V_51 ) )
goto V_75;
V_51 -> V_76 = V_8 -> V_5 ;
* V_63 = V_65 ;
return V_51 ;
V_75:
F_57 ( V_65 ) ;
return NULL ;
}
struct V_1 * F_58 ( struct V_51 * V_51 )
{
return V_51 -> V_77 ;
}
int F_59 ( struct V_1 * V_8 ,
struct V_78 * V_79 )
{
int V_9 ;
if ( ! ( V_79 -> V_64 & V_80 ) )
V_79 -> V_81 = V_8 -> V_7 -> V_25 ;
else if ( ( V_79 -> V_81 < V_8 -> V_7 -> V_25 ) ||
( V_79 -> V_81 > V_8 -> V_7 -> V_82 ) ) {
return - V_83 ;
}
V_9 = F_60 ( V_8 , V_79 -> V_81 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_28 ( V_8 , V_79 -> V_84 , V_85 ) ;
if ( V_9 < 0 ) {
F_61 ( V_8 , V_8 ) ;
return V_9 ;
}
return 0 ;
}
void T_9 * F_62 ( struct V_1 * V_8 )
{
struct V_6 * V_7 = V_8 -> V_7 ;
int V_9 ;
V_9 = F_63 ( V_7 ) ;
if ( V_9 )
return NULL ;
F_29 ( L_3 ,
V_41 , V_7 -> V_86 , V_7 -> V_19 -> V_87 ) ;
return F_64 ( V_8 -> V_86 , V_8 -> V_88 ) ;
}
void F_65 ( void T_9 * V_89 )
{
F_66 ( V_89 ) ;
}
int F_67 ( struct V_1 * V_8 )
{
struct V_6 * V_7 = V_8 -> V_7 ;
int V_9 ;
V_9 = F_68 ( V_7 ) ;
if ( V_9 )
return V_9 ;
return F_63 ( V_7 ) ;
}
void F_69 ( struct V_6 * V_7 ,
bool V_90 )
{
V_7 -> V_19 -> V_91 = V_90 ;
}
