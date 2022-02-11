static bool
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( & V_2 -> V_5 , V_4 ) ;
F_3 ( & V_2 -> V_6 ) ;
return F_4 ( V_2 -> V_7 ) ;
}
int
F_5 ( struct V_8 * V_9 , int V_10 ,
unsigned V_11 , bool V_12 )
{
T_1 * V_13 = V_9 -> V_14 ;
struct V_3 V_15 , V_16 ;
struct V_1 * V_2 ;
int V_17 = 0 ;
F_6 ( V_9 ) ;
if ( V_12 ) {
if ( F_7 ( & V_13 -> V_18 . V_7 ,
V_10 , V_11 , 0 ,
V_13 -> V_18 . V_19 ,
0 ) )
return 0 ;
} else {
if ( F_8 ( & V_13 -> V_18 . V_7 ,
V_10 , V_11 , 0 ) )
return 0 ;
}
F_9 ( V_9 , V_10 , V_11 , V_12 ) ;
F_10 ( & V_16 ) ;
if ( V_12 )
F_11 ( & V_13 -> V_18 . V_7 , V_10 ,
V_11 , 0 ,
V_13 -> V_18 . V_19 ) ;
else
F_12 ( & V_13 -> V_18 . V_7 , V_10 , V_11 ) ;
F_13 (obj, &dev_priv->mm.inactive_list, mm_list) {
if ( F_1 ( V_2 , & V_16 ) )
goto V_20;
}
F_13 (obj, &dev_priv->mm.active_list, mm_list) {
if ( V_2 -> V_6 . V_21 || V_2 -> V_22 )
continue;
if ( F_1 ( V_2 , & V_16 ) )
goto V_20;
}
F_13 (obj, &dev_priv->mm.flushing_list, mm_list) {
if ( V_2 -> V_22 )
continue;
if ( F_1 ( V_2 , & V_16 ) )
goto V_20;
}
F_13 (obj, &dev_priv->mm.active_list, mm_list) {
if ( ! V_2 -> V_6 . V_21 || V_2 -> V_22 )
continue;
if ( F_1 ( V_2 , & V_16 ) )
goto V_20;
}
while ( ! F_14 ( & V_16 ) ) {
V_2 = F_15 ( & V_16 ,
struct V_1 ,
V_5 ) ;
V_17 = F_16 ( V_2 -> V_7 ) ;
F_17 ( V_17 ) ;
F_18 ( & V_2 -> V_5 ) ;
F_19 ( & V_2 -> V_6 ) ;
}
return - V_23 ;
V_20:
F_10 ( & V_15 ) ;
while ( ! F_14 ( & V_16 ) ) {
V_2 = F_15 ( & V_16 ,
struct V_1 ,
V_5 ) ;
if ( F_16 ( V_2 -> V_7 ) ) {
F_20 ( & V_2 -> V_5 , & V_15 ) ;
continue;
}
F_18 ( & V_2 -> V_5 ) ;
F_19 ( & V_2 -> V_6 ) ;
}
while ( ! F_14 ( & V_15 ) ) {
V_2 = F_15 ( & V_15 ,
struct V_1 ,
V_5 ) ;
if ( V_17 == 0 )
V_17 = F_21 ( V_2 ) ;
F_18 ( & V_2 -> V_5 ) ;
F_19 ( & V_2 -> V_6 ) ;
}
return V_17 ;
}
int
F_22 ( struct V_8 * V_9 , bool V_24 )
{
T_1 * V_13 = V_9 -> V_14 ;
int V_17 ;
bool V_25 ;
V_25 = ( F_14 ( & V_13 -> V_18 . V_26 ) &&
F_14 ( & V_13 -> V_18 . V_27 ) &&
F_14 ( & V_13 -> V_18 . V_28 ) ) ;
if ( V_25 )
return - V_23 ;
F_23 ( V_9 , V_24 ) ;
V_17 = F_24 ( V_9 ) ;
if ( V_17 )
return V_17 ;
F_17 ( ! F_14 ( & V_13 -> V_18 . V_27 ) ) ;
return F_25 ( V_9 , V_24 ) ;
}
int
F_25 ( struct V_8 * V_9 , bool V_24 )
{
T_1 * V_13 = V_9 -> V_14 ;
struct V_1 * V_2 , * V_29 ;
F_26 (obj, next,
&dev_priv->mm.inactive_list, mm_list) {
if ( ! V_24 || V_2 -> V_30 != V_31 ) {
int V_17 = F_21 ( V_2 ) ;
if ( V_17 )
return V_17 ;
}
}
return 0 ;
}
