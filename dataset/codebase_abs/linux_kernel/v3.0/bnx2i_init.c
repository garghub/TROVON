void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = 0 ;
if ( ( V_2 -> V_4 == V_5 ) ||
( V_2 -> V_4 == V_6 ) )
F_2 ( V_7 , & V_2 -> V_3 ) ;
else if ( ( V_2 -> V_4 == V_8 ) ||
( V_2 -> V_4 == V_9 ) )
F_2 ( V_10 , & V_2 -> V_3 ) ;
else if ( ( V_2 -> V_4 == V_11 ) ||
( V_2 -> V_4 == V_12 ) ) {
F_2 ( V_13 , & V_2 -> V_3 ) ;
V_2 -> V_14 = V_15 ;
} else if ( V_2 -> V_4 == V_16 ||
V_2 -> V_4 == V_17 ||
V_2 -> V_4 == V_18 ||
V_2 -> V_4 == V_19 ||
V_2 -> V_4 == V_20 )
F_2 ( V_21 , & V_2 -> V_3 ) ;
else
F_3 ( V_22 L_1 ,
V_2 -> V_4 ) ;
}
struct V_1 * F_4 ( void )
{
struct V_1 * V_2 = NULL ;
struct V_1 * V_23 ;
if ( ! V_24 )
goto V_25;
F_5 ( & V_26 ) ;
F_6 (tmp_hba, &adapter_list, link) {
if ( V_23 -> V_27 && V_23 -> V_27 -> V_28 ) {
V_2 = V_23 ;
break;
}
}
F_7 ( & V_26 ) ;
V_25:
return V_2 ;
}
struct V_1 * F_8 ( struct V_29 * V_27 )
{
struct V_1 * V_2 , * V_30 ;
F_5 ( & V_26 ) ;
F_9 (hba, temp, &adapter_list, link) {
if ( V_2 -> V_27 == V_27 ) {
F_7 ( & V_26 ) ;
return V_2 ;
}
}
F_7 ( & V_26 ) ;
return NULL ;
}
void F_10 ( void * V_31 )
{
#define F_11 (1000 / HZ)
struct V_1 * V_2 = V_31 ;
int V_32 = V_33 ;
if ( ! V_2 -> V_27 -> V_34 ) {
F_3 ( V_22 L_2
L_3 , V_2 -> V_35 -> V_36 ) ;
if ( F_12 ( V_37 , & V_2 -> V_38 ) ) {
F_5 ( & V_26 ) ;
F_13 ( & V_2 -> V_39 ) ;
V_24 -- ;
V_2 -> V_27 -> V_40 ( V_2 -> V_27 , V_41 ) ;
F_14 ( V_37 , & V_2 -> V_38 ) ;
F_7 ( & V_26 ) ;
F_15 ( V_2 ) ;
}
return;
}
F_16 ( V_2 ) ;
while ( ! F_12 ( V_42 , & V_2 -> V_43 ) && V_32 -- )
F_17 ( F_11 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_44 * V_45 ;
struct V_46 * V_47 , * V_48 ;
if ( V_2 -> V_49 ) {
F_3 ( V_22 L_4
L_5 , V_2 -> V_35 -> V_36 ,
V_2 -> V_49 ) ;
F_5 ( & V_2 -> V_50 ) ;
F_19 (pos, tmp, &hba->ep_active_list) {
V_45 = F_20 ( V_47 , struct V_44 , V_39 ) ;
F_21 ( V_45 ) ;
V_45 -> V_51 = NULL ;
}
F_7 ( & V_2 -> V_50 ) ;
}
}
void F_22 ( void * V_31 )
{
struct V_1 * V_2 = V_31 ;
int V_52 ;
int V_53 = 1 * V_33 ;
if ( ! F_23 ( V_54 ,
& V_2 -> V_43 ) ) {
F_24 ( V_2 -> V_55 ,
V_56 ) ;
V_53 = V_2 -> V_57 ;
}
F_25 ( V_2 -> V_58 ,
( F_26 ( & V_2 -> V_59 ) &&
F_26 ( & V_2 -> V_60 ) ) ,
2 * V_33 ) ;
while ( V_2 -> V_49 ) {
V_52 = V_2 -> V_49 ;
F_25 ( V_2 -> V_58 ,
( V_2 -> V_49 != V_52 ) ,
V_53 ) ;
if ( V_2 -> V_49 == V_52 )
break;
}
F_18 ( V_2 ) ;
F_14 ( V_54 , & V_2 -> V_43 ) ;
F_14 ( V_42 , & V_2 -> V_43 ) ;
}
static int F_27 ( struct V_1 * V_2 , struct V_29 * V_27 )
{
int V_61 ;
F_5 ( & V_26 ) ;
V_2 -> V_27 = V_27 ;
V_61 = V_27 -> V_62 ( V_27 , V_41 , V_2 ) ;
if ( ! V_61 ) {
V_2 -> V_63 ++ ;
F_2 ( V_37 , & V_2 -> V_38 ) ;
F_28 ( & V_2 -> V_39 , & V_64 ) ;
V_24 ++ ;
} else if ( V_61 == - V_65 )
F_3 ( V_22 L_6
L_7 , V_2 , V_27 ) ;
else if ( V_61 == - V_66 )
F_3 ( V_67 L_8 ) ;
else if ( V_61 == - V_68 )
F_3 ( V_67 L_9 , V_41 ) ;
else
F_3 ( V_67 L_10 , V_61 ) ;
F_7 ( & V_26 ) ;
return V_61 ;
}
void F_29 ( struct V_29 * V_69 )
{
struct V_1 * V_2 ;
V_2 = F_30 ( V_69 ) ;
if ( ! V_2 ) {
F_3 ( V_67 L_11 ) ;
return;
}
F_14 ( V_37 , & V_2 -> V_38 ) ;
if ( F_27 ( V_2 , V_69 ) ) {
F_3 ( V_67 L_12 , V_2 ) ;
F_15 ( V_2 ) ;
}
}
void F_31 ( struct V_29 * V_69 )
{
struct V_1 * V_2 ;
V_2 = F_8 ( V_69 ) ;
if ( ! V_2 ) {
F_3 ( V_70 L_13
L_14 , V_69 ) ;
return;
}
F_5 ( & V_26 ) ;
F_13 ( & V_2 -> V_39 ) ;
V_24 -- ;
if ( F_12 ( V_37 , & V_2 -> V_38 ) ) {
V_2 -> V_27 -> V_40 ( V_2 -> V_27 , V_41 ) ;
F_14 ( V_37 , & V_2 -> V_38 ) ;
}
F_7 ( & V_26 ) ;
F_15 ( V_2 ) ;
}
static int T_1 F_32 ( void )
{
int V_71 ;
F_3 ( V_70 L_15 , V_72 ) ;
if ( V_73 && ! F_33 ( V_73 ) )
V_73 = F_34 ( V_73 ) ;
F_35 ( & V_26 ) ;
V_74 =
F_36 ( & V_75 ) ;
if ( ! V_74 ) {
F_3 ( V_67 L_16 ) ;
V_71 = - V_76 ;
goto V_77;
}
V_71 = F_37 ( V_41 , & V_78 ) ;
if ( V_71 ) {
F_3 ( V_67 L_17 ) ;
goto V_79;
}
return 0 ;
V_79:
F_38 ( & V_75 ) ;
V_77:
return V_71 ;
}
static void T_2 F_39 ( void )
{
struct V_1 * V_2 ;
F_5 ( & V_26 ) ;
while ( ! F_26 ( & V_64 ) ) {
V_2 = F_20 ( V_64 . V_80 , struct V_1 , V_39 ) ;
F_40 ( & V_2 -> V_39 ) ;
V_24 -- ;
if ( F_12 ( V_37 , & V_2 -> V_38 ) ) {
F_18 ( V_2 ) ;
V_2 -> V_27 -> V_40 ( V_2 -> V_27 , V_41 ) ;
F_14 ( V_37 , & V_2 -> V_38 ) ;
}
F_15 ( V_2 ) ;
}
F_7 ( & V_26 ) ;
F_38 ( & V_75 ) ;
F_41 ( V_41 ) ;
}
