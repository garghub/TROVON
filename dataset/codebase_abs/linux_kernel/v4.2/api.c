struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_1 * V_6 ;
int V_7 ;
V_5 = F_2 ( V_3 ) ;
F_3 ( & V_5 -> V_3 ) ;
V_6 = F_4 () ;
if ( F_5 ( V_6 ) )
return V_6 ;
V_7 = F_6 ( V_6 , V_5 , false , NULL ) ;
if ( V_7 ) {
F_7 ( V_6 ) ;
F_8 ( & V_5 -> V_3 ) ;
return F_9 ( - V_8 ) ;
}
F_10 ( V_6 ) ;
return V_6 ;
}
struct V_1 * F_11 ( struct V_2 * V_3 )
{
return V_3 -> V_3 . V_9 . V_10 ;
}
struct V_11 * F_12 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( V_3 ) ;
return V_5 -> V_12 -> V_3 . V_13 ;
}
int F_13 ( struct V_1 * V_6 )
{
if ( V_6 -> V_14 != V_15 )
return - V_16 ;
F_8 ( & V_6 -> V_5 -> V_3 ) ;
F_14 ( V_6 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_6 , int V_17 )
{
if ( V_17 == 0 )
V_17 = V_6 -> V_5 -> V_18 ;
return F_16 ( V_6 , V_17 ) ;
}
void F_17 ( struct V_1 * V_6 )
{
F_18 ( & V_6 -> V_19 , V_6 -> V_5 -> V_12 ) ;
}
static T_1 F_19 ( struct V_1 * V_6 , int V_17 )
{
T_2 V_20 ;
int V_21 ;
F_20 ( V_17 == 0 ) ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
V_20 = V_6 -> V_19 . V_20 [ V_21 ] ;
if ( V_17 < V_20 ) {
return V_6 -> V_19 . V_23 [ V_21 ] + V_17 ;
}
V_17 -= V_20 ;
}
return 0 ;
}
int F_21 ( struct V_1 * V_6 , int V_17 ,
T_3 V_24 , void * V_25 , char * V_26 )
{
T_1 V_27 ;
V_27 = F_19 ( V_6 , V_17 ) ;
if ( ! V_27 )
return - V_28 ;
return F_22 ( V_6 -> V_5 -> V_12 , V_27 , V_24 , V_25 , V_26 ) ;
}
void F_23 ( struct V_1 * V_6 , int V_17 , void * V_25 )
{
T_1 V_27 ;
unsigned int V_29 ;
V_27 = F_19 ( V_6 , V_17 ) ;
if ( ! V_27 )
return;
V_29 = F_24 ( NULL , V_27 ) ;
if ( V_29 )
F_25 ( V_29 , V_25 ) ;
}
int F_26 ( struct V_1 * V_6 , T_4 V_30 ,
struct V_31 * V_32 )
{
int V_7 = 0 ;
bool V_33 = true ;
F_27 ( L_1 , V_34 , V_6 -> V_35 ) ;
F_28 ( & V_6 -> V_36 ) ;
if ( V_6 -> V_14 == V_37 )
goto V_38;
if ( V_32 ) {
V_6 -> V_39 = F_29 ( V_32 , V_40 ) ;
F_30 ( V_6 -> V_39 ) ;
V_33 = false ;
}
F_31 () ;
if ( ( V_7 = F_32 ( V_6 , V_33 , V_30 , 0 ) ) ) {
F_33 ( V_6 -> V_39 ) ;
F_34 () ;
goto V_38;
}
V_6 -> V_14 = V_37 ;
V_38:
F_35 ( & V_6 -> V_36 ) ;
return V_7 ;
}
int F_36 ( struct V_1 * V_6 )
{
return V_6 -> V_35 ;
}
int F_37 ( struct V_1 * V_6 )
{
return F_38 ( V_6 ) ;
}
void F_39 ( struct V_1 * V_6 )
{
V_6 -> V_41 = true ;
F_10 ( V_6 ) ;
}
int F_40 ( struct V_42 * V_42 , struct V_43 * V_43 )
{
return F_41 ( V_42 , V_43 ) ;
}
int F_42 ( struct V_42 * V_42 , struct V_43 * V_43 )
{
return F_43 ( V_42 , V_43 ) ;
}
long F_44 ( struct V_43 * V_43 , unsigned int V_44 , unsigned long V_45 )
{
return F_45 ( V_43 , V_44 , V_45 ) ;
}
int F_46 ( struct V_43 * V_43 , struct V_46 * V_47 )
{
return F_47 ( V_43 , V_47 ) ;
}
unsigned int F_48 ( struct V_43 * V_43 , struct V_48 * V_49 )
{
return F_49 ( V_43 , V_49 ) ;
}
T_5 F_50 ( struct V_43 * V_43 , char T_6 * V_50 , T_7 V_51 ,
T_8 * V_52 )
{
return F_51 ( V_43 , V_50 , V_51 , V_52 ) ;
}
struct V_43 * F_52 ( struct V_1 * V_6 , struct V_53 * V_54 ,
int * V_55 )
{
struct V_43 * V_43 ;
int V_7 , V_56 , V_57 ;
V_56 = V_58 | V_59 ;
V_7 = F_53 ( V_56 ) ;
if ( V_7 < 0 )
return F_9 ( V_7 ) ;
V_57 = V_7 ;
if ( V_54 ) {
F_54 ( V_60 ) ;
F_54 ( V_49 ) ;
F_54 ( V_61 ) ;
F_54 ( V_62 ) ;
F_54 ( V_63 ) ;
F_54 ( V_64 ) ;
F_54 ( V_65 ) ;
} else
V_54 = (struct V_53 * ) & V_66 ;
V_43 = F_55 ( L_2 , V_54 , V_6 , V_56 ) ;
if ( F_5 ( V_43 ) )
F_56 ( V_57 ) ;
* V_55 = V_57 ;
return V_43 ;
}
struct V_1 * F_57 ( struct V_43 * V_43 )
{
return V_43 -> V_67 ;
}
int F_58 ( struct V_1 * V_6 ,
struct V_68 * V_69 )
{
int V_7 ;
if ( ! ( V_69 -> V_56 & V_70 ) )
V_69 -> V_71 = V_6 -> V_5 -> V_18 ;
else if ( ( V_69 -> V_71 < V_6 -> V_5 -> V_18 ) ||
( V_69 -> V_71 > V_6 -> V_5 -> V_72 ) ) {
return - V_73 ;
}
V_7 = F_59 ( V_6 , V_69 -> V_71 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_26 ( V_6 , V_69 -> V_74 , V_75 ) ;
if ( V_7 < 0 ) {
F_60 ( V_6 , V_6 ) ;
return V_7 ;
}
return 0 ;
}
void T_9 * F_61 ( struct V_1 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_5 ;
int V_7 ;
V_7 = F_62 ( V_5 ) ;
if ( V_7 )
return NULL ;
F_27 ( L_3 ,
V_34 , V_5 -> V_76 , V_5 -> V_12 -> V_77 ) ;
return F_63 ( V_6 -> V_76 , V_6 -> V_78 ) ;
}
void F_64 ( void T_9 * V_79 )
{
F_65 ( V_79 ) ;
}
int F_66 ( struct V_1 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_5 ;
int V_7 ;
V_7 = F_67 ( V_5 ) ;
if ( V_7 )
return V_7 ;
return F_62 ( V_5 ) ;
}
