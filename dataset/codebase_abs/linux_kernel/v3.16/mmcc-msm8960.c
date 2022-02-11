static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
int V_5 = 0 ;
T_2 V_6 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_9 = V_2 -> V_9 ;
int V_10 = F_3 ( V_2 -> V_9 ) ;
for ( V_4 = 0 ; V_4 < V_10 ; V_4 ++ ) {
V_5 = F_4 ( F_5 ( V_9 , V_4 ) ) ;
if ( V_5 )
goto V_11;
}
if ( V_3 == 2 )
V_6 = V_8 -> V_12 ;
else
V_6 = 0 ;
F_6 ( V_8 -> V_13 . V_14 , V_8 -> V_15 , V_8 -> V_12 , V_6 ) ;
F_7 ( 1 ) ;
if ( V_3 == 1 )
V_6 = V_8 -> V_16 ;
else
V_6 = 0 ;
F_6 ( V_8 -> V_13 . V_14 , V_8 -> V_17 , V_8 -> V_16 , V_6 ) ;
F_7 ( 1 ) ;
V_11:
for ( V_4 -- ; V_4 >= 0 ; V_4 -- )
F_8 ( F_5 ( V_9 , V_4 ) ) ;
return V_5 ;
}
static T_1 F_9 ( struct V_1 * V_2 )
{
T_2 V_6 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_10 ( V_8 -> V_13 . V_14 , V_8 -> V_15 , & V_6 ) ;
if ( V_6 & V_8 -> V_12 )
return 2 ;
F_10 ( V_8 -> V_13 . V_14 , V_8 -> V_17 , & V_6 ) ;
if ( V_6 & V_8 -> V_16 )
return 1 ;
return 0 ;
}
static int F_11 ( struct V_18 * V_19 )
{
return F_12 ( V_19 , & V_20 ) ;
}
static int F_13 ( struct V_18 * V_19 )
{
F_14 ( V_19 ) ;
return 0 ;
}
