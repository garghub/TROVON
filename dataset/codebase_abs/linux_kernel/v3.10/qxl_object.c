static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
V_6 = (struct V_5 * ) V_4 -> V_7 . V_8 -> V_9 ;
F_3 ( V_6 , V_4 , false ) ;
F_4 ( & V_4 -> V_10 ) ;
F_5 ( & V_6 -> V_11 . V_12 ) ;
F_6 ( & V_4 -> V_13 ) ;
F_7 ( & V_6 -> V_11 . V_12 ) ;
F_8 ( & V_4 -> V_7 ) ;
F_9 ( V_4 ) ;
}
bool F_10 ( struct V_1 * V_4 )
{
if ( V_4 -> V_14 == & F_1 )
return true ;
return false ;
}
void F_11 ( struct V_3 * V_15 , T_1 V_16 )
{
T_1 V_17 = 0 ;
V_15 -> V_18 . V_19 = 0 ;
V_15 -> V_18 . V_20 = 0 ;
V_15 -> V_18 . V_18 = V_15 -> V_21 ;
V_15 -> V_18 . V_22 = V_15 -> V_21 ;
if ( V_16 == V_23 )
V_15 -> V_21 [ V_17 ++ ] = V_24 | V_25 ;
if ( V_16 == V_26 )
V_15 -> V_21 [ V_17 ++ ] = V_24 | V_27 ;
if ( V_16 == V_28 )
V_15 -> V_21 [ V_17 ++ ] = V_29 | V_30 ;
if ( ! V_17 )
V_15 -> V_21 [ V_17 ++ ] = V_29 | V_30 ;
V_15 -> V_18 . V_31 = V_17 ;
V_15 -> V_18 . V_32 = V_17 ;
}
int F_12 ( struct V_5 * V_6 ,
unsigned long V_33 , bool V_34 , T_1 V_16 ,
struct V_35 * V_36 ,
struct V_3 * * V_37 )
{
struct V_3 * V_4 ;
enum V_38 type ;
int V_39 ;
if ( F_13 ( V_6 -> V_40 . V_41 . V_42 == NULL ) )
V_6 -> V_40 . V_41 . V_42 = V_6 -> V_43 -> V_42 ;
if ( V_34 )
type = V_44 ;
else
type = V_45 ;
* V_37 = NULL ;
V_4 = F_14 ( sizeof( struct V_3 ) , V_46 ) ;
if ( V_4 == NULL )
return - V_47 ;
V_33 = F_15 ( V_33 , V_48 ) ;
V_39 = F_16 ( V_6 -> V_43 , & V_4 -> V_7 , V_33 ) ;
if ( F_13 ( V_39 ) ) {
F_9 ( V_4 ) ;
return V_39 ;
}
V_4 -> V_7 . V_49 = NULL ;
V_4 -> type = V_16 ;
V_4 -> V_50 = 0 ;
V_4 -> V_51 = 0 ;
F_17 ( V_6 , & V_4 -> V_10 ) ;
F_18 ( & V_4 -> V_13 ) ;
F_19 ( & V_4 -> V_52 , 0 ) ;
if ( V_36 )
V_4 -> V_36 = * V_36 ;
F_11 ( V_4 , V_16 ) ;
V_39 = F_20 ( & V_6 -> V_40 . V_41 , & V_4 -> V_2 , V_33 , type ,
& V_4 -> V_18 , 0 , ! V_34 , NULL , V_33 ,
NULL , & F_1 ) ;
if ( F_13 ( V_39 != 0 ) ) {
if ( V_39 != - V_53 )
F_21 ( V_6 -> V_8 ,
L_1 ,
V_33 , V_16 ) ;
return V_39 ;
}
* V_37 = V_4 ;
return 0 ;
}
int F_22 ( struct V_3 * V_4 , void * * V_54 )
{
bool V_55 ;
int V_39 ;
if ( V_4 -> V_56 ) {
if ( V_54 )
* V_54 = V_4 -> V_56 ;
return 0 ;
}
V_39 = F_23 ( & V_4 -> V_2 , 0 , V_4 -> V_2 . V_57 , & V_4 -> V_58 ) ;
if ( V_39 )
return V_39 ;
V_4 -> V_56 = F_24 ( & V_4 -> V_58 , & V_55 ) ;
if ( V_54 )
* V_54 = V_4 -> V_56 ;
return 0 ;
}
void * F_25 ( struct V_5 * V_6 ,
struct V_3 * V_4 , int V_59 )
{
struct V_60 * V_61 = & V_4 -> V_2 . V_41 -> V_61 [ V_4 -> V_2 . V_62 . V_63 ] ;
void * V_64 ;
int V_65 ;
struct V_66 * V_67 ;
if ( V_4 -> V_2 . V_62 . V_63 == V_68 )
V_67 = V_6 -> V_69 ;
else if ( V_4 -> V_2 . V_62 . V_63 == V_70 )
V_67 = V_6 -> V_71 ;
else
goto V_72;
( void ) F_26 ( V_61 , false ) ;
V_65 = F_27 ( V_4 -> V_2 . V_41 , & V_4 -> V_2 . V_62 ) ;
F_28 ( V_61 ) ;
return F_29 ( V_67 , V_4 -> V_2 . V_62 . V_73 . V_74 + V_59 ) ;
V_72:
if ( V_4 -> V_56 ) {
V_64 = V_4 -> V_56 + ( V_59 * V_48 ) ;
return V_64 ;
}
V_65 = F_22 ( V_4 , & V_64 ) ;
if ( V_65 )
return NULL ;
V_64 += V_59 * V_48 ;
return V_64 ;
}
void F_30 ( struct V_3 * V_4 )
{
if ( V_4 -> V_56 == NULL )
return;
V_4 -> V_56 = NULL ;
F_31 ( & V_4 -> V_58 ) ;
}
void F_32 ( struct V_5 * V_6 ,
struct V_3 * V_4 , void * V_75 )
{
struct V_60 * V_61 = & V_4 -> V_2 . V_41 -> V_61 [ V_4 -> V_2 . V_62 . V_63 ] ;
struct V_66 * V_67 ;
if ( V_4 -> V_2 . V_62 . V_63 == V_68 )
V_67 = V_6 -> V_69 ;
else if ( V_4 -> V_2 . V_62 . V_63 == V_70 )
V_67 = V_6 -> V_71 ;
else
goto V_72;
F_33 ( V_75 ) ;
( void ) F_26 ( V_61 , false ) ;
F_34 ( V_4 -> V_2 . V_41 , & V_4 -> V_2 . V_62 ) ;
F_28 ( V_61 ) ;
return ;
V_72:
F_30 ( V_4 ) ;
}
void F_35 ( struct V_3 * * V_4 )
{
struct V_1 * V_2 ;
if ( ( * V_4 ) == NULL )
return;
V_2 = & ( ( * V_4 ) -> V_2 ) ;
F_36 ( & V_2 ) ;
if ( V_2 == NULL )
* V_4 = NULL ;
}
struct V_3 * F_37 ( struct V_3 * V_4 )
{
F_38 ( & V_4 -> V_2 ) ;
return V_4 ;
}
int F_39 ( struct V_3 * V_4 , T_1 V_16 , T_2 * V_76 )
{
struct V_5 * V_6 = (struct V_5 * ) V_4 -> V_7 . V_8 -> V_9 ;
int V_39 , V_77 ;
if ( V_4 -> V_50 ) {
V_4 -> V_50 ++ ;
if ( V_76 )
* V_76 = F_40 ( V_4 ) ;
return 0 ;
}
F_11 ( V_4 , V_16 ) ;
for ( V_77 = 0 ; V_77 < V_4 -> V_18 . V_31 ; V_77 ++ )
V_4 -> V_21 [ V_77 ] |= V_78 ;
V_39 = F_41 ( & V_4 -> V_2 , & V_4 -> V_18 , false , false ) ;
if ( F_42 ( V_39 == 0 ) ) {
V_4 -> V_50 = 1 ;
if ( V_76 != NULL )
* V_76 = F_40 ( V_4 ) ;
}
if ( F_13 ( V_39 != 0 ) )
F_21 ( V_6 -> V_8 , L_2 , V_4 ) ;
return V_39 ;
}
int F_43 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_4 -> V_7 . V_8 -> V_9 ;
int V_39 , V_77 ;
if ( ! V_4 -> V_50 ) {
F_44 ( V_6 -> V_8 , L_3 , V_4 ) ;
return 0 ;
}
V_4 -> V_50 -- ;
if ( V_4 -> V_50 )
return 0 ;
for ( V_77 = 0 ; V_77 < V_4 -> V_18 . V_31 ; V_77 ++ )
V_4 -> V_21 [ V_77 ] &= ~ V_78 ;
V_39 = F_41 ( & V_4 -> V_2 , & V_4 -> V_18 , false , false ) ;
if ( F_13 ( V_39 != 0 ) )
F_21 ( V_6 -> V_8 , L_4 , V_4 ) ;
return V_39 ;
}
void F_45 ( struct V_5 * V_6 )
{
struct V_3 * V_4 , * V_79 ;
if ( F_46 ( & V_6 -> V_11 . V_80 ) )
return;
F_21 ( V_6 -> V_8 , L_5 ) ;
F_47 (bo, n, &qdev->gem.objects, list) {
F_5 ( & V_6 -> V_43 -> V_81 ) ;
F_21 ( V_6 -> V_8 , L_6 ,
& V_4 -> V_7 , V_4 , ( unsigned long ) V_4 -> V_7 . V_33 ,
* ( ( unsigned long * ) & V_4 -> V_7 . V_82 ) ) ;
F_5 ( & V_6 -> V_11 . V_12 ) ;
F_6 ( & V_4 -> V_13 ) ;
F_7 ( & V_6 -> V_11 . V_12 ) ;
F_48 ( & V_4 -> V_7 ) ;
F_7 ( & V_6 -> V_43 -> V_81 ) ;
}
}
int F_49 ( struct V_5 * V_6 )
{
return F_50 ( V_6 ) ;
}
void F_51 ( struct V_5 * V_6 )
{
F_52 ( V_6 ) ;
}
int F_53 ( struct V_5 * V_6 , struct V_3 * V_4 )
{
int V_65 ;
if ( V_4 -> type == V_26 && V_4 -> V_51 == 0 ) {
V_65 = F_54 ( V_6 , V_4 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_55 ( V_6 , V_4 , NULL ) ;
if ( V_65 )
return V_65 ;
}
return 0 ;
}
void F_56 ( struct V_83 * V_84 , bool V_85 )
{
struct V_86 * V_87 , * V_88 ;
F_47 (entry, sf, &reloc_list->bos, lhead) {
F_57 ( V_87 -> V_4 ) ;
F_58 ( & V_87 -> V_89 ) ;
F_9 ( V_87 ) ;
}
}
int F_59 ( struct V_83 * V_84 , struct V_3 * V_4 )
{
struct V_86 * V_87 ;
int V_65 ;
F_60 (entry, &reloc_list->bos, lhead) {
if ( V_87 -> V_4 == V_4 )
return 0 ;
}
V_87 = F_61 ( sizeof( struct V_86 ) , V_46 ) ;
if ( ! V_87 )
return - V_47 ;
V_87 -> V_4 = V_4 ;
F_62 ( & V_87 -> V_89 , & V_84 -> V_90 ) ;
V_65 = F_63 ( V_4 , false ) ;
if ( V_65 )
return V_65 ;
if ( ! V_4 -> V_50 ) {
F_11 ( V_4 , V_4 -> type ) ;
V_65 = F_41 ( & V_4 -> V_2 , & V_4 -> V_18 ,
true , false ) ;
if ( V_65 )
return V_65 ;
}
V_65 = F_53 ( V_4 -> V_7 . V_8 -> V_9 , V_4 ) ;
if ( V_65 )
return V_65 ;
return 0 ;
}
