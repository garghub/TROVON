static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
V_6 -> V_8 -> V_9 -> V_10 ( V_6 , V_4 ) ;
}
static void F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
V_6 -> V_8 -> V_9 -> V_11 ( V_6 , V_4 ) ;
}
static void F_3 ( struct V_5 * V_6 , struct V_1 * V_12 ,
const char * V_13 ,
void (* F_4)( struct V_1 * V_14 ,
struct V_3 * V_15 ) )
{
struct V_1 * V_2 ;
V_2 = F_5 ( V_6 -> V_16 , V_13 , V_12 ) ;
if ( V_2 == NULL )
return;
F_6 ( V_2 , V_6 , F_4 ) ;
if ( F_7 ( V_2 ) < 0 )
F_8 ( V_2 ) ;
}
void F_9 ( struct V_5 * V_6 )
{
struct V_1 * V_12 ;
V_12 = F_5 ( V_6 -> V_16 , L_1 ,
V_6 -> V_16 -> V_17 ) ;
if ( V_12 == NULL )
return;
V_12 -> V_18 = V_19 | V_20 | V_21 ;
if ( F_7 ( V_12 ) < 0 ) {
F_8 ( V_12 ) ;
return;
}
F_3 ( V_6 , V_12 , L_2 , F_1 ) ;
F_3 ( V_6 , V_12 , L_3 , F_2 ) ;
}
