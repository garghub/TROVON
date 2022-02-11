void F_1 ( struct V_1 * V_2 , struct V_3 * * V_4 )
{
struct V_3 * V_5 = * V_4 ;
F_2 ( & V_5 -> V_2 . V_6 ) ;
F_3 ( V_2 , V_5 -> V_7 != V_2 , L_1 , V_8 ) ;
V_5 -> V_7 = NULL ;
* V_4 = NULL ;
F_4 ( & V_5 -> V_2 ) ;
}
void F_5 ( struct V_1 * V_2 ,
struct V_3 * * V_4 )
{
struct V_3 * V_5 = * V_4 ;
if ( ! V_5 )
return;
F_6 ( & V_5 -> V_2 ) ;
F_7 ( & V_5 -> V_2 ) ;
F_1 ( V_2 , V_4 ) ;
F_8 ( & V_5 -> V_2 ) ;
F_4 ( & V_5 -> V_2 ) ;
}
bool F_9 ( struct V_1 * V_2 , struct V_3 * V_9 ,
struct V_3 * * V_4 )
{
if ( V_9 -> V_7 )
return false ;
F_2 ( & V_9 -> V_2 . V_6 ) ;
F_3 ( V_2 , * V_4 , L_1 , V_8 ) ;
V_9 -> V_7 = V_2 ;
* V_4 = V_9 ;
F_6 ( & V_9 -> V_2 ) ;
return true ;
}
bool F_10 ( struct V_1 * V_2 , struct V_3 * V_9 ,
struct V_3 * * V_4 )
{
bool V_10 ;
F_7 ( & V_9 -> V_2 ) ;
V_10 = F_9 ( V_2 , V_9 , V_4 ) ;
F_8 ( & V_9 -> V_2 ) ;
return V_10 ;
}
static int F_11 ( struct V_1 * V_2 , void * V_11 )
{
char * V_12 = V_11 ;
return strcmp ( V_12 , F_12 ( V_2 ) ) == 0 ;
}
static bool F_13 ( struct V_1 * V_2 , struct V_3 * V_5 )
{
struct V_13 * V_13 = F_14 ( V_2 -> V_14 ) ;
struct V_1 * V_15 = NULL ;
if ( F_15 ( V_2 ) )
V_15 = V_13 -> V_16 ;
else if ( F_16 ( V_2 ) )
V_15 = V_13 -> V_17 ;
else if ( F_17 ( V_2 ) )
V_15 = V_13 -> V_18 ;
if ( V_15 == V_2 || V_5 || V_2 -> V_19 )
return false ;
return true ;
}
struct V_20 * F_18 ( struct V_1 * V_2 )
{
if ( F_16 ( V_2 ) )
return F_19 ( V_2 ) ;
if ( F_17 ( V_2 ) ) {
struct V_21 * V_21 = F_20 ( V_2 ) ;
return & V_21 -> V_20 ;
}
F_21 ( 1 ) ;
return NULL ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_3 * * V_4 )
{
F_5 ( V_2 , V_4 ) ;
if ( F_13 ( V_2 , * V_4 ) ) {
F_23 ( V_2 , V_22 ) ;
} else if ( F_15 ( V_2 ) ) {
struct V_23 * V_23 = F_24 ( V_2 ) ;
V_23 -> V_24 = 0 ;
F_25 ( V_23 -> V_25 ) ;
V_23 -> V_25 = NULL ;
} else if ( F_16 ( V_2 ) || F_17 ( V_2 ) ) {
struct V_20 * V_20 = F_18 ( V_2 ) ;
F_25 ( V_20 -> V_25 ) ;
V_20 -> V_25 = NULL ;
V_20 -> V_26 = V_27 ;
}
}
T_1 F_26 ( struct V_1 * V_2 ,
struct V_3 * * V_4 , const char * V_28 ,
T_2 V_29 )
{
struct V_3 * V_5 ;
struct V_1 * V_30 ;
char * V_12 ;
if ( V_2 -> V_19 ) {
F_27 ( V_2 , L_2 , V_8 ) ;
return - V_31 ;
}
V_12 = F_28 ( V_28 , V_29 , V_32 ) ;
if ( ! V_12 )
return - V_33 ;
F_29 ( V_12 ) ;
if ( strncmp ( V_12 , L_3 , 9 ) == 0 || strcmp ( V_12 , L_4 ) == 0 )
;
else {
V_29 = - V_34 ;
goto V_35;
}
V_5 = * V_4 ;
if ( strcmp ( V_12 , L_4 ) == 0 ) {
F_22 ( V_2 , V_4 ) ;
goto V_35;
} else if ( V_5 ) {
F_27 ( V_2 , L_5 ,
F_12 ( & V_5 -> V_2 ) ) ;
V_29 = - V_31 ;
goto V_35;
}
V_30 = F_30 ( V_2 -> V_14 , V_12 , F_11 ) ;
if ( ! V_30 ) {
F_27 ( V_2 , L_6 , V_12 ,
F_12 ( V_2 -> V_14 ) ) ;
V_29 = - V_36 ;
goto V_35;
}
V_5 = F_31 ( V_30 ) ;
if ( F_32 ( V_5 ) < V_37 ) {
F_27 ( V_2 , L_7 , V_12 ) ;
V_29 = - V_38 ;
goto V_39;
}
F_33 ( ! F_34 ( V_2 ) ) ;
if ( ! F_10 ( V_2 , V_5 , V_4 ) ) {
F_27 ( V_2 , L_8 ,
F_12 ( & V_5 -> V_2 ) ) ;
V_29 = - V_31 ;
}
V_39:
F_4 ( & V_5 -> V_2 ) ;
V_35:
F_25 ( V_12 ) ;
return V_29 ;
}
T_3 F_35 ( struct V_40 * V_40 )
{
T_3 V_41 ;
T_4 V_42 ;
F_36 ( sizeof( struct V_43 ) != V_44 ) ;
F_36 ( sizeof( struct V_45 ) != V_44 ) ;
F_36 ( sizeof( struct V_40 ) != V_44 ) ;
V_42 = V_40 -> V_46 ;
V_40 -> V_46 = 0 ;
V_41 = F_37 ( V_40 , sizeof( * V_40 ) , 1 ) ;
V_40 -> V_46 = V_42 ;
return V_41 ;
}
static int F_38 ( struct V_3 * V_5 ,
T_5 V_47 , void * V_28 , T_2 V_48 , int V_49 )
{
struct V_50 * V_51 = F_39 ( & V_5 -> V_2 ) ;
unsigned int V_52 = F_40 ( V_48 + ( V_47 & ( 512 - 1 ) ) , 512 ) ;
T_6 V_53 = V_47 >> 9 ;
int V_54 = 0 ;
if ( F_41 ( ! V_48 ) )
return 0 ;
if ( F_41 ( V_47 + V_48 > V_51 -> V_48 ) ) {
F_3 ( & V_5 -> V_2 , 1 , L_9 ) ;
return - V_55 ;
}
if ( V_49 == V_56 ) {
if ( F_41 ( F_42 ( & V_51 -> V_57 , V_53 , V_52 ) ) )
return - V_58 ;
return F_43 ( V_28 , V_51 -> V_59 + V_47 , V_48 ) ;
}
if ( F_41 ( F_42 ( & V_51 -> V_57 , V_53 , V_52 ) ) ) {
if ( F_44 ( V_47 , 512 ) && F_44 ( V_48 , 512 )
&& ( ! V_5 -> V_7 || ! F_15 ( V_5 -> V_7 ) ) ) {
long V_60 ;
V_60 = F_45 ( & V_5 -> V_2 , V_47 , V_48 ) ;
if ( V_60 < V_48 )
V_54 = - V_58 ;
if ( V_60 > 0 && V_60 / 512 ) {
V_60 /= 512 ;
F_46 ( & V_51 -> V_57 , V_53 , V_60 ) ;
}
F_47 ( V_51 -> V_59 + V_47 , V_48 ) ;
} else
V_54 = - V_58 ;
}
F_48 ( V_51 -> V_59 + V_47 , V_28 , V_48 ) ;
F_49 ( F_14 ( V_5 -> V_2 . V_14 ) ) ;
return V_54 ;
}
int F_50 ( struct V_1 * V_2 , struct V_50 * V_51 )
{
struct V_61 * V_62 = & V_51 -> V_62 ;
struct V_3 * V_5 = & V_51 -> V_63 ;
V_51 -> V_48 = F_51 ( V_62 ) ;
if ( ! F_52 ( V_2 , V_62 -> V_64 , F_51 ( V_62 ) ,
F_12 ( & V_5 -> V_2 ) ) ) {
F_53 ( V_2 , L_10 , V_62 ) ;
return - V_31 ;
}
V_5 -> V_65 = F_38 ;
if ( F_54 ( V_2 , & V_51 -> V_57 ) )
return - V_33 ;
F_55 ( F_14 ( V_5 -> V_2 . V_14 ) , & V_51 -> V_57 ,
& V_51 -> V_62 ) ;
V_51 -> V_59 = F_56 ( V_2 , V_62 -> V_64 , F_51 ( V_62 ) ,
V_66 ) ;
return F_57 ( V_51 -> V_59 ) ;
}
void F_58 ( struct V_1 * V_2 , struct V_50 * V_51 )
{
struct V_61 * V_62 = & V_51 -> V_62 ;
F_59 ( V_2 , V_51 -> V_59 ) ;
F_60 ( V_2 , & V_51 -> V_57 ) ;
F_61 ( V_2 , V_62 -> V_64 , F_51 ( V_62 ) ) ;
}
