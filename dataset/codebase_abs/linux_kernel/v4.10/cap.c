static bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 . V_2 != 5 ;
}
static bool F_2 ( struct V_1 * V_2 )
{
return ! F_1 ( V_2 )
&& V_2 -> V_4 . V_5 == 0
&& V_2 -> V_4 . V_6 == 0 ;
}
static enum V_7 V_7 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) )
return V_2 -> V_3 . V_2 ;
else
return V_2 -> V_4 . V_2 ;
}
static T_1 F_3 ( struct V_1 * V_2 , T_1 V_8 )
{
int V_5 ;
if ( V_8 == 1 ) {
V_5 = V_2 -> V_3 . V_5 ;
} else {
if ( F_1 ( V_2 ) )
V_5 = V_2 -> V_3 . V_5 ;
else if ( ! F_2 ( V_2 ) )
V_5 = V_2 -> V_4 . V_5 ;
else
V_5 = V_2 -> V_9 . V_5 ;
}
if ( V_5 == V_8 )
return 0 ;
return V_5 ;
}
int F_4 ( struct V_10 * V_11 , enum V_12 V_13 , enum V_7 V_2 )
{
T_1 V_8 = 1 ;
struct V_1 V_14 ;
int V_15 ;
int V_16 = 10 ;
while ( V_16 -- ) {
V_15 = F_5 ( V_11 , & V_14 , V_13 , V_8 , 1 ) ;
if ( V_15 ) {
if ( V_13 == V_17 && V_8 == 0xa
&& V_11 -> V_18 . type == V_19 ) {
V_8 = 0x39 ;
continue;
}
return V_15 ;
}
if ( V_8 != 1 ) {
if ( V_7 ( & V_14 ) == V_2 )
return V_8 ;
if ( F_2 ( & V_14 ) ) {
V_15 = F_5 ( V_11 , & V_14 , V_13 ,
V_8 , 2 ) ;
if ( V_15 )
return V_15 ;
}
}
V_8 = F_3 ( & V_14 , V_8 ) ;
if ( ! V_8 )
return 0 ;
}
F_6 ( V_11 ,
L_1 ,
V_2 , V_13 , V_8 ) ;
return - V_20 ;
}
