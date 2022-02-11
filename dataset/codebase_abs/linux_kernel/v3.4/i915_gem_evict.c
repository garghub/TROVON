static bool
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( & V_2 -> V_5 , V_4 ) ;
return F_3 ( V_2 -> V_6 ) ;
}
int
F_4 ( struct V_7 * V_8 , int V_9 ,
unsigned V_10 , bool V_11 )
{
T_1 * V_12 = V_8 -> V_13 ;
struct V_3 V_14 , V_15 ;
struct V_1 * V_2 ;
int V_16 = 0 ;
F_5 ( V_8 , V_9 , V_10 , V_11 ) ;
F_6 ( & V_15 ) ;
if ( V_11 )
F_7 ( & V_12 -> V_17 . V_6 , V_9 ,
V_10 , 0 ,
V_12 -> V_17 . V_18 ) ;
else
F_8 ( & V_12 -> V_17 . V_6 , V_9 , V_10 ) ;
F_9 (obj, &dev_priv->mm.inactive_list, mm_list) {
if ( F_1 ( V_2 , & V_15 ) )
goto V_19;
}
F_9 (obj, &dev_priv->mm.active_list, mm_list) {
if ( V_2 -> V_20 . V_21 || V_2 -> V_22 )
continue;
if ( F_1 ( V_2 , & V_15 ) )
goto V_19;
}
F_9 (obj, &dev_priv->mm.flushing_list, mm_list) {
if ( V_2 -> V_22 )
continue;
if ( F_1 ( V_2 , & V_15 ) )
goto V_19;
}
F_9 (obj, &dev_priv->mm.active_list, mm_list) {
if ( ! V_2 -> V_20 . V_21 || V_2 -> V_22 )
continue;
if ( F_1 ( V_2 , & V_15 ) )
goto V_19;
}
while ( ! F_10 ( & V_15 ) ) {
V_2 = F_11 ( & V_15 ,
struct V_1 ,
V_5 ) ;
V_16 = F_12 ( V_2 -> V_6 ) ;
F_13 ( V_16 ) ;
F_14 ( & V_2 -> V_5 ) ;
}
return - V_23 ;
V_19:
F_6 ( & V_14 ) ;
while ( ! F_10 ( & V_15 ) ) {
V_2 = F_11 ( & V_15 ,
struct V_1 ,
V_5 ) ;
if ( F_12 ( V_2 -> V_6 ) ) {
F_15 ( & V_2 -> V_5 , & V_14 ) ;
F_16 ( & V_2 -> V_20 ) ;
continue;
}
F_14 ( & V_2 -> V_5 ) ;
}
while ( ! F_10 ( & V_14 ) ) {
V_2 = F_11 ( & V_14 ,
struct V_1 ,
V_5 ) ;
if ( V_16 == 0 )
V_16 = F_17 ( V_2 ) ;
F_14 ( & V_2 -> V_5 ) ;
F_18 ( & V_2 -> V_20 ) ;
}
return V_16 ;
}
int
F_19 ( struct V_7 * V_8 , bool V_24 )
{
T_1 * V_12 = V_8 -> V_13 ;
int V_16 ;
bool V_25 ;
V_25 = ( F_10 ( & V_12 -> V_17 . V_26 ) &&
F_10 ( & V_12 -> V_17 . V_27 ) &&
F_10 ( & V_12 -> V_17 . V_28 ) ) ;
if ( V_25 )
return - V_23 ;
F_20 ( V_8 , V_24 ) ;
V_16 = F_21 ( V_8 , true ) ;
if ( V_16 )
return V_16 ;
F_13 ( ! F_10 ( & V_12 -> V_17 . V_27 ) ) ;
return F_22 ( V_8 , V_24 ) ;
}
int
F_22 ( struct V_7 * V_8 , bool V_24 )
{
T_1 * V_12 = V_8 -> V_13 ;
struct V_1 * V_2 , * V_29 ;
F_23 (obj, next,
&dev_priv->mm.inactive_list, mm_list) {
if ( ! V_24 || V_2 -> V_30 != V_31 ) {
int V_16 = F_17 ( V_2 ) ;
if ( V_16 )
return V_16 ;
}
}
return 0 ;
}
