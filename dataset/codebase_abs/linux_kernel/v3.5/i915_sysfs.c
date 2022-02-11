static T_1 F_1 ( struct V_1 * V_2 , const T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_2 V_7 ;
if ( ! F_2 ( V_2 ) )
return 0 ;
V_7 = F_3 ( V_3 ) * 128ULL ;
return F_4 ( V_7 , 100000 ) ;
}
static T_3
F_5 ( struct V_8 * V_2 , struct V_9 * V_10 , char * V_11 )
{
struct V_12 * V_13 = F_6 ( V_2 , struct V_12 , V_14 ) ;
return snprintf ( V_11 , V_15 , L_1 , F_2 ( V_13 -> V_2 ) ) ;
}
static T_3
F_7 ( struct V_8 * V_2 , struct V_9 * V_10 , char * V_11 )
{
struct V_12 * V_13 = F_6 ( V_2 , struct V_12 , V_14 ) ;
T_1 V_16 = F_1 ( V_13 -> V_2 , V_17 ) ;
return snprintf ( V_11 , V_15 , L_2 , V_16 ) ;
}
static T_3
F_8 ( struct V_8 * V_2 , struct V_9 * V_10 , char * V_11 )
{
struct V_12 * V_13 = F_6 ( V_2 , struct V_12 , V_14 ) ;
T_1 V_18 = F_1 ( V_13 -> V_2 , V_19 ) ;
return snprintf ( V_11 , V_15 , L_2 , V_18 ) ;
}
static T_3
F_9 ( struct V_8 * V_2 , struct V_9 * V_10 , char * V_11 )
{
struct V_12 * V_13 = F_6 ( V_2 , struct V_12 , V_14 ) ;
T_1 V_20 = F_1 ( V_13 -> V_2 , V_21 ) ;
return snprintf ( V_11 , V_15 , L_2 , V_20 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
int V_22 ;
if ( F_11 ( V_2 ) -> V_23 < 6 )
return;
V_22 = F_12 ( & V_2 -> V_24 -> V_14 . V_25 , & V_26 ) ;
if ( V_22 )
F_13 ( L_3 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
F_15 ( & V_2 -> V_24 -> V_14 . V_25 , & V_26 ) ;
}
