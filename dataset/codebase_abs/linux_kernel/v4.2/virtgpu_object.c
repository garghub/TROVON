static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
V_6 = (struct V_5 * ) V_4 -> V_7 . V_8 -> V_9 ;
if ( V_4 -> V_10 )
F_3 ( V_6 , V_4 -> V_10 ) ;
if ( V_4 -> V_11 )
F_4 ( V_4 ) ;
F_5 ( & V_4 -> V_7 ) ;
F_6 ( V_4 ) ;
}
static void F_7 ( struct V_3 * V_12 ,
bool V_13 )
{
T_1 V_14 = 1 ;
T_1 V_15 = V_13 ? V_16 : 0 ;
V_12 -> V_17 . V_17 = & V_12 -> V_18 ;
V_12 -> V_17 . V_19 = & V_12 -> V_18 ;
V_12 -> V_18 . V_20 = 0 ;
V_12 -> V_18 . V_21 = 0 ;
V_12 -> V_18 . V_22 =
V_23 | V_24 | V_15 ;
V_12 -> V_17 . V_25 = V_14 ;
V_12 -> V_17 . V_26 = V_14 ;
}
int F_8 ( struct V_5 * V_6 ,
unsigned long V_27 , bool V_28 , bool V_13 ,
struct V_3 * * V_29 )
{
struct V_3 * V_4 ;
enum V_30 type ;
T_2 V_31 ;
int V_32 ;
if ( V_28 )
type = V_33 ;
else
type = V_34 ;
* V_29 = NULL ;
V_31 = F_9 ( & V_6 -> V_35 . V_36 , V_27 ,
sizeof( struct V_3 ) ) ;
V_4 = F_10 ( sizeof( struct V_3 ) , V_37 ) ;
if ( V_4 == NULL )
return - V_38 ;
V_27 = F_11 ( V_27 , V_39 ) ;
V_32 = F_12 ( V_6 -> V_40 , & V_4 -> V_7 , V_27 ) ;
if ( V_32 != 0 )
goto V_41;
V_4 -> V_42 = false ;
F_7 ( V_4 , V_13 ) ;
V_32 = F_13 ( & V_6 -> V_35 . V_36 , & V_4 -> V_2 , V_27 , type ,
& V_4 -> V_17 , 0 , ! V_28 , NULL , V_31 ,
NULL , NULL , & F_1 ) ;
if ( V_32 != 0 )
goto V_43;
* V_29 = V_4 ;
return 0 ;
V_43:
F_5 ( & V_4 -> V_7 ) ;
V_41:
F_6 ( V_4 ) ;
return V_32 ;
}
int F_14 ( struct V_3 * V_4 , void * * V_44 )
{
bool V_45 ;
int V_46 ;
if ( V_4 -> V_47 ) {
if ( V_44 )
* V_44 = V_4 -> V_47 ;
return 0 ;
}
V_46 = F_15 ( & V_4 -> V_2 , 0 , V_4 -> V_2 . V_48 , & V_4 -> V_49 ) ;
if ( V_46 )
return V_46 ;
V_4 -> V_47 = F_16 ( & V_4 -> V_49 , & V_45 ) ;
if ( V_44 )
* V_44 = V_4 -> V_47 ;
return 0 ;
}
int F_17 ( struct V_5 * V_50 ,
struct V_3 * V_4 )
{
int V_32 ;
struct V_51 * * V_11 = V_4 -> V_2 . V_52 -> V_11 ;
int V_53 = V_4 -> V_2 . V_48 ;
if ( V_4 -> V_11 )
return 0 ;
if ( V_4 -> V_2 . V_52 -> V_54 == V_55 )
V_4 -> V_2 . V_52 -> V_36 -> V_56 -> V_57 ( V_4 -> V_2 . V_52 ) ;
V_4 -> V_11 = F_18 ( sizeof( struct V_58 ) , V_37 ) ;
if ( ! V_4 -> V_11 )
goto V_59;
V_32 = F_19 ( V_4 -> V_11 , V_11 , V_53 , 0 ,
V_53 << V_60 , V_37 ) ;
if ( V_32 )
goto V_59;
return 0 ;
V_59:
F_6 ( V_4 -> V_11 ) ;
V_4 -> V_11 = NULL ;
return - V_38 ;
}
void F_4 ( struct V_3 * V_4 )
{
F_20 ( V_4 -> V_11 ) ;
F_6 ( V_4 -> V_11 ) ;
V_4 -> V_11 = NULL ;
}
int F_21 ( struct V_3 * V_4 , bool V_61 )
{
int V_46 ;
V_46 = F_22 ( & V_4 -> V_2 , true , V_61 , false , NULL ) ;
if ( F_23 ( V_46 != 0 ) )
return V_46 ;
V_46 = F_24 ( & V_4 -> V_2 , true , true , V_61 ) ;
F_25 ( & V_4 -> V_2 ) ;
return V_46 ;
}
