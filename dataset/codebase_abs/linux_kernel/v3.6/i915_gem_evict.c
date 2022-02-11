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
unsigned V_11 , bool V_12 )
{
T_1 * V_13 = V_9 -> V_14 ;
struct V_3 V_15 , V_16 ;
struct V_1 * V_2 ;
int V_17 = 0 ;
F_5 ( V_9 , V_10 , V_11 , V_12 ) ;
F_6 ( & V_16 ) ;
if ( V_12 )
F_7 ( & V_13 -> V_18 . V_7 ,
V_10 , V_11 , 0 ,
0 , V_13 -> V_18 . V_19 ) ;
else
F_8 ( & V_13 -> V_18 . V_7 ,
V_10 , V_11 , 0 ) ;
F_9 (obj, &dev_priv->mm.inactive_list, mm_list) {
if ( F_1 ( V_2 , & V_16 ) )
goto V_20;
}
F_9 (obj, &dev_priv->mm.active_list, mm_list) {
if ( V_2 -> V_21 . V_22 )
continue;
if ( F_1 ( V_2 , & V_16 ) )
goto V_20;
}
F_9 (obj, &dev_priv->mm.flushing_list, mm_list) {
if ( F_1 ( V_2 , & V_16 ) )
goto V_20;
}
F_9 (obj, &dev_priv->mm.active_list, mm_list) {
if ( ! V_2 -> V_21 . V_22 )
continue;
if ( F_1 ( V_2 , & V_16 ) )
goto V_20;
}
while ( ! F_10 ( & V_16 ) ) {
V_2 = F_11 ( & V_16 ,
struct V_1 ,
V_6 ) ;
V_17 = F_12 ( V_2 -> V_7 ) ;
F_13 ( V_17 ) ;
F_14 ( & V_2 -> V_6 ) ;
}
return - V_23 ;
V_20:
F_6 ( & V_15 ) ;
while ( ! F_10 ( & V_16 ) ) {
V_2 = F_11 ( & V_16 ,
struct V_1 ,
V_6 ) ;
if ( F_12 ( V_2 -> V_7 ) ) {
F_15 ( & V_2 -> V_6 , & V_15 ) ;
F_16 ( & V_2 -> V_21 ) ;
continue;
}
F_14 ( & V_2 -> V_6 ) ;
}
while ( ! F_10 ( & V_15 ) ) {
V_2 = F_11 ( & V_15 ,
struct V_1 ,
V_6 ) ;
if ( V_17 == 0 )
V_17 = F_17 ( V_2 ) ;
F_14 ( & V_2 -> V_6 ) ;
F_18 ( & V_2 -> V_21 ) ;
}
return V_17 ;
}
int
F_19 ( struct V_8 * V_9 , bool V_24 )
{
T_1 * V_13 = V_9 -> V_14 ;
struct V_1 * V_2 , * V_25 ;
bool V_26 ;
int V_17 ;
V_26 = ( F_10 ( & V_13 -> V_18 . V_27 ) &&
F_10 ( & V_13 -> V_18 . V_28 ) &&
F_10 ( & V_13 -> V_18 . V_29 ) ) ;
if ( V_26 )
return - V_23 ;
F_20 ( V_9 , V_24 ) ;
V_17 = F_21 ( V_9 ) ;
if ( V_17 )
return V_17 ;
F_22 ( V_9 ) ;
F_13 ( ! F_10 ( & V_13 -> V_18 . V_28 ) ) ;
F_23 (obj, next,
&dev_priv->mm.inactive_list, mm_list) {
if ( ! V_24 || V_2 -> V_30 != V_31 ) {
if ( V_2 -> V_5 == 0 )
F_24 ( F_17 ( V_2 ) ) ;
}
}
return 0 ;
}
