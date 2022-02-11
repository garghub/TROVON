static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return snprintf ( V_5 , V_8 , L_1 , V_7 -> V_9 . V_10 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return snprintf ( V_5 , V_8 , L_1 , V_7 -> V_11 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return snprintf ( V_5 , V_8 , L_1 , V_7 -> V_12 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return snprintf ( V_5 , V_8 , L_2 , V_7 -> V_13 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned int V_14 ;
V_14 = 0 ;
F_7 ( & V_15 ) ;
V_14 = F_8 ( & V_7 -> V_16 ) ;
F_9 ( & V_15 ) ;
return snprintf ( V_5 , V_8 , L_1 , V_14 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_17 * V_18 ;
unsigned int V_19 ;
V_19 = 0 ;
F_7 ( & V_15 ) ;
F_11 (aq, ac)
V_19 += V_18 -> V_20 ;
F_9 ( & V_15 ) ;
return snprintf ( V_5 , V_8 , L_1 , V_19 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_17 * V_18 ;
unsigned int V_21 ;
V_21 = 0 ;
F_7 ( & V_15 ) ;
F_11 (aq, ac)
V_21 += V_18 -> V_22 ;
F_9 ( & V_15 ) ;
return snprintf ( V_5 , V_8 , L_1 , V_21 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_3 , F_14 ( V_2 ) -> V_10 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_16 ( F_2 ( V_2 ) ) ;
}
struct V_6 * F_17 ( int V_23 , int V_12 , int V_10 ,
unsigned int V_13 )
{
struct V_6 * V_7 ;
V_7 = F_18 ( sizeof( * V_7 ) , V_24 ) ;
if ( ! V_7 )
return NULL ;
F_19 ( & V_7 -> V_25 ) ;
V_7 -> V_9 . V_1 . V_26 = F_15 ;
V_7 -> V_9 . V_1 . type = & V_27 ;
V_7 -> V_9 . V_10 = V_10 ;
if ( V_10 == V_28 )
V_7 -> V_9 . V_10 = V_29 ;
V_7 -> V_11 = V_10 ;
V_7 -> V_12 = V_12 ;
V_7 -> V_13 = V_13 ;
V_7 -> V_23 = V_23 ;
return V_7 ;
}
