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
void F_11 ( struct V_3 * V_15 , T_1 V_16 , bool V_17 )
{
T_1 V_18 = 0 ;
T_1 V_19 = V_17 ? V_20 : 0 ;
V_15 -> V_21 . V_22 = 0 ;
V_15 -> V_21 . V_23 = 0 ;
V_15 -> V_21 . V_21 = V_15 -> V_24 ;
V_15 -> V_21 . V_25 = V_15 -> V_24 ;
if ( V_16 == V_26 )
V_15 -> V_24 [ V_18 ++ ] = V_27 | V_28 | V_19 ;
if ( V_16 == V_29 )
V_15 -> V_24 [ V_18 ++ ] = V_27 | V_30 | V_19 ;
if ( V_16 == V_31 )
V_15 -> V_24 [ V_18 ++ ] = V_32 | V_33 | V_19 ;
if ( ! V_18 )
V_15 -> V_24 [ V_18 ++ ] = V_32 | V_33 ;
V_15 -> V_21 . V_34 = V_18 ;
V_15 -> V_21 . V_35 = V_18 ;
}
int F_12 ( struct V_5 * V_6 ,
unsigned long V_36 , bool V_37 , bool V_17 , T_1 V_16 ,
struct V_38 * V_39 ,
struct V_3 * * V_40 )
{
struct V_3 * V_4 ;
enum V_41 type ;
int V_42 ;
if ( F_13 ( V_6 -> V_43 . V_44 . V_45 == NULL ) )
V_6 -> V_43 . V_44 . V_45 = V_6 -> V_46 -> V_45 ;
if ( V_37 )
type = V_47 ;
else
type = V_48 ;
* V_40 = NULL ;
V_4 = F_14 ( sizeof( struct V_3 ) , V_49 ) ;
if ( V_4 == NULL )
return - V_50 ;
V_36 = F_15 ( V_36 , V_51 ) ;
V_42 = F_16 ( V_6 -> V_46 , & V_4 -> V_7 , V_36 ) ;
if ( F_13 ( V_42 ) ) {
F_9 ( V_4 ) ;
return V_42 ;
}
V_4 -> V_7 . V_52 = NULL ;
V_4 -> type = V_16 ;
V_4 -> V_53 = V_17 ? 1 : 0 ;
V_4 -> V_54 = 0 ;
F_17 ( V_6 , & V_4 -> V_10 ) ;
F_18 ( & V_4 -> V_13 ) ;
if ( V_39 )
V_4 -> V_39 = * V_39 ;
F_11 ( V_4 , V_16 , V_17 ) ;
V_42 = F_19 ( & V_6 -> V_43 . V_44 , & V_4 -> V_2 , V_36 , type ,
& V_4 -> V_21 , 0 , ! V_37 , NULL , V_36 ,
NULL , & F_1 ) ;
if ( F_13 ( V_42 != 0 ) ) {
if ( V_42 != - V_55 )
F_20 ( V_6 -> V_8 ,
L_1 ,
V_36 , V_16 ) ;
return V_42 ;
}
* V_40 = V_4 ;
return 0 ;
}
int F_21 ( struct V_3 * V_4 , void * * V_56 )
{
bool V_57 ;
int V_42 ;
if ( V_4 -> V_58 ) {
if ( V_56 )
* V_56 = V_4 -> V_58 ;
return 0 ;
}
V_42 = F_22 ( & V_4 -> V_2 , 0 , V_4 -> V_2 . V_59 , & V_4 -> V_60 ) ;
if ( V_42 )
return V_42 ;
V_4 -> V_58 = F_23 ( & V_4 -> V_60 , & V_57 ) ;
if ( V_56 )
* V_56 = V_4 -> V_58 ;
return 0 ;
}
void * F_24 ( struct V_5 * V_6 ,
struct V_3 * V_4 , int V_61 )
{
struct V_62 * V_63 = & V_4 -> V_2 . V_44 -> V_63 [ V_4 -> V_2 . V_64 . V_65 ] ;
void * V_66 ;
int V_67 ;
struct V_68 * V_69 ;
if ( V_4 -> V_2 . V_64 . V_65 == V_70 )
V_69 = V_6 -> V_71 ;
else if ( V_4 -> V_2 . V_64 . V_65 == V_72 )
V_69 = V_6 -> V_73 ;
else
goto V_74;
( void ) F_25 ( V_63 , false ) ;
V_67 = F_26 ( V_4 -> V_2 . V_44 , & V_4 -> V_2 . V_64 ) ;
F_27 ( V_63 ) ;
return F_28 ( V_69 , V_4 -> V_2 . V_64 . V_75 . V_76 + V_61 ) ;
V_74:
if ( V_4 -> V_58 ) {
V_66 = V_4 -> V_58 + ( V_61 * V_51 ) ;
return V_66 ;
}
V_67 = F_21 ( V_4 , & V_66 ) ;
if ( V_67 )
return NULL ;
V_66 += V_61 * V_51 ;
return V_66 ;
}
void F_29 ( struct V_3 * V_4 )
{
if ( V_4 -> V_58 == NULL )
return;
V_4 -> V_58 = NULL ;
F_30 ( & V_4 -> V_60 ) ;
}
void F_31 ( struct V_5 * V_6 ,
struct V_3 * V_4 , void * V_77 )
{
struct V_62 * V_63 = & V_4 -> V_2 . V_44 -> V_63 [ V_4 -> V_2 . V_64 . V_65 ] ;
struct V_68 * V_69 ;
if ( V_4 -> V_2 . V_64 . V_65 == V_70 )
V_69 = V_6 -> V_71 ;
else if ( V_4 -> V_2 . V_64 . V_65 == V_72 )
V_69 = V_6 -> V_73 ;
else
goto V_74;
F_32 ( V_77 ) ;
( void ) F_25 ( V_63 , false ) ;
F_33 ( V_4 -> V_2 . V_44 , & V_4 -> V_2 . V_64 ) ;
F_27 ( V_63 ) ;
return ;
V_74:
F_29 ( V_4 ) ;
}
void F_34 ( struct V_3 * * V_4 )
{
struct V_1 * V_2 ;
if ( ( * V_4 ) == NULL )
return;
V_2 = & ( ( * V_4 ) -> V_2 ) ;
F_35 ( & V_2 ) ;
if ( V_2 == NULL )
* V_4 = NULL ;
}
struct V_3 * F_36 ( struct V_3 * V_4 )
{
F_37 ( & V_4 -> V_2 ) ;
return V_4 ;
}
int F_38 ( struct V_3 * V_4 , T_1 V_16 , T_2 * V_78 )
{
struct V_5 * V_6 = (struct V_5 * ) V_4 -> V_7 . V_8 -> V_9 ;
int V_42 ;
if ( V_4 -> V_53 ) {
V_4 -> V_53 ++ ;
if ( V_78 )
* V_78 = F_39 ( V_4 ) ;
return 0 ;
}
F_11 ( V_4 , V_16 , true ) ;
V_42 = F_40 ( & V_4 -> V_2 , & V_4 -> V_21 , false , false ) ;
if ( F_41 ( V_42 == 0 ) ) {
V_4 -> V_53 = 1 ;
if ( V_78 != NULL )
* V_78 = F_39 ( V_4 ) ;
}
if ( F_13 ( V_42 != 0 ) )
F_20 ( V_6 -> V_8 , L_2 , V_4 ) ;
return V_42 ;
}
int F_42 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_4 -> V_7 . V_8 -> V_9 ;
int V_42 , V_79 ;
if ( ! V_4 -> V_53 ) {
F_43 ( V_6 -> V_8 , L_3 , V_4 ) ;
return 0 ;
}
V_4 -> V_53 -- ;
if ( V_4 -> V_53 )
return 0 ;
for ( V_79 = 0 ; V_79 < V_4 -> V_21 . V_34 ; V_79 ++ )
V_4 -> V_24 [ V_79 ] &= ~ V_20 ;
V_42 = F_40 ( & V_4 -> V_2 , & V_4 -> V_21 , false , false ) ;
if ( F_13 ( V_42 != 0 ) )
F_20 ( V_6 -> V_8 , L_4 , V_4 ) ;
return V_42 ;
}
void F_44 ( struct V_5 * V_6 )
{
struct V_3 * V_4 , * V_80 ;
if ( F_45 ( & V_6 -> V_11 . V_81 ) )
return;
F_20 ( V_6 -> V_8 , L_5 ) ;
F_46 (bo, n, &qdev->gem.objects, list) {
F_5 ( & V_6 -> V_46 -> V_82 ) ;
F_20 ( V_6 -> V_8 , L_6 ,
& V_4 -> V_7 , V_4 , ( unsigned long ) V_4 -> V_7 . V_36 ,
* ( ( unsigned long * ) & V_4 -> V_7 . V_83 ) ) ;
F_5 ( & V_6 -> V_11 . V_12 ) ;
F_6 ( & V_4 -> V_13 ) ;
F_7 ( & V_6 -> V_11 . V_12 ) ;
F_47 ( & V_4 -> V_7 ) ;
F_7 ( & V_6 -> V_46 -> V_82 ) ;
}
}
int F_48 ( struct V_5 * V_6 )
{
return F_49 ( V_6 ) ;
}
void F_50 ( struct V_5 * V_6 )
{
F_51 ( V_6 ) ;
}
int F_52 ( struct V_5 * V_6 , struct V_3 * V_4 )
{
int V_67 ;
if ( V_4 -> type == V_29 && V_4 -> V_54 == 0 ) {
V_67 = F_53 ( V_6 , V_4 ) ;
if ( V_67 )
return V_67 ;
V_67 = F_54 ( V_6 , V_4 , NULL ) ;
if ( V_67 )
return V_67 ;
}
return 0 ;
}
int F_55 ( struct V_5 * V_6 )
{
return F_56 ( & V_6 -> V_43 . V_44 , V_72 ) ;
}
int F_57 ( struct V_5 * V_6 )
{
return F_56 ( & V_6 -> V_43 . V_44 , V_70 ) ;
}
