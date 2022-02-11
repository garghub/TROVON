struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_1 * V_8 ;
int V_9 ;
V_7 = F_2 ( V_3 ) ;
F_3 ( & V_7 -> V_3 ) ;
V_8 = F_4 () ;
if ( F_5 ( V_8 ) ) {
V_9 = F_6 ( V_8 ) ;
goto V_10;
}
V_8 -> V_11 = true ;
V_5 = F_7 ( sizeof( struct V_4 ) , V_12 ) ;
if ( ! V_5 ) {
V_9 = - V_13 ;
goto V_14;
}
F_8 ( V_5 ) ;
V_9 = F_9 ( V_8 , V_7 , false , V_5 ) ;
if ( V_9 )
goto V_15;
F_10 ( V_8 ) ;
return V_8 ;
V_15:
F_11 ( V_5 ) ;
V_14:
F_11 ( V_8 ) ;
V_10:
F_12 ( & V_7 -> V_3 ) ;
return F_13 ( V_9 ) ;
}
struct V_1 * F_14 ( struct V_2 * V_3 )
{
return V_3 -> V_3 . V_16 . V_17 ;
}
struct V_18 * F_15 ( struct V_2 * V_3 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_3 ) ;
return V_7 -> V_19 -> V_3 . V_20 ;
}
int F_16 ( struct V_1 * V_8 )
{
if ( V_8 -> V_21 >= V_22 )
return - V_23 ;
F_12 ( & V_8 -> V_7 -> V_3 ) ;
F_17 ( V_8 ) ;
return 0 ;
}
int F_18 ( struct V_1 * V_8 , int V_24 )
{
if ( V_24 == 0 )
V_24 = V_8 -> V_7 -> V_25 ;
return F_19 ( V_8 , V_24 ) ;
}
void F_20 ( struct V_1 * V_8 )
{
F_21 ( V_8 ) ;
F_22 ( & V_8 -> V_26 , V_8 -> V_7 -> V_19 ) ;
}
static T_1 F_23 ( struct V_1 * V_8 , int V_24 )
{
T_2 V_27 ;
int V_28 ;
F_24 ( V_24 == 0 ) ;
for ( V_28 = 0 ; V_28 < V_29 ; V_28 ++ ) {
V_27 = V_8 -> V_26 . V_27 [ V_28 ] ;
if ( V_24 < V_27 ) {
return V_8 -> V_26 . V_30 [ V_28 ] + V_24 ;
}
V_24 -= V_27 ;
}
return 0 ;
}
int F_25 ( struct V_1 * V_8 , int V_24 ,
T_3 V_31 , void * V_32 , char * V_33 )
{
T_1 V_34 ;
V_34 = F_23 ( V_8 , V_24 ) ;
if ( ! V_34 )
return - V_35 ;
return F_26 ( V_8 -> V_7 -> V_19 , V_34 , V_31 , V_32 , V_33 ) ;
}
void F_27 ( struct V_1 * V_8 , int V_24 , void * V_32 )
{
T_1 V_34 ;
unsigned int V_36 ;
V_34 = F_23 ( V_8 , V_24 ) ;
if ( ! V_34 )
return;
V_36 = F_28 ( NULL , V_34 ) ;
if ( V_36 )
F_29 ( V_36 , V_32 ) ;
}
int F_30 ( struct V_1 * V_8 , T_4 V_37 ,
struct V_38 * V_39 )
{
int V_9 = 0 ;
bool V_40 = true ;
F_31 ( L_1 , V_41 , V_8 -> V_42 ) ;
F_32 ( & V_8 -> V_43 ) ;
if ( V_8 -> V_21 == V_22 )
goto V_44;
if ( V_39 ) {
V_8 -> V_45 = F_33 ( V_39 , V_46 ) ;
F_34 ( V_8 -> V_45 ) ;
V_40 = false ;
}
F_35 () ;
if ( ( V_9 = F_36 ( V_8 , V_40 , V_37 , 0 ) ) ) {
F_37 ( V_8 -> V_45 ) ;
F_38 () ;
goto V_44;
}
V_8 -> V_21 = V_22 ;
V_44:
F_39 ( & V_8 -> V_43 ) ;
return V_9 ;
}
int F_40 ( struct V_1 * V_8 )
{
return V_8 -> V_42 ;
}
int F_41 ( struct V_1 * V_8 )
{
return F_42 ( V_8 ) ;
}
void F_43 ( struct V_1 * V_8 )
{
V_8 -> V_47 = true ;
F_10 ( V_8 ) ;
}
int F_44 ( struct V_48 * V_48 , struct V_49 * V_49 )
{
return F_45 ( V_48 , V_49 ) ;
}
int F_46 ( struct V_48 * V_48 , struct V_49 * V_49 )
{
return F_47 ( V_48 , V_49 ) ;
}
long F_48 ( struct V_49 * V_49 , unsigned int V_50 , unsigned long V_51 )
{
return F_49 ( V_49 , V_50 , V_51 ) ;
}
int F_50 ( struct V_49 * V_49 , struct V_52 * V_53 )
{
return F_51 ( V_49 , V_53 ) ;
}
unsigned int F_52 ( struct V_49 * V_49 , struct V_54 * V_55 )
{
return F_53 ( V_49 , V_55 ) ;
}
T_5 F_54 ( struct V_49 * V_49 , char T_6 * V_56 , T_7 V_57 ,
T_8 * V_58 )
{
return F_55 ( V_49 , V_56 , V_57 , V_58 ) ;
}
struct V_49 * F_56 ( struct V_1 * V_8 , struct V_59 * V_60 ,
int * V_61 )
{
struct V_49 * V_49 ;
int V_9 , V_62 , V_63 ;
V_62 = V_64 | V_65 ;
V_9 = F_57 ( V_62 ) ;
if ( V_9 < 0 )
return F_13 ( V_9 ) ;
V_63 = V_9 ;
if ( V_60 ) {
F_58 ( V_66 ) ;
F_58 ( V_55 ) ;
F_58 ( V_67 ) ;
F_58 ( V_68 ) ;
F_58 ( V_69 ) ;
F_58 ( V_70 ) ;
F_58 ( V_71 ) ;
} else
V_60 = (struct V_59 * ) & V_72 ;
V_49 = F_59 ( L_2 , V_60 , V_8 , V_62 ) ;
if ( F_5 ( V_49 ) )
goto V_73;
V_49 -> V_74 = V_8 -> V_5 ;
* V_61 = V_63 ;
return V_49 ;
V_73:
F_60 ( V_63 ) ;
return NULL ;
}
struct V_1 * F_61 ( struct V_49 * V_49 )
{
return V_49 -> V_75 ;
}
int F_62 ( struct V_1 * V_8 ,
struct V_76 * V_77 )
{
int V_9 ;
if ( ! ( V_77 -> V_62 & V_78 ) )
V_77 -> V_79 = V_8 -> V_7 -> V_25 ;
else if ( ( V_77 -> V_79 < V_8 -> V_7 -> V_25 ) ||
( V_77 -> V_79 > V_8 -> V_7 -> V_80 ) ) {
return - V_81 ;
}
V_9 = F_63 ( V_8 , V_77 -> V_79 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_30 ( V_8 , V_77 -> V_82 , V_83 ) ;
if ( V_9 < 0 ) {
F_64 ( V_8 , V_8 ) ;
return V_9 ;
}
return 0 ;
}
void T_9 * F_65 ( struct V_1 * V_8 )
{
struct V_6 * V_7 = V_8 -> V_7 ;
int V_9 ;
V_9 = F_66 ( V_7 ) ;
if ( V_9 )
return NULL ;
F_31 ( L_3 ,
V_41 , V_7 -> V_84 , V_7 -> V_19 -> V_85 ) ;
return F_67 ( V_8 -> V_84 , V_8 -> V_86 ) ;
}
void F_68 ( void T_9 * V_87 )
{
F_69 ( V_87 ) ;
}
int F_70 ( struct V_1 * V_8 )
{
struct V_6 * V_7 = V_8 -> V_7 ;
int V_9 ;
V_9 = F_71 ( V_7 ) ;
if ( V_9 )
return V_9 ;
return F_66 ( V_7 ) ;
}
void F_72 ( struct V_6 * V_7 ,
bool V_88 )
{
V_7 -> V_19 -> V_89 = V_88 ;
}
