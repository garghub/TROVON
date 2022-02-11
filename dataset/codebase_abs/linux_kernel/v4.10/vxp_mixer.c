static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> type = V_5 ;
V_4 -> V_6 = 1 ;
V_4 -> V_7 . integer . V_8 = 0 ;
V_4 -> V_7 . integer . V_9 = V_10 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_13 * V_14 = F_3 ( V_2 ) ;
struct V_15 * V_16 = (struct V_15 * ) V_14 ;
V_12 -> V_7 . integer . V_7 [ 0 ] = V_16 -> V_17 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_13 * V_14 = F_3 ( V_2 ) ;
struct V_15 * V_16 = (struct V_15 * ) V_14 ;
unsigned int V_18 = V_12 -> V_7 . integer . V_7 [ 0 ] ;
if ( V_18 > V_10 )
return - V_19 ;
F_5 ( & V_14 -> V_20 ) ;
if ( V_16 -> V_17 != V_12 -> V_7 . integer . V_7 [ 0 ] ) {
F_6 ( V_14 , V_12 -> V_7 . integer . V_7 [ 0 ] ) ;
V_16 -> V_17 = V_12 -> V_7 . integer . V_7 [ 0 ] ;
F_7 ( & V_14 -> V_20 ) ;
return 1 ;
}
F_7 ( & V_14 -> V_20 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_13 * V_14 = F_3 ( V_2 ) ;
struct V_15 * V_16 = (struct V_15 * ) V_14 ;
V_12 -> V_7 . integer . V_7 [ 0 ] = V_16 -> V_17 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_13 * V_14 = F_3 ( V_2 ) ;
struct V_15 * V_16 = (struct V_15 * ) V_14 ;
int V_18 = ! ! V_12 -> V_7 . integer . V_7 [ 0 ] ;
F_5 ( & V_14 -> V_20 ) ;
if ( V_16 -> V_17 != V_18 ) {
F_10 ( V_14 , V_18 ) ;
V_16 -> V_17 = V_18 ;
F_7 ( & V_14 -> V_20 ) ;
return 1 ;
}
F_7 ( & V_14 -> V_20 ) ;
return 0 ;
}
int F_11 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = (struct V_15 * ) V_14 ;
int V_21 ;
V_16 -> V_17 = 0 ;
switch ( V_14 -> type ) {
case V_22 :
F_6 ( V_14 , 0 ) ;
break;
case V_23 :
F_10 ( V_14 , 0 ) ;
break;
}
switch ( V_14 -> type ) {
case V_22 :
if ( ( V_21 = F_12 ( V_14 -> V_24 , F_13 ( & V_25 , V_16 ) ) ) < 0 )
return V_21 ;
break;
case V_23 :
if ( ( V_21 = F_12 ( V_14 -> V_24 , F_13 ( & V_26 , V_16 ) ) ) < 0 )
return V_21 ;
break;
}
return 0 ;
}
