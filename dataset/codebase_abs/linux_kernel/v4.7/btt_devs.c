static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 -> V_4 ) ;
struct V_5 * V_5 = F_3 ( V_2 ) ;
F_4 ( V_2 , L_1 , V_6 ) ;
F_5 ( & V_5 -> V_2 , & V_5 -> V_7 ) ;
F_6 ( & V_3 -> V_8 , V_5 -> V_9 ) ;
F_7 ( V_5 -> V_10 ) ;
F_7 ( V_5 ) ;
}
bool F_8 ( struct V_1 * V_2 )
{
return V_2 -> type == & V_11 ;
}
struct V_5 * F_3 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_9 ( V_2 , struct V_5 , V_2 ) ;
F_10 ( ! F_8 ( V_2 ) ) ;
return V_5 ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
return F_12 ( V_5 -> V_15 , V_16 , V_14 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_12 * V_13 , const char * V_14 , T_2 V_17 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
T_1 V_18 ;
F_14 ( V_2 ) ;
F_15 ( V_2 ) ;
V_18 = F_16 ( V_2 , V_14 , & V_5 -> V_15 ,
V_16 ) ;
F_4 ( V_2 , L_2 , V_6 ,
V_18 , V_14 , V_14 [ V_17 - 1 ] == '\n' ? L_3 : L_4 ) ;
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
return V_18 ? V_18 : V_17 ;
}
static T_1 F_19 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
if ( V_5 -> V_10 )
return sprintf ( V_14 , L_5 , V_5 -> V_10 ) ;
return sprintf ( V_14 , L_4 ) ;
}
static T_1 F_20 ( struct V_1 * V_2 ,
struct V_12 * V_13 , const char * V_14 , T_2 V_17 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
T_1 V_18 ;
F_14 ( V_2 ) ;
V_18 = F_21 ( V_2 , & V_5 -> V_10 , V_14 , V_17 ) ;
F_4 ( V_2 , L_2 , V_6 ,
V_18 , V_14 , V_14 [ V_17 - 1 ] == '\n' ? L_3 : L_4 ) ;
F_18 ( V_2 ) ;
return V_18 ? V_18 : V_17 ;
}
static T_1 F_22 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
T_1 V_18 ;
F_15 ( V_2 ) ;
V_18 = sprintf ( V_14 , L_1 , V_5 -> V_7
? F_23 ( & V_5 -> V_7 -> V_2 ) : L_3 ) ;
F_17 ( V_2 ) ;
return V_18 ;
}
static T_1 F_24 ( struct V_1 * V_2 ,
struct V_12 * V_13 , const char * V_14 , T_2 V_17 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
T_1 V_18 ;
F_14 ( V_2 ) ;
F_15 ( V_2 ) ;
V_18 = F_25 ( V_2 , & V_5 -> V_7 , V_14 , V_17 ) ;
F_4 ( V_2 , L_2 , V_6 ,
V_18 , V_14 , V_14 [ V_17 - 1 ] == '\n' ? L_3 : L_4 ) ;
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
return V_18 ;
}
static struct V_1 * F_26 ( struct V_3 * V_3 ,
unsigned long V_15 , T_3 * V_10 ,
struct V_19 * V_7 )
{
struct V_5 * V_5 ;
struct V_1 * V_2 ;
V_5 = F_27 ( sizeof( * V_5 ) , V_20 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_9 = F_28 ( & V_3 -> V_8 , 0 , 0 , V_20 ) ;
if ( V_5 -> V_9 < 0 ) {
F_7 ( V_5 ) ;
return NULL ;
}
V_5 -> V_15 = V_15 ;
if ( V_10 )
V_10 = F_29 ( V_10 , 16 , V_20 ) ;
V_5 -> V_10 = V_10 ;
V_2 = & V_5 -> V_2 ;
F_30 ( V_2 , L_6 , V_3 -> V_9 , V_5 -> V_9 ) ;
V_2 -> V_4 = & V_3 -> V_2 ;
V_2 -> type = & V_11 ;
V_2 -> V_21 = V_22 ;
F_31 ( & V_5 -> V_2 ) ;
if ( V_7 && ! F_32 ( & V_5 -> V_2 , V_7 , & V_5 -> V_7 ) ) {
F_4 ( & V_7 -> V_2 , L_7 ,
V_6 , F_23 ( V_7 -> V_23 ) ) ;
F_33 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
struct V_1 * F_34 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = F_26 ( V_3 , 0 , NULL , NULL ) ;
if ( V_2 )
F_35 ( V_2 ) ;
return V_2 ;
}
static bool F_36 ( T_3 * V_10 )
{
static const T_3 V_24 [ 16 ] ;
return ( memcmp ( V_10 , V_24 , 16 ) == 0 ) ;
}
bool F_37 ( struct V_5 * V_5 , struct V_25 * V_26 )
{
const T_3 * V_27 = F_38 ( & V_5 -> V_7 -> V_2 ) ;
T_4 V_28 ;
if ( memcmp ( V_26 -> V_29 , V_30 , V_31 ) != 0 )
return false ;
if ( ! F_36 ( V_26 -> V_27 ) )
if ( memcmp ( V_26 -> V_27 , V_27 , 16 ) != 0 )
return false ;
V_28 = F_39 ( V_26 -> V_28 ) ;
V_26 -> V_28 = 0 ;
if ( V_28 != F_40 ( (struct V_32 * ) V_26 ) )
return false ;
V_26 -> V_28 = F_41 ( V_28 ) ;
if ( ( F_42 ( V_26 -> V_33 ) & V_34 ) != 0 )
F_43 ( & V_5 -> V_2 , L_8 ) ;
return true ;
}
static int F_44 ( struct V_5 * V_5 ,
struct V_19 * V_7 , struct V_25 * V_25 )
{
if ( ! V_25 || ! V_7 || ! V_5 )
return - V_35 ;
if ( F_45 ( V_7 , V_36 , V_25 , sizeof( * V_25 ) ) )
return - V_37 ;
if ( F_46 ( V_7 ) < V_38 )
return - V_37 ;
if ( ! F_37 ( V_5 , V_25 ) )
return - V_35 ;
V_5 -> V_15 = F_42 ( V_25 -> V_39 ) ;
V_5 -> V_10 = F_29 ( V_25 -> V_10 , 16 , V_20 ) ;
if ( ! V_5 -> V_10 )
return - V_40 ;
F_35 ( & V_5 -> V_2 ) ;
return 0 ;
}
int F_47 ( struct V_1 * V_2 , struct V_19 * V_7 )
{
int V_18 ;
struct V_1 * V_41 ;
struct V_25 * V_25 ;
struct V_3 * V_3 = F_2 ( V_7 -> V_2 . V_4 ) ;
if ( V_7 -> V_42 )
return - V_35 ;
F_15 ( & V_7 -> V_2 ) ;
V_41 = F_26 ( V_3 , 0 , NULL , V_7 ) ;
F_17 ( & V_7 -> V_2 ) ;
if ( ! V_41 )
return - V_40 ;
V_25 = F_48 ( V_2 , sizeof( * V_25 ) , V_20 ) ;
V_18 = F_44 ( F_3 ( V_41 ) , V_7 , V_25 ) ;
F_4 ( V_2 , L_9 , V_6 ,
V_18 == 0 ? F_23 ( V_41 ) : L_10 ) ;
if ( V_18 < 0 ) {
struct V_5 * V_5 = F_3 ( V_41 ) ;
F_49 ( V_41 , & V_5 -> V_7 ) ;
F_33 ( V_41 ) ;
}
return V_18 ;
}
