static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
V_6 = (struct V_5 * ) V_4 -> V_7 . V_8 -> V_9 ;
F_3 ( V_6 , V_4 , false ) ;
F_4 ( & V_6 -> V_10 . V_11 ) ;
F_5 ( & V_4 -> V_12 ) ;
F_6 ( & V_6 -> V_10 . V_11 ) ;
F_7 ( & V_4 -> V_7 ) ;
F_8 ( V_4 ) ;
}
bool F_9 ( struct V_1 * V_4 )
{
if ( V_4 -> V_13 == & F_1 )
return true ;
return false ;
}
void F_10 ( struct V_3 * V_14 , T_1 V_15 , bool V_16 )
{
T_1 V_17 = 0 ;
T_1 V_18 = V_16 ? V_19 : 0 ;
unsigned V_20 ;
V_14 -> V_21 . V_21 = V_14 -> V_22 ;
V_14 -> V_21 . V_23 = V_14 -> V_22 ;
if ( V_15 == V_24 )
V_14 -> V_22 [ V_17 ++ ] . V_25 = V_26 | V_27 | V_18 ;
if ( V_15 == V_28 )
V_14 -> V_22 [ V_17 ++ ] . V_25 = V_26 | V_29 | V_18 ;
if ( V_15 == V_30 )
V_14 -> V_22 [ V_17 ++ ] . V_25 = V_31 | V_32 | V_18 ;
if ( ! V_17 )
V_14 -> V_22 [ V_17 ++ ] . V_25 = V_31 | V_32 ;
V_14 -> V_21 . V_33 = V_17 ;
V_14 -> V_21 . V_34 = V_17 ;
for ( V_20 = 0 ; V_20 < V_17 ; ++ V_20 ) {
V_14 -> V_22 [ V_20 ] . V_35 = 0 ;
V_14 -> V_22 [ V_20 ] . V_36 = 0 ;
}
}
int F_11 ( struct V_5 * V_6 ,
unsigned long V_37 , bool V_38 , bool V_16 , T_1 V_15 ,
struct V_39 * V_40 ,
struct V_3 * * V_41 )
{
struct V_3 * V_4 ;
enum V_42 type ;
int V_43 ;
if ( V_38 )
type = V_44 ;
else
type = V_45 ;
* V_41 = NULL ;
V_4 = F_12 ( sizeof( struct V_3 ) , V_46 ) ;
if ( V_4 == NULL )
return - V_47 ;
V_37 = F_13 ( V_37 , V_48 ) ;
V_43 = F_14 ( V_6 -> V_49 , & V_4 -> V_7 , V_37 ) ;
if ( F_15 ( V_43 ) ) {
F_8 ( V_4 ) ;
return V_43 ;
}
V_4 -> type = V_15 ;
V_4 -> V_50 = V_16 ? 1 : 0 ;
V_4 -> V_51 = 0 ;
F_16 ( & V_4 -> V_12 ) ;
if ( V_40 )
V_4 -> V_40 = * V_40 ;
F_10 ( V_4 , V_15 , V_16 ) ;
V_43 = F_17 ( & V_6 -> V_52 . V_53 , & V_4 -> V_2 , V_37 , type ,
& V_4 -> V_21 , 0 , ! V_38 , NULL , V_37 ,
NULL , NULL , & F_1 ) ;
if ( F_15 ( V_43 != 0 ) ) {
if ( V_43 != - V_54 )
F_18 ( V_6 -> V_8 ,
L_1 ,
V_37 , V_15 ) ;
return V_43 ;
}
* V_41 = V_4 ;
return 0 ;
}
int F_19 ( struct V_3 * V_4 , void * * V_55 )
{
bool V_56 ;
int V_43 ;
if ( V_4 -> V_57 ) {
if ( V_55 )
* V_55 = V_4 -> V_57 ;
return 0 ;
}
V_43 = F_20 ( & V_4 -> V_2 , 0 , V_4 -> V_2 . V_58 , & V_4 -> V_59 ) ;
if ( V_43 )
return V_43 ;
V_4 -> V_57 = F_21 ( & V_4 -> V_59 , & V_56 ) ;
if ( V_55 )
* V_55 = V_4 -> V_57 ;
return 0 ;
}
void * F_22 ( struct V_5 * V_6 ,
struct V_3 * V_4 , int V_60 )
{
struct V_61 * V_62 = & V_4 -> V_2 . V_53 -> V_62 [ V_4 -> V_2 . V_63 . V_64 ] ;
void * V_65 ;
int V_66 ;
struct V_67 * V_68 ;
if ( V_4 -> V_2 . V_63 . V_64 == V_69 )
V_68 = V_6 -> V_70 ;
else if ( V_4 -> V_2 . V_63 . V_64 == V_71 )
V_68 = V_6 -> V_72 ;
else
goto V_73;
( void ) F_23 ( V_62 , false ) ;
V_66 = F_24 ( V_4 -> V_2 . V_53 , & V_4 -> V_2 . V_63 ) ;
F_25 ( V_62 ) ;
return F_26 ( V_68 , V_4 -> V_2 . V_63 . V_74 . V_75 + V_60 ) ;
V_73:
if ( V_4 -> V_57 ) {
V_65 = V_4 -> V_57 + ( V_60 * V_48 ) ;
return V_65 ;
}
V_66 = F_19 ( V_4 , & V_65 ) ;
if ( V_66 )
return NULL ;
V_65 += V_60 * V_48 ;
return V_65 ;
}
void F_27 ( struct V_3 * V_4 )
{
if ( V_4 -> V_57 == NULL )
return;
V_4 -> V_57 = NULL ;
F_28 ( & V_4 -> V_59 ) ;
}
void F_29 ( struct V_5 * V_6 ,
struct V_3 * V_4 , void * V_76 )
{
struct V_61 * V_62 = & V_4 -> V_2 . V_53 -> V_62 [ V_4 -> V_2 . V_63 . V_64 ] ;
struct V_67 * V_68 ;
if ( V_4 -> V_2 . V_63 . V_64 == V_69 )
V_68 = V_6 -> V_70 ;
else if ( V_4 -> V_2 . V_63 . V_64 == V_71 )
V_68 = V_6 -> V_72 ;
else
goto V_73;
F_30 ( V_76 ) ;
( void ) F_23 ( V_62 , false ) ;
F_31 ( V_4 -> V_2 . V_53 , & V_4 -> V_2 . V_63 ) ;
F_25 ( V_62 ) ;
return ;
V_73:
F_27 ( V_4 ) ;
}
void F_32 ( struct V_3 * * V_4 )
{
if ( ( * V_4 ) == NULL )
return;
F_33 ( & ( * V_4 ) -> V_7 ) ;
* V_4 = NULL ;
}
struct V_3 * F_34 ( struct V_3 * V_4 )
{
F_35 ( & V_4 -> V_7 ) ;
return V_4 ;
}
int F_36 ( struct V_3 * V_4 , T_1 V_15 , T_2 * V_77 )
{
struct V_5 * V_6 = (struct V_5 * ) V_4 -> V_7 . V_8 -> V_9 ;
int V_43 ;
if ( V_4 -> V_50 ) {
V_4 -> V_50 ++ ;
if ( V_77 )
* V_77 = F_37 ( V_4 ) ;
return 0 ;
}
F_10 ( V_4 , V_15 , true ) ;
V_43 = F_38 ( & V_4 -> V_2 , & V_4 -> V_21 , false , false ) ;
if ( F_39 ( V_43 == 0 ) ) {
V_4 -> V_50 = 1 ;
if ( V_77 != NULL )
* V_77 = F_37 ( V_4 ) ;
}
if ( F_15 ( V_43 != 0 ) )
F_18 ( V_6 -> V_8 , L_2 , V_4 ) ;
return V_43 ;
}
int F_40 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_4 -> V_7 . V_8 -> V_9 ;
int V_43 , V_20 ;
if ( ! V_4 -> V_50 ) {
F_41 ( V_6 -> V_8 , L_3 , V_4 ) ;
return 0 ;
}
V_4 -> V_50 -- ;
if ( V_4 -> V_50 )
return 0 ;
for ( V_20 = 0 ; V_20 < V_4 -> V_21 . V_33 ; V_20 ++ )
V_4 -> V_22 [ V_20 ] . V_25 &= ~ V_19 ;
V_43 = F_38 ( & V_4 -> V_2 , & V_4 -> V_21 , false , false ) ;
if ( F_15 ( V_43 != 0 ) )
F_18 ( V_6 -> V_8 , L_4 , V_4 ) ;
return V_43 ;
}
void F_42 ( struct V_5 * V_6 )
{
struct V_3 * V_4 , * V_78 ;
if ( F_43 ( & V_6 -> V_10 . V_79 ) )
return;
F_18 ( V_6 -> V_8 , L_5 ) ;
F_44 (bo, n, &qdev->gem.objects, list) {
F_18 ( V_6 -> V_8 , L_6 ,
& V_4 -> V_7 , V_4 , ( unsigned long ) V_4 -> V_7 . V_37 ,
* ( ( unsigned long * ) & V_4 -> V_7 . V_80 ) ) ;
F_4 ( & V_6 -> V_10 . V_11 ) ;
F_5 ( & V_4 -> V_12 ) ;
F_6 ( & V_6 -> V_10 . V_11 ) ;
F_33 ( & V_4 -> V_7 ) ;
}
}
int F_45 ( struct V_5 * V_6 )
{
return F_46 ( V_6 ) ;
}
void F_47 ( struct V_5 * V_6 )
{
F_48 ( V_6 ) ;
}
int F_49 ( struct V_5 * V_6 , struct V_3 * V_4 )
{
int V_66 ;
if ( V_4 -> type == V_28 && V_4 -> V_51 == 0 ) {
V_66 = F_50 ( V_6 , V_4 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_51 ( V_6 , V_4 , NULL ) ;
if ( V_66 )
return V_66 ;
}
return 0 ;
}
int F_52 ( struct V_5 * V_6 )
{
return F_53 ( & V_6 -> V_52 . V_53 , V_71 ) ;
}
int F_54 ( struct V_5 * V_6 )
{
return F_53 ( & V_6 -> V_52 . V_53 , V_69 ) ;
}
