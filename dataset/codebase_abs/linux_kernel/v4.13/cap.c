int F_1 ( struct V_1 * V_2 , enum V_3 V_4 )
{
T_1 V_5 ;
if ( V_2 -> V_6 . type == V_7 )
V_5 = 0x39 ;
else
V_5 = 0x1 ;
do {
struct V_8 V_9 ;
int V_10 ;
V_10 = F_2 ( V_2 , & V_9 , V_11 , V_5 , 1 ) ;
if ( V_10 )
return V_10 ;
if ( V_9 . V_12 . V_4 == V_4 )
return V_5 ;
V_5 = V_9 . V_12 . V_13 ;
} while ( V_5 );
return - V_14 ;
}
static int F_3 ( struct V_15 * V_16 , enum V_17 V_4 )
{
int V_5 = V_16 -> V_6 . V_18 ;
while ( V_5 > 0 && V_5 < V_19 ) {
struct V_8 V_9 ;
int V_10 ;
V_10 = F_4 ( V_16 , & V_9 , V_20 , V_5 , 1 ) ;
if ( V_10 )
return V_10 ;
if ( V_9 . V_12 . V_4 == V_4 )
return V_5 ;
V_5 = V_9 . V_12 . V_13 ;
}
return - V_14 ;
}
int F_5 ( struct V_15 * V_16 , enum V_21 V_22 )
{
struct V_8 V_9 ;
int V_5 ;
V_5 = F_3 ( V_16 , V_23 ) ;
if ( V_5 < 0 )
return V_5 ;
while ( V_5 > 0 && V_5 < V_24 ) {
int V_10 ;
V_10 = F_4 ( V_16 , & V_9 , V_20 , V_5 , 2 ) ;
if ( V_10 )
return V_10 ;
if ( V_5 >= V_19 ) {
if ( V_9 . V_25 . V_26 == V_22 )
return V_5 ;
V_5 = V_9 . V_25 . V_13 ;
} else {
if ( V_9 . V_27 . V_26 == V_22 )
return V_5 ;
if ( ! V_9 . V_27 . V_28 )
return - V_14 ;
V_5 = V_9 . V_27 . V_13 ;
}
}
return - V_14 ;
}
