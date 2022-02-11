static T_1 F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_3 * V_5 ,
T_2 V_6 )
{
unsigned int V_7 ;
unsigned int V_8 ;
if ( F_2 ( ! V_2 || ! V_4 || ! V_5 ) )
return - V_9 ;
if ( V_6 == 0 )
return 0 ;
V_8 = V_2 -> V_10 . V_11 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
if ( F_2 ( V_4 -> V_12 . V_13 % 8 ||
V_4 -> V_12 . V_14 % 8 ) )
return - V_9 ;
if ( F_2 ( V_5 -> V_12 . V_13 % 8 ||
V_5 -> V_12 . V_14 % 8 ) )
return - V_9 ;
if ( ! V_4 -> V_15 ) {
if ( V_5 -> V_16 )
F_3 ( & V_5 -> V_12 , 0 , V_6 , V_2 -> V_17 . V_18 ) ;
V_5 -> V_15 = 0 ;
continue;
}
V_5 -> V_15 = 1 ;
F_4 ( & V_4 -> V_12 , 0 , & V_5 -> V_12 , 0 , V_6 , V_2 -> V_10 . V_18 ) ;
V_4 ++ ;
V_5 ++ ;
}
return V_6 ;
}
int F_5 ( struct V_19 * V_20 ,
struct V_21 * V_10 ,
struct V_21 * V_17 ,
struct V_1 * * V_22 )
{
int V_23 ;
struct V_1 * V_2 ;
int V_24 ;
if ( F_2 ( ! V_22 ) )
return - V_9 ;
* V_22 = NULL ;
if ( F_2 ( V_10 -> V_18 != V_17 -> V_18 ) )
return - V_9 ;
if ( F_2 ( V_10 -> V_25 != V_17 -> V_25 ) )
return - V_9 ;
if ( F_2 ( V_10 -> V_11 != V_17 -> V_11 ) )
return - V_9 ;
V_24 = F_6 ( V_10 -> V_18 ) ;
if ( F_2 ( V_24 <= 0 ) )
return - V_9 ;
V_23 = F_7 ( V_20 , L_1 , V_10 , V_17 ,
0 , & V_2 ) ;
if ( V_23 < 0 )
return V_23 ;
V_2 -> V_26 = F_1 ;
* V_22 = V_2 ;
return 0 ;
}
