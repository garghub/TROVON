static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
F_2 ( V_2 -> V_4 ) ;
if ( V_4 )
F_3 ( V_4 ) ;
V_2 -> V_5 = V_5 ;
V_2 -> V_4 = V_4 ;
}
static struct V_3 * F_4 ( struct V_2 * V_2 ,
struct V_1 * V_6 )
{
struct V_3 * V_4 ;
V_4 = V_6 -> V_4 ;
if ( ! V_4 )
goto V_7;
F_3 ( V_4 ) ;
if ( F_5 ( ! F_6 ( V_6 -> V_8 , V_2 -> V_9 ) ||
( V_4 -> V_10 && ! V_4 -> V_11 -> V_12 ( V_4 , V_6 -> V_5 ) ) ) ) {
F_1 ( V_6 , NULL , 0 ) ;
F_2 ( V_4 ) ;
goto V_7;
}
return V_4 ;
V_7:
V_6 -> V_8 = V_13 ;
return NULL ;
}
struct V_3 * F_7 ( struct V_2 * V_2 )
{
if ( ! V_2 -> V_14 )
return NULL ;
return F_4 ( V_2 , F_8 ( V_2 -> V_14 ) ) ;
}
struct V_15 * F_9 ( struct V_2 * V_2 , T_2 * V_16 )
{
struct V_1 * V_6 ;
struct V_3 * V_4 ;
if ( ! V_2 -> V_14 )
return NULL ;
V_6 = F_8 ( V_2 -> V_14 ) ;
V_4 = F_4 ( V_2 , V_6 ) ;
if ( ! V_4 )
return NULL ;
* V_16 = V_6 -> V_17 . V_18 ;
return F_10 ( V_4 , struct V_15 , V_4 ) ;
}
void F_11 ( struct V_2 * V_2 , struct V_3 * V_4 ,
T_2 V_16 )
{
struct V_1 * V_6 ;
if ( ! V_2 -> V_14 )
return;
V_6 = F_8 ( V_2 -> V_14 ) ;
F_1 ( V_6 , V_4 , 0 ) ;
V_6 -> V_17 . V_18 = V_16 ;
}
void F_12 ( struct V_2 * V_2 , struct V_3 * V_4 ,
const struct V_19 * V_20 )
{
struct V_1 * V_6 ;
if ( ! V_2 -> V_14 )
return;
V_6 = F_8 ( V_2 -> V_14 ) ;
F_1 ( F_8 ( V_2 -> V_14 ) , V_4 ,
F_13 ( (struct V_21 * ) V_4 ) ) ;
V_6 -> V_22 = * V_20 ;
}
struct V_3 * F_14 ( struct V_2 * V_2 ,
struct V_19 * V_16 )
{
struct V_1 * V_6 ;
struct V_3 * V_4 ;
if ( ! V_2 -> V_14 )
return NULL ;
V_6 = F_8 ( V_2 -> V_14 ) ;
V_4 = F_4 ( V_2 , V_6 ) ;
if ( ! V_4 )
return NULL ;
* V_16 = V_6 -> V_22 ;
return V_4 ;
}
int F_15 ( struct V_2 * V_2 , T_3 V_23 )
{
V_2 -> V_14 = F_16 ( struct V_1 ,
V_23 | V_24 ) ;
if ( ! V_2 -> V_14 )
return - V_25 ;
F_17 ( V_2 ) ;
return 0 ;
}
void F_18 ( struct V_2 * V_2 )
{
int V_26 ;
if ( ! V_2 -> V_14 )
return;
F_19 (i)
F_2 ( F_20 ( V_2 -> V_14 , V_26 ) -> V_4 ) ;
F_21 ( V_2 -> V_14 ) ;
}
