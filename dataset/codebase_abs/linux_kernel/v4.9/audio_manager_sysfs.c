static T_1 F_1 (
struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_6 )
{
struct V_7 V_8 = { { 0 } } ;
int V_9 = sscanf ( V_5 ,
L_1 V_10 L_2
L_3
L_4 ,
V_8 . V_11 , & V_8 . V_12 , & V_8 . V_13 , & V_8 . V_14 ,
& V_8 . V_15 , & V_8 . V_16 , & V_8 . V_17 ) ;
if ( V_9 != 7 )
return - V_18 ;
V_9 = F_2 ( & V_8 ) ;
if ( V_9 < 0 )
return - V_18 ;
return V_6 ;
}
static T_1 F_3 (
struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_6 )
{
int V_19 ;
int V_9 = sscanf ( V_5 , L_5 , & V_19 ) ;
if ( V_9 != 1 )
return - V_18 ;
V_9 = F_4 ( V_19 ) ;
if ( V_9 )
return V_9 ;
return V_6 ;
}
static T_1 F_5 (
struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_6 )
{
int V_19 ;
int V_9 = sscanf ( V_5 , L_5 , & V_19 ) ;
if ( V_9 == 1 ) {
V_9 = F_6 ( V_19 ) ;
if ( V_9 )
return V_9 ;
} else if ( ! strncmp ( L_6 , V_5 , 3 ) )
F_7 () ;
else
return - V_18 ;
return V_6 ;
}
static void F_8 (
struct V_1 * V_2 , struct V_3 * V_20 )
{
int V_21 ;
V_21 = F_9 ( V_2 , & V_20 -> V_4 ) ;
if ( V_21 ) {
F_10 ( L_7 ,
V_20 -> V_4 . V_11 , V_21 ) ;
}
}
void F_11 ( struct V_1 * V_2 )
{
F_8 ( V_2 , & V_22 ) ;
F_8 ( V_2 , & V_23 ) ;
F_8 ( V_2 , & V_24 ) ;
}
