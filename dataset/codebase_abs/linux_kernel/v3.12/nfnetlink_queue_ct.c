struct V_1 * F_1 ( struct V_2 * V_3 , T_1 * V_4 ,
enum V_5 * V_6 )
{
struct V_7 * V_8 ;
struct V_1 * V_9 ;
V_8 = F_2 ( V_7 ) ;
if ( V_8 == NULL )
return NULL ;
V_9 = F_3 ( V_3 , V_6 ) ;
if ( V_9 ) {
if ( ! F_4 ( V_9 ) )
* V_4 += V_8 -> V_10 ( V_9 ) ;
else
V_9 = NULL ;
}
return V_9 ;
}
struct V_1 *
F_5 ( const struct V_2 * V_11 , const struct V_12 * V_13 ,
enum V_5 * V_6 )
{
struct V_7 * V_8 ;
struct V_1 * V_9 ;
V_8 = F_2 ( V_7 ) ;
if ( V_8 == NULL )
return NULL ;
V_9 = F_3 ( V_11 , V_6 ) ;
if ( V_9 && ! F_4 ( V_9 ) )
V_8 -> V_14 ( V_13 , V_9 ) ;
return V_9 ;
}
int F_6 ( struct V_2 * V_11 , struct V_1 * V_9 ,
enum V_5 V_6 )
{
struct V_7 * V_8 ;
struct V_12 * V_15 ;
T_2 V_16 ;
V_8 = F_2 ( V_7 ) ;
if ( V_8 == NULL )
return 0 ;
V_15 = F_7 ( V_11 , V_17 | V_18 ) ;
if ( ! V_15 )
goto V_19;
if ( V_8 -> V_20 ( V_11 , V_9 ) < 0 )
goto V_19;
F_8 ( V_11 , V_15 ) ;
V_16 = V_6 ;
if ( F_9 ( V_11 , V_21 , F_10 ( V_16 ) ) )
goto V_19;
return 0 ;
V_19:
return - 1 ;
}
void F_11 ( struct V_2 * V_11 , struct V_1 * V_9 ,
enum V_5 V_6 , int V_22 )
{
struct V_7 * V_8 ;
V_8 = F_2 ( V_7 ) ;
if ( V_8 == NULL )
return;
if ( ( V_9 -> V_23 & V_24 ) && V_22 )
V_8 -> V_25 ( V_11 , V_9 , V_6 , V_22 ) ;
}
int F_12 ( struct V_1 * V_9 , const struct V_12 * V_13 ,
T_3 V_26 , T_3 V_27 )
{
struct V_7 * V_8 ;
if ( F_4 ( V_9 ) )
return 0 ;
V_8 = F_2 ( V_7 ) ;
if ( V_8 == NULL )
return - V_28 ;
return V_8 -> V_29 ( V_13 , V_9 , V_26 , V_27 ) ;
}
