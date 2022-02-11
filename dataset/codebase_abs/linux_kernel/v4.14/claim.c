void F_1 ( struct V_1 * V_2 , struct V_3 * * V_4 )
{
struct V_3 * V_5 = * V_4 ;
struct V_6 * V_6 ;
if ( ! V_5 )
return;
V_6 = F_2 ( & V_5 -> V_2 ) ;
F_3 ( & V_6 -> V_7 ) ;
F_4 ( V_2 , V_5 -> V_8 != V_2 , L_1 , V_9 ) ;
V_5 -> V_8 = NULL ;
* V_4 = NULL ;
F_5 ( & V_5 -> V_2 ) ;
}
void F_6 ( struct V_1 * V_2 ,
struct V_3 * * V_4 )
{
struct V_3 * V_5 = * V_4 ;
if ( ! V_5 )
return;
F_7 ( & V_5 -> V_2 ) ;
F_8 ( & V_5 -> V_2 ) ;
F_1 ( V_2 , V_4 ) ;
F_9 ( & V_5 -> V_2 ) ;
F_5 ( & V_5 -> V_2 ) ;
}
bool F_10 ( struct V_1 * V_2 , struct V_3 * V_10 ,
struct V_3 * * V_4 )
{
struct V_6 * V_6 = F_2 ( & V_10 -> V_2 ) ;
if ( V_10 -> V_8 )
return false ;
F_3 ( & V_6 -> V_7 ) ;
F_4 ( V_2 , * V_4 , L_1 , V_9 ) ;
V_10 -> V_8 = V_2 ;
* V_4 = V_10 ;
F_7 ( & V_10 -> V_2 ) ;
return true ;
}
bool F_11 ( struct V_1 * V_2 , struct V_3 * V_10 ,
struct V_3 * * V_4 )
{
bool V_11 ;
F_8 ( & V_10 -> V_2 ) ;
V_11 = F_10 ( V_2 , V_10 , V_4 ) ;
F_9 ( & V_10 -> V_2 ) ;
return V_11 ;
}
static int F_12 ( struct V_1 * V_2 , void * V_12 )
{
char * V_13 = V_12 ;
return strcmp ( V_13 , F_13 ( V_2 ) ) == 0 ;
}
static bool F_14 ( struct V_1 * V_2 , struct V_3 * V_5 )
{
struct V_14 * V_14 = F_15 ( V_2 -> V_15 ) ;
struct V_1 * V_16 = NULL ;
if ( F_16 ( V_2 ) )
V_16 = V_14 -> V_17 ;
else if ( F_17 ( V_2 ) )
V_16 = V_14 -> V_18 ;
else if ( F_18 ( V_2 ) )
V_16 = V_14 -> V_19 ;
if ( V_16 == V_2 || V_5 || V_2 -> V_20 )
return false ;
return true ;
}
struct V_21 * F_19 ( struct V_1 * V_2 )
{
if ( F_17 ( V_2 ) )
return F_20 ( V_2 ) ;
if ( F_18 ( V_2 ) ) {
struct V_22 * V_22 = F_21 ( V_2 ) ;
return & V_22 -> V_21 ;
}
F_22 ( 1 ) ;
return NULL ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_3 * * V_4 )
{
F_1 ( V_2 , V_4 ) ;
if ( F_14 ( V_2 , * V_4 ) ) {
F_24 ( V_2 , V_23 ) ;
} else if ( F_16 ( V_2 ) ) {
struct V_24 * V_24 = F_25 ( V_2 ) ;
V_24 -> V_25 = 0 ;
F_26 ( V_24 -> V_26 ) ;
V_24 -> V_26 = NULL ;
} else if ( F_17 ( V_2 ) || F_18 ( V_2 ) ) {
struct V_21 * V_21 = F_19 ( V_2 ) ;
F_26 ( V_21 -> V_26 ) ;
V_21 -> V_26 = NULL ;
V_21 -> V_27 = V_28 ;
}
}
T_1 F_27 ( struct V_1 * V_2 ,
struct V_3 * * V_4 , const char * V_29 ,
T_2 V_30 )
{
struct V_3 * V_5 ;
struct V_1 * V_31 ;
char * V_13 ;
if ( V_2 -> V_20 ) {
F_28 ( V_2 , L_2 , V_9 ) ;
return - V_32 ;
}
V_13 = F_29 ( V_29 , V_30 , V_33 ) ;
if ( ! V_13 )
return - V_34 ;
F_30 ( V_13 ) ;
if ( strncmp ( V_13 , L_3 , 9 ) == 0 || strcmp ( V_13 , L_4 ) == 0 )
;
else {
V_30 = - V_35 ;
goto V_36;
}
V_5 = * V_4 ;
if ( strcmp ( V_13 , L_4 ) == 0 ) {
F_23 ( V_2 , V_4 ) ;
goto V_36;
} else if ( V_5 ) {
F_28 ( V_2 , L_5 ,
F_13 ( & V_5 -> V_2 ) ) ;
V_30 = - V_32 ;
goto V_36;
}
V_31 = F_31 ( V_2 -> V_15 , V_13 , F_12 ) ;
if ( ! V_31 ) {
F_28 ( V_2 , L_6 , V_13 ,
F_13 ( V_2 -> V_15 ) ) ;
V_30 = - V_37 ;
goto V_36;
}
V_5 = F_32 ( V_31 ) ;
switch ( V_5 -> V_38 ) {
case V_39 :
break;
case V_40 :
case V_41 :
if ( ! F_16 ( V_2 ) ) {
V_30 = - V_32 ;
goto V_42;
}
break;
case V_43 :
if ( ! F_17 ( V_2 ) ) {
V_30 = - V_32 ;
goto V_42;
}
break;
case V_44 :
if ( ! F_18 ( V_2 ) ) {
V_30 = - V_32 ;
goto V_42;
}
break;
default:
V_30 = - V_32 ;
goto V_42;
break;
}
if ( F_33 ( V_5 ) < V_45 ) {
F_28 ( V_2 , L_7 , V_13 ) ;
V_30 = - V_46 ;
goto V_42;
}
F_34 ( ! F_35 ( V_2 ) ) ;
if ( ! F_10 ( V_2 , V_5 , V_4 ) ) {
F_28 ( V_2 , L_8 ,
F_13 ( & V_5 -> V_2 ) ) ;
V_30 = - V_32 ;
}
V_42:
F_5 ( & V_5 -> V_2 ) ;
V_36:
F_26 ( V_13 ) ;
return V_30 ;
}
T_3 F_36 ( struct V_47 * V_47 )
{
T_3 V_48 ;
T_4 V_49 ;
F_37 ( sizeof( struct V_50 ) != V_51 ) ;
F_37 ( sizeof( struct V_52 ) != V_51 ) ;
F_37 ( sizeof( struct V_47 ) != V_51 ) ;
V_49 = V_47 -> V_53 ;
V_47 -> V_53 = 0 ;
V_48 = F_38 ( V_47 , sizeof( * V_47 ) , 1 ) ;
V_47 -> V_53 = V_49 ;
return V_48 ;
}
static int F_39 ( struct V_3 * V_5 ,
T_5 V_54 , void * V_29 , T_2 V_55 , int V_56 ,
unsigned long V_57 )
{
struct V_58 * V_59 = F_40 ( & V_5 -> V_2 ) ;
unsigned int V_60 = F_41 ( V_55 + ( V_54 & ( 512 - 1 ) ) , 512 ) ;
T_6 V_61 = V_54 >> 9 ;
int V_62 = 0 ;
if ( F_42 ( ! V_55 ) )
return 0 ;
if ( F_42 ( V_54 + V_55 > V_59 -> V_55 ) ) {
F_4 ( & V_5 -> V_2 , 1 , L_9 ) ;
return - V_63 ;
}
if ( V_56 == V_64 ) {
if ( F_42 ( F_43 ( & V_59 -> V_65 , V_61 , V_60 ) ) )
return - V_66 ;
return F_44 ( V_29 , V_59 -> V_67 + V_54 , V_55 ) ;
}
if ( F_42 ( F_43 ( & V_59 -> V_65 , V_61 , V_60 ) ) ) {
if ( F_45 ( V_54 , 512 ) && F_45 ( V_55 , 512 )
&& ! ( V_57 & V_68 ) ) {
long V_69 ;
F_46 () ;
V_69 = F_47 ( & V_5 -> V_2 ,
V_59 -> V_70 . V_71 + V_54 , V_55 ) ;
if ( V_69 < V_55 )
V_62 = - V_66 ;
if ( V_69 > 0 && V_69 / 512 ) {
V_69 /= 512 ;
F_48 ( & V_59 -> V_65 , V_61 , V_69 ) ;
}
F_49 ( V_59 -> V_67 + V_54 , V_55 ) ;
} else
V_62 = - V_66 ;
}
F_50 ( V_59 -> V_67 + V_54 , V_29 , V_55 ) ;
F_51 ( F_15 ( V_5 -> V_2 . V_15 ) ) ;
return V_62 ;
}
int F_52 ( struct V_1 * V_2 , struct V_58 * V_59 )
{
struct V_72 * V_70 = & V_59 -> V_70 ;
struct V_3 * V_5 = & V_59 -> V_73 ;
V_59 -> V_55 = F_53 ( V_70 ) ;
if ( ! F_54 ( V_2 , V_70 -> V_71 , F_53 ( V_70 ) ,
F_13 ( & V_5 -> V_2 ) ) ) {
F_55 ( V_2 , L_10 , V_70 ) ;
return - V_32 ;
}
V_5 -> V_74 = F_39 ;
if ( F_56 ( V_2 , & V_59 -> V_65 ) )
return - V_34 ;
F_57 ( F_15 ( V_5 -> V_2 . V_15 ) , & V_59 -> V_65 ,
& V_59 -> V_70 ) ;
V_59 -> V_67 = F_58 ( V_2 , V_70 -> V_71 , F_53 ( V_70 ) ,
V_75 ) ;
return F_59 ( V_59 -> V_67 ) ;
}
void F_60 ( struct V_1 * V_2 , struct V_58 * V_59 )
{
struct V_72 * V_70 = & V_59 -> V_70 ;
F_61 ( V_2 , V_59 -> V_67 ) ;
F_62 ( V_2 , & V_59 -> V_65 ) ;
F_63 ( V_2 , V_70 -> V_71 , F_53 ( V_70 ) ) ;
}
