int F_1 ( struct V_1 * V_2 )
{
F_2 () ;
return 0 ;
}
void F_3 ( struct V_1 * V_3 )
{
struct V_4 * V_5 = F_4 ( V_3 ) ;
if ( V_5 ) {
F_5 ( & V_5 ) ;
}
}
int F_6 ( struct V_6 * V_7 , int V_8 ,
int V_9 , int V_10 ,
bool V_11 , bool V_12 ,
struct V_1 * * V_2 )
{
struct V_4 * V_5 ;
int V_13 ;
* V_2 = NULL ;
if ( V_9 < V_14 ) {
V_9 = V_14 ;
}
V_13 = F_7 ( V_7 , V_8 , V_9 , V_12 , V_10 , & V_5 ) ;
if ( V_13 ) {
if ( V_13 != - V_15 )
F_8 ( L_1 ,
V_8 , V_10 , V_9 , V_13 ) ;
return V_13 ;
}
* V_2 = & V_5 -> V_16 ;
F_9 ( & V_7 -> V_17 . V_18 ) ;
F_10 ( & V_5 -> V_19 , & V_7 -> V_17 . V_20 ) ;
F_11 ( & V_7 -> V_17 . V_18 ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 , T_1 V_21 ,
T_2 * V_22 )
{
struct V_4 * V_5 = F_4 ( V_2 ) ;
int V_13 ;
V_13 = F_13 ( V_5 , false ) ;
if ( F_14 ( V_13 != 0 ) )
return V_13 ;
V_13 = F_15 ( V_5 , V_21 , V_22 ) ;
F_16 ( V_5 ) ;
return V_13 ;
}
void F_17 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_4 ( V_2 ) ;
int V_13 ;
V_13 = F_13 ( V_5 , false ) ;
if ( F_18 ( V_13 == 0 ) ) {
F_19 ( V_5 ) ;
F_16 ( V_5 ) ;
}
}
int F_20 ( struct V_1 * V_3 ,
T_1 V_23 , T_1 V_24 )
{
struct V_4 * V_5 ;
T_1 V_25 ;
int V_13 ;
V_5 = F_4 ( V_3 ) ;
V_25 = V_24 ;
if ( ! V_25 ) {
V_25 = V_23 ;
}
if ( ! V_25 ) {
F_21 ( V_26 L_2 ) ;
return 0 ;
}
if ( V_25 == V_27 ) {
V_13 = F_22 ( V_5 , NULL , false ) ;
if ( V_13 ) {
F_21 ( V_28 L_3 ) ;
return V_13 ;
}
}
return 0 ;
}
int F_23 ( struct V_6 * V_7 )
{
F_24 ( & V_7 -> V_17 . V_20 ) ;
return 0 ;
}
void F_25 ( struct V_6 * V_7 )
{
F_26 ( V_7 ) ;
}
int F_27 ( struct V_29 * V_30 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_6 * V_7 = V_30 -> V_34 ;
struct V_35 * args = V_31 ;
struct V_36 * V_37 ;
V_37 = & V_7 -> V_38 . V_39 . V_37 [ V_40 ] ;
args -> V_41 = V_7 -> V_42 . V_43 ;
args -> V_44 = ( V_45 ) V_37 -> V_8 << V_46 ;
if ( V_7 -> V_47 )
args -> V_44 -= F_28 ( V_7 -> V_47 ) ;
args -> V_44 -= F_29 ( V_7 ) ;
args -> V_48 = V_7 -> V_42 . V_49 - V_7 -> V_50 . V_51 - 4096 -
V_52 * 64 * 1024 ;
return 0 ;
}
int F_30 ( struct V_29 * V_30 , void * V_31 ,
struct V_32 * V_33 )
{
F_8 ( L_4 , V_53 ) ;
return - V_54 ;
}
int F_31 ( struct V_29 * V_30 , void * V_31 ,
struct V_32 * V_33 )
{
F_8 ( L_4 , V_53 ) ;
return - V_54 ;
}
int F_32 ( struct V_29 * V_30 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_6 * V_7 = V_30 -> V_34 ;
struct V_55 * args = V_31 ;
struct V_1 * V_3 ;
T_1 V_56 ;
int V_13 ;
args -> V_8 = F_33 ( args -> V_8 , V_14 ) ;
V_13 = F_6 ( V_7 , args -> V_8 , args -> V_9 ,
args -> V_10 , false ,
false , & V_3 ) ;
if ( V_13 ) {
return V_13 ;
}
V_13 = F_34 ( V_33 , V_3 , & V_56 ) ;
F_35 ( V_3 ) ;
if ( V_13 ) {
return V_13 ;
}
args -> V_56 = V_56 ;
return 0 ;
}
int F_36 ( struct V_29 * V_30 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_57 * args = V_31 ;
struct V_1 * V_3 ;
struct V_4 * V_5 ;
int V_13 ;
V_3 = F_37 ( V_30 , V_33 , args -> V_56 ) ;
if ( V_3 == NULL ) {
return - V_58 ;
}
V_5 = F_4 ( V_3 ) ;
V_13 = F_20 ( V_3 , args -> V_59 , args -> V_60 ) ;
F_35 ( V_3 ) ;
return V_13 ;
}
int F_38 ( struct V_32 * V_33 ,
struct V_29 * V_30 ,
T_1 V_56 , T_2 * V_61 )
{
struct V_1 * V_3 ;
struct V_4 * V_5 ;
V_3 = F_37 ( V_30 , V_33 , V_56 ) ;
if ( V_3 == NULL ) {
return - V_58 ;
}
V_5 = F_4 ( V_3 ) ;
* V_61 = F_39 ( V_5 ) ;
F_35 ( V_3 ) ;
return 0 ;
}
int F_40 ( struct V_29 * V_30 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_62 * args = V_31 ;
return F_38 ( V_33 , V_30 , args -> V_56 , & args -> V_63 ) ;
}
int F_41 ( struct V_29 * V_30 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_64 * args = V_31 ;
struct V_1 * V_3 ;
struct V_4 * V_5 ;
int V_13 ;
T_1 V_65 = 0 ;
V_3 = F_37 ( V_30 , V_33 , args -> V_56 ) ;
if ( V_3 == NULL ) {
return - V_58 ;
}
V_5 = F_4 ( V_3 ) ;
V_13 = F_22 ( V_5 , & V_65 , true ) ;
switch ( V_65 ) {
case V_40 :
args -> V_25 = V_66 ;
break;
case V_67 :
args -> V_25 = V_68 ;
break;
case V_69 :
args -> V_25 = V_27 ;
default:
break;
}
F_35 ( V_3 ) ;
return V_13 ;
}
int F_42 ( struct V_29 * V_30 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_70 * args = V_31 ;
struct V_1 * V_3 ;
struct V_4 * V_5 ;
int V_13 ;
V_3 = F_37 ( V_30 , V_33 , args -> V_56 ) ;
if ( V_3 == NULL ) {
return - V_58 ;
}
V_5 = F_4 ( V_3 ) ;
V_13 = F_22 ( V_5 , NULL , false ) ;
if ( V_5 -> V_7 -> V_71 -> V_72 )
V_5 -> V_7 -> V_71 -> V_72 ( V_5 -> V_7 , V_5 ) ;
F_35 ( V_3 ) ;
return V_13 ;
}
int F_43 ( struct V_29 * V_30 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_73 * args = V_31 ;
struct V_1 * V_3 ;
struct V_4 * V_5 ;
int V_13 = 0 ;
F_44 ( L_5 , args -> V_56 ) ;
V_3 = F_37 ( V_30 , V_33 , args -> V_56 ) ;
if ( V_3 == NULL )
return - V_58 ;
V_5 = F_4 ( V_3 ) ;
V_13 = F_45 ( V_5 , args -> V_74 , args -> V_75 ) ;
F_35 ( V_3 ) ;
return V_13 ;
}
int F_46 ( struct V_29 * V_30 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_76 * args = V_31 ;
struct V_1 * V_3 ;
struct V_4 * V_77 ;
int V_13 = 0 ;
F_44 ( L_6 ) ;
V_3 = F_37 ( V_30 , V_33 , args -> V_56 ) ;
if ( V_3 == NULL )
return - V_58 ;
V_77 = F_4 ( V_3 ) ;
V_13 = F_13 ( V_77 , false ) ;
if ( F_14 ( V_13 != 0 ) )
goto V_78;
F_47 ( V_77 , & args -> V_74 , & args -> V_75 ) ;
F_16 ( V_77 ) ;
V_78:
F_35 ( V_3 ) ;
return V_13 ;
}
int F_48 ( struct V_32 * V_79 ,
struct V_29 * V_30 ,
struct V_80 * args )
{
struct V_6 * V_7 = V_30 -> V_34 ;
struct V_1 * V_3 ;
T_1 V_56 ;
int V_13 ;
args -> V_75 = F_49 ( V_7 , args -> V_81 , args -> V_82 , 0 ) * ( ( args -> V_82 + 1 ) / 8 ) ;
args -> V_8 = args -> V_75 * args -> V_83 ;
args -> V_8 = F_50 ( args -> V_8 , V_14 ) ;
V_13 = F_6 ( V_7 , args -> V_8 , 0 ,
V_66 ,
false , V_84 ,
& V_3 ) ;
if ( V_13 )
return - V_85 ;
V_13 = F_34 ( V_79 , V_3 , & V_56 ) ;
F_35 ( V_3 ) ;
if ( V_13 ) {
return V_13 ;
}
args -> V_56 = V_56 ;
return 0 ;
}
int F_51 ( struct V_32 * V_79 ,
struct V_29 * V_30 ,
T_1 V_56 )
{
return F_52 ( V_79 , V_56 ) ;
}
