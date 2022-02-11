static bool
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_2 -> V_5 )
return false ;
F_2 ( & V_2 -> V_6 , V_4 ) ;
return F_3 ( V_2 -> V_7 ) ;
}
int
F_4 ( struct V_8 * V_9 , int V_10 ,
unsigned V_11 , unsigned V_12 ,
bool V_13 , bool V_14 )
{
T_1 * V_15 = V_9 -> V_16 ;
struct V_3 V_17 , V_18 ;
struct V_1 * V_2 ;
int V_19 = 0 ;
F_5 ( V_9 , V_10 , V_11 , V_13 ) ;
F_6 ( & V_18 ) ;
if ( V_13 )
F_7 ( & V_15 -> V_20 . V_7 ,
V_10 , V_11 , V_12 ,
0 , V_15 -> V_20 . V_21 ) ;
else
F_8 ( & V_15 -> V_20 . V_7 ,
V_10 , V_11 , V_12 ) ;
F_9 (obj, &dev_priv->mm.inactive_list, mm_list) {
if ( F_1 ( V_2 , & V_18 ) )
goto V_22;
}
if ( V_14 )
goto V_23;
F_9 (obj, &dev_priv->mm.active_list, mm_list) {
if ( F_1 ( V_2 , & V_18 ) )
goto V_22;
}
V_23:
while ( ! F_10 ( & V_18 ) ) {
V_2 = F_11 ( & V_18 ,
struct V_1 ,
V_6 ) ;
V_19 = F_12 ( V_2 -> V_7 ) ;
F_13 ( V_19 ) ;
F_14 ( & V_2 -> V_6 ) ;
}
return - V_24 ;
V_22:
F_6 ( & V_17 ) ;
while ( ! F_10 ( & V_18 ) ) {
V_2 = F_11 ( & V_18 ,
struct V_1 ,
V_6 ) ;
if ( F_12 ( V_2 -> V_7 ) ) {
F_15 ( & V_2 -> V_6 , & V_17 ) ;
F_16 ( & V_2 -> V_25 ) ;
continue;
}
F_14 ( & V_2 -> V_6 ) ;
}
while ( ! F_10 ( & V_17 ) ) {
V_2 = F_11 ( & V_17 ,
struct V_1 ,
V_6 ) ;
if ( V_19 == 0 )
V_19 = F_17 ( V_2 ) ;
F_14 ( & V_2 -> V_6 ) ;
F_18 ( & V_2 -> V_25 ) ;
}
return V_19 ;
}
int
F_19 ( struct V_8 * V_9 )
{
T_1 * V_15 = V_9 -> V_16 ;
struct V_1 * V_2 , * V_26 ;
bool V_27 ;
int V_19 ;
V_27 = ( F_10 ( & V_15 -> V_20 . V_28 ) &&
F_10 ( & V_15 -> V_20 . V_29 ) ) ;
if ( V_27 )
return - V_24 ;
F_20 ( V_9 ) ;
V_19 = F_21 ( V_9 ) ;
if ( V_19 )
return V_19 ;
F_22 ( V_9 ) ;
F_23 (obj, next,
&dev_priv->mm.inactive_list, mm_list)
if ( V_2 -> V_5 == 0 )
F_24 ( F_17 ( V_2 ) ) ;
return 0 ;
}
